MODULE LibLRealConvFormatReal2;

IMPORT
  Out := Out0, ConvTypes, LRealConv;

PROCEDURE WriteFormat (str: ARRAY OF CHAR);
  VAR
    f: ConvTypes.ConvResults;
  BEGIN
    Out.String ("str='"); Out.String (str); Out.String ("', format=");
    f := LRealConv.FormatReal (str);
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
    WriteFormat ("1.7976931348623156E+308");
    WriteFormat ("1.7976931348623157E+308");
    WriteFormat ("-1.7976931348623157E+308");
    WriteFormat ("1.7976931348623157000E+308");
    WriteFormat ("0.17976931348623157000E+309");
    WriteFormat ("0.017976931348623157000E+310");
    WriteFormat ("17.976931348623157000E+307");
    WriteFormat ("+0.000E9999999999");
    WriteFormat ("1.7976931348623158E-308");
    WriteFormat ("1.7976931348623157E-309");
    
    WriteFormat ("1.7976931348623157001E+308");
    WriteFormat ("0.17976931348623157001E+309");
    WriteFormat ("0.017976931348623157001E+310");
    WriteFormat ("17.976931348623157001E+307");
    WriteFormat ("1.7976931348623158E+308");
  END Test;

END LibLRealConvFormatReal2.
