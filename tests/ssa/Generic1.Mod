MODULE Generic1;

TYPE
  Object* = POINTER TO ObjectDesc;
  ObjectDesc* = RECORD
    f*: LONGINT;
  END;
  
TYPE
  A1* = POINTER TO A1Desc;
  A1Desc* = RECORD
    (ObjectDesc)
  END;

TYPE
  A2* = POINTER TO A2Desc;
  A2Desc* = RECORD
    (A1Desc)
  END;
  
TYPE
  B*(Base: A1) = POINTER TO BDesc(Base);
  BDesc*(Base: A1) = RECORD 
    x: Base;
  END;

VAR
  b0-: B;
  b1-: B(A1);
  b2-: B(A2);

PROCEDURE (obj: Object) Id*(): LONGINT;
  BEGIN
    RETURN 123;
  END Id;

PROCEDURE (b: B) Set*(obj: BDesc.Base);
  VAR
    x: BDesc.Base;
  BEGIN
  END Set;

PROCEDURE (b: B) Get*(): BDesc.Base;
  VAR
    x: BDesc.Base;
  BEGIN
  END Get;

END Generic1.
