MODULE Generic70;

IMPORT
Out:=Out0;

TYPE
Alp = POINTER TO AlpDesc;
AlpDesc = RECORD

END;

Bet = POINTER TO BetDesc;
BetDesc = RECORD(AlpDesc)

END;

Gam = POINTER TO GamDesc;
GamDesc = RECORD

END;

PROCEDURE (self: Alp) INIT*(alpParam: LONGINT);
BEGIN
Out.String("alp.init ");
Out.Int(alpParam, 1);
Out.Ln;
END INIT;

PROCEDURE (self: Gam) UseBet;
VAR
b: Bet;
BEGIN
b := NEW(Bet, 1);
END UseBet;

PROCEDURE (self: Bet) INIT*(alpParam: LONGINT;
betParam: LONGINT);
BEGIN
Out.String("bet.init ");
Out.Int(alpParam, 1);
Out.String(" ");
Out.Int(betParam, 1);
Out.Ln;
END INIT;

PROCEDURE Test*;
VAR
g: Gam;
BEGIN
g := NEW(Gam);
g.UseBet;
END Test;

END Generic70.
