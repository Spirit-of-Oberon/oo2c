MODULE gi;

IMPORT
  SYSTEM, Ascii, Channel, CharClass, Err, IntStr, Msg, StdChannels,
  RT0, Object, Exception, ADT:ArrayList, ADT:Dictionary, ADT:StringBuffer,
  ADT:Arrays, ADT:Comparator, OS:Path, OS:Files,
  StringSearch, StringSearch:RegexpDFA, StringSearch:NoMatch,
  IO, IO:Address, IO:FileChannel,
  Net:NNTP;

TYPE
  String = Object.String8;
  Header = POINTER TO HeaderDesc;
  HeaderDesc = RECORD
    (Object.ObjectDesc)
    msgId: LONGINT;
    subject: String;
  END;
  
TYPE
  GroupData = POINTER TO GroupDataDesc;
  GroupDataDesc = RECORD
    firstId, lastId: LONGINT;
    headers: ArrayList.ArrayList;  (* of Header *)
  END;

TYPE
  File = POINTER TO FileDesc;
  FileList = POINTER TO ARRAY OF File;
  FileDesc = RECORD
    (Object.ObjectDesc)
    subject: String;
    total: LONGINT;
    present: LONGINT;
    msgIds: POINTER TO ARRAY OF LONGINT;
  END;

TYPE
  CmpFile = POINTER TO CmpFileDesc;
  CmpFileDesc = RECORD
    (Comparator.ComparatorDesc)
  END;

TYPE
  Client = POINTER TO ClientDesc;
  ClientDesc = RECORD
    (NNTP.ClientDesc)
  END;
  
CONST
  eol = Ascii.lf;
  headerSep = Ascii.vt;
  
VAR
  cmpFile: CmpFile;
  nntpServer: String;
  dataDir: STRING;
  serverAddr: Address.SocketInet;
  nntpClient: Client;
  group: STRING;
  selectSubjects, excludeSubjects: StringSearch.Matcher;
  forceIncomplete: BOOLEAN;
  dumpTarget: Channel.Writer;
  historyChannel: IO.ByteChannel;
  history: Dictionary.Dictionary;
  
  reqGroup: NNTP.Group;
  reqXHdr: NNTP.XHdr;
  reqQuit: NNTP.Quit;
  text: NNTP.Text;
  gd: GroupData;
  fileList: FileList;
  removed: LONGINT;


PROCEDURE (cmp: CmpFile) Compare*(o1: Object.Object; o2: Object.Object): LONGINT;
  BEGIN
    RETURN o1(File).subject.Compare(o2(File).subject);
  END Compare;


PROCEDURE NewClient*(serverAddr: Address.SocketInet;
                     async: BOOLEAN): Client;
  VAR
    cl: Client;
  BEGIN
    NEW(cl);
    NNTP.InitClient(cl, serverAddr, async);
    RETURN cl;
  END NewClient;

PROCEDURE (cl: Client) LogRequest*(cmd: Object.String8);
  BEGIN
    Err.String("NNTP> "); Err.Object(cmd); Err.Ln;
  END LogRequest;

PROCEDURE (cl: Client) LogResponse*(statusLine: Object.String8);
  BEGIN
    Err.String("NNTP< "); Err.Object(statusLine); Err.Ln;
  END LogResponse;


PROCEDURE WriteUsage();
  BEGIN
    Err.String("Usage: gi [--force][--exclude <regexp>] <group> <regexp>"); Err.Ln;
  END WriteUsage;

PROCEDURE Error(msg: STRING);
  BEGIN
    Err.Object("Error: "+msg); Err.Ln;
    HALT(1);
  END Error;

PROCEDURE LogMsg(msg: STRING);
  BEGIN
    Err.Object(msg); Err.Ln;
  END LogMsg;

PROCEDURE HomeDir(): String;
  VAR
    path: ARRAY 1024 OF CHAR;
  BEGIN
    IF RT0.GetEnv("HOME", path) THEN
      RETURN Object.NewLatin1(path);
    ELSE
      Error("HOME is not set");
    END;
  END HomeDir;

