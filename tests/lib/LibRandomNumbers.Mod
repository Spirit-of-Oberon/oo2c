MODULE LibRandomNumbers;

IMPORT
  Out, RandomNumbers;

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
  END Test;

END LibRandomNumbers.
