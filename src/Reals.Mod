(*	$Id$	*)
MODULE Reals;
 
 (*
    Reals - Mathematical functions for an arbitrary-precision floating
            point representation named Real.
    
    Copyright (C) 1997 Michael Griebling
    From an original FORTRAN library MPFUN by David H. Bailey, NASA Ames
    Research Center which is available from:
    
      http://science.nas.nasa.gov/Groups/AAA/db.webpage/mpdist/mpdist.html
    
    or via email from mp-request@nas.nasa.gov.
    Source translated with permission of the original author.
 
    This module is free software; you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as 
    published by the Free Software Foundation; either version 2 of the
    License, or (at your option) any later version.
 
    This module is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.
 
    You should have received a copy of the GNU Lesser General Public
    License along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

*)

(* 
    From the author's description:
    
    The following information is a brief description of this program.  For
    full details and instructions for usage, see the paper "A Portable High
    Performance Multiprecision Package", available from the author.

    This package of Fortran subroutines performs multiprecision floating point
    arithmetic.  If sufficient main memory is available, the maximum precision
    level is at least 16 million digits.  The maximum dynamic range is at
    least 10^(+-14,000,000).  It employs advanced algorithms, including an
    FFT-based multiplication routine [Not yet in Oberon-2--MG] and some recently discovered
    quadratically convergent algorithms for pi, exp and log.  The package also
    features extensive debug and self-checking facilities, so that it can be
    used as a rigorous system integrity test.  All of the routines in this
    package have been written to facilitate vector, parallel processing and/or
    RISC processing.
    
    My comments:
    
    The current algorithms are not optimized for really large numbers.  If there
    is some interest, I will be porting those algorithms as well from the original
    author.  The existing algorithms will work in a reasonable time for most numbers
    and are hard-limited via a constant `maxDigits' to a maximum of about 225 digits.
    This constant can be easily increased.  Of course, performance will suffer.  The
    actual working precision is adjustable via the `SetWords' routine.  The actual
    number of words will then be reflected in the `curMant' read-only constant.
    Each word gives about 7.22 digits of precision.  The default precision is set
    to `maxDigits'.
    
    There may be a couple of bugs in several routines which affect the accuracy
    in the last few places of the result.  This shouldn't make much difference to
    casual users as long as the precision is set to be 10-20 digits more than you
    need.  I am investigating these problems.
*)
  
IMPORT rm:=LRealMath, Out:=OakOut;
       (* rm:=MathL, Out; *)    (* uncomment for o2c compatibility *)
    
CONST
  ZERO = 0.0;
  ONE  = 1.0;
  HALF = 0.5; 
  invLn2 = 1.4426950408889633D0;
  Ln2 = 0.693147180559945309D0;
  
  (* numeric precision-setting constants *) 
  maxDigits*=500;                                  (* initial precision level in digits *)
  outDigits*=56;                                   (* initial output precision level in digits *)
  log10eps*=10-maxDigits;                          (* log10 of initial eps level *)
  maxMant*=ENTIER(maxDigits/7.224719896D0+HALF)+1; (* hardcoded maximum mantissa words *)
  maxExp*=2000000;                                 (* maximum exponent *)
  
  (* internal scaling constants *)
  mpbbx=4096.0D0; 
  radix=mpbbx*mpbbx; mpbx2=radix*radix; mprbx=ONE/mpbbx;
  invRadix=mprbx*mprbx; mprx2=invRadix*invRadix; mprxx=16*mprx2;
  
  (* miscellaneous constants *)
  NBT=24; NPR=32; MPIRD=1; NIT=3;
  
TYPE
  Real* = POINTER TO RealDesc;
  RealDesc = ARRAY OF REAL;
  FixedLReal = ARRAY maxMant+8 OF LONGREAL;
  FixedReal = ARRAY maxMant+8 OF REAL;
  Real8 = ARRAY 8 OF REAL;

VAR
  err*, curMant-, debug*, numBits, sigDigs-: INTEGER;
  xONE: Real8;                    (* internal constant *)
  eps-, ln2-, pi-, ln10-: Real;

(*---------------------------------------------------------*)
(* Internal basic operator definitions                     *)

PROCEDURE Min (x, y: LONGINT) : LONGINT;
BEGIN
  IF x<y THEN RETURN x ELSE RETURN y END
END Min;

PROCEDURE Max (x, y: LONGINT) : LONGINT;
BEGIN
  IF x>y THEN RETURN x ELSE RETURN y END
END Max;

PROCEDURE Sign (x, y: REAL) : LONGINT;
BEGIN
  IF y<ZERO THEN RETURN -ENTIER(ABS(x))
  ELSE RETURN ENTIER(ABS(x))
  END
END Sign;

PROCEDURE Zero (VAR x: ARRAY OF REAL);
(* x to zero *)
BEGIN
  x[0]:=ZERO; x[1]:=ZERO
END Zero;

PROCEDURE Int (x: LONGREAL) : LONGINT;
BEGIN
  IF x<ZERO THEN RETURN -ENTIER(-x)
  ELSE RETURN ENTIER(x)
  END
END Int;

PROCEDURE ipower (x: LONGREAL; base: INTEGER): LONGREAL;
(* ipower(x, base) returns the x to the integer power base where base*Log2(x) < Log2(Max) *)
  VAR y: LONGREAL; neg: BOOLEAN;
BEGIN
  (* compute x**base using an optimised algorithm from Knuth, slightly 
     altered : p442, The Art Of Computer Programming, Vol 2 *)
  y:=ONE; IF base<0 THEN neg:=TRUE; base := -base ELSE neg:= FALSE END;
  LOOP
    IF ODD(base) THEN y:=y*x END;
    base:=base DIV 2; IF base=0 THEN EXIT END;
    x:=x*x;
  END;
  IF neg THEN RETURN ONE/y ELSE RETURN y END
END ipower;

