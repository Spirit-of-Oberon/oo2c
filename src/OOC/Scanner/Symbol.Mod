(* 	$Id$	 *)
MODULE OOC:Scanner:Symbol;
(*  Symbolic names for symbols known to the scanner.
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

TYPE
  Id* = SHORTINT;
  (**This type holds symbol ids.  *)

CONST
  (**Symbol identifications.  Use these symbolic values for type @otype{Id}.  
     The scanner @omodule{*OOC:Scanner} classifies its input stream into a 
     sequence of @otype{Id} values.  *)
  times*=1; slash*=2; div*=3; mod*=4;
  and*=5; plus*=6; minus*=7; or*=8; eql*=9;
  neq*=10; lss*=11; leq*=12; gtr*=13; geq*=14;
  in*=15; is*=16; arrow*=17; period*=18; comma*=19;
  colon*=20; upto*=21; rParen*=22; rBrak*=23; rBrace*=24;
  of*=25; then*=26; do*=27; to*=28; by*=29; lParen*=30;
  lBrak*=31; lBrace*=32; not*=33; becomes*=34;
  number10*=35; number16*=36; number16X*=37;
  numberExpE*=38; numberExpD*=39;
  nil*=40; stringSingle*=41; stringDouble*=42; 
  ident*=43; semicolon*=44;
  bar*=45; end*=46; else*=47; elsif*=48; until*=49;
  if*=50; case*=51; while*=52; repeat*=53; loop*=54;
  for*=55; with*=56; exit*=57; return*=58;
  array*=59; record*=60; pointer*=61; begin*=62; const*=63;
  type*=64; var*=65; procedure*=66;
  import*=67; module*=68; endOfFile*=69;
  
  (* nonstandard symbols & symbols normally mapped to whitespace; use the
     predicate @oproc{IsWhitespace} to test for whitespace *)
  invalid*=70; pragmaStart*=71; pragmaEnd*=72;
  threeDots*=73; comment*=74; docComment* = 75; pragma*=76; whitespace*=77;
  
  addOnSymbols=78;
  (* if you want to tinker with the language, put additional symbol ids here;
     do _not_ insert them into the symbol ids above, because the parser 
     uses ranges of ids, like "(a<=id) & (id<=b)", for its tests *)

VAR
  name-: ARRAY addOnSymbols, 13 OF CHAR;
  (**Symbolic names for the symbol ids listed above.  *)
  representation-: ARRAY addOnSymbols, 10 OF CHAR;
  (**Textual representation of the symbol ids, as they appear in the text.
     If there is no constant representation for an id, like for identifiers
     or comments, the corresponding array element is the empty string.  *)
  i: INTEGER;

PROCEDURE IsKeyword* (id: Id): BOOLEAN;
(**Returns @code{TRUE} iff @oparam{id} is a keyword.  *)
  BEGIN
    RETURN (id = div) OR (id = mod) OR (id = in) OR (id = is) OR (id = nil) OR
           (id = or) OR (of <= id) & (id <= by) OR (end <= id) & (id <= module)
  END IsKeyword;

PROCEDURE IsWhitespace* (id: Id): BOOLEAN;
(**Returns @code{TRUE} iff @oparam{id} is a whitespace symbol.  *)
  BEGIN
    RETURN (id >= comment) & (id < addOnSymbols)
  END IsWhitespace;

BEGIN
  FOR i := 0 TO addOnSymbols-1 DO
    name[i] := ""; representation[i] := ""
  END;
  name[times] := "times"; representation[times] := "*";
  name[slash] := "slash"; representation[slash] := "/";
  name[div] := "div"; representation[div] := "DIV";
  name[mod] := "mod"; representation[mod] := "MOD";
  name[and] := "and"; representation[and] := "&";
  name[plus] := "plus"; representation[plus] := "+";
  name[minus] := "minus"; representation[minus] := "-";
  name[or] := "or"; representation[or] := "OR";
  name[eql] := "eql"; representation[eql] := "=";
  name[neq] := "neq"; representation[neq] := "#";
  name[lss] := "lss"; representation[lss] := "<";
  name[leq] := "leq"; representation[leq] := "<=";
  name[gtr] := "gtr"; representation[gtr] := ">";
  name[geq] := "geq"; representation[geq] := ">=";
  name[in] := "in"; representation[in] := "IN";
  name[is] := "is"; representation[is] := "IS";
  name[arrow] := "arrow"; representation[arrow] := "^";
  name[period] := "period"; representation[period] := ".";
  name[comma] := "comma"; representation[comma] := ",";
  name[colon] := "colon"; representation[colon] := ":";
  name[upto] := "upto"; representation[upto] := "..";
  name[rParen] := "rParen"; representation[rParen] := ")";
  name[rBrak] := "rBrak"; representation[rBrak] := "]";
  name[rBrace] := "rBrace"; representation[rBrace] := "}";
  name[of] := "of"; representation[of] := "OF";
  name[then] := "then"; representation[then] := "THEN";
  name[do] := "do"; representation[do] := "DO";
  name[to] := "to"; representation[to] := "TO";
  name[by] := "by"; representation[by] := "BY";
  name[lParen] := "lParen"; representation[lParen] := "(";
  name[lBrak] := "lBrak"; representation[lBrak] := "[";
  name[lBrace] := "lBrace"; representation[lBrace] := "{";
  name[not] := "not"; representation[not] := "~";
  name[becomes] := "becomes"; representation[becomes] := ":=";
  name[number10] := "number10";
  name[number16] := "number16";
  name[number16X] := "number16X";
  name[numberExpE] := "numberExpE";
  name[numberExpD] := "numberExpD";
  name[nil] := "nil"; representation[nil] := "NIL";
  name[stringSingle] := "stringSingle";
  name[stringDouble] := "stringDouble";
  name[ident] := "ident";
  name[semicolon] := "semicolon"; representation[semicolon] := ";";
  name[bar] := "bar"; representation[bar] := "|";
  name[end] := "end"; representation[end] := "END";
  name[else] := "else"; representation[else] := "ELSE";
  name[elsif] := "elsif"; representation[elsif] := "ELSIF";
  name[until] := "until"; representation[until] := "UNTIL";
  name[if] := "if"; representation[if] := "IF";
  name[case] := "case"; representation[case] := "CASE";
  name[while] := "while"; representation[while] := "WHILE";
  name[repeat] := "repeat"; representation[repeat] := "REPEAT";
  name[loop] := "loop"; representation[loop] := "LOOP";
  name[for] := "for"; representation[for] := "FOR";
  name[with] := "with"; representation[with] := "WITH";
  name[exit] := "exit"; representation[exit] := "EXIT";
  name[return] := "return"; representation[return] := "RETURN";
  name[array] := "array"; representation[array] := "ARRAY";
  name[record] := "record"; representation[record] := "RECORD";
  name[pointer] := "pointer"; representation[pointer] := "POINTER";
  name[begin] := "begin"; representation[begin] := "BEGIN";
  name[const] := "const"; representation[const] := "CONST";
  name[type] := "type"; representation[type] := "TYPE";
  name[var] := "var"; representation[var] := "VAR";
  name[procedure] := "procedure"; representation[procedure] := "PROCEDURE";
  name[import] := "import"; representation[import] := "IMPORT";
  name[module] := "module"; representation[module] := "MODULE";
  name[endOfFile] := "endOfFile";
  name[invalid] := "invalid";
  name[threeDots] := "threeDots"; representation[threeDots] := "...";
  name[pragmaStart] := "pragmaStart"; representation[pragmaStart] := "<*";
  name[pragmaEnd] := "pragmaEnd"; representation[pragmaEnd] := "*>";
  name[comment] := "comment";
  name[docComment] := "docComment";
  name[pragma] := "pragma";
  name[whitespace] := "whitespace"
END OOC:Scanner:Symbol.
