(* 	$Id: TranslateToX86.Mod,v 1.2 2004/06/03 22:26:32 mva Exp $	 *)
MODULE OOC:Make:TranslateToX86;
(*  Translates a module file into an x86 assembler file.
    Copyright (C) 2004  Michael van Acken

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
  IO, IO:StdChannels,
  OOC:Config:Pragmas, OOC:Auxiliary:ParseModule,
  OOC:Auxiliary:WriteSymbolFile, OOC:Error, Rep := OOC:Repository, OOC:AST,
  OOC:AST:CreateIR, ASTtoXML := OOC:AST:XML, 
  OOC:IR, IRtoXML := OOC:IR:XML, OOC:IR:ConstFold, OOC:IR:CheckUses,
  Sym := OOC:SymbolTable, OOC:SymbolTable:Exports, OOC:SymbolTable:Uses,
  OOC:X86:Translate;

PROCEDURE Run*(m: Rep.Module; libraryName: STRING;
               analysisOnly: BOOLEAN; uses: Uses.Uses;
               writeAST: BOOLEAN; writeIR: BOOLEAN): Error.List
RAISES IO.Error;
(**Compiles a module, creating the symbol file and all relevant C files.  *)
  VAR
    ast: AST.Node;
    symTab: Sym.Module;
    errList: Error.List;
    exports: Sym.Exports;
    module: IR.Module;
    pragmaHistory: Pragmas.History;
    ch: IO.ByteChannel;
  BEGIN
    ParseModule.ParseModule (m, TRUE, TRUE, FALSE, FALSE, libraryName, uses,
                             ast, symTab, pragmaHistory, errList);
    (* note: don't let `ParseModule' write the symbol file; this reduces the
       data in `symTab' to the view of client modules: declarations private to
       the module are stripped when writing the symbol file  *)
    
    IF errList.NoErrors() THEN
      IF writeAST THEN
        ASTtoXML.Write (StdChannels.stdout, ast(AST.Module));
      END;
      module := CreateIR.CreateIR (ast(AST.Module), symTab, 
                                   IR.NewBuilder (symTab, uses, pragmaHistory,
                                                  errList, 
                                                  ConstFold.NewConstFold()));
      IF errList.NoErrors() THEN
        CheckUses.CheckUses(module, symTab, pragmaHistory, errList);
      END;
      
      IF writeIR THEN
        IRtoXML.Write (StdChannels.stdout, module);
      END;
      
      exports := Exports.GetExports (symTab, TRUE);
      
      IF errList.NoErrors() & ~analysisOnly THEN
        (* only attempt to produce output if program compiled without errors *)
        ch := m.GetOutputChannel(Rep.modAssemblerFile, TRUE);
        Translate.Translate(m, symTab, module, ch);

        IF errList.NoErrors() THEN
          WriteSymbolFile.WriteSymbolFile (m, symTab, errList);
        END;
        
        ch.CloseAndRegister();
      END;
      module.Destroy;                    (* cleanup for the sake of the gc *)
    END;
    
    RETURN errList;
  END Run;

END OOC:Make:TranslateToX86.
