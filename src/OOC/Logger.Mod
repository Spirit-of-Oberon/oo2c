MODULE OOC:Logger;

IMPORT
  Out, URI, URI:Scheme:File;

VAR
  cwd: File.URI;
  
PROCEDURE WriteURI (uri: URI.URI);
  VAR
    str: ARRAY 1024 OF CHAR;
  BEGIN
    uri := uri.MakeRelative(cwd);
    uri.GetString(str);
    Out.String(str);
    Out.Ln;
  END WriteURI;

PROCEDURE ReadFile* (uri: URI.URI);
  BEGIN
    Out.String("- ");
    WriteURI(uri);
  END ReadFile;

PROCEDURE WriteFile* (uri: URI.URI);
  BEGIN
    Out.String("+ ");
    WriteURI(uri);
  END WriteFile;

BEGIN
  cwd := File.GetCwd();
END OOC:Logger.
