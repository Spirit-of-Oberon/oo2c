MODULE Lsh1;

IMPORT SYSTEM, Out:=Out0;

PROCEDURE Test*;
  VAR
    i8: SHORTINT;
    i16: INTEGER;
    i32: LONGINT;
    c8: CHAR;
    c16: LONGCHAR;
    b: SYSTEM.BYTE;
  BEGIN
    i8 := 64;
    Out.Int (SYSTEM.LSH(i8, 0), 12); 
    Out.Int (SYSTEM.LSH(i8, 1), 12); 
    Out.Int (SYSTEM.LSH(i8, 2), 12); 
    Out.Ln;

    i16 := 16384;
    Out.Int (SYSTEM.LSH(i16, 0), 12); 
    Out.Int (SYSTEM.LSH(i16, 1), 12); 
    Out.Int (SYSTEM.LSH(i16, 2), 12);
    Out.Ln;

    i32 := 1073741824;
    Out.Int (SYSTEM.LSH(i32, 0), 12); 
    Out.Int (SYSTEM.LSH(i32, 1), 12); 
    Out.Int (SYSTEM.LSH(i32, 2), 12);
    Out.Ln;

    c8 := 40X;
    Out.Int (ORD(SYSTEM.LSH(c8, 0)), 12); 
    Out.Int (ORD(SYSTEM.LSH(c8, 1)), 12); 
    Out.Int (ORD(SYSTEM.LSH(c8, 2)), 12); 
    Out.Ln;
    
    c16 := 4000X;
    Out.Int (ORD(SYSTEM.LSH(c16, 0)), 12); 
    Out.Int (ORD(SYSTEM.LSH(c16, 1)), 12); 
    Out.Int (ORD(SYSTEM.LSH(c16, 2)), 12); 
    Out.Ln;

    b := SYSTEM.VAL(SYSTEM.BYTE, 64);
    Out.Int (SYSTEM.VAL(SHORTINT,SYSTEM.LSH(b, 0)), 12); 
    Out.Int (SYSTEM.VAL(SHORTINT,SYSTEM.LSH(b, 1)), 12); 
    Out.Int (SYSTEM.VAL(SHORTINT,SYSTEM.LSH(b, 2)), 12); 
    Out.Ln;

    Out.Ln;

    i8 := 2;
    Out.Int (SYSTEM.LSH(i8, 0), 12); 
    Out.Int (SYSTEM.LSH(i8, -1), 12); 
    Out.Int (SYSTEM.LSH(i8, -2), 12); 
    Out.Ln;

    i16 := 2;
    Out.Int (SYSTEM.LSH(i16, 0), 12); 
    Out.Int (SYSTEM.LSH(i16, -1), 12); 
    Out.Int (SYSTEM.LSH(i16, -2), 12);
    Out.Ln;

    i32 := 2;
    Out.Int (SYSTEM.LSH(i32, 0), 12); 
    Out.Int (SYSTEM.LSH(i32, -1), 12); 
    Out.Int (SYSTEM.LSH(i32, -2), 12);
    Out.Ln;

    c8 := 2X;
    Out.Int (ORD(SYSTEM.LSH(c8, 0)), 12); 
    Out.Int (ORD(SYSTEM.LSH(c8, -1)), 12); 
    Out.Int (ORD(SYSTEM.LSH(c8, -2)), 12); 
    Out.Ln;
    
    c16 := 2X;
    Out.Int (ORD(SYSTEM.LSH(c16, 0)), 12); 
    Out.Int (ORD(SYSTEM.LSH(c16, -1)), 12); 
    Out.Int (ORD(SYSTEM.LSH(c16, -2)), 12); 
    Out.Ln;

    b := SYSTEM.VAL(SYSTEM.BYTE, 2);
    Out.Int (SYSTEM.VAL(SHORTINT,SYSTEM.LSH(b, 0)), 12); 
    Out.Int (SYSTEM.VAL(SHORTINT,SYSTEM.LSH(b, -1)), 12); 
    Out.Int (SYSTEM.VAL(SHORTINT,SYSTEM.LSH(b, -2)), 12); 
    Out.Ln;
  END Test;

END Lsh1.
