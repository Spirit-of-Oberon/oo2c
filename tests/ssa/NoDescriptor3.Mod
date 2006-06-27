MODULE NoDescriptor3;

TYPE
  R* = RECORD [NO_DESCRIPTOR]
    a*: INTEGER;
  END;
  Ptr* = POINTER TO R;
  
PROCEDURE P*;
  VAR
    ptr: Ptr;
  BEGIN
    NEW(ptr);
  END P;

END NoDescriptor3.
