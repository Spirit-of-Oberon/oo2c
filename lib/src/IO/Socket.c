/*	$Id$	*/
/*  Interface to socket facilities.
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
*/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>

#if defined(__CYGWIN__) || defined(__APPLE__)
typedef unsigned short uint16_t;
#endif

#include "__oo2c.h"
#include "__config.h"
#include "IO/Socket.d"

int IO_Socket__AF_INET = AF_INET;
int IO_Socket__AF_UNIX = AF_UNIX;
int IO_Socket__AF_UNSPEC = AF_UNSPEC;
int IO_Socket__SOCK_STREAM = SOCK_STREAM;
int IO_Socket__SOCK_DGRAM = SOCK_DGRAM;
unsigned int IO_Socket__MSG_DONTROUTE = MSG_DONTROUTE;
unsigned int IO_Socket__MSG_OOB = MSG_OOB;
unsigned int IO_Socket__MSG_PEEK = MSG_PEEK;
#ifdef MSG_DONTWAIT
unsigned int IO_Socket__MSG_DONTWAIT = MSG_DONTWAIT;
#else
unsigned int IO_Socket__MSG_DONTWAIT = 0;
#endif
#ifdef MSG_WAITALL
unsigned int IO_Socket__MSG_WAITALL = MSG_WAITALL;
#else
unsigned int IO_Socket__MSG_WAITALL = 0;
#endif

#ifdef SHUT_RD
int IO_Socket__SHUT_RD = SHUT_RD;
int IO_Socket__SHUT_WR = SHUT_WR;
int IO_Socket__SHUT_RDWR = SHUT_RDWR;
#else
int IO_Socket__SHUT_RD = 0;
int IO_Socket__SHUT_WR = 1;
int IO_Socket__SHUT_RDWR = 2;
#endif

static IO_Socket__ErrorContext IO_Socket__errorContext;
Channel__Result IO_Socket__errorWouldBlock;


void IO_Socket__ErrorContextDesc_GetTemplate(IO_Socket__ErrorContext context, Msg__Msg msg, Msg__LString templ, OOC_LEN templ_0d) {
  char *str;
  OOC_INT32 res = msg->code;
  
  if (res == IO_Socket__protocolNotSupported) {
    str = "Protocol not supported";
  } else if (res == IO_Socket__processTooManyFileDescriptors) {
    str = "Too many file descriptors open for process";
  } else if (res == IO_Socket__systemTooManyFileDescriptors) {
    str = "Too many file descriptors open for system";
  } else if (res == IO_Socket__accessDenied) {
    str = "Process does not have privilege to open this socket";
  } else if (res == IO_Socket__noBuffers) {
    str = "System ran out of internal buffer space";
  } else if (res == IO_Socket__socketError) {
    str = "Unknown socket error";
  } else if (res == IO_Socket__badFileDescriptor) {
    str = "Socket is not a valid file descriptor";
  } else if (res == IO_Socket__notSocket) {
    str = "File descriptor is not a socket";
  } else if (res == IO_Socket__addrNotAvailable) {
    str = "Address is not available on remote machine";
  } else if (res == IO_Socket__addrFamilyNotSupported) {
    str = "Address family is not supported by socket";
  } else if (res == IO_Socket__isConnected) {
    str = "Socket already connected";
  } else if (res == IO_Socket__timedOut) {
    str = "Attempt to establish a connection timed out";
  } else if (res == IO_Socket__connectionRefused) {
    str = "Remote server refused to establish connection";
  } else if (res == IO_Socket__networkUnreachable) {
    str = "Network of given address not reachable";
  } else if (res == IO_Socket__addrInUse) {
    str = "Socket address already in use";
  } else if (res == IO_Socket__connectInProgress) {
    str = "Non-blocking socket could not establish connection immediately";
  } else if (res == IO_Socket__connectAlreadyInProgress) {
    str = "Non-blocking socket has a pending connection in progress";
  } else if (res == IO_Socket__connectionTerminated) {
    str = "Connection terminated";
  } else {
    str = NULL;
  } 

  _copy_8to16(str, templ, templ_0d);
  if (msg->attribList) {
    Msg__Attribute attr;
    OOC_CHAR16 eol[2] = {(OOC_CHAR16)CharClass__eol[0], (OOC_CHAR16)0};
    OOC_CHAR16 str16[Msg__sizeAttrName+1];

    attr = msg->attribList;
    while (attr) {
      LongStrings__Append(eol, 2, templ, templ_0d);
      _copy_8to16((char*)attr->name, str16, strlen((char*)attr->name)+1);
      LongStrings__Append(str16, Msg__sizeAttrName+1, templ, templ_0d);
      _copy_8to16("=${", str16, Msg__sizeAttrName+1);
      LongStrings__Append(str16, Msg__sizeAttrName+1, templ, templ_0d);
      _copy_8to16((char*)attr->name, str16, Msg__sizeAttrName+1);
      LongStrings__Append(str16, Msg__sizeAttrName+1, templ, templ_0d);
      _copy_8to16("}", str16, Msg__sizeAttrName+1);
      LongStrings__Append(str16, Msg__sizeAttrName+1, templ, templ_0d);
      attr = attr->nextAttrib;
    }
  }
}


