MODULE LibException19;

IMPORT
  Exception;
  
TYPE
  E* = POINTER TO EDesc;
  EDesc = RECORD
    (Exception.CheckedDesc)
  END;

TYPE
  R0* = POINTER TO R0Desc;
  R0Desc = RECORD
  END;

TYPE
  R1* = POINTER TO R1Desc;
  R1Desc = RECORD
    (R0Desc) 
  END;
  
PROCEDURE (r: R0) P1();
  END P1;

PROCEDURE (r: R1) P1() RAISES Exception.Exception;
(* not allowed: cannot raise more exceptions than the base method *)
  END P1;

END LibException19.
