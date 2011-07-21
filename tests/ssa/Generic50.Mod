MODULE Generic50;

IMPORT Out:=Out0;
  
TYPE
  Object* = POINTER TO ObjectDesc;
  ObjectDesc = RECORD
  END;
  
TYPE
  Node* = POINTER TO NodeDesc;
  NodeDesc = RECORD
    (ObjectDesc)
  END;

TYPE
  Wrapper*(E: Object) = POINTER TO WrapperDesc(E);
  WrapperDesc(E: Object) = RECORD
    obj: Object;
  END;

PROCEDURE (o: Object) Type*();
  BEGIN
    Out.String("Object"); Out.Ln;
  END Type;

PROCEDURE (o: Node) Type*();
  BEGIN
    Out.String("Node"); Out.Ln;
  END Type;

PROCEDURE (w: Wrapper(E)) P();
  BEGIN
    w.obj.Type();
  END P;

PROCEDURE Test*();
  VAR
    w: Wrapper(Node);
  BEGIN
    NEW(w);
    w.obj := NEW(Node);
    w.P;
  END Test;

END Generic50.
