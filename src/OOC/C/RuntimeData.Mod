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
      w. WriteLn;
      w. WriteString ("  ");
    END Nli;
  
  PROCEDURE WriteForm (form: ARRAY OF CHAR);
    BEGIN
      w. WriteString (Config.runtimeModule+"__");
      w. WriteString (form);
    END WriteForm;
  
  PROCEDURE ArrayTypeDescr (array: Sym.Array);
    VAR
      name: String.String;
    BEGIN
      name := Naming.NameOfTypeDescriptor (array);
      
      w. WriteLn;
      IF writeHeader THEN
        w. WriteString ("extern ");
      END;
      w. WriteString (structType);
      w. WriteString (" ");
      w. WriteString (name. array^);
      IF writeHeader THEN
        w. WriteString (";");
      ELSE
        w. WriteString (" = &("+structTypeDesc+"){");
        Nli;
        IF array. isOpenArray THEN
          WriteForm ("strOpenArray");
          w. WriteString (",");
          Nli;
          w. WriteLInt (array. GetOpenDimensions(), 0);
          w. WriteString (",");
        ELSE
          WriteForm ("strArray");
          w. WriteString (",");
          Nli;
          w. WriteLInt (array. length, 0);
          w. WriteString (",");
        END;
        w. WriteLn;
        w. WriteString ("};");
      END;
    END ArrayTypeDescr;
  
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
