(*	$Id: Memory.Mod,v 1.6 2003/06/23 20:54:40 mva Exp $	*)
MODULE IO:Memory;
(*  Memory backed byte channel.
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

TYPE
  Data = POINTER TO ARRAY [READ_ONLY] OF CHAR;
  Channel* = POINTER TO ChannelDesc;
  ChannelDesc = RECORD
    (IO.ByteChannelDesc)
    pos: LONGINT;
    length-: LONGINT;
    data-: Data;
  END;

CONST
  offset = 16;
  
PROCEDURE Init(ch: Channel);
  BEGIN
    IO.InitByteChannel(ch);
    NEW(ch.data, 4*1024-offset);
    ch.pos := 0;
    ch.length := 0;
  END Init;

PROCEDURE Open*(): Channel;
  VAR
    ch: Channel;
  BEGIN
    NEW(ch);
    Init(ch);
    RETURN ch;
  END Open;

PROCEDURE (ch: Channel) SetBlocking*(block: BOOLEAN);
  BEGIN
  END SetBlocking;

PROCEDURE (ch: Channel) FileDescriptor*(): IO.FileDescriptor;
  BEGIN
    RETURN -1;
  END FileDescriptor;

PROCEDURE (ch: Channel) SetPos*(pos: LONGINT);
(**@precond
   @samp{0 <= pos <= ch.length}
   @end precond *)
  BEGIN
    ch.pos := pos;
  END SetPos;

PROCEDURE (ch: Channel) Read*(VAR buffer: ARRAY OF SYSTEM.BYTE;
                              start, length: LONGINT): LONGINT;
  BEGIN
    IF (ch.pos+length <= ch.length) THEN (* can read all `length' bytes *)
      SYSTEM.MOVE(SYSTEM.ADR(ch.data^)+ch.pos,
                  SYSTEM.ADR(buffer)+start,
                  length);
      INC(ch.pos, length);
      RETURN length;
    ELSIF (ch.pos = ch.length) THEN      (* end of file *)
      RETURN -1;
    ELSE                                 (* partial answer *)
      length := ch.length-ch.pos;
      SYSTEM.MOVE(SYSTEM.ADR(ch.data^)+ch.pos,
                  SYSTEM.ADR(buffer)+start,
                  length);
      INC(ch.pos, length);
      RETURN length;
    END;
  END Read;

PROCEDURE (ch: Channel) Write*(buffer[NO_COPY]: ARRAY OF SYSTEM.BYTE;
                               start, length: LONGINT): LONGINT;
  VAR
    i: LONGINT;
    n: Data;
  BEGIN
    IF (ch.pos+length > LEN(ch.data^)) THEN
      i := LEN(ch.data^);
      REPEAT
        i := i*2+offset;
      UNTIL (i >= ch.pos+length);
      NEW(n, i);
      SYSTEM.MOVE(SYSTEM.ADR(ch.data^), SYSTEM.ADR(n^), LEN(ch.data^));
      ch.data := n;
    END;
    
    SYSTEM.MOVE(SYSTEM.ADR(buffer)+start,
                SYSTEM.ADR(ch.data^)+ch.pos,
                length);
    INC(ch.pos, length);
    IF (ch.pos > ch.length) THEN
      ch.length := ch.pos;
    END;
    RETURN length;
  END Write;

PROCEDURE (ch: Channel) Truncate*(newLength: LONGINT);
(**@precond
   @samp{0 <= newLength <= ch.length}
   @end precond *)
  BEGIN
    ch.length := newLength;
  END Truncate;

PROCEDURE (ch: Channel) Fingerprint* (VAR key: ARRAY OF SYSTEM.BYTE;
                                      start, end: LONGINT);
(**Generates fingerprint value over the data of @oparam{ch}, over the byte
   range @samp{[start..end[}.  The argument passed to @oparam{key} must be a
   @code{LONGINT} variable.  To fingerprint the whole file, use a
   @oparam{start} value of @samp{0} and an @oparam{end} of
   @samp{ch.file.length}.
   
   See @cite{Structured Programming(1993) 14: 136-147}.
   
   @precond
   @samp{LEN(key) = fpSize}
   @end precond *)
  CONST
    fpSize = SIZE(LONGINT);
  VAR
    pos: LONGINT;
    i, j, new, old: INTEGER;
    byte: CHAR;
  BEGIN
    FOR i := 0 TO fpSize-1 DO
      key[i] := 0
    END;
    i := 0; j := 0;
    (* calculate fp *)
    FOR pos := start TO end-1 DO
      byte := SYSTEM.VAL (CHAR, ch. data[pos]);
      old := ORD (SYSTEM.VAL (CHAR, key[i]));
      new := ORD (SYSTEM.VAL (CHAR, SYSTEM.ROT (byte, j)));
      key[i] := CHR ((old+new) MOD 256);
      INC (i); 
      IF (i = fpSize) THEN
        j := (j + 1) MOD 8; i := 0
      END
    END
  END Fingerprint;

END IO:Memory.
