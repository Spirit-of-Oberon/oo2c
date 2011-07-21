MODULE CodeMotion3;
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
    y := x.value;
    WHILE (ptr # NIL) DO
      IF deref THEN
        res := y;
      END;
      ptr := ptr.next;
    END;
    RETURN res;
  END P;

END CodeMotion3.
