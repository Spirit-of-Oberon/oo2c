MODULE XML:UnicodeBuffer [OOC_EXTENSIONS];

IMPORT
  SYSTEM, Msg, Strings, LongStrings, Exception, IO,
  XML:InputBuffer, Codec := XML:UnicodeCodec;


TYPE
  Char* = LONGCHAR;
  (**Character type used to represent the Unicode input data.  *)
  CharArray* = POINTER TO ARRAY OF Char;
  (**Character array of arbitrary length.  This type is used for the 
     character data of the input buffer.  *)
  CharPos* = LONGINT;
  (**Character position for a channel.  The very first byte that would
     be read from the channel has position 0.  *)
     
CONST
  markerEOB* = 0FFFEX;
  (**This is the character value that is used to mark the end of the Unicode
     buffer.  It is the first non-input character after the last valid document
     character in the buffer.  Because this character code is never produced
     by the Unicode decoders, testing against this character code gives
     a definitive answer.  Calling @oproc{Input.NextBlock} will replace
     the character with a valid character from the input document, or with
     @oconst{markerEOD}.  *)
  markerEOD* = 0FFFFX;
  (**This character value marks the end of the document.  It is the first
     non-input character after the last valid document character in the buffer.
     This character is never emitted by the Unicode decoders, and it is
     never replaced with another value.  *)
  markerError* = Codec.decodeError;
  (**This character is inserted into the processor output for characters that
     are not valid in XML.  *)
    
TYPE
  Input* = POINTER TO InputDesc;
  InputDesc = RECORD
    byteBuffer: InputBuffer.Buffer;
    byteEndOfData: BOOLEAN;
    codecFactory-: Codec.Factory;
    codec-: Codec.Codec;
    autoDetectedCodec-: BOOLEAN;
    
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
       discarded by @oproc{Input.NextBlock}.  Possible values for this field
       are [0..@ofield{endOfBuffer}].  *)
    errList-: Msg.MsgList;
    (**Error messages are appended to this list.  *)
  END;

CONST
  charsPerRead = 4*1024;
  (* always read a multiple of @oconst{charsPerRead} characters from the input
     channel, >= Codec.maxUCS2EncodingLength *)
  offsetSizeOfBuffer = 32;
  sizeOfInputBuffer* = 4*charsPerRead-offsetSizeOfBuffer;(* must not be zero *)
  (* initial size of input buffer; the buffer will be extended when
     required; minumum is 4 bytes *)
  
(*CONST
  (* to test the buffer handling of the parser, set `charsPerRead' to 2
     and `sizeOfInputBuffer' successively to 4, 5, 6, 7; for each setting, run
     the full set of tests  *)
  charsPerRead = 2;
  sizeOfInputBuffer = 4;*)


CONST
  sizeOutputByteBuffer = 8*1024;
  sizeOutputUnicodeBuffer = sizeOutputByteBuffer;

TYPE
  Output* = POINTER TO OutputDesc;
  OutputDesc* = RECORD
    codecFactory-: Codec.Factory;
    codec-: Codec.Codec;
    (**Any encoding errors are signalled by incrementing
       @ofield{Codec.Codec.invalidChars}.  *)
    writer-: IO.ByteChannel;
    error-: IO.Error;
    
    byteBuffer: POINTER TO ARRAY sizeOutputByteBuffer OF CHAR;
    byteStart, byteEnd: LONGINT;
    unicodeBuffer: POINTER TO ARRAY sizeOutputUnicodeBuffer OF LONGCHAR;
    unicodeEnd: LONGINT;
  END;


