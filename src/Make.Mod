(* 	$Id$	 *)
MODULE Make [OOC_EXTENSIONS];
(*  Framework for discovering and building interdependend resources.
    Copyright (C) 2001, 2002  Michael van Acken

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

(**This module provides a framework to identify and execute the commands
   necessary to bring a given set of targets up to date.  For each target, it
   identifies the resources required to determine if the target is up to date.
   If the target is invalid, because it does not exist, or one of the ancestor
   resources indicates that it must be rebuild, a command is executed to create
   a new version of the target resource.  Once added to the process, ancestor
   resources become intermediate targets themselves, and are resolved in a
   similar way.

   Resources are represented by instances of @otype{Entity}, and commands by
   @otype{Command}.  Both are derived from @otype{Node}.  Dependencies between
   entities and commands are modeled by added instances of @otype{Edge} to the
   graph.  @otype{Context} defines the set of targets, indicates which
   configuration data applies to commands, and serves as a container for all
   nodes and edges.  *)

IMPORT
  Channel, Config, Log, Strings, ADT:Object, ADT:String, ADT:Dictionary;

CONST
  writeLog = FALSE;

TYPE
  EntityState* = LONGINT;
  (**Holds the current state of an instance of @otype{Entity}: undicovered,
     valid, invalid, ready to build.  *)
  
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
     values @samp{>=@oconst{entityUndiscovered}} alike.  *)

TYPE
  CommandState* = LONGINT;
  (**Holds the current state of an instance of @otype{Command}: undicovered,
     completed successfully, failed to complete, invalid, or ready to be
     scheduled.  *)

CONST
  commandInvalid* = -4;
  (**The command cannot be scheduled for execution, because at least one of its
     ancestors is in an invalid state.  This state is similar to
     @oconst{commandFailed}, although no attempt is made to actually run the
     command.  *)
  commandSchedule* = -3;
  (**The command is scheduled for execution.  *)
  commandSuccessful* = -2;
  (**The command has been succesfully executed.  *)
  commandFailed* = -1;
  (**The command has been executed, but it failed.  *)
  commandUndiscovered* = 0;
  (**The command's state has not been determined yet.  The framework treats all
     values @samp{>=@oconst{entityUndiscovered}} the same.  *)


TYPE
  Node* = POINTER TO NodeDesc;
  Context* = POINTER TO ContextDesc;
  Edge* = POINTER TO EdgeDesc;
  NodeDesc* = RECORD [ABSTRACT]
  (**The common ancestor of all entities and commands.  This class procides the
     infrastructure to manage a graph of dependencies.  *)
    (Object.ObjectDesc)
    nextNode-: Node;
    (**Linked list of all nodes, both entities and commands, in the
       @otype{Context}.  *)
    context-: Context;
    (**The node's context for which it has been created.  *)
    descendantList-: Edge;
    (**List of edges enumerating the descendants of a node.  The edges are
       linked with @ofield{Edge.nextDescendant}.  *)
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
     of the dependency graph.  The edge begins at the descendant node, and ends
     with the ancestor node.  It is directed in the mathematical senses, and
     can be traversed in both directions.  It is possible to enumerate all
     edges from a decendant to its ancestor, and vice versa.

     An edge orignating from an instance of @otype{Entity} designates a ``must
     be evaluated before'' relationship.  That is, the ancestor of the edge
     must have a known state (valid or invalid) before the state of the
     descendant can be determined.

     On the other hand, an edge originating at a @otype{Command} indicates the
     the descendant of this edge is created when running the command.  A
     command can have multiple descendants.  There are no edges between two
     instances of @otype{Command}.  *)
    descendant-: Node;
    (**The (virtual) starting node of the edge.  It designates the descendant
       of the ancestor/descendant relationship represented by the edge.  *)
    ancestor-: Node;
    (**The (virtual) ending node of the edge.  It designates the ancestor
       of the ancestor/descendant relationship represented by the edge.  *)
    nextDescendant-: Edge;
    (**The next edge in the list of edges anchored in
       @samp{Edge.ancestor.descendantList}.  *)
    nextAncestor-: Edge;
    (**The next edge in the list of edges anchored in
       @samp{Edge.descendant.ancestorList}.  *)
  END;


