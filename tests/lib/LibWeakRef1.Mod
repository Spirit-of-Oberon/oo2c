MODULE LibWeakRef1;


IMPORT
  Out := Out0, RT0, WeakRef;

CONST
  count = 10;

TYPE
  T = POINTER TO TDesc;
  TDesc = RECORD (RT0.ObjectDesc)
	(* This type should be automatically finalized since it implements
       RT0:ObjectDesc.Finalize *)
    i : LONGINT;
  END;

VAR
  r : ARRAY count OF T;
  wr : ARRAY count OF WeakRef.WeakRef(T);

PROCEDURE (t : T) INIT(i : LONGINT);
BEGIN
  t.i := i;
END INIT;

PROCEDURE ActiveReferences() : SET;
(* Return the set of references that are still active (ie. not NIL) *)
VAR 
  i : LONGINT;
  result : SET;
BEGIN
  result := {};

  FOR i := 0 TO count-1 DO
    IF wr[i].Get() # NIL THEN
      INCL(result, i);
    END;
  END;
  RETURN result;
END ActiveReferences;

PROCEDURE Create;
VAR
  i : LONGINT;
BEGIN
  FOR i := 0 TO count-1 DO
    r[i] := NEW(T, i);
    wr[i] := NEW(WeakRef.WeakRef(T), r[i]);
  END;
END Create;

PROCEDURE Test*;
  VAR
    i : LONGINT;
  BEGIN
    (* create objects and references *)

    Create;

    (* GC, and see which are active. Should be all of them. *)

    RT0.CollectGarbage;

    Out.Set(ActiveReferences()); Out.Ln;

    FOR i := 0 TO count-1 DO
      r[i] := NIL;
    END;

    (* GC, and see which are active. Should be none of them. *)

    RT0.CollectGarbage;

    Out.Set(ActiveReferences()); Out.Ln;
  END Test;
  
END LibWeakRef1.
