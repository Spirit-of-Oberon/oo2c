MODULE Make:Edge:TimeDep;

IMPORT
  Time, Make, Make:Entity:Resource;


TYPE
  Edge* = POINTER TO EdgeDesc;
  EdgeDesc = RECORD
    (Make.EdgeDesc)
  END;

PROCEDURE Init* (edge: Edge; descendent, ancestor: Resource.Entity);
  BEGIN
    Make.InitEdge (edge, descendent, ancestor)
  END Init;

PROCEDURE New* (descendent, ancestor: Resource.Entity): Edge;
  VAR
    edge: Edge;
  BEGIN
    NEW (edge);
    Init (edge, descendent, ancestor);
    RETURN edge
  END New;

PROCEDURE (edge: Edge) IsInvalid*(): BOOLEAN;
(**Returns @code{TRUE} if the entity @ofield{edge.descendent} does not exist,
   of it the ancestor's time stamp is more recent than that of the descendent.
   Note: If both have the same time stamp (which usually has only a resolution
   of one second), the descendent is assumed to be valid and result is
   @code{FALSE}.

   @precond
   The edge's ancestor is marked as ``valid''.
   @end precond  *)
  VAR
    tsDescendent, tsAncestor: Time.TimeStamp;
  BEGIN
    ASSERT (edge. ancestor(Resource.Entity). state = Make.entityValid);
    IF edge. descendent(Resource.Entity). Exists() THEN
      edge. descendent(Resource.Entity). GetTimeStamp (tsDescendent);
      edge. ancestor(Resource.Entity). GetTimeStamp (tsAncestor);
      RETURN (tsAncestor. Cmp (tsDescendent) > 0)
    ELSE
      RETURN TRUE
    END
  END IsInvalid;

END Make:Edge:TimeDep.
