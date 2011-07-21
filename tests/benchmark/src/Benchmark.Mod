MODULE Benchmark;

IMPORT 
  Channel, ProgramArgs, TextRider, Out, Err, Time, Strings,

  Driver, Category,

  MiscDriver,
  FFTDriver,
  SortDriver,
  ArrayDriver;

TYPE
  ScheduleEntry = POINTER TO ScheduleEntryDesc;
  ScheduleEntryDesc = RECORD
    id : LONGINT;
    driver : Driver.Driver;
    result : REAL;
    next : ScheduleEntry;
  END;

VAR
  schedule : ScheduleEntry;
  normalise : BOOLEAN;
  all : BOOLEAN;

CONST
  perfWidth = 6;
  resultWidth = 10;
  resultDigits = 1;

PROCEDURE NewEntry(driver : Driver.Driver; id : LONGINT) : ScheduleEntry;
VAR
  e : ScheduleEntry;
BEGIN
  NEW(e);
  e.next := NIL;
  e.driver := driver;
  e.id := id;
  RETURN e;
END NewEntry;

PROCEDURE AppendTest(driver : Driver.Driver; id : LONGINT);
(* Append a (driver,id) test to the current schedule *)
VAR s, e : ScheduleEntry;
BEGIN
  e := NewEntry(driver, id);
  IF schedule = NIL THEN
    schedule := e;
  ELSE
    s := schedule;
    WHILE s.next # NIL DO s := s.next; END;
    s.next := e;
  END;
END AppendTest;

PROCEDURE AppendCategory(c : Category.Category);
VAR
  e : Category.CategoryEntry;
BEGIN
  e := c.entries;
  WHILE e # NIL DO
    AppendTest(e.driver, e.id);
    e := e.next;
  END;
END AppendCategory;

PROCEDURE FindSchedule(driver : Driver.Driver; id : LONGINT) : ScheduleEntry;
(* Search the current schedule for the given (driver,id). If found, return the
schedule entry. *)
VAR
  s : ScheduleEntry;
BEGIN
  s := schedule;
  WHILE s # NIL DO
    IF (s.driver = driver) & (s.id = id) THEN
      RETURN s;
    END;
    s := s.next;
  END;
  RETURN NIL;
END FindSchedule;

PROCEDURE RunTest (d : Driver.Driver; id : LONGINT; VAR info : Driver.InfoDesc) : REAL;
(* Execute a test with given driver and id. Return the number of iterations per second. *)
VAR
  t1, t2 : Time.TimeStamp;
  i : Time.Interval;
  j, count : LONGINT;
  result : REAL;
BEGIN
  count := 1;
  Err.String(info.name); 
  Err.String(": ");
  Err.Flush;
  REPEAT
    count := count * 2;
    Err.LongInt(count,0); Err.Char(" "); Err.Flush;
    Time.GetTime(t1);
    d.Exec(id, count);
    Time.GetTime(t2);
    t2.Delta(t1, i);
  UNTIL i.msecInt > 10000;
  Err.Ln;

  result := count / i.msecInt * 1000;

  Err.String(info.name); Err.String(": ");
  Err.RealFix(result, resultWidth, resultDigits);
  Err.String(" per second"); Err.Ln;
  Err.Ln;
  RETURN result;
END RunTest;

PROCEDURE ScheduleAll;
(* Schedule all available tests for execution. *)
VAR
  e : Driver.DriverEntry;
  info : Driver.Info;
  i : LONGINT;
BEGIN
  e := Driver.drivers;
  WHILE e # NIL DO
    info := e.driver.GetInfo();
    FOR i := 0 TO LEN(info^)-1 DO
      AppendTest(e.driver, i);
    END;
    e := e.next;
  END;
END ScheduleAll;

PROCEDURE RunSchedule;
(* Execute each test in the current schedule. Accumulate the result in the
schedule entry for output later. *)
VAR 
  s, e : ScheduleEntry;
  result : REAL;
  info : Driver.Info;
  refId : LONGINT;
BEGIN
  s := schedule;
  WHILE s # NIL DO
    info := s.driver.GetInfo();
    refId := info[s.id].reference;
    s.result := RunTest(s.driver, s.id, info[s.id]);
    (* If normalising, ensure that the reference test is scheduled. *)
    IF normalise & (refId >= 0) & (FindSchedule(s.driver, refId) = NIL) THEN
      e := NewEntry(s.driver, refId);
      e.next := s.next; s.next := e;
    END;
    s := s.next;
  END;
END RunSchedule;

PROCEDURE RepeatChar(ch : CHAR; width : LONGINT);
BEGIN
  WHILE width > 0 DO
    Out.Char(ch);
    DEC(width);
  END;
END RepeatChar;

PROCEDURE StringWidth(name : ARRAY OF CHAR; width : LONGINT);
(* Format a string with width @oparam{len}, padding with trailing spaces. *)
VAR 
  len, pos : LONGINT;
