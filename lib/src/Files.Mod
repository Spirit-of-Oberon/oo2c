(*	$Id$	*)
MODULE Files [FOREIGN "C"; LINK FILE "Files.c" END]; <* Warnings := FALSE *>
(*  Access to files and file attributes.
    Copyright (C) 1997, 1999  Michael van Acken

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
Note 1:
This text describes only the additional features of files beyond the standard
channels.  Please refer to Channel.Mod for the semantics of all items that are
inherited from Channel without modifications.

Note 2:
Most Unix systems only allow a fixed number of files (and sockets) to
be open simultaneously.  If this limit is reached, no new file can be
opened or socket be created until an old file/socket is closed.  For
any POSIX compliant system at least 16 open files are supported, most
implementations provide a much larger number.
*)
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
  (* access to the channel was denied, e.g. because a file's permissions don't
     permit the requested access method, or because the given URL isn't 
     publically readable *)
  isDirectory* = Ch.freeErrorCode+1;
  (* the `flags' argument specified write access, and the file is a 
    directory *)
  tooManyFiles* = Ch.freeErrorCode+2;
  (* the process or the entire system has too many files open *)
  noSuchFile* = Ch.freeErrorCode+3;
  (* the named file in a call to `Old' does not exist; or the directory part of
     a file name passed to `New' or `Tmp' does not exist *)
  directoryFull* = Ch.freeErrorCode+4;
  (* the directory or the file system that would contain the new file cannot be
     extended, either because there is no space left or the directory has a 
     fixed upper limit *)
  readOnlyFileSystem* = Ch.freeErrorCode+5;
  (* the file resides on a read-only file system and it is attempted to create
     a new file or to gain write access for an existing one  *)
  invalidTime* = Ch.freeErrorCode+6;
  (* the time passed to procedure SetModTime is no valid time stamp; either the
     millisecond part isn't valid, or the time value is too large or too small
     to be mapped to the time value of the underlying OS *)
  notOwner* = Ch.freeErrorCode+7;
  (* only the owner of a file can change its modification time *)
  anonymousFile* = Ch.freeErrorCode+8;
  (* a file can only be registered if a file name was passed to the initial 
    call to Tmp() *)
  dirWriteDenied* = Ch.freeErrorCode+9;
  (* you need to have write permission for the directory you want to add a new
     file to *)
  fileError* = Ch.freeErrorCode+10;
  (* unspecified error when opening/creating a file; this usually means that
     this module doesn't know how to interpret the error code delivered by 
     the OS *)
  nameTooLong* = Ch.freeErrorCode+11;
  (* either the total length of the file name or of an individual file name
     component is too large; the operating system can impose such limits (see
     PATH_MAX and NAME_MAX in /usr/include/limits.h), or the file system itself
     restricts the format of names on it *) 
  notDirectory* = Ch.freeErrorCode+12;
  (* a file that is referenced as a directory component of the file name 
     exists, but is not a directory *)
  linkLoop* = Ch.freeErrorCode+13;
  (* too many symbolic links were resolved while trying to look up the file
     name; the operating system has an arbitrary limit on the number of 
     symbolic links that may be resolved in looking up a single file name,
     as a primitive way to detect loops *)
     
  
CONST
  (* possible elements for `flags' parameter of New/Old/Tmp: *)
  read* = 0;
  (* if the file cannot be opened for reading access, then it isn't opened at
     all; in this case the error code is set to `noReadAccess' *)
  write* = 1;
  (* if the file cannot be opened for writing access, then it isn't opened at
     all; in this case the error code is set to `noWriteAccess' *)
  tryRead* = 2;
  (* try to open this file for reading access; if the file permissions don't 
     permit reading the file is opened nevertheless, but the file descriptor's
     attribute `readable' is set to FALSE *)
  tryWrite* = 3;
  (* try to open this file for writing access; if the file permissions don't 
     permit writing the file is opened nevertheless, but the file descriptor's
     attribute `writable' is set to FALSE *)
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
     (* this record is exported, so that extensions of Channel can access the
        error descriptions by extending `ErrorContextDesc' *)
    (Ch.ErrorContextDesc)
  END;

VAR
  errorContext: ErrorContext;
  
  
PROCEDURE (context: ErrorContext) GetTemplate* (msg: Msg.Msg; VAR templ: Msg.LString);


(* type-bound procedures from Channel.Channel:
   Length, NewReader, NewWriter, Flush, Close *)

PROCEDURE (f: File) Register*;
(* Registers the file `f' in the directory structure if it has been created 
   with the `Tmp' procedure below.  Registration happens atomically, i.e., it
   is guaranteed that any previously existing file is replaced by the newly 
   registered one without any "in between" state.  If the operation is 
   interrupted, then either the old file still exists on the file system, or
   it has been replaced completely by the new one.
     Calling `Tmp' and `Register' successively  has the same effect as calling
   `New'.  Calling this procedure has no effect if the file `f' has been 
   created with `New' or has been registered previously.  Registration fails
   with an `anonymousFile' error if it was created by calling `Tmp' with an
   empty file name, and with a `channelClosed' error if `f' is closed.  *)
  
PROCEDURE (f: File) NewReader*(): Reader;
(* Attaches a new reader to the file `f'.  It is placed at the very start 
   of the file, and its `res' field is initialized to `done'.  `f.res' is
   set to `done' on success and the new reader is returned.  Otherwise result 
   is NIL and `f.res' is changed to indicate the error cause.  *)
  
PROCEDURE (f: File) NewWriter*(): Writer;
(* Attaches a new writer to the file `f'.  It is placed at the very start 
   of the file, and its `res' field is initialized to `done'.  `f.res' is
   set to `done' on success and the new writer is returned.  Otherwise result 
   is NIL and `f.res' is changed to indicate the error cause.  *)
  
PROCEDURE (f: File) Close*;
(* Flushes all buffers associated with `f', closes the file, and frees all
   system resources allocated to it.  This invalidates all riders attached to
   `f', they can't be used further.  On success, i.e. if all read and write 
   operations (including flush) completed successfully, `f.res' is set to 
   `done'.  An opened file can only be closed once, successive calls of 
   `Close' are undefined.  
   Note that unlike the Oberon System all opened files have to be closed
   explicitly.  Otherwise resources allocated to them will remain blocked.  *)
  

(* type-bound procedures from Channel.Reader:
   Pos, Available, SetPos, ReadByte, ReadBytes, ClearError *)

(* type-bound procedures from Channel.Writer:
   Pos, SetPos, WriteByte, WriteBytes, ErrorDescr, ClearError *)

PROCEDURE (w: Writer) Truncate* (newLength: LONGINT);
(* Causes the file associated with `w' to have the specified length.  If the 
   file was previously larger than `newLength', the extra data is lost.  If it
   was previously shorter, bytes between the old and new lengths are read as 
   zeros.  The writer's position is not modified.
   Note: On systems that do not support shortening files directly it is 
   implemented as a partial file copy.  *)


(* specialized file access; these procedures allow finer grained control than 
   the standard type-bound procedures Filename.New/Old *)
   
PROCEDURE New* (file: ARRAY OF CHAR; flags: SET; VAR res: Result): File;
(* Creates a new file under the given name.  On success the new file handle is
   returned and `res' is set to `done'.  Otherwise result is NIL and `res'
   and will indicate the problem.
   Note that in terms of the Oberon System this procedure combines the 
   procedures New and Register.  *)
  
PROCEDURE Old* (file: ARRAY OF CHAR; flags: SET; VAR res: Result): File;
(* Opens an existing file.  On success the new file handle is returned and
   `res' is set to `done'.  Otherwise result is NIL and `res' will indicate the
   problem.  *)
  
PROCEDURE Tmp* (file: ARRAY OF CHAR; flags: SET; VAR res: Result): File;
(* Creates a temporary file that can be registered later on.  On success the 
   new file handle is returned and `res' is set to `done'.  Otherwise result
   is NIL and `res' will indicate the problem.
     Temporary files are created with an empty permission list, the 
   permissions are extended upon registration.  The files are deleted if they
   haven't been registered and are closed or the program terminates.  
     An unique temporary file name is created if the given file name is the 
   empty string.  Such a file can't be registered later.  Note that some 
   systems are said to have a very low limit for the number of temporary file 
   names.  The limit is never less than 25.  To be on the safe side you should
   never have more than 25 anonymous temporary files open simultaneously, or 
   check that the TMP_MAX macro in /usr/include/stdio.h is large enough for 
   your purposes.
     With oo2c if `file' isn't empty, the new name is derived from the old one
   by appending "^", "^1", "^2", etc. in turn, until a file name is found that
   doesn't exist already.  If such call to `Tmp' returns `nameTooLong', then 
   this refers to the constructed temporary name, not the one in `file'.  
     This function corresponds to Oberon System's New.  *)
  
PROCEDURE SetModTime* (file: ARRAY OF CHAR; mtime: Time.TimeStamp; VAR res: Result);
(* Sets the modification time of the given file to `mtime'.  On success `res'
   will contain `done', otherwise an error code that'll indicate the problem.
   Note that under Unix this procedure will also change the access time to the
   value of `mtime'.  *)

PROCEDURE GetModTime* (file: ARRAY OF CHAR; VAR mtime: Time.TimeStamp; VAR res: Result);
(* Gets the modification time of the given file to `mtime'.  On success `res'
   will contain `done', otherwise an error code indicating the problem.*)

PROCEDURE Exists* (file: ARRAY OF CHAR): BOOLEAN;
(* Returns TRUE if a file `file' exists, FALSE otherwise. 
   ... will be changed to give more useful information on failure *)

END Files.
