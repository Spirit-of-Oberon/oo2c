(*	$Id: StringSearch.Mod,v 1.5 2002/12/17 19:33:50 mva Exp $	*)
MODULE StringSearch [OOC_EXTENSIONS];
(*  Framework for string searching algorithms.
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
  Object;

(**This module specifies a common framework for string search algorithms.
   Examples for implementations are @omodule{*StringSearch:SubstringBF}, which
   does brute-force searching for substrings, and
   @omodule{*StringSearch:Regexp}, a regular expression engine.  *)

TYPE
  Flags* = SET;
  
CONST
  ignoreCase* = 0;
  (**Perform case-insensitive matching.  For example, a regular expression like
     @samp{[A-Z]} will match lowercase letters, too.  *)
  copyString* = 1;
  (**If set, then the match and search functions working an character arrays
     create a new copy of the searched string for @ofield{MatchObject.string}.
     Setting this flag is only useful if you intend to extract matched
     substrings from an instance of @otype{MatchObject}.  Note that most
     matchers do not support capturing matched substrings.  *)
  
TYPE
  Factory* = POINTER TO FactoryDesc;
  FactoryDesc* = RECORD [ABSTRACT]
    (**Factory for @otype{Matcher} objects.  An instance of @otype{Matcher} is
       created from a textual description of a search pattern by calling
       @oproc{Factory.Compile}.  *)
    (Object.ObjectDesc)
  END;

TYPE
  Matcher* = POINTER TO MatcherDesc;
  MatcherDesc* = RECORD [ABSTRACT]
  (**A representation of a search pattern.  An instance of @otype{Matcher} is
     applied to a string by calling one of the match or search methods.  *)
    (Object.ObjectDesc)
    pattern-: Object.String8;
    (**The pattern string from which the matcher object was compiled.  *)
    flags-: Flags;
    (**The flags argument used when the matcher object was compiled.  *)
    groups-: LONGINT;
    (**The number of groups defined in the pattern string.  If there
       are no groups, for example because the matcher does not support
       them, the field is zero.  *)
  END;

TYPE
  MatchObject* = POINTER TO MatchObjectDesc;
  MatchObjectDesc* = RECORD [ABSTRACT]
  (**Represents the result of a successful match or search operation.  *)
    (Object.ObjectDesc)
    pos-: LONGINT;
    (**The value of @var{pos} which was passed to a search or match function.
       This is the index into the string at which the matcher engine started
       looking for a match.  *)
    endpos-: LONGINT;
    (**The value of @var{endpos} which was passed to a search or match
       function.  This is the index into the string beyond which the matcher
       engine will not go.  *)
    matcher-: Matcher;
    (**The matcher object whose match or search method produced this
       @otype{MatchObject} instance.  *)
    string-: Object.String8;
    (**The string passed to a match or search function.  This field is
       @code{NIL} if @oproc{Matcher.MatchChars} or @oproc{Matcher.SearchChars}
       is called without the flag @oconst{copyString}.  *)
  END;


PROCEDURE InitMatchObject* (m: MatchObject; pos, endpos: LONGINT;
                            matcher: Matcher; string: Object.String8);
  BEGIN
    m. pos := pos;
    m. endpos := endpos;
    m. matcher := matcher;
    m. string := string;
  END InitMatchObject;

PROCEDURE (m: MatchObject) Destroy*;
  BEGIN
    m. pos := 0;
    m. endpos := 0;
    m. matcher := NIL;
    m. string := NIL;
  END Destroy;

PROCEDURE (m: MatchObject) [ABSTRACT] Start* (group: LONGINT): LONGINT;
(**Returns the index of the start of the substring matched by @oparam{group}.
   A @oparam{group} of @samp{0} refers to the whole matched substring.  Returns
   @samp{-1} if the group exists but did not contribute to the match.  For a
   match object @var{m}, and a group @var{g} that did contribute to the match,
   the substring matched by group @var{g} is
   @samp{string[@var{m}.Start(@var{g}), @var{m}.End(@var{g})[}.  Note that
   @samp{m.Start(@var{g})} will equal @samp{m.End(@var{g})} if @var{g} matched
   a null string.

   Note: Not all matcher implementations implement groups other than the whole
   match.
   
   @precond
   @samp{0 <= @oparam{group} <= @ofield{m.matcher.groups}}
   @end precond *)
  END Start;

PROCEDURE (m: MatchObject) [ABSTRACT] End* (group: LONGINT): LONGINT;
(**Returns the index of the end of the substring matched by @oparam{group}.
   See @oproc{MatchObject.Start}.  *)
  END End;


PROCEDURE InitMatcher* (matcher: Matcher; pattern: Object.String8; flags: Flags; groups: LONGINT);
  BEGIN
    matcher. pattern := pattern;
    matcher. flags := flags;
    matcher. groups := groups;
  END InitMatcher;

PROCEDURE (matcher: Matcher) Destroy*;
  BEGIN
    matcher. pattern := NIL;
    matcher. flags := {};
    matcher. groups := 0;
  END Destroy;

PROCEDURE (matcher: Matcher) [ABSTRACT] MatchChars* (string[NO_COPY]: ARRAY OF CHAR; pos, endpos: LONGINT): MatchObject;
(**Returns a corresponding @otype{MatchObject} instance, if zero or more
   characters at the beginning of string match this @otype{Matcher}.  Returns
   @code{NIL} if the string does not match the pattern.  Note that this is
   different from a zero-length match.

   Note: If you want to locate a match anywhere in string, use
   @oproc{Matcher.Search} instead.

   The second parameter @oparam{pos} gives an index in the string where the
   search is to start, for example 0 to start at the beginning of the string.

   The parameter @oparam{endpos} limits how far the string will be searched.
   It will be as if the string is @oparam{endpos} characters long, so only the
   characters in @samp{[@oparam{pos}, @oparam{endpos}[} will be searched for a
   match.  A value of @samp{-1} is equivalent to an @oparam{endpos} of
   @samp{Length(string)}.

   @precond
   The start position is within the string @samp{0 <= @oparam{pos} <=
   Length(string)}, and the given end position is either @samp{-1}, or between
   the start position and the end of the string @samp{@oparam{pos} <=
   @oparam{endpos} <= Length(string)}.
   @end precond *)
  END MatchChars;

PROCEDURE (matcher: Matcher) [ABSTRACT] Match* (string: Object.String8; pos, endpos: LONGINT): MatchObject;
  (**Like @oproc{Matcher.MatchChars}, but works on an instance of
     @otype{Object.String8}.  *)
  END Match;

PROCEDURE (matcher: Matcher) [ABSTRACT] SearchChars* (string[NO_COPY]: ARRAY OF CHAR; pos, endpos: LONGINT): MatchObject;
(**Scans through string looking for a location where this @otype{Matcher}
   produces a match, and return a corresponding @otype{MatchObject} instance.
   Returns @code{NIL} if no position in the string matches the pattern.  Note
   that this is different from finding a zero-length match at some point in the
   string.

   The @oparam{pos} and @oparam{endpos} parameters have the same
   meaning as for the @oproc{Matcher.MatchChars} method.  *)
  END SearchChars;

PROCEDURE (matcher: Matcher) [ABSTRACT] Search* (string: Object.String8; pos, endpos: LONGINT): MatchObject;
  (**Like @oproc{Matcher.SearchChars}, but works on an instance of
     @otype{Object.String8}.  *)
  END Search;
  
PROCEDURE InitFactory* (f: Factory);
  BEGIN
  END InitFactory;

PROCEDURE (f: Factory) Destroy*;
  BEGIN
  END Destroy;

PROCEDURE (f: Factory) [ABSTRACT] Compile* (pattern: Object.String8;
                                            flags: Flags): Matcher;
(**Compile a expression, for example a regular expression pattern, into a
   @otype{Matcher} expression object.  The matcher object can be used for
   matching using its @oproc{Matcher.MatchChars} and
   @oproc{Matcher.SearchChars} methods.

   The pattern's behaviour can be modified by specifying a @oparam{flags}
   value.  The set can include of the following variables: @oconst{ignoreCase},
   @oconst{copyString}.

   Result is @code{NIL} if the given pattern is invalid.

   @precond
   The value of @oparam{pattern} does not contain the character @code{0X}.
   @end precond  *)
  END Compile;

END StringSearch.
