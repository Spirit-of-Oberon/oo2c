MODULE IO:SocketChannel;

IMPORT
  SYSTEM, IO, IO:Address, IO:Socket,
  <*PUSH; Warnings:=FALSE*>IO:FileChannel<*POP*>;
  
TYPE
  Channel* = POINTER TO ChannelDesc;
  ChannelDesc = RECORD
    (IO.ByteChannelDesc)
    socket-: Socket.Socket;
    connected-: BOOLEAN;
    connectionPending-: BOOLEAN;
  END;

TYPE
  ServerChannel* = POINTER TO ServerChannelDesc;
  ServerChannelDesc = RECORD
    (IO.ChannelDesc)
    socket-: Socket.Server;
  END;

PROCEDURE (ch: Channel) SetBlocking*(block: BOOLEAN) RAISES IO.Error;
  BEGIN
    ch.socket.SetBlocking(block);
  END SetBlocking;

PROCEDURE (ch: Channel) Connect*(endPoint: Address.Socket): BOOLEAN
RAISES IO.Error;
  BEGIN
    ch.socket.Connect(endPoint);
    ch.connected := TRUE;
    RETURN TRUE;  (* no nonblocking for now *)
  END Connect;

PROCEDURE (ch: Channel) FinishConnect*(): BOOLEAN;
  BEGIN  (* not implemented yet *)
  END FinishConnect;

PROCEDURE (ch: Channel) Read*(VAR buffer: ARRAY OF SYSTEM.BYTE;
                                start, length: LONGINT): LONGINT
RAISES IO.Error;
  VAR
    res: LONGINT;
  BEGIN
    res := Socket.Read(ch.socket, buffer, start, length);
    IF (res = 0) & (length # 0) THEN
      EXCL(ch.readyOps, IO.opRead);
    END;
    RETURN res;
  END Read;
  
PROCEDURE (ch: Channel) Write*(buffer[NO_COPY]: ARRAY OF SYSTEM.BYTE;
                                 start, length: LONGINT): LONGINT
RAISES IO.Error;
  VAR
    res: LONGINT;
  BEGIN
    res := Socket.Write(ch.socket, buffer, start, length);
    IF (res = 0) & (length # 0) THEN
      EXCL(ch.readyOps, IO.opWrite);
    END;
    RETURN res;
  END Write;
  
PROCEDURE (ch: Channel) Close*() RAISES IO.Error;
  BEGIN
    ch.Close^();
    ch.socket.Close();
  END Close;

PROCEDURE Open*(): Channel RAISES IO.Error;
  VAR
    ch: Channel;
  BEGIN
    NEW(ch);
    ch.socket := Socket.New();
    IO.InitByteChannel(ch);
    ch.connected := FALSE;
    ch.connectionPending := FALSE;
    RETURN ch;
  END Open;

PROCEDURE Connect*(remote: Address.Socket): Channel
  RAISES IO.Error;
  VAR
    ch: Channel;
    done: BOOLEAN;
  BEGIN
    ch := Open();
    done := ch.Connect(remote);
    RETURN ch;
  END Connect;

PROCEDURE (ch: Channel) FileDescriptor*(): IO.FileDescriptor;
  BEGIN
    RETURN ch.socket.fd;
  END FileDescriptor;



PROCEDURE OpenServer*(): ServerChannel RAISES IO.Error;
  VAR
    ch: ServerChannel;
  BEGIN
    NEW(ch);
    ch.socket := Socket.NewServer();
    IO.InitChannel(ch);
    RETURN ch;
  END OpenServer;

PROCEDURE (ch: ServerChannel) SetBlocking*(block: BOOLEAN) RAISES IO.Error;
  BEGIN
    ch.socket.SetBlocking(block);
  END SetBlocking;

PROCEDURE (ch: ServerChannel) Accept*(): Channel RAISES IO.Error;
(**Accepts a connection request from a remote socket.

   On success, result is a channel for the incoming connection.  If the server
   socket is in non-blocking more, and there are no more pending connections,
   then result is @code{NIL}.  An error raises an exception of type
   @otype{IO.Error}.  *)
  VAR
    client: Channel;
    socket: Socket.Socket;
  BEGIN
    socket := ch.socket.Accept();
    IF (socket = NIL) THEN
      EXCL(ch.readyOps, IO.opAccept);
      RETURN NIL;
    ELSE
      NEW(client);
      IO.InitChannel(client);
      client.socket := socket;
      client.connected := TRUE;
      client.connectionPending := FALSE;
      RETURN client;
    END;
  END Accept;

PROCEDURE (ch: ServerChannel) FileDescriptor*(): IO.FileDescriptor;
  BEGIN
    RETURN ch.socket.fd;
  END FileDescriptor;

END IO:SocketChannel.
