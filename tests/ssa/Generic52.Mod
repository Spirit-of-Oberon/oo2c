MODULE Generic52;

IMPORT SYSTEM, G:=Generic1;

TYPE
  A*(T: G.Object) = POINTER TO ADesc(T);
  ADesc*(T: G.Object) = RECORD
  END;

PROCEDURE (a: A(T)) ProcA*(arg1: T; arg2: A(G.Object));
  VAR
    ptr: SYSTEM.PTR;
  BEGIN
    ptr := arg1;
    ptr := arg2;
  END ProcA;

END Generic52.
