MODULE Language:Integer;

IMPORT 
  L := Language,
  I := Language:IntegerType;

TYPE
  Type* = I.Type;
  Value* = I.Value;
  
VAR
  type- : Type;

PROCEDURE New*(value : INTEGER) : Value;
BEGIN
  RETURN type.Value(value)
END New;

BEGIN
  type := I.NewType(MIN(INTEGER), MAX(INTEGER));
END Language:Integer.
