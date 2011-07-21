(* 	$Id: PThread.Mod,v 1.7 2003/10/02 08:00:48 mva Exp $	 *)
MODULE Thread:PThread [FOREIGN "C"; LINK LIB "pthread"; FILE "PThread.c" END];
(*  Interface for ths POSIX threads library.
    Copyright (C) 2003  Michael van Acken

    This module is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public License
    as published by the Free Software Foundation; either version 2 of
    the License, or (at your option) any later version.

    This module is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with OOC. If not, write to the Free Software Foundation,
    59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*)
<*Warnings := FALSE*>

IMPORT
  SYSTEM, RT0, Object, Exception;

(**This is an experimental and preliminary interface to the pthread library.
   The garbage collector must have been compiled with pthread support as well,
   or the heap may go down in flames.  See the source code of
   @file{liboo2c.xml} for on overview of library modules that are not
   multi-threading safe (most notably, @omodule{*Files} and
   @omodule{*IO:FileChannel}.  *)
   
TYPE
  Error* = POINTER TO ErrorDesc;
  ErrorDesc = RECORD
    (Exception.CheckedDesc)
    errorCode-: LONGINT;
  END;

TYPE
  Thread* = POINTER TO ThreadDesc;
  ThreadDesc* = RECORD [ABSTRACT]
    (Object.ObjectDesc)
    (* Note: Reading an attribute of this object is only safe within its own
       thread of control.  Accessed from other threads, the results are
       undefined unless the two threads are explicitky synchronized.  *)
    exceptionState: Exception.ThreadState;
    (* The garbage collector does not see and thread local storage, so
       we must make sure a reference to the current exception is always life
       in an area it @emph{can} see.  *)
    thread: SYSTEM.PTR;
    (* FIXME... under Linux and Solaris pthread_t is actually an integer type
       (long or unsigned), which triggers a warning under 64 bit Solaris *)
  END;

TYPE
  Mutex* = POINTER TO MutexDesc;
  MutexDesc = RECORD
    mutex: SYSTEM.PTR;
  END;

TYPE
  Condition* = POINTER TO ConditionDesc;
  ConditionDesc = RECORD
    cond: SYSTEM.PTR; 
  END;


PROCEDURE (e: Error) INIT*(msg: STRING; errno: LONGINT);
PROCEDURE CheckError*(errorCode: LONGINT; fatal: BOOLEAN) RAISES Error;
  
(* ------------------------------------------------------------------------ *)
  
PROCEDURE (t: Thread) INIT*();

PROCEDURE (t: Thread) [ABSTRACT] Run*();

PROCEDURE (t: Thread) RunWrapper();

PROCEDURE (t: Thread) Start*()
RAISES Error;
  
PROCEDURE (t: Thread) Join*()
RAISES Error;

PROCEDURE CurrentThread*(): Thread;
(**Return the current @otype{Thread} object, corresponding to the caller's
   thread of control.  This is guaranteed to be a non-@code{NIL} value.  *)
  
(* ------------------------------------------------------------------------ *)

PROCEDURE (m: Mutex) INIT*();
  
PROCEDURE (m: Mutex) Lock*();

PROCEDURE (m: Mutex) Unlock*();

PROCEDURE (m: Mutex) Destroy*();

PROCEDURE (m: Mutex) TryLock*(): BOOLEAN;
(**Behaves identically to @oproc{Mutex.Lock}, except that it does not block
   the calling thread if the mutex is already locked by another thread (or by
   the calling thread in the case of a "fast" mutex).  Instead, this method
   returns immediatly with @code{FALSE}.  *)
  
(* ------------------------------------------------------------------------ *)

PROCEDURE (c: Condition) INIT*();
  
PROCEDURE (c: Condition) Signal*();

PROCEDURE (c: Condition) Broadcast*();

PROCEDURE (c: Condition) Wait*(m: Mutex);

PROCEDURE (c: Condition) TimedWait*(m: Mutex; absTime: LONGREAL): BOOLEAN;
(**Return @code{TRUE} if the condition is signaled before time
   @oparam{absTime} is reached.  @oparam{absTime} is the number of seconds
   since Jan 01 1970 00:00 GMT.  *)

PROCEDURE (c: Condition) Destroy*();

END Thread:PThread.
