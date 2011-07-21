MODULE Undef8;

TYPE
  R = RECORD a: INTEGER; END;
  P = POINTER TO R;
  
PROCEDURE Proc*();
  VAR
    p: P;
  BEGIN
    p.a := 123;
  END Proc;

END Undef8.
