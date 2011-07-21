MODULE Generic31;

IMPORT G:=Generic1;

TYPE
  A*(T: G.Object) = POINTER TO ADesc(T);
  ADesc*(T: G.Object) = RECORD
  END;
  B*(T: G.Object) = POINTER TO BDesc(T);
  BDesc*(T: G.Object) = RECORD
    (ADesc(T))
  END;

VAR
  bp: B(G.A1);
  
PROCEDURE (a: A(T)) ProcA*(arg: T);
  BEGIN
  END ProcA;

PROCEDURE P*(o1: G.Object);
  BEGIN
    bp.ProcA(o1);
  END P;

END Generic31.
