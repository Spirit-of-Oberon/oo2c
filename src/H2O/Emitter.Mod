(*  
    Module Emitter: Low level processing for 
    Copyright (C) 1998-2004  Stewart Greenhill

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

MODULE H2O:Emitter;

IMPORT IO:TextRider, H2O:Value, Object;

CONST
  (* Declaration types *)
  dtConst* = 1;
  dtType* = 2;
  dtVar* = 3;
  dtUnknown* = 0;

TYPE
  Emitter* = POINTER TO EmitterDesc;
  EmitterDesc* = RECORD
    lineFull : BOOLEAN;
    declType : INTEGER;
    wr : TextRider.Writer;
  END;

PROCEDURE (e : Emitter) WriteString* (s : ARRAY OF CHAR);
BEGIN
  e.lineFull := TRUE;
  e.wr.WriteString(s);
END WriteString;

PROCEDURE (e : Emitter) WriteValueLongInt(o : Value.LongInt);
VAR
  value : LONGINT;
BEGIN
  value := o.value;
  IF (value <= 0) OR (o.radix = 10) THEN
    e.wr.WriteLInt(value, 0);
  ELSE
    e.wr.WriteHex(value, o.size);
    e.wr.WriteChar('H');
  END;
END WriteValueLongInt;

PROCEDURE (e : Emitter) WriteObject* (o : Object.Object);
BEGIN
  WITH o : Value.LongInt DO
    e.WriteValueLongInt(o);
  ELSE
    e.wr.WriteObject(o);
  END;
END WriteObject;

PROCEDURE (e : Emitter) WriteInt* (i : LONGINT);
BEGIN
  e.lineFull := TRUE;
  e.wr.WriteLInt(i,0);
END WriteInt;

PROCEDURE (e : Emitter) WriteHex* (i : LONGINT);
BEGIN
  e.lineFull := TRUE;
  e.wr.WriteHex(i,0);
END WriteHex;

PROCEDURE (e : Emitter) WriteChar* (ch : CHAR);
BEGIN
  e.lineFull := TRUE;
  e.wr.WriteChar(ch);
END WriteChar;

PROCEDURE (e : Emitter) WriteLn*;
BEGIN
  e.lineFull := FALSE;
  e.wr.WriteLn;
END WriteLn;

PROCEDURE (e : Emitter) BlankLine*;
BEGIN
  IF e.lineFull THEN
    e.WriteLn;
  END;
END BlankLine;

PROCEDURE (e : Emitter) DeclType* (t : INTEGER);
BEGIN
  e.BlankLine;
  
  IF t # e.declType THEN
    e.declType := t;
    CASE e.declType OF
    | dtConst: e.WriteString("CONST");
    | dtType: e.WriteString("TYPE");
    | dtVar: e.WriteString("VAR");
    END;
    e.WriteLn;
  END;
END DeclType;

PROCEDURE (e : Emitter) INIT* (wr : TextRider.Writer);
BEGIN
  e.lineFull := FALSE;
  e.declType := dtUnknown;
  e.wr := wr;
END INIT;

PROCEDURE (e : Emitter) Indent* (level : INTEGER);
VAR i : INTEGER;
BEGIN
  WHILE level > 0 DO
    e.WriteString("  ");
    DEC(level);
  END;
END Indent;

END H2O:Emitter.
