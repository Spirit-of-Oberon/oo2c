(*	$Id: FileChannel.Mod,v 1.6 2003/06/09 17:49:16 mva Exp $	*)
MODULE IO:FileChannel [FOREIGN "C"; LINK FILE "FileChannel.c" END];
(*  Access to files through channel objects.
    Copyright (C) 2003  Michael van Acken

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
<*Warnings:=FALSE*>

IMPORT
  SYSTEM, RT0, Object, Termination, OS:Path, IO, IO:StdChannels, IO:Buffer;
  
TYPE
  Channel* = POINTER TO ChannelDesc;
  ChannelList = ARRAY OF Channel;
  ChannelDesc = RECORD
    (**Note: Unlikes @otype{*Files.File}, this class does not do any buffering
       by itself.  *)
    (IO.ByteChannelDesc)
    fd: IO.FileDescriptor;
    origName: STRING;
    tmpName: Object.String8;
    tmpIndex: LONGINT;
    (* For a temporary file, this is an index into an array of all open
       temporary files.  For all other files, this is @samp{-1}.  *)
  END;

CONST
  read* = 0;
  (**Open file for reading.  *)
  write* = 1;
  (**Open file for writing.  *)
  create* = 2;
  (**Create file if it does not exist.  *)
  exclusive* = 3;
  (**If both @oconst{create} and @oconst{exclusive} are set, then @oproc{Open}
     fails if the specified file already exists.  This flag has no effect if
     @oconst{tmpFile} is set.  *)
  truncate* = 4;
  (**Truncate file to zero length if it exists.  On some systems, for this to
     work @oconst{write} must be set as well.  *)
  append* = 5;
  (**Open file in ``append'' mode.  All data written to this file is added
     to its end.  *)
  tmpFile* = 6;
  (**A file opened with this flag is created with some unused file name, and is
     renamed to the file name passed to @oproc{Open} when
     @oproc{Channel.CloseAndRegister} is called.  If it is closed with
     @oproc{Channel.Close}, then the temporary file is removed.  If the program
     terminates, an attempt is made to close and remove all @oconst{tmpFile}
     files that are still open.  *)

PROCEDURE OpenUnbuffered*(file: STRING; mode: SET): Channel
(**Return a file channel for the name @oparam{file}.  @oproc{Path.Encode} is
   used to calculate the path name that is passed to the OS.

   @precond
   @oparam{file} is a non-empty string.
   @end precond  *)
  RAISES IO.Error;

PROCEDURE Open*(file: STRING; mode: SET): Buffer.Channel
(**Return a buffered channel for @oparam{file}.  @oproc{Path.Encode} is
   used to calculate the path name that is passed to the OS.

   @precond
   @oparam{file} is a non-empty string.
   @end precond  *)
  RAISES IO.Error;

PROCEDURE (ch: Channel) SetBlocking*(block: BOOLEAN) RAISES IO.Error;

PROCEDURE (ch: Channel) Read*(VAR buffer: ARRAY OF SYSTEM.BYTE;
                              start, length: LONGINT): LONGINT
  RAISES IO.Error;
  
PROCEDURE (ch: Channel) Write*(buffer[NO_COPY]: ARRAY OF SYSTEM.BYTE;
                               start, length: LONGINT): LONGINT
  RAISES IO.Error;
  
PROCEDURE (ch: Channel) Close*() RAISES IO.Error;
(**Remove the file if the channel was opened with @oconst{tmpFile}.  *)

PROCEDURE (ch: Channel) CloseAndRegister*() RAISES IO.Error;

(*PROCEDURE (ch: Channel) Pos*(): LONGINT;*)

PROCEDURE (ch: Channel) SetPos*(pos: LONGINT) RAISES IO.Error;

PROCEDURE (ch: Channel) Length*(): LONGINT RAISES IO.Error;

PROCEDURE (ch: Channel) FileDescriptor*(): IO.FileDescriptor;

END IO:FileChannel.
