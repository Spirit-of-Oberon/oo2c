(* 	$Id: Error.Mod,v 1.17 2004/04/03 14:40:32 mva Exp $	 *)
MODULE OOC:Error;
(*  Creates lists of error messages and converts them to text.
    Copyright (C) 1999, 2000-2004  Michael van Acken

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
  IO, IO:TextRider, LongStrings, CharClass, M := Msg, Object, OS:Path;
  
  
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
    noError: BOOLEAN;
    (* if TRUE, then the list is either empty or contains only warnings *)
  END;

CONST
  styleFileLineColumn* = 0;
  styleCharPos* = 1;
  styleAttributes* = 2;
  
VAR
  style*: SHORTINT;
  minErrorDistance*: LONGINT;
  (**If an error message's position is less than this number of characters
     before or after an existing error message, then it is silently discarded.
     By default, this is @samp{0}, which means that no messages
     are thrown away.  *)
     
CONST
  posAttr = "pos";
  columnAttr = "column";
  lineAttr = "line";
  warningPrefix* = "Warning: ";
  (**All error messages using this prefix are considered warnings.  They do not
     influence compilation, nor do they cause the compiler to terminate with a
     non-zero exit code.  The test for warnings is a bit crude right now,
     because it checks if @samp{": "+warningPrefix} appears somewhere in the
     error message's template string.  *)
  
PROCEDURE InitContext* (c: Context; id: M.String);
  BEGIN
    M.InitContext (c, id)
  END InitContext;

PROCEDURE New* (context: Context; code: Code): Msg;
  BEGIN
    RETURN M.New (context, code)
  END New;

PROCEDURE NewList* (fileName: STRING): List;
(**Creates new error list for the file @oparam{fileName}.  *)
  VAR
    list: List;
    chars: Object.CharsLatin1;
  BEGIN
    chars := Path.Encode(fileName);
    
    NEW (list);
    M.InitMsgList (list);
    COPY (chars^, list. fileName);
    list. adjustCharPos := FALSE;
    list. noError := TRUE;
    RETURN list
  END NewList;

PROCEDURE IsWarning (msg: Msg): BOOLEAN;
  VAR
    found: BOOLEAN;
    pos: INTEGER;
    template: ARRAY 128 OF LONGCHAR;
  BEGIN
    msg.context.GetTemplate(msg, template);
    LongStrings.FindNext(warningPrefix, template, 0, found, pos);
    RETURN found;
  END IsWarning;

PROCEDURE (l: List) AppendWarning*(msg: Msg);
  VAR
    oldNoError: BOOLEAN;
  BEGIN
    oldNoError := l.noError;
    l.Append(msg);
    l.noError := oldNoError;
    (* NOTE: l.Append^(msg) should only be called in Append() below *)
  END AppendWarning;

PROCEDURE (l: List) Append* (msg: Msg);
  VAR
    ptr: M.Msg;
    msgPos, ptrPos: M.Attribute;
    isError: BOOLEAN;
  BEGIN
    isError := ~IsWarning(msg);
    IF l.noError & isError THEN
      l.noError := FALSE;
    END;
    
    msgPos := msg.GetAttribute(posAttr);
    IF isError THEN
      ptr := l.msgList;
      WHILE (ptr # NIL) DO
        ptrPos := ptr.GetAttribute(posAttr);
        IF ~IsWarning(ptr) &
           (ptrPos # NIL) &
           (ABS(ptrPos(M.IntAttribute).int - msgPos(M.IntAttribute).int) < 
            minErrorDistance) THEN
          RETURN;
        END;
        ptr := ptr.nextMsg;
      END;
    END;
    l.Append^(msg);
  END Append;

PROCEDURE (l: List) NoErrors*(): BOOLEAN;
  BEGIN
    RETURN l.noError;
  END NoErrors;

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
    IF (style = styleCharPos) THEN
      COPY ("${pos}: ", templ);
      LongStrings.Append (text, templ);
    ELSIF (style = styleFileLineColumn) THEN
      COPY (":${line}:${column}: ", templ);
      LongStrings.Append (text, templ);
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

PROCEDURE (errList: List) Write* (ch: IO.ByteChannel);
(**Writes the list of error messages to the ouput channel @oparam{ch}.  The
   channel must be writable.  The generated list is prefixed by the name
   of the file to which the errors refer.  *)
  VAR
    writer: TextRider.Writer;
    msg: Msg;
    text: ARRAY 8*1024 OF CHAR;
    attrPos, attrLine, attrColumn: M.Attribute;
    lastPos: LONGINT;
    
  PROCEDURE WriteMsg (msg: Msg);
    BEGIN
      msg. GetText (text);
      
      IF errList. adjustCharPos THEN  (* adjust character position *)
        attrPos := msg. GetAttribute (posAttr);
        attrLine := msg. GetAttribute (lineAttr);
        IF (attrPos # NIL) & (attrLine # NIL) THEN
          msg. SetIntAttrib (posAttr, attrPos(M.IntAttribute). int-
                             attrLine(M.IntAttribute). int);
          msg. GetText (text);
          msg. SetIntAttrib (posAttr, attrPos(M.IntAttribute). int)
        END
      END;
      IF (style = styleFileLineColumn) THEN
        (* Increment line and column number by one.  That is, the first
           character of the file is (1,1).  *)
        attrLine := msg. GetAttribute (lineAttr);
        IF (attrLine # NIL) THEN
          msg. SetIntAttrib (lineAttr, attrLine(M.IntAttribute). int+1);
        END;
        attrColumn := msg. GetAttribute (columnAttr);
        IF (attrColumn # NIL) & (attrLine # NIL) THEN
          msg. SetIntAttrib (columnAttr, attrColumn(M.IntAttribute). int+1);
        END;
        msg. GetText (text);

        IF (attrLine # NIL) & (attrColumn # NIL) THEN
          writer. WriteString (errList. fileName);
        END;
      END;
      writer. WriteString (text);
      writer. WriteLn;
    END WriteMsg;

  PROCEDURE GetNext (VAR lastPos: LONGINT): Msg;
    VAR
      msg, best: Msg;
      bestPos: LONGINT;
      pos: M.Attribute;
    BEGIN
      best := NIL;
      bestPos := -1;
      msg := errList. msgList;
      WHILE (msg # NIL) DO
        pos := msg.GetAttribute(posAttr);
        IF (pos # NIL) & (pos(M.IntAttribute).int >= lastPos) &
           ((best = NIL) OR (pos(M.IntAttribute).int < bestPos)) THEN
          best := msg;
          bestPos := pos(M.IntAttribute).int;
        END;
        msg := msg. nextMsg
      END;
      lastPos := bestPos;
      RETURN best;
    END GetNext;
  
  BEGIN
    writer := TextRider.ConnectWriter (ch);
    ASSERT (writer # NIL);
    
    IF (errList. fileName # "") & (style # styleFileLineColumn) THEN
      writer. WriteString ("In file ");
      writer. WriteString (errList. fileName);
      writer. WriteString (": ");
      writer. WriteLn
    END;

    (* first, write out all errors that have no position attribute *)
    msg := errList. msgList;
    WHILE (msg # NIL) DO
      attrPos := msg.GetAttribute(posAttr);
      IF (attrPos = NIL) THEN
        WriteMsg (msg);
      END;
      msg := msg. nextMsg
    END;
    
    (* second, write sorted list of all errors withs position *)
    lastPos := -1;
    LOOP
      msg := GetNext(lastPos);
      IF (msg = NIL) THEN
        EXIT;
      ELSE
        WriteMsg (msg);
        msg.SetIntAttrib(posAttr, -2);   (* mark as written *)
      END;
    END;
  END Write;

BEGIN
  style := styleAttributes;
  minErrorDistance := 0;
END OOC:Error.
