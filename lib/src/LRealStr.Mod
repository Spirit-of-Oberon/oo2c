MODULE LRealStr;

IMPORT
  C, CharClass, ConvTypes, LRealConv, Strings;
  
TYPE
  ConvResults* = ConvTypes.ConvResults;
  (**One of @oconst{strAllRight}, @oconst{strOutOfRange},
     @oconst{strWrongFormat}, or @oconst{strEmpty}.  *)

CONST
  strAllRight*=ConvTypes.strAllRight;
  (**The string format is correct for the corresponding conversion.  *)
  strOutOfRange*=ConvTypes.strOutOfRange;
  (**The string is well-formed but the value cannot be represented.  *)
  strWrongFormat*=ConvTypes.strWrongFormat;
  (**The string is in the wrong format for the conversion.  *)
  strEmpty*=ConvTypes.strEmpty;
  (**The given string is empty.  *)

PROCEDURE StrToReal*(str: ARRAY OF CHAR;
                     VAR real: LONGREAL; VAR res: ConvResults);
  BEGIN
    res := LRealConv.FormatReal (str);
    IF (res IN {strAllRight, strOutOfRange}) THEN
      real := LRealConv.ValueReal (str);
    END;
  END StrToReal;

PROCEDURE IsSign (ch: CHAR): BOOLEAN;
  BEGIN
    RETURN (ch = "-") OR (ch = "+")
  END IsSign;

