(* 	$Id$	 *)
MODULE OOC:AST:ExtTree:CreateSymTab;
(*  Creates symbol table from abstract syntax tree of module `ExtTree'.
    Copyright (C) 2000  Michael van Acken

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
  OOC:AST, OOC:Scanner:Builder:BasicList, OOC:AST:ExtTree,
  OOC:SymbolTable:Item,
  SymTabBuilder := OOC:SymbolTable:Builder;


TYPE
  Visitor* = POINTER TO VisitorDesc;
  VisitorDesc = RECORD
    (ExtTree.VisitorDesc)
    stb: SymTabBuilder.Builder;
    (* the builder used to create the symbol table entries *)
    parent: Item.Item;
    (* when calling a visit method, this field holds a reference to the
       current parent of newly created symbol table entries *)
    type: Item.Type;
    (* a visit method that creates a new type (or a type name), places
       the type object here *)
    root: Item.Module;
    (* the root of the newly created symbol table; this is the result of
       @oproc{CreateSymTab} *)
  END;


PROCEDURE GetName (node: AST.Node): Item.Name;
  VAR
    sym: BasicList.Symbol;
    name: Item.Name;
  BEGIN
    WITH node: ExtTree.Terminal DO
      sym := node. sym
    | node: ExtTree.IdentDef DO
      sym := node. ident. sym
    END;
    NEW (name);
    Item.InitName (name, sym. str, sym. pos, sym. line, sym. column);
    RETURN name
  END GetName;

PROCEDURE GetPosition (node: AST.Node): Item.Position;
  VAR
    sym: BasicList.Symbol;
    position: Item.Position;
  BEGIN
    WITH node: ExtTree.Terminal DO
      sym := node. sym
    | node: ExtTree.IdentDef DO
      sym := node. ident. sym
    END;
    NEW (position);
    Item.InitPosition (position, sym. pos, sym. line, sym. column);
    RETURN position
  END GetPosition;

PROCEDURE ExportMark (id: AST.Node): Item.ExportMark;
  BEGIN
    WITH id: ExtTree.IdentDef DO
      IF (id. mark = NIL) THEN
        RETURN Item.nameNotExported
      ELSIF (id. mark. sym. str^ = "*") THEN
        RETURN Item.nameExported
      ELSIF (id. mark. sym. str^ = "-") THEN
        RETURN Item.nameExportedRO
      ELSE
      END
    END
  END ExportMark;

PROCEDURE EndOfType (t: AST.Node): Item.ModulePos;
  VAR
    end: Item.ModulePos;
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
      END
    END
  END EndOfType;

PROCEDURE Accept (v: Visitor; node: AST.Node);
  VAR
    oldParent: Item.Item;
  BEGIN
    oldParent := v. parent;
    node(ExtTree.Node). Accept (v);
    v. parent := oldParent
  END Accept;

PROCEDURE AcceptParent (v: Visitor; node: AST.Node; newParent: Item.Item);
(* Like @oproc{Accept} above, but change the field @samp{v.parent} to 
   @oparam{newParent} before calling @oproc{Accept} for @oparam{node}.
   Afterwards, the old value of @samp{v.parent} is restored.  *)
  VAR
    oldParent: Item.Item;
  BEGIN
    oldParent := v. parent;
    v. parent := newParent;
    node(ExtTree.Node). Accept (v);
    v. parent := oldParent
  END AcceptParent;

PROCEDURE GetType (v: Visitor; node: AST.Node): Item.Type;
  VAR
    t: Item.Type;
  BEGIN
    v. type := NIL;
    Accept (v, node);
    ASSERT (v. type # NIL);
    t := v. type;
    RETURN t
  END GetType;



PROCEDURE (v: Visitor) VisitNodeList* (nl: ExtTree.NodeList);
  BEGIN
    ASSERT (FALSE)  (* must use specialized code *)
  END VisitNodeList;

PROCEDURE (v: Visitor) VisitModule* (module: ExtTree.Module);
  VAR
    moduleDecl: Item.Module;
    moduleName: Item.Name;
  BEGIN
    moduleName := GetName (module. name. nameList. n[0]);
    Item.InitName (moduleName, module. moduleName, moduleName. pos, 
                   moduleName. line, moduleName. column);
    moduleDecl := v. stb. NewModule (moduleName, module. name. docString);
    v. root := moduleDecl;
    
    IF (module. importList # NIL) THEN
      AcceptParent (v, module. importList, moduleDecl)
    END;
    AcceptParent (v, module. body, moduleDecl)
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
    import: Item.Import;
    name, moduleName: Item.Name;
    nameSym: BasicList.Symbol;
  BEGIN
    (* extract module name from import statment *)
    moduleName := GetName (importDecl. module. nameList. n[0]);
    Item.InitName (moduleName, importDecl. moduleName, moduleName. pos, 
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
    const: Item.ConstDecl;
  BEGIN
    const := v. stb. NewConstDecl (v. parent, 
      GetName (constDecl. identDef. ident),
      constDecl. semicolon(ExtTree.Terminal). sym. pos,
      ExportMark (constDecl. identDef), constDecl. identDef. docString)
  END VisitConstDecl;

PROCEDURE (v: Visitor) VisitTypeDecl* (typeDecl: ExtTree.TypeDecl);
  VAR
    type: Item.TypeDecl;
  BEGIN
    type := v. stb. NewTypeDecl (v. parent,
      GetName (typeDecl. identDef. ident),
      EndOfType (typeDecl. type), ExportMark (typeDecl. identDef), 
      typeDecl. identDef. docString, GetType (v, typeDecl. type))
  END VisitTypeDecl;

PROCEDURE (v: Visitor) VisitVarDecl* (varDecl: ExtTree.VarDecl);
  VAR
    type: Item.Type;
    var: Item.VarDecl;
    i: LONGINT;
  BEGIN
    type := GetType (v, varDecl. type);
    FOR i := 0 TO varDecl. identList. len-1 BY 3 DO
      var := v. stb. NewVarDecl (v. parent,
        GetName (varDecl. identList. n[i](ExtTree.IdentDef). ident),
        EndOfType (varDecl. type),
        ExportMark (varDecl. identList. n[i]), 
        varDecl. identList. n[i](ExtTree.IdentDef). docString,
        FALSE, FALSE, FALSE, type)
    END
  END VisitVarDecl;

PROCEDURE (v: Visitor) VisitReceiver* (receiver: ExtTree.Receiver);
  VAR
    type: Item.Type;
    var: Item.VarDecl;
  BEGIN
    type := GetType (v, receiver. type);
    var := v. stb. NewVarDecl (v. parent, 
      GetName (receiver. ident), EndOfType (receiver. type),
      Item.nameNotExported, receiver. ident. docString,
      TRUE, TRUE, receiver. var # NIL, type)
  END VisitReceiver;

PROCEDURE (v: Visitor) VisitFPSection* (fpSection: ExtTree.FPSection);
  VAR
    type: Item.Type;
    var: Item.VarDecl;
    i: LONGINT;
  BEGIN
    type := GetType (v, fpSection. type);
    FOR i := 0 TO fpSection. identList. len-1 BY 3 DO
      var := v. stb. NewVarDecl (v. parent,
        GetName (fpSection. identList. n[i]),
        EndOfType (fpSection. type), Item.nameNotExported,
        fpSection. identList. n[i](ExtTree.IdentDef). docString,
        TRUE, FALSE, fpSection. var # NIL, type)
    END
  END VisitFPSection;

PROCEDURE (v: Visitor) VisitProcDecl* (procDecl: ExtTree.ProcDecl);
  VAR
    proc: Item.ProcDecl;
    type: Item.Type;
    formalPars: Item.FormalPars;
    endPos: Item.ModulePos;
    i: LONGINT;
    nodePtr: AST.Node;
  BEGIN
    endPos := EndOfType (procDecl. formalPars);
    IF (endPos < 0) THEN
      endPos := EndOfType (procDecl. identDef. ident)
    END;

    proc := v. stb. NewProcDecl (v. parent, 
      GetName (procDecl. identDef. ident), endPos,
      ExportMark (procDecl. identDef),
      procDecl. identDef. docString,
      procDecl. receiver # NIL, procDecl. arrow # NIL);

    IF (procDecl. formalPars # NIL) &
       (procDecl. formalPars(ExtTree.FormalPars). result # NIL) THEN
      type := GetType (v, procDecl. formalPars(ExtTree.FormalPars). result)
    ELSE
      type := NIL
    END;
    formalPars := v. stb. NewFormalPars (proc,
                                         GetPosition (procDecl. proc), type);
    proc. formalPars := formalPars;

    IF (procDecl. receiver # NIL) THEN
      AcceptParent (v, procDecl. receiver, formalPars)
    END;
    IF (procDecl. formalPars # NIL) & 
       (procDecl. formalPars(ExtTree.FormalPars). fpSections # NIL) THEN
      FOR i := 0 TO procDecl. formalPars(ExtTree.FormalPars). fpSections. len-1 BY 2 DO
        nodePtr := procDecl. formalPars(ExtTree.FormalPars). fpSections. n[i];
        WITH nodePtr: ExtTree.Terminal DO (* rest parameter *)
          ASSERT (nodePtr. sym. str^ = "...");
          formalPars. EnableRestParameters()
        ELSE
          AcceptParent (v, nodePtr, formalPars)
        END
      END
    END;
    
    IF (procDecl. body # NIL) THEN
      AcceptParent (v, procDecl. body, proc)
    END
  END VisitProcDecl;

PROCEDURE (v: Visitor) VisitFieldList* (fieldList: ExtTree.FieldList);
  VAR
    field: Item.FieldDecl;
    type: Item.Type;
    i: LONGINT;
  BEGIN
    type := GetType (v, fieldList. type);
    FOR i := 0 TO fieldList. identList. len-1 BY 2 DO
      field := v. stb. NewFieldDecl (v. parent,
        GetName (fieldList. identList. n[i](ExtTree.IdentDef). ident),
        EndOfType (fieldList. type),
        ExportMark (fieldList. identList. n[i](ExtTree.IdentDef)), 
        fieldList. identList. n[i](ExtTree.IdentDef). docString,
        type)
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
    record: Item.Record;
    baseType: Item.Type;
    i: LONGINT;
  BEGIN
    IF (recordType. baseType # NIL) THEN
      baseType := GetType (v, recordType. baseType);
    ELSE
      baseType := NIL
    END;
    record := v. stb. NewRecord (v. parent, GetPosition (recordType. record),
                                 baseType);
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
                                   GetType (v, pointerType. type))
  END VisitPointerType;

PROCEDURE (v: Visitor) VisitArrayType* (arrayType: ExtTree.ArrayType);
  VAR
    array: Item.Array;
    baseType: Item.Type;
    i: LONGINT;
  BEGIN
    IF (arrayType. exprList. len > 0) THEN
      baseType := GetType (v, arrayType. type);
      FOR i := arrayType. exprList. len-1 TO 0 BY -2 DO
        baseType := v. stb. NewArray (v. parent,
                               GetPosition (arrayType. array), FALSE, baseType)
      END;
      array := baseType(Item.Array)
    ELSE
      array := v. stb. NewArray (v. parent, GetPosition (arrayType. array),
                                 TRUE, GetType (v, arrayType. type))
    END;
    v. type := array
  END VisitArrayType;

PROCEDURE (v: Visitor) VisitProcType* (procType: ExtTree.ProcType);
  VAR
    formalPars: Item.FormalPars;
    baseType: Item.Type;
    i: LONGINT;
  BEGIN
    IF (procType. formalPars # NIL) &
       (procType. formalPars(ExtTree.FormalPars). result # NIL) THEN
      baseType := GetType (v, procType. formalPars(ExtTree.FormalPars). result)
    ELSE
      baseType := NIL
    END;
    formalPars := v. stb. NewFormalPars (v. parent, 
                                      GetPosition (procType. procedure),
                                      baseType);
    IF (procType. formalPars # NIL) &
       (procType. formalPars(ExtTree.FormalPars). fpSections # NIL) THEN
      FOR i := 0 TO procType. formalPars(ExtTree.FormalPars). fpSections. len-1 BY 2 DO
        AcceptParent (v, procType. formalPars(ExtTree.FormalPars). 
                           fpSections. n[i], formalPars)
      END
    END;
    v. type := formalPars
  END VisitProcType;


PROCEDURE CreateSymTab* (module: AST.Node; stb: SymTabBuilder.Builder): Item.Module;
(**Creates a symbol table from the abstract syntax tree in @oparam{module}.
   The elements of the symbol table are created by calling appropriate 
   factory methods of @oparam{stb}.  Result is the root object of the newly
   created symbol table.  *)
  VAR
    v: Visitor;
  BEGIN
    NEW (v);
    v. stb := stb;
    v. parent := NIL;
    v. type := NIL;
    v. root := NIL;
    Accept (v, module);
    stb. Finalize (v. root);
    RETURN v. root
  END CreateSymTab;

END OOC:AST:ExtTree:CreateSymTab.
