MODULE BugLoopRewrite1;

<*IndexCheck:=FALSE*>

PROCEDURE FindFoo (pattern, stringToSearch: ARRAY OF CHAR; startPos: INTEGER;
                   VAR patternFound: BOOLEAN; VAR posOfPattern: INTEGER);
  VAR
    patternPos: INTEGER;
  BEGIN
    patternPos := 0;
    LOOP
      IF (pattern[patternPos] = 0X) THEN     
        patternFound := TRUE;
        posOfPattern := startPos-patternPos;
        EXIT
      ELSE                               
        startPos := startPos-patternPos+1; 
        patternPos := 0
      END
    END
  END FindFoo;
  
END BugLoopRewrite1.
