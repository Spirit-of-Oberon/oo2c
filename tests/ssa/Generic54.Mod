MODULE Generic54;

IMPORT G:=Generic1;

TYPE
  A*(T1, T2: G.Object) = POINTER TO ADesc(T1, T2);
  ADesc*(T1, T2: G.Object) = RECORD
    f1-: T1;
    f2-: T2;
  END;

PROCEDURE (a: A) ProcA*();
  END ProcA;

END Generic54.