TYPE
  Command* = POINTER TO CommandDesc;
  CommandDesc* = RECORD [ABSTRACT]
  (**A command creates or updates resources represented by entities.  Before a
     command is activated, the state of all its ancestor entities is known.
     Typically, all ancestors are required to be valid in this case.  When a
     command finishes successfully, all its descendant entities must exist and
     be in a valid state.  A failed command leaves all its descendants in an
     invalid state (with the exception of those that were valid beforehand).  *)
    (NodeDesc)
    state-: CommandState;
    (* One of @oconst{commandInvalid}, @oconst{commandSchedule},
       @oconst{commandSuccessful}, @oconst{commandFailed}, or >=
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
     Input entity of a command invocation (ancestor of a command).  Before the
     command is executed, all its input entities must be in a valid state.

     @item
     Output entity of a command (descendant of a command).  Upon successful
     completion, all output entities of a command are in a valid state.
     @end itemize

     Entities are the ``glue'' between commands: the information passed into a
     command and all relevant results generated by a command are described by a
     set of entities.

     Sometimes, evaluation of an entity depends on other entities.  For
     example, a file @var{foo} including another file @var{bar} can only be
     used if both files are present.  This is modeled by making the entity of
     @var{bar} a direct ancestor of @var{foo}.  *)
    (NodeDesc)
    state-: EntityState;
    (**One of @oconst{entityBuild}, @oconst{entityInvalid},
       @oconst{entityValid}, or >= @oconst{entityUndiscovered}.  *)
    command-: Command;
    (**If the entity switched to state @oconst{entityBuild}, the build command
       is retrieved via @oproc{Context.GetCommand} and stored here.  *)
  END;

TYPE
  ContextDesc* = RECORD [ABSTRACT]
  (**All entities and commands exist within a context.  A build process is
     started by evaluating the @ofield{target} command of the context.  Upon
     completion of this command, all entities in the target's ancestor list are
     up to date, or the build failed.  *)
    nodeList-: Node;
    (**List of all nodes, @otype{Entity} or @otype{Command}, that exist within
       the context.  The nodes are linked via @ofield{Node.nextNode}.  *)
    nodes-: Dictionary.Dictionary;
    (**Dictionary holding all nodes from @ofield{nodeList}.  Key and value
       of each entry are references to the node object.  *)
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
(**Returns a string that identifies the node.  Only used for debugging
   purposes.  Should not return @code{NIL}.  *)
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

PROCEDURE InitEdge* (edge: Edge; descendant, ancestor: Node);
(**Initializes a new edge instance.s

   @precond
   Both nodes are part of the same context.  Either @oparam{descendant} or
   @oparam{ancestor} is an @otype{Entity}.
   @end precond  *)
  BEGIN
    ASSERT (descendant. context = ancestor. context);
    ASSERT ((descendant IS Entity) OR (ancestor IS Entity));
    edge. descendant := descendant;
    edge. ancestor := ancestor;
    edge. nextDescendant := NIL;
    edge. nextAncestor := NIL;
  END InitEdge;

PROCEDURE NewEdge (descendant, ancestor: Node): Edge;
  VAR
    edge: Edge;
  BEGIN
    NEW (edge);
    InitEdge (edge, descendant, ancestor);
    RETURN edge
  END NewEdge;

PROCEDURE (edge: Edge) IsInvalid* (): BOOLEAN;
(**Returns @code{TRUE} if the descendant of the given edge is invalid with
   respect to the edge'e ancestor.  See @oproc{*Make:Edge:TimeDep.Edge.Invalid}
   for an example.

   The default implementation always returns @code{FALSE}.
   
   @precond
   The edge's ancestor is marked as ``valid''.
   @end precond  *)
  BEGIN
    RETURN FALSE
  END IsInvalid;

