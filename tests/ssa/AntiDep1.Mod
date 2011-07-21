MODULE AntiDep1;

IMPORT
  Out := Out0;
  
VAR
  r: RECORD a: INTEGER; END;

PROCEDURE P (): INTEGER;
  VAR
    x: INTEGER;
  BEGIN
    x := r. a;
    r. a := 2;
    RETURN x
  END P;

PROCEDURE Test* ();
  BEGIN
    r. a := 1;
    Out.Int (r. a, 0); Out.Ln;
    Out.Int (P(), 0); Out.Ln;
    Out.Int (r. a, 0); Out.Ln;
  END Test;

END AntiDep1.
