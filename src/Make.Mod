MODULE Make [OOC_EXTENSIONS];

IMPORT
  Channel, Config, Log, Strings, ADT:Object, ADT:String;

CONST
  writeLog = FALSE;

TYPE
  EntityState* = LONGINT;
  
CONST
  entityBuild* = -3;
  (**The entity is invalid and must be (re-)build by running a command.  Once
     the command has been executed, the entity is reclassified as either
     @oconst{entityValid} or @oconst{entityInvalid}.  All values
     @samp{<=@oconst{entityBuild}} are treated alike by the framework.  *)
  entityValid* = -2;
  (**The entity is valid, that is, it exists and its content is up to date.
     Once this state is reached, the entity will not change for the duration of
     the build.  *)
  entityInvalid* = -1;
  (**The entity is invalid.  Either it does not exist, or its content is known
     to be outdated.  If the entity cannot be rebuild, it stays in this state.  *)
  entityUndiscovered* = 0;
  (**The entity's state has not been determined yet.  The framework treats all
     values @samp{>=@oconst{entityUndiscovered}}.  *)

TYPE
  CommandState* = LONGINT;
  
CONST
  commandInvalid* = -4;
  (**The command cannot be scheduled for execution, because at least one of its
     ancestors is in an invalid state.  *)
  commandSchedule* = -3;
  (**The command is scheduled for execution.  *)
  commandSuccessful* = -2;
  (**The command has been succesfully executed.  *)
  commandFailed* = -1;
  (**The command has been executed, but it failed.  *)
  commandUndiscovered* = 0;
  (**The command's state has not been determined yet.  The framework treats all
     values @samp{>=@oconst{entityUndiscovered}}.  *)
  
  
