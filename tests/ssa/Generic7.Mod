MODULE Generic7;

IMPORT G := Generic1;
  
TYPE
  R1(B: G.Object) = RECORD END;
  R2(C: G.A1) = RECORD (R1(C)) x: B END;

END Generic7.
