MODULE LibIntConvValueInt1;

IMPORT
  Out := Out0, ConvTypes, IntConv;

PROCEDURE Value (str: ARRAY OF CHAR);
  BEGIN
    Out.Int (IntConv.ValueInt (str), 0); Out.Ln;
  END Value;

PROCEDURE Test* ();
  BEGIN
    Value (" 1");
    Value ("+1");
    Value ("-1");
    Value ("2147483647");
    Value ("-2147483648");
  END Test;

END LibIntConvValueInt1.
