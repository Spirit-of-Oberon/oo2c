MODULE OOC:Make:Edge:TimeStampDep;

IMPORT
  Time, OOC:Make;


TYPE
  Edge* = POINTER TO EdgeDesc;
  EdgeDesc = RECORD
    (Make.EdgeDesc)
  END;

PROCEDURE Init* (edge: Edge; descendent, ancestor: Make.Node);
  BEGIN
    Make.InitEdge (edge, descendent, ancestor)
  END Init;

PROCEDURE New* (descendent, ancestor: Make.Node): Edge;
  VAR
    edge: Edge;
  BEGIN
    NEW (edge);
    Init (edge, descendent, ancestor);
    RETURN edge
  END New;

PROCEDURE (edge: Edge) Invalidated*(): BOOLEAN;
(**Returns @code{TRUE} is the ancestor's time stamp is more recent than that 
   of the descendent.  Note: If both have the same time stamp (which usually
   has only a resolution of one second), the descendent is assumed to be
   valid and result is @code{FALSE}.  *)
  VAR
    tsDescendent: Time.TimeStamp;
  BEGIN
    edge. descendent. GetTimeStamp (tsDescendent);
    RETURN (edge. ancestor. effectiveTimeStamp. Cmp (tsDescendent) > 0)
  END Invalidated;

END OOC:Make:Edge:TimeStampDep.
