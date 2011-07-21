(* 	$Id: DeclWriter.Mod,v 1.69 2004/04/05 06:17:42 sgreenhill Exp $	 *)
MODULE OOC:C:DeclWriter [OOC_EXTENSIONS];
(*  Defines classes to handle C declarations, types, and include statements.
    Copyright (C) 2001-2003  Michael van Acken

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
  SYSTEM, IntStr, Strings, IO, IO:TextRider,
  Object, Object:Boxed, Object:BigInt, ADT:ArrayList, URI, 
  OOC:Repository, Sym := OOC:SymbolTable, OOC:SymbolTable:Predef,
  TR := OOC:SymbolTable:TypeRules, OOC:Repository:FileSystem;
  


TYPE
  TypeQualifier* = SHORTINT;
  (**Type qualifier of a definition.  One of @oconst{tqNone}, @oconst{tqConst},
     or @oconst{tqVolatile}.  Qualifiers are mutually exclusive.  That is, only
     one of them applies.  They can be used in connection with pointers
     (@oproc{Writer.NewPointer}) or declarations
     (@oproc{Writer.NewDeclaration}).  *)

CONST
  tqNone* = 0;
  (**Type definition has no qualifier.  *)
  tqConst* = 1;
  (**Definition is prefixed with the type qualifier @code{const}.  *)
  tqVolatile* = 2;
  (**Definition is prefixed with the type qualifier @code{volatile}.  *)
  
TYPE
  Type* = POINTER TO TypeDesc;
  TypeDesc = RECORD [ABSTRACT]
    (**Abstract base type for all type represenations.  *)
  END;

TYPE
  BasicTypeId* = SHORTINT;
  
CONST
  void* = 0;
  (**This is the C pseudo type @code{void}.  Used to declare proper procedures
     that do no return a result value.  *)
  ptr* = 1;
  (**This type is mapped to the type name @code{OOC_PTR}, which in turn is an
     alias for @samp{void*}.  *)
  int8* = 2;
  (**This type is mapped to the name @code{OOC_INT8}, a signed integer type
     holding (at least) 8 bits.  *)
  int16* = 3;
  (**This type is mapped to the name @code{OOC_INT16}, a signed integer type
     holding (at least) 16 bits.  *)
  int32* = 4;
  (**This type is mapped to the name @code{OOC_INT32}, a signed integer type
     holding (at least) 32 bits.  *)
  int64* = 5;
  (**This type is mapped to the name @code{OOC_INT64}, a signed integer type
     holding (at least) 64 bits.  *)
  uint8* = 6;
  (**This type is mapped to the name @code{OOC_UINT8}, a unsigned integer type
     holding (at least) 8 bits.  *)
  uint16* = 7;
  (**This type is mapped to the name @code{OOC_UINT16}, a unsigned integer type
     holding (at least) 16 bits.  *)
  uint32* = 8;
  (**This type is mapped to the name @code{OOC_UINT32}, a unsigned integer type
     holding (at least) 32 bits.  *)
  uint64* = 9;
  (**This type is mapped to the name @code{OOC_UINT64}, a unsigned integer type
     holding (at least) 64 bits.  *)
  char8* = 10;
  (**This type is mapped to the name @code{OOC_CHAR8}, the type used to store 8
     bit character values.  This in turn is an alias for @code{unsigned char}.  *)
  char16* = 11;
  (**This type is mapped to the name @code{OOC_CHAR16}, the type used to store
     16 bit character values.  Usually, this is equvalient to @oconst{uint16}.  *)
  char32* = 12;
  (**This type is mapped to the name @code{OOC_CHAR32}, the type used to store
     32 bit character values.  Usually, this is equvalient to @oconst{uint32}.  *)
  real32* = 13;
  (**This is mapped to the IEEE 754 single precision floating point type,
     usually @code{float}.  *)
  real64* = 14;
  (**This is mapped to the IEEE 754 double precision floating point type,
     usually @code{double}.  *)
  
  lengthType* = 15;
  (**This basic type is used to store the length of arrays.  On the C level, it
     is an alias for a signed integer type.  On 32 bit targets, @oconst{int32}
     and @oconst{lengthType} are mapped to the same C type.  When working on
     the level of the @emph{input} language, the symbol type
     @oconst{*OOC:SymbolTable:Predef.lengthType} should be used.  *)
  typeTagType* = 16;
  (**This type is used to store type tag values.  This is a pointer with a
     defined meaning within the run-time system.  *)
  
  lastBasicType = typeTagType;

  
TYPE
  BasicType* = POINTER TO BasicTypeDesc;
  BasicTypeDesc = RECORD
    (**Represents basic, predefined types.  For each @otype{BasicTypeId} exists
       an instance of this class.  The field @ofield{Writer.basicType} maps ids to
       their corresponding instances.  *)
    (TypeDesc)
    id: BasicTypeId;
    repr-: ARRAY 32 OF CHAR;
  END;

TYPE
  Pointer* = POINTER TO PointerDesc;
  PointerDesc = RECORD
    (**Represents pointer types.  See @oproc{Writer.NewPointer}.  *)
    (TypeDesc)
    typeQualifier: TypeQualifier;
    base-: Type;
  END;

TYPE
  Array* = POINTER TO ArrayDesc;
  ArrayDesc = RECORD
    (**Represents array types.  See @oproc{Writer.NewArray}.  *)
    (TypeDesc)
    base: Type;
    size: LONGINT;
  END;

TYPE
  Function* = POINTER TO FunctionDesc;
  FunctionDesc = RECORD
    (**Represents function types.  See @oproc{Writer.NewFunction}.  *)
    (TypeDesc)
    resultType: Type;
    parameters: ArrayList.ArrayList;
    restParameters: BOOLEAN;
    noReturn: BOOLEAN;
    callConv: Sym.CallConv;
  END;

TYPE
  Struct* = POINTER TO StructDesc;
  StructDesc = RECORD
    (TypeDesc)
    isUnion: BOOLEAN;
    name: STRING;
    members: ArrayList.ArrayList;        (* of Declaration *)
  END;

TYPE
  TypeRefClass* = SHORTINT;

CONST
  refTypedef* = 0;
  refStruct* = 1;
  refUnion* = 2;
  
TYPE
  TypeRef* = POINTER TO TypeRefDesc;
  TypeRefDesc = RECORD
    (TypeDesc)
    class: TypeRefClass;
    name: STRING;
  END;
  
TYPE
  StorageClass* = SHORTINT;
  (**Storage class of a declaration.  One of @oconst{scMember},
     @oconst{scTypedef}, @oconst{scExtern}, @oconst{scStatic}, @oconst{scAuto},
     or @oconst{scRegister}.  Please note that there are also specializations
     of @otype{Declaration}, like @otype{IncludeModule} or @otype{Define},
     that have no storage class.  In this case, @oconst{scAuto} is used.  *)
  
CONST
  scMember* = 0;
  (**Used for members of a @code{struct} or @code{union} definition.  *)
  scTypedef* = 1;
  (**Declaration is prefixed with the keyword @code{typedef}.  *)
  scExtern* = 2;
  (**Declaration is prefixed with the keyword @code{extern}.  *)
  scStatic* = 3;
  (**Declaration is prefixed with the keyword @code{static}.  *)
  scAuto* = 4;
  (**Declaration is written without any storage class prefix, implying the
     storage class @code{auto}.  *)
  scRegister* = 5;
  (**Declaration is prefixed with the keyword @code{register}.  *)
  scForceAuto* = 6;
  (**Declaration is written with the explicit storage class @code{auto}.  *)

TYPE
  Declaration* = POINTER TO DeclarationDesc;
  DeclarationDesc = RECORD
    (**An instance of this class is a model for a C declaration or definition.
       It includes information on the declaration's type qualifier, its storage
       class, its type, and the declared name.  New declaration objects are
       created with @oproc{Writer.NewDeclaration} and are serialized into an
       output file with @oproc{Writer.WriteDeclaration}.  *)
    (Object.ObjectDesc)
    typeQualifier: TypeQualifier;
    storageClass: StorageClass;
    type: Type;
    name-: STRING;
  END;

TYPE
  IncludeModule* = POINTER TO IncludeModuleDesc;
  IncludeModuleDesc = RECORD
    (**A special declaration indicating that a module's header file should be
       included.  *)
    (DeclarationDesc)
    module: Repository.Module;
  END;
  
TYPE
  Define* = POINTER TO DefineDesc;
  DefineDesc = RECORD
    (**A special declaration that is translated into a @code{#define} statement
       declaring a symbolic name for a constant.  *)
    (DeclarationDesc)
    const: Boxed.Object;
    oocType: Sym.Type;
  END;
  
TYPE
  Writer* = POINTER TO WriterDesc;
  WriterDesc* = RECORD
    (**This writer is wrapper around of @otype{TextRider.Writer} with
       additional knowledge about C declarations, definitions, and literals.
       Its main purpose is to act as an abstraction layer for the not so easy
       task of writing C type expressions.  *)
    ch: IO.ByteChannel;
    baseURI: URI.HierarchicalURI;
    textWriter-: TextRider.Writer;
    
    includes: ArrayList.ArrayList;
    declarations: ArrayList.ArrayList;
    
    indentation: LONGINT;
    (**Current indentation level.  Used by @oproc{Writer.Newline}.  *)
    
    basicType-: ARRAY lastBasicType+1 OF BasicType;
    (**Maps ids of basic types (see @otype{BasicTypeId}) onto the corresponding
       instances of @otype{BasicType}.  *)
  END;


CONST
  priName = 0;
  priStruct = 1;
  priPointer = 1;
  priArray = 2;
  priFunction = 2;
  priDeclaration = 3;



PROCEDURE ^ NewBasicType (id: BasicTypeId; repr: ARRAY OF CHAR): BasicType;
PROCEDURE ^ (d: Declaration) Write (w: Writer);
PROCEDURE ^ (w: Writer) NewDeclaration* (name: STRING; typeQualifier: TypeQualifier; storageClass: StorageClass; type: Type): Declaration;

PROCEDURE InitWriter (w: Writer; ch: IO.ByteChannel;
                      baseURI: URI.HierarchicalURI);
  PROCEDURE CreateBasicType (id: BasicTypeId; repr: ARRAY OF CHAR);
    BEGIN
      w. basicType[id] := NewBasicType (id, repr)
    END CreateBasicType;
  
  BEGIN
    w. ch := ch;
    w. baseURI := baseURI;
    w. indentation := 0;
    
    w. textWriter := TextRider.ConnectWriter (ch);
    w. includes := ArrayList.New (4);
    w. declarations := ArrayList.New (16);
    
    CreateBasicType (void, "void");
    CreateBasicType (ptr, "OOC_PTR");
    CreateBasicType (int8, "OOC_INT8");
    CreateBasicType (int16, "OOC_INT16");
    CreateBasicType (int32, "OOC_INT32");
    CreateBasicType (int64, "OOC_INT64");
    CreateBasicType (uint8, "OOC_UINT8");
    CreateBasicType (uint16, "OOC_UINT16");
    CreateBasicType (uint32, "OOC_UINT32");
    CreateBasicType (uint64, "OOC_UINT64");
    CreateBasicType (char8, "OOC_CHAR8");
    CreateBasicType (char16, "OOC_CHAR16");
    CreateBasicType (char32, "OOC_CHAR32");
    CreateBasicType (real32, "OOC_REAL32");
    CreateBasicType (real64, "OOC_REAL64");
    CreateBasicType (lengthType, "OOC_LEN");
    CreateBasicType (typeTagType, "RT0__Struct");
  END InitWriter;

PROCEDURE NewWriter* (ch: IO.ByteChannel;
                      baseURI: URI.HierarchicalURI): Writer;
  (**Creates a new writer with an output target of @oparam{ch}.  If
     @oparam{baseURI} is non-@code{NIL}, then the file names in include
     statements are made relative with respect to this URI before output.  *)
  VAR
    w: Writer;
  BEGIN
    NEW (w);
    InitWriter (w, ch, baseURI);
    RETURN w
  END NewWriter;

PROCEDURE (w: Writer) CopyTo* (dest: Writer);
  (**Copies the internal state of @oparam{w} to @oparam{dest}.  Afterwards,
     @oparam{dest} can be used in place of @oparam{w} and vice versa.  *)
  
  BEGIN  (* dest^ := w^ is prevented by the language definition :-(  *)
    dest. ch := w. ch;
    dest. baseURI := w. baseURI;
    dest. textWriter := w. textWriter;
    dest. includes := w. includes;
    dest. declarations := w. declarations;
    dest. indentation := w. indentation;
    dest. basicType := w. basicType;
  END CopyTo;

PROCEDURE (w: Writer) WriteString* (str[NO_COPY]: ARRAY OF CHAR);
  BEGIN
    w. textWriter. WriteString (str)
  END WriteString;

PROCEDURE (w: Writer) WriteObject* (obj: Object.Object);
  BEGIN
    w.textWriter.WriteObject(obj);
  END WriteObject;

PROCEDURE (w: Writer) WriteChar* (ch: CHAR);
  BEGIN
    w. textWriter. WriteChar (ch)
  END WriteChar;

PROCEDURE (w: Writer) WriteLn*();
  BEGIN
    w. textWriter. WriteLn
  END WriteLn;

PROCEDURE (w: Writer) WriteLInt*(lint: LONGINT; n: LONGINT);
  BEGIN
    w. textWriter. WriteLInt (lint, n)
  END WriteLInt;

PROCEDURE (w: Writer) Indent* (delta: LONGINT);
(**Change current indentation by @oparam{delta} levels.  *)
  BEGIN
    INC (w. indentation, delta);
  END Indent;

PROCEDURE (w: Writer) Newline*();
  VAR
    i: LONGINT;
  BEGIN
    w. WriteLn;
    FOR i := 1 TO w. indentation DO
      w. WriteString ("  ");
    END;
  END Newline;

PROCEDURE (w: Writer) WriteInclude* (includePath: ARRAY OF CHAR);
(**Write an include statement @code{#include <@dots{}>} for the indicated
   file.  *)
  BEGIN
    w. WriteString ('#include <');
    w. WriteString (includePath);
    w. WriteString ('>');
    w. WriteLn
  END WriteInclude;
  
PROCEDURE (w: Writer) Close* ()
RAISES IO.Error;
(**Closes the writer's output channel.  *)
  BEGIN
    w.ch.CloseAndRegister();
  END Close;

PROCEDURE (w: Writer) WriteConst* (value: Boxed.Object; type: Sym.Type);
(**Writes the C representation of the constant value @oparam{value} to
   @oparam{w}.  This procedure handles all necessary translations to get a
   faithful representation of the value in the language of C.

   @strong{NOTE}: This method is deprecated.  Use
   @oproc{Writer.WriteBasicConst} or @oproc{Writer.WriteStringConst}
   instead.  *)
  CONST
    delim = '"';
    quotedDelim = '\"';
  VAR
    i, len, charValue: LONGINT;
    s: STRING;
    paren: BOOLEAN;
    
  PROCEDURE WriteOct (ch: LONGINT);
    BEGIN
      w. WriteChar (CHR (ch+ORD("0")));
    END WriteOct;
 
  PROCEDURE WriteChar (charValue : LONGINT);
  BEGIN
    IF (charValue < ORD (" ")) OR (charValue >= 127) OR
      (charValue = ORD ("'")) OR (charValue = ORD ("\")(*"*)) THEN
      w. WriteChar ("\")(*"*); 
      WriteOct (charValue DIV 64);
      WriteOct (charValue DIV 8 MOD 8);
      WriteOct (charValue MOD 8);
    ELSE
      w. WriteChar (CHR (charValue));
    END;
  END WriteChar;
 
  BEGIN
    IF (value = NIL) THEN
      w. WriteString ("0");
    ELSE
      WITH value: Boxed.Boolean DO
        IF value. value THEN
          w. WriteString("OOC_TRUE")
        ELSE
          w. WriteString("OOC_FALSE")
        END
            
      | value: Boxed.String DO
        s := value.value;
        IF TR.IsPredefType(TR.BaseCharType(type), Predef.char) THEN
          IF (type(Sym.PredefType). id = Predef.char) THEN
            (* note: the character value is cast to OOC_CHAR8 to avoid
               any problems if characters are interpreted as signed values
               by default; that is, '\377' is _not_ -1 *)
            charValue := ORD(s.CharAt(0));
            w. WriteString ("(OOC_CHAR8)'");
            WriteChar(charValue);
            w. WriteChar ("'");
          ELSE
            w. WriteChar (delim);
            i := 0; len := s. length;
            WHILE (i # len) DO
              IF (s.CharAt(i) = delim) THEN
                w. WriteString (quotedDelim)
              ELSE  (* note: this is a tidbit slow for large strings *)
                WriteChar(ORD(s.CharAt(i)))
              END;
              INC (i)
            END;
            w. WriteChar (delim);
          END;

        ELSE
          IF TR.IsCharType(type) THEN
            CASE type(Sym.PredefType).id OF
            | Predef.longchar:
              w. WriteString ("(OOC_CHAR16)");
            | Predef.ucs4char:
              w. WriteString ("(OOC_CHAR32)");
            END;
            charValue := ORD(s.CharAt(0));
            IF (charValue < ORD (" ")) OR (charValue >= 127) OR
               (charValue = ORD ("'")) OR (charValue = ORD ("\")(*"*)) THEN
              w. textWriter. WriteLInt (charValue, 0);
            ELSE
              w. WriteChar ("'");
              w. WriteChar (CHR (charValue));
              w. WriteChar ("'");
            END;
          ELSE
            (* Interesting bit of C knowledge: An expression like `(T){1,2}'
               cannot be passed to a cpp macro, because the preprocessor
               interprets the `,' as its argument separator.  On the other
               hand, `((T){1,2})' works.  *)
            CASE type(Sym.PredefType).id OF
            | Predef.stringLongChar:
              w. WriteString ("((OOC_CHAR16[]){");
            | Predef.stringUCS4Char:
              w. WriteString ("((OOC_CHAR32[]){");
            END;
            i := 0; len := s.length;
            WHILE (i # len) DO
              IF (i # 0) THEN
                w. WriteChar (",");
              END;
              w. textWriter. WriteLInt (ORD(s.NextChar(i)), 0);
            END;
            IF (i # 0) THEN
              w. WriteChar (",");
            END;
            w. textWriter. WriteLInt (0, 0);
            w. WriteString ("})");
          END;
        END;
        
      | value: Boxed.LongReal DO
        paren := (value.value < 0);
        IF paren THEN w.WriteString("(") END;
        w. WriteObject(value.ToString());
        IF TR.IsPredefType(type, Predef.real) THEN
          w. WriteString("f");
        END;
        IF paren THEN w.WriteString(")") END;
        
      | value: BigInt.BigInt DO
        IF (value. ToLongInt() = MIN (LONGINT)) THEN
          (* this assumes that MIN(LONGINT) is also the smallest value of
             the C type "int"; to avoid overflow errors, we must rewrite
             the value slightly *)
          w. WriteString ("(-");
          w. WriteLInt (MAX (LONGINT), 0);
          w. WriteString ("-1)");
        ELSE
          paren := (value.Sign() < 0);
          IF paren THEN w.WriteString("(") END;
          w. WriteObject(value.ToString());
          IF paren THEN w.WriteString(")") END;
        END;
        
      | value: Boxed.Set DO
        w.WriteConst(BigInt.NewInt(SYSTEM.VAL(LONGINT, value.value)), type);
      END;
    END;
  END WriteConst;

PROCEDURE (w: Writer) WriteBasicConst* (value: Boxed.Object;
                                        type: BasicTypeId);
(**Writes the C representation of the constant value @oparam{value} to
   @oparam{w}.  This procedure handles all necessary translations to get a
   faithful representation of the value in the language of C.  The exact
   variant used is based on the dynamic type of @oparam{value} and the
   type id in @oparam{type}.  *)
  VAR
    charValue: LONGINT;
    s: STRING;
    signed, paren: BOOLEAN;
    
  PROCEDURE WriteOct (ch: LONGINT);
    BEGIN
      w. WriteChar (CHR (ch+ORD("0")));
    END WriteOct;
 
  PROCEDURE WriteChar (charValue : LONGINT);
  BEGIN
    IF (charValue < ORD (" ")) OR (charValue >= 127) OR
      (charValue = ORD ("'")) OR (charValue = ORD ("\")(*"*)) THEN
      w. WriteChar ("\")(*"*); 
      WriteOct (charValue DIV 64);
      WriteOct (charValue DIV 8 MOD 8);
      WriteOct (charValue MOD 8);
    ELSE
      w. WriteChar (CHR (charValue));
    END;
  END WriteChar;
 
  BEGIN
    IF (value = NIL) THEN
      w. WriteString ("0");
    ELSE
      WITH value: Boxed.Boolean DO
        IF value. value THEN
          w. WriteString("OOC_TRUE")
        ELSE
          w. WriteString("OOC_FALSE")
        END
            
      | value: Boxed.String DO
        s := value.value;
        IF (type = char8) OR (type = uint8) THEN
          (* note: the character value is cast to OOC_CHAR8 to avoid
             any problems if characters are interpreted as signed values
             by default; that is, '\377' is _not_ -1 *)
          charValue := ORD(s.CharAt(0));
          w. WriteString ("(OOC_CHAR8)'");
          WriteChar(charValue);
          w. WriteChar ("'");
        ELSE
          CASE type OF
          | uint16, char16:
            w. WriteString ("(OOC_CHAR16)");
          | uint32, char32:
            w. WriteString ("(OOC_CHAR32)");
          END;
          charValue := ORD(s.CharAt(0));
          IF (charValue < ORD (" ")) OR (charValue >= 127) OR
             (charValue = ORD ("'")) OR (charValue = ORD ("\")(*"*)) THEN
            w. textWriter. WriteLInt (charValue, 0);
          ELSE
            w. WriteChar ("'");
            w. WriteChar (CHR (charValue));
            w. WriteChar ("'");
          END;
        END;
        
      | value: Boxed.LongReal DO
        paren := (value.value < 0);
        IF paren THEN w.WriteString("(") END;
        w. WriteObject(value.ToString());
        IF (type = real32) THEN
          w. WriteString("f");
        END;
        IF paren THEN w.WriteString(")") END;
        
      | value: BigInt.BigInt DO
        signed := (type < uint8);
        IF signed & (value. ToLongInt() = MIN (LONGINT)) THEN
          (* this assumes that MIN(LONGINT) is also the smallest value of
             the C type "int"; to avoid overflow errors, we must rewrite
             the value slightly *)
          w. WriteString ("(-");
          w. WriteLInt (MAX (LONGINT), 0);
          w. WriteString ("-1)");
        ELSE
          paren := (value.Sign() < 0);
          IF paren THEN w.WriteString("(") END;
          w. WriteObject(value.ToString());
          IF ~signed THEN
            w.WriteString("u");
          END;
          IF paren THEN w.WriteString(")") END;
        END;
        
      | value: Boxed.Set DO
        w.WriteBasicConst(BigInt.NewInt(SYSTEM.VAL(LONGINT, value.value)),
                          type);
      END;
    END;
  END WriteBasicConst;

PROCEDURE (w: Writer) WriteStringConst* (value: Boxed.Object; type: Sym.Type);
(**Writes the C representation of the constant value @oparam{value} to
   @oparam{w}.  This procedure handles all necessary translations to get a
   faithful representation of the value in the language of C.  *)
  CONST
    delim = '"';
    quotedDelim = '\"';
  VAR
    i, len: LONGINT;
    s: STRING;
    
  PROCEDURE WriteOct (ch: LONGINT);
    BEGIN
      w. WriteChar (CHR (ch+ORD("0")));
    END WriteOct;
 
  PROCEDURE WriteChar (charValue : LONGINT);
  BEGIN
    IF (charValue < ORD (" ")) OR (charValue >= 127) OR
      (charValue = ORD ("'")) OR (charValue = ORD ("\")(*"*)) THEN
      w. WriteChar ("\")(*"*); 
      WriteOct (charValue DIV 64);
      WriteOct (charValue DIV 8 MOD 8);
      WriteOct (charValue MOD 8);
    ELSE
      w. WriteChar (CHR (charValue));
    END;
  END WriteChar;
 
  BEGIN
    s := value(Boxed.String).value;
    IF TR.IsPredefType(TR.BaseCharType(type), Predef.char) THEN
      w. WriteChar (delim);
      i := 0; len := s. length;
      WHILE (i # len) DO
        IF (s.CharAt(i) = delim) THEN
          w. WriteString (quotedDelim)
        ELSE  (* note: this is a tidbit slow for large strings *)
          WriteChar(ORD(s.CharAt(i)))
        END;
        INC (i)
      END;
      w. WriteChar (delim);
      
    ELSE
      (* Interesting bit of C knowledge: An expression like `(T){1,2}'
         cannot be passed to a cpp macro, because the preprocessor
         interprets the `,' as its argument separator.  On the other
         hand, `((T){1,2})' works.  *)
      CASE type(Sym.PredefType).id OF
      | Predef.stringLongChar:
        w. WriteString ("((OOC_CHAR16[]){");
      | Predef.stringUCS4Char:
        w. WriteString ("((OOC_CHAR32[]){");
      END;
      i := 0; len := s.length;
      WHILE (i # len) DO
        IF (i # 0) THEN
          w. WriteChar (",");
        END;
        w. textWriter. WriteLInt (ORD(s.NextChar(i)), 0);
      END;
      IF (i # 0) THEN
        w. WriteChar (",");
      END;
      w. textWriter. WriteLInt (0, 0);
      w. WriteString ("})");
    END;
  END WriteStringConst;

PROCEDURE (w: Writer) WriteDeclaration* (d: Declaration);
(**Writes the declaration @oparam{d} to @oparam{w}.  *)
  BEGIN
    d. Write (w)
  END WriteDeclaration;

PROCEDURE (w: Writer) AddDeclaration* (d: Declaration);
(**Adds the declaration @oparam{d} to the list of scheduled declarations of
   @oparam{w}.  All declarations registered this way are written to the file
   when @oproc{Writer.WriteDeclarationList} is called.  *)
  BEGIN
    WITH d: IncludeModule DO
      w. includes. Append (d)
    ELSE
      w. declarations. Append (d)
    END;
  END AddDeclaration;

PROCEDURE (w: Writer) WriteDeclarationList*();
(**Writes out all declarations that have been registered with
   @oproc{w.AddDeclaration}.  All include statements are written first
   (omitting duplicates), followed by the other declarations in the order in
   which they were added.  *)
  
  PROCEDURE WriteIncludes();
    VAR
      i: LONGINT;
    BEGIN
      FOR i := 0 TO w. includes. Size()-1 DO
        w. includes. array[i](IncludeModule). Write (w)
      END
    END WriteIncludes;
  
  PROCEDURE WriteDeclarations();
    VAR
      i: LONGINT;
      d: Declaration;
    BEGIN
      FOR i := 0 TO w. declarations. Size()-1 DO
        d := w. declarations. array[i](Declaration);
        w. WriteDeclaration (d);
        IF ~(d IS Define) THEN
          w. WriteChar (";");
        END;
        w. WriteLn
      END
    END WriteDeclarations;
  
  BEGIN
    WriteIncludes;
    WriteDeclarations
  END WriteDeclarationList;


(* Types
   ------------------------------------------------------------------------ *)

PROCEDURE InitType (t: Type);
  BEGIN
  END InitType;

PROCEDURE (t: Type) Priority (): SHORTINT;
  BEGIN
<*PUSH; Assertions:=TRUE*>
    ASSERT (FALSE);
<*POP*>
  END Priority;

PROCEDURE (t: Type) WriteLeft (w: Writer);
  BEGIN
    ASSERT (FALSE);
  END WriteLeft;

PROCEDURE (t: Type) WriteRight (w: Writer);
  BEGIN
    ASSERT (FALSE);
  END WriteRight;

PROCEDURE WriteLeft (w: Writer; t: Type; callerPri: SHORTINT);
  BEGIN
    t. WriteLeft (w);
    IF (callerPri < t. Priority()) THEN
      w. WriteChar ("(")
    END;
  END WriteLeft;

PROCEDURE WriteRight (w: Writer; t: Type; callerPri: SHORTINT);
  BEGIN
    IF (callerPri < t. Priority()) THEN
      w. WriteChar (")")
    END;
    t. WriteRight (w);
  END WriteRight;



PROCEDURE InitBasicType (bt: BasicType; id: BasicTypeId; repr: ARRAY OF CHAR);
  BEGIN
    InitType (bt);
    bt. id := id;
    COPY (repr, bt. repr);
  END InitBasicType;

PROCEDURE NewBasicType (id: BasicTypeId; repr: ARRAY OF CHAR): BasicType;
  VAR
    bt: BasicType;
  BEGIN
    NEW (bt);
    InitBasicType (bt, id, repr);
    RETURN bt
  END NewBasicType;

PROCEDURE (bt: BasicType) Priority (): SHORTINT;
  BEGIN
    RETURN priName
  END Priority;

PROCEDURE (bt: BasicType) WriteLeft (w: Writer);
  BEGIN
    w. WriteString (bt. repr);
    w. WriteChar (" ")
  END WriteLeft;

PROCEDURE (bt: BasicType) WriteRight (w: Writer);
  BEGIN
  END WriteRight;


PROCEDURE InitPointer (p: Pointer; typeQualifier: TypeQualifier; base: Type);
  BEGIN
    InitType (p);
    p. typeQualifier := typeQualifier;
    p. base := base;
  END InitPointer;

PROCEDURE (w: Writer) NewPointer* (typeQualifier: TypeQualifier; base: Type): Pointer;
  VAR
    p: Pointer;
  BEGIN
    NEW (p);
    InitPointer (p, typeQualifier, base);
    RETURN p
  END NewPointer;

PROCEDURE (p: Pointer) Priority (): SHORTINT;
  BEGIN
    RETURN priPointer
  END Priority;

PROCEDURE (p: Pointer) WriteLeft (w: Writer);
  BEGIN
    WriteLeft (w, p. base, priPointer);
    w. WriteChar("*")
  END WriteLeft;

PROCEDURE (p: Pointer) WriteRight (w: Writer);
  BEGIN
    WriteRight (w, p. base, priPointer);
  END WriteRight;



PROCEDURE InitArray (a: Array; base: Type; size: LONGINT);
  BEGIN
    InitType (a);
    a. base := base;
    a. size := size;
  END InitArray;

PROCEDURE (w: Writer) NewArray* (base: Type; size: LONGINT): Array;
  VAR
    a: Array;
  BEGIN
    NEW (a);
    InitArray (a, base, size);
    RETURN a
  END NewArray;

PROCEDURE (a: Array) Priority (): SHORTINT;
  BEGIN
    RETURN priArray
  END Priority;

PROCEDURE (a: Array) WriteLeft (w: Writer);
  BEGIN
    WriteLeft (w, a. base, priArray)
  END WriteLeft;

PROCEDURE (a: Array) WriteRight (w: Writer);
  BEGIN
    w. WriteChar ("[");
    IF (a. size >= 0) THEN
      w. WriteLInt (a. size, 0);
    END;
    w. WriteChar ("]");
    WriteRight (w, a. base, priArray);
  END WriteRight;



PROCEDURE InitFunction (fct: Function; resultType: Type; restParameters: BOOLEAN);
  BEGIN
    fct. resultType := resultType;
    fct. parameters := ArrayList.New (4);
    fct. restParameters := restParameters;
    fct. noReturn := FALSE;
    fct. callConv := Sym.callConvDefault;
  END InitFunction;

PROCEDURE (w: Writer) NewFunction* (resultType: Type; restParameters: BOOLEAN): Function;
  VAR
    fct: Function;
  BEGIN
    NEW (fct);
    InitFunction (fct, resultType, restParameters);
    RETURN fct
  END NewFunction;

PROCEDURE (fct: Function) SetNoReturn* (noReturn: BOOLEAN);
  BEGIN
    fct.noReturn := noReturn;
  END SetNoReturn;

PROCEDURE (fct: Function) SetCallConv* (callConv: Sym.CallConv);
  BEGIN
    fct.callConv := callConv;
  END SetCallConv;

PROCEDURE (fct: Function) AddParameter* (param: Declaration);
  BEGIN
    fct. parameters. Append (param)
  END AddParameter;

PROCEDURE (fct: Function) MakeParametersVolatile*();
  VAR
    i: LONGINT;
    param: Declaration;
  BEGIN
    FOR i := 0 TO fct.parameters.size-1 DO
      param := fct.parameters.array[i](Declaration);
      IF (param.typeQualifier = tqNone) THEN
        param.typeQualifier := tqVolatile;
      END;
    END;
  END MakeParametersVolatile;


PROCEDURE (fct: Function) Priority (): SHORTINT;
  BEGIN
    RETURN priFunction
  END Priority;

PROCEDURE (fct: Function) WriteLeft (w: Writer);
  BEGIN
    WriteLeft (w, fct. resultType, priFunction);
    IF fct.noReturn THEN
      w.WriteString("NORETURN ");
    END;
    CASE fct.callConv OF
    | Sym.callConvC:
      (* w.WriteString("__attribute__ ((cdecl)) "); *)
    | Sym.callConvPascal:
      w.WriteString("__attribute__ ((stdcall)) ");
    | Sym.callConvFastcall:
      w.WriteString("__attribute__ ((fastcall)) ");
    ELSE
    END;
  END WriteLeft;

PROCEDURE (fct: Function) WriteRight (w: Writer);
  VAR
    i: LONGINT;
  BEGIN
    IF (fct.parameters.Size() = 0) THEN
      w. WriteString("(void)");
    ELSE
      w. WriteChar("(");
      FOR i := 0 TO fct. parameters. Size()-1 DO
        IF (i # 0) THEN
          w. WriteString (", ")
        END;
        w. WriteDeclaration (fct. parameters. array[i](Declaration))
      END;
      IF fct. restParameters THEN
        w. WriteString (", ...");
      END;
      w. WriteChar(")");
    END;
    WriteRight (w, fct. resultType, priFunction);
    IF fct.noReturn THEN
      w.WriteString(" NORETURN2");
    END;
  END WriteRight;

(* -------- *)

PROCEDURE InitStruct (struct: Struct; isUnion: BOOLEAN; name: STRING);
  BEGIN
    struct. isUnion := isUnion;
    struct. members := ArrayList.New (4);
    struct. name := name;
  END InitStruct;

PROCEDURE (w: Writer) NewStruct* (isUnion: BOOLEAN; name: STRING): Struct;
  VAR
    struct: Struct;
  BEGIN
    NEW (struct);
    InitStruct (struct, isUnion, name);
    RETURN struct
  END NewStruct;

PROCEDURE (struct: Struct) AddMember* (param: Declaration);
  BEGIN
    struct. members. Append (param)
  END AddMember;

PROCEDURE (struct: Struct) AddPadding* (w: Writer; offset: LONGINT);
  VAR
    str: ARRAY 32 OF CHAR;
  BEGIN
    IntStr.IntToStr (offset, str);
    Strings.Insert ("__pad", 0, str);
    struct. AddMember (w. NewDeclaration (Object.NewLatin1(str), tqNone, scMember,
                                          w. basicType[char8]));
  END AddPadding;

PROCEDURE (struct: Struct) Priority (): SHORTINT;
  BEGIN
    RETURN priStruct
  END Priority;

PROCEDURE (struct: Struct) WriteLeft (w: Writer);
  VAR
    i: LONGINT;
  BEGIN
    IF struct. isUnion THEN
      w. WriteString ("union");
    ELSE
      w. WriteString ("struct");
    END;
    IF (struct. name # NIL) THEN
      w. WriteString (" ");
      w. WriteObject (struct. name);
    END;
    w. WriteString (" {");
    w. Indent (1);
    FOR i := 0 TO struct. members. Size()-1 DO
      w. Newline;
      w. WriteDeclaration (struct. members. array[i](Declaration));
      w. WriteString (";")
    END;
    IF (struct. members. Size() = 0) THEN
      (* avoid an empty struct (and a possible warning)
         by writing out a dummy member *)
      w. Newline;
      w. WriteString ("char __dummy;");
    END;
    w. Indent (-1);
    w. Newline;
    w. WriteString ("} ");
  END WriteLeft;

PROCEDURE (struct: Struct) WriteRight (w: Writer);
  BEGIN
  END WriteRight;

(* -------- *)

PROCEDURE InitTypeRef (typeRef: TypeRef; class: TypeRefClass; name: STRING);
  BEGIN
    typeRef. class := class;
    typeRef. name := name;
  END InitTypeRef;

PROCEDURE (w: Writer) NewTypeRef* (class: TypeRefClass; name: STRING): TypeRef;
  VAR
    typeRef: TypeRef;
  BEGIN
    NEW (typeRef);
    InitTypeRef (typeRef, class, name);
    RETURN typeRef
  END NewTypeRef;

PROCEDURE (typeRef: TypeRef) Priority (): SHORTINT;
  BEGIN
    RETURN priName
  END Priority;

PROCEDURE (typeRef: TypeRef) WriteLeft (w: Writer);
  BEGIN
    CASE typeRef. class OF
    | refTypedef:
    | refStruct : w. WriteString ("struct ");
    | refUnion  : w. WriteString ("union ");
    END;
    w. WriteObject (typeRef. name);
    w. WriteChar (" ");
  END WriteLeft;

PROCEDURE (typeRef: TypeRef) WriteRight (w: Writer);
  BEGIN
  END WriteRight;


PROCEDURE (w: Writer) WriteType* (t: Type);
  BEGIN
    t. WriteLeft (w);
    t. WriteRight (w)
  END WriteType;




(* Declarations
   ------------------------------------------------------------------------ *)

PROCEDURE InitDeclaration (d: Declaration; name: STRING;
                           typeQualifier: TypeQualifier;
                           storageClass: StorageClass; type: Type);
  BEGIN
    d. name := name;
    d. typeQualifier := typeQualifier;
    d. storageClass := storageClass;
    d. type := type
  END InitDeclaration;

PROCEDURE (w: Writer) NewDeclaration* (name: STRING; typeQualifier: TypeQualifier; storageClass: StorageClass; type: Type): Declaration;
  VAR
    d: Declaration;
  BEGIN
    NEW (d);
    InitDeclaration (d, name, typeQualifier, storageClass, type);
    RETURN d
  END NewDeclaration;

PROCEDURE (d: Declaration) SetTypeQualifier*(typeQualifier: TypeQualifier);
  BEGIN
    d.typeQualifier := typeQualifier;
  END SetTypeQualifier;

PROCEDURE (d: Declaration) Write (w: Writer);
  PROCEDURE WriteTypeQualifier (w: Writer; typeQualifier: TypeQualifier);
    BEGIN
      CASE typeQualifier OF
      | tqNone    :
      | tqConst   : w. WriteString ("const ")
      | tqVolatile: w. WriteString ("volatile ")
      END
    END WriteTypeQualifier;

  BEGIN
    CASE d. storageClass OF
    | scMember  :
    | scTypedef : w. WriteString ("typedef ")
    | scExtern  : w. WriteString ("extern ")
    | scStatic  : w. WriteString ("static ")
    | scAuto    :
    | scRegister: w. WriteString ("register ")
    | scForceAuto: w. WriteString ("auto ")
    END;
    WriteTypeQualifier (w, d. typeQualifier);
    WriteLeft (w, d. type, priDeclaration);
    w. WriteObject (d. name);
    WriteRight (w, d. type, priDeclaration)
  END Write;



PROCEDURE InitIncludeModule (d: IncludeModule; module: Repository.Module);
  BEGIN
    InitDeclaration (d, NIL, tqNone, scAuto, NIL);
    d. module := module;
  END InitIncludeModule;

PROCEDURE (w: Writer) NewIncludeModule* (module: Repository.Module): IncludeModule;
  VAR
    d: IncludeModule;
  BEGIN
    ASSERT(module # NIL);
    NEW (d);
    InitIncludeModule (d, module);
    RETURN d
  END NewIncludeModule;

PROCEDURE (w: Writer) WriteModuleInclude*(m: Repository.Module;
                                          fileId: Repository.FileId);
  VAR
    path: STRING;
    chars: Object.CharsLatin1;
  BEGIN
    path := FileSystem.ModuleToFileName(m.name^)+
        m.origin.GetDefaultSuffix(fileId);
    chars := path(Object.String8).CharsLatin1();
    w. WriteInclude(chars^);
  END WriteModuleInclude;

PROCEDURE (d: IncludeModule) Write (w: Writer);
  BEGIN
    w.WriteModuleInclude(d.module, Repository.modHeaderFileC);
  END Write;


PROCEDURE InitDefine (d: Define; name: STRING;
                      const: Boxed.Object; oocType: Sym.Type);
  BEGIN
    InitDeclaration (d, name, tqNone, scAuto, NIL);
    d. const := const;
    d. oocType := oocType;
  END InitDefine;

PROCEDURE (w: Writer) NewDefine* (name: STRING;
                                  const: Boxed.Object;
                                  oocType: Sym.Type): Define;
  VAR
    d: Define;
  BEGIN
    NEW (d);
    InitDefine (d, name, const, oocType);
    RETURN d
  END NewDefine;

PROCEDURE (d: Define) Write (w: Writer);
  BEGIN
    w. WriteString ("#define ");
    w. WriteObject (d. name);
    w. WriteString (" ");
    IF (d. const = NIL) THEN
      w. WriteString (" 0");             (* NULL *)
    ELSIF (d. oocType = NIL) THEN
      w. WriteConst (d. const, Predef.GetType (Predef.stringChar));
    ELSE
      w. WriteConst (d. const, d. oocType);
    END;
  END Write;



PROCEDURE (w: Writer) WriteTypeCast* (t: Type);
  BEGIN
    w. WriteChar ("(");
    t. WriteLeft (w);
    t. WriteRight (w);
    w. WriteChar (")");
  END WriteTypeCast;


(*
<*PUSH; Warnings:=FALSE*>
PROCEDURE Test;
  VAR
    w: Writer;
    fct: Type;
    res: Msg.Msg;
    r: TextRider.Reader;
    
  PROCEDURE Cmp (t: Type; expected: ARRAY OF CHAR);
    VAR
      result: ARRAY 4*1024 OF CHAR;
    BEGIN
      w. WriteDeclaration (w. NewDeclaration ("x", tqNone, scAuto, t));
      w. WriteLn;
      
      r. ReadLine (result);
      ASSERT (r. res = NIL);
      
      IF (result # expected) THEN
        Err.String ("expected: "); Err.String (expected); Err.Ln;
        Err.String ("but got : "); Err.String (result); Err.Ln;
        HALT (1)
      ELSE
        Err.String ("done: "); Err.String (result); Err.Ln;
      END
    END Cmp;
  
  BEGIN
    Err.String ("Running OOC:C:WriteDecl.Test...");
    Err.Ln;

    w := NewWriter(Memory.Open(), NIL);
    ASSERT (w. ch # NIL);
    r := TextRider.ConnectReader (w. ch);
    ASSERT (r # NIL);

    w.basicType[int32] := NewBasicType (int32, "int");  (*change name for test*)
    Cmp(w.basicType[int32], "int x");
    Cmp(w. NewPointer (tqNone, w.basicType[int32]), "int *x");
    Cmp(w. NewArray (w.basicType[int32], 8), "int x[8]");
    Cmp(w. NewArray (w. NewPointer (tqNone, w.basicType[int32]), 8), "int *x[8]");
    Cmp(w. NewPointer (tqNone, w. NewArray (w.basicType[int32], 8)), "int (*x)[8]");
    Cmp(w. NewArray (w. NewArray (w.basicType[int32], 8), 4), "int x[4][8]");
    
    fct := w. NewFunction (w.basicType[int32], FALSE);
    Cmp (fct, "int x()");
    fct := w. NewFunction (w. NewPointer (tqNone, w.basicType[int32]), FALSE);
    Cmp (fct, "int *x()");
    fct := w. NewFunction (w. NewArray (w.basicType[int32], 8), FALSE);
    Cmp (fct, "int x()[8]");
    
    fct := w. NewPointer (tqNone, w. NewFunction (w.basicType[int32], FALSE));
    Cmp (fct, "int (*x)()");
    fct := w. NewPointer (tqNone, w. NewFunction (w. NewPointer (tqNone, w.basicType[int32]), FALSE));
    Cmp (fct, "int *(*x)()");
    fct := w. NewPointer (tqNone, w. NewFunction (w. NewArray (w.basicType[int32], 8), FALSE));
    Cmp (fct, "int (*x)()[8]");
    
    fct := w. NewArray (w. NewFunction (w.basicType[int32], FALSE), 4);
    Cmp (fct, "int x[4]()");
    fct := w. NewArray (w. NewFunction (w. NewPointer (tqNone, w.basicType[int32]), FALSE), 4);
    Cmp (fct, "int *x[4]()");
    fct := w. NewArray (w. NewFunction (w. NewArray (w.basicType[int32], 8), FALSE), 4);
    Cmp (fct, "int x[4]()[8]");
    
    
    Err.String ("no errors"); Err.Ln
  END Test;
<*POP*>
*)*)*)*)*)

BEGIN
  (*Test;*)
END OOC:C:DeclWriter.
