(* 	$Id: RT0.Mod,v 1.51 2004/12/15 13:07:21 mva Exp $	 *)
MODULE RT0 [
  FOREIGN "C";
  LINK
    FILE "RT0.c";
    <*IF HAVE_LIB_DL THEN*>LIB "dl";<*END*>
    <*IF HAVE_LIB_GC THEN*>
      <*IF HAVE_LIB_DL THEN*>
        LIB "gc" ("dl");
      <*ELSE*>
        LIB "gc";
      <*END*>
    <*END*>
    <*IF HAVE_LIB_M THEN*>LIB "m";<*END*>
  END ];
(*  Proxy module for the run-time system of C back-ends of OOC2
    Copyright (C) 2001, 2002, 2003, 2004  Michael van Acken

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
   include path of the C compiler, so that @file{__oo2c.h}, @file{__typemap.h},
   and so on, are picked up from here.

   The compiler implicitly adds an import for this module to every module.  A
   program may import this module directly, for example to gain access to meta
   data embedded by the compiler into a module's object file.  Please note that
   this module should be considered a part of the compiler, @emph{not} of the
   standard library.  As such, it may differ across different compiler
   implementations, and for a given compiler its interface might change without
   prior notice.

   Note: The math library @samp{libm} is always linked in for the sake of the
   predefined function @code{ENTIER}.  *)

IMPORT
  SYSTEM;

  
