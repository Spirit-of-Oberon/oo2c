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
    (* massage the output of sprintf to match our requirement; note: this
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
  BEGIN
    ASSERT(FALSE);
  END RealToFixed;

PROCEDURE RealToStr* (real: LONGREAL;
                      VAR str: ARRAY OF CHAR);
  BEGIN
    ASSERT(FALSE);
  END RealToStr;

END LRealStr.
