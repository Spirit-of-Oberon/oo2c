MODULE ConstFold9;

IMPORT Out := Out0;

CONST
  c = 16;
  
TYPE
  A = ARRAY c OF CHAR;

VAR
  a: A;
  
PROCEDURE Test*;
  BEGIN
    Out.Int(LEN (a),0); Out.Ln;
  END Test;

END ConstFold9.
