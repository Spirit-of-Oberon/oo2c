MODULE TestCompile;

IMPORT
  StdChannels, Out, Err, Make, Make:Command:Target,
  StringSearch, StringSearch:RegexpDFA, 
  Config:Section:Arguments, 
  Config:Section:Options, BooleanValue := Config:Value:Boolean,
  StringValue := Config:Value:String, ADT:String, Sym := OOC:SymbolTable,
  OOC:Config, OOC:Config:Assembler,
  OOC:Repository, OOC:Repository:GetModuleClass, OOC:Make:Entity:ModuleFile,
  OOC:Make:Command:TranslateToC, OOC:Make:Command:TranslateToIA32,
  OOC:Make:Command:WriteMainFileC, OOC:Make:Command:CompileFileC,
  OOC:Make:Command:WriteMainFileAssembler, OOC:Make:Command:AssembleFile,
  OOC:Make:Command:LinkProgramC, OOC:Error, Rep := OOC:Repository,
  OOC:C:IRtoC, SSAtoC := OOC:SSA:WriteC, SSAtoIA32 := OOC:IA32:WriteAssembler;
  


TYPE
  Context = POINTER TO ContextDesc;
  ContextDesc = RECORD
    (Make.ContextDesc)
  END;

VAR
  context: Context;


VAR
  cfgErrList: Error.List;
  i: LONGINT;
  arg: Arguments.Argument;
  node: ModuleFile.Entity;
  m: Rep.Module;
  mode: SHORTINT;
  
  make: Options.Option;
  writeAST: Options.Option;
  writeIR: Options.Option;
  useSSA: Options.Option;
  translateIA32: Options.Option;
  inspectProc: Options.Option;
  inspectStage: Options.Option;
  
  
PROCEDURE InitContext (context: Context; target: Make.Command);
  BEGIN
    Make.InitContext (context, NIL, target);
  END InitContext;

PROCEDURE NewContext(): Context;
  VAR
    context: Context;
  BEGIN
    NEW (context);
    InitContext (context, Target.New());
    RETURN context
  END NewContext;

