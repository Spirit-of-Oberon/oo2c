MODULE M;


TYPE
  Class* = POINTER TO ClassDesc;
  ClassDesc = RECORD
    
  END;

PROCEDURE Init* (c: Class);
  END Init;

PROCEDURE New* (): Class;
  END New;

PROCEDURE (VAR c: ClassDesc) M1*;
  END M1;

PROCEDURE (c: Class) M2*;
  END M2;

END M.
