(* 	$Id: Identity.Mod,v 1.3 2004/04/01 20:36:12 mva Exp $	 *)
MODULE OOC:Scanner:Identity;
(*  Passes string representation of scanned symbols to output channel.
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

(** This is the most simple builder for a scanner: it takes the string
representation of the symbols, and writes it unchanged to the
designated output channel.  The output produced this way matches the
input data character to character, even if the scanner reports illegal
or malformed symbols.  Note that the scanner also passes whitespace to
the builder.  *)

IMPORT
  Exception, IO, OOC:Scanner:Symbol, OOC:Scanner:InputBuffer, 
  B := OOC:Scanner:SymList;

TYPE
  Builder* = POINTER TO BuilderDesc;
  BuilderDesc = RECORD
    (B.BuilderDesc)
    writer: IO.ByteChannel;
  END;
  

PROCEDURE Init* (b: Builder; buffer: InputBuffer.Buffer; ch: IO.ByteChannel);
  BEGIN
    B.Init (b, buffer, TRUE);
    b. writer := ch;
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
    d: LONGINT;
  BEGIN
    TRY
      d := b. writer. Write (b. inputBuffer. chars^, cstart, cend-cstart);
    CATCH IO.Error(e):
      Exception.Abort(e);
    END;
  END AddSymbol;

END OOC:Scanner:Identity.
