MODULE OOC:X86:RuntimeData;

IMPORT
  Ascii, RT0, Object, ADT:StringBuffer, ADT:ArrayList, Sym := OOC:SymbolTable,
  OOC:SymbolTable:Predef, OOC:C:Naming;
  
TYPE
  DataWriter = POINTER TO DataWriterDesc;
  DataWriterDesc = RECORD
    sb: StringBuffer.StringBuffer;
    align: LONGINT;
    objectPosition: LONGINT;
  END;

CONST
  nl = Ascii.lf;
  tab = Ascii.ht;
  nlTab = nl+tab;

CONST
  sizeAddress = 4;
  sizeModuleDesc = 2*sizeAddress;
  sizeStructDesc = 9*sizeAddress;
  moduleDescriptor = "_mid";
  moduleName = "_mid_name";
  moduleTypeDescrList = "_mid_tdlist";
  
PROCEDURE (dw: DataWriter) INIT*(sb: StringBuffer.StringBuffer;
                                 align: LONGINT);
  BEGIN
    dw.sb := sb;
    dw.align := align;
    dw.objectPosition := -1;

    sb.Append(nlTab+".data");
    sb.Append(nlTab+".align ");
    sb.AppendInt(align);
  END INIT;

PROCEDURE (dw: DataWriter) Align();
  BEGIN
    dw.sb.Append(nlTab+".align ");
    dw.sb.AppendInt(dw.align);
  END Align;

PROCEDURE (dw: DataWriter) Object(name: STRING; size: LONGINT;
                                  global: BOOLEAN);
  BEGIN
    IF global THEN
      dw.sb.Append(nl+".global "+name);
    END;
    dw.sb.Append(nlTab+".type "+name+", @object");
    dw.sb.Append(nlTab+".size "+name+", ");
    dw.sb.AppendInt(size);
    dw.sb.Append(nl+name+":");
    dw.objectPosition := 0;
  END Object;

PROCEDURE (dw: DataWriter) Pad(bytes: LONGINT);
  BEGIN
    dw.sb.Append(nlTab+".zero ");
    dw.sb.AppendInt(bytes);
    INC(dw.objectPosition, bytes);
  END Pad;

