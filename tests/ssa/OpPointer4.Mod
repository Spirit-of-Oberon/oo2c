MODULE OpPointer4;

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
VAR r : RDesc;
BEGIN
  r := New(1)^;
END Test;

END OpPointer4.
