MODULE Generic14;

IMPORT G:=Generic1;
  
TYPE
  P*(A: G.Object) = POINTER TO R(A);
  R*(B: G.Object) = RECORD END;

PROCEDURE (p: P) F*(x: P.B);
  BEGIN
  END F;

END Generic14.
