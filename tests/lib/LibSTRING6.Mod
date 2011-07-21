MODULE LibSTRING6;

IMPORT
  Out := Out0, String := Object;

PROCEDURE F(): STRING;
  BEGIN
    RETURN "foo";
  END F;

PROCEDURE Write (s: STRING);
  VAR
    c: String.CharsLatin1;
  BEGIN
    c := s(String.String8).CharsLatin1();
    Out.String(c^); Out.Ln;
  END Write;

PROCEDURE Test*;
  BEGIN
    Write(F());
  END Test;
  
END LibSTRING6.
