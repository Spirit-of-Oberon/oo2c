MODULE LibSTRING7;

IMPORT
  Out := Out0, Object;

PROCEDURE Write (s: Object.Object);
  VAR
    c: Object.CharsLatin1;
  BEGIN
    c := s(Object.String8).CharsLatin1();
    Out.String(c^); Out.Ln;
  END Write;

PROCEDURE Test*;
  BEGIN
    Write("bar");
  END Test;
  
END LibSTRING7.
