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
  ADT:ArrayList,
  OS:ProcessManagement, OOC:Error, OOC:Repository, OOC:Config:CCompiler,
  Sym := OOC:SymbolTable;

PROCEDURE Run*(module: Repository.Module;
               imports: ARRAY OF Repository.Module;
               forLibrary: String.String): BOOLEAN;
  VAR
    str: ARRAY 16*1024 OF CHAR;        (* link commands can get _very_ long *)
    path: Repository.URIBuffer;
    uri: URI.URI;
    exit, i: LONGINT;
    res: Error.Msg;
    linkDirective: Sym.LinkDirective;
    libsMap, importedLibs: Dictionary.Dictionary;
    importedLibsList: ArrayList.ArrayList;
    libs: Object.ObjectArrayPtr;
    objectFile, outputFile: Repository.FileId;
    libraryName: String.String;
    import: Repository.Module;
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
          (module. GetURI (outputFile), (forLibrary # NIL), str);

      libsMap := Dictionary.New();
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
          uri := imports[i]. GetURI (objectFile);
          uri(File.URI). GetPath (path);
          Strings.Append (" ", str);
          Strings.Append (path, str);
          
          (* note down any libraries that need to be linked in *)
          linkDirective := imports[i].ifData.linkDirectives;
          WHILE (linkDirective # NIL) DO
            WITH linkDirective: Sym.LinkLib DO
              libsMap. Set (linkDirective. libraryName, NIL);
            ELSE                         (* ignore *)
            END;
            linkDirective := linkDirective. next
          END;
        END;
      END;

      IF (forLibrary = NIL) THEN
        (* add file with function main() *)
        uri := module. GetURI (Repository.modMainObjectFile);
        uri(File.URI). GetPath (path);
        Strings.Append (" ", str);
        Strings.Append (path, str);
      END;

      FOR i := 0 TO importedLibsList.size-1 DO
        import := importedLibsList.array[i](Repository.Module);
        IF import.FileExists(Repository.modLibrary) THEN
          (* looks like an uninstalled library *)
          uri := import.GetURI(Repository.modLibrary);
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
      
      (* add "-l" options for the external libraries *)
      (* FIXME... honor interdependencies between libraries in order
         of options *)
      libs := libsMap. Keys();
      FOR i := 0 TO LEN (libs^)-1 DO
        Strings.Append (" -l", str);
        Strings.Append (libs[i](String.String). array^, str);
      END;
    END;
    IF (res = NIL) THEN
      Out.String (str);
      Out.Ln;
      exit := ProcessManagement.system (str)
    END;
    
    RETURN (res = NIL) & (exit = 0)
  END Run;

END OOC:Make:LinkProgramC.

