MODULE IO:Port:SocketTCP;
(*  Implementation of an outgoing TCP connection.
    Copyright (C) 2001  Michael van Acken

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

<* DEFINE DUMP_BYTES := FALSE *>
IMPORT
<*IF DUMP_BYTES THEN*>Log,Err,<*END*>
  Msg, Object, IO:Socket, Port0 := IO:Port, IO:Port:Streaming;


CONST
  done* = Socket.done;
  
TYPE
  Port* = POINTER TO PortDesc;
  PortDesc = RECORD
    (Streaming.PortDesc)
    hostname-: Object.String8;
    portNumber-: LONGINT;
    socket: Socket.Socket;
    pendingConnect: BOOLEAN;
    addr: Socket.sockaddr_in;
  END;
  


PROCEDURE InitPort* (p: Port; group: Port0.Group;
                     hostname: Object.String8; portNumber: LONGINT);
  BEGIN
    Streaming.InitPort (p, group);
    p. hostname := hostname;
    p. portNumber := portNumber;
    p. socket := NIL;
    p. pendingConnect := FALSE;
  END InitPort;

PROCEDURE NewPort* (group: Port0.Group;
                    hostname: Object.String8; portNumber: LONGINT;
                    blocking: BOOLEAN): Port;
  VAR
    p: Port;
  BEGIN
    NEW (p);
    InitPort (p, group, hostname, portNumber);
    RETURN p
  END NewPort;

PROCEDURE InitAccept (p: Port; group: Port0.Group;
                      serverSocket: Socket.Socket;
                      VAR res: Msg.Msg);
  VAR
    remoteAddrLen: LONGINT;
  BEGIN
    InitPort (p, group, NIL, -1);
    remoteAddrLen := SIZE (Socket.sockaddr_in);
    p. socket := serverSocket. Accept (p. addr, remoteAddrLen);
    res := p. socket. res;
    
    IF (res = Socket.done) THEN
      p. socket. SetBlocking (FALSE)
    END
  END InitAccept;

PROCEDURE NewAccept* (group: Port0.Group;
                      serverSocket: Socket.Socket;
                      VAR res: Msg.Msg): Port;
  VAR
    p: Port;
  BEGIN
    NEW (p);
    InitAccept (p, group, serverSocket, res);
    IF (res = Socket.done) THEN
      Port0.PortStatusChange (p, Socket.done);   (* add to set of open ports *)
      RETURN p
    ELSE
      p. Disband();
      RETURN NIL
    END
  END NewAccept;


PROCEDURE (p: Port) Open* (VAR res: Msg.Msg);
  VAR
    chars: Object.CharsLatin1;
  BEGIN
    ASSERT (~p. isOpen);
    
    p. socket := Socket.New (Socket.AF_INET, Socket.SOCK_STREAM, 0, res);
    IF (res = Socket.done) THEN
      chars := p.hostname.CharsLatin1();
      Socket.InitSockAddrINET (p. addr, chars^, p. portNumber);
      p. socket. SetBlocking (FALSE);
      p. socket. Connect (p. addr, SIZE (Socket.sockaddr_in));
      p. pendingConnect := 
        ((p. socket. res # Socket.done) &
         (p. socket. res. code = Socket.connectInProgress));
      IF ((p. socket. res = Socket.done) OR
          (p. socket. res. code = Socket.connectInProgress)) THEN
        p. Open^ (res)
      ELSE
        res := p. socket. res;
        p. socket. Close
      END
    END
  END Open;

PROCEDURE (p: Port) Close* (reason: Msg.Msg; VAR res: Msg.Msg);
  BEGIN
    ASSERT (p. isOpen);
    
    p. socket. Close();
    res := p. socket. res;
    IF (res # Socket.done) &
       ((reason = Socket.done) OR
        (reason. code = Socket.connectionTerminated)) THEN
      reason := res
    END;
    p. outputStart := p. outputEnd;      (* discard buffer contents *)
    p. Close^ (reason, res)
  END Close;


PROCEDURE (p: Port) CanRead*(): BOOLEAN;
  BEGIN
    RETURN p. pendingConnect OR p. CanRead^()
  END CanRead;

PROCEDURE (p: Port) CanWrite*(): BOOLEAN;
  BEGIN
    RETURN p. pendingConnect OR p. CanWrite^()
  END CanWrite;

PROCEDURE (p: Port) GetFileDescriptor*(): Port0.FileDescriptor;
  BEGIN
    ASSERT (p. isOpen);
    RETURN p. socket. fd
  END GetFileDescriptor;

PROCEDURE (p: Port) Do* (read, write: BOOLEAN; VAR res: Msg.Msg);
  VAR
<*IF DUMP_BYTES THEN*>i: LONGINT;<*END*>
    rBytes, len, usedCapacity, rc: LONGINT;
  BEGIN
    IF p. pendingConnect & (read OR write) THEN
      (* the pending connect is a success or failure; if it failed, close the
         port and return the result of the connect *)
<*IF DUMP_BYTES THEN*>Log.String (p. hostname. array^, "connect completed");<*END*>
      p. pendingConnect := FALSE;
      p. socket. ConnectDone
    ELSE
      IF read THEN
        rBytes := p. socket. Recv (p. inputBuffer^, p. inputStart,
                                   p. inputSize-p. inputStart, {});
        IF (rBytes > 0) & (p. transfer # NIL) THEN
<*IF DUMP_BYTES THEN*>Err.String ("reading:"); Err.Ln;
FOR i := p.inputStart TO p.inputStart+rBytes-1 DO
Err.Char(p.inputBuffer[i]);
END;<*END*>
          res := Port0.done;
          p. inputStart := p. transfer(Streaming.Transfer). IncomingData
            (p. inputBuffer, p. inputStart, p. inputStart+rBytes, res);
          IF (res # Port0.done) THEN
            RETURN
          END
        END
      END;

      IF write & 
         ((p. socket. res = Socket.done) OR 
          (p. socket. res = Socket.errorWouldBlock)) THEN
        (* here holds: p.outputEnd # p.outputStart *)
        IF (p. outputStart < p. outputEnd) THEN
<*IF DUMP_BYTES THEN*>Err.String ("sending:"); Err.Ln;
FOR i := p. outputStart TO p.outputEnd-1 DO
Err.Char(p.outputBuffer[i]);
END;<*END*>
          rc := p. socket. Send (p. outputBuffer^, p. outputStart,
                                 p. outputEnd-p. outputStart, {});
        ELSE
          len := LEN (p. outputBuffer^)-p. outputStart;
<*IF DUMP_BYTES THEN*>Err.String ("sending:"); Err.Ln;
FOR i := p. outputStart TO len-1 DO
Err.Char(p.outputBuffer[i]);
END;<*END*>
          rc := p. socket. Send (p. outputBuffer^, p. outputStart, len, {});
          IF (rc = len) THEN
            p. outputStart := 0;
            rc := p. socket. Send (p. outputBuffer^, 0, p. outputEnd, {})
          END
        END;
        
        IF (rc > 0) THEN
          INC (p. outputStart, rc);
          usedCapacity := p. UsedOutputCapacity();
          IF (usedCapacity <= p. alertLevel) THEN
            (* here holds: p.transfer # NIL, because p.alertLevel is set *)
            p. transfer(Streaming.Transfer).
              OutputNotification (p. outputSize-usedCapacity)
          END
        END
      END
    END;

    IF (p. socket. res = Socket.errorWouldBlock) THEN
      res := Socket.done
    ELSE
      res := p. socket. res
    END
  END Do;

END IO:Port:SocketTCP.
