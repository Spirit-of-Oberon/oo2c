MODULE Generic9;

IMPORT G := Generic1;
  
TYPE
  R*(B: G.Object) = RECORD x-: B END;

VAR
  x*: R();

END Generic9.
