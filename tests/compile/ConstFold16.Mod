MODULE ConstFold16;

IMPORT Out := Out0;

CONST
  MINSET = 0;
  MAXSET = 31;

CONST
  a = {1, 2, 5..9};
  b = {2, 4, 6, 8};

  union = a + b;
  diff = a - b;
  intersect = a * b;
  xor = a / b;
  not = -a;
  ina = 1 IN a;
  inb = 1 IN b;

PROCEDURE Test*;
BEGIN
  Out.Set(a); Out.Ln;
  Out.Set(b); Out.Ln;
  Out.Set(union); Out.Ln;
  Out.Set(diff); Out.Ln;
  Out.Set(intersect); Out.Ln;
  Out.Set(xor); Out.Ln;
  Out.Set({MINSET..MAXSET}); Out.Ln;
  Out.Set(not); Out.Ln;
  Out.Bool(ina); Out.Ln;
  Out.Bool(inb); Out.Ln;
END Test;

END ConstFold16.
