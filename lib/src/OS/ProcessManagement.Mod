(* 	$Id: ProcessManagement.Mod,v 1.3 2003/05/18 11:28:59 mva Exp $	 *)
MODULE OS:ProcessManagement [FOREIGN "C"; LINK FILE "ProcessManagement.c" END];
(*  Creation and management of processes.
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

(**This is a subset of the @samp{Process Management} section of Python's
   @samp{os} package.  If you want to add to this module, use the Python
   function signature and add a parameter @samp{res} instead of raising
   an exception.  *)

IMPORT
  C, Object, OS:Path;

PROCEDURE system* (command: STRING): C.int;
(**Executes the command in a subshell.  This is implemented by calling the
   Standard C function @samp{system()}, and has the same limitations.  The
   return value is the exit status of the process encoded in the format
   specified for @samp{wait()}.  Note that POSIX does not specify the meaning
   of the return value of the C @samp{system()} function, so the return value
   of this Oberon-2 function is system-dependent.

   @oproc{Path.Encode} is used to calculate the character array that is passed
   to the OS.  *)

PROCEDURE ExitStatus* (status : C.int) : C.int;
(**Returns the exit status for the command executed by @samp{system()}. If the
   process terminated abnormally (eg. due to a signal), the value -1 is
   returned. *)

PROCEDURE TermSignal* (status : C.int) : C.int;
(**Returns the termination signal for the command executed by @samp{system()}.
   If the process terminated normally, the value -1 is returned. *)

END OS:ProcessManagement.
