MODULE OOC:C:WriteDecl [OOC_EXTENSIONS];

IMPORT
  TextRider, ADT:Object, ADT:String, ADT:ArrayList,
  URI, FileURI := URI:Scheme:File,
  IO:Memory, Msg, Err, 
  OOC:Repository;
  


TYPE
  TypeQualifier* = SHORTINT;

CONST
  tqNone* = 0;
  tqConst* = 1;
  tqVolatile* = 2;
  
TYPE
  Type* = POINTER TO TypeDesc;
  TypeDesc = RECORD [ABSTRACT]
  END;

TYPE
  BasicTypeId* = SHORTINT;
  
CONST
  void* = 0;
  ptr* = 1;
  int8* = 2;
  int16* = 3;
  int32* = 4;
  int64* = 5;
  uint8* = 6;
  uint16* = 7;
  uint32* = 8;
  uint64* = 9;
  char8* = 10;
  char16* = 11;
  real32* = 12;
  real64* = 13;
  lastBasicType = real64;
  
TYPE
  BasicType = POINTER TO BasicTypeDesc;
  BasicTypeDesc = RECORD
    (TypeDesc)
    id: BasicTypeId;
    repr-: ARRAY 32 OF CHAR;
  END;

TYPE
  Pointer* = POINTER TO PointerDesc;
  PointerDesc = RECORD
    (TypeDesc)
    typeQualifier: TypeQualifier;
    base: Type;
  END;

TYPE
  Array* = POINTER TO ArrayDesc;
  ArrayDesc = RECORD
    (TypeDesc)
    base: Type;
    size: LONGINT;
  END;

TYPE
  Function* = POINTER TO FunctionDesc;
  FunctionDesc = RECORD
    (TypeDesc)
    resultType: Type;
    parameters: ArrayList.ArrayList;
  END;


TYPE
  StorageClass* = SHORTINT;

CONST
  scMember* = 0;                         (* applies to struct/union members *)
  scTypedef* = 1;
  scExtern* = 2;
  scStatic* = 3;
  scAuto* = 4;
  scRegister* = 5;

TYPE
  Declaration* = POINTER TO DeclarationDesc;
  DeclarationDesc = RECORD
    (Object.ObjectDesc)
    typeQualifier: TypeQualifier;
    storageClass: StorageClass;
    type: Type;
    name: String.String;
  END;
  
TYPE
  Block* = POINTER TO BlockDesc;
  BlockDesc = RECORD
    includes: ArrayList.ArrayList;
    declarations: ArrayList.ArrayList;
    
    relativeIncludePaths: BOOLEAN;
    (**If TRUE, then include paths are written relative to the repository base;
       otherwise, they are written as absolute paths.  *)
  END;


VAR
  basicType-: ARRAY lastBasicType+1 OF BasicType;


CONST
  priName = 0;
  priPointer = 1;
  priArray = 2;
  priFunction = 2;
  priDeclaration = 3;


PROCEDURE InitBlock* (b: Block);
  BEGIN
    b. includes := ArrayList.New (4);
    b. declarations := ArrayList.New (16);
    b. relativeIncludePaths := FALSE;
    (* NOTE: relative paths are broken, because the file name are not
       rewritten relative to the current file name... FIXME *)
  END InitBlock;

PROCEDURE NewBlock* (): Block;
  VAR
    b: Block;
  BEGIN
    NEW (b);
    InitBlock (b);
    RETURN b
  END NewBlock;

PROCEDURE (b: Block) IncludeModule* (module: Repository.Module);
  BEGIN
    IF ~b. includes. Contains (module) THEN
      b. includes. Append (module)
    END
  END IncludeModule;


(* Types
   ------------------------------------------------------------------------ *)

PROCEDURE InitType (t: Type);
  BEGIN
  END InitType;

PROCEDURE (t: Type) [ABSTRACT] Priority* (): SHORTINT;
  END Priority;

PROCEDURE (t: Type) [ABSTRACT] WriteLeft* (w: TextRider.Writer);
  END WriteLeft;

PROCEDURE (t: Type) [ABSTRACT] WriteRight* (w: TextRider.Writer);
  END WriteRight;

PROCEDURE ^ (d: Declaration) Write* (w: TextRider.Writer);

