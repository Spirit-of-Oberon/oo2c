MODULE OOC:Make:BuildCmd:CompileModule;

IMPORT
  OOC:Make, OOC:Make:Node:ModuleOutput, OOC:Auxiliary:ParseModule,
  OOC:Error, OOC:Repository, OOC:AST, 
  OOC:SymbolTable:Item;

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
(**Compiles a module, creating the symbol file and the object file.  *)
  VAR
    ast: AST.Node;
    symTab: Item.Module;
    errList: Error.List;
    m: Repository.Module;
  BEGIN
    m := n(ModuleOutput.Node). module;
    ParseModule.ParseModule (m, n. dg. config, TRUE, TRUE, ast, symTab, errList);
    (* symbol file is written by the `ParseModule' function *)
    (* ... no more to do right now *)
    RETURN Make.NewBuildResult (errList. msgCount = 0, FALSE, errList)
  END Build;

END OOC:Make:BuildCmd:CompileModule.
