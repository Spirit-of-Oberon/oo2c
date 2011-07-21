MODULE Generic68;

IMPORT
  Object;

TYPE
  Bet(E: Object.Object) = POINTER TO BetDesc(* forget (E) *);
  BetDesc(E: Object.Object) = RECORD (Object.ObjectDesc)
  
  END;

PROCEDURE Test*();
  BEGIN
  END Test;

END Generic68.
