/*	$Id$	*/
/*  Generalized access to POSIX-style file descriptors.
    Copyright (C) 1997-2000  Michael van Acken

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
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <limits.h>
#include <string.h>
#include <sys/ioctl.h>


#include "__oo2c.h"
#include "__config.h"
#include "IO/PFD.d"

#if TIME_WITH_SYS_TIME
# include <sys/time.h>
# include <time.h>
#else
# if HAVE_SYS_TIME_H
#  include <sys/time.h>
# else
#  include <time.h>
# endif
#endif
#if HAVE_SOCKET_H
#include <socket.h>
#endif

#if HAVE_SYSLIMITS_H
#include <syslimits.h>
#endif

#ifndef SSIZE_MAX
/* for every POSIX.1 system the macro SSIZE_MAX is the limit on the number of
   bytes that can be read or written in a single operation; assume 2^15 if
   there is no other information available */
#ifdef POSIX_SSIZE_MAX
#define SSIZE_MAX POSIX_SSIZE_MAX
#else
#define SSIZE_MAX 32768
#endif
#endif

/* keep track whether the file descriptors 0-2 refer to the standard IO
   descriptors passed from the shell, or should be treated like any other
   descriptor */
static int standard_io[3] = {1, 1, 1};

static IO_PFD__ErrorContext IO_PFD__errorContext;


/* function definitions */