PROCEDURE AutodetectEnc (input: Input; VAR enc: ARRAY OF CHAR): LONGINT;
(* Do autodetection of used character encoding.  The guess should be good
   enough to get the parser through the encoding declaration, that may 
   revise the decision made here.  This procedure is based on Appendix F of
   the XML 1.0 Technical Report (more precisely, on the errata E44 that should
   go into the report's second edition).
   
   Bugfix: The UTF-16 rules with byte order mark in E44 break for the test file
   xmltest/valid/ext-sa/014.ent, which begins with 2 byte order marks; this is
   perfectly valid, therefore the implementation was changed from
     "FE FF 00 ##" and "FF FE ## 00"
   to
     ("FE FF 00 ##" or "FE FF ## 00" or "FE FF ## ##") and
     ("FF FE 00 ##" or "FF FE ## 00" or "FF FE ## ##")

   Result: An encoding identifier in @oparam{enc}, and the number of characters
     that make up the byte order mark (BOM), and that should be skipped in
     the input stream.  *)
  VAR
    skip: LONGINT;
    str: ARRAY 16 OF CHAR;
    x: InputBuffer.CharArray;
  BEGIN
    ASSERT (input. byteBuffer. offsetFromPos0 = 0);
    str := "UTF-8"; skip := 0; 
    x := input. byteBuffer. chars;
    IF (input. byteBuffer. endOfBuffer >= 4) THEN
      CASE x[0] OF
      | 000X:
        IF (x[1] = 0X) THEN
          IF (x[2] = 0X) & (x[3] = 3CX) THEN  (* UCS-4, 1234 order *)
            str := "UCS-4-1234"
          ELSIF (x[2] = 3CX) & (x[3] = 0X) THEN  (* UCS-4, 2143 order *)
            str := "UCS-4-2143"
          ELSIF (x[2] = 0FEX) & (x[3] = 0FFX) THEN(* UCS-4, 1234 order, BOM *)
            str := "UCS-4-1234"; skip := 4
          ELSIF (x[2] = 0FFX) & (x[3] = 0FEX) THEN(* UCS-4, 2143 order, BOM *)
            str := "UCS-4-2143"; skip := 4
          END
        ELSIF (x[1] = 3CX) & (x[2] = 0X) & (x[3] = 0X) THEN
          (* UCS-4, 3412 order *)
          str := "UCS-4-3412"
        ELSIF (x[1] = 3CX) & (x[2] = 0X) & (x[3] = 3FX) THEN  (* UTF-16LE *)
          str := "UTF16-LE"
        END
      | 03CX:
        IF (x[1] = 0X) THEN
          IF (x[2] = 0X) & (x[3] = 0X) THEN  (* UTF-16, 4321 order *)
            str := "UCS-4-4321"
          ELSIF (x[2] = 3FX) & (x[3] = 0X) THEN  (* UTF-16, little endian *)
            str := "UTF-16LE"
          END
        ELSIF (x[1] = 3FX) & (x[2] = 78X) & (x[3] = 6DX) THEN
          str := "UTF-8"
        END
      | 04CX:
        IF (x[1] = 6FX) & (x[2] = 0A7X) & (x[3] = 94X) THEN
          (* some variant of EBCDIC, code page can only be determined from
             encoding declaration *)
          str := "EBCDIC"
        END
      | 0EFX:
        IF (x[1] = 0BBX) & (x[2] = 0BFX) THEN
          (* UTF-8, with byte order mark *)
          str := "UTF-8"; skip := 3
        END
      | 0FEX:
        IF (x[1] = 0FFX) THEN
          IF (x[2] # 0X) OR (x[3] # 0X) THEN
            (* UTF-16 big endian, with byte order mark *)
            str := "UTF-16BE"; skip := 2
          ELSIF (x[2] = 0X) & (x[3] = 0X) THEN(* UCS-4, 3412 order, BOM *)
            str := "UCS-4-3412"; skip := 4
          END
        END
      | 0FFX:
        IF (x[1] = 0FEX) THEN
          IF (x[2] # 0X) OR (x[3] # 0X) THEN
            (* UTF-16 little endian, with byte order mark *)
            str := "UTF-16LE"; skip := 2
          ELSIF (x[2] = 0X) & (x[3] = 0X) THEN(* UCS-4, 4321 order, BOM *)
            str := "UCS-4-4321"; skip := 4
          END
        END
      ELSE  (* use default *)
      END
    END;
    COPY (str, enc);
    RETURN skip
  END AutodetectEnc;
    

(*PROCEDURE WriteBuffer (in: Input);
  VAR
    i: LONGINT;
  BEGIN
    Out.String ("UNICODE BUFFER >>>");
    FOR i := 0 TO in. endOfBuffer-1 DO
      IF (in. chars[i] > 0FFX) THEN
        Out.Char("?")
      ELSE
        Out.Char(SHORT (in. chars[i]))
      END
    END;
    Out.String ("<<< EOB");
    Out.Ln;
  END WriteBuffer;*)

PROCEDURE (in: Input) NextBlock* (): BOOLEAN
RAISES IO.Error;
(**Tries to read additional data from @oparam{in}'s channel.  If at least one
   character could be read, result is @code{TRUE}.  @code{FALSE} means
   that not a single character was added to the buffer, either because the end
   of the file was reached, or because of a read error.  In the latter case,
   an message is added to @oparam{in}'s error list.
   
   A call to this buffer may change the fields @ofield{Input.chars},
   @ofield{Input.offsetFromPos0}, and @ofield{Input.endOfBuffer}.  If
   part of the buffer is discarded, @ofield{Input.discardable} is 
   set to zero.  *)
  VAR
    len: CharPos;
    nChars: CharArray;
  BEGIN
    IF (in. chars[in. endOfBuffer] = markerEOD) THEN
      RETURN FALSE
    ELSIF ~in. byteEndOfData &
       (in. byteBuffer. discardable >= LEN (in. byteBuffer. chars^) DIV 2) THEN
      in. byteEndOfData := ~in. byteBuffer. NextBlock()
    END;
    
    ASSERT (in. chars[in. endOfBuffer] = markerEOB);
    IF (in. discardable >= charsPerRead) THEN
      (* move data to beginning of buffer *)
      len := in. endOfBuffer - in. discardable;
      IF (len < in. discardable) THEN
        (* can use MOVE only when the memory areas do not intersect; the 
           chance that we cannot MOVE is so small, that we simply ignore 
           this case and add more memory to the buffer if it ever happens *)
        SYSTEM.MOVE (SYSTEM.ADR (in. chars[in. discardable]), 
                     SYSTEM.ADR (in. chars^),
                     (len+1)*SIZE (Char));
        INC (in. offsetFromPos0, in. discardable);
        in. endOfBuffer := len;
        in. discardable := 0
      END
    END;
    ASSERT (in. chars[in. endOfBuffer] = markerEOB);

    IF (in. endOfBuffer+charsPerRead >= LEN (in. chars^)) THEN
      (* extend buffer so that it can hold in. endOfBuffer+charsPerRead+1 
         bytes *)
      len := LEN (in. chars^);
      REPEAT
        INC (len, charsPerRead)
      UNTIL (in. endOfBuffer+charsPerRead < len);
      NEW (nChars, len);
      SYSTEM.MOVE (SYSTEM.ADR (in. chars^),
                   SYSTEM.ADR (nChars^),
                   (in. endOfBuffer+1)*SIZE (Char));
      in. chars := nChars
    END;
    
    IF (in. byteBuffer. discardable # in. byteBuffer. endOfBuffer) THEN
      (* append additional input to the buffer; at least one character
         is decoded *)
      in. codec. Decode (in. byteBuffer. chars^,
                     in. byteBuffer. discardable, in. byteBuffer. endOfBuffer,
                     in. chars^,
                     in. endOfBuffer, LEN (in. chars^)-1,
                     in. byteBuffer. discardable, in. endOfBuffer);
      in. chars[in. endOfBuffer] := markerEOB;
      RETURN TRUE
    ELSE                                 (* no further input *)
      in. chars[in. endOfBuffer] := markerEOD;
      RETURN FALSE
    END
  END NextBlock;

PROCEDURE (in: Input) Close*() RAISES IO.Error;
(**Closes the channel associated with buffer @oparam{in}.  Afterwards, no
   further operations are permitted on @oparam{in}, except for reading the
   field @ofield{Input.errList}.  *)
  BEGIN
    in. byteBuffer. Close;
    in. byteBuffer := NIL;
    in. codec := NIL;
    in. chars := NIL;
  END Close;

PROCEDURE (in: Input) SetCodec* (cf: Codec.Factory; autoDetect: BOOLEAN)
RAISES IO.Error;
(* pre: in.byteBuffer.offsetFromPos0=0 *)
  VAR
    dummy: BOOLEAN;
  BEGIN
    ASSERT (in. byteBuffer. offsetFromPos0 = 0);
    in. codecFactory := cf;
    in. codec := cf. NewCodecBOM
      (in. byteBuffer. chars^, 0, in. byteBuffer. endOfBuffer,
       in. byteBuffer. discardable);
    in. chars[0] := markerEOB;
    in. discardable := 0;
    in. offsetFromPos0 := 0;
    in. endOfBuffer := 0;
    dummy := in. NextBlock();
    in. autoDetectedCodec := autoDetect
  END SetCodec;

PROCEDURE InitInput* (input: Input; new: BOOLEAN;
                      reader: IO.ByteChannel; codecFactory: Codec.Factory;
                      errList: Msg.MsgList)
RAISES IO.Error;
  VAR
    encoding: ARRAY 256 OF CHAR;
    skip: LONGINT;
    autoDetect: BOOLEAN;
  BEGIN
    IF new THEN
      input. byteBuffer := InputBuffer.New (reader, errList);
      NEW (input. chars, sizeOfInputBuffer);
    ELSE
      ASSERT (FALSE);
      (*input. byteBuffer. Reset (reader, errList)*)
    END;
    
    input. byteEndOfData := FALSE;
    input. errList := errList;
    
    autoDetect := FALSE;
    IF (codecFactory = NIL) THEN
      skip := AutodetectEnc (input, encoding);
      codecFactory := Codec.GetFactory (encoding);
      ASSERT (codecFactory # NIL);
      autoDetect := TRUE
    END;
    
    input. SetCodec (codecFactory, autoDetect);
  END InitInput;

(*PROCEDURE (input: Input) Reset* (reader: Channel.Reader; 
                                 codecFactory: Codec.Factory;
                                 errList: Msg.MsgList);
(**Resets the buffer @oparam{input} to its initial state.  This has the same
   effect as calling @oproc{NewInput} with the same parameters, except that
   some of the resources allocated by @oparam{input} are reused.

   Note: This method does not change the state of the reader @oparam{reader}.
   For example, if the reader should continue reading a file from its
   beginning, then it must be positioned @emph{before} this method is called.  *)
  BEGIN
    InitInput (input, FALSE, reader, codecFactory, errList)
  END Reset;*)

PROCEDURE NewInput* (reader: IO.ByteChannel; codecFactory: Codec.Factory;
                     errList: Msg.MsgList): Input
RAISES IO.Error;
(**Create new input buffer for reader @oparam{reader} and try to read the first
   block of data from it.  Returns an initialized input buffer with up to
   @oconst{sizeOfInputBuffer} characters of input.  *)
  VAR
    input: Input;
  BEGIN
    NEW (input);
    InitInput (input, TRUE, reader, codecFactory, errList);
    RETURN input
  END NewInput;

(* ------------------------------------------------------------------------ *)

PROCEDURE FlushBytes (out: Output);
  VAR
    d: LONGINT;
    e: Exception.Exception;
  BEGIN
    TRY
      d := out. writer. Write (out. byteBuffer^, 0, out. byteEnd);
    CATCH IO.Error:
      e := Exception.Current();
      out.error := e(IO.Error);
    END;
    out. byteEnd := 0
  END FlushBytes;

PROCEDURE Encode (out: Output; all: BOOLEAN);
  VAR
    start, limit, i, len: LONGINT;
  BEGIN
    start := 0;
    IF all THEN
      limit := out. unicodeEnd-Codec.maxUCS2EncodingLength
    ELSE
      limit := out. unicodeEnd-LEN (out. byteBuffer^) DIV 8
    END;
    WHILE (start <= limit) DO
      IF (LEN (out. byteBuffer^)-out. byteEnd < Codec.maxUTF8EncodingLength) THEN
        FlushBytes (out)
      END;
      out. codec. Encode (out. unicodeBuffer^, start, out. unicodeEnd,
                        out. byteBuffer^, out. byteEnd, LEN (out. byteBuffer^),
                        start, out. byteEnd)
    END;
    
    IF all & (start # out. unicodeEnd) THEN
      IF (LEN (out. byteBuffer^)-out. byteEnd < Codec.maxUTF8EncodingLength) THEN
        FlushBytes (out)
      END;
      out. codec. Encode (out. unicodeBuffer^, start, out. unicodeEnd,
                        out. byteBuffer^, out. byteEnd, LEN (out. byteBuffer^),
                        start, out. byteEnd);
      ASSERT (start = out. unicodeEnd)
    ELSE
      len := out. unicodeEnd-start;
      FOR i := 0 TO len-1 DO
        out. unicodeBuffer[i] := out. unicodeBuffer[start+i]
      END;
      out. unicodeEnd := len
    END
  END Encode;

PROCEDURE (out: Output) Write16I* (str[NO_COPY]: ARRAY OF Char;
                                         start, end: CharPos);
  VAR
    len: LONGINT;
  BEGIN
    len := end-start;
    IF (len # 0) & (out. unicodeEnd+len <= LEN (out. unicodeBuffer^)) THEN
      SYSTEM.MOVE (SYSTEM.ADR (str[start]),
                   SYSTEM.ADR (out. unicodeBuffer[out. unicodeEnd]),
                   len*SIZE (Char));
      INC (out. unicodeEnd, len)
    ELSE
      WHILE (start # end) DO
        IF (out. unicodeEnd = LEN (out. unicodeBuffer^)) THEN
          Encode (out, FALSE)
        END;
        len := LEN (out. unicodeBuffer^)-out. unicodeEnd;
        IF (len > end-start) THEN
          len := end-start
        END;
        out. Write16I (str, start, start+len);
        INC (start, len)
      END
    END
  END Write16I;

PROCEDURE (out: Output) Write8I* (str[NO_COPY]: ARRAY OF CHAR;
                                  start, end: CharPos);
  VAR
    pos, len: LONGINT;
  BEGIN
    len := end-start;
    IF (len # 0) & (out. unicodeEnd+len <= LEN (out. unicodeBuffer^)) THEN
      pos := out. unicodeEnd-start;
      WHILE (start # end) DO
        out. unicodeBuffer[pos+start] := str[start];
        INC (start)
      END;
      INC (out. unicodeEnd, len)
    ELSE
      WHILE (start # end) DO
        IF (out. unicodeEnd = LEN (out. unicodeBuffer^)) THEN
          Encode (out, FALSE)
        END;
        len := LEN (out. unicodeBuffer^)-out. unicodeEnd;
        IF (len > end-start) THEN
          len := end-start
        END;
        out. Write8I (str, start, start+len);
        INC (start, len)
      END
    END
  END Write8I;

PROCEDURE (out: Output) Write16* (str[NO_COPY]: ARRAY OF Char);
  BEGIN
    out. Write16I (str, 0, LongStrings.Length (str))
  END Write16;

PROCEDURE (out: Output) Write8* (str[NO_COPY]: ARRAY OF CHAR);
  BEGIN
    out. Write8I (str, 0, Strings.Length (str))
  END Write8;

PROCEDURE (out: Output) Flush*() RAISES IO.Error;
(**Flushes the contents of the output buffer to the channel.  Then, flush is
   called on the channel itself.  *)
  BEGIN
    Encode (out, TRUE);
    FlushBytes (out);
    out. writer. Flush
  END Flush;

PROCEDURE InitOutput* (out: Output; new: BOOLEAN;
                       writer: IO.ByteChannel;
                       codecFactory: Codec.Factory; createBOM: BOOLEAN);
  BEGIN
    IF new THEN
      NEW (out. byteBuffer);
      NEW (out. unicodeBuffer);
    END;
    
    out. codecFactory := codecFactory;
    out. codec := codecFactory. NewCodec();
    out. writer := writer;
    out. error := NIL;
    out. byteStart := 0; out. byteEnd := 0;
    out. unicodeEnd := 0;
    
    IF createBOM THEN
      out. codec. EncodeBOM (out. byteBuffer^, out. byteEnd,
                             LEN (out. byteBuffer^), out. byteEnd)
    END
  END InitOutput;

(*PROCEDURE (output: Output) Reset* (writer: Channel.Writer; 
                                   codecFactory: Codec.Factory;
                                   createBOM: BOOLEAN);
(**Resets the buffer @oparam{output} to its initial state.  This has the same
   effect as calling @oproc{NewOutput} with the same parameters, except that
   some of the resources allocated by @oparam{output} are reused.

   Note: This method does not change the state of the writer @oparam{writer}.
   For example, if the writer should continue writing to the beginning of a
   file, then it should be positioned @emph{before} this method is called.  *)
  BEGIN
    InitOutput (output, FALSE, writer, codecFactory, createBOM)
  END Reset;*)

PROCEDURE NewOutput* (writer: IO.ByteChannel; codecFactory: Codec.Factory;
                      createBOM: BOOLEAN): Output;
(**Creates new output buffer for writer @oparam{writer}.  *)
  VAR
    output: Output;
  BEGIN
    NEW (output);
    InitOutput (output, TRUE, writer, codecFactory, createBOM);
    RETURN output
  END NewOutput;

BEGIN
  ASSERT (charsPerRead >= Codec.maxUCS2EncodingLength)
END XML:UnicodeBuffer.
