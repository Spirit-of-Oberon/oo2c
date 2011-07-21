(*  
    H2O Module Scanner: Performs lexical analysis. Tokenises input.

    Copyright (C) 1998-2002  Stewart Greenhill

    This file is part of OOC.

    OOC is free software; you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    OOC is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
    License for more details.

    You should have received a copy of the GNU General Public License
    along with OOC. If not, write to the Free Software Foundation, 59
    Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*)

MODULE H2O:Scanner [OOC_EXTENSIONS];

IMPORT
  Err, CharClass, TextRider,
  Object, ADT:StringBuffer,
  H2O:Source, H2O:Error;

CONST
  optTestValid* = 1;
  optReturnEndLine* = 2;
  optComment* = 3;
  optDontReadAhead* = 4;
  optReturnWhiteSpace* = 5;
  optDontExpand* = 6;

  eol = 0AX;
  eof = 04X;

  (* 000: semantic categories *)

  ident*=0; 
  number*=1;
  string*=2;
  endLine* = 4;
  endFile* = 5;
  comment*=6;
  parameter* = 7;
  whiteSpace* = 8;

  (* 100: punctuation *)

  comma*=100;
  lbracket*=101;
  rbracket*=102;
  lbrace*=103;
  rbrace*=104;
  lsqbracket*=105;
  rsqbracket*=106;
  colon*=107; 
  semicolon*=108;
  period*=109;
  condIf*=110;
  dotdotdot* = 111;
  hash* = 112;

  (* 200: arithmetic operators *)

  add*=200;
  sub*=201;
  mul*=202;
  div*=203;
  mod*=204;
  lsh*=205;
  rsh*=206;
  and*=207;
  or*=208;
  not*=209;

  (* 300: assignment operators *)

  assign* =300; 
  addEq*=301;
  subEq*=302;
  mulEq*=303;
  divEq*=304;
  modEq*=305;
  lshEq*=306;
  rshEq*=307;
  bitAndEq*=308;
  bitOrEq*=309;
  xorEq*=310;

  (* 400: relational operators *)

  eq*=400;
  gt*=401;
  lt*=402;
  geq*=403;
  leq*=404;
  notEq*=405; 
 
  (* 600: bitwise operators *)

  bitAnd*=600;
  bitOr*=601;
  bitNot*=602;
  xor*=603;

TYPE
  Token* = POINTER TO TokenDesc;
  TokenDesc* = RECORD (Object.ObjectDesc)
    name- : STRING;
    sym- : INTEGER;
    len- : INTEGER;
    base- : INTEGER;
    value- : LONGINT;
  END;
 
TYPE
  KeyWord* = POINTER TO KeyWordDesc;
  KeyWordDesc* = RECORD
    next : KeyWord;
    name : STRING;
    value : INTEGER;
  END;

TYPE
  Interpreter* = POINTER TO InterpreterDesc;
  InterpreterDesc* = RECORD [ABSTRACT]
  END;

TYPE
  TokenSource* = POINTER TO TokenSourceDesc;
  TokenSourceDesc* = RECORD [ABSTRACT]
  END;

  Scanner* = POINTER TO ScannerDesc;
  ScannerDesc* = RECORD (TokenSourceDesc)
    in- : Source.Input;         (* stack of input sources *)
    err- : Error.Error;
    ch- : CHAR;                  (* current character *)
    buffer- : StringBuffer.StringBuffer;
    (*valid : BOOLEAN;		(* FIXME! *)*)
  END;

PROCEDURE (s : TokenSource) [ABSTRACT] GetToken* (token : Token; options : SET);
END GetToken;

PROCEDURE (t : Interpreter) [ABSTRACT] Evaluate* (token : Token; options : SET; VAR result : LONGINT);
END Evaluate;

PROCEDURE CheckKeyWord* (keywords : KeyWord; token : Token);
VAR k : KeyWord;
BEGIN
  k := keywords;
  WHILE k # NIL DO
    IF k.name.Equals(token.name) THEN
      token.sym := k.value; RETURN;
    ELSE
      k := k.next;
    END;
  END;
END CheckKeyWord;

PROCEDURE AddKeyWord* (VAR keywords : KeyWord; a : STRING; value : INTEGER);
VAR k : KeyWord;
BEGIN
  NEW(k);
  k.name := a;
  k.value := value;
  k.next := keywords;
  keywords := k;
END AddKeyWord;

PROCEDURE (s : Scanner) GetChar*;
BEGIN
  s.in.ReadChar(s.ch);
END GetChar;

