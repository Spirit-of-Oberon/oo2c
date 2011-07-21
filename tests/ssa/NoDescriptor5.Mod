MODULE NoDescriptor5;

TYPE
  R* = ARRAY [NO_LENGTH_INFO] OF CHAR;
  Ptr* = POINTER TO R;
  
PROCEDURE P*;
  VAR
    ptr: Ptr;
  BEGIN
    NEW(ptr);
  END P;

END NoDescriptor5.
