(*	$Id: RegexpParser.Mod,v 1.2 2002/12/17 19:33:40 mva Exp $	*)
MODULE StringSearch:RegexpParser;
(*  Translates regular expression pattern into abstract syntax tree.
    Copyright (C) 2001  Michael van Acken

    This module is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public License
    as published by the Free Software Foundation; either version 2 of
    the License, or (at your option) any later version.

    This module is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with OOC. If not, write to the Free Software Foundation,
    59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*)

IMPORT
  Ascii, Object, StringSearch;


(*

Syntax:

special_char    ::= [.^$*+?\\\[\]|()].

SpecialSequence ::= "\d" | "\D" | "\s" | "\S" | "\w" | "\W".

Shorthand       ::= "\b" | "\a" | "\e" | "\f" | "\n" | "\r" | "\t" | "\v".

Factor          ::= "." | "^" | "$" | (char - special_char) |
                    "\" special_char | SpecialSequence | Shorthand |
                    Set | "(" Regexp ")" .
  first(Factor)  = char - [])*+?]
  follow(Factor) = [*+?|)] + first(Factor) + eos

Set             ::= "[" ["^"] {SpecialSequence | Char ["-" Char]} "]".

Char            ::= char - "\" | Shorthand | "\" char.

Term            ::= Factor ["*" | "+" | "?"].
  first(Term)    = first(Factor)
  follow(Term)   = first(Factor) + follow(Expr)

Expr            ::= {Term}.
  first(Expr)    = first(Factor) + follow(Term)
  follow(Expr)   = "|" + ")" + eos

Regexp          ::= Expr {"|" Expr}.
  first(Regexp)  = first(Expr)
  follow(Regexp) = eos

*)


CONST
  backslash* = "\";                      (* " *)
  sizeCHAR* = 256;
  sizeSET* = MAX (SET)+1;
  maxGroupCount = 127;

TYPE
  FactorType* = SHORTINT;
  
CONST
  matchEmpty = -2;
  matchGroup* = -1;
  matchChar* = 0;
  matchCharIgnoreCase* = 1;
  matchAnyButNewline* = 3;
  matchAtFirstChar* = 4;
  matchAfterLastChar* = 5;
  matchSet* = 6;
  matchSetInverted* = 7;

TYPE
  CharSet* = POINTER TO ARRAY sizeCHAR DIV sizeSET OF SET;
  Factor* = POINTER TO FactorDesc;
  Group* = POINTER TO GroupDesc;
  FactorDesc* = RECORD
    type-: FactorType;
    (**Determines how the factor is matched against input.  *)
    char-: CHAR;
    (**For a character match, this field holds the expected character.
       Otherwise, it is @code{0X}.  *)
    charSet-: CharSet;
    (**For a character set match, this field refers to a set of characters.
       Otherwise, it is @code{NIL}.  *)
    group-: Group;
    (**For a parenthised group, this field refers to the nested group.
       Otherwise, it is @code{NIL}.  *)
  END;

TYPE
  QuantifierType* = SHORTINT;
  (**One of @oconst{exactlyOnce}, @oconst{zeroOrOnceGreedy},
     @oconst{zeroOrMoreGreedy}, or @oconst{onceOrMoreGreedy}.  *)
  
CONST
  exactlyOnce* = 0;
  (**The expression must match exactly once.  Example: @samp{a}.  *)
  zeroOrOnceGreedy* = 1;
  (**The expression can match at most once, and the longest match wins.
     Example: @samp{a?}.  *)
  zeroOrMoreGreedy* = 2;
  (**The expression must match zero or more times.  The longest match wins.
     Example: @samp{a*}.  *)
  onceOrMoreGreedy* = 3;
  (**The expression must match one or more times.  The longest match wins.
     Example: @samp{a+}.  *)
  
TYPE
  Term* = POINTER TO TermDesc;
  TermDesc* = RECORD
  (**An atomic factor, optionally followed by a quantifier.  *)
    next-: Term;
    (**Links elements of @ofield{Expr.termList}. *)
    factor-: Factor;
    (**The base expression of the term.  *)
    quantifier-: QuantifierType;
    (**Specifies how often @ofield{factor} must match for the term to be
       considered a successful match.  *)
  END;

TYPE
  Expr* = POINTER TO ExprDesc;
  ExprDesc* = RECORD
  (**Represents a sequence of terms like @samp{a}, @samp{[a]}, or @samp{a*}.  *)
    next-: Expr;
    (**Links elements of @ofield{Group.exprList}.  *)
    termList-: Term;
    (**Sequence of terms within the expression.  List is linked by
       @ofield{Term.next}.  Note: This list may be empty, which happens for
       expressions like @samp{}, @samp{()}, @samp{(a|)}, and so on.  *)
  END;
  
