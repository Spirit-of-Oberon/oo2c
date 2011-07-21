MODULE New8;

TYPE
  Alp = POINTER TO AlpDesc;
  AlpDesc = RECORD
  END;

PROCEDURE (self: Alp) GetVal(): LONGINT;
BEGIN
  RETURN 0;
END GetVal;

PROCEDURE DoTest;
VAR
  v: LONGINT;
BEGIN
  v := NEW(Alp).GetVal();
END DoTest;

END New8.