PROCEDURE WriteLeft (w: TextRider.Writer; t: Type; callerPri: SHORTINT);
  BEGIN
    t. WriteLeft (w);
    IF (callerPri < t. Priority()) THEN
      w. WriteChar ("(")
    END;
  END WriteLeft;

PROCEDURE WriteRight (w: TextRider.Writer; t: Type; callerPri: SHORTINT);
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

PROCEDURE (bt: BasicType) Priority* (): SHORTINT;
  BEGIN
    RETURN priName
  END Priority;

PROCEDURE (bt: BasicType) WriteLeft* (w: TextRider.Writer);
  BEGIN
    w. WriteString (bt. repr);
    w. WriteChar (" ")
  END WriteLeft;

PROCEDURE (bt: BasicType) WriteRight* (w: TextRider.Writer);
  BEGIN
  END WriteRight;


PROCEDURE InitPointer (p: Pointer; typeQualifier: TypeQualifier; base: Type);
  BEGIN
    InitType (p);
    p. typeQualifier := typeQualifier;
    p. base := base;
  END InitPointer;

PROCEDURE (b: Block) NewPointer* (typeQualifier: TypeQualifier; base: Type): Pointer;
  VAR
    p: Pointer;
  BEGIN
    NEW (p);
    InitPointer (p, typeQualifier, base);
    RETURN p
  END NewPointer;

PROCEDURE (p: Pointer) Priority* (): SHORTINT;
  BEGIN
    RETURN priPointer
  END Priority;

PROCEDURE (p: Pointer) WriteLeft* (w: TextRider.Writer);
  BEGIN
    WriteLeft (w, p. base, priPointer);
    w. WriteChar("*")
  END WriteLeft;

PROCEDURE (p: Pointer) WriteRight* (w: TextRider.Writer);
  BEGIN
    WriteRight (w, p. base, priPointer);
  END WriteRight;



PROCEDURE InitArray (a: Array; base: Type; size: LONGINT);
  BEGIN
    InitType (a);
    a. base := base;
    a. size := size;
  END InitArray;

PROCEDURE (b: Block) NewArray* (base: Type; size: LONGINT): Array;
  VAR
    a: Array;
  BEGIN
    NEW (a);
    InitArray (a, base, size);
    RETURN a
  END NewArray;

PROCEDURE (a: Array) Priority* (): SHORTINT;
  BEGIN
    RETURN priArray
  END Priority;

PROCEDURE (a: Array) WriteLeft* (w: TextRider.Writer);
  BEGIN
    WriteLeft (w, a. base, priArray)
  END WriteLeft;

PROCEDURE (a: Array) WriteRight* (w: TextRider.Writer);
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

PROCEDURE (b: Block) NewFunction* (resultType: Type): Function;
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


PROCEDURE (fct: Function) Priority* (): SHORTINT;
  BEGIN
    RETURN priFunction
  END Priority;

PROCEDURE (fct: Function) WriteLeft* (w: TextRider.Writer);
  BEGIN
    WriteLeft (w, fct. resultType, priFunction);
  END WriteLeft;

