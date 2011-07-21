
(* Test simple constant folding for integers. *)

MODULE Fold1;

IMPORT Out;

PROCEDURE Int(x : INTEGER);
BEGIN
  Out.Int(x, 0); Out.Ln;
END Int;

PROCEDURE Test* ();
  BEGIN
    (* constant *)
    Int(123);
    (* integer unary + and - operator *)
    Int(+123);
    Int(-123);

    (* integer arithmetic *)
    Int(1 + 2);
    Int(-1 + 1);
    Int(1 - 1);
    Int(1 + 2 * 3);
    Int(2 * 3 + 4 * 5);
    Int(10 DIV 3);
    Int(10 MOD 3);
  END Test;

END Fold1.
