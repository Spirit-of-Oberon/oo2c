MODULE ConstFold16;

IMPORT Out;

CONST
  a = {1, 2, 5..9};
  b = {2, 4, 6, 8};

PROCEDURE Test*;
BEGIN
  Out.Set(a); Out.Ln;
  Out.Set(b); Out.Ln;
END Test;

END ConstFold16.
