MODULE Generic69;

IMPORT
  Out:=Out0,
  Object;

TYPE
  Bet(E: Object.Object) = POINTER TO BetDesc(E);
  BetDesc(E: Object.Object) = RECORD (Object.ObjectDesc)
  
  END;

  Gam(E: Object.Object) = POINTER TO GamDesc(E);
  GamDesc(E: Object.Object) = RECORD (BetDesc(E))

  END;

PROCEDURE (self: Bet(E)) Dummy*();
BEGIN
  Out.String("bet.dummy");
  Out.Ln;
END Dummy;

PROCEDURE (self: Gam(E)) Dummy*();
BEGIN
  Out.String("gam.dummy");
  Out.Ln;
END Dummy;

PROCEDURE Test*();
VAR
  b: Bet(Object.Object);
BEGIN
  b := NEW(Gam(Object.Object));
  Out.String("after new");
  Out.Ln;
  b.Dummy;
  Out.String("all right");
  Out.Ln;
END Test;

END Generic69.
