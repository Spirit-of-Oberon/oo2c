MODULE M;  (* -*-Mode: oberon-2-*- *)

IMPORT
  Object;

TYPE
  Key* = Object.Object;
  Value* = Object.Object;
  
TYPE
  Dictionary*(K: Key; V: Value) = POINTER TO DictionaryDesc(K, V);
  DictionaryDesc(K: Key; V: Value) = RECORD
  END;

PROCEDURE (dict: Dictionary(K, V)) INIT*;
  END INIT;

PROCEDURE New* (): Dictionary;
  END New;

PROCEDURE (dict: Dictionary(K, V)) Destroy*;
  END Destroy;

END M.
