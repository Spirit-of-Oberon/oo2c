MODULE BugLoopRewrite2;
<*IndexCheck := FALSE*>

IMPORT
  Out:=Out0;
  
PROCEDURE Length(stringVal: ARRAY OF CHAR): INTEGER;
  VAR
    i: INTEGER;
  BEGIN
    i := 0;
    WHILE (stringVal[i] # 0X) DO
      INC (i)
    END;
    RETURN i
  END Length;

PROCEDURE Delete(VAR stringVar: ARRAY OF CHAR; 
                 startPos, numberToDelete: INTEGER);
  VAR
    stringLength, i: INTEGER;
  BEGIN
    stringLength := Length (stringVar);
    i := startPos;
    REPEAT
      stringVar[i] := stringVar[i+numberToDelete];
      INC(i);
    UNTIL (i > stringLength-numberToDelete);
  END Delete;
 
PROCEDURE Test2b (str: ARRAY OF CHAR);
  BEGIN
    Out.String (str); Out.Ln;
    Delete (str, 0, 2);
    Out.String (str); Out.Ln;
  END Test2b;

PROCEDURE Test*();
  BEGIN
    Test2b ("abc");
  END Test;

END BugLoopRewrite2.
