MODULE M057 [FOREIGN "C"; LINK FILE "PosixFileDescr.c" END];

IMPORT
  Time := M055, Ch := M056;

TYPE
  Channel* = POINTER TO ChannelDesc;
  ChannelDesc* = RECORD
    (Ch.ChannelDesc)
  END;
  
PROCEDURE (ch: Channel) GetModTime* (VAR mtime: Time.TimeStamp);
(* Retrieves the modification time of the data accessed by the given channel.
   If no such information is avaiblable, `ch.res' is set to `noModTime', 
   otherwise to `done'.  *)

END M057.