TYPE
  GroupId* = SHORTINT;
  GroupDesc* = RECORD
  (**Represents list of alternatives, separated by @samp{|}.  *)
  exprList-: Expr;
    (**List of alternatives within this group.  List is linked by
       @ofield{Expr.next}.  *)
    groupId-: GroupId;
    (**Identifier for this group.  The group that represents the whole regular
       expression has an id of @samp{0}.  The ids of nested groups is derived
       by counting opening parenthesis before it.  The first @samp{(} in the
       expression gets the id @samp{1}, the second @samp{2}, and so on.  *)
  END;


TYPE
  Builder* = POINTER TO BuilderDesc;
  BuilderDesc* = RECORD
  (**Factory for nodes of the abstract syntax tree.  *)
  END;



VAR
  setDigits: CharSet;
  setWhitespace: CharSet;
  setAlphaNum: CharSet;


PROCEDURE UpperLower* (ch: CHAR; VAR upper, lower: CHAR);
  VAR
    i: INTEGER;
  BEGIN
    i := ORD (ch);
    IF (96<i) & (i<123) OR (224<=i) & (i<255) & (i#247) THEN
      upper := CHR (i-32); lower := ch
    ELSIF ((96-32)<i) & (i<(123-32)) OR
          ((224-32)<=i) & (i<(255-32)) & (i#(247-32)) THEN
      upper := ch; lower := CHR (i+32)
    ELSE
      upper := ch; lower := ch
    END
  END UpperLower;


PROCEDURE NewSet (): CharSet;
  VAR
    set: CharSet;
    i: LONGINT;
  BEGIN
    NEW (set);
    FOR i := 0 TO LEN (set^)-1 DO
      set[i] := {}
    END;
    RETURN set
  END NewSet;

PROCEDURE SetElement (set: CharSet; flags: StringSearch.Flags; i: LONGINT);
  VAR
    upper, lower: CHAR;
  BEGIN
    IF (StringSearch.ignoreCase IN flags) THEN
      UpperLower (CHR (i), upper, lower);
      INCL (set[ORD (upper) DIV sizeSET], ORD (upper) MOD sizeSET);
      INCL (set[ORD (lower) DIV sizeSET], ORD (lower) MOD sizeSET)
    ELSE
      INCL (set[i DIV sizeSET], i MOD sizeSET);
    END
  END SetElement;

PROCEDURE SetRange (set: CharSet; flags: StringSearch.Flags; start, end: CHAR);
  VAR
    i: LONGINT;
  BEGIN
    FOR i := ORD (start) TO ORD (end) DO
      SetElement (set, flags, i)
    END
  END SetRange;

PROCEDURE Union (dest, source: CharSet);
  VAR
    i: LONGINT;
  BEGIN
    FOR i := 0 TO LEN (dest^)-1 DO
      dest[i] := dest[i]+source[i]
    END
  END Union;

PROCEDURE UnionComplement (dest, source: CharSet);
  VAR
    i: LONGINT;
  BEGIN
    FOR i := 0 TO LEN (dest^)-1 DO
      dest[i] := dest[i]+(-source[i])
    END
  END UnionComplement;

PROCEDURE Shorthand (ch: CHAR): CHAR;
  BEGIN
    CASE ch OF
    | "b": RETURN Ascii.bs
    | "a": RETURN Ascii.bel
    | "e": RETURN Ascii.esc
    | "f": RETURN Ascii.ff
    | "n": RETURN Ascii.lf
    | "r": RETURN Ascii.cr
    | "t": RETURN Ascii.ht
    | "v": RETURN Ascii.vt
    ELSE RETURN 0X
    END
  END Shorthand;




PROCEDURE InitGroup* (group: Group; groupId: GroupId);
  BEGIN
    group. exprList := NIL;
    group. groupId := groupId;
  END InitGroup;

PROCEDURE (b: Builder) NewGroup* (groupId: GroupId): Group;
  VAR
    group: Group;
  BEGIN
    NEW (group);
    InitGroup (group, groupId);
    RETURN group
  END NewGroup;


PROCEDURE InitExpr* (expr: Expr);
  BEGIN
    expr. next := NIL;
    expr. termList := NIL;
  END InitExpr;

PROCEDURE (b: Builder) NewExpr* (): Expr;
  VAR
    expr: Expr;
  BEGIN
    NEW (expr);
    InitExpr (expr);
    RETURN expr
  END NewExpr;


PROCEDURE InitTerm* (term: Term);
  BEGIN
    term. next := NIL;
    term. factor := NIL;
    term. quantifier := exactlyOnce;
  END InitTerm;

PROCEDURE (b: Builder) NewTerm* (): Term;
  VAR
    term: Term;
  BEGIN
    NEW (term);
    InitTerm (term);
    RETURN term
  END NewTerm;


PROCEDURE InitFactor* (factor: Factor; type: FactorType);
  BEGIN
    factor. type := type;
    factor. char := 0X;
    factor. charSet := NIL;
    factor. group := NIL;
  END InitFactor;

PROCEDURE (b: Builder) NewFactor* (type: FactorType): Factor;
  VAR
    factor: Factor;
  BEGIN
    NEW (factor);
    InitFactor (factor, type);
    RETURN factor
  END NewFactor;


PROCEDURE InitBuilder* (b: Builder);
  BEGIN
  END InitBuilder;

PROCEDURE NewBuilder* (): Builder;
  VAR
    b: Builder;
  BEGIN
    NEW (b);
    InitBuilder (b);
    RETURN b
  END NewBuilder;



PROCEDURE Parse* (b: Builder; pattern: Object.String8; flags: StringSearch.Flags): Group;
(**Parses the regular expression in @oparam{pattern}, modified by the options
   passed in @oparam{flags}.

   Result is an abstract syntax tree of the regular expression on success, and
   @code{NIL} on failure.  The nodes of the AST a constructed from instances
   created through the builder object @oparam{b}.

   For a short description of regular expression syntax, see
   @omodule{*StringSearch:RegexpDFA}.  *)
  VAR
    re: Object.CharsLatin1;
    reEnd: LONGINT;
    regexpGroup: Group;
    
  VAR
    pos: LONGINT;
    errorPos: LONGINT;
    groupCount: GroupId; (* number of groups, including the regexp itself *)
    currentGroup: GroupId;
  
  PROCEDURE Error;
    BEGIN
      IF (errorPos < 0) THEN
        errorPos := pos
      END;
      IF (re[pos] # 0X) THEN
        INC (pos)
      END
    END Error;
  
  PROCEDURE Regexp (VAR group: Group);
    VAR
      last: Expr;
      oldGroupId: GroupId;
      
    PROCEDURE Expr (VAR expr: Expr);
      VAR
        last: Term;
        
      PROCEDURE Term (VAR term: Term);
        PROCEDURE Factor (VAR factor: Factor);
          PROCEDURE Set (set: CharSet): FactorType;
            VAR
              ch1: CHAR;
              type: FactorType;
            
            PROCEDURE SpecialSequence (ch: CHAR): BOOLEAN;
              BEGIN
                CASE CAP (ch) OF
                | "D", "S", "W": RETURN TRUE
                ELSE RETURN FALSE
                END
              END SpecialSequence;
            
            PROCEDURE Char(): CHAR;
              BEGIN
                IF (re[pos] = backslash) THEN
                  IF (re[pos+1] = 0X) THEN
                    Error; RETURN " "
                  ELSIF (Shorthand (re[pos+1]) # 0X) THEN
                    INC (pos, 2); RETURN Shorthand (re[pos-1])
                  ELSE
                    INC (pos, 2); RETURN re[pos-1]
                  END
                ELSE
                  INC (pos); RETURN re[pos-1]
                END
              END Char;
            
            BEGIN  (* pre: re[pos] = "[" *)
              INC (pos);
              IF (re[pos] = "^") THEN
                type := matchSetInverted; INC (pos)
              ELSE
                type := matchSet
              END;
              REPEAT
                IF (re[pos] = backslash) & SpecialSequence (re[pos+1]) THEN
                  CASE re[pos+1] OF
                  | "d": Union (set, setDigits)
                  | "D": UnionComplement (set, setDigits)
                  | "s": Union (set, setWhitespace)
                  | "S": UnionComplement (set, setWhitespace)
                  | "w": Union (set, setAlphaNum)
                  | "W": UnionComplement (set, setAlphaNum)
                  ELSE
                    Error
                  END;
                  INC (pos, 2)
                ELSE
                  ch1 := Char();
                  IF (re[pos] = "-") &
                     (re[pos+1] # "]") &
                     ~((re[pos+1] = backslash) &
                       SpecialSequence (re[pos+2])) THEN
                    INC (pos);
                    SetRange (set, flags, ch1, Char())
                  ELSE
                    SetElement (set, flags, ORD (ch1))
                  END
                END
              UNTIL (errorPos >= 0) OR (re[pos] = 0X) OR (re[pos] = "]");
              IF (re[pos] # "]") THEN
                Error
              ELSE
                INC (pos)
              END;
              RETURN type
            END Set;
          
          BEGIN  (* pre: (re[pos] # 0X) & (re[pos] # "|") & (re[pos] # ")") *)
            CASE re[pos] OF
            | ".":
              factor := b. NewFactor (matchAnyButNewline);
              INC (pos)
              
            | "^":
              factor := b. NewFactor (matchAtFirstChar);
              INC (pos)
              
            | "$":
              factor := b. NewFactor (matchAfterLastChar);
              INC (pos)
              
            | backslash:
              factor := b. NewFactor (matchEmpty);
              CASE re[pos+1] OF
              | ".", "^", "$", "*", "+", "?", backslash,
                "[", "]", "|", "(", ")":
                factor. type := matchChar; factor. char := re[pos+1]
              | "d", "D":
                factor. type := matchSet; factor. charSet := setDigits
              | "s", "S":
                factor. type := matchSet; factor. charSet := setWhitespace
              | "w", "W":
                factor. type := matchSet; factor. charSet := setAlphaNum
              ELSE
                IF (Shorthand (re[pos+1]) # 0X) THEN
                  factor. type := matchChar;
                  factor. char := Shorthand (re[pos+1])
                ELSE
                  Error; DEC (pos, 2)
                END
              END;
              IF (factor. type = matchSet) & 
                 ("A" <= re[pos+1]) & (re[pos+1] <= "Z") THEN
                factor. type := matchSetInverted
              END;
              INC (pos, 2)
              
            | "[":
              factor := b. NewFactor (matchSet);
              factor. charSet := NewSet();
              factor. type := Set (factor. charSet)
              
            | "(":
              INC (pos);
              factor := b. NewFactor (matchGroup);
              Regexp (factor. group);
              IF (re[pos] = ")") THEN
                INC (pos)
              ELSE
                Error
              END
              
            | "*", "+", "?", "]":
              factor := b. NewFactor (matchEmpty);
              Error
              
            ELSE
              IF (StringSearch.ignoreCase IN flags) THEN
                factor := b. NewFactor (matchCharIgnoreCase)
              ELSE
                factor := b. NewFactor (matchChar)
              END;
              factor. char := re[pos];
              INC (pos)
            END
          END Factor;
        
        BEGIN
          term := b. NewTerm();
          
          Factor (term. factor);
          CASE re[pos] OF
          | "*": term. quantifier := zeroOrMoreGreedy; INC (pos)
          | "+": term. quantifier := onceOrMoreGreedy; INC (pos)
          | "?": term. quantifier := zeroOrOnceGreedy; INC (pos)
          ELSE
          END
        END Term;
      
      BEGIN
        expr := b. NewExpr();
        
        IF ~((re[pos] = 0X) OR (re[pos] = "|") OR (re[pos] = ")")) THEN
          Term (expr. termList); last := expr. termList;
          WHILE (errorPos < 0) &
                (re[pos] # 0X) & (re[pos] # "|") & (re[pos] # ")") DO
            Term (last. next); last := last. next
          END
        END
      END Expr;
    
    BEGIN
      IF (groupCount = maxGroupCount) THEN
        Error
      ELSE
        INC (groupCount)
      END;
      oldGroupId := currentGroup;
      group := b. NewGroup (groupCount);
      
      Expr (group. exprList);
      last := group. exprList;
      WHILE (re[pos] = "|") DO
        INC (pos);
        Expr (last. next);
        last := last. next
      END;
      
      currentGroup := oldGroupId
    END Regexp;
  
  BEGIN
    re := pattern. CharsLatin1();
    reEnd := pattern. length;
    
    groupCount := -1;
    currentGroup := -1;
    pos := 0;
    errorPos := -1;
    
    Regexp (regexpGroup);
    IF (pos # reEnd) THEN
      Error
    END;
    
    IF (errorPos < 0) THEN               (* success *)
      RETURN regexpGroup
    ELSE
      RETURN NIL
    END
  END Parse;

BEGIN
  setDigits := NewSet();
  SetRange (setDigits, {}, "0", "9");
  setWhitespace := NewSet();
  SetElement (setWhitespace, {}, ORD (Ascii.sp));
  SetElement (setWhitespace, {}, ORD (Ascii.ht));
  SetElement (setWhitespace, {}, ORD (Ascii.lf));
  SetElement (setWhitespace, {}, ORD (Ascii.cr));
  SetElement (setWhitespace, {}, ORD (Ascii.ff));
  SetElement (setWhitespace, {}, ORD (Ascii.vt));
  setAlphaNum := NewSet();
  SetRange (setAlphaNum, {}, "0", "9");
  SetRange (setAlphaNum, {}, "a", "z");
  SetRange (setAlphaNum, {}, "A", "Z");
END StringSearch:RegexpParser.
