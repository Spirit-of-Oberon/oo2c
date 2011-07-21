MODULE SortDriver;

IMPORT 
  D := Driver, C := Category,

  Sort, SortC;

TYPE
  Driver = POINTER TO DriverDesc;
  DriverDesc = RECORD (D.DriverDesc)
  END;

VAR
  driver : Driver;
  info : D.Info;
  c : C.Category;

CONST
  size = 1000;

VAR
  a : ARRAY size OF LONGINT;

PROCEDURE FillArray;
VAR i : LONGINT;
BEGIN
  FOR i := 0 TO size-1 DO
    a[i] := i;
  END;
END FillArray;

(* FIXME! Check order for input array. Add tests for sorted/unsorted input? *)

PROCEDURE (d : Driver) Exec* (testId : LONGINT; count : LONGINT);
BEGIN
  CASE testId OF
  | 0 :  (* QSORT *)
    WHILE count > 0 DO
      FillArray();
      Sort.QuickSort(a, 0, LEN(a)-1);
      DEC(count);
    END;
  | 1 : (* QSORTC *)
    WHILE count > 0 DO
      FillArray();
      SortC.QuickSort(a, 0, LEN(a)-1);
      DEC(count);
    END;
  | 2 : (* BSORT *)
    WHILE count > 0 DO
      FillArray();
      Sort.BubbleSort(a);
      DEC(count);
    END;
  | 3 : (* BSORTC *)
    WHILE count > 0 DO
      FillArray();
      SortC.BubbleSort(a, LEN(a));
      DEC(count);
    END;
  END;
END Exec;

PROCEDURE (d : Driver) GetInfo* () : D.Info;
BEGIN
  RETURN info;
END GetInfo;

BEGIN
  NEW(info, 4);

  info[0].name := "QSORT";
  info[0].reference := 1;
  info[0].desc := "QuickSort 1000 element LONGINT array.";

  info[1].name := "QSORTC";
  info[1].reference := -1;
  info[1].desc := "QuickSort 1000 element LONGINT array.";

  info[2].name := "BSORT";
  info[2].reference := 3;
  info[2].desc := "BubbleSort 1000 element LONGINT array.";

  info[3].name := "BSORTC";
  info[3].reference := -1;
  info[3].desc := "BubbleSort 1000 element LONGINT array.";

  NEW(driver);
  D.Register(driver);

  c := C.New("Sort");
  c.AddTest("QSORT"); c.AddTest("QSORTC");
  c.AddTest("BSORT"); c.AddTest("BSORTC");
  C.Register(c);

END SortDriver.
