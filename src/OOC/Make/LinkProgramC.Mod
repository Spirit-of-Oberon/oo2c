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
  OS:ProcessManagement, OOC:Error, OOC:Repository, OOC:Config:CCompiler,
  Sym := OOC:SymbolTable;

PROCEDURE Run*(module: Repository.Module;
               imports: ARRAY OF Repository.Module;
               forLibrary: BOOLEAN): BOOLEAN;
  VAR
    str: ARRAY 16*1024 OF CHAR;        (* link commands can get _very_ long *)
    path: Repository.URIBuffer;
    uri: URI.URI;
    exit, i: LONGINT;
    res: Error.Msg;
    linkDirective: Sym.LinkDirective;
    libsMap: Dictionary.Dictionary;
    libs: Object.ObjectArrayPtr;
    objectFile, outputFile: Repository.FileId;
  BEGIN
    exit := 0;
    IF forLibrary THEN
      objectFile := Repository.modObjectFileLib;
      outputFile := Repository.modLibrary;
    ELSE
      objectFile := Repository.modObjectFile;
      outputFile := Repository.modExecutable;
    END;
    
    module. CreateOutputDir (outputFile, res);
    IF (res = NIL) THEN
      CCompiler.LinkProgramCmd
          (module. GetURI (outputFile), forLibrary, str);

      libsMap := Dictionary.New();
      FOR i := 0 TO LEN(imports)-1 DO
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

      IF ~forLibrary THEN
        (* add file with function main() *)
        uri := module. GetURI (Repository.modMainObjectFile);
        uri(File.URI). GetPath (path);
        Strings.Append (" ", str);
        Strings.Append (path, str);
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

