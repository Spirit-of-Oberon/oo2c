(*	$Id: BinaryRider.Mod,v 1.5 2003/05/31 16:51:54 mva Exp $	*)
MODULE IO:BinaryRider;

(*
    BinaryRider - Binary-level input/output of Oberon variables.       
    Copyright (C) 1998, 1999, 2002, 2003  Michael van Acken
    Copyright (C) 1997  Michael Griebling
 
    This module is free software; you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as 
    published by the Free Software Foundation; either version 2 of the
    License, or (at your option) any later version.
 
    This module is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.
 
    You should have received a copy of the GNU Lesser General Public
    License along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

*)

IMPORT
  SYSTEM, Strings, Object, IO;

CONST
  (* possible endian settings *)
  nativeEndian* = 0;    (**Do whatever the host machine uses.  *)
  littleEndian* = 1;    (**Read/write least significant byte first.  *)
  bigEndian*    = 2;    (**Read/write most significant byte first.  *)

TYPE
  Reader* = POINTER TO ReaderDesc;
  ReaderDesc* = RECORD
    byteOrder-: SHORTINT;
    (**Endian settings for the reader.  *)
    channel-: IO.ByteChannel;
    (**The channel on which this reader is operating.  *)
  END;

  Writer* = POINTER TO WriterDesc;
  WriterDesc* = RECORD
    byteOrder-: SHORTINT;
    (**Endian settings for the writer.  *)
    channel-: IO.ByteChannel;
    (**The channel on which this writer is operating.  *)
  END;
 
VAR
  systemByteOrder: SHORTINT;         (* default CPU endian setting *)


(* Reader methods 
   ------------------------------------------------------------------------ *)

(*PROCEDURE (r: Reader) Pos* () : LONGINT;
  BEGIN
    RETURN r.byteReader.Pos() 
  END Pos;*)

PROCEDURE (r: Reader) SetPos* (newPos: LONGINT) RAISES IO.Error;
  BEGIN
    r.channel.SetPos(newPos);
  END SetPos;
  
PROCEDURE (r: Reader) ReadBytes * (VAR x: ARRAY OF SYSTEM.BYTE;
                                   start, n: LONGINT)
