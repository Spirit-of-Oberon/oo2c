(* 	$Id$	 *)
MODULE OOC:OpTree:Operator;
(*  Symbolic names for operators in expressions.
    Copyright (C) 2000  Michael van Acken

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

IMPORT
  OOC:Scanner:Symbol;


TYPE
  Id* = SHORTINT;
  (**This type holds operator ids.  *)

CONST
  (**Operator identifications.  Use these symbolic values for type @otype{Id}.
     The operator tree generated from the abstract syntax tree classifies its
     nodes with @otype{Id} values.  *)
  and* = 0;                             (* &   logical "and" *)
  or* = 1;                              (* OR  logical "or" *)
  not* = 2;                             (* ~   negation or set complement *)
  
  mul* = 3;                             (* *   multiplation or intersection *)
  add* = 4;                             (* +   addition or union *)
  sub* = 5;                             (* -   subtraction or set difference *)
  div* = 7;                             (* DIV integer division *)
  mod* = 8;                             (* MOD integer modulo *)
  
  rdiv* = 6;                            (* /   real division or
                                               symmetrical set difference*)
  
  eql* = 9;                             (* =   equal *)
  neq* = 10;                            (* #   not equal*)
  lss* = 11;                            (* <   less than *)
  leq* = 12;                            (* <=  less or equal *)
  gtr* = 13;                            (* >   greater than *)
  geq* = 14;                            (* >=  greater or equal *)
  
  in* = 15;                             (* IN  set membership *)
  is* = 16;                             (* IS  type test *)
  guard* = 17;                          (*     type guard *)
  deref* = 18;                          (* ^   dereference or super call *)
  select* = 19;                         (* .   module or record selector *)
  index* = 20;                          (* []  index operator *)
  range* = 21;                          (* ..  range operator *)
  assign* = 22;                         (* :=  assignment operator *)
  
  addOnOperators = assign+1;
  (* if you want to tinker with the language, put additional operator ids here;
     do _not_ insert them into the operator ids above, because parts of the
     compiler use ranges of ids, like "(a<=id) & (id<=b)", for their tests *)

  illegal* = -1;
  
VAR
  representation-: ARRAY addOnOperators, 6 OF CHAR;
  (**Textual representation of the operator ids, as they appear in the source
     code.  If no unique representation exists, the name of the operation
     is given instead.  *)
  i: INTEGER;

PROCEDURE SymbolToOperator* (symId: Symbol.Id): Id;
  BEGIN
    CASE symId OF
    | Symbol.times: RETURN mul;
    | Symbol.slash: RETURN rdiv;
    | Symbol.div: RETURN div;
    | Symbol.mod: RETURN mod;
    | Symbol.and: RETURN and;
    | Symbol.plus: RETURN add;
    | Symbol.minus: RETURN sub;
    | Symbol.or: RETURN or;
    | Symbol.eql: RETURN eql;
    | Symbol.neq: RETURN neq;
    | Symbol.lss: RETURN lss;
    | Symbol.leq: RETURN leq;
    | Symbol.gtr: RETURN gtr;
    | Symbol.geq: RETURN geq;
    | Symbol.in: RETURN in;
    | Symbol.is: RETURN is;
    | Symbol.arrow: RETURN deref;
    | Symbol.period: RETURN select;
    | Symbol.upto: RETURN range;
    | Symbol.not: RETURN not;
    | Symbol.becomes: RETURN assign;
    END
  END SymbolToOperator;

BEGIN
  FOR i := 0 TO addOnOperators-1 DO
    representation[i] := ""
  END;
  
  representation[and] := "&";
  representation[or] := "OR";
  representation[not] := "~";
  representation[mul] := "*";
  representation[add] := "+";
  representation[sub] := "-";
  representation[rdiv] := "/";
  representation[div] := "DIV";
  representation[mod] := "MOD";
  representation[eql] := "=";
  representation[neq] := "#";
  representation[lss] := "<";
  representation[leq] := "<=";
  representation[gtr] := ">";
  representation[geq] := "<=";
  representation[in] := "IN";
  representation[is] := "IS";
  representation[guard] := "guard";
  representation[deref] := "^";
  representation[select] := ".";
  representation[range] := "..";
  representation[assign] := ":=";
END OOC:OpTree:Operator.
