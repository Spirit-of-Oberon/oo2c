MODULE Generic76;

TYPE
  Alp = POINTER TO AlpDesc;
  AlpDesc = RECORD [ABSTRACT]
  END;

PROCEDURE (self: Alp) [ABSTRACT] INIT*(); END INIT;

END Generic76.
