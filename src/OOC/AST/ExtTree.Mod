(* 	$Id$	 *)
MODULE OOC:AST:ExtTree [OOC_EXTENSIONS];
(*  Creates extended abstract syntax tree from the parser output.
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
  ADT:String, OOC:Scanner:Builder:BasicList, OOC:AST, OOC:Doc,
  OOC:SymbolTable:Item;



(**
The syntax tree constructed by this module is a one-to-one representation
of the data passed to the factory methods of @omodule{AST}.  Every call
to a factory method creates a new heap object, which is filled with the
arguments of the method.  Please check @omodule{AST} for a description
of the parameters.  The result of @oproc{Builder.Module} is the
root of the generated syntax tree.

This module defines also a @samp{Visitor} pattern for the syntax tree.
The base class @otype{Visitor} defines visitor methods for every class
that is part of the syntax tree, and every node defines a corresponding
@samp{Accept} method.  The default action of the @samp{Visit} methods
is to do nothing.  The method @oproc{Visitor.VisitNodeList} calls 
@samp{Accept} on all element of the list that are not @code{NIL}.
*)

TYPE
  NodeList* = POINTER TO NodeListDesc;
  NodeListDesc* = RECORD
    (AST.NodeListDesc)
  END;

TYPE
  Node* = POINTER TO NodeDesc;
  NodeDesc* = RECORD [ABSTRACT]
    (AST.NodeDesc)
  END;
  
TYPE
  Builder* = POINTER TO BuilderDesc;
  BuilderDesc* = RECORD
    (AST.BuilderDesc)
  END;



TYPE
  Flags* = POINTER TO FlagsDesc;
  Terminal* = POINTER TO TerminalDesc;
  TerminalDesc = RECORD
    (NodeDesc)
    sym-: BasicList.Symbol;
  END;

TYPE
  IdentDef* = POINTER TO IdentDefDesc;
  IdentDefDesc = RECORD
    (NodeDesc)
    ident-: Terminal;
    mark-: Terminal;
    docString-: Doc.Document;
  END;

TYPE
  ModuleIdent* = POINTER TO ModuleIdentDesc;
  ModuleIdentDesc = RECORD
    (NodeDesc)
    nameList-: AST.NodeList;
    docString-: Doc.Document;
  END;

TYPE
  Type* = POINTER TO TypeDesc;
  TypeDesc = RECORD [ABSTRACT]
    (NodeDesc)
  END;

TYPE
  ArrayType* = POINTER TO ArrayTypeDesc;
  ArrayTypeDesc = RECORD
    (TypeDesc)
    array-: AST.Node;
    flags-: AST.Node;
    exprList-: AST.NodeList;
    of-: AST.Node;
    type-: AST.Node;
  END;

TYPE
  FieldList* = POINTER TO FieldListDesc;
  FieldListDesc = RECORD
    (NodeDesc)
    identList-: AST.NodeList;
    colon-: AST.Node;
    type-: AST.Node;
  END;

TYPE
  RecordType* = POINTER TO RecordTypeDesc;
  RecordTypeDesc = RECORD
    (TypeDesc)
    record-: AST.Node;
    flags-: AST.Node;
    lParen-: AST.Node;
    baseType-: AST.Node;
    rParen-: AST.Node;
    fieldLists-: AST.NodeList;
    end-: AST.Node;
  END;

TYPE
  PointerType* = POINTER TO PointerTypeDesc;
  PointerTypeDesc = RECORD
    (TypeDesc)
    pointer-: AST.Node;
    flags-: AST.Node;
    to-: AST.Node;
    type-: AST.Node;
  END;


TYPE
  FPSection* = POINTER TO FPSectionDesc;
  FPSectionDesc = RECORD
    (NodeDesc)
    var-: AST.Node;
    identList-: AST.NodeList;
    colon-: AST.Node;
    type-: AST.Node;
  END;

TYPE
  FormalPars* = POINTER TO FormalParsDesc;
  FormalParsDesc = RECORD
    (NodeDesc)
    flags-: AST.Node;
    lParen-: AST.Node;
    fpSections-: AST.NodeList;           (* optional *)
    rParen-: AST.Node;
    colon-: AST.Node;
    result-: AST.Node;
  END;

TYPE
  ProcType* = POINTER TO ProcTypeDesc;
  ProcTypeDesc = RECORD
    (TypeDesc)
    procedure-: AST.Node;
    formalPars-: AST.Node;
  END;


TYPE
  ImportDecl* = POINTER TO ImportDeclDesc;
  ImportDeclDesc = RECORD
    (NodeDesc)
    alias-: AST.Node;                    (* optional *)
    becomes-: AST.Node;                  (* optional *)
    module-: ModuleIdent;                (* required *)
    moduleName-: AST.Name;
  END;

TYPE
  ConstDecl* = POINTER TO ConstDeclDesc;
  ConstDeclDesc = RECORD
    (NodeDesc)
    identDef-: IdentDef;
    equal-: AST.Node;
    expr-: AST.Node;
    semicolon-: AST.Node;
  END;

TYPE
  TypeDecl* = POINTER TO TypeDeclDesc;
  TypeDeclDesc = RECORD
    (NodeDesc)
    identDef-: IdentDef;
    equal-: AST.Node;
    type-: AST.Node;
    semicolon-: AST.Node;
  END;

TYPE
  VarDecl* = POINTER TO VarDeclDesc;
  VarDeclDesc = RECORD
    (NodeDesc)
    identList-: AST.NodeList;
    colon-: AST.Node;
    type-: AST.Node;
    semicolon-: AST.Node;
  END;

TYPE
  Receiver* = POINTER TO ReceiverDesc;
  ReceiverDesc = RECORD
    (NodeDesc)
    lParen-: AST.Node;
    var-: AST.Node;
    ident-: IdentDef;
    colon-: AST.Node;
    type-: AST.Node;
    rParen-: AST.Node;
  END;

TYPE
  Body* = POINTER TO BodyDesc;
  BodyDesc = RECORD
    (NodeDesc)
    declSeq-: NodeList;
    begin-: AST.Node;
    statmSeq-: NodeList;  (* may be NIL *)
    end-: AST.Node;
    name-: AST.Node;
  END;
  
TYPE
  ProcDecl* = POINTER TO ProcDeclDesc;
  ProcDeclDesc = RECORD
    (NodeDesc)
    proc-: AST.Node;
    arrow-: AST.Node;
    receiver-: AST.Node;
    flags-: AST.Node;
    identDef-: IdentDef;
    formalPars-: AST.Node;
    semicolon1-: AST.Node;
    body-: Body;  (* can be NIL *)
    semicolon2-: AST.Node;
    
    symTabEntry-: Item.ProcDecl;
  END;

TYPE
  ImportList* = POINTER TO ImportListDesc;
  ImportListDesc* = RECORD
    (NodeDesc)
    import-: AST.Node;
    imports-: AST.NodeList;
    semicolon-: AST.Node;
  END;

TYPE
  Module* = POINTER TO ModuleDesc;
  ModuleDesc* = RECORD
    (NodeDesc)
    module-: AST.Node;
    name-: ModuleIdent;
    flags-: Flags;
    semicolon-: AST.Node;
    importList-: AST.Node;
    body-: Body;  (* can be NIL *)
    period-: AST.Node;
    
    moduleName-: AST.Name;
  END;


TYPE
  Operator* = POINTER TO OperatorDesc;
  OperatorDesc = RECORD
    (NodeDesc)
    (* Assuming that no errors have been found, the operator field is 
       always non-NIL.  For dyadic operators, both operands are non-NIL.
       For monadic operators, either the left (prefix, like "+a" or "~a") or 
       right (postfix, like "a^") operand is NIL.  *)
    left-: Node;                         (* can be NIL *)
    op-: Terminal;
    right-: Node;                        (* can be NIL *)
  END;

TYPE
  Factor* = POINTER TO FactorDesc;
  FactorDesc = RECORD
    (NodeDesc)
    lParen-: AST.Node;
    expr-: AST.Node;
    rParen-: AST.Node;
  END;

TYPE
  Set* = POINTER TO SetDesc;
  SetDesc = RECORD
    (NodeDesc)
    type-: AST.Node;
    lBrace-: AST.Node;
    elementList-: AST.NodeList;
    rBrace-: AST.Node;
  END;

TYPE
  ArrayIndex* = POINTER TO ArrayIndexDesc;
  ArrayIndexDesc = RECORD
    (NodeDesc)
    design-: AST.Node;
    lBrak-: AST.Node;
    indices-: AST.NodeList;
    rBrak-: AST.Node;
  END;

TYPE
  FunctionCall* = POINTER TO FunctionCallDesc;
  FunctionCallDesc = RECORD
    (NodeDesc)
    design-: Node;
    lParen-: AST.Node;
    arguments-: AST.NodeList;
    rParen-: AST.Node;
  END;



TYPE
  Assignment* = POINTER TO AssignmentDesc;
  AssignmentDesc = RECORD
    (NodeDesc)
    assignment-: AST.Node;
  END;

TYPE
  ProcedureCall* = POINTER TO ProcedureCallDesc;
  ProcedureCallDesc = RECORD
    (NodeDesc)
    call-: Node;                    (* see @oproc{AST.Builder.ProcedureCall} *)
  END;

TYPE
  IfStatm* = POINTER TO IfStatmDesc;
  IfStatmDesc = RECORD
    (NodeDesc)
    guardList-: AST.NodeList;
    else-: AST.Node;
    elseStatmSeq-: AST.NodeList;
    end-: AST.Node;
  END;

TYPE
  CaseStatm* = POINTER TO CaseStatmDesc;
  CaseStatmDesc = RECORD
    (NodeDesc)
    case-: AST.Node;
    expr-: AST.Node;
    of-: AST.Node;
    caseList-: AST.NodeList;
    else-: AST.Node;
    elseStatmSeq-: AST.NodeList;
    end-: AST.Node;
  END;

TYPE
  WhileStatm* = POINTER TO WhileStatmDesc;
  WhileStatmDesc = RECORD
    (NodeDesc)
    while-: AST.Node;
    guard-: AST.Node;
    do-: AST.Node;
    statmSeq-: AST.NodeList;
    end-: AST.Node;
  END;

TYPE
  RepeatStatm* = POINTER TO RepeatStatmDesc;
  RepeatStatmDesc = RECORD
    (NodeDesc)
    repeat-: AST.Node;
    statmSeq-: AST.NodeList;
    until-: AST.Node;
    expr-: AST.Node;
  END;

TYPE
  ForStatm* = POINTER TO ForStatmDesc;
  ForStatmDesc = RECORD
    (NodeDesc)
    for-: AST.Node;
    ident-: AST.Node;
    becomes-: AST.Node;
    startValue-: AST.Node;
    to-: AST.Node;
    endValue-: AST.Node;
    by-: AST.Node;
    step-: AST.Node;
    do-: AST.Node;
    statmSeq-: AST.NodeList;
    end-: AST.Node;
  END;

TYPE
  LoopStatm* = POINTER TO LoopStatmDesc;
  LoopStatmDesc = RECORD
    (NodeDesc)
    loop-: AST.Node;
    statmSeq-: AST.NodeList;
    end-: AST.Node;
  END;

TYPE
  WithStatm* = POINTER TO WithStatmDesc;
  WithStatmDesc = RECORD
    (NodeDesc)
    guardList-: AST.NodeList;
    else-: AST.Node;
    elseStatmSeq-: AST.NodeList;
    end-: AST.Node;
  END;

TYPE
  ExitStatm* = POINTER TO ExitStatmDesc;
  ExitStatmDesc = RECORD
    (NodeDesc)
    exit-: AST.Node;
  END;

TYPE
  ReturnStatm* = POINTER TO ReturnStatmDesc;
  ReturnStatmDesc = RECORD
    (NodeDesc)
    return-: AST.Node;
    expr-: AST.Node;
  END;



TYPE
  FlagsDesc = RECORD
    (NodeDesc)
    context-: SHORTINT;
    lBrak-: AST.Node;
    flagList-: AST.NodeList;
    rBrak-: AST.Node;
  END;

TYPE
  ProcIdFlag* = POINTER TO ProcIdFlagDesc;
  ProcIdFlagDesc = RECORD
    (NodeDesc)
    procId-: AST.Node;
    equal-: AST.Node;
    number-: AST.Node;
  END;

TYPE
  LibraryFlag* = POINTER TO LibraryFlagDesc;
  LibraryFlagDesc = RECORD
    (NodeDesc)
    library-: AST.Node;
    name-: AST.Node;
    version-: AST.Node;
    semicolon-: AST.Node;
  END;

TYPE
  ModuleFlags* = POINTER TO ModuleFlagsDesc;
  ModuleFlagsDesc = RECORD
    (NodeDesc)
    library-: AST.Node;
    external-: Terminal;
    callConv-: Terminal;
    moduleFlags-: AST.NodeList;
    semicolon-: AST.Node;
    link-: AST.Node;
    linkSections-: AST.NodeList;
    end-: AST.Node;
  END;

TYPE
  LinkFileFlag* = POINTER TO LinkFileFlagDesc;
  LinkFileFlagDesc = RECORD
    (NodeDesc)
    file-: AST.Node;
    fileName-: Terminal;
    addOption-: AST.Node;
    prefixOpt-: Terminal;
    comma-: AST.Node;
    suffixOpt-: Terminal;
  END;

TYPE
  LinkObjFlag* = POINTER TO LinkObjFlagDesc;
  LinkObjFlagDesc = RECORD
    (NodeDesc)
    obj-: AST.Node;
    fileName-: AST.Node;
  END;

TYPE
  LinkLibFlag* = POINTER TO LinkLibFlagDesc;
  LinkLibFlagDesc = RECORD
    (NodeDesc)
    lib-: AST.Node;
    libName-: AST.Node;
    lParen-: AST.Node;
    dependences-: AST.NodeList;
    rParen-: AST.Node;
    addOption-: AST.Node;
    prefixOpt-: AST.Node;
    comma-: AST.Node;
    suffixOpt-: AST.Node;
  END;



TYPE
  Visitor* = POINTER TO VisitorDesc;
  VisitorDesc* = RECORD [ABSTRACT]
  END;


PROCEDURE (node: Node) [ABSTRACT] Accept* (v: Visitor);
  END Accept;

PROCEDURE InitVisitor* (v: Visitor);
  END InitVisitor;

PROCEDURE (v: Visitor) VisitNodeList* (nl: NodeList);
  VAR
    i: LONGINT;
  BEGIN
    FOR i := 0 TO nl. len-1 DO
      IF (nl. n[i] # NIL) THEN
        nl. n[i](Node). Accept (v)
      END
    END
  END VisitNodeList;

PROCEDURE (v: Visitor) VisitTerminal* (terminal: Terminal);
  END VisitTerminal;

PROCEDURE (v: Visitor) VisitIdentDef* (identDef: IdentDef);
  END VisitIdentDef;

PROCEDURE (v: Visitor) VisitModuleIdent* (moduleIdent: ModuleIdent);
  END VisitModuleIdent;

(* types *)
PROCEDURE (v: Visitor) VisitArrayType* (arrayType: ArrayType);
  END VisitArrayType;

PROCEDURE (v: Visitor) VisitFieldList* (fieldList: FieldList);
  END VisitFieldList;

PROCEDURE (v: Visitor) VisitRecordType* (recordType: RecordType);
  END VisitRecordType;

PROCEDURE (v: Visitor) VisitPointerType* (pointerType: PointerType);
  END VisitPointerType;

PROCEDURE (v: Visitor) VisitFPSection* (fpSection: FPSection);
  END VisitFPSection;

PROCEDURE (v: Visitor) VisitFormalPars* (formalPars: FormalPars);
  END VisitFormalPars;

PROCEDURE (v: Visitor) VisitProcType* (procType: ProcType);
  END VisitProcType;

(* declarations *)
PROCEDURE (v: Visitor) VisitImportDecl* (importDecl: ImportDecl);
  END VisitImportDecl;

PROCEDURE (v: Visitor) VisitConstDecl* (constDecl: ConstDecl);
  END VisitConstDecl;

PROCEDURE (v: Visitor) VisitTypeDecl* (typeDecl: TypeDecl);
  END VisitTypeDecl;

PROCEDURE (v: Visitor) VisitVarDecl* (varDecl: VarDecl);
  END VisitVarDecl;

PROCEDURE (v: Visitor) VisitReceiver* (receiver: Receiver);
  END VisitReceiver;

PROCEDURE (v: Visitor) VisitProcDecl* (procDecl: ProcDecl);
  END VisitProcDecl;

PROCEDURE (v: Visitor) VisitImportList* (importList: ImportList);
  END VisitImportList;

PROCEDURE (v: Visitor) VisitBody* (body: Body);
  END VisitBody;

PROCEDURE (v: Visitor) VisitModule* (module: Module);
  END VisitModule;

(* expressions *)
PROCEDURE (v: Visitor) VisitOperator* (operator: Operator);
  END VisitOperator;

PROCEDURE (v: Visitor) VisitFactor* (factor: Factor);
  END VisitFactor;

PROCEDURE (v: Visitor) VisitSet* (set: Set);
  END VisitSet;

PROCEDURE (v: Visitor) VisitArrayIndex* (arrayIndex: ArrayIndex);
  END VisitArrayIndex;

PROCEDURE (v: Visitor) VisitFunctionCall* (functionCall: FunctionCall);
  END VisitFunctionCall;

(* statements *)
PROCEDURE (v: Visitor) VisitAssignment* (assignment: Assignment);
  END VisitAssignment;

PROCEDURE (v: Visitor) VisitProcedureCall* (procedureCall: ProcedureCall);
  END VisitProcedureCall;

PROCEDURE (v: Visitor) VisitIfStatm* (ifStatm: IfStatm);
  END VisitIfStatm;

PROCEDURE (v: Visitor) VisitCaseStatm* (caseStatm: CaseStatm);
  END VisitCaseStatm;

PROCEDURE (v: Visitor) VisitWhileStatm* (whileStatm: WhileStatm);
  END VisitWhileStatm;

PROCEDURE (v: Visitor) VisitRepeatStatm* (repeatStatm: RepeatStatm);
  END VisitRepeatStatm;

PROCEDURE (v: Visitor) VisitForStatm* (forStatm: ForStatm);
  END VisitForStatm;

PROCEDURE (v: Visitor) VisitLoopStatm* (loopStatm: LoopStatm);
  END VisitLoopStatm;

PROCEDURE (v: Visitor) VisitWithStatm* (withStatm: WithStatm);
  END VisitWithStatm;

PROCEDURE (v: Visitor) VisitExitStatm* (exitStatm: ExitStatm);
  END VisitExitStatm;

PROCEDURE (v: Visitor) VisitReturnStatm* (returnStatm: ReturnStatm);
  END VisitReturnStatm;

(* flags *)
PROCEDURE (v: Visitor) VisitFlags* (flags: Flags);
  END VisitFlags;

PROCEDURE (v: Visitor) VisitProcIdFlag* (procIdFlag: ProcIdFlag);
  END VisitProcIdFlag;

PROCEDURE (v: Visitor) VisitLibraryFlag* (libraryFlag: LibraryFlag);
  END VisitLibraryFlag;

PROCEDURE (v: Visitor) VisitModuleFlags* (moduleFlags: ModuleFlags);
  END VisitModuleFlags;

PROCEDURE (v: Visitor) VisitLinkFileFlag* (linkFileFlag: LinkFileFlag);
  END VisitLinkFileFlag;

PROCEDURE (v: Visitor) VisitLinkObjFlag* (linkObjFlag: LinkObjFlag);
  END VisitLinkObjFlag;

PROCEDURE (v: Visitor) VisitLinkLibFlag* (linkLibFlag: LinkLibFlag);
  END VisitLinkLibFlag;



PROCEDURE Init* (b: Builder);
  BEGIN
  END Init;

PROCEDURE New* (): Builder;
  VAR
    b: Builder;
  BEGIN
    NEW (b);
    Init (b);
    RETURN b
  END New;

PROCEDURE (b: Builder) NewNodeList* (): NodeList;
(**Creates a new node list of length zero.  *)
  VAR
    nl: NodeList;
  BEGIN
    NEW (nl);
    AST.InitNodeList (nl);
    RETURN nl
  END NewNodeList;

PROCEDURE (nl: NodeList) Accept* (v: Visitor);
  BEGIN
    v. VisitNodeList (nl)
  END Accept;



PROCEDURE (b: Builder) Terminal* (sym: BasicList.Symbol): Node;
  VAR
    t: Terminal;
  BEGIN
    NEW (t);
    t. sym := sym;
    RETURN t
  END Terminal;

PROCEDURE (terminal: Terminal) Accept* (v: Visitor);
  BEGIN
    v. VisitTerminal (terminal)
  END Accept;

PROCEDURE (terminal: Terminal) GetString* (stripQuotes: BOOLEAN): String.String;
  BEGIN
    IF stripQuotes THEN
      RETURN String.NewRegion (terminal. sym. str^,
                               1, terminal. sym. len-1)
    ELSE
      RETURN String.New (terminal. sym. str^)
    END
  END GetString;


PROCEDURE (b: Builder) IdentDef* (ident, mark: AST.Node): Node;
  VAR
    id: IdentDef;
  BEGIN
    NEW (id);
    IF (ident # NIL) THEN
      id. ident := ident(Terminal)
    ELSE
      id. ident := NIL
    END;
    IF (mark # NIL) THEN
      id. mark := mark(Terminal)
    ELSE
      id. mark := NIL
    END;
    id. docString := NIL;
    RETURN id
  END IdentDef;

PROCEDURE (identDef: IdentDef) AttachDocString* (docString: Doc.Document);
  BEGIN
    IF (identDef. docString # NIL) THEN
      identDef. docString. Merge (docString)
    ELSE
      identDef. docString := docString
    END
  END AttachDocString;

PROCEDURE (identDef: IdentDef) Accept* (v: Visitor);
  BEGIN
    v. VisitIdentDef (identDef)
  END Accept;


PROCEDURE (b: Builder) ModuleIdent* (nameList: AST.NodeList): Node;
  VAR
    moduleIdent: ModuleIdent;
  BEGIN
    NEW (moduleIdent);
    moduleIdent. nameList := nameList;
    moduleIdent. docString := NIL;
    RETURN moduleIdent
  END ModuleIdent;

PROCEDURE (moduleIdent: ModuleIdent) AttachDocString* (docString: Doc.Document);
  BEGIN
    IF (moduleIdent. docString # NIL) THEN
      moduleIdent. docString. Merge (docString)
    ELSE
      moduleIdent. docString := docString
    END
  END AttachDocString;

PROCEDURE (moduleIdent: ModuleIdent) Accept* (v: Visitor);
  BEGIN
    v. VisitModuleIdent (moduleIdent)
  END Accept;


PROCEDURE InitType (t: Type);
  BEGIN
  END InitType;

PROCEDURE (b: Builder) ArrayType* (array, flags: AST.Node; exprList: AST.NodeList; of, type: AST.Node): Node;
  VAR
    at: ArrayType;
  BEGIN
    NEW (at);
    InitType (at);
    at. array := array;
    at. flags := flags;
    at. exprList := exprList;
    at. of := of;
    at. type := type;
    RETURN at
  END ArrayType;

PROCEDURE (arrayType: ArrayType) Accept* (v: Visitor);
  BEGIN
    v. VisitArrayType (arrayType)
  END Accept;


PROCEDURE (b: Builder) FieldList* (identList: AST.NodeList; colon, type: AST.Node): Node;
  VAR
    fl: FieldList;
  BEGIN
    NEW (fl);
    fl. identList := identList;
    fl. colon := colon;
    fl. type := type;
    RETURN fl
  END FieldList;

PROCEDURE (fieldList: FieldList) Accept* (v: Visitor);
  BEGIN
    v. VisitFieldList (fieldList)
  END Accept;


PROCEDURE (b: Builder) RecordType* (record, flags, lParen, baseType, rParen: AST.Node; fieldLists: AST.NodeList; end: AST.Node): Node;
  VAR
    rt: RecordType;
  BEGIN
    NEW (rt);
    InitType (rt);
    rt. record := record;
    rt. flags := flags;
    rt. lParen := lParen;
    rt. baseType := baseType;
    rt. rParen := rParen;
    rt. fieldLists := fieldLists;
    rt. end := end;
    RETURN rt
  END RecordType;

PROCEDURE (recordType: RecordType) Accept* (v: Visitor);
  BEGIN
    v. VisitRecordType (recordType)
  END Accept;


PROCEDURE (b: Builder) PointerType* (pointer, flags, to, type: AST.Node): Node;
  VAR
    pt: PointerType;
  BEGIN
    NEW (pt);
    InitType (pt);
    pt. pointer := pointer;
    pt. flags := flags;
    pt. to := to;
    pt. type := type;
    RETURN pt
  END PointerType;

PROCEDURE (pointerType: PointerType) Accept* (v: Visitor);
  BEGIN
    v. VisitPointerType (pointerType)
  END Accept;


PROCEDURE (b: Builder) FPSection* (var: AST.Node; identList: AST.NodeList; colon, type: AST.Node): Node;
  VAR
    fp: FPSection;
  BEGIN
    NEW (fp);
    fp. var := var;
    fp. identList := identList;
    fp. colon := colon;
    fp. type := type;
    RETURN fp
  END FPSection;

PROCEDURE (fpSection: FPSection) Accept* (v: Visitor);
  BEGIN
    v. VisitFPSection (fpSection)
  END Accept;


PROCEDURE (b: Builder) FormalPars* (flags, lParen: AST.Node; fpSections: AST.NodeList; rParen, colon, result: AST.Node): Node;
  VAR
    fp: FormalPars;
  BEGIN
    NEW (fp);
    fp. flags := flags;
    fp. lParen := lParen;
    fp. fpSections := fpSections;
    fp. rParen := rParen;
    fp. colon := colon;
    fp. result := result;
    RETURN fp
  END FormalPars;
  
PROCEDURE (formalPars: FormalPars) Accept* (v: Visitor);
  BEGIN
    v. VisitFormalPars (formalPars)
  END Accept;


PROCEDURE (b: Builder) ProcType* (procedure, formalPars: AST.Node): Node;
  VAR
    pt: ProcType;
  BEGIN
    NEW (pt);
    InitType (pt);
    pt. procedure := procedure;
    pt. formalPars := formalPars;
    RETURN pt
  END ProcType;

PROCEDURE (procType: ProcType) Accept* (v: Visitor);
  BEGIN
    v. VisitProcType (procType)
  END Accept;



PROCEDURE (b: Builder) ImportDecl* (alias, becomes, module: AST.Node;
                                    moduleName: AST.Name): Node;
  VAR
    id: ImportDecl;
  BEGIN
    NEW (id);
    id. alias := alias;
    id. becomes := becomes;
    id. module := module(ModuleIdent);
    id. moduleName := moduleName;
    RETURN id
  END ImportDecl;

PROCEDURE (importDecl: ImportDecl) Accept* (v: Visitor);
  BEGIN
    v. VisitImportDecl (importDecl)
  END Accept;


PROCEDURE (b: Builder) ConstDecl* (identDef, equal, expr, semicolon: AST.Node): Node;
  VAR
    cd: ConstDecl;
  BEGIN
    NEW (cd);
    cd. identDef := identDef(IdentDef);
    cd. equal := equal;
    cd. expr := expr;
    cd. semicolon := semicolon;
    RETURN cd
  END ConstDecl;

PROCEDURE (constDecl: ConstDecl) Accept* (v: Visitor);
  BEGIN
    v. VisitConstDecl (constDecl)
  END Accept;


PROCEDURE (b: Builder) TypeDecl* (identDef, equal, type, semicolon: AST.Node): Node;
  VAR
    td: TypeDecl;
  BEGIN
    NEW (td);
    td. identDef := identDef(IdentDef);
    td. equal := equal;
    td. type := type;
    td. semicolon := semicolon;
    RETURN td
  END TypeDecl;

PROCEDURE (typeDecl: TypeDecl) Accept* (v: Visitor);
  BEGIN
    v. VisitTypeDecl (typeDecl)
  END Accept;


PROCEDURE (b: Builder) VarDecl* (identList: AST.NodeList; colon, type, semicolon: AST.Node): Node;
  VAR
    vd: VarDecl;
  BEGIN
    NEW (vd);
    vd. identList := identList;
    vd. colon := colon;
    vd. type := type;
    vd. semicolon := semicolon;
    RETURN vd
  END VarDecl;

PROCEDURE (varDecl: VarDecl) Accept* (v: Visitor);
  BEGIN
    v. VisitVarDecl (varDecl)
  END Accept;


PROCEDURE (b: Builder) Receiver* (lParen, var, ident, colon, type, rParen: AST.Node): Node;
  VAR
    r: Receiver;
  BEGIN
    NEW (r);
    r. lParen := lParen;
    r. var := var;
    r. ident := ident(IdentDef);
    r. colon := colon;
    r. type := type;
    r. rParen := rParen;
    RETURN r
  END Receiver;

PROCEDURE (receiver: Receiver) Accept* (v: Visitor);
  BEGIN
    v. VisitReceiver (receiver)
  END Accept;


PROCEDURE (b: Builder) ProcDecl* (proc, arrow, receiver, 
                                 flags, identDef, formalPars, semicolon1,
                                 body, semicolon2: AST.Node): Node;
  VAR
    pd: ProcDecl;
  BEGIN
    NEW (pd);
    pd. proc := proc;
    pd. arrow := arrow;
    pd. receiver := receiver;
    pd. flags := flags;
    pd. identDef := identDef(IdentDef);
    pd. formalPars := formalPars;
    pd. semicolon1 := semicolon1;
    IF (body = NIL) THEN
      pd. body := NIL
    ELSE
      pd. body := body(Body)
    END;
    pd. semicolon2 := semicolon2;
    
    pd. symTabEntry := NIL;
    RETURN pd
  END ProcDecl;

PROCEDURE (procDecl: ProcDecl) Accept* (v: Visitor);
  BEGIN
    v. VisitProcDecl (procDecl)
  END Accept;

PROCEDURE (procDecl: ProcDecl) SetSymTabEntry* (item: Item.Item);
  BEGIN
    procDecl. symTabEntry := item(Item.ProcDecl)
  END SetSymTabEntry;


PROCEDURE (b: Builder) ImportList* (import: AST.Node;
                               imports: AST.NodeList; semicolon: AST.Node): Node;
  VAR
    il: ImportList;
  BEGIN
    NEW (il);
    il. import := import;
    il. imports := imports;
    il. semicolon := semicolon;
    RETURN il
  END ImportList;

PROCEDURE (importList: ImportList) Accept* (v: Visitor);
  BEGIN
    v. VisitImportList (importList)
  END Accept;


PROCEDURE (b: Builder) Body* (declSeq: AST.NodeList;
                              begin: AST.Node; statmSeq: AST.NodeList; 
                              end, name: AST.Node): AST.Node;
  VAR
    body: Body;
  BEGIN
    NEW (body);
    body. declSeq := declSeq(NodeList);
    body. begin := begin;
    IF (statmSeq = NIL) THEN
      body. statmSeq := NIL;
    ELSE
      body. statmSeq := statmSeq(NodeList)
    END;
    body. end := end;
    body. name := name;
    RETURN body
  END Body;

PROCEDURE (body: Body) Accept* (v: Visitor);
  BEGIN
    v. VisitBody (body)
  END Accept;


PROCEDURE (b: Builder) Module* (module, name: AST.Node;
              flags, semicolon, importList, body, period: AST.Node;
              moduleName: AST.Name): Node;
  VAR
    m: Module;
  BEGIN
    NEW (m);
    m. module := module;
    m. name := name(ModuleIdent);
    IF (flags # NIL) THEN
      m. flags := flags(Flags)
    ELSE
      m. flags := NIL
    END;
    m. semicolon := semicolon;
    m. importList := importList;
    IF (body # NIL) THEN
      m. body := body(Body)
    ELSE
      m. body := NIL
    END;
    m. period := period;
    m. moduleName := moduleName;
    RETURN m
  END Module;

PROCEDURE (module: Module) Accept* (v: Visitor);
  BEGIN
    v. VisitModule (module)
  END Accept;



PROCEDURE (b: Builder) Operator* (left, op, right: AST.Node): Node;
  VAR
    o: Operator;
  BEGIN
    NEW (o);
    IF (left = NIL) THEN
      o. left := NIL
    ELSE
      o. left := left(Node)
    END;
    o. op := op(Terminal);
    IF (right = NIL) THEN
      o. right := NIL
    ELSE
      o. right := right(Node)
    END;
    RETURN o
  END Operator;

PROCEDURE (operator: Operator) Accept* (v: Visitor);
  BEGIN
    v. VisitOperator (operator)
  END Accept;


PROCEDURE (b: Builder) Factor* (lParen, expr, rParen: AST.Node): Node;
  VAR
    f: Factor;
  BEGIN
    NEW (f);
    f. lParen := lParen;
    f. expr := expr;
    f. rParen := rParen;
    RETURN f
  END Factor;

PROCEDURE (factor: Factor) Accept* (v: Visitor);
  BEGIN
    v. VisitFactor (factor)
  END Accept;


PROCEDURE (b: Builder) Set* (type, lBrace: AST.Node; elementList: AST.NodeList; rBrace: AST.Node): Node;
  VAR
    s: Set;
  BEGIN
    NEW (s);
    s. type := type;
    s. lBrace := lBrace;
    s. elementList := elementList;
    s. rBrace := rBrace;
    RETURN s
  END Set;

PROCEDURE (set: Set) Accept* (v: Visitor);
  BEGIN
    v. VisitSet (set)
  END Accept;


PROCEDURE (b: Builder) ArrayIndex* (design, lBrak: AST.Node; indices: AST.NodeList; rBrak: AST.Node): Node;
  VAR
    ai: ArrayIndex;
  BEGIN
    NEW (ai);
    ai. design := design;
    ai. lBrak := lBrak;
    ai. indices := indices;
    ai. rBrak := rBrak;
    RETURN ai
  END ArrayIndex;

PROCEDURE (arrayIndex: ArrayIndex) Accept* (v: Visitor);
  BEGIN
    v. VisitArrayIndex (arrayIndex)
  END Accept;


PROCEDURE (b: Builder) FunctionCall* (design, lParen: AST.Node; arguments: AST.NodeList; rParen: AST.Node): Node;
  VAR
    fc: FunctionCall;
  BEGIN
    NEW (fc);
    fc. design := design(Node);
    fc. lParen := lParen;
    fc. arguments := arguments;
    fc. rParen := rParen;
    RETURN fc
  END FunctionCall;

PROCEDURE (functionCall: FunctionCall) Accept* (v: Visitor);
  BEGIN
    v. VisitFunctionCall (functionCall)
  END Accept;


PROCEDURE (b: Builder) Assignment* (assignment: AST.Node): Node;
  VAR
    a: Assignment;
  BEGIN
    NEW (a);
    a. assignment := assignment;
    RETURN a
  END Assignment;

PROCEDURE (assignment: Assignment) Accept* (v: Visitor);
  BEGIN
    v. VisitAssignment (assignment)
  END Accept;


PROCEDURE (b: Builder) ProcedureCall* (call: AST.Node): Node;
  VAR
    p: ProcedureCall;
  BEGIN
    NEW (p);
    p. call := call(Node);
    RETURN p
  END ProcedureCall;

PROCEDURE (procedureCall: ProcedureCall) Accept* (v: Visitor);
  BEGIN
    v. VisitProcedureCall (procedureCall)
  END Accept;


PROCEDURE (b: Builder) IfStatm* (guardList: AST.NodeList; else: AST.Node; elseStatmSeq: AST.NodeList; end: AST.Node): Node;
  VAR
    i: IfStatm;
  BEGIN
    NEW (i);
    i. guardList := guardList;
    i. else := else;
    i. elseStatmSeq := elseStatmSeq;
    i. end := end;
    RETURN i
  END IfStatm;

PROCEDURE (ifStatm: IfStatm) Accept* (v: Visitor);
  BEGIN
    v. VisitIfStatm (ifStatm)
  END Accept;


PROCEDURE (b: Builder) CaseStatm* (case, expr, of: AST.Node; caseList: AST.NodeList; else: AST.Node; elseStatmSeq: AST.NodeList; end: AST.Node): Node;
  VAR
    c: CaseStatm;
  BEGIN
    NEW (c);
    c. case := case;
    c. expr := expr;
    c. of := of;
    c. caseList := caseList;
    c. else := else;
    c. elseStatmSeq := elseStatmSeq;
    c. end := end;
    RETURN c
  END CaseStatm;

PROCEDURE (caseStatm: CaseStatm) Accept* (v: Visitor);
  BEGIN
    v. VisitCaseStatm (caseStatm)
  END Accept;


PROCEDURE (b: Builder) WhileStatm* (while, guard, do: AST.Node; statmSeq: AST.NodeList; end: AST.Node): Node;
  VAR
    w: WhileStatm;
  BEGIN
    NEW (w);
    w. while := while;
    w. guard := guard;
    w. do := do;
    w. statmSeq := statmSeq;
    w. end := end;
    RETURN w
  END WhileStatm;

PROCEDURE (whileStatm: WhileStatm) Accept* (v: Visitor);
  BEGIN
    v. VisitWhileStatm (whileStatm)
  END Accept;


PROCEDURE (b: Builder) RepeatStatm* (repeat: AST.Node; statmSeq: AST.NodeList; until, expr: AST.Node): Node;
  VAR
    r: RepeatStatm;
  BEGIN
    NEW (r);
    r. repeat := repeat;
    r. statmSeq := statmSeq;
    r. until := until;
    r. expr := expr;
    RETURN r
  END RepeatStatm;

PROCEDURE (repeatStatm: RepeatStatm) Accept* (v: Visitor);
  BEGIN
    v. VisitRepeatStatm (repeatStatm)
  END Accept;


PROCEDURE (b: Builder) ForStatm* (for, ident, becomes, startValue, to, endValue, by, step, do: AST.Node; statmSeq: AST.NodeList; end: AST.Node): Node;
  VAR
    f: ForStatm;
  BEGIN
    NEW (f);
    f. for := for;
    f. ident := ident;
    f. becomes := becomes;
    f. startValue := startValue;
    f. to := to;
    f. endValue := endValue;
    f. by := by;
    f. step := step;
    f. do := do;
    f. statmSeq := statmSeq;
    f. end := end;
    RETURN f
  END ForStatm;

PROCEDURE (forStatm: ForStatm) Accept* (v: Visitor);
  BEGIN
    v. VisitForStatm (forStatm)
  END Accept;


PROCEDURE (b: Builder) LoopStatm* (loop: AST.Node; statmSeq: AST.NodeList; end: AST.Node): Node;
  VAR
    l: LoopStatm;
  BEGIN
    NEW (l);
    l. loop := loop;
    l. statmSeq := statmSeq;
    l. end := end;
    RETURN l
  END LoopStatm;

PROCEDURE (loopStatm: LoopStatm) Accept* (v: Visitor);
  BEGIN
    v. VisitLoopStatm (loopStatm)
  END Accept;


PROCEDURE (b: Builder) WithStatm* (guardList: AST.NodeList; else: AST.Node; elseStatmSeq: AST.NodeList; end: AST.Node): Node;
  VAR
    w: WithStatm;
  BEGIN
    NEW (w);
    w. guardList := guardList;
    w. else := else;
    w. elseStatmSeq := elseStatmSeq;
    w. end := end;
    RETURN w
  END WithStatm;

PROCEDURE (withStatm: WithStatm) Accept* (v: Visitor);
  BEGIN
    v. VisitWithStatm (withStatm)
  END Accept;


PROCEDURE (b: Builder) ExitStatm* (exit: AST.Node): Node;
  VAR
    e: ExitStatm;
  BEGIN
    NEW (e);
    e. exit := exit;
    RETURN e
  END ExitStatm;

PROCEDURE (exitStatm: ExitStatm) Accept* (v: Visitor);
  BEGIN
    v. VisitExitStatm (exitStatm)
  END Accept;


PROCEDURE (b: Builder) ReturnStatm* (return, expr: AST.Node): Node;
  VAR
    r: ReturnStatm;
  BEGIN
    NEW (r);
    r. return := return;
    r. expr := expr;
    RETURN r
  END ReturnStatm;

PROCEDURE (returnStatm: ReturnStatm) Accept* (v: Visitor);
  BEGIN
    v. VisitReturnStatm (returnStatm)
  END Accept;




PROCEDURE (b: Builder) Flags* (context: SHORTINT; lBrak: AST.Node;
                               flagList: AST.NodeList; rBrak: AST.Node): AST.Node;
  VAR
    f: Flags;
  BEGIN
    NEW (f);
    f. context := context;
    f. lBrak := lBrak;
    f. flagList := flagList;
    f. rBrak := rBrak;
    RETURN f
  END Flags;

PROCEDURE (b: Builder) ProcWithoutBody* (moduleFlags, procFlags: AST.Node): BOOLEAN;
  VAR
    i: LONGINT;
    n: AST.Node;
  BEGIN
    IF (moduleFlags # NIL) &
       ~(moduleFlags(Flags). flagList. n[0] IS Terminal) THEN
      (* module flags exist, and the flag list does not start with
         OOC_EXTENSIONS: assume INTERFACE or FOREIGN module *)
      IF (procFlags # NIL) THEN  (* search for HAS_BODY flag *)
        i := 0;
        WHILE (i < procFlags(Flags). flagList. len) DO
          n := procFlags(Flags). flagList. n[i];
          IF (n IS Terminal) & (n(Terminal). sym. str^ = "HAS_BODY") THEN
            RETURN FALSE
          END;
          INC (i, 2)
        END
      END;
      RETURN TRUE
    ELSE
      RETURN FALSE
    END
  END ProcWithoutBody;


PROCEDURE (flags: Flags) Accept* (v: Visitor);
  BEGIN
    v. VisitFlags (flags)
  END Accept;


PROCEDURE (b: Builder) ProcIdFlag* (procId, equal, number: AST.Node): AST.Node;
  VAR
    pid: ProcIdFlag;
  BEGIN
    NEW (pid);
    pid. procId := procId;
    pid. equal := equal;
    pid. number := number;
    RETURN pid
  END ProcIdFlag;

PROCEDURE (procIdFlag: ProcIdFlag) Accept* (v: Visitor);
  BEGIN
    v. VisitProcIdFlag (procIdFlag)
  END Accept;


PROCEDURE (b: Builder) LibraryFlag* (library, name, version, semicolon: AST.Node): AST.Node;
  VAR
    lf: LibraryFlag;
  BEGIN
    NEW (lf);
    lf. library := library;
    lf. name := name;
    lf. version := version;
    lf. semicolon := semicolon;
    RETURN lf
  END LibraryFlag;

PROCEDURE (libraryFlag: LibraryFlag) Accept* (v: Visitor);
  BEGIN
    v. VisitLibraryFlag (libraryFlag)
  END Accept;


PROCEDURE (b: Builder) ModuleFlags* (
             library, external,  callConv: AST.Node; moduleFlags: AST.NodeList;
             semicolon, link: AST.Node;
             linkSections: AST.NodeList; end: AST.Node): AST.Node;
  VAR
    mf: ModuleFlags;
  BEGIN
    NEW (mf);
    mf. external := external(Terminal);
    mf. callConv := callConv(Terminal);
    mf. library := library;
    mf. moduleFlags := moduleFlags;
    mf. semicolon := semicolon;
    mf. link := link;
    mf. linkSections := linkSections;
    mf. end := end;
    RETURN mf
  END ModuleFlags;

PROCEDURE (moduleFlags: ModuleFlags) Accept* (v: Visitor);
  BEGIN
    v. VisitModuleFlags (moduleFlags)
  END Accept;


PROCEDURE (b: Builder) LinkFileFlag* (file, fileName, addOption, prefixOpt, comma, suffixOpt: AST.Node): AST.Node;
  VAR
    lff: LinkFileFlag;
  BEGIN
    NEW (lff);
    lff. file := file;
    lff. fileName := fileName(Terminal);
    lff. addOption := addOption;
    IF (prefixOpt = NIL) THEN
      lff. prefixOpt := NIL
    ELSE
      lff. prefixOpt := prefixOpt(Terminal)
    END;
    lff. comma := comma;
    IF (suffixOpt = NIL) THEN
      lff. suffixOpt := NIL
    ELSE
      lff. suffixOpt := suffixOpt(Terminal)
    END;
    RETURN lff
  END LinkFileFlag;

PROCEDURE (linkFileFlag: LinkFileFlag) Accept* (v: Visitor);
  BEGIN
    v. VisitLinkFileFlag (linkFileFlag)
  END Accept;


PROCEDURE (b: Builder) LinkObjFlag* (obj, fileName: AST.Node): AST.Node;
  VAR
    lof: LinkObjFlag;
  BEGIN
    NEW (lof);
    lof. obj := obj;
    lof. fileName := fileName;
    RETURN lof
  END LinkObjFlag;

PROCEDURE (linkObjFlag: LinkObjFlag) Accept* (v: Visitor);
  BEGIN
    v. VisitLinkObjFlag (linkObjFlag)
  END Accept;


PROCEDURE (b: Builder) LinkLibFlag* (lib, libName, lParen: AST.Node;
                  dependences: AST.NodeList;
                  rParen, addOption, prefixOpt, comma, suffixOpt: AST.Node): AST.Node;
  VAR
    llf: LinkLibFlag;
  BEGIN
    NEW (llf);
    llf. lib := lib;
    llf. libName := libName;
    llf. lParen := lParen;
    llf. dependences := dependences;
    llf. rParen := rParen;
    llf. addOption := addOption;
    llf. prefixOpt := prefixOpt;
    llf. comma := comma;
    llf. suffixOpt := suffixOpt;
    RETURN llf
  END LinkLibFlag;

PROCEDURE (linkLibFlag: LinkLibFlag) Accept* (v: Visitor);
  BEGIN
    v. VisitLinkLibFlag (linkLibFlag)
  END Accept;

END OOC:AST:ExtTree.
