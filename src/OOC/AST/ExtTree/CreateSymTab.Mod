(* 	$Id$	 *)
MODULE OOC:AST:ExtTree:CreateSymTab;
(*  Creates symbol table from abstract syntax tree of module `ExtTree'.
    Copyright (C) 2000-2003  Michael van Acken

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
  Object, Exception, URI, ParserURI := URI:Parser,
  OOC:Scanner:Symbol, OOC:AST, OOC:Scanner:BasicList, OOC:AST:ExtTree,
  Sym := OOC:SymbolTable, OOC:SymbolTable:Predef,
  SymTabBuilder := OOC:SymbolTable:Builder;


TYPE
  Visitor* = POINTER TO VisitorDesc;
  VisitorDesc = RECORD
    (ExtTree.VisitorDesc)
    stb: SymTabBuilder.Builder;
    (* the builder used to create the symbol table entries *)
    parent: Sym.Item;
    (* when calling a visit method, this field holds a reference to the
       current parent of newly created symbol table entries *)
    type: Sym.Type;
    (* a visit method that creates a new type (or a type name), places
       the type object here *)
    root: Sym.Module;
    (* the root of the newly created symbol table; this is the result of
       @oproc{CreateSymTab} *)
    baseURI: URI.HierarchicalURI;
    (* any relative file names in the module are resolved relative to this
       base URI; currently, the only file names in question are the ones
       given in a module's LINK section *)
    rootURI: URI.HierarchicalURI;
    (* once expanded relative to @ofield{baseURI}, all URIs are made relative
       again with respect to this URI; `rootURI' is currently the base
       directory of the repository of the module *)
  END;


PROCEDURE GetName* (node: AST.Node): Sym.Name;
  VAR
    sym: BasicList.Symbol;
    name: Sym.Name;
  BEGIN
    WITH node: ExtTree.Terminal DO
      sym := node. sym
    | node: ExtTree.IdentDef DO
      sym := node. ident. sym
    END;
    NEW (name);
    Sym.InitName (name, sym. str, sym. pos, sym. line, sym. column);
    RETURN name
  END GetName;

PROCEDURE GetPosition (node: AST.Node): Sym.Position;
  VAR
    sym: BasicList.Symbol;
    position: Sym.Position;
  BEGIN
    WITH node: ExtTree.Terminal DO
      sym := node. sym
    | node: ExtTree.IdentDef DO
      sym := node. ident. sym
    | node: ExtTree.Operator DO
      ASSERT(node.op.sym.id = Symbol.period);
      sym := node.right(ExtTree.Terminal).sym;
    END;
    NEW (position);
    Sym.InitPosition (position, sym. pos, sym. line, sym. column);
    RETURN position
  END GetPosition;

PROCEDURE ExportMark (id: AST.Node): Sym.ExportMark;
  BEGIN
    WITH id: ExtTree.IdentDef DO
      IF (id. mark = NIL) THEN
        RETURN Sym.nameNotExported
      ELSIF (id. mark. sym. str^ = "*") THEN
        RETURN Sym.nameExported
      ELSE (* (id. mark. sym. str^ = "-") *)
        RETURN Sym.nameExportedRO
      END
    END
  END ExportMark;

