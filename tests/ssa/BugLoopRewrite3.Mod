MODULE BugLoopRewrite3;
<*IndexCheck := FALSE*>

IMPORT
  Out:=Out0;
  
PROCEDURE splitext (path: ARRAY OF CHAR);
  VAR
    i: INTEGER;
  BEGIN
    i := 2  (*Strings.Length (path)*);
    REPEAT
      DEC(i);
    UNTIL (path[i-1] = "/") OR (path[i] = ".");
    
    IF (path[i] = ".") THEN
      Out.Int(i, 0);
    ELSE
      Out.String("no extension");
    END;
    Out.Ln;
  END splitext;

PROCEDURE Test*();
  BEGIN
    splitext("a.");
  END Test;

END BugLoopRewrite3.
