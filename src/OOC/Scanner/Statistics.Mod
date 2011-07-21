(* 	$Id: Statistics.Mod,v 1.3 2004/04/01 20:36:12 mva Exp $	 *)
MODULE OOC:Scanner:Statistics;
(*  Displays statistics about the symbols of a module.
    Copyright (C) 2000  Michael van Acken

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

(** This builder counts the symbols of a module.  For every kind of
symbol, it lists how often it appears in the input text, and how many
characters are used by these symbols.  *)

IMPORT
  IO, IO:TextRider, Strings, OOC:Scanner:InputBuffer, OOC:Scanner:Symbol,
  B := OOC:Scanner:SymList;

CONST
  maxSymbols= 256;
  
TYPE
  Builder* = POINTER TO BuilderDesc;
  BuilderDesc = RECORD
    (B.BuilderDesc)
    w: TextRider.Writer;
    numOfSymbols: LONGINT;
    numOfChars: LONGINT;
    symPerId, sizePerId: ARRAY maxSymbols OF LONGINT;
  END;

PROCEDURE Init* (b: Builder; buffer: InputBuffer.Buffer; ch: IO.ByteChannel);
  VAR
    i: LONGINT;
  BEGIN
    B.Init (b, buffer, TRUE);
    b. w := TextRider.ConnectWriter (ch);
    b. numOfSymbols := 0;
    b. numOfChars := 0;
    FOR i := 0 TO maxSymbols-1 DO
      b. symPerId[i] := 0;
      b. sizePerId[i] := 0
    END
  END Init;

PROCEDURE New* (buffer: InputBuffer.Buffer; ch: IO.ByteChannel): Builder;
  VAR
    b: Builder;
  BEGIN
    NEW (b);
    Init (b, buffer, ch);
    RETURN b
  END New;

PROCEDURE (b: Builder) AddSymbol* (id: Symbol.Id;
                                   cstart, cend: B.Pos;
                                   line, column: LONGINT);
  VAR
    i: LONGINT;
    numOfWS: LONGINT;
    sizeOfWS: LONGINT;
    
  PROCEDURE WritePadded (str: ARRAY OF CHAR; width: INTEGER);
    VAR
      len: INTEGER;
    BEGIN
      b. w. WriteString (str);
      len := Strings.Length (str);
      WHILE (width > len) DO
        b. w. WriteChar (" ");
        DEC (width)
      END
    END WritePadded;
  
  BEGIN
    INC (b. numOfSymbols);
    INC (b. numOfChars, cend-cstart);
    INC (b. symPerId[id]);
    INC (b. sizePerId[id], cend-cstart);
    
    IF (id = Symbol.endOfFile) THEN
      b. w. WriteString ("#symbols: ");
      b. w. WriteLInt (b. numOfSymbols, 6);
      b. w. WriteLn;
      b. w. WriteString ("#chars  : ");
      b. w. WriteLInt (b. numOfChars, 6);
      b. w. WriteLn;
      b. w. WriteLn;
      
      b. w. WriteString ("name            #symbols    #chars");
      b. w. WriteLn;
      b. w. WriteString ("--------------  --------  --------");
      b. w. WriteLn;
      numOfWS := 0;
      sizeOfWS := 0;
      FOR i := 0 TO maxSymbols-1 DO
        IF (b. symPerId[i] # 0) THEN
          IF (Symbol.comment <= i) & (i <= Symbol.whitespace) THEN
            INC (numOfWS, b. symPerId[i]);
            INC (sizeOfWS, b. sizePerId[i])
          END;
          
          WritePadded (Symbol.name[i], 14);
          b. w. WriteLInt (b. symPerId[i], 10);
          b. w. WriteLInt (b. sizePerId[i], 10);
          b. w. WriteLn
        END
      END;
      b. w. WriteLn;
      
      b. w. WriteString ("all whitespace");
      b. w. WriteLInt (numOfWS, 10);
      b. w. WriteLInt (sizeOfWS, 10);
      b. w. WriteLn;
      b. w. WriteString ("non-whitespace");
      b. w. WriteLInt (b. numOfSymbols-numOfWS, 10);
      b. w. WriteLInt (b. numOfChars-sizeOfWS, 10);
      b. w. WriteLn
    END
  END AddSymbol;

END OOC:Scanner:Statistics.
