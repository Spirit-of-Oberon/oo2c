MODULE IO:PFD [FOREIGN "C"; LINK FILE "PFD.c" END];
<*Warnings:=FALSE*>

IMPORT
  SYSTEM, RT0, Object, Exception, IO;
  
TYPE
  Channel* = POINTER TO ChannelDesc;
  ChannelList = ARRAY OF Channel;
  ChannelDesc = RECORD
    (**Note: Unlikes @otype{*Files.File}, this class does not do any buffering
       by itself.  *)
    (IO.ByteChannelDesc)
    fd: IO.FileDescriptor;
  END;

VAR
  stdin-, stdout-, stderr-: Channel;
  
PROCEDURE Init*(ch: Channel; fd: IO.FileDescriptor);

PROCEDURE (ch: Channel) Read*(VAR buffer: ARRAY OF SYSTEM.BYTE;
                              start, length: LONGINT): LONGINT
  RAISES IO.Error;
  
PROCEDURE (ch: Channel) Write*(buffer[NO_COPY]: ARRAY OF SYSTEM.BYTE;
                               start, length: LONGINT): LONGINT
  RAISES IO.Error;
  
PROCEDURE (ch: Channel) SetBlocking*(block: BOOLEAN) RAISES IO.Error;
PROCEDURE (ch: Channel) FileDescriptor*(): IO.FileDescriptor;

PROCEDURE IOError* [NO_RETURN](suffix: STRING) RAISES IO.Error;

END IO:PFD.
