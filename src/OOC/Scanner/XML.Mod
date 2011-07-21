(* 	$Id: XML.Mod,v 1.3 2004/04/01 20:36:12 mva Exp $	 *)
MODULE OOC:Scanner:XML;
(*  Creates XML document from a scanned symbol sequence.
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

(** This builder translates a sequence of scanned symbols into an XML
document.  The output includes the textual representation of the
symbol, its character position in the input channel, its line number,
and its starting column.

Example: This very simple module,

@example
MODULE Simple;
END Simple.
@end example

@noindent
produces this XML document

@example
<?xml version='1.0' encoding='ISO-8859-1' standalone='yes'?>
<document>
<symbol id='module' pos='0' line='1' column='0'>MODULE</symbol>
<symbol id='whitespace' pos='6' line='1' column='6'> </symbol>
<symbol id='ident' pos='7' line='1' column='7'>Simple</symbol>
<symbol id='semicolon' pos='13' line='1' column='13'>;</symbol>
<symbol id='whitespace' pos='14' line='1' column='14'>&#10;</symbol>
<symbol id='end' pos='15' line='2' column='0'>END</symbol>
<symbol id='whitespace' pos='18' line='2' column='3'> </symbol>
<symbol id='ident' pos='19' line='2' column='4'>Simple</symbol>
<symbol id='period' pos='25' line='2' column='10'>.</symbol>
<symbol id='whitespace' pos='26' line='2' column='11'>&#10;</symbol>
<symbol id='endOfFile' pos='27' line='3' column='0'></symbol>
</document>
@end example
*)

IMPORT
  Exception, IO, IO:TextRider,
  OOC:Scanner:Symbol, OOC:Scanner:InputBuffer, B := OOC:Scanner:SymList;

TYPE
  Builder* = POINTER TO BuilderDesc;
  BuilderDesc = RECORD
    (B.BuilderDesc)
    w: TextRider.Writer;
  END;
  

PROCEDURE Init* (b: Builder; buffer: InputBuffer.Buffer; ch: IO.ByteChannel);
  BEGIN
    B.Init (b, buffer, TRUE);
    b. w := TextRider.ConnectWriter (ch);
  END Init;

PROCEDURE New* (buffer: InputBuffer.Buffer; ch: IO.ByteChannel): Builder;
  VAR
    b: Builder;
  BEGIN
    NEW (b);
    Init (b, buffer, ch);
    b. w. WriteString ("<?xml version='1.0' encoding='ISO-8859-1' standalone='yes'?>");
    b. w. WriteLn;
    b. w. WriteString ("<document>");
    b. w. WriteLn;
    RETURN b
  END New;

PROCEDURE (b: Builder) AddSymbol* (id: Symbol.Id;
                                   cstart, cend: B.Pos;
                                   line, column: LONGINT);
  PROCEDURE WriteQuoted (w: TextRider.Writer; VAR str: ARRAY OF CHAR; s, e: LONGINT);
    VAR
      last, d: LONGINT;
    BEGIN
      WHILE (s # e) DO
        last := s;
        WHILE (s # e) &
              (str[s] # "&") & (str[s] # "<") & (str[s] # ">") & 
              (str[s] # 09X) & (str[s] # 0AX) & (str[s] # 0DX) DO
          INC (s)
        END;
        TRY
          d := w. channel. Write (str, last, s-last);
        CATCH IO.Error(e):
          Exception.Abort(e);
        END;
        IF (s # e) THEN
          CASE str[s] OF
          | "&": w. WriteString ("&amp;")
          | "<": w. WriteString ("&lt;")
          | ">": w. WriteString ("&gt;")
          | 09X: w. WriteString ("&#9;")
          | 0AX: w. WriteString ("&#10;")
          | 0DX: w. WriteString ("&#13;")
          END;
          INC (s)
        END
      END
    END WriteQuoted;

  BEGIN
    b. w. WriteString ("<symbol id='");
    b. w. WriteString (Symbol.name[id]);
    b. w. WriteString ("' pos='");
    b. w. WriteLInt (b. inputBuffer. offsetFromPos0+cstart, 0);
    b. w. WriteString ("' line='");
    b. w. WriteLInt (line, 0);
    b. w. WriteString ("' column='");
    b. w. WriteLInt (column, 0);
    b. w. WriteString ("'>");
    WriteQuoted (b. w, b. inputBuffer. chars^, cstart, cend);
    b. w. WriteString ("</symbol>");
    b. w. WriteLn;
    
    IF (id = Symbol.endOfFile) THEN
      b. w. WriteString ("</document>");
      b. w. WriteLn
    END
  END AddSymbol;

END OOC:Scanner:XML.
