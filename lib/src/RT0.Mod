(* 	$Id$	 *)
MODULE RT0 [FOREIGN "C"; LINK FILE "RT0.c" END];
(*  Proxy module for the run-time system of C back-ends of OOC2
    Copyright (C) 2001, 2002  Michael van Acken

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
   executable.  A program may import this module directly, for example to gain
   access to meta data embedded by the compiler into a module's object file.
   Please note that this module should be considered a part of the compiler,
   @emph{not} of the standard library.  As such, it may differ across different
   compiler implementations, and for a given compiler its interface might
   change without prior notice.  *)

IMPORT
  SYSTEM;

  
CONST  (* predefined types, taken from `OOC:SymbolTable:Predef' *)
  strBoolean* = 0;
  strChar* = 1;
  strShortint* = 3;
  strInteger* = 4;
  strLongint* = 5;

CONST
  strArray* = -1;
  (**An array definition with a fixed length, as in @samp{ARRAY 123 OF
     CHAR}.  *)

  strOpenArray* = -2;
  (**An array definition with an unspecified length, as in @samp{ARRAY OF
     CHAR}.  *)

  strRecord* = -3;
  (**A record, either in its C @code{struct} or @code{union} variant.  *)
  
  strPointer* = -4;
  (**A pointer definition of the form @samp{POINTER TO T}.  *)
  
TYPE
  Struct* = POINTER TO StructDesc;
  StructDesc = RECORD [NO_DESCRIPTOR, NOT_EXTENSIBLE]
    (**A type description.

       @table @code
       @item ARRAY n OF @dots{}
       @itemize @bullet
       @item @ofield{form} equals @oconst{strArray}.

       @item @ofield{len} holds the length of the array, for example @samp{123}
       for an @samp{ARRAY 123 OF CHAR}.

       @item @ofield{base} is the type descriptor of the array's
       element type, for example @ovar{char} for @samp{ARRAY 123 OF CHAR}.
       @end itemize


       @item ARRAY OF @dots{}
       @itemize @bullet
       @item @ofield{form}
       equals @oconst{strOpenArray}.

       @item @ofield{len} holds the number of
       open dimensions, for example @samp{1} for an @samp{ARRAY OF CHAR}.

       @item @ofield{base} is the type descriptor of the array's base type, for
       example @ovar{char} for @samp{ARRAY OF CHAR} or @samp{ARRAY OF ARRAY OF
       CHAR}.  The base type always has a known size, that is, it is neven an
       open array type.
       @end itemize


       @item RECORD @dots{} END
       @itemize @bullet
       @item @ofield{form} equals @oconst{strRecord}.

       @item @ofield{len} is the extension level of the record.  A record
       without a base type has a level of @samp{0}.  Every extension level
       increments this level by one.

       @item @ofield{base} is the type descriptor of the record's base type, or
       @code{NIL} if the record has no base type.
       @end itemize


       @item POINTER TO @dots{}
       @itemize @bullet
       @item @ofield{form} equals @oconst{strPointer}.

       @item @ofield{base} is the base type of the pointer.
       @end itemize

       @end table  *)

    base-: Struct;
    (**Element type, pointer base type, or record base type.  *)

    size-: LONGINT;
    (**Size of the data type in bytes.  For an open array type, this field is
       @samp{-1}.  *)
    
    len-: LONGINT;
    (**Holds the length of an array, the number of open dimensions
       of an open array, or the extension level of a record.  *)
    
    form-: SHORTINT;
    (**Identifies which kind of type constructor variant is used.  *)
  END;

TYPE
  Name* = POINTER TO ARRAY [NO_LENGTH_INFO, NO_DESCRIPTOR] OF CHAR;
  Object* = POINTER TO ObjectDesc;
  ObjectDesc = RECORD [NO_DESCRIPTOR, NOT_EXTENSIBLE]
    (**A named object defined in a declaration.  *)
  END;

VAR
  boolean-: StructDesc;
  char-: StructDesc;
  shortint-: StructDesc;
  integer-: StructDesc;
  longint-: StructDesc;

PROCEDURE NewObject* (td: Struct; ...): SYSTEM.PTR;
(**Allocates a new array or record variable on the heap, using the type
   descriptor @oparam{td}.  For an open array object, the lengths of the
   array's dimensions are passed as second, third, and so on, parameter.  They
   must be of type @code{LONGINT}.  *)
   
END RT0.
