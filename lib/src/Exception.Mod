MODULE Exception [FOREIGN "C"; LINK FILE "Exception.c" END];
<*Warnings:=FALSE*>

IMPORT
  SYSTEM, RT0, Object;

(**The statement 

   @example
   TRY
     S
   CATCH T1:
     C1
   CATCH T2:
     C2
   END;
   @end example

   is roughly equivalent to

   @enumerate
   @item
   Push exception handler for this TRY block (Exception.PushContext).

   @item
   Evaluate S, followed by Exception.PopContext.  If there are any
   RETURN or EXIT statements within S that would cause control flow to
   leave the TRY statement, then they also do an implicit PopContext.

   @item
   If an exception is raised during S, then

   @example
   Exception.PopContext;
   WITH temp: T1 DO
     C1;
   | temp: T2 DO
     C2;
   ELSE
     Exception.ActivateContext;
   END;
   Exception.Clear;
   @end example
   @end enumerate
*)

(*
   Each TRY block pushes an exception handler on a stack managed as a
   global variable of module Exception.  If threading is ever supported,
   then each thread needs its own pointer to the top of this stack, as
   well as its own `current' exception pointer.
*)

CONST
  maxBacktraceSize = 20+1;
  
TYPE
  Exception* = POINTER TO ExceptionDesc;
  ExceptionDesc* = RECORD
    msg: STRING;
    backtrace: ARRAY maxBacktraceSize OF SYSTEM.PTR;
    backtraceSize: LONGINT;
  END;
  ContextPtr = POINTER TO Context;
  Context* = RECORD [NO_DESCRIPTOR]
    next: ContextPtr;
    jmpbuf: SYSTEM.PTR;
  END;
  
PROCEDURE Init*(e: Exception; msg: STRING);
(**Initialize exception @oparam{e} and set @oparam{msg} as its message.
   On systems that support it, this also stores the first few entries of
   the call stack.  *)
PROCEDURE Raise*(e: Exception) RAISES Exception;
(**Raise exception @oparam{e}.  *)
PROCEDURE Current*(): Exception;
(**Pointer to the currently active exception.  This is @code{NIL}
   if no exeception has been raised, or when a @code{CATCH} clause has been
   completed successfully for the last exception.  *)
  
PROCEDURE Clear*;
(**Set the current exception marker to @code{NIL}.  This procedure should never
   be called directly.  *)
PROCEDURE PushContext*(VAR context: Context; jmpbuf: SYSTEM.PTR);
(**Push @oparam{context} on the stack of exception handlers, and make it point
   to the execution context @oparam{jmpbuf}.  This procedure should never be
   called directly.  *)
PROCEDURE PopContext*(n: LONGINT);
(**Remove @oparam{n} entries from the top of exception handler stack.  This
   procedure should never be called directly.  *)
PROCEDURE ActivateContext*;
(**Activate the execution context on the top of the exception handler stack.
   If the stack is empty, a message with details of the current exception is
   written to @samp{var}, and the program is aborted.  This procedure should
   never be called directly.  *)

PROCEDURE (e: Exception) GetMessage*(): STRING;
(**Return the message string describing the exception @oparam{e}.  *)
PROCEDURE (e: Exception) WriteBacktrace*;
(**If available, write the top-most entries of the call stack to @var{stderr}.
   This function uses the GNU function @samp{backtrace_symbols()} to produce
   its output.  Please see the documentation of GNU libc for more information
   on how to make function names available to the program.  The tool
   @samp{oobacktrace} may also be able to add function names to the output.  *)
END Exception.
