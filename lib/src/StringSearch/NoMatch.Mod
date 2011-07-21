(*	$Id: NoMatch.Mod,v 1.2 2002/12/17 19:33:40 mva Exp $	*)
MODULE StringSearch:NoMatch [OOC_EXTENSIONS];
(*  A matcher that does not match anything ;-)
    Copyright (C) 2002  Michael van Acken

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

TYPE
  Factory* = POINTER TO FactoryDesc;
  FactoryDesc* = RECORD
    (**This class implements a matcher that always returns the result
       ''no match''.*)
    (StringSearch.FactoryDesc)
  END;

TYPE
  Matcher* = POINTER TO MatcherDesc;
  MatcherDesc* = RECORD
    (StringSearch.MatcherDesc)
  END;

VAR
  factory-: Factory;
  matcher-: Matcher;


PROCEDURE InitMatcher (matcher: Matcher; pattern: Object.String8; flags: StringSearch.Flags; groups: LONGINT);
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

PROCEDURE (matcher: Matcher) MatchChars* (string[NO_COPY]: ARRAY OF CHAR; pos, endpos: LONGINT): StringSearch.MatchObject;
  BEGIN
    RETURN NIL;
  END MatchChars;

PROCEDURE (matcher: Matcher) Match* (string: Object.String8; pos, endpos: LONGINT): StringSearch.MatchObject;
  BEGIN
    RETURN NIL;
  END Match;


PROCEDURE (matcher: Matcher) SearchChars* (string[NO_COPY]: ARRAY OF CHAR; pos, endpos: LONGINT): StringSearch.MatchObject;
  BEGIN
    RETURN NIL;
  END SearchChars;

PROCEDURE (matcher: Matcher) Search* (string: Object.String8; pos, endpos: LONGINT): StringSearch.MatchObject;
  BEGIN
    RETURN NIL;
  END Search;


PROCEDURE InitFactory (f: Factory);
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
    RETURN matcher
  END Compile;

BEGIN
  factory := NewFactory();
  matcher := NewMatcher(Object.NewLatin1(""), {}, 0);
END StringSearch:NoMatch.
