(* 	$Id$	 *)
MODULE OOC:Make:Command:TranslateToC [OOC_EXTENSIONS];
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
  Channel, Make, StdChannels, ADT:String, ADT:Dictionary, 
  OOC:Make:Entity:ModuleFile,
  OOC:Config:Pragmas, OOC:Auxiliary:Config, OOC:Auxiliary:ParseModule,
  OOC:Auxiliary:WriteSymbolFile, OOC:Error, OOC:Repository, OOC:AST,
  OOC:AST:ExtTree, OOC:AST:ExtTree:CreateIR, ASTtoXML := OOC:AST:ExtTree:XML, 
  OOC:IR, IRtoXML := OOC:IR:XML, OOC:IR:ConstFold,
  Sym := OOC:SymbolTable, OOC:SymbolTable:Exports, 
  OOC:C:DeclWriter, OOC:C:ConvertDecl;

TYPE
  Translator* = POINTER TO TranslatorDesc;
  TranslatorDesc* = RECORD [ABSTRACT]
    w-: DeclWriter.Writer;
  END;

TYPE
  Command* = POINTER TO CommandDesc;
  CommandDesc = RECORD
    (Make.CommandDesc)
    module: Repository.Module;
    errList: Error.List;
    writeAST: BOOLEAN;
    writeIR: BOOLEAN;
    translator: Translator;
  END;


PROCEDURE InitTranslator* (t: Translator);
  BEGIN
    t. w := NIL;
  END InitTranslator;

PROCEDURE (t: Translator) SetWriter* (w: DeclWriter.Writer);
  BEGIN
    t. w := w;
  END SetWriter;

PROCEDURE (t: Translator) [ABSTRACT] WriteProcBody* (proc: IR.Procedure);
  END WriteProcBody;

PROCEDURE (t: Translator) [ABSTRACT] WriteModuleBody* (statmSeq: IR.StatementSeq);
  END WriteModuleBody;


