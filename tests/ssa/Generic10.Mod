MODULE Generic10;

IMPORT G := Generic1;
  
TYPE
  R*(B: G.Object) = RECORD x-: B END;

VAR
  x*: R(G.Object, G.Object);

END Generic10.
