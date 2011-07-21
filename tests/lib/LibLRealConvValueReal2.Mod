MODULE LibLRealConvValueReal2;

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
    (* smallest positive LONGREAL, denormalized *)
    Value ("4.9406564584124654e-324");
    (* largest negative LONGREAL, denormalized *)
    Value ("-4.9406564584124654e-324");
  END Test;

END LibLRealConvValueReal2.
