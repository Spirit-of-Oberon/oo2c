(* 	$Id$	 *)
MODULE OS:Files [FOREIGN "C"; LINK FILE "Files.c" 
  <*IF HAVE_LIB_MINGWEX THEN *> ; LIB "mingwex" <* END *>
  END];
(*  Manipulation of file and directory entries.
    Copyright (C) 2000, 2002  Michael van Acken

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
   function signature and add a parameter @samp{res} instead of raising
   an exception.  *)

IMPORT
  Msg, LongStrings, CharClass;

TYPE
  Result* = Msg.Msg;
  Path* = ARRAY OF CHAR;
  Mode* = LONGINT;
  (**File creation mask.  *)
  Name* = POINTER TO ARRAY OF CHAR;
  NameArray* = POINTER TO ARRAY OF Name;
  
CONST
  done* = NIL;
  (**Value of parameter @samp{res} after successful completion.  *)
  
CONST
  accessDenied* = 1;
  (**Write permission is denied for the parent directory in which
     the new directory is to be added.  *)
  fileExists* = 2;
  (**A file named `path' already exists.  *)
  writeError* = 3;
  (**Any other error, e.g. too many links in the parent directory, no
     space left in the file system, or the file system is read-only.  *)
  fileBusy* = 4;
  (**This error indicates that the file is being used by the
     system in such a way that it can't be unlinked.  For example,
     you might see this error if the file name specifies the root
     directory or a mount point for a file system.  *)
  noSuchFile* = 5;
  (**The file name to be deleted doesn't exist.  *)
  
    
CONST
  defaultMode* = 0*512 + 7*64 + 7*8 + 7*1;
  (**Default file creation mask (octal 0777).  Minus the flags cleared through
     @samp{umask}, all permission bits are set.  *)

TYPE
  ErrorContext = POINTER TO ErrorContextDesc;
  ErrorContextDesc = RECORD
    (Msg.ContextDesc)
  END;

VAR
  errorContext: ErrorContext;
  

PROCEDURE (context: ErrorContext) GetTemplate* (msg: Msg.Msg; VAR templ: Msg.LString);

PROCEDURE listdir* (path: Path; VAR res: Result): NameArray;
(**Return a list containing the names of the entries in the directory.  The
   list is in arbitrary order.  It does not include the special entries
   @samp{.} and @samp{..}, even if they are present in the directory.  *)
  
PROCEDURE mkdir* (path: Path; mode: Mode; VAR res: Result);
(**Creates directory @oparam{path} in the local file system with numeric mode
   @oparam{mode}.  On some systems, @oparam{mode} is ignored. Where it is used,
   the current @samp{umask} value is first masked out.  On success, the
   value of @oparam{res} is @code{NIL}.  Otherwise, it is a reference to an
   error message.  *)

PROCEDURE makedirs* (path: Path; mode: Mode; VAR res: Result);
(**Recursive directory creation function. Like @oproc{mkdir}, but makes all
   intermediate-level directories needed to contain the leaf directory. 
   This procedure does nothing if the target directory already exists.
   If the leaf directory does not exists and cannot be created, an error
   message is returned in @oparam{res}.  Otherwise, @oparam{res} is set to
   @code{NIL}.  [Note: Python actually considers it an error if the directory
   @oparam{path} already exists.  Should we do the same?] *)

PROCEDURE remove* (path: Path; VAR res: Result);
(**Removes the file @oparam{path}.  *)

END OS:Files.
