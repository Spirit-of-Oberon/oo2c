(* 	$Id: Writer.Mod,v 1.11 2003/02/02 19:10:09 mva Exp $	 *)
MODULE OOC:IA32:Writer [OOC_EXTENSIONS];
(*  Write assembler file.
    Copyright (C) 2002, 2003  Michael van Acken

    This file is part of OOC.

    OOC is free software; you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.  

    OOC is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
    License for more details. 

    You should have received a copy of the GNU General Public License
    along with OOC. If not, write to the Free Software Foundation, 59
    Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*)

IMPORT
  Ascii, IntStr, Strings, IO, IO:TextRider,
  Object, Object:Boxed, ADT:Dictionary;

TYPE
  Writer* = POINTER TO WriterDesc;
  WriterDesc* = RECORD
    (**This writer is wrapper around of @otype{TextRider.Writer} with
       additional knowledge about C declarations, definitions, and literals.
       Its main purpose is to act as an abstraction layer for the not so easy
       task of writing C type expressions.  *)
    ch: IO.ByteChannel;
    textWriter-: TextRider.Writer;
    stringData: Dictionary.Dictionary;
    stringDataCount: LONGINT;
  END;


PROCEDURE InitWriter (w: Writer; ch: IO.ByteChannel);
  BEGIN
    w. ch := ch;
    w. textWriter := TextRider.ConnectWriter (ch);
    w. stringData := Dictionary.New();
    w. stringDataCount := 1;
  END InitWriter;

PROCEDURE NewWriter* (ch: IO.ByteChannel): Writer;
  VAR
    w: Writer;
  BEGIN
    NEW (w);
    InitWriter (w, ch);
    RETURN w
  END NewWriter;

PROCEDURE (w: Writer) Newline*;
  BEGIN
    w. textWriter. WriteLn;
  END Newline;

PROCEDURE (w: Writer) Write* (str: ARRAY OF CHAR);
  BEGIN
    w. textWriter. WriteString (str);
  END Write;

PROCEDURE (w: Writer) WriteObject* (str: STRING);
  BEGIN
    w. textWriter. WriteObject (str);
  END WriteObject;

PROCEDURE (w: Writer) Label* (label: STRING);
  BEGIN
    w. textWriter. WriteObject (label);
    w. textWriter. WriteChar (":");
    w. textWriter. WriteLn;
  END Label;

PROCEDURE (w: Writer) Section* (section: ARRAY OF CHAR);
  BEGIN
    w. textWriter. WriteString (section);
    w. textWriter. WriteLn;
  END Section;

PROCEDURE (w: Writer) Directive* (dir: ARRAY OF CHAR);
  BEGIN
    w. textWriter. WriteChar (Ascii.ht);
    w. textWriter. WriteString (dir);
    w. textWriter. WriteLn;
  END Directive;

PROCEDURE (w: Writer) Instr* (instr: ARRAY OF CHAR);
  BEGIN
    w. textWriter. WriteChar (Ascii.ht);
    w. textWriter. WriteString (instr);
    w. textWriter. WriteLn;
  END Instr;

PROCEDURE (w: Writer) StringLiteral* (str: ARRAY OF CHAR);
  BEGIN
    w. textWriter. WriteChar (Ascii.ht);
    w. textWriter. WriteString ('.string "');
    w. textWriter. WriteString (str);
    w. textWriter. WriteString ('"');
    w. textWriter. WriteLn;
  END StringLiteral;

PROCEDURE (w: Writer) GetStringLabel* (value: Boxed.String): STRING;
  VAR
    obj: Object.Object;
    s: STRING;
    label: ARRAY 32 OF CHAR;
  BEGIN
    IF w. stringData. HasKey (value) THEN
      obj := w. stringData. Get (value);
      RETURN obj(STRING);
    ELSE
      IntStr.IntToStr (w. stringDataCount, label);
      INC (w. stringDataCount);
      Strings.Insert (".LC", 0, label);
      s := Object.NewLatin1(label);
      w. stringData. Set (value, s);
      RETURN s;
    END;
  END GetStringLabel;

PROCEDURE (w: Writer) PushInt* (i: LONGINT);
  BEGIN
    w. textWriter. WriteString (Ascii.ht+"pushl $");
    w. textWriter. WriteLInt (i, 0);
    w. textWriter. WriteLn;
  END PushInt;

PROCEDURE (w: Writer) PushLabel* (label: ARRAY OF CHAR);
  BEGIN
    w. textWriter. WriteString (Ascii.ht+"pushl $");
    w. textWriter. WriteString (label);
    w. textWriter. WriteLn;
  END PushLabel;

PROCEDURE (w: Writer) PopBytes* (bytes: LONGINT);
  BEGIN
    w. textWriter. WriteString (Ascii.ht+"addl $");
    w. textWriter. WriteLInt (bytes, 0);
    w. textWriter. WriteString (",%esp");
    w. textWriter. WriteLn;
  END PopBytes;

PROCEDURE (w: Writer) WriteStringData* ();
  VAR
    strings: Object.ObjectArrayPtr;
    label: Object.Object;
    i: LONGINT;
    chars: Object.CharsLatin1;
  BEGIN
    w. Section (".data");
    w. Section (".section .rodata");
    strings := w. stringData. Keys();
    FOR i := 0 TO LEN (strings^)-1 DO
      label := w. stringData. Get (strings[i]);
      w. Label (label(STRING));
      chars := strings[i](Boxed.String).value(Object.String8).CharsLatin1();
      w. StringLiteral (chars^);
    END;
  END WriteStringData;

PROCEDURE (w: Writer) Close* () RAISES IO.Error;
(**Closes the writer's output channel.  *)
  VAR
    ch: IO.ByteChannel;
  BEGIN
    IF (w.textWriter.error # NIL) THEN
      RAISE(w.textWriter.error);
    END;

    ch := w.textWriter.channel;
    ch.CloseAndRegister();
  END Close;

END OOC:IA32:Writer.
