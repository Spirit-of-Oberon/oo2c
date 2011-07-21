(*	$Id: Log.Mod,v 1.9 2003/08/03 16:39:37 mva Exp $	*)
MODULE Log [OOC_EXTENSIONS];
(*  Simple logging facility to stderr.
    Copyright (C) 1998-2000 Michael van Acken
 
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
  S := SYSTEM, RT0, StdChannels, TextRider, Obj := Object;

VAR
  writer-: TextRider.Writer;
  (**This is the rider used by the output procedures.  It is initialized to
     hold a text writer to the channel @ovar{StdChannels.stderr}.  This can be
     changed by calling @oproc{SetWriter}.  *)
     
PROCEDURE Done* () : BOOLEAN;
(**Returns @code{TRUE} if the last operation was successful.  *)
  BEGIN
    RETURN (writer. res = TextRider.done)
  END Done;

PROCEDURE ClearError*;
  BEGIN
    writer. ClearError
  END ClearError;


PROCEDURE SetWriter* (w: TextRider.Writer);
(* Changes the rider @ovar{writer}.  All following calls to output procedures
   will write to @oparam{w}.  The preferred method of connecting to the
   standard output channel is to call @samp{SetWriter(NIL)}.  *)
  BEGIN
    IF w=NIL THEN writer:=TextRider.ConnectWriter (StdChannels.stderr)
    ELSE writer:=w
    END  
  END SetWriter;

PROCEDURE Flush*;
(**Flushes all buffers associated with @ovar{writer}.  *)
  BEGIN
    writer. base. Flush
  END Flush;


PROCEDURE Char* (msg[NO_COPY]: ARRAY OF CHAR; ch: CHAR);
  BEGIN
    writer. WriteString (msg);
    writer. WriteString (": ");
    writer. WriteChar (ch);
    writer. WriteLn
  END Char;
  
PROCEDURE String* (msg[NO_COPY]: ARRAY OF CHAR; s[NO_COPY]: ARRAY OF CHAR);
  BEGIN
    writer. WriteString (msg);
    writer. WriteString (": ");
    writer. WriteString (s);
    writer. WriteLn
  END String;

PROCEDURE LString* (msg[NO_COPY]: ARRAY OF CHAR; s[NO_COPY]: ARRAY OF LONGCHAR);
(**Very primitive @code{LONGCHAR} output.  The procedure writes a string of
   @code{SHORT}ed characters.  If a character cannot be shorted, it is replaced
   by the character @samp{?}.  In the future, this may be changed to UTF-8
   output.  Use at your own risk!

   As it is, this procedure should @emph{not} be documented in the reference
   manual.  *)
  VAR
    i: LONGINT;
  BEGIN
    writer. WriteString (msg);
    writer. WriteString (": ");
    i := 0;
    WHILE (s[i] # 0X) DO
      WHILE (s[i] # 0X) & (s[i] <= MAX (CHAR)) DO
        writer. WriteChar (SHORT (s[i]));
        INC (i)
      END;
      WHILE (s[i] # 0X) & (s[i] > MAX (CHAR)) DO
        writer. WriteChar ("?");
        INC (i)
      END
    END;
    writer. WriteLn
  END LString;

PROCEDURE Object* (msg[NO_COPY]: ARRAY OF CHAR; obj: Obj.Object);
  BEGIN
    writer. WriteString (msg);
    writer. WriteString (": ");
    writer. WriteObject (obj);
    writer. WriteLn
  END Object;

PROCEDURE Bool* (msg[NO_COPY]: ARRAY OF CHAR; bool: BOOLEAN);
  BEGIN
    writer. WriteString (msg);
    writer. WriteString (": ");
    writer. WriteBool (bool);
    writer. WriteLn
  END Bool;
  
PROCEDURE LongInt* (msg[NO_COPY]: ARRAY OF CHAR; lint: LONGINT);
  BEGIN
    writer. WriteString (msg);
    writer. WriteString (": ");
    writer. WriteLInt (lint, 0);
    writer. WriteLn
  END LongInt;

PROCEDURE ShortInt* (msg[NO_COPY]: ARRAY OF CHAR; sint: SHORTINT);
  BEGIN
    writer. WriteString (msg);
    writer. WriteString (": ");
    writer. WriteSInt (sint, 0);
    writer. WriteLn
  END ShortInt;

PROCEDURE Int* (msg[NO_COPY]: ARRAY OF CHAR; int: LONGINT);
  BEGIN
    writer. WriteString (msg);
    writer. WriteString (": ");
    writer. WriteLInt (int, 0);
    writer. WriteLn
  END Int;

PROCEDURE Hex* (msg[NO_COPY]: ARRAY OF CHAR; lint: LONGINT);
  BEGIN
    writer. WriteString (msg);
    writer. WriteString (": ");
    writer. WriteHex (lint, 8);
    writer. WriteLn
  END Hex;
 
PROCEDURE HexAdr (msg[NO_COPY]: ARRAY OF CHAR; adr: S.ADDRESS);
  BEGIN
    writer. WriteString (msg);
    writer. WriteString (": ");
<* IF TARGET_ADDRESS = 64 THEN *>
    writer. WriteHex (SHORT (S.LSH (adr, -32)), 8);
    writer. WriteHex (SHORT (S.LSH (S.LSH (adr, 32), -32)), 8);
<* ELSE *>
    writer. WriteHex (adr, 8);
<* END *>
    writer. WriteLn
  END HexAdr;
 
PROCEDURE LongReal* (msg[NO_COPY]: ARRAY OF CHAR; lreal: LONGREAL);
  BEGIN
    writer. WriteString (msg);
    writer. WriteString (": ");
    writer. WriteLReal (lreal, 24, 17);
    writer. WriteLn
  END LongReal;

PROCEDURE Real* (msg[NO_COPY]: ARRAY OF CHAR; real: REAL);
  BEGIN
    writer. WriteString (msg);
    writer. WriteString (": ");
    writer. WriteReal (real, 16, 9);
    writer. WriteLn
  END Real;

PROCEDURE LongRealEng* (lreal: LONGREAL);
  BEGIN
    writer. WriteLRealEng (lreal, 26, 17)
  END LongRealEng;

PROCEDURE RealEng* (real: REAL);
  BEGIN
    writer. WriteRealEng (real, 18, 9)
  END RealEng;
  
PROCEDURE Set* (msg[NO_COPY]: ARRAY OF CHAR; s: SET);
  BEGIN
    writer. WriteString (msg);
    writer. WriteString (": ");
    writer. WriteSet (s);
    writer. WriteLn
  END Set;

PROCEDURE Msg* (msg[NO_COPY]: ARRAY OF CHAR);
  BEGIN
    writer. WriteString (msg);
    writer. WriteLn
  END Msg;

PROCEDURE Ln*;
  BEGIN
    writer. WriteLn
  END Ln;

PROCEDURE Ptr* (msg[NO_COPY]: ARRAY OF CHAR; ptr: S.PTR);
  BEGIN
    IF (ptr = NIL) THEN
      String (msg, "NIL")
    ELSE
      HexAdr (msg, S.VAL (S.ADDRESS, ptr))
    END
  END Ptr;

PROCEDURE Adr* (msg[NO_COPY]: ARRAY OF CHAR; VAR x: ARRAY OF S.BYTE);
  BEGIN
    HexAdr (msg, S.ADR (x))
  END Adr;

PROCEDURE Type* (msg[NO_COPY]: ARRAY OF CHAR; ptr: S.PTR);
(* pre: `ptr' is a POINTER TO R, where R is a record type whose type is 
     declared in a normal module.  'o' must have a legal value, i.e., it is
     either NIL or was initialized through NEW.  *)
  VAR
    str: ARRAY 256 OF CHAR;
    type: RT0.Struct;
  BEGIN
    IF (ptr = NIL) THEN
      String (msg, "NIL")
    ELSE
      type := RT0.TypeOf (ptr);
      writer. WriteString (msg);
      writer. WriteString (": ");
      COPY (type. module. name^, str);
      writer. WriteString (str);
      writer. WriteString (".");
      COPY (type. name^, str);
      writer. WriteString (str);
      writer. WriteLn
    END
  END Type;

BEGIN
  SetWriter(NIL) 
END Log.
