MODULE M006 [OOC_EXTENSIONS];
(**This is a partially Texinfo-ized version of a part of the Channel module
   interface.  It is used as an early test for the XML based interface
   documentation facilities.  *)
TYPE
  Result* = POINTER TO ResultDesc (*Msg.Msg*);
  ResultDesc = RECORD END;
  
TYPE
  Channel* = POINTER TO ChannelDesc;
  ChannelDesc* = RECORD [ABSTRACT]
    (**The abstract base type of all byte-stream input/output classes.  *)
    res*: Result;       (* READ-ONLY *)
    (**Error flag signalling failure of a call to NewReader, NewWriter, Flush,
       or Close.  Initialized to `done' when creating the channel.  Every 
       operation sets this to `done' on success, or to a message object to 
       indicate the error source.  *)
    
    readable*: BOOLEAN;  (* READ-ONLY *)
    (**TRUE iff readers can be attached to this channel with NewReader *)
    writable*: BOOLEAN;  (* READ-ONLY *)
    (**TRUE iff writers can be attached to this channel with NewWriter *)
    
    open*: BOOLEAN;  (* READ-ONLY *)
    (**Channel status.  Set to TRUE on channel creation, set to FALSE by 
       calling Close.  Closing a channel prevents all further read or write
       operations on it.  *)
  END;

TYPE
  Reader* = POINTER TO ReaderDesc;
  ReaderDesc* = RECORD [ABSTRACT]
    (**A byte-oriented reader for a @otype{Channel} instance.  *)
    base*: Channel;  (* READ-ONLY *)
    (**This field refers to the channel the Reader is connected to.  *)

    res*: Result;   (* READ-ONLY *)
    (**Error flag signalling failure of a call to ReadByte, ReadBytes, or 
       SetPos.  Initialized to `done' when creating a Reader or by calling 
       ClearError.  The first failed reading (or SetPos) operation changes this
       to indicate the error, all further calls to ReadByte, ReadBytes, or 
       SetPos will be ignored until ClearError resets this flag.  This means 
       that the successful completion of an arbitrary complex sequence of read
       operations can be ensured by asserting that `res' equals `done' 
       beforehand and also after the last operation.  *)
    
    bytesRead*: LONGINT;  (* READ-ONLY *)
    (**Set by ReadByte and ReadBytes to indicate the number of bytes that were
       successfully read.  *)
       
    positionable*: BOOLEAN;  (* READ-ONLY *)
    (**TRUE iff the Reader can be moved to another position with `SetPos'; for
       channels that can only be read sequentially, like input from keyboard, 
       this is FALSE.  *)
  END;

TYPE
  Writer* = POINTER TO WriterDesc;
  WriterDesc* = RECORD [ABSTRACT]
    (**A byte-oriented writer for a @otype{Channel} instance.  *)
    base*: Channel;  (* READ-ONLY *)
    (**This field refers to the channel the Writer is connected to.  *)

    res*: Result;   (* READ-ONLY *)
    (**Error flag signalling failure of a call to WriteByte, WriteBytes, or 
       SetPos.  Initialized to `done' when creating a Writer or by calling 
       ClearError.  The first failed writing (or SetPos) operation changes this
       to indicate the error, all further calls to WriteByte, WriteBytes, or 
       SetPos will be ignored until ClearError resets this flag.  This means 
       that the successful completion of an arbitrary complex sequence of write
       operations can be ensured by asserting that `res' equals `done' 
       beforehand and also after the last operation.  Note that due to 
       buffering a write error may occur when flushing or closing the 
       underlying file, so you have to check the channel's `res' field after 
       any Flush() or the final Close(), too.  *)
     
    bytesWritten*: LONGINT;  (* READ-ONLY *)
    (**Set by WriteByte and WriteBytes to indicate the number of bytes that 
       were successfully written.  *)
       
    positionable*: BOOLEAN;  (* READ-ONLY *)
    (**TRUE iff the Writer can be moved to another position with `SetPos'; for
       channels that can only be written sequentially, like output to terminal,
       this is FALSE.  *)
  END;

TYPE
  ErrorContext = POINTER TO ErrorContextDesc;
  ErrorContextDesc* = RECORD
  END;


VAR
  errorContext: ErrorContext;

(* Reader methods 
   ------------------------------------------------------------------------ *)

PROCEDURE (r: Reader) [ABSTRACT] Pos*(): LONGINT;
(**Returns the current reading position associated with the reader `r' in
   channel `r.base'.  That is, it returns the index of the first byte that is
   read by the next call to ReadByte resp. ReadBytes.  This procedure will
   return `noPosition' if the reader has no concept of a reading position
   (e.g. if it corresponds to input from keyboard), otherwise the result is
   not negative.*)
  END Pos;

