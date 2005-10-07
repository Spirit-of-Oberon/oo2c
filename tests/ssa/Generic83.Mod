MODULE Generic83;

IMPORT Object, Out:=Out0;
  
TYPE
  Entry(E: Object.Object) = POINTER TO EntryDesc(E);
  EntryDesc(E: Object.Object) = RECORD
    (Object.ObjectDesc)
    x: E;
  END;
  Data = POINTER TO DataDesc;
  DataDesc = RECORD
    (Object.ObjectDesc)
  END;
  
PROCEDURE (e: Entry(E)) INIT*(x: Object.Object);
  BEGIN
    e.x := x(E);
  END INIT;
  
PROCEDURE (e: Entry(E)) Equals* (obj: Object.Object): BOOLEAN;
  BEGIN
    WITH obj: E DO
      RETURN e.x = obj;
    ELSE
      RETURN FALSE;
    END;
  END Equals;

PROCEDURE Test*;
  VAR
    o1: Object.Object;
    e1: Entry(Object.Object);
  BEGIN
    o1 := NEW(Data);
    e1 := NEW(Entry(Object.Object), o1);
    Out.Bool(e1.Equals(o1)); Out.Ln;
    Out.Bool(e1.Equals(e1)); Out.Ln;
  END Test;
  
END Generic83.
