MODULE ConstFold15;

IMPORT
  Out := Out0;

CONST
  a = "A"; 
  b = "B";

  lt1 = a < a;
  le1 = a <= a;
  eq1 = a = a;
  ne1 = a # a;
  ge1 = a >= a;
  gt1 = a > a;

  lt2 = a < b;
  le2 = a <= b;
  eq2 = a = b;
  ne2 = a # b;
  ge2 = a >= b;
  gt2 = a > b;

  lt3 = b < a;
  le3 = b <= a;
  eq3 = b = a;
  ne3 = b # a;
  ge3 = b >= a;
  gt3 = b > a;

PROCEDURE Test*;
BEGIN
  Out.Bool(lt1); Out.Ln;
  Out.Bool(le1); Out.Ln;
  Out.Bool(eq1); Out.Ln;
  Out.Bool(ne1); Out.Ln;
  Out.Bool(ge1); Out.Ln;
  Out.Bool(gt1); Out.Ln;

  Out.Bool(lt2); Out.Ln;
  Out.Bool(le2); Out.Ln;
  Out.Bool(eq2); Out.Ln;
  Out.Bool(ne2); Out.Ln;
  Out.Bool(ge2); Out.Ln;
  Out.Bool(gt2); Out.Ln;

  Out.Bool(lt3); Out.Ln;
  Out.Bool(le3); Out.Ln;
  Out.Bool(eq3); Out.Ln;
  Out.Bool(ne3); Out.Ln;
  Out.Bool(ge3); Out.Ln;
  Out.Bool(gt3); Out.Ln;
END Test;

END ConstFold15.
