MODULE LibStringSearch2;

IMPORT
  RT0, Out := Out0, RND := RandomNumbers, Time, Object, StringSearch,
  StringSearch:SubstringBF, StringSearch:SubstringBM, StringSearch:RegexpDFA;

TYPE
  StringPtr = POINTER TO ARRAY OF CHAR;


PROCEDURE WriteType (t: RT0.Struct);
  VAR
    str: ARRAY 256 OF CHAR;
  BEGIN
    Out.String ("[");
    COPY (t. module. name^, str);
    Out.String (str);
    Out.String (".");
    COPY (t. name^, str);
    Out.String (str);
    Out.String ("]");
  END WriteType;

PROCEDURE Compile (f: StringSearch.Factory;
                   pattern: ARRAY OF CHAR; flags: StringSearch.Flags): StringSearch.Matcher;
  VAR
    matcher: StringSearch.Matcher;
  BEGIN
    WriteType (RT0.TypeOf (f));
    Out.String (" pattern=`");
    Out.String (pattern);
    Out.String ("'");
    IF (StringSearch.ignoreCase IN flags) THEN
      Out.String (", ignoreCase");
    END;
    Out.Ln;
    matcher := f. Compile (Object.NewLatin1 (pattern), flags);
    IF (matcher = NIL) THEN
      Out.String ("### compile failed, aborting"); Out.Ln; HALT(1)
    END;
    RETURN matcher
  END Compile;

PROCEDURE Match (matcher: StringSearch.Matcher; string: ARRAY OF CHAR): StringSearch.MatchObject;
  VAR
    m: StringSearch.MatchObject;
  BEGIN
    m := matcher. MatchChars (string, 0, -1);
    IF (m = NIL) THEN
      Out.String ("--> no match");
      Out.Ln
    ELSE
      Out.String ("--> start=");
      Out.Int (m. Start(0), 0);
      Out.String (", end=");
      Out.Int (m. End(0), 0);
      Out.Ln
    END;
    RETURN m
  END Match;

PROCEDURE Search (matcher: StringSearch.Matcher; string: ARRAY OF CHAR; pos, endpos: LONGINT): StringSearch.MatchObject;
  VAR
    m: StringSearch.MatchObject;
  BEGIN
    m := matcher. SearchChars (string, pos, endpos);
    IF (m = NIL) THEN
      Out.String ("--> no match");
      Out.Ln
    ELSE
      Out.String ("--> start=");
      Out.Int (m. Start(0), 0);
      Out.String (", end=");
      Out.Int (m. End(0), 0);
      Out.Ln
    END;
    RETURN m
  END Search;


