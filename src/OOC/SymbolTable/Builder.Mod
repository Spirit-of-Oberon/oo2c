(* 	$Id$	 *)
MODULE OOC:SymbolTable:Builder [OOC_EXTENSIONS];
(*  Defines a builder class with factory methods for symbol table entries.
    Copyright (C) 2000, 2001  Michael van Acken

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
  OOC:Doc, OOC:SymbolTable:Item;


TYPE
  Builder* = POINTER TO BuilderDesc;
  BuilderDesc* = RECORD
    (**The builder defines a factory method for every item that can appear
       in a module's symbol table.  The arguments of the factory methods
       are passed directly to the initialization procedures of the
       corresponding classes from @omodule{Item}.
       The arguments correspond directly to the record fields defined for
       the specializations of @otype{Item.Item}.  *)
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


PROCEDURE (b: Builder) NewModule* (name: Item.Name; docString: Doc.Document;
                                   class: Item.ModuleClass;
                                   callConv: Item.CallConv): Item.Module;
  VAR
    mod: Item.Module;
  BEGIN
    NEW (mod);
    Item.InitModule (mod, name, docString, class, callConv);
    RETURN mod
  END NewModule;

PROCEDURE (b: Builder) NewImport* (parent: Item.Item; name: Item.Name;
                                   visibleFrom: Item.ModulePos;
                                   docString: Doc.Document;
                                   moduleName: Item.Name): Item.Import;
  VAR
    import: Item.Import;
  BEGIN
    NEW (import);
    Item.InitImport (import, parent, name, visibleFrom, docString, moduleName);
    RETURN import
  END NewImport;

PROCEDURE (b: Builder) NewConstDecl* (parent: Item.Item; name: Item.Name;
                                      visibleFrom: Item.ModulePos;
                                      exportMark: Item.ExportMark;
                                      docString: Doc.Document;
                                      value: Language.Value;
                                      type: Item.PredefType): Item.ConstDecl;
(**Note: If the value and type of the constant are not known yet, 
   then @oparam{value} is @code{NIL}.  *)
  VAR
    const: Item.ConstDecl;
  BEGIN
    NEW (const);
    Item.InitConstDecl (const, parent, name, visibleFrom, exportMark,
                        docString, value, type);
    RETURN const
  END NewConstDecl;

PROCEDURE (b: Builder) NewTypeDecl* (parent: Item.Item; name: Item.Name;
                                 visibleFrom: Item.ModulePos;
                                 exportMark: Item.ExportMark;
                                 docString: Doc.Document;
                                 type: Item.Type): Item.TypeDecl;
  VAR
    t: Item.TypeDecl;
  BEGIN
    NEW (t);
    Item.InitTypeDecl (t, parent, name, visibleFrom, exportMark, docString, type);
    IF (type. typeName = NIL) THEN
      type. SetTypeName (name);
    END;
    RETURN t
  END NewTypeDecl;

PROCEDURE (b: Builder) NewVarDecl* (parent: Item.Item; name: Item.Name;
                                 visibleFrom: Item.ModulePos;
                                 exportMark: Item.ExportMark;
                                 docString: Doc.Document;
                                 isParameter, isReceiver, isVarParam: BOOLEAN;
                                 type: Item.Type): Item.VarDecl;
  VAR
    var: Item.VarDecl;
  BEGIN
    NEW (var);
    Item.InitVarDecl (var, parent, name, visibleFrom, exportMark, docString,
                      isParameter, isReceiver, isVarParam, type);
    RETURN var
  END NewVarDecl;

PROCEDURE (b: Builder) NewFieldDecl* (parent: Item.Item; name: Item.Name;
                                      visibleFrom: Item.ModulePos;
                                      exportMark: Item.ExportMark;
                                      docString: Doc.Document;
                                      type: Item.Type): Item.FieldDecl;
  VAR
    field: Item.FieldDecl;
  BEGIN
    NEW (field);
    Item.InitFieldDecl (field, parent, name, visibleFrom, exportMark, docString, type);
    RETURN field
  END NewFieldDecl;

PROCEDURE (b: Builder) NewPredefProc* (parent: Item.Item; name: Item.Name; id: Item.PredefId): Item.PredefProc;
  VAR
    pproc: Item.PredefProc;
  BEGIN
    NEW (pproc);
    Item.InitPredefProc (pproc, parent, name, id);
    RETURN pproc
  END NewPredefProc;

PROCEDURE (b: Builder) NewProcDecl* (parent: Item.Item; name: Item.Name;
                           visibleFrom: Item.ModulePos;
                           exportMark: Item.ExportMark;
                           docString: Doc.Document;
                           isTypeBound, isForwardDecl: BOOLEAN): Item.ProcDecl;
  VAR
    procDecl: Item.ProcDecl;
  BEGIN
    NEW (procDecl);
    Item.InitProcDecl (procDecl, parent, name, visibleFrom, exportMark, 
                       docString, isTypeBound, isForwardDecl);
    RETURN procDecl
  END NewProcDecl;



PROCEDURE (b: Builder) NewPredefType* (parent: Item.Item; id: Item.PredefId): Item.PredefType;
  VAR
    ptype: Item.PredefType;
  BEGIN
    NEW (ptype);
    Item.InitPredefType (ptype, parent, id);
    RETURN ptype
  END NewPredefType;

PROCEDURE (b: Builder) NewTypeName* (parent: Item.Item;
                                     position: Item.Position;
                                     module, ident: Item.Name): Item.TypeName;
  VAR
    tname: Item.TypeName;
  BEGIN
    NEW (tname);
    Item.InitTypeName (tname, parent, position, module, ident);
    RETURN tname
  END NewTypeName;

PROCEDURE (b: Builder) NewRecord* (parent: Item.Item;
                                   position: Item.Position;
                                   baseType: Item.Type): Item.Record;
  VAR
    record: Item.Record;
  BEGIN
    NEW (record);
    Item.InitRecord (record, parent, position, baseType);
    RETURN record
  END NewRecord;

PROCEDURE (b: Builder) NewArray* (parent: Item.Item; 
                                  position: Item.Position;
                                  isOpenArray: BOOLEAN;
                                  elementType: Item.Type): Item.Array;
  VAR
    array: Item.Array;
  BEGIN
    NEW (array);
    Item.InitArray (array, parent, position, isOpenArray, elementType);
    RETURN array
  END NewArray;

PROCEDURE (b: Builder) NewPointer* (parent: Item.Item;
                                    position: Item.Position;
                                    baseType: Item.Type): Item.Pointer;
  VAR
    ptr: Item.Pointer;
  BEGIN
    NEW (ptr);
    Item.InitPointer (ptr, parent, position, baseType);
    RETURN ptr
  END NewPointer;

PROCEDURE (b: Builder) NewFormalPars* (parent: Item.Item;
                                       position: Item.Position;
                                       resultType: Item.Type): Item.FormalPars;
  VAR
    fpars: Item.FormalPars;
  BEGIN
    NEW (fpars);
    Item.InitFormalPars (fpars, parent, position, resultType);
    RETURN fpars
  END NewFormalPars;


PROCEDURE (b: Builder) Finalize* (module: Item.Module);
  PROCEDURE CollectFormalPars (item: Item.Item);
  (* Sets the field @ofield{OOC:SymbolTable:Item.FormalPars.params} for
     all formal parameter definitions under @oparam{item}.  *)
    VAR
      ptr: Item.Item;
      c: LONGINT;
    BEGIN
      IF (item # NIL) THEN
        WITH item: Item.FormalPars DO
          c := 0;
          ptr := item. nestedItems;
          WHILE (ptr # NIL) DO
            IF (ptr IS Item.VarDecl) & 
               ptr(Item.VarDecl). isParameter &
               ~ptr(Item.VarDecl). isReceiver THEN
              INC (c)
            END;
            ptr := ptr. nextNested
          END;
          
          NEW (item. params, c);
          c := 0;
          ptr := item. nestedItems;
          WHILE (ptr # NIL) DO
            IF (ptr IS Item.VarDecl) &
               ptr(Item.VarDecl). isParameter &
               ~ptr(Item.VarDecl). isReceiver THEN
              item. params[c] := ptr(Item.VarDecl);
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
  
  PROCEDURE SetClassName (item: Item.Item);
    VAR
      ptr: Item.Item;
      pointerDecl: Item.TypeDecl;
      pointerName: Item.Name;
      record: Item.Record;
      found: BOOLEAN;
      pos: INTEGER;
    
    PROCEDURE SameType (decl: Item.Name; typeName: Item.Type): BOOLEAN;
      BEGIN
        WITH typeName: Item.TypeName DO
          RETURN (typeName. module = NIL) &
                 (typeName. ident. str^ = decl. str^)
        ELSE
          RETURN FALSE
        END
      END SameType;
    
    PROCEDURE GetPointerDecl (scope: Item.Item; typeName: Item.Name): Item.TypeDecl;
      VAR
        ptr: Item.Item;
        pointerDecl: Item.TypeDecl;
      BEGIN
        pointerDecl := NIL;
        ptr := scope. nestedItems;
        WHILE (ptr # NIL) DO
          WITH ptr: Item.TypeDecl DO
            IF (ptr. type IS Item.Pointer) &
               SameType (typeName, ptr.type(Item.Pointer).srcCodeBaseType) THEN
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
    
    PROCEDURE HasTypeBoundProcedures (scope: Item.Item;
                                      record, pointer: Item.Name): BOOLEAN;
      VAR
        ptr: Item.Item;
      BEGIN
        ptr := scope. nestedItems;
        WHILE (ptr # NIL) DO
          WITH ptr: Item.ProcDecl DO
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
        WITH item: Item.TypeDecl DO
          IF (item. type IS Item.Record) THEN
            (* this is a type declaration for a record on the module level *)
            ASSERT (item. parent IS Item.Module);
            record := item. type(Item.Record);
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
        | item: Item.ProcDecl DO  (* skip all non-global declarations *)
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

PROCEDURE (b: Builder) WriteSymbolTable* (ch: Channel.Channel; symTab: Item.Module; VAR res: Channel.Result);
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

PROCEDURE (b: Builder) ReadSymbolTable* (ch: Channel.Channel; VAR res: Channel.Result): Item.Module;
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
      RETURN obj(Item.Module)
    END
  END ReadSymbolTable;

END OOC:SymbolTable:Builder.
