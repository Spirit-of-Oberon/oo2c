MODULE Generic1;

TYPE
  A1* = POINTER TO A1Desc;
  A1Desc* = RECORD
  END;

TYPE
  A2* = POINTER TO A2Desc;
  A2Desc* = RECORD
    (A1Desc)
  END;
  
TYPE
  B*<Base: A1> = POINTER TO BDesc<Base>;
  BDesc*<Base: A1> = RECORD 
    x: Base;
  END;

VAR
  b0-: B;
  b1-: B<A1>;
  b2-: B<A2>;

END Generic1.
