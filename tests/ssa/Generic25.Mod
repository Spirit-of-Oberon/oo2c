MODULE Generic25;

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
  ra: A(G.Object);
  rb: B(G.Object);
  
PROCEDURE P*(o1: G.Object; a1: G.A1);
  BEGIN
    ra.a^[0] := o1;
    ra.a^[0] := a1;
    
    rb.b^[0] := o1;
    rb.b^[0] := a1;
    
    rb.a^[0] := o1;
    rb.a^[0] := a1;
  END P;

END Generic25.
