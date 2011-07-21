(*      $Id: ParserProtocol.Mod,v 1.3 2003/02/02 17:58:39 mva Exp $   *)
MODULE XML:Builder:ParserProtocol [OOC_EXTENSIONS];
(*  Translates XML document to canonical XML.
    Copyright (C) 2000, 2001, 2003  Michael van Acken

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


IMPORT
  IntStr, IO, URI, URI:Scheme:File,
  Codec := XML:UnicodeCodec, XML:DTD, B := XML:Builder,
  XML:Writer, XML:Locator;


TYPE
  Builder* = POINTER TO BuilderDesc;
  BuilderDesc = RECORD
  (**Writes out the sequence of callbacks initiated by the parser.  Used for
     debugging purposes.  *)
    (B.BuilderDesc)
    w-: Writer.Writer;
    locator-: Locator.Locator;
  END;


PROCEDURE String (w: Writer.Writer; name: ARRAY OF LONGCHAR; string: DTD.String);
  BEGIN
    IF (string # NIL) THEN
      w. StartTag (name, TRUE);
      w. Write (string^);
      w. EndTag
    END
  END String;

PROCEDURE Int (w: Writer.Writer; name: ARRAY OF LONGCHAR; value: LONGINT);
  VAR
    val: ARRAY 32 OF CHAR;
  BEGIN
    w. StartTag (name, TRUE);
    IntStr.IntToStr (value, val);
    w. WriteLatin1 (val);
    w. EndTag
  END Int;

PROCEDURE Boolean (w: Writer.Writer; name: ARRAY OF LONGCHAR; value: BOOLEAN);
  BEGIN
    w. StartTag (name, TRUE);
    IF value THEN
      w. Write ("yes")
    ELSE
      w. Write ("no")
    END;
    w. EndTag
  END Boolean;

PROCEDURE WriteURI (w: Writer.Writer; name: ARRAY OF LONGCHAR; uri: URI.URI);
  BEGIN
    IF (uri # NIL) THEN
      w. StartTag (name, TRUE);
      w. WriteURI (uri, FALSE);
      w. EndTag
    END
  END WriteURI;

PROCEDURE WritePos (b: Builder);
  BEGIN
    b. w. StartTag ("locator", FALSE);
    IF (b. locator. entity. baseURI # NIL) THEN
      Int (b. w, "char-index", b. locator. charIndex);
      Int (b. w, "line", b. locator. line);
      Int (b. w, "column", b. locator. column);
      WriteURI (b. w, "base-uri", b. locator. entity. baseURI)
    END;
    b. w. EndTag
  END WritePos;


PROCEDURE Notation (b: Builder; notation: DTD.Notation; writePos: BOOLEAN);
  VAR
    w: Writer.Writer;
  BEGIN
    IF (notation # NIL) THEN
      w := b. w;
      w. StartTag ("notation", FALSE);
      String (w, "name", notation. name);
      String (w, "system-identifier", notation. system);
      String (w, "public-identifier", notation. public);
      WriteURI (w, "base-uri", notation. baseURI);
      IF writePos THEN
        WritePos (b)
      END;
      w. EndTag
    END
  END Notation;

PROCEDURE Entity (b: Builder; entity: DTD.Entity; writePos: BOOLEAN);
  VAR
    w: Writer.Writer;
  BEGIN
    w := b. w;
    w. StartTag ("entity", FALSE);
    
    w. StartTag ("type", TRUE);
    CASE entity. type OF
    | DTD.entityInternalGeneral: w. WriteLatin1 ("internal general")
    | DTD.entityInternalParameter: w. WriteLatin1 ("internal parameter")
    | DTD.entityExternalGeneral: w. WriteLatin1 ("external general")
    | DTD.entityExternalParameter: w. WriteLatin1 ("external parameter")
    | DTD.entityUnparsed: w. WriteLatin1 ("external general unparsed")
    | DTD.entityDocument: w. WriteLatin1 ("document")
    | DTD.entityExternalDTDSubset: w. WriteLatin1 ("external DTD subset")
    END;
    w. EndTag;
    
    String (w, "name", entity. name);
    WITH entity: DTD.ExternalEntity DO
      String (w, "system-identifier", entity. system);
      String (w, "public-identifier", entity. public);
      WriteURI (w, "base-uri", entity. baseURI);
      String (w, "notation", entity. ndata);
    | entity: DTD.InternalEntity DO
      w. StartTag ("content", TRUE);
      w. WriteI (entity. entityValue^, 0, entity. LengthValue());
      w. EndTag
    END;
    
    IF writePos THEN
      WritePos (b)
    END;
    w. EndTag
  END Entity;

PROCEDURE NamespaceDeclaration (w: Writer.Writer; namespaceDecl: DTD.NamespaceDeclaration);
  BEGIN
    w. StartTag ("namespace-declaration", FALSE);
    String (w, "prefix", namespaceDecl. prefix);
    IF (namespaceDecl. uri # NIL) THEN
      w. StartTag ("namespace-uri", TRUE);
      w. WriteLatin1 (namespaceDecl. uri^);
      w. EndTag
    END;
    w. EndTag
  END NamespaceDeclaration;


PROCEDURE (b: Builder) SetLocator* (locator: Locator.Locator);
  BEGIN
    b. locator := locator
  END SetLocator;

PROCEDURE (b: Builder) StartDocument* (documentEntity: DTD.ExternalEntity);
  BEGIN
    b. w. StartTag ("parser-protocol", FALSE);
    (*b. w. AttrURI ("xml:base", b. w. baseURI, TRUE);
        this breaks the simple minded diff tests, so I leave it out for now *)
    b. w. StartTag ("start-document", FALSE);
    Entity (b, documentEntity, FALSE);
    WritePos (b);
    b. w. EndTag
  END StartDocument;

PROCEDURE (b: Builder) EndDocument*;
  BEGIN
    b. w. NewLine;
    b. w. StartTag ("end-document", FALSE);
    WritePos (b);
    b. w. EndTag;
    b. w. EndTag;
    TRY
      b. w. EndOfText
    CATCH IO.Error:
    END;
  END EndDocument;


PROCEDURE (b: Builder) StartDTD* (dtdBuilder: DTD.Builder);
  BEGIN
    b. w. NewLine;
    b. w. StartTag ("start-dtd", FALSE);
    WritePos (b);
    b. w. EndTag
  END StartDTD;

PROCEDURE (b: Builder) EndDTD* (externalDTD: DTD.ExternalEntity;
                                allDeclarationsProcessed: BOOLEAN);
  BEGIN
    b. w. NewLine;
    b. w. StartTag ("end-dtd", FALSE);
    IF (externalDTD # NIL) THEN
      Entity (b, externalDTD, FALSE)
    END;
    Boolean (b. w, "all-declarations-processed", allDeclarationsProcessed);
    WritePos (b);
    b. w. EndTag
  END EndDTD;



PROCEDURE (b: Builder) StartElement* (namespaceDecl: DTD.NamespaceDeclaration; 
                                      localName: DTD.String);
  BEGIN
    b. w. NewLine;
    b. w. StartTag ("start-element", FALSE);
    IF (namespaceDecl # NIL) THEN
      NamespaceDeclaration (b. w, namespaceDecl)
    END;
    String (b. w, "local-name", localName);
    WritePos (b);
    b. w. EndTag
  END StartElement;

PROCEDURE (b: Builder) Attribute* (namespaceDecl: DTD.NamespaceDeclaration; 
                                   localName: DTD.String;
                                   attrDecl: DTD.AttrDecl;
                                   value: DTD.AttValue;
                                   specified: BOOLEAN);
  BEGIN
    b. w. NewLine;
    b. w. StartTag ("attribute", FALSE);
    IF (namespaceDecl # NIL) THEN
      NamespaceDeclaration (b. w, namespaceDecl)
    END;
    String (b. w, "local-name", localName);
    IF (attrDecl # NIL) THEN
      b. w. StartTag ("attr-type", TRUE);
      CASE attrDecl. type OF
      | DTD.attrID: b. w. WriteLatin1 ("ID")
      | DTD.attrIDREF: b. w. WriteLatin1 ("IDREF")
      | DTD.attrIDREFS: b. w. WriteLatin1 ("IDREFS")
      | DTD.attrENTITY: b. w. WriteLatin1 ("ENTITY")
      | DTD.attrENTITIES: b. w. WriteLatin1 ("ENTITIES")
      | DTD.attrNMTOKEN: b. w. WriteLatin1 ("NMTOKEN")
      | DTD.attrNMTOKENS: b. w. WriteLatin1 ("NMTOKENS")
      | DTD.attrNOTATION: b. w. WriteLatin1 ("NOTATION")
      | DTD.attrENUMERATED: b. w. WriteLatin1 ("ENUMERATED")
      | DTD.attrCDATA: b. w. WriteLatin1 ("CDATA")
      END;
      b. w. EndTag;
      b. w. StartTag ("default-type", TRUE);
      CASE attrDecl. default OF
      | DTD.attrRequired: b. w. WriteLatin1 ("#REQUIRED")
      | DTD.attrImplied: b. w. WriteLatin1 ("#IMPLIED")
      | DTD.attrDefault: b. w. WriteLatin1 ("#DEFAULT")
      | DTD.attrFixed: b. w. WriteLatin1 ("#FIXED")
      END;
      b. w. EndTag
    END;
    String (b. w, "value", value. Flatten (attrDecl));
    Boolean (b. w, "specified", specified);
    IF specified THEN
      WritePos (b)
    END;
    b. w. EndTag
  END Attribute;

PROCEDURE (b: Builder) NamespaceDeclaration* (namespaceDecl: DTD.NamespaceDeclaration);
  BEGIN
    b. w. NewLine;
    NamespaceDeclaration (b. w, namespaceDecl)
  END NamespaceDeclaration;

PROCEDURE (b: Builder) AttributesDone*;
  BEGIN
    b. w. NewLine;
    b. w. StartTag ("attributes-done", FALSE);
    WritePos (b);
    b. w. EndTag
  END AttributesDone;

PROCEDURE (b: Builder) SkippedEntity* (name: DTD.String; referent: DTD.Entity);
  BEGIN
    b. w. NewLine;
    b. w. StartTag ("skipped-entity", FALSE);
    String (b. w, "name", name);
    IF (referent # NIL) THEN
      Entity (b, referent, FALSE)
    END;
    WritePos (b);
    b. w. EndTag
  END SkippedEntity;

PROCEDURE (b: Builder) EndElement* (namespaceDecl: DTD.NamespaceDeclaration; 
                                    localName: DTD.String);
  BEGIN
    b. w. NewLine;
    b. w. StartTag ("end-element", FALSE);
    IF (namespaceDecl # NIL) THEN
      NamespaceDeclaration (b. w, namespaceDecl)
    END;
    String (b. w, "local-name", localName);
    WritePos (b);
    b. w. EndTag
  END EndElement;

PROCEDURE (b: Builder) EntityDecl* (entity: DTD.Entity);
  BEGIN
    b. w. NewLine;
    Entity (b, entity, TRUE)
  END EntityDecl;

PROCEDURE (b: Builder) Notation* (notation: DTD.Notation);
  BEGIN
    b. w. NewLine;
    Notation (b, notation, TRUE)
  END Notation;

PROCEDURE (b: Builder) Characters* (VAR chars: DTD.StringVar;
                                    charsStart, charsEnd: DTD.CharPos;
                                    elementWhitespace: DTD.ElementWhitespaceType);
  BEGIN
    b. w. NewLine;
    b. w. StartTag ("characters", FALSE);
    b. w. StartTag ("chars", TRUE);
    b. w. WriteI (chars, charsStart, charsEnd);
    b. w. EndTag;
    b. w. StartTag ("element-whitespace", TRUE);
    CASE elementWhitespace OF
    | DTD.elementWhitespaceYes: b. w. WriteLatin1 ("yes")
    | DTD.elementWhitespaceNo: b. w. WriteLatin1 ("no")
    | DTD.elementWhitespaceUnknown: b. w. WriteLatin1 ("unknown")
    END;
    b. w. EndTag;
    WritePos (b);
    b. w. EndTag
  END Characters;

PROCEDURE (b: Builder) StartCDATA*;
  BEGIN
    b. w. NewLine;
    b. w. StartTag ("start-cdata", FALSE);
    WritePos (b);
    b. w. EndTag
  END StartCDATA;

PROCEDURE (b: Builder) EndCDATA*;
  BEGIN
    b. w. NewLine;
    b. w. StartTag ("end-cdata", FALSE);
    WritePos (b);
    b. w. EndTag
  END EndCDATA;

PROCEDURE (b: Builder) StartEntity* (entity: DTD.Entity);
  BEGIN
    b. w. NewLine;
    b. w. StartTag ("start-entity", FALSE);
    b. w. AttrString ("name", entity. name^);
    WritePos (b);
    b. w. EndTag
  END StartEntity;

PROCEDURE (b: Builder) EndEntity* (entity: DTD.Entity);
  BEGIN
    b. w. NewLine;
    b. w. StartTag ("end-entity", FALSE);
    b. w. AttrString ("name", entity. name^);
    WritePos (b);
    b. w. EndTag
  END EndEntity;


PROCEDURE (b: Builder) ProcessingInstruction* (
                      target: DTD.String; VAR content: DTD.StringVar;
                      contentStart, contentEnd: DTD.CharPos; baseURI: URI.URI);
  BEGIN
    b. w. NewLine;
    b. w. StartTag ("processing-instruction", FALSE);
    String (b. w, "target", target);
    b. w. StartTag ("content", TRUE);
    b. w. WriteI (content, contentStart, contentEnd);
    b. w. EndTag;
    WriteURI (b. w, "base-uri", baseURI);
    WritePos (b);
    b. w. EndTag
  END ProcessingInstruction;

PROCEDURE (b: Builder) Comment* (VAR chars: DTD.StringVar;
                                 start, end: DTD.CharPos);
  BEGIN
    b. w. NewLine;
    b. w. StartTag ("comment", FALSE);
    b. w. StartTag ("content", TRUE);
    b. w. WriteI (chars, start, end);
    b. w. EndTag;
    WritePos (b);
    b. w. EndTag
  END Comment;


PROCEDURE New* (outputChannel: IO.ByteChannel;
                codecFactory: Codec.Factory): Builder;
  VAR
    b: Builder;
  BEGIN
    NEW (b);
    B.Init (b);
    b. w := Writer.New (outputChannel, codecFactory, TRUE, 2);
    b. w. WriteTextDecl ("1.0", "");
    b. w. SetBaseURI (File.GetCwd());
    RETURN b
  END New;

END XML:Builder:ParserProtocol.
