
MODULE Fold1;

IMPORT Out;

PROCEDURE Int(x : INTEGER);
BEGIN
  Out.Int(x, 0); Out.Ln;
END Int;

PROCEDURE Test* ();
  BEGIN
    Int(123);
    Int(1 + 2);
    Int(1 + 2 * 3);
  END Test;

END Fold1.
