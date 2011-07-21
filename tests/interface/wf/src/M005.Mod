MODULE M005 [OOC_EXTENSIONS];

TYPE
  Channel* = POINTER TO ChannelDesc;
  ChannelDesc* = RECORD [ABSTRACT]
  (**This is a class type.  *)
    f-: CHAR;
    (**This is a read-only field.  *)
  END;

PROCEDURE (ch: Channel) P*;
(**This is a type-bound procedure.  *)
  END P;

PROCEDURE New*(): Channel;
(**This is a constructor function.  *)
  END New;
  
PROCEDURE Init*(ch: Channel);
(** This is an initialization procedure.  *)
  END Init;
  
END M005.
