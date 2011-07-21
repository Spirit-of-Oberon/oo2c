MODULE LibRandomNumbers;

IMPORT
  Out := Out0, RandomNumbers;

CONST
  mod = 2147483646;
  
PROCEDURE WriteRND ();
  VAR
    i: LONGINT;
  BEGIN
    FOR i := 0 TO 2 DO
      Out.Int (RandomNumbers.RND (mod), 12);
    END;
    Out.Ln;
  END WriteRND;

PROCEDURE Test* ();
  BEGIN
    WriteRND;
    
    RandomNumbers.PutSeed (2);
    WriteRND;
    
    RandomNumbers.PutSeed (2147483646);
    WriteRND;

    RandomNumbers.PutSeed (12345);
    Out.Real (RandomNumbers.Random(), 6); Out.Ln;
  END Test;

END LibRandomNumbers.
