MODULE Deprecated1;

CONST
  const*[DEPRECATED] = 123;

VAR
  var*[DEPRECATED]: INTEGER;

TYPE
  Record*[DEPRECATED] = RECORD
    field*[DEPRECATED]: INTEGER;
  END;

TYPE
  ClassA* = POINTER TO ClassADesc;
  ClassADesc = RECORD
  END;
  ClassB* = POINTER TO ClassBDesc;
  ClassBDesc = RECORD
    (ClassADesc)
  END;
  
VAR
  record*: Record;
  
PROCEDURE [DEPRECATED] Proc*();
  BEGIN
  END Proc;

PROCEDURE (a: ClassA) [DEPRECATED] TBProc*();
  BEGIN
  END TBProc;

PROCEDURE (b: ClassB) TBProc*();
  BEGIN
  END TBProc;

END Deprecated1.