PROCEDURE (s : Scanner) GetToken* (token : Token; options : SET);
VAR
  ch : CHAR;

  PROCEDURE StartToken;
  BEGIN
    token.name := NIL;
    s.buffer.Delete(0,s.buffer.length);
  END StartToken;

  PROCEDURE EndToken;
  BEGIN
    token.name := s.buffer.ToString();
  END EndToken;

  PROCEDURE NextChar;
  BEGIN
    s.in.ReadChar(ch);
    s.ch := ch;
  END NextChar;

  PROCEDURE AcceptChar;
  BEGIN
    s.buffer.AppendLatin1Char(ch);
    NextChar;
  END AcceptChar;
 
  PROCEDURE Ident;
  BEGIN
    REPEAT
      AcceptChar;
    UNTIL ~( CharClass.IsLetter(ch) OR CharClass.IsNumeric(ch) OR (ch='_') );
    token.sym := ident;
  END Ident;
  
  PROCEDURE Comment;
  BEGIN
    token.sym := comment; token.value := 0;
    LOOP
      IF ch = '*' THEN
        NextChar;
        IF ch = '/' THEN
          NextChar; 
          RETURN
        ELSE
          s.buffer.AppendLatin1Char("*");
        END
      END;
      AcceptChar;
    END
  END Comment;
  
  PROCEDURE Comment2;
  BEGIN
    token.sym := comment; token.value := 1;
    WHILE ch # eol DO AcceptChar END;
  END Comment2;
  
  PROCEDURE Number;
  VAR
    digit : INTEGER;
  
    PROCEDURE Digit() : BOOLEAN;
    BEGIN
      IF (token.base = 16) THEN
        IF (ch >= 'A') & (ch <= 'F') THEN
          digit := 10 + ORD(ch) - ORD('A'); RETURN TRUE
        ELSIF (ch >= 'a') & (ch <= 'f') THEN
          digit := 10 + ORD(ch) - ORD('a'); RETURN TRUE
        END
      END;
      digit := ORD(ch) - ORD('0');
      RETURN (digit >= 0) & (digit < token.base);
    END Digit;
  
  BEGIN
    token.value := 0;
    IF ch = '0' THEN
      AcceptChar;
      IF (ch = 'x') OR (ch = 'X') THEN
        token.base := 16;
        AcceptChar;
      ELSE
        token.base := 8;
      END;
    ELSE
      token.base := 10;
    END;
    WHILE Digit() DO
      token.value := token.base * token.value + digit;
      AcceptChar
    END;
    token.sym := number;
    IF (ch = "L") OR (ch = "l") OR (ch = "U") OR (ch = "u") THEN
      AcceptChar;
    END;
  END Number;
  
  PROCEDURE GetString(term : CHAR);
  BEGIN
    StartToken;
    token.sym := string;
    AcceptChar;
    WHILE ch # term DO
      AcceptChar;
    END;
    AcceptChar;
  END GetString;
  
  PROCEDURE AssignOp(noAssignOp, assignOp : INTEGER);
  BEGIN
    AcceptChar;
    IF ch = "=" THEN
      token.sym := assignOp; AcceptChar
    ELSE
      token.sym := noAssignOp;
    END;
  END AssignOp;

  PROCEDURE SymOp(op : INTEGER);
  BEGIN
    token.sym := op; 
    AcceptChar;
  END SymOp;

