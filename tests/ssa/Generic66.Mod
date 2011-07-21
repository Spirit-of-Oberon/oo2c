MODULE Generic66;

IMPORT
  Object;

TYPE

  Bet(E: Object.Object) = POINTER TO BetDesc(E);
  BetDesc(E: Object.Object) = RECORD (Object.ObjectDesc)
  
  END;

PROCEDURE DoTest();
VAR
  rl: Bet(Object.Object);
BEGIN
  rl := NEW(Bet(Karamba));
END DoTest;

BEGIN
  DoTest;
END Generic66.
