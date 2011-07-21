MODULE OOC:Auxiliary:WriteSymbolFile;

IMPORT
  Strings, IO, IO:BinaryRider, IO:Memory,
  OOC:Repository, OOC:Error, Sym := OOC:SymbolTable, OOC:SymbolTable:Builder,
  OOC:SymbolTable:Exports;
  

PROCEDURE WriteSymbolFile* (m: Repository.Module; symTab: Sym.Module;
                            errList: Error.List)
RAISES IO.Error;
  VAR
    ch, chDoc: IO.ByteChannel;
    stb: Builder.Builder;
    mem: Memory.Channel;
    w: BinaryRider.Writer;
    fp, i, len, d: LONGINT;
    mr: Sym.ModuleRef;
  BEGIN
    mem := Memory.Open();
    chDoc := m.GetOutputChannel(Repository.modSymbolFileDoc, TRUE);
    Sym.Prune (symTab, Exports.GetExports (symTab, TRUE));
    stb := Builder.New();
    stb. WriteSymbolTable (mem, chDoc, symTab);
    mem.Fingerprint(fp, 0, mem.length);

    ch := m. GetOutputChannel (Repository.modSymbolFile, TRUE);
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
    
    mem.SetPos(0);
    d := mem.TransferTo(mem.length, ch);
    ch.CloseAndRegister();
    chDoc.CloseAndRegister();
  END WriteSymbolFile;

END OOC:Auxiliary:WriteSymbolFile.
