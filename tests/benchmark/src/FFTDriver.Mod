MODULE FFTDriver;

IMPORT 
  Out, R := RealMath,
  D := Driver, C := Category, Type,

  FFT, FFTC;

TYPE
  Driver = POINTER TO DriverDesc;
  DriverDesc = RECORD (D.DriverDesc)
  END;

VAR
  driver : Driver;
  info : D.Info;
  c : C.Category;

VAR
  (* Complex array for FFT *)
  a : ARRAY 256 OF Type.Complex;

PROCEDURE ShowArray();
VAR
  i : INTEGER;
BEGIN
  FOR i := 0 TO LEN(a) - 1 DO
    Out.Int(i, 0); Out.String(" "); 
    Out.Real(a[i].r, 0, 0); Out.String(" ");
    Out.Real(a[i].r, 0, 0); Out.Ln;
  END;
END ShowArray; 

PROCEDURE FillArray;
VAR i : INTEGER;
BEGIN
  FOR i := 0 TO LEN(a) - 1 DO
    a[i].r := R.sin(2 * R.pi * 2 * i / LEN(a));
    a[i].i := 0;
  END;
END FillArray;

PROCEDURE (d : Driver) Exec* (testId : LONGINT; count : LONGINT);
BEGIN
  CASE testId OF
  | 0 :  (* FFT *)
    FillArray();
    WHILE count > 0 DO
      FFT.FFT(a, TRUE);  (* forward *)
      FFT.FFT(a, FALSE); (* reverse *)
      DEC(count);
    END;
  | 1 : (* FFTC *)
    FillArray();
    WHILE count > 0 DO
      FFTC.FFT(a, LEN(a), TRUE);  (* forward *)
      FFTC.FFT(a, LEN(a), FALSE); (* reverse *)
      DEC(count);
    END;
  | 2 : (* FFT2 *)
    FillArray();
    WHILE count > 0 DO
      FFT.FFT2(a, TRUE);  (* forward *)
      FFT.FFT2(a, FALSE); (* reverse *)
      DEC(count);
    END;
  | 3 : (* FFT2C *)
    FillArray();
    WHILE count > 0 DO
      FFTC.FFT2(a, LEN(a), TRUE);  (* forward *)
      FFTC.FFT2(a, LEN(a), FALSE); (* reverse *)
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

  info[0].name := "FFT";
  info[0].reference := 1;
  info[0].desc := "256 point complex FFT and IFFT. Butterfly in-line.";

  info[1].name := "FFTC";
  info[1].reference := -1;
  info[1].desc := "256 point complex FFT and IFFT. Butterfly in-line.";

  info[2].name := "FFT2";
  info[2].reference := 3;
  info[2].desc := "256 point complex FFT and IFFT. Butterfly in procedure.";

  info[3].name := "FFT2C";
  info[3].reference := -1;
  info[3].desc := "256 point complex FFT and IFFT. Butterfly in procedure.";

  NEW(driver);
  D.Register(driver);

  c := C.New("TestFFT");
  c.AddTest("FFT"); c.AddTest("FFT2"); c.AddTest("FFTC"); c.AddTest("FFT2C");
  C.Register(c);
END FFTDriver.
