(*	$Id$	*)
MODULE ADT:String [OOC_EXTENSIONS];
(*  Immutable string data type.
    Copyright (C) 2001  Stewart Greenhill

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
  ADT:Object, Language:=LanguageNew, S := SYSTEM;

TYPE
  CharArray* = ARRAY OF CHAR;
  CharArrayPtr* = POINTER TO CharArray;

  String* = POINTER TO StringDesc;
  StringDesc* = RECORD (Object.StringDesc)
    (** A string value. Oberon-2 definition includes strings, but not as first
     * order types. String values are immutable and so may always be safely
     * passed by reference.  Functions are provided to retrieve copies of the
     * String character array. *)
    length- : LONGINT;
    array- : CharArrayPtr;
  END;

  MapCharProc* = PROCEDURE (c : CHAR) : CHAR;

  StringArray* = ARRAY OF String;
  StringArrayPtr* = POINTER TO StringArray;


PROCEDURE CompareRegion(VAR source : ARRAY OF CHAR; pos, endPos : LONGINT; VAR dest : ARRAY OF CHAR; destPos : LONGINT) : SHORTINT;
(** Compare @samp{endPos-pos} characters from position @oparam{pos} in source
 * string @oparam{source} with characters at position @oparam{destPos} in
 * string @oparam{dest}. Returns -1, 0, or 1 according to whether
 * @oparam{source} is lexically `less than', `equal', or `greater than'
 * @oparam{dest}.  *)

VAR count : LONGINT;
BEGIN
  count := endPos - pos;
  ASSERT(count >= 0);
  ASSERT((pos >= 0) & (endPos <= LEN(source)));
  ASSERT((destPos >= 0) & (destPos + count <= LEN(dest)));

  WHILE (pos < endPos) & (source[pos] = dest[destPos]) DO
    INC(pos); INC(destPos);
  END;
  IF pos = endPos THEN RETURN 0 END;
  IF source[pos] < dest[destPos] THEN
    RETURN -1
  ELSE 
    RETURN 1;
  END;
END CompareRegion;

PROCEDURE CopyRegion (VAR source : ARRAY OF CHAR; pos, endPos : LONGINT; VAR dest : ARRAY OF CHAR; destPos : LONGINT);
(** Copy exactly @samp{endPos-pos} characters from position @oparam{pos} in
 * source string @oparam{source} to position @oparam{destPos} in destination
 * string @oparam{dest}. *)

VAR count : LONGINT;
BEGIN
  count := endPos - pos;
  ASSERT(count >= 0);
  ASSERT((pos >= 0) & (endPos <= LEN(source)));
  ASSERT((destPos >= 0) & (destPos + count <= LEN(dest)));
  WHILE pos < endPos DO
    dest[destPos] := source[pos];
    INC(pos); INC(destPos);
  END;
END CopyRegion;

PROCEDURE ArraySize (size : LONGINT) : LONGINT;
(** Determine how many elements to allocate for a string of length
 * @oparam{size}. Note that in general, strings are not null-terminated.
 * Procedures that copy data out of strings (eg. GetChars) may add a terminator
 * to the result. Possibly, adjust allocation here to be kind to the GC. *)

BEGIN
  (* avoid allocating zero length array & leave room for additional 0X *)
  RETURN size+1
END ArraySize;

PROCEDURE InitString (str : String; length : LONGINT);
(** Initialise length of string @oparam{str} and allocate an array sufficient
 * to hold the string plus a terminating null *)

BEGIN
  Object.Init(str);
  NEW(str.array, ArraySize(length));
  str.length := length;
END InitString;

PROCEDURE InitRegion* (str : String; VAR source : ARRAY OF CHAR; pos, endPos : LONGINT);
(** Initialise string @oparam{str} with @samp{endPos-pos} characters from
 * array @oparam{source} starting at position @oparam{pos}. *)

VAR count : LONGINT;
BEGIN
  count := endPos - pos;
  ASSERT(count >= 0);
  InitString(str, count);
  CopyRegion(source, pos, endPos, str.array^, 0);
  str.array[count] := 0X;
END InitRegion;

PROCEDURE Init* (str : String; VAR source : ARRAY OF CHAR);
(** Initialise string @oparam{str} with the string contained in
 * @oparam{source}. *)

VAR i: LONGINT;
BEGIN
  i := 0;
  WHILE (source[i] # 0X) DO INC(i) END;
  InitRegion(str, source, 0, i)
END Init;

PROCEDURE (str : String) Map* (p : MapCharProc) : String;
(** Return a string created by applying a mapping function @oparam{p} to each
 * of the characters in string @oparam{str}. *)

VAR
  i : LONGINT; 
  res : String; 
BEGIN
  NEW(res);
  InitString(res, str.length);
  FOR i := 0 TO str.length-1 DO
    res.array[i] := p(str.array[i]);
  END;
  res.array[str.length] := 0X;
  RETURN res;
END Map;

PROCEDURE New* (source[NO_COPY] : ARRAY OF CHAR) : String;
(** Return a new @otype{String} with for the null-terminated string contained
 * in the array @oparam{source} *)

VAR res : String;
BEGIN
  NEW(res);
  Init(res, source);
  RETURN res;
END New;

PROCEDURE NewRegion* (source[NO_COPY] : ARRAY OF CHAR; pos, endPos : LONGINT) : String;
(** Return a new @otype{String} with @samp{endPos-pos} characters from
 * array @oparam{source} starting at position @oparam{pos}. Note: the
 * source and result string may include the @code{0X} character. *)

VAR res : String;
BEGIN
  NEW(res);
  InitRegion(res, source, pos, endPos);
  RETURN res;
END NewRegion;

PROCEDURE (str : String) ToString* () : String;
BEGIN
  RETURN str;
END ToString;

PROCEDURE (str : String) Concat* (source : String) : String;
(** Return a new @otype{String} that contains the string @oparam{source}
 * appended to the string @oparam{str} *)

VAR 
  res : String;
  length : LONGINT;
BEGIN
  NEW(res);
  length := str.length + source.length;
  InitString(res, length);
  CopyRegion(str.array^, 0, str.length, res.array^, 0);
  CopyRegion(source.array^, 0, source.length, res.array^, str.length);
  res.array[length] := 0X;
  RETURN res;
END Concat;

PROCEDURE (str : String) GetChar* (pos : LONGINT) : CHAR;
(** Return the character at position @oparam{pos} in string @oparam{str}. *)
BEGIN
  ASSERT(pos <= str.length);
  RETURN str.array^[pos];
END GetChar;

PROCEDURE (s : String) GetChars* (VAR destination : ARRAY OF CHAR);
(** Copy the characters in @oparam{s} into a character array @oparam{s}. If
 * there is room in the result array, it will be null terminated. *)

VAR limit : LONGINT;
BEGIN
  limit := LEN(destination) - 1;
  IF s.length < limit THEN limit := s.length END;
  CopyRegion(s.array^, 0, limit, destination, 0);
  destination[limit] := 0X;
END GetChars;

PROCEDURE (str : String) GetCharsRegion* (pos, endPos : LONGINT; VAR destination : ARRAY OF CHAR; destPos : LONGINT);
(** Copy @samp{endPos-pos} characters from starting at position
 * @oparam{pos} into character array @oparam{destination}. *)

VAR count : LONGINT;
BEGIN
  count := endPos - pos;
  ASSERT(destPos + count <= LEN(destination));
  CopyRegion(str.array^, pos, endPos, destination, destPos); 
  destination[destPos+count] := 0X
END GetCharsRegion;

PROCEDURE (str : String) Extract* (startPos, numberToExtract: LONGINT): String;
(** Return a new string containing exactly @oparam{numberToExtract} characters
 * starting at position @oparam{startPos} in @oparam{str}. *)

BEGIN
  ASSERT(startPos + numberToExtract <= str.length);
  RETURN NewRegion(str.array^, startPos, startPos+numberToExtract);
END Extract;

PROCEDURE (str : String) Size* () : LONGINT;
(**Return the length of string @oparam{str}, not including the terminating null
  *character  *)
BEGIN
  RETURN str.length;
END Size;


PROCEDURE (str: String) IndexOf* (char: CHAR; pos: LONGINT): LONGINT;
(**Returns the index of the first occurence of @oparam{char} at or after
   position @oparam{pos}.  If no such character exists, result is @code{-1}.

   @precond
   @samp{0 <= pos <= str.length}
   @end precond  *)
  VAR
    endpos: LONGINT;
  BEGIN
    endpos := str. length;
    WHILE (pos # endpos) DO
      IF (str. array[pos] = char) THEN
        RETURN pos
      END;
      INC (pos)
    END;
    RETURN -1
  END IndexOf;

PROCEDURE (str: String) LastIndexOf* (char: CHAR; endpos: LONGINT): LONGINT;
(**Returns the index of the last occurence of @oparam{char} before
   position @oparam{endpos}.  If no such character exists, result is @code{-1}.

   @precond
   @samp{0 <= endpos <= str.length}
   @end precond  *)
  BEGIN
    DEC (endpos);
    WHILE (endpos # -1) & (str. array[endpos] # char) DO
      DEC (endpos)
    END;
    RETURN endpos
  END LastIndexOf;

PROCEDURE (str : String) Compare* (source : String) : SHORTINT;
(** Return -1, 0, or 1 according to whether string @oparam{str} is lexically
 * `less than', `equal', or `greater than' string @oparam{source}. Note that
 * the value of comparing the result with zero will be the same as if the
 * comparison operator were applied between the two strings. That is, 
 *   str.Compare(source) <OP> 0
 * is equivalent to
 *   str <OP> source
 * where <OP> is any integer relational operator (eg. =, #, <, <=, >, >=) *)

VAR result : SHORTINT;
BEGIN
  IF str.length > source.length THEN
    result := CompareRegion(str.array^, 0, source.length, source.array^, 0);
    IF result = 0 THEN RETURN 1 ELSE RETURN result END;
  ELSIF str.length < source.length THEN
    result := CompareRegion(str.array^, 0, str.length, source.array^, 0);
    IF result = 0 THEN RETURN -1 ELSE RETURN result END;
  ELSE
    RETURN CompareRegion(str.array^, 0, str.length, source.array^, 0);
  END;
END Compare;

PROCEDURE (str : String) CompareRegionArray* (pos, endPos : LONGINT; source[NO_COPY] : ARRAY OF CHAR; srcPos : LONGINT) : SHORTINT;
(**Compare @samp{endPos-pos} characters starting at position @oparam{pos} in *
   string @oparam{str} with characters in array @oparam{source} starting at *
   position @oparam{srcPos}. See @oproc{String.Compare} for description of the
   result.  *)

BEGIN
  RETURN CompareRegion(str.array^, pos, endPos, source, srcPos);
END CompareRegionArray;

PROCEDURE (str : String) CompareRegion* (pos, endPos : LONGINT; source : String; srcPos : LONGINT) : SHORTINT;
(**Compare @samp{endPos-pos} characters starting at position @oparam{pos} in *
   string @oparam{str} with characters in string @oparam{source} starting at *
   position @oparam{srcPos}. See @oproc{String.Compare} for description of the
   result.  *)

BEGIN
  RETURN CompareRegion(str.array^, pos, endPos, source.array^, srcPos);
END CompareRegion;

PROCEDURE (str : String) FindFirst* (pattern : String; startPos: LONGINT) : LONGINT;
(** Looks forward for first occurrence of @oparam{pattern} in @oparam{str},
 * starting the search at position @oparam{startPos}. If found, the function
 * returns the start position in @oparam{str} of @oparam{pattern}. If not
 * found, the function returns -1. *)

  VAR
    patternPos: LONGINT;
  BEGIN
    IF startPos < str.length THEN
      patternPos := 0;
      LOOP
        IF (patternPos = pattern.length) THEN     
          (* reached end of pattern *)
          RETURN startPos-patternPos;
        ELSIF (startPos = str.length) THEN 
          (* end of string (but not of pattern) *)
          RETURN -1;
        ELSIF (str.array^[startPos] = pattern.array^[patternPos]) THEN  
          (* characters identic, compare next one *)
          INC (startPos); 
          INC (patternPos)
        ELSE                               
          (* difference found: reset indices and restart *)
          startPos := startPos-patternPos+1; 
          patternPos := 0
        END
      END
    ELSE
      RETURN -1
    END
  END FindFirst;
 
PROCEDURE (str : String) FindLast* (pattern : String; startPos: LONGINT) : LONGINT;
(** Looks backward for the last occurrence of @oparam{pattern} in @oparam{str},
 * starting the search at position @oparam{startPos}.  If found, the function
 * returns the start position in @oparam{str} of @oparam{pattern}. If not
 * found, the function returns -1. *)

  VAR
    patternPos, limit : LONGINT;
  BEGIN
    (* correct `startPos' if it is larger than the possible searching range *)
    limit := str.length - pattern.length;
    IF startPos > limit THEN
      startPos := limit;
    END;
    
    IF (startPos >= 0) THEN
      patternPos := 0;
      LOOP
        IF (patternPos = pattern.length) THEN     
          (* reached end of pattern *)
          RETURN startPos-patternPos;
        ELSIF (str.array^[startPos] # pattern.array^[patternPos]) THEN
          (* characters differ: reset indices and restart *)
          IF (startPos > patternPos) THEN
            startPos := startPos-patternPos-1;
            patternPos := 0
          ELSE
            (* reached beginning of `stringToSearch' without finding a match *)
            RETURN -1;
          END
        ELSE  (* characters identic, compare next one *)
          INC (startPos); 
          INC (patternPos)
        END
      END
    ELSE
      RETURN -1
    END
  END FindLast;

PROCEDURE (str : String) StartsWith* (prefix : String) : BOOLEAN;
(** Return TRUE IFF string @oparam{str} starts with the characters in string
 * @oparam{prefix}. *)

BEGIN
  IF prefix.length > str.length THEN
    RETURN FALSE;
  ELSE
    RETURN str.CompareRegion(0, prefix.length, prefix, 0) = 0
  END;
END StartsWith;

PROCEDURE (str : String) EndsWith* (suffix : String) : BOOLEAN;
(** Return TRUE IFF string @oparam{str} ends with the characters in string
 * @oparam{suffix}. *)

BEGIN
  IF suffix.length > str.length THEN 
    RETURN FALSE;
  ELSE
    RETURN 
      str.CompareRegion(str.length-suffix.length, str.length, suffix, 0) = 0
  END;
END EndsWith;

PROCEDURE ToUpper * (c : CHAR) : CHAR;
(** This @otype{MapCharProc} converts ASCII characters to upper case. It may be
 * passed as a parameter to Map in order to convert a string to upper case. *)

BEGIN
  RETURN CAP(c);
END ToUpper;

PROCEDURE ToLower * (c : CHAR) : CHAR;
(** This @otype{MapCharProc} converts ASCII characters to lower case. It may be
 * passed as a parameter to Map in order to convert a string to lower case. *)

BEGIN
  IF (c >= 'A') & (c <= 'Z') THEN
    RETURN CHR(ORD('a')+ORD(c)-ORD('A'));
  ELSE
    RETURN c;
  END;
END ToLower;

PROCEDURE (str : String) HashCode* (): LONGINT;
  VAR
    len, x, p: LONGINT;
  BEGIN
    (* this is intended as a reimplementation of the Python hash code on
       strings; any errors are mine, of course *)
    len := str. length;
    x := ASH (LONG (ORD (str. array[0])), 7);
    p := 0;
    WHILE (p # len) DO
      <* PUSH; OverflowCheck := FALSE *>
      x := S.VAL (LONGINT, S.VAL (SET, 1000003*x) /
                           S.VAL (SET, LONG (ORD (str. array[p]))));
      <* POP *>
      INC (p)
    END;
    x := S.VAL (LONGINT, S.VAL (SET, x) / S.VAL (SET, len));
    RETURN x
  END HashCode;

PROCEDURE (str : String) Equals* (y: Language.Object): BOOLEAN;
(**Determines if the receiver and the parameter are equal strings.  That is, it
   returns @code{TRUE} if, and only if, @oparam{y} is an instance of
   @otype{String} with the same length and content as @oparam{str}.  *)
  VAR
    i: LONGINT;
  BEGIN
    IF (y = NIL) OR ~(y IS String) OR (str. length # y(String). length) THEN
      RETURN FALSE
    ELSE
      FOR i := 0 TO str. length-1 DO
        IF (str. array[i] # y(String). array[i]) THEN
          RETURN FALSE
        END
      END;
      RETURN TRUE
    END
  END Equals;

PROCEDURE (str: String) Load* (r: Object.Reader);
  VAR length : LONGINT;
  BEGIN
    str. Load^ (r);
    r. ReadNum (length);
    InitString(str, length);
    r. ReadBytes (str. array^, 0, str. length * SIZE(CHAR));
    str. array[str. length] := 0X;
  END Load;

PROCEDURE (str: String) Store* (w: Object.Writer);
  BEGIN
    str. Store^ (w);
    w. WriteNum (str. length);
    w. WriteBytes (str. array^, 0, str. length * SIZE(CHAR))
  END Store;

END ADT:String.

