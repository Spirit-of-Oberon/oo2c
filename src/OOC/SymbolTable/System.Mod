(* 	$Id$	 *)
MODULE OOC:SymbolTable:System;
(*  Defines symbol table of pseudo module with predefined entities.
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
  Strings, OOC:SymbolTable:Item, OOC:SymbolTable:Builder;


CONST
  address* = 100;
  byte* = 101;
  ptr* = 102;
  
PROCEDURE CreateModule* (stb: Builder.Builder): Item.Module;
(**Creates the symbol table of the pseudo module that contains the predefined
   entities of the language, that can be used directly in a module without
   prefixing them with a module name.  It declares types like @samp{CHAR},
   @samp{BOOLEAN}, or @samp{INTEGER}, as well as predefined procedures and
   functions, like @samp{COPY} or @samp{LEN}.  *)
  VAR
    module: Item.Module;
  
  PROCEDURE GetName (name: ARRAY OF CHAR): Item.Name;
    VAR
      n: Item.Name;
      str: Item.NameString;
    BEGIN
      NEW (n);
      NEW (str, Strings.Length (name)+1);
      COPY (name, str^);
      Item.InitName (n, str, 0, 1, 0);
      RETURN n
    END GetName;

  PROCEDURE SystemType (id: Item.PredefId; name: ARRAY OF CHAR);
    VAR
      ptype: Item.PredefType;
      tdecl: Item.TypeDecl;
    BEGIN
      ptype := stb. NewPredefType (module, id);
      tdecl := stb. NewTypeDecl (module, GetName (name), 0,
                                 Item.nameExported, NIL, ptype)
    END SystemType;
  
  BEGIN
    module := stb. NewModule (GetName ("SYSTEM"), NIL, Item.mcInternal, Item.callConvInternal);
    
    SystemType (address, "ADDRESS");
    SystemType (byte, "BYTE");
    SystemType (ptr, "PTR");
    
    stb. Finalize (module);
    RETURN module
  END CreateModule;

END OOC:SymbolTable:System.
