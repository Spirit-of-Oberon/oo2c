MODULE LibRealConvFormatReal2;

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
    WriteFormat ("3.40282346E+38");
    WriteFormat ("3.40282347E+38");
    WriteFormat ("-3.40282347E+38");
    WriteFormat ("3.40282347000E+38");
    WriteFormat ("0.340282347000E+39");
    WriteFormat ("0.0340282347000E+40");
    WriteFormat ("34.0282347E+37");
    WriteFormat ("+0.000E9999999999");
    WriteFormat ("3.40282348E-38");
    WriteFormat ("3.40282347E-39");
    
    WriteFormat ("3.40282347001E+38");
    WriteFormat ("0.340282347001E+39");
    WriteFormat ("0.0340282347001E+40");
    WriteFormat ("34.0282347001E+37");
    WriteFormat ("3.40282348E+38");
  END Test;

END LibRealConvFormatReal2.
