MODULE OpRecord1;

IMPORT
  Out := Out0;

TYPE
  T = SHORTINT;

  R = POINTER TO RDesc;
  RDesc = RECORD
    i : T;
    c : CHAR;
  END;

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

PROCEDURE RecordValue(val : RDesc);
BEGIN
  val.i := val.i + 1;
END RecordValue;

PROCEDURE RecordRef(VAR val : RDesc);
BEGIN
  val.i := val.i + 1;
END RecordRef;

PROCEDURE RecordPtr(val : R);
BEGIN
  val.i := val.i + 1;
END RecordPtr;

PROCEDURE Test1;
VAR
  r : RDesc;
BEGIN
  r.i := 0;

  ElemValue(r.i); OutT(r.i);

  ElemRef(r.i); OutT(r.i);

  RecordValue(r); OutT(r.i);

  RecordRef(r); OutT(r.i);
END Test1;

PROCEDURE Test2;
VAR
  r : R;
BEGIN
  NEW(r);

  r.i := 0;

  ElemValue(r.i); OutT(r.i);

  ElemRef(r.i); OutT(r.i);

  RecordValue(r^); OutT(r.i);

  RecordRef(r^); OutT(r.i);
END Test2;
 
PROCEDURE Test3;
VAR
  r : R;
BEGIN
  NEW(r);

  r^.i := 0;

  ElemValue(r^.i); OutT(r.i);

  ElemRef(r^.i); OutT(r.i);

  RecordValue(r^); OutT(r.i);

  RecordPtr(r); OutT(r.i);
END Test3;

PROCEDURE Test*;
BEGIN
  Test1;
  Test2;
  Test3;
END Test;

END OpRecord1.
