(* 	$Id$	 *)
MODULE OOC:AST [OOC_EXTENSIONS];
(*  Abstract builder class for parser output.
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
  Strings, OOC:Scanner:InputBuffer, OOC:Doc, OOC:Scanner:BasicList,
  <*PUSH; Warnings:=FALSE*>OOC:Scanner:Symbol<*POP (*for refs in docs*)*>;

TYPE
  Name* = InputBuffer.CharArray;
  
TYPE
  Node* = POINTER TO NodeDesc;
  NodeDesc* = RECORD [ABSTRACT]
    (**Base type of all nodes that make up the abstract syntax tree.  *)
  END;

TYPE
  NodeArray* = POINTER TO ARRAY OF Node;
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
  BuilderDesc* = RECORD [ABSTRACT]
    (**Abstract builder class for the parser.  During parsing, the module
       @omodule{*OOC:Parser} will call the factory methods below to create
       the abstract syntax tree.  Typically, a factory method corresponds
       to the production of the grammar with the same name.  *)
    expectedModuleName-: Name;
    (**See @oproc{Builder.SetModuleName}.  *)
  END;

(**
The design of this abstract syntax tree builder was governed by these
principles:

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
*)


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

PROCEDURE InitNodeList* (nl: NodeList);
(**Initializes a node list of length zero.  *)
  BEGIN
    nl. len := 0;
    NEW (nl. n, 8)
  END InitNodeList;

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



PROCEDURE InitBuilder* (b: Builder);
  BEGIN
    b. expectedModuleName := NIL;
  END InitBuilder;

PROCEDURE (b: Builder) SetModuleName* (name: ARRAY OF CHAR);
(**Sets the expected module in the builder instance.  If set, then the parser
   will compare the expected with the actual module name, and report an error
   if they differ.  *)
  BEGIN
    NEW (b. expectedModuleName, Strings.Length (name)+1);
    COPY (name, b. expectedModuleName^);
  END SetModuleName;

PROCEDURE (b: Builder) [ABSTRACT] Terminal* (sym: BasicList.Symbol): Node;
(**Takes the symbol @oparam{sym} and creates a terminal node of the syntax
   tree.  In this context, @dfn{terminal} means that the node is a leaf of
   the tree.  *)
  END Terminal;

PROCEDURE (b: Builder) [ABSTRACT] IdentDef* (ident, mark: Node): Node;
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
  END IdentDef;

PROCEDURE (b: Builder) [ABSTRACT] ModuleIdent* (nameList: NodeList): Node;
(**A module name.  The @oparam{nameList} is is list of
   @oproc{Builder.Terminal}, with the even elements being identifiers, and the
   odd elements being @samp{:}.  *)
  END ModuleIdent;

PROCEDURE (b: Builder) [ABSTRACT] ArrayType* (array, flags: Node; exprList: NodeList; of, type: Node): Node;
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
  END ArrayType;

PROCEDURE (b: Builder) [ABSTRACT] FieldList* (identList: NodeList; colon, type: Node): Node;
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
  END FieldList;

PROCEDURE (b: Builder) [ABSTRACT] RecordType* (record, flags, lParen, qualident, rParen: Node; fieldLists: NodeList; end: Node): Node;
(**Record type constructor.

   @table @oparam
   @item record
   The symbol @samp{RECORD}, result of @oproc{Builder.Terminal}.
   
   @item flags
   ...
   
   @item lParen
   The symbol @samp{(}, result of @oproc{Builder.Terminal}, or @code{NIL}
   if the record has no base type.
   
   @item qualident
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
  END RecordType;

PROCEDURE (b: Builder) [ABSTRACT] PointerType* (pointer, flags, to, type: Node): Node;
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
  END PointerType;

PROCEDURE (b: Builder) [ABSTRACT] FPSection* (var: Node; identList: NodeList; colon, type: Node): Node;
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
  END FPSection;

PROCEDURE (b: Builder) [ABSTRACT] FormalPars* (flags, lParen: Node;
                                               fpSections: NodeList;
                                               rParen, colon, result: Node;
                                               raises: Node;
                                               raisesList: NodeList): Node;
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
  END FormalPars;
  
PROCEDURE (b: Builder) [ABSTRACT] ProcType* (procedure, formalPars: Node): Node;
(**Procedure type constructor.

   @table @oparam
   @item procedure
   The symbol @samp{PROCEDURE}, result of @oproc{Builder.Terminal}.
   
   @item formalPars
   The formal parameters of the procedure type.  This value is created
   by @oproc{Builder.FormalPars}.  It is never @code{NIL}.
   @end table  *)
  END ProcType;

PROCEDURE (b: Builder) [ABSTRACT] TPSection* (identList: NodeList; colon, type: Node): Node;
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
  END TPSection;

PROCEDURE (b: Builder) [ABSTRACT] TypePars* (lParen: Node;
                                             tpSections: NodeList;
                                             rParen: Node): Node;
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
  END TypePars;
  
PROCEDURE (b: Builder) [ABSTRACT] QualType* (qualident: Node;
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
  END QualType;
  

PROCEDURE (b: Builder) [ABSTRACT] ImportDecl* (alias, becomes, module: Node;
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
  END ImportDecl;

PROCEDURE (b: Builder) [ABSTRACT] ConstDecl* (identDef, flags, equal, expr, semicolon: Node): Node;
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
  END ConstDecl;

PROCEDURE (b: Builder) [ABSTRACT] TypeDecl* (identDef, flags, typePars, equal,
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
  END TypeDecl;

PROCEDURE (b: Builder) [ABSTRACT] VarDecl* (identList: NodeList; colon, type, semicolon: Node): Node;
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
  END VarDecl;

PROCEDURE (b: Builder) [ABSTRACT] Receiver* (lParen, var, ident, colon, type,
                                             lParenAlias: Node;
                                             aliasList: NodeList;
                                             rParenAlias, rParen: Node): Node;
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
  END Receiver;

PROCEDURE (b: Builder) [ABSTRACT] ProcDecl* (proc, arrow, receiver, 
                                 flags, identDef, formalPars, semicolon1,
                                 body, semicolon2: Node): Node;
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
  END ProcDecl;

PROCEDURE (b: Builder) [ABSTRACT] ImportList* (import: Node;
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
  END ImportList;

PROCEDURE (b: Builder) [ABSTRACT] Body* (declSeq: NodeList; 
                                         begin: Node; statmSeq: NodeList;
                                         end, name: Node): Node;
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
  END Body;

PROCEDURE (b: Builder) [ABSTRACT] Module* (module, name,
                 flags, semicolon, importList, body, period: Node;
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
  END Module;


PROCEDURE (b: Builder) [ABSTRACT] Operator* (left, op, right: Node): Node;
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
  END Operator;

PROCEDURE (b: Builder) [ABSTRACT] Factor* (lParen, expr, rParen: Node): Node;
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
  END Factor;

PROCEDURE (b: Builder) [ABSTRACT] Set* (type, lBrace: Node; elementList: NodeList; rBrace: Node): Node;
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
  END Set;

PROCEDURE (b: Builder) [ABSTRACT] ArrayIndex* (design, lBrak: Node; indices: NodeList; rBrak: Node): Node;
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
  END ArrayIndex;

PROCEDURE (b: Builder) [ABSTRACT] FunctionCall* (design, lParen: Node; arguments: NodeList; rParen: Node): Node;
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
  END FunctionCall;


PROCEDURE (b: Builder) [ABSTRACT] Assignment* (assignment: Node): Node;
(**Value assignment.  This factory method is called if the statement begins
   with a designator, and is followed by a an assignment operator @samp{:=}.

   @table @oparam
   @item assignment
   An assignment operation, that is, an expression whose top node is
   the operator @samp{:=}.
   @end table  *)
  END Assignment;

PROCEDURE (b: Builder) [ABSTRACT] ProcedureCall* (call: Node): Node;
(**Procedure call.  This factory method is called if the statement begins
   with a designator, but is not followed by a an assignment operator
   @samp{:=}.

   @table @oparam
   @item call
   A designator.  If @oparam{call} is already an instance of
   @oproc{Builder.FunctionCall}, then the additional procedure call
   wrapper is redundant and @emph{must} be ignored.
   @end table  *)
  END ProcedureCall;

PROCEDURE (b: Builder) [ABSTRACT] IfStatm* (guardList: NodeList; else: Node; elseStatmSeq: NodeList; end: Node): Node;
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
  END IfStatm;

PROCEDURE (b: Builder) [ABSTRACT] CaseStatm* (case, expr, of: Node; caseList: NodeList; else: Node; elseStatmSeq: NodeList; end: Node): Node;
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
  END CaseStatm;

PROCEDURE (b: Builder) [ABSTRACT] WhileStatm* (while, guard, do: Node; statmSeq: NodeList; end: Node): Node;
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
  END WhileStatm;

PROCEDURE (b: Builder) [ABSTRACT] RepeatStatm* (repeat: Node; statmSeq: NodeList; until, expr: Node): Node;
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
  END RepeatStatm;

PROCEDURE (b: Builder) [ABSTRACT] ForStatm* (for, ident, becomes, startValue, to, endValue, by, step, do: Node; statmSeq: NodeList; end: Node): Node;
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
  END ForStatm;

PROCEDURE (b: Builder) [ABSTRACT] LoopStatm* (loop: Node; statmSeq: NodeList; end: Node): Node;
(**The generic loop.

   @table @oparam
   @item loop
   The keyword @samp{LOOP}.
   
   @item statmSeq
   The statement sequence of the loop.
   
   @item end
   The keyword @samp{END}.
   @end table  *)
  END LoopStatm;

PROCEDURE (b: Builder) [ABSTRACT] WithStatm* (guardList: NodeList; else: Node; elseStatmSeq: NodeList; end: Node): Node;
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
  END WithStatm;

PROCEDURE (b: Builder) [ABSTRACT] ExitStatm* (exit: Node): Node;
(**@code{EXIT} statement.

   @table @oparam
   @item exit
   The keyword @samp{EXIT}.
   @end table  *)
  END ExitStatm;

PROCEDURE (b: Builder) [ABSTRACT] ReturnStatm* (return, expr: Node): Node;
(**@code{RETURN} statement.

   @table @oparam
   @item return
   The keyword @samp{RETURN}.
   
   @item expr
   An expression.  This argument is @code{NIL}, if the return statement
   does not include a function result.
   @end table  *)
  END ReturnStatm;

PROCEDURE (b: Builder) [ABSTRACT] TryStatm* (try: Node; statmSeq: NodeList;
                                             catchList: NodeList; end: Node): Node;
(**Exception handler statement.

   @table @oparam
   @item try
   The keyword @samp{TRY}, result of @oproc{Builder.Terminal}.
   
   @item statmSeq
   The statement sequence of the @samp{TRY}'s body.
   
   @item catchList
   This is the list of all catch blocks.  It is a sequence of keywords,
   type names, and statement sequences.
   
   @table @samp
   @item catchList MOD 4 == 0
   The keyword @samp{CATCH}.
   
   @item catchList MOD 4 == 1
   A type name, matching the rule of @samp{Qualident}.
   
   @item catchList MOD 4 == 2
   The terminal symbol @samp{:}.
   
   @item catchList MOD 4 == 3
   The statement sequence of the catch block.
   @end table

   @item end
   The keyword @samp{END}, result of @oproc{Builder.Terminal}
   @end table  *)
  END TryStatm;


PROCEDURE (b: Builder) [ABSTRACT] Flags* (context: SHORTINT; lBrak: Node;
                                        flagList: NodeList; rBrak: Node): Node;
  END Flags;

PROCEDURE (b: Builder) [ABSTRACT] ProcWithoutBody* (moduleFlags, procFlags: Node): BOOLEAN;
(**This predicate determines, if a procedure declaration without a forward
   flag has a procedure body.  For declarations in a normal body, it returns
   always @code{FALSE}.  For a procedure declaration in an @samp{INTERFACE} or
   @samp{FOREIGN} module, the result depends on the presence of the
   @samp{HAS_BODY} flag.  *)
  END ProcWithoutBody;



PROCEDURE (b: Builder) [ABSTRACT] ProcIdFlag* (procId, equal, number: Node): Node;
  END ProcIdFlag;

PROCEDURE (b: Builder) [ABSTRACT] ModuleFlags* (
                   external, callConv: Node; moduleFlags: NodeList;
                   semicolon, link:Node;
                   linkSections: NodeList; end: Node): Node;
  END ModuleFlags;

PROCEDURE (b: Builder) [ABSTRACT] LinkFileFlag* (file, fileName, addOption, prefixOpt, comma, suffixOpt: Node): Node;
  END LinkFileFlag;

PROCEDURE (b: Builder) [ABSTRACT] LinkObjFlag* (obj, fileName: Node): Node;
  END LinkObjFlag;

PROCEDURE (b: Builder) [ABSTRACT] LinkLibFlag* (lib, libName, lParen: Node;
                  dependences: NodeList;
                  rParen, addOption, prefixOpt, comma, suffixOpt: Node): Node;
  END LinkLibFlag;

END OOC:AST.
