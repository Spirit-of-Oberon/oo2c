MODULE Language:Integer;

IMPORT
  Language, Language:Numeric;


TYPE
  MAXINT* = <*IF TARGET_INTEGER = 64 THEN*>HUGEINT<*ELSE*>LONGINT<*END*>;
  (**This type refers to the largest primitive integer type supported on this
     system.  *)
  
TYPE
  Type* = POINTER TO TypeDesc;
  TypeDesc = RECORD
    (Language.TypeDesc)
    sizeInWords-: INTEGER;
    sizeInBits-: INTEGER;
    min-, max-: MAXINT;                  (* min = -max-1 *)
  END;

TYPE
  Value* = POINTER TO ValueDesc;
  ValueDesc = RECORD
    (Numeric.ValueDesc)
    int-: MAXINT;
  END;


PROCEDURE InitValue* (v: Value; t: Type; status: Language.ValueStatus;
                      int: MAXINT);
  BEGIN
    Language.InitValue (v, t, status);
    v. int := int;
  END InitValue;

PROCEDURE NewValue* (t: Type; status: Language.ValueStatus; int: MAXINT): Value;
  VAR
    v: Value;
  BEGIN
    NEW (v);
    InitValue (v, t, status, int);
    RETURN v
  END NewValue;

PROCEDURE StrToInt* (str: ARRAY OF CHAR; VAR int: MAXINT;
                     VAR status: Language.ValueStatus);
  VAR
    i, digit: LONGINT;
    limit: MAXINT;
    neg: BOOLEAN;
  BEGIN
    status := Language.statusOk;
    CASE str[0] OF
    | "-": neg := TRUE; i := 1
    | "+": neg := FALSE; i := 1
    ELSE
      neg := FALSE; i := 0
    END;
    IF (str[i] = 0X) THEN                (* check for empty string *)
      status := Language.statusFormatError
    END;
    
    (* `limit' is choosen in such a way, that for any `int' with
       `int >= limit' the relation `int*10 >= MIN(MAXINT)' holds *)
    limit := MIN (MAXINT) DIV 10;
    IF (limit MOD 10 # 0) THEN
      INC (limit)
    END;
    
    (* decode digits, but take care that no overflow occurs *)
    int := 0;
    WHILE ("0" <= str[i]) & (str[i] <= "9") DO
      IF (int < limit) THEN
        status := Language.statusOverflow
      ELSE
        int := int*10;
        digit := ORD (str[i])-ORD ("0");
        IF (digit > int-MIN (MAXINT)) THEN
          status := Language.statusOverflow
        ELSE  (* int-digit >= MIN (MAXINT) *)
          DEC (int, digit)
        END
      END;
      INC (i)
    END;
    
    IF (str[i] # 0X) THEN
      status := Language.statusFormatError
    ELSIF ~neg & (int = MIN (MAXINT)) THEN
      status := Language.statusOverflow
    END;
    
    IF (status = Language.statusOk) THEN
      IF ~neg THEN int := -int END
    ELSIF neg THEN
      int := MIN (MAXINT)
    ELSE
      int := MAX (MAXINT)
    END
  END StrToInt;

PROCEDURE IntToStr* (int: MAXINT; VAR str: ARRAY OF CHAR);
  CONST
    maxLength = (SIZE (MAXINT)*Language.bitsPerWord) DIV 3+1;
  VAR
    b : ARRAY maxLength+1 OF CHAR;
    digit: MAXINT;
    s, e: INTEGER;

  PROCEDURE Reverse (VAR str : ARRAY OF CHAR; start, end : INTEGER);
  (* Reverses order of characters in the interval [start..end]. *)
    VAR
      h : CHAR;
    BEGIN
      WHILE start < end DO
        h := str[start]; str[start] := str[end]; str[end] := h;
        INC(start); DEC(end)
      END
    END Reverse;

  BEGIN
    IF (int < 0) THEN
      b[0] := "-"; e := 1
    ELSE
      int := -int; e := 0
    END;
    s := e;
    
    REPEAT
      digit := 10-int MOD 10;
      IF (digit = 10) THEN digit := 0 END;
      b[e] := CHR (ORD ("0") + digit);
      int := int DIV 10;
      INC (e)
    UNTIL (int = 0);
    b[e] := 0X;
    Reverse (b, s, e-1);
    
    COPY (b, str)                        (* truncate if necessary *)
  END IntToStr;
  
PROCEDURE Sgn (v: Value): SHORTINT;
  BEGIN
    IF (v. int < 0) THEN
      RETURN -1
    ELSIF (v. int > 0) THEN
      RETURN 1
    ELSE
      RETURN 0
    END
  END Sgn;

PROCEDURE MaxStatus (a, b: Language.ValueStatus): Language.ValueStatus;
  BEGIN
    IF (a > b) THEN
      RETURN a
    ELSE
      RETURN b
    END
  END MaxStatus;


PROCEDURE InitType* (t: Type; sizeInWords: INTEGER; sizeInBits: INTEGER;
                     min, max: MAXINT);
  BEGIN
    t. sizeInWords := sizeInWords;
    t. sizeInBits := sizeInBits;
    t. min := min;
    t. max := max;
  END InitType;

PROCEDURE (t: Type) ValueOf* (str: ARRAY OF CHAR): Value;
  VAR
    int: MAXINT;
    status: Language.ValueStatus;
  BEGIN
    StrToInt (str, int, status);
    IF (status = Language.statusOk) &
       ((int < t. min) OR (int > t. max)) THEN
      status := Language.statusOverflow
    END;
    RETURN NewValue (t, status, int)
  END ValueOf;

PROCEDURE (t: Type) Min* (): Value;
  BEGIN
    RETURN NewValue (t, Language.statusOk, t. min)
  END Min;

PROCEDURE (t: Type) Max* (): Value;
  BEGIN
    RETURN NewValue (t, Language.statusOk, t. max)
  END Max;


PROCEDURE NewType* (sizeInWords: INTEGER;
                    sizeInBits: INTEGER;
                    min, max: MAXINT): Type;
  VAR
    t: Type;
  BEGIN
    NEW (t);
    InitType (t, sizeInWords, sizeInBits, min, max);
    RETURN t
  END NewType;


PROCEDURE (v: Value) ToString* (VAR str: ARRAY OF CHAR);
  BEGIN
    CASE v. status OF
    | Language.statusOk:
      IntToStr (v. int, str)
    | Language.statusUnderflow:
      COPY ("#underflow#", str)
    | Language.statusOverflow:
      COPY ("#overflow#", str)
    | Language.statusDivByZero:
      COPY ("#div_by_zero#", str)
    | Language.statusFormatError:
      COPY ("#format_error#", str)
    | Language.statusTypeError:
      COPY ("#type_error#", str)
    END
  END ToString;

PROCEDURE (v: Value) Copy*(): Value;
  BEGIN
    RETURN NewValue (v. type(Type), v. status, v. int)
  END Copy;

PROCEDURE (v: Value) Neg* (): Value;
  BEGIN
    IF (v. int <= v. type(Type). min) THEN
      RETURN NewValue (v. type(Type),
                       MaxStatus (v. status, Language.statusOverflow),
                       v. type(Type). max)
    ELSE
      RETURN NewValue (v. type(Type), v. status, -v. int)
    END
  END Neg;

PROCEDURE (v: Value) Abs* (): Value;
  BEGIN
    IF (v. int < 0) THEN
      RETURN v. Neg()
    ELSE
      RETURN v. Copy()
    END
  END Abs;

PROCEDURE (v: Value) Add* (w: Numeric.Value): Value;
  VAR
    w0: Value;
    overflow: BOOLEAN;
    t: Type;
  BEGIN
    w0 := w(Value);
    IF (w. status > v. status) THEN
      RETURN w0
    ELSIF (v. status # Language.statusOk) THEN
      RETURN v
    ELSE
      t := v. type(Type);
      overflow := FALSE;
      IF (Sgn (v) = Sgn (w0)) & (v. int # 0) THEN  
        (* both v and w are either negative or positive *)
        IF (v. int > 0) THEN  (* v and w are positive *)
          overflow := (v. int > t. max-w0. int)
        ELSE  (* v and w are negative *)
          overflow := (v. int < t. min-w0. int)
        END
      END;
      IF overflow OR 
         (v. int+w0. int < t. min) OR
         (v. int+w0. int > t. max) THEN
        RETURN NewValue (t, Language.statusOverflow, 1)
      ELSE
        RETURN NewValue (t, Language.statusOk, v. int+w0. int)
      END
    END
  END Add;

PROCEDURE (v: Value) Sub* (w: Numeric.Value): Value;
  VAR
    w0, x: Value;
    t: Type;
    max: Language.Value;
  BEGIN
    w0 := w(Value);
    IF (w. status > v. status) THEN
      RETURN w0
    ELSIF (v. status # Language.statusOk) THEN
      RETURN v
    ELSE
      t := v. type(Type);
      IF (w0. int = t. min) THEN
        IF (v. int = t. max) THEN
          RETURN NewValue (t, Language.statusOverflow, 1)
        ELSE
          INC (v. int);
          max := t. Max();
          x := v. Add (max(Value));
          DEC (v. int);
          RETURN x
        END
      ELSE
        RETURN v. Add (w. Neg())
      END
    END
  END Sub;

PROCEDURE (v: Value) Mult* (w: Numeric.Value): Value;
  VAR
    w0: Value;
    t: Type;
    int, div: MAXINT;
    min: Value;
  BEGIN
    w0 := w(Value);
    IF (w. status > v. status) THEN
      RETURN w0
    ELSIF (v. status # Language.statusOk) THEN
      RETURN v
    ELSE
      t := v. type(Type);
      min := t. Min();
      IF (v. int # 0) & (w0.int # 0) & (v. int # 1) & (w0. int # 1) THEN
        (* here holds: (v <= -1) OR (v >= 2), (w0 <= -1) OR (w0 >= 2) *)
        IF (v. int = t. min) OR (w0. int = t. min) OR
           (Sgn (v) = Sgn (w0)) & (min. Cmp (w0. Mult (v. Neg())) <= 0) THEN
          (* abort if `-v' and `-w0' would cause an overflow, or if `v*w0>0',
             but `-(v*w0)<=t. min' *)
          RETURN NewValue (t, Language.statusOverflow, 1)
        ELSE  (* here holds: `-v', `-w0' are valid, `v*w0<0' *)
          IF (w0. int < 0) THEN  (* make `w0' positive, `v' negative *)
            w0 := w0. Neg(); v := v. Neg()
          END;
          (* test `v*w0 < t. min' *)
          div := t. min DIV w0. int;
          IF (v. int < div) OR (v. int = div) & (t. min MOD w0. int > 0) THEN
            RETURN NewValue (t, Language.statusOverflow, 1)
          END
        END
      END;
      int := v. int*w0. int;
      IF (int < t. min) OR (int > t. max) THEN
        RETURN NewValue (t, Language.statusOverflow, 1)
      ELSE
        RETURN NewValue (t, Language.statusOk, int)
      END
    END
  END Mult;

PROCEDURE (v: Value) Div* (w: Numeric.Value): Value;
  VAR
    w0: Value;
    t: Type;
  BEGIN
    w0 := w(Value);
    t := v. type(Type);
    IF (w. status > v. status) THEN
      RETURN w0
    ELSIF (v. status # Language.statusOk) THEN
      RETURN v
    ELSIF (w0. int = 0) THEN
      RETURN NewValue (t, Language.statusDivByZero, 1)
    ELSE
      RETURN NewValue (t, Language.statusOk, v. int DIV w0. int)
    END
  END Div;

PROCEDURE (v: Value) Mod* (w: Numeric.Value): Value;
  VAR
    w0: Value;
    t: Type;
  BEGIN
    w0 := w(Value);
    t := v. type(Type);
    IF (w. status > v. status) THEN
      RETURN w0
    ELSIF (v. status # Language.statusOk) THEN
      RETURN v
    ELSIF (w0. int = 0) THEN
      RETURN NewValue (t, Language.statusDivByZero, 1)
    ELSE
      RETURN NewValue (t, Language.statusOk, v. int MOD w0. int)
    END
  END Mod;

PROCEDURE (v: Value) Cmp* (w: Numeric.Value): SHORTINT;
(* Compares 'a' to 'b'.  Result: -1: a<b;  0: a=b;  1: a>b 
   Above convention makes more sense since the comparison 
   can be directly extrapolated to a comparison between the 
   two numbers e.g.,
   
        Cmp(a,b)<0  then a<b
        Cmp(a,b)=0  then a=b
        Cmp(a,b)>0  then a>b
        Cmp(a,b)>=0 then a>=b
*)
  VAR
    w0: Value;
  BEGIN
    w0 := w(Value);
    IF (v. status # Language.statusOk) OR
       (w0. status # Language.statusOk) THEN
      RETURN MIN (SHORTINT)
    ELSIF (v. int < w0. int) THEN
      RETURN -1
    ELSIF (v. int > w0. int) THEN
      RETURN 1
    ELSE
      RETURN 0
    END
  END Cmp;

PROCEDURE (v: Value) Ash* (n: Value): Value;
  VAR
    n0: MAXINT;
    two: Value;
  BEGIN
    IF (n. status # Language.statusOk) THEN
      RETURN n
    ELSE
      n0 := n. int;
      two := NewValue (v. type(Type), Language.statusOk, 2);
      WHILE (n0 # 0) & (v. status = Language.statusOk) DO
        IF (n0 < 0) THEN
          v := v. Div (two); INC (n0)
        ELSE
          v := v. Mult (two); DEC (n0)
        END
      END;
      RETURN v
    END
  END Ash;

END Language:Integer.
