MODULE OOC:Make [OOC_EXTENSIONS];
(**This module is based on the ideas presented in

@example
Proposal for PyMake
A Highly Extensible Next Generation Make System
Rich Miller <Rich_Miller@@idx.com>
March 31, 2000
@url{http://software-carpentry.codesourcery.com/entries/build/PyMake/PyMake.html}
@end example

Please note that this module does @emph{not} try to provide a general
purpose make utility.  It provides a framework for the services needed
by the OOC compiler, and does not try to meet demands beyond this goal.

Concurrent builds, that is, one or more builds started concurrently on
the same code base, are not supported.  The behaviour in such a case is
undefined.  In particular, it is not guaranteed that even one of the
concurrent builds finishes correctly.

The job dispatcher is a class of its own, with a very simple interface.
Actual implementations of the dispatcher may use subprocesses, threads,
or even remote hosts to get the job done.  The most simple implementation,
of course, is a synchronous dispatcher running as part of the current
process.

*)
<*DEFINE OOC_Make_DEBUG := FALSE*>

IMPORT
  <*IF OOC_Make_DEBUG THEN*>Out, <*END*>
  StdChannels, Strings, Time, OOC:Error, OOC:Repository, OOC:Auxiliary:Config;


CONST
  nodeUneval = 0;
  (**Status of node is not known.  *)
  nodeEval = 1;
  (**Evaluation of the node is underway.  *)
  nodeOK = 2;
  (**Node was already up to date.  *)
  nodeDone = 3;
  (**Node was successfully built.  *)
  nodeBad = 4;
  (**Node was not built, because an ancestor failed or was absent.  *)
  nodeFailed = 5;
  (**Node built was attempted, but failed.  *)

TYPE
  DepGraph* = POINTER TO DepGraphDesc;
  JobDispatcher* = POINTER TO JobDispatcherDesc;
  BuildCmd* = POINTER TO BuildCmdDesc;
  Node* = POINTER TO NodeDesc;

TYPE
  NameMapping = POINTER TO NameMappingDesc;
  NameMappingDesc = RECORD
    next: NameMapping;
    name: POINTER TO ARRAY OF CHAR;
    node: Node;
  END;

TYPE
  DepGraphDesc = RECORD
    nodeList-, nodeListTail: Node;
    (**This list contains all nodes that are part of the dependency graph.
       They are linked using @ofield{Node.nextNode}.  *)
    jd: JobDispatcher;
    (* Any build commands are handed over to this dispatcher.  In theory,
       the dispatcher could run in a different thread or process.  In practice,
       the current implementation works synchronously with just one active job
       at a time.  *)
    buildCmds-: ARRAY Repository.maxFileId+1 OF BuildCmd;
    config-: Config.Config;
    nameList: NameMapping;
  END;


TYPE
  Edge* = POINTER TO EdgeDesc;
  EdgeDesc* = RECORD [ABSTRACT]
    (**An instance of @otype{Edge} represents a directed connection of two
       nodes of the dependency graph.  The edges begins at the descendent 
       node, and ends with the ancestor node.  The edges are directed in
       the mathematical senses, and they can be traversed
       in both directions.  It is possible to enumerate all edges from a
       decendant to an ancestor, and vice versa.  *)
    descendent-: Node;
    (**The (virtual) starting node of the edge.  It designates the descendent
       of the ancestor/descendent relationship represented by the edge.  *)
    ancestor-: Node;
    (**The (virtual) ending node of the edge.  It designates the ancestor
       of the ancestor/descendent relationship represented by the edge.  *)
    nextDescendent-: Edge;
    (**The next edge in the list of edges anchored in
       @samp{Edge.ancestor.descendentList}.  *)
    nextAncestor-: Edge;
    (**The next edge in the list of edges anchored in
       @samp{Edge.descendent.ancestorList}.  *)
  END;

TYPE
  NodeDesc* = RECORD [ABSTRACT]
    (**A node in the dependency graph represents a component, typically
       a file.  *)
    nextNode-: Node;
    (**Refers to next node in the list @ofield{DepGraph.nodeList}.  *)
    dg-: DepGraph;
    (**The dependency graph, of which this instance of @otype{Node} is
       part of.  *)
    descendentList-: Edge;
    (**List of edges enumerating the descendents of a node.  The edges are
       linked with @ofield{Edge.nextDescendent}.  *)
    ancestorList-: Edge; 
    (**List of edges enumerating the ancestors of a node.  The edges are
       linked with @ofield{Edge.nextAncestor}.  *)
    status: SHORTINT;
    (* The status of the node.  One of @oconst{nodeUneval}, @oconst{nodeEval},
       @oconst{nodeOK}, @oconst{nodeDone}, @oconst{nodeBad}, or 
       @oconst{nodeFailed}.  *)
    blockCount: LONGINT;
    (* The number of ancestors that are not up to date.  *)
    static: BOOLEAN;
    (* A static node is not changed by builds.  This is used to mark source
       files.  *)
    effectiveTimeStamp-: Time.TimeStamp;
    (* After a node has been evaluated, this field holds the maximum of the
       time stamp of the node and the effective time stamps of its ancestors.
       *)
  END;

TYPE
  FileNode* = POINTER TO FileNodeDesc;
  FileNodeDesc = RECORD [ABSTRACT]
    (**A node of type @otype{FileNode} represents a file that is stored in
       a known repository.  *)
    (NodeDesc)
  END;

TYPE
  BuildCmdDesc* = RECORD [ABSTRACT]
  END;

TYPE
  BuildResult* = POINTER TO BuildResultDesc;
  BuildResultDesc = RECORD
    success-: BOOLEAN;
    noAction-: BOOLEAN;
    errList-: Error.List;
  END;

TYPE
  JobDispatcherDesc* = RECORD [ABSTRACT]
  END;



PROCEDURE (n: Node) [ABSTRACT] GetId* (VAR id: ARRAY OF CHAR);
  END GetId;

PROCEDURE AddingNode (n: Node);
<*IF OOC_Make_DEBUG THEN*>
  VAR
    id: ARRAY 1024 OF CHAR;
  BEGIN
    n. GetId (id);
    Out.String ("make: adding node (");
    Out.String (id);
    Out.String (")");
    Out.Ln
<*END*>
  END AddingNode;

PROCEDURE AddingJob (n: Node);
<*IF OOC_Make_DEBUG THEN*>
  VAR
    id: ARRAY 1024 OF CHAR;
  BEGIN
    n. GetId (id);
    Out.String ("make: BUILDING node (");
    Out.String (id);
    Out.String (")");
    Out.Ln
<*END*>
  END AddingJob;

PROCEDURE JobDone (n: Node);
<*IF OOC_Make_DEBUG THEN*>
  VAR
    id: ARRAY 1024 OF CHAR;
  BEGIN
    n. GetId (id);
    Out.String ("make: DONE building node (");
    Out.String (id);
    Out.String (")");
    Out.Ln
<*END*>
  END JobDone;

PROCEDURE StartEvaluating (n: Node);
<*IF OOC_Make_DEBUG THEN*>
  VAR
    id: ARRAY 1024 OF CHAR;
  BEGIN
    n. GetId (id);
    Out.String ("make: START node (");
    Out.String (id);
    Out.String (")");
    Out.Ln
<*END*>
  END StartEvaluating;

PROCEDURE StopEvaluating (n: Node);
<*IF OOC_Make_DEBUG THEN*>
  VAR
    id: ARRAY 1024 OF CHAR;
  BEGIN
    n. GetId (id);
    Out.String ("make: STOP node (");
    Out.String (id);
    Out.String (")");
    Out.Ln
<*END*>
  END StopEvaluating;

PROCEDURE DoesNotExist (n: Node);
<*IF OOC_Make_DEBUG THEN*>
  VAR
    id: ARRAY 1024 OF CHAR;
  BEGIN
    n. GetId (id);
    Out.String ("make:   # (");
    Out.String (id);
    Out.String (") does not exist");
    Out.Ln
<*END*>
  END DoesNotExist;

PROCEDURE Invalidated (e: Edge);
<*IF OOC_Make_DEBUG THEN*>
  VAR
    id: ARRAY 1024 OF CHAR;
  BEGIN
    Out.String ("make:   # dependency (");
    e. descendent. GetId (id);
    Out.String (id);
    Out.String (") --> (");
    e. ancestor. GetId (id);
    Out.String (id);
    Out.String (") is not valid");
    Out.Ln
<*END*>
  END Invalidated;

PROCEDURE Evaluated (n: Node);
<*IF OOC_Make_DEBUG THEN*>
  VAR
    id: ARRAY 1024 OF CHAR;
  BEGIN
    Out.String ("make: status of (");
    n. GetId (id);
    Out.String (id);
    Out.String (") is '");
    CASE n. status OF
    | nodeUneval: Out.String ("uneval")
    | nodeEval: Out.String ("eval")
    | nodeOK: Out.String ("ok")
    | nodeDone: Out.String ("done")
    | nodeBad: Out.String ("bad")
    | nodeFailed: Out.String ("failed")
    END;
    Out.String ("'");
    Out.Ln
<*END*>
  END Evaluated;

PROCEDURE AddingDep (edge: Edge);
<*IF OOC_Make_DEBUG THEN*>
  VAR
    id: ARRAY 1024 OF CHAR;
  BEGIN
    Out.String ("make: adding dependency (");
    edge. descendent. GetId (id);
    Out.String (id);
    Out.String (") --> (");
    edge. ancestor. GetId (id);
    Out.String (id);
    Out.String (")");
    Out.Ln
<*END*>
  END AddingDep;


(* Build Result
   ------------------------------------------------------------------------ *)

PROCEDURE InitBuildResult (buildRes: BuildResult; success, noAction: BOOLEAN;
                           errList: Error.List);
  BEGIN
    buildRes. success := success;
    buildRes. noAction := noAction;
    buildRes. errList := errList;
  END InitBuildResult;

PROCEDURE NewBuildResult* (success, noAction: BOOLEAN; errList: Error.List): BuildResult;
  VAR
    buildRes: BuildResult;
  BEGIN
    NEW (buildRes);
    InitBuildResult (buildRes, success, noAction, errList);
    RETURN buildRes
  END NewBuildResult;


(* Build Command
   ------------------------------------------------------------------------ *)

PROCEDURE (cmd: BuildCmd) [ABSTRACT] Build* (n: Node): BuildResult;
(**Tries to build component @oparam{n}.  The results of this attempt are
   reported back as an object of type @otype{BuildResult}.  *)
  END Build;


(* Job Dispatcher
   ------------------------------------------------------------------------ *)

PROCEDURE InitJobDispatcher* (jd: JobDispatcher);
  BEGIN
  END InitJobDispatcher;

PROCEDURE (jd: JobDispatcher) [ABSTRACT] AddJob* (n: Node; cmd: BuildCmd);
(**Adds a new entry to the set of ready jobs of the dispatcher @oparam{jd}.  *)
  END AddJob;

PROCEDURE (jd: JobDispatcher) Reset*;
  BEGIN
  END Reset;


(* Dependency Edges
   ------------------------------------------------------------------------ *)

PROCEDURE InitEdge* (edge: Edge; descendent, ancestor: Node);
  BEGIN
    edge. descendent := descendent;
    edge. ancestor := ancestor;
    edge. nextDescendent := NIL;
    edge. nextAncestor := NIL;
  END InitEdge;

PROCEDURE (edge: Edge) [ABSTRACT] Invalidated*(): BOOLEAN;
(**Returns @code{TRUE}, if changes to the ancestor component
   @samp{edge.ancestor} invalidate the descendent component
   @samp{edge.descendent}.  In this case, the descendent must be rebuilt, using
   an up to date copy of the ancestor.  The function should return @code{TRUE}
   if either component does not exist.  *)
  END Invalidated;


(* Nodes
   ------------------------------------------------------------------------ *)

PROCEDURE InitNode* (n: Node; static: BOOLEAN);
  BEGIN
    n. nextNode := NIL;
    n. dg := NIL;
    n. descendentList := NIL;
    n. ancestorList := NIL;
    n. status := nodeUneval;
    n. blockCount := 0;
    n. static := static;
    Time.InitTimeStamp (n. effectiveTimeStamp, 0, 0)
  END InitNode;

PROCEDURE (n: Node) [ABSTRACT] GetBuildCommand*(): BuildCmd;
(**Creates a command that can be used to create the component designated
   by the node @oparam{n}.  *)
  END GetBuildCommand;

PROCEDURE (n: Node) [ABSTRACT] Exists* (): BOOLEAN;
(**Returns @code{TRUE} iff the component indicated through @oparam{n} 
   exists.  Otherwise, the component must be rebuild.  *)
  END Exists;

PROCEDURE (n: Node) [ABSTRACT] GetTimeStamp* (VAR ts: Time.TimeStamp);
(**Returns the modification time of the component represented by the
   node @oparam{n}.  Note that this value differs from the @emph{effective
   timestamp}, which is computed from the node and all its ancestors.  *)
  END GetTimeStamp;

PROCEDURE (n: Node) [ABSTRACT] AddDependencies*;
(**Adds all ancestors of @oparam{n} to the dependency graph.  This method
   determines all components the node @oparam{n} depends on, and adds them as
   direct ancestors of @oparam{n} to the graph.  It is called during evaluation
   of the node (see @oproc{DepGraph.Evaluate}).  *)
  END AddDependencies;

PROCEDURE (n: Node) IsAncestor* (descendent: Node): BOOLEAN;
(**Returns @code{TRUE} iff @oparam{n} is a direct ancestor of
   @oparam{descendent}.  *)
  VAR
    edge: Edge;
  BEGIN
    edge := n. descendentList;
    WHILE (edge # NIL) & (edge. descendent # descendent) DO
      edge := edge. nextDescendent
    END;
    RETURN (edge # NIL)
  END IsAncestor;


PROCEDURE ^ EvaluateNode (n: Node);

PROCEDURE UnblockDescendents (n: Node);
  VAR
    dEdge: Edge;
  BEGIN    
    dEdge := n. descendentList;
    WHILE (dEdge # NIL) DO
      DEC (dEdge. descendent. blockCount);
      IF (dEdge. descendent. blockCount = 0) &
         (dEdge. descendent. status = nodeUneval) THEN
        EvaluateNode (dEdge. descendent)
      END;
      dEdge := dEdge. nextDescendent
    END
  END UnblockDescendents;

PROCEDURE SetEvalStatus (n: Node; status: SHORTINT);
  VAR
    aEdge: Edge;
  BEGIN
    n. status := status;
    Evaluated (n);
    
    n. GetTimeStamp (n. effectiveTimeStamp);
    aEdge := n. ancestorList;
    WHILE (aEdge # NIL) DO
      IF (aEdge. ancestor. effectiveTimeStamp. Cmp (n. effectiveTimeStamp) > 0) THEN
        n. effectiveTimeStamp := aEdge. ancestor. effectiveTimeStamp
      END;
      aEdge := aEdge. nextAncestor
    END;
    
    UnblockDescendents (n)
  END SetEvalStatus;

PROCEDURE EvaluateNode (n: Node);
  PROCEDURE EvaluateAncestors (n: Node);
    VAR
      aEdge: Edge;
    BEGIN
      aEdge := n. ancestorList;
      WHILE (aEdge # NIL) DO
        IF (aEdge. ancestor. status = nodeUneval) THEN
          EvaluateNode (aEdge. ancestor)
        END;
        aEdge := aEdge. nextAncestor
      END
    END EvaluateAncestors;
  
  PROCEDURE IsBad (n: Node): BOOLEAN;
    VAR
      aEdge: Edge;
    BEGIN
      aEdge := n. ancestorList;
      WHILE (aEdge # NIL) DO
        IF (aEdge. ancestor. status = nodeBad) OR
           (aEdge. ancestor. status = nodeFailed) THEN
          RETURN TRUE
        END;
        aEdge := aEdge. nextAncestor
      END;
      RETURN FALSE
    END IsBad;
  
  PROCEDURE IsDone (n: Node): BOOLEAN;
  (* A node is done if its component exists, and if none of its ancestors has
     changed.  Nodes that have no ancestors, or that are marked "static" are
     always "done", unless they have been flagged "bad" already.  *)
    VAR
      aEdge: Edge;
    BEGIN
      IF n. Exists() THEN
        aEdge := n. ancestorList;
        WHILE (aEdge # NIL) DO
          ASSERT (aEdge. ancestor. status # nodeUneval);
          ASSERT (aEdge. ancestor. status # nodeEval);
          IF aEdge. Invalidated() THEN
            (* the relationship indicated by the edge has been invalidated,
               e.g., because the ancestor file's content has changed *)
            Invalidated (aEdge);
            RETURN FALSE
          END;
          aEdge := aEdge. nextAncestor
        END;
        RETURN TRUE
      ELSE                               (* component does not exist *)
        DoesNotExist (n);
        RETURN FALSE
      END
    END IsDone;
  
  BEGIN  (* pre: (n. status = nodeUneval) *)
    StartEvaluating (n);
    ASSERT (n. status = nodeUneval);
    
    n. status := nodeEval;
    n. AddDependencies;
    EvaluateAncestors (n);
    IF IsBad (n) THEN
      (* ancestor failed to build; this means we can unblock all descendents
         immediately, which in turn evaluates them to "bad" *)
      SetEvalStatus (n, nodeBad)
    ELSIF IsDone (n) OR n. static THEN
      (* the node is up to date; no need to build it *)
      SetEvalStatus (n, nodeOK)
    ELSE
      (* add job to build node "n" to the job dispatcher's list; once the
         job is done (or failed to be done), the job dispatcher calls
         @oproc{Node.BuildFinished} *)
      AddingJob (n);
      n. dg. jd. AddJob (n, n. GetBuildCommand())
    END;
    StopEvaluating (n)
  END EvaluateNode;

PROCEDURE (n: Node) BuildFinished* (res: BuildResult);
(**Signals that the build of node @oparam{n} is done.  The results of the
   attempt are reported in @oparam{res}.  *)
  BEGIN
    JobDone (n);
    IF res. success THEN
      IF res. noAction THEN
        SetEvalStatus (n, nodeOK)
      ELSE
        SetEvalStatus (n, nodeDone)
      END
    ELSE
      res. errList. Write (StdChannels.stderr);
      SetEvalStatus (n, nodeFailed)
    END
  END BuildFinished;


(* Dependency Graph
   ------------------------------------------------------------------------ *)

PROCEDURE InitDepGraph* (dg: DepGraph; config: Config.Config; jd: JobDispatcher);
  VAR
    i: Repository.FileId;
  BEGIN
    dg. nodeList := NIL;
    dg. nodeListTail := NIL;
    dg. config := config;
    dg. jd := jd;
    FOR i := 0 TO Repository.maxFileId DO
      dg. buildCmds[i] := NIL
    END;
    dg. nameList := NIL
  END InitDepGraph;

PROCEDURE NewDepGraph* (config: Config.Config; jd: JobDispatcher): DepGraph;
  VAR
    dg: DepGraph;
  BEGIN
    NEW (dg);
    InitDepGraph (dg, config, jd);
    RETURN dg
  END NewDepGraph;

PROCEDURE (dg: DepGraph) SetBuildCmd* (fileId: Repository.FileId; buildCmd: BuildCmd);
  BEGIN
    dg. buildCmds[fileId] := buildCmd
  END SetBuildCmd;

PROCEDURE (dg: DepGraph) AddNode* (n: Node);
(**Adds the node @oparam{n} to the dependency graph @oparam{dg}.

   @precond
   The node @oparam{n} is not yet part of a dependency graph.
   @end precond  *)
  BEGIN
    AddingNode (n);
    
    ASSERT (n. dg = NIL);
    n. nextNode := NIL;
    n. dg := dg;
    IF (dg. nodeListTail = NIL) THEN
      dg. nodeList := n
    ELSE
      dg. nodeListTail. nextNode := n
    END;
    dg. nodeListTail := n
  END AddNode;

PROCEDURE (dg: DepGraph) AddNamedNode* (n: Node; name: ARRAY OF CHAR);
(**Adds the node @oparam{n} to the dependency graph @oparam{dg} and assigns it
   the name @oparam{name}.

   @precond
   The node @oparam{n} is not yet part of a dependency graph.
   @end precond  *)
  
  PROCEDURE AddName (VAR list: NameMapping);
    BEGIN
      IF (list = NIL) THEN
        NEW (list);
        list. next := NIL;
        NEW (list. name, Strings.Length (name)+1);
        COPY (name, list. name^);
        list. node := n
      ELSIF (list. name^ = name) THEN
        list. node := n
      ELSE
        AddName (list. next)
      END
    END AddName;
  
  BEGIN
    dg. AddNode (n);
    AddName (dg. nameList)
  END AddNamedNode;

PROCEDURE (dg: DepGraph) GetNamedNode* (name: ARRAY OF CHAR): Node;
  VAR
    nm: NameMapping;
  BEGIN
    nm := dg. nameList;
    WHILE (nm # NIL) & (nm. name^ # name) DO
      nm := nm. next
    END;
    IF (nm # NIL) THEN
      RETURN nm. node
    ELSE
      RETURN NIL
    END
  END GetNamedNode;

PROCEDURE (dg: DepGraph) AddDependency* (edge: Edge);
(**Adds the dependency relationship described by @oparam{edge} to the
   dependency graph.
   
   @precond
   Both @samp{edge.descendent} and @samp{edge.ancestor} are already part of the
   dependency graph @oparam{dg}.
   @end precond *)
  BEGIN
    AddingDep (edge);
    ASSERT (edge. descendent. dg = dg);
    ASSERT (edge. ancestor. dg = dg);
    
    edge. nextDescendent := edge. ancestor. descendentList;
    edge. nextAncestor := edge. descendent. ancestorList;
    edge. ancestor. descendentList := edge;
    edge. descendent. ancestorList := edge;
    INC (edge. descendent. blockCount)
  END AddDependency;

PROCEDURE (dg: DepGraph) Evaluate*(): BOOLEAN;
(**Evaluates all nodes of the graph.  *)
  VAR
    n: Node;
    count: LONGINT;
  BEGIN
    dg. jd. Reset;
    n := dg. nodeList;
    WHILE (n # NIL) DO
      (* note: the list `dg.nodeList' will grow while we are traversing it *)
      IF (n. status = nodeUneval) THEN
        EvaluateNode (n)
      END;
      n := n. nextNode
    END;
    
    count := 0;
    n := dg. nodeList;
    WHILE (n # NIL) DO
      IF (n. status # nodeOK) & (n. status # nodeDone) THEN
        INC (count)
      END;
      n := n. nextNode
    END;
    RETURN (count = 0)
  END Evaluate;

END OOC:Make.
