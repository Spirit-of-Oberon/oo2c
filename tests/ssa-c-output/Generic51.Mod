MODULE Generic51;
<*DerefCheck:=FALSE*>

TYPE
  Object* = POINTER TO ObjectDesc;
  ObjectDesc = RECORD
  END;
  
TYPE
  Entry(K: Object; V: Object) = RECORD
  END;
  Table(K: Object; V: Object) = POINTER TO ARRAY OF Entry(K, V);

TYPE
  Dictionary*(K: Object; V: Object) = POINTER TO DictionaryDesc(K, V);
  DictionaryDesc(K: Object; V: Object) = RECORD
    x: LONGINT;
    table: Table(K, V);
  END;

PROCEDURE (dict: Dictionary(K, V)) Resize*(): Table(K, V);
  VAR
    oldTable, newTable: Table(K, V);
  BEGIN
    oldTable := dict.table;
    NEW(newTable, 123);
    dict.table := newTable;
    RETURN oldTable;
  END Resize;

PROCEDURE Test*();
  VAR
    dict: Dictionary;
    x: Table;
  BEGIN
    NEW(dict);
    dict.table := NIL;
    x := dict.Resize();
    <*Assertions := TRUE*>
    ASSERT(x=NIL);
  END Test;

END Generic51.

