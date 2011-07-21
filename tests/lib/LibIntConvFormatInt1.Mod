MODULE LibIntConvFormatInt1;

IMPORT
  Out := Out0, ConvTypes, IntConv;

PROCEDURE WriteFormat (str: ARRAY OF CHAR);
  VAR
    f: ConvTypes.ConvResults;
  BEGIN
    f := IntConv.FormatInt (str);
    CASE f OF
    | ConvTypes.strAllRight: Out.String ("all right");
    | ConvTypes.strOutOfRange: Out.String ("out of range");
    | ConvTypes.strWrongFormat: Out.String ("wrong format");
    | ConvTypes.strEmpty: Out.String ("empty");
    END;
    Out.Ln;
  END WriteFormat;

PROCEDURE Test* ();
  BEGIN
    WriteFormat ("");
    WriteFormat ("   ");
    WriteFormat ("0");
    WriteFormat ("+0");
    WriteFormat ("-0");
    WriteFormat ("1");
    WriteFormat ("+1");
    WriteFormat ("-1");
    WriteFormat ("10");
    WriteFormat ("+10");
    WriteFormat ("-10");
    WriteFormat ("214748365");
    WriteFormat ("-214748365");
    WriteFormat ("2147483647");
    WriteFormat ("-2147483648");
    WriteFormat ("2147483648");
    WriteFormat ("-2147483649");
    WriteFormat ("+");
    WriteFormat ("-");
    WriteFormat ("+-0");
    WriteFormat ("1 2");
    WriteFormat ("123 ");
  END Test;

END LibIntConvFormatInt1.
