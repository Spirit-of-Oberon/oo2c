MODULE FFT;

<* IndexCheck := FALSE *> 
<* DerefCheck := FALSE *> 

IMPORT 
  Type,
  R := RealMath, 
  Out;

TYPE
  Complex = Type.Complex;

VAR
  sineTable : POINTER TO ARRAY OF REAL;
  cosInc : LONGINT;
  order : LONGINT;

PROCEDURE BitRev(VAR a : ARRAY OF Complex);
VAR
  i, irev, carry, size, s2 : LONGINT;
  temp : Complex;
BEGIN
  irev := 0;
  size := LEN(a); s2 := size DIV 2;
  FOR i := 0 TO size-1 DO
    IF i < irev THEN
      temp := a[i]; a[i] := a[irev]; a[irev] := temp;
    END;
    carry := s2;
    WHILE (carry # 0) & (carry <= irev) DO
      DEC(irev, carry);
      carry := carry DIV 2;
    END;
    INC(irev, carry);
  END;
END BitRev;

PROCEDURE GenTable(n : LONGINT);
(* Generate 3/4 cycle sine table for sin/cos lookup *)
VAR
  mult : REAL;
  i : LONGINT;
  size : LONGINT;
BEGIN
  cosInc := n DIV 4;
  size := cosInc * 3 + 1;
  NEW(sineTable, size);
  mult := 2 * R.pi / n;
  FOR i := 0 TO size - 1 DO
    sineTable[i] := R.sin(mult * i);
  END;
  cosInc := n DIV 4;
  order := n;
END GenTable;

PROCEDURE FFT* (VAR a : ARRAY OF Complex; fwd : BOOLEAN);
(* Radix-2 Fast Fourier Transform *)
VAR
  idx, idxStep, i, i2, j, k, m, n : LONGINT;
  b, w, ai, ai2 : Complex;
BEGIN
  n := LEN(a);
  IF (order # 2 * n) THEN GenTable(2 * n); END;

  BitRev(a);

  k := 1; idxStep := 2 * n;
  WHILE k < n DO
    m := k;
    k := k * 2; idxStep := idxStep DIV 2;
    j := 0; idx := 0;
    WHILE j < m DO
      w.r := sineTable[idx + cosInc];
      w.i := -sineTable[idx];
      IF ~fwd THEN w.i := -w.i END;
      i := j;
      WHILE i < n DO
        i2 := i + m;
        ai2 := a[i2]; ai := a[i];
        b.r := w.r * ai2.r - w.i * ai2.i;
        b.i := w.r * ai2.i + w.i * ai2.r;
        a[i2].r := ai.r - b.r; a[i2].i := ai.i - b.i;
        a[i].r  := ai.r + b.r;  a[i].i := ai.i + b.i;
        INC(i, k);
      END; (* FOR i *)
      INC(j, 1); INC(idx, idxStep);
    END; (* FOR j *)
  END; (* FOR k *)
  IF ~fwd THEN
    FOR i := 0 TO n-1 DO
      a[i].r := a[i].r / n; a[i].i := a[i].i / n;
    END;
  END;
END FFT;


PROCEDURE FFT2* (VAR a : ARRAY OF Complex; fwd : BOOLEAN);
(* Radix-2 Fast Fourier Transform. Inner butterfly calculation is factored
 * into a separate procedure. 
 *
 * Without an optimiser, this version can be expected to perform significantly
 * better since the array address calculations are performed only once in the
 * call to Butterfly. 
 *
 * With an optimiser, the procedure call overheads will probably make this
 * version slightly slower. *)
VAR
  idx, idxStep, i, i2, j, k, m, n : LONGINT;
  b, w : Complex;

  PROCEDURE Butterfly(VAR ai, ai2 : Complex);
  BEGIN
      b.r := w.r * ai2.r - w.i * ai2.i;
      b.i := w.r * ai2.i + w.i * ai2.r;
      ai2.r := ai.r - b.r; ai2.i := ai.i - b.i;
      ai.r  := ai.r + b.r;  ai.i := ai.i + b.i;
  END Butterfly;

BEGIN
  n := LEN(a);
  IF (order # 2 * n) THEN GenTable(2 * n); END;

  BitRev(a);

  k := 1; idxStep := 2 * n;
  WHILE k < n DO
    m := k;
    k := k * 2; idxStep := idxStep DIV 2;
    j := 0; idx := 0;
    WHILE j < m DO
      w.r := sineTable[idx + cosInc];
      w.i := -sineTable[idx];
      IF ~fwd THEN w.i := -w.i END;
      i := j;
      WHILE i < n DO
        i2 := i + m;
        Butterfly(a[i], a[i2]);
        INC(i, k);
      END; (* FOR i *)
      INC(j, 1); INC(idx, idxStep);
    END; (* FOR j *)
  END; (* FOR k *)
  IF ~fwd THEN
    FOR i := 0 TO n-1 DO
      a[i].r := a[i].r / n; a[i].i := a[i].i / n;
    END;
  END;
END FFT2;

BEGIN
  order := 0;
  sineTable := NIL;
END FFT.
