MODULE OpPointer7;

TYPE
  B = POINTER TO BDesc;
  BDesc = RECORD END;

PROCEDURE (b : B)  P;
BEGIN
  b.P^();
END P;

END OpPointer7.
