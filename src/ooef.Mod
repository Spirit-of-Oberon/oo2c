(* 	$Id: ooef.Mod,v 1.9 2004/04/01 20:36:12 mva Exp $	 *)
MODULE ooef;  
(*  Filter to convert error messages emitted by oo2c into other formats.
    Copyright (C) 1995-1999, 2002, 2003, 2004  Michael van Acken

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
  In, Out, Str := Strings, IntConv, Channel, Files, Ascii,
  CharClass, IntStr, Object, IO:StdChannels, 
  CfgData := Config, Config:Section:Options,
  OOC:Config, OOC:Config:CCompiler, E := OOC:Error, OOC:Repository;

CONST
  eol = CharClass.eol;
  tab = 8;                              (* tab stop position *)
  context = 0;                          (* display error in context *)
  lineOnly = 1;                         (* display as file:line:message *)
  lineColumn = 2;                       (* display as file:line,col:message *)
  
CONST
  sizePath = 256;
  sizeErrText = 100;

TYPE 
  Filename = ARRAY sizePath OF CHAR;
  Error = POINTER TO ErrorDesc;
  FileInfo = POINTER TO FileInfoDesc;
  ErrorDesc = RECORD 
    next: Error;
    pos: LONGINT;
    text: ARRAY sizeErrText OF CHAR
  END;
  FileInfoDesc = RECORD 
    next: FileInfo;
    name: Filename;
    errList: Error
  END;

VAR
  cfgErrList: E.List;
  files, active: FileInfo;
  fileBuffer: POINTER TO ARRAY OF CHAR;
  bufferSize, errorPos: LONGINT;
  dummy: Repository.URIBuffer;
  
  echoErrors: BOOLEAN;                  (* echo errors while scanning them *)
  echoText: BOOLEAN;                    (* echo all non-error messages *)
  mode: Options.Option;                 (* contect, lineOnly, lineColumn *)
  help: Options.Option;

  leadContext: LONGINT;                 (* context lines before error *)
  trailContext: LONGINT;                (* context lines behind error *)
  connContext: LONGINT;                 (* connect context less/equal that many lines apart *)
  
PROCEDURE Match (pat, s: ARRAY OF CHAR): BOOLEAN;
(* Returns TRUE if the string in s matches the string in pat.
   The pattern may contain any number of the wild characters '*' and '?'
   '?' matches any single character
   '*' matches any sequence of characters (including a zero length sequence)
   E.g. '*.?' will match any string with two or more characters if it's second
   last character is '.'. *)
  VAR
    lenSource,
    lenPattern: INTEGER;

   PROCEDURE RecMatch(VAR src: ARRAY OF CHAR; posSrc: INTEGER;
                      VAR pat: ARRAY OF CHAR; posPat: INTEGER): BOOLEAN;
     (* src = to be tested ,    posSrc = position in src *)
     (* pat = pattern to match, posPat = position in pat *)
     VAR
       i: INTEGER;
     BEGIN
       LOOP
         IF (posSrc = lenSource) & (posPat = lenPattern) THEN
           RETURN TRUE
         ELSIF (posPat = lenPattern) THEN
           RETURN FALSE
         ELSIF (pat[posPat] = "*") THEN
           IF (posPat = lenPattern-1) THEN
             RETURN TRUE
           ELSE
             FOR i := posSrc TO lenSource DO
               IF RecMatch (src, i, pat, posPat+1) THEN
                 RETURN TRUE
               END
             END;
             RETURN FALSE
           END
         ELSIF (pat[posPat] # "?") & (pat[posPat] # src[posSrc]) THEN
           RETURN FALSE
         ELSE
           INC(posSrc); INC(posPat)
         END
       END
     END RecMatch;

  BEGIN
    lenPattern := Str.Length (pat);
    lenSource := Str.Length (s);
    RETURN RecMatch (s, 0, pat, 0)
  END Match;

PROCEDURE ActiveFile (name: ARRAY OF CHAR);
(* Move information block on file `name' to the start of the list `files'. *)
  VAR
    f: FileInfo;
  BEGIN
    (* search for `name' in list of known files *)
    f := files;
    WHILE (f # NIL) & (f. name # name) DO
      f := f. next
    END;
    IF (f = NIL) THEN  (* no `name' in list: add new entry as first element *)
      NEW (f);
      f. next := files;
      COPY (name, f. name);
      f. errList := NIL;
      files := f;
      active := files
    ELSE  (* `name' found *)
      active := f
    END
  END ActiveFile;

PROCEDURE AddError (VAR list: Error; pos: LONGINT; text: ARRAY OF CHAR);
(* Append error message (pos, text) to `list'. *)
  VAR
    err, ptr: Error;
  BEGIN
    NEW (err);
    err. next := NIL;
    err. pos := pos;
    COPY (text, err. text);
    
    IF (list = NIL) THEN
      list := err
    ELSE
      ptr := list;
      WHILE (ptr. next # NIL) DO
        ptr := ptr. next
      END;
      ptr. next := err
    END
  END AddError;

PROCEDURE ScanInput;
(* Scan input for error messages and add them to the data structure in `files'
   respectively `files.errList'. *)
  VAR
    i: INTEGER;
    ch: CHAR;
    str, text: ARRAY 1024 OF CHAR;
    number: ARRAY 16 OF CHAR;
    filename: Filename;
    
  PROCEDURE Ln;
    BEGIN
      (* only do a newline if the input stream contained one *)
      IF In.Done() & (ch = eol) THEN
        Out.Ln
      END
    END Ln;
    
  BEGIN
    WHILE In.Done() DO
      (* read line of text *)
      i := 0;
      LOOP
        In.Char (ch);
        IF ~In.Done() OR (ch = eol) THEN
          EXIT
        ELSIF (i < LEN(str)-1) THEN
          str[i] := ch;
          INC (i)
        END
      END;
      str[i] := 0X;
      (* interpret line str *)
      IF Match ("In file *: ", str) THEN
        (* file that error messages are refering to *)
        IF echoErrors THEN
          Out.String (str);
          Ln
        END;
        Str.Extract (str, 8, Str.Length (str)-10, filename);
        ActiveFile (filename)
      ELSIF Match ("*: *", str) THEN
        (* error message, refering to the file in `files' *)
        IF echoErrors THEN
          Out.String (str);
          Ln
        END;
        (* locate position of first `:' *)
        i := 0;
        WHILE (str[i] # ":") DO
          INC (i)
        END;
        (* extract and convert char number *)
        Str.Extract (str, 0, i, number);
        IF (IntConv.FormatInt (number) = IntConv.strAllRight) & 
           (active # NIL) THEN
          (* add (number, text) to error list of file `active' *)
          Str.Extract (str, i+1, Str.Length (str)-i-1, text);
          AddError (active. errList, IntConv.ValueInt (number), text)
        ELSIF echoText THEN
          (* no leading number, text ignored *)
          Out.String (str);
          Ln
        END
      ELSIF echoText THEN
        (* additional text, ignored *)
        Out.String (str);
        Ln
      END
    END
  END ScanInput;

PROCEDURE SortErrors;
(* Reverse list of files and sort error messages with increasing file 
   position. *)
  VAR
    f, next: FileInfo;
    newList, e: Error;
    
  PROCEDURE RemLargestPos (VAR list: Error; max: LONGINT): Error;
  (* If `list' contains an error message whose position is greater/equal to
     `max', remove the largest position from `list' and return it.  Otherwise 
     return NIL. *)
    VAR
      e: Error;
    BEGIN
      IF (list = NIL) THEN
        RETURN NIL
      ELSE
        IF (list. pos >= max) THEN
          e := RemLargestPos (list. next, list. pos);
          IF (e = NIL) THEN
            e := list;
            list := list. next
          END;
          RETURN e
        ELSE
          RETURN RemLargestPos (list. next, max)
        END
      END
    END RemLargestPos;
    
  BEGIN
    f := NIL;
    WHILE (files # NIL) DO
      next := files. next;
      files. next := f;
      f := files;
      files := next
    END;
    files := f;
    
    f := files;
    WHILE (f # NIL) DO    
      newList := NIL;
      WHILE (f. errList # NIL) DO
        e := RemLargestPos (f. errList, MIN (LONGINT));
        e. next := newList;
        newList := e
      END;
      f. errList := newList;
      f := f. next
    END
  END SortErrors;
  
PROCEDURE PrintErrors;
(* Write error messages to stdout.  Format is determined by `mode'. *)
  VAR
    f: FileInfo;
    e: Error;
    fileSize, scanPos, lineStart, lastPos, col, i: LONGINT;
    scanLine: LONGINT;
    file: Files.File;
    reader: Channel.Reader;
    res: Files.Result;

  PROCEDURE CountLines (start, end: LONGINT): LONGINT;
  (* Count newline characters in the intervall [start..end[. *)
    VAR
      count: LONGINT;
    BEGIN
      count := 0;
      WHILE (start < end) DO
        IF (fileBuffer[start] = eol) THEN
          INC (count)
        END;
        INC (start)
      END;
      RETURN count
    END CountLines;
  
  PROCEDURE SkipLines (pos, n: LONGINT): LONGINT;
  (* Return position of n-th previous (n<0) or n-th following line.  For
     n=0 result is the beginning of the current line.  Lines skipped may be
     less than demanded if the end (or beginning) of the file is reached 
     first. *)
    BEGIN
      IF (n <= 0) THEN
        WHILE (pos > 0) DO
          IF (fileBuffer[pos-1] = eol) THEN
            IF (n = 0) THEN
              RETURN pos
            ELSE
              INC (n)
            END
          END;
          DEC (pos)
        END;
        RETURN 0
      ELSE
        WHILE (pos < fileSize) DO
          IF (fileBuffer[pos] = eol) THEN
            IF (n = 1) THEN
              RETURN pos+1
            ELSE
              DEC (n)
            END
          END;
          INC (pos)
        END;
        RETURN fileSize
      END
    END SkipLines;
  
  PROCEDURE PrintText (start, end: LONGINT);
  (* Print text in intervall [start..end[.  Add a newline if end=fileSize, 
     end>start, fileBuffer[end-1]#eol. *)
    VAR
      i: LONGINT;
    BEGIN
      i := start;
      WHILE (i < end) DO
        Out.Char (fileBuffer[i]);
        INC (i)
      END;
      IF (end = fileSize) & (start < end) & (fileBuffer[end-1] # eol) THEN
        Out.Char (eol)
      END
    END PrintText;

  PROCEDURE Column (pos: LONGINT): LONGINT;
  (* Calculate column of file position `pos'.  `lineStart' is the starting
     position of the current line, no newline characters allow in 
     [lineStart..pos[.  Tab stops are `tab' apart.  1 is the rightmost 
     column. *)
    VAR
      p, c: LONGINT;
    BEGIN
      p := lineStart;
      c := 0;
      WHILE (p < pos) DO
        IF (fileBuffer[p] = Ascii.ht) THEN
          c := c+tab-c MOD tab
        ELSE
          INC (c)
        END;
        INC (p)
      END;
      RETURN c+1
    END Column;
    
  BEGIN
    f := files;
    WHILE (f # NIL) DO
      (* write header for context output *)
      IF (mode.value(CfgData.IntegerVar).integer = context) THEN
        IF (f # files) THEN
          Out.String ("###############################################################################"); Out.Ln
        END;
        Out.String ("In file ");
        Out.String (f. name);
        Out.String (":");
        Out.Ln
      END;
      
      (* read file `f.name' into `fileBuffer' *)
      IF Files.Exists (f. name) THEN
        file := Files.Old (f. name, {Files.read}, res);
        IF file = NIL THEN
          Out.String ("Error: Can't open file ");
          Out.String (f. name);
          Out.Ln;
          RETURN
        END;
        reader := file. NewReader();
        fileSize := file. Length();
        IF (fileSize > bufferSize) THEN
          NEW (fileBuffer, fileSize);
          bufferSize := fileSize
        END;
        reader. ReadBytes (fileBuffer^, 0, fileSize);
        IF (reader. res # Files.done) THEN
          Out.String ("Error: Error while reading from ");
          Out.String (f. name);
          Out.Ln;
          RETURN
        END;
        file. Close;
      
        (* print error messages *)
        lastPos := -1;
        lineStart := 0;
        scanPos := 0;
        scanLine := 1;
        e := f. errList;
        WHILE (e # NIL) DO
          (* find line number for error position `e.pos' *)
          WHILE (scanPos < e. pos) DO
            IF (fileBuffer[scanPos] = eol) THEN
              INC (scanLine);
              lineStart := scanPos+1
            END;
            INC (scanPos)
          END;
          IF (mode.value(CfgData.IntegerVar).integer = context) THEN  
            (* display lines of source code around error *)
            IF (lastPos >= 0) & (CountLines (lastPos, scanPos)-1 <= 
                                   leadContext+trailContext+connContext) THEN
              (* print all lines between last and current error plus the 
                 current line *)
              PrintText (SkipLines (lastPos, 1), SkipLines (scanPos, 1))
            ELSE
              IF (lastPos >= 0) THEN  (* print context behind last error *)
                PrintText (SkipLines (lastPos, 1), 
                           SkipLines (lastPos, trailContext+1));
                Out.Ln;
                Out.String ("...");
                Out.Ln;
                Out.Ln
              END;
              (* print context before current error plus the current line *)
              PrintText (SkipLines (scanPos, -leadContext), 
                         SkipLines (scanPos, 1))
            END;
            (* write error marker and error message *)
            IF (lastPos # scanPos) THEN
              col := Column (e. pos);
              i := 1;
              WHILE (i < col) DO
                IF (i <= 1) THEN
                  Out.Char ("#")
                ELSE
                  Out.Char ("-")
                END;
                INC (i)
              END;
              Out.Char ("^");
              Out.Ln
            END;
            Out.String ("# ");
            Out.LongInt (scanLine, 0);
            Out.String (": ");
            Out.String (e. text);
            Out.Ln;
            lastPos := scanPos
          ELSIF (mode.value(CfgData.IntegerVar).integer >= lineOnly) THEN
            Out.String (f. name);
            Out.Char (":");
            Out.LongInt (scanLine, 0);
            IF (mode.value(CfgData.IntegerVar).integer = lineColumn) THEN
              Out.Char (",");
              Out.LongInt (Column (e. pos), 0)
            END;
            Out.Char (":");
            Out.String (e. text);
            Out.Ln
          END;
          e := e. next
        END;
        IF (mode.value(CfgData.IntegerVar).integer = context) THEN
          (* add trailing context lines of last error message *)
          PrintText (SkipLines (lastPos, 1), 
                     SkipLines (lastPos, 1+trailContext))
        END
      END;        
      f := f. next
    END
  END PrintErrors;

PROCEDURE TranslateArgs (VAR file: ARRAY OF CHAR; VAR pos: LONGINT): BOOLEAN;
  VAR
    arg: STRING;
    str8: Object.String8;
    chars: Object.CharsLatin1;
    res: IntStr.ConvResults;
  BEGIN
    arg := Config.arguments.Get(0);
    str8 := arg.ToString8("?");
    chars := str8.CharsLatin1();
    IF ~Files.Exists(chars^) THEN
      Out.String ("Error: Cannot find file ");
      Out.Object (arg);
      Out.Ln;
      RETURN FALSE
    ELSE
      COPY(chars^, file);
      arg := Config.arguments.Get(1);
      str8 := arg.ToString8("?");
      chars := str8.CharsLatin1();
      IntStr.StrToInt (chars^, pos, res);
      IF (res # IntStr.strAllRight) OR (pos < 0) THEN
        Out.String ("Error: Invalid file position ");
        Out.LongInt (pos, 0);
        Out.Ln;
        RETURN FALSE
      ELSE
        RETURN TRUE
      END
    END
  END TranslateArgs;

PROCEDURE WriteHelp;
  BEGIN
    Out.String ("Usage: oo2c --error-style char-pos ... | ooef [option]"); Out.Ln;
    Out.String ("       ooef [option] <module> <pos>"); Out.Ln;
    Out.String ("Options: "); Out.Ln;
    Out.String ("--context, -c   Print errors in source text context (default)."); Out.Ln;
    Out.String ("--line, -l      Print errors in the format `file:line:error'."); Out.Ln;
    Out.String ("--linecol, -L   Print errors in the format `file:line,column:error'."); Out.Ln;
    Out.String ("--help, -h      Write this text and exit."); Out.Ln;
  END WriteHelp;

PROCEDURE NewConfig;
  BEGIN
    mode := Config.AddOption("errorFormat", CfgData.NewIntegerVar(context));
    Config.AddCmdLine("--context,-c",
                      "<options><set name='errorFormat'>0</set></options>");
    Config.AddCmdLine("--line,-l",
                      "<options><set name='errorFormat'>1</set></options>");
    Config.AddCmdLine("--linecol,-L",
                      "<options><set name='errorFormat'>2</set></options>");

    Config.AddRepositoryListEnv();
    Config.AddCmdLine("--repository,-r",
                 "<repositories><file-system>$1</file-system></repositories>");
    
    help := Config.AddOption("help", CfgData.NewBooleanVar(FALSE));
    Config.AddCmdLine("-h,--help",
                      "<options><set name='help'>TRUE</set></options>");
    
    CCompiler.RegisterConfig;  (* make oo2c options known *)
  END NewConfig;

BEGIN
  files := NIL;
  active := NIL;
  fileBuffer := NIL;
  bufferSize := -1;
  echoErrors := FALSE;
  echoText := TRUE;
  leadContext := 3;
  trailContext := 3;
  connContext := 3;

  cfgErrList := E.NewList("");
  NewConfig;
  Config.Read(cfgErrList);
  
  IF (cfgErrList. msgCount # 0) THEN
    cfgErrList. Write (StdChannels.stderr);
  END;
  IF ~cfgErrList.NoErrors() THEN
    HALT (1)
  ELSIF help.value(CfgData.BooleanVar).boolean OR
        ((Config.arguments.ArgNumber() # 0) &
         (Config.arguments.ArgNumber() # 2)) THEN
    WriteHelp
  ELSIF (Config.arguments.ArgNumber() = 2) THEN
    IF TranslateArgs (dummy, errorPos) THEN
      ActiveFile (dummy);
      AddError (active. errList, errorPos, "");
      PrintErrors
    END
  ELSE
    ScanInput;
    SortErrors;
    PrintErrors
  END
END ooef.
