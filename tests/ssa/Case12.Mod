MODULE Case12;

TYPE
  Node* = POINTER TO NodeDesc;
  NodeDesc = RECORD
  END;
  
PROCEDURE Qualident (): Node;
  BEGIN
    RETURN NIL;
  END Qualident;

PROCEDURE Type (level: LONGINT): Node;
  VAR
    type: Node;
  BEGIN
    CASE level OF
    | 555:
      type :=  Qualident();
    ELSE
      type :=  NIL
    END;
    RETURN type
  END Type;

END Case12.
