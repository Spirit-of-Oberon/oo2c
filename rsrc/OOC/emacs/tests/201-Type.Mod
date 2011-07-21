MODULE M;  (* -*-Mode: oberon-2-*- *)

TYPE
  R0 = RECORD END;
  R = RECORD
    (R0)
    a: BOOLEAN;
    f: REAL;
  END;
  P = POINTER TO R;
  
END M.
