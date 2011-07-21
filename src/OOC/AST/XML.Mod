(* 	$Id: XML.Mod,v 1.1 2003/08/26 14:05:22 mva Exp $	 *)
MODULE OOC:AST:XML;
(*  Writes an abstract syntax tree into an XML document.
    Copyright (C) 2000, 2001, 2002, 2003  Michael van Acken

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
  IO, OOC:Scanner:Symbol, OOC:AST, XML:Writer,
  XML:UnicodeCodec:Latin1, OOC:Doc, DocXML := OOC:Doc:Output:XML;


PROCEDURE Write* (cw: IO.ByteChannel; m: AST.Module)
RAISES IO.Error;
(**Writes the abstract syntax tree @oparam{m} to the output writer 
   @oparam{cw}.  The result is an XML document that describes the
   structure of the syntax tree.  The only information lost is formatting,
   comments, and pragmas.  Here is an example of the output for the
   most simple module:
   
   @example
   <?xml version='1.0' encoding='ISO-8859-1' standalone='yes'?>
   <module>
     <symbol id='module'>MODULE</symbol>
     <node_list>
       <symbol id='ident'>Simple</symbol>
     </node_list>
     <symbol id='semicolon'>;</symbol>
     <body>
       <node_list>
       </node_list>
       <symbol id='end'>END</symbol>
       <node_list>
         <symbol id='ident'>Simple</symbol>
       </node_list>
     </body>
     <symbol id='period'>.</symbol>
   </module>
   @end example  *)
  VAR
    w: Writer.Writer;
  
  PROCEDURE Node (n: AST.Node);
    VAR
      i: LONGINT;

    PROCEDURE NodeDocString (doc: Doc.Document);
      BEGIN
        IF (doc # NIL) THEN
          DocXML.WriteOberonDoc (w, doc, NIL, NIL, NIL, NIL)
        END
      END NodeDocString;
    
    BEGIN
      IF (n # NIL) THEN
        WITH n: AST.NodeList DO
          w. StartTag ("node_list", FALSE);
          FOR i := 0 TO n. len-1 DO
            Node (n. n[i])
          END;
          w. EndTag
          
        | n: AST.Terminal DO
          w. StartTag ("symbol", TRUE);
          w. AttrStringLatin1 ("id", Symbol.name[n. sym. id]);
          w. WriteLatin1I (n. sym. str^, 0, n. sym. len);
          w. EndTag
        
        | n: AST.IdentDef DO
          w. StartTag ("ident_def", FALSE);
          Node (n. ident);
          Node (n. mark);
          NodeDocString (n. docString);
          w. EndTag
        
        | n: AST.ModuleIdent DO
          w. StartTag ("module_ident", FALSE);
          Node (n. nameList);
          NodeDocString (n. docString);
          w. EndTag
          
        | n: AST.ArrayType DO
          w. StartTag ("array_type", FALSE);
          Node (n. array);
          Node (n. flags);
          Node (n. exprList);
          Node (n. of);
          Node (n. type);
          w. EndTag
        
        | n: AST.FieldList DO
          w. StartTag ("field_list", FALSE);
          Node (n. identList);
          Node (n. colon);
          Node (n. type);
          w. EndTag
        
        | n: AST.RecordType DO
          w. StartTag ("record_type", FALSE);
          Node (n. record);
          Node (n. flags);
          Node (n. lParen);
          Node (n. baseType);
          Node (n. rParen);
          Node (n. fieldLists);
          Node (n. end);
          w. EndTag
        
        | n: AST.PointerType DO
          w. StartTag ("pointer_type", FALSE);
          Node (n. pointer);
          Node (n. flags);
          Node (n. to);
          Node (n. type);
          w. EndTag
        
        | n: AST.FPSection DO
          w. StartTag ("fp_section", FALSE);
          Node (n. var);
          Node (n. identList);
          Node (n. colon);
          Node (n. type);
          w. EndTag
        
        | n: AST.FormalPars DO
          w. StartTag ("formal_pars", FALSE);
          Node (n. flags);
          Node (n. lParen);
          Node (n. fpSections);
          Node (n. rParen);
          Node (n. colon);
          Node (n. result);
          Node (n. raises);
          Node (n. raisesList);
          w. EndTag
          
        | n: AST.ProcType DO
          w. StartTag ("proc_type", FALSE);
          Node (n. procedure);
          Node (n. formalPars);
          w. EndTag
          
        | n: AST.TPSection DO
          w. StartTag ("tp_section", FALSE);
          Node (n. identList);
          Node (n. colon);
          Node (n. type);
          w. EndTag
        
        | n: AST.TypePars DO
          w. StartTag ("type_pars", FALSE);
          Node (n. lParen);
          Node (n. tpSections);
          Node (n. rParen);
          w. EndTag
          
        | n: AST.QualType DO
          w. StartTag ("qual_type", FALSE);
          Node (n. qualident);
          Node (n. lParen);
          Node (n. arguments);
          Node (n. rParen);
          w. EndTag
          
        | n: AST.ImportDecl DO
          w. StartTag ("import_decl", FALSE);
          Node (n. alias);
          Node (n. becomes);
          Node (n. module);
          w. EndTag
          
        | n: AST.ConstDecl DO
          w. StartTag ("const_decl", FALSE);
          Node (n. identDef);
          Node (n. equal);
          Node (n. expr);
          Node (n. semicolon);
          w. EndTag
          
        | n: AST.TypeDecl DO
          w. StartTag ("type_decl", FALSE);
          Node (n. identDef);
          Node (n. typePars);
          Node (n. equal);
          Node (n. type);
          Node (n. semicolon);
          w. EndTag
          
        | n: AST.VarDecl DO
          w. StartTag ("var_decl", FALSE);
          Node (n. identList);
          Node (n. colon);
          Node (n. type);
          Node (n. semicolon);
          w. EndTag
        
        | n: AST.Receiver DO
          w. StartTag ("receiver", FALSE);
          Node (n. lParen);
          Node (n. var);
          Node (n. ident);
          Node (n. colon);
          Node (n. type);
          Node (n. rParen);
          w. EndTag
          
        | n: AST.ProcDecl DO
          w. StartTag ("proc_decl", FALSE);
          Node (n. proc);
          Node (n. arrow);
          Node (n. receiver);
          Node (n. flags);
          Node (n. identDef);
          Node (n. formalPars);
          Node (n. semicolon1);
          Node (n. body);
          Node (n. semicolon2);
          w. EndTag
        
        | n: AST.ImportList DO
          w. StartTag ("import_list", FALSE);
          Node (n. import);
          Node (n. imports);
          Node (n. semicolon);
          w. EndTag
          
        | n: AST.Body DO
          w. StartTag ("body", FALSE);
          Node (n. declSeq);
          Node (n. begin);
          Node (n. statmSeq);
          Node (n. end);
          Node (n. name);
          w. EndTag
          
        | n: AST.Module DO
          w. StartTag ("module", FALSE);
          Node (n. module);
          Node (n. name);
          Node (n. flags);
          Node (n. semicolon);
          Node (n. importList);
          Node (n. body);
          Node (n. period);
          w. EndTag
        
        | n: AST.Operator DO
          w. StartTag ("operator", FALSE);
          Node (n. left);
          Node (n. op);
          Node (n. right);
          w. EndTag
        
        | n: AST.Factor DO
          w. StartTag ("factor", FALSE);
          Node (n. lParen);
          Node (n. expr);
          Node (n. rParen);
          w. EndTag
        
        | n: AST.Set DO
          w. StartTag ("set", FALSE);
          Node (n. type);
          Node (n. lBrace);
          Node (n. elementList);
          Node (n. rBrace);
          w. EndTag
        
        | n: AST.ArrayIndex DO
          w. StartTag ("array_index", FALSE);
          Node (n. design);
          Node (n. lBrak);
          Node (n. indices);
          Node (n. rBrak);
          w. EndTag
        
        | n: AST.FunctionCall DO
          w. StartTag ("function_call", FALSE);
          Node (n. design);
          Node (n. lParen);
          Node (n. arguments);
          Node (n. rParen);
          w. EndTag
        
        
        | n: AST.Assignment DO
          Node (n. assignment)
          
        | n: AST.ProcedureCall DO
          w. StartTag ("procedure_call", FALSE);
          Node (n. call);
          w. EndTag
          
        | n: AST.IfStatm DO
          w. StartTag ("if_statm", FALSE);
          Node (n. guardList);
          Node (n. else);
          Node (n. elseStatmSeq);
          Node (n. end);
          w. EndTag
        
        | n: AST.CaseStatm DO
          w. StartTag ("case_statm", FALSE);
          Node (n. case);
          Node (n. expr);
          Node (n. of);
          Node (n. caseList);
          Node (n. else);
          Node (n. elseStatmSeq);
          Node (n. end);
          w. EndTag
        
        | n: AST.WhileStatm DO
          w. StartTag ("while_statm", FALSE);
          Node (n. while);
          Node (n. guard);
          Node (n. do);
          Node (n. statmSeq);
          Node (n. end);
          w. EndTag
        
        | n: AST.RepeatStatm DO
          w. StartTag ("repeat_statm", FALSE);
          Node (n. repeat);
          Node (n. statmSeq);
          Node (n. until);
          Node (n. expr);
          w. EndTag
        
        | n: AST.ForStatm DO
          w. StartTag ("for_statm", FALSE);
          Node (n. for);
          Node (n. ident);
          Node (n. becomes);
          Node (n. startValue);
          Node (n. to);
          Node (n. endValue);
          Node (n. by);
          Node (n. step);
          Node (n. do);
          Node (n. statmSeq);
          Node (n. end);
          w. EndTag
        
        | n: AST.LoopStatm DO
          w. StartTag ("loop_statm", FALSE);
          Node (n. loop);
          Node (n. statmSeq);
          Node (n. end);
          w. EndTag
        
        | n: AST.WithStatm DO
          w. StartTag ("with_statm", FALSE);
          Node (n. guardList);
          Node (n. else);
          Node (n. elseStatmSeq);
          Node (n. end);
          w. EndTag
        
        | n: AST.ExitStatm DO
          w. StartTag ("exit_statm", FALSE);
          Node (n. exit);
          w. EndTag
        
        | n: AST.ReturnStatm DO
          w. StartTag ("return_statm", FALSE);
          Node (n. return);
          Node (n. expr);
          w. EndTag
        
        | n: AST.TryStatm DO
          w. StartTag ("try_statm", FALSE);
          Node(n.try);
          Node(n.statmSeq);
          Node(n.catchList);
          Node(n.end);
          w. EndTag
        
        
        
        | n: AST.Flags DO
          w. StartTag ("flags", FALSE);
          Node (n. lBrak);
          Node (n. flagList);
          Node (n. rBrak);
          w. EndTag
        
        | n: AST.ProcIdFlag DO
          w. StartTag ("proc_id_flag", FALSE);
          Node (n. procId);
          Node (n. equal);
          Node (n. number);
          w. EndTag
        
        | n: AST.ModuleFlags DO
          w. StartTag ("module_flags", FALSE);
          Node (n. external);
          Node (n. callConv);
          Node (n. moduleFlags);
          Node (n. semicolon);
          Node (n. link);
          Node (n. linkSections);
          Node (n. end);
          w. EndTag
        
        | n: AST.LinkFileFlag DO
          w. StartTag ("link_file_flag", FALSE);
          Node (n. file);
          Node (n. fileName);
          Node (n. addOption);
          Node (n. prefixOpt);
          Node (n. comma);
          Node (n. suffixOpt);
          w. EndTag
        
        | n: AST.LinkObjFlag DO
          w. StartTag ("link_obj_flag", FALSE);
          Node (n. obj);
          Node (n. fileName);
          w. EndTag
        
        | n: AST.LinkLibFlag DO
          w. StartTag ("link_lib_flag", FALSE);
          Node (n. lib);
          Node (n. libName);
          Node (n. lParen);
          Node (n. dependencies);
          Node (n. rParen);
          Node (n. addOption);
          Node (n. prefixOpt);
          Node (n. comma);
          Node (n. suffixOpt);
          w. EndTag
        END
      END
    END Node;

  BEGIN
    w := Writer.New (cw, Latin1.factory, TRUE, 2);
    w. WriteTextDecl ("1.0", "yes");
    Node (m);
    w. EndOfText
  END Write;

END OOC:AST:XML.
