MODULE IO:Port [OOC_EXTENSIONS];
(*  Framework for select() based IO.
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
  C, Msg, IO:Select, IO:Socket;


CONST
  done* = Socket.done;

CONST
  portOpen* = 0;
  (**The ports status has changed to ``open''.  *)
  portClose* = 1;
  (**The ports status has changed to ``close''.  *)
  portDisbanded* = 2;
  (**The port is being disbanded.  *)
  
TYPE
  FileDescriptor* = C.int;
  (**Holds low-level file descriptor identifiers, as used by
     @oproc{Select.Select}.  *)
  Buffer* = POINTER TO ARRAY OF CHAR;
  (**A buffer that holds data scheduled for output, or incoming data from 
     a remote peer.  *)
  
TYPE
  Group* = POINTER TO GroupDesc;
  Port* = POINTER TO PortDesc;
  Transfer* = POINTER TO TransferDesc;
  
TYPE
  PortDesc* = RECORD [ABSTRACT]
  (**An object where data is sent or received.  Most of the time this is a
     non-blocking TCP socket, but it can also be a server socket listening for
     incoming connections, or @code{stdin} or @code{stdout}.

     A port exists in a @otype{Group}, and is either open or closed.  An open
     port is able to receive or send data, while a closed port is inactive
     until opened.  Ports can be disbanded, which will remove them from their
     group.  *)
    transfer-: Transfer;
    (**The transfer object associated with this port.  This field can be
       @code{NIL}.  *)
    next-: Port;
    (**Refers to the next open port in the list @ofield{Group.openList} or
       to the next closed port in the list @ofield{Group.closedList}.  Please
       note that the value of this field changes if the port is opened or
       closed.  *)
    isOpen-: BOOLEAN;
    (**If @code{TRUE}, then the port is able to send or receive data.  *)
    group-: Group;
    (**The group to which the port is associated, and which monitors I/O events
       on this port.  *)
  END;
  GroupDesc* = RECORD
  (**A set of ports.  By calling @oproc{Group.Select} it is possible to send
     output and react to input on all open ports in the group.  A group is a
     high-level interface upon the Unix system call @code{select()}.  *)
    openPorts-: LONGINT;
    (**Number of ports in state ``open''.  *)
    openList-: Port;
    (**List of open states, linked via @ofield{Port.next}.  *)
    closedList-: Port;
    (**List of open states, linked via @ofield{Port.next}.  *)
    
    readSet, writeSet: Select.FileDescrSet;
  END;
  TransferDesc* = RECORD [ABSTRACT]
  (**Transfers byte data to and from a port.  Instances of this class are
     intermediaries between ports and the application.  *)
  END;

TYPE
  TransferFactory* = POINTER TO TransferFactoryDesc;
  TransferFactoryDesc* = RECORD [ABSTRACT]
    (**Creates new instances of @otype{Transfer} on request.  *)
  END;


TYPE
  ErrorContext = POINTER TO ErrorContextDesc;
  ErrorContextDesc = RECORD
    (Msg.ContextDesc)
  END;

CONST
  protocolError* = 0;
  
VAR
  errorContext: ErrorContext;
  msgProtocolError*: Msg.Msg;


PROCEDURE (context: ErrorContext) GetTemplate* (msg: Msg.Msg; VAR templ: Msg.LString);
  VAR
    t: ARRAY 128 OF Msg.LChar;
  BEGIN
    CASE msg. code OF
    | protocolError:
      t := "Protocol error"
    END;
    COPY (t, templ)
  END GetTemplate;


PROCEDURE InitGroup* (group: Group);
  BEGIN
    group. openList := NIL;
    group. closedList := NIL;
    group. readSet := Select.NewSet();
    group. writeSet := Select.NewSet();
    group. openPorts := 0;
  END InitGroup;

PROCEDURE NewGroup* (): Group;
(**Creates a new, empty group.  *)
  VAR
    group: Group;
  BEGIN
    NEW (group);
    InitGroup (group);
    RETURN group
  END NewGroup;

PROCEDURE AddOpen (group: Group; p: Port);
  BEGIN
    p. next := group. openList;
    group. openList := p;
    INC (group. openPorts)
  END AddOpen;

PROCEDURE RemoveOpen (group: Group; p: Port);
  VAR
    ptr: Port;
  BEGIN
    IF (group. openList = p) THEN
      group. openList := p. next
    ELSE
      ptr := group. openList;
      WHILE (ptr. next # p) DO
        ptr := ptr. next
      END;
      ptr. next := p. next
    END;
    DEC (group. openPorts)
  END RemoveOpen;

PROCEDURE AddClose (group: Group; p: Port);
  BEGIN
    p. next := group. closedList;
    group. closedList := p
  END AddClose;

PROCEDURE RemoveClose (group: Group; p: Port);
  VAR
    ptr: Port;
  BEGIN
    IF (group. closedList = p) THEN
      group. closedList := p. next
    ELSE
      ptr := group. closedList;
      WHILE (ptr. next # p) DO
        ptr := ptr. next
      END;
      ptr. next := p. next
    END
  END RemoveClose;


PROCEDURE ^ (t: Transfer) PortStatusChange* (newStatus: SHORTINT; reason: Msg.Msg);

PROCEDURE PortStatusChange* (p: Port; reason: Msg.Msg);
  BEGIN
    IF p. isOpen THEN
      RemoveOpen (p. group, p);
      AddClose (p. group, p);
      p. isOpen := FALSE;
      IF (p. transfer # NIL) THEN
        p. transfer. PortStatusChange (portClose, reason)
      END      
    ELSE
      RemoveClose (p. group, p);
      AddOpen (p. group, p);
      p. isOpen := TRUE;
      IF (p. transfer # NIL) THEN
        p. transfer. PortStatusChange (portOpen, reason)
      END
    END
  END PortStatusChange;


PROCEDURE InitPort* (port: Port; group: Group);
  BEGIN
    port. transfer := NIL;
    port. next := NIL;
    port. group := group;
    port. isOpen := FALSE;
    AddClose (group, port)
  END InitPort;

PROCEDURE (p: Port) Open* (VAR res: Msg.Msg);
(* @precond
   @samp{p.isOpen = FALSE}
   @end precond *)
  BEGIN
    ASSERT (~p. isOpen);
    PortStatusChange (p, Socket.done)
  END Open;

PROCEDURE (p: Port) Close* (reason: Msg.Msg; VAR res: Msg.Msg);
(* @precond
   @samp{p.isOpen = FALSE}
   @end precond
   
   @postcond
   @samp{p.isOpen = TRUE}
   @end postcond *)
  BEGIN
    ASSERT (p. isOpen);
    PortStatusChange (p, reason)
  END Close;

PROCEDURE (p: Port) Disband*;
(* @precond
   @samp{p.isOpen = FALSE}
   @end precond *)
  BEGIN
    ASSERT (~p. isOpen);
    RemoveClose (p. group, p);
    p. group := NIL;
    IF (p. transfer # NIL) THEN
      p. transfer. PortStatusChange (portDisbanded, Socket.done)
    END;
  END Disband;


PROCEDURE (p: Port) [ABSTRACT] CanRead*(): BOOLEAN;
(* @precond
   @samp{p.IsOpen = TRUE}
   @end precond *)
  END CanRead;

PROCEDURE (p: Port) [ABSTRACT] CanWrite*(): BOOLEAN;
(* @precond
   @samp{p.IsOpen = TRUE}
   @end precond *)
  END CanWrite;

PROCEDURE (p: Port) [ABSTRACT] GetFileDescriptor*(): FileDescriptor;
(* @precond
   @samp{p.IsOpen = TRUE}
   @end precond *)
  END GetFileDescriptor;

PROCEDURE (p: Port) [ABSTRACT] Do* (read, write: BOOLEAN; VAR res: Msg.Msg);
(**@precond
   @samp{p.isOpen = TRUE} and @samp{read implies p.CanRead()} and @samp{write
   implies p.CanWrite()}.
   @end precond  *)
  END Do;


PROCEDURE (group: Group) Select* (sec, usec: LONGINT);
  VAR
    p, next: Port;
    res, dummy: Msg.Msg;
    count, fd: LONGINT;
    read, write: BOOLEAN;
  BEGIN
    group. readSet. Zero();
    group. writeSet. Zero();
    
    p := group. openList;
    WHILE (p # NIL) DO
      IF p. CanRead() THEN
        group. readSet. Set (p. GetFileDescriptor())
      END;
      IF p. CanWrite() THEN
        group. writeSet. Set (p. GetFileDescriptor())
      END;
      p := p. next
    END;
    
    count := Select.Select (group. readSet, group. writeSet, NIL, sec, usec);
    IF (count # 0) THEN
      p := group. openList;
      WHILE (p # NIL) DO
        next := p. next;

        fd := p. GetFileDescriptor();
        read := group. readSet. IsSet (fd);
        write := group. writeSet. IsSet (fd);
        IF read OR write THEN
          p. Do (read, write, res);
          IF (res # Socket.done) THEN
            p. Close (res, dummy)
          END
        END;
        
        p := next
      END;
    END
  END Select;


PROCEDURE InitTransfer* (t: Transfer);
  BEGIN
  END InitTransfer;

PROCEDURE (t: Transfer) SetPort* (p: Port);
  BEGIN
    IF (p # NIL) THEN
      ASSERT (p. transfer = NIL);
      p. transfer := t
    END
  END SetPort;

PROCEDURE (t: Transfer) PortStatusChange* (newStatus: SHORTINT; reason: Msg.Msg);
(**Called after the status of the port of transfer @oparam{t} has changed.  For
   @oconst{portClose}, @oparam{reason} holds the error message that was passed
   to @oproc{Port.Close}.  *)
  END PortStatusChange;



PROCEDURE InitTransferFactory* (tf: TransferFactory);
  BEGIN
  END InitTransferFactory;

PROCEDURE (tf: TransferFactory) [ABSTRACT] NewTransfer*(): Transfer;
  END NewTransfer;

BEGIN
  NEW (errorContext);
  Msg.InitContext (errorContext, "IO:Port");
  msgProtocolError := Msg.New (errorContext, protocolError);
END IO:Port.
