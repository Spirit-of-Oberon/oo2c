MODULE M060;

TYPE
  Obj* = POINTER TO ObjDesc;
  ObjDesc* = RECORD END;
  BDesc*(Base: Obj) = RECORD
    x: Base;
  END;

END M060.
