(* 	$Id$	 *)
MODULE OOC:Error;
(*  Creates lists of error messages and converts them to text.
    Copyright (C) 1999, 2000, 2001  Michael van Acken

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
  Channel, TextRider, LongStrings, CharClass, M := Msg;
  
  
TYPE
  Msg* = M.Msg;
  Code* = M.Code;
  Char* = M.Char;
  LChar* = M.LChar;
  String* = M.String;
  StringPtr* = M.StringPtr;
  LString* = M.LString;
  LStringPtr* = M.LStringPtr;
  
TYPE
  Context* = POINTER TO ContextDesc;
  ContextDesc* = RECORD
    (M.ContextDesc)
  END;

TYPE
  List* = POINTER TO ListDesc;
  ListDesc = RECORD
    (M.MsgListDesc)
    fileName-: ARRAY 256 OF CHAR;
    (**Any error messages appended to this list refer to the source text
       obtained from this file name.  It is prefixed to the output when
       writing the list of error messages to the output channel.  *)
    adjustCharPos: BOOLEAN;
    (* if TRUE, then subtract the line number from the character position *)
  END;

VAR
  oo2cStyleErrors*: BOOLEAN;


PROCEDURE InitContext* (c: Context; id: M.String);
  BEGIN
    M.InitContext (c, id)
  END InitContext;

PROCEDURE New* (context: Context; code: Code): Msg;
  BEGIN
    RETURN M.New (context, code)
  END New;

PROCEDURE NewList* (fileName: ARRAY OF CHAR): List;
(**Creates new error list for the file @oparam{fileName}.  *)
  VAR
    list: List;
  BEGIN
    NEW (list);
    M.InitMsgList (list);
    COPY (fileName, list. fileName);
    list. adjustCharPos := FALSE;
    RETURN list
  END NewList;


PROCEDURE (c: Context) BaseTemplate* (msg: Msg; text: LString; VAR templ: LString);
(**Creates the default error description for message @oparam{msg}.  The
   argument @oparam{text} holds the readable description of the error code
   @samp{msg.code}.  For debugging purposes, all attributes defined for the
   message @oparam{msg} are attached to the template string using the pattern
   @samp{foo=$@{foo@}}.  *)
  VAR
    attr: M.Attribute;
    repl: ARRAY 8*1024 OF M.LChar;
  BEGIN
    IF oo2cStyleErrors THEN
      COPY ("${pos}:100 ", templ);
      LongStrings.Append (text, templ)
    ELSE
      COPY (text, templ);
      COPY (CharClass.eol, repl);
      LongStrings.Append (repl, templ);
      attr := msg. attribList;
      WHILE (attr # NIL) DO
        COPY (attr. name^, repl);
        LongStrings.Append (repl, templ);
        LongStrings.Append ("=${", templ);
        LongStrings.Append (repl, templ);
        LongStrings.Append ("}", templ);
        COPY (CharClass.eol, repl);
        LongStrings.Append (repl, templ);
        attr := attr. nextAttrib
      END
    END
  END BaseTemplate;

PROCEDURE (errList: List) SetAdjustCharPos* (adjust: BOOLEAN);
(**If set to @code{TRUE}, then decrement the character position reported in a
   error message by the number of lines.  This has the effect that CR/LF
   character pairs, the end of line symbol under DOS based systems, are counted
   as a single character.  This has the effect that editors that count likewise
   display error positions correctly.  *)
  BEGIN
    errList. adjustCharPos := adjust
  END SetAdjustCharPos;

PROCEDURE (errList: List) Write* (ch: Channel.Channel);
(**Writes the list of error messages to the ouput channel @oparam{ch}.  The
   channel must be writable.  The generated list is prefixed by the name
   of the file to which the errors refer.  *)
  VAR
    writer: TextRider.Writer;
    msg: Msg;
    text: ARRAY 8*1024 OF CHAR;
    attrPos, attrLine: M.Attribute;
  BEGIN
    writer := TextRider.ConnectWriter (ch);
    ASSERT (writer # NIL);
    
    IF (errList. fileName # "") THEN
      writer. WriteString ("In file ");
      writer. WriteString (errList. fileName);
      writer. WriteString (": ");
      writer. WriteLn
    END;
    
    msg := errList. msgList;
    WHILE (msg # NIL) DO
      msg. GetText (text);
      
      IF errList. adjustCharPos THEN  (* adjust character position *)
        attrPos := msg. GetAttribute ("pos");
        attrLine := msg. GetAttribute ("line");
        IF (attrPos # NIL) & (attrLine # NIL) THEN
          msg. SetIntAttrib ("pos", attrPos(M.IntAttribute). int-
                                    attrLine(M.IntAttribute). int);
          msg. GetText (text);
          msg. SetIntAttrib ("pos", attrPos(M.IntAttribute). int)
        END
      END;
      writer. WriteString (text);
      writer. WriteLn;
      msg := msg. nextMsg
    END
  END Write;

BEGIN
  oo2cStyleErrors := FALSE
END OOC:Error.
