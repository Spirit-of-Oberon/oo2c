(*	$Id: SocketChannel.Mod,v 1.7 2004/11/21 20:31:44 mva Exp $	*)
MODULE IO:SocketChannel;
(*  Access to TCP connections through channel objects.
    Copyright (C) 2003, 2004  Michael van Acken

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

IMPORT
  SYSTEM, IO, IO:Address, IO:Socket,
  <*PUSH; Warnings:=FALSE*>IO:FileChannel<*POP*>;
  
TYPE
  Channel* = POINTER TO ChannelDesc;
  ChannelDesc = RECORD
    (IO.ByteChannelDesc)
    socket-: Socket.Socket;
    blocking: BOOLEAN;
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
    ch.blocking := block;
  END SetBlocking;

PROCEDURE (ch: Channel) Connect*(endPoint: Address.Socket): BOOLEAN
(**Note: Non-blocking connect is not supported yet.  *)
RAISES IO.Error;
  BEGIN
    ch.connected := ch.socket.Connect(endPoint);
    ch.connectionPending := ~ch.connected;
    RETURN ch.connected;
  END Connect;

PROCEDURE (ch: Channel) FinishConnect*(): BOOLEAN
RAISES IO.Error;
  BEGIN
    ch.connected := ch.socket.FinishConnect();
    IF ch.connected THEN
      EXCL(ch.readyOps, IO.opConnect);
      ch.connectionPending := FALSE;
    END;
    RETURN ch.connected;
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
    ch.connected := FALSE;
    ch.connectionPending := FALSE;
    ch.socket.Close();
  END Close;

PROCEDURE Open*(): Channel RAISES IO.Error;
  VAR
    ch: Channel;
  BEGIN
    NEW(ch);
    ch.socket := Socket.New();
    ch.INIT^();
    ch.blocking := TRUE;
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
    ch.INIT^();
    RETURN ch;
  END OpenServer;

PROCEDURE (ch: ServerChannel) SetBlocking*(block: BOOLEAN) RAISES IO.Error;
  BEGIN
    ch.socket.SetBlocking(block);
  END SetBlocking;

PROCEDURE (ch: ServerChannel) Accept*(): Channel RAISES IO.Error;
(**Accepts a connection request from a remote socket.

   On success, result is a channel for the incoming connection.  If the server
   socket is in non-blocking mode, and there are no more pending connections,
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
      client.INIT^();
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
