(* 	$Id$	 *)
MODULE OOC:SymbolTable:Predef;
(*  Defines symbol table of pseudo module with predefined entities.
    Copyright (C) 2000, 2001, 2002  Michael van Acken

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
  Strings, Language, Language:Boolean,
  Sym := OOC:SymbolTable, OOC:SymbolTable:Builder;


CONST
  (* note: ids must be unique across all predefined types; changing the
     id of a type breaks existing symbol files! *)
  boolean* = 0;
  char* = 1;
  longchar* = 2;
  shortint* = 3;
  integer* = 4;
  longint* = 5;
  real* = 6;
  longreal* = 7;
  set* = 8;
  address* = 9;
  byte* = 10;
  ptr* = 11;

  charString* = 12;
  longcharString* = 13;
  void* = 14;
  lastId = void;

  lengthType* = 5;
  (**Alias for the integer type used to represent the length of an array.
     This is also the result type of the predefined function @code{LEN}.
     Normally, this is the same as @oconst{longint}.  Use this symbolic
     name when producing values the are array indices or lengths.  *)
  
CONST
  (* These represent set of types that may be treated similarly. *)

  classChar* = {char, longchar};
  classInteger* = {shortint, integer, longint};
  classReal* = {real, longreal};
  classNumeric* = classInteger + classReal;
  classSet* = {set};

CONST
  (* predefine procedures and functions *)
  assert* = 0;

PROCEDURE GetName (name: ARRAY OF CHAR): Sym.Name;
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

PROCEDURE PredefType (stb: Builder.Builder;
                      module: Sym.Module;
                      id: Sym.PredefId;
                      name: ARRAY OF CHAR): Sym.PredefType;
  VAR
    ptype: Sym.PredefType;
    tdecl: Sym.TypeDecl;
  BEGIN
    ptype := stb. NewPredefType (module, id);
    Sym.predefIdToType[id] := ptype;
    IF (name # "") THEN
      tdecl := stb. NewTypeDecl (module, GetName (name), 0,
                                 Sym.nameExported, NIL, ptype)
    END;
    RETURN ptype
  END PredefType;

PROCEDURE CreatePredef* (stb: Builder.Builder): Sym.Module;
(**Creates the symbol table of the pseudo module that contains the predefined
   entities of the language, that can be used directly in a module without
   prefixing them with a module name.  It declares types like @samp{CHAR},
   @samp{BOOLEAN}, or @samp{INTEGER}, as well as predefined procedures and
   functions, like @samp{COPY} or @samp{LEN}.  *)
  VAR
    module: Sym.Module;
    ptype: Sym.PredefType;
    
  PROCEDURE PredefProc (id: Sym.PredefId; name: ARRAY OF CHAR);
    VAR
      pproc: Sym.PredefProc;
    BEGIN
      pproc := stb. NewPredefProc (module, GetName (name), id);
    END PredefProc;
  
  PROCEDURE PredefConst (name: ARRAY OF CHAR; value: Language.Value;
                         type: Sym.PredefType);
    VAR
      cdecl: Sym.ConstDecl;
    BEGIN
      cdecl := stb. NewConstDecl (module, GetName (name), 0, Sym.nameExported,
                                  NIL, value, type)
    END PredefConst;
  
  BEGIN
    module := stb. NewModule (GetName ("#predef"), NIL, Sym.mcInternal, Sym.callConvInternal);
    
    ptype := PredefType (stb, module, boolean, "BOOLEAN");
    PredefConst ("FALSE", Boolean.New (FALSE), ptype);
    PredefConst ("TRUE", Boolean.New (TRUE), ptype);
    
    ptype := PredefType (stb, module, char, "CHAR");
    ptype := PredefType (stb, module, longchar, "LONGCHAR");
    ptype := PredefType (stb, module, shortint, "SHORTINT");
    ptype := PredefType (stb, module, integer, "INTEGER");
    ptype := PredefType (stb, module, longint, "LONGINT");
    ptype := PredefType (stb, module, real, "REAL");
    ptype := PredefType (stb, module, longreal, "LONGREAL");
    ptype := PredefType (stb, module, set, "SET");
    
    ptype := PredefType (stb, module, charString, "");
    ptype := PredefType (stb, module, longcharString, "");
    ptype := PredefType (stb, module, void, "");
    
    PredefProc (assert, "ASSERT");
    
    stb. Finalize (module);
    RETURN module
  END CreatePredef;

PROCEDURE CreateSYSTEM* (stb: Builder.Builder): Sym.Module;
(**Creates the symbol table of the pseudo module @code{SYSTEM}.  *)
  VAR
    module: Sym.Module;
    ptype: Sym.PredefType;
  BEGIN
    module := stb. NewModule (GetName ("SYSTEM"), NIL, Sym.mcInternal, Sym.callConvInternal);
    
    ptype := PredefType (stb, module, address, "ADDRESS");
    ptype := PredefType (stb, module, byte, "BYTE");
    ptype := PredefType (stb, module, ptr, "PTR");
    
    stb. Finalize (module);
    RETURN module
  END CreateSYSTEM;

PROCEDURE GetType* (id: Sym.PredefId): Sym.PredefType;
  BEGIN
    RETURN Sym.predefIdToType[id]
  END GetType;

BEGIN
  NEW (Sym.predefIdToType, lastId+1)
END OOC:SymbolTable:Predef.
