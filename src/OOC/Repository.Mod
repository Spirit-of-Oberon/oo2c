MODULE OOC:Repository [OOC_EXTENSIONS];

IMPORT
  Msg, Channel, TextRider, Strings, Time, ADT:Object, URI,
  OOC:Scanner:InputBuffer, OOC:SymbolTable:Item, OOC:SymbolTable:Builder;


TYPE
  URIBuffer* = ARRAY 1024 OF CHAR;

TYPE
  Repository* = POINTER TO RepositoryDesc;
  RepositoryDesc* = RECORD [ABSTRACT]
    baseRep-: Repository;
    baseURI-: URI.HierarchicalURI;
  END;

TYPE
  Module* = POINTER TO ModuleDesc;
  Import* = POINTER TO ImportDesc;
  ImportDesc = RECORD
    nextImport-: Import;
    imported-: Module;
  END;

TYPE
  ModuleName* = Msg.String;
  ModuleNamePtr* = Msg.StringPtr;
  ModuleDesc* = RECORD [ABSTRACT]
    (Object.ObjectDesc)
    (**Note: The function @oproc{*OOC:Config:Repositories.Section.GetModule} is
       used to retrieve module instances from repositories.  It ensures that
       for a given module name only one instance of @otype{Module} is created
       during execution of a compilation run.  *)
    origin-: Repository;
    (**Identifies the repository from which this module was taken.  *)
    name-: ModuleNamePtr;
    importListScanned-: BOOLEAN;
    (**If @code{TRUE}, then the module's import list has been scanned and can
       be accessed through the field @ofield{Module.importList}.  Imported
       modules are added to the list through @oproc{Module.AddImport}.  *)
    importList-: Import;
    symbolTable-: Item.Module;
    (**After the module's symbol file has been read, this field refers to
       its symbol table.  *)
  END;

TYPE
  FileId* = SHORTINT;
  (**This type identifies the various output files that can be derived from an
     Oberon-2 module's source code.  The symbolic names
     (@oconst{modModuleSource}, @samp{modSymbolFile}, etc.) are used to
     identify the different output formats.  Every repository can map the ids
     to its own directory structure, and choose its own file name suffix for
     them.  *)
  
