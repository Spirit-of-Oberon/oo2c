MODULE Case2;

PROCEDURE P (i: INTEGER);
  BEGIN
    <*CaseSelectCheck:=TRUE*>
    CASE i OF
    | 1: (* nothing *)
    END;
  END P;

PROCEDURE Test* ();
  BEGIN
    P (2);
  END Test;

END Case2.
