MODULE Language:Integer;

IMPORT 
  L := Language,
  I := Language:IntegerType;

VAR
  type- : I.Type;

PROCEDURE New*(value : INTEGER) : I.Value;
BEGIN
  RETURN type.Value(value)
END New;

BEGIN
  type := I.NewType(MIN(INTEGER), MAX(INTEGER));
END Language:Integer.
