MODULE LibRealConvScanReal3;

IMPORT
  Out := Out0, ConvTypes, RealConv;

PROCEDURE Track (str: ARRAY OF CHAR);
  VAR
    cl: ConvTypes.ScanClass;
    st: ConvTypes.ScanState;
    i: LONGINT;
  BEGIN
    Out.String ("input: "); Out.String (str); Out.Ln;
    RealConv.ScanReal (str[0], cl, st);
    i := 1;
    WHILE (cl # ConvTypes.invalid) & (cl # ConvTypes.terminator) DO
      Out.Int (cl, 3);
      st. p(str[i], cl, st);
      INC (i);
    END;
    Out.Int (cl, 3);
    Out.Ln;
  END Track;

PROCEDURE Test* ();
  BEGIN
    Track ("1E0");
    Track ("1 E0");
    Track ("1E 0");
    Track ("1E+1");
    Track ("1E-1");
    Track ("1E+ 1");
    Track ("1E34 ");
    Track ("1E");
    Track ("1e0");
  END Test;

END LibRealConvScanReal3.
