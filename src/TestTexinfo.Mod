MODULE TestTexinfo;

IMPORT
  StdChannels, ProgramArgs, TextRider, Out, Files, Msg, Std:=IO:StdChannels,
  OOC:Error, OOC:Scanner:InputBuffer, OOC:Scanner:BasicList,
  OOC:Doc, OOC:Doc:Input:Texinfo, OOC:Doc:Output:XML, OOC:Doc:Output:Text;

CONST
  modeXML = 0;
  modeText = 1;
  
VAR
  argReader: TextRider.Reader;
  file: Files.File;
  arg, msgText: ARRAY 1024 OF CHAR;
  res: Msg.Msg;
  errList: Error.List;
  mode: INTEGER;
  document: Doc.Document;
  s: Doc.String;
  processComment: BOOLEAN;

PROCEDURE GetFile (file: Files.File): BasicList.Symbol;
  VAR
    len: LONGINT;
    reader: Files.Reader;
    s: InputBuffer.CharArray;
  BEGIN
    len := file. Length();
    NEW (s, len+1);
    reader := file. NewReader();
    reader. ReadBytes (s^, 0, len);
    ASSERT (reader. res = Files.done);
    s[len] := 0X;
    file. Close;
    RETURN BasicList.NewSymbol (s, reader. bytesRead)
  END GetFile;

BEGIN
  IF (ProgramArgs.args. ArgNumber() = 0) THEN
    Out.String ("Usage: TestTexinfo [--xml|--text][--comment] <file>"); Out.Ln;
    HALT (1)
  ELSE
    mode := modeXML;
    processComment := FALSE;
    argReader := TextRider.ConnectReader (ProgramArgs.args);
    argReader. ReadLine (arg);           (* skip command name *)
    LOOP
      argReader. ReadLine (arg);
      IF (argReader. res # TextRider.done) THEN
        EXIT
      END;
      
      IF (arg = "--xml") THEN
        mode := modeXML
      ELSIF (arg = "--text") THEN
        mode := modeText
      ELSIF (arg = "--comment") THEN
        processComment := TRUE
      ELSE
        file := Files.Old (arg, {Files.read}, res);
        IF (file = NIL) THEN
          res. GetText (msgText);
          Out.String ("Error opening "); Out.String (arg); Out.Ln;
          Out.String (msgText); Out.Ln;
          HALT (1)
        ELSE
          errList := Error.NewList (arg);
          document := Texinfo.Parse (GetFile (file), processComment, errList);
          IF (errList. msgCount # 0) THEN
            errList. Write (StdChannels.stderr);
            HALT (1)
          ELSE
            CASE mode OF
            | modeXML:
              XML.Write (Std.stdout, document, NIL, NIL, NIL, NIL);
            | modeText:
              s := Text.Convert (document, 0, 71, 3);
              Out.String (s^)
            END
          END
        END
      END
    END
  END
END TestTexinfo.
