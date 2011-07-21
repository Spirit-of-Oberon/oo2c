MODULE HOTIf3;

IMPORT Out := Out0;
  
PROCEDURE If (a, b: BOOLEAN);
  BEGIN
    IF a THEN
      Out.String ("a=TRUE")
    ELSIF b THEN
      Out.String ("a=FALSE, b=TRUE")
    ELSE
      Out.String ("a=FALSE, b=FALSE")
    END;
    Out.Ln
  END If;

PROCEDURE Test* ();
  BEGIN
    If (TRUE, TRUE);
    If (FALSE, TRUE);
    If (FALSE, FALSE);
  END Test;

END HOTIf3.
