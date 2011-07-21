(* 	$Id: InputBuffer.Mod,v 1.2 2003/01/30 23:36:04 mva Exp $	 *)
MODULE XML:InputBuffer;
(*  Defines input buffer for OOC's scanner.
    Copyright (C) 2000, 2003  Michael van Acken
*)

IMPORT
  SYSTEM, Msg, IO;

TYPE
  Char* = CHAR;
  (**Character type used to represent the input data.  *)
  CharArray* = POINTER TO ARRAY OF Char;
  (**Character array of arbitrary length.  This type is used for the 
     character data of the input buffer.  *)
  CharPos* = LONGINT;
  (**Character position for a channel.  The very first byte that would
     be read from the channel has position 0.  *)
     
CONST
  markerEOB* = 0X;
  (**This is the character value that is used to mark the first invalid
     character after the buffer.  Use @oproc{Buffer.EndOfBuffer} to determine,
     whether the character position is indeed the end of the buffer.  *)

TYPE
  Buffer* = POINTER TO BufferDesc;
  BufferDesc = RECORD
    r: IO.ByteChannel;
    chars-: CharArray;
    (**Character data from input channel.  *)
    offsetFromPos0-: CharPos;
    (**Offset of @samp{chars[0]} from the beginning of the input text.  *)
    endOfBuffer-: CharPos;
    (**Number of valid characters in @ofield{chars}.  All index values in the
       range [0..@ofield{endOfBuffer}-1] hold valid characters.  The value
       of @samp{chars[endOfBuffer]} is @oconst{markerEOB}.  *)
    discardable*: CharPos;
    (**The client can define here how many bytes that have been read into
       the buffer will not be inspected again later, and can therefore be
       discarded by @oproc{Buffer.NextBlock}.  Possible values for this field
       are [0..@ofield{endOfBuffer}].  *)
    errList-: Msg.MsgList;
    (**Error messages are appended to this list.  *)
  END;

CONST
  bytesPerRead = 4*1024;
  (* always read a multiple of @oconst{bytesPerRead} from the input
     channel *)
  sizeOfBuffer* = 4*bytesPerRead-32;      (* must not be zero *)
  (* initial size of input buffer; the buffer will be extended when
     required *)
  

PROCEDURE (b: Buffer) NextBlock* (): BOOLEAN RAISES IO.Error;
(**Tries to read additional data from @oparam{b}'s channel.  If at least one
   byte could be read, result is @code{TRUE}.  @code{FALSE} means that not
   a single byte was added to the buffer, either because the end of the file
   was reached, or because of a read error.  In the latter case, an message
   is added to @oparam{b}'s error list.
   
   A call to this buffer may change the fields @ofield{Buffer.chars},
   @ofield{Buffer.offsetFromPos0}, and @ofield{Buffer.endOfBuffer}.  If
   part of the buffer is discarded, @ofield{Buffer.discardable} is 
   set to zero.  *)
  VAR
    len: CharPos;
    nChars: CharArray;
    d: LONGINT;
  BEGIN
    ASSERT (b. chars[b. endOfBuffer] = markerEOB);
    ASSERT (b. chars[b. endOfBuffer] = markerEOB);
    IF (b. discardable >= bytesPerRead) THEN
      (* move data to beginning of buffer *)
      len := b. endOfBuffer - b. discardable;
      IF (len < b. discardable) THEN
        (* can use MOVE only when the memory areas do not intersect; the 
           chance that we cannot MOVE is so small, that we simply ignore 
           this case and add more memory to the buffer if it ever happens *)
        SYSTEM.MOVE (SYSTEM.ADR (b. chars[b. discardable]), 
                     SYSTEM.ADR (b. chars^),
                     len+1);
        INC (b. offsetFromPos0, b. discardable);
        b. endOfBuffer := len;
        b. discardable := 0
      END
    END;
    ASSERT (b. chars[b. endOfBuffer] = markerEOB);
    
    IF (b. endOfBuffer+bytesPerRead >= LEN (b. chars^)) THEN
      (* extend buffer so that it can hold b. endOfBuffer+bytesPerRead+1 
         bytes *)
      len := LEN (b. chars^);
      REPEAT
        INC (len, bytesPerRead)
      UNTIL (b. endOfBuffer+bytesPerRead < len);
      NEW (nChars, len);
      SYSTEM.MOVE (SYSTEM.ADR (b. chars^),
                   SYSTEM.ADR (nChars^),
                   b. endOfBuffer+1);
      b. chars := nChars
    END;
    
    (* append additional input to the buffer; read only multiple of
       bytesPerRead  *)
    len := LEN (b. chars^) - b. endOfBuffer - 1;
    len := (len DIV bytesPerRead)*bytesPerRead;
    d := b. r. Read (b. chars^, b. endOfBuffer, len);
    IF (d = -1) THEN
      ASSERT (b. chars[b. endOfBuffer] = markerEOB);
      RETURN FALSE
    ELSE
      INC (b. endOfBuffer, d);
      b. chars[b. endOfBuffer] := markerEOB;
      ASSERT (b. chars[b. endOfBuffer] = markerEOB);
      RETURN TRUE
    END
  END NextBlock;

