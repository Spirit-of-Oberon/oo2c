MODULE LongReal3;

IMPORT Out:=Out0;

PROCEDURE Print(x: LONGREAL);
  BEGIN
    Out.LongReal(x, 3); Out.Ln;
  END Print;

PROCEDURE f(): LONGREAL;
  BEGIN
    RETURN 1.0;
  END f;

PROCEDURE g(): LONGREAL;
  BEGIN
    RETURN 2.0;
  END g;

PROCEDURE h(): LONGREAL;
  BEGIN
    RETURN -0.025;
  END h;

PROCEDURE Test*();
  BEGIN
    Print(f());
    Print(g());
    Print(h());
  END Test;

END LongReal3.