PROCEDURE NntpServer(): String;
  VAR
    path: ARRAY 1024 OF CHAR;
  BEGIN
    IF RT0.GetEnv("NNTPSERVER", path) THEN
      RETURN Object.NewLatin1(path);
    ELSE
      Error("NNTPSERVER is not set");
    END;
  END NntpServer;

PROCEDURE GetConfig()
RAISES Address.UnknownHostException;
  VAR
    i: LONGINT;

  PROCEDURE GetArg(i: LONGINT): String;
    CONST
      maxLength = 8*1024;
    VAR
      buffer: ARRAY maxLength+2 OF CHAR;
      str: String;
    BEGIN
      COPY(RT0.argv[i]^, buffer);
      str := Object.NewLatin1(buffer);
      IF (str.length > maxLength) THEN
        Error("Argument too long");
      END;
      RETURN str;
    END GetArg;

  BEGIN
    group := NIL;
    selectSubjects := NIL;
    excludeSubjects := NoMatch.matcher;
    forceIncomplete := FALSE;
    
    i := 1;
    LOOP
      IF (i = RT0.argc) THEN
        EXIT;
      ELSIF (RT0.argv[i]^ = "--force") THEN
        forceIncomplete := TRUE; 
      ELSIF (RT0.argv[i]^ = "--exclude") & (i+2 <= RT0.argc) THEN
        excludeSubjects := RegexpDFA.factory.Compile(GetArg(i+1), {StringSearch.ignoreCase});
        IF (excludeSubjects = NIL) THEN
          Error("Invalid exclude pattern");
        END;
        INC(i, 2);
      ELSE
        EXIT;
      END;
    END;
    
    IF (i+2 = RT0.argc) THEN
      group := GetArg(i);
      selectSubjects := RegexpDFA.factory.Compile(GetArg(i+1),
                                                  {StringSearch.ignoreCase});
      IF (selectSubjects = NIL) THEN
        Error("Invalid select pattern");
      END;
    END;
    
    IF (group = NIL) THEN
      WriteUsage;
      HALT(1);
    END;
    serverAddr := Address.GetSocketInet(Address.GetByName(nntpServer),
                                        NNTP.defaultPort);
  END GetConfig;

