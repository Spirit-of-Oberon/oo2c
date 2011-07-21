(*	$Id: StdChannels.Mod,v 1.2 2004/11/21 20:31:44 mva Exp $	*)
MODULE IO:StdChannels [FOREIGN "C"; LINK FILE "StdChannels.c" END];
(*  Provides standard channels stdin, stdout, and stderr.
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
<*Warnings:=FALSE*>

IMPORT
  SYSTEM, RT0, Object, Exception, IO;
  
TYPE
  Channel* = POINTER TO ChannelDesc;
  ChannelList = ARRAY OF Channel;
  ChannelDesc = RECORD
    (IO.ByteChannelDesc)
    fd: IO.FileDescriptor;
  END;

VAR
  stdin-, stdout-, stderr-: IO.ByteChannel;
  
PROCEDURE (ch: Channel) INIT*(fd: IO.FileDescriptor);

PROCEDURE (ch: Channel) Read*(VAR buffer: ARRAY OF SYSTEM.BYTE;
                              start, length: LONGINT): LONGINT
  RAISES IO.Error;
  
PROCEDURE (ch: Channel) Write*(buffer[NO_COPY]: ARRAY OF SYSTEM.BYTE;
                               start, length: LONGINT): LONGINT
  RAISES IO.Error;
  
PROCEDURE (ch: Channel) SetBlocking*(block: BOOLEAN) RAISES IO.Error;
PROCEDURE (ch: Channel) FileDescriptor*(): IO.FileDescriptor;

PROCEDURE IOError* [NO_RETURN](suffix: STRING) RAISES IO.Error;

END IO:StdChannels.
