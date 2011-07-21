(*	$Id: ProgramArgs.Mod,v 1.6 2002/11/17 13:57:45 mva Exp $	*)
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

(**This module provides access to the command line arguments passed to the
   program's invocation.  They are mapped onto a standard channel, with each
   argument transformed to a single line of text.  Newline characters embedded
   in arguments are converted to spaces.  Interpreting the arguments is usually
   done by applying @oproc{*TextRider.Reader} or @oproc{*TextRider.Scanner} to
   the argument channel.

   The number of arguments can be determined by calling @oproc{args.ArgNumber}.
   If the invokation was something like @samp{foo bar 42}, where @samp{foo} is
   the command's name, then the channel's contents would look like this:

   @example
   foo
   bar
   42
   @end example

   For the given example @oproc{args.ArgNumber} would return @samp{2}.  *)
<* ConformantMode := FALSE *>  (* for NewReader/NewWriter *)

IMPORT
  SYSTEM, RT0, Ch := Channel, CharClass, Time, Msg;

  
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
  VAR
    i, j, count: LONGINT;
  BEGIN
    IF (r. pos0 = RT0.argc) THEN
      (* some trickery to get Pos(SetPos(x))=x for x>=ch.Length *)
      RETURN r. pos1
    ELSE
      i := 0; j := 0; count := 0;
      WHILE (i # r. pos0) OR (j # r. pos1) DO
        IF (RT0.argv[i][j] = 0X) THEN
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
  VAR
    i, j, count: LONGINT;
  BEGIN
    IF (r. res = done) THEN
      IF (newPos < 0) THEN
        r. res := GetError (outOfRange)
      ELSIF r. base. open THEN
        i := 0; j := 0; count := 0;
        WHILE (i < RT0.argc) & (count # newPos) DO
          IF (RT0.argv[i][j] = 0X) THEN
            INC (i); j := 0
          ELSE
            INC (j)
          END;
          INC (count)
        END;
        r. pos0 := i;
        IF (i = RT0.argc) THEN
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
  BEGIN
    IF (r. res = done) THEN
      IF r. base. open THEN
        IF (r. pos0 = RT0.argc) THEN
          r. res := GetError (readAfterEnd)
        ELSIF (RT0.argv[r. pos0][r. pos1] = 0X) THEN
          x := CharClass.eol;
          INC (r. pos0);
          IF (r. pos0 = RT0.argc) THEN
            (* some trickery to get Pos(SetPos(x))=x for x>=ch.Length *)
            r. pos1 := r. base. Length()
          ELSE
            r. pos1 := 0
          END
        ELSIF (RT0.argv[r. pos0][r. pos1] = CharClass.eol) THEN
          (* newline character is turned into space *)
          x := " ";
          INC (r. pos1)
        ELSE
          x := RT0.argv[r. pos0][r. pos1];
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
  VAR
    i, j, len: LONGINT;
  BEGIN
    i := 0; len := 0;
    WHILE (i < RT0.argc) DO
      j := 0;
      WHILE (RT0.argv[i][j] # 0X) DO
        INC (j)
      END;
      INC (len, j+1);
      INC (i)
    END;
    RETURN len
  END Length;
  
PROCEDURE (ch: Channel) ArgNumber* (): LONGINT;
(**Returns the number of command line arguments (excluding the program name
   itself) passed to the program.  *)
  BEGIN
    RETURN RT0.argc-1
  END ArgNumber;

PROCEDURE (ch: Channel) GetModTime* (VAR mtime: Time.TimeStamp);
(**Since the argument channel has no modification time, this procedure will
   always signal a `noModTime' error.  *)
  BEGIN
    ch. res := GetError (Ch.noModTime)
  END GetModTime;

PROCEDURE (ch: Channel) NewReader*(): Reader;
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
