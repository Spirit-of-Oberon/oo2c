MODULE LibException20;

IMPORT
  Exception;
  
TYPE
  E* = POINTER TO EDesc;
  EDesc = RECORD
    (Exception.ExceptionDesc)
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
  
PROCEDURE (r: R0) P1() RAISES E;
  END P1;

PROCEDURE (r: R1) P1() RAISES Exception.Exception;
(* not allowed: cannot raise exception that is not an extenion of one inherited
   from the base method *)
  END P1;

END LibException20.
