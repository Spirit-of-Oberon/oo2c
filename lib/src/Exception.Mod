(* 	$Id$	 *)
MODULE Exception [FOREIGN "C"; LINK FILE "Exception.c" END];
(*  Implements the run-time part of the exceptions mechanism.
    Copyright (C) 2002,2003  Michael van Acken

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
   Push exception handler for this @code{TRY} block (@oproc{PushContext}).

   @item
   Evaluate @var{S}, followed by @oproc{PopContext}.  If there are any
   @code{RETURN} or @code{EXIT} statements within @var{S} that would cause
   control flow to leave the @code{TRY} statement, then they also do an
   implicit @oproc{PopContext} as part of the non-local exit.

   @item
   If an exception is raised during @var{S}, then do

   @example
   Exception.PopContext;
   temp := Exception.Current();
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

   An exception is raised by calling the predefined procedure @code{RAISE} with
   an instance of @otype{Exception}.  This passes control to the nearest
   @code{CATCH} clause whose type is an extension of the raised exception, if
   such a clause exist.  Otherwise, the exception is written to @var{stderr}
   and the program is aborted.

   Within a @code{CATCH}, the predefined variable @code{EXCEPTION} holds the
   value of @oproc{Current}.  Its type is the one given in the
   @code{CATCH} clause.  The variable is read-only.
   
   An exception @var{E} must either be caught within a procedure, or the
   procedure must declare that it may pass an exception of type @var{E} up to
   its caller.  For example,

   @example
   PROCEDURE P() RAISES E;
   @end example

   @noindent
   declares that evaluation of @samp{P} may raise an exception of type @var{E},
   or an extension thereof.

   Within the module body no exceptions can be passed up, because there is no
   caller.  As a consequence, any exception that is not caught explicity is
   written to @var{stderr} and aborts the program.

   @emph{Note}: A @code{TRY} block is mapped to C's @samp{setjmp()} function by
   @code{oo2c}.  The amount of data stored by this function depends on the
   target architecture and may differ by a factor of ten or more.  For example,
   on a @samp{ix86} processor, only 72 bytes are stored, while on a @samp{PPC}
   this is 768 bytes.  As a consequence, the work done within a @code{TRY}
   should be large enough to amortize the costs of the @code{TRY} for all
   possible targets.  *)

(*
   Each @code{TRY} block pushes an exception handler on a stack managed as a
   global variable of module Exception.  If threading is ever supported,
   then each thread needs its own pointer to the top of this stack, as
   well as its own `current' exception pointer.
*)

CONST
  maxBacktraceSize = 20+1;
  
TYPE
  Exception* = POINTER TO ExceptionDesc;
  ExceptionDesc* = RECORD
  (**An exception describes an anomalous condition that makes it impossible to
     complete a given task.  It provides a short, human readable text
     describing the problem.  If supported, it also includes information on the
     top few entries of the procedure call stack.  *)
    msg: STRING;
    backtrace: ARRAY maxBacktraceSize OF SYSTEM.PTR;
    backtraceSize: LONGINT;  (* -1 if backtrace() hasn't been called yet *)
  END;
  ContextPtr = POINTER TO Context;
  Context* = RECORD [NO_DESCRIPTOR]
  (**Use by the run-time system to store an execution context for later
     (re)use.  *)
    next: ContextPtr;
    jmpbuf: SYSTEM.PTR;
  END;

TYPE
  ParseError* = POINTER TO ParseErrorDesc;
  ParseErrorDesc = RECORD
    (**Indicates an error while parsing a string value.  *)
    (ExceptionDesc)
    offset-: LONGINT;
    (**The offset relative to the beginning of the parsed text where the
       error was found.  If this information is not available, then this
       field is @samp{-1}.  *)
  END;


PROCEDURE (e: Exception) INIT*(msg: STRING);
(**Initialize exception @oparam{e} and set @oparam{msg} as its message.
   @oparam{msg} may be @code{NIL}, but in this case
   @oproc{Exception.GetMessage} must be redefined to provide a non-@code{NIL}
   message.

   @precond
   @oparam{e} is not @code{NIL}.
   @end precond  *)
PROCEDURE Raise* [NO_RETURN](e: Exception) RAISES Exception;
(**Raise exception @oparam{e}.  On systems that support it, the first time this
   procedure is called with a given exception it stores the first few entries
   of the call stack.  This procedure is the implementation of the predefined
   procedure @code{RAISE}.

   @precond
   @oparam{e} is not @code{NIL}.
   @end precond  *)
PROCEDURE Current*(): Exception;
(**Pointer to the currently active exception.  This is @code{NIL}
   if no exception has been raised, or when a @code{CATCH} clause has been
   completed successfully for the last exception.  Within a @code{CATCH}
   block, the predefined read-only variable @samp{EXCEPTION} holds the
   same pointer value.  *)
  
PROCEDURE Clear*;
(**Set the current exception marker to @code{NIL}.  This procedure should never
   be called directly.  *)
PROCEDURE PushContext*(VAR context: Context; jmpbuf: SYSTEM.PTR);
(**Push @oparam{context} on the stack of exception handlers, and make it point
   to the execution context @oparam{jmpbuf}.  This procedure should never be
   called directly.  *)
PROCEDURE PopContext*(n: LONGINT);
(**Remove @oparam{n} entries from the top of exception handler stack.  This
   procedure should never be called directly.
   
   @precond
   @samp{@oparam{n} >= 1}.
   @end precond *)
PROCEDURE ActivateContext* [NO_RETURN]();
(**Activate the execution context on the top of the exception handler stack.
   If the stack is empty, a message with details of the current exception is
   written to @var{stderr}, and the program is aborted.  This procedure should
   never be called directly.  *)

PROCEDURE (e: Exception) GetMessage*(): STRING;
(**Return the message string describing the exception @oparam{e}.  *)
PROCEDURE (e: Exception) WriteBacktrace*;
(**If available, write the top-most entries of the call stack to @var{stderr}.
   This function uses the GNU function @samp{backtrace_symbols()} to produce
   its output.  Please see the documentation of GNU libc for more information
   on how to make function names available to the program.  The tool
   @samp{oobacktrace} may also be able to add function names to the output.  *)

PROCEDURE (e: ParseError) INIT*(msg: STRING; offset: LONGINT);
  
PROCEDURE FatalError*[NO_RETURN]();
(**Write data of current exception to @var{stderr} and abort program.  It is
   an error to call this procedure outside a @code{CATCH} block of a @code{TRY}
   statement.  *)
  
END Exception.
