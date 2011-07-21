MODULE OpPointer2;

TYPE

  A = POINTER TO ADesc;
  ADesc = RECORD END;

  B = POINTER TO BDesc;
  BDesc = RECORD (ADesc) END;

PROCEDURE (b : B)  P;
BEGIN
  b.P^();
END P;

END OpPointer2.
