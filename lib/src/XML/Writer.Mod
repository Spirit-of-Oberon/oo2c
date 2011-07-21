(*      $Id: Writer.Mod,v 1.11 2003/06/23 20:56:01 mva Exp $   *)
MODULE XML:Writer [OOC_EXTENSIONS];
(*  Support for generating XML documents.
    Copyright (C) 2000-2003  Michael van Acken

    This module is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public License
    as published by the Free Software Foundation; either version 2 of
    the License, or (at your option) any later version.

    This module is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with OOC. If not, write to the Free Software Foundation,
    59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*)

(**
   Planned changes for future releases:

   @itemize @bullet
   @item
   Rename @oproc{Writer.AttrInt} to @samp{AttrLInt}.

   @item
   Rename @samp{*I} methods to @samp{*Region}.

   @item
   Provide methods for writing unquoted text (inherited methods from
   @otype{UnicodeBuffer.OutputDesc} are not sufficient, because the writer
   holds state of start tag).
   @end itemize  *)

IMPORT
  Ascii, Strings, LongStrings, IntStr, RealStr, Object, IO, URI,
  Codec := XML:UnicodeCodec, XML:UnicodeBuffer;


TYPE
  Char* = LONGCHAR;
  String = POINTER TO ARRAY OF Char;
  Elements = POINTER TO ARRAY OF
               RECORD
                 name: String;
                 mixedContent: BOOLEAN;
               END;

TYPE
  Writer* = POINTER TO WriterDesc;
  WriterDesc* = RECORD
  (**Note: Output is buffered.  Calling @oproc{Writer.EndOfText} will also
     flush the buffers.  *)
    (UnicodeBuffer.OutputDesc)
    indentLevel: LONGINT;
    indent: LONGINT;
    newLine: ARRAY 3 OF CHAR;
    lenNewLine: LONGINT;
    emptyElementHTML: BOOLEAN;
    baseURI-: URI.HierarchicalURI;
    
    elementStack: Elements;
    lenElementStack: LONGINT;
    doIndent: BOOLEAN;
    openStartTag: BOOLEAN;
    openEmptyTag: BOOLEAN;
  END;


