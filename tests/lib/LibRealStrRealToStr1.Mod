MODULE LibRealStrRealToStr1;

IMPORT
  Out := Out0, RealStr;

PROCEDURE Value (real: REAL);
  VAR
    str: ARRAY 10 OF CHAR;
  BEGIN
    RealStr.RealToStr (real, str);
    Out.String (str);
    Out.Ln;
  END Value;

PROCEDURE Test* ();
  BEGIN
    Value (99999999);
    Value (10000000);
    Value ( 9999999);
    Value ( 1000000);
    Value (  999999);
    Value (  100000);
    Value (   99999);
    
    Out.Ln;
    Value (-9999999);
    Value (-1000000);
    Value ( -999999);
    Value ( -100000);
    Value (  -99999);
    Value (  -10000);
    Value (   -9999);

    Out.Ln;
    Value (-99999999);
    Value (-99950000);
    Value (-99949999);
    Value (-10000000);
  END Test;

END LibRealStrRealToStr1.
