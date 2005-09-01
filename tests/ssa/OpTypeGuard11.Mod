MODULE OpTypeGuard11;

IMPORT Out:=Out0;

TYPE
   T0 = POINTER TO T0Desc;
   T0Desc = RECORD x: LONGINT END;

   T1 = POINTER TO T1Desc;
   T1Desc = RECORD (T0Desc) y: LONGINT END;

   T2 = POINTER TO T2Desc;
   T2Desc = RECORD (T1Desc) z: LONGINT END;

VAR
   t0: T0;
   t2: T2;

BEGIN
   NEW(t2);
   t0 := t2;
   Out.Int(t0(T1)(T2).z, 0);
   Out.Ln
END OpTypeGuard11.
