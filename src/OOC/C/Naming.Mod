MODULE OOC:C:Naming;

IMPORT
  IntStr, Strings, ADT:Object, ADT:String, ADT:Dictionary,
  OOC:Config, Sym := OOC:SymbolTable, OOC:SymbolTable:Predef;

TYPE
  Buffer = ARRAY 2*1024 OF CHAR;

CONST
  suffixPassPerRef* = "__ref";
  (**Suffix attached to parameter names if they are value parameters that
     are passed by reference to the callee.  The callee must create and
     populate its own copy of the parameter if necessary.  For Oberon-2
     source code, NO_COPY prevents creation of a local copy in the callee.  *)

VAR
  keywords: Dictionary.Dictionary;
  (* maps C/C++ keywords to a safer counterpart *)
  rwPrefix: String.String;
  (* prefix string used to mangle reserved names *)
  tdPrefix: String.String;
  (* prefix of the type descriptor namespace *)

PROCEDURE NameOfDeclaration* (decl: Sym.Declaration): String.String;
  VAR
    relativeId: Sym.NameString;
    str: Buffer;
    i: LONGINT;
    m: Sym.Item;
    relativeName: BOOLEAN;
    name: String.String;
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
       (decl(Sym.VarDecl). isParameter OR ~(decl. parent IS Sym.Module)) THEN
      (* use relative names for parameters and for variables of procedures *)
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

    name := String.New (str);
    IF keywords. HasKey (name) THEN
      obj := keywords. Get (name);
      RETURN obj(String.String);
    ELSIF IsReservedName (str) THEN
      RETURN rwPrefix. Concat (name);
    ELSE
      RETURN name;
    END;
  END NameOfDeclaration;

PROCEDURE NameOfModuleInit* (m: Sym.Module; rtWrapper: BOOLEAN): String.String;
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
    IF rtWrapper THEN
      Strings.Append ("_init0", str);
    ELSE      
      Strings.Append ("_init", str);
    END;
    RETURN String.New (str)
  END NameOfModuleInit;

PROCEDURE NameOfLengthParam* (param: Sym.VarDecl; dim: LONGINT): String.String;
  VAR
    str: Buffer;
    name: String.String;
  BEGIN
    name := NameOfDeclaration (param);
    IntStr.IntToStr (dim, str);
    Strings.Insert ("_", 0, str);
    Strings.Append ("d", str);
    Strings.Insert (name. array^, 0, str);
    RETURN String.New (str)
  END NameOfLengthParam;

PROCEDURE NameOfTypeTagParam* (param: Sym.VarDecl): String.String;
  VAR
    str: Buffer;
    name: String.String;
  BEGIN
    name := NameOfDeclaration (param);
    COPY (name. array^, str);
    Strings.Append ("__tag", str);
    RETURN String.New (str)
  END NameOfTypeTagParam;

PROCEDURE NameOfType* (type: Sym.Type): String.String;
(**@precond
   @samp{type. namingDecl # NIL}
   @end precond *)
  BEGIN
    ASSERT (type. namingDecl # NIL);
    RETURN NameOfDeclaration (type. namingDecl);
  END NameOfType;

PROCEDURE NameOfTypeDescriptor* (type: Sym.Type): String.String;
(**@precond
   @samp{type. namingDecl # NIL}
   @end precond *)
  VAR
    name: String.String;
    str, str2: ARRAY 32 OF CHAR;
  BEGIN
    WITH type: Sym.PredefType DO
      CASE type. id OF
      | Predef.boolean : str := "boolean"
      | Predef.char    : str := "char"
      | Predef.longchar: str := "longchar"
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
      RETURN String.New (str2);
    ELSE
      IF (type. namingDecl = NIL) THEN
        name := tdPrefix. Concat (NameOfDeclaration (type. Module()));
        IntStr.IntToStr (type. position. pos, str);
        RETURN name. Concat (String.New (str));
      ELSE
        RETURN tdPrefix. Concat (NameOfType (type));
      END;
    END;
  END NameOfTypeDescriptor;

PROCEDURE NameOfTypeBoundIndex* (proc: Sym.ProcDecl): String.String;
(**Return the name of the C #define that holds the index of this
   type-bound procedure.  *)
  VAR
    name: String.String;
  BEGIN
    name := String.New ("_TBN_");
    RETURN name. Concat (NameOfDeclaration (proc));
  END NameOfTypeBoundIndex;

PROCEDURE NameOfTypeBoundSignature* (proc: Sym.ProcDecl): String.String;
(**Return the name of the C typedef that defines the signature of this
   type-bound procedure.  *)
  VAR
    name: String.String;
  BEGIN
    name := String.New ("_TBP_");
    RETURN name. Concat (NameOfDeclaration (proc));
  END NameOfTypeBoundSignature;

PROCEDURE Init ();
  PROCEDURE RW (str: ARRAY OF CHAR);
    VAR
      name: String.String;
    BEGIN
      name := String.New (str);
      keywords. Set (name, rwPrefix. Concat (name));
    END RW;
  
  BEGIN
    keywords := Dictionary.New();
    rwPrefix := String.New ("_");
    tdPrefix := String.New ("_td_");
    
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
