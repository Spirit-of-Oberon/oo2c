MODULE IO:Socket [FOREIGN "C"; LINK FILE "Socket.c" END];
<* Warnings := FALSE *>

IMPORT
  SYSTEM, IO, IO:Address, IO:PFD;

TYPE
  Socket* = POINTER TO SocketDesc;
  SocketDesc = RECORD
    (**A socket is an endpoint for TCP communication between two machines.  *)
    fd-: IO.FileDescriptor;
  END;

TYPE
  Server* = POINTER TO ServerDesc;
  ServerDesc = RECORD
    (**A server socket listens for incoming TCP connections.  *)
    fd-: IO.FileDescriptor;
  END;


PROCEDURE New*(): Socket RAISES IO.Error;
(**Create an unconnected socket.  *)

PROCEDURE (s: Socket) SetBlocking*(block: BOOLEAN)
  RAISES IO.Error;
  
PROCEDURE (s: Socket) Bind*(bindPoint: Address.Socket)
  RAISES IO.Error;
(**Bind this socket to a local address.

   If the address is @code{NIL}, then the system will pick up an ephemeral port
   and a valid local address to bind the socket.  *)
  
PROCEDURE (s: Socket) Connect*(endPoint: Address.Socket)
  RAISES IO.Error;
(**Connect this socket to the remote end point.  *)
  
PROCEDURE (s: Socket) RemoteAddress*(): Address.Socket
  RAISES IO.Error;
(**Returns the address of the remove end of a connection.  *)
  
PROCEDURE (s: Socket) Close*()
  RAISES IO.Error;
(**Close this socket.

   Once a socket has been closed, it is not available for further networking
   use.  That is, it can't be reconnected or rebound; a new socket needs to be
   created.  *)


PROCEDURE NewServer*(): Server RAISES IO.Error;
(**Create an unconnected socket.  *)

PROCEDURE (s: Server) SetReuseAddress*(on: BOOLEAN) RAISES IO.Error;
  
PROCEDURE (s: Server) SetBlocking*(block: BOOLEAN) RAISES IO.Error;
  
PROCEDURE (s: Server) Bind*(bindPoint: Address.Socket;
                                  queueSize: LONGINT)
  RAISES IO.Error;
(**Bind this socket to a local address and switch it to listening mode.
   @oparam{queueSize} specifies the length of the queue for pending
   connections.

   If the address is @code{NIL}, then the system will pick up an ephemeral port
   and a valid local address to bind the socket.  *)

PROCEDURE (s: Server) Accept*(): Socket RAISES IO.Error;
(**Accepts a connection request from a remote socket.

   On success, result is the local socket of the connection.  If the server
   socket is in non-blocking more, and there are no more pending connections,
   then result is @code{NIL}.  An error raises an exception of type
   @otype{IO.Error}.  *)

PROCEDURE (s: Server) Close*() RAISES IO.Error;
(**Close this socket.

   Once a socket has been closed, it is not available for further networking
   use.  That is, it can't be reconnected or rebound; a new socket needs to be
   created.  *)


PROCEDURE Read*(s: Socket; VAR buffer: ARRAY OF SYSTEM.BYTE;
                start, length: LONGINT): LONGINT
RAISES IO.Error;
(**Exported for the sake of @omodule{*IO:SocketChannel}.  *)
  
PROCEDURE Write*(s: Socket; buffer[NO_COPY]: ARRAY OF SYSTEM.BYTE;
                 start, length: LONGINT): LONGINT
RAISES IO.Error;
(**Exported for the sake of @omodule{*IO:SocketChannel}.  *)

END IO:Socket.
