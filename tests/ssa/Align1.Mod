MODULE Align1;

IMPORT SYSTEM, Out:=Out0;

TYPE
  T = RECORD 
    a : CHAR;
    b : LONGREAL;
  END;

  TUnion = RECORD [UNION]
    a : CHAR;
    b : LONGREAL;
  END;

  T1 = RECORD [ALIGN1]
    a : CHAR;
    b : LONGREAL;
  END;

  T2 = RECORD [ALIGN2]
    a : CHAR;
    b : LONGREAL;
  END;

  T4 = RECORD [ALIGN4]
    a : CHAR;
    b : LONGREAL;
  END;

  T8 = RECORD [ALIGN8]
    a : CHAR;
    b : LONGREAL;
  END;

PROCEDURE Test*;
VAR
  t : T;
  tUnion : TUnion;
  t1 : T1;
  t2 : T2;
  t4 : T4;
  t8 : T8;
BEGIN  (* note: Out.Int() does not work with 64 bit addresses *)
  Out.Int(SYSTEM.ADR(t.b) - SYSTEM.ADR(t.a), 0); Out.Ln;
  Out.Int(SYSTEM.ADR(tUnion.b) - SYSTEM.ADR(tUnion.a), 0); Out.Ln;
  Out.Int(SYSTEM.ADR(t1.b) - SYSTEM.ADR(t1.a), 0); Out.Ln;
  Out.Int(SYSTEM.ADR(t2.b) - SYSTEM.ADR(t2.a), 0); Out.Ln;
  Out.Int(SYSTEM.ADR(t4.b) - SYSTEM.ADR(t4.a), 0); Out.Ln;
  Out.Int(SYSTEM.ADR(t8.b) - SYSTEM.ADR(t8.a), 0); Out.Ln;
END Test;

END Align1.
