(* 	$Id$	 *)
MODULE OOC:Scanner:Builder [OOC_EXTENSIONS];
(*  Builder interface for the scanner module.
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

IMPORT
  OOC:Scanner:InputBuffer, OOC:Scanner:Symbol;
  
(**
   A scanner builder is called from the scanner with information about symbols
   as they are being scanned.  For any kind of symbol, the scanner calls
   @oproc{Builder.AddSymbol}.  The procedure gets the symbol id (a value from
   the constants listed in @omodule{Symbol}, the start, and the ending position
   of the symbol as arguments.

   File positions are stored as (pos, line, column) tuples.  The position
   counts characters from the beginning of the file, with pos 0 being the first
   character.  Line 0, column 0 refers to the first position of the file.  The
   position of the end of a symbol refers to the character just to the right of
   the character in question.

   Example: A symbol @code{MODULE} in the first line of a file would have a
   starting position of (0,0,0), and an ending position of (6,0,6).

   Symbols can only be part of a single line, with the exception of the special
   symbols representing whitespace, comments, or pragmas.  That is, for normal
   symbols the line number of both starting and ending position is equal.  In
   this case the length of the symbol is equal to the difference of the column
   numbers (or character positions) of the ending and starting positions.

   Comments and pragmas are white space when translating a module.  For
   purposes of text rewriting they can't be ignored.  Therefore the scanner
   includes them as separate entities in the symbol stream.  They are stored as
   text blocks which include the starting and ending delimiter of the contruct.
   A comment starts with @code{(} and @code{*} and ends with the matching
   @code{*} and @code{)}, including any nested comments or pragmas within.  The
   same holds for pragmas.  Additionally program text that is disabled due to
   conditional compilation is included in the enclosing pragma's text block.
   For completeness, the scanner also reports whitespace in the text as
   symbols.  *)

TYPE
  Pos* = InputBuffer.CharPos;
  Line* = LONGINT;
  Column* = LONGINT;
  
TYPE
  Builder* = POINTER TO BuilderDesc;
  BuilderDesc* = RECORD [ABSTRACT]
    inputBuffer-: InputBuffer.Buffer;
  END;
  

PROCEDURE Init* (b: Builder; buffer: InputBuffer.Buffer);
(**Initialize builder object @oparam{b}.  The scanner will read its data from
   @oparam{buffer}.The character intervals given to @oproc{Builder.AddSymbol}
   are mapped to strings from this buffer.  *)
  BEGIN
    b. inputBuffer := buffer
  END Init;

PROCEDURE (b: Builder) [ABSTRACT] AddSymbol* (id: Symbol.Id;
                                              cstart, cend: Pos; line: Line;
                                              column: Column);
(**Append new symbol to the symbol stream.  The values @oparam{cstart} and
   @oparam{cend} are character positions relative to 
   @samp{b.inputBuffer.offsetFromPos0}, that is, they are indexes of characters
   in @samp{b.inputBuffer.chars}.  @oparam{line} is the line number of
   the symbol (counting from 0), and @oparam{column} the column of its first
   character (counting from 0).  If the symbol is no whitespace, comment, 
   pragma, or illegal, then it starts and ends on the same line, and it has no
   embedded control characters.  Otherwise, it may span multiple lines, and 
   can have arbitrary embedded characters.  *)
  END AddSymbol;

END OOC:Scanner:Builder.
