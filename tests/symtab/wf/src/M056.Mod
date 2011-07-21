MODULE M056 [OOC_EXTENSIONS];

IMPORT M055;

TYPE
  Channel* = POINTER TO ChannelDesc;
  ChannelDesc* = RECORD [ABSTRACT]
  END;

PROCEDURE (ch: Channel) [ABSTRACT] GetModTime* (VAR mtime: M055.TimeStamp);
  END GetModTime;
  
END M056.
