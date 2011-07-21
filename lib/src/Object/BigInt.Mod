(*	$Id: BigInt.Mod,v 1.8 2005/01/18 09:26:34 mva Exp $	*)
MODULE Object:BigInt [OOC_EXTENSIONS];
(*  Implements integer values of arbitrary magnitude.
    Copyright (C) 2002-2005  Michael van Acken

    This module is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public License
    as published by the Free Software Foundation; either version 2 of
    the License, or (at your option) any later version.

    This module is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with OOC. If not, write to the Free Software Foundation,
    59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*)


(* This module is a reformulation of (parts of) Python's @file{longobject.c}
   in Oberon-2.  Optimizations like Karatsuba multiplication and string
   conversion for power of two base have been omitted.  All errors are mine,
   of course.  *)
   
IMPORT
  S := SYSTEM, CharClass, Strings, Object, Object:Boxed, IO, ADT:Storable;
  
TYPE
  Digit = INTEGER;
  TwoDigits = LONGINT;
  
CONST
  shift = 15;                            (* minimum is 6 *)
  base = ASH(1,shift);
  mask = base-1;

TYPE
  BigInt* = POINTER TO BigIntDesc;
  DigitArray = POINTER TO ARRAY OF Digit;
  BigIntDesc = RECORD
    (* Stores an integer number of arbitrary size.  The absolute value of a
       number is equal to @samp{SUM(for @var{i}=0 through ABS(@ofield{size})-1)
       digit[@var{i}]*2^(shift*@var{i})}.  Negative numbers are represented
       with @samp{@ofield{size}<0}, and zero by @samp{@ofield{size}=0}.  In a
       normalized number, @samp{@ofield{digit}[ABS(@ofield{size})-1]} (the most
       significant digit) is never zero.  For all valid @var{i}, @samp{0 <=
       @ofield{digit}[@var{i}] <= mask}.  *)
    (Boxed.ObjectDesc)
    size: LONGINT;
    digit: DigitArray;
  END;

VAR
  zero-: BigInt;
  one-: BigInt;
  powerOf2: ARRAY 37 OF SHORTINT;
  
PROCEDURE NewInstance (size: LONGINT): BigInt;
  VAR
    big: BigInt;
  BEGIN
    NEW(big);
    big.size := size;
    NEW(big.digit, ABS(size));
    RETURN big;
  END NewInstance;

