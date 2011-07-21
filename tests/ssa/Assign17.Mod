MODULE Assign17;

IMPORT Out:=Out0;
  
TYPE
  Data = POINTER TO DataRec;
  DataRec = RECORD END;
  IntData = POINTER TO IntDataRec;
  IntDataRec = 
    RECORD (DataRec)
      val : LONGINT;
    END;

PROCEDURE showerror(a:Data);
  VAR
    aIntDataRec : IntDataRec;
  BEGIN
    aIntDataRec := a^(IntDataRec);
    Out.Int(aIntDataRec.val, 0); Out.Ln;
  END showerror;

PROCEDURE Test*();
  VAR
    d: IntData;
  BEGIN
    NEW(d);
    d.val := 1234;
    showerror(d);
  END Test;

END Assign17.
