(* 	$Id: ProcessParameters.Mod,v 1.7 2003/08/22 09:04:34 mva Exp $	 *)
MODULE OS:ProcessParameters [FOREIGN "C"; LINK FILE "ProcessParameters.c" END];
(*  Handles information of the current process and user.
    Copyright (C) 2000, 2003  Michael van Acken

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
   function signature where appropriate.  *)

IMPORT
  Object, OS:Path, IO, IO:StdChannels;

PROCEDURE GetCwd*(): STRING
RAISES IO.Error;
(**Returns a string representing the current working directory.  *)

PROCEDURE GetEnv*(name: STRING): STRING;
(**If an environment variable @oparam{name} exists, then return its value.
   Otherwise, return @code{NIL}.  *)

END OS:ProcessParameters.
