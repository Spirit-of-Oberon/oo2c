MODULE TestThread;

IMPORT
  Log, Exception, PThread;

CONST
  arraySize = 1024;
  iterations = 1024*512;
  blockSize = 1024;
  blockCount = 1024;
  
TYPE
  Block = POINTER TO ARRAY blockSize OF LONGINT;
  Thread = POINTER TO ThreadDesc;
  ThreadDesc = RECORD
    (PThread.ThreadDesc)
    str: STRING;
    id: LONGINT;
    blocks: ARRAY blockCount OF Block;
  END;
  
VAR
  a, b: Thread;
  array: ARRAY arraySize OF LONGINT;
  i: LONGINT;
  m: PThread.Mutex;
  
PROCEDURE (t: Thread) INIT*(str: STRING; id: LONGINT);
  BEGIN
    t.INIT^();
    t.str := str;
    t.id := id;
    FOR i := 0 TO blockCount-1 DO
      t.blocks[i] := NIL;
    END;
  END INIT;

PROCEDURE (t: Thread) Run*();
  VAR
    i, j: LONGINT;
    b: Block;
  BEGIN
    (* test mutex *)
    FOR i := 1 TO iterations DO
      m.Lock;
      FOR j := 0 TO arraySize-1 DO
        IF (j # 0) THEN
          (* without the mutex, this will eventually fail *)
          ASSERT(array[j-1]-1 = array[j]);
        END;
        INC(array[j]);
      END;
      m.Unlock;
    END;
    Log.Object("Mutex test completed", t.str);
    
    (* test memory *)
    FOR i := 1 TO 100000 DO
      b := t.blocks[i MOD blockCount];
      IF (b # NIL) THEN
        FOR j := 0 TO blockSize-1 DO
          IF (b[j] # t.id) THEN
            Log.LongInt("expected", t.id);
            Log.LongInt("but got", b[j]);
            ASSERT(FALSE);
          END;
        END;
      END;
      
      NEW(b);
      FOR j := 0 TO blockSize-1 DO
        b[j] := t.id;
      END;
      t.blocks[i MOD blockCount] := b;
    END;
    Log.Object("Heap test completed", t.str);
  END Run;

BEGIN
  FOR i := 0 TO arraySize-1 DO
    array[i] := 0;
  END;
  m := NEW(PThread.Mutex);
      
  a := NEW(Thread, "a", 1);
  b := NEW(Thread, "b", 2);
  TRY
    a.Start;
    b.Start;
    a.Join;
    b.Join;
  CATCH PThread.Error:
    Exception.FatalError();
  END;
END TestThread.
