(* 	$Id$	 *)
MODULE OOC:SymbolTable:Builder [OOC_EXTENSIONS];
(*  Defines a builder class with factory methods for symbol table entries.
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
  Strings, Channel, Language, ADT:Object, ADT:Object:Storage,
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

VAR
  autoImport-: POINTER TO ARRAY OF AutoImport;
  doAutoImport*: BOOLEAN;
  (**If @code{FALSE} (the default), don't do any automatical import in the
     symbol table or the the repository's
     @oproc{*OOC:Repository:GetImports.GetImports}.  Right now, only the
     program @code{oo2c} sets this to @code{TRUE}.  *)
  
  
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
                                      value: Language.Value;
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
                                 type: Sym.Type): Sym.TypeDecl;
  VAR
    t: Sym.TypeDecl;
  BEGIN
    NEW (t);
    Sym.InitTypeDecl (t, parent, name, visibleFrom, exportMark, docString, type);
    IF (type. namingDecl = NIL) THEN
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
                                     isTypeBound, isForwardDecl: BOOLEAN;
                                     procAST: AST.Node): Sym.ProcDecl;
  VAR
    procDecl: Sym.ProcDecl;
  BEGIN
    NEW (procDecl);
    Sym.InitProcDecl (procDecl, parent, name, visibleFrom, exportMark, 
                       docString, isTypeBound, isForwardDecl, procAST);
    RETURN procDecl
  END NewProcDecl;



PROCEDURE (b: Builder) NewPredefType* (parent: Sym.Item; id: Sym.PredefId): Sym.PredefType;
  VAR
    ptype: Sym.PredefType;
  BEGIN
    NEW (ptype);
    Sym.InitPredefType (ptype, parent, id);
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
    IF (b.class = Sym.mcInterface) THEN
      record.hasDescriptor := FALSE;
      record.isExtensible := FALSE;
    END;
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
    IF isOpenArray & (b.class = Sym.mcInterface) THEN
      array.hasDescriptor := FALSE;
      array.hasLengthInfo := FALSE;
    END;
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
    IF (b.class = Sym.mcInterface) THEN
      ptr.isStatic := TRUE;
    END;
    RETURN ptr
  END NewPointer;

PROCEDURE (b: Builder) NewFormalPars* (parent: Sym.Item;
                                       position: Sym.Position;
                                       resultType: Sym.Type): Sym.FormalPars;
  VAR
    fpars: Sym.FormalPars;
  BEGIN
    NEW (fpars);
    Sym.InitFormalPars (fpars, parent, position, resultType);
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
                                NIL, FALSE, FALSE, NIL);
    bodyDecl. formalPars := b. NewFormalPars(bodyDecl, name, NIL);
    NEW (bodyDecl. formalPars. params, 0);
    
    NEW (mod);
    Sym.InitModule (mod, name, docString, class, callConv, moduleAST,
                    bodyDecl);
    RETURN mod
  END NewModule;


PROCEDURE (b: Builder) Finalize* (module: Sym.Module);
  PROCEDURE CollectFormalPars (item: Sym.Item);
  (* Sets the field @ofield{Sym.FormalPars.params} for
     all formal parameter definitions under @oparam{item}.  *)
    VAR
      ptr: Sym.Item;
      c: LONGINT;
    BEGIN
      IF (item # NIL) THEN
        WITH item: Sym.FormalPars DO
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
          END
        ELSE
        END;
        
        ptr := item. nestedItems;
        WHILE (ptr # NIL) DO
          CollectFormalPars (ptr);
          ptr := ptr. nextNested
        END
      END
    END CollectFormalPars;
  
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
      BEGIN
        pointerDecl := NIL;
        ptr := scope. nestedItems;
        WHILE (ptr # NIL) DO
          WITH ptr: Sym.TypeDecl DO
            IF (ptr. type IS Sym.Pointer) &
               SameType (typeName, ptr.type(Sym.Pointer).srcCodeBaseType) THEN
              IF (pointerDecl = NIL) THEN
                pointerDecl := ptr
              ELSE
                RETURN NIL
              END
            END
          ELSE
          END;
          ptr := ptr. nextNested
        END;
        RETURN pointerDecl
      END GetPointerDecl;
    
    PROCEDURE HasTypeBoundProcedures (scope: Sym.Item;
                                      record, pointer: Sym.Name): BOOLEAN;
      VAR
        ptr: Sym.Item;
      BEGIN
        ptr := scope. nestedItems;
        WHILE (ptr # NIL) DO
          WITH ptr: Sym.ProcDecl DO
            IF ptr. isTypeBound &
               (SameType (record, ptr.formalPars.receiver.srcCodeType) OR
                (pointer # NIL) &
                SameType (pointer, ptr.formalPars.receiver.srcCodeType)) THEN
              RETURN TRUE
            END
          ELSE
          END;
          ptr := ptr. nextNested
        END;
        RETURN FALSE
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

  PROCEDURE AddAutoImports (module: Sym.Module);
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
      FOR a := 0 TO LEN(autoImport^)-1 DO
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
    SetClassName (module);
    IF doAutoImport THEN
      AddAutoImports (module);
    END;
  END Finalize;

PROCEDURE (b: Builder) WriteSymbolTable* (ch: Channel.Channel; symTab: Sym.Module; VAR res: Channel.Result);
  VAR
    writer: Storage.Writer;
  BEGIN
    (* Note: This method omits the fingerprint value and is therefore
       not symmetric to ReadSymbolTable *)
    writer := Storage.ConnectWriter (ch);
    writer. WriteObject (symTab);
    res := writer. res;
    IF (res = Channel.done) THEN
      res := ch. res
    END
  END WriteSymbolTable;

PROCEDURE (b: Builder) ReadSymbolTable* (ch: Channel.Channel;
                                         VAR res: Channel.Result): Sym.Module;
  VAR
    obj: Object.Object;
    reader: Storage.Reader;
    fp: LONGINT;
  BEGIN
    reader := Storage.ConnectReader (ch);
    reader. ReadBytes(fp, 0, SIZE(LONGINT));
    reader. ReadObject (obj);
    res := reader. res;
    IF (obj = NIL) THEN
      RETURN NIL
    ELSE
      obj(Sym.Module).fingerprint := fp;
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
  doAutoImport := FALSE;
  
  NEW(autoImport, 2);
  NEW(autoImport[0]);
  autoImport[0].module := N("RT0");
  NEW (autoImport[0].exclude, 2);
  autoImport[0].exclude[0] := autoImport[0].module;
  autoImport[0].exclude[1] := N("Out0");
  NEW(autoImport[1]);
  autoImport[1].module := N("Language:String0");
  NEW (autoImport[1].exclude, 3);
  autoImport[1].exclude[0] := autoImport[0].module;
  autoImport[1].exclude[1] := autoImport[1].module;
  autoImport[1].exclude[2] := N("Out0");
END OOC:SymbolTable:Builder.
