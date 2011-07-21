
(* Test generation of type conversion operators *)

MODULE Fold2;

IMPORT Out;

PROCEDURE Int(x : INTEGER);
BEGIN
  Out.Int(x, 0); Out.Ln;
END Int;

PROCEDURE Test*;
VAR
  i1, i2 : INTEGER;
  s1, s2 : SHORTINT;
  res : INTEGER;
BEGIN
  Int(i1);
  Int(i1 + i2);
  Int(s1 + i1);
  Int(i1 + s1);
  Int(s1 + s2); 
END Test;

END Fold2.
