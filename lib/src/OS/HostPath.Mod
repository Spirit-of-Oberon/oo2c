
MODULE OS:HostPath [FOREIGN "C"; LINK FILE "HostPath.c" END];

(*  Normalisation of OS file names. 

    Copyright (C) 2003  Stewart Greenhill

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

(**Operating systems differ in the syntax of file names and paths.

   Unix paths are simple and systematic. The "/" symbol separates path
   elements. Paths with a leading separator are absolute; otherwise the path
   is relative to the user's current working directory.

   Paths in Microsoft Windows are more problematic. Typically "\" is used as a
   path separator, but "/" is also permitted. Paths with a leading separator
   are relative to the user's current working drive. Paths with a leading
   drive specifier may be absolute or relative. For example, "C:\test" is an
   absolute path, whereas "C:test" is relative the the user's current
   directory on drive "C".

   In order to avoid exposing OS-specific details such as "drives" and
   "working directory per drive", native host OS paths are converted into a
   "normalized" form in which:

   @itemize @bullet
   @item
   The symbol "/" separates path elements.
   
   @item 
   Absolute paths begin with a path separator.

   @item
   Special symbols such as "\" and ":" (used in Windows) are not present in 
   the path. This means that normalized paths may form part of URIs.
   @end itemize

   Normalized paths may be converted back to native OS paths. However, during
   normalization relative paths may be converted to absolute paths so a
   denormalized relative path may no longer be relative.

*)

(**Normalisation of Microsoft Windows paths:

   @itemize @bullet

   @item
   Backslash is converted to forward slash.
 
   @item
   Drive identifier "C:" is converted to "/C$".

   @item
   Drive-relative paths (eg. C:test) are converted to absolute paths by
   replacing the drive identifier with the user's current working directory on
   that drive.
 
   @end itemize 

   Denormalisation of Microsoft Windows paths:

   @itemize @bullet

   @item
   Backslashes cause problems in many contexts since they are often used as
   escape characters. Windows usually treats forward and back slashes
   equivalently, so we retain only forward slashes.

   @item (HACK) OOC sometimes treats paths like "c:/.." as relative,
   erroneously applying transformations on repository paths. For now, we treat
   all absolute paths as relative to the CURRENT drive.

   @end itemize
*)

IMPORT
<*WITH Warnings:=FALSE DO*>
  Msg, LongStrings, CharClass, C;
<*END*>

TYPE
  Result* = Msg.Msg;
  Path* = ARRAY OF CHAR;

CONST
  done* = NIL;
  (**Value of parameter @samp{res} after successful completion.  *)

CONST
  pathTooLong* = 0;
  (**The buffer passed to @oproc{Normalize} or @oproc{Denormalize} is too small
     to hold the string representation of the transformed path. *)

 TYPE
  ErrorContext = POINTER TO ErrorContextDesc;
  ErrorContextDesc = RECORD
    (Msg.ContextDesc)
  END;

VAR
<*WITH Warnings:=FALSE DO*>
  errorContext: ErrorContext;
<*END*>

PROCEDURE Normalize* (VAR path : ARRAY OF CHAR; VAR res : Msg.Msg);
(**Convert path from host OS to normal form. *)

PROCEDURE Denormalize* (VAR path : ARRAY OF CHAR; VAR res : Msg.Msg);
(**Convert path from normal to host OS form. *)

END OS:HostPath.
