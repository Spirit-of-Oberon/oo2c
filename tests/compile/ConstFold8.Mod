MODULE ConstFold8;

IMPORT Out;

TYPE
  A = ARRAY 16 OF CHAR;

VAR
  a: A;

CONST
  c = LEN (a);
  
PROCEDURE Test*;
  BEGIN
    Out.Int(c,0); Out.Ln;
  END Test;

END ConstFold8.
