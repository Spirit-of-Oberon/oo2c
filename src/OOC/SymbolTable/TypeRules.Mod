(* 	$Id$	 *)
MODULE OOC:SymbolTable:TypeRules;
(*  Defines the type rules of the language.
    Copyright (C) 2000, 2001  Michael van Acken

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


PROCEDURE (tr: Rules) IsNamedType* (type: Sym.Type): BOOLEAN;
(**Returns @code{TRUE}, iff the type @oparam{type} can be accessed through
   a type name.  *)
  BEGIN
    ASSERT (~(type IS Sym.TypeName));
    RETURN (type. typeName # NIL)
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

PROCEDURE (tr : Rules) IsPredefClass* (type : Sym.Type; class : SET) : BOOLEAN;
(**Returns @code{TRUE}, iff the type @oparam{type} is a a member of a class of
   types. A class is represented by a SET of @otype{Sym.PredefId} values.
   These are defined by classXXX constants in @omodule{*OOC:SymbolTable:Predef}.
   *)
  BEGIN
    WITH type : Sym.PredefType DO
      RETURN type.id IN class;
    ELSE
      RETURN FALSE
    END;
  END IsPredefClass;

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
      IF (largeId IN Predef.classNumeric) THEN
        RETURN (smallId IN Predef.classNumeric) & (smallId <= largeId);
      ELSIF (largeId IN Predef.classChar) THEN
        RETURN (smallId IN Predef.classChar) & (smallId <= largeId);
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

END OOC:SymbolTable:TypeRules.
