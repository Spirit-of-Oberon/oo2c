MODULE Abstract4;

TYPE
  R = RECORD [ABSTRACT] END;
  P = POINTER TO R;

VAR
  p: P;

BEGIN
  NEW(p);
END Abstract4.
