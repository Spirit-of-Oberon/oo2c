(* 	$Id: Parser.Mod,v 1.28 2005/10/07 08:35:42 mva Exp $	 *)
MODULE OOC:Parser;
(*  Parses an Oberon-2 module and creates an abstract syntax tree.
    Copyright (C) 1999-2005  Michael van Acken

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
  Msg, Strings,
  OOC:Error, OOC:Scanner:Symbol, OOC:Scanner:SymList, OOC:AST,
  OOC:Doc, OOC:Doc:Input:Texinfo;


CONST
  (**These flags can be set for the parameter @oparam{Module.parseOptions} of
     procedure @oproc{Module}:  *)
  enableFlags* = 0;
  (**If set, then the declarations and type definitions can include compiler
     specific flags enclosed in "[..]".  Otherwise, an error is signalled if
     such constructs appear in the source code.  *)
  enableMultiPartIdent* = 1;
  (**If set, then the module's name and the names appearing in the import
     list can be multi-part identifiers.  Otherwise, module names are 
     restricted to plain identifiers.  *)
  enableRestParam* = 2;
  (**If this is set, the parser will accept the special parameter "..." as the
     last entry of a formal parameter list.  Otherwise, a syntax error is
     signalled if such a parameter is used.  *)
  enableDocComment* = 3;
  (**If set, call @oproc{AST.Node.AttachDocString} on the name 
     (@oproc{AST.Builder.IdentDef}, or @oproc{AST.Builder.ModuleIdent})
     of the preceding declaration for any documentation comment
     encountered in the symbol list.  *)
  enableTypeParams* = 4;
  (**If set, the a type declaration may include a list of type parameters.  *)
  onlyParseImport* = 5;
  (**If set, stop parsing right after the import list.  Otherwise, parse
     the whole module.  *)
  enableAll* = {MIN(SET)..MAX(SET)}-{onlyParseImport};
  (**Enables all the non-standard syntactic contructions listed above.  *)


CONST
  trailingJunk = 1;
  expectKeyword = 2;
  expectSymbol = 3;
  expectIdent = 4;
  nameMismatch = 5;
  expectDataType = 6;
  unexpectedSymbol = 7;
  noFlags = 8;
  noRestParameter = 9;
  noMultiPartIdent = 10;
  importingThisModule = 11;
  exportMarkInProc = 12;
  noReadOnlyExport = 13;
  tbProcInsideProc = 14;
  illegalFactor = 15;
  invalidFlag = 16;
  expectExternalKW = 17;
  (*expectLinkSection = 18;  unused *)
  fileNameMismatch = 19;
  
TYPE
  ErrorContext = POINTER TO ErrorContextDesc;
  ErrorContextDesc = RECORD  (* stateless *)
    (Error.ContextDesc)
  END;

VAR
  parserContext: ErrorContext;


PROCEDURE (context: ErrorContext) GetTemplate* (msg: Error.Msg; VAR templ: Error.LString);
  VAR
    t: ARRAY 128 OF Error.LChar;
  BEGIN
    CASE msg. code OF
    | trailingJunk:
      t := "Junk after end of module"
    | expectKeyword:
      t := "Expected keyword `${sym_name}'"
    | expectSymbol:
      t := "Expected symbol `${sym_name}'"
    | expectIdent:
      t := "Expected identifier"
    | nameMismatch:
      t := "Expected name `${name}'"
    | expectDataType:
      t := "Expected data type"
    | unexpectedSymbol:
      t := "Unexpected symbol"
    | noFlags:
      t := "System specific flags are not allowed in this module"
    | noMultiPartIdent:
      t := "Multipart identifiers not supported for this module"
    | noRestParameter:
      t := "Cannot use rest parameter in this module"
    | importingThisModule:
      t := "A module cannot import itself"
    | exportMarkInProc:
      t := "Export only possible on top level"
    | noReadOnlyExport:
      t := "This object can only be exported with `*'"
    | tbProcInsideProc:
      t := "Type-bound procedure must be declared on top level"
    | illegalFactor:
      t := "Factor starts with illegal symbol"
    | invalidFlag:
      t := "Invalid flag"
    | expectExternalKW:
      t := "Expected keyword `INTERFACE' or `FOREIGN'"
    | fileNameMismatch:
      t := "Module name does not match access path `${name}'"
    END;
    context. BaseTemplate (msg, t, templ)
  END GetTemplate;


PROCEDURE Module* (sym: SymList.Symbol; ast: AST.Builder;
                   errList: Error.List; parseOptions: SET): AST.Node;
(**This procedure implements a recursive descent parser for a slightly modified
   Oberon-2 syntax.  It takes a sequences of tokens in @oparam{sym} and creates
   an abstract syntax tree by calling the builder procedures from @oparam{ast}.
   Syntax errors are reported by appending messages to @oparam{errList}.  The
   result of this procedure is the root of the abstract syntax tree.  It
   describes the whole module and is created by calling
   @oproc{AST.Builder.Module}.
   
   The accepted syntax is less restrictive than the syntax given in the 
   Oberon-2 language report, because this parser performs its task without
   any hints from the symbol table.  In particular, it cannot identify module
   names, which means it cannot recognize the @samp{Qualident} rule without
   fail, and it cannot distinguish between a function call and a type-guard.
   For these reasons, the rule for @samp{Designator} does start with an
   @samp{ident} instead of a @samp{Qualident}, and it also includes the
   function call syntax.  The latter is normally part of @samp{Factor}.  Later
   passes of the compiler must ensure that designators comply to the original
   Oberon-2 syntax.
   
   Optional syntactic extensions are enabled through flags of
   @oparam{parseOptions}.  Currently, the list includes system flags, 
   multi-part identifiers, and C style rest parameters.  See the list under
   @oconst{enableAll} for more details.  *)
  VAR
    prevSym, nameSym: SymList.Symbol;
    lastError: Error.Msg;
    body: AST.Body;
    module: AST.Terminal;
    moduleFlags: AST.Flags;
    name, scolon, import, period, eof: AST.Node;
    headName: AST.Name;
    
    lastIdentDef: AST.Node;
    (* node with name of last declaration; if a doc comment is found, the
       comment is attached to this node *)
    
  PROCEDURE Err (code: Error.Code; sym: SymList.Symbol);
  (* Creates an error message, using the starting position of the symbol 
     @oparam{sym} for the error position.  The newly created message is 
     appended to @oparam{errList}, and a reference to the message is
     stored in @ovar{lastError}.  *)
    BEGIN
      lastError := Error.New (parserContext, code);
      lastError. SetIntAttrib ("pos", sym. pos);
      lastError. SetIntAttrib ("line", sym. line);
      lastError. SetIntAttrib ("column", sym. column);
      errList. Append (lastError)
    END Err;
  
  PROCEDURE ErrEndPos (code: Error.Code; sym: SymList.Symbol);
  (* Creates an error message, using the @emph{ending} position of the symbol 
     @oparam{sym} for the error position.  The newly created message is 
     appended to @oparam{errList}, and a reference to the message is
     stored in @ovar{lastError}.  *)
    BEGIN
      lastError := Error.New (parserContext, code);
      lastError. SetIntAttrib ("pos", sym. pos+sym. len);
      lastError. SetIntAttrib ("line", sym. line);
      lastError. SetIntAttrib ("column", sym. column+sym. len);
      errList. Append (lastError)
    END ErrEndPos;
  
  PROCEDURE ErrStringAttrib (name: ARRAY OF CHAR; VAR str: ARRAY OF CHAR);
  (* Adds a string attribute @oparam{name} with the value @oparam{str} to
     the last error message generated with @oproc{Err} or @oproc{ErrEndPos}. *)
    BEGIN
      lastError. SetStringAttrib (name, Msg.GetStringPtr (str))
    END ErrStringAttrib;
  
  
  PROCEDURE NextSym;
    VAR
      document: Doc.Document;
    BEGIN
      prevSym := sym; sym := sym. next;
      IF (sym # NIL) & (sym. id = Symbol.docComment) THEN
        REPEAT
          IF (sym. id = Symbol.docComment) & (lastIdentDef # NIL) &
             (enableDocComment IN parseOptions) THEN
            document := Texinfo.Parse (sym, TRUE, errList);
            IF (document # NIL) THEN
              lastIdentDef. AttachDocString (document)
            END
          END;
          sym := sym. next
        UNTIL (sym. id # Symbol.docComment)
      END
    END NextSym;
  
  PROCEDURE CheckSym (symId: Symbol.Id): AST.Terminal;
  (**Compares with current symbol @oparam{sym} with the required symbol (or
     symbol class) in @oparam{symId}.  If there is a mismatch, an error message
     is emitted and the function returns @code{NIL}.  Otherwise, it creates an
     instance from the current symbol using @oproc{AST.Builder.Terminal}, moves
     the current symbol forward by one step, and returns the newly created
     node.  *)
    VAR
      node: AST.Terminal;
    BEGIN
      IF (sym. id # symId) THEN
        IF Symbol.IsKeyword (symId) THEN
          Err (expectKeyword, sym);
          lastError. SetStringAttrib ("sym_name", 
                               Msg.GetStringPtr (Symbol.representation[symId]))
        ELSIF (symId = Symbol. ident) THEN
          Err (expectIdent, sym)
        ELSIF (symId = Symbol.endOfFile) THEN
          Err (trailingJunk, sym)
        ELSE
          CASE symId OF
          | Symbol.semicolon, Symbol.colon, Symbol.comma, Symbol.period,
            Symbol.lParen, Symbol.lBrak, Symbol.lBrace, Symbol.rParen,
            Symbol.rBrak, Symbol.rBrace:
            IF (prevSym # NIL) THEN
              ErrEndPos (expectSymbol, prevSym)
            ELSE
              Err (expectSymbol, sym)
            END
          ELSE
            Err (expectSymbol, sym)
          END;
          lastError. SetStringAttrib ("sym_name", 
                               Msg.GetStringPtr (Symbol.representation[symId]))
        END;
        IF (symId = Symbol.becomes) & 
             ((sym. id = Symbol.eql) OR (sym. id = Symbol.colon)) OR
           (symId = Symbol.eql) & (sym. id = Symbol.becomes) OR 
           ((Symbol.of <= symId) & (symId <= Symbol.by) OR
            (Symbol.end <= symId) & (symId <= Symbol.module)) & 
              (sym. id = Symbol.ident) THEN
          NextSym
        END;
        RETURN ast. Terminal (sym);
      END;
      node := ast. Terminal (sym);
      NextSym;
      RETURN node
    END CheckSym;

  PROCEDURE MultiPartIdent (VAR name: AST.Name): AST.Node;
  (* Reads multi-part identifier, if these are enabled, and a simple identifer
     otherwise.  In any case, the result is an instance of
     @otype{AST.NodeList}, with the array elements with an even index being
     the identifiers, and the odd elements being colons.  Both kinds of nodes
     are instances of @otype{AST.Terminal}.  *)
    VAR
      nl: AST.NodeList;
    
    PROCEDURE Append (node: AST.Node);
      VAR
        new: AST.Name;
      BEGIN
        NEW (new, Strings.Length (name^)+sym. len+1);
        COPY (name^, new^);
        Strings.Append (sym. str^, new^);
        nl. Append (node)
      END Append;
    
    PROCEDURE AppendString (prefix, suffix: AST.Name): AST.Name;
      VAR
        s: AST.Name;
        len: LONGINT;
      BEGIN
        len := Strings.Length (prefix^)+Strings.Length (suffix^)+2;
        NEW (s, len);
        COPY (prefix^, s^);
        Strings.Append (":", s^);
        Strings.Append (suffix^, s^);
        RETURN s
      END AppendString;
    
    BEGIN
      (*S: mp_ident = ident {":" ident}.  *)
      nl := ast. NewNodeList();
      name := sym. str;
      Append (CheckSym (Symbol.ident));
      IF (sym.id = Symbol.colon) & ~(enableMultiPartIdent IN parseOptions) THEN
        Err (noMultiPartIdent, sym)
      END;
      WHILE (sym. id = Symbol.colon) DO
        Append (CheckSym (Symbol.colon));
        name := AppendString (name, sym. str);
        Append (CheckSym (Symbol.ident))
      END;
      RETURN ast. ModuleIdent (nl)
    END MultiPartIdent;
  
  PROCEDURE Flags (context: SHORTINT): AST.Flags;
  (* Reads a list of system flags.  *)
    VAR
      counter: LONGINT;
      lBrak, rBrak: AST.Node;
      flagList: AST.NodeList;
    
    PROCEDURE Ident (name: ARRAY OF CHAR): BOOLEAN;
      BEGIN
        RETURN (sym. id = Symbol.ident) & (sym. str^ = name)
      END Ident;
    
    PROCEDURE Flag(): AST.Node;
      VAR
        procId, eql, number: AST.Node;
      BEGIN
        (* S: Flag = "PROC_ID" "=" number10 | string | ident. *)
        IF (context = AST.flagsProcedure) & Ident ("PROC_ID") THEN
          (* procedure declaration: non-standard procedure *)
          procId := CheckSym (Symbol.ident);
          eql := CheckSym (Symbol.eql);
          number := CheckSym (Symbol.number10);
          RETURN ast. ProcIdFlag (procId, eql, number)
        ELSIF ((context = AST.flagsProcType) OR
               (context = AST.flagsProcedure) OR
               (context = AST.flagsVariable)) & 
              ((sym. id = Symbol.stringSingle) OR
               (sym. id = Symbol.stringDouble)) THEN
          (* procedure type: string defines the calling convention, or
             procedure or variable: string defines linkage name *)
          RETURN CheckSym (sym. id)
        ELSIF (sym. id = Symbol.ident) THEN
          (* default: a flag is an identifier *)
          RETURN CheckSym (Symbol.ident)
        ELSE
          Err (invalidFlag, sym);
          RETURN NIL
        END
      END Flag;
    
    PROCEDURE ModuleFlags(): AST.Node;
      VAR
        external, callConv, semicolon, link, end: AST.Node;
        moduleFlags, linkSections: AST.NodeList;
        
      PROCEDURE CheckString (): AST.Node;
        BEGIN
          IF (sym. id = Symbol.stringSingle) THEN
            RETURN CheckSym (Symbol.stringSingle)
          ELSE
            RETURN CheckSym (Symbol.stringDouble)
          END
        END CheckString;
      
      PROCEDURE LinkSection (): AST.Node;
        VAR
          kw, string, lParen, rParen: AST.Node;
          addOptions, addIdent1, addComma, addIdent2: AST.Node;
          dependences: AST.NodeList;
          
        PROCEDURE Options;
          BEGIN
            addOptions := NIL;
            addIdent1 := NIL;
            addComma := NIL;
            addIdent2 := NIL;
            IF Ident ("ADD_OPTION") THEN
              addOptions := CheckSym (Symbol.ident);
              addIdent1 := CheckSym (Symbol.ident);
              IF (sym. id = Symbol.comma) THEN
                addComma := CheckSym (Symbol.comma);
                addIdent2 := CheckSym (Symbol.ident)
              END
            END
          END Options;
        
        BEGIN
          (*S: LinkSection =
            S:   [ "FILE" string [Options] |
            S:     "OBJ" string |
            S:      "LIB" string ["(" string {"," string} ")"] [Options] ].
            S: Options = "ADD_OPTION" ident ["," ident].  *)
          IF Ident ("FILE") THEN
            kw := CheckSym (Symbol.ident);
            string := CheckString();
            Options;
            RETURN ast. LinkFileFlag (kw, string, addOptions, addIdent1, 
                                      addComma, addIdent2)
          ELSIF Ident ("OBJ") THEN
            kw := CheckSym (Symbol.ident);
            string := CheckString();
            RETURN ast. LinkObjFlag (kw, string)
          ELSIF Ident("LIB") OR Ident("FRAMEWORK") THEN
            kw := CheckSym (Symbol.ident);
            string := CheckString();
            IF (sym. id = Symbol.lParen) THEN
              lParen := CheckSym (Symbol.lParen);
              dependences := ast. NewNodeList();
              LOOP
                dependences. Append (CheckString());
                IF (sym. id = Symbol.comma) THEN
                  dependences. Append (CheckSym (Symbol.comma))
                ELSE
                  EXIT
                END
              END;
              rParen := CheckSym (Symbol.rParen)
            ELSE
              lParen := NIL;
              dependences := NIL;
              rParen := NIL;
            END;
            Options;
            RETURN ast. LinkLibFlag (kw, string, lParen, dependences, rParen,
                                    addOptions, addIdent1, addComma, addIdent2)
          ELSE
            RETURN NIL
          END
        END LinkSection;
      
      BEGIN
        (*S: ModuleFlags = "OOC_EXTENSIONS" | "DEPRECATED" |
          S:   ("INTERFACE"|"FOREIGN") string {"," ident}
          S:   [";" "LINK" LinkSection {";" LinkSection} "END".  *)
        IF Ident ("OOC_EXTENSIONS") THEN
          RETURN CheckSym (Symbol.ident)
        ELSIF Ident("DEPRECATED") THEN
          (* FIXME... this approach works only if a single flag is present *)
          RETURN CheckSym (Symbol.ident)
        ELSE
          IF ~Ident("INTERFACE") & ~Ident("FOREIGN") THEN
            Err (expectExternalKW, sym)
          END;
          external := CheckSym(Symbol.ident);
          callConv := CheckString();
          
          moduleFlags := ast. NewNodeList();
          WHILE (sym. id = Symbol.comma) DO
            moduleFlags. Append (CheckSym (Symbol.comma));
            moduleFlags. Append (CheckSym (Symbol.ident))
          END;
          
          IF (sym. id = Symbol.semicolon) THEN
            semicolon := CheckSym (Symbol.semicolon);
            IF Ident ("LINK") THEN
              link := CheckSym (Symbol.ident)
            ELSE
              Err (invalidFlag, sym);
              link := NIL
            END;
            linkSections := ast. NewNodeList();
            LOOP
              linkSections. Append (LinkSection());
              IF (sym. id = Symbol.semicolon) THEN
                linkSections. Append (CheckSym (Symbol.semicolon))
              ELSE
                EXIT
              END
            END;
            end := CheckSym (Symbol.end)
          ELSE
            semicolon := NIL;
            link := NIL;
            linkSections := NIL;
            end := NIL
          END;
          
          RETURN ast. ModuleFlags (external, callConv, moduleFlags,
                                   semicolon, link, linkSections, end)
        END
      END ModuleFlags;
    
    BEGIN
      (*S: Flags = [ "[" ( ModuleFlags | Flag {";" Flag} ) "]" ].  *)
      IF (sym. id = Symbol.lBrak) THEN
        IF ~(enableFlags IN parseOptions) THEN
          Err (noFlags, sym);

          (* skip to end of flags, processing any nested `[...]' on the way *)
          counter := 0;
          REPEAT
            IF (sym. id = Symbol.endOfFile) THEN
              counter := 0
            ELSE
              CASE sym. id OF
              | Symbol.rBrak:
                INC (counter)
              | Symbol.lBrak:
                DEC (counter);
                prevSym := sym
              ELSE  (* just skip *)
              END;
              NextSym
            END
          UNTIL (counter = 0);
          RETURN NIL
        ELSE
          lBrak := CheckSym (Symbol.lBrak);
          flagList := ast. NewNodeList();
          CASE context OF
          | AST.flagsModule:
            flagList. Append (ModuleFlags())
          ELSE
            LOOP
              flagList. Append (Flag ());
              IF (sym. id = Symbol.comma) THEN
                flagList. Append (CheckSym (Symbol.comma))
              ELSE
                EXIT
              END
            END
          END;
          rBrak := CheckSym (Symbol.rBrak);
          RETURN ast. Flags (context, lBrak, flagList, rBrak)
        END
      ELSE
        RETURN NIL
      END
    END Flags;
  
  
  (* The procedures below implement the various productions of the Oberon-2
     syntax.  For the most part, one procedure corresponds to the equally named
     production.  The syntax implemented by the procedures is described by
     comments whose lines are prefixed by the string "S:".  Every procedure
     expects to get the current position in the input stream in the variable
     @ovar{sym}, and moves this input position forward as it parses the 
     input stream.
     
     As soon as a procedure has finished parsing its production, it calls the 
     corresponding type-bound procedure of @oparam{ast}, which is a concrete
     implementation of the abstract class @otype{AST.Builder}.  The type-bound
     procedures takes all the parts of the production as arguments, and creates
     an instance of @otype{AST.Node} to store the results of this parsing
     step.  The newly created instance is then the result of the parser's
     procedure and is passed upward in the recursive descent parser.  *)
     
  PROCEDURE IdentDef (level: LONGINT; noReadOnly, noMark: BOOLEAN;
                      VAR name: AST.Name): AST.IdentDef;
    VAR
      ident, mark: AST.Terminal;
      identDef: AST.IdentDef;
    BEGIN
      (*S: IdentDef = ident ["*" | "-"].  *)
      name := sym. str;
      ident := CheckSym (Symbol.ident);
      IF (sym. id = Symbol.minus) & ~noMark THEN
        IF (level # 0) THEN Err (exportMarkInProc, sym) END;
        IF noReadOnly THEN Err (noReadOnlyExport, sym) END;
        mark := CheckSym (Symbol.minus)
      ELSIF (sym. id = Symbol.times) & ~noMark THEN
        IF (level # 0) THEN Err (exportMarkInProc, sym) END;
        mark := CheckSym (Symbol.times)
      ELSE
        mark := NIL
      END;
      identDef := ast. IdentDef (ident, mark);
      lastIdentDef := identDef;
      RETURN identDef
    END IdentDef;

  PROCEDURE ImportList (moduleName: AST.Name): AST.Node;
    VAR
      import, scolon: AST.Node;
      imports: AST.NodeList;
    
    PROCEDURE ImportDecl (): AST.Node;
      VAR
        alias, becomes, module: AST.Node;
        name: AST.Name;
        ptr: SymList.Symbol;
      BEGIN
        (*S: ImportDecl = [ident ":="] mp_ident.  *)
        IF (sym. next # NIL) & (sym. next. id = Symbol.becomes) THEN
          alias := CheckSym (Symbol.ident);
          becomes := CheckSym (Symbol.becomes)
        ELSE
          alias := NIL;
          becomes := NIL
        END;
        ptr := sym;
        module := MultiPartIdent (name);
        IF (name^ = moduleName^) THEN
          Err (importingThisModule, ptr)
        END;
        (*lastIdentDef := module;  nobody attaches comments to imports? *)
        RETURN ast. ImportDecl (alias, becomes, module, name)
      END ImportDecl;
    
    BEGIN  (* pre: sym.id=Symbol.import *)
      (*S: ImportList = "IMPORT" ImportDecl {"," ImportDecl} ";".  *)
      import := CheckSym (Symbol.import);
      imports := ast. NewNodeList();
      LOOP
        imports. Append (ImportDecl());
        IF (sym. id = Symbol.comma) THEN
          imports. Append (CheckSym (Symbol.comma))
        ELSE
          EXIT
        END
      END;
      scolon := CheckSym (Symbol.semicolon);
      RETURN ast. ImportList (import, imports, scolon);
    END ImportList;
  
  PROCEDURE ^ Expr (): AST.Node;
  
  PROCEDURE Qualident (): AST.Node;
    VAR
      module, period, ident: AST.Node;
    BEGIN
      (*S: Qualident = ident ["." ident].  *)
      module := CheckSym (Symbol.ident);
      IF (sym. id = Symbol.period) THEN
        period := CheckSym (Symbol.period);
        ident := CheckSym (Symbol.ident);
        RETURN ast. Operator (module, period, ident)
      ELSE
        RETURN module
      END
    END Qualident;
  
  PROCEDURE QualType(): AST.Node;
    VAR
      type, left, right: AST.Node;
      list: AST.NodeList;
    BEGIN
      (*S: QualType = Qualident ["(" [QualType {"," QualType}] ")"] *)
      type :=  Qualident();
      IF (sym.id = Symbol.lParen) & (enableTypeParams IN parseOptions) THEN
        left := CheckSym(Symbol.lParen);
        list := ast.NewNodeList();
        IF (sym.id # Symbol.rParen) THEN
          list.Append(QualType());
          WHILE (sym.id = Symbol.comma) DO
            list.Append(CheckSym(Symbol.comma));
            list.Append(QualType());
          END
        END;
        right := CheckSym(Symbol.rParen);
        RETURN ast.QualType(type, left, list, right);
      ELSE
        RETURN type;
      END;
    END QualType;
  
  PROCEDURE Designator (): AST.Node;
    VAR
      x, y, op, left, right: AST.Node;
      list: AST.NodeList;

    PROCEDURE Call(design: AST.Node): AST.Node;
      VAR
        left, right: AST.Node;
        list: AST.NodeList;
      BEGIN
        left := CheckSym (Symbol.lParen);
        list := ast. NewNodeList();
        IF (sym. id # Symbol.rParen) THEN
          list. Append (Expr());
          WHILE (sym. id = Symbol.comma) DO
            list. Append (CheckSym (Symbol.comma));
            list. Append (Expr())
          END
        END;
        right := CheckSym (Symbol.rParen);
        RETURN ast. FunctionCall (design, left, list, right)
      END Call;
    
    BEGIN
      (*S: Designator = ident { "." ident | "^" | 
        S:                      "[" Expr {"," Expr} "]" | 
        S:                      "(" [Expr {"," Expr}] ")" }.  *)
      x := CheckSym (Symbol.ident);
      LOOP
        CASE sym. id OF
        | Symbol.period:
          op := CheckSym (Symbol.period);
          y := CheckSym (Symbol.ident);
          x := ast. Operator (x, op, y)
        | Symbol.arrow:
          op := CheckSym (Symbol.arrow);
          x := ast. Operator (x, op, NIL)
        | Symbol.lBrak:
          left := CheckSym (Symbol.lBrak);
          list := ast. NewNodeList();
          list. Append (Expr());
          WHILE (sym. id = Symbol.comma) DO
            list. Append (CheckSym (Symbol.comma));
            list. Append (Expr())
          END;
          right := CheckSym (Symbol.rBrak);
          x := ast. ArrayIndex (x, left, list, right)
        | Symbol.lParen:
          x := Call(x);
        ELSE
          EXIT
        END
      END;
      RETURN x;
    END Designator;
  
  PROCEDURE Expr (): AST.Node;
    VAR
      x, y, op: AST.Node;

    PROCEDURE SimpleExpr (): AST.Node;
      VAR
        x, y, op: AST.Node;

      PROCEDURE Term (): AST.Node;
        VAR
          x, y, op: AST.Node;
          
        PROCEDURE Factor (): AST.Node;
          VAR
            factor, lParen, expr, rParen, op, right: AST.Node;
            
          PROCEDURE Set (type: AST.Node): AST.Node;
            VAR
              lBrace, rBrace: AST.Node;
              elementList: AST.NodeList;
              
            PROCEDURE Element (): AST.Node;
              VAR
                lExpr, upto, rExpr: AST.Node;
              BEGIN
                lExpr := Expr();
                IF (sym. id = Symbol.upto) THEN
                  upto := CheckSym (Symbol.upto);
                  rExpr := Expr();
                  RETURN ast. Operator (lExpr, upto, rExpr)
                ELSE
                  RETURN lExpr
                END
              END Element;
            
            BEGIN
              (*S: Set = "{" [Element {"," Element}] "}".
                S: Element = Expr [".." Expr].  *)
              lBrace := CheckSym (Symbol.lBrace);
              elementList := ast. NewNodeList();
              IF (sym. id # Symbol.rBrace) THEN
                elementList. Append (Element());
                WHILE (sym. id = Symbol.comma) DO
                  elementList. Append (CheckSym (Symbol.comma));
                  elementList. Append (Element())
                END
              END;
              rBrace := CheckSym (Symbol.rBrace);
              RETURN ast. Set (type, lBrace, elementList, rBrace)
            END Set;
          
          BEGIN
            (*S: Factor = Designator [Set] | number | character | string |
              S:          "NIL" | Set | "(" Expr ")" | "~" Factor.
              Note: Function calls have been folded into Designator.  *)
            IF (sym. id = Symbol.ident) THEN
              factor := Designator();
              IF (sym. id = Symbol.lBrace) THEN
                factor := Set (factor)
              END
            ELSIF (Symbol.number10 <= sym. id) &
                  (sym. id <= Symbol.numberExpD) THEN
              factor := CheckSym (sym. id)
            ELSIF (sym. id = Symbol.stringSingle) OR
                  (sym. id = Symbol.stringDouble) THEN
              factor := CheckSym (sym. id)
            ELSIF (sym. id = Symbol.nil) THEN
              factor := CheckSym (Symbol.nil)
            ELSIF (sym. id = Symbol.lBrace) THEN
              factor := Set (NIL)
            ELSIF (sym. id = Symbol.lParen) THEN
              lParen := CheckSym (Symbol.lParen);
              expr := Expr();
              rParen := CheckSym (Symbol.rParen);
              factor := ast. Factor (lParen, expr, rParen)
            ELSIF (sym. id = Symbol.not) THEN
              op := CheckSym (Symbol.not);
              right := Factor();
              factor := ast. Operator (NIL, op, right)
            ELSE
              Err (illegalFactor, sym);
              factor := ast. Terminal (sym); (* avoid NIL *)
            END;
            RETURN factor
          END Factor;
        
        BEGIN
          (*S: Term = Factor {MulOp Factor}.
            S: MulOp = "*" | "/" | "DIV" | "MOD" | "&".  *)
          x := Factor();
          WHILE (Symbol.times <= sym. id) & (sym. id <= Symbol.and) DO
            op := CheckSym (sym. id);
            y := Factor();
            x := ast. Operator (x, op, y)
          END;
          RETURN x
        END Term;
      
      BEGIN
        (*S: SimpleExpr = ["+" | "-"] Term {AddOp Term}.
          S: AddOp = "+" | "-" | "OR".  *)
        IF (sym. id = Symbol.plus) OR (sym. id = Symbol.minus) THEN
          op := CheckSym (sym. id);
          y := Term();
          x := ast. Operator (NIL, op, y)
        ELSE
          x := Term()
        END;
        WHILE (Symbol.plus <= sym. id) & (sym. id <= Symbol.or) DO
          op := CheckSym (sym. id);
          y := Term();
          x := ast. Operator (x, op, y)
        END;
        RETURN x
      END SimpleExpr;
    
    BEGIN
      (*S: Expr = SimpleExpr [Relation SimpleExpr].
        S: Relation = "=" | "#" | "<" | "<=" | ">" | ">=" | "IN" | "IS".  *)
      x := SimpleExpr();
      IF (Symbol.eql <= sym. id) & (sym. id <= Symbol.is) THEN
        op := CheckSym (sym. id);
        y := SimpleExpr();
        x := ast. Operator (x, op, y)
      END;
      RETURN x
    END Expr;

  PROCEDURE ^ Type (level: LONGINT): AST.Node;
  
  PROCEDURE FormalPars (): AST.Node;
    VAR
      flags: AST.Flags;
      lParen, rParen, colon, result, raises, oldLastIdentDef: AST.Node;
      fpSections, raisesList: AST.NodeList;
    
    PROCEDURE FPSection (): AST.Node;
      VAR
        var, colon, type, ident: AST.Node;
        fpList: AST.NodeList;
        dummy: AST.Name;
      BEGIN
        (*S: FormalPars = ["VAR"] ident Flags 
          S:              {"," ident Flags} ":" Type.  *)
        IF (sym. id = Symbol.var) THEN
          var := CheckSym (Symbol.var)
        ELSE
          var := NIL
        END;
        fpList := ast. NewNodeList();
        LOOP
          ident := IdentDef (0, FALSE, TRUE, dummy);
          lastIdentDef := ident;
          fpList. Append (ident);
          fpList. Append (Flags (AST.flagsParameter));
          IF (sym. id = Symbol.comma) THEN
            fpList. Append (CheckSym (Symbol.comma))
          ELSE
            EXIT
          END
        END;
        colon := CheckSym (Symbol.colon);
        type := Type (MIN (LONGINT));
        RETURN ast. FPSection (var, fpList, colon, type)
      END FPSection;
    
    BEGIN
      (*S: FormalPars = Flags 
        S:              [ "(" [FPSection {";" FPSection} [";" "..."] ] ")"
        S:                [":" QualType]
        S:                ["RAISES" Qualident {"," Qualident}] ].  *)
      oldLastIdentDef := lastIdentDef;
      flags := Flags (AST.flagsProcType);
      IF (sym. id = Symbol.lParen) THEN
        lParen := CheckSym (Symbol.lParen);
        fpSections := ast. NewNodeList();
        IF (sym. id = Symbol.var) OR (sym. id = Symbol.ident) THEN
          LOOP
            fpSections. Append (FPSection());
            IF (sym. id = Symbol.semicolon) THEN
              fpSections. Append (CheckSym (Symbol.semicolon));
              IF (sym. id = Symbol.threeDots) THEN
                IF ~(enableRestParam IN parseOptions) THEN
                  Err (noRestParameter, sym)
                END;
                fpSections. Append (CheckSym (Symbol.threeDots));
                EXIT
              END
            ELSE
              EXIT
            END
          END
        END;
        rParen := CheckSym (Symbol.rParen);
        IF (sym. id = Symbol.colon) THEN
          colon := CheckSym (Symbol.colon);
          result := QualType()
        ELSE
          colon := NIL;
          result := NIL
        END;

        IF (sym.id = Symbol.raises) THEN
          raises := CheckSym (Symbol.raises);
          raisesList := ast. NewNodeList();
          LOOP
            raisesList. Append (Qualident());
            IF (sym. id = Symbol.comma) THEN
              raisesList. Append (CheckSym (Symbol.comma));
            ELSE
              EXIT;
            END
          END;
        ELSE
          raises := NIL; 
          raisesList := NIL;
        END;
      ELSE
        lParen := NIL;
        fpSections := NIL;
        rParen := NIL;
        colon := NIL;
        result := NIL;
        raisesList := NIL;
        raises := NIL; 
      END;
      lastIdentDef := oldLastIdentDef;
      RETURN ast. FormalPars (flags, lParen, fpSections, rParen,
                              colon, result, raises, raisesList);
    END FormalPars;
  
  PROCEDURE TypePars(): AST.TypePars;
    VAR
      lParen, rParen, oldLastIdentDef: AST.Node;
      tpSections: AST.NodeList;
    
    PROCEDURE TPSection (): AST.Node;
      VAR
        colon, type, ident: AST.Node;
        tpList: AST.NodeList;
        dummy: AST.Name;
      BEGIN
        (*S: TPSection = ident {"," ident} ":" Qualident.  *)
        tpList := ast.NewNodeList();
        LOOP
          ident := IdentDef(0, FALSE, TRUE, dummy);
          lastIdentDef := ident;
          tpList.Append (ident);
          IF (sym. id = Symbol.comma) THEN
            tpList.Append(CheckSym(Symbol.comma));
          ELSE
            EXIT;
          END
        END;
        colon := CheckSym(Symbol.colon);
        type := Qualident();
        (*type := Type(MIN(LONGINT));*)
        RETURN ast.TPSection(tpList, colon, type);
      END TPSection;
    
    BEGIN  (* pre: (sym.id = Symbol.lParen) *)
      (*S: TypePars = "(" [TPSection {";" TPSection} ] ")".  *)
      oldLastIdentDef := lastIdentDef;
      lParen := CheckSym(Symbol.lParen);
      tpSections := ast.NewNodeList();
      IF (sym.id = Symbol.ident) THEN
        LOOP
          tpSections.Append(TPSection());
          IF (sym.id = Symbol.semicolon) THEN
            tpSections.Append(CheckSym(Symbol.semicolon));
          ELSE
            EXIT;
          END
        END
      END;
      rParen := CheckSym(Symbol.rParen);
      lastIdentDef := oldLastIdentDef;
      RETURN ast.TypePars(lParen, tpSections, rParen);
    END TypePars;
  
  PROCEDURE Type (level: LONGINT): AST.Node;
    VAR
      type: AST.Node;
    
    PROCEDURE ArrayType (): AST.Node;
      VAR
        array, of, type: AST.Node;
        flags: AST.Flags;
        exprList: AST.NodeList;
      BEGIN
        (*S: ArrayType = "ARRAY" Flags [Expr {"," Expr}] "OF" Type.  *)
        array := CheckSym (Symbol.array);
        flags := Flags (AST.flagsArrayType);
        exprList := ast. NewNodeList();
        IF (sym. id # Symbol.of) THEN
          LOOP
            exprList. Append (Expr());
            IF (sym. id = Symbol.comma) THEN
              exprList. Append (CheckSym (Symbol.comma))
            ELSE
              EXIT
            END
          END
        END;
        of := CheckSym (Symbol.of);
        type := Type (level);
        RETURN ast. ArrayType (array, flags, exprList, of, type)
      END ArrayType;
    
    PROCEDURE RecordType (): AST.Node;
      VAR
        flags: AST.Flags;
        record, lParen, qualident, rParen, end: AST.Node;
        fieldLists: AST.NodeList;
      
      PROCEDURE FieldList (): AST.Node;
        VAR
          colon, type: AST.Node;
          identList: AST.NodeList;
          dummy: AST.Name;
        BEGIN  (* pre: sym. id = Symbol.ident *)
          (*S: FieldList = IdentDef Flags {"," IdentDef Flags } ":" Type.  *)
          identList := ast. NewNodeList();
          LOOP
            identList. Append (IdentDef (level, FALSE, FALSE, dummy));
            identList. Append (Flags (AST.flagsField));
            IF (sym. id = Symbol.comma) THEN
              identList. Append (CheckSym (Symbol.comma))
            ELSE
              EXIT
            END
          END;
          colon := CheckSym (Symbol.colon);
          type := Type (level);
          RETURN ast. FieldList (identList, colon, type)
        END FieldList;
      
      BEGIN
        (*S: RecordType = "RECORD" Flags ["("QualType")"] 
          S:              [FieldList] {";" [FieldList]} "END".  *)
        record := CheckSym (Symbol.record);
        flags := Flags (AST.flagsRecordType);
        IF (sym. id = Symbol.lParen) THEN
          lParen := CheckSym (Symbol.lParen);
          qualident := QualType();
          rParen := CheckSym (Symbol.rParen)
        ELSE
          lParen := NIL;
          qualident := NIL;
          rParen := NIL
        END;
        fieldLists := ast. NewNodeList();
        LOOP
          IF (sym. id = Symbol.ident) THEN
            fieldLists. Append (FieldList())
          ELSE
            fieldLists. Append (NIL)
          END;
          IF (sym. id = Symbol.semicolon) THEN
            fieldLists. Append (CheckSym (Symbol.semicolon))
          ELSE
            EXIT
          END
        END;
        end := CheckSym (Symbol.end);
        RETURN ast. RecordType (record, flags, lParen, qualident, rParen,
                                fieldLists, end)
      END RecordType;
    
    PROCEDURE PointerType (): AST.Node;
      VAR
        flags: AST.Flags;
        pointer, to, type: AST.Node;
      BEGIN
        (*S: PointerType =  "POINTER" Flags "TO" Type.  *)
        pointer := CheckSym (Symbol.pointer);
        flags := Flags (AST.flagsPointerType);
        to := CheckSym (Symbol.to);
        type := Type (level);
        RETURN ast. PointerType (pointer, flags, to, type)
      END PointerType;
    
    PROCEDURE ProcType (): AST.Node;
      VAR
        procedure, formalPars: AST.Node;
      BEGIN
        (*S: ProcType = "PROCEDURE" FormalPars.  *)
        procedure := CheckSym (Symbol.procedure);
        formalPars := FormalPars();
        RETURN ast. ProcType (procedure, formalPars)
      END ProcType;

    BEGIN
      (*S: Type = QualType|ArrayType|RecordType|PointerType|ProcType.  *)
      CASE sym. id OF
      | Symbol.ident:
        type :=  QualType();
      | Symbol.array:
        type :=  ArrayType()
      | Symbol.record:
        type :=  RecordType()
      | Symbol.pointer:
        type :=  PointerType()
      | Symbol.procedure:
        type :=  ProcType()
      ELSE
        Err (expectDataType, sym);
        type :=  NIL
      END;
      IF ((sym. id < Symbol.semicolon) OR (sym. id > Symbol.else)) & 
         (sym. id # Symbol.rParen) THEN
        (* unexpected symbol (has to be out of follow (Type)); skip token to
           resynchronize *)
        Err (unexpectedSymbol, sym);
        WHILE ((sym. id < Symbol.ident) OR (sym. id > Symbol.else)) &
              (sym. id < Symbol.begin) & (sym. id # Symbol.rParen) DO
          NextSym
        END
      END;
      RETURN type
    END Type;

  PROCEDURE Body (level: LONGINT; headName: AST.Name): AST.Body;
  (* level=0: module; level>0: nested in this many procedures *)
    VAR
      begin, end, name: AST.Node;
      declSeq, statmSeq: AST.NodeList;
      ptr: SymList.Symbol;
      tailName: AST.Name;
    
    PROCEDURE DeclSeq(): AST.NodeList;
      VAR
        nl: AST.NodeList;
        
      PROCEDURE ConstDecl(): AST.Node;
        VAR
          flags: AST.Flags;
          identDef, equal, expr, scolon: AST.Node;
          dummy: AST.Name;
        BEGIN  (* pre: (sym. id = Symbol.ident) *)
          (*S: ConstDecl = IdentDef Flags "=" Expr ";".  *)
          identDef := IdentDef (level, TRUE, FALSE, dummy);
          flags := Flags(AST.flagsConstDecl);
          equal := CheckSym (Symbol.eql);
          expr := Expr();
          scolon := CheckSym (Symbol.semicolon);
          RETURN ast. ConstDecl (identDef, flags, equal, expr, scolon)
        END ConstDecl;

      PROCEDURE TypeDecl (): AST.Node;
        VAR
          flags: AST.Flags;
          typePars: AST.TypePars;
          identDef, equal, type, scolon: AST.Node;
          dummy: AST.Name;
        BEGIN  (* pre: (sym. id = Symbol.ident) *)
          (*S: TypeDecl = IdentDef Flags [TypePars] "=" Type ";".  *)
          identDef := IdentDef (level, TRUE, FALSE, dummy);
          flags := Flags(AST.flagsTypeDecl);
          IF (sym.id = Symbol.lParen) & (enableTypeParams IN parseOptions) THEN
            typePars := TypePars();
          ELSE
            typePars := NIL;
          END;
          equal := CheckSym (Symbol.eql);
          type := Type (level);
          scolon := CheckSym (Symbol.semicolon);
          RETURN ast. TypeDecl (identDef, flags, typePars, equal, type, scolon)
        END TypeDecl;

      PROCEDURE VarDecl (): AST.Node;
        VAR
          identList: AST.NodeList;
          colon, type, scolon: AST.Node;
          dummy: AST.Name;
        BEGIN  (* pre: (sym. id = Symbol.ident) *)
          (*S: VarDecl = IdentDef Flags 
            S:             {"," IdentDef Flags} ":" Type.  *)
          identList := ast. NewNodeList();
          LOOP
            identList. Append (IdentDef (level, FALSE, FALSE, dummy));
            identList. Append (Flags (AST.flagsVariable));
            IF (sym. id = Symbol.comma) THEN
              identList. Append (CheckSym (Symbol.comma))
            ELSIF (sym. id = Symbol.ident) THEN
              Err (expectIdent, sym)
            ELSE
              EXIT
            END
          END;
          colon := CheckSym (Symbol.colon);
          type := Type (level);
          scolon := CheckSym (Symbol.semicolon);
          RETURN ast. VarDecl (identList, colon, type, scolon)
        END VarDecl;

      PROCEDURE ProcDecl (): AST.Node;
        VAR
          flags: AST.Flags;
          body: AST.Body;
          proc, arrow, receiver, identDef, formalPars, semicolon1,
              semicolon2: AST.Node;
          procName: AST.Name;
        
        PROCEDURE Receiver (): AST.Node;
          VAR
            ident: AST.IdentDef;
            lParenAlias, rParenAlias: AST.Terminal;
            lParen, var, colon, type, rParen: AST.Node;
            aliasList: AST.NodeList;
            dummy: AST.Name;

          PROCEDURE AliasList(VAR lParen: AST.Terminal;
                              VAR aliasList: AST.NodeList;
                              VAR rParen: AST.Terminal);
            BEGIN  (* pre: sym.id=lParen *)
              lParen := CheckSym (Symbol.lParen);
              aliasList := ast.NewNodeList();
              IF (sym.id = Symbol.ident) THEN
                LOOP
                  aliasList.Append(CheckSym(Symbol.ident));
                  IF (sym.id = Symbol.comma) THEN
                    aliasList.Append(CheckSym(Symbol.comma));
                  ELSE
                    EXIT;
                  END;
                END;
              END;
              rParen := CheckSym (Symbol.rParen);
            END AliasList;
          
          BEGIN
            (*S: AliasList = "(" [ident {"," ident}] ")".
              S: Receiver = "(" ["VAR"] ident ":" ident  [AliasList] ")".  *)
            lParen := CheckSym (Symbol.lParen);
            IF (sym. id = Symbol.var) THEN
              var := CheckSym (Symbol.var)
            ELSE
              var := NIL
            END;
            ident := IdentDef (0, FALSE, TRUE, dummy);
            colon := CheckSym (Symbol.colon);
            type := CheckSym (Symbol.ident);
            
            IF (sym.id = Symbol.lParen) THEN
              AliasList(lParenAlias, aliasList, rParenAlias);
            ELSE
              lParenAlias := NIL;
              aliasList := NIL;
              rParenAlias := NIL;
            END;
            
            rParen := CheckSym (Symbol.rParen);
            RETURN ast. Receiver (lParen, var, ident, colon, type,
                                  lParenAlias, aliasList, rParenAlias, rParen);
          END Receiver;
        
        BEGIN  (* pre: (sym. id = Symbol.procedure) *)
          (*S: ProcDecl = "PROCEDURE" ["^"] [Receiver] Flags IdentDef 
            S:            FormalPars ";" [Body ";"].  *)
          proc := CheckSym (Symbol.procedure);
          IF (sym. id = Symbol.arrow) THEN
            arrow := CheckSym (Symbol.arrow)
          ELSE
            arrow := NIL
          END;
          IF (sym. id = Symbol.lParen) THEN
            IF (level # 0) THEN Err (tbProcInsideProc, sym) END;
            receiver := Receiver()
          ELSE
            receiver := NIL
          END;
          flags := Flags (AST.flagsProcedure);
          identDef := IdentDef (level, TRUE, FALSE, procName);
          formalPars := FormalPars();
          semicolon1 := CheckSym (Symbol.semicolon);
          IF (arrow = NIL) & ~ast. ProcWithoutBody (moduleFlags, flags) THEN
            body := Body (level+1, procName);
            semicolon2 := CheckSym (Symbol.semicolon)
          ELSE
            body := NIL;
            semicolon2 := NIL
          END;
          RETURN ast. ProcDecl (proc, arrow, receiver, flags, identDef, 
                                formalPars, semicolon1, body, semicolon2)
        END ProcDecl;

      BEGIN
        (*S: DeclSeq = { "CONST" {ConstDecl} | 
          S:             "TYPE" {TypeDecl} |
          S;             "VAR" {VarDecl} } {ProcDecl}.
          Note: the ending ";" is handled as part of the declaration syntax *)
        nl := ast. NewNodeList();
        LOOP
          IF (sym. id = Symbol.const) THEN (* constant declaration *)
            nl. Append (CheckSym (Symbol.const));
            WHILE (sym. id = Symbol.ident) DO
              nl. Append (ConstDecl())
            END
          ELSIF (sym. id = Symbol.type) THEN (* type declaration *)
            nl. Append (CheckSym (Symbol.type));
            WHILE (sym. id = Symbol.ident) DO
              nl. Append (TypeDecl())
            END
          ELSIF (sym. id = Symbol.var) THEN (* variable declaration *)
            nl. Append (CheckSym (Symbol.var));
            WHILE (sym. id = Symbol.ident) DO
              nl. Append (VarDecl())
            END
          ELSE
            EXIT
          END
        END;
        (* parse list of procedure declarations *)
        WHILE (sym. id = Symbol.procedure) DO
          nl. Append (ProcDecl())
        END;
        RETURN nl
      END DeclSeq;

    PROCEDURE StatementSeq(): AST.NodeList;
      VAR
        list: AST.NodeList;
      
      PROCEDURE Statement (): AST.Node;
        PROCEDURE ProcCallOrAssignment (): AST.Node;
          VAR
            design, becomes, value: AST.Node;
          BEGIN
            (*S: ProcCallOrAssignment = Designator [":=" Expr].  *)
            design := Designator();
            IF (sym. id = Symbol.becomes) THEN
              becomes := CheckSym (Symbol.becomes);
              value := Expr();
              RETURN ast. Assignment (ast. Operator (design, becomes, value))
            ELSE
              RETURN ast. ProcedureCall (design)
            END
          END ProcCallOrAssignment;
        
        PROCEDURE IfStatm (): AST.Node;
          VAR
            else: AST.Node;
            guardList, elseStatmSeq: AST.NodeList;
          BEGIN
            (*S: IfStatm = "IF" Expr "THEN" StatementSeq
              S:           {"ELSIF" Expr "THEN" StatementSeq}
              S:           ["ELSE" StatementSeq] "END".  *)
            guardList := ast. NewNodeList();
            guardList. Append (CheckSym (Symbol.if));
            LOOP
              guardList. Append (Expr());
              guardList. Append (CheckSym (Symbol.then));
              guardList. Append (StatementSeq());
              IF (sym. id = Symbol.elsif) THEN
                guardList. Append (CheckSym (Symbol.elsif))
              ELSE
                EXIT
              END
            END;
            IF (sym. id = Symbol.else) THEN
              else := CheckSym (Symbol.else);
              elseStatmSeq := StatementSeq()
            ELSE
              else := NIL;
              elseStatmSeq := NIL
            END;
            end := CheckSym (Symbol.end);
            RETURN ast. IfStatm (guardList, else, elseStatmSeq, end)
          END IfStatm;
        
        PROCEDURE CaseStatm (): AST.Node;
          VAR
            case, expr, of, else, end: AST.Node;
            caseList, elseStatmSeq: AST.NodeList;
            
          PROCEDURE Case (caseList: AST.NodeList);
            VAR
              labels: AST.NodeList;
              startValue, upto, endValue: AST.Node;
            BEGIN
              (*S: Case = [CaseLabels {"," CaseLabels} ":" StatementSeq].
                S: CaseLabels = Expr [".." Expr].  *)
              IF (sym. id < Symbol.bar) THEN
                labels := ast. NewNodeList();
                LOOP
                  startValue := Expr();
                  IF (sym. id = Symbol.upto) THEN
                    upto := CheckSym (Symbol.upto);
                    endValue := Expr();
                    labels. Append (ast. Operator (startValue, upto, endValue))
                  ELSE
                    labels. Append (startValue)
                  END;
                  IF (sym. id = Symbol.comma) THEN
                    labels. Append (CheckSym (Symbol.comma))
                  ELSE
                    EXIT
                  END
                END;
                caseList. Append (labels);
                caseList. Append (CheckSym (Symbol.colon));
                caseList. Append (StatementSeq())
              ELSE
                caseList. Append (NIL);
                caseList. Append (NIL);
                caseList. Append (NIL)
              END
            END Case;
          
          BEGIN
            (*S: CaseStatm = "CASE" Expr "OF" Case {"|" Case} 
              S:             ["ELSE" StatementSeq] "END".  *)
            case := CheckSym (Symbol.case);
            expr := Expr();
            of := CheckSym (Symbol.of);
            caseList := ast.NewNodeList();
            Case (caseList);
            WHILE (sym. id = Symbol.bar) DO
              caseList. Append (CheckSym (Symbol.bar));
              Case (caseList)
            END;
            IF (sym. id = Symbol.else) THEN
              else := CheckSym (Symbol.else);
              elseStatmSeq := StatementSeq()
            ELSE
              else := NIL;
              elseStatmSeq := NIL
            END;
            end := CheckSym (Symbol.end);
            RETURN ast. CaseStatm (case, expr, of, caseList, 
                                   else, elseStatmSeq, end)
          END CaseStatm;
        
        PROCEDURE WhileStatm (): AST.Node;
          VAR
            while, guard, do, end: AST.Node;
            statmSeq: AST.NodeList;
          BEGIN
            (*S: WhileStatm = "WHILE" Expr "DO" StatementSeq "END".  *)
            while := CheckSym (Symbol.while);
            guard := Expr();
            do := CheckSym (Symbol.do);
            statmSeq := StatementSeq();
            end := CheckSym (Symbol.end);
            RETURN ast. WhileStatm (while, guard, do, statmSeq, end)
          END WhileStatm;
        
        PROCEDURE RepeatStatm (): AST.Node;
          VAR
            repeat, until, expr: AST.Node;
            statmSeq: AST.NodeList;
          BEGIN
            (*S: RepeatStatm = "REPEAT" StatementSeq "UNTIL" Expr.  *)
            repeat := CheckSym (Symbol.repeat);
            statmSeq := StatementSeq();
            until := CheckSym (Symbol.until);
            expr := Expr();
            RETURN ast. RepeatStatm (repeat, statmSeq, until, expr)
          END RepeatStatm;
        
        PROCEDURE ForStatm (): AST.Node;
          VAR
            for, ident, becomes, startValue, to, endValue, 
            by, step, range, do, end: AST.Node;
            statmSeq: AST.NodeList;
          BEGIN
            (*S: ForStatm = "FOR" ident (":=" Expr "TO" Expr ["BY" Expr] |
              S:                         "IN" Expr )
              S:            "DO" StatementSeq "END".  *)
            for := CheckSym (Symbol.for);
            ident := CheckSym (Symbol.ident);
            IF (sym.id = Symbol.in) THEN
              becomes := CheckSym (Symbol.in);
              range := Expr();
              do := CheckSym (Symbol.do);
              statmSeq := StatementSeq();
              end := CheckSym (Symbol.end);
              RETURN ast. IterateStatm (for, ident, becomes, range,
                                        do, statmSeq, end);
            ELSE
              becomes := CheckSym (Symbol.becomes);
              startValue := Expr();
              to := CheckSym (Symbol.to);
              endValue := Expr();
              IF (sym. id = Symbol.by) THEN
                by := CheckSym (Symbol.by);
                step := Expr()
              ELSE
                by := NIL;
                step := NIL
              END;
              do := CheckSym (Symbol.do);
              statmSeq := StatementSeq();
              end := CheckSym (Symbol.end);
              RETURN ast. ForStatm (for, ident, becomes, startValue, to, 
                                    endValue, by, step, do, statmSeq, end);
            END;
          END ForStatm;
        
        PROCEDURE LoopStatm (): AST.Node;
          VAR
            loop, end: AST.Node;
            statmSeq: AST.NodeList;
          BEGIN
            (*S: LoopStatm = "LOOP" StatementSeq "END".  *)
            loop := CheckSym (Symbol.loop);
            statmSeq := StatementSeq();
            end := CheckSym (Symbol.end);
            RETURN ast. LoopStatm (loop, statmSeq, end)
          END LoopStatm;
        
        PROCEDURE WithStatm (): AST.Node;
          VAR
            else, end, var, colon, type: AST.Node;
            guardList, elseStatmSeq: AST.NodeList;
          BEGIN
            (*S: WithStatm = "WITH" Guard "DO" StatementSeq 
              S:             {"|" Guard "DO" StatementSeq}
              S:             ["ELSE" StatementSeq] "END".  *)
            guardList := ast. NewNodeList();
            guardList. Append (CheckSym (Symbol.with));
            LOOP
              var := Qualident();
              colon := CheckSym (Symbol.colon);
              type := QualType();
              guardList. Append (ast. Operator (var, colon, type));
              guardList. Append (CheckSym (Symbol.do));
              guardList. Append (StatementSeq());
              IF (sym. id = Symbol.bar) THEN
                guardList. Append (CheckSym (Symbol.bar))
              ELSE
                EXIT
              END
            END;
            IF (sym. id = Symbol.else) THEN
              else := CheckSym (Symbol.else);
              elseStatmSeq := StatementSeq()
            ELSE
              else := NIL;
              elseStatmSeq := NIL
            END;
            end := CheckSym (Symbol.end);
            RETURN ast. WithStatm (guardList, else, elseStatmSeq, end)
          END WithStatm;
        
        PROCEDURE ExitStatm (): AST.Node;
          VAR
            exit: AST.Node;
          BEGIN
            (*S: ExitStatm = "EXIT".  *)
            exit := CheckSym (Symbol.exit);
            RETURN ast. ExitStatm (exit)
          END ExitStatm;
        
        PROCEDURE ReturnStatm (): AST.Node;
          VAR
            return, expr: AST.Node;
          BEGIN
            (*S: ReturnStatm = "RETURN" [Expr].  *)
            return := CheckSym (Symbol.return);
            IF (sym. id < Symbol.semicolon) THEN
              expr := Expr()
            ELSE
              expr := NIL
            END;
            RETURN ast. ReturnStatm (return, expr)
          END ReturnStatm;

        PROCEDURE TryStatm(): AST.Node;
          VAR
            catchList: AST.NodeList;
            try, end: AST.Node;
            statmSeq: AST.NodeList;

          PROCEDURE Catch(): AST.Node;
            VAR
              catch, type, lParen, ident, rParen, colon: AST.Node;
              statmSeq: AST.NodeList;
            BEGIN
              catch := CheckSym(Symbol.catch);
              type := Qualident();
              IF (sym.id = Symbol.lParen) THEN
                lParen := CheckSym(Symbol.lParen);
                ident := CheckSym(Symbol.ident);
                rParen := CheckSym(Symbol.rParen);
              ELSE
                lParen := NIL;
                ident := NIL;
                rParen := NIL;
              END;
              colon := CheckSym(Symbol.colon);
              statmSeq := StatementSeq();
              RETURN ast.Catch(catch, type, lParen, ident, rParen,
                               colon, statmSeq);
            END Catch;
          
          BEGIN
            (*S: TryStatm = "TRY" StatementSeq
                            {"CATCH" Qualident["(" ident ")"]":" StatementSeq}
                            "END". *)
            try := CheckSym(Symbol.try);
            statmSeq := StatementSeq();
            catchList := ast.NewNodeList();
            WHILE (sym.id = Symbol.catch) DO
              catchList.Append(Catch());
            END;
            end := CheckSym(Symbol.end);
            RETURN ast.TryStatm(try, statmSeq, catchList, end);
          END TryStatm;
        
        BEGIN
          (*S: Statement = [ ProcCallOrAssignment | IfStatm | CaseStatm |
                             WhileStatm | RepeatStatm | ForStatm | LoopStatm |
                             WithStatm | ExitStatm | ReturnStatm ].  *)
          CASE sym. id OF
          | Symbol.ident:
            RETURN ProcCallOrAssignment()
          | Symbol.if:
            RETURN IfStatm()
          | Symbol.case:
            RETURN CaseStatm()
          | Symbol.while:
            RETURN WhileStatm()
          | Symbol.repeat:
            RETURN RepeatStatm()
          | Symbol.for:
            RETURN ForStatm()
          | Symbol.loop:
            RETURN LoopStatm()
          | Symbol.with:
            RETURN WithStatm()
          | Symbol.exit:
            RETURN ExitStatm()
          | Symbol.return:
            RETURN ReturnStatm()
          | Symbol.try:
            RETURN TryStatm()
          ELSE
            RETURN NIL
          END
        END Statement;
      
      BEGIN
        (*S: StatementSeq = Statement {";" Statement}.  *)
        list := ast. NewNodeList();
        list. Append (Statement());
        WHILE (sym. id = Symbol.semicolon) DO
          list. Append (CheckSym (Symbol.semicolon));
          list. Append (Statement())
        END;
        RETURN list
      END StatementSeq;
    
    PROCEDURE CheckName (sym: SymList.Symbol; head, tail: AST.Name);
      BEGIN
        IF (errList. msgCount = 0) & (head^ # tail^) THEN
          Err (nameMismatch, sym);
          ErrStringAttrib ("name", head^)
        END
      END CheckName;
    
    BEGIN
      (*S: Body = DeclSeq ["BEGIN" StatementSeq] "END" mp_ident.  *)
      declSeq := DeclSeq();
      IF (sym. id = Symbol.begin) THEN
        begin := CheckSym (Symbol.begin);
        statmSeq := StatementSeq()
      ELSE
        begin := NIL;
        statmSeq := NIL
      END;
      end := CheckSym (Symbol.end);
      ptr := sym;
      name := MultiPartIdent (tailName);
      CheckName (ptr, headName, tailName);
      RETURN ast. Body (declSeq, begin, statmSeq, end, name)
    END Body;
  
  BEGIN
    lastError := NIL;
    prevSym := NIL;
    lastIdentDef := NIL;
    WHILE (sym. id = Symbol.docComment) DO
      sym := sym. next
    END;
    
    (*S: Module = "MODULE" mp_ident Flags ";" [ImportList] Body ".".  *)
    module := CheckSym (Symbol.module);
    nameSym := sym;
    name := MultiPartIdent (headName);
    IF (ast. expectedModuleName # NIL) &
       (headName^ # ast. expectedModuleName^) THEN
      Err (fileNameMismatch, nameSym);
      ErrStringAttrib ("name", ast. expectedModuleName^)
    END;
    
    lastIdentDef := name;
    moduleFlags := Flags (AST.flagsModule);
    scolon := CheckSym (Symbol.semicolon);
    IF (sym. id = Symbol.import) THEN
      import := ImportList (headName)
    ELSE
      import := NIL
    END;
    IF ~(onlyParseImport IN parseOptions) THEN
      body := Body (0, headName);
      period := CheckSym (Symbol.period);
      eof := CheckSym (Symbol.endOfFile)
    ELSE
      body := NIL;
      period := NIL
    END;
    RETURN ast. Module (module, name, moduleFlags, scolon, 
                        import, body, period, headName)
  END Module;

BEGIN
  NEW (parserContext);
  Error.InitContext (parserContext, "OOC:Parser")
END OOC:Parser.
