MODULE OOC:Package;

IMPORT
  Log, Msg, URI, URI:Scheme:File,
  XMLError := XML:Error, XML:Locator, XML:DTD, XML:Builder,
  Config:Parser, OOC:Logger, OOC:Error;

TYPE
  URIBuffer = ARRAY 1024 OF CHAR;

CONST
  rootPackage = "package";

TYPE
  Version* = POINTER TO VersionDesc;
  VersionDesc = RECORD
    current-, age-, revision-: DTD.String; 
  END;
  
TYPE
  Package* = POINTER TO PackageDesc;
  PackageDesc = RECORD
    name-: DTD.String;
    version-: Version;
  END;
  
CONST
  invalidContent = 0;
  invalidRootName = 1;
  invalidCharData = 2;
  invalidAttribute = 3;
  junkAtEndOfElement = 4;
  requireNameAttribute = 5;
  requireVersionElement = 6;
  requireCurrentAttribute = 7;
  requireRevisionAttribute = 8;
  
TYPE
  ErrorContext = POINTER TO ErrorContextDesc;
  ErrorContextDesc = RECORD  (* stateless *)
    (XMLError.ContextDesc)
  END;

VAR
  packageContext: ErrorContext;


PROCEDURE (context: ErrorContext) GetTemplate* (msg: Msg.Msg; VAR templ: Msg.LString);
  VAR
    t: ARRAY 128 OF Msg.LChar;
  BEGIN
    CASE msg. code OF
    | invalidContent:
      t := "Invalid content for element `${name}'"
    | invalidRootName:
      t := "Name of root element must be `${name}'"
    | invalidCharData:
      t := "Element must only contain whitespace character data"
    | invalidAttribute:
      t := "Attribute `${name}' is not defined for this element"
    | junkAtEndOfElement:
      t := "Junk at end of element"
    | requireNameAttribute:
      t := "This element requires an attribute `name'"
    | requireVersionElement:
      t := "Expected child element `version'"
    | requireCurrentAttribute:
      t := "This element requires an attribute `current'"
    | requireRevisionAttribute:
      t := "This element requires an attribute `revision'"
    END;
    context. WriteTemplate (msg, t, templ)
  END GetTemplate;

PROCEDURE NewVersion(): Version;
  VAR
    version: Version;
  BEGIN
    NEW(version);
    version.current := NIL;
    version.age := NIL;
    version.revision := NIL;
    RETURN version;
  END NewVersion;

PROCEDURE NewPackage(): Package;
  VAR
    p: Package;
  BEGIN
    NEW(p);
    p.name := NIL;
    RETURN p;
  END NewPackage;


PROCEDURE ProcessPackage (root: Parser.Element;
                          errorListener: Locator.ErrorListener): Package;
  VAR
    lastError: Msg.Msg;
    node: Parser.Node;
    pkg: Package;
    i: LONGINT;
    att: Builder.Attribute;
    
  PROCEDURE Err(code: Msg.Code; xmlNode: Parser.Node);
    BEGIN
      lastError := errorListener.Error(packageContext, code, FALSE,
                                       xmlNode. pos);
    END Err;

  PROCEDURE SkipWS;
    BEGIN
      WHILE (node # NIL) & (node IS Parser.CharData) DO
        IF ~node.IsWhitespace() THEN
          Err(invalidCharData, node);
        END;
        node := node.nextNode;
      END;
    END SkipWS;

  PROCEDURE AtElement(elementName: ARRAY OF LONGCHAR): BOOLEAN;
    BEGIN
      RETURN (node # NIL) &
          (node IS Parser.Element) &
          (node(Parser.Element).name^ = elementName);
    END AtElement;

  PROCEDURE ParseVersion(elem: Parser.Element): Version;
    VAR
      i: LONGINT;
      version: Version;
    BEGIN
      version := NewVersion();
      FOR i := 0 TO elem.attrList.len-1 DO
        att := elem.attrList.attr[i];
        IF (att.localName^ = "current") THEN
          version.current := att.value.Flatten(att.attrDecl);
        ELSIF (att.localName^ = "age") THEN
          version.age := att.value.Flatten(att.attrDecl);
        ELSIF (att.localName^ = "revision") THEN
          version.revision := att.value.Flatten(att.attrDecl);
        ELSE
          Err(invalidAttribute, elem);
          lastError.SetLStringAttrib("name", Msg.GetLStringPtr(att.localName^));
        END
      END;
      IF (version.current = NIL) THEN
        Err(requireCurrentAttribute, elem);
      END;
      IF (version.revision = NIL) THEN
        Err(requireRevisionAttribute, elem);
      END;
      IF (elem.content # NIL) THEN
        Err(invalidContent, elem.content);
        lastError.SetLStringAttrib("name", Msg.GetLStringPtr(elem.name^));
      END;
      SkipWS;
      RETURN version;
    END ParseVersion;
  
  BEGIN
    IF (root.name^ # rootPackage) THEN
      Err (invalidRootName, root);
      lastError.SetLStringAttrib("name", Msg.GetLStringPtr(rootPackage));
    END;

    pkg := NewPackage();
    FOR i := 0 TO root.attrList.len-1 DO
      att := root.attrList.attr[i];
      IF (att.localName^ = "name") THEN
        pkg.name := att.value.Flatten(att.attrDecl);
      ELSE
        Err(invalidAttribute, root);
        lastError.SetLStringAttrib("name", Msg.GetLStringPtr(att.localName^));
      END
    END;
    IF (pkg.name = NIL) THEN
      Err(requireNameAttribute, root);
    END;
    
    node := root.content;
    SkipWS;
    IF AtElement("version") THEN
      pkg.version := ParseVersion(node(Parser.Element));
    ELSE
      Err(requireVersionElement, node);
    END;
    
    WHILE AtElement("requires") DO
      SkipWS;
    END;
    IF AtElement("pragma-list") THEN
      SkipWS;
    END;
    WHILE AtElement("library") DO
      SkipWS;
    END;
    WHILE AtElement("executable") DO
      SkipWS;
    END;
    WHILE AtElement("file-set") DO
      SkipWS;
    END;
    IF (node # NIL) THEN
      Err(junkAtEndOfElement, node);
    END;
    RETURN pkg;
  END ProcessPackage;

PROCEDURE DumpPackage (pkg: Package);
  BEGIN
    Log.LString("pkg.name", pkg.name^);
    Log.LString("pkg.version.current", pkg.version.current^);
    IF (pkg.version.age # NIL) THEN
      Log.LString("pkg.version.age", pkg.version.age^);
    END;
    Log.LString("pkg.version.revision", pkg.version.revision^);
  END DumpPackage;

PROCEDURE ParseFile* (fileName: URI.URI; VAR errList: Error.List);
  VAR
    p: Parser.Parser;
    res: Msg.Msg;
    path: URIBuffer;
    pkg: Package;
  BEGIN
    Logger.ReadFile(fileName);
    fileName(File.URI).GetPath(path);
    p := Parser.NewFile (path, res);
    IF (res # NIL) THEN
      errList.Append (res)
    ELSE
      p.ParseDocument();
      IF (p.errList.msgCount = 0) THEN
        pkg := ProcessPackage(p.root, p.errorListener);
        DumpPackage(pkg);
      ELSE
        errList.AppendList(p.errList)
      END
    END
  END ParseFile;

BEGIN
  NEW (packageContext);
  Msg.InitContext (packageContext, "OOC:Package");
END OOC:Package.
