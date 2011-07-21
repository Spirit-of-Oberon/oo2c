MODULE CodeMotion1;
<*DerefCheck:=FALSE*>

TYPE
  Node = POINTER TO NodeDesc;
  NodeDesc = RECORD
    value: LONGINT;
    next: Node; 
  END;
  
PROCEDURE P*(ptr: Node; x: Node; deref: BOOLEAN): LONGINT;
  VAR
    res: LONGINT;
  BEGIN
    res := 0;
    WHILE (ptr # NIL) DO
      IF deref THEN
        res := x.value;
      END;
      ptr := ptr.next;
    END;
    RETURN res;
  END P;

END CodeMotion1.
