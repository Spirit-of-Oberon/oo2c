MODULE OpArray1;

IMPORT Out;

PROCEDURE ArrayValue (a : ARRAY OF CHAR);
BEGIN
  Out.Char(a[0]);
END ArrayValue;

PROCEDURE ArrayRef (VAR a : ARRAY OF CHAR);
BEGIN
  Out.Char(a[0]);
END ArrayRef;

BEGIN
  
END OpArray1.
