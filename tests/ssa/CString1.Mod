MODULE CString1;

IMPORT Out := Out0;
TYPE
  CString = POINTER [CSTRING] TO ARRAY OF CHAR;

PROCEDURE OutString(str : CString);
BEGIN
  Out.String(str^); Out.Ln;
END OutString;

PROCEDURE Test*;
VAR
  a : POINTER TO ARRAY OF CHAR;
  b : ARRAY 32 OF CHAR;
BEGIN
  OutString("String Constant");
  OutString('X');
  NEW(a, 32);
  COPY("Open Array", a^);
  OutString(a^);
  COPY("Fixed Array", b);
  OutString(b);
END Test;

END CString1.
