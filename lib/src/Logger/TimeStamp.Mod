MODULE Logger:TimeStamp [FOREIGN "C"; LINK FILE "TimeStamp.c" END];
(**Private helper class of module @omodule{*Logger}.  *)

PROCEDURE GmtNow*(VAR str: ARRAY OF CHAR; template: ARRAY OF CHAR);
PROCEDURE LocalNow*(VAR str: ARRAY OF CHAR; template: ARRAY OF CHAR);

END Logger:TimeStamp.
