MODULE Generic53;

IMPORT G:=Generic1;

TYPE
  A*(T1, T2: G.Object) = POINTER TO ADesc(T1, T2);
  ADesc*(T1, T2: G.Object) = RECORD
    f1: T1;
    f2: T2;
  END;

PROCEDURE ^ (a: A(Y1,Y2)) ProcA*(arg1: Y1; arg2: Y2);

PROCEDURE (a: A(X1,X2)) ProcA*(arg1: X1; arg2: X2);
  VAR
    v1: X1;
    v2: X2;
  BEGIN
    v1 := arg1;
    v2 := arg2;
    
    a.f1 := arg1;
    a.f2 := arg2;

    a.f1 := v1;
    a.f2 := v2;
  END ProcA;

END Generic53.
