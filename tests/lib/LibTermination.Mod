MODULE LibTermination;

IMPORT
  Out := Out0, Termination;

PROCEDURE Write ();
  BEGIN
    Out.String ("exiting..."); Out.Ln;
  END Write;

PROCEDURE DontWrite ();
  BEGIN
    Out.String ("DontWrite should not be called..."); Out.Ln;
  END DontWrite;

PROCEDURE Test* ();
  BEGIN
    Termination.RegisterProc (DontWrite);
    Termination.RegisterProc (Write);
    Termination.UnregisterProc (DontWrite);
  END Test;

END LibTermination.
