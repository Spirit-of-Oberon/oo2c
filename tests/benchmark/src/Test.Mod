MODULE Test;

IMPORT 
  Channel, ProgramArgs, TextRider, Out, Err, Time,

  Driver,

  FFTDriver,
  SortDriver;

PROCEDURE RunTest (d : Driver.Driver; id : LONGINT; VAR info : Driver.InfoDesc);
VAR
  t1, t2 : Time.TimeStamp;
  i : Time.Interval;
  j, count : LONGINT;
BEGIN
  count := 1;
  Out.String(info.name); 
  Out.String(": ");
  Out.Flush;
  REPEAT
    count := count * 2;
    Out.LongInt(count,0); Out.Char(" "); Out.Flush;
    Time.GetTime(t1);
    d.Exec(id, count);
    Time.GetTime(t2);
    t2.Delta(t1, i);
  UNTIL i.msecInt > 10000;
  Out.Ln;

  Out.String(info.name); Out.String(": ");
  Out.Real(count / i.msecInt * 1000, 0, 0);
  Out.String(" per second"); Out.Ln;
  Out.Ln;
END RunTest;

PROCEDURE RunAll;
VAR
  e : Driver.DriverEntry;
  d : Driver.Driver;
  info : Driver.Info;
  i : LONGINT;
BEGIN
  e := Driver.drivers;
  WHILE e # NIL DO
    d := e.driver;
    info := d.GetInfo();
    FOR i := 0 TO LEN(info^)-1 DO
       RunTest(d, i, info[i]); 
    END;
    e := e.next;
  END;
END RunAll;

PROCEDURE ParseOptions;
VAR
  rd : TextRider.Reader;
  line : ARRAY 256 OF CHAR;
BEGIN
  Out.LongInt(ProgramArgs.args.ArgNumber(), 0); Out.Ln;
  rd := TextRider.ConnectReader(ProgramArgs.args);
  rd.ReadLine(line);
  LOOP
    rd.ReadLine(line);
    IF rd.res # TextRider.done THEN
      EXIT
    END;
    Out.String(line);
  END;
  IF rd.res.code # Channel.readAfterEnd THEN
    rd.res.GetText(line);
    Err.String(line);
  END;
END ParseOptions;

PROCEDURE ParseOptions2;
VAR
  rd : TextRider.Reader;
  line : ARRAY 256 OF CHAR;
BEGIN
  Out.String("Arg count = ");
  Out.LongInt(ProgramArgs.args.ArgNumber(), 0); 
  Out.Ln;

  rd := TextRider.ConnectReader(ProgramArgs.args);
  LOOP
    rd.ReadLine(line);
    IF rd.res # TextRider.done THEN
      EXIT
    END;
    Out.String(line); Out.Ln;
  END;
  IF rd.res.code # Channel.readAfterEnd THEN
    rd.res.GetText(line);
    Out.String(line);
  END;
END ParseOptions2;

BEGIN
  ParseOptions2();
END Test.

