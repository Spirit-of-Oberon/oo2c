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

PROCEDURE (l: ArrayList) Append* (obj: ArrayListDesc.E);
  END Append;

PROCEDURE (d: Document) P*(importDecl: G.A1);
  BEGIN
    d. usedImportsList. Append (importDecl)
  END P;

END Generic47.
