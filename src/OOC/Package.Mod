MODULE OOC:Package;

IMPORT
  IntStr, LongStrings, Msg, Out, StdChannels, Strings, IO, IO:FileChannel,
  Object, ADT:ArrayList, ADT:StringBuffer, OSFiles := OS:Files,
  OS:ProcessManagement, URI, FileURI:=URI:Scheme:File, XML:UnicodeCodec:Latin1,
  XMLError := XML:Error, XML:Locator, XML:DTD, XML:Builder, XML:Writer,
  Config:Parser, Config:Value, StringValue := Config:Value:String,
  BooleanValue := Config:Value:Boolean, IntegerValue := Config:Value:Integer,
  Config:Section:Options,
  OOC:Logger, OOC:Config, OOC:Error, Rep := OOC:Repository;

TYPE
  URIBuffer = ARRAY 1024 OF CHAR;

CONST
  rootPackage = "package";
  rootRepository = "repository";
  pkgInfoSubdir = "/pkginfo";
  pkgInfoFile = "/pkginfo.xml";
  
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
    mainModule-: STRING; 
  END;
  
TYPE
  Library* = POINTER TO LibraryDesc;
  LibraryDesc = RECORD
    (Object.ObjectDesc)
    name-: STRING;
    mainModule-: STRING;
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
    name-: STRING;
    destName-: STRING;
  END;

TYPE
  FileSet* = POINTER TO FileSetDesc;
  FileSetDesc = RECORD
    (FileDataDesc)
    sourceDir: STRING;
    destDir: STRING;
    head-, tail: FileData;
  END;

TYPE
  KeyValue* = POINTER TO KeyValueDesc;
  KeyValueDesc = RECORD
    (Object.ObjectDesc)
    key-: STRING;
    value-: Value.Value;
  END;

TYPE
  Package* = POINTER TO PackageDesc;
  PackageDesc = RECORD
    (Rep.PkgInfoDesc)
    name-: STRING;
    version: Version;
    library-: ArrayList.ArrayList;
    executable-: ArrayList.ArrayList;
    
    fileSet-: FileSet;
    (**This is a reference to a file set with a source and destination
       path of @samp{.}.  *)
  END;

TYPE
  Repository* = POINTER TO RepositoryDesc;
  RepositoryDesc = RECORD
    (Rep.PkgInfoDesc)
    installedPkgs-: ArrayList.ArrayList;  (* of STRING *)
  END;
  
CONST
  packageData = "pkginfo.xml";

VAR
  stringType: STRING;
  
CONST
  invalidContent = 0;
  invalidRootName = 1;
  invalidCharData = 2;
  invalidAttribute = 3;
  junkAtEndOfElement = 4;
  requireNameAttribute = 5;
  requireVersionChild = 6;
  requireCurrentAttribute = 7;
  requireRevisionAttribute = 8;
  requireMainModuleAttribute = 9;
  requireSourceDirAttribute = 10;
  requireTypeAttribute = 11;
  requireFileOrFileSet = 12;
  requireDefine = 13;
  notUnsignedInteger = 14;
  requireCharacterData = 15;
  unknownType = 16;
  invalidValue = 17;
  
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
    | requireVersionChild:
      t := "Expected child element `version'"
    | requireCurrentAttribute:
      t := "This element requires an attribute `current'"
    | requireRevisionAttribute:
      t := "This element requires an attribute `revision'"
    | requireMainModuleAttribute:
      t := "This element requires an attribute `main-module'"
    | requireSourceDirAttribute:
      t := "This element requires an attribute `source-dir'"
    | requireTypeAttribute:
      t := "This element requires an attribute `type'"
    | requireFileOrFileSet:
      t := "Expected child element `file' or `file-set'"
    | requireDefine:
      t := "Expected child element `define'"
    | notUnsignedInteger:
      t := "Attribute `${name}' must be an unsigned integer"
    | requireCharacterData:
      t := "Only character data allowed here"
    | unknownType:
      t := "Type `${type}' is not supported for this variable"
    | invalidValue:
      t := "Invalid value: ${reason}"
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
    executable.mainModule := NIL;
    RETURN executable;
  END NewExecutable;