static void add_msg_attribute(Msg__Msg msg, const char* name, const char* value) {
  DYN_TBCALL(Msg,MsgDesc,SetStringAttrib,msg,
	     (msg, (const OOC_CHAR8*)name, strlen(name)+1,
              Msg__GetStringPtr((OOC_CHAR8*)value, strlen(value)+1)));
}

static Msg__Msg get_error (int res) {
  Msg__Code code;
  Msg__Msg msg;
  
  if (res != -1) {
    return IO_Socket__done;
  } else if (errno == EWOULDBLOCK) {
    return IO_Socket__errorWouldBlock;
  } else {
    switch (errno) {
    case EPROTONOSUPPORT:
      code = IO_Socket__protocolNotSupported; break;
    case EMFILE:
      code = IO_Socket__processTooManyFileDescriptors; break;
    case ENFILE:
      code = IO_Socket__systemTooManyFileDescriptors; break;
    case EACCES:
      code = IO_Socket__accessDenied; break;
    case ENOBUFS:
      code = IO_Socket__noBuffers; break;

    case EBADF:
      code = IO_Socket__badFileDescriptor; break;
    case ENOTSOCK:
      code = IO_Socket__notSocket; break;
    case EADDRNOTAVAIL:
      code = IO_Socket__addrNotAvailable; break;
    case EAFNOSUPPORT:
      code = IO_Socket__addrFamilyNotSupported; break;
    case EISCONN:
      code = IO_Socket__isConnected; break;
    case ETIMEDOUT:
      code = IO_Socket__timedOut; break;
    case ECONNREFUSED:
      code = IO_Socket__connectionRefused; break;
    case ENETUNREACH:
      code = IO_Socket__networkUnreachable; break;
    case EADDRINUSE:
      code = IO_Socket__addrInUse; break;
    case EINPROGRESS:
      code = IO_Socket__connectInProgress; break;
    case EALREADY:
      code = IO_Socket__connectAlreadyInProgress; break;
    
    default:
      code = IO_Socket__socketError;
    }

    msg = Msg__New((Msg__Context)IO_Socket__errorContext, code);
#if HAVE_STRERROR
    add_msg_attribute(msg, "errstr", strerror(errno));
#endif
    DYN_TBCALL(Msg,MsgDesc,SetIntAttrib,msg,
	(msg, (const OOC_CHAR8*)"errno", 6, (OOC_INT32)errno));

    return msg;
  }
}
static Msg__Msg get_error_bytes (int res, OOC_INT32 nbytes) {
  if ((res == 0) && (nbytes != 0)) {
    Msg__Msg msg;
    
    msg = Msg__New((Msg__Context)IO_Socket__errorContext, 
		   IO_Socket__connectionTerminated);
#if HAVE_STRERROR
    add_msg_attribute(msg, "errstr", "Connection terminated");
#endif
    return msg;
  } else if (res != -1) {
    return IO_Socket__done;
  } else {
    return get_error(res);
  }
}

void IO_Socket__Init(IO_Socket__Socket s, int family, int type, int protocol, Msg__Msg *res) {
  s->fd = socket(family, type, protocol);
  s->res = IO_Socket__done;
  *res = get_error(s->fd);
}

