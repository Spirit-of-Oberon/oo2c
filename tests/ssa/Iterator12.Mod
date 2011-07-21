MODULE Iterator12;

TYPE
  Instr* = POINTER TO InstrDesc;
  InstrDesc = RECORD 
  END;
  Block* = POINTER TO BlockDesc;
  BlockDesc = RECORD
  END;

PROCEDURE P*(b: Block);
  VAR
    instr: Instr;
  BEGIN
    FOR instr IN b DO
    END;
  END P;

END Iterator12.
