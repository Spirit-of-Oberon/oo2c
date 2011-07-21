MODULE Array;

<* IndexCheck := FALSE *> 
<* DerefCheck := FALSE *> 

IMPORT 
  Type, SYSTEM;

(* Operations on real arrays *)

TYPE
  RealArray = Type.RealArray;

PROCEDURE ZeroArray1* (a : RealArray; len : LONGINT);
VAR i : LONGINT;
BEGIN
  i := 0;
  WHILE i < len DO
    a[i] := 0;
    INC(i,1);
  END;
END ZeroArray1;

PROCEDURE ZeroArray2* (a : RealArray; len : LONGINT);
VAR i : LONGINT;
BEGIN
  i := 0;
  WHILE i < len DO
    a[i] := 0;
    a[i+1] := 0;
    INC(i,2);
  END;
END ZeroArray2;

PROCEDURE ZeroArray4* (a : RealArray; len : LONGINT);
VAR i : LONGINT;
BEGIN
  i := 0;
  WHILE i < len DO
    a[i] := 0;
    a[i+1] := 0;
    a[i+2] := 0;
    a[i+3] := 0;
    INC(i,4);
  END;
END ZeroArray4;

PROCEDURE CopyArray1* (a, b : RealArray; len : LONGINT);
VAR i : LONGINT;
BEGIN
  i := 0;
  WHILE i < len DO
    b[i] := a[i];
    INC(i,1);
  END;
END CopyArray1;

PROCEDURE CopyArray2* (a, b : RealArray; len : LONGINT);
VAR i : LONGINT;
BEGIN
  i := 0;
  WHILE i < len DO
    b[i] := a[i];
    b[i+1] := a[i+1];
    INC(i,2);
  END;
END CopyArray2;

PROCEDURE CopyArray4* (a, b : RealArray; len : LONGINT);
VAR i : LONGINT;
BEGIN
  i := 0;
  WHILE i < len DO
    b[i] := a[i];
    b[i+1] := a[i+1];
    b[i+2] := a[i+2];
    b[i+3] := a[i+3];
    INC(i,4);
  END;
END CopyArray4;

PROCEDURE CopyArrayMove* (a, b : RealArray; len : LONGINT);
BEGIN
  SYSTEM.MOVE(SYSTEM.VAL(SYSTEM.ADDRESS,a), 
	SYSTEM.VAL(SYSTEM.ADDRESS,b), len * SIZE(REAL));
END CopyArrayMove;

PROCEDURE AddArray1* (a, b : RealArray; len : LONGINT);
VAR i : LONGINT;
BEGIN
  i := 0;
  WHILE i < len DO
    b[i] := b[i] + a[i];
    INC(i,1);
  END;
END AddArray1;

PROCEDURE AddArray2* (a, b : RealArray; len : LONGINT);
VAR i : LONGINT;
BEGIN
  i := 0;
  WHILE i < len DO
    b[i] := b[i] + a[i];
    b[i+1] := b[i+1] + a[i+1];
    INC(i,2);
  END;
END AddArray2;

PROCEDURE AddArray4* (a, b : RealArray; len : LONGINT);
VAR i : LONGINT;
BEGIN
  i := 0;
  WHILE i < len DO
    b[i] := b[i] + a[i];
    b[i+1] := b[i+1] + a[i+1];
    b[i+2] := b[i+2] + a[i+2];
    b[i+3] := b[i+3] + a[i+3];
    INC(i,4);
  END;
END AddArray4;

END Array.
