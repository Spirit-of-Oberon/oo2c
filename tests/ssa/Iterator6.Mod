MODULE Iterator6;

IMPORT
  Out:=Out0;

TYPE
  Object* = POINTER TO ObjectDesc;
  ObjectDesc* = RECORD
  END;
  Iterator* = POINTER TO IteratorDesc;
  IteratorDesc* = RECORD
  END;

PROCEDURE (iter: Iterator) INIT*();
  BEGIN
  END INIT;

PROCEDURE (iter: Iterator) Next*(VAR c: CHAR): BOOLEAN;
  BEGIN
    RETURN FALSE;
  END Next;

PROCEDURE (obj: Object) INIT*();
  BEGIN
  END INIT;

PROCEDURE (obj: Object) Chars*(): Iterator;
  BEGIN
    RETURN NEW(Iterator);
  END Chars;

PROCEDURE Test*();
  VAR
    o: Object;
    c: CHAR;
  BEGIN
    o := NEW(Object);
    FOR c IN o.Chars() DO
      Out.Char("X");
    END;
    Out.Ln;
  END Test;

END Iterator6.
