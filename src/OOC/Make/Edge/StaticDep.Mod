MODULE OOC:Make:Edge:StaticDep;

IMPORT
  OOC:Make;


TYPE
  Edge* = POINTER TO EdgeDesc;
  EdgeDesc = RECORD
    (**Models a static relationship between two nodes.  Depending on the 
       value of @oparam{Init.invalid}, the relationship is either always
       valid or always invalid.  *)
    (Make.EdgeDesc)
    invalid: BOOLEAN;
  END;

PROCEDURE Init* (edge: Edge; descendent, ancestor: Make.Node; invalid: BOOLEAN);
  BEGIN
    Make.InitEdge (edge, descendent, ancestor)
  END Init;

PROCEDURE New* (descendent, ancestor: Make.Node; invalid: BOOLEAN): Edge;
  VAR
    edge: Edge;
  BEGIN
    NEW (edge);
    Init (edge, descendent, ancestor, invalid);
    RETURN edge
  END New;

PROCEDURE (edge: Edge) Invalidated*(): BOOLEAN;
(**Result is the value of @oparam{Init.invalid}.  *)
  BEGIN
    RETURN edge. invalid
  END Invalidated;

END OOC:Make:Edge:StaticDep.
