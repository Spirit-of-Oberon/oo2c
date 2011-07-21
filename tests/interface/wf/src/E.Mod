MODULE E;

VAR
  a*: INTEGER;
  b-: INTEGER;
  c: INTEGER;

TYPE someType* = INTEGER;

TYPE
  Class* = POINTER TO ClassDesc;
  ClassDesc* = RECORD
  END;

PROCEDURE P* (someType: someType);
  END P;

PROCEDURE (c: Class) Method*;
(**This is an exported type-bound procedure.  The receiver is @oparam{c}.  *)
  END Method;

END E.
