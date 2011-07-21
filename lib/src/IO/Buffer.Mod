(*	$Id: Buffer.Mod,v 1.5 2004/11/21 20:31:44 mva Exp $	*)
MODULE IO:Buffer;
(*  Generic buffering channel.
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

IMPORT
  SYSTEM, Ascii, Object, ADT:StringBuffer, IO;

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
    buffer: ARRAY sizeBuffer OF CHAR;
  END;

PROCEDURE (ch: Channel) INIT*(base: IO.ByteChannel);
  BEGIN
    ch.INIT^();
    ch.base := base;
    ch.reading := TRUE;
    ch.pos := 0;
    ch.endOfBuffer := 0;
  END INIT;

PROCEDURE Open*(base: IO.ByteChannel): Channel;
  BEGIN
    RETURN NEW(Channel, base);
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

PROCEDURE (ch: Channel) SetPos*(pos: LONGINT) RAISES IO.Error;
  BEGIN
    ch.Flush();
    ch.base.SetPos(pos);
  END SetPos;

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

PROCEDURE (ch: Channel) ReadLineLF*(): Object.String8
RAISES IO.Error;
(**Read one entire line from the channel.  The line after the first line-feed
   character (@oconst{Ascii.lf}; that is, a trailing line-feed is kept in the
   string.  If the channel ends with an incomplete line, then the line-feed
   character is absent from the last line.  @code{NIL} is returned after the
   last line of the channel has been read.

   Note: The returned string contains null characters (@samp{0X}) if they
   occurred in the input.  *)
  VAR
    i, d: LONGINT;
    sb: StringBuffer.StringBuffer;
    str: STRING;
    str8: Object.String8;
  BEGIN
    IF ~ch.reading THEN
      ch.Flush();
    END;

    i := ch.pos;
    WHILE (i # ch.endOfBuffer) DO
      IF (ch.buffer[i] = Ascii.lf) THEN  (* found complete line in buffer *)
        str8 := Object.NewLatin1Region(ch.buffer, ch.pos, i+1);
        ch.pos := i+1;
        RETURN str8;
      END;
      INC(i);
    END;

    (* add text fragments to string buffer until a whole line is assembled,
       or until the end of the file has been reached *)
    sb := StringBuffer.NewLatin1Region(ch.buffer, ch.pos, ch.endOfBuffer);
    LOOP
      d := ch.base.Read(ch.buffer, 0, sizeBuffer);
      IF (d < 0) THEN                    (* end of file *)
        IF (sb.length = 0) THEN
          RETURN NIL;                    (* ch.pos = ch.endOfBuffer *)
        ELSE                             (* incomplete line *)
          ch.pos := 0;
          ch.endOfBuffer := 0;
          EXIT;
        END;
      ELSE
        i := 0;
        WHILE (i # d) & (ch.buffer[i] # Ascii.lf) DO
          INC(i);
        END;
        IF (i = d) THEN                  (* no end of line in buffer *)
          sb.AppendLatin1Region(ch.buffer, 0, d);
        ELSE                             (* line ends with buffer[i] *)
          sb.AppendLatin1Region(ch.buffer, 0, i+1);
          ch.pos := i+1;
          ch.endOfBuffer := d;
          EXIT;
        END;
      END;
    END;
    str := sb.ToString();
    RETURN str(Object.String8);
  END ReadLineLF;

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

PROCEDURE (ch: Channel) CloseAndRegister*() RAISES IO.Error;
  BEGIN
    ch.Flush();
    ch.base.CloseAndRegister();
  END CloseAndRegister;

END IO:Buffer.
