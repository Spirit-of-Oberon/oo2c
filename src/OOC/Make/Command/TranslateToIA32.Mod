(* 	$Id$	 *)
MODULE OOC:Make:Command:TranslateToIA32 [OOC_EXTENSIONS];
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
  Ascii, Channel, Make, Msg, StdChannels, ADT:String, ADT:Dictionary, 
  OOC:Make:Entity:ModuleFile,
  OOC:Config:Pragmas, OOC:Auxiliary:ParseModule,
  OOC:Auxiliary:WriteSymbolFile, OOC:Error, Rep := OOC:Repository, OOC:AST,
  OOC:AST:ExtTree, OOC:AST:ExtTree:CreateIR, ASTtoXML := OOC:AST:ExtTree:XML, 
  OOC:IR, IRtoXML := OOC:IR:XML, OOC:IR:ConstFold,
  Sym := OOC:SymbolTable, OOC:SymbolTable:Exports, 
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

TYPE
  Command* = POINTER TO CommandDesc;
  CommandDesc = RECORD
    (Make.CommandDesc)
    module: Rep.Module;
    errList: Error.List;
    writeAST: BOOLEAN;
    writeIR: BOOLEAN;
    translator: Translator;
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


PROCEDURE New* (context: Make.Context; module: Rep.Module;
                writeAST, writeIR: BOOLEAN; translator: Translator): Command;
  VAR
    cmd: Command;
  BEGIN
    NEW (cmd);
    Make.InitCommand (cmd, context);
    cmd. module := module;
    cmd. errList := NIL;
    cmd. writeAST := writeAST;
    cmd. writeIR := writeIR;
    cmd. translator := translator;
    RETURN cmd
  END New;

PROCEDURE (cmd: Command) Id* (): String.String;
  BEGIN
    RETURN String.New ("[OOC:Make:Command:TranslateToIA32]")
  END Id;

PROCEDURE (cmd: Command) Discover* (): Make.CommandState;
  PROCEDURE HasInvalidAncestor(): BOOLEAN;
    VAR
      aEdge: Make.Edge;
    BEGIN
      aEdge := cmd. ancestorList;
      WHILE (aEdge # NIL) DO
        IF (aEdge. ancestor IS Make.Entity) &
           (aEdge. ancestor(Make.Entity). state = Make.entityInvalid) &
           (aEdge. ancestor(Make.Entity). command # NIL) THEN
          RETURN TRUE
        END;
        aEdge := aEdge. nextAncestor
      END;
      RETURN FALSE
    END HasInvalidAncestor;

  PROCEDURE AddDescendant (fileId: Rep.FileId);
    VAR
      desc: ModuleFile.Entity;
    BEGIN
      desc := ModuleFile.GetEntity (cmd. context, cmd. module, fileId);
      IF ~desc. IsDescendantOf (cmd) THEN
        cmd. AddDescendant (desc)
      END
    END AddDescendant;
  
  BEGIN
    IF (cmd. state = Make.commandUndiscovered) THEN
      AddDescendant (Rep.modAssemblerFile);
      AddDescendant (Rep.modSymbolFile);
      ModuleFile.DiscoverCompile (cmd, cmd. module);
      RETURN cmd. state+1
    ELSE
      (* if one of the ancestors is invalid because of failed build, then
         don't try to run this command; note: an ancestor that is invalid
         without any attempt to build it does not generate an error, so we
         run this command just to get an error message *)
      IF HasInvalidAncestor() THEN
        RETURN Make.commandInvalid
      ELSE
        RETURN Make.commandSchedule
      END
    END
  END Discover;


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


PROCEDURE (cmd: Command) Run*(): BOOLEAN;
(**Compiles a module, creating the symbol file and all relevant C files.  *)
  VAR
    ast: AST.Node;
    symTab: Sym.Module;
    errList: Error.List;
    m: Rep.Module;
    exports: Dictionary.Dictionary;
    module: IR.Module;
    pragmaHistory: Pragmas.History;
    w: Writer.Writer;
    res: Msg.Msg;

  PROCEDURE CloseFile (w: Writer.Writer);
    VAR
      res: Error.Msg;
    BEGIN
      IF (w # NIL) THEN
        w. Newline;
        w. Close (res);
        IF (res # NIL) THEN
          errList. Append (res)
        END
      END;
    END CloseFile;
  
  BEGIN
    m := cmd. module;
    ParseModule.ParseModule (m, TRUE, TRUE, FALSE,
                             ast, symTab, pragmaHistory, errList);
    (* note: don't let `ParseModule' write the symbol file; this reduces the
       data in `symTab' to the view of client modules: declarations private to
       the module are stripped when writing the symbol file  *)
    
    IF (errList. msgCount = 0) THEN
      IF cmd. writeAST THEN
        ASTtoXML.Write (StdChannels.stdout.NewWriter(), ast(ExtTree.Module));
      END;
      module := CreateIR.CreateIR (ast(ExtTree.Module), symTab, 
                                   IR.NewBuilder (symTab, pragmaHistory,
                                                  errList,
                                                  ConstFold.NewConstFold()));
      IF cmd. writeIR THEN
        IRtoXML.Write (StdChannels.stdout. NewWriter(), module);
      END;
      
      exports := Exports.GetExports (symTab, TRUE);
      
      IF (errList. msgCount = 0) THEN
        (* only attempt to produce output if program compiled without errors *)

        w := Writer.NewWriter
            (m. GetOutputChannel (Rep.modAssemblerFile, TRUE, res));
        IF (res = Channel.done) THEN
          WriteCodeFile (w, m, symTab, module, cmd. translator);
        ELSE
          errList. Append (res);
        END;
        WriteSymbolFile.WriteSymbolFile (m, symTab, errList);

        (* close all output file after adding a tidbit of text to it;
           this way, these files are as old or more recent than the symbol
           file, and the file depened on the symbol file in the make rules *)
        CloseFile (w);
      END;
    END;
    
    cmd. errList := errList;
    RETURN (errList. msgCount = 0)
  END Run;

PROCEDURE (cmd: Command) ProduceOutput* (stdout, stderr: Channel.Channel);
  BEGIN
    IF (cmd. errList. msgCount # 0) THEN
      cmd. errList. Write (stderr)
    END
  END ProduceOutput;

END OOC:Make:Command:TranslateToIA32.
