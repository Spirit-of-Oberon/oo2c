MODULE NoDescriptor1;

TYPE
  R* = RECORD [NO_DESCRIPTOR]
    a*: INTEGER;
  END;

PROCEDURE P(VAR r: R);
  BEGIN
  END P;

PROCEDURE Test*;
  VAR
    r: R;
  BEGIN
    P(r);
  END Test;

END NoDescriptor1.