PROCEDURE New* (context: Make.Context; module: Repository.Module;
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
    RETURN String.New ("[OOC:Make:Command:TranslateToC]")
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

  PROCEDURE AddDescendant (fileId: Repository.FileId);
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
      AddDescendant (Repository.modHeaderFileC);
      AddDescendant (Repository.modDeclFileC);
      AddDescendant (Repository.modCodeFileC);
      AddDescendant (Repository.modSymbolFile);
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
  VAR
    import: Repository.Import;
  BEGIN
    WriteModuleName (w, "#ifndef _MODULE_", m, "_", TRUE);
    WriteModuleName (w, "#define _MODULE_", m, "_", TRUE);
    w. WriteLn;
    
    (* __typemap definitions are required parse definitions of the
       module header file *)
    w. WriteString ('#include "__typemap.h"');
    w. WriteLn;
    import := m. importList;
    WHILE (import # NIL) DO
      w. WriteInclude (import.imported.GetURI (Repository.modHeaderFileC));
      import := import. nextImport
    END;
    w. WriteLn;
    
    ConvertDecl.ConvertSymTab (w, m, symTab, exports, TRUE);
    w. WriteDeclarationList;
    w. WriteLn;
    
    WriteModuleName (w, "#endif /* _MODULE_", m, "_ */", TRUE);
  END WriteHeaderFile;

PROCEDURE WriteDeclFile (w: DeclWriter.Writer; m: Repository.Module;
                         symTab: Sym.Module; exports: Dictionary.Dictionary);
  BEGIN
    w. WriteInclude (m. GetURI (Repository.modHeaderFileC));
    ConvertDecl.ConvertSymTab (w, m, symTab, exports, FALSE);
    w. WriteDeclarationList;
  END WriteDeclFile;

PROCEDURE WriteCodeFile (w: DeclWriter.Writer; m: Repository.Module;
                         moduleIR: IR.Module; translator: Translator);
  PROCEDURE WriteProcedures (w: DeclWriter.Writer;
                             procList: IR.ProcedureList);
    VAR
      d: DeclWriter.Declaration;
      i: LONGINT;
    BEGIN
      FOR i := 0 TO LEN (procList^)-1 DO
        d := ConvertDecl.GetProc (w, procList[i]. decl);
        w. WriteLn;
        w. WriteDeclaration (d);
        w. WriteString (" {");
        translator. WriteProcBody (procList[i]);
        w. WriteLn;
        w. WriteString ("}");
        w. WriteLn
      END
    END WriteProcedures;
  
  BEGIN
    w. WriteInclude (m. GetURI (Repository.modDeclFileC));
    translator. SetWriter (w);
    
    (* include full __oo2c.h only in generated C code files; this way,
       the .h and .d files can be used without pulling in all the 
       declarations of the run-time header file *)
    w. WriteString ('#include "__oo2c.h"');
    w. WriteLn;
    WriteProcedures (w, moduleIR. procList);
    w. WriteLn;
    WriteModuleName (w, "void ", m, "_init(void) {", FALSE);
    translator. WriteModuleBody (moduleIR. statmSeq);
    w. WriteLn;
    w. WriteString ("}");
    w. WriteLn;
  END WriteCodeFile;


PROCEDURE (cmd: Command) Run*(): BOOLEAN;
(**Compiles a module, creating the symbol file and all relevant C files.  *)
  VAR
    ast: AST.Node;
    symTab: Sym.Module;
    errList: Error.List;
    m: Repository.Module;
    config: Config.Config;
    exports: Dictionary.Dictionary;
    module: IR.Module;
    pragmaHistory: Pragmas.History;

  PROCEDURE WriteFile (fileId: Repository.FileId);
    VAR
      res: Error.Msg;
      w: DeclWriter.Writer;
    BEGIN
      w := DeclWriter.NewWriter (m. GetOutputChannel (fileId, TRUE, res),
                                 m. GetURI (fileId));
      IF (res = Channel.done) THEN
        CASE fileId OF
        | Repository.modHeaderFileC:
          WriteHeaderFile (w, m, symTab, exports);
        | Repository.modDeclFileC:
          WriteDeclFile (w, m, symTab, exports);
        | Repository.modCodeFileC:
          WriteCodeFile (w, m, module, cmd. translator);
        END;
        w. Close (res);
      END;
      IF (res # NIL) THEN
        errList. Append (res)
      END
    END WriteFile;
  
  BEGIN
    m := cmd. module;
    config := cmd. context. config(Config.Config);
    ParseModule.ParseModule (m, config, TRUE, TRUE, FALSE,
                             ast, symTab, pragmaHistory, errList);
    (* note: don't let `ParseModule' write the symbol file; this reduces the
       data in `symTab' to the view of client modules: declarations private to
       the module are stripped when writing the symbol file  *)
    
    IF (errList. msgCount = 0) THEN
      IF cmd. writeAST THEN
        ASTtoXML.Write (StdChannels.stdout.NewWriter(), ast(ExtTree.Module));
      END;
      module := CreateIR.CreateIR (ast(ExtTree.Module), symTab, 
                                 IR.NewBuilder (pragmaHistory, errList, config.typeRules, ConstFold.NewConstFold()));
      IF cmd. writeIR THEN
        IRtoXML.Write (StdChannels.stdout. NewWriter(), module);
      END;
      
      exports := Exports.GetExports (symTab);
      
      IF (errList. msgCount = 0) THEN
        (* only attempt to produce output if program compiled without errors *)

        WriteFile (Repository.modHeaderFileC);
        WriteFile (Repository.modDeclFileC);
        IF (symTab. class = Sym.mcStandard) THEN
          WriteFile (Repository.modCodeFileC);
        END;

        WriteSymbolFile.WriteSymbolFile (m, symTab, errList);
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

END OOC:Make:Command:TranslateToC.
