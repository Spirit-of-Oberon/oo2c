MODULE Generic2;

IMPORT
  G := Generic1;

TYPE
  Array1(E: G.Object) = ARRAY 256 OF E;
  Array2(E: G.Object) = POINTER TO ARRAY OF E;

VAR
  a-: Array1(G.A1);
  b-: Array2(G.Object);
  
END Generic2.
