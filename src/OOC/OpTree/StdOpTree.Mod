MODULE OOC:OpTree:StdOpTree;

IMPORT
  OOC:Scanner:Symbol, OOC:Scanner:Builder:BasicList,
  Op := OOC:OpTree:Operator, OOC:OpTree;

TYPE
  Builder* = POINTER TO BuilderDesc;
  BuilderDesc* = RECORD
    (OpTree.BuilderDesc)
  END;




TYPE
  StdNode* = POINTER TO StdNodeDesc;
  StdNodeDesc = RECORD
    (OpTree.NodeDesc)
  END;

TYPE
  Const* = POINTER TO ConstDesc;
  ConstDesc = RECORD
    (StdNodeDesc)
    sym: BasicList.Symbol;
  END;

TYPE
  Name* = POINTER TO NameDesc;
  NameDesc = RECORD
    (StdNodeDesc)
    sym: BasicList.Symbol;
    opId: Op.Id;
  END;

TYPE
  Operator* = POINTER TO OperatorDesc;
  OperatorDesc = RECORD
    (StdNodeDesc)
    op: Name;
    left, right: StdNode;
  END;

TYPE
  SetRange* = POINTER TO SetDesc;
  SetDesc = RECORD
    (StdNodeDesc)
    type: StdNode;
    lower, upper: StdNode;
  END;

TYPE
  FunctionCall* = POINTER TO FunctionCallDesc;
  FunctionCallDesc = RECORD
    (StdNodeDesc)
    fct: StdNode;
    arguments: OpTree.NodeList;
  END;



TYPE
  ProcedureCall* = POINTER TO ProcedureCallDesc;
  ProcedureCallDesc = RECORD
    (OpTree.NodeDesc)
    call: OpTree.Node;                (* see @oproc{AST.Builder.ProcedureCall} *)
  END;

TYPE
  Assignment* = POINTER TO AssignmentDesc;
  AssignmentDesc = RECORD
    (OpTree.NodeDesc)
    assignment: OpTree.Node;
  END;

TYPE
  IfStatm* = POINTER TO IfStatmDesc;
  IfStatmDesc = RECORD
    (OpTree.NodeDesc)
    guard: OpTree.Node;
    trueStatm: OpTree.NodeList;
    falseStatm: OpTree.NodeList;
  END;

TYPE
  CaseStatm* = POINTER TO CaseStatmDesc;
  CaseStatmDesc = RECORD
    (OpTree.NodeDesc)
    expr: OpTree.Node;
    labels: OpTree.NodeList;
    branches: OpTree.NodeList;
    else: OpTree.NodeList;
  END;

TYPE
  WhileStatm* = POINTER TO WhileStatmDesc;
  WhileStatmDesc = RECORD
    (OpTree.NodeDesc)
    guard: OpTree.Node;
    statmSeq: OpTree.NodeList;
  END;

TYPE
  RepeatStatm* = POINTER TO RepeatStatmDesc;
  RepeatStatmDesc = RECORD
    (OpTree.NodeDesc)
    statmSeq: OpTree.NodeList;
    until: OpTree.Node;
  END;

TYPE
  ForStatm* = POINTER TO ForStatmDesc;
  ForStatmDesc = RECORD
    (OpTree.NodeDesc)
    var: OpTree.Node;
    start: OpTree.Node;
    end: OpTree.Node;
    step: OpTree.Node;
    statmSeq: OpTree.NodeList;
  END;

TYPE
  LoopStatm* = POINTER TO LoopStatmDesc;
  LoopStatmDesc = RECORD
    (OpTree.NodeDesc)
    statmSeq: OpTree.NodeList;
  END;

TYPE
  WithStatm* = POINTER TO WithStatmDesc;
  WithStatmDesc = RECORD
    (OpTree.NodeDesc)
    guard: OpTree.Node;
    trueStatm: OpTree.NodeList;
    falseStatm: OpTree.NodeList;
  END;

TYPE
  ExitStatm* = POINTER TO ExitStatmDesc;
  ExitStatmDesc = RECORD
    (OpTree.NodeDesc)
  END;

TYPE
  ReturnStatm* = POINTER TO ReturnStatmDesc;
  ReturnStatmDesc = RECORD
    (OpTree.NodeDesc)
    expr: OpTree.Node;
  END;



PROCEDURE (b: Builder) Const* (sym: BasicList.Symbol): OpTree.Node;
  VAR
    c: Const;
  BEGIN
    NEW (c);
    c. sym := sym;
    RETURN c
  END Const;

PROCEDURE (b: Builder) Name* (sym: BasicList.Symbol): OpTree.Node;
  VAR
    n: Name;
  BEGIN
    NEW (n);
    n. sym := sym;
    IF (sym. id = Symbol.ident) THEN
      n. opId := Op.illegal
    ELSE
      n. opId := Op.SymbolToOperator (sym. id)
    END;
    RETURN n
  END Name;

