MODULE Generic62;

TYPE
  Node* = POINTER TO NodeDesc(Node);
  NodeDesc(P: Node) = RECORD
    parent-: P;
  END;
  
END Generic62.
