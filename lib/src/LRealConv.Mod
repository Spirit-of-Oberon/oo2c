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
    ELSIF inputCh="E" THEN
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
    ELSIF inputCh="E" THEN
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

PROCEDURE FormatReal*(str: ARRAY OF CHAR): ConvResults;
  BEGIN
    RETURN -1;
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
