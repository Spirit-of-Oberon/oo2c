(* 	$Id$	 *)
MODULE OOC:Make:Command:TranslateToC;
(*  Translates a module file into a bunch of C code files.
    Copyright (C) 2001  Michael van Acken

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
  Channel, Files, Make, StdChannels, TextRider, ADT:String, ADT:Dictionary,
  URI, OOC:Make:Entity:ModuleFile,
  OOC:Config:Pragmas, OOC:Auxiliary:Config, OOC:Auxiliary:ParseModule,
  OOC:Error, OOC:Repository, OOC:AST,
  OOC:AST:ExtTree, OOC:AST:ExtTree:CreateIR,
  OOC:IR, OOC:IR:Operator, OOC:IR:XML,
  OOC:SymbolTable:Item, OOC:SymbolTable:Exports,
  OOC:C:WriteConst, OOC:C:WriteDecl, OOC:C:ConvertDecl, OOC:C:Naming,
  WriteSSA := OOC:SSA:WriteC;

TYPE
  Command* = POINTER TO CommandDesc;
  CommandDesc = RECORD
    (Make.CommandDesc)
    module: Repository.Module;
    errList: Error.List;
    useSSA: BOOLEAN;
    writeIR: BOOLEAN;
  END;

PROCEDURE New* (context: Make.Context; module: Repository.Module;
                useSSA, writeIR: BOOLEAN): Command;
  VAR
    cmd: Command;
  BEGIN
    NEW (cmd);
    Make.InitCommand (cmd, context);
    cmd. module := module;
    cmd. errList := NIL;
    cmd. useSSA := useSSA;
    cmd. writeIR := writeIR;
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

PROCEDURE WriteFile (m: Repository.Module; fileId: Repository.FileId;
                     errList: Error.List;
                     converter: ConvertDecl.Converter;
                     moduleIR: IR.Module; useSSA: BOOLEAN);
  VAR
    ch: Channel.Channel;
    baseURI: URI.HierarchicalURI;
    res: Error.Msg;
    w: TextRider.Writer;
    import: Repository.Import;
  
  PROCEDURE WriteInclude (w: TextRider.Writer;
                          includeURI: URI.HierarchicalURI);
    VAR
      relativeURI: URI.URI;
      str: ARRAY 1024 OF CHAR;
    BEGIN
      relativeURI := includeURI. MakeRelative (baseURI);
      relativeURI. GetString (str);
      w. WriteString ('#include "');
      IF (str[0] # "/") & (str[0] # ".") THEN
        w. WriteString ("./")
      END;
      w. WriteString (str);
      w. WriteString ('"');
      w. WriteLn
    END WriteInclude;
  
  PROCEDURE WriteModuleName (w: TextRider.Writer; 
                             prefix: ARRAY OF CHAR;
                             module: Repository.Module;
                             suffix: ARRAY OF CHAR;
                             newline: BOOLEAN);
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
  
  PROCEDURE WriteDeclarations (w: TextRider.Writer;
                               converter: ConvertDecl.Converter;
                               writeExported: BOOLEAN);
    VAR
      b: WriteDecl.Block;
    BEGIN
      b := WriteDecl.NewBlock();
      converter. ConvertSymTab (b, writeExported);
      b. Write (w)
    END WriteDeclarations;
  
  PROCEDURE WriteExpr (w: TextRider.Writer;
                       converter: ConvertDecl.Converter;
                       expr: IR.Expression);
    VAR
      name: String.String;
    BEGIN
      WITH expr: IR.Const DO
        WriteConst.Write (w, expr. value)
        
      | expr: IR.Var DO
        name := Naming.NameOfDeclaration (expr. decl);
        w. WriteString (name. array^)
        
      | expr: Operator.Negate DO
        w. WriteChar ("-");
        WriteExpr (w, converter, expr. opnd1);
      END
    END WriteExpr;
    
  PROCEDURE WriteStatmSeq (w: TextRider.Writer;
                           converter: ConvertDecl.Converter;
                           statmSeq: IR.StatementSeq);
    VAR
      i: LONGINT;
      statm: IR.Statement;
    
    PROCEDURE Assert (statm: IR.Assert);
      BEGIN
        IF ~statm. disabled THEN
          w. WriteLn;
          w. WriteString ("_assert(");
          WriteExpr (w, converter, statm. predicate);
          w. WriteString (", ");
          w. WriteLInt (statm. code, 0);
          w. WriteString (", ");
          w. WriteString ("0");  (* ... file position missing *)
          w. WriteString (");")
        END
      END Assert;
    
    PROCEDURE Call (statm: IR.Call);
      VAR
        i: LONGINT;
        design: IR.Expression;
        name: String.String;
      BEGIN
        w. WriteLn;
        design := statm. design;
        WITH design: IR.ProcedureRef DO
          name := Naming.NameOfDeclaration (design. decl);
          w. WriteString (name. array^)
        END;
        w. WriteString ("(");
        FOR i := 0 TO LEN (statm. arguments^)-1 DO
          (* FIXME... this may be incorrect if the argument list includes
             multiple occurences of expressions that should only be 
             evaluated once *)
          IF (i # 0) THEN
            w. WriteString (", ")
          END;
          WriteExpr (w, converter, statm. arguments[i])
        END;
        w. WriteString (");");
      END Call;
    
    BEGIN
      (* quick and dirty translation with limited scope; should be placed
         in a separate module ... *)
      FOR i := 0 TO LEN (statmSeq^)-1 DO
        statm := statmSeq[i];
        WITH statm: IR.Assert DO
          Assert (statm)
        | statm: IR.Call DO
          Call (statm)
        END
      END
    END WriteStatmSeq;
  
  PROCEDURE WriteProcedures (w: TextRider.Writer;
                             converter: ConvertDecl.Converter;
                             procList: IR.ProcedureList);
    VAR
      b: WriteDecl.Block;
      d: WriteDecl.Declaration;
      i: LONGINT;
    BEGIN
      b := WriteDecl.NewBlock();
      FOR i := 0 TO LEN (procList^)-1 DO
        d := converter. ConvertProc (b, procList[i]. decl);
        w. WriteLn;
        d. Write (w);
        w. WriteString (" {");
        IF useSSA THEN
          WriteSSA.ProcBody (w, converter, procList[i]);
        ELSE
          WriteStatmSeq (w, converter, procList[i]. statmSeq);
        END;
        w. WriteLn;
        w. WriteString ("}");
        w. WriteLn
      END
    END WriteProcedures;
  
  BEGIN
    ch := m. GetOutputChannel (fileId, TRUE, res);
    IF (res = Channel.done) THEN
      baseURI := m. GetURI (fileId);
      w := TextRider.ConnectWriter (ch);
      
      CASE fileId OF
      | Repository.modHeaderFileC:
        WriteModuleName (w, "#ifndef _MODULE_", m, "_", TRUE);
        WriteModuleName (w, "#define _MODULE_", m, "_", TRUE);
        w. WriteLn;
        
        (* __typemap definitions are required parse definitions of the
           module header file *)
        w. WriteString ('#include "__typemap.h"');
        w. WriteLn;
        import := m. importList;
        WHILE (import # NIL) DO
          WriteInclude (w, import. imported.
            GetURI (Repository.modHeaderFileC));
          import := import. nextImport
        END;
        w. WriteLn;
        
        WriteDeclarations (w, converter, TRUE);
        w. WriteLn;
        
        WriteModuleName (w, "#endif /* _MODULE_", m, "_ */", TRUE);
        
        
      | Repository.modDeclFileC:
         WriteInclude (w, m. GetURI (Repository.modHeaderFileC));
         WriteDeclarations (w, converter, FALSE);
          
      | Repository.modCodeFileC:
         WriteInclude (w, m. GetURI (Repository.modDeclFileC));

        (* include full __oo2c.h only in generated C code files; this way,
           the .h and .d files can be used without pulling in all the 
           declarations of the run-time header file *)
         w. WriteString ('#include "__oo2c.h"');
         w. WriteLn;
         WriteProcedures (w, converter, moduleIR. procList);
         w. WriteLn;
         WriteModuleName (w, "void ", m, "_init(void) {", FALSE);
         WriteStatmSeq (w, converter, moduleIR. statmSeq);
         w. WriteLn;
         w. WriteString ("}");
         w. WriteLn
      END;
      
      res := w. res;
      ch(Files.File). Register;
      IF (ch. res # NIL) & (res = NIL) THEN
        res := ch. res
      END
    END;
    
    IF (res # NIL) THEN
      errList. Append (res)
    END
  END WriteFile;


PROCEDURE (cmd: Command) Run*(): BOOLEAN;
(**Compiles a module, creating the symbol file and all relevant C files.  *)
  VAR
    ast: AST.Node;
    symTab: Item.Module;
    errList: Error.List;
    m: Repository.Module;
    config: Config.Config;
    exports: Dictionary.Dictionary;
    module: IR.Module;
    converter: ConvertDecl.Converter;
    pragmaHistory: Pragmas.History;
  BEGIN
    m := cmd. module;
    config := cmd. context. config(Config.Config);
    ParseModule.ParseModule (m, config, TRUE, TRUE, TRUE,
                             ast, symTab, pragmaHistory, errList);
    (* symbol file is written by the `ParseModule' function *)
    
    IF (errList. msgCount = 0) THEN
      module := CreateIR.CreateIR (ast(ExtTree.Module), symTab, 
                                 Operator.NewBuilder (pragmaHistory, errList));
      IF cmd. writeIR THEN
        XML.Write (StdChannels.stdout. NewWriter(), module);
        
      END;
      
      exports := Exports.GetExports (symTab);
      converter := ConvertDecl.NewConverter (m, symTab, exports);
      
      WriteFile (m, Repository.modHeaderFileC, errList, converter,
                 NIL, cmd. useSSA);
      WriteFile (m, Repository.modDeclFileC, errList, converter,
                 NIL, cmd. useSSA);
      IF (symTab. class = Item.mcStandard) THEN
        WriteFile (m, Repository.modCodeFileC, errList, converter,
                   module, cmd. useSSA)
      END
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
