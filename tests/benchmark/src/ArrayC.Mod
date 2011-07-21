
MODULE ArrayC [INTERFACE "C"; LINK FILE "ArrayC.c" END];

IMPORT Type;

TYPE
  RealArray = Type.RealArray;

PROCEDURE ZeroArray1* (a : RealArray; len : LONGINT);

PROCEDURE ZeroArray2* (a : RealArray; len : LONGINT);

PROCEDURE ZeroArray4* (a : RealArray; len : LONGINT);

PROCEDURE ZeroArrayBlock* (a : RealArray; len : LONGINT);

PROCEDURE CopyArray1* (a, b : RealArray; len : LONGINT);

PROCEDURE CopyArray2* (a, b : RealArray; len : LONGINT);

PROCEDURE CopyArray4* (a, b : RealArray; len : LONGINT);

PROCEDURE CopyArrayBlock* (a, b : RealArray; len : LONGINT);

PROCEDURE AddArray1* (a, b : RealArray; len : LONGINT);

PROCEDURE AddArray2* (a, b : RealArray; len : LONGINT);

PROCEDURE AddArray4* (a, b : RealArray; len : LONGINT);

END ArrayC.
