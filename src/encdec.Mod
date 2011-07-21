MODULE encdec;

IMPORT
  SYSTEM, Ascii, Channel, Files, Log, Msg,
  ProgramArgs, StdChannels, TextRider, 
  Object, ADT:StringBuffer, Codec,
  Codec:Latin1, Codec:UTF32, Codec:UU, Codec:YEnc,
  Codec:Twofish, Codec:Deflate;

TYPE
  State = PROCEDURE (VAR data: ARRAY OF CHAR; start, end: LONGINT): LONGINT;
  (* Process `data' starting at `start', and stop when reaching `end'.  Result
     is the position of the first character of the line that is not processed
     by this state.  The procedure must either return a value larger than
     `start', or change the value of the global variable `state'.

     At least one full line of data is passed to the procedure.  It cannot rely
     on getting more than a single line.

     side-effect: The global variable `state' is changed to the next state
     processor.

     precond: start<end & IsEOL(data[end-1]) & data[start,end-1] holds at least
     one full line of input  *)

CONST
  sizeBuffer = 8*1024;
  encode = 0;
  decode = 1;
  decodeFiles = 2;
  
VAR
  mode: SHORTINT;
  codec1: Codec.Codec;
  key: Object.String;
  
  codecUU, codecYEnc: Codec.Codec;
  decoder: Codec.Decoder;
  outputBuffer: StringBuffer.StringBuffer;
  state: State;
  yencHeader: YEnc.Header;
  
  enc: Codec.Encoder;
  dec: Codec.Decoder;
  r: Channel.Reader;
  w: Channel.Writer;
  file: Files.File;

PROCEDURE StartFile (codec: Codec.Codec; name: ARRAY OF CHAR);
  VAR
    c: Object.CharsLatin1;
    res: Msg.Msg;
  BEGIN
    Log.String ("writing to file", name);
    c := codec.preferredName(Object.String8).CharsLatin1();
    Log.String ("codec", c^);

    file := Files.New(name, {Files.write}, res);
    ASSERT(res = Files.done);
    w := file.NewWriter();
  END StartFile;

PROCEDURE EndFile (complete: BOOLEAN);
  BEGIN
    ASSERT (file # NIL);
    
    IF complete THEN
      Log.Msg ("  --> done");
    ELSE
      Log.Msg ("  --> done (partial file)");
    END;
    file.Close();
    ASSERT(file.res = Files.done);
    w := NIL;
    file := NIL;
  END EndFile;


PROCEDURE ^ SearchForFile (VAR data: ARRAY OF CHAR; start, end: LONGINT): LONGINT;
PROCEDURE ^ ProcessDataUU (VAR data: ARRAY OF CHAR; start, end: LONGINT): LONGINT;

PROCEDURE SkipJunkUU (VAR data: ARRAY OF CHAR; start, end: LONGINT): LONGINT;
  VAR
    eol: LONGINT;
  BEGIN
    LOOP
      eol := UU.LineData (data, start, end);
      IF (eol >= 0) THEN
        state := ProcessDataUU;
        EXIT;
      ELSE
        eol := YEnc.LineBegin (data, start, end, yencHeader);
        IF (eol < 0) THEN
          eol := YEnc.LineBegin (data, start, end, yencHeader);
        END;
        IF (eol >= 0) THEN
          (* found beginning of other file: current uuencoded file is
             incomplete *)
          Log.String ("error", "found begin line in uuencode data");
          EndFile(FALSE);
          state := SearchForFile;
          EXIT;
        END;
      END;

      WHILE (start # end) & ~UU.IsEOL (data[start])  DO
        INC (start);
      END;
      WHILE (start # end) & UU.IsEOL (data[start])  DO
        INC (start);
      END;
    END;
    RETURN start;
  END SkipJunkUU;

PROCEDURE ProcessDataUU (VAR data: ARRAY OF CHAR; start, end: LONGINT): LONGINT;
  VAR
    eol, startOfData, endOfData: LONGINT;
    chars: StringBuffer.CharsLatin1;
  BEGIN
    startOfData := start;
    LOOP
      eol := UU.LineData (data, start, end);
      IF (eol >= 0) THEN
        start := eol;
        WHILE (start # end) & UU.IsEOL (data[start]) DO INC (start) END;
      ELSE
        endOfData := start;
        eol := UU.LineEnd (data, start, end);
        IF (eol >= 0) THEN
          start := eol;
          WHILE (start # end) & UU.IsEOL (data[start]) DO INC (start) END;
          state := SearchForFile;
        ELSE
          state := SkipJunkUU;
        END;
        EXIT;
      END;

      IF (start = end) THEN
        endOfData := start;
        EXIT
      END;
    END;

    decoder. Decode (data, startOfData, endOfData, outputBuffer);

    IF (state # ProcessDataUU) OR
       (outputBuffer. length >= sizeBuffer DIV 2) THEN
      chars := outputBuffer.CharsLatin1();
      w.WriteBytes(chars^, 0, outputBuffer.length);
      outputBuffer.Clear;

      IF (state = SearchForFile) THEN
        EndFile(TRUE);
      END;
    END;

    RETURN start;
  END ProcessDataUU;

PROCEDURE SearchNextYEnc (VAR data: ARRAY OF CHAR; start, end: LONGINT): LONGINT;
  VAR
    eol: LONGINT;
    yencHeader: YEnc.Header;
    uuHeader: UU.Header;
  BEGIN
    LOOP
      eol := YEnc.LineBegin (data, start, end, yencHeader);
      IF (eol < 0) THEN
        eol := UU.LineBegin (data, start, end, uuHeader);
        IF (eol >= 0) THEN
          (* looking for further yenc parts, but got some uuencoded data:
             looks like the yenc data is incomplete *)
          Log.String ("error", "found uuencode begin line in yenc data");
          EndFile(FALSE);
        END;
      END;
      IF (eol >= 0) THEN
        state := SearchForFile;
        EXIT;
      END;

      WHILE (start # end) & ~UU.IsEOL (data[start])  DO
        INC (start);
      END;
      WHILE (start # end) & UU.IsEOL (data[start])  DO
        INC (start);
      END;
    END;
    RETURN start;
  END SearchNextYEnc;

PROCEDURE ProcessDataYEnc (VAR data: ARRAY OF CHAR; start, end: LONGINT): LONGINT;
  VAR
    eol, startOfData, endOfData: LONGINT;
    chars: StringBuffer.CharsLatin1;
    endOfPart: BOOLEAN;
  BEGIN
    endOfPart := FALSE;
    startOfData := start;
    LOOP
      eol := YEnc.LineData (data, start, end, yencHeader);
      IF (eol >= 0) THEN
        start := eol;
        WHILE (start # end) & UU.IsEOL (data[start]) DO INC (start) END;
      ELSE
        endOfData := start;
        eol := YEnc.LineEnd (data, start, end, yencHeader);
        endOfPart := (eol >= 0);
        IF endOfPart THEN
          start := eol;
          WHILE (start # end) & UU.IsEOL (data[start]) DO INC (start) END;
        END;

        IF (yencHeader.part > 0) & (yencHeader.partEnd # yencHeader.size) THEN
          state := SearchNextYEnc;
        ELSE
          state := SearchForFile;
        END;
        EXIT;
      END;

      IF (start = end) THEN
        endOfData := start;
        EXIT
      END;
    END;

    decoder. Decode (data, startOfData, endOfData, outputBuffer);

    IF (state # ProcessDataYEnc) OR
       (outputBuffer. length >= sizeBuffer DIV 2) THEN
      chars := outputBuffer.CharsLatin1();
      w.WriteBytes(chars^, 0, outputBuffer.length);
      outputBuffer.Clear;

      IF (state # ProcessDataYEnc) & (state # SearchNextYEnc) THEN
        (* fixme... check crc32, check size *)
        EndFile(endOfPart);
      END;
    END;

    RETURN start;
  END ProcessDataYEnc;

PROCEDURE ProcessPartHeaderYEnc (VAR data: ARRAY OF CHAR; start, end: LONGINT): LONGINT;
  VAR
    eol: LONGINT;
  BEGIN
    eol := YEnc.LinePart (data, start, end, yencHeader);
    IF (eol >= 0) THEN
      start := eol;
      WHILE (start # end) & UU.IsEOL (data[start]) DO INC (start) END;
      
      (* check begin... *)
      
      decoder := codecYEnc.NewDecoder();
      decoder.Start;
      state := ProcessDataYEnc;
      IF (file = NIL) THEN (* first part of single of multipart yenc *)
        StartFile(codecYEnc, yencHeader.fileName);
      END;

      Log.LongInt ("yenc part begin", yencHeader.partBegin);
      Log.LongInt ("yenc part end", yencHeader.partEnd);
      RETURN start;
    ELSE
      Log.String ("error", "missing =ypart line");
      IF (file # NIL) THEN
        EndFile(FALSE);
      END;
      
      state := SearchForFile;
      RETURN start;              (* missing =ypart line *)
    END;
  END ProcessPartHeaderYEnc;

PROCEDURE SearchForFile (VAR data: ARRAY OF CHAR; start, end: LONGINT): LONGINT;
  VAR
    eol: LONGINT;
    uuHeader: UU.Header;
    oldHeader: YEnc.Header;
    
  PROCEDURE HeadersMatch (VAR old, new: YEnc.Header): BOOLEAN;
    BEGIN
      IF (old.fileName # new.fileName) THEN
        Log.String("error", "file name mismatch in yenc parts");
        RETURN FALSE;
      ELSIF (old.size # new.size) THEN
        Log.String("error", "size mismatch in yenc parts");
        RETURN FALSE;
      ELSE
        RETURN TRUE;
      END;
    END HeadersMatch;
  
  BEGIN
    WHILE (start < end) DO
      eol := UU.LineBegin (data, start, end, uuHeader);
      IF (eol >= 0) THEN
        start := eol;
        WHILE (start # end) & UU.IsEOL (data[start]) DO INC (start) END;
        decoder := codecUU.NewDecoder();
        decoder.Start;
        state := ProcessDataUU;
        StartFile(codecUU, uuHeader.fileName);
        RETURN start;
      ELSE
        oldHeader := yencHeader;
        eol := YEnc.LineBegin (data, start, end, yencHeader);
        IF (eol >= 0) THEN
          start := eol;
          WHILE (start # end) & UU.IsEOL (data[start]) DO INC (start) END;
          
          IF (file # NIL) THEN             (* in incomplete multipart yenc *)
            IF ~HeadersMatch (oldHeader, yencHeader) THEN
              EndFile(FALSE);
              RETURN start;
            ELSIF (yencHeader.part # oldHeader.part+1) THEN
              Log.String("error", "part number mismatch in yenc multipart");
              EndFile(FALSE);
              RETURN start;
            END;
          ELSIF (yencHeader.part >= 0) & (yencHeader.part # 1) THEN
            Log.String("error", "beginning of yenc multipart is not part 1");
            RETURN start;
          END;
          
          Log.LongInt ("yenc part", yencHeader.part);
          Log.LongInt ("yenc line", yencHeader.line);
          Log.LongInt ("yenc size", yencHeader.size);
          Log.String ("yenc filename", yencHeader.fileName);
          
          IF (yencHeader.part > 0) THEN
            state := ProcessPartHeaderYEnc;
            RETURN start;
          ELSE
            decoder := codecYEnc.NewDecoder();
            decoder.Start;
            state := ProcessDataYEnc;
            IF (file = NIL) THEN (* first part of single of multipart yenc *)
              StartFile(codecYEnc, yencHeader.fileName);
            END;
            
            RETURN start;
          END;
        ELSE
          WHILE (start # end) & ~UU.IsEOL (data[start])  DO
            INC (start);
          END;
          WHILE (start # end) & UU.IsEOL (data[start])  DO
            INC (start);
          END;
        END;
      END;
    END;
    RETURN start;
  END SearchForFile;

PROCEDURE DecodeFiles (r: Channel.Reader);
  VAR
    d: ARRAY sizeBuffer OF CHAR;
    start, end, endOfData: LONGINT;
    done: BOOLEAN;
    
  PROCEDURE ReadBlock;
    VAR
      len: LONGINT;
    BEGIN
      len := sizeBuffer-endOfData;
      r. ReadBytes (d, endOfData, len);
      done := (r. bytesRead # len);
      INC (endOfData, r. bytesRead);
      IF done THEN (* add eol to make sure that all lines are complete *)
        d[endOfData] := Ascii.lf;
        INC (endOfData);
      END;

      start := 0;
      end := endOfData;
      WHILE (end # start) & ~UU.IsEOL(d[end-1]) DO
        DEC (end);
      END;
    END ReadBlock;
  
  BEGIN
    start := 0; end := 0; endOfData := 0;
    done := FALSE;
    ReadBlock;
    outputBuffer := StringBuffer.NewCapacity(sizeBuffer);
    state := SearchForFile;
    
    LOOP
      WHILE (start < end) DO
        start := state(d, start, end);
      END;

      IF done THEN
        IF (state # SearchForFile) THEN
          Log.String("error", "end of input stream");
          EndFile(FALSE);
        END;
        EXIT;
      ELSIF (endOfData-start <= start) THEN
        SYSTEM.MOVE (SYSTEM.ADR (d[start]), SYSTEM.ADR (d), endOfData-start);
        DEC (endOfData, start);
        ReadBlock;
      ELSE
        Log.String ("Error", "Line too long"); HALT (1);
      END;
    END;
  END DecodeFiles;

PROCEDURE Encode (enc: Codec.Encoder; r: Channel.Reader; w: Channel.Writer);
  VAR
    d: ARRAY sizeBuffer OF CHAR;
    b: StringBuffer.StringBuffer;
    s: Object.String;
    c: StringBuffer.CharsLatin1;
  BEGIN
    b := StringBuffer.NewCapacity (sizeBuffer+256);
    LOOP
      r.ReadBytes (d, 0, sizeBuffer);
      IF (r.bytesRead = 0) THEN
        EXIT;
      ELSE
        s := Object.NewLatin1Region (d, 0, r.bytesRead);
        enc.Encode (s, 0, r.bytesRead, b);
        
        c := b.CharsLatin1();
        w.WriteBytes(c^, 0, b.length);
        b.Clear;
      END;
    END;
    enc.Closure(b);
    c := b.CharsLatin1();
    w.WriteBytes(c^, 0, b.length);
  END Encode;

PROCEDURE Decode (dec: Codec.Decoder; r: Channel.Reader; w: Channel.Writer);
  VAR
    d: ARRAY sizeBuffer OF CHAR;
    b: StringBuffer.StringBuffer;
    s: Object.String;
    c: StringBuffer.CharsLatin1;
  BEGIN
    b := StringBuffer.NewCapacity (sizeBuffer+256);
    LOOP
      r.ReadBytes (d, 0, sizeBuffer);
      IF (r.bytesRead = 0) THEN
        EXIT;
      ELSE
        s := Object.NewLatin1Region (d, 0, r.bytesRead);
        dec.Decode (d, 0, r.bytesRead, b);
        
        c := b.CharsLatin1();
        w.WriteBytes(c^, 0, b.length);
        b.Clear;
      END;
    END;
    c := b.CharsLatin1();
    w.WriteBytes(c^, 0, b.length);
  END Decode;

PROCEDURE ParseArguments (r: TextRider.Reader);
  VAR
    arg: ARRAY 256 OF CHAR;

  PROCEDURE GetCodec (name: STRING): Codec.Codec;
    VAR
      c: Codec.Codec;
    BEGIN
      c := Codec.Get (name);
      IF (c = NIL) THEN
        Log.Str ("No such codec", name);
        HALT(1);
      END;
      RETURN c;
    END GetCodec;
  
    BEGIN
    r. ReadLine (arg);

    LOOP
      r. ReadLine (arg);
      IF (r. res # TextRider.done) THEN
        EXIT;
      ELSE
        IF (arg = "--encode") THEN
          mode := encode;
          r. ReadLine (arg);
          codec1 := GetCodec (Object.NewLatin1(arg));
        ELSIF (arg = "--decode") THEN
          mode := decode;
          r. ReadLine (arg);
          codec1 := GetCodec (Object.NewLatin1(arg));
        ELSIF (arg = "--decode-files") THEN
          mode := decodeFiles;
        ELSIF (arg = "--key") THEN
          r. ReadLine (arg);
          key := Object.NewLatin1(arg);
        ELSE
          Log.String ("Unknown argument", arg);
          HALT (1);
        END;
      END;
    END;
  END ParseArguments;

BEGIN
  Latin1.Register;                       (* unicode: latin1 *)
  UTF32.Register;                        (* unicode: utf-32 *)
  UU.Register;                           (* transport: uuencode *)
  YEnc.Register;                         (* transport: yencode *)
  Twofish.Register;                      (* encryption: twofish *)
  Deflate.Register;                      (* compression: zlib's deflate *)
  
  codecUU := UU.uu;
  codecYEnc := YEnc.yenc;
  key := NIL;
  ParseArguments (TextRider.ConnectReader(ProgramArgs.args));
  
  r := StdChannels.stdin.NewReader();
  w := StdChannels.stdout.NewWriter();
  file := NIL;
  CASE mode OF
  | encode:
    enc := codec1.NewEncoder();
    WITH enc: Codec.CryptoEncoder DO
      enc.SetKey(key(Object.String8));
    ELSE
    END;
    enc.Start;
    Encode (enc, r, w);
    enc.End;
  | decode:
    dec := codec1.NewDecoder();
    WITH dec: Codec.CryptoDecoder DO
      dec.SetKey(key(Object.String8));
    ELSE
    END;
    dec.Start;
    Decode (dec, r, w);
    dec.End;
  | decodeFiles:
    w := NIL;
    DecodeFiles (r);
  END;
END encdec.
