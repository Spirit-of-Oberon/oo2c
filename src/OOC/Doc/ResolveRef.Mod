MODULE OOC:Doc:ResolveRef;

IMPORT
  Msg, Strings, ADT:Object, ADT:Object:Dictionary,
  OOC:Error, OOC:Doc, OOC:SymbolTable:Item, OOC:SymbolTable:Exports,
  OOC:Config:Repositories;
  
CONST
  refEmpty = 0;
  refHasMarkup = 1;
  invalidCharacter = 2;
  moduleNameExpected = 3;
  identExpected = 4;
  endOfString = 5;
  unresolvedIdent = 6;
  notModule = 7;
  notConstDecl = 8;
  notFieldDecl = 9;
  notParameterDecl = 10;
  notProcDecl = 11;
  notTypeDecl = 12;
  notVarDecl = 13;
  refToPrivateDecl = 14;
  
TYPE
  ErrorContext = POINTER TO ErrorContextDesc;
  ErrorContextDesc = RECORD  (* stateless *)
    (Error.ContextDesc)
  END;

VAR
  resolveContext: ErrorContext;


PROCEDURE (context: ErrorContext) GetTemplate* (msg: Error.Msg; VAR templ: Error.LString);
  VAR
    t: ARRAY 128 OF Error.LChar;
  BEGIN
    CASE msg. code OF
    | refEmpty:
      t := "Reference command is empty"
    | refHasMarkup:
      t := "Reference command contains markup commands"
    | invalidCharacter:
      t := "Invalid character `${char}' in reference command"
    | moduleNameExpected:
      t := "Expected module name, but found `${char}'"
    | identExpected:
      t := "Expected identifier, but found `${char}'"
    | endOfString:
      t := "Expected identifier at end of reference command"
    | unresolvedIdent:
      t := "Could not resolve identifier `${ident}'"
    | notModule:
      t := "The referenced declaration is not a module"
    | notConstDecl:
      t := "The referenced declaration is not a constant"
    | notFieldDecl:
      t := "The referenced declaration is not a record field"
    | notParameterDecl:
      t := "The referenced declaration is not a parameter"
    | notProcDecl:
      t := "The referenced declaration is not a procedure"
    | notTypeDecl:
      t := "The referenced declaration is not a type"
    | notVarDecl:
      t := "The referenced declaration is not a variable"
    | refToPrivateDecl:
      t := "The referenced declaration is not exported"
    END;
    context. BaseTemplate (msg, t, templ)
  END GetTemplate;


