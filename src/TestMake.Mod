MODULE TestMake;

IMPORT
  Channel, Config, IntStr, Log, Make, ProgramArgs, StdChannels, Strings,
  TextRider, ADT:String, DefaultTarget := Make:Command:Target;


TYPE
  Target* = POINTER TO TargetDesc;
  TargetDesc = RECORD
    (DefaultTarget.TargetDesc)
  END;

TYPE
  Entity* = POINTER TO EntityDesc;
  EntityDesc = RECORD
    (Make.EntityDesc)
    id: ARRAY 2 OF CHAR;
    discover: ARRAY 256 OF CHAR;
  END;

TYPE
  Command* = POINTER TO CommandDesc;
  CommandDesc = RECORD
    (Make.CommandDesc)
    id: ARRAY 2 OF CHAR;
    discoverIn: ARRAY 256 OF CHAR;
    discoverOut: ARRAY 256 OF CHAR;
  END;

TYPE
  Context* = POINTER TO ContextDesc;
  ContextDesc = RECORD
    (Make.ContextDesc)
  END;


VAR
  r: TextRider.Reader;
  arg: ARRAY 1024 OF CHAR;
  context: Context;
  entities: ARRAY 256 OF Entity;
  commands: ARRAY 256 OF Command;
  i: LONGINT;

(* ------------------------------------------------------------------------ *)

PROCEDURE InitTarget* (target: Target);
  BEGIN
    Make.InitCommand (target, NIL);
  END InitTarget;

PROCEDURE NewTarget* (): Target;
  VAR
    target: Target;
  BEGIN
    NEW (target);
    InitTarget (target);
    RETURN target
  END NewTarget;

PROCEDURE (target: Target) Discover*(): Make.CommandState;
  BEGIN
    IF target. HasInvalidAncestor() THEN
      Log.Msg ("target.Discover() --> commandInvalid");
      RETURN Make.commandInvalid
    ELSE
      Log.Msg ("target.Discover() --> commandSchedule");
      RETURN Make.commandSchedule
    END
  END Discover;

PROCEDURE (target: Target) Run*(): BOOLEAN;
  BEGIN
    Log.Msg ("target.Run() --> TRUE");
    RETURN TRUE
  END Run;

(* ------------------------------------------------------------------------ *)

PROCEDURE InitEntity (entity: Entity; context: Make.Context;
                      id: CHAR; discover: ARRAY OF CHAR);
  BEGIN
    Make.InitEntity (entity, context);
    entity. id[0] := id;
    entity. id[1] := 0X;
    COPY (discover, entity. discover)
  END InitEntity;

PROCEDURE NewEntity (context: Context; id: CHAR; discover: ARRAY OF CHAR): Entity;
  VAR
    entity: Entity;
  BEGIN
    NEW (entity);
    InitEntity (entity, context, id, discover);
    RETURN entity
  END NewEntity;

PROCEDURE CreateEntity (context: Context; id: CHAR; discover: ARRAY OF CHAR): Entity;
  BEGIN
    IF (entities[ORD (id)] = NIL) THEN
      entities[ORD (id)] := NewEntity (context, id, discover)
    END;
    RETURN entities[ORD (id)]
  END CreateEntity;

PROCEDURE (entity: Entity) Id* (): String.String;
  BEGIN
    RETURN String.New ("[TestMake.Entity]")
  END Id;

