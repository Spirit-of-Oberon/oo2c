MODULE LRealStr;

IMPORT
  ConvTypes, LRealConv;
  
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

PROCEDURE RealToFloat* (real: LONGREAL; sigFigs: INTEGER;
                        VAR str: ARRAY OF CHAR);
  BEGIN
    ASSERT(FALSE);
  END RealToFloat;

PROCEDURE RealToEng* (real: LONGREAL; sigFigs: INTEGER;
                      VAR str: ARRAY OF CHAR);
  BEGIN
    ASSERT(FALSE);
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
