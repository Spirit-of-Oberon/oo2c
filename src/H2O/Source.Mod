MODULE H2O:Source [OOC_EXTENSIONS];

IMPORT
  H2O:Module,
  Object, TextRider, Channel, Err, Msg, Files, Strings,
  OOC:Config, OOC:Repository, URI;

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
    rd: TextRider.Reader;
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
    Err.String(") in file "); Err.Str(s.name); Err.Ln;
    s := s.next;
  END;
END ShowContext;

PROCEDURE (i : Input) ReadChar* (VAR ch : CHAR);
VAR
  rd : TextRider.Reader; src : Source;
BEGIN
  IF (i.src # NIL) & (i.src.rd.Available() = 0) & (ch # eol) THEN
    ch := eol;
    Err.String("End of line assumed for incorrectly terminated file");
    Err.Ln;
    i.ShowContext;
  ELSE
    REPEAT
      WHILE (i.src # NIL) & (i.src.rd.Available() = 0) DO
        i.src.rd.base.Close;
        INC(i.lines, i.src.line); INC(i.files);
        i.src := i.src.next;
      END;
      IF i.src = NIL THEN
        ch := eof;
      ELSE
        src := i.src; rd := src.rd;
        i.module := src.module;
        IF rd.Eol() THEN
          rd.ReadLn;
          ch := eol;
        ELSE
          rd.ReadChar(ch);
        END;
        src.pos := rd.Pos();
        IF ch = eol THEN
          src.col := 0; INC(src.line);
        ELSE
          INC(src.col);
        END;
      END
    UNTIL ch # cr
  END;
  IF debugText IN debug THEN
    Err.Char(ch);
  END;
END ReadChar;

PROCEDURE Fatal* (msg : ARRAY OF CHAR);
BEGIN
  Err.String("Error: ");
  Err.String(msg);
  Err.Ln;
  HALT(1);
END Fatal;

PROCEDURE (i : Input) NoFile(res : Files.Result);
VAR
  a : ARRAY 256 OF CHAR;
BEGIN
  i.ShowContext();
  res.GetText(a);
  Fatal(a);
END NoFile;

PROCEDURE (i : Input) Include* (fileName : ARRAY OF CHAR; search : BOOLEAN);
VAR
  realFileName : ARRAY 256 OF CHAR;
  moduleName : Object.String8;
  module : Module.Module;
  s : Source;
  m : Repository.Module;
  uri : URI.HierarchicalURI;
  channel : Channel.Channel;
  msg : Msg.Msg;
BEGIN
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
      channel := uri.GetChannel(URI.channelOld, msg);
    END;    
  ELSE
    Strings.Assign(fileName, realFileName);
    channel := Files.Old(realFileName, {Files.read}, msg);
  END;
  IF channel = NIL THEN
    i.NoFile(msg)
  END;

  NEW(s);
  s.rd := TextRider.ConnectReader(channel);
  s.pos := 0;
  s.line := 0;
  s.col := 0;
  s.next := i.src;
  s.name := Object.NewLatin1(realFileName);
  i.src := s;
  Err.String("<Processing "); Err.Str(s.name); Err.Char(">"); Err.Ln;

  moduleName := Module.ModuleName(realFileName);
  module := Module.FindModule(moduleName);
  IF module = NIL THEN
    Err.String("NEW ");
    module := Module.NewModule(moduleName);
  END;
  Err.String("MODULE "); Err.Str(moduleName); 
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
