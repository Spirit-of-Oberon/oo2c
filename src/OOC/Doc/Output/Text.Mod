(* 	$Id: Text.Mod,v 1.4 2002/12/27 11:42:18 mva Exp $	 *)
MODULE OOC:Doc:Output:Text;
(*  Converts Texinfo text to plain ASCII file, similar to makeinfo.
    Copyright (C) 1999, 2000, 2001  Michael van Acken

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
  IntStr, Strings, OOC:Doc, OOC:Doc:TextBuffer, OOC:Doc:Decoration;


VAR
  replacements: ARRAY Doc.glyphRightQuot+1 OF ARRAY 4 OF CHAR;


PROCEDURE Convert* (document: Doc.Document;
                    indent, scrWidth, indentFirst: LONGINT): Doc.String;
(* Formats the Texinfo description in `texinfo', for a screen with of
   `scrWidth', using an indentation of `indent'.  The first line of a
   paragraph is indented additional `indentFirst' spaces.  *)
  VAR
    b: TextBuffer.Buffer;
    currBlock: TextBuffer.Buffer;
    
  PROCEDURE BlockList (blockList: Doc.BlockElement; indent, offsetFirst: LONGINT);
    VAR
      block: Doc.BlockElement;
      
    PROCEDURE InlineList (inlineList: Doc.InlineElement);
      VAR
        inline: Doc.InlineElement;
        name: ARRAY 32 OF CHAR;
      
      PROCEDURE ConvertMarkup (mi: Doc.MarkedInline);
        VAR
          h: LONGINT;
        BEGIN
          CASE mi. mark OF
          | Doc.markAsIs:
            InlineList (mi. inlineText)
          | Doc.markCite, Doc.markCode, Doc.markCommand, Doc.markFile,
            Doc.markKbd, Doc.markSamp, 
            Doc.markOberonModule, Doc.markOberonConst, Doc.markOberonProc,
            Doc.markOberonType, Doc.markOberonVar, Doc.markOberonField:
            currBlock. Append ("`");
            InlineList (mi. inlineText);
            currBlock. Append ("'")
          | Doc.markDfn:
            currBlock. Append ('"');
            InlineList (mi. inlineText);
            currBlock. Append ('"')
          | Doc.markEmph:
            currBlock. Append ("_");
            InlineList (mi. inlineText);
            currBlock. Append ("_")
          | Doc.markStrong:
            currBlock. Append ("*");
            InlineList (mi. inlineText);
            currBlock. Append ("*")
          | Doc.markVar, Doc.markOberonParam:
            h := currBlock. len;
            InlineList (mi. inlineText);
            currBlock. Capitalize (h, currBlock. len)
          | Doc.markUrl:
            currBlock. Append ("<");
            InlineList (mi. inlineText);
            currBlock. Append (">")
          END
        END ConvertMarkup;
      
      BEGIN
        inline := inlineList;
        WHILE (inline # NIL) DO
          inline. NodeName (name);
          WITH inline: Doc.Glyph DO
            currBlock. Append (replacements[inline. code])
            
          | inline: Doc.MarkedInline DO
            ConvertMarkup (inline)
            
          | inline: Doc.Text DO
            currBlock. Append (inline. string^)
            
          | inline: Doc.Email DO
            IF (inline. displayed = NIL) THEN (* one argument *)
              currBlock. Append ("<");
              InlineList (inline. address);
              currBlock. Append (">")
            ELSE                       (* two arguments *)
              InlineList (inline. displayed);
              currBlock. Append (" <");
              InlineList (inline. address);
              currBlock. Append (">")
            END
            
          | inline: Doc.Uref DO
            IF (inline. text = NIL) THEN (* one argument *)
              currBlock. Append ("`");
              InlineList (inline. url);
              currBlock. Append ("'")
            ELSIF (inline. replacement = NIL) THEN
              InlineList (inline. text);
              currBlock. Append (" (");
              InlineList (inline. url);
              currBlock. Append (")")
            ELSE                       (* three argument form *)
              InlineList (inline. replacement)
            END
          END;
          inline := inline. nextInline
        END
      END InlineList;
    
    PROCEDURE Block (block: Doc.BlockElement; indent, offsetFirst: LONGINT);
      VAR
        item, firstColumn: Doc.BlockElement;
        len, index: LONGINT;
        
      PROCEDURE ItemPrefix (prefix: Doc.InlineElement): LONGINT;
        VAR
          start: LONGINT;
        BEGIN
          start := currBlock. len;
          InlineList (prefix);
          currBlock. Append (" ");
          RETURN currBlock. len-start
        END ItemPrefix;

      PROCEDURE EnumPrefix (mode: SHORTINT; index: LONGINT): LONGINT;
        VAR
          start: LONGINT;
          str: ARRAY 16 OF CHAR;
        BEGIN
          start := currBlock. len;
          CASE mode OF
          | Doc.enumNumber:
            IntStr.IntToStr(index, str);
          | Doc.enumUppercase:
            str[0] := CHR(ORD("A")-1+index);
            str[1] := 0X;
          | Doc.enumLowercase:
            str[0] := CHR(ORD("a")-1+index);
            str[1] := 0X;
          END;
          Strings.Append(". ", str);
          currBlock.Append(str);
          RETURN currBlock. len-start
        END EnumPrefix;

      BEGIN
        WITH block: Doc.Paragraph DO
          InlineList (block. inlineText);
          IF block. noIndent & (offsetFirst > 0) THEN
            TextBuffer.FormatBlock(b, currBlock, indent, scrWidth, 0)
          ELSE
            TextBuffer.FormatBlock(b, currBlock, indent, scrWidth, offsetFirst)
          END;
          currBlock. Clear
        
        | block: Doc.Example DO
          InlineList (block. inlineText);
          TextBuffer.IndentBlock (b, currBlock, indent+5);
          currBlock. Clear
        
        | block: Doc.PreCond DO
          b. AppendSpaces (indent);
          b. Append ("*Pre-condition*: ");
          BlockList (block. blockList, indent, -(indent+17))
        
        | block: Doc.PostCond DO
          b. AppendSpaces (indent);
          b. Append ("*Pre-condition*: ");
          BlockList (block. blockList, indent, -(indent+18))
        
        | block: Doc.Itemize DO
          INC (indent, 5);
          IF (block. text # NIL) THEN
            BlockList (block. text. blockList, indent, 0);
            IF block. text. padAfter THEN
              b. AppendEOL
            END
          END;
          item := block. itemList;
          WHILE (item # NIL) DO
            IF (offsetFirst < 0) THEN
              b. AppendSpaces (3);
              len := ItemPrefix (block. mark);
              BlockList (item(Doc.Item). blockList, indent, offsetFirst-3)
            ELSE
              b. AppendSpaces (indent-2);
              len := ItemPrefix (block. mark);
              BlockList (item(Doc.Item). blockList, indent, -(indent-2))
            END;
            IF item. padAfter THEN
              b. AppendEOL
            END;
            item := item. nextBlock
          END
        
        | block: Doc.Enumerate DO
          INC (indent, 5);
          IF (block. text # NIL) THEN
            BlockList (block. text. blockList, indent, 0);
            IF block. text. padAfter THEN
              b. AppendEOL
            END
          END;
          index := block.start;
          item := block. itemList;
          WHILE (item # NIL) DO
            IF (offsetFirst < 0) THEN
              b. AppendSpaces (2);
              len := EnumPrefix (block.mode, index);
              BlockList (item(Doc.Item). blockList, indent, offsetFirst-2)
            ELSE
              b. AppendSpaces (indent-3);
              len := EnumPrefix (block.mode, index);
              BlockList (item(Doc.Item). blockList, indent, -(indent-3))
            END;
            IF item. padAfter THEN
              b. AppendEOL
            END;
            INC(index);
            item := item. nextBlock
          END
        
        | block: Doc.TableRow DO
          firstColumn := block. firstColumnList;
          WHILE (firstColumn # NIL) DO
            InlineList (firstColumn(Doc.FirstColumn). inlineText);
            TextBuffer.FormatBlock (b, currBlock, indent, scrWidth, 0);
            currBlock. Clear;
            firstColumn := firstColumn. nextBlock
          END;
          BlockList (block. item. blockList, indent+5, 0);

        | block: Doc.Table DO
          BlockList (block. rowList, indent, offsetFirst)
        END;
        IF block. padAfter THEN
          b. AppendEOL
        END
      END Block;
    
    BEGIN
      block := blockList;
      WHILE (block # NIL) DO
        Block (block, indent, offsetFirst);
        block := block. nextBlock
      END
    END BlockList;
  
  BEGIN
    b := TextBuffer.New();
    currBlock := TextBuffer.New();
    
    BlockList (document. blockList, indent, indentFirst);
    
    RETURN b. str
  END Convert;

PROCEDURE ToComment* (document: Doc.Document): Doc.String;
(* Like `Convert' above, and additionally rewrites the output text into 
   a comment that can be inserted again into the original source text.  *)
  VAR
    d: Decoration.Decoration;
    s: Doc.String;
  
(*  PROCEDURE CompensateIndentation (VAR s: ARRAY OF CHAR; len: LONGINT): BOOLEAN;
    VAR
      i: LONGINT;
    BEGIN
      i := 0;
      WHILE (i # len) DO
        IF (s[i] # " ") THEN
          RETURN FALSE
        END;
        INC (i)
      END;
      RETURN TRUE
    END CompensateIndentation;*)
  
  BEGIN
    d := document. decoration;
    s := Convert (document, d. indent, d. scrWidth, 0);
    
(*    s := d. Decorate (s);
    IF CompensateIndentation (s^, document. firstColumn) THEN
      Strings.Delete (s^, 0, SHORT (document. firstColumn))
    END;*)
    
    RETURN s
  END ToComment;

BEGIN
  replacements[Doc.glyphBullet] := "*";
  replacements[Doc.glyphDots] := "...";
  replacements[Doc.glyphMinus] := "-";
  replacements[Doc.glyphEmDash] := "--";
  replacements[Doc.glyphResult] := "=>";
  replacements[Doc.glyphLeftQuot] := '"';
  replacements[Doc.glyphRightQuot] := '"';
END OOC:Doc:Output:Text.