PROCEDURE Normalize(VAR b: ARRAY OF CHAR; start, end: LONGINT): String;
  VAR
    i, d: LONGINT;
  BEGIN
    (* strip leading whitespace *)
    WHILE (start # end) & (b[start] <= " ") DO
      INC(start);
    END;
    
    (* change sequences of control or space characters to single space *)
    i := start; d := 0;
    WHILE (i # end) DO
      IF (b[i] <= " ") THEN
        b[i-d] := " ";
        INC(i);
        WHILE (b[i] <= " ") & (i # end) DO
          INC(i); INC(d);
        END;
      ELSE
        b[i-d] := b[i];
        INC (i);
      END;
    END;
    
    (* remove trailing space *)
    IF (i-d-1 >= start) & (b[i-d-1] = " ") THEN
      INC(d);
    END;
    
    RETURN Object.NewLatin1Region(b, start, i-d);
  END Normalize;

PROCEDURE ReadGroupData(group: STRING): GroupData
RAISES IO.Error;
  CONST
    sizeBuffer = 8*1024;
  VAR
    fileName: STRING;
    ch: IO.ByteChannel;
    b: ARRAY sizeBuffer OF CHAR;
    r, pos, start, end, i, lastId: LONGINT;
    gd: GroupData;
    header: Header;

  PROCEDURE CreateDir(fileName: STRING);
    VAR
      str: Object.CharsLatin1;
      path: ARRAY 1024 OF CHAR;
      res: Msg.Msg;
    BEGIN
      str := fileName(Object.String8).CharsLatin1();
      Path.dirname(str^, path);
      Files.makedirs(path, Files.defaultMode, res);
      ASSERT(res = NIL);
    END CreateDir;
  
  PROCEDURE ParseInt(VAR b: ARRAY OF CHAR; start, end: LONGINT): LONGINT;
    CONST
      maxLength = 12;
    VAR
      str: ARRAY maxLength+1 OF CHAR;
      i, x: LONGINT;
      res: IntStr.ConvResults;
    BEGIN
      IF (end-start <= maxLength) THEN
        i := 0;
        WHILE (start # end) DO
          str[i] := b[start]; INC(start); INC(i);
        END;
        str[i] := 0X;
        IntStr.StrToInt(str, x, res);
        IF (res = IntStr.strAllRight) THEN
          RETURN x;
        END;
      END;
      Error("Invalid number "+Object.NewLatin1Region(b, start, end));
    END ParseInt;
  
  PROCEDURE ParseStartEnd(VAR b: ARRAY OF CHAR; start, end: LONGINT;
                          VAR idStart, idEnd: LONGINT);
    VAR
      p0, p1, p2, p3: LONGINT;
    BEGIN
      p0 := start;
      WHILE CharClass.IsNumeric(b[start]) DO
        INC(start);
      END;
      p1 := start;
      IF (b[start] = "-") THEN
        INC(start);
        p2 := start;
        WHILE CharClass.IsNumeric(b[start]) DO
          INC(start);
        END;
        p3 := start;
        
        IF (start = end) THEN
          idStart := ParseInt(b, p0, p1);
          idEnd := ParseInt(b, p2, p3);
          RETURN;
        END;
      END;
      Error("Syntax error in first line of "+fileName);
    END ParseStartEnd;

  PROCEDURE ParseHeader(VAR b: ARRAY OF CHAR; start, end: LONGINT): Header;
    VAR
      p0, p1: LONGINT;
      header: Header;
    BEGIN
      p0 := start;
      WHILE (start # end) & CharClass.IsNumeric(b[start]) DO
        INC(start);
      END;
      p1 := start;
      IF (b[start] = headerSep) THEN
        INC(start);

        NEW(header);
        header.msgId := ParseInt(b, p0, p1);
        header.subject := Normalize(b, start, end);
        RETURN header;
      END;
      Error("Syntax error header line: "+
            Object.NewLatin1Region(b, p0, end));
    END ParseHeader;
  
  BEGIN
    NEW(gd);
    gd.headers := ArrayList.New(512);
    gd.firstId := -1;
    gd.lastId := -1;
    
    fileName := dataDir+"/"+group;
    LogMsg("Reading group file "+fileName);
    CreateDir(fileName);
    ch := FileChannel.Open(fileName(String), {FileChannel.read, FileChannel.write, FileChannel.create});
    
    pos := 0; end := 0; lastId := -1;
    LOOP
      r := ch.Read(b, pos, LEN(b)-pos);
      IF (r < 0) THEN
        IF (pos # 0) THEN
          Error("Incomplete line at end of "+fileName);
        END;
        EXIT;
      ELSE
        INC(end, r);
        start := 0;
        WHILE (pos # end) DO
          WHILE (pos # end) & (b[pos] # eol) DO
            INC(pos);
          END;
          IF (pos # end) THEN            (* found end of line *)
            IF (gd.firstId < 0) THEN     (* first line *)
              ParseStartEnd(b, start, pos, gd.firstId, gd.lastId);
            ELSE                         (* line with msg id and subject *)
              header := ParseHeader(b, start, pos);
              ASSERT(header.msgId > lastId);
              gd.headers.Append(header);
              lastId := header.msgId;
            END;
            INC(pos);
            start := pos;
          END;
        END;

        (* move unprocessed data to beginning of buffer *)
        FOR i := start TO end-1 DO
          b[i-start] := b[i];
        END;
        DEC(end, start);
        pos := end;
      END;
    END;
    ch.Close();

    IF (gd.firstId < 0) THEN             (* no data *)
      gd.firstId := 0; gd.lastId := 0;
    END;
    RETURN gd;
  END ReadGroupData;

PROCEDURE WriteGroupData(gd: GroupData) RAISES IO.Error;
  CONST
    sizeBuffer = 8*1024;
    maxIntLength = 12;
  VAR
    fileName: STRING;
    ch: IO.ByteChannel;
    b: ARRAY sizeBuffer OF CHAR;
    pos, i: LONGINT;
    header: Header;

  PROCEDURE AppendChar(ch: CHAR);
    BEGIN
      b[pos] := ch; INC(pos);
    END AppendChar;
  
  PROCEDURE AppendInt(int: LONGINT);
    VAR
      str: ARRAY maxIntLength+1 OF CHAR;
      i: LONGINT;
    BEGIN
      IntStr.IntToStr(int, str);
      i := 0;
      WHILE (str[i] # 0X) DO
        b[pos] := str[i]; INC(i); INC(pos);
      END;
    END AppendInt;
  
  PROCEDURE AppendString(str: STRING);
    VAR
      chars: Object.CharsLatin1;
    BEGIN
      chars := str(String).CharsLatin1();
      SYSTEM.MOVE(SYSTEM.ADR(chars^), SYSTEM.ADR(b[pos]), str.length);
      INC(pos, str.length);
    END AppendString;

  PROCEDURE Flush() RAISES IO.Error;
    VAR
      start: LONGINT;
    BEGIN
      start := 0;
      WHILE (start # pos) DO
        INC(start, ch.Write(b, start, pos-start));
      END;
      pos := 0;
    END Flush;
  
  BEGIN
    fileName := dataDir+"/"+group;
    LogMsg("Writing group file "+fileName);
    ch := FileChannel.Open(fileName(String),
                           {FileChannel.write,
                            FileChannel.create,
                            FileChannel.truncate});
    
    pos := 0;
    AppendInt(gd.firstId);
    AppendChar("-");
    AppendInt(gd.lastId);
    AppendChar(eol);
    
    i := 0;
    WHILE (i # gd.headers.size) DO
      header := gd.headers.array[i](Header);
      IF (pos+header.subject.length+(maxIntLength+2) > LEN(b)) THEN
        Flush;
      END;
      
      AppendInt(header.msgId);
      AppendChar(headerSep);
      AppendString(header.subject);
      AppendChar(eol);
      INC(i);
    END;
    Flush();
    ch.Close();
  END WriteGroupData;

PROCEDURE ReduceGroupData(gd: GroupData; first, last: LONGINT): LONGINT;
  VAR
    removed, i: LONGINT;
    headers: ArrayList.ArrayList;
  BEGIN
    headers := gd.headers;
    i := 0;
    WHILE (i # headers.size) &
          (headers.array[i](Header).msgId < first) DO
      INC(i);
    END;
    headers.RemoveRange(0, i);
    removed := i;

    i := headers.size;
    WHILE (i # 0) & (headers.array[i-1](Header).msgId > last) DO
      DEC(i);
    END;
    INC(removed, headers.size-i);
    headers.RemoveRange(i, headers.size);

    IF (first > gd.firstId) THEN
      gd.firstId := first;
    END;
    IF (last < gd.lastId) THEN
      gd.lastId := last;
    END;
    IF (gd.firstId > gd.lastId) THEN
      gd.firstId := 0;
      gd.lastId := 0;
    END;
    RETURN removed;
  END ReduceGroupData;

PROCEDURE AppendXHdr(gd: GroupData; req: NNTP.XHdr; last: LONGINT)
RAISES IO.Error, NNTP.ProtocolError;
  VAR
    text: NNTP.Text;
    headers: ArrayList.ArrayList;
    prevId, pos, start, end: LONGINT;
    header: Header;
  BEGIN
    prevId := gd.lastId;
    headers := gd.headers;
    REPEAT
      text := nntpClient.RetrieveText();

      pos := 0;
      WHILE (pos # text.length) DO
        NEW(header);
        req.ParseLine(text, pos, header.msgId, start, end);
        ASSERT (prevId < header.msgId);
        prevId := header.msgId;
        header.subject := Normalize(text.data, start, end);

        headers.Append(header);
      END;
    UNTIL text.last;
    gd.lastId := last;
  END AppendXHdr;

PROCEDURE FilterGroupData(gd: GroupData;
                          select, exclude: StringSearch.Matcher);
  VAR
    i: LONGINT;
    str: STRING;
    header: Header;
    headers, selected: ArrayList.ArrayList;
  BEGIN
    selected := ArrayList.New(128);
    
    headers := gd.headers;
    i := 0;
    WHILE (i # headers.size) DO
      header := headers.array[i](Header);
      str := header.subject;
      IF (select.Search(str(String), 0, str.length) # NIL) &
         (exclude.Search(str(String), 0, str.length) = NIL) THEN
        selected.Append(header);
      END;
      INC(i);
    END;

    Err.String("Subject matches: "); Err.LongInt(selected.size, 0);
    Err.String(" of "); Err.LongInt(headers.size, 0); Err.Ln;
    gd.headers := selected;
  END FilterGroupData;

PROCEDURE StripPartIndicator(string: String;
                             VAR part, total: LONGINT): String;
  VAR
    c: Object.CharsLatin1;
    i, endOfPart, startOfPart: LONGINT;
    end: CHAR;
    sep: BOOLEAN;
    norm: STRING;
    
  PROCEDURE SkipNumber(): LONGINT;
    CONST
      maxLengthInt = 16;
    VAR
      end: LONGINT;
      str: ARRAY maxLengthInt+1 OF CHAR;
      j, h: LONGINT;
      res: IntStr.ConvResults;
    BEGIN
      end := i;
      WHILE (i # 0) & CharClass.IsNumeric(c[i-1]) DO
        DEC(i);
      END;
      IF (i < end) & (end-i < maxLengthInt) THEN
        j := i; h := 0;
        WHILE (j # end) DO
          str[h] := c[j]; INC(h); INC(j);
        END;
        str[h] := 0X;
        IntStr.StrToInt(str, j, res);
        IF (res = IntStr.strAllRight) THEN
          RETURN j;
        END;
      END;
      RETURN -1;
    END SkipNumber;
  
  PROCEDURE SkipWhitespace();
    BEGIN
      WHILE (i # 0) & (c[i-1] <= " ") DO
        DEC(i);
      END;
    END SkipWhitespace;
  
  BEGIN
    c := string.CharsLatin1();
    i := string.length;
    WHILE (i # 0) DO
      WHILE (i # 0) & (c[i-1] # ")") & (c[i-1] # "]") DO
        DEC(i);
      END;

      IF (i # 0) THEN
        DEC(i);
        CASE c[i] OF
        | ")": end := "("
        | "]": end := "["
        END;
        SkipWhitespace;
        total := SkipNumber();
        IF (total >= 0) THEN
          SkipWhitespace;

          sep := TRUE;
          IF (i # 0) & (c[i-1] = "/") THEN
            DEC(i);
          (*ELSIF (i > 1) & (c[i-1] = "f") & (c[i-2] = "o") THEN
            DEC(i, 2);*)
          ELSE
            sep := FALSE;
          END;

          IF sep THEN
            SkipWhitespace;
            endOfPart := i;
            part := SkipNumber();
            IF (part >= 0) THEN
              startOfPart := i;
              SkipWhitespace;
              IF (i # 0) & (c[i-1] = end) THEN
                DEC(i);
                norm := string.Substring(0, startOfPart)+"#"+
                    string.Substring(endOfPart, string.length);
                RETURN norm(String);
              END;
            END;
          END;
        END;
      END;
    END;

    (* no match: assume 1/1 *)
    part := 1; total := 1;
    RETURN string;
  END StripPartIndicator;

PROCEDURE CreateFiles(gd: GroupData): FileList;
  VAR
    i, part, total: LONGINT;
    str: String;
    header: Header;
    headers: ArrayList.ArrayList;
    files: Dictionary.Dictionary;
    obj: Object.Object;
    file: File;
    values: Object.ObjectArrayPtr;
    fileList: FileList;
    
  PROCEDURE NewFile(subject: String; total: LONGINT): File;
    VAR
      file: File;
      i: LONGINT;
    BEGIN
      NEW(file);
      file.subject := subject;
      file.total := total;
      file.present := 0;
      NEW(file.msgIds, total);
      FOR i := 0 TO total-1 DO
        file.msgIds[i] := -1;
      END;
      RETURN file;
    END NewFile;

  PROCEDURE AddArticle(file: File; part: LONGINT; msgId: LONGINT);
    VAR
      i: LONGINT;
    BEGIN
      IF (1 <= part) & (part <= file.total) THEN
        i := part-1;
        IF (file.msgIds[i] < 0) THEN
          INC(file.present);
        END;
        file.msgIds[i] := msgId;
      END;
    END AddArticle;
  
  BEGIN
    headers := gd.headers;
    files := Dictionary.New();
    
    i := 0;
    WHILE (i # headers.size) DO
      header := headers.array[i](Header);
      str := StripPartIndicator(header.subject, part, total);
      
      IF files.HasKey(str) THEN
        obj := files.Get(str);
        file := obj(File);
      ELSE
        file := NewFile(str, total);
        files.Set(str, file);
      END;
      ASSERT(file.total = total);
      AddArticle(file, part, header.msgId);
      
      INC(i);
    END;

    values := files.Values();
    Arrays.Sort(values^, 0, LEN(values^), cmpFile);
    
    NEW(fileList, LEN(values^));
    FOR i := 0 TO LEN(values^)-1 DO
      fileList[i] := values[i](File);
    END;
    RETURN fileList;
  END CreateFiles;

PROCEDURE AddToHistory(file: File) RAISES IO.Error;
  VAR
    b: StringBuffer.StringBuffer;
    c: StringBuffer.CharsLatin1;
    i: LONGINT;
  BEGIN
    b := StringBuffer.New("");
    b.Append(group);
    b.AppendLatin1(": ");
    b.Append(file.subject);
    b.AppendLatin1Char(eol);
    c := b.CharsLatin1();
    i := 0;
    WHILE (i # b.length) DO
      INC(i, historyChannel.Write(c^, i, b.length-i));
    END;
    history.Set(file.subject, NIL);
  END AddToHistory;

PROCEDURE DownloadFiles(fileList: FileList)
RAISES IO.Error, NNTP.ProtocolError, NNTP.ErrorResponse;
  VAR
    i, j, status: LONGINT;
    file: File;
    article: NNTP.Article;
    e: Exception.Exception;
  BEGIN
    FOR i := 0 TO LEN(fileList^)-1 DO
      file := fileList[i];
      IF history.HasKey(file.subject) THEN
        Err.String("Skipping "); Err.Object(file.subject);
        Err.String(" (already downloaded)"); Err.Ln;
      ELSIF forceIncomplete OR (file.present = file.total) THEN
        Err.String("Downloading: "); Err.Object(file.subject); Err.Ln;
        TRY
          FOR j := 0 TO file.total-1 DO
            IF (file.msgIds[j] >= 0) THEN
              article := nntpClient.Article(file.msgIds[j]);
              REPEAT
                text := nntpClient.RetrieveText();
                dumpTarget.WriteBytes(text.data, 0, text.length);
                ASSERT(dumpTarget.res = Channel.done);
              UNTIL text.last;
            END;
          END;
          AddToHistory(file);
        CATCH NNTP.ErrorResponse:
          e := Exception.Current();
          status := e(NNTP.ErrorResponse).request.response.status;
          IF (status = 423) OR (status = 430) THEN
            Err.String("Missing article, aborting download"); Err.Ln;
          ELSE
            RAISE(e(NNTP.ErrorResponse));
          END;
        END;
      ELSE
        Err.String("Incomplete file ("); Err.LongInt(file.present, 0);
        Err.String(" of "); Err.LongInt(file.total, 0); Err.String("): ");
        Err.Object(file.subject); Err.Ln;
      END;
    END;
  END DownloadFiles;

PROCEDURE ReadHistory(VAR history: Dictionary.Dictionary): IO.ByteChannel
RAISES IO.Error;
  CONST
    sizeBuffer = 8*1024;
  VAR
    fileName: String;
    ch: IO.ByteChannel;
    b: ARRAY sizeBuffer OF CHAR;
    end, pos, start, sep, r, i: LONGINT;
    str: String;
  BEGIN
    fileName := "__download_history__";
    LogMsg("Reading history file "+fileName);
    TRY
      ch := FileChannel.OpenUnbuffered(fileName,
                                       {FileChannel.read, FileChannel.write,
                                        FileChannel.append});
    CATCH IO.FileNotFound:
      Error("File does not exist.  Do `touch "+fileName+"' first.");
    END;
    
    history := Dictionary.New();
    pos := 0; end := 0;
    LOOP
      r := ch.Read(b, pos, LEN(b)-pos);
      IF (r < 0) THEN
        IF (pos # 0) THEN
          Error("Incomplete line at end of "+fileName);
        END;
        EXIT;
      ELSE
        INC(end, r);
        start := 0;
        WHILE (pos # end) DO
          WHILE (pos # end) & (b[pos] # eol) DO
            INC(pos);
          END;
          IF (pos # end) THEN            (* found end of line *)
            sep := start;
            WHILE (sep < end-1) & ((b[sep] # ":") OR (b[sep+1] # " ")) DO
              INC(sep);
            END;
            
            ASSERT(sep < end-1);
            str := Object.NewLatin1Region(b, start, sep);
            IF str.Equals(group) THEN
              str := Object.NewLatin1Region(b, sep+2, pos);
              history.Set(str, NIL);
            END;
            INC(pos);
            start := pos;
          END;
        END;

        (* move unprocessed data to beginning of buffer *)
        FOR i := start TO end-1 DO
          b[i-start] := b[i];
        END;
        DEC(end, start);
        pos := end;
      END;
    END;
    
    Err.String("Matches in history file: "); Err.LongInt(history.Size(), 0);
    Err.Ln;
    RETURN ch;
  END ReadHistory;

BEGIN  <*Warnings:=FALSE*>
  NEW(cmpFile);
  Comparator.Init(cmpFile);

  nntpServer := NntpServer();
  dataDir := HomeDir()+"/.gi_headers/"+nntpServer;
  dumpTarget := StdChannels.stdout.NewWriter();
  GetConfig();
  gd := ReadGroupData(group);
  historyChannel := ReadHistory(history);
  
  nntpClient := NewClient(serverAddr, FALSE);
  nntpClient.Connect();

  reqGroup := nntpClient.Group(group);
  removed := ReduceGroupData(gd, reqGroup.first, reqGroup.last);
  Err.String("Removed subjects: "); Err.LongInt(removed, 0); Err.Ln;

  IF (gd.lastId < reqGroup.last) THEN
    reqXHdr := nntpClient.XHdr("subject", gd.lastId+1, reqGroup.last);
    AppendXHdr(gd, reqXHdr, reqGroup.last);
    
    WriteGroupData(gd);
  END;

  FilterGroupData(gd, selectSubjects, excludeSubjects);
  fileList := CreateFiles(gd);
  DownloadFiles(fileList);

  reqQuit := nntpClient.Quit();
  nntpClient.Close();
  historyChannel.Close();
END gi.
