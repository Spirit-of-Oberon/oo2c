MODULE Incl1;

IMPORT Out:=Out0;
  
PROCEDURE Test* ();
  VAR
    s: SET;
  BEGIN
    s := {};
    INCL(s,0);
    Out.Set(s); Out.Ln;
    INCL(s,31);
    Out.Set(s); Out.Ln;
    EXCL(s,0);
    Out.Set(s); Out.Ln;
    EXCL(s,31);
    Out.Set(s); Out.Ln;
  END Test;

END Incl1.
