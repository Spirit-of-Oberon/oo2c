(* 	$Id$	 *)
MODULE OOC:Make:TranslateToC [OOC_EXTENSIONS];
(*  Translates a module file into a bunch of C code files.
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
  Channel, Out, StdChannels, ADT:String, ADT:Dictionary, 
  OOC:Config, OOC:Config:Pragmas, OOC:Auxiliary:ParseModule,
  OOC:Auxiliary:WriteSymbolFile, OOC:Error, OOC:Repository, OOC:AST,
  OOC:AST:ExtTree, OOC:AST:ExtTree:CreateIR, ASTtoXML := OOC:AST:ExtTree:XML, 
  OOC:IR, IRtoXML := OOC:IR:XML, OOC:IR:ConstFold,
  Sym := OOC:SymbolTable, OOC:SymbolTable:Exports, 
  OOC:C:DeclWriter, OOC:C:ConvertDecl, OOC:C:RuntimeData;

TYPE
  Translator* = POINTER TO TranslatorDesc;
  TranslatorDesc* = RECORD [ABSTRACT]
    w-: DeclWriter.Writer;

    wd-: DeclWriter.Writer;
    (**Reference to the writer for the @file{.d} file.  It can be used to
       add declarations to the end of the file.  Because this file is
       included at the very beginning of the @file{.c} file, these declarations
       have global visibility.  *)
    
    procList: IR.ProcedureList;
    (* List of all procedures in this module.  *)
    
    currentProc: LONGINT;
    (* Index of the most recent call to @oproc{Translator.WriteProcedure}.
       This method restores it to its old value when it is done, which means it
       is aware of procedure nesting.  *)
  END;

  
PROCEDURE InitTranslator* (t: Translator);
  BEGIN
    t. w := NIL;
    t. wd := NIL;
    t. procList := NIL;
    t. currentProc := -1;
  END InitTranslator;

PROCEDURE (t: Translator) SetWriter* (w: DeclWriter.Writer);
  BEGIN
    t. w := w;
  END SetWriter;

PROCEDURE (t: Translator) SetProcedureList* (procList: IR.ProcedureList);
  BEGIN
    t. procList := procList;
  END SetProcedureList;

PROCEDURE (t: Translator) SetDataWriter* (wd: DeclWriter.Writer);
  BEGIN
    t. wd := wd;
  END SetDataWriter;

PROCEDURE (t: Translator) [ABSTRACT] WriteProcBody* (proc: IR.Procedure);
  END WriteProcBody;

PROCEDURE (t: Translator) WriteProcedure (procIndex: LONGINT);
  VAR
    w: DeclWriter.Writer;
    d: DeclWriter.Declaration;
    oldProcIndex: LONGINT;
  BEGIN
    oldProcIndex := t. currentProc;
    t. currentProc := procIndex;
    
    w := t. w;
    d := ConvertDecl.GetProc (w, t. procList[procIndex]. decl, FALSE);
    w. Newline;
    w. WriteDeclaration (d);
    w. WriteString (" {");
    t. WriteProcBody (t. procList[procIndex]);
    w. Newline;
    w. WriteString ("}");
    w. WriteLn;

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
          t. w. Indent (1);
          t. w. Newline;
          t. WriteProcedure (i);
          t. w. Indent (-1);
        END;
        INC (i);
      END;
    END;
  END WriteNestedProcedures;

PROCEDURE WriteModuleName (w: DeclWriter.Writer; 
                           prefix: ARRAY OF CHAR; module: Repository.Module;
                           suffix: ARRAY OF CHAR; newline: BOOLEAN);
  VAR
    str: ARRAY 1024 OF CHAR;
    i: LONGINT;
  BEGIN
    COPY (module. name^, str);
    i := 0;
    WHILE (str[i] # 0X) DO
      IF (str[i] = ":") THEN str[i] := "_" END;
      INC (i)
    END;
    w. WriteString (prefix);
    w. WriteString (str);
    w. WriteString (suffix);
    IF newline THEN
      w. WriteLn
    END
  END WriteModuleName;

PROCEDURE WriteHeaderFile (w: DeclWriter.Writer; m: Repository.Module;
                           symTab: Sym.Module; exports: Dictionary.Dictionary);
  BEGIN
    WriteModuleName (w, "#ifndef _MODULE_", m, "_", TRUE);
    WriteModuleName (w, "#define _MODULE_", m, "_", TRUE);
    w. WriteLn;
    
    (* __typemap definitions are required to parse definitions of the
       module header file *)
    w. WriteString ('#include "__typemap.h"');
    w. WriteLn;

    (* pull in type definitions for the run-time meta data: module descriptor,
       type descriptor, and so on.  *)
    w. WriteString ('#include "'+Config.runtimeModule+Repository.headerSuffix+'"');
    w. WriteLn;
    
    ConvertDecl.ConvertSymTab (w, m, symTab, exports, TRUE);
    w. WriteDeclarationList;
    RuntimeData.Write (w, symTab, TRUE);
    
    WriteModuleName (w, "#endif /* _MODULE_", m, "_ */", TRUE);
  END WriteHeaderFile;

PROCEDURE WriteDeclFile (w: DeclWriter.Writer; m: Repository.Module;
                         symTab: Sym.Module; exports: Dictionary.Dictionary);
  BEGIN
    w. WriteInclude (m. GetURI (Repository.modHeaderFileC, FALSE));

    ConvertDecl.ConvertSymTab (w, m, symTab, exports, FALSE);
    w. WriteDeclarationList;
    RuntimeData.Write (w, symTab, FALSE);
  END WriteDeclFile;

PROCEDURE WriteCodeFile (w, wd: DeclWriter.Writer; m: Repository.Module;
                         moduleIR: IR.Module; translator: Translator);
  VAR
    i: LONGINT;
  BEGIN
    w. WriteInclude (m. GetURI (Repository.modDeclFileC, FALSE));
    translator. SetWriter (w);
    
    (* include full __oo2c.h only in generated C code files; this way,
       the .h and .d files can be used without pulling in all the 
       declarations of the run-time header file *)
    w. WriteString ('#include "__oo2c.h"');
    w. WriteLn;
    translator. SetDataWriter (wd);
    translator. SetProcedureList (moduleIR. procList);
    FOR i := 0 TO LEN (moduleIR. procList^)-1 DO
      IF (moduleIR. procList[i]. decl. parent IS Sym.Module) THEN
        translator. WriteProcedure (i);
      END;
    END;
    w. WriteLn;
    WriteModuleName (w, "void OOC_", m, "_init(void) {", FALSE);
    translator. WriteProcBody (moduleIR. moduleBody);
    w. WriteLn;
    w. WriteString ("}");
    w. WriteLn;

    translator. SetProcedureList (NIL);
  END WriteCodeFile;


PROCEDURE Run*(m: Repository.Module; libraryName: String.String;
               writeAST: BOOLEAN; writeIR: BOOLEAN;
               translator: Translator): Error.List;
(**Compiles a module, creating the symbol file and all relevant C files.  *)
  VAR
    ast: AST.Node;
    symTab: Sym.Module;
    errList: Error.List;
    exports: Dictionary.Dictionary;
    module: IR.Module;
    pragmaHistory: Pragmas.History;
    wh, wd, wc: DeclWriter.Writer;

  PROCEDURE WriteFile (fileId: Repository.FileId): DeclWriter.Writer;
    VAR
      res: Error.Msg;
      w: DeclWriter.Writer;
    BEGIN
      w := DeclWriter.NewWriter (m. GetOutputChannel (fileId, TRUE, res),
                                 m. GetURI (fileId, FALSE));
      IF (res = Channel.done) THEN
        CASE fileId OF
        | Repository.modHeaderFileC:
          WriteHeaderFile (w, m, symTab, exports);
        | Repository.modDeclFileC:
          WriteDeclFile (w, m, symTab, exports);
        | Repository.modCodeFileC:
          WriteCodeFile (w, wd, m, module, translator);
        END;
        RETURN w
      ELSE
        errList. Append (res);
        RETURN NIL
      END;
    END WriteFile;

  PROCEDURE CloseFile (w: DeclWriter.Writer);
    VAR
      res: Error.Msg;
    BEGIN
      IF (w # NIL) THEN
        w. WriteLn;
        w. WriteString ("/* --- */");
        w. WriteLn;
        w. Close (res);
        IF (res # NIL) THEN
          errList. Append (res)
        END
      END;
    END CloseFile;
  
  BEGIN
    ParseModule.ParseModule (m, TRUE, TRUE, FALSE, FALSE, libraryName,
                             ast, symTab, pragmaHistory, errList);
    (* note: don't let `ParseModule' write the symbol file; this reduces the
       data in `symTab' to the view of client modules: declarations private to
       the module are stripped when writing the symbol file  *)
    
    IF errList.NoErrors() THEN
      IF writeAST THEN
        ASTtoXML.Write (StdChannels.stdout.NewWriter(), ast(ExtTree.Module));
      END;
      module := CreateIR.CreateIR (ast(ExtTree.Module), symTab, 
                                   IR.NewBuilder (symTab, pragmaHistory,
                                                  errList, 
                                                  ConstFold.NewConstFold()));
      IF writeIR THEN
        IRtoXML.Write (StdChannels.stdout. NewWriter(), module);
      END;
      
      exports := Exports.GetExports (symTab, TRUE);
      
      IF errList.NoErrors() THEN
        (* only attempt to produce output if program compiled without errors *)

        wh := WriteFile (Repository.modHeaderFileC);
        wd := WriteFile (Repository.modDeclFileC);
        IF (symTab. class = Sym.mcStandard) THEN
          wc := WriteFile (Repository.modCodeFileC);
        ELSE
          wc := NIL;
        END;

        WriteSymbolFile.WriteSymbolFile (m, symTab, errList);

        (* close all C output files after adding a tidbit of text to them;
           this way, these files are as old or more recent than the symbol
           file, and the generated C files may depened on the symbol file
           in the make rules *)
        CloseFile (wh);
        CloseFile (wd);
        CloseFile (wc);
      END;
      module.Destroy;                    (* cleanup for the sake of the gc *)
    END;
    
    RETURN errList;
  END Run;

END OOC:Make:TranslateToC.
