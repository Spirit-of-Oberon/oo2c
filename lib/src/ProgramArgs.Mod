(*	$Id$	*)
MODULE ProgramArgs;
(*  Provides access to a program invokation's command line arguments.
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

(* 
This module provides access to the command line arguments passed to the 
program's invokation.  They are mapped onto a standard channel, with each
argument transformed to a single line of text.  Newline characters embedded
in arguments are converted to spaces.  Interpreting the arguments is usually
done by applying TextRider.Reader of TextRider.Scanner to the argument channel.

The number of arguments can be determined by calling `args. ArgNumber()'.  If
the invokation was something like `foo bar 42', where `foo' is the command's
name, then the channel's contents would look like this:

---example start---
foo
bar
42
---example end---

For the given example ArgNumber() would return 2.
*)
<* ConformantMode := FALSE *>  (* for NewReader/NewWriter *)

IMPORT
  SYSTEM, Ch := Channel, PosixFileDescr, CharClass, Time, Msg;

  
CONST
  (* NOTE: refer to module Channel for the meaning of the various codes *)
  
  (* the following values may appear in the `res' field of `Channel', `Reader',
     or `Writer': *)
  done* = Ch.done;

  (* symbolic values for `Reader.res' resp. `Writer.res': *)
  outOfRange* = Ch.outOfRange;
  readAfterEnd* = Ch.readAfterEnd;
  channelClosed* = Ch.channelClosed;
  
  (* symbolic values for `Ch.res': *)
  noWriteAccess* = Ch.noWriteAccess;
  noModTime* = Ch.noModTime;

TYPE
  Channel* = POINTER TO ChannelDesc;
  ChannelDesc = RECORD
    (Ch.ChannelDesc)
  END;
  Reader = POINTER TO ReaderDesc;
  ReaderDesc = RECORD
    (Ch.ReaderDesc)
    pos0, pos1: LONGINT
  END;

VAR
  args-: Channel;
  

TYPE
  ErrorContext = POINTER TO ErrorContextDesc;
  ErrorContextDesc* = RECORD
    (Ch.ErrorContextDesc)
  END;

VAR
  errorContext: ErrorContext;

PROCEDURE GetError (code: Msg.Code): Msg.Msg;
  BEGIN
    RETURN Msg.New (errorContext, code)
  END GetError;


PROCEDURE (r: Reader) Pos*(): LONGINT;
(* Returns the current reading position associated with the reader `r' in
   channel `r.base', i.e. the index of the first byte that is read by the
   next call to ReadByte resp. ReadBytes.  This procedure will return 
   `noPosition' if the reader has no concept of a reading position (e.g. if it
   corresponds to input from keyboard), otherwise the result is not negative.*)
  VAR
    i, j, count: LONGINT;
  BEGIN
    IF (r. pos0 = PosixFileDescr.argc) THEN
      (* some trickery to get Pos(SetPos(x))=x for x>=ch.Length *)
      RETURN r. pos1
    ELSE
      i := 0; j := 0; count := 0;
      WHILE (i # r. pos0) OR (j # r. pos1) DO
        IF (PosixFileDescr.argv[i][j] = 0X) THEN
          INC (i); j := 0
        ELSE
          INC (j)
        END;
        INC (count)
      END;
      RETURN count
    END
  END Pos;

PROCEDURE (r: Reader) Available*(): LONGINT;
(* Returns the number of bytes available for the next reading operation.  For
   a file this is the length of the channel `r.base' minus the current reading
   position, for an interactive channel (or a channel designed to handle slow
   transfer rates) this is the number of bytes that can be accessed without
   additional waiting.  The result is -1 if Close() was called for the channel,
   or no more byte are available and the remote end of the channel has been
   closed.
   Note that the number of bytes returned is always a lower approximation of
   the number that could be read at once; for some channels or systems it might
   be as low as 1 even if tons of bytes are waiting to be processed.  *)
  VAR
    i: LONGINT;
  BEGIN
    IF r. base. open THEN
      i := r. base. Length() - r. Pos();
      IF (i < 0) THEN
        RETURN 0
      ELSE
        RETURN i
      END
    ELSE
      RETURN -1
    END
  END Available;
  
PROCEDURE (r: Reader) SetPos* (newPos: LONGINT);
(* Sets the reading position to `newPos'.  A negative value of `newPos' or 
   calling this procedure for a reader that doesn't allow positioning will set
   `r.res' to `outOfRange'.  A value larger than the channel's length is legal,
   but the following read operation will most likely fail with an 
   `readAfterEnd' error unless the channel has grown beyond this position in 
   the meantime).
   Calls to this procedure while `r.res # done' will be ignored, in particular
   a call with `r.res = readAfterEnd' error will not reset `res' to `done'. *)
  VAR
    i, j, count: LONGINT;
  BEGIN
    IF (r. res = done) THEN
      IF (newPos < 0) THEN
        r. res := GetError (outOfRange)
      ELSIF r. base. open THEN
        i := 0; j := 0; count := 0;
        WHILE (i < PosixFileDescr.argc) & (count # newPos) DO
          IF (PosixFileDescr.argv[i][j] = 0X) THEN
            INC (i); j := 0
          ELSE
            INC (j)
          END;
          INC (count)
        END;
        r. pos0 := i;
        IF (i = PosixFileDescr.argc) THEN
          (* some trickery to get Pos(SetPos(x))=x for x>=ch.Length *)
          r. pos1 := newPos
        ELSE
          r. pos1 := j
        END
      ELSE  (* channel has been closed *)
        r. res := GetError (channelClosed)
      END
    END
  END SetPos;
  
PROCEDURE (r: Reader) ReadByte* (VAR x: SYSTEM.BYTE);
(* Reads a single byte from the channel `r.base' at the reading position 
   associated with `r' and places it in `x'.  The reading position is moved 
   forward by one byte on success, otherwise `r.res' is changed to indicate 
   the error cause.  Calling this procedure with the reader `r' placed at the 
   end (or beyond the end) of the channel will set `r.res' to `readAfterEnd'.
   `r.bytesRead' will be 1 on success and 0 on failure.
   Calls to this procedure while `r.res # done' will be ignored.  *)
  BEGIN
    IF (r. res = done) THEN
      IF r. base. open THEN
        IF (r. pos0 = PosixFileDescr.argc) THEN
          r. res := GetError (readAfterEnd)
        ELSIF (PosixFileDescr.argv[r. pos0][r. pos1] = 0X) THEN
          x := CharClass.eol;
          INC (r. pos0);
          IF (r. pos0 = PosixFileDescr.argc) THEN
            (* some trickery to get Pos(SetPos(x))=x for x>=ch.Length *)
            r. pos1 := r. base. Length()
          ELSE
            r. pos1 := 0
          END
        ELSIF (PosixFileDescr.argv[r. pos0][r. pos1] = CharClass.eol) THEN
          (* newline character is turned into space *)
          x := " ";
          INC (r. pos1)
        ELSE
          x := PosixFileDescr.argv[r. pos0][r. pos1];
          INC (r. pos1)
        END
      ELSE  (* channel has been closed *)
        r. res := GetError (channelClosed);
        r. bytesRead := 0
      END
    ELSE
      r. bytesRead := 0
    END
  END ReadByte;
  
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
  VAR
    i: LONGINT;
  BEGIN
    (* no need for fancy footwork here; simply delegate everything 
       to ReadByte *)
    i := 0;
    WHILE (i < n) & (r. res = done) DO
      r. ReadByte (x[start+i]);
      IF (r. res = done) THEN
        INC (i)
      END
    END;
    r. bytesRead := i
  END ReadBytes;
  


(* Channel methods 
   ------------------------------------------------------------------------ *)
   
PROCEDURE (ch: Channel) Length*(): LONGINT;
(* Result is the number of bytes of data that this channel refers to.  If `ch'
   represents a file, then this value is the file's size.  If `ch' has no fixed
   length (e.g. because it's interactive), the result is `noLength'.  *)
  VAR
    i, j, len: LONGINT;
  BEGIN
    i := 0; len := 0;
    WHILE (i < PosixFileDescr.argc) DO
      j := 0;
      WHILE (PosixFileDescr.argv[i][j] # 0X) DO
        INC (j)
      END;
      INC (len, j+1);
      INC (i)
    END;
    RETURN len
  END Length;
  
PROCEDURE (ch: Channel) ArgNumber* (): LONGINT;
(* Returns the number of command line arguments (excluding the program name
   itself) passed to the program.  *)
  BEGIN
    RETURN PosixFileDescr.argc-1
  END ArgNumber;

PROCEDURE (ch: Channel) GetModTime* (VAR mtime: Time.TimeStamp);
(* Since the argument channel has no modification time, this procedure will
   always signal a `noModTime' error.  *)
  BEGIN
    ch. res := GetError (Ch.noModTime)
  END GetModTime;

PROCEDURE (ch: Channel) NewReader*(): Reader;
(* Attaches a new reader to the channel `ch'.  It is placed at the very start 
   of the channel, and its `res' field is initialized to `done'.  `ch.res' is
   set to `done' on success and the new reader is returned.  Otherwise result 
   is NIL and `ch.res' is changed to indicate the error cause.  
   Note that always the same reader is returned if the channel does not support
   multiple reading positions.  *)
  VAR
    r: Reader;
  BEGIN
    IF ch. open THEN
      NEW (r);
      r. base := ch;
      r. ClearError;
      r. bytesRead := 1;
      r. positionable := TRUE;
      r. pos0 := 0;
      r. pos1 := 0;
      ch. ClearError
    ELSE
      r := NIL;
      ch. res := GetError (channelClosed)
    END;
    RETURN r
  END NewReader;
  
PROCEDURE (ch: Channel) Flush*;
  BEGIN
    IF ~ch. open THEN
      ch. res := GetError (channelClosed)
    END
  END Flush;

PROCEDURE (ch: Channel) Close*;
(* Closes the program arguments channel.  No further reading from it will be
   possible.  *)
  BEGIN
    ch. open := FALSE
  END Close;

BEGIN
  NEW (errorContext);
  Msg.InitContext (errorContext, "OOC:Core:ProgramArgs");
  
  NEW (args);
  args. ClearError;
  args. readable := TRUE;
  args. writable := FALSE;
  args. open := TRUE
END ProgramArgs.
