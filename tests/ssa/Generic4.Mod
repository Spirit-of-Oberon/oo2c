MODULE Generic4;

IMPORT
  G := Generic1;

TYPE
  R1(A: G.Object) = RECORD x*: A END;
  R2(A, B: G.Object) = RECORD (R1(A)) y*: B END;
  
VAR
  r2-: R2(G.A1, G.A2);
  
END Generic4.
