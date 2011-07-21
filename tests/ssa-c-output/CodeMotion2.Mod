MODULE CodeMotion2;
<*DerefCheck:=FALSE*>

TYPE
  Node = POINTER TO NodeDesc;
  NodeDesc = RECORD
    value: LONGINT;
    next: Node; 
  END;
  
PROCEDURE P*(ptr: Node; x: Node; deref: BOOLEAN): LONGINT;
  VAR
    y, res: LONGINT;
  BEGIN
    res := 0;
    WHILE (ptr # NIL) DO
      y := x.value;
      IF deref THEN
        res := y;
      END;
      ptr := ptr.next;
    END;
    RETURN res;
  END P;

END CodeMotion2.
