MODULE Generic27;

IMPORT G:=Generic1;

TYPE
  A*(T: G.Object) = RECORD
    a-: POINTER TO ARRAY 1 OF T;
  END;
  B*(T: G.Object) = RECORD
    (A(T))
    b-: POINTER TO ARRAY 1 OF T;
  END;

VAR
  rb: B(G.A1);
  
PROCEDURE P*(o1: G.Object);
  BEGIN
    rb.b^[0] := o1;
  END P;

END Generic27.