PROCEDURE (context: Context) GetCommand* (entity: Make.Entity): Make.Command;
  PROCEDURE OptionToMatcher (option: Options.Option; cmdLineName: ARRAY OF CHAR): StringSearch.Matcher;
    VAR
      matcher: StringSearch.Matcher;
      str: String.String;
    BEGIN
      str := String.New (option. value(StringValue.Value). string^);
      matcher := RegexpDFA.factory. Compile (str, {});
      IF (matcher = NIL) THEN
        Err.String ("Warning: Cannot parse regular expression in ");
        Err.String (cmdLineName);
        Err.String (", ignoring it");
        Err.Ln;
        matcher := RegexpDFA.factory. Compile (String.New ("$"), {});
      END;
      RETURN matcher
    END OptionToMatcher;

  PROCEDURE CompileToC (entity: ModuleFile.Entity): Make.Command;
    VAR
      t: TranslateToC.Translator;
    BEGIN
      IF useSSA. value(BooleanValue.Value). boolean THEN
        t := SSAtoC.NewTranslator
            (OptionToMatcher (inspectProc, "--inspect.1"),
             OptionToMatcher (inspectStage, "--inspect.2"));
      ELSE
        t := IRtoC.NewTranslator();
      END;
      
      RETURN TranslateToC.New (context, entity. module,
                               writeAST.value(BooleanValue.Value). boolean,
                               writeIR. value(BooleanValue.Value). boolean,
                               t);
    END CompileToC;
  
  PROCEDURE CompileToAssembler (entity: ModuleFile.Entity): Make.Command;
    VAR
      tIA32: TranslateToIA32.Translator;
    BEGIN
      tIA32 := SSAtoIA32.NewTranslator
          (entity. module,
           OptionToMatcher (inspectProc, "--inspect.1"),
           OptionToMatcher (inspectStage, "--inspect.2"));
      RETURN TranslateToIA32.New
          (context, entity. module,
           writeAST.value(BooleanValue.Value). boolean,
           writeIR. value(BooleanValue.Value). boolean,
           tIA32);
    END CompileToAssembler;
  
  PROCEDURE AssemblerInput (aEdge: Make.Edge): BOOLEAN;
    VAR
      ancestor: ModuleFile.Entity;
    BEGIN
      WHILE (aEdge # NIL) DO
        ancestor := aEdge. ancestor(ModuleFile.Entity);
        IF (ancestor. fileId = Repository.modMainFileAssembler) OR
           (ancestor. fileId = Repository.modAssemblerFile) THEN
          RETURN TRUE;
        END;
        aEdge := aEdge. nextAncestor;
      END;
      RETURN FALSE;
    END AssemblerInput;
  
  BEGIN
    WITH entity: ModuleFile.Entity DO
      CASE entity. fileId OF
      | Rep.modHeaderFileC, Rep.modDeclFileC, Rep.modCodeFileC:
        RETURN CompileToC (entity);
        
      | Rep.modAssemblerFile:
        RETURN CompileToAssembler (entity);

      | Rep.modSymbolFile:
        IF translateIA32. value(BooleanValue.Value). boolean &
           (GetModuleClass.GetModuleClass (entity. module) = Sym.mcStandard) THEN
          RETURN CompileToAssembler (entity);
        ELSE
          RETURN CompileToC (entity);
        END;
             
      | Rep.modMainFileC:
        RETURN WriteMainFileC.New (context, entity. module);
        
      | Rep.modMainFileAssembler:
        RETURN WriteMainFileAssembler.New (context, entity. module);
        
      | Rep.modObjectFile, Rep.modMainObjectFile:
        IF AssemblerInput (entity. ancestorList) THEN
          RETURN AssembleFile.New (context, entity. module, entity. fileId);
        ELSE
          RETURN CompileFileC.New (context, entity. module, entity. fileId);
        END;
        
      | Rep.modExecutable:
        RETURN LinkProgramC.New (context, entity. module)
      END
    END
  END GetCommand;
  

PROCEDURE NewConfig;
  BEGIN
    make := Config.AddOption ("make", BooleanValue.New (FALSE));
    writeAST := Config.AddOption ("write-ast", BooleanValue.New (FALSE));
    writeIR := Config.AddOption ("write-ir", BooleanValue.New (FALSE));
    useSSA := Config.AddOption ("use-ssa", BooleanValue.New (FALSE));
    translateIA32 := Config.AddOption ("translate-ia32", BooleanValue.New (FALSE));
    inspectProc := Config.AddOption ("inspect-proc", StringValue.New ("$"));
    inspectStage := Config.AddOption ("inspect-stage", StringValue.New ("$"));
    
    Config.AddCmdLine ("--repository,-r",
                 "<repositories><file-system>$1</file-system></repositories>");
    Config.AddCmdLine ("--make",
                 "<options><set name='make'>TRUE</set></options>");
    Config.AddCmdLine ("--use-ssa",
                 "<options><set name='use-ssa'>TRUE</set></options>");
    Config.AddCmdLine ("--ia32",
                 "<options><set name='translate-ia32'>TRUE</set><set name='use-ssa'>TRUE</set></options>");
    Config.AddCmdLine ("--write-ast",
                 "<options><set name='write-ast'>TRUE</set></options>");
    Config.AddCmdLine ("--write-ir",
                 "<options><set name='write-ir'>TRUE</set></options>");
    Config.AddCmdLine ("--inspect",
                 "<options><set name='inspect-proc'>$1</set><set name='inspect-stage'>$2</set></options>");
  END NewConfig;

BEGIN
  Error.oo2cStyleErrors := TRUE;
  cfgErrList := Error.NewList ("");
  NewConfig;
  Config.Read (cfgErrList);
  
  IF make. value(BooleanValue.Value). boolean THEN
    mode := Rep.modExecutable
  ELSIF translateIA32. value(BooleanValue.Value). boolean THEN
    mode := Rep.modObjectFile;
  ELSE
    mode := Rep.modCodeFileC
  END;
  Assembler.useAssembler := translateIA32. value(BooleanValue.Value). boolean;
  
  IF (cfgErrList. msgCount # 0) THEN
    cfgErrList. Write (StdChannels.stderr);
    HALT (1)
  ELSIF (Config.arguments. ArgNumber() = 0) THEN
    Out.String ("Usage: TestCompile [--config <cfg-file>] {-r <base-dir>} [--make][--write-ast][--write-ir][--use-ssa|--ia32][--inspect <proc-regexp> <stage-regexp>] <file>"); Out.Ln;
    HALT (1)
  ELSE
    context := NewContext();
    
    FOR i := 0 TO Config.arguments. ArgNumber()-1 DO
      arg := Config.arguments. Get (i);
      m := Config.repositories. GetModule (arg^);
      IF (m = NIL) THEN
        Err.String ("Error: Cannot locate module ");
        Err.String (arg^);
        Err.Ln;
        HALT (1)
      ELSE
        node := ModuleFile.GetEntity (context, m, mode);
        context. target. AddAncestor (node)
      END
    END;
    
    IF ~context. Solve (StdChannels.stdout, StdChannels.stderr) THEN
      HALT (1)
    END
  END
END TestCompile.
