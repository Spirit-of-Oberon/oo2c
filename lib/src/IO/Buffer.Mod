(*	$Id$	*)
MODULE IO:Buffer;
(*  Generic buffering channel.
    Copyright (C) 2003  Michael van Acken

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

IMPORT
  SYSTEM, IO;

CONST
  sizeBuffer = 8*1024;
  sizeDirect = sizeBuffer DIV 2;
  (* If the data is not present in the buffer, and its size exceeds this number
     of bytes, them it is not copied into the buffer, but rather read or
     written directly.  *)
  
TYPE
  Channel* = POINTER TO ChannelDesc;
  ChannelDesc = RECORD
    (IO.ByteChannelDesc)
    base-: IO.ByteChannel;
    reading: BOOLEAN;
    pos, endOfBuffer: LONGINT;
    buffer: ARRAY sizeBuffer OF SYSTEM.BYTE;
  END;

PROCEDURE Init(ch: Channel; base: IO.ByteChannel);
  BEGIN
    IO.InitByteChannel(ch);
    ch.base := base;
    ch.reading := TRUE;
    ch.pos := 0;
    ch.endOfBuffer := 0;
  END Init;

PROCEDURE Open*(base: IO.ByteChannel): Channel;
  VAR
    ch: Channel;
  BEGIN
    NEW(ch);
    Init(ch, base);
    RETURN ch;
  END Open;

PROCEDURE (ch: Channel) Flush*() RAISES IO.Error;
  VAR
    d: LONGINT;
  BEGIN
    IF (ch.pos # ch.endOfBuffer) THEN
      IF ch.reading THEN
        ch.pos := 0;
        ch.endOfBuffer := 0;
      ELSE
        ASSERT(ch.pos = 0);
        d := ch.base.Write(ch.buffer, 0, ch.endOfBuffer);
        ASSERT(d = ch.endOfBuffer);
        ch.endOfBuffer := 0;
      END;
      ch.base.Flush();
    END;
  END Flush;

PROCEDURE (ch: Channel) SetPosition*(pos: LONGINT) RAISES IO.Error;
  BEGIN
    ch.Flush();
    ch.base.SetPosition(pos);
  END SetPosition;

PROCEDURE (ch: Channel) Read*(VAR buffer: ARRAY OF SYSTEM.BYTE;
                              start, length: LONGINT): LONGINT
RAISES IO.Error;
  VAR
    i, d: LONGINT;
  BEGIN
    IF ch.reading THEN
      i := ch.endOfBuffer-ch.pos;
      ASSERT(i >= 0);
      IF (i >= length) THEN      (* fast path: can serve request from buffer *)
        SYSTEM.MOVE(SYSTEM.ADR(ch.buffer)+ch.pos,
                    SYSTEM.ADR(buffer)+start,
                    length);
        INC(ch.pos, length);
        RETURN length;
      ELSE                           (* data only in part in buffer *)
        SYSTEM.MOVE(SYSTEM.ADR(ch.buffer)+ch.pos,
                    SYSTEM.ADR(buffer)+start,
                    i);
        INC(ch.pos, i);
        INC(start, i);
        DEC(length, i);
      END;
    ELSE                                 (* no input data in buffer *)
      ch.Flush();
      i := 0;
    END;
    (* here holds: `i' is the number of bytes already transferred *)
    
    IF (length # 0) THEN
      ASSERT(ch.pos = ch.endOfBuffer);
      IF (length >= sizeDirect) THEN
        d := ch.base.Read(buffer, start, length);
        IF (d < 0) THEN                  (* end of file *)
          IF (i > 0) THEN
            RETURN i;
          ELSE
            RETURN d;
          END;
        ELSE
          RETURN d+i;
        END;
      ELSE
        d := ch.base.Read(ch.buffer, 0, sizeBuffer);
        ch.reading := TRUE;
        ch.pos := 0;
        IF (d < 0) THEN                  (* end of file *)
          ch.endOfBuffer := 0;
          IF (i > 0) THEN
            RETURN i;
          ELSE
            RETURN -1;
          END;
        ELSE                             (* data was added to buffer *)
          ch.endOfBuffer := d;
          RETURN i+ch.Read(buffer, start, length);
        END;
      END;
    ELSE
      RETURN i;
    END;
  END Read;

PROCEDURE (ch: Channel) Write*(buffer[NO_COPY]: ARRAY OF SYSTEM.BYTE;
                               start, length: LONGINT): LONGINT
RAISES IO.Error;
  BEGIN
    IF ch.reading THEN
      ch.Flush();
      ch.reading := FALSE;
    END;
    
    IF (ch.endOfBuffer+length <= sizeBuffer) THEN (* fits into buffer *)
      SYSTEM.MOVE(SYSTEM.ADR(buffer)+start,
                  SYSTEM.ADR(ch.buffer)+ch.endOfBuffer, length);
      INC(ch.endOfBuffer, length);
      RETURN length;
    ELSE
      ch.Flush();                        (* flush buffer *)
      IF (length >= sizeDirect) THEN     (* too large, write directly *)
        RETURN ch.base.Write(buffer, start, length);
      ELSE                               (* write data into empty buffer *)
        RETURN ch.Write(buffer, start, length);
      END;
    END;
  END Write;

PROCEDURE (ch: Channel) SetBlocking*(block: BOOLEAN) RAISES IO.Error;
  BEGIN
    ch.base.SetBlocking(block);
  END SetBlocking;

PROCEDURE (ch: Channel) FileDescriptor*(): IO.FileDescriptor;
  BEGIN
    RETURN -1;
  END FileDescriptor;

PROCEDURE (ch: Channel) Close*() RAISES IO.Error;
  BEGIN
    ch.Flush();
    ch.base.Close();
  END Close;

END IO:Buffer.
