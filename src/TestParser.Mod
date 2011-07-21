MODULE TestParser;

IMPORT
  ProgramArgs, TR := TextRider, Out, Msg,
  Object, IO, IO:FileChannel, IO:StdChannels, IO:TextRider, 
  OOC:Config:Pragmas, OOC:Error, OOC:Scanner:InputBuffer, 
  OOC:Scanner, OOC:Scanner:SymList, OOC:Parser, 
  OOC:AST, OOC:AST:XML, OOC:AST:StupidPP;
  
CONST
  modeXML = 0;
  modeStupidPP = 1;
  
VAR
  argReader: TR.Reader;
  file: IO.ByteChannel;
  arg, msgText: ARRAY 1024 OF CHAR;
  res: Msg.Msg;
  errList: Error.List;
  inputBuffer: InputBuffer.Buffer;
  pragmaSection: Pragmas.Section;
  scannerBuilder: SymList.Builder;
  astBuilder: AST.Builder;
  ast: AST.Node;
  mode: INTEGER;
BEGIN
  IF (ProgramArgs.args. ArgNumber() = 0) THEN
    Out.String ("Usage: TestParser [--xml|--stupid-pp] <file>"); Out.Ln;
    HALT (1)
  ELSE
    mode := modeXML;
    argReader := TR.ConnectReader (ProgramArgs.args);
    argReader. ReadLine (arg);           (* skip command name *)
    LOOP
      argReader. ReadLine (arg);
      IF (argReader. res # TR.done) THEN
        EXIT
      END;
      
      IF (arg = "--xml") THEN
        mode := modeXML
      ELSIF (arg = "--stupid-pp") THEN
        mode := modeStupidPP
      ELSE
        file := FileChannel.Open(Object.NewLatin1(arg), {FileChannel.read});
        IF (file = NIL) THEN
          res. GetText (msgText);
          Out.String ("Error opening "); Out.String (arg); Out.Ln;
          Out.String (msgText); Out.Ln;
          HALT (1)
        ELSE
          errList := Error.NewList(Object.NewLatin1(arg));
          inputBuffer := InputBuffer.New (file, errList);
          pragmaSection := Pragmas.New();
          scannerBuilder := SymList.New (inputBuffer, TRUE);
          Scanner.ScanInput (scannerBuilder, pragmaSection, Scanner.enableAll);
          astBuilder := AST.New();
          ast := Parser.Module (scannerBuilder. head, 
                                astBuilder, errList, Parser.enableAll);
          
          CASE mode OF
          | modeXML:
            XML.Write (StdChannels.stdout, ast(AST.Module))
          | modeStupidPP:
            StupidPP.Write (TextRider.ConnectWriter (StdChannels.stdout),
                            ast(AST.Module))
          END;
          IF (errList. msgCount # 0) THEN
            errList. Write (StdChannels.stderr);
            HALT (1)
          END
        END
      END
    END
  END
END TestParser.
