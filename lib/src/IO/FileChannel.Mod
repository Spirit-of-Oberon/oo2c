MODULE IO:FileChannel [FOREIGN "C"; LINK FILE "FileChannel.c" END];
<*Warnings:=FALSE*>

IMPORT
  SYSTEM, RT0, Object, Termination, IO, IO:PFD, IO:Buffer;
  
TYPE
  Channel* = POINTER TO ChannelDesc;
  ChannelList = ARRAY OF Channel;
  ChannelDesc = RECORD
    (**Note: Unlikes @otype{*Files.File}, this class does not do any buffering
       by itself.  *)
    (IO.ByteChannelDesc)
    fd: IO.FileDescriptor;
    origName, tmpName: Object.String8;
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

PROCEDURE OpenUnbuffered*(file: Object.String8; mode: SET): Channel
(**Return a file channel for the name @oparam{file}.

   @precond
   @oparam{file} is a non-empty string.
   @end precond  *)
  RAISES IO.Error;

PROCEDURE Open*(file: Object.String8; mode: SET): Buffer.Channel
(**Return a buffered channel for @oparam{file}.

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

(*PROCEDURE (ch: Channel) Position*(): LONGINT;*)

PROCEDURE (ch: Channel) SetPosition*(pos: LONGINT) RAISES IO.Error;


PROCEDURE (ch: Channel) FileDescriptor*(): IO.FileDescriptor;

END IO:FileChannel.