PROCEDURE Init* (w: Writer; 
                 writer: IO.ByteChannel; codecFactory: Codec.Factory;
                 writeBOM: BOOLEAN; indentLevel: LONGINT);
  BEGIN
    UnicodeBuffer.InitOutput (w, TRUE, writer, codecFactory, writeBOM);
    NEW (w. elementStack, 8);
    
    w. indentLevel := indentLevel;
    w. indent := 0;
    w. emptyElementHTML := FALSE;
    w. baseURI := NIL;
    w. newLine := Ascii.lf;
    w. lenNewLine := 1;
    
    w. lenElementStack := 0;
    w. doIndent := FALSE;                (* don't indent first start tag *)
    w. openStartTag := FALSE;
    w. openEmptyTag := FALSE;
  END Init;

PROCEDURE New* (writer: IO.ByteChannel; codecFactory: Codec.Factory;
                writeBOM: BOOLEAN; indentLevel: LONGINT): Writer;
  VAR
    w: Writer;
  BEGIN
    NEW (w);
    Init (w, writer, codecFactory, writeBOM, indentLevel);
    RETURN w
  END New;

(*PROCEDURE (w: Writer) Reset* (writer: Channel.Writer; 
                              codecFactory: Codec.Factory;
                              writeBOM: BOOLEAN);
  BEGIN
    w. Reset^ (writer, codecFactory, writeBOM);
    Init (w, FALSE, writer, codecFactory, writeBOM, w. indentLevel);
  END Reset;*)

PROCEDURE (w: Writer) SetBaseURI* (baseURI: URI.HierarchicalURI);
  BEGIN
    w. baseURI := baseURI
  END SetBaseURI;

PROCEDURE (w: Writer) SetEmptyElementHTML* (html: BOOLEAN);
  BEGIN
    w. emptyElementHTML := html
  END SetEmptyElementHTML;

PROCEDURE (w: Writer) WriteTextDecl* (version, standalone: ARRAY OF CHAR);
  VAR
    encoding: ARRAY 256 OF CHAR;
  BEGIN
    w. Write8 ("<?xml");
    IF (version # "") THEN
      w. Write8 (" version='");
      w. Write8 (version);
      w. Write8 ("'")
    END;
    w. Write8 (" encoding='");
    w. codecFactory. GetEncodingName (encoding);
    w. Write8 (encoding);
    w. Write8 ("'");
    IF (standalone # "") THEN
      w. Write8 (" standalone='");
      w. Write8 (standalone);
      w. Write8 ("'")
    END;
    w. Write8 ("?>");
    w. doIndent := (w. indentLevel >= 0)
  END WriteTextDecl;

PROCEDURE (w: Writer) NewLine*;
  VAR
    i: LONGINT;
  BEGIN
    IF w. doIndent THEN
      w. Write8I (w. newLine, 0, w. lenNewLine);
      FOR i := 1 TO w. indent DO
        w. Write8 (" ")
      END
    END
  END NewLine;


PROCEDURE (w: Writer) CloseStartTag*;
  BEGIN
    ASSERT (w. openStartTag);
    IF w. openEmptyTag THEN
      IF w. emptyElementHTML THEN
        w. Write8 (" />")
      ELSE
        w. Write8 ("/>")
      END;
      w. openEmptyTag := FALSE
    ELSE
      w. Write8 (">")
    END;
    w. openStartTag := FALSE
  END CloseStartTag;


PROCEDURE (w: Writer) WriteI* (str[NO_COPY]: ARRAY OF Char; s, e: LONGINT);
  VAR
    last: LONGINT;
  BEGIN
    IF w. openStartTag THEN w. CloseStartTag END;
    WHILE (s # e) DO
      last := s;
      WHILE (s # e) &
            (str[s] # "&") & (str[s] # "<") & (str[s] # ">") DO
        INC (s)
      END;
      w. Write16I (str, last, s);
      IF (s # e) THEN
        CASE str[s] OF
        | "&": w. Write8 ("&amp;")
        | "<": w. Write8 ("&lt;")
        | ">": w. Write8 ("&gt;")
        END;
        INC (s)
      END
    END
  END WriteI;

PROCEDURE (w: Writer) WriteLatin1I* (str[NO_COPY]: ARRAY OF CHAR;
                                     s, e: LONGINT);
  VAR
    last: LONGINT;
  BEGIN
    IF w. openStartTag THEN w. CloseStartTag END;
    WHILE (s # e) DO
      last := s;
      WHILE (s # e) &
            (str[s] # "&") & (str[s] # "<") & (str[s] # ">") DO
        INC (s)
      END;
      w. Write8I (str, last, s);
      IF (s # e) THEN
        CASE str[s] OF
        | "&": w. Write8 ("&amp;")
        | "<": w. Write8 ("&lt;")
        | ">": w. Write8 ("&gt;")
        END;
        INC (s)
      END
    END
  END WriteLatin1I;

PROCEDURE (w: Writer) Write* (str[NO_COPY]: ARRAY OF Char);
  BEGIN
    w. WriteI (str, 0, LongStrings.Length (str))
  END Write;

PROCEDURE (w: Writer) WriteObject*(obj: Object.Object);
  VAR
    str: STRING;
    str8: Object.String8;
    chars: Object.CharsLatin1;
  BEGIN
    str := obj.ToString();
    str8 := str.ToString8("?");
    chars := str8.CharsLatin1();
    w.WriteLatin1I(chars^, 0, str8.length);
  END WriteObject;

PROCEDURE (w: Writer) WriteLatin1* (str[NO_COPY]: ARRAY OF CHAR);
  BEGIN
    w. WriteLatin1I (str, 0, Strings.Length (str))
  END WriteLatin1;

PROCEDURE (w: Writer) WriteURI* (uri: URI.URI; absolute: BOOLEAN);
  BEGIN
    IF ~absolute THEN
      uri := uri.MakeRelative(w.baseURI);
    END;
    w.WriteObject(uri.ToString())
  END WriteURI;

PROCEDURE (w: Writer) WriteLInt* (value: LONGINT);
  VAR
    val: ARRAY 32 OF CHAR;
  BEGIN
    IntStr.IntToStr (value, val);
    w. WriteLatin1 (val)
  END WriteLInt;

PROCEDURE (w: Writer) WriteRealFix* (real: REAL; k: LONGINT);
  VAR
    val: ARRAY 128 OF CHAR;
  BEGIN
    RealStr.RealToFixed(real, SHORT(k), val);
    w. WriteLatin1 (val)
  END WriteRealFix;

PROCEDURE GetString (str[NO_COPY]: ARRAY OF Char): String;
  VAR
    s: String;
  BEGIN
    NEW (s, LongStrings.Length (str)+1);
    COPY (str, s^);
    RETURN s
  END GetString;

PROCEDURE (w: Writer) StartTag* (name[NO_COPY]: ARRAY OF Char;
                                 mixedContent: BOOLEAN);
  VAR
    new: Elements;
    i: LONGINT;
  BEGIN
    IF w. openStartTag THEN w. CloseStartTag END;
    w. NewLine;
    w. Write8 ("<");
    w. Write16 (name);
    
    IF (w. lenElementStack = LEN (w. elementStack^)) THEN
      NEW (new, w. lenElementStack*2);
      FOR i := 0 TO w. lenElementStack-1 DO
        new[i] := w. elementStack[i]
      END;
      w. elementStack := new
    END;
    w. elementStack[w. lenElementStack]. name := GetString (name);
    w. elementStack[w. lenElementStack]. mixedContent := mixedContent;
    INC (w. lenElementStack);
    w. openStartTag := TRUE;
    
    w. doIndent := (w. indentLevel >= 0) & ~mixedContent;
    IF w. doIndent THEN
      INC (w. indent, w. indentLevel)
    END
  END StartTag;

PROCEDURE (w: Writer) StartTagLatin1* (name[NO_COPY]: ARRAY OF CHAR;
                                       mixedContent: BOOLEAN);
  VAR
    name16: ARRAY 1024 OF Char;
  BEGIN
    COPY (name, name16);
    w. StartTag (name16, mixedContent)
  END StartTagLatin1;

PROCEDURE (w: Writer) EmptyTag* (name[NO_COPY]: ARRAY OF Char);
  BEGIN
    IF w. openStartTag THEN w. CloseStartTag END;
    w. NewLine;
    w. Write8 ("<");
    w. Write16 (name);
    (* no need to push the element name on the stack, because
       we will not have to write out the matching end tag *)
    w. openStartTag := TRUE;
    w. openEmptyTag := TRUE
  END EmptyTag;

PROCEDURE (w: Writer) EmptyTagLatin1* (name[NO_COPY]: ARRAY OF Char);
  VAR
    name16: ARRAY 1024 OF Char;
  BEGIN
    COPY (name, name16);
    w. EmptyTag (name16)
  END EmptyTagLatin1;


PROCEDURE (w: Writer) AttrString* (name[NO_COPY], value[NO_COPY]: ARRAY OF Char);
  VAR
    s, e, last: LONGINT;
  BEGIN
    ASSERT (w. openStartTag);
    w. Write8 (" ");
    w. Write16 (name);
    w. Write8 ("='");
    
    s := 0; e := LongStrings.Length (value);
    WHILE (s # e) DO
      last := s;
      WHILE (s # e) & (value[s] # "'") &
            (value[s] # "&") & (value[s] # "<") & (value[s] # ">") DO
        INC (s)
      END;
      w. Write16I (value, last, s);
      IF (s # e) THEN
        CASE value[s] OF
        | "&": w. Write8 ("&amp;")
        | "<": w. Write8 ("&lt;")
        | ">": w. Write8 ("&gt;")
        | "'": w. Write8 ("&apos;")
        END;
        INC (s)
      END
    END;
    
    w. Write8 ("'")
  END AttrString;

PROCEDURE (w: Writer) AttrStringLatin1* (name[NO_COPY]: ARRAY OF Char;
                                         value[NO_COPY]: ARRAY OF CHAR);
  VAR
    s, e, last: LONGINT;
  BEGIN
    ASSERT (w. openStartTag);
    w. Write8 (" ");
    w. Write16 (name);
    w. Write8 ("='");
    
    s := 0; e := Strings.Length (value);
    WHILE (s # e) DO
      last := s;
      WHILE (s # e) & (value[s] # "'") &
            (value[s] # "&") & (value[s] # "<") & (value[s] # ">") DO
        INC (s)
      END;
      w. Write8I (value, last, s);
      IF (s # e) THEN
        CASE value[s] OF
        | "&": w. Write8 ("&amp;")
        | "<": w. Write8 ("&lt;")
        | ">": w. Write8 ("&gt;")
        | "'": w. Write8 ("&apos;")
        END;
        INC (s)
      END
    END;
    
    w. Write8 ("'")
  END AttrStringLatin1;

PROCEDURE (w: Writer) AttrObject* (name[NO_COPY]: ARRAY OF Char;
                                   value: Object.String);
  VAR
    chars: Object.CharsLatin1;
    s: Object.String;
  BEGIN  (* FIXME... handle wide chars *)
    s := value.ToString8("?");
    chars := s(Object.String8).CharsLatin1();
    w.AttrStringLatin1(name, chars^);
  END AttrObject;

PROCEDURE (w: Writer) AttrInt* (name[NO_COPY]: ARRAY OF Char; value: LONGINT);
  VAR
    val: ARRAY 32 OF CHAR;
  BEGIN
    IntStr.IntToStr (value, val);
    w. AttrStringLatin1 (name, val)
  END AttrInt;

PROCEDURE (w: Writer) AttrBool* (name[NO_COPY]: ARRAY OF Char; value: BOOLEAN);
  BEGIN
    IF value THEN
      w. AttrStringLatin1 (name, "yes")
    ELSE
      w. AttrStringLatin1 (name, "no")
    END
  END AttrBool;

PROCEDURE (w: Writer) AttrURI* (name[NO_COPY]: ARRAY OF Char; uri: URI.URI;
                                absolute: BOOLEAN);
  BEGIN
    ASSERT (w. openStartTag);
    IF ~absolute THEN
      uri := uri. MakeRelative (w. baseURI)
    END;
    w.AttrObject(name, uri.ToString());
  END AttrURI;


PROCEDURE (w: Writer) EndTag*;
  BEGIN
    IF (w. lenElementStack <= 0) THEN
      TRY
        w. Flush;
      CATCH IO.Error:
      END;
      ASSERT (FALSE)
    END;
    
    IF w. doIndent THEN
      DEC (w. indent, w. indentLevel)
    END;
    DEC (w. lenElementStack);
    
    IF w. openEmptyTag THEN              (* preceding element was empty tag *)
      w. CloseStartTag;
      w. NewLine;
      w. Write8 ("</");
      w. Write16 (w. elementStack[w. lenElementStack]. name^);
      w. Write8 (">")
    ELSIF w. openStartTag THEN           (* no content, make empty tag *)
      IF w. emptyElementHTML THEN
        w. Write8 (" />")
      ELSE
        w. Write8 ("/>")
      END;
      w. openStartTag := FALSE
    ELSE                                 (* write end tag *)
      w. NewLine;
      w. Write8 ("</");
      w. Write16 (w. elementStack[w. lenElementStack]. name^);
      w. Write8 (">")
    END;
    
    w. doIndent := (w. indentLevel >= 0);
    IF (w. lenElementStack > 0) THEN
      w. doIndent := w. doIndent &
                     ~(w. elementStack[w. lenElementStack-1]. mixedContent)
    END
  END EndTag;

PROCEDURE (w: Writer) EndOfText*() RAISES IO.Error;
(**Adds final newline to text and flushes all buffers.  *)
  BEGIN
    IF w. openStartTag THEN w. CloseStartTag END;
    w. NewLine;
    w. Flush;
    ASSERT (w. lenElementStack = 0);
  END EndOfText;
  
END XML:Writer.
