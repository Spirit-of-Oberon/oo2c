MODULE LibLRealStrRealToFixed1;

IMPORT
  Out := Out0, LRealStr;

PROCEDURE Value (real: LONGREAL; sigFigs: INTEGER);
  VAR
    str: ARRAY 32 OF CHAR;
  BEGIN
    LRealStr.RealToFixed (real, sigFigs, str);
    Out.String (str);
    Out.Ln;
  END Value;

(*PROCEDURE ValueTrunc (i: LONGINT);
  VAR
    str: ARRAY 4 OF CHAR;
  BEGIN
    LRealStr.RealToFixed (i, str);
    Out.String (str);
    Out.Ln;
  END ValueTrunc;*)

PROCEDURE Test* ();
  BEGIN
    Value (3923009, 0);
    Value (39.23009, 0);
    Value (3.923009, 0);
    Value (0.3923009, 0);
    Value (0.0003923009, 0);
    Value (0, 0);
    Value (-0.0003923009, 0);
    
    Out.Ln;
    Value (3923009, 1);
    Value (39.23009, 1);
    Value (3.923009, 1);
    Value (0.3923009, 1);
    Value (0.0003923009, 1);
    Value (0, 1);
    Value (-0.0003923009, 1);
    
    Out.Ln;
    Value (3923009, 2);
    Value (39.23009, 2);
    Value (3.923009, 2);
    Value (0.3923009, 2);
    Value (0.0003923009, 2);
    Value (0, 2);
    Value (-0.0003923009, 2);
    
    Out.Ln;
    Value (3923009, 5);
    Value (39.23009, 5);
    Value (3.923009, 5);
    Value (0.3923009, 5);
    Value (0.0003923009, 5);
    Value (0, 5);
    Value (-0.0003923009, 5);
  END Test;

END LibLRealStrRealToFixed1.
