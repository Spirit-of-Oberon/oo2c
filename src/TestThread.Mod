MODULE TestThread;
<*Assertions := TRUE*>

IMPORT
  Log, Exception, Thread:PThread;

CONST
  arraySize = 1024;
  iterations = 1024*512;
  blockSize = 1024;
  blockCount = 1024;
  exceptionIterations = 1024*1024;
  
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

VAR
  count: LONGINT;
  countMutex: PThread.Mutex;
  countCondition: PThread.Condition;
  
PROCEDURE (t: Thread) INIT*(str: STRING; id: LONGINT);
  BEGIN
    t.INIT^();
    t.str := str;
    t.id := id;
    FOR i := 0 TO blockCount-1 DO
      t.blocks[i] := NIL;
    END;
  END INIT;

PROCEDURE (t: Thread) Sync*();
  BEGIN
    countMutex.Lock();
    INC(count);
    IF (count = 2) THEN
      Log.Object("Caught up with other thread", t.str);
      countCondition.Signal();
      count := 0;                        (* reset counter *)
    ELSE
      Log.Object("Delaying thread", t.str);
      countCondition.Wait(countMutex);
      Log.Object("Continuing after wait", t.str);
    END;
    countMutex.Unlock();
  END Sync;

PROCEDURE (t: Thread) Run*();
  VAR
    i, j: LONGINT;
    b: Block;
    e: Exception.Exception;
  BEGIN
    (* test exceptions *)
    Log.Object("Starting exceptions test", t.str);
    e := NEW(Exception.Exception, "Test123");
    FOR i := 1 TO exceptionIterations DO
      TRY
        RAISE(e);
      CATCH Exception.Exception:
        IF (Exception.Current() # e) THEN
          Log.Ptr("expected exception", e);
          Log.Ptr("but got exception", Exception.Current());
          ASSERT(FALSE);
        END;
      END;
    END;
    Log.Object("Exceptions test completed", t.str);
    t.Sync();
    
    (* test mutex *)
    Log.Object("Starting mutex test", t.str);
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
    t.Sync();
    
    (* test memory *)
    Log.Object("Starting heap test", t.str);
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
    t.Sync();
  END Run;

BEGIN
  FOR i := 0 TO arraySize-1 DO
    array[i] := 0;
  END;
  m := NEW(PThread.Mutex);

  count := 0;
  countMutex := NEW(PThread.Mutex);
  countCondition := NEW(PThread.Condition);
  
  a := NEW(Thread, "a", 1);
  b := NEW(Thread, "b", 2);
  TRY
    a.Start;
    b.Start;
    a.Join;
    b.Join;
  CATCH PThread.Error(e):
    Exception.Abort(e);
  END;
END TestThread.
