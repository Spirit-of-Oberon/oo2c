(* 	$Id: NNTP.Mod,v 1.3 2003/06/11 21:06:27 mva Exp $	 *)
MODULE URI:Scheme:NNTP;
(*  Implementation of the "nntp" URI scheme.
    Copyright (C) 2001, 2003  Michael van Acken

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
  URI0 := URI, URI:Scheme:Hierarchical, URI:Authority:ServerBased,
  Query := URI:Query:Unparsed;


TYPE
  URI* = POINTER TO URIDesc;
  URIDesc = RECORD
  (**This class implements the @samp{nntp:} (or @samp{news:}, or @samp{snews:})
     URI scheme.  It uses @otype{ServerBased.Authority} for its authority
     component, and @otype{Query.Query} for a query part.

     @strong{NOTE}: The current implementation parses the URI as a generic
     hierarchical URI.  The path syntax specific to news it @emph{not}
     implemented yet.
     
     @noindent
     Syntax:

     @example
     newsURL      = scheme ":" [ news-server ] [ refbygroup | message ]
     scheme       = "news" | "snews" | "nntp"
     news-server  = "//" server "/"
     refbygroup   = group [ "/" messageno [ "-" messageno ] ]
     message      = local-part "@@" domain
     @end example  *)
    (Hierarchical.GenericDesc)
  END;



PROCEDURE Init* (http: URI; schemeId: STRING;
                 authority: URI0.Authority; query: URI0.Query);
  BEGIN
    Hierarchical.Init (http, schemeId, authority, query)
  END Init;

PROCEDURE New* (schemeId: STRING;
                authority: URI0.Authority; query: URI0.Query): URI;
  VAR
    http: URI;
  BEGIN
    NEW (http);
    Init (http, schemeId, authority, query);
    RETURN http
  END New;

PROCEDURE (http: URI) NewAuthority* (): URI0.Authority;
  BEGIN
    RETURN ServerBased.New (NIL, "", -1, 119)
  END NewAuthority;

PROCEDURE (http: URI) NewQuery* (): URI0.Query;
  BEGIN
    RETURN Query.New ("")
  END NewQuery;

PROCEDURE (http: URI) Clone* (): URI;
  VAR
    copy: URI;
  BEGIN
    NEW (copy);
    http. Copy (copy);
    RETURN copy
  END Clone;


PROCEDURE NewPrototype* (scheme: STRING): URI;
  BEGIN
    RETURN New (scheme, NIL, NIL)
  END NewPrototype;

END URI:Scheme:NNTP.
