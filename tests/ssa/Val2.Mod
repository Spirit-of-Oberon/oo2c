MODULE Val2;

IMPORT SYSTEM, Out := Out0;

PROCEDURE Cast (s: SET);
  BEGIN
    Out.Int (SYSTEM.VAL (LONGINT, s), 0); Out.Ln;
  END Cast;

PROCEDURE Test* ();
  BEGIN
    Cast ({0..31});
  END Test;

END Val2.