PROCEDURE (fct: Function) WriteRight* (w: TextRider.Writer);
  VAR
    i: LONGINT;
  BEGIN
    w. WriteChar("(");
    FOR i := 0 TO fct. parameters. Size()-1 DO
      IF (i # 0) THEN
        w. WriteString (", ")
      END;
      fct. parameters. array[i](Declaration). Write (w)
    END;
    w. WriteChar(")");
    WriteRight (w, fct. resultType, priFunction)
  END WriteRight;



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

PROCEDURE (b: Block) NewDeclaration* (name: String.String; typeQualifier: TypeQualifier; storageClass: StorageClass; type: Type): Declaration;
  VAR
    d: Declaration;
  BEGIN
    NEW (d);
    InitDeclaration (d, name, typeQualifier, storageClass, type);
    RETURN d
  END NewDeclaration;

PROCEDURE WriteTypeQualifier (w: TextRider.Writer; typeQualifier: TypeQualifier);
  BEGIN
    CASE typeQualifier OF
    | tqNone    :
    | tqConst   : w. WriteString ("const ")
    | tqVolatile: w. WriteString ("volatile ")
    END
  END WriteTypeQualifier;

PROCEDURE (d: Declaration) Write* (w: TextRider.Writer);
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



PROCEDURE (b: Block) AddDecl* (d: Declaration);
  BEGIN
    IF (d # NIL) THEN
      b. declarations. Append (d)
    END;
  END AddDecl;

PROCEDURE (b: Block) Write* (w: TextRider.Writer);
  PROCEDURE WriteIncludes;
    VAR
      m: Repository.Module;
      i: LONGINT;
      uri: URI.URI;
      path: Repository.URIBuffer;
    BEGIN
      FOR i := 0 TO b. includes. Size()-1 DO
        m := b. includes. array[i](Repository.Module);
        uri := m. GetURI (Repository.modHeaderFileC);
        IF b. relativeIncludePaths THEN
          uri := uri. MakeRelative (m. origin. baseURI)
        END;
        uri(FileURI.URI). GetPath (path);
        
        w. WriteString ('#include "');
        w. WriteString (path);
        w. WriteString ('"');
        w. WriteLn
      END
    END WriteIncludes;
  
  PROCEDURE WriteDeclarations;
    VAR
      d: Declaration;
      i: LONGINT;
    BEGIN
      FOR i := 0 TO b. declarations. Size()-1 DO
        d := b. declarations. array[i](Declaration);
        d. Write (w);
        w. WriteChar (";");
        w. WriteLn
      END
    END WriteDeclarations;
  
  BEGIN
    WriteIncludes;
    WriteDeclarations
  END Write;


PROCEDURE Init;
  PROCEDURE CreateBasicType (id: BasicTypeId; repr: ARRAY OF CHAR);
    BEGIN
      basicType[id] := NewBasicType (id, repr)
    END CreateBasicType;
  
  BEGIN
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
  END Init;

PROCEDURE Test;
  VAR
    b: Block;
    fct: Type;
    
  PROCEDURE Cmp (t: Type; expected: ARRAY OF CHAR);
    VAR
      ch: Memory.Channel;
      w: TextRider.Writer;
      r: TextRider.Reader;
      result: ARRAY 4*1024 OF CHAR;
      res: Msg.Msg;
      d: Declaration;
    BEGIN
      ch := Memory.Tmp("", {Memory.write, Memory.read}, res);
      w := TextRider.ConnectWriter (ch);
      d := b. NewDeclaration (String.New ("x"), tqNone, scAuto, t);
      d. Write (w);
      w. WriteLn;
      
      r := TextRider.ConnectReader (ch);
      ASSERT (r # NIL);
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
    Err.String ("Running OOC:WriteC.Test...");
    Err.Ln;
    b := NewBlock();
    
    Cmp(basicType[int32], "int x");
    Cmp(b. NewPointer (tqNone, basicType[int32]), "int *x");
    Cmp(b. NewArray (basicType[int32], 8), "int x[8]");
    Cmp(b. NewArray (b. NewPointer (tqNone, basicType[int32]), 8), "int *x[8]");
    Cmp(b. NewPointer (tqNone, b. NewArray (basicType[int32], 8)), "int (*x)[8]");
    Cmp(b. NewArray (b. NewArray (basicType[int32], 8), 4), "int x[4][8]");
    
    fct := b. NewFunction (basicType[int32]);
    Cmp (fct, "int x()");
    fct := b. NewFunction (b. NewPointer (tqNone, basicType[int32]));
    Cmp (fct, "int *x()");
    fct := b. NewFunction (b. NewArray (basicType[int32], 8));
    Cmp (fct, "int x()[8]");
    
    fct := b. NewPointer (tqNone, b. NewFunction (basicType[int32]));
    Cmp (fct, "int (*x)()");
    fct := b. NewPointer (tqNone, b. NewFunction (b. NewPointer (tqNone, basicType[int32])));
    Cmp (fct, "int *(*x)()");
    fct := b. NewPointer (tqNone, b. NewFunction (b. NewArray (basicType[int32], 8)));
    Cmp (fct, "int (*x)()[8]");
    
    fct := b. NewArray (b. NewFunction (basicType[int32]), 4);
    Cmp (fct, "int x[4]()");
    fct := b. NewArray (b. NewFunction (b. NewPointer (tqNone, basicType[int32])), 4);
    Cmp (fct, "int *x[4]()");
    fct := b. NewArray (b. NewFunction (b. NewArray (basicType[int32], 8)), 4);
    Cmp (fct, "int x[4]()[8]");
    
    
    Err.String ("no errors"); Err.Ln
  END Test;

BEGIN
  Init;
(*  Test;*)
END OOC:C:WriteDecl.
