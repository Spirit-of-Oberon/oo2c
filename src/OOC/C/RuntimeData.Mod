(* 	$Id: RuntimeData.Mod,v 1.26 2004/01/20 06:59:57 sgreenhill Exp $	 *)
MODULE OOC:C:RuntimeData;
(*  Writes C code for run-time data like type descriptors.
    Copyright (C) 2002, 2003  Michael van Acken

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
  IO:TextRider, ADT:ArrayList, ADT:StringBuffer,
  OOC:Config, Sym := OOC:SymbolTable,
  OOC:SymbolTable:Namespace, TR := OOC:SymbolTable:TypeRules,
  OOC:C:Naming, OOC:C:DeclWriter, Strings;

CONST
  structTypeDesc = Config.runtimeModule+"__StructDesc";
  
PROCEDURE Write* (declWriter: DeclWriter.Writer; symTab: Sym.Module;
                  qtdData: Naming.QualTypeData; writeHeader: BOOLEAN);
  VAR
    w: TextRider.Writer;
    tdNames: ArrayList.ArrayList;
    
  PROCEDURE Nli();       (* new line and indent *)
    BEGIN
      (*w. WriteLn;
      w. WriteString ("  ");*)
      
      w. WriteChar (" ");
    END Nli;
  
  PROCEDURE CNli();   (* comma, new line and indent *)
    BEGIN
      (*w. WriteChar (",");
      w. WriteLn;
      w. WriteString ("  ");*)
      
      w. WriteString (", ");
    END CNli;
  
  PROCEDURE WriteFlags(type : Sym.Type);
    (* Output any special run-time flags associated with type @oparam{type}. *)

    VAR
      output : BOOLEAN;    (* TRUE iff output has been generated yet. *)

    PROCEDURE GetName (name: ARRAY OF CHAR): Sym.Name;
      (* This should be declared public somewhere since it is used from various
         places: SymbolTable:Builder, SymbolTable.Predef, here, ... *)
      VAR
        n: Sym.Name;
        str: Sym.NameString;
      BEGIN
        NEW (n);
        NEW (str, Strings.Length (name)+1);
        COPY (name, str^);
        Sym.InitName (n, str, 0, 1, 0);
        RETURN n
      END GetName;
    
    PROCEDURE ImplementsFinalize(t : Sym.Record) : BOOLEAN;
      (* Determine if record @oparam{t} overrides RT0:ObjectDesc.Finalize. *) 
      CONST
        name = "Finalize";
        class = "ObjectDesc";
        module = "RT0";
      VAR 
        decl : Sym.Declaration;   (* method declaration *)
        root : Sym.Type;          (* root class for @oparam{t} *)
        impl : Sym.Type;          (* implementing class for Finalize method *)
      BEGIN
        decl := t.ns.Identify(t, GetName(name), TRUE);
        IF (decl # NIL) & (decl IS Sym.ProcDecl) THEN
          (* @oparam{t} implements procedure Finalize *)
  
          (* Find the root type that this record implements. *)
          root := t.Deparam();
          WHILE (root IS Sym.Record) & (root(Sym.Record).baseType # NIL) DO
            root := root(Sym.Record).baseType.Deparam();
          END;
  
          (* Find the record type to which Finalize is bound. *) 
          impl := decl(Sym.ProcDecl).formalPars.receiver.type.Deparam();
          impl := impl(Sym.Pointer).baseType.Deparam();
  
          RETURN (impl # root) &
            (root.namingDecl.name.str^ = class) &
            (root.namingDecl.parent IS Sym.Module) &
            (root.namingDecl.parent(Sym.Module).name.str^ = module);
        ELSE
          RETURN FALSE;
        END;
      END ImplementsFinalize;
  
    PROCEDURE OutFlag(name : ARRAY OF CHAR);
      BEGIN
        IF output THEN
          w.WriteString("|");
        END;
        w.WriteString("(1<<");
        w.WriteString(name);
        w.WriteString(")");
        output := TRUE;
      END OutFlag;
  
    BEGIN
      output := FALSE;
      IF type # NIL THEN
        WITH type : Sym.Record DO
          IF type.isVtable THEN
            OutFlag("RT0__flagVTable");
          END;
    
          IF type.isAtomic THEN
            OutFlag("RT0__flagAtomic");
          END;
    
          IF ImplementsFinalize(type) THEN
            OutFlag("RT0__flagFinalize");
          END;
        | type : Sym.Array DO
          IF type.isAtomic THEN
            OutFlag("RT0__flagAtomic");
          END;
        ELSE
        END;
      END;
      IF ~output THEN
        w.WriteString("0");
      END;
    END WriteFlags; 

  PROCEDURE WriteForm (form: ARRAY OF CHAR);
    BEGIN
      w. WriteString (Config.runtimeModule+"__");
      w. WriteString (form);
    END WriteForm;
  
  PROCEDURE WriteDescrVariable (type: Sym.Type);
    VAR
      name: STRING;
    BEGIN
      name := Naming.NameOfTypeDescriptor (type, qtdData);
      
      w. WriteLn;
      IF writeHeader THEN
        w. WriteString ("extern ");
      ELSIF (type. namingDecl # NIL) &
            (type. namingDecl. parent IS Sym.Module) THEN
        tdNames.Append (name);
      END;
      w. WriteString (structTypeDesc);
      w. WriteString (" ");
      w. WriteObject (name);
      IF writeHeader THEN
        w. WriteString (";");
      ELSE
        w. WriteString (" = {");
        Nli;
      END;
    END WriteDescrVariable;

  PROCEDURE WriteName (type: Sym.Type);
    BEGIN
      CNli;
      IF (type. namingDecl = NIL) THEN
        w. WriteString ("NULL");
      ELSE
        w. WriteChar ('"');
        w. WriteString (type. namingDecl. name. str^);
        w. WriteChar ('"');
      END;
    END WriteName;

  PROCEDURE WriteTDRef(type: Sym.Type);
    VAR
      name: STRING;
    BEGIN
      type := type.Deparam();
      IF type.hasDescriptor THEN
        w.WriteString("&");
        name := Naming.NameOfTypeDescriptor(type, qtdData);
        w.WriteObject(name);
      ELSE
        w.WriteString("NULL");
      END;
    END WriteTDRef;
  
  PROCEDURE ArrayTypeDescr (array: Sym.Array);
    VAR
      base: Sym.Type;
    BEGIN
      WriteDescrVariable (array);
      IF ~writeHeader THEN
        IF array. isOpenArray THEN
          base := array. GetNonOpenElementType();
          w. WriteString ("(RT0__Struct[]){"); (* baseTypes *)
          WriteTDRef(base);
          w. WriteChar ("}");
          CNli; w. WriteString ("NULL"); (* tbProcs *)
          CNli; w. WriteString ("NULL"); (* typeArgs *)
          CNli; w. WriteString ("&_mid"); (* module *)
          WriteName (array);             (* name *)
          ASSERT(base.size >= 0);
          CNli; w. WriteLInt (base. size, 0); (* size *)
          CNli; w. WriteLInt (array. GetOpenDimensions(), 0); (* len *)
          CNli; WriteFlags(array);          (* flags *)
          CNli; WriteForm ("strOpenArray"); (* form *)
        ELSE
          w. WriteString ("(RT0__Struct[]){"); (* baseTypes *)
          WriteTDRef(array.elementType);
          w. WriteChar ("}");
          CNli; w. WriteString ("NULL"); (* tbProcs *)
          CNli; w. WriteString ("NULL"); (* typeArgs *)
          CNli; w. WriteString ("&_mid"); (* module *)
          WriteName (array);             (* name *)
          CNli; w.WriteLInt (array. size, 0); (* size *)
          CNli; w. WriteLInt (array. length, 0); (* len *)
          CNli; WriteFlags(array);       (* flags *)
          CNli; WriteForm ("strArray");  (* form *)
        END;
        w. WriteString (" };");
      END;
    END ArrayTypeDescr;
  
  PROCEDURE TBProcs (record: Sym.Record; tbProcCount: LONGINT);
    VAR
      i: LONGINT;
      proc: Sym.ProcDecl;
      name: STRING;
    BEGIN
      FOR i := 0 TO tbProcCount-1 DO
        IF (i # 0) THEN
          w. WriteChar (",");
        END;
        proc := record. ns(Namespace.Extended). GetTBProcByIndex (i);
        ASSERT (proc # NIL);
        w. WriteString ("(void*)");
        name := Naming.NameOfDeclaration (proc);
        w. WriteObject (name);
      END;
    END TBProcs;
  
  PROCEDURE RecordTypeDescr (record: Sym.Record);
    VAR
      len: LONGINT;

    PROCEDURE BaseTypes (t: Sym.Type): LONGINT;
      VAR
        len: LONGINT;
        name: STRING;
      BEGIN
        IF (t = NIL) THEN
          RETURN -1;
        ELSE
          t := t.Deparam();
          len := BaseTypes (t(Sym.Record). baseType);
          name := Naming.NameOfTypeDescriptor (t, qtdData);
          w. WriteChar ("&");
          w. WriteObject(name);
          IF (t # record) THEN
            w. WriteChar (",");
          END;
          RETURN len+1;
        END;
      END BaseTypes;

    BEGIN
      WriteDescrVariable (record);
      IF ~writeHeader THEN
        w. WriteString ("(RT0__Struct[]){"); (* baseTypes *)
        len := BaseTypes (record);
        w. WriteChar ("}");
        CNli; w. WriteString ("(void*[]){");   (* tbProcs *)
        TBProcs(record, record.tbProcCount);
        w. WriteChar ("}");
        CNli; w. WriteString ("NULL");   (* typeArgs *)
        CNli; w. WriteString ("&_mid");  (* module *)
        WriteName (record);              (* name *)
        CNli; w. WriteLInt (record. size, 0); (* size *)
        CNli; w. WriteLInt (len, 0);     (* len *)

        CNli; WriteFlags(record);        (* flags *)
        CNli; WriteForm ("strRecord");   (* form *)
        w. WriteString (" };");
      END;
    END RecordTypeDescr;
  
  PROCEDURE PointerTypeDescr (pointer: Sym.Pointer);
    BEGIN
      WriteDescrVariable (pointer);
      IF ~writeHeader THEN
        w. WriteString ("(RT0__Struct[]){"); (* baseTypes *)
        WriteTDRef(pointer.baseType);
        w. WriteChar ("}");
        CNli; w. WriteString ("NULL");   (* tbProcs *)
        CNli; w. WriteString ("NULL");   (* typeArgs *)
        CNli; w. WriteString ("&_mid");  (* module *)
        WriteName (pointer);             (* name *)
        CNli; w. WriteLInt (pointer. size, 0); (* size *)
        CNli; w. WriteLInt (-1, 0);      (* len *)
        CNli; WriteFlags(pointer);       (* flags *)
        CNli; WriteForm ("strPointer");  (* form *)
        w. WriteString (" };");
      END;
    END PointerTypeDescr;
  
  PROCEDURE Traverse (item: Sym.Item; proc: Sym.ProcDecl);
    VAR
      nested: Sym.Item;

    PROCEDURE IsParameter (item: Sym.Item): BOOLEAN;
      BEGIN
        WHILE (item # proc) &
              ~((item IS Sym.VarDecl) & item(Sym.VarDecl). isParameter) DO
          item := item. parent;
        END;
        RETURN (item # proc);
      END IsParameter;

    BEGIN
      WITH item: Sym.Array DO
        IF item.hasDescriptor & ~IsParameter (item) THEN
          ArrayTypeDescr (item);
        END;

      | item: Sym.Record DO
        IF item.hasDescriptor THEN
          RecordTypeDescr (item);
        END;
        
      | item: Sym.Pointer DO
        IF item.hasDescriptor THEN
          PointerTypeDescr (item);
        END;
        
      | item: Sym.ProcDecl DO            (* adjust current procedure *)
        proc := item;
      ELSE                               (* ignore everything else *)
      END;

      nested := item. nestedItems;
      WHILE (nested # NIL) DO
        Traverse (nested, proc);
        nested := nested. nextNested;
      END;
    END Traverse;

  PROCEDURE QualTypeDescr(qtdData: Naming.QualTypeData);
    VAR
      i: LONGINT;

    PROCEDURE QualTypeName(t: Sym.Type): STRING;
      VAR
        sb: StringBuffer.StringBuffer;
        i: LONGINT;
        module: Sym.Module;
      BEGIN
        sb := NEW(StringBuffer.StringBuffer, 128);
        WITH t: Sym.TypeClosure DO
          sb.Append(QualTypeName(t.baseType));
          sb.Append("(");
          FOR i := 0 TO LEN(t.arguments^)-1 DO
            IF (i # 0) THEN
              sb.Append(",");
            END;
            sb.Append(QualTypeName(t.arguments[i].type));
          END;
          sb.Append(")");
        ELSE
          module := t.Module();
          sb.AppendLatin1(module.name.str^);
          sb.Append(".");
          sb.AppendLatin1(t.namingDecl.name.str^);
        END;
        RETURN sb.ToString();
      END QualTypeName;
    
    PROCEDURE BaseTypes (record: Sym.Type; t: Sym.Type): LONGINT;
      VAR
        len: LONGINT;
        name: STRING;
      BEGIN
        IF (t = NIL) THEN
          RETURN -1;
        ELSE
          len := BaseTypes(record, TR.RecordBaseType(t));
          name := Naming.NameOfTypeDescriptor (t, qtdData);
          w. WriteChar ("&");
          w. WriteObject(name);
          IF (t # record) THEN
            w. WriteChar (",");
          END;
          RETURN len+1;
        END;
      END BaseTypes;

    PROCEDURE WriteQualTypeDescr(qtd: Naming.QualTypeDescr);
      VAR
        i, len: LONGINT;
        name: STRING;
        record: Sym.Record;
      BEGIN
        tdNames.Append(qtd.name);       (* add to td list in module *)
        
        w.WriteLn;
        w.WriteString("static ");
        w.WriteString(structTypeDesc);
        w.WriteString(" ");
        w.WriteObject(qtd.name);
        w.WriteString(" = {");
        Nli;

        IF (qtd.type.Deparam() IS Sym.Record) THEN
          w. WriteString ("(RT0__Struct[]){"); (* baseTypes *)
          len := BaseTypes (qtd.type, qtd.type);
          w. WriteChar ("}");
          
          CNli; w. WriteString ("(void*[]){"); (* tbProcs *)
          record := qtd.type.baseType(Sym.Record);
          TBProcs(record, record.tbProcCount);
          w. WriteChar ("}");
        ELSE  (* IS Sym.Pointer *)
          len := 0;
          w. WriteString ("(RT0__Struct[]){"); (* baseTypes *)
          w.WriteString("&");
          name := Naming.NameOfTypeDescriptor(TR.PointerBaseType(qtd.type),
                                              qtdData);
          w.WriteObject(name);
          w. WriteChar ("}");
          CNli; w.WriteString("NULL");   (* tbProcs *)
          record := NIL;
        END;
        
        CNli; w.WriteString("(RT0__Struct[]){"); (* typeArgs *)
        WriteTDRef(qtd.type.baseType);
        FOR i := 0 TO LEN(qtd.type.arguments^)-1 DO
          CNli;
          WriteTDRef(qtd.type.arguments[i].type);
        END;
        w.WriteString(", NULL}");
        
        CNli; w.WriteString("&_mid");    (* module *)
        
        CNli; w.WriteChar('"');          (* name *)
        w.WriteObject(QualTypeName(qtd.type));
        w.WriteChar('"');
        
        CNli; w.WriteLInt(qtd.type.size, 0); (* size *)
        CNli; w.WriteLInt(len, 0);       (* len *)
        CNli; WriteFlags(record);        (* flags *)
        CNli; WriteForm("strQualType");   (* form *)
        w.WriteString(" };");
      END WriteQualTypeDescr;
    
    BEGIN
      FOR i := 0 TO qtdData.list.size-1 DO
        WriteQualTypeDescr(qtdData.list.array[i]);
      END;
    END QualTypeDescr;
  
  PROCEDURE ModuleDescr (module: Sym.Module; tdNames: ArrayList.ArrayList);
    VAR
      i: LONGINT;
    BEGIN
      w. WriteLn;
      w. WriteString ("static RT0__ModuleDesc _mid = {");
      Nli;
      w. WriteString ('(OOC_CHAR8*)"');
      w. WriteString (module. name. str^);
      w. WriteString ('"');
      CNli;
      w. WriteString ("(RT0__Struct[]) {");
      Nli;
      FOR i := 0 TO tdNames. size-1 DO
        w. WriteString ("&");
        w. WriteObject (tdNames. array[i](STRING));
        CNli;
      END;
      w. WriteString ("NULL } };");
      w. WriteLn;
    END ModuleDescr;

  PROCEDURE ModuleInit (module: Sym.Module);
    VAR
      name0, name: STRING;
    BEGIN
      name0 := Naming.NameOfModuleInit (module, TRUE);
      name := Naming.NameOfModuleInit (module, FALSE);
      w. WriteLn;
      w. WriteString ("extern void ");
      w. WriteObject (name0);
      w. WriteString ("() {");
      IF (module. name. str^ # Config.runtimeModule) THEN
        (* cannot register the lowest level run-time module with itself *)
        w. WriteLn;
        w. WriteString ("  RT0__RegisterModule(&_mid);");
      END;
      w. WriteLn;
      w. WriteString ("  ");
      w. WriteObject (name);
      w. WriteString ("();");
      w. WriteLn;
      w. WriteString ("}");
    END ModuleInit;
  
  BEGIN
    w := declWriter. textWriter;
    tdNames := ArrayList.New (16);
    w. WriteLn;
    w. WriteString ("/* run-time meta data */");
    IF ~writeHeader THEN
      w. WriteLn;
      w. WriteString ("static RT0__ModuleDesc _mid;"); (* make _mid known *)
    END;
    Traverse (symTab, NIL);
    IF ~writeHeader THEN
      QualTypeDescr(qtdData);
      ModuleDescr (symTab, tdNames);     (* define _mid *)
      ModuleInit (symTab);
    END;
    w. WriteLn;
  END Write;

END OOC:C:RuntimeData.
