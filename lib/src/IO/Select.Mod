MODULE IO:Select [FOREIGN "C"; LINK FILE "Select.c" END];
<* Warnings := FALSE *>

IMPORT
  SYSTEM, Object, IO, IO:PFD;

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

PROCEDURE Init*(s: Selector);
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
