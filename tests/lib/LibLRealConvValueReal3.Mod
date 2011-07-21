MODULE LibLRealConvValueReal3;

IMPORT
  Out := Out0, ConvTypes, LRealConv;

PROCEDURE Value (str: ARRAY OF CHAR);
  CONST
    sigFigs = 17;
  BEGIN
    Out.String ("str='"); Out.String (str); Out.String ("', value=");
    Out.LongReal (LRealConv.ValueReal (str), sigFigs-1); Out.Ln;
  END Value;

PROCEDURE Test* ();
  BEGIN
    Value (" -0.0");
  END Test;

END LibLRealConvValueReal3.
