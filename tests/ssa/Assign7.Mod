MODULE Assign7;

PROCEDURE P (a, b: ARRAY OF CHAR);
  BEGIN
    a := b;                            (* not assignment compatible *)
  END P;

END Assign7.
