MODULE LibAdtObjectStorage;

IMPORT
  Out, IO, IO:FileChannel, ADT:Storable, ADT:Object:Storage;

TYPE
  Data = POINTER TO DataDesc;
  DataDesc = RECORD
    (Storable.ObjectDesc)
    next: Data;
    name: ARRAY 32 OF CHAR;
    num: LONGINT;
    written: BOOLEAN;
  END;

PROCEDURE (d: Data) Store* (w: Storable.Writer) RAISES IO.Error;
  BEGIN
    w.WriteObject(d.next);
    w.WriteString(d.name);
    w.WriteNum(d.num);
  END Store;

PROCEDURE (d: Data) Load* (r: Storable.Reader) RAISES IO.Error;
  VAR
    obj: Storable.Object;
  BEGIN
    r.ReadObject(obj);
    IF (obj = NIL) THEN
      d.next := NIL;
    ELSE
      d.next := obj(Data);
    END;
    r.ReadString(d.name);
    r.ReadNum(d.num);
  END Load;

PROCEDURE Write(d: Data);
  BEGIN
    IF (d = NIL) THEN
      Out.String ("NIL");
    ELSIF ~d.written THEN
      Out.String (d.name);
      Out.Char(",");
      Out.LongInt (d.num, 0);
      Out.Ln;
      
      d.written := TRUE;
      Write(d.next);
    END;
  END Write;

PROCEDURE GenData(): Data;
  VAR
    d1, d2, d3: Data;
    
  PROCEDURE NewData (name: ARRAY OF CHAR; num: LONGINT): Data;
    VAR
      d: Data;
    BEGIN
      NEW (d);
      Storable.Init(d);
      d.next := NIL;
      COPY(name, d.name);
      d.num := num;
      d.written := FALSE;
      RETURN d;
    END NewData;
  
  BEGIN
    d1 := NewData("obj1", 1);
    d2 := NewData("obj2", 128);
    d3 := NewData("obj3", 65536);
    d1.next := d2;
    d2.next := d3;
    d3.next := d1;                       (* cycle *)
    RETURN d1;
  END GenData;

PROCEDURE Test* () RAISES IO.Error;
  VAR
    f: IO.ByteChannel;
    w: Storage.Writer;
    r: Storage.Reader;
    data1, data2: Data;
    obj: Storable.Object;
  CONST
    dumpFile = "wd/storage.data";
  BEGIN
    data1 := GenData();
    Write(data1);
    
    f := FileChannel.Open(dumpFile, {FileChannel.write, FileChannel.create});
    w := Storage.ConnectWriter(f);
    w. WriteObject (data1);
    f.Close;

    f := FileChannel.Open(dumpFile, {FileChannel.read});
    r := Storage.ConnectReader(f);
    r. ReadObject (obj);
    data2 := obj(Data);
    f.Close;

    Out.Ln;
    Write(data2);
  END Test;

END LibAdtObjectStorage.
