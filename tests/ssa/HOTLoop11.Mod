MODULE HOTLoop11;

IMPORT Out:=Out0;

VAR
  g: INTEGER;
  a: ARRAY 1 OF INTEGER;
  
<*IndexCheck:=FALSE*>
PROCEDURE P (x: INTEGER): INTEGER;
  VAR
    cont: BOOLEAN;
  BEGIN
    cont := TRUE;
    LOOP
      IF cont THEN
        g := x*12; cont := FALSE;
      ELSE
        EXIT
      END
    END;
    
    RETURN a[0];
  END P;

PROCEDURE Test* ();
  BEGIN
    a[0] := 123;
    Out.Int (P(0), 0); Out.Ln;
  END Test;

END HOTLoop11.
