MODULE VTable5;

IMPORT 
  Out,
  VTable4, (* abstract interface *)
  VTable3; (* FOREIGN c++ implementation *)

TYPE
  TDesc = VTable4.TDesc;
  T = VTable4.T;

TYPE
  TImpl = POINTER TO TImplDesc;
  TImplDesc = RECORD [VTABLE] (TDesc)
  END;

PROCEDURE (t : TImpl) String* (str : ARRAY OF CHAR);
BEGIN
  Out.String(str); Out.Flush;
END String;

PROCEDURE (t : TImpl) Int* (i : LONGINT);
BEGIN
  Out.LongInt(i, 0); Out.Flush;
END Int;

PROCEDURE (t : TImpl) Ln*;
BEGIN
  Out.Ln; Out.Flush;
END Ln;

PROCEDURE (t : TImpl) Chain* (obj : T; i : LONGINT);
BEGIN
  Out.String("VTable5:T "); Out.LongInt(i, 0); Out.Ln; Out.Flush;
  IF i > 0 THEN
    obj.Chain(t, i-1);
  END;
END Chain;

PROCEDURE Test*;
VAR
  t : T;
  i : TImpl;

BEGIN
  (* create foreign VTABLE object *)
  t := VTable3.NewT();
  t.String("VTable3 "); t.Int(0); t.Ln;

  (* create Oberon-2 implementation of the same interface *)
  NEW(i);
  i.String("VTable5 ");i.Int(0); i.Ln;
  
  t.Chain(i, 8);
  i.Chain(t, 8);
END Test;

END VTable5.
