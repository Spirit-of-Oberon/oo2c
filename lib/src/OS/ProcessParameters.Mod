(* 	$Id$	 *)
MODULE OS:ProcessParameters [FOREIGN "C"; LINK FILE "ProcessParameters.c" END];
(*  Handles information of the current process and user.
    Copyright (C) 2000  Michael van Acken

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
<* Warnings := FALSE *>

(**This is a subset of the @samp{Process Parameters} section of Python's
   @samp{os} package.  If you want to add to this module, use the Python
   function signature and add a parameter @samp{res} instead of raising
   an exception.  *)

IMPORT
  Msg, LongStrings, CharClass, C;

TYPE
  Result* = Msg.Msg;
  Path* = ARRAY OF CHAR;
  
CONST
  done* = NIL;
  (**Value of parameter @samp{res} after successful completion.  *)

CONST
  invalidBuffer* = 1;
  (**The character array passed to @oproc{getcwd} is empty.  *)
  cwdTooLong* = 2;
  (**The buffer passed to @oproc{getcwd} is too small to hold the string
     representation of the current working directory.  *)
  accessDenied* = 3;
  (**Permission to read or search a component 
     of the current working directory was denied.  *)
    
TYPE
  ErrorContext = POINTER TO ErrorContextDesc;
  ErrorContextDesc = RECORD
    (Msg.ContextDesc)
  END;

VAR
  errorContext: ErrorContext;
  

PROCEDURE getcwd* (VAR buffer: Path; VAR res: Result);
(**Returns a string representing the current working directory.  *)

END OS:ProcessParameters.
