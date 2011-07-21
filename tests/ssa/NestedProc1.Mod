MODULE NestedProc1;

IMPORT Out := Out0;
  
PROCEDURE Test* ();
  PROCEDURE Inner ();
    BEGIN
      Out.String ("Hello World"); Out.Ln;
    END Inner;
  
  BEGIN
    Inner;
  END Test;

END NestedProc1.
