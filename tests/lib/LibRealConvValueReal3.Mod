MODULE LibRealConvValueReal3;

IMPORT
  Out := Out0, ConvTypes, RealConv;

PROCEDURE Value (str: ARRAY OF CHAR);
  CONST
    sigFigs = 9;
  BEGIN
    Out.String ("str='"); Out.String (str); Out.String ("', value=");
    Out.LongReal (RealConv.ValueReal (str), sigFigs-1); Out.Ln;
  END Value;

PROCEDURE Test* ();
  BEGIN
    Value (" -0.0");
  END Test;

END LibRealConvValueReal3.
