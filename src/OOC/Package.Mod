MODULE OOC:Package;

IMPORT
  Log, Msg, URI, URI:Scheme:File, Config:Parser, OOC:Logger, OOC:Error;

TYPE
  URIBuffer = ARRAY 1024 OF CHAR;
  
PROCEDURE ParseFile* (fileName: URI.URI; VAR errList: Error.List);
  VAR
    p: Parser.Parser;
    res: Msg.Msg;
    path: URIBuffer;
  BEGIN
    Logger.ReadFile(fileName);
    fileName(File.URI).GetPath(path);
    p := Parser.NewFile (path, res);
    IF (res # NIL) THEN
      errList. Append (res)
    ELSE
      p. ParseDocument();
      IF (p. errList. msgCount = 0) THEN
        Log.LString("root", p.root.name^);
      ELSE
        errList. AppendList (p. errList)
      END
    END
  END ParseFile;

END OOC:Package.
