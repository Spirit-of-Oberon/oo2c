MODULE OOC:Doc:Input:Texinfo;
<* Warnings := FALSE *>

IMPORT
  Ascii, CharClass, Out, Msg, Channel, TextRider, StdChannels, Strings,
  OOC:Error, OOC:Scanner:InputBuffer, OOC:Scanner, 
  OOC:Scanner:Builder:BasicList, OOC:Doc, OOC:Doc:Decoration,
  OOC:Doc:TextBuffer;


TYPE
  Id = SHORTINT;

CONST
  (* Class 1: Non-alphabetic commands.  These commands never take any 
              argument.  They are never followed by braces.  *)
  class1Low = 0;
  cmdAtGlyph = class1Low+0;
  cmdLeftBrace = class1Low+1;
  cmdRightBrace = class1Low+2;
  class1High = cmdRightBrace;
  
  (* Class 2: Alphabetic commands that do not require arguments.  These 
              commands start with @ followed by a word followed by left-
              and right-hand braces.  *)
  class2Low = class1High+1;
  cmdBullet = class2Low+0;
  cmdDots = class2Low+1;
  cmdMinus = class2Low+2;
  cmdResult = class2Low+3;
  class2High = cmdResult;
  
  (* Class 3: Alphabetic commands that require arguments within braces.
             These commands start with @ followed by a letter or a word,
             followed by an argument within braces.  *)
  class3Low = class2High+1;
  cmdAsIs = class3Low+0;
  cmdCite = class3Low+1;
  cmdCode = class3Low+2;
  cmdDfn = class3Low+3;
  cmdEmph = class3Low+4;
  cmdFile = class3Low+5;
  cmdKbd = class3Low+6;
  cmdSamp = class3Low+7;
  cmdStrong = class3Low+8;
  cmdUrl = class3Low+9;
  cmdVar = class3Low+10;
  cmdOberonModule = class3Low+11;
  cmdOberonConst = class3Low+12;
  cmdOberonField = class3Low+13;
  cmdOberonParam = class3Low+14;
  cmdOberonProc = class3Low+15;
  cmdOberonType = class3Low+16;
  cmdOberonVar = class3Low+17;
  cmdEmail = class3Low+18;
  cmdUref = class3Low+19;
  class3High = cmdUref;
  class3Args = cmdEmail;  (* marks the beginning of multi argument commands *)
  
  (* Class 4: Alphabetic commands that occupy an entire line.
              These commands occupy an entire line.  The line starts with @,
              followed by the name of the command (a word).  If no argument
              is needed, the word is followed by the end of the line.  If 
              there is an argument, it is separated from the command name by
              a space.  Braces are not used.  *)
  class4Low = class3High+1;
  cmdExample = class4Low+0;
  cmdItemize = class4Low+1;
  cmdNoIndent = class4Low+2;
  cmdPreCond = class4Low+3;
  cmdPostCond = class4Low+4;
  cmdTable = class4Low+5;
  (* the following commands are only valid _inside_ certain blocks: *)
  cmdEnd = class4Low+6;
  cmdItem = class4Low+7;
  cmdItemX = class4Low+8;
  class4High = cmdItemX;
  
  (* miscellaneous commands that do not start with @, but nevertheless
     have an effect on the output *)
  cmdUnknown = class4High+1;             (* used for unknown command names *)
  cmdEmDash = class4High+2;              (* --- *)
  cmdLeftQuot = class4High+3;            (* `` *)
  cmdRightQuot = class4High+4;           (* '' *)
  cmdText = class4High+5;
  cmdOpeningBrace = class4High+6;
  cmdClosingBrace = class4High+7;
  cmdArgSeparator = class4High+8;
  cmdEndOfText = class4High+9;



TYPE
  Command = POINTER TO CommandDesc;
  CommandDesc = RECORD
    id: Id;
    class: SHORTINT;
    name: ARRAY 16 OF CHAR;
    argLow, argHigh: SHORTINT;
  END;

TYPE
  Token = POINTER TO TokenDesc;
  TokenDesc = RECORD
    next: Token;
    bol: BOOLEAN;                        (* beginning of line *)
    id: Id;                              (* one of the cmdXXX *)
    pos: InputBuffer.CharPos;
    line, column: LONGINT;
    str: Doc.String;
  END;

VAR
  class1: ARRAY 256 OF SHORTINT;
  cmdList: ARRAY class4High+1 OF Command;
  emptyString: Doc.String;



CONST
  unknownCommand = 1;
  expectedLeftBrace = 2;
  expectedRightBrace = 3;
  junkAfterText = 4;
  junkAtEndOfLine = 5;
  invalidItemMark = 6;
  notAtBeginningOfLine = 7;
  expectedEnd = 8;
  lonelyLeftBrace = 9;
  lonelyRightBrace = 10;
  wrongNumberOfArgs = 11;
  expectedMarkupCommand = 12;
  
TYPE
  ErrorContext = POINTER TO ErrorContextDesc;
  ErrorContextDesc = RECORD  (* stateless *)
    (Error.ContextDesc)
  END;

