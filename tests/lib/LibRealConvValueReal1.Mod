MODULE LibRealConvValueReal1;

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
    Value (" +0.0");
    Value ("-1.0");
    Value ("+1.0");
    Value ("+1.");
    Value ("+1E10");
    Value ("-1E+20");
    Value ("0.1");
    Value ("1E-1");
    Value ("3.40282347E+38");   (* MAX(REAL) *)
    Value ("3.40282326E+38");
    Value ("1.17549449E-38");
    Value ("1.17549435E-38");  (* smallest normalized positive *)
    Value ("-1.17549435E-38"); (* largest normalized negative *)
    Value ("-1.17549449E-38");
    Value ("-3.40282326E+38");
    Value ("-3.40282347E+38");  (* MIN(REAL) *)
  END Test;

END LibRealConvValueReal1.
