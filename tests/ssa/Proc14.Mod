MODULE Proc14;

IMPORT SYSTEM;

TYPE
  T* = POINTER TO TDesc;
  TDesc = RECORD
  END;
  
PROCEDURE P (VAR y: SYSTEM.PTR);
  BEGIN
  END P;

PROCEDURE Test* ();
  VAR
    x: T;
  BEGIN
    NEW(x);
    P(x);
  END Test;

END Proc14.
