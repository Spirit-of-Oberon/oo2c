(* 	$Id: Scanner.Mod,v 1.10 2003/08/24 00:03:58 mva Exp $	 *)
MODULE OOC:Scanner;
(*  Convert a character sequence into a stream of Oberon-2 symbols.
    Copyright (C) 2000, 2001, 2002, 2003  Michael van Acken

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
  Ascii, IO, OOC:Error, OOC:Scanner:InputBuffer, OOC:Scanner:Symbol,
  OOC:Scanner:Pragma, OOC:Scanner:SymList, OOC:Config:Pragmas;


CONST
  enableIdentUnderscore* = 0;
  (**When set in @oparam{ScanInput.scanOptions}, allow identifiers to contain
     an underscore.  An underscore is treated like an additional letter
     character.  *)
  enableThreeDots* = 1;
  (**When set in @oparam{ScanInput.scanOptions}, translate the character
     sequence @samp{...} into a symbol with the id 
     @oconst{Symbol.threeDots}.  *)
  enablePragmaSymbols* = 2;
  (**When set in @oparam{ScanInput.scanOptions}, translate the delimiters
     @samp{<*} and @samp{*>} to the symbols @oconst{Symbol.pragmaStart} and
     @oconst{Symbol.pragmaEnd}.  Otherwise, the character sequences are
     tokenized as @oconst{Symbol.lss}, @oconst{Symbol.times}, and 
     @oconst{Symbol.gtr}.  *)
  enablePragmaProcessing* = 3;
  (**When set in @oparam{ScanInput.scanOptions}, interpret pragmas and resolve
     them in the scanner.  As a result, the scanner's client will not see any
     part of a pragma statement, or symbols that have been removed from the
     source file.  Instead, text that is skipped because of this, is reported
     as @oconst{Symbol.pragma}.  Like comments, such a symbol can span 
     multiple lines and must be treated as whitespace.  *)
  enableCharPosAdjust* = 4;
  (**If set, then change the @otype{Error.List} instance so that it 
     reports a character position that is decremented by the line number of
     the error.  This fixes CR/LF reporting for editors that count this as a
     single end of line character.  *)
  abortAtDeclarations* = 5;
  (**Stop reading in data when reaching one of the declaration blocks,
     like @code{CONST}, @code{TYPE}, or @code{VAR}.  *)
  
  enableAll* = {enableIdentUnderscore..enableCharPosAdjust};
  (**Enables all available add-on symbols.  *)
  
CONST
  sizeKWTable = 256;
  (* size of keyword hash table *)

VAR
  kwStr: ARRAY sizeKWTable, 2 OF InputBuffer.CharArray; 
  (* hash table for keywords, used by `Ident' *)
  kwSym: ARRAY sizeKWTable, 2 OF SHORTINT; 
  (* token for associated keywords (values for `sym') *)

CONST
  tabWidth* = 8;
  (**Width of tabulators.  Use to calculate column numbers for text with
     embedded TAB characters.  *)


CONST
  commentNotClosed = 1;
  illegalStringChar = 2;
  stringNotEnded = 3;
  notWithinComment = 4;
  illegalSymbol = 5;
  illegalExponent = 6;
  illegalHexDigit = 7;
  notWithinPragma = 8;
  
TYPE
  ErrorContext = POINTER TO ErrorContextDesc;
  ErrorContextDesc = RECORD  (* stateless *)
    (Error.ContextDesc)
  END;

VAR
  scannerContext: ErrorContext;


PROCEDURE (context: ErrorContext) GetTemplate* (msg: Error.Msg; VAR templ: Error.LString);
  VAR
    t: ARRAY 128 OF Error.LChar;
  BEGIN
    CASE msg. code OF
    | commentNotClosed:
      t := "Comment not closed"
    | illegalStringChar:
      t := "Illegal character 0${char_code}X in string"
    | stringNotEnded:
      t := "String not ended"
    | notWithinComment:
      t := "Not within comment"
    | illegalSymbol:
      t := "Illegal symbol `${sym_string}'"
    | illegalExponent:
      t := "Illegal exponent format"
    | illegalHexDigit:
      t := "Illegal cipher"
    | notWithinPragma:
      t := "Not within pragma"
    END;
    context. BaseTemplate (msg, t, templ)
  END GetTemplate;

PROCEDURE ScanInput* (builder: SymList.Builder;
                      defaultPragmas: Pragmas.Section; scanOptions: SET)
RAISES IO.Error;
(**Reads sequence of characters from input buffer @samp{builder. inputBuffer}
   and emits a sequence of symbols to @oparam{builder}.  The generated symbol
   sequence includes the whole text of the input buffer.  The last symbol has
   the id @oconst{Symbol.endOfFile} and a length of zero.  Any error in the
   input stream adds a message to @samp{builder. inputBuffer. errList} and a
   symbol with an id of @oconst{Symbol.invalid}.  The parameter
   @oparam{scanOptions} controls if some symbols that are not part of
   standard Oberon-2 are recognized by the scanner.  *)
  VAR
    chars: InputBuffer.CharArray;
    (* copy of the pointer `b.chars' *)
    cpos: InputBuffer.CharPos;
    (* current scanning position in `chars' *)
    currLine: LONGINT;
    (* current line number of `pos', starting at 0 *)
    currLinePos: InputBuffer.CharPos;
    (* position of the first character of the current line *)
    currLineTab: LONGINT;
    (* difference between column and character position due to tab chars *)
    
    b: InputBuffer.Buffer;
    pragma: Pragma.State;
    inputMode: Pragma.InputMode;
    (* this variable determines, which context is used to interpret symbols:
       normal program text, pragma text, or skipped text; it is managed by
       Pragma.AddSymbol, it is not changed by this procedure *)
    
    cstart: InputBuffer.CharPos;
    currColumn, startColumn, startLine, i, sum: LONGINT;
    dummy: BOOLEAN;
    sym: Symbol.Id;
    lastError: Error.Msg;
    strPtr: Error.StringPtr;
    eolIsCRLF: BOOLEAN;
    (* initialized to FALSE, set to TRUE with the first CR/LF combination
       encountered *)
       
    
  PROCEDURE Err (code: Error.Code);
    BEGIN
      lastError := Error.New (scannerContext, code);
      lastError. SetIntAttrib ("pos", cstart+b. offsetFromPos0);
      lastError. SetIntAttrib ("line", startLine);
      lastError. SetIntAttrib ("column", startColumn);
      b. errList. Append (lastError);
      sym := Symbol.invalid
    END Err;
    
  PROCEDURE ErrPos (code: Error.Code; cpos: LONGINT);
    BEGIN
      Err (code);
      lastError. SetIntAttrib ("pos", cpos+b. offsetFromPos0);
      lastError. SetIntAttrib ("column", cpos-currLinePos+currLineTab)
    END ErrPos;
    
  PROCEDURE NextBlock (): BOOLEAN RAISES IO.Error;
    VAR
      oldOffset: InputBuffer.CharPos;
      res: BOOLEAN;
    BEGIN
      oldOffset := b. offsetFromPos0;
      res := b. NextBlock();
      chars := b. chars;
      DEC (cpos, b. offsetFromPos0-oldOffset);
      DEC (cstart, b. offsetFromPos0-oldOffset);
      DEC (currLinePos, b. offsetFromPos0-oldOffset);
      RETURN res
    END NextBlock;
  
  PROCEDURE EndOfLine (sizeEOL: LONGINT);
    BEGIN
      INC (cpos, sizeEOL);
      INC (currLine);
      currLinePos := cpos;
      currLineTab := 0;
      IF (sizeEOL = 2) THEN
        eolIsCRLF := TRUE
      END
    END EndOfLine;
  
  PROCEDURE Lookahead (len: LONGINT) RAISES IO.Error;
    VAR
      i: InputBuffer.CharPos;
    BEGIN
      FOR i := 1 TO len DO
        IF (chars[cpos+i] = InputBuffer.markerEOB) & ~NextBlock() THEN
          RETURN
        END
      END
    END Lookahead;
  
  PROCEDURE LookaheadChar(): CHAR RAISES IO.Error;
    BEGIN
      Lookahead (1);
      RETURN chars[cpos+1]
    END LookaheadChar;
  
  PROCEDURE CompareIdent (start: InputBuffer.CharPos;
                          VAR kw: ARRAY OF CHAR): BOOLEAN;
  (* Compares the current identifier symbol starting at buffer position 
     `start' with `kw', returns TRUE if they are identical. *)
    VAR
      i: InputBuffer.CharPos;
    BEGIN
      i := 0;
      WHILE (kw[i] # 0X) & (kw[i] = chars[start+i]) DO
        INC (i)
      END;
      RETURN (kw[i] = 0X) & (start+i = cpos)
    END CompareIdent;
  
  PROCEDURE SetCharAttrib (ch: LONGINT);
    VAR
      str: Error.StringPtr;
      h: CHAR;
      i, j: LONGINT;
    BEGIN
      NEW (str, 6);
      i := 0;
      REPEAT
        IF (ch MOD 16 < 10) THEN
          str[i] := CHR (ch MOD 16+ORD ("0"))
        ELSE
          str[i] := CHR (ch MOD 16+(ORD ("A")-10))
        END;
        ch := ch DIV 16;
        INC (i)
      UNTIL (ch = 0);
      str[i] := 0X;
      
      j := 0; DEC (i);
      WHILE (j < i) DO
        h := str[j]; str[j] := str[i]; str[i] := h;
        INC (j); DEC (i)
      END;
      
      lastError. SetStringAttrib ("char_code", str)
    END SetCharAttrib;
  
  
  BEGIN
    b := builder. inputBuffer;
    lastError := NIL;
    chars := b. chars;
    cpos := 0;
    currLine := 0;
    currLinePos := cpos;
    currLineTab := 0;
    inputMode := Pragma.inputText;
    eolIsCRLF := FALSE;
    Pragma.Init (pragma, builder, defaultPragmas);
    
    LOOP
      (* handle whitespace *)
      cstart := cpos;
      startLine := currLine;
      startColumn := cpos-currLinePos+currLineTab;
      LOOP
        CASE chars[cpos] OF
        | InputBuffer.markerEOB:
          IF b. EndOfBuffer (cpos) THEN
            IF ~NextBlock() THEN
              EXIT  (* end of file: leave whitespace loop *)
            END
          ELSE
            INC (cpos)
          END
        | Ascii.lf:
          EndOfLine (1)
        | Ascii.cr:
          IF (chars[cpos+1] = InputBuffer.markerEOB) THEN
            dummy := NextBlock()  (* ensure that next character is valid *)
          END;
          IF (chars[cpos+1] = Ascii.lf) THEN
            EndOfLine (2)
          ELSE
            EndOfLine (1)
          END
        | Ascii.ht:  (* adjust for horizontal tabulator *)
          currColumn := cpos-currLinePos+currLineTab;
          INC (currLineTab, tabWidth-currColumn MOD tabWidth-1);
          INC (cpos)
        | 21X .. MAX (InputBuffer.Char):
          EXIT
        ELSE
          INC (cpos)
        END
      END;
      IF (cstart # cpos) & (inputMode = Pragma.inputText) THEN
        builder. AddSymbol (Symbol.whitespace, cstart, cpos, 
                            startLine, startColumn)
        (* end line=currLine, end column=cpos-currLinePos+currLineTab *)
      END;
      
      (* character `chars[cpos]' is not a whitespace character, but the
         reading position can be past the end of the file *)
      cstart := cpos;
      startLine := currLine;
      startColumn := cpos-currLinePos+currLineTab;
      CASE chars[cpos] OF
      | InputBuffer.markerEOB:
        EXIT                             (* end of file *)
      | "_":
        IF (enableIdentUnderscore IN scanOptions) THEN
          REPEAT
            cpos := cstart; sum := 0;
            REPEAT  (* loop to the first non char/cypher *)
              INC (sum, ORD (chars[cpos]));
              INC (cpos)
            UNTIL ~(("A" <= CAP (chars[cpos])) & (CAP (chars[cpos]) <= "Z") OR
                    ("0" <= chars[cpos]) & (chars[cpos] <= "9") OR
                    (chars[cpos] = "_"))
          UNTIL (chars[cpos] # InputBuffer.markerEOB) OR ~NextBlock();
          sym := Symbol.ident
        ELSE
          Err (illegalSymbol);
          NEW (strPtr, 2);
          strPtr[0] := chars[cpos]; strPtr[1] := 0X;
          lastError. SetStringAttrib ("sym_string", strPtr);
          INC (cpos)
        END
      | "a".."z", "A".."Z":              (* identifier or keyword *)
        REPEAT
          cpos := cstart; sum := 0;
          REPEAT  (* loop to the first non char/cypher *)
            INC (sum, ORD (chars[cpos]));
            INC (cpos)
          UNTIL ~(("A" <= CAP (chars[cpos])) & (CAP (chars[cpos]) <= "Z") OR
                  ("0" <= chars[cpos]) & (chars[cpos] <= "9") OR
                  (chars[cpos] = "_") & (enableIdentUnderscore IN scanOptions))
        UNTIL (chars[cpos] # InputBuffer.markerEOB) OR ~NextBlock();
        
        sym := Symbol.ident;
        i := sum MOD sizeKWTable;
        IF (kwSym[i, 0] >= 0) THEN       (* check for keyword *)
          IF CompareIdent (cstart, kwStr[i, 0]^) THEN
            sym := kwSym[i, 0]
          ELSIF (kwSym[i, 1] >= 0) & CompareIdent (cstart, kwStr[i, 1]^) THEN
            sym := kwSym[i, 1]
          END;

          IF (sym >= Symbol.const) & (sym < Symbol.import) &
             (abortAtDeclarations IN scanOptions) THEN
            EXIT;                        (* abort scanning early *)
          END;
        END
      | "0".."9":                        (* number or character constant *)
        REPEAT
          cpos := cstart;
          (* scan characters to the first non (hex-) cipher; note: lower case 
             characters like "a" are _not_ valid hex digits *)
          REPEAT
            INC (cpos)
          UNTIL ~ (("0" <= chars[cpos]) & (chars[cpos] <= "9") OR 
                   ("A" <= chars[cpos]) & (chars[cpos] <= "F"))
        UNTIL (chars[cpos] # InputBuffer.markerEOB) OR ~NextBlock();
        
        IF (chars[cpos] = ".") & (LookaheadChar() # ".") THEN
          (* looking at a real constant, and not at a ".." symbol *)
          sym := Symbol.numberExpE;
          INC (cpos);
          (* read decimal fraction *)
          REPEAT
            WHILE ("0" <= chars[cpos]) & (chars[cpos] <= "9") DO
              INC (cpos)
            END
          UNTIL (chars[cpos] # InputBuffer.markerEOB) OR ~NextBlock();
          IF (chars[cpos] = "E") OR (chars[cpos] = "D") THEN
            IF (chars[cpos] = "D") THEN
              sym := Symbol.numberExpD
            END;
            
            (* read scale factor *)
            Lookahead (2);
            INC (cpos);
            IF (chars[cpos] = "-") OR (chars[cpos] = "+") THEN
              INC (cpos)
            END;
            IF ("0" <= chars[cpos]) & (chars[cpos] <= "9") THEN
              REPEAT
                WHILE ("0" <= chars[cpos]) & (chars[cpos] <= "9") DO
                  INC (cpos)
                END
              UNTIL (chars[cpos] # InputBuffer.markerEOB) OR ~NextBlock()
            ELSE
              ErrPos (illegalExponent, cpos)
            END
          END
        ELSE                             (* integer or character constant *)
          IF (chars[cpos] = "H") THEN
            sym := Symbol.number16;
            INC (cpos)
          ELSIF (chars[cpos] = "X") THEN
            sym := Symbol.number16X;
            INC (cpos)
          ELSE  (* check whether all characters are decimal digits *)
            sym := Symbol.number10;
            i := cstart;
            WHILE (i # cpos) & ("0" <= chars[i]) & (chars[i] <= "9") DO
              INC (i)
            END;
            IF (i # cpos) THEN           (* chars[i] isn't from "0".."9" *)
              ErrPos (illegalHexDigit, i)
            END
          END
        END
      | '"', "'":
        IF (chars[cpos] = '"') THEN
          sym := Symbol.stringDouble
        ELSE
          sym := Symbol.stringSingle
        END;
        REPEAT
          cpos := cstart;
          (* loop until end delimiter or control character, whatever comes 
             first *)
          REPEAT
            INC (cpos)
          UNTIL (chars[cpos] < " ") OR (chars[cpos] = chars[cstart])
        UNTIL (chars[cpos] # InputBuffer.markerEOB) OR ~NextBlock();
        
        IF (chars[cpos] # chars[cstart]) THEN
          IF (chars[cpos] = Ascii.lf) OR (chars[cpos] = Ascii.cr) THEN
            Err (stringNotEnded)
          ELSE
            ErrPos (illegalStringChar, cpos);
            SetCharAttrib (ORD (chars[cpos]))
          END
        ELSE
          INC (cpos)
        END
      | "~":
        sym := Symbol.not; INC (cpos)
      | "{":
        sym := Symbol.lBrace; INC (cpos)
      | ".": 
        Lookahead (2);
        INC (cpos);
        IF (chars[cpos] = ".") THEN 
          sym := Symbol.upto; 
          INC (cpos);
          IF (chars[cpos] = ".") & (enableThreeDots IN scanOptions) THEN 
            sym := Symbol.threeDots;
            INC (cpos)
          END
        ELSE 
          sym := Symbol.period
        END
      | "^":
        sym := Symbol.arrow; INC (cpos)
      | "[":
        sym := Symbol.lBrak; INC (cpos)
      | ":": 
        Lookahead (1);
        INC (cpos);
        IF (chars[cpos] = "=") THEN 
          sym := Symbol.becomes; INC (cpos)
        ELSE 
          sym := Symbol.colon
        END
      | "(": 
        Lookahead (1);
        INC (cpos);
        IF (chars[cpos] = "*") THEN      (* looking at start of comment *)
          IF (chars[cpos+1] = "*") & (chars[cpos+2] # ")") THEN
            sym := Symbol.docComment
          ELSE
            sym := Symbol.comment
          END;
          sum := 1;
          LOOP
            CASE chars[cpos] OF
            | InputBuffer.markerEOB:
              IF b. EndOfBuffer (cpos) THEN
                IF ~NextBlock() THEN
                  EXIT  (* end of file: leave comment loop *)
                END
              ELSE
                INC (cpos)
              END
            | Ascii.lf:
              EndOfLine (1)
            | Ascii.cr:
              IF (chars[cpos+1] = InputBuffer.markerEOB) THEN
                dummy := NextBlock()  (* ensure that next character is valid *)
              END;
              IF (chars[cpos+1] = Ascii.lf) THEN
                EndOfLine (2)
              ELSE
                EndOfLine (1)
              END
            | Ascii.ht:  (* adjust for horizontal tabulator *)
              currColumn := cpos-currLinePos+currLineTab;
              INC (currLineTab, tabWidth-currColumn MOD tabWidth-1);
              INC (cpos)
            | "*":
              Lookahead (1);
              INC (cpos);
              IF (chars[cpos] = ")") THEN (* end of comment *)
                INC (cpos);
                DEC (sum);
                IF (sum = 0) THEN EXIT END
              END
            | "(":
              Lookahead (1);
              INC (cpos);
              IF (chars[cpos] = "*") THEN (* nested comments *)
                INC (sum)
              END
            ELSE
              INC (cpos)
            END
          END;
          
          IF (sum # 0) THEN
            Err (commentNotClosed)
          END
        ELSE 
          sym := Symbol.lParen
        END
      | "*": 
        Lookahead (1);
        INC (cpos);
        IF (chars[cpos] = ")") THEN
          Err (notWithinComment);
          INC (cpos)
        ELSIF (chars[cpos] = ">") & (enablePragmaSymbols IN scanOptions) THEN
          IF (inputMode # Pragma.inputPragma) THEN
            Err (notWithinPragma)
          ELSE
            sym := Symbol.pragmaEnd
          END;
          INC (cpos)
        ELSE
          sym := Symbol.times
        END
      | "/":
        sym := Symbol.slash; INC (cpos)
      | "&":
        sym := Symbol.and; INC (cpos)
      | "+":
        sym := Symbol.plus; INC (cpos)
      | "-":
        sym := Symbol.minus; INC (cpos)
      | "=":
        sym := Symbol.eql; INC (cpos)
      | "#":
        sym := Symbol.neq; INC (cpos)
      | "<": 
        Lookahead (1);
        INC (cpos);
        IF (chars[cpos] = "=") THEN 
          sym := Symbol.leq; INC (cpos)
        ELSIF (chars[cpos] = "*") & (enablePragmaSymbols IN scanOptions) THEN
          sym := Symbol.pragmaStart;
          INC (cpos)
        ELSE 
          sym := Symbol.lss 
        END
      | ">": 
        Lookahead (1);
        INC (cpos);
        IF (chars[cpos] = "=") THEN 
          sym := Symbol.geq; INC (cpos)
        ELSE 
          sym := Symbol.gtr
        END
      | "}":
        sym := Symbol.rBrace; INC (cpos)
      | ")":
        sym := Symbol.rParen; INC (cpos)
      | "]":
        sym := Symbol.rBrak; INC (cpos)
      | "|":
        sym := Symbol.bar; INC (cpos)
      | ";":
        sym := Symbol.semicolon; INC (cpos)
      | ",":
        sym := Symbol.comma; INC (cpos)
      ELSE
        Err (illegalSymbol);
        NEW (strPtr, 2);
        strPtr[0] := chars[cpos]; strPtr[1] := 0X;
        lastError. SetStringAttrib ("sym_string", strPtr);
        INC (cpos)
      END;
      
      IF (sym = Symbol.pragmaStart) &
         (enablePragmaProcessing IN scanOptions) THEN
        Pragma.AddSymbol (pragma, inputMode, sym, cstart, cpos,
                          startLine, startColumn)
      ELSIF (inputMode = Pragma.inputSkippedText) THEN
        (* silently discard the symbol, it will appear in the text of 
           the enclosing pragma symbol *)
      ELSIF (inputMode = Pragma.inputText) THEN
        (* anything before current reading position can be discarded from
           the input buffer by NextBlock() *)
        b. discardable := cpos;
        
        builder. AddSymbol (sym, cstart, cpos, startLine, startColumn)
        (* end_line=currLine, end_column=cpos-currLinePos+currLineTab *)
      ELSE  (* (inputMode = Pragma.inputPragma) *)
        Pragma.AddSymbol (pragma, inputMode, sym, cstart, cpos,
                          startLine, startColumn)
      END
    END;
    
    IF (enablePragmaProcessing IN scanOptions) THEN
      (* pipe end of file through pragma machine, because it may have some last
         error messages to report (like unfinished pragma, or an `IF' without
         an `END') *)
      Pragma.AddSymbol (pragma, inputMode, Symbol.endOfFile, cpos, cpos,
                        currLine, cpos-currLinePos+currLineTab)
    ELSE
      builder. AddSymbol (Symbol.endOfFile, cpos, cpos,
                          currLine, cpos-currLinePos+currLineTab)
    END;
    builder. SetPragmaHistory (pragma. variableHistory);
    
    IF (enableCharPosAdjust IN scanOptions) & eolIsCRLF THEN
      b. errList. SetAdjustCharPos (TRUE)
    END
  END ScanInput;

PROCEDURE InitKeywords;
(* Fills hash table used by the identifier part of `ScanInput' to identify
   the keywords. *)
  VAR
    i: LONGINT;

  PROCEDURE KW (ident: ARRAY OF CHAR; sym: SHORTINT);
    VAR
      i, j, sum: INTEGER;
      str: InputBuffer.CharArray;
    BEGIN
      sum := 0; i := 0;
      WHILE (ident[i] # 0X) DO
        INC (sum, ORD (ident[i])); INC (i)
      END;
      j := sum MOD sizeKWTable;
      NEW (str, i+1);
      COPY (ident, str^);
      IF (kwSym[j, 0] < 0) THEN
        kwSym[j, 0] := sym;
        kwStr[j, 0] := str
      ELSE
        kwSym[j, 1] := sym;
        kwStr[j, 1] := str
      END
    END KW;

  BEGIN
    FOR i := 0 TO sizeKWTable-1 DO
      kwSym[i, 0] := -1; kwSym[i, 1] := -1;
      kwStr[i, 0] := NIL; kwStr[i, 1] := NIL
    END;
    
    KW ("ARRAY", Symbol.array);
    KW ("BEGIN", Symbol.begin);
    KW ("BY", Symbol.by);
    KW ("CASE", Symbol.case);
    KW ("CONST", Symbol.const);
    KW ("DIV", Symbol.div);
    KW ("DO", Symbol.do);
    KW ("ELSE", Symbol.else);
    KW ("ELSIF", Symbol.elsif);
    KW ("END", Symbol.end);
    KW ("EXIT", Symbol.exit);
    KW ("FOR", Symbol.for);
    KW ("IF", Symbol.if);
    KW ("IMPORT", Symbol.import);
    KW ("IN", Symbol.in);
    KW ("IS", Symbol.is);
    KW ("LOOP", Symbol.loop);
    KW ("MOD", Symbol.mod);
    KW ("MODULE", Symbol.module);
    KW ("NIL", Symbol.nil);
    KW ("OF", Symbol.of);
    KW ("OR", Symbol.or);
    KW ("POINTER", Symbol.pointer); 
    KW ("PROCEDURE", Symbol.procedure);
    KW ("RECORD", Symbol.record);
    KW ("REPEAT", Symbol.repeat);
    KW ("RETURN", Symbol.return);
    KW ("THEN", Symbol.then);
    KW ("TO", Symbol.to);
    KW ("TYPE", Symbol.type);
    KW ("UNTIL", Symbol.until);
    KW ("VAR", Symbol.var);
    KW ("WHILE", Symbol.while); 
    KW ("WITH", Symbol.with);
    KW ("TRY", Symbol.try);
    KW ("CATCH", Symbol.catch);
    KW ("RAISES", Symbol.raises);
  END InitKeywords;

BEGIN
  NEW (scannerContext);
  Error.InitContext (scannerContext, "OOC:Scanner");
  InitKeywords
END OOC:Scanner.
