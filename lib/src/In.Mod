(*	$Id: In.Mod,v 1.2 2002/06/17 21:45:53 mva Exp $	*)
MODULE In;

(*
    In -  Simple terminal input of Oberon variables.       
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

IMPORT
  StdChannels, TextRider;
    
VAR
  reader-: TextRider.Reader;
  (**This is the rider used by the input procedures.  It is initialized to
     hold a text reader on the channel @ovar{StdChannels.stdin}.  This can be
     changed by calling @oproc{SetReader}.  *)

PROCEDURE Done* () : BOOLEAN;
(**Returns @code{TRUE} if the last operation was successful.  *)
  BEGIN
    RETURN (reader. res = TextRider.done)
  END Done;

PROCEDURE ClearError*;
  BEGIN
    reader. ClearError
  END ClearError;


PROCEDURE SetReader* (r: TextRider.Reader);
(**Changes the rider @ovar{reader}.  All following calls to input procedures
   will read from @oparam{r}.  The preferred method of connecting to the
   standard input channel is to call @samp{SetReader(NIL)}.  *)
  BEGIN
    IF r=NIL THEN reader:=TextRider.ConnectReader(StdChannels.stdin)
    ELSE reader := r
    END
  END SetReader;

PROCEDURE Char* (VAR ch: CHAR);
  BEGIN
    reader. ReadChar (ch);
  END Char;

PROCEDURE Line* (VAR s: ARRAY OF CHAR);
  BEGIN
    reader. ReadLine (s)   
  END Line;

PROCEDURE String* (VAR s: ARRAY OF CHAR);
  BEGIN
    reader. ReadString (s)   
  END String;  
  
PROCEDURE Identifier* (VAR s: ARRAY OF CHAR);
  BEGIN
    reader. ReadIdentifier (s) 
  END Identifier;
  
PROCEDURE Bool* (VAR bool: BOOLEAN);
  BEGIN
    reader. ReadBool (bool)   
  END Bool;
  
PROCEDURE ShortInt* (VAR int: SHORTINT);
  BEGIN
    reader. ReadSInt (int)   
  END ShortInt;
  
PROCEDURE Int* (VAR int: INTEGER);
  BEGIN
    reader. ReadInt (int)  
  END Int;

PROCEDURE LongInt* (VAR lint: LONGINT);
  BEGIN
    reader. ReadLInt (lint)  
  END LongInt;

PROCEDURE Hex* (VAR lint: LONGINT);
  BEGIN
    reader. ReadHex (lint) 
  END Hex;
  
PROCEDURE LongReal* (VAR lreal: LONGREAL);
  BEGIN
    reader. ReadLReal (lreal)    
  END LongReal;

PROCEDURE Real* (VAR real: REAL);
  BEGIN
    reader. ReadReal (real)   
  END Real;
  
PROCEDURE Set* (VAR s: SET);
  BEGIN
    reader. ReadSet (s)    
  END Set;

BEGIN
  SetReader(NIL)
END In.




