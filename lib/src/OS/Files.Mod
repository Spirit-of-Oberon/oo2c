(* 	$Id: Files.Mod,v 1.10 2003/06/10 23:20:00 mva Exp $	 *)
MODULE OS:Files [FOREIGN "C"; LINK FILE "Files.c";
  <*IF HAVE_LIB_MINGWEX THEN*> LIB "mingwex"; <*END*>
  END];
(*  Manipulation of file and directory entries.
    Copyright (C) 2000, 2002, 2003  Michael van Acken

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

(**This is a subset of the @samp{Files & Directories} section of Python's
   @samp{os} package.  If you want to add to this module, use the Python
   function signature where appropriate.  *)

IMPORT
  Object, OS:Path, IO, IO:StdChannels;

TYPE
  Mode* = LONGINT;
  (**File creation mask.  *)
  NameArray* = POINTER TO ARRAY OF STRING;
  Time* = LONGREAL;
  (**Number of seconds elapsed since 00:00:00 on January 1, 1970, Coordinated
     Universal Time.  Subsecond resolution depends on the function used to
     retrieve the time value, and the operating system in use.  *)
  
CONST
  defaultMode* = 0*512 + 7*64 + 7*8 + 7*1;
  (**Default file creation mask (octal 0777).  Minus the flags cleared through
     @samp{umask}, all permission bits are set.  *)


PROCEDURE ListDir*(path: STRING): NameArray
RAISES IO.Error;
(**Return a list containing the names of the entries in the directory.  The
   list is in arbitrary order.  It does not include the special entries
   @samp{.} and @samp{..}, even if they are present in the directory.  *)
  
PROCEDURE MkDir*(path: STRING; mode: Mode)
RAISES IO.Error;
(**Creates directory @oparam{path} in the local file system with numeric mode
   @oparam{mode}.  On some systems, @oparam{mode} is ignored. Where it is used,
   the current @samp{umask} value is first masked out.  *)

PROCEDURE MakeDirs*(path: STRING; mode: Mode)
RAISES IO.Error;
(**Recursive directory creation function. Like @oproc{MkDir}, but makes all
   intermediate-level directories needed to contain the leaf directory. 
   This procedure does nothing if the target directory already exists.
   If the leaf directory does not exists and cannot be created, an exception
   is raised.  [Note: Python actually considers it an error if the directory
   @oparam{path} already exists.  Should we do the same?] *)

PROCEDURE Remove*(path: STRING)
RAISES IO.Error;
(**Removes the file @oparam{path}.  *)

PROCEDURE Exists*(path: STRING): BOOLEAN;
(**Return @code{TRUE} if an entity @oparam{path} exists.  *)

PROCEDURE MTime*(path: STRING): Time
RAISES IO.Error;
(**Return modification time of the indicated file.  *)
  
END OS:Files.
