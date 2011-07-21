MODULE LibOut;

IMPORT
  Out;
  
PROCEDURE Test* ();
  BEGIN
    Out.String ("String"); Out.Ln;
    Out.Char ("C"); Out.Ln;
    Out.Int (123, 0); Out.Ln;
  END Test;

END LibOut.
