MODULE LibLRealStrRealToFixed2;

IMPORT
  Out := Out0, LRealStr;

PROCEDURE Value (real: LONGREAL; sigFigs: INTEGER);
  VAR
    str: ARRAY 32 OF CHAR;
  BEGIN
    LRealStr.RealToFixed (real, sigFigs, str);
    Out.String (str);
    Out.Ln;
  END Value;

(*PROCEDURE ValueTrunc (i: LONGINT);
  VAR
    str: ARRAY 4 OF CHAR;
  BEGIN
    LRealStr.RealToFixed (i, str);
    Out.String (str);
    Out.Ln;
  END ValueTrunc;*)

PROCEDURE Test* ();
  BEGIN
    Value (3923009, -1);
    Value (3.923009, -1);
    Value (0.0003923009, -1);

    Out.Ln;
    Value (3923009, -2);
    Value (3.923009, -2);
    Value (0.0003923009, -2);

    Out.Ln;
    Value (3923009, -5);
    Value (3.923009, -5);
    Value (0.0003923009, -5);

    Out.Ln;
    Value (19960, -3);                   (* round up *)
    Value (19951, -3);                   (* round up *)
    Value (19950.0001, -3);              (* round up *)
    Value (19950, -3);                   (* round up (to even) *)
    Value (19850.0001D0, -3);            (* round up (E0 would round down) *)
    Value (19850, -3);                   (* round down (to even) *)
    Value (19800, -3);                   (* round down *)
    
    Out.Ln;
    Value (99960, -3);                   (* round up, overflow left *)
    Value (99960, -5);                   (* round up, overflow left *)
    Value (99960, -6);                   (* round up, overflow left *)
    Value (-99960, -3);                  (* round down, overflow left *)
    Value (-99960, -5);                  (* round down, overflow left *)
    Value (-99960, -6);                  (* round down, overflow left *)

    Out.Ln;
    Value (49960, -6);                   (* round down to zero *)
    Value (4, -2);                       (* round down to zero *)
    Value (0.4, -1);                     (* round down to zero *)
    Value (-0.4, -1);                    (* round up to zero *)
  END Test;

END LibLRealStrRealToFixed2.
