MODULE OOC:Logger;

IMPORT
  Out, URI, URI:Scheme:File;

VAR
  cwd: File.URI;
  indentMake: LONGINT;

CONST
  logMake = FALSE;

VAR
  silence*: BOOLEAN;
  (**If @code{TRUE}, then this module does not produce any output.  *)


PROCEDURE WriteURI (uri: URI.URI);
  BEGIN
    IF ~silence THEN
      WITH uri: File.URI DO
        Out.Object(uri.GetPath());
      ELSE
        Out.Object(uri.ToString());
      END;
    END;
  END WriteURI;

PROCEDURE ReadFile* (uri: URI.URI);
  BEGIN
    IF ~silence THEN
      Out.String("- ");
      WriteURI(uri);
      Out.Ln;
      Out.Flush;
    END;
  END ReadFile;

PROCEDURE ReadFileName* (fileName: STRING);
  BEGIN
    IF ~silence THEN
      Out.String("- ");
      Out.Object(fileName);
      Out.Ln;
      Out.Flush;
    END;
  END ReadFileName;

PROCEDURE WriteFile* (uri: URI.URI);
  BEGIN
    IF ~silence THEN
      Out.String("+ ");
      WriteURI(uri);
      Out.Ln;
      Out.Flush;
    END;
  END WriteFile;

PROCEDURE WriteFileName* (fileName: STRING);
  BEGIN
    IF ~silence THEN
      Out.String("+ ");
      Out.Object(fileName);
      Out.Ln;
      Out.Flush;
    END;
  END WriteFileName;

PROCEDURE ShellCommand* (str: STRING);
  BEGIN
    IF ~silence THEN
      Out.Object(str);
      Out.Ln;
      Out.Flush;
    END;
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
    IF ~silence & logMake THEN
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
    IF ~silence & logMake THEN
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
    IF ~silence & logMake THEN
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
    IF ~silence & logMake THEN
      IndentMake;
      Out.String(s1);
      Out.Ln;
    END;
  END ExplainMake;

PROCEDURE ExplainFileMake*(s1: ARRAY OF CHAR; uri1: URI.URI;
                           s2: ARRAY OF CHAR);
  BEGIN
    IF ~silence & logMake THEN
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
    IF ~silence & logMake THEN
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
  silence := FALSE;
END OOC:Logger.
