MODULE LibBigInt1;

IMPORT
  RandomNumbers, Object, Object:BigInt;

CONST
  shift = 15;
  base = ASH(1,shift);
  mask = base-1;
  repeat = 1;  (* 1000 *)
  
PROCEDURE Test*;
  CONST
    f = 1000000;
  VAR
    big, a, b, div, rem, mod, z: BigInt.BigInt;
    i, x0, x1: LONGINT;
    str: Object.String8;
  BEGIN
    (* conversion LONGINT -> BigInt -> LONGINT *)
    big := BigInt.NewInt(0); ASSERT(big.ToLongInt() = 0);
    big := BigInt.NewInt(1); ASSERT(big.ToLongInt() = 1);
    big := BigInt.NewInt(mask); ASSERT(big.ToLongInt() = mask);
    big := BigInt.NewInt(base); ASSERT(big.ToLongInt() = base);
    big := BigInt.NewInt(mask*base+mask); ASSERT(big.ToLongInt() = mask*base+mask);
    big := BigInt.NewInt(base*base); ASSERT(big.ToLongInt() = base*base);
    big := BigInt.NewInt(MAX(LONGINT)); ASSERT(big.ToLongInt() = MAX(LONGINT));

    big := BigInt.NewInt(-1); ASSERT(big.ToLongInt() = -1);
    big := BigInt.NewInt(-mask); ASSERT(big.ToLongInt() = -mask);
    big := BigInt.NewInt(-base); ASSERT(big.ToLongInt() = -base);
    big := BigInt.NewInt(-(mask*base+mask)); ASSERT(big.ToLongInt() = -(mask*base+mask));
    big := BigInt.NewInt(-(base*base)); ASSERT(big.ToLongInt() = -(base*base));
    big := BigInt.NewInt(MIN(LONGINT)); ASSERT(big.ToLongInt() = MIN(LONGINT));

    (* addition *)
    a := BigInt.NewInt(-base-1); b := BigInt.NewInt(-1);
    big := a.Add(b); ASSERT(big.ToLongInt() = -base-2);
    a := BigInt.NewInt(-1); b := BigInt.NewInt(-base-1);
    big := a.Add(b); ASSERT(big.ToLongInt() = -base-2);
    a := BigInt.NewInt(-base); b := BigInt.NewInt(1);
    big := a.Add(b); ASSERT(big.ToLongInt() = -base+1);
    a := BigInt.NewInt(-1); b := BigInt.NewInt(base);
    big := a.Add(b); ASSERT(big.ToLongInt() = base-1);
    a := BigInt.NewInt(-base-1); b := BigInt.NewInt(1);
    big := a.Add(b); ASSERT(big.ToLongInt() = -base);
    a := BigInt.NewInt(-1); b := BigInt.NewInt(-base-1);
    big := a.Add(b); ASSERT(big.ToLongInt() = -base-2);
    a := BigInt.NewInt(-base-1); b := BigInt.NewInt(base+1);
    big := a.Add(b); ASSERT(big.ToLongInt() = 0);
    a := BigInt.NewInt(-1); b := BigInt.NewInt(1);
    big := a.Add(b); ASSERT(big.ToLongInt() = 0);
    a := BigInt.NewInt(base); b := BigInt.NewInt(-1);
    big := a.Add(b); ASSERT(big.ToLongInt() = base-1);
    a := BigInt.NewInt(base-1); b := BigInt.NewInt(-1);
    big := a.Add(b); ASSERT(big.ToLongInt() = base-2);
    a := BigInt.NewInt(base-1); b := BigInt.NewInt(-base+1);
    big := a.Add(b); ASSERT(big.ToLongInt() = 0);
    a := BigInt.NewInt(base); b := BigInt.NewInt(base);
    big := a.Add(b); ASSERT(big.ToLongInt() = base+base);
    a := BigInt.NewInt(base); b := BigInt.NewInt(1);
    big := a.Add(b); ASSERT(big.ToLongInt() = base+1);
    a := BigInt.NewInt(base+1); b := BigInt.NewInt(0);
    big := a.Add(b); ASSERT(big.ToLongInt() = base+1);
    a := BigInt.NewInt(0); b := BigInt.NewInt(base+1);
    big := a.Add(b); ASSERT(big.ToLongInt() = base+1);
    a := BigInt.NewInt(0); b := BigInt.NewInt(0);
    big := a.Add(b); ASSERT(big.ToLongInt() = 0);

    a := BigInt.NewInt(0); b := BigInt.NewInt(0); ASSERT(a.Cmp(b) = 0);
    a := BigInt.NewInt(0); b := BigInt.NewInt(1); ASSERT(a.Cmp(b) = -1);
    a := BigInt.NewInt(-1); b := BigInt.NewInt(0); ASSERT(a.Cmp(b) = -1);
    a := BigInt.NewInt(-1); b := BigInt.NewInt(1); ASSERT(a.Cmp(b) = -1);
    a := BigInt.NewInt(1); b := BigInt.NewInt(2); ASSERT(a.Cmp(b) = -1);
    a := BigInt.NewInt(-2); b := BigInt.NewInt(-1); ASSERT(a.Cmp(b) = -1);
    a := BigInt.NewInt(1); b := BigInt.NewInt(0); ASSERT(a.Cmp(b) = 1);
    a := BigInt.NewInt(0); b := BigInt.NewInt(-1); ASSERT(a.Cmp(b) = 1);
    a := BigInt.NewInt(1); b := BigInt.NewInt(-1); ASSERT(a.Cmp(b) = 1);
    a := BigInt.NewInt(2); b := BigInt.NewInt(1); ASSERT(a.Cmp(b) = 1);
    a := BigInt.NewInt(-1); b := BigInt.NewInt(-2); ASSERT(a.Cmp(b) = 1);
    
    FOR i := 0 TO 3*1000*repeat-1 DO
      x0 := RandomNumbers.RND(MAX(LONGINT))-MAX(LONGINT) DIV 2;
      x1 := RandomNumbers.RND(MAX(LONGINT))-MAX(LONGINT) DIV 2;
      a := BigInt.NewInt(x0); b := BigInt.NewInt(x1);
      big := a.Add(b); ASSERT(big.ToLongInt() = x0+x1);
      big := a.Sub(b); ASSERT(big.ToLongInt() = x0-x1);
    END;

    FOR i := 0 TO 10*1000*repeat-1 DO
      x0 := RandomNumbers.RND(MAX(INTEGER))-MAX(INTEGER) DIV 2;
      x1 := RandomNumbers.RND(MAX(INTEGER))-MAX(INTEGER) DIV 2;
      a := BigInt.NewInt(x0); b := BigInt.NewInt(x1);
      big := a.Mul(b); ASSERT(big.ToLongInt() = x0*x1);
    END;

    (*a := BigInt.NewInt(13); b := BigInt.NewInt(10); DivRem(a, b, div, rem);
    ASSERT(div.ToLongInt() = 1); ASSERT(rem.ToLongInt() = 3);
    a := BigInt.NewInt(-13); b := BigInt.NewInt(10); DivRem(a, b, div, rem);
    ASSERT(div.ToLongInt() = -1); ASSERT(rem.ToLongInt() = -3);
    a := BigInt.NewInt(13); b := BigInt.NewInt(-10); DivRem(a, b, div, rem);
    ASSERT(div.ToLongInt() = -1); ASSERT(rem.ToLongInt() = 3);
    a := BigInt.NewInt(-13); b := BigInt.NewInt(-10); DivRem(a, b, div, rem);
    ASSERT(div.ToLongInt() = 1); ASSERT(rem.ToLongInt() = -3);*)

    a := BigInt.NewInt(13); b := BigInt.NewInt(10); a.DivMod(b, div, mod);
    ASSERT(div.ToLongInt() = 1); ASSERT(mod.ToLongInt() = 3);
    a := BigInt.NewInt(-13); b := BigInt.NewInt(10); a.DivMod(b, div, mod);
    ASSERT(div.ToLongInt() = -2); ASSERT(mod.ToLongInt() = 7);
    a := BigInt.NewInt(13); b := BigInt.NewInt(-10); a.DivMod(b, div, mod);
    ASSERT(div.ToLongInt() = -2); ASSERT(mod.ToLongInt() = -7);
    a := BigInt.NewInt(-13); b := BigInt.NewInt(-10); a.DivMod(b, div, mod);
    ASSERT(div.ToLongInt() = 1); ASSERT(mod.ToLongInt() = -3);

    (*a := BigInt.NewInt(13*f); b := BigInt.NewInt(10*f); DivRem(a, b, div, rem);
    ASSERT(div.ToLongInt() = 1); ASSERT(rem.ToLongInt() = 3*f);
    a := BigInt.NewInt(-13*f); b := BigInt.NewInt(10*f); DivRem(a, b, div, rem);
    ASSERT(div.ToLongInt() = -1); ASSERT(rem.ToLongInt() = -3*f);
    a := BigInt.NewInt(13*f); b := BigInt.NewInt(-10*f); DivRem(a, b, div, rem);
    ASSERT(div.ToLongInt() = -1); ASSERT(rem.ToLongInt() = 3*f);
    a := BigInt.NewInt(-13*f); b := BigInt.NewInt(-10*f); DivRem(a, b, div, rem);
    ASSERT(div.ToLongInt() = 1); ASSERT(rem.ToLongInt() = -3*f);*)

    a := BigInt.NewInt(13*f); b := BigInt.NewInt(10*f); a.DivMod(b, div, mod);
    ASSERT(div.ToLongInt() = 1); ASSERT(mod.ToLongInt() = 3*f);
    a := BigInt.NewInt(-13*f); b := BigInt.NewInt(10*f); a.DivMod(b, div, mod);
    ASSERT(div.ToLongInt() = -2); ASSERT(mod.ToLongInt() = 7*f);
    a := BigInt.NewInt(13*f); b := BigInt.NewInt(-10*f); a.DivMod(b, div, mod);
    ASSERT(div.ToLongInt() = -2); ASSERT(mod.ToLongInt() = -7*f);
    a := BigInt.NewInt(-13*f); b := BigInt.NewInt(-10*f); a.DivMod(b, div, mod);
    ASSERT(div.ToLongInt() = 1); ASSERT(mod.ToLongInt() = -3*f);

    FOR i := 0 TO 5*1000*repeat-1 DO
      x0 := RandomNumbers.RND(MAX(LONGINT));
      x1 := RandomNumbers.RND(MAX(LONGINT));
      a := BigInt.NewInt(x0); b := BigInt.NewInt(x1);
      IF (RandomNumbers.RND(1000) < 500) THEN a := a.Neg(); END;
      IF (RandomNumbers.RND(1000) < 500) THEN b := b.Neg(); END;

      (*DivRem(a, b, div, rem);
      ASSERT(rem.IsZero() OR (a.Sign() = rem.Sign()));
      z := rem.Abs(); ASSERT(z.Cmp(b.Abs()) < 0);
      z := b.Mul(div); ASSERT(a.Equals(z.Add(rem)));*)
      
      a.DivMod(b, div, mod);
      ASSERT(mod.IsZero() OR (b.Sign() = mod.Sign()));
      z := mod.Abs(); ASSERT(z.Cmp(b.Abs()) < 0);
      z := b.Mul(div); ASSERT(a.Equals(z.Add(mod)));
    END;

    z := BigInt.NewInt(1000); str := z.Format( 10);
    ASSERT(str.Equals(Object.NewLatin1("1000")));
    z := BigInt.NewInt(MAX(LONGINT)); str := z.Format( 16);
    ASSERT(str.Equals(Object.NewLatin1("7FFFFFFF")));
    z := BigInt.NewInt(MIN(LONGINT)); str := z.Format( 16);
    ASSERT(str.Equals(Object.NewLatin1("-80000000")));
    z := BigInt.NewInt(127); str := z.Format( 2);
    ASSERT(str.Equals(Object.NewLatin1("1111111")));
    z := BigInt.NewInt(-1000); str := z.Format( 2);
    ASSERT(str.Equals(Object.NewLatin1("-1111101000")));
    z := BigInt.NewInt(-1000); str := z.Format( 8);
    ASSERT(str.Equals(Object.NewLatin1("-1750")));
    z := BigInt.NewInt(-1000); str := z.Format( 16);
    ASSERT(str.Equals(Object.NewLatin1("-3E8")));
    z := BigInt.NewInt(-1000); str := z.Format( 32);
    ASSERT(str.Equals(Object.NewLatin1("-V8")));

    z := BigInt.NewString("0", 10); ASSERT(z.ToLongInt() = 0);
    z := BigInt.NewString("1", 10); ASSERT(z.ToLongInt() = 1);
    z := BigInt.NewString("-1", 10); ASSERT(z.ToLongInt() = -1);
    z := BigInt.NewString(" 7FFFFFFF", 16); ASSERT(z.ToLongInt() = MAX(LONGINT));
    z := BigInt.NewString("-80000000", 16); ASSERT(z.ToLongInt() = MIN(LONGINT));
    
    FOR i := 0 TO 1*1000*repeat-1 DO
      x0 := RandomNumbers.RND(MAX(LONGINT));
      a := BigInt.NewInt(x0);
      IF (RandomNumbers.RND(1000) < 500) THEN a := a.Neg(); END;

      str := a.Format(10);
      b := BigInt.NewStr(str, 10);
      ASSERT(a.Equals(b));
    END;

    z := BigInt.NewInt(0); z := z.LShift(1); ASSERT(z.ToLongInt() = 0);
    z := BigInt.NewInt(1); z := z.LShift(1); ASSERT(z.ToLongInt() = 2);
    z := BigInt.NewInt(-1); z := z.LShift(1); ASSERT(z.ToLongInt() = -2);
    z := BigInt.NewInt(10000); z := z.LShift(1); ASSERT(z.ToLongInt() = 20000);
    z := BigInt.NewInt(-10000); z := z.LShift(1); ASSERT(z.ToLongInt() = -20000);
    z := BigInt.NewInt(1); z := z.LShift(30); ASSERT(z.ToLongInt() = ASH(1,30));
    z := BigInt.NewInt(-1); z := z.LShift(30); ASSERT(z.ToLongInt() = ASH(-1,30));
    z := BigInt.NewInt(1000); z := z.LShift(20); ASSERT(z.ToLongInt() = ASH(1000,20));
    z := BigInt.NewInt(-1000); z := z.LShift(20); ASSERT(z.ToLongInt() = ASH(-1000,20));

    z := BigInt.NewInt(3); z := z.RShift(1); ASSERT(z.ToLongInt() = 1);
    z := BigInt.NewInt(2); z := z.RShift(1); ASSERT(z.ToLongInt() = 1);
    z := BigInt.NewInt(1); z := z.RShift(1); ASSERT(z.ToLongInt() = 0);
    z := BigInt.NewInt(0); z := z.RShift(1); ASSERT(z.ToLongInt() = 0);
    z := BigInt.NewInt(-1); z := z.RShift(1); ASSERT(z.ToLongInt() = -1);
    z := BigInt.NewInt(-2); z := z.RShift(1); ASSERT(z.ToLongInt() = -1);
    z := BigInt.NewInt(-3); z := z.RShift(1); ASSERT(z.ToLongInt() = -2);
    z := BigInt.NewInt(1000); z := z.RShift(1); ASSERT(z.ToLongInt() = 500);
    z := BigInt.NewInt(1000); z := z.RShift(2); ASSERT(z.ToLongInt() = 250);
    z := BigInt.NewInt(1000); z := z.RShift(3); ASSERT(z.ToLongInt() = 125);
    z := BigInt.NewInt(1000); z := z.RShift(4); ASSERT(z.ToLongInt() = 62);
    z := BigInt.NewInt(1000); z := z.RShift(5); ASSERT(z.ToLongInt() = 31);
    z := BigInt.NewInt(1000); z := z.RShift(6); ASSERT(z.ToLongInt() = 15);
    z := BigInt.NewInt(1000); z := z.RShift(16); ASSERT(z.ToLongInt() = 0);
    z := BigInt.NewInt(1000000); z := z.RShift(16); ASSERT(z.ToLongInt() = 15);
  END Test;

END LibBigInt1.
