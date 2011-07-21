(* 	$Id: GetModuleClass.Mod,v 1.3 2003/04/16 10:32:36 mva Exp $	 *)
MODULE OOC:Repository:GetModuleClass;
(*  Determine the list of modules imported by a given module.
    Copyright (C) 2002  Michael van Acken

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
  Msg,
  OOC:Config, Rep := OOC:Repository, OOC:Error, OOC:Scanner:InputBuffer, 
  OOC:Scanner, OOC:Scanner:BasicList,
  OOC:Parser, OOC:AST, OOC:AST:ExtTree, Sym := OOC:SymbolTable;
  


PROCEDURE GetModuleClass* (m: Rep.Module): Sym.ModuleClass;
  VAR
    res: Msg.Msg;
    inputBuffer: InputBuffer.Buffer;
    scannerBuilder: BasicList.Builder;
    astBuilder: ExtTree.Builder;
    ast: AST.Node;
    errList: Error.List;
    external: ExtTree.Terminal;
  BEGIN
    inputBuffer := m. GetInputBuffer (res);
    IF (inputBuffer # NIL) THEN
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
      IF (errList. msgCount = 0) & (ast(ExtTree.Module). flags # NIL) THEN
        external := ast(ExtTree.Module). flags. flagList(ExtTree.NodeList).
            n[0](ExtTree.ModuleFlags). external;
        IF (external. sym. str^ = "INTERFACE") THEN
          RETURN Sym.mcInterface;
        ELSIF (external. sym. str^ = "FOREIGN") THEN
          RETURN Sym.mcForeign;
        END;
      END;
    END;
    RETURN Sym.mcStandard;
  END GetModuleClass;

END OOC:Repository:GetModuleClass.
