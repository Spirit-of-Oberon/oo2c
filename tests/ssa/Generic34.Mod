MODULE Generic34;

IMPORT G:=Generic1;

TYPE
  A*(T: G.Object) = RECORD
  END;
  B*(T: G.Object) = RECORD
    (A(T))
  END;

VAR
  br: B(G.A1);
  
PROCEDURE (VAR a: A(T)) ProcA*(arg: T);
  BEGIN
  END ProcA;

PROCEDURE P*(o1: G.Object);
  BEGIN
    br.ProcA(o1);
  END P;

END Generic34.