PROCEDURE Normalize (big: BigInt);
  VAR
    i, j: LONGINT;
  BEGIN
    j := ABS(big.size);
    i := j;
    WHILE (i # 0) & (big.digit[i-1] = 0) DO
      DEC (i);
    END;
    IF (i # j) THEN
      IF (big.size < 0) THEN
        i := -i;
      END;
      big.size := i;
    END;
  END Normalize;

(*PROCEDURE Dump (msg: ARRAY OF CHAR; big: BigInt);
  VAR
    i: LONGINT;
  BEGIN
    Out.String (msg);
    Out.String(": size=");
    Out.LongInt(big.size,0);
    Out.String (", digits=");
    FOR i := 0 TO ABS(big.size)-1 DO
      Out.Int(big.digit[i], 0);
      Out.Char(" ");
    END;
    Out.String (", base=");
      Out.LongInt(base, 0);
    Out.Ln;
  END Dump;*)

PROCEDURE AddAbs (a, b: BigInt): BigInt;
(**Adds the absolute values of two integers.  *)
  VAR
    z: BigInt;
    i, carry, sizeA, sizeB: LONGINT;
  BEGIN
    IF (ABS(a.size) < ABS(b.size)) THEN
      z := a; a := b; b := z;
    END;
    sizeA := ABS(a.size); sizeB := ABS(b.size);

    z := NewInstance(sizeA+1);
    carry := 0;
    i := 0;
    WHILE (i # sizeB) DO
      INC(carry, a.digit[i]+b.digit[i]);
      z.digit[i] := SHORT(carry MOD base);
      carry := carry DIV base;
      INC(i);
    END;
    WHILE (i # sizeA)  DO
      INC(carry, a.digit[i]);
      z.digit[i] := SHORT(carry MOD base);
      carry := carry DIV base;
      INC(i);
    END;
    z.digit[i] := SHORT(carry);
    Normalize(z);
    RETURN z;
  END AddAbs;

PROCEDURE NewInt* (int: LONGINT): BigInt;
  CONST
    maxDigits = (SIZE(LONGINT)*8+shift-2) DIV shift;
  VAR
    sign, size, i: LONGINT;
    big: BigInt;
  BEGIN
    IF (int = 0) THEN
      RETURN zero;
    ELSE
      sign := 1;
      IF (int < 0) THEN
        IF (int = MIN(LONGINT)) THEN (* handle overflow for -MIN(LONGINT) *)
          big := NewInt(int+1);
          IF (big.digit[0] = mask) THEN
            big := AddAbs(big, one);
            big.size := -big.size;
          ELSE
            INC(big.digit[0]);
          END;
          RETURN big;
        ELSE
          int := -int;
          sign := -1;
        END;
      END;
      IF (base = ASH(1,15)) THEN         (* unwind loop for standard case *)
        big := NewInstance(3);             (* number not normalized *)
        big.digit[0] := SHORT(int MOD base);
        big.digit[1] := SHORT((int DIV base) MOD base);
        big.digit[2] := SHORT(int DIV (base*base));
        IF (big.digit[2] # 0) THEN
          size := 3;
        ELSIF (big.digit[1] # 0) THEN
          size := 2;
        ELSE
          size := 1;
        END;
      ELSE                               (* loop for non-standard base *)
        big := NewInstance(maxDigits);
        i := 0;
        WHILE (int # 0) DO
          big.digit[i] := SHORT(int MOD base);
          int := int DIV base;
          INC (i);
        END;
        size := i;
      END;
      big.size := size*sign;
      RETURN big;
    END;
  END NewInt;

PROCEDURE (a: BigInt) Copy*(): BigInt;
  VAR
    size: LONGINT;
    z: BigInt;
  BEGIN
    size := ABS(a.size);
    z := NewInstance(a.size);
    S.MOVE(S.ADR(a.digit^),S.ADR(z.digit^),size*SIZE(Digit));
    RETURN z;
  END Copy;

PROCEDURE (a: BigInt) HashCode*(): Object.Hash;
  VAR
    len, p: LONGINT;
    x: Object.Hash;
  BEGIN
    len := ABS(a.size);
    IF (len = 0) THEN
      RETURN 0;
    ELSE
      x := ASH(a.digit[0], 7);
      p := 0;
      WHILE (p # len) DO
<* PUSH; OverflowCheck := FALSE *>
        x := S.VAL(Object.Hash, S.VAL(SET, 1000003*x) /
                   S.VAL(SET, LONG(a.digit[p])));
<* POP *>
        INC(p);
      END;
      x := S.VAL(Object.Hash, S.VAL(SET,x) / S.VAL(SET,len));
      RETURN x
    END;
  END HashCode;

PROCEDURE (a: BigInt) Equals* (b: Object.Object): BOOLEAN;
  VAR
    i: LONGINT;
  BEGIN
    IF (b = NIL) THEN
      RETURN FALSE;
    END;
    
    WITH b: BigInt DO
      IF (a.size # b.size) THEN
        RETURN FALSE;
      ELSE
        FOR i := 0 TO ABS(a.size)-1 DO
          IF (a.digit[i] # b.digit[i]) THEN
            RETURN FALSE;
          END;
        END;
        RETURN TRUE;
      END;
    ELSE
      RETURN FALSE;
    END;
  END Equals;

PROCEDURE (a: BigInt) IsZero*(): BOOLEAN;
  BEGIN
    RETURN (a.size = 0);
  END IsZero;

PROCEDURE (a: BigInt) NonZero*(): BOOLEAN;
  BEGIN
    RETURN (a.size # 0);
  END NonZero;

PROCEDURE (a: BigInt) ToLongInt*(): LONGINT;
  VAR
    int, i: LONGINT;
  BEGIN
    int := 0;
    FOR i := ABS(a.size)-1 TO 0 BY -1 DO
      int := int*base+a.digit[i];
    END;
    IF (a.size < 0) THEN
      RETURN -int;
    ELSE
      RETURN int;
    END;
  END ToLongInt;

PROCEDURE (a: BigInt) Sign*(): LONGINT;
  BEGIN
    IF (a.size > 0) THEN
      RETURN 1;
    ELSIF (a.size < 0) THEN
      RETURN -1;
    ELSE
      RETURN 0;
    END;
  END Sign;

PROCEDURE (a: BigInt) Cmp* (b: Object.Object): LONGINT;
  VAR
    i, res: LONGINT;
  BEGIN
    WITH b: BigInt DO
      IF (a.size < b.size) THEN
        RETURN -1;
      ELSIF (a.size > b.size) THEN
        RETURN 1;
      ELSE
        i := ABS(a.size);
        REPEAT
          DEC(i);
        UNTIL (i < 0) OR (a.digit[i] # b.digit[i]);
        IF (i < 0) THEN
          RETURN 0;
        ELSIF (a.digit[i] < b.digit[i]) THEN
          res := -1;
        ELSE
          res := 1;
        END;
        IF (a.size < 0) THEN
          RETURN -res;
        ELSE
          RETURN res;
        END;
      END;
    END;
  END Cmp;

PROCEDURE (a: BigInt) Abs*(): BigInt;
  VAR
    size: LONGINT;
    z: BigInt;
  BEGIN
    IF (a.size >= 0) THEN
      RETURN a;
    ELSE
      size := -a.size;
      z := NewInstance(size);
      S.MOVE(S.ADR(a.digit^),
                  S.ADR(z.digit^),
                  size*SIZE(Digit));
      RETURN z;
    END;
  END Abs;

PROCEDURE (a: BigInt) Neg*(): BigInt;
  VAR
    z: BigInt;
  BEGIN
    z := a.Copy();
    z.size := -z.size;
    RETURN z;
  END Neg;

PROCEDURE SubAbs (a, b: BigInt): BigInt;
(**Subtract the absolute value of two integers.  *)
  VAR
    z: BigInt;
    i, borrow, sign, sizeA, sizeB: LONGINT;
  BEGIN
    sign := 1;
    IF (ABS(a.size) < ABS(b.size)) THEN
      z := a; a := b; b := z;
      sign := -1;
    ELSIF (ABS(a.size) = ABS(b.size)) THEN
      (* find highest digit where a and b differ *)
      i := ABS(a.size)-1;
      WHILE (i >= 0) & (a.digit[i] = b.digit[i]) DO
        DEC(i);
      END;
      IF (i < 0) THEN
        RETURN zero;
      ELSIF (a.digit[i] < b.digit[i]) THEN
        z := a; a := b; b := z;
        sign := -1;
      END;
    END;
    sizeA := ABS(a.size); sizeB := ABS(b.size);
    
    z := NewInstance(sizeA);
    borrow := 0;
    i := 0;
    WHILE (i # sizeB) DO
      borrow := a.digit[i]-b.digit[i]-borrow;
      z.digit[i] := SHORT(borrow MOD base);
      borrow := (borrow DIV base) MOD 2; (* keep only 1 sign bit *)
      INC(i);
    END;
    WHILE (i # sizeA)  DO
      borrow := a.digit[i]-borrow;
      z.digit[i] := SHORT(borrow MOD base);
      borrow := (borrow DIV base) MOD 2;
      INC(i);
    END;
    ASSERT(borrow = 0);
    IF (sign < 0) THEN
      z.size := -z.size;
    END;
    Normalize(z);
    RETURN z;
  END SubAbs;

PROCEDURE MulAbs (a, b: BigInt): BigInt;
(* Grade school multiplication, ignoring the signs.  * Returns the absolute
   value of the product.  *)
  VAR
    sizeA, sizeB, i, j, f, carry: LONGINT;
    z: BigInt;
  BEGIN
    sizeA := ABS(a.size); sizeB := ABS(b.size);
    
    z := NewInstance(sizeA+sizeB);
    FOR i := 0 TO sizeA+sizeB-1 DO
      z.digit[i] := 0;
    END;
    
    i := 0;
    WHILE (i # sizeA) DO
      f := a.digit[i];
      carry := 0;
      j := 0;
      WHILE (j # sizeB) DO
        INC (carry, z.digit[i+j]+b.digit[j]*f);
        ASSERT(carry >= 0);
        z.digit[i+j] := SHORT(carry MOD base);
        carry := carry DIV base;
        INC(j);
      END;
      WHILE (carry # 0) DO
        INC(carry, z.digit[i+j]);
        ASSERT(carry >= 0);
        z.digit[i+j] := SHORT(carry MOD base);
        carry := carry DIV base;
        INC(j);
      END;
      INC(i);
    END;
    Normalize(z);
    RETURN z;
  END MulAbs;

PROCEDURE (a: BigInt) Add* (b: BigInt): BigInt;
  VAR
    z: BigInt;
  BEGIN
    IF (a.size < 0) THEN
      IF (b.size < 0) THEN
        z := AddAbs(a, b);
        z.size := -z.size;
        RETURN z;
      ELSE
        RETURN SubAbs(b, a);
      END;
    ELSE
      IF (b.size < 0) THEN
        RETURN SubAbs(a, b);
      ELSE
        RETURN AddAbs(a, b);
      END;
    END;
  END Add;

PROCEDURE (a: BigInt) Sub* (b: BigInt): BigInt;
  VAR
    z: BigInt;
  BEGIN
    IF (a.size < 0) THEN
      IF (b.size < 0) THEN
        z := SubAbs(a, b);
      ELSE
        z := AddAbs(a, b);
      END;
      z.size := -z.size;
      RETURN z;
    ELSE
      IF (b.size < 0) THEN
        RETURN AddAbs(a, b);
      ELSE
        RETURN SubAbs(a, b);
      END;
    END;
  END Sub;

PROCEDURE (a: BigInt) Mul* (b: BigInt): BigInt;
  VAR
    z: BigInt;
  BEGIN
    z := MulAbs(a, b);
    IF ((a.size < 0) # (b.size < 0)) THEN
      z.size := -z.size;
    END;
    RETURN z;
  END Mul;

PROCEDURE InplaceDivRem1 (VAR pout: ARRAY OF Digit;
                          VAR pin: ARRAY OF Digit;
                          size: LONGINT; n: Digit): Digit;
(* Divide long @oparam{pin}, with @oparam{size} digits, by non-zero digit
   @oparam{n}, storing quotient in @oparam{pout}, and returning the remainder.
   @oparam{pin[0]} and @oparam{pout[0]} point at the LSD.  It's OK for
   @samp{pin=pout} on entry, which saves oodles of mallocs/frees in
   long_format, but that should be done with great care since longs are
   immutable.  *)
  VAR
    rem, hi: LONGINT;
  BEGIN
    ASSERT((n > 0) & (n < base));
    
    rem := 0;
    WHILE (size > 0) DO
      DEC(size);
      rem := rem*base + pin[size];
      hi := rem DIV n;
      pout[size] := SHORT(hi);
      DEC(rem, hi*n);
    END;
    RETURN SHORT(rem);
  END InplaceDivRem1;

PROCEDURE DivRem1 (a: BigInt; n: Digit; VAR rem: Digit): BigInt;
(* Divide a long integer by a digit, returning both the quotient
   (as function result) and the remainder (through *prem).
   The sign of a is ignored; n should not be zero. *)
  VAR
    size: LONGINT;
    z: BigInt;
  BEGIN
    ASSERT((n > 0) & (n < base));

    size := ABS(a.size);
    z := NewInstance(size);
    rem := InplaceDivRem1(z.digit^, a.digit^, size, n);
    Normalize(z);
    RETURN z;
  END DivRem1;

PROCEDURE MulAdd1 (a: BigInt; n, add: Digit): BigInt;
(* Multiply by a single digit and add a single digit, ignoring the sign. *)
  VAR
    sizeA, carry, i: LONGINT;
    z: BigInt;
  BEGIN
    sizeA := ABS(a.size);
    z := NewInstance(sizeA+1);
    carry := add;
    i := 0;
    WHILE (i # sizeA) DO
      INC(carry, LONG(a.digit[i])*n);
      z.digit[i] := SHORT(carry MOD base);
      carry := carry DIV base;
      INC(i);
    END;
    z.digit[i] := SHORT(carry);
    Normalize(z);
    RETURN z;
  END MulAdd1;

PROCEDURE DivRemAbs (v1, w1: BigInt; VAR rem: BigInt): BigInt;
(* Unsigned long division with remainder -- the algorithm.  *)

  VAR
    sizeV, sizeW, j, k, i: LONGINT;
    d, vj, zz: Digit;
    v, w, a: BigInt;
    q, z, carry: TwoDigits;
  BEGIN
    sizeV := ABS(v1.size); sizeW := ABS(w1.size);
    d := SHORT(base DIV (LONG(w1.digit[sizeW-1])+1));
    v := MulAdd1(v1, d, 0);
    w := MulAdd1(w1, d, 0);
    
    ASSERT((sizeV >= sizeW) & (sizeW > 1));
    ASSERT(sizeW = ABS(w.size));
    sizeV := ABS(v.size);
    a := NewInstance(sizeV-sizeW+1);

    j := sizeV;
    k := a.size-1;
    WHILE (k >= 0) DO
      IF (j >= sizeV) THEN
        vj := 0;
      ELSE
        vj := v.digit[j];
      END;
      carry := 0;

      IF (vj = w.digit[sizeW-1]) THEN
        q := mask;
      ELSE
        q := (LONG(vj)*base + v.digit[j-1]) DIV w.digit[sizeW-1];
      END;
      WHILE (w.digit[sizeW-2]*q >
             ((LONG(vj)*base + v.digit[j-1] -
              q*w.digit[sizeW-1])*base) + v.digit[j-2]) DO
        DEC(q);
      END;

      i := 0;
      WHILE (i < sizeW) & (i+k < sizeV) DO
        z := w.digit[i]*q;
        zz := SHORT(z DIV base);
        INC(carry, v.digit[i+k] - z + LONG(zz)*base);
        v.digit[i+k] := SHORT(carry MOD base);
        carry := ASH(carry, -shift);
        DEC(carry, zz);
        INC(i);
      END;

      IF (i+k < sizeV) THEN
        INC(carry, v.digit[i+k]);
        v.digit[i+k] := 0;
      END;

      IF (carry = 0) THEN
        a.digit[k] := SHORT(q);
      ELSE
        ASSERT(carry = -1);
        a.digit[k] := SHORT(q)-1;
        carry := 0;
        i := 0;
        WHILE (i < sizeW) & (i+k < sizeV) DO
          INC(carry, v.digit[i+k] + w.digit[i]);
          v.digit[i+k] := SHORT(carry MOD base);
          carry := ASH(carry, -shift);
          INC (i);
        END;
      END;
      DEC(j);
      DEC(k);
    END;
    Normalize(a);
    rem := DivRem1(v, d, d);
    RETURN a;
  END DivRemAbs;

PROCEDURE DivRem (a: BigInt; b: BigInt; VAR div, rem: BigInt);
  VAR
    sizeA, sizeB: LONGINT;
    remDigit: Digit;
    z: BigInt;
  BEGIN
    sizeA := ABS(a.size); sizeB := ABS(b.size);

    <*PUSH; Assertions:=TRUE*>
    ASSERT(sizeB # 0);                   (* division by zero? *)
    <*POP*>
    IF (sizeA < sizeB) OR
       (sizeA = sizeB) & (a.digit[sizeA-1] < b.digit[sizeB-1]) THEN
      (* |a| < |b| *)
      div := zero; 
      rem := a;
    ELSE
      IF (sizeB = 1) THEN
        remDigit := 0;
        z := DivRem1(a, b.digit[0], remDigit);
        rem := NewInt(remDigit);
      ELSE
        z := DivRemAbs(a, b, rem);
      END;
      
      (* Set the signs.  The quotient z has the sign of a*b; the remainder r
         has the sign of a, so a = b*z + r.  *)
      IF ((a.size < 0) # (b.size < 0)) THEN
	z.size := -z.size;
      END;
      IF (a.size < 0) & (rem.size # 0) THEN
	rem.size := -rem.size;
      END;
      div := z;
    END;
  END DivRem;

PROCEDURE (v: BigInt) DivMod* (w: BigInt; VAR div, mod: BigInt);
  BEGIN
    DivRem(v, w, div, mod);
    IF (mod.size < 0) & (w.size > 0) OR (mod.size > 0) & (w.size < 0) THEN
      mod := mod.Add(w);
      div := div.Sub(one);
    END;
  END DivMod;

PROCEDURE (v: BigInt) Div* (w: BigInt): BigInt;
  VAR
    div, mod: BigInt;
  BEGIN
    v.DivMod(w, div, mod);
    RETURN div;
  END Div;

PROCEDURE (v: BigInt) Mod* (w: BigInt): BigInt;
  VAR
    div, mod: BigInt;
  BEGIN
    v.DivMod(w, div, mod);
    RETURN mod;
  END Mod;

PROCEDURE (a: BigInt) Format* (outputBase: Digit): Object.String8;
(* Convert a long int object to a string, using a given conversion base.
   Return a string object.  *)
  VAR
    sizeA, i, bits, size, power, newpow, ntostore, d, pos, baseBits,
        accumBits: LONGINT;
    accum: TwoDigits;
    str: POINTER TO ARRAY OF CHAR;
    powbase, rem, nextrem: Digit;
    c: CHAR;
    scratch: BigInt;
  BEGIN
    sizeA := ABS(a.size);
    ASSERT((outputBase >= 2) & (outputBase <= 36));

    (* Compute a rough upper bound for the length of the string *)
    i := outputBase;
    bits := 0;
    WHILE (i > 1) DO
      INC(bits);
      i := i DIV 2;
    END;
    i := 5 + (sizeA*shift+bits-1) DIV bits;
    NEW (str, i);
    pos := i;
    
    IF (sizeA = 0) THEN
      RETURN Object.NewLatin1("0");

    ELSIF (powerOf2[outputBase] > 0) THEN
      baseBits := powerOf2[outputBase];
      accum := 0;
      accumBits := 0;
      i := 0;
      
      WHILE (i # sizeA) DO
        INC(accum, ASH(a.digit[i], accumBits));
        INC(accumBits, shift);
        ASSERT(accumBits >= baseBits);
        REPEAT
          d := accum MOD outputBase;  (* expensive, a mask op would do *)
          IF (d < 10) THEN
            c := CHR(d+ORD("0"));
          ELSE
            c := CHR(d+(ORD("A")-10));
          END;
          DEC(pos);
	  str[pos] := c;
          DEC(accumBits, baseBits);
          accum := ASH(accum, -baseBits);
        UNTIL (accumBits < baseBits) & (i < sizeA-1) OR (accum = 0);
        INC(i);
      END;
      IF (a.size < 0) THEN
        DEC(pos);
        str[pos] := "-";
      END;
      RETURN Object.NewLatin1Region(str^, pos, LEN(str^));
      
    ELSE
      (* powbase <- largest power of outputBase that fits in a digit. *)
      powbase := outputBase;  (* powbase == outputBase ** power *)
      power := 1;
      LOOP
	newpow := powbase * LONG(outputBase);
        IF (newpow > base) THEN
          EXIT;
        END;
	powbase := SHORT(newpow);
	INC(power);
      END;

      (* Get a scratch area for repeated division. *)
      scratch := a.Copy();
      size := sizeA;
      
      (* Repeatedly divide by powbase. *)
      REPEAT
	ntostore := power;
	rem := InplaceDivRem1(scratch.digit^, scratch.digit^, size, powbase);
	IF (scratch.digit[size-1] = 0) THEN
          DEC(size);
        END;
        
	(* Break rem into digits. *)
	ASSERT(ntostore > 0);
	REPEAT
	  nextrem := SHORT(rem DIV outputBase);
	  d := rem - nextrem*outputBase;
          IF (d < 10) THEN
            c := CHR(d+ORD("0"));
          ELSE
            c := CHR(d+(ORD("A")-10));
          END;
          DEC(pos);
	  str[pos] := c;
	  rem := nextrem;
	  DEC(ntostore);
	  (* Termination is a bit delicate:  must not
	     store leading zeroes, so must get out if
	     remaining quotient and rem are both 0. *)
	UNTIL (ntostore = 0) OR ((size = 0) & (rem = 0));
      UNTIL (size = 0);
      IF (a.size < 0) THEN
        DEC(pos);
        str[pos] := "-";
      END;
      RETURN Object.NewLatin1Region(str^, pos, LEN(str^));
    END;
  END Format;

PROCEDURE (a: BigInt) ToString*(): Object.String8;
  BEGIN
    RETURN a.Format(10);
  END ToString;

PROCEDURE NewLatin1Region*(str[NO_COPY]: ARRAY OF CHAR; start, end: LONGINT;
                           inputBase: LONGINT): BigInt;
(**Result is @code{NIL} if the string interval does not match the syntax for
   integer numbers.
   
   @precond
   @samp{@oparam{start} <= @oparam{end}}
   @end precond *)
  VAR
    sign, d, firstDigit: LONGINT;
    z: BigInt;
  BEGIN
    sign := 1;
    ASSERT((2 <= inputBase) & (inputBase <= 36));

    (* skip leading whitespace *)
    WHILE (start # end) & CharClass.IsWhiteSpace(str[start]) DO
      INC(start);
    END;

    (* handle sign *)
    IF (start # end) THEN
      IF (str[start] = "-") THEN
        sign := -1;
        INC(start);
      ELSIF (str[start] = "+") THEN
        INC(start);
      END;
    END;

    z := NewInstance(0);
    firstDigit := start;
    WHILE (start # end) DO
      d := ORD(str[start]);
      IF (d <= ORD("9")) THEN
        DEC(d, ORD("0"));
      ELSIF (d >= ORD("a")) THEN
        DEC(d, ORD("a")-10);
      ELSIF (d >= ORD("A")) THEN
        DEC(d, ORD("A")-10);
      END;
      IF ((d >= 0) & (d < base)) THEN
        z := MulAdd1(z, SHORT(inputBase), SHORT(d));
      ELSE                               (* error: bail out *)
        RETURN NIL;
      END;
      INC (start);
    END;
    z.size := sign*z.size;
    IF (start # firstDigit) THEN
      RETURN z;
    ELSE                                 (* no digits, then no number *)
      RETURN NIL;
    END;
  END NewLatin1Region;

PROCEDURE NewLatin1* (str[NO_COPY]: ARRAY OF CHAR; inputBase: LONGINT): BigInt;
  BEGIN
    RETURN NewLatin1Region(str, 0, Strings.Length(str), inputBase);
  END NewLatin1;

PROCEDURE New* (str: STRING; inputBase: LONGINT): BigInt;
  VAR
    str8: Object.String8;
    chars: Object.CharsLatin1;
  BEGIN
    str8 := str.ToString8("?");
    chars := str8.CharsLatin1();
    RETURN NewLatin1Region(chars^, 0, str.length, inputBase);
  END New;

PROCEDURE (a: BigInt) Invert*(): BigInt;
(**Bitwise complement.  The result equals @samp{-(a+1)}.  *)
  BEGIN
    a := a.Add(one);
    a.size := -a.size;
    RETURN a;
  END Invert;

PROCEDURE (a: BigInt) LShift* (n: LONGINT): BigInt;
  VAR
    wordShift, remShift, oldSize, newSize, i, j, accum: LONGINT;
    z: BigInt;
  BEGIN
    ASSERT(n >= 0);
    wordShift := n DIV shift;
    remShift := n MOD shift;
    
    oldSize := ABS(a.size);
    newSize := oldSize+wordShift;
    IF (remShift # 0) THEN
      INC(newSize);
    END;

    z := NewInstance(newSize);
    IF (a.size < 0) THEN
      z.size := -z.size;
    END;
    i := 0;
    WHILE (i # wordShift) DO
      z.digit[i] := 0;
      INC(i);
    END;
    accum := 0;
    j := 0;
    WHILE (j # oldSize) DO
      INC(accum, ASH(a.digit[j], remShift));
      z.digit[i] := SHORT(accum MOD base);
      accum := accum DIV base;
      INC(i);
      INC(j);
    END;
    IF (remShift # 0) THEN
      z.digit[newSize-1] := SHORT(accum);
    ELSE
      ASSERT(accum = 0);
    END;
    Normalize(z);
    RETURN z;
  END LShift;

PROCEDURE (a: BigInt) RShift* (n: LONGINT): BigInt;
  VAR
    wordShift, newSize, loShift, hiShift, i, j: LONGINT;
    loMask, hiMask: SET;
    z: BigInt;
  BEGIN
    ASSERT(n >= 0);
    IF (a.size < 0) THEN
      a := a.Invert();
      a := a.RShift(n);
      RETURN a.Invert();
    ELSE
      wordShift := n DIV shift;
      newSize := a.size-wordShift;
      IF (newSize <= 0) THEN
        RETURN zero;
      ELSE
        loShift := n MOD shift;
        hiShift := shift-loShift;
        loMask := S.VAL(SET, ASH(1, hiShift)-1);
        hiMask := S.VAL(SET, base-1-(ASH(1, hiShift)-1));
        z := NewInstance(newSize);
        i := 0;
        j := wordShift;
        WHILE (i < newSize) DO
          z.digit[i] := SHORT(S.VAL(LONGINT, S.VAL(SET, ASH(a.digit[j], -loShift))*loMask));
          IF (i+1 < newSize) THEN
            INC(z.digit[i], SHORT(S.VAL(LONGINT, S.VAL(SET, ASH(a.digit[j+1], hiShift))*hiMask)));
          END;
          INC(i);
          INC(j);
        END;
        Normalize(z);
        RETURN z;
      END;
    END;
  END RShift;

PROCEDURE (a: BigInt) Store*(w: Storable.Writer) RAISES IO.Error;
  VAR
    i: LONGINT;
  BEGIN
    w.WriteNum(a.size);
    FOR i := 0 TO ABS(a.size)-1 DO
      w.WriteInt(a.digit[i]);
    END;
  END Store;

PROCEDURE (a: BigInt) Load*(r: Storable.Reader) RAISES IO.Error;
  VAR
    i: LONGINT;
  BEGIN
    r.ReadNum(a.size);
    NEW(a.digit, ABS(a.size));
    FOR i := 0 TO ABS(a.size)-1 DO
      r.ReadInt(a.digit[i]);
    END;
  END Load;

PROCEDURE Init ();
  VAR
    i: LONGINT;
  BEGIN
    FOR i := 0 TO LEN(powerOf2)-1 DO
      powerOf2[i] := -1;
    END;
    powerOf2[ 2] := 1;
    powerOf2[ 4] := 2;
    powerOf2[ 8] := 3;
    powerOf2[16] := 4;
    powerOf2[32] := 5;
    
    zero := NewInstance(0);
    one := NewInstance(1); one.digit[0] := 1;
  END Init;

BEGIN
  Init;
END Object:BigInt.
