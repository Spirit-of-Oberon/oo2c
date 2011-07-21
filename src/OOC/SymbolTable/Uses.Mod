(* 	$Id: Uses.Mod,v 1.8 2003/05/19 23:27:03 mva Exp $	 *)
MODULE OOC:SymbolTable:Uses;
(*  List uses of a given declaration.
    Copyright (C) 2003  Michael van Acken

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
  Object, Err, Strings, OOC:Error, Sym := OOC:SymbolTable;
  
TYPE
  Uses* = POINTER TO UsesDesc;
  Selector = POINTER TO ARRAY OF Sym.Name;
  StoredUses = POINTER TO ARRAY OF RECORD
    ident: Sym.Name;
    decl: Sym.Declaration;
  END;
  UsesDesc = RECORD
    selector: Selector;  (* if NIL, then skip any usage checks *)
    errList: Error.List;
    pattern: Sym.Declaration;
    
    storeUses: BOOLEAN;
    storedUsesCount: LONGINT;
    storedUses: StoredUses;
  END;

CONST
  (*noMatch = 0;*)
  useOfObject = 1;
  definition = 2;
  deprecated = 3;
  
TYPE
  ErrorContext = POINTER TO ErrorContextDesc;
  ErrorContextDesc = RECORD  (* stateless *)
    (Error.ContextDesc)
  END;

VAR
  usesContext: ErrorContext;

PROCEDURE (context: ErrorContext) GetTemplate* (msg: Error.Msg; VAR templ: Error.LString);
  CONST
    prefix = "[uses] ";
  VAR
    t: ARRAY 128 OF Error.LChar;
  BEGIN
    CASE msg. code OF
    | useOfObject:
      t := prefix+"Use"
    | definition:
      t := prefix+"Definition"
    | deprecated:
      t := Error.warningPrefix+"Use of deprecated object"
    END;
    context. BaseTemplate (msg, t, templ)
  END GetTemplate;


PROCEDURE InitUses(u: Uses; selector: Selector);
  BEGIN
    u.selector := selector;
    u.errList := NIL;
    u.pattern := NIL;
    
    u.storeUses := FALSE;
    u.storedUsesCount := 0;
    NEW(u.storedUses, 8);
  END InitUses;

PROCEDURE New*(extIdent: STRING; VAR syntaxError: BOOLEAN): Uses;
(**If @oparam{extIdent} is the empty string, then no usage tracking of a
   particular declaration is done.  In this case, this module only implements
   warnings for using occurences of deprecated declarations.  *)
  VAR
    u: Uses;
    selector: Selector;
    str8: Object.String8;
    chars: Object.CharsLatin1;

  PROCEDURE GetName(str: ARRAY OF CHAR): Sym.Name;
    VAR
      name: Sym.Name;
      string: Sym.NameString;
    BEGIN
      NEW(string, Strings.Length(str)+1);
      COPY(str, string^);
      
      NEW(name);
      Sym.InitName(name, string, 0, 0, 0);
      RETURN name
    END GetName;
  
  PROCEDURE ParseIdent(str: ARRAY OF CHAR): Selector;
    VAR
      i, start: INTEGER;
      count: INTEGER;
      s: Selector;
      buffer: ARRAY 1024 OF CHAR;
    BEGIN
      count := 0;
      i := 0;
      WHILE (str[i] # 0X) DO
        CASE str[i] OF
        | "a".."z", "A".."Z", "0".."9", "_", ":":
          (* allowed character *)
        | ".":
          INC(count);
        ELSE
          RETURN NIL;
        END;
        INC(i);
      END;

      NEW(s, count+1);
      count := 0;
      i := 0;
      WHILE (str[i] # 0X) DO
        start := i;
        WHILE (str[i] # ".") & (str[i] # 0X) DO
          INC(i);
        END;
        IF (i = start) THEN
          RETURN NIL;  (* empty part *)
        ELSE
          Strings.Extract(str, start, i-start, buffer);
          s[count] := GetName(buffer);
        END;
        IF (str[i] = ".") THEN
          INC(i);
        END;
        INC(count);
      END;
      RETURN s;
    END ParseIdent;
  
  BEGIN
    IF (extIdent.length = 0) THEN
      selector := NIL;
      syntaxError := FALSE;
    ELSE
      str8 := extIdent.ToString8("?");
      chars := str8.CharsLatin1();
      selector := ParseIdent(chars^);
      syntaxError := (selector = NIL);
    END;
    
    NEW(u);
    InitUses(u, selector);
    RETURN u;
  END New;

PROCEDURE (u: Uses) TrackingDeclarations*(): BOOLEAN;
  BEGIN
    RETURN (u.selector # NIL);
  END TrackingDeclarations;

PROCEDURE (u: Uses) StartModule*(symTab: Sym.Module; errList: Error.List);
(**Signal that module @oparam{symTab} is about to be processed.  No attempt
   is made to resolve identifiers with respect to @oparam{symTab} until
   @oproc{Uses.RegisterSymTab} is called.  *)
  BEGIN
    u.errList := errList;
    IF u.TrackingDeclarations() THEN
      u.storeUses := (symTab.name.str^ = u.selector[0].str^);
    ELSE
      u.storeUses := FALSE;
    END;
  END StartModule;

PROCEDURE AddMsg(u: Uses; ident: Sym.Name; code: Error.Code);
  VAR
    e: Error.Msg;
  BEGIN
    e := Error.New(usesContext, code);
    e.SetIntAttrib("pos", ident.pos);
    e.SetIntAttrib("line", ident.line);
    e.SetIntAttrib("column", ident.column);
    u.errList.AppendWarning (e);
  END AddMsg;

PROCEDURE (u: Uses) Matches(decl: Sym.Declaration): BOOLEAN;
  VAR
    index: LONGINT;
    p: Sym.ProcDecl;
    record: Sym.Record;
  BEGIN
    IF (decl = u.pattern) THEN
      RETURN TRUE;
    ELSIF (u.pattern # NIL) THEN
      IF (decl IS Sym.Import) &
         (decl(Sym.Import).externalSymTab = u.pattern) THEN
        RETURN TRUE;
      ELSIF (decl IS Sym.ProcDecl) & (u.pattern IS Sym.ProcDecl) &
            (decl.name.str^ = u.pattern.name.str^) &
            decl(Sym.ProcDecl).IsTypeBound() &
            u.pattern(Sym.ProcDecl).IsTypeBound() &
            (decl(Sym.ProcDecl).tbProcIndex =
             u.pattern(Sym.ProcDecl).tbProcIndex) THEN
        (* two type-bound procedures with the same name and index; if the walk
           down from decl's base type encounters our pattern, then we have a
           match *)
        index := decl(Sym.ProcDecl).tbProcIndex;
        p := decl(Sym.ProcDecl);
        REPEAT
          record := decl(Sym.ProcDecl).Class();
          p := record.ns.GetSuperProcByIndex(index);
        UNTIL (p = NIL) OR (p = u.pattern);
        RETURN (p # NIL);
      ELSE
        RETURN FALSE;
      END;
    ELSE
      RETURN FALSE;
    END;
  END Matches;

PROCEDURE (u: Uses) RegisterSymTab*(symTab: Sym.Module);
(**Announce that the namespace information in @oparam{symTab} is complete and
   can be used for searched.  *)
  VAR
    i: LONGINT;
    
  PROCEDURE ResolveSelector(root: Sym.Module): Sym.Declaration;
    VAR
      item: Sym.Item;
      i: LONGINT;
      ns: Sym.Namespace;

    PROCEDURE Namespace(item: Sym.Item): Sym.Namespace;
      BEGIN
        WITH item: Sym.Module DO
          RETURN item.ns;
        | item: Sym.ProcDecl DO
          RETURN item.ns;
          
        | item: Sym.TypeDecl DO
          RETURN Namespace(item.type);
        | item: Sym.VarDecl DO
          RETURN Namespace(item.type);
        | item: Sym.FieldDecl DO
          RETURN Namespace(item.type);
        | item: Sym.Import DO
          RETURN Namespace(item.externalSymTab);
          
        | item: Sym.Record DO
          RETURN item.ns;
        | item: Sym.Pointer DO
          RETURN Namespace(item.baseType);
        | item: Sym.Array DO
          RETURN Namespace(item.elementType);
        ELSE
          RETURN NIL;
        END;
      END Namespace;
    
    BEGIN
      IF (root.name.str^ = u.selector[0].str^) THEN
        i := 1;
        item := root;
        WHILE (i # LEN(u.selector^)) DO
          ns := Namespace(item);
          IF (ns = NIL) THEN
            item := NIL;
          ELSE
            item := ns.Identify(root, u.selector[i], TRUE);
          END;
          
          IF (item = NIL) THEN
            IF (root.name.pos >= 0) THEN
              (* we are currently parsing this module *)
              Err.String("Error: Cannot resolve member `");
              Err.String(u.selector[i].str^);
              Err.String("' of --uses");
              Err.Ln;
              HALT(1);
            ELSE
              (* imported module: fail silently, there cannot be any uses *)
              RETURN NIL;
            END;
          ELSE
            INC(i);
          END;
        END;
        RETURN item(Sym.Declaration);
      ELSE
        RETURN NIL;
      END;
    END ResolveSelector;
  
  PROCEDURE Resolve(): Sym.Declaration;
    VAR
      decl: Sym.Declaration;
      item: Sym.Item;
    BEGIN
      decl := ResolveSelector(symTab);
      IF (decl = NIL) THEN
        item := symTab.nestedItems;
        WHILE (decl = NIL) & (item # NIL) DO
          WITH item: Sym.Import DO
            decl := ResolveSelector(item.externalSymTab);
          ELSE
            (* ignore *)
          END;
          item := item.nextNested;
        END;
      END;
      RETURN decl;
    END Resolve;
  
  BEGIN
    IF u.TrackingDeclarations() THEN
      u.pattern := Resolve();
      IF (u.pattern # NIL) & (u.pattern.name.pos >= 0) THEN
        AddMsg(u, u.pattern.name, definition);
      END;
      
      FOR i := 0 TO u.storedUsesCount-1 DO
        IF u.Matches(u.storedUses[i].decl) THEN
          AddMsg(u, u.storedUses[i].ident, useOfObject);
        END;
        u.storedUses[i].ident := NIL;
        u.storedUses[i].decl := NIL;
      END;
      u.storedUsesCount := 0;
      u.storeUses := FALSE;
    END;
  END RegisterSymTab;

PROCEDURE Mark*(decl: Sym.Declaration; uses: Uses; ident: Sym.Name);
  VAR
    new: StoredUses;
    i: LONGINT;

  PROCEDURE Deprecated(decl: Sym.Declaration): BOOLEAN;
    BEGIN
      WITH decl: Sym.Import DO
        RETURN decl.externalSymTab.deprecated;
      ELSE
        RETURN decl.deprecated;
      END;
    END Deprecated;
  
  BEGIN
    IF (decl # NIL) THEN
      decl.IncrUsageCounter();

      IF (uses # NIL) & (ident.pos > 0) THEN
        IF Deprecated(decl) THEN
          AddMsg(uses, ident, deprecated);
        END;

        IF (uses # NIL) & uses.TrackingDeclarations() THEN
          IF uses.storeUses THEN
            IF (uses.storedUsesCount = LEN(uses.storedUses^)) THEN
              NEW(new, uses.storedUsesCount*2);
              FOR i := 0 TO uses.storedUsesCount-1 DO
                new[i] := uses.storedUses[i];
              END;
              uses.storedUses := new;
            END;
            uses.storedUses[uses.storedUsesCount].ident := ident;
            uses.storedUses[uses.storedUsesCount].decl := decl;
            INC(uses.storedUsesCount);
          ELSIF uses.Matches(decl) THEN
            AddMsg(uses, ident, useOfObject);
          END;
        END;
      END;
    END;
  END Mark;

BEGIN
  NEW (usesContext);
  Error.InitContext (usesContext, "OOC:SymbolTable:Uses");
END OOC:SymbolTable:Uses.
