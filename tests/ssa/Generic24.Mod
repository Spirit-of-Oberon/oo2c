MODULE Generic24;

IMPORT G:=Generic1;

TYPE
  ArrayList*(E: G.Object) = POINTER TO ArrayListDesc(E);
  ArrayListDesc*(E: G.Object) = RECORD
    (G.ObjectDesc)
    x-: POINTER TO ARRAY OF E;
  END;

PROCEDURE (l: ArrayList(E)) Copy1*(): ArrayList(E);
  VAR
    x: ArrayList(E);
  BEGIN
    x := NIL;
    x := l;
    RETURN x;
  END Copy1;

PROCEDURE (l: ArrayList(E)) Copy2*(): ArrayList(E);
  BEGIN
    RETURN l;
  END Copy2;

END Generic24.
