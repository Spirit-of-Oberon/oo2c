(* 	$Id: Path.Mod,v 1.5 2004/11/24 03:53:09 sgreenhill Exp $	 *)
MODULE OS:Path;
(*  Manipulation of file and directory names.
    Copyright (C) 2000, 2001, 2003  Michael van Acken

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
  Object, ADT:StringBuffer;

CONST
  sep = "/";
  
PROCEDURE DirName*(path: STRING): STRING;
(**Calculates the directory name of pathname @oparam{path}.  *)
  VAR
    i, j: LONGINT;
  BEGIN
    i := path.LastIndexOf(sep, path.length);
    IF (i >= 0) THEN
      (* if dirname is not composed exclusively of slashes, remove any
         trailing "/" characters *)
      j := i;
      WHILE (j > 0) & (path.CharAt(j-1) = sep) DO
        DEC(j);
      END;
      IF (j = 0) THEN     (* include path separator at position `i' *)
        INC(i);
      ELSE                       (* discard all trailing separators *)
        i := j;
      END;
      RETURN path.Substring(0, i);
    ELSE                      (* plain file name, no directory part *)
      RETURN "";
    END;
  END DirName;

PROCEDURE BaseName* (path: STRING): STRING;
(**Calculates the basename of pathname @oparam{path}.  The basename is the last
   pathname component of @oparam{path}.  It never contains a slash.  If
   @oparam{path} ends with a slash, then the basename is the empty string.  If
   path does not contain a slash, then the basename equals path.  *)
  VAR
    i: LONGINT;
  BEGIN
    i := path.LastIndexOf(sep, path.length);
    IF (i >= 0) THEN
      RETURN path.Substring(i+1, path.length);
    ELSE
      RETURN path;
    END;
  END BaseName;

PROCEDURE SplitExt* (path: STRING; VAR root, ext: STRING);
(**Splits the pathname @oparam{path} into a pair @samp{(@oparam{root},
   @oparam{ext})} such that @samp{concat(@oparam{root},@oparam{ext}) =
   @oparam{path}}.  The extension @oparam{ext} is empty or begins with a period
   and contains at most one period.  The extension string does not contain a
   slash character.  *)
  VAR
    i: LONGINT;
  BEGIN
    i := path.LastIndexOf(".", path.length);
    IF (i >= 0) & (path.IndexOf(sep, i) < 0) THEN
      root := path.Substring(0, i);
      ext := path.Substring(i, path.length);
    ELSE
      root := path;
      ext := "";
    END;
  END SplitExt;


PROCEDURE Encode*(path: STRING): Object.CharsLatin1;
(**Encode the file path or command @oparam{path} as a system-specific sequence
   of bytes.

   The default implementation returns a string with all character codes above
   @samp{0FFX} replaced with the character @samp{_}.  That is, non ISO Latin1
   characters are discarded.  For instances of @otype{Object.String8}, it is
   the identity operation.  *)
  VAR
    path8: Object.String8;
  BEGIN
    path8 := path.ToString8("_");
    RETURN path8.CharsLatin1();
  END Encode;

PROCEDURE Decode*(path[NO_COPY]: ARRAY OF CHAR): STRING;
(**Convert a system-specific sequence of bytes @oparam{path} representing a
   file path into a string instance.  This is the inverse of @oproc{Encode}.  *)
  BEGIN
    RETURN Object.NewLatin1(path);
  END Decode;

PROCEDURE QuoteForShell* (path : STRING) : STRING;
(**Convert a path to a form suitable for passing as a command-line argument to
   a system command. Certain characters cannot be directly used in command-line
   path arguments because the characters have special significance to the
   system shell. For example, spaces are used to separate arguments in command
   lines, so a path containing spaces must be quoted to cause the shell to
   treat it as a literal.
   
   This function determines if @oparam{path} needs to be quoted. If so, it
   returns a quoted version. Otherwise, the original @oparam{path} is returned.
   *)

 CONST
    escapeChar = "\";
    quoteChars = escapeChar + '"';

  PROCEDURE EscapeReservedChars(s, reserved : STRING; escape : CHAR) : STRING;
  VAR
    i : LONGINT;
    sb : StringBuffer.StringBuffer;
    c : UCS4CHAR;
    needQuote : BOOLEAN;
  BEGIN
    needQuote := FALSE;
    sb := StringBuffer.New('"');
    FOR i := 0 TO s.length - 1 DO
      c := s.CharAt(i);
      IF reserved.IndexOf(c, 0) >= 0 THEN
        sb.AppendLatin1Char(escape);
        needQuote := TRUE;
      ELSIF c = ' ' THEN
        needQuote := TRUE;
      END;
      sb.AppendChar(c);
    END;
    sb.AppendChar('"');
    IF needQuote THEN
      RETURN sb.ToString();
    ELSE
      RETURN s;
    END;
  END EscapeReservedChars;

  BEGIN
    RETURN EscapeReservedChars(path, quoteChars, escapeChar);
  END QuoteForShell;

END OS:Path.
