#include <__oo2c.h>
#include <__config.h>
#include <IO/Select.d>

#include <sys/time.h>
#include <sys/types.h>
#include <errno.h>

struct fdsets {
  fd_set read;
  fd_set write;
};

static const OOC_UINT32 read_mask = ((1U<<IO__opRead)|
				     (1U<<IO__opAccept)|
				     (1U<<IO__opConnect));
static const OOC_UINT32 write_mask = ((1U<<IO__opWrite)|
				      (1U<<IO__opConnect));


void IO_Select__Init(IO_Select__Selector s) {
  s->sets = RT0__NewBlock(sizeof(struct fdsets));
  s->current = NULL;
}

IO_Select__Selector IO_Select__Open() {
  IO_Select__Selector s = RT0__NewObject(OOC_TYPE_DESCR(IO_Select,SelectorDesc));
  IO_Select__Init(s);
  return s;
}

IO__SelectionKey IO_Select__SelectorDesc_AddSelectionKey(IO_Select__Selector s, OOC_INT32 fd, IO__Channel channel, OOC_UINT32 ops, Object__Object attachment) {
  struct fdsets* fds = (struct fdsets*)s->sets;
  IO_Select__SelectionKey k = RT0__NewObject(OOC_TYPE_DESCR(IO_Select,SelectionKeyDesc));
  IO__InitSelectionKey((IO__SelectionKey)k, fd, (IO__Selector)s,
			channel, ops, attachment);
  k->nextKey = s->keys;
  s->keys = (IO__SelectionKey)k;
  return (IO__SelectionKey)k;
}

void IO_Select__SelectorDesc_RemoveSelectionKey(IO_Select__Selector s,
						 IO__SelectionKey k) {
}

void IO_Select__SelectorDesc_Close(IO_Select__Selector s) {
  RT0__FreeBlock(s->sets);
  s->current = NULL;
  IO__SelectorDesc_Close((IO__Selector)s);
}

OOC_INT32 IO_Select__SelectorDesc_Select(IO_Select__Selector s,
					  OOC_INT32 sec, OOC_INT32 usec) {
  struct fdsets* fds = (struct fdsets*)s->sets;
  struct timeval tv, *tvptr;
  IO__SelectionKey k;
  int res;
  OOC_INT32 updates;
  
  OOC_METHOD(s,IO__SelectorDesc_RemoveCanceled)((IO__Selector)s);
  
  FD_ZERO(&fds->read);
  FD_ZERO(&fds->write);
  k = s->keys;
  while (k) {
    /* only select() on read/write if the key's interest mask has bits set
       that are not in the current ready mask */
    OOC_UINT32 ops = k->interestOps & ~k->channel->readyOps;
    if (ops & read_mask) {
      FD_SET(k->fd,&fds->read);
    }
    if (ops & write_mask) {
      FD_SET(k->fd,&fds->write);
    }
    k = k->nextKey;
  }
  
  if (sec >= 0) {
    tv.tv_sec = sec;
    tv.tv_usec = usec;
    tvptr = &tv;
  } else {
    tvptr = NULL;
  }
  do {
    res = select(FD_SETSIZE, &fds->read, &fds->write, NULL, tvptr);
    /* note: in case of EINTR, we may actually wait too long if *tvptr is not
       updated by the call to select() */
  } while ((res == -1) && (errno == EINTR));
  if (res < 0) {
    IO_StdChannels__IOError(NULL);
  } else if (res == 0) {  /* timeout, no fd ready */
    return 0;
  }
  
  updates = 0;
  s->current = (IO_Select__SelectionKey)s->keys;  /* reset NextKey() */
  k = s->keys;
  while (k) {
    OOC_UINT32 readyOps = 0;
    if (FD_ISSET(k->fd, &fds->read)) {
      readyOps |= (k->interestOps & read_mask);
    }
    if (FD_ISSET(k->fd, &fds->write)) {
      readyOps |= (k->interestOps & write_mask);
    }
    if (readyOps) {
      k->channel->readyOps |= readyOps;
      updates++;
    }
    k = k->nextKey;
  }
  
  return updates;
}

IO_Select__SelectionKey IO_Select__SelectorDesc_NextKey(IO_Select__Selector s) {
  IO__SelectionKey k = (IO__SelectionKey)s->current;
  while (k && !(k->interestOps & k->channel->readyOps)) {
    k = k->nextKey;
  }
  if (k) {
    s->current = (IO_Select__SelectionKey)k->nextKey;
  } else {
    s->current = NULL;
  }
  return (IO_Select__SelectionKey)k;
}

void OOC_IO_Select_init(void) {
}
