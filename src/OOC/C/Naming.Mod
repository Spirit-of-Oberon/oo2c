MODULE OOC:C:Naming;

IMPORT
  IntStr, Strings, Object, ADT:Dictionary, ADT:ArrayList, 
  OOC:Config, Sym := OOC:SymbolTable, OOC:SymbolTable:Predef,
  TR := OOC:SymbolTable:TypeRules;

TYPE
  Buffer = ARRAY 2*1024 OF CHAR;
  QualTypeDescr* = POINTER TO QualTypeDescrDesc;
  QualTypeDescrDesc = RECORD
    (**Describes a type descriptor for a qualified type.  *)
    (Object.ObjectDesc)
    name-: STRING;
    (* Name of the variable that holds the type descriptor.  Initially
       @code{NIL}.  *)
    type-: Sym.Type;
    (**@otype{Sym.TypeClosure} or @otype{Sym.TypeVar}.  *)
  END;
  QualTypeData* = POINTER TO QualTypeDataDesc;
  QualTypeDataDesc = RECORD
    list-: ArrayList.ArrayList(QualTypeDescr);
    (* List of type descriptors referenced in the program code or by other
       descriptors.  The entries are sorted so that a descriptor at position
       @var{x} only references non-qualified type descriptors or type
       descriptors with positions smaller than @var{x}.  *)
  END;
  
CONST
  suffixPassPerRef* = "__ref";
  (**Suffix attached to parameter names if they are value parameters that
     are passed by reference to the callee.  The callee must create and
     populate its own copy of the parameter if necessary.  For Oberon-2
     source code, NO_COPY prevents creation of a local copy in the callee.  *)

VAR
  keywords: Dictionary.Dictionary;
  (* maps C/C++ keywords to a safer counterpart *)
  rwPrefix: STRING;
  (* prefix string used to mangle reserved names *)
  tdPrefix: STRING;
  (* prefix of the type descriptor namespace *)


PROCEDURE (qtd: QualTypeDescr) INIT*(id: LONGINT; type: Sym.Type);
  VAR
    str: ARRAY 16 OF CHAR;
  BEGIN
    ASSERT((type IS Sym.TypeClosure) OR (type IS Sym.TypeVar));
    IntStr.IntToStr(id, str);
    qtd.name := "_td__qtd"+Object.NewLatin1(str);
    qtd.type := type;
  END INIT;

PROCEDURE (qtdData: QualTypeData) INIT*();
  BEGIN
    qtdData.list := NEW(ArrayList.ArrayList(QualTypeDescr), 8);
  END INIT;