BEGIN
  pos := 0;
  len := Strings.Length(name);
  IF width >= 0 THEN
    width := width - len;
    Out.String(name); RepeatChar(" ", width);
  ELSE
    width := -width - len;
    RepeatChar(" ", width); Out.String(name);
  END;
END StringWidth;

PROCEDURE ShowResults;
(* Output a summary table with the results for each test. *)
VAR
  s : ScheduleEntry;
  info : Driver.Info;
  refId : LONGINT; entry : ScheduleEntry;

  PROCEDURE Divider;
  BEGIN
    RepeatChar("-", Driver.nameLength+resultWidth);
    IF normalise THEN
      Out.Char(" "); RepeatChar("-", perfWidth+1);
    END;
    Out.Ln;
  END Divider;

BEGIN
  s := schedule;
  StringWidth("Test", Driver.nameLength);
  StringWidth("tests/sec", -resultWidth);
  IF normalise THEN
    Out.String(" % optimal");
  END;
  Out.Ln;
  Divider;
  WHILE s # NIL DO
    info := s.driver.GetInfo();
    StringWidth(info[s.id].name, Driver.nameLength);
    Out.RealFix(s.result, resultWidth, resultDigits);
    IF normalise THEN
      refId := info[s.id].reference;
      entry := FindSchedule(s.driver, refId);
      IF entry # NIL THEN
        Out.String(" ");
        Out.RealFix(100.0 * s.result / entry.result, perfWidth, resultDigits);
        Out.String("%");
      END;
    END;
    Out.Ln;
    s := s.next;
  END;
  Divider;
END ShowResults;

PROCEDURE ShowTests;
(* Show a list of all available tests and their descriptions. *)
VAR
  d : Driver.DriverEntry;
  info : Driver.Info;
  i : LONGINT;
  reference : BOOLEAN;
BEGIN
  Out.String("Available benchmarks:"); Out.Ln;
  reference := FALSE;
  d := Driver.drivers;
  WHILE d # NIL DO
    info := d.driver.GetInfo();
    FOR i := 0 TO LEN(info^)-1 DO
      IF info[i].reference >= 0 THEN
        Out.Char(" ");
      ELSE
        Out.Char("*");
        reference := TRUE;
      END;
      StringWidth(info[i].name, 16);
      Out.String(info[i].desc); Out.Ln;
    END;
    d := d.next;
  END;
  IF reference THEN
    Out.String("--"); Out.Ln;
    Out.String("* indicates reference implementation"); Out.Ln;
  END;
END ShowTests;

PROCEDURE ShowCategories;
VAR 
  c : Category.Category;
  e : Category.CategoryEntry;
  info : Driver.Info;
BEGIN
  Out.String("Categories:"); Out.Ln;
  c := Category.categories;
  WHILE c # NIL DO
    Out.Char(' '); StringWidth(c.name, 16); 
    e := c.entries;
    WHILE e # NIL DO
      Out.Char(' ');
      info := e.driver.GetInfo();
      Out.String(info[e.id].name);
      e := e.next;
    END;
    Out.Ln;
    c := c.next;
  END;
END ShowCategories;

PROCEDURE ShowUsage;
BEGIN
  Out.String("Usage: Benchmark [--all|--normalise] <tests>"); Out.Ln;
  ShowTests();
  ShowCategories();
END ShowUsage;

PROCEDURE ParseOptions;
VAR
  rd : TextRider.Reader;
  line : ARRAY 256 OF CHAR;
  driver : Driver.Driver;
  id : LONGINT;
  c : Category.Category;
  errors : LONGINT;
BEGIN
  errors := 0;
  IF ProgramArgs.args.ArgNumber() = 0 THEN
    ShowUsage();
    HALT(1);
  ELSE
    rd := TextRider.ConnectReader(ProgramArgs.args);
    rd.ReadLine(line);
    LOOP
      rd.ReadLine(line);
      IF rd.res # TextRider.done THEN
        EXIT
      END;
  
      IF (line = "--normalise") THEN
        normalise := TRUE;
      ELSIF (line = "--all") THEN
        all := TRUE;
      ELSE
        IF Driver.FindTest(line, driver, id) THEN
          AppendTest(driver, id);
        ELSIF Category.FindCategory(line, c) THEN
          AppendCategory(c);
        ELSE
          Err.String("Test '"); Err.String(line); 
          Err.String("' unknown."); Err.Ln;
          INC(errors);
        END
      END
    END;
    IF rd.res.code # Channel.readAfterEnd THEN
      rd.res.GetText(line);
      Err.String(line);
    END;
    IF errors > 0 THEN
      ShowUsage();
      HALT(1);
    END;
  END;
END ParseOptions;

BEGIN
  schedule := NIL;
  normalise := FALSE;
  all := FALSE;
  ParseOptions;
  IF all THEN
    schedule := NIL; ScheduleAll();
  END;
  RunSchedule();
  ShowResults();
END Benchmark.

