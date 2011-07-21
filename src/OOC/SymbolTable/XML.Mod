(* 	$Id: XML.Mod,v 1.15 2003/05/06 22:00:01 mva Exp $	 *)
MODULE OOC:SymbolTable:XML;
(*  Converts symbol table to XML document.
    Copyright (C) 2000, 2001, 2002, 2003  Michael van Acken

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
  Strings, Object, IO, XML:Writer, XML:UnicodeCodec:Latin1,
  Dictionary := ADT:Dictionary:IntValue, 
  Sym := OOC:SymbolTable, OOC:SymbolTable:GetClass,
  DocXML := OOC:Doc:Output:XML;


PROCEDURE Write* (cw: IO.ByteChannel; module: Sym.Module)
RAISES IO.Error;
(**Writes the symbol table with root @oparam{module} to the output writer 
   @oparam{cw}.  The result is an XML document that describes the
   structure of the symbol table.  Here is an example of the output for the
   most simple module:
   
   @example
   MODULE M;

   TYPE R = RECORD a: INTEGER END;

   END M.
   @end example
   
   @example
   <?xml version='1.0' encoding='ISO-8859-1' standalone='yes'?>
   <module id='0' name='M' pos='7' line='1' column='7' visible_from='0' export='no'>
     <record_type id='1' pos='20' line='3' column='9' base_type='#none' tb_proc_count='0'>
       <type_name id='2' pos='30' line='3' column='19' ident_name='INTEGER' ident_pos='30' ident_line='3' ident_column='19'>
       </type_name>
       <field_decl id='3' name='a' pos='27' line='3' column='16' visible_from='37' export='no' type_id='#predef.INTEGER'>
       </field_decl>
     </record_type>
     <type_decl id='4' name='R' pos='16' line='3' column='5' visible_from='41' export='no' type_id='1'>
     </type_decl>
   </module>
   @end example  *)
  VAR
    w: Writer.Writer;
    counter: LONGINT;
    items: POINTER TO ARRAY OF Sym.Item;
    floatingItems: Dictionary.Dictionary;
    
  PROCEDURE CountItems (item: Sym.Item): LONGINT;
    VAR
      c: LONGINT;
      ptr: Sym.Item;
    BEGIN
      IF (item = NIL) THEN
        RETURN 0
      ELSE
        c := 1; ptr := item. nestedItems;
        WHILE (ptr # NIL) DO
          INC (c, CountItems (ptr));
          ptr := ptr. nextNested
        END;
        RETURN c
      END
    END CountItems;
  
  PROCEDURE StoreId (item: Sym.Item; VAR id: LONGINT);
    VAR
      ptr: Sym.Item;
    BEGIN
      IF (item # NIL) THEN
        items[id] := item;
        INC (id);
        ptr := item. nestedItems;
        WHILE (ptr # NIL) DO
          StoreId (ptr, id);
          ptr := ptr. nextNested
        END
      END
    END StoreId;
  
  PROCEDURE Id (item: Sym.Item): LONGINT;
    VAR
      i: LONGINT;
    BEGIN
      i := 0;
      WHILE (i # LEN(items^)) & (items[i] # item) DO
        INC (i)
      END;
      IF (i = LEN(items^)) THEN
        IF ~floatingItems.HasKey(item) THEN
          floatingItems.Set(item, -(floatingItems.Size()+1));
        END;
        RETURN floatingItems.Get(item);
      ELSE
        RETURN i;
      END;
    END Id;
  
  
  PROCEDURE WriteItem (item: Sym.Item);
    VAR
      element: ARRAY 32 OF CHAR;
      str: STRING;
      chars: Object.CharsLatin1;
      
    PROCEDURE StartTag (str: ARRAY OF CHAR; id: LONGINT);
      BEGIN
        w. StartTagLatin1 (str, FALSE);
        w. AttrInt ("id", id);
        INC (counter)
      END StartTag;
    
    PROCEDURE AttribString (prefix, name, value: ARRAY OF CHAR);
      VAR
        str: ARRAY 256 OF CHAR;
        str16: ARRAY 256 OF LONGCHAR;
      BEGIN
        COPY (prefix, str);
        Strings.Append (name, str);
        COPY (str, str16);
        w. AttrStringLatin1 (str16, value)
      END AttribString;
    
    PROCEDURE AttribInt (prefix, name: ARRAY OF CHAR; value: LONGINT);
      VAR
        str: ARRAY 256 OF CHAR;
        str16: ARRAY 256 OF LONGCHAR;
      BEGIN
        COPY (prefix, str);
        Strings.Append (name, str);
        COPY (str, str16);
        w. AttrInt (str16, value)
      END AttribInt;
    
    PROCEDURE AttribBool (prefix, name: ARRAY OF CHAR; value: BOOLEAN);
      VAR
        str: ARRAY 256 OF CHAR;
        str16: ARRAY 256 OF LONGCHAR;
      BEGIN
        COPY (prefix, str);
        Strings.Append (name, str);
        COPY (str, str16);
        w. AttrBool (str16, value)
      END AttribBool;
    
    PROCEDURE AttribTypeId (prefix, name: ARRAY OF CHAR; type: Sym.Type);
      VAR
        str: ARRAY 1024 OF CHAR;
        m: Sym.Module;
      BEGIN
        m := type. Module();
        IF (m = module) THEN
          AttribInt (prefix, name, Id (type))
        ELSE
          COPY (m. name. str^, str);
          Strings.Append (".", str);
          Strings.Append (type. namingDecl. name. str^, str);
          AttribString (prefix, name, str)
        END
      END AttribTypeId;
    
    PROCEDURE WriteNested (item: Sym.Item);
      VAR
        i: Sym.Item;
      BEGIN
        i := item. nestedItems;
        WHILE (i # NIL) DO
          WriteItem (i);
          i := i. nextNested
        END
      END WriteNested;
    
    PROCEDURE PositionAttributes (position: Sym.Position;
                                  prefix: ARRAY OF CHAR);
      BEGIN
        AttribInt (prefix, "pos", position. pos);
        AttribInt (prefix, "line", position. line);
        AttribInt (prefix, "column", position. column);
      END PositionAttributes;
    
    PROCEDURE NameAttributes (name: Sym.Name; prefix: ARRAY OF CHAR);
      BEGIN
        AttribString (prefix, "name", name. str^);
        PositionAttributes (name, prefix)
      END NameAttributes;
    
    PROCEDURE ClassAttributes (item: Sym.Item);
      VAR
        class: Sym.Name;
      BEGIN
        class := GetClass.GetClass (item);
        IF (class # NIL) THEN
          AttribString ("", "class", class. str^)
        END
      END ClassAttributes;
    
    BEGIN
      IF (item # NIL) THEN
        WITH item: Sym.Declaration DO
          WITH item: Sym.Module DO
            element := "module"
          | item: Sym.Import DO
            element := "import"
          | item: Sym.ProcDecl DO
            element := "procedure_decl"
          | item: Sym.ConstDecl DO
            element := "const_decl"
          | item: Sym.TypeDecl DO
            element := "type_decl"
          | item: Sym.VarDecl DO
            element := "var_decl"
          | item: Sym.FieldDecl DO
            element := "field_decl"
          | item: Sym.PredefProc DO
            element := "predef_proc"
          | item: Sym.Redirect DO
          END;
          
          StartTag (element, Id (item));
          NameAttributes (item. name, "");
          ClassAttributes (item);
          AttribInt ("", "visible_from", item. visibleFrom);
          CASE item. exportMark OF
          | Sym.nameNotExported:
            AttribString ("", "export", "no")
          | Sym.nameExported:
            AttribString ("", "export", "yes")
          | Sym.nameExportedRO:
            AttribString ("", "export", "read-only")
          END;
          
          WITH item: Sym.Module DO
            str := item. ClassToString();
            IF ~str.Equals("standard") THEN
              chars := str(Object.String8).CharsLatin1();
              AttribString ("", "class", chars^)
            END;
            IF (item.libraryName # NIL) THEN
              chars := item.libraryName(Object.String8).CharsLatin1();
              AttribString("", "library_name", chars^);
            END;
            str := item. CallConvToString();
            IF ~str.Equals("default") THEN
              chars := str(Object.String8).CharsLatin1();
              AttribString ("", "call_conv", chars^)
            END
            
          | item: Sym.Import DO
            NameAttributes (item. moduleName, "imported_module_")
          | item: Sym.ProcDecl DO
            AttribBool ("", "is_type_bound", item.IsTypeBound());
            AttribBool ("", "is_forward_decl", item. isForwardDecl);
            IF item.IsTypeBound() THEN
              AttribInt ("", "tb_proc_index", item. tbProcIndex)
            END
          | item: Sym.ConstDecl DO
          | item: Sym.TypeDecl DO
            IF item.isTypeParameter THEN
              AttribBool("", "is_type_parameter", item.isTypeParameter);
            END;
            AttribTypeId ("", "type_id", item. type)
          | item: Sym.VarDecl DO
            AttribBool ("", "is_parameter", item. isParameter);
            AttribBool ("", "is_receiver", item. isReceiver);
            AttribBool ("", "is_var_parameter", item. isVarParam);
            AttribTypeId ("", "type_id", item. type)
          | item: Sym.FieldDecl DO
            AttribTypeId ("", "type_id", item. type)
          | item: Sym.PredefProc DO
            (* FIXME... what to write here? *)
          | item: Sym.Redirect DO
            AttribString ("", "module", item.module.str^);
            AttribString ("", "name", item.name.str^);
          END;
          
          IF (item. docString # NIL) THEN
            DocXML.WriteOberonDoc (w, item. docString, module, NIL, NIL, NIL)
          END;
          WriteNested (item);
          w. EndTag
          
        | item: Sym.TypePars DO
          StartTag ("type_pars", Id (item));
          WriteNested (item);
          w. EndTag
          
        | item: Sym.Type DO
          WITH item: Sym.TypeName DO
            element := "type_name"
          | item: Sym.Pointer DO
            element := "pointer_type"
          | item: Sym.Record DO
            element := "record_type"
          | item: Sym.Array DO
            element := "array_type"
          | item: Sym.FormalPars DO
            element := "procedure_type"
          | item: Sym.PredefType DO
            element := "predef_type"
          | item: Sym.TypeVar DO
            element := "type_var"
          | item: Sym.QualType DO
            element := "qual_type"
          END;
          StartTag (element, Id (item));

          IF ~(item IS Sym.PredefType) THEN
            PositionAttributes (item. position, "");
          END;
          IF (item.typePars # NIL) THEN
            AttribInt("", "type_pars_id", Id(item.typePars));
          END;
          ClassAttributes (item);
          WITH item: Sym.TypeName DO
            IF (item. module # NIL) THEN
              NameAttributes (item. module, "module_")
            END;
            NameAttributes (item. ident, "ident_")
          | item: Sym.Pointer DO
            AttribTypeId ("", "base_type_id", item. baseType)
          | item: Sym.Array DO
            AttribBool ("", "is_open_array", item. isOpenArray);
            AttribTypeId ("", "element_type_id", item. elementType)
          | item: Sym.Record DO
            IF (item. baseType = NIL) THEN
              AttribString ("", "base_type", "#none")
            ELSE
              AttribTypeId ("", "base_type_id", item. baseType)
            END;
            AttribInt ("", "tb_proc_count", item. tbProcCount)
          | item: Sym.FormalPars DO
            IF (item. receiver # NIL) THEN
              AttribInt ("", "receiver_id", Id (item. receiver))
            END;
            IF (item. resultType = NIL) THEN
              AttribString ("", "resultType", "#none")
            ELSE
              AttribTypeId ("", "result_type_id", item. resultType)
            END;
            IF item. anyRestParameters THEN
              AttribBool ("", "any_rest_parameters", TRUE)
            END
          | item: Sym.PredefType DO
            (* FIXME... what to write here? *)
          | item: Sym.TypeVar DO
            AttribTypeId ("", "bound_id", item. bound)
          | item: Sym.QualType DO
            AttribTypeId ("", "base_type_id", item. baseType);
          END;
          
          WriteNested (item);
          w. EndTag;
              
        | item: Sym.ExceptionName DO
          StartTag ("exception_name", Id (item));
          AttribTypeId ("", "type_id", item. type);
          w. EndTag;
        END
      END
    END WriteItem;

  BEGIN
    w := Writer.New (cw, Latin1.factory, TRUE, 2);
    w. WriteTextDecl ("1.0", "yes");
    
    counter := 0;
    NEW (items, CountItems (module));
    StoreId (module, counter);
    ASSERT (counter = LEN (items^));
    floatingItems := Dictionary.New();
    
    WriteItem (module);
    w. EndOfText
  END Write;

END OOC:SymbolTable:XML.
