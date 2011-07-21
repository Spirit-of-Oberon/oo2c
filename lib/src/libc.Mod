(* 	$Id: libc.Mod,v 1.3 2002/11/29 23:17:19 mva Exp $	 *)
MODULE libc [INTERFACE "C"];
(*  Basic data types for interfacing to C code.
    Copyright (C) 1997-1998  Michael van Acken

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
 
IMPORT
  C;
  
(**This module defines some C functions for the convenience of modules of the
   standard library.  The declarations may be changed, moved, or removed
   without prior notice.

   The module @omodule{C} holds type and constant definitions for often used
   entities, while this module declares functions.  The reason for this
   separation is that @samp{FOREIGN} or @samp{INTERFACE} modules must be able
   to import the definitions of @omodule{C}, without pulling in any function
   prototypes that clash with the standard headers of the C library.  *)
   
PROCEDURE strtod* (string: C.address;
                   VAR tailptr: C.charPtr1d): C.double;
PROCEDURE strtof* (string: C.address;
                   VAR tailptr: C.charPtr1d): C.float;
PROCEDURE sscanf* (s: C.address; template: ARRAY OF CHAR; ...) : C.int;
PROCEDURE sprintf* (VAR s: ARRAY OF CHAR; template: ARRAY OF CHAR; ...);
                        
END libc.
