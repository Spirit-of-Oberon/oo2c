MODULE Generic30;

IMPORT G:=Generic1;

TYPE
  A*(T: G.Object) = POINTER TO ADesc(T);
  ADesc*(T: G.Object) = RECORD
  END;

VAR
  ap: A(G.A1);
  
PROCEDURE (a: A(T)) ProcA*(arg: T);
  BEGIN
  END ProcA;

PROCEDURE P*(o1: G.Object);
  BEGIN
    ap.ProcA(o1);
  END P;

END Generic30.
