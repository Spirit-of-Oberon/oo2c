(* 	$Id$	 *)
MODULE Make:Edge:TimeDep;
(*  Implements dependencies between resources based on time stamps.
    Copyright (C) 2001  Michael van Acken

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


IMPORT
  Time, Make, Make:Entity:Resource;


TYPE
  Edge* = POINTER TO EdgeDesc;
  EdgeDesc = RECORD
    (**The descendant of such an edge is invalid if it does not exist, or if
       the ancestor is more recent.  *)
    (Make.EdgeDesc)
  END;

PROCEDURE Init* (edge: Edge; descendant, ancestor: Resource.Entity);
  BEGIN
    Make.InitEdge (edge, descendant, ancestor)
  END Init;

PROCEDURE New* (descendant, ancestor: Resource.Entity): Edge;
(**Creates a new instance of @otype{Edge}.  *)
  VAR
    edge: Edge;
  BEGIN
    NEW (edge);
    Init (edge, descendant, ancestor);
    RETURN edge
  END New;

PROCEDURE (edge: Edge) IsInvalid*(): BOOLEAN;
(**Returns @code{TRUE} if the entity @ofield{edge.descendant} does not exist,
   of it the ancestor's time stamp is more recent than that of the descendant.
   Note: If both have the same time stamp (which usually has only a resolution
   of one second), the descendant is assumed to be valid and result is
   @code{FALSE}.

   @precond
   The edge's ancestor is marked as ``valid''.
   @end precond  *)
  VAR
    tsDescendant, tsAncestor: Time.TimeStamp;
  BEGIN
    ASSERT (edge. ancestor(Resource.Entity). state = Make.entityValid);
    IF edge. descendant(Resource.Entity). Exists() THEN
      edge. descendant(Resource.Entity). GetTimeStamp (tsDescendant);
      edge. ancestor(Resource.Entity). GetTimeStamp (tsAncestor);
      RETURN (tsAncestor. Cmp (tsDescendant) > 0)
    ELSE
      RETURN TRUE
    END
  END IsInvalid;

END Make:Edge:TimeDep.
