(*	$Id$	*)
MODULE IntConv;
(*
    IntConv -  Low-level integer/string conversions.       
    Copyright (C) 1995 Michael Griebling
    Copyright (C) 2000 Michael van Acken
 
    This module is free software; you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as 
    published by the Free Software Foundation; either version 2 of the
    License, or (at your option) any later version.
 
    This module is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.
 
    You should have received a copy of the GNU Lesser General Public
    License along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

*)
 
IMPORT
  Char := CharClass, Str := Strings, Conv := ConvTypes;
 
TYPE
  ConvResults* = Conv.ConvResults;
  (**One of @oconst{strAllRight}, @oconst{strOutOfRange},
     @oconst{strWrongFormat}, or @oconst{strEmpty}.  *)

CONST
  strAllRight*=Conv.strAllRight;
  (**The string format is correct for the corresponding conversion.  *)
  strOutOfRange*=Conv.strOutOfRange;
  (**The string is well-formed but the value cannot be represented.  *)
  strWrongFormat*=Conv.strWrongFormat;
  (**The string is in the wrong format for the conversion.  *)
  strEmpty*=Conv.strEmpty;
  (**The given string is empty.  *)


VAR
  W, S, SI: Conv.ScanState;

(* internal state machine procedures *)

PROCEDURE WState(inputCh: CHAR; VAR chClass: Conv.ScanClass; VAR nextState: Conv.ScanState);
BEGIN
  IF Char.IsNumeric(inputCh) THEN chClass:=Conv.valid; nextState:=W
  ELSE chClass:=Conv.terminator; nextState:=NIL
  END
END WState;
  
 
PROCEDURE SState(inputCh: CHAR; VAR chClass: Conv.ScanClass; VAR nextState: Conv.ScanState);
BEGIN
  IF Char.IsNumeric(inputCh) THEN chClass:=Conv.valid; nextState:=W 
  ELSE chClass:=Conv.invalid; nextState:=S
  END
END SState;

  
PROCEDURE ScanInt*(inputCh: CHAR; VAR chClass: Conv.ScanClass; VAR nextState: Conv.ScanState);
 (**Represents the start state of a finite state scanner for signed whole
    numbers---assigns class of @oparam{inputCh} to @oparam{chClass} and a
    procedure representing the next state to @oparam{nextState}.

    The call of @samp{ScanInt(inputCh,chClass,nextState)} shall assign values
    to @oparam{chClass} and @oparam{nextState} depending upon the value of
    @oparam{inputCh} as shown in the following table.

    @example
    Procedure       inputCh         chClass         nextState (a procedure
                                                    with behaviour of)
    ---------       ---------       --------        ---------
    ScanInt         space           padding         ScanInt
                    sign            valid           SState
                    decimal digit   valid           WState
                    other           invalid         ScanInt
    SState          decimal digit   valid           WState
                    other           invalid         SState
    WState          decimal digit   valid           WState
                    other           terminator      --
    @end example

    NOTE 1 -- The procedure @oproc{ScanInt} corresponds to the start state of a
    finite state machine to scan for a character sequence that forms a signed
    whole number.  It may be used to control the actions of a finite state
    interpreter.  As long as the value of @oparam{chClass} is other than
    @oconst{Conv.terminator} or @oconst{Conv.invalid}, the
    interpreter should call the procedure whose value is assigned to
    @oparam{nextState} by the previous call, supplying the next character from
    the sequence to be scanned.  It may be appropriate for the interpreter to
    ignore characters classified as @oconst{Conv.invalid}, and proceed
    with the scan.  This would be the case, for example, with interactive
    input, if only valid characters are being echoed in order to give
    interactive users an immediate indication of badly-formed data.  If the
    character sequence end before one is classified as a terminator, the
    string-terminator character should be supplied as input to the finite state
    scanner.  If the preceeding character sequence formed a complete number,
    the string-terminator will be classified as @oconst{Conv.terminator},
    otherwise it will be classified as @oconst{Conv.invalid}.  *)
BEGIN
  IF Char.IsWhiteSpace(inputCh) THEN chClass:=Conv.padding; nextState:=SI
  ELSIF (inputCh="+") OR (inputCh="-") THEN chClass:=Conv.valid; nextState:=S
  ELSIF Char.IsNumeric(inputCh) THEN chClass:=Conv.valid; nextState:=W
  ELSE chClass:=Conv.invalid; nextState:=SI
  END
