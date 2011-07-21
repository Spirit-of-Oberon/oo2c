MODULE M012;
(** @ofield{p.a.x} *)

TYPE
  R* = RECORD a-: RECORD b: INTEGER; END; END;
  P* = POINTER TO ARRAY OF R;

VAR
  p*: P;

END M012.
