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
  Strings, Language, Language:Boolean, Language:Integer, Language:String8,
  Language:String16, Language:Real,
  Sym := OOC:SymbolTable, OOC:SymbolTable:Builder;


CONST
  (* note: ids must be unique across all predefined types; changing the
     id of a type breaks existing symbol files! *)
  boolean* = 0;
  (**Predefined type @code{BOOLEAN}.  *)
  char* = 1;
  (**Predefined type @code{CHAR}.  On all platforms supported by OOC this is 1
     byte.  The character encoding is ISO Latin-1.  *)
  longchar* = 2;
  (**Predefined type @code{LONGCHAR}.  An OOC extension.  A 2 byte Unicode
     character value encoded as UCS-2.  (FIXME... is this the correct encoding
     name?)  *)
  shortint* = 3;
  (**Integer value, two's complement encoding, stored in one byte.  *)
  integer* = 4;
  (**Integer value, two's complement encoding, stored in two bytes.  *)
  longint* = 5;
  (**Integer value, two's complement encoding, stored in four bytes.  *)
  hugeint* = 6;
  (**Integer value, two's complement encoding, stored in eight bytes.  *)
  real* = 7;
  (**Floating point value, IEEE-754 single precision, stored in four bytes.  *)
  longreal* = 8;
  (**Floating point value, IEEE-754 single precision, stored in eight bytes. *)
  set* = 9;
  (**A set of integer values in the range @samp{0 <= x < 32}.  Stored in
     four bytes.  *)
  
  address* = longint;
  byte* = 10;
  ptr* = 11;

  charString* = 12;
  (**A string value based on the predefined type @code{CHAR}.  This is a
     sequence of arbitrary @oconst{char} constants.  In particular, the string
     may contain the character code @code{0X}.  *)
  longcharString* = 13;
  (**Like @oconst{charString}, but based on the type @code{LONGCHAR}.  *)
  nil* = 14;
  (**The type of the constant @code{NIL}.  *)
  void* = 15;
  (**The return type of procedures, indicating that no result is produced.  *)
  
  lastId* = void;
  (**Id of last predefined type.  Typically used in client modules
     to declare variables @code{ARRAY @oconst{lastId}+1 OF @dots{}}.  *)
  
  lengthType* = 5;
  (**Alias for the integer type used to represent the length of an array.
     This is also the result type of the predefined function @code{LEN}.
     Normally, this is the same as @oconst{longint}.  Use this symbolic
     name when producing values the are array indices or lengths.  *)

CONST
  minChar* = MIN(CHAR);         maxChar* = MAX(CHAR);
  minLongchar* = MIN(LONGCHAR); maxLongchar* = MAX(LONGCHAR);
  
VAR
  minConst, maxConst: ARRAY lastId+1 OF Language.Value;
  (**Array with the @code{MIN} and @code{MAX} values of the predefined
     types.  An entry @code{NIL} means that the operation is not
     applicable to the type.  *)

CONST
  (* predefined procedures and functions *)
  assert* = 0;                           (* ASSERT *)
  len* = 1;                              (* LEN *)
  size* = 2;                             (* SIZE *)
  inc* = 3;                              (* INC *)
  dec* = 4;                              (* DEC *)
  ash* = 5;                              (* ASH *)
  cap* = 6;                              (* CAP *)
  long* = 7;                             (* LONG *)
  short* = 8;                            (* SHORT *)
  chr* = 9;                              (* CHR *)
  entier* = 10;                          (* ENTIER *)
  odd* = 11;                             (* ODD *)
  ord* = 12;                             (* ORD *)
  max* = 13;                             (* MAX *)
  min* = 14;                             (* MIN *)
  new* = 15;                             (* NEW *)
  copy* = 16;                            (* COPY *)

  adr* = 17;                             (* SYSTEM.ADR *)
  
VAR
  i: LONGINT;

  
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
                      name: ARRAY OF CHAR;
                      size: LONGINT; align: INTEGER;
                      minValue, maxValue: Language.Value): Sym.PredefType;
  VAR
    ptype: Sym.PredefType;
    tdecl: Sym.TypeDecl;
  BEGIN
    ptype := stb. NewPredefType (module, id);
    ptype. SetSize (size, SHORT (size));
    Sym.predefIdToType[id] := ptype;
    minConst[id] := minValue;
    maxConst[id] := maxValue;
    IF (name # "") THEN
      tdecl := stb. NewTypeDecl (module, GetName (name), 0,
                                 Sym.nameExported, NIL, ptype)
    END;
    RETURN ptype
  END PredefType;

PROCEDURE TypeAlias (stb: Builder.Builder;
                     module: Sym.Module;
                     name: ARRAY OF CHAR; baseType: Sym.PredefType);
  VAR
    tdecl: Sym.TypeDecl;
  BEGIN
    tdecl := stb. NewTypeDecl (module, GetName (name), 0,
                               Sym.nameExported, NIL, baseType);
  END TypeAlias;

PROCEDURE PredefProc (stb: Builder.Builder; module: Sym.Module;
                      id: Sym.PredefId; name: ARRAY OF CHAR;
                      minArgs, maxArgs: INTEGER);
  VAR
    pproc: Sym.PredefProc;
  BEGIN
    pproc := stb. NewPredefProc (module, GetName (name), id, minArgs, maxArgs);
  END PredefProc;

PROCEDURE CreatePredef* (stb: Builder.Builder): Sym.Module;
(**Creates the symbol table of the pseudo module that contains the predefined
   entities of the language, that can be used directly in a module without
   prefixing them with a module name.  It declares types like @samp{CHAR},
   @samp{BOOLEAN}, or @samp{INTEGER}, as well as predefined procedures and
   functions, like @samp{COPY} or @samp{LEN}.  *)
  VAR
    module: Sym.Module;
    ptype: Sym.PredefType;
    
  PROCEDURE PredefConst (name: ARRAY OF CHAR; value: Language.Value;
                         type: Sym.PredefType);
    VAR
      cdecl: Sym.ConstDecl;
    BEGIN
      cdecl := stb. NewConstDecl (module, GetName (name), 0, Sym.nameExported,
                                  NIL, value, type, NIL)
    END PredefConst;
  
  BEGIN
    module := stb. NewModule (GetName ("#predef"), NIL, Sym.mcInternal,
                              Sym.callConvInternal, NIL);
    
    ptype := PredefType (stb, module, boolean, "BOOLEAN", 1, 1, NIL, NIL);
    PredefConst ("FALSE", Boolean.New (FALSE), ptype);
    PredefConst ("TRUE", Boolean.New (TRUE), ptype);
    
    ptype := PredefType (stb, module, char, "CHAR", 1, 1,
                         String8.NewChar (minChar),
                         String8.NewChar (maxChar));
    ptype := PredefType (stb, module, longchar, "LONGCHAR", 2, 2,
                         String16.NewChar (minLongchar),
                         String16.NewChar (maxLongchar));
    ptype := PredefType (stb, module, shortint, "SHORTINT", 1, 1,
                         Integer.New (MIN (SHORTINT)),
                         Integer.New (MAX (SHORTINT)));
    ptype := PredefType (stb, module, integer, "INTEGER", 2, 2,
                         Integer.New (MIN (INTEGER)),
                         Integer.New (MAX (INTEGER)));
    ptype := PredefType (stb, module, longint, "LONGINT", 4, 4,
                         Integer.New (MIN (LONGINT)),
                         Integer.New (MAX (LONGINT)));
    ptype := PredefType (stb, module, hugeint, "HUGEINT", 4, 4,
                         Integer.NewString ("-9223372036854775808"),
                         Integer.NewString ("9223372036854775807"));
    ptype := PredefType (stb, module, real, "REAL", 4, 4,
                         Real.New (MIN (REAL)),
                         Real.New (MAX (REAL)));
    ptype := PredefType (stb, module, longreal, "LONGREAL", 8, 8,
                         Real.New (MIN (LONGREAL)),
                         Real.New (MAX (LONGREAL)));
    ptype := PredefType (stb, module, set, "SET", 4, 4,
                         Integer.New (MIN (SET)),
                         Integer.New (MAX (SET)));
    
    ptype := PredefType (stb, module, charString, "", Sym.dynamicSize, 1,
                         NIL, NIL);
    ptype := PredefType (stb, module, longcharString, "", Sym.dynamicSize, 2,
                         NIL, NIL);
    ptype := PredefType (stb, module, nil, "", 4, 4,
                         NIL, NIL);
    ptype := PredefType (stb, module, void, "", 0, 1,
                         NIL, NIL);
    
    PredefProc (stb, module, assert, "ASSERT", 1, 2);
    PredefProc (stb, module, len, "LEN", 1, 2);
    PredefProc (stb, module, size, "SIZE", 1, 1);
    PredefProc (stb, module, inc, "INC", 1, 2);
    PredefProc (stb, module, dec, "DEC", 1, 2);
    PredefProc (stb, module, ash, "ASH", 2, 2);
    PredefProc (stb, module, cap, "CAP", 1, 1);
    PredefProc (stb, module, long, "LONG", 1, 1);
    PredefProc (stb, module, short, "SHORT", 1, 1);
    PredefProc (stb, module, chr, "CHR", 1, 1);
    PredefProc (stb, module, entier, "ENTIER", 1, 1);
    PredefProc (stb, module, odd, "ODD", 1, 1);
    PredefProc (stb, module, ord, "ORD", 1, 1);
    PredefProc (stb, module, max, "MAX", 1, 1);
    PredefProc (stb, module, min, "MIN", 1, 1);
    PredefProc (stb, module, new, "NEW", 1, Sym.unlimitedArgs);
    PredefProc (stb, module, copy, "COPY", 2, 2);
    
    stb. Finalize (module);
    RETURN module
  END CreatePredef;

PROCEDURE CreateSYSTEM* (stb: Builder.Builder): Sym.Module;
(**Creates the symbol table of the pseudo module @code{SYSTEM}.  *)
  VAR
    module: Sym.Module;
    ptype: Sym.PredefType;
  BEGIN
    module := stb. NewModule (GetName ("SYSTEM"), NIL, Sym.mcInternal,
                              Sym.callConvInternal, NIL);

    TypeAlias (stb, module, "ADDRESS", Sym.predefIdToType[longint]);
    ptype := PredefType (stb, module, byte, "BYTE", 1, 1, NIL, NIL);
    ptype := PredefType (stb, module, ptr, "PTR", 4, 4, NIL, NIL);

    PredefProc (stb, module, adr, "ADR", 1, 1);
    
    stb. Finalize (module);
    RETURN module
  END CreateSYSTEM;

PROCEDURE GetType* (id: Sym.PredefId): Sym.PredefType;
  BEGIN
    RETURN Sym.predefIdToType[id]
  END GetType;

PROCEDURE GetMin* (type: Sym.Type): Language.Value;
  BEGIN
    WITH type: Sym.PredefType DO
      RETURN minConst[type. id];
    ELSE
      RETURN NIL;
    END;
  END GetMin;

PROCEDURE GetMax* (type: Sym.Type): Language.Value;
  BEGIN
    WITH type: Sym.PredefType DO
      RETURN maxConst[type. id];
    ELSE
      RETURN NIL;
    END;
  END GetMax;

PROCEDURE SmallestIntType* (value: Integer.Value): Sym.Type;
(**Return the smallest integer type that can represent @oparam{value}. *)
  VAR
    i: INTEGER;
  BEGIN
    FOR i := shortint TO real-1 DO
      IF (value.Compare(minConst[i](Integer.Value)) >= 0) &
         (value.Compare(maxConst[i](Integer.Value)) <= 0) THEN
        RETURN GetType(i);
      END;
    END;
    RETURN NIL;
  END SmallestIntType;

BEGIN
  NEW (Sym.predefIdToType, lastId+1);
  FOR i := 0 TO lastId DO
    minConst[i] := NIL; maxConst[i] := NIL;
  END;
END OOC:SymbolTable:Predef.
