MODULE Generic3;

IMPORT
  G := Generic1;

TYPE
  R1(A,B: G.A1) = RECORD a*: A; b*: B; END;
  R2(A: G.A1; B: G.A2) = RECORD a*: A; b*: B; END;
  R3() = RECORD END;
  
VAR
  r1-: R1(G.A1, G.A2);
  r2-: R2(G.A1, G.A2);
  r3-: R3();
  
END Generic3.
