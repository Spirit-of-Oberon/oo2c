MODULE Language [OOC_EXTENSIONS];

CONST
  bitsPerWord* = 8;
  (**The number of bits within the smallest addressable unit in memory.  On
     most machines, this is a byte with @samp{8} bits.  On specialized
     processors, e.g. DSPs, this may be different.  *)

TYPE
  ValueStatus* = SHORTINT;
  
CONST
  statusOk* = 0;
  statusUnderflow* = 1;
  statusOverflow* = 2;
  statusDivByZero* = 3;
  statusFormatError* = 4;
  statusTypeError* = 5;
  
TYPE
  Type* = POINTER TO TypeDesc;
  TypeDesc* = RECORD [ABSTRACT]
  END;

TYPE
  Value* = POINTER TO ValueDesc;
  ValueDesc* = RECORD [ABSTRACT]
    type-: Type;
    status-: ValueStatus;
  END;


PROCEDURE InitValue* (v: Value; t: Type; status: ValueStatus);
  BEGIN
    v. type := t;
    v. status := status;
  END InitValue;

PROCEDURE (t: Type) [ABSTRACT] ValueOf* (str: ARRAY OF CHAR): Value;
  END ValueOf;

PROCEDURE (t: Type) [ABSTRACT] Min*(): Value;
  END Min;

PROCEDURE (t: Type) [ABSTRACT] Max*(): Value;
  END Max;

PROCEDURE (v: Value) [ABSTRACT] ToString* (VAR str: ARRAY OF CHAR);
  END ToString;

END Language.
