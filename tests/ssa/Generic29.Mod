MODULE Generic29;

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
  ap: A(G.Object);
  bp: B(G.Object);
  
PROCEDURE (a: A(T)) ProcA*(arg: T);
  BEGIN
  END ProcA;

PROCEDURE (b: B(T)) ProcB*(arg: T);
  BEGIN
  END ProcB;

PROCEDURE P*(o1: G.Object; a1: G.A1);
  BEGIN
    ap.ProcA(o1);
    ap.ProcA(a1);

    bp.ProcB(o1);
    bp.ProcB(a1);
    
    bp.ProcA(o1);
    bp.ProcA(a1);
  END P;

END Generic29.
