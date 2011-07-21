MODULE NoDescriptor4;

TYPE
  R* = ARRAY [NO_DESCRIPTOR] OF CHAR;
  Ptr* = POINTER TO R;
  
PROCEDURE P*;
  VAR
    ptr: Ptr;
  BEGIN
    NEW(ptr);
  END P;

END NoDescriptor4.
