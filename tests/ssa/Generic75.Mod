MODULE Generic75;

TYPE
  Alp* = POINTER TO AlpDesc;
  AlpDesc = RECORD
  END;

PROCEDURE (self: Alp) INIT*(): LONGINT;
BEGIN
  RETURN 0;
END INIT;

END Generic75.
