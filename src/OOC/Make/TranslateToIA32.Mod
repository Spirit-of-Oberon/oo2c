(* 	$Id: TranslateToIA32.Mod,v 1.14 2003/08/26 14:05:21 mva Exp $	 *)
MODULE OOC:Make:TranslateToIA32 [OOC_EXTENSIONS];
(*  Translates a module file into a bunch of C code files.
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
  Ascii, IO, IO:StdChannels,
  OOC:Config:Pragmas, OOC:Auxiliary:ParseModule,
  OOC:Auxiliary:WriteSymbolFile, OOC:Error, Rep := OOC:Repository,
  OOC:AST, OOC:AST:CreateIR, ASTtoXML := OOC:AST:XML, 
  OOC:IR, IRtoXML := OOC:IR:XML, OOC:IR:ConstFold,
  Sym := OOC:SymbolTable, OOC:SymbolTable:Exports, OOC:SymbolTable:Uses,
  OOC:IA32:Writer, OOC:IA32:RuntimeData;

TYPE
  Translator* = POINTER TO TranslatorDesc;
  TranslatorDesc* = RECORD [ABSTRACT]
    w-: Writer.Writer;

    module-: Rep.Module;
    symTab-: Sym.Module;
    
    procList: IR.ProcedureList;
    (* List of all procedures in this module.  *)
    
    currentProc: LONGINT;
    (* Index of the most recent call to @oproc{Translator.WriteProcedure}.
       This method restores it to its old value when it is done, which means it
       is aware of procedure nesting.  *)
  END;


PROCEDURE InitTranslator* (t: Translator; module: Rep.Module);
  BEGIN
    t. w := NIL;
    t. procList := NIL;
    t. currentProc := -1;
    t. module := module;
    t. symTab := NIL;
  END InitTranslator;

PROCEDURE (t: Translator) SetWriter* (w: Writer.Writer; symTab: Sym.Module);
  BEGIN
    t. w := w;
    t. symTab := symTab;
  END SetWriter;

PROCEDURE (t: Translator) SetProcedureList* (procList: IR.ProcedureList);
  BEGIN
    t. procList := procList;
  END SetProcedureList;

PROCEDURE (t: Translator) [ABSTRACT] WriteProcBody* (proc: IR.Procedure);
  END WriteProcBody;

PROCEDURE (t: Translator) WriteProcedure (procIndex: LONGINT);
  VAR
    oldProcIndex: LONGINT;
  BEGIN
    oldProcIndex := t. currentProc;
    t. currentProc := procIndex;
    
    t. WriteProcBody (t. procList[procIndex]);
    
    t. currentProc := oldProcIndex;
  END WriteProcedure;

PROCEDURE (t: Translator) WriteNestedProcedures*;
(**The implementation of @oproc{Translator.WriteProcBody} may call this
   procedure to write out all procedures that are nested into the procedure for
   which it was called.  The translator instance keeps track of which procedure
   that was, and which of the other procedures are part of it.

   Note: ANSI-C does not support nested functions.  This is a feature of gcc.  *)
  VAR
    currentDecl: Sym.ProcDecl;
    i: LONGINT;
  BEGIN
    IF (t. currentProc >= 0) THEN (* not writing the module pseudo procedure *)
      currentDecl := t. procList[t. currentProc]. decl;
      i := t. currentProc+1;
      WHILE (i # LEN (t. procList^)) DO
        IF (t. procList[i]. decl. parent = currentDecl) THEN
          t. w. Newline;
          t. WriteProcedure (i);
        END;
        INC (i);
      END;
    END;
  END WriteNestedProcedures;


PROCEDURE WriteCodeFile (w: Writer.Writer; m: Rep.Module; symTab: Sym.Module;
                         moduleIR: IR.Module; translator: Translator);
  VAR
    i: LONGINT;
  BEGIN
    translator. SetWriter (w, symTab);

    w. Section (".text");
    w. Label (".Ltext0");
    RuntimeData.Write (w, symTab);
                       
    w. Section (".text");
    translator. SetProcedureList (moduleIR. procList);
    FOR i := 0 TO LEN (moduleIR. procList^)-1 DO
      IF (moduleIR. procList[i]. decl. parent IS Sym.Module) THEN
        translator. WriteProcedure (i);
      END;
    END;
    translator. WriteProcBody (moduleIR. moduleBody);
    translator. SetProcedureList (NIL);

    w. WriteStringData();
    
    w. Label (".Letext");
    w. Directive (".ident"+Ascii.ht+'"OOC: 0.1"');
  END WriteCodeFile;


PROCEDURE Run*(m: Rep.Module; libraryName: STRING; uses: Uses.Uses;
               writeAST, writeIR: BOOLEAN;
               translator: Translator): Error.List
RAISES IO.Error;
(**Compiles a module, creating the symbol file and the assembler file.  *)
  VAR
    ast: AST.Node;
    symTab: Sym.Module;
    errList: Error.List;
    exports: Sym.Exports;
    moduleIR: IR.Module;
    pragmaHistory: Pragmas.History;
    w: Writer.Writer;

  PROCEDURE CloseFile (w: Writer.Writer) RAISES IO.Error;
    BEGIN
      IF (w # NIL) THEN
        w. Newline;
        w. Close ();
      END;
    END CloseFile;
  
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
      moduleIR := CreateIR.CreateIR (ast(AST.Module), symTab, 
                                     IR.NewBuilder (symTab, uses,
                                                    pragmaHistory, errList,
                                                    ConstFold.NewConstFold()));
      IF writeIR THEN
        IRtoXML.Write (StdChannels.stdout, moduleIR);
      END;
      
      exports := Exports.GetExports (symTab, TRUE);
      
      IF errList.NoErrors() THEN
        (* only attempt to produce output if program compiled without errors *)

        w := Writer.NewWriter
            (m. GetOutputChannel (Rep.modAssemblerFile, TRUE));
        WriteCodeFile (w, m, symTab, moduleIR, translator);
        WriteSymbolFile.WriteSymbolFile (m, symTab, errList);

        (* close all output file after adding a tidbit of text to it;
           this way, these files are as old or more recent than the symbol
           file, and the file depened on the symbol file in the make rules *)
        CloseFile (w);
      END;
    END;
    
    RETURN errList;
  END Run;

END OOC:Make:TranslateToIA32.
