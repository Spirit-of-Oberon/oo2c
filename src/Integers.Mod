(*	$Id$	*)
MODULE Integers;

(*
    Integers - Arbitrary precision integer operations.       
    Copyright (C) 1996 Computer Inspirations
 
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

    Algorithms are from Knuth: "The Art Of Computer Programming", 
    Vol 2, section 4.3.1
*)
  
IMPORT BinaryRider;

CONST
  B  = 8000H;      (* base (32768) for calculations *)
  (* Log2B = 15; *)      (* log2(B) *)
  BR = B+0.0;      (* real version *)

TYPE
  Integer* = POINTER TO IntegerDesc;
  IntegerDesc = ARRAY OF INTEGER;
  
  (* 
      Internal integer representation:
  
        I[0]    - Sign (1 for positive, 0 for zero, -1 for negative)
        I[1..n] - Unsigned integer number with 16-bits/entry
                  where I[1] is the most significant "digit"
   *)

CONST
  positive=1; negative=-1;
  
VAR
  ZERO, ONE: Integer;
    
  (***********************************************************)
  (* Internal Operations on Integers                         *)
  
  PROCEDURE New (n: LONGINT) : Integer;
  VAR d: Integer; i: LONGINT;
  BEGIN
    NEW(d, n); d[0]:=positive;
    FOR i:=1 TO n-1 DO d[i]:=0 END;  (* clear number *)
    RETURN d
  END New;
    
  PROCEDURE Copy (VAR s: ARRAY OF INTEGER; n: LONGINT) : Integer;
  (* n is number of occupied elements in s, including the sign *)
  VAR d: Integer; i, j: LONGINT;
  BEGIN
    IF n=0 THEN n:=LEN(s) END;
    
    (* reduce the size of the number -- if needed *)
    i:=1; WHILE (s[i]=0) & (i<n-1) DO INC(i) END; 
    DEC(i); DEC(n, i);  
    
    (* create a new number and copy contents *)
    NEW(d, n); FOR j:=1 TO n-1 DO d[j]:=s[i+j] END;
    d[0]:=s[0];  (* copy the sign *)
    RETURN d
  END Copy;
  
  PROCEDURE Assign (VAR w, u : ARRAY OF INTEGER);
  (* Pre: LEN(w)>= LEN(u); Post: w=u *)
  VAR i, j, lw, lu: LONGINT;
  BEGIN
    lw:=LEN(w)-1; lu:=LEN(u)-1;
    ASSERT(lw>=lu, 105);
    j:=lw;
    FOR i:=lu TO 1 BY -1 DO w[j]:=u[i]; DEC(j) END; (* w := u *)
    FOR i:=j TO 1 BY -1 DO w[i]:=0 END;  (* zero other digits *)
    w[0]:=u[0] (* copy the sign *)
  END Assign;
   
  PROCEDURE Sub (x: ARRAY OF INTEGER; VAR y: ARRAY OF INTEGER) : Integer;
  (* Pre: x>0, y>0, LEN(x)>=LEN(y); Post: z=x-y *)
  VAR xt, yt, i, j, len, borrow: LONGINT;
  BEGIN
    len:=LEN(x)-1; j:=LEN(y)-1; borrow:=0;
    FOR i:= len TO 1 BY -1 DO
      xt:=x[i]; 
      IF j<1 THEN yt:=0 ELSE yt:=y[j] END;
      IF xt<yt THEN x[i]:=SHORT(B+xt-yt+borrow); borrow:=-1
      ELSE x[i]:=SHORT(xt-yt+borrow); borrow:=0
      END;
      DEC(j)
    END;
    ASSERT(borrow=0, 100);
    RETURN Copy(x, len+1)
  END Sub;
   
  PROCEDURE Add (x: ARRAY OF INTEGER; VAR y: ARRAY OF INTEGER) : Integer;
  (* Pre: x>0, y>0, LEN(x)>=LEN(y); Post: z=x+y *)
  VAR xt, yt, i, j, len, r, carry: LONGINT; z: Integer;
  BEGIN
    len:=LEN(x)-1; j:=LEN(y)-1; carry:=0;
    FOR i:= len TO 1 BY -1 DO
      xt:=x[i]; 
      IF j<1 THEN yt:=0 ELSE yt:=y[j] END;
      r:=xt+yt+carry;
      IF r>=B THEN x[i]:=SHORT(r-B); carry:=1
      ELSE x[i]:=SHORT(r); carry:=0
      END;
      DEC(j)
    END;
    IF carry=1 THEN NEW(z, len+2);
      FOR i:=1 TO len DO z[i+1]:=x[i] END; z[1]:=1;
      RETURN z
    ELSE RETURN Copy(x, len+1) 
    END
  END Add;    
  
  PROCEDURE UCompare (VAR x, y: ARRAY OF INTEGER): LONGINT;
  (* Post: x>y, RETURN 1; x=y, RETURN 0; x<y RETURN -1 *)
  VAR xl, yl, i: LONGINT;
  BEGIN
    xl:=LEN(x); yl:=LEN(y);
    IF xl>yl THEN RETURN 1      (* x len > y len so x > y *)
    ELSIF xl<yl THEN RETURN -1  (* x len < y len so x < y *)
    ELSE (* number lengths are the same *)
      i:=0;
      LOOP
        INC(i);
        IF i=xl THEN RETURN 0                          (* done so x = y *)
        ELSIF x[i]>y[i] THEN RETURN 1  (* upper x > upper y *)
        ELSIF x[i]<y[i] THEN RETURN -1 (* upper x < upper y *)
        END
      END
    END
  END UCompare;
  
  PROCEDURE MultDigit (VAR w, u : ARRAY OF INTEGER; digit: LONGINT; VAR c: INTEGER);
  VAR i, k, t: LONGINT;
  BEGIN
    i:=LEN(u)-1; k:=c;
    REPEAT                            
      t:=u[i]*digit+k;          (* multiply *)
      w[i]:=SHORT(t MOD B); k:=t DIV B; (* generate result & carry *)
      DEC(i)
    UNTIL i=0;
    c:=SHORT(k)
  END MultDigit;

  PROCEDURE MultAdd (VAR w, u, v : ARRAY OF INTEGER; digit: LONGINT; VAR c: INTEGER);
  VAR i, k, t: LONGINT;
  BEGIN
    i:=LEN(u)-1; k:=c;
    REPEAT                                 
      t:=u[i]*digit+k+v[i]; (* multiply *)
      w[i]:=SHORT(t MOD B); k:=t DIV B;     (* generate result & carry *)
      DEC(i)
    UNTIL i=0;
    c:=SHORT(k)
  END MultAdd;
  
  PROCEDURE DivDigit (VAR w, u: ARRAY OF INTEGER; digit: LONGINT; VAR r: LONGINT);
  VAR j, t, m: LONGINT;
  BEGIN
    j:=1; r:=0; m:=LEN(u)-1;
    REPEAT                            
      t:=r*B+u[j];
      w[j]:=SHORT(t DIV digit); r:=t MOD digit; (* generate result & remainder *)
      INC(j)
    UNTIL j>m
  END DivDigit;
 
  PROCEDURE ModDigit (VAR u: ARRAY OF INTEGER; digit: LONGINT; VAR r: LONGINT);
  VAR j, t, m, rl: LONGINT;
  BEGIN
    j:=1; rl:=0; m:=LEN(u)-1; 
    REPEAT                            
      t:=rl*B+u[j];
      rl:=t MOD digit; (* generate result & remainder *)
      INC(j)
    UNTIL j>m;
    r:=SHORT(rl)
  END ModDigit;
  
  PROCEDURE ToString (x: ARRAY OF INTEGER; VAR s: ARRAY OF CHAR; base: INTEGER);
  VAR i, d, l, xl, c, z: LONGINT; ch: CHAR;
  
    PROCEDURE IsZero () : BOOLEAN;
    VAR c: LONGINT;
    BEGIN
      c:=1; WHILE (c<=xl) & (x[c]=0) DO INC(c) END;
      RETURN c>xl
    END IsZero;
    
  BEGIN
    (* generate the number's sign *)
    IF x[0]=negative THEN s[0]:="-"; c:=1 ELSE c:=0 END;
    x[0]:=positive; l:=LEN(s)-1; xl:=LEN(x)-1; z:=c;
    
    (* perform the conversion *)
    WHILE ~IsZero() & (c<l) DO            (* do while x>0 *)
      DivDigit(x, x, base, d);            (* d=x MOD base; x=x DIV base *)
      IF d<10 THEN s[c]:=CHR(d+ORD("0"))  (* add to string *)
      ELSE s[c]:=CHR(d-10+ORD("A"))
      END;
      INC(c);
    END;
    ASSERT(c<l, 103);          (* string has to be big enough *)
   
    IF z = c THEN 
      (* return something for a zero number *)
      s[0]:='0';
      s[1]:=0X
    ELSE
      (* reverse the string characters *)
      DEC(c);
      FOR i:=z TO z+((c-z) DIV 2) DO
        ch:=s[i]; s[i]:=s[c-i+z]; s[c-i+z]:= ch
      END;
      s[c+1] := 0X;
    END;
  END ToString;
   
  PROCEDURE Mult (VAR w: ARRAY OF INTEGER; u, v: ARRAY OF INTEGER);
  (* Pre: w=0, u>0, v>0; Post: w=u*v *)
  VAR i, j, k, n, t, lw, off, um, vm: LONGINT;
  BEGIN 
    (* least significant blocks *)
    j:=LEN(v)-1; n:=LEN(u)-1; lw:=LEN(w)-1; 
    
    (* clear w *)
    Assign(w, ZERO^);
    
    (* offset is chosen so i+j+off<LEN(w) *)
    off:=lw-j-n;
    
    (* determine max digits in u and v *)
    um:=0; WHILE (um<n) & (u[um+1]=0) DO INC(um) END;
    vm:=0; WHILE (vm<j) & (v[vm+1]=0) DO INC(vm) END;
    
    (* traditional multiplication algorithm radix B *)
    REPEAT
      IF v[j]#0 THEN            (* perform the following if multiplier#0 *)
        i:=n; k:=0;             (* least significant block of multiplicand *)
        REPEAT
          t:=u[i]*v[j]+w[i+j+off]+k; (* multiply *)
          w[i+j+off]:=SHORT(t MOD B); k:=t DIV B;  (* generate result & carry *)
          DEC(i)
        UNTIL i<=um;
        w[um+j+off]:=SHORT(k)
      ELSE w[um+j+off]:=0
      END;
      DEC(j)
    UNTIL j<=vm;
    
    (* generate resultant sign *)
    w[0]:=u[0]*v[0];
  END Mult;
  
  PROCEDURE QR (u, v : ARRAY OF INTEGER; VAR q, r: ARRAY OF INTEGER);
  (* Pre: u>v, u>=0, v>B; Post: q=u DIV v, r=u-q*v *)
  VAR i, k, mn, n, m, d, j, qp, uj, uj1, uj2, t, v1, v2: LONGINT; 
    c: INTEGER;
  BEGIN
    (* want u,v normalized so u[1]>=8000H *)
    mn:=LEN(u)-1; i:=u[mn]; n:=LEN(v)-1; m:=mn-n; 
    d:=B DIV (v[1]+1);
    
    (* scale u, v to be normalized *)
    u[0]:=0; c:=0;            (* clear input carries *)
    MultDigit(u, u, d, u[0]); (* normalize u *)
    MultDigit(v, v, d, c);    (* normalize v *)  
        
    j:=0; 
    REPEAT
      (* determine the value of the q[j] "digit" *)
      uj:=u[j]; uj1:=u[j+1]; uj2:=u[j+2];
      v1:=v[1]; v2:=v[2];
      IF uj=v1 THEN qp:=B-1 ELSE qp:=(uj*B+uj1) DIV v1 END;
      IF (v2*qp-uj2) DIV B > uj*B+uj1-qp*v1 THEN DEC(qp); 
        IF (v2*qp-uj2) DIV B > uj*B+uj1-qp*v1 THEN DEC(qp) END
      END;
      
      (* determine u = u-qp*v *)
      i:=n; k:=0; c:=0; v[0]:=0;                  
      REPEAT
        t:=v[i]*qp+k; k:=t DIV B;      (* multiply & remainder *)
        t:=u[i+j]-(t MOD B)+c;         (* subtraction *)
        IF t<0 THEN c:=-1; u[i+j]:=SHORT(B+t)  (* generate borrow *)
        ELSE c:=0; u[i+j]:=SHORT(t)
        END;
        DEC(i)
      UNTIL i<0;
      
      (* test the remainder and add back -- if necessary *)
      IF c<0 THEN DEC(qp);   (* oops, add one divisor to dividend *)
        k:=0;
        FOR i:=n TO 1 BY -1 DO
          t:=u[i+j]+v[i]+k;
          IF t>=B THEN u[i+j]:=SHORT(t-B); k:=1
          ELSE u[i+j]:=SHORT(t); k:=0
          END
        END;
        u[j] := SHORT(u[j]+k-B)
      END;
      IF LEN(q)>1 THEN q[j]:=SHORT(qp) END;
      INC(j)
    UNTIL j>m;
    
    (* denormalize the quotient *)
    IF (LEN(q)>1) & (LEN(q)-1>=m+1) THEN
      FOR i:=m TO 0 BY -1 DO q[i+1]:=q[i] END
    END;
    
    (* denormalize the remainder -- if needed *)
    IF LEN(r)>1 THEN
      FOR i:=1 TO n DO r[i]:=u[i+m] END;
      DivDigit(r, r, d, i)
    END
  END QR;
  
  PROCEDURE gcd (u: ARRAY OF INTEGER; v: LONGINT) : Integer;
  (* Post: RETURN gcd(u,v) *)
  VAR r, i, ul, m: LONGINT;
  BEGIN
    ul:=LEN(u)-1;
    LOOP
      IF v=0 THEN RETURN Copy(u, 0) END;
      ModDigit(u, v, r); m:=ul-1;
      IF v>B THEN u[ul]:=SHORT(v MOD B);
        u[m]:=SHORT(v DIV B); DEC(m)
      ELSE u[ul]:=SHORT(v)
      END;
      FOR i:=1 TO m DO u[i]:=0 END; 
      v:=r
    END
  END gcd;
  
  PROCEDURE mgcd (u, v, t, w: ARRAY OF INTEGER) : Integer;
  (* Pre: u>=0, v>=0, u>=v, LEN(t)=LEN(u)=LEN(w); Post: gcd(u,v) *)
  VAR uh, vh, A, B, C, D, T, q, vl, ul, c: LONGINT;
    null: ARRAY 1 OF INTEGER;  (* empty variable *)
  BEGIN
    vl:=LEN(v)-1; ul:=LEN(u)-1;    
    LOOP
      (* find next active digit *)    
      c:=1; WHILE (c<=vl) & (v[c]=0) DO INC(c) END;
      
      (* terminate if one digit is left *)
      IF c=vl THEN RETURN gcd(u, v[c]) END;
      
      (* reduce the large number *)
      vh:=v[c];
      c:=1; WHILE (c<=ul) & (u[c]=0) DO INC(c) END;
      uh:=u[c]; 
      A:=1; B:=0; C:=0; D:=1;
      LOOP
        (* test the quotient *)
        IF (vh+C=0) OR (vh+D=0) THEN EXIT END; 
        q:=(uh+A) DIV (vh+C);
        IF q#(uh+B) DIV (vh+D) THEN EXIT END;
        
        (* Euclid emulation *)
        T:=A-q*C; A:=C; C:=T; T:=B-q*D;
        B:=D; D:=T; T:=uh-q*vh; uh:=vh; vh:=T
      END;
      
      (* multi-precision operations *)
      IF B=0 THEN
        QR(u, v, null, t);                  (* t := u MOD v *)
        Assign(u, v);                       (* u := v *)
        Assign(v, t)                        (* v := t *)        
      ELSE
        t[0]:=0; MultDigit(t, u, A, t[0]);  (* t := A*u *)
        w[0]:=0; MultDigit(w, u, C, w[0]);  (* w := C*u *)
        t[0]:=0; MultAdd(t, v, t, B, t[0]); (* t := t+B*v *)
        w[0]:=0; MultAdd(w, v, w, D, w[0]); (* w := w+D*v *)
        Assign(u, t); Assign(v, w);         (* u := t; v := w *)
      END
    END
  END mgcd;
  
  PROCEDURE IntPower (VAR y: ARRAY OF INTEGER; x: ARRAY OF INTEGER; exp: LONGINT);
  (* Pre: exp>=0; Post: y=x**exp *)
  BEGIN
    Assign(y, ONE^); (* y = 1 *)
    LOOP
      IF ODD(exp) THEN Mult(y, y, x) END;
      exp:=exp DIV 2;  (* simulate DIV 2 *)
      IF exp=0 THEN EXIT END;
      Mult(x, x, x)
    END  
  END IntPower;
  
  PROCEDURE ExtractDigit (x: ARRAY OF INTEGER; d: LONGINT) : LONGINT;
  VAR b: LONGINT;
  BEGIN
    (* move the digit into the least significant position *)
    WHILE d>0 DO DivDigit(x, x, 10, b); DEC(d) END;
    
    (* extract the digit *)
    ModDigit(x, 10, b);
    RETURN b
  END ExtractDigit;
  
  PROCEDURE Times10 (VAR r: ARRAY OF INTEGER; b: INTEGER);
  BEGIN
    MultDigit(r, r, 10, b); ASSERT(b=0, 101)
  END Times10;

  (* Removed on Michael van Acken's order
  PROCEDURE ShiftRight (x: ARRAY OF INTEGER; digits, bits: LONGINT) : Integer;
  (* Pre: digits>=0, bits>=0; Post: RETURN x DIV (digits*B+bits) *)
  VAR i, bpower: LONGINT;
  BEGIN
    (* shift whole digits *)
    FOR i:=LEN(x)-1-digits TO 1 BY -1 DO x[i+digits]:=x[i] END;
    FOR i:=1 TO digits DO x[i]:=0 END;
    
    (* shift by bits *)
    bpower:=1; WHILE bits>0 DO bpower:=bpower*2; DEC(bits) END; (* 2^bits *)
    DivDigit(x, x, bpower, i);
    RETURN Copy(x, 0) (* truncate leading zeros *)
  END ShiftRight;
  
  PROCEDURE ShiftLeft (VAR x: ARRAY OF INTEGER; digits, bits: LONGINT) : Integer;
  (* Pre: digits>=0, bits>=0; Post: RETURN x * (digits*B+bits) *)
  VAR i, bpower, lx: LONGINT; r: Integer; c: INTEGER;
  BEGIN
    (* allocate room for shifted result *)
    lx:=LEN(x)+digits; IF bits>0 THEN INC(lx) END; 
    r:=New(lx); Assign(r^, x);    
    
    (* shift whole digits *)
    FOR i:=1 TO lx-1-digits DO r[i]:=r[i+digits] END;
    FOR i:=lx-digits TO lx-1 DO r[i]:=0 END;
    
    (* shift by bits *)
    bpower:=1; WHILE bits>0 DO bpower:=bpower*2; DEC(bits) END; (* 2^bits *)
    c:=0; MultDigit(r^, r^, bpower, c);
    IF r[1]=0 THEN RETURN Copy(r^, 0) ELSE RETURN r END
  END ShiftLeft;
  *)
  
  
  (* removed to adhere to Oberon-F interface
  (***********************************************************)
  (* INTERNAL operations to type-cast Integers to/from Sets  *)
  (* DO NOT USE.  Please use the ToSet & ToInteger routines  *)
  (* from the Sets module instead.                           *)

  PROCEDURE ConvertToInteger * (x: ARRAY OF SET) : Integer;
  CONST S=MAX(SET)+1;
  VAR r: Integer; l, bit: LONGINT; c: INTEGER;
  BEGIN
    l:=S*LEN(x);
    IF l MOD Log2B > 0 THEN r:=New(l DIV Log2B + 2) ELSE r:=New(l DIV Log2B + 1) END; 
    FOR bit:=LEN(x)*S-1 TO 0 BY -1 DO
      IF (bit MOD S) IN x[bit DIV S] THEN c:=1 ELSE c:=0 END;
      MultDigit(r^, r^, 2, c)
    END;
    IF r[1]#0 THEN RETURN r ELSE RETURN Copy(r^, 0) END
  END ConvertToInteger;
  
  PROCEDURE ConvertToSet * (x : ARRAY OF INTEGER; VAR s: ARRAY OF SET);
  VAR l, bit, d: LONGINT;
  
    PROCEDURE IsZero () : BOOLEAN;
    VAR c: LONGINT;
    BEGIN
      c:=1; WHILE (c<=l) & (x[c]=0) DO INC(c) END;
      RETURN c>l
    END IsZero;

  BEGIN
    l:=LEN(x)-1; bit:=0;
    WHILE ~IsZero() DO (* lowest bit to highest *)
      IF ODD(x[l]) THEN INCL(s[bit DIV 32], bit MOD 32) END; 
      DivDigit(x, x, 2, d); INC(bit)
    END
  END ConvertToSet;
  *)
  

  (***********************************************************)
  (* Operations to convert standard numbers to/from Integers *)

  PROCEDURE Entier* (x: LONGREAL) : Integer;
  (* Returns the largest integer not greater than `x' *)
  CONST SCALE=1.0/B;
  VAR ix: ARRAY 65 OF INTEGER; i, exp: LONGINT;
  BEGIN
    IF x<0 THEN ix[0]:=negative; x:=-x        (* adjust for negatives *)
    ELSE ix[0]:=positive 
    END;
    exp:=0;
    WHILE x>B DO x:=x*SCALE; INC(exp) END;    (* scale down the number *)
    FOR i:=1 TO exp+1 DO 
      ix[i]:=SHORT(ENTIER(x)); x:=(x-ix[i])*B (* convert/store the number *)
    END;
    RETURN Copy(ix, exp+2)
  END Entier;
  
  PROCEDURE Float* (x: Integer) : LONGREAL;
  VAR cnt, len: LONGINT; r: LONGREAL;
  BEGIN
    len:=LEN(x^)-1; r:=x[1];
    FOR cnt:=2 TO len DO 
      IF r<MAX(LONGREAL)/B THEN r:=r*BR+x[cnt]
      ELSIF x[0]=negative THEN RETURN MIN(LONGREAL)
      ELSE RETURN MAX(LONGREAL)
      END
    END;
    IF x[0]=negative THEN RETURN -r ELSE RETURN r END
  END Float;
  
  PROCEDURE Long* (x: LONGINT) : Integer;
  VAR si: ARRAY 4 OF INTEGER;
  BEGIN
    IF x=MIN(LONGINT) THEN 
      si[0]:=negative; si[1]:=2; si[2]:=0; si[3]:=0
    ELSE
      IF x<0 THEN x:=-x; si[0]:=negative ELSE si[0]:=positive END;
      si[1]:=SHORT(x DIV (B*B)); 
      si[2]:=SHORT((x DIV B) MOD B);
      si[3]:=SHORT(x MOD B)
    END;
    RETURN Copy(si, 4)
  END Long;
  
  PROCEDURE Short* (x: Integer) : LONGINT;
  VAR r, l, m: LONGINT;
  BEGIN
    m:=LEN(x^)-1; r:=x[1]; l:=2;
    WHILE l<=m DO
      IF r>(MAX(LONGINT)-x[l]) DIV B THEN (* saturate number *)
        IF x[0]=negative THEN RETURN MIN(LONGINT)
        ELSE RETURN MAX(LONGINT)
        END
      ELSE r:=r*B+x[l]
      END;
      INC(l)
    END;
    
    (* adjust for negative sign *)
    IF x[0]=negative THEN RETURN -r ELSE RETURN r END
  END Short;
    
  (***********************************************************)
  (* Operations to internalize/externalize Integers          *)

  PROCEDURE Externalize* (VAR w: BinaryRider.Writer; x: Integer);
  VAR i: LONGINT;
  BEGIN
    w.WriteNum(LEN(x^));
    FOR i:=0 TO LEN(x^)-1 DO w.WriteInt(x[i]) END
  END Externalize;
  
  PROCEDURE Internalize* (VAR r: BinaryRider.Reader; VAR x: Integer);
  VAR i, s: LONGINT;
  BEGIN
    r.ReadNum(s); NEW(x, s);
    FOR i:=0 TO s-1 DO r.ReadInt(x[i]) END  
  END Internalize;
  
  (***********************************************************)
  (* Mathematical operations on Integers                     *)
  
  PROCEDURE Abs* (x: Integer) : Integer;
  VAR r: Integer;
  BEGIN
    IF x[0]=negative THEN r:=Copy(x^, 0); r[0]:=positive; RETURN r
    ELSE RETURN x
    END
  END Abs;
  
  PROCEDURE Odd* (x: Integer) : BOOLEAN;
  BEGIN
    RETURN ODD(x[LEN(x^)-1])
  END Odd;

  PROCEDURE Compare* (x, y: Integer): LONGINT;
  (* Post: x>y, RETURN 1; x=y, RETURN 0; x<y RETURN -1 *)
  BEGIN
    IF x[0]#y[0] THEN RETURN x[0] (* if x<0 and y>0 then x<y and vice versa *)
    ELSE RETURN UCompare(x^, y^)  (* signs are the same *)
    END
  END Compare;
  
  PROCEDURE Difference* (x, y: Integer) : Integer;
  (* Post: RETURN x-y *)
  VAR d: Integer;
  BEGIN
    (* ensure that ABS(x)>ABS(y) *)
    IF UCompare(x^, y^)<0 THEN d:=y; y:=x; x:=d END; (* swap x and y *)

    (* determine how to subtract the numbers *)
    IF x[0]=y[0] THEN d:=Sub(x^, y^) (* x+,y+, so z=x-y or x-,y-, so z=-x-(-y)=-(x-y) *)           
    ELSE d:=Add(x^, y^)              (* x-,y+, so z=-x-y=-(x+y) or x+,y-, so z=x-(-y)=x+y *)                           
    END;
    
    d[0]:=x[0]; (* sign of x always gives the right result *)
    RETURN d
  END Difference;

  PROCEDURE Sum* (x, y: Integer) : Integer;
  (* Post: RETURN x+y *)
  VAR d: Integer;
  BEGIN
    (* ensure that ABS(x)>ABS(y) *)
    IF UCompare(x^, y^)<0 THEN d:=y; y:=x; x:=d END; (* swap x and y *)

    (* determine how to subtract the numbers *)
    IF x[0]#y[0] THEN d:=Sub(x^, y^) (* x-,y+, so z=-x+y=-(x-y) or x+,y-, so z=x-y *)           
    ELSE d:=Add(x^, y^)              (* x+,y+, so z=x-y or x-,y-, so z=-x-(-y)=-(x-y) *)                           
    END;
    
    d[0]:=x[0]; (* sign of x always gives the right result *)
    RETURN d  
  END Sum; 
  
  PROCEDURE Product* (x, y: Integer) : Integer;
  (* Post: RETURN x*y *)
  VAR w: Integer;
  BEGIN    
    (* allocate space for result and clear it *)
    w:=New(LEN(y^)+LEN(x^)-1);              
    
    (* perform the multiplication *)
    Mult(w^, x^, y^);
    IF w[1]=0 THEN RETURN Copy(w^, 0)   (* truncate leading zero *)
    ELSE RETURN w
    END
  END Product;
    
  PROCEDURE QuoRem* (x, y: Integer; VAR quo, rem: Integer);
  (* Pre: y#0; Post: quo=x DIV y, rem= x MOD y *)
  VAR cmp: LONGINT; one: ARRAY 2 OF INTEGER;
  
    PROCEDURE FixUp ();
    BEGIN    
      (* fix up remainder/quotient *)
      IF (rem[1]#0) & (x[0]#y[0]) THEN 
        rem:=Sub(y^, rem^); quo:=Add(quo^, ONE^) 
      END;
      
      (* fix up the signs *)
      rem[0]:=y[0]; 
      quo[0]:=x[0]*y[0]
    END FixUp;
    
  BEGIN
    (* division by zero? *)
    ASSERT(y[1]#0, 103);             (* ensure y#0 *)
    
    (* return trivial results *)
    cmp:=UCompare(x^, y^);
    IF cmp<0 THEN                    (* x<y *)
      quo:=New(2); rem:=Copy(x^, 0); (* x DIV y=0, x MOD y=x *)
      FixUp; RETURN
    ELSIF cmp=0 THEN                 (* x=y *)
      one[0]:=x[0]*y[0]; one[1]:=1;  (* x DIV y = 1 *)
      quo:=Copy(one, 0);
      rem:=ZERO;                     (* x MOD y = 0 *)
      RETURN
    END;
    
    (* perform the division *)
    IF LEN(y^)=2 THEN (* single-digit divide *)
      quo:=New(LEN(x^)); 
      DivDigit(quo^, x^, y[1], cmp);
      one[1]:=SHORT(cmp); rem:=Copy(one, 2)
    ELSE (* full divide *)
      cmp:=LEN(x^)-LEN(y^)+1;
      IF cmp=1 THEN cmp:=2 END;
      quo:=New(cmp); rem:=New(LEN(y^)); 
      QR(x^, y^, quo^, rem^)
    END;
    
    (* adjust for negative numbers *)
    FixUp 
  END QuoRem;
  
  PROCEDURE Quotient* (x, y: Integer) : Integer;
  (* Pre: y#0; Post: RETURN x DIV y *)
  VAR q, r: Integer;
  BEGIN
    QuoRem(x, y, q, r); RETURN q
  END Quotient;  
  
  PROCEDURE Remainder* (x, y: Integer) : Integer;
  (* Pre: y#0; Post: RETURN x MOD y *)
  VAR
    q, r: Integer;
  BEGIN
    QuoRem(x, y, q, r); RETURN r
  END Remainder;

  PROCEDURE GCD* (x, y: Integer) : Integer;
  (* Pre: x,y >= 0; Post: RETURN gcd(x,y) *)
  BEGIN
    IF UCompare(x^, y^)>=0 THEN RETURN mgcd(x^, y^, x^, x^)
    ELSE RETURN mgcd(y^, x^, y^, y^)
    END
  END GCD;
    
  PROCEDURE Power* (x: Integer; exp: LONGINT) : Integer;
  (* Pre: exp>=0; Post: RETURN x**exp *)
  VAR y: Integer;
  BEGIN 
    IF exp<0 THEN RETURN New(2) END;           (* x**-exp = 0 *)
    y:=New((LEN(x^)-1)*exp+1); Assign(y^, x^); (* y = x *)
    IntPower(y^, y^, exp);
    IF y[1]=0 THEN RETURN Copy(y^, 0) ELSE RETURN y END
  END Power;
  
  PROCEDURE Sign* (x: Integer) : SHORTINT;
  (* Post: x>0, RETURN 1; x=0, RETURN 0; x<0, RETURN -1 *)
  BEGIN
    IF x[1]=0 THEN RETURN 0
    ELSE RETURN SHORT(x[0])
    END
  END Sign;
  
  PROCEDURE Factorial* (x: LONGINT) : Integer;
  (* Pre: x>=0; Post: RETURN x!=x(x-1)(x-2)...(2)(1) *)
  VAR f: Integer; t, bits: LONGINT; c: INTEGER;
  BEGIN
    ASSERT(x>=0, 108); t:=x; bits:=0;
    IF x<2 THEN RETURN ONE END;              (* 0! & 1! *)
    WHILE t>0 DO t:=t DIV B; INC(bits) END;  (* log32768(x) *)
    f:=New(4*x*bits DIV 5 + 1);              (* #digits=4*x*log32768(x)/5 *)
    Assign(f^, ONE^);                        (* f=1 *)
    WHILE x>1 DO
      c:=0; MultDigit(f^, f^, x, c); DEC(x)  (* f=f*x *)
    END;
    RETURN Copy(f^, 0)
  END Factorial;

  (*  Michael van Acken doesn't like these routines
      being in here.
  PROCEDURE Random* (digits: LONGINT) : Integer;
  (* Pre: x>0; Post: RETURN digits-length random number *)
  CONST a=16385; c=1;
  VAR n: Integer; i: LONGINT; s: Time.TimeStamp; cs: Cal.Calendar;
  BEGIN
    ASSERT(digits>0, 109); SysClock.GetClock(cs); cs.ToTimeStamp(s);
    n:=New(2215*digits DIV 10000+1);     (* n=digits*log32768(10) *)
    n[1]:=SHORT((a*SHORT(s.msecs MOD B)+c) MOD B);
    FOR i:=2 TO LEN(n^)-1 DO n[i]:=SHORT((a*n[i-1]+c) MOD B) END;
    RETURN n
  END Random;
  
  PROCEDURE Shift* (x: Integer; exp: LONGINT) : Integer;
  (* Post: RETURN Floor(x*2^exp) *)
  VAR sh: LONGINT;
  BEGIN
    (* eliminate out of bound and trivial shifts *)
    IF exp=0 THEN RETURN x
    ELSIF exp<(1-LEN(x^))*Log2B THEN RETURN ZERO
    END;
    
    (* break down the shift into bit shifts and digit shifts *)
    sh:=ABS(exp) DIV Log2B;   (* number of whole digits *)
    IF exp<0 THEN
      RETURN ShiftRight(x^, sh, -(exp+Log2B*sh))      
    ELSE          
      RETURN ShiftLeft(x^, sh, exp-Log2B*sh)
    END
  END Shift;
  *)
  
  
  (***********************************************************)
  (* Operations to extract pieces of Integers                *)
  
  PROCEDURE ThisDigit10* (x: Integer; exp10: LONGINT) : CHAR;
  (* Pre: exp10>=0; Post: RETURN (x DIV 10^exp10) MOD 10 *)
  BEGIN
    ASSERT(exp10>=0, 106);  (* error indication *)
    RETURN CHR(ExtractDigit(x^, exp10)+ORD("0"))
  END ThisDigit10;
      
  PROCEDURE Digits10Of* (x: Integer) : LONGINT;
  (* Post: RETURN x MOD 1000000000 *)
  VAR d: ARRAY 3 OF INTEGER; dummy: ARRAY 1 OF INTEGER;
  BEGIN
    d[0]:=positive; d[1]:=7735H; d[2]:=4A00H;  (* 1000000000 *)
    QR(x^, d, dummy, d);                       (* x MOD 1000000000 *)
    RETURN d[1]*B+d[2]
  END Digits10Of;
    
  (***********************************************************)
  (* Operations to convert strings to/from Integers          *)
      
  PROCEDURE ConvertFromString* (s: ARRAY OF CHAR; VAR x: Integer);
  (* Pre: [+|-]d{d} where d=["0".."9"]; Post: `x' contains integer *)
  CONST Tab = 9X; Space = " "; base=10;  (* could be made an argument *)
  VAR i, c, e: LONGINT; neg: BOOLEAN; maxChar1, maxChar2: CHAR;
  BEGIN
    (* skip whitespace *)
    ASSERT((base>=2) & (base<=36), 110);    
    IF base>10 THEN maxChar1:="9"; maxChar2:=CHR(base-11+ORD("A")) 
    ELSE maxChar1:=CHR(base-1+ORD("0")); maxChar2:=0X 
    END;
    c:=0; WHILE (s[c]=Space) OR (s[c]=Tab) DO INC(c) END;
    
    (* check for a sign *)
    IF s[c]="-" THEN neg:=TRUE; INC(c)
    ELSIF s[c]="+" THEN neg:=FALSE; INC(c)
    ELSE neg:=FALSE
    END;
    
    (* find end of number *)
    e:=c; WHILE ((s[e]>="0")&(s[e]<=maxChar1)) OR ((s[e]>="A")&(s[e]<=maxChar2)) DO INC(e) END;
      
    (* determine resultant size and allocate number *)
    i:=69*(e-c) DIV 320 + 2;
    
    (* convert to binary *)
    x:=New(i);   (* x = 0 *)
    WHILE c<e DO
      IF s[c]<="9" THEN Times10(x^, ORD(s[c])-ORD("0"))
      ELSE Times10(x^, ORD(s[c])-ORD("A"))
      END;
      INC(c)
    END;
    IF neg THEN x[0]:=negative END; (* adjust the sign *)
    IF x[1]=0 THEN x:=Copy(x^, 0) END (* truncate leading zero *)
  END ConvertFromString;
     
  PROCEDURE ConvertToString* (x: Integer; VAR s: ARRAY OF CHAR);
  (* Post: s holds a string representation of `x' *)
  BEGIN    
    (* convert the number in ToString so a stack copy of x is used *)
    ToString(x^, s, 10)
  END ConvertToString;
  
BEGIN 
  ZERO:=New(2); ONE:=New(2); ONE[1]:=1;
END Integers.




