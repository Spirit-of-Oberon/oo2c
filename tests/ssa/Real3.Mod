MODULE Real3;

IMPORT Out:=Out0;

PROCEDURE Print(x: REAL);
  BEGIN
    Out.Real(x, 3); Out.Ln;
  END Print;

PROCEDURE f(): REAL;
  BEGIN
    RETURN 1.0;
  END f;

PROCEDURE g(): REAL;
  BEGIN
    RETURN 2.0;
  END g;

PROCEDURE h(): REAL;
  BEGIN
    RETURN -0.025;
  END h;

PROCEDURE Test*();
  BEGIN
    Print(f());
    Print(g());
    Print(h());
  END Test;

END Real3.