PROCEDURE (dw: DataWriter) PadTo(pos: LONGINT);
  BEGIN
    IF (dw.objectPosition # pos) THEN
      dw.Pad(pos-dw.objectPosition);
    END;
  END PadTo;

PROCEDURE (dw: DataWriter) FixAlign(size: LONGINT);
  BEGIN
    dw.PadTo(size);
    IF (size MOD dw.align # 0) THEN
      dw.Align();
    END;
  END FixAlign;

PROCEDURE (dw: DataWriter) Adr(symbol: STRING);
  BEGIN
    dw.sb.Append(nlTab+".long ");
    dw.sb.Append(symbol);
    INC(dw.objectPosition, sizeAddress);
  END Adr;

PROCEDURE (dw: DataWriter) Null();
  BEGIN
    dw.sb.Append(nlTab+".long 0");
    INC(dw.objectPosition, sizeAddress);
  END Null;

PROCEDURE (dw: DataWriter) LongInt(x: LONGINT);
  BEGIN
    dw.sb.Append(nlTab+".long ");
    dw.sb.AppendInt(x);
    INC(dw.objectPosition, 4);
  END LongInt;

PROCEDURE (dw: DataWriter) ShortInt(x: SHORTINT);
  BEGIN
    dw.sb.Append(nlTab+".byte ");
    dw.sb.AppendInt(x);
    INC(dw.objectPosition, 1);
  END ShortInt;

PROCEDURE (dw: DataWriter) StringObject(name, value: STRING);
  VAR
    size: LONGINT;
  BEGIN
    size := value.length+1;
    dw.Object(name, size, FALSE);
    dw.sb.Append(nlTab+'.string "'+value+'"');
    INC(dw.objectPosition, size);
    dw.FixAlign(size);
  END StringObject;

PROCEDURE (dw: DataWriter) TypeFlags(type: Sym.Type);
(* Output any special run-time flags associated with type @oparam{type}. *)
  VAR
    flags: LONGINT;
  BEGIN
    flags := 0;
    IF (type # NIL) THEN
      WITH type : Sym.Record DO
        IF type.isVtable THEN
          INC(flags, ASH(1, RT0.flagVTable));
        END;
        IF type.isAtomic THEN
          INC(flags, ASH(1, RT0.flagAtomic));
        END;
        IF Predef.ImplementsFinalize(type) THEN
          INC(flags, ASH(1, RT0.flagFinalize));
        END;
      | type : Sym.Array DO
        IF type.isAtomic THEN
          INC(flags, ASH(1, RT0.flagAtomic));
        END;
      ELSE
      END;
    END;
    dw.LongInt(flags);
  END TypeFlags;

PROCEDURE Write*(sb: StringBuffer.StringBuffer; symTab: Sym.Module);
  VAR
    dw: DataWriter;
    tdNames: ArrayList.ArrayList;
    qtdData: Naming.QualTypeData;
    
  PROCEDURE ModuleDescr(module: Sym.Module; tdNames: ArrayList.ArrayList);
    VAR
      i, size: LONGINT;
    BEGIN
      dw.StringObject(moduleName, module.Name());

      size := (tdNames.size+1)*sizeAddress;
      dw.Object(moduleTypeDescrList, size, FALSE);
      FOR i := 0 TO tdNames.size-1 DO
        dw.Adr(tdNames.array[i](STRING));
      END;
      dw.Null();
      
      dw.Object(moduleDescriptor, sizeModuleDesc, FALSE);
      dw.Adr(moduleName);
      dw.Adr(moduleTypeDescrList);
      dw.FixAlign(sizeModuleDesc);
    END ModuleDescr;

  PROCEDURE WriteName(name: STRING; type: Sym.Type): STRING;
    BEGIN
      IF (type.namingDecl = NIL) THEN
        RETURN "0";
      ELSE
        dw.StringObject(name, Object.NewLatin1(type.namingDecl.name.str^));
        RETURN name;
      END;
    END WriteName;

  PROCEDURE TypeDescrRef(type: Sym.Type);
    BEGIN
      type := type.Deparam();
      IF type.hasDescriptor THEN
        dw.Adr(Naming.NameOfTypeDescriptor(type, qtdData));
      ELSE
        dw.Null();
      END;
    END TypeDescrRef;
  
  PROCEDURE ArrayTypeDescr(array: Sym.Array);
    VAR
      nameTypeDesc, nameTypeName, nameBaseTypes: STRING;
      base: Sym.Type;
    BEGIN
      nameTypeDesc := Naming.NameOfTypeDescriptor(array, qtdData);
      nameTypeName := nameTypeDesc+"_name";
      nameBaseTypes := nameTypeDesc+"_base_types";

      nameTypeName := WriteName(nameTypeName, array);
      IF array.isOpenArray THEN
        base := array.GetNonOpenElementType();
      ELSE
        base := array.elementType;
      END;
      dw.Object(nameBaseTypes, sizeAddress, TRUE);
      TypeDescrRef(base);
      
      dw.Object(nameTypeDesc, sizeStructDesc, FALSE);
      dw.Adr(nameBaseTypes);
      dw.Null();                         (* tbProcs *)
      dw.Null();                         (* typeArgs *)
      dw.Adr(moduleDescriptor);          (* module *)
      dw.Adr(nameTypeName);              (* name *)
      IF array.isOpenArray THEN
        ASSERT(base.size >= 0);
        dw.LongInt(base.size);             (* size *)
        dw.LongInt(array.GetOpenDimensions()); (* len *)
        dw.TypeFlags(array);               (* flags *)
        dw.ShortInt(RT0.strOpenArray);     (* form *)
      ELSE
        dw.LongInt(array.size);            (* size *)
        dw.LongInt(array.length);          (* len *)
        dw.TypeFlags(array);               (* flags *)
        dw.ShortInt(RT0.strArray);         (* form *)
      END;
      dw.FixAlign(sizeStructDesc);
    END ArrayTypeDescr;
  
  PROCEDURE RecordTypeDescr(record: Sym.Record);
    VAR
      len: LONGINT;
      nameTypeDesc, nameTypeName, nameBaseTypes: STRING;

    PROCEDURE BaseTypes(t: Sym.Type): LONGINT;
      VAR
        len: LONGINT;
      BEGIN
        IF (t = NIL) THEN
          RETURN -1;
        ELSE
          t := t.Deparam();
          len := BaseTypes(t(Sym.Record).baseType);
          dw.Adr(Naming.NameOfTypeDescriptor(t, qtdData));
          RETURN len+1;
        END;
      END BaseTypes;

    BEGIN
      nameTypeDesc := Naming.NameOfTypeDescriptor(record, qtdData);
      nameTypeName := nameTypeDesc+"_name";
      nameBaseTypes := nameTypeDesc+"_base_types";

      nameTypeName := WriteName(nameTypeName, record);

      dw.Object(nameBaseTypes, (record.ExtensionLevel()+1)*sizeAddress, FALSE);
      len := BaseTypes(record);
      
      dw.Object(nameTypeDesc, sizeStructDesc, TRUE);
      dw.Adr(nameBaseTypes);
      dw.Null();                         (* tbProcs *)
      dw.Null();                         (* typeArgs *)
      dw.Adr(moduleDescriptor);          (* module *)
      dw.Adr(nameTypeName);              (* name *)
      dw.LongInt(record.size);           (* size *)
      dw.LongInt(len);                   (* len *)
      dw.TypeFlags(record);              (* flags *)
      dw.ShortInt(RT0.strRecord);        (* form *)
      dw.FixAlign(sizeStructDesc);
    END RecordTypeDescr;
  
  PROCEDURE PointerTypeDescr(pointer: Sym.Pointer);
    VAR
      nameTypeDesc, nameTypeName, nameBaseTypes: STRING;
    BEGIN
      nameTypeDesc := Naming.NameOfTypeDescriptor(pointer, qtdData);
      nameTypeName := nameTypeDesc+"_name";
      nameBaseTypes := nameTypeDesc+"_base_types";

      nameTypeName := WriteName(nameTypeName, pointer);

      dw.Object(nameBaseTypes, sizeAddress, TRUE);
      TypeDescrRef(pointer.baseType);
      
      dw.Object(nameTypeDesc, sizeStructDesc, FALSE);
      dw.Adr(nameBaseTypes);
      dw.Null();                         (* tbProcs *)
      dw.Null();                         (* typeArgs *)
      dw.Adr(moduleDescriptor);          (* module *)
      dw.Adr(nameTypeName);              (* name *)
      dw.LongInt(pointer.size);          (* size *)
      dw.LongInt(-1);                    (* len *)
      dw.TypeFlags(pointer);             (* flags *)
      dw.ShortInt(RT0.strPointer);       (* form *)
      dw.FixAlign(sizeStructDesc);
    END PointerTypeDescr;
  
  PROCEDURE Traverse(item: Sym.Item; proc: Sym.ProcDecl);
    VAR
      nested: Sym.Item;

    PROCEDURE IsParameter(item: Sym.Item): BOOLEAN;
      BEGIN
        WHILE (item # proc) &
              ~((item IS Sym.VarDecl) & item(Sym.VarDecl).isParameter) DO
          item := item.parent;
        END;
        RETURN (item # proc);
      END IsParameter;

    BEGIN
      WITH item: Sym.Array DO
        IF item.hasDescriptor & ~IsParameter(item) THEN
          ArrayTypeDescr(item);
        END;
      | item: Sym.Record DO
        IF item.hasDescriptor THEN
          RecordTypeDescr(item);
        END;
      | item: Sym.Pointer DO
        IF item.hasDescriptor THEN
          PointerTypeDescr(item);
        END;
      | item: Sym.ProcDecl DO            (* adjust current procedure *)
        proc := item;
      ELSE                               (* ignore everything else *)
      END;

      nested := item.nestedItems;
      WHILE (nested # NIL) DO
        Traverse(nested, proc);
        nested := nested.nextNested;
      END;
    END Traverse;

  BEGIN
    qtdData := NIL;   (* FIXME *)
    dw := NEW(DataWriter, sb, 4);
    tdNames := ArrayList.New(16);
    Traverse(symTab, NIL);
    (*QualTypeDescr(qtdData);*)
    ModuleDescr(symTab, tdNames);     (* define _mid *)
  END Write;

END OOC:X86:RuntimeData.
