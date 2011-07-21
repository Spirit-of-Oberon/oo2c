MODULE Warshall;

<* IndexCheck := FALSE *> 

PROCEDURE Transclosure* (VAR path: ARRAY OF ARRAY OF BOOLEAN; max: LONGINT);
  VAR
    i, j, k: LONGINT;
  BEGIN
    FOR i := 0 TO max-1 DO
      FOR j := 0 TO max-1 DO
        IF path[i, j] THEN
          FOR k := 0 TO max-1 DO
            IF path[j, k] THEN
              path[i, k] := TRUE;
            END;
          END;
        END;
      END;
    END;
  END Transclosure;

END Warshall.
