MODULE And1;

IMPORT Out := Out0;

PROCEDURE P (c: CHAR; x: BOOLEAN): BOOLEAN;
  BEGIN
    Out.Char (c); RETURN x;
  END P;

PROCEDURE Test* ();
  BEGIN
    Out.String ("FALSE & FALSE: ");
    Out.Bool (P("a", FALSE) & P("b", FALSE));
    Out.Ln;
    
    Out.String ("FALSE & TRUE : ");
    Out.Bool (P("a", FALSE) & P("b", TRUE));
    Out.Ln;
    
    Out.String ("TRUE & FALSE : ");
    Out.Bool (P("a", TRUE) & P("b", FALSE));
    Out.Ln;
    
    Out.String ("TRUE & TRUE  : ");
    Out.Bool (P("a", TRUE) & P("b", TRUE));
    Out.Ln;
  END Test;

END And1.
