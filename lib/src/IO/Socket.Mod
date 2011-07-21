(*	$Id: Socket.Mod,v 1.10 2003/07/29 15:30:20 mva Exp $	*)
MODULE IO:Socket [FOREIGN "C";
  LINK
    FILE "Socket.c";
    <*IF HAVE_LIB_XNET THEN*>LIB "xnet";<*END*>
    <*IF HAVE_LIB_WSOCK32 THEN*>LIB "wsock32";<*END*>
  END ];
(*  Server and client sockets for TCP streams.
    Copyright (C) 2003  Michael van Acken

    This module is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public License
    as published by the Free Software Foundation; either version 2 of
    the License, or (at your option) any later version.

    This module is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with OOC. If not, write to the Free Software Foundation,
    59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*)
<* Warnings := FALSE *>

IMPORT
  SYSTEM, IO, IO:Address, IO:StdChannels;

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


PROCEDURE New*(): Socket
RAISES IO.Error;
(**Create an unconnected socket.  *)

PROCEDURE (s: Socket) SetBlocking*(block: BOOLEAN)
RAISES IO.Error;
  
PROCEDURE (s: Socket) Bind*(bindPoint: Address.Socket)
RAISES IO.Error;
(**Bind this socket to a local address.

   If the address is @code{NIL}, then the system will pick up an ephemeral port
   and a valid local address to bind the socket.  *)
  
PROCEDURE (s: Socket) Connect*(endPoint: Address.Socket): BOOLEAN
RAISES IO.Error;
(**Connect this socket to the remote end point.  Result is @code{TRUE} if
   the connection has been established, and @code{FALSE} if the process is
   still in progress when this method returns.  *)
  
PROCEDURE (s: Socket) FinishConnect*(): BOOLEAN
RAISES IO.Error;
(**Try to complete socket connect after @oproc{Socket.Connect} has been called
   on a non-blocking socket.  Result is @code{TRUE} on success, and
   @code{FALSE} if the connection process cannot be completed at this time.  *)

PROCEDURE (s: Socket) RemoteAddress*(): Address.Socket
RAISES IO.Error;
(**Returns the address of the remove end of a connection.  *)
  
PROCEDURE (s: Socket) Close*()
RAISES IO.Error;
(**Close this socket.

   Once a socket has been closed, it is not available for further networking
   use.  That is, it can't be reconnected or rebound; a new socket needs to be
   created.  *)


PROCEDURE NewServer*(): Server
RAISES IO.Error;
(**Create an unconnected socket.  *)

PROCEDURE (s: Server) SetReuseAddress*(on: BOOLEAN)
RAISES IO.Error;
  
PROCEDURE (s: Server) SetBlocking*(block: BOOLEAN)
RAISES IO.Error;
  
PROCEDURE (s: Server) Bind*(bindPoint: Address.Socket; queueSize: LONGINT)
RAISES IO.Error;
(**Bind this socket to a local address and switch it to listening mode.
   @oparam{queueSize} specifies the length of the queue for pending
   connections.

   If the address is @code{NIL}, then the system will pick up an ephemeral port
   and a valid local address to bind the socket.  *)

PROCEDURE (s: Server) Accept*(): Socket
RAISES IO.Error;
(**Accepts a connection request from a remote socket.

   On success, result is the local socket of the connection.  If the server
   socket is in non-blocking more, and there are no more pending connections,
   then result is @code{NIL}.  An error raises an exception of type
   @otype{IO.Error}.  *)

PROCEDURE (s: Server) Close*()
RAISES IO.Error;
(**Close this socket.

   Once a socket has been closed, it is not available for further networking
   use.  That is, it cannot be reconnected or rebound; a new socket needs to be
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
