MODULE LibAdtString;

IMPORT 
  S := ADT:String,
  Out := Out0;

VAR
  a : S.String;
  s : ARRAY 32 OF CHAR;
  s2 : ARRAY 4 OF CHAR;
  pos : LONGINT;

PROCEDURE OutString(s : S.String);
BEGIN
  Out.String(s.array^);
END OutString;

PROCEDURE Compare(s1, s2 : S.String);
BEGIN
  Out.String("Compare(");
  OutString(s1);
  Out.String(",");
  OutString(s2);
  Out.String(")=");
  Out.Int(s1.Compare(s2), 0);
  Out.Ln;
END Compare;

PROCEDURE Successor (ch : CHAR) : CHAR;
BEGIN
  RETURN CHR(ORD(ch)+1);
END Successor;

PROCEDURE Test* ();
  BEGIN
    Out.String("NewRegion: "); OutString(S.NewRegion("0123456", 1, 3)); Out.Ln;
    
    (* String including null character *)
    a := S.NewRegion("0123456", 0, 8);
    Out.String("NewRegion: "); OutString(a); Out.String(", Length: "); Out.Int(a.length, 0); Out.Ln;
    
    (* Test some string functions *)
    Out.String("Testing String"); Out.Ln;
    Compare(S.New("ABC"), S.New("BCD"));
    Compare(S.New("ABC"), S.New("ABC"));
    Compare(S.New("BCD"), S.New("ABC"));
    Compare(S.New("ABC"), S.New("AB"));
    Compare(S.New("AB"), S.New("ABC"));
    
    a := S.New("abcde");
    Out.String("Equals: "); Out.Bool(a.Equals(S.New("abcde"))); Out.Ln;
    Out.String("GetChars: "); a.GetChars(s); Out.String(s); Out.Ln;
    Out.String("GetChars: "); a.GetChars(s2); Out.String(s2); Out.Ln;
    Out.String("GetChar: "); Out.Char(a.GetChar(3)); Out.Ln;
    Out.String("Extract: "); OutString(a.Extract(1, 3)); Out.Ln;
    Out.String("StartsWith: "); Out.Bool(a.StartsWith(S.New("abc"))); Out.Ln;
    Out.String("StartsWith: "); Out.Bool(a.StartsWith(S.New("cde"))); Out.Ln;
    Out.String("EndsWith: "); Out.Bool(a.EndsWith(S.New("abc"))); Out.Ln;
    Out.String("EndsWith: "); Out.Bool(a.EndsWith(S.New("cde"))); Out.Ln;
    Out.String("Concat: "); OutString(a.Concat(S.New("ABCDE"))); Out.Ln;
    a := S.New("-ABCAB-");
    pos := a.FindFirst(S.New("AB"), 2);
    Out.String("FindFirst: "); Out.Int(pos, 0); Out.Ln;
    pos := a.FindFirst(S.New("AB"), 5);
    Out.String("FindFirst: "); Out.Int(pos, 0); Out.Ln;
    pos := a.FindLast(S.New("AB"), 6);
    Out.String("FindLast: "); Out.Int(pos, 0); Out.Ln;
    pos := a.FindLast(S.New("AB"), 3);
    Out.String("FindLast: "); Out.Int(pos, 0); Out.Ln;
    pos := a.FindLast(S.New("AB"), 0);
    Out.String("FindLast: "); Out.Int(pos, 0); Out.Ln;
    Out.String("CompareRegion: "); Out.Int(a.CompareRegion(1, 4, S.New("ABC"), 0), 0); Out.Ln;
    Out.String("CompareRegionArray: "); Out.Int(a.CompareRegionArray(1, 4, "ABC", 0), 0); Out.Ln;
    Out.String("CompareRegionArray: "); Out.Int(a.CompareRegionArray(1, 4, "BCD", 0), 0); Out.Ln;
    Out.String("CompareRegionArray: "); Out.Int(a.CompareRegionArray(1, 4, "012", 0), 0); Out.Ln;
    
    Out.String("Map: "); OutString(a.Map(S.ToLower)); Out.Ln;
    Out.String("Map: "); OutString(a.Map(Successor)); Out.Ln;
  END Test;

END LibAdtString.
