MODULE VTable2;

TYPE
  A = POINTER TO ADesc;
  ADesc = RECORD 
  END;

  B = POINTER TO BDesc;
  BDesc = RECORD [VTABLE] (ADesc)
  END;

END VTable2.
