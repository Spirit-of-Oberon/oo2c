(*	$Id$	*)
MODULE IO:PFD [FOREIGN "C"; LINK FILE "PFD.c" END];
(*  Generalized access to POSIX-style file descriptors.
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
*)
<* Warnings := FALSE; ConformantMode := FALSE *>

(** Note: This module is a stripped down version of @omodule{*PosixFileDescr}.
All buffering code has been removed.  The function @oproc{Reader.Available}
uses the @samp{ioctl()} function @samp{FIONREAD} if this macro is defined.
*)

IMPORT
  SYSTEM, C, Time, CharClass, Ch := Channel, Msg, LongStrings;


TYPE
  Result* = Ch.Result;
  
CONST  (* NOTE: refer to module Channel for the meaning of the various codes *)
  noLength* = Ch.noLength;
  noPosition* = Ch.noPosition;
  
  (* the following values may appear in the `res' (or `res.code')
     field of `Channel', `Reader', or `Writer': *)
  done* = Ch.done;
  invalidChannel* = Ch.invalidChannel;
  writeError* = Ch.writeError;
  noRoom* = Ch.noRoom; 
  wouldBlock* = Ch.freeErrorCode;
  
  (* symbolic values for error codes in `Reader.res' resp. `Writer.res': *)
  outOfRange* = Ch.outOfRange;
  readAfterEnd* = Ch.readAfterEnd;
  channelClosed* = Ch.channelClosed;
  readError* = Ch.readError;
  invalidFormat* = Ch.invalidFormat;
  
  (* symbolic values for error code in `Ch.res': *)
  noReadAccess* = Ch.noReadAccess;
  noWriteAccess* = Ch.noWriteAccess;
  closeError* = Ch.closeError;
  noModTime* = Ch.noModTime;
  noTmpName* = Ch.noTmpName;
  
  freeErrorCode* = Ch.freeErrorCode+1;


CONST  (* values for field `buffering´ parameter `mode' of procedure `Init': *)
  readOnly* = 0;
  writeOnly* = 1;
  readWrite* = 2;
  
CONST  (* standard file descriptor ids *)
  stdinFileno* = 0;
  stdoutFileno* = 1;
  stderrFileno* = 2;

TYPE
  Channel* = POINTER TO ChannelDesc;
  Reader* = POINTER TO ReaderDesc;
  Writer* = POINTER TO WriterDesc;

TYPE
  ChannelDesc* = RECORD
    (Ch.ChannelDesc)
    fd-: C.int;
    (* file descriptor; set with the Init procedure *)
    pos: C.int;
    (* current reading/writing position of the channel; this may differ from
       a reader or writer position if more than one of them are attached *)
    positionable: BOOLEAN;
    (* TRUE iff Length and SetPos are available for the attached riders *)
    reader: Reader;
    (* holds the single reader if the channel isn't positionable *)
    writer: Writer;
    (* holds the single writer if the channel isn't positionable *)
  END;
  ReaderDesc* = RECORD
    (Ch.ReaderDesc)
    pos: C.int;
  END;
  WriterDesc* = RECORD
    (Ch.WriterDesc)
    pos: C.int;
  END;

TYPE
  FileDescriptor = C.int;

TYPE
  ErrorContext = POINTER TO ErrorContextDesc;
  ErrorContextDesc* = RECORD
     (* this record is exported, so that extensions of Channel can access the
        error descriptions by extending `ErrorContextDesc' *)
    (Ch.ErrorContextDesc)
  END;


PROCEDURE (context: ErrorContext) GetTemplate* (msg: Msg.Msg; VAR templ: Msg.LString);

PROCEDURE InitReader* (r: Reader; ch: Channel);

PROCEDURE InitWriter* (w: Writer; ch: Channel);


(* Reader methods 
   ------------------------------------------------------------------------ *)

PROCEDURE (r: Reader) Pos*(): LONGINT;
(* Returns the current reading position associated with the reader `r' in
   channel `r.base', i.e. the index of the first byte that is read by the
   next call to ReadByte resp. ReadBytes.  This procedure will return 
   `noPosition' if the reader has no concept of a reading position (e.g. if it
   corresponds to input from keyboard), otherwise the result is not negative.*)
  
PROCEDURE (r: Reader) Available*(): LONGINT;
(* Returns the number of bytes available for the next reading operation.  For
   a file this is the length of the channel `r.base' minus the current reading
   position, for an sequential channel (or a channel designed to handle slow
   transfer rates) this is the number of bytes that can be accessed without
   additional waiting.  The result is -1 if the channel has been closed.  
   Note that the number of bytes returned is always a lower approximation of
   the number that could be read at once; for some channels or systems it might
   be as low as 1 even if tons of bytes are waiting to be processed.  *)
  
PROCEDURE (r: Reader) SetPos* (newPos: LONGINT);
(* Sets the reading position to `newPos'.  A negative value of `newPos' or 
   calling this procedure for a reader that doesn't allow positioning will set
   `r.res' to `outOfRange'.  A value larger than the channel's length is legal,
   but the following read operation will most likely fail with an 
   `readAfterEnd' error unless the channel has grown beyond this position in 
   the meantime.
   Calls to this procedure while `r.res # done' will be ignored, in particular
   a call with `r.res = readAfterEnd' error will not reset `res' to `done'. *)
  
PROCEDURE (r: Reader) ReadByte* (VAR x: SYSTEM.BYTE);
(* Reads a single byte from the channel `r.base' at the reading position 
   associated with `r' and places it in `x'.  The reading position is moved 
   forward by one byte on success, otherwise `r.res' is changed to indicate 
   the error cause.  Calling this procedure with the reader `r' placed at the 
   end (or beyond the end) of the channel will set `r.res' to `readAfterEnd'.
   `r.bytesRead' will be 1 on success and 0 on failure.
   Calls to this procedure while `r.res # done' will be ignored.  *)
  
PROCEDURE (r: Reader) ReadBytes* (VAR x: ARRAY OF SYSTEM.BYTE; 
                                  start, n: LONGINT);
(* Reads `n' bytes from the channel `r.base' at the reading position associated
   with `r' and places them in `x', starting at index `start'.  The 
   reading position is moved forward by `n' bytes on success, otherwise 
   `r.res' is changed to indicate the error cause.  Calling this procedure with
   the reader `r' placed less than `n' bytes before the end of the channel will
   will set `r.res' to `readAfterEnd'.  `r.bytesRead' will hold the number of
   bytes that were actually read (being equal to `n' on success).
   Calls to this procedure while `r.res # done' will be ignored.
   pre: (n >= 0) & (0 <= start) & (start+n <= LEN (x)) *)

(* Writer methods 
   ------------------------------------------------------------------------ *)

PROCEDURE (w: Writer) Pos*(): LONGINT;
(* Returns the current writing position associated with the writer `w' in
   channel `w.base', i.e. the index of the first byte that is written by the
   next call to WriteByte resp. WriteBytes.  This procedure will return 
   `noPosition' if the writer has no concept of a writing position (e.g. if it
   corresponds to output to terminal), otherwise the result is not negative. *)
  
PROCEDURE (w: Writer) SetPos* (newPos: LONGINT);
(* Sets the writing position to `newPos'.  A negative value of `newPos' or 
   calling this procedure for a writer that doesn't allow positioning will set
   `w.res' to `outOfRange'.  A value larger than the channel's length is legal,
   the following write operation will fill the gap between the end of the 
   channel and this position with zero bytes.
   Calls to this procedure while `w.res # done' will be ignored.  *)
  
PROCEDURE (w: Writer) WriteByte* (x: SYSTEM.BYTE);
(* Writes a single byte `x' to the channel `w.base' at the writing position 
   associated with `w'.  The writing position is moved forward by one byte on 
   success, otherwise `w.res' is changed to indicate the error cause.
   `w.bytesWritten' will be 1 on success and 0 on failure.
   Calls to this procedure while `w.res # done' will be ignored.  *)
  
PROCEDURE (w: Writer) WriteBytes* (VAR x: ARRAY OF SYSTEM.BYTE; start, n: LONGINT);
(* Writes `n' bytes from `x', starting at position `start', to the channel 
   `w.base' at the writing position associated with `w'.  The writing position
   is moved forward by `n' bytes on success, otherwise `w.res' is changed to 
   indicate the error cause.  `w.bytesWritten' will hold the number of bytes 
   that were actually written (being equal to `n' on success).
   Calls to this procedure while `w.res # done' will be ignored.
   pre: (n >= 0) & (0 <= start) & (start+n <= LEN (x))  *)

(* Channel methods 
   ------------------------------------------------------------------------ *)

PROCEDURE (ch: Channel) Length*(): LONGINT;
(* Result is the number of bytes of data that this channel refers to.  If `ch'
   represents a file, then this value is the file's size.  If `ch' has no fixed
   length (e.g. because it's interactive), the result is `noLength'.  *)
  
PROCEDURE (ch: Channel) GetModTime* (VAR mtime: Time.TimeStamp);
(* Retrieves the modification time of the data accessed by the given channel.
   If no such information is avaiblable, `ch.res' is set to `noModTime', 
   otherwise to `done'.  *)

PROCEDURE (ch: Channel) NewReader*(): Reader;
(* Attaches a new reader to the channel `ch'.  It is placed at the very start 
   of the channel, and its `res' field is initialized to `done'.  `ch.res' is
   set to `done' on success and the new reader is returned.  Otherwise result 
   is NIL and `ch.res' is changed to indicate the error cause.
   Note that always the same reader is returned if the channel does not support
   multiple reading positions.  *)
  
PROCEDURE (ch: Channel) NewWriter*(): Writer;
(* Attaches a new writer to the channel `ch'.  It is placed at the very start 
   of the channel, and its `res' field is initialized to `done'.  `ch.res' is
   set to `done' on success and the new writer is returned.  Otherwise result 
   is NIL and `ch.res' is changed to indicate the error cause.
   Note that always the same reader is returned if the channel does not support
   multiple writing positions.  *)
  
PROCEDURE (ch: Channel) Flush*;
(* Flushes all buffers related to this channel.  Any pending write operations
   are passed to the underlying OS and all buffers are marked as invalid.  The
   next read operation will get its data directly from the channel instead of 
   the buffer.  If a writing error occurs during flushing, the field `ch.res'
   will be changed to `writeError', otherwise it's assigned `done'.  Note that
   you have to check the channel's `res' flag after an explicit flush yourself,
   since none of the attached writers will notice any write error in this 
   case.  *)
  
PROCEDURE (ch: Channel) Close*;
(* Flushes all buffers associated with `ch', closes the channel, and frees all
   system resources allocated to it.  This invalidates all riders attached to
   `ch', they can't be used further.  On success, i.e. if all read and write 
   operations (including flush) completed successfully, `ch.res' is set to 
   `done'.  An opened channel can only be closed once, successive calls of 
   `Close' are undefined.  *)

PROCEDURE Init* (ch: Channel; fd: FileDescriptor; mode: SHORTINT);
(* Attach channel `ch' to file descriptor `fd'.  `mode' specifies whether the
   descriptor should be treated as read only, write only, or read/write.  
   It's a bad idea to pass a duplicated file descriptor to `fd', all kinds 
   of unexpected things might happen.  *)

PROCEDURE Truncate* (w: Writer; newLength: LONGINT);
(* Causes the file associated with `w' to have the specified length.  If the 
   file was previously larger than `newLength', the extra data is lost.  If it
   was previously shorter, bytes between the old and new lengths are read as 
   zeros.  The writer's position is not modified.
   Note: On systems that do not support shortening files directly it is 
   implemented as a partial file copy.
   This procedure should always be called through Files.Writer.Truncate.  *)

END IO:PFD.
