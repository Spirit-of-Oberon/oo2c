(*	$Id: Files.Mod,v 1.2 2002/06/17 21:45:53 mva Exp $	*)
MODULE Files [FOREIGN "C"; LINK FILE "Files.c" END]; <* Warnings := FALSE *>
(*  Access to files and file attributes.
    Copyright (C) 1997, 1999, 2002  Michael van Acken

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
   Note 1: This documentation describes only the additional features of files
   beyond the standard channels.  Please refer to @omodule{*Channel} for the
   semantics of all items that are inherited from Channel without
   modifications.

   Note 2: Most Unix systems only allow a fixed number of files (and sockets)
   to be open simultaneously.  If this limit is reached, no new file can be
   opened or socket be created until an old file/socket is closed.  For any
   POSIX compliant system at least 16 open files are supported, most
   implementations provide a much larger number.  *)

<* ConformantMode := FALSE *>  (* for NewReader/NewWriter *)

IMPORT
  Ch0 := Channel, Ch := PosixFileDescr, Time, Termination,
  CharClass, LongStrings, Msg;


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

  (* these values report problems when opening or modifying a file: *)
  accessDenied* = Ch.freeErrorCode;
  (**Access to the channel was denied.  For example, because a file's
     permissions don't permit the requested access method, or because the given
     URL isn't publically readable.  *)
  isDirectory* = Ch.freeErrorCode+1;
  (**The @samp{flags} argument specified write access, and the file is a 
    directory.  *)
  tooManyFiles* = Ch.freeErrorCode+2;
  (**The process or the entire system has too many files open.  *)
  noSuchFile* = Ch.freeErrorCode+3;
  (**The named file in a call to @oproc{Old} does not exist.  Or the directory
     part of a file name passed to @oproc{New} or @oproc{Tmp} does not exist.  *)
  directoryFull* = Ch.freeErrorCode+4;
  (**The directory or the file system that would contain the new file cannot be
     extended, either because there is no space left or the directory has a
     fixed upper limit.  *)
  readOnlyFileSystem* = Ch.freeErrorCode+5;
  (**The file resides on a read-only file system and it is attempted to create
     a new file, or to gain write access for an existing one.  *)
  invalidTime* = Ch.freeErrorCode+6;
  (**The time passed to procedure @oproc{SetModTime} is no valid time stamp.
     Either the millisecond part isn't valid, or the time value is too large or
     too small to be mapped to the time value of the underlying OS.  *)
  notOwner* = Ch.freeErrorCode+7;
  (**Only the owner of a file can change its modification time.  *)
  anonymousFile* = Ch.freeErrorCode+8;
  (**A file can only be registered if a file name was passed to the initial 
     call to @oproc{Tmp}.  *)
  dirWriteDenied* = Ch.freeErrorCode+9;
  (**You need to have write permission for the directory you want to add a new
     file to.  *)
  fileError* = Ch.freeErrorCode+10;
  (**Unspecified error when opening/creating a file.  This usually means that
     this module doesn't know how to interpret the error code delivered by 
     the OS.  *)
  nameTooLong* = Ch.freeErrorCode+11;
  (**Either the total length of the file name or of an individual file name
     component is too large.  The operating system can impose such limits (see
     PATH_MAX and NAME_MAX in @file{/usr/include/limits.h}), or the file system
     itself restricts the format of names on it.  *) 
  notDirectory* = Ch.freeErrorCode+12;
  (**A file that is referenced as a directory component of the file name 
     exists, but is not a directory.  *)
  linkLoop* = Ch.freeErrorCode+13;
  (**Too many symbolic links were resolved while trying to look up the file
     name.  The operating system has an arbitrary limit on the number of 
     symbolic links that may be resolved in looking up a single file name,
     as a primitive way to detect loops.  *)
     
  
CONST
  (* possible elements for `flags' parameter of New/Old/Tmp: *)
  read* = 0;
  (**If the file cannot be opened for reading access, then it isn't opened at
     all.  In this case the error code is set to @oconst{noReadAccess}.  *)
  write* = 1;
  (**If the file cannot be opened for writing access, then it isn't opened at
     all.  In this case the error code is set to @oconst{noWriteAccess}.  *)
  tryRead* = 2;
  (**Try to open this file for reading access.  If the file permissions don't 
     permit reading the file is opened nevertheless, but the file descriptor's
     attribute @ofield{File.readable} is set to @code{FALSE}.  *)
  tryWrite* = 3;
  (**Try to open this file for writing access.  If the file permissions don't 
     permit writing the file is opened nevertheless, but the file descriptor's
     attribute @ofield{File.writable} is set to @code{FALSE}.  *)
  (* note: at least one of the above flags has to be set; otherwise you'll 
     always get an `access denied' error *)

TYPE
  File* = POINTER TO FileDesc;
  FileDesc* = RECORD 
    (Ch.ChannelDesc)
    next: File;
    tmpName, name: POINTER TO ARRAY [NO_LENGTH_INFO, NO_DESCRIPTOR] OF CHAR;
    anonymous: BOOLEAN;
  END;

TYPE
  Reader* = POINTER TO ReaderDesc;
  ReaderDesc* = RECORD
    (Ch.ReaderDesc)
  END;

TYPE
  Writer* = POINTER TO WriterDesc;
  WriterDesc* = RECORD 
    (Ch.WriterDesc)
  END;


TYPE
  ErrorContext* = POINTER TO ErrorContextDesc;
  ErrorContextDesc* = RECORD
     (**This record is exported, so that extensions of @otype{File} can access
        the error descriptions by extending @otype{ErrorContextDesc}.  *)
    (Ch.ErrorContextDesc)
  END;

VAR
  errorContext: ErrorContext;
  
  
PROCEDURE (context: ErrorContext) GetTemplate* (msg: Msg.Msg; VAR templ: Msg.LString);


(* type-bound procedures from Channel.Channel:
   Length, NewReader, NewWriter, Flush, Close *)

PROCEDURE (f: File) Register*;
(**Registers the file @oparam{f} in the directory structure if it has been
   created with the @oproc{Tmp} procedure below.  Registration happens
   atomically.  That is, it is guaranteed that any previously existing file is
   replaced by the newly registered one without any "in between" state.  If the
   operation is interrupted, then either the old file still exists on the file
   system, or it has been replaced completely by the new one.

   Calling @oproc{Tmp} and @oproc{File.Register} successively has the same
   effect as calling @oproc{New}.  Calling this procedure has no effect if the
   file @oparam{f} has been created with @oproc{New} or has been registered
   previously.  Registration fails with an @oconst{anonymousFile} error if it
   was created by calling @oproc{Tmp} with an empty file name, and with a
   @oconst{channelClosed} error if @oparam{f} is closed.  *)
  
PROCEDURE (f: File) NewReader*(): Reader;
(**Attaches a new reader to the file @oparam{f}.  It is placed at the very
   start of the file, and its @ofield{Reader.res} field is initialized to
   @oconst{done}.  @ofield{f.res} is set to @oconst{done} on success and the
   new reader is returned.  Otherwise result is @code{NIL} and @ofield{f.res}
   is changed to indicate the error cause.  *)
  
PROCEDURE (f: File) NewWriter*(): Writer;
(**Attaches a new writer to the file @oparam{f}.  It is placed at the very
   start of the file, and its @ofield{Writer.res} field is initialized to
   @oconst{done}.  @ofield{f.res} is set to @oconst{done} on success and the
   new writer is returned.  Otherwise result is @code{NIL} and @ofield{f.res}
   is changed to indicate the error cause.  *)
  
PROCEDURE (f: File) Close*;
(**Flushes all buffers associated with @oparam{f}, closes the file, and frees
   all system resources allocated to it.  This invalidates all riders attached
   to @oparam{f}, they can't be used further.  On success, that is, if all read
   and write operations (including flush) completed successfully,
   @ofield{f.res} is set to @oconst{done}.

   An opened file can only be closed once, successive calls of
   @oproc{File.Close} are undefined.  Note that unlike the Oberon System all
   opened files have to be closed explicitly.  Otherwise resources allocated to
   them will remain blocked.  *)
  

(* type-bound procedures from Channel.Reader:
   Pos, Available, SetPos, ReadByte, ReadBytes, ClearError *)

(* type-bound procedures from Channel.Writer:
   Pos, SetPos, WriteByte, WriteBytes, ErrorDescr, ClearError *)

PROCEDURE (w: Writer) Truncate* (newLength: LONGINT);
(**Causes the file associated with @oparam{w} to have the specified length.  If
   the file was previously larger than @oparam{newLength}, then the extra data
   is lost.  If it was previously shorter, bytes between the old and new
   lengths are read as zeros.  The writer's position is not modified.  Note: On
   systems that do not support shortening files directly it is implemented as a
   partial file copy.  *)


(* specialized file access; these procedures allow finer grained control than 
   the standard type-bound procedures Filename.New/Old *)
   
PROCEDURE New* (file: ARRAY OF CHAR; flags: SET; VAR res: Result): File;
(**Creates a new file under the given name.  On success the new file handle is
   returned and @oparam{res} is set to @oconst{done}.  Otherwise result is
   @code{NIL} and @oparam{res} and will indicate the problem.

   Note that in terms of the Oberon System this procedure combines the
   procedures @samp{New} and @samp{Register}.  *)
  
PROCEDURE Old* (file: ARRAY OF CHAR; flags: SET; VAR res: Result): File;
(**Opens an existing file.  On success the new file handle is returned and
   @oparam{res} is set to @oconst{done}.  Otherwise result is @code{NIL} and
   @oparam{res} will indicate the problem.  *)
  
PROCEDURE Tmp* (file: ARRAY OF CHAR; flags: SET; VAR res: Result): File;
(**Creates a temporary file that can be registered later on.  On success the
   new file handle is returned and @oparam{res} is set to @oconst{done}.
   Otherwise result is @code{NIL} and @oparam{res} will indicate the problem.

   Temporary files are created with an empty permission list, the permissions
   are extended upon registration.  The files are deleted if they haven't been
   registered and are closed or the program terminates.

   An unique temporary file name is created if the given file name is the empty
   string.  Such a file can't be registered later.  Note that some systems are
   said to have a very low limit for the number of temporary file names.  The
   limit is never less than 25.  To be on the safe side you should never have
   more than 25 anonymous temporary files open simultaneously, or check that
   the @samp{TMP_MAX} macro in @file{/usr/include/stdio.h} is large enough for
   your purposes.

   With @code{oo2c} if @oparam{file} isn't empty, the new name is derived from
   the old one by appending "^", "^1", "^2", etc. in turn, until a file name is
   found that doesn't exist already.  If such call to @oproc{Tmp} returns
   @oconst{nameTooLong}, then this refers to the constructed temporary name,
   not the one in @oparam{file}.  This function corresponds to Oberon System's
   @samp{New}.  *)
  
PROCEDURE SetModTime* (file: ARRAY OF CHAR; mtime: Time.TimeStamp; VAR res: Result);
(**Sets the modification time of the given file to @oparam{mtime}.  On success
   @oparam{res} will contain @oconst{done}, otherwise an error code that
   indicates the problem.  Note that under Unix this procedure will also change
   the access time to the value of @oparam{mtime}.  *)

PROCEDURE GetModTime* (file: ARRAY OF CHAR; VAR mtime: Time.TimeStamp; VAR res: Result);
(**Gets the modification time of the given file to @oparam{mtime}.  On success
   @oparam{res} will contain @oconst{done}, otherwise an error code indicating
   the problem.  *)

PROCEDURE Exists* (file: ARRAY OF CHAR): BOOLEAN;
(**Returns @code{TRUE} if a file @oparam{file} exists, and @code{FALSE}
   otherwise.  *)

END Files.