PROCEDURE (b: Builder) Operator* (op, left, right: OpTree.Node): OpTree.Node;
  VAR
    o: Operator;
  BEGIN
    NEW (o);
    o. op := op(Name);
    IF (left # NIL) THEN
      o. left := left(StdNode)
    ELSE
      o. left := NIL
    END;
    IF (right # NIL) THEN
      o. right := right(StdNode)
    ELSE
      o. right := NIL
    END;
    RETURN o
  END Operator;

PROCEDURE (b: Builder) UnionOperator* (): OpTree.Node;
  VAR
    union: Name;
  BEGIN
    NEW (union);
    union. sym := NIL;
    union. opId := Op.add;
    RETURN union
  END UnionOperator;

PROCEDURE (b: Builder) IndexOperator* (): OpTree.Node;
  VAR
    index: Name;
  BEGIN
    NEW (index);
    index. sym := NIL;
    index. opId := Op.index;
    RETURN index
  END IndexOperator;

PROCEDURE (b: Builder) SetRange* (type, lower, upper: OpTree.Node): OpTree.Node;
  VAR
    sr: SetRange;
  BEGIN
    NEW (sr);
    IF (type # NIL) THEN
      sr. type := type(StdNode)
    ELSE
      sr. type := NIL
    END;
    IF (lower # NIL) THEN
      sr. lower := lower(StdNode)
    ELSE
      sr. lower := NIL
    END;
    IF (upper # NIL) THEN
      sr. upper := upper(StdNode)
    ELSE
      sr. upper := NIL
    END;
    RETURN sr
  END SetRange;

PROCEDURE (b: Builder) FunctionCall* (fct: OpTree.Node;
                                      arguments: OpTree.NodeList): OpTree.Node;
  VAR
    fc: FunctionCall;
  BEGIN
    NEW (fc);
    fc. fct := fct(StdNode);
    fc. arguments := arguments;
    RETURN fc
  END FunctionCall;



PROCEDURE (b: Builder) Assignment* (assignment: OpTree.Node): OpTree.Node;
  VAR
    a: Assignment;
  BEGIN
    NEW (a);
    a. assignment := assignment;
    RETURN a
  END Assignment;     

PROCEDURE (b: Builder) ProcedureCall* (call: OpTree.Node): OpTree.Node;
  VAR
    pc: ProcedureCall;
  BEGIN
    NEW (pc);
    pc. call := call;
    RETURN pc
  END ProcedureCall;  
                      
PROCEDURE (b: Builder) IfStatm* (guard: OpTree.Node; trueStatm, falseStatm: OpTree.NodeList): OpTree.Node;
  VAR
    is: IfStatm;
  BEGIN
    NEW (is);
    is. guard := guard;
    is. trueStatm := trueStatm;
    is. falseStatm := falseStatm;
    RETURN is
  END IfStatm;        
                      
PROCEDURE (b: Builder) CaseStatm* (expr: OpTree.Node; labels: OpTree.NodeList; branches: OpTree.NodeList; else: OpTree.NodeList): OpTree.Node;
  VAR
    cs: CaseStatm;
  BEGIN
    NEW (cs);
    cs. expr := expr;
    cs. labels := labels;
    cs. branches := branches;
    cs. else := else;
    RETURN cs
  END CaseStatm;      
                      
PROCEDURE (b: Builder) WhileStatm* (guard: OpTree.Node; statmSeq: OpTree.NodeList): OpTree.Node;
  VAR
    ws: WhileStatm;
  BEGIN
    NEW (ws);
    ws. guard := guard;
    ws. statmSeq := statmSeq;
    RETURN ws
  END WhileStatm;     
                      
PROCEDURE (b: Builder) RepeatStatm* (statmSeq: OpTree.NodeList; until: OpTree.Node): OpTree.Node;
  VAR
    rs: RepeatStatm;
  BEGIN
    NEW (rs);
    rs. statmSeq := statmSeq;
    rs. until := until;
    RETURN rs
  END RepeatStatm;    
                      
PROCEDURE (b: Builder) ForStatm* (var, start, end, step: OpTree.Node; statmSeq: OpTree.NodeList): OpTree.Node;
  VAR
    fs: ForStatm;
  BEGIN
    NEW (fs);
    fs. var := var;
    fs. start := start;
    fs. end := end;
    fs. step := step;
    fs. statmSeq := statmSeq;
    RETURN fs
  END ForStatm;       
                      
PROCEDURE (b: Builder) LoopStatm* (statmSeq: OpTree.NodeList): OpTree.Node;
  VAR
    ls: LoopStatm;
  BEGIN
    NEW (ls);
    ls. statmSeq := statmSeq;
    RETURN ls
  END LoopStatm;      
                      
PROCEDURE (b: Builder) WithStatm* (guard: OpTree.Node; trueStatm, falseStatm: OpTree.NodeList): OpTree.Node;
  VAR
    ws: WithStatm;
  BEGIN
    NEW (ws);
    ws. guard := guard;
    ws. trueStatm := trueStatm;
    ws. falseStatm := falseStatm;
    RETURN ws
  END WithStatm;      
                      
PROCEDURE (b: Builder) ExitStatm* (): OpTree.Node;
  VAR
    es: ExitStatm;
  BEGIN
    NEW (es);
    RETURN es
  END ExitStatm;      
                      
PROCEDURE (b: Builder) ReturnStatm* (expr: OpTree.Node): OpTree.Node;
  VAR
    rs: ReturnStatm;
  BEGIN
    NEW (rs);
    rs. expr := expr;
    RETURN rs
  END ReturnStatm;

END OOC:OpTree:StdOpTree.
