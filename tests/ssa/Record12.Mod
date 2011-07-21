MODULE Record12;

IMPORT
  Out := Out0;
  
TYPE
  R0*= RECORD      x: INTEGER; END;
  R1 = RECORD (R0) y: INTEGER; END;
  
VAR
  r: R0;
  
PROCEDURE Set(VAR r: R0);
  VAR
    r0: R0;
  BEGIN
    r0. x := 123;
    r := r0;                   (* dynamic type of r must be checked *)
  END Set;

PROCEDURE Test* ();
  BEGIN
    r. x := 99;
    Set(r);
    Out.Int (r. x, 0); Out.Ln;
  END Test;

END Record12.
