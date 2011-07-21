(*	$Id: SubstringBM.Mod,v 1.2 2002/12/17 19:33:40 mva Exp $	*)
MODULE StringSearch:SubstringBM [OOC_EXTENSIONS];
(*  Boyer-Moore substring seach.
    Copyright (C) 2001  Michael van Acken

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
  Object, StringSearch, StringSearch:SubstringBF, StringSearch:RegexpParser;

CONST
  ignoreCase* = StringSearch.ignoreCase;
  (**See @oconst{StringSearch.ignoreCase}.  *)
  copyString* = StringSearch.copyString;
  (**See @oconst{StringSearch.copyString}.  *)

TYPE
  Factory* = POINTER TO FactoryDesc;
  FactoryDesc* = RECORD
    (**This class implements the Boyer-Moore string searching algorithm.  With
       a pattern length of @var{M} and a string length of @var{N}, a search
       operation never requires more than @var{M}+@var{N} character
       comparisons, and about @var{N}/@var{M} steps if the alphabet is not
       small and the pattern is not long.  *)
    (StringSearch.FactoryDesc)
  END;

CONST
  sizeChar = ORD(MAX(CHAR))+1;
  
TYPE
  Matcher* = POINTER TO MatcherDesc;
  MatcherDesc* = RECORD
    (SubstringBF.MatcherDesc)
    skip: ARRAY sizeChar OF LONGINT;
    shift: POINTER TO ARRAY OF LONGINT;
  END;

TYPE
  MatchObject* = POINTER TO MatchObjectDesc;
  MatchObjectDesc = RECORD
    (SubstringBF.MatchObjectDesc)
  END;

VAR
  factory-: Factory;



PROCEDURE InitMatchObject (m: MatchObject; pos, endpos: LONGINT;
                           matcher: Matcher; string: Object.String8;
                           start, end: LONGINT);
  BEGIN
    SubstringBF.InitMatchObject (m, pos, endpos, matcher, string, start, end);
  END InitMatchObject;

PROCEDURE NewMatchObject (pos, endpos: LONGINT;
                          matcher: Matcher; string: Object.String8;
                          start, end: LONGINT): MatchObject;
  VAR
    m: MatchObject;
  BEGIN
    NEW (m);
    InitMatchObject (m, pos, endpos, matcher, string, start, end);
    RETURN m
  END NewMatchObject;

(* inherited from SubstringBF:
PROCEDURE (m: MatchObject) Start* (group: LONGINT): LONGINT;
PROCEDURE (m: MatchObject) End* (group: LONGINT): LONGINT;
*)


PROCEDURE InitMatcher (matcher: Matcher; pattern: Object.String8; flags: StringSearch.Flags; groups: LONGINT);
  VAR
    i, j, m, m1, maxGap: LONGINT;
    a, b: CHAR;
    len: POINTER TO ARRAY OF LONGINT;
    array: Object.CharsLatin1;
  BEGIN
    SubstringBF.InitMatcher (matcher, pattern, flags, groups);
    
    (* init skip *)
    m := pattern. length; m1 := m-1;
    FOR i := 0 TO sizeChar-1 DO
      matcher. skip[i] := m
    END;
    array := pattern.CharsLatin1();
    IF (StringSearch.ignoreCase IN flags) THEN
      FOR i := 0 TO m1 DO
        RegexpParser.UpperLower (array[i], a, b);
        matcher. skip[ORD (a)] := m1-i;
        matcher. skip[ORD (b)] := m1-i
      END
    ELSE
      FOR i := 0 TO m1 DO
        matcher. skip[ORD (array[i])] := m1-i
      END
    END;
    
    (* init shift *)
    NEW (matcher. shift, m+1);
    NEW (len, m);
    
    FOR i := 1 TO m1 DO
      j := 0;
      IF (StringSearch.ignoreCase IN flags) THEN
        WHILE (j < m) & (m1-i-j >= 0) &
              (CAP (array[m1-j]) = CAP (array[m1-i-j])) DO
          INC (j)
        END
      ELSE
        WHILE (j < m) & (m1-i-j >= 0) &
              (array[m1-j] = array[m1-i-j]) DO
          INC (j)
        END
      END;
      len[i] := j
    END;
    
    FOR i := 1 TO m1 DO
      matcher. shift[i] := 0
    END;
    FOR i := m1 TO 1 BY -1 DO
      matcher. shift[len[i]] := i
    END;
    matcher. shift[0] := 1;
    
    maxGap := m;
    FOR i := 1 TO m1 DO
      IF (matcher. shift[i] = 0) THEN
        matcher. shift[i] := maxGap
      END;
      IF (matcher. shift[i]+i = m) THEN
        maxGap := matcher. shift[i]
      END
    END
  END InitMatcher;

PROCEDURE NewMatcher (pattern: Object.String8; flags: StringSearch.Flags; groups: LONGINT): Matcher;
  VAR
    matcher: Matcher;
  BEGIN
    NEW (matcher);
    InitMatcher (matcher, pattern, flags, 0);
    RETURN matcher
  END NewMatcher;

(* procedures inherited from SubstringBF:
PROCEDURE (matcher: Matcher) MatchChars* (string[NO_COPY]: ARRAY OF CHAR; pos, endpos: LONGINT): MatchObject;
PROCEDURE (matcher: Matcher) Match* (string: Object.String8; pos, endpos: LONGINT): MatchObject;
*)

PROCEDURE SearchStart* (matcher: Matcher;
                        string[NO_COPY]: ARRAY OF CHAR;
                        pos, endpos: LONGINT): LONGINT;
(**PRIVATE.  Used by module RegexpDFA.  *)
  VAR
    i, rightEnd, sh, sk, m1: LONGINT;
    p: Object.String8;
    array: Object.CharsLatin1;
  BEGIN
    p := matcher. pattern;
    m1 := p.length-1;

    array := p.CharsLatin1();
    rightEnd := pos+m1;
    IF (ignoreCase IN matcher. flags) THEN
      WHILE (rightEnd < endpos) DO
        i := 0;
        WHILE (i <= m1) & (CAP (string[rightEnd-i]) = CAP (array[m1-i])) DO
          INC (i)
        END;

        IF (i > m1) THEN
          RETURN rightEnd-m1
        ELSE
          sk := matcher. skip[ORD (string[rightEnd-i])];
          sh := matcher. shift[i];
          IF (sk-i > sh) THEN
            INC (rightEnd, sk-i)
          ELSE
            INC (rightEnd, sh)
          END
        END
      END
    ELSE
      WHILE (rightEnd < endpos) DO
        i := 0;
        WHILE (i <= m1) & (string[rightEnd-i] = array[m1-i]) DO
          INC (i)
        END;

        IF (i > m1) THEN
          RETURN rightEnd-m1
        ELSE
          sk := matcher. skip[ORD (string[rightEnd-i])];
          sh := matcher. shift[i];
          IF (sk-i > sh) THEN
            INC (rightEnd, sk-i)
          ELSE
            INC (rightEnd, sh)
          END
        END
      END
    END;
    RETURN -1
  END SearchStart;

PROCEDURE Search (matcher: Matcher;
                  string[NO_COPY]: ARRAY OF CHAR; len: LONGINT;
                  pos, endpos: LONGINT; s: Object.String8): MatchObject;
  VAR
    i, rightEnd, sh, sk, m1: LONGINT;
    p: Object.String8;
    array: Object.CharsLatin1;
  
  PROCEDURE Match(): MatchObject;
    BEGIN
      IF (s = NIL) & (StringSearch.copyString IN matcher. flags) THEN
        IF (len < 0) THEN                (* don't know length yet *)
          len := endpos;
          WHILE (string[len] # 0X) DO
            INC (len)
          END
        END;
        s := Object.NewLatin1Region(string, 0, len)
      END;
      RETURN NewMatchObject (pos, endpos, matcher, s, rightEnd-m1, rightEnd-m1+p. length)
    END Match;
  
  BEGIN
    p := matcher. pattern;
    m1 := p.length-1;

    array := p.CharsLatin1();
    rightEnd := pos+m1;
    IF (ignoreCase IN matcher. flags) THEN
      WHILE (rightEnd < endpos) DO
        i := 0;
        WHILE (i <= m1) & (CAP (string[rightEnd-i]) = CAP (array[m1-i])) DO
          INC (i)
        END;

        IF (i > m1) THEN
          RETURN Match()
        ELSE
          sk := matcher. skip[ORD (string[rightEnd-i])];
          sh := matcher. shift[i];
          IF (sk-i > sh) THEN
            INC (rightEnd, sk-i)
          ELSE
            INC (rightEnd, sh)
          END
        END
      END
    ELSE
      WHILE (rightEnd < endpos) DO
        i := 0;
        WHILE (i <= m1) & (string[rightEnd-i] = array[m1-i]) DO
          INC (i)
        END;

        IF (i > m1) THEN
          RETURN Match()
        ELSE
          sk := matcher. skip[ORD (string[rightEnd-i])];
          sh := matcher. shift[i];
          IF (sk-i > sh) THEN
            INC (rightEnd, sk-i)
          ELSE
            INC (rightEnd, sh)
          END
        END
      END
    END;
    RETURN NIL
  END Search;

PROCEDURE (matcher: Matcher) SearchChars* (string[NO_COPY]: ARRAY OF CHAR; pos, endpos: LONGINT): MatchObject;
  BEGIN
    IF (endpos = -1) THEN
      REPEAT
        INC (endpos)
      UNTIL (string[endpos] = 0X)
    END;
    RETURN Search (matcher, string, -1, pos, endpos, NIL)
  END SearchChars;

PROCEDURE (matcher: Matcher) Search* (string: Object.String8; pos, endpos: LONGINT): MatchObject;
  VAR
    chars: Object.CharsLatin1;
  BEGIN
    IF (endpos = -1) THEN
      endpos := string. length
    END;
    chars := string.CharsLatin1();
    RETURN Search (matcher, chars^, string. length, pos, endpos, string)
  END Search;


PROCEDURE InitFactory* (f: Factory);
  BEGIN
    StringSearch.InitFactory (f);
  END InitFactory;

PROCEDURE NewFactory (): Factory;
  VAR
    f: Factory;
  BEGIN
    NEW (f);
    InitFactory (f);
    RETURN f
  END NewFactory;

PROCEDURE (f: Factory) Compile* (pattern: Object.String8;
                                 flags: StringSearch.Flags): Matcher;
  BEGIN
    RETURN NewMatcher (pattern, flags, 0)
  END Compile;

BEGIN
  factory := NewFactory()
END StringSearch:SubstringBM.
