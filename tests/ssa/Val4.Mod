MODULE Val4;

IMPORT SYSTEM, Out := Out0;

PROCEDURE Test* ();
  CONST
    real = 1.0;
    set = {0, 15, 16, 31};
  VAR
    r32, rt: REAL;
    i32: LONGINT;
    s32, rs: SET;
  BEGIN
    r32 := real;
    i32 := SYSTEM.VAL(LONGINT,r32);
    Out.Int(i32, 0); Out.Ln;
    rt := SYSTEM.VAL(REAL, i32);
    ASSERT (rt = real);
    
    s32 := set;
    i32 := SYSTEM.VAL(LONGINT,s32);
    Out.Int(i32, 0); Out.Ln;
    rs := SYSTEM.VAL(SET, i32);
    ASSERT (rs = set);
  END Test;

END Val4.
