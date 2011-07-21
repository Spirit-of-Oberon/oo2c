MODULE LoopRewrite8;
<*IndexCheck:=FALSE*>

PROCEDURE FindNext* (pattern[NO_COPY], stringToSearch[NO_COPY]: ARRAY OF CHAR;
                     startPos: INTEGER;
                     VAR patternFound: BOOLEAN; VAR posOfPattern: INTEGER);
  VAR
    patternPos: INTEGER;
  BEGIN
    startPos := startPos;
    patternPos := 0;
    LOOP
      IF (pattern[patternPos] = 0X) THEN     
        (* reached end of pattern *)
        patternFound := TRUE;
        posOfPattern := startPos-patternPos;
        EXIT
      ELSIF (stringToSearch[startPos] = 0X) THEN 
        (* end of string (but not of pattern) *)
        patternFound := FALSE;
        EXIT
      ELSIF (stringToSearch[startPos] = pattern[patternPos]) THEN  
        (* characters identic, compare next one *)
        INC (startPos); 
        INC (patternPos)
      ELSE                               
        (* difference found: reset indices and restart *)
        startPos := startPos-patternPos+1; 
        patternPos := 0
      END
    END
  END FindNext;
  
END LoopRewrite8.
