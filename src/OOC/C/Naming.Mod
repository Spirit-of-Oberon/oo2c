MODULE OOC:C:Naming;

IMPORT
  IntStr, Strings, ADT:String, OOC:Repository, Sym := OOC:SymbolTable,
  OOC:SymbolTable:Predef, OOC:Auxiliary:Config;

TYPE
  Buffer = ARRAY 2*1024 OF CHAR;

CONST
  suffixPassPerRef* = "__ref";
  (**Suffix attached to parameter names if they are value parameters that
     are passed by reference to the callee.  The callee must create and
     populate its own copy of the parameter.  *)

  
PROCEDURE NameOfDeclaration* (decl: Sym.Declaration): String.String;
  VAR
    relativeId: Sym.NameString;
    str: Buffer;
    i: LONGINT;
    m: Sym.Item;
    relativeName: BOOLEAN;
  BEGIN
    relativeName := FALSE;
    
    IF (decl IS Sym.VarDecl) & (decl(Sym.VarDecl). isParameter) THEN
      (* use relative names for parameters for procedure types and for
         global procedures *)
      relativeName :=
        ~(decl. parent. parent IS Sym.ProcDecl) OR
        (decl. parent. parent. parent IS Sym.Module)

    ELSIF (decl IS Sym.FieldDecl) THEN
      (* use relative names for record fields, as long as there are no
         collisions between a local field and one inherited from a
         base type *)
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
    
    RETURN String.New (str)
  END NameOfDeclaration;

PROCEDURE NameOfModuleInit* (m: Repository.Module): String.String;
  VAR
    str: Buffer;
  BEGIN
    COPY (m. name^, str);
    Strings.Append ("_init", str);
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
      | Predef.shortint: str := "shortint"
      | Predef.integer : str := "integer"
      | Predef.longint : str := "longint"
      END;
      str2 := Config.runtimeModule;
      Strings.Append ("__", str2);
      Strings.Append (str, str2);
      RETURN String.New (str2);
    ELSE
      name := String.New ("_td_");
      IF (type. namingDecl = NIL) THEN
        IntStr.IntToStr (type. position. pos, str);
        RETURN name. Concat (String.New (str));
      ELSE
        RETURN name. Concat (NameOfType (type));
      END;
    END;
  END NameOfTypeDescriptor;

END OOC:C:Naming.
