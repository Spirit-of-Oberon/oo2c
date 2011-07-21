MODULE LibLRealConvValueReal1;

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
    Value (" +0.0");
    Value ("-1.0");
    Value ("+1.0");
    Value ("+1.");
    Value ("+1E10");
    Value ("-1E+20");
    Value ("0.1");
    Value ("1E-1");
    Value ("1.7976931348623157E+308");  (* MAX(LONGREAL) *)
    Value ("1.7976931348623155E+308");
    Value ("2.2250738585072019E-308");
    Value ("2.2250738585072014E-308");  (* smallest normalized positive *)
    Value ("-2.2250738585072014E-308"); (* largest normalized negative *)
    Value ("-2.2250738585072019E-308");
    Value ("-1.7976931348623155E+308");
    Value ("-1.7976931348623157E+308");  (* MIN(LONGREAL) *)
  END Test;

END LibLRealConvValueReal1.
