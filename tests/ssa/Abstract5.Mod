MODULE Abstract5;

TYPE
  R = RECORD END;
  P = POINTER TO R;

PROCEDURE (p: P) [ABSTRACT] Proc*;
  END Proc;

END Abstract5.
