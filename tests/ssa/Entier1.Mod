MODULE Entier1;

IMPORT Out := Out0;

PROCEDURE EntierReal (x: REAL; i: LONGINT);
  BEGIN
    Out.Real(x, 4);
    Out.Int(i, 4);
    Out.Int(ENTIER(x), 4);
    Out.Ln;
  END EntierReal;

PROCEDURE EntierLongReal (x: LONGREAL; i: LONGINT);
  BEGIN
    Out.LongReal(x, 4);
    Out.Int(i, 4);
    Out.Int(ENTIER(x), 4);
    Out.Ln;
  END EntierLongReal;

PROCEDURE Test* ();
  BEGIN
    EntierReal(0.0, 0);
    EntierReal(0.9, 0);
    EntierReal(-0.1, -1);
    EntierLongReal(0.0D0, 0);
    EntierLongReal(0.9D0, 0);
    EntierLongReal(-0.1D0, -1);
  END Test;

END Entier1.