PROCEDURE Reduce (VAR a: LONGREAL; VAR exp: LONGINT);
(* reduce `a' to be within 1 and radix and adjust
   the exponent `exp' appropriately *)
CONST
  maxIterations=100;
VAR
  k: LONGINT;
BEGIN
  IF a>=radix THEN
    FOR k:=1 TO maxIterations DO
      a:=invRadix*a;
      IF a<radix THEN INC(exp, k); RETURN END
    END 
  ELSIF a<ONE THEN
    FOR k:=1 TO maxIterations DO
      a:=radix*a;
      IF a>=ONE THEN DEC(exp, k); RETURN END
    END
  END
END Reduce;

PROCEDURE ^ OutReal (n: Real);   (* forward declaration *)


(*----------------------------------------------------------
   NB. The following routines are exported ONLY for use in
       other library modules.  Users should NOT use these.
 *)

PROCEDURE copy * (VAR a: RealDesc; VAR b: RealDesc);
(* b:=a *)
VAR ia, na, i: LONGINT;
BEGIN
  ia:=Sign(ONE, a[0]); na:=Min(ENTIER(ABS(a[0])), curMant);
  IF na=0 THEN Zero(b); RETURN END;
  b[0]:=Sign(na, ia);
  FOR i:=1 TO na+2 DO b[i]:=a[i] END
END copy;

PROCEDURE OutRealDesc (VAR n: RealDesc);
VAR r: Real;
BEGIN
  NEW(r, LEN(n)); copy(n, r^); OutReal(r)
END OutRealDesc;

PROCEDURE Write (q: RealDesc);
VAR i: LONGINT;
BEGIN
  (* output raw number *)
  FOR i:=0 TO ENTIER(ABS(q[0]))+1 DO 
    Out.String("x["); Out.Int(i, 0); Out.String("]="); Out.Int(Int(q[i]), 0); Out.Ln 
  END;
  Out.Ln
END Write;

PROCEDURE Round * (VAR a: RealDesc);
(*
    This performs rounding and truncation of the a number.
    The maxExp value is the absolute value of the largest exponent
    word allowed for extended numbers.
 *)
VAR
  a2: REAL;
  allZeros: BOOLEAN;
  ia, na, n4, i, k: LONGINT;  
BEGIN
  (* error testing *)
  IF err#0 THEN Zero(a); RETURN END;
  
  (* check for initial zeros *)
  a2:=a[1]; a[1]:=ZERO; ia:=Sign(ONE, a[0]);
  na:=Min(ENTIER(ABS(a[0])), curMant);
  n4:=na+4; 
  IF a[2]=ZERO THEN
    (* find the nonzero word and shift the entire number left.
       The length of the result is reduced by the length of the
       shift *)
    allZeros:=TRUE; i:=4;
    WHILE allZeros & (i<=n4) DO
      IF a[i-1]#ZERO THEN allZeros:=FALSE; k:=i-3 END;
      INC(i)
    END;
    IF allZeros THEN Zero(a); RETURN END;
    FOR i:=2 TO n4-k-1 DO a[i]:=a[i+k] END;
    a2:=a2-k; na:=na-Max(k-2, 0);
  END;
  
  (* perform rounding depending on MPIRD *)
  IF (na=curMant) & (MPIRD>=1) THEN
    IF ((MPIRD=1) & (a[na+2]>=HALF*radix)) OR ((MPIRD=2) & (a[na+2]>=ONE)) THEN
      a[na+1]:=a[na+1]+ONE
    END;
    
    (* release carries as far as necessary due to rounding *)
    i:=na+1;
    LOOP
      IF i<2 THEN a[2]:=a[1]; na:=1; a2:=a2+ONE; EXIT END;
      IF a[i]<radix THEN EXIT END;
      a[i]:=SHORT(LONG(a[i])-radix); a[i-1]:=a[i-1]+ONE;
      DEC(i)
    END
  END;
  
  (* At least the last mantissa word is zero.  Find the last
     nonzero word and adjust the length of the result accordingly *)
  IF a[na+1]=ZERO THEN
    i:=na+2;
    WHILE i>=3 DO
      IF a[i-1]#ZERO THEN na:=i-2; i:=1 END;
      DEC(i)
    END;
    IF i#0 THEN Zero(a); RETURN END
  END;
  
  (* check for overflow and underflow *)
  IF a2<-maxExp THEN
    Out.String("*** Round: Exponent underflow!"); Out.Ln;
    err:=68;
  ELSIF a2>maxExp THEN
    Out.String("*** Round: Exponent overflow!"); Out.Ln;
    err:=69
  END;
  
  (* check for zero *)
  IF a[2]=ZERO THEN Zero(a)
  ELSE a[0]:=Sign(na, ia); a[1]:=a2;
    a[na+2]:=ZERO; a[na+3]:=ZERO
  END
END Round;

PROCEDURE Normalize * (VAR d: ARRAY OF LONGREAL; VAR a: RealDesc);
(*
   This converts the number in array d to the standard normalized
   form in a.  Values in d are often negative or exceed the maximum
   radix radix in result arrays, and this fixes them.
   
   Normalize assumes that two extra mantissa words are input at the
   end of d.  This reduces precision loss when it is necessary to
   shift the result to the left.  The output is placed in the array
   a.  Debug output starts with debug = 10.
*)
VAR
  a2: REAL;
  t1, t2, t3: LONGREAL;
  ia, na, n4, i: LONGINT;
BEGIN
  IF err#0 THEN Zero(a); RETURN END;
  ia:=Sign(ONE, SHORT(d[0])); na:=Min(ENTIER(ABS(d[0])), curMant);
  IF na=0 THEN Zero(a); RETURN END;
  n4:=na+4; a2:=SHORT(d[1]); d[1]:=ZERO;  
  LOOP
    t1:=ZERO;
    FOR i:=n4-1 TO 2 BY -1 DO
      t3:=t1+d[i]; t2:=invRadix*t3; t1:=Int(t2);
      IF (t2<ZERO) & (t1#t2) THEN t1:=t1-ONE END;
      d[i]:=t3-t1*radix
    END;   
    d[1]:=d[1]+t1;
    IF d[1]<ZERO THEN
      (* negate all words and re-normalize *)
      ia:=-ia; d[2]:=d[2]+radix*d[1]; d[1]:=ZERO;
      FOR i:=1 TO n4-1 DO d[i]:=-d[i] END      
    ELSIF d[1]>ZERO THEN
      (* nonzero number spilled into d[1].  Shift the entire number
         right one cell.  The exponent and length of the result are
         increased by one. *)
      FOR i:=n4-1 TO 2 BY -1 DO a[i]:=SHORT(d[i-1]) END;
      na:=Min(na+1, curMant); a2:=a2+ONE;
      EXIT
    ELSE
      FOR i:=2 TO n4-1 DO a[i]:=SHORT(d[i]) END;     
      EXIT
    END
  END;
  
  (* perform rounding and truncation *)
  a[0]:=Sign(na, ia); a[1]:=a2;
  Round(a)
END Normalize;

PROCEDURE RealToNumbExp * (VAR a: RealDesc; VAR b: LONGREAL; VAR n: LONGINT);
(*
    This routine converts the multiprecision number `a' to the number
    `d'*2**`n', accurate to between 14-17 digits, depending on the
    system.  `b' will be between 1 and radix.
 *)
VAR
  aa: LONGREAL; na: LONGINT;
BEGIN
  (* handle error propogation *)
  IF err#0 THEN b:=ZERO; n:=0; RETURN END;
  
  (* trivial cases *)
  IF a[0]=ZERO THEN b:=ZERO; n:=0; RETURN END;
  
  (* real algorithm *)
  na:=ENTIER(ABS(a[0])); aa:=a[2];
  IF na>=2 THEN aa:=aa+invRadix*a[3] END;
  IF na>=3 THEN aa:=aa+mprx2*a[4] END;
  IF na>=4 THEN aa:=aa+invRadix*mprx2*a[5] END;
  
  n:=NBT*Int(a[1]);
  IF a[0]<0 THEN b:=-aa ELSE b:=aa END
END RealToNumbExp;

PROCEDURE NumbExpToReal * (a: LONGREAL; n: LONGINT; VAR b: RealDesc);
(*
    This routine converts the number `a'*2**`n' to an extended form
    in `b'.  All bits of `a' are recovered in `b'.  However, note
    for example that if `a'=0.1D0 and `n'=0, then `b' will NOT be
    the multiprecision equivalent of 1/10.  Debug output starts
    with debug = 9.  Pre: LEN(b)>=8.
 *)
VAR
  aa: LONGREAL; n1, n2, i: LONGINT;
BEGIN
  (* check for zero *)
  IF a=ZERO THEN Zero(b); RETURN END;
  n1:=Int(n/NBT); n2:=n-NBT*n1; 
  aa:=ABS(a)*ipower(2.0, SHORT(n2));
  
  (* reduce aa to within 1 and radix *)
  Reduce(aa, n1);
  
  (* store successive sections of aa into b *)
  b[1]:=n1; 
  b[2]:=Int(aa); aa:=radix*(aa-b[2]);
  b[3]:=Int(aa); aa:=radix*(aa-b[3]);
  b[4]:=Int(aa); aa:=radix*(aa-b[4]); 
  b[5]:=Int(aa);
  b[6]:=ZERO;
  b[7]:=ZERO;
  
  (* find length of resultant number *)
  FOR i:=5 TO 2 BY -1 DO
    IF b[i]#ZERO THEN b[0]:=Sign(i-1, SHORT(a)); RETURN END
  END;
  b[0]:=ZERO
END NumbExpToReal;

PROCEDURE Add * (VAR c: RealDesc; a, b : RealDesc);
(*
   This routine adds MP numbers a and b to yield the MP
   sum c.  It attempts to include all significance of a
   and b in the result, up to the maximum mantissa length
   curMant.  Debug output starts with debug = 9.
*)
VAR
  i, ia, ib, na, nb, nsh: LONGINT;
  ixa, ixb, ixd, ish, m1, m2, m3, m4, m5, nd: LONGINT;
  db: LONGREAL;
  d: FixedLReal;
BEGIN
  IF err#0 THEN Zero(c); RETURN END;
  IF debug>=9 THEN
    Out.String("Add 1"); Out.Ln; Write(a);
    Out.String("Add 2"); Out.Ln; Write(b)   
  END;
  ia:=Sign(ONE, a[0]); ib:=Sign(ONE, b[0]);
  na:=Min(ENTIER(ABS(a[0])), curMant);
  nb:=Min(ENTIER(ABS(b[0])), curMant);
  
  (* check for zero inputs *)
  IF na=0 THEN (* a is zero -- the result is b *)
    c[0]:=Sign(nb, ib);
    FOR i:=1 TO nb+1 DO c[i]:=b[i] END
  ELSIF nb=0 THEN (* b is zero -- the result is a *)
    c[0]:=Sign(na, ia);
    FOR i:=1 TO na+1 DO c[i]:=a[i] END  
  ELSE
    IF ia=ib THEN db:=ONE ELSE db:=-ONE END;
    ixa:=Int(a[1]); ixb:=Int(b[1]); ish:=ixa-ixb;
    
    (* check if `a's exponent is greater than `b's *)
    IF ish>=0 THEN
      (* `b' must be shifted to the right *)
      m1:=Min(na, ish); m2:=Min(na, nb+ish); m3:=na; 
      m4:=Min(Max(na, ish), curMant+1);
      m5:=Min(Max(na, nb+ish), curMant+1);
      d[0]:=ZERO; d[1]:=ZERO;
      FOR i:=1    TO m1 DO d[i+1]:=a[i+1] END;
      FOR i:=m1+1 TO m2 DO d[i+1]:=a[i+1]+db*b[i+1-ish] END;
      FOR i:=m2+1 TO m3 DO d[i+1]:=a[i+1] END;
      FOR i:=m3+1 TO m4 DO d[i+1]:=ZERO END;
      FOR i:=m4+1 TO m5 DO d[i+1]:=db*b[i+1-ish] END;
      nd:=m5; ixd:=ixa; d[nd+2]:=ZERO; d[nd+3]:=ZERO
    ELSE
      (* `b' has greater exponent than `a', so `a' is shifted
         to the right. *)
      nsh:=-ish; m1:=Min(nb, nsh); m2:=Min(nb, na+nsh); m3:=nb;
      m4:=Min(Max(nb, nsh), curMant+1);
      m5:=Min(Max(nb, na+nsh), curMant+1);
      d[0]:=ZERO; d[1]:=ZERO;
      FOR i:=1    TO m1 DO d[i+1]:=db*b[i+1] END;
      FOR i:=m1+1 TO m2 DO d[i+1]:=a[i+1-nsh]+db*b[i+1] END;
      FOR i:=m2+1 TO m3 DO d[i+1]:=db*b[i+1] END;
      FOR i:=m3+1 TO m4 DO d[i+1]:=ZERO END;
      FOR i:=m4+1 TO m5 DO d[i+1]:=a[i+1-nsh] END;
      nd:=m5; ixd:=ixb; d[nd+2]:=ZERO; d[nd+3]:=ZERO
    END;
    d[0]:=Sign(nd, ia); d[1]:=ixd;
    Normalize(d, c)
  END;
  IF debug>=9 THEN Out.String("Add 3"); Out.Ln; Write(c) END
END Add;

PROCEDURE Sub * (VAR c: RealDesc; a, b: RealDesc);
BEGIN
  IF err#0 THEN Zero(c); RETURN END;
  
  (* negate and perform addition *)
  b[0]:=-b[0]; Add(c, a, b)
END Sub;

PROCEDURE Mul * (VAR c: RealDesc; a, b: RealDesc);
(*
    This routine multiplies numbers `a' and `b' to yield the
    produce `c'.  When one of the arguments has a much higher
    level of precision than the other, this routine is slightly
    more efficient if `a' has the lower level of precision.
    Debug output starts with debug = 8.
    
    This routine returns up to curMant mantissa words of the
    product.  If the complete double-long product of `a' and
    `b' is desired, then curMant must be at least as large as
    the sum of the mantissa lengths of `a' and `b'.  In other
    words, if the precision levels of `a' and `b' are both
    64 words, then curMant must be at least 128 words to
    obtain the complete double-long product in `c'.
 *)
VAR
  ia, ib, na, nb, nc, i, j, i1, i2, n2, j3: LONGINT; 
  d2, t1, t2: LONGREAL;
  d: FixedLReal;
BEGIN
  IF err#0 THEN Zero(c); RETURN END;
  IF debug>=8 THEN
    Out.String("Mul 1"); Out.Ln; Write(a);
    Out.String("Mul 2"); Out.Ln; Write(b)   
  END;
  ia:=Sign(ONE, a[0]); ib:=Sign(ONE, b[0]);
  na:=Min(ENTIER(ABS(a[0])), curMant);
  nb:=Min(ENTIER(ABS(b[0])), curMant);
  
  (* if one of the inputs is zero--result is zero *)
  IF (na=0) OR (nb=0) THEN Zero(c); RETURN END;
 
  (* check for multiplication by 1 *)
  IF (na=1) & (a[2]=ONE) THEN
    (* a is 1 or -1 -- result is b or -b *)
    c[0]:=Sign(nb, ia*ib); c[1]:=a[1]+b[1];
    FOR i:= 2 TO nb+1 DO c[i]:=b[i] END;
    RETURN
  ELSIF (nb=1) & (b[2]=ONE) THEN
    (* b is 1 or -1 -- result is a or -a *)
    c[0]:=Sign(na, ia*ib); c[1]:=a[1]+b[1];
    FOR i:= 2 TO na+1 DO c[i]:=a[i] END;
    RETURN    
  END;
  
  nc:=Min(na+nb, curMant);
  d2:=a[1]+b[1]; 
  FOR i:=0 TO nc+3 DO d[i]:=ZERO END;
  
  (* perform ordinary long multiplication algorithm.
     Accumulate at most curMant+4 mantissa words of the
     product. *)
  FOR j:=3 TO na+2 DO
    t1:=a[j-1]; j3:=j-3;
    n2:=Min(nb+2, curMant+4-j3);
    FOR i:=2 TO n2-1 DO
      d[i+j3]:=d[i+j3]+t1*b[i]
    END;
    
    (* release carries periodically to avoid overflowing
       the exact integer capacity of double precision
       floating point words in d *)
    IF j-2 MOD NPR = 0 THEN
      i1:=Max(3, j-NPR); i2:=n2+j3;
      FOR i:=i1 TO i2 DO
        t1:=d[i-1]; t2:=Int(invRadix*t1);
        d[i-1]:=t1-radix*t2;
        d[i-2]:=d[i-2]+t2
      END
    END
  END;
  
  (* if d[1] is nonzero, shift the result one cell right *)
  IF d[1]#ZERO THEN
    d2:=d2+ONE;
    FOR i:=nc+3 TO 2 BY -1 DO d[i]:=d[i-1] END
  END;
  d[0]:=Sign(nc, ia*ib); d[1]:=d2;
  
  (* fix up result since some words may be negative or
     exceed radix *)
  Normalize(d, c);
  IF debug>=9 THEN Out.String("Mul 3"); Out.Ln; Write(c) END
END Mul;

PROCEDURE Muld * (VAR c: RealDesc; a: RealDesc; b: LONGREAL; n: LONGINT);
(*
    This routine multiplies the multiple precision number `a' 
    by the number `b'*2**`n' to produce the multiple precision
    result in `c'.
 *)
VAR
  bb: LONGREAL; d: FixedLReal;
  ia, ib, n1, n2, i, na: LONGINT;
  f: Real8;
BEGIN
  IF err#0 THEN Zero(c); RETURN END;
  IF debug>=9 THEN
    Out.String("Muld 1"); Out.Ln; Write(a);
    Out.String("Muld 2"); Out.Ln; Out.LongReal(b, 0); 
    Out.String("; n="); Out.Int(n, 0); Out.Ln   
  END;
  
  (* check for zero inputs *)
  ia:=Sign(ONE, a[0]); ib:=Sign(ONE, SHORT(b)); 
  na:=Min(ENTIER(ABS(a[0])), curMant);
  IF (na=0) OR (b=ZERO) THEN Zero(c); RETURN END;
  n1:=Int(n/NBT); n2:=n-NBT*n1; bb:=ABS(b)*ipower(2.0, SHORT(n2));
  
  (* reduce bb to within 1 and radix *)
  Reduce(bb, n1);
  
  (* if `b' cannot be represented exactly in a single mantissa word then use Mul *)
  IF bb#Int(bb) THEN
    IF b<ZERO THEN bb:=-ABS(b) ELSE bb:=ABS(b) END;
    NumbExpToReal(bb, n1*NBT, f);  (* convert bb to f (Real) *)
    Mul(c, f, a)
  ELSE
    (* perform short multiply *)
    FOR i:=2 TO na+1 DO d[i]:=bb*a[i] END;
    
    (* set exponent and fix up the result *)
    d[0]:=Sign(na, ia*ib); d[1]:=a[1]+n1;
    d[na+2]:=ZERO; d[na+3]:=ZERO;
    Normalize(d, c)
  END;
  
  IF debug>=9 THEN
    Out.String("Muld 3"); Out.Ln; Write(c)
  END
END Muld;

PROCEDURE Div * (VAR c: RealDesc; a, b: RealDesc);
(*
    This routine divides the number `a' by the number `b' to yield
    the quotient `c'.  Debug output starts with debug = 8.
 *)
VAR
  ia, ib, na, nb, nc, i3, i2, i, j, j3, md, is, ij: LONGINT;
  rb, ss, t0, t1, t2: LONGREAL;
  useOldj: BOOLEAN;
  d: FixedLReal;
BEGIN
  (* handle errors *)
  IF err#0 THEN Zero(c); RETURN END;
  IF debug>=8 THEN
    Out.String("Div 1"); Out.Ln; Write(a);
    Out.String("Div 2"); Out.Ln; Write(b)   
  END;
  
  (* extract lengths and number signs *)
  ia:=Sign(ONE, a[0]); ib:=Sign(ONE, b[0]);
  na:=Min(ENTIER(ABS(a[0])), curMant);
  nb:=Min(ENTIER(ABS(b[0])), curMant);
  
  (* check if dividend is zero *)
  IF na=0 THEN Zero(c); RETURN END;
  
  (* check for divisors of 1 or -1 *)
  IF (nb=1) & (b[2]=ONE) THEN
    c[0]:=Sign(na, ia*ib);
    c[1]:=a[1]-b[1];
    FOR i:=2 TO na+1 DO c[i]:=a[i] END;
    RETURN
  END;
  
  (* check if divisor is zero *)
  IF nb=0 THEN
    Out.String("*** Div: Divisor is zero!"); Out.Ln;
    err:=31; RETURN
  END;
  
  (* initialize trial divisor and trial dividend *)
  t0:=radix*b[2]; 
  IF nb>=2 THEN t0:=t0+b[3] END;
  IF nb>=3 THEN t0:=t0+invRadix*b[4] END;
  IF nb>=4 THEN t0:=t0+mprx2*b[5] END;
  rb:=ONE/t0; md:=Min(na+nb, curMant);
  d[0]:=ZERO;
  FOR i:=1 TO na DO d[i]:=a[i+1] END;
  FOR i:=na+1 TO md+3 DO d[i]:=ZERO END;
  
  (* perform ordinary long division algorithm.  First
     compute only the first na words of the quotient. *)
  FOR j:=2 TO na+1 DO
    t1:=mpbx2*d[j-2]+radix*d[j-1]+d[j]+invRadix*d[j+1];
    t0:=Int(rb*t1); j3:=j-3;
    i2:=Min(nb, curMant+2-j3)+2;
    ij:=i2+j3;
    FOR i:=3 TO i2 DO
      i3:=i+j3-1; d[i3]:=d[i3]-t0*b[i-1]
    END;
    
    (* release carries periodically to avoid overflowing
       the exact integer capacity of double precision
       floating point words in d. *)
    IF j-1 MOD NPR = 0 THEN
      FOR i:=j TO ij-1 DO
        t1:=d[i]; t2:=Int(invRadix*t1);
        d[i]:=t1-radix*t2; d[i-1]:=d[i-1]+t2
      END
    END;
    d[j-1]:=d[j-1]+radix*d[j-2];
    d[j-2]:=t0
  END;
  
  (* compute additional words of the quotient, as long as
     the remainder is nonzero. *)
  j:=na+2; useOldj:=FALSE;
  LOOP
    IF j>curMant+3 THEN EXIT END;
    t1:=mpbx2*d[j-2] + radix*d[j-1] + d[j];
    IF j<=curMant+2 THEN t1:=t1+invRadix*d[j+1] END;
    t0:=Int(rb*t1); j3:=j-3;
    i2:=Min(nb, curMant+2-j3)+2;
    ij:=i2+j3; ss:=ZERO;
    
    FOR i:=3 TO i2 DO
      i3:=i+j3-1; d[i3]:=d[i3]-t0*b[i-1];
      ss:=ss+ABS(d[i3])
    END;
    
    IF j-1 MOD NPR = 0 THEN
      FOR i:=j TO ij-1 DO
        t1:=d[i]; t2:=Int(invRadix*t1);
        d[i]:=t1-radix*t2; d[i-1]:=d[i-1]+t2
      END
    END;
    d[j-1]:=d[j-1]+radix*d[j-2];
    d[j-2]:=t0;
    IF ss=ZERO THEN useOldj:=TRUE; EXIT END;
    IF ij<=curMant THEN d[ij+2]:=ZERO END;
    INC(j)
  END;
  
  (* set sign and exponent, and fix up result *)
  IF ~useOldj THEN j:=curMant+3 END;
  d[j-1]:=ZERO;
  IF d[0]=ZERO THEN is:=1 ELSE is:=2 END;
  nc:=Min(j-1, curMant);
  d[nc+2]:=ZERO; d[nc+3]:=ZERO;
  FOR i:=j TO 2 BY -1 DO d[i]:=d[i-is] END;
  d[0]:=Sign(nc, ia*ib);
  d[1]:=a[1]-b[1]+is-2;
  Normalize(d, c);
  
  IF debug>=8 THEN
    Out.String("Div 3"); Out.Ln; Write(c)   
  END;  
END Div;

PROCEDURE Divd * (VAR c: RealDesc; a: RealDesc; b: LONGREAL; n: LONGINT);
(*
    This routine divides the multiple precision number `a' 
    by the number `b'*2**`n' to produce the multiple precision
    result in `c'.
 *)
VAR
  t1, bb, br, dd: LONGREAL; 
  d: FixedLReal;
  ia, ib, n1, n2, nc, na, j: LONGINT;
  ok: BOOLEAN;
  f: Real8;
BEGIN
  IF err#0 THEN Zero(c); RETURN END;
  ia:=Sign(ONE, a[0]); ib:=Sign(ONE, SHORT(b)); 
  na:=Min(ENTIER(ABS(a[0])), curMant);
  
  (* check if dividend is zero *)
  IF na=0 THEN Zero(c); RETURN END;
  
  (* check if divisor is zero *)
  IF b=ZERO THEN Out.String("*** Divd: Divisor is zero!"); 
    Out.Ln; err:=32; RETURN
  END;
  
  n1:=Int(n/NBT); n2:=n-NBT*n1; bb:=ABS(b)*ipower(2.0, SHORT(n2));
  
  (* reduce bb to within 1 and radix *)
  Reduce(bb, n1);
  
  (* if `b' cannot be represented exactly in a single mantissa word then use Div *)
  IF bb#Int(bb) THEN
    IF b<ZERO THEN bb:=-ABS(b) ELSE bb:=ABS(b) END;
    NumbExpToReal(bb, n1*NBT, f);  (* convert bb to f (Real) *)
    Div(c, a, f)
  ELSE
    (* perform short division *)
    br:=ONE/bb; dd:=a[2];
    j:=2; ok:=TRUE;
    WHILE ok & (j<=curMant+3) DO
      t1:=Int(br*dd); d[j]:=t1;
      dd:=radix*(dd-t1*bb);
      IF j<=na THEN dd:=dd+a[j+1]
      ELSIF dd=ZERO THEN ok:=FALSE
      END;
      INC(j)
    END;
    
    (* set exponent and fix up the result *)
    DEC(j); nc:=Min(j-1, curMant);
    d[0]:=Sign(nc, ia*ib); d[1]:=a[1]-n1;
    IF j<=curMant+2 THEN d[j+1]:=ZERO END;
    IF j<=curMant+1 THEN d[j+2]:=ZERO END;
    Normalize(d, c)
  END
END Divd;

PROCEDURE Abs * (VAR z: RealDesc; x: RealDesc);
BEGIN
  copy(x, z); z[0]:=ABS(x[0])
END Abs;

PROCEDURE IntPower * (VAR b: RealDesc; a: RealDesc; n: LONGINT);
(*
    This routine computes the `n'-th power of the extended
    number `a' and returns the extended result in `b'.
    When `n' is negative, the reciprocal of `a'**|`n'| is
    returned.  The Knuth's method is used p442, "The Art
    of Computer Programming", Vol 2.
 *)
VAR
  na, nws, nn: LONGINT;
  r, t: FixedReal;
BEGIN
  IF err#0 THEN Zero(b); RETURN END;
  na:=Min(ENTIER(ABS(a[0])), curMant);
  
  (* check for errors *)
  IF na=0 THEN
    IF n>=0 THEN Zero(b)
    ELSE Out.String("*** ipower: Argument is zero and n is <= 0."); 
      Out.Ln; err:=57
    END;
    RETURN
  END;
  
  (* check for trival cases *)  
  nws:=curMant; INC(curMant); nn:=ABS(n);
  IF nn=0 THEN copy(xONE, b);                 (* x^0 = 1 *)
    curMant:=SHORT(nws); RETURN 
  ELSIF nn=1 THEN copy(a, b)                  (* x^1 = x *)
  ELSIF nn=2 THEN Mul(t, a, a); copy(t, b)    (* x^2 = x*x *)
  ELSE   
    (* apply Knuth's algorithm *)
    copy(xONE, b);  (* b = 1 *)
    copy(a, r);     (* r = a *)
    LOOP
      IF ODD(nn) THEN Mul(t, b, r); copy(t, b) END;
      nn:=nn DIV 2; IF nn=0 THEN EXIT END;
      Mul(r, r, r)
    END
  END;
    
  (* take reciprocal if n<0 *)
  IF n<0 THEN Div(t, xONE, b); copy(t, b) END;
  
  (* restore original precision *)
  curMant:=SHORT(nws); Round(b)
END IntPower;

PROCEDURE Cmp * (VAR a, b: RealDesc) : LONGINT;
(*
     This routine compares the extended numbers `a' and `b' and
     returns the value -1, 0, or 1 depending on whether `a'<`b',
     `a'=`b', or `a'>`b'.  It is faster than merely subtracting
     `a' and `b' and looking at the sign of the result.
 *)
VAR
  ia, ib, ma, mb, na, nb, i: LONGINT;
BEGIN
  ia:=Sign(ONE, a[0]); IF a[0]=ZERO THEN ia:=0 END; 
  ib:=Sign(ONE, b[0]); IF b[0]=ZERO THEN ib:=0 END;
  
  (* compare signs *)
  IF ia#ib THEN RETURN Sign(ONE, ia-ib) END;
  
  (* signs are the same, compare exponents *)
  ma:=Int(a[1]); mb:=Int(b[1]);
  IF ma#mb THEN RETURN ia*Sign(ONE, ma-mb) END;
  
  (* signs & exponents are the same, compare mantissas *)
  na:=Min(ENTIER(ABS(a[0])), curMant); nb:=Min(ENTIER(ABS(b[0])), curMant);
  FOR i:=2 TO Min(na, nb)+1 DO
    IF a[i]#b[i] THEN RETURN ia*Sign(ONE, a[i]-b[i]) END
  END;
  
  (* mantissas are the same to the common length, compare lengths *)
  IF na#nb THEN RETURN ia*Sign(ONE, na-nb) END;
  
  (* signs, exponents, mantissas, and legnths are the same so a=b *)
  RETURN 0
END Cmp;

PROCEDURE Sqrt * (VAR b: RealDesc; a: RealDesc);
(*
     Computes the square root of `a' and returns the result
     in `b'.
     
     This routine employs the following Newton-Raphson iteration, which
     converges to 1 / Sqrt(a):
     
       X(k+1) = X(k) + 0.5 * (1 - X(k)^2 * a) * X(k)
       
     where the multiplication () * X(k) is performed with only half the
     normal level of precision.  These iterations are performed with a
     maximum precision level curMant that is dynamically changed,
     doubling with each iteration.  The final iteration is performed
     as follows (this is due to A. Karp):
     
       Sqrt(a) = (a * X(n)) + 0.5 * (a - (a * X(n)^2) * X(n)
       
     where the multiplications a * X(n) and ()* X(n) are performed
     with only half of the final level of precision. 
 *)
VAR
  t1, t2: LONGREAL;
  k0, k1, k2: FixedReal;
  iq: BOOLEAN;
  ia, na, nws, n2, n, k, nw1, nw2, mq: LONGINT;
BEGIN
  IF err#0 THEN Zero(b); RETURN END;
  ia:=Sign(ONE, a[0]); na:=Min(ENTIER(ABS(a[0])), curMant);
  
  (* trivial values *)
  IF na=0 THEN Zero(b); RETURN END;
  
  (* error checking *)
  IF ia<0 THEN Out.String("*** Sqrt: Argument is negative!");
    Out.Ln; err:=70; RETURN
  END;
  nws:=curMant;
  
  (* determine the least integer mq such that 2^mq >= curMant *)
  t1:=curMant; mq:=Int(invLn2*rm.ln(t1)+ONE-mprxx);
  
  (* initial approximation of 1 / Sqrt(a) *)
  RealToNumbExp(a, t1, n);
  n2:=-(n DIV 2); t2:=rm.sqrt(t1*ipower(2.0D0, SHORT(n+2*n2)));
  t1:=ONE/t2;
  NumbExpToReal(t1, n2, b);
  curMant:=3; iq:=FALSE;
  
  (* perform the Newton_Raphson iteration described above with
     a dynamically changing precision level curMant (one greater
     than the powers of two). *)
  FOR k:=2 TO mq-1 DO
    nw1:=curMant; curMant:=SHORT(Min(2*curMant-2, nws)+1);
    nw2:=curMant; 
    LOOP
      Mul(k0, b, b);           (* k0 = X(k)^2 *)
      Mul(k1, a, k0);          (* k1 = a * X(k)^2 *)
      Sub(k0, xONE, k1);       (* k0 = 1 - a * X(k)^2 *)
      curMant:=SHORT(nw1);
      Mul(k1, b, k0);          (* k1 = X(k)*(1 - a * X(k)^2) *)
      Muld(k0, k1, HALF, 0);   (* k0 = 0.5 * (X(k)*(1 - a * X(k)^2)) *)
      curMant:=SHORT(nw2);
      Add(b, b, k0);           (* X(k+1) = X(k) + 0.5 * (X(k)*(1 - a * X(k)^2)) *)
      IF ~iq & (k=mq-NIT) THEN iq:=TRUE
      ELSE EXIT
      END
    END
  END;
  
  (* last iteration using Karp's trick *)
  Mul(k0, a, b);               (* k0 = a * X(n) *)
  nw1:=curMant;
  curMant:=SHORT(Min(2*curMant-2, nws)+1);
  nw2:=curMant;
  Mul(k1, k0, k0);             (* k1 = (a * X(n))^2 *)
  Sub(k2, a, k1);              (* k2 = a - (a * X(n))^2 *)
  curMant:=SHORT(nw1);
  Mul(k1, k2, b);              (* k1 = X(n) * (a - (a * X(n))^2) *)
  Muld(k2, k1, HALF, 0);       (* k2 = 0.5 * (X(n) * (a - (a * X(n))^2)) *)
  curMant:=SHORT(nw2);
  Add(k1, k0, k2);             (* Sqrt(a) = a * X(n) + 0.5 * (X(n) * (a - (a * X(n))^2)) *)
  copy(k1, b);
  
  (* restore original resolution *)
  curMant:=SHORT(nws); Round(b)
END Sqrt;

PROCEDURE Root * (VAR b: RealDesc; a: RealDesc; n: LONGINT);
(*
     Computes the `n'th root of `a' and returns the result in `b'.
     `n' must be at least one and must not exceed 2^30.
     
     This routine employs the following Newton-Raphson iteration, which
     converges to a ^ (-1/n):
     
       X(k+1) = X(k) + (X(k)/n) * (1 - X(k)^n * a)
       
     The reciprocal of the final approximation to a ^ (-1/n) is the
     nth root.  These iterations are performed with a maximum precision
     level curMant that is dynamically changed, approximately doubling 
     with each iteration.
     
     When n is large and a is very near one, the following binomial 
     series is employed instead of the Newton scheme:
     
       (1+x)^(1/n) = 1 + x/n + x^2*(1-n)/(2!*n^2) + ...
 *)
CONST
  maxN = 40000000H;   (* 2^30 *)
VAR
  t1, t2, tn: LONGREAL;
  k0, k1, k2, k3: FixedReal;
  f2: Real8;
  iq: BOOLEAN;
  nws: INTEGER;
  ia, na, n2, k, mq, n1, n3: LONGINT;
BEGIN
  IF err#0 THEN Zero(b); RETURN END;
  ia:=Sign(ONE, a[0]); na:=Min(ENTIER(ABS(a[0])), curMant);
  
  (* trivial values *)
  IF na=0 THEN Zero(b); RETURN END;
  
  (* error checking *)
  IF ia<0 THEN
    IF ODD(n) THEN a[0]:=-a[0] (* continue with ABS(a) *)
    ELSE Out.String("*** Root: Argument is negative!");
      Out.Ln; err:=70; RETURN
    END
  END;
  IF (n<=0) OR (n>maxN) THEN
    Out.String("*** Root: Improper value of n!"); Out.Ln;
    err:=60; RETURN
  END;
  nws:=curMant;
  
  (* if n = 1 or 2 use faster local routines *)
  IF n=1 THEN copy(a, b); b[0]:=Sign(b[0], ia); RETURN
  ELSIF n=2 THEN Sqrt(b, a); RETURN
  END;
  
  (* determine the least integer mq such that 2^mq >= curMant *)
  t1:=curMant; mq:=Int(invLn2*rm.ln(t1)+ONE-mprxx);
  
  (* check how close `a' is to 1 *)
  Sub(k0, a, xONE);
  IF k0[0]=ZERO THEN copy(xONE, b); RETURN END;
  RealToNumbExp(k0, t1, n1);
  n2:=Int(invLn2*rm.ln(ABS(t1)));
  t1:=t1*ipower(HALF, SHORT(n2));
  INC(n1, n2);
  IF n1<=-30 THEN
    t2:=n; n2:=Int(invLn2*rm.ln(t2)+ONE+mprxx);
    n3:=-NBT*curMant DIV n1;
    IF n3<Int(1.25*n2) THEN
      (* `a' is so close to 1 that it is cheaper to use the
         binomial series *)
      INC(curMant);
      Divd(k1, k0, t2, 0); Add(k2, xONE, k1);
      k:=0;
      LOOP
        INC(k); t1:=1-k*n; t2:=(k+1)*n;
        Muld(k2, k1, t1, 0);
        Muld(k1, k3, t2, 0);
        Mul(k3, k0, k1);
        copy(k3, k1);
        Add(k3, k1, k2);
        copy(k3, k2);
        IF (k1[0]=ZERO) OR (k1[1]<-curMant) THEN EXIT END
      END;
      copy(k2, b); Div(k0, xONE, k2);
      curMant:=nws; Round(b);
      b[0]:=Sign(b[0], ia);
      RETURN
    END 
  END;
  
  (* compute the initial approximation of a^(-1/n) *)
  tn:=n; RealToNumbExp(a, t1, n1);
  n2:=-Int(n1/tn);
  t2:=rm.exp(-ONE/tn*(rm.ln(t1)+(n1+tn*n2)*Ln2));
  NumbExpToReal(t2, n2, b);
  NumbExpToReal(tn, 0, f2);
  curMant:=3; iq:=FALSE;
  
  (* perform the Newton_Raphson iteration described above
     with a dynamically changing precision level curMant
     which is one greater than the powers of two. *)
  FOR k:=2 TO mq DO
    curMant:=SHORT(Min(2*curMant-2, nws)+1);
    LOOP
      IntPower(k0, b, n);
      Mul(k1, a, k0);
      Sub(k0, xONE, k1);
      Mul(k1, b, k0);
      Divd(k0, k1, tn, 0);
      Add(k1, b, k0);
      copy(k1, b);
      IF ~iq & (k=mq-NIT) THEN iq:=TRUE
      ELSE EXIT
      END
    END
  END;
  
  (* take reciprocal to give final result *)
  Div(k1, xONE, b); copy(k1, b);
  
  (* restore original resolution *)
  curMant:=nws; Round(b);
  b[0]:=Sign(b[0], ia)  
END Root;

PROCEDURE Pi * (VAR pi: RealDesc);
(*
     Computes Pi to available precision (curMant words). 
     
     The algorithm that is used, which is due to Salamin and
     Brent, is as follows:
     
     Set A(0) = 1, B(0) = 1/Sqrt(2), D(0) = Sqrt(2) - 1/2.
          
     Then from k = 1 iterate the following operations:
     
     A(k) = 0.5 * (A(k-1) + B(k-1))
     B(k) = Sqrt (A(k-1) * B(k-1))
     D(k) = D(k-1) - 2^k * (A(k) - B(k))^2
     
     Then P(k) = (A(k) + B(k))^2 / D(k) converges quadratically to
     Pi.  In other words, each iteration approximately doubles the
     number of correct digits, providing all iterations are done 
     with the maximum precision.
 *)
VAR
  f: Real8;
  An, Bn, Dn, t, r: FixedReal;
  nws, mq: LONGINT;
  k: INTEGER;
  t1: LONGREAL;
BEGIN
  IF err#0 THEN Zero(pi); RETURN END;
  
  (* increase working resolution *)
  nws:=curMant; INC(curMant);
  
  (* determine the number of iterations required for the given
     precision level.  This formula is good only for this Pi
     algorithm. *)
  t1:=nws*rm.log(radix, 10.0);
  mq:=Int(invLn2*(rm.ln(t1)-ONE)+ONE);
  
  (* initialize working variables *)
  copy(xONE, An);                       (* A(0) = 1 *)
  f[0]:=ONE; f[1]:=ZERO; f[2]:=2.0;
  Sqrt(t, f);                           (* t = Sqrt(2) *)
  Muld(Bn, t, HALF, 0);                 (* B(0) = 1 / Sqrt(2) *)
  f[1]:=-ONE; f[2]:=SHORT(HALF*radix);
  Sub(Dn, t, f);                        (* D(0) = Sqrt(2) - 1/2 *)
  
  (* perform iterations as above *)
  FOR k:=1 TO SHORT(mq) DO
    Mul(t, An, Bn);                     (* t = A(k-1) * B(k-1) *) 
    Add(r, An, Bn);                     (* r = A(k-1) + B(k-1) *)
    Sqrt(Bn, t);                        (* B(k) = Sqrt(A(k-1) * B(k-1)) *)
    Muld(An, r, HALF, 0);               (* A(k) = 0.5 * (A(k-1) + B(k-1)) *)    
    Sub(t, An, Bn);                     (* t = A(k) - B(k) *)
    Mul(t, t, t);                       (* t = (A(k) - B(k))^2 *)
    t1:=ipower(2.0D0, k);               (* t1 = 2^k *)
    Muld(t, t, t1, 0);                  (* t = 2^k * (A(k) - B(k))^2 *)
    Sub(Dn, Dn, t);                     (* D(k) = D(k-1) -  2^k * (A(k) - B(k))^2 *)
  END;
  
  (* complete the computation *)
  Add(t, An, Bn);                       (* t = A(k) + B(k) *)
  Mul(t, t, t);                         (* t = (A(k) + B(k))^2 *)
  Div(pi, t, Dn);                       (* k2 = (A(k) + B(k))^2 / D(k) *)
  
  (* back to original precision *)
  curMant:=SHORT(nws); Round(pi)
END Pi;

PROCEDURE Entier * (VAR b: RealDesc; a: RealDesc);
(*
    Set `b' to the largest integer not greater than `a'.
    For example: Entier(3.6) = 3 and Entier(-1.6)=-2
 *)
VAR
  ia, na, ma, nb, i: LONGINT;
BEGIN
  IF err#0 THEN Zero(b); RETURN END;
  ia:=Sign(ONE, a[0]); na:=Min(ENTIER(ABS(a[0])), curMant); 
  ma:=Int(a[1]);
  
  (* check for zero -> result is zero *)
  IF na=0 THEN Zero(b); RETURN END;
  
  (* check if `a' can be represented exactly as an integer *)
  IF ma>=curMant THEN
    Out.String("*** Entier: Argument is too large!"); Out.Ln;
    err:=56; RETURN
  END;
    
  (* place integer part of a in b *)
  nb:=Min(Max(ma+1, 0), na);
  IF nb=0 THEN Zero(b); RETURN
  ELSE
    b[0]:=Sign(nb, ia); b[1]:=ma;
    b[nb+2]:=ZERO; b[nb+3]:=ZERO;
    FOR i:=2 TO nb+1 DO b[i]:=a[i] END
  END;
  
  (* if (a < 0) & (Frac(a)#0) then b = b - 1 *)
  IF ia=-1 THEN
    FOR i:=nb+2 TO na+1 DO
      IF a[i]#ZERO THEN Sub(b, b, xONE); RETURN END
    END
  END
END Entier;

PROCEDURE RoundInt * (VAR b: RealDesc; a: RealDesc);
(*
    Set `b' to the integer nearest to the multiple precision
    number `a'.
 *)
VAR
  ia, na, ma, ic, nc, mc, nb, i: LONGINT;
  f: Real8;
  k0: FixedReal;
BEGIN
  IF err#0 THEN Zero(b); RETURN END;
  ia:=Sign(ONE, a[0]); na:=Min(ENTIER(ABS(a[0])), curMant);
  ma:=Int(a[1]);
  
  (* check for zero -> result is zero *)
  IF na=0 THEN Zero(b); RETURN END;
  
  (* check if `a' can be represented exactly as an integer *)
  IF ma>=curMant THEN
    Out.String("*** RoundInt: Argument is too large!"); Out.Ln;
    err:=56; RETURN
  END;
  
  (* add or subtract 1/2 from the input, depending on its sign *)
  f[0]:=ONE; f[1]:=-ONE; f[2]:=SHORT(HALF*radix);
  IF ia=1 THEN Add(k0, a, f) ELSE Sub(k0, a, f) END;
  ic:=Sign(ONE, k0[0]); nc:=ENTIER(ABS(k0[0])); mc:=Int(k0[1]);
  
  (* place integer part of k0 in b *)
  nb:=Min(Max(mc+1, 0), nc);
  IF nb=0 THEN Zero(b)
  ELSE
    b[0]:=Sign(nb, ic); b[1]:=mc;
    b[nb+2]:=ZERO; b[nb+3]:=ZERO;
    FOR i:=2 TO nb+1 DO b[i]:=k0[i] END
  END
END RoundInt;

PROCEDURE Exp * (VAR b: RealDesc; a: RealDesc);
(*
    This computes the exponential function of the extended
    precision number `a' and returns the result in `b'.  The
    value of `ln2' is also required.
    
    This algorithm uses a modification of the Taylor's series
    for Exp(t):
    
      Exp(t) = (1 + r + r^2/2! + r^3/3! + r^4/4! ...) ^ q*2^n
     
    where q = 256, r = t'/q, t' = t - n Ln(2) and where n is
    chosen so that -0.5 Ln(2) < t' <= 0.5 Ln(2).  Reducing t
    mod Ln(2) and dividing by 256 ensures that -0.001<r<=0.001
    which accelerates convergence in the above series.
 *)
CONST
  NQ=8;
VAR
  t1, t2, tl: LONGREAL;
  ia, na, nws, n1, nz, l1, i: LONGINT;
  k0, k1, k2, k3: FixedReal;
BEGIN
  IF err#0 THEN Zero(b); RETURN END;
  ia:=Sign(ONE, a[0]); na:=Min(ENTIER(ABS(a[0])), curMant);
  RealToNumbExp(a, t1, n1);
  t1:=t1*ipower(2, SHORT(n1));
  
  (* unless the argument is near Ln(2), ln2 must be precomputed.
     This exception is necessary because Ln calls Exp to
     initialize ln2 *)
  IF (ABS(t1-Ln2)>invRadix) & (ln2=NIL) THEN
    Out.String("*** Exp: ln2 must be precomputed!"); Out.Ln;
    err:=34; RETURN
  END;
  
  (* check for overflows and underflows *)
  IF t1>=1.0D9 THEN
    IF t1>ZERO THEN
      Out.String("*** Exp: Argument is too large "); Out.LongReal(t1, 0);
      Out.String(" x 10^"); Out.Int(n1, 0); Out.Ln; err:=35
    ELSE Zero(b)
    END;
    RETURN
  END;
  
  (* increase resolution *)
  nws:=curMant; INC(curMant);
  
  (* compute the reduced argument a' = a - Ln(2) * ENTIER(a/Ln(2)).
     Save nz = ENTIER(a/Ln(2)) for correcting the exponent of the
     final result. *)
  IF ABS(t1-Ln2)>invRadix THEN
    Div(k0, a, ln2^);
    RoundInt(k1, k0);
    RealToNumbExp(k1, t1, n1);
    nz:=Int(t1*ipower(2, SHORT(n1))+Sign(SHORT(mprxx), SHORT(t1)));
    Mul(k2, ln2^, k1);
    Sub(k0, a, k2)
  ELSE copy(a, k0); nz:=0
  END;
  tl:=k0[1]-curMant;
  
  (* check if the reduced argument is zero *)
  IF k0[0]=ZERO THEN copy(xONE, k0)
  ELSE
    (* divide the reduced argument by 2^nq *)
    Divd(k1, k0, ONE, NQ);
    
    (* compute Exp using the usual Taylor series *)
    copy(xONE, k2); copy(xONE, k3); l1:=0;
    LOOP
      INC(l1);
      IF l1=10000 THEN
        Out.String("*** Exp: Iteration limit exceeded!"); Out.Ln;
        err:=36; curMant:=SHORT(nws); RETURN
      END;
      t2:=l1;
      Mul(k0, k2, k1);
      Divd(k2, k0, t2, 0);
      Add(k0, k3, k2);
      copy(k0, k3);
      
      (* check for convergence of the series *)
      IF (k2[0]=ZERO) OR (k2[1]<tl) THEN EXIT END;
    END;
    
    (* raise to the (2^nq)-th power *)
    FOR i:=1 TO NQ DO Mul(k0, k0, k0) END
  END;
  
  (* multiply by 2^nz *)
  Muld(k1, k0, ONE, nz);
  copy(k1, b);
  
  (* restore original precision level *)
  curMant:=SHORT(nws); Round(b)
END Exp;

PROCEDURE Ln * (VAR b: RealDesc; a: RealDesc);
(*
    This routine computes the natural logarithm of the extended
    precision number `a' and returns the extended precision
    result in `b'.  This routine uses a previously calculated
    value `ln2'.  If `a' is close to 2 then `ln2' is not required
    so this procedure can be used to compute `ln2'.
    
    The Taylor series for Ln converges much more slowly than that
    of Exp.  Thus this routine does not employ the Taylor series,
    but instead computes logarithms by solving Exp(b) = a using the
    following Newton iteration, which converges to `b':
    
      X(k+1) = X(k) + (a - Exp(X(k)) / Exp(X(k))
      
    These iterations are performed with a maximum precision level
    curMant that is dynamically changed, approximately doubling 
    with each iteration.
 *) 
VAR
  ia, na, n1, nws, mq, k: LONGINT;
  t1, t2: LONGREAL;
  k0, k1, k2: FixedReal;
  iq: BOOLEAN;
BEGIN
  IF err#0 THEN Zero(b); RETURN END;
  
  (* check for error inputs *)
  ia:=Sign(ONE, a[0]); na:=Min(ENTIER(ABS(a[0])), curMant);
  IF (ia<0) OR (na=0) THEN Out.String("*** Ln: Argument is less than or equal to zero!");
    Out.Ln; err:=50; RETURN
  END;
  
  (* unless the input is close to 2, ln2 must be known *)
  RealToNumbExp(a, t1, n1);
  IF ((ABS(t1-2.0D0)>1.0D-3) OR (n1#0)) & (ln2=NIL) THEN
    Out.String("*** Ln: Ln(2) must be precomputed!"); Out.Ln; err:=51; RETURN
  END;
  
  (* check if input is exactly one *)
  IF (a[0]=ONE) & (a[1]=ZERO) & (a[2]=ONE) THEN Zero(b); RETURN END;
  
  (* determine the least integer mq such that 2^mq >= curMant *)
  nws:=curMant; t2:=nws; mq:=Int(invLn2*rm.ln(t2)+ONE-mprxx);
  
  (* compute initial approximation of Ln(a) *)
  t1:=rm.ln(t1)+n1*Ln2; NumbExpToReal(t1, 0, b);
  curMant:=3; iq:=FALSE;
  FOR k:=2 TO mq DO
    curMant:=SHORT(Min(2*curMant-2, nws)+1);
    LOOP
      Exp(k0, b);        (* k0 = Exp(X(k)) *)
      Sub(k1, a, k0);    (* k1 = a - Exp(X(k)) *)
      Div(k2, k1, k0);   (* k2 = (a - Exp(X(k))) / Exp(X(k)) *)
      Add(k1, b, k2);    (* k1 = X(k) + (a - Exp(X(k))) / Exp(X(k)) *)
      copy(k1, b);
      IF (k=mq-NIT) & ~iq THEN iq:=TRUE
      ELSE EXIT
      END
    END
  END;
  
  (* restore original precision *)
  curMant:=SHORT(nws); Round(b)
END Ln;

PROCEDURE SinCos * (VAR sin, cos: RealDesc; a: RealDesc);
(* 
     This routine computes the cosine and sine of the extended
     precision number `a' and returns the results in `cos' and
     `sin', respectively.  The units of `a' are in radians.
     
     The calculations are performed using the conventional Taylor's
     series for Sin(s):
     
       Sin(s) = s - s^3/3! + s^5/5! - s^7/7! ....
       
     where s = t - a * pi/2 - b*pi/16 and the integers a and b are
     chosen to minimize the absolute value of s.  We can then compute
     
       Sin (t) = Sin (s + a*pi/2 + b*pi/16)
       Cos (t) = Cos (s + a*pi/2 + b*pi/16) 
       
     by applying elementary trig identities for sums.  The sine and
     cosine of b*pi/16 are of the form 1/2*Sqrt(2 +- Sqrt(2 +- Sqrt(2))).
     Reducing t in this manner ensures that -Pi/32 < s < Pi/32 which
     accelerates convergence in the above series.
 *)
VAR
  t1, t2: LONGREAL;
  nws: INTEGER;
  f: Real8;
  ia, na, ka, kb, n1, kc, l1: LONGINT;
  k0, k1, k2, k3, k4, k5, k6: FixedReal;
BEGIN
  IF err#0 THEN Zero(sin); Zero(cos); RETURN END;
  
  ia:=Sign(ONE, a[0]); na:=Min(ENTIER(ABS(a[0])), curMant);
  
  (* check for trivial case when a = 0 *)
  IF na=0 THEN copy(xONE, cos); Zero(sin); RETURN END;
  
  (* check if pi has been precomputed *)
  IF pi=NIL THEN Out.String("*** SinCos: pi must be precomputed!");
    Out.Ln; err:=28; RETURN
  END;
  
  (* increase resolution *)
  nws:=curMant; INC(curMant);
  
  (* reduce input to between -pi and pi *)
  Muld(k0, pi^, 2.0D0, 0);
  Div(k1, a, k0);
  RoundInt(k2, k1);       (* k2 = a DIV 2pi *)
  Sub(k3, k1, k2);        (* k3 = a MOD 2pi *)
  
  (* determine the nearest multiple of pi/2, and within a
     quadrant, the nearest multiple of pi/16.  Through most
     of the rest of this procedure, ka and kb are the integers
     a and b of the above algorithm. *)
  RealToNumbExp(k3, t1, n1);
  IF n1>=-NBT THEN
    t1:=t1*ipower(2, SHORT(n1)); t2:=4*t1;
    IF t2<ZERO THEN ka:=-ENTIER(HALF-t2) ELSE ka:=ENTIER(t2+HALF) END;  (* ka:=rm.round(t2) *)
    t1:=8*(t2-ka);
    IF t1<ZERO THEN kb:=-ENTIER(HALF-t1) ELSE kb:=ENTIER(t1+HALF) END;  (* kb:=rm.round(8*(t2-ka)) *)
    (* ka:=ENTIER(t2); kb:=rm.round(8*(t2-ka)) *)
  ELSE ka:=0; kb:=0
  END;
  t1:=(8*ka+kb)/32;
  NumbExpToReal(t1, 0, k1);
  Sub(k2, k3, k1);
  Mul(k1, k0, k2);

  (* compute cosine and sine of the reduced arguments using
     Taylor's series *)
  IF k1[0]=ZERO THEN Zero(k0)
  ELSE
    copy(k1, k0); Mul(k2, k0, k0); l1:=0;
    LOOP
      INC(l1);
      IF l1=10000 THEN
        Out.String("*** SinCos: Iteration limit exceeded!"); Out.Ln;
        err:=29; curMant:=nws; RETURN
      END;
      t2:=-(2.0D0*l1)*(2.0D0*l1+ONE);
      Mul(k3, k2, k1);
      Divd(k1, k3, t2, 0);
      Add(k3, k1, k0);
      copy(k3, k0);
      
      (* check for convergence of the series *)
      IF (k1[0]=ZERO) OR (k1[1]<k0[1]-curMant) THEN EXIT END
    END
  END;

  (* compute Cos(s) = Sqrt(1-Sin(s)^2) *)
  copy(k0, k1);
  Mul(k2, k0, k0); Sub(k3, xONE, k2); Sqrt(k0, k3);
  
  (* compute cosine and sine of b*Pi/16 *)
  kc:=ABS(kb); f[0]:=ONE; f[1]:=ZERO; f[2]:=2.0;
  IF kc=0 THEN copy(xONE, k2); Zero(k3)
  ELSE
    CASE kc OF
    | 1: Sqrt(k4, f); Add(k5, f, k4); Sqrt(k4, k5)
    | 2: Sqrt(k4, f)
    | 3: Sqrt(k4, f); Sub(k5, f, k4); Sqrt(k4, k5)
    | 4: Zero(k4)
    | ELSE (* do nothing *)
    END;
    Add(k5, f, k4); Sqrt(k3, k5); Muld(k2, k3, HALF, 0);
    Sub(k5, f, k4); Sqrt(k4, k5); Muld(k3, k4, HALF, 0)
  END; 
  
  (* apply the trigonometric summation identities to compute
     cosine and sine of s + b*Pi/16 *)
  IF kb<0 THEN k3[0]:=-k3[0] END;
  Mul(k4, k0, k2); Mul(k5, k1, k3); Sub(k6, k4, k5);
  Mul(k4, k1, k2); Mul(k5, k0, k3); Add(k1, k4, k5);
  copy(k6, k0);   
  
  (* this code applies the trig summation identities for
     (s + b*pi/16 + a*pi/2 *)
  CASE ka OF
  |     0: copy(k0, cos); copy(k1, sin)
  |     1: copy(k1, cos); cos[0]:=-cos[0]; copy(k0, sin)
  |    -1: copy(k1, cos); copy(k0, sin); sin[0]:=-sin[0]
  | 2, -2: copy(k0, cos); cos[0]:=-cos[0]; copy(k1, sin); sin[0]:=-sin[0]
  | ELSE (* do nothing *)
  END;
  
  (* restore the orginal precision level *)
  curMant:=nws; Round(cos); Round(sin)
END SinCos;

PROCEDURE SinhCosh * (VAR sinh, cosh: RealDesc; a: RealDesc);
(*
    This routine computes the hyperbolic cosine and sine of the
    number `a' and returns the two results in `cosh' and `sinh',
    respectively.  The last word of the result is not reliable.
 *)
VAR
  k0, k1, k2: FixedReal;
  nws: INTEGER;
BEGIN
  nws:=curMant; INC(curMant);
  Exp(k0, a); Div(k1, xONE, k0);         (* k1 = exp(-a); k0 = exp(a) *)
  Add(k2, k0, k1);                       (* k2 = exp(a) + exp(-a) *)
  Muld(k2, k2, HALF, 0); copy(k2, cosh); (* cosh = (exp(a) + exp(-a))/2 *)
  Sub(k2, k0, k1);                       (* k2 = exp(a) - exp(-a) *)
  Muld(k2, k2, HALF, 0); copy(k2, sinh); (* sinh = (exp(a) - exp(-a))/2 *)
  
  (* restore orginal precision *)
  curMant:=nws; Round(cosh); Round(sinh)
END SinhCosh;

PROCEDURE ATan2 * (VAR a: RealDesc; x, y: RealDesc);
(*
    This routine computes the angle `a' subtended by the
    pair (`x', `y') considered as a point in the x-y plane.
    This routine places the resultant angle correctly in the
    full circle where -pi < `a' <= pi.  The last word of the
    result is not reliable.
    
    The Taylor series for Arcsin converges much more slowly than
    that of Sin.  Thus this routine does not employ a Taylor
    series, but instead computes Arccos or Arcsin by solving
    Cos(a) = x or Sin(a) = y using one of the following Newton
    iterations, both of which converge to `a':
    
      z(k+1) = z(k) - (x - Cos(z(k))) / Sin(z(k))
      z(k+1) = z(k) - (y - Sin(z(k))) / Cos(z(k))
      
    The first is selected if Abs(x) <= Abs(y); otherwise the
    second is used.  These iterations are performed with a
    maximum precision level curMant that is dynamically changed,
    approximately doubling with each iteration.
 *)
CONST
  NIT=3;
VAR
  t1, t2, t3: LONGREAL;
  iq: BOOLEAN;
  nws: INTEGER;
  ix, iy, nx, ny, mq, n1, n2, kk, k: LONGINT;
  k0, k1, k2, k3, k4: FixedReal;
BEGIN
  IF err#0 THEN Zero(a); RETURN END;
  ix:=Sign(ONE, x[0]); nx:=Min(ENTIER(ABS(x[0])), curMant);
  iy:=Sign(ONE, y[0]); ny:=Min(ENTIER(ABS(y[0])), curMant); 
  
  (* check if both x and y are zero *)
  IF (nx=0) & (ny=0) THEN
    Out.String("*** ATan2: Both arguments are zero!"); Out.Ln;
    err:=7; RETURN
  END;
  
  (* check if pi has been precomputed *)
  IF pi=NIL THEN
    Out.String("*** ATan2: Pi must be precomputed!"); Out.Ln;
    err:=8; RETURN
  END;
  
  (* check if one of x or y is zero *)
  IF nx=0 THEN
    IF iy>0 THEN Muld(a, pi^, HALF, 0)
    ELSE Muld(a, pi^, -HALF, 0)
    END;
    RETURN
  ELSIF ny=0 THEN
    IF ix>0 THEN Zero(a) ELSE copy(pi^, a) END;
    RETURN
  END;
  
  (* increase the resolution *)
  nws:=curMant; INC(curMant);
  
  (* determine the least integer mq such that 2^mq >= curMant *)
  mq:=Int(invLn2*rm.ln(nws)+ONE-mprxx);
  
  (* normalize x and y so that x^2 + y^2 = 1 *)
  Mul(k0, x, x); Mul(k1, y, y); Add(k2, k0, k1); Sqrt(k3, k2);
  Div(k1, x, k3); Div(k2, y, k3);
  
  (* compute initial approximation of the angle *)
  RealToNumbExp(k1, t1, n1); RealToNumbExp(k2, t2, n2);
  n1:=Max(n1, -66); n2:=Max(n2, -66);
  t1:=t1*ipower(2, SHORT(n1)); t2:=t2*ipower(2, SHORT(n2));
  t3:=rm.arctan2(t2, t1);
  NumbExpToReal(t3, 0, a);
  
  (* the smaller of x or y will be used from now on to measure convergence.
     This selects the Newton iteration (of the two listed above) that has
     the largest denominator *)
  IF ABS(t1)<=ABS(t2) THEN kk:=1; copy(k1, k0)
  ELSE kk:=2; copy(k2, k0)
  END;
  
  (* perform the Newton-Raphson iteration described above with a dynamically
     changing precision level curMant (one greater than powers of two). *)
  curMant:=3; iq:=FALSE;
  FOR k:=2 TO mq DO
    curMant:=SHORT(Min(2*curMant-2, nws)+1);
    LOOP
      SinCos(k2, k1, a);    
      IF kk=1 THEN Sub(k3, k0, k1); Div(k4, k3, k2); Sub(k1, a, k4)     
      ELSE Sub(k3, k0, k2); Div(k4, k3, k1); Add(k1, a, k4)         
      END;
      copy(k1, a);
      IF ~iq & (k=mq-NIT) THEN iq:=TRUE ELSE EXIT END
    END
  END;
  
  (* restore the original precision *)
  curMant:=nws; Round(a)
END ATan2;

(*---------------------------------------------------------*)
(*                                                         *)
(* The following routines are intended for external users  *)
(*                                                         *)
(*---------------------------------------------------------*)
(* Constructors                                            *)

PROCEDURE Long * (x: LONGREAL) : Real;
VAR 
  r: Real;
BEGIN
  (* create a new number *)
  NEW(r, curMant+3); 
  NumbExpToReal(x, 0, r^);
  RETURN r
END Long;

PROCEDURE Copy * (a: Real) : Real;
(*
    Return a copy of `a'.
 *)
VAR
  b: Real;
BEGIN
  NEW(b, curMant+3);
  copy(a^, b^);  (* b:=a *)
  RETURN b
END Copy;

PROCEDURE ToReal * (str: ARRAY OF CHAR) : Real;
(*
    Converts the number in `str' to an extended Real and
    returns the result.  The number representation is
    given by:
    
       number = ["+"|"-"] {digit} ["." {digit}] [scale]
       
    where  scale = "E"|"D" ["+"|"-"] digit {digit}
    and    digit = "0".."9" | " "
    
    Thus the following is a valid input number:
    
           "1.23456 12938 23456 E + 200"
           
    Note: This real number definition is backwardly
    compatible with the Oberon-2 real string but has
    been extended to allow splitting of very large
    numbers into more readable segments by inserting
    spaces.
 *)
VAR
  b: Real;
  s: FixedReal;
  nexp, es, is, cc, dig, nws, dp: LONGINT;
  isZero: BOOLEAN;
  f: Real8;
  
  PROCEDURE SkipBlanks;
  BEGIN
    WHILE str[cc]=" " DO INC(cc) END
  END SkipBlanks;
  
  PROCEDURE GetDigit () : LONGINT;
  (* skips blanks to get a digit; returns
     -1 on an invalid digit *)
  VAR ch: CHAR;
  BEGIN
    SkipBlanks; ch:=str[cc];
    IF (ch>="0") & (ch<="9") THEN
      INC(cc);
      IF ch>"0" THEN isZero:=FALSE END;
      RETURN ORD(ch)-ORD("0")
    ELSE RETURN -1
    END
  END GetDigit;
  
  PROCEDURE GetSign () : LONGINT;
  BEGIN
    SkipBlanks; (* skip leading blanks *)
  
    (* check for leading sign *)
    IF str[cc]="+" THEN INC(cc); RETURN 1
    ELSIF str[cc]="-" THEN INC(cc); RETURN -1
    ELSE RETURN 1
    END
  END GetSign;
  
BEGIN
  cc:=0; nws:=curMant; INC(curMant);
  
  (* check for initial sign *)
  is:=GetSign();
  
  (* clear result *)
  Zero(s); f[0]:=ONE; f[1]:=ZERO;
  
  (* scan for digits, stop on a non-digit *)
  isZero:=TRUE;
  LOOP
    dig:=GetDigit();
    IF dig<0 THEN EXIT END;
    IF ~isZero THEN Muld(s, s, 10.0, 0) END; 
    IF dig#0 THEN f[2]:=dig; Add(s, f, s) END   
  END;
  
  (* check for decimal point *)
  dp:=0;
  IF str[cc]="." THEN
    INC(cc);
    LOOP
      dig:=GetDigit();
      IF dig<0 THEN EXIT END;     
      Muld(s, s, 10.0, 0);
      IF dig#0 THEN f[0]:=ONE; f[2]:=dig 
      ELSE f[0]:=ZERO
      END;
      INC(dp); Add(s, f, s)
    END
  END;
  
  (* check for exponent *)
  nexp:=0;
  IF (str[cc]="E") OR (str[cc]="D") THEN
    INC(cc);
    es:=GetSign();
    LOOP
      dig:=GetDigit();
      IF dig<0 THEN EXIT END;
      nexp:=nexp*10+dig
    END; 
    nexp:=es*nexp  (* add the sign *)
  END;
  
  (* scale the resultant number *)
  s[0]:=s[0]*is; DEC(nexp, dp);
  f[0]:=ONE; f[2]:=10.0; NEW(b, curMant+4); 
  IntPower(b^, f, nexp); Mul(s, b^, s); copy(s, b^); 
  
  (* back to original resolution *)
  curMant:=SHORT(nws); Round(b^);
  RETURN b
END ToReal;


(*---------------------------------------------------------*)
(* Conversion routines                                     *)

PROCEDURE ToString * (a: Real; VAR str: ARRAY OF CHAR; n: LONGINT);
(* 
     Converts `a' to a number in scientific notation to `n'
     significant places.  The length of `str' should be at 
     least `n'+15 characters.
 *)
CONST
  log2=0.301029995663981195D0;
VAR
  aa, t1: LONGREAL;
  f: Real8;
  k: FixedReal;
  ok: BOOLEAN;
  nn, cc, nws, na, ia, nx, nl, j, l: LONGINT;
  
  PROCEDURE AddChar (c: CHAR);
  BEGIN
    str[cc]:=c; INC(cc)    
  END AddChar;
  
  PROCEDURE AddDigit (d: LONGINT);
  BEGIN
    AddChar(CHR(d+ORD("0")))
  END AddDigit;
  
  PROCEDURE AddInt (n: LONGINT);
  BEGIN
    IF n<10 THEN AddDigit(n)
    ELSE AddInt(n DIV 10); AddDigit(n MOD 10)
    END
  END AddInt;
  
BEGIN
  ia:=Sign(ONE, a[0]); na:=Min(ENTIER(ABS(a[0])), curMant);
  nws:=curMant; INC(curMant);
  f[0]:=ONE; f[1]:=ZERO; f[2]:=10;
  
  (* determine the exact power of ten for exponent *)
  IF na#0 THEN
    aa:=a[2];
    IF na>=2 THEN aa:=aa+invRadix*a[3] END;
    IF na>=3 THEN aa:=aa+mprx2*a[4] END;
    IF na>=4 THEN aa:=aa+invRadix*mprx2*a[5] END;
    t1:=log2*NBT*a[1]+rm.log(aa, 10);
    IF t1>=ZERO THEN nx:=Int(t1) ELSE nx:=Int(t1-ONE) END;
    IntPower(k, f, nx);  (* k = 10**nx *)
    Div(k, a^, k);     (* k = a*10**nx *) 
    
    (* adjust k if above is not quite right *)
    WHILE k[1]<0 DO DEC(nx); Muld(k, k, 10.0, 0) END;
    WHILE k[2]>=10.0 DO INC(nx); Divd(k, k, 10.0, 0) END;
    k[0]:=ABS(k[0])
  ELSE nx:=0
  END;
  
  (* output the sign and first digit *)
  IF ia=-1 THEN str[0]:="-"; cc:=1 ELSE cc:=0 END;
  IF na#0 THEN nn:=Int(k[2]) ELSE nn:=0 END;
  AddDigit(nn); AddChar(".");
   
  (* output the remaining mantissa digits *)
  IF na#0 THEN
    f[2]:=nn; Sub(k, k, f);
    IF k[0]#ZERO THEN
      Muld(k, k, 10.0, 0);
      nl:=Min(maxDigits-1, Max(Int((curMant-1)*rm.log(radix, 10))-1, 1));
      IF n>1 THEN nl:=n-1 END;
      j:=1; ok:=TRUE;
      WHILE ok & (j<=nl) DO
        IF k[1]=ZERO THEN nn:=Int(k[2]); f[0]:=1; f[2]:=nn
        ELSE f[0]:=0; nn:=0
        END;
        AddDigit(nn); Sub(k, k, f); Muld(k, k, 10.0, 0);
        IF k[0]=ZERO THEN ok:=FALSE
        ELSE INC(j)
        END
      END;
      
      (* check if trailing zeros should be trimmed *)
      l:=cc-1;
      IF str[l]="0" THEN
        WHILE (str[l]="0") & (str[l-1]#".") DO DEC(l) END;

      (* check if trailing nines should be rounded up *)
      ELSIF (j>nl) & (str[l]="9") & (str[l-1]="9") & (str[l-2]="9") THEN
        WHILE str[l]="9" DO DEC(l) END;
        IF (str[l]=".") & (str[l-1]="9") THEN
          (* all digits to the right of the decimal point
             have been rounded away.  Set digit to 1 and
             increase exponent by one *)
          INC(nx); str[l-1]:="1"; str[l+1]:="0"; INC(l)
        ELSE str[l]:=CHR(ORD(str[l])+1)
        END
      END;
      cc:=l+1
    END;
    
    (* output the exponent *)
    IF str[cc-1]="." THEN AddChar("0") END;  (* ensure one trailing zero *)
    AddChar("E");
    IF nx<0 THEN AddChar("-"); nx:=-nx ELSE AddChar("+") END;
    AddInt(nx)
  ELSE AddChar("0"); AddChar("E"); AddChar("+"); AddChar("0")  (* output 0.0E+0 for zero *)
  END;
  str[cc]:=0X;
  curMant:=SHORT(nws)
END ToString;

PROCEDURE short * (q: Real) : LONGREAL;
VAR
  x: LONGREAL; exp: LONGINT;
BEGIN
  RealToNumbExp(q^, x, exp);  
  RETURN x*ipower(2, SHORT(exp));
  (* RETURN lr.scale(x, SHORT(exp)) *)
END short;

PROCEDURE entier * (q: Real) : Real;
VAR
  r: Real;
BEGIN
  NEW(r, curMant+4);
  Entier(r^, q^);
  RETURN r
END entier;

PROCEDURE fraction * (q: Real) : Real;
VAR
  r: Real;
BEGIN
  r:=entier(q);
  IF q[0]<ZERO THEN Add(r^, q^, xONE) END;
  Sub(r^, q^, r^);
  RETURN r
END fraction;

(*---------------------------------------------------------*)
(* Basic math routines                                     *)

PROCEDURE add * (z1, z2: Real): Real;
VAR
  r: Real;
BEGIN
  NEW(r, curMant+4);
  Add(r^, z1^, z2^);
  RETURN r
END add;

PROCEDURE sub * (z1, z2: Real): Real;
VAR
  r: Real;
BEGIN
  NEW(r, curMant+4);
  Sub(r^, z1^, z2^);
  RETURN r
END sub;

PROCEDURE mul * (z1, z2: Real): Real;
VAR
  r: Real;
BEGIN
  NEW(r, curMant+4);
  Mul(r^, z1^, z2^);
  RETURN r
END mul;
  
PROCEDURE div * (z1, z2: Real): Real;
VAR
  r: Real;
BEGIN
  NEW(r, curMant+4);
  Div(r^, z1^, z2^);
  RETURN r
END div;
  
PROCEDURE abs * (z: Real): Real;
  (* Returns the absolute value of z *)
VAR
  r: Real;
BEGIN
  NEW(r, curMant+2);
  Abs(r^, z^);
  RETURN r
END abs;

PROCEDURE cmp * (a, b: Real) : LONGINT;
(*
     This routine compares the extended numbers `a' and `b' and
     returns the value -1, 0, or 1 depending on whether `a'<`b',
     `a'=`b', or `a'>`b'.  It is faster than merely subtracting
     `a' and `b' and looking at the sign of the result.
 *)
BEGIN
  RETURN Cmp(a^, b^)
END cmp;
 
(*---------------------------------------------------------*)
(* Power and transcendental routines                       *)
  
PROCEDURE power * (x, exp: Real): Real;
  (* Returns the value of the number x raised to the power exp *)
VAR
  r: Real;
BEGIN
  NEW(r, curMant+4);
  
  (* check for integer powers *)
  Entier(r^, exp^);
  IF cmp(r, exp)=0 THEN IntPower(r^, x^, Int(short(r)))
  ELSE (* x^exp = Exp(exp*Ln(x)) *)
    Ln(r^, x^); Mul(r^, exp^, r^); Exp(r^, r^)
  END;
  RETURN r
END power;

PROCEDURE root * (z: Real; n: LONGINT): Real;
  (* Returns the `n'th root of `z' *)
VAR
  r: Real;
BEGIN
  NEW(r, curMant+4);
  Root(r^, z^, n);
  RETURN r
END root;

PROCEDURE sqrt * (z: Real): Real;
  (* Returns the principal square root of z, with arg in the range [-pi/2, pi/2] *)
VAR
  r: Real;
BEGIN
  NEW(r, curMant+4);
  Sqrt(r^, z^);
  RETURN r
END sqrt;
 
PROCEDURE exp * (z: Real): Real;
  (* Returns the complex exponential of z *)
VAR
  r: Real;
BEGIN
  NEW(r, curMant+4);
  Exp(r^, z^);
  RETURN r
END exp;
 
PROCEDURE ln * (z: Real): Real;
  (* Returns the principal value of the natural logarithm of z *)
VAR
  r: Real;
BEGIN
  NEW(r, curMant+4);
  Ln(r^, z^);
  RETURN r
END ln;

PROCEDURE log * (z, base: Real): Real;
  (* Returns the principal value of the natural logarithm of z *)
VAR
  r: Real; t: FixedReal;
BEGIN
  NEW(r, curMant+4);
  Ln(r^, z^); Ln(t, base^); Div(r^, r^, t);
  RETURN r
END log;

PROCEDURE sin * (z: Real): Real;
  (* Returns the sine of z *)
VAR
  s: Real; c: FixedReal;
BEGIN
  NEW(s, curMant+4);
  SinCos(s^, c, z^);
  RETURN s
END sin;
 
PROCEDURE cos * (z: Real): Real;
  (* Returns the cosine of z *)
VAR
  s: FixedReal; c: Real;
BEGIN
  NEW(c, curMant+4);
  SinCos(s, c^, z^);
  RETURN c
END cos;

PROCEDURE sincos * (z: Real; VAR sin, cos: Real);
  (* Returns the sine & cosine of z *)
BEGIN
  NEW(sin, curMant+4); NEW(cos, curMant+4);
  SinCos(sin^, cos^, z^)
END sincos; 
 
PROCEDURE tan * (z: Real): Real;
  (* Returns the tangent of z *)
VAR
  s, c: FixedReal; r: Real;
BEGIN
  NEW(r, curMant+4);
  SinCos(s, c, z^); Div(r^, s, c);
  RETURN r
END tan;
 
PROCEDURE arcsin * (z: Real): Real;
  (* Returns the arcsine of z *)
VAR
  t: FixedReal; r: Real;
BEGIN
  NEW(r, curMant+4);
  Abs(t, z^);
  IF Cmp(t, xONE)>0 THEN 
    Out.String("*** Illegal arcsin argument!"); Out.Ln; err:=20
  ELSE  
    Mul(t, t, t); Sub(t, xONE, t); Sqrt(t, t);  (* t = Sqrt(1 - z^2) *)     
    ATan2(r^, t, z^)                            (* r = ATan(z/Sqrt(1-z^2)) *)
  END;
  RETURN r
END arcsin;
 
PROCEDURE arccos * (z: Real): Real;
  (* Returns the arccosine of z *)
VAR
  t: FixedReal; r: Real;
BEGIN
  NEW(r, curMant+4);
  Abs(t, z^);
  IF Cmp(t, xONE)>0 THEN 
    Out.String("*** Illegal arccos argument!"); Out.Ln; err:=21
  ELSE
    Mul(t, t, t); Sub(t, xONE, t); Sqrt(t, t);  (* t = Sqrt(1 - z^2) *)
    ATan2(r^, z^, t)                            (* r = ATan(Sqrt(1-z^2)/z) *)
  END;
  RETURN r
END arccos;
 
PROCEDURE arctan * (z: Real): Real;
  (* Returns the arctangent of z *)
VAR
  r: Real;
BEGIN
  NEW(r, curMant+4);
  ATan2(r^, xONE, z^);
  RETURN r
END arctan;

PROCEDURE arctan2 * (xn, xd: Real): Real;
  (* Returns the arctangent of xn/xd *)
VAR
  r: Real;
BEGIN
  NEW(r, curMant+4);
  ATan2(r^, xd^, xn^);
  RETURN r
END arctan2;

PROCEDURE sinhcosh * (z: Real; VAR sinh, cosh: Real);
  (* Returns the hyberbolic sine & cosine of z *)
BEGIN
  NEW(sinh, curMant+4); NEW(cosh, curMant+4);
  SinhCosh(sinh^, cosh^, z^)
END sinhcosh; 

PROCEDURE sinh * (z: Real): Real;
  (* Returns the hyperbolic sine of z *)
VAR
  s: Real;
  c: FixedReal;  
BEGIN
  NEW(s, curMant+4); SinhCosh(s^, c, z^);
  RETURN s
END sinh;
 
PROCEDURE cosh * (z: Real): Real;
  (* Returns the hyperbolic cosine of z *)
VAR
  c: Real;
  s: FixedReal; 
BEGIN
  NEW(c, curMant+4); SinhCosh(s, c^, z^);
  RETURN c
END cosh;

PROCEDURE tanh * (z: Real): Real;
  (* Returns the hyperbolic tangent of z *)
VAR
  sinh, cosh: FixedReal; r: Real;
BEGIN
  NEW(r, curMant+4);
  SinhCosh(sinh, cosh, z^); Div(r^, sinh, cosh);  
  RETURN r
END tanh;

PROCEDURE OutReal (n: Real);
VAR str: ARRAY 256 OF CHAR;
BEGIN
  ToString(n, str, outDigits); Out.String(str)
END OutReal;


PROCEDURE Test;
VAR
  s, n, m: Real;  
BEGIN
  Out.String("pi="); OutReal(pi); Out.Ln;
  Out.String("ln2="); OutReal(ln2); Out.Ln;
  Out.String("ln10="); OutReal(ln10); Out.Ln;
  Out.String("eps="); OutReal(eps); Out.Ln;
  Out.String("log10(eps)="); OutReal(log(eps, Long(10))); Out.Ln;
  n:=ToReal("123456789012345678901234567890123456789");
  m:=ToReal("0.123456789012345678901234567890123456790");
  CASE cmp(n, m) OF
  | 0: Out.String("n=m")
  | 1: Out.String("n>m")
  | ELSE Out.String("n<m")
  END;
  Out.Ln;
  Out.String("n="); OutReal(n); Out.Ln;
  Out.String("m="); OutReal(m); Out.Ln;
  s:=mul(n, m);
  Out.String("n*m="); OutReal(s); Out.Ln;
  s:=add(n, m);
  Out.String("n+m="); OutReal(s); Out.Ln;
  s:=sub(n, m);
  Out.String("n-m="); OutReal(s); Out.Ln;  
  s:=div(n, m);
  Out.String("n/m="); OutReal(s); Out.Ln;
  s:=div(Long(1), Long(3));
  Out.String("1/3="); OutReal(s); Out.Ln;
  Out.String("1/3+1/3="); OutReal(add(s, s)); Out.Ln;
  Out.String("1/3*1/3="); OutReal(mul(s, s)); Out.Ln;
  Out.String("1/3*3="); OutReal(mul(s, Long(3))); Out.Ln;
  n:=Long(2.0);
  s:=power(n, Long(64));
  Out.String("2^64="); OutReal(s); Out.Ln;
  n:=ToReal("1.010E-10");
  Out.String("1.010E-10="); OutReal(n); Out.Ln;
  n:=ToReal("-12.0E+10");
  Out.String("-12.0E+10="); OutReal(n); Out.Ln;
  n:=ToReal("0.00045E-10");  
  Out.String("0.00045E-10="); OutReal(n); Out.Ln;
  n:=ToReal("-12 345 678");  
  Out.String("-12 345 678="); OutReal(n); Out.Ln;  
  n:=ToReal("1E10000");  
  Out.String("1E10000="); OutReal(n); Out.Ln;    
  sincos(pi, m, n);
  Out.String("Sin(pi)="); OutReal(m); Out.Ln;
  Out.String("Cos(pi)="); OutReal(n); Out.Ln;
  sincos(div(pi, Long(8)), m, n);  
  Out.String("Sin(pi/8)="); OutReal(m); Out.Ln;
  Out.String("Cos(pi/8)="); OutReal(n); Out.Ln;
  sincos(Long(1), m, n);
  Out.String("Sin(1)="); OutReal(m); Out.Ln;
  Out.String("Cos(1)="); OutReal(n); Out.Ln;   
  Out.String("-8^(-1/3)="); OutReal(root(Long(-8), 3)); Out.Ln;
  Out.String("(2^64)^(-1/64)="); OutReal(root(power(Long(2), Long(64)), 64)); Out.Ln;
  Out.String("4*arctan(1)="); OutReal(mul(Long(4), arctan(Long(1)))); Out.Ln;
  Out.String("arcsin(sin(1))="); OutReal(arcsin(sin(Long(1)))); Out.Ln;
  Out.String("ENTIER(3.6)="); OutReal(entier(Long(3.6))); Out.Ln;
  Out.String("ENTIER(-3.6)="); OutReal(entier(Long(-3.6))); Out.Ln;  
END Test;

PROCEDURE Init;
TYPE
  LongFixed = ARRAY 2*(maxMant+4) OF REAL;
VAR
  t0, t1, t2, t3, t4: LongFixed;
BEGIN
  (* internal constants *)
  xONE[0]:=ONE; xONE[1]:=ZERO; xONE[2]:=ONE;  (* 1.0 *)
  
  Out.Open;
    
  (* initialize internal constants *)
  err:=0; curMant:=maxMant+1; debug:=0; numBits:=22;
  
  (* compute required constants to correct precision *)
  Pi(t1);                      (* t1 = pi *)
  NumbExpToReal(2, 0, t0);     (* t0 = 2.0 *)
  ln2:=NIL; Ln(t2, t0);        (* t2 = Ln(2.0) *)
  NEW(ln2, LEN(t0)); copy(t2, ln2^);
  NumbExpToReal(10, 0, t0);    (* t0 = 10.0 *)
  Ln(t3, t0);                  (* t3 = Ln(10.0) *)
  IntPower(t4, t0, log10eps);  (* t4 = 10^(10-maxDigits) *)
  
  (* transfer to current variables *)
  curMant:=maxMant; 
  NEW(pi, curMant+4); copy(t1, pi^);
  NEW(ln2, curMant+4); copy(t2, ln2^);  
  NEW(ln10, curMant+4); copy(t3, ln10^);
  NEW(eps, curMant+4); copy(t4, eps^); 
  
  (* set the current output precision *)
  sigDigs:=maxDigits
END Init;

PROCEDURE SetWords * (words: INTEGER);
BEGIN
  IF (words>0) & (words<=maxMant) THEN
    curMant:=words
  END
END SetWords;

BEGIN
  Init;
END Reals.

