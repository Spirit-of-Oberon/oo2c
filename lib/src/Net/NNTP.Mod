MODULE Net:NNTP;

IMPORT
  SYS:=SYSTEM, Ascii, CharClass, IntStr, Object,
  ADT:StringBuffer, IO, IO:Address, IO:SocketChannel;

(**This module implements the client side of the NNTP protocol.  It supports
   three modes of operation:

   @table @asis
   @item Synchronous Operation
   One request is send to the NNTP server, and the whole response is retrieved
   before sending the next request.  That is, at most one request is in
   progress at any point in time.  For example, a call to @oproc{Client.Group}
   sends a @samp{group} request returns only if the response has arrived and
   its data has been stored in the @otype{Group} object.  This mode is the
   easiest to use.

   @item Asynchronous Operation
   A sequence of requests can be send to the NNTP server, before starting to
   retrieve the responses for the requests.  This allows to launch multiple
   requests back to back, following by reading the responses back to back.  For
   example, a call to @oproc{Client.Group} writes out the @samp{group} command
   to the NNTP server and returns without looking for a response.  The response
   must be read by a separate call to @oproc{Client.RetrieveResponse}.  The
   advantage of this approach is that it hides most of the latency incurred by
   a sequence of requests, because the server can process them back to back,
   without waiting for the next request to arrive.

   Stuffing too many or too large requests into the pipeline before reading any
   responses may lead to a deadlock, though.  For most applications, the
   benefits compared to the simple synchronous mode are small.

   @item Non-blocking Asynchronous Operation
   This is the most complicated usage scenario.  The client's socket is
   switched to non-blocking mode and data is send to or received from the
   server as availability allows.  This requires that the application runs a
   @otype{IO.Selector} loop that detects if data has arrived for reading on the
   client's socket, or if more data can be written to the socket.  @dots{}
   @end table  *)
  
CONST
  inputBufferCapacity = 4*1024;  (* must be larger than longest line *)
  outputBufferCapacity = 4*1024; (* must be larger than 3 *)
  textCapacity = 8*1024-32;
  maxLineLength = inputBufferCapacity-2;
  (* To be precise, the maximum length of a line of input excluding the CRLF
     suffix is min(textCapacity,inputBufferCapacity)-2.  *)
  defaultPort* = 119;
  
TYPE
  Msg = POINTER TO MsgDesc;
  MsgDesc = RECORD
    nextMsg: Msg;
  END;
  
TYPE
  Response* = POINTER TO ResponseDesc;
  ResponseDesc = RECORD
    (**Represents an NNTP response.  *)
    (MsgDesc)
    statusLine-: Object.String8;
    (**The first line of the response, as received from the NNTP server.
       The end of line characters have been stripped.  *)
    status-: LONGINT;
    (**The integer status code.  *)
    long-: BOOLEAN;
    (**If @code{TRUE}, then the response includes a message body.  The body's
       data is obtained by calling @oproc{Client.RetrieveText}, possibly
       repeatedly.  *)
  END;

TYPE
  Request = POINTER TO RequestDesc;
  RequestDesc = RECORD [ABSTRACT]
    (**Represents an NNTP request.  *)
    (MsgDesc)
    command: Object.String8;
    long: BOOLEAN;
    response-: Response;
    (* Refers to the associated response object, once it has been received.
       Until then, this field is @code{NIL}.  *)
  END;

TYPE
  Text* = POINTER TO TextDesc;
  TextDesc = RECORD
    (**A chunk of text data of a long response or a long request.  *)
    (MsgDesc)
    length*: LONGINT;
    (**Number of valid characters in @ofield{data}.  A number in the range
       @samp{0 <= @ofield{length} <= LEN(@ofield{data})}.  *)
    last*: BOOLEAN; 
    (**If @code{TRUE}, then this chunk is the last part of the response or
       request.  For a request, this means that the message is complete and
       must terminted with a single @samp{.} (dot) on a line by itself.  For a
       response, it means that no further text data follows.  *)
    data*: ARRAY textCapacity OF CHAR;
    (**Text data.  A number of lines, using @oconst{eol} as their end of
       line marker.  The class @otype{Client} is responsible for encoding this
       data for NNTP's over the wire protocol (that is, using CRLF at end of
       line, doubling a @samp{.} at the beginning of the line, and closing
       a long message with a @samp{.} on a line by itself).  *)
  END;
  
