MODULE OOC:Auxiliary:WriteSymbolFile;

IMPORT
  Channel, Files, Msg, IO:Memory,
  OOC:Repository, OOC:Error, Sym := OOC:SymbolTable, OOC:SymbolTable:Builder,
  OOC:SymbolTable:Exports;
  

PROCEDURE WriteSymbolFile* (m: Repository.Module; symTab: Sym.Module;
                            errList: Error.List);
  VAR
    res: Msg.Msg;
    ch: Channel.Channel;
    stb: Builder.Builder;
    mem: Memory.Channel;
    w: Channel.Writer;
    fp: LONGINT;
  BEGIN
    mem := Memory.Tmp("", {Memory.read, Memory.write}, res);
    IF (res = NIL) THEN
      Sym.Prune (symTab, Exports.GetExports (symTab, TRUE));
      stb := Builder.New();
      stb. WriteSymbolTable (mem, symTab, res);
      mem.Fingerprint(fp, 0, mem.file.length);

      IF (res = NIL) THEN
        ch := m. GetOutputChannel (Repository.modSymbolFile, TRUE, res);
        IF (res = NIL) THEN
          w := ch.NewWriter();
          w.WriteBytes(fp, 0, SIZE(LONGINT));
          mem.CopyToWriter(w);
          ch(Files.File). Register;
          ch.Close;
          
          res := w.res;
          IF (res = Channel.done) THEN
            res := ch. res
          END
        END;
      END;
    END;
    IF (res # NIL) THEN
      errList. Append (res)
    END
  END WriteSymbolFile;

BEGIN
  
END OOC:Auxiliary:WriteSymbolFile.
