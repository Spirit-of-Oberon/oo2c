(* 	$Id$	 *)
MODULE Make:Entity:Group;
(*  Implements a group of entities.
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
  Make, ADT:String;

TYPE
  Entity* = POINTER TO EntityDesc;
  EntityDesc* = RECORD
  (**Implements a group of entities.  Does not add any ancestors in
     @oproc{*Make:Target.Discover}.  *)
  
    (Make.EntityDesc)
  END;

PROCEDURE Init* (entity: Entity; context: Make.Context);
  BEGIN
    Make.InitEntity (entity, context)
  END Init;

PROCEDURE New* (context: Make.Context): Entity;
(**Creates a new instance of @otype{Entity}.  *)
  VAR
    entity: Entity;
  BEGIN
    NEW (entity);
    Init (entity, context);
    RETURN entity
  END New;

PROCEDURE (entity: Entity) Discover* (): Make.EntityState;
(**Returns @oconst{Make.entityInvalid} if any of the ancestors is invalid, and
   @oconst{Make.entityValid} otherwise.  *)
  BEGIN
    IF entity. HasInvalidAncestor() THEN
      RETURN Make.entityInvalid
    ELSE
      RETURN Make.entityValid
    END
  END Discover;

PROCEDURE (entity: Entity) Id* (): String.String;
  BEGIN
    RETURN String.New ("[Make:Entity:Group]")
  END Id;

END Make:Entity:Group.
