(* 	$Id$	 *)
MODULE OOC:SymbolTable:ImportModules;
(*  Retrieve exported symbol data for imported modules.
    Copyright (C) 2000, 2001, 2002  Michael van Acken

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
  Msg, OOC:Config, OOC:Error, Sym := OOC:SymbolTable, OOC:Repository;


CONST
  noSuchModule = 1;
  readErrorSymbolFile = 2;
  
TYPE
  ErrorContext = POINTER TO ErrorContextDesc;
  ErrorContextDesc = RECORD  (* stateless *)
    (Error.ContextDesc)
  END;

VAR
  importModulesContext: ErrorContext;


PROCEDURE (context: ErrorContext) GetTemplate* (msg: Error.Msg; VAR templ: Error.LString);
  VAR
    t: ARRAY 128 OF Error.LChar;
  BEGIN
    CASE msg. code OF
    | noSuchModule:
      t := "Cannot locate module `${name}'"
    | readErrorSymbolFile:
      t := "Failed to read symbol file: ${reason}"
    END;
    context. BaseTemplate (msg, t, templ)
  END GetTemplate;


PROCEDURE ImportModules* (systemModule: Sym.Module;
                          symTab: Sym.Module;
                          errList: Error.List);
  VAR
    ptr: Sym.Item;
    lastError: Error.Msg;
    
  PROCEDURE Err (code: Error.Code; name: Sym.Name);
    BEGIN
      lastError := Error.New (importModulesContext, code);
      lastError. SetIntAttrib ("pos", name. pos);
      lastError. SetIntAttrib ("line", name. line);
      lastError. SetIntAttrib ("column", name. column);
      lastError. SetStringAttrib ("name", Msg.GetStringPtr (name. str^));
      errList. Append (lastError)
    END Err;
  
  PROCEDURE ReadSymbolFile (import: Sym.Import);
    VAR
      m: Repository.Module;
      res: Msg.Msg;
    BEGIN
      IF import. IsInternalImport() THEN
        import. SetExternalSymTab (systemModule)
      ELSE
        m := Config.repositories. GetModule (import. moduleName. str^);
        IF (m = NIL) THEN
          Err (noSuchModule, import. moduleName)
        ELSE
          symTab := m. ReadSymbolFile (res);
          IF (res # NIL) THEN
            Err (readErrorSymbolFile, import. moduleName);
            lastError. SetMsgAttrib ("reason", res)
          ELSE
            (* when we reach this point, then the imported modules have
               been processed one way or other, and we must make sure that
               we only see exactly this processed data further on *)
            m.SetInterfaceData(symTab, Repository.completeInterface);
            m.SetFingerprint(symTab.fingerprint);
            import. SetExternalSymTab (symTab)
          END
        END
      END
    END ReadSymbolFile;
  
  BEGIN
    lastError := NIL;
    ptr := symTab. nestedItems;
    WHILE (ptr # NIL) DO
      WITH ptr: Sym.Import DO
        ReadSymbolFile (ptr)
      ELSE
      END;
      ptr := ptr. nextNested
    END
  END ImportModules;

BEGIN
  NEW (importModulesContext);
  Error.InitContext (importModulesContext, "OOC:SymbolTable:ImportModules")
END OOC:SymbolTable:ImportModules.