CONST
  modModuleSource* = 0;
  (**Refers to a module's source file.

     Source files are located by using the function
     @oproc{*OOC:Config:Repositories.Section.GetModule} and then calling
     @oproc{*OOC:Repository.Module.GetURI} (or one of its friends) on the
     result.  *)
  modSymbolFile* = 1;
  (**A module's symbol file holds all information that is made available to
     importing modules.  *)
  modSymbolTableXML* = 2;
  (**This is an XML representation of the internal symbol table built of the
     datatypes defined in @omodule{*OOC:SymbolTable:Item}.  It is used for
     debugging.  *)
  modInterfaceXML* = 3;
  (**An XML representation of the public interface of a module.  Files of this
     type contain everything that is part of the symbol file, plus additional
     information like documentation text and, possibly, module locations.  *)
     (*... fixme: InterfaceXML should be equivalent to SymbolFile content *)
  modInterfaceDescr* = 4;
  (**A description of a module's public interface, including descriptions for
     declarations and information about used base types and inherited
     entities.  *)
  modInterfaceHTML* = 5;
  (**A module's HTML documentation is based on the output of
     @oconst{modInterfaceXML}.  It converts all information present in the XML
     document to HTML, and adds additional data from imported modules.
     Examples for this are lists of base types of records, and documentation
     text inherited from base types.  *)
  modOpTreeXML* = 6;
  (**This file holds an XML representation of the operator trees of the
     module's statements and expressions.  This is for debugging purposes.  *)
  modObjectFile* = 7;
  (**This is a standard object file, usually with the suffix @file{.o}, derived
     from the module's source code.  *)
  modObjectFileSharedLib* = 8;
  (**An object file suitable for inclusion into a shared library.  Library
     support may be implemented through external tools like @code{libtool}.  *)
  modObjectFileStaticLib* = 9;
  (**An object file suitable for inclusion into a static library.  Library
     support may be implemented through external tools like @code{libtool}.  *)
  modObjectFileDynamicLoad* = 10;
  (**An object file that can be dynamically loaded into a program.  Generating
     such files may be delegated to external tools like @code{libtool}.  *)
  modCodeFileC* = 11;
  (**For the C translator, this designates the C code file generated for a
     module.  *)
  modHeaderFileC* = 12;
  (**For the C translator, this designates the C header file that is used by
     the C code of the module, and is included into all client's C code.  *)
  resourceFile* = 13;
  (**A resource file is a non-Oberon file that accompanies a package.
     Resources are typically located in the @file{rsrc} subdirectory of a
     package or repository.  For example, XML DTD files and XSL stylesheets
     that are part of the OOC distribution are stored as resource files.

     Similar to search facility for module source files, resource files are
     located using the function
     @oproc{*OOC:Config:Repositories.Section.GetResource}.  *)
  maxFileId* = resourceFile;


PROCEDURE Init* (rep: Repository; baseRep: Repository; baseURI: URI.HierarchicalURI);
  VAR
    str: URIBuffer;
  BEGIN
    baseURI. GetString (str);
    ASSERT ((str # "") & (str[Strings.Length (str)-1] = "/"));
    rep. baseRep := baseRep;
    rep. baseURI := baseURI;
  END Init;

PROCEDURE InitModule* (m: Module; origin: Repository; name: ModuleName);
  BEGIN
    Object.Init (m);
    m. origin := origin;
    m. name := Msg.GetStringPtr (name);
    m. importListScanned := FALSE;
    m. importList := NIL;
    m. symbolTable := NIL;
  END InitModule;



PROCEDURE (rep: Repository) [ABSTRACT] GetModule* (moduleName: ARRAY OF CHAR): Module;
(**Tries to locate a module with the name @oparam{moduleName} in the repository
   @oparam{rep}.  On success, the function returns the module object, and
   result is @code{NIL} if the repository does not include this module.

   This function should only be called from
   @oproc{*OOC:Config:Repositories.Section.GetModule}.  It does not do any
   caching on the results of the query.  *)
  END GetModule;

PROCEDURE (rep: Repository) [ABSTRACT] GetResource* (package, path: ARRAY OF CHAR): URI.URI;
(**Tries to locate the resource file @oparam{path} under the package directory
   @oparam{package} in the repository.  On success, an URI for the file is
   returned.  Otherwise, result is @code{NIL}.

   This function should never be called by directly, except from
   @oproc{*OOC:Config:Repositories.Section.GetResource}.  *)
  END GetResource;
  
PROCEDURE (rep: Repository) [ABSTRACT] DumpContent* (w: TextRider.Writer);
  END DumpContent;


PROCEDURE (m: Module) AddImport* (imported: Module);
(**Adds a new module @oparam{imported} to the import list of @oparam{m}.
   If @oparam{imported} is @code{NIL}, then import list is completed and
   the flag @ofield{m.importListScanned} is set to @code{TRUE}.
   
   @precond
   @ofield{m.importListScanned} is not @code{TRUE}.
   @end precond *)
  PROCEDURE Append (VAR list: Import);
    BEGIN
      IF (list = NIL) THEN
        NEW (list);
        list. nextImport := NIL;
        list. imported := imported
      ELSE
        Append (list. nextImport)
      END
    END Append;
  
  BEGIN
    ASSERT (~m. importListScanned);
    IF (imported = NIL) THEN
      m. importListScanned := TRUE
    ELSE
      Append (m. importList)
    END
  END AddImport;

PROCEDURE (m: Module) [ABSTRACT] GetInputBuffer* (VAR msg: Msg.Msg): InputBuffer.Buffer;
(* result is NIL in case of error, with msg holding the error message *)
  END GetInputBuffer;

PROCEDURE (m: Module) [ABSTRACT] GetURI* (fileId: FileId; VAR res: Msg.Msg): URI.HierarchicalURI;
  END GetURI;

PROCEDURE (m: Module) [ABSTRACT] GetTimeStamp* (fileId: FileId; VAR ts: Time.TimeStamp);
  END GetTimeStamp;

PROCEDURE (m: Module) [ABSTRACT] GetOutputChannel* (fileId: FileId; makeTmp: BOOLEAN; VAR res: Msg.Msg): Channel.Channel;
  END GetOutputChannel;

PROCEDURE (rep: Repository) GetDefaultSubdir* (id: FileId; VAR subdir: ARRAY OF CHAR);
  BEGIN
    CASE id OF
    | modModuleSource:
      COPY ("src", subdir)
    | modSymbolFile:
      COPY ("sym", subdir)
    | modSymbolTableXML, modInterfaceXML, modInterfaceDescr, modOpTreeXML:
      COPY ("doc/xml", subdir)
    | modInterfaceHTML:
      COPY ("doc/html", subdir)
    | modObjectFile, modCodeFileC, modHeaderFileC, modObjectFileDynamicLoad:
      COPY ("obj", subdir)
    | modObjectFileSharedLib, modObjectFileStaticLib:
      COPY ("lib/obj", subdir)
    | resourceFile:
      COPY ("rsrc", subdir)
    END
  END GetDefaultSubdir;

PROCEDURE (rep: Repository) GetDefaultSuffix* (id: FileId; VAR suffix: ARRAY OF CHAR);
  BEGIN
    CASE id OF
    | modModuleSource:
      COPY (".Mod", suffix)
    | modSymbolFile:
      COPY (".Sym", suffix)
    | modSymbolTableXML:
      COPY ("_symtab.xml", suffix)
    | modInterfaceXML:
      COPY ("_sym.xml", suffix)
    | modInterfaceDescr:
      COPY (".xml", suffix)
    | modInterfaceHTML:
      COPY (".html", suffix)
    | modOpTreeXML:
      COPY ("_op.xml", suffix)
    | modObjectFile, modObjectFileDynamicLoad, modObjectFileStaticLib:
      COPY (".o", suffix)
    | modCodeFileC:
      COPY (".c", suffix)
    | modHeaderFileC:
      COPY (".h", suffix)
    | modObjectFileSharedLib:
      COPY (".lo", suffix)
    | resourceFile:
      ASSERT (FALSE)
    END
  END GetDefaultSuffix;

PROCEDURE (m: Module) GetSymbolTable* (VAR res: Msg.Msg): Item.Module;
(**Locates and reads the symbol table of module @oparam{m}.  In general, any
   type references in the returned symbol table are @emph{not} resolved.  Use
   @oproc{*OOC:Auxiliary:GetSymbolTable.GetSymbolTable} to get such a symbol
   table.  *)
  VAR
    stb: Builder.Builder;
    ch: Channel.Channel;
    uri: URI.URI;
    symTab: Item.Module;
  BEGIN
    IF (m. symbolTable # NIL) THEN
      res := NIL;
      RETURN m. symbolTable              (* return cached entry *)
    ELSE
      uri := m. GetURI (modSymbolFile, res);
      IF (res = NIL) THEN
        ch := uri. GetChannel (URI.channelOld, res);
        IF (res = NIL) THEN
          stb := Builder.New();
          symTab := stb. ReadSymbolTable (ch, res);
          ch. Close;
          IF (res = NIL) THEN
            m. symbolTable := symTab;    (* cache for later use *)
            RETURN symTab
          END
        END
      END;
      RETURN NIL
    END
  END GetSymbolTable;


PROCEDURE ValidModuleName* (moduleName: ARRAY OF CHAR): BOOLEAN;
(* Returns TRUE iff moduleName is matches `ident {":" ident}'.  *)
  VAR
    i: LONGINT;
  BEGIN
    i := 0;
    WHILE (moduleName[i] # 0X) DO
      IF (("A" <= CAP (moduleName[i])) & (CAP (moduleName[i]) <= "Z")) THEN
        REPEAT
          INC (i)
        UNTIL ~(("A" <= CAP (moduleName[i])) & (CAP (moduleName[i]) <= "Z") OR
                ("0" <= moduleName[i]) & (moduleName[i] <= "9"));
        IF (moduleName[i] = ":") THEN
          INC (i);
          IF (moduleName[i] = 0X) THEN   (* ":" at end of name *)
            RETURN FALSE
          END
        ELSIF (moduleName[i] # 0X) THEN  (* invalid character *)
          RETURN FALSE
        END
      ELSE  (* identifier doesn't start with letter *)
        RETURN FALSE
      END
    END;
    RETURN TRUE
  END ValidModuleName;

END OOC:Repository.
