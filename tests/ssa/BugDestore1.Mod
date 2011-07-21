MODULE BugDestore1;

PROCEDURE Format;
  VAR
    size: LONGINT;
  BEGIN
    REPEAT
      IF FALSE THEN
        DEC(size);
      END;
      
      REPEAT
      UNTIL (size = 1);
    UNTIL (size = 0);
  END Format;

END BugDestore1.
