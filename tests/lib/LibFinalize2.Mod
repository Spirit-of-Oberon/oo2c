MODULE LibFinalize2;

IMPORT
  Out := Out0, Object, RT0;

TYPE
  T = POINTER TO TDesc;
  TDesc = RECORD 
    (* This type should not be finalised. It does not extend RT0:ObjectDesc. *)
    i : LONGINT;
  END;

VAR
  finalised : SET;

PROCEDURE (t : T) Finalize*;
BEGIN
  INCL(finalised, t.i);
END Finalize;

PROCEDURE Test*;
  VAR
    t : T;
    i : LONGINT;
  BEGIN
    finalised := {};

    FOR i := 0 TO 9 DO
      NEW(t); t.i := i;
    END;

    RT0.CollectGarbage;

    Out.Set(finalised); Out.Ln;
  END Test;
  
END LibFinalize2.
