MODULE Generic36;

IMPORT G:=Generic1;

TYPE
  A*(T: G.Object) = POINTER TO ADesc(T);
  ADesc*(T: G.Object) = RECORD
    x: T;
  END;
  B*(T: G.Object) = POINTER TO BDesc(T);
  BDesc*(T: G.Object) = RECORD
    (ADesc(T))
  END;

VAR
  ap: A;
  bp: B;
  
PROCEDURE ProcA*(arg: G.Object);
  BEGIN
  END ProcA;

PROCEDURE P*(o1: G.Object);
  BEGIN
    ProcA(ap.x);
    ProcA(bp.x);

    ap.x := o1;
    bp.x := o1;
  END P;

END Generic36.
