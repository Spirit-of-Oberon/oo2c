(*	$Id$	*)
MODULE ADT:StringBuffer [OOC_EXTENSIONS];
(*  String data type of dynamic length.
    Copyright (C) 1998-2001  Michael van Acken

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
  S := SYSTEM, RT0, ADT:Object, ADT:String, IntStr, RealStr;

TYPE
  StringBuffer* = POINTER TO StringBufferDesc;
  StringBufferDesc* = RECORD
  (**This type is an abstraction around the often used data type @code{POINTER
     TO ARRAY OF CHAR}.  It is mutable in the sense that it can be modified in
     place.  All variables sharing a reference to an instance of
     @otype{StringBuffer} see all changes applied to it.  In this it differs
     from the @samp{string} type in Python, or @samp{String} in Java, that are
     immutable and cannot be changed once created.

     The methods of @otype{StringBuffer} resemble the procedures of module
     @omodule{*Strings}.  Some changes were necessary, though: A string
     @samp{OUT} parameter was turned into a function result, and an
     @samp{IN/OUT} parameter was turned into the receiver.  As an alternative
     to @oproc{*Strings.Assign}, @oproc{StringBuffer.Copy} is available; it
     returns a newly created string with the same content.

     The character @code{0X} can be stored in instances of
     @otype{StringBuffer}.  The user should be aware that in this case any
     operations that require @code{0X} as the termination character cannot be
     applied to the string instance.  *)
    (Object.ObjectDesc)
    length-: LONGINT;
    (**The length of the string.  *)
    array-: String.CharArrayPtr;
    (**The content of the string.  @samp{@ofield{array}[@ofield{length}]} is
       always @code{0X}.

       Both read and write access to @samp{@ofield{array}^} is permitted, as
       long as no characters past index @ofield{length} are read or modified.
       Instances of strings can include the character @code{0X} at positions
       before @ofield{length}.  *)
  END;

CONST
  minimumSize = 16;
  rtOverhead = 16;


PROCEDURE ArraySize (len: LONGINT): LONGINT;
(* Note: `len' does not include the terminating @code{0X}.  *)
  VAR
    size: LONGINT;
  BEGIN
    (* assume that the run-time information (type tag, length, etc.) of an open
       array is `rtOverhead' bytes or less *)
    INC (len, rtOverhead+1);
    size := minimumSize;
    WHILE (size < len) DO
      size := size*2
    END;
    RETURN size - rtOverhead
  END ArraySize;

PROCEDURE Extend (str: StringBuffer; len: LONGINT; copyOver: BOOLEAN);
(* Ajust array size of `str', so that a string of length `len' (plus the
   terminating 0X) can be stored in `str'.  If `len' is much smaller than
   the current size of `str', then `str' is shrunk.  *)
  VAR
    newSize: LONGINT;
    new: String.CharArrayPtr;
  BEGIN
    IF (len >= LEN (str. array^)) OR 
       ((LEN (str. array^) > minimumSize) &
        (len <= LEN (str. array^) DIV 3)) THEN
      newSize := ArraySize (len);

      IF (newSize # LEN (str. array^)) THEN
        NEW (new, newSize);
        IF copyOver THEN
          S.MOVE (S.ADR (str. array^), S. ADR (new^), str. length);
        END;
        str. array := new
      END
    END
  END Extend;

PROCEDURE NewLength (len: LONGINT): StringBuffer;
  VAR
    str: StringBuffer;
  BEGIN
    NEW (str);
    Object.Init (str);
    NEW (str. array, ArraySize (len));
    str. array[0] := 0X;
    str. length := 0;
    RETURN str
  END NewLength;


PROCEDURE Init* (str: StringBuffer; value[NO_COPY]: ARRAY OF CHAR);
(**Initializes string @oparam{str} to the contents of @oparam{value},
   interpreted as a string value.  *)
  VAR
    len: LONGINT;
  BEGIN
    Object.Init (str);
    len := 0;
    WHILE value[len] # 0X DO INC(len) END;
    NEW (str. array, ArraySize (len));
    COPY (value, str. array^);
    str. length := len
  END Init;

PROCEDURE New* (value[NO_COPY]: ARRAY OF CHAR): StringBuffer;
(**Creates a new instance of @otype{StringBuffer} from the contents of
   @oparam{value}.  The length of the new string equals
   @samp{@oproc{*Strings.Length}(@oparam{value})}.  *)
  VAR
    str: StringBuffer;
  BEGIN
    NEW (str);
    Init (str, value);
    RETURN str
  END New;

PROCEDURE (str: StringBuffer) Destroy*;
  BEGIN
    str. Destroy ();
    str. length := 0;
    str. array := NIL
  END Destroy;


PROCEDURE (str: StringBuffer) Size* (): LONGINT;
(**Returns the length of the string.  *)
  BEGIN
    RETURN str. length
  END Size;

PROCEDURE (str: StringBuffer) IsEmpty* (): BOOLEAN;
(**Returns @code{TRUE} if, and only if, the string instance holds no
   characters.  *)
  BEGIN
    RETURN (str. length = 0)
  END IsEmpty;

PROCEDURE (x: StringBuffer) Equals* (y: Object.Object): BOOLEAN;
(**Determines if the receiver and the parameter are equal strings.  That is, it
   returns @code{TRUE} if, and only if, @oparam{y} is an instance of
   @otype{StringBuffer} with the same length and content as @oparam{x}.  *)
  VAR
    i: LONGINT;
  BEGIN
    IF (y = NIL) OR ~(y IS StringBuffer) OR (x. length # y(StringBuffer). length) THEN
      RETURN FALSE
    ELSE
      FOR i := 0 TO x. length-1 DO
        IF (x. array[i] # y(StringBuffer). array[i]) THEN
          RETURN FALSE
        END
      END;
      RETURN TRUE
    END
  END Equals;
  
PROCEDURE (str: StringBuffer) HashCode* (): LONGINT;
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
                           S.VAL (SET, LONG( ORD (str. array[p]))));
      <* POP *>
      INC (p)
    END;
    x := S.VAL (LONGINT, S.VAL (SET, x) / S.VAL (SET, len));
    RETURN x
  END HashCode;
  
PROCEDURE (str: StringBuffer) Copy*(): StringBuffer;
(**Creates a new string, using the contents of @oparam{str}.  *)
  VAR
    i: LONGINT;
    dest: StringBuffer;
  BEGIN
    dest := NewLength (str. length);
    FOR i := 0 TO str. length DO
      dest. array[i] := str. array[i]
    END;
    dest. length := str. length;
    RETURN dest
  END Copy;

PROCEDURE (str: StringBuffer) Extract* (startPos, numberToExtract: LONGINT): StringBuffer;
(**Copies at most @oparam{numberToExtract} characters from @oparam{str} to a
   string instance, starting at position @oparam{startPos} in @oparam{str}.
   An empty string value will be extracted if @oparam{startPos} is greater than
   or equal to @samp{Length(str)}.

   @precond
   @oparam{startPos} and @oparam{numberToExtract} are not negative.
   @end precond  *)
  VAR
    i: LONGINT;
    dest: StringBuffer;
  BEGIN
    dest := NewLength (numberToExtract);
    IF (startPos < str. length) THEN
      i := 0;
      WHILE (i < numberToExtract) & (startPos+i # str. length) DO
        dest. array[i] := str. array[startPos+i];
        INC (i)
      END;
      dest. array[i] := 0X;
      dest. length := i
    END;
    RETURN dest
  END Extract;

PROCEDURE (str: StringBuffer) Delete* (startPos, numberToDelete: LONGINT);
(**Deletes at most @oparam{numberToDelete} characters from @oparam{str},
   starting at position @oparam{startPos}.  The string value in
   @oparam{str} is not altered if @oparam{startPos} is greater than or
   equal to @samp{Length(str)}.

   @precond
   @oparam{startPos} and @oparam{numberToDelete} are not negative.
   @end precond  *)
  VAR
    i: LONGINT;
  BEGIN
    IF (startPos+numberToDelete < str. length) THEN
      (* `str. array' has remaining characters beyond the deleted section;
         these have to be moved forward by `numberToDelete' characters *)
      FOR i := startPos TO str. length-numberToDelete DO
        str. array[i] := str. array[i+numberToDelete]
      END;
      DEC (str. length, numberToDelete)
    ELSIF (startPos < str. length) THEN
      str. array[startPos] := 0X;
      str. length := startPos
    END;
    Extend (str, str. length, TRUE)  (* shrink array? *)
  END Delete;
 
PROCEDURE (str: StringBuffer) Insert* (source: StringBuffer; startPos: LONGINT);
(**Inserts @oparam{source} into @oparam{str} at position @oparam{startPos}.
   After the call @oparam{str} contains the string that is contructed by first
   splitting @oparam{str} at the position @oparam{startPos} and then
   concatenating the first half, @oparam{source}, and the second half.  The
   string value in @oparam{str} is not altered if @oparam{startPos} is greater
   than @samp{Length(source)}.  If @samp{startPos = Length(source)}, then
   @oparam{source} is appended to @oparam{str}.

   @precond
   @oparam{startPos} is not negative.
   @end precond  *)
  VAR
    i: LONGINT;
  BEGIN
    IF (startPos <= str. length) THEN
      Extend (str, str. length+source. length, TRUE);
      (* `source' is inserted inside of `destination'; move tail section of 
         `str' *)
      FOR i := str. length TO startPos BY -1 DO
        str. array[i+source. length] := str. array[i]
      END;
      (* copy characters from `source' to `str' *)
      FOR i := 0 TO source. length-1 DO
        str. array[startPos+i] := source. array[i]
      END;
      INC (str. length, source. length)
    END
  END Insert;
  
PROCEDURE (str: StringBuffer) Replace* (source: StringBuffer; startPos: LONGINT);
(**Copies @oparam{source} into @oparam{str}, starting at position
   @oparam{startPos}.  Copying stops when all of @oparam{source} has been
   copied, or when the last character of the string value in @oparam{str} has
   been replaced.  The string value in @oparam{str} is not altered if
   @oparam{startPos} is greater than or equal to
   @samp{Length(@oparam{source})}.

   @precond
   @oparam{startPos} is not negative.
   @end precond  *)
  VAR
    i: LONGINT;
  BEGIN
    IF (startPos < str. length) THEN
      (* if `startPos' is inside `str', then replace characters until
         the end of `source' or `str' is reached *)
      i := 0;
      WHILE (startPos # str. length) & (i # source. length) DO
        str. array[startPos] := source. array[i];
        INC (startPos);
        INC (i)
      END
    END
  END Replace;
 
PROCEDURE (str: StringBuffer) Append* (source: String.String);
(**Appends @oparam{source} to @oparam{str}. *)

  BEGIN
    Extend (str, str. length+source. length, TRUE);
    source.GetCharsRegion(0, source.length, str.array^, str.length);
    INC (str. length, source. length)
  END Append;

PROCEDURE (str: StringBuffer) Concat* (source2: StringBuffer): StringBuffer;
(**Concatenates @oparam{source2} onto @oparam{str} and copies the result into a
   new string instance.  *)
  VAR
    i, j: LONGINT;
    dest: StringBuffer;
  BEGIN
    dest := NewLength (str. length+source2. length);
    FOR i := 0 TO str. length DO
      dest. array[i] := str. array[i]
    END;
    j := str. length;
    FOR i := 0 TO source2. length DO
      dest. array[i+j] := source2. array[i]
    END;
    dest. length := str. length+source2. length;
    RETURN dest
  END Concat;


PROCEDURE (str: StringBuffer) AppendChar* (ch: CHAR);
(**Appends the character @oparam{ch} to the string @oparam{str}.  @oparam{ch}
   may be @code{0X}.  *)
  BEGIN
    Extend (str, str. length+1, TRUE);
    str. array[str.length] := ch;
    str. array[str.length+1] := 0X;
    INC (str. length)
  END AppendChar;

PROCEDURE (str: StringBuffer) AppendString* (stringValue[NO_COPY]: ARRAY OF CHAR);
(**Appends the string value in @oparam{stringValue} to the string @oparam{str}.
   Afterwards, the length of @oparam{str} has increased by
   @samp{@oproc{*Strings.Length}(@oparam{stringValue})} characters.  *)
  VAR
    clen, i: LONGINT;
  BEGIN
    clen := 0;
    WHILE (stringValue[clen] # 0X) DO
      INC (clen)
    END;
    Extend (str, str. length+clen, TRUE);
    FOR i := 0 TO clen DO
      str. array[str. length+i] := stringValue[i]
    END;
    INC (str. length, clen)
  END AppendString;

PROCEDURE (str: StringBuffer) AppendRegion* (chars[NO_COPY]: ARRAY OF CHAR; pos, endPos: LONGINT);
(**Appends the characters in @samp{@oparam{chars}[@oparam{pos},
   @oparam{endPos}-1]} to the string @oparam{str}.  The character
   interval may include @code{0X}.  Afterwards, the length of @oparam{str}
   has increased by @samp{endPos-pos} characters.  *)
  VAR
    len: LONGINT;
  BEGIN
    len := endPos-pos;
    Extend (str, str. length+len, TRUE);
    ASSERT (str.length+len < LEN (str. array^));
    S.MOVE (S.ADR (chars[pos]), S.ADR (str. array[str. length]), len);
    INC (str. length, len);
    str. array[str. length] := 0X
  END AppendRegion;

PROCEDURE (str : StringBuffer) AppendLongInt* (val : LONGINT);
(**Append the string representation of @code{LONGINT} @oparam{val} to the
   current string *)
VAR a : ARRAY 32 OF CHAR;
BEGIN
  IntStr.IntToStr(val, a);
  str.AppendString(a);
END AppendLongInt;

PROCEDURE (str : StringBuffer) AppendReal* (val : REAL);
(**Append the string representation of @code{REAL} @oparam{val} to the
   current string *)
VAR a : ARRAY 32 OF CHAR;
BEGIN
  RealStr.RealToStr(val, a);
  str.AppendString(a);
END AppendReal;

PROCEDURE (str : StringBuffer) AppendSet* (val : SET);
(**Append the string representation of a @code{SET} @oparam{val} to the
   currrent string. *)
VAR
 begin, i : SHORTINT; comma : BOOLEAN;
BEGIN
  str.AppendChar("{");
  comma := FALSE;
  i := MIN(SET);
  WHILE i <= MAX(SET) DO
    IF i IN val THEN
      begin := i;
      WHILE (i < MAX(SET)) & ((i+1) IN val) DO INC(i) END;
      IF comma THEN 
        str.AppendChar(",")
      END;
      comma := TRUE;
      str.AppendLongInt(begin);
      IF begin < i THEN
        IF i = begin + 1 THEN
          str.AppendChar(",");
        ELSE
          str.AppendString("..");
        END;
        str.AppendLongInt(i);
      END;
    END;
    INC(i)
  END; 
  str.AppendChar("}");
END AppendSet;

PROCEDURE (str : StringBuffer) AppendBool* (val : BOOLEAN);
(**Append the string representation of a @code{BOOLEAN} @oparam{val} to the
   current string. *)
BEGIN
  IF val THEN
    str.AppendString("TRUE")
  ELSE
    str.AppendString("FALSE")
  END
END AppendBool;

PROCEDURE (str : StringBuffer) AppendObject* (object : Object.Object);
(**Append the string representation of an @otype{Object.Object} to the current
   string. This procedure uses @oproc{Object.Object.ToString} to obtain a
   textual description of the object. If @oproc{Object.Object.ToString} does
   not return a @otype{String.String} (eg. the base method has not been
   overridden), a canonical description will be generated using the type name
   and address.  *)
VAR 
  res : Object.String;
  type : RT0.Struct;
  name: ARRAY 256 OF CHAR;
BEGIN
  IF object = NIL THEN
    str.AppendString("NIL");
  ELSE
    res := object.ToString();
    IF (res # NIL) & (res IS String.String) THEN
      str.Append(res(String.String));
    ELSE
      type := RT0.TypeOf(object);
      str.AppendChar("[");
      COPY (type.module.name^, name);
      str.AppendString(name);
      str.AppendChar(".");
      COPY (type.name^, name);
      str.AppendString(name);
      str.AppendChar("@");
<*IF TARGET_ADDRESS = 64 THEN*>
      str.AppendString("???");
<*ELSE*>
      str.AppendLongInt(S.VAL(LONGINT, object));
<*END*>
      str.AppendChar("]");
    END
  END;
END AppendObject;
 
PROCEDURE (str : StringBuffer) ToString* () : String.String;
(**Return an immutable @otype{StringBuffer} representing the current string. *)
BEGIN
  RETURN String.NewRegion(str.array^, 0, str.length);
END ToString;

PROCEDURE (str: StringBuffer) Load* (r: Object.Reader);
  BEGIN
    str. Load^ (r);
    r. ReadNum (str. length);
    NEW (str. array, ArraySize (str. length));
    r. ReadBytes (str. array^, 0, str. length * SIZE(CHAR));
    str. array[str. length] := 0X;
  END Load;

PROCEDURE (str: StringBuffer) Store* (w: Object.Writer);
  BEGIN
    str. Store^ (w);
    w. WriteNum (str. length);
    w. WriteBytes (str. array^, 0, str. length * SIZE(CHAR))
  END Store;

END ADT:StringBuffer.