IO_Socket__Socket IO_Socket__New(int family, int type, int protocol, Msg__Msg *res) {
  IO_Socket__Socket s;
  
  s = RT0__NewObject(OOC_TYPE_DESCR(IO_Socket,SocketDesc));
  IO_Socket__Init (s, family, type, protocol, res);
  return *res ? NULL : s;
}

void IO_Socket__InitFromFD(IO_Socket__Socket s, int fd, int family, int type, int protocol, Msg__Msg *res) {
  s->fd = fd;
  s->res = IO_Socket__done;
}

IO_Socket__Socket IO_Socket__NewFromFD(int fd, int family, int type, int protocol, Msg__Msg *res) {
  IO_Socket__Socket s;
  
  s = RT0__NewObject(OOC_TYPE_DESCR(IO_Socket,SocketDesc));
  IO_Socket__InitFromFD (s, fd, family, type, protocol, res);
  return s;
}

void IO_Socket__InitSockAddrINET(IO_Socket__sockaddr_in *addr, RT0__Struct addr__tag, const unsigned char* hostname, OOC_LEN hostname_0d, int port) {
  struct hostent *hostinfo;
  
  addr->sin_family = AF_INET;
  addr->sin_port = htons ((uint16_t )port);
  if (hostname[0] != '\000') {
    hostinfo = gethostbyname ((const char*)hostname);
    if (hostinfo == NULL) {
      addr->sin_family = AF_UNSPEC;
    } else {
      addr->sin_addr = *(IO_Socket__in_addr*) hostinfo->h_addr;
    }
  } else {
    addr->sin_addr.saddr = htonl(INADDR_ANY);
  }
}

Channel__Channel IO_Socket__SocketDesc_GetChannel(IO_Socket__Socket s) {
  IO_PFD__Channel ch;
  
  ch = RT0__NewObject(OOC_TYPE_DESCR(IO_PFD,ChannelDesc));
  IO_PFD__Init(ch, dup(s->fd), IO_PFD__readWrite);
  s->res = IO_Socket__done;
  return (Channel__Channel)ch;
}

IO_Socket__Socket IO_Socket__SocketDesc_Accept(IO_Socket__Socket s, IO_Socket__SockAddrParam cliaddr, OOC_LEN cliaddr_0d, int *addrlen) {
  int res;
  
  res = accept(s->fd, (struct sockaddr*)cliaddr, addrlen);
  s->res = get_error(res);
  if (res == -1) {
    return NULL;
  } else {
    return IO_Socket__NewFromFD(res, -1, -1, -1, &s->res);
  }
}

void IO_Socket__SocketDesc_Bind(IO_Socket__Socket s, IO_Socket__SockAddrParam myaddr, OOC_LEN myaddr_0d, OOC_INT32 addrlen) {
  s->res = get_error(bind(s->fd, (struct sockaddr*)myaddr, addrlen));
}

void IO_Socket__SocketDesc_Close(IO_Socket__Socket s) {
  int res;

  /* close the file descriptor; try again if the primitive is
     interrupted by signal */
  do {
    res = close(s->fd);
  } while ((res == -1) && (errno == EINTR));
  s->fd = -1;	/* this ensure that future calls will get an EBADF error */
  s->res = get_error(res);
}

void IO_Socket__SocketDesc_Connect(IO_Socket__Socket s, IO_Socket__SockAddrParam servaddr, OOC_LEN servaddr_0d, OOC_INT32 addrlen) {
  int res;
  
  res = connect(s->fd, (struct sockaddr*)servaddr, addrlen);
  s->res = get_error(res);
}

void IO_Socket__SocketDesc_GetPeerName(IO_Socket__Socket s, IO_Socket__SockAddrParam peeraddr, OOC_LEN peeraddr_0d, int *addrlen) {
  s->res = get_error(getpeername(s->fd, (struct sockaddr*)peeraddr, addrlen));
}

void IO_Socket__SocketDesc_GetSockName(IO_Socket__Socket s, IO_Socket__SockAddrParam localaddr, OOC_LEN localaddr_0d, int *addrlen) {
  s->res = get_error(getsockname(s->fd, (struct sockaddr*)localaddr, addrlen));
}

void IO_Socket__SocketDesc_Listen(IO_Socket__Socket s, int backlog) {
  s->res = get_error(listen(s->fd, backlog));
}

