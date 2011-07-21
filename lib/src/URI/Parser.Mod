(* 	$Id: Parser.Mod,v 1.4 2003/06/05 22:09:36 mva Exp $	 *)
MODULE URI:Parser;
(*  Implements the URI parser.
    Copyright (C) 2000, 2003  Michael van Acken

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
  Strings, Object, Exception, URI, URI:CharClass, Str := URI:String,
  URI:Scheme:Hierarchical, URI:Scheme:Opaque, URI:Scheme:CurrentDoc;


VAR
  defaultHierarchical: URI.HierarchicalURI;
  defaultOpaque: URI.OpaqueURI;


PROCEDURE NewURILatin1*(str: ARRAY OF CHAR;
                        baseURI: URI.HierarchicalURI): URI.URI
RAISES Exception.ParseError;
(**Parses the string in @oparam{str} and creates a new URI object.  If the
   string is a relative URI, the URI is made absolute in relation to
   @oparam{baseURI}.  It is an error, if a relative URI string is given and
   @oparam{baseURI} is @code{NIL}.  *)
   
(* use baseURI and resolve immediately, or delay this until later? ... *)
  VAR
    i, start, endOfScheme: Str.Offset;
    schemeId, substr: Object.String8;
    uri, protoURI: URI.URI;
    hierURI: URI.HierarchicalURI;
  
  PROCEDURE Path (absolute: BOOLEAN) RAISES Exception.ParseError;
    VAR
      start: Str.Offset;
      substr: Object.String8;
    BEGIN  (* pre: ~absolute OR (str[i] = "/") *)
      IF absolute THEN
        INC (i)
      END;
      start := i;
      WHILE (str[i] # "?") & (str[i] # "#") & (str[i] # 0X) DO
        INC (i)
      END;
      substr := Object.NewLatin1Region(str, start, i);
      hierURI.ParsePath(substr.CharsLatin1(), absolute, start);
    END Path;
  
  BEGIN
    IF (str = "") THEN
      RETURN CurrentDoc.New()
    END;
    
    (* isolate scheme component of URI *)
    schemeId := NIL; protoURI := NIL;
    i := 0;
    WHILE (str[i] # ":") & (str[i] # "/") &
          (str[i] # "?") & (str[i] # "#") & (str[i] # 0X) DO
      INC (i)
    END;
    IF (str[i] = ":") & (i # 0) THEN     (* scheme is given *)
      endOfScheme := i;
      (* we got an absolute URI, because a non-empty scheme name is given;
         check if the characters before the ":" are valid *)
      i := 0;
      IF CharClass.SkipAlpha (str, i) THEN
        WHILE CharClass.SkipAlphaNum (str, i) OR
              CharClass.SkipMember (str, i, "+-.") DO
        END
      END;
      IF (i = endOfScheme) THEN          (* all characters valid *)
        schemeId := Object.NewLatin1Region(str, 0, i);
        INC (i);
        protoURI := URI.GetScheme (schemeId)
      ELSE                               (* `i' refers to the illegal char *)
        RAISE(NEW(Exception.ParseError,
                  "Illegal character in scheme component", i));
      END
    ELSE
      i := 0
    END;
    
    IF (schemeId = NIL) THEN
      IF (baseURI = NIL) THEN
        RAISE(NEW(Exception.ParseError,
                  "Cannot resolve relative URI reference without known base URI", i));
      ELSE
        protoURI := baseURI
      END
    END;
    
    uri := NIL; hierURI := NIL;
    IF (schemeId = NIL) OR (str[i] = "/") OR
       (protoURI # NIL) & (protoURI IS URI.HierarchicalURI) THEN
      (* absolute or relative URI, with hierarchical path *)
      IF (protoURI = NIL) THEN
        protoURI := defaultHierarchical
      ELSIF ~(protoURI IS URI.HierarchicalURI) THEN
        RAISE(NEW(Exception.ParseError,
                  "Expected absolute or net path beginning with a slash `/'",
                  i));
      END;

      uri := protoURI. Clone();
      uri. SetSchemeId (schemeId);
      hierURI := uri(URI.HierarchicalURI);
      IF (str[i] = "/") & (str[i+1] = "/") THEN
        hierURI. SetAuthority (hierURI. NewAuthority());
        IF (hierURI. authority = NIL) THEN
          RAISE(NEW(Exception.ParseError,
                    "This URI scheme does not support an authority component",
                    i));
        ELSE
          (* path includes an authority component; extract authority
             substring and hand it over to the prototype URI's authority
             parser *)
          INC (i, 2);
          start := i;
          WHILE (str[i] # "/") & (str[i] # "?") &
                (str[i] # "#") & (str[i] # 0X) DO
            INC (i)
          END;
          substr := Object.NewLatin1Region(str, start, i);
          hierURI.authority.ParseAuthority(substr.CharsLatin1(), start);
          
          IF (str[i] = "/") THEN
            Path (TRUE)
          ELSE
            hierURI. ClearPath
          END
        END
      ELSE
        IF (schemeId # NIL) & hierURI.AuthorityMandatory() THEN
          RAISE(NEW(Exception.ParseError,
                    "The URI does must include an authority component", i));
        END;
        hierURI. SetAuthority (NIL);
        IF (str[i] = "/") THEN
          Path (TRUE)
        ELSIF (schemeId # NIL) THEN
          RAISE(NEW(Exception.ParseError,
                    "The URI scheme name must be followed by a slash `/'", i));
        ELSE                             (* relative URI *)
          Path (FALSE)
        END
      END;
      
      (* check for query component *)
      IF (str[i] = "?") THEN
        hierURI. SetQuery (hierURI. NewQuery());
        IF (hierURI. query = NIL) THEN
          RAISE(NEW(Exception.ParseError,
                    "This URI scheme does not support a query component", i));
        ELSE
          INC (i);
          start := i;
          WHILE (str[i] # "#") & (str[i] # 0X) DO
            INC (i)
          END;
          substr := Object.NewLatin1Region(str, start, i);
          hierURI.query.ParseQuery(substr.CharsLatin1(), start)
        END
      ELSE
        hierURI. SetQuery (NIL)
      END;
      
      IF (schemeId = NIL) THEN
        hierURI. ResolveRelative (baseURI)
      END
    ELSE  (* (schemeId # NIL) & (str[i] # "/") *)
      (* absolute URI with opaque path component *)
      IF (str[i] = 0X) THEN
        RAISE(NEW(Exception.ParseError,
                  "The opaque part of an URI must not be empty", i));
      END;

      IF (protoURI = NIL) THEN
        protoURI := defaultOpaque
      ELSIF ~(protoURI IS URI.OpaqueURI) THEN
        RAISE(NEW(Exception.ParseError,
                  "Expected opaque URI component, not a slash `/'", i));
      END;
      
      uri := protoURI. Clone();
      uri. SetSchemeId (schemeId);
      substr := Object.NewLatin1Region(str, i, Strings.Length(str));
      uri(URI.OpaqueURI).ParseOpaquePart(substr.CharsLatin1(), i);
      i := Strings.Length (str);
    END;
    
    IF (str[i] # 0X) THEN
      RAISE(NEW(Exception.ParseError, "Junk after URI", i));
    END;
    RETURN uri;
  END NewURILatin1;

PROCEDURE NewURI*(str: Object.String8;
                  baseURI: URI.HierarchicalURI): URI.URI
RAISES Exception.ParseError;
  VAR
    chars: Object.CharsLatin1;
  BEGIN
    chars := str.CharsLatin1();
    RETURN NewURILatin1(chars^, baseURI);
  END NewURI;

PROCEDURE NewReferenceLatin1*(str: ARRAY OF CHAR;
                              baseURI: URI.HierarchicalURI;
                              fragmentPrototype: URI.Fragment): URI.Reference
RAISES Exception.ParseError;
(**Like @oproc{NewURI}, but parses a URI reference in @oparam{str}.  The
   instance @oparam{fragmentPrototype} is used to parse the fragment identifier
   of the URI.  The format of the fragment identifier is not related to the
   URI.  The application must know what to expect, and provide a matching
   @otype{URI.Fragment} prototype, to which the parser delegates analysis of
   the fragment identifier.  *)
  VAR
    i: URI.Offset;
    uri: URI.URI;
    fragment: URI.Fragment;
    substr: Object.String8;
    ch: CHAR;
  BEGIN
    i := 0;
    WHILE (str[i] # 0X) & (str[i] # "#") DO
      INC (i)
    END;
    
    ch := str[i];
    str[i] := 0X;
    uri := NewURILatin1(str, baseURI);
    str[i] := ch;
    
    IF (ch = 0X) THEN                  (* no fragment identifier *)
      RETURN URI.NewReference (uri, NIL)
    ELSE
      fragment := fragmentPrototype. Clone();
      substr := Object.NewLatin1Region(str, i+1, Strings.Length(str));
      fragment.ParseFragment(substr.CharsLatin1(), i+1);
      RETURN URI.NewReference (uri, fragment);
    END
  END NewReferenceLatin1;

PROCEDURE NewReference*(str: Object.String8;
                        baseURI: URI.HierarchicalURI;
                        fragmentPrototype: URI.Fragment): URI.Reference
RAISES Exception.ParseError;
  VAR
    chars: Object.CharsLatin1;
  BEGIN
    chars := str.CharsLatin1();
    RETURN NewReferenceLatin1(chars^, baseURI, fragmentPrototype);
  END NewReference;

BEGIN
  defaultHierarchical := Hierarchical.New (NIL, NIL, NIL);
  defaultOpaque := Opaque.New (NIL, "");
END URI:Parser.
