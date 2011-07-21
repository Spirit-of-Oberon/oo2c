MODULE LibSTRING8;

IMPORT
  Out := Out0, Object;

TYPE
  MyObject* = POINTER TO MyObjectDesc;
  MyObjectDesc = RECORD
    (Object.ObjectDesc) 
  END;
  
PROCEDURE Write (s: MyObject);
  END Write;

PROCEDURE Test*;
  BEGIN
    Write("bar");
  END Test;
  
END LibSTRING8.
