(* 	$Id$	 *)
MODULE OOC:C:RuntimeData;
(*  Writes C code for run-time data like type descriptors.
    Copyright (C) 2002  Michael van Acken

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
  TextRider, ADT:String, ADT:ArrayList, OOC:Config, Sym := OOC:SymbolTable,
  OOC:SymbolTable:Namespace, OOC:C:Naming, OOC:C:DeclWriter;

CONST
  structTypeDesc = Config.runtimeModule+"__StructDesc";
  
PROCEDURE Write* (declWriter: DeclWriter.Writer;
                  symTab: Sym.Module; writeHeader: BOOLEAN);
  VAR
    w: TextRider.Writer;
    tdNames: ArrayList.ArrayList;
    
  PROCEDURE Nli ();                      (* new line and indent *)
    BEGIN
      (*w. WriteLn;
      w. WriteString ("  ");*)
      
      w. WriteChar (" ");
    END Nli;
  
  PROCEDURE CNli ();                     (* comma, new line and indent *)
    BEGIN
      (*w. WriteChar (",");
      w. WriteLn;
      w. WriteString ("  ");*)
      
      w. WriteString (", ");
    END CNli;
  
  PROCEDURE WriteForm (form: ARRAY OF CHAR);
    BEGIN
      w. WriteString (Config.runtimeModule+"__");
      w. WriteString (form);
    END WriteForm;
  
  PROCEDURE WriteDescrVariable (type: Sym.Type);
    VAR
      name: String.String;
    BEGIN
      name := Naming.NameOfTypeDescriptor (type);
      
      w. WriteLn;
      IF writeHeader THEN
        w. WriteString ("extern ");
      ELSIF (type. namingDecl # NIL) &
            (type. namingDecl. parent IS Sym.Module) THEN
        tdNames.Append (name);
      END;
      w. WriteString (structTypeDesc);
      w. WriteString (" ");
      w. WriteString (name. array^);
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
      name: String.String;
    BEGIN
      IF type.hasDescriptor THEN
        w.WriteString("&");
        name := Naming.NameOfTypeDescriptor(type);
        w.WriteString(name.array^);
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
          CNli; w. WriteString ("&_mid"); (* module *)
          WriteName (array);             (* name *)
          ASSERT(base.size >= 0);
          CNli; w. WriteLInt (base. size, 0); (* size *)
          CNli; w. WriteLInt (array. GetOpenDimensions(), 0); (* len *)
          CNli; WriteForm ("strOpenArray"); (* form *)
        ELSE
          w. WriteString ("(RT0__Struct[]){"); (* baseTypes *)
          WriteTDRef(array.elementType);
          w. WriteChar ("}");
          CNli; w. WriteString ("NULL"); (* tbProcs *)
          CNli; w. WriteString ("&_mid"); (* module *)
          WriteName (array);             (* name *)
          CNli; w.WriteLInt (array. size, 0); (* size *)
          CNli; w. WriteLInt (array. length, 0); (* len *)
          CNli; WriteForm ("strArray");  (* form *)
        END;
        w. WriteString (" };");
      END;
    END ArrayTypeDescr;
  
  PROCEDURE RecordTypeDescr (record: Sym.Record);
    VAR
      len: LONGINT;

    PROCEDURE BaseTypes (t: Sym.Type): LONGINT;
      VAR
        len: LONGINT;
        name: String.String;
      BEGIN
        IF (t = NIL) THEN
          RETURN -1;
        ELSE
          len := BaseTypes (t(Sym.Record). baseType);
          name := Naming.NameOfTypeDescriptor (t);
          w. WriteChar ("&");
          w. WriteString (name. array^);
          IF (t # record) THEN
            w. WriteChar (",");
          END;
          RETURN len+1;
        END;
      END BaseTypes;

    PROCEDURE TBProcs (tbProcCount: LONGINT);
      VAR
        i: LONGINT;
        proc: Sym.ProcDecl;
        name: String.String;
      BEGIN
        FOR i := 0 TO tbProcCount-1 DO
          IF (i # 0) THEN
            w. WriteChar (",");
          END;
          proc := record. ns(Namespace.Extended). GetTBProcByIndex (i);
          ASSERT (proc # NIL);
          w. WriteString ("(void*)");
          name := Naming.NameOfDeclaration (proc);
          w. WriteString (name. array^);
        END;
      END TBProcs;
    
    BEGIN
      WriteDescrVariable (record);
      IF ~writeHeader THEN
        w. WriteString ("(RT0__Struct[]){"); (* baseTypes *)
        len := BaseTypes (record);
        w. WriteChar ("}");
        CNli; w. WriteString ("(void*[]){");   (* tbProcs *)
        TBProcs (record. tbProcCount);
        w. WriteChar ("}");
        CNli; w. WriteString ("&_mid");  (* module *)
        WriteName (record);              (* name *)
        CNli; w. WriteLInt (record. size, 0); (* size *)
        CNli; w. WriteLInt (len, 0);     (* len *)
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
        CNli; w. WriteString ("&_mid");  (* module *)
        WriteName (pointer);             (* name *)
        CNli; w. WriteLInt (pointer. size, 0); (* size *)
        CNli; w. WriteLInt (-1, 0);      (* len *)
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
        w. WriteString (tdNames. array[i](String.String). array^);
        CNli;
      END;
      w. WriteString ("NULL } };");
      w. WriteLn;
    END ModuleDescr;

  PROCEDURE ModuleInit (module: Sym.Module);
    VAR
      name0, name: String.String;
    BEGIN
      name0 := Naming.NameOfModuleInit (module, TRUE);
      name := Naming.NameOfModuleInit (module, FALSE);
      w. WriteLn;
      w. WriteString ("extern void ");
      w. WriteString (name0. array^);
      w. WriteString ("() {");
      IF (module. name. str^ # Config.runtimeModule) THEN
        (* cannot register the lowest level run-time module with itself *)
        w. WriteLn;
        w. WriteString ("  RT0__RegisterModule(&_mid);");
      END;
      w. WriteLn;
      w. WriteString ("  ");
      w. WriteString (name. array^);
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
      ModuleDescr (symTab, tdNames);     (* define _mid *)
      ModuleInit (symTab);
    END;
    w. WriteLn;
  END Write;

END OOC:C:RuntimeData.
