MODULE LibLongStringsShort1;

IMPORT
  Out := Out0, LongStrings;

PROCEDURE Write (x: ARRAY OF LONGCHAR);
  VAR
    str: ARRAY 32 OF CHAR;
  BEGIN
    LongStrings.Short (x, "?", str);
    Out.String (str); Out.Ln;
  END Write;

PROCEDURE Test* ();
  VAR
    str16: ARRAY 32 OF LONGCHAR;
  BEGIN
    str16[0] := "a"; str16[1] := "b"; str16[2] := "c"; str16[3] := 0X;
    Write (str16);

    str16[1] := 100X;
    Write (str16);
  END Test;

END LibLongStringsShort1.
