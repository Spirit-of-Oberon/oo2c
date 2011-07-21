/*	$Id: PosixFileDescr.c,v 1.11 2004/12/15 11:27:03 mva Exp $	*/
/*  Generalized access to POSIX-style file descriptors.
    Copyright (C) 1997-2000, 2002  Michael van Acken

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
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <limits.h>
#include <string.h>

#include <__oo2c.h>
#include <__config.h>

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
#if HAVE_UNISTD_H
#include <unistd.h>
#elif HAVE_IO_H
#include <io.h>
#endif

#ifdef __MINGW32__
#include <fcntl.h>
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

#define _MODULE_libc_ /* don't pull in declaration from the `libc' module */
#include <PosixFileDescr.d>

/* keep track whether the file descriptors 0-2 refer to the standard IO
   descriptors passed from the shell, or should be treated like any other
   descriptor */
static int standard_io[3] = {1, 1, 1};

static PosixFileDescr__ErrorContext PosixFileDescr__errorContext;



/* function definitions */

void PosixFileDescr__ErrorContextDesc_GetTemplate(PosixFileDescr__ErrorContext context, Msg__Msg msg, Msg__LString templ, OOC_INT32 templ_0d) {
  /* super call to get first template string; this module adds no error 
     codes beyond the list given in Channel.Mod */
  STATIC_TBCALL(Channel,ErrorContextDesc,GetTemplate,context,
		((Channel__ErrorContext)context, msg, templ, templ_0d));
  
  if (msg->attribList) {
    Msg__Attribute attr;
    OOC_CHAR16 eol[2] = {(OOC_CHAR16)CharClass__eol, (OOC_CHAR16)0};
    OOC_CHAR16 str16[Msg__sizeAttrName+1];
    
    /*LongStrings__Append(eol, 2, templ, templ_0d);*/
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
  
  msg = Msg__New((Msg__Context)PosixFileDescr__errorContext, code);
  if (use_errno) {
#if HAVE_STRERROR
    char *errstr = strerror(errno);
    DYN_TBCALL(Msg,MsgDesc,SetStringAttrib,msg,
	       (msg, (const OOC_CHAR8*)"errstr", 7, (OOC_CHAR8*)errstr));
#endif
    DYN_TBCALL(Msg,MsgDesc,SetIntAttrib,msg,
	       (msg, (const OOC_CHAR8*)"errno", 6, (OOC_INT32)errno));
  }
  return msg;
}

static void adjust_pos(PosixFileDescr__Channel ch, int pos) {
  if (ch->positionable && (ch->pos != pos)) {
    (void)lseek(ch->fd, pos, SEEK_SET);
    ch->pos = pos;
  }
}

static Msg__Msg write_error(void) {
  if (errno == EBADF) {
    return get_error(Channel__invalidChannel, 1);
  } else if (errno == ENOSPC) {
    return get_error(Channel__noRoom, 1);
#ifdef EDQUOT
  } else if (errno == EDQUOT) {
    return get_error(Channel__noRoom, 1);
#endif
  } else {
    return get_error(Channel__writeError, 1);
  }
}

static Msg__Msg read_error(void) {
  if (errno == EBADF) {
    return get_error(Channel__invalidChannel, 1);
  } else {
    return get_error(Channel__readError, 1);
  }
}

static Msg__Msg read_bytes(PosixFileDescr__Channel ch, OOC_INT32 pos, OOC_INT32 n,
                           OOC_BYTE *x, OOC_INT32 *bytes_read) {
/* Reads only a single line for line buffered input from terminal; in this case
   `n´ should be large enough to hold a single line.  */
  size_t size, acc;
  ssize_t res;
  
  adjust_pos(ch, pos);
  /* read bytes from stream; repeat until all have been read successfully */
  acc = 0;
  do {
    /* make sure that no read request larger than the system limit is 
       issued */
    size = n-acc;
    if (size > SSIZE_MAX) size = SSIZE_MAX;
    res = read(((PosixFileDescr__Channel)ch)->fd, x+acc, (ssize_t)size);
    /* note: for a terminal in canonical input mode the above read will at most
       return a single line, independent of the requested size; I hope that
       SSIZE_MAX is larger than MAX_CANON... */
    if (res >= 0) acc += res;
  } while (((res == -1) && (errno == EINTR)) ||
	   ((res > 0) && (acc < (size_t)n) && 
	    (ch->buffering != PosixFileDescr__lineBuffer)));
  *bytes_read = acc;
  ch->pos += acc;
  
  /* check error condition */
  if (res == -1) {
    return read_error();
  } else if ((res == 0) && (size != 0)) {
    /* we tried to read behind the end of file */
    return get_error(Channel__readAfterEnd, 0);
  } else {
    return Channel__done;
  }
}

static Msg__Msg write_bytes(PosixFileDescr__Channel ch, OOC_INT32 pos, OOC_INT32 n,
                            const OOC_BYTE *x, OOC_INT32 *bytes_written) {
  size_t size, acc;
  ssize_t res;
  
  adjust_pos(ch, pos);
  /* write bytes to stream; repeat until all have been written successfully */
  acc = 0;
  do {
    /* make sure that no write request larger than the system limit is 
       issued */
    size = n-acc;
    if (size > SSIZE_MAX) size = SSIZE_MAX;
    res = write(((PosixFileDescr__Channel)ch)->fd, x+acc, size);
    if (res >= 0) acc += res;
  } while (((res == -1) && (errno == EINTR)) ||
           ((res > 0) && (acc < (size_t)n)));
  *bytes_written = acc;
  ch->pos += acc;
  
  /* check error condition */
  if (res == -1) {
    return write_error();
  } else {
    return Channel__done;
  }
}

static Msg__Msg flush_buffer(PosixFileDescr__Channel ch) {
  OOC_INT32 bytesWritten;
  
  if ((ch->buffering != PosixFileDescr__noBuffer) && ch->dirty) {
    ch->dirty = 0;
    return write_bytes(ch, ch->bufStart, ch->bufEnd - ch->bufStart, 
                       ch->buf, &bytesWritten);
  } else {
    return Channel__done;
  }
}

void PosixFileDescr__InitReader(PosixFileDescr__Reader r, PosixFileDescr__Channel ch) {
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

void PosixFileDescr__InitWriter(PosixFileDescr__Writer w, PosixFileDescr__Channel ch) {
  w->base = (Channel__Channel)ch;
  w->res = Channel__done;
  w->bytesWritten = -1;
  w->positionable = ch->positionable && !ch->append;
  w->pos = 0;
  DYN_TBCALL(Channel,ChannelDesc,ClearError,ch,((Channel__Channel)ch));
  if (!ch->positionable) {
    ch->writer = w;
  }
}



OOC_INT32 PosixFileDescr__ReaderDesc_Pos(PosixFileDescr__Reader r) {
  if (r->positionable) {
    return r->pos;
  } else {
    return Channel__noPosition;
  }
}

int PosixFileDescr__ReaderDesc_Available(PosixFileDescr__Reader r) {
  struct stat stat_buf;
  int res;
  OOC_INT32 len;
  PosixFileDescr__Channel ch = (PosixFileDescr__Channel)r->base;

  res = fstat(ch->fd, &stat_buf);
  
  if ((!r->base->open) || (res == -1)) {
    /* error; assume that channel has been closed */
    return -1;
  } else if (S_ISREG(stat_buf.st_mode)) {
    /* regular file; check position and size */
    len = stat_buf.st_size;
    if ((ch->buffering != PosixFileDescr__noBuffer) &&
	ch->dirty && (ch->bufEnd > len)) {
      return len = ch->bufEnd;
    }

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
#ifndef __MINGW32__
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
#else
    return 0;
#endif
  }
}

void PosixFileDescr__ReaderDesc_SetPos(PosixFileDescr__Reader r, OOC_INT32 newPos) {
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

void PosixFileDescr__ReaderDesc_ReadByte(PosixFileDescr__Reader r, OOC_BYTE *x) {
  PosixFileDescr__Result res;
  OOC_INT32 bytesRead;
  PosixFileDescr__Channel ch = (PosixFileDescr__Channel)r->base;
      
  if (r->res == Channel__done) {
    if (!r->base->open) {
      r->res = get_error(Channel__channelClosed, 0);
      r->bytesRead = 0;

    } else if (ch->buffering == PosixFileDescr__noBuffer) {
      if (ch->dirty) {
	res = flush_buffer(ch);
	if (res != Channel__done) {
	  r->res = res;
	  r->bytesRead = 0;
	  return;
	}
      }
      res = read_bytes(ch, r->pos, 1, x, &r->bytesRead);
      if (res != Channel__done) r->res = res;
      r->pos += r->bytesRead;
      
    } else {
      /* line or block buffering is enabled; check if the byte is currently in
         the buffer; refill if it isn't */
      if ((r->pos < ch->bufStart) || (ch->bufEnd <= r->pos)) {
        /* requested byte isn't in buffer: flush and refill */
        res = flush_buffer(ch);
        if (res == Channel__done) {
          res = read_bytes(ch, r->pos, ch->sizeBuffer, ch->buf, &bytesRead);
          ch->bufStart = r->pos;
          ch->bufEnd = r->pos + bytesRead;
        }
        if ((res != Channel__done) && 
	    ((res->code != Channel__readAfterEnd) || (bytesRead == 0))) {
          /* reaching the end of the file is acceptable, all other errors have
             to be reported back */
          r->res = res;
          r->bytesRead = 0;
	} else {
	  *x = ch->buf[0];
	  r->pos++;
	  r->bytesRead = 1;
        }
      } else {
	*x = ch->buf[r->pos - ch->bufStart];
	r->pos++;
	r->bytesRead = 1;
      }
    }
  } else {
    r->bytesRead = 0;
  }
}

void PosixFileDescr__ReaderDesc_ReadBytes(PosixFileDescr__Reader r, OOC_BYTE* x, int x_0d, OOC_INT32 start, OOC_INT32 n) {
  PosixFileDescr__Result res;
  OOC_INT32 bytesRead, size;
  PosixFileDescr__Channel ch = (PosixFileDescr__Channel)r->base;

  if (r->res == Channel__done) {
    if (!r->base->open) {
      r->res = get_error(Channel__channelClosed, 0);
      r->bytesRead = 0;

    } else if (n == 0) {
      /* ignore request for zero bytes, but only after we have made
	 sure that the channel is still open */

    } else if (ch->buffering == PosixFileDescr__noBuffer) {
      if (ch->dirty) {
	res = flush_buffer(ch);
	if (res != Channel__done) {
	  r->res = res;
	  r->bytesRead = 0;
	  return;
	}
      }
      res = read_bytes(ch, r->pos, n, x+start, &r->bytesRead);
      if (res != Channel__done) r->res = res;
      r->pos += r->bytesRead;

    } else {
      /* the following cases deal with block and line buffering */
      if (ch->dirty && (ch->bufStart > r->pos)) {
	/* make sure that any holes we might notice are actually created for
	   the file descriptor */
	res = flush_buffer(ch);
	if (res != Channel__done) {
	  r->res = res;
	  r->bytesRead = 0;
	  return;
	}
      }
      
      if ((ch->bufStart == ch->bufEnd) ||
	  (r->pos+n <= ch->bufStart) ||
	  (r->pos >= ch->bufEnd)) {
	/* the buffer is empty, or the whole requested interval is located in 
	   front or behind the buffer */

	if (ch->buffering == PosixFileDescr__lineBuffer) {
 	  /* we are reading from a terminal in canonical input mode; 
	     successively grab lines until the whole request is fulfilled */
	  r->bytesRead = 0;
	  do {  /* here holds: n>0, buffer is empty */
	    /* get a single line of input into the buffer */
	    res = read_bytes(ch, r->pos, ch->sizeBuffer, ch->buf, &bytesRead);
	    if (res != Channel__done) r->res = res;
	    ch->bufStart = r->pos;
	    ch->bufEnd = r->pos + bytesRead;
	  
	    /* copy available bytes from buffer to x+start */
	    size = n;
	    if (size > bytesRead) size = bytesRead;
	    (void)memcpy(x+start, ch->buf, size);
	    start += size;
	    n -= size;
	    r->bytesRead += size;
	    r->pos += size;
	  } while ((res == Channel__done) && (n > 0));
	    
	} else if (n >= ch->sizeBuffer) {
	  /* the requested block is larger than the buffer, so don't bother
	     filling it and transfer bytes directly to x+start */
	  res = read_bytes(ch, r->pos, n, x+start, &r->bytesRead);
	  if (res != Channel__done) r->res = res;
	  r->pos += r->bytesRead;
	  
	} else {
	  /* fill buffer with file contents starting at r->pos */
	  res = flush_buffer(ch);
	  if (res == Channel__done) {
	    res = read_bytes(ch, r->pos, ch->sizeBuffer, ch->buf, &bytesRead);
	    ch->bufStart = r->pos;
	    ch->bufEnd = r->pos + bytesRead;
	    
	    /* copy available bytes from buffer to x+start */
	    size = n;
	    if (size > bytesRead) size = bytesRead;
	    (void)memcpy(x+start, ch->buf, size);
	    r->bytesRead = size;
	    r->pos += size;
	  } else {
	    r->bytesRead = 0;
	  }
          
	  if ((res != Channel__done) && 
	      ((res->code != Channel__readAfterEnd) || (r->bytesRead < n))) {
	    r->res = res;
	  }
	}
	
      } else {
	/* the intersection of the requested and the buffered file interval 
	   isn't empty; first read the bytes in front of the buffer, then copy
	   the bytes from the buffer, and finally fill in the rest of the 
	   request */
	if (r->pos < ch->bufStart) {
	  res = read_bytes(ch, r->pos, ch->bufStart - r->pos, x+start, 
			   &r->bytesRead);
	  r->pos += r->bytesRead;
	  if (res != Channel__done) {
	    r->res = res;
	    return;
	  } else {
	    n -= r->bytesRead;
	  }
	} else {
	  r->bytesRead = 0;
	}

	size = ch->bufEnd - r->pos;
	if (size > n) size = n;
	(void)memcpy(x + start + r->bytesRead, 
		     ch->buf + r->pos - ch->bufStart, size);
	r->bytesRead += size;
	r->pos += size;
	n -= size;
	
	if (n > 0) {
	  size = r->bytesRead;
	  PosixFileDescr__ReaderDesc_ReadBytes(r, x, x_0d, start+size, n);
	  r->bytesRead += size;
	}
      }
    }
  } else {
    r->bytesRead = 0;
  }
}



int PosixFileDescr__WriterDesc_Pos(PosixFileDescr__Writer w) {
  if (w->positionable) {
    return w->pos;
  } else {
    return Channel__noPosition;
  }
}

void PosixFileDescr__WriterDesc_SetPos(PosixFileDescr__Writer w, OOC_INT32 newPos) {
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

void PosixFileDescr__WriterDesc_WriteByte(PosixFileDescr__Writer w, OOC_BYTE x) {
  PosixFileDescr__Result res;
  PosixFileDescr__Channel ch = (PosixFileDescr__Channel)w->base;
  
  if (w->res == Channel__done) {
    if (!w->base->open) {
      w->res = get_error(Channel__channelClosed, 0);
      w->bytesWritten = 0;
    
    } else if (ch->buffering == PosixFileDescr__noBuffer) {
      res = write_bytes(ch, w->pos, 1, &x, &w->bytesWritten);
      if (res != Channel__done) w->res = res;
      w->pos += w->bytesWritten;
      
    } else {                    /* buffering is enabled */
      if (ch->dirty && 
          ((w->pos < ch->bufStart) || 
           (w->pos > ch->bufEnd) ||
           ((w->pos == ch->bufEnd) && 
            (ch->bufEnd - ch->bufStart == ch->sizeBuffer)))) {
        /* current buffer is dirty, and the new byte can't be added to it;
           flush it to make room for next output */
        res = flush_buffer(ch);
        if (res != Channel__done) {
          w->res = res;
          w->bytesWritten = 0;
          return;
        }
      }
        
      if (!ch->dirty) {  /* convert buffer from read to write state */
        ch->bufStart = w->pos;
        ch->bufEnd = w->pos+1;
	ch->dirty = 1;
      } else if (w->pos == ch->bufEnd) { /* add to end of buffer */
        ch->bufEnd++;
      }
      ch->buf[w->pos - ch->bufStart] = x;
      w->pos++;
      w->bytesWritten = 1;

      if ((ch->buffering == PosixFileDescr__lineBuffer) &&
          ((OOC_CHAR8)x == CharClass__eol)) {
        res = flush_buffer(ch);
        if (res) {
          w->res = res;
          w->bytesWritten = 0;
        }
      }
    }
  } else {
    w->bytesWritten = 0;
  }
}

static PosixFileDescr__Result flush_lines (PosixFileDescr__Channel ch, 
					   OOC_INT32 start, OOC_INT32 end) {
  OOC_INT32 i;

  i = start;
  while ((i < end) && (ch->buf[i] != CharClass__eol)) {
    i++;
  }
  if (i != end) {
    return flush_buffer(ch);
  } else {
    return Channel__done;
  }
}

void PosixFileDescr__WriterDesc_WriteBytes(PosixFileDescr__Writer w, const OOC_BYTE* x, int x_0d, OOC_INT32 start, OOC_INT32 n) {
  PosixFileDescr__Result res;
  OOC_INT32 size, s, e;
  PosixFileDescr__Channel ch = (PosixFileDescr__Channel)w->base;

  if (w->res == Channel__done) {
    if (!w->base->open) {
      w->res = get_error(Channel__channelClosed, 0);
      w->bytesWritten = 0;

    } else if (ch->buffering == PosixFileDescr__noBuffer) {
      res = write_bytes(ch, w->pos, n, (const OOC_BYTE*)x+start,
			&w->bytesWritten);
      if (res) w->res = res;
      w->pos += w->bytesWritten;
      
    } else if (!ch->dirty ||
               (w->pos+n <= ch->bufStart) ||
               (w->pos > ch->bufEnd) ||
               ((w->pos == ch->bufEnd) && 
		(ch->bufEnd - ch->bufStart == ch->sizeBuffer))) {
      /* the buffer contains no written data, or the whole requested interval 
         is located in front or behind the buffer, or the buffer is full */
      res = flush_buffer(ch);
      if (res) {
        w->res = res;
        w->bytesWritten = 0;
        return;
      }
      
      if (n >= ch->sizeBuffer) {
        /* the written block is larger than the buffer, so don't bother
           filling it and transfer bytes directly from x+start*/
        res = write_bytes(ch, w->pos, n, (const OOC_BYTE*)x+start,
			  &w->bytesWritten);
        if (res) w->res = res;
	/* determine the intersection between buffer and write request */
	s = ch->bufStart;
	if (w->pos > s) s = w->pos;
	e = ch->bufEnd;
	if (w->pos + w->bytesWritten < e) e = w->pos + w->bytesWritten;
	if (s < e) {
	  /* someone was reading in the area we have just overwritten; update 
	     buffer contents in intersection of buffer and write request 
	     instead of invalidating the buffer */
	  (void)memcpy(ch->buf + (s - ch->bufStart),
		       x + start + (s - w->pos), e - s);
	}
        w->pos += w->bytesWritten;

      } else {
        /* copy bytes into buffer */
        (void)memcpy(ch->buf, x+start, n);
        ch->bufStart = w->pos;
        ch->bufEnd = w->pos + n;
        ch->dirty = 1;
        w->bytesWritten = n;
        w->pos += n;
	if (ch->buffering == PosixFileDescr__lineBuffer) {
	  res = flush_lines(ch, 0, n);
	  if (res) {
	    w->res = res;
	    w->bytesWritten = 0;
	  }
	}
      }
    } else {
      /* the intersection of the written interval and the buffered file 
         interval isn't empty, or the new data extends the current buffer;
         first write the bytes in front of the buffer, then extend the buffer,
         and finally write the bytes after the buffer */
      if (w->pos < ch->bufStart) {
        res = write_bytes(ch, w->pos, ch->bufStart - w->pos,
			  (const OOC_BYTE*)x+start, &w->bytesWritten);
        w->pos += w->bytesWritten;
        if (res) {
          w->res = res;
          return;
        } else {
          n -= w->bytesWritten;
        }
      } else {
        w->bytesWritten = 0;
      }
      
      s = w->pos - ch->bufStart;
      size = ch->sizeBuffer - s;
      if (size > n) size = n;
      (void)memcpy(ch->buf + s, x + start + w->bytesWritten, size);
      if (w->pos + size > ch->bufEnd) {
	ch->bufEnd = w->pos + size;
      }
      w->bytesWritten += size;
      w->pos += size;
      n -= size;

      if (n > 0) {
        size = w->bytesWritten;
        PosixFileDescr__WriterDesc_WriteBytes(w, x, x_0d, start+size, n);
	if (w->res == Channel__done) w->bytesWritten += size;
      } else if (ch->buffering == PosixFileDescr__lineBuffer) {
	res = flush_lines(ch, s, size);
	if (res) {
	  w->res = res;
	  w->bytesWritten = 0;
	}
      }
    }
  } else {
    w->bytesWritten = 0;
  }
}



OOC_INT32 PosixFileDescr__ChannelDesc_Length(PosixFileDescr__Channel ch) {
  int res;
  struct stat stat_buf;
  OOC_INT32 len;

  res = fstat(ch->fd, &stat_buf);
  if (res == -1) {
    return Channel__noLength;
  } else {
    len = stat_buf.st_size;
    if ((ch->buffering != PosixFileDescr__noBuffer) &&
	ch->dirty && (ch->bufEnd > len)) {
      return ch->bufEnd;
    } else {
      return len;
    }
  }
}

/* define the day count of the Unix epoch (Jan 1 1970 00:00:00 GMT) for the
   Time.TimeStamp format */
#define days_to_epoch 40587
#define secs_per_day 86400

void PosixFileDescr__ChannelDesc_GetModTime(PosixFileDescr__Channel ch, struct Time__TimeStamp *mtime, RT0__Struct mtime__tag) {
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

PosixFileDescr__Reader PosixFileDescr__ChannelDesc_NewReader(PosixFileDescr__Channel ch) {
  PosixFileDescr__Reader r = NULL;

  if (!ch->open) {
    ch->res = get_error(Channel__channelClosed, 0);
  } else if (ch->readable) {
    if (ch->positionable || (ch->reader == NULL)) {
      r = RT0__NewObject(OOC_TYPE_DESCR(PosixFileDescr,ReaderDesc));
      PosixFileDescr__InitReader (r, ch);
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

PosixFileDescr__Writer PosixFileDescr__ChannelDesc_NewWriter(PosixFileDescr__Channel ch) {
  PosixFileDescr__Writer w = NULL;

  if (!ch->open) {
    ch->res = get_error(Channel__channelClosed, 0);
  } else if (ch->writable) {
    if (ch->positionable || (ch->writer == NULL)) {
      w = RT0__NewObject(OOC_TYPE_DESCR(PosixFileDescr,WriterDesc));
      PosixFileDescr__InitWriter (w, ch);
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

void PosixFileDescr__ChannelDesc_Flush(PosixFileDescr__Channel ch) {
  ch->res = flush_buffer(ch);
  if (ch->buffering == PosixFileDescr__blockBuffer) {
    /* invalidate whole buffer to force next read operation to get the
       data from the OS; of course this won´t work for unbuffered input or
       when reading lines from a terminal in canonical input mode */
    ch->bufEnd = ch->bufStart;
  }
}

void PosixFileDescr__ChannelDesc_Close(PosixFileDescr__Channel ch) {
  int res;

  /* flush the channel; this may be an upcall */
  DYN_TBCALL(Channel,ChannelDesc,Flush,ch,((Channel__Channel)ch));

  /* close the file descriptor; try again if the primitive is
     interrupted by signal */
  do {
    res = close(ch->fd);
  } while ((res == -1) && (errno == EINTR));
  if (ch->fd <= PosixFileDescr__stderrFileno) { 
    /* this fd isn't used for standard IO anymore */
    standard_io[ch->fd] = 0;
  }
  ch->fd = -1;

  /* only put a close error into ch->res if the flush succeeded; 
     otherwise keep the old error indication */
  if ((res == -1) && (ch->res == Channel__done)) {
    if (errno == EBADF) {
      ch->res = get_error(Channel__invalidChannel, 1);
    } else if (errno == ENOSPC) {
      ch->res = get_error(Channel__noRoom, 1);
#ifdef EDQUOT
    } else if (errno == EDQUOT) {
      ch->res = get_error(Channel__noRoom, 1);
#endif
    } else {
      ch->res = get_error(Channel__writeError, 1);
    }
  }

  /* free buffer */
  if (ch->buf) {
    RT0__FreeBlock(ch->buf);
    ch->buf = NULL;
  }

  /* mark channel as closed */
  ch->open = 0;
}

void PosixFileDescr__Init(PosixFileDescr__Channel ch, PosixFileDescr__FileDescriptor fd, OOC_INT8 mode) {
/* Initializes channel `ch' to use file descriptor `fd' and access rights 
   `mode'.  If `fd' is a file, block buffering is enabled; if it's a terminal,
   output is line buffered; otherwise no buffering is applied.
   The standard file descriptors that were passed from the shell are handled
   specially: positioning is disabled, and stderr is never buffered.  */
  struct stat stat_buf;
  int size;

  ch->fd = fd;
  ch->pos = lseek(fd, 0, SEEK_CUR);
  ch->positionable = (ch->pos != -1);
  ch->append = 0;
  ch->dirty = 0;
  ch->bufStart = 0;
  ch->bufEnd = 0;
  ch->reader = NULL;
  ch->writer = NULL;

  /* assume that this call never fails; otherwise someone handed us a bad file
     descriptor, which is forbidden :-) */
  (void)fstat(fd, &stat_buf);
  
  /* decide which buffering to use, get memory for buffer */
  if (isatty(fd)) {
    /* do line buffering for anything that is connected to a terminal; 
       canonical input mode is assumed when reading from a terminal; likewise
       it is assumed that positioning is not possible */
    ch->buffering = PosixFileDescr__lineBuffer;
  } else if (S_ISREG(stat_buf.st_mode)) {
    /* files are buffered on a per block basis; this can only work for files,
       since other input types would block when filling the buffer */
    ch->buffering = PosixFileDescr__blockBuffer;
  } else {  /* the conservative approach: don't buffer unknown fd */
    ch->buffering = PosixFileDescr__noBuffer;
  }
  
  /* handle standard file descriptors: no positioning and don't buffer 
     stderr */
  if (((fd == PosixFileDescr__stdoutFileno) || 
       (fd == PosixFileDescr__stdinFileno)) && standard_io[fd]) {
    ch->positionable = 0;
  } else if ((fd == PosixFileDescr__stderrFileno) && standard_io[fd]) {
    ch->positionable = 0;
    ch->buffering = PosixFileDescr__noBuffer;
  }
  
  if (ch->buffering != PosixFileDescr__noBuffer) {
#if HAVE_ST_BLKSIZE
    size = stat_buf.st_blksize;
    if (size < 1024) {  /* impose a lower and upper limit on block size */
      size = 1024;
    } else if (size > 8192) {
      size = 8192;
    }
#else
    size = 2048;
#endif
    /* in any case `size' should be sufficiently large compared with 
       MAX_CANON */
    ch->buf = RT0__NewBlock(size);
    ch->sizeBuffer = size;
  } else {
    ch->buf = NULL;
    ch->sizeBuffer = 0;
  }

  DYN_TBCALL(Channel,ChannelDesc,ClearError,ch,((Channel__Channel)ch));
  ch->readable = (mode == PosixFileDescr__readOnly) || (mode == PosixFileDescr__readWrite);
  ch->writable = (mode == PosixFileDescr__writeOnly) || (mode == PosixFileDescr__readWrite);
  ch->open = 1;
}

void PosixFileDescr__Truncate(PosixFileDescr__Writer w, int newLength) {
#if HAVE_FTRUNCATE
  int res;

  if (w->res == Channel__done) {
    if (!w->base->open) {
      w->res = get_error(Channel__channelClosed, 0);
    } else {
      PosixFileDescr__Channel ch = (PosixFileDescr__Channel)w->base;
      do {
	/* mh, ftruncate is neither ANSI nor POSIX; if there is a system out
           there that doesn't support it we need to extend configure to check
	   for its presence and provide alternative code... --mva */
        res = ftruncate(ch->fd, newLength);
      } while ((res == -1) && (errno == EINTR));
      
      if (res == -1) {
        w->res = write_error();
      } else if (ch->bufEnd > newLength) {
        /* truncate buffer */
        if (ch->bufStart >= newLength) {
          ch->bufEnd = ch->bufStart; /* empty interval means empty buffer */
        } else {
          ch->bufEnd = newLength;
        }
      }
    }
  }
#else
  /* ftruncate not in MINGW32 API. Return error. */
  w->res = get_error(Channel__invalidChannel, 0);
#endif
}

void OOC_PosixFileDescr_init(void) {
  PosixFileDescr__errorContext = RT0__NewObject(OOC_TYPE_DESCR(PosixFileDescr,ErrorContextDesc));
  Msg__InitContext((Msg__Context)PosixFileDescr__errorContext, 
		   (const OOC_CHAR8*)"OOC:Core:PosixFileDescr", 24);
#ifdef O_BINARY
  /* set standard I/O channels to binary mode */
  setmode(fileno(stdin), O_BINARY);
  setmode(fileno(stdout), O_BINARY);
  setmode(fileno(stderr), O_BINARY);
#endif 
}

void OOC_PosixFileDescr_destroy(void) {
  /* FIXME... if we ever to module unloading  */
}
