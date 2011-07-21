(* 	$Id: Doc.Mod,v 1.15 2003/07/06 09:09:05 mva Exp $	 *)
MODULE OOC:Doc [OOC_EXTENSIONS];
(*  Defines the data structure used to store documentation strings.
    Copyright (C) 2002, 2003  Michael van Acken

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
  CharClass, Strings, Object, ADT:Storable, ADT:ArrayList, IO,
  OOC:Doc:Decoration, OOC:Scanner:InputBuffer;


(*

Adding a new command:

1. Add a new class to OOC:Doc to hold the internal representation
   of the command.
   
2. For the new class, define the `InitXXX' and `NewXXX' procedures,
   and the type-bound procedures `NodeName' and `Normalize'.

3. Extent the parser (or parsers) under OOC:Doc:Input:* to accept
   the new command, and to create instances of the new class.

4. Extent the presentation modules (OOC:Doc:Output:XML and friends)
   to emit formatted text for the new class.  Don't forget to adjust
   the DTD `oberon-doc.dtd' of the XML output, too.
   
*)

TYPE
  Position* = RECORD
    char-: InputBuffer.CharPos;
    line-, column-: LONGINT;
  END;
  
TYPE
  Element* = POINTER TO ElementDesc;
  ElementDesc = RECORD [ABSTRACT]
    (Storable.ObjectDesc)
    pos*: Position;
    (**Currently, this field is only valid for @otype{Text} and
       @otype{OberonRef} elements, and is only used for direct children of an
       instance of @otype{OberonRef}.  *)
  END;

TYPE
  InlineElement* = POINTER TO InlineElementDesc;
  InlineElementDesc = RECORD [ABSTRACT]
    (ElementDesc)
    nextInline-: InlineElement;
  END;

TYPE
  BlockElement* = POINTER TO BlockElementDesc;
  BlockElementDesc = RECORD [ABSTRACT]
    (ElementDesc)
    nextBlock-: BlockElement;
    padAfter-: BOOLEAN;
  END;

TYPE
  Document* = POINTER TO DocumentDesc;
  DocumentDesc = RECORD
    (Storable.ObjectDesc)
    blockList-: BlockElement;
    summary-: InlineElement;
    decoration-: Decoration.Decoration;
    firstColumn-: LONGINT;
    usedImportsList-: ArrayList.ArrayList;
    (**This list is filled with import declarations that are used by
       @oproc{*OOC:Doc:ResolveRef.Resolve} to resolve module names in reference
       commands.  If no such references were found, this field stays
       @code{NIL}.  The list contains instances of
       @otype{*OOC:SymbolTable.Import}.  *)
  END;


TYPE
  InlineList* = POINTER TO InlineListDesc;
  InlineListDesc = RECORD
    head-, tail-: InlineElement;
  END;

TYPE
  BlockList* = POINTER TO BlockListDesc;
  BlockListDesc = RECORD
    head-, tail-: BlockElement;
  END;


(* Inline Elements
   ------------------------------------------------------------------------ *)

CONST
  glyphBullet* = 0;
  glyphDots* = 1;
  glyphMinus* = 2;
  glyphEmDash* = 3;
  glyphResult* = 4;
  glyphLeftQuot* = 5;
  glyphRightQuot* = 6;
  
TYPE
  Glyph* = POINTER TO GlyphDesc;
  GlyphDesc = RECORD
    (InlineElementDesc)
    code-: LONGINT;
  END;

TYPE
  String* = Decoration.String;
  Text* = POINTER TO TextDesc;
  TextDesc = RECORD
    (InlineElementDesc)
    string-: String;
  END;

CONST
  markAsIs* = 0;
  markCite* = 1;
  markCode* = 2;
  markCommand* = 3;
  markDfn* = 4;
  markEmph* = 5;
  markFile* = 6;
  markKbd* = 7;
  markSamp* = 8;
  markStrong* = 9;
  markVar* = 10;
  markUrl* = 11;
  markOberonModule* = 12;
  markOberonConst* = 13;
  markOberonField* = 14;
  markOberonParam* = 15;
  markOberonProc* = 16;
  markOberonType* = 17;
  markOberonVar* = 18;
  
TYPE
  MarkedInline* = POINTER TO MarkedInlineDesc;
  MarkedInlineDesc = RECORD
    (InlineElementDesc)
    mark-: LONGINT;
    inlineText-: InlineElement;
  END;

TYPE
  OberonRef* = POINTER TO OberonRefDesc;
  OberonRefDesc = RECORD
    (MarkedInlineDesc)
    target-: Storable.Object;    (* is Sym.Declaration *)
    externalModule-,
    externalId-: InputBuffer.CharArray;
    (* either target or (externalModule, externalId) are NIL; these fields
       are filled in by @oproc{OOC:Doc:ResolveRef.Resolve} *)
  END;

TYPE
  Email* = POINTER TO EmailDesc;
  EmailDesc = RECORD
    (InlineElementDesc)
    address-: InlineElement;
    displayed-: InlineElement;
  END;

TYPE
  Uref* = POINTER TO UrefDesc;
  UrefDesc = RECORD
    (InlineElementDesc)
    url-: InlineElement;
    text-: InlineElement;
    replacement-: InlineElement;
  END;

(* Block Elements
   ------------------------------------------------------------------------ *)

TYPE
  Paragraph* = POINTER TO ParagraphDesc;
  ParagraphDesc = RECORD
    (BlockElementDesc)
    inlineText-: InlineElement;
    noIndent-: BOOLEAN;
  END;

TYPE
  Example* = POINTER TO ExampleDesc;
  ExampleDesc = RECORD
    (BlockElementDesc)
    inlineText-: InlineElement;
  END;

TYPE
  PreCond* = POINTER TO PreCondDesc;
  PreCondDesc = RECORD
    (BlockElementDesc)
    blockList-: BlockElement;
  END;

TYPE
  PostCond* = POINTER TO PostCondDesc;
  PostCondDesc = RECORD
    (BlockElementDesc)
    blockList-: BlockElement;
  END;

TYPE
  Item* = POINTER TO ItemDesc;
  ItemDesc = RECORD
    (BlockElementDesc)
    blockList-: BlockElement;
  END;

TYPE
  Itemize* = POINTER TO ItemizeDesc;
  ItemizeDesc = RECORD
    (BlockElementDesc)
    mark-: InlineElement;
    text-: Item;
    itemList-: BlockElement;
  END;

CONST
  enumNumber* = 0;
  enumLowercase* = 1;
  enumUppercase* = 2;
  
TYPE
  Enumerate* = POINTER TO EnumerateDesc;
  EnumerateDesc = RECORD
    (BlockElementDesc)
    mode-: SHORTINT;
    start-: LONGINT;
    text-: Item;
    itemList-: BlockElement;
  END;

TYPE
  FirstColumn* = POINTER TO FirstColumnDesc;
  FirstColumnDesc = RECORD
    (BlockElementDesc)
    inlineText-: InlineElement;
  END;

TYPE
  TableRow* = POINTER TO TableRowDesc;
  TableRowDesc = RECORD
    (BlockElementDesc)
    firstColumnList-: BlockElement;
    item-: Item;
  END;

TYPE
  Table* = POINTER TO TableDesc;
  TableDesc = RECORD
    (BlockElementDesc)
    rowList-: BlockElement;
  END;


PROCEDURE SetPosition* (VAR pos: Position; char: InputBuffer.CharPos;
                        line, column: LONGINT);
  BEGIN
    pos. char := char;
    pos. line := line;
    pos. column := column
  END SetPosition;



PROCEDURE InitElement (e: Element);
  BEGIN
    e. pos. char := -1;
    e. pos. line := -1;
    e. pos. column := -1;
  END InitElement;

PROCEDURE (e: Element) [ABSTRACT] NodeName* (VAR name: ARRAY OF CHAR);
  END NodeName;

PROCEDURE (e: Element) [ABSTRACT] Normalize*;
  END Normalize;

PROCEDURE (e: Element) Store* (w: Storable.Writer) RAISES IO.Error;
  BEGIN
    (* field `pos' is not stored, and set to the default value on import *)
  END Store;

PROCEDURE (e: Element) Load* (r: Storable.Reader) RAISES IO.Error;
  BEGIN
    InitElement (e);                     (* set `pos' to default value *)
  END Load;



PROCEDURE MergeInline* (VAR dest: InlineElement; src: InlineElement);
  VAR
    i: InlineElement;
  BEGIN
    IF (dest = NIL) THEN
      dest := src
    ELSE
      i := dest;
      WHILE (i. nextInline # NIL) DO
        i := i. nextInline
      END;
      i. nextInline := src
    END
  END MergeInline;

PROCEDURE InitInlineElement (e: InlineElement);
  BEGIN
    InitElement (e);
    e. nextInline := NIL
  END InitInlineElement;

PROCEDURE (e: InlineElement) StripHeadWS;
  END StripHeadWS;

PROCEDURE (e: InlineElement) StripTailWS;
  END StripTailWS;

PROCEDURE (e: InlineElement) Store* (w: Storable.Writer) RAISES IO.Error;
  BEGIN
    e. Store^ (w);
    w. WriteObject (e. nextInline)
  END Store;

PROCEDURE (e: InlineElement) Load* (r: Storable.Reader) RAISES IO.Error;
  VAR
    obj: Object.Object;
  BEGIN
    e. Load^ (r);
    r. ReadObject (obj);
    IF (obj = NIL) THEN
      e. nextInline := NIL
    ELSE
      e. nextInline := obj(InlineElement)
    END
  END Load;



PROCEDURE InitBlockElement (e: BlockElement; padAfter: BOOLEAN);
  BEGIN
    InitElement (e);
    e. nextBlock := NIL;
    e. padAfter := padAfter
  END InitBlockElement;

PROCEDURE (e: BlockElement) Store* (w: Storable.Writer) RAISES IO.Error;
  BEGIN
    e. Store^ (w);
    w. WriteObject (e. nextBlock);
    w. WriteBool (e. padAfter)
  END Store;

PROCEDURE (e: BlockElement) Load* (r: Storable.Reader) RAISES IO.Error;
  VAR
    obj: Object.Object;
  BEGIN
    e. Load^ (r);
    r. ReadObject (obj);
    IF (obj = NIL) THEN
      e. nextBlock := NIL
    ELSE
      e. nextBlock := obj(BlockElement)
    END;
    r. ReadBool (e. padAfter)
  END Load;




(* some helper functions and methods:
   ------------------------------------------------------------------------ *)
   
PROCEDURE NormalizeBlockList (blockList: BlockElement);
  VAR
    block: BlockElement;
  BEGIN
    block := blockList;
    WHILE (block # NIL) DO
      block. Normalize;
      block := block. nextBlock
    END
  END NormalizeBlockList;

PROCEDURE NoPadLastElement (list: BlockElement);
  BEGIN
    IF (list # NIL) THEN
      WHILE (list. nextBlock # NIL) DO
        list := list. nextBlock
      END;
      list. padAfter := FALSE
    END
  END NoPadLastElement;
  


PROCEDURE NewInlineList* (): InlineList;
  VAR
    il: InlineList;
  BEGIN
    NEW (il);
    il. head := NIL;
    il. tail := NIL;
    RETURN il
  END NewInlineList;

PROCEDURE (il: InlineList) Append* (inlineElement: InlineElement);
  BEGIN
    inlineElement. nextInline := NIL;
    IF (il. head = NIL) THEN
      il. head := inlineElement
    ELSE
      il. tail. nextInline := inlineElement
    END;
    il. tail := inlineElement
  END Append;

PROCEDURE NewBlockList* (): BlockList;
  VAR
    bl: BlockList;
  BEGIN
    NEW (bl);
    bl. head := NIL;
    bl. tail := NIL;
    RETURN bl
  END NewBlockList;

PROCEDURE (bl: BlockList) Append* (inlineElement: BlockElement);
  BEGIN
    inlineElement. nextBlock := NIL;
    IF (bl. head = NIL) THEN
      bl. head := inlineElement
    ELSE
      bl. tail. nextBlock := inlineElement
    END;
    bl. tail := inlineElement
  END Append;


PROCEDURE NormalizeInlineList (VAR blockList: InlineElement);
  VAR
    i, prev: InlineElement;
  BEGIN
    prev := NIL;
    i := blockList;
    WHILE (i # NIL) DO
      i. Normalize;
      IF (i IS Text) & (i(Text). string^ = "") THEN
        (* remove text fragment, that has been reduced to the empty string;
           NOTE: for this to work, you must strip any whitespace from inline
           text _before_ calling `Normalize' on it *)
        IF (prev = NIL) THEN
          blockList := i. nextInline
        ELSE
          prev. nextInline := i. nextInline
        END
      ELSE
        prev := i
      END;
      i := i. nextInline
    END
  END NormalizeInlineList;

PROCEDURE LastInlineElement (inlineList: InlineElement): InlineElement;
  VAR
    last: InlineElement;
  BEGIN
    last := inlineList;
    WHILE (last. nextInline # NIL) DO
      last := last. nextInline
    END;
    RETURN last
  END LastInlineElement;

PROCEDURE LastBlockElement (blockList: BlockElement): BlockElement;
  VAR
    last: BlockElement;
  BEGIN
    last := blockList;
    WHILE (last. nextBlock # NIL) DO
      last := last. nextBlock
    END;
    RETURN last
  END LastBlockElement;

PROCEDURE NormalizeArg (inlineText: InlineElement);
  VAR
    last: InlineElement;
  BEGIN
    IF (inlineText # NIL) THEN
      inlineText. StripHeadWS;
      last := LastInlineElement (inlineText);
      last. StripTailWS;
      NormalizeInlineList (inlineText)
    END
  END NormalizeArg;

PROCEDURE StripInlineListWS (inlineList: InlineElement);
  VAR
    last: InlineElement;
  BEGIN
    IF (inlineList # NIL) THEN
      inlineList. StripHeadWS;
      last := LastInlineElement (inlineList);
      last. StripTailWS
    END
  END StripInlineListWS;

(* ------------------------------------------------------------------------ *)

PROCEDURE InitGlyph (glyph: Glyph; glyphCode: LONGINT);
  BEGIN
    InitInlineElement (glyph);
    glyph. code := glyphCode
  END InitGlyph;

PROCEDURE NewGlyph* (glyphCode: LONGINT): Glyph;
  VAR
    glyph: Glyph;
  BEGIN
    NEW (glyph);
    InitGlyph (glyph, glyphCode);
    RETURN glyph
  END NewGlyph;

PROCEDURE (glyph: Glyph) NodeName* (VAR name: ARRAY OF CHAR);
  BEGIN
    CASE glyph. code OF
    | glyphBullet: COPY ("bullet", name)
    | glyphDots: COPY ("dots", name)
    | glyphMinus: COPY ("minus", name)
    | glyphEmDash: COPY ("em-dash", name)
    | glyphResult: COPY ("result", name)
    | glyphLeftQuot: COPY ("left-quote", name)
    | glyphRightQuot: COPY ("right-quote", name)
    END
  END NodeName;

PROCEDURE (glyph: Glyph) Normalize*;
  END Normalize;

PROCEDURE (glyph: Glyph) Store* (w: Storable.Writer) RAISES IO.Error;
  BEGIN
    glyph. Store^ (w);
    w. WriteNum (glyph. code)
  END Store;

PROCEDURE (glyph: Glyph) Load* (r: Storable.Reader) RAISES IO.Error;
  BEGIN
    glyph. Load^ (r);
    r. ReadNum (glyph. code)
  END Load;


PROCEDURE InitText (text: Text; VAR pos: Position; VAR string: ARRAY OF CHAR);
  BEGIN
    InitInlineElement (text);
    text. pos := pos;
    NEW (text. string, Strings.Length (string)+1);
    COPY (string, text. string^)
  END InitText;

PROCEDURE NewText* (VAR string: ARRAY OF CHAR; VAR pos: Position): Text;
  VAR
    text: Text;
  BEGIN
    NEW (text);
    InitText (text, pos, string);
    RETURN text
  END NewText;

PROCEDURE (text: Text) NodeName* (VAR name: ARRAY OF CHAR);
  BEGIN
    COPY ("text", name)
  END NodeName;

PROCEDURE (text: Text) Normalize*;
  VAR
    s, ns: String;
    i, delta, dotExt: LONGINT;
  BEGIN
    (* convert <=" " to space, multiple spaces to single space; two 
       whitespaces are kept after a dot, and "dot<NL>" is converted
       to "dot<SPACE><SPACE>" *)
    s := text. string; i := 0; delta := 0; dotExt := 0;
    WHILE (s[i] # 0X) DO
      IF (s[i] <= " ") THEN
        s[i-delta] := " "; INC (i);
        WHILE (s[i] # 0X) & (s[i] <= " ") DO
          INC (i); INC (delta)
        END
      ELSIF (s[i] = ".") THEN
        s[i-delta] := s[i]; INC (i);
        IF (s[i] # 0X) & (s[i] <= " ") & 
           (s[i+1] # 0X) & (s[i+1] <= " ") THEN
          s[i-delta] := " "; INC (i) (* keep two spaces *)
        ELSIF (s[i] = CharClass.eol) THEN
          (* dot followed by eol: convert to dot plus 2 spaces; because
             this operation can extend the string, it is done in a
             separate step *)
          s[i-delta] := 1X; INC (i); INC (dotExt)
        END
      ELSE
        s[i-delta] := s[i]; INC (i)
      END
    END;
    s[i-delta] := 0X;

    DEC (i, delta);
    IF (i+dotExt >= LEN (s^)) THEN
      NEW (ns, i+dotExt+1);
      text. string := ns
    ELSE
      ns := s
    END;
    WHILE (i >= 0) DO
      IF (s[i] = 1X) THEN
        ns[i+dotExt] := " ";
        DEC (dotExt);
        ns[i+dotExt] := " ";
        DEC (i)
      ELSE
        ns[i+dotExt] := s[i];
        DEC (i)
      END
    END
  END Normalize;

PROCEDURE (text: Text) StripHeadWS;
  VAR
    i: LONGINT;
  BEGIN
    i := 0;
    WHILE (text. string[i] # 0X) & (text. string[i] <= " ") DO
      INC (i)
    END;
    Strings.Delete (text. string^, 0, SHORT (i))
  END StripHeadWS;

PROCEDURE (text: Text) StripTailWS;
  VAR
    i: LONGINT;
  BEGIN
    i := Strings.Length (text. string^);
    WHILE (i # 0) & (text. string[i-1] <= " ") DO
      DEC (i)
    END;
    text. string[i] := 0X
  END StripTailWS;

PROCEDURE (text: Text) Store* (w: Storable.Writer) RAISES IO.Error;
  VAR
    i: LONGINT;
  BEGIN
    text. Store^ (w);
    i := 0;
    WHILE (text. string[i] # 0X) DO
      INC (i)
    END;
    w. WriteNum (i);
    w. WriteString (text. string^)
  END Store;

PROCEDURE (text: Text) Load* (r: Storable.Reader) RAISES IO.Error;
  VAR
    len: LONGINT;
  BEGIN
    text. Load^ (r);
    r. ReadNum (len);
    NEW (text. string, len+1);
    r. ReadString (text. string^)
  END Load;


PROCEDURE InitMarkedInline (mi: MarkedInline;
                            mark: LONGINT; inlineText: InlineElement);
  BEGIN
    InitInlineElement (mi);
    mi. mark := mark;
    mi. inlineText := inlineText
  END InitMarkedInline;

PROCEDURE NewMarkedInline* (mark: LONGINT; inlineText: InlineElement): MarkedInline;
  VAR
    mi: MarkedInline;
  BEGIN
    NEW (mi);
    InitMarkedInline (mi, mark, inlineText);
    RETURN mi
  END NewMarkedInline;

PROCEDURE (mi: MarkedInline) NodeName* (VAR name: ARRAY OF CHAR);
  BEGIN
    CASE mi. mark OF
    | markAsIs: COPY ("asis", name)
    | markCite: COPY ("cite", name)
    | markCode: COPY ("code", name)
    | markCommand: COPY ("command", name)
    | markDfn: COPY ("dfn", name)
    | markEmph: COPY ("emph", name)
    | markFile: COPY ("file", name)
    | markKbd: COPY ("kbd", name)
    | markSamp: COPY ("samp", name)
    | markStrong: COPY ("strong", name)
    | markVar: COPY ("var", name)
    | markUrl: COPY ("url", name)
    | markOberonModule: COPY ("oberon-module", name)
    | markOberonConst: COPY ("oberon-const", name)
    | markOberonField: COPY ("oberon-field", name)
    | markOberonParam: COPY ("oberon-param", name)
    | markOberonProc: COPY ("oberon-proc", name)
    | markOberonType: COPY ("oberon-type", name)
    | markOberonVar: COPY ("oberon-var", name)
    END
  END NodeName;

PROCEDURE (mi: MarkedInline) Normalize*;
  BEGIN
    NormalizeInlineList (mi. inlineText)
  END Normalize;

PROCEDURE (mi: MarkedInline) StripHeadWS;
  BEGIN
    mi. inlineText. StripHeadWS
  END StripHeadWS;

PROCEDURE (mi: MarkedInline) StripTailWS;
  VAR
    last: InlineElement;
  BEGIN
    last := LastInlineElement (mi. inlineText);
    last. StripTailWS
  END StripTailWS;

PROCEDURE (mi: MarkedInline) Store* (w: Storable.Writer) RAISES IO.Error;
  BEGIN
    mi. Store^ (w);
    w. WriteNum (mi. mark);
    w. WriteObject (mi. inlineText)
  END Store;

PROCEDURE (mi: MarkedInline) Load* (r: Storable.Reader) RAISES IO.Error;
  VAR
    obj: Object.Object;
  BEGIN
    mi. Load^ (r);
    r. ReadNum (mi. mark);
    r. ReadObject (obj);
    IF (obj = NIL) THEN
      mi. inlineText := NIL
    ELSE
      mi. inlineText := obj(InlineElement)
    END
  END Load;


PROCEDURE InitOberonRef (or: OberonRef;
                         mark: LONGINT; inlineText: InlineElement;
                         target: Storable.Object);
  BEGIN
    InitMarkedInline (or, mark, inlineText);
    or. target := target;
    or. externalModule := NIL;
    or. externalId := NIL;
  END InitOberonRef;

PROCEDURE NewOberonRef* (mark: LONGINT; inlineText: InlineElement;
                         target: Storable.Object): MarkedInline;
  VAR
    or: OberonRef;
  BEGIN
    NEW (or);
    InitOberonRef (or, mark, inlineText, target);
    RETURN or
  END NewOberonRef;

PROCEDURE (or: OberonRef) SetTarget* (targetDecl: Storable.Object);
  BEGIN
    or. target := targetDecl
  END SetTarget;

PROCEDURE (or: OberonRef) SetExternalTarget* (module, id: InputBuffer.CharArray);
  BEGIN
    or. externalModule := module;
    or. externalId := id
  END SetExternalTarget;

PROCEDURE (or: OberonRef) Store* (w: Storable.Writer) RAISES IO.Error;
  BEGIN
    or. Store^ (w);
    (* don't store target, externalModule, or externalId *)
  END Store;

PROCEDURE (or: OberonRef) Load* (r: Storable.Reader) RAISES IO.Error;
  BEGIN
    or. Load^ (r);
    or. target := NIL;
    or. externalModule := NIL;
    or. externalId := NIL
  END Load;


PROCEDURE InitEmail (email: Email; address, displayed: InlineElement);
  BEGIN
    InitInlineElement (email);
    email. address := address;
    email. displayed := displayed
  END InitEmail;

PROCEDURE NewEmail* (address, displayed: InlineElement): Email;
  VAR
    email: Email;
  BEGIN
    NEW (email);
    InitEmail (email, address, displayed);
    RETURN email
  END NewEmail;

PROCEDURE (email: Email) NodeName* (VAR name: ARRAY OF CHAR);
  BEGIN
    COPY ("email", name)
  END NodeName;

PROCEDURE (email: Email) Normalize*;
  BEGIN
    NormalizeArg (email. address);
    NormalizeArg (email. displayed)
  END Normalize;

PROCEDURE (email: Email) Store* (w: Storable.Writer) RAISES IO.Error;
  BEGIN
    email. Store^ (w);
    w. WriteObject (email. address);
    w. WriteObject (email. displayed)
  END Store;

PROCEDURE (email: Email) Load* (r: Storable.Reader) RAISES IO.Error;
  VAR
    obj: Object.Object;
  BEGIN
    email. Load^ (r);
    r. ReadObject (obj);
    IF (obj = NIL) THEN
      email. address := NIL
    ELSE
      email. address := obj(InlineElement)
    END;
    r. ReadObject (obj);
    IF (obj = NIL) THEN
      email. displayed := NIL
    ELSE
      email. displayed := obj(InlineElement)
    END
  END Load;


PROCEDURE InitUref (uref: Uref; url, text, replacement: InlineElement);
  BEGIN
    InitInlineElement (uref);
    uref. url := url;
    uref. text := text;
    uref. replacement := replacement
  END InitUref;

PROCEDURE NewUref* (url, text, replacement: InlineElement): Uref;
  VAR
    uref: Uref;
  BEGIN
    NEW (uref);
    InitUref (uref, url, text, replacement);
    RETURN uref
  END NewUref;

PROCEDURE (uref: Uref) NodeName* (VAR name: ARRAY OF CHAR);
  BEGIN
    COPY ("uref", name)
  END NodeName;

PROCEDURE (uref: Uref) Normalize*;
  BEGIN
    NormalizeArg (uref. url);
    NormalizeArg (uref. text);
    NormalizeArg (uref. replacement)
  END Normalize;

PROCEDURE (uref: Uref) Store* (w: Storable.Writer) RAISES IO.Error;
  BEGIN
    uref. Store^ (w);
    w. WriteObject (uref. url);
    w. WriteObject (uref. text);
    w. WriteObject (uref. replacement);
  END Store;

PROCEDURE (uref: Uref) Load* (r: Storable.Reader) RAISES IO.Error;
  VAR
    obj: Object.Object;
  BEGIN
    uref. Load^ (r);
    r. ReadObject (obj);
    IF (obj = NIL) THEN
      uref. url := NIL
    ELSE
      uref. url := obj(InlineElement)
    END;
    r. ReadObject (obj);
    IF (obj = NIL) THEN
      uref. text := NIL
    ELSE
      uref. text := obj(InlineElement)
    END;
    r. ReadObject (obj);
    IF (obj = NIL) THEN
      uref. replacement := NIL
    ELSE
      uref. replacement := obj(InlineElement)
    END;
  END Load;


PROCEDURE InitParagraph (p: Paragraph; padAfter: BOOLEAN; inlineText: InlineElement; noIndent: BOOLEAN);
  BEGIN
    InitBlockElement (p, padAfter);
    p. inlineText := inlineText;
    p. noIndent := noIndent
  END InitParagraph;

PROCEDURE NewParagraph* (padAfter: BOOLEAN; inlineText: InlineElement; noIndent: BOOLEAN): Paragraph;
  VAR
    p: Paragraph;
  BEGIN
    NEW (p);
    InitParagraph (p, padAfter, inlineText, noIndent);
    RETURN p
  END NewParagraph;

PROCEDURE (p: Paragraph) NodeName* (VAR name: ARRAY OF CHAR);
  BEGIN
    COPY ("p", name)
  END NodeName;

PROCEDURE (p: Paragraph) Normalize*;
  BEGIN
    StripInlineListWS (p. inlineText);
    NormalizeInlineList (p. inlineText)
  END Normalize;

PROCEDURE (p: Paragraph) Store* (w: Storable.Writer) RAISES IO.Error;
  BEGIN
    p. Store^ (w);
    w. WriteObject (p. inlineText);
    w. WriteBool (p. noIndent)
  END Store;

PROCEDURE (p: Paragraph) Load* (r: Storable.Reader) RAISES IO.Error;
  VAR
    obj: Object.Object;
  BEGIN
    p. Load^ (r);
    r. ReadObject (obj);
    IF (obj = NIL) THEN
      p. inlineText := NIL
    ELSE
      p. inlineText := obj(InlineElement)
    END;
    r. ReadBool (p. noIndent)
  END Load;


PROCEDURE InitExample (ex: Example; padAfter: BOOLEAN; inlineText: InlineElement);
  BEGIN
    InitBlockElement (ex, padAfter);
    ex. inlineText := inlineText
  END InitExample;

PROCEDURE NewExample* (padAfter: BOOLEAN; inlineText: InlineElement): Example;
  VAR
    ex: Example;
  BEGIN
    NEW (ex);
    InitExample (ex, padAfter, inlineText);
    RETURN ex
  END NewExample;

PROCEDURE (ex: Example) NodeName* (VAR name: ARRAY OF CHAR);
  BEGIN
    COPY ("example", name)
  END NodeName;

PROCEDURE (ex: Example) Normalize*;
  END Normalize;

PROCEDURE (ex: Example) Store* (w: Storable.Writer) RAISES IO.Error;
  BEGIN
    ex. Store^ (w);
    w. WriteObject (ex. inlineText)
  END Store;

PROCEDURE (ex: Example) Load* (r: Storable.Reader) RAISES IO.Error;
  VAR
    obj: Object.Object;
  BEGIN
    ex. Load^ (r);
    r. ReadObject (obj);
    IF (obj = NIL) THEN
      ex. inlineText := NIL
    ELSE
      ex. inlineText := obj(InlineElement)
    END
  END Load;


PROCEDURE InitPreCond (pc: PreCond; padAfter: BOOLEAN; blockList: BlockElement);
  BEGIN
    InitBlockElement (pc, padAfter);
    pc. blockList := blockList
  END InitPreCond;

PROCEDURE NewPreCond* (padAfter: BOOLEAN; blockList: BlockElement): PreCond;
  VAR
    pc: PreCond;
  BEGIN
    NEW (pc);
    InitPreCond (pc, padAfter, blockList);
    RETURN pc
  END NewPreCond;

PROCEDURE (pc: PreCond) NodeName* (VAR name: ARRAY OF CHAR);
  BEGIN
    COPY ("pre-cond", name)
  END NodeName;

PROCEDURE (pc: PreCond) Normalize*;
  BEGIN
    NormalizeBlockList (pc. blockList)
  END Normalize;

PROCEDURE (pc: PreCond) Store* (w: Storable.Writer) RAISES IO.Error;
  BEGIN
    pc. Store^ (w);
    w. WriteObject (pc. blockList)
  END Store;

PROCEDURE (pc: PreCond) Load* (r: Storable.Reader) RAISES IO.Error;
  VAR
    obj: Object.Object;
  BEGIN
    pc. Load^ (r);
    r. ReadObject (obj);
    IF (obj = NIL) THEN
      pc. blockList := NIL
    ELSE
      pc. blockList := obj(BlockElement)
    END
  END Load;


PROCEDURE InitPostCond (pc: PostCond; padAfter: BOOLEAN; blockList: BlockElement);
  BEGIN
    InitBlockElement (pc, padAfter);
    pc. blockList := blockList
  END InitPostCond;

PROCEDURE NewPostCond* (padAfter: BOOLEAN; blockList: BlockElement): PostCond;
  VAR
    pc: PostCond;
  BEGIN
    NEW (pc);
    InitPostCond (pc, padAfter, blockList);
    RETURN pc
  END NewPostCond;

PROCEDURE (pc: PostCond) NodeName* (VAR name: ARRAY OF CHAR);
  BEGIN
    COPY ("post-cond", name)
  END NodeName;

PROCEDURE (pc: PostCond) Normalize*;
  BEGIN
    NormalizeBlockList (pc. blockList)
  END Normalize;

PROCEDURE (pc: PostCond) Store* (w: Storable.Writer) RAISES IO.Error;
  BEGIN
    pc. Store^ (w);
    w. WriteObject (pc. blockList)
  END Store;

PROCEDURE (pc: PostCond) Load* (r: Storable.Reader) RAISES IO.Error;
  VAR
    obj: Object.Object;
  BEGIN
    pc. Load^ (r);
    r. ReadObject (obj);
    IF (obj = NIL) THEN
      pc. blockList := NIL
    ELSE
      pc. blockList := obj(BlockElement)
    END
  END Load;


PROCEDURE InitItem (item: Item; padAfter: BOOLEAN; blockList: BlockElement);
  BEGIN
    InitBlockElement (item, padAfter);
    item. blockList := blockList
  END InitItem;

PROCEDURE NewItem* (padAfter: BOOLEAN; blockList: BlockElement): Item;
  VAR
    item: Item;
  BEGIN
    NEW (item);
    InitItem (item, padAfter, blockList);
    RETURN item
  END NewItem;

PROCEDURE (item: Item) NodeName* (VAR name : ARRAY OF CHAR);
  BEGIN
    COPY ("item", name)
  END NodeName;

PROCEDURE (item: Item) Normalize*;
  BEGIN
    NormalizeBlockList (item. blockList);
    NoPadLastElement (item. blockList);
    item. padAfter := TRUE
  END Normalize;

PROCEDURE (item: Item) Store* (w: Storable.Writer) RAISES IO.Error;
  BEGIN
    item. Store^ (w);
    w. WriteObject (item. blockList)
  END Store;

PROCEDURE (item: Item) Load* (r: Storable.Reader) RAISES IO.Error;
  VAR
    obj: Object.Object;
  BEGIN
    item. Load^ (r);
    r. ReadObject (obj);
    IF (obj = NIL) THEN
      item. blockList := NIL
    ELSE
      item. blockList := obj(BlockElement)
    END
  END Load;


PROCEDURE InitItemize (i: Itemize; padAfter: BOOLEAN; mark: InlineElement;
                       text: Item; itemList: BlockElement);
  BEGIN
    InitBlockElement (i, padAfter);
    i. mark := mark;
    i. text := text;
    i. itemList := itemList
  END InitItemize;

PROCEDURE NewItemize* (padAfter: BOOLEAN; mark: InlineElement;
                       text: Item; itemList: BlockElement): Itemize;
  VAR
    i: Itemize;
  BEGIN
    NEW (i);
    InitItemize (i, padAfter, mark, text, itemList);
    RETURN i
  END NewItemize;

PROCEDURE (i: Itemize) NodeName* (VAR name : ARRAY OF CHAR);
  BEGIN
    COPY ("itemize", name)
  END NodeName;

PROCEDURE (i: Itemize) Normalize*;
  BEGIN
    StripInlineListWS (i. mark);
    NormalizeInlineList (i. mark);
    IF (i. text # NIL) THEN
      i. text. Normalize
    END;
    NormalizeBlockList (i. itemList);
    NoPadLastElement (i. itemList)
  END Normalize;

PROCEDURE (i: Itemize) Store* (w: Storable.Writer) RAISES IO.Error;
  BEGIN
    i. Store^ (w);
    w. WriteObject (i. mark);
    w. WriteObject (i. text);
    w. WriteObject (i. itemList)
  END Store;

PROCEDURE (i: Itemize) Load* (r: Storable.Reader) RAISES IO.Error;
  VAR
    obj: Object.Object;
  BEGIN
    i. Load^ (r);
    r. ReadObject (obj);
    IF (obj = NIL) THEN
      i. mark := NIL
    ELSE
      i. mark := obj(InlineElement)
    END;
    r. ReadObject (obj);
    IF (obj = NIL) THEN
      i. text := NIL
    ELSE
      i. text := obj(Item)
    END;
    r. ReadObject (obj);
    IF (obj = NIL) THEN
      i. itemList := NIL
    ELSE
      i. itemList := obj(BlockElement)
    END;
  END Load;


PROCEDURE InitEnumerate (e: Enumerate; padAfter: BOOLEAN;
                         mode: SHORTINT; start: LONGINT;
                         text: Item; itemList: BlockElement);
  BEGIN
    InitBlockElement (e, padAfter);
    e. mode := mode;
    e. start := start;
    e. text := text;
    e. itemList := itemList
  END InitEnumerate;

PROCEDURE NewEnumerate* (padAfter: BOOLEAN; mode: SHORTINT; start: LONGINT;
                         text: Item; itemList: BlockElement): Enumerate;
  VAR
    e: Enumerate;
  BEGIN
    NEW (e);
    InitEnumerate (e, padAfter, mode, start, text, itemList);
    RETURN e;
  END NewEnumerate;

PROCEDURE (e: Enumerate) NodeName* (VAR name : ARRAY OF CHAR);
  BEGIN
    COPY ("enumerate", name)
  END NodeName;

PROCEDURE (e: Enumerate) Normalize*;
  BEGIN
    IF (e. text # NIL) THEN
      e. text. Normalize
    END;
    NormalizeBlockList (e. itemList);
    NoPadLastElement (e. itemList)
  END Normalize;

PROCEDURE (e: Enumerate) Store* (w: Storable.Writer) RAISES IO.Error;
  BEGIN
    e. Store^ (w);
    w. WriteSInt (e. mode);
    w. WriteNum (e. start);
    w. WriteObject (e. text);
    w. WriteObject (e. itemList)
  END Store;

PROCEDURE (e: Enumerate) Load* (r: Storable.Reader) RAISES IO.Error;
  VAR
    obj: Object.Object;
  BEGIN
    e. Load^ (r);
    r. ReadSInt (e. mode);
    r. ReadNum (e. start);
    r. ReadObject (obj);
    IF (obj = NIL) THEN
      e. text := NIL
    ELSE
      e. text := obj(Item)
    END;
    r. ReadObject (obj);
    IF (obj = NIL) THEN
      e. itemList := NIL
    ELSE
      e. itemList := obj(BlockElement)
    END;
  END Load;


PROCEDURE InitFirstColumn (fc: FirstColumn; padAfter: BOOLEAN; inlineText: InlineElement);
  BEGIN
    InitBlockElement (fc, padAfter);
    fc. inlineText := inlineText
  END InitFirstColumn;

PROCEDURE NewFirstColumn* (padAfter: BOOLEAN; inlineText: InlineElement): FirstColumn;
  VAR
    fc: FirstColumn;
  BEGIN
    NEW (fc);
    InitFirstColumn (fc, padAfter, inlineText);
    RETURN fc
  END NewFirstColumn;

PROCEDURE (fc: FirstColumn) NodeName* (VAR name: ARRAY OF CHAR);
  BEGIN
    COPY ("table-first-column", name)
  END NodeName;

PROCEDURE (fc: FirstColumn) Normalize*;
  BEGIN
    StripInlineListWS (fc. inlineText);
    NormalizeInlineList (fc. inlineText);
    fc. padAfter := FALSE
  END Normalize;

PROCEDURE (fc: FirstColumn) Store* (w: Storable.Writer) RAISES IO.Error;
  BEGIN
    fc. Store^ (w);
    w. WriteObject (fc. inlineText)
  END Store;

PROCEDURE (fc: FirstColumn) Load* (r: Storable.Reader) RAISES IO.Error;
  VAR
    obj: Object.Object;
  BEGIN
    fc. Load^ (r);
    r. ReadObject (obj);
    IF (obj = NIL) THEN
      fc. inlineText := NIL
    ELSE
      fc. inlineText := obj(InlineElement)
    END
  END Load;


PROCEDURE InitTableRow (tr: TableRow; padAfter: BOOLEAN;
                        firstColumnList: BlockElement; item: Item);
  BEGIN
    InitBlockElement (tr, padAfter);
    tr. firstColumnList := firstColumnList;
    tr. item := item;
  END InitTableRow;

PROCEDURE NewTableRow* (padAfter: BOOLEAN;
                        firstColumnList: BlockElement; item: Item): TableRow;
  VAR
    tr: TableRow;
  BEGIN
    NEW (tr);
    InitTableRow (tr, padAfter, firstColumnList, item);
    RETURN tr
  END NewTableRow;

PROCEDURE (tr: TableRow) NodeName* (VAR name : ARRAY OF CHAR);
  BEGIN
    COPY ("table-row", name)
  END NodeName;

PROCEDURE (tr: TableRow) Normalize*;
  BEGIN
    NormalizeBlockList (tr. firstColumnList);
    tr. item. Normalize;
    tr. item. padAfter := FALSE;
    tr. padAfter := TRUE
  END Normalize;

PROCEDURE (tr: TableRow) Store* (w: Storable.Writer) RAISES IO.Error;
  BEGIN
    tr. Store^ (w);
    w. WriteObject (tr. firstColumnList);
    w. WriteObject (tr. item);
  END Store;

PROCEDURE (tr: TableRow) Load* (r: Storable.Reader) RAISES IO.Error;
  VAR
    obj: Object.Object;
  BEGIN
    tr. Load^ (r);
    r. ReadObject (obj);
    IF (obj = NIL) THEN
      tr. firstColumnList := NIL
    ELSE
      tr. firstColumnList := obj(BlockElement)
    END;
    r. ReadObject (obj);
    IF (obj = NIL) THEN
      tr. item := NIL
    ELSE
      tr. item := obj(Item)
    END;
  END Load;


PROCEDURE InitTable (t: Table; padAfter: BOOLEAN; rowList: BlockElement);
  BEGIN
    InitBlockElement (t, padAfter);
    t. rowList := rowList
  END InitTable;

PROCEDURE NewTable* (padAfter: BOOLEAN; rowList: BlockElement): Table;
  VAR
    t: Table;
  BEGIN
    NEW (t);
    InitTable (t, padAfter, rowList);
    RETURN t
  END NewTable;

PROCEDURE (t: Table) NodeName* (VAR name: ARRAY OF CHAR);
  BEGIN
    COPY ("table", name)
  END NodeName;

PROCEDURE (t: Table) Normalize*;
  BEGIN
    NormalizeBlockList (t. rowList);
    NoPadLastElement (t. rowList)
  END Normalize;

PROCEDURE (t: Table) Store* (w: Storable.Writer) RAISES IO.Error;
  BEGIN
    t. Store^ (w);
    w. WriteObject (t. rowList)
  END Store;

PROCEDURE (t: Table) Load* (r: Storable.Reader) RAISES IO.Error;
  VAR
    obj: Object.Object;
  BEGIN
    t. Load^ (r);
    r. ReadObject (obj);
    IF (obj = NIL) THEN
      t. rowList := NIL
    ELSE
      t. rowList := obj(BlockElement)
    END
  END Load;


PROCEDURE ExtractSummary (block: BlockElement): InlineElement;
  VAR
    done: BOOLEAN;
  
  PROCEDURE Extract (inlineList: InlineElement): InlineElement;
    VAR
      inline: InlineElement;
      resultList: InlineList;
      newText: Text;
      i: LONGINT;
    
    PROCEDURE EndOfSummary (VAR str: ARRAY OF CHAR): LONGINT;
      BEGIN
        i := 0;
        WHILE (str[i] # 0X) DO
          IF (str[i] = ".") & (str[i+1] = " ") THEN
            RETURN i+1
          END;
          INC (i)
        END;
        RETURN -1
      END EndOfSummary;
    
    BEGIN
      resultList := NewInlineList();
      inline := inlineList;
      WHILE (inline # NIL) & ~done DO
        WITH inline: Glyph DO
          resultList. Append (NewGlyph (inline. code))
        | inline: Text DO
          newText := NewText (inline. string^, inline. pos);
          i := EndOfSummary (newText. string^);
          IF (i >= 0) THEN
            newText. string[i] := 0X;
            done := TRUE
          END;
          resultList. Append (newText)
        | inline: OberonRef DO
          resultList. Append (NewOberonRef (inline. mark,
                                            Extract (inline. inlineText),
                                            inline. target));
          resultList. tail(OberonRef). pos := inline. pos
        | inline: MarkedInline DO
          resultList. Append (NewMarkedInline (inline. mark,
                                               Extract (inline. inlineText)))
        | inline: Email DO
          resultList. Append (NewEmail (inline. address, inline. displayed))
        | inline: Uref DO
          resultList. Append (NewUref (inline. url, inline. text,
                                       inline. replacement))
        END;
        inline := inline. nextInline
      END;
      RETURN resultList. head
    END Extract;
  
  BEGIN
    IF (block # NIL) & (block IS Paragraph) THEN
      done := FALSE;
      RETURN Extract (block(Paragraph). inlineText)
    ELSE
      RETURN NIL
    END
  END ExtractSummary;


PROCEDURE NewDocument* (blockList: BlockElement;
                        decoration: Decoration.Decoration;
                        firstColumn: LONGINT): Document;
  VAR
    d: Document;
  BEGIN
    NEW (d);
    d. blockList := blockList;
    d. summary := NIL;
    d. decoration := decoration;
    d. firstColumn := firstColumn;
    d. usedImportsList := NIL;
    RETURN d
  END NewDocument;

PROCEDURE (d: Document) AddUsedImport* (importDecl: Storable.Object);
  VAR
    i: LONGINT;
  BEGIN
    IF (d. usedImportsList = NIL) THEN
      d. usedImportsList := ArrayList.New (2)
    END;
    FOR i := 0 TO d. usedImportsList. size-1 DO
      IF (d. usedImportsList. array[i] = importDecl) THEN
        RETURN
      END
    END;
    d. usedImportsList. Append (importDecl)
  END AddUsedImport;

PROCEDURE (d: Document) Store* (w: Storable.Writer) RAISES IO.Error;
  BEGIN
    w. WriteObject (d. blockList);
    w. WriteObject (d. summary);
    (* don't store decoration, firstColumn, or usedImportsList *)
  END Store;

PROCEDURE (d: Document) Load* (r: Storable.Reader) RAISES IO.Error;
  VAR
    obj: Object.Object;
  BEGIN
    r. ReadObject (obj);
    IF (obj = NIL) THEN
      d. blockList := NIL
    ELSE
      d. blockList := obj(BlockElement)
    END;
    r. ReadObject (obj);
    IF (obj = NIL) THEN
      d. summary := NIL
    ELSE
      d. summary := obj(InlineElement)
    END;
    d. decoration := NIL;
    d. firstColumn := 0;
    d. usedImportsList := NIL;
  END Load;

PROCEDURE (doc: Document) Normalize*;
  BEGIN
    NormalizeBlockList (doc. blockList);
    doc. summary := ExtractSummary (doc. blockList)
  END Normalize;

PROCEDURE (doc: Document) Merge* (source: Document);
  VAR
    last: BlockElement;
  BEGIN
    IF (doc. blockList = NIL) THEN
      doc. blockList := source. blockList
    ELSE
      last := LastBlockElement (doc. blockList);
      last. nextBlock := source. blockList
    END
  END Merge;

END OOC:Doc.
