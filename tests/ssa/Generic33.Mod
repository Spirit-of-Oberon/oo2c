MODULE Generic33;

IMPORT G:=Generic1;

TYPE
  A*(T: G.Object) = RECORD
  END;

VAR
  ar: A(G.A1);
  
PROCEDURE (VAR a: A(T)) ProcA*(arg: T);
  BEGIN
  END ProcA;

PROCEDURE P*(o1: G.Object; a1: G.A1);
  BEGIN
    ar.ProcA(o1);
  END P;

END Generic33.
