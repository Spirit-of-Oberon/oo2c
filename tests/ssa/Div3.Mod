MODULE Div3;

IMPORT Out := Out0;

PROCEDURE Div (i: INTEGER);
  BEGIN
    Out.Int (i DIV 2, 3); Out.Ln;
  END Div;

PROCEDURE Test* ();
  BEGIN
    Div (2);
    Div (-2);
  END Test;

END Div3.
