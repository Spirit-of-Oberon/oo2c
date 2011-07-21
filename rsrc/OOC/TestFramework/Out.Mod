(*	$Id: Out.Mod,v 1.1 2001/04/12 12:52:00 mva Exp $	*)
MODULE Out [OOC_EXTENSIONS];

(*
    OakOut -  Text-based output of Oberon variables.       
    Copyright (C) 1997 Michael Griebling
 
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

(* see also [Oakwood Guidelines, revision 1A]
Module Out provides a set of basic routines for formatted output of characters,
numbers, and strings.  It assumes a standard output stream to which the symbols
are written.

Examples
                                output (asterisks denote blanks)
  Out.Open;
  Out.Int(-3, 5);               ***-3
  Out.Int(3, 0);                3
  Out.Real(1.5, 10);            ***1.5E+00  (original Oakwood: **1.50E+00(?))
  Out.Real(-0.005, 0)           -5.0E-03
*)

IMPORT 
  RealStr, LRealStr, Strings, StdChannels, TextRider;

VAR
  writer: TextRider.Writer;
  
PROCEDURE Open*;
(* Initializes the output stream. *)
  BEGIN 
    writer:=TextRider.ConnectWriter(StdChannels.stdout);
    IF writer=NIL THEN RETURN END;
    writer.SetOpts({TextRider.noBuffering})  (* don't need Flush anymore *)
  END Open;

PROCEDURE Char* (ch: CHAR);
(* Writes the character ch to the end of the output stream. *)
  BEGIN
    IF writer=NIL THEN RETURN END;
    writer. WriteChar (ch)
  END Char;

PROCEDURE String* (s[NO_COPY]: ARRAY OF CHAR);
(* Writes the null-terminated character sequence s to the end of the output
   stream (without 0X). *)
  BEGIN
    IF writer=NIL THEN RETURN END;  
    writer. WriteString (s)
  END String;

PROCEDURE Int* (i, n: LONGINT);
(* Writes the integer number i to the end of the output stream.  If the textual
   representation of i requires m characters, i is right adjusted in a field of
   Max(n, m) characters padded with blanks at the left end.  A plus sign is not
   written. *)
  BEGIN
    IF writer=NIL THEN RETURN END;  
    writer. WriteLInt (i, n) 
  END Int;

PROCEDURE RemoveTrailingZeros (VAR str: ARRAY OF CHAR; pos: INTEGER);
  BEGIN
    WHILE (pos>1) & (str[pos-1]#".") & (str[pos]="0") DO
      Strings.Delete(str, pos, 1); DEC(pos)
    END
  END RemoveTrailingZeros;
  
PROCEDURE Real* (x: REAL; n: INTEGER);
(* Writes the real number x to the end of the output stream using an 
   exponential form.  If the textual representation of x requires m characters
   (including a two-digit signed exponent), x is right adjusted in a field of
   Max(n, m) characters padded with blanks at the left end.  A plus sign of the
   mantissa is not written. *)
  VAR
    str: ARRAY 128 OF CHAR; pos: INTEGER; found: BOOLEAN;
  BEGIN
    IF writer=NIL THEN RETURN END;
    
    (* format the string *)
    RealStr.RealToFloat(x, 0, str);
    
    (* add exponent if it is zero *)
    Strings.FindNext("E", str, 0, found, pos);
    IF ~found THEN (* append zero exponent for Oakwood *)
      RemoveTrailingZeros(str, Strings.Length(str)-1);   
      Strings.Append("E+00", str)
    ELSE
      (* add another zero to the exponent -- if needed *)
      IF Strings.Length(str)-pos<4 THEN Strings.Insert("0", pos+2, str) END;
      RemoveTrailingZeros(str, pos-1)
    END;
    
    (* output the string *)
    DEC(n, Strings.Length(str));
    WHILE n>0 DO writer. WriteChar(" "); DEC(n) END;  
    writer. WriteString(str)
  END Real;

PROCEDURE LongReal* (x: LONGREAL; n: INTEGER);
(* Writes the long real number x to the end of the output stream using an 
   exponential form.  If the textual representation of x requires m characters
   (including a three-digit signed exponent), x is right adjusted in a field of
   Max(n, m) characters padded with blanks at the left end.  A plus sign of the
   mantissa is not written. *)
  VAR
    str: ARRAY 128 OF CHAR; pos: INTEGER; found: BOOLEAN;
  BEGIN
    IF writer=NIL THEN RETURN END;
    
    (* format the string *)
    LRealStr.RealToFloat(x, 0, str);
    
    (* add exponent if it is zero *)
    Strings.FindNext("E", str, 0, found, pos);
    IF ~found THEN (* append zero exponent for Oakwood *)
      RemoveTrailingZeros(str, Strings.Length(str)-1);   
      Strings.Append("E+000", str)
    ELSE
      (* add another zero to the exponent -- if needed *)
      IF Strings.Length(str)-pos<5 THEN Strings.Insert("0", pos+2, str) END;
      RemoveTrailingZeros(str, pos-1)
    END;
    
    (* output the string *)
    DEC(n, Strings.Length(str));
    WHILE n>0 DO writer. WriteChar(" "); DEC(n) END;  
    writer. WriteString(str)
  END LongReal;

PROCEDURE Ln*;
(* Writes an end-of-line symbol to the end of the output stream. *)
  BEGIN
    IF writer=NIL THEN RETURN END;  
    writer. WriteLn    
  END Ln;

BEGIN
  writer:=NIL
END Out.
