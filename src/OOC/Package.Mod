MODULE OOC:Package;

IMPORT
  IntStr, LongStrings, Msg, Strings, ADT:Object, ADT:String, ADT:ArrayList,
  URI, FileURI := URI:Scheme:File,
  XMLError := XML:Error, XML:Locator, XML:DTD, XML:Builder,
  Config:Parser, OOC:Logger, OOC:Error;

TYPE
  URIBuffer = ARRAY 1024 OF CHAR;

CONST
  rootPackage = "package";

TYPE
  Version = POINTER TO VersionDesc;
  VersionDesc = RECORD
    current, age, revision: LONGINT;  (* unsigned integers *)
    tuple-: ARRAY 32 OF CHAR;
  END;

TYPE
  Executable* = POINTER TO ExecutableDesc;
  ExecutableDesc = RECORD
    (Object.ObjectDesc)
    mainModule-: String.String; 
  END;
  
TYPE
  Library* = POINTER TO LibraryDesc;
  LibraryDesc = RECORD
    (Object.ObjectDesc)
    name-: String.String;
    mainModule-: String.String;
    version-: Version;
  END;

TYPE
  FileData* = POINTER TO FileDataDesc;
  FileDataDesc = RECORD
    nextFileData-: FileData;
  END;
  
TYPE
  File* = POINTER TO FileDesc;
  FileDesc = RECORD
    (FileDataDesc)
    name-: String.String;
    destName-: String.String;
  END;

TYPE
  FileSet* = POINTER TO FileSetDesc;
  FileSetDesc = RECORD
    (FileDataDesc)
    sourceDir: String.String;
    destDir: String.String;
    head-, tail: FileData;
  END;
  
TYPE
  Package* = POINTER TO PackageDesc;
  PackageDesc = RECORD
    name-: String.String;
    version: Version;
    library-: ArrayList.ArrayList;
    executable-: ArrayList.ArrayList;
    fileSet-: FileSet;
    (**This is a reference to a file set with a source and destination
       path of @samp{.}.  *)
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
  requireSourceDirAttribute = 10;
  requireFileOrFileSet = 11;
  notUnsignedInteger = 12;
  
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
    | requireSourceDirAttribute:
      t := "This element requires an attribute `source-dir'"
    | requireFileOrFileSet:
      t := "Expected child element `file' or `file-set'"
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

PROCEDURE InitFileData(fdata: FileData);
  BEGIN
    fdata.nextFileData := NIL;
  END InitFileData;

PROCEDURE NewFileSet(): FileSet;
  VAR
    fileSet: FileSet;
  BEGIN
    NEW(fileSet);
    InitFileData(fileSet);
    fileSet.sourceDir := NIL;
    fileSet.destDir := NIL;
    fileSet.head := NIL;
    fileSet.tail := NIL;
    RETURN fileSet;
  END NewFileSet;

PROCEDURE (fileSet: FileSet) Append*(fdata: FileData);
  BEGIN
    IF (fileSet.tail = NIL) THEN
      fileSet.head := fdata;
    ELSE
      fileSet.tail.nextFileData := fdata;
    END;
    fileSet.tail := fdata;
  END Append;

PROCEDURE NewFile*(name, destName: String.String): File;
  VAR
    file: File;
  BEGIN
    NEW(file);
    InitFileData(file);
    file.name := name;
    file.destName := destName;
    RETURN file;
  END NewFile;

PROCEDURE NewPackage(): Package;
  VAR
    p: Package;
  BEGIN
    NEW(p);
    p.name := NIL;
    p.version := NIL;
    p.library := ArrayList.New(4);
    p.executable := ArrayList.New(4);
    p.fileSet := NIL;
    RETURN p;
  END NewPackage;


