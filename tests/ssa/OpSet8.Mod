MODULE OpSet8;

IMPORT Out := Out0;
  
PROCEDURE Write (s: SET);
  VAR
    i: LONGINT;
  BEGIN
    FOR i := MIN(SET) TO MAX(SET) DO
      IF (i IN s) THEN
        Out.Int(i, 3);
      END;
    END;
    Out.Ln;
  END Write;

PROCEDURE Range(a, b: INTEGER): SET;
  BEGIN
    RETURN {a..b};
  END Range;

PROCEDURE Test*;
  BEGIN
    Write({16..15});                     (* empty set *)
    Write({0});
    Write({0..0});                       (* one element *)
    Write({15..16});
    Write({0..31});
    Write(Range(16,15));                 (* empty set *)
    Write(Range(0,0));                   (* one element *)
    Write(Range(15,16));
    Write(Range(0,31));
  END Test;

END OpSet8.
