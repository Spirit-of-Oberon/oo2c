MODULE Abstract10;

TYPE
  R = RECORD [ABSTRACT] END;
  P = POINTER TO R;

VAR
  p: P;

BEGIN
  p := NEW(P);
END Abstract10.
