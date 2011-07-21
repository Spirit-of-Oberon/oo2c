MODULE Generic77;

IMPORT Object;
  
TYPE
  Entry(E : Object.Object) = POINTER TO EntryDesc(E);
  EntryDesc(E : Object.Object) = RECORD (Object.ObjectDesc)
    next, previous : Entry(E);
    element : E;
  END;

  LinkedList*(E : Object.Object) = POINTER TO LinkedListDesc(E);
  LinkedListDesc*(E : Object.Object) = RECORD
    elements : Entry(E);
    size-: LONGINT;
  END;

PROCEDURE (l : LinkedList(E)) RemoveEntry(e : Entry(E));
BEGIN
  ASSERT(e # l.elements);
END RemoveEntry;

END Generic77.
