MODULE HOTFunction4;

IMPORT Out := Out0;
  
PROCEDURE Select (b: BOOLEAN): INTEGER;
  BEGIN
    IF b THEN
      RETURN 1
    ELSE
      RETURN 0
    END;
  END Select;

PROCEDURE Test* ();
  BEGIN
    Out.Int(Select(FALSE), 0); Out.Ln;
    Out.Int(Select(TRUE), 0); Out.Ln;
  END Test;

END HOTFunction4.