RAISES IO.Error;
(**Read the bytes according to the native machine byte order.  *)
  BEGIN
    IF (r.channel.Read(x, start, n) # n) THEN
      IO.RaiseFormatError("Short file");
    END;
  END ReadBytes;

PROCEDURE (r: Reader) ReadBytesOrdered (VAR x: ARRAY OF SYSTEM.BYTE)
RAISES IO.Error;
(* Read the bytes according to the Reader byte order setting. *)
  VAR
    i, d: LONGINT;
  BEGIN
    IF (r.byteOrder=nativeEndian) OR (r.byteOrder=systemByteOrder) THEN
      d := r.channel.Read(x, 0, LEN(x));
      IF (d # LEN(x)) THEN
        IO.RaiseFormatError("Short file");
      END;
    ELSE  (* swap bytes of value *)
      FOR i:=LEN(x)-1 TO 0 BY -1 DO
        IF (r.channel.Read(x[i], 0, 1) # 1) THEN
          IO.RaiseFormatError("Short file");
        END;
      END;
    END
  END ReadBytesOrdered;

PROCEDURE (r: Reader) ReadBool*(VAR bool: BOOLEAN)
RAISES IO.Error;
  VAR
    byte: SHORTINT;
  BEGIN
    IF (r.channel.Read(byte, 0, 1) # 1) THEN
      IO.RaiseFormatError("Short file");
    ELSIF (byte # 0) & (byte # 1) THEN
      IO.RaiseFormatError("Value out of range");
    END;
    bool := (byte # 0);
  END ReadBool;
  
PROCEDURE (r: Reader) ReadChar* (VAR ch: CHAR)
RAISES IO.Error;
  BEGIN
    IF (r.channel.Read(ch, 0, 1) # 1) THEN
      IO.RaiseFormatError("Short file");
    END;
  END ReadChar;

PROCEDURE (r: Reader) ReadLChar*(VAR ch: LONGCHAR)
RAISES IO.Error;
  BEGIN
    r. ReadBytesOrdered (ch);
  END ReadLChar;

PROCEDURE (r: Reader) ReadString* (VAR s: ARRAY OF CHAR)
RAISES IO.Error;
(**The string @oparam{s} is filled until @samp{0X} is encountered, there are no
   more characters in the channel, or the string is filled. @oparam{s} is
   always terminated with @samp{0X}.  *)
  VAR
    cnt, len: INTEGER;
  BEGIN
    len:=SHORT(LEN(s)-1); cnt:=-1;
    REPEAT
      INC(cnt); r.ReadChar(s[cnt])
    UNTIL (s[cnt]=0X) OR (cnt=len);
    IF (s[cnt] # 0X) THEN
      IO.RaiseFormatError("String not terminated");
    END;
  END ReadString;  

PROCEDURE (r: Reader) ReadLString* (VAR s: ARRAY OF LONGCHAR)
RAISES IO.Error;
(**The string @oparam{s} is filled until @samp{0X} is encountered, there are no
   more characters in the channel, or the string is filled. @oparam{s} is
   always terminated with @samp{0X}.  *)
  VAR
    cnt, len: INTEGER;
  BEGIN
    len:=SHORT(LEN(s)-1); cnt:=-1;
    REPEAT
      INC(cnt); r.ReadLChar(s[cnt])
    UNTIL (s[cnt]=0X) OR (cnt=len);
    IF (s[cnt] # 0X) THEN
      IO.RaiseFormatError("String not terminated");
    END;
  END ReadLString;  

PROCEDURE (r: Reader) ReadSInt*(VAR sint: SHORTINT)
RAISES IO.Error;
  BEGIN
    r.ReadBytesOrdered(sint);
  END ReadSInt;

PROCEDURE (r: Reader) ReadInt*(VAR int: INTEGER)
RAISES IO.Error;
  BEGIN
    r.ReadBytesOrdered(int);
  END ReadInt;

PROCEDURE (r: Reader) ReadLInt*(VAR lint: LONGINT)
RAISES IO.Error;
(* see ReadInt *)
  BEGIN
    r.ReadBytesOrdered(lint);
  END ReadLInt;

PROCEDURE (r: Reader) ReadNum*(VAR num: LONGINT)
RAISES IO.Error;
(* Read integers in a compressed and portable format. *)
  VAR s: SHORTINT; x: CHAR; y: LONGINT;
  BEGIN
    s:=0; y:=0; r.ReadChar(x);
    WHILE (s < 28) & (x >= 80X) DO
      INC(y, ASH(LONG(ORD(x))-128, s)); INC(s, 7); 
      r.ReadChar(x)
    END;
    (* Q: (s = 28) OR (x < 80X) *)
    IF (x >= 80X) OR  (* with s=28 this means we have more than 5 digits *)
       (s = 28) & (8X <= x) & (x < 78X) THEN   (* overflow in most sig byte *)
      IO.RaiseFormatError("Overflow");
    ELSE
      num:=ASH(SYSTEM.LSH(LONG(ORD(x)), 25), s-25)+y;
    END
  END ReadNum;

PROCEDURE (r: Reader) ReadReal*(VAR real: REAL)
RAISES IO.Error;
(* see ReadInt *)
  BEGIN    
    r.ReadBytesOrdered(real);
  END ReadReal;

PROCEDURE (r: Reader) ReadLReal*(VAR lreal: LONGREAL)
RAISES IO.Error;
(* see ReadInt *)
  BEGIN
    r.ReadBytesOrdered(lreal);
  END ReadLReal;
 
PROCEDURE (r: Reader) ReadSet*(VAR s: SET)
RAISES IO.Error;
  BEGIN
    r.ReadBytesOrdered(s);
  END ReadSet;

PROCEDURE (r: Reader) ReadStr* (VAR s: Object.String)
RAISES IO.Error;
  CONST
    sizeBuffer8 = 1024;
    sizeBuffer16 = 512;
  VAR
    len, x: LONGINT;
    buffer8: ARRAY sizeBuffer8 OF CHAR;
    dynBuffer8: POINTER TO ARRAY OF CHAR;
    buffer16: ARRAY sizeBuffer16 OF LONGCHAR;
    dynBuffer16: POINTER TO ARRAY OF LONGCHAR;
    i: LONGINT;
  BEGIN
    r.ReadNum(len);
    IF (len = 0) THEN
      s := NIL;
      
    ELSIF (len > 0) THEN
      DEC(len);
      IF (len < sizeBuffer8) THEN
        r.ReadBytes(buffer8, 0, len);
        s := Object.NewLatin1Region(buffer8, 0, len);
      ELSE
        NEW(dynBuffer8, len);
        r.ReadBytes(dynBuffer8^, 0, len);
        s := Object.NewLatin1Region(dynBuffer8^, 0, len);
      END;
      
    ELSE  (* this is quite slow; FIXME... use the UTF8 codec instead *)
      len := -len-1;
      IF (len < sizeBuffer16) THEN
        FOR i := 0 TO len-1 DO
          r.ReadNum(x);
          buffer16[i] := LONGCHR(x);
        END;
        s := Object.NewUTF16Region(buffer16, 0, len);
      ELSE
        NEW(dynBuffer16, len);
        FOR i := 0 TO len-1 DO
          r.ReadNum(x);
          buffer16[i] := LONGCHR(x);
        END;
        s := Object.NewUTF16Region(dynBuffer16^, 0, len);
      END;
    END;
  END ReadStr;

PROCEDURE (r: Reader) SetByteOrder* (order: SHORTINT);
  BEGIN
    ASSERT((order>=nativeEndian) & (order<=bigEndian));
    r.byteOrder:=order
  END SetByteOrder;

(* Writer methods 
   ------------------------------------------------------------------------ *)

(* The Write-methods write the value to the underlying channel. It is 
   possible that only part of the value is written
 *)

(*PROCEDURE (w: Writer) Pos* () : LONGINT;
  BEGIN
    RETURN w.byteWriter.Pos()
  END Pos;*)

PROCEDURE (w: Writer) SetPos* (newPos: LONGINT) RAISES IO.Error;
  BEGIN
    w.channel.SetPos(newPos);
  END SetPos;

PROCEDURE (w: Writer) WriteBytes * (x[NO_COPY]: ARRAY OF SYSTEM.BYTE;
                                    start, n: LONGINT)
RAISES IO.Error;
(* Write the bytes according to the native machine byte order. *)
  VAR
    d: LONGINT;
  BEGIN
    d := w.channel.Write(x, start, n);
  END WriteBytes;

PROCEDURE (w: Writer) WriteOrdered (VAR x: ARRAY OF SYSTEM.BYTE)
RAISES IO.Error;
(* Write the bytes according to the Writer byte order setting. *)
  VAR
    i, d: LONGINT;
  BEGIN
    IF (w.byteOrder=nativeEndian) OR (w.byteOrder=systemByteOrder) THEN
      d := w.channel.Write(x, 0, LEN(x)) 
    ELSE
      FOR i:=LEN(x)-1 TO 0 BY -1 DO d := w.channel.Write(x[i], 0, 1) END  
    END;
  END WriteOrdered;

PROCEDURE (w: Writer) WriteChar*(ch: CHAR)
RAISES IO.Error;
  VAR
    d: LONGINT;
  BEGIN
    d := w. channel. Write(ch, 0, 1);
  END WriteChar;
  
PROCEDURE (w: Writer) WriteBool*(bool: BOOLEAN)
RAISES IO.Error;
  BEGIN
    IF bool THEN
      w. WriteChar (1X)
    ELSE
      w. WriteChar (0X)
    END;
  END WriteBool;
  
PROCEDURE (w: Writer) WriteLChar*(ch: LONGCHAR)
RAISES IO.Error;
  BEGIN
    w. WriteOrdered (ch);
  END WriteLChar;

PROCEDURE (w: Writer) WriteString*(s[NO_COPY]: ARRAY OF CHAR)
RAISES IO.Error;
(**Note: The terminating @samp{0X} is also written.  *)
  VAR
    d: LONGINT;
  BEGIN
    d := w.channel.Write (s, 0, Strings.Length (s)+1);
  END WriteString;

PROCEDURE (w: Writer) WriteLString*(s[NO_COPY]: ARRAY OF LONGCHAR)
RAISES IO.Error;
(**The terminating @samp{0X} is also written.  *)
  VAR
    i: LONGINT;
  BEGIN
    i := -1;
    REPEAT
      INC (i);
      w. WriteLChar (s[i])
    UNTIL (s[i] = 0X);
  END WriteLString;

PROCEDURE (w: Writer) WriteSInt*(sint: SHORTINT)
RAISES IO.Error;
  VAR
    d: LONGINT;
  BEGIN
    d := w.channel.Write(sint, 0, 1);
  END WriteSInt;

PROCEDURE (w: Writer) WriteInt*(int: INTEGER)
RAISES IO.Error;
  BEGIN
    w.WriteOrdered(int);
  END WriteInt;

PROCEDURE (w: Writer) WriteLInt*(lint: LONGINT)
RAISES IO.Error;
(* see WriteInt *)
  BEGIN
    w.WriteOrdered(lint);
  END WriteLInt;

PROCEDURE (w: Writer) WriteNum*(lint: LONGINT)
RAISES IO.Error;
(**Write integers in a compressed and portable format.  *)
  BEGIN
    WHILE (lint<-64) OR (lint>63) DO
      w.WriteChar(CHR(lint MOD 128+128));
      lint:=lint DIV 128
    END;
    w.WriteChar(CHR(lint MOD 128));
  END WriteNum;

(* see WriteInt *)
PROCEDURE (w: Writer) WriteReal*(real: REAL)
RAISES IO.Error;
  BEGIN
    w.WriteOrdered(real);
  END WriteReal;

PROCEDURE (w: Writer) WriteLReal*(lreal: LONGREAL)
RAISES IO.Error;
(* see WriteInt *)
  BEGIN
    w.WriteOrdered(lreal);
  END WriteLReal;

PROCEDURE (w: Writer) WriteSet*(s: SET)
RAISES IO.Error;
  BEGIN
    w.WriteOrdered(s);
  END WriteSet;

PROCEDURE (w: Writer) WriteStr*(s: Object.String)
RAISES IO.Error;
  VAR
    chars8: Object.CharsLatin1;
    chars16: Object.CharsUTF16;
    i, d: LONGINT;
  BEGIN
    IF (s = NIL) THEN
      w.WriteNum(0);
    ELSE
      WITH s: Object.String8 DO
        w.WriteNum(s.length+1);
        chars8 := s.CharsLatin1();
        d := w.channel.Write(chars8^, 0, s.length);
        
      | s: Object.String16 DO            (* FIXME... use UTF8 codec *)
        w.WriteNum(-s.length-1);
        chars16 := s.CharsUTF16();
        FOR i := 0 TO s.length-1 DO
          w.WriteNum(ORD(chars16[i]));
        END;
      END;
    END;
  END WriteStr;

PROCEDURE (w: Writer) SetByteOrder* (order: SHORTINT);
  BEGIN
    ASSERT((order>=nativeEndian) & (order<=bigEndian));
    w.byteOrder:=order
  END SetByteOrder;

(* Reader Procedures
   ------------------------------------------------------------------------ *)

(* Create a new Reader and attach it to the Channel ch. NIL is 
   returned when it is not possible to read from the channel.
   The Reader is positioned at the beginning for positionable 
   channels and at the current position for non-positionable channels.
 *)

PROCEDURE InitReader* (r: Reader; ch: IO.ByteChannel; byteOrder: SHORTINT);
  BEGIN
    r. byteOrder := byteOrder;
    r. channel := ch;
  END InitReader;

PROCEDURE ConnectReader*(ch: IO.ByteChannel): Reader;
(**@precond
   @oparam{ch} is in blocking mode.
   @end precond *)
  VAR
    r: Reader;
  BEGIN
    NEW (r);
    InitReader (r, ch, littleEndian);
    RETURN r
  END ConnectReader;
  
(* Writer Procedures
   ------------------------------------------------------------------------ *)

(* Create a new Writer and attach it to the Channel ch. NIL is 
   returned when it is not possible to write to the channel.
   The Writer is positioned at the beginning for positionable 
   channels and at the current position for non-positionable channels.
 *)
PROCEDURE InitWriter* (w: Writer; ch: IO.ByteChannel; byteOrder: SHORTINT);
  BEGIN
    w.byteOrder := byteOrder;
    w.channel := ch;
  END InitWriter;

PROCEDURE ConnectWriter*(ch: IO.ByteChannel): Writer;
(**@precond
   @oparam{ch} is in blocking mode.
   @end precond *)
  VAR
    w: Writer;
  BEGIN
    NEW (w);
    InitWriter (w, ch, littleEndian);
    RETURN w;
  END ConnectWriter;

PROCEDURE SetDefaultByteOrder(VAR x: ARRAY OF SYSTEM.BYTE);
  BEGIN
    IF SYSTEM.VAL(CHAR, x[0])=1X THEN
      systemByteOrder:=littleEndian
    ELSE
      systemByteOrder:=bigEndian
    END
  END SetDefaultByteOrder;

PROCEDURE Init;
  VAR i: INTEGER;
  BEGIN
    i:=1; SetDefaultByteOrder(i)
  END Init;

BEGIN
  Init;
END IO:BinaryRider.