PROCEDURE (b: Buffer) EndOfBuffer* (cpos: CharPos): BOOLEAN;
(**Returns TRUE iff character position @oparam{cpos} refers to the position
   after the last valid byte in the buffer.
   
   @precond
   @samp{0} <= @oparam{cpos} <= @samp{b.endOfBuffer}
   and @samp{b. chars[cpos] = markerEOB}
   @end precond  *)
  BEGIN
    ASSERT (0 <= cpos);
    ASSERT (cpos <= b. endOfBuffer);
    ASSERT (b. chars[cpos] = markerEOB);
    RETURN (cpos = b. endOfBuffer)
  END EndOfBuffer;

PROCEDURE (b: Buffer) Close*() RAISES IO.Error;
(**Closes the channel associated with buffer @oparam{b}.  Afterwards, no
   further operations are permitted on @oparam{b}, except for reading the
   field @ofield{Buffer.errList}.  *)
  BEGIN
    b. r. Close();
    b. r := NIL;
    b. chars := NIL;
  END Close;

PROCEDURE Init (b: Buffer; new: BOOLEAN;
                reader: IO.ByteChannel; errList: Msg.MsgList)
RAISES IO.Error;
  VAR
    dummy: BOOLEAN;
  BEGIN
    b. r := reader;
    b. discardable := 0;
    b. offsetFromPos0 := 0;
    b. endOfBuffer := 0;
    b. errList := errList;
    IF new THEN
      NEW (b. chars, sizeOfBuffer)
    END;
    b. chars[0] := markerEOB;
    dummy := b. NextBlock();
  END Init;

(*PROCEDURE (b: Buffer) Reset* (reader: Channel.Reader; errList: Msg.MsgList);
(**Resets the buffer @oparam{b} to its initial state.  This has the same effect
   as calling @oproc{New} with the same parameters, except that some of the
   resources allocated by @oparam{b} are reused.
   
   Note: This method does not change the state of the reader @oparam{reader}.
   For example, if the reader should continue reading a file from its
   beginning, then it must be positioned @emph{before} this method is called.*)
  BEGIN
    Init (b, FALSE, reader, errList)
  END Reset;*)

PROCEDURE New* (reader: IO.ByteChannel; errList: Msg.MsgList): Buffer
RAISES IO.Error;
(**Creates a new input buffer for reader @oparam{reader} and tries to read the
   first block of data from it.  Returns an initialized input buffer with up to
   @oconst{sizeOfBuffer} characters of input.  *)
  VAR
    b: Buffer;
  BEGIN
    NEW (b);
    Init (b, TRUE, reader, errList);
    RETURN b
  END New;

END XML:InputBuffer.
