(* 	$Id: CmdLine.Mod,v 1.5 2003/05/17 18:52:17 mva Exp $	 *)
MODULE Config:Source:CmdLine;
(*  Command line parser for OOC's configuration system.
    Copyright (C) 2000, 2003  Michael van Acken

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
  Object, CharClass, Strings, LongStrings, Msg, Channel, TextRider,
  IO, Writer := IO:TextRider,
  Config:Source, Config:Parser;

CONST
  maxLenArgument = 2*1024;

TYPE
  OptionTemplate* = POINTER TO OptionTemplateDesc;
  NameArray = POINTER TO ARRAY OF Object.String8;
  OptionTemplateDesc = RECORD
    next: OptionTemplate;
    names: NameArray;
    argNumber: LONGINT;
    pattern: Object.String8;
  END;

TYPE
  Command*= POINTER TO CommandDesc;
  ArgList = POINTER TO ARRAY OF Object.String8;
  CommandDesc = RECORD
    (**A command corresponds to a single command line option and its arguments.
       It is converted into an XML text fragment, which describes the result
       of the application of the command line option.  *)
    nextCommand-: Command;
    (**Next command in list @ofield{CmdLine.commandList}.  *)
    template-: OptionTemplate;
    (**Text template, that is used to create the XML fragment.  Any references
       $1, $2, ..., $9 are replaced with the arguments from @ofield{argList}.*)
    argList-: ArgList;
    (**Arguments of the command line option.  If the option has no arguments,
       @samp{LEN(argList^)} is zero.  *)
    doNotWrite-: BOOLEAN;
    (**During @oproc{CmdLine.Write}, do not include the command in the 
       output, if this field is set to @code{TRUE}.  It is @code{FALSE} by
       default, but can be changed to @code{TRUE} with
       @oproc{Command.DoNotWrite}.  *)
  END;

TYPE
  CmdLine* = POINTER TO CmdLineDesc;
  CmdLineDesc = RECORD
    (**This class implements the command line handling of OOC's configuration
       system.  It converts command line options into XML elements.  New option
       formats are registered with @oproc{CmdLine.AddOptionTemplate}.  The
       command line is parsed by @oproc{CmdLine.Parse}.  Use the procedure
       @oproc{CmdLine.Write} to generate the XML elements from a parsed
       command line.  *)
    (Source.SourceDesc)
    optionTemplates: OptionTemplate;
    (* List of all option formals registered with 
       @oproc{CmdLine.AddOptionTemplate}.  *)
    
    enableDashDash: BOOLEAN;
    (* see @oproc{CmdLine.EnableDashDash} *)
    expandToSingleChar: BOOLEAN;
    (* see @oproc{CmdLine.ExpandToSingleChar} *)
    optionsStartWithDash: BOOLEAN;
    (* see @oproc{CmdLine.OptionsStartWithDash} *)
    
    commandList-: Command;
    (* After @oproc{CmdLine.Parse}, this field refers to a list of commands.
       Every command @otype{Command} corresponds to a command line option.  *)
    argumentList: ArgList;
    (* After @oproc{CmdLine.Parse}, this field holds the non-option arguments
       from the command line.  If there are no such arguments, 
       @samp{LEN(argumentList^)} is zero.  Note: If the command line could
       not be parsed successfully, this field is @code{NIL}.  *)
  END;


CONST
  connectFailed = 1;
  junkAfterEnd = 2;
  readError = 3;
  unknownOption = 4;
  singleCharWithArgs = 5;
  expectArguments = 6;
  
TYPE
  ErrorContext = POINTER TO ErrorContextDesc;
  ErrorContextDesc = RECORD  (* stateless *)
    (Msg.ContextDesc)
  END;

VAR
  cmdLineContext: ErrorContext;

PROCEDURE (context: ErrorContext) GetTemplate* (msg: Msg.Msg; 
                                                VAR templ: Msg.LString);
  VAR
    t: ARRAY 128 OF Msg.LChar;
  BEGIN
    CASE msg. code OF
    | connectFailed:
      t := "Failed to connect reader to program arguments"
    | junkAfterEnd:
      t := "Junk after last command line argument"
    | readError:
      t := "Error while reading command line arguments";
      LongStrings.Append (CharClass.eol, t);
      LongStrings.Append ("  Reason: ${reason}", t)
    | unknownOption:
      t := "Unknown command line option `${string}'"
    | singleCharWithArgs:
      t := "Option `${string}' needs ${number} argument(s) and must stand for its own"
    | expectArguments:
      t := "Option `${string}' requires ${number} parameter(s)"
    END;
    COPY (t, templ)
  END GetTemplate;

PROCEDURE Error (code: Msg.Code): Msg.Msg;
  VAR
    err: Msg.Msg;
  BEGIN
    err := Msg.New (cmdLineContext, code);
    RETURN err
  END Error;

PROCEDURE ErrorReason (code: Msg.Code; reason: Msg.Msg): Msg.Msg;
  VAR
    err: Msg.Msg;
  BEGIN
    err := Msg.New (cmdLineContext, code);
    err. SetMsgAttrib ("reason", reason);
    RETURN err
  END ErrorReason;

PROCEDURE ErrorString (code: Msg.Code; string: Object.String8): Msg.Msg;
  VAR
    err: Msg.Msg;
    chars: Object.CharsLatin1;
  BEGIN
    err := Msg.New (cmdLineContext, code);
    chars := string.CharsLatin1();
    err. SetStringAttrib ("string", Msg.GetStringPtr (chars^));
    RETURN err
  END ErrorString;

PROCEDURE ErrorStringNum (code: Msg.Code; string: Object.String8;
                          number: LONGINT): Msg.Msg;
  VAR
    err: Msg.Msg;
    chars: Object.CharsLatin1;
  BEGIN
    err := Msg.New (cmdLineContext, code);
    chars := string.CharsLatin1();
    err. SetStringAttrib ("string", Msg.GetStringPtr (chars^));
    err. SetIntAttrib ("number", number);
    RETURN err
  END ErrorStringNum;


PROCEDURE (command: Command) DoNotWrite*;
(**Remove the command @oparam{command} from the output of
   @oproc{CmdLine.Write}.  *)
  BEGIN
    command. doNotWrite := TRUE
  END DoNotWrite;


PROCEDURE Init (cmdLine: CmdLine);
  BEGIN
    Source.Init (cmdLine);
    cmdLine. optionTemplates := NIL;
    cmdLine. enableDashDash := TRUE;
    cmdLine. expandToSingleChar := TRUE;
    cmdLine. optionsStartWithDash := TRUE;
    
    cmdLine. commandList := NIL;
    cmdLine. argumentList := NIL;
  END Init;

PROCEDURE New* (): CmdLine;
(**Creates new instance of @otype{CmdLine}, using the default settings.  *)
  VAR
    cmdLine: CmdLine;
  BEGIN
    NEW (cmdLine);
    Init (cmdLine);
    RETURN cmdLine
  END New;

PROCEDURE (cmdLine: CmdLine) AddOptionTemplate* (names: ARRAY OF CHAR;
                                transformation: ARRAY OF CHAR): OptionTemplate;
(**Registers a command line option for the section under the names listed in
   @oparam{names}.  This arguments is a list of names separated by commas
   @samp{,}.  The names can contain any character but @code{0X} and @samp{,}.
   For example, the string @samp{-f,--flags} would register the command line
   options @samp{-f} and @samp{--flags}.  It is suggested that the option
   names use either the short format, that is, dash followed by some character,
   or the long format, which typically uses two dashes followed by an
   alphanumeric identifier.
   
   The string @oparam{transformation} determines, which XML text fragment 
   is added to the configuration database whenever this option is encountered.
   The transformation can contain argument references @samp{$1}, @samp{$2},
   @dots{}, @samp{$9}.  They are replaced with the first, second, and so on,
   argument following the option name.  There are no restrictions on the
   replacement text, except that it should produce a well-formed XML element.
   
   The function returns a reference to the newly created option template
   object.
   
   If more than one option is registered under the same name, then only the
   first option is considered when parsing command lines.  No error message or
   warning is issued in such a case.
   
   Example:
   
   @example
   t := cmdLine.AddOptionTemplate("-f,--foo", "<set name='foo'>$1</set>");
   
   command line arguments: -f test123
   @result{} <set name='foo'>test123</set>
   command line arguments: --foo test123
   @result{} <set name='foo'>test123</set>
   command line arguments: -f '&'
   @result{} <set name='foo'>&amp;</set>
   
   t := cmdLine.AddOptionTemplate("--xy", "</coord x='$1' y='$2'>");
   
   command line arguments: --xy 0.0 1.0
   @result{} </coord x='0.0' y='1.0'>
   @end example  *)
  VAR
    num: LONGINT;
    i: INTEGER;
    opt: OptionTemplate;
    nameArray: NameArray;
  
  PROCEDURE Append (VAR list: OptionTemplate);
    BEGIN
      IF (list = NIL) THEN
        list := opt
      ELSE
        Append (list. next)
      END
    END Append;

  BEGIN
    NEW (opt);
    opt. next := NIL;
    opt. names := NIL;
    opt. argNumber := 0;
    opt. pattern := Object.NewLatin1(transformation);
    
    (* find out how many parameters follow this option on the command line *)
    i := 0;
    WHILE (transformation[i] # 0X) DO
      IF (transformation[i] = "$") & 
         ("1" <= transformation[i+1]) & (transformation[i+1] <= "9") THEN
        num := ORD (transformation[i+1])-ORD ("0");
        IF (num > 0) & (num > opt. argNumber) THEN
          opt. argNumber := num
        END;
        INC (i, 2)
      ELSE
        INC (i)
      END
    END;
    
    (* for every string in "str1,str2,str3,..." create a new name entry,
       and add it to `cmdLine's name list *)
    num := 1;
    i := 0;
    WHILE (names[i] # 0X) DO
      IF (names[i] = ",") THEN
        INC (num)
      END;
      INC (i)
    END;
    NEW (nameArray, num);
    
    num := 0;
    WHILE (names # "") DO
      i := 0;
      WHILE (names[i] # 0X) & (names[i] # ",") DO
        INC (i)
      END;
      IF (names[i] = 0X) THEN
        nameArray[num] := Object.NewLatin1(names);
        names[0] := 0X
      ELSE
        names[i] := 0X;
        nameArray[num] := Object.NewLatin1(names);
        names[i] := ",";
        Strings.Delete (names, 0, i+1)
      END;
      INC (num)
    END;
    opt. names := nameArray;
    Append (cmdLine. optionTemplates);
    RETURN opt
  END AddOptionTemplate;

PROCEDURE (cmdLine: CmdLine) EnableDashDash* (enable: BOOLEAN);
(**When enabled, then the command line argument @samp{--} ends the list of
   options.  Any further arguments after @samp{--} are treated as non-option
   arguments, even if they look like options.  If this is disabled, @samp{--}
   is treated like any other option or non-option argument.  Default
   is @samp{enable=TRUE}.  *)
  BEGIN
    cmdLine. enableDashDash := enable
  END EnableDashDash;

PROCEDURE (cmdLine: CmdLine) EnableExpandToSingleChar* (enable: BOOLEAN);
(**If this is enabled, and a command line argument of the form @samp{-xyz}
   does no match any known option name, then the argument is interpreted 
   like @samp{-x -y -z}.  The character after the dash must not be a dash
   itself.  Default is @samp{enable=TRUE}.  *)
  BEGIN
    cmdLine. expandToSingleChar := enable
  END EnableExpandToSingleChar;

PROCEDURE (cmdLine: CmdLine) OptionsStartWithDash* (enable: BOOLEAN);
(**If this is enabled, any command line argument that starts with a dash
   @samp{-}, but does not match a registered option name, nor belongs to
   a preceding option, is reported as an error.  Otherwise, it is assumed to
   be the first of the non-option arguments, and option parsing stops at
   its place.  Default is @samp{enabled=TRUE}.  *)
  BEGIN
    cmdLine. optionsStartWithDash := enable
  END OptionsStartWithDash;


PROCEDURE (cmdLine: CmdLine) Parse* (ch: Channel.Channel): Msg.Msg;
(**Parses the command line arguments from channel @oparam{ch} according to
   the option formats and settings of @oparam{cmdLine}, and stores the result
   in @oparam{cmdLine}.  Result is @code{NIL} on success, and a reference to
   an error message on failure.  Typically, the the program argument channeld
   @ovar{*ProgramArgs.args} is passed to the parameter @oparam{ch}.
   
   Using the default settings, the command line arguments are parsed like
   this:
   
   @itemize
   @item
   If an option matches one of the formats registered with
   @oproc{CmdLine.AddOptionTemplate}, it is accepted and the required
   number of arguments following it taken from the input stream.
   
   @item
   If an option is preceded by a single dash, but does not match any 
   registered option, it is treated as a number of single character options.
   Such options cannot have any additional arguments.  (See also
   @oproc{CmdLine.EnableExpandToSingleChar}.)
   
   @item
   If the special command line argument @samp{--} is found, option parsing
   stops and all arguments following it are treated as non-options.  (See also
   @oproc{CmdLine.EnableDashDash}.)
   
   @item
   Any command line option starting with a dash, that fails to be resolved
   by the above rules, will cause an error message.  (See also
   @oproc{CmdLine.OptionsStartWithDash}.)
   
   @item
   The first argument that does not belong to an option, nor begins with a
   dash, is assumed to be the first non-option argument of the command line.
   Any arguments following it are also considered to be non-options.
   @end itemize
   *)
  VAR
    msg: Msg.Msg;
    r: TextRider.Reader;
    argString: ARRAY maxLenArgument OF CHAR;
    numArgs, i, j, restArg: LONGINT;
    argList: ArgList;
    arg, singleOption: Object.String8;
    chars: Object.CharsLatin1;
    cmd: OptionTemplate;
    singleCharCmd: ARRAY 3 OF CHAR;
  
  PROCEDURE Append (VAR arg: ARRAY OF CHAR);
    VAR
      i: LONGINT;
      newList: ArgList;
    BEGIN
      IF (numArgs = LEN (argList^)) THEN
        NEW (newList, LEN (argList^)*2);
        FOR i := 0 TO LEN (argList^)-1 DO
          newList[i] := argList[i]
        END;
        FOR i := LEN (argList^) TO LEN (argList^)*2-1 DO
          newList[i] := NIL
        END;
        argList := newList
      END;

      argList[numArgs] := Object.NewLatin1(arg);
      INC (numArgs)
    END Append;
  
  PROCEDURE FindOptionTemplate (name: Object.String8): OptionTemplate;
    VAR
      o: OptionTemplate;
      i: LONGINT;
    BEGIN
      o := cmdLine. optionTemplates;
      WHILE (o # NIL) DO
        FOR i := 0 TO LEN (o. names^)-1 DO
          IF o.names[i].Equals(name) THEN
            RETURN o
          END
        END;
        o := o. next
      END;
      RETURN NIL
    END FindOptionTemplate;
  
  PROCEDURE EvalOption (argString: Object.String8;
                        cmd: OptionTemplate; VAR optIndex: LONGINT): Msg.Msg;
    VAR
      i: LONGINT;
      command: Command;
    
    PROCEDURE Append (VAR list: Command);
      BEGIN
        IF (list = NIL) THEN
          list := command
        ELSE
          Append (list. nextCommand)
        END
      END Append;
    
    BEGIN
      IF (optIndex+cmd. argNumber >= numArgs) THEN
        RETURN ErrorStringNum (expectArguments, argString, cmd. argNumber)
      ELSE
        NEW (command);
        command. nextCommand := NIL;
        command. template := cmd;
        command. doNotWrite := FALSE;
        NEW (command. argList, cmd. argNumber);
        FOR i := 0 TO cmd. argNumber-1 DO
          command. argList[i] := argList[optIndex+1+i]
        END;
        INC (optIndex, cmd. argNumber);
        Append (cmdLine. commandList);
        RETURN NIL
      END
    END EvalOption;
  
  BEGIN
    numArgs := 0;
    NEW (argList, 8);
    
    (* convert command line arguments into list of strings *)
    r := TextRider.ConnectReader (ch);
    IF (r = NIL) THEN
      RETURN Error (connectFailed);
    ELSE
      WHILE (r. res = Channel.done) DO
        r. ReadLine (argString);
        IF (r. res = Channel.done) THEN
          Append (argString)
        END
      END;
      IF (r. res. code = Channel.readAfterEnd) & (argString[0] # 0X) THEN
        RETURN Error (junkAfterEnd)
      ELSIF (r. res. code # Channel.readAfterEnd) THEN
        RETURN ErrorReason (readError, r. res)
      END
    END;
    
    (* start reading arguments at index 1, the first argument is always
       the command name *)
    restArg := -1;
    i := 1;
    WHILE (i < numArgs) & (restArg < 0) DO
      arg := argList[i];
      
      (* first try to find a perfect match with one command line option *)
      cmd := FindOptionTemplate (arg);
      IF (cmd # NIL) THEN
        msg := EvalOption (arg, cmd, i);
        IF (msg # NIL) THEN
          RETURN msg
        END
      ELSIF cmdLine. enableDashDash & arg.Equals("--") THEN  (* end of options *)
        restArg := i+1
      ELSIF cmdLine. expandToSingleChar & (arg.CharAt(0) = "-") & (arg.CharAt(1) # "-") THEN
        (* interpret argument as multiple single character options without 
           any following parameters *)
        singleCharCmd := "-?";
        chars := arg.CharsLatin1();
        j := 1;
        WHILE (chars[j] # 0X) DO
          singleCharCmd[1] := chars[j];
          singleOption := Object.NewLatin1(singleCharCmd);
          cmd := FindOptionTemplate(singleOption);
          IF (cmd = NIL) THEN
            RETURN ErrorString (unknownOption, singleOption)
          ELSIF (cmd. argNumber # 0) THEN
            RETURN ErrorStringNum (singleCharWithArgs, singleOption,
                                   cmd. argNumber)
          ELSE
            msg := EvalOption (singleOption, cmd, i);
            IF (msg # NIL) THEN
              RETURN msg
            END
          END;
          INC (j)
        END
      ELSIF cmdLine. optionsStartWithDash & (arg.CharAt(0) = "-") THEN
        RETURN ErrorString (unknownOption, arg)
      ELSE  (* unknown option: probably end of list *)
        restArg := i
      END;
      INC (i)
    END;
    
    (* starting with `restArg', all further arguments are not options *)
    IF (restArg < 0) THEN
      restArg := numArgs
    END;
    NEW (cmdLine. argumentList, numArgs-restArg);
    FOR i := restArg TO numArgs-1 DO
      cmdLine. argumentList[i-restArg] := argList[i]
    END;
    
    RETURN NIL
  END Parse;

PROCEDURE (cmdLine: CmdLine) Write* (ch: IO.ByteChannel;
                                     rootTag: Parser.String)
RAISES IO.Error;
(**Writes the parsed command line arguments as a sequence of XML elements to
   the output channel @oparam{ch}.  Options are represented by their
   replacement text, with argument references of the transformation string
   exchanged for the actual argument values.  Non-option arguments are written
   in an XML element @samp{arguments}, with every nested element
   @samp{argument} corresponding to one command line argument.
   
   If the argument @oparam{rootTag} is not empty, the output is placed within
   an element with the name @oparam{rootTag}, and the whole text is prefixed
   by an XML declaration with an appropriate encoding string.
   
   Example:
   
   @example
   t := cmdLine.AddOptionTemplate("-t,--test", "<set name='test'>$1</set>");
   err := cmdLine. Parse (ProgramArgs.args);
   IF (err = NIL) THEN
     cmdLine. Write (StdChannels.stdout, "")
   END
   @end example
   
   @noindent
   When run, the program fragment produces this output:
   
   @example
   # ./TestCmdLine -t argument1 b
   <set name='test'>argument1</set>
   <arguments>
     <arg>b</arg>
   </arguments>

   # ./TestCmdLine foo '&'
   <arguments>
     <arg>foo</arg>
     <arg>&amp;</arg>
   </arguments>
   
   # ./TestCmdLine        
   <arguments>
   </arguments>
   @end example
   
   @precond
   Channel @oparam{ch} is writable.  @oproc{CmdLine.Parse} has been executed
   successfully for @oparam{cmdLine}.
   @end precond *)
  VAR
    w: Writer.Writer;
    i, j: LONGINT;
    command: Command;
    pattern: Object.String8;
    chars: Object.CharsLatin1;
    root8: ARRAY 1024 OF CHAR;
    
  PROCEDURE WriteQuoted (w: Writer.Writer; str: Object.String8);
    VAR
      s, e, last: LONGINT;
      chars: Object.CharsLatin1;
    BEGIN
      chars := str.CharsLatin1();
      s := 0;
      e := str.length;
      WHILE (s # e) DO
        last := s;
        WHILE (s # e) & (chars[s] # "&") &
              (chars[s] # "<") & (chars[s] # ">") &
              (chars[s] # "'") & (chars[s] # '"') DO
          INC (s)
        END;
        w. WriteStringRegion (chars^, last, s);
        IF (s # e) THEN
          CASE chars[s] OF
          | "&": w. WriteString ("&amp;")
          | "<": w. WriteString ("&lt;")
          | ">": w. WriteString ("&gt;")
          | "'": w. WriteString ("&apos;")
          | '"': w. WriteString ("&quot;")
          END;
          INC (s)
        END
      END
    END WriteQuoted;

  BEGIN
    w := Writer.ConnectWriter(ch);
    
    IF (rootTag # "") THEN
      (* don't forget to import the XML codec for the encoding you use! *)
      w. WriteString ("<?xml version='1.0' encoding='ISO-8859-1' standalone='yes'?>");
      w. WriteLn;
      LongStrings.Short (rootTag, "?", root8);
      w. WriteString ("<");
      w. WriteString (root8);
      w. WriteString (">");
      w. WriteLn
    END;
    
    command := cmdLine. commandList;
    WHILE (command # NIL) DO
      IF ~command. doNotWrite THEN
        pattern := command. template. pattern;
        chars := pattern.CharsLatin1();
        i := 0;
        WHILE (chars[i] # 0X) DO
          j := i;
          WHILE (chars[i] # 0X) & (chars[i] # "$") DO
            INC (i)
          END;

          IF (chars[i] = "$") THEN
            IF ("1" <= chars[i+1]) & (chars[i+1] <= "9") THEN
              w. WriteStringRegion(chars^, j, i);
              WriteQuoted (w, command. argList[ORD (chars[i+1])-ORD("1")]);
              INC (i, 2)
            ELSE
              INC (i);
              w. WriteStringRegion(chars^, j, i)
            END
          ELSE
            w. WriteStringRegion(chars^, j, i)
          END
        END;
        w. WriteLn
      END;
      command := command. nextCommand
    END;
    
    w. WriteString ("<arguments>");
    w. WriteLn;
    IF (cmdLine. argumentList # NIL) THEN
      FOR i := 0 TO LEN (cmdLine. argumentList^)-1 DO
        w. WriteString ("  <arg>");
        WriteQuoted (w, cmdLine. argumentList[i]);
        w. WriteString ("</arg>");
        w. WriteLn
      END
    END;
    w. WriteString ("</arguments>");
    w. WriteLn;
    
    IF (rootTag # "") THEN
      w. WriteString ("</");
      w. WriteString (root8);
      w. WriteString (">");
      w. WriteLn
    END;

    IF (w.error # NIL) THEN
      RAISE(w.error);
    END;
  END Write;

BEGIN
  NEW (cmdLineContext);
  Msg.InitContext (cmdLineContext, "Config:Source:CmdLine")
END Config:Source:CmdLine.
