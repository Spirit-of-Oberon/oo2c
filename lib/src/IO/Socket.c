#include <__oo2c.h>
#include <__config.h>
#include <IO/Socket.d>

#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <errno.h>

IO_Socket__Socket IO_Socket__New() {
  IO_Socket__Socket s =
    RT0__NewObject(OOC_TYPE_DESCR(IO_Socket,SocketDesc));
  s->fd = socket(PF_INET, SOCK_STREAM, 0);
  if (s->fd < 0) {
    IO_StdChannels__IOError(NULL);
  }
  return s;
}

void IO_Socket__SocketDesc_SetBlocking(IO_Socket__Socket s, OOC_CHAR8 block) {
  int delay_flag = fcntl(s->fd, F_GETFL, 0);
  if (delay_flag < 0) {
    IO_StdChannels__IOError(NULL);
  }
  if (block) {
    delay_flag &= (~O_NDELAY);
  } else {
    delay_flag |= O_NDELAY;
  }
  if (fcntl(s->fd, F_SETFL, delay_flag) < 0) {
    IO_StdChannels__IOError(NULL);
  }
}

void IO_Socket__SocketDesc_Bind(IO_Socket__Socket s,
				 IO_Address__Socket bindPoint) {
  struct sockaddr *addr;
  
  addr = (struct sockaddr *)
    OOC_METHOD(bindPoint,IO_Address__SocketDesc_GetSockAddr)(bindPoint);
  if (bind(s->fd, addr, OOC_ARRAY_LENGTH(addr,0)) < 0) {
    IO_StdChannels__IOError(NULL);
  }
}

void IO_Socket__SocketDesc_Connect(IO_Socket__Socket s,
				    IO_Address__Socket endPoint) {
  struct sockaddr *addr;
  
  addr = (struct sockaddr *)
    OOC_METHOD(endPoint,IO_Address__SocketDesc_GetSockAddr)(endPoint);
  if (connect(s->fd, addr, OOC_ARRAY_LENGTH(addr,0)) < 0) {
    IO_StdChannels__IOError(NULL);
  }
}

IO_Address__Socket IO_Socket__SocketDesc_RemoteAddress(IO_Socket__Socket s) {
  if (s->fd < 0) {
    return NULL;
  } else {
    IO_Address__Inet4 inet4;
    
    struct sockaddr_in clientname;
    int size = sizeof(clientname);
    if (getpeername(s->fd, (struct sockaddr*)&clientname, &size) < 0) {
      IO_StdChannels__IOError(NULL);
    }
    
    inet4 = RT0__NewObject(OOC_TYPE_DESCR(IO_Address,Inet4Desc));
    inet4->addr = ntohl(clientname.sin_addr.s_addr);
    return (IO_Address__Socket)
      IO_Address__GetSocketInet((IO_Address__Inet)inet4,
				 clientname.sin_port);
  }
}

void IO_Socket__SocketDesc_Close(IO_Socket__Socket s) {
  if (close(s->fd) < 0) {
    IO_StdChannels__IOError(NULL);
  }
  s->fd = -1;
}



IO_Socket__Server IO_Socket__NewServer() {
  IO_Socket__Server s =
    RT0__NewObject(OOC_TYPE_DESCR(IO_Socket,ServerDesc));
  s->fd = socket(AF_INET, SOCK_STREAM, 0);
  return s;
}

void IO_Socket__ServerDesc_SetReuseAddress(IO_Socket__Server s, OOC_CHAR8 on) {
  int i = on?1:0;
  if (setsockopt(s->fd, SOL_SOCKET, SO_REUSEADDR, (void*)&i, sizeof(i)) < 0) {
    IO_StdChannels__IOError(NULL);
  }
}

void IO_Socket__ServerDesc_SetBlocking(IO_Socket__Server s, OOC_CHAR8 block) {
  int delay_flag = fcntl(s->fd, F_GETFL, 0);
  if (delay_flag < 0) {
    IO_StdChannels__IOError(NULL);
  }
  if (block) {
    delay_flag &= (~O_NDELAY);
  } else {
    delay_flag |= O_NDELAY;
  }
  if (fcntl(s->fd, F_SETFL, delay_flag) < 0) {
    IO_StdChannels__IOError(NULL);
  }
}

void IO_Socket__ServerDesc_Bind(IO_Socket__Server s,
				       IO_Address__Socket bindPoint,
				       OOC_INT32 queueSize) {
  struct sockaddr *addr;
  
  addr = (struct sockaddr *)
    OOC_METHOD(bindPoint,IO_Address__SocketDesc_GetSockAddr)(bindPoint);
  if (bind(s->fd, addr, OOC_ARRAY_LENGTH(addr,0)) < 0) {
    IO_StdChannels__IOError(NULL);
  }
  if (listen(s->fd, (unsigned int)queueSize) < 0) {
    IO_StdChannels__IOError(NULL);
  }
}

IO_Socket__Socket IO_Socket__ServerDesc_Accept(IO_Socket__Server s) {
  struct sockaddr_in clientname;
  IO_Socket__Socket c =
    RT0__NewObject(OOC_TYPE_DESCR(IO_Socket,SocketDesc));
  int size = sizeof(clientname);
  int fd = accept(s->fd, (struct sockaddr*)&clientname, &size);

  if (fd < 0) {
    if (errno == EWOULDBLOCK) {
      return NULL;
    } else {
      IO_StdChannels__IOError(NULL);
    }
  }
  c->fd = fd;
  return c;
}

void IO_Socket__ServerDesc_Close(IO_Socket__Server s) {
  if (close(s->fd) < 0) {
    IO_StdChannels__IOError(NULL);
  }
  s->fd = -1;
}


OOC_INT32 IO_Socket__Read(IO_Socket__Socket ch,
			   OOC_CHAR8 buffer[], OOC_LEN x_0d,
			   OOC_INT32 start, OOC_INT32 length) {
  ssize_t res;
  
  do {
    res = read(ch->fd, buffer+start, (size_t)length);
  } while ((res == -1) && (errno == EINTR));
  
  if (res == -1) {		/* check error condition */
    if (errno == EWOULDBLOCK) {
      return 0;
    } else {
      IO_StdChannels__IOError(NULL);
    }
  } else if ((res == 0) && (length != 0)) {
    return -1;			/* end of file */
  }
  return res;			/* can be zero if size is zero */
}

OOC_INT32 IO_Socket__Write(IO_Socket__Socket ch,
			    const OOC_BYTE buffer[], OOC_LEN x_0d,
			    OOC_INT32 start, OOC_INT32 length) {
  ssize_t res;
  
  do {
    res = write(ch->fd, buffer+start, (size_t)length);
  } while ((res == -1) && (errno == EINTR));
  
  if (res == -1) {
    if (errno == EWOULDBLOCK) {
      return 0;
    } else {
      IO_StdChannels__IOError(NULL);
    }
  }
  return res;
}


void OOC_IO_Socket_init(void) {
}
