(* 	$Id: XML.Mod,v 1.27 2003/05/31 16:51:53 mva Exp $	 *)
MODULE OOC:SSA:XML;
(*  Produces a canonical representation of SSA code in XML.
    Copyright (C) 2001, 2002, 2003  Michael van Acken

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
  Object, IO, IO:StdChannels, Dictionary := ADT:Dictionary:IntValue, 
  ADT:StringBuffer, WriterXML := XML:Writer, XML:UnicodeCodec:Latin1,
  OOC:SSA:Opcode, OOC:SSA:Result, OOC:SSA:Opnd, OOC:SSA, OOC:SSA:Schedule;


TYPE
  Writer* = POINTER TO WriterDesc;
  WriterDesc* = RECORD
    (WriterXML.WriterDesc)
    sb: StringBuffer.StringBuffer;
    
    idMap: Dictionary.Dictionary;
    (* maps instructions to their numeric id; a negative value means that
       the instruction has not been scheduled for writing yet *)
  END;
  
PROCEDURE InitWriter* (w: Writer; cw: IO.ByteChannel);
  BEGIN
    WriterXML.Init (w, cw, Latin1.factory, TRUE, 2);
    w. sb := StringBuffer.New("");
  END InitWriter;

PROCEDURE NewWriter* (cw: IO.ByteChannel): Writer;
  VAR
    w: Writer;
  BEGIN
    NEW (w);
    InitWriter (w, cw);
    RETURN w
  END NewWriter;

PROCEDURE (w: Writer) WriteInstrAttr* (instr: SSA.Instr);
  BEGIN
  END WriteInstrAttr;

PROCEDURE (w: Writer) WriteInstrChildren* (instr: SSA.Instr);
  BEGIN
  END WriteInstrChildren;

PROCEDURE (w: Writer) GetId (result: SSA.Result): LONGINT;
  BEGIN
    IF w. idMap. HasKey (result) THEN
      RETURN ABS (w. idMap. Get (result))
    ELSE
      RETURN -1
    END;
  END GetId;

PROCEDURE (w: Writer) AttrId* (name: ARRAY OF LONGCHAR; result: SSA.Result);
  VAR
    str: ARRAY 64 OF CHAR;
    res: SSA.Result;
    countSameId, posSameId: LONGINT;
  BEGIN
    w. sb. Delete (0, w. sb. length);
    w. sb. AppendInt (ABS (w. GetId (result. instr)));
    IF (result # result. instr) THEN
      w. sb. AppendLatin1Char (".");
      Result.GetName (result. class, str);
      w. sb. AppendLatin1 (str);
      
      countSameId := 0; posSameId := 0;
      res := result. instr. nextResult;
      REPEAT
        IF (res = result) THEN
          posSameId := countSameId;
        END;
        IF (res. class = result. class) THEN
          INC (countSameId)
        END;
        res := res. nextResult
      UNTIL (res = NIL);
      IF (countSameId # 1) THEN
        w. sb. AppendLatin1Char (".");
        w. sb. AppendInt (posSameId);
      END;
    END;
    w. AttrObject(name, w. sb.ToString());
  END AttrId;

PROCEDURE (w: Writer) AttrRef* (res: SSA.Result);
  VAR
    value: Object.String;
  BEGIN
    IF (res = NIL) THEN
      w. AttrString ("argref", "NIL");
    ELSE
      WITH res: SSA.Const DO
        IF (res. value = SSA.nil) THEN
          value := "NIL";
        ELSE
          value := res. value. ToString();
        END;
        IF (value IS Object.String16) THEN
          w. AttrObject ("const-value", "[Object.String16]");
        ELSE
          w. AttrObject ("const-value", value(Object.String8));
        END;
      | res: SSA.DeclRef DO
        w. AttrStringLatin1 ("declref", res. decl. name. str^);
      | res: SSA.Address DO
        w. AttrStringLatin1 ("address-of", res. decl. name. str^);
      ELSE
        w. AttrId ("argref", res);
      END;
    END;
  END AttrRef;

PROCEDURE Omit (instr: SSA.Instr): BOOLEAN;
  BEGIN
    RETURN instr. IsConst();
  END Omit;

PROCEDURE (w: Writer) WriteInstr (instr: SSA.Instr);
  VAR
    value: Object.String;
    res: SSA.Result;
    opnd: SSA.Opnd;
    
  PROCEDURE StartTagInstr (w: WriterXML.Writer; instr: SSA.Instr);
    VAR
      str: ARRAY 64 OF CHAR;
    BEGIN
      Opcode.GetName (instr. opcode, instr. subclass, str);
      w. StartTagLatin1 (str, FALSE);
    END StartTagInstr;
  
  PROCEDURE WriteResult (res: SSA.Result);
    VAR
      str: ARRAY 64 OF CHAR;
    BEGIN
      w. StartTag ("res", FALSE);
      
      w. AttrId ("id", res);
      
      Result.GetName (res. class, str);
      w. AttrStringLatin1 ("class", str);

      IF (res. subclass # Opcode.scNone) THEN
        Opcode.GetSubclassName (res. subclass, str);
        w. AttrStringLatin1 ("subclass", str);
      END;
      
      w. EndTag;  (* res *)
    END WriteResult;
  
  PROCEDURE WriteOpnd (opnd: SSA.Opnd);
    VAR
      str: ARRAY 64 OF CHAR;
    BEGIN
      w. StartTag ("opnd", FALSE);
      
      Opnd.GetName (opnd. class, str);
      w. AttrStringLatin1 ("class", str);
      w. AttrRef (opnd. arg);
      w. EndTag;  (* opnd *)
    END WriteOpnd;
  
  BEGIN
    IF Omit (instr) THEN
      (* these kinds of instructions are written in a shorthand form:
         their actual value is indicated in the "opnd" tag, and the
         instructions themselves are omitted *)
      RETURN
    END;
    
    StartTagInstr (w, instr);
    w. AttrInt ("id", w. GetId (instr));
    
    WITH instr: SSA.Const DO
      IF (instr. value = SSA.nil) THEN
        value := "NIL";
      ELSE
        value := instr. value. ToString();        
      END;
      w. AttrObject ("value", value(Object.String8));

    | instr: SSA.Address DO
      w. AttrStringLatin1 ("address-of", instr. decl. name. str^);
    ELSE
    END;
    w. WriteInstrAttr (instr);
    
    opnd := instr. opndList;
    WHILE (opnd # NIL) DO
      WriteOpnd (opnd);
      opnd := opnd. nextOpnd
    END;
    
    res := instr. nextResult;
    WHILE (res # NIL) DO
      WriteResult (res);
      res := res. nextResult
    END;
    
    w. WriteInstrChildren (instr);
    w. EndTag;  (* instr *)
  END WriteInstr;

PROCEDURE (w: Writer) WriteProcBody* (pb: SSA.ProcBlock;
                                      includeDeadCode: BOOLEAN)
RAISES IO.Error;
  VAR
    instr: SSA.Instr;
    instrCount: LONGINT;
    
  PROCEDURE AssignId (instr: SSA.Instr);
    VAR
      opnd: SSA.Opnd;
    BEGIN
      IF ~w. idMap. HasKey (instr) THEN
        (* assign ids to all instructions that are referenced in the
           operand list *)
        opnd := instr. opndList;
        WHILE (opnd # NIL) DO
          AssignId (opnd. arg. instr);
          opnd := opnd. nextOpnd
        END;
        
        IF ~Omit (instr) THEN
          w. idMap. Set (instr, -instrCount);
          INC (instrCount);
        END;
        
        opnd := instr. opndList;
        WHILE (opnd # NIL) DO
          AssignId (opnd. arg. instr);
          opnd := opnd. nextOpnd
        END;
      END;
    END AssignId;
    
  PROCEDURE TraverseInstr (instr: SSA.Instr);
    VAR
      opnd: SSA.Opnd;
      backwardFeed: SSA.Result;
      id: LONGINT;
    BEGIN
      IF ~Omit (instr) THEN
        id := w. idMap. Get (instr);
        IF (id < 0) THEN                   (* not yet scheduled? *)
          w. idMap. Set (instr, -id); (* mark as scheduled *)

          IF (instr. opcode = Opcode.loopStart) THEN
            (* for a loop-start instruction, write the input path
               of the loop before the instruction, and the back-edge
               after it *)
            TraverseInstr (instr. opndList. arg. instr);
            w. WriteInstr (instr);
            backwardFeed := instr. GetBackwardFeed();
            TraverseInstr (backwardFeed. instr);
          ELSE
            (* schedule all operands for writing _before_ this instruction *)
            opnd := instr. opndList;
            WHILE (opnd # NIL) DO
              TraverseInstr (opnd. arg. instr);
              opnd := opnd. nextOpnd
            END;
            w. WriteInstr (instr);
          END;
        END;
      END;
    END TraverseInstr;
  
  BEGIN
    w. WriteTextDecl ("1.0", "no");

    (* first pass: assign ids to all instructions reachable from the
       exit instruction; this step skips dead code *)
    w. idMap := Dictionary.New();
    instrCount := 1;
    AssignId (pb. selectReturn);
    
    w. StartTag ("procedure-body", FALSE);
    w. AttrStringLatin1 ("name", pb. procDecl. name. str^);
    TraverseInstr (pb. selectReturn);

    IF includeDeadCode THEN
      (* finally pick up dead code; in the output, these instructions appear
         after the `exit' *)
      instr := pb. instrList;
      WHILE (instr # NIL) DO
        IF ~w. idMap. HasKey (instr) THEN
          AssignId (instr);
          TraverseInstr (instr);
        END;
        instr := instr. nextInstr
      END;
    END;
    w. EndTag;  (* procedure-body *)
    w. EndOfText
  END WriteProcBody;

PROCEDURE Write* (cw: IO.ByteChannel; pb: SSA.ProcBlock;
                  includeDeadCode: BOOLEAN)
RAISES IO.Error;
(**Note: If @oparam{includeDeadCode} is set and the block contains instructions
   that are dead, then the output depends on the order of instructions in the
   blocks instruction list.  Consequently, it is no longer canonical and may
   differ for otherwise equivalent SSA sequences.  *)
  VAR
    w: Writer;
  BEGIN
    w := NewWriter (cw);
    w. WriteProcBody (pb, includeDeadCode);
  END Write;

PROCEDURE ToStderr*(pb: SSA.ProcBlock);
  BEGIN
    TRY
      Write(StdChannels.stderr, pb, TRUE);
    CATCH IO.Error:
    END;
  END ToStderr;

PROCEDURE (w: Writer) WriteSchedule* (domRoot: Schedule.Block)
RAISES IO.Error;
  VAR
    instrCount: LONGINT;
    
  PROCEDURE WriteBlock (b: Schedule.Block);
    VAR
      proxy: Schedule.InstrProxy;
      nested: Schedule.Block;
    BEGIN
      WITH b: Schedule.BranchBlock DO
        w. StartTag ("block-branch", FALSE)
      ELSE
        w. StartTag ("block", FALSE)
      END;
      
      proxy := b. proxyList;
      WHILE (proxy # NIL) DO
        w. WriteInstr (proxy. instr);
        proxy := proxy. nextProxy
      END;

      nested := b. domList;
      WHILE (nested # NIL) DO
        WriteBlock (nested);
        nested := nested. nextDom
      END;

      w. EndTag;  (* block *)
    END WriteBlock;

  PROCEDURE AssignIds (b: Schedule.Block);
    VAR
      proxy: Schedule.InstrProxy;
      nested: Schedule.Block;
    BEGIN
      proxy := b. proxyList;
      WHILE (proxy # NIL) DO
        IF ~Omit (proxy. instr) THEN
          w. idMap. Set (proxy. instr, instrCount);
          INC (instrCount);
        END;
        proxy := proxy. nextProxy
      END;

      nested := b. domList;
      WHILE (nested # NIL) DO
        AssignIds (nested);
        nested := nested. nextDom
      END;
    END AssignIds;
  
  BEGIN
    w. WriteTextDecl ("1.0", "no");

    w. idMap := Dictionary.New();
    instrCount := 1;
    AssignIds (domRoot);
    
    w. StartTag ("schedule", FALSE);
    WriteBlock (domRoot);
    w. EndTag;  (* schedule *)
    w. EndOfText
  END WriteSchedule;

PROCEDURE WriteSchedule* (cw: IO.ByteChannel; domRoot: Schedule.Block)
RAISES IO.Error;
  VAR
    w: Writer;
  BEGIN
    w := NewWriter (cw);
    w. WriteSchedule (domRoot);
  END WriteSchedule;

END OOC:SSA:XML.
