MODULE Language:Numeric [OOC_EXTENSIONS];

IMPORT
  Language;


TYPE
  Value* = POINTER TO ValueDesc;
  ValueDesc* = RECORD [ABSTRACT]
    (Language.ValueDesc)
  END;


PROCEDURE (v: Value) [ABSTRACT] Copy* (): Value;
  END Copy;

PROCEDURE (v: Value) [ABSTRACT] Neg* (): Value;
  END Neg;

PROCEDURE (v: Value) [ABSTRACT] Abs* (): Value;
  END Abs;

PROCEDURE (v: Value) [ABSTRACT] Add* (w: Value): Value;
  END Add;

PROCEDURE (v: Value) [ABSTRACT] Sub* (w: Value): Value;
  END Sub;

PROCEDURE (v: Value) [ABSTRACT] Mult* (w: Value): Value;
  END Mult;

PROCEDURE (v: Value) [ABSTRACT] Cmp* (w: Value): SHORTINT;
  END Cmp;

END Language:Numeric.