PROCEDURE NormalizeFloat (VAR s: ARRAY OF CHAR);
  VAR
    i, d: INTEGER;
  BEGIN
    (* massage the output of sprintf to match our requirements; note: this
       code should also handle "Inf", "Infinity", "NaN", etc., gracefully
       but this is untested *)
    IF (s[0] = "+") THEN d := 1; ELSE d := 0; END; (* erase "+" sign *)
    i := 1;
    WHILE (s[i] # 0X) DO
      IF (s[i] = ".") & (s[i+1] = "E") THEN
        INC (d);             (* eliminate "." if no digits follow *)
      ELSIF (s[i] = "0") & IsSign (s[i-d-1]) THEN
        INC (d);           (* eliminate zeros after exponent sign *)
      ELSE
        s[i-d] := s[i];
      END;
      INC (i);
    END;
    IF (s[i-d-2] = "E") THEN
      s[i-d-2] := 0X;                  (* remove "E+" or "E-" *)
    ELSE
      s[i-d] := 0X;
    END;
  END NormalizeFloat;

PROCEDURE RealToFloat* (real: LONGREAL; sigFigs: INTEGER;
                        VAR str: ARRAY OF CHAR);
(**Assign to @oparam{str} the possibly truncated string corresponding to the
   value of @oparam{real} in floating-point form.  A sign is included only for
   negative values.  One significant digit is included in the whole number
   part.  The signed exponent part is included only if the exponent value is
   not 0.  If the value of @oparam{sigFigs} is greater than 0, that number of
   significant digits is included, otherwise an implementation-defined number
   of significant digits.  The decimal point shall is not included if there are
   no significant digits in the fractional part.

   For example:

   @example
   value:   3923009     39.23009     0.0003923009
   sigFigs
   1        4E+6        4E+1         4E-4 
   2        3.9E+6      3.9E+1       3.9E-4
   5        3.9230E+6   3.9230E+1    3.9230E-4
   @end example  *)
  VAR
    s: ARRAY 32 OF CHAR;
    i, d: INTEGER;
  BEGIN
    IF (sigFigs < 1) OR (sigFigs > 17) THEN sigFigs := 17; END;
    C.sprintf(s, "%-+#.*E", sigFigs-1, real);
    NormalizeFloat (s);
    COPY (s, str);
  END RealToFloat;

PROCEDURE RealToEng* (real: LONGREAL; sigFigs: INTEGER;
                      VAR str: ARRAY OF CHAR);
(**Converts the value of @oparam{real} to floating-point string form, with
   @oparam{sigFigs} significant figures, and copies the possibly truncated
   result to @oparam{str}.  The number is scaled with one to three digits in
   the whole number part and with an exponent that is a multiple of three.  For
   example:

   @example
   value:   3923009     39.23009   0.0003923009
   sigFigs
   1        4E+6        40         400E-6 
   2        3.9E+6      39         390E-6
   5        3.9230E+6   39.230     392.30E-6     
   @end example  *)
  VAR
    s: ARRAY 32 OF CHAR;
    i, d, fract, exp, posExp, offset: INTEGER;
  BEGIN
    IF (sigFigs < 1) OR (sigFigs > 17) THEN sigFigs := 17; END;
    C.sprintf(s, "%-+#.*E", sigFigs-1, real);

    (* find out how large the exponent is, and how many digits are in the
       fractional part *)
    fract := 0; exp := 0;
    IF CharClass.IsNumeric (s[1]) THEN   (* skip for NaN, Inf *)
      i := 0; d := 0;
      WHILE (s[i] # "E") DO
        fract := fract + d;
        IF (s[i] = ".") THEN d := 1; END;
        INC (i);
      END;
      INC (i);
      IF (s[i] = "-") THEN d := -1; ELSE d := 1; END;
      posExp := i;
      INC (i);
      WHILE (s[i] # 0X) DO
        exp := exp*10 + d*(ORD (s[i]) - ORD ("0"));
        INC (i);
      END;
    END;

    offset := exp MOD 3;
    IF (offset # 0) THEN
      WHILE (fract < offset) DO        (* need more zeros before "E" *)
        Strings.Insert ("0", posExp-1, s); INC (fract); INC (posExp);
      END;
      i := 2;
      WHILE (i < offset+2) DO    (* move "." offset places to right *)
        s[i] := s[i+1]; INC (i);
      END;
      s[i] := ".";

      (* write new exponent *)
      exp := exp-offset;
      IF (exp < 0) THEN
        exp := -exp; s[posExp] := "-";
      ELSE
        s[posExp] := "+";
      END;
      s[posExp+1] := CHR (exp DIV 100 + ORD("0"));
      s[posExp+2] := CHR (exp DIV 10 MOD 10 + ORD("0"));
      s[posExp+3] := CHR (exp MOD 10 + ORD("0"));
      s[posExp+4] := 0X;
    END;
    NormalizeFloat (s);
    COPY (s, str);
  END RealToEng;

PROCEDURE RealToFixed* (real: LONGREAL; place: INTEGER;
                        VAR str: ARRAY OF CHAR);
(**The call @samp{RealToFixed(real,place,str)} assigns to @oparam{str} the
   possibly truncated string corresponding to the value of @oparam{real} in
   fixed-point form.  A sign is included only for negative values.  At least
   one digit is included in the whole number part.  The value is rounded to the
   given value of @oparam{place} relative to the decimal point.  The decimal
   point is suppressed if @oparam{place} is less than @samp{0}.  For example:

   @example
   value:    3923009         3.923009   0.0003923009
   sigFigs
   -5        3920000         0          0 
   -2        3923010         0          0
   -1        3923009         4          0 
   0         3923009.        4.         0. 
   1         3923009.0       3.9        0.0
   4         3923009.0000    3.9230     0.0004       
   @end example  *)
  VAR
    s: ARRAY 308+32 OF CHAR;
    i, d, c, sigFigs, fract, point, suffix: INTEGER;

  PROCEDURE NotZero (VAR s: ARRAY OF CHAR; pos: INTEGER): BOOLEAN;
    BEGIN
      WHILE (s[pos] # 0X) DO
        IF (s[pos] # "0") & (s[pos] # ".") THEN
          RETURN TRUE;
        END;
        INC (pos);
      END;
      RETURN FALSE;
    END NotZero;
  
  BEGIN
    IF (place < 0) THEN sigFigs := 16+1; ELSE sigFigs := place END;
    C.sprintf(s, "%-+#.*f", sigFigs, real);

    IF (place < 0) THEN
      (* locate position of decimal point in string *)
      point := 1;
      WHILE (s[point] # ".") DO INC (point); END;
      
      (* number of digits before point is `point-1'; position in string
         of the first digit that will be converted to zero due to rounding:
         `point+place+1'; rightmost digit that may be incremented because
         of rounding: `point+place' *)
      IF (point+place >= 0) THEN
        suffix := point+place+1; IF (s[suffix] = ".") THEN INC (suffix); END;
        IF (s[suffix] > "5") OR
           (s[suffix] = "5") &
            (NotZero (s, suffix+1) OR
             (point+place # 0) & (ORD (s[point+place]) MOD 2 = 1)) THEN
          (* we are rounding up *)
          i := point+place;
          WHILE (s[i] = "9") DO s[i] := "0"; DEC (i); END;
          IF (i = 0) THEN                (* looking at sign *)
            Strings.Insert ("1", 1, s); INC (point);
          ELSE
            s[i] := CHR (ORD (s[i])+1);  (* increment non-"9" digit by one *)
          END;
        END;
        
        (* zero everything after the digit at `place' *)
        i := point+place+1;
        IF (i = 1) THEN                  (* all zero *)
          s[1] := "0"; s[2] := 0X;
        ELSE
          WHILE (s[i] # ".") DO s[i] := "0"; INC (i); END;
        END;
      ELSE                                 (* round to zero *)
        s[1] := "0"; s[2] := 0X;
      END;
      s[point] := 0X;
    END;

    (* correct sign, and add trailing zeros if necessary *)
    IF (s[0] = "+") THEN d := 1; ELSE d := 0; END; (* erase "+" sign *)
    i := 1; fract := 0; c := 0;
    WHILE (s[i] # 0X) DO
      s[i-d] := s[i];
      fract := fract+c;
      IF (s[i] = ".") THEN
        c := 1;
      END;
      INC (i);
    END;
    WHILE (fract < place) DO
      s[i-d] := "0"; INC (fract); INC (i);
    END;
    s[i-d] := 0X;
    
    COPY (s, str);
  END RealToFixed;

PROCEDURE RealToStr* (real: LONGREAL;
                      VAR str: ARRAY OF CHAR);
(**If the sign and magnitude of @oparam{real} can be shown within the capacity
   of @oparam{str}, the call @samp{RealToStr(real,str)} behaves as the call
   @samp{RealToFixed(real,place,str)}, with a value of @samp{place} chosen to
   fill exactly the remainder of @oparam{str}.  Otherwise, the call behaves as
   the call @samp{RealToFloat(real,sigFigs,str)}, with a value of
   @samp{sigFigs} of at least one, but otherwise limited to the number of
   significant digits that can be included together with the sign and exponent
   part in @oparam{str}.  *)
  VAR
    s: ARRAY 308+32 OF CHAR;
    d, sigFigs: LONGINT;
  BEGIN
    (* use a trial and error approach; this may not be fast, nor unambiguous,
       but it should be correct *)
    RealToFixed(real, -1, s);
    d := LEN (str)-Strings.Length (s)-1;
    IF (d > 0) THEN
      RealToFixed(real, SHORT (d)-1, s);
    ELSIF (d < 0) THEN
      RealToFloat(real, 1, s);
      d := LEN (str)-Strings.Length (s)-1;
      IF (d > 1) THEN          (* room for "." and additional digit *)
        RealToFloat(real, SHORT (d), s);
        IF (Strings.Length(s) < LEN(str)-1) THEN
          (* exponent smaller than expected due to rounding *)
          RealToFloat(real, SHORT (d)+1, s);
        END;
      END;
    END;
    COPY (s, str);
  END RealToStr;

END LRealStr.
