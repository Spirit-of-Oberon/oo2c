MODULE TestInterfaceGen;

IMPORT
  Object, StdChannels, Out, Err, ADT:Dictionary, ADT:ArrayList,
  CfgData := Config, Config:Section:Options,
  OOC:Config, OOC:SymbolTable:InterfaceDescr,
  OOC:Error, Rep := OOC:Repository, Sym := OOC:SymbolTable, OOC:Make;
  


VAR
  cfgErrList: Error.List;
  i: LONGINT;
  arg: STRING;
  chars: Object.CharsLatin1;
  m: Rep.Module;
  mode: SHORTINT;
  makeRules: Make.Rules;
  ok: BOOLEAN;
  moduleList: POINTER TO ARRAY OF Rep.Module;
  
  buildHTML: Options.Option;
  closure: Options.Option;
  errorStyle: Options.Option;
  

PROCEDURE NewConfig;
  BEGIN
    buildHTML := Config.AddOption ("build-html", CfgData.NewBooleanVar(FALSE));
    closure := Config.AddOption ("closure", CfgData.NewBooleanVar(FALSE));
    errorStyle := Config.AddOption ("error-style", CfgData.NewStringVar("default"));
    
    Config.AddCmdLine ("--repository,-r",
                 "<repositories><file-system>$1</file-system></repositories>");
    Config.AddCmdLine ("--html",
                 "<options><set name='build-html'>TRUE</set></options>");
    Config.AddCmdLine ("--closure",
                 "<options><set name='closure'>TRUE</set></options>");
    Config.AddCmdLine ("--error-style",
                 "<options><set name='error-style'>$1</set></options>");
  END NewConfig;

PROCEDURE CollectExtensions (moduleList: ARRAY OF Rep.Module): Sym.ExtensionDict;
  VAR
    extensionDict: Sym.ExtensionDict;
    visited: Dictionary.Dictionary;

  PROCEDURE Scan(m: Rep.Module);
    VAR
      ptr: Sym.Item;
      base: Sym.Type;
      list: ArrayList.ArrayList;
      i: LONGINT;
    BEGIN
      IF ~visited.HasKey(m) THEN
        visited.Set(m, NIL);

        FOR i := 0 TO LEN(m.ifImportList^)-1 DO
          Scan(m.ifImportList[i].module);
        END;

        ptr := m.ifData.nestedItems;
        WHILE (ptr # NIL) DO
          IF (ptr IS Sym.Record) & (ptr(Sym.Record). baseType # NIL) THEN
            base := ptr(Sym.Record). baseType;
            ASSERT(base IS Sym.Record);
            IF extensionDict. HasKey (base) THEN
              list := extensionDict. Get (base);
            ELSE
              list := ArrayList.New (4);
              extensionDict. Set (base, list)
            END;
            list. Append (ptr)
          END;
          ptr := ptr. nextNested
        END
      END;
    END Scan;
  
  BEGIN
    extensionDict := NEW(Sym.ExtensionDict);
    visited := Dictionary.New();
    FOR i := 0 TO LEN(moduleList)-1 DO
      Scan(moduleList[i]);
    END;
    RETURN extensionDict;
  END CollectExtensions;

BEGIN
  InterfaceDescr.absoluteDtdSystemId := FALSE;
  Rep.readDocStrings := TRUE;
  
  cfgErrList := Error.NewList ("");
  NewConfig;
  Config.Read (cfgErrList);
  (* discard errors in config file 
  IF (cfgErrList. msgCount # 0) THEN
    cfgErrList. Write (StdChannels.stderr);
    HALT (1)
  END;*)
  
  IF (Config.arguments. ArgNumber() = 0) THEN
    Out.String ("Usage: TestInterfaceGen [--html][--closure][--error-style <style>] {-r <base-dir>} <file>"); Out.Ln;
    HALT (1)
  ELSE
    makeRules := Make.NewRules();
    makeRules.SetBackend(Make.backendNone);
    makeRules.SetErrOut(StdChannels.stderr);
    ok := TRUE;
    
    IF errorStyle.value(CfgData.StringVar).string.Equals("oo2c") THEN
      Error.style := Error.styleCharPos;
    END;
    IF buildHTML.value(CfgData.BooleanVar). boolean THEN
      mode := Rep.modInterfaceHTML
    ELSE
      mode := Rep.modInterfaceDescr
    END;

    NEW(moduleList, Config.arguments.ArgNumber());
    FOR i := 0 TO Config.arguments. ArgNumber()-1 DO
      arg := Config.arguments.Get(i);
      arg := arg.ToString8("?");
      chars := arg(Object.String8).CharsLatin1();
      IF Rep.ValidModuleName (chars^) THEN
        m := Config.repositories. GetModule (chars^);
        IF (m = NIL) THEN
          Err.String ("Error: Cannot locate module ");
          Err.Object (arg);
          Err.Ln;
          HALT (1)
        ELSE
          moduleList[i] := m;
        END
      ELSE
        Err.String ("Error: Invalid module name ");
        Err.Object (arg);
        Err.Ln;
        HALT (1)
      END
    END;
    
    (* scan the symbol files of all modules, including all imports *)
    FOR i := 0 TO LEN(moduleList^)-1 DO
      ok := makeRules.Update(moduleList[i], Rep.modSymbolFile) & ok;
    END;
    makeRules.SetExtensionDict(CollectExtensions(moduleList^));
    
    FOR i := 0 TO LEN(moduleList^)-1 DO
      ok := makeRules.Update(moduleList[i], mode) & ok;
    END;
    
    IF ~ok THEN
      HALT (1)
    END
  END
END TestInterfaceGen.
