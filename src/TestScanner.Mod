MODULE TestScanner;

IMPORT
  ProgramArgs, TextRider, Out, Object, IO, IO:FileChannel, IO:StdChannels, Config,
  OOC:Config:Pragmas, OOC:Error, OOC:Scanner:InputBuffer, OOC:Scanner:SymList,
  OOC:Scanner, OOC:Scanner:XML, OOC:Scanner:Identity, 
  OOC:Scanner:Statistics;

CONST
  modeXML = 0;
  modeIdentity = 1;
  modeStatistics = 2;
  
VAR
  argReader: TextRider.Reader;
  file: IO.ByteChannel;
  arg: ARRAY 1024 OF CHAR;
  errList: Error.List;
  inputBuffer: InputBuffer.Buffer;
  pragmaSection: Pragmas.Section;
  pv: Pragmas.Pragma;
  scannerBuilder: SymList.Builder;
  mode: INTEGER;
BEGIN
  IF (ProgramArgs.args. ArgNumber() = 0) THEN
    Out.String ("Usage: TestScanner [--xml|--identity|--statistics] <file>"); Out.Ln;
    HALT (1)
  ELSE
    mode := modeXML;
    argReader := TextRider.ConnectReader (ProgramArgs.args);
    argReader. ReadLine (arg);           (* skip command name *)
    LOOP
      argReader. ReadLine (arg);
      IF (argReader. res # TextRider.done) THEN
        EXIT
      END;
      
      IF (arg = "--xml") THEN
        mode := modeXML
      ELSIF (arg = "--identity") THEN
        mode := modeIdentity
      ELSIF (arg = "--statistics") THEN
        mode := modeStatistics
      ELSE
        file := FileChannel.Open(Object.NewLatin1(arg), {FileChannel.read});
        
        errList := Error.NewList(Object.NewLatin1(arg));
        inputBuffer := InputBuffer.New (file, errList);
        pragmaSection := Pragmas.New();
        pv := pragmaSection. Set ("predef_true", Config.NewBooleanVar(TRUE));
        pv := pragmaSection. Set ("predef_false", Config.NewBooleanVar(FALSE));
        
        CASE mode OF
        | modeXML:
          scannerBuilder := XML.New (inputBuffer, StdChannels.stdout)
        | modeIdentity:
          scannerBuilder := Identity.New (inputBuffer, StdChannels.stdout)
        | modeStatistics:
          scannerBuilder := Statistics.New (inputBuffer, StdChannels.stdout)
        END;
        
        Scanner.ScanInput (scannerBuilder, pragmaSection, Scanner.enableAll);
        IF (errList. msgCount # 0) THEN
          errList. Write (StdChannels.stderr);
          HALT (1)
        END
      END
    END
  END
END TestScanner.
