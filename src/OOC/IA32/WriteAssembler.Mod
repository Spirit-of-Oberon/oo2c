(* 	$Id: WriteAssembler.Mod,v 1.20 2003/02/23 02:41:52 mva Exp $	 *)
MODULE OOC:IA32:WriteAssembler [OOC_EXTENSIONS];
(*  Translates a set of scheduled SSA instructions to IA32 assembler.
    Copyright (C) 2002, 2003  Michael van Acken

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

(**This module is a _very_ limited code generator for IA32 assembler code,
   using the AT&T syntax of the GNU assembler (aka gas, aka as).  Right now, it
   can translate the baseline tests in tests/ia32/, but nothing more.  To be
   more precise, it can translate procedures with up to one parameter, that
   have no non-constant expressions, and that call other procedures.  As it is,
   this module is a proof of concept how assembler output would be integrated
   into the OOC build framework.  *)

IMPORT
  Ascii, IntStr, Log, Out, Strings, StringSearch, IO, IO:StdChannels,
  Object, Object:Boxed, Object:BigInt, 
  Rep := OOC:Repository, OOC:IR, Sym := OOC:SymbolTable,
  OOC:SSA, OOC:SSA:Opcode, OOC:SSA:Opnd, OOC:SSA:Schedule, 
  OOC:C:Naming, OOC:IA32:Writer, OOC:Make:TranslateToIA32,
  OOC:SSA:IRtoSSA, OOC:SSA:XML,
  OOC:SSA:DeadCodeElimination, OOC:SSA:Destore;


TYPE
  Translator = POINTER TO TranslatorDesc;
  TranslatorDesc = RECORD
    (TranslateToIA32.TranslatorDesc)
    inspectProc: StringSearch.Matcher;
    inspectStage: StringSearch.Matcher;
    lfeCount: LONGINT;
  END;

TYPE
  Buffer = ARRAY 256 OF CHAR;

PROCEDURE WriteInstrList (w: Writer.Writer; b: Schedule.Block);
  VAR
    proxy: Schedule.InstrProxy;
    instr: SSA.Instr;

  PROCEDURE Value (opnd: SSA.Opnd; VAR str: ARRAY OF CHAR);
    VAR
      arg: SSA.Result;
      s: STRING;
      chars: Object.CharsLatin1;
      
    PROCEDURE Const (value: Boxed.Object; stringType: Sym.Type);
      VAR
        s: STRING;
        string: STRING;
        chars: Object.CharsLatin1;
      BEGIN
        IF (value = NIL) THEN
          COPY ("$0", str);
        ELSE
          WITH value: Boxed.Boolean DO
            IF value. value THEN
              COPY ("$1", str);
            ELSE
              COPY ("$0", str);
            END
          | value: Boxed.String DO
            IF (stringType = NIL) THEN
              IntStr.IntToStr(ORD(value.value.CharAt(0)), str);
            ELSE
              s := w. GetStringLabel (value);
              chars := s(Object.String8).CharsLatin1();
              COPY(chars^, str);
            END;
            Strings.Insert ("$", 0, str);
          | value: Boxed.LongReal DO
            ASSERT (FALSE);
          | value: BigInt.BigInt DO
            string := value.ToString();
            chars := string(Object.String8).CharsLatin1();
            COPY(chars^, str);
            Strings.Insert ("$", 0, str);
          | value: Boxed.Set DO
            ASSERT (FALSE);
          END;
        END;
      END Const;
    
    BEGIN
      arg := opnd. arg;
      WITH arg: SSA.Const DO
        Const (arg. value, arg. stringType);
        
      | arg: SSA.Address DO
        s := Naming.NameOfDeclaration (arg. decl);
        chars := s(Object.String8).CharsLatin1();
        COPY(chars^, str);

      ELSE
        CASE arg. instr. opcode OF
        | Opcode.get:
          (* FIXME... this only works for first parameter *)
          w. Instr ("movswl 8(%ebp),%ebx");
          COPY ("%ebx", str);
        ELSE
          Log.Type ("arg.instr", arg. instr);
          arg. instr. LogOpcode ("opcode");
          ASSERT (FALSE);
        END;
      END;
    END Value;
  
  PROCEDURE Push (opnd: SSA.Opnd);
    VAR
      str: Buffer;
    BEGIN
      Value (opnd, str);
      Strings.Insert ("pushl ", 0, str);
      w. Instr (str);
    END Push;

  PROCEDURE PushList (opnd: SSA.Opnd; class: Opnd.Class): LONGINT;
    VAR
      len: LONGINT;
    BEGIN
      IF (opnd. class = class) THEN
        len := PushList (opnd. nextOpnd, class);
        Push (opnd);
        RETURN len+1;
      ELSE
        RETURN 0;
      END;
    END PushList;
  
  PROCEDURE Assert (assert: SSA.Instr);
    BEGIN
      (* FIXME... always translated as ASSERT(FALSE,n) *)
      Push (assert. opndList. nextOpnd. nextOpnd);
      w. PushInt (assert. pos);
      w. PushLabel ("_mid");
      w. Instr ("call RT0__ErrorAssertionFailed");
      w. PopBytes (12);
    END Assert;

  PROCEDURE Call (call: SSA.Instr);
    VAR
      str: Buffer;
      len: LONGINT;
    BEGIN
      len := PushList (call. opndList. nextOpnd, Opnd.arg);
      Value (call. opndList, str);
      Strings.Insert ("call ", 0, str);
      w. Instr (str);
      IF (len # 0) THEN
        w. PopBytes (len*4);
      END;
    END Call;
  
  BEGIN
    proxy := b. proxyList;
    WHILE (proxy # NIL) DO
      instr := proxy. instr;

      CASE instr. opcode OF
      | Opcode.const:
        (* nothing, handled in `Ref' *)
      | Opcode.declRef:
        (* nothing, handled in `Ref' *)
      | Opcode.typeRef:
        (* nothing, handled in `Ref' *)
      | Opcode.address:
        (* nothing, handled in `Ref' *)
      | Opcode.get:
        (* nothing, handled in `Ref' for now *)
        
      | Opcode.enter:
        (* nothing *)
      | Opcode.select:
        (* nothing *)
      | Opcode.labels:
        (* nothing *)

      | Opcode.multiply:
        (* ... *)
      | Opcode.getLengthParam:
        (* ... *)
      | Opcode.copyParameter:
        (* ... *)
        
      | Opcode.return:
        (* nothing *)
      | Opcode.selectReturn:
        (* nothing *)

      | Opcode.assert:
        Assert (instr);
      | Opcode.call:
        Call (instr);
      END;
      
      proxy := proxy. nextProxy
    END;
  END WriteInstrList;

PROCEDURE WriteBlocks (w: Writer.Writer; domRoot: Schedule.Block);
  PROCEDURE WriteBlock (b: Schedule.Block);
    BEGIN
      IF (b. degreeIn # 0) THEN
        WriteInstrList (w, b);
      END;
    END WriteBlock;
  
  BEGIN
    WriteBlock (domRoot);
  END WriteBlocks;

PROCEDURE (t: Translator) WriteProcBody* (proc: IR.Procedure);
  VAR
    w: Writer.Writer;
    name: STRING;
    lfe: ARRAY 32 OF CHAR;
    pb: SSA.ProcBlock;
    enter: SSA.Instr;
    s: SSA.Result;
    domRoot: Schedule.Block;
    writeProc: BOOLEAN;
    destore: Destore.State;
    instr, next: SSA.Instr;

  PROCEDURE Write (pre, post: ARRAY OF CHAR);
    BEGIN
      IF writeProc &
         ((t. inspectStage. MatchChars (pre, 0, -1) # NIL) OR
          (t. inspectStage. MatchChars (post, 0, -1) # NIL)) THEN
        Out.String ("PROCEDURE ");
        Out.String (pb. procDecl. name. str^);
        Out.String ("/");
        Out.String (pre);
        Out.String ("/");
        Out.String (post);
        Out.String (":");
        Out.Ln;
        Out.Flush;
        TRY
          XML.Write (StdChannels.stdout, pb, TRUE);
        CATCH IO.Error:
        END;
        Out.Flush;
      END;
    END Write;
  
  BEGIN
    (*Log.String ("procedure",proc. decl. name. str^);*)
    pb := SSA.NewProcBlock (proc);
    writeProc := (t. inspectProc. MatchChars (proc. decl. name. str^, 0, -1) # NIL);
    enter := pb. selectReturn. opndList. arg. instr;
    s := IRtoSSA.StatmSeq (pb, enter. nextResult,
                           proc. statmSeq);
    pb. selectReturn. AddOpnd (s, Opnd.store);

    (*Blocker.Write (StdChannels.stdout, pb);*)
    
    (* code transformations *)
    Write ("initial", "dce-pre");
    DeadCodeElimination.Transform (pb);
    Write ("dce-post", "destore-pre");
    destore := Destore.New (pb);
    destore. Transform();
    Write ("destore-post", "dce-pre");
    DeadCodeElimination.Transform (pb);
    Write ("dce-post", "final");

    (* type-conv is not supported yet ;-) *)
    instr := pb. instrList;
    WHILE (instr # NIL) DO
      next := instr.nextInstr;
      CASE instr. opcode OF
      | Opcode.typeConv:
        instr.ReplaceUses(instr.opndList.arg);
        pb.DeleteInstr(instr);
      ELSE (* nothing to do *)
      END;
      instr := next;
    END;
    
    domRoot := Schedule.Schedule (pb);
    IF writeProc THEN
      IF (t. inspectStage. MatchChars ("schedule", 0, -1) # NIL) THEN
        (* write schedule SSA code to stdout *)
        TRY
          XML.WriteSchedule (StdChannels.stdout, domRoot);
        CATCH IO.Error:
        END;
        Out.Flush
      END;
    END;
    

    w := t. w;
    IF (proc. decl. parent = NIL) THEN
      name := Naming.NameOfModuleInit (t. symTab, TRUE);
    ELSE      
      name := Naming.NameOfDeclaration (proc. decl);
    END;
    IntStr.IntToStr (t. lfeCount, lfe);
    Strings.Insert (".Lfe", 0, lfe);
    INC (t. lfeCount);
    
    w. Instr (".align 4");
    w. Write (".globl "); w. WriteObject (name); w. Newline;
    w. Write (Ascii.ht+".type "); w. WriteObject (name);
    w. Write (",@function"); w. Newline;
    w. Label (name);
    w. Instr ("pushl %ebp");
    w. Instr ("movl %esp,%ebp");
    w. Instr ("pushl %ebx");             (* save register *)
    
    WriteBlocks (w, domRoot);
    
    w. Instr ("pop %ebx");               (* restore register *)
    w. Instr ("leave");
    w. Instr ("ret");
    w. Label (Object.NewLatin1(lfe));
    w. Write (Ascii.ht+".size "); w. WriteObject (name); w. Write (",");
    w. Write (lfe); w. Write ("-"); w. WriteObject (name); w. Newline;
  END WriteProcBody;


PROCEDURE InitTranslator* (t: Translator; module: Rep.Module;
                           inspectProc, inspectStage: StringSearch.Matcher);
  BEGIN
    TranslateToIA32.InitTranslator (t, module);
    t. inspectProc := inspectProc;
    t. inspectStage := inspectStage;
    t. lfeCount := 1;
  END InitTranslator;

PROCEDURE NewTranslator* (module: Rep.Module;
                          inspectProc, inspectStage: StringSearch.Matcher): Translator;
  VAR
    t: Translator;
  BEGIN
    NEW (t);
    InitTranslator (t, module, inspectProc, inspectStage);
    RETURN t
  END NewTranslator;

END OOC:IA32:WriteAssembler.
