#include <__oo2c.h>
#include <__config.h>
#include <IO/PFD.d>

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <limits.h>
#include <string.h>

void IO_PFD__IOError(Object__String suffix) {
  RT0__Struct e_type;
  const int size_buffer = 1024;
#ifdef HAVE_STRERROR_R
  char buffer[size_buffer];
  char* err = strerror_r(errno, buffer, size_buffer);
#else
  char* err = strerror(errno);
#endif
  Object__String8 msg = Object__NewLatin1(err, size_buffer);
  Object__String str;
  Exception__Exception e;

  switch (errno) {
  case ENOENT:
    e_type = OOC_TYPE_DESCR(IO,FileNotFoundDesc); break;
  default:
    e_type = OOC_TYPE_DESCR(IO,ErrorDesc);
  }
  e = RT0__NewObject(e_type);
  
  if (suffix) {
    str = Object__Concat2((Object__String)Object__NewLatin1Region(": ",3,0,2),
			  suffix);
    str = Object__Concat2((Object__String)msg, str);
  } else {
    str = (Object__String)msg;
  }
  IO__InitError((IO__Error)e, str);
  Exception__Raise(e);
}

void IO_PFD__Init(IO_PFD__Channel ch, IO__FileDescriptor fd) {
  IO__InitByteChannel((IO__ByteChannel)ch);
  ch->fd = fd;
}

OOC_INT32 IO_PFD__ChannelDesc_Read(IO_PFD__Channel ch,
				    OOC_CHAR8 buffer[], OOC_LEN x_0d,
				    OOC_INT32 start, OOC_INT32 length) {
  ssize_t res;
  
  do {
    res = read(ch->fd, buffer+start, (size_t)length);
  } while ((res == -1) && (errno == EINTR));
  
  if (res == -1) {		/* check error condition */
    IO_PFD__IOError(NULL);
  } else if ((res == 0) && (length != 0)) {
    return -1;			/* end of file */
  }
  return res;			/* can be zero if size is zero */
}

OOC_INT32 IO_PFD__ChannelDesc_Write(IO_PFD__Channel ch,
				     const OOC_BYTE buffer[], OOC_LEN x_0d,
				     OOC_INT32 start, OOC_INT32 length) {
  ssize_t res;
  
  do {
    res = write(ch->fd, buffer+start, (size_t)length);
  } while ((res == -1) && (errno == EINTR));
  
  if (res == -1) {
    IO_PFD__IOError(NULL);
  }
  return res;
}

void IO_PFD__ChannelDesc_SetBlocking(IO_PFD__Channel ch, OOC_CHAR8 block) {
  /* not supported */
}

OOC_INT32 IO_PFD__ChannelDesc_FileDescriptor(IO_PFD__Channel ch) {
  return ch->fd;
}

static IO_PFD__Channel stdchannel(int fd) {
  IO_PFD__Channel ch = RT0__NewObject(OOC_TYPE_DESCR(IO_PFD,ChannelDesc));
  IO_PFD__Init(ch, fd);
  return ch;
}

void OOC_IO_PFD_init(void) {
 IO_PFD__stdin = stdchannel(STDIN_FILENO);
 IO_PFD__stdout = stdchannel(STDOUT_FILENO);
 IO_PFD__stderr = stdchannel(STDERR_FILENO);
}
