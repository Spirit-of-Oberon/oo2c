MODULE ConstFold6;

IMPORT Out;

CONST
  maxShortInt = 127;
  minShortInt = -128;
  maxInteger = 32767;
  minInteger = -32768;
  maxLongInt = 2147483647;
  minLongInt = -2147483647; (* C compiler treats -2147483648 as unsigned ? *)

  offset = 1;

PROCEDURE Test*;
BEGIN
  Out.Int(minShortInt-offset,0); Out.Ln;
  Out.Int(maxShortInt+offset,0); Out.Ln;
  Out.Int(minInteger-offset,0); Out.Ln;
  Out.Int(maxInteger+offset,0); Out.Ln;
  Out.Int(minLongInt-offset,0); Out.Ln;
  Out.Int(maxLongInt+offset,0); Out.Ln;
END Test;

END ConstFold6.
