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
       corresponding classes from @omodule{Sym}.
       The arguments correspond directly to the record fields defined for
       the specializations of @otype{Sym.Item}.  *)
  END;


PROCEDURE Init* (b: Builder);
  BEGIN
  END Init;

PROCEDURE New* (): Builder;
  VAR
    b: Builder;
  BEGIN
    NEW (b);
    Init (b);
    RETURN b
  END New;


PROCEDURE (b: Builder) NewModule* (name: Sym.Name; docString: Doc.Document;
                                   class: Sym.ModuleClass;
                                   callConv: Sym.CallConv;
                                   moduleAST: AST.Node): Sym.Module;
  VAR
    mod: Sym.Module;
  BEGIN
    NEW (mod);
    Sym.InitModule (mod, name, docString, class, callConv, moduleAST);
    RETURN mod
  END NewModule;

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
    IF (type. typeName = NIL) THEN
      type. SetTypeName (name);
    END;
    RETURN t
  END NewTypeDecl;

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

PROCEDURE (b: Builder) NewPredefProc* (parent: Sym.Item; name: Sym.Name; id: Sym.PredefId): Sym.PredefProc;
  VAR
    pproc: Sym.PredefProc;
  BEGIN
    NEW (pproc);
    Sym.InitPredefProc (pproc, parent, name, id);
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


PROCEDURE (b: Builder) Finalize* (module: Sym.Module);
  PROCEDURE CollectFormalPars (item: Sym.Item);
  (* Sets the field @ofield{Sym := OOC:SymbolTable.FormalPars.params} for
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
  
  BEGIN
    CollectFormalPars (module);
    SetClassName (module)
  END Finalize;

PROCEDURE (b: Builder) WriteSymbolTable* (ch: Channel.Channel; symTab: Sym.Module; VAR res: Channel.Result);
  VAR
    writer: Storage.Writer;
  BEGIN
    writer := Storage.ConnectWriter (ch);
    writer. WriteObject (symTab);
    res := writer. res;
    IF (res = Channel.done) THEN
      res := ch. res
    END
  END WriteSymbolTable;

PROCEDURE (b: Builder) ReadSymbolTable* (ch: Channel.Channel; VAR res: Channel.Result): Sym.Module;
  VAR
    obj: Object.Object;
    reader: Storage.Reader;
  BEGIN
    reader := Storage.ConnectReader (ch);
    reader. ReadObject (obj);
    res := reader. res;
    IF (obj = NIL) THEN
      RETURN NIL
    ELSE
      RETURN obj(Sym.Module)
    END
  END ReadSymbolTable;

END OOC:SymbolTable:Builder.
