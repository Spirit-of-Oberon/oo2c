MODULE BugUnreachable1;

   PROCEDURE Index*(c: CHAR): LONGINT;
   BEGIN
      LOOP
      END;
      IF c = 0X THEN RETURN -1 ELSE RETURN 1 END
   END Index;

END BugUnreachable1.
