MODULE OOC:Scanner:Integer;

IMPORT
  Strings, IntStr, Msg, OOC:Error, OOC:Scanner:InputBuffer;


TYPE
  Integer* = LONGINT;
  
CONST
  outOfRange = 1;
  negativeHexConst = 2;
  
TYPE
  ErrorContext = POINTER TO ErrorContextDesc;
  ErrorContextDesc = RECORD  (* stateless *)
    (Error.ContextDesc)
  END;

VAR
  integerContext: ErrorContext;


PROCEDURE (context: ErrorContext) GetTemplate* (msg: Error.Msg; VAR templ: Error.LString);
  VAR
    t: ARRAY 128 OF Error.LChar;
  BEGIN
    CASE msg. code OF
    | outOfRange:
      t := "Integer value out of range"
    | negativeHexConst:
      t := "Hexadecimal constant would be mapped to negative value"
    END;
    context. BaseTemplate (msg, t, templ)
  END GetTemplate;


PROCEDURE Convert10* (str: InputBuffer.CharArray; VAR int: Integer): Msg.Msg;
  VAR
    format: IntStr.ConvResults;
  BEGIN
    IntStr.StrToInt (str^, int, format);
    IF (format = IntStr.strOutOfRange) THEN
      int := 1; 
      RETURN Error.New (integerContext, outOfRange)
    ELSE
      RETURN NIL
    END
  END Convert10;

PROCEDURE Convert16* (str: InputBuffer.CharArray; VAR int: Integer): Msg.Msg;
  VAR
    spos, epos: LONGINT;

  PROCEDURE GetDigit (c: CHAR): INTEGER;
    VAR
      d: INTEGER;
    BEGIN
      d:=ORD(c);
      IF (ORD ("0") <= d) & (d <= ORD ("9")) THEN
        DEC (d, ORD ("0"))
      ELSE  (* (ORD ("A") <= d) & (d <= ORD ("F")) *)
        (* the explicit test can be omitted, since this procedure is only 
           called for numbers that match [0-9A-F]+  *)
        DEC (d, ORD ("A")-10)
      END;
      RETURN d
    END GetDigit;

  BEGIN
    spos := 0; epos := Strings.Length (str^);
    
    int := 0;
    (* skip leading zeros *)
    WHILE (str[spos] = "0") DO 
      INC (spos)
    END;
    IF (epos-spos > 7) THEN  (* value has more than 8 significant digits *)
      int := 1;
      RETURN Error.New (integerContext, outOfRange) (* number out of range *)
    ELSIF (spos <= epos) THEN         (* if any non-zero digits follow *)
      int := GetDigit (str[spos]);
      INC (spos);
      IF (epos-spos = 6) & (int >= 8) THEN
        (* value is beyond MAX(LONGINT)=07FFFFFFFH: correct this by sub-
           tracting 16 from the value of the most significant digit, creating
           the negative number that matches the two's complement bit pattern *)
        RETURN Error.New (integerContext, negativeHexConst);
        (* ... fixme: the above should be a warning *)
        (*DEC (int, 10H)   map to negative number *)
      END;
      WHILE (spos <= epos) DO
        int := int*10H + GetDigit (str[spos]);
        INC (spos)
      END
    (* ELSE: number is non-empty sequence of "0", keep int=0 *)
    END;
    RETURN NIL
  END Convert16;

BEGIN
  NEW (integerContext);
  Error.InitContext (integerContext, "OOC:Scanner:Integer")
END OOC:Scanner:Integer.
