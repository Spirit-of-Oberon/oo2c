MODULE Cap2;

IMPORT Out := Out0;

PROCEDURE HexDigit (ch: CHAR): LONGINT;
  BEGIN
    ch := CAP (ch);
    CASE ch OF
    | "0".."9": RETURN ORD(ch)-ORD("0")
    | "A".."F": RETURN ORD(ch)+(10-ORD("A"))
    ELSE
      RETURN -1
    END;
  END HexDigit;

PROCEDURE Test* ();
  BEGIN
    Out.Int (HexDigit ("0"), 0); Out.Ln;
    Out.Int (HexDigit ("9"), 0); Out.Ln;
    Out.Int (HexDigit ("a"), 0); Out.Ln;
    Out.Int (HexDigit ("A"), 0); Out.Ln;
    Out.Int (HexDigit ("f"), 0); Out.Ln;
    Out.Int (HexDigit ("F"), 0); Out.Ln;
    Out.Int (HexDigit ("g"), 0); Out.Ln;
  END Test;

END Cap2.
