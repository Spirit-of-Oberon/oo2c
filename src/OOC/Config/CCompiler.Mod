MODULE OOC:Config:CCompiler;

IMPORT
  Strings, URI, URI:Scheme:File, Config:Section:Options;
  
PROCEDURE CompileFileCmd* (options: Options.Section; in, out: URI.URI;
                           VAR cmd: ARRAY OF CHAR);
  VAR
    str: ARRAY 1024 OF CHAR;
  BEGIN
    COPY ("gcc -g -pipe -c ", cmd);
    in(File.URI). GetPath (str);
    Strings.Append (str, cmd);
    Strings.Append (" -o ", cmd);
    out(File.URI). GetPath (str);
    Strings.Append (str, cmd);
  END CompileFileCmd;

PROCEDURE LinkProgramCmd* (options: Options.Section; execFile: URI.URI;
                           VAR cmd: ARRAY OF CHAR);
  VAR
    str: ARRAY 1024 OF CHAR;
  BEGIN
    COPY ("gcc -g -pipe -o ", cmd);
    execFile(File.URI). GetPath (str);
    Strings.Append (str, cmd)
  END LinkProgramCmd;

END OOC:Config:CCompiler.
