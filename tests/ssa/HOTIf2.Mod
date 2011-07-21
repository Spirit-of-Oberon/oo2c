MODULE HOTIf2;

IMPORT Out := Out0;
  
PROCEDURE If (b: BOOLEAN);
  VAR
    x: INTEGER;
  BEGIN
    IF b THEN
      Out.String ("TRUE ")
    END;
    Out.String ("EXIT");
    Out.Ln
  END If;

PROCEDURE Test* ();
  BEGIN
    If (TRUE);
    If (FALSE);
  END Test;

END HOTIf2.
