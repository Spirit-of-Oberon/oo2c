MODULE Atomic1;

IMPORT
  Out, RT0, SYSTEM;

TYPE
  Name = POINTER TO ARRAY OF CHAR;

  (* Atomic types : these contain no pointers to heap objects *)

  A1 = RECORD 
  END; 

  A2 = RECORD
    a : LONGINT;
  END;

  A3 = RECORD
    a : ARRAY 3 OF A2;
  END;

  A4 = RECORD
    a : ARRAY 16 OF CHAR;
  END;

  A5 = RECORD
    a : SYSTEM.ADDRESS;
  END;

  A6 = RECORD [NO_TRACED_POINTERS]
    a : POINTER TO A6;
  END;

  A7(T : RT0.Object) = RECORD
  END;

  A8 = ARRAY OF CHAR;

  A9 = ARRAY 128 OF CHAR;

  A10 = ARRAY [NO_TRACED_POINTERS] OF Name;

  (* Non-atomic types : these contain pointers to heap objects *)

  P1 = RECORD 
    a : SYSTEM.PTR;
  END;

  P2 = RECORD (* pointer to record *)
    a : POINTER TO P2;
  END;

  P3 = RECORD (* pointer to array *)
    a : POINTER TO ARRAY OF CHAR;
  END;

  P4 = RECORD (* pointer via type name *)
    a : Name;
  END;

  P5(T : RT0.Object) = RECORD (* type variable *)
    a : T;
  END;

  P6 = RECORD (P2) (* extension with inherited pointer *)
  END;

  P7 = RECORD (A1) (* extension without inherited pointer *)
    b : Name;
  END;

  P8 = RECORD (* aggregate containing pointer *)
    a : LONGINT;
    b : P4;
  END;

  P9 = RECORD (* aggregate containing pointer *)
    a : LONGINT;
    b : P8;
  END;

  P10 = ARRAY OF Name;

  P11 = ARRAY 128 OF Name;

  P12 = RECORD
    a : LONGINT;
    b : P11;
  END;

VAR
  module : RT0.Module;

PROCEDURE P(name : ARRAY OF CHAR);
VAR
  s : RT0.Struct;
BEGIN
  s := RT0.ThisType(module, name);
  ASSERT(s # NIL);
  Out.String(name); 
  Out.String(" : ");
  Out.Bool(RT0.flagAtomic IN s.flags);
  Out.Ln;
END P;
 
PROCEDURE Test*;
BEGIN
  module := RT0.ThisModule("Atomic1");
 
  P("A1");
  P("A2");
  P("A3");
  P("A4");
  P("A5");
  P("A6");
  P("A7");
  P("A8");
  P("A9");
  P("A10");

  P("P1");
  P("P2");
  P("P3");
  P("P4");
  P("P5");
  P("P6");
  P("P7");
  P("P8");
  P("P9");
  P("P10");
  P("P11");
  P("P12");
END Test;

END Atomic1.


