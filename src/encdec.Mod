MODULE encdec;

IMPORT
  SYSTEM, Ascii, Channel, Files, Log, ProgramArgs, StdChannels, TextRider, 
  String := Language:String0, Codec,
  Codec:Latin1, Codec:UTF32, Codec:UU, Codec:Twofish, Codec:Deflate;

TYPE
  State = PROCEDURE (VAR data: ARRAY OF CHAR; start, end: LONGINT): LONGINT;
  (* Process `data' starting at `start', and stop when reaching `end'.  Result
     is the position of the first character of the line that is not processed
     by this state.

     side-effect: The global variable `state' is changed to the next state
     processor.
     
     precond: start<end & IsEOL(data[end-1]) *)

CONST
  sizeBuffer = 8*1024;
  encode = 0;
  decode = 1;
  decodeFiles = 2;
  
VAR
  mode: SHORTINT;
  codec1: Codec.Codec;
  key: String.String;
  
  codecUU: Codec.Codec;
  decoder: Codec.Decoder;
  outputBuffer: String.Buffer;
  state: State;
  
  enc: Codec.Encoder;
  dec: Codec.Decoder;
  r: Channel.Reader;
  w: Channel.Writer;
  
PROCEDURE ^ SearchForFile (VAR data: ARRAY OF CHAR; start, end: LONGINT): LONGINT;

PROCEDURE ProcessDataUU (VAR data: ARRAY OF CHAR; start, end: LONGINT): LONGINT;
  VAR
    eol, startOfData, endOfData, lines: LONGINT;
    chars: String.CharsLatin1;
  BEGIN
    lines := 0;
    startOfData := start;
    LOOP
      eol := UU.LineData (data, start, end);
      IF (eol >= 0) THEN
        start := eol;
        WHILE (start # end) & UU.IsEOL (data[start]) DO INC (start) END;
        INC (lines);
      ELSE
        endOfData := start;
        eol := UU.LineEnd (data, start, end);
        IF (eol >= 0) THEN
          Log.LongInt ("lines before end", lines);
          start := eol;
          WHILE (start # end) & UU.IsEOL (data[start]) DO INC (start) END;
          state := SearchForFile;
        ELSE
          Log.LongInt ("lines before junk", lines);
(*          state := SkipJunkUU;*)
          state := SearchForFile;
        END;
        EXIT;
      END;

      IF (start = end) THEN
        Log.LongInt ("lines before end of block", lines);
        endOfData := start;
        EXIT
      END;
    END;

    decoder. Decode (data, startOfData, endOfData, outputBuffer);

    IF (outputBuffer. length >= sizeBuffer DIV 2) THEN
      chars := outputBuffer.CharsLatin1();
      w.WriteBytes(chars^, 0, outputBuffer.length);
    END;

    RETURN start;
  END ProcessDataUU;

PROCEDURE SearchForFile (VAR data: ARRAY OF CHAR; start, end: LONGINT): LONGINT;
  VAR
    eol: LONGINT;
    header: UU.Header;
  BEGIN
    WHILE (start < end) DO
      eol := UU.LineBegin (data, start, end, header);
      IF (eol >= 0) THEN
        start := eol;
        WHILE (start # end) & UU.IsEOL (data[start]) DO INC (start) END;
        decoder := codecUU.NewDecoder();
        state := ProcessDataUU;
        Log.LongInt ("uu mode", header. fileMode);
        Log.String ("uu filename", header. fileName);
        RETURN start;
      ELSE
        WHILE (start # end) & ~UU.IsEOL (data[start])  DO
          INC (start);
        END;
        WHILE (start # end) & UU.IsEOL (data[start])  DO
          INC (start);
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
    outputBuffer := String.NewBuffer(sizeBuffer);
    state := SearchForFile;
    
    LOOP
      WHILE (start < end) DO
        start := state(d, start, end);
      END;

      IF done THEN
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
    b: String.Buffer;
    s: String.String;
    c: String.CharsLatin1;
  BEGIN
    b := String.NewBuffer (sizeBuffer+256);
    LOOP
      r.ReadBytes (d, 0, sizeBuffer);
      IF (r.bytesRead = 0) THEN
        EXIT;
      ELSE
        s := String.NewLatin1Region (d, 0, r.bytesRead);
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
    b: String.Buffer;
    s: String.String;
    c: String.CharsLatin1;
  BEGIN
    b := String.NewBuffer (sizeBuffer+256);
    LOOP
      r.ReadBytes (d, 0, sizeBuffer);
      IF (r.bytesRead = 0) THEN
        EXIT;
      ELSE
        s := String.NewLatin1Region (d, 0, r.bytesRead);
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

  PROCEDURE GetCodec (name: ARRAY OF CHAR): Codec.Codec;
    VAR
      c: Codec.Codec;
    BEGIN
      c := Codec.Get (name);
      IF (c = NIL) THEN
        Log.String ("No such codec", name);
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
          codec1 := GetCodec (arg);
        ELSIF (arg = "--decode") THEN
          mode := decode;
          r. ReadLine (arg);
          codec1 := GetCodec (arg);
        ELSIF (arg = "--decode-files") THEN
          mode := decodeFiles;
        ELSIF (arg = "--key") THEN
          r. ReadLine (arg);
          key := String.NewLatin1(arg);
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
  Twofish.Register;                      (* encryption: twofish *)
  Deflate.Register;                      (* compression: zlib's deflate *)
  
  codecUU := UU.uu;
  key := NIL;
  ParseArguments (TextRider.ConnectReader(ProgramArgs.args));
  
  r := StdChannels.stdin.NewReader();
  w := StdChannels.stdout.NewWriter();
  CASE mode OF
  | encode:
    enc := codec1.NewEncoder();
    WITH enc: Codec.CryptoEncoder DO
      enc.SetKey(key(String.String8));
    ELSE
    END;
    enc.Start;
    Encode (enc, r, w);
    enc.End;
  | decode:
    dec := codec1.NewDecoder();
    WITH dec: Codec.CryptoDecoder DO
      dec.SetKey(key(String.String8));
    ELSE
    END;
    dec.Start;
    Decode (dec, r, w);
    dec.End;
  | decodeFiles:
    DecodeFiles (r);
  END;
END encdec.
