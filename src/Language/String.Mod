MODULE Language:String [OOC_EXTENSIONS];

IMPORT 
  L := Language;

TYPE
  Value* = POINTER TO ValueDesc;
  ValueDesc* = RECORD [ABSTRACT]
    (L.ValueDesc)
  END;

PROCEDURE Init* (v: Value; type: L.Type);
  BEGIN
    L.InitValue (v, type);
  END Init;

PROCEDURE (v: Value) [ABSTRACT] Length*(): LONGINT;
  END Length;

END Language:String.
