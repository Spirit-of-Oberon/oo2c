#include <__oo2c.h>
#include <__config.h>
#include <IO/Address.d>

#include <sys/types.h>
#ifdef __MINGW32__
#include <winsock.h>
#else
#include <netinet/in.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#endif
#include <string.h>
#ifdef HAVE_STDINT_H
#  include <stdint.h>
#else
#  ifdef __CYGWIN__
  typedef unsigned int uint32_t;
#  endif
#endif

static IO_Address__Inet4 new_inet4(uint32_t addr) {
  IO_Address__Inet4 in =
    RT0__NewObject(OOC_TYPE_DESCR(IO_Address,Inet4Desc));
  memcpy(in, &addr, sizeof(uint32_t));
  return in;
}

IO_Address__Inet IO_Address__GetByName(Object__String8 host) {
  
  if (host != NULL) {
    char* hname=(char*)OOC_METHOD(host,Object__String8Desc_CharsLatin1)(host);
    struct hostent *hostinfo = gethostbyname(hname);
    
    if (hostinfo == NULL) {
      Exception__Exception e =
	RT0__NewObject(OOC_TYPE_DESCR(IO_Address,UnknownHostExceptionDesc));
      IO__ErrorDesc_INIT((IO__Error)e, (Object__String)host);
      Exception__Raise(e);
    } else {
      return (IO_Address__Inet)new_inet4(ntohl(*(uint32_t*)hostinfo->h_addr));
    }
  } else {
    return (IO_Address__Inet)IO_Address__inet4Loopback;
  }
}

IO_Address__SocketInet IO_Address__GetSocketInet(IO_Address__Inet host,
						   OOC_INT32 port) {
  IO_Address__SocketInet addr =
    RT0__NewObject(OOC_TYPE_DESCR(IO_Address,SocketInetDesc));
  addr->host = host;
  addr->port = port;
  return addr;
}

IO_Address__SockAddr IO_Address__SocketDesc_GetSockAddr(IO_Address__Socket s) {
  return NULL;  /* declared abstract */
}

Object__String IO_Address__Inet4Desc_ToString(IO_Address__Inet4 addr) {
  struct in_addr inaddr;
  char* a;
  int len;
  
  inaddr.s_addr = htonl(addr->addr);
  a = inet_ntoa(inaddr);
  len = strlen(a);
  return (Object__String)Object__NewLatin1Region(a, len, 0, len);
}

OOC_CHAR8 IO_Address__Inet4Desc_Equals(IO_Address__Inet4 addr, Object__Object y) {
  if (y && OOC_TYPE_TEST(OOC_TYPE_DESCR(IO_Address,Inet4Desc),
			 OOC_TYPE_TAG(y))) {
    return (addr->addr == ((IO_Address__Inet4)y)->addr);
  } else {
    return 0;
  }
}

OOC_INT32 IO_Address__Inet4Desc_HashCode(IO_Address__Inet4 addr) {
  return addr->addr;
}


IO_Address__SockAddr IO_Address__SocketInetDesc_GetSockAddr(IO_Address__SocketInet s) {
  RT0__Struct tag = OOC_TYPE_TAG(s->host);
  
  if (OOC_TYPE_TEST(tag,OOC_TYPE_DESCR(IO_Address,Inet4Desc))) {
    struct sockaddr_in *addr =
      RT0__NewObject(OOC_PTRBASE_DESCR(IO_Address,SockAddr),
		     sizeof(struct sockaddr_in));
    addr->sin_family = AF_INET;
    addr->sin_addr.s_addr = htonl(*(uint32_t*)s->host);
    addr->sin_port = htons((unsigned short int)s->port);
    return (IO_Address__SockAddr)addr;
  } else {
    return NULL;  /* handle IPv6 addresses here */
  }
}

Object__String IO_Address__SocketInetDesc_ToString(IO_Address__SocketInet s) {
  Object__Object obj = (Object__Object)s->host;
  Object__String host;
  char str[16];
  int len;
  
  host = OOC_METHOD(obj,Object__ObjectDesc_ToString)(obj);
  len = sprintf(str, ":%d", s->port);
  return Object__Concat2
    (host, (Object__String)Object__NewLatin1Region(str, len, 0, len));
}

OOC_CHAR8 IO_Address__SocketInetDesc_Equals(IO_Address__SocketInet s, Object__Object y) {
  if (y && OOC_TYPE_TEST(OOC_TYPE_DESCR(IO_Address,Inet4Desc),
			 OOC_TYPE_TAG(y))) {
    IO_Address__SocketInet ys = (IO_Address__SocketInet)y;
    return (s->port == ys->port) &&
      OOC_METHOD(s->host,Object__ObjectDesc_Equals)
	((Object__Object)s->host, (Object__Object)ys->host);
  } else {
    return 0;
  }
}

OOC_INT32 IO_Address__SocketInetDesc_HashCode(IO_Address__SocketInet s) {
  Object__Object obj = (Object__Object)s->host;
  Object__Hash h = OOC_METHOD(obj,Object__ObjectDesc_HashCode)(obj);
  return h ^ s->port;
}

void OOC_IO_Address_init(void) {
  IO_Address__inet4Loopback = new_inet4(INADDR_LOOPBACK);
  IO_Address__inet4Any = new_inet4(INADDR_ANY);
  IO_Address__inet4Broadcast = new_inet4(INADDR_BROADCAST);
}
