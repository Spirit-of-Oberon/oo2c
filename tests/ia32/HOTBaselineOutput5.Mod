MODULE HOTBaselineOutput5;  (* mva *)

IMPORT Out := Out0;

PROCEDURE Test*;
  BEGIN
    Out.Char ("a"); Out.Ln;
    Out.Char ("z"); Out.Ln;
    Out.Char ("A"); Out.Ln;
    Out.Char ("Z"); Out.Ln;
    Out.Char ("0"); Out.Ln;
    Out.Char ("9"); Out.Ln;
  END Test;

END HOTBaselineOutput5.
