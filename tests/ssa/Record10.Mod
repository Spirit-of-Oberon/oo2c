MODULE Record10;

IMPORT Out := Out0;

CONST
  len = 2;

TYPE
  P = POINTER TO R;
  R = RECORD
    x: ARRAY len OF CHAR;
    y: INTEGER;
  END;

PROCEDURE Test* ();
  BEGIN
  END Test;

END Record10.
