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
  Channel, Files, Make, TextRider, ADT:String, ADT:Dictionary,
  URI, OOC:Make:Entity:ModuleFile,
  OOC:Auxiliary:Config, OOC:Auxiliary:ParseModule,
  OOC:Error, OOC:Repository, OOC:AST, 
  OOC:SymbolTable:Item, OOC:SymbolTable:Exports,
  OOC:C:WriteDecl, OOC:C:ConvertDecl;

TYPE
  Command* = POINTER TO CommandDesc;
  CommandDesc = RECORD
    (Make.CommandDesc)
    module: Repository.Module;
    errList: Error.List;
  END;

PROCEDURE New* (context: Make.Context; module: Repository.Module): Command;
  VAR
    cmd: Command;
  BEGIN
    NEW (cmd);
    Make.InitCommand (cmd, context);
    cmd. module := module;
    cmd. errList := NIL;
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
                     ast: AST.Node; symTab: Item.Module;
                     exports: Dictionary.Dictionary;
                     errList: Error.List);
  VAR
    ch: Channel.Channel;
    baseURI: URI.HierarchicalURI;
    res: Error.Msg;
    w: TextRider.Writer;
  
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
                             suffix: ARRAY OF CHAR);
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
      w. WriteLn;
    END WriteModuleName;
  
  PROCEDURE WriteDeclarations (w: TextRider.Writer; writeExported: BOOLEAN);
    VAR
      f: WriteDecl.Block;
    BEGIN
      f := WriteDecl.NewBlock();
      ConvertDecl.Convert (m, symTab, f, exports, writeExported);
      f. Write (w)
    END WriteDeclarations;
  
  BEGIN
    ch := m. GetOutputChannel (fileId, TRUE, res);
    IF (res = Channel.done) THEN
      baseURI := m. GetURI (fileId);
      w := TextRider.ConnectWriter (ch);
      
      CASE fileId OF
      | Repository.modHeaderFileC:
        WriteModuleName (w, "#ifndef _MODULE_", m, "_");
        WriteModuleName (w, "#define _MODULE_", m, "_");
        w. WriteLn;
        
        (*w. WriteString ('#include "_oo2c.h"'); w. WriteLn;*)
(*        import := m. importList;
        WHILE (import # NIL) DO
          WriteInclude (w, import. imported.
            GetURI (Repository.modHeaderFileC));
          import := import. nextImport
        END;*)
        
        WriteDeclarations (w, TRUE);
        w. WriteLn;
        
        WriteModuleName (w, "#endif /* ", m, " */");
        
        
      | Repository.modDeclFileC:
        WriteInclude (w, m. GetURI (Repository.modHeaderFileC));
        WriteDeclarations (w, FALSE);
          
      | Repository.modCodeFileC:
         WriteInclude (w, m. GetURI (Repository.modDeclFileC));
         w. WriteLn;
         WriteModuleName (w, "void ", m, "_init(void) {");
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
  BEGIN
    m := cmd. module;
    config := cmd. context. config(Config.Config);
    ParseModule.ParseModule (m, config, TRUE, TRUE, ast, symTab, errList);
    (* symbol file is written by the `ParseModule' function *)
    
    (* ... not much to do right now *)
    exports := Exports.GetExports (symTab);
    WriteFile (m, Repository.modHeaderFileC, ast, symTab, exports, errList);
    WriteFile (m, Repository.modDeclFileC, ast, symTab, exports, errList);
    IF (symTab. class = Item.mcStandard) THEN
      WriteFile (m, Repository.modCodeFileC, ast, symTab, exports, errList)
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
