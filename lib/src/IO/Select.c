/*	$Id$	*/
/*  Wrapper around the select() function.
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
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>
#include <stddef.h>
#include <errno.h>
#ifdef __APPLE__
/* APPLE sys/types.h defines FD_SET functions in terms of bzero/bcopy, but 
   does not include a definition of these functions. Therefore, we need
   string.h */
#include <string.h>
#endif
#include <__oo2c.h>
#include <__config.h>
#include <IO/Select.d>

int IO_Select__FD_SETSIZE = FD_SETSIZE;

IO_Select__FileDescrSet IO_Select__NewSet(void) {
  IO_Select__FileDescrSet set;

  set = RT0__NewObject(OOC_TYPE_DESCR(IO_Select,FileDescrSetDesc));
  set->fd_set = RT0__NewBlock(sizeof(fd_set));
  return set;
}

void IO_Select__FileDescrSetDesc_Zero(IO_Select__FileDescrSet fdSet) {
  FD_ZERO((fd_set*)(fdSet->fd_set));
}

void IO_Select__FileDescrSetDesc_Set(IO_Select__FileDescrSet fdSet, int fd) {
  FD_SET(fd, (fd_set*)(fdSet->fd_set));
}

void IO_Select__FileDescrSetDesc_Clear(IO_Select__FileDescrSet fdSet, int fd) {
  FD_CLR(fd, (fd_set*)(fdSet->fd_set));
}

unsigned char IO_Select__FileDescrSetDesc_IsSet(IO_Select__FileDescrSet fdSet, int fd) {
  return (FD_ISSET(fd, (fd_set*)(fdSet->fd_set)) != 0);
}

void IO_Select__FileDescrSetDesc_Copy(IO_Select__FileDescrSet fdSet, IO_Select__FileDescrSet dest) {
  *(fd_set*)(dest->fd_set) = *(fd_set*)(fdSet->fd_set);
}

OOC_INT32 IO_Select__Select(IO_Select__FileDescrSet read,
			    IO_Select__FileDescrSet write,
			    IO_Select__FileDescrSet except,
			    OOC_INT32 sec, OOC_INT32 usec) {
  struct timeval tv;
  struct timeval* tvptr;
  int res;
  
  if (sec >= 0) {
    tv.tv_sec = sec;
    tv.tv_usec = usec;
    tvptr = &tv;
  } else {
    tvptr = NULL;
  }
  
  do {
    res = select(FD_SETSIZE,
		 read ? (fd_set*)(read->fd_set) : NULL,
		 write ? (fd_set*)(write->fd_set) : NULL,
		 except ? (fd_set*)(except->fd_set) : NULL,
		 tvptr);
  } while ((res == -1) && (errno == EINTR));
  /* ... bug: EINTR must adjust the timeout! */
  return res;
}

void OOC_IO_Select_init(void) {
}
