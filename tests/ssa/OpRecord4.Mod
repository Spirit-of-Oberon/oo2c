MODULE OpRecord4;

IMPORT Out := Out0;

TYPE

  R = POINTER TO RDesc;

  RDesc = RECORD
    i : INTEGER;
  END;

PROCEDURE New(i : INTEGER) : R;
VAR r : R;
BEGIN
  NEW(r);
  r.i := i;
  RETURN r;
END New;

PROCEDURE Test*;
BEGIN
  Out.Int(New(1).i, 0);
END Test;

END OpRecord4.
