MODULE Undef11;

PROCEDURE P();
  BEGIN
  END P;

PROCEDURE Proc*();
  BEGIN
    LOOP
      EXIT;
      P();
    END;
  END Proc;

END Undef11.
