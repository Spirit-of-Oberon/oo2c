MODULE Generic11;

IMPORT G := Generic1;
  
TYPE
  R*(B: G.A1) = RECORD x*: B END;

VAR
  x*: R(G.Object);

END Generic11.
