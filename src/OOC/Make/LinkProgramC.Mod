(* 	$Id: LinkProgramC.Mod,v 1.27 2003/10/16 20:33:36 mva Exp $	 *)
MODULE OOC:Make:LinkProgramC;
(*  Links object files and libraries to create an executable file.
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
  Out, IO, URI, URI:Scheme:File, Object, ADT:Dictionary,
  ADT:ArrayList, ADT:StringBuffer, CfgData := Config,
  OS:ProcessManagement, OOC:Repository, OOC:Config,
  OOC:Config:CCompiler, Sym := OOC:SymbolTable;

VAR
  empty, space: STRING;
  
PROCEDURE GetExternalLibs (moduleList: ARRAY OF Repository.Module;
                           thisLibrary: STRING): Object.StringArrayPtr;
  VAR
    i, j: LONGINT;
    linkDirective: Sym.LinkDirective;
    libDeps: Dictionary.Dictionary(STRING, ArrayList.ArrayList);
    visited: Dictionary.Dictionary;
    depArray: ArrayList.ArrayList;
    extLibs: Object.StringArrayPtr;
    option: Dictionary.Dictionary;
    prev, new: STRING;

  PROCEDURE GetDepArray (libName: STRING): ArrayList.ArrayList;
    VAR
      list: ArrayList.ArrayList;
    BEGIN
      IF libDeps.HasKey(libName) THEN
        RETURN libDeps.Get(libName);
      ELSE
        list := ArrayList.New(4);
        libDeps.Set(libName, list);
        RETURN list;
      END;
    END GetDepArray;

  PROCEDURE AddLibrary (libName: STRING; VAR pos: LONGINT);
    VAR
      depArray: ArrayList.ArrayList;
      i: LONGINT;
      obj: Object.Object;
    BEGIN
      IF ~visited.HasKey(libName) & libDeps.HasKey(libName) THEN
        visited.Set(libName, NIL);
        depArray := GetDepArray(libName);
        FOR i := 0 TO depArray.size-1 DO
          AddLibrary(depArray.array[i](Object.String), pos);
        END;
        obj := option.Get(libName);
        extLibs[pos] := obj(STRING);
        INC (pos);
      END;
    END AddLibrary;

  PROCEDURE IncludeModule(module: Repository.Module): BOOLEAN;
    BEGIN
      RETURN (module.ifData.libraryName = NIL) OR
          module.ifData.libraryName.Equals(thisLibrary);
    END IncludeModule;

  PROCEDURE Option(lib: Sym.LinkLib): STRING;
    VAR
      obj: Object.Object;
      str: STRING;
    BEGIN
      IF option.HasKey(lib.libraryName) THEN
        obj := option.Get(lib.libraryName);
        RETURN obj(STRING);
      ELSE
        CASE lib.type OF
        | Sym.libTypeStandard:
          str := " -l"+lib.libraryName;
        | Sym.libTypeFramework:
          str := " -framework "+lib.libraryName;
        END;
        option.Set(lib.libraryName, str);
        RETURN str;
      END;
    END Option;

  PROCEDURE LookupValue(optionName: STRING): STRING;
    VAR
      v: CfgData.Variable;
    BEGIN
      v := Config.options.GetValue(optionName);
      IF (v # NIL) & (v IS CfgData.StringVar) THEN
        RETURN v(CfgData.StringVar).string;
      ELSE
        RETURN empty;
      END;
    END LookupValue;
  
  BEGIN
    (* In the a first pass over all object files, pick up any references
       to external libraries.  Ignore any modules that have been put into
       libraries themselves.  *)
    NEW(libDeps);
    libDeps.INIT();
    option := Dictionary.New();
    FOR i := 0 TO LEN(moduleList)-1 DO
      IF IncludeModule(moduleList[i]) THEN
        (* note down any libraries that need to be linked in *)
        linkDirective := moduleList[i].ifData.linkDirectives;
        WHILE (linkDirective # NIL) DO
          WITH linkDirective: Sym.LinkLib DO
            depArray := GetDepArray(linkDirective.libraryName);
            FOR j := 0 TO LEN(linkDirective.dependencies^)-1 DO
              depArray.Append(linkDirective.dependencies[j]);
            END;
            prev := Option(linkDirective);
            IF (linkDirective.prefixOption # NIL) THEN
              new := space.Concat(LookupValue(linkDirective.prefixOption));
              option.Set(linkDirective.libraryName, new.Concat(prev));
              prev := Option(linkDirective); (* refresh *)
            END;
            IF (linkDirective.suffixOption # NIL) THEN
              new := space.Concat(LookupValue(linkDirective.suffixOption));
              option.Set(linkDirective.libraryName, prev.Concat(new));
            END;
          ELSE                         (* ignore *)
          END;
          linkDirective := linkDirective. next
        END;
      END;
    END;

    (* Pick up library references, starting at the module at the bottom and
       ending with the main module.  Ignore module from libraries.  Honor
       library interdependencies by putting base libraries first.  *)
    NEW(extLibs, libDeps.Size());
    visited := Dictionary.New();
    j := 0;
    FOR i := 0 TO LEN(moduleList)-1 DO
      IF IncludeModule(moduleList[i]) THEN
        (* note down any libraries that need to be linked in *)
        linkDirective := moduleList[i].ifData.linkDirectives;
        WHILE (linkDirective # NIL) DO
          WITH linkDirective: Sym.LinkLib DO
            AddLibrary(linkDirective.libraryName, j);
          ELSE                         (* ignore *)
          END;
          linkDirective := linkDirective. next
        END;
      END;
    END;
    ASSERT(j = LEN(extLibs^));
    RETURN extLibs;
  END GetExternalLibs;

PROCEDURE Run*(module: Repository.Module;
               imports: ARRAY OF Repository.Module;
               forLibrary: STRING): BOOLEAN
RAISES IO.Error;
  VAR
    sb: StringBuffer.StringBuffer;
    cmd: STRING;
    uri: URI.URI;
    exit, i: LONGINT;
    importedLibs: Dictionary.Dictionary;
    importedLibsList: ArrayList.ArrayList;
    objectFile, outputFile: Repository.FileId;
    libraryName: STRING;
    import: Repository.Module;
    extLibs: Object.StringArrayPtr;
  BEGIN
    exit := 0;
    IF (forLibrary # NIL) THEN
      objectFile := Repository.modObjectFileLib;
      outputFile := Repository.modLibrary;
    ELSE
      objectFile := Repository.modObjectFile;
      outputFile := Repository.modExecutable;
    END;
    
    module. CreateOutputDir (outputFile);
    sb := StringBuffer.New(CCompiler.LinkProgramCmd
                           (module. GetURI (outputFile, TRUE),
                            (forLibrary # NIL)));

    importedLibs := Dictionary.New();
    importedLibsList := ArrayList.New(4);
    FOR i := 0 TO LEN(imports)-1 DO
      ASSERT(imports[i].ifQuality = Repository.completeInterface);
      libraryName := imports[i].ifData.libraryName;
      IF (libraryName # NIL) & ~libraryName.Equals(forLibrary) THEN
        (* object file is part of a library; for each library encountered
           this way, keep track of one module that it provides *)
        IF ~importedLibs.HasKey(libraryName) THEN
          importedLibs.Set(libraryName, NIL);
          importedLibsList.Append(imports[i]);
        END;
      ELSIF ~imports[i].ifData.NoObjectFile() THEN
        uri := imports[i]. GetURI (objectFile, TRUE);
        sb.Append(" ");
        sb.Append(uri(File.URI).GetPath());
      END;
    END;

    IF (forLibrary = NIL) THEN
      (* add file with function main() *)
      uri := module. GetURI (Repository.modMainObjectFile, TRUE);
      sb.Append(" ");
      sb.Append(uri(File.URI).GetPath());
    END;

    FOR i := 0 TO importedLibsList.size-1 DO
      import := importedLibsList.array[i](Repository.Module);
      IF import.FileExists(Repository.modLibrary) THEN
        (* looks like an uninstalled library *)
        uri := import.GetURI(Repository.modLibrary, TRUE);
        sb.Append(" ");
        sb.Append(uri(File.URI).GetPath());
      ELSE
        (* we don't have a .la file, so assume that it's a regularly
           installed libtool library  *)
        sb.Append(" -l");
        sb.Append(import.ifData.libraryName);
      END;
    END;
    
    (* add "-l" options for the external libraries, most specific library
       first *)
    extLibs := GetExternalLibs(imports, forLibrary);
    FOR i := LEN (extLibs^)-1 TO 0 BY -1 DO
      sb.Append(extLibs[i]);
    END;
    sb.Append(" ");
    sb.Append(CCompiler.libs.value);

    cmd := sb.ToString();
    Out.Object(cmd);
    Out.Ln;
    exit := ProcessManagement.system(cmd);
    RETURN (exit = 0)
  END Run;

BEGIN
  empty := Object.emptyString;
  space := " ";
END OOC:Make:LinkProgramC.
