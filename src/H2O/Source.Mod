MODULE H2O:Source [OOC_EXTENSIONS];

IMPORT
  H2O:Type, H2O:Option,
  Object, Err, Log, ADT:Dictionary,
  IO, IO:FileChannel, IO:Memory, OS:Files, OS:Path, Exception;

CONST
  cr = 0DX;
  eol* = 0AX;
  eof* = 04X;

TYPE
  Source* = POINTER TO SourceDesc;
  SourceDesc = RECORD
    isFile : BOOLEAN;
    name : STRING;
    pos, line, col : LONGINT;
	channel : IO.ByteChannel;
    next : Source;
    module : Type.Module;
  END;

  Input* = POINTER TO InputDesc;
  InputDesc = RECORD
    lines, files : LONGINT;
    src : Source;

    options- : Option.Options;
    path : Option.StringList;
    exclude : Option.StringList;
    frameworks : Option.StringList;

(* frameworkMap associates each framework with the path to its Headers
   directory. *)
    frameworkMap : Dictionary.Dictionary(STRING,STRING);

(* frameworkLength is the number of options elements currently incorporated
   into the frameworkMap. The map is generated on demand when an include is
   required and unprocessed options elements exist. *)
    frameworkLength : LONGINT;
  END;

VAR
  options- : Option.Options;

  outputSearchFile : Option.Boolean;
  outputFrameworkPath : Option.Boolean;

PROCEDURE (i : Input) AppendPath* (path : STRING);
BEGIN
  i.path.value.Append(path);
END AppendPath;

PROCEDURE (i : Input) AppendFrameworkPath* (path : STRING);
BEGIN
  i.frameworks.value.Append(path);
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

PROCEDURE (i : Input) SearchFile(path : STRING; VAR channel : IO.ByteChannel) : BOOLEAN;
BEGIN
  IF outputSearchFile.value THEN
    Log.Object("SearchFile", path);
  END;
  TRY
    channel := FileChannel.Open(path, {FileChannel.read});
    RETURN TRUE;
  CATCH IO.Error:
    RETURN FALSE;
  END;
END SearchFile;

PROCEDURE (i : Input) FindFramework(base : STRING);
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
            i.frameworkMap.Set(root, includeDir);
            IF outputFrameworkPath.value THEN
              Log.Object("Framework", root + " at " + includeDir);
            END;
            i.FindFramework(element);
          END
        END
      END
    CATCH IO.Error:
    END
  END
END FindFramework;

(* Locate a file using Apple "framework" packages. 
Note: this implementation is a little slow. Rather than searching the
entire pacakge tree for every file, a package directory should be build
using just one search at the start. *)

PROCEDURE (i : Input) FindFrameworks;
VAR
  pos, length : LONGINT;
  obj : STRING;
BEGIN
  length := i.frameworks.value.Size();
  FOR pos := i.frameworkLength TO length - 1 DO
    obj := i.frameworks.value.Get(pos);
    i.FindFramework(obj)
  END;
  i.frameworkLength := length;
END FindFrameworks;

(* Locate a file using Apple "framework" packages. 
Note: this implementation is a little slow. Rather than searching the
entire pacakge tree for every file, a package directory should be build
using just one search at the start. *)

PROCEDURE (i : Input) SearchFrameworks(name : STRING; VAR path : STRING; VAR channel : IO.ByteChannel) : BOOLEAN;
VAR
  directory : STRING;
  fileName, frameworkName : STRING;
BEGIN
  fileName := Path.BaseName(name);
  frameworkName := Path.DirName(name);

  i.FindFrameworks;
  IF i.frameworkMap.HasKey(frameworkName) THEN
    directory := i.frameworkMap.Get(frameworkName);
    path := directory + fileName;
    RETURN i.SearchFile(path, channel);
  ELSE
    Log.Object("Unknown framework", frameworkName);
    RETURN FALSE;    
  END;
END SearchFrameworks;

PROCEDURE (i : Input) SearchPath(fileName : STRING; VAR path : STRING; VAR channel : IO.ByteChannel) : BOOLEAN;
VAR 
  pos : LONGINT;
  obj : Object.Object;
