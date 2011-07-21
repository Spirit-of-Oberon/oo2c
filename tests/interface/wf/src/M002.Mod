MODULE M002;

PROCEDURE Length* (stringVal: ARRAY OF CHAR): INTEGER;
  END Length;
  
PROCEDURE Assign* (source: ARRAY OF CHAR; VAR destination: ARRAY OF CHAR);
  END Assign;
  
PROCEDURE Extract* (source: ARRAY OF CHAR; startPos, numberToExtract: INTEGER;
                    VAR destination: ARRAY OF CHAR);
  END Extract;

END M002.