TYPE
  Node* = POINTER TO NodeDesc;
  Context* = POINTER TO ContextDesc;
  Edge* = POINTER TO EdgeDesc;
  NodeDesc* = RECORD [ABSTRACT]
    (Object.ObjectDesc)
    nextNode-: Node;
    (**Linked list of all nodes in the @otype{Context}. *)
    context-: Context;
    (**The node's context after it has been added with @oproc{Context.AddNode}.  *)
    descendentList-: Edge;
    (**List of edges enumerating the descendents of a node.  The edges are
       linked with @ofield{Edge.nextDescendent}.  *)
    ancestorList-: Edge; 
    (**List of edges enumerating the ancestors of a node.  The edges are
       linked with @ofield{Edge.nextAncestor}.  *)
    blockingEntities: LONGINT;
    (**The number of entities in the node's ancestor list that are not in one
       of the states @oconst{entityValid} or @oconst{entityInvalid}.  If this
       value is zero, then @emph{all} ancestors have been classified as being
       ``valid'' or ``invalid''.  *)
    ancestorOfTarget: BOOLEAN;
    (**If @code{TRUE}, then this node is a direct or indirect ancestor of the
       @ofield{Context.target} command.  *)
  END;

TYPE
  EdgeDesc* = RECORD
  (**An instance of @otype{Edge} represents a directed connection of two nodes
     of the dependency graph.  The edges begins at the descendent node, and
     ends with the ancestor node.  The edges are directed in the mathematical
     senses, and they can be traversed in both directions.  It is possible to
     enumerate all edges from a decendant to an ancestor, and vice versa.  *)
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
  Command* = POINTER TO CommandDesc;
  CommandDesc* = RECORD [ABSTRACT]
  (**A command creates or updates resources represented by entities.  Before a
     command is activated, all its @emph{in} entities are guaranteed to exist
     and to be in a valid state.  When a command finishes successfully, all its
     @emph{out} entities must exist and be in a valid state.  A failed command
     leaves all its @emph{out} entities in an invalid state.  *)
    (NodeDesc)
    state-: CommandState;
    (* One of @oconst{commandSuccessful}, @oconst{commandFailed}, or >=
       @oconst{commandUndiscovered}.  *)
  END;

TYPE
  Entity* = POINTER TO EntityDesc;
  EntityDesc* = RECORD [ABSTRACT]
  (**A resource like a file, a directory, a server, or a service, or a virtual
     entity that only exists while running a build sequence.  The resource
     represented by an entity object can exist or can be missing; if it exists,
     it may be in a valid or invalid state.  Most entities perform two
     different roles:

     @itemize @bullet
     @item
     Input entity of a command invocation.  Before the command is executed, all
     its input entities must be in a valid state.

     @item
     Output entity of a command.  Upon successful completion, all output
     entities of a command are in a valid state.
     @end itemize

     Entities are the ``glue'' between commands: the information passed into a
     command and all relevant results generated by a command are described by a
     set of entities.  *)
    (NodeDesc)
    state-: EntityState;
    (**One of @oconst{entityInvalid}, @oconst{entityValid}, or >=
       @oconst{entityUndiscovered}.  *)
    command-: Command;
    (**If the entity switched to state @oconst{entityBuild}, the build command
       is retrieved via @oproc{Context.GetCommand} and stored here.  *)
  END;

TYPE
  ContextDesc* = RECORD [ABSTRACT]
  (**All entities and commands exist within a context.  A build process is
     started by evaluating the @ofield{target} command of the context.  Upon
     completion of this command, all entities that have been added to the
     target's ancestor list are up to date, or the build failed.  *)
    nodeList-: Node;
    (**List of all nodes, @otype{Entity} or @otype{Command}, that exist within
       the context.  The nodes are linked via @ofield{Node.nextNode}.  *)
    target-: Command;
    (**This is the target that @oproc{Context.Solve} tries to solve.  Entities
       or commands that are not direct or indirect ancestors of this command
       are ignored.  *)
    config-: Config.Config;
    (**The configuration data that applies for commands and entities in the
       context.  *)
  END;



(* Dependency Edges
   ------------------------------------------------------------------------ *)

PROCEDURE (n: Node) [ABSTRACT] Id* (): String.String;
  END Id;

PROCEDURE WriteLog (node: Node; msg: ARRAY OF CHAR);
  VAR
    str: String.String;
    s: ARRAY 1024 OF CHAR;
  BEGIN
    IF writeLog THEN
      str := node. Id();
      COPY (str. array^, s);
      Strings.Append (": ", s);
      Strings.Append (msg, s);
      Log.Msg (s)
    END
  END WriteLog;

PROCEDURE MarkNodeTransitive (n: Node);
  VAR
    aEdge: Edge;
  BEGIN
    IF ~n. ancestorOfTarget THEN
      n. ancestorOfTarget := TRUE;
      aEdge := n. ancestorList;
      WHILE (aEdge # NIL) DO
        MarkNodeTransitive (aEdge. ancestor);
        aEdge := aEdge. nextAncestor
      END
    END
  END MarkNodeTransitive;

PROCEDURE InitEdge* (edge: Edge; descendent, ancestor: Node);
(**@precond
   Either @oparam{descendent} or @oparam{ancestor} is an @otype{Entity}.
   @end precond  *)
  BEGIN
    ASSERT ((descendent IS Entity) OR (ancestor IS Entity));
    edge. descendent := descendent;
    edge. ancestor := ancestor;
    edge. nextDescendent := NIL;
    edge. nextAncestor := NIL;
  END InitEdge;

PROCEDURE NewEdge (descendent, ancestor: Node): Edge;
  VAR
    edge: Edge;
  BEGIN
    ASSERT (descendent # NIL);
    ASSERT (ancestor # NIL);
    NEW (edge);
    InitEdge (edge, descendent, ancestor);
    RETURN edge
  END NewEdge;

PROCEDURE (edge: Edge) IsInvalid* (): BOOLEAN;
  BEGIN
    RETURN FALSE
  END IsInvalid;

PROCEDURE AddDependence (edge: Edge);
  BEGIN
    ASSERT (edge. ancestor. context # NIL);
    ASSERT (edge. descendent. context # NIL);
    ASSERT (edge. descendent. context = edge. ancestor. context);
    edge. nextDescendent := edge. ancestor. descendentList;
    edge. nextAncestor := edge. descendent. ancestorList;
    edge. ancestor. descendentList := edge;
    edge. descendent. ancestorList := edge;
    
    (* if the edge connects an ancestor of `target' with a node that
       is no ancestor yet, then mark transitively mark ancestor as
       `ancestorOfTarget' *)
    IF edge. descendent. ancestorOfTarget &
       ~edge. ancestor. ancestorOfTarget THEN
      MarkNodeTransitive (edge. ancestor)
    END;
    
    IF ((edge. ancestor IS Entity) &
        (edge. ancestor(Entity). state # entityValid) &
        (edge. ancestor(Entity). state # entityInvalid)) THEN
      INC (edge. descendent. blockingEntities)
    END
  END AddDependence;


(* Node (common base type of both Entity and Command)
   ------------------------------------------------------------------------ *)

PROCEDURE InitNode* (n: Node);
  BEGIN
    Object.Init (n);
    n. nextNode := NIL;
    n. context := NIL;
    n. descendentList := NIL;
    n. ancestorList := NIL;
    n. blockingEntities := 0;
    n. ancestorOfTarget := FALSE;
  END InitNode;

PROCEDURE (n: Node) HasInvalidAncestor*(): BOOLEAN;
  VAR
    aEdge: Edge;
  BEGIN
    aEdge := n. ancestorList;
    WHILE (aEdge # NIL) DO
      IF (aEdge. ancestor IS Entity) &
         (aEdge. ancestor(Entity). state = entityInvalid) THEN
        RETURN TRUE
      END;
      aEdge := aEdge. nextAncestor
    END;
    RETURN FALSE
  END HasInvalidAncestor;

PROCEDURE (n: Node) HasInvalidAncestorEdge*(): BOOLEAN;
  VAR
    aEdge: Edge;
  BEGIN
    aEdge := n. ancestorList;
    WHILE (aEdge # NIL) DO
      IF aEdge. IsInvalid() THEN
        RETURN TRUE
      END;
      aEdge := aEdge. nextAncestor
    END;
    RETURN FALSE
  END HasInvalidAncestorEdge;

PROCEDURE (n: Node) IsDescendentOf* (parent: Node): BOOLEAN;
  VAR
    aEdge: Edge;
  BEGIN
    aEdge := n. ancestorList;
    WHILE (aEdge # NIL) DO
      IF (aEdge. ancestor = parent) THEN
        RETURN TRUE
      END;
      aEdge := aEdge. nextAncestor
    END;
    RETURN FALSE
  END IsDescendentOf;

PROCEDURE (n: Node) AddAncestor* (ancestor: Node);
  BEGIN
    AddDependence (NewEdge (n, ancestor))
  END AddAncestor;

PROCEDURE (n: Node) AddDescendent* (descendent: Node);
  BEGIN
    AddDependence (NewEdge (descendent, n))
  END AddDescendent;

PROCEDURE (n: Node) AddAncestors* (source: Node);
(**Adds edges to non-command ancestors of @oparam{source} to @oparam{n}.  *)
  VAR
    aEdge: Edge;
  BEGIN
    aEdge := source. ancestorList;
    WHILE (aEdge # NIL) DO
      IF (aEdge. ancestor IS Entity) THEN
        n. AddAncestor (aEdge. ancestor)
      END;
      aEdge := aEdge. nextAncestor
    END
  END AddAncestors;


(* Entities
   ------------------------------------------------------------------------ *)

PROCEDURE InitEntity* (entity: Entity);
  BEGIN
    InitNode (entity);
    entity. state := entityUndiscovered;
    entity. command := NIL;
  END InitEntity;

PROCEDURE (entity: Entity) SetState (newState: EntityState);
(**@precond
   @ofield{entity.state} is neither @oconst{entityValid} nor
   @oconst{entityInvalid}.
   @end precond  *)
  VAR
    dEdge: Edge;
  BEGIN
    ASSERT ((entity. state # entityValid) &
            (entity. state # entityInvalid));
    entity. state := newState;
    IF (newState = entityValid) OR (newState = entityInvalid) THEN
      dEdge := entity. descendentList;
      WHILE (dEdge # NIL) DO
        DEC (dEdge. descendent. blockingEntities);
        dEdge := dEdge. nextDescendent
      END
    END
  END SetState;

PROCEDURE (entity: Entity) [ABSTRACT] Discover*(): EntityState;
(**Called by the framework to add information to the node.  When this method is
   called, all entity ancestors of the node have been classified as either
   @oconst{entityValid} or @oconst{entityInvalid}.  Based on the ancestor's
   data and the @oparam{entity} itself, an implementation can do one of the
   following:

   @itemize @bullet
   @item
   Add further nodes to the ancestor list, that is, extend the list of entities
   on which the current entity depends.  The method must return a value of
   >=@oconst{entityUndiscovered}.  It will be called again once the newly added
   ancestors have been given their final classification, ``valid'' or
   ``invalid''.
   
   @item
   Set the final state of the entity.  In this case, the function result is
   either@oconst{entityValid} or @oconst{entityInvalid}.

   @item
   Tell the framework to (re-)build the entity by running the command
   associated with the entity.  In this case, the method must return
   @oconst{entityBuild}.
   @end itemize

   @precond
   @oparam{entity} is ancestor of the context's target and
   @samp{@ofield{entity.state} >= @oconst{entityUndiscovered}} and
   all ancestors of @oparam{entity} have a state of @oconst{entityValid} or
   @oconst{entityInvalid}.
   @end precond  *)
  END Discover;


(* Commands
   ------------------------------------------------------------------------ *)

PROCEDURE InitCommand* (cmd: Command);
  BEGIN
    InitNode (cmd);
    cmd. state := commandUndiscovered
  END InitCommand;

PROCEDURE (cmd: Command) SetState (newState: CommandState);
  BEGIN
    cmd. state := newState
  END SetState;

PROCEDURE (cmd: Command) [ABSTRACT] Discover*(): CommandState;
(**Called by the framework to add information to the node.  When this method is
   called, all entity ancestors of the node have been classified as either
   @oconst{entityValid} or @oconst{entityInvalid}.  Based on the ancestor's
   data and the @oparam{cmd} itself, an implementation can do one of the
   following:

   @itemize @bullet
   @item
   Add further nodes to the ancestor list, that is, extend the list of entities
   on which the command depends.  The method must return a value of
   >=@oconst{commandUndiscovered}.  It will be called again once the newly
   added ancestors have been given their final classification, ``valid'' or
   ``invalid''.
   
   @item
   Decide that the command cannot be executed, typically because a required
   ancestor entity is invalid.  Result is @oconst{commandInvalid}.

   @item
   Tell the framework to schedule the command for execution.  In this case, the
   method's result is @oconst{commandSchedule}.
   @end itemize

   @precond
   @oparam{cmd} is ancestor of the context's target and
   @samp{@ofield{cmd.state} >= @oconst{commandUndiscovered}} and
   all ancestors of @oparam{cmd} have a state of @oconst{entityValid} or
   @oconst{entityInvalid}.
   @end precond  *)
  END Discover;

PROCEDURE (cmd: Command) [ABSTRACT] Run*(): BOOLEAN;
  END Run;

PROCEDURE (cmd: Command) [ABSTRACT] ProduceOutput* (stdout, stderr: Channel.Channel);
  END ProduceOutput;

(* Context
   ------------------------------------------------------------------------ *)

PROCEDURE (context: Context) [ABSTRACT] GetCommand* (entity: Entity): Command;
(**Called after node @oparam{entity} switched to the state
   @oconst{entityBuild}.  Result is a command that produces @oparam{entity} as
   one of its output entities.  The entity @oparam{entity} is automatically
   added to the command's descendents.  If the command has additional
   descendents, it is expected to add them to its ancestor list with its first
   call to @oproc{Command.Discover}.

   @postcond
   The context of the returned command is @code{NIL} or equal to
   @oparam{context}.
   @end postcond  *)
  END GetCommand;

PROCEDURE (context: Context) AddNode* (n: Node);
  BEGIN
    n. nextNode := context. nodeList;
    context. nodeList := n;
    n. context := context
  END AddNode;

PROCEDURE (context: Context) Solve* (stdout, stderr: Channel.Channel): BOOLEAN;
  PROCEDURE MarkDescendentsInvalid (node: Node);
    VAR
      dEdge: Edge;
    BEGIN
      dEdge := node. descendentList;
      WHILE (dEdge # NIL) DO
        IF (dEdge. descendent(Entity). state # entityValid) &
           (dEdge. descendent(Entity). state # entityInvalid) THEN
          dEdge. descendent(Entity). SetState (entityInvalid)
        END;
        dEdge := dEdge. nextDescendent
      END
    END MarkDescendentsInvalid;
  
  PROCEDURE MarkDescendentsValid (node: Node);
    VAR
      dEdge: Edge;
    BEGIN
      dEdge := node. descendentList;
      WHILE (dEdge # NIL) DO
        IF (dEdge. descendent(Entity). state # entityValid) THEN
          (* descendent cannot be invalid, because it is derived from
             a build command *)
          dEdge. descendent(Entity). SetState (entityValid)
        END;
        dEdge := dEdge. nextDescendent
      END
    END MarkDescendentsValid;
  
  PROCEDURE DiscoverNodes(): BOOLEAN;
    VAR
      node: Node;
      didDiscover: BOOLEAN;
    BEGIN
      didDiscover := FALSE;
      node := context. nodeList;
      WHILE (node # NIL) DO
        IF node. ancestorOfTarget & (node. blockingEntities = 0) THEN
          WITH node: Entity DO
            IF (node. state >= entityUndiscovered) THEN
              WriteLog (node, "discovering");
              node. SetState (node. Discover());
              didDiscover := TRUE
            END;
            IF (node. state = entityBuild) & (node. command = NIL) THEN
              WriteLog (node, "adding build command");
              node. command := context. GetCommand (node);
              IF (node. command. context = NIL) THEN
                context. AddNode (node. command)
              ELSE
                ASSERT (node. command. context = context)
              END;
              WriteLog (node. command, "new build command");
              IF ~node. IsDescendentOf (node. command) THEN
                node. command. AddDescendent (node)
              END;
              didDiscover := TRUE
            END
          | node: Command DO
            IF (node. state >= commandUndiscovered) THEN
              WriteLog (node, "discovering");
              node. SetState (node. Discover());
              didDiscover := TRUE
            END
          END
        END;
        node := node. nextNode
      END;
      RETURN didDiscover
    END DiscoverNodes;
  
  PROCEDURE RunCommands;
    VAR
      node: Node;
    BEGIN
      node := context. nodeList;
      WHILE (node # NIL) DO
        WITH node: Entity DO
          (* ignore entities *)
        | node: Command DO
          IF (node. state = commandSchedule) THEN
            WriteLog (node, "running");
            IF node. Run () THEN
              WriteLog (node, "completed successfully");
              node. SetState (commandSuccessful);
              MarkDescendentsValid (node);
            ELSE
              WriteLog (node, "completed with error");
              node. SetState (commandFailed);
              MarkDescendentsInvalid (node)
            END;
            node. ProduceOutput (stdout, stderr)
          END
        END;
        node := node. nextNode
      END;
    END RunCommands;
  
  BEGIN
    LOOP
      IF DiscoverNodes() THEN
        REPEAT UNTIL ~DiscoverNodes()
      ELSE
        EXIT
      END;
      RunCommands
    END;
    RETURN (context. target. state = commandSuccessful)
  END Solve;

PROCEDURE (context: Context) AddDependence* (edge: Edge);
  BEGIN
    AddDependence (edge)
  END AddDependence;

PROCEDURE (context: Context) Exists* (n: Node): BOOLEAN;
  VAR
    node: Node;
  BEGIN
    node := context. nodeList;
    WHILE (node # NIL) & (node # n) DO
      node := node. nextNode
    END;
    RETURN (node # NIL)
  END Exists;

PROCEDURE (context: Context) GetNamedEntity* (name: ARRAY OF CHAR): Entity;
  BEGIN
    RETURN NIL
  END GetNamedEntity;
  
PROCEDURE InitContext* (context: Context; config: Config.Config; target: Command);
  BEGIN
    context. nodeList := NIL;
    context. config := config;
    context. AddNode (target);
    MarkNodeTransitive (target);
    context. target := target
  END InitContext;

END Make.