PROCEDURE ParseRef (ref: Doc.OberonRef; errList: Error.List;
                    VAR external: BOOLEAN; VAR tokenList: Doc.InlineList): BOOLEAN;
  VAR
    currElement: Doc.InlineElement;
    currText: Doc.Text;
    currPos: LONGINT;
    char: CHAR;
    lastError: Error.Msg;
  
  PROCEDURE Err (code: Error.Code);
    VAR
      pos: Doc.Element;
    BEGIN
      IF (ref. inlineText = NIL) OR ~(ref. inlineText IS Doc.Text) THEN
        pos := ref
      ELSE
        pos := ref. inlineText
      END;
      lastError := Error.New (resolveContext, code);
      lastError. SetIntAttrib ("pos", pos. pos. char);
      lastError. SetIntAttrib ("line", pos. pos. line);
      lastError. SetIntAttrib ("column", pos. pos. column);
      errList. Append (lastError);
      currText := NIL                    (* abort parsing *)
    END Err;
  
  PROCEDURE HasMarkup (ptr: Doc.InlineElement): BOOLEAN;
    BEGIN
      WHILE (ptr # NIL) DO
        IF ~(ptr IS Doc.Text) THEN
          RETURN TRUE
        END;
        ptr := ptr. nextInline
      END;
      RETURN FALSE
    END HasMarkup;

  PROCEDURE NextChar;
    BEGIN
      INC (currPos);
      char := currText. string[currPos];
      WHILE (currText # NIL) & (char = 0X) DO
        currElement := currElement. nextInline;
        currPos := 0;
        IF (currElement = NIL) THEN
          currText := NIL
        ELSE
          currText := currElement(Doc.Text);
          char := currText. string[currPos]
        END
      END
    END NextChar;
  
  PROCEDURE S;
    BEGIN
      WHILE (currText # NIL) & (char <= " ") DO
        NextChar
      END
    END S;

  PROCEDURE SetCharAttribute;
    VAR
      str: ARRAY 2 OF CHAR;
    BEGIN
      str[0] := char; str[1] := 0X;
      lastError. SetStringAttrib ("char", Msg.GetStringPtr (str))
    END SetCharAttribute;
  
  PROCEDURE Ident (isModule: BOOLEAN);
    VAR
      str: ARRAY 1024 OF CHAR;
      i: LONGINT;
      
    PROCEDURE Valid (ch: CHAR): BOOLEAN;
      BEGIN
        CASE ch OF
        | "a".."z", "A".."Z", "0".."9", "_":
          RETURN TRUE
        | ":":
          RETURN isModule
        ELSE
          RETURN FALSE
        END
      END Valid;
    
    BEGIN
      IF (currText = NIL) THEN
        Err (endOfString)
      ELSIF Valid (char) THEN
        i := 0;
        REPEAT
          IF (i < LEN (str)-1) THEN
            str[i] := char;
            INC (i)
          END;
          NextChar
        UNTIL (currText = NIL) OR ~Valid (char);
        str[i] := 0X;
        tokenList. Append (Doc.NewText (str, ref. inlineText. pos))
        
      ELSIF isModule THEN
        Err (moduleNameExpected); SetCharAttribute
      ELSE
        Err (identExpected); SetCharAttribute
      END
    END Ident;
  
  BEGIN
    lastError := NIL;
    external := FALSE;
    tokenList := Doc.NewInlineList();
    
    currElement := ref. inlineText;
    IF (currElement = NIL) THEN
      Err (refEmpty);
    ELSIF HasMarkup (currElement) THEN
      Err (refHasMarkup)
    ELSE
      currText := currElement(Doc.Text);
      currPos := 0;
      char := currText. string[currPos];
      
      (* syntax: S ["*" S mident | ident] S {"." S ident S} *)
      S;
      IF (char = "*") THEN
        external := TRUE;
        NextChar;
        S;
        Ident (TRUE)
      ELSE
        Ident (FALSE)
      END;
      S;
      WHILE (currText # NIL) & (char = ".") DO
        NextChar;
        S;
        Ident (FALSE);
        S
      END;
      
      IF (currText # NIL) THEN
        Err (invalidCharacter); SetCharAttribute
      END
    END;
    RETURN (lastError = NIL)
  END ParseRef;

PROCEDURE Resolve* (symTab: Item.Module;
                    repositories: Repositories.Section;
                    errList: Error.List);
  VAR
    interfaceCache: Dictionary.Dictionary;
    
  PROCEDURE ResolveRef (doc: Doc.Document;
                        ref: Doc.OberonRef;
                        refererDecl: Item.Declaration;
                        identificationContext: Item.Item;
                        nsRecord: Item.Namespace);
    VAR
      decl: Item.Declaration;
      ns: Item.Namespace;
      tokenList: Doc.InlineList;
      external: BOOLEAN;
      part, ptr: Doc.InlineElement;
      lastError: Error.Msg;
      module, id: Item.NameString;
      len: LONGINT;

    PROCEDURE GetName (): Item.Name;
      VAR
        n: Item.Name;
      BEGIN
        NEW (n);
        Item.InitName (n, part(Doc.Text). string, ref. pos. char,
                       ref. pos. line, ref. pos. column);
        RETURN n
      END GetName;
    
    PROCEDURE Err (code: Error.Code);
      VAR
        pos: Doc.Element;
      BEGIN
        pos := ref. inlineText;
        lastError := Error.New (resolveContext, code);
        lastError. SetIntAttrib ("pos", pos. pos. char);
        lastError. SetIntAttrib ("line", pos. pos. line);
        lastError. SetIntAttrib ("column", pos. pos. column);
        errList. Append (lastError)
      END Err;

    PROCEDURE Exported (decl: Item.Declaration): BOOLEAN;
      VAR
        module: Item.Module;
        obj: Object.Object;
        exports: Dictionary.Dictionary;
      BEGIN
        IF (decl IS Item.Module) THEN
          (* export flags don't apply to modules; an module is always public *)
          RETURN TRUE
        ELSE
          module := decl. Module();
          IF ~interfaceCache. HasKey (module) THEN
            interfaceCache. SetValue (module, Exports.GetExports (module))
          END;
          obj := interfaceCache. GetValue (module);
          exports := obj(Dictionary.Dictionary);
          RETURN exports. HasKey (decl)
        END
      END Exported;
    
    BEGIN
      IF ParseRef (ref, errList, external, tokenList) THEN
        part := tokenList. head;
        
        IF external THEN
          (* reference to an external declaration; don't try to locate the
             declaration in the internal symbol table; instead, use the given
             string as canonical name of the referenced declaration *)
          module := part(Doc.Text). string;
          
          len := 0;
          ptr := part. nextInline;
          WHILE (ptr # NIL) DO
            INC (len, Strings.Length (ptr(Doc.Text). string^)+1);
            ptr := ptr. nextInline
          END;
          
          NEW (id, len);
          COPY ("", id^);
          ptr := part. nextInline;
          WHILE (ptr # NIL) DO
            Strings.Append (ptr(Doc.Text). string^, id^);
            ptr := ptr. nextInline;
            IF (ptr # NIL) THEN
              Strings.Append (".", id^)
            END
          END;
          
          ref. SetExternalTarget (module, id)
        ELSE
          decl := NIL;
          IF (nsRecord # NIL) &
             (ref. mark = Doc.markOberonField) & 
             (tokenList. head. nextInline = NIL) THEN
            (* if we are within a record, and the reference command is
               `ofield', and if the reference is a single symbol, the try to
               resolve the identifier in the record context  *)
            decl := nsRecord. Identify (identificationContext, GetName(), TRUE)
          END;
          IF (decl = NIL) THEN
            (* if we haven't found in the out-of-band namespace, use the
               standard namespace associated with the current context *)
            ns := identificationContext. Namespace();
            decl := ns. Identify (identificationContext, GetName(), TRUE)
          END;
          IF (decl # NIL) & (decl IS Item.Import) THEN
            (* replace import with the imported module *)
            doc. AddUsedImport (decl);
            decl := decl(Item.Import). externalSymTab
          END;

          WHILE (decl # NIL) & (part. nextInline # NIL) DO
            part := part. nextInline;
            ns := decl. GetEmbeddedNamespace (TRUE);
            decl := ns. Identify (identificationContext, GetName(), TRUE)
          END;

          IF (decl = NIL) THEN
            Err (unresolvedIdent);
            lastError. SetStringAttrib ("ident", 
                                    Msg.GetStringPtr (part(Doc.Text). string^))
          ELSE
            CASE ref. mark OF
            | Doc.markOberonModule:
              IF ~(decl IS Item.Module) THEN
                Err (notModule)
              END
            | Doc.markOberonConst:
              IF ~(decl IS Item.ConstDecl) THEN
                Err (notConstDecl)
              END
            | Doc.markOberonField:
              IF ~(decl IS Item.FieldDecl) THEN
                Err (notFieldDecl)
              END
            | Doc.markOberonParam:
              IF ~(decl IS Item.VarDecl) OR
                 ~decl(Item.VarDecl). isParameter THEN
                Err (notParameterDecl)
              END
            | Doc.markOberonProc:
              IF ~(decl IS Item.ProcDecl) THEN
                Err (notProcDecl)
              END
            | Doc.markOberonType:
              IF ~(decl IS Item.TypeDecl) THEN
                Err (notTypeDecl)
              END
            | Doc.markOberonVar:
              IF ~(decl IS Item.VarDecl) OR decl(Item.VarDecl). isParameter THEN
                Err (notVarDecl)
              END
            END;
            
            IF ~Exported (decl) & Exported (refererDecl) THEN
              Err (refToPrivateDecl)
            END;
            
            ref. SetTarget (decl)
          END
        END
      END
    END ResolveRef;
  
  PROCEDURE ResolveDoc (doc: Doc.Document; refererDecl: Item.Declaration;
                        identificationContext: Item.Item;
                        nsRecord: Item.Namespace);
                        
    PROCEDURE ResolveInlineList (inlineList: Doc.InlineElement);
      VAR
        ptr: Doc.InlineElement;
      BEGIN
        ptr := inlineList;
        WHILE (ptr # NIL) DO
          WITH ptr: Doc.Glyph DO
            (* nothing *)
          | ptr: Doc.Text DO
            (* nothing *)
          | ptr: Doc.OberonRef DO
            ResolveRef (doc, ptr, refererDecl, identificationContext, nsRecord)
          | ptr: Doc.MarkedInline DO
            ResolveInlineList (ptr. inlineText)
          | ptr: Doc.Email DO
            ResolveInlineList (ptr. address);
            ResolveInlineList (ptr. displayed)
          | ptr: Doc.Uref DO
            ResolveInlineList (ptr. url);
            ResolveInlineList (ptr. text);
            ResolveInlineList (ptr. replacement)
          END;
          ptr := ptr. nextInline
        END
      END ResolveInlineList;
    
    PROCEDURE ResolveBlockList (blockList: Doc.BlockElement);
      VAR
        ptr: Doc.BlockElement;
      BEGIN
        ptr := blockList;
        WHILE (ptr # NIL) DO
          WITH ptr: Doc.Paragraph DO
            ResolveInlineList (ptr. inlineText)
          | ptr: Doc.Example DO
            ResolveInlineList (ptr. inlineText)
          | ptr: Doc.PreCond DO
            ResolveBlockList (ptr. blockList)
          | ptr: Doc.PostCond DO
            ResolveBlockList (ptr. blockList)
          | ptr: Doc.Item DO
            ResolveBlockList (ptr. blockList)
          | ptr: Doc.Itemize DO
            ResolveInlineList (ptr. mark);
            ResolveBlockList (ptr. text);
            ResolveBlockList (ptr. itemList)
          | ptr: Doc.FirstColumn DO
            ResolveInlineList (ptr. inlineText)
          | ptr: Doc.TableRow DO
            ResolveBlockList (ptr. firstColumnList);
            ResolveBlockList (ptr. item)
          | ptr: Doc.Table DO
            ResolveBlockList (ptr. rowList)
          END;
          ptr := ptr. nextBlock
        END
      END ResolveBlockList;
    
    BEGIN
      ResolveBlockList (doc. blockList);
      ResolveInlineList (doc. summary)
    END ResolveDoc;
  
  PROCEDURE RecResolve (item: Item.Item; identificationContext: Item.Item;
                        nsRecord: Item.Namespace);
    VAR
      ptr: Item.Item;
      ns: Item.Namespace;
    BEGIN
      IF (item IS Item.Declaration) THEN

        IF (item IS Item.ProcDecl) THEN
          identificationContext := item
        ELSE
          ns := item(Item.Declaration). GetEmbeddedNamespace (FALSE);
          IF (ns # NIL) THEN
            nsRecord := ns
          END
        END;
        
        IF (item(Item.Declaration). docString # NIL) THEN
          ResolveDoc (item(Item.Declaration). docString, 
                      item(Item.Declaration),
                      identificationContext,
                      nsRecord)
        END
        
      ELSIF (item IS Item.Record) THEN
        nsRecord := item. Namespace()
      END;
      
      ptr := item. nestedItems;
      WHILE (ptr # NIL) DO
        RecResolve (ptr, identificationContext, nsRecord);
        ptr := ptr. nextNested
      END
    END RecResolve;
  
  BEGIN
    interfaceCache := Dictionary.New();
    RecResolve (symTab, symTab, NIL)
  END Resolve;

BEGIN
  NEW (resolveContext);
  Error.InitContext (resolveContext, "OOC:Doc:ResolveRef")
END OOC:Doc:ResolveRef.
