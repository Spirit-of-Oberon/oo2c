MODULE OOC:Make:BuildCmd:InterfaceXML;

IMPORT
  Channel, Files, Msg, URI, 
  OOC:Make, OOC:Make:Node:ModuleOutput, OOC:Auxiliary:ParseModule,
  OOC:Error, OOC:Repository, OOC:AST, 
  OOC:SymbolTable:Item, OOC:SymbolTable:Item:InterfaceXML;

TYPE
  BuildCmd* = POINTER TO BuildCmdDesc;
  BuildCmdDesc = RECORD
    (Make.BuildCmdDesc)
  END;

PROCEDURE New*(): BuildCmd;
  VAR
    cmd: BuildCmd;
  BEGIN
    NEW (cmd);
    RETURN cmd
  END New;

PROCEDURE (cmd: BuildCmd) Build* (n: Make.Node): Make.BuildResult;
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
  BEGIN
    m := n(ModuleOutput.Node). module;
    ParseModule.ParseModule (m, n. dg. config, TRUE, FALSE, ast, symTab, errList);
    IF (errList. msgCount = 0) THEN
      outputURI := m. GetURI (Repository.modInterfaceXML, res);
      outputChannel := m. GetOutputChannel (Repository.modInterfaceXML, TRUE, res);
      IF (outputChannel = NIL) THEN
        errList. Append (res)
      ELSE
        InterfaceXML.Write (outputChannel, outputURI, symTab,
                            n. dg. config. repositories);
        outputChannel(Files.File). Register;
        outputChannel. Close;
        IF (outputChannel. res # Channel.done) THEN
          errList. Append (outputChannel. res)
        END
      END
    END;
    RETURN Make.NewBuildResult (errList. msgCount = 0, FALSE, errList)
  END Build;

END OOC:Make:BuildCmd:InterfaceXML.
