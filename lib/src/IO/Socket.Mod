(*	$Id$	*)
MODULE IO:Socket [FOREIGN "C"; 
                  LINK
                    FILE "Socket.c"
                    <*IF LIB_HAVE_LIBXNET THEN*>; LIB "xnet"<*END*>
                  END];
(*  Interface to socket facilities.
    Copyright (C) 2000  Michael van Acken

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
  SYSTEM, C, Channel, CharClass, LongStrings, Msg, IO:PFD, IO:Select;

TYPE
  Result* = Channel.Result;
  
CONST
  done* = Channel.done;
  
CONST
  protocolNotSupported* = 0;
  (**The @samp{protocol} or @samp{type} is not supported by the @samp{family}
     specified.  *)
  processTooManyFileDescriptors* = 1;
  (**The process already has too many file descriptors open.  *)
  systemTooManyFileDescriptors* = 2;
  (**The system already has too many file descriptors open.  *)
  accessDenied* = 3;
  (**The process does not have privilege to create a socket of the
     specified @samp{type} or @samp{protocol}.  *)
  noBuffers* = 4;
  (**The system ran out of internal buffer space.  *)
  socketError* = 5;
  (**Used when an unknown error code is returned by a socket operation.  *)

  badFileDescriptor* = 6;
  (**The given socket is not a valid file descriptor.  *)
  notSocket* = 7;
  (**The given file descriptor is not a socket.  *)
  addrNotAvailable* = 8;
  (**The specified address is not available on the remote machine.  *)
  addrFamilyNotSupported* = 10;
  (**The given address family is not supported by this socket.  *)
  isConnected* = 11;
  (**The given socket is already connected.  *)
  timedOut* = 12;
  (**The attempt to establish the connection timed out.  *)
  connectionRefused* = 13;
  (**The remote server has actively refused to establish the connection.  *)
  networkUnreachable* = 14;
  (**The network of the given address is not reachable from this host.  *)
  addrInUse* = 15;
  (**The socket address of the given address is already in use.  *)
  connectInProgress* = 16;
  (**The socket is non-blocking and the connection could not be established
     immediately.  Another @oproc{Socket.Connect} call on the same socket,
     before the connection is completely established, will fail with
     @oconst{connectAlreadyInProgress}.  *)
  connectAlreadyInProgress* = 17;
  (**The socket is non-blocking and already has a pending connection in
     progress (see @oconst{connectInProgress}).  *)
  wouldBlock* = 18;
  (**Nonblocking mode has been set on the socket, and the write or read
     operation would block.  *)
  connectionTerminated* = 19;
  (**A read or write operation for a non-zero number of bytes was done,
     but there is no data available and the connection has been terminated.  *)
  
  
      
TYPE
  sa_family_t* = C.shortint;
  socklen_t* = C.int;
  ssize_t* = C.size_t;
  
VAR
  AF_INET-: C.int;
  AF_UNIX-: C.int;
  AF_UNSPEC-: C.int;
  
VAR
  SOCK_STREAM-: C.int;
  SOCK_DGRAM-: C.int;

VAR
  MSG_DONTROUTE-: C.set;
  MSG_DONTWAIT-: C.set;
  MSG_OOB-: C.set;
  MSG_PEEK-: C.set;
  MSG_WAITALL-: C.set;
  (**Note: Not all of the @samp{MSG_*} flags are supported on all systems.
     If a flag @samp{MSG_X} is not available, then the variable @samp{MSG_X}
     holds the empty set.  *)

VAR
  SHUT_RD-: C.int;
  SHUT_WR-: C.int;
  SHUT_RDWR-: C.int;
  
TYPE
  Socket* = POINTER TO SocketDesc;
  SocketDesc = RECORD
    fd-: C.int;
    res-: Result;
  END;


TYPE
  sockaddr* = POINTER TO sockaddrDesc;
  sockaddrDesc = RECORD
    sa_family*: sa_family_t;
  END;
  SockAddrParam* = ARRAY OF SYSTEM.BYTE;
  
TYPE
  in_addr* = RECORD
  (**This data type is used in certain contexts to contain an IPv4 Internet
     host address.  *)
    saddr*: C.int;      (* name `s_addr' doesn't compile under Solaris  *)
    (**This field records the host address number as an unsigned 32 bit integer
       type.  *)
  END;

TYPE
  sockaddr_in* = RECORD
  (**This is the data type used to represent socket addresses in the Internet
     namespace.

     When you call @samp{bind} or @samp{getsockname}, you should specify
     @samp{SIZE (sockaddr_in)} as the @var{length} parameter if you are
     using an IPv4 Internet namespace socket address.  *)
    sin_family*: sa_family_t;
    (**This identifies the address family or format of the socket address.  You
       should store the value of @ovar{AF_INET} in this member.  *)
    sin_port*: C.shortint;               
    (**This is the port number.  @strong{Important:} This field actually holds
       an unsigned value.  *)
    sin_addr*: in_addr;
    (**This is the Internet address of the host machine.  *)
    sin_zero*: ARRAY 16-2-2-SIZE (in_addr) OF CHAR;
  END;

TYPE
  sockaddr_un* = RECORD
    sun_family*: C.shortint;
    (**This identifies the address family or format of the socket address.  You
       should store the value @ovar{AF_UNIX} to designate the local namespace.

       You should compute the @var{length} parameter for a socket
       address in the local namespace as the sum of the size of the
       @ofield{sun_family} component and the string length (@emph{not} the
       allocation size!) of the file name string.  *)
    sun_path*: ARRAY 108 OF C.char;
    (**This is the file name to use.

       @strong{Incomplete:} Why is 108 a magic number?  RMS suggests making
       this a zero-length array and tweaking the example following to use
       @samp{alloca} to allocate an appropriate amount of storage based on the
       length of the filename.  *)
  END;


TYPE
  ErrorContext = POINTER TO ErrorContextDesc;
  ErrorContextDesc* = RECORD
    (Msg.ContextDesc)
  END;

VAR
  errorContext: ErrorContext;
  errorWouldBlock-: Result;


PROCEDURE (context: ErrorContext) GetTemplate* (msg: Msg.Msg; VAR templ: Msg.LString);


PROCEDURE Init* (s: Socket; family: C.int; type: C.int; protocol: C.int; VAR res: Msg.Msg);

PROCEDURE New* (family: C.int; type: C.int; protocol: C.int; VAR res: Msg.Msg): Socket;
(**Creates a new socket using the given address family, socket type and
   protocol number. The address family should be @ovar{AF_INET} or
   @ovar{AF_UNIX}. The socket type should be @ovar{SOCK_STREAM},
   @ovar{SOCK_DGRAM} or perhaps one of the other @samp{SOCK_} constants. The
   protocol number is usually zero.  *)

PROCEDURE InitFromFD* (s: Socket; fd: C.int;
                       family: C.int; type: C.int; protocol: C.int;
                       VAR res: Msg.Msg);

PROCEDURE NewFromFD* (fd: C.int;
                      family: C.int; type: C.int; protocol: C.int;
                      VAR res: Msg.Msg): Socket;
(**Builds a socket object from an existing file descriptor.  Address family,
   socket type and protocol number are as for the @oproc{New} function
   above. The file descriptor should refer to a socket, but this is not checked
   --- subsequent operations on the object may fail if the file descriptor is
   invalid.  This function is rarely needed, but can be used to get or set
   socket options on a socket passed to a program as standard input or output
   (e.g. a server started by the Unix inet daemon).  *)

PROCEDURE InitSockAddrINET* (VAR addr: sockaddr_in;
                             hostname: ARRAY OF CHAR; port: LONGINT);
(**Initializes a socket address in the Internet namespace based on a host name
   @oparam{hostname} and port number @oparam{port}.  The port number is an
   unsigned 16 bit integer value.  If @oparam{hostname} is the empty string,
   @samp{INADDR_ANY} is used as the value for the @ofield{sockaddr_in.sin_addr}
   field of the address.  This is the usual address use when accepting incoming
   connections.

   On success, @oparam{addr} holds a valid socket address of the family
   @ovar{AF_INET}.  On failure, @ofield{addr.sin_family} holds the value
   @ovar{AF_UNSPEC}.

   Please note that this procedure only covers the most common case of IPv4
   addresses.  More advanced address mapping procedures should be placed in
   another module.  *)


PROCEDURE (s: Socket) GetChannel* (): Channel.Channel;
(**Returns a channel for the given socket @oparam{s}.  The channel's file
   descriptor is a @samp{dup()} of the socket's file descriptor.  That is, both
   can and must be closed independently.  *)


PROCEDURE (s: Socket) Accept* (VAR cliaddr: SockAddrParam;
                               VAR addrlen: socklen_t): Socket;
(**Accepts a connection on socket @oparam{s}.  The socket must be bound to an
   address and listening for connections.

   The @oproc{Socket.Accept} function waits if there are no connections
   pending, unless the socket @oparam{s} has nonblocking mode set.

   The return value is a new socket object usable to send and receive data on
   the connection.  On error, result is @code{NIL} and @ofield{s.res} holds the
   error message.

   The @oparam{cliaddr} and @oparam{addrlen} arguments are used to return
   information about the name of the client socket that initiated the
   connection.  Before the call, @oparam{addrlen} must be set to the size of
   the socket address structure passed to @oparam{cliaddr}, and on return this
   variable contains the actual number of bytes stored in the socket address
   structure.  *)

PROCEDURE (s: Socket) Bind* (VAR myaddr: SockAddrParam;
                             addrlen: socklen_t);
(**Binds the socket to the address.  The socket must not already be bound.  The
   parameter @oparam{myaddr} is a protocol-specific address, and
   @oparam{addrlen} the size of this address structure.

   Depending on the result of the operation, @ofield{s.res} is changed.  *)

PROCEDURE (s: Socket) Close*;
(**Closes the socket @oparam{s}.  The socket is no longer usable by the
   process.  TCP will try to send any data that is already queued to be send to
   the other end.  *)

PROCEDURE (s: Socket) Connect* (VAR servaddr: SockAddrParam;
                                addrlen: socklen_t);
(**Connects to a remote socket at @oparam{servaddr}.  The parameter
   @oparam{servaddr} is a protocol-specific address, and @oparam{addrlen} the
   size of this address structure.

   The client does not have to call @oproc{Socket.Bind} before calling
   @oproc{Socket.Connect}: the kernel will choose both an ephemeral port and
   the source IP address if necessary.

   Depending on the result of the operation, @ofield{s.res} is changed.  *)

PROCEDURE (s: Socket) GetPeerName* (VAR peeraddr: SockAddrParam;
                                    VAR addrlen: socklen_t);
(**Returns the remote address to which the socket is connected.  The function
   fills in the socket address structure @oparam{peeraddr}.  Before the
   procedure is called, @oparam{addrlen} must be set to the size of the
   strucure @oparam{peeraddr}, on return it holds the number of bytes in
   @oparam{peeraddr} actually changed by the call.  *)

PROCEDURE (s: Socket) GetSockName* (VAR localaddr: SockAddrParam;
                                    VAR addrlen: socklen_t);
(**Returns the socket's own address.  The function fills in the socket address
   structure @oparam{localaddr}.  Before the procedure is called,
   @oparam{addrlen} must be set to the size of the strucure @oparam{localaddr},
   on return it holds the number of bytes in @oparam{localaddr} actually
   changed by the call.  *)

PROCEDURE (s: Socket) Listen* (backlog: C.int);
(**Listens for connections made to the socket.  The @oparam{backlog} argument
   specifies the maximum number of queued connections and should be at least 1;
   the maximum value is system-dependent (usually 5).

   Depending on the result of the operation, @ofield{s.res} is changed.  *)

PROCEDURE (s: Socket) Recv* (VAR buff: ARRAY OF SYSTEM.BYTE;
                             start: LONGINT; nbytes: C.size_t;
                             flags: C.set): ssize_t;
(**Receives data from the socket.  Depending on the result of the operation,
   @ofield{s.res} is updated.  See the Unix manual page recv(2) for the
   details.
   
   If @oparam{nbytes} is non-zero, but no data is available and the connection
   has been terminated, the error @oconst{connectionTerminated} is reported.
   
   For performace reasons, the error code @code{EWOULDBLOCK} always returns the
   same error message @ovar{errorWouldBlock} in @ofield{s.res}.  *)

PROCEDURE (s: Socket) Send* (VAR buff: ARRAY OF SYSTEM.BYTE;
                             start: LONGINT; nbytes: C.size_t;
                             flags: C.set): ssize_t;
(**Sends data to the socket.  Depending on the result of the operation,
   @ofield{s.res} is updated.  See the Unix manual page send(2) for the
   details.

   If @oparam{nbytes} is non-zero, but no data is available and the connection
   has been terminated, the error @oconst{connectionTerminated} is reported.
   
   For performace reasons, the error code @code{EWOULDBLOCK} always returns the
   same error message @ovar{errorWouldBlock} in @ofield{s.res}.  *)

PROCEDURE (s: Socket) RecvFrom* (VAR buff: ARRAY OF SYSTEM.BYTE;
                                 start: LONGINT; nbytes: C.size_t;
                                 flags: C.set;
                                 VAR from: SockAddrParam;
                                 VAR addrlen: socklen_t): ssize_t;
(**Receives data from the socket.  Depending on the result of the operation,
   @ofield{s.res} is updated.  See the Unix manual page recvfrom(2) for the
   details.
   
   If @oparam{nbytes} is non-zero, but no data is available and the connection
   has been terminated, the error @oconst{connectionTerminated} is reported.
   
   For performace reasons, the error code @code{EWOULDBLOCK} always returns the
   same error message @ovar{errorWouldBlock} in @ofield{s.res}.  *)

PROCEDURE (s: Socket) SendTo* (VAR buff: ARRAY OF SYSTEM.BYTE;
                               start: LONGINT; nbytes: C.size_t;
                               flags: C.set;
                               VAR to: SockAddrParam;
                               addrlen: socklen_t): ssize_t;
(**Sends data to the socket.  Depending on the result of the operation,
   @ofield{s.res} is updated.  See the Unix manual page sendto(2) for the
   details.

   If @oparam{nbytes} is non-zero, but no data is available and the connection
   has been terminated, the error @oconst{connectionTerminated} is reported.
   
   For performace reasons, the error code @code{EWOULDBLOCK} always returns the
   same error message @ovar{errorWouldBlock} in @ofield{s.res}.  *)

PROCEDURE (s: Socket) SetBlocking* (blocking: BOOLEAN);
(**Set blocking or non-blocking mode of the socket: if @oparam{blocking} is
   @code{FALSE}, the socket is set to non-blocking, else to blocking mode.
   Initially all sockets are in blocking mode. In non-blocking mode, if a
   @oproc{Socket.Recv} call doesn't find any data, or if a @oproc{Socket.Send}
   call can't immediately dispose of the data, an error is is signalled in
   @ofield{s.res}.  In blocking mode, the calls block until they can proceed.  *)

PROCEDURE (s: Socket) SetReuseAddress*;
(**Sets the option @samp{SO_REUSEADDR} for the socket.  This option controls
   whether @oproc{Socket.Bind} should permit reuse of local addresses for this
   socket.  If you enable this option, you can actually have two sockets with
   the same Internet port number; but the system won't allow you to use the two
   identically-named sockets in a way that would confuse the Internet.  The
   reason for this option is that some higher-level Internet protocols,
   including FTP, require you to keep reusing the same port number.
   
   [Could someone please add the generic getsockopt/setsockopt functions 
    to this module?!] *)


PROCEDURE (s: Socket) Shutdown* (howto: C.int);
(**Shuts down one or both halves of the connection.  @oparam{howto} must
   be one of @ovar{SHUT_RD}, @ovar{SHUT_WR}, or @ovar{SHUT_RDWR}.

   Depending on the result of the operation, @ofield{s.res} is changed.  *)

PROCEDURE (s: Socket) ConnectDone*;
(**When doing a non-blocking @oproc{Socket.Connect}, this procedure is
   used to determine the result of the connect call.  The usage scenario
   goes like this:
   
   @example
   allocate socket
   set socket to non-blocking mode
   call socket.Connect()
   
   IF (socket.res # done) & (socket.res.code # connectInProgress) THEN
     call Select(), with socket fd set in both read and write masks
     IF (read or write flag is set) THEN
       call ConnectDone()
       test result code in socket.res
     END
   END
   @end example
   *)

END IO:Socket.
