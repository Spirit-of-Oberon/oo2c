MODULE Generic79;

IMPORT Object;
  
TYPE
  Entry(E : Object.Object) = POINTER TO EntryDesc(E);
  EntryDesc(E : Object.Object) = RECORD (Object.ObjectDesc)
  END;

  LinkedList*(E : Object.Object) = POINTER TO LinkedListDesc(E);
  LinkedListDesc*(E : Object.Object) = RECORD
    size-: LONGINT;
  END;

PROCEDURE (l: LinkedList(E)) Equals* (obj: Object.Object);
  VAR
    e2 : Entry(E);
  BEGIN
    WITH obj : Entry(E) DO
      e2 := obj;
    END;
  END Equals;

END Generic79.
