MODULE Iterator9;

TYPE
  Iterator* = POINTER TO IteratorDesc;
  IteratorDesc* = RECORD
  END;

PROCEDURE (iter: Iterator) Next*(VAR c: CHAR): CHAR;
  BEGIN
    RETURN 0X;
  END Next;

PROCEDURE Test*();
  VAR
    iter: Iterator;
    c: CHAR;
  BEGIN
    NEW(iter);
    FOR c IN iter DO
    END;
  END Test;

END Iterator9.
