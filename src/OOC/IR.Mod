MODULE OOC:IR [OOC_EXTENSIONS];

IMPORT
  OOC:AST;


TYPE
  Name* = AST.Name;

TYPE
  Node* = POINTER TO NodeDesc;
  NodeDesc = RECORD [ABSTRACT]
  END;

TYPE
  Module* = POINTER TO ModuleDesc;
  ModuleDesc = RECORD
    (NodeDesc)
    name-: Name;
  END;




TYPE
  Builder* = POINTER TO BuilderDesc;
  BuilderDesc = RECORD
  END;

TYPE
  Visitor* = POINTER TO VisitorDesc;
  VisitorDesc* = RECORD [ABSTRACT]
  (**Base class for visitor pattern.  Specializations of various @code{Visit*}
     methods are responsible for traversing the tree of the module
     representation.  *)
  END;



PROCEDURE InitVisitor* (v: Visitor);
  BEGIN
  END InitVisitor;

PROCEDURE InitBuilder* (b: Builder);
  BEGIN
  END InitBuilder;

PROCEDURE NewBuilder*(): Builder;
  VAR
    b: Builder;
  BEGIN
    NEW (b);
    InitBuilder (b);
    RETURN b
  END NewBuilder;



PROCEDURE InitNode* (n: Node);
  BEGIN
  END InitNode;

PROCEDURE (node: Node) [ABSTRACT] Accept* (v: Visitor);
  END Accept;



PROCEDURE InitModule* (m: Module; name: Name);
  BEGIN
    InitNode (m);
    m. name := name;
  END InitModule;

PROCEDURE (b: Builder) NewModule* (name: Name): Module;
  VAR
    m: Module;
  BEGIN
    NEW (m);
    InitModule (m, name);
    RETURN m
  END NewModule;

PROCEDURE (v: Visitor) [ABSTRACT] VisitModule* (module: Module);
  END VisitModule;

PROCEDURE (m: Module) Accept* (v: Visitor);
  BEGIN
    v. VisitModule (m)
  END Accept;



END OOC:IR.
