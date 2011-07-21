MODULE Val1;

IMPORT SYSTEM, Out := Out0;

PROCEDURE Cast (r: REAL);
  BEGIN
    Out.Int (SYSTEM.VAL (LONGINT, r), 0); Out.Ln;
  END Cast;

PROCEDURE Test* ();
  BEGIN
    Cast (1);
  END Test;

END Val1.
