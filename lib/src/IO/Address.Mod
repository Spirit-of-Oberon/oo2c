MODULE IO:Address [FOREIGN "C"; LINK FILE "Address.c" END];
<*Warnings:=FALSE*>

IMPORT
  RT0, Exception, Object;
  
TYPE
  Inet* = POINTER TO InetDesc;
  InetDesc = RECORD
    (**IPv4 or IPv6 Internet host address.  *)
    (Object.ObjectDesc)
  END;
  Inet4* = POINTER TO Inet4Desc;
  Inet4Desc = RECORD
    (**IPv4 Internet host address.  *)
    (InetDesc)
    addr: LONGINT;
  END;
  (*Inet6* = POINTER TO Inet6Desc;
  Inet6Desc = RECORD
    (**IPv6 Internet host address.  *)
    (InetDesc)
    addr: ARRAY 4 OF LONGINT;
  END;*)

TYPE
  Port* = LONGINT;
  (**Port number of an Internet host.  A value in the range @samp{0..65335}. *)
  Socket* = POINTER TO SocketDesc;
  SocketDesc = RECORD [ABSTRACT]
    (**A socket address.  *)
    (Object.ObjectDesc)
  END;
  SocketInet* = POINTER TO SocketInetDesc;
  SocketInetDesc = RECORD
    (**An Internet socket address.  *)
    (SocketDesc)
    host-: Inet;
    (**IP address of the host.  *)
    port-: Port;
    (**Port number of the socket.  A number between zero and 65535.  *)
  END;

TYPE
  SockAddr* = POINTER TO ARRAY OF CHAR;

TYPE
  UnknownHostException* = POINTER TO UnknownHostExceptionDesc;
  UnknownHostExceptionDesc = RECORD
    (Exception.ExceptionDesc)
  END;

VAR
  inet4Loopback-: Inet4;
  (**The internet address @samp{127.0.0.1} referring to this machine,
     typically called @samp{localhost}.  *)
  inet4Any-: Inet4;
  (**Stands for "any incoming address" when binding to an address.  This is the
     usual address in the host part of @otype{SocketInet} to accept Internet
     connections on a server port.  *)
  inet4Broadcast-: Inet4;
  (**The address to send a broadcast message.  *)
  
PROCEDURE GetByName*(host: Object.String8): Inet
  RAISES UnknownHostException;
(**Determines the IP address of a host, given the host's DNS name.  The host
   name @code{NIL} refers to the local host.  *)

PROCEDURE (addr: Inet4) ToString*(): STRING;
PROCEDURE (addr: Inet4) Equals*(y: Object.Object): BOOLEAN;  
PROCEDURE (addr: Inet4) HashCode*(): Object.Hash;

PROCEDURE GetSocketInet*(host: Inet; port: Port): SocketInet;
(**Return an Internet socket address for the given host address and
   port number.  *)

PROCEDURE (s: Socket) [ABSTRACT] GetSockAddr*(): SockAddr;
(**Return the socket address @oparam{s}, in the format expected by the
   functions of libc.  *)

PROCEDURE (s: SocketInet) ToString*(): STRING;
PROCEDURE (s: SocketInet) Equals*(y: Object.Object): BOOLEAN;  
PROCEDURE (s: SocketInet) HashCode*(): Object.Hash;
PROCEDURE (s: SocketInet) GetSockAddr*(): SockAddr;

END IO:Address.
