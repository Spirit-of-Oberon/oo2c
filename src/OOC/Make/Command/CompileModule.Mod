MODULE OOC:Make:Command:CompileModule;

IMPORT
  Channel, Make, ADT:String, OOC:Make:Entity:ModuleFile,
  OOC:Auxiliary:Config, OOC:Auxiliary:ParseModule,
  OOC:Error, OOC:Repository, OOC:AST, 
  OOC:SymbolTable:Item;

TYPE
  Command* = POINTER TO CommandDesc;
  CommandDesc = RECORD
    (Make.CommandDesc)
    module: Repository.Module;
    errList: Error.List;
  END;

PROCEDURE New* (module: Repository.Module): Command;
  VAR
    cmd: Command;
  BEGIN
    NEW (cmd);
    Make.InitCommand (cmd);
    cmd. module := module;
    cmd. errList := NIL;
    RETURN cmd
  END New;

PROCEDURE (cmd: Command) Id* (): String.String;
  BEGIN
    RETURN String.New ("[OOC:Make:Command:CompileModule]")
  END Id;

PROCEDURE (cmd: Command) Discover* (): Make.CommandState;
  PROCEDURE HasInvalidAncestor(): BOOLEAN;
    VAR
      aEdge: Make.Edge;
    BEGIN
      aEdge := cmd. ancestorList;
      WHILE (aEdge # NIL) DO
        IF (aEdge. ancestor IS Make.Entity) &
           (aEdge. ancestor(Make.Entity). state = Make.entityInvalid) &
           (aEdge. ancestor(Make.Entity). command # NIL) THEN
          RETURN TRUE
        END;
        aEdge := aEdge. nextAncestor
      END;
      RETURN FALSE
    END HasInvalidAncestor;

  BEGIN
    IF (cmd. state = Make.commandUndiscovered) THEN
      ModuleFile.DiscoverCompile (cmd, cmd. module);
      RETURN cmd. state+1
    ELSE
      (* if one of the ancestors is invalid because of failed build, then
         don't try to run this command; note: an ancestor that is invalid
         without any attempt to build it does not generate an error, so we
         run this command just to get an error message *)
      IF HasInvalidAncestor() THEN
        RETURN Make.commandInvalid
      ELSE
        RETURN Make.commandSchedule
      END
    END
  END Discover;

PROCEDURE (cmd: Command) Run*(): BOOLEAN;
(**Compiles a module, creating the symbol file and the object file.  *)
  VAR
    ast: AST.Node;
    symTab: Item.Module;
    errList: Error.List;
    m: Repository.Module;
    config: Config.Config;
  BEGIN
    m := cmd. module;
    config := cmd. context. config(Config.Config);
    ParseModule.ParseModule (m, config, TRUE, TRUE, ast, symTab, errList);
    (* symbol file is written by the `ParseModule' function *)
    (* ... no more to do right now *)
    cmd. errList := errList;
    RETURN (errList. msgCount = 0)
  END Run;

PROCEDURE (cmd: Command) ProduceOutput* (stdout, stderr: Channel.Channel);
  BEGIN
    IF (cmd. errList. msgCount # 0) THEN
      cmd. errList. Write (stderr)
    END
  END ProduceOutput;

END OOC:Make:Command:CompileModule.
