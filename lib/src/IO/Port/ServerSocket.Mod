MODULE IO:Port:ServerSocket;
(*  Implementation of a TCP server socket.
    Copyright (C) 2001, 2002  Michael van Acken

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
  Msg, IO:Socket, Port0 := IO:Port, SocketPort := IO:Port:SocketTCP;


CONST
  done* = Socket.done;
  
TYPE
  Port* = POINTER TO PortDesc;
  PortDesc = RECORD
    (Port0.PortDesc)
    portNumber-: LONGINT;
    reuseAddress-: BOOLEAN;
    listenQueue-: LONGINT;
    transferFactory: Port0.TransferFactory;
    socket: Socket.Socket;
  END;

PROCEDURE InitPort* (p: Port; group: Port0.Group;
                     portNumber: LONGINT; reuseAddress: BOOLEAN;
                     listenQueue: LONGINT;
                     transferFactory: Port0.TransferFactory);
  BEGIN
    Port0.InitPort (p, group);
    p. portNumber := portNumber;
    p. reuseAddress := reuseAddress;
    p. listenQueue := listenQueue;
    p. transferFactory := transferFactory;
    p. socket := NIL;
  END InitPort;

PROCEDURE NewPort* (group: Port0.Group;
                    portNumber: LONGINT; reuseAddress: BOOLEAN;
                    listenQueue: LONGINT;
                    transferFactory: Port0.TransferFactory): Port;
  VAR
    p: Port;
  BEGIN
    NEW (p);
    InitPort (p, group, portNumber, reuseAddress, listenQueue, transferFactory);
    RETURN p
  END NewPort;

PROCEDURE (p: Port) Open* (VAR res: Msg.Msg);
  VAR
    addr: Socket.sockaddr_in;
  BEGIN
    p. socket := Socket.New (Socket.AF_INET, Socket.SOCK_STREAM, 0, res);
    IF (res = Socket.done) THEN
      Socket.InitSockAddrINET (addr, "", p. portNumber);
      ASSERT (addr. sin_family = Socket.AF_INET);
      IF p. reuseAddress THEN
        p. socket. SetReuseAddress
      END;
      p. socket. Bind (addr, SIZE (Socket.sockaddr_in));
      res := p. socket. res;
      IF (res = Socket.done) THEN
        p. socket. Listen (p. listenQueue);
        res := p. socket. res;
        
        IF (res = Socket.done) THEN
          p. Open^ (res)
        END
      END
    END
  END Open;

PROCEDURE (p: Port) Close* (reason: Msg.Msg; VAR res: Msg.Msg);
  BEGIN
    p. socket. Close();
    res := p. socket. res;
    p. Close^ (res, res)
  END Close;


PROCEDURE (p: Port) CanRead*(): BOOLEAN;
  BEGIN
    ASSERT (p. isOpen);
    RETURN TRUE
  END CanRead;

PROCEDURE (p: Port) CanWrite*(): BOOLEAN;
  BEGIN
    ASSERT (p. isOpen);
    RETURN FALSE
  END CanWrite;

PROCEDURE (p: Port) GetFileDescriptor*(): Port0.FileDescriptor;
  BEGIN
    ASSERT (p. isOpen);
    RETURN p. socket. fd
  END GetFileDescriptor;

PROCEDURE (p: Port) Do* (read, write: BOOLEAN; VAR res: Msg.Msg);
  VAR
    newPort: SocketPort.Port;
    t: Port0.Transfer;
  BEGIN
    newPort := SocketPort.NewAccept (p. group, p. socket, res);
    IF (res = Socket.done) THEN
      t := p. transferFactory. NewTransfer();
      t. SetPort (newPort)
    END
  END Do;

END IO:Port:ServerSocket.