PROCEDURE AddDependence (edge: Edge);
(*  VAR
    str: String.String;*)
  BEGIN
    ASSERT (edge. ancestor. context # NIL);
    ASSERT (edge. descendant. context # NIL);
    ASSERT (edge. descendant. context = edge. ancestor. context);
    edge. nextDescendant := edge. ancestor. descendantList;
    edge. nextAncestor := edge. descendant. ancestorList;
    edge. ancestor. descendantList := edge;
    edge. descendant. ancestorList := edge;

(*    str := edge. ancestor. Id();
    Log.String ("ancestor", str. array^);
    str := edge. descendant. Id();
    Log.String ("descendant", str. array^);*)
    (* if the edge connects an ancestor of `target' with a node that
       is no ancestor yet, then mark transitively mark ancestor as
       `ancestorOfTarget' *)
    IF edge. descendant. ancestorOfTarget &
       ~edge. ancestor. ancestorOfTarget THEN
      MarkNodeTransitive (edge. ancestor)
    END;
    
    IF ((edge. ancestor IS Entity) &
        (edge. ancestor(Entity). state # entityValid) &
        (edge. ancestor(Entity). state # entityInvalid)) THEN
      INC (edge. descendant. blockingEntities)
    END
  END AddDependence;


(* Node (common base type of both Entity and Command)
   ------------------------------------------------------------------------ *)

PROCEDURE AddNode (context: Context; n: Node);
  BEGIN
    n. nextNode := context. nodeList;
    context. nodeList := n;
    n. context := context;
    context. nodes. Set(n, n);
  END AddNode;

PROCEDURE InitNode* (n: Node; context: Context);
(**Intializes the given node @oparam{n} and adds it to the @oparam{context}.
   If @oparam{context} is @code{NIL}, then the node can only be used as the
   target of @oproc{InitContext}.  *)
  BEGIN
    Object.Init (n);
    n. nextNode := NIL;
    n. context := NIL;
    n. descendantList := NIL;
    n. ancestorList := NIL;
    n. blockingEntities := 0;
    n. ancestorOfTarget := FALSE;
    IF (context # NIL) THEN
      AddNode (context, n)
    END
  END InitNode;

PROCEDURE (n: Node) HasInvalidAncestor*(): BOOLEAN;
(**Returns @code{TRUE} if @oparam{n} has an ancestor entity with a state of
   @oconst{entityInvalid}.  Ancestors that are derived from @otype{Command} are
   ignored.  *)
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
(**Is @code{TRUE} if any of the ancestor edges of @oparam{n} reports
   @samp{@oproc{Edge.IsInvalid}()=@code{TRUE}}.  *)
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

PROCEDURE (n: Node) IsDescendantOf* (parent: Node): BOOLEAN;
(**Is @code{TRUE} if @oparam{n} is a direct descendant of @oparam{parent}.  *)
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
  END IsDescendantOf;

PROCEDURE (n: Node) AddAncestor* (ancestor: Node);
(**Adds a new edge between @oparam{ancestor} and @oparam{n} (the descendant).  *)
  BEGIN
    AddDependence (NewEdge (n, ancestor))
  END AddAncestor;

PROCEDURE (n: Node) AddDescendant* (descendant: Node);
(**Adds a new edge between @oparam{n} (the ancestor) and @oparam{descendant}.  *)
  BEGIN
    AddDependence (NewEdge (descendant, n))
  END AddDescendant;

PROCEDURE (n: Node) AddAncestors* (source: Node);
(**Adds edges to all entity ancestors of @oparam{source} to @oparam{n}.
   Command ancestors are ignored.  *)
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

PROCEDURE InitEntity* (entity: Entity; context: Context);
(**Initializes the entity and adds it to @oparam{context}.  *)
  BEGIN
    InitNode (entity, context);
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
      dEdge := entity. descendantList;
      WHILE (dEdge # NIL) DO
        DEC (dEdge. descendant. blockingEntities);
        dEdge := dEdge. nextDescendant
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
   Set the final state of the entity to @samp{success}.  In this case, the
   function result is @oconst{entityValid}.
 
   @item
   Set the final state of the entity to @samp{failure}.  In this case, the
   function result is @oconst{entityInvalid}.  The the failure is caused by the
   entity itself, and not by one of its ancestors, then the function is also
   required to produce an error message.

   @item
   Tell the framework to (re-)build the entity by running the command
   associated with the entity.  In this case, the method must return
   @oconst{entityBuild}.
   @end itemize

   A typical implementation of this procedure looks like this:

   @example
   IF (entity. state = Make.entityUndiscovered) THEN
     (* add all resources on which `entity'
        depends to its ancestor list ... *)
     RETURN entity. state+1
   ELSE
     IF entity. HasInvalidAncestor() THEN
       (* fail if an ancestor resource is unavailable *)
       RETURN Make.entityInvalid
     ELSIF entity. HasInvalidAncestorEdge() THEN
       (* entity is invalid with respect to its ancestors *)
       RETURN Make.entityBuild
     ELSE
       (* entity is still valid; no need to rebuild *)
       RETURN Make.entityValid
     END
   END
   @end example

   @precond
   @oparam{entity} is ancestor of the context's target and
   @samp{@ofield{entity.state} >= @oconst{entityUndiscovered}} and all
   ancestors of @oparam{entity} have a state of @oconst{entityValid} or
   @oconst{entityInvalid}.
   @end precond  *)
  END Discover;


(* Commands
   ------------------------------------------------------------------------ *)

PROCEDURE InitCommand* (cmd: Command; context: Context);
(**Initializes the command and adds it to @oparam{context}.  *)
  BEGIN
    InitNode (cmd, context);
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

   Assuming that the command produces a single entity, and this entity (which
   triggered the creation of this build command) already determined that all
   pre-conditions of the command are fulfilled, a typical implementation of
   this procedure looks like this:

   @example
   entity := (determine output entity...);
   cmd. AddAncestors (entity);
   RETURN Make.commandSchedule
   @end example

   @precond
   @oparam{cmd} is ancestor of the context's target and
   @samp{@ofield{cmd.state} >= @oconst{commandUndiscovered}} and all ancestors
   of @oparam{cmd} have a state of @oconst{entityValid} or
   @oconst{entityInvalid}.
   @end precond  *)
  END Discover;

PROCEDURE (cmd: Command) [ABSTRACT] Run*(): BOOLEAN;
(**Tries to run the command @oparam{cmd}.  Result is @code{TRUE} after
   successful completion, and @code{FALSE} otherwise.  To support concurrent
   evaluation of commands, the command should buffer its output and only write
   it out when @oproc{Command.ProduceOutput} is called.  *)
  END Run;

PROCEDURE (cmd: Command) [ABSTRACT] ProduceOutput* (stdout, stderr: Channel.Channel);
(**Retrieves the output produced by running the command @oparam{cmd}.  *)
  END ProduceOutput;

(* Context
   ------------------------------------------------------------------------ *)

PROCEDURE (context: Context) [ABSTRACT] GetCommand* (entity: Entity): Command;
(**Called after node @oparam{entity} switched to the state
   @oconst{entityBuild}.  Result is a command that produces @oparam{entity} as
   one of its output entities.  The entity @oparam{entity} is automatically
   added to the command's descendants.  If the command has additional
   descendants, it is expected to add them to its ancestor list with its first
   call to @oproc{Command.Discover}.

   @postcond
   The context of the returned command is equal to @oparam{context}.
   @end postcond  *)
  END GetCommand;

PROCEDURE (context: Context) NotifyCompletion* (node: Node; success: BOOLEAN);
(**Called after @samp{node.Run} has finished.  The result of this method
   is passed as input argument to @oparam{success}.  The default implementation
   is an empty procedure.  *)
  BEGIN
  END NotifyCompletion;

PROCEDURE (context: Context) Solve* (stdout, stderr: Channel.Channel): BOOLEAN;
(**Attempts to bring all entities registered as ancestors of
   @ofield{context.target} up to date.  If necessary, resources are build or
   rebuild as part of the process.  Output of commands is written to
   @oparam{stdout} and @oparam{stderr}.  Result is @code{TRUE} if all entities
   in the target set are up to date upon completion, and @code{FALSE}
   otherwise.  *)
  PROCEDURE MarkDescendantsInvalid (node: Node);
    VAR
      dEdge: Edge;
    BEGIN
      dEdge := node. descendantList;
      WHILE (dEdge # NIL) DO
        IF (dEdge. descendant(Entity). state # entityValid) &
           (dEdge. descendant(Entity). state # entityInvalid) THEN
          dEdge. descendant(Entity). SetState (entityInvalid)
        END;
        dEdge := dEdge. nextDescendant
      END
    END MarkDescendantsInvalid;
  
  PROCEDURE MarkDescendantsValid (node: Node);
    VAR
      dEdge: Edge;
    BEGIN
      dEdge := node. descendantList;
      WHILE (dEdge # NIL) DO
        IF (dEdge. descendant(Entity). state # entityValid) THEN
          (* descendant cannot be invalid, because it is derived from
             a build command *)
          dEdge. descendant(Entity). SetState (entityValid)
        END;
        dEdge := dEdge. nextDescendant
      END
    END MarkDescendantsValid;
  
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
              WriteLog (node. command, "new build command");
              IF ~node. IsDescendantOf (node. command) THEN
                node. command. AddDescendant (node)
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
      success: BOOLEAN;
    BEGIN
      node := context. nodeList;
      WHILE (node # NIL) DO
        WITH node: Entity DO
          (* ignore entities *)
        | node: Command DO
          IF (node. state = commandSchedule) THEN
            WriteLog (node, "running");
            success := node. Run();
            IF success THEN
              WriteLog (node, "completed successfully");
              node. SetState (commandSuccessful);
              MarkDescendantsValid (node);
            ELSE
              WriteLog (node, "completed with error");
              node. SetState (commandFailed);
              MarkDescendantsInvalid (node)
            END;
            node. ProduceOutput (stdout, stderr);
            context.NotifyCompletion(node, success);
          END;
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
(**Adds a new @oparam{edge} to the context's dependence graph.  *)
  BEGIN
    AddDependence (edge)
  END AddDependence;

PROCEDURE (context: Context) GetNamedEntity* (name: ARRAY OF CHAR): Entity;
(**Returns an entity of the @oparam{context} identified by name.  If no such
   entity exists, result is @code{NIL}.  *)
  BEGIN
    RETURN NIL
  END GetNamedEntity;
  
PROCEDURE InitContext* (context: Context; config: Config.Config; target: Command);
(**Intializes a new, empty context.  Usually, @oparam{target} is an instance of
   @otype{*Make:Command:Target.Target}.

   @precond
   @code{@ofield{target.context}=@code{NIL}}
   @end precond  *)
  BEGIN
    ASSERT (target. context = NIL);
    context. nodeList := NIL;
    context. nodes := Dictionary.New();
    context. config := config;
    AddNode (context, target);
    MarkNodeTransitive (target);
    context. target := target
  END InitContext;

END Make.
