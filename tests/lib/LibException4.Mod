MODULE LibException4;

IMPORT
  Out:=Out0, Exception;

PROCEDURE Test*() RAISES Exception.Exception;
  VAR
    e: Exception.Exception;
  BEGIN
    NEW(e);
    e.INIT("Some exception");
    Exception.Raise(e);
  END Test;

END LibException4.
