MODULE MiscDriver;

IMPORT 
  Out, R := RealMath,
  D := Driver, C := Category, Type,

  Warshall, WarshallC;

TYPE
  Driver = POINTER TO DriverDesc;
  DriverDesc = RECORD (D.DriverDesc)
  END;

VAR
  driver : Driver;
  info : D.Info;
  c : C.Category;

VAR
  (* Complex array for Misc *)
  a : ARRAY 256, 256 OF BOOLEAN;

PROCEDURE FillArray;
VAR i, j : INTEGER;
BEGIN
  FOR i := 0 TO LEN(a)-1 DO
    FOR j := 0 TO LEN(a,1)-1 DO
      a[i, j] := (i-j = 1);
    END;
  END;
END FillArray;

PROCEDURE (d : Driver) Exec* (testId : LONGINT; count : LONGINT);
BEGIN
  CASE testId OF
  | 0 :  (* Warshall *)
    FillArray();
    WHILE count > 0 DO
      Warshall.Transclosure(a, LEN(a));
      DEC(count);
    END;
  | 1 : (* WarshallC *)
    FillArray();
    WHILE count > 0 DO
      WarshallC.Transclosure(a, LEN(a));
      DEC(count);
    END;
  END;
END Exec;

PROCEDURE (d : Driver) GetInfo* () : D.Info;
BEGIN
  RETURN info;
END GetInfo;

BEGIN
  NEW(info, 2);

  info[0].name := "Warshall";
  info[0].reference := 1;
  info[0].desc := "Transitive closure on adjactency matrix.";

  info[1].name := "WarshallC";
  info[1].reference := -1;
  info[1].desc := "Transitive closure on adjactency matrix.";
  
  NEW(driver);
  D.Register(driver);

  c := C.New("TestMisc");
  c.AddTest("Warshall"); c.AddTest("WarshallC");
  C.Register(c);
END MiscDriver.