TYPE
  Client* = POINTER TO ClientDesc;
  Connect = POINTER TO ConnectDesc;
  ClientDesc* = RECORD
    serverAddr-: Address.SocketInet;
    
    async-: BOOLEAN;
    (**If @code{FALSE}, connects and requests are processed synchronously.  A
       method issuing a request returns only if the status line of the response
       has been received.  Note: The interface for requests that include a text
       part is more complicated than this.

       In asynchronous mode, requests are queued for processing and the
       initiating method returns immediately after sending the command line to
       the server.  To get the request's response, the application must call
       @oproc{Client.RetrieveResponse}.  *)
    blocking-: BOOLEAN;
    (**If @code{FALSE}, then the socket is switched to non-blocking mode.  If a
       @oproc{Client.RetrieveResponse} or @oproc{Client.RetrieveText} operation
       discovers that no more input is available, or if an operation writes to
       the socket and there is no more room in the kernel buffers, then it
       returns immediately.  *)

    welcome-: Object.String8;
    (**The text received from the server after connecting.  *)
    
    connectRequest-: Connect;
    (**When running in asynchronous mode, @oproc{Client.Connect} stores here
       the pseudo request whose reply is the server's @samp{Welcome} message.
       In synchronous mode, this field is @code{NIL}.  *)
    
    postingAllowed-: BOOLEAN;
    (**Set to @code{TRUE} if the server's welcome message indicates that
       it allows posting.  *)
    
    channel: SocketChannel.Channel;
    
    rLen: LONGINT;    (* number of valid bytes in `r'; 0<=rLen<=LEN(r) *)
    rLine: LONGINT;   (* start of current line; 0<=rLine<=rLen *)
    rPos: LONGINT;    (* current scanning position; rLine<=rPos<=rLen *)
    rText: Text;      (* if #NIL: rLine is in text part of a response *)
    sPos: LONGINT;    (* position of first unsend char in `waiting' *)
    sLen: LONGINT;    (* number of valid bytes in `s'; 0<=sLen<=LEN(s) *)
    r: ARRAY inputBufferCapacity OF CHAR;
    s: ARRAY outputBufferCapacity OF CHAR;
    waiting: Msg;
    (* List of messages or text fragments that have not been transferred into
       the output buffer @ofield{s} yet, and, by implication, have not been
       sent to the server.  @oproc{Client.SendRequest} adds messages to this
       queue, and @oproc{FillSBuffer} removes them when all their data
       has been copied to @ofield{s}.  *)
    sent: Msg;
    (* List of messages that have been moved to the output buffer @ofield{s},
       for which reply's status line has not been read yet.
       @oproc{FillSBuffer} adds a message to this list once all its data has
       been transferred to @ofield{s}, and @oproc{Client.RetrieveResponse}
       removes a message if its complete status line (but not the message body)
       has been read and parsed.  This field is initialized with a list
       containing a pseudo request whose response is the server's welcome
       message.  *)
  END;

TYPE
  ErrorResponse* = POINTER TO ErrorResponseDesc;
  ErrorResponseDesc = RECORD
  (**Raised if the response from the server indicates an error.  All status
     code @samp{3xx}, @samp{4xx}, and @samp{5xx} trigger this exception.  This
     means that associated request has been processed, with a negative
     outcome.  The complete response can be accessed through
     @ofield{request}'s response entry.  *)
    (IO.ErrorResponseDesc)
    request-: Request;
  END;

(* Request Classes
   ------------------------------------------------------------------------ *)
  
TYPE
  ConnectDesc = RECORD
    (RequestDesc) 
  END;
  
TYPE
  Group* = POINTER TO GroupDesc;
  GroupDesc = RECORD
    (RequestDesc)
    msgCount-, first-, last-: LONGINT;
    name-: Object.String8;
  END;
  
TYPE
  XHdr* = POINTER TO XHdrDesc;
  XHdrDesc = RECORD
    (RequestDesc)
    msgCount-, first-, last-: LONGINT;
    name-: Object.String8;
  END;
  
TYPE
  Article* = POINTER TO ArticleDesc;
  ArticleDesc = RECORD
    (RequestDesc)
  END;
  
TYPE
  Quit* = POINTER TO QuitDesc;
  QuitDesc = RECORD
    (RequestDesc)
  END;
  

CONST
  eol* = Ascii.lf;
  respXHDR = 221;
  respARTICLE =220;

PROCEDURE (cl: Client) LogRequest*(cmd: Object.String8);
  END LogRequest;

PROCEDURE (cl: Client) LogResponse*(statusLine: Object.String8);
  END LogResponse;

PROCEDURE (msg: Msg) INIT*();
  BEGIN
    msg.nextMsg := NIL;
  END INIT;

PROCEDURE NewText*(): Text;
  VAR
    t: Text;
  BEGIN
    NEW(t);
    t.INIT();
    t.length := 0;
    t.last := FALSE;
    RETURN t;
  END NewText;

PROCEDURE (req: Request) INIT*(cmd: Object.String8; long: BOOLEAN);
  BEGIN
    req.INIT^();
    req.command := cmd;
    req.long := long;
    req.response := NIL;
  END INIT;

PROCEDURE (req: Request) ParseStatus(resp: Response)
RAISES IO.ProtocolError;
(**Parse the status line of the response and incorporate its data into the
   request handle @oparam{req}.  *)
  BEGIN
  END ParseStatus;

PROCEDURE (resp: Response) INIT*(VAR b: ARRAY OF CHAR;
                                 start, end: LONGINT;
                                 status: LONGINT; long: BOOLEAN);
  BEGIN
    resp.INIT^();
    resp.statusLine := Object.NewLatin1Region(b, start, end);
    resp.status := status;
    resp.long := long;
  END INIT;

PROCEDURE NewResponse(VAR b: ARRAY OF CHAR; start, end: LONGINT;
                      status: LONGINT; long: BOOLEAN): Response;
  BEGIN
    RETURN NEW(Response, b, start, end, status, long);
  END NewResponse;

PROCEDURE (cl: Client) INIT*(serverAddr: Address.SocketInet;
                             async, blocking: BOOLEAN);
  BEGIN
    cl.serverAddr := serverAddr;
    cl.async := async;
    cl.blocking := blocking;
    cl.welcome := NIL;
    cl.connectRequest := NIL;
    cl.postingAllowed := FALSE;
    cl.channel := NIL;
  END INIT;

PROCEDURE NewClient*(serverAddr: Address.SocketInet;
                     async, blocking: BOOLEAN): Client;
  BEGIN
    RETURN NEW(Client, serverAddr, async, blocking);
  END NewClient;

PROCEDURE Append(VAR list: Msg; msg: Msg);
  VAR
    ptr: Msg;
  BEGIN
    msg.nextMsg := NIL;
    IF (list = NIL) THEN
      list := msg;
    ELSE
      ptr := list;
      WHILE (ptr.nextMsg # NIL) DO
        ptr := ptr.nextMsg;
      END;
      ptr.nextMsg := msg;
    END;
  END Append;

PROCEDURE FillSBuffer(cl: Client);
  VAR
    msg, ptr: Msg;
    chars: Object.CharsLatin1;
    pos, copy, len, left: LONGINT;
  BEGIN
    pos := cl.sPos; len := cl.sLen;
    LOOP
      msg := cl.waiting;
      WITH msg: Request DO
        chars := msg.command.CharsLatin1();
        copy := msg.command.length-pos;
        left := LEN(cl.s)-len;
        IF (copy+2 > left) THEN
          (* command line doesn't fit into buffer: copy as much as possible
             and leave loop *)
          IF (left < copy) THEN
            copy := left;
          END;
          SYS.MOVE(SYS.ADR(chars^)+pos, SYS.ADR(cl.s)+len, copy);
          INC(pos, copy);
          INC(len, copy);
          EXIT;
        ELSE  (* rest of command plus CRLF fits into buffer *)
          SYS.MOVE(SYS.ADR(chars^)+pos, SYS.ADR(cl.s)+len, copy);
          INC(len, copy);
          cl.s[len] := Ascii.cr;
          cl.s[len+1] := Ascii.lf;
          INC(len, 2);
          
          cl.LogRequest(msg.command);
          ptr := cl.waiting;
          cl.waiting := cl.waiting.nextMsg;
          Append(cl.sent, ptr);
          pos := 0;
          IF (cl.waiting = NIL) THEN
            EXIT;
          END;
        END;
      ELSE
        ASSERT(FALSE);
      END;
    END;
    cl.sPos := pos; cl.sLen := len;
  END FillSBuffer;

PROCEDURE SendMsg(cl: Client)
RAISES IO.Error;
  VAR
    start, len: LONGINT;
  BEGIN
    ASSERT(cl.blocking);
    WHILE (cl.waiting # NIL) DO
      FillSBuffer(cl);
      
      len := cl.sLen;
      start := 0;
      WHILE (start # len) DO
        INC(start, cl.channel.Write(cl.s, start, len-start));
      END;
      cl.sLen := 0;
    END;
  END SendMsg;

PROCEDURE (cl: Client) SendRequest(req: Request)
RAISES IO.Error;
  BEGIN
    Append(cl.waiting, req);
    SendMsg(cl);
  END SendRequest;

PROCEDURE (cl: Client) SendText(text: Text);
  BEGIN
    ASSERT(FALSE);
  END SendText;

PROCEDURE ExtractStatus(cl: Client; start, end: LONGINT): Response
RAISES IO.ProtocolError;
(**Create response object from the text of the status line
   @samp{cl.r[start,end[}.  *)
  VAR
    status: LONGINT;
    long: BOOLEAN;
    resp: Response;
  BEGIN
    IF (end-start >= 3) &
       CharClass.IsNumeric(cl.r[start]) &
       CharClass.IsNumeric(cl.r[start+1]) &
       CharClass.IsNumeric(cl.r[start+2]) &
       ((end-start = 3) OR (cl.r[start+3] <= " ")) THEN
      status := (ORD(cl.r[start])-ORD("0"))*100+
          (ORD(cl.r[start+1])-ORD("0"))*10+
          (ORD(cl.r[start+2])-ORD("0"));
      long := (status=respXHDR) OR (status=respARTICLE);
      IF long THEN
        cl.rText := NewText();
      END;
      resp := NewResponse(cl.r, start, end, status, long);
      RETURN resp;
    ELSE
      RAISE(NEW(IO.ProtocolError, "No status code: "+
                Object.NewLatin1Region(cl.r, start, end)));
    END;
  END ExtractStatus;

PROCEDURE GetMsg(cl: Client): Msg
RAISES IO.Error;
(**Retrieves the next response or chunk of text from the socket.  Undos NNTP
   encoding (CRLF -> LF, ".." --> "." at beginning of line).  Beyond a basic
   check that the status line of a response begins with a 3 digit code, no
   parsing is done.

   Result is only @code{NIL} if the client's socket is in non-blocking mode
   and not a single complete line can be assembled before a read operation
   on the socket returns @samp{EWOULDBLOCK}.  *)
  VAR
    line, pos, len, end, i, copy: LONGINT;
    msg: Msg;
  BEGIN
    line := cl.rLine; pos := cl.rPos; len := cl.rLen;
    
    LOOP
      (* pre: line is the starting position of the current line *)
      WHILE (pos # len) & (cl.r[pos] # Ascii.lf) DO
        INC(pos);
      END;

      IF (pos # len) THEN  (* we reached the end of a complete line *)
        (* make `end' point at the beginning of the eol sequence *)
        end := pos;
        IF (end > line) & (cl.r[end-1] = Ascii.cr) THEN
          DEC(end);
        END;

        (* here holds: r[line,end[ holds a complete line of data, minus eol *)
        IF (cl.rText # NIL) THEN
          IF (end = line+1) & (cl.r[line] = ".") THEN (* end of text *)
            cl.rText.last := TRUE;
            msg := cl.rText;
            cl.rText := NIL;
            INC(pos); line := pos;
            EXIT;
          ELSE                           (* line of text *)
            IF (cl.r[line] = ".") & (cl.r[line+1] = ".") THEN
              INC(line);    (* undo double "." at beginning of line *)
            END;
            IF (cl.rText.length+(end-line)+1 > LEN(cl.rText.data))  THEN
              (* line does not fit into current text block *)
              IF (end-line > maxLineLength) THEN
                RAISE(NEW(IO.ProtocolError, "Line too long"));
              ELSE
                cl.rText.last := FALSE;
                msg := cl.rText;
                cl.rText := NewText();
                EXIT;
              END;
            ELSE
              copy := end-line;
              SYS.MOVE(SYS.ADR(cl.r)+line,
                       SYS.ADR(cl.rText.data)+cl.rText.length,
                       end-line);
              INC(cl.rText.length, copy);
              cl.rText.data[cl.rText.length] := eol;
              INC(cl.rText.length);
              INC(pos); line := pos;
            END;
          END;
        ELSE                             (* status line of response *)
          msg := ExtractStatus(cl, line, end);
          cl.LogResponse(msg(Response).statusLine);
          INC(pos); line := pos;
          EXIT;
        END;

      ELSE
        (* no data or incomplete line: move remaining data to beginning
           of buffer and read more from the socket *)
        FOR i := line TO len-1 DO
          cl.r[i-line] := cl.r[i];
        END;
        DEC(pos, line);
        DEC(len, line);
        line := 0;
        i := cl.channel.Read(cl.r, len, LEN(cl.r)-len);
        IF (i = 0) THEN  (* no more data available from non-blocking socket *)
          msg := NIL;
          EXIT;
        ELSE (* have new data: try again to assemble a complete line  *)
          ASSERT(i > 0);
          INC(len, i);
        END;
      END;
    END;

    cl.rLine := line; cl.rPos := pos; cl.rLen := len;
    RETURN msg;
  END GetMsg;

PROCEDURE (cl: Client) RetrieveResponse*(req: Request): Response
RAISES IO.Error, ErrorResponse;
(**Retrieve the status line of the next pending request.
   
   Result is only @code{NIL} if the client's socket is in non-blocking mode
   and not a single complete line can be assembled before a read operation
   on the socket returns @samp{EWOULDBLOCK}.  *)
  VAR
    msg: Msg;
    resp: Response;
    e: ErrorResponse;
  BEGIN
    msg := GetMsg(cl);
    IF (msg = NIL) THEN
      RETURN NIL;
    ELSE
      resp := msg(Response);
      
      IF (cl.sent = NIL) THEN
        RAISE(NEW(IO.ProtocolError,
                  "Response without prior request: "+resp.statusLine));
      ELSE
        ASSERT(req = cl.sent);
        req.response := resp;
        cl.sent := cl.sent.nextMsg;
        IF (resp.status >= 300) THEN     (* negative response *)
          NEW(e);
          e.INIT(resp.statusLine);
          e.request := req;
          RAISE(e);
        ELSIF (req IS Connect) THEN (* special case: welcome message *)
          cl.welcome := resp.statusLine;
          cl.postingAllowed := (resp.status = 200);
        ELSE                            (* request specific parsing *)
          req.ParseStatus(resp);
        END;
      END;
      RETURN resp;
    END;
  END RetrieveResponse;

PROCEDURE (cl: Client) RetrieveText*(): Text
RAISES IO.Error;
(**Retrieves the next text chunk of the current response.  The chunk contains
   an integral number of lines.  That is, it is either empty, or the first
   character of the chunk is the first of a line and character
   @samp{text.data[text.length-1]} is @oconst{eol}.

   Result is only @code{NIL} if the client's socket is in non-blocking mode
   and not a single complete line can be assembled before a read operation
   on the socket returns @samp{EWOULDBLOCK}.
   
   @precond
   The current response is of type ``long'', and no text chunk has been
   retrieved with a @ofield{Text.last} of @code{TRUE}.
   @end precond  *)
  VAR
    msg: Msg;
  BEGIN
    msg := GetMsg(cl);
    IF (msg = NIL) THEN
      RETURN NIL;
    ELSE
      RETURN msg(Text);
    END;
  END RetrieveText;

PROCEDURE (cl: Client) Connect*()
RAISES IO.Error, ErrorResponse;
(**Initiate a connection to the NNTP server.  In synchronous mode, this method
   retrieves the server's welcome message before returning.  In asynchronous
   mode, it returns immediately and it is the task of the application to call
   @oproc{Client.RetrieveResponse} with @ofield{cl.connectRequest} as argument
   to read the welcome message.  *)
  VAR
    resp: Response;
    connect: Connect;
  BEGIN
    cl.channel := SocketChannel.Connect(cl.serverAddr);
    cl.sPos := 0; cl.sLen := 0;
    cl.rLine := 0; cl.rPos := 0; cl.rLen := 0; cl.rText := NIL;
    cl.waiting := NIL; cl.sent := NIL;

    connect := NEW(Connect, NIL, FALSE);
    cl.sent := connect;
    IF cl.async THEN
      cl.connectRequest := connect;
    ELSE
      resp := cl.RetrieveResponse(connect);
    END;
  END Connect;

PROCEDURE (cl: Client) Close*()
RAISES IO.Error;
  BEGIN
    cl.channel.Close();
    cl.channel := NIL;
  END Close;


PROCEDURE ShortRequest(cl: Client; req: Request)
RAISES IO.Error, ErrorResponse;
  VAR
    resp: Response;
  BEGIN
    ASSERT(~req.long);
    cl.SendRequest(req);
    IF ~cl.async THEN
      resp := cl.RetrieveResponse(req);
    END;
  END ShortRequest;

PROCEDURE SkipWhitespace(params: Object.CharsLatin1; VAR pos: LONGINT);
  BEGIN
    WHILE (params[pos] # 0X) & (params[pos] <= " ") DO
      INC(pos);
    END;
  END SkipWhitespace;

PROCEDURE SkipStatus(params: Object.CharsLatin1): LONGINT;
  VAR
    pos: LONGINT;
  BEGIN
    pos := 3;
    SkipWhitespace(params, pos);
    RETURN pos;
  END SkipStatus;

PROCEDURE GetInt(params: Object.CharsLatin1; VAR pos: LONGINT): LONGINT
RAISES IO.ProtocolError;
  VAR
    str: ARRAY 16 OF CHAR;
    start, i: LONGINT;
    res: IntStr.ConvResults;
  BEGIN
    (* skip any redundant leading zeros *)
    WHILE (params[pos] = "0") & (params[pos+1] = "0") DO
      INC(pos);
    END;
    
    start := pos; i := 0;
    WHILE (params[pos] > " ") DO
      IF (i < LEN(str)-1) THEN
        str[i] := params[pos]; INC(i);
      END;
      INC(pos);
    END;
    str[i] := 0X;
    
    IntStr.StrToInt(str, i, res);
    IF (res # IntStr.strAllRight) THEN
      RAISE(NEW(IO.ProtocolError, "Invalid number"));
    ELSE
      SkipWhitespace(params, pos);
      RETURN i;
    END;
  END GetInt;

PROCEDURE GetString(params: Object.CharsLatin1; VAR pos: LONGINT): Object.String8;
  VAR
    start, e: LONGINT;
  BEGIN
    start := pos;
    WHILE (params[pos] > " ") DO
      INC(pos);
    END;
    e := pos;
    SkipWhitespace(params, pos);
    RETURN Object.NewLatin1Region(params^, start, e);
  END GetString;

(* Commands
   ------------------------------------------------------------------------ *)

PROCEDURE (req: Group) ParseStatus(resp: Response)
RAISES IO.ProtocolError;
  VAR
    params: Object.CharsLatin1;
    pos: LONGINT;
  BEGIN
    params := resp.statusLine.CharsLatin1();
    pos := SkipStatus(params);
    req.msgCount := GetInt(params, pos);
    req.first := GetInt(params, pos);
    req.last := GetInt(params, pos);
    req.name := GetString(params, pos);
  END ParseStatus;

PROCEDURE (cl: Client) Group*(name: STRING): Group
RAISES IO.Error, ErrorResponse;
  VAR
    req: Group;
    cmd: STRING;
  BEGIN
    cmd := "group "+name;
    req := NEW(Group, cmd(Object.String8), FALSE);
    req.msgCount := -1;
    req.first := -1;
    req.last := -1;
    req.name := NIL;
    ShortRequest(cl, req);
    RETURN req;
  END Group;


PROCEDURE (req: XHdr) ParseLine*(text: Text; VAR pos: LONGINT;
                                 VAR msgId, startHeader, endHeader: LONGINT)
RAISES IO.ProtocolError;
  VAR
    str: ARRAY 16 OF CHAR;
    start, i: LONGINT;
    res: IntStr.ConvResults;
  BEGIN
    start := pos; i := 0;
    WHILE (pos # text.length) & CharClass.IsNumeric(text.data[pos]) DO
      IF (i < LEN(str)) THEN
        str[i] := text.data[pos];
      END;
      INC(pos); INC(i);
    END;
    IF (i = LEN(str)) THEN
      RAISE(NEW(IO.ProtocolError, "Message id too long"));
    ELSE
      str[i] := 0X;
      IntStr.StrToInt(str, msgId, res);
      IF (res = IntStr.strAllRight) THEN
        IF (pos # text.length) & (text.data[pos] <= " ") THEN
          INC(pos);
        END;
        startHeader := pos;

        WHILE (pos # text.length) & (text.data[pos] # eol) DO
          INC(pos);
        END;
        endHeader := pos;

        IF (pos # text.length) THEN
          INC(pos);
        END;
      ELSE
        RAISE(NEW(IO.ProtocolError, "Invalid message id"));
      END;
    END;
  END ParseLine;

PROCEDURE (cl: Client) XHdr*(header: STRING; lower, upper: LONGINT): XHdr
RAISES IO.Error, ErrorResponse;
  VAR
    req: XHdr;
    cmd: STRING;
    b: StringBuffer.StringBuffer;
  BEGIN
    b := StringBuffer.New("xhdr ");
    b.Append(header);
    b.AppendLatin1Char(" ");
    b.AppendInt(lower);
    b.AppendLatin1Char("-");
    b.AppendInt(upper);
    cmd := b.ToString();
    
    req := NEW(XHdr, cmd(Object.String8), FALSE);
    ShortRequest(cl, req);
    RETURN req;
  END XHdr;


PROCEDURE (cl: Client) Article*(msgId: LONGINT): Article
RAISES IO.Error, ErrorResponse;
  VAR
    req: Article;
    cmd: STRING;
    b: StringBuffer.StringBuffer;
  BEGIN
    b := StringBuffer.New("article ");
    b.AppendInt(msgId);
    cmd := b.ToString();
    
    req := NEW(Article, cmd(Object.String8), FALSE);
    ShortRequest(cl, req);
    RETURN req;
  END Article;


PROCEDURE (cl: Client) Quit*(): Quit
RAISES IO.Error, ErrorResponse;
  VAR
    req: Quit;
  BEGIN
    req := NEW(Quit, "quit", FALSE);
    ShortRequest(cl, req);
    RETURN req;
  END Quit;

END Net:NNTP.
