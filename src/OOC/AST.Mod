(* 	$Id: AST.Mod,v 1.21 2004/03/21 16:09:19 mva Exp $	 *)
MODULE OOC:AST [OOC_EXTENSIONS];
(*  Creates extended abstract syntax tree from the parser output.
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
  Strings, Object, OOC:Scanner:InputBuffer, OOC:Scanner:SymList, OOC:Doc,
  <*WITH Warnings:=FALSE DO*>OOC:Scanner:Symbol<*END (*for refs in docs*)*>;



(**
The syntax tree constructed by this module is a one-to-one representation
of the data passed to the factory methods of @otype{Builder}.  Every call
to a factory method creates a new object, which is filled with the
arguments of the method.  The result of @oproc{Builder.Module} is the
root of the generated syntax tree.

The principles behind the design of this module are:

@itemize
@item
All syntactic information discovered by the parser must be passed to the
builder.  This includes the structure of the document, as well as @emph{all}
terminal symbols, and their positions.

@item
The builder must be simple.  The classes and factory methods should be
easy to grasp, and their granularity should not be too small.

@item
The interface of the builder makes no assumptions how the parsed
information is used by the program.  It should serve equally well any
tool that is operating on the source code, for any purpose.
@end itemize


Data types, expressions, and statements are defined by several
syntactic entities.  If a rule of the grammar refers to the
@samp{Type} production, the actual type description that is part of
the abstract syntax tree is one of the @emph{concrete} type syntax
variants.  Types can be referenced or defined by one of these
constructions:

@table @asis
@item Unqualified Type Name
Such a type reference is created by @oproc{Builder.Terminal}.

@item Qualified Type Name
This is represented as a module name, followed by a selector name.  A
qualified type name is the result of @oproc{Builder.Operator}, using the
symbol @oconst{Symbol.period} as operator.

@item Array Type
Constructed by a call to @oproc{Builder.ArrayType}.

@item Record Type
Constructed by a call to @oproc{Builder.RecordType}.

@item Pointer Type
Constructed by a call to @oproc{Builder.PointerType}.

@item Procedure Type
Constructed by a call to @oproc{Builder.ProcType}.
@end table

Likewise, the grammar production @samp{Expr} is broken down into
several basic expression archetypes.  Most kinds of expressions are
mapped to dyadic or monadic operators, but there are also other
variants for specialized values.

@table @asis
@item Designator
A designator defines the place or the value of a variable, depending
of the context of its use.  Designators are created by repeated
application of @oproc{Builder.Terminal} (for identifiers),
@oproc{Builder.Operator} (for qualified identifiers, monadic, and
dyadic operators), @oproc{Builder.ArrayIndex} (one or more array
indexes), and @oproc{Builder.FunctionCall} (for function calls,
procedure calls, and type guards).  Please note that type guards are
mapped to functions calls on the syntax level, and that the designator
implementation of the parser is less restrictive than the Oberon-2
syntax, because of the limits of a recursive descent parser that
does not use any information from a symbol table.

@item Set Constructor
A set constructor is the result of a call to @oproc{Builder.Set}.  The
set is defined by a sequence of @oproc{Builder.Operator} using
@oconst{Symbol.upto} as operator.

@item Constants
Integer, string, and character constants, and the keyword @code{NIL}
are mapped to instances of @oproc{Builder.Terminal}.

@item Parenthesis
An expression in parenthesis is represented by @oproc{Builder.Factor}.

@item Operators
All monadic and dyadic operators, like @samp{~}, @samp{*}, @samp{+},
@samp{IN}, and so on, are mapped to results of
@oproc{Builder.Operator}.
@end table


Statement sequences are respresented by lists of statements, separated
by @samp{;}.  An empty statement is mapped to @code{NIL}.  For a
statement list @samp{statmSeq}, the list has this form:

@table @samp
@item statmList MOD 2 == 0
Result of any of the statement factory methods, or a function call, or 
@code{NIL} for the empty statement.
@item statmList MOD 2 == 1
The symbol @samp{;}, result of @oproc{Builder.Terminal}.
@end table

This module defines also a @samp{Visitor} pattern for the syntax tree.
The base class @otype{Visitor} defines visitor methods for every class
that is part of the syntax tree, and every node defines a corresponding
@samp{Accept} method.  The default action of the @samp{Visit} methods
is to do nothing.  The method @oproc{Visitor.VisitNodeList} calls 
@samp{Accept} on all element of the list that are not @code{NIL}.
*)

TYPE
  Name* = InputBuffer.CharArray;
  Node* = POINTER TO NodeDesc;
  NodeArray* = POINTER TO ARRAY OF Node;
  NodeDesc* = RECORD [ABSTRACT]
    (**Base type of all nodes that make up the abstract syntax tree.  *)
  END;

TYPE
  NodeList* = POINTER TO NodeListDesc;
  NodeListDesc* = RECORD
    (**Defines a simple list of nodes.  This is used to model repetition 
       like @samp{ident @{"," ident@}} in the syntax tree.  *)
    (NodeDesc)
    len-: LONGINT;
    (**The number of nodes in the list.  A value of zero means that the list
       is empty.  *)
    n-: NodeArray;
    (**This array holds the nodes of the list.  The elements 
       @samp{[0..@ofield{len}-1]} hold valid data.  If @ofield{len} is zero,
       then @ofield{n} is an array of length zero.  *)
  END;


TYPE
  Builder* = POINTER TO BuilderDesc;
  BuilderDesc* = RECORD
    (**Abstract builder class for the parser.  During parsing, the module
       @omodule{*OOC:Parser} will call the factory methods below to create
       the abstract syntax tree.  Typically, a factory method corresponds
       to the production of the grammar with the same name.  *)
    expectedModuleName-: Name;
    (**See @oproc{Builder.SetModuleName}.  *)
  END;



TYPE
  Flags* = POINTER TO FlagsDesc;
  Terminal* = POINTER TO TerminalDesc;
  TerminalDesc = RECORD
    (NodeDesc)
    sym-: SymList.Symbol;
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
    nameList-: NodeList;
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
    array-: Node;
    flags-: Flags;
    exprList-: NodeList;
    of-: Node;
    type-: Node;
  END;

TYPE
  FieldList* = POINTER TO FieldListDesc;
  FieldListDesc = RECORD
    (NodeDesc)
    identList-: NodeList;
    colon-: Node;
    type-: Node;
  END;

TYPE
  RecordType* = POINTER TO RecordTypeDesc;
  RecordTypeDesc = RECORD
    (TypeDesc)
    record-: Node;
    flags-: Flags;
    lParen-: Node;
    baseType-: Node;
    rParen-: Node;
    fieldLists-: NodeList;
    end-: Node;
  END;

TYPE
  PointerType* = POINTER TO PointerTypeDesc;
  PointerTypeDesc = RECORD
    (TypeDesc)
    pointer-: Node;
    flags-: Flags;
    to-: Node;
    type-: Node;
  END;


TYPE
  FPSection* = POINTER TO FPSectionDesc;
  FPSectionDesc = RECORD
    (NodeDesc)
    var-: Node;
    identList-: NodeList;
    colon-: Node;
    type-: Node;
  END;

TYPE
  FormalPars* = POINTER TO FormalParsDesc;
  FormalParsDesc = RECORD
    (NodeDesc)
    flags-: Flags;
    lParen-: Node;
    fpSections-: NodeList;           (* optional *)
    rParen-: Node;
    colon-: Node;
    result-: Node;
    raises-: Node;
    raisesList-: NodeList;
  END;

TYPE
  ProcType* = POINTER TO ProcTypeDesc;
  ProcTypeDesc = RECORD
    (TypeDesc)
    procedure-: Node;
    formalPars-: Node;
  END;

TYPE
  TPSection* = POINTER TO TPSectionDesc;
  TPSectionDesc = RECORD
    (NodeDesc)
    var-: Node;
    identList-: NodeList;
    colon-: Node;
    type-: Node;
  END;

TYPE
  TypePars* = POINTER TO TypeParsDesc;
  TypeParsDesc = RECORD
    (NodeDesc)
    lParen-: Node;
    tpSections-: NodeList;
    rParen-: Node;
  END;

TYPE
  QualType* = POINTER TO QualTypeDesc;
  QualTypeDesc = RECORD
    (NodeDesc)
    qualident-: Node;
    lParen-: Terminal;
    arguments-: NodeList;
    rParen-: Terminal;
  END;


TYPE
  ImportDecl* = POINTER TO ImportDeclDesc;
  ImportDeclDesc = RECORD
    (NodeDesc)
    alias-: Node;                    (* optional *)
    becomes-: Node;                  (* optional *)
    module-: ModuleIdent;                (* required *)
    moduleName-: Name;
  END;

TYPE
  ConstDecl* = POINTER TO ConstDeclDesc;
  ConstDeclDesc = RECORD
    (NodeDesc)
    identDef-: IdentDef;
    flags-: Flags;
    equal-: Node;
    expr-: Node;
    semicolon-: Node;
  END;

TYPE
  TypeDecl* = POINTER TO TypeDeclDesc;
  TypeDeclDesc = RECORD
    (NodeDesc)
    identDef-: IdentDef;
    flags-: Flags;
    typePars-: TypePars;
    equal-: Node;
    type-: Node;
    semicolon-: Node;
  END;

TYPE
  VarDecl* = POINTER TO VarDeclDesc;
  VarDeclDesc = RECORD
    (NodeDesc)
    identList-: NodeList;
    colon-: Node;
    type-: Node;
    semicolon-: Node;
  END;

TYPE
  Receiver* = POINTER TO ReceiverDesc;
  ReceiverDesc = RECORD
    (NodeDesc)
    lParen-: Node;
    var-: Node;
    ident-: IdentDef;
    colon-: Node;
    type-: Node;
    lParenAlias-: Terminal;
    aliasList-: NodeList;
    rParenAlias-: Terminal;
    rParen-: Node;
  END;

TYPE
  Body* = POINTER TO BodyDesc;
  BodyDesc = RECORD
    (NodeDesc)
    declSeq-: NodeList;
    begin-: Node;
    statmSeq-: NodeList;  (* may be NIL *)
    end-: Terminal;
    name-: Node;
  END;
  
TYPE
  ProcDecl* = POINTER TO ProcDeclDesc;
  ProcDeclDesc = RECORD
    (NodeDesc)
    proc-: Terminal;
    arrow-: Node;
    receiver-: Node;
    flags-: Flags;
    identDef-: IdentDef;
    formalPars-: Node;
    semicolon1-: Node;
    body-: Body;  (* can be NIL *)
    semicolon2-: Node;
  END;

TYPE
  ImportList* = POINTER TO ImportListDesc;
  ImportListDesc* = RECORD
    (NodeDesc)
    import-: Node;
    imports-: NodeList;
    semicolon-: Node;
  END;

TYPE
  Module* = POINTER TO ModuleDesc;
  ModuleDesc* = RECORD
    (NodeDesc)
    module-: Terminal;
    name-: ModuleIdent;
    flags-: Flags;
    semicolon-: Node;
    importList-: Node;
    body-: Body;  (* can be NIL *)
    period-: Node;
    
    moduleName-: Name;
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
    lParen-: Terminal;
    expr-: Node;
    rParen-: Terminal;
  END;

TYPE
  Set* = POINTER TO SetDesc;
  SetDesc = RECORD
    (NodeDesc)
    type-: Node;
    lBrace-: Terminal;
    elementList-: NodeList;
    rBrace-: Terminal;
  END;

TYPE
  ArrayIndex* = POINTER TO ArrayIndexDesc;
  ArrayIndexDesc = RECORD
    (NodeDesc)
    design-: Node;
    lBrak-: Terminal;
    indices-: NodeList;
    rBrak-: Terminal;
  END;

TYPE
  FunctionCall* = POINTER TO FunctionCallDesc;
  FunctionCallDesc = RECORD
    (NodeDesc)
    design-: Node;
    lParen-: Terminal;
    arguments-: NodeList;
    rParen-: Terminal;
  END;



TYPE
  Assignment* = POINTER TO AssignmentDesc;
  AssignmentDesc = RECORD
    (NodeDesc)
    assignment-: Operator;
  END;

TYPE
  ProcedureCall* = POINTER TO ProcedureCallDesc;
  ProcedureCallDesc = RECORD
    (NodeDesc)
    call-: Node;                    (* see @oproc{Builder.ProcedureCall} *)
  END;

TYPE
  IfStatm* = POINTER TO IfStatmDesc;
  IfStatmDesc = RECORD
    (NodeDesc)
    guardList-: NodeList;
    else-: Node;
    elseStatmSeq-: NodeList;
    end-: Node;
  END;

TYPE
  CaseStatm* = POINTER TO CaseStatmDesc;
  CaseStatmDesc = RECORD
    (NodeDesc)
    case-: Terminal;
    expr-: Node;
    of-: Node;
    caseList-: NodeList;
    else-: Node;
    elseStatmSeq-: NodeList;
    end-: Node;
  END;

TYPE
  WhileStatm* = POINTER TO WhileStatmDesc;
  WhileStatmDesc = RECORD
    (NodeDesc)
    while-: Terminal;
    guard-: Node;
    do-: Terminal;
    statmSeq-: NodeList;
    end-: Terminal;
  END;

TYPE
  RepeatStatm* = POINTER TO RepeatStatmDesc;
  RepeatStatmDesc = RECORD
    (NodeDesc)
    repeat-: Terminal;
    statmSeq-: NodeList;
    until-: Terminal;
    expr-: Node;
  END;

TYPE
  ForStatm* = POINTER TO ForStatmDesc;
  ForStatmDesc = RECORD
    (NodeDesc)
    for-: Terminal;
    ident-: Node;
    becomes-: Terminal;
    startValue-: Node;
    to-: Terminal;
    endValue-: Node;
    by-: Terminal;
    step-: Node;
    do-: Terminal;
    statmSeq-: NodeList;
    end-: Terminal;
  END;

TYPE
  IterateStatm* = POINTER TO IterateStatmDesc;
  IterateStatmDesc = RECORD
    (NodeDesc)
    for-: Terminal;
    ident-: Node;
    in-: Terminal;
    range-: Node;
    do-: Terminal;
    statmSeq-: NodeList;
    end-: Terminal;
  END;

TYPE
  LoopStatm* = POINTER TO LoopStatmDesc;
  LoopStatmDesc = RECORD
    (NodeDesc)
    loop-: Terminal;
    statmSeq-: NodeList;
    end-: Terminal;
  END;

TYPE
  WithStatm* = POINTER TO WithStatmDesc;
  WithStatmDesc = RECORD
    (NodeDesc)
    guardList-: NodeList;
    else-: Node;
    elseStatmSeq-: NodeList;
    end-: Node;
  END;

TYPE
  ExitStatm* = POINTER TO ExitStatmDesc;
  ExitStatmDesc = RECORD
    (NodeDesc)
    exit-: Terminal;
  END;

TYPE
  ReturnStatm* = POINTER TO ReturnStatmDesc;
  ReturnStatmDesc = RECORD
    (NodeDesc)
    return-: Terminal;
    expr-: Node;
  END;

TYPE
  Catch* = POINTER TO CatchDesc;
  CatchDesc = RECORD
    (NodeDesc)
    catch-: Terminal;
    type-: Node;
    lParen-: Node;  (* optional *)
    ident-: Terminal;   (* optional *)
    rParen-: Node;  (* optional *)
    colon-: Node;
    statmSeq-: NodeList;
  END;

TYPE
  TryStatm* = POINTER TO TryStatmDesc;
  TryStatmDesc = RECORD
    (NodeDesc)
    try-: Terminal;
    statmSeq-: NodeList;
    catchList-: NodeList;
    end-: Terminal;
  END;

TYPE
  FlagsDesc = RECORD
    (NodeDesc)
    context-: SHORTINT;
    lBrak-: Node;
    flagList-: NodeList;
    rBrak-: Node;
  END;

TYPE
  ProcIdFlag* = POINTER TO ProcIdFlagDesc;
  ProcIdFlagDesc = RECORD
    (NodeDesc)
    procId-: Node;
    equal-: Node;
    number-: Node;
  END;

TYPE
  ModuleFlags* = POINTER TO ModuleFlagsDesc;
  ModuleFlagsDesc = RECORD
    (NodeDesc)
    external-: Terminal;
    callConv-: Terminal;
    moduleFlags-: NodeList;
    semicolon-: Node;
    link-: Node;
    linkSections-: NodeList;
    end-: Node;
  END;

TYPE
  LinkFileFlag* = POINTER TO LinkFileFlagDesc;
  LinkFileFlagDesc = RECORD
    (NodeDesc)
    file-: Node;
    fileName-: Terminal;
    addOption-: Node;
    prefixOpt-: Terminal;
    comma-: Node;
    suffixOpt-: Terminal;
  END;

TYPE
  LinkObjFlag* = POINTER TO LinkObjFlagDesc;
  LinkObjFlagDesc = RECORD
    (NodeDesc)
    obj-: Node;
    fileName-: Node;
  END;

TYPE
  LinkLibFlag* = POINTER TO LinkLibFlagDesc;
  LinkLibFlagDesc = RECORD
    (NodeDesc)
    lib-: Node;
    libName-: Terminal;
    lParen-: Node;
    dependencies-: NodeList;
    rParen-: Node;
    addOption-: Node;
    prefixOpt-: Terminal;
    comma-: Node;
    suffixOpt-: Terminal;
  END;


CONST  (* ids for the various invocations of Flags(): *)
  flagsProcType* = 0;
  flagsArrayType* = 1;
  flagsRecordType* = 2;
  flagsPointerType* = 3;
  flagsConstDecl* = 4;
  flagsTypeDecl* = 5;
  flagsVariable* = 6;
  flagsField* = 7;
  flagsParameter* = 8;
  flagsProcedure* = 9;
  flagsModule* = 10;


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
        nl. n[i]. Accept (v)
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

PROCEDURE (v: Visitor) VisitTPSection* (tpSection: TPSection);
  END VisitTPSection;

PROCEDURE (v: Visitor) VisitTypePars* (typePars: TypePars);
  END VisitTypePars;

PROCEDURE (v: Visitor) VisitQualType* (qualType: QualType);
  END VisitQualType;


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

PROCEDURE (v: Visitor) VisitIterateStatm* (iterStatm: IterateStatm);
  END VisitIterateStatm;

PROCEDURE (v: Visitor) VisitLoopStatm* (loopStatm: LoopStatm);
  END VisitLoopStatm;

PROCEDURE (v: Visitor) VisitWithStatm* (withStatm: WithStatm);
  END VisitWithStatm;

PROCEDURE (v: Visitor) VisitExitStatm* (exitStatm: ExitStatm);
  END VisitExitStatm;

PROCEDURE (v: Visitor) VisitReturnStatm* (returnStatm: ReturnStatm);
  END VisitReturnStatm;

PROCEDURE (v: Visitor) VisitCatch* (catch: Catch);
  END VisitCatch;

PROCEDURE (v: Visitor) VisitTryStatm* (tryStatm: TryStatm);
  END VisitTryStatm;

(* flags *)
PROCEDURE (v: Visitor) VisitFlags* (flags: Flags);
  END VisitFlags;

PROCEDURE (v: Visitor) VisitProcIdFlag* (procIdFlag: ProcIdFlag);
  END VisitProcIdFlag;

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
    b.expectedModuleName := NIL;
  END Init;

PROCEDURE New* (): Builder;
  VAR
    b: Builder;
  BEGIN
    NEW (b);
    Init (b);
    RETURN b
  END New;

PROCEDURE InitNodeList (nl: NodeList);
(**Initializes a node list of length zero.  *)
  BEGIN
    nl. len := 0;
    NEW (nl. n, 8)
  END InitNodeList;

PROCEDURE (b: Builder) SetModuleName* (name: ARRAY OF CHAR);
(**Sets the expected module in the builder instance.  If set, then the parser
   will compare the expected with the actual module name, and report an error
   if they differ.  *)
  BEGIN
    NEW (b. expectedModuleName, Strings.Length (name)+1);
    COPY (name, b. expectedModuleName^);
  END SetModuleName;

PROCEDURE (b: Builder) NewNodeList* (): NodeList;
(**Creates a new node list of length zero.  *)
  VAR
    nl: NodeList;
  BEGIN
    NEW (nl);
    InitNodeList (nl);
    RETURN nl
  END NewNodeList;

PROCEDURE (nl: NodeList) Append* (node: Node);
(**Appends the node @oparam{node} to the list @oparam{nl}.  *)
  VAR
    i: LONGINT;
    new: NodeArray;
  BEGIN
    IF (nl. len = LEN (nl. n^)) THEN
      NEW (new, LEN (nl. n^)*2);
      FOR i := 0 TO LEN (nl. n^)-1 DO
        new[i] := nl. n[i]
      END;
      nl. n := new
    END;
    nl. n[nl. len] := node;
    INC (nl. len)
  END Append;

PROCEDURE (nl: NodeList) Accept* (v: Visitor);
  BEGIN
    v. VisitNodeList (nl)
  END Accept;


PROCEDURE (n: Node) AttachDocString* (docComment: Doc.Document);
(**If processing of documentation comments is enabled, this procedure is called
   whenever such a comment is found.  The node @oparam{n} is the result of
   a call to @oproc{Builder.IdentDef} or @oproc{*AST.Builder.ModuleIdent}.  The
   note the name of the nearest preceding valid declaration.  The default
   behaviour of this procedure is to do nothing.  It most be redefined in
   concrete definitions of @otype{Node}, or documentation comments will be
   silently discarded.
   
   Note: This procedure can be called more than once for a given node.  *)
  END AttachDocString;



PROCEDURE (b: Builder) Terminal* (sym: SymList.Symbol): Terminal;
(**Takes the symbol @oparam{sym} and creates a terminal node of the syntax
   tree.  In this context, @dfn{terminal} means that the node is a leaf of
   the tree.  *)
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

PROCEDURE (terminal: Terminal) GetString* (stripQuotes: BOOLEAN): STRING;
  BEGIN
    IF stripQuotes THEN
      RETURN Object.NewLatin1Region (terminal. sym. str^,
                               1, terminal. sym. len-1)
    ELSE
      RETURN Object.NewLatin1 (terminal. sym. str^)
    END
  END GetString;


PROCEDURE (b: Builder) IdentDef* (ident, mark: Terminal): IdentDef;
(**An identifier, possibly followed by an export mark.  This factory method
   is called for @emph{all} name definitions in a module, excluding import
   declarations and the module name itself.

   @table @oparam
   @item ident
   Result of @oproc{Builder.Terminal}.
   @item mark
   Result of @oproc{Builder.Terminal}, or @code{NIL} if no export mark
   is present.
   @end table  *)
  VAR
    id: IdentDef;
  BEGIN
    NEW (id);
    id. ident := ident;
    id. mark := mark;
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


PROCEDURE (b: Builder) ModuleIdent* (nameList: NodeList): Node;
(**A module name.  The @oparam{nameList} is is list of
   @oproc{Builder.Terminal}, with the even elements being identifiers, and the
   odd elements being @samp{:}.  *)
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

PROCEDURE (b: Builder) ArrayType* (array: Node; flags: Flags;
                                   exprList: NodeList; of, type: Node): Node;
(**Array type constructor.

   @table @oparam
   @item array
   The keyword @code{ARRAY}, result of @oproc{Builder.Terminal}.
   
   @item flags
   ...
   
   @item exprList
   A list of expressions that define the lengths of the array for dimension
   0, 1, and so on.  If no length is given, that is, if the array
   is of the @samp{open} kind, the length of the expression list is zero.
   This value is never @code{NIL}.
   
   @table @samp
   @item exprList MOD 2 == 0
   Result of any of the expression functions (@oproc{Builder.Operator},
   @oproc{Builder.Factor}, and so on).
   @item exprList MOD 2 == 1
   The symbol @samp{,}, result of @oproc{Builder.Terminal}.
   @end table
   
   @item of
   The keyword @code{OF}, result of @oproc{Builder.Terminal}.
   
   @item type
   A type reference or type constructor.
   @end table  *)
(**Array type constructor.

   @table @oparam
   @item array
   The keyword @code{ARRAY}, result of @oproc{Builder.Terminal}.
   
   @item flags
   ...
   
   @item exprList
   A list of expressions that define the lengths of the array for dimension
   0, 1, and so on.  If no length is given, that is, if the array
   is of the @samp{open} kind, the length of the expression list is zero.
   This value is never @code{NIL}.
   
   @table @samp
   @item exprList MOD 2 == 0
   Result of any of the expression functions (@oproc{Builder.Operator},
   @oproc{Builder.Factor}, and so on).
   @item exprList MOD 2 == 1
   The symbol @samp{,}, result of @oproc{Builder.Terminal}.
   @end table
   
   @item of
   The keyword @code{OF}, result of @oproc{Builder.Terminal}.
   
   @item type
   A type reference or type constructor.
   @end table  *)
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


PROCEDURE (b: Builder) FieldList* (identList: NodeList; colon, type: Node): Node;
(**Field list of a record definition.

   @table @oparam
   @item identList
   A list of identifiers and optional flags, separated by commas.
   
   @table @samp
   @item identList MOD 3 == 0
   A field name, result of @oproc{Builder.IdentDef}.
   @item identList MOD 3 == 1
   Flags (optional).
   @item identList MOD 3 == 2
   The symbol @samp{,}, result of @oproc{Builder.Terminal}.
   @end table
   
   @item colon
   The symbol @samp{:}, result of @oproc{Builder.Terminal}.
   
   @item type
   A type reference or type constructor.
   @end table  *)
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


PROCEDURE (b: Builder) RecordType* (record: Node; flags: Flags;
                                    lParen, baseType, rParen: Node;
                                    fieldLists: NodeList; end: Node): Node;
(**Record type constructor.

   @table @oparam
   @item record
   The symbol @samp{RECORD}, result of @oproc{Builder.Terminal}.
   
   @item flags
   ...
   
   @item lParen
   The symbol @samp{(}, result of @oproc{Builder.Terminal}, or @code{NIL}
   if the record has no base type.
   
   @item baseType
   A possibly qualified identifer, @oproc{Builder.Terminal} or 
   @oproc{Builder.Operator}.  This argument is @code{NIL} if the record
   has no base type.
   
   @item rParen
   The symbol @samp{)}, result of @oproc{Builder.Terminal}, or @code{NIL}
   if the record has no base type.
   
   @item fieldLists
   A list of field list definitions and comma symbols.  This argument is
   never @code{NIL}.  A field list declaration is the result of 
   @oproc{Builder.FieldList}.  Empty field list declarations are mapped
   to @code{NIL}.
   
   @table @samp
   @item fieldLists MOD 2 == 0
   A field list, result of @oproc{Builder.FieldList}, or @code{NIL}.
   @item identList MOD 2 == 1
   The symbol @samp{;}, result of @oproc{Builder.Terminal}.
   @end table
   
   @item end
   The symbol @samp{END}, result of @oproc{Builder.Terminal}.
   @end table  *)
(**Record type constructor.

   @table @oparam
   @item record
   The symbol @samp{RECORD}, result of @oproc{Builder.Terminal}.
   
   @item flags
   ...
   
   @item lParen
   The symbol @samp{(}, result of @oproc{Builder.Terminal}, or @code{NIL}
   if the record has no base type.
   
   @item baseType
   A possibly qualified identifer, @oproc{Builder.Terminal} or 
   @oproc{Builder.Operator}.  This argument is @code{NIL} if the record
   has no base type.
   
   @item rParen
   The symbol @samp{)}, result of @oproc{Builder.Terminal}, or @code{NIL}
   if the record has no base type.
   
   @item fieldLists
   A list of field list definitions and comma symbols.  This argument is
   never @code{NIL}.  A field list declaration is the result of 
   @oproc{Builder.FieldList}.  Empty field list declarations are mapped
   to @code{NIL}.
   
   @table @samp
   @item fieldLists MOD 2 == 0
   A field list, result of @oproc{Builder.FieldList}, or @code{NIL}.
   @item identList MOD 2 == 1
   The symbol @samp{;}, result of @oproc{Builder.Terminal}.
   @end table
   
   @item end
   The symbol @samp{END}, result of @oproc{Builder.Terminal}.
   @end table  *)
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


PROCEDURE (b: Builder) PointerType* (pointer: Node; flags: Flags;
                                     to, type: Node): Node;
(**Pointer type constructor.

   @table @oparam
   @item pointer
   The symbol @samp{POINTER}, result of @oproc{Builder.Terminal}.
   
   @item flags
   ...
   
   @item to
   The symbol @samp{TO}, result of @oproc{Builder.Terminal}.
   
   @item type
   A type reference or type constructor.
   @end table  *)
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


PROCEDURE (b: Builder) FPSection* (var: Node; identList: NodeList; colon, type: Node): Node;
(**Section of formal parameters.

   @table @oparam
   @item var
   The keyword @samp{VAR} (created by @oproc{Builder.Terminal}), or @code{NIL}
   if the section describes a list of value parameters.
   
   @item identList
   A list of identifiers and optional system flags, separated by commas.
   
   @table @samp
   @item identList MOD 3 == 0
   A field name, result of @oproc{Builder.Terminal}.
   @item identList MOD 3 == 1
   ...
   @item identList MOD 3 == 2
   The symbol @samp{,}, result of @oproc{Builder.Terminal}.
   @end table
   
   @item colon
   The symbol @samp{:}, result of @oproc{Builder.Terminal}.
   
   @item type
   A type reference or type constructor.
   @end table  *)
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


PROCEDURE (b: Builder) FormalPars* (flags: Flags; lParen: Node; fpSections: NodeList; rParen, colon, result, raises: Node; raisesList: NodeList): Node;
(**Formal parameter definition.  Note: If the formal parameter list is 
   completely empty, that is, if it does not even contain a parenthesis
   pair @samp{()}, all arguments from @oparam{lParen} onward are @code{NIL}.

   @table @oparam
   @item flags
   ...
   
   @item lParen
   The symbol @samp{(}, result of @oproc{Builder.Terminal}, or @code{NIL}
   if the formal parameter list is completely empty.
   
   @item fpSections
   A list of formal parameter sections.  This argument is only @code{NIL},
   if the formal parameter list is completely empty.
   
   @table @samp
   @item fpSections MOD 2 == 0
   A formal parameter section, result of @oproc{Builder.FPSection}, or
   possibly, for the last element of the list, the terminal symbol
   @oconst{Symbol.threeDots} (result of @oproc{Builder.Terminal}).
   @item fpSections MOD 2 == 1
   The symbol @samp{;}, result of @oproc{Builder.Terminal}.
   @end table
   
   @item rParen
   The symbol @samp{)}, result of @oproc{Builder.Terminal}, or @code{NIL}
   if the formal parameter list is completely empty.
   
   @item colon
   The symbol @samp{:}, result of @oproc{Builder.Terminal}, or @code{NIL}
   if the formal parameter list defines a procedure type.
   
   @item result
   A type reference or type constructor, or @code{NIL}
   if the formal parameter list defines a procedure type.

   @item raises
   The symbol @samp{RAISES}, result of @oproc{Builder.Terminal}, or @code{NIL}
   if the formal parameters do not declare any exceptions.
   
   @item raisesList
   A list of type names.  This argument is @code{NIL},
   if the formal parameters do not declare any exceptions.
   
   @table @samp
   @item raisesList MOD 2 == 0
   A qualified identifier, result of @oproc{Builder.Operator} or
   @oproc{Builder.Terminal}.
   @item fpSections MOD 2 == 1
   The symbol @samp{,}, result of @oproc{Builder.Terminal}.
   @end table
   
   @end table  *)
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
    fp. raises := raises;
    fp. raisesList := raisesList;
    RETURN fp
  END FormalPars;
  
PROCEDURE (formalPars: FormalPars) Accept* (v: Visitor);
  BEGIN
    v. VisitFormalPars (formalPars)
  END Accept;


PROCEDURE (b: Builder) ProcType* (procedure, formalPars: Node): Node;
(**Procedure type constructor.

   @table @oparam
   @item procedure
   The symbol @samp{PROCEDURE}, result of @oproc{Builder.Terminal}.
   
   @item formalPars
   The formal parameters of the procedure type.  This value is created
   by @oproc{Builder.FormalPars}.  It is never @code{NIL}.
   @end table  *)
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


PROCEDURE (b: Builder) TPSection* (identList: NodeList; colon, type: Node): Node;
(**Section of type parameters.

   @table @oparam
   @item identList
   A list of identifiers, separated by commas.
   
   @table @samp
   @item identList MOD 3 == 0
   A field name, result of @oproc{Builder.Terminal}.
   @item identList MOD 3 == 1
   The symbol @samp{,}, result of @oproc{Builder.Terminal}.
   @end table
   
   @item colon
   The symbol @samp{:}, result of @oproc{Builder.Terminal}.
   
   @item type
   A type name.
   @end table  *)
  VAR
    tp: TPSection;
  BEGIN
    NEW (tp);
    tp. identList := identList;
    tp. colon := colon;
    tp. type := type;
    RETURN tp
  END TPSection;

PROCEDURE (tpSection: TPSection) Accept* (v: Visitor);
  BEGIN
    v. VisitTPSection (tpSection)
  END Accept;


PROCEDURE (b: Builder) TypePars* (lParen: Node;
                                  tpSections: NodeList;
                                  rParen: Node): TypePars;
(**Type parameter definition.

   @table @oparam
   @item lParen
   The symbol @samp{<}, result of @oproc{Builder.Terminal}.
   
   @item tpSections
   A list of type parameter sections.  This list may have a length of zero.
   
   @table @samp
   @item tpSections MOD 2 == 0
   A formal parameter section, result of @oproc{Builder.TPSection}.
   @item fpSections MOD 2 == 1
   The symbol @samp{;}, result of @oproc{Builder.Terminal}.
   @end table
   
   @item rParen
   The symbol @samp{>}, result of @oproc{Builder.Terminal}.
   @end table  *)
  VAR
    tp: TypePars;
  BEGIN
    NEW (tp);
    tp. lParen := lParen;
    tp. tpSections := tpSections;
    tp. rParen := rParen;
    RETURN tp
  END TypePars;
  
PROCEDURE (typePars: TypePars) Accept* (v: Visitor);
  BEGIN
    v. VisitTypePars (typePars)
  END Accept;


PROCEDURE (b: Builder) QualType*(qualident: Node;
                                 lParen: Node;
                                 arguments: NodeList;
                                 rParen: Node): Node;
(**A qualified type reference.  This method is @emph{only} used if a parameter
   list is given.  That is, @oparam{lParen}, @oparam{arguments}, and
   @oparam{rParen} are never @code{NIL}.

   @table @oparam
   @item qualident
   The type name, @oproc{Builder.Terminal} or @oproc{Builder.Operator}.

   @item lParen
   The symbol @samp{<}, result of @oproc{Builder.Terminal}.

   @item arguments
   A list of type parameter sections.  This list may have a length of zero.

   @table @samp
   @item tpSections MOD 2 == 0
   A qualified type, @oproc{Builder.Terminal}, @oproc{Builder.Operator}, or
   @oproc{Builder.QualType}.
   @item fpSections MOD 2 == 1
   The symbol @samp{,}, result of @oproc{Builder.Terminal}.
   @end table

   @item rParen
   The symbol @samp{>}, result of @oproc{Builder.Terminal}.
   @end table  *)
  VAR
    qt: QualType;
  BEGIN
    NEW (qt);
    qt.qualident := qualident;
    qt.lParen := lParen(Terminal);
    qt.arguments := arguments;
    qt.rParen := rParen(Terminal);
    RETURN qt;
  END QualType;
  
PROCEDURE (qualType: QualType) Accept* (v: Visitor);
  BEGIN
    v. VisitQualType (qualType)
  END Accept;



PROCEDURE (b: Builder) ImportDecl* (alias, becomes, module: Node;
                                    moduleName: Name): Node;
(**An import declaration for a single module.

   @table @oparam
   @item alias
   If the declaration defines an alias name, the the value of this argument
   is created by @oproc{Builder.Terminal}.  Otherwise, it is @code{NIL}.
   
   @item becomes
   The symbol @samp{:=}, or @code{NIL} if no alias name is defined.
   
   @item module
   The imported module's name.  This is is an instance of
   @oproc{Builder.ModuleIdent}.
   
   @item moduleName
   The textual representation of the module name.  Contrary to @oparam{module},
   this is a single string.  It is the concatenation of all of the symbols in
   @oparam{module}.
   @end table  *)
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


PROCEDURE (b: Builder) ConstDecl* (identDef: Node; flags: Flags;
                                   equal, expr, semicolon: Node): Node;
(**Constant declaration.

   @table @oparam
   @item identDef
   The identifier, optionally followed by an export mark.  Result 
   of @oproc{Builder.IdentDef}.

   @item flags
   Declaration flags.
   
   @item equal
   The symbol @samp{=}, result of @oproc{Builder.Terminal}.
   
   @item expr
   An expression.  This can be any value produced by the syntax rule
   @samp{Expr} or it subclauses.
   
   @item semicolon
   The symbol @samp{;}, result of @oproc{Builder.Terminal}.
   @end table  *)
  VAR
    cd: ConstDecl;
  BEGIN
    NEW (cd);
    cd. identDef := identDef(IdentDef);
    cd. flags := flags;
    cd. equal := equal;
    cd. expr := expr;
    cd. semicolon := semicolon;
    RETURN cd
  END ConstDecl;

PROCEDURE (constDecl: ConstDecl) Accept* (v: Visitor);
  BEGIN
    v. VisitConstDecl (constDecl)
  END Accept;


PROCEDURE (b: Builder) TypeDecl* (identDef: Node; flags: Flags;
                                  typePars: TypePars; equal,
                                  type, semicolon: Node): Node;
(**Type declaration.

   @table @oparam
   @item identDef
   The identifier, optionally followed by an export mark.  Result of
   @oproc{Builder.IdentDef}.

   @item flags
   Declaration flags.
   
   @item typePars
   For a parameterized type, this is the list of type parameters (a result of
   @oproc{Builder.TypePars}).  Otherwise, it is @code{NIL}.

   @item equal
   The symbol @samp{=}, result of @oproc{Builder.Terminal}.

   @item type
   A type reference or type constructor.

   @item semicolon
   The symbol @samp{;}, result of @oproc{Builder.Terminal}.
   @end table  *)
  VAR
    td: TypeDecl;
  BEGIN
    NEW (td);
    td. identDef := identDef(IdentDef);
    td. flags := flags;
    td. typePars := typePars;
    td. equal := equal;
    td. type := type;
    td. semicolon := semicolon;
    RETURN td
  END TypeDecl;

PROCEDURE (typeDecl: TypeDecl) Accept* (v: Visitor);
  BEGIN
    v. VisitTypeDecl (typeDecl)
  END Accept;


PROCEDURE (b: Builder) VarDecl* (identList: NodeList; colon, type, semicolon: Node): Node;
(**Declaration of a variable or a list of variables.

   @table @oparam
   @item identList
   @item identList
   A list of identifiers and optional system flags, separated by commas.
   
   @table @samp
   @item identList MOD 3 == 0
   An identifier, optionally followed by an export mark, result of
   @oproc{Builder.IdentDef}.
   @item identList MOD 3 == 1
   ...
   @item identList MOD 3 == 2
   The symbol @samp{,}, result of @oproc{Builder.Terminal}.
   @end table
   
   @item colon
   The symbol @samp{:}, result of @oproc{Builder.Terminal}.
   
   @item type
   A type reference or type constructor.
   
   @item semicolon
   The symbol @samp{;}, result of @oproc{Builder.Terminal}.
   @end table  *)
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


PROCEDURE (b: Builder) Receiver* (lParen, var: Node; ident: IdentDef;
                                  colon, type: Node; lParenAlias: Terminal;
                                  aliasList: NodeList;
                                  rParenAlias: Terminal; rParen: Node): Node;
(**Receiver of the declaration of a type-bound procedure.

   @table @oparam
   @item lParen
   The symbol @samp{(}, result of @oproc{Builder.Terminal}.

   @item var
   The keyword @samp{VAR} (created by @oproc{Builder.Terminal}), or @code{NIL}
   if the receiver describes value parameter.

   @item ident
   An identifier, created by @oproc{Builder.Terminal}.

   @item colon
   The symbol @samp{:}, result of @oproc{Builder.Terminal}.

   @item type
   A type name, result of @oproc{Builder.Terminal}.

   @item lParenAlias
   If the receiver is for a parametric record type, this result of
   @oproc{Builder.Terminal} introduces the list of aliases for the type
   parameters.  Otherwise, it is @code{NIL}.

   @item aliasList
   List of @oproc{Builder.Terminal} values, even elements are identifiers, odd
   are @samp{,}.

   @item rParenAlias
   End of the alias list, result of @oproc{Builder.Terminal}.

   @item rParen
   The symbol @samp{)}, result of @oproc{Builder.Terminal}.
   @end table  *)
  VAR
    r: Receiver;
  BEGIN
    NEW (r);
    r. lParen := lParen;
    r. var := var;
    r. ident := ident;
    r. colon := colon;
    r. type := type;
    r. lParenAlias := lParenAlias;
    r. aliasList := aliasList;
    r. rParenAlias := rParenAlias;
    r. rParen := rParen;
    RETURN r
  END Receiver;

PROCEDURE (receiver: Receiver) Accept* (v: Visitor);
  BEGIN
    v. VisitReceiver (receiver)
  END Accept;


PROCEDURE (b: Builder) ProcDecl*(proc, arrow, receiver: Node; 
                                 flags: Flags;
                                 identDef, formalPars, semicolon1: Node;
                                 body: Body; semicolon2: Node): Node;
(**Procedure declaration.

   @table @oparam
   @item proc
   The keyword @samp{PROCEDURE}, result of @oproc{Builder.Terminal}.
   
   @item arrow
   The symbol @samp{^}, result of @oproc{Builder.Terminal}, if this is a
   forward declaration, and @code{NIL} otherwise.
   
   @item receiver
   An instance of @oproc{Builder.Receiver}, if this is a declaration of
   a type-bound procedure, and @code{NIL} otherwise.
   
   @item flags
   ...
   
   @item identDef
   The procedure name, optionally followed by an export mark.  Result 
   of @oproc{Builder.IdentDef}.

   @item formalPars
   The formal parameters of the procedure.  This value is created
   by @oproc{Builder.FormalPars}.  It is never @code{NIL}.
   
   @item semicolon1
   The symbol @samp{;}, result of @oproc{Builder.Terminal}.
   
   @item body
   For a regular procedure declaration, this argument describes the
   procedure body.  It is created by @oproc{Builder.Body}.  For a forward
   declaration, or a procedure prototype, this argument is @code{NIL}.
   
   @item semicolon2
   The symbol @samp{;}, result of @oproc{Builder.Terminal}.  This argument
   is @code{NIL}, iff @oparam{body} is @code{NIL}..
   @end table  *)
  VAR
    pd: ProcDecl;
  BEGIN
    NEW (pd);
    pd. proc := proc(Terminal);
    pd. arrow := arrow;
    pd. receiver := receiver;
    pd. flags := flags;
    pd. identDef := identDef(IdentDef);
    pd. formalPars := formalPars;
    pd. semicolon1 := semicolon1;
    pd. body := body;
    pd. semicolon2 := semicolon2;
    RETURN pd
  END ProcDecl;

PROCEDURE (procDecl: ProcDecl) Accept* (v: Visitor);
  BEGIN
    v. VisitProcDecl (procDecl)
  END Accept;


PROCEDURE (b: Builder) ImportList* (import: Node;
                               imports: NodeList; semicolon: Node): Node;
(**List of import declarations.

   @table @oparam
   @item import
   The keyword @samp{IMPORT} (created by @oproc{Builder.Terminal}).
   
   @item imports
   A list of import declarations, separated by commas.
   
   @table @samp
   @item identList MOD 2 == 0
   An import declaration, result of @oproc{Builder.ImportDecl}.
   @item identList MOD 2 == 1
   The symbol @samp{,}, result of @oproc{Builder.Terminal}.
   @end table
   
   @item semicolon
   The symbol @samp{;}, result of @oproc{Builder.Terminal}.
   @end table  *)
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


PROCEDURE (b: Builder) Body* (declSeq: NodeList;
                              begin: Node; statmSeq: NodeList; 
                              end, name: Node): Body;
(**Module or procedure body.

   @table @oparam
   @item declSeq
   A list of constant, type, variable, or procedure declarations, with an
   occasional keyword in between.  The keywords @samp{CONST}, @samp{TYPE},
   and @samp{VAR} appear as part of this list, and @emph{not} as part of
   any declarations.
   
   This list can contain instances created by these factory methods:
   
   @itemize @bullet
   @item @oproc{Builder.Terminal}
   @item @oproc{Builder.ConstDecl}
   @item @oproc{Builder.TypeDecl}
   @item @oproc{Builder.VarDecl}
   @item @oproc{Builder.ProcDecl}
   @end itemize
   
   @item begin
   The keyword @samp{BEGIN}, result of @oproc{Builder.Terminal}.  If 
   the body contains no statements, this keyword is optional and can
   be @code{NIL}.
   
   @item statmSeq
   A list of statements.  If there is no @samp{BEGIN} keyword, this 
   argument is @code{NIL}.

   @table @samp
   @item identList MOD 2 == 0
   A statement, or @code{NIL}.
   @item identList MOD 2 == 1
   The symbol @samp{;}, result of @oproc{Builder.Terminal}.
   @end table
   
   @item begin
   The keyword @samp{END}, result of @oproc{Builder.Terminal}.
   
   @item name
   The name of the module or procedure.  This is an instance of
   @oproc{Builder.ModuleIdent}.  Note that the parser checks
   if the name of the body matches that of the module or procedure.
   @end table  *)
  VAR
    body: Body;
  BEGIN
    NEW (body);
    body. declSeq := declSeq;
    body. begin := begin;
    body. statmSeq := statmSeq;
    body. end := end(Terminal);
    body. name := name;
    RETURN body
  END Body;

PROCEDURE (body: Body) Accept* (v: Visitor);
  BEGIN
    v. VisitBody (body)
  END Accept;


PROCEDURE (b: Builder) Module* (module: Terminal; name: Node;
                                flags: Flags; semicolon, importList: Node;
                                body: Body; period: Node;
                                moduleName: Name): Node;
(**Module declaration.

   @table @oparam
   @item module
   The keyword @samp{MODULE}, result of @oproc{Builder.Terminal}.
   
   @item name
   The name of the module, result of @oproc{Builder.ModuleIdent}.
   
   @item flags
   Either the result of @oproc{Builder.ModuleFlags} (for @samp{FOREIGN} and
   @samp{INTERFACE} modules) or a list of flags.
   
   @item semicolon
   The symbol @samp{;}, result of @oproc{Builder.Terminal}.
   
   @item importList
   An object create by @oproc{Builder.ImportList}, or @code{NIL} if the
   module has no imports.
   
   @item body
   The module body, result of @oproc{Builder.Body}.
   
   @item period
   The symbol @samp{.}, result of @oproc{Builder.Terminal}.
   
   @item moduleName
   The textual representation of the module name.  Contrary to @oparam{name},
   this is a single string.  It is the concatenation of all of the symbols in
   @oparam{name}.
   @end table  *)
  VAR
    m: Module;
  BEGIN
    NEW (m);
    m. module := module;
    m. name := name(ModuleIdent);
    m. flags := flags;
    m. semicolon := semicolon;
    m. importList := importList;
    m. body := body;
    m. period := period;
    m. moduleName := moduleName;
    RETURN m
  END Module;

PROCEDURE (module: Module) Accept* (v: Visitor);
  BEGIN
    v. VisitModule (module)
  END Accept;



PROCEDURE (b: Builder) Operator* (left, op, right: Node): Node;
(**This factory method covers all monadic and dyadic operators.  Please note
   that this also includes the operators of the rules @samp{Qualident}, 
   @samp{Designator}, and @samp{Assignment}.

   @table @oparam
   @item left
   The left operand, an arbitrary expression.  For monadic prefix operators,
   like @samp{+a} or @samp{~a}, this argument is @code{NIL}.
   
   @item op
   The operator symbol, result of @oproc{Builder.Terminal}.
   
   @item right
   The right operand, an arbitrary expression.  For monadic prefix operators,
   like @samp{a^}, this argument is @code{NIL}.
   @end table  *)
  VAR
    o: Operator;
  BEGIN
    NEW (o);
    IF (left = NIL) THEN
      o. left := NIL
    ELSE
      o. left := left
    END;
    o. op := op(Terminal);
    IF (right = NIL) THEN
      o. right := NIL
    ELSE
      o. right := right
    END;
    RETURN o
  END Operator;

PROCEDURE (operator: Operator) Accept* (v: Visitor);
  BEGIN
    v. VisitOperator (operator)
  END Accept;


PROCEDURE (b: Builder) Factor* (lParen, expr, rParen: Node): Node;
(**As far as the abstract syntax tree is concerned, a @samp{Factor} is
   a parenthised expression.  All other @samp{Factor} variants of the syntax
   are covered by other factory methods.
   
   @table @oparam
   @item lParen
   Left parenthesis, result of @oproc{Builder.Terminal}.
   
   @item expr
   An expression.
   
   @item rParen
   Right parenthesis, result of @oproc{Builder.Terminal}.
   @end table  *)
  VAR
    f: Factor;
  BEGIN
    NEW (f);
    f. lParen := lParen(Terminal);
    f. expr := expr;
    f. rParen := rParen(Terminal);
    RETURN f
  END Factor;

PROCEDURE (factor: Factor) Accept* (v: Visitor);
  BEGIN
    v. VisitFactor (factor)
  END Accept;


PROCEDURE (b: Builder) Set* (type, lBrace: Node; elementList: NodeList; rBrace: Node): Node;
(**Set constructor.

   @table @oparam
   @item type
   The optional type designator.  For the standard Oberon-2set constructor,
   this argument is @code{NIL}.
   
   @item lBrace
   Left brace @samp{@{}, result of @oproc{Builder.Terminal}.
   
   @item elementList
   A list of set elements, separated by commas.
   
   @table @samp
   @item identList MOD 2 == 0
   A set element.  This is either an expression denoting a single set element,
   or an operator of type @oconst{Symbol.upto}, denoting a range of set
   elements.
   
   @item identList MOD 2 == 1
   The symbol @samp{,}, result of @oproc{Builder.Terminal}.
   @end table
   
   @item rBrace
   Right brace @samp{@}}, result of @oproc{Builder.Terminal}.
   @end table  *)
  VAR
    s: Set;
  BEGIN
    NEW (s);
    s. type := type;
    s. lBrace := lBrace(Terminal);
    s. elementList := elementList;
    s. rBrace := rBrace(Terminal);
    RETURN s
  END Set;

PROCEDURE (set: Set) Accept* (v: Visitor);
  BEGIN
    v. VisitSet (set)
  END Accept;


PROCEDURE (b: Builder) ArrayIndex* (design, lBrak: Node; indices: NodeList; rBrak: Node): Node;
(**Element selector on array value.

   @table @oparam
   @item design
   The array designator.
   
   @item lBrak
   Left brace @samp{[}, result of @oproc{Builder.Terminal}.
   
   @item indices
   A list of array indices, separated by commas.
   
   @table @samp
   @item identList MOD 2 == 0
   An integer expression.
   
   @item identList MOD 2 == 1
   The symbol @samp{,}, result of @oproc{Builder.Terminal}.
   @end table
   
   @item rBrak
   Right brace @samp{]}, result of @oproc{Builder.Terminal}.
   @end table  *)
  VAR
    ai: ArrayIndex;
  BEGIN
    NEW (ai);
    ai. design := design;
    ai. lBrak := lBrak(Terminal);
    ai. indices := indices;
    ai. rBrak := rBrak(Terminal);
    RETURN ai
  END ArrayIndex;

PROCEDURE (arrayIndex: ArrayIndex) Accept* (v: Visitor);
  BEGIN
    v. VisitArrayIndex (arrayIndex)
  END Accept;


PROCEDURE (b: Builder) FunctionCall* (design, lParen: Node; arguments: NodeList; rParen: Node): Node;
(**Function call, procedure call, or type guard.  In the general case, the
   parser cannot detect, whether parenthesis within a designator is a function
   call, or a type guard.  For this reason, it treats a type guard as a kind of
   generalized function call and handles all function (and procedure) calls as
   part of the designator rule.

   @table @oparam
   @item design
   The function designator.
   
   @item lParen
   Left argument parenthesis @samp{(}, result of @oproc{Builder.Terminal}.
   
   @item arguments
   A list of function arguments, separated by commas.
   
   @table @samp
   @item identList MOD 2 == 0
   An expression.
   
   @item identList MOD 2 == 1
   The symbol @samp{,}, result of @oproc{Builder.Terminal}.
   @end table
   
   @item rParen
   Right arguments parenthesis @samp{)}, result of @oproc{Builder.Terminal}.
   @end table  *)
  VAR
    fc: FunctionCall;
  BEGIN
    NEW (fc);
    fc. design := design;
    fc. lParen := lParen(Terminal);
    fc. arguments := arguments;
    fc. rParen := rParen(Terminal);
    RETURN fc
  END FunctionCall;

PROCEDURE (functionCall: FunctionCall) Accept* (v: Visitor);
  BEGIN
    v. VisitFunctionCall (functionCall)
  END Accept;


PROCEDURE (b: Builder) Assignment* (assignment: Node): Node;
(**Value assignment.  This factory method is called if the statement begins
   with a designator, and is followed by a an assignment operator @samp{:=}.

   @table @oparam
   @item assignment
   An assignment operation, that is, an expression whose top node is
   the operator @samp{:=}.
   @end table  *)
  VAR
    a: Assignment;
  BEGIN
    NEW (a);
    a. assignment := assignment(Operator);
    RETURN a
  END Assignment;

PROCEDURE (assignment: Assignment) Accept* (v: Visitor);
  BEGIN
    v. VisitAssignment (assignment)
  END Accept;


PROCEDURE (b: Builder) ProcedureCall* (call: Node): Node;
(**Procedure call.  This factory method is called if the statement begins
   with a designator, but is not followed by a an assignment operator
   @samp{:=}.

   @table @oparam
   @item call
   A designator.  If @oparam{call} is already an instance of
   @oproc{Builder.FunctionCall}, then the additional procedure call
   wrapper is redundant and @emph{must} be ignored.
   @end table  *)
  VAR
    p: ProcedureCall;
  BEGIN
    NEW (p);
    p. call := call;
    RETURN p
  END ProcedureCall;

PROCEDURE (procedureCall: ProcedureCall) Accept* (v: Visitor);
  BEGIN
    v. VisitProcedureCall (procedureCall)
  END Accept;


PROCEDURE (b: Builder) IfStatm* (guardList: NodeList; else: Node; elseStatmSeq: NodeList; end: Node): Node;
(**Conditional statement.

   @table @oparam
   @item guardList
   This is the list of all guarded commands.  It is a sequence of keywords,
   boolean expressions, and statement sequences.
   
   @table @samp
   @item guardList MOD 4 == 0
   Either the keyword @samp{IF}, for the very first guarded command, and
   the keyword @samp{ELSIF} for any further guarded command.
   
   @item guardList MOD 4 == 1
   A boolean expression.
   
   @item guardList MOD 4 == 2
   The keyword @samp{THEN}.
   
   @item guardList MOD 4 == 3
   The statement sequence of the guarded command.
   @end table

   @item else
   The keyword @samp{ELSE}, result of @oproc{Builder.Terminal}, or @code{NIL}
   if the statement does not include an @code{ELSE} part.
   
   @item elseStatmSeq
   The statement sequence of the optional @code{ELSE} part.  This argument
   is @code{NIL}, iff @oparam{else} is @code{NIL}.
   
   @item end
   The keyword @samp{END}, result of @oproc{Builder.Terminal}
   @end table  *)
  VAR
    i: IfStatm;
  BEGIN
    NEW (i);
    i. guardList := guardList;
    i. else := else;
    IF (elseStatmSeq # NIL) THEN
      i. elseStatmSeq := elseStatmSeq;
    ELSE
      i. elseStatmSeq := NIL;
    END;
    i. end := end;
    RETURN i
  END IfStatm;

PROCEDURE (ifStatm: IfStatm) Accept* (v: Visitor);
  BEGIN
    v. VisitIfStatm (ifStatm)
  END Accept;


PROCEDURE (b: Builder) CaseStatm* (case, expr, of: Node; caseList: NodeList; else: Node; elseStatmSeq: NodeList; end: Node): Node;
(**Case statement.
   
   @table @oparam
   @item case
   The keyword @samp{CASE}.
   
   @item expr
   The selection expression of the statement.
   
   @item of
   The keyword @samp{OF}.
   
   @item caseList
   This is the list of all branches of the @code{CASE} statement.
   It is a sequence of instances of lists of case labels, colons,
   statements sequences, and separator symbols @samp{|}.
   
   @table @samp
   @item caseList MOD 4 == 0
   Either a list of case labels, or @code{NIL} if the branch
   is completely empty.
   
   @table @samp
   @item labelList MOD 2 == 0
   An expression, possibly an operator of the class @oconst{Symbol.upto}.
   
   @item labelList MOD 2 == 1
   The symbol @samp{,}.
   @end table

   @item caseList MOD 4 == 1
   The symbol @samp{:}, or @code{NIL} if the branch is empty.
   
   @item caseList MOD 4 == 2
   The statement sequence of the @code{CASE} branch, or @code{NIL}
   if the branch is completely empty.
   
   @item caseList MOD 4 == 3
   The symbol @samp{|}, or @code{NIL} if no further case branches
   follow.
   @end table

   @item else
   The keyword @samp{ELSE}, result of @oproc{Builder.Terminal}, or @code{NIL}
   if the statement does not include an @code{ELSE} part.
   
   @item elseStatmSeq
   The statement sequence of the optional @code{ELSE} part.  This argument
   is @code{NIL}, iff @oparam{else} is @code{NIL}.
   
   @item end
   The keyword @samp{END}, result of @oproc{Builder.Terminal}
   @end table  *)
  VAR
    c: CaseStatm;
  BEGIN
    NEW (c);
    c. case := case(Terminal);
    c. expr := expr;
    c. of := of;
    c. caseList := caseList;
    c. else := else;
    IF (elseStatmSeq = NIL) THEN
      c. elseStatmSeq := NIL;
    ELSE
      c. elseStatmSeq := elseStatmSeq;
    END;
    c. end := end;
    RETURN c
  END CaseStatm;

PROCEDURE (caseStatm: CaseStatm) Accept* (v: Visitor);
  BEGIN
    v. VisitCaseStatm (caseStatm)
  END Accept;


PROCEDURE (b: Builder) WhileStatm* (while, guard, do: Node; statmSeq: NodeList; end: Node): Node;
(**@code{WHILE} loop.

   @table @oparam
   @item while
   The keyword @samp{WHILE}.
   
   @item guard
   A boolean expression.
   
   @item do
   The keyword @samp{DO}.
   
   @item statmSeq
   The statement sequence of the loop.
   
   @item end
   The keyword @samp{END}.
   @end table  *)
  VAR
    w: WhileStatm;
  BEGIN
    NEW (w);
    w. while := while(Terminal);
    w. guard := guard;
    w. do := do(Terminal);
    w. statmSeq := statmSeq;
    w. end := end(Terminal);
    RETURN w
  END WhileStatm;

PROCEDURE (whileStatm: WhileStatm) Accept* (v: Visitor);
  BEGIN
    v. VisitWhileStatm (whileStatm)
  END Accept;


PROCEDURE (b: Builder) RepeatStatm* (repeat: Node; statmSeq: NodeList; until, expr: Node): Node;
(**@code{REPEAT} loop.

   @table @oparam
   @item repeat
   The keyword @samp{REPEAT}.
   
   @item statmSeq
   The statement sequence of the loop.
   
   @item until
   The keyword @samp{UNTIL}.
   
   @item expr
   A boolean expression.
   @end table  *)
  VAR
    r: RepeatStatm;
  BEGIN
    NEW (r);
    r. repeat := repeat(Terminal);
    r. statmSeq := statmSeq;
    r. until := until(Terminal);
    r. expr := expr;
    RETURN r
  END RepeatStatm;

PROCEDURE (repeatStatm: RepeatStatm) Accept* (v: Visitor);
  BEGIN
    v. VisitRepeatStatm (repeatStatm)
  END Accept;


PROCEDURE (b: Builder) ForStatm* (for, ident, becomes, startValue, to, endValue, by, step, do: Node; statmSeq: NodeList; end: Node): Node;
(**@code{FOR} loop.

   @table @oparam
   @item for
   The keyword @samp{FOR}.
   
   @item ident
   A variable identifier, result of @oproc{Builder.Terminal}.
   
   @item becomes
   The symbol @samp{:=}.
   
   @item startValue
   An expression.
   
   @item to
   The keyword @samp{TO}.
   
   @item endValue
   An expression.
   
   @item by
   The keyword @samp{BY}.  This argument is @code{NIL}, if the loop
   does not include a step clause.
   
   @item step
   An expression.  This argument is @code{NIL}, iff @oparam{by} is @code{NIL}.
   
   @item do
   The keyword @samp{DO}.
   
   @item statmSeq
   The statement sequence of the loop.
   
   @item end
   The keyword @samp{END}.
   @end table  *)
  VAR
    f: ForStatm;
  BEGIN
    NEW (f);
    f. for := for(Terminal);
    f. ident := ident;
    f. becomes := becomes(Terminal);
    f. startValue := startValue;
    f. to := to(Terminal);
    f. endValue := endValue;
    IF (step = NIL) THEN
      f. by := NIL;
      f. step := NIL;
    ELSE
      f. by := by(Terminal);
      f. step := step;
    END;
    f. do := do(Terminal);
    f. statmSeq := statmSeq;
    f. end := end(Terminal);
    RETURN f
  END ForStatm;

PROCEDURE (forStatm: ForStatm) Accept* (v: Visitor);
  BEGIN
    v. VisitForStatm (forStatm)
  END Accept;


PROCEDURE (b: Builder) IterateStatm* (for, ident, in, range, do: Node; statmSeq: NodeList; end: Node): Node;
(**@code{FOR} loop.

   @table @oparam
   @item for
   The keyword @samp{FOR}.
   
   @item ident
   A variable identifier, result of @oproc{Builder.Terminal}.
   
   @item in
   The symbol @samp{IN}.
   
   @item range
   An expression.
   
   @item do
   The keyword @samp{DO}.
   
   @item statmSeq
   The statement sequence of the loop.
   
   @item end
   The keyword @samp{END}.
   @end table  *)
  VAR
    f: IterateStatm;
  BEGIN
    NEW (f);
    f. for := for(Terminal);
    f. ident := ident;
    f. in := in(Terminal);
    f. range := range;
    f. do := do(Terminal);
    f. statmSeq := statmSeq;
    f. end := end(Terminal);
    RETURN f
  END IterateStatm;

PROCEDURE (iterStatm: IterateStatm) Accept* (v: Visitor);
  BEGIN
    v. VisitIterateStatm (iterStatm)
  END Accept;


PROCEDURE (b: Builder) LoopStatm* (loop: Node; statmSeq: NodeList; end: Node): Node;
(**The generic loop.

   @table @oparam
   @item loop
   The keyword @samp{LOOP}.
   
   @item statmSeq
   The statement sequence of the loop.
   
   @item end
   The keyword @samp{END}.
   @end table  *)
  VAR
    l: LoopStatm;
  BEGIN
    NEW (l);
    l. loop := loop(Terminal);
    l. statmSeq := statmSeq;
    l. end := end(Terminal);
    RETURN l
  END LoopStatm;

PROCEDURE (loopStatm: LoopStatm) Accept* (v: Visitor);
  BEGIN
    v. VisitLoopStatm (loopStatm)
  END Accept;


PROCEDURE (b: Builder) WithStatm* (guardList: NodeList; else: Node; elseStatmSeq: NodeList; end: Node): Node;
(**Regional type guard.

   @table @oparam
   @item guardList
   This is the list of all guarded commands.  It is a sequence of keywords,
   type guard expressions, and statement sequences.
   
   @table @samp
   @item guardList MOD 4 == 0
   Either the keyword @samp{WITH}, for the very first guarded command, and
   the symbol @samp{|} for any further guarded command.
   
   @item guardList MOD 4 == 1
   A type guard expression, an operator of class @oconst{Symbol.colon}.
   
   @item guardList MOD 4 == 2
   The keyword @samp{DO}.
   
   @item guardList MOD 4 == 3
   The statement sequence of the guarded command.
   @end table

   @item else
   The keyword @samp{ELSE}, result of @oproc{Builder.Terminal}, or @code{NIL}
   if the statement does not include an @code{ELSE} part.
   
   @item elseStatmSeq
   The statement sequence of the optional @code{ELSE} part.  This argument
   is @code{NIL}, iff @oparam{else} is @code{NIL}.
   
   @item end
   The keyword @samp{END}, result of @oproc{Builder.Terminal}
   @end table  *)
  VAR
    w: WithStatm;
  BEGIN
    NEW (w);
    w. guardList := guardList;
    w. else := else;
    IF (elseStatmSeq # NIL) THEN
      w. elseStatmSeq := elseStatmSeq;
    ELSE
      w. elseStatmSeq := NIL;
    END;
    w. end := end;
    RETURN w
  END WithStatm;

PROCEDURE (withStatm: WithStatm) Accept* (v: Visitor);
  BEGIN
    v. VisitWithStatm (withStatm)
  END Accept;


PROCEDURE (b: Builder) ExitStatm* (exit: Node): Node;
(**@code{EXIT} statement.

   @table @oparam
   @item exit
   The keyword @samp{EXIT}.
   @end table  *)
  VAR
    e: ExitStatm;
  BEGIN
    NEW (e);
    e. exit := exit(Terminal);
    RETURN e
  END ExitStatm;

PROCEDURE (exitStatm: ExitStatm) Accept* (v: Visitor);
  BEGIN
    v. VisitExitStatm (exitStatm)
  END Accept;


PROCEDURE (b: Builder) ReturnStatm* (return, expr: Node): Node;
(**@code{RETURN} statement.

   @table @oparam
   @item return
   The keyword @samp{RETURN}.
   
   @item expr
   An expression.  This argument is @code{NIL}, if the return statement
   does not include a function result.
   @end table  *)
  VAR
    r: ReturnStatm;
  BEGIN
    NEW (r);
    r. return := return(Terminal);
    r. expr := expr;
    RETURN r
  END ReturnStatm;

PROCEDURE (returnStatm: ReturnStatm) Accept* (v: Visitor);
  BEGIN
    v. VisitReturnStatm (returnStatm)
  END Accept;


PROCEDURE (b: Builder) Catch*(catch, type, lParen, ident, rParen,
                              colon: Node; statmSeq: NodeList): Node;
(**Catch clause of a @code{TRY} statement.

   @table @oparam
   @item catch
   The keyword @samp{CATCH}.
   
   @item type
   A type name, matching the rule of @samp{Qualident}.
   
   @item lParen
   The terminal symbol @samp{(}, or @code{NIL}.
   
   @item ident
   The optional exception name.
   
   @item rParen
   The terminal symbol @samp{)}, or @code{NIL}.
   
   @item colon
   The terminal symbol @samp{:}, or @code{NIL}.
   
   @item statmSeq
   The statement sequence of the catch block.
   @end table  *)
  VAR
    c: Catch;
  BEGIN
    NEW(c);
    c.catch := catch(Terminal);
    c.type := type;
    c.lParen := lParen;
    IF (ident = NIL) THEN
      c.ident := NIL;
    ELSE
      c.ident := ident(Terminal);
    END;
    c.rParen := rParen;
    c.colon := colon;
    c.statmSeq := statmSeq;
    RETURN c;
  END Catch;

PROCEDURE (catch: Catch) Accept* (v: Visitor);
  BEGIN
    v. VisitCatch (catch)
  END Accept;

PROCEDURE (b: Builder) TryStatm* (try: Node; statmSeq: NodeList;
                                  catchList: NodeList; end: Node): Node;
(**Exception handler statement.

   @table @oparam
   @item try
   The keyword @samp{TRY}, result of @oproc{Builder.Terminal}.
   
   @item statmSeq
   The statement sequence of the @samp{TRY}'s body.
   
   @item catchList
   This is the list of all catch blocks.  It is a sequence of nodes
   produced by @oproc{Builder.Catch}.

   @item end
   The keyword @samp{END}, result of @oproc{Builder.Terminal}
   @end table  *)
  VAR
    t: TryStatm;
  BEGIN
    NEW (t);
    t.try := try(Terminal);
    t.statmSeq := statmSeq;
    t.catchList := catchList;
    t.end := end(Terminal);
    RETURN t;
  END TryStatm;

PROCEDURE (tryStatm: TryStatm) Accept* (v: Visitor);
  BEGIN
    v. VisitTryStatm (tryStatm)
  END Accept;



PROCEDURE (b: Builder) Flags* (context: SHORTINT; lBrak: Node;
                               flagList: NodeList; rBrak: Node): Flags;
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

PROCEDURE (b: Builder) ProcWithoutBody* (moduleFlags, procFlags: Node): BOOLEAN;
(**This predicate determines, if a procedure declaration without a forward
   flag has a procedure body.  For declarations in a normal body, it returns
   always @code{FALSE}.  For a procedure declaration in an @samp{INTERFACE} or
   @samp{FOREIGN} module, the result depends on the presence of the
   @samp{HAS_BODY} flag.  *)
  VAR
    i: LONGINT;
    n: Node;
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


PROCEDURE (b: Builder) ProcIdFlag* (procId, equal, number: Node): Node;
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


PROCEDURE (b: Builder) ModuleFlags* (
             external,  callConv: Node; moduleFlags: NodeList;
             semicolon, link: Node;
             linkSections: NodeList; end: Node): Node;
  VAR
    mf: ModuleFlags;
  BEGIN
    NEW (mf);
    mf. external := external(Terminal);
    mf. callConv := callConv(Terminal);
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


PROCEDURE (b: Builder) LinkFileFlag* (file, fileName, addOption, prefixOpt, comma, suffixOpt: Node): Node;
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


PROCEDURE (b: Builder) LinkObjFlag* (obj, fileName: Node): Node;
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


PROCEDURE (b: Builder) LinkLibFlag* (lib, libName, lParen: Node;
                  dependencies: NodeList;
                  rParen, addOption, prefixOpt, comma, suffixOpt: Node): Node;
  VAR
    llf: LinkLibFlag;
  BEGIN
    NEW (llf);
    llf. lib := lib;
    llf. libName := libName(Terminal);
    llf. lParen := lParen;
    IF (dependencies = NIL) THEN
      llf. dependencies := NIL;
    ELSE
      llf. dependencies := dependencies;
    END;
    llf. rParen := rParen;
    llf. addOption := addOption;
    IF (prefixOpt = NIL) THEN
      llf. prefixOpt := NIL
    ELSE
      llf. prefixOpt := prefixOpt(Terminal)
    END;
    llf. comma := comma;
    IF (suffixOpt = NIL) THEN
      llf. suffixOpt := NIL
    ELSE
      llf. suffixOpt := suffixOpt(Terminal)
    END;
    RETURN llf
  END LinkLibFlag;

PROCEDURE (linkLibFlag: LinkLibFlag) Accept* (v: Visitor);
  BEGIN
    v. VisitLinkLibFlag (linkLibFlag)
  END Accept;

END OOC:AST.
