MODULE Language:INTEGER;

IMPORT
  Language, Language:Integer;


TYPE
  Builtin* = INTEGER;

CONST
  min* = MIN (Builtin);
  max* = MAX (Builtin);
  sizeInWords* = SIZE (INTEGER);
  sizeInBits* = SIZE (INTEGER)*Language.bitsPerWord;

VAR
  type-: Integer.Type;
  
BEGIN
  type := Integer.NewType (sizeInWords, sizeInBits, min, max)
END Language:INTEGER.
