MODULE OOC:Make:BuildCmd:InterfaceDescr;

IMPORT
  Channel, Files, Msg, ADT:Object:Dictionary, URI, 
  OOC:Make, OOC:Make:Node:ModuleOutput, OOC:Auxiliary:GetSymbolTable,
  OOC:Error, OOC:Repository, OOC:SymbolTable:Item, 
  OOC:SymbolTable:Item:InterfaceDescr,
  OOC:Doc:ResolveRef, OOC:Make:Node:UsageData;

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
    symTab: Item.Module;
    errList: Error.List;
    res: Msg.Msg;
    outputChannel: Channel.Channel;
    outputURI: URI.HierarchicalURI;
    m: Repository.Module;
  
  PROCEDURE GetExtensionDict (n: Make.Node): Dictionary.Dictionary;
    VAR
      edge: Make.Edge;
    BEGIN
      edge := n. ancestorList;
      WHILE (edge # NIL) DO
        IF (edge. ancestor IS UsageData.Node) THEN
          RETURN edge. ancestor(UsageData.Node). extensionDict
        END;
        edge := edge. nextAncestor
      END;
      RETURN NIL
    END GetExtensionDict;
  
  BEGIN
    m := n(ModuleOutput.Node). module;
    symTab := GetSymbolTable.GetSymbolTable (m, n. dg. config, res);
    
    errList := Error.NewList ("");
    ResolveRef.Resolve (symTab, n. dg. config. repositories, errList);
    ASSERT (errList. msgCount = 0);
    
    outputURI := m. GetURI (Repository.modInterfaceDescr, res);
    outputChannel := m. GetOutputChannel (Repository.modInterfaceDescr, TRUE, res);
    IF (outputChannel = NIL) THEN
      errList. Append (res)
    ELSE
      InterfaceDescr.Write (outputChannel, outputURI, symTab,
                            n. dg. config. repositories,
                            GetExtensionDict (n));
      outputChannel(Files.File). Register;
      outputChannel. Close;
      IF (outputChannel. res # Channel.done) THEN
        errList. Append (outputChannel. res)
      END
    END;
    RETURN Make.NewBuildResult (errList. msgCount = 0, FALSE, errList)
  END Build;

END OOC:Make:BuildCmd:InterfaceDescr.
