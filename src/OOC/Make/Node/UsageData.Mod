MODULE OOC:Make:Node:UsageData;

IMPORT
  Msg, Time, ADT:Object, ADT:Object:Dictionary, ADT:Object:ArrayList,
  OOC:Make, OOC:Make:Node:ModuleOutput, OOC:Make:Edge:StaticDep,
  Rep := OOC:Repository, OOC:SymbolTable:Item, OOC:Auxiliary:GetSymbolTable;



TYPE
  Node* = POINTER TO NodeDesc;
  NodeDesc = RECORD
    (Make.NodeDesc)
    extensionDict-: Dictionary.Dictionary;
  END;

TYPE
  BuildCmd* = POINTER TO BuildCmdDesc;
  BuildCmdDesc = RECORD
    (Make.BuildCmdDesc)
  END;


PROCEDURE New(): BuildCmd;
  VAR
    cmd: BuildCmd;
  BEGIN
    NEW (cmd);
    RETURN cmd
  END New;

PROCEDURE (cmd: BuildCmd) Build* (n: Make.Node): Make.BuildResult;
  VAR
    edge: Make.Edge;
    module: Item.Module;
    ptr, base: Item.Item;
    extensionDict: Dictionary.Dictionary;
    list: ArrayList.ArrayList;
    obj: Object.Object;
    res: Msg.Msg;
  BEGIN
    extensionDict := Dictionary.New();
    
    edge := n. ancestorList;
    WHILE (edge # NIL) DO
      module := GetSymbolTable.GetSymbolTable (
                    edge. ancestor(ModuleOutput.Node). module,
                    n. dg. config, res);
      ptr := module. nestedItems;
      WHILE (ptr # NIL) DO
        IF (ptr IS Item.Record) & (ptr(Item.Record). baseType # NIL) THEN
          base := ptr(Item.Record). baseType;
          IF extensionDict. HasKey (base) THEN
            obj := extensionDict. Get (base);
            list := obj(ArrayList.ArrayList)
          ELSE
            list := ArrayList.New (4);
            extensionDict. Set (base, list)
          END;
          list. Append (ptr)
        END;
        ptr := ptr. nextNested
      END;
      
      edge := edge. nextAncestor
    END;
    
    n(Node). extensionDict := extensionDict;
    RETURN Make.NewBuildResult (TRUE, FALSE, NIL)
  END Build;

(* ------------------------------------------------------------------------ *)

PROCEDURE InitNode (n: Node);
  BEGIN
    Make.InitNode (n, FALSE);
    n. extensionDict := NIL;
  END InitNode;

PROCEDURE NewNode*(): Node;
  VAR
    n: Node;
  BEGIN
    NEW (n);
    InitNode (n);
    RETURN n
  END NewNode;


PROCEDURE (n: Node) GetBuildCommand*(): Make.BuildCmd;
  BEGIN
    RETURN New()
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
(**Adds the symbol files of all @otype{ModuleOutput.Node} instances in the
   dependency graph as ancestors to @oparam{n}.  That is, for every instance of
   @otype{ModuleOutput.Node} in the graph, the corresponding symbol file node
   is located and added as an ancestor to @oparam{n}.  Please note that modules
   that are @emph{not} part of the graph at the time that this procedure is
   called are also @emph{not} added to the ancestor list.  *)
  VAR
    ptr: Make.Node;
    symFile: ModuleOutput.Node;
  BEGIN
    ptr := n. dg. nodeList;
    WHILE (ptr # NIL) DO
      IF (ptr IS ModuleOutput.Node) THEN
        symFile := ModuleOutput.GetNode (n. dg, ptr(ModuleOutput.Node). module,
                                         Rep.modSymbolFile);
        IF ~symFile. IsAncestor (n) THEN
          n. dg. AddDependency (StaticDep.New (n, symFile, TRUE))
        END
      END;
      ptr := ptr. nextNode
    END
  END AddDependencies;

PROCEDURE (n: Node) GetId* (VAR id: ARRAY OF CHAR);
  BEGIN
    COPY ("anonymous instance of OOC:Make:Node:UsageData.Node", id)
  END GetId;

END OOC:Make:Node:UsageData.
