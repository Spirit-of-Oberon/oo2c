MODULE Iterator5;

IMPORT
  Out:=Out0;

TYPE
  Object* = POINTER TO ObjectDesc;
  ObjectDesc* = RECORD
    value: ARRAY 11+1 OF CHAR; 
  END;
  Iterator* = POINTER TO IteratorDesc;
  IteratorDesc* = RECORD
    obj: Object;
    i: LONGINT;
  END;

PROCEDURE (iter: Iterator) INIT*(obj: Object);
  BEGIN
    iter.obj := obj;
    iter.i := 0;
  END INIT;

PROCEDURE (iter: Iterator) Next*(VAR c: CHAR): BOOLEAN;
  BEGIN
    IF (iter.i = 11) THEN  (* omit trailing 0X *)
      RETURN FALSE;
    ELSE
      c := iter.obj.value[iter.i];
      INC(iter.i);
      RETURN TRUE;
    END;
  END Next;

PROCEDURE (obj: Object) INIT*(value: ARRAY OF CHAR);
  BEGIN
    COPY(value, obj.value);
  END INIT;

PROCEDURE (obj: Object) Chars*(): Iterator;
  BEGIN
    RETURN NEW(Iterator, obj);
  END Chars;

(*
PROCEDURE Test*();
  VAR
    o: Object;
    i: Iterator;
    c: CHAR;
  BEGIN
    o := NEW(Object, "Hello World");
    i := o.Chars();
    WHILE i.Next(c) DO
      Out.Char(c);
    END;
    Out.Ln;
  END Test;
*)

PROCEDURE Test*();
  VAR
    o: Object;
    c: CHAR;
  BEGIN
    o := NEW(Object, "Hello World");
    FOR c IN o.Chars() DO
      Out.Char(c);
    END;
    Out.Ln;
  END Test;

END Iterator5.
