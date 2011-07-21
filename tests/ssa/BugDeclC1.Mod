MODULE BugDeclC1;

TYPE
  SleepQRecPtr* = POINTER TO SleepQRec;
  SleepQProcPtr* = PROCEDURE (message: LONGINT;
                              qRecPtr: SleepQRecPtr): LONGINT;
  SleepQRec_struct* = RECORD
  END;
  SleepQRec* = SleepQRec_struct;

PROCEDURE Test*();
  BEGIN
  END Test;
                     
END BugDeclC1.
