MODULE LibException38;

IMPORT Exception;
  
TYPE
  Iterator* = POINTER TO IteratorDesc;
  IteratorDesc* = RECORD
  END;

PROCEDURE (iter: Iterator) Next*(VAR c: CHAR): BOOLEAN
RAISES Exception.Checked;
  BEGIN
    RETURN FALSE;
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

END LibException38.
