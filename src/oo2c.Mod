MODULE oo2c;

IMPORT
  <*IF COMPILER_MAJOR>=2 THEN*>
    RT0,
  <*END*>
  StdChannels, Out, Err, Make, Make:Command:Target, StringSearch:NoMatch, 
  Config:Section:Arguments, Config:Section:Options, Config:Value:Boolean,
  OOC:Config, OOC:Config:CCompiler, OOC:Config:Assembler,
  OOC:SymbolTable:Builder,
  OOC:Make:Entity:ModuleFile, OOC:Make:Command:TranslateToC, 
  OOC:Make:Command:WriteMainFileC, OOC:Make:Command:CompileFileC,
  OOC:Make:Command:LinkProgramC, OOC:Error, Rep := OOC:Repository,
  SSAtoC := OOC:SSA:WriteC;
  


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

PROCEDURE (context: Context) NotifyCompletion* (node: Make.Node;
                                                success: BOOLEAN);
  BEGIN
    IF (node IS TranslateToC.Command) THEN
<*IF COMPILER_MAJOR>=2 THEN*>
      RT0.CollectGarbage;
<*END*>
    END;
  END NotifyCompletion;

PROCEDURE (context: Context) GetCommand* (entity: Make.Entity): Make.Command;
  PROCEDURE CompileToC (entity: ModuleFile.Entity): Make.Command;
    VAR
      t: TranslateToC.Translator;
    BEGIN
      t := SSAtoC.NewTranslator(NoMatch.matcher, NoMatch.matcher);
      RETURN TranslateToC.New (context, entity. module, FALSE, FALSE, t);
    END CompileToC;
  
  BEGIN
    WITH entity: ModuleFile.Entity DO
      CASE entity. fileId OF
      | Rep.modHeaderFileC, Rep.modDeclFileC, Rep.modCodeFileC:
        RETURN CompileToC (entity);
        
      | Rep.modSymbolFile:
        RETURN CompileToC (entity);
        
      | Rep.modMainFileC:
        RETURN WriteMainFileC.New (context, entity. module);
        
      | Rep.modObjectFile, Rep.modMainObjectFile:
        RETURN CompileFileC.New (context, entity. module, entity. fileId);
        
      | Rep.modExecutable:
        RETURN LinkProgramC.New (context, entity. module)
      END
    END
  END GetCommand;
  

PROCEDURE NewConfig;
  BEGIN
    make := Config.AddOption ("make", Boolean.New (FALSE));
    
    Config.AddCmdLine ("--repository,-r",
                 "<repositories><file-system>$1</file-system></repositories>");
    Config.AddCmdLine ("--make",
                 "<options><set name='make'>TRUE</set></options>");
    
    CCompiler.RegisterConfig;
  END NewConfig;

BEGIN
  Error.oo2cStyleErrors := TRUE;
  Error.minErrorDistance := 16;
  Builder.doAutoImport := TRUE;
  cfgErrList := Error.NewList ("");
  NewConfig;
  Config.Read (cfgErrList);
  
  IF make. value(Boolean.Value). boolean THEN
    mode := Rep.modExecutable
  ELSE
    mode := Rep.modCodeFileC
  END;
  Assembler.useAssembler := FALSE;
  
  IF (cfgErrList. msgCount # 0) THEN
    cfgErrList. Write (StdChannels.stdout);
    HALT (1)
  ELSIF (Config.arguments. ArgNumber() = 0) THEN
    Out.String ("Usage: oo2c [--config <cfg-file>] {-r <base-dir>} [--make] <file>"); Out.Ln;
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
END oo2c.
