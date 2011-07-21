(* 	$Id: Predef.Mod,v 1.59 2004/06/06 20:33:44 mva Exp $	 *)
MODULE OOC:SymbolTable:Predef;
(*  Defines symbol table of pseudo module with predefined entities.
    Copyright (C) 2000-2004  Michael van Acken

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
  Strings, Object, Object:Boxed, Object:BigInt,
  OOC:Config:Autoconf, Sym := OOC:SymbolTable, OOC:SymbolTable:Builder;


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
     character value encoded as UCS-2.
     name?)  *)
  ucs4char* = 3;
  (**Predefined type @code{UCS4CHAR}.  An OOC extension.  A 4 byte Unicode
     character value encoded as UCS-4.  *)
  shortint* = 4;
  (**Integer value, two's complement encoding, stored in one byte.  *)
  integer* = 5;
  (**Integer value, two's complement encoding, stored in two bytes.  *)
  longint* = Autoconf.longint;
  (**Integer value, two's complement encoding, stored in four bytes.  *)
  hugeint* = Autoconf.hugeint;
  (**Integer value, two's complement encoding, stored in eight bytes.  *)
  real* = 8;
  (**Floating point value, IEEE-754 single precision, stored in four bytes.  *)
  longreal* = 9;
  (**Floating point value, IEEE-754 single precision, stored in eight bytes. *)
  set* = 10;
  (**A set of integer values in the range @samp{0 <= x < 32}.  Stored in
     four bytes.  *)
  
  address* = Autoconf.address;  (* alias to appropriate integer type *)
  byte* = 11;
  ptr* = 12;

  stringChar* = 13;
  (**A string value based on the predefined type @code{CHAR}.  This is a
     sequence of arbitrary @oconst{char} constants.  In particular, the string
     may contain the character code @code{0X}.  *)
  stringLongChar* = 14;
  (**Like @oconst{stringChar}, but based on the type @code{LONGCHAR}.  *)
  stringUCS4Char* = 15;
  (**Like @oconst{stringChar}, but based on the type @code{UCS4CHAR}.  *)
  nil* = 16;
  (**The type of the constant @code{NIL}.  *)
  void* = 17;
  (**The return type of procedures, indicating that no result is produced.  *)

  outOfRangeInt* = 18;
  (**This type is assigned to integer values that are too large to be stored in
     the largest available integer type.  *)
  
  lastId* = outOfRangeInt;
  (**Id of last predefined type.  Typically used in client modules
     to declare variables @code{ARRAY @oconst{lastId}+1 OF @dots{}}.  *)
  
  lengthType* = longint;
  (**Alias for the integer type used to represent the length of an array.
     This is also the result type of the predefined function @code{LEN}.
     Normally, this is the same as @oconst{longint}.  Use this symbolic
     name when producing values the are array indices or lengths.  *)

CONST
  minChar* = 0X;     maxChar* = 0FFX;
  minLongChar* = 0X; maxLongChar* = 0FFFFX;
  minUCS4Char* = 0X; maxUCS4Char* = 10FFFFX;
  
VAR
  minConst, maxConst: ARRAY lastId+1 OF Boxed.Object;
  (**Array with the @code{MIN} and @code{MAX} values of the predefined
     types.  An entry @code{NIL} means that the operation is not
     applicable to the type.  *)

CONST
  (* predefined procedures and functions *)
  assert* = 0;                           (* ASSERT *)
  halt* = 1;                             (* HALT *)
  len* = 2;                              (* LEN *)
  size* = 3;                             (* SIZE *)
  inc* = 4;                              (* INC *)
  dec* = 5;                              (* DEC *)
  incl* = 6;                             (* INCL *)
  excl* = 7;                             (* EXCL *)
  abs* = 8;                              (* ABS *)
  ash* = 9;                              (* ASH *)
  cap* = 10;                             (* CAP *)
  long* = 11;                            (* LONG *)
  short* = 12;                           (* SHORT *)
  chr* = 13;                             (* CHR *)
  longchr* = 14;                         (* LONGCHR *)
  ucs4chr* = 15;                         (* UCS4CHR *)
  entier* = 16;                          (* ENTIER *)
  odd* = 17;                             (* ODD *)
  ord* = 18;                             (* ORD *)
  max* = 19;                             (* MAX *)
  min* = 20;                             (* MIN *)
  new* = 21;                             (* NEW *)
  copy* = 22;                            (* COPY *)
  raise* = 23;                           (* RAISE *)
  
  adr* = 24;                             (* SYSTEM.ADR *)
  lsh* = 25;                             (* SYSTEM.LSH *)
  move* = 26;                            (* SYSTEM.MOVE *)
  systemNew* = 27;                       (* SYSTEM.NEW *)
  rot* = 28;                             (* SYSTEM.ROT *)
  val* = 29;                             (* SYSTEM.VAL *)

CONST
  minExitCode* = 0;
  maxExitCode* = 127+1;
  defaultAssertCode* = 127;
  initMethod* = "INIT";
  
VAR
  nameStringModule-, nameStringType-: Sym.Name;
  
  
PROCEDURE GetName*(name: ARRAY OF CHAR): Sym.Name;
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
                      minValue, maxValue: Boxed.Object): Sym.PredefType;
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
                                 Sym.nameExported, NIL, ptype, FALSE)
    END;
    RETURN ptype
  END PredefType;

PROCEDURE PredefVar(stb: Builder.Builder; module: Sym.Module;
                    name: ARRAY OF CHAR; type: Sym.Type): Sym.VarDecl;
  BEGIN
    (* for starters, there is only one predefined, but usually invisible,
       variable: EXCEPTION *)
    RETURN stb.NewVarDecl(module, GetName(name), 0, Sym.nameNotExported, NIL,
                          FALSE, FALSE, FALSE, type);
  END PredefVar;

PROCEDURE TypeAlias (stb: Builder.Builder;
                     module: Sym.Module;
                     name: ARRAY OF CHAR; baseType: Sym.PredefType);
  VAR
    tdecl: Sym.TypeDecl;
  BEGIN
    tdecl := stb. NewTypeDecl (module, GetName (name), 0,
                               Sym.nameExported, NIL, baseType, FALSE);
  END TypeAlias;

PROCEDURE PredefProc (stb: Builder.Builder; module: Sym.Module;
                      id: Sym.PredefId; name: ARRAY OF CHAR;
                      minArgs, maxArgs: INTEGER);
  VAR
    pproc: Sym.PredefProc;
  BEGIN
    pproc := stb. NewPredefProc (module, GetName (name), id, minArgs, maxArgs);
  END PredefProc;

PROCEDURE CreatePredef* (stb: Builder.Builder;
                         VAR exception: Sym.VarDecl): Sym.Module;
(**Creates the symbol table of the pseudo module that contains the predefined
   entities of the language, that can be used directly in a module without
   prefixing them with a module name.  It declares types like @samp{CHAR},
   @samp{BOOLEAN}, or @samp{INTEGER}, as well as predefined procedures and
   functions, like @samp{COPY} or @samp{LEN}.  *)
  VAR
    module: Sym.Module;
    ptype: Sym.PredefType;
    redir: Sym.Redirect;
    
  PROCEDURE PredefConst (name: ARRAY OF CHAR; value: Boxed.Object;
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
    PredefConst ("FALSE", Boxed.false, ptype);
    PredefConst ("TRUE", Boxed.true, ptype);
    
    ptype := PredefType (stb, module, char, "CHAR", 1, 1,
                         Boxed.NewString(Object.NewLatin1Char(minChar)),
                         Boxed.NewString(Object.NewLatin1Char(maxChar)));
    ptype := PredefType (stb, module, longchar, "LONGCHAR", 2, 2,
                         Boxed.NewString(Object.NewUTF16Char(minLongChar)),
                         Boxed.NewString(Object.NewUTF16Char(maxLongChar)));
    ptype := PredefType (stb, module, ucs4char, "UCS4CHAR", 4, 4,
                         Boxed.NewString(Object.NewUCS4Char(minUCS4Char)),
                         Boxed.NewString(Object.NewUCS4Char(maxUCS4Char)));
    ptype := PredefType (stb, module, shortint, "SHORTINT", 1, 1,
                         BigInt.NewInt(MIN (SHORTINT)),
                         BigInt.NewInt(MAX (SHORTINT)));
    ptype := PredefType (stb, module, integer, "INTEGER", 2, 2,
                         BigInt.NewInt(MIN (INTEGER)),
                         BigInt.NewInt(MAX (INTEGER)));
    ptype := PredefType (stb, module, longint, "LONGINT", 4, 4,
                         BigInt.NewInt(MIN (LONGINT)),
                         BigInt.NewInt(MAX (LONGINT)));
    IF (Autoconf.bitsTargetInteger > 32) THEN
      ptype := PredefType (stb, module, hugeint, "HUGEINT", 8, 8,
                           BigInt.NewLatin1("-9223372036854775808", 10),
                           BigInt.NewLatin1("9223372036854775807", 10));
    END;
    ptype := PredefType (stb, module, real, "REAL", 4, 4,
                         Boxed.NewLongReal(MIN (REAL)),
                         Boxed.NewLongReal(MAX (REAL)));
    ptype := PredefType (stb, module, longreal, "LONGREAL", 8, 8,
                         Boxed.NewLongReal(MIN (LONGREAL)),
                         Boxed.NewLongReal(MAX (LONGREAL)));
    ptype := PredefType (stb, module, set, "SET", 4, 4,
                         BigInt.NewInt(MIN (SET)),
                         BigInt.NewInt(MAX (SET)));
    
    ptype := PredefType (stb, module, stringChar, "", Sym.dynamicSize, 1,
                         NIL, NIL);
    ptype := PredefType (stb, module, stringLongChar, "", Sym.dynamicSize, 2,
                         NIL, NIL);
    ptype := PredefType (stb, module, stringUCS4Char, "", Sym.dynamicSize, 4,
                         NIL, NIL);
    ptype := PredefType (stb, module, nil, "", 4, 4,
                         NIL, NIL);
    ptype := PredefType (stb, module, void, "", 0, 1,
                         NIL, NIL);
    ptype := PredefType (stb, module, outOfRangeInt, "", 0, 1,
                         NIL, NIL);

    exception := PredefVar(stb, module, "EXCEPTION", Sym.predefIdToType[nil]);
    
    redir := stb. NewRedirect(module, GetName("STRING"),
                              nameStringModule, nameStringType);
    
    PredefProc (stb, module, assert, "ASSERT", 1, 2);
    PredefProc (stb, module, halt, "HALT", 1, 1);
    PredefProc (stb, module, len, "LEN", 1, 2);
    PredefProc (stb, module, size, "SIZE", 1, 1);
    PredefProc (stb, module, inc, "INC", 1, 2);
    PredefProc (stb, module, dec, "DEC", 1, 2);
    PredefProc (stb, module, incl, "INCL", 2, 2);
    PredefProc (stb, module, excl, "EXCL", 2, 2);
    PredefProc (stb, module, abs, "ABS", 1, 1);
    PredefProc (stb, module, ash, "ASH", 2, 2);
    PredefProc (stb, module, cap, "CAP", 1, 1);
    PredefProc (stb, module, long, "LONG", 1, 1);
    PredefProc (stb, module, short, "SHORT", 1, 1);
    PredefProc (stb, module, chr, "CHR", 1, 1);
    PredefProc (stb, module, longchr, "LONGCHR", 1, 1);
    PredefProc (stb, module, ucs4chr, "UCS4CHR", 1, 1);
    PredefProc (stb, module, entier, "ENTIER", 1, 1);
    PredefProc (stb, module, odd, "ODD", 1, 1);
    PredefProc (stb, module, ord, "ORD", 1, 1);
    PredefProc (stb, module, max, "MAX", 1, 1);
    PredefProc (stb, module, min, "MIN", 1, 1);
    PredefProc (stb, module, new, "NEW", 1, Sym.unlimitedArgs);
    PredefProc (stb, module, copy, "COPY", 2, 2);
    PredefProc (stb, module, raise, "RAISE", 1, 1);
    
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

    TypeAlias (stb, module, "ADDRESS", Sym.predefIdToType[address]);
    ptype := PredefType (stb, module, byte, "BYTE", 1, 1, NIL, NIL);
    ptype := PredefType (stb, module, ptr, "PTR",
                         Sym.predefIdToType[address].size,
                         Sym.predefIdToType[address].align,
                         NIL, NIL);

    PredefProc (stb, module, adr, "ADR", 1, 1);
    PredefProc (stb, module, lsh, "LSH", 2, 2);
    PredefProc (stb, module, move, "MOVE", 3, 3);
    PredefProc (stb, module, systemNew, "NEW", 2, 2);
    PredefProc (stb, module, rot, "ROT", 2, 2);
    PredefProc (stb, module, val, "VAL", 2, 2);
    
    stb. Finalize (module);
    RETURN module
  END CreateSYSTEM;

PROCEDURE GetType* (id: Sym.PredefId): Sym.PredefType;
  BEGIN
    RETURN Sym.predefIdToType[id]
  END GetType;

PROCEDURE GetMin* (type: Sym.Type): Boxed.Object;
  BEGIN
    WITH type: Sym.PredefType DO
      RETURN minConst[type. id];
    ELSE
      RETURN NIL;
    END;
  END GetMin;

PROCEDURE GetMax* (type: Sym.Type): Boxed.Object;
  BEGIN
    WITH type: Sym.PredefType DO
      RETURN maxConst[type. id];
    ELSE
      RETURN NIL;
    END;
  END GetMax;

PROCEDURE SmallestIntType* (value: BigInt.BigInt): Sym.Type;
(**Return the smallest integer type that can represent @oparam{value}. *)
  VAR
    i: INTEGER;
  BEGIN
    FOR i := shortint TO real-1 DO
      IF (value.Cmp(minConst[i]) >= 0) & (value.Cmp(maxConst[i]) <= 0) THEN
        RETURN GetType(i);
      END;
    END;
    RETURN GetType(outOfRangeInt);
  END SmallestIntType;

PROCEDURE IsStaticMethod*(name: ARRAY OF CHAR): BOOLEAN;
(**Return @code{TRUE} if static binding is used for the method @oparam{name}.
   Such a method must be marked as exported.  *)
  BEGIN
    RETURN (name = initMethod);
  END IsStaticMethod;

PROCEDURE ImplementsFinalize*(t: Sym.Record): BOOLEAN;
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

PROCEDURE Init;
  VAR
    i: LONGINT;
  BEGIN
    NEW (Sym.predefIdToType, lastId+1);
    FOR i := 0 TO lastId DO
      minConst[i] := NIL; maxConst[i] := NIL;
    END;
    
    nameStringModule := GetName(Builder.prefixAutoImport+
                                Builder.stringModule);
    nameStringType := GetName("String");
  END Init;

BEGIN
  Init;
END OOC:SymbolTable:Predef.
