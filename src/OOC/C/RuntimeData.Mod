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
  TextRider, ADT:String, Sym := OOC:SymbolTable,
  OOC:Auxiliary:Config, OOC:C:Naming, OOC:C:DeclWriter;

CONST
  structType = Config.runtimeModule+"__Struct";
  structTypeDesc = Config.runtimeModule+"__StructDesc";
  
PROCEDURE Write* (declWriter: DeclWriter.Writer;
                  symTab: Sym.Module; writeHeader: BOOLEAN);
  VAR
    w: TextRider.Writer;

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
  
  PROCEDURE ArrayTypeDescr (array: Sym.Array);
    VAR
      name: String.String;
      base: Sym.Type;
    BEGIN
      WriteDescrVariable (array);
      IF ~writeHeader THEN
        IF array. isOpenArray THEN
          base := array. GetNonOpenElementType();
          name := Naming.NameOfTypeDescriptor (base);
          w.WriteChar ("&");
          w. WriteString (name. array^); (* base *)
          CNli; w.WriteLInt (-1, 0);     (* size *)
          CNli; w. WriteLInt (array. GetOpenDimensions(), 0); (* len *)
          CNli; WriteForm ("strOpenArray"); (* form *)
        ELSE
          name := Naming.NameOfTypeDescriptor (array. elementType);
          w.WriteChar ("&");
          w. WriteString (name. array^); (* base *)
          CNli; w.WriteLInt (array. size, 0); (* size *)
          CNli; w. WriteLInt (array. length, 0); (* len *)
          CNli; WriteForm ("strArray");  (* form *)
        END;
        w. WriteString (" };");
      END;
    END ArrayTypeDescr;
  
  PROCEDURE RecordTypeDescr (record: Sym.Record);
    VAR
      name: String.String;
      base: Sym.Type;

    PROCEDURE BaseTypes (t: Sym.Type): LONGINT;
      BEGIN
        IF (t = NIL) THEN
          RETURN 0;
        ELSE
          RETURN BaseTypes (t(Sym.Record). baseType)+1;
        END;
      END BaseTypes;
    
    BEGIN
      WriteDescrVariable (record);
      IF ~writeHeader THEN
        IF (record. baseType = NIL) THEN
          w. WriteString ("NULL");       (* base *)
        ELSE
          name := Naming.NameOfTypeDescriptor (record. baseType);
          w.WriteChar ("&");
          w. WriteString (name. array^); (* base *)
        END;
        CNli; w.WriteLInt (record. size, 0); (* size *)
        CNli; w. WriteLInt (BaseTypes (record. baseType), 0); (* len *)
        CNli; WriteForm ("strRecord"); (* form *)
        w. WriteString (" };");
      END;
    END RecordTypeDescr;
  
  PROCEDURE PointerTypeDescr (pointer: Sym.Pointer);
    VAR
      name: String.String;
      base: Sym.Type;
    BEGIN
      WriteDescrVariable (pointer);
      IF ~writeHeader THEN
        name := Naming.NameOfTypeDescriptor (pointer. baseType);
        w.WriteChar ("&");
        w. WriteString (name. array^); (* base *)
        CNli; w.WriteLInt (pointer. size, 0); (* size *)
        CNli; w. WriteLInt (-1, 0); (* len *)
        CNli; WriteForm ("strPointer"); (* form *)
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
        IF ~IsParameter (item) THEN
          ArrayTypeDescr (item);
        END;

      | item: Sym.Record DO
        RecordTypeDescr (item);
        
      | item: Sym.Pointer DO
        PointerTypeDescr (item);
        
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
  
  BEGIN
    w := declWriter. textWriter;
    w. WriteLn;
    w. WriteString ("/* run-time meta data */");
    Traverse (symTab, NIL);
    w. WriteLn;
  END Write;

END OOC:C:RuntimeData.
