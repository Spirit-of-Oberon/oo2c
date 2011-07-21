MODULE T5;

PROCEDURE f*(a, b: LONGINT): LONGINT;
  VAR
    h: LONGINT;
  BEGIN
    IF (b > a) THEN
      h := a; a := b; b := h;
    END;
    RETURN a-b;
  END f;

END T5.
