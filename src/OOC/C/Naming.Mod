MODULE OOC:C:Naming;

IMPORT
  IntStr, Strings, ADT:String, OOC:Repository, Sym := OOC:SymbolTable;

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

END OOC:C:Naming.
