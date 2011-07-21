(*	$Id: SubstringBF.Mod,v 1.2 2002/12/17 19:33:40 mva Exp $	*)
MODULE StringSearch:SubstringBF [OOC_EXTENSIONS];
(*  Brute-force substring seach.
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
  Object, StringSearch;

CONST
  ignoreCase* = StringSearch.ignoreCase;
  (**See @oconst{StringSearch.ignoreCase}.  *)
  copyString* = StringSearch.copyString;
  (**See @oconst{StringSearch.copyString}.  *)

TYPE
  Factory* = POINTER TO FactoryDesc;
  FactoryDesc* = RECORD
    (**This class implements a brute-force substring matcher.  With a pattern
       length of @var{M} and a string length of @var{N}, a substring search can
       require up to O(N*M) operations.  *)
    (StringSearch.FactoryDesc)
  END;

TYPE
  Matcher* = POINTER TO MatcherDesc;
  MatcherDesc* = RECORD
    (StringSearch.MatcherDesc)
  END;

TYPE
  MatchObject* = POINTER TO MatchObjectDesc;
  MatchObjectDesc* = RECORD
    (StringSearch.MatchObjectDesc)
    start, end: LONGINT;
  END;

VAR
  factory-: Factory;



PROCEDURE InitMatchObject* (m: MatchObject; pos, endpos: LONGINT;
                            matcher: Matcher; string: Object.String8;
                            start, end: LONGINT);
  BEGIN
    StringSearch.InitMatchObject (m, pos, endpos, matcher, string);
    m. start := start;
    m. end := end;
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

PROCEDURE (m: MatchObject) Start* (group: LONGINT): LONGINT;
  BEGIN
    ASSERT (group = 0);
    RETURN m. start
  END Start;

PROCEDURE (m: MatchObject) End* (group: LONGINT): LONGINT;
  BEGIN
    ASSERT (group = 0);
    RETURN m. end
  END End;



PROCEDURE InitMatcher* (matcher: Matcher; pattern: Object.String8; flags: StringSearch.Flags; groups: LONGINT);
  BEGIN
    StringSearch.InitMatcher (matcher, pattern, flags, groups)
  END InitMatcher;

PROCEDURE NewMatcher (pattern: Object.String8; flags: StringSearch.Flags; groups: LONGINT): Matcher;
  VAR
    matcher: Matcher;
  BEGIN
    NEW (matcher);
    InitMatcher (matcher, pattern, flags, 0);
    RETURN matcher
  END NewMatcher;

PROCEDURE Match (matcher: Matcher;
                 string[NO_COPY]: ARRAY OF CHAR; len: LONGINT;
                 pos, endpos: LONGINT; s: Object.String8): MatchObject;
  VAR
    ppos, spos: LONGINT;
    array: Object.CharsLatin1;
  BEGIN
    spos := pos;
    ppos := 0;
    array := matcher.pattern.CharsLatin1();
    IF (ignoreCase IN matcher. flags) THEN
      WHILE (ppos # matcher. pattern. length) & (spos # endpos) &
            (CAP(string[spos]) = CAP(array[ppos])) DO
        INC (spos); INC (ppos)
      END
    ELSE
      WHILE (ppos # matcher. pattern. length) & (spos # endpos) &
            (string[spos] = array[ppos]) DO
        INC (spos); INC (ppos)
      END
    END;
    
    IF (ppos = matcher. pattern. length) THEN
      IF (s = NIL) & (StringSearch.copyString IN matcher. flags) THEN
        IF (len < 0) THEN                (* don't know length yet *)
          len := endpos;
          WHILE (string[len] # 0X) DO
            INC (len)
          END
        END;
        s := Object.NewLatin1Region (string, 0, len)
      END;
      RETURN NewMatchObject (pos, endpos, matcher, s, pos, spos)
    ELSE
      RETURN NIL
    END
  END Match;

PROCEDURE (matcher: Matcher) MatchChars* (string[NO_COPY]: ARRAY OF CHAR; pos, endpos: LONGINT): MatchObject;
  BEGIN
    IF (endpos = -1) THEN
      REPEAT
        INC (endpos)
      UNTIL (string[endpos] = 0X)
    END;
    RETURN Match (matcher, string, -1, pos, endpos, NIL)
  END MatchChars;

PROCEDURE (matcher: Matcher) Match* (string: Object.String8; pos, endpos: LONGINT): MatchObject;
  VAR
    chars: Object.CharsLatin1;
  BEGIN
    IF (endpos = -1) THEN
      endpos := string. length
    END;
    chars := string.CharsLatin1();
    RETURN Match (matcher, chars^, string. length, pos, endpos, string)
  END Match;


PROCEDURE Search (matcher: Matcher;
                  string[NO_COPY]: ARRAY OF CHAR; len: LONGINT;
                  pos, endpos: LONGINT; s: Object.String8): MatchObject;
  VAR
    ppos, spos: LONGINT;
    array: Object.CharsLatin1;
  BEGIN
    spos := pos;
    ppos := 0;
    array := matcher.pattern.CharsLatin1();
    IF (ignoreCase IN matcher. flags) THEN
      WHILE (ppos # matcher. pattern. length) & (spos # endpos) DO
        IF (CAP (string[spos]) = CAP (array[ppos])) THEN
          INC (spos); INC (ppos)
        ELSE (* difference found: reset indices and restart *)
          spos := spos-ppos+1; ppos := 0
        END
      END
    ELSE
      WHILE (ppos # matcher. pattern. length) & (spos # endpos) DO
        IF (string[spos] = array[ppos]) THEN
          INC (spos); INC (ppos)
        ELSE (* difference found: reset indices and restart *)
          spos := spos-ppos+1; ppos := 0
        END
      END
    END;
    
    IF (ppos = matcher. pattern. length) THEN
      IF (s = NIL) & (StringSearch.copyString IN matcher. flags) THEN
        IF (len < 0) THEN                (* don't know length yet *)
          len := endpos;
          WHILE (string[len] # 0X) DO
            INC (len)
          END
        END;
        s := Object.NewLatin1Region (string, 0, len)
      END;
      RETURN NewMatchObject (pos, endpos, matcher, s,
                             spos-matcher. pattern. length, spos)
    ELSE
      RETURN NIL
    END
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
END StringSearch:SubstringBF.
