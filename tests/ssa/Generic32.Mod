MODULE Generic32;

IMPORT G:=Generic1;

TYPE
  A*(T: G.Object) = RECORD
  END;
  B*(T: G.Object) = RECORD
    (A(T))
  END;

VAR
  ar: A(G.Object);
  br: B(G.Object);
  
PROCEDURE (VAR a: A(T)) ProcA*(arg: T);
  BEGIN
  END ProcA;

PROCEDURE (VAR b: B(T)) ProcB*(arg: T);
  BEGIN
  END ProcB;

PROCEDURE P*(o1: G.Object; a1: G.A1);
  BEGIN
    ar.ProcA(o1);
    ar.ProcA(a1);

    br.ProcB(o1);
    br.ProcB(a1);
    
    br.ProcA(o1);
    br.ProcA(a1);
  END P;

END Generic32.
