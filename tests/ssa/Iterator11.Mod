MODULE Iterator11;

TYPE
  Iterator* = POINTER TO IteratorDesc;
  IteratorDesc* = RECORD
  END;

PROCEDURE (iter: Iterator) Next*(VAR c: CHAR): BOOLEAN;
  BEGIN
    RETURN FALSE;
  END Next;

PROCEDURE Test*();
  VAR
    iter: Iterator;
    c: LONGCHAR;
  BEGIN
    NEW(iter);
    FOR c IN iter DO
    END;
  END Test;

END Iterator11.
