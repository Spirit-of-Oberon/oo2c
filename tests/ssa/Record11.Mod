MODULE Record11;

TYPE
  R0 = RECORD      x: INTEGER; END;
  R1 = RECORD (R0) y: INTEGER; END;
  
VAR
  r: R1;
  
PROCEDURE Set(VAR r: R0);
  VAR
    r0: R0;
  BEGIN
    r0. x := 123;
    <*TypeGuard:=TRUE*>
    r := r0;                   (* dynamic type of r must be checked *)
  END Set;

PROCEDURE Test* ();
  BEGIN
    Set(r);
  END Test;

END Record11.
