MODULE Case11;

IMPORT Out := Out0;

PROCEDURE P (i: CHAR);
  BEGIN
    CASE i OF
    || "a".."z", "A".."Z": Out.String ("letter");
    || "0".."9": Out.String ("digit");
    || (* nothing *)
    ELSE
      Out.String ("no match");
    END;
    Out.Ln;
  END P;

PROCEDURE Test* ();
  VAR
    i: INTEGER;
  BEGIN
    P ("a");
    P ("g");
    P ("z");
    P ("0");
    P ("9");
    P ("/");
  END Test;

END Case11.
