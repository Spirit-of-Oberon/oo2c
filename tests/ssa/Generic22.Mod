MODULE Generic22;

IMPORT G:=Generic1;

TYPE
  ArrayList*<E: G.Object> = POINTER TO ArrayListDesc<E>;
  ArrayListDesc*<E: G.Object> = RECORD
    (G.ObjectDesc)
    x-: POINTER TO ARRAY OF E;
  END;

PROCEDURE (l: ArrayList) Copy1*(): ArrayList<ArrayList.E>;
  VAR
    x: ArrayList<ArrayList.E>;
  BEGIN
    x := l;
    RETURN x;
  END Copy1;

PROCEDURE (l: ArrayList) Copy2*(): ArrayList<ArrayList.E>;
  BEGIN
    RETURN l;
  END Copy2;

END Generic22.
