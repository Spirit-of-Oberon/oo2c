(* 	$Id: FileSystem.Mod,v 1.4 2004/11/10 08:45:45 mva Exp $	 *)
MODULE OOC:Config:FileSystem;
(*  Implements "file-system" element of XML repository configuration.
    Copyright (C) 2001  Michael van Acken

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
  Msg, LongStrings, Strings, Exception,
  URI, URIParser := URI:Parser, URI:Scheme:File,
  XML:DTD, XMLBuilder := XML:Builder, XML:Locator,
  Config:Parser, CS := Config:Section, 
  OOC:Config:Repositories, OOC:Repository,
  FileSystemRepository := OOC:Repository:FileSystem;


TYPE
  RepositoryEntry = POINTER TO RepositoryEntryDesc;
  RepositoryEntryDesc = RECORD
    (Repositories.RepositoryEntryDesc)
  END;


CONST
  invalidAttribute = 1;
  requireCharDataContent = 2;
  invalidURI = 3;
  
TYPE
  ErrorContext = POINTER TO ErrorContextDesc;
  ErrorContextDesc = RECORD  (* stateless *)
    (CS.ErrorContextDesc)
  END;

VAR
  repositoriesContext: ErrorContext;


PROCEDURE (context: ErrorContext) GetTemplate* (msg: Msg.Msg; VAR templ: Msg.LString);
  VAR
    t: ARRAY 128 OF Msg.LChar;
  BEGIN
    CASE msg. code OF
    | invalidAttribute:
      t := "Attribute `${name}' is not defined for this element"
    | requireCharDataContent:
      t := "This element must contain character data only"
    | invalidURI:
      t := "Invalid URI.  Reason: ${uri_msg}"
    END;
    context. WriteTemplate (msg, t, templ)
  END GetTemplate;


PROCEDURE NewRepositoryEntry (): RepositoryEntry;
  VAR
    re: RepositoryEntry;
  BEGIN
    NEW (re);
    Repositories.InitRepositoryEntry (re, "file-system");
    RETURN re
  END NewRepositoryEntry;

PROCEDURE (re: RepositoryEntry) ProcessElement* (
                        node: Parser.Element;
                        errorListener: Locator.ErrorListener;
                        baseRep: Repository.Repository): Repository.Repository;
  VAR
    parserString: DTD.String;
    att: XMLBuilder.Attribute;
    lastError: Msg.Msg;
    relativeUri, uri: URI.URI;
    str8: ARRAY 4*1024 OF CHAR;
    i: LONGINT;
    
  PROCEDURE Err (code: Msg.Code; xmlNode: Parser.Node);
    BEGIN
      lastError := errorListener. Error (repositoriesContext, code, FALSE, xmlNode. pos)
    END Err;
  
  BEGIN
    FOR i := 0 TO node. attrList. len-1 DO
      att := node. attrList. attr[i];
      Err (invalidAttribute, node);
      lastError. SetLStringAttrib ("name", Msg.GetLStringPtr (att. localName^))
    END;

    IF ~node. HasNoElementContent() THEN
      Err (requireCharDataContent, node)
    ELSE
      parserString := node. GetCharDataContent();
      LongStrings.Short (parserString^, "?", str8);
      IF (str8 = "") THEN
        str8 := "./";
      ELSIF (str8[Strings.Length (str8)-1] # "/") THEN
        Strings.Append ("/", str8);
      END;
      relativeUri := File.ToURI(str8);   (* transform into URI for quoting *)
      TRY
        uri := URIParser.NewURI(relativeUri.ToString(),
                                FileSystemRepository.baseURI);
        RETURN FileSystemRepository.New (baseRep, uri(URI.HierarchicalURI));
      CATCH Exception.ParseError:
        Err (invalidURI, node);
      END
    END;
    RETURN NIL
  END ProcessElement;

BEGIN
  NEW (repositoriesContext);
  Msg.InitContext (repositoriesContext, "OOC:Config:FileSystem");
  Repositories.AddRepositoryEntry (NewRepositoryEntry())
END OOC:Config:FileSystem.
