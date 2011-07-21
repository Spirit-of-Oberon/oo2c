MODULE VarPar1c;

IMPORT Out := Out0;
  
VAR
  a: INTEGER;
  x: LONGINT;

PROCEDURE F(VAR p: INTEGER): LONGINT;
  BEGIN
    x := 1;
    p := 2;
    RETURN x+p
  END F;

PROCEDURE Test*;
  BEGIN
    Out.Int (SHORT (F(a)), 0); Out.Ln;
  END Test;

END VarPar1c.
