MODULE M061;

TYPE
  Obj* = POINTER TO ObjDesc;
  ObjDesc* = RECORD END;
  
  B*(Base: Obj) = POINTER TO BDesc(Base);
  BDesc*(Base: Obj) = RECORD 
  END;

END M061.
