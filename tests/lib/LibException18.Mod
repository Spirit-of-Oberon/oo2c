MODULE LibException18;

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
  
PROCEDURE (r: R0) P1() RAISES Exception.Exception;
  END P1;

PROCEDURE (r: R1) P1() RAISES Exception.Exception;
(* allowed: same set of exceptions *)
  END P1;


PROCEDURE (r: R0) P2() RAISES Exception.Exception;
  END P2;

PROCEDURE (r: R1) P2();
(* allowed: specialization may raise a smaller set of exceptions *)
  END P2;


PROCEDURE (r: R0) P3() RAISES Exception.Exception;
  END P3;

PROCEDURE (r: R1) P3() RAISES E;
(* allowed: specialization may raise an extension of an exception declared
   for the base method *)
  END P3;

END LibException18.
