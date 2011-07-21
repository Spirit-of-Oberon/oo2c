(*	$Id: StdChannels.Mod,v 1.2 2002/12/19 06:36:46 mva Exp $	*)
MODULE StdChannels [OOC_EXTENSIONS];
(*  Defines the standard I/O channels.
    Copyright (C) 1997-1999  Michael van Acken

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

IMPORT
  Channel, FD := PosixFileDescr, Time, Termination, Msg, SYSTEM;

(**Standard channels corresponding to the the standard file descriptors
   @samp{stdin}, @samp{stdout}, @samp{stderr}, and the pseudo channel
   @samp{/dev/null}.

   Standard channels do not have to be opened by a client program since they
   are already open and ready for use.  Under some operating system they may be
   connected to sources and destinations specified before the program is run,
   while on a stand-alone system they may be connected to a console terminal.

   The standard channels (stdin, stdout, stderr) should never be closed and the
   values used to identify standard channels should be constant throughout the
   execution of the program.  *)


VAR  (* standard channels *)
  stdin-: Channel.Channel;
  (**Standard input.  *)
  stdout-: Channel.Channel;
  (**Standard output.  *)
  stderr-: Channel.Channel;
  (**Standard error output.  *)

TYPE
  NullChannel = POINTER TO NullChannelDesc;
  Writer = POINTER TO WriterDesc;
  NullChannelDesc = RECORD
    (Channel.ChannelDesc)
    writer: Writer
  END;
  WriterDesc = RECORD
    (Channel.WriterDesc)
  END;
  
VAR
  null-: NullChannel;
  (**Null channel.  Write only, accepts arbitrary input.  *)
  
VAR
  fd: FD.Channel;


TYPE
  ErrorContext = POINTER TO ErrorContextDesc;
  ErrorContextDesc = RECORD
    (Channel.ErrorContextDesc)
  END;

VAR
  errorContext: ErrorContext;

PROCEDURE GetError (code: Msg.Code): Msg.Msg;
  BEGIN
    RETURN Msg.New (errorContext, code)
  END GetError;



(* Writer methods 
   ------------------------------------------------------------------------ *)

PROCEDURE (w: Writer) Pos*(): LONGINT;
  BEGIN
    RETURN Channel.noPosition
  END Pos;
  
PROCEDURE (w: Writer) SetPos* (newPos: LONGINT);
  END SetPos;
  
PROCEDURE (w: Writer) WriteByte* (x: SYSTEM.BYTE);
  BEGIN
    w. bytesWritten := 1
  END WriteByte;
  
PROCEDURE (w: Writer) WriteBytes* (x[NO_COPY]: ARRAY OF SYSTEM.BYTE; start, n: LONGINT);
  BEGIN
    w. bytesWritten := n
  END WriteBytes;


(* Channel methods 
   ------------------------------------------------------------------------ *)

PROCEDURE (ch: NullChannel) Length*(): LONGINT;
  BEGIN
    RETURN Channel.noLength
  END Length;

PROCEDURE (ch: NullChannel) GetModTime* (VAR mtime: Time.TimeStamp);
  BEGIN
    ch. res := GetError (Channel.noModTime)
  END GetModTime;


PROCEDURE (ch: NullChannel) NewReader*(): Channel.Reader;
  BEGIN
    ch. res := GetError (Channel.noReadAccess);
    RETURN NIL
  END NewReader;
  
PROCEDURE (ch: NullChannel) NewWriter*(): Channel.Writer;
  VAR
    w: Writer;
  BEGIN
    ch. ClearError;
    IF (ch. writer = NIL) THEN
      NEW (w);
      w. base := ch;
      w. ClearError;
      w. positionable := FALSE;
      w. bytesWritten := -1;
      ch. writer := w;
      RETURN w
    ELSE
      RETURN ch. writer
    END
  END NewWriter;
  
PROCEDURE (ch: NullChannel) Flush*;
  BEGIN
    ch. ClearError
  END Flush;
  
PROCEDURE (ch: NullChannel) Close*;
  BEGIN
    ch. ClearError
  END Close;

  
PROCEDURE Flush;
  BEGIN
    stdout. Flush; stderr.Flush
  END Flush;


BEGIN
  NEW (errorContext);
  Msg.InitContext (errorContext, "OOC:Core:StdChannels");

  (* create standard channels stdin, stdout, stderr from the POSIX file 
     descriptors *)
  NEW (fd);
  FD.Init (fd, FD.stdinFileno, FD.readOnly);
  stdin := fd;
  NEW (fd);
  FD.Init (fd, FD.stdoutFileno, FD.writeOnly);
  stdout := fd;
  NEW (fd);
  FD.Init (fd, FD.stderrFileno, FD.writeOnly);
  stderr := fd;
  
  (* create null channel *)
  NEW (null);
  null. ClearError;
  null. readable := FALSE;
  null. writable := TRUE;
  null. open := TRUE;
  
  (* make sure that any output is flushed on program termination *)
  Termination.RegisterProc (Flush)
END StdChannels.
