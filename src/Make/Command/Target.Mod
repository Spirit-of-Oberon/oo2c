(* 	$Id$	 *)
MODULE Make:Command:Target;
(*  Default target for `Make.Context'.
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
  Channel, Make, ADT:String;


TYPE
  Target* = POINTER TO TargetDesc;
  TargetDesc* = RECORD
  (**Default target for @otype{Make.Context}.  Does not add any ancestors in
     @oproc{Target.Discover}, and @oproc{Target.Run} always returns
     @code{TRUE}.  *)
  
    (Make.CommandDesc)
  END;

(* Default Target
   ------------------------------------------------------------------------ *)

PROCEDURE Init* (target: Target);
  BEGIN
    Make.InitCommand (target, NIL);
  END Init;

PROCEDURE New* (): Target;
(**Creates a new instance of @otype{Target}.  *)
  VAR
    target: Target;
  BEGIN
    NEW (target);
    Init (target);
    RETURN target
  END New;

PROCEDURE (target: Target) Id* (): String.String;
  BEGIN
    RETURN String.New ("[target]")
  END Id;

PROCEDURE (target: Target) Discover*(): Make.CommandState;
(**Returns @oconst{Make.commandInvalid} if any of the ancestors is invalid, and
   @oconst{Make.commandSchedule} otherwise.  *)
  BEGIN
    IF target. HasInvalidAncestor() THEN
      RETURN Make.commandInvalid
    ELSE
      RETURN Make.commandSchedule
    END
  END Discover;

PROCEDURE (target: Target) Run*(): BOOLEAN;
(**Empty command, result is always @code{TRUE}.  *)
  BEGIN
    RETURN TRUE
  END Run;

PROCEDURE (target: Target) ProduceOutput* (stdout, stderr: Channel.Channel);
(**Empty procedure.  *)
  BEGIN
  END ProduceOutput;

END Make:Command:Target.
