MODULE Mod2;

IMPORT Out := Out0;

PROCEDURE Mod (i, j: INTEGER);
  BEGIN
    Out.Int (i, 3); Out.String (" MOD "); Out.Int (j, 0); Out.String (" = ");
    Out.Int (i MOD j, 0); Out.Ln;
  END Mod;

PROCEDURE Test* ();
  VAR
    i: INTEGER;
  BEGIN
    FOR i := -6 TO 6 DO
      Mod (i, -3);
    END;
  END Test;

END Mod2.