PROCEDURE Normalize*(fileSet: FileSet): FileSet;
(**Converts a hierarchy of file sets and files into a flat list of files.

   @itemize @bullet
   @item
   The top-level file set has a source and destination directory of @samp{.}.

   @item
   No file sets are contained within the top-level file set, only files.

   @item
   The source and destination names of all file entries are fully expanded.

   @item
   Files are sorted first by destination name, then by source name.

   @item
   Sequences of @samp{/} are replaced with a single @samp{/}.

   @item
   Path segments @samp{./} are eliminated.

   @item
   Path segments @samp{../} are expanded in place.  If such a segment 
   appears at the beginning of a path, then it is discarded.

   @item
   Trailing @samp{/} characters are removed from file paths.
   @end itemize  *)
  VAR
    norm: FileSet;
    buffer: POINTER TO ARRAY OF CHAR;
    
  PROCEDURE NormalizeFileSet(fileSet: FileSet;
                             sourcePrefix, destPrefix: String.String);
    VAR
      ptr: FileData;

    PROCEDURE NormalizeFile(file: File);
      VAR
        nFile: File;
        name, destName: String.String;

      PROCEDURE NormalizePath(path: String.String): String.String;
        VAR
          i, j: INTEGER;
        BEGIN
          IF (buffer = NIL) OR (path.length >= LEN(buffer^)) THEN
            NEW(buffer, path.length+1);
          END;
          COPY(path.array^, buffer^);

          i := 0;
          WHILE (buffer[i] # 0X) DO
            IF (buffer[i] = "/") THEN
              (* eliminate second slash of "//" *)
              Strings.Delete(buffer^, i, 1);
            ELSIF (buffer[i] = ".") & (buffer[i+1] = "/") THEN
              (* eliminate dot segment of "/./" *)
              Strings.Delete(buffer^, i, 2);
            ELSIF (buffer[i] = ".") & (buffer[i+1] = ".") &
                  (buffer[i+2] = "/")  THEN
              IF (i = 0) THEN
                (* eliminate "..": "../" turns into "" *)
                Strings.Delete(buffer^, i, 3);
              ELSE
                (* eliminate "..": "/foo/../" turns into "/" *)
                j := i;
                REPEAT
                  DEC(j);
                UNTIL (j = 0) OR (buffer[j-1] = "/");
                Strings.Delete(buffer^, j, i-j+3);
                i := j;
              END;
            ELSE  (* move `i' past next "/" *)
              LOOP
                IF (buffer[i] = 0X) THEN
                  EXIT;
                ELSIF (buffer[i] = "/") THEN
                  INC(i);
                  EXIT;
                ELSE
                  INC(i);
                END;
              END;
            END;
          END;

          (* eliminate trailing "/" *)
          WHILE (i # 0) & (buffer[i-1] = "/") DO
            DEC(i);
          END;
          buffer[i] := 0X;
          
          IF (i # path.length) THEN
            RETURN String.NewRegion(buffer^, 0, i);
          ELSE  (* no changes, reuse old string *)
            RETURN path;
          END;
        END NormalizePath;
      
      BEGIN
        name := NormalizePath(sourcePrefix.Concat(file.name));
        IF (file.destName # NIL) THEN
          destName := NormalizePath(destPrefix.Concat(file.destName));
        ELSE
          destName := NormalizePath(destPrefix.Concat(file.name));
        END;
        nFile := NewFile(name, destName);
        norm.Append(nFile);
      END NormalizeFile;
    
    BEGIN
      sourcePrefix := sourcePrefix.Concat(fileSet.sourceDir);
      sourcePrefix := sourcePrefix.Concat(String.New("/"));
      IF (fileSet.destDir # NIL) THEN
        destPrefix := destPrefix.Concat(fileSet.destDir);
      ELSE
        destPrefix := destPrefix.Concat(fileSet.sourceDir);
      END;
      destPrefix := destPrefix.Concat(String.New("/"));
      
      ptr := fileSet.head;
      WHILE (ptr # NIL) DO
        WITH ptr: FileSet DO
          NormalizeFileSet(ptr, sourcePrefix, destPrefix);
        | ptr: File DO
          NormalizeFile(ptr);
        END;
        ptr := ptr.nextFileData;
      END;
    END NormalizeFileSet;
  
  PROCEDURE MergeSort(list: FileData): FileData;
    VAR
      ptr, next, a, b, tail: FileData;

    PROCEDURE Less(a, b: File): BOOLEAN;
      VAR
        cmp: LONGINT;
      BEGIN
        cmp := a.destName.Compare(b.destName);
        IF (cmp = 0) THEN
          cmp := a.name.Compare(b.name);
        END;
        RETURN (cmp < 0);
      END Less;
    
    BEGIN
      IF (list = NIL) OR (list.nextFileData = NIL) THEN
        RETURN list;
      ELSE
        a := NIL; b := NIL;

        (* split `list' into lists `a' and `b' *)
        ptr := list;
        WHILE (ptr # NIL) DO
          next := ptr.nextFileData;
          ptr.nextFileData := a;
          a := ptr;
          ptr := next;

          IF (ptr # NIL) THEN
            next := ptr.nextFileData;
            ptr.nextFileData := b;
            b := ptr;
            ptr := next;
          END;
        END;

        (* sort `a' and `b' *)
        a := MergeSort(a);
        b := MergeSort(b);

        (* merge `a' and `b' into a sorted list *)
        list := NewFile(NIL, NIL); tail := list;
        WHILE (a # NIL) OR (b # NIL) DO
          IF (a # NIL) & ((b = NIL) OR Less(a(File), b(File))) THEN
            ptr := a; a := a.nextFileData;
          ELSE
            ptr := b; b := b.nextFileData;
          END;
          ptr.nextFileData := NIL;
          tail.nextFileData := ptr;
          tail := ptr;
        END;
        RETURN list.nextFileData;
      END;
    END MergeSort;
  
  BEGIN
    buffer := NIL;
    norm := NewFileSet();
    norm.sourceDir := String.New(".");
    norm.destDir := norm.sourceDir;

    NormalizeFileSet(fileSet, String.New(""), String.New(""));
    norm.head := MergeSort(norm.head);
    norm.tail := norm.head;
    WHILE (norm.tail.nextFileData # NIL) DO
      norm.tail := norm.tail.nextFileData;
    END;
    
    (*ptr := norm.head;
    WHILE (ptr # NIL) DO
      Log.String("source", ptr(File).name.array^);
      Log.String("  --> dest", ptr(File).destName.array^);
      ptr := ptr.nextFileData;
    END;*)
    
    RETURN norm;
  END Normalize;

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

  PROCEDURE StringAttr(att: Builder.Attribute): String.String;
    VAR
      str: DTD.String;
      buffer: POINTER TO ARRAY OF CHAR;
    BEGIN
      str := att.value.Flatten(att.attrDecl);
      NEW(buffer, LEN(str^));
      LongStrings.Short(str^, "?", buffer^);
      RETURN String.New(buffer^);
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
  
  PROCEDURE ParseFileSet(elem: Parser.Element): FileSet;
  (* pre: element.name="file-set" *)
    VAR
      i: LONGINT;
      fileSet: FileSet;
      node: Parser.Node;

    PROCEDURE ParseFile(elem: Parser.Element): File;
    (* pre: element.name="file" *)
      VAR
        i: LONGINT;
        node: Parser.Node;
        name, destName: String.String;
      BEGIN
        name := NIL;
        destName := NIL;
        FOR i := 0 TO elem.attrList.len-1 DO
          att := elem.attrList.attr[i];
          IF (att.localName^ = "name") THEN
            name := StringAttr(att);
          ELSIF (att.localName^ = "dest-name") THEN
            destName := StringAttr(att);
          ELSE
            Err(invalidAttribute, elem);
            lastError.SetLStringAttrib("name", Msg.GetLStringPtr(att.localName^));
          END
        END;
        IF (name = NIL) THEN
          Err(requireNameAttribute, elem);
        END;
        
        node := elem.content;
        SkipWS(node);
        IF (node # NIL) THEN
          Err(junkAtEndOfElement, node);
        END;
        
        RETURN NewFile(name, destName);
      END ParseFile;
    
    BEGIN
      fileSet := NewFileSet();
      FOR i := 0 TO elem.attrList.len-1 DO
        att := elem.attrList.attr[i];
        IF (att.localName^ = "source-dir") THEN
          fileSet.sourceDir := StringAttr(att);
        ELSIF (att.localName^ = "dest-dir") THEN
          fileSet.destDir := StringAttr(att);
        ELSE
          Err(invalidAttribute, elem);
          lastError.SetLStringAttrib("name", Msg.GetLStringPtr(att.localName^));
        END
      END;
      IF (fileSet.sourceDir = NIL) THEN
        Err(requireSourceDirAttribute, elem);
      END;

      node := elem.content;
      SkipWS(node);
      WHILE (node # NIL) DO
        IF AtElement(node, "file-set") THEN
          fileSet.Append(ParseFileSet(node(Parser.Element)));
          node := node.nextNode;
        ELSIF AtElement(node, "file") THEN
          fileSet.Append(ParseFile(node(Parser.Element)));
          node := node.nextNode;
        ELSE
          Err(requireFileOrFileSet, node);
          node := node.nextNode;
        END;
        SkipWS(node);
      END;
      RETURN fileSet;
    END ParseFileSet;
  
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

    pkg.fileSet := NewFileSet();
    pkg.fileSet.sourceDir := String.New(".");
    pkg.fileSet.destDir := String.New(".");
    WHILE AtElement(node, "file-set") DO
      pkg.fileSet.Append(ParseFileSet(node(Parser.Element)));
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
    fileName(FileURI.URI).GetPath(path);
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