VAR
  texinfoContext: ErrorContext;


PROCEDURE (context: ErrorContext) GetTemplate* (msg: Error.Msg; VAR templ: Error.LString);
  VAR
    t: ARRAY 128 OF Error.LChar;
  BEGIN
    CASE msg. code OF
    | unknownCommand:
      t := "Unknown Texinfo command name `@${name}'"
    | expectedLeftBrace:
      t := "Expected argument delimiter `{'"
    | expectedRightBrace:
      t := "Expected argument delimiter `}'"
    | junkAfterText:
      t := "Junk after end of text"
    | junkAtEndOfLine:
      t := "Junk at end of line"
    | invalidItemMark:
      t := "Expected item mark"
    | notAtBeginningOfLine:
      t := "This command must stand at the beginning of the line"
    | expectedEnd:
      t := "Expected command `@end ${name}'"
    | lonelyLeftBrace:
      t := "Found `{' outside of a command"
    | lonelyRightBrace:
      t := "Found `}' outside of a command"
    | wrongNumberOfArgs:
      t := "Command `@${name}' requires ${minimum} arguments"
    | expectedMarkupCommand:
      t := "Require markup command after `@table'"
    END;
    context. BaseTemplate (msg, t, templ)
  END GetTemplate;


PROCEDURE Tokenize (sym: BasicList.Symbol; str: Decoration.String;
                    errList: Error.List): Token;
