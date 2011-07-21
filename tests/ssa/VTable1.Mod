MODULE VTable1;

IMPORT
  Out := Out0, SYSTEM;
TYPE
  VR* = POINTER TO VRDesc;

  VRDesc* = RECORD [VTABLE]
  END;

PROCEDURE (v : VR) T*;
BEGIN
  Out.String("T()"); Out.Ln;
END T;

PROCEDURE Test*;
VAR v : VR;
BEGIN
  NEW(v);
  Out.String("Size of object is "); Out.Int(SIZE(VRDesc), 0); Out.Ln;
  v.T();
END Test;

END VTable1.
