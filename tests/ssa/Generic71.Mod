MODULE Generic71;

TYPE
   (* T = A;  OK : error *)
   T = A(B);  (* problem : crash *)

PROCEDURE P(t : T);
BEGIN
END P;

END Generic71.
