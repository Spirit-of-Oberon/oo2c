MODULE Generic15;

IMPORT G:=Generic1;
  
TYPE
  R1*(B: G.Object) = RECORD END;
  R2*(D: G.Object) = RECORD (R1(D)) END;

PROCEDURE (VAR r: R2(X)) F*(x: R2.D);
  BEGIN
  END F;

END Generic15.
