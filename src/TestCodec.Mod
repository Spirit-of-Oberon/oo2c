MODULE TestCodec;

IMPORT
  Log, Channel, ProgramArgs, StdChannels, BinaryRider, TextRider,
  RandomNumbers, Object, ADT:StringBuffer, Codec;

CONST
  charProducer = "producer";
  charConsumer = "consumer";
  recode = "recode";
  
VAR
  command: ARRAY 128 OF CHAR;
  codec1, codec2: Codec.Codec;
  charGen: BOOLEAN;
  repeatCount: LONGINT;
  range: ARRAY 128 OF RECORD start, end, count: LONGINT; END;
  maxValue: LONGINT;
  rangeCount: LONGINT;
  totalChars: LONGINT;
  data32: POINTER TO ARRAY OF UCS4CHAR;
  
PROCEDURE ParseArgs ();
  VAR
    i, start: LONGINT;
    r: TextRider.Reader;
    exec: ARRAY 128 OF CHAR;

  PROCEDURE ReadCodec (): Codec.Codec;
    VAR
      name: ARRAY 128 OF CHAR;
      c: Codec.Codec;
    BEGIN
      r. ReadLine (name);
      c := Codec.Get (Object.NewLatin1(name));
      IF (c = NIL) THEN
        Log.String ("no such codec", name);
        HALT(1);
      END;
      RETURN c;
    END ReadCodec;
  
  BEGIN
    r := TextRider.ConnectReader(ProgramArgs.args);
    r. ReadLine (exec);
    r. ReadLine (command);
    IF (r. res # ProgramArgs.done) THEN
      Log.String ("usage", "TestCodec (producer|consumer) <codec> <repeat> {<char-bound> <char-repeat>}...");
    ELSE
      codec1 := ReadCodec();
      charGen := (command = charProducer) OR (command = charConsumer);
      maxValue := -1;
      rangeCount := 0;
      totalChars := 0;
      
      IF charGen THEN
        r. ReadLInt (repeatCount);
        
        i := 0;
        start := 0;
        WHILE (r. res = ProgramArgs.done) DO
          range[i]. start := start;
          r. ReadLInt (range[i]. end);
          IF (r. res = ProgramArgs.done) THEN
            ASSERT (range[i]. start <= range[i]. end);
            r. ReadLInt (range[i]. count);
            INC (totalChars, range[i]. count);
            start := range[i]. end+1;
            maxValue := start;
            INC (i);
          END;
        END;
        rangeCount := i;

      ELSIF (command = recode) THEN
        codec2 := ReadCodec();
      END;
    END;
  END ParseArgs;

PROCEDURE ProduceChars ();
  VAR
    i, j, r: LONGINT;
    h: UCS4CHAR;
  BEGIN
    NEW (data32, totalChars);
    i := 0;
    FOR r := 0 TO rangeCount-1 DO
      FOR j := 0 TO range[r]. count-1 DO
        data32[i] := UCS4CHR(RandomNumbers.RND(range[r]. end-range[r]. start)+range[r]. start);
        INC (i);
      END;
    END;
    FOR i := 0 TO totalChars-1 DO
      j := RandomNumbers.RND(totalChars-i)+i;
      h := data32[i]; data32[i] := data32[j]; data32[j] := h;
    END;
  END ProduceChars;

PROCEDURE WriteChars ();
  VAR
    w: BinaryRider.Writer;
    b: StringBuffer.StringBuffer;
    s: Object.String;
    d: StringBuffer.CharsLatin1;
    start, end, repeat: LONGINT;
    enc: Codec.Encoder;
  BEGIN
    Log.Msg ("  writing data");
    w := BinaryRider.ConnectWriter (StdChannels.stdout);
    b := StringBuffer.NewCapacity(4*1024);
    s := Object.NewUCS4Region(data32^, 0, totalChars);
    enc := codec1. NewEncoder();
    FOR repeat := 1 TO repeatCount DO
      start := 0;
      WHILE (start # s. length) DO
        end := start + 2*1024;
        IF (end > s. length) THEN end := s. length; END;
        
        enc. Encode (s, start, end, b);
        d := b. CharsLatin1();
        w. WriteBytes (d^, 0, b. length);
        
        b. Clear();
        start := end;
      END;
    END;
  END WriteChars;

PROCEDURE ReadChars ();
  CONST
    sizeBuffer = 8*1024;
  VAR
    r: Channel.Reader;
    b: StringBuffer.StringBuffer;
    d: ARRAY 8*1024 OF CHAR;
    dec: Codec.Decoder;
    totalRead, offset: LONGINT;
    
  PROCEDURE ProcessChunk ();
    VAR
      i: LONGINT;
      s: Object.String;
    BEGIN
      r. ReadBytes (d, 0, sizeBuffer);
      dec. Decode (d, 0, r. bytesRead, b);
      INC (totalRead, b. length);

      s := b. ToString();
      FOR i := 0 TO s. length-1 DO
        ASSERT (s. CharAt(i) = data32[offset], 11);
        INC (offset);
        IF (offset = totalChars) THEN
          offset := 0;
        END;
      END;
      b. Clear;
    END ProcessChunk;
  
  BEGIN
    Log.Msg ("  reading data");
    r := StdChannels.stdin. NewReader();
    b := StringBuffer.NewCapacity(4*1024);
    totalRead := 0;
    offset := 0;
    dec := codec1. NewDecoder();
    ProcessChunk;
    WHILE (r. res = Channel.done) DO
      ProcessChunk;
    END;

    ASSERT (totalRead = totalChars*repeatCount, 10);
    Log.Msg ("  length of input matches expected length");
  END ReadChars;

PROCEDURE RecodeChars ();
  CONST
    sizeBuffer = 8*1024;
  VAR
    r: Channel.Reader;
    w: Channel.Writer;
    b1, b2: StringBuffer.StringBuffer;
    d: ARRAY 8*1024 OF CHAR;
    dec: Codec.Decoder;
    enc: Codec.Encoder;
    
  PROCEDURE ProcessChunk ();
    VAR
      s: Object.String;
      bytes: StringBuffer.CharsLatin1;
    BEGIN
      r. ReadBytes (d, 0, sizeBuffer);
      dec. Decode (d, 0, r. bytesRead, b1);
      s := b1. ToString();
      b1. Clear;
      
      enc. Encode (s, 0, s. length, b2);
      bytes := b2. CharsLatin1();
      w. WriteBytes (bytes^, 0, b2. length);
      b2. Clear;
    END ProcessChunk;
  
  BEGIN
    Log.Msg ("  recoding data");
    r := StdChannels.stdin. NewReader();
    w := StdChannels.stdout. NewWriter();
    b1 := StringBuffer.NewCapacity(4*1024);
    b2 := StringBuffer.NewCapacity(4*1024);
    
    dec := codec1. NewDecoder();
    enc := codec2. NewEncoder();
    
    ProcessChunk;
    WHILE (r. res = Channel.done) DO
      ProcessChunk;
    END;
  END RecodeChars;

BEGIN
  ParseArgs;
  Log.String ("command", command);
  IF charGen THEN
    Log.Msg ("  generating random characters");
    ProduceChars;

    IF (command = charProducer) THEN
      WriteChars;
    ELSIF (command = charConsumer) THEN
      ReadChars;
    END;
  ELSIF (command = recode) THEN
    RecodeChars;
  ELSE
    Log.String ("unknown command", command);
    HALT(1);
  END;
END TestCodec.
