MODULE OOC:Logger;

IMPORT
  Out, URI, URI:Scheme:File;

VAR
  cwd: File.URI;
  indentMake: LONGINT;

CONST
  logMake = FALSE;
      
PROCEDURE WriteURI (uri: URI.URI);
  VAR
    str: ARRAY 1024 OF CHAR;
  BEGIN
    uri := uri.MakeRelative(cwd);
    uri.GetString(str);
    Out.String(str);
  END WriteURI;

PROCEDURE ReadFile* (uri: URI.URI);
  BEGIN
    Out.String("- ");
    WriteURI(uri);
    Out.Ln;
  END ReadFile;

PROCEDURE WriteFile* (uri: URI.URI);
  BEGIN
    Out.String("+ ");
    WriteURI(uri);
    Out.Ln;
  END WriteFile;

PROCEDURE ShellCommand* (str: ARRAY OF CHAR);
  BEGIN
    Out.String (str);
    Out.Ln;
    Out.Flush;
  END ShellCommand;

PROCEDURE IndentMake;
  VAR
    i: LONGINT;
  BEGIN
    Out.String("[make]");
    FOR i := 1 TO indentMake DO
      Out.String ("  ");
    END;
  END IndentMake;

PROCEDURE EnterMake*(rule, module: ARRAY OF CHAR);
  BEGIN
    IF logMake THEN
      IndentMake;
      Out.String("enter ");
      Out.String(rule);
      Out.String(" for ");
      Out.String(module);
      Out.Ln;
      INC(indentMake);
    END;
  END EnterMake;

PROCEDURE ExitMake*(rule, module: ARRAY OF CHAR; success: BOOLEAN): BOOLEAN;
  BEGIN
    IF logMake THEN
      DEC(indentMake);
      IndentMake;
      Out.String("leave ");
      Out.String(rule);
      Out.String(" for ");
      Out.String(module);
      IF success THEN
        Out.String (" (success)");
      ELSE
        Out.String (" (failure)");
      END;
      Out.Ln;
    END;
    RETURN success;
  END ExitMake;

PROCEDURE CachedMake*(rule, module: ARRAY OF CHAR; success: BOOLEAN): BOOLEAN;
  BEGIN
    IF logMake THEN
      IndentMake;
      Out.String("cached result: ");
      Out.String(rule);
      Out.String(" for ");
      Out.String(module);
      IF success THEN
        Out.String (" (success)");
      ELSE
        Out.String (" (failure)");
      END;
      Out.Ln;
    END;
    RETURN success;
  END CachedMake;

PROCEDURE ExplainMake*(s1: ARRAY OF CHAR);
  BEGIN
    IF logMake THEN
      IndentMake;
      Out.String(s1);
      Out.Ln;
    END;
  END ExplainMake;

PROCEDURE ExplainFileMake*(s1: ARRAY OF CHAR; uri1: URI.URI;
                           s2: ARRAY OF CHAR);
  BEGIN
    IF logMake THEN
      IndentMake;
      Out.String(s1);
      WriteURI(uri1);
      Out.String(s2);
      Out.Ln;
    END;
  END ExplainFileMake;

PROCEDURE ExplainFilesMake*(s1: ARRAY OF CHAR; uri1: URI.URI;
                            s2: ARRAY OF CHAR; uri2: URI.URI;
                            s3: ARRAY OF CHAR);
  BEGIN
    IF logMake THEN
      IndentMake;
      Out.String(s1);
      WriteURI(uri1);
      Out.String(s2);
      WriteURI(uri2);
      Out.String(s3);
      Out.Ln;
    END;
  END ExplainFilesMake;

BEGIN
  cwd := File.GetCwd();
  indentMake := 0;
END OOC:Logger.
