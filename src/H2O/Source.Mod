MODULE H2O:Source [OOC_EXTENSIONS];

IMPORT
  H2O:Module,
  Object, Err, Log, ADT:ArrayList,
  IO, IO:FileChannel, OS:Files, OS:Path, Exception;

CONST
  cr = 0DX;
  eol* = 0AX;
  eof* = 04X;

TYPE
  Source* = POINTER TO SourceDesc;
  SourceDesc = RECORD
    name : STRING;
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
    path : ArrayList.ArrayList;
    frameworks : ArrayList.ArrayList;
  END;

PROCEDURE (i : Input) AppendPath* (path : STRING);
BEGIN
  i.path.Append(path);
END AppendPath;

PROCEDURE (i : Input) AppendFrameworkPath* (path : STRING);
BEGIN
  i.frameworks.Append(path);
END AppendFrameworkPath;

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

PROCEDURE (i : Input) SearchFile(path : STRING; VAR channel : IO.ByteChannel) : BOOLEAN;
BEGIN
  Log.Object("SearchFile", path);
  TRY
    channel := FileChannel.Open(path, {FileChannel.read});
    RETURN TRUE;
  CATCH IO.Error:
    RETURN FALSE;
  END;
END SearchFile;

PROCEDURE (i : Input) SearchFramework(base : STRING; fileName : STRING; frameworkName : STRING; VAR path : STRING; VAR channel : IO.ByteChannel) : BOOLEAN;
VAR 
  pos : LONGINT;
  list : Files.NameArray;
  frameworksDir, element, root, ext, includeDir : STRING;
BEGIN
  frameworksDir := base + "/Frameworks";
  IF Files.Exists(frameworksDir) THEN
    (* how to check if this is a file or directory *)
  TRY
    list := Files.ListDir(frameworksDir);
    IF (list # NIL) THEN
      FOR pos := 0 TO LEN(list^)-1 DO
        element := frameworksDir + "/" + list[pos];
        Path.SplitExt(Path.BaseName(element), root, ext);
        IF ext.Equals(".framework") THEN
          includeDir := element + "/Headers/";
          IF root.Equals(frameworkName) THEN
            path := includeDir + fileName;
            IF i.SearchFile(path, channel) THEN RETURN TRUE END;
          END;
          path := includeDir + frameworkName + "/" + fileName;
          IF i.SearchFile(path, channel) THEN RETURN TRUE END;
          IF i.SearchFramework(element, fileName, frameworkName, path, channel) THEN
            RETURN TRUE;
          END;
        END
      END
    END
  CATCH IO.Error:
  END;
  END;
  RETURN FALSE
END SearchFramework;

(* Locate a file using Apple "framework" packages. 
Note: this implementation is a little slow. Rather than searching the
entire pacakge tree for every file, a package directory should be build
using just one search at the start. *)

PROCEDURE (i : Input) SearchFrameworks(name : STRING; VAR path : STRING; VAR channel : IO.ByteChannel) : BOOLEAN;
VAR
  pos : LONGINT;
  obj : Object.Object;
  fileName, frameworkName : STRING;
BEGIN
  fileName := Path.BaseName(name);
  frameworkName := Path.DirName(name);
  FOR pos := 0 TO i.frameworks.Size() - 1 DO
    obj := i.frameworks.Get(pos);
    IF i.SearchFramework(obj(STRING), fileName, frameworkName, path, channel) THEN 
      RETURN TRUE
    END;
  END;
  RETURN FALSE;
END SearchFrameworks;

PROCEDURE (i : Input) SearchPath(fileName : STRING; VAR path : STRING; VAR channel : IO.ByteChannel) : BOOLEAN;
VAR 
  pos : LONGINT;
  obj : Object.Object;
BEGIN
  FOR pos := 0 TO i.path.Size() - 1 DO
    obj := i.path.Get(pos);
    path := obj(STRING) + "/" + fileName;
    IF i.SearchFile(path, channel) THEN 
      RETURN TRUE
    END;
  END;
  RETURN FALSE;
END SearchPath;

PROCEDURE (i : Input) Include* (fileName : STRING; search : BOOLEAN);
VAR
  realFileName : STRING;
  moduleName : STRING;
  module : Module.Module;
  s : Source;
  channel : IO.ByteChannel;
BEGIN
  TRY
    IF search THEN
      IF ~i.SearchPath(fileName, realFileName, channel) &
         ~i.SearchFrameworks(fileName, realFileName, channel) THEN
        Err.String ("Error: Cannot locate module ");
        Err.Object (fileName);
        Err.Ln;
        HALT (1)
      END;    
    ELSE
      realFileName := fileName;
      channel := FileChannel.Open(fileName, {FileChannel.read});
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
  s.name := realFileName;
  i.src := s;
  Err.String("<Processing "); Err.Object(s.name); Err.Char(">"); Err.Ln;

  moduleName := Module.ModuleName(realFileName);
  module := Module.FindModule(moduleName);
  IF module = NIL THEN
    Err.String("NEW ");
    module := Module.NewModule(moduleName);
  END;
  Err.String("MODULE "); Err.Object(moduleName); 
  Err.String(" for "); Err.Object(realFileName);
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
  i.path := ArrayList.New(10);
  i.frameworks := ArrayList.New(10);
  RETURN i;
END New;

END H2O:Source.
