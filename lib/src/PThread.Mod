MODULE PThread [FOREIGN "C"; LINK LIB "pthread"; FILE "PThread.c" END];
<*Warnings := FALSE*>

IMPORT
  SYSTEM, RT0, Object, Exception;

(**This is an experimental and preliminary interface to the pthread library.
   Threads and exceptions are not integrated yet.  The garbage collector must
   have been compiled with pthread support as well, or the heap may go down in
   flames.  But I was not able to get this to work with a thread-safe gc at all
   on my Linux box.  And the heap went down in flames.  Which makes this module
   pretty useless for the moment.  *)
   
TYPE
  Error* = POINTER TO ErrorDesc;
  ErrorDesc = RECORD
    (Exception.ExceptionDesc)
    errorCode-: LONGINT;
  END;
  
TYPE
  Thread* = POINTER TO ThreadDesc;
  ThreadDesc* = RECORD [ABSTRACT]
    thread: SYSTEM.PTR;
  END;

TYPE
  Mutex* = POINTER TO MutexDesc;
  MutexDesc = RECORD
    mutex: SYSTEM.PTR;
  END;

PROCEDURE (e: Error) INIT*(msg: STRING; errno: LONGINT);

(* ------------------------------------------------------------------------ *)
  
PROCEDURE (t: Thread) INIT*();

PROCEDURE (t: Thread) [ABSTRACT] Run*();

PROCEDURE (t: Thread) Start*()
RAISES Error;
  
PROCEDURE (t: Thread) Join*()
RAISES Error;

(* ------------------------------------------------------------------------ *)

PROCEDURE (m: Mutex) INIT*();
  
PROCEDURE (m: Mutex) Lock*();

PROCEDURE (m: Mutex) Unlock*();

PROCEDURE (m: Mutex) Destroy*();

END PThread.
