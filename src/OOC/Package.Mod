MODULE OOC:Package;

IMPORT
  IntStr, LongStrings, Msg, Strings, ADT:Object, ADT:ArrayList,
  URI, URI:Scheme:File,
  XMLError := XML:Error, XML:Locator, XML:DTD, XML:Builder,
  Config:Parser, OOC:Logger, OOC:Error;

TYPE
  URIBuffer = ARRAY 1024 OF CHAR;

CONST
  rootPackage = "package";

TYPE
  String = POINTER TO ARRAY OF CHAR;
  Version = POINTER TO VersionDesc;
  VersionDesc = RECORD
    current, age, revision: LONGINT;  (* unsigned integers *)
    tuple-: ARRAY 32 OF CHAR;
  END;

TYPE
  Executable* = POINTER TO ExecutableDesc;
  ExecutableDesc = RECORD
    (Object.ObjectDesc)
    mainModule-: String; 
  END;
  
TYPE
  Library* = POINTER TO LibraryDesc;
  LibraryDesc = RECORD
    (Object.ObjectDesc)
    name-: String;
    mainModule-: String;
    version-: Version;
  END;
  
TYPE
  Package* = POINTER TO PackageDesc;
  PackageDesc = RECORD
    name-: String;
    version: Version;
    library-: ArrayList.ArrayList;
    executable-: ArrayList.ArrayList;
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
  requireMainModuleAttribute = 9;
  notUnsignedInteger = 10;
  
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
      t := "Only whitespace character data allowed here"
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
    | requireMainModuleAttribute:
      t := "This element requires an attribute `main-module'"      
    | notUnsignedInteger:
      t := "Attribute `${name}' must be an unsigned integer"
    END;
    context. WriteTemplate (msg, t, templ)
  END GetTemplate;

PROCEDURE NewVersion(): Version;
  VAR
    version: Version;
  BEGIN
    NEW(version);
    version.current := -1;
    version.age := 0;
    version.revision := -1;
    version.tuple := "";
    RETURN version;
  END NewVersion;

PROCEDURE NewExecutable(): Executable;
  VAR
    executable: Executable;
  BEGIN
    NEW(executable);
    Object.Init(executable);
    executable.mainModule := NIL;
    RETURN executable;
  END NewExecutable;

PROCEDURE NewLibrary(): Library;
  VAR
    library: Library;
  BEGIN
    NEW(library);
    Object.Init(library);
    library.mainModule := NIL;
    library.version := NIL;
    RETURN library;
  END NewLibrary;

PROCEDURE NewPackage(): Package;
  VAR
    p: Package;
  BEGIN
    NEW(p);
    p.name := NIL;
    p.version := NIL;
    p.library := ArrayList.New(4);
    p.executable := ArrayList.New(4);
    RETURN p;
  END NewPackage;


