MODULE PRE3;
<*DerefCheck:=FALSE; TypeGuard:=FALSE*>

TYPE
  Node = POINTER TO NodeDesc;
  NodeDesc = RECORD [ABSTRACT]
  END;

TYPE
  ModuleFlags = POINTER TO ModuleFlagsDesc;
  ModuleFlagsDesc = RECORD
    (NodeDesc)
    str: POINTER TO ARRAY OF CHAR;
  END;
  
TYPE
  Flags = POINTER TO FlagsDesc;
  FlagsDesc = RECORD
    (NodeDesc)
    n: Node;
  END;

PROCEDURE T* (flags: Flags);
  VAR
    mf: ModuleFlags;
  BEGIN
    mf := NIL;
    IF (flags # NIL) & (flags.n IS ModuleFlags) THEN
      mf := flags.n(ModuleFlags);
      ASSERT (mf.str^ = "FOREIGN");
    END;
    ASSERT(mf # NIL);
  END T;

END PRE3.
