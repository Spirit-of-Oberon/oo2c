MODULE Assign2;

TYPE
  R = RECORD END;

VAR
  r: R;

PROCEDURE (VAR r: R) TBProc ();
  BEGIN
  END TBProc;

BEGIN
  r. TBProc := 2;
END Assign2.
