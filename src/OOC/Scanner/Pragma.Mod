MODULE OOC:Scanner:Pragma;

IMPORT
  Msg, Strings, RT0,
  OOC:Error, OOC:Scanner:InputBuffer, OOC:Scanner:Symbol, OOC:Scanner:Builder,
  OOC:Scanner:Builder:BasicList, OOC:Config:Pragmas, OOC:Scanner:Integer,
  
  ConfigValue := Config:Value,
  BooleanValue := Config:Value:Boolean,
  IntegerValue := Config:Value:Integer,
  StringValue := Config:Value:String;


TYPE
  InputMode* = SHORTINT;

CONST
  inputText* = 0;
  inputPragma* = 1;
  inputSkippedText* = 2;
  
TYPE 
  ConditionStack = POINTER TO ConditionStackDesc;
  ConditionStackDesc = RECORD
    prev: ConditionStack;
    (* link to preceding item in stack, top of stack is in `condStack' *)
    ifPos: BasicList.Symbol;
    (* position of initial `IF' keyword *)
    skippedCond: BOOLEAN;
    (* TRUE iff whole condition is part of skipped text *)
    foundTrue: BOOLEAN;
    (* TRUE iff a preceding IF or ELSIF guard evaluated to TRUE *)
    elsePresent: BOOLEAN;
    (* set when an ELSE part has been parsed *)
  END;

TYPE
  State* = RECORD
    buffer: InputBuffer.Buffer;
    (* input buffer, from which the symbols in @ofield{symList} were taken *)
    
    builder: Builder.Builder;
    (* builder that is served by the associated scanner instance *)
    
    
    condStack: ConditionStack;
    (* conditional statements are managed on this stack *)
    
    evalText: BOOLEAN;
    (* this field keeps track, if the current symbol is part of pragma 
       (or source text), that is evaluated, or whether it is skipped text
       that must only be correct on the syntax (or lexical) level; the
       value of this variable changes with conditional pragma statements *)
    
    symList: BasicList.Builder;
    (* all symbols within a `<*...*>' pragma section are collected into this
       list; the list excludes the beginning delimiter, but includes the 
       @oconst{Symbol.pragmaEnd} symbol *)
    
    
    startCharPos, startAbsPos: InputBuffer.CharPos;
    startLine, startColumn: LONGINT;
    (* these fields refer to the position of the `<*' of the current pragma
       section; they are used to create the pseudo symbol of type
       @oconst{Symbol.pragma}, that collects the pragma section and skipped
       text into a single multi-line symbol *)
    
    variableHistory-: Pragmas.History;
    (**This object keeps track of the changes to pragma variables through
       assignments and @code{PUSH} and @code{POP} operations.  The initial
       values of the variables are taken from @oparam{Init.defaultPragmas}  *)
  END;


CONST
  alreadyInPragma = 1;
  pragmaNotClosed = 2;
  expectKeyword = 3;
  expectSymbol = 4;
  expectIdent = 5;
  illegalVarName = 6;
  undefinedPragmaVar = 7;
  invalidOperands = 8;
  illegalFactor = 9;
  expectBooleanExpr = 10;
  noOpenIf = 11;
  ifWithoutEnd = 12;
  elseAlreadyPresent = 13;
  pragmaVarAlreadyDefined = 14;
  notAssignmentCompatible = 15;
  unbalancedPop = 16;

TYPE
  ErrorContext = POINTER TO ErrorContextDesc;
  ErrorContextDesc = RECORD  (* stateless *)
    (Error.ContextDesc)
  END;

VAR
  pragmaContext: ErrorContext;


PROCEDURE (context: ErrorContext) GetTemplate* (msg: Error.Msg; VAR templ: Error.LString);
  VAR
    t: ARRAY 128 OF Error.LChar;
  BEGIN
    CASE msg. code OF
    | alreadyInPragma:
      t := "Pragma start delimiter within pragma"
    | pragmaNotClosed:
      t := "Pragma not closed"
    | expectKeyword:
      t := "Expected keyword `${sym_name}'"
    | expectSymbol:
      t := "Expected symbol `${sym_name}'"
    | expectIdent:
      t := "Expected identifier"
    | illegalVarName:
      t := "Illegal variable name"
    | undefinedPragmaVar:
      t := "Undefined pragma variable"
    | invalidOperands:
      t := "Invalid operands"
    | expectBooleanExpr:
      t := "Expected boolean expression"
    | noOpenIf:
      t := "No open `IF' statement"
    | ifWithoutEnd:
      t := "`IF' statement lacks `END'"
    | elseAlreadyPresent:
      t := "`ELSE' part already defined"
    | pragmaVarAlreadyDefined:
      t := "Pragma variable already defined"
    | notAssignmentCompatible:
      t := "Value not assignment compatible to variable"
    | unbalancedPop:
      t := "No values stored on pragma stack"
    END;
    context. BaseTemplate (msg, t, templ)
  END GetTemplate;


PROCEDURE Init* (VAR state: State; builder: Builder.Builder;
                 defaultPragmas: Pragmas.Section);
(* The parameter @oparam{defaultPragmas} is a reference to the configuration
   section that holds the values of pragma variables.  The values listed there
   represent the state of the pragma variables at the beginning of the module
   file.

   @precond
   @oparam{defaultPragmas} and its content must never be changed, or the
   field @ofield{State.variableHistory} will break, that is, it will report
   incorrect values for the pragma variables of the file.  If necessary, use
   @oproc{OOC:Config:Pragmas.Clone} to create a copy of the pragma sections.
   @end precond  *)
  BEGIN
    state. builder := builder;
    state. buffer := builder. inputBuffer;
    state. symList := BasicList.New (builder. inputBuffer, FALSE);
    state. condStack := NIL;
    state. evalText := TRUE;
    state. variableHistory := Pragmas.NewHistory (defaultPragmas);
  END Init;

PROCEDURE ParsePragma (VAR state: State): InputMode;
  TYPE  
    Value = RECORD
      value: ConfigValue.Value;          (* NIL means undefined value *)
      sym: BasicList.Symbol;
    END;
    
  VAR
    dummy, err, nested: BOOLEAN;
    sym, prevSym: BasicList.Symbol;
    lastError: Error.Msg;
  
  PROCEDURE AppendErr (sym: BasicList.Symbol);
    BEGIN
      lastError. SetIntAttrib ("pos", sym. pos);
      lastError. SetIntAttrib ("line", sym. line);
      lastError. SetIntAttrib ("column", sym. column);
      state. buffer. errList. Append (lastError)
    END AppendErr;
  
  PROCEDURE Err (code: Error.Code; sym: BasicList.Symbol);
    BEGIN
      lastError := Error.New (pragmaContext, code);
      AppendErr (sym)
    END Err;

  PROCEDURE CheckName (sym: BasicList.Symbol);
    VAR
      name: InputBuffer.CharArray;
    BEGIN
      name := sym. str;
      IF (name^ = "TRUE") OR (name^ = "FALSE") OR (name^ = "PUSH") OR 
         (name^ = "POP") OR (name^ = "DEFINE") THEN
        Err (illegalVarName, sym)
      END
    END CheckName;
  
  PROCEDURE CheckBoolean (eval: BOOLEAN; VAR value: Value);
    BEGIN
      IF (value. value # NIL) & ~(value. value IS BooleanValue.Value) THEN
        IF eval THEN
          Err (expectBooleanExpr, value. sym)
        END;
        value. value := BooleanValue.New (FALSE)
      END
    END CheckBoolean;
  
  PROCEDURE NextSym;
    BEGIN
      prevSym := sym;
      sym := sym. next
    END NextSym;
  
  PROCEDURE CheckSym (symId: Symbol.Id);
    BEGIN
      IF (sym. id # symId) THEN
        IF Symbol.IsKeyword (symId) THEN
          Err (expectKeyword, sym)
        ELSE
          Err (expectSymbol, sym)
        END;
        lastError. SetStringAttrib ("sym_name", 
                               Msg.GetStringPtr (Symbol.representation[symId]))
      END;
      NextSym
    END CheckSym;
  
  PROCEDURE GetBool (value: Value): BOOLEAN;
    BEGIN
      IF (value. value # NIL) & (value. value IS BooleanValue.Value) THEN
        RETURN value. value(BooleanValue.Value). boolean
      ELSE
        RETURN FALSE
      END
    END GetBool;

  PROCEDURE GetInt (value: Value): IntegerValue.Type;
    BEGIN
      RETURN value. value(IntegerValue.Value). integer
    END GetInt;

  PROCEDURE GetString (value: Value): StringValue.Type;
    BEGIN
      RETURN value. value(StringValue.Value). string
    END GetString;

  PROCEDURE Expression (eval: BOOLEAN; VAR value: Value);
    VAR
      right: Value;
      pos: BasicList.Symbol;
      op: Symbol.Id;
      leftString, rightString: StringValue.Type;
      
    PROCEDURE SimpleExpr (eval: BOOLEAN; VAR value: Value);
      VAR
        right: Value;

      PROCEDURE Term (eval: BOOLEAN; VAR value: Value);
        VAR
          right: Value;
          
        PROCEDURE Factor (eval: BOOLEAN; VAR value: Value);
          VAR
            varValue: ConfigValue.Value;
            int: Integer.Integer;
          BEGIN
            value. value := NIL;
            value. sym := sym;
            CASE sym. id OF
            | Symbol.ident:
              IF (sym. str^ = "FALSE") OR (sym. str^ = "TRUE") THEN
                (* boolean constant *)
                value. value := BooleanValue.New (sym. str^ = "TRUE")
              ELSE                       (* variable *)
                CheckName (sym);
                varValue := state. variableHistory. GetValue (sym. str^, sym. pos);
                IF (varValue # NIL) THEN
                  value. value := varValue
                ELSIF eval THEN
                  Err (undefinedPragmaVar, sym)
                END
              END;
              NextSym
              
            | Symbol.number10:           (* decimal integer const *)
              lastError := Integer.Convert10 (sym. str, int);
              IF (lastError # NIL) THEN
                AppendErr (sym)
              END;
              value. value := IntegerValue.New (int);
              NextSym
              
            | Symbol.number16:           (* hexadecimal integer const *)
              lastError := Integer.Convert16 (sym. str, int);
              IF (lastError # NIL) THEN
                AppendErr (sym)
              END;
              value. value := IntegerValue.New (int);
              NextSym
              
            | Symbol.stringSingle, Symbol.stringDouble: (* string const *)
              value. value := StringValue.New (sym. str^);
              Strings.Delete (value. value(StringValue.Value). string^, 0, 1);
              Strings.Delete (value. value(StringValue.Value). string^, 
               Strings.Length (value. value(StringValue.Value). string^)-1, 1);
              NextSym
              
            | Symbol.lParen:             (* parenthesis *)
              NextSym;
              Expression (eval, value);
              CheckSym (Symbol.rParen)
              
            | Symbol.not:                (* negation *)
              NextSym;
              Expression (eval, value);
              CheckBoolean (eval, value);
              value. value := BooleanValue.New (~GetBool (value))
              
            ELSE
              Err (illegalFactor, sym);  (* factor starts with illegal sym *)
              NextSym
            END
          END Factor;
        
        BEGIN
          Factor (eval, value);
          WHILE (sym. id = Symbol.and) DO
            CheckBoolean (eval, value);
            value. sym := sym;
            NextSym;
            Factor (eval & GetBool (value), right);
            CheckBoolean (eval & GetBool (value), right);
            value. value := BooleanValue.New (GetBool(value) & GetBool(right))
          END
        END Term;
      
      BEGIN
        Term (eval, value);
        WHILE (sym. id = Symbol.or) DO
          CheckBoolean (eval, value);
          value. sym := sym;
          NextSym;
          Term (eval & ~GetBool (value), right);
          CheckBoolean (eval & ~GetBool (value), right);
          value. value := BooleanValue.New (GetBool (value) OR GetBool (right))
        END
      END SimpleExpr;
    
    BEGIN
      SimpleExpr (eval, value);
      IF (Symbol.eql <= sym. id) & (sym. id <= Symbol.geq) THEN
        op := sym. id; pos := sym;
        NextSym;
        SimpleExpr (eval, right);
        IF ~eval OR (value. value = NIL) OR (right. value = NIL) THEN
          (* ignore *)
        ELSIF (RT0.TypeOf (value. value) # RT0.TypeOf (right. value)) OR
              (value. value IS BooleanValue.Value) & 
                (Symbol.lss <= op) & (op <= Symbol.geq) THEN
          Err (invalidOperands, pos)
        ELSIF eval THEN                  (* evaluate comparison *)
          IF (value. value IS BooleanValue.Value) THEN
            CASE op OF
            | Symbol.eql: value. value := 
                BooleanValue.New (GetBool (value) = GetBool (right))
            | Symbol.neq: value. value := 
                BooleanValue.New (GetBool (value) # GetBool (right))
            END
          ELSIF (value. value IS IntegerValue.Value) THEN
            CASE op OF
            | Symbol.eql: value. value :=
                BooleanValue.New (GetInt (value) = GetInt (right))
            | Symbol.neq: value. value :=
                BooleanValue.New (GetInt (value) # GetInt (right))
            | Symbol.lss: value. value :=
                BooleanValue.New (GetInt (value) < GetInt (right))
            | Symbol.leq: value. value :=
                BooleanValue.New (GetInt (value) <= GetInt (right))
            | Symbol.gtr: value. value :=
                BooleanValue.New (GetInt (value) > GetInt (right))
            | Symbol.geq: value. value :=
                BooleanValue.New (GetInt (value) >= GetInt (right))
            END
          ELSIF (value. value IS StringValue.Value) THEN
            leftString := GetString (value);
            rightString := GetString (right);
            CASE op OF
            | Symbol.eql: value. value :=
                BooleanValue.New (leftString^ = rightString^)
            | Symbol.neq: value. value :=
                BooleanValue.New (leftString^ # rightString^)
            | Symbol.lss: value. value :=
                BooleanValue.New (leftString^ < rightString^)
            | Symbol.leq: value. value :=
                BooleanValue.New (leftString^ <= rightString^)
            | Symbol.gtr: value. value :=
                BooleanValue.New (leftString^ > rightString^)
            | Symbol.geq: value. value :=
                BooleanValue.New (leftString^ >= rightString^)
            END
          END
        END;
        value. sym := pos
      END
    END Expression;
  
  PROCEDURE BoolExpression (eval: BOOLEAN): BOOLEAN;
    VAR
      value: Value;
    BEGIN
      Expression (eval, value);
      CheckBoolean (eval, value);
      RETURN GetBool (value)
    END BoolExpression;
  
  PROCEDURE PushCond;
  (* Creates new stack element, pushes it onto `condStack' *)
    VAR
      cond: ConditionStack;
    BEGIN
      NEW (cond);
      cond. prev := state. condStack;
      cond. ifPos := sym;
      cond. skippedCond := ~state. evalText;
      cond. foundTrue := FALSE;
      cond. elsePresent := FALSE;
      state. condStack := cond
    END PushCond;
  
  PROCEDURE PopCond;
    BEGIN
      state. condStack := state. condStack. prev
    END PopCond;

  PROCEDURE CheckForIf (noElse: BOOLEAN);
  (* Checks that an IF statement is opened.  If `noElse=TRUE', then it is also
     checked that no ELSE part is present.  *)
    BEGIN
      IF (state. condStack = NIL) THEN
        Err (noOpenIf, sym);
        PushCond
      ELSIF noElse & state. condStack. elsePresent THEN
        Err (elseAlreadyPresent, sym);
        PushCond
      END
    END CheckForIf;
  
  PROCEDURE Assignment (define, eval: BOOLEAN);
  (* define=TRUE: defining assignment, eval=TRUE: execute assignment *)
    VAR
      name: BasicList.Symbol;
      value: Value;
      pos: BasicList.Symbol;
      varValue: ConfigValue.Value;
    BEGIN
      IF (sym. id = Symbol.ident) THEN
        IF eval THEN
          varValue := state. variableHistory. GetValue (sym. str^, sym. pos);
          pos := sym;
          CheckName (sym);
          name := sym;
          IF (varValue = NIL) & ~define THEN
            Err (undefinedPragmaVar, sym)
          ELSIF (varValue # NIL) & define THEN
            Err (pragmaVarAlreadyDefined, sym)
          END;
          NextSym;
          CheckSym (Symbol.becomes);
          Expression (eval, value);
          
          IF (value. value # NIL) THEN
            IF (varValue = NIL) THEN
              state. variableHistory. SetValue (name. str^, name. pos, value. value)
            ELSE
              WITH varValue: BooleanValue.Value DO
                err := ~(value. value IS BooleanValue.Value)
              | varValue: IntegerValue.Value DO
                err := ~(value. value IS IntegerValue.Value)
              | varValue: StringValue.Value DO
                err := ~(value. value IS StringValue.Value)
              END;
              state. variableHistory. SetValue (name. str^, name. pos, value. value);
              IF err THEN
                Err (notAssignmentCompatible, value. sym)
              END
            END
          END
        ELSE  (* don't execute, just do syntax check *)
          CheckName (sym);
          NextSym;
          CheckSym (Symbol.becomes);
          Expression (eval, value)
        END
      ELSE
        Err (expectIdent, sym)
      END
    END Assignment;
  
  BEGIN  (* pre: symbol before `state.symList.head' is "<*",
                 last element of `state.symList' is "*>" *) 
    lastError := NIL;
    prevSym := NIL;
    sym := state. symList. head;
    
    LOOP
      nested := (sym. id = Symbol.if) OR
                (sym. id = Symbol.elsif) OR
                (sym. id = Symbol.else);
      IF (sym. id = Symbol.if) OR (sym. id = Symbol.elsif) THEN
        IF (sym. id = Symbol.if) THEN
          PushCond
        ELSE  (* (sym. id = Symbol.elsif) *)
          CheckForIf (TRUE)
        END;
        NextSym;
        IF state. condStack. skippedCond OR state. condStack. foundTrue THEN
          (* only do syntax check on guard *)
          dummy := BoolExpression (FALSE);
          state. evalText := FALSE
        ELSE                           (* evaluate guard *)
          state. condStack. foundTrue := BoolExpression (TRUE);
          state. evalText := state. condStack. foundTrue
        END;
        CheckSym (Symbol.then)
      ELSIF (sym. id = Symbol.else) THEN
        CheckForIf (TRUE);
        state. condStack. elsePresent := TRUE;
        NextSym;
        state. evalText := ~state. condStack. skippedCond & 
                           ~state. condStack.foundTrue
      ELSIF (sym. id = Symbol.end) THEN
        CheckForIf (FALSE);
        state. evalText := ~state. condStack. skippedCond;
        PopCond;  (* remove top of stack *)
        NextSym
      ELSIF (sym. id = Symbol.ident) & (sym. str^ = "DEFINE") THEN
        NextSym;
        Assignment (TRUE, state. evalText)
      ELSIF (sym. id = Symbol.ident) & (sym. str^ = "PUSH") THEN
        IF state. evalText THEN
          state. variableHistory. Push
        END;
        NextSym
      ELSIF (sym. id = Symbol.ident) & (sym. str^ = "POP") THEN
        IF state. evalText THEN
          IF (state. variableHistory. numPushes = 0) THEN
            Err (unbalancedPop, sym)
          ELSE
            state. variableHistory. Pop (sym. pos)
          END
        END;
        NextSym
      ELSIF (sym. id = Symbol.ident) THEN
        Assignment (FALSE, state. evalText)
      END;
      IF (sym. id = Symbol.semicolon) THEN
        NextSym
      ELSIF (sym. id # Symbol.end) &
            ((sym. id = Symbol.pragmaEnd) OR ~nested) THEN
        EXIT
      END
    END;
    CheckSym (Symbol.pragmaEnd);
    
    IF state. evalText THEN
      RETURN inputText
    ELSE
      RETURN inputSkippedText
    END
  END ParsePragma;

PROCEDURE AddSymbol* (VAR state: State; VAR inputMode: InputMode;
                      id: Symbol.Id; cstart, cend: InputBuffer.CharPos;
                      line, column: LONGINT);
  VAR
    lastError: Error.Msg;
    
  PROCEDURE Err (code: Error.Code);
    BEGIN
      lastError := Error.New (pragmaContext, code);
      lastError. SetIntAttrib ("pos", cstart+state. buffer. offsetFromPos0);
      lastError. SetIntAttrib ("line", line);
      lastError. SetIntAttrib ("column", column);
      state. buffer. errList. Append (lastError)
    END Err;
  
  PROCEDURE ErrSym (code: Error.Code; sym: BasicList.Symbol);
    BEGIN
      lastError := Error.New (pragmaContext, code);
      lastError. SetIntAttrib ("pos", sym. pos);
      lastError. SetIntAttrib ("line", sym. line);
      lastError. SetIntAttrib ("column", sym. column);
      state. buffer. errList. Append (lastError)
    END ErrSym;
  
  PROCEDURE EndOfPragma;
    BEGIN
      state. builder. AddSymbol (Symbol.pragma, state. startCharPos, cend,
                                 state. startLine, state. startColumn)
    END EndOfPragma;
  
  PROCEDURE EndOfFile;
    BEGIN
      Err (pragmaNotClosed);
      lastError. SetIntAttrib ("pos", state. startAbsPos);
      lastError. SetIntAttrib ("line", state. startLine);
      lastError. SetIntAttrib ("column", state. startColumn);
      EndOfPragma;
      state. builder. AddSymbol (id, cstart, cend, line, column)
    END EndOfFile;
  
  BEGIN
    CASE inputMode OF
    | inputText:
      CASE id OF
      | Symbol.pragmaStart:
        inputMode := inputPragma;
        state. startCharPos := cstart;
        state. startAbsPos := cstart+state. buffer. offsetFromPos0;
        state. startLine := line;
        state. startColumn := column
      | Symbol.endOfFile:
        IF (state. condStack # NIL) THEN
          ErrSym (ifWithoutEnd, state. condStack. ifPos)
        END;
        state. builder. AddSymbol(Symbol.endOfFile, cstart, cend, line, column)
      END
      
    | inputPragma:
      CASE id OF
      | Symbol.pragmaStart:
        Err (alreadyInPragma)
      | Symbol.pragmaEnd:
        state. symList. AddSymbol (id, cstart, cend, line, column);
        inputMode := ParsePragma (state);
        IF (inputMode = inputText) THEN
          EndOfPragma
        END;
        state. symList. Clear
      | Symbol.endOfFile:
        EndOfFile
      ELSE  (* add symbol to pragma sequence *)
        state. symList. AddSymbol (id, cstart, cend, line, column)
      END
      
    | inputSkippedText:
      CASE id OF
      | Symbol.pragmaStart:
        inputMode := inputPragma
      | Symbol.pragmaEnd:
        (* this error case is already handled by the scanner *)
      | Symbol.endOfFile:
        EndOfFile
      ELSE
        (* skip all symbols upto end of file or start of next pragma *)
      END
    END
  END AddSymbol;

BEGIN
  NEW (pragmaContext);
  Error.InitContext (pragmaContext, "OOC:Scanner:Pragma");
END OOC:Scanner:Pragma.
