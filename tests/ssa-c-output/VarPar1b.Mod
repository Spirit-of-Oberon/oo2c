MODULE VarPar1b;

IMPORT Out := Out0;
  
VAR
  a: INTEGER;
  x: INTEGER;

PROCEDURE F(VAR p: INTEGER): INTEGER;
  BEGIN
    x := 1;
    p := 2;
    RETURN x+p
  END F;

PROCEDURE Test*;
  BEGIN
    Out.Int (F(a), 0); Out.Ln;
    Out.Int (F(x), 0); Out.Ln;
  END Test;

END VarPar1b.
