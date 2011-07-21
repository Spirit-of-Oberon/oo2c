MODULE Config:Source:Environment;

IMPORT
  Object, Msg, LongStrings, OS:ProcessParameters, IO, Writer := IO:TextRider,
  Config:Source, Config:Parser;


TYPE
  VariableTemplate* = POINTER TO VariableTemplateDesc;
  VariableTemplateDesc = RECORD
    next: VariableTemplate;
    name: Object.String8;
    pattern: Object.String8;
    isList: BOOLEAN;
    listSep: CHAR;
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
    argument-: Object.String8;
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


PROCEDURE (t: VariableTemplate) INIT*(name, transformation: Object.String8;
                                      isList: BOOLEAN; listSep: CHAR);
  BEGIN
    t.next := NIL;
    t.name := name;
    t.pattern := transformation;
    t.isList := isList;
    t.listSep := listSep;
  END INIT;

PROCEDURE Append (VAR list: VariableTemplate; t: VariableTemplate);
  BEGIN
    IF (list = NIL) THEN
      list := t
    ELSE
      Append (list. next, t)
    END
  END Append;

PROCEDURE (env: Environment) AddVariableTemplate* (name, transformation: Object.String8): VariableTemplate;
(**If a variable name is added multiple times, all rules associated with this
   name are evaluated if it appears in the program's environment.  *)
  VAR
    t: VariableTemplate;
  BEGIN
    t := NEW (VariableTemplate, name, transformation, FALSE, 0X);
    Append (env. variableTemplates, t);
    RETURN t
  END AddVariableTemplate;

PROCEDURE (env: Environment) AddListTemplate* (name,
                                               transformation: Object.String8;
                                               listSep: CHAR): VariableTemplate;
  VAR
    t: VariableTemplate;
  BEGIN
    t := NEW (VariableTemplate, name, transformation, TRUE, listSep);
    Append (env. variableTemplates, t);
    RETURN t
  END AddListTemplate;

PROCEDURE (env: Environment) Parse*(): Msg.Msg;
  VAR
    t: VariableTemplate;
    i, j: LONGINT;
    value, entry: STRING;
    
  PROCEDURE AddCommand(t: VariableTemplate; value: STRING);
    VAR
      cmd: Command;
      
    PROCEDURE Append (VAR list: Command);
      BEGIN
        IF (list = NIL) THEN
          list := cmd
        ELSE
          Append (list. nextCommand)
        END
      END Append;
    
    BEGIN
      NEW (cmd);
      cmd. nextCommand := NIL;
      cmd. template := t;
      cmd. argument := value(Object.String8);
      cmd. doNotWrite := FALSE;
      Append (env. commandList)
    END AddCommand;
  
  BEGIN
    t := env. variableTemplates;
    WHILE (t # NIL) DO
      value := ProcessParameters.GetEnv(t.name);
      IF (value # NIL) THEN
        IF t.isList THEN
          i := 0;
          WHILE (i >= 0) DO
            j := value.IndexOf(t.listSep, i);
            IF (j < 0) THEN
              entry := value.Substring(i, value.length);
              i := j;
            ELSE
              entry := value.Substring(i, j);
              i := j+1;  (* skip separator *)
            END;
            IF (entry.length > 0) THEN  (* drop any empty entries *)
              AddCommand(t, entry);
            END;
          END;
        ELSE
          AddCommand(t, value);
        END;
      END;
      t := t. next
    END;
    RETURN NIL
  END Parse;

PROCEDURE (env: Environment) Write* (ch: IO.ByteChannel;
                                     rootTag: Parser.String);
  VAR
    w: Writer.Writer;
    i, j: LONGINT;
    command: Command;
    pattern: Object.String8;
    chars: Object.CharsLatin1;
    root8: ARRAY 1024 OF CHAR;
    
  PROCEDURE WriteQuoted (w: Writer.Writer; str: Object.String8);
    VAR
      s, e, last: LONGINT;
      chars: Object.CharsLatin1;
    BEGIN
      chars := str.CharsLatin1();
      s := 0;
      e := str.length;
      WHILE (s # e) DO
        last := s;
        WHILE (s # e) & (chars[s] # "&") &
              (chars[s] # "<") & (chars[s] # ">") &
              (chars[s] # "'") & (chars[s] # '"') DO
          INC (s)
        END;
        w. WriteStringRegion (chars^, last, s);
        IF (s # e) THEN
          CASE chars[s] OF
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
    w := Writer.ConnectWriter (ch);
    
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
        chars := pattern.CharsLatin1();
        i := 0;
        WHILE (chars[i] # 0X) DO
          j := i;
          WHILE (chars[i] # 0X) & (chars[i] # "$") DO
            INC (i)
          END;

          IF (chars[i] = "$") & (chars[i+1] = "1") THEN
            w. WriteStringRegion (chars^, j, i);
            WriteQuoted (w, command. argument);
            INC (i, 2)
          ELSE
            w. WriteStringRegion (chars^, j, i)
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
  END Write;

END Config:Source:Environment.
