(* 	$Id: Repositories.Mod,v 1.23 2003/06/05 22:09:32 mva Exp $	 *)
MODULE OOC:Config:Repositories [OOC_EXTENSIONS];
(*  Management of a hierarchy of configured repositories.
    Copyright (C) 2001-2003  Michael van Acken

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
  Msg, Channel, TextRider, LongStrings,
  Object, URI, URI:Scheme:File, 
  XML:DTD, XML:Locator, Config:Parser, CS := Config:Section,
  OOC:Repository, OOC:Repository:FileSystem;


TYPE
  Section* = POINTER TO SectionDesc;
  ModuleList = POINTER TO ARRAY OF Repository.Module;
  SectionDesc = RECORD
    (CS.SectionDesc)
    topLevelRep-: Repository.Repository;
    cache: ModuleList;
    lenCache: LONGINT;
  END;
  
TYPE
  RepositoryEntry* = POINTER TO RepositoryEntryDesc;
  RepositoryEntryDesc* = RECORD [ABSTRACT]
    next: RepositoryEntry;
    name: ARRAY 32 OF DTD.Char;
  END;

CONST
  invalidContent = 1;
  invalidAttribute = 2;
  requireEmpty = 3;
  
TYPE
  ErrorContext = POINTER TO ErrorContextDesc;
  ErrorContextDesc = RECORD  (* stateless *)
    (CS.ErrorContextDesc)
  END;

VAR
  repositoriesContext: ErrorContext;
  repositoryEntries: RepositoryEntry;


PROCEDURE (context: ErrorContext) GetTemplate* (msg: Msg.Msg; VAR templ: Msg.LString);
  VAR
    t: ARRAY 128 OF Msg.LChar;
  BEGIN
    CASE msg. code OF
    | invalidContent:
      t := "Invalid content for element `${name}'"
    | invalidAttribute:
      t := "Attribute `${name}' is not defined for this element"
    | requireEmpty:
      t := "This element must be empty"
    END;
    context. WriteTemplate (msg, t, templ)
  END GetTemplate;



PROCEDURE Init (s: Section; id: Parser.String);
  BEGIN
    CS.Init (s, id);
    s. topLevelRep := NIL;
    NEW (s. cache, 64);
    s. lenCache := 0;
  END Init;

PROCEDURE New* (): Section;
  CONST
    sectionName = "repositories";
  VAR
    s: Section;
  BEGIN
    NEW (s);
    Init (s, sectionName);
    RETURN s
  END New;

PROCEDURE InitRepositoryEntry* (re: RepositoryEntry; name: ARRAY OF CHAR);
  BEGIN
    re. next := NIL;
    COPY (name, re. name);
  END InitRepositoryEntry;

PROCEDURE (re: RepositoryEntry) [ABSTRACT] ProcessElement*
                       (node: Parser.Element;
                        errorListener: Locator.ErrorListener;
                        baseRep: Repository.Repository): Repository.Repository;
  END ProcessElement;
  
PROCEDURE AddRepositoryEntry* (re: RepositoryEntry);
  BEGIN
    re. next := repositoryEntries;
    repositoryEntries := re
  END AddRepositoryEntry;



PROCEDURE (s: Section) ProcessElements* (sectionRoot: Parser.Element;
                                         errorListener: Locator.ErrorListener);
  VAR
    node: Parser.Node;
    lastError: Msg.Msg;
    re: RepositoryEntry;
    rep: Repository.Repository;
    
  PROCEDURE Err (code: Msg.Code; xmlNode: Parser.Node);
    BEGIN
      lastError := errorListener. Error (repositoriesContext, code, FALSE, xmlNode. pos)
    END Err;
  
  BEGIN
    node := sectionRoot. content;
    WHILE (node # NIL) DO
      WITH node: Parser.Element DO
        re := repositoryEntries;
        WHILE (re # NIL) & (re. name # node. name^) DO
          re := re. next
        END;
        
        IF (re # NIL) THEN
          rep := re. ProcessElement (node, errorListener, s. topLevelRep);
          IF (rep # NIL) THEN
            s. topLevelRep := rep
          END
        ELSE
          Err (invalidContent, node);
          lastError. SetLStringAttrib ("name", Msg.GetLStringPtr (s. name^))
        END
        
      | node: Parser.CharData DO
        IF ~node. IsWhitespace() THEN
          Err (invalidContent, node)
        END
      END;
      node := node. nextNode
    END
  END ProcessElements;

PROCEDURE (s: Section) DumpContent* (ch: Channel.Channel);
  VAR
    w: TextRider.Writer;
    str8: ARRAY 2048 OF CHAR;
  
  PROCEDURE Write (rep: Repository.Repository);
    BEGIN
      IF (rep # NIL) THEN
        Write (rep. baseRep);
        rep. DumpContent (w)
      END
    END Write;
  
  BEGIN
    w := TextRider.ConnectWriter (ch);
    LongStrings.Short (s. name^, "?", str8);
    w. WriteString ("<");
    w. WriteString (str8);
    w. WriteString (">"); w. WriteLn;
    Write (s. topLevelRep);
    LongStrings.Short (s. name^, "?", str8);
    w. WriteString ("</");
    w. WriteString (str8);
    w. WriteString (">"); w. WriteLn
  END DumpContent;

PROCEDURE (s: Section) GetModule* (moduleRef: ARRAY OF CHAR): Repository.Module;
(**Tries to locate the module corresponding to @oparam{moduleRef} in the
   configured repositories.  On success, result is a reference to the module;
   on failure, result is @code{NIL}.

   Depending on the module reference, the module is located by different means.
   The reference can be one of the following:

   @table @asis
   @item A Module Name
   In this case, the top-most repository that contains the sources for this
   module is used.  This is the preferred way to identify modules.

   @item A File Name in a Repository
   The referred to repository is used.  Note that this may cause problems, if a
   repository with a higher priority also defines a module of the same name.

   @item An Arbitrary File Name
   The module is presumed to belong to the repository with the highest
   priority.  The module's source code is taken from the file name, but all
   output files are written into the repository.  This mechanism should only be
   used in test setups where the input files are not organized into
   repositories, for example with the Hostess test suite.
   @end table

   Multiple calls to this function using the same module reference are
   guaranteed to return the same object.  That is, this function caches all
   retrieved modules and produces module references from the cache for
   subsequent queries.  *)
  VAR
    m: Repository.Module;
    topLevelRep: Repository.Repository;
    i: LONGINT;
    file: File.URI;
  
  PROCEDURE AddToCache (m: Repository.Module);
    VAR
      new: ModuleList;
      i: LONGINT;
    BEGIN
      (* if we found a module, then add it to the cache *)
      IF (m # NIL) THEN
        IF (s. lenCache = LEN (s. cache^)) THEN
          NEW (new, LEN (s. cache^)*2);
          FOR i := 0 TO LEN (s. cache^)-1 DO
            new[i] := s. cache[i]
          END;
          s. cache := new
        END;
        s. cache[s. lenCache] := m;
        INC (s. lenCache)
      END;
    END AddToCache;
  
  BEGIN
    IF Repository.ValidModuleName (moduleRef) OR (moduleRef[0] = "#") THEN
      (* note: moduleRef[0]="#" selects predefined modules *)
      (* scan the cache for this module name; linear search isn't exactly fast
         for huge module sets, so maybe we should improve this later... *)
      i := 0;
      WHILE (i # s. lenCache) & (s. cache[i]. name^ # moduleRef) DO
        INC (i)
      END;
      IF (i # s. lenCache) THEN            (* gotcha *)
        RETURN s. cache[i]
      END;

      (* module not found in cache: traverse repositories *)
      topLevelRep := s. topLevelRep;
      REPEAT
        m := topLevelRep. GetModule (moduleRef, NIL);
        topLevelRep := topLevelRep. baseRep
      UNTIL (m # NIL) OR (topLevelRep = NIL);

      (* if we found a module, then add it to the cache *)
      AddToCache (m);
      RETURN m
      
    ELSE
      (* scan the cache for this file name; linear search isn't exactly fast
         for huge module sets, so maybe we should improve this later... *)
      file := File.ToURI (moduleRef);
      
      i := 0;
      WHILE (i # s. lenCache) & (s. cache[i]. MatchesURI (Repository.modModuleSource, file)) DO
        INC (i)
      END;
      IF (i # s. lenCache) THEN            (* gotcha *)
        RETURN s. cache[i]
      END;

      (* file name not found in cache: traverse repositories *)
      topLevelRep := s. topLevelRep;
      REPEAT
        m := topLevelRep. GetModuleByURI (file, FALSE);
        topLevelRep := topLevelRep. baseRep
      UNTIL (m # NIL) OR (topLevelRep = NIL);
      
      IF (m = NIL) THEN
        m := s. topLevelRep. GetModuleByURI (file, TRUE)
      END;
      
      AddToCache (m);
      RETURN m
    END
  END GetModule;

PROCEDURE (s: Section) GetResource* (package, path: ARRAY OF CHAR): URI.URI;
(**Tries to locate the resource file @oparam{path} under the package
   directory @oparam{package} in the configured repositories.  On success, an
   URI for the file is returned.  Otherwise, result is @code{NIL}.  *)
  VAR
    uri: URI.URI;
    topLevelRep: Repository.Repository;
  BEGIN
    topLevelRep := s. topLevelRep;
    REPEAT
      uri := topLevelRep. GetResource (package, path);
      topLevelRep := topLevelRep. baseRep
    UNTIL (uri # NIL) OR (topLevelRep = NIL);
    RETURN uri
  END GetResource;

PROCEDURE (s: Section) GetIncludePaths*(): Object.StringArrayPtr;
  VAR
    rep: Repository.Repository;
    c: LONGINT;
    result: Object.StringArrayPtr;
    
  PROCEDURE Select (rep: Repository.Repository): BOOLEAN;
    BEGIN
      RETURN (rep IS FileSystem.Repository)
    END Select;
  
  BEGIN
    c := 0;
    rep := s. topLevelRep;
    WHILE (rep # NIL) & Select (rep) DO
      INC (c);
      rep := rep. baseRep
    END;
    
    NEW (result, c);
    c := 0;
    rep := s. topLevelRep;
    WHILE (rep # NIL) DO
      IF Select (rep) THEN
        result[c] := 
            rep(FileSystem.Repository).relativeBaseURI(File.URI).GetPath()+
            rep.GetDefaultSubdir(Repository.modHeaderFileC);
        INC (c);
      END;
      rep := rep. baseRep
    END;
    RETURN result
  END GetIncludePaths;

BEGIN
  URI.RegisterScheme(File.NewPrototype());
  NEW (repositoriesContext);
  Msg.InitContext (repositoriesContext, "OOC:Config:Repositories");
  repositoryEntries := NIL
END OOC:Config:Repositories.
