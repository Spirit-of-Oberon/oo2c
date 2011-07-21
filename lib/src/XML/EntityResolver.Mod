(*      $Id: EntityResolver.Mod,v 1.3 2003/06/05 22:09:35 mva Exp $   *)
MODULE XML:EntityResolver;
(*  Locates and opens external entities for the XML parser.
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
  LongStrings, Msg, Strings, Object, Exception,
  URI, URI:Parser, URI:CharClass,
  XML:Error, XML:DTD, Codec := XML:UnicodeCodec, XML:UnicodeCodec:UTF8;


TYPE
  Resolver* = POINTER TO ResolverDesc;
  ResolverDesc* = RECORD
  END;

CONST  (* error codes *)
  invalidURI = 1;
  
VAR
  resolverContext: Error.Context;


PROCEDURE NormalizeURI* (uri: DTD.String): DTD.StringURI;
(**Normalizes an Unicode string representing a URI to a legal URI.  First, t
   the Unicode string is encoded into a UTF-8 byte sequence.  Then, any
   resulting bytes that are not reserved, unreserved, @samp{#}, or @samp{%}
   are replaced with URI escape sequences.  In particular, all non-ASCII
   bytes are escaped.  *)
  VAR
    len16, i: INTEGER;
    codec: Codec.Codec;
    str8: ARRAY 8*1024 OF CHAR;
    repl: ARRAY 4 OF CHAR;
    srcDone, destDone: LONGINT;

  PROCEDURE ToHex (i: INTEGER): CHAR;
    BEGIN
      IF (i < 10) THEN
        RETURN CHR (i+ORD ("0"))
      ELSE
        RETURN CHR (i+(ORD ("A")-10))
      END
    END ToHex;

  BEGIN
    len16 := LongStrings.Length (uri^);
    codec := UTF8.factory. NewCodec();

    (* encode UCS-2 character sequence as UTF-8 character sequence *)
    IF (len16 # 0) THEN
      codec. Encode (uri^, 0, len16, str8, 0, LEN (str8), srcDone, destDone);
      IF (srcDone # len16) THEN
        codec. Encode (uri^, srcDone, len16, str8, destDone, LEN (str8),
                       srcDone, destDone);
        ASSERT (srcDone = len16)
      END;
      str8[destDone] := 0X
    ELSE
      COPY ("", str8)
    END;

    (* encode every non-ASCII character and some other characters in the
       UTF-8 string to %HH *)
    i := 0;
    WHILE (str8[i] # 0X) DO
      IF (str8[i] >= 80X) OR
         ~(CharClass.IsReserved (str8[i]) OR
           CharClass.IsUnreserved (str8[i]) OR
           (str8[i] = "#") OR
           (str8[i] = "%")) THEN
        repl := "%HH";
        repl[1] := ToHex (ORD (str8[i]) DIV 16);
        repl[2] := ToHex (ORD (str8[i]) MOD 16);
        Strings.Delete (str8, i, 1);
        Strings.Insert (repl, i, str8);
        INC (i, 3)
      ELSE
        INC (i)
      END
    END;

    RETURN DTD.GetStringURI (str8, 0, i)
  END NormalizeURI;


PROCEDURE (r: Resolver) GetURI* (public, system: DTD.String; baseURI: URI.URI;
                                 VAR uri: URI.URI; VAR res: Msg.Msg);
(**Interprets the public or system identifier of an external entity and
   constructs an URI for it.  On success, the URI of the document is returned
   in @oparam{uri}, and @code{NIL} in @oparam{res}.  On failure, @oparam{res}
   holds an error message.
   
   The default implementation ignores the public identifier and uses the
   URI in @oparam{system}.  An relative system identifier is expanded relative
   to @oparam{baseURI}.  Both @oparam{uri} and @oparam{res} are set to 
   @code{NIL} if no system identifier is present, which is permitted for
   notation declarations.  *)
  VAR
    str8: DTD.StringURI;
    err: Error.Msg;
    e: Exception.Exception;
    str: STRING;
    chars: Object.CharsLatin1;
  BEGIN
    IF (system = NIL) THEN               (* notation declaration *)
      uri := NIL; res := NIL;
      RETURN
    END;
    
    str8 := NormalizeURI (system);
    TRY
      IF (baseURI # NIL) & (baseURI IS URI.HierarchicalURI) THEN
        uri := Parser.NewURILatin1(str8^, baseURI(URI.HierarchicalURI));
      ELSE
        uri := Parser.NewURILatin1(str8^, NIL);
      END;
      res := NIL;
    CATCH Exception.ParseError:
      err := Error.New(resolverContext, invalidURI);
      e := Exception.Current();
      str := e.GetMessage();
      chars := str(Object.String8).CharsLatin1();
      err.SetStringAttrib("reason", Msg.GetStringPtr(chars^));
      res := err;
    END;
  END GetURI;
  
PROCEDURE New* (): Resolver;
  VAR
    er: Resolver;
  BEGIN
    NEW (er);
    RETURN er
  END New;

BEGIN
  resolverContext := Error.NewContext("XML:EntityResolver");
  resolverContext.SetString(invalidURI, "Invalid URI: ${reason}")
END XML:EntityResolver.
