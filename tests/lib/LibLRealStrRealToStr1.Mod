MODULE LibLRealStrRealToStr1;

IMPORT
  Out := Out0, LRealStr;

PROCEDURE Value (real: LONGREAL);
  VAR
    str: ARRAY 10 OF CHAR;
  BEGIN
    LRealStr.RealToStr (real, str);
    Out.String (str);
    Out.Ln;
  END Value;

PROCEDURE Test* ();
  BEGIN
    Value (999999999);
    Value (100000000);
    Value ( 99999999);
    Value ( 10000000);
    Value (  9999999);
    Value (  1000000);
    Value (   999999);
    
    Out.Ln;
    Value (-99999999);
    Value (-10000000);
    Value ( -9999999);
    Value ( -1000000);
    Value (  -999999);
    Value (  -100000);
    Value (   -99999);

    Out.Ln;
    Value (9999999999.D0);
    Value (9999500000.D0);        (* this is 1.000E+10 or 9.9995E+9 *)
    Value (9999499999.D0);
    Value (1000000000.D0);

    Out.Ln;
    Value (-999999999);
    Value (-999500000);
    Value (-999499999);
    Value (-100000000);
  END Test;

END LibLRealStrRealToStr1.
