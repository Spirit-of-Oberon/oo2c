(* 	$Id: SymList.Mod,v 1.1 2003/08/24 00:02:44 mva Exp $	 *)
MODULE OOC:Scanner:SymList;
(*  Stores a list of text tokens (aka symbols).
    Copyright (C) 2000, 2002  Michael van Acken

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
  SYSTEM, Strings, OOC:Scanner:InputBuffer, Sym := OOC:Scanner:Symbol,
  OOC:Config:Pragmas;


TYPE
  Pos* = InputBuffer.CharPos;
  Line* = LONGINT;
  Column* = LONGINT;
  
TYPE
  Symbol* = POINTER TO SymbolDesc;
  SymbolDesc* = RECORD
    next-: Symbol;
    (**Next symbol in the list.  Any symbols that have no significance in an
       Oberon-2 module, like whitespace or comments, are discarded.  *)
    id-: Sym.Id;
    (**One of the ids define in module @omodule{Sym}.  *)
    str-: InputBuffer.CharArray;
    (**Character array with the textual representation of the symbol.  The
       string is 0X terminated, but for comments, pragmas, and illegal symbols
       it may also contain 0X.  For such symbols, the true length is stored in
       the field @ofield{len}.  *)
    len-: LONGINT;
    (**Length of character string in @ofield{str}.  This may differ from the
       result of @oproc{*Strings.Length}, if @ofield{str} contains @code{0X}
       characters in addition to the string terminator.  *)
    pos-: InputBuffer.CharPos;
    (**Character position of the first character of the symbol in the input
       stream.  *)
    line-, column-: LONGINT;
    (**Line and column of the first character of the symbol.  Line and
       column numbers start at 0.  *)
  END;

TYPE
  Builder* = POINTER TO BuilderDesc;
  BuilderDesc* = RECORD
    inputBuffer-: InputBuffer.Buffer;
    pragmaHistory-: Pragmas.History;
    (**The history data of assignments to pragma variables.  This field is
       set with @oproc{Builder.SetPragmaHistory} when the scanner is done.  *)
    
    head-, tail-: Symbol;
    (**These fields refer to the first and last symbol of the module.  When the
       scanner is done, both are not @code{NIL} and @ofield{tail} refers to
       the symbol with the id @oconst{Sym.endOfFile}.  *)
       
    includeDocComments: BOOLEAN;
  END;


PROCEDURE Init* (b: Builder; buffer: InputBuffer.Buffer;
                 includeDocComments: BOOLEAN);
(**Initialize builder object @oparam{b}.  The scanner will read its data from
   @oparam{buffer}.  The character intervals given to @oproc{Builder.AddSymbol}
   are mapped to strings from this buffer.  *)
  BEGIN
    b. inputBuffer := buffer;
    b. pragmaHistory := NIL;
    b. head := NIL;
    b. tail := NIL;
    b. includeDocComments := includeDocComments
  END Init;

PROCEDURE New* (buffer: InputBuffer.Buffer; includeDocComments: BOOLEAN): Builder;
  VAR
    b: Builder;
  BEGIN
    NEW (b);
    Init (b, buffer, includeDocComments);
    RETURN b
  END New;

PROCEDURE NewSymbol* (str: InputBuffer.CharArray; len: LONGINT): Symbol;
  VAR
    sym: Symbol;
  BEGIN
    NEW (sym);
    sym. next := NIL;
    sym. id := -1;
    sym. str := str;
    sym. len := len;
    sym. pos := 0;
    sym. line := 0;
    sym. column := 0;
    RETURN sym
  END NewSymbol;

PROCEDURE CloneSymbol* (old: Symbol; str: ARRAY OF InputBuffer.Char): Symbol;
  VAR
    sym: Symbol;
  BEGIN
    NEW (sym);
    sym. next := NIL;
    sym. id := old. id;
    sym. len := Strings.Length (str);
    NEW (sym. str, sym. len+1);
    COPY (str, sym. str^);
    sym. pos := old. pos;
    sym. line := old. line;
    sym. column := old. column;
    RETURN sym
  END CloneSymbol;

PROCEDURE (b: Builder) Clear*;
  BEGIN
    b. head := NIL;
    b. tail := NIL
  END Clear;

PROCEDURE (b: Builder) AddSymbol* (id: Sym.Id;
                                   cstart, cend: Pos;
                                   line, column: LONGINT);
(**Append new symbol to the list of symbols.  The values @oparam{cstart} and
   @oparam{cend} are character positions relative to 
   @samp{b.inputBuffer.offsetFromPos0}, that is, they are indexes of characters
   in @samp{b.inputBuffer.chars}.  @oparam{line} is the line number of
   the symbol (counting from 0), and @oparam{column} the column of its first
   character (counting from 0).  If the symbol is no whitespace, comment, 
   pragma, or illegal, then it starts and ends on the same line, and it has no
   embedded control characters.  Otherwise, it may span multiple lines, and 
   can have arbitrary embedded characters.  *)
  VAR
    sym: Symbol;
    len: LONGINT;
  BEGIN
    IF (id < Sym.comment) OR (id > Sym.whitespace) OR
       (id = Sym.docComment) & b. includeDocComments THEN
      NEW (sym);
      sym. next := NIL;
      sym. id := id;
      sym. pos := b. inputBuffer. offsetFromPos0+cstart;
      sym. line := line;
      sym. column := column;
      len := cend-cstart;
      NEW (sym. str, len+1);
      SYSTEM.MOVE (SYSTEM.ADR (b. inputBuffer. chars[cstart]),
                   SYSTEM.ADR (sym. str^), len);
      sym. str[len] := 0X;
      sym. len := len;
      
      IF (b. tail = NIL) THEN
        b. head := sym
      ELSE
        b. tail. next := sym
      END;
      b. tail := sym
    END
  END AddSymbol;

PROCEDURE (b: Builder) SetPragmaHistory* (pragmaHistory: Pragmas.History);
(**Sets @ofield{Builder.pragmaHistory}.  *)
  BEGIN
    b. pragmaHistory := pragmaHistory;
  END SetPragmaHistory;

END OOC:Scanner:SymList.
