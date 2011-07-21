(*	$Id: PosixFileDescr.Mod,v 1.4 2003/03/16 16:28:59 mva Exp $	*)
MODULE PosixFileDescr [FOREIGN "C"; LINK FILE "PosixFileDescr.c" END];
(*  Generalized access to POSIX-style file descriptors.
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
<* Warnings := FALSE; ConformantMode := FALSE *>

(*
Warning:
This module is not part of the "official" OOC suit of library modules.  It
provides an abstract class containing the features that are used by all channel
implementations based on Unix-style file descriptors.  It will not be available
for all implementations of OOC.  Usage of of this module should be restricted 
to derived modules like StdChannels or Files.  It should never be used directly
by a programmer.
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
  
  freeErrorCode* = Ch.freeErrorCode;


CONST  (* values for field `buffering´ parameter `mode' of procedure `Init': *)
  readOnly* = 0;
  writeOnly* = 1;
  readWrite* = 2;
  
CONST  (* standard file descriptor ids *)
  stdinFileno* = 0;
  stdoutFileno* = 1;
  stderrFileno* = 2;

CONST  (* accepted values for parameter `buffering' in `ChannelDesc´: *)
  noBuffer* = 0;
  lineBuffer* = 1;  (* only applicable to terminals *)
  blockBuffer* = 2;
  
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
    append: BOOLEAN;
    (* TRUE iff writers will always append to the file *)
    dirty: BOOLEAN;
    (* TRUE iff buffer needs to be written back; this also serves to 
       distinguish between the buffers access mode: TRUE means write, FALSE
       is read *)
    buffering: SHORTINT;
    (* mode of buffering (none, line, block); for reading line buffering is 
       only applicable for canonical terminal input *)
    buf: POINTER TO ARRAY [NO_LENGTH_INFO, NO_DESCRIPTOR] OF CHAR;
    sizeBuffer: LONGINT;
    (* buffer of length sizeBuffer; sizeBuffer=0 is equivalent to buf=NIL *)
    bufStart, 
    bufEnd: LONGINT;
    (* describe the interval for which the buffer holds valid data from the
       file; the interval contains the character at bufStart, but excludes
       the one at bufEnd, i.e., it is [bufStart..bufEnd[; bufStart<=bufEnd
       always holds, bufStart=bufEnd means an empty buffer; a dirty buffer
       is never emtpy *)
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
PROCEDURE (r: Reader) Available*(): LONGINT;
PROCEDURE (r: Reader) SetPos* (newPos: LONGINT);
PROCEDURE (r: Reader) ReadByte* (VAR x: SYSTEM.BYTE);
PROCEDURE (r: Reader) ReadBytes* (VAR x: ARRAY OF SYSTEM.BYTE; 
                                  start, n: LONGINT);

(* Writer methods 
   ------------------------------------------------------------------------ *)

PROCEDURE (w: Writer) Pos*(): LONGINT;
PROCEDURE (w: Writer) SetPos* (newPos: LONGINT);
PROCEDURE (w: Writer) WriteByte* (x: SYSTEM.BYTE);
PROCEDURE (w: Writer) WriteBytes* (x: ARRAY OF SYSTEM.BYTE; start, n: LONGINT);

(* Channel methods 
   ------------------------------------------------------------------------ *)

PROCEDURE (ch: Channel) Length*(): LONGINT;
PROCEDURE (ch: Channel) GetModTime* (VAR mtime: Time.TimeStamp);
PROCEDURE (ch: Channel) NewReader*(): Reader;
PROCEDURE (ch: Channel) NewWriter*(): Writer;
PROCEDURE (ch: Channel) Flush*;
PROCEDURE (ch: Channel) Close*;

PROCEDURE Init* (ch: Channel; fd: FileDescriptor; mode: SHORTINT);
(**Attach channel @oparam{ch} to file descriptor @oparam{fd}.  @oparam{mode}
   specifies whether the descriptor should be treated as read only, write only,
   or read/write.  It's a bad idea to pass a duplicated file descriptor to
   @oparam{fd}, all kinds of unexpected things might happen.  *)

PROCEDURE Truncate* (w: Writer; newLength: LONGINT);
(**Causes the file associated with @oparam{w} to have the specified length.  If
   the file was previously larger than @oparam{newLength}, the extra data is
   lost.  If it was previously shorter, bytes between the old and new lengths
   are read as zeros.  The writer's position is not modified.  Note: On systems
   that do not support shortening files directly it is implemented as a partial
   file copy.  This procedure should always be called through
   @oproc{*Files.Writer.Truncate}.

   Availability: Unix.  *)

END PosixFileDescr.
