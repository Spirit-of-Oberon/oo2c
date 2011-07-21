(* 	$Id: Error.Mod,v 1.5 2003/06/01 19:44:56 mva Exp $	 *)
MODULE XML:Error;
(*  Creates lists of error messages and converts them to text.
    Copyright (C) 2000, 2001, 2003  Michael van Acken

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
  Ascii, Strings,Channel, TextRider, LongStrings, M := Msg,
  Object, IO, OS:ProcessParameters, URI, URI:Scheme:File;
  
  
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
  Mapping* = POINTER TO MappingDesc;
  MappingDesc = RECORD
    next: Mapping;
    code: Code;
    text: LStringPtr;
  END;

TYPE
  Context* = POINTER TO ContextDesc;
  ContextDesc* = RECORD
    (M.ContextDesc)
    mapping: Mapping;
  END;

TYPE
  List* = POINTER TO ListDesc;
  ListDesc = RECORD
    (M.MsgListDesc)
    cwdURI: URI.HierarchicalURI;
  END;


VAR
  errMsgLineBase*: LONGINT;
  (**Line number used to refer to the first line in a file in an error message.
     The default is @samp{0}.  Most programs count lines beginning at @samp{1},
     so you might want to change this before calling the XML parser.  *)
  errMsgColumnBase*: LONGINT;
  (**Column number used to refer to the first character of a line in an error
     message.  The default is @samp{0}.  *)
  errMsgCharPosBase*: LONGINT;
  (**Character position used to refer to the first character of a file in an
     error message.  The default is @samp{0}.  *)


PROCEDURE InitContext* (c: Context; id: M.String);
  BEGIN
    M.InitContext (c, id);
    c. mapping := NIL
  END InitContext;

PROCEDURE NewContext* (id: M.String): Context;
(**Creates a new error context, using the id @oparam{id}.  @oparam{id} should
   be a module name.  *)
  VAR
    c: Context;
  BEGIN
    NEW (c);
    InitContext (c, id);
    RETURN c
  END NewContext;

PROCEDURE (context: Context) WriteTemplate* (msg: M.Msg; msgText: M.LString; VAR templ: M.LString);
  VAR
    entityName: M.Attribute;
  CONST
    eol = Ascii.lf;
  BEGIN
    entityName := msg. GetAttribute ("entity_name");
    IF (entityName = NIL) THEN
      COPY ("", templ)
    ELSE
      COPY ("While expanding entity `", templ);
      LongStrings.Append (entityName(M.LStringAttribute). string^, templ);
      LongStrings.Append ("': ", templ)
    END;
    
    LongStrings.Append (msgText, templ);
    LongStrings.Insert ("line=${line}, column=${column}"+eol+
                        "${char}: ", 0, templ);
  END WriteTemplate;

PROCEDURE (context: Context) GetTemplate* (msg: Msg; VAR templ: LString);
  VAR
    m: Mapping;
  BEGIN
    m := context. mapping;
    WHILE (m # NIL) & (m. code # msg. code) DO
      m := m. next
    END;
    IF (m # NIL) THEN
      context. WriteTemplate (msg, m. text^, templ)
    ELSE
      context. WriteTemplate (msg, "--unknown error code; msg_context=${MSG_CONTEXT}; msg_code=${MSG_CODE}--", templ)
    END
  END GetTemplate;

PROCEDURE (context: Context) SetString* (code: Code; str: String);
(**Maps the error code @oparam{code} onto the error text @oparam{str}.  If a
   mapping for @oparam{code} exists, it is replaced with the new one.  *)
  PROCEDURE Append (VAR mlist: Mapping);
    VAR
      str16: ARRAY 1024 OF M.LChar;
    BEGIN
      IF (mlist = NIL) THEN
        NEW (mlist);
        mlist. next := NIL;
        mlist. code := code;
        COPY (str, str16);
        mlist. text := M.GetLStringPtr (str16)
      ELSIF (mlist. code = code) THEN
        COPY (str, str16);
        mlist. text := M.GetLStringPtr (str16)
      ELSE
        Append (mlist. next)
      END
    END Append;
  
  BEGIN
    Append (context. mapping)
  END SetString;

PROCEDURE New* (context: Context; code: Code): Msg;
  BEGIN
    RETURN M.New (context, code)
  END New;

PROCEDURE NewList*(): List;
(**Creates new error list.  *)
  VAR
    list: List;
  BEGIN
    NEW (list);
    M.InitMsgList (list);
    list. cwdURI := File.GetCwd();
    RETURN list
  END NewList;


PROCEDURE (errList: List) Write* (ch: Channel.Channel);
(**Writes the list of error messages to the ouput channel @oparam{ch}.  The
   channel must be writable.  The generated list is prefixed by the name
   of the file to which the errors refer.  File names relative to the current
   working directory are rewritten to relative path names, using the list's
   `cwdURI' as base.  *)
  VAR
    writer: TextRider.Writer;
    msg, prev: Msg;
    text: ARRAY 8*1024 OF CHAR;
    uriAttr: M.Attribute;
    uri, prevURI: M.StringPtr;
    repl1, repl2: ARRAY 1024 OF CHAR;
    len: LONGINT;
    cwd: STRING;

  PROCEDURE Replace (VAR text: ARRAY OF CHAR; pattern, repl: ARRAY OF CHAR);
    VAR
      pos: INTEGER;
      found: BOOLEAN;
    BEGIN
      Strings.FindNext (pattern, text, 0, found, pos);
      WHILE found DO
        Strings.Delete (text, pos, Strings.Length (pattern));
        Strings.Insert (repl, pos, text);
        INC (pos, Strings.Length (repl));
        Strings.FindNext (pattern, text, pos, found, pos)
      END
    END Replace;
  
  PROCEDURE DistanceOk (m0, m1: M.Msg): BOOLEAN;
    VAR
      p0, p1: M.Attribute;
    BEGIN
      IF (m0 = NIL) THEN
        RETURN TRUE
      ELSE
        p0 := m0. GetAttribute ("char");
        p1 := m1. GetAttribute ("char");
        IF (p0 # NIL) & (p1 # NIL) &
           (p0 IS M.IntAttribute) &
           (p1 IS M.IntAttribute) &
           (ABS (p0(M.IntAttribute). int - p1(M.IntAttribute). int) < 16) THEN
          RETURN FALSE
        ELSE
          RETURN TRUE
        END
      END
    END DistanceOk;

  PROCEDURE Copy(s: STRING; VAR str: ARRAY OF CHAR);
    VAR
      s8: Object.String8;
      chars: Object.CharsLatin1;
    BEGIN
      s8 := s.ToString8("?");
      chars := s8.CharsLatin1();
      COPY(chars^, str);
    END Copy;
  
  BEGIN
    writer := TextRider.ConnectWriter (ch);
    ASSERT (writer # NIL);

    Copy(errList.cwdURI.ToString(), repl1);
    Copy(errList.cwdURI(File.URI).GetPath(), repl2);
    Strings.Insert ("file_name=", 0, repl2);
    
    prev := NIL; prevURI := NIL;
    msg := errList. msgList;
    WHILE (msg # NIL) DO
      IF DistanceOk (prev, msg) THEN
        uriAttr := msg. GetAttribute ("baseURI");
        IF (uriAttr(M.StringAttribute).string # prevURI) THEN
          uri := uriAttr(M.StringAttribute).string;
          COPY(uriAttr(M.StringAttribute).string^, text);
          TRY
            cwd := "file://"+ProcessParameters.GetCwd()+"/";
            len := Strings.Length(text);
            IF (cwd.length < len) &
               cwd.Equals(Object.NewLatin1Region(text, 0, cwd.length)) THEN
              Strings.Delete(text, 0, SHORT(cwd.length));
            END;
          CATCH IO.Error:
            (* ignore *)
          END;
          
          writer. WriteString ("In file ");
          writer. WriteString (text);
          writer. WriteString (": ");
          writer. WriteLn
        END;
        prevURI := uriAttr(M.StringAttribute).string;
        
        msg. GetText (text);
        Replace (text, repl1, "file:");
        Replace (text, repl2, "file_name=");
        writer. WriteString (text);
        writer. WriteLn;
        prev := msg
      END;
      msg := msg. nextMsg
    END
  END Write;

BEGIN
  URI.RegisterScheme(File.NewPrototype());
  errMsgLineBase := 0; errMsgColumnBase := 0; errMsgCharPosBase := 0;
END XML:Error.
