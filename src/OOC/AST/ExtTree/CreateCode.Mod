MODULE OOC:AST:ExtTree:CreateCode;

IMPORT
  OOC:AST:ExtTree, OOC:SymbolTable:Item, OOC:OpTree, Out;


TYPE
  Body* = POINTER TO BodyDesc;
  BodyDesc = RECORD
    next: Body;
    statmList: OpTree.NodeList;
  END;

TYPE
  BodyList* = POINTER TO BodyListDesc;
  BodyListDesc = RECORD
    head, tail: Body;
    
  END;


PROCEDURE NewBodyList (): BodyList;
  VAR
    bl: BodyList;
  BEGIN
    NEW (bl);
    bl. head := NIL;
    bl. tail := NIL;
    RETURN bl
  END NewBodyList;

PROCEDURE NewBody (statmList: OpTree.NodeList): Body;
  VAR
    b: Body;
  BEGIN
    NEW (b);
    b. next := NIL;
    b. statmList := statmList;
    RETURN b
  END NewBody;


PROCEDURE CreateCode* (module: ExtTree.Module;
                       symbolTable: Item.Module;
                       opTreeBuilder: OpTree.Builder);
  VAR
    nodeIndex: LONGINT;
    node: ExtTree.ProcDecl;
    item: Item.ProcDecl;
    
  PROCEDURE NextProcNode(): ExtTree.ProcDecl;
    BEGIN
      IF (module. body # NIL) THEN
        INC (nodeIndex);
        WHILE (nodeIndex # module. body. declSeq. len) DO
          IF (module. body. declSeq. n[nodeIndex] IS ExtTree.ProcDecl) THEN
            RETURN module. body. declSeq. n[nodeIndex](ExtTree.ProcDecl)
          END;
          INC (nodeIndex)
        END
      END;
      RETURN NIL
    END NextProcNode;
  
  PROCEDURE FirstProcItem (): Item.ProcDecl;
    VAR
      i: Item.Item;
    BEGIN
      i := symbolTable. nestedItems;
      WHILE (i # NIL) & ~(i IS Item.ProcDecl) DO
        i := i. nextNested
      END;
      IF (i = NIL) THEN
        RETURN NIL
      ELSE
        RETURN i(Item.ProcDecl)
      END
    END FirstProcItem;
  
  PROCEDURE NextProcItem (): Item.ProcDecl;
    VAR
      i: Item.Item;
    BEGIN
      i := item;
      i := i. nextNested;
      WHILE (i # NIL) & ~(i IS Item.ProcDecl) DO
        i := i. nextNested
      END;
      IF (i = NIL) THEN
        RETURN NIL
      ELSE
        RETURN i(Item.ProcDecl)
      END
    END NextProcItem;
  
  BEGIN
    nodeIndex := -1;
    node := NextProcNode();
    item := FirstProcItem();
    WHILE (node # NIL) OR (item # NIL) DO
      Out.String (node. identDef. ident. sym. str^); Out.Ln;
      Out.String (item. name. str^); Out.Ln;
      node := NextProcNode();
      item := NextProcItem()
    END
  END CreateCode;

END OOC:AST:ExtTree:CreateCode.
