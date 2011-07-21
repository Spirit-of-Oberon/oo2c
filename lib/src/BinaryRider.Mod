(*	$Id: BinaryRider.Mod,v 1.8 2003/05/31 16:51:55 mva Exp $	*)
MODULE BinaryRider [OOC_EXTENSIONS];

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
  Strings, Channel, Object, SYSTEM, Msg;

CONST
  (* result codes *)
  done* = Channel.done;
  invalidFormat* = Channel.invalidFormat;
  readAfterEnd* = Channel.readAfterEnd;
  
  (* possible endian settings *)
  nativeEndian* = 0;    (**Do whatever the host machine uses.  *)
  littleEndian* = 1;    (**Read/write least significant byte first.  *)
  bigEndian*    = 2;    (**Read/write most significant byte first.  *)

TYPE
  Reader* = POINTER TO ReaderDesc;
  ReaderDesc* = RECORD
    res*: Msg.Msg;       (* READ-ONLY *)
    byteOrder-: SHORTINT;
    (**Endian settings for the reader.  *)
    byteReader-: Channel.Reader;  (* only to be used by extensions of Reader *)
    (**Binary reader underneath this text reader.  This field should only
       be used by extensions of this type.  *)
    base-: Channel.Channel;
    (**The channel on which this reader is operating.  *)
  END;

  Writer* = POINTER TO WriterDesc;
  WriterDesc* = RECORD
    res*: Msg.Msg;       (* READ-ONLY *)
    byteOrder-: SHORTINT;
    (**Endian settings for the writer.  *)
    byteWriter-: Channel.Writer;
    (**Binary writer underneath this text writer.  This field should only
       be used by extensions of this type.  *)
    base-: Channel.Channel;
    (**The channel on which this writer is operating.  *)
  END;
 
VAR
  systemByteOrder: SHORTINT;         (* default CPU endian setting *)


TYPE
  ErrorContext = POINTER TO ErrorContextDesc;
  ErrorContextDesc* = RECORD
    (**This record is exported, so that extensions of Channel can access the
       error descriptions by extending @otype{ErrorContextDesc}.  *)
    (Channel.ErrorContextDesc)
  END;

VAR
  errorContext: ErrorContext;


PROCEDURE GetError (code: Msg.Code): Msg.Msg;
  BEGIN
    RETURN Msg.New (errorContext, code)
  END GetError;


(* Reader methods 
   ------------------------------------------------------------------------ *)

(* The following methods read a value of the given type from the current
   position in the BinaryReader. 
   Iff the value is invalid for its type, 'r.res' is 'invalidFormat' 
   Iff there aren't enough bytes to satisfy the request, 'r.res' is
   'readAfterEnd'.
 *)
 
PROCEDURE (r: Reader) Pos* () : LONGINT;
  BEGIN
    RETURN r.byteReader.Pos() 
  END Pos;

PROCEDURE (r: Reader) SetPos* (newPos: LONGINT);
  BEGIN
    IF (r. res = done) THEN
      r.byteReader.SetPos(newPos);
      r.res := r.byteReader.res
    END
  END SetPos;
  
PROCEDURE (r: Reader) ClearError*;
  BEGIN
    r.byteReader.ClearError;
    r.res := done
  END ClearError;

PROCEDURE (r: Reader) Available * () : LONGINT;
  BEGIN
    RETURN r.byteReader.Available()
  END Available;  

PROCEDURE (r: Reader) ReadBytes * (VAR x: ARRAY OF SYSTEM.BYTE;
                                   start, n: LONGINT);
(**Read the bytes according to the native machine byte order.  *)
  BEGIN
    IF (r.res = done) THEN
      r.byteReader.ReadBytes(x, start, n);
      r.res := r.byteReader.res
    END
  END ReadBytes;

PROCEDURE (r: Reader) ReadBytesOrdered (VAR x: ARRAY OF SYSTEM.BYTE);
(* Read the bytes according to the Reader byte order setting. *)
  VAR i: LONGINT;
  BEGIN
    IF (r.byteOrder=nativeEndian) OR (r.byteOrder=systemByteOrder) THEN
      r.byteReader.ReadBytes(x, 0, LEN(x)) 
    ELSE  (* swap bytes of value *)
      FOR i:=LEN(x)-1 TO 0 BY -1 DO r.byteReader.ReadByte(x[i]) END  
    END
  END ReadBytesOrdered;

