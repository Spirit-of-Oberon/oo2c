MODULE Generic39;

IMPORT G:=Generic1;
  
TYPE
  List*(E: G.Object) = POINTER TO ListDesc(E);
  ListDesc(E: G.Object) = RECORD
    (G.ObjectDesc)
    next: List(E);
    data: E;
  END;

PROCEDURE (l: List(E)) Get(i: LONGINT): E;
  BEGIN
    IF (i = 0) THEN
      RETURN l.data;
    ELSE
      RETURN l.next.Get(i-1);
    END;
  END Get;

END Generic39.
