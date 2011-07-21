MODULE M011;
(** @ofield{p.b} *)

TYPE
  R* = RECORD a-: INTEGER; END;
  P* = POINTER TO ARRAY OF R;

VAR
  p*: P;

END M011.
