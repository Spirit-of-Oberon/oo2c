(* 	$Id$	 *)
MODULE OOC:Repository:GetImports;
(*  Determine the list of modules imported by a given module.
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
  Msg, URI, OOC:Config, Rep := OOC:Repository, OOC:SymbolTable:Builder,
  
  OOC:Error, OOC:Scanner:InputBuffer, 
  OOC:Scanner, OOC:Scanner:Builder:BasicList,
  OOC:Parser, OOC:AST, OOC:AST:ExtTree, Sym := OOC:SymbolTable;
  


CONST
  noSuchModule = 1;
  
TYPE
  ErrorContext = POINTER TO ErrorContextDesc;
  ErrorContextDesc = RECORD  (* stateless *)
    (Error.ContextDesc)
  END;

VAR
  getImportsContext: ErrorContext;

PROCEDURE (context: ErrorContext) GetTemplate* (msg: Error.Msg; VAR templ: Error.LString);
  VAR
    t: ARRAY 128 OF Error.LChar;
  BEGIN
    CASE msg. code OF
    | noSuchModule:
      t := "Cannot locate module `${name}'"
    END;
    context. BaseTemplate (msg, t, templ)
  END GetTemplate;



PROCEDURE GetImports* (m: Rep.Module; VAR errList: Error.List);
  VAR
    res: Msg.Msg;
    inputBuffer: InputBuffer.Buffer;
    scannerBuilder: BasicList.Builder;
    astBuilder: ExtTree.Builder;
    ast: AST.Node;
    uri: URI.URI;
    uriStr: Rep.URIBuffer;
    item: Sym.Item;
    import: Rep.Module;
  
  PROCEDURE StoreImports (m: Rep.Module; imports: AST.NodeList);
    VAR
      i: LONGINT;
      import: Rep.Module;
      
    PROCEDURE Err (code: Error.Code; sym: BasicList.Symbol);
      VAR
        lastError: Error.Msg;
      BEGIN
        lastError := Error.New (getImportsContext, code);
        lastError. SetIntAttrib ("pos", sym. pos);
        lastError. SetIntAttrib ("line", sym. line);
        lastError. SetIntAttrib ("column", sym. column);
        errList. Append (lastError)
      END Err;

    BEGIN
      i := 0;
      WHILE (i < imports. len) DO
        import := Config.repositories. GetModule (imports. n[i](ExtTree.ImportDecl). moduleName^);
        IF (import = NIL) THEN
          Err (noSuchModule,
               imports. n[i](ExtTree.ImportDecl). module. 
                 nameList. n[0](ExtTree.Terminal). sym)
        ELSE
          m. AddImport (import)
        END;
        INC (i, 2)
      END
    END StoreImports;

  PROCEDURE AppendRuntimeModules;
    VAR
      a, e: LONGINT;
      rtModule: Rep.Module;
    BEGIN
      IF Builder.doAutoImport THEN
        FOR a := 0 TO LEN(Builder.autoImport^)-1 DO
          e := LEN(Builder.autoImport[a].exclude^)-1;
          WHILE (e >= 0) &
                (Builder.autoImport[a].exclude[e]^ # m.name^) DO
            DEC (e);
          END;
          IF (e < 0) THEN (* this module doesn't appear in exclusion list *)
            rtModule := Config.repositories.GetModule (Builder.autoImport[a].module^);
            IF (rtModule # NIL) THEN
              (* in a standard environment, this file should always exist *)
              m. AddImport (rtModule);
            END;
          END;
        END;
      END;
    END AppendRuntimeModules;
  
  BEGIN
    IF m. importListScanned THEN         (* imports are already known *)
      RETURN
          
    ELSIF (m. symbolTable # NIL) THEN    (* take imports from symbol file *)
      (* FIXME... check if there is a situation where we must ignore
         the contents of the symbol file *)
      item := m. symbolTable. nestedItems;
      WHILE (item # NIL) DO
        WITH item: Sym.Import DO
          IF ~item. IsInternalImport() THEN
            import := Config.repositories. GetModule (item. moduleName. str^);
            ASSERT (import # NIL);
            m. AddImport (import);
          END;
        ELSE                             (* ignore *)
        END;
        item := item. nextNested
      END;
      AppendRuntimeModules;
      m. AddImport (NIL)  (* mark module with "import scanned" *)
    ELSE                                 (* take imports from source file *)
      
      inputBuffer := m. GetInputBuffer (res);
      IF (inputBuffer = NIL) THEN
        ast := NIL;
        uri := m. GetURI (Rep.modModuleSource);
        uri. GetString (uriStr);
        errList := Error.NewList (uriStr);
        errList. Append (res)
      ELSE
        errList := inputBuffer. errList;
        scannerBuilder := BasicList.New (inputBuffer, TRUE);
        Scanner.ScanInput (scannerBuilder, Config.pragmas, Scanner.enableAll);
        inputBuffer. Close;
        
        ast := NIL;
        IF (errList. msgCount = 0) THEN
          astBuilder := ExtTree.New();
          ast := Parser.Module (scannerBuilder. head, 
                                astBuilder, errList,
                                Parser.enableAll+{Parser.onlyParseImport})
        END;
        IF (errList. msgCount = 0) &
           (ast(ExtTree.Module). importList # NIL) THEN
          StoreImports (m, ast(ExtTree.Module).
                        importList(ExtTree.ImportList). imports);
        END;
        AppendRuntimeModules;
        m. AddImport (NIL)  (* mark module with "import scanned" *)
      END
    END;
  END GetImports;

BEGIN
  NEW (getImportsContext);
  Error.InitContext (getImportsContext, "OOC:Repository:GetImports")
END OOC:Repository:GetImports.
