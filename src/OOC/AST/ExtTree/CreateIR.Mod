MODULE OOC:AST:ExtTree:CreateIR;

IMPORT
  OOC:AST:ExtTree, OOC:IR;

PROCEDURE CreateIR* (module: ExtTree.Module; b: IR.Builder): IR.Module;
  BEGIN
    RETURN b. NewModule (module. moduleName)
  END CreateIR;

END OOC:AST:ExtTree:CreateIR.
