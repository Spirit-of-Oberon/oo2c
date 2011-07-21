(* 	$Id: Make.Mod,v 1.71 2004/11/24 03:56:09 sgreenhill Exp $	 *)
MODULE OOC:Make;
(*  Builds object files, libraries, binaries, and the like.
    Copyright (C) 2002, 2003, 2004  Michael van Acken

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
  Msg, Out, Time, IO, IO:StdChannels, 

  Object, ADT:ArrayList, ADT:Dictionary, ADT:StringBuffer, StringSearch,
  StringSearch:NoMatch, OS:Path,
  OSFiles := OS:Files, OS:ProcessManagement, URI, URI:Scheme:File,

  OOC:Logger, OOC:Error, OOC:Config,
  OOC:Config:Pragmas, OOC:Config:Repositories,
  OOC:Doc:ResolveRef, OOC:Package, Rep := OOC:Repository, OOC:AST,
  Sym := OOC:SymbolTable, OOC:SymbolTable:CreateNamespace,
  OOC:SymbolTable:InterfaceDescr, OOC:SymbolTable:InterfaceXML,
  OOC:SymbolTable:Uses, OOC:Auxiliary:ParseModule, OOC:Make:LinkProgramC,
  
  OOC:Config:CCompiler, OOC:Make:TranslateToC, OOC:Make:WriteMainFileC,
  SSAtoC := OOC:SSA:WriteC, OOC:Config:Assembler, OOC:Make:TranslateToX86,
  OOC:Make:WriteMainFileAssembler;

TYPE
  ModuleInfo = POINTER TO ModuleInfoDesc;
  ModuleInfoDesc = RECORD
    (Object.ObjectDesc)
    updated: ARRAY Rep.maxFileId+1 OF BOOLEAN;
    updateResult: ARRAY Rep.maxFileId+1 OF BOOLEAN;
    compiled: BOOLEAN;
    compileResult: BOOLEAN;
  END;
  
TYPE
  ModuleList* = POINTER TO ARRAY OF Rep.Module;
  Rules* = POINTER TO RulesDesc;
  RulesDesc* = RECORD
    backend: LONGINT;
    library: Package.Library;
    (**If set, then all modules are compiled for this library.  *)
    checkAllImportsModule: Rep.Module;
    (* If not NIL, then for all modules but this one the set of imported
       modules is only checked if they contribute to the module's symbol
       file.  This can speed up a simple compile run on a module considerably,
       when only the correctness of the current module is to be checked.  *)
       
    localRepository: Rep.Repository;
    imports-: ModuleList;
    mInfo: Dictionary.Dictionary;
    
    extensionDict: Sym.ExtensionDict;
    (**Used by @oproc{Rules.UpdateInterfaceDescr}.  It maps record types
       to a list of known extensions.  *)
       
    runCreateNamespace: BOOLEAN;
    (**If @code{TRUE} (the default), then @oproc{Rules.UpdateSymbolFile} runs
       @oproc{CreateNamespace.CreateNamespace} immediately after if has
       read in the symbol file.  *)
    
    errout: IO.ByteChannel;
    (**Error messages are written to this channel.  *)

    forceUpdate: BOOLEAN;
    (**If @code{TRUE}, then compile module even if all derived files are up
       to date with respect to the source code.  This flag has no effect if
       no source code is available.  *)

    uses: Uses.Uses;
    (**Used to track uses of a given list of objects.  Can be @code{NIL}.  *)
  END;

CONST
  stylesheetPackageName = "OOC";
  stylesheetPath = "xml/interface-description.xsl";
  backendNone* = 0;
  backendSSAtoC* = 1;
  backendSSAtoX86* = 2;
  
VAR
  fileIdNames: ARRAY Rep.maxFileId+1 OF ARRAY 24 OF CHAR;
  stylesheetSystemId: URI.URI;
  inspectProc*, inspectStage*: StringSearch.Matcher;
  (**Debug options, not supported by all back-ends.  The matcher
     @ovar{inspectProc} is applied to procedure names.  On success, the
     back-end writes out additional information for the procedure, where the
     granularity can be further reduced by restricting the output to stages
     matching @ovar{inspectStage}.  *)
  writeAST*: BOOLEAN;
  (**If @code{TRUE}, write out the abstract syntax tree for modules.  *)
  writeIR*: BOOLEAN;
  (**If @code{TRUE}, write out the intermediate code representation that
     has been derived from the AST.  *)
  writeStats*: BOOLEAN;
  (**If @code{TRUE}, then the SSA back-end writes the static intruction count
     of all compiled procedures to stdout.  *)
  
CONST
  noSuchModule = 1;
  partOfAnotherLibrary = 2;
  
TYPE
  ErrorContext = POINTER TO ErrorContextDesc;
  ErrorContextDesc = RECORD  (* stateless *)
    (Error.ContextDesc)
  END;

VAR
  makeContext: ErrorContext;

PROCEDURE (context: ErrorContext) GetTemplate* (msg: Error.Msg; VAR templ: Error.LString);
  VAR
    t: ARRAY 128 OF Error.LChar;
  BEGIN
    CASE msg. code OF
    | noSuchModule:
      t := "Cannot locate module `${name}'"
    | partOfAnotherLibrary:
      t := "Module is already part of library `${name}'"
    END;
    context. BaseTemplate (msg, t, templ)
  END GetTemplate;


PROCEDURE InitRules* (r: Rules);
  BEGIN
    r.backend := backendSSAtoC;
    r.library := NIL;
    r.checkAllImportsModule := NIL;
    
    r.localRepository := NIL;
    r.imports := NIL;
    r.mInfo := Dictionary.New();
    r.extensionDict := NIL;
    r.runCreateNamespace := TRUE;
    r.errout := StdChannels.stdout;
    r.forceUpdate := FALSE;
    r.forceUpdate := FALSE;
    r.uses := NIL;
  END InitRules;

PROCEDURE NewRules*(): Rules;
  VAR
    r: Rules;
  BEGIN
    NEW(r);
    InitRules(r);
    RETURN r;
  END NewRules;

PROCEDURE (r: Rules) SetBackend* (backend: LONGINT);
  BEGIN
    r.backend := backend;
  END SetBackend;

PROCEDURE (r: Rules) SetLibrary* (library: Package.Library);
  BEGIN
    r.library := library;
  END SetLibrary;

PROCEDURE (r: Rules) LibraryName*(): STRING;
  BEGIN
    IF (r.library # NIL) THEN
      RETURN r.library.name;
    ELSE
      RETURN NIL;
    END;
  END LibraryName;

PROCEDURE (r: Rules) SetAllImportsModule*(module: Rep.Module);
  BEGIN
    r.checkAllImportsModule := module;
  END SetAllImportsModule;

PROCEDURE (r: Rules) SetErrOut* (ch: IO.ByteChannel);
  BEGIN
    r.errout := ch;
  END SetErrOut;

PROCEDURE (r: Rules) SetForceUpdate*(forceUpdate: BOOLEAN);
  BEGIN
    r.forceUpdate := forceUpdate;
  END SetForceUpdate;

PROCEDURE (r: Rules) UsageTracking*(extIdent: STRING): BOOLEAN;
  VAR
    syntaxError: BOOLEAN;
  BEGIN
    r.uses := Uses.New(extIdent, syntaxError);
    RETURN ~syntaxError;
  END UsageTracking;

PROCEDURE (r: Rules) SetExtensionDict*(dict: Sym.ExtensionDict);
  BEGIN
    r.extensionDict := dict;
  END SetExtensionDict;

PROCEDURE (r: Rules) CheckAllImports(module: Rep.Module): BOOLEAN;
(**If @code{TRUE}, then an update on a symbol file checks all imports
   of the module.  Otherwise, only the imported modules that contribute
    to the module's own symbol file are considered.  *)
  BEGIN
    RETURN (r.checkAllImportsModule = NIL) OR
        (r.checkAllImportsModule = module);
  END CheckAllImports;

PROCEDURE (r: Rules) GetModuleInfo* (module: Rep.Module): ModuleInfo;
  VAR
    i: LONGINT;
    obj: Object.Object;
    mInfo: ModuleInfo;
  BEGIN
    IF r.mInfo.HasKey(module) THEN
      obj := r.mInfo.Get(module);
      mInfo := obj(ModuleInfo);
    ELSE
      NEW(mInfo);
      FOR i := 0 TO Rep.maxFileId DO
        mInfo.updated[i] := FALSE;
        mInfo.updateResult[i] := FALSE;
      END;
      mInfo.compiled := FALSE;
      mInfo.compileResult := FALSE;
      r.mInfo.Set(module, mInfo);
    END;
    RETURN mInfo;
  END GetModuleInfo;

PROCEDURE Exists (module: Rep.Module; fileId: Rep.FileId): BOOLEAN;
  BEGIN
    IF module.FileExists(fileId) THEN
      Logger.ExplainFileMake("file ", module.GetURI(fileId, TRUE), " exists");
      RETURN TRUE;
    ELSE
      Logger.ExplainFileMake("file ", module.GetURI(fileId, TRUE), " does not exist");
      RETURN FALSE;
    END;
  END Exists;

PROCEDURE DerivedIsOlder2 (descendentModule: Rep.Module;
                           descendent: Rep.FileId;
                           ancestorModule: Rep.Module;
                           ancestor: Rep.FileId): BOOLEAN;
(**Return TRUE if the derived file (@oparam{descendentModule},
   @oparam{descendent}) does not exist, or is older than its ancestor file
   (@oparam{ancestorModule}, @oparam{ancestor}).

   @precond
   The ancestor file exists and is up to date.
   @end precond  *)
  VAR
    tsDesc, tsAncest: Time.TimeStamp;
  BEGIN
    descendentModule.GetTimeStamp(descendent, tsDesc);
    IF (tsDesc.days = MAX(LONGINT)) THEN
      Logger.ExplainFileMake("file ", descendentModule.GetURI(descendent, TRUE),
                             " does not exist");
      RETURN TRUE;
    ELSE
      ancestorModule.GetTimeStamp(ancestor, tsAncest);
      IF (tsDesc.Cmp(tsAncest) >= 0) THEN
        Logger.ExplainFilesMake("ts(", descendentModule.GetURI(descendent, TRUE),
                                ") >= ts(", ancestorModule.GetURI(ancestor, TRUE), ")");
        RETURN FALSE;
      ELSE
        Logger.ExplainFilesMake("ts(", descendentModule.GetURI(descendent, TRUE),
                                ") < ts(", ancestorModule.GetURI(ancestor, TRUE), ")");
        RETURN TRUE;
      END;
    END;
  END DerivedIsOlder2;

PROCEDURE DerivedIsOlder (module: Rep.Module; descendent, ancestor: Rep.FileId): BOOLEAN;
  BEGIN
    RETURN DerivedIsOlder2(module, descendent, module, ancestor);
  END DerivedIsOlder;

PROCEDURE FingerprintMismatch (descendentModule: Rep.Module;
                               descendentFP: LONGINT;
                               ancestorModule: Rep.Module;
                               ancestorFP: LONGINT): BOOLEAN;
  BEGIN
    IF (descendentFP = ancestorFP) THEN
      Logger.ExplainFilesMake("fp(", descendentModule.GetURI(Rep.modSymbolFile, TRUE),
                              ") = fp(", ancestorModule.GetURI(Rep.modSymbolFile, TRUE), ")");
      RETURN FALSE;
    ELSE
      Logger.ExplainFilesMake("fp(", descendentModule.GetURI(Rep.modSymbolFile, TRUE),
                              ") # fp(", ancestorModule.GetURI(Rep.modSymbolFile, TRUE), ")");
      RETURN TRUE;
    END;
  END FingerprintMismatch;

PROCEDURE CreateErrList(module: Rep.Module): Error.List;
  VAR
    uri: URI.URI;
  BEGIN
    uri := module.GetURI(Rep.modModuleSource, TRUE);
    RETURN Error.NewList(uri.ToString());
  END CreateErrList;

PROCEDURE (r: Rules) WriteErrList* (errList: Error.List);
  BEGIN
    IF (errList.msgCount # 0) THEN
      errList.Write(r.errout);
    END;
  END WriteErrList;

PROCEDURE (r: Rules) WriteError(module: Rep.Module; res: Msg.Msg);
  VAR
    errList: Error.List;
  BEGIN
    errList := CreateErrList(module);
    errList.Append(res);
    r.WriteErrList(errList);
  END WriteError;

<*PUSH; Warnings:=FALSE*>
PROCEDURE WriteImports (module: Rep.Module);
  VAR
    import: Rep.Module;
    i: LONGINT;
  BEGIN
    ASSERT(module.ifQuality >= Rep.importsOnly);
    Out.String("> IMPORT of "); Out.String(module.name^); Out.Ln;
    FOR i := 0 TO LEN(module.ifImportList^)-1 DO
      import := Config.repositories.GetModule(module.ifImportList[i].name.str^);
      IF (import = NIL) THEN
        Out.String("> no such module: ");
        Out.String(module.ifImportList[i].name.str^);
        Out.Ln;
      ELSE
        Out.String("> ");
        Out.String(import.name^);
        Out.Ln;
      END;
    END;
  END WriteImports;
<*POP*>

PROCEDURE (r: Rules) GetImports(module: Rep.Module): BOOLEAN
RAISES IO.Error;
(**Retrieves the imports of @oparam{module} together with any other data from
   the module header, and stores the result in @oparam{module}.  Result is
   @code{TRUE} on success, and @code{FALSE} if no provably up to date data
   could be retrieved for the module.

   Note: This function only looks at the given module.  It does not descend to
   other modules that are imported by it.  *)
  VAR
    ast: AST.Node;
    symTab: Sym.Module;
    pragmaHistory: Pragmas.History;
    errList: Error.List;
    
  PROCEDURE ResolveNames ();
    VAR
      i: LONGINT;
      import: Rep.Module;
      
    PROCEDURE Err (code: Error.Code; sym: Sym.Name);
      VAR
        lastError: Error.Msg;
        pos: LONGINT;
      BEGIN
        lastError := Error.New (makeContext, code);
        pos := sym.pos;
        IF (pos < 0) THEN
          pos := 0;
        END;
        lastError. SetIntAttrib ("pos", pos);
        lastError. SetIntAttrib ("line", sym. line);
        lastError. SetIntAttrib ("column", sym. column);
        lastError. SetStringAttrib ("name", Msg.GetStringPtr(sym. str^));
        errList. Append (lastError)
      END Err;
    
    BEGIN
      FOR i := 0 TO LEN(module.ifImportList^)-1 DO
        IF ~module.ifImportList[i].internal THEN
          import := Config.repositories.GetModule(module.ifImportList[i].name.str^);
          IF (import = NIL) THEN
            Err (noSuchModule, module.ifImportList[i].name);
          ELSE
            module.ifImportList[i].module := import;
          END;
        END;
      END;
    END ResolveNames;
  
  BEGIN
    Logger.EnterMake("GetImports", module.name^);
    IF (module.ifQuality # Rep.noInterfaceData) THEN
      Logger.ExplainMake("using cached value");
      RETURN Logger.ExitMake("GetImports", module.name^, TRUE);
      
    ELSIF Exists(module, Rep.modModuleSource) &
          DerivedIsOlder(module, Rep.modSymbolFile, Rep.modModuleSource) THEN
      (* the symbol file does not exist, or the source file is more recent
         than the symbol file: extract information from source file *)
      ParseModule.ParseModule(module, FALSE, FALSE, FALSE, TRUE,
                              r.LibraryName(), r.uses,
                              ast, symTab, pragmaHistory, errList);
      IF errList.NoErrors() THEN
        module.SetInterfaceData(symTab, Rep.importsOnly,
                                r.CheckAllImports(module));
      END;
      
    ELSE
      (* symbol file exists and is up to date, at least as far as the
         import list and the module header are concerned *)
      errList := CreateErrList(module);
      symTab := module.ReadSymbolFile();
      
      module.SetInterfaceData(symTab, Rep.importsWithFingerprint,
                              r.CheckAllImports(module));
      module.SetFingerprint(symTab.fingerprint);
    END;

    IF errList.NoErrors() THEN
      ResolveNames();
    END;
    
    r.WriteErrList(errList);
    RETURN Logger.ExitMake("GetImports", module.name^, errList.NoErrors());
  END GetImports;


PROCEDURE ^ (r: Rules) Update*(module: Rep.Module;
                               fileId: Rep.FileId): BOOLEAN;

PROCEDURE (r: Rules) SelectBackend(module: Rep.Module): LONGINT
RAISES IO.Error;
  VAR
    b: LONGINT;
  BEGIN
    b := r.backend;
    IF r.GetImports(module) THEN
      IF (b = backendSSAtoX86) &
         ((module.ifData.class = Sym.mcForeign) OR
          (module.ifData.class = Sym.mcInterface)) THEN
        b := backendSSAtoC;
      END;
    END;
    RETURN b;
  END SelectBackend;

PROCEDURE (r: Rules) CompileModule*(module: Rep.Module;
                                    analysisOnly: BOOLEAN): BOOLEAN
(**With @oparam{analysisOnly}, no output files are written.  Note: This is only
   implemented for the C back-end right now.  *)
RAISES IO.Error;
  VAR
    success: BOOLEAN;
    mInfo: ModuleInfo;
    errList: Error.List;
    libraryName: STRING;
    
  PROCEDURE DoEmptyBackend(libraryName: STRING): Error.List
  RAISES IO.Error;
    VAR
      ast: AST.Node;
      symTab: Sym.Module;
      errList: Error.List;
      pragmaHistory: Pragmas.History;
    BEGIN
      ParseModule.ParseModule (module, FALSE, TRUE, TRUE, FALSE, libraryName,
                               r.uses, ast, symTab, pragmaHistory, errList);
      RETURN errList;
    END DoEmptyBackend;
  
  PROCEDURE DoSSAtoC(libraryName: STRING): Error.List
  RAISES IO.Error;
    VAR
      t: TranslateToC.Translator;
    BEGIN
      t := SSAtoC.NewTranslator(writeStats, inspectProc, inspectStage);
      RETURN TranslateToC.Run(module, libraryName, analysisOnly, r.uses,
                              writeAST, writeIR, t);
    END DoSSAtoC;
  
  PROCEDURE DoSSAtoX86(libraryName: STRING): Error.List
  RAISES IO.Error;
    BEGIN
      RETURN TranslateToX86.Run(module, libraryName, analysisOnly, r.uses,
                                writeAST, writeIR);
    END DoSSAtoX86;
  
  BEGIN
    mInfo := r.GetModuleInfo(module);
    IF mInfo.compiled THEN
      Logger.ExplainMake("cached result: CompileModule");
      RETURN mInfo.compileResult;
    ELSE
      Logger.EnterMake("CompileModule", module.name^);

      libraryName := r.LibraryName();
      IF (libraryName # NIL) & (module.origin # r.localRepository) THEN
        (* only include modules from the repository of the top-level module
           in the library; alternatively, we might report this as a fatal
           error, because shared libraries cannot depend on plain object files
           on some (all?) systems *)
        libraryName := NIL;
      END;
      
      CASE r.SelectBackend(module) OF
      | backendNone:
        errList := DoEmptyBackend(libraryName);
      | backendSSAtoC:
        errList := DoSSAtoC(libraryName);
      | backendSSAtoX86:
        errList := DoSSAtoX86(libraryName);
      END;

      success := (errList = NIL) OR errList.NoErrors();
      IF success & ~analysisOnly THEN
        (* read symbol file that we have just written *)
        module.SetInterfaceData(NIL, Rep.noInterfaceData, TRUE);
        success := r.GetImports(module);
        IF success THEN
          module.SetInterfaceData(module.ifData, Rep.completeInterface, TRUE);
        END;
      END;
      r.WriteErrList(errList);
      
      mInfo.compiled := TRUE;
      mInfo.compileResult := success;
      RETURN Logger.ExitMake("CompileModule", module.name^, success);
    END;
  END CompileModule;

PROCEDURE (r: Rules) UpdateSymbolFile(module: Rep.Module): BOOLEAN
RAISES IO.Error;
  VAR
    i: LONGINT;
    isUpToDate, sourceExists, dummy: BOOLEAN;
    errList: Error.List;
    err: Error.Msg;
    chars: Object.CharsLatin1;
  BEGIN
    IF (module.ifQuality = Rep.completeInterface) THEN
      (* we have the results cached *)
      RETURN TRUE;
    ELSIF r.GetImports(module) THEN
      (* tentatively mark file as up to date if the source file does not
         exist, or if the symbol file is not older than the source *)
      sourceExists := Exists(module, Rep.modModuleSource);
      isUpToDate := ~sourceExists OR
          ~DerivedIsOlder(module, Rep.modSymbolFile, Rep.modModuleSource);
      
      IF (r.LibraryName() # NIL) & (module.origin = r.localRepository) THEN
        IF (module.ifData.libraryName = NIL) THEN
          (* the symbol file does not exist, or it does not associate the
             module with any library: force compilation of module *)
          Logger.ExplainMake("module is not part of a library");
          isUpToDate := FALSE;
          
        ELSIF ~module.ifData.libraryName.Equals(r.LibraryName()) THEN
          (* the symbol file says the module is part of another library in
             the same repository; assume that this is not intended and
             report a fatal error *)
          err := Error.New (makeContext, partOfAnotherLibrary);
          chars := module.ifData.libraryName(Object.String8).CharsLatin1();
          err. SetStringAttrib ("name", Msg.GetStringPtr(chars^));
          r.WriteError(module, err);
          RETURN FALSE;
        END;
      END;
      
      (* unconditionally bring the symbol files of all imported modules up to
         date and see if any of them invalidates this symbol file  *)
      i := 0;
      WHILE (i # LEN(module.ifImportList^)) DO
        IF ~module.ifImportList[i].internal THEN
          IF r.Update(module.ifImportList[i].module, Rep.modSymbolFile) THEN
            (* mark for compilation if an imported symbol file is more recent
               than our file, but not if the times are equal; compilation of
               small modules may produce the same timestamp as that of an
               imported module  *)
            isUpToDate := isUpToDate &
                ~FingerprintMismatch(module,
                                     module.ifImportList[i].fingerprint,
                                     module.ifImportList[i].module,
                                     module.ifImportList[i].module.ifData.fingerprint);
          ELSE
            RETURN FALSE;
          END;
        END;
        INC(i);
      END;

      (* with the doc strings split off into a separate file, this file must
         exist as well or we may fail to read the symbol file back again *)
      isUpToDate := isUpToDate & Exists(module, Rep.modSymbolFileDoc);
      
      IF isUpToDate THEN
        (* if the file is current, then GetImports() has already read it
           and we only need to complete the data *)
        ASSERT(module.ifData # NIL);
        module.SetInterfaceData(module. ifData, Rep.completeInterface,
                                r.CheckAllImports(module));

        IF (r.uses # NIL) & sourceExists & r.uses.TrackingDeclarations() THEN
          (* symbol file is up to date, but we are looking for uses of
             declarations: compile module in "analysis only" mode *)
          dummy := r.CompileModule(module, TRUE);
        END;
      ELSE
        isUpToDate := r.CompileModule(module, FALSE);
      END;

      IF isUpToDate THEN
        errList := CreateErrList(module);
        CreateNamespace.CreateNamespace(module.ifData, r.uses, errList);
        r.WriteErrList(errList);
        IF ~errList.NoErrors() THEN
          r.WriteErrList(errList);
          isUpToDate := FALSE;
        END;
      END;
      
      RETURN isUpToDate;
    END;
    RETURN FALSE;
  END UpdateSymbolFile;

PROCEDURE (r: Rules) UpdateSymbolTableXML*(module: Rep.Module): BOOLEAN
RAISES IO.Error;
(* Must be redefined by application when used.  *)
  BEGIN
<*PUSH; Assertions:=TRUE*>
    ASSERT (FALSE);
<*POP*>
  END UpdateSymbolTableXML;

PROCEDURE (r: Rules) UpdateInterfaceDescr (module: Rep.Module): BOOLEAN
RAISES IO.Error;
  VAR
    success: BOOLEAN;
    outputChannel: IO.ByteChannel;
    errList: Error.List;
  BEGIN
    success := r.Update(module, Rep.modSymbolFile);
    IF success THEN
      (* the interface XML code depends on the symbol file of the module, which
         includes descriptions of declarations, and on the symbol files of all
         modules imported by it; actually, it may even contain 
         information from modules that are imported indirectly, e.g., when
         inheriting a method description from a remote base class

         because changes in a symbol file's signature are propagated upward,
         depending on only the local symbol file should be sufficient  *)
      IF DerivedIsOlder(module, Rep.modInterfaceDescr, Rep.modSymbolFile) THEN
        errList := CreateErrList(module);
        CreateNamespace.CreateNamespace(module.ifData, r.uses, errList);
        ResolveRef.Resolve(module.ifData, errList);
        ASSERT (errList.msgCount = 0);
        
        outputChannel := module.GetOutputChannel(Rep.modInterfaceDescr, TRUE);
        InterfaceDescr.Write (outputChannel,
                              module.GetURI (Rep.modInterfaceDescr, FALSE),
                              module.ifData,
                              Config.repositories, r.extensionDict);
        outputChannel.CloseAndRegister();
        
        r.WriteErrList(errList);
        success := errList.NoErrors();
      END;
    END;
    RETURN success;
  END UpdateInterfaceDescr;

PROCEDURE (r: Rules) UpdateInterfaceXML (module: Rep.Module): BOOLEAN
RAISES IO.Error;
  VAR
    success: BOOLEAN;
    outputChannel: IO.ByteChannel;
    errList: Error.List;
    ast: AST.Node;
    symTab: Sym.Module;
    pragmaHistory: Pragmas.History;
  BEGIN
    success := r.Update(module, Rep.modSymbolFile);
    IF success THEN
      (* the interface XML code depends on the symbol file and the XML
         interface descriptions of all imported modules; the latter is
         necessary because the current HTML generation process relies on
         the XML files of directly and indirectly imported modules *)
      IF DerivedIsOlder(module, Rep.modInterfaceXML, Rep.modSymbolFile) THEN
        errList := CreateErrList(module);

        ParseModule.ParseModule(module, FALSE, TRUE, FALSE, FALSE,
                                r.LibraryName(), r.uses,
                                ast, symTab, pragmaHistory, errList);
        IF errList.NoErrors() THEN
          outputChannel := module.GetOutputChannel(Rep.modInterfaceXML, TRUE);
          InterfaceXML.Write(outputChannel,
                             module.GetURI(Rep.modInterfaceXML, FALSE),
                             symTab, Config.repositories);
          outputChannel.CloseAndRegister();
        END;

        r.WriteErrList(errList);
        success := errList.NoErrors();
      END;
    END;
    RETURN success;
  END UpdateInterfaceXML;

PROCEDURE (r: Rules) UpdateInterfaceHTML(module: Rep.Module): BOOLEAN
RAISES IO.Error;
  VAR
    sb: StringBuffer.StringBuffer;
    cmd, path: STRING;
    success: BOOLEAN;
    uri: URI.URI;
    exit: LONGINT;
    errList: Error.List;
    
  PROCEDURE GetSystemId (repositories: Repositories.Section): URI.URI;
    BEGIN
      IF (stylesheetSystemId = NIL) THEN
        stylesheetSystemId := repositories. GetResource (stylesheetPackageName, stylesheetPath);
        IF (stylesheetSystemId = NIL) THEN
          Out.String ("Error: Cannot locate stylesheet "+stylesheetPath+
                      " from package "+stylesheetPackageName+" in any of the "+
                      "configured repositories.");
          Out.Ln;
          HALT (1)
        END;
        RETURN stylesheetSystemId
      ELSE
        RETURN stylesheetSystemId
      END
    END GetSystemId;
  
  BEGIN
    success := r.Update(module, Rep.modInterfaceDescr);
    IF success THEN
      IF DerivedIsOlder(module, Rep.modInterfaceHTML, Rep.modInterfaceDescr) THEN
        exit := 0;

        (* xsltproc command name *)
        sb := StringBuffer.New(Config.xsltproc.value.ToString());
        
        (* put -o <file> option in front of style sheet  *)
        sb.Append(" -o ");
        uri := module. GetURI (Rep.modInterfaceHTML, TRUE);
        path := uri(File.URI).GetPath();
        sb.Append(Path.QuoteForShell(path));

        (* create directory for HTML file, if it does not exist *)
        OSFiles.MakeDirs (Path.DirName(path), OSFiles.defaultMode);
        
        (* append file name of style sheet *)
        uri := GetSystemId (Config.repositories);
        sb.Append(" ");
        sb.Append(Path.QuoteForShell(uri(File.URI).GetPath()));
        
        (* append name of XML file *)
        uri := module. GetURI (Rep.modInterfaceDescr, TRUE);
        sb.Append(" ");
        sb.Append(Path.QuoteForShell(uri(File.URI).GetPath()));
        
        cmd := sb.ToString();
        Logger.ShellCommand(cmd);
        exit := ProcessManagement.system(cmd);
        
        errList := NIL;
        success := (exit = 0);
      END;
    END;
    RETURN success;
  END UpdateInterfaceHTML;

PROCEDURE UpdateCompilerOutput (r: Rules; module: Rep.Module;
                                fileId: Rep.FileId): BOOLEAN
RAISES IO.Error;
  BEGIN
    IF Exists(module, Rep.modModuleSource) THEN
      IF r.forceUpdate OR
         DerivedIsOlder(module, fileId, Rep.modModuleSource) THEN
        RETURN r.CompileModule(module, FALSE);
      ELSE
        RETURN TRUE;
      END;
    ELSE
      RETURN Exists(module, fileId);
    END;
  END UpdateCompilerOutput;

PROCEDURE (r: Rules) UpdateHeaderFileC(module: Rep.Module): BOOLEAN
RAISES IO.Error;
(* Update header file and all other header files included by it.

   Note: Interface changes are propagated through the symbol files, which may
   cause header files to be updated as well.  In general new header files do
   @emph{not} cause their client headers or C files to be updated.  *)
  VAR
    i: LONGINT;
  BEGIN
    IF r.GetImports(module) THEN
      FOR i := 0 TO LEN(module.ifImportList^)-1 DO
        IF ~module.ifImportList[i].internal &
           ~r.Update(module.ifImportList[i].module, Rep.modHeaderFileC) THEN
          RETURN FALSE;
        END;
      END;
      RETURN UpdateCompilerOutput(r, module, Rep.modHeaderFileC);
    ELSE
      RETURN FALSE;
    END;
  END UpdateHeaderFileC;

PROCEDURE (r: Rules) UpdateDeclFileC(module: Rep.Module): BOOLEAN
RAISES IO.Error;
  BEGIN
    RETURN
        r.Update(module, Rep.modHeaderFileC) &
        UpdateCompilerOutput(r, module, Rep.modDeclFileC);
  END UpdateDeclFileC;

PROCEDURE (r: Rules) UpdateCodeFileC(module: Rep.Module): BOOLEAN
RAISES IO.Error;
  BEGIN
    IF r.Update(module, Rep.modDeclFileC) THEN
      IF (module.ifData.class = Sym.mcForeign) OR
         (module.ifData.class = Sym.mcInterface) THEN
        Logger.ExplainMake("module's C code provided by user");
        RETURN TRUE;
      ELSE
        RETURN UpdateCompilerOutput(r, module, Rep.modCodeFileC);
      END;
    ELSE
      RETURN FALSE;
    END;
  END UpdateCodeFileC;

PROCEDURE (r: Rules) UpdateAssemblerFile(module: Rep.Module): BOOLEAN
RAISES IO.Error;
  BEGIN
    IF r.GetImports(module) THEN
      IF (module.ifData.class = Sym.mcForeign) OR
         (module.ifData.class = Sym.mcInterface) THEN
        Logger.ExplainMake("module's C code provided by user");
        RETURN TRUE;
      ELSE
        RETURN UpdateCompilerOutput(r, module, Rep.modAssemblerFile);
      END;
    ELSE
      RETURN FALSE;
    END;
  END UpdateAssemblerFile;

PROCEDURE (r: Rules) UpdateObjectFile(module: Rep.Module): BOOLEAN
RAISES IO.Error;
(* Update object file if the underlying symbol file or C file has been changed.
   Because the symbol file is regenerated each time the interface of an
   imported module changes, the dependency on the symbol file triggers an
   update if the interface of an included header file may have changed in a
   significant way.  *)
  VAR
    cmd: STRING;
    success: BOOLEAN;
  BEGIN
    IF ~CCompiler.HaveLibtool() &
       ~Exists(module, Rep.modModuleSource) &
       Exists(module, Rep.modObjectFile) THEN
      (* Without libtool, we have no static or shared libraries and everything
         is done with plain object files.  In this case, the object files are
         installed without their source code, and cannot be rebuild.  In fact,
         testing if they need to be rebuild leads to errors.  So shortcut the
         process for this special case.  *)
      Logger.ExplainMake("no source code available, and object file exists");
      RETURN TRUE;
    END;
    
    IF (r.SelectBackend(module) = backendSSAtoX86) THEN
      success := r.Update(module, Rep.modAssemblerFile);
      IF DerivedIsOlder(module, Rep.modObjectFile, Rep.modAssemblerFile) THEN
        module.CreateOutputDir (Rep.modObjectFile);
        cmd := Assembler.AssembleFileCmd(module.GetURI(Rep.modAssemblerFile, TRUE),
                                  module.GetURI(Rep.modObjectFile, TRUE));
        Logger.ShellCommand(cmd);
        success := (ProcessManagement.system (cmd) = 0);
      END;
      
    ELSE
      success := r.Update(module, Rep.modCodeFileC);
      IF success & ~CCompiler.SkipCallCC() &
         DerivedIsOlder(module, Rep.modObjectFile, Rep.modCodeFileC) THEN
        module.CreateOutputDir (Rep.modObjectFile);
        cmd := CCompiler.CompileFileCmd(module.GetURI(Rep.modCodeFileC, TRUE),
                                        module.GetURI(Rep.modObjectFile, TRUE),
                                        FALSE);
        Logger.ShellCommand(cmd);
        success := (ProcessManagement.system(cmd) = 0);
      END;
    END;
    RETURN success;
  END UpdateObjectFile;

PROCEDURE (r: Rules) UpdateObjectFileLib(module: Rep.Module): BOOLEAN
RAISES IO.Error;
(* Like UpdateObjectFile(), but produce an object file suitable for
   a libtool-style library.

   @precond
   This method is called from @oproc{Rules.UpdateLibrary}.  
   @end precond *)
  VAR
    cmd: STRING;
    success: BOOLEAN;
    outputFile: URI.URI;
  BEGIN
    success := r.Update(module, Rep.modCodeFileC);
    IF ~CCompiler.SkipCallCC() &
       DerivedIsOlder(module, Rep.modObjectFileLib, Rep.modCodeFileC) THEN
      module.CreateOutputDir (Rep.modObjectFile);
      outputFile := module.GetURI(Rep.modObjectFileLib, TRUE);
      cmd := CCompiler.CompileFileCmd(module.GetURI(Rep.modCodeFileC, TRUE),
                                      module.GetURI(Rep.modObjectFileLib, TRUE),
                                      TRUE);
      Logger.ShellCommand(cmd);
      success := (ProcessManagement.system(cmd) = 0);
    END;
    RETURN success;
  END UpdateObjectFileLib;

PROCEDURE (r: Rules) UpdateMainFileC (module: Rep.Module): BOOLEAN
RAISES IO.Error;
(* Write a new main file if it does not exist, or if a symbol file
   of a module in @oparam{imports} is more recent than the existing
   main file.  The latter avoids re-linking if no file has been touched.
   
   @precond
   This method is called within @oproc{Rules.UpdateExecutable}.
   @endprecond *)
  VAR
    success, isUpToDate: BOOLEAN;
    i: LONGINT;
  BEGIN  (* pre: symbol files of all imports[x] are up to date *)
    success := r.Update(module, Rep.modSymbolFile); (* also updates import data *)
    IF success THEN
      isUpToDate := Exists(module, Rep.modMainFileC);
      i := 0;
      WHILE isUpToDate & (i # LEN(r.imports^)) DO
        IF DerivedIsOlder2(module, Rep.modMainFileC,
                           r.imports[i], Rep.modSymbolFile) THEN
          isUpToDate := FALSE;
        END;
        INC(i);
      END;
      
      IF ~isUpToDate THEN
        WriteMainFileC.WriteFile(module, r.imports^);
        success := TRUE;
      END;
    END;
    RETURN success;
  END UpdateMainFileC;

PROCEDURE (r: Rules) UpdateMainFileX86(module: Rep.Module): BOOLEAN
RAISES IO.Error;
  VAR
    success, isUpToDate: BOOLEAN;
    i: LONGINT;
  BEGIN  (* pre: symbol files of all imports[x] are up to date *)
    success := r.Update(module, Rep.modSymbolFile); (* also updates import data *)
    IF success THEN
      isUpToDate := Exists(module, Rep.modMainFileAssembler);
      i := 0;
      WHILE isUpToDate & (i # LEN(r.imports^)) DO
        IF DerivedIsOlder2(module, Rep.modMainFileAssembler,
                           r.imports[i], Rep.modSymbolFile) THEN
          isUpToDate := FALSE;
        END;
        INC(i);
      END;
      
      IF ~isUpToDate THEN
        WriteMainFileAssembler.WriteFile(module, r.imports^);
      END;
    END;
    RETURN success;
  END UpdateMainFileX86;

PROCEDURE (r: Rules) UpdateMainObjectFile (module: Rep.Module): BOOLEAN
RAISES IO.Error;
(* Produce a new object file with the main function if the file does not
   exist, or if the input C file is more recent.

   @precond
   This method is called within @oproc{Rules.UpdateExecutable}.
   @endprecond *)
  VAR
    cmd: STRING;
    success: BOOLEAN;
  BEGIN
    IF (r.backend = backendSSAtoX86) THEN
      success := r.Update(module, Rep.modMainFileAssembler);
      IF DerivedIsOlder(module, Rep.modMainObjectFile,
                        Rep.modMainFileAssembler) THEN
        module.CreateOutputDir (Rep.modMainObjectFile);
        cmd := Assembler.AssembleFileCmd(module.GetURI(Rep.modMainFileAssembler, TRUE),
                                  module.GetURI(Rep.modMainObjectFile, TRUE));
        Logger.ShellCommand(cmd);
        success := (ProcessManagement.system(cmd) = 0);
      END;
      
    ELSE
      success := r.Update(module, Rep.modMainFileC);
      IF ~CCompiler.SkipCallCC() &
         DerivedIsOlder(module, Rep.modMainObjectFile, Rep.modMainFileC) THEN
        module.CreateOutputDir (Rep.modMainObjectFile);
        cmd := CCompiler.CompileFileCmd(module.GetURI(Rep.modMainFileC, TRUE),
                                        module.GetURI(Rep.modMainObjectFile, TRUE),
                                        FALSE);
        Logger.ShellCommand(cmd);
        success := (ProcessManagement.system(cmd) = 0);
      END;
    END;
    RETURN success;
  END UpdateMainObjectFile;

PROCEDURE ModuleClosure*(module: Rep.Module): ModuleList;
  VAR
    i: LONGINT;
    dict: Dictionary.Dictionary;
    list: ArrayList.ArrayList;
    a: ModuleList;
    
  PROCEDURE Closure (module: Rep.Module);
    VAR
      i: LONGINT;
    BEGIN
      IF ~dict.HasKey(module) THEN
        dict.Set(module, NIL);
        
        FOR i := 0 TO LEN(module.ifImportList^)-1 DO
          IF ~module.ifImportList[i].internal THEN
            ASSERT(module.ifImportList[i].module # NIL);
            Closure(module.ifImportList[i].module);
          END;
        END;

        list.Append(module);  (* importing module follows its imports *)
      END;
    END Closure;
  
  BEGIN
    dict := Dictionary.New();
    list := ArrayList.New(16);
    Closure(module);
    NEW(a, list.size);
    FOR i := 0 TO list.size-1 DO
      a[i] := list.array[i](Rep.Module);
    END;
    RETURN a;
  END ModuleClosure;

PROCEDURE (r: Rules) UpdateExecutable(module: Rep.Module): BOOLEAN
RAISES IO.Error;
(**Update executable that uses @oparam{module} as its main module.  If any of
   the modules has changed, or if an object file is missing, then rebuild as
   needed.  Result is @code{TRUE} on success, and @code{FALSE} if the current
   executable is not up to date, and could not be rebuild.  *)
  VAR
    i: LONGINT;
    success, isUpToDate: BOOLEAN;
    dict: Dictionary.Dictionary;
    list: ArrayList.ArrayList;
    
  PROCEDURE Closure (module: Rep.Module);
    VAR
      i: LONGINT;
    BEGIN
      IF ~dict.HasKey(module) THEN
        dict.Set(module, NIL);
        
        FOR i := 0 TO LEN(module.ifImportList^)-1 DO
          IF ~module.ifImportList[i].internal THEN
            ASSERT(module.ifImportList[i].module # NIL);
            Closure(module.ifImportList[i].module);
          END;
        END;

        list.Append(module);  (* importing module follows its imports *)
      END;
    END Closure;
  
  BEGIN
    success := FALSE;
    IF r.Update(module, Rep.modSymbolFile) THEN (* also updates all import data *)
      (* the link command depends on the object file containing the main()
         function, and on the object files of all modules that are imported
         directly or indirectly by the main module  *)
      r.imports := ModuleClosure(module);
      
      isUpToDate := TRUE;
      FOR i := 0 TO LEN(r.imports^)-1 DO
        IF (r.imports[i].ifQuality = Rep.completeInterface) &
           (r.imports[i].ifData.libraryName # NIL) THEN
          (* the module is part of a library: assume that the library
             exists and that the object file in it is up to date *)
        ELSIF r.imports[i].ifData.NoObjectFile() THEN
          (* this in an INTERFACE or MODULE without a code file *)
        ELSIF ~r.Update(r.imports[i], Rep.modObjectFile) THEN
          RETURN FALSE;
        ELSIF DerivedIsOlder2(module, Rep.modExecutable,
                              r.imports[i], Rep.modObjectFile) THEN
          isUpToDate := FALSE;
        END;
      END;
      
      IF ~r.Update(module, Rep.modMainObjectFile) THEN
        (* doing this after the normal modules should ensure that RT0.h
           exists *)
        RETURN FALSE;
      END;
      isUpToDate := isUpToDate &
          ~DerivedIsOlder(module, Rep.modExecutable, Rep.modMainObjectFile);
      
      success := isUpToDate OR CCompiler.SkipCallCC() OR
          LinkProgramC.Run(module, r.imports^, NIL);
    END;
    RETURN success;
  END UpdateExecutable;

PROCEDURE (r: Rules) UpdateLibrary(module: Rep.Module): BOOLEAN
RAISES IO.Error;
(**Update or create a library that is described by the import list of
   @oparam{module}.  Library name and version number are taken from the
   module's source code.  Result is @code{TRUE} on success, and @code{FALSE} if
   the current library is not up to date, and could not be rebuild.  As a
   side-effect, @ofield{r.imports} is set to the list of modules that are
   part of the library.

   @precond
   @ofield{r.library} is set.
   @end precond*)
  VAR
    success, isUpToDate: BOOLEAN;
    closure: ModuleList;
    i: LONGINT;
    importLibrary: STRING;
  BEGIN
    r.localRepository := module.origin;
    
    (* Discovery and symbol file creation: Update all modules from the
       current repository that are imported by `module' for inclusion in the
       indicated library.  *)
    success := r.Update(module, Rep.modSymbolFile);
    IF success THEN
      closure := ModuleClosure(module);
      r.imports := closure;
      
      (* Create library files (static and shared).  *)
      isUpToDate := Exists(module, Rep.modLibrary);
      FOR i := 0 TO LEN(closure^)-1 DO
        importLibrary := closure[i].ifData.libraryName;
        IF (importLibrary # NIL) & ~importLibrary.Equals(r.LibraryName()) THEN
          (* skip, it is from another library *)
        ELSIF closure[i].ifData.NoObjectFile() THEN
          (* skip *)
        ELSIF ~r.Update(closure[i], Rep.modObjectFileLib) THEN
          RETURN FALSE;
        ELSIF DerivedIsOlder2(module, Rep.modLibrary,
                              closure[i], Rep.modObjectFileLib) THEN
          isUpToDate := FALSE;
        END;
      END;

      IF ~isUpToDate THEN
        (* Collect library meta data: Scan for libraries that need to be linked
           into this library.  Only consider libraries that are linked directly
           into our library, and assume that libtool keeps track of nested
           links.  *)
        (* ... *)
        
        (* Link library *)
        success := isUpToDate OR
            LinkProgramC.Run(module, closure^, r.library);
        
        (* Write library meta file containing OOC's information about the new
           library.  *)
        (* ... *)
      END;
    END;
    RETURN success;
  END UpdateLibrary;

PROCEDURE (r: Rules) Update*(module: Rep.Module; fileId: Rep.FileId): BOOLEAN
RAISES IO.Error;
  VAR
    res: BOOLEAN;
    mInfo: ModuleInfo;
  BEGIN
    mInfo := r.GetModuleInfo(module);
    IF mInfo.updated[fileId] THEN
      RETURN Logger.CachedMake(fileIdNames[fileId],
                               module.name^, mInfo.updateResult[fileId]);
    ELSIF (fileId IN module.visitedByMake) THEN
      Out.String("Error: Cyclic dependency in module ");
      Out.String(module.name^);
      Out.Ln;
      RETURN FALSE;
    ELSE
      Logger.EnterMake(module.name^, fileIdNames[fileId]);
      INCL(module.visitedByMake, fileId);
      CASE fileId OF
      | Rep.modExecutable:
        res := r.UpdateExecutable(module);
      | Rep.modLibrary:
        res := r.UpdateLibrary(module);
      | Rep.modMainObjectFile:
        res := r.UpdateMainObjectFile(module);
      | Rep.modMainFileC:
        res := r.UpdateMainFileC(module);
      | Rep.modMainFileAssembler:
        res := r.UpdateMainFileX86(module);
      | Rep.modObjectFile:
        res := r.UpdateObjectFile(module);
      | Rep.modObjectFileLib:
        res := r.UpdateObjectFileLib(module);
      | Rep.modCodeFileC:
        res := r.UpdateCodeFileC(module);
      | Rep.modDeclFileC:
        res := r.UpdateDeclFileC(module);
      | Rep.modHeaderFileC:
        res := r.UpdateHeaderFileC(module);
      | Rep.modAssemblerFile:
        res := r.UpdateAssemblerFile(module);
      | Rep.modInterfaceDescr:
        res := r.UpdateInterfaceDescr(module);
      | Rep.modInterfaceXML:
        res := r.UpdateInterfaceXML(module);
      | Rep.modInterfaceHTML:
        res := r.UpdateInterfaceHTML(module);
      | Rep.modSymbolTableXML:
        res := r.UpdateSymbolTableXML(module);
      | Rep.modSymbolFile:
        res := r.UpdateSymbolFile(module);
      END;
      mInfo.updated[fileId] := TRUE;
      mInfo.updateResult[fileId] := res;
      EXCL(module.visitedByMake, fileId);
      RETURN Logger.ExitMake(module.name^, fileIdNames[fileId], res);
    END;
  END Update;

BEGIN
  inspectProc := NoMatch.matcher;
  inspectStage := NoMatch.matcher;
  writeAST := FALSE;
  writeIR := FALSE;
  writeStats := FALSE;
  stylesheetSystemId := NIL;
  
  fileIdNames[Rep.modExecutable] := "Executable";
  fileIdNames[Rep.modLibrary] := "Library";
  fileIdNames[Rep.modMainObjectFile] := "MainObjectFile";
  fileIdNames[Rep.modMainFileC] := "MainFileC";
  fileIdNames[Rep.modObjectFile] := "ObjectFile";
  fileIdNames[Rep.modObjectFileLib] := "ObjectFileLib";
  fileIdNames[Rep.modCodeFileC] := "CodeFileC";
  fileIdNames[Rep.modDeclFileC] := "DeclFileC";
  fileIdNames[Rep.modHeaderFileC] := "HeaderFileC";
  fileIdNames[Rep.modInterfaceDescr] := "InterfaceDescr";
  fileIdNames[Rep.modInterfaceXML] := "InterfaceXML";
  fileIdNames[Rep.modInterfaceHTML] := "InterfaceHTML";
  fileIdNames[Rep.modSymbolFile] := "SymbolFile";
  fileIdNames[Rep.modSymbolTableXML] := "SymbolTableXML";
  fileIdNames[Rep.modAssemblerFile] := "AssemblerFile";
  fileIdNames[Rep.modMainFileAssembler] := "MainFileAssembler";
  
  NEW (makeContext);
  Error.InitContext (makeContext, "OOC:Make");
END OOC:Make.
