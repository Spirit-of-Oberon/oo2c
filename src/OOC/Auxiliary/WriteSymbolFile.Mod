MODULE OOC:Auxiliary:WriteSymbolFile;

IMPORT
  Channel, Files, Msg, 
  OOC:Repository, OOC:Error, OOC:SymbolTable:Item, OOC:SymbolTable:Builder,
  OOC:SymbolTable:Exports;
  

PROCEDURE WriteSymbolFile* (m: Repository.Module; symTab: Item.Module;
                            errList: Error.List);
  VAR
    res: Msg.Msg;
    ch: Channel.Channel;
    stb: Builder.Builder;
  BEGIN
    ch := m. GetOutputChannel (Repository.modSymbolFile, TRUE, res);
    IF (res = NIL) THEN
      Item.Prune (symTab, Exports.GetExports (symTab)); (* ... *)
      stb := Builder.New();
      stb. WriteSymbolTable (ch, symTab, res);
      ch(Files.File). Register;
      ch. Close;
      IF (res = Channel.done) THEN
        res := ch. res
      END
    END;
    IF (res # NIL) THEN
      errList. Append (res)
    END
  END WriteSymbolFile;

BEGIN
  
END OOC:Auxiliary:WriteSymbolFile.
