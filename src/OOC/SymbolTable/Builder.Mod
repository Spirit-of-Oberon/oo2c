(* 	$Id: Builder.Mod,v 1.57 2004/01/12 05:42:25 sgreenhill Exp $	 *)
MODULE OOC:SymbolTable:Builder [OOC_EXTENSIONS];
(*  Defines a builder class with factory methods for symbol table entries.
    Copyright (C) 2000-2003  Michael van Acken

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
  Out, Strings, Object, Object:Boxed, ADT:Dictionary, IO,
  OOC:Doc, OOC:AST, Sym := OOC:SymbolTable;


TYPE
  Builder* = POINTER TO BuilderDesc;
  BuilderDesc* = RECORD
    (**The builder defines a factory method for every item that can appear
       in a module's symbol table.  The arguments of the factory methods
       are passed directly to the initialization procedures of the
       corresponding classes from @omodule{Sym}, which in turn
       correspond directly to the record fields defined for
       the specializations of @otype{Sym.Item}.  *)
    class: Sym.ModuleClass;
    (**Toggle semantics of declarations.  This field identifies the class of
       module being contructed.  For example, @oconst{Sym.mcInterface} means
       that the symbol table of an @samp{INTERFACE} module is being build, and
       that the semantics of some declaration and definitions need to be
       adjusted for this.  *)
  END;

TYPE
  Writer = POINTER TO WriterDesc;
  WriterDesc = RECORD
    (**This special writer maps all @otype{Sym.Name} instances with the same
       value onto a single object in the symbol file.  *)
    (Sym.WriterDesc)
    names: Dictionary.Dictionary(STRING, Sym.Name);
  END;
  
TYPE
  Reader = POINTER TO ReaderDesc;
  ReaderDesc = RECORD
    (Sym.ReaderDesc)
  END;
  
TYPE
  AutoImport* = POINTER TO AutoImportDesc;
  Name = POINTER TO ARRAY OF CHAR;
  AutoImportDesc = RECORD
    module-: Name;
    (**Full name of the module that is to be imported into every module
       not found in the exclude list.  *)
    exclude-: POINTER TO ARRAY OF Name;
    (**Lists the names of all modules for which @ofield{module} is not
       to be imported automatically.  This list is never empty, because it
       must include the value of @ofield{module}.  *)
  END;

CONST
  prefixAutoImport* = "-";
  stringModule* = "Object";
  stringModuleC* = "Object";

CONST
  noAutoImport* = 0;
  (**Don't do any automatical import in the symbol table or in the repository's
     @oproc{*OOC:Repository:GetImports.GetImports}.  *)
  autoImportRT0* = 1;
  (**Add @samp{RT0} to every import list, but no other modules.  *)
  fullAutoImport* = 2;
  (**Add all listed modules to the import list.  *)
  
VAR
  autoImport-: POINTER TO ARRAY OF AutoImport;
  doAutoImport*: SHORTINT;
  (**Enables or disables automatic adding of modules to the import list.  *)

CONST
  magicNumberSize* = 4;

VAR
  magicNumber*: ARRAY magicNumberSize+1 OF CHAR;  (* must not contain 0X *)
  
PROCEDURE Init* (b: Builder);
  BEGIN
    b. class := Sym.mcStandard;
  END Init;

PROCEDURE New* (): Builder;
  VAR
    b: Builder;
  BEGIN
    NEW (b);
    Init (b);
    RETURN b
  END New;

PROCEDURE (b: Builder) SetClass* (class: Sym.ModuleClass);
  BEGIN
    b. class := class;
  END SetClass;


PROCEDURE (b: Builder) NewImport* (parent: Sym.Item; name: Sym.Name;
                                   visibleFrom: Sym.ModulePos;
                                   docString: Doc.Document;
                                   moduleName: Sym.Name): Sym.Import;
  VAR
    import: Sym.Import;
  BEGIN
    NEW (import);
    Sym.InitImport (import, parent, name, visibleFrom, docString, moduleName);
    RETURN import
  END NewImport;

PROCEDURE (b: Builder) NewConstDecl* (parent: Sym.Item; name: Sym.Name;
                                      visibleFrom: Sym.ModulePos;
                                      exportMark: Sym.ExportMark;
                                      docString: Doc.Document;
                                      value: Boxed.Object;
                                      type: Sym.PredefType;
                                      constExpr: AST.Node): Sym.ConstDecl;
(**Note: If the value and type of the constant are not known yet, then
   @oparam{value} and @oparam{type} are @code{NIL}.  When creating the symbol
   table from source code, then this information is not available initially and
   only set later when translating constant expressions during the creation of
   the IR data structure.  *)
  VAR
    const: Sym.ConstDecl;
  BEGIN
    NEW (const);
    Sym.InitConstDecl (const, parent, name, visibleFrom, exportMark,
                       docString, value, type, constExpr);
    RETURN const
  END NewConstDecl;

PROCEDURE (b: Builder) NewTypeDecl* (parent: Sym.Item; name: Sym.Name;
                                     visibleFrom: Sym.ModulePos;
                                     exportMark: Sym.ExportMark;
                                     docString: Doc.Document;
                                     type: Sym.Type;
                                     isTypeParameter: BOOLEAN): Sym.TypeDecl;
  VAR
    t: Sym.TypeDecl;
    
  PROCEDURE NewTypeVar(bound: Sym.Type; parent: Sym.Item): Sym.TypeVar;
    VAR
      tv: Sym.TypeVar;
    BEGIN
      NEW(tv);
      Sym.InitTypeVar(tv, parent, type.position, bound);
      tv.SetNamingDecl(t);
      RETURN tv;
    END NewTypeVar;
  
  BEGIN
    NEW (t);
    IF isTypeParameter THEN
      type := NewTypeVar(type, parent);
    END;
    Sym.InitTypeDecl (t, parent, name, visibleFrom, exportMark,
                      docString, type, isTypeParameter);
    IF (type # NIL) & (type.namingDecl = NIL) THEN
      type. SetNamingDecl (t);
    END;
    RETURN t
  END NewTypeDecl;

PROCEDURE (b: Builder) NewRedirect* (parent: Sym.Item; name: Sym.Name;
                                     module, ident: Sym.Name): Sym.Redirect;
  VAR
    redir: Sym.Redirect;
  BEGIN
    NEW (redir);
    Sym.InitRedirect (redir, parent, name, module, ident);
    RETURN redir
  END NewRedirect;

PROCEDURE (b: Builder) NewVarDecl* (parent: Sym.Item; name: Sym.Name;
                                 visibleFrom: Sym.ModulePos;
                                 exportMark: Sym.ExportMark;
                                 docString: Doc.Document;
                                 isParameter, isReceiver, isVarParam: BOOLEAN;
                                 type: Sym.Type): Sym.VarDecl;
  VAR
    var: Sym.VarDecl;
  BEGIN
    NEW (var);
    Sym.InitVarDecl (var, parent, name, visibleFrom, exportMark, docString,
                      isParameter, isReceiver, isVarParam, type);

    IF isParameter & (b. class = Sym.mcInterface) THEN
      var.supplementArgs := FALSE;
    END;
    RETURN var
  END NewVarDecl;

PROCEDURE (b: Builder) NewFieldDecl* (parent: Sym.Item; name: Sym.Name;
                                      visibleFrom: Sym.ModulePos;
                                      exportMark: Sym.ExportMark;
                                      docString: Doc.Document;
                                      type: Sym.Type): Sym.FieldDecl;
  VAR
    field: Sym.FieldDecl;
  BEGIN
    NEW (field);
    Sym.InitFieldDecl (field, parent, name, visibleFrom, exportMark, docString, type);
    RETURN field
  END NewFieldDecl;

PROCEDURE (b: Builder) NewPredefProc* (parent: Sym.Item; name: Sym.Name;
                                       id: Sym.PredefId;
                                       minArgs, maxArgs: INTEGER): Sym.PredefProc;
  VAR
    pproc: Sym.PredefProc;
  BEGIN
    NEW (pproc);
    Sym.InitPredefProc (pproc, parent, name, id, minArgs, maxArgs);
    RETURN pproc
  END NewPredefProc;

PROCEDURE (b: Builder) NewProcDecl* (parent: Sym.Item; name: Sym.Name;
                                     visibleFrom: Sym.ModulePos;
                                     exportMark: Sym.ExportMark;
                                     docString: Doc.Document;
                                     procClass: SHORTINT;
                                     isForwardDecl: BOOLEAN;
                                     procAST: AST.Node): Sym.ProcDecl;
  VAR
    procDecl: Sym.ProcDecl;
  BEGIN
    NEW (procDecl);
    Sym.InitProcDecl (procDecl, parent, name, visibleFrom, exportMark, 
                       docString, procClass, isForwardDecl, procAST);
    RETURN procDecl
  END NewProcDecl;



PROCEDURE EvalContext(b: Builder; type: Sym.Type);
  BEGIN
    IF (b.class = Sym.mcInterface) THEN
      type.hasDescriptor := FALSE;
      WITH type: Sym.Record DO
        type.isExtensible := FALSE;
      | type: Sym.Array DO
        type.hasLengthInfo := ~type.isOpenArray;
      | type: Sym.Pointer DO
        type.isStatic := TRUE;
      ELSE
        (* nothing *)
      END;
    END;
  END EvalContext;

PROCEDURE (b: Builder) NewPredefType* (parent: Sym.Item; id: Sym.PredefId): Sym.PredefType;
  VAR
    ptype: Sym.PredefType;
  BEGIN
    NEW (ptype);
    Sym.InitPredefType (ptype, parent, id);
    EvalContext(b, ptype);
    RETURN ptype
  END NewPredefType;

PROCEDURE (b: Builder) NewTypeName* (parent: Sym.Item;
                                     position: Sym.Position;
                                     module, ident: Sym.Name): Sym.TypeName;
  VAR
    tname: Sym.TypeName;
  BEGIN
    NEW (tname);
    Sym.InitTypeName (tname, parent, position, module, ident);
    EvalContext(b, tname);
    RETURN tname
  END NewTypeName;

PROCEDURE (b: Builder) NewRecord* (parent: Sym.Item;
                                   position: Sym.Position;
                                   baseType: Sym.Type): Sym.Record;
  VAR
    record: Sym.Record;
  BEGIN
    NEW (record);
    Sym.InitRecord (record, parent, position, baseType);
    EvalContext(b, record);
    RETURN record
  END NewRecord;

PROCEDURE (b: Builder) NewArray* (parent: Sym.Item; 
                                  position: Sym.Position;
                                  isOpenArray: BOOLEAN;
                                  lengthExpr: AST.Node;
                                  elementType: Sym.Type): Sym.Array;
  VAR
    array: Sym.Array;
  BEGIN
    NEW (array);
    Sym.InitArray (array, parent, position, isOpenArray,
                   elementType, lengthExpr);
    EvalContext(b, array);
    RETURN array
  END NewArray;

PROCEDURE (b: Builder) NewPointer* (parent: Sym.Item;
                                    position: Sym.Position;
                                    baseType: Sym.Type): Sym.Pointer;
  VAR
    ptr: Sym.Pointer;
  BEGIN
    NEW (ptr);
    Sym.InitPointer (ptr, parent, position, baseType);
    EvalContext(b, ptr);
    RETURN ptr
  END NewPointer;

PROCEDURE (b: Builder) NewTypePars* (parent: Sym.Item): Sym.TypePars;
  VAR
    typePars: Sym.TypePars;
  BEGIN
    NEW (typePars);
    Sym.InitTypePars(typePars, parent);
    RETURN typePars
  END NewTypePars;

PROCEDURE (b: Builder) NewQualType* (parent: Sym.Item;
                                     position: Sym.Position;
                                     baseType: Sym.Type;
                                     arguments: Sym.TypeRefArray): Sym.QualType;
  VAR
    qualType: Sym.QualType;
  BEGIN
    NEW (qualType);
    Sym.InitQualType(qualType, parent, position, baseType, arguments);
    EvalContext(b, qualType);
    RETURN qualType
  END NewQualType;

PROCEDURE (b: Builder) NewExceptionName*(parent: Sym.Item;
                                         type: Sym.Type): Sym.ExceptionName;
  VAR
    eName: Sym.ExceptionName;
  BEGIN
    NEW(eName);
    Sym.InitExceptionName(eName, parent, type);
    RETURN eName;
  END NewExceptionName;

PROCEDURE (b: Builder) NewFormalPars* (parent: Sym.Item;
                                       position: Sym.Position): Sym.FormalPars;
  VAR
    fpars: Sym.FormalPars;
  BEGIN
    NEW (fpars);
    Sym.InitFormalPars (fpars, parent, position);
    EvalContext(b, fpars);
    RETURN fpars
  END NewFormalPars;

PROCEDURE (b: Builder) NewModule* (name: Sym.Name; docString: Doc.Document;
                                   class: Sym.ModuleClass;
                                   callConv: Sym.CallConv;
                                   moduleAST: AST.Node): Sym.Module;
  VAR
    mod: Sym.Module;
    bodyDecl: Sym.ProcDecl;
    bodyName: Sym.Name;
    str: Sym.NameString;
  BEGIN
    (* create an empty procedure declaration with no parameters and no
       result; this declaration is later used as a wrapper for the
       module body's statement sequence *)
    NEW (bodyName);
    NEW (str, 32);
    COPY (Sym.declModuleBody, str^);
    Sym.InitName (bodyName, str, -1, -1, -1);
    bodyDecl := b. NewProcDecl (NIL, bodyName, 0, Sym.nameNotExported,
                                NIL, Sym.standardProc, FALSE, NIL);
    bodyDecl. formalPars := b. NewFormalPars(bodyDecl, name);
    NEW (bodyDecl. formalPars. params, 0);
    NEW (bodyDecl. formalPars. raises, 0);
    
    NEW (mod);
    Sym.InitModule (mod, name, docString, class, callConv, moduleAST,
                    bodyDecl);
    RETURN mod
  END NewModule;


PROCEDURE (b: Builder) Finalize* (module: Sym.Module);
  VAR
    getPointerDecl: Dictionary.Dictionary(STRING, Sym.TypeDecl);
    hasTypeBoundProc: Dictionary.Dictionary(STRING, Object.Object);
    
  PROCEDURE CollectFormalPars (item: Sym.Item);
  (* Sets the field @ofield{Sym.FormalPars.params} for all formal parameter
     definitions under @oparam{item}.  Strictly speaking, this is not necessary
     for the compiler proper because @omodule{*OOC:SymbolTable:CreateNamespace}
     is already doing this.  For the sake of tools that do not run
     CreateNamespace, we repeat the process here.  *)
    VAR
      ptr: Sym.Item;
      c: LONGINT;
    BEGIN
      IF (item # NIL) THEN
        WITH item: Sym.FormalPars DO
          IF (item.params = NIL) THEN
            c := 0;
            ptr := item. nestedItems;
            WHILE (ptr # NIL) DO
              IF (ptr IS Sym.VarDecl) & 
                 ptr(Sym.VarDecl). isParameter &
                 ~ptr(Sym.VarDecl). isReceiver THEN
                INC (c)
              END;
              ptr := ptr. nextNested
            END;
            
            NEW (item. params, c);
            c := 0;
            ptr := item. nestedItems;
            WHILE (ptr # NIL) DO
              IF (ptr IS Sym.VarDecl) &
                 ptr(Sym.VarDecl). isParameter &
                 ~ptr(Sym.VarDecl). isReceiver THEN
                item. params[c] := ptr(Sym.VarDecl);
                INC (c)
              END;
              ptr := ptr. nextNested
            END;
          END;
        ELSE
        END;
        
        ptr := item. nestedItems;
        WHILE (ptr # NIL) DO
          CollectFormalPars (ptr);
          ptr := ptr. nextNested
        END
      END
    END CollectFormalPars;

  PROCEDURE PreprocessSetClassName(module: Sym.Module);
    VAR
      ptr: Sym.Item;
      name: Object.String8;

    PROCEDURE UnqualifiedName(type: Sym.Type): BOOLEAN;
      BEGIN
        WITH type: Sym.TypeName DO
          RETURN (type.module = NIL);
        ELSE
          RETURN FALSE;
        END
      END UnqualifiedName;
    
    BEGIN
      ptr := module.nestedItems;
      WHILE (ptr # NIL) DO
        WITH ptr: Sym.TypeDecl DO
          IF (ptr.type IS Sym.Pointer) &
             UnqualifiedName(ptr.type(Sym.Pointer).srcCodeBaseType) THEN
            name := Object.NewLatin1(ptr.type(Sym.Pointer).srcCodeBaseType(Sym.TypeName).ident.str^);
            IF getPointerDecl.HasKey(name) THEN
              (* multiple pointers to one record or array type *)
              getPointerDecl.Set(name, NIL);
            ELSE
              getPointerDecl.Set(name, ptr);
            END;
          END;

        | ptr: Sym.ProcDecl DO
          IF ptr.IsTypeBound() THEN
            name := Object.NewLatin1(ptr.formalPars.receiver.srcCodeType(Sym.TypeName).ident.str^);
            hasTypeBoundProc.Set(name, NIL)
          END;
        ELSE
        END;
        ptr := ptr.nextNested;
      END;
    END PreprocessSetClassName;
  
  PROCEDURE SetClassName (item: Sym.Item);
    VAR
      ptr: Sym.Item;
      pointerDecl: Sym.TypeDecl;
      pointerName: Sym.Name;
      record: Sym.Record;
      found: BOOLEAN;
      pos: INTEGER;
    
    PROCEDURE SameType (decl: Sym.Name; typeName: Sym.Type): BOOLEAN;
      BEGIN
        WITH typeName: Sym.TypeName DO
          RETURN (typeName. module = NIL) &
                 (typeName. ident. str^ = decl. str^)
        ELSE
          RETURN FALSE
        END
      END SameType;
    
    PROCEDURE GetPointerDecl (scope: Sym.Item; typeName: Sym.Name): Sym.TypeDecl;
      VAR
        ptr: Sym.Item;
        pointerDecl: Sym.TypeDecl;
        name: Object.String8;
      BEGIN
        IF (scope IS Sym.Module) THEN
          name := Object.NewLatin1(typeName.str^);
          IF getPointerDecl.HasKey(name) THEN
            RETURN getPointerDecl.Get(name);
          ELSE
            RETURN NIL;
          END;
        ELSE  (* not in module scope: fallback to old search *)
          pointerDecl := NIL;
          ptr := scope.nestedItems;
          WHILE (ptr # NIL) DO
            WITH ptr: Sym.TypeDecl DO
              IF (ptr.type IS Sym.Pointer) &
                 SameType(typeName, ptr.type(Sym.Pointer).srcCodeBaseType) THEN
                IF (pointerDecl = NIL) THEN
                  pointerDecl := ptr;
                ELSE
                  RETURN NIL;
                END;
              END;
            ELSE
            END;
            ptr := ptr.nextNested;
          END;
          RETURN pointerDecl;
        END;
      END GetPointerDecl;
    
    PROCEDURE HasTypeBoundProcedures (scope: Sym.Item;
                                      record, pointer: Sym.Name): BOOLEAN;
      VAR
        ptr: Sym.Item;
        name: Object.String8;
      BEGIN
        IF (scope IS Sym.Module) THEN
          name := Object.NewLatin1(record.str^);
          IF hasTypeBoundProc.HasKey(name) THEN
            RETURN TRUE;
          ELSIF (pointer # NIL) THEN
            name := Object.NewLatin1(pointer.str^);
            IF hasTypeBoundProc.HasKey(name) THEN
              RETURN TRUE;
            END;
          END;
          RETURN FALSE;
        ELSE  (* not in module scope: fallback to old search *)
          ptr := scope. nestedItems;
          WHILE (ptr # NIL) DO
            WITH ptr: Sym.ProcDecl DO
              IF ptr.IsTypeBound() &
                 (SameType(record, ptr.formalPars.receiver.srcCodeType) OR
                  (pointer # NIL) &
                  SameType(pointer, ptr.formalPars.receiver.srcCodeType)) THEN
                RETURN TRUE;
              END;
            ELSE
            END;
            ptr := ptr.nextNested;
          END;
          RETURN FALSE;
        END;
      END HasTypeBoundProcedures;
    
    BEGIN
      IF (item # NIL) THEN
        WITH item: Sym.TypeDecl DO
          IF (item. type IS Sym.Record) THEN
            (* this is a type declaration for a record on the module level *)
            ASSERT (item. parent IS Sym.Module);
            record := item. type(Sym.Record);
            pointerDecl := GetPointerDecl (item. parent, item. name);
            IF (pointerDecl # NIL) THEN
              pointerName := pointerDecl. name
            ELSE
              pointerName := NIL
            END;
            
            IF (pointerDecl # NIL) OR
               ((record. srcCodeBaseType # NIL) OR
               HasTypeBoundProcedures (item. parent, 
                                       item. name, pointerName)) THEN
              record. className := item. name;
              IF (pointerName # NIL) THEN
                Strings.FindNext (pointerName. str^, item. name. str^, 0,
                                  found, pos);
                IF found & (pos = 0) THEN
                  record. className := pointerDecl. name
                END
              END
            END
          END
        | item: Sym.ProcDecl DO  (* skip all non-global declarations *)
          RETURN
        ELSE
        END;
        
        ptr := item. nestedItems;
        WHILE (ptr # NIL) DO
          SetClassName (ptr);
          ptr := ptr. nextNested
        END
      END
    END SetClassName;

  PROCEDURE AddAutoImports (module: Sym.Module; len: LONGINT);
    VAR
      a, e: LONGINT;
      import: Sym.Import;
      
    PROCEDURE GetName (str: ARRAY OF CHAR; prefix: BOOLEAN): Sym.Name;
      VAR
        name: Sym.Name;
        nameStr: Sym.NameString;
      BEGIN
        NEW(name);
        NEW(nameStr, Strings.Length(str)+2);
        COPY(str, nameStr^);
        IF prefix THEN
          Strings.Insert("-", 0, nameStr^);
        END;
        Sym.InitName(name, nameStr, 0, 0, 0);
        RETURN name;
      END GetName;
    
    BEGIN
      FOR a := 0 TO len-1 DO
        e := LEN(autoImport[a].exclude^)-1;
        WHILE (e >= 0) & (autoImport[a].exclude[e]^ # module. name. str^) DO
          DEC (e);
        END;
        IF (e < 0) THEN (* this module does not appear in the exclusion list *)
          import := b. NewImport (module,
                                  GetName(autoImport[a].module^, TRUE),
                                  0, NIL,
                                  GetName(autoImport[a].module^, FALSE));
        END;
      END;
    END AddAutoImports;
  
  BEGIN
    CollectFormalPars (module);

    (* compute `getPointerDecl' for `SetClassName()' *)
    getPointerDecl := NEW(Dictionary.Dictionary(STRING, Sym.TypeDecl));
    hasTypeBoundProc := NEW(Dictionary.Dictionary(STRING, Object.Object));
    PreprocessSetClassName(module);
    SetClassName (module);
    
    IF (module.class = Sym.mcInternal) THEN
      (* no auto imports at all *)
    ELSIF (doAutoImport = fullAutoImport) THEN
      AddAutoImports (module, LEN(autoImport^));
    ELSIF (doAutoImport = autoImportRT0) THEN
      AddAutoImports (module, 1);
    END;
  END Finalize;



PROCEDURE (w: Writer) INIT*(ch, chDoc: IO.ByteChannel);
  BEGIN
    w.INIT^(ch, chDoc);
    w.names := NEW(Dictionary.Dictionary(STRING, Sym.Name));
  END INIT;

PROCEDURE (w: Writer) WriteObject* (obj: Object.Object) RAISES IO.Error;
  VAR
    str: STRING;
  BEGIN
    IF (obj = NIL) THEN
      w.WriteObject^(NIL);
    ELSE
      WITH obj: Sym.Name DO
        str := Object.NewLatin1(obj.str^);
        IF w.names.HasKey(str) THEN
          w.WriteObject^(w.names.Get(str));
        ELSE
          w.WriteObject^(obj);
          w.names.Set(str, obj);
        END;
      ELSE
        w.WriteObject^(obj);
      END;
    END;
  END WriteObject;

PROCEDURE (w: Writer) Disconnect*;
  BEGIN
    w.Disconnect^;
    w.names := NIL;
  END Disconnect;

PROCEDURE (b: Builder) WriteSymbolTable* (ch, chDoc: IO.ByteChannel;
                                          symTab: Sym.Module)
RAISES IO.Error;
  VAR
    writer: Writer;
  BEGIN
    (* Note: This method omits the magic number and the fingerprint value and
       is therefore not symmetric to ReadSymbolTable.  The two values are
       written by OOC:Auxiliary:WriteSymbolFile.WriteSymbolFile *)
    writer := NEW(Writer, ch, chDoc);
    writer. WriteObject (symTab);
  END WriteSymbolTable;

PROCEDURE (b: Builder) ReadSymbolTable* (ch, chDoc: IO.ByteChannel): Sym.Module
RAISES IO.Error;
  VAR
    obj: Object.Object;
    reader: Reader;
    fp, i, fpi, len: LONGINT;
    mn: ARRAY magicNumberSize+1 OF CHAR;
    prunedImports: Sym.ModuleRefArray;
    str: Sym.NameString;
  BEGIN
    reader := NEW(Reader, ch, chDoc);
    reader. ReadBytes(mn, 0, magicNumberSize);
    mn[magicNumberSize] := 0X;
    IF (mn # magicNumber) THEN
      Out.String ("Fatal error: Symbol file does not start with required magic number.");
      Out.Ln;
      HALT(1);
    END;
    reader. ReadBytes(fp, 0, SIZE(LONGINT));
    
    reader.ReadNum(len);
    NEW(prunedImports, len);
    FOR i := 0 TO LEN(prunedImports^)-1 DO
      reader.ReadNum(len);
      NEW(str, len+1);
      reader.ReadBytes(str^, 0, len);
      str[len] := 0X;
      reader.ReadBytes(fpi, 0, SIZE(LONGINT));
      
      NEW(prunedImports[i]);
      prunedImports[i].name := str;
      prunedImports[i].fingerprint := fpi;
    END;
    
    reader. ReadObject (obj);
    IF (obj = NIL) THEN
      RETURN NIL
    ELSE
      obj(Sym.Module).fingerprint := fp;
      obj(Sym.Module).prunedImports := prunedImports;
      RETURN obj(Sym.Module)
    END
  END ReadSymbolTable;


PROCEDURE N (str: ARRAY OF CHAR): Name;
  VAR
    len: LONGINT;
    name: Name;
  BEGIN
    len := Strings.Length(str);
    NEW (name, len+1);
    COPY (str, name^);
    RETURN name;
  END N;

BEGIN
  doAutoImport := noAutoImport;
  magicNumber := "OOC9";
  
  NEW(autoImport, 3);
  NEW(autoImport[0]);
  autoImport[0].module := N("RT0");
  NEW (autoImport[0].exclude, 2);
  autoImport[0].exclude[0] := autoImport[0].module;
  autoImport[0].exclude[1] := N("Out0");
  
  NEW(autoImport[1]);
  autoImport[1].module := N(stringModule);
  NEW (autoImport[1].exclude, 4);
  autoImport[1].exclude[0] := autoImport[0].module;
  autoImport[1].exclude[1] := autoImport[1].module;
  autoImport[1].exclude[2] := N("Out0");
  autoImport[1].exclude[3] := N("HashCode");
  
  NEW(autoImport[2]);
  autoImport[2].module := N("Exception");
  NEW (autoImport[2].exclude, 5);
  autoImport[2].exclude[0] := autoImport[0].module;
  autoImport[2].exclude[1] := autoImport[1].module;
  autoImport[2].exclude[2] := autoImport[2].module;
  autoImport[2].exclude[3] := N("Out0");
  autoImport[2].exclude[4] := N("HashCode");
END OOC:SymbolTable:Builder.
