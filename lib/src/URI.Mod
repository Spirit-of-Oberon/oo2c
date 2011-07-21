(* 	$Id: URI.Mod,v 1.6 2003/05/22 20:20:34 mva Exp $	 *)
MODULE URI [OOC_EXTENSIONS];
(*  Implements RFC2396 "Uniform Resource Identifiers: Generic Syntax"
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

(**This module provides the framework for an implementation of RFC 2396,
   @cite{Uniform Resource Locators (URI): Generic Syntax}.  It defined the
   abstract types @otype{URI}, @otype{OpaqueURI}, and @otype{HierarchicalURI},
   together with the abstract base types that represent the authority, query,
   and fragment component of an URI.  Handling of the path part of a
   hierarchical URI is delegated to the implementation of
   @otype{*URI:Scheme:Hierarchical.Generic}.  Additionally, this module defines
   the type @otype{Reference}, which represents an URI reference.

   Conversion of an URI string into an instance of the data type @otype{URI} is
   done by @oproc{*URI:Parser.NewURI}.  Likewise,
   @oproc{*URI:Parser.NewReference} translates a string into an instance of
   @otype{Reference}.

   The modules @samp{URI:Scheme:*} implement concrete specializations of
   @otype{URI} for various URI scheme identifiers.  Modules named
   @samp{URI:Authority:*}, @samp{URI:Query:*}, and @samp{URI:Fragment:*}
   implement concrete authority, query, and fragment instances.  *)

IMPORT
  CharClass, TextRider, Object, Exception, IO, ADT:StringBuffer,
  Str := URI:String;

TYPE
  Offset* = Str.Offset;
  (**A character offset.  *)
  
TYPE
  URI* = POINTER TO URIDesc;
  URIDesc* = RECORD [ABSTRACT]
  (**Abstract base type of all URI variants.  This class has one concrete
     (@otype{*URI:Scheme:CurrentDoc.CurrentDoc}) and two abstract
     specializations (@otype{HierarchicalURI} and @otype{OpaqueURI}) in this
     module.  All concrete specializations should be in modules with the name
     prefix @samp{URI:Scheme:*}.  *)
    (Object.ObjectDesc)
    schemeId-: STRING;
    (**Scheme part of the URI.  For a relative URI (and all instances of
       @otype{*URI:Scheme:CurrentDoc.CurrentDoc}), this field is @code{NIL}. *)
  END;

TYPE
  Authority* = POINTER TO AuthorityDesc;
  AuthorityDesc* = RECORD [ABSTRACT]
  (**Authority component of an URI.  See @omodule{*URI:Authority:Unparsed},
     @omodule{*URI:Authority:ServerBased}, or
     @omodule{*URI:Authority:RegistryBased} for concrete examples.  *)
  END;

TYPE
  Query* = POINTER TO QueryDesc;
  QueryDesc* = RECORD [ABSTRACT]
  (**Query component of an URI.  See @omodule{*URI:Query:Unparsed} for a
     concrete example.  *)
  END;

TYPE
  Fragment* = POINTER TO FragmentDesc;
  FragmentDesc* = RECORD [ABSTRACT]
  (**Fragment identifier of an URI.  See @omodule{*URI:Fragment:Unparsed} for a
     concrete example.  *)
  END;


TYPE
  HierarchicalURI* = POINTER TO HierarchicalURIDesc;
  HierarchicalURIDesc* = RECORD [ABSTRACT]
  (**Holds a hierachical URI.  *)
    (URIDesc)
    authority-: Authority;
    (**Authority component of the URI.  If there is no authority component,
       this field is @code{NIL}.  *)
    query-: Query;
    (**Query component of the URI.  If the URI has no query component, this
       field is @code{NIL}.  *)
  END;

TYPE
  OpaqueURI* = POINTER TO OpaqueURIDesc;
  OpaqueURIDesc* = RECORD [ABSTRACT]
  (**Holds an opaque URI.  *)
    (URIDesc)
  END;


TYPE
  Reference* = POINTER TO ReferenceDesc;
  ReferenceDesc = RECORD
  (**A URI reference is an URI plus an optional fragment identifier.  *)
    uri-: URI;
    (**The URI part of the URI reference.  This field is never @code{NIL}.  *)
    fragment-: Fragment;
    (**The fragment identifier of the URI reference.  If the reference has no
       fragment identifier, then this field is @code{NIL}.  *)
  END;



CONST
  channelNew* = 0;
  (**Open the channel on a new resource, truncating any existing resource of
     the same name.  Both read and write access is enabled.  *)
  channelTmp* = 1;
  (**Open the channel on a new resource, but do not register the resource yet.
     Both read and write access is enabled.  *)
  channelOld* = 2;
  (**Open the channel on an old resource.  Only read access is enabled.  *)

TYPE
  ChannelMode* = SHORTINT;
  (**This type is used to signal how @oproc{URI.GetChannel} should open a
     channel.  It must be one of @oconst{channelNew}, @oconst{channelTmp}, or
     @oconst{channelOld}.  *)

TYPE
  List = POINTER TO ListDesc;
  ListDesc = RECORD
    next: List;
    scheme: URI;
  END;

VAR
  schemeList: List;


(* URI
   ------------------------------------------------------------------------ *)

PROCEDURE InitURI* (uri: URI; schemeId: STRING);
  BEGIN
    uri. schemeId := schemeId
  END InitURI;

PROCEDURE (uri: URI) [ABSTRACT] Clone* (): URI;
(**Creates a deep copy of the URI referenced by @oparam{uri}.  That is, it
   creates a new instance of @oparam{uri} and calls @oproc{URI.Copy} on it.  *)
  END Clone;

PROCEDURE (uri: URI) Copy* (dest: URI);
(**Copies contents of source @oparam{uri} to target @oparam{dest}.

   @precond
   The dynamic type of @oparam{dest} is an extension of the dynamic type
   of @oparam{uri}.
   @end precond  *)
  BEGIN
    IF (uri. schemeId = NIL) THEN
      dest. schemeId := NIL
    ELSE
      dest. schemeId := uri. schemeId
    END
  END Copy;

PROCEDURE (uri: URI) SetSchemeId* (schemeId: STRING);
(**Sets the scheme identifier of @oparam{uri}.  If @oparam{schemeId} is
   @code{NIL}, then @oparam{uri} is a relative URI.  *)
  BEGIN
    uri. schemeId := schemeId
  END SetSchemeId;

PROCEDURE (uri: URI) [ABSTRACT] WriteXML* (w: TextRider.Writer);
(**Writes an XML fragment describing the URI @oparam{uri} to the writer
   @oparam{w}.  *)
  END WriteXML;

PROCEDURE (uri: URI) [ABSTRACT] ToString*(): Object.String8;
(**Converts the URI @oparam{uri} to its string representation.
   Reserved characters in the URI and characters that may not appear in a valid
   URI are escaped where necessary.  *)
  END ToString;

PROCEDURE (uri: URI) AppendScheme* (sb: StringBuffer.StringBuffer);
(**Appends the scheme component of @oparam{uri} to the string @oparam{sb}.  *)
  BEGIN
    IF (uri. schemeId # NIL) THEN
      sb.Append(uri. schemeId);
      sb.Append(":");
    END
  END AppendScheme;

PROCEDURE (uri: URI) MakeRelative* (baseURI: HierarchicalURI): URI;
(**Converts @oparam{uri} into an URI relative to @oparam{baseURI}.  The result
   is @oparam{uri} itself, if

   @itemize @bullet
   @item
   @oparam{baseURI} is @code{NIL},
   @item
   @oparam{uri} is not an extension of @otype{HierarchicalURI}, or
   @item
   @oparam{uri} and @oparam{baseURI} have no common base.
   @end itemize

   Otherwise, a new URI is constructed that holds only those parts of
   @oparam{uri}, that cannot be derived from @oparam{baseURI}.  The inverse
   transformation is done by @oproc{HierarchicalURI.ResolveRelative}.  *)
  BEGIN
    (* if we walk in here, then `uri' is not hierarchical *)
    RETURN uri
  END MakeRelative;

PROCEDURE (uri: URI) GetChannel* (mode: ChannelMode): IO.ByteChannel
RAISES IO.Error;
(**Opens a channel to the resource indicated by URI @oparam{uri}.  Depending on
   @oparam{mode}, one of these operations is performed:

   @table @oconst
   @item channelNew
   Opens a channel to a new instance of the resource.  If the resource exists,
   it is truncated.  The channel is opened for both read and write access.

   @item channelTmp
   Opens a channel to a new instance of the resource, but does not register the
   resource within its naming service.  The channel is opened for both read and
   write access.  Please note that some channel operations do not support this
   operation.  For those that do, registration of the resource in the naming
   service depends on the channel implementation.

   @item channelOld
   Opens a channel to an existing resource.  Only read access is enabled.
   @end table

   On success, a channel instance is returned.  On failure, an exception of
   type @otype{IO.Error} is raised.

   Note: Currently, only the @samp{file} URI (@omodule{*URI:Scheme:File}) and
   the @samp{http} URI (@omodule{*URI:Scheme:HTTP}) support this method.  *)
  BEGIN
    RAISE(NEW(IO.NotImplemented, NIL));
  END GetChannel;


(* Opaque URI
   ------------------------------------------------------------------------ *)

PROCEDURE InitOpaqueURI* (uri: OpaqueURI; schemeId: STRING);
  BEGIN
    InitURI (uri, schemeId)
  END InitOpaqueURI;

PROCEDURE (uri: OpaqueURI) [ABSTRACT] ParseOpaquePart* (str: Object.CharsLatin1; offset: Offset)
RAISES Exception.ParseError;
(**Parses the opaque component @oparam{str} of an URI.  On success, the data is
   stored in the URI @oparam{uri} and the result is @code{NIL}.  In case of 
   error, e.g., because @oparam{str} contains characters that are not allowed
   in an URI, an error message is returned and @oparam{uri} is not modified.
   A character position in an error message refers to an index in @oparam{str},
   incremented by the value of @oparam{offset}.  *)
  END ParseOpaquePart;


(* Authority
   ------------------------------------------------------------------------ *)

PROCEDURE InitAuthority* (auth: Authority);
  BEGIN
  END InitAuthority;

PROCEDURE (auth: Authority) [ABSTRACT] Clone* (): Authority;
(**Creates a deep copy of the authority component referenced by
   @oparam{auth}.  *)
  END Clone;

PROCEDURE (auth: Authority) [ABSTRACT] Copy* (dest: Authority);
(**Copies contents of source @oparam{auth} to target @oparam{dest}.

   @precond
   The dynamic type of @oparam{dest} is an extension of the dynamic type
   of @oparam{auth}.
   @end precond  *)
  END Copy;

PROCEDURE (auth: Authority) [ABSTRACT] ParseAuthority* (str: Object.CharsLatin1; offset: Offset)
RAISES Exception.ParseError;
(**Parses the authority component @oparam{str} of an hierarchical URI.  On
   success, the data is stored in the authority object @oparam{auth} and the
   result is @code{NIL}.  In case of error, a message object is returned and
   @oparam{auth} is not modified.  A character position in an error message
   refers to an index in @oparam{str}, incremented by the value of
   @oparam{offset}.  *)
  END ParseAuthority;

PROCEDURE (auth: Authority) [ABSTRACT] WriteXML* (w: TextRider.Writer);
(**Writes an XML fragment describing the authority component to the writer
   @oparam{w}.  *)
  END WriteXML;

PROCEDURE (auth: Authority) [ABSTRACT] Append* (sb: StringBuffer.StringBuffer);
(**Appends the textual representation of the authority component
   @oparam{auth} to the string @oparam{sb}.  *)
  END Append;


(* Query
   ------------------------------------------------------------------------ *)

PROCEDURE InitQuery* (query: Query);
  BEGIN
  END InitQuery;

PROCEDURE (query: Query) [ABSTRACT] Clone* (): Query;
(**Creates a deep copy of the queryority component referenced by
   @oparam{query}.  *)
  END Clone;

PROCEDURE (query: Query) [ABSTRACT] Copy* (dest: Query);
(**Copies contents of source @oparam{query} to target @oparam{dest}.

   @precond
   The dynamic type of @oparam{dest} is an extension of the dynamic type
   of @oparam{query}.
   @end precond  *)
  END Copy;

PROCEDURE (query: Query) [ABSTRACT] ParseQuery* (str: Object.CharsLatin1; offset: Offset)
RAISES Exception.ParseError;
(**Parses the query component @oparam{str} of an hierarchical URI.  On
   success, the data is stored in the query object @oparam{query} and the
   result is @code{NIL}.  In case of error, a message object is returned and
   @oparam{query} is not modified.  A character position in an error message
   refers to an index in @oparam{str}, incremented by the value of
   @oparam{offset}.  *)
  END ParseQuery;

PROCEDURE (query: Query) [ABSTRACT] WriteXML* (w: TextRider.Writer);
(**Writes an XML fragment describing the query component to the writer
   @oparam{w}.  *)
  END WriteXML;

PROCEDURE (query: Query) [ABSTRACT] Append* (sb: StringBuffer.StringBuffer);
(**Appends the textual representation of the query component
   @oparam{query} to the string @oparam{sb}.  *)
  END Append;


(* HierarchicalURI
   ------------------------------------------------------------------------ *)

PROCEDURE InitHierarchicalURI* (uri: HierarchicalURI; schemeId: STRING;
                                authority: Authority; query: Query);
  BEGIN
    InitURI (uri, schemeId);
    uri. authority := authority;
    uri. query := query
  END InitHierarchicalURI;

PROCEDURE (uri: HierarchicalURI) AuthorityMandatory*(): BOOLEAN;
(**If @code{TRUE} and the URI has a scheme component, then require that an
   authority is present when parsing the URI, and include an empty authority
   part when converting the URI to a string, if no authority is defined.

   By default, this method returns @code{FALSE}.  *)
  BEGIN
    RETURN FALSE;
  END AuthorityMandatory;

PROCEDURE (uri: HierarchicalURI) Copy* (dest: URI);
  BEGIN
    uri. Copy^ (dest);
    WITH dest: HierarchicalURI DO
      IF (uri. authority # NIL) THEN
        dest. authority := uri. authority. Clone()
      ELSE
        dest. authority := NIL
      END;
      IF (uri. query # NIL) THEN
        dest. query := uri. query. Clone()
      ELSE
        dest. query := NIL
      END
    END
  END Copy;

PROCEDURE (uri: HierarchicalURI) [ABSTRACT] NewAuthority*(): Authority;
(**Creates a new instance of the authority component of URI @oparam{uri}.
   The new object is subsequently filled in by parsing the authority component
   of the URI string (see @oproc{*URI:Authority.ParseAuthority}).  *)
  END NewAuthority;

PROCEDURE (uri: HierarchicalURI) SetAuthority* (auth: Authority);
(**Sets the authority component of @oparam{uri}.  A value of @code{NIL} means
   that the URI has no authority component.  *)
  BEGIN
    uri. authority := auth
  END SetAuthority;

PROCEDURE (uri: HierarchicalURI) [ABSTRACT] NewQuery*(): Query;
(**Creates a new instance of the query component of URI @oparam{uri}.
   The new object is subsequently filled in by parsing the query component
   of the URI string (see @oproc{*URI:Query.ParseQuery}).  *)
  END NewQuery;

PROCEDURE (uri: HierarchicalURI) SetQuery* (query: Query);
(**Sets the query component of @oparam{uri}.  A value of @code{NIL} means that
   the URI has no query component.  *)
  BEGIN
    uri. query := query
  END SetQuery;

PROCEDURE (uri: HierarchicalURI) ResolveRelative* (baseURI: HierarchicalURI);
(**Resolves the relative URI @oparam{uri} to an absolute URI.  The missing
   parts of @oparam{uri} are taken from @oparam{baseURI}.  This is the
   inverse transformation to @oproc{URI.MakeRelative}.  *)
  BEGIN
    IF (uri. schemeId = NIL) THEN
      uri. schemeId := baseURI. schemeId
    END;
    IF (uri. authority = NIL) THEN
      uri. authority := baseURI. authority
    END
  END ResolveRelative;

PROCEDURE (uri: HierarchicalURI) [ABSTRACT] ClearPath*;
(**Sets the path component of @oparam{uri} to the empty path.  Unlike the
   authority or query component, an URI always includes a path component.  *)
  END ClearPath;

PROCEDURE (uri: HierarchicalURI) [ABSTRACT] ParsePath* (str: Object.CharsLatin1; absolute: BOOLEAN; offset: Offset)
RAISES Exception.ParseError;
(**Parses the path component @oparam{str} of an URI.  The parameter
   @oparam{absolute} indicates, whether the path is absolute or relative.  On
   success, the data is stored in the URI @oparam{uri} and the result is
   @code{NIL}.  In case of error, an error message is returned and @oparam{uri}
   is not modified.  A character position in an error message refers to an
   index in @oparam{str}, incremented by the value of @oparam{offset}.  *)
  END ParsePath;

PROCEDURE (uri: HierarchicalURI) MakeRelative* (baseURI: HierarchicalURI): URI;
  VAR
    a1, a2: StringBuffer.StringBuffer;
    copy: URI;

  PROCEDURE Equal(s1, s2: STRING): BOOLEAN;
    BEGIN
      RETURN s1.Equals(s2);
    END Equal;
  
  BEGIN
    IF (baseURI = NIL) THEN
      (* no base URI given; cannot make a relative URI from this *)
      RETURN uri
    ELSIF ~uri.schemeId.Equals(baseURI.schemeId) THEN
      (* URIs use different schemes: cannot make a relative path *)
      RETURN uri
    ELSIF ((uri. authority = NIL) # (baseURI. authority = NIL)) THEN
      (* URI has an authority component, but base has not, or
         URI has no authority component, but base has; in the first case,
         the result URI must include the net_path, effectively saving only
         the scheme id; in the latter case, no rel_path can be used *)
      RETURN uri
    ELSIF (uri. authority # NIL) THEN
      a1 := StringBuffer.New(""); uri. authority. Append (a1);
      a2 := StringBuffer.New(""); baseURI. authority. Append (a2);
      IF (a1.length # a2.length) OR ~Equal(a1.ToString(), a2.ToString()) THEN
        (* authority components differ; again the result would need to
           include the net_path *)
        RETURN uri
      END
    END;
    
    copy := uri. Clone();
    copy. schemeId := NIL;
    copy(HierarchicalURI). authority := NIL;
    RETURN copy(HierarchicalURI)
  END MakeRelative;

PROCEDURE (uri: HierarchicalURI) [ABSTRACT] AppendPath* (sb: StringBuffer.StringBuffer);
(**Appends the textual representation of the path component of @oparam{uri}
   to the string @oparam{sb}.  *)
  END AppendPath;


(* Fragment
   ------------------------------------------------------------------------ *)

PROCEDURE InitFragment* (frag: Fragment);
  BEGIN
  END InitFragment;

PROCEDURE (frag: Fragment) [ABSTRACT] Clone* (): Fragment;
(**Creates a deep copy of the fragment component referenced by
   @oparam{frag}.  *)
  END Clone;

PROCEDURE (frag: Fragment) [ABSTRACT] Copy* (dest: Fragment);
(**Copies contents of source @oparam{frag} to target @oparam{dest}.

   @precond
   The dynamic type of @oparam{dest} is an extension of the dynamic type
   of @oparam{frag}.
   @end precond  *)
  END Copy;

PROCEDURE (frag: Fragment) [ABSTRACT] ParseFragment* (str: Object.CharsLatin1;
                                                      offset: Offset)
RAISES Exception.ParseError;
(**Parses the fragment component @oparam{str} of an URI.  On
   success, the data is stored in the fragment object @oparam{frag} and the
   result is @code{NIL}.  In case of error, a message object is returned and
   @oparam{frag} is not modified.  A character position in an error message
   refers to an index in @oparam{str}, incremented by the value of
   @oparam{offset}.  *)
  END ParseFragment;

PROCEDURE (frag: Fragment) [ABSTRACT] WriteXML* (w: TextRider.Writer);
(**Writes an XML fragment describing the fragment identifier to the writer
   @oparam{w}.  *)
  END WriteXML;

PROCEDURE (frag: Fragment) [ABSTRACT] Append* (sb: StringBuffer.StringBuffer);
(**Appends the textual representation of the fragment identifier
   @oparam{frag} to the string @oparam{sb}.  *)
  END Append;


(* URI Reference
   ------------------------------------------------------------------------ *)

PROCEDURE NewReference* (uri: URI; fragment: Fragment): Reference;
  VAR
    ref: Reference;
  BEGIN
    NEW (ref);
    ref. uri := uri;
    ref. fragment := fragment;
    RETURN ref
  END NewReference;

PROCEDURE (ref: Reference) WriteXML* (w: TextRider.Writer);
(**Writes an XML fragment describing the URI reference @oparam{ref} to the
   writer @oparam{w}.  *)
  BEGIN
    w. WriteString (CharClass.eol+"<uri-reference>");
    ref. uri. WriteXML (w);
    IF (ref. fragment # NIL) THEN
      ref. fragment. WriteXML (w)
    END;
    w. WriteString (CharClass.eol+"</uri-reference>")
  END WriteXML;

PROCEDURE (ref: Reference) ToString*(): Object.String8;
(**Converts the URI reference @oparam{ref} to its string representation.
   Reserved characters in the URI and fragment identifier are escaped where
   necessary.  *)
  VAR
    sb: StringBuffer.StringBuffer;
    str: STRING;
  BEGIN
    IF (ref. uri # NIL) THEN
      sb := StringBuffer.New(ref.uri.ToString());
    ELSE
      sb := StringBuffer.New("");
    END;
    IF (ref.fragment # NIL) THEN
      ref.fragment.Append(sb);
    END;
    str := sb.ToString();
    RETURN str(Object.String8);
  END ToString;


(* ------------------------------------------------------------------------ *)

PROCEDURE RegisterScheme* (scheme: URI);
(**Registers a new prototype object @oparam{scheme} under the name
   @samp{scheme.schemeId^} in the module's list of supported URI schemes.  If
   a previously registered scheme of the same name exists, it is replaced with
   @oparam{scheme}.  Note that case is not distinguished for scheme names.  *)
   
  PROCEDURE Append (VAR list: List);
    BEGIN
      IF (list = NIL) THEN
        NEW (list);
        list. next := NIL;
        list. scheme := scheme
      ELSIF scheme.schemeId.EqualsIgnoreCase(list.scheme.schemeId) THEN
        list. scheme := scheme
      ELSE
        Append (list. next)
      END
    END Append;
  
  BEGIN
    Append (schemeList)
  END RegisterScheme;

PROCEDURE GetScheme* (name: Str.STRING): URI;
(**Returns a prototype object for URI scheme @oparam{name}.  If no matching
   scheme was registered previously with @oproc{RegisterScheme}, @code{NIL}
   is returned.  *)
  VAR
    scheme: List;
  
  BEGIN
    scheme := schemeList;
    WHILE (scheme # NIL) & ~name.EqualsIgnoreCase(scheme.scheme.schemeId) DO
      scheme := scheme. next
    END;
    IF (scheme = NIL) THEN
      RETURN NIL
    ELSE
      RETURN scheme. scheme
    END
  END GetScheme;

BEGIN
  schemeList := NIL;
END URI.
