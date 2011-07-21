(*      $Id: Namespaces.Mod,v 1.3 2003/06/05 22:09:35 mva Exp $   *)
MODULE XML:Builder:Namespaces;
(*  Provides namespace support for XML:Parser.
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
  Msg, LongStrings, Object, Exception,
  URI, URIParser := URI:Parser, URI:Fragment:Unparsed,
  XML:Error, XML:DTD, XML:Locator, B := XML:Builder, XML:EntityResolver;


TYPE
  NamespaceList = POINTER TO ARRAY OF DTD.NamespaceDeclaration;
  ElementData = RECORD
    namespaceDecl: DTD.NamespaceDeclaration;
    (* namespace URI of current element *)
    localName: DTD.String;
    (* local name of current element *)
    pos: Locator.Position;
    default: DTD.NamespaceDeclaration;
    startLocal: LONGINT;
  END;
  Stack = POINTER TO ARRAY OF ElementData;

TYPE
  Builder* = POINTER TO BuilderDesc;
  BuilderDesc = RECORD
  (**This builder adds namespace support to the parser.  It rewrites element
     and attribute names if they have a namespace prefix.  The rewritten
     element and attribute data is then passed on to the delegate builder.  All
     other callbacks are propagated without changes.

     Assuming that @samp{builder} is an instance of
     @otype{B.Builder}, the following commands create a
     namespace-aware parser:

     @example
     builder := Namespaces.New (builder);
     p := Parser.NewFile (arg, NIL, NIL, NIL, builder, res);
     p. enforceQNames := TRUE;
     @end example  *)
  
    (B.BuilderDesc)
    parserLocator: Locator.Locator;
    namespaceLocator: Locator.Locator;
    delegateBuilder: B.Builder;
    errorListener: Locator.ErrorListener;
    
    currLevel: LONGINT;
    (* level of current element; document element is 0, each nesting level
       adds 1 *)
    stack: Stack;
    
    namespaceList: NamespaceList;
    lenNamespaceList: LONGINT;
    
    attrList: B.AttributeList;
  END;


CONST  (* error codes *)
  emptyURI = 1;
  malformedURIRef = 2;
  undeclaredPrefix = 3;
  nameClash = 4;

VAR
  namespacesContext: Error.Context;


PROCEDURE (b: Builder) SetLocator* (locator: Locator.Locator);
  BEGIN
    b. parserLocator := locator;
    b. delegateBuilder. SetLocator (locator)
  END SetLocator;

PROCEDURE (b: Builder) SetErrorListener* (el: Locator.ErrorListener);
  BEGIN
    b. errorListener := el;
    b. delegateBuilder. SetErrorListener (el)
  END SetErrorListener;


PROCEDURE (b: Builder) StartDocument* (documentEntity: DTD.ExternalEntity);
  BEGIN
    b. delegateBuilder. StartDocument (documentEntity)
  END StartDocument;

PROCEDURE (b: Builder) EndDocument*;
  BEGIN
    b. delegateBuilder. EndDocument
  END EndDocument;

PROCEDURE (b: Builder) StartDTD* (dtdBuilder: DTD.Builder);
  BEGIN
    b. delegateBuilder. StartDTD (dtdBuilder)
  END StartDTD;

PROCEDURE (b: Builder) EndDTD* (externalDTD: DTD.ExternalEntity;
                                allDeclarationsProcessed: BOOLEAN);
  BEGIN
    b. delegateBuilder. EndDTD (externalDTD, allDeclarationsProcessed)
  END EndDTD;



PROCEDURE (b: Builder) StartElement* (namespaceDecl: DTD.NamespaceDeclaration; 
                                      localName: DTD.String);
  VAR
    new: Stack;
    i: LONGINT;
  BEGIN
    ASSERT (namespaceDecl = NIL);
    INC (b. currLevel);
    IF (b. currLevel = LEN (b. stack^)) THEN
      NEW (new, LEN (b. stack^)*2);
      FOR i := 0 TO LEN (b. stack^)-1 DO
        new[i] := b. stack[i]
      END;
      b. stack := new
    END;
    
    b. stack[b. currLevel]. namespaceDecl := namespaceDecl;
    b. stack[b. currLevel]. localName := localName;
    b. stack[b. currLevel]. pos := b. parserLocator^;
    IF (b. currLevel > 0) THEN
      b. stack[b. currLevel]. default := b. stack[b. currLevel-1]. default
    ELSE
      b. stack[b. currLevel]. default := NIL
    END;
    b. stack[b. currLevel]. startLocal := b. lenNamespaceList
  END StartElement;

PROCEDURE (b: Builder) EndElement* (namespaceDecl: DTD.NamespaceDeclaration; 
                                    localName: DTD.String);
  BEGIN
    ASSERT (namespaceDecl = NIL);
    b. delegateBuilder. EndElement (b. stack[b. currLevel]. namespaceDecl,
                                    b. stack[b. currLevel]. localName);
    b. lenNamespaceList := b. stack[b. currLevel]. startLocal;
    DEC (b. currLevel);
  END EndElement;

PROCEDURE (b: Builder) Attribute* (namespaceDecl: DTD.NamespaceDeclaration; 
                                   localName: DTD.String;
                                   attrDecl: DTD.AttrDecl;
                                   value: DTD.AttValue;
                                   specified: BOOLEAN);
  VAR
    prefix, str: DTD.String;
    err: Error.Msg;
    nspDecl: DTD.NamespaceDeclaration;
    
  PROCEDURE IsNamespaceDecl (VAR str: ARRAY OF DTD.Char): BOOLEAN;
    BEGIN
      RETURN (str[0] = "x") & (str[1] = "m") & (str[2] = "l") &
             (str[3] = "n") & (str[4] = "s") &
             ((str[5] = 0X) OR (str[5] = ":"))
    END IsNamespaceDecl;
  
  PROCEDURE GetURI (str: DTD.String): DTD.StringURI;
    VAR
      str8: DTD.StringURI;
      baseURI: URI.URI;
      uriRef: URI.Reference;
      res: Msg.Msg;
      err: Error.Msg;
      fragm: Unparsed.Fragment;
      e: Exception.Exception;
      str0: STRING;
      chars: Object.CharsLatin1;
    BEGIN
      str8 := EntityResolver.NormalizeURI (str);
      baseURI := b. parserLocator. entity. baseURI;
      fragm := Unparsed.New("");

      res := NIL;
      TRY
        IF (baseURI # NIL) & (baseURI IS URI.HierarchicalURI) THEN
          uriRef := URIParser.NewReferenceLatin1
              (str8^, baseURI(URI.HierarchicalURI), fragm)
        ELSE
          uriRef := URIParser.NewReferenceLatin1
              (str8^, NIL, fragm)
        END;
      CATCH Exception.ParseError:
        res := Error.New(namespacesContext, malformedURIRef);
        e := Exception.Current();
        str0 := e.GetMessage();
        chars := str0(Object.String8).CharsLatin1();
        res.SetStringAttrib("reason", Msg.GetStringPtr(chars^));
      END;
      
      IF (res # NIL) THEN
        err := b. errorListener. Error (namespacesContext, malformedURIRef,
                                        TRUE, b. parserLocator^);
        err. SetMsgAttrib ("uri_error", res);
        RETURN NIL
      ELSE
        RETURN str8
      END
    END GetURI;
  
  PROCEDURE AddDecl (namespaceDecl: DTD.NamespaceDeclaration);
    VAR
      new: NamespaceList;
      i: LONGINT;
    BEGIN
      IF (b. lenNamespaceList = LEN (b. namespaceList^)) THEN
        NEW (new, LEN (b. namespaceList^)*2);
        FOR i := 0 TO LEN (b. namespaceList^)-1 DO
          new[i] := b. namespaceList[i]
        END;
        b. namespaceList := new
      END;
      
      IF ~((namespaceDecl. prefix # NIL) &
           (namespaceDecl. uri = NIL)) THEN
        b. namespaceList[b. lenNamespaceList] := namespaceDecl;
        INC (b. lenNamespaceList)
      END
    END AddDecl;
  
  BEGIN
    ASSERT (namespaceDecl = NIL);
    IF IsNamespaceDecl (localName^) THEN
      (* create a record for the namespace declarations local to the current
         element, unless this record already exists *)
      str := value. Flatten (attrDecl);
      IF (localName[5] = 0X) THEN        (* default declaration *)
        IF (str^ = "") THEN
          AddDecl (DTD.NewNamespaceDeclaration (NIL, NIL));
          b. stack[b. currLevel]. default := NIL
        ELSE
          nspDecl := DTD.NewNamespaceDeclaration (NIL, GetURI (str));
          AddDecl (nspDecl);
          b. stack[b. currLevel]. default := nspDecl
        END
      ELSE
        prefix := DTD.GetString (localName^, 6, LongStrings.Length (localName^));
        IF (str^ = "") THEN
          err := b. errorListener. Error (namespacesContext, emptyURI,
                                          TRUE, b. parserLocator^)
        ELSE
          AddDecl (DTD.NewNamespaceDeclaration (prefix, GetURI (str)))
        END
      END
    ELSE
      b. attrList. Append (B.NewAttribute (namespaceDecl, localName, attrDecl,
                           value, specified, b. parserLocator))
    END
  END Attribute;
  
PROCEDURE (b: Builder) NamespaceDeclaration* (namespaceDecl: DTD.NamespaceDeclaration);
  BEGIN
    ASSERT (FALSE)
  END NamespaceDeclaration;

PROCEDURE (b: Builder) AttributesDone*;
  VAR
    i, j, colon: LONGINT;
    attr: B.Attribute;
    localName: DTD.String;
    namespaceDecl: DTD.NamespaceDeclaration;
    err: Error.Msg;
  
  PROCEDURE GetColon (VAR str: ARRAY OF DTD.Char): LONGINT;
    VAR
      i: LONGINT;
    BEGIN
      i := 0;
      WHILE (str[i] # 0X) & (str[i] # ":") DO
        INC (i)
      END;
      IF (str[i] = ":") THEN
        RETURN i
      ELSE
        RETURN -1
      END
    END GetColon;
  
  PROCEDURE GetNamespace (VAR str: ARRAY OF DTD.Char; colon: LONGINT): DTD.NamespaceDeclaration;
    VAR
      i: LONGINT;
      err: Error.Msg;
    BEGIN
      str[colon] := 0X;
      i := b. lenNamespaceList-1;
      WHILE (i >= 0) DO
        IF (b. namespaceList[i]. prefix^ = str) THEN
          str[colon] := ":";
          RETURN b. namespaceList[i]
        END;
        DEC (i)
      END;
      err := b. errorListener. Error (namespacesContext, undeclaredPrefix,
                                      TRUE, b. namespaceLocator^);
      err. SetLStringAttrib ("prefix", Msg.GetLStringPtr (str));
      str[colon] := ":";
      RETURN NIL
    END GetNamespace;
  
  BEGIN
    b. delegateBuilder. SetLocator (b. namespaceLocator);
    
    (* emit start element *)
    b. namespaceLocator^ := b. stack[b. currLevel]. pos;
    localName := b. stack[b. currLevel]. localName;
    colon := GetColon (localName^);
    IF (colon >= 0) THEN
      namespaceDecl := GetNamespace (localName^, colon);
      localName := DTD.GetString (localName^, colon+1, LongStrings.Length (localName^))
    ELSE
      namespaceDecl := b. stack[b. currLevel]. default
    END;
    b. stack[b. currLevel]. namespaceDecl := namespaceDecl;
    b. stack[b. currLevel]. localName := localName;
    b. delegateBuilder. StartElement (namespaceDecl, localName);
    
    (* emit namespace declarations *)
    i := b. stack[b. currLevel]. startLocal;
    WHILE (i # b. lenNamespaceList) DO
      b. delegateBuilder. NamespaceDeclaration (b. namespaceList[i]);
      INC (i)
    END;
    
    (* emit all other atttributes *)
    i := 0;
    WHILE (i # b. attrList. len) DO
      attr := b. attrList. attr[i];
      b. namespaceLocator^ := attr. pos;
      
      localName := attr. localName;
      colon := GetColon (localName^);
      IF (colon >= 0) THEN
        namespaceDecl := GetNamespace (localName^, colon);
        localName := DTD.GetString (localName^, colon+1, LongStrings.Length (localName^));
        
        (* make sure that no other attribute until now had the same local name
           and namespace URI *)
        j := 0;
        WHILE (j # i) DO
          IF (b. attrList. attr[j]. localName^ = localName^) &
             (b. attrList. attr[j]. namespaceDecl # NIL) &
             (b. attrList. attr[j]. namespaceDecl. uri^ = namespaceDecl. uri^) THEN
            err := b. errorListener. Error (namespacesContext, nameClash,
                                            TRUE, b. namespaceLocator^);
            err. SetLStringAttrib ("prefix", Msg.GetLStringPtr (b. attrList. attr[j]. namespaceDecl. prefix^));
            err. SetLStringAttrib ("localName", Msg.GetLStringPtr (localName^));
          END;
          INC (j)
        END
      ELSE
        namespaceDecl := NIL
      END;
      attr. namespaceDecl := namespaceDecl;
      attr. localName := localName;
      
      b. delegateBuilder. Attribute (namespaceDecl,
                                     localName,
                                     attr. attrDecl,
                                     attr. value,
                                     attr. specified);
      INC (i)
    END;
    
    b. delegateBuilder. SetLocator (b. parserLocator);
    b. delegateBuilder. AttributesDone
  END AttributesDone;


PROCEDURE (b: Builder) SkippedEntity* (name: DTD.String; referent: DTD.Entity);
  BEGIN
    b. delegateBuilder. SkippedEntity (name, referent)
  END SkippedEntity;


PROCEDURE (b: Builder) Characters* (VAR chars: DTD.StringVar;
                                    charsStart, charsEnd: DTD.CharPos;
                                    elementWhitespace: DTD.ElementWhitespaceType);
  BEGIN
    b. delegateBuilder. Characters (chars, charsStart, charsEnd,
                                    elementWhitespace)
  END Characters;


PROCEDURE (b: Builder) StartCDATA*;
  BEGIN
    b. delegateBuilder. StartCDATA
  END StartCDATA;

PROCEDURE (b: Builder) EndCDATA*;
  BEGIN
    b. delegateBuilder. EndCDATA
  END EndCDATA;

PROCEDURE (b: Builder) StartEntity* (entity: DTD.Entity);
  BEGIN
    b. delegateBuilder. StartEntity (entity)
  END StartEntity;

PROCEDURE (b: Builder) EndEntity* (entity: DTD.Entity);
  BEGIN
    b. delegateBuilder. EndEntity (entity)
  END EndEntity;



PROCEDURE (b: Builder) EntityDecl* (entity: DTD.Entity);
  BEGIN
    b. delegateBuilder. EntityDecl (entity)
  END EntityDecl;

PROCEDURE (b: Builder) Notation* (notation: DTD.Notation);
  BEGIN
    b. delegateBuilder. Notation (notation)
  END Notation;

PROCEDURE (b: Builder) ProcessingInstruction* (
                     target: DTD.String; VAR content: DTD.StringVar;
                     contentStart, contentEnd: DTD.CharPos; baseURI: URI.URI);
  BEGIN
    b. delegateBuilder. ProcessingInstruction (target, content,
      contentStart, contentEnd, baseURI)
  END ProcessingInstruction;

PROCEDURE (b: Builder) Comment* (VAR chars: DTD.StringVar;
                                 start, end: DTD.CharPos);
  BEGIN
    b. delegateBuilder. Comment (chars, start, end)
  END Comment;



PROCEDURE Init* (b: Builder; delegateBuilder: B.Builder);
  BEGIN
    b. delegateBuilder := delegateBuilder;
    NEW (b. namespaceLocator);
    b. parserLocator := NIL;
    b. errorListener := NIL;
    
    b. currLevel := -1;
    NEW (b. stack, 16);
    
    b. lenNamespaceList := 0;
    NEW (b. namespaceList, 16);
    
    b. attrList := B.NewAttributeList();
  END Init;

PROCEDURE New* (delegateBuilder: B.Builder): Builder;
(**Creates a new builder that performs namespaces transformations on the
   parser callbacks.  Except for splitting qualified names into namespace URI
   and local name, all callbacks are passed on to @oparam{delegateBuilder}
   unchanged.  *)
  VAR
    b: Builder;
  BEGIN
    NEW (b);
    Init (b, delegateBuilder);
    RETURN b
  END New;


PROCEDURE SetErrorMessages;
  VAR
    i: INTEGER;
    t: ARRAY 128 OF CHAR;
  BEGIN
    FOR i := 0 TO 999 DO
      CASE i OF
      | emptyURI:
        t := "Namespace URI must not be empty"
      | malformedURIRef:
        t := "Malformed URI reference: ${uri_error}"
      | undeclaredPrefix:
        t := "Prefix `${prefix}' is not declared"
      | nameClash:
        t := "Attribute name conflicts with `${prefix}:${localName}'"
      ELSE
        t := ""
      END;
      IF (t # "") THEN
        namespacesContext. SetString (i, t)
      END
    END
  END SetErrorMessages;

BEGIN
  namespacesContext := Error.NewContext ("XML:Builder:Namespaces");
  SetErrorMessages
END XML:Builder:Namespaces.
