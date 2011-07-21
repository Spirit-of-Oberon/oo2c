MODULE Short1;

PROCEDURE Test* ();
  VAR
    i8: SHORTINT; i16: INTEGER; i32: LONGINT;
    c32: UCS4CHAR; c16: LONGCHAR; c8: CHAR;
    r64: LONGREAL; r32: REAL;
  BEGIN
    i32 := 1;
    i16 := SHORT(i32);
    i8 := SHORT(i16);

    c32 := 1X;
    c16 := SHORT(c32);
    c8 := SHORT(c16);

    r64 := 1.0;
    r32 := SHORT(r64);

    i8 := SHORT(128-128);
  END Test;

END Short1.
