(*	$Id: IO.Mod,v 1.15 2004/11/21 20:31:50 mva Exp $	*)
MODULE IO;
(*  Defines common behaviour of I/O channel and selector.
    Copyright (C) 2003, 2004  Michael van Acken

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

(**

   This set of modules defines a set of input/output abstractions for files,
   sockets, pipes, and so on.  The modules are not related to the library
   modules @omodule{*Channel}, @omodule{*Files}, and derivates.  Their goals
   are quite different:

   @itemize @bullet
   @item
   Provide an thin and efficient layer on top of the operation system's I/O
   features.
   @item
   Use exceptions to propagate errors to the application that are reported by
   the C library.
   @item
   Provide an abstraction for I/O multiplexing that allows to use different
   mechanisms besides @code{select()}.
   @item
   The level of abstraction should be high-level enough to care for slighty
   different I/O primitives, most notably under Windows.
   @end itemize

   The roots of the interface are partially the Java IO package, Python, and
   the Oberon-2 standard I/O modules.  Eventually, the modules will replace the
   @samp{IO:*} inherited from the old @samp{libxml} package.  *)

IMPORT
  SYSTEM, Object, Exception, C;
  
TYPE
  Channel* = POINTER TO ChannelDesc;
  SelectionKey* = POINTER TO SelectionKeyDesc;
  SelectionKeyList = POINTER TO ARRAY OF SelectionKey;
  ChannelDesc* = RECORD [ABSTRACT]
  (**A channel is a means by which a program can perform I/O operations.
     Examples for channels are @otype{*IO:FileChannel.Channel},
     @otype{*IO:SocketChannel.Channel}, and
     @otype{*IO:SocketChannel.ServerChannel}.  *)
    readyOps*: SET;
    (* Set of operations that can be performed on the channel without blocking.
       Valid elements are @oconst{opRead}, @oconst{opWrite}, @oconst{opAccept},
       and @oconst{opConnect}.

       This field is used in conjunction with a @oproc{Selector}.  It should
       only be modified by I/O operations of extensions of @otype{Channel}.  *)
    
    keys: SelectionKeyList;
    (* List of selection keys for each selector for which this channel has
       been registered.  The last entry is followed by NIL.  *)
  END;

TYPE
  ByteChannel* = POINTER TO ByteChannelDesc;
  ByteChannelDesc* = RECORD [ABSTRACT]
    (ChannelDesc)
    (**Common base type of channels supporting the @oproc{ByteChannel.Read} and
       @oproc{ByteChannel.Write} methods.  *)
  END;
  
TYPE
  Selector* = POINTER TO SelectorDesc;
  SelectorDesc* = RECORD [ABSTRACT]
  (**A mechanism to discover channels that are ready for I/O operations.  For
     example, a selector can be used to find out for which channels input
     data is available.

     Note: The definition of this class covers both selectors that report the
     current state of a channel, and those that only report an event if a
     channel becomes ready.  @oproc{Selector.Select} only adds new ready flags,
     but never clears them.  I/O operations like @oproc{ByteChannel.Read},
     @oproc{ByteChannel.Write}, @oproc{*SocketChannel.Channel.Connect}, and
     @oproc{*SocketChannel.ServerChannel.Accept} clear the corresponding flag
     if the channel is in non-blocking mode and they get an @samp{EWOULDBLOCK}
     error from the libc function.  *)
    (Object.ObjectDesc)
    keys-: SelectionKey;
    (**A list of selection keys registered for this selector.  The keys are
       linked via @ofield{SelectionKey.nextKey}.  *)
    cancel: BOOLEAN;
  END;
  
TYPE
  FileDescriptor* = C.int;
  SelectionKeyDesc* = RECORD
  (**Association between a @otype{Channel} and @otype{Selector}.  *)
    (Object.ObjectDesc)
    fd-: FileDescriptor;
    interestOps-: SET;
    attachment-: Object.Object;
    selector-: Selector;
    channel-: Channel;

    nextKey-: SelectionKey;
    cancel: BOOLEAN;
  END;

CONST
  opRead* = 0;
  (**Used to signal interest in new input data, or to indicate that some
     input data has become available for processing.  *)
  opWrite* = 1;
  (**Used to signal interest to produce output on a channel, or to indicate
     that there is room for more data to be passed to the operating system.  *)
  opAccept* = 2;
  (**Used to signal interest in connection requests, or to indicate that there
     are pending requests.  *)
  opConnect* = 3;
  (**Used to signal interest in completion of a currently pending connection
     attempt, or to indicate that a pending connect has been completed.  *)

TYPE
  Error* = POINTER TO ErrorDesc;
  ErrorDesc* = RECORD
  (**Base class of all I/O exceptions raised by channel implementations.  *)
    (Exception.CheckedDesc) 
  END;
  FileNotFound* = POINTER TO FileNotFoundDesc;
  FileNotFoundDesc = RECORD
  (**This exception is raised if a C function returns a @samp{ENOENT} error. *)
    (ErrorDesc)
  END;
  AccessDenied* = POINTER TO AccessDeniedDesc;
  AccessDeniedDesc = RECORD
  (**This exception is raised if a C function returns a @samp{EACCES} error. *)
    (ErrorDesc)
  END;
  FileExists* = POINTER TO FileExistsDesc;
  FileExistsDesc = RECORD
  (**This exception is raised if a C function returns a @samp{EEXIST} error. *)
    (ErrorDesc)
  END;
  FileBusy* = POINTER TO FileBusyDesc;
  FileBusyDesc = RECORD
  (**This exception is raised if a C function returns a @samp{EBUSY} error. *)
    (ErrorDesc)
  END;
  InvalidArgument* = POINTER TO InvalidArgumentDesc;
  InvalidArgumentDesc = RECORD
  (**This exception is raised if a C function returns a @samp{EINVAL} error. *)
    (ErrorDesc)
  END;
  OutOfRange* = POINTER TO OutOfRangeDesc;
  OutOfRangeDesc = RECORD
  (**This exception is raised if a C function returns a @samp{ERANGE} error. *)
    (ErrorDesc)
  END;

TYPE
  NotImplemented* = POINTER TO NotImplementedDesc;
  NotImplementedDesc = RECORD
  (**Raised when a method is called that is not implemented for a particular
     channel.  Note: This should be moved into module @omodule{Exception} and
     marked as an unchecked exception.  *)
    (ErrorDesc) 
  END;
  FormatError* = POINTER TO FormatErrorDesc;
  FormatErrorDesc = RECORD
  (**Raised if input data does not satisfy the expected format.  For example,
     because the required number of bytes cannot be read from the channel,
     or because the data is syntactically wrong.  *)
    (ErrorDesc) 
  END;
  ProtocolError* = POINTER TO ProtocolErrorDesc;
  ProtocolErrorDesc* = RECORD
  (**Raised if malformed data is received from the remote side of a
     conversation.  This is @emph{not} used for responses that indicate failure
     to process a request.  An example for a protocol error is an NNTP response
     message that does not begin with a three digit status code.  After such an
     error, the connection should be closed immediately.  *)
    (ErrorDesc)
  END;
  ErrorResponse* = POINTER TO ErrorResponseDesc;
  ErrorResponseDesc* = RECORD
  (**Raised if the remote side of a conversation sends a reply with an error
     status code.  *)
    (ErrorDesc)
  END;


PROCEDURE (e: Error) INIT*(msg: STRING);
  BEGIN
    e.INIT^(msg);
  END INIT;

PROCEDURE NewFormatError*(msg: STRING): FormatError;
  BEGIN
    RETURN NEW(FormatError, msg);
  END NewFormatError;

PROCEDURE RaiseFormatError*(msg: STRING)
RAISES FormatError;
  BEGIN
    RAISE(NewFormatError(msg));
  END RaiseFormatError;

PROCEDURE RaiseNotImplemented*()
RAISES NotImplemented;
  BEGIN
    RAISE(NEW(NotImplemented, NIL));
  END RaiseNotImplemented;

PROCEDURE (k: SelectionKey) INIT*(fd: FileDescriptor;
                                  selector: Selector; channel: Channel;
                                  ops: SET; attachment: Object.Object);
  BEGIN
    k.fd := fd;
    k.interestOps := ops;
    k.attachment := attachment;
    k.selector := selector;
    k.channel := channel;
    k.cancel := FALSE;
  END INIT;

PROCEDURE (k: SelectionKey) Attach*(obj: Object.Object);
(**Set @ofield{k.attachment} to @oparam{obj}.  *)
  BEGIN
    k.attachment := obj;
  END Attach;

PROCEDURE (k: SelectionKey) Cancel*;
(**Mark key @oparam{k} as canceled.  The key is immediately eliminated from the
   channels's list of keys.  It is removed from the selector's key list with
   the next call to @oproc{Selector.Select}.  Closing a channel cancels all its
   selection keys.  *)
  BEGIN
    IF ~k.cancel THEN
      k.cancel := TRUE;
      k.selector.cancel := TRUE;
    END;
  END Cancel;

PROCEDURE (k: SelectionKey) SetInterestOps*(ops: SET);
(**Set @ofield{k.interestOps} to @oparam{ops}.  *)
  BEGIN
    k.interestOps := ops;
  END SetInterestOps;


PROCEDURE (s: Selector) INIT*();
  BEGIN
    s.keys := NIL;
    s.cancel := FALSE;
  END INIT;

PROCEDURE (s: Selector) Close*();
(**Cancel all selection keys registered for the selector @oparam{s} and close
   the selector.  *)
  VAR
    k: SelectionKey;
  BEGIN
    k := s.keys;
    WHILE (k # NIL) DO
      k.Cancel();
      k := k.nextKey;
    END;
    s.keys := NIL;
  END Close;

PROCEDURE (s: Selector) [ABSTRACT] Select*(sec, usec: LONGINT): LONGINT
RAISES Error;
(**Determine if operations on registered channels are ready.  The function
   returns the number of channels with a non-empty ready set.  Result is
   @samp{0} if no channels are ready or have become ready until the time the
   specified timeout expires.  If this function is called with a channel
   already being ready, then it behaves as if a timeout of zero had been
   requested.

   After a call to @oproc{Selector.Select}, the method @oproc{Selector.NextKey}
   iterates over all ready channels.  *)
  END Select;

PROCEDURE (s: Selector) [ABSTRACT] NextKey*(): SelectionKey;
(**Return the next selection key of selector @oparam{s} with a non-empty
   intersection of @ofield{SelectionKey.interestOps} and
   @ofield{Channel.readyOps}.  Result is @code{NIL} if no such channel exists.  *)
  END NextKey;

PROCEDURE (s: Selector) [ABSTRACT] AddSelectionKey*(fd: FileDescriptor;
                                                    channel: Channel;
                                                    ops: SET;
                                                    attachment: Object.Object): SelectionKey;
(**Private method of the selector.  Create and initialize a selection key.
   The caller is responsible for adding the key to the selector.  *)
  END AddSelectionKey;

PROCEDURE (s: Selector) [ABSTRACT] RemoveSelectionKey*(k: SelectionKey);
(**Private method of the selector.  Do any bookkeeping require to eliminate the
   selection key.  The caller is responsible for removing the key from the
   selector's list of keys.  *)
  END RemoveSelectionKey;

PROCEDURE (s: Selector) RemoveCanceled*();
(**Removes all keys that have been marked as ``canceled'' from the selector.
   This is a private method, and should only be called from
   @oproc{Selector.Select}.  *)
  VAR
    prev, k: SelectionKey;
  BEGIN
    IF s.cancel THEN
      prev := NIL;
      k := s.keys;
      WHILE (k # NIL) DO
        IF k.cancel THEN
          s.RemoveSelectionKey(k);
          IF (prev = NIL) THEN
            s.keys := k.nextKey;
          ELSE
            prev.nextKey := k.nextKey;
          END;
        ELSE
          prev := k;
        END;
        k := k.nextKey;
      END;
    END;
  END RemoveCanceled;


PROCEDURE (ch: Channel) INIT*();
  BEGIN
    ch.readyOps := {};
    NEW(ch.keys, 2);
    ch.keys[0] := NIL;
  END INIT;

PROCEDURE (ch: Channel) [ABSTRACT] FileDescriptor*(): FileDescriptor;
(**Return the file descriptor of the channel.  This is the integer number
   that is used to identify the channel on the level of the C library.
   If the channel is not associated with a file descriptor, result is
   @samp{-1}.  *)
  END FileDescriptor;

PROCEDURE (ch: Channel) RegisterWithSelector*(sel: Selector;
                                              ops: SET;
                                              attachment: Object.Object): SelectionKey;
(**Register the channel @oparam{ch} with the selector @oparam{sel}.  If such a
   registration already exists, then return the old selection key.  Otherwise,
   create a new key with an interest set @oparam{ops} and attachment
   @oparam{attachment} and return it.  *)
  VAR
    k: SelectionKey;
    n: SelectionKeyList;
    i, j: LONGINT;
  BEGIN
    i := 0;
    WHILE (ch.keys[i] # NIL) DO
      IF (ch.keys[i].selector = sel) THEN (* key already exists: return it *)
        RETURN ch.keys[i];
      END;
      INC(i);
    END;
    IF (i+1 = LEN(ch.keys^)) THEN
      NEW(n, LEN(ch.keys^)*2);
      FOR j := 0 TO i DO
        n[i] := ch.keys[i];
      END;
      ch.keys := n;
    END;
    ch.keys[i+1] := NIL;
    k := sel.AddSelectionKey(ch.FileDescriptor(), ch, ops, attachment);
    ch.keys[i] := k;
    RETURN k;
  END RegisterWithSelector;

PROCEDURE (ch: Channel) KeyForSelector*(sel: Selector): SelectionKey;
(**Return selection key of @oparam{ch} for selector @oparam{sel}.  Result is
   @code{NIL} if the channel is not registered with the selector.  *)

  VAR
    i: LONGINT;
  BEGIN
    i := 0;
    WHILE (ch.keys[i] # NIL) & (ch.keys[i].selector # sel) DO
      INC(i);
    END;
    RETURN ch.keys[i];
  END KeyForSelector;

PROCEDURE (ch: Channel) [ABSTRACT] SetBlocking*(block: BOOLEAN)
RAISES Error;
(**Change the channel's blocking mode.  Channels typically default to
   blocking mode on creation.

   If a channel does not support non-blocking operation, then any call to this
   method is ignored.  Rider implementations from @omodule{*IO:BinaryRider} and
   @omodule{*IO:TextRider} only work with blocking channels.  *)
  END SetBlocking;

PROCEDURE (ch: Channel) Close*()
RAISES Error;
(**Cancel all selection keys registered for the channel @oparam{ch} and close
   the channel.  *)
  VAR
    i: LONGINT;
  BEGIN
    i := 0;
    WHILE (ch.keys[i] # NIL) DO
      ch.keys[i].Cancel();
      INC(i);
    END;
  END Close;

PROCEDURE (ch: Channel) CloseAndRegister*()
RAISES Error;
(**Like @oproc{Channel.Close}, but register the channel's target with its
   naming service once done.  Right now, only @omodule{*IO:FileChannel}
   supports this feature; see @oconst{*IO:FileChannel.tmpFile} for details.
   By default, this method simply calls @oproc{Channel.Close}.  *)
  BEGIN
    ch.Close();
  END CloseAndRegister;

PROCEDURE (ch: ByteChannel) INIT*();
  BEGIN
    ch.INIT^();
  END INIT;

PROCEDURE (ch: Channel) SetPos*(pos: LONGINT)
RAISES Error;
(**Change the channels position to @oparam{pos}.  *)
  BEGIN
    RaiseNotImplemented();
  END SetPos;

PROCEDURE (ch: ByteChannel) [ABSTRACT] Read*(VAR buffer: ARRAY OF SYSTEM.BYTE;
                                             start, length: LONGINT): LONGINT
RAISES Error;
(**Read a sequence of bytes from the channel into the buffer.

   An attempt is made to read up to @oparam{length} bytes from the channel.
   The bytes are written to @oparam{buffer}, starting at position
   @oparam{start}.  Result is the number of bytes actually read, or @samp{-1}
   if the read position is at the end of the channel, and @oparam{length}
   is not zero.

   A read operation might not read @oparam{length} bytes, and in fact it might
   not read any bytes at all.  Whether or not it does so depends upon the
   nature and state of the channel.  A socket channel in non-blocking mode, for
   example, cannot read any more bytes than are immediately available from the
   socket's input buffer; similarly, a file channel cannot read any more bytes
   than remain in the file.  It is guaranteed, however, that if a channel is in
   blocking mode and there is at least one byte remaining in the buffer then
   this method will block until at least one byte is read.

   @precond
   @samp{0 <= @oparam{start} <= @oparam{start}+@oparam{length} <=
   LEN(@oparam{buffer})} and @samp{@oparam{length} >= 0}.
   @end precond  *)
  END Read;

PROCEDURE (ch: ByteChannel) [ABSTRACT] Write*(buffer[NO_COPY]: ARRAY OF SYSTEM.BYTE;
                                              start, length: LONGINT): LONGINT
RAISES Error;
(**Write a sequence of bytes to this channel from the buffer.

   An attempt is made to write up to @oparam{length} bytes to the channel.  The
   bytes are taken from @oparam{buffer}, beginning at position @oparam{start}.

   A write operation can return after writing less than @oparam{length} bytes.
   That is, some types of channels, depending upon their state, may write only
   some of the bytes or possibly none at all.  A socket channel in non-blocking
   mode, for example, cannot write any more bytes than are free in the socket's
   output buffer.  Result is the number of bytes actually written.

   @precond
   @samp{0 <= @oparam{start} <= @oparam{start}+@oparam{length} <=
   LEN(@oparam{buffer})} and @samp{@oparam{length} >= 0}.
   @end precond  *)
  END Write;

PROCEDURE (ch: ByteChannel) Flush*()
RAISES Error;
(**Flush all buffers associated with channel @oparam{ch}.  *)
  END Flush;

PROCEDURE (ch: ByteChannel) TransferTo*(length: LONGINT;
                                        target: ByteChannel): LONGINT
RAISES Error;
(**Transfer upto @oparam{length} bytes from channel @oparam{ch} to
   @oparam{target}.  Result is the number of bytes actually copied.  *)
  CONST
    sizeBuffer = 8*1024;
  VAR
    buffer: ARRAY sizeBuffer OF SYSTEM.BYTE;
    i, j, rd, wd: LONGINT;
  BEGIN
    i := 0;
    WHILE (i # length) DO
      rd := ch.Read(buffer, 0, sizeBuffer);
      IF (rd = -1) THEN                   (* end of channel *)
        RETURN i;
      ELSE
        j := 0;
        WHILE (j # rd) DO
          wd := target.Write(buffer, j, rd-j);
          IF (wd = -1) THEN
            RETURN i+j;
          ELSE
            INC(j, wd);
          END;
        END;
        INC(i, rd);
      END;
    END;
    RETURN i;
  END TransferTo;

END IO.
