MODULE HOTVarPar1;

IMPORT Out := Out0;
  
VAR
  a: INTEGER;

PROCEDURE Set(VAR x: INTEGER; val: INTEGER);
  BEGIN
    x := val
  END Set;

PROCEDURE Test*;
  BEGIN
    Set(a, 2); Out.Int (a, 0); Out.Ln;
    Set(a, 3); Out.Int (a, 0); Out.Ln;
  END Test;

END HOTVarPar1.
