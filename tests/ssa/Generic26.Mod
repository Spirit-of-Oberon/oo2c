MODULE Generic26;

IMPORT G:=Generic1;

TYPE
  A*(T: G.Object) = RECORD
    a-: POINTER TO ARRAY 1 OF T;
  END;

VAR
  ra: A(G.A1);
  
PROCEDURE P*(o1: G.Object);
  BEGIN
    ra.a^[0] := o1;
  END P;

END Generic26.
