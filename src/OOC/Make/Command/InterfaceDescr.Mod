MODULE OOC:Make:Command:InterfaceDescr;

IMPORT
  Channel, Files, Make, Msg, ADT:String, ADT:Dictionary, URI, 
  OOC:Auxiliary:GetSymbolTable, OOC:Auxiliary:Config,
  OOC:Error, OOC:Repository, OOC:SymbolTable:Item, 
  OOC:SymbolTable:Item:InterfaceDescr, OOC:Make:Entity:ModuleFile, 
  OOC:Doc:ResolveRef, OOC:Make:Entity:UsageData;

TYPE
  Command* = POINTER TO CommandDesc;
  CommandDesc = RECORD
    (Make.CommandDesc)
    output: ModuleFile.Entity;
    errList: Error.List;
  END;

PROCEDURE New* (output: ModuleFile.Entity): Command;
  VAR
    cmd: Command;
  BEGIN
    NEW (cmd);
    Make.InitCommand (cmd);
    cmd. output := output;
    cmd. errList := NIL;
    RETURN cmd
  END New;

PROCEDURE (cmd: Command) Id* (): String.String;
  BEGIN
    RETURN String.New ("[OOC:Make:Command:InterfaceDescr]")
  END Id;

PROCEDURE (cmd: Command) Discover* (): Make.CommandState;
  BEGIN
    cmd. AddAncestors (ModuleFile.GetEntity (cmd. context, cmd. output. module,
                                             Repository.modSymbolFile));
    RETURN Make.commandSchedule
  END Discover;

PROCEDURE (cmd: Command) Run*(): BOOLEAN;
(**Writes the description of the module's public interface as an XML document.
   *)
  VAR
    symTab: Item.Module;
    errList: Error.List;
    res: Msg.Msg;
    outputChannel: Channel.Channel;
    outputURI: URI.HierarchicalURI;
    m: Repository.Module;
    config: Config.Config;
  
  PROCEDURE GetExtensionDict (n: Make.Node): Dictionary.Dictionary;
    VAR
      edge: Make.Edge;
    BEGIN
      edge := n. ancestorList;
      WHILE (edge # NIL) DO
        IF (edge. ancestor IS UsageData.Entity) THEN
          RETURN edge. ancestor(UsageData.Entity). extensionDict
        END;
        edge := edge. nextAncestor
      END;
      RETURN NIL
    END GetExtensionDict;
  
  BEGIN
    m := cmd. output. module;
    config := cmd. context. config(Config.Config);
    symTab := GetSymbolTable.GetSymbolTable (m, config, res);
    
    errList := Error.NewList ("");
    ResolveRef.Resolve (symTab, config. repositories, errList);
    ASSERT (errList. msgCount = 0);
    
    outputURI := m. GetURI (Repository.modInterfaceDescr, res);
    outputChannel := m. GetOutputChannel (Repository.modInterfaceDescr, TRUE, res);
    IF (outputChannel = NIL) THEN
      errList. Append (res)
    ELSE
      InterfaceDescr.Write (outputChannel.NewWriter(), outputURI, symTab,
                         config. repositories, GetExtensionDict (cmd. output));
      outputChannel(Files.File). Register;
      outputChannel. Close;
      IF (outputChannel. res # Channel.done) THEN
        errList. Append (outputChannel. res)
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

END OOC:Make:Command:InterfaceDescr.
