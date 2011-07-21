(*	$Id: RegexpDFA.Mod,v 1.5 2003/08/02 07:27:19 mva Exp $	*)
MODULE StringSearch:RegexpDFA [OOC_EXTENSIONS];
(*  DFA based regular expression matcher.
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

<* DEFINE DEBUG := FALSE *>

IMPORT
  <*IF DEBUG THEN*>
  Out, ADT:Dictionary:IntValue,
  <*END*>
  Ascii, Object, StringSearch, StringSearch:SubstringBM,
  Regexp := StringSearch:RegexpParser;


(**This module implements a DFA based regular expression pattern matcher.  In
   case of a successful match the longest left-most match is returned.  (That
   is, none of the current test cases fails to report the longest
   match@dots{}).  With a pattern length of @var{M} and a string length of
   @var{@var{N}}, a regular expression match can require up to
   O(@var{M}*@var{N}) operations, and a regular expression search up to
   O(@var{M}*@var{N}^2) operations.

   @strong{Limitations}: Due to its DFA nature, the matcher cannot support
   extraction of matched groups.  The number of parenthesis groups in a pattern
   is limited to 127.  The implementation is not optimized for speed, except
   for using Boyer-Moore for constant pattern prefixes.
   

   Note: This description is a subset of the Python 2.1 documentation chapter
   @samp{4.2.1 Regular Expression Syntax} at
   @url{http://python.org/doc/2.1/lib/re-syntax.html}.

   A regular expression (or RE) specifies a set of strings that matches it; the
   functions in this module let you check if a particular string matches a
   given regular expression (or if a given regular expression matches a
   particular string, which comes down to the same thing).

   Regular expressions can be concatenated to form new regular expressions; if
   @samp{A} and @samp{B} are both regular expressions, then @samp{AB} is also
   an regular expression.  If a string @var{p} matches @samp{A} and another
   string @var{q} matches @samp{B}, the string @var{pq} will match @samp{AB}.
   Thus, complex expressions can easily be constructed from simpler primitive
   expressions like the ones described here.

   A brief explanation of the format of regular expressions follows. For
   further information and a gentler presentation, consult the Regular
   Expression HOWTO, accessible from @url{http://www.python.org/doc/howto/}.

   Regular expressions can contain both special and ordinary characters. Most
   ordinary characters, like @samp{A}, @samp{a}, or @samp{0}, are the simplest
   regular expressions; they simply match themselves.  You can concatenate
   ordinary characters, so @samp{last} matches the string ``last''.

   Some characters, like ``|'' or ``('', are special. Special characters either
   stand for classes of ordinary characters, or affect how the regular
   expressions around them are interpreted.

   The special characters are:

   @table @samp
   @item .
   (Dot.) Matches any character except a newline.

   @item ^
   (Caret.)  Matches the start of the string.

   @item $
   Matches the end of the string.  @samp{foo} matches both ``foo'' and
   ``foobar'', while the regular expression @samp{foo$} matches only ``foo''.

   @item *
   Causes the resulting RE to match 0 or more repetitions of the preceding RE,
   as many repetitions as are possible.  @samp{ab*} will match ``a'', ``ab'',
   or ``a`` followed by any number of ``b''s.

   @item +
   Causes the resulting RE to match 1 or more repetitions of the preceding
   RE. @samp{ab+} will match ``a'' followed by any non-zero number of ``b''s;
   it will not match just ``a''.

   @item ?
   Causes the resulting RE to match 0 or 1 repetitions of the preceding
   RE. @samp{ab?} will match either ``a'' or ``ab''.


   @item \
   Either escapes special characters (permitting you to match characters like
   ``*'', ``?'', and so forth), or signals a special sequence; special
   sequences are discussed below.

   @item [@dots{}]
   Used to indicate a set of characters. Characters can be listed individually,
   or a range of characters can be indicated by giving two characters and
   separating them by a @samp{-}.  Special characters are not active inside
   sets.  For example, @samp{[akm$]} will match any of the characters ``a'',
   ``k'', ``m'', or ``$''; @samp{[a-z]} will match any lowercase letter, and
   @samp{[a-zA-Z0-9]} matches any letter or digit.  Character classes such as
   @samp{\w} or @samp{\S} (defined below) are also acceptable inside a range.
   If you want to include a ``]'' or a ``-'' inside a set, precede it with a
   backslash, or place it as the first character.  The pattern @samp{[]]} will
   match ``]'', for example.

   You can match the characters not within a range by complementing the set.
   This is indicated by including a @samp{^} as the first character of the set;
   @samp{^} elsewhere will simply match the ``^'' character.  For example,
   @samp{[^5]} will match any character except ``5''.

   @item |
   @samp{A|B}, where @samp{A} and @samp{B} can be arbitrary REs, creates a
   regular expression that will match either ``A'' or ``B''.  An arbitrary
   number of REs can be separated by the @samp{|} in this way.  This can be
   used inside groups (see below) as well.  REs separated by @samp{|} are tried
   from left to right, and the first one that allows the complete pattern to
   match is considered the accepted branch.  This means that if A matches, B
   will never be tested, even if it would produce a longer overall match.  In
   other words, the @samp{|} operator is never greedy. To match a literal
   ``|'', use @samp{\|}, or enclose it inside a character class, as in
   @samp{[|]}.

   @item (@dots{})
   Matches whatever regular expression is inside the parentheses, and indicates
   the start and end of a group.  To match the literals ``('' or ``)'', use
   @samp{\(} or @samp{\)}, or enclose them inside a character class: @samp{[(]}
   @samp{[)]}.

   @item \d
   Matches any decimal digit; this is equivalent to the set @samp{[0-9]}.

   @item \D
   Matches any non-digit character; this is equivalent to the set
   @samp{[^0-9]}.

   @item \s
   Matches any whitespace character; this is equivalent to the set
   @samp{[\t\n\r\f\v ]}.

   @item \S
   Matches any non-whitespace character; this is equivalent to the set
   @samp{[^\t\n\r\f\v ]}.

   @item \w
   Matches any alphanumeric character; this is equivalent to the set
   @samp{[a-zA-Z0-9_]}.

   @item \W
   Matches any non-alphanumeric character; this is equivalent to the set
   @samp{[^a-zA-Z0-9_]}.

   @item \\
   Matches a literal backslash.
   @end table  *)

CONST
  ignoreCase* = StringSearch.ignoreCase;
  (**See @oconst{StringSearch.ignoreCase}.  *)
  copyString* = StringSearch.copyString;
  (**See @oconst{StringSearch.copyString}.  *)

CONST
  enterGroup = -3;
  leaveGroup = -2;
  matchEmpty = -1;
  matchChar = Regexp.matchChar;
  matchCharIgnoreCase = Regexp.matchCharIgnoreCase;
  matchAnyButNewline = Regexp.matchAnyButNewline;
  matchAtFirstChar = Regexp.matchAtFirstChar;
  matchAfterLastChar = Regexp.matchAfterLastChar;
  matchSet = Regexp.matchSet;
  matchSetInverted = Regexp.matchSetInverted;

CONST
  neverPushed = -1;
  
TYPE
  GroupId = SHORTINT;
  Node = POINTER TO NodeDesc;
  NodeDesc = RECORD
    <*IF DEBUG THEN*>(Object.ObjectDesc)<*END*>
    suc, alt: Node;
    type: SHORTINT;
    ch: CHAR;
    notMinimized: BOOLEAN;
    groupId: GroupId;
    set: Regexp.CharSet;
    pushedMark: LONGINT;
  END;
  
TYPE
  Factory* = POINTER TO FactoryDesc;
  FactoryDesc* = RECORD
    (**The matcher factory.  *)
    (StringSearch.FactoryDesc)
  END;

TYPE
  Matcher* = POINTER TO MatcherDesc;
  MatcherDesc* = RECORD
    (StringSearch.MatcherDesc)
    initialState: Node;
    prefixMatcher: SubstringBM.Matcher;
  END;

TYPE
  MatchObject* = POINTER TO MatchObjectDesc;
  MatchObjectDesc = RECORD
    (StringSearch.MatchObjectDesc)
    start, end: LONGINT;
  END;

VAR
  factory-: Factory;




PROCEDURE BuildDFA (regexp: Regexp.Group): Node;
  VAR
    initialState, dummy: Node;
    
  PROCEDURE BuildGroup (group: Regexp.Group;
                        VAR start, startAlt: Node; end: Node);
    PROCEDURE NewNode (type: SHORTINT; suc: Node): Node;
      VAR
        n: Node;
      BEGIN
        NEW (n);
        n. type := type;
        n. ch := 0X;
        n. suc := suc;
        n. alt := NIL;
        n. notMinimized := TRUE;
        n. groupId := group. groupId;
        n. set := NIL;
        n. pushedMark := neverPushed;
        RETURN n
      END NewNode;

    PROCEDURE BuildExprList (expr: Regexp.Expr;
                             VAR start, startAlt: Node; end: Node);
      PROCEDURE BuildTermList (term: Regexp.Term;
                               VAR start, startAlt: Node; end: Node);
        VAR
          n: Node; 
          
        PROCEDURE BuildFactor (factor: Regexp.Factor;
                               VAR start, startAlt: Node; end: Node);
          BEGIN
            CASE factor. type OF
            | Regexp.matchChar, Regexp.matchCharIgnoreCase:
              start := NewNode (factor. type, end);
              start. ch := factor. char;
              startAlt := start
            | Regexp.matchSet, Regexp.matchSetInverted:
              start := NewNode (factor. type, end);
              start. set := factor. charSet;
              startAlt := start
            | Regexp.matchAnyButNewline, Regexp.matchAtFirstChar,
              Regexp.matchAfterLastChar:
              start := NewNode (factor. type, end);
              startAlt := start
            | Regexp.matchGroup:
              BuildGroup (factor. group, start, startAlt, end)
            END
          END BuildFactor;
        
        BEGIN
          IF (term = NIL) THEN
            start := end
          ELSE
            BuildTermList (term. next, start, startAlt, end);
            end := start;
            CASE term. quantifier OF
            | Regexp.exactlyOnce:
              BuildFactor (term. factor, start, startAlt, end)
            | Regexp.zeroOrOnceGreedy:
              BuildFactor (term. factor, start, startAlt, end);
              startAlt. alt := NewNode (matchEmpty, end);
              startAlt := startAlt. alt
            | Regexp.zeroOrMoreGreedy:
              start := NewNode (matchEmpty, start); (* target for loop *)
              BuildFactor (term. factor, start. suc, startAlt, start);
              startAlt. alt := end;
              start := NewNode (matchEmpty, start); (* outer entry point *)
              startAlt := start
            | Regexp.onceOrMoreGreedy:
              n := NewNode (matchEmpty, NIL); (* end of loop *)
              BuildFactor (term. factor, start, startAlt, n);
              n. suc := start;
              n. alt := end;
              start := NewNode (matchEmpty, start); (* outer entry point *)
              startAlt := start
            END
          END
        END BuildTermList;
      
      BEGIN
        IF (expr = NIL) THEN
          start := NIL; startAlt := NIL
        ELSE
          IF (expr. termList = NIL) THEN
            start := NewNode (matchEmpty, end); startAlt := start
          ELSE
            BuildTermList (expr. termList, start, startAlt, end)
          END;
          BuildExprList (expr. next, startAlt. alt, startAlt, end)
        END
      END BuildExprList;
    
    BEGIN
      start := NewNode (enterGroup, NIL);
      BuildExprList (group. exprList, start. suc, startAlt,
                     NewNode (leaveGroup, end));
      startAlt := start;
    END BuildGroup;
  
  PROCEDURE Minimize (VAR n: Node);
    BEGIN
      IF (n # NIL) THEN
        IF n. notMinimized THEN
          n. notMinimized := FALSE;
          Minimize (n. suc);
          Minimize (n. alt)
        END;
        IF (n. type = matchEmpty) & (n. alt = NIL) THEN
          n := n. suc
        END
      END
    END Minimize;

  BEGIN
    IF (regexp = NIL) THEN
      RETURN NIL
    ELSE
      dummy := NIL;
      BuildGroup (regexp, initialState, dummy, NIL);
      Minimize (initialState);
      RETURN initialState
    END
  END BuildDFA;



PROCEDURE InitMatchObject (m: MatchObject; pos, endpos: LONGINT;
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


PROCEDURE InitMatcher (matcher: Matcher; pattern: Object.String8; flags: StringSearch.Flags; groups: LONGINT; initialState: Node);
  CONST
    maxPrefixLength = 1024;
  VAR
    prefixLength, i: LONGINT;
    type: SHORTINT;
    ptr: Node;
    str: ARRAY maxPrefixLength OF CHAR;
    prefixPattern: Object.String8;
  BEGIN
    StringSearch.InitMatcher (matcher, pattern, flags, groups);
    matcher. initialState := initialState;
    
    (* does the pattern start with a fixed prefix? *)
    matcher. prefixMatcher := NIL;
    type := initialState. suc. type;
    IF (type = matchChar) OR (type = matchCharIgnoreCase) THEN
      prefixLength := 0;
      ptr := initialState. suc;
      WHILE (ptr. type = type) & (ptr. alt = NIL) DO
        INC (prefixLength); ptr := ptr. suc
      END;
      
      IF (prefixLength > 1) THEN
        IF (prefixLength > maxPrefixLength) THEN
          prefixLength := maxPrefixLength
        END;
        ptr := initialState. suc;
        FOR i := 0 TO prefixLength-1 DO
          str[i] := ptr. ch; ptr := ptr. suc
        END;
        prefixPattern := Object.NewLatin1Region (str, 0, prefixLength);
        IF (type = matchChar) THEN
          flags := {}
        ELSE
          flags := {ignoreCase}
        END;
        matcher. prefixMatcher :=
          SubstringBM.factory. Compile(prefixPattern, flags);
      END
    END;
  END InitMatcher;

PROCEDURE NewMatcher (pattern: Object.String8; flags: StringSearch.Flags; groups: LONGINT; initialState: Node): Matcher;
  VAR
    matcher: Matcher;
  BEGIN
    NEW (matcher);
    InitMatcher (matcher, pattern, flags, 0, initialState);
    RETURN matcher
  END NewMatcher;

PROCEDURE Match (matcher: Matcher;
                 string[NO_COPY]: ARRAY OF CHAR; len: LONGINT;
                 startpos, pos, endpos: LONGINT;
                 s: Object.String8): MatchObject;
  TYPE
    DequeEntry = POINTER TO DequeEntryDesc;
    DequeEntryDesc = RECORD
      next: DequeEntry;
      state: Node;
    END;
  CONST
    scanState = NIL;
  VAR
    spos, endOfMatch, i: LONGINT;
    first, last, deScanState: DequeEntry;
    state: Node;
    
  PROCEDURE Put (state: Node);
    VAR
      de: DequeEntry;
    BEGIN
      IF (state # scanState) THEN
        (* first check if the state is already present in the deque after the
           scanState marker *)
        de := deScanState. next;
        WHILE (de # NIL) DO
          IF (de. state = state) THEN
            RETURN
          END;
          de := de. next
        END
      END;
      
      NEW (de);
      de. next := NIL;
      de. state := state;
      IF (first = NIL) THEN
        first := de
      ELSE
        last. next := de
      END;
      last := de
    END Put;
  
  PROCEDURE Push (state: Node);
    VAR
      de: DequeEntry;
    BEGIN
      IF (state. pushedMark # spos) THEN
        (* only push state if it has not put pushed into the deque for this
           character position before *)
        state. pushedMark := spos;
        
        NEW (de);
        de. next := first;
        de. state := state;
        IF (first = NIL) THEN
          last := de
        END;
        first := de
      END
    END Push;
  
  PROCEDURE PruneGroup (groupId: GroupId);
    VAR
      de, prev: DequeEntry;
    BEGIN
      de := first; prev := NIL;
      WHILE (de. state # scanState) DO
        IF (de. state. groupId = groupId) THEN
          IF (de = first) THEN
            first := de. next
          ELSE
            prev. next := de. next
          END;
          IF (de. next = NIL) THEN
            last := prev
          END
        END;
        prev := de; de := de. next
      END
    END PruneGroup;
  
  PROCEDURE UnmarkNode (n: Node);
    BEGIN
      WHILE (n # NIL) & (n. pushedMark # neverPushed) DO
        n. pushedMark := neverPushed;
        IF (n. alt # NIL) THEN UnmarkNode (n. alt) END;
        n := n. suc
      END
    END UnmarkNode;
  
  PROCEDURE MarkCurrentStates;
    VAR
      de: DequeEntry;
    BEGIN
      de := first;
      WHILE (de # NIL) DO
        de. state. pushedMark := spos;
        de := de. next
      END
    END MarkCurrentStates;
  
  BEGIN
    first := NIL;
    last := NIL;
    deScanState := NIL;
    Put (scanState);
    deScanState := last;
    UnmarkNode (matcher. initialState);
    
    endOfMatch := -1;
    spos := pos;
    state := matcher. initialState;
    state. pushedMark := spos;           (* without this, UnmarkNode fails *)
    WHILE (first # NIL) DO
      (* repeat until deque is empty except for scanState entry *)
      
      IF (state = scanState) THEN
        INC (spos);
        MarkCurrentStates();
        Put (scanState);
        deScanState := last
      ELSE
        IF (state. alt # NIL) THEN
          Push (state. alt)
        END;
        CASE state. type OF
        | enterGroup:
          Push (state. suc)
        | leaveGroup:
          PruneGroup (state. groupId);
          IF (state. groupId = 0) THEN
            endOfMatch := spos
          ELSE
            Push (state. suc)
          END
        | matchEmpty:
          ASSERT (state. suc # NIL);
          Push (state. suc)
        | matchChar:
          IF (spos # endpos) & (string[spos] = state. ch) THEN
            Put (state. suc)
          END
        | matchCharIgnoreCase:
          IF (spos # endpos) & (CAP (string[spos]) = CAP (state. ch)) THEN
            Put (state. suc)
          END
        | matchAnyButNewline:
          IF (spos # endpos) & (string[spos] # Ascii.lf) THEN
            Put (state. suc)
          END
        | matchAtFirstChar:
          IF (spos = 0) THEN
            Push (state. suc)
          END
        | matchAfterLastChar:
          IF (spos = endpos) THEN
            Push (state. suc)
          END
        | matchSet:
          i := ORD (string[spos]);
          IF (spos # endpos) &
             (i MOD Regexp.sizeSET IN state. set[i DIV Regexp.sizeSET]) THEN
            Put (state. suc)
          END
        | matchSetInverted:
          i := ORD (string[spos]);
          IF (spos # endpos) &
             ~(i MOD Regexp.sizeSET IN state. set[i DIV Regexp.sizeSET]) THEN
            Put (state. suc)
          END
        END
      END;
      
      (* pop leftmost element from the deque *)
      state := first. state;
      first := first. next;
    END;
    
    IF (endOfMatch >= 0) THEN
      IF (s = NIL) & (StringSearch.copyString IN matcher. flags) THEN
        IF (len < 0) THEN                (* don't know length yet *)
          len := endpos;
          WHILE (string[len] # 0X) DO
            INC (len)
          END
        END;
        s := Object.NewLatin1Region (string, 0, len)
      END;
      RETURN NewMatchObject (startpos, endpos, matcher, s, pos, endOfMatch)
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
    RETURN Match (matcher, string, -1, pos, pos, endpos, NIL)
  END MatchChars;

PROCEDURE (matcher: Matcher) Match* (string: Object.String8; pos, endpos: LONGINT): MatchObject;
  VAR
    chars: Object.CharsLatin1;
  BEGIN
    IF (endpos = -1) THEN
      endpos := string. length
    END;
    chars := string.CharsLatin1();
    RETURN Match (matcher, chars^, string. length, pos, pos, endpos, string)
  END Match;

PROCEDURE Search (matcher: Matcher;
                  string[NO_COPY]: ARRAY OF CHAR; len: LONGINT;
                  pos, endpos: LONGINT; s: Object.String8): MatchObject;
  VAR
    m: MatchObject;
    startpos, startPrefix: LONGINT;
  BEGIN
    startpos := pos;
    IF (matcher. prefixMatcher # NIL) THEN
      WHILE (pos <= endpos) DO
        startPrefix := SubstringBM.SearchStart (matcher. prefixMatcher,
                                                string, pos, endpos);
        IF (startPrefix >= 0) THEN
          (* prefix is fine, let's see if the rest matches *)
          m := Match (matcher, string, len, startpos, startPrefix, endpos, s);
          IF (m # NIL) THEN
            RETURN m                     (* got a match, no need to continue *)
          ELSE
            pos := startPrefix+1         (* wasn't a match after all *)
          END
        ELSE                             (* no prefix, no match *)
          RETURN NIL
        END
      END
    ELSE
      WHILE (pos <= endpos) DO
        m := Match (matcher, string, len, startpos, pos, endpos, s);
        IF (m # NIL) THEN
          RETURN m
        END;
        INC (pos)
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


<*IF DEBUG THEN*>
PROCEDURE DumpRegexp (regexp: Node);
  VAR
    ref, done: IntValue.Dictionary;
    c: LONGINT;
  
  PROCEDURE AssignId (n: Node);
    BEGIN
      IF ~ref. HasKey (n) THEN
        ref. Set (n, c);
        INC (c)
      END
    END AssignId;
  
  PROCEDURE WriteRef (n: Node);
    BEGIN
      IF (n = NIL) THEN
        Out.String ("NIL")
      ELSE
        AssignId (n);
        Out.LongInt (ref. Get (n), 0)
      END
    END WriteRef;
  
  PROCEDURE Write (n: Node);
    PROCEDURE WriteChar (i: LONGINT);
      BEGIN
        IF (i < 32) OR (i >= 127) THEN
          Out.Char (Regexp.backslash);
          Out.Char (CHR (i DIV 64+ORD ("0")));
          Out.Char (CHR (i DIV 8 MOD 8+ORD ("0")));
          Out.Char (CHR (i MOD 8+ORD ("0")))
        ELSE
          Out.Char (CHR (i))
        END
      END WriteChar;

    PROCEDURE WriteSet (set: Regexp.CharSet);
      VAR
        i, j: LONGINT;
        
      PROCEDURE IsSet (i: LONGINT): BOOLEAN;
        BEGIN
          RETURN (i MOD Regexp.sizeSET IN set[i DIV Regexp.sizeSET])
        END IsSet;
      
      BEGIN
        i := 0; j := 0;
        WHILE (i < Regexp.sizeCHAR) DO
          IF IsSet (i) THEN
            j := i+1;
            WHILE (j < Regexp.sizeCHAR) & IsSet (j) DO
              INC (j)
            END;
            IF (j-i > 3) THEN
              WriteChar (i); Out.String ("-"); WriteChar (j-1); i := j
            ELSE
              WriteChar (i); INC (i)
            END
          ELSE
            INC (i)
          END
        END
      END WriteSet;
    
    BEGIN
      IF (n # NIL) & ~done. HasKey (n) THEN
        done. Set (n, 0);
        
        WriteRef (n);
        Out.String (" [gid=");
        Out.Int (n. groupId, 0);
        Out.String ("]: ");
        CASE n. type OF
        | enterGroup:
          Out.String ("enter_group()")
        | leaveGroup:
          Out.String ("leave_group()")
        | matchEmpty:
          Out.String ("*EMPTY*")
        | matchChar:
          Out.String ("char("); WriteChar (ORD (n. ch)); Out.String(")")
        | matchCharIgnoreCase:
          Out.String ("char_ic("); WriteChar (ORD (n. ch)); Out.String(")")
        | matchAnyButNewline:
          Out.String ("any char but newline")
        | matchAtFirstChar:
          Out.String ("match at first char")
        | matchAfterLastChar:
          Out.String ("match after last char")
        | matchSet:
          Out.String ("set("); WriteSet (n. set); Out.String (")")
        | matchSetInverted:
          Out.String ("~set("); WriteSet (n. set); Out.String (")")
        END;
        Out.Ln;
        Out.String ("  suc="); WriteRef (n. suc); Out.Ln;
        Out.String ("  alt="); WriteRef (n. alt); Out.Ln;
        
        Write (n. suc); Write (n. alt);
      END
    END Write;
  
  BEGIN
    c := 0;
    ref := IntValue.New();
    done := IntValue.New();
    Write (regexp);
  END DumpRegexp;

PROCEDURE Test (pattern: ARRAY OF CHAR);
  VAR
    matcher: StringSearch.Matcher;
  BEGIN
    Out.Ln; Out.String ("pattern="); Out.String (pattern); Out.Ln;
    matcher := factory. Compile (Object.NewLatin1 (pattern), {});
    IF (matcher = NIL) THEN
      Out.String ("ERROR"); Out.Ln;
    ELSE
      (*DumpRegexp (matcher(Matcher). initialState)*)
    END
  END Test;

PROCEDURE RunTests*;
  BEGIN
    (* reference output for this test cases is in 
       tests/stringsearch/TestRegexp.out *)
    Test ("");
    Test ("()");
    Test ("a");
    Test ("(a)");
    Test ("abc");
    Test ("a|b");
    Test ("|b");
    Test ("a|");
    Test ("(a|b)");
    Test ("(|b)");
    Test ("(a|)");

    Test ("a?");
    Test ("ab?");
    Test ("(a|b)?");
    Test ("(ab)?");
    Test ("a?|x");
    Test ("ab?|x");
    Test ("(a|b)?|x");
    Test ("(ab)?|x");

    Test ("a*");
    Test ("ab*");
    Test ("(a|b)*");
    Test ("(ab)*");
    Test ("a*|x");
    Test ("ab*|x");
    Test ("(a|b)*|x");
    Test ("(ab)*|x");

    Test ("a+");
    Test ("ab+");
    Test ("(a|b)+");
    Test ("(ab)+");
    Test ("a+|x");
    Test ("ab+|x");
    Test ("(a|b)+|x");
    Test ("(ab)+|x");

    Test ("[a]");
    Test ("[^a]");
    Test ("[0-9]");
    Test ("[\d]");
    Test ("\d");
    Test ("[^0-9]");
    Test ("[\D]");
    Test ("\D");
    Test ("[a-zA-Z0-9_]");
    Test ("[\w]");
    Test ("\w");
    Test ("[^a-zA-Z0-9_]");
    Test ("[\W]");
    Test ("\W");
    Test ("[$^*+?|()]");
    Test ("[\]]");
    Test ("[]]");
    Test ("[\-]");
    Test ("[-]");
    Test ("[\-]");
    Test ("[a-]");

    Test (".");
    Test ("^");
    Test ("$");
    Test ("\.\^\$\*\+\?\\\[\]\|\(\)");
    Test ("\b\a\e\f\n\r\t\v");
    Test ("[\b\a\e\f\n\r\t\v]");
  END RunTests;
<*END*>


PROCEDURE (f: Factory) Compile* (pattern: Object.String8;
                                 flags: StringSearch.Flags): Matcher;
  VAR
    initialState: Node;
  BEGIN
    initialState := BuildDFA (Regexp.Parse (Regexp.NewBuilder(),
                                            pattern, flags));
    IF (initialState = NIL) THEN
      RETURN NIL
    ELSE
      <*IF DEBUG THEN*>DumpRegexp (initialState);<*END*>
      RETURN NewMatcher (pattern, flags, 0, initialState)
    END
  END Compile;


BEGIN
  factory := NewFactory();
  
  <*IF DEBUG THEN*>
  RunTests;
  <*END*>
END StringSearch:RegexpDFA.
