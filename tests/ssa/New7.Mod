MODULE New7;
<*Assertions:=TRUE*>

TYPE
  P = POINTER TO ARRAY OF CHAR;

PROCEDURE F(n: LONGINT): P;
  VAR
    p: P;
  BEGIN
    NEW(p,n);
    RETURN p;
  END F;

PROCEDURE Test*;
  BEGIN
    ASSERT(F(-1) # NIL);
  END Test;

END New7.
