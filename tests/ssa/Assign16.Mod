MODULE Assign16;

IMPORT
  Out:=Out0;

TYPE
  Alp = POINTER TO AlpDesc;
  AlpDesc = RECORD

  END;
  
VAR
  a: Alp;

PROCEDURE (self: Alp) INIT*;
BEGIN

END INIT;

PROCEDURE Dummy(): Alp;
BEGIN
  RETURN NIL;
END Dummy;

BEGIN
  Alp := a;
  Alp := Dummy();
  Alp := NEW(Alp);
END Assign16.
