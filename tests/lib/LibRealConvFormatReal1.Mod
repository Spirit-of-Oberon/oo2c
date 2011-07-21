MODULE LibRealConvFormatReal1;

IMPORT
  Out := Out0, ConvTypes, RealConv;

PROCEDURE WriteFormat (str: ARRAY OF CHAR);
  VAR
    f: ConvTypes.ConvResults;
  BEGIN
    Out.String ("str='"); Out.String (str); Out.String ("', format=");
    f := RealConv.FormatReal (str);
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
    WriteFormat (" 0");
    WriteFormat ("1");
    WriteFormat ("+1");
    WriteFormat (" -1");
    WriteFormat ("1.");
    WriteFormat ("1.0");
    WriteFormat ("1E1");
    WriteFormat ("1e1");
    WriteFormat ("1.E1");
    WriteFormat ("1.0E1");
    WriteFormat ("1E+12");
    WriteFormat ("1E-12");
    
    WriteFormat (".1");
    WriteFormat (" 0 ");
    WriteFormat ("1. ");
    WriteFormat ("E1");
    WriteFormat ("1E");
    WriteFormat ("1E-");
    WriteFormat ("1E1.2");
  END Test;

END LibRealConvFormatReal1.
