MODULE LibFinalize1;

(* Test finalisation. A quirk: the GC seems to not free the last object
allocated, so we need to perform one extra allocation. Is this a bug? *)

IMPORT
  Out := Out0, RT0;

CONST
  count = 100;
  cycles = 1000;

TYPE
  T = POINTER TO TDesc;
  TDesc = RECORD (RT0.ObjectDesc)
	(* This type should be automatically finalized since it implements
       RT0:ObjectDesc.Finalize *)
    i : LONGINT;
  END;

  S = POINTER TO SDesc;
  SDesc = RECORD
  END;

VAR
  r : ARRAY count OF T;
  finaliseCount : ARRAY count OF INTEGER;

PROCEDURE (t : T) Finalize*;
BEGIN
  INC(finaliseCount[t.i]);
END Finalize;

PROCEDURE Allocate;
VAR i : LONGINT; t : T; 
BEGIN
  FOR i := 0 TO count-1 DO
    NEW(t); t.i := i;
    r[i] := t;
  END;
END Allocate;

PROCEDURE Test*;
  VAR i : LONGINT;
  BEGIN
    FOR i := 0 TO count-1 DO
      finaliseCount[i] := 0;
    END;

    Out.String("Begin"); Out.Ln;

    (* do <cycles+1> allocations, creating <cycles*count> free objects *)

    FOR i := 0 TO cycles DO
      Allocate;
      RT0.CollectGarbage;
    END;

    Out.String("End"); Out.Ln;

    (* check for missed finalisation *)
    FOR i := 0 TO count-1 DO
      IF finaliseCount[i] # cycles THEN
        Out.Int(i, 0); Out.Char(':'); Out.Int(finaliseCount[i], 0); Out.Ln;
      END;
    END;
  END Test;
  
END LibFinalize1.
