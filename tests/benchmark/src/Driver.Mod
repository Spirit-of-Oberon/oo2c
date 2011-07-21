MODULE Driver [OOC_EXTENSIONS];

CONST
  nameLength* = 16;

TYPE
  Driver* = POINTER TO DriverDesc;
  DriverDesc* = RECORD [ABSTRACT]
    (**A driver is an interface to a batch of tests. Typically a driver does
    the following:
    - Maintains any data structures required for running tests (eg. input data
      arrays).
    - Implements a simple dispatch method (Exec) that handles differences
      between the implementation of tests.
    - Provides meta-data about what tests are provided (via GetInfo).
    - Provides "reference" tests in "C", allowing the performance of Oberon-2
      code to be compared with the "optimal" solution.  *)
    
  END;

  (* List nodes for list of registered drivers. *)
  DriverEntry* = POINTER TO DriverEntryDesc;
  DriverEntryDesc* = RECORD
    driver- : Driver;
    next- : DriverEntry;
  END;

  InfoDesc* = RECORD
    (** Index of the reference test for this test. *)
    reference* : LONGINT;

    (** Short name for this test. *)
    name* : ARRAY nameLength OF CHAR;

    (** Description of this test. *)
    desc* : ARRAY 128 OF CHAR;
  END;

  (* Information for each driver is an array of test descriptors. *)
  Info* = POINTER TO ARRAY OF InfoDesc;

VAR
  (** Linked list of registered test drivers. *)
  drivers- : DriverEntry;

PROCEDURE (d : Driver) [ABSTRACT] Exec* (testId : LONGINT; count : LONGINT);
(**Execute test @oparam{testId} for @oparam{count} iterations. *)
END Exec;

PROCEDURE (d : Driver) [ABSTRACT] GetInfo*() : Info;
(**Return an array of test descriptors for this driver. *)
END GetInfo;

PROCEDURE Register* (d : Driver);
(**Add driver @oparam{d} to the list of available drivers. *)
VAR e : DriverEntry;
BEGIN
  NEW(e);
  e.driver := d;
  e.next := drivers;
  drivers := e;
END Register;

PROCEDURE FindTest* (name : ARRAY OF CHAR; VAR driver : Driver; VAR id : LONGINT) : BOOLEAN;
(* Check if some driver supports a test with the given name. If so, set the
driver and test id and return TRUE. *)
VAR 
  d : DriverEntry;
  info : Info;
  i : LONGINT;
BEGIN
  d := drivers;
  WHILE d # NIL DO
    info := d.driver.GetInfo();
    FOR i := 0 TO LEN(info^)-1 DO
      IF info[i].name = name THEN
        driver := d.driver; id := i; RETURN TRUE;
      END
    END;
    d := d.next;
  END;
  RETURN FALSE
END FindTest;

BEGIN
  drivers := NIL;
END Driver.