(* Tokenizes the Texinfo string in `str' and returns a list of tokens.
   Result is NIL if an error was found.  *)
  VAR
    pos, startPos, startColumn, currLine, currLinePos, currLineTab: LONGINT;
    i, len: LONGINT;
    name: ARRAY 16 OF CHAR;
    lastError: Error.Msg;
    tokenList, tokenTail: Token;
    beginningOfLine: BOOLEAN;
    
  PROCEDURE Err (code: Error.Code);
    BEGIN
      lastError := Error.New (texinfoContext, code);
      lastError. SetIntAttrib ("pos", sym. pos+startPos);
      lastError. SetIntAttrib ("line", currLine);
      lastError. SetIntAttrib ("column", startColumn);
      errList. Append (lastError)
(***)
    END Err;
  
  PROCEDURE Append (t: Token);
    BEGIN
      t. next := NIL;
      IF (tokenList = NIL) THEN
        tokenList := t
      ELSE
        tokenTail. next := t
      END;
      tokenTail := t
    END Append;
  
  PROCEDURE InitToken (t: Token; id: LONGINT);
    BEGIN
      t. next := NIL;
      t. id := SHORT (SHORT (id));
      t. pos := sym. pos+startPos;
      t. line := currLine;
      t. column := startColumn;
      t. bol := beginningOfLine;
      t. str := NIL
    END InitToken;
  
  PROCEDURE AddToken (id: LONGINT);
    VAR
      t: Token;
    BEGIN
      NEW (t);
      InitToken (t, id);
      Append (t);
      beginningOfLine := FALSE
    END AddToken;
  
  PROCEDURE AddText;
    VAR
      t: Token;
      j: LONGINT;
    BEGIN  (* pre: str[pos] is no valid text character *)
      NEW (t);
      InitToken (t, cmdText);
      Append (t);
      beginningOfLine := FALSE;
      
      NEW (t. str, pos-startPos+1);
      FOR j := startPos TO pos-1 DO
        t.str[j-startPos] := str[j]
      END;
      t. str[pos-startPos] := 0X
    END AddText;
  
  PROCEDURE LookingAt (pattern: ARRAY OF CHAR): BOOLEAN;
    VAR
      i: LONGINT;
    BEGIN
      i := 0;
      WHILE (pattern[i] # 0X) & (str[pos+i] = pattern[i]) DO
        INC (i)
      END;
      RETURN (pattern[i] = 0X)
    END LookingAt;
  
  PROCEDURE OutOfBandCommand(): BOOLEAN;
    BEGIN
      RETURN LookingAt ("---") OR LookingAt ("``") OR LookingAt ("''")
    END OutOfBandCommand;
  
  
  PROCEDURE IsTextChar (): BOOLEAN;
    BEGIN
      CASE str[pos] OF
      | "@", "{", "}", ",", Ascii.lf, Ascii.cr:
        RETURN FALSE
      ELSE
        RETURN TRUE
      END
    END IsTextChar;
  
  PROCEDURE Newline (incr: LONGINT);
    BEGIN
      INC (pos, incr);
      beginningOfLine := TRUE;
      currLinePos := pos;
      currLineTab := 0;
      INC (currLine)
    END Newline;
    
  PROCEDURE BeginningOfLine (pos: LONGINT): BOOLEAN;
    BEGIN
      WHILE (pos # 0) & 
            ((str[pos-1] = Decoration.removedSpace) OR
             (str[pos-1] = Decoration.removedTab)) DO
        DEC (pos)
      END;
      RETURN (pos = 0) OR (str[pos-1] = Ascii.cr) OR (str[pos-1] = Ascii.lf)
    END BeginningOfLine;
  
  BEGIN
    tokenList := NIL; tokenTail := NIL; pos := 0; beginningOfLine := TRUE;
    currLine := sym. line; currLinePos := -sym. column; currLineTab := 0;
    
    WHILE (str[pos] # 0X) DO
      startPos := pos;
      startColumn := pos-currLinePos+currLineTab;
      CASE str[pos] OF
      | "@":                             (* Texinfo command *)
        INC (pos);
        (* copy command name into `name' *)
        IF CharClass.IsLetter (str[pos]) THEN  (* alphabetic command name *)
          i := 0;
          REPEAT
            IF (i < (LEN (name)-1)) THEN
              name[i] := str[pos];
              INC (i)
            END;
            INC (pos)
          UNTIL ~CharClass.IsLetter (str[pos]);
          len := i;
          name[i] := 0X
        ELSE  (* non-alphabetic command name: a single character *)
          name[0] := str[pos];
          name[1] := 0X;
          len := 1;
          INC (pos)
        END;

        (* ok, I am lazy: linear search for command is not the fastest
           thing to do, if the list of commands gets longer *)
        i := class4High;
        WHILE (i >= 0) & (cmdList[i]. name # name) DO
          DEC (i)
        END;
        IF (i < 0) THEN                  (* error: unknown command *)
          Err (unknownCommand);
          lastError. SetStringAttrib ("name", Msg.GetStringPtr (name));
          i := cmdUnknown
        ELSIF (class4Low <= i) & (i <= class4High) & ~beginningOfLine THEN
          Err (notAtBeginningOfLine)
        END;
        AddToken (i)
      
      | "{":
        AddToken (cmdOpeningBrace);
        INC (pos)
      
      | "}":
        AddToken (cmdClosingBrace);
        INC (pos)
      
      | ",":
        AddToken (cmdArgSeparator);
        INC (pos)
      
      | Ascii.lf:                        (* end of line, Unix style *)
        IF BeginningOfLine (pos) THEN
          AddText                        (* add empty line *)
        END;
        Newline (1)
        
      | Ascii.cr:
        IF BeginningOfLine (pos) THEN
          AddText                        (* add empty line *)
        END;
        IF (str[pos+1] = Ascii.lf) THEN  (* end of line, DOS style *)
          Newline (2)
        ELSE                             (* end of line, Mac style *)
          Newline (1)
        END
      
      | Decoration.removedSpace:         (* ignore former space char *)
        INC (pos)                        
        
      | Decoration.removedTab:           (* ignore former tab char *)
        i := pos-currLinePos+currLineTab;
        INC (currLineTab, Scanner.tabWidth-i MOD Scanner.tabWidth-1);
        INC (pos)
        
      ELSE                               (* some kind of text *)
        IF LookingAt ("---") THEN
          AddToken (cmdEmDash);
          INC (pos, 3)
        ELSIF LookingAt ("``") THEN
          AddToken (cmdLeftQuot);
          INC (pos, 2)
        ELSIF LookingAt ("''") THEN
          AddToken (cmdRightQuot);
          INC (pos, 2)
        ELSE
          WHILE (str[pos] # 0X) & IsTextChar() & ~OutOfBandCommand() DO
            IF (str[pos] = Ascii.ht) THEN  (* horizontal tabulator *)
              i := pos-currLinePos+currLineTab;
              INC (currLineTab, Scanner.tabWidth-i MOD Scanner.tabWidth-1)
            END;
            INC (pos)
          END;
          AddText
        END
      END
    END;
    startPos := pos;
    startColumn := pos-currLinePos+currLineTab;
    AddToken (cmdEndOfText);
    RETURN tokenList;
  END Tokenize;

PROCEDURE WriteTokens (ch: Channel.Channel; t: Token);
  VAR
    w: TextRider.Writer;
    
  PROCEDURE WriteQuoted (w: TextRider.Writer; VAR str: ARRAY OF CHAR; s, e: LONGINT);
    VAR
      last: LONGINT;
    BEGIN
      WHILE (s # e) DO
        last := s;
        WHILE (s # e) &
              (str[s] # "&") & (str[s] # "<") & (str[s] # ">") & 
              (str[s] # 09X) & (str[s] # 0AX) & (str[s] # 0DX) DO
          INC (s)
        END;
        w. byteWriter. WriteBytes (str, last, s-last);
        IF (s # e) THEN
          CASE str[s] OF
          | "&": w. WriteString ("&amp;")
          | "<": w. WriteString ("&lt;")
          | ">": w. WriteString ("&gt;")
          | 09X: w. WriteString ("&#9;")
          | 0AX: w. WriteString ("&#10;")
          | 0DX: w. WriteString ("&#13;")
          END;
          INC (s)
        END
      END
    END WriteQuoted;

  BEGIN
    w := TextRider.ConnectWriter (ch);
    w. WriteString ("<?xml version='1.0' encoding='ISO-8859-1' standalone='yes'?>");
    w. WriteString ("<token-list>");
    w. WriteLn;
    WHILE (t # NIL) DO
      w. WriteString ("  <token id='");
      CASE t. id OF
      | cmdUnknown: w. WriteString ("#unknown")
      | cmdEmDash: w. WriteString ("#---")
      | cmdLeftQuot: w. WriteString ("#``")
      | cmdRightQuot: w. WriteString ("#''")
      | cmdText: w. WriteString ("#text")
      | cmdOpeningBrace: w. WriteString ("#{")
      | cmdClosingBrace: w. WriteString ("#}")
      | cmdArgSeparator: w. WriteString ("#,")
      | cmdEndOfText: w. WriteString ("#end-of-text")
      ELSE
        w. WriteString (cmdList[t. id]. name)
      END;
      IF t. bol THEN
        w. WriteString ("' bol='yes");
      END;
      w. WriteString ("' pos='");
      w. WriteLInt (t. pos, 0);
      w. WriteString ("' line='");
      w. WriteLInt (t. line, 0);
      w. WriteString ("' column='");
      w. WriteLInt (t. column, 0);
      IF (t. str # NIL) THEN
        w. WriteString ("'>");
        WriteQuoted (w, t. str^, 0, Strings.Length (t. str^));
        w. WriteString ("</token>")
      ELSE
        w. WriteString ("'/>")
      END;
      w. WriteLn;
      t := t. next
    END;
    w. WriteString ("</token-list>");
    w. WriteLn
  END WriteTokens;


PROCEDURE Parse* (sym: BasicList.Symbol; removeDecoration: BOOLEAN;
                  errList: Error.List): Doc.Document;
  VAR
    str: Decoration.String;
    lastError: Error.Msg;
    tokenList, token: Token;
    blockList: Doc.BlockElement;
    decoration: Decoration.Decoration;
    document: Doc.Document;
    buffer: TextBuffer.Buffer;
    bufferPos: Doc.Position;
    oldErrors: LONGINT;

  PROCEDURE IsInlineToken (t: Token): BOOLEAN;
    BEGIN
      RETURN (class1Low <= t. id) & (t. id <= class3High) OR
             (cmdUnknown < t. id) & (t. id <= cmdArgSeparator)
    END IsInlineToken;
  
  PROCEDURE IsBlockToken (t: Token): BOOLEAN;
    BEGIN
      RETURN (class4Low <= t. id) & (t. id < cmdEnd)
    END IsBlockToken;
  
  PROCEDURE Err (code: Error.Code);
    BEGIN
      lastError := Error.New (texinfoContext, code);
      lastError. SetIntAttrib ("pos", token. pos);
      lastError. SetIntAttrib ("line", token. line);
      lastError. SetIntAttrib ("column", token. column);
      errList. Append (lastError)
    END Err;
  
  PROCEDURE NextToken;
    BEGIN
      IF (token. id # cmdEndOfText) THEN
        token := token. next
      END
    END NextToken;
  
  PROCEDURE CheckToken (id: Id);
    BEGIN
      IF (id # token. id) THEN
        CASE id OF
        | cmdOpeningBrace:
          Err (expectedLeftBrace)
        | cmdClosingBrace:
          Err (expectedRightBrace)
        | cmdEndOfText:
          Err (junkAfterText)
        END
      END;
      NextToken
    END CheckToken;
  
  PROCEDURE SkipWhitespace;
    PROCEDURE OnlyWS (VAR str: ARRAY OF CHAR): BOOLEAN;
      VAR
        i: LONGINT;
      BEGIN
        i := 0;
        WHILE (str[i] # 0X) & (str[i] <= " ") DO
          INC (i)
        END;
        RETURN (str[i] = 0X)
      END OnlyWS;
    
    BEGIN
      WHILE (token. id = cmdText) & ~token. bol & OnlyWS (token. str^) DO
        token := token. next
      END
    END SkipWhitespace;
  
  PROCEDURE IdToChar (id: Id):CHAR;
    BEGIN
      CASE token. id OF
      | cmdAtGlyph   : RETURN "@"
      | cmdLeftBrace : RETURN "{"
      | cmdRightBrace: RETURN "}"
      END
    END IdToChar;

  PROCEDURE IdToGlyph (id: Id): LONGINT;
    BEGIN
      CASE token. id OF
      | cmdBullet: RETURN Doc.glyphBullet
      | cmdDots  : RETURN Doc.glyphDots
      | cmdMinus : RETURN Doc.glyphMinus
      | cmdResult: RETURN Doc.glyphResult
      END
    END IdToGlyph;

  PROCEDURE IdToMark (id: Id): LONGINT;
    BEGIN
      CASE id OF
      | cmdAsIs: RETURN Doc.markAsIs
      | cmdCite: RETURN Doc.markCite
      | cmdCode: RETURN Doc.markCode
      | cmdDfn: RETURN Doc.markDfn
      | cmdEmph: RETURN Doc.markEmph
      | cmdFile: RETURN Doc.markFile
      | cmdKbd: RETURN Doc.markKbd
      | cmdOberonModule: RETURN Doc.markOberonModule
      | cmdOberonConst: RETURN Doc.markOberonConst
      | cmdOberonField: RETURN Doc.markOberonField
      | cmdOberonParam: RETURN Doc.markOberonParam
      | cmdOberonProc: RETURN Doc.markOberonProc
      | cmdOberonType: RETURN Doc.markOberonType
      | cmdOberonVar: RETURN Doc.markOberonVar
      | cmdSamp: RETURN Doc.markSamp
      | cmdStrong: RETURN Doc.markStrong
      | cmdUrl: RETURN Doc.markUrl
      | cmdVar: RETURN Doc.markVar
      END
    END IdToMark;
  
  PROCEDURE IsOberonRef (mark: LONGINT): BOOLEAN;
    BEGIN
      RETURN (Doc.markOberonModule <= mark) & (mark <= Doc.markOberonVar)
    END IsOberonRef;
  
  PROCEDURE ParseBlockList(): Doc.BlockElement;
    VAR
      list: Doc.BlockList;
      inlineText: Doc.InlineElement;
      noIndent: BOOLEAN;
    
    PROCEDURE ParseInlineList (isArg, ignoreParagraph, exitAfterEOL: BOOLEAN): Doc.InlineElement;
      VAR
        list: Doc.InlineList;
        str2: ARRAY 2 OF CHAR;
        mark: LONGINT;
        inlineText: Doc.InlineElement;
        posToken: Token;
        
      PROCEDURE AddText (str: ARRAY OF CHAR);
        BEGIN  (* pre: current token is the one that produces the
                       test in `str' *)
          IF (buffer. len = 0) THEN
            (* the current token defines the beginning of the text; use its
               position as the text element's position *)
            Doc.SetPosition (bufferPos, token. pos, token. line, token. column)
          END;
          
          buffer. Append (str);
          IF token. next. bol & (buffer. len # 0) THEN
            buffer. AppendEOL
          END
        END AddText;
      
      PROCEDURE FlushBuffer;
        BEGIN
          IF (buffer. len # 0) THEN
            list. Append (Doc.NewText (buffer. str^, bufferPos));
            buffer. Clear
          END
        END FlushBuffer;
      
      PROCEDURE AddInline (i: Doc.InlineElement);
        BEGIN  (* pre: current token is positioned right after the
                       tokens of `i' *)
          FlushBuffer;
          list. Append (i);
          IF token. bol THEN
            buffer. AppendEOL
          END
        END AddInline;
      
      PROCEDURE EndOfArguments (): BOOLEAN;
        BEGIN
          RETURN (token. id = cmdClosingBrace) OR
                 (token. id = cmdEndOfText) OR
                 (class4Low <= token. id) & (token. id <= class4High)
        END EndOfArguments;
      
      PROCEDURE CheckNumOfArgs (id: Id; num: LONGINT);
        BEGIN
          IF (cmdList[id]. argLow > num) THEN
            Err (wrongNumberOfArgs);
            lastError. SetStringAttrib ("name",
                                        Msg.GetStringPtr (cmdList[id]. name));
            lastError. SetIntAttrib ("minimum", cmdList[id]. argLow)
          END
        END CheckNumOfArgs;
      
      PROCEDURE Email (): Doc.Email;
        VAR
          i: LONGINT;
          inlineText, address, displayed: Doc.InlineElement;
        BEGIN
          NextToken;
          CheckToken (cmdOpeningBrace);
          address := NIL; displayed := NIL;
          i := 0;
          WHILE ~EndOfArguments() DO
            IF (i # 0) THEN
              CheckToken (cmdArgSeparator)
            END;
            inlineText := ParseInlineList (TRUE, FALSE, FALSE);
            CASE i OF
            | 0: address := inlineText
            | 1: displayed := inlineText
            ELSE
              Doc.MergeInline (displayed, inlineText)
            END;
            INC (i)
          END;
          CheckNumOfArgs (cmdEmail, i);
          CheckToken (cmdClosingBrace);
          RETURN Doc.NewEmail (address, displayed)
        END Email;
      
      PROCEDURE Uref (): Doc.Uref;
        VAR
          i: LONGINT;
          inlineText, url, text, replacement: Doc.InlineElement;
        BEGIN
          NextToken;
          CheckToken (cmdOpeningBrace);
          url := NIL; text := NIL; replacement := NIL;
          i := 0;
          WHILE ~EndOfArguments() DO
            IF (i # 0) THEN
              CheckToken (cmdArgSeparator)
            END;
            inlineText := ParseInlineList (TRUE, FALSE, FALSE);
            CASE i OF
            | 0: url := inlineText
            | 1: text := inlineText
            | 2: replacement := inlineText
            ELSE
              Doc.MergeInline (replacement, inlineText)
            END;
            INC (i)
          END;
          CheckNumOfArgs (cmdUref, i);
          CheckToken (cmdClosingBrace);
          RETURN Doc.NewUref (url, text, replacement)
        END Uref;
      
      BEGIN
        list := Doc.NewInlineList();
        LOOP
          CASE token. id OF
          | class1Low..class1High:
            str2 := "x";
            str2[0] := IdToChar (token. id);
            AddText (str2);
            NextToken

          | class2Low..class2High:
            AddInline (Doc.NewGlyph (IdToGlyph (token. id)));
            NextToken;
            CheckToken (cmdOpeningBrace);
            CheckToken (cmdClosingBrace)

          | class3Low..class3Args-1:
            FlushBuffer;
            mark := IdToMark (token. id);
            posToken := token;
            NextToken;
            CheckToken (cmdOpeningBrace);
            inlineText := ParseInlineList(FALSE, FALSE, FALSE);
            CheckToken (cmdClosingBrace);
            IF (Doc.markOberonModule <= mark) &
               (mark <= Doc.markOberonVar) THEN
              AddInline (Doc.NewOberonRef (mark, inlineText, NIL));
              Doc.SetPosition (list. tail(Doc.OberonRef). pos,
                               posToken. pos, posToken. line, posToken. column)
            ELSE
              AddInline (Doc.NewMarkedInline (mark, inlineText))
            END
            
          | cmdEmail:
            FlushBuffer;
            AddInline (Email());
          
          | cmdUref:
            FlushBuffer;
            AddInline (Uref());
            
          | cmdEmDash:
            AddInline (Doc.NewGlyph (Doc.glyphEmDash));
            NextToken

          | cmdLeftQuot:
            AddInline (Doc.NewGlyph (Doc.glyphLeftQuot));
            NextToken

          | cmdRightQuot:
            AddInline (Doc.NewGlyph (Doc.glyphRightQuot));
            NextToken

          | cmdText:
            IF (token. str^ = "") & ~ignoreParagraph THEN
              EXIT
            ELSE
              AddText (token. str^);
              NextToken
            END

          | cmdOpeningBrace:
            Err (lonelyLeftBrace);
            NextToken

          | cmdArgSeparator:
            IF isArg THEN
              EXIT
            ELSE
              AddText (",");
              NextToken
            END
          
          ELSE
            EXIT
          END;
          
          IF exitAfterEOL & token. bol THEN
            EXIT
          END
        END;
        FlushBuffer;
        RETURN list. head
      END ParseInlineList;
    
    PROCEDURE AtEmptyLine(): BOOLEAN;
      BEGIN
        RETURN (token. id = cmdText) & (token. str^ = "") OR
               (token. id = cmdEndOfText)
      END AtEmptyLine;
    
    PROCEDURE CheckEnd (id: Id);
      PROCEDURE Substr (VAR string, pattern: ARRAY OF CHAR): BOOLEAN;
        VAR
          found: BOOLEAN;
          pos, i: INTEGER;
        BEGIN
          Strings.FindNext (pattern, string, 0, found, pos);
          IF found THEN
            FOR i := 0 TO pos-1 DO
              IF (string[i] > " ") THEN
                RETURN FALSE
              END
            END;
            i := pos + Strings.Length (pattern);
            WHILE (string[i] # 0X) DO
              IF (string[i] > " ") THEN
                RETURN FALSE
              END;
              INC (i)
            END;
            RETURN TRUE
          ELSE
            RETURN FALSE
          END
        END Substr;
      
      BEGIN
        IF (token. id # cmdEnd) OR
           (token. next # NIL) & token. next. bol THEN
          Err (expectedEnd);
          lastError. SetStringAttrib ("name",
                                      Msg.GetStringPtr (cmdList[id]. name));
        END;
        NextToken;
        IF ~token. bol THEN
          IF (token. id # cmdText) OR
             ~Substr (token. str^, cmdList[id]. name) THEN
            Err (expectedEnd);
            lastError. SetStringAttrib ("name",
                                        Msg.GetStringPtr (cmdList[id]. name))
          END;
          NextToken
        END
      END CheckEnd;
    
    PROCEDURE Itemize (): Doc.Itemize;
      VAR
        mark: Doc.InlineElement;
        text, itemText: Doc.BlockElement;
        itemList: Doc.BlockList;
        textItem: Doc.Item;
        str2: ARRAY 2 OF CHAR;
        padAfter: BOOLEAN;
        pos: Doc.Position;
      BEGIN  (* pre: token. id = cmdItemize *)
        NextToken;
        SkipWhitespace;
        IF token. bol THEN               (* no marker given, use default *)
          mark := Doc.NewGlyph (Doc.glyphBullet)
        ELSE
          Doc.SetPosition (pos, token. pos, token. line, token. column);
          IF (token. id = cmdText) THEN
            mark := Doc.NewText (token. str^, pos)
          ELSIF (class1Low <= token. id) & (token. id <= class1High) THEN
            str2 := "x";
            str2[0] := IdToChar (token. id);
            mark := Doc.NewText (token. str^, pos)
          ELSIF (class2Low <= token. id) & (token. id <= class2High) THEN
            mark := Doc.NewGlyph (IdToGlyph (token. id))
          ELSE
            Err (invalidItemMark);
            mark := Doc.NewGlyph(Doc.glyphBullet);
          END;
          NextToken;
          IF ~token. bol THEN
            Err (junkAtEndOfLine)
          END
        END;
        
        text := ParseBlockList();
        IF (text # NIL) THEN
          textItem := Doc.NewItem (AtEmptyLine(), text)
        ELSE
          textItem := NIL
        END;
        
        itemList := Doc.NewBlockList();
        WHILE (token. id = cmdItem) DO
          NextToken;
          itemText := ParseBlockList();
          itemList. Append (Doc.NewItem (AtEmptyLine(), itemText))
        END;
        CheckEnd (cmdItemize);
        RETURN Doc.NewItemize (AtEmptyLine(), mark, textItem, itemList. head)
      END Itemize;
    
    PROCEDURE Example (): Doc.Example;
      VAR
        inlineText: Doc.InlineElement;
      BEGIN  (* pre: token. id = cmdExample *)
        NextToken;
        SkipWhitespace;
        IF ~token. bol THEN
          Err (junkAtEndOfLine)
        END;
        inlineText := ParseInlineList (FALSE, TRUE, FALSE);
        CheckEnd (cmdExample);
        RETURN Doc.NewExample (AtEmptyLine(), inlineText)
      END Example;
    
    PROCEDURE PCond (): Doc.BlockElement;
      VAR
        inlineText: Doc.InlineElement;
        cmdId: Id;
      BEGIN  (* pre: token. id IN {cmdPreCond, cmdPostCond} *)
        cmdId := token. id;
        NextToken;
        SkipWhitespace;
        IF ~token. bol THEN
          Err (junkAtEndOfLine)
        END;
        blockList := ParseBlockList ();
        CheckEnd (cmdId);
        CASE cmdId OF
        | cmdPreCond:
          RETURN Doc.NewPreCond (AtEmptyLine(), blockList)
        | cmdPostCond:
          RETURN Doc.NewPostCond (AtEmptyLine(), blockList)
        END
      END PCond;
    
    PROCEDURE Table (): Doc.Table;
      VAR
        mark: LONGINT;
        text, itemText, tableEntry: Doc.BlockElement;
        rowList, firstColumnList: Doc.BlockList;
        textItem: Doc.Item;
        first: Doc.MarkedInline;
        str2: ARRAY 2 OF CHAR;
        padAfter: BOOLEAN;
      BEGIN  (* pre: token. id = cmdTable *)
        NextToken;
        SkipWhitespace;
        IF token. bol THEN               (* no marker given, use default *)
          mark := Doc.markAsIs;
          Err (expectedMarkupCommand)
        ELSIF (class3Low <= token. id) & (token. id < class3Args) THEN
          mark := IdToMark (token. id);
          NextToken;
          SkipWhitespace
        ELSE
          mark := Doc.markAsIs;
          Err (expectedMarkupCommand);
          NextToken
        END;
        IF ~token. bol THEN
          Err (junkAtEndOfLine)
        END;
        
        rowList := Doc.NewBlockList();
        WHILE (token. id # cmdEnd) & (token. id # cmdEndOfText) DO
          firstColumnList := Doc.NewBlockList();
          IF (token. id = cmdItem) THEN
            REPEAT
              NextToken;
              IF IsOberonRef (mark) THEN
                first := Doc.NewOberonRef (mark, 
                                     ParseInlineList (FALSE, FALSE, TRUE), NIL)
              ELSE
                first := Doc.NewMarkedInline (mark, 
                                          ParseInlineList (FALSE, FALSE, TRUE))
              END;
              firstColumnList. Append (Doc.NewFirstColumn (FALSE, first))
            UNTIL (token. id # cmdItemX)
          END;
          tableEntry := ParseBlockList();
          rowList. Append (Doc.NewTableRow (FALSE,
            firstColumnList. head, Doc.NewItem (FALSE, tableEntry)))
        END;
        CheckEnd (cmdTable);
        RETURN Doc.NewTable (AtEmptyLine(), rowList. head)
      END Table;
    
    BEGIN
      noIndent := TRUE;
      list := Doc.NewBlockList();
      LOOP
        CASE token. id OF
        | cmdEndOfText:
          EXIT
          
        | cmdClosingBrace:
          Err (lonelyRightBrace);
          NextToken

        | cmdNoIndent:
          noIndent := TRUE;
          NextToken()
          
        | cmdItemize:
          list. Append (Itemize())
        
        | cmdExample:
          list. Append (Example())
        
        | cmdPreCond, cmdPostCond:
          list. Append (PCond())
        
        | cmdTable:
          list. Append (Table())
          
        ELSE                             (* paragraph block *)
          IF (token. id = cmdText) & (token. str^ = "") THEN
            (* paragraph separator *)
            NextToken
          ELSIF ~IsInlineToken (token) THEN
            EXIT
          ELSE
            inlineText := ParseInlineList (FALSE, FALSE, FALSE);
            list. Append (Doc.NewParagraph (AtEmptyLine(), inlineText,
                                            noIndent));
            noIndent := FALSE
          END;
        END
      END;
      RETURN list. head
    END ParseBlockList;
  
  BEGIN
    buffer := TextBuffer.New();
    IF removeDecoration THEN
      str := Decoration.Remove (sym, decoration)
    ELSE
      str := sym. str;
      decoration := NIL
    END;
    oldErrors := errList. msgCount;
    tokenList := Tokenize (sym, str, errList);
    (*WriteTokens (StdChannels.stdout, tokenList);*)

    IF (errList. msgCount = oldErrors) THEN
      (* parse list of tokens *)
      token := tokenList;
      blockList := ParseBlockList();
      CheckToken (cmdEndOfText);
      document := Doc.NewDocument (blockList, decoration, sym. column);
      document. Normalize;
      RETURN document
    ELSE
      RETURN NIL
    END
  END Parse;

PROCEDURE Init;
  VAR
    i: LONGINT;

  PROCEDURE Register (cmdId: LONGINT; name: ARRAY OF CHAR);
    BEGIN
      IF (cmdList[cmdId]. class = -1) THEN
        CASE cmdId OF
        | class1Low..class1High:
          cmdList[cmdId]. class := 1;
          ASSERT (name[1] = 0X);
          ASSERT (cmdId < MAX (Id));
          class1[ORD (name[0])] := SHORT (SHORT (cmdId))
        | class2Low..class2High:
          cmdList[cmdId]. class := 2
        | class3Low..class3High:
          cmdList[cmdId]. class := 3;
          cmdList[cmdId]. argLow := 1;
          cmdList[cmdId]. argHigh := 1
        | class4Low..class4High:
          cmdList[cmdId]. class := 4
        END;
        COPY (name, cmdList[cmdId]. name);
        ASSERT (name = cmdList[cmdId]. name)
      ELSE
        Out.String ("Module OOC:Doc:Input:Texinfo: Command id ");
        Out.LongInt (cmdId, 0);
        Out.String (" for @");
        Out.String (name);
        Out.String (" already in use by @");
        Out.String (cmdList[cmdId]. name);
        Out.Ln;
        HALT(1)
      END
    END Register;

  PROCEDURE RegisterArgs (cmdId: LONGINT; low, high: SHORTINT);
    BEGIN
      cmdList[cmdId]. argLow := low;
      cmdList[cmdId]. argHigh := high
    END RegisterArgs;

  BEGIN
    FOR i := 0 TO 255 DO
      class1[i] := -1
    END;
    FOR i := 0 TO class4High DO
      NEW (cmdList[i]);
      cmdList[i]. class := -1;
      cmdList[i]. name := "";
      cmdList[i]. argLow := -1;
      cmdList[i]. argHigh := -1
    END;
    NEW (emptyString, 1);
    emptyString[0] := 0X;
    
    (* class 1 *)
    Register (cmdAtGlyph, "@");
    Register (cmdLeftBrace, "{");
    Register (cmdRightBrace, "}");
    (* class 2 *)
    Register (cmdBullet, "bullet");
    Register (cmdDots, "dots");
    Register (cmdMinus, "minus");
    Register (cmdResult, "result");
    (* class 3 *)
    Register (cmdAsIs , "asis");
    Register (cmdCite, "cite");
    Register (cmdCode, "code");
    Register (cmdDfn , "dfn");
    Register (cmdEmail, "email"); RegisterArgs (cmdEmail, 1, 2);
    Register (cmdEmph, "emph");
    Register (cmdFile, "file");
    Register (cmdKbd, "kbd");
    Register (cmdOberonModule, "omodule");
    Register (cmdOberonConst, "oconst");
    Register (cmdOberonField, "ofield");
    Register (cmdOberonParam, "oparam");
    Register (cmdOberonProc, "oproc");
    Register (cmdOberonType, "otype");
    Register (cmdOberonVar, "ovar");
    Register (cmdSamp, "samp");
    Register (cmdStrong, "strong");
    Register (cmdUref, "uref"); RegisterArgs (cmdUref, 1, 3);
    Register (cmdUrl, "url");
    Register (cmdVar, "var");
    (* class 4 *)
    Register (cmdEnd, "end");
    Register (cmdExample, "example");
    Register (cmdItem, "item");
    Register (cmdItemize, "itemize");
    Register (cmdItemX, "itemx");
    Register (cmdNoIndent, "noindent");
    Register (cmdPreCond, "precond");
    Register (cmdPostCond, "postcond");
    Register (cmdTable, "table");
  END Init;

BEGIN
  NEW (texinfoContext);
  Error.InitContext (texinfoContext, "OOC:Doc:Texinfo");
  Init
END OOC:Doc:Input:Texinfo.
