MODULE LibIntStrIntToStr1;

IMPORT
  Out := Out0, IntStr;

PROCEDURE Value (i: LONGINT);
  VAR
    str: ARRAY 32 OF CHAR;
  BEGIN
    IntStr.IntToStr (i, str);
    Out.String (str);
    Out.Ln;
  END Value;

PROCEDURE ValueTrunc (i: LONGINT);
  VAR
    str: ARRAY 4 OF CHAR;
  BEGIN
    IntStr.IntToStr (i, str);
    Out.String (str);
    Out.Ln;
  END ValueTrunc;

PROCEDURE Test* ();
  BEGIN
    Value (-2147483647-1);
    Value (-2147483647);
    Value (-1);
    Value (0);
    Value (1);
    Value (2147483646);
    Value (2147483647);

    ValueTrunc (-2147483647-1);
    ValueTrunc (-2147483647);
    ValueTrunc (-100);
    ValueTrunc (-99);
    ValueTrunc (-1);
    ValueTrunc (0);
    ValueTrunc (1);
    ValueTrunc (999);
    ValueTrunc (1000);
    ValueTrunc (2147483646);
    ValueTrunc (2147483647);
  END Test;

END LibIntStrIntToStr1.
