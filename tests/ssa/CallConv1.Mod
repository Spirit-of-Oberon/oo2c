MODULE CallConv1;

TYPE

  CProc* = PROCEDURE ["C"] (VAR result : INTEGER);

  PascalProc* = PROCEDURE ["Pascal"] (VAR result : INTEGER);

  Proc* = PROCEDURE (VAR result : INTEGER);

  T* = POINTER TO TDesc;
  TDesc* = RECORD
  END;

PROCEDURE CExample* ["C"] (VAR result : INTEGER);
BEGIN
  result := 2;
END CExample;

PROCEDURE PascalExample* ["Pascal"] (VAR result : INTEGER);
BEGIN
  result := 1;
END PascalExample;

PROCEDURE Example* (VAR result : INTEGER);
BEGIN
  result := 0;
END Example;

PROCEDURE (t : T) CBound* ["C"] (VAR result : INTEGER);
BEGIN
  result := 2;
END CBound;

PROCEDURE (t : T) PascalBound* ["Pascal"] (VAR result : INTEGER);
BEGIN
  result := 1;
END PascalBound;

PROCEDURE (t : T) Bound* (VAR result : INTEGER);
BEGIN
  result := 0;
END Bound;

END CallConv1.
