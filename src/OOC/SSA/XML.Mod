(* 	$Id$	 *)
MODULE OOC:SSA:XML;
(*  Produces a canonical representation of SSA code in XML.
    Copyright (C) 2001  Michael van Acken

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
  Channel, Dictionary := ADT:Dictionary:IntValue, ADT:String, ADT:StringBuffer,
  XML:Writer, XML:UnicodeCodec:Latin1,
  OOC:SSA:Opcode, OOC:SSA:Result, OOC:SSA:Opnd, OOC:SSA;



PROCEDURE Write* (cw: Channel.Writer; pb: SSA.ProcBlock;
                  includeDeadCode: BOOLEAN);
(**Note: If @oparam{includeDeadCode} is set and the block contains instructions
   that are dead, then the output depends on the order of instructions in the
   blocks instruction list.  Consequently, it is no longer canonical and may
   differ for otherwise equivalent SSA sequences.  *)
  VAR
    w: Writer.Writer;
    instr: SSA.Instr;
    instrCount: LONGINT;
    sb: StringBuffer.StringBuffer;
    
    idMap: Dictionary.Dictionary;
    (* maps instructions to their numeric id; a negative value means that
       the instruction has not been scheduled for writing yet *)

  PROCEDURE AssignId (instr: SSA.Instr);
    VAR
      opnd: SSA.Opnd;
    BEGIN
      IF ~idMap. HasKey (instr) THEN
        (* assign ids to all instructions that are referenced in the
           operand list *)
        opnd := instr. opndList;
        WHILE (opnd # NIL) DO
          AssignId (opnd. arg. instr);
          opnd := opnd. nextOpnd
        END;

        idMap. Set (instr, -instrCount);
        INC (instrCount);
      END;
    END AssignId;
  
  PROCEDURE WriteInstr (instr: SSA.Instr; id: LONGINT);
    VAR
      str: ARRAY 64 OF CHAR;
      value: String.String;
      res: SSA.Result;
      opnd: SSA.Opnd;
      
    PROCEDURE AttrId (name: ARRAY OF LONGCHAR; result: SSA.Result);
      VAR
        str: ARRAY 64 OF CHAR;
        res: SSA.Result;
        countSameId, posSameId: LONGINT;
      BEGIN
        sb. Delete (0, sb. length);
        sb. AppendLongInt (ABS (idMap. Get (result. instr)));
        IF (result # result. instr) THEN
          sb. AppendChar (".");
          Result.GetName (result. class, str);
          sb. AppendString (str);

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
            sb. AppendChar (".");
            sb. AppendLongInt (posSameId);
          END;
        END;
        w. AttrStringLatin1 (name, sb. array^);
      END AttrId;

    PROCEDURE WriteResult (res: SSA.Result);
      VAR
        str: ARRAY 64 OF CHAR;
      BEGIN
        w. StartTag ("res", FALSE);
        
        AttrId ("id", res);
        
        Result.GetName (res. class, str);
        w. AttrStringLatin1 ("class", str);
        
        w. EndTag;  (* res *)
      END WriteResult;
    
    PROCEDURE WriteOpnd (opnd: SSA.Opnd);
      VAR
        arg: SSA.Result;
        str: ARRAY 64 OF CHAR;
      BEGIN
        w. StartTag ("opnd", FALSE);

        Opnd.GetName (opnd. class, str);
        w. AttrStringLatin1 ("class", str);
        
        arg := opnd. arg;
        WITH arg: SSA.Const DO
          value := arg. value. ToString();
          w. AttrStringLatin1 ("const-value", value. array^);
        | arg: SSA.DeclRef DO
          w. AttrStringLatin1 ("declref", arg. decl. name. str^);
        | arg: SSA.Address DO
          w. AttrStringLatin1 ("address-of", arg. decl. name. str^);
        ELSE
          AttrId ("argref", opnd. arg);
        END;
        w. EndTag;  (* opnd *)
      END WriteOpnd;
    
    BEGIN
      IF (instr IS SSA.Const) OR
         (instr IS SSA.DeclRef) OR
         (instr IS SSA.Address) THEN
        (* these kinds of instructions are written in a shorthand form:
           their actual value is indicated in the "opnd" tag, and the
           instructions themselves are omitted *)
        RETURN
      END;
      
      Opcode.GetName (instr. opcode, instr. subclass, str);
      w. StartTagLatin1 (str, FALSE);
      w. AttrInt ("id", id);

      WITH instr: SSA.Const DO
        value := instr. value. ToString();
        w. AttrStringLatin1 ("value", value. array^);
      ELSE
      END;
      
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
      
      w. EndTag;  (* instr *)
    END WriteInstr;
  
  PROCEDURE TraverseInstr (instr: SSA.Instr);
    VAR
      opnd: SSA.Opnd;
      id: LONGINT;
    BEGIN
      id := idMap. Get (instr);
      IF (id < 0) THEN                   (* not yet scheduled? *)
        idMap. Set (instr, -id);         (* mark as scheduled *)
        
        (* schedule all operands for writing _before_ this instruction *)
        opnd := instr. opndList;
        WHILE (opnd # NIL) DO
          TraverseInstr (opnd. arg. instr);
          opnd := opnd. nextOpnd
        END;
        WriteInstr (instr, -id);
      END;
    END TraverseInstr;
  
  BEGIN
    sb := StringBuffer.New("");
    w := Writer.New (cw, Latin1.factory, TRUE, 2);
    w. WriteTextDecl ("1.0", "yes");

    (* first pass: assign ids to all instructions reachable from the
       exit instruction; this step skips dead code *)
    idMap := Dictionary.New();
    instrCount := 1;
    AssignId (pb. selectReturn);
    
    w. StartTag ("procedure-body", FALSE);
    TraverseInstr (pb. selectReturn);

    IF includeDeadCode THEN
      (* finally pick up dead code; in the output, these instructions appear
         after the `exit' *)
      instr := pb. instrList;
      WHILE (instr # NIL) DO
        IF ~idMap. HasKey (instr) THEN
          AssignId (instr);
          TraverseInstr (instr);
        END;
        instr := instr. nextInstr
      END;
    END;
    w. EndTag;  (* procedure-body *)
    w. EndOfText
  END Write;
  
END OOC:SSA:XML.