PROCEDURE ProcessPackage (root: Parser.Element;
                          errorListener: Locator.ErrorListener;
                          errList: Error.List): Package;
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
      errList.Append(lastError);
    END Err;

  PROCEDURE StringAttr(att: Builder.Attribute): String;
    VAR
      str: DTD.String;
      buffer: String;
    BEGIN
      str := att.value.Flatten(att.attrDecl);
      NEW(buffer, LEN(str^));
      LongStrings.Short(str^, "?", buffer^);
      RETURN buffer;
    END StringAttr;
  
  PROCEDURE SkipWS(VAR node: Parser.Node);
    BEGIN
      WHILE (node # NIL) & (node IS Parser.CharData) DO
        IF ~node.IsWhitespace() THEN
          Err(invalidCharData, node);
        END;
        node := node.nextNode;
      END;
    END SkipWS;

  PROCEDURE AtElement(node: Parser.Node;
                      elementName: ARRAY OF LONGCHAR): BOOLEAN;
    BEGIN
      RETURN (node # NIL) &
          (node IS Parser.Element) &
          (node(Parser.Element).name^ = elementName);
    END AtElement;

  PROCEDURE ParseVersion(elem: Parser.Element): Version;
  (* pre: element.name="version" *)
    VAR
      i: LONGINT;
      version: Version;
      str: ARRAY 32 OF CHAR;

    PROCEDURE Unsigned (att: Builder.Attribute): LONGINT;
      CONST
        bufferSize = 128;
      VAR
        str: DTD.String;
        buffer: ARRAY bufferSize OF CHAR;
        res: IntStr.ConvResults;
        i: LONGINT;
      BEGIN
        str := att.value.Flatten(att.attrDecl);
        IF (LEN(str^) < bufferSize) THEN
          LongStrings.Short(str^, "?", buffer);
          IntStr.StrToInt(buffer, i, res);
          IF (res = IntStr.strAllRight) & (i >= 0) THEN
            RETURN i;
          END;
        END;
        Err(notUnsignedInteger, elem);
        lastError.SetLStringAttrib("name", Msg.GetLStringPtr(att.localName^));
        RETURN 0;
      END Unsigned;
    
    BEGIN
      version := NewVersion();
      FOR i := 0 TO elem.attrList.len-1 DO
        att := elem.attrList.attr[i];
        IF (att.localName^ = "current") THEN
          version.current := Unsigned(att);
        ELSIF (att.localName^ = "age") THEN
          version.age := Unsigned(att);
        ELSIF (att.localName^ = "revision") THEN
          version.revision := Unsigned(att);
        ELSE
          Err(invalidAttribute, elem);
          lastError.SetLStringAttrib("name", Msg.GetLStringPtr(att.localName^));
        END
      END;
      IF (version.current = -1) THEN
        Err(requireCurrentAttribute, elem);
      END;
      IF (version.revision = -1) THEN
        Err(requireRevisionAttribute, elem);
      END;
      IF (elem.content # NIL) THEN
        Err(invalidContent, elem.content);
        lastError.SetLStringAttrib("name", Msg.GetLStringPtr(elem.name^));
      END;
      
      version.tuple := "";
      IntStr.IntToStr(version.current, str);
      Strings.Append(str, version.tuple);
      Strings.Append(":", version.tuple);
      IntStr.IntToStr(version.age, str);
      Strings.Append(str, version.tuple);
      Strings.Append(":", version.tuple);
      IntStr.IntToStr(version.revision, str);
      Strings.Append(str, version.tuple);
      
      RETURN version;
    END ParseVersion;
  
  PROCEDURE ParseExecutable(elem: Parser.Element): Executable;
  (* pre: element.name="executable" *)
    VAR
      i: LONGINT;
      executable: Executable;
    BEGIN
      executable := NewExecutable();
      FOR i := 0 TO elem.attrList.len-1 DO
        att := elem.attrList.attr[i];
        IF (att.localName^ = "main-module") THEN
          executable.mainModule := StringAttr(att);
        ELSE
          Err(invalidAttribute, elem);
          lastError.SetLStringAttrib("name", Msg.GetLStringPtr(att.localName^));
        END
      END;
      IF (executable.mainModule = NIL) THEN
        Err(requireMainModuleAttribute, elem);
      END;
      RETURN executable;
    END ParseExecutable;
  
  PROCEDURE ParseLibrary(elem: Parser.Element): Library;
  (* pre: element.name="library" *)
    VAR
      i: LONGINT;
      library: Library;
      node: Parser.Node;
    BEGIN
      library := NewLibrary();
      FOR i := 0 TO elem.attrList.len-1 DO
        att := elem.attrList.attr[i];
        IF (att.localName^ = "name") THEN
          library.name := StringAttr(att);
        ELSIF (att.localName^ = "main-module") THEN
          library.mainModule := StringAttr(att);
        ELSE
          Err(invalidAttribute, elem);
          lastError.SetLStringAttrib("name", Msg.GetLStringPtr(att.localName^));
        END
      END;
      IF (library.mainModule = NIL) THEN
        Err(requireMainModuleAttribute, elem);
      END;

      node := elem.content;
      SkipWS(node);
      IF AtElement(node, "version") THEN
        library.version := ParseVersion(node(Parser.Element));
        node := node.nextNode;
        SkipWS(node);
      ELSE
        Err(requireVersionElement, node);
      END;
      IF (node # NIL) THEN
        Err(junkAtEndOfElement, node);
      END;
      
      RETURN library;
    END ParseLibrary;
  
  BEGIN
    IF (root.name^ # rootPackage) THEN
      Err (invalidRootName, root);
      lastError.SetLStringAttrib("name", Msg.GetLStringPtr(rootPackage));
    END;

    pkg := NewPackage();
    FOR i := 0 TO root.attrList.len-1 DO
      att := root.attrList.attr[i];
      IF (att.localName^ = "name") THEN
        pkg.name := StringAttr(att);
      ELSE
        Err(invalidAttribute, root);
        lastError.SetLStringAttrib("name", Msg.GetLStringPtr(att.localName^));
      END
    END;
    IF (pkg.name = NIL) THEN
      Err(requireNameAttribute, root);
    END;
    
    node := root.content;
    SkipWS(node);
    IF AtElement(node, "version") THEN
      pkg.version := ParseVersion(node(Parser.Element));
      node := node.nextNode;
      SkipWS(node);
    ELSE
      Err(requireVersionElement, node);
    END;
    
    WHILE AtElement(node, "requires") DO
      node := node.nextNode;
      SkipWS(node);
    END;
    
    IF AtElement(node, "pragma-list") THEN
      SkipWS(node);
    END;
    
    WHILE AtElement(node, "library") DO
      pkg.library.Append(ParseLibrary(node(Parser.Element)));
      node := node.nextNode;
      SkipWS(node);
    END;
    WHILE AtElement(node, "executable") DO
      pkg.executable.Append(ParseExecutable(node(Parser.Element)));
      node := node.nextNode;
      SkipWS(node);
    END;
    
    WHILE AtElement(node, "file-set") DO
      node := node.nextNode;
      SkipWS(node);
    END;
    IF (node # NIL) THEN
      Err(junkAtEndOfElement, node);
    END;
    RETURN pkg;
  END ProcessPackage;

PROCEDURE ParseFile* (fileName: URI.URI; VAR errList: Error.List): Package;
  VAR
    p: Parser.Parser;
    res: Msg.Msg;
    path: URIBuffer;
  BEGIN
    Logger.ReadFile(fileName);
    fileName(File.URI).GetPath(path);
    p := Parser.NewFile (path, res);
    IF (res # NIL) THEN
      errList.Append (res)
    ELSE
      p.ParseDocument();
      IF (p.errList.msgCount = 0) THEN
        RETURN ProcessPackage(p.root, p.errorListener, errList);
      ELSE
        errList.AppendList(p.errList)
      END
    END;
    RETURN NIL;
  END ParseFile;

BEGIN
  NEW (packageContext);
  Msg.InitContext (packageContext, "OOC:Package");
END OOC:Package.
