(* 	$Id: StupidPP.Mod,v 1.1 2003/08/26 14:05:22 mva Exp $	 *)
MODULE OOC:AST:StupidPP;
(*  A simple pretty printer: it writes the syntax tree, omitting any comments.
    Copyright (C) 2000-2003  Michael van Acken

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
  Log, TextRider, OOC:Scanner:Symbol, OOC:AST;
  
PROCEDURE Write* (w: TextRider.Writer; m: AST.Module);
(**Writes the abstract syntax tree @oparam{m} to the output writer
   @oparam{w}.  The result is the content of the source module, with a
   very rigid formatting and minus any embedded comments or pragmas.  *)
  VAR
    indent: LONGINT;
    
  PROCEDURE NewLine;
    VAR
      i: LONGINT;
    BEGIN
      w. WriteLn;
      FOR i := 1 TO indent DO
        w. WriteString ("  ")
      END
    END NewLine;

  PROCEDURE Node (n: AST.Node);
    VAR
      i, j: LONGINT;

    BEGIN
      IF (n # NIL) THEN
        WITH n: AST.NodeList DO
          FOR i := 0 TO n. len-1 DO
            Node (n. n[i])
          END
         
        | n: AST.Terminal DO
          w. byteWriter. WriteBytes (n. sym. str^, 0, n. sym. len)
        
        | n: AST.IdentDef DO
          Node (n. ident);
          IF (n. mark # NIL) THEN
            Node (n. mark)
          END
        
        | n: AST.ModuleIdent DO
          Node (n. nameList)
          
        | n: AST.ArrayType DO
          w. WriteString ("ARRAY");
          Node (n. flags);
          i := 0;
          WHILE (i < n. exprList. len) DO
            IF (i # 0) THEN
              w. WriteString (", ")
            ELSE
              w. WriteString (" ")
            END;
            Node (n. exprList. n[i]);
            INC (i, 2)
          END;
          w. WriteString (" OF ");
          Node (n. type)
        
        | n: AST.FieldList DO
          i := 0;
          WHILE (i < n. identList. len) DO
            IF (i # 0) THEN
              w. WriteString (", ")
            END;
            Node (n. identList. n[i]);
            INC (i, 3)
          END;
          w. WriteString (": ");
          Node (n. type)
        
        | n: AST.RecordType DO
          w. WriteString ("RECORD");
          Node (n. flags);
          INC (indent);
          IF (n. baseType # NIL) THEN
            NewLine;
            w. WriteString ("(");
            Node (n. baseType);
            w. WriteString (")")
          END;
          i := 0;
          WHILE (i < n. fieldLists. len) DO
            IF (n. fieldLists. n[i] = NIL) THEN
              (* emtpy field list *)
            ELSIF (n. fieldLists. n[i] IS AST.Terminal) THEN
              w. WriteString (";")
            ELSE
              NewLine;
              Node (n. fieldLists. n[i]);
            END;
            INC (i)
          END;
          DEC (indent);
          NewLine;
          w. WriteString ("END")
        
        | n: AST.PointerType DO
          w. WriteString ("POINTER ");
          Node (n. flags);
          w. WriteString ("TO ");
          Node (n. type)
        
        | n: AST.FPSection DO
          IF (n. var # NIL) THEN
            w. WriteString ("VAR ")
          END;
          Node (n. identList. n[0]);
          Node (n. identList. n[1]);
          i := 3;
          WHILE (i < n. identList. len) DO
            w. WriteString (", ");
            Node (n. identList. n[i]);
            Node (n. identList. n[i+1]);
            INC (i, 3)
          END;
          w. WriteString (": ");
          Node (n. type)
        
        | n: AST.FormalPars DO
          Node (n. flags);
          IF (n. fpSections # NIL) THEN
            w. WriteString (" (");
            i := 0;
            WHILE (i < n. fpSections. len) DO
              IF (i # 0) THEN
                w. WriteString ("; ")
              END;
              Node (n. fpSections. n[i]);  (* fpSection or restParam *)
              INC (i, 2)
            END;
            w. WriteString (")");
            IF (n. result # NIL) THEN
              w. WriteString (": ");
              Node (n. result)
            END
          END
        
        | n: AST.ProcType DO
          w. WriteString ("PROCEDURE ");
          Node (n. formalPars)
          
        | n: AST.ImportDecl DO
          IF (n. alias # NIL) THEN
            Node (n. alias);
            w. WriteString (" := ")
          END;
          Node (n. module)
          
        | n: AST.ConstDecl DO
          INC (indent);
          NewLine;
          Node (n. identDef);
          w. WriteString (" = ");
          Node (n. expr);
          w. WriteString (";");
          DEC (indent)
          
        | n: AST.TypeDecl DO
          INC (indent);
          NewLine;
          Node (n. identDef);
          w. WriteString (" = ");
          Node (n. type);
          w. WriteString (";");
          DEC (indent)
          
        | n: AST.VarDecl DO
          INC (indent);
          NewLine;
          Node (n. identList. n[0]);
          Node (n. identList. n[1]);
          i := 3;
          WHILE (i < n. identList. len) DO
            w. WriteString (", ");
            Node (n. identList. n[i]);
            Node (n. identList. n[i+1]);
            INC (i, 3)
          END;
          w. WriteString (": ");
          Node (n. type);
          w. WriteString (";");
          DEC (indent)
          
        | n: AST.Receiver DO
          w. WriteString ("(");
          IF (n. var # NIL) THEN
            w. WriteString ("VAR ")
          END;
          Node (n. ident);
          w. WriteString (": ");
          Node (n. type);
          w. WriteString (") ")
          
        | n: AST.ProcDecl DO
          NewLine; NewLine;
          w. WriteString ("PROCEDURE ");
          IF (n. arrow # NIL) THEN
            w. WriteString ("^")
          END;
          Node (n. receiver);
          Node (n. flags);
          Node (n. identDef);
          Node (n. formalPars);
          w. WriteString (";");
          IF (n. body # NIL) THEN
            INC (indent);
            Node (n. body);
            DEC (indent);
            w. WriteString (";")
          END
        
        | n: AST.ImportList DO
          NewLine;
          NewLine;
          w. WriteString ("IMPORT");
          INC (indent);
          NewLine;
          Node (n. imports. n[0]);
          i := 2;
          WHILE (i < n. imports. len) DO
            w. WriteString (", ");
            Node (n. imports. n[i]);
            INC (i, 2)
          END;
          w. WriteString (";");
          DEC (indent);
        
        | n: AST.Body DO
          FOR i := 0 TO n. declSeq. len-1 DO
            IF (n. declSeq. n[i] IS AST.Terminal) THEN
              NewLine; NewLine
            END;
            Node (n. declSeq. n[i])
          END;
          IF (n. begin # NIL) THEN
            NewLine;
            w. WriteString ("BEGIN");
            INC (indent);
            Node (n. statmSeq);
            DEC (indent)
          END;
          NewLine;
          w. WriteString ("END ");
          Node (n. name)
          
        | n: AST.Module DO
          w. WriteString ("MODULE ");
          Node (n. name);
          Node (n. flags);
          w. WriteString (";");
          Node (n. importList);
          Node (n. body);
          w. WriteString (".");
          w. WriteLn
        
        | n: AST.Operator DO
          IF (n. op. sym. id = Symbol.becomes) THEN
            NewLine
          END;
          Node (n. left);
          IF Symbol.IsKeyword (n. op. sym. id) THEN
            w. WriteString (" ");
            Node (n. op);
            w. WriteString (" ")
          ELSE
            Node (n. op);
          END;
          Node (n. right)
        
        | n: AST.Factor DO
          w. WriteString ("(");
          Node (n. expr);
          w. WriteString (")")
          
        
        | n: AST.Set DO
          IF (n. type # NIL) THEN
            Node (n. type)
          END;
          w. WriteString ("{");
          i := 0;
          WHILE (i < n. elementList. len) DO
            IF (i # 0) THEN
              w. WriteString (", ")
            END;
            Node (n. elementList. n[i]);
            INC (i, 2)
          END;
          w. WriteString ("}")
        
        | n: AST.ArrayIndex DO
          Node (n. design);
          w. WriteString ("[");
          i := 0;
          WHILE (i < n. indices. len) DO
            IF (i # 0) THEN
              w. WriteString (", ")
            END;
            Node (n. indices. n[i]);
            INC (i, 2)
          END;
          w. WriteString ("]");
        
        | n: AST.FunctionCall DO
          Node (n. design);
          w. WriteString ("(");
          i := 0;
          WHILE (i < n. arguments. len) DO
            IF (i # 0) THEN
              w. WriteString (", ")
            END;
            Node (n. arguments. n[i]);
            INC (i, 2)
          END;
          w. WriteString (")");
        
        
        | n: AST.Assignment DO
          NewLine;
          Node (n. assignment)
          
        | n: AST.ProcedureCall DO
          NewLine;
          Node (n. call)
          
        | n: AST.IfStatm DO
          i := 0;
          WHILE (i < n. guardList. len) DO
            NewLine;
            IF (i = 0) THEN
              w. WriteString ("IF ")
            ELSE
              w. WriteString ("ELSIF ")
            END;
            Node (n. guardList. n[i+1]);
            w. WriteString (" THEN");
            INC (indent);
            Node (n. guardList. n[i+3]);
            DEC (indent);
            INC (i, 4)
          END;
          IF (n. else # NIL) THEN
            NewLine;
            w. WriteString ("ELSE");
            INC (indent);
            Node (n. elseStatmSeq);
            DEC (indent)
          END;
          NewLine;
          w. WriteString ("END")
        
        | n: AST.CaseStatm DO
          NewLine;
          w. WriteString ("CASE ");
          Node (n. expr);
          w. WriteString (" OF");
          i := 0;
          WHILE (i < n. caseList. len) DO
            ASSERT (i+2 < n. caseList. len);
            IF (n. caseList. n[i] # NIL) THEN
              NewLine;
              w. WriteString ("| ");
              j := 0;
              WHILE (j < n. caseList. n[i](AST.NodeList). len) DO
                IF (j # 0) THEN
                  w. WriteString (", ")
                END;
                Node (n. caseList. n[i](AST.NodeList). n[j]);
                INC (j, 2)
              END;
              w. WriteString (": ");
              INC (indent);
              Node (n. caseList. n[i+2]);
              DEC (indent)
            END;
            INC (i, 4)
          END;
          IF (n. else # NIL) THEN
            NewLine;
            w. WriteString ("ELSE");
            INC (indent);
            Node (n. elseStatmSeq);
            DEC (indent)
          END;
          NewLine;
          w. WriteString ("END")
        
        | n: AST.WhileStatm DO
          NewLine;
          w. WriteString ("WHILE ");
          Node (n. guard);
          w. WriteString (" DO");
          INC (indent);
          Node (n. statmSeq);
          DEC (indent);
          NewLine;
          w. WriteString ("END")
        
        | n: AST.RepeatStatm DO
          NewLine;
          w. WriteString ("REPEAT");
          INC (indent);
          Node (n. statmSeq);
          DEC (indent);
          NewLine;
          w. WriteString ("UNTIL ");
          Node (n. expr)
        
        | n: AST.ForStatm DO
          NewLine;
          w. WriteString ("FOR ");
          Node (n. ident);
          w. WriteString (" := ");
          Node (n. startValue);
          w. WriteString (" TO ");
          Node (n. endValue);
          IF (n. step # NIL) THEN
            w. WriteString (" BY ");
            Node (n. step)
          END;
          w. WriteString (" DO");
          INC (indent);
          Node (n. statmSeq);
          DEC (indent);
          NewLine;
          w. WriteString ("END")
          
        | n: AST.LoopStatm DO
          NewLine;
          w. WriteString ("LOOP");
          INC (indent);
          Node (n. statmSeq);
          DEC (indent);
          NewLine;
          w. WriteString ("END")
        
        | n: AST.WithStatm DO
          i := 0;
          WHILE (i < n. guardList. len) DO
            NewLine;
            IF (i = 0) THEN
              w. WriteString ("WITH ")
            ELSE
              w. WriteString ("| ")
            END;
            Node (n. guardList. n[i+1]);
            w. WriteString (" DO");
            INC (indent);
            Node (n. guardList. n[i+3]);
            DEC (indent);
            INC (i, 4)
          END;
          IF (n. else # NIL) THEN
            NewLine;
            w. WriteString ("ELSE");
            INC (indent);
            Node (n. elseStatmSeq);
            DEC (indent)
          END;
          NewLine;
          w. WriteString ("END")
        
        | n: AST.ExitStatm DO
          NewLine;
          w. WriteString ("EXIT")
        
        | n: AST.ReturnStatm DO
          NewLine;
          w. WriteString ("RETURN");
          IF (n. expr # NIL) THEN
            w. WriteString (" ");
            Node (n. expr)
          END
        
        
        
        | n: AST.Flags DO
          w. WriteString (" [");
          Node (n. flagList);
          w. WriteString ("]")
        
        | n: AST.ProcIdFlag DO
          w. WriteString ("PROC_ID=");
          Node (n. number)
        
        | n: AST.ModuleFlags DO
          Node (n. external);
          w. WriteString (" ");
          Node (n. callConv);
          i := 1;
          WHILE (i < n. moduleFlags. len) DO
            w. WriteString (", ");
            Node (n. moduleFlags. n[i]);
            INC (i, 2)
          END;
          IF (n. semicolon # NIL) THEN
            w. WriteString ("; LINK ");
            i := 0;
            WHILE (i < n. linkSections. len) DO
              IF (i # 0) THEN
                w. WriteString ("; ")
              END;
              Node (n. linkSections. n[i]);
              INC (i, 2)
            END;
            w. WriteString (" END")
          END
        
        | n: AST.LinkFileFlag DO
          w. WriteString ("FILE ");
          Node (n. fileName);
          IF (n. addOption # NIL) THEN
            w. WriteString (" ADD_OPTION ");
            Node (n. prefixOpt);
            IF (n. comma # NIL) THEN
              w. WriteString (", ");
              Node (n. suffixOpt)
            END
          END
        
        | n: AST.LinkObjFlag DO
          w. WriteString ("OBJ ");
          Node (n. fileName)
        
        | n: AST.LinkLibFlag DO
          w. WriteString ("LIB ");
          Node (n. libName);
          IF (n. lParen # NIL) THEN
            w. WriteString (" (");
            i := 0;
            WHILE (i < n. dependencies. len) DO
              IF (i # 0) THEN
                w. WriteString (", ")
              END;
              Node (n. dependencies. n[i]);
              INC (i, 2)
            END;
            w. WriteString (")")
          END;
          IF (n. addOption # NIL) THEN
            w. WriteString (" ADD_OPTION ");
            Node (n. prefixOpt);
            IF (n. comma # NIL) THEN
              w. WriteString (", ");
              Node (n. suffixOpt)
            END
          END
        ELSE
          Log.Type ("unknown node type", n);
          ASSERT (FALSE)
        END  
      END
    END Node;

  BEGIN
    indent := 0;
    Node (m)
  END Write;

END OOC:AST:StupidPP.
