MODULE H2O:Value;

(* This module provides representations for basic scalar types involved in "C"
expressions. In most cases, these are simlar to the corresponding types
defined in Object:Boxed. However, in some cases additional information is
maintained to improve the translation of constants. *)

IMPORT Object:Boxed, ADT:StringBuffer;

TYPE
  Object* = Boxed.Object;

TYPE
  String* = Boxed.String;

TYPE
  LongReal* = Boxed.LongReal;

TYPE 
  Boolean* = Boxed.Boolean;

TYPE
  LongInt* = POINTER TO LongIntDesc;
  LongIntDesc* = RECORD (Boxed.LongIntDesc)
    radix- : INTEGER;
    size- : INTEGER;
  END;

VAR
  zeroLongInt- : LongInt;

PROCEDURE NewLongIntSize* (value : LONGINT; radix, size : INTEGER) : LongInt;
VAR i : LongInt;
BEGIN
  NEW(i);
  i.INIT(value);
  i.radix := radix;
  i.size := size;
  RETURN i;
END NewLongIntSize;

PROCEDURE NewLongInt* (value : LONGINT) : LongInt;
BEGIN
  RETURN NewLongIntSize(value, 10, -1);
END NewLongInt;

PROCEDURE ToBase(value, radix, length : LONGINT; withSign : BOOLEAN) : STRING;
VAR
  digits : ARRAY 32 OF CHAR;
  pos : INTEGER;
  b : StringBuffer.StringBuffer;

  PROCEDURE Digit(value : LONGINT) : CHAR;
  BEGIN
    IF value < 10 THEN
      RETURN CHR(value + ORD('0'))
    ELSE
      RETURN CHR(value + ORD('A')-10);
    END
  END Digit;

BEGIN
  pos := 0;
  b := StringBuffer.New("");
  IF withSign & (value < 0) THEN
    b.AppendLatin1Char("-");
    value := -value;
  END;

  WHILE value # 0 DO
    digits[pos] := Digit(value MOD radix);
    value := value DIV radix;
    INC(pos);
  END;
  WHILE length > pos DO
    b.AppendLatin1Char('0'); DEC(length);
  END;
  WHILE pos > 0 DO
    DEC(pos);
    b.AppendLatin1Char(digits[pos]);
  END;
  IF radix = 16 THEN b.AppendLatin1Char('H') END;
  RETURN b.ToString();
END ToBase;

PROCEDURE (i : LongInt) ToString* () : STRING;
BEGIN
  RETURN ToBase(i.value, i.radix, i.size, (i.radix = 10));
END ToString;

PROCEDURE NewLongReal* (value : LONGREAL) : LongReal;
BEGIN
  RETURN NEW(LongReal, value);
END NewLongReal;

PROCEDURE NewString* (value : STRING) : String;
BEGIN
  RETURN NEW(String, value);
END NewString;

BEGIN
  zeroLongInt := NewLongInt(0);
END H2O:Value.
