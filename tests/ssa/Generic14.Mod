MODULE Generic14;

IMPORT G:=Generic1;
  
TYPE
  P*(A: G.Object) = POINTER TO R(A);
  R*(B: G.Object) = RECORD END;

PROCEDURE (p: P(B)) F*(x: A);
  BEGIN
  END F;

END Generic14.