PROCEDURE NameOfDeclaration* (decl: Sym.Declaration): STRING;
  VAR
    relativeId: Sym.NameString;
    str: Buffer;
    i: LONGINT;
    m: Sym.Item;
    relativeName: BOOLEAN;
    name: STRING;
    string: STRING;
    obj: Object.Object;

  PROCEDURE IsReservedName (VAR str: ARRAY OF CHAR): BOOLEAN;
  (* The names "^[ilr]\d+$" are used by the SSA based C back-end for
     local variables.  *)
    VAR
      i: LONGINT;
    BEGIN
      IF (str[0] = "i") OR (str[0] = "w") OR (str[0] = "l") OR
         (str[0] = "f") OR (str[0] = "d") THEN
        i := 1;
        WHILE ("0" <= str[i]) & (str[i] <= "9") DO
          INC (i)
        END;
        RETURN (i > 1) & (str[i] = 0X);
      ELSE
        RETURN FALSE;
      END;
    END IsReservedName;

  PROCEDURE IsInterfaceModule (module: Sym.Module): BOOLEAN;
    BEGIN
      RETURN (module. class = Sym.mcInterface);
    END IsInterfaceModule;
  
  BEGIN
    relativeName := FALSE;
    
    IF (decl IS Sym.VarDecl) &
       (decl(Sym.VarDecl). isParameter OR
        ~(decl. parent IS Sym.Module) OR
        IsInterfaceModule (decl. Module())) THEN
      (* use relative names for parameters and for variables of procedures,
         and do not mangle variable names in INTERFACE modules *)
      relativeName := TRUE;
      
    ELSIF (decl IS Sym.FieldDecl) THEN
      (* use relative names for record fields, as long as there are no
         collisions between a local field and one inherited from a
         base type *)
      relativeName := ~decl(Sym.FieldDecl).shadowsPrivateBase;

    ELSIF (decl IS Sym.ProcDecl) & (decl(Sym.ProcDecl). linkName # NIL) THEN
      (* the declaration defines its own linkage name: immediately, return it
         because collisions with reserved names don't matter here *)
      RETURN decl(Sym.ProcDecl). linkName;
      
    ELSIF (decl IS Sym.ProcDecl) & IsInterfaceModule (decl. Module()) THEN
      (* names of procedures declared in interface modules are not mangled
         by default *)
      relativeName := TRUE;
    END;
    
    IF relativeName THEN
      COPY (decl. name. str^, str)
    ELSE
      (* replace ":" in module name with "_" *)
      m := decl;
      WHILE ~(m IS Sym.Module) DO
        m := m. parent
      END;
      COPY (m(Sym.Module). name. str^, str);
      i := 0;
      WHILE (str[i] # 0X) DO
        IF (str[i] = ":") THEN str[i] := "_" END;
        INC (i)
      END;

      (* append "__" to separate module name from relative id *)
      Strings.Append ("__", str);

      (* append relative id, replacing "." with "_" *)
      relativeId := decl. GetId();
      Strings.Append (relativeId^, str);
      INC (i, 2);
      WHILE (str[i] # 0X) DO
        IF (str[i] = ".") THEN str[i] := "_" END;
        INC (i)
      END
    END;

    name := Object.NewLatin1(str);
    IF keywords. HasKey (name) THEN
      obj := keywords. Get (name);
      RETURN obj(STRING);
    ELSIF IsReservedName (str) THEN
      string := rwPrefix. Concat (name);
      RETURN string;
    ELSE
      RETURN name;
    END;
  END NameOfDeclaration;

PROCEDURE NameOfModuleInit* (m: Sym.Module; initFunction: BOOLEAN;
                             rtWrapper: BOOLEAN): STRING;
  VAR
    str: Buffer;
    i: LONGINT;
  BEGIN
    COPY (m. name. str^, str);
    i := 0;
    WHILE (str[i] # 0X) DO
      IF (str[i] = ":") THEN str[i] := "_" END;
      INC (i)
    END;
    Strings.Insert("OOC_", 0, str);
    IF initFunction THEN
      IF rtWrapper THEN
        Strings.Append ("_open", str);
      ELSE      
        Strings.Append ("_init", str);
      END;
    ELSE
      IF rtWrapper THEN
        Strings.Append ("_close", str);
      ELSE      
        Strings.Append ("_destroy", str);
      END;
    END;
    RETURN Object.NewLatin1(str)
  END NameOfModuleInit;

PROCEDURE NameOfLengthParam* (param: Sym.VarDecl; dim: LONGINT): STRING;
  VAR
    str: ARRAY 16 OF CHAR;
  BEGIN
    IntStr.IntToStr (dim, str);
    RETURN NameOfDeclaration(param)+"_"+Object.NewLatin1(str)+"d";
  END NameOfLengthParam;

PROCEDURE NameOfTypeTagParam* (param: Sym.VarDecl): STRING;
  BEGIN
    RETURN NameOfDeclaration(param)+"__tag";
  END NameOfTypeTagParam;

PROCEDURE NameOfType* (type: Sym.Type): STRING;
(**@precond
   @samp{type. namingDecl # NIL}
   @end precond *)
  BEGIN
    WITH type: Sym.TypeVar DO
      RETURN NameOfType(type.bound);
    ELSE
      WHILE (type.namingDecl = NIL) & (type IS Sym.QualType) DO
        (* skip over implicit type argument list *)
        type := type(Sym.QualType).baseType;
      END;
      ASSERT (type. namingDecl # NIL);
      RETURN NameOfDeclaration (type. namingDecl);
    END;
  END NameOfType;

PROCEDURE NameOfTypeDescriptor* (type: Sym.Type;
                                 qtdData: QualTypeData): STRING;
(**Side effect: If @oparam{type} requires a special type descriptor that does
   not exist by default, then an entry for it is added to @oparam{qtdData}.

   @precond
   @samp{type. namingDecl # NIL}
   @end precond  *)
  VAR
    string: STRING;
    str, str2: ARRAY 32 OF CHAR;
    base: Sym.Type;
    dummy: STRING;
    i: LONGINT;

  PROCEDURE AddToQtd(type: Sym.Type): STRING;
    VAR
      i: LONGINT;
      qtd: QualTypeDescr;
    BEGIN
      FOR i := 0 TO qtdData.list.size-1 DO
        IF TR.SameType(type, qtdData.list.array[i].type) THEN
          RETURN qtdData.list.array[i].name;
        END;
      END;
      
      qtd := NEW(QualTypeDescr, qtdData.list.size, type);
      qtdData.list.Append(qtd);
      RETURN qtd.name;
    END AddToQtd;
  
  BEGIN
    WITH type: Sym.QualType DO
      RETURN NameOfTypeDescriptor(Sym.Expand(type), qtdData);

    | type: Sym.TypeVar DO
      RETURN AddToQtd(type);
      
    | type: Sym.TypeClosure DO
      base := type.baseType;
      
      (* only create qualified type descriptors for records and record
         pointers; all other types only have non-qualified descriptors *)
      WITH base: Sym.Pointer DO
        IF ~TR.IsRecord(base.baseType) THEN
          RETURN NameOfTypeDescriptor(base, qtdData);
        END;
      | base: Sym.Record DO
        (* fall through *)
      ELSE
        RETURN NameOfTypeDescriptor(base, qtdData);
      END;
      
      WITH base: Sym.Pointer DO
        dummy := NameOfTypeDescriptor(TR.PointerBaseType(type), qtdData);
      | base: Sym.Record DO
        IF (base.baseType # NIL) THEN
          (* make sure the type descriptor of the base type exists *)
          dummy := NameOfTypeDescriptor(TR.RecordBaseType(type), qtdData);
        END;
      ELSE
        (* ignore *)
      END;
      FOR i := 0 TO LEN(type.arguments^)-1 DO
        (* make sure the type descriptor of the type argument exists *)
        dummy := NameOfTypeDescriptor(type.arguments[i].type, qtdData);
      END;
      
      RETURN AddToQtd(type);

    | type: Sym.FormalPars DO
      RETURN Config.runtimeModule+"__procedure";

    | type: Sym.PredefType DO
      CASE type. id OF
      | Predef.boolean : str := "boolean"
      | Predef.char    : str := "char"
      | Predef.longchar: str := "longchar"
      | Predef.ucs4char: str := "ucs4char"
      | Predef.shortint: str := "shortint"
      | Predef.integer : str := "integer"
      | Predef.longint : str := "longint"
      | Predef.real    : str := "real"
      | Predef.longreal: str := "longreal"
      | Predef.set     : str := "set32"
      | Predef.byte    : str := "byte"
      | Predef.ptr     : str := "ptr"
      END;
      str2 := Config.runtimeModule;
      Strings.Append ("__", str2);
      Strings.Append (str, str2);
      RETURN Object.NewLatin1(str2);
    ELSE
      IF (type. namingDecl = NIL) THEN
        string := tdPrefix. Concat (NameOfDeclaration (type. Module()));
        IntStr.IntToStr (type. position. pos, str);
        string := string. Concat (Object.NewLatin1(str));
        RETURN string;
      ELSE
        string := tdPrefix. Concat (NameOfType (type));
        RETURN string;
      END;
    END;
  END NameOfTypeDescriptor;

PROCEDURE NameOfTypeBoundIndex* (proc: Sym.ProcDecl): STRING;
(**Return the name of the C #define that holds the index of this
   type-bound procedure.  *)
  BEGIN
    RETURN "_TBN_"+NameOfDeclaration (proc);
  END NameOfTypeBoundIndex;

PROCEDURE NameOfTypeBoundSignature* (proc: Sym.ProcDecl): STRING;
(**Return the name of the C typedef that defines the signature of this
   type-bound procedure.  *)
  BEGIN
    RETURN "_TBP_"+NameOfDeclaration (proc);
  END NameOfTypeBoundSignature;

PROCEDURE Init ();
  PROCEDURE RW (str: ARRAY OF CHAR);
    VAR
      name: STRING;
    BEGIN
      name := Object.NewLatin1(str);
      keywords. Set (name, rwPrefix. Concat (name));
    END RW;
  
  BEGIN
    keywords := Dictionary.New();
    rwPrefix := "_";
    tdPrefix := "_td_";
    
    (* reserved words of ANSI-C *)
    RW ("auto"); RW ("break"); RW ("case"); RW ("char"); RW ("const"); 
    RW ("continue"); RW ("default"); RW ("do"); RW ("double"); RW ("else"); 
    RW ("enum"); RW ("extern"); RW ("float"); RW ("for"); RW ("goto"); 
    RW ("if"); RW ("int"); RW ("long"); RW ("register"); RW ("return"); 
    RW ("short"); RW ("signed"); RW ("sizeof"); RW ("static"); RW ("struct"); 
    RW ("switch"); RW ("typedef"); RW ("union"); RW ("unsigned"); RW ("void"); 
    RW ("volatile"); RW ("while"); RW ("fortran"); RW ("asm"); 
    (* C++ reserved words *)
    RW ("bool"); RW ("catch"); RW ("class"); RW ("delete"); RW ("false"); 
    RW ("friend"); RW ("inline"); RW ("new"); RW ("operator"); RW ("private"); 
    RW ("protected"); RW ("public"); RW ("template"); RW ("true"); RW ("try");
    RW ("this"); RW ("virtual"); RW ("throw");
    (* standard C entities used by the compiler *)
    RW ("NULL")
  END Init;

BEGIN
  Init
END OOC:C:Naming.
