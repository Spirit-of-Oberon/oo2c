(* 	$Id$	 *)
MODULE OS:Path;
(*  Manipulation of file and directory names.
    Copyright (C) 2000, 2001  Michael van Acken

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
  Strings;


PROCEDURE dirname* (path: ARRAY OF CHAR; VAR dirname: ARRAY OF CHAR);
(**Calculates the directory name of pathname @oparam{path} and returns the
   result in @oparam{dirname}.  If @oparam{dirname} is not long enough to hold
   the result, the string is truncated. *)
  VAR
    i, j: INTEGER;
    len: LONGINT;
  BEGIN
    len := LEN (dirname);
    
    (* copy anything in path up to and including the final "/" to dirname *)
    i := Strings.Length (path);
    WHILE (i > 0) & (path[i-1] # "/") DO
      DEC (i)
    END;
    FOR j := 0 TO i-1 DO
      IF (j < len) THEN
        dirname[j] := path[j]
      END
    END;
    IF (i >= len) THEN
      i := SHORT (len-1)
    END;
    dirname[i] := 0X;
    
    (* if dirname is not composed exclusively of slashes, remove any
       trailing "/" characters *)
    i := -1;
    j := 0;
    WHILE (dirname[j] # 0X) DO
      IF (dirname[j] # "/") THEN
        i := j
      END;
      INC (j)
    END;
    IF (i >= 0) THEN
      dirname[i+1] := 0X
    END
  END dirname;

PROCEDURE basename* (path: ARRAY OF CHAR; VAR basename: ARRAY OF CHAR);
(**Calculates the basename of pathname @oparam{path} and returns the result in
   @oparam{basename}.  The basename is the last pathname component of path.  It
   will never contain a slash.  If path ends with a slash, then the basename is
   the empty string.  If path does not contain a slash, then the basename
   equals path.  If @oparam{basename} is not long enough to hold the result,
   the string is truncated.  *)
  VAR
    i: INTEGER;
  BEGIN
    i := Strings.Length (path);
    WHILE (i > 0) & (path[i-1] # "/") DO
      DEC (i)
    END;
    Strings.Extract (path, i, MAX (INTEGER), basename)
  END basename;

PROCEDURE splitext* (path: ARRAY OF CHAR; VAR root, ext: ARRAY OF CHAR);
(**Splits the pathname @oparam{path} into a pair @samp{(@oparam{root},
   @oparam{ext})} such that @samp{concat(@oparam{root},@oparam{ext}) =
   @oparam{path}}.  The extension @oparam{ext} is empty or begins with a period
   and contains at most one period.  The extension string does not contain a
   slash character.  *)
  VAR
    i: INTEGER;
  BEGIN
    i := Strings.Length (path);
    WHILE (i > 0) & (path[i-1] # "/") & (path[i] # ".") DO
      DEC (i)
    END;
    IF (path[i] = ".") THEN
      Strings.Extract (path, 0, i, root);
      Strings.Extract (path, i, MAX (INTEGER), ext)
    ELSE
      COPY (path, root);
      COPY ("", ext)
    END
  END splitext;

END OS:Path.
