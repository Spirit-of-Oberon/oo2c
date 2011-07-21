(*	$Id: Select.Mod,v 1.7 2004/11/21 20:31:44 mva Exp $	*)
MODULE IO:Select [FOREIGN "C"; LINK FILE "Select.c" 
  <* IF HAVE_LIB_WSOCK32 THEN *> ; LIB "wsock32" <* END *>
END];
(*  Selector implementation based on the select() function.
    Copyright (C) 2003, 2004  Michael van Acken

    This module is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public License
    as published by the Free Software Foundation; either version 2 of
    the License, or (at your option) any later version.

    This module is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with OOC. If not, write to the Free Software Foundation,
    59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*)
<* Warnings := FALSE *>

IMPORT
  SYSTEM, Object, IO, IO:StdChannels;

TYPE
  SelectionKey* = POINTER TO SelectionKeyDesc;
  SelectionKeyDesc = RECORD
    (IO.SelectionKeyDesc)
  END;
  
TYPE
  Selector* = POINTER TO SelectorDesc;
  SelectorDesc = RECORD
    (IO.SelectorDesc)
    sets: SYSTEM.PTR;
    current: SelectionKey;
  END;

PROCEDURE (s: Selector) INIT*();
PROCEDURE Open*(): Selector;
PROCEDURE (s: Selector) AddSelectionKey*(fd: IO.FileDescriptor;
                                         channel: IO.Channel;
                                         ops: SET;
                                         attachment: Object.Object): IO.SelectionKey;
PROCEDURE (s: Selector) RemoveSelectionKey* (k: IO.SelectionKey);
PROCEDURE (s: Selector) Close*();
PROCEDURE (s: Selector) Select*(sec, usec: LONGINT): LONGINT RAISES IO.Error;
PROCEDURE (s: Selector) NextKey*(): SelectionKey;

END IO:Select.
