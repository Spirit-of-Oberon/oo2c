(*	$Id$	*)
MODULE IO:Select [FOREIGN "C"; LINK FILE "Select.c" END];
(*  Wrapper around the select() function.
    Copyright (C) 2000  Michael van Acken

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
  SYSTEM, C;


TYPE
  FileDescrSet* = POINTER TO FileDescrSetDesc;
  FileDescrSetDesc = RECORD
  (**This class encapsulates the C structure @samp{fd_set}.  *)
    fd_set: SYSTEM.PTR;
  END;

VAR
  FD_SETSIZE-: C.int;
  (**The value of the C marco @samp{FD_SETSIZE}.  The value of this macro is
     the maximum number of file descriptors that a @otype{FileDescrSet} object
     can hold information about.  On systems with a fixed maximum number,
     @ovar{FD_SETSIZE} is at least that number.  On some systems, including
     GNU, there is no absolute limit on the number of descriptors open, but
     this macro still has a constant value which controls the number of bits in
     an @otype{FileDescrSet}; if you get a file descriptor with a value as high
     as @ovar{FD_SETSIZE}, you cannot put that descriptor into an
     @otype{FileDescrSet}.  *)
  
PROCEDURE NewSet* (): FileDescrSet;
(**Creates a new, empty instance of @otype{FileDescrSet}.  *)

PROCEDURE (fdSet: FileDescrSet) Zero*;
(**Initializes @oparam{fdSet} to the empty set.  *)

PROCEDURE (fdSet: FileDescrSet) Set* (fd: C.int);
(**Adds file descriptor @oparam{fd} to the set @oparam{fdSet}.  *)

PROCEDURE (fdSet: FileDescrSet) Clear* (fd: C.int);
(**Removes file descriptor @oparam{fd} from the set @oparam{fdSet}.  *)

PROCEDURE (fdSet: FileDescrSet) IsSet* (fd: C.int): BOOLEAN;
(**Returns @code{TRUE} if, and only if, @oparam{fd} is a member of the file
   descriptor set @oparam{fdSet}.  *)

PROCEDURE (fdSet: FileDescrSet) Copy* (dest: FileDescrSet);
(**Copies the contens of @oparam{fdSet} to @oparam{dest}.  The destination
   variable must have been created with @oproc{NewSet} previously.  *)


PROCEDURE Select* (read, write, except: FileDescrSet;
                   sec, usec: LONGINT): LONGINT;
(**This function is a simple wrapper around the C function @samp{select}.  See
   the manual page select(2) for the details.  The parameters @oparam{sec} and
   @oparam{usec} determine the timeout value.  If both are zero, the function
   returns immediately.  If @oparam{sec} is negative, it will wait
   indefinitely.

   On success, the returned value is the total number of ready file descriptors
   in all of the sets.  A result of @samp{-1} signals an error: a descriptor in
   the file descriptor sets is invalid, or one of the timeout value is negative
   or too large.

   Note: For the current implementation, a signal that causes @samp{select()}
   to return with @samp{EINTR} starts the timeout anew.  When this happens,
   @samp{select()} waits longer than the specified time; if the signals arrive
   ``just right'' it might even wait forever.  This is a bug and should be
   fixed ;-)  *)

END IO:Select.
