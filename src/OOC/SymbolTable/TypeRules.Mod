(* 	$Id$	 *)
MODULE OOC:SymbolTable:TypeRules;
(*  Defines the type rules of the language.
    Copyright (C) 2000-2002  Michael van Acken

    This file is part of OOC.

    OOC is free software; you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.  

    OOC is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
    License for more details. 

    You should have received a copy of the GNU General Public License
    along with OOC. If not, write to the Free Software Foundation, 59
    Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*)

IMPORT
  Sym := OOC:SymbolTable, OOC:SymbolTable:Predef;

TYPE
  Rules* = POINTER TO RulesDesc;
  RulesDesc = RECORD
    (**An instance of this class provides various predicate methods.  Every
       method corresponds to one particular type rule of the language.  The
       predicates implement the composition restrictions for types (e.g., an
       integer type cannot be a pointer base type), type compatiblity
       (same type, equal type, and such like), matching of formal parameters,
       and so on.  *)
  END;


PROCEDURE Init* (tr: Rules);
  BEGIN
  END Init;

PROCEDURE (tr: Rules) IsNamedType* (type: Sym.Type): BOOLEAN;
(**Returns @code{TRUE}, iff the type @oparam{type} can be accessed through
   a type name.  *)
  BEGIN
    ASSERT (~(type IS Sym.TypeName));
    RETURN (type. namingDecl # NIL)
  END IsNamedType;

PROCEDURE (tr: Rules) IsScalarType* (type: Sym.Type): BOOLEAN;
(**Returns @code{TRUE}, iff the type @oparam{type} is a scalar type, that is,
   if it is a predefined type, a pointer type, or a procedure type.  Result
   is @code{FALSE} for record and array types.  *)
  BEGIN
    RETURN (type IS Sym.PredefType) OR
           (type IS Sym.Pointer) OR
           (type IS Sym.FormalPars)
  END IsScalarType;

PROCEDURE (tr: Rules) IsCharType* (type: Sym.Type): BOOLEAN;
(**Result is @code{TRUE} iff @oparam{type} is a character type.  *)
  BEGIN
    WITH type: Sym.PredefType DO
      RETURN (type. id IN {Predef.char, Predef.longchar})
    ELSE
      RETURN FALSE
    END;
  END IsCharType;

PROCEDURE (tr: Rules) IsStringConst* (type: Sym.Type): BOOLEAN;
(**Result is @code{TRUE} iff @oparam{type} is a string constant.  *)
  BEGIN
    WITH type: Sym.PredefType DO
      RETURN (type. id IN {Predef.charString, Predef.longcharString})
    ELSE
      RETURN FALSE
    END;
  END IsStringConst;

PROCEDURE (tr: Rules) IsIntegerType* (type: Sym.Type): BOOLEAN;
(**Result is @code{TRUE} iff @oparam{type} is an integer type.  *)
  BEGIN
    WITH type: Sym.PredefType DO
      RETURN (type. id IN {Predef.shortint .. Predef.real-1})
    ELSE
      RETURN FALSE
    END;
  END IsIntegerType;

PROCEDURE (tr: Rules) IsRealType* (type: Sym.Type): BOOLEAN;
(**Result is @code{TRUE} iff @oparam{type} is a floating point type.  *)
  BEGIN
    WITH type: Sym.PredefType DO
      RETURN (type. id IN {Predef.real, Predef.longreal})
    ELSE
      RETURN FALSE
    END;
  END IsRealType;

PROCEDURE (tr: Rules) IsNumericType* (type: Sym.Type): BOOLEAN;
(**Result is @code{TRUE} iff @oparam{type} is a numeric type.  *)
  BEGIN
    RETURN tr. IsIntegerType(type) OR tr. IsRealType(type)
  END IsNumericType;

PROCEDURE (tr: Rules) IsSetType* (type: Sym.Type): BOOLEAN;
(**Result is @code{TRUE} iff @oparam{type} is a set type.  *)
  BEGIN
    WITH type: Sym.PredefType DO
      RETURN (type. id IN {Predef.set})
    ELSE
      RETURN FALSE
    END;
  END IsSetType;

PROCEDURE (tr : Rules) IncludesType* (large, small: Sym.Type): BOOLEAN;
(**Returns @code{TRUE} iff type @oparam{large} includes type @oparam{small}.
   The Oberon-2 report defines inclusion for numeric types: LONGREAL >= REAL >=
   LONGINT >= INTEGER >= SHORTINT. In addition, we have: LONGCHAR >= CHAR. *)
  VAR
    largeId, smallId : Sym.PredefId;
  BEGIN
    IF (large IS Sym.PredefType) & (small IS Sym.PredefType) THEN
      largeId := large(Sym.PredefType).id;
      smallId := small(Sym.PredefType).id;
      IF tr. IsNumericType(large) THEN
        RETURN tr. IsNumericType(small) & (smallId <= largeId);
      ELSIF tr. IsCharType(large) THEN
        RETURN tr. IsCharType(small) & (smallId <= largeId);
      END;
    END;
    RETURN FALSE;
  END IncludesType;

PROCEDURE (tr: Rules) IsOpenArrayType* (type: Sym.Type): BOOLEAN;
(**Returns @code{TRUE}, iff the type @oparam{type} is an array, and its
   length is not known at compile time.  *)
  BEGIN
    ASSERT (~(type IS Sym.TypeName));
    RETURN (type IS Sym.Array) & type(Sym.Array). isOpenArray
  END IsOpenArrayType;

PROCEDURE (tr: Rules) IsArrayOfChar* (type: Sym.Type): BOOLEAN;
(**Returns @code{TRUE}, iff the type @oparam{type} is an
   @code{ARRAY OF CHAR} or an @code{ARRAY OF LONGCHAR}.  *)
  BEGIN
    ASSERT (~(type IS Sym.TypeName));
    RETURN
        (type IS Sym.Array) &
        type(Sym.Array). isOpenArray &
        tr. IsCharType (type(Sym.Array). elementType)
  END IsArrayOfChar;



PROCEDURE (tr: Rules) IsValidRecordBaseType* (type: Sym.Type): BOOLEAN;
(**Returns @code{TRUE}, iff the type @oparam{type} can be used for the
   base type of a record definition.  *)
  BEGIN
    RETURN (type IS Sym.Record)
  END IsValidRecordBaseType;

PROCEDURE (tr: Rules) IsValidParameterType* (type: Sym.Type): BOOLEAN;
(**Returns @code{TRUE}, iff the type @oparam{type} can be used for the
   type of a formal parameter definition.  *)
  BEGIN
    ASSERT (~(type IS Sym.TypeName));
    RETURN tr. IsNamedType (type) OR
           tr. IsOpenArrayType (type) OR
           (type IS Sym.FormalPars)
  END IsValidParameterType;

PROCEDURE (tr: Rules) IsValidReceiverType* (type: Sym.Type): BOOLEAN;
(**Returns @code{TRUE}, iff the type @oparam{type} can be used for the
   type of a receiver declaration.  *)
  BEGIN
    ASSERT (~(type IS Sym.TypeName));
    RETURN
      (type IS Sym.Record) OR
      (type IS Sym.Pointer) & (type(Sym.Pointer). baseType IS Sym.Record)
  END IsValidReceiverType;

PROCEDURE (tr: Rules) IsValidResultType* (type: Sym.Type): BOOLEAN;
(**Returns @code{TRUE}, iff the type @oparam{type} can be used for the
   result type of a formal parameter definition.  This function also 
   return @code{TRUE}, if @oparam{type} is @code{NIL}.  *)
  BEGIN
    RETURN (type = NIL) OR tr. IsScalarType (type)
  END IsValidResultType;

PROCEDURE (tr: Rules) IsValidPointerBaseType* (type: Sym.Type): BOOLEAN;
(**Returns @code{TRUE}, iff the type @oparam{type} can be used as the
   base type of a pointer type definition.  *)
  BEGIN
    RETURN (type IS Sym.Array) OR (type IS Sym.Record)
  END IsValidPointerBaseType;

PROCEDURE (tr: Rules) IsValidArrayElementType* (type: Sym.Type; isOpenArray: BOOLEAN): BOOLEAN;
(**Returns @code{TRUE}, iff the type @oparam{type} can be used as the
   element type of a array type definition.  The result may differ for
   open arrays and fixed length arrays.  *)
  BEGIN
    IF isOpenArray THEN
      RETURN TRUE
    ELSE
      RETURN ~(type IS Sym.Array) OR ~type(Sym.Array). isOpenArray
    END
  END IsValidArrayElementType;

PROCEDURE ^ (tr: Rules) FormalParamsMatch* (baseFPars, procFPars: Sym.FormalPars; allowExtendedResult: BOOLEAN): BOOLEAN;

PROCEDURE (tr: Rules) SameType* (a, b: Sym.Type): BOOLEAN;
(**Returns @code{TRUE}, iff @oparam{a} and @oparam{b} are the @dfn{same type},
   as defined in the language report.  *)
  BEGIN
    RETURN (a = b) & ~tr. IsOpenArrayType (a)
  END SameType;

PROCEDURE (tr: Rules) EqualTypes* (a, b: Sym.Type): BOOLEAN;
(**Returns @code{TRUE}, iff @oparam{a} and @oparam{b} are of @dfn{equal type},
   as defined in the language report.  *)
  BEGIN
    RETURN tr. SameType (a, b) OR
           tr. IsOpenArrayType (a) & tr. IsOpenArrayType (b) &
             tr. EqualTypes (a(Sym.Array). elementType, 
                             b(Sym.Array). elementType) OR
           (a IS Sym.FormalPars) & (b IS Sym.FormalPars) &
             tr. FormalParamsMatch (a(Sym.FormalPars), b(Sym.FormalPars), FALSE)
           
  END EqualTypes;

PROCEDURE (tr: Rules) IsExtensionOf* (type, base: Sym.Type): BOOLEAN;
(* Result is TRUE iff the type @oparam{type} is an extension of the type
   @oparam{base}.  See Oberon-2 report, Appendix A.  *)
  BEGIN
    (* if `type' and `base' are pointers: reduce them to their base types *)
    IF (type IS Sym.Pointer) & (base IS Sym.Pointer) THEN
      type := type(Sym.Pointer). baseType;
      base := base(Sym.Pointer). baseType
    END;
    IF (type IS Sym.Record) & (base IS Sym.Record) THEN
      (* either `type' and `base' where records from the start, or they were
         both record pointers *)
      WHILE (type # NIL) & (type IS Sym.Record) DO 
        IF tr. SameType (type, base) THEN
          RETURN TRUE
        ELSE
          type := type(Sym.Record). baseType
        END
      END
    END;
    RETURN FALSE
  END IsExtensionOf;

PROCEDURE (tr: Rules) FormalParamsMatch* (baseFPars, procFPars: Sym.FormalPars; allowExtendedResult: BOOLEAN): BOOLEAN;
(**Returns @code{TRUE}, iff the formal parameter lists described by 
   @oparam{baseFPars} and @oparam{procFPars} match.  The comparison includes
   the formal parameters, the result type, and any rest parameter.  The
   receiver of the formal parameter lists is ignored.
   
   If @oparam{allowExtendedResult} is @code{TRUE}, then the result type of
   @oparam{procFPars} may be an extension of the result type of
   @oparam{baseFPars}, otherwise the result types must be the same.  *)
  VAR
    i: LONGINT;
  BEGIN
    IF (LEN (baseFPars. params^) # LEN (procFPars. params^)) THEN
      RETURN FALSE
    ELSIF ((baseFPars. resultType = NIL) # (procFPars. resultType = NIL)) THEN
      RETURN FALSE
    ELSIF (baseFPars. resultType # NIL) & 
          ~allowExtendedResult &   
          ~tr. SameType (baseFPars. resultType, procFPars. resultType) THEN
      RETURN FALSE
    ELSIF (baseFPars. resultType # NIL) & 
          allowExtendedResult &
          ~(tr. SameType (baseFPars. resultType, procFPars. resultType) OR
            tr. IsExtensionOf (procFPars. resultType, baseFPars. resultType)) THEN
      RETURN FALSE
    ELSIF (baseFPars. anyRestParameters # procFPars. anyRestParameters) THEN
      RETURN FALSE
    ELSE
      FOR i := 0 TO LEN (baseFPars. params^)-1 DO
        IF (baseFPars. params[i]. isVarParam # 
            procFPars. params[i]. isVarParam) OR
           ~tr. EqualTypes (baseFPars. params[i]. type, 
                            procFPars. params[i]. type) THEN
          RETURN FALSE
        END
      END;
      RETURN TRUE
    END
  END FormalParamsMatch;

PROCEDURE (tr: Rules) IsValidRedefinition* (baseFPars, procFPars: Sym.FormalPars): BOOLEAN;
(**Returns @code{TRUE}, iff @oparam{procFPars} is a valid redefinition of
   the type-bound procedure @oparam{baseFPars}.  *)
  BEGIN
    RETURN
      (baseFPars. receiver. isVarParam = procFPars. receiver. isVarParam) &
      tr. FormalParamsMatch (baseFPars, procFPars, TRUE)
  END IsValidRedefinition;

PROCEDURE (tr: Rules) IsValidForwardDecl* (forward, proc: Sym.FormalPars): BOOLEAN;
(**Returns @code{TRUE}, iff @oparam{forward} is a valid forward declaration
   of the procedure @oparam{proc}.  *)
  BEGIN
    IF (forward. receiver # NIL) THEN
      RETURN tr. IsValidRedefinition (proc, forward)
    ELSE
      RETURN tr. FormalParamsMatch (proc, forward, FALSE)
    END
  END IsValidForwardDecl;



PROCEDURE (tr: Rules) IsArrayType* (type: Sym.Type): BOOLEAN;
(**Returns @code{TRUE}, iff @oparam{type} is an array type. *)
  BEGIN
    ASSERT (~(type IS Sym.TypeName));
    RETURN (type IS Sym.Array)
  END IsArrayType;

PROCEDURE (tr: Rules) IsArrayCompatible* (argType, fparType: Sym.Type): BOOLEAN;
(**Returns @code{TRUE}, iff the type of the actual parameter @oparam{argType}
   is array compatible with that of a formal parameter @oparam{fparType}.
   Note: The case where @oparam{argType} is a string constant
   @oconst{Predef.charString} must be handled by the caller.  In this
   the implementation of this function differs from the @cite{Appendix A}
   of the language report.  *)
  BEGIN
    ASSERT (~(argType IS Sym.PredefType) OR
            (argType(Sym.PredefType). id # Predef.charString));
    WHILE tr. IsOpenArrayType (fparType) & (argType IS Sym.Array) DO
      argType := argType(Sym.Array). elementType;
      fparType := fparType(Sym.Array). elementType
    END;
    RETURN tr. SameType (argType, fparType)
  END IsArrayCompatible;

PROCEDURE (tr: Rules) IsComponentOf* (subType, superType: Sym.Type;
                                      arrayCompat: BOOLEAN): BOOLEAN;
(**Returns @code{TRUE} iff type @oparam{superType} is equal to or contains a
   subtype of type @oparam{subType}.  If @oparam{arrayCompat} is @code{TRUE}
   also returns @code{TRUE} if a subtype of @oparam{superType} is array
   compatible to @oparam{subType}.  *)
  VAR 
    field: Sym.Item;
  BEGIN
    IF tr. EqualTypes (superType, subType) OR 
       tr. IsExtensionOf (superType, subType) THEN
      RETURN TRUE
    ELSIF arrayCompat & tr. IsArrayCompatible (subType, superType) THEN
      RETURN TRUE
    ELSIF (superType IS Sym.Array) THEN
      RETURN tr. IsComponentOf (subType, superType(Sym.Array). elementType,
                            arrayCompat)
    ELSIF (superType IS Sym.Record) THEN
      (* inspect types of all fields of all base types *)
      WHILE (superType # NIL) DO
        field := superType. nestedItems;
        WHILE (field # NIL) DO
          WITH field: Sym.FieldDecl DO
            IF tr. IsComponentOf (subType, field. type, arrayCompat) THEN
              RETURN TRUE
            END
          ELSE  (* ignore entries for type-bound procedures *)
          END;
          field := field. nextNested
        END;
        superType := superType(Sym.Record). baseType
      END;
      RETURN FALSE
    ELSE
      RETURN FALSE
    END
  END IsComponentOf;

PROCEDURE (tr: Rules) IsByteCompatible* (type: Sym.Type): BOOLEAN;
(**Returns @code{TRUE}, iff the type @oparam{type} can be assigned to
   a @samp{BYTE} variable.  *)
  BEGIN
    WITH type: Sym.PredefType DO
      RETURN (type. id = Predef.char) OR (type. id = Predef.shortint);
    ELSE
      RETURN FALSE;
    END;
  END IsByteCompatible;

PROCEDURE (tr: Rules) IsNilCompatible* (type: Sym.Type): BOOLEAN;
(**Returns @code{TRUE}, iff the value @code{NIL} can be assigned to
   variables of type @oparam{type}.  *)
  BEGIN
    WITH type: Sym.PredefType DO
      RETURN (type. id = Predef.ptr)
    | type: Sym.Pointer DO
      RETURN TRUE;
    | type: Sym.FormalPars DO
      RETURN TRUE;
    ELSE
      RETURN FALSE;
    END;
  END IsNilCompatible;


PROCEDURE (tr: Rules) AllocateType* (type: Sym.Type);
(**This maps a type @oparam{type} onto the size and alignment constrains of the
   destination architecture.  That is, it sets size and aligment of
   @oparam{type}, and calculates offsets of record fields.  The exact mapping
   is usually a function of the target architecture.  The default
   implementation assumes a generic 32 bit architecture.  See
   @ofield{Sym.Type.size} and @ofield{Sym.Type.align} for more information.

   @precond
   @oparam{type} is not a @otype{Sym.TypeName}.  There are no cyclic references
   between structured types (like records or arrays) that are not broken by
   intermediate pointer types.
   @end precond

   @postcond
   The field @ofield{type.size} and @ofield{type.align} are set, as are the
   fields of all types that are part of @oparam{type} or are referenced by it.
   @end postcond  *)
  CONST
    pointerSize = 4;
    pointerAlign = 4;
  VAR
    i, size: LONGINT;
    align, maxAlign, fieldAlign: INTEGER;
    nested: Sym.Item;
  BEGIN
    IF (type. size = Sym.unknownSize) THEN
      (* note: size and alignment of predefined types is defined in
         module OOC:SymbolTable:Predef *)
      WITH type: Sym.Pointer DO
        type. SetSize (pointerSize, pointerAlign); (* this breaks any cycles *)
        (* don't call `tr. AllocateType (type. baseType)' here: this may
           be a forward reference, and some pieces of information about this
           type may not be computed yet *)

      | type: Sym.FormalPars DO
        type. SetSize (pointerSize, pointerAlign); (* this breaks any cycles *)
        IF (type. receiver # NIL) THEN
          tr. AllocateType (type. receiver. type);
        END;
        FOR i := 0 TO LEN (type. params^)-1 DO
          tr. AllocateType (type. params[i]. type);
        END;
        
      | type: Sym.Array DO
        tr. AllocateType (type. elementType);
        IF type. isOpenArray THEN
          type. SetSize (Sym.dynamicSize, type. elementType. align);
        ELSE
          type. SetSize (type. length*type. elementType. size,
                         type. elementType. align);
        END;

      | type: Sym.Record DO
        (* initialize size and alignment, take base type into account *)
        IF (type. baseType = NIL) THEN 
          align := 1;  (* this alignment is also used if the record is empty *)
          size := 0
        ELSE
          tr. AllocateType (type. baseType);
          align := type. baseType. align;
          size := type. baseType. size
        END;
      
        (* determine maximum alignment value, as selected by ALIGN[1248] *)
        (*IF (t. beFlags*{structAlign1..structAlign8} # {}) THEN
          i := structAlign8;
          WHILE ~(i IN t. beFlags) DO
            DEC (i)
          END;
          maxAlign := SHORT (ASH (1, i-structAlign1))
        ELSE*)
          maxAlign := MAX (INTEGER);
        (*END;*)

        nested := type. nestedItems;
        WHILE (nested # NIL) DO
          WITH nested: Sym.FieldDecl DO
            tr. AllocateType (nested. type);
            fieldAlign := nested. type. align;
            IF (fieldAlign > maxAlign) THEN
              fieldAlign := maxAlign
            END;
            
            IF (fieldAlign > align) THEN
              (* record's alignment is the highest alignment of all fields *)
              align := fieldAlign
            END;
            
            IF type. isUnion THEN
              (* union type: map all fields to the same offset 0; the overall 
                 size is equal to the size of the largest union element *)
              nested. SetOffset (0);
              IF (nested. type. size > size) THEN
                size := nested. type. size
              END
            ELSE
              (* record type: adjust the offset to satisfy the field's
                 alignment requirements, then add field size to record size *)
              IF (size MOD fieldAlign # 0) THEN
                INC (size, fieldAlign - size MOD fieldAlign)
              END;
              nested. SetOffset (size);
              INC (size, nested. type. size)
            END
          ELSE  (* ignore *)
          END;
          nested := nested. nextNested
        END;
        
        (* adjust record size to be a multiple of its alignment *)
        IF (size MOD align # 0) THEN
          type. SetSize (size + align - size MOD align, align)
        ELSE
          type. SetSize (size, align)
        END;
      END;
    END;
  END AllocateType;

END OOC:SymbolTable:TypeRules.
