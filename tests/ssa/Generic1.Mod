MODULE Generic1;

TYPE
  Object* = POINTER TO ObjectDesc;
  ObjectDesc* = RECORD
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
  B*<Base: A1> = POINTER TO BDesc<Base>;
  BDesc*<Base: A1> = RECORD 
    x: Base;
  END;

VAR
  b0-: B;
  b1-: B<A1>;
  b2-: B<A2>;

PROCEDURE (b: B) Set*(obj: B.Base);
  VAR
    x: B.Base;
  BEGIN
  END Set;

PROCEDURE (b: B) Get*(): B.Base;
  VAR
    x: B.Base;
  BEGIN
  END Get;

END Generic1.