PROCEDURE NewLibrary(): Library;
  VAR
    library: Library;
  BEGIN
    NEW(library);
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

PROCEDURE NewFile*(name, destName: STRING): File;
  VAR
    file: File;
  BEGIN
    NEW(file);
    InitFileData(file);
    file.name := name;
    file.destName := destName;
    RETURN file;
  END NewFile;

PROCEDURE NewKeyValue*(key: STRING; value: Value.Value): KeyValue;
  VAR
    kv: KeyValue;
  BEGIN
    NEW(kv);
    kv.key := key;
    kv.value := value;
    RETURN kv;
  END NewKeyValue;

PROCEDURE MergeConfig(pkg: Rep.PkgInfo; options, pragmas: Options.Section);
  VAR
    i: LONGINT;
    kv: KeyValue;
    o: Options.Option;
    chars: Object.CharsLatin1;
  BEGIN
    FOR i := 0 TO pkg.options.size-1 DO
      kv := pkg.options.array[i](KeyValue);
      chars := kv.key(Object.String8).CharsLatin1();
      o := options.Set(chars^, kv.value);
    END;
    FOR i := 0 TO pkg.pragmas.size-1 DO
      kv := pkg.pragmas.array[i](KeyValue);
      chars := kv.key(Object.String8).CharsLatin1();
      o := pragmas.Set(chars^, kv.value);
    END;
  END MergeConfig;

PROCEDURE NewPackage(): Package;
  VAR
    p: Package;
  BEGIN
    NEW(p);
    Rep.InitPkgInfo(p);
    p.name := NIL;
    p.version := NIL;
    p.library := ArrayList.New(4);
    p.executable := ArrayList.New(4);
    p.fileSet := NIL;
    RETURN p;
  END NewPackage;

PROCEDURE NewRepository(): Repository;
  VAR
    r: Repository;
  BEGIN
    NEW(r);
    Rep.InitPkgInfo(r);
    r.installedPkgs := ArrayList.New(4);
    RETURN r;
  END NewRepository;

