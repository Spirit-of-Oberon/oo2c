MODULE Generic72;

TYPE
  Object* = POINTER TO ObjectDesc;
  ObjectDesc* = RECORD [ABSTRACT]
  END;
  Item*(K: Object) = RECORD
  END;
  ItemArrayPtr*(K: Object) = POINTER TO ARRAY OF Item(K);

VAR
  item  : Item(Object);
  items : ItemArrayPtr(Object);
    
PROCEDURE Test*();
  BEGIN
    item := items[0];
  END Test;

BEGIN
  NEW(items, 1);
END Generic72.
