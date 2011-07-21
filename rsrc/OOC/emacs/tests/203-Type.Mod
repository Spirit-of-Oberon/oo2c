MODULE M;  (* -*-Mode: oberon-2-*- *)

TYPE
  R = RECORD
    a: BOOLEAN;
    r: RECORD
      x, y: CHAR;
      z: BOOLEAN;
    END;
    f: REAL;
  END;
  P = POINTER TO R;
  
END M.
