(*	$Id$	*)
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
  StringSearch, ADT:String;

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
                            matcher: Matcher; string: String.String;
                            start, end: LONGINT);
  BEGIN
    StringSearch.InitMatchObject (m, pos, endpos, matcher, string);
    m. start := start;
    m. end := end;
  END InitMatchObject;

PROCEDURE NewMatchObject (pos, endpos: LONGINT;
                          matcher: Matcher; string: String.String;
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



PROCEDURE InitMatcher* (matcher: Matcher; pattern: String.String; flags: StringSearch.Flags; groups: LONGINT);
  BEGIN
    StringSearch.InitMatcher (matcher, pattern, flags, groups)
  END InitMatcher;

PROCEDURE NewMatcher (pattern: String.String; flags: StringSearch.Flags; groups: LONGINT): Matcher;
  VAR
    matcher: Matcher;
  BEGIN
    NEW (matcher);
    InitMatcher (matcher, pattern, flags, 0);
    RETURN matcher
  END NewMatcher;

PROCEDURE Match (matcher: Matcher;
                 string[NO_COPY]: ARRAY OF CHAR; len: LONGINT;
                 pos, endpos: LONGINT; s: String.String): MatchObject;
  VAR
    ppos, spos: LONGINT;
  BEGIN
    spos := pos;
    ppos := 0;
    IF (ignoreCase IN matcher. flags) THEN
      WHILE (ppos # matcher. pattern. length) & (spos # endpos) &
            (CAP(string[spos]) = CAP(matcher. pattern. array[ppos])) DO
        INC (spos); INC (ppos)
      END
    ELSE
      WHILE (ppos # matcher. pattern. length) & (spos # endpos) &
            (string[spos] = matcher. pattern. array[ppos]) DO
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
        s := String.NewRegion (string, 0, len)
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

PROCEDURE (matcher: Matcher) Match* (string: String.String; pos, endpos: LONGINT): MatchObject;
  BEGIN
    IF (endpos = -1) THEN
      endpos := string. length
    END;
    RETURN Match (matcher, string. array^, string. length, pos, endpos, string)
  END Match;


PROCEDURE Search (matcher: Matcher;
                  string[NO_COPY]: ARRAY OF CHAR; len: LONGINT;
                  pos, endpos: LONGINT; s: String.String): MatchObject;
  VAR
    ppos, spos: LONGINT;
  BEGIN
    spos := pos;
    ppos := 0;
    IF (ignoreCase IN matcher. flags) THEN
      WHILE (ppos # matcher. pattern. length) & (spos # endpos) DO
        IF (CAP (string[spos]) = CAP (matcher. pattern. array[ppos])) THEN
          INC (spos); INC (ppos)
        ELSE (* difference found: reset indices and restart *)
          spos := spos-ppos+1; ppos := 0
        END
      END
    ELSE
      WHILE (ppos # matcher. pattern. length) & (spos # endpos) DO
        IF (string[spos] = matcher. pattern. array[ppos]) THEN
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
        s := String.NewRegion (string, 0, len)
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

PROCEDURE (matcher: Matcher) Search* (string: String.String; pos, endpos: LONGINT): MatchObject;
  BEGIN
    IF (endpos = -1) THEN
      endpos := string. length
    END;
    RETURN Search (matcher, string. array^, string. length, pos, endpos, string)
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

PROCEDURE (f: Factory) Compile* (pattern: String.String;
                                 flags: StringSearch.Flags): Matcher;
  BEGIN
    RETURN NewMatcher (pattern, flags, 0)
  END Compile;

BEGIN
  factory := NewFactory()
END StringSearch:SubstringBF.
