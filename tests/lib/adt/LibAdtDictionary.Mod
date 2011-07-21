MODULE LibAdtDictionary;

IMPORT
  Out := Out0, Object,
  Dict := ADT:Dictionary, RND := RandomNumbers,
  (* the rest is only imported to see if it compiles: *)
  ADT:Dictionary:AddressKey, ADT:Dictionary:IntValue,
  AddressToInt := ADT:Dictionary:AddressKey:IntValue;

TYPE
  Obj* = POINTER TO ObjDesc;
  ObjDesc = RECORD
    (Object.ObjectDesc)
  END;


PROCEDURE TestFixedSize (size: LONGINT);
  VAR
    key, value: POINTER TO ARRAY OF Obj;
    i: LONGINT;
    dict: Dict.Dictionary;
  BEGIN
    Out.String ("Test fixed size "); Out.Int (size, 0); Out.Ln;
    NEW (key, size); NEW (value, size);
    FOR i := 0 TO size-1 DO
      NEW (key[i]); NEW (value[i])
    END;
    
    dict := Dict.New();
    ASSERT (dict. Size() = 0);
    FOR i := 0 TO size-1 DO
      ASSERT (~dict. HasKey (key[i]));
      dict. Set (key[i], value[i]);
      ASSERT (dict. HasKey (key[i]));
      ASSERT (dict. Get (key[i]) = value[i]);
      ASSERT (dict. Size() = i+1);
      (*keys := dict. Keys()*)
    END;
    ASSERT (dict. Size() = size);
    
    FOR i := 0 TO size-1 DO
      ASSERT (dict. Get (key[i]) = value[i]);
    END;
    Out.String ("done"); Out.Ln;
  END TestFixedSize;

PROCEDURE TestDelete (size: LONGINT);
  VAR
    key, oldKey, value: POINTER TO ARRAY OF Obj;
    i, j, refSize: LONGINT;
    dict: Dict.Dictionary;
  BEGIN
    Out.String ("Test delete "); Out.Int (size, 0); Out.Ln;
    NEW (key, size); NEW (oldKey, size); NEW (value, size);
    FOR i := 0 TO size-1 DO
      NEW (key[i]); oldKey[i] := key[i]; NEW (value[i])
    END;
    
    dict := Dict.New();
    FOR i := 0 TO size-1 DO
      ASSERT (key[i] # NIL);
      ASSERT (~dict. HasKey (key[i]));
      dict. Set (key[i], value[i]);
      ASSERT (dict. HasKey (key[i]));
      ASSERT (dict. Get (key[i]) = value[i]);
      ASSERT (dict. Size() = i+1);
    END;
    ASSERT (dict. Size() = size);
    
    refSize := size;
    FOR i := 0 TO size DIV 2 DO
      j := RND.RND (size);
      IF (key[j] # NIL) THEN
        ASSERT (dict. HasKey (key[j]));
        ASSERT (dict. Get (key[j]) = value[j]);
        dict. Delete (key[j]);
        ASSERT (~dict. HasKey (key[j]));
        DEC (refSize);
        ASSERT (dict. Size() = refSize);
        key[j] := NIL
      END
    END;
    
    FOR i := 0 TO size-1 DO
      IF (key[i] # NIL) THEN
        ASSERT (dict. HasKey (key[i]));
        ASSERT (dict. Get (key[i]) = value[i])
      ELSE
        ASSERT (~dict. HasKey (oldKey[i]));
      END
    END;
    Out.String ("done"); Out.Ln;
  END TestDelete;

PROCEDURE Test* ();
  BEGIN
    TestFixedSize (1);
    TestFixedSize (32);
    TestFixedSize (1024);
    
    TestDelete (16);
    TestDelete (1024);
    
    TestFixedSize (128*1024);
    TestDelete (128*1024);
  END Test;

END LibAdtDictionary.
