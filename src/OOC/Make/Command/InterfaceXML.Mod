MODULE OOC:Make:Command:InterfaceXML;

IMPORT
  Channel, Files, Msg, URI, Make, ADT:String,
  OOC:Make:Entity:ModuleFile, OOC:Auxiliary:ParseModule, OOC:Auxiliary:Config,
  OOC:Error, OOC:Repository, OOC:AST, 
  OOC:SymbolTable:Item, OOC:SymbolTable:Item:InterfaceXML;

TYPE
  Command* = POINTER TO CommandDesc;
  CommandDesc = RECORD
    (Make.CommandDesc)
    module: Repository.Module;
    errList: Error.List;
  END;

PROCEDURE New* (module: Repository.Module): Command;
  VAR
    cmd: Command;
  BEGIN
    NEW (cmd);
    Make.InitCommand (cmd);
    cmd. module := module;
    cmd. errList := NIL;
    RETURN cmd
  END New;

PROCEDURE (cmd: Command) Id* (): String.String;
  BEGIN
    RETURN String.New ("[OOC:Make:Command:InterfaceXML]")
  END Id;

PROCEDURE (cmd: Command) Discover* (): Make.CommandState;
  BEGIN
    cmd. AddAncestors (ModuleFile.GetEntity (cmd. context, cmd. module,
                                             Repository.modSymbolFile));
    RETURN Make.commandSchedule
  END Discover;

PROCEDURE (cmd: Command) Run*(): BOOLEAN;
(**Writes the description of the module's public interface as an XML document.
   *)
  VAR
    ast: AST.Node;
    symTab: Item.Module;
    errList: Error.List;
    res: Msg.Msg;
    outputChannel: Channel.Channel;
    outputURI: URI.HierarchicalURI;
    m: Repository.Module;
    config: Config.Config;
  BEGIN
    m := cmd. module;
    config := cmd. context. config(Config.Config);
    ParseModule.ParseModule (m, config, TRUE, FALSE, ast, symTab, errList);
    IF (errList. msgCount = 0) THEN
      outputURI := m. GetURI (Repository.modInterfaceXML, res);
      outputChannel := m. GetOutputChannel (Repository.modInterfaceXML, TRUE, res);
      IF (outputChannel = NIL) THEN
        errList. Append (res)
      ELSE
        InterfaceXML.Write (outputChannel.NewWriter(), outputURI, symTab,
                            config. repositories);
        outputChannel(Files.File). Register;
        outputChannel. Close;
        IF (outputChannel. res # Channel.done) THEN
          errList. Append (outputChannel. res)
        END
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

END OOC:Make:Command:InterfaceXML.