CONST  (* predefined types, taken from `OOC:SymbolTable:Predef' *)
  strBoolean* = 0;
  strChar* = 1;
  strLongchar* = 2;
  strUCS4Char* = 3;
  strShortint* = 4;
  strInteger* = 5;
  strLongint* = 6;
  strReal* = 7;
  strLongreal* = 8;
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

  strQualType* = -5;
  (**A qualified type, specifying type arguments for a parametric type's
     parameter list.  *)

  strProcedure* = -6;
  (**A procedure type.  Currently, all procedure types are mapped onto the
     single type descriptor @ovar{procedure}, even though they may differ in
     the number, type or mode of their parameters, or their result type.  *)
  
CONST
  flagAtomic* = 0;
  (**Indicates that this record type does not contain any references that
     need to be considered by the garbage collector.  It may be allocated as
     an atomic object. *)

  flagVTable* = 1;
  (**Indicates that this record type has a vtable entry which must be
     initialised by @oproc{NewObject}. *)

  flagFinalize* = 2;
  (**Indicates that this record type has a Finalize procedure which should be
     called by the run-time system upon collection by the GC. This flag is set
     by the compiler for record types that override the method
     @oproc{ObjectDesc.Finalize}.  *)

TYPE
  Object* = POINTER TO ObjectDesc;
  ObjectDesc* = RECORD
  END;

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
       @samp{ARRAY OF ARRAY OF CHAR}.  The base type always has a known size;
       that is, it is never an open array type.
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


       @item @var{T}(@var{A1},@var{A2},@dots{})
       @itemize @bullet
       @item @ofield{form} equals @oconst{strQualType}.

       @item @ofield{name} is a fully expanded qualified type constructor
       of the form @samp{T(A1,A2,...)}, where @samp{T}, @samp{A1}, @samp{A2},
       and so on, are qualified type names.
       
       @item @samp{@ofield{typeArgs}[0]} is the base type of the qualified
       type (the @var{T} in the example above).

       @item @samp{@ofield{typeArgs}[1, 2, @dots{}]} are the type arguments
       (@var{A1}, @var{A2}, and so on) followed by @code{NIL}.

       @item All other fields hold a value equivalent to the corresponding
       field in the qualified type's base type.
       
       @end itemize

       @end table  *)

    baseTypes-: POINTER TO ARRAY [NO_LENGTH_INFO, NO_DESCRIPTOR] OF Struct;
    (**Array element type, pointer base type, or list of record base types.
       For predefined scalar types this field is @code{NIL}.  *)
    
    tbProcs-: POINTER TO ARRAY [NO_LENGTH_INFO, NO_DESCRIPTOR] OF SYSTEM.PTR;
    (**Table of type-bound procedures of a record type.  This field is
       @code{NIL} for all other types.  *)

    typeArgs-: POINTER TO ARRAY [NO_LENGTH_INFO, NO_DESCRIPTOR] OF Struct;
    (**For a qualified type @oconst{strQualType}, this array holds the base
       type followed by the type arguments applied to the base type, followed
       by @code{NIL}.  For all other types, this field is @code{NIL}.  *)
    
    module-: Module;
    (**The module that defines this type descriptor.  For predefined types,
       this is a reference to module @samp{RT0}.  *)

    name-: Name;
    (**Type name.  @code{NIL} for anonymous types.  For instances of
       @oconst{strQualType}, this is a fully expanded qualified type
       constructor of the form @samp{T(A1,A2,...)}.  *)

    size-: LONGINT;
    (**Size of the data type in bytes.  For an open array type, which has
       no static size of its own, this field is size of the first element
       type that is not an open array.  *)
    
    len-: LONGINT;
    (**Holds the length of an array, the number of open dimensions
       of an open array, or the extension level of a record.  *)
    
    flags-: SET;
    (**Holds attributes that control the way the run-time deals with values of
       this type (eg. see @oconst{flagAtomic}, @oconst{flagVTable}). *)

    form-: SHORTINT;
    (**Identifies which kind of type constructor variant is used.  *)

	(* Careful: fields declared after here will be after any padding generated
	   to align @ofield{form}. This means that initialisers might not do the
       right thing unless values are also emitted for the pad fields. *)

  END;

(*TYPE
  Object* = POINTER TO ObjectDesc;
  ObjectDesc = RECORD [NO_DESCRIPTOR, NOT_EXTENSIBLE]
    (**A named object defined in a declaration.  *)
  END;*)

TYPE
  ModuleDesc = RECORD
    name-: Name;
    (**Name of the module.  *)

    typeDescriptors-: POINTER TO ARRAY [NO_LENGTH_INFO, NO_DESCRIPTOR] OF Struct;
    (**All type descriptors of this module that correspond to named types
       defined on the top level.  Descriptors are listed in no particular
       order.  The last element of the array has the value @code{NIL}.  *)

    openCount-: LONGINT;
    (**Number of times this module's @code{open()} function has been called
       from client modules.  At the same time, this is the number of client
       modules actively using this module.  *)
  END;

TYPE
  CaseRange* = RECORD
    low-, high-: LONGINT;
    jmp-: SYSTEM.PTR;
  END;
  
VAR
  boolean-: StructDesc;
  char-: StructDesc;
  longchar-: StructDesc;
  ucs4char-: StructDesc;
  shortint-: StructDesc;
  integer-: StructDesc;
  longint-: StructDesc;
  real-: StructDesc;
  longreal-: StructDesc;
  set32-: StructDesc;
  byte-: StructDesc;
  ptr-: StructDesc;
  procedure-: StructDesc;

VAR
  argc-: LONGINT;
  argv-: POINTER TO ARRAY [NO_LENGTH_INFO, NO_DESCRIPTOR] OF
                      POINTER TO ARRAY [NO_LENGTH_INFO, NO_DESCRIPTOR] OF CHAR;
  poisonHeap*: LONGINT;
  (**If set to a non-negative value, then memory allocated through
     @oproc{NewObject} and @oproc{NewBlock} is filled with this byte value.
     Otherwise, the memory is left as provided by the used libc or libgc
     library.  This is the default.  *)

PROCEDURE (o: Object) Finalize*;
(**This procedure is called by the run-time system immediately before an object
   is collected by the garbage collector. This procedure may be used to reclaim
   any system resources (other than GC-managed memory) associated with this
   object (eg. OS handles). Any type that overrides this method is
   automatically registered for finalization by the run-time system.

   The Boehm GC finalizes objects in @emph{topological order}. That is, if
   @var{A} points to @var{B}, and both are registered for finalization, it is
   guaranteed the @var{A} will be finalized first. This usually guarantees that
   finalization procedures see only unfinalized objects. For more details on
   finalization, see:
   @url{http://www.hpl.hp.com/personal/Hans_Boehm/gc/finalization.html}.

   @strong{Important}: Program behaviour is undefined if this procedure raises
   an exception and passes it on to its caller.  In this case, the caller is
   the garbage collector and it is not prepared to handle exceptions.  *)

PROCEDURE NewObject* (td: Struct; ...): SYSTEM.PTR;
(**Allocates a new array or record variable on the heap, using the type
   descriptor @oparam{td}.  For an open array object, the lengths of the
   array's dimensions are passed as second, third, and so on, parameter.  They
   must be of type @code{LONGINT}.  *)

PROCEDURE TypeOf* (ptr: SYSTEM.PTR): Struct;
(**Returns the type of the record pointer @oparam{ptr}.  The address
   @oparam{ptr} must be a previous result of @oproc{NewObject}.  Result is
   undefined if @oparam{ptr} is not a reference to a record object.  *)

PROCEDURE TypeTest* (tag, td: Struct): BOOLEAN;
(**Return @code{TRUE} if the type tag @oparam{tag} belongs to an object that is
   an instance of the type @oparam{td}.  For normal (that is, non-qualified)
   types, this is a constant type operation that is basically a pointer
   comparison.  For qualified types, it compares the structure of both types.
   In this case, the function returns @code{TRUE} if the relevant base type of
   @oparam{tag} and @oparam{td} have the same base type, and if the
   corresponding type arguments are of the same type.

   @precond
   @oparam{tag} and @oparam{td} is the type descriptor of a @samp{RECORD} type.
   @end precond  *)

PROCEDURE NewBlock* (bytes: LONGINT): SYSTEM.PTR;
(**Allocates a memory block on the heap with a size of at least @oparam{bytes}
   bytes.  Pointers in the allocated block are ignored during garbage
   collection.  That is, the block must not contain any references to objects
   on the heap that are not kept live by other pointers.  *)

PROCEDURE FreeBlock* (ptr: SYSTEM.PTR);
(**Frees a block of memory allocated with @oproc{NewBlock}.  *)

PROCEDURE CollectGarbage*;
(**Explicitly trigger a full, world-stop garbage collection.  *)

PROCEDURE RegisterDisappearingLink* (VAR ptr: SYSTEM.PTR);
(**Register the pointer @oparam{ptr} to be cleared when the object that it
   references is collected by the garbage collector. Note: it is only safe
   to register pointers from heap objects, or global module variables. NEVER
   use this procedure for a pointer allocated on the stack (ie. a local
   variable or procedure parameter). *)

PROCEDURE UnregisterDisappearingLink* (VAR ptr: SYSTEM.PTR);
(**Undoes a registration of pointer @oparam{ptr} created by
   @oproc{RegisterDisappearingLink}. *)

PROCEDURE ErrorIndexOutOfRange* [NO_RETURN](mid: Module; pos: LONGINT;
                                 index, length: LONGINT);
PROCEDURE ErrorDerefOfNil* [NO_RETURN](mid: Module; pos: LONGINT);
PROCEDURE ErrorFailedTypeGuard* [NO_RETURN](mid: Module; pos: LONGINT; typeTag: Struct);
PROCEDURE ErrorFailedCase* [NO_RETURN](mid: Module; pos: LONGINT; select: LONGINT);
PROCEDURE ErrorFailedWith* [NO_RETURN](mid: Module; pos: LONGINT; typeTag: Struct);
PROCEDURE ErrorFailedTypeAssert* [NO_RETURN](mid: Module; pos: LONGINT);
PROCEDURE ErrorFailedFunction* [NO_RETURN](mid: Module; pos: LONGINT);
PROCEDURE ErrorAssertionFailed* [NO_RETURN](mid: Module; pos: LONGINT; code: LONGINT);
PROCEDURE Halt* [NO_RETURN](code: LONGINT);

PROCEDURE RegisterModule* (mid: Module);
(**Registers the module descriptor with the run-time system.  *)

PROCEDURE UnregisterModule* (mid: Module);
(**Unregisters the module descriptor from the run-time system.  Currently,
   this procedure is a noop.  *)

PROCEDURE ThisModule* (name: ARRAY OF CHAR): Module;
(**Returns the module descriptor for the module @oparam{name}.  Result is
   @code{NIL} if no module of this name has been registered.  *)
  
PROCEDURE ThisType* (mid: Module; name: ARRAY OF CHAR): Struct;
(**Returns the type descriptor for the type @oparam{name} of module
   @oparam{mid}.  If @oparam{name} defines a qualified type and there is no
   match in @oparam{mid}, then @emph{all} modules of the program are searched.
   Result is @code{NIL} if there is no such type descriptor.  *)

PROCEDURE ScanCaseRanges*(table: ARRAY [NO_LENGTH_INFO] OF CaseRange;
                          value: LONGINT): SYSTEM.PTR;
  
END RT0.
