MODULE Cse2;

IMPORT Out := Out0;
  
TYPE
  P* = POINTER TO PDesc;
  PDesc = RECORD
    x: INTEGER;
  END;

<*DerefCheck:=FALSE*>
PROCEDURE F (p: P);
  BEGIN
    IF (p # NIL) & (p.x # 0) THEN
      Out.Int (p.x, 0); Out.Ln;
    END;
  END F;

PROCEDURE Test* ();
  BEGIN
    F(NIL);
  END Test;

END Cse2.
