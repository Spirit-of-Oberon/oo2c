MODULE Generic24;

IMPORT G:=Generic1;

TYPE
  ArrayList*(E: G.Object) = POINTER TO ArrayListDesc(E);
  ArrayListDesc*(E: G.Object) = RECORD
    (G.ObjectDesc)
    x-: POINTER TO ARRAY OF E;
  END;

PROCEDURE (l: ArrayList) Copy1*(): ArrayList(ArrayListDesc.E);
  VAR
    x: ArrayList(ArrayListDesc.E);
  BEGIN
    x := NIL;
    x := l;
    RETURN x;
  END Copy1;

PROCEDURE (l: ArrayList) Copy2*(): ArrayList(ArrayListDesc.E);
  BEGIN
    RETURN l;
  END Copy2;

END Generic24.
