(* 	$Id$	 *)
MODULE OOC:C:DeclWriter [OOC_EXTENSIONS];
(*  Defines classes to handle C declarations, types, and include statements.
    Copyright (C) 2001, 2002  Michael van Acken

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
  Channel, Err, Files, Msg, TextRider, ADT:Object, ADT:String, ADT:ArrayList,
  URI, FileURI := URI:Scheme:File, IO:Memory, 
  Language, Language:Boolean, Language:String8,
  Language:Integer,
  OOC:Repository, Sym := OOC:SymbolTable, OOC:SymbolTable:Predef;
  


TYPE
  TypeQualifier* = SHORTINT;
  (**Type qualifier of a definition.  One of @oconst{tqNone}, @oconst{tqConst},
     or @oconst{tqVolatile}.  Qualifiers are mutually exclusive, that is, only
     one of them applies.  They can be used connection with pointers
     (@oproc{Writer.NewPointer}) or declarations (@oproc{Writer.NewDeclaration}).  *)

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
  (**This type is mapped to the name @code{OOC_INT8}, a unsigned integer type
     holding (at least) 8 bits.  *)
  uint16* = 7;
  (**This type is mapped to the name @code{OOC_INT16}, a unsigned integer type
     holding (at least) 16 bits.  *)
  uint32* = 8;
  (**This type is mapped to the name @code{OOC_INT32}, a unsigned integer type
     holding (at least) 32 bits.  *)
  uint64* = 9;
  (**This type is mapped to the name @code{OOC_INT64}, a unsigned integer type
     holding (at least) 64 bits.  *)
  char8* = 10;
  (**This type is mapped to the name @code{OOC_CHAR8}, the type used to store 8
     bit character values.  This in turn is an alias for @code{unsigned char}.  *)
  char16* = 11;
  (**This type is mapped to the name @code{OOC_CHAR16}, the type used to store
     16 bit character values.  Usually, this is equvalient to @oconst{uint16}.  *)
  real32* = 12;
  (**This is mapped to the IEEE 754 single precision floating point type,
     usually @code{float}.  *)
  real64* = 13;
  (**This is mapped to the IEEE 754 double precision floating point type,
     usually @code{double}.  *)
  
  lengthType* = 14;
  (**This basic type is used to store the length of arrays.  On the C level, it
     is an alias for a signed integer type.  On 32 bit targets, @oconst{int32}
     and @oconst{lengthType} are mapped to the same C type.  When working on
     the level of the @emph{input} language, the symbol type
     @oconst{*OOC:SymbolTable:Predef.lengthType} should be used.  *)
  
  lastBasicType = lengthType;

  
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
    base: Type;
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
  END;

TYPE
  Struct* = POINTER TO StructDesc;
  StructDesc = RECORD
    (TypeDesc)
    isUnion: BOOLEAN;
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
    name: String.String;
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
    name: String.String;
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
    const: Language.Value;
  END;
  
TYPE
  Writer* = POINTER TO WriterDesc;
  WriterDesc* = RECORD
    (**This writer is wrapper around of @otype{TextRider.Writer} with
       additional knowledge about C declarations, definitions, and literals.
       Its main purpose is to act as an abstraction layer for the not so easy
       task of writing C type expressions.  *)
    ch: Channel.Channel;
    baseURI: URI.HierarchicalURI;
    textWriter: TextRider.Writer;
    
    includes: ArrayList.ArrayList;
    declarations: ArrayList.ArrayList;
    
    relativeIncludePaths: BOOLEAN;
    (**If TRUE, then include paths are written relative to @ofield{baseURI};
       otherwise, they are written as absolute paths.  *)
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

PROCEDURE InitWriter (w: Writer; ch: Channel.Channel;
                      baseURI: URI.HierarchicalURI);
  PROCEDURE CreateBasicType (id: BasicTypeId; repr: ARRAY OF CHAR);
    BEGIN
      w. basicType[id] := NewBasicType (id, repr)
    END CreateBasicType;
  
  BEGIN
    w. ch := ch;
    w. baseURI := baseURI;
    w. indentation := 0;
    
    w. relativeIncludePaths := (baseURI # NIL);
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
    CreateBasicType (real32, "OOC_REAL32");
    CreateBasicType (real64, "OOC_REAL64");
    CreateBasicType (lengthType, "OOC_LEN");
  END InitWriter;

PROCEDURE NewWriter* (ch: Channel.Channel;
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
    dest. relativeIncludePaths := w. relativeIncludePaths;
    dest. basicType := w. basicType;
  END CopyTo;

PROCEDURE (w: Writer) WriteString* (str[NO_COPY]: ARRAY OF CHAR);
  BEGIN
    w. textWriter. WriteString (str)
  END WriteString;

PROCEDURE (w: Writer) WriteChar* (ch: CHAR);
  BEGIN
    w. textWriter. WriteChar (ch)
  END WriteChar;

PROCEDURE (w: Writer) WriteLn*;
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

PROCEDURE (w: Writer) Newline*;
  VAR
    i: LONGINT;
  BEGIN
    w. WriteLn;
    FOR i := 1 TO w. indentation DO
      w. WriteString ("  ");
    END;
  END Newline;

PROCEDURE (w: Writer) WriteInclude* (includeURI: URI.HierarchicalURI);
(**Write an include statement @code{#include "@dots{}"} for the indicated file.

   @precond
   @samp{@oparam{includeURI} IS @otype{FileURI.URI}}
   @end precond *)
  VAR
    relativeURI: URI.URI;
    str: ARRAY 1024 OF CHAR;
  BEGIN
    IF w. relativeIncludePaths THEN
      relativeURI := includeURI. MakeRelative (w. baseURI);
      relativeURI. GetString (str);
    ELSE
      includeURI(FileURI.URI). GetPath (str)
    END;
    w. WriteString ('#include "');
    IF (str[0] # "/") & (str[0] # ".") THEN
      w. WriteString ("./")
    END;
    w. WriteString (str);
    w. WriteString ('"');
    w. WriteLn
  END WriteInclude;
  
PROCEDURE (w: Writer) Close* (VAR res: Msg.Msg);
(**Closes the writer's output channel.  Any error in the text writer, while
   registering the file, or closing the channel is reported back in
   @oparam{res}.  A @oparam{res} of @code{NIL} indicates success.  *)
  BEGIN
    res := w. textWriter. res;
    IF (w. ch IS Files.File) THEN
      w. ch(Files.File). Register;
    END;
    IF (w. ch. res # NIL) & (res = NIL) THEN
      res := w. ch. res
    END;
    w. ch. Close();
    IF (w. ch. res # NIL) & (res = NIL) THEN
      res := w. ch. res
    END;
  END Close;

PROCEDURE (w: Writer) WriteConst* (value: Language.Value; type: Sym.Type);
(**Writes the C representation of the constant value @oparam{value} to
   @oparam{w}.  This procedure handles all necessary translations to get a
   faithful representation of the value in the language of C.  *)
  CONST
    delim = '"';
    quotedDelim = '\"';
  VAR
    i, len, charValue: LONGINT;
    str : String.String;

  PROCEDURE WriteOct (ch: LONGINT);
    BEGIN
      w. WriteChar (CHR (ch+ORD("0")));
    END WriteOct;
  
  BEGIN
    WITH value: Boolean.Value DO
      IF value. value THEN
        w. WriteString("OOC_TRUE")
      ELSE
        w. WriteString("OOC_FALSE")
      END
      
    | value: String8.Value DO
      IF (type(Sym.PredefType). id = Predef.char) THEN
        charValue := ORD (value. value. array[0]);
        w. WriteChar ("'");
        IF (charValue < ORD (" ")) OR (charValue >= 127) OR
           (charValue = ORD ("'")) OR (charValue = ORD ("\")(*"*)) THEN
          w. WriteChar ("\")(*"*); 
          WriteOct (charValue DIV 64);
          WriteOct (charValue DIV 8 MOD 8);
          WriteOct (charValue MOD 8);
        ELSE
          w. WriteChar (CHR (charValue));
        END;
        w. WriteChar ("'");
      ELSE
        w. WriteChar (delim);
        i := 0; len := value. value. length;
        WHILE (i # len) DO
          IF (value. value. array[i] = delim) THEN
            w. WriteString (quotedDelim)
          ELSE  (* note: this is a tidbit slow for large strings *)
            w. WriteChar (value. value. array[i])
          END;
          INC (i)
        END;
        w. WriteChar (delim);
      END;
      
    | value: Integer.Value DO
      IF (value. ToLInt() = MIN (LONGINT)) THEN
        (* this assumes that MIN(LONGINT) is also the smallest value of
           the C type "int"; to avoid overflow errors, we must rewrite
           the value slightly *)
        w. WriteString ("(-");
        w. WriteLInt (MAX (LONGINT), 0);
        w. WriteString ("-1)");
      ELSE
        str := value.ToString();
        w. WriteString(str.array^);
      END;
    END
  END WriteConst;

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

PROCEDURE (w: Writer) WriteDeclarationList*;
(**Writes out all declarations that have been registered with
   @oproc{w.AddDeclaration}.  All include statements are written first
   (omittend duplicates), followed by the other declarations in the order in
   which they were added.  *)
  
  PROCEDURE WriteIncludes;
    VAR
      i: LONGINT;
    BEGIN
      FOR i := 0 TO w. includes. Size()-1 DO
        w. includes. array[i](IncludeModule). Write (w)
      END
    END WriteIncludes;
  
  PROCEDURE WriteDeclarations;
    VAR
      i: LONGINT;
    BEGIN
      FOR i := 0 TO w. declarations. Size()-1 DO
        w. WriteDeclaration (w. declarations. array[i](Declaration));
        w. WriteChar (";");
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
    ASSERT (FALSE); RETURN -1;
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



PROCEDURE InitFunction (fct: Function; resultType: Type);
  BEGIN
    fct. resultType := resultType;
    fct. parameters := ArrayList.New (4);
  END InitFunction;

PROCEDURE (w: Writer) NewFunction* (resultType: Type): Function;
  VAR
    fct: Function;
  BEGIN
    NEW (fct);
    InitFunction (fct, resultType);
    RETURN fct
  END NewFunction;

PROCEDURE (fct: Function) AddParameter* (param: Declaration);
  BEGIN
    fct. parameters. Append (param)
  END AddParameter;


PROCEDURE (fct: Function) Priority (): SHORTINT;
  BEGIN
    RETURN priFunction
  END Priority;

PROCEDURE (fct: Function) WriteLeft (w: Writer);
  BEGIN
    WriteLeft (w, fct. resultType, priFunction);
  END WriteLeft;

PROCEDURE (fct: Function) WriteRight (w: Writer);
  VAR
    i: LONGINT;
  BEGIN
    w. WriteChar("(");
    FOR i := 0 TO fct. parameters. Size()-1 DO
      IF (i # 0) THEN
        w. WriteString (", ")
      END;
      w. WriteDeclaration (fct. parameters. array[i](Declaration))
    END;
    w. WriteChar(")");
    WriteRight (w, fct. resultType, priFunction)
  END WriteRight;

(* -------- *)

PROCEDURE InitStruct (struct: Struct; isUnion: BOOLEAN);
  BEGIN
    struct. isUnion := isUnion;
    struct. members := ArrayList.New (4);
  END InitStruct;

PROCEDURE (w: Writer) NewStruct* (isUnion: BOOLEAN): Struct;
  VAR
    struct: Struct;
  BEGIN
    NEW (struct);
    InitStruct (struct, isUnion);
    RETURN struct
  END NewStruct;

PROCEDURE (struct: Struct) AddMember* (param: Declaration);
  BEGIN
    struct. members. Append (param)
  END AddMember;


PROCEDURE (struct: Struct) Priority (): SHORTINT;
  BEGIN
    RETURN priStruct
  END Priority;

PROCEDURE (struct: Struct) WriteLeft (w: Writer);
  VAR
    i: LONGINT;
  BEGIN
    IF struct. isUnion THEN
      w. WriteString ("union {");
    ELSE
      w. WriteString ("struct {");
    END;
    w. Indent (1);
    FOR i := 0 TO struct. members. Size()-1 DO
      w. Newline;
      w. WriteDeclaration (struct. members. array[i](Declaration));
      w. WriteString (";")
    END;
    w. Indent (-1);
    w. Newline;
    w. WriteString ("} ");
  END WriteLeft;

PROCEDURE (struct: Struct) WriteRight (w: Writer);
  BEGIN
  END WriteRight;

(* -------- *)

PROCEDURE InitTypeRef (typeRef: TypeRef; class: TypeRefClass; name: String.String);
  BEGIN
    typeRef. class := class;
    typeRef. name := name;
  END InitTypeRef;

PROCEDURE (w: Writer) NewTypeRef* (class: TypeRefClass; name: String.String): TypeRef;
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
    w. WriteString (typeRef. name. array^);
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

PROCEDURE InitDeclaration (d: Declaration; name: String.String;
                           typeQualifier: TypeQualifier;
                           storageClass: StorageClass; type: Type);
  BEGIN
    Object.Init (d);
    d. name := name;
    d. typeQualifier := typeQualifier;
    d. storageClass := storageClass;
    d. type := type
  END InitDeclaration;

PROCEDURE (w: Writer) NewDeclaration* (name: String.String; typeQualifier: TypeQualifier; storageClass: StorageClass; type: Type): Declaration;
  VAR
    d: Declaration;
  BEGIN
    NEW (d);
    InitDeclaration (d, name, typeQualifier, storageClass, type);
    RETURN d
  END NewDeclaration;

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
    END;
    WriteTypeQualifier (w, d. typeQualifier);
    WriteLeft (w, d. type, priDeclaration);
    w. WriteString (d. name. array^);
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
    NEW (d);
    InitIncludeModule (d, module);
    RETURN d
  END NewIncludeModule;

PROCEDURE (d: IncludeModule) Write (w: Writer);
  BEGIN
    w. WriteInclude (d. module. GetURI (Repository.modHeaderFileC))
  END Write;


PROCEDURE InitDefine (d: Define; name: String.String;
                      const: Language.Value);
  BEGIN
    InitDeclaration (d, name, tqNone, scAuto, NIL);
    d. const := const;
  END InitDefine;

PROCEDURE (w: Writer) NewDefine* (name: String.String;
                                  const: Language.Value): Define;
  VAR
    d: Define;
  BEGIN
    NEW (d);
    InitDefine (d, name, const);
    RETURN d
  END NewDefine;

PROCEDURE (d: Define) Write (w: Writer);
  BEGIN
    w. WriteString ("#define ");
    w. WriteString (d. name. array^);
    w. WriteString (" ");
    w. WriteConst (d. const, Predef.GetType (Predef.charString));
  END Write;




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
      w. WriteDeclaration (w. NewDeclaration (String.New ("x"), tqNone, scAuto, t));
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

    w := NewWriter(Memory.Tmp("", {Memory.write, Memory.read}, res), NIL);
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
    
    fct := w. NewFunction (w.basicType[int32]);
    Cmp (fct, "int x()");
    fct := w. NewFunction (w. NewPointer (tqNone, w.basicType[int32]));
    Cmp (fct, "int *x()");
    fct := w. NewFunction (w. NewArray (w.basicType[int32], 8));
    Cmp (fct, "int x()[8]");
    
    fct := w. NewPointer (tqNone, w. NewFunction (w.basicType[int32]));
    Cmp (fct, "int (*x)()");
    fct := w. NewPointer (tqNone, w. NewFunction (w. NewPointer (tqNone, w.basicType[int32])));
    Cmp (fct, "int *(*x)()");
    fct := w. NewPointer (tqNone, w. NewFunction (w. NewArray (w.basicType[int32], 8)));
    Cmp (fct, "int (*x)()[8]");
    
    fct := w. NewArray (w. NewFunction (w.basicType[int32]), 4);
    Cmp (fct, "int x[4]()");
    fct := w. NewArray (w. NewFunction (w. NewPointer (tqNone, w.basicType[int32])), 4);
    Cmp (fct, "int *x[4]()");
    fct := w. NewArray (w. NewFunction (w. NewArray (w.basicType[int32], 8)), 4);
    Cmp (fct, "int x[4]()[8]");
    
    
    Err.String ("no errors"); Err.Ln
  END Test;

BEGIN
  (*Test;*)
END OOC:C:DeclWriter.
