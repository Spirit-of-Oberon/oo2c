MODULE Long1;

PROCEDURE Test* ();
  VAR
    i8: SHORTINT; i16: INTEGER; i32: LONGINT;
    c16: LONGCHAR; c8: CHAR;
    r64: LONGREAL; r32: REAL;
  BEGIN
    i8 := 1;
    i16 := LONG(i8);
    i32 := LONG(i16);

    c8 := 1X;
    c16 := LONG(c8);

    r32 := 1.0;
    r64 := LONG(r32);

    i32 := LONG(MAX(LONGINT));
  END Test;

END Long1.
