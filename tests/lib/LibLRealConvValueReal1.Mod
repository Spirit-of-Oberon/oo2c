MODULE LibLRealConvValueReal1;

IMPORT
  Out, ConvTypes, LRealConv;

PROCEDURE Value (str: ARRAY OF CHAR);
  BEGIN
    Out.String ("str='"); Out.String (str); Out.String ("', value=");
    Out.LongReal (LRealConv.ValueReal (str), 8); Out.Ln;
  END Value;

PROCEDURE Test* ();
  BEGIN
    Value (" 1.0");
  END Test;

END LibLRealConvValueReal1.
