MODULE OpExprCompat1;

IMPORT Out := Out0;

PROCEDURE Test*;
VAR
  si : SHORTINT;
  i : INTEGER;
  li : LONGINT;
  r : REAL;
  a1, a2 : ARRAY 8 OF CHAR;
  p : POINTER TO ARRAY OF CHAR;
BEGIN
  i := 1;
  si := 1;
  li := 1;
  r := 1.0;

  i := si + si;
  i := i + si;
  i := si + i;

  li := i + i;
  li := li + i;
  li := i + li;

  r := li + r;
  r := r + li;
  r := li / i;

  a1 := "string";
  a2 := a1;

  p := NIL;

  Out.Int(li,0); Out.Ln;
  Out.Int(i,0); Out.Ln;
  Out.Real(r,0); Out.Ln;
  Out.String(a2); Out.Ln;
END Test;

END OpExprCompat1.
