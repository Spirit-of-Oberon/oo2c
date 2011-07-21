MODULE LibLRealStrStrToReal1;

IMPORT
  Out := Out0, LRealStr;

PROCEDURE Value (str: ARRAY OF CHAR);
  VAR
    r: LONGREAL; res: LRealStr.ConvResults;
  BEGIN
    r := 0;
    LRealStr.StrToReal (str, r, res);
    Out.LongReal (r, 17);
    CASE res OF
    | LRealStr.strAllRight: Out.String (" strAllRight");
    | LRealStr.strWrongFormat: Out.String (" strWrongFormat");
    | LRealStr.strEmpty: Out.String (" strEmpty");
    | LRealStr.strOutOfRange: Out.String (" strOutOfRange");
    END;
    Out.Ln;
  END Value;

PROCEDURE Test* ();
  BEGIN
    Value ("  ");
    Value (" 0");
    Value ("1.0");
    Value ("1E1");
    Value ("1E309");
    Value ("-1E309");
    Value ("1 E2");
  END Test;

END LibLRealStrStrToReal1.
