MODULE Or1;

IMPORT Out := Out0;

PROCEDURE P (c: CHAR; x: BOOLEAN): BOOLEAN;
  BEGIN
    Out.Char (c); RETURN x;
  END P;

PROCEDURE Test* ();
  BEGIN
    Out.String ("FALSE OR FALSE: ");
    Out.Bool (P("a", FALSE) OR P("b", FALSE));
    Out.Ln;
    
    Out.String ("FALSE OR TRUE : ");
    Out.Bool (P("a", FALSE) OR P("b", TRUE));
    Out.Ln;
    
    Out.String ("TRUE OR FALSE : ");
    Out.Bool (P("a", TRUE) OR P("b", FALSE));
    Out.Ln;
    
    Out.String ("TRUE OR TRUE  : ");
    Out.Bool (P("a", TRUE) OR P("b", TRUE));
    Out.Ln;
  END Test;

END Or1.
