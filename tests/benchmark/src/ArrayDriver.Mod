MODULE ArrayDriver;

IMPORT 
  D := Driver, C := Category,

  Type, Array, ArrayC;

TYPE
  Driver = POINTER TO DriverDesc;
  DriverDesc = RECORD (D.DriverDesc)
  END;

VAR
  driver : Driver;
  info : D.Info;
  c : C.Category;

CONST
  size = 10000;

VAR
  a, b : Type.RealArray;

PROCEDURE (d : Driver) Exec* (testId : LONGINT; count : LONGINT);
BEGIN
  CASE testId OF
  | 0 :  (* ZeroArray1 *)
    WHILE count > 0 DO
      Array.ZeroArray1(a, size);
      DEC(count);
    END;
  | 1 :  (* ZeroArray2 *)
    WHILE count > 0 DO
      Array.ZeroArray2(a, size);
      DEC(count);
    END;
  | 2 :  (* ZeroArray4 *)
    WHILE count > 0 DO
      Array.ZeroArray4(a, size);
      DEC(count);
    END;
  | 3 :  (* CopyArray1 *)
    WHILE count > 0 DO
      Array.CopyArray1(a, b, size);
      DEC(count);
    END;
  | 4 :  (* CopyArray2 *)
    WHILE count > 0 DO
      Array.CopyArray2(a, b, size);
      DEC(count);
    END;
  | 5 :  (* CopyArray4 *)
    WHILE count > 0 DO
      Array.CopyArray4(a, b, size);
      DEC(count);
    END;
  | 6 :  (* CopyArrayMove *)
    WHILE count > 0 DO
      Array.CopyArrayMove(a, b, size);
      DEC(count);
    END;
  | 7 :  (* AddArray1 *)
    WHILE count > 0 DO
      Array.AddArray1(a, b, size);
      DEC(count);
    END;
  | 8 :  (* AddArray2 *)
    WHILE count > 0 DO
      Array.AddArray2(a, b, size);
      DEC(count);
    END;
  | 9 :  (* AddArray4 *)
    WHILE count > 0 DO
      Array.AddArray4(a, b, size);
      DEC(count);
    END;
  | 10 :  (* ZeroArray1C *)
    WHILE count > 0 DO
      ArrayC.ZeroArray1(a, size);
      DEC(count);
    END;
  | 11 :  (* ZeroArray2C *)
    WHILE count > 0 DO
      ArrayC.ZeroArray2(a, size);
      DEC(count);
    END;
  | 12 :  (* ZeroArray4C *)
    WHILE count > 0 DO
      ArrayC.ZeroArray4(a, size);
      DEC(count);
    END;
  | 13 :  (* ZeroArrayBlockC *)
    WHILE count > 0 DO
      ArrayC.ZeroArrayBlock(a, size);
      DEC(count);
    END;
  | 14 :  (* CopyArray1C *)
    WHILE count > 0 DO
      ArrayC.CopyArray1(a, b, size);
      DEC(count);
    END;
  | 15 :  (* CopyArray2C *)
    WHILE count > 0 DO
      ArrayC.CopyArray2(a, b, size);
      DEC(count);
    END;
  | 16 :  (* CopyArray4C *)
    WHILE count > 0 DO
      ArrayC.CopyArray4(a, b, size);
      DEC(count);
    END;
  | 17 :  (* CopyArrayBlockC *)
    WHILE count > 0 DO
      ArrayC.CopyArrayBlock(a, b, size);
      DEC(count);
    END;
  | 18 :  (* AddArray1C *)
    WHILE count > 0 DO
      ArrayC.AddArray1(a, b, size);
      DEC(count);
    END;
  | 19 :  (* AddArray2C *)
    WHILE count > 0 DO
      ArrayC.AddArray2(a, b, size);
      DEC(count);
    END;
  | 20 :  (* AddArray4C *)
    WHILE count > 0 DO
      ArrayC.AddArray4(a, b, size);
      DEC(count);
    END;
  END;
END Exec;

PROCEDURE (d : Driver) GetInfo* () : D.Info;
BEGIN
  RETURN info;
