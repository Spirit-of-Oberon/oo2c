MODULE OOC:Auxiliary:WriteSymbolFile;

IMPORT
  BinaryRider, Channel, Files, Msg, Strings, IO:Memory,
  OOC:Repository, OOC:Error, Sym := OOC:SymbolTable, OOC:SymbolTable:Builder,
  OOC:SymbolTable:Exports;
  

PROCEDURE WriteSymbolFile* (m: Repository.Module; symTab: Sym.Module;
                            errList: Error.List);
  VAR
    res: Msg.Msg;
    ch: Channel.Channel;
    stb: Builder.Builder;
    mem: Memory.Channel;
    w: BinaryRider.Writer;
    fp, i, len: LONGINT;
    mr: Sym.ModuleRef;
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
          w := BinaryRider.ConnectWriter(ch);
          w.WriteBytes(Builder.magicNumber, 0, Builder.magicNumberSize);
          w.WriteBytes(fp, 0, SIZE(LONGINT));
          
          (* Write list of all imported module names, in the order in which
             they appear in the source file.  This list is not part of the
             fingerprinted file area.  Any changes to this list do not
             invalidate the symbol file's fingerprint value.  *)
          w.WriteNum(LEN(symTab.prunedImports^));
          FOR i := 0 TO LEN(symTab.prunedImports^)-1 DO
            mr := symTab.prunedImports[i];
            len := Strings.Length(mr.name^);
            w.WriteNum(len);
            w.WriteBytes(mr.name^, 0, len);
            fp := mr.fingerprint;
            w.WriteBytes(fp, 0, SIZE(LONGINT));
          END;
          
          mem.CopyToWriter(w.byteWriter);
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
