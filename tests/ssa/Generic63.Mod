MODULE Generic63;

TYPE
  Node*(P: Node) = POINTER TO NodeDesc(P);
  NodeDesc(P: Node) = RECORD
    parent-: P;
  END;
  
END Generic63.
