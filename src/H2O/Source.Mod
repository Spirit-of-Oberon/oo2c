MODULE H2O:Source [OOC_EXTENSIONS];

IMPORT
  H2O:Module,
  Object, Err, Strings,
  OOC:Config, OOC:Repository, URI, IO, IO:FileChannel, Exception;

CONST
  cr = 0DX;
  eol* = 0AX;
  eof* = 04X;

  debugText = 0;  (* output each character of input as it is read *)
  debug = {};

TYPE
  Source* = POINTER TO SourceDesc;
  SourceDesc = RECORD
    name : Object.String8;
    pos, line, col : LONGINT;
	channel : IO.ByteChannel;
    next : Source;
    module : Module.Module;
  END;

  Input* = POINTER TO InputDesc;
  InputDesc = RECORD
    module- : Module.Module;
    lines, files : LONGINT;
    src : Source;
  END;

PROCEDURE (i : Input) ShowContext*;
VAR s : Source;
BEGIN
  s := i.src;
  WHILE s # NIL DO
    Err.String("  At positon "); Err.LongInt(s.pos, 0); 
    Err.String(" (line="); Err.LongInt(s.line+1, 0);
    Err.String(", col="); Err.LongInt(s.col, 0);
    Err.String(") in file "); Err.Object(s.name); Err.Ln;
    s := s.next;
  END;
END ShowContext;

PROCEDURE (i : Input) Error(msg : STRING);
BEGIN
  i.ShowContext();
  Err.String("Error: ");
  Err.Object(msg);
  Err.Ln;
  HALT(1);
END Error;

(* Report source context for exception *)

PROCEDURE (i : Input) Exception(e : Exception.Exception);
BEGIN
  i.Error(e.GetMessage());
END Exception;

PROCEDURE (i : Input) ReadChar* (VAR ch : CHAR);
VAR
  count : LONGINT;
  src : Source;
BEGIN
  TRY
    REPEAT
      IF i.src = NIL THEN
        ch := eof
      ELSE
        (* Read one character from the current source *)
        count := i.src.channel.Read(ch, 0, 1);
        IF count = -1 THEN
          (* No more input available *)
          IF ch # eol THEN
            (* Check file termination, required for preprocessor *)
            ch := eol;
            Err.String("End of line assumed for incorrectly terminated file");
            Err.Ln;
            i.ShowContext
          ELSE
            (* Close this source, and retry *)
            i.src.channel.Close;
            INC(i.lines, i.src.line); INC(i.files);
            i.src := i.src.next;
            ch := cr;
          END
        ELSIF count = 1 THEN
          src := i.src;
          INC(src.pos);
          IF ch = eol THEN
            src.col := 0; INC(src.line)
          ELSE
            INC(src.col)
          END
        ELSE
          i.Error("Non-blocking stream returned 0 bytes")
        END
      END
    UNTIL ch # cr;
  CATCH IO.Error:
    i.Exception(Exception.Current())
  END;
END ReadChar;

PROCEDURE (i : Input) Include* (fileName : ARRAY OF CHAR; search : BOOLEAN);
VAR
  realFileName : ARRAY 256 OF CHAR;
  moduleName : Object.String8;
  module : Module.Module;
  s : Source;
  m : Repository.Module;
  uri : URI.HierarchicalURI;
  channel : IO.ByteChannel;
  e : IO.Error;
BEGIN
  TRY
    IF search THEN
      m := Config.repositories. GetModule (fileName);
      IF (m = NIL) THEN
        Err.String ("Error: Cannot locate module ");
        Err.String (fileName);
        Err.Ln;
        HALT (1)
      ELSE
        uri := m.GetURI(Repository.modHeaderFileC, FALSE);
        uri.GetString(realFileName);
        channel := uri.GetChannel(URI.channelOld);
      END;    
    ELSE
      Strings.Assign(fileName, realFileName);
      channel := FileChannel.Open(Object.NewLatin1(fileName), {FileChannel.read});
    END;
  CATCH IO.Error:
	i.Exception(Exception.Current());
  END;

  NEW(s);
  s.channel := channel;
  s.pos := 0;
  s.line := 0;
  s.col := 0;
  s.next := i.src;
  s.name := Object.NewLatin1(realFileName);
  i.src := s;
  Err.String("<Processing "); Err.Object(s.name); Err.Char(">"); Err.Ln;

  moduleName := Module.ModuleName(realFileName);
  module := Module.FindModule(moduleName);
  IF module = NIL THEN
    Err.String("NEW ");
    module := Module.NewModule(moduleName);
  END;
  Err.String("MODULE "); Err.Object(moduleName); 
  Err.String(" for "); Err.String(realFileName);
  Err.Ln;
  i.module := module;
  s.module := module;
END Include;

PROCEDURE (i : Input) Summary*();
BEGIN
  Err.String("Processed "); Err.LongInt(i.lines,0); 
  Err.String(" lines in "); Err.LongInt(i.files,0);
  Err.String(" files"); Err.Ln;
END Summary;

PROCEDURE New* () : Input;
VAR i : Input;
BEGIN
  NEW(i);
  i.src := NIL;
  i.lines := 0;
  i.files := 0;
  RETURN i;
END New;

END H2O:Source.
