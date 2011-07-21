MODULE Generic64;

TYPE
  A* = POINTER TO ADesc;
  ADesc = RECORD
  END;

TYPE
  B* = POINTER TO BDesc;
  BDesc = RECORD
    (ADesc)
  END;

PROCEDURE (a: A) INIT*();
  BEGIN
  END INIT;

PROCEDURE (b: B) INIT*();
  BEGIN
    (*b.INIT^();*)
  END INIT;

END Generic64.
