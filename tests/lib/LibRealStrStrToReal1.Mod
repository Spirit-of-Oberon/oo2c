MODULE LibRealStrStrToReal1;

IMPORT
  Out := Out0, RealStr;

PROCEDURE Value (str: ARRAY OF CHAR);
  VAR
    r: REAL; res: RealStr.ConvResults;
  BEGIN
    r := 0;
    RealStr.StrToReal (str, r, res);
    Out.LongReal (r, 17);
    CASE res OF
    | RealStr.strAllRight: Out.String (" strAllRight");
    | RealStr.strWrongFormat: Out.String (" strWrongFormat");
    | RealStr.strEmpty: Out.String (" strEmpty");
    | RealStr.strOutOfRange: Out.String (" strOutOfRange");
    END;
    Out.Ln;
  END Value;

PROCEDURE Test* ();
  BEGIN
    Value ("  ");
    Value (" 0");
    Value ("1.0");
    Value ("1E1");
    Value ("1E39");
    Value ("-1E39");
    Value ("1 E2");
  END Test;

END LibRealStrStrToReal1.