END ScanInt;
 
 
PROCEDURE FormatInt*(str: ARRAY OF CHAR): ConvResults;
(**Returns the format of the string value for conversion to LONGINT.  *)
VAR
  ch: CHAR;
  int: LONGINT;
  len, index, digit: INTEGER;
  state: Conv.ScanState;
  positive: BOOLEAN;
  prev, class: Conv.ScanClass;
BEGIN
  len:=Str.Length(str); index:=0;
  class:=Conv.padding; prev:=class;
  state:=SI; int:=0; positive:=TRUE;
  LOOP
    ch:=str[index];
    state.p(ch, class, state);
    CASE class OF
    | Conv.padding: (* nothing to do *)
    | Conv.valid:
        IF ch="-" THEN positive:=FALSE
        ELSIF ch="+" THEN positive:=TRUE
        ELSE (* must be a digit *)
          digit:=ORD(ch)-ORD("0");
          IF positive THEN
            IF int>(MAX(LONGINT)-digit) DIV 10 THEN RETURN strOutOfRange END;
            int:=int*10+digit
          ELSE
            IF int>(MIN(LONGINT)+digit) DIV 10 THEN
              int:=int*10-digit
            ELSIF (int < (MIN(LONGINT)+digit) DIV 10) OR
                  ((int = (MIN(LONGINT)+digit) DIV 10) &
                    ((MIN(LONGINT)+digit) MOD 10 # 0)) THEN
              RETURN strOutOfRange
            ELSE
              int:=int*10-digit
            END
          END
        END
      
    | Conv.invalid:
      IF (prev = Conv.padding) THEN
        RETURN strEmpty;
      ELSE
        RETURN strWrongFormat;
      END;
      
    | Conv.terminator:
      IF (ch = 0X) THEN
        RETURN strAllRight;
      ELSE
        RETURN strWrongFormat;
      END;
    END;
    prev:=class; INC(index)
  END;
END FormatInt;
 
 
PROCEDURE ValueInt*(str: ARRAY OF CHAR): LONGINT;
(**Returns the value corresponding to the signed whole number string value 
   @oparam{str} if @oparam{str} is well-formed.  Otherwise, result is
   undefined.  *)
VAR
  ch: CHAR;
  len, index, digit: INTEGER;
  int: LONGINT;  
  state: Conv.ScanState;
  positive: BOOLEAN;
  class: Conv.ScanClass;  
BEGIN
  IF FormatInt(str)=strAllRight THEN
    len:=Str.Length(str); index:=0;
    state:=SI; int:=0; positive:=TRUE;
    FOR index:=0 TO len-1 DO
      ch:=str[index];
      state.p(ch, class, state);
      IF class=Conv.valid THEN
        IF ch="-" THEN positive:=FALSE
        ELSIF ch="+" THEN positive:=TRUE
        ELSE (* must be a digit *)
          digit:=ORD(ch)-ORD("0");
          IF positive THEN int:=int*10+digit
          ELSE int:=int*10-digit
          END
        END
      END
    END;
    RETURN int
  ELSE RETURN 0 (* raise exception here *)
  END
END ValueInt;


PROCEDURE LengthInt*(int: LONGINT): INTEGER;
(**Returns the number of characters in the string representation of
   @oparam{int}.  This value corresponds to the capacity of an array @samp{str}
   which is of the minimum capacity needed to avoid truncation of the result in
   the call @samp{IntStr.IntToStr(int,str)}.  *)
VAR
  cnt: INTEGER;
BEGIN
  IF int=MIN(LONGINT) THEN int:=-(int+1); cnt:=1 (* argh!! *)
  ELSIF int<=0 THEN int:=-int; cnt:=1 
  ELSE cnt:=0 
  END;
  WHILE int>0 DO INC(cnt); int:=int DIV 10 END;
  RETURN cnt
END LengthInt; 

BEGIN
  (* kludge necessary because of recursive procedure declaration *)
  NEW(S); NEW(W); NEW(SI);  
  S.p:=SState; W.p:=WState; SI.p:=ScanInt
END IntConv.