PROCEDURE (entity: Entity) Discover*(): Make.EntityState;
  VAR
    ancestor: Entity;
    i: LONGINT;
    
  PROCEDURE Msg (result: ARRAY OF CHAR; incr: LONGINT);
    VAR
      msg: ARRAY 256 OF CHAR;
      str: ARRAY 16 OF CHAR;
    BEGIN
      COPY ("entity('", msg);
      Strings.Append (entity. id, msg);
      Strings.Append ("').Discover() --> ", msg);
      Strings.Append (result, msg);
      IF (incr # 0) THEN
        IntStr.IntToStr (incr, str);
        Strings.Append ("+", msg);
        Strings.Append (str, msg)
      END;
      Log.Msg (msg);
    END Msg;
  
  BEGIN
    ASSERT (entity. state >= Make.entityUndiscovered);
    
    IF (entity. discover[entity. state] = "-") THEN
      Msg ("entityInvalid", 0);
      RETURN Make.entityInvalid
    ELSIF (entity. discover[entity. state] = "@") THEN
      Msg ("entityBuild", 0);
      RETURN Make.entityBuild
    ELSIF (entity. discover[entity. state] = 0X) THEN
      IF entity. HasInvalidAncestor() THEN
        Msg ("entityInvalid", 0);
        RETURN Make.entityInvalid
      ELSE
        Msg ("entityValid", 0);
        RETURN Make.entityValid
      END
    ELSE
      i := entity. state;
      WHILE (entity. discover[i] # 0X) & (entity. discover[i] # "-") DO
        ancestor := entities[ORD (entity. discover[i])];
        entity. AddAncestor (ancestor);
        INC (i)
      END;
      Msg ("entityStateUnknown", i);
      RETURN SHORT (SHORT (i))
    END
  END Discover;

(* ------------------------------------------------------------------------ *)

PROCEDURE InitCommand (command: Command; context: Context;
                       id: CHAR; discoverIn, discoverOut: ARRAY OF CHAR);
  BEGIN
    Make.InitCommand (command, context);
    command. id[0] := id;
    command. id[1] := 0X;
    COPY (discoverIn, command. discoverIn);
    COPY (discoverOut, command. discoverOut)
  END InitCommand;

PROCEDURE NewCommand (context: Context; id: CHAR; discoverIn, discoverOut: ARRAY OF CHAR): Command;
  VAR
    command: Command;
  BEGIN
    NEW (command);
    InitCommand (command, context, id, discoverIn, discoverOut);
    RETURN command
  END NewCommand;

PROCEDURE CreateCommand (context: Context; id: CHAR; discoverIn, discoverOut: ARRAY OF CHAR): Command;
  BEGIN
    IF (commands[ORD (id)] = NIL) THEN
      commands[ORD (id)] := NewCommand (context, id, discoverIn, discoverOut)
    END;
    RETURN commands[ORD (id)]
  END CreateCommand;

PROCEDURE (command: Command) Id* (): String.String;
  BEGIN
    RETURN String.New ("[TestMake.Command]")
  END Id;

PROCEDURE (command: Command) Discover*(): Make.CommandState;
  VAR
    ancestor, descendent: Entity;
    i: LONGINT;
    
  PROCEDURE Msg (result: ARRAY OF CHAR);
    VAR
      msg: ARRAY 256 OF CHAR;
    BEGIN
      COPY ("command('", msg);
      Strings.Append (command. id, msg);
      Strings.Append ("').Discover() --> ", msg);
      Strings.Append (result, msg);
      Log.Msg (msg);
    END Msg;
  
  BEGIN
    IF (command. state = Make.commandUndiscovered) THEN
      i := 0;
      WHILE (command. discoverIn[i] # 0X) DO
        ancestor := entities[ORD (command. discoverIn[i])];
        command. AddAncestor (ancestor);
        INC (i)
      END;
      i := 0;
      WHILE (command. discoverOut[i] # 0X) DO
        descendent := entities[ORD (command. discoverOut[i])];
        command. AddDescendent (descendent);
        INC (i)
      END;
      
      Msg ("commandStateUnknown+1");
      RETURN Make.commandUndiscovered+1
      
    ELSIF (command. state = Make.commandUndiscovered+1) THEN
      IF command. HasInvalidAncestor() THEN
        Msg ("commandInvalid");
        RETURN Make.commandInvalid
      ELSE
        Msg ("commandSchedule");
        RETURN Make.commandSchedule
      END
      
    ELSE
        Msg ("commandSuccessful");
      RETURN Make.commandSuccessful
    END
  END Discover;

PROCEDURE (command: Command) Run*(): BOOLEAN;
  VAR
    msg: ARRAY 256 OF CHAR;
    res: BOOLEAN;
  BEGIN
    res := ~command. HasInvalidAncestor();
    COPY ("command('", msg);
    Strings.Append (command. id, msg);
    Strings.Append ("').Run() --> ", msg);
    IF res THEN
      Strings.Append ("TRUE", msg)
    ELSE
      Strings.Append ("FALSE", msg)
    END;
    Log.Msg (msg);
    RETURN res
  END Run;

PROCEDURE (command: Command) ProduceOutput* (stdout, stderr: Channel.Channel);
  BEGIN
  END ProduceOutput;


(* ------------------------------------------------------------------------ *)

PROCEDURE InitContext (context: Context; target: Make.Command);
  BEGIN
    Make.InitContext (context, NIL, target)
  END InitContext;

PROCEDURE NewContext* (target: Make.Command): Context;
  VAR
    context: Context;
  BEGIN
    NEW (context);
    InitContext (context, target);
    RETURN context
  END NewContext;

PROCEDURE (context: Context) GetConfig* (): Config.Config;
  BEGIN
    RETURN NIL
  END GetConfig;

PROCEDURE (context: Context) GetCommand* (entity: Make.Entity): Make.Command;
  PROCEDURE Msg;
    VAR
      msg: ARRAY 256 OF CHAR;
    BEGIN
      COPY ("entity('", msg);
      Strings.Append (entity(Entity). id, msg);
      Strings.Append ("').GetCommand()", msg);
      Log.Msg (msg);
    END Msg;
  
  BEGIN
    ASSERT (entity. state = Make.entityBuild);
    
    Msg;
    i := 0;
    WHILE (entity(Entity). discover[i] # "@") DO
      INC (i)
    END;
    RETURN commands[ORD (entity(Entity). discover[i+1])]
  END GetCommand;


(* ------------------------------------------------------------------------ *)

PROCEDURE SetupA;
  BEGIN
    (* except for the target, the context is empty *)
  END SetupA;

PROCEDURE SetupB;
  VAR
    entity: Entity;
  BEGIN
    (* the target depends on a single valid entity *)
    SetupA();
    entity := CreateEntity (context, "a", "");
    context. target. AddAncestor (entity)
  END SetupB;

PROCEDURE SetupC;
  VAR
    entity: Entity;
  BEGIN
    (* the target depends on two other entities, the entities themselves 
       are also linked by a dependence *)
    SetupA();
    entity := CreateEntity (context, "c", "");
    entity := CreateEntity (context, "b", "c");
    entity := CreateEntity (context, "a", "bc");
    context. target. AddAncestor (entity)
  END SetupC;

PROCEDURE SetupD;
  VAR
    entity, dummy: Entity;
  BEGIN
    (* the target depends on two other entities, the entities themselves 
       are also linked by a dependence; permutation of SetupC: same result,
       although the nodes may be evaluated in a different order *)
    SetupA();
    entity := CreateEntity (context, "a", "bc");
    dummy := CreateEntity (context, "b", "c");
    dummy := CreateEntity (context, "c", "");
    context. target. AddAncestor (entity)
  END SetupD;

PROCEDURE SetupE;
  VAR
    entity: Entity;
  BEGIN
    (* no ancestor of target, so there is nothing to do *)
    SetupA();
    entity := CreateEntity (context, "c", "");
    entity := CreateEntity (context, "b", "c");
    entity := CreateEntity (context, "a", "bc");
  END SetupE;

PROCEDURE SetupInvalid1;
  VAR
    entity: Entity;
  BEGIN
    (* the target depends on a single invalid entity *)
    SetupA();
    entity := CreateEntity (context, "a", "-");
    context. target. AddAncestor (entity)
  END SetupInvalid1;

PROCEDURE SetupInvalid2;
  VAR
    entity: Entity;
  BEGIN
    (* the target depends on two other entities, the entities themselves 
       are also linked by a dependence, the "lowest" entity is invalid *)
    SetupA();
    entity := CreateEntity (context, "c", "-");
    entity := CreateEntity (context, "b", "c");
    entity := CreateEntity (context, "a", "bc");
    context. target. AddAncestor (entity)
  END SetupInvalid2;

PROCEDURE SetupInvalid3;
  VAR
    entity: Entity;
  BEGIN
    (* the target depends on two other entities, the entities themselves 
       are also linked by a dependence, the "middle" entity becomes
       invalid after discovering the "lowest" *)
    SetupA();
    entity := CreateEntity (context, "c", "");
    entity := CreateEntity (context, "b", "c-");
    entity := CreateEntity (context, "a", "bc");
    context. target. AddAncestor (entity)
  END SetupInvalid3;

PROCEDURE SetupBuild1;
  VAR
    entity: Entity;
    command: Command;
  BEGIN
    (* the target depends on one entity that must be build; the build does
       not require any other entity, and is immediately successful *)
    SetupA();
    command := CreateCommand (context, "A", "", "a");
    entity := CreateEntity (context, "a", "@A");
    context. target. AddAncestor (entity)
  END SetupBuild1;

PROCEDURE SetupBuild2;
  VAR
    entity: Entity;
    command: Command;
  BEGIN
    (* the target depends on one entity that must be build; the build
       requires other valid entity *)
    SetupA();
    entity := CreateEntity (context, "b", "");
    command := CreateCommand (context, "A", "b", "a");
    entity := CreateEntity (context, "a", "@A");
    context. target. AddAncestor (entity)
  END SetupBuild2;

PROCEDURE SetupBuild3;
  VAR
    entity: Entity;
    command: Command;
  BEGIN
    (* the target depends on one entity that must be build; the build
       requires other invalid entity *)
    SetupA();
    entity := CreateEntity (context, "b", "-");
    command := CreateCommand (context, "A", "b", "a");
    entity := CreateEntity (context, "a", "@A");
    context. target. AddAncestor (entity)
  END SetupBuild3;

BEGIN
  FOR i := 0 TO LEN (entities)-1 DO
    entities[i] := NIL
  END;
  
  r := TextRider.ConnectReader (ProgramArgs.args);
  r. ReadLine (arg);
  r. ReadLine (arg);

  context := NewContext (NewTarget());
  IF (arg = "simple1") THEN
    SetupA
  ELSIF (arg = "simple2") THEN
    SetupB
  ELSIF (arg = "simple3") THEN
    SetupC
  ELSIF (arg = "simple4") THEN
    SetupD
  ELSIF (arg = "simple5") THEN
    SetupE
  ELSIF (arg = "invalid1") THEN
    SetupInvalid1
  ELSIF (arg = "invalid2") THEN
    SetupInvalid2
  ELSIF (arg = "invalid3") THEN
    SetupInvalid3
  ELSIF (arg = "build1") THEN
    SetupBuild1
  ELSIF (arg = "build2") THEN
    SetupBuild2
  ELSIF (arg = "build3") THEN
    SetupBuild3
  ELSE
    Log.Msg ("No such test case"); HALT (1)
  END;
  
  IF ~context. Solve (StdChannels.stdout, StdChannels.stderr) THEN
    Log.Msg ("failure");
    HALT(1)
  ELSE
    Log.Msg ("success")
  END
END TestMake.
