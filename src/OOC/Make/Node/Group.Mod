MODULE OOC:Make:Node:Group;

IMPORT
  Time, OOC:Make;



TYPE
  Node* = POINTER TO NodeDesc;
  NodeDesc = RECORD
    (Make.NodeDesc)
  END;


PROCEDURE InitNode (n: Node; static: BOOLEAN);
  BEGIN
    Make.InitNode (n, static)
  END InitNode;

PROCEDURE NewNode* (static: BOOLEAN): Node;
  VAR
    n: Node;
  BEGIN
    NEW (n);
    InitNode (n, static);
    RETURN n
  END NewNode;


PROCEDURE (n: Node) GetBuildCommand*(): Make.BuildCmd;
  BEGIN
    RETURN NIL
  END GetBuildCommand;

PROCEDURE (n: Node) Exists* (): BOOLEAN;
  BEGIN
    RETURN TRUE
  END Exists;

PROCEDURE (n: Node) GetTimeStamp* (VAR ts: Time.TimeStamp);
  BEGIN
    Time.InitTimeStamp (ts, 0, 0)
  END GetTimeStamp;

PROCEDURE (n: Node) AddDependencies*;
  BEGIN
  END AddDependencies;

PROCEDURE (n: Node) GetId* (VAR id: ARRAY OF CHAR);
  BEGIN
    COPY ("anonymous instance of OOC:Make:Node:Group.Node", id)
  END GetId;

END OOC:Make:Node:Group.