BEGIN
  ch := s.ch;
  IF optReturnWhiteSpace IN options THEN INCL(options, optReturnEndLine) END;

  REPEAT
    (* first, bypass any whitespace, returning tokens if we are looking for
    white-space tokens *)

    LOOP
      IF ch = eol THEN
        IF optReturnEndLine IN options THEN
          IF ~(optDontReadAhead IN options) THEN
            NextChar
          END;
          token.sym := endLine; token.name := NIL; RETURN
        ELSE
          NextChar
        END;
      ELSIF ch = eof THEN
        token.sym := endFile; token.name := NIL; RETURN
      ELSIF CharClass.IsWhiteSpace(ch) THEN
        IF optReturnWhiteSpace IN options THEN
          StartToken;
          WHILE CharClass.IsWhiteSpace(ch) & (ch # eof) & (ch # eol) DO
            AcceptChar
          END;
          EndToken; token.sym := whiteSpace; RETURN
        ELSE
          WHILE CharClass.IsWhiteSpace(ch) & (ch # eof) & (ch # eol) DO
            NextChar
          END
        END
      ELSIF (ch = "\") THEN
        NextChar;
        IF ch = eol THEN 
          NextChar 
        ELSE 
          s.err.UnexpectedCharacter(ch);
        END
      ELSE
        EXIT
      END
    END;

    StartToken;
    CASE ch OF
    | "a".."z", "A".."Z", "_": 
      Ident; 
    | "0".."9": 
      Number
    | '"': GetString('"')
    | "'": GetString("'")
    | "#": SymOp(hash);
    | ')': SymOp(rbracket);
    | '(': SymOp(lbracket);
    | ']': SymOp(rsqbracket);
    | '[': SymOp(lsqbracket);
    | '}': SymOp(rbrace);
    | '{': SymOp(lbrace);
    | '?': SymOp(condIf);
    | ':': SymOp(colon);
    | ';': SymOp(semicolon);
    | ',': SymOp(comma);
    | '.': SymOp(period);
      IF ch = '.' THEN
        AcceptChar;
        IF ch = '.' THEN
          SymOp(dotdotdot);
        ELSE
          s.err.Error("Invalid token: '..'");
        END;
      END;
    | '<': 
      AcceptChar; 
      IF ch = '=' THEN 
        SymOp(leq);
      ELSIF ch = '<' THEN
        AssignOp(lsh, lshEq);
      ELSE 
        token.sym := lt
      END
    | '>':
      AcceptChar; 
      IF ch = '=' THEN
        SymOp(geq);
      ELSIF ch = '>' THEN
        AssignOp(rsh, rshEq);
      ELSE 
        token.sym := gt 
      END
    | '+': AssignOp(add, addEq);
    | '-': AssignOp(sub, subEq);
    | '*': AssignOp(mul, mulEq);
    | '%': AssignOp(mod, modEq);
    | '=': AssignOp(assign, eq);
    | '!': AssignOp(not, notEq);
    | '/': 
      AcceptChar; 
      IF ch = '*' THEN
        NextChar; StartToken; Comment
      ELSIF ch = '/' THEN
        NextChar; StartToken; Comment2
      ELSIF ch = '=' THEN 
        SymOp(divEq);
      ELSE
        token.sym := div END
    | '&': 
      AcceptChar;
      IF ch = '=' THEN 
        SymOp(bitAndEq);
      ELSIF ch = '&' THEN
        SymOp(and);
      ELSE
        token.sym := bitAnd
      END
    | '|': 
      AcceptChar;
      IF ch = '=' THEN 
        SymOp(bitOrEq);
      ELSIF ch = '|' THEN
        SymOp(or);
      ELSE
        token.sym := bitOr
      END
    | '^': AssignOp(xor, xorEq);
    | '~': SymOp(bitNot);
    ELSE
      s.err.UnexpectedCharacter(ch);
    END;
  UNTIL (optComment IN options) OR (token.sym # comment);
  EndToken;
END GetToken;

PROCEDURE NewToken* (sym : INTEGER) : Token;
VAR t : Token;
BEGIN
  NEW(t);
  t.sym := sym;
  t.name := NIL;
  RETURN t;
END NewToken;

PROCEDURE NewTokenParameter* (value : LONGINT) : Token;
VAR t : Token;
BEGIN
  t := NewToken(parameter);
  t.value := value;
  RETURN t;
END NewTokenParameter;

PROCEDURE (t : Token) Copy* () : Token;
VAR new : Token;
BEGIN
  NEW(new);
  new^ := t^;
  RETURN new;
END Copy;

PROCEDURE (t : Token) ToString* () : STRING;
VAR b : StringBuffer.StringBuffer;
BEGIN
  b := StringBuffer.New("TOKEN(");
  b.AppendInt(t.sym);
  IF t.name # NIL THEN
    b.Append(",text='");
    b.Append(t.name);
    b.Append("'");
  END;
  IF (t.sym=number) OR (t.sym=parameter) THEN
    b.Append(",value=");
    b.AppendInt(t.value);
  END;
  b.Append(")");
  RETURN b.ToString();
END ToString;

PROCEDURE (t : Token) Write* (wr : TextRider.Writer);
BEGIN
  wr.WriteObject(t);
END Write;

PROCEDURE (t : Token) Text* (wr : TextRider.Writer);
BEGIN
  CASE t.sym OF
  | endLine:
    wr.WriteLn;
  | endFile:
  | comment:
    IF t.value = 0 THEN
      wr.WriteString("/*");
      wr.WriteObject(t.name);
      wr.WriteString("*/");
    ELSE
      wr.WriteString("//");
      wr.WriteObject(t.name);
    END;
  ELSE
    IF t.name # NIL THEN
      wr.WriteObject(t.name);
    ELSE
      t.Write(Err.writer); HALT(0);
    END;
  END;
END Text;

PROCEDURE New* (in : Source.Input; err : Error.Error) : Scanner;
VAR s : Scanner;
BEGIN
  NEW(s);
  s.in := in;
  s.err := err;
  s.buffer := StringBuffer.New("");
  s.in.ReadChar(s.ch);
  RETURN s;
END New;

END H2O:Scanner.
