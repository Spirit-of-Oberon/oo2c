MODULE OOC:Config:Repositories [OOC_EXTENSIONS];

IMPORT
  Msg, Channel, TextRider, LongStrings, URI, XML:DTD, XML:Locator,
  Config:Parser, CS := Config:Section, OOC:Repository;


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

PROCEDURE (s: Section) GetModule* (moduleName: ARRAY OF CHAR): Repository.Module;
(**Tries to locate module @oparam{moduleName} in the configured repositories.
   On success, result is a reference to the module; on failure, result is
   @code{NIL}.
   
   Multiple calls to this function using the same module name are guaranteed
   to return the same object.  That is, this function caches all retrieved
   modules and produces module references from the cache for subsequent
   queries.  *)
  VAR
    m: Repository.Module;
    topLevelRep: Repository.Repository;
    new: ModuleList;
    i: LONGINT;
  BEGIN
    (* scan the cache for this module name; linear search isn't exactly fast
       for huge module sets, so maybe we should improve this later... *)
    i := 0;
    WHILE (i # s. lenCache) & (s. cache[i]. name^ # moduleName) DO
      INC (i)
    END;
    IF (i # s. lenCache) THEN            (* gotcha *)
      RETURN s. cache[i]
    END;
    
    (* module not found in cache: traverse repositories *)
    topLevelRep := s. topLevelRep;
    REPEAT
      m := topLevelRep. GetModule (moduleName);
      topLevelRep := topLevelRep. baseRep
    UNTIL (m # NIL) OR (topLevelRep = NIL);
    
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
    
    RETURN m
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

BEGIN
  NEW (repositoriesContext);
  Msg.InitContext (repositoriesContext, "OOC:Config:Repositories");
  repositoryEntries := NIL
END OOC:Config:Repositories.
