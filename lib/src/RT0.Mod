(* 	$Id$	 *)
MODULE RT0 [FOREIGN "C"; LINK FILE "__oo2c.c" END];
(*  Proxy module for the run-time system of C back-ends of OOC2
    Copyright (C) 2001  Michael van Acken

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

(**Proxy module for the run-time system.  This module is used to pull in the
   executable code of the run-time system, and to mark the place of the
   run-time system's header files.  This module's directory is added to the
   include path of the C compiler, so that __oo2c.h, __typemap.h, and so on,
   are picked up from here.

   The compiler implicitly adds an import to this module when building an
   executable.  A program may import this module directly, although there is
   currently no useful content in here.  *)

END RT0.