BEGIN
  FOR pos := 0 TO i.path.value.Size() - 1 DO
    obj := i.path.value.Get(pos);
    path := obj(STRING) + "/" + fileName;
    IF i.SearchFile(path, channel) THEN 
      RETURN TRUE
    END;
  END;
  RETURN FALSE;
END SearchPath;

PROCEDURE (i : Input) PushSource(channel : IO.ByteChannel; name : STRING; module : Type.Module; isFile : BOOLEAN);
VAR
  s : Source;
BEGIN
  NEW(s);
  s.channel := channel;
  s.pos := 0;
  s.line := 0;
  s.col := 0;
  s.next := i.src;
  s.name := name;
  s.module := module;
  s.isFile := isFile;
  i.src := s;
  Err.String("<Processing "); Err.Object(s.name); Err.Char(">"); Err.Ln;
END PushSource;

PROCEDURE (i : Input) PushProlog(prolog : STRING; module : Type.Module; suffix : STRING);
VAR
  channel : IO.ByteChannel;
  string8 : Object.String8;
  chars8 : Object.CharsLatin1;
  length : LONGINT;
BEGIN
  string8 := prolog.ToString8(" ");
  chars8 := string8.CharsLatin1();
  TRY 
    channel := Memory.Open();
    length := channel.Write(chars8^, 0, LEN(chars8^)-1);
    channel.SetPos(0);
    i.PushSource(channel, module.name + ":" + suffix, module, FALSE);
  CATCH IO.Error:
    i.Exception(Exception.Current())
  END;
END PushProlog;

PROCEDURE (i : Input) Include* (fileName : STRING; search : BOOLEAN);
VAR
  found : BOOLEAN;
  realFileName : STRING;
  moduleName : STRING;
  module : Type.Module;
  channel : IO.ByteChannel;
  prolog : STRING;
BEGIN
  IF i.exclude.Contains(fileName) THEN 
    RETURN;
  END;
  IF search THEN
    found := i.SearchPath(fileName, realFileName, channel) OR
      i.SearchFrameworks(fileName, realFileName, channel);
  ELSE
    IF i.src = NIL THEN
      realFileName := fileName;
    ELSE
      realFileName := Path.DirName(i.src.name) + "/" + fileName;
    END;
    found := i.SearchFile(realFileName, channel);
  END;
  IF ~found THEN
    Err.String ("Error: Cannot locate module ");
    Err.Object (fileName);
    Err.Ln;
    HALT (1)
  END;    

  realFileName := realFileName.ToString8("_");
  moduleName := Type.ModuleName(realFileName);
  module := Type.FindModule(moduleName);
  IF module = NIL THEN
    Err.String("NEW ");
    module := Type.NewModule(moduleName);
  END;
  Err.String("MODULE "); Err.Object(moduleName); 
  Err.String(" for "); Err.Object(realFileName);
  Err.Ln;
  i.PushSource(channel, realFileName, module, TRUE);
  prolog := module.prolog.value;
  IF prolog.length > 0 THEN
    i.PushProlog(prolog, module, "Prolog");
  END;
END Include;

PROCEDURE (i : Input) ReadChar* (VAR ch : CHAR);
VAR
  count : LONGINT;
  src : Source; epilog : STRING;
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
            src := i.src;
            i.src.channel.Close;
            INC(i.lines, i.src.line); INC(i.files);
            i.src := i.src.next;
            ch := cr;

            (* check for module epilog *)
            epilog := src.module.epilog.value ;
            IF src.isFile & (epilog.length > 0)  THEN
              i.PushProlog(epilog, src.module, "Epilog")
            END;
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

PROCEDURE (i : Input) GetModule*() : Type.Module;
BEGIN
  RETURN i.src.module;
END GetModule;
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

  i.options := NEW(Option.Options);
  i.path := i.options.StringList("Include");
  i.exclude := i.options.StringList("Exclude");
  i.frameworks := i.options.StringList("Framework");
  i.frameworkMap := NEW(Dictionary.Dictionary(STRING,STRING));
  i.frameworkLength := 0;
  RETURN i;
END New;

PROCEDURE InitOptions;
BEGIN
  options := NEW(Option.Options);
  outputSearchFile := options.Boolean("OutputSearchFile", FALSE);
  outputFrameworkPath := options.Boolean("OutputFrameworkPath", FALSE);
END InitOptions;

BEGIN
  InitOptions;
END H2O:Source.
