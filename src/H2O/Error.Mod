MODULE H2O:Error;

IMPORT 
  Err, H2O:Source, 
  Object, Object:Boxed, ADT:StringBuffer;

TYPE 
  Error* = POINTER TO ErrorDesc;
  ErrorDesc = RECORD
    in : Source.Input;
  END;

PROCEDURE Format(format : STRING; p1, p2, p3 : Object.Object) : STRING;
VAR
  b : StringBuffer.StringBuffer;
  ch : CHAR; i : LONGINT;
BEGIN
  b := StringBuffer.New("");
  i := 0;
  WHILE i < format.length DO
    ch := SHORT(SHORT(format.CharAt(i)));
    IF ch = "$" THEN
      INC(i);
      ch := SHORT(SHORT(format.CharAt(i)));
      CASE ORD(ch) - ORD('0') OF
      | 0: b.Append(p1);
      | 1: b.Append(p2);
      | 2: b.Append(p3);
      END;
    ELSE
      b.AppendLatin1Char(ch);
    END;
    INC(i);
  END;
  RETURN b.ToString();
END Format;

PROCEDURE (e : Error) MsgString* (msg : STRING; error : BOOLEAN);
BEGIN
  IF error THEN
    Err.String("Error: "); 
  ELSE
    Err.String("Warning: ");
  END;
  Err.Object(msg);
  Err.Ln;
  Err.Flush;
  e.in.ShowContext();
  IF error THEN HALT(0) END;
END MsgString;

PROCEDURE (e : Error) Error*(msg : STRING);
BEGIN
  e.MsgString(msg, TRUE);
END Error;

PROCEDURE (e : Error) ErrorParam* (msg : STRING ; p1, p2, p3 : Object.Object);
BEGIN
  e.MsgString(Format(msg, p1, p2, p3), TRUE);
END ErrorParam;

PROCEDURE (e : Error) MsgParam* (msg : STRING; p1, p2, p3 : Object.Object; error : BOOLEAN);
BEGIN
  e.MsgString(Format(msg, p1, p2, p3), error);
END MsgParam;

PROCEDURE (e : Error) UnexpectedCharacter* (ch : CHAR);
BEGIN
  e.ErrorParam("Unexpected character '$0'",
               NEW(Boxed.String, Object.NewLatin1Char(ch)),NIL,NIL);
END UnexpectedCharacter;

PROCEDURE (e : Error) ExpectedToken* (expected, found : Object.Object);
BEGIN
  e.ErrorParam("Expected token $0 but found token $1",expected,found,NIL);
END ExpectedToken;

PROCEDURE (e : Error) UnexpectedToken* (found : Object.Object);
BEGIN
  e.ErrorParam("Unexpected token $0",found,NIL,NIL);
END UnexpectedToken;

PROCEDURE (e : Error) ExpectedIdentifier* (found : Object.Object);
BEGIN
  e.ErrorParam("Expected Identifier but found token $0",found,NIL,NIL);
END ExpectedIdentifier;

PROCEDURE New* (in : Source.Input) : Error;
VAR err : Error;
BEGIN
  NEW(err);
  err.in := in;
  RETURN err;
END New;

END H2O:Error.