int IO_Socket__SocketDesc_Recv(IO_Socket__Socket s, unsigned char* buff, OOC_LEN buff_0d, OOC_INT32 start, OOC_INT32 nbytes, unsigned int flags) {
  int res;
  
  do {
    res = recv(s->fd, buff+start, nbytes, flags);
  } while ((res == -1) && (errno == EINTR));
  s->res = get_error_bytes(res, nbytes);
  return res;
}

int IO_Socket__SocketDesc_Send(IO_Socket__Socket s, unsigned char* buff, OOC_LEN buff_0d, OOC_INT32 start, OOC_INT32 nbytes, unsigned int flags) {
  int res;
  
  do {
    res = send(s->fd, buff+start, nbytes, flags);
  } while ((res == -1) && (errno == EINTR));
  s->res = get_error_bytes(res, nbytes);
  return res;
}

int IO_Socket__SocketDesc_RecvFrom(IO_Socket__Socket s, unsigned char* buff, OOC_LEN buff_0d, OOC_INT32 start, OOC_INT32 nbytes, unsigned int flags, IO_Socket__SockAddrParam from, OOC_LEN from_0d, int *addrlen) {
  int res;
  
  do {
    res = recvfrom(s->fd, buff+start, nbytes, flags,
                   (struct sockaddr*)from, addrlen);
  } while ((res == -1) && (errno == EINTR));
  s->res = get_error_bytes(res, nbytes);
  return res;
}

int IO_Socket__SocketDesc_SendTo(IO_Socket__Socket s, unsigned char* buff, OOC_LEN buff_0d, OOC_INT32 start, OOC_INT32 nbytes, unsigned int flags, IO_Socket__SockAddrParam to, OOC_LEN to_0d, int addrlen) {
  int res;
  
  do {
    res = sendto(s->fd, buff+start, nbytes, flags,
                 (struct sockaddr*)to, addrlen);
  } while ((res == -1) && (errno == EINTR));
  s->res = get_error_bytes(res, nbytes);
  return res;
}

void IO_Socket__SocketDesc_SetBlocking(IO_Socket__Socket s, OOC_BOOLEAN blocking) {
  int delay_flag;
  
  delay_flag = fcntl(s->fd, F_GETFL, 0);
  if (blocking) {
    delay_flag &= (~O_NDELAY);
  } else {
    delay_flag |= O_NDELAY;
  }
  fcntl(s->fd, F_SETFL, delay_flag);
}

void IO_Socket__SocketDesc_Shutdown(IO_Socket__Socket s, int howto) {
  s->res = get_error(shutdown(s->fd, howto));
}

void IO_Socket__SocketDesc_SetReuseAddress(IO_Socket__Socket s) {
  int i = 1;
  s->res = get_error(setsockopt(s->fd, SOL_SOCKET, SO_REUSEADDR,
                     (void*)&i, sizeof(i)));
}

void IO_Socket__SocketDesc_ConnectDone(IO_Socket__Socket s) {
  int error, len, rc;
  
  len = sizeof(error);
  if ((rc = getsockopt(s->fd, SOL_SOCKET, SO_ERROR, (void*)&error, &len)) < 0) {
    s->res = get_error(rc);	/* Solaris pending error */
  } else {
    /* Berkeley-derived implementations return an rc of 0, with the
       pending error returned in error */
    if (error) {
      errno = error;
      s->res = get_error(-1);
    } else {
      s->res = IO_Socket__done;
    }
  }
}


void IO_Socket_init(void) {
  IO_Socket__errorContext =
    RT0__NewObject(OOC_TYPE_DESCR(IO_Socket,ErrorContextDesc));
  Msg__InitContext((Msg__Context)IO_Socket__errorContext, 
		   (const OOC_CHAR8*)"IO:Socket", 10);

  IO_Socket__errorWouldBlock = Msg__New((Msg__Context)IO_Socket__errorContext,
					IO_Socket__wouldBlock);
#if HAVE_STRERROR
  add_msg_attribute(IO_Socket__errorWouldBlock, "errstr",
		    strerror(EWOULDBLOCK));
#endif
  DYN_TBCALL(Msg,MsgDesc,SetIntAttrib,IO_Socket__errorWouldBlock,
	     (IO_Socket__errorWouldBlock, (const OOC_CHAR8*)"errno",
	      6, (OOC_INT32)EWOULDBLOCK));
}
