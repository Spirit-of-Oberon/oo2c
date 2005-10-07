MODULE Generic84;

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
  
PROCEDURE (VAR e: EntryDesc(E)) Init*(x: Object.Object);
  BEGIN
    e.x := x(E);
  END Init;
  
PROCEDURE (VAR e: EntryDesc(E)) Eql* (obj: Object.Object): BOOLEAN;
  BEGIN
    WITH obj: E DO
      RETURN e.x = obj;
    ELSE
      RETURN FALSE;
    END;
  END Eql;

PROCEDURE Test*;
  VAR
    o1: Object.Object;
    e1: Entry(Object.Object);
  BEGIN
    o1 := NEW(Data);
    e1 := NEW(Entry(Object.Object));
    e1^.Init(o1);
    Out.Bool(e1^.Eql(o1)); Out.Ln;
    Out.Bool(e1^.Eql(e1)); Out.Ln;
  END Test;
  
END Generic84.
