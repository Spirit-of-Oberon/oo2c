(* 	$Id$	 *)
MODULE RT0 [FOREIGN "C"; LINK FILE "RT0.c"; LIB "m" END];
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
   change without prior notice.

   Note: The math library @samp{libm} is always linked in for the sake of the
   predefined function @code{ENTIER}.  *)

IMPORT
  SYSTEM;

  
CONST  (* predefined types, taken from `OOC:SymbolTable:Predef' *)
  strBoolean* = 0;
  strChar* = 1;
  strLongchar* = 2;
  strShortint* = 3;
  strInteger* = 4;
  strLongint* = 5;
  strSet32* = 9;
  strByte* = 10;
  strPtr* = 11;

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
  Name* = POINTER TO ARRAY [NO_LENGTH_INFO, NO_DESCRIPTOR] OF CHAR;
  Module* = POINTER TO ModuleDesc;
  Struct* = POINTER TO StructDesc;
  StructDesc = RECORD [NO_DESCRIPTOR, NOT_EXTENSIBLE]
    (**A type description.

       @table @code
       @item ARRAY n OF @dots{}
       @itemize @bullet
       @item @ofield{form} equals @oconst{strArray}.

       @item @ofield{len} holds the length of the array, for example @samp{123}
       for an @samp{ARRAY 123 OF CHAR}.

       @item @samp{@ofield{baseTypes}[0]} is the type descriptor of the array's
       element type, for example @ovar{char} for @samp{ARRAY 123 OF CHAR}.
       @end itemize


       @item ARRAY OF @dots{}
       @itemize @bullet
       @item @ofield{form}
       equals @oconst{strOpenArray}.

       @item @ofield{len} holds the number of
       open dimensions, for example @samp{1} for an @samp{ARRAY OF CHAR}.

       @item @samp{@ofield{baseTypes}[0]} is the type descriptor of the array's
       base type, for example @ovar{char} for @samp{ARRAY OF CHAR} or
       @samp{ARRAY OF ARRAY OF CHAR}.  The base type always has a known size,
       that is, it is neven an open array type.
       @end itemize


       @item RECORD @dots{} END
       @itemize @bullet
       @item @ofield{form} equals @oconst{strRecord}.

       @item @ofield{len} is the extension level of the record.  A record
       without a base type has a level of @samp{0}.  Every extension level
       increments this level by one.

       @item @ofield{baseTypes} lists the type descriptors of the record's base
       types.  The array has a length of @samp{@ofield{len}+1}, with
       @samp{baseTypes[len]} being equal to the type descriptor itself,
       @samp{baseTypes[len-1]} being the descriptor of the direct base type,
       and so on.
       @end itemize


       @item POINTER TO @dots{}
       @itemize @bullet
       @item @ofield{form} equals @oconst{strPointer}.

       @item @samp{@ofield{baseTypes}[0]} is the base type of the pointer.
       @end itemize

       @end table  *)

    baseTypes-: POINTER TO ARRAY [NO_LENGTH_INFO, NO_DESCRIPTOR] OF Struct;
    (**Array element type, pointer base type, or list of record base types.
       For predefined scalar types this field is @code{NIL}.  *)
    
    tbProcs-: POINTER TO ARRAY [NO_LENGTH_INFO, NO_DESCRIPTOR] OF SYSTEM.PTR;
    (**Table of type-bound procedures of a record type.  This field is
       @code{NIL} for all other types.  *)

    module-: Module;
    (**The module that defines this type descriptor.  For predefined types,
       this is a reference to module @samp{RT0}.  *)

    name-: Name;
    (**Type name.  @code{NIL} for anonymous types.  *)

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
  Object* = POINTER TO ObjectDesc;
  ObjectDesc = RECORD [NO_DESCRIPTOR, NOT_EXTENSIBLE]
    (**A named object defined in a declaration.  *)
  END;

TYPE
  ModuleDesc = RECORD
    name-: Name;
    (**Name of the module.  *)

    typeDescriptors-: POINTER TO ARRAY [NO_LENGTH_INFO, NO_DESCRIPTOR] OF Struct;
    (**All type descriptors of this module that correspond to named types
       defined on the top level.  Descriptors are listed in no particular
       order.  The last element of the array has the value @code{NIL}.  *)
  END;
  
VAR
  boolean-: StructDesc;
  char-: StructDesc;
  longchar-: StructDesc;
  shortint-: StructDesc;
  integer-: StructDesc;
  longint-: StructDesc;
  set32-: StructDesc;
  byte-: StructDesc;
  ptr-: StructDesc;

VAR
  argc-: LONGINT;
  argv-: POINTER TO ARRAY [NO_LENGTH_INFO, NO_DESCRIPTOR] OF
                      POINTER TO ARRAY [NO_LENGTH_INFO, NO_DESCRIPTOR] OF CHAR;


PROCEDURE NewObject* (td: Struct; ...): SYSTEM.PTR;
(**Allocates a new array or record variable on the heap, using the type
   descriptor @oparam{td}.  For an open array object, the lengths of the
   array's dimensions are passed as second, third, and so on, parameter.  They
   must be of type @code{LONGINT}.  *)

PROCEDURE TypeOf* (ptr: SYSTEM.PTR): Struct;
(**Returns the type of the record pointer @oparam{ptr}.  The address
   @oparam{ptr} must be a previous result of @oproc{NewObject}.  Result is
   undefined if @oparam{ptr} is not a reference to a record object.  *)

PROCEDURE NewBlock* (bytes: LONGINT): SYSTEM.PTR;
(**Allocates a memory block on the heap with a size of at least @oparam{bytes}
   bytes.  Pointers in the allocated block are ignored during garbage
   collection.  That is, the block must not contain any references to objects
   on the heap that are not kept live by other pointers.  *)

PROCEDURE FreeBlock* (ptr: SYSTEM.PTR);
(**Frees a block of memory allocated with @oproc{NewBlock}.  *)

PROCEDURE InitVParStack* (bytes: LONGINT);
(**Allocates the heap block that serves as a stack for value parameters of
   open array type.  It is used as a fallback if no mechanism is available
   to store the data on the normal C stack.  This procedure is called once,
   from the program's setup code.  *)


PROCEDURE ErrorIndexOutOfRange* (mid: Module; pos: LONGINT;
                                 index, length: LONGINT);
PROCEDURE ErrorDerefOfNil* (mid: Module; pos: LONGINT);
PROCEDURE ErrorFailedTypeGuard* (mid: Module; pos: LONGINT; typeTag: Struct);
PROCEDURE ErrorFailedCase* (mid: Module; pos: LONGINT; select: LONGINT);
PROCEDURE ErrorFailedWith* (mid: Module; pos: LONGINT; typeTag: Struct);
PROCEDURE ErrorFailedTypeAssert* (mid: Module; pos: LONGINT);
PROCEDURE ErrorFailedFunction* (mid: Module; pos: LONGINT);
PROCEDURE ErrorAssertionFailed* (mid: Module; pos: LONGINT; code: LONGINT);
PROCEDURE Halt* (code: LONGINT);

PROCEDURE RegisterModule* (mid: Module);
(**Registers the module descriptor with the run-time system.  *)

PROCEDURE ThisModule* (name: ARRAY OF CHAR): Module;
(**Returns the module descriptor for the module @oparam{name}.  Result is
   @code{NIL} if no module of this name has been registered.  *)
  
PROCEDURE ThisType* (mid: Module; name: ARRAY OF CHAR): Struct;
(**Returns the type descriptor for the type @oparam{name} of module
   @oparam{mid}.  Result is @code{NIL} if there is not such type descriptor.  *)

PROCEDURE GetEnv* (name: ARRAY OF CHAR; VAR value: ARRAY OF CHAR): BOOLEAN;
(**If an environment variable @oparam{name} exists, copy its value into
   @oparam{value} and return @code{TRUE}.  Otherwise, return @code{FALSE}.  *)

END RT0.
