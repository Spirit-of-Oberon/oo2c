(* 	$Id: InputBuffer.Mod,v 1.3 2003/01/30 23:38:20 mva Exp $	 *)
MODULE OOC:Scanner:InputBuffer;
(*  Defines input buffer for OOC's scanner.
    Copyright (C) 2000, 2001, 2003  Michael van Acken

    This file is part of OOC.

    OOC is free software; you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.  

    OOC is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
    License for more details. 

    You should have received a copy of the GNU General Public License
    along with OOC. If not, write to the Free Software Foundation, 59
    Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*)

IMPORT
  SYSTEM, IO, OOC:Error;

TYPE
  Char* = CHAR;
  (**Character type used to represent the input data.  With OOC, this is
     either @otype{CHAR}, or @otype{LONGCHAR} to permit processing of Unicode
     input files.  Switching between character types is possible, although 
     this will need manual adjustments to the scanner modules.  *)
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
    errList-: Error.List;
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
    IF (d <= 0) THEN
      ASSERT (b. chars[b. endOfBuffer] = markerEOB);
      RETURN FALSE
    ELSE
      INC (b. endOfBuffer, d);
      b. chars[b. endOfBuffer] := markerEOB;
      ASSERT (b. chars[b. endOfBuffer] = markerEOB);
      RETURN TRUE
    END;
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
    b. r. Close;
    b. r := NIL;
    b. chars := NIL;
  END Close;

PROCEDURE New* (ch: IO.ByteChannel; errList: Error.List): Buffer;
(**Create new input buffer for channel @oparam{ch} and try to read the first
   block of data from it.  
   On success, this function returns an initialized input buffer with up to 
   @oconst{sizeOfBuffer} characters of input.  *)
  VAR
    b: Buffer;
  BEGIN
    NEW (b);
    b. r := ch;
    b. discardable := 0;
    b. offsetFromPos0 := 0;
    b. endOfBuffer := 0;
    b. errList := errList;
    NEW (b. chars, sizeOfBuffer);
    b. chars[0] := markerEOB;
    RETURN b;
  END New;

END OOC:Scanner:InputBuffer.