PROCEDURE (r: Reader) ReadBool*(VAR bool: BOOLEAN);
  VAR byte: SHORTINT;
  BEGIN
    IF (r.res = done) THEN
      r. byteReader. ReadByte (byte); 
      IF (r. byteReader. res = done) & (byte # 0) & (byte # 1) THEN
        r. res := GetError (invalidFormat)
      ELSE
        r. res := r. byteReader. res
      END;
      bool := (byte # 0)
    END
  END ReadBool;
  
PROCEDURE (r: Reader) ReadChar* (VAR ch: CHAR);
  BEGIN
    IF (r.res = done) THEN
      r. byteReader.ReadByte (ch);
      r.res := r.byteReader.res
    END
  END ReadChar;

PROCEDURE (r: Reader) ReadLChar*(VAR ch: LONGCHAR);
  BEGIN
    IF (r.res = done) THEN
      r. ReadBytesOrdered (ch);
      r.res := r.byteReader.res
    END
  END ReadLChar;

PROCEDURE (r: Reader) ReadString* (VAR s: ARRAY OF CHAR);
(**The string @oparam{s} is filled until @samp{0X} is encountered, there are no
   more characters in the channel, or the string is filled. @oparam{s} is
   always terminated with @samp{0X}.  *)
  VAR
    cnt, len: INTEGER;
  BEGIN
    IF (r.res = done) THEN
      len:=SHORT(LEN(s)-1); cnt:=-1;
      REPEAT
        INC(cnt); r.ReadChar(s[cnt])
      UNTIL (s[cnt]=0X) OR (r.byteReader.res#done) OR (cnt=len);
      IF (r. byteReader. res = done) & (s[cnt] # 0X) THEN
        r.byteReader.res := GetError (invalidFormat);
        s[cnt]:=0X
      ELSE
        r.res := r.byteReader.res
      END
    END
  END ReadString;  

PROCEDURE (r: Reader) ReadLString* (VAR s: ARRAY OF LONGCHAR);
(**The string @oparam{s} is filled until @samp{0X} is encountered, there are no
   more characters in the channel, or the string is filled. @oparam{s} is
   always terminated with @samp{0X}.  *)
  VAR
    cnt, len: INTEGER;
  BEGIN
    IF (r.res = done) THEN
      len:=SHORT(LEN(s)-1); cnt:=-1;
      REPEAT
        INC(cnt); r.ReadLChar(s[cnt])
      UNTIL (s[cnt]=0X) OR (r.byteReader.res#done) OR (cnt=len);
      IF (r. byteReader. res = done) & (s[cnt] # 0X) THEN
        r.byteReader.res := GetError (invalidFormat);
        s[cnt]:=0X
      ELSE
        r.res := r.byteReader.res
      END
    END
  END ReadLString;  

PROCEDURE (r: Reader) ReadSInt*(VAR sint: SHORTINT);
  BEGIN
    IF (r.res = done) THEN
      r.byteReader.ReadByte(sint); (* SIZE(SYSTEM.BYTE) = SIZE(SHORTINT) *)  ;
      r.res := r.byteReader.res
    END
  END ReadSInt;

PROCEDURE (r: Reader) ReadInt*(VAR int: INTEGER);
  BEGIN
    IF (r.res = done) THEN
      r.ReadBytesOrdered(int);
      r.res := r.byteReader.res
     END
  END ReadInt;

PROCEDURE (r: Reader) ReadLInt*(VAR lint: LONGINT);
(* see ReadInt *)
  BEGIN
    IF (r.res = done) THEN
      r.ReadBytesOrdered(lint);
      r.res := r.byteReader.res
    END
  END ReadLInt;

PROCEDURE (r: Reader) ReadNum*(VAR num: LONGINT);
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
       (s = 28) & (8X <= x) & (x < 78X) &   (* overflow in most sig byte *)
       (r. byteReader. res = done) THEN
      r. res := GetError (invalidFormat)
    ELSE
      num:=ASH(SYSTEM.LSH(LONG(ORD(x)), 25), s-25)+y;
      r. res := r. byteReader. res
    END
  END ReadNum;

PROCEDURE (r: Reader) ReadReal*(VAR real: REAL);
(* see ReadInt *)
  BEGIN    
    IF (r.res = done) THEN
      r.ReadBytesOrdered(real);
      r.res := r.byteReader.res
    END
  END ReadReal;

PROCEDURE (r: Reader) ReadLReal*(VAR lreal: LONGREAL);
(* see ReadInt *)
  BEGIN
    IF (r.res = done) THEN
      r.ReadBytesOrdered(lreal);
      r.res := r.byteReader.res
    END
  END ReadLReal;
 
PROCEDURE (r: Reader) ReadSet*(VAR s: SET);
  BEGIN
    IF (r.res = done) THEN
      r.ReadBytesOrdered(s);
      r.res := r.byteReader.res
    END
  END ReadSet;

PROCEDURE (r: Reader) ReadStr* (VAR s: Object.String);
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
    IF (r.res = done) THEN
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

PROCEDURE (w: Writer) Pos* () : LONGINT;
  BEGIN
    RETURN w.byteWriter.Pos()
  END Pos;

PROCEDURE (w: Writer) SetPos* (newPos: LONGINT);
  BEGIN
    IF (w.res = done) THEN
      w.byteWriter.SetPos(newPos);
      w.res := w.byteWriter.res
    END
  END SetPos;

PROCEDURE (w: Writer) ClearError*;
  BEGIN
    w.byteWriter.ClearError;
    w.res := done
  END ClearError;

PROCEDURE (w: Writer) WriteBytes * (x[NO_COPY]: ARRAY OF SYSTEM.BYTE;
                                    start, n: LONGINT);
(* Write the bytes according to the native machine byte order. *)
  BEGIN
    IF (w.res = done) THEN
      w.byteWriter.WriteBytes(x, start, n);
      w.res := w.byteWriter.res
    END
  END WriteBytes;

PROCEDURE (w: Writer) WriteBytesOrdered (VAR x: ARRAY OF SYSTEM.BYTE);
(* Write the bytes according to the Writer byte order setting. *)
  VAR i: LONGINT;
  BEGIN
    IF (w.byteOrder=nativeEndian) OR (w.byteOrder=systemByteOrder) THEN
      w.byteWriter.WriteBytes(x, 0, LEN(x)) 
    ELSE
      FOR i:=LEN(x)-1 TO 0 BY -1 DO w.byteWriter.WriteByte(x[i]) END  
    END
  END WriteBytesOrdered;

PROCEDURE (w: Writer) WriteBool*(bool: BOOLEAN);
  BEGIN
    IF (w.res = done) THEN
      IF bool THEN
        w. byteWriter. WriteByte (1)
      ELSE
        w. byteWriter. WriteByte (0)
      END;
      w. res := w. byteWriter. res
    END
  END WriteBool;
  
PROCEDURE (w: Writer) WriteChar*(ch: CHAR);
  BEGIN
    IF (w.res = done) THEN
      w. byteWriter. WriteByte(ch);
      w.res := w.byteWriter.res
    END
  END WriteChar;
  
PROCEDURE (w: Writer) WriteLChar*(ch: LONGCHAR);
  BEGIN
    IF (w.res = done) THEN
      w. WriteBytesOrdered (ch);
      w.res := w.byteWriter.res
    END
  END WriteLChar;

PROCEDURE (w: Writer) WriteString*(s[NO_COPY]: ARRAY OF CHAR);
(**Note: The terminating @samp{0X} is also written.  *)
  BEGIN
    IF (w.res = done) THEN
      w.byteWriter.WriteBytes (s, 0, Strings.Length (s)+1);
      w.res := w.byteWriter.res
    END
  END WriteString;

PROCEDURE (w: Writer) WriteLString*(s[NO_COPY]: ARRAY OF LONGCHAR);
(**The terminating @samp{0X} is also written.  *)
  VAR
    i: LONGINT;
  BEGIN
    IF (w.res = done) THEN
      i := -1;
      REPEAT
        INC (i);
        w. WriteLChar (s[i])
      UNTIL (s[i] = 0X);
      w.res := w.byteWriter.res
    END
  END WriteLString;

PROCEDURE (w: Writer) WriteSInt*(sint: SHORTINT);
  BEGIN
    IF (w.res = done) THEN
      w.byteWriter.WriteByte(sint);
      w.res := w.byteWriter.res
    END
  END WriteSInt;

PROCEDURE (w: Writer) WriteInt*(int: INTEGER);
  BEGIN
    IF (w.res = done) THEN
      w.WriteBytesOrdered(int);
      w.res := w.byteWriter.res
    END
  END WriteInt;

PROCEDURE (w: Writer) WriteLInt*(lint: LONGINT);
(* see WriteInt *)
  BEGIN
    IF (w.res = done) THEN
      w.WriteBytesOrdered(lint);
      w.res := w.byteWriter.res
    END
  END WriteLInt;

PROCEDURE (w: Writer) WriteNum*(lint: LONGINT);
(**Write integers in a compressed and portable format.  *)
  BEGIN
    IF (w.res = done) THEN
      WHILE (lint<-64) OR (lint>63) DO
        w.WriteChar(CHR(lint MOD 128+128));
        lint:=lint DIV 128
      END;
      w.WriteChar(CHR(lint MOD 128));
      w.res := w.byteWriter.res
    END
  END WriteNum;

(* see WriteInt *)
PROCEDURE (w: Writer) WriteReal*(real: REAL);
  BEGIN
    IF (w.res = done) THEN
      w.WriteBytesOrdered(real);
      w.res := w.byteWriter.res
    END
  END WriteReal;

PROCEDURE (w: Writer) WriteLReal*(lreal: LONGREAL);
(* see WriteInt *)
  BEGIN
    IF (w.res = done) THEN
      w.WriteBytesOrdered(lreal);
      w.res := w.byteWriter.res
    END
  END WriteLReal;

PROCEDURE (w: Writer) WriteSet*(s: SET);
  BEGIN
    IF (w.res = done) THEN
      w.WriteBytesOrdered(s);
      w.res := w.byteWriter.res
    END
  END WriteSet;

PROCEDURE (w: Writer) WriteStr*(s: Object.String);
  VAR
    chars8: Object.CharsLatin1;
    chars16: Object.CharsUTF16;
    i: LONGINT;
  BEGIN
    IF (s = NIL) THEN
      w.WriteNum(0);
    ELSE
      WITH s: Object.String8 DO
        w.WriteNum(s.length+1);
        chars8 := s.CharsLatin1();
        w.WriteBytes(chars8^, 0, s.length);
        
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

PROCEDURE InitReader* (r: Reader; ch: Channel.Channel; byteOrder: SHORTINT);
  BEGIN
    r. res := done;
    r. byteReader := ch. NewReader();
    r. byteOrder := byteOrder;
    r. base := ch;
  END InitReader;

PROCEDURE ConnectReader*(ch: Channel.Channel): Reader;
  VAR
    r: Reader;
  BEGIN
    NEW (r);
    InitReader (r, ch, littleEndian);
    IF (r. byteReader = NIL) THEN
      RETURN NIL
    ELSE
      RETURN r
    END
  END ConnectReader;
  
(* Writer Procedures
   ------------------------------------------------------------------------ *)

(* Create a new Writer and attach it to the Channel ch. NIL is 
   returned when it is not possible to write to the channel.
   The Writer is positioned at the beginning for positionable 
   channels and at the current position for non-positionable channels.
 *)
PROCEDURE InitWriter* (w: Writer; ch: Channel.Channel; byteOrder: SHORTINT);
  BEGIN
    w. res := done;
    w. byteWriter := ch. NewWriter();
    w. byteOrder := byteOrder;
    w. base := ch;
  END InitWriter;

PROCEDURE ConnectWriter*(ch: Channel.Channel): Writer;
  VAR
    w: Writer;
  BEGIN
    NEW (w);
    InitWriter (w, ch, littleEndian);
    IF (w. byteWriter = NIL) THEN
      RETURN NIL
    ELSE
      RETURN w
    END
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
  NEW (errorContext);
  Msg.InitContext (errorContext, "OOC:Core:BinaryRider");
  Init
END BinaryRider.