PROCEDURE EndOfType (t: AST.Node): Sym.ModulePos;
  VAR
    end: Sym.ModulePos;
  BEGIN
    IF (t = NIL) THEN
      RETURN -1
    ELSE
      WITH t: ExtTree.Terminal DO
        RETURN t. sym. pos+t. sym. len
      | t: ExtTree.Operator DO
        RETURN EndOfType (t. right)
      | t: ExtTree.ArrayType DO
        RETURN EndOfType (t. type)
      | t: ExtTree.RecordType DO
        RETURN EndOfType (t. end)
      | t: ExtTree.PointerType DO
        RETURN EndOfType (t. type)
      | t: ExtTree.ProcType DO
        IF (t. formalPars # NIL) THEN
          end := EndOfType (t. formalPars);
          IF (end = -1) THEN
            RETURN EndOfType (t. procedure)
          ELSE
            RETURN end
          END
        ELSE
          RETURN EndOfType (t. procedure)
        END
      | t: ExtTree.FormalPars DO
        IF (t. result # NIL) THEN
          RETURN EndOfType (t. result)
        ELSIF (t. rParen # NIL) THEN
          RETURN EndOfType (t. rParen)
        ELSE
          RETURN -1
        END
      | t: ExtTree.QualType DO
        RETURN EndOfType(t.rParen);
      END
    END
  END EndOfType;

PROCEDURE Accept (v: Visitor; node: AST.Node);
  VAR
    oldParent: Sym.Item;
  BEGIN
    oldParent := v. parent;
    node(ExtTree.Node). Accept (v);
    v. parent := oldParent
  END Accept;

PROCEDURE AcceptParent (v: Visitor; node: AST.Node; newParent: Sym.Item);
(* Like @oproc{Accept} above, but change the field @samp{v.parent} to 
   @oparam{newParent} before calling @oproc{Accept} for @oparam{node}.
   Afterwards, the old value of @samp{v.parent} is restored.  *)
  VAR
    oldParent: Sym.Item;
  BEGIN
    oldParent := v. parent;
    v. parent := newParent;
    node(ExtTree.Node). Accept (v);
    v. parent := oldParent
  END AcceptParent;

PROCEDURE GetType (v: Visitor; node: AST.Node): Sym.Type;
  VAR
    t: Sym.Type;
  BEGIN
    v. type := NIL;
    Accept (v, node);
    ASSERT (v. type # NIL);
    t := v. type;
    RETURN t
  END GetType;

PROCEDURE GetTypeParent (v: Visitor; node: AST.Node; newParent: Sym.Item): Sym.Type;
  VAR
    t: Sym.Type;
  BEGIN
    v. type := NIL;
    AcceptParent (v, node, newParent);
    ASSERT (v. type # NIL);
    t := v. type;
    RETURN t
  END GetTypeParent;

PROCEDURE AddFlags (item: Sym.Item; flags: ExtTree.Flags);
  VAR
    i: LONGINT;
    n: ExtTree.Node;
    l: ExtTree.NodeList;
  BEGIN
    IF (flags # NIL) THEN
      l := flags.flagList(ExtTree.NodeList);
      FOR i := 0 TO l. len-1 BY 2 DO
        n := l. n[i](ExtTree.Node);
        WITH n: ExtTree.Terminal DO
          item.AddFlag(GetName(n));
        END;
      END;
    END;
  END AddFlags;



PROCEDURE (v: Visitor) VisitNodeList* (nl: ExtTree.NodeList);
  BEGIN
    ASSERT (FALSE)  (* must use specialized code *)
  END VisitNodeList;

PROCEDURE (v: Visitor) VisitModule* (module: ExtTree.Module);
  VAR
    moduleDecl: Sym.Module;
    moduleName, name: Sym.Name;
    class: Sym.ModuleClass;
    callConv: Sym.CallConv;
    mf: ExtTree.ModuleFlags;
    uri: URI.URI;
    str, prefixOption, suffixOption: STRING;
    i, j: LONGINT;
    n: AST.Node;
    depList: Object.StringArrayPtr;
    chars: Object.CharsLatin1;
  BEGIN
    moduleName := GetName (module. name. nameList. n[0]);
    Sym.InitName (moduleName, module. moduleName, moduleName. pos, 
                   moduleName. line, moduleName. column);
    
    mf := NIL;
    class := Sym.mcStandard;
    callConv := Sym.callConvDefault;
    IF (module. flags # NIL) THEN
      FOR i := 0 TO module.flags.flagList.len-1 DO
        n := module. flags. flagList. n[i];
        WITH n: ExtTree.ModuleFlags DO
          mf := n;
          IF (mf. external. sym. str^ = "FOREIGN") THEN
            class := Sym.mcForeign
          ELSIF (mf. external. sym. str^ = "INTERFACE") THEN
            class := Sym.mcInterface
          END;
          str := mf. callConv. GetString (TRUE);
          callConv := Sym.StringToCallConv (str);
          
          v. stb. SetClass (class);
          
        | n: ExtTree.Terminal DO
          (* skip *)
        END;
      END;
    END;
    
    moduleDecl := v. stb. NewModule (moduleName, module. name. docString,
                                     class, callConv, module);
    IF (module. flags # NIL) THEN  (* process list of flag names *)
      FOR i := 0 TO module.flags.flagList.len-1 DO
        n := module. flags. flagList. n[i];
        WITH n: ExtTree.Terminal DO
          name := GetName(n);
          IF ("A" <= CAP(name.str[0])) & (CAP(name.str[0]) <= "Z") THEN
            (* only add flag names, and skip things like ";" *)
            moduleDecl.AddFlag(GetName(n));
          END;
        ELSE
          (* ignore *)
        END;
      END;
    END;
    IF (mf # NIL) & (mf. linkSections # NIL) THEN
      FOR i := 0 TO mf. linkSections. len-1 DO
        n := mf. linkSections. n[i];
        IF (n # NIL) THEN  (* skip empty section *)
          WITH n: ExtTree.LinkFileFlag DO
            str := n. fileName. GetString (TRUE);
            chars := str(Object.String8).CharsLatin1();
            TRY
              uri := ParserURI.NewURI (chars^, v. baseURI);
            CATCH Exception.ParseError:
              ASSERT(FALSE);
            END;
            ASSERT (uri # NIL);
            uri := uri. MakeRelative (v. rootURI);
            IF (n. prefixOpt # NIL) THEN
              prefixOption := n. prefixOpt. GetString (FALSE)
            ELSE
              prefixOption := NIL
            END;
            IF (n. suffixOpt # NIL) THEN
              suffixOption := n. suffixOpt. GetString (FALSE)
            ELSE
              suffixOption := NIL
            END;
            moduleDecl. AddLinkFile (uri(URI.HierarchicalURI),
                                     prefixOption, suffixOption);
            
          | n: ExtTree.LinkLibFlag DO
            str := n. libName. GetString (TRUE);
            IF (n. prefixOpt # NIL) THEN
              prefixOption := n. prefixOpt. GetString (FALSE)
            ELSE
              prefixOption := NIL
            END;
            IF (n. suffixOpt # NIL) THEN
              suffixOption := n. suffixOpt. GetString (FALSE)
            ELSE
              suffixOption := NIL
            END;
            IF (n. dependencies = NIL) THEN
              NEW (depList, 0);
            ELSE
              NEW (depList, n. dependencies. len DIV 2+1);
              FOR j := 0 TO n. dependencies. len-1 BY 2 DO
                depList[j DIV 2] := n. dependencies. n[j](ExtTree.Terminal). GetString (TRUE);
              END;
            END;
            moduleDecl. AddLinkLib (str, depList, prefixOption, suffixOption);
          ELSE
            (* ignore list of flags for now *)
          END;
        END;
      END;
    END;
    
    v. root := moduleDecl;
    IF (module. importList # NIL) THEN
      AcceptParent (v, module. importList, moduleDecl)
    END;
    IF (module. body # NIL) THEN (* no body if parsing stopped after IMPORT *)
      AcceptParent (v, module. body, moduleDecl)
    END;
  END VisitModule;

PROCEDURE (v: Visitor) VisitImportList* (importList: ExtTree.ImportList);
  VAR
    i: LONGINT;
  BEGIN
    FOR i := 0 TO importList. imports. len-1 BY 2 DO
      Accept (v, importList. imports. n[i])
    END
  END VisitImportList;

PROCEDURE (v: Visitor) VisitBody* (body: ExtTree.Body);
  VAR
    i: LONGINT;
  BEGIN
    FOR i := 0 TO body. declSeq. len-1 DO
      IF ~(body. declSeq. n[i] IS ExtTree.Terminal) THEN
        Accept (v, body. declSeq. n[i])
      END
    END
  END VisitBody;

PROCEDURE (v: Visitor) VisitImportDecl* (importDecl: ExtTree.ImportDecl);
  VAR
    import: Sym.Import;
    name, moduleName: Sym.Name;
    nameSym: BasicList.Symbol;
  BEGIN
    (* extract module name from import statment *)
    moduleName := GetName (importDecl. module. nameList. n[0]);
    Sym.InitName (moduleName, importDecl. moduleName, moduleName. pos, 
                   moduleName. line, moduleName. column);

    (* under which name is the module imported? *)
    nameSym := importDecl. module. nameList. 
                 n[importDecl. module. nameList. len-1](ExtTree.Terminal). sym;
    IF (importDecl. becomes # NIL) THEN
      name := GetName (importDecl. alias)
    ELSE
      name := GetName (importDecl. module. nameList.
                         n[importDecl. module. nameList. len-1])
    END;
    
    import := v. stb. NewImport (v. parent, name, nameSym. pos+nameSym. len,
                                 importDecl. module. docString, moduleName)
  END VisitImportDecl;

PROCEDURE (v: Visitor) VisitConstDecl* (constDecl: ExtTree.ConstDecl);
  VAR
    const: Sym.ConstDecl;
  BEGIN
    const := v. stb. NewConstDecl (
        v. parent, GetName (constDecl. identDef. ident),
        constDecl. semicolon(ExtTree.Terminal). sym. pos,
        ExportMark (constDecl. identDef), constDecl. identDef. docString,
        NIL, NIL, constDecl. expr);
    IF (constDecl.flags # NIL) THEN
      AddFlags(const, constDecl.flags);
    END;
  END VisitConstDecl;

PROCEDURE (v: Visitor) VisitTPSection* (tpSection: ExtTree.TPSection);
  VAR
    type: Sym.Type;
    typeDecl: Sym.TypeDecl;
    i: LONGINT;
  BEGIN
    type := GetType (v, tpSection.type);
    FOR i := 0 TO tpSection.identList.len-1 BY 2 DO
      typeDecl := v.stb.NewTypeDecl
          (v.parent, GetName(tpSection.identList.n[i]),
           EndOfType(tpSection.type), Sym.nameNotExported,
           tpSection.identList.n[i](ExtTree.IdentDef).docString, type, TRUE);
    END;
  END VisitTPSection;

PROCEDURE (v: Visitor) VisitTypeDecl* (typeDecl: ExtTree.TypeDecl);
  VAR
    type: Sym.TypeDecl;
    base: Sym.Type;
    typePars: Sym.TypePars;
    i: LONGINT;
  BEGIN
    IF (typeDecl.typePars = NIL) THEN
      base := GetType(v, typeDecl.type);
    ELSE
      typePars := v.stb.NewTypePars(v.parent);
      FOR i := 0 TO typeDecl.typePars.tpSections.len-1 BY 2 DO
        AcceptParent(v, typeDecl.typePars.tpSections.n[i], typePars);
      END;
      base := GetTypeParent(v, typeDecl.type, typePars);
      ASSERT(base.namingDecl = NIL);
      base.SetTypePars(typePars);
    END;
    type := v. stb. NewTypeDecl
        (v.parent, GetName(typeDecl.identDef.ident),
         EndOfType(typeDecl.type), ExportMark(typeDecl.identDef), 
         typeDecl.identDef.docString, base, FALSE);
    IF (typeDecl.flags # NIL) THEN
      AddFlags(type, typeDecl.flags);
    END;
  END VisitTypeDecl;

PROCEDURE (v: Visitor) VisitVarDecl* (varDecl: ExtTree.VarDecl);
  VAR
    type: Sym.Type;
    var: Sym.VarDecl;
    i: LONGINT;
    flags: AST.Node;
  BEGIN
    type := GetType (v, varDecl. type);
    FOR i := 0 TO varDecl. identList. len-1 BY 3 DO
      var := v. stb. NewVarDecl (v. parent,
        GetName (varDecl. identList. n[i](ExtTree.IdentDef). ident),
        EndOfType (varDecl. type),
        ExportMark (varDecl. identList. n[i]), 
        varDecl. identList. n[i](ExtTree.IdentDef). docString,
        FALSE, FALSE, FALSE, type);
      flags := varDecl. identList. n[i+1];
      IF (flags # NIL) THEN
        AddFlags(var, flags(ExtTree.Flags));
      END;
    END
  END VisitVarDecl;

PROCEDURE (v: Visitor) VisitReceiver* (receiver: ExtTree.Receiver);
  VAR
    type: Sym.Type;
    var: Sym.VarDecl;
    alias: Sym.TypeDecl;
    i: LONGINT;
    nodes: AST.NodeArray;
  BEGIN
    type := GetType (v, receiver. type);
    var := v. stb. NewVarDecl (v. parent, 
      GetName (receiver. ident), EndOfType (receiver. type),
      Sym.nameNotExported, receiver. ident. docString,
      TRUE, TRUE, receiver. var # NIL, type);

    IF (receiver.lParenAlias # NIL) THEN
      var.hasAliasList := TRUE;
      nodes := receiver.aliasList.n;
      FOR i := 0 TO receiver.aliasList.len-1 BY 2 DO
        alias := v.stb.NewTypeDecl
            (v.parent, GetName(nodes[i]), EndOfType(nodes[i]),
             Sym.nameNotExported, NIL, NIL, FALSE);
      END;
    END;
  END VisitReceiver;

PROCEDURE (v: Visitor) VisitFPSection* (fpSection: ExtTree.FPSection);
  VAR
    type: Sym.Type;
    var: Sym.VarDecl;
    i: LONGINT;
    flags: AST.Node;
  BEGIN
    type := GetType (v, fpSection. type);
    FOR i := 0 TO fpSection. identList. len-1 BY 3 DO
      var := v. stb. NewVarDecl (v. parent,
        GetName (fpSection. identList. n[i]),
        EndOfType (fpSection. type), Sym.nameNotExported,
        fpSection. identList. n[i](ExtTree.IdentDef). docString,
        TRUE, FALSE, fpSection. var # NIL, type);
      flags := fpSection. identList. n[i+1];
      IF (flags # NIL) THEN
        AddFlags(var, flags(ExtTree.Flags));
      END;
    END
  END VisitFPSection;

PROCEDURE (v: Visitor) VisitProcDecl* (procDecl: ExtTree.ProcDecl);
  VAR
    proc: Sym.ProcDecl;
    procClass: SHORTINT;
    type: Sym.Type;
    fpar: ExtTree.FormalPars;
    formalPars: Sym.FormalPars;
    endPos: Sym.ModulePos;
    i: LONGINT;
    nodePtr: AST.Node;

  PROCEDURE ParseFlags (proc: Sym.ProcDecl; flags: ExtTree.NodeList);
    VAR
      i: LONGINT;
      n: ExtTree.Node;
    BEGIN
      FOR i := 0 TO flags. len-1 BY 2 DO
        n := flags. n[i](ExtTree.Node);
        WITH n: ExtTree.Terminal DO
          CASE n.sym.id OF
          | Symbol.stringSingle, Symbol.stringDouble:
            proc. SetLinkName (n. GetString (TRUE));
          ELSE
            proc.AddFlag(GetName(n));
          END;
        END;
      END;
    END ParseFlags;
  
  BEGIN
    endPos := EndOfType (procDecl. formalPars);
    IF (endPos < 0) THEN
      endPos := EndOfType (procDecl. identDef. ident)
    END;

    IF (procDecl.receiver = NIL) THEN
      procClass := Sym.standardProc;
    ELSIF Predef.IsStaticMethod(procDecl.identDef.ident.sym.str^) THEN
      procClass := Sym.staticMethod;
    ELSE
      procClass := Sym.virtualMethod;
    END;
    proc := v. stb. NewProcDecl (v. parent, 
      GetName (procDecl. identDef. ident), endPos,
      ExportMark (procDecl. identDef),
      procDecl. identDef. docString,
      procClass, procDecl. arrow # NIL, procDecl);
    
    formalPars := v. stb. NewFormalPars (proc,
                                         GetPosition (procDecl. proc));
    IF (procDecl. formalPars # NIL) &
       (procDecl. formalPars(ExtTree.FormalPars). result # NIL) THEN
      formalPars.SetResultType
          (GetTypeParent(v, procDecl.formalPars(ExtTree.FormalPars).result,
                         formalPars));
    END;
    proc. formalPars := formalPars;

    IF (procDecl. receiver # NIL) THEN
      AcceptParent (v, procDecl. receiver, formalPars)
    END;
    IF (procDecl. formalPars # NIL) THEN
      fpar := procDecl. formalPars(ExtTree.FormalPars);
      AddFlags(formalPars, fpar.flags);
      IF (fpar. fpSections # NIL) THEN
        FOR i := 0 TO fpar. fpSections. len-1 BY 2 DO
          nodePtr := fpar. fpSections. n[i];
          WITH nodePtr: ExtTree.Terminal DO (* rest parameter *)
            ASSERT (nodePtr. sym. str^ = "...");
            formalPars. EnableRestParameters()
          ELSE
            AcceptParent (v, nodePtr, formalPars)
          END
        END
      END;

      IF (fpar.raisesList # NIL) THEN
        NEW(formalPars.raises, (fpar.raisesList.len+1) DIV 2);
        FOR i := 0 TO fpar. raisesList. len-1 BY 2 DO
          nodePtr := fpar. raisesList. n[i];
          type := GetType(v, nodePtr);
          formalPars.raises[i DIV 2] :=
              v.stb.NewExceptionName(formalPars, type);
        END
      ELSE
        NEW(formalPars.raises, 0);
      END;
    END;
    IF (procDecl. flags # NIL) THEN
      ParseFlags (proc, procDecl. flags. flagList(ExtTree.NodeList));
    END;
    
    IF (procDecl. body # NIL) THEN
      AcceptParent (v, procDecl. body, proc)
    END
  END VisitProcDecl;

PROCEDURE (v: Visitor) VisitFieldList* (fieldList: ExtTree.FieldList);
  VAR
    field: Sym.FieldDecl;
    type: Sym.Type;
    i: LONGINT;
    flags: AST.Node;
  BEGIN
    type := GetType (v, fieldList. type);
    FOR i := 0 TO fieldList. identList. len-1 BY 3 DO
      field := v. stb. NewFieldDecl (v. parent,
        GetName (fieldList. identList. n[i](ExtTree.IdentDef). ident),
        EndOfType (fieldList. type),
        ExportMark (fieldList. identList. n[i](ExtTree.IdentDef)), 
        fieldList. identList. n[i](ExtTree.IdentDef). docString,
        type);
      flags := fieldList. identList. n[i+1];
      IF (flags # NIL) THEN
        AddFlags(field, flags(ExtTree.Flags));
      END;
    END
  END VisitFieldList;


PROCEDURE (v: Visitor) VisitTerminal* (terminal: ExtTree.Terminal);
  BEGIN
    v. type := v. stb. NewTypeName (v. parent, GetPosition (terminal), 
                                    NIL, GetName (terminal))
  END VisitTerminal;

PROCEDURE (v: Visitor) VisitOperator* (operator: ExtTree.Operator);
  BEGIN
    v. type := v. stb. NewTypeName (v. parent, GetPosition (operator. left),
                           GetName (operator. left), GetName (operator. right))
  END VisitOperator;

PROCEDURE (v: Visitor) VisitRecordType* (recordType: ExtTree.RecordType);
  VAR
    record: Sym.Record;
    baseType: Sym.Type;
    i: LONGINT;
  BEGIN
    IF (recordType. baseType # NIL) THEN
      baseType := GetType (v, recordType. baseType);
    ELSE
      baseType := NIL
    END;
    record := v. stb. NewRecord (v. parent, GetPosition (recordType. record),
                                 baseType);
    AddFlags(record, recordType.flags);
    FOR i := 0 TO recordType. fieldLists. len-1 BY 2 DO
      IF (recordType. fieldLists. n[i] # NIL) THEN
        AcceptParent (v, recordType. fieldLists. n[i], record)
      END
    END;
    v. type := record
  END VisitRecordType;

PROCEDURE (v: Visitor) VisitPointerType* (pointerType: ExtTree.PointerType);
  BEGIN
    v. type := v. stb. NewPointer (v. parent,
                                   GetPosition (pointerType. pointer),
                                   GetType (v, pointerType. type));
    AddFlags(v.type, pointerType.flags);
  END VisitPointerType;

PROCEDURE (v: Visitor) VisitArrayType* (arrayType: ExtTree.ArrayType);
  VAR
    array: Sym.Array;
    baseType: Sym.Type;
    i: LONGINT;
    pos: Sym.Position;
  BEGIN
    IF (arrayType. exprList. len > 0) THEN
      baseType := GetType (v, arrayType. type);
      FOR i := arrayType. exprList. len-1 TO 0 BY -2 DO
        IF (i = 0) THEN
          pos := GetPosition (arrayType. array);
        ELSE
          pos := GetPosition (arrayType. exprList. n[i-1]);
        END;
        baseType := v. stb. NewArray
            (v. parent,
             pos,
             FALSE,
             arrayType. exprList. n[i],
             baseType);
        AddFlags(baseType, arrayType.flags);
      END;
      array := baseType(Sym.Array)
    ELSE
      array := v. stb. NewArray (v. parent, GetPosition (arrayType. array),
                                 TRUE, NIL, GetType (v, arrayType. type));
      AddFlags(array, arrayType.flags);
    END;
    v. type := array
  END VisitArrayType;

PROCEDURE (v: Visitor) VisitProcType* (procType: ExtTree.ProcType);
  VAR
    fpar: ExtTree.FormalPars;
    formalPars: Sym.FormalPars;
    i: LONGINT;
    nodePtr: AST.Node;
    type: Sym.Type;
  BEGIN
    formalPars := v. stb. NewFormalPars (v. parent, 
                                      GetPosition (procType. procedure));
    IF (procType. formalPars # NIL) &
       (procType. formalPars(ExtTree.FormalPars). result # NIL) THEN
      formalPars.SetResultType
          (GetTypeParent(v, procType.formalPars(ExtTree.FormalPars).result,
                         formalPars));
    END;
    IF (procType.formalPars # NIL) THEN
      AddFlags(formalPars, procType.formalPars(ExtTree.FormalPars).flags);
    END;
    IF (procType. formalPars # NIL) THEN
      fpar := procType. formalPars(ExtTree.FormalPars);
      IF (fpar. fpSections # NIL) THEN
        FOR i := 0 TO fpar. fpSections. len-1 BY 2 DO
          AcceptParent (v, fpar. fpSections. n[i], formalPars)
        END;
      END;
      
      IF (fpar.raisesList # NIL) THEN
        NEW(formalPars.raises, (fpar.raisesList.len+1) DIV 2);
        FOR i := 0 TO fpar. raisesList. len-1 BY 2 DO
          nodePtr := fpar. raisesList. n[i];
          type := GetType(v, nodePtr);
          formalPars.raises[i DIV 2] :=
              v.stb.NewExceptionName(formalPars, type);
        END
      ELSE
        NEW(formalPars.raises, 0);
      END;
    END;
    v. type := formalPars
  END VisitProcType;

PROCEDURE (v: Visitor) VisitQualType* (qualType: ExtTree.QualType);
  VAR
    baseType: Sym.Type;
    arguments: Sym.TypeRefArray;
    i: LONGINT;
  BEGIN
    baseType := GetType(v, qualType.qualident);
    NEW(arguments, (qualType.arguments.len+1) DIV 2);
    FOR i := 0 TO qualType.arguments.len-1 BY 2 DO
      Sym.InitTypeRef(arguments[i DIV 2],
                      GetType(v, qualType.arguments.n[i]));
    END;
    v.type := v.stb.NewQualType(v.parent,
                                GetPosition(qualType.qualident),
                                baseType, arguments);
  END VisitQualType;


PROCEDURE CreateSymTab* (module: AST.Node; stb: SymTabBuilder.Builder;
                         libraryName: STRING;
                         baseURI, rootURI: URI.HierarchicalURI): Sym.Module;
(**Creates a symbol table from the abstract syntax tree in @oparam{module}.
   The elements of the symbol table are created by calling appropriate 
   factory methods of @oparam{stb}.  Result is the root object of the newly
   created symbol table.

   The field @ofield{Sym.Module.libraryName} is set to @oparam{libraryName}.
   *)
  VAR
    v: Visitor;
  BEGIN
    NEW (v);
    v. stb := stb;
    v. parent := NIL;
    v. type := NIL;
    v. root := NIL;
    v. baseURI := baseURI;
    v. rootURI := rootURI;
    Accept (v, module);
    v.root.SetLibraryName(libraryName);
    stb. Finalize (v. root);
    RETURN v. root
  END CreateSymTab;

END OOC:AST:ExtTree:CreateSymTab.
