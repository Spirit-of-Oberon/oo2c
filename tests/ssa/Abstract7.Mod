MODULE Abstract7;

TYPE
  R0 = RECORD [ABSTRACT] END;
  P0 = POINTER TO R0;
  R1 = RECORD (R0) END;
  P1 = POINTER TO R1;

PROCEDURE (p: P0) [ABSTRACT] Proc*;
  END Proc;

PROCEDURE (p: P1) Proc*;
  BEGIN
    p.Proc^;
  END Proc;

END Abstract7.
