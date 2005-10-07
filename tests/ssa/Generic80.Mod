MODULE Generic80;

IMPORT Object;
  
TYPE
  Entry(E : Object.Object) = POINTER TO EntryDesc(E);
  EntryDesc(E : Object.Object) = RECORD (Object.ObjectDesc)
    next, previous : Entry(E);
    element : E;
  END;

  LinkedList*(E : Object.Object) = POINTER TO LinkedListDesc(E);
  LinkedListDesc*(E : Object.Object) = RECORD
    (Object.ObjectDesc)
    elements : Entry(E);
    size-: LONGINT;
  END;

PROCEDURE (l: LinkedList(E)) Equals* (obj: Object.Object): BOOLEAN;
  VAR
    e2 : Entry(E);
  BEGIN
    WITH obj : LinkedList(E) DO
      e2 := obj.elements.next;
    END;
  END Equals;

END Generic80.
