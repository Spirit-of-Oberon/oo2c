MODULE ConstFold12;

IMPORT
  Out := Out0;

CONST
  andFF = FALSE & FALSE;
  andTF = TRUE & FALSE;
  andFT = FALSE & TRUE;
  andTT = TRUE & TRUE;

  orFF = FALSE OR FALSE;
  orTF = TRUE OR FALSE;
  orFT = FALSE OR TRUE;
  orTT = TRUE OR TRUE;

  notT = ~TRUE;
  notF = ~FALSE; 

PROCEDURE Test*;
BEGIN
  Out.Bool(andFF); Out.Ln;
  Out.Bool(andTF); Out.Ln;
  Out.Bool(andFT); Out.Ln;
  Out.Bool(andTT); Out.Ln;

  Out.Bool(orFF); Out.Ln;
  Out.Bool(orTF); Out.Ln;
  Out.Bool(orFT); Out.Ln;
  Out.Bool(orTT); Out.Ln;

  Out.Bool(notT); Out.Ln;
  Out.Bool(notF); Out.Ln; 
END Test;

END ConstFold12.