END GetInfo;

BEGIN
  NEW(a, size);
  NEW(b, size);
  NEW(info, 21);

  info[0].name := "ZeroArray1";
  info[0].reference := 10;
  info[0].desc := "Fill array with zero, 1 element per iteration";

  info[1].name := "ZeroArray2";
  info[1].reference := 11;
  info[1].desc := "Fill array with zero, 2 elements per iteration";

  info[2].name := "ZeroArray4";
  info[2].reference := 12;
  info[2].desc := "Fill array with zero, 4 elements per iteration";

  info[3].name := "CopyArray1";
  info[3].reference := 14;
  info[3].desc := "Copy array, 1 element per iteration";

  info[4].name := "CopyArray2";
  info[4].reference := 15;
  info[4].desc := "Copy array, 2 elements per iteration";

  info[5].name := "CopyArray4";
  info[5].reference := 16;
  info[5].desc := "Copy array, 4 elements per iteration";

  info[6].name := "CopyArrayMove";
  info[6].reference := 17;
  info[6].desc := "Copy array using SYSTEM.MOVE";

  info[7].name := "AddArray1";
  info[7].reference := 18;
  info[7].desc := "Add array, 1 element per iteration";

  info[8].name := "AddArray2";
  info[8].reference := 19;
  info[8].desc := "Add array, 2 elements per iteration";

  info[9].name := "AddArray4";
  info[9].reference := 20;
  info[9].desc := "Add array, 4 elements per iteration";

  info[10].name := "ZeroArray1C";
  info[10].reference := -1;
  info[10].desc := "Fill array with zero, 1 element per iteration";

  info[11].name := "ZeroArray2C";
  info[11].reference := -1;
  info[11].desc := "Fill array with zero, 2 elements per iteration";

  info[12].name := "ZeroArray4C";
  info[12].reference := -1;
  info[12].desc := "Fill array with zero, 4 elements per iteration";

  info[13].name := "ZeroArrayBlockC";
  info[13].reference := -1;
  info[13].desc := "Fill array with zero, using memset";

  info[14].name := "CopyArray1C";
  info[14].reference := -1;
  info[14].desc := "Copy array, 1 element per iteration";

  info[15].name := "CopyArray2C";
  info[15].reference := -1;
  info[15].desc := "Copy array, 2 elements per iteration";

  info[16].name := "CopyArray4C";
  info[16].reference := -1;
  info[16].desc := "Copy array, 4 elements per iteration";

  info[17].name := "CopyArrayBlockC";
  info[17].reference := -1;
  info[17].desc := "Copy array using memcpy";

  info[18].name := "AddArray1C";
  info[18].reference := -1;
  info[18].desc := "Add array, 1 element per iteration";

  info[19].name := "AddArray2C";
  info[19].reference := -1;
  info[19].desc := "Add array, 2 elements per iteration";

  info[20].name := "AddArray4C";
  info[20].reference := -1;
  info[20].desc := "Add array, 4 elements per iteration";

  NEW(driver);
  D.Register(driver);

  c := C.New("ZeroArray");
  c.AddTest("ZeroArray1"); c.AddTest("ZeroArray2"); c.AddTest("ZeroArray4");
  c.AddTest("ZeroArray1C"); c.AddTest("ZeroArray2C"); c.AddTest("ZeroArray4C");
  c.AddTest("ZeroArrayBlockC");
  C.Register(c);

  c := C.New("CopyArray");
  c.AddTest("CopyArray1"); c.AddTest("CopyArray2");
  c.AddTest("CopyArray4"); c.AddTest("CopyArrayMove");
  c.AddTest("CopyArray1C"); c.AddTest("CopyArray2C");
  c.AddTest("CopyArray4C"); c.AddTest("CopyArrayBlockC");
  C.Register(c);

  c := C.New("AddArray");
  c.AddTest("AddArray1"); c.AddTest("AddArray2"); c.AddTest("AddArray4");
  c.AddTest("AddArray1C"); c.AddTest("AddArray2C"); c.AddTest("AddArray4C");
  C.Register(c);

END ArrayDriver.
