MODULE LRealConv;

IMPORT
  CharClass, ConvTypes;

(**

   The regular expression for a signed fixed-point real number is
   @samp{[+-]?\d+(\.\d* )?}.  For the optional exponent part, it is
   @samp{E[+-]?\d+}.
  
*)

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

CONST
  padding*=ConvTypes.padding;
  (**A leading or padding character at this point in the scan---ignore it. *)
  valid*=ConvTypes.valid;
  (**A valid character at this point in the scan---accept it.  *)
  invalid*=ConvTypes.invalid;
  (*An invalid character at this point in the scan---reject it *)
  terminator*=ConvTypes.terminator;
  (**A terminating character at this point in the scan (not part of token).  *)

TYPE
  ScanClass* = ConvTypes.ScanClass;
  ScanState* = ConvTypes.ScanState;

CONST
  SigFigs*=15;  (* Accuracy of LONGREALs.  Scrap this? ... FIXME *)
  expChar = "E";
  maxValue = "17976931348623157";
  (* signifcant digits of the maximum value 1.7976931348623157D+308 *)
  maxExp = 308;
  (* maxium positive exponent of a normalized number *)
  
VAR
  RS, P, F, E, SE, WE, SR: ScanState;
 

(* internal state machine procedures *)

PROCEDURE IsSign (ch: CHAR): BOOLEAN;
(* Return TRUE for '+' or '-' *)
  BEGIN
    RETURN (ch='+') OR (ch='-')
  END IsSign;  

PROCEDURE RSState(inputCh: CHAR;
                  VAR chClass: ScanClass; VAR nextState: ScanState);
  BEGIN
    IF CharClass.IsNumeric(inputCh) THEN
      chClass:=valid; nextState:=P
    ELSE
      chClass:=invalid; nextState:=RS
    END
  END RSState;

PROCEDURE PState(inputCh: CHAR;
                 VAR chClass: ScanClass; VAR nextState: ScanState);
  BEGIN
    IF CharClass.IsNumeric(inputCh) THEN
      chClass:=valid; nextState:=P
    ELSIF inputCh="." THEN
      chClass:=valid; nextState:=F
    ELSIF inputCh=expChar THEN
      chClass:=valid; nextState:=E  
    ELSE
      chClass:=terminator; nextState:=NIL
    END
  END PState;

PROCEDURE FState(inputCh: CHAR;
                 VAR chClass: ScanClass; VAR nextState: ScanState);
  BEGIN
    IF CharClass.IsNumeric(inputCh) THEN
      chClass:=valid; nextState:=F
    ELSIF inputCh=expChar THEN
      chClass:=valid; nextState:=E  
    ELSE
      chClass:=terminator; nextState:=NIL
    END
  END FState;

PROCEDURE EState(inputCh: CHAR;
                 VAR chClass: ScanClass; VAR nextState: ScanState);
  BEGIN
    IF IsSign(inputCh) THEN
      chClass:=valid; nextState:=SE
    ELSIF CharClass.IsNumeric(inputCh) THEN
      chClass:=valid; nextState:=WE  
    ELSE
      chClass:=invalid; nextState:=E
    END
  END EState;

PROCEDURE SEState(inputCh: CHAR;
                  VAR chClass: ScanClass; VAR nextState: ScanState);
  BEGIN
    IF CharClass.IsNumeric(inputCh) THEN
      chClass:=valid; nextState:=WE  
    ELSE
      chClass:=invalid; nextState:=SE
    END
  END SEState;

PROCEDURE WEState(inputCh: CHAR;
                  VAR chClass: ScanClass; VAR nextState: ScanState);
  BEGIN
    IF CharClass.IsNumeric(inputCh) THEN
      chClass:=valid; nextState:=WE  
    ELSE
      chClass:=terminator; nextState:=NIL
    END
  END WEState;

PROCEDURE ScanReal*(inputCh: CHAR;
                    VAR chClass: ScanClass; VAR nextState: ScanState);
  BEGIN
    IF CharClass.IsWhiteSpace(inputCh) THEN
      chClass:=padding; nextState:=SR
    ELSIF IsSign(inputCh) THEN
      chClass:=valid; nextState:=RS
    ELSIF CharClass.IsNumeric(inputCh) THEN
      chClass:=valid; nextState:=P
    ELSE
      chClass:=invalid; nextState:=SR
    END
  END ScanReal;

