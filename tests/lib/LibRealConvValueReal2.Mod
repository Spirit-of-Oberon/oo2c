MODULE LibRealConvValueReal2;

IMPORT
  Out := Out0, ConvTypes, RealConv;

PROCEDURE Value (str: ARRAY OF CHAR);
  CONST
    sigFigs = 9;
  BEGIN
    Out.String ("str='"); Out.String (str); Out.String ("', value=");
    Out.Real (RealConv.ValueReal (str), sigFigs-1); Out.Ln;
  END Value;

PROCEDURE Test* ();
  BEGIN
    (* smallest positive REAL, denormalized *)
    Value (" 1.40129846e-45");
    (* largest negative REAL, denormalized *)
    Value ("-1.40129846E-45");
  END Test;

END LibRealConvValueReal2.