PROCEDURE MatchOk (f: StringSearch.Factory;
                   pattern: ARRAY OF CHAR; flags: StringSearch.Flags;
                   string: ARRAY OF CHAR; expectStart, expectEnd: LONGINT);
  VAR
    matcher: StringSearch.Matcher;
    m: StringSearch.MatchObject;
  BEGIN
    matcher := Compile (f, pattern, flags);
    Out.String ("matching against `");
    Out.String (string);
    Out.String ("'");
    Out.Ln;
    m := Match (matcher, string);
    IF (m = NIL) THEN
      Out.String ("### match failed, aborting"); Out.Ln; HALT(1)
    ELSIF (m. Start(0) # expectStart) THEN
      Out.String ("### expected start: "); Out.Int (expectStart,0); Out.Ln;
      HALT(1)
    ELSIF (m. End(0) # expectEnd) THEN
      Out.String ("### expected end: "); Out.Int (expectEnd, 0); Out.Ln;
      HALT(1)
    END
  END MatchOk;

PROCEDURE MatchNotOk (f: StringSearch.Factory;
                      pattern: ARRAY OF CHAR; flags: StringSearch.Flags;
                      string: ARRAY OF CHAR);
  VAR
    matcher: StringSearch.Matcher;
    m: StringSearch.MatchObject;
  BEGIN
    matcher := Compile (f, pattern, flags);
    Out.String ("matching against `");
    Out.String (string);
    Out.String ("'");
    Out.Ln;
    m := Match (matcher, string);
    IF (m # NIL) THEN
      Out.String ("### match succeeded, aborting"); Out.Ln; HALT(1)
    END
  END MatchNotOk;


PROCEDURE SearchOkRegion (f: StringSearch.Factory;
                          pattern: ARRAY OF CHAR; flags: StringSearch.Flags;
                          string: ARRAY OF CHAR;
                          pos, endpos: LONGINT;
                          expectStart, expectEnd: LONGINT);
  VAR
    matcher: StringSearch.Matcher;
    m: StringSearch.MatchObject;
  BEGIN
    matcher := Compile (f, pattern, flags);
    Out.String ("searching in `");
    Out.String (string);
    Out.String ("'");
    Out.Ln;
    m := Search (matcher, string, pos, endpos);
    IF (m = NIL) THEN
      Out.String ("### match failed, aborting"); Out.Ln; HALT(1)
    ELSIF (m. Start(0) # expectStart) THEN
      Out.String ("### expected start: "); Out.Int (expectStart,0); Out.Ln;
      HALT(1)
    ELSIF (m. End(0) # expectEnd) THEN
      Out.String ("### expected end: "); Out.Int (expectEnd, 0); Out.Ln;
      HALT(1)
    END
  END SearchOkRegion;

PROCEDURE SearchOk (f: StringSearch.Factory;
                   pattern: ARRAY OF CHAR; flags: StringSearch.Flags;
                   string: ARRAY OF CHAR; expectStart, expectEnd: LONGINT);
  BEGIN
    SearchOkRegion (f, pattern, flags, string, 0, -1, expectStart, expectEnd)
  END SearchOk;

PROCEDURE SearchNotOkRegion (f: StringSearch.Factory;
                             pattern: ARRAY OF CHAR; flags: StringSearch.Flags;
                             string: ARRAY OF CHAR;
                             pos, endpos: LONGINT);
  VAR
    matcher: StringSearch.Matcher;
    m: StringSearch.MatchObject;
  BEGIN
    matcher := Compile (f, pattern, flags);
    Out.String ("searching in `");
    Out.String (string);
    Out.String ("'");
    Out.Ln;
    m := Search (matcher, string, pos, endpos);
    IF (m # NIL) THEN
      Out.String ("### match succeeded, aborting"); Out.Ln; HALT(1)
    END
  END SearchNotOkRegion;

PROCEDURE SearchNotOk (f: StringSearch.Factory;
                      pattern: ARRAY OF CHAR; flags: StringSearch.Flags;
                      string: ARRAY OF CHAR);
  BEGIN
    SearchNotOkRegion (f, pattern, flags, string, 0, -1)
  END SearchNotOk;




PROCEDURE SimpleMatches (f: StringSearch.Factory);
  BEGIN
    MatchOk(f, "", {}, "", 0, 0);
    MatchOk(f, "", {}, "a", 0, 0);
    MatchOk(f, "a", {}, "a", 0, 1);
    MatchOk(f, "a", {}, "ab", 0, 1);
    MatchOk(f, "ab", {}, "ab", 0, 2);

    MatchOk(f, "a", {StringSearch.ignoreCase}, "a", 0, 1);
    MatchOk(f, "a", {StringSearch.ignoreCase}, "A", 0, 1);
    MatchOk(f, "A", {StringSearch.ignoreCase}, "a", 0, 1);
    MatchOk(f, "A", {StringSearch.ignoreCase}, "A", 0, 1);
    
    MatchNotOk(f, "a", {}, "");
    MatchNotOk(f, "a", {}, "A");
    MatchNotOk(f, "ab", {}, "a");
    MatchNotOk(f, "ab", {}, "ac");
  END SimpleMatches;

PROCEDURE SimpleSearches (f: StringSearch.Factory);
  VAR
    i: LONGINT;
    
  PROCEDURE Large (n: LONGINT);
    VAR
      len, c, i, j: LONGINT;
      s, p: POINTER TO ARRAY OF CHAR;
    BEGIN
      len := (n*(n+1)) DIV 2;
      NEW (p, n+1);
      FOR i := 0 TO n-1 DO
        p[i] := CHR (ORD ("a")+i)
      END;
      p[n] := 0X;
      
      NEW (s, len+1);
      c := 0;
      FOR i := 0 TO n-1 DO
        FOR j := 0 TO i DO
          s[c] := CHR (ORD ("a")+j); INC (c)
        END
      END;
      ASSERT (c = len);
      s[len] := 0X;
      
      SearchOk(f, p^, {}, s^, len-n, len);
    END Large;
  
  BEGIN
    SearchOk(f, "", {}, "", 0, 0);
    SearchOk(f, "", {}, "a", 0, 0);
    SearchOk(f, "a", {}, "a", 0, 1);
    SearchOk(f, "a", {}, "abc", 0, 1);
    SearchOk(f, "b", {}, "abc", 1, 2);
    SearchOk(f, "c", {}, "abc", 2, 3);
    SearchOk(f, "ab", {}, "ab", 0, 2);
    SearchOk(f, "bc", {}, "bcd", 0, 2);
    SearchOk(f, "sting", {}, "a string searching example consisting of",32,37);
    
    SearchOk(f, "a", {StringSearch.ignoreCase}, "a", 0, 1);
    SearchOk(f, "a", {StringSearch.ignoreCase}, "A", 0, 1);
    SearchOk(f, "A", {StringSearch.ignoreCase}, "a", 0, 1);
    SearchOk(f, "A", {StringSearch.ignoreCase}, "A", 0, 1);
    SearchOk(f, "abc", {StringSearch.ignoreCase}, "aBaCaBCabc", 4, 7);
    
    SearchOk(f, "- versus -", {StringSearch.ignoreCase}, "nd row of fills for Versus - I can't fill 20+ files requests. [1/3] - Versus - VCD Screener CD1.r27 (#/67)", 68, 78);
    SearchOk(f, "- versus -", {StringSearch.ignoreCase}, "fills for Versus - I can't fill 20+ files requests. [1/3] - Versus - VCD Screener CD1.r27 (#/67)", 58, 68);
    SearchOk(f, "- versus -", {StringSearch.ignoreCase}, "r Versus - I can't fill 20+ files requests. [1/3] - Versus - VCD Screener CD1.r27 (#/67)", 50, 60);
    SearchOk(f, "- versus -", {StringSearch.ignoreCase}, "Versus - I can't fill 20+ files requests. [1/3] - Versus - VCD Screener CD1.r27 (#/67)", 48, 58);

    FOR i := 1 TO 26 DO
      Large (i)
    END;
    
    SearchNotOk(f, "a", {}, "");
    SearchNotOk(f, "a", {}, "A");
    SearchNotOk(f, "ab", {}, "a");
    SearchNotOk(f, "ab", {}, "ac");
  END SimpleSearches;

PROCEDURE RegexpSearches (f: StringSearch.Factory);
  BEGIN
    SearchOk(f, "a|b", {}, "ab", 0, 1);
    SearchOk(f, "a|ab", {}, "ab", 0, 1); (* | is not greedy *) 
    
    SearchOk(f, "a*", {}, "b", 0, 0);
    SearchOk(f, "a*", {}, "ab", 0, 1);
    SearchOk(f, "a*", {}, "aab", 0, 2);
    SearchOk(f, "a*ab", {}, "ab", 0, 2);
    SearchOk(f, "a*ab", {}, "aab", 0, 3);
    SearchOk(f, "a*|ab", {}, "abc", 0, 1); (* | is not greedy *) 
    SearchOk(f, "a*|ab", {}, "aabc", 0, 2); (* | is not greedy *) 
    
    SearchOk(f, "(ab)?ab", {}, "ab", 0, 2);
    SearchOk(f, "(ab)?ab", {}, "ababc", 0, 4);
    
    SearchOk(f, ".", {}, "a", 0, 1);
    SearchOk(f, ".", {}, ".", 0, 1);
    SearchOk(f, "\.", {}, ".", 0, 1);
    SearchOk(f, ".*", {}, "", 0, 0);
    SearchOk(f, ".*", {}, "abc", 0, 3);
    
    SearchOk(f, "^b", {}, "bc", 0, 1);
    SearchOk(f, "^bc", {}, "bc", 0, 2);
    
    SearchOk(f, "c$", {}, "bc", 1, 2);
    SearchOk(f, "bc$", {}, "bc", 0, 2);
    
    SearchOk(f, "[abc]", {}, "abc", 0, 1);
    SearchOk(f, "[abc]?", {}, "abc", 0, 1);
    SearchOk(f, "[abc]*", {}, "abc", 0, 3);
    SearchOk(f, "[abc]+", {}, "abc", 0, 3);

    SearchOk(f, "[^abc]", {}, "abcd", 3, 4);
    SearchOk(f, "[^abc]?", {}, "abc", 0, 0);
    SearchOk(f, "[^abc]?", {}, "xabc", 0, 1);
    SearchOk(f, "[^abc]*", {}, "abc", 0, 0);

    (* test behavior of ^ at beginning of string *)
    SearchOk(f, "^a", {}, "abcd", 0, 1);
    SearchNotOk(f, "^a", {}, "Xabcd");
    SearchOk(f, "(^)a", {}, "abcd", 0, 1);
    SearchNotOk(f, "(^)a", {}, "Xabcd");
    SearchOk(f, "(^|Z)a", {}, "abcd", 0, 1);
    SearchOk(f, "(^|Z)a", {}, "XYZabcd", 2, 4);
    SearchNotOk(f, "(^|Z)a", {}, "XaZbcd");
    SearchOk(f, "(^|[ABC])a", {}, "abcd", 0, 1);
    SearchOk(f, "(^|[ABC])a", {}, "XYZAabcd", 3, 5);
    SearchOk(f, "(^|[ABC])a", {}, "XYZCabcd", 3, 5);
    SearchNotOk(f, "(^|[ABC])a", {}, "XaCbcd");

    (* test behavior of ^ and $ with region *)
    SearchOkRegion(f, "a", {}, "xax", 0, 3, 1, 2);
    SearchNotOkRegion(f, "^a", {}, "xax", 0, 3);
    SearchNotOkRegion(f, "^a", {}, "xax", 1, 3);
    SearchNotOkRegion(f, "a$", {}, "xax", 0, 3);
    SearchOkRegion(f, "a$", {}, "xax", 0, 2, 1, 2);
    
    SearchOk(f, "(a*a)*", {}, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", 0, 32);
    SearchOk(f, "X(.+)+X", {}, "=XX============================X", 1, 32);
    SearchOk(f, "(a?)*", {}, "xaaaaaaaaaaaaaaaaaaaaaaaaaaaaaay", 0, 0);
    SearchOk(f, "(a?)*", {}, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaay", 0, 30);
    
    SearchOk(f, "bar[ .-]?1", {StringSearch.ignoreCase}, "Bar 1x", 0, 5);
    SearchOk(f, "bar[ .-]?1", {StringSearch.ignoreCase}, "Bar-1x", 0, 5);
    SearchOk(f, "bar[ .-]?1", {StringSearch.ignoreCase}, "Bar.1x", 0, 5);
    SearchOk(f, "bar[ .-]?1", {StringSearch.ignoreCase}, "Bar 1x", 0, 5);
    SearchOk(f, "high( tv|_?[23])", {StringSearch.ignoreCase}, "-High TV - ", 1, 8);
    
    SearchNotOk(f, "\.", {}, "a");
    SearchNotOk(f, "a+", {}, "b");
    SearchNotOk(f, "aa+", {}, "ab");
    SearchNotOk(f, "^b", {}, "abc");
    SearchNotOk(f, "^bc", {}, "abc");
    SearchNotOk(f, "c$", {}, "bcd");
    SearchNotOk(f, "bc$", {}, "bcd");
    SearchNotOk(f, "[^abc]+", {}, "abc");
    SearchNotOk(f, "X(.+)+X", {}, "=XX============================");
    
    SearchNotOk(f, "-r-", {StringSearch.ignoreCase}, "rr-");
  END RegexpSearches;

PROCEDURE Random (seed: LONGINT; size: LONGINT): StringPtr;
  VAR
    s: StringPtr;
    i: LONGINT;
  BEGIN
    RND.PutSeed (seed);
    NEW (s, size);
    FOR i := 0 TO size-1 DO
      s[i] := CHR (RND.RND (256))
    END;
    RETURN s
  END Random;

PROCEDURE Timing (f: StringSearch.Factory; size: LONGINT);
  VAR
    matcher: StringSearch.Matcher;
    s: StringPtr;
    m: StringSearch.MatchObject;
    start, end: Time.TimeStamp;
    t: Time.Interval;
  BEGIN
    matcher := f. Compile (Object.NewLatin1 ("this is some unlikely string"), {});
    s := Random (654321, size);
    Out.String ("start search in random..."); Out.Ln;
    Time.GetTime (start);
    m := matcher. SearchChars (s^, 0, size);
    Time.GetTime (end);
    Out.String ("end search in random..."); Out.Ln;
    end.Delta(start, t);
    Out.Int (t. msecInt, 0); Out.String (" msec"); Out.Ln
  END Timing;

PROCEDURE Test*;
  BEGIN
    SimpleMatches (SubstringBF.factory);
    SimpleSearches (SubstringBF.factory);
    
    SimpleMatches (SubstringBM.factory);
    SimpleSearches (SubstringBM.factory);
    
    SimpleMatches (RegexpDFA.factory);
    SimpleSearches (RegexpDFA.factory);
    RegexpSearches (RegexpDFA.factory);
    
    (*Timing (RegexpDFA.factory, 16*1024*1024);*)
  END Test;

END LibStringSearch2.
