MODULE OOC:SymbolTable:Uses;

IMPORT
  Err, Strings, OOC:Error, Sym := OOC:SymbolTable;
  
TYPE
  Uses* = POINTER TO UsesDesc;
  Selector = POINTER TO ARRAY OF Sym.Name;
  StoredUses = POINTER TO ARRAY OF RECORD
    ident: Sym.Name;
    decl: Sym.Declaration;
  END;
  UsesDesc = RECORD
    selector: Selector;
    errList: Error.List;
    pattern: Sym.Declaration;
    
    storeUses: BOOLEAN;
    storedUsesCount: LONGINT;
    storedUses: StoredUses;
  END;

CONST
  useOfName = 1;
  
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
    | useOfName:
      t := prefix+"Use"
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

PROCEDURE New*(extIdent: ARRAY OF CHAR): Uses;
  VAR
    u: Uses;
    selector: Selector;

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
    selector := ParseIdent(extIdent);
    IF (selector = NIL) THEN
      RETURN NIL;
    ELSE
      NEW(u);
      InitUses(u, selector);
      RETURN u;
    END;
  END New;

PROCEDURE (u: Uses) StartModule*(symTab: Sym.Module; errList: Error.List);
(**Signal that module @oparam{symTab} is about to be processed.  No attempt
   is made to resolve identifiers with respect to @oparam{symTab} until
   @oproc{Uses.RegisterSymTab} is called.  *)
  BEGIN
    u.errList := errList;
    u.storeUses := (symTab.name.str^ = u.selector[0].str^);
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
(* FIXME... for procedure names, match redefinitions as well *)
  BEGIN
    RETURN (decl = u.pattern);
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
    u.pattern := Resolve();
    
    FOR i := 0 TO u.storedUsesCount-1 DO
      IF u.Matches(u.storedUses[i].decl) THEN
        AddMsg(u, u.storedUses[i].ident, useOfName);
      END;
      u.storedUses[i].ident := NIL;
      u.storedUses[i].decl := NIL;
    END;
    u.storedUsesCount := 0;
    u.storeUses := FALSE;
  END RegisterSymTab;

PROCEDURE Mark*(decl: Sym.Declaration; uses: Uses; ident: Sym.Name);
  VAR
    new: StoredUses;
    i: LONGINT;
  BEGIN
    IF (decl # NIL) THEN
      decl.IncrUsageCounter();

      IF (uses # NIL) & (ident.pos > 0) THEN
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
          AddMsg(uses, ident, useOfName);
        END;
      END;
    END;
  END Mark;

BEGIN
  NEW (usesContext);
  Error.InitContext (usesContext, "OOC:SymbolTable:Uses");
END OOC:SymbolTable:Uses.
