MODULE OpTypeGuard6;

IMPORT Out := Out0;

TYPE
  A = POINTER TO ADesc; ADesc = RECORD END;
  B = POINTER TO BDesc; BDesc = RECORD (ADesc) x: INTEGER; END;

PROCEDURE Do (VAR a: ADesc);
  BEGIN
    a(BDesc). x := 1;
  END Do;

PROCEDURE Test*;
  VAR
    a: ADesc;
  BEGIN
    Do(a);
  END Test;

END OpTypeGuard6.
