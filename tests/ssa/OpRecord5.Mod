MODULE OpRecord5;

TYPE
  R = POINTER TO RDesc;
  RDesc = RECORD
    i : INTEGER;
  END;

PROCEDURE RecordPtr(val : R);
BEGIN
  val.i := val.i + 1;
END RecordPtr;

PROCEDURE Test*;
BEGIN
  RecordPtr(NIL);
END Test;

END OpRecord5.
