(* 	$Id$	 *)
MODULE OOC:Make:Entity:UsageData;
(*  Implements pseudo `Make' entity to collect usage date of declarations.
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
  Channel, Msg, ADT:Object, ADT:String, ADT:Dictionary, ADT:ArrayList,
  Make, OOC:Make:Entity:ModuleFile, 
  Rep := OOC:Repository, OOC:SymbolTable:Item,
  OOC:Auxiliary:Config, OOC:Auxiliary:GetSymbolTable;



TYPE
  Entity* = POINTER TO EntityDesc;
  EntityDesc = RECORD
    (Make.EntityDesc)
    extensionDict-: Dictionary.Dictionary;
  END;

TYPE
  Command* = POINTER TO CommandDesc;
  CommandDesc = RECORD
    (Make.CommandDesc)
    usageData: Entity;
  END;


PROCEDURE NewCommand* (context: Make.Context; usageData: Entity): Command;
  VAR
    cmd: Command;
  BEGIN
    NEW (cmd);
    Make.InitCommand (cmd, context);
    cmd. usageData := usageData;
    RETURN cmd
  END NewCommand;

PROCEDURE (cmd: Command) Id* (): String.String;
  BEGIN
    RETURN String.New ("[OOC:Make:Entity:UsageDate.Command]")
  END Id;

PROCEDURE (cmd: Command) Discover*(): Make.CommandState;
  BEGIN
    IF cmd. HasInvalidAncestor() THEN
      RETURN Make.commandInvalid
    ELSE
      RETURN Make.commandSchedule
    END
  END Discover;
  
PROCEDURE (cmd: Command) Run*(): BOOLEAN;
  VAR
    edge: Make.Edge;
    module: Item.Module;
    ptr, base: Item.Item;
    extensionDict: Dictionary.Dictionary;
    list: ArrayList.ArrayList;
    obj: Object.Object;
    res: Msg.Msg;
    config: Config.Config;
  BEGIN
    extensionDict := Dictionary.New();
    config := cmd. context. config(Config.Config);
    
    edge := cmd. usageData. ancestorList;
    WHILE (edge # NIL) DO
      IF (edge. ancestor # cmd) THEN
        module := GetSymbolTable.GetSymbolTable (
                      edge. ancestor(ModuleFile.Entity). module, config, res);
        ptr := module. nestedItems;
        WHILE (ptr # NIL) DO
          IF (ptr IS Item.Record) & (ptr(Item.Record). baseType # NIL) THEN
            base := ptr(Item.Record). baseType;
            IF extensionDict. HasKey (base) THEN
              obj := extensionDict. Get (base);
              list := obj(ArrayList.ArrayList)
            ELSE
              list := ArrayList.New (4);
              extensionDict. Set (base, list)
            END;
            list. Append (ptr)
          END;
          ptr := ptr. nextNested
        END
      END;
      
      edge := edge. nextAncestor
    END;
    
    cmd. usageData. extensionDict := extensionDict;
    RETURN TRUE
  END Run;

PROCEDURE (cmd: Command) ProduceOutput* (stdout, stderr: Channel.Channel);
  BEGIN
  END ProduceOutput;

(* ------------------------------------------------------------------------ *)

PROCEDURE InitEntity (entity: Entity; context: Make.Context);
  BEGIN
    Make.InitEntity (entity, context);
    entity. extensionDict := NIL;
  END InitEntity;

PROCEDURE NewEntity* (context: Make.Context): Entity;
  VAR
    entity: Entity;
  BEGIN
    NEW (entity);
    InitEntity (entity, context);
    RETURN entity
  END NewEntity;

PROCEDURE (entity: Entity) Id* (): String.String;
  BEGIN
    RETURN String.New ("[OOC:Make:Entity:UsageDate.Entity]")
  END Id;

PROCEDURE (entity: Entity) Discover*(): Make.EntityState;
(**Adds the symbol files of all @otype{ModuleFile.Entity} instances in the
   dependency graph as ancestors to @oparam{entity}.  That is, for every
   instance of @otype{ModuleFile.Entity} in the graph, the corresponding symbol
   file node is located and added as an ancestor to @oparam{entity}.  Please
   note that modules that are @emph{not} part of the graph at the time that
   this procedure is called are also @emph{not} added to the ancestor list.  *)
  VAR
    ptr: Make.Node;
    symFile: ModuleFile.Entity;
  BEGIN
    IF (entity. state = Make.entityUndiscovered) THEN
      ptr := entity. context. nodeList;
      WHILE (ptr # NIL) DO
        IF (ptr IS ModuleFile.Entity) THEN
          symFile := ModuleFile.GetEntity (entity. context,
                            ptr(ModuleFile.Entity). module, Rep.modSymbolFile);
          IF ~entity. IsDescendantOf (symFile) THEN
            entity. AddAncestor (symFile)
          END
        END;
        ptr := ptr. nextNode
      END;
      RETURN entity. state+1
    ELSIF entity. HasInvalidAncestor() THEN
      RETURN Make.entityInvalid
    ELSE
      RETURN Make.entityBuild
    END
  END Discover;

END OOC:Make:Entity:UsageData.
