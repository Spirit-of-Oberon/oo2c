MODULE ConstFold16;

IMPORT Out;

CONST
  a = {1, 2, 5..9};
  b = {2, 4, 6, 8};

  union = a + b;
  diff = a - b;
  intersect = a * b;
  xor = a / b;

PROCEDURE Test*;
BEGIN
  Out.Set(a); Out.Ln;
  Out.Set(b); Out.Ln;
  Out.Set(union); Out.Ln;
  Out.Set(diff); Out.Ln;
  Out.Set(intersect); Out.Ln;
  Out.Set(xor); Out.Ln;
END Test;

END ConstFold16.
