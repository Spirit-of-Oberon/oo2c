MODULE Generic12;

IMPORT G := Generic1;
  
TYPE
  R1*(B: G.A1) = RECORD x*: B END;
  R2*(C: G.Object) = RECORD (R1(C)) END;

END Generic12.
