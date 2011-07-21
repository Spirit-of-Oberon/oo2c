MODULE Iterator7;

TYPE
  Iterator* = RECORD
  END;

PROCEDURE (VAR iter: Iterator) Next*(VAR c: CHAR): BOOLEAN;
  BEGIN
    RETURN FALSE;
  END Next;

PROCEDURE Test*();
  VAR
    iter: Iterator;
    c: CHAR;
  BEGIN
    FOR c IN iter DO
    END;
  END Test;

END Iterator7.
