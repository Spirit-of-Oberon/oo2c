MODULE Generic49;

IMPORT G:=Generic1;
  
TYPE
  Key* = G.Object;
  Value* = G.Object;
  Entry(K: Key; V: Value) = RECORD
    hash: LONGINT;
  END;
  Table(K: Key; V: Value) = POINTER TO ARRAY OF Entry(K, V);
  Dictionary*(K: Key; V: Value) = POINTER TO DictionaryDesc(K, V);
  DictionaryDesc(K: Key; V: Value) = RECORD
  END;
    
PROCEDURE (dict: Dictionary(K, V)) Resize (newSize: LONGINT);
  VAR
    i: LONGINT;
    newTable: Table(K, V);
  BEGIN
    NEW (newTable, newSize);
    FOR i := 0 TO newSize-1 DO
      newTable[i]. hash := 0
    END;
  END Resize;

END Generic49.
