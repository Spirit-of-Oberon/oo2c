MODULE LibLRealStrRealToEng1;

IMPORT
  Out := Out0, LRealStr;

PROCEDURE Value (real: LONGREAL; sigFigs: INTEGER);
  VAR
    str: ARRAY 32 OF CHAR;
  BEGIN
    LRealStr.RealToEng (real, sigFigs, str);
    Out.String (str);
    Out.Ln;
  END Value;

(*PROCEDURE ValueTrunc (i: LONGINT);
  VAR
    str: ARRAY 4 OF CHAR;
  BEGIN
    LRealStr.RealToEng (i, str);
    Out.String (str);
    Out.Ln;
  END ValueTrunc;*)

PROCEDURE Test* ();
  BEGIN
    Value (3923009, 1);
    Value (39.23009, 1);
    Value (3.923009, 1);
    Value (0.3923009, 1);
    Value (0.0003923009, 1);
    Value (0, 1);
    Value (-0.0003923009, 1);
    
    Value (3923009, 2);
    Value (39.23009, 2);
    Value (3.923009, 2);
    Value (0.3923009, 2);
    Value (0.0003923009, 2);
    Value (0, 2);
    Value (-0.0003923009, 2);
    
    Value (3923009, 5);
    Value (39.23009, 5);
    Value (3.923009, 5);
    Value (0.3923009, 5);
    Value (0.0003923009, 5);
    Value (0, 5);
    Value (-0.0003923009, 5);
  END Test;

END LibLRealStrRealToEng1.