PROCEDURE (r: Repository) MergePackage(pkg: Package);
  VAR
    i: LONGINT;
    kv: KeyValue;
  BEGIN
    r.installedPkgs.Append(pkg.name);
    FOR i := 0 TO pkg.options.size-1 DO
      kv := pkg.options.array[i](KeyValue);
      r.options.Append(kv);
    END;
    FOR i := 0 TO pkg.pragmas.size-1 DO
      kv := pkg.pragmas.array[i](KeyValue);
      r.pragmas.Append(kv);
    END;
  END MergePackage;

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
                             sourcePrefix, destPrefix: STRING);
    VAR
      ptr: FileData;

    PROCEDURE NormalizeFile(file: File);
      VAR
        nFile: File;
        name, destName: STRING;

      PROCEDURE NormalizePath(path: STRING): STRING;
        VAR
          i, j: INTEGER;
          chars: Object.CharsLatin1;
        BEGIN
          IF (buffer = NIL) OR (path.length >= LEN(buffer^)) THEN
            NEW(buffer, path.length+1);
          END;
          chars := path(Object.String8).CharsLatin1();
          COPY(chars^, buffer^);

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
            RETURN Object.NewLatin1Region(buffer^, 0, i);
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
      sourcePrefix := sourcePrefix+fileSet.sourceDir+"/";
      IF (fileSet.destDir # NIL) THEN
        destPrefix := destPrefix+fileSet.destDir;
      ELSE
        destPrefix := destPrefix+fileSet.sourceDir;
      END;
      destPrefix := destPrefix+"/";
      
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
    norm.sourceDir := ".";
    norm.destDir := norm.sourceDir;

    NormalizeFileSet(fileSet, "", "");
    norm.head := MergeSort(norm.head);
    norm.tail := norm.head;
    IF (norm.tail # NIL) THEN
      WHILE (norm.tail.nextFileData # NIL) DO
        norm.tail := norm.tail.nextFileData;
      END;
    END;
    
    (*ptr := norm.head;
    WHILE (ptr # NIL) DO
      Log.String("source", ptr(File).name.array^);
      Log.String("  --> dest", ptr(File).destName.array^);
      ptr := ptr.nextFileData;
    END;*)
    
    RETURN norm;
  END Normalize;

PROCEDURE StringAttr(att: Builder.Attribute): STRING;
  VAR
    str: DTD.String;
    buffer: POINTER TO ARRAY OF CHAR;
  BEGIN
    str := att.value.Flatten(att.attrDecl);
    NEW(buffer, LEN(str^));
    LongStrings.Short(str^, "?", buffer^);
    RETURN Object.NewLatin1(buffer^);
  END StringAttr;

PROCEDURE AtElement(node: Parser.Node;
                    elementName: ARRAY OF LONGCHAR): BOOLEAN;
  BEGIN
    RETURN (node # NIL) &
        (node IS Parser.Element) &
        (node(Parser.Element).name^ = elementName);
  END AtElement;

PROCEDURE ParseKeyValue(elem: Parser.Element;
                        list: ArrayList.ArrayList;
                        options: Options.Section;
                        defaultType: STRING;
                        errorListener: Locator.ErrorListener;
                        errList: Error.List);
(* pre: element.name="options" or "pragmas" *)
  VAR
    node: Parser.Node;
    lastError: Error.Msg;
    
  PROCEDURE Err(code: Msg.Code; xmlNode: Parser.Node);
    BEGIN
      lastError := errorListener.Error(packageContext, code, FALSE,
                                       xmlNode. pos);
      errList.Append(lastError);
    END Err;

  PROCEDURE SkipWS(VAR node: Parser.Node);
    BEGIN
      WHILE (node # NIL) & (node IS Parser.CharData) DO
        IF ~node.IsWhitespace() THEN
          Err(invalidCharData, node);
        END;
        node := node.nextNode;
      END;
    END SkipWS;

  PROCEDURE ParseDefine(elem: Parser.Element): KeyValue;
  (* pre: element.name="define" *)
    VAR
      i: LONGINT;
      node: Parser.Node;
      name, type: STRING;
      value: Value.Value;
      str: ARRAY 1024 OF CHAR;
      att: Builder.Attribute;
      stringBuffer: STRING;
      errMsg: Msg.Msg;
      chars: Object.CharsLatin1;
    BEGIN
      name := NIL;
      type := defaultType;
      FOR i := 0 TO elem.attrList.len-1 DO
        att := elem.attrList.attr[i];
        IF (att.localName^ = "name") THEN
          name := StringAttr(att);
        ELSIF (att.localName^ = "type") THEN
          type := StringAttr(att);
        ELSE
          Err(invalidAttribute, elem);
          lastError.SetLStringAttrib("name", Msg.GetLStringPtr(att.localName^));
        END
      END;
      IF (name = NIL) THEN
        Err(requireNameAttribute, elem);
        RETURN NIL;
      ELSIF (type = NIL) THEN
        Err(requireTypeAttribute, elem);
        RETURN NIL;
      ELSE
        stringBuffer := "";
        node := elem.content;
        WHILE (node # NIL) DO
          WITH node: Parser.CharData DO
            LongStrings.Short(node.string^, "?", str);
            stringBuffer := stringBuffer.Concat(Object.NewLatin1(str));
          ELSE
            Err(requireCharacterData, node);
          END;
          node := node.nextNode;
        END;

        chars := type(Object.String8).CharsLatin1();
        value := options.typeList.GetClone(chars^);
        IF (value = NIL) THEN
          Err(unknownType, elem);
          lastError.SetStringAttrib("type", Msg.GetStringPtr(chars^))
        ELSE
          chars := stringBuffer(Object.String8).CharsLatin1();
          value.StringToValue(chars^, errMsg);
          IF (errMsg # NIL) THEN
            Err(invalidValue, elem);
            lastError.SetMsgAttrib("reason", errMsg)
          END
        END;
        
        RETURN NewKeyValue(name, value);
      END;
    END ParseDefine;
  
  BEGIN
    IF (elem.attrList.len # 0) THEN
      Err(invalidAttribute, elem);
      lastError.SetLStringAttrib("name", Msg.GetLStringPtr(elem.attrList.attr[0].localName^));
    END;
    
    node := elem.content;
    SkipWS(node);
    WHILE (node # NIL) DO
      IF AtElement(node, "define") THEN
        list.Append(ParseDefine(node(Parser.Element)));
        node := node.nextNode;
      ELSE
        Err(requireDefine, node);
        node := node.nextNode;
      END;
      SkipWS(node);
    END;
  END ParseKeyValue;

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

  PROCEDURE SkipWS(VAR node: Parser.Node);
    BEGIN
      WHILE (node # NIL) & (node IS Parser.CharData) DO
        IF ~node.IsWhitespace() THEN
          Err(invalidCharData, node);
        END;
        node := node.nextNode;
      END;
    END SkipWS;

  PROCEDURE ParseVersion(elem: Parser.Element): Version;
  (* pre: element.name="version" *)
    VAR
      i: LONGINT;
      version: Version;
      str: ARRAY 32 OF CHAR;
      att: Builder.Attribute;
      
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
      att: Builder.Attribute;
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
      att: Builder.Attribute;
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
        Err(requireVersionChild, elem);
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
      att: Builder.Attribute;
      
    PROCEDURE ParseFile(elem: Parser.Element): File;
    (* pre: element.name="file" *)
      VAR
        i: LONGINT;
        node: Parser.Node;
        name, destName: STRING;
        att: Builder.Attribute;
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
      Err(requireVersionChild, root);
    END;
    
    WHILE AtElement(node, "requires") DO
      node := node.nextNode;
      SkipWS(node);
    END;
    
    IF AtElement(node, "options") THEN
      ParseKeyValue(node(Parser.Element), pkg.options, Config.options,
                    stringType, errorListener, errList);
      node := node.nextNode;
      SkipWS(node);
    END;
    
    IF AtElement(node, "pragmas") THEN
      ParseKeyValue(node(Parser.Element), pkg.pragmas, Config.pragmas,
                    stringType, errorListener, errList);
      node := node.nextNode;
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
    pkg.fileSet.sourceDir := ".";
    pkg.fileSet.destDir := ".";
    WHILE AtElement(node, "file-set") DO
      pkg.fileSet.Append(ParseFileSet(node(Parser.Element)));
      node := node.nextNode;
      SkipWS(node);
    END;
    IF (node # NIL) THEN
      Err(junkAtEndOfElement, node);
    END;
    IF (errList.msgCount # 0) THEN
      pkg := NIL;
    END;
    RETURN pkg;
  END ProcessPackage;

PROCEDURE ProcessRepository (root: Parser.Element;
                             errorListener: Locator.ErrorListener;
                             errList: Error.List): Repository;
  VAR
    lastError: Msg.Msg;
    node: Parser.Node;
    rep: Repository;
    
  PROCEDURE Err(code: Msg.Code; xmlNode: Parser.Node);
    BEGIN
      lastError := errorListener.Error(packageContext, code, FALSE,
                                       xmlNode. pos);
      errList.Append(lastError);
    END Err;

  PROCEDURE SkipWS(VAR node: Parser.Node);
    BEGIN
      WHILE (node # NIL) & (node IS Parser.CharData) DO
        IF ~node.IsWhitespace() THEN
          Err(invalidCharData, node);
        END;
        node := node.nextNode;
      END;
    END SkipWS;

  BEGIN
    IF (root.name^ # rootRepository) THEN
      Err (invalidRootName, root);
      lastError.SetLStringAttrib("name", Msg.GetLStringPtr(rootRepository));
    END;

    rep := NewRepository();
    node := root.content;
    SkipWS(node);
    WHILE AtElement(node, "installed") DO
      node := node.nextNode;
      SkipWS(node);
    END;
    
    IF AtElement(node, "options") THEN
      ParseKeyValue(node(Parser.Element), rep.options, Config.options,
                    stringType, errorListener, errList);
      node := node.nextNode;
      SkipWS(node);
    END;
    
    IF AtElement(node, "pragmas") THEN
      ParseKeyValue(node(Parser.Element), rep.pragmas, Config.pragmas,
                    stringType, errorListener, errList);
      node := node.nextNode;
      SkipWS(node);
    END;
    
    IF (node # NIL) THEN
      Err(junkAtEndOfElement, node);
    END;
    IF (errList.msgCount # 0) THEN
      rep := NIL;
    END;
    RETURN rep;
  END ProcessRepository;

PROCEDURE ParseFile(fileName: ARRAY OF CHAR; requirePackage: BOOLEAN;
                    VAR errList: Error.List): Rep.PkgInfo
RAISES IO.Error;
  VAR
    p: Parser.Parser;
  BEGIN
    Logger.ReadFileName(fileName);
    TRY
      p := Parser.NewFile (fileName);
      p.ParseDocument();
      IF (p.errList.msgCount = 0) THEN
        IF ~requirePackage & (p.root.name^ = rootRepository) THEN
          RETURN ProcessRepository(p.root, p.errorListener, errList);
        ELSE
          RETURN ProcessPackage(p.root, p.errorListener, errList);
        END;
      ELSE
        errList.AppendList(p.errList);
        RETURN NIL;
      END;
    CATCH IO.FileNotFound:
      RETURN NIL;
    END;
  END ParseFile;

PROCEDURE GetPackage* (pkgName: ARRAY OF CHAR;
                       VAR rep: Rep.Repository): Package;
  BEGIN
    (* module not found in cache: traverse repositories *)
    rep := Config.repositories.topLevelRep;
    WHILE (rep # NIL) DO
      IF (rep.packageInfo # NIL) &
         (rep.packageInfo IS Package) &
         rep.packageInfo(Package).name.Equals(Object.NewLatin1(pkgName)) THEN
        RETURN rep.packageInfo(Package);
      END;
      rep := rep.baseRep;
    END;
    RETURN NIL;
  END GetPackage;

PROCEDURE ParseMetaData*(options, pragmas: Options.Section): BOOLEAN
RAISES IO.Error;
  VAR
    errList: Error.List;
    dummy: BOOLEAN;
    
  PROCEDURE Parse(rep: Rep.Repository): BOOLEAN
  RAISES IO.Error;
    VAR
      uri: URI.URI;
      pkg: Rep.PkgInfo;
      fileName: Rep.URIBuffer;
    BEGIN
      IF (rep # NIL) THEN
        IF Parse(rep.baseRep) THEN
          uri := rep.GetResource("", packageData);
          IF (uri # NIL) THEN
            uri(FileURI.URI).GetPath(fileName);
            pkg := ParseFile(fileName, FALSE, errList);
            rep.SetPackageInfo(pkg);
            IF (pkg # NIL) THEN
              MergeConfig(pkg, options, pragmas);
            END;
            IF (errList.msgCount # 0) THEN
              RETURN FALSE;
            END;
          END;
        END;
      END;
      RETURN TRUE;
    END Parse;
  
  BEGIN
    errList := Error.NewList("");
    dummy := Parse(Config.repositories.topLevelRep);
    errList.Write(StdChannels.stdout);
    RETURN errList.NoErrors();
  END ParseMetaData;

PROCEDURE WriteKeyValue(w: Writer.Writer;
                        tag: ARRAY OF CHAR; list: ArrayList.ArrayList);
  VAR
    i: LONGINT;
    kv: KeyValue;
    v: Value.Value;
    str: ARRAY 1024 OF CHAR;
    type: ARRAY 32 OF CHAR;
  BEGIN
    w.StartTagLatin1(tag, FALSE);
    FOR i := 0 TO list.size-1 DO
      kv := list.array[i](KeyValue);
      w.StartTag("define", TRUE);
      w.AttrObject("name", kv.key);
      v := kv.value;
      WITH v: StringValue.Value DO
        type := "string";
      | v: BooleanValue.Value DO
        type := "boolean";
      | v: IntegerValue.Value DO
        type := "integer";
      END;
      w.AttrStringLatin1("type", type);
      kv.value.ValueToString(str);
      w.WriteLatin1(str);
      w.EndTag();  (* set *)
    END;
    w.EndTag();
  END WriteKeyValue;

PROCEDURE WritePackage*(pkg: Package; targetDir: ARRAY OF CHAR)
RAISES IO.Error;
  VAR
    b: StringBuffer.StringBuffer;
    fileName: STRING;
    f: IO.ByteChannel;
    w: Writer.Writer;
    i: LONGINT;
    str: StringBuffer.CharsLatin1;
    
  PROCEDURE WriteVersion(w: Writer.Writer; version: Version);
    BEGIN
      w.StartTag("version", FALSE);
      w.AttrInt("current", version.current);
      IF (version.age > 0) THEN
        w.AttrInt("age", version.age)
      END;
      w.AttrInt("revision", version.revision);
      w.EndTag();  (* version *)
    END WriteVersion;

  PROCEDURE WriteLibrary(w: Writer.Writer; library: Library);
    BEGIN
      w.StartTag("library", FALSE);
      w.AttrObject("name", library.name);
      w.AttrObject("main-module", library.mainModule);
      WriteVersion(w, library.version);
      w.EndTag();  (* library *)
    END WriteLibrary;

  PROCEDURE WriteExecutable(w: Writer.Writer; executable: Executable);
    BEGIN
      w.StartTag("executable", FALSE);
      w.AttrObject("main-module", executable.mainModule);
      w.EndTag();  (* executable *)
    END WriteExecutable;

  PROCEDURE WriteFileSet(w: Writer.Writer; fileSet: FileSet);
    VAR
      ptr: FileData;

    PROCEDURE WriteFile(w: Writer.Writer; file: File);
      BEGIN
        w.StartTag("file", FALSE);
        w.AttrObject("name", file.name);
        IF (file.destName # NIL) THEN
          w.AttrObject("dest-name", file.destName);
        END;
        w.EndTag();  (* file *)
      END WriteFile;
    
    BEGIN
      w.StartTag("file-set", FALSE);
      w.AttrObject("source-dir", fileSet.sourceDir);
      IF (fileSet.destDir # NIL) THEN
        w.AttrObject("dest-dir", fileSet.destDir);
      END;
      ptr := fileSet.head;
      WHILE (ptr # NIL) DO
        WITH ptr: FileSet DO
          WriteFileSet(w, ptr);
        | ptr: File DO
          WriteFile(w, ptr);
        END;
        ptr := ptr.nextFileData;
      END;
      w.EndTag();  (* file-set *)
    END WriteFileSet;

  BEGIN
    b := StringBuffer.NewLatin1(targetDir);
    b.AppendLatin1(pkgInfoSubdir);
    b.Append("/");
    b.Append(pkg.name);
    b.Append(".xml");
    fileName := b.ToString();
    
    f := FileChannel.Open(fileName(Object.String8),
                          {FileChannel.write, FileChannel.create,
                           FileChannel.truncate});
    w := Writer.New(f, Latin1.factory, TRUE, 2);
    
    w.StartTag("package", FALSE);
    w.AttrObject("name", pkg.name);
    WriteVersion(w, pkg.version);
    WriteKeyValue(w, "options", pkg.options);
    WriteKeyValue(w, "pragmas", pkg.pragmas);
    FOR i := 0 TO pkg.library.size-1 DO
      WriteLibrary(w, pkg.library.array[i](Library));
    END;
    FOR i := 0 TO pkg.executable.size-1 DO
      WriteExecutable(w, pkg.executable.array[i](Executable));
    END;
    WriteFileSet(w, pkg.fileSet);
    w.EndTag();  (* package *)
    w.EndOfText();
    
    f.Close();
    b.Insert("chmod 644 ", 0);
    str := b.CharsLatin1();
    Logger.ShellCommand(str^);
    i := ProcessManagement.system(str^);
  END WritePackage;

PROCEDURE WriteRepository*(rep: Repository; targetDir: ARRAY OF CHAR)
RAISES IO.Error;
  VAR
    str, fileName: URIBuffer;
    f: IO.ByteChannel;
    w: Writer.Writer;
    i: LONGINT;

  PROCEDURE WriteInstalledPkg(w: Writer.Writer; pkgName: STRING);
    BEGIN
      w.StartTag("installed", FALSE);
      w.AttrObject("package", pkgName);
      w.EndTag();  (* pkgName *)
    END WriteInstalledPkg;

  BEGIN
    COPY(targetDir, fileName);
    Strings.Append(pkgInfoFile, fileName);

    Logger.WriteFileName(fileName);
    f := FileChannel.Open(Object.NewLatin1(fileName),
                          {FileChannel.write, FileChannel.create,
                           FileChannel.truncate});
    w := Writer.New(f, Latin1.factory, TRUE, 2);
    
    w.StartTag("repository", FALSE);
    FOR i := 0 TO rep.installedPkgs.size-1 DO
      WriteInstalledPkg(w, rep.installedPkgs.array[i](STRING));
    END;
    WriteKeyValue(w, "options", rep.options);
    WriteKeyValue(w, "pragmas", rep.pragmas);
    w.EndTag();  (* repository *)
    w.EndOfText();
    f.Close();
    
    COPY(fileName, str);
    Strings.Insert("chmod 644 ", 0, str);
    Logger.ShellCommand(str);
    i := ProcessManagement.system(str);
  END WriteRepository;

PROCEDURE RemovePkgInfoCmd*(pkg: Package; targetDir, uninstall: ARRAY OF CHAR;
                            VAR cmd: ARRAY OF CHAR);
  VAR
    b: StringBuffer.StringBuffer;
    chars: StringBuffer.CharsLatin1;
  BEGIN
    b := StringBuffer.NewLatin1(uninstall);
    b.Append(" ");
    b.AppendLatin1(targetDir);
    b.Append(pkgInfoSubdir);
    b.Append("/");
    b.Append(pkg.name);
    b.Append(".xml");
    chars := b.CharsLatin1();
    COPY(chars^, cmd);
  END RemovePkgInfoCmd;

PROCEDURE GetPkgInfo*(targetDir, pkgName: ARRAY OF CHAR;
                      VAR errList: Error.List): Package
RAISES IO.Error;
  VAR
    fileName: URIBuffer;
    pkgInfo: Rep.PkgInfo;
  BEGIN
    COPY(targetDir, fileName);
    Strings.Append(pkgInfoSubdir, fileName);
    Strings.Append("/", fileName);
    Strings.Append(pkgName, fileName);
    Strings.Append(".xml", fileName);
    
    errList := Error.NewList(fileName);
    pkgInfo := ParseFile(fileName, TRUE, errList);
    IF (pkgInfo # NIL) THEN
      RETURN pkgInfo(Package);
    ELSE
      RETURN NIL;
    END;
  END GetPkgInfo;

PROCEDURE UpdateRepository*(targetDir: ARRAY OF CHAR): BOOLEAN
RAISES IO.Error;
  VAR
    dirName, fileName: URIBuffer;
    files: OSFiles.NameArray;
    res: Msg.Msg;
    i: LONGINT;
    errList: Error.List;
    pkg: Rep.PkgInfo;
    repository: Repository;
    
  PROCEDURE IsPkgInfo(name: ARRAY OF CHAR): BOOLEAN;
    VAR
      found: BOOLEAN;
      pos: INTEGER;
    BEGIN
      Strings.FindPrev(".xml", name, MAX(INTEGER), found, pos);
      RETURN found & (pos = Strings.Length(name)-4);
    END IsPkgInfo;
  
  BEGIN
    COPY(targetDir, dirName);
    Strings.Append(pkgInfoSubdir, dirName);

    files := OSFiles.listdir(dirName, res);
    IF (res = NIL) THEN
      repository := NewRepository();
      FOR i := 0 TO LEN(files^)-1 DO
        IF IsPkgInfo(files[i]^) THEN
          COPY(dirName, fileName);
          Strings.Append("/", fileName);
          Strings.Append(files[i]^, fileName);
          
          errList := Error.NewList(fileName);
          pkg := ParseFile(fileName, TRUE, errList);
          IF (errList.msgCount # 0) THEN
            errList.Write(StdChannels.stdout);
            RETURN FALSE;
          ELSE
            repository.MergePackage(pkg(Package));
          END;
        END;
      END;
      
      WriteRepository(repository, targetDir);
      IF (res # NIL) THEN
        Out.String("Error: Write error for ");
        Out.String(fileName);
        Out.Ln;
        RETURN FALSE;
      END;
      RETURN TRUE;
    ELSE
      Out.String("Error: No such directory ");
      Out.String(dirName);
      Out.Ln;
      RETURN FALSE;
    END;
  END UpdateRepository;

BEGIN
  stringType := "string";
  NEW (packageContext);
  Msg.InitContext (packageContext, "OOC:Package");
END OOC:Package.
