MODULE M009;
(** @ofield{p.a} *)

TYPE
  R* = RECORD a-: INTEGER; END;
  P* = POINTER TO ARRAY OF R;

VAR
  p*: P;

END M009.
