MODULE MinMax1;

IMPORT Out := Out0;

PROCEDURE Test* ();
  BEGIN
    Out.Int (MIN (SHORTINT), 12); Out.Int (MAX (SHORTINT), 12); Out.Ln;
    Out.Int (MIN ( INTEGER), 12); Out.Int (MAX ( INTEGER), 12); Out.Ln;
    Out.Int (MIN ( LONGINT), 12); Out.Int (MAX ( LONGINT), 12); Out.Ln;
  END Test;

END MinMax1.
