MODULE VTable2;

TYPE
  A = POINTER TO ADesc;
  ADesc = RECORD [VTABLE]
  END;

  B = POINTER TO BDesc;
  BDesc = RECORD (ADesc)
  END;

END VTable2.
