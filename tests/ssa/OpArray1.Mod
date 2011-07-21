MODULE OpArray1;

IMPORT
  Out := Out0;

TYPE
  T = SHORTINT;

PROCEDURE OutT(val : T);
BEGIN
  Out.Int(val,0); Out.Ln;
END OutT;

PROCEDURE ElemValue(val : T);
BEGIN
  val := val + 1;
END ElemValue;

PROCEDURE ElemRef(VAR ref : T);
BEGIN
  ref := ref + 1;
END ElemRef;

PROCEDURE ArrayValue(val : ARRAY OF T);
BEGIN
  val[0] := val[0] + 1;
END ArrayValue;

PROCEDURE ArrayRef(VAR val : ARRAY OF T);
BEGIN
  val[0] := val[0] + 1;
END ArrayRef;

PROCEDURE Test1;
VAR
  a : ARRAY 20 OF T;
BEGIN
  a[0] := 0;

  ElemValue(a[0]); OutT(a[0]);

  ElemRef(a[0]); OutT(a[0]);

  ArrayValue(a); OutT(a[0]);

  ArrayRef(a); OutT(a[0]);
END Test1;

PROCEDURE Test2;
VAR
  a : POINTER TO ARRAY OF T;
BEGIN
  NEW(a, 20);
  a^[0] := 0;
  a[0] := 0;

  ElemValue(a[0]); OutT(a[0]);

  ElemRef(a^[0]); OutT(a[0]);

  ArrayValue(a^); OutT(a[0]);

  ArrayRef(a^); OutT(a[0]);
END Test2;
 
PROCEDURE Test3;
VAR
  a : POINTER TO ARRAY OF ARRAY OF T;
BEGIN
  NEW(a, 20, 20);
  a^[0][0] := 0;
  a[0][0] := 0;
  a^[0,0] := 0;
  a[0,0] := 0;

  ElemValue(a[0][0]); OutT(a[0,0]);

  ElemRef(a^[0][0]); OutT(a[0,0]);

  ArrayValue(a[0]); OutT(a[0,0]);

  ArrayRef(a^[0]); OutT(a[0,0]);
END Test3;

PROCEDURE Test*;
BEGIN
  Test1;
  Test2;
  Test3;
END Test;

END OpArray1.
