MODULE Config:Source:Environment;

IMPORT
  Channel, TextRider, Msg, Strings, LongStrings,
  <*IF COMPILER_MAJOR=1 THEN*>Rts,<*ELSE*>RT0,<*END*>
  Config:Value, Config:Source, Config:Parser;


TYPE
  VariableTemplate* = POINTER TO VariableTemplateDesc;
  VariableTemplateDesc = RECORD
    next: VariableTemplate;
    name: Value.StringPtr;
    pattern: Value.StringPtr;
  END;

TYPE
  Command* = POINTER TO CommandDesc;
  CommandDesc = RECORD
    (**A command corresponds to a single environment variable.
       It is converted into an XML text fragment, which describes the result
       of setting the environment variable.  *)
    nextCommand-: Command;
    (**Next command in list @ofield{Environment.commandList}.  *)
    template-: VariableTemplate;
    (**Text template, that is used to create the XML fragment.  Any reference
       $1 is replaced with the value from @ofield{argument}.*)
    argument-: Value.StringPtr;
    (**Value of the environment variable.  *)
    doNotWrite-: BOOLEAN;
    (**During @oproc{Environment.Write}, do not include the command in the 
       output, if this field is set to @code{TRUE}.  It is @code{FALSE} by
       default, but can be changed to @code{TRUE} with
       @oproc{Command.DoNotWrite}.  *)
  END;

TYPE
  Environment* = POINTER TO EnvironmentDesc;
  EnvironmentDesc = RECORD
    (Source.SourceDesc)
    variableTemplates: VariableTemplate;
    commandList-: Command;
    (* After @oproc{CmdLine.Parse}, this field refers to a list of commands.
       Every command @otype{Command} corresponds to a environment variable.  *)
  END;


PROCEDURE Init (env: Environment);
  BEGIN
    Source.Init (env)
  END Init;

PROCEDURE New* (): Environment;
  VAR
    env: Environment;
  BEGIN
    NEW (env);
    Init (env);
    env. variableTemplates := NIL;
    env. commandList := NIL;
    RETURN env
  END New;

PROCEDURE (command: Command) DoNotWrite*;
(**Remove the command @oparam{command} from the output of
   @oproc{Environment.Write}.  *)
  BEGIN
    command. doNotWrite := TRUE
  END DoNotWrite;


PROCEDURE (env: Environment) AddVariableTemplate* (name: ARRAY OF CHAR;
                               transformation: Value.String): VariableTemplate;
(**If a variable name is added multiple times, all rules associated with this
   name are evaluated if it appears in the program's environment.  *)
  VAR
    t: VariableTemplate;
  
  PROCEDURE Append (VAR list: VariableTemplate);
    BEGIN
      IF (list = NIL) THEN
        list := t
      ELSE
        Append (list. next)
      END
    END Append;
    
  BEGIN
    NEW (t);
    t. next := NIL;
    t. name := Value.GetStringPtr (name);
    t. pattern := Value.GetStringPtr (transformation);
    Append (env. variableTemplates);
    RETURN t
  END AddVariableTemplate;

PROCEDURE (env: Environment) Parse*(): Msg.Msg;
  VAR
    t: VariableTemplate;
    cmd: Command;
    found: BOOLEAN;
    value: ARRAY 1024 OF CHAR;
    
  PROCEDURE Append (VAR list: Command);
    BEGIN
      IF (list = NIL) THEN
        list := cmd
      ELSE
        Append (list. nextCommand)
      END
    END Append;
  
  BEGIN
    t := env. variableTemplates;
    WHILE (t # NIL) DO
<*IF COMPILER_MAJOR=1 THEN*>
      found := Rts.GetEnv (value, t. name^);
<*ELSE*>
      found := RT0.GetEnv (t. name^, value);
<*END*>
      IF found THEN
        NEW (cmd);
        cmd. nextCommand := NIL;
        cmd. template := t;
        cmd. argument := Value.GetStringPtr (value);
        cmd. doNotWrite := FALSE;
        Append (env. commandList)
      END;
      t := t. next
    END;
    RETURN NIL
  END Parse;

PROCEDURE (env: Environment) Write* (ch: Channel.Channel;
                                     rootTag: Parser.String;
                                     VAR res: Msg.Msg);
  VAR
    w: TextRider.Writer;
    i, j: LONGINT;
    command: Command;
    pattern: Value.StringPtr;
    root8: ARRAY 1024 OF CHAR;
    
  PROCEDURE WriteQuoted (w: TextRider.Writer; VAR str: ARRAY OF CHAR);
    VAR
      s, e, last: LONGINT;
    BEGIN
      s := 0;
      e := Strings.Length (str);
      WHILE (s # e) DO
        last := s;
        WHILE (s # e) & (str[s] # "&") &
              (str[s] # "<") & (str[s] # ">") &
              (str[s] # "'") & (str[s] # '"') DO
          INC (s)
        END;
        w. byteWriter. WriteBytes (str, last, s-last);
        IF (s # e) THEN
          CASE str[s] OF
          | "&": w. WriteString ("&amp;")
          | "<": w. WriteString ("&lt;")
          | ">": w. WriteString ("&gt;")
          | "'": w. WriteString ("&apos;")
          | '"': w. WriteString ("&quot;")
          END;
          INC (s)
        END
      END
    END WriteQuoted;

  BEGIN
    w := TextRider.ConnectWriter (ch);
    IF (w = NIL) THEN
      res := w. res;
      RETURN
    END;
    
    IF (rootTag # "") THEN
      (* don't forget to import the XML codec for the encoding you use! *)
      w. WriteString ("<?xml version='1.0' encoding='ISO-8859-1' standalone='yes'?>");
      w. WriteLn;
      LongStrings.Short (rootTag, "?", root8);
      w. WriteString ("<");
      w. WriteString (root8);
      w. WriteString (">");
      w. WriteLn
    END;
    
    command := env. commandList;
    WHILE (command # NIL) DO
      IF ~command. doNotWrite THEN
        pattern := command. template. pattern;
        i := 0;
        WHILE (pattern[i] # 0X) DO
          j := i;
          WHILE (pattern[i] # 0X) & (pattern[i] # "$") DO
            INC (i)
          END;

          IF (pattern[i] = "$") & (pattern[i+1] = "1") THEN
            w. byteWriter. WriteBytes (pattern^, j, i-j);
            WriteQuoted (w, command. argument^);
            INC (i, 2)
          ELSE
            w. byteWriter. WriteBytes (pattern^, j, i-j)
          END
        END;
        w. WriteLn
      END;
      command := command. nextCommand
    END;
    
    IF (rootTag # "") THEN
      w. WriteString ("</");
      w. WriteString (root8);
      w. WriteString (">");
      w. WriteLn
    END;
    res := w. res
  END Write;

END Config:Source:Environment.
