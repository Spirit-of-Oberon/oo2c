MODULE LibLRealConvScanReal1;

IMPORT
  Out := Out0, ConvTypes, LRealConv;

PROCEDURE Track (str: ARRAY OF CHAR);
  VAR
    cl: ConvTypes.ScanClass;
    st: ConvTypes.ScanState;
    i: LONGINT;
  BEGIN
    Out.String ("input: "); Out.String (str); Out.Ln;
    LRealConv.ScanReal (str[0], cl, st);
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
    Track (" 1");
    Track ("+1");
    Track ("-1");
    Track ("1");
    Track ("1 ");
    Track ("+-1");
    Track ("123");
    Track ("");
  END Test;

END LibLRealConvScanReal1.