PROCEDURE FormatReal* (str: ARRAY OF CHAR): ConvResults;
  VAR
    i: LONGINT;
    ch: CHAR;
    state: ScanState;
    class: ScanClass;
    wSigFigs, fLeadingZeros, exp, startOfExp: LONGINT;
    expNegative, allZeroDigit: BOOLEAN;
    
  CONST
    expCutoff = 100000000;
    (* assume overflow if the value of the exponent is larger than this *)

  PROCEDURE NonZeroDigit (): LONGINT;
  (* locate first non-zero digit in str *)
    BEGIN
      i := 0;
      WHILE (i # startOfExp) & ((str[i] < "1") OR (str[i] > "9")) DO
        INC (i);
      END;
      RETURN i;
    END NonZeroDigit;
  
  PROCEDURE LessOrEqual (upperBound: ARRAY OF CHAR): BOOLEAN;
    VAR
      i, j: LONGINT;
    BEGIN
      i := NonZeroDigit();
      IF (i # startOfExp) THEN         (* str[i] is non-zero digit  *)
        j := 0;
        WHILE (i # startOfExp) & (upperBound[j] # 0X) DO
          IF (str[i] < upperBound[j]) THEN
            RETURN TRUE;
          ELSIF (str[i] > upperBound[j]) THEN
            RETURN FALSE;
          ELSE
            INC (j); INC (i);
            IF (str[i] = ".") THEN       (* skip decimal point *)
              INC (i);
            END;
          END;
        END;
        
        IF (upperBound[j] = 0X) THEN
          (* any trailing zeros don't change the outcome: skip them *)
          WHILE (str[i] = "0") OR (str[i] = ".") DO
            INC (i);
          END;
        END;
      END;
      RETURN (i = startOfExp);
    END LessOrEqual;
  
  BEGIN
    (* normalize exponent character *)
    i := 0;
    WHILE (str[i] # 0X) & (str[i] # "e") DO
      INC (i);
    END;
    IF (str[i] = "e") THEN
      str[i] := expChar;
    END;
    
    (* move index `i' over padding characters *)
    i := 0;
    state := SR;
    REPEAT
      ch := str[i];
      state.p(ch, class, state);
      INC (i);
    UNTIL (class # padding);

    IF (ch = 0X) THEN
      RETURN strEmpty;
    ELSE
      (* scan part before decimal point or exponent *)
      WHILE (class = valid) & (state # F) & (state # E) &
            ((ch < "1") OR (ch > "9")) DO
        ch := str[i];
        state.p(ch, class, state);
        INC (i);
      END;
      wSigFigs := 0;
      WHILE (class = valid) & (state # F) & (state # E) DO
        INC (wSigFigs);
        ch := str[i];
        state.p(ch, class, state);
        INC (i);
      END;
      (* here holds: wSigFigs is the number of significant digits in
         the whole number part of the number; 0 means there are only
         zeros before the decimal point *)
      
      (* scan fractional part exponent *)
      fLeadingZeros := 0; allZeroDigit := TRUE;
      WHILE (class = valid) & (state # E) DO
        ch := str[i];
        IF allZeroDigit THEN
          IF (ch = "0") THEN
            INC (fLeadingZeros);
          ELSIF (ch # ".") THEN
            allZeroDigit := FALSE;
          END;
        END;
        state.p(ch, class, state);
        INC (i);
      END;
      (* here holds: fLeadingZeros holds the number of zeros after
         the decimal point *)
      
      (* scan exponent *)
      startOfExp := i-1; exp := 0; expNegative := FALSE;
      WHILE (class = valid) DO
        ch := str[i];
        IF (ch = "-") THEN
          expNegative := TRUE;
        ELSIF ("0" <= ch) & (ch <= "9") & (exp < expCutoff) THEN
          exp := exp*10 + (ORD(ch)-ORD("0"));
        END;
        state.p(ch, class, state);
        INC (i);
      END;
      IF expNegative THEN
        exp := -exp;
      END;
      (* here holds: exp holds the value of the exponent; if it's absolute
         value is larger than expCutoff, then there has been an overflow  *)

      IF (class = invalid) OR (ch # 0X) THEN
        RETURN strWrongFormat;
      ELSE (* (class = terminator) & (ch = 0X) *)
        (* normalize the number: calculate the exponent if the number would
           start with a non-zero digit, immediately followed by the
           decimal point *)
        IF (wSigFigs > 0) THEN
          exp := exp+wSigFigs-1;
        ELSE
          exp := exp-fLeadingZeros-1;
        END;
        
        IF (exp > maxExp) & (NonZeroDigit() # startOfExp) OR
           (exp = maxExp) & ~LessOrEqual (maxValue) THEN
          RETURN strOutOfRange;
        ELSE
          RETURN strAllRight;
        END;
      END;
    END;
  END FormatReal;
 
PROCEDURE ValueReal*(str: ARRAY OF CHAR): LONGREAL;
  BEGIN
    RETURN -1.0;
  END ValueReal;

PROCEDURE LengthFloatReal*(real: LONGREAL; sigFigs: INTEGER): INTEGER;
  BEGIN
    RETURN -1;
  END LengthFloatReal;
 
PROCEDURE LengthEngReal*(real: LONGREAL; sigFigs: INTEGER): INTEGER;
  BEGIN
    RETURN -1;
  END LengthEngReal;
 
PROCEDURE LengthFixedReal*(real: LONGREAL; place: INTEGER): INTEGER;
  BEGIN
    RETURN -1;
  END LengthFixedReal;

BEGIN
  NEW(RS); RS.p:=RSState; 
  NEW(P);  P.p:=PState; 
  NEW(F);  F.p:=FState; 
  NEW(E);  E.p:=EState;
  NEW(SE); SE.p:=SEState; 
  NEW(WE); WE.p:=WEState; 
  NEW(SR); SR.p:=ScanReal;
END LRealConv.
