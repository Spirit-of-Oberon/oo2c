MODULE Generic47;

IMPORT G:=Generic1;
  
TYPE
  ArrayList*(E: G.Object) = POINTER TO ArrayListDesc(E);
  ArrayListDesc*(E: G.Object) = RECORD
  END;

TYPE
  Document* = POINTER TO DocumentDesc;
  DocumentDesc = RECORD
    usedImportsList-: ArrayList;
  END;

PROCEDURE New* (initialSize: LONGINT): ArrayList;
  BEGIN
    RETURN NIL;
  END New;

PROCEDURE (l: ArrayList(E)) Append* (obj: E);
  END Append;

PROCEDURE (d: Document) P*(importDecl: G.A1);
  BEGIN
    IF (d. usedImportsList = NIL) THEN
      d. usedImportsList := New(2);
    END;
    (* ... *)
    d. usedImportsList. Append (importDecl)
  END P;

END Generic47.
