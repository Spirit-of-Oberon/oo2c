MODULE M059;

TYPE
  Obj* = POINTER TO ObjDesc;
  ObjDesc* = RECORD END;
  BDesc*(Base: Obj) = RECORD 
  END;

END M059.
