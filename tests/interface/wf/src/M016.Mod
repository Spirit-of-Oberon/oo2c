MODULE M016;

TYPE
  C0* = POINTER TO C0Desc;
  C0Desc = RECORD
  END;
  
TYPE
  C1* = POINTER TO C1Desc;
  C1Desc = RECORD
    (C0Desc)
    a-: INTEGER;
  END;

TYPE
  C2* = POINTER TO C2Desc;
  C2Desc = RECORD
    (C1Desc)
  END;

PROCEDURE (xxx: C0) P* (y: CHAR);
(** @oparam{xxx}, @oparam{y} *)
  END P;

PROCEDURE (c1: C1) P* (b: CHAR);
  END P;

END M016.
