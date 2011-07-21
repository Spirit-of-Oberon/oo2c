(* 	$Id: Repository.Mod,v 1.44 2003/11/13 23:02:08 mva Exp $	 *)
MODULE OOC:Repository [OOC_EXTENSIONS];
(*  Abstraction of storage of source, intermediate, and target code.
    Copyright (C) 2001, 2002, 2003  Michael van Acken

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
  Msg, TextRider, Strings, Time,
  Object, ADT:ArrayList,
  URI, IO, OS:Path, OOC:Logger,
  OOC:Scanner:InputBuffer, Sym := OOC:SymbolTable, OOC:SymbolTable:Builder;

CONST
  headerSuffix* = ".oh";

TYPE
  URIBuffer* = ARRAY 1024 OF CHAR;

TYPE
  PkgInfo* = POINTER TO PkgInfoDesc;
  PkgInfoDesc* = RECORD
    options-, pragmas-: ArrayList.ArrayList;  (* of Package.KeyValue *)
  END;
  
TYPE
  Repository* = POINTER TO RepositoryDesc;
  RepositoryDesc* = RECORD [ABSTRACT]
    baseRep-: Repository;
    baseURI-: URI.HierarchicalURI;
    packageInfo-: PkgInfo;
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
  ModuleRef* = RECORD
    name-: Sym.Name;
    module*: Module;
    internal-: BOOLEAN;
    fingerprint-: LONGINT;
  END;
  ModuleDesc* = RECORD [ABSTRACT]
    (Object.ObjectDesc)
    (**Note: The function @oproc{*OOC:Config:Repositories.Section.GetModule} is
       used to retrieve module instances from repositories.  It ensures that
       for a given module name only one instance of @otype{Module} is created
       during execution of a compilation run.  *)
    origin-: Repository;
    (**Identifies the repository from which this module was taken.  *)
    name-: ModuleNamePtr;
    
    srcFileOverride-: URI.HierarchicalURI;
    (**If not @code{NIL}, then the source code is read from this file, instead
       from the normal file path constructed from the repository base and the
       module name.  This kind of file access is deprecated, because it can
       produce an inconsistent state in a repository.  It is included primarily
       to support test setups where the source code is not organized in
       repositories.  *)
    
    ifData-: Sym.Module;
    (**Interface data of this module.  This includes both its imports and
       its exports.  Depending on @ofield{ifQuality}, only part of the
       data may be available at the moment.  *)
    ifQuality-: SHORTINT;
    (**Quality of data in the field @ofield{ifData}.  One of
       @oconst{noInterfaceData}, @oconst{importsOnly},
       @oconst{importsWithFingerprint}, or @oconst{completeInterface}.  *)
    ifImportList-: POINTER TO ARRAY OF ModuleRef;
    (**Mirrors the imports from @ofield{ifData}.  *)
    visitedByMake*: SET;
    (**Used by @omodule{*OOC:Make} to detect cyclic dependencies when
       updating or building files.  *)
    
    haveFingerprint: BOOLEAN;
    fingerprint: LONGINT;
  END;

CONST
  noInterfaceData* = 1;
  (**No interface data is known.  @ofield{Module.ifData} is @code{NIL}.  *)
  importsOnly* = 2;
  (**Only the module names in the import list and the data from the module
     header in @ofield{Module.ifData} can be trusted.  Additional information
     is either missing, or may not be up to date.  *)
  importsWithFingerprint* = 3;
  (**Like @oconst{importsOnly}, with the addition of fingerprint values for
     all modules in the import list.  *)
  completeInterface* = 4;
  (**The data in @ofield{Module.ifData} is complete and up to date.  The
     symbol table, and all symbol tables that are referenced by it, can be used
     when compiling a module.  *)
  
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
     @oproc{Module.GetURI} (or one of its friends) on the result.

     Note: In the make facility, the only entity that is allowed to register a
     dependency on this file is @oconst{modSymbolFile}.  *)
  modSymbolFile* = 1;
  (**A module's symbol file holds all information that is made available to
     importing modules.  When compiling the module, this file is always the one
     with the oldest time stamp of all generated files.  This way, within a
     make graph any other output file of the compiler can register a dependency
     on this file, instead of @oconst{modModuleSource}.

     The documentation strings of a module are stored separately in a file
     @oconst{modSymbolFileDoc}.  *)
  modSymbolTableXML* = 2;
  (**This is an XML representation of the internal symbol table built of the
     datatypes defined in @omodule{*OOC:SymbolTable}.  It is used for
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
  modObjectFileLib* = 8;
  (**An object file suitable for inclusion into a shared library.  When using
     libtool, then this is the @file{.lo} file that acts as a standin for both
     the file for the static and for the shared library.  *)
  (* ... unused: 9 *)
  modObjectFileDynamicLoad* = 10;
  (**An object file that can be dynamically loaded into a program.  Generating
     such files may be delegated to external tools like @code{libtool}.  *)
  modCodeFileC* = 11;
  (**For the C translator, this designates the C code file generated for a
     module.  This file contains an include for the file @oconst{modDeclFileC}
     and the function definitions.  *)
  modDeclFileC* = 12;
  (**For the C translator, this designates the C code file holding all global
     declarations of a module.  It includes the run-time data structure like
     module and file descriptors, global variable definitions, and all other
     global declarations that are not part of the header file
     @oconst{modHeaderFileC}.  *)
  modHeaderFileC* = 13;
  (**For the C translator, this designates the C header file that is used by
     the C code of the module, and is included into all client's C code.  *)
  modAssemblerFile* = 14;
  (**For the assembler file generated for a module.  This is equivalent to
     @oconst{modCodeFileC}.  *)
  modMainFileC* = 15;
  (**This file contains the main function of a program.  It is a variant of
     @oconst{modCodeFileC} in that it contains C code and is compiled to an
     object file.  *)
  modMainFileAssembler* = 16;
  (**This file contains the main function of a program as assembler code.  It
     is equivalent to @oconst{modMainFileC}, and is translated to
     @oconst{modMainObjectFile}.  *)
  modMainObjectFile* = 17;
  (**Compiled version of @oconst{modMainFileC} or
     @oconst{modMainFileAssembler}.  *)
  modExecutable* = 18;
  (**Represents the executable one gets when using this module as a program's
     main module.  *)
  modLibrary* = 19;
  (**An OS library created from a source file that the package descriptor
     indicates as the main module of a library.  Typically, the module
     is simply a list of @code{IMPORT}s pulling in all modules that should
     be part of the library.
                                 
     The library includes a static part, and, optionally, a shared part.
     Static libraries are included into the binary when building an executable,
     while shared libaries are resolved and linked when the executable is
     started.  From the point of view of the OOC make mechanism, a library is
     an atomic entity.  It does not care whether shared libraries are supported
     by the operating system, or how.  Building a library may result in just a
     static part, or in both static and shared parts.

     The file name of the library is derived indirectly from the module:
     instead of the module's name, the name of its library is used, prefixed
     by the string @samp{lib}.  This means, that @oproc{Module.GetURI}
     return the same URI for all modules of the library.
     
     [These statements should be general enough to be true.  Since this topic
     is highly dependent on the operating system, I'm not willing to bet much
     on this, though.  As it is, it is the current working hypothesis ;-)]  *)
  modSymbolFileDoc* = 20;
  (**Holds the documentation strings of a symbol file.  *)
  resourceFile* = 21;
  (**A resource file is a non-Oberon file that accompanies a package.
     Resources are typically located in the @file{rsrc} subdirectory of a
     package or repository.  For example, XML DTD files and XSL stylesheets
     that are part of the OOC distribution are stored as resource files.

     Similar to search facility for module source files, resource files are
     located using the function
     @oproc{*OOC:Config:Repositories.Section.GetResource}.  *)
  maxFileId* = resourceFile;


VAR
  readDocStrings*: BOOLEAN;
  (**If @code{TRUE}, the doc strings of a module are read with its symbol file.
     Otherwise, the doc strings are omitted and set to @code{NIL}.  The latter
     is the default.  *)

PROCEDURE Init* (rep: Repository; baseRep: Repository; baseURI: URI.HierarchicalURI);
  BEGIN
    rep. baseRep := baseRep;
    rep. baseURI := baseURI;
    rep. packageInfo := NIL;
  END Init;

PROCEDURE InitModule* (m: Module; origin: Repository; name: ModuleName;
                       srcFileOverride: URI.HierarchicalURI);
  BEGIN
    m. origin := origin;
    m. name := Msg.GetStringPtr (name);
    m. srcFileOverride := srcFileOverride;
    
    m. ifQuality := noInterfaceData;
    m. ifData := NIL;
    m. ifImportList := NIL;
    m. visitedByMake := {};
    
    m. haveFingerprint := FALSE;
    m. fingerprint := 0;
  END InitModule;


PROCEDURE InitPkgInfo*(pkgInfo: PkgInfo);
  BEGIN
    pkgInfo.options := ArrayList.New(4);
    pkgInfo.pragmas := ArrayList.New(4);
  END InitPkgInfo;

PROCEDURE (rep: Repository) SetPackageInfo* (packageInfo: PkgInfo);
  BEGIN
    rep.packageInfo := packageInfo;
  END SetPackageInfo;

PROCEDURE (rep: Repository) [ABSTRACT] GetModule* (moduleName: ARRAY OF CHAR; 
                                 srcFileOverride: URI.HierarchicalURI): Module;
(**Tries to locate a module with the name @oparam{moduleName} in the repository
   @oparam{rep}.  For this it checks if the module's source file or symbol file
   exists in the repository.  On success, the function returns the module
   object, and result is @code{NIL} if the repository does not include this
   module.

   If @oparam{srcFileOverride} is not @code{NIL}, then no check is performed if
   the module's sources actually exists.  Instead, the value of
   @oparam{srcFileOverride} is taken as the location of the source file.

   This function should only be called from
   @oproc{*OOC:Config:Repositories.Section.GetModule}.  It does not do any
   caching on the results of the query.  *)
  END GetModule;

PROCEDURE (rep: Repository) [ABSTRACT] GetResource* (package, path: ARRAY OF CHAR): URI.URI;
(**Tries to locate the resource file @oparam{path} under the package directory
   @oparam{package} in the repository.  On success, an URI for the file is
   returned.  Otherwise, result is @code{NIL}.

   An empty package name signals that a repository specific resource is
   requested.
   
   This function should never be called by directly, except from
   @oproc{*OOC:Config:Repositories.Section.GetResource}.  *)
  END GetResource;

PROCEDURE (rep: Repository) [ABSTRACT] DumpContent* (w: TextRider.Writer);
  END DumpContent;


PROCEDURE (m: Module) SetInterfaceData*(ifData: Sym.Module;
                                        ifQuality: SHORTINT;
                                        allImports: BOOLEAN);
  VAR
    count, i: LONGINT;
    item: Sym.Item;
    oldIfData: Sym.Module;
    mr: Sym.ModuleRef;
    name: Sym.Name;
  BEGIN
    oldIfData := m.ifData;
    m.ifData := ifData;
    m.ifQuality := ifQuality;

    IF (ifData = NIL) THEN
      m.ifImportList := NIL;
    ELSIF (oldIfData # ifData) THEN
      count := 0;
      item := ifData.nestedItems;
      WHILE (item # NIL) DO
        WITH item: Sym.Import DO
          INC(count);
        ELSE
        END;
        item := item.nextNested;
      END;
      IF allImports & (ifData.prunedImports # NIL) THEN
        INC(count, LEN(ifData.prunedImports^));
      END;
      
      NEW(m.ifImportList, count);
      count := 0;
      item := ifData.nestedItems;
      WHILE (item # NIL) DO
        WITH item: Sym.Import DO
          m.ifImportList[count].name := item.moduleName;
          m.ifImportList[count].module := NIL;
          m.ifImportList[count].internal := (item.moduleName.str^ = "SYSTEM");
          m.ifImportList[count].fingerprint := item.fingerprint;
          INC(count);
        ELSE
        END;
        item := item.nextNested;
      END;

      IF allImports & (ifData.prunedImports # NIL) THEN
        FOR i := 0 TO LEN(ifData.prunedImports^)-1 DO
          mr := ifData.prunedImports[i];
          NEW(name);
          Sym.InitName(name, mr.name, 0, 0, 0);
          m.ifImportList[count].name := name;
          m.ifImportList[count].module := NIL;
          m.ifImportList[count].internal := FALSE;
          m.ifImportList[count].fingerprint := mr.fingerprint;
          INC(count);
        END;
      END;
    END;
  END SetInterfaceData;

PROCEDURE (m: Module) SetFingerprint* (fp: LONGINT);
  BEGIN
    m.haveFingerprint := TRUE;
    m.fingerprint := fp;
  END SetFingerprint;

PROCEDURE (m: Module) GetImportedModule*(name: ARRAY OF CHAR): Module;
  VAR
    i: LONGINT;
  BEGIN
    i := 0;
    WHILE (i # LEN(m.ifImportList^)) &
          (m.ifImportList[i].name.str^ # name) DO
      INC(i);
    END;
    IF (i = LEN(m.ifImportList^)) THEN
      RETURN NIL;
    ELSE
      RETURN m.ifImportList[i].module;
    END;
  END GetImportedModule;

PROCEDURE (rep: Repository) [ABSTRACT] GetLocalPath*(m: Module; fileId: FileId): Object.String8;
(**Return the path to the indicated module file, relative to the
   repositories base URI.  *)
  END GetLocalPath;

PROCEDURE (m: Module) [ABSTRACT] GetInputBuffer* (): InputBuffer.Buffer
RAISES IO.Error;
(* result is NIL in case of error, with msg holding the error message *)
  END GetInputBuffer;

PROCEDURE (m: Module) GetURI* (fileId: FileId;
                               allowRelative: BOOLEAN): URI.HierarchicalURI;
(**Return an URI for the file @oparam{fileId} of the module @oparam{m}.
   If @oparam{allowRelative} is @code{TRUE}, then the answer may be an
   URI that is relative to the current working directory.  *)
  BEGIN
    (* check if the module provides its own .c file; in this case, return
       the given name, instead of the automatically generated one *)
    IF (fileId = modCodeFileC) & (m. ifData # NIL) &
       (m. ifData. class # Sym.mcStandard) THEN
      RETURN m. ifData. GetExternalSource (m. origin. baseURI);
    ELSE
      RETURN NIL;
    END;
  END GetURI;

PROCEDURE (m: Module) MatchesURI* (fileId: FileId; uri: URI.URI): BOOLEAN;
(**Returns @code{TRUE} if the given @oparam{uri} matches the URI of the
   module's file.  *)
  VAR
    a, b: STRING;
    muri: URI.HierarchicalURI;
  BEGIN
    muri := m. GetURI (fileId, FALSE);
    a := muri.ToString();
    b := uri.ToString();
    RETURN a.Equals(b);
  END MatchesURI;

PROCEDURE (m: Module) [ABSTRACT] GetTimeStamp* (fileId: FileId; VAR ts: Time.TimeStamp);
(**If the file does not exist, or the time stamp cannot be retrieved for
   some other reason, @ofield{ts.days} is @code{MAX(LONGINT)}.  *)
  END GetTimeStamp;

PROCEDURE (m: Module) [ABSTRACT] FileExists* (fileId: FileId): BOOLEAN;
  END FileExists;

PROCEDURE (m: Module) [ABSTRACT] CreateOutputDir* (fileId: FileId)
RAISES IO.Error;
  END CreateOutputDir;

PROCEDURE (m: Module) [ABSTRACT] GetOutputChannel* (fileId: FileId;
                                                    makeTmp: BOOLEAN): IO.ByteChannel
RAISES IO.Error;
  END GetOutputChannel;

PROCEDURE (rep: Repository) GetDefaultSubdir* (id: FileId): Object.String8;
  BEGIN
    CASE id OF
    | modModuleSource:
      RETURN "src";
    | modSymbolFile, modSymbolFileDoc:
      RETURN "sym";
    | modSymbolTableXML, modInterfaceXML, modInterfaceDescr, modOpTreeXML:
      RETURN "oocdoc/xml";
    | modInterfaceHTML:
      RETURN "oocdoc/html";
    | modObjectFile, modCodeFileC, modDeclFileC, modHeaderFileC,
      modAssemblerFile, modObjectFileDynamicLoad,
      modMainFileC, modMainFileAssembler, modMainObjectFile:
      RETURN "obj";
    | modObjectFileLib:
      RETURN "obj";
    | modExecutable:
      RETURN "bin";
    | modLibrary:
      RETURN "obj";
    | resourceFile:
      RETURN "rsrc";
    END
  END GetDefaultSubdir;

PROCEDURE (rep: Repository) GetDefaultSuffix* (id: FileId): Object.String8;
  BEGIN
    CASE id OF
    | modModuleSource:
      RETURN ".Mod";
    | modSymbolFile:
      RETURN ".Sym";
    | modSymbolFileDoc:
      RETURN ".Doc";
    | modSymbolTableXML:
      RETURN "_symtab.xml";
    | modInterfaceXML:
      RETURN "_sym.xml";
    | modInterfaceDescr:
      RETURN ".xml";
    | modInterfaceHTML:
      RETURN ".html";
    | modOpTreeXML:
      RETURN "_op.xml";
    | modObjectFile, modObjectFileDynamicLoad:
      RETURN ".o";
    | modObjectFileLib:
      RETURN ".lo";
    | modCodeFileC:
      RETURN ".c";
    | modDeclFileC:
      RETURN ".d";
    | modHeaderFileC:
      RETURN headerSuffix;
    | modAssemblerFile:
      RETURN ".s";
    | modMainFileC:
      RETURN "_.c";
    | modMainFileAssembler:
      RETURN "_.s";
    | modMainObjectFile:
      RETURN "_.o";
    | modExecutable:
      RETURN "";
    | modLibrary:
      RETURN ".la";
    | resourceFile:
      ASSERT (FALSE)
    END
  END GetDefaultSuffix;

PROCEDURE ValidModuleName* (moduleName: ARRAY OF CHAR): BOOLEAN;
(* Returns TRUE iff moduleName is matches `ident {":" ident}'.  *)
  VAR
    i: LONGINT;
  BEGIN
    i := 0;
    WHILE (moduleName[i] # 0X) DO
      IF (("A" <= CAP (moduleName[i])) & (CAP (moduleName[i]) <= "Z") OR
          (moduleName[i] = "_")) THEN
        REPEAT
          INC (i)
        UNTIL ~(("A" <= CAP (moduleName[i])) & (CAP (moduleName[i]) <= "Z") OR
                ("0" <= moduleName[i]) & (moduleName[i] <= "9") OR
                (moduleName[i] = "_"));
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
    RETURN (i > 0);
  END ValidModuleName;

PROCEDURE (rep: Repository) GetModuleByURI* (uri: URI.HierarchicalURI; force: BOOLEAN): Module;
  VAR
    relURI: URI.URI;
    str: URIBuffer;
    s, ext: STRING;
    subdir, s8: Object.String8;
    chars: Object.CharsLatin1;
    i: LONGINT;
    m: Module;
  BEGIN
    m := NIL;
    
    IF force THEN
      (* force: take basename of uri minus extension as module name *)
      s := Path.BaseName(uri.ToString());
      Path.SplitExt(s, s, ext);
      chars := s(Object.String8).CharsLatin1();
      IF ValidModuleName (chars^) THEN
        m := rep. GetModule (chars^, uri)
      END
    ELSE

      relURI := uri. MakeRelative (rep. baseURI);
      IF (relURI. schemeId = NIL) THEN  (* uri is relative to baseURI *)
        s := relURI.ToString();
        subdir := rep.GetDefaultSubdir (modModuleSource);

        (* the string representation of the relative URI must begin with the
           default subdirectory for sources, followed by a slash; note: this
           only works if `subdir' is not empty *)
        ASSERT (subdir.length # 0);
        i := subdir.length;
        IF s.StartsWith(subdir) & (s.CharAt(i) = "/") THEN
          (* approximate module name by stripping subdir prefix and replacing
             "/" with ":"; everything after the first "." is discarded *)
          s8 := s.ToString8("?");
          chars := s8.CharsLatin1();
          COPY(chars^, str);
          
          Strings.Delete (str, 0, SHORT(i)+1);
          i := 0;
          WHILE (str[i] # 0X) & (str[i] # ".") DO
            IF (str[i] = "/") THEN
              str[i] := ":"
            END;
            INC (i)
          END;
          str[i] := 0X;

          m := rep. GetModule (str, NIL);
          IF (m # NIL) & ~m. MatchesURI (modModuleSource, uri) THEN
            (* final check: the URI for the source of the module must match
               exactly the URI given as argument *)
            m :=  NIL
          END
        END
      END
    END;
    RETURN m
  END GetModuleByURI;

PROCEDURE (m: Module) ReadSymbolFile*(): Sym.Module
RAISES IO.Error;
(**Locates and reads the symbol table of module @oparam{m}.  The symbol file's
   fingerprint value is set in the returned object.  In general, any type
   references in the returned symbol table are @emph{not} resolved.  This must
   be done manually by calling
   @oproc{*OOC:SymbolTable:CreateNamespace.CreateNamespace}.

   If available and @oconst{completeInterface}, the cached symbol table
   @ofield{m.ifData} is returned.  If the symbol file is read from disk, it is
   @emph{not} stored in @ofield{m.ifData}, because only the calling function
   knows about the quality of the imported data.  *)
  VAR
    stb: Builder.Builder;
    ch, chDoc: IO.ByteChannel;
    uri: URI.URI;
    symTab: Sym.Module;
  BEGIN
    IF (m.ifQuality = completeInterface) THEN
      RETURN m.ifData;
    ELSE
      uri := m. GetURI (modSymbolFile, TRUE);
      ch := uri. GetChannel (URI.channelOld);
      Logger.ReadFile(uri);

      IF readDocStrings THEN
        uri := m. GetURI (modSymbolFileDoc, TRUE);
        chDoc := uri. GetChannel (URI.channelOld);
        Logger.ReadFile(uri);
      ELSE
        chDoc := NIL;
      END;
      
      stb := Builder.New();
      symTab := stb. ReadSymbolTable (ch, chDoc);
      IF (chDoc # NIL) THEN
        chDoc.Close;
      END;
      ch. Close;
      RETURN symTab;
    END;
  END ReadSymbolFile;

BEGIN
  readDocStrings := FALSE;
END OOC:Repository.
