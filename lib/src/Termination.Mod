(*	$Id$	*)
MODULE Termination [FOREIGN "C"; LINK FILE "Termination.c" END];
(*  Provides procedures for program finalization.
    Copyright (C) 1997  Michael van Acken

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
(* preliminary version ... *)

TYPE
  Proc* = PROCEDURE;
  
PROCEDURE RegisterProc* (proc: Proc);
(* Adds `proc' to the list of procedures executed at program termination.
   Procedures are called in reverse order of registration.  
   Note: The registered procedures will be called on normal program 
   termination, if an error signal is raised, or if an termination signal
   is raised. *)
  
PROCEDURE UnregisterProc* (proc: Proc);
(* Removes `proc' from the list of procedures executed at program termination.
   The last procedure equal to `proc' is removed.  Nothing is done if `proc'
   hasn't been registered before.  *)
  
END Termination.
