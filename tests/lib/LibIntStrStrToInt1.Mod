MODULE LibIntStrStrToInt1;

IMPORT
  Out := Out0, IntStr;

PROCEDURE Value (str: ARRAY OF CHAR);
  VAR
    i: LONGINT; res: IntStr.ConvResults;
  BEGIN
    i := 0;
    IntStr.StrToInt (str, i, res);
    Out.Int (i, 0);
    CASE res OF
    | IntStr.strAllRight: Out.String (" strAllRight");
    | IntStr.strWrongFormat: Out.String (" strWrongFormat");
    | IntStr.strEmpty: Out.String (" strEmpty");
    | IntStr.strOutOfRange: Out.String (" strOutOfRange");
    END;
    Out.Ln;
  END Value;

PROCEDURE Test* ();
  BEGIN
    Value ("  ");
    Value (" 0");
    Value (" 1");
    Value ("+1");
    Value ("-1");
    Value ("2147483647");
    Value ("-2147483648");
    Value ("2147483648");
    Value ("-2147483649");
    Value ("1.0");
    Value ("1-");
    Value ("1 2");
  END Test;

END LibIntStrStrToInt1.