PROCEDURE (r: Reader) [ABSTRACT] Available*(): LONGINT;
(**Returns the number of bytes available for the next reading operation.  For
   a file this is the length of the channel `r.base' minus the current reading
   position, for an sequential channel (or a channel designed to handle slow
   transfer rates) this is the number of bytes that can be accessed without
   additional waiting.  The result is -1 if Close() was called for the channel,
   or no more byte are available and the remote end of the channel has been
   closed.
   Note that the number of bytes returned is always a lower approximation of
   the number that could be read at once; for some channels or systems it might
   be as low as 1 even if tons of bytes are waiting to be processed.  *)
  END Available;
  
PROCEDURE (r: Reader) [ABSTRACT] SetPos* (newPos: LONGINT);
(**Sets the reading position to `newPos'.  A negative value of `newPos' or 
   calling this procedure for a reader that doesn't allow positioning will set
   `r.res' to `outOfRange'.  A value larger than the channel's length is legal,
   but the following read operation will most likely fail with an 
   `readAfterEnd' error unless the channel has grown beyond this position in 
   the meantime.
   Calls to this procedure while `r.res # done' will be ignored, in particular
   a call with `r.res.code = readAfterEnd' error will not reset `res' to 
   `done'.  *)
  END SetPos;
  
PROCEDURE (r: Reader) ClearError*;
(**Sets the result flag `r.res' to `done', re-enabling further read operations
   on `r'.  *)
  BEGIN
    r. res := done
  END ClearError;




(* Writer methods 
   ------------------------------------------------------------------------ *)

PROCEDURE (w: Writer) [ABSTRACT] Pos*(): LONGINT;
(**Returns the current writing position associated with the writer `w' in
   channel `w.base', i.e. the index of the first byte that is written by the
   next call to WriteByte resp. WriteBytes.  This procedure will return 
   `noPosition' if the writer has no concept of a writing position (e.g. if it
   corresponds to output to terminal), otherwise the result is not negative. *)
  END Pos;
  
PROCEDURE (w: Writer) [ABSTRACT] SetPos* (newPos: LONGINT);
(**Sets the writing position to `newPos'.  A negative value of `newPos' or 
   calling this procedure for a writer that doesn't allow positioning will set
   `w.res' to `outOfRange'.  A value larger than the channel's length is legal,
   the following write operation will fill the gap between the end of the 
   channel and this position with zero bytes.
   Calls to this procedure while `w.res # done' will be ignored.  *)
  END SetPos;
  
PROCEDURE (w: Writer) ClearError*;
(**Sets the result flag `w.res' to `done', re-enabling further write operations
   on `w'.  *)
  BEGIN
    w. res := done
  END ClearError;

    


(* Channel methods 
   ------------------------------------------------------------------------ *)
   
PROCEDURE (ch: Channel) [ABSTRACT] Length*(): LONGINT;
(**Result is the number of bytes of data that this channel refers to.  If `ch'
   represents a file, then this value is the file's size.  If `ch' has no fixed
   length (e.g. because it's interactive), the result is `noLength'.  *)
  END Length;
  
PROCEDURE (ch: Channel) NewReader*(): Reader;
(**Attaches a new reader to the channel `ch'.  It is placed at the very start 
   of the channel, and its `res' field is initialized to `done'.  `ch.res' is
   set to `done' on success and the new reader is returned.  Otherwise result 
   is NIL and `ch.res' is changed to indicate the error cause.  
   Note that always the same reader is returned if the channel does not support
   multiple reading positions.  *)
  END NewReader;
  
PROCEDURE (ch: Channel) NewWriter*(): Writer;
(**Attaches a new writer to the channel `ch'.  It is placed at the very start 
   of the channel, and its `res' field is initialized to `done'.  `ch.res' is
   set to `done' on success and the new writer is returned.  Otherwise result 
   is NIL and `ch.res' is changed to indicate the error cause.
   Note that always the same reader is returned if the channel does not support
   multiple writing positions.  *)
  END NewWriter;
  
PROCEDURE (ch: Channel) [ABSTRACT] Flush*;
(**Flushes all buffers related to this channel.  Any pending write operations
   are passed to the underlying OS and all buffers are marked as invalid.  The
   next read operation will get its data directly from the channel instead of 
   the buffer.  If a writing error occurs during flushing, the field `ch.res'
   will be changed to `writeError', otherwise it's assigned `done'.  Note that
   you have to check the channel's `res' flag after an explicit flush yourself,
   since none of the attached writers will notice any write error in this 
   case.  *)
  END Flush;

PROCEDURE (ch: Channel) [ABSTRACT] Close*;
(**Flushes all buffers associated with `ch', closes the channel, and frees all
   system resources allocated to it.  This invalidates all riders attached to
   `ch', they can't be used further.  On success, i.e. if all read and write 
   operations (including flush) completed successfully, `ch.res' is set to 
   `done'.  An opened channel can only be closed once, successive calls of 
   `Close' are undefined.  
   Note that unlike the Oberon System all opened channels have to be closed
   explicitly.  Otherwise resources allocated to them will remain blocked.  *)
  END Close;

PROCEDURE (ch: Channel) ClearError*;
(**Sets the result flag `ch.res' to `done'.  *)
  BEGIN
    ch. res := done
  END ClearError;

END M006.