void IO_PFD__ErrorContextDesc_GetTemplate(IO_PFD__ErrorContext context, Msg__Msg msg, Msg__LString templ, OOC_LEN templ_0d) {
  char* str;
  
  if (msg->code == IO_PFD__wouldBlock) {
    str = "Operation would block";
  } else {
    str = NULL;
  }
  if (str) {
    _copy_8to16(str, templ, templ_0d);
  } else {
    /* super call to get first template string */
    STATIC_TBCALL(Channel,ErrorContextDesc,GetTemplate,context,
		  ((Channel__ErrorContext)context, msg, templ, templ_0d));
  }

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

static Msg__Msg get_error(Msg__Code code, int use_errno) {
  Msg__Msg msg;
  
  msg = Msg__New((Msg__Context)IO_PFD__errorContext, code);
  if (use_errno) {
#if HAVE_STRERROR
    char *errstr = strerror(errno);
    DYN_TBCALL(Msg,MsgDesc,SetStringAttrib,msg,
	       (msg, (const OOC_CHAR8*)"errstr", 7, (OOC_CHAR*)errstr));
#endif
    DYN_TBCALL(Msg,MsgDesc,SetIntAttrib,msg,
	       (msg, (const OOC_CHAR8*)"errno", 6, (OOC_INT32)errno));
  }
  return msg;
}

static void adjust_pos(IO_PFD__Channel ch, int pos) {
  if (ch->positionable && (ch->pos != pos)) {
    (void)lseek(ch->fd, pos, SEEK_SET);
    ch->pos = pos;
  }
}

static Msg__Msg write_error (IO_PFD__Channel ch) {
  if (errno == EBADF) {
    if (!ch->open) {
      return get_error(Channel__channelClosed, 0);
    } else {
      return get_error(Channel__invalidChannel, 1);
    }
  } else if (errno == ENOSPC) {
    return get_error(Channel__noRoom, 1);
#ifdef EDQUOT
  } else if (errno == EDQUOT) {
    return get_error(Channel__noRoom, 1);
#endif
  } else if ((errno == EAGAIN) || (errno == EWOULDBLOCK)) {
    return get_error(IO_PFD__wouldBlock, 1);
  } else {
    return get_error(Channel__writeError, 1);
  }
}

void IO_PFD__InitReader(IO_PFD__Reader r, IO_PFD__Channel ch) {
  r->base = (Channel__Channel)ch;
  r->res = Channel__done;
  r->bytesRead = -1;
  r->positionable = ch->positionable;
  r->pos = 0;
  DYN_TBCALL(Channel,ChannelDesc,ClearError,ch,((Channel__Channel)ch));
  if (!ch->positionable) {
    ch->reader = r;
  }
}

void IO_PFD__InitWriter(IO_PFD__Writer w, IO_PFD__Channel ch) {
  w->base = (Channel__Channel)ch;
  w->res = Channel__done;
  w->bytesWritten = -1;
  w->positionable = ch->positionable;
  w->pos = 0;
  DYN_TBCALL(Channel,ChannelDesc,ClearError,ch,((Channel__Channel)ch));
  if (!ch->positionable) {
    ch->writer = w;
  }
}



OOC_INT32 IO_PFD__ReaderDesc_Pos(IO_PFD__Reader r) {
  return (r->positionable) ? r->pos : Channel__noPosition;
}

OOC_INT32 IO_PFD__ReaderDesc_Available(IO_PFD__Reader r) {
  struct stat stat_buf;
  int res;
  OOC_INT32 len;
  IO_PFD__Channel ch = (IO_PFD__Channel)r->base;

  res = fstat(ch->fd, &stat_buf);
  
  if ((!r->base->open) || (res == -1)) {
    /* error; assume that channel has been closed */
    return -1;
  } else if (S_ISREG(stat_buf.st_mode)) {
    /* regular file; check position and size */
    len = stat_buf.st_size;
    res = len - r->pos;
    if (res < 0) {
      /* a previous SetPos might have moved the reading position past the end
         of the file; this is no error, put obviously no bytes can be read 
         there -- although this might change if the file is expanded */
      return 0;
    } else {
      return res;
    }
  } else {
#ifdef FIONREAD
    if (ioctl(ch->fd, FIONREAD, &len) < 0) {
      return -1;
    } else {
      return len;
    }
#else
    /* something else, like terminal or socket */
    fd_set set;
    struct timeval timeout;
    
    timeout.tv_sec = 0;
    timeout.tv_usec = 0;
    FD_ZERO(&set);
    FD_SET(ch->fd, &set);
    
    do {
      res = select(FD_SETSIZE, (void*)&set, NULL, NULL, &timeout);
    } while ((res == -1) && (errno == EINTR));
    
    /* res==-1: error; assume that channel has been closed
       res== 0: no input availbale
       res== 1: input available from channel */
    return res;
#endif
  }
}

void IO_PFD__ReaderDesc_SetPos(IO_PFD__Reader r, OOC_INT32 newPos) {
  if (r->res == Channel__done) {
    if (!r->base->open) {
      r->res = get_error(Channel__channelClosed, 0);
    } else if ((r->positionable) && (newPos >= 0)) {
      r->pos = newPos;
    } else {
      r->res = get_error(Channel__outOfRange, 0);
    }
  }
}


void IO_PFD__ReaderDesc_ReadBytes(IO_PFD__Reader r, OOC_BYTE* x, OOC_LEN x_0d, OOC_INT32 start, OOC_INT32 n) {
  IO_PFD__Channel ch = (IO_PFD__Channel)r->base;

  if (r->res == Channel__done) {
    size_t size, acc;
    ssize_t res;

    adjust_pos(ch, r->pos);
    /* read bytes from stream; repeat until all have been read successfully */
    x += start;
    acc = 0;
    do {
      /* make sure that no read request larger than the system limit is 
	 issued */
      size = n-acc;
      if (size > SSIZE_MAX) size = SSIZE_MAX;
      res = read(ch->fd, x+acc, (ssize_t)size);
      if (res >= 0) acc += res;
    } while (((res == -1) && (errno == EINTR)) ||
	     ((res > 0) && (acc < (size_t)n)));
    r->bytesRead = acc;
    r->pos += acc;
    ch->pos += acc;
    
    /* check error condition */
    if (res == -1) {
      if (errno == EBADF) {
	if (!ch->open) {
	  r->res = get_error(Channel__channelClosed, 0);
	} else {
	  r->res = get_error(Channel__invalidChannel, 1);
	}
      } else if ((errno == EAGAIN) || (errno == EWOULDBLOCK)) {
	r->res = get_error(IO_PFD__wouldBlock, 1);
      } else {
	r->res = get_error(Channel__readError, 1);
      }
    } else if ((res == 0) && (size != 0)) {
      /* we tried to read behind the end of file */
      r->res = get_error(Channel__readAfterEnd, 0);
    }

  } else {
    r->bytesRead = 0;
  }
}

void IO_PFD__ReaderDesc_ReadByte(IO_PFD__Reader r, OOC_BYTE *x) {
  IO_PFD__ReaderDesc_ReadBytes(r, x, 1, 0, 1);
}



OOC_INT32 IO_PFD__WriterDesc_Pos(IO_PFD__Writer w) {
  if (w->positionable) {
    return w->pos;
  } else {
    return Channel__noPosition;
  }
}

void IO_PFD__WriterDesc_SetPos(IO_PFD__Writer w, OOC_INT32 newPos) {
  if (w->res == Channel__done) {
    if (!w->base->open) {
      w->res = get_error(Channel__channelClosed, 0);
    } else if ((w->positionable) && (newPos >= 0)) {
      w->pos = newPos;
    } else {
      w->res = get_error(Channel__outOfRange, 0);
    }
  }
}

void IO_PFD__WriterDesc_WriteBytes(IO_PFD__Writer w, OOC_BYTE* x, OOC_LEN x_0d, OOC_INT32 start, OOC_INT32 n) {
  IO_PFD__Channel ch = (IO_PFD__Channel)w->base;

  if (w->res == Channel__done) {
    size_t size, acc;
    ssize_t res;

    adjust_pos(ch, w->pos);
    /* write bytes to stream; repeat until all have been written successfully*/
    x += start;
    acc = 0;
    do {
      /* make sure that no write request larger than the system limit is 
	 issued */
      size = n-acc;
      if (size > SSIZE_MAX) size = SSIZE_MAX;
      res = write(ch->fd, x+acc, size);
      if (res >= 0) acc += res;
    } while (((res == -1) && (errno == EINTR)) ||
	     ((res > 0) && (acc < (size_t)n)));
    w->bytesWritten = acc;
    w->pos += acc;
    ch->pos += acc;

    /* check error condition */
    if (res == -1) {
      w->res = write_error(ch);
    }
  } else {
    w->bytesWritten = 0;
  }
}

void IO_PFD__WriterDesc_WriteByte(IO_PFD__Writer w, OOC_BYTE x) {
  IO_PFD__WriterDesc_WriteBytes(w, &x, 1, 0, 1);
}



OOC_INT32 IO_PFD__ChannelDesc_Length(IO_PFD__Channel ch) {
  int res;
  struct stat stat_buf;
  OOC_INT32 len;

  res = fstat(ch->fd, &stat_buf);
  if (res == -1) {
    return Channel__noLength;
  } else {
    len = stat_buf.st_size;
    return len;
  }
}

/* define the day count of the Unix epoch (Jan 1 1970 00:00:00 GMT) for the
   Time.TimeStamp format */
#define days_to_epoch 40587
#define secs_per_day 86400

void IO_PFD__ChannelDesc_GetModTime(IO_PFD__Channel ch, Time__TimeStamp *mtime, RT0__Struct mtime__tag) {
  int res;
  struct stat stat_buf;

  res = fstat(ch->fd, &stat_buf);
  if (res == -1) {
    ch->res = get_error(Channel__noModTime, 0);
  } else {
    mtime->days = days_to_epoch + stat_buf.st_mtime / secs_per_day;
    mtime->msecs = (stat_buf.st_mtime % secs_per_day) * 1000;
#if HAVE_ST_MTIME_USEC
    mtime->msecs += (stat_buf.st_mtime_usec / 1000);
#endif
    ch->res = Channel__done;
  }
}

IO_PFD__Reader IO_PFD__ChannelDesc_NewReader(IO_PFD__Channel ch) {
  IO_PFD__Reader r = NULL;

  if (!ch->open) {
    ch->res = get_error(Channel__channelClosed, 0);
  } else if (ch->readable) {
    if (ch->positionable || (ch->reader == NULL)) {
      r = RT0__NewObject(OOC_TYPE_DESCR(IO_PFD,ReaderDesc));
      IO_PFD__InitReader (r, ch);
      if (!ch->positionable) {
	ch->reader = r;		/* store for reuse */
      }
    } else {
      /* channel doesn't support multiple readers, so just return the 
         one previously created */
      r = ch->reader;
    }
  } else {
    ch->res = get_error(Channel__noReadAccess, 0);
  }

  return r;
}

IO_PFD__Writer IO_PFD__ChannelDesc_NewWriter(IO_PFD__Channel ch) {
  IO_PFD__Writer w = NULL;

  if (!ch->open) {
    ch->res = get_error(Channel__channelClosed, 0);
  } else if (ch->writable) {
    if (ch->positionable || (ch->writer == NULL)) {
      w = RT0__NewObject(OOC_TYPE_DESCR(IO_PFD,WriterDesc));
      IO_PFD__InitWriter (w, ch);
      if (!ch->positionable) {
	ch->writer = w;		/* store for reuse */
      }
    } else {
      /* channel doesn't support multiple writers, so just return the 
         one previously created */
      w = ch->writer;
    }
  } else {
    ch->res = get_error(Channel__noWriteAccess, 0);
  }

  return w;
}

void IO_PFD__ChannelDesc_Flush(IO_PFD__Channel ch) {
}

void IO_PFD__ChannelDesc_Close(IO_PFD__Channel ch) {
  int res;

  /* flush the channel; this may be an upcall */
  DYN_TBCALL(Channel,ChannelDesc,Flush,ch,((Channel__Channel)ch));

  /* close the file descriptor; try again if the primitive is
     interrupted by signal */
  do {
    res = close(ch->fd);
  } while ((res == -1) && (errno == EINTR));
  if (ch->fd <= IO_PFD__stderrFileno) { 
    /* this fd isn't used for standard IO anymore */
    standard_io[ch->fd] = 0;
  }
  ch->fd = -1;	/* this ensure that future calls will get an EBADF error */

  /* only put a close error into ch->res if the flush succeeded; 
     otherwise keep the old error indication */
  if ((res == -1) && (ch->res == Channel__done)) {
    ch->res = write_error(ch);
  }

  /* mark channel as closed */
  ch->open = 0;
}

void IO_PFD__Init(IO_PFD__Channel ch, int fd, OOC_INT8 mode) {
/* Initializes channel `ch' to use file descriptor `fd' and access rights 
   `mode'.  
   The standard file descriptors that were passed from the shell are handled
   specially: positioning is disabled.  */
  struct stat stat_buf;

  ch->fd = fd;
  ch->pos = lseek(fd, 0, SEEK_CUR);
  ch->positionable = (ch->pos != -1);
  ch->reader = NULL;
  ch->writer = NULL;

  /* assume that this call never fails; otherwise someone handed us a bad file
     descriptor, which is forbidden :-) */
  (void)fstat(fd, &stat_buf);
  
  /* handle standard file descriptors: no positioning */
  if ((IO_PFD__stdinFileno<=fd) && (fd<=IO_PFD__stderrFileno) && standard_io[fd]) {
    ch->positionable = 0;
  }
  
  DYN_TBCALL(Channel,ChannelDesc,ClearError,ch,((Channel__Channel)ch));
  ch->readable = (mode == IO_PFD__readOnly) || (mode == IO_PFD__readWrite);
  ch->writable = (mode == IO_PFD__writeOnly) || (mode == IO_PFD__readWrite);
  ch->open = 1;
}

void IO_PFD__Truncate(IO_PFD__Writer w, OOC_INT32 newLength) {
  int res;

  if (w->res == Channel__done) {
    if (!w->base->open) {
      w->res = get_error(Channel__channelClosed, 0);
    } else {
      IO_PFD__Channel ch = (IO_PFD__Channel)w->base;
      do {
	/* mh, ftruncate is neither ANSI nor POSIX; if there is a system out
           there that doesn't support it we need to extend configure to check
	   for its presence and provide alternative code... --mva */
        res = ftruncate(ch->fd, newLength);
      } while ((res == -1) && (errno == EINTR));
      
      if (res == -1) {
        w->res = write_error((IO_PFD__Channel)w->base);
      }
    }
  }
}

void IO_PFD_init(void) {
  IO_PFD__errorContext =
    RT0__NewObject(OOC_TYPE_DESCR(IO_PFD,ErrorContextDesc));
  Msg__InitContext((Msg__Context)IO_PFD__errorContext, 
		   (const OOC_CHAR8*)"IO:PFD", 7);
}
