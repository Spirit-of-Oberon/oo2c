(* 	$Id$	 *)
MODULE Make:Entity:Resource [OOC_EXTENSIONS];
(*  Abstract class for entities with URI and time stamp.
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
  Make, Time, URI;



TYPE
  Entity* = POINTER TO EntityDesc;
  EntityDesc* = RECORD [ABSTRACT]
  (**A specialisation of @otype{Make.Entity} that is associated with an Uniform
     Resource Identifier @otype{URI.URI} and a time stamp.  The time stamps are
     for example evaluated by @otype{*Make:Edge:TimeDep.Edge}.  *)
    (Make.EntityDesc)
  END;

PROCEDURE Init* (entity: Entity; context: Make.Context);
  BEGIN
    Make.InitEntity (entity, context)
  END Init;

PROCEDURE (entity: Entity) [ABSTRACT] GetURI* (): URI.URI;
(**Returns the URI of the entity.  *)
  END GetURI;

PROCEDURE (entity: Entity) [ABSTRACT] Exists* (): BOOLEAN;
(**Returns @code{TRUE} if the resource associated with the entity exists.  *)
  END Exists;

PROCEDURE (entity: Entity) [ABSTRACT] GetTimeStamp* (VAR ts: Time.TimeStamp);
(**Returns the time stamp of @oparam{entity}.  This can be the time stamp of
   the resource itself, the maximum time stamp of the resource and all its
   ancestors, or some variant between these two extremes.

   @precond
   All ancestors of @oparam{entity} are known to be ``valid''.
   @end precond  *)
  END GetTimeStamp;
  
END Make:Entity:Resource.
