(* 	$Id$	 *)
MODULE OOC:Make:LinkProgramC;
(*  Links object files and libraries to create an executable file.
    Copyright (C) 2001, 2002  Michael van Acken

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
  Out, Strings, URI, URI:Scheme:File, ADT:Object, ADT:String, ADT:Dictionary,
  ADT:ArrayList, Config:Value, StringValue := Config:Value:String,
  OS:ProcessManagement, OOC:Error, OOC:Repository, OOC:Config,
  OOC:Config:CCompiler, Sym := OOC:SymbolTable;

VAR
  empty, space: String.String;
  
PROCEDURE GetExternalLibs (moduleList: ARRAY OF Repository.Module;
                           thisLibrary: String.String): String.StringArrayPtr;
  VAR
    i, j: LONGINT;
    linkDirective: Sym.LinkDirective;
    libDeps, visited: Dictionary.Dictionary;
    depArray: ArrayList.ArrayList;
    extLibs: String.StringArrayPtr;
    option: Dictionary.Dictionary;
    prev, new: String.String;

  PROCEDURE GetDepArray (libName: String.String): ArrayList.ArrayList;
    VAR
      obj: Object.Object;
      list: ArrayList.ArrayList;
    BEGIN
      IF libDeps.HasKey(libName) THEN
        obj := libDeps.Get(libName);
        RETURN obj(ArrayList.ArrayList);
      ELSE
        list := ArrayList.New(4);
        libDeps.Set(libName, list);
        RETURN list;
      END;
    END GetDepArray;

  PROCEDURE AddLibrary (libName: String.String; VAR pos: LONGINT);
    VAR
      depArray: ArrayList.ArrayList;
      i: LONGINT;
      obj: Object.Object;
    BEGIN
      IF ~visited.HasKey(libName) & libDeps.HasKey(libName) THEN
        visited.Set(libName, NIL);
        depArray := GetDepArray(libName);
        FOR i := 0 TO depArray.size-1 DO
          AddLibrary(depArray.array[i](String.String), pos);
        END;
        obj := option.Get(libName);
        extLibs[pos] := obj(String.String);
        INC (pos);
      END;
    END AddLibrary;

  PROCEDURE IncludeModule(module: Repository.Module): BOOLEAN;
    BEGIN
      RETURN (module.ifData.libraryName = NIL) OR
          module.ifData.libraryName.Equals(thisLibrary);
    END IncludeModule;

  PROCEDURE Option(libraryName: String.String): String.String;
    VAR
      obj: Object.Object;
      str: String.String;
    BEGIN
      IF option.HasKey(libraryName) THEN
        obj := option.Get(libraryName);
        RETURN obj(String.String);
      ELSE
        str := String.New("-l");
        str := str.Concat(libraryName);
        option.Set(libraryName, str);
        RETURN str;
      END;
    END Option;

  PROCEDURE LookupValue(optionName: String.String): String.String;
    VAR
      v: Value.Value;
    BEGIN
      v := Config.options.GetValue(optionName.array^);
      IF (v # NIL) & (v IS StringValue.Value) THEN
        RETURN String.New(v(StringValue.Value).string^);
      ELSE
        RETURN empty;
      END;
    END LookupValue;
  
  BEGIN
    (* In the a first pass over all object files, pick up any references
       to external libraries.  Ignore any modules that have been put into
       libraries themselves.  *)
    libDeps := Dictionary.New();
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
            IF (linkDirective.prefixOption # NIL) THEN
              prev := space.Concat(Option(linkDirective.libraryName));
              new := LookupValue(linkDirective.prefixOption);
              option.Set(linkDirective.libraryName, new.Concat(prev));
            END;
            IF (linkDirective.suffixOption # NIL) THEN
              prev := Option(linkDirective.libraryName);
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
               forLibrary: String.String): BOOLEAN;
  VAR
    str: ARRAY 16*1024 OF CHAR;        (* link commands can get _very_ long *)
    path: Repository.URIBuffer;
    uri: URI.URI;
    exit, i: LONGINT;
    res: Error.Msg;
    importedLibs: Dictionary.Dictionary;
    importedLibsList: ArrayList.ArrayList;
    objectFile, outputFile: Repository.FileId;
    libraryName: String.String;
    import: Repository.Module;
    extLibs: String.StringArrayPtr;
  BEGIN
    exit := 0;
    IF (forLibrary # NIL) THEN
      objectFile := Repository.modObjectFileLib;
      outputFile := Repository.modLibrary;
    ELSE
      objectFile := Repository.modObjectFile;
      outputFile := Repository.modExecutable;
    END;
    
    module. CreateOutputDir (outputFile, res);
    IF (res = NIL) THEN
      CCompiler.LinkProgramCmd
          (module. GetURI (outputFile, TRUE), (forLibrary # NIL), str);

      importedLibs := Dictionary.New();
      importedLibsList := ArrayList.New(4);
      FOR i := 0 TO LEN(imports)-1 DO
        ASSERT(imports[i].ifQuality = Repository.completeInterface);
        libraryName := imports[i].ifData.libraryName;
        IF (libraryName # NIL) & ~libraryName.Equals(forLibrary) THEN
          (* object file is part of a library; for each library encountered
             this way, keep track of one module that it provides *)
          IF ~importedLibs.HasKey(libraryName) THEN
            importedLibs.Set(imports[i].ifData.libraryName, NIL);
            importedLibsList.Append(imports[i]);
          END;
        ELSE
          uri := imports[i]. GetURI (objectFile, TRUE);
          uri(File.URI). GetPath (path);
          Strings.Append (" ", str);
          Strings.Append (path, str);
        END;
      END;

      IF (forLibrary = NIL) THEN
        (* add file with function main() *)
        uri := module. GetURI (Repository.modMainObjectFile, TRUE);
        uri(File.URI). GetPath (path);
        Strings.Append (" ", str);
        Strings.Append (path, str);
      END;

      FOR i := 0 TO importedLibsList.size-1 DO
        import := importedLibsList.array[i](Repository.Module);
        IF import.FileExists(Repository.modLibrary) THEN
          (* looks like an uninstalled library *)
          uri := import.GetURI(Repository.modLibrary, TRUE);
          uri(File.URI). GetPath (path);
          Strings.Append (" ", str);
          Strings.Append (path, str);
        ELSE
          (* we don't have a .la file, so assume that it's a regularly
             installed libtool library  *)
          Strings.Append(" -l", str);
          Strings.Append(import.ifData.libraryName.array^, str);
        END;
      END;
      
      (* add "-l" options for the external libraries, most specific library
         first *)
      extLibs := GetExternalLibs(imports, forLibrary);
      FOR i := LEN (extLibs^)-1 TO 0 BY -1 DO
        Strings.Append (extLibs[i]. array^, str);
      END;
      Strings.Append (" ", str);
      Strings.Append (CCompiler.libs.value(StringValue.Value).string^, str);
    END;
    IF (res = NIL) THEN
      Out.String (str);
      Out.Ln;
      exit := ProcessManagement.system (str)
    END;
    
    RETURN (res = NIL) & (exit = 0)
  END Run;

BEGIN
  empty := String.New("");
  space := String.New(" ");
END OOC:Make:LinkProgramC.
