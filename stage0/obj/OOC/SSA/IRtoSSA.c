#include <OOC/SSA/IRtoSSA.d>
#include <__oo2c.h>
#include <setjmp.h>

static void OOC_SSA_IRtoSSA__AddStoreBackwardFeed(OOC_SSA__ProcBlock pb, OOC_SSA__Instr loopEnd, OOC_SSA__Result storeArg) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)pb;
  i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i0, 6, 0);
  i1 = (OOC_INT32)storeArg;
  OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i1, 2);
  i1 = (OOC_INT32)loopEnd;
  i2 = (OOC_INT32)OOC_SSA__InstrDesc_GetOpndClass((OOC_SSA__Instr)i1, 13);
  i3 = i2==(OOC_INT32)0;
  if (i3) goto l3;
  i0 = (OOC_INT32)OOC_SSA__InstrDesc_AddResult((OOC_SSA__Instr)i0, 2);
  OOC_SSA__OpndDesc_ReplaceArg((OOC_SSA__Opnd)i2, (OOC_SSA__Result)i0);
  goto l4;
l3:
  i0 = (OOC_INT32)OOC_SSA__InstrDesc_AddResult((OOC_SSA__Instr)i0, 2);
  OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i0, 13);
l4:
  return;
  ;
}

OOC_SSA__Result OOC_SSA_IRtoSSA__StatmSeq(OOC_SSA__ProcBlock pb, OOC_SSA__Result s, OOC_IR__StatementSeq statmSeq) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_INT32 i;
  OOC_IR__Statement statm;
  auto void OOC_SSA_IRtoSSA__StatmSeq_Chain(OOC_SSA__Instr instr);
  auto OOC_SSA__Result OOC_SSA_IRtoSSA__StatmSeq_FixAddress(OOC_SSA__Result arg);
  auto OOC_SSA__Result OOC_SSA_IRtoSSA__StatmSeq_FixLength(OOC_SSA__Result arg);
  auto OOC_SSA__Instr OOC_SSA_IRtoSSA__StatmSeq_Call(OOC_IR__Call call);
  auto OOC_SSA__Result OOC_SSA_IRtoSSA__StatmSeq_Expression(OOC_IR__Expression expr);
  auto OOC_SSA__Result OOC_SSA_IRtoSSA__StatmSeq_CalculateLength(OOC_SSA__ProcBlock pb, OOC_IR__Expression value, OOC_INT32 dim, OOC_SSA__Result baseArray);
  auto OOC_SSA__Instr OOC_SSA_IRtoSSA__StatmSeq_CalculateSize(OOC_SSA__ProcBlock pb, OOC_IR__Expression value, OOC_SSA__Result length);
  auto OOC_SymbolTable__Type OOC_SSA_IRtoSSA__StatmSeq_TypeOfString(OOC_SymbolTable__Type type);
  auto void OOC_SSA_IRtoSSA__StatmSeq_TransferReadDesign(OOC_SSA__Result source, OOC_SSA__Instr instr);
  auto void OOC_SSA_IRtoSSA__StatmSeq_TransferWriteDesign(OOC_SSA__Result source, OOC_SSA__Instr instr);
  auto OOC_SSA__Instr OOC_SSA_IRtoSSA__StatmSeq_CopyString(OOC_IR__CopyString cp);
  auto OOC_SSA__Instr OOC_SSA_IRtoSSA__StatmSeq_AddException(OOC_SSA__ProcBlock pb, OOC_Scanner_SymList__Symbol sym, OOC_INT8 opcode, OOC_INT8 subclass);
  auto OOC_SSA__Instr OOC_SSA_IRtoSSA__StatmSeq_TypeTag(OOC_IR__Expression design, OOC_SSA__Result value, OOC_CHAR8 checkDerefOfNil, OOC_Scanner_SymList__Symbol derefSym);
  auto OOC_SSA__Instr OOC_SSA_IRtoSSA__StatmSeq_Copy(OOC_IR__Copy cp);
  auto OOC_SSA__Result OOC_SSA_IRtoSSA__StatmSeq_Expression(OOC_IR__Expression expr);
  auto void OOC_SSA_IRtoSSA__StatmSeq_Assert(OOC_IR__Assert assert);
  auto OOC_SSA__Instr OOC_SSA_IRtoSSA__StatmSeq_Assignment(OOC_IR__Assignment assignment);
  auto OOC_SSA__Instr OOC_SSA_IRtoSSA__StatmSeq_Call(OOC_IR__Call call);
  auto OOC_SSA__Result OOC_SSA_IRtoSSA__StatmSeq_PopExceptionContext(OOC_SSA__Result storeIn, OOC_INT32 n);
  auto void OOC_SSA_IRtoSSA__StatmSeq_Return(OOC_IR__Return _return);
  auto void OOC_SSA_IRtoSSA__StatmSeq_IfStatm(OOC_IR__IfStatm ifStatm);
  auto void OOC_SSA_IRtoSSA__StatmSeq_WithStatm(OOC_IR__WithStatm withStatm);
  auto void OOC_SSA_IRtoSSA__StatmSeq_CaseStatm(OOC_IR__CaseStatm caseStatm);
  auto void OOC_SSA_IRtoSSA__StatmSeq_RepeatStatm(OOC_IR__RepeatStatm repeatStatm);
  auto void OOC_SSA_IRtoSSA__StatmSeq_WhileStatm(OOC_IR__WhileStatm whileStatm);
  auto void OOC_SSA_IRtoSSA__StatmSeq_ForStatm(OOC_IR__ForStatm forStatm);
  auto void OOC_SSA_IRtoSSA__StatmSeq_IterateArrayStatm(OOC_IR__IterateArrayStatm iterStatm);
  auto void OOC_SSA_IRtoSSA__StatmSeq_IterateObjectStatm(OOC_IR__IterateObjectStatm iterStatm);
  auto void OOC_SSA_IRtoSSA__StatmSeq_LoopStatm(OOC_IR__LoopStatm loopStatm);
  auto void OOC_SSA_IRtoSSA__StatmSeq_Exit(OOC_IR__Exit exit);
  auto void OOC_SSA_IRtoSSA__StatmSeq_TryStatm(OOC_IR__TryStatm _try);
  auto void OOC_SSA_IRtoSSA__StatmSeq_CopyParameter(OOC_IR__CopyParameter cp);
  auto OOC_SSA__Instr OOC_SSA_IRtoSSA__StatmSeq_MoveBlock(OOC_IR__MoveBlock move);
  auto OOC_SSA__Instr OOC_SSA_IRtoSSA__StatmSeq_Raise(OOC_IR__Raise raise);
    
    void OOC_SSA_IRtoSSA__StatmSeq_Chain(OOC_SSA__Instr instr) {
      register OOC_INT32 i0,i1,i2;

      i0 = (OOC_INT32)instr;
      i1 = *(OOC_INT8*)((_check_pointer(i0, 2463))+36);
      i1 = i1==13;
      if (i1) goto l3;
      i1 = *(OOC_INT8*)((_check_pointer(i0, 2504))+36);
      i1 = i1==12;
      
      goto l5;
l3:
      i1=1u;
l5:
      if (i1) goto l7;
      i1 = *(OOC_INT8*)((_check_pointer(i0, 2545))+36);
      i1 = i1==15;
      
      goto l9;
l7:
      i1=1u;
l9:
      if (i1) goto l11;
      i1 = *(OOC_INT8*)((_check_pointer(i0, 2593))+36);
      i1 = i1==59;
      
      goto l13;
l11:
      i1=1u;
l13:
      if (i1) goto l15;
      i1 = (OOC_INT32)s;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i1, 2);
      goto l16;
l15:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2640))+24);
      i2 = (OOC_INT32)s;
      OOC_SSA__OpndDesc_ReplaceArg((OOC_SSA__Opnd)i1, (OOC_SSA__Result)i2);
l16:
      i0 = (OOC_INT32)OOC_SSA__InstrDesc_AddResult((OOC_SSA__Instr)i0, 2);
      s = (OOC_SSA__Result)i0;
      return;
      ;
    }

    
    OOC_SSA__Result OOC_SSA_IRtoSSA__StatmSeq_FixAddress(OOC_SSA__Result arg) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)arg;
      i1 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_FixSubclass((OOC_SSA__ProcBlock)i1, (OOC_SSA__Result)i0, 9);
      return (OOC_SSA__Result)i0;
      ;
    }

    
    OOC_SSA__Result OOC_SSA_IRtoSSA__StatmSeq_FixLength(OOC_SSA__Result arg) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)arg;
      i1 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_FixSubclass((OOC_SSA__ProcBlock)i1, (OOC_SSA__Result)i0, 3);
      return (OOC_SSA__Result)i0;
      ;
    }

    
    OOC_SSA__Result OOC_SSA_IRtoSSA__StatmSeq_CalculateLength(OOC_SSA__ProcBlock pb, OOC_IR__Expression value, OOC_INT32 dim, OOC_SSA__Result baseArray) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_SymbolTable__Type type;
      OOC_INT32 i;
      auto OOC_SSA__Result OOC_SSA_IRtoSSA__StatmSeq_CalculateLength_RecursiveGetLength(OOC_SymbolTable__Type type, OOC_INT32 dim);
        
        OOC_SSA__Result OOC_SSA_IRtoSSA__StatmSeq_CalculateLength_RecursiveGetLength(OOC_SymbolTable__Type type, OOC_INT32 dim) {
          register OOC_INT32 i0,i1,i2,i3;
          OOC_SSA__Result len;
          OOC_SSA__Instr lenp;

          i0 = (OOC_INT32)type;
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3940)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
          type = (OOC_SymbolTable__Type)i0;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3969)))), &_td_OOC_SymbolTable__ArrayDesc);
          if (i1) goto l3;
          i0 = (OOC_INT32)pb;
          i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConstInt((OOC_SSA__ProcBlock)i0, 1);
          i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_FixLength((OOC_SSA__Result)i0);
          return (OOC_SSA__Result)i0;
          goto l12;
l3:
          i1 = *(OOC_UINT8*)((_check_pointer(i0, 4001))+40);
          if (i1) goto l6;
          i1 = *(OOC_INT32*)((_check_pointer(i0, 4149))+52);
          i2 = (OOC_INT32)pb;
          i1 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConstInt((OOC_SSA__ProcBlock)i2, i1);
          
          goto l7;
l6:
          i1 = (OOC_INT32)baseArray;
          i2 = dim;
          i3 = (OOC_INT32)pb;
          i1 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddGetLengthInstr((OOC_SSA__ProcBlock)i3, (OOC_SSA__Instr)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4074)))), &_td_OOC_SSA__InstrDesc, 4074)), (i2+1), (OOC_SymbolTable__Array)i0);
          
l7:
          i1 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_FixLength((OOC_SSA__Result)i1);
          len = (OOC_SSA__Result)i1;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4246))+44);
          i2 = OOC_SymbolTable_TypeRules__IsArray((OOC_SymbolTable__Type)i2);
          if (i2) goto l10;
          return (OOC_SSA__Result)i1;
          goto l12;
l10:
          i2 = (OOC_INT32)pb;
          i2 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i2, 22, 3);
          lenp = (OOC_SSA__Instr)i2;
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i1, 1);
          i1 = dim;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4428))+44);
          i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_CalculateLength_RecursiveGetLength((OOC_SymbolTable__Type)i0, (i1+1));
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i0, 1);
          return (OOC_SSA__Result)i2;
l12:
          _failed_function(3785); return 0;
          ;
        }


      i0 = (OOC_INT32)value;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4796)))), &_td_OOC_IR__IndexDesc);
      if (!i1) goto l9;
l4_loop:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4838)))), &_td_OOC_IR__IndexDesc, 4838)), 4844))+8);
      i1 = dim;
      value = (OOC_IR__Expression)i0;
      dim = (i1+1);
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4796)))), &_td_OOC_IR__IndexDesc);
      if (i1) goto l4_loop;
l9:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4964))+4);
      type = (OOC_SymbolTable__Type)i0;
      i = 0;
      i1 = dim;
      i2 = 0<=i1;
      if (!i2) goto l18;
      i2=0;
l13_loop:
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5019)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
      type = (OOC_SymbolTable__Type)i0;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5056)))), &_td_OOC_SymbolTable__ArrayDesc, 5056)), 5062))+44);
      type = (OOC_SymbolTable__Type)i0;
      i2 = i2+1;
      i = i2;
      i3 = i2<=i1;
      if (i3) goto l13_loop;
l18:
      i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_CalculateLength_RecursiveGetLength((OOC_SymbolTable__Type)i0, i1);
      return (OOC_SSA__Result)i0;
      ;
    }

    
    OOC_SSA__Instr OOC_SSA_IRtoSSA__StatmSeq_CalculateSize(OOC_SSA__ProcBlock pb, OOC_IR__Expression value, OOC_SSA__Result length) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_SymbolTable__Type type;
      OOC_SSA__Instr size;

      i0 = (OOC_INT32)value;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5634)))), &_td_OOC_IR__IndexDesc);
      if (!i1) goto l9;
l4_loop:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5676)))), &_td_OOC_IR__IndexDesc, 5676)), 5682))+8);
      value = (OOC_IR__Expression)i0;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5634)))), &_td_OOC_IR__IndexDesc);
      if (i1) goto l4_loop;
l9:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5782))+4);
      type = (OOC_SymbolTable__Type)i0;
      i1 = OOC_SymbolTable_TypeRules__IsArrayType((OOC_SymbolTable__Type)i0);
      if (!i1) goto l18;
l13_loop:
      i0 = (OOC_INT32)OOC_SymbolTable_TypeRules__ArrayElementType((OOC_SymbolTable__Type)i0);
      type = (OOC_SymbolTable__Type)i0;
      i1 = OOC_SymbolTable_TypeRules__IsArrayType((OOC_SymbolTable__Type)i0);
      if (i1) goto l13_loop;
l18:
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5897)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
      type = (OOC_SymbolTable__Type)i0;
      i1 = (OOC_INT32)pb;
      i2 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i1, 22, 9);
      size = (OOC_SSA__Instr)i2;
      i3 = (OOC_INT32)length;
      i3 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_FixAddress((OOC_SSA__Result)i3);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i3, 1);
      i0 = *(OOC_INT32*)((_check_pointer(i0, 6078))+32);
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConstInt((OOC_SSA__ProcBlock)i1, i0);
      i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_FixAddress((OOC_SSA__Result)i0);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i0, 1);
      return (OOC_SSA__Instr)i2;
      ;
    }

    
    OOC_SymbolTable__Type OOC_SSA_IRtoSSA__StatmSeq_TypeOfString(OOC_SymbolTable__Type type) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)type;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6221)))), &_td_OOC_SymbolTable__ArrayDesc);
      if (i1) goto l11;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6557)))), &_td_OOC_SymbolTable__PredefTypeDesc);
      if (i1) goto l5;
      return (OOC_SymbolTable__Type)(OOC_INT32)0;
      goto l20;
l5:
      i1 = *(OOC_INT16*)((_check_pointer(i0, 6594))+40);
      switch (i1) {
      case 13:
      case 14:
      case 15:
        i0 = *(OOC_INT16*)((_check_pointer(i0, 6714))+40);
        i0 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(((i0-13)+1));
        return (OOC_SymbolTable__Type)i0;
        goto l20;
      default:
        return (OOC_SymbolTable__Type)(OOC_INT32)0;
        goto l20;
      }
l11:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6252))+44);
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6266)))), &_td_OOC_SymbolTable__PredefTypeDesc);
      if (i1) goto l14;
      return (OOC_SymbolTable__Type)(OOC_INT32)0;
      goto l20;
l14:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6309))+44);
      i1 = *(OOC_INT16*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6327)))), &_td_OOC_SymbolTable__PredefTypeDesc, 6327)), 6338))+40);
      switch (i1) {
      case 1:
      case 2:
      case 3:
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6428))+44);
        return (OOC_SymbolTable__Type)i0;
        goto l20;
      default:
        return (OOC_SymbolTable__Type)(OOC_INT32)0;
        goto l20;
      }
l20:
      _failed_function(6155); return 0;
      ;
    }

    
    void OOC_SSA_IRtoSSA__StatmSeq_TransferReadDesign(OOC_SSA__Result source, OOC_SSA__Instr instr) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_SSA__Opnd opnd;

      i0 = (OOC_INT32)source;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6994)))), &_td_OOC_SSA__ConstDesc);
      if (i1) goto l18;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7133))+8);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7140))+24);
      opnd = (OOC_SSA__Opnd)i0;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l19;
      i1 = (OOC_INT32)instr;
      
l5_loop:
      i2 = *(OOC_INT8*)((_check_pointer(i0, 7200))+4);
      i2 = i2==4;
      if (i2) goto l8;
      i2 = *(OOC_INT8*)((_check_pointer(i0, 7245))+4);
      i2 = i2==5;
      
      goto l10;
l8:
      i2=1u;
l10:
      if (!i2) goto l12;
      i2 = *(OOC_INT8*)((_check_pointer(i0, 7320))+4);
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7309));
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i3, i2);
l12:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7367))+8);
      opnd = (OOC_SSA__Opnd)i0;
      i2 = i0!=(OOC_INT32)0;
      if (i2) goto l5_loop;
      goto l19;
l18:
      i1 = (OOC_INT32)instr;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i0, 4);
l19:
      return;
      ;
    }

    
    void OOC_SSA_IRtoSSA__StatmSeq_TransferWriteDesign(OOC_SSA__Result source, OOC_SSA__Instr instr) {
      register OOC_INT32 i0,i1,i2;
      OOC_SSA__Opnd opnd;

      i0 = (OOC_INT32)source;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7564))+8);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7571))+24);
      opnd = (OOC_SSA__Opnd)i0;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l15;
      i1 = (OOC_INT32)instr;
      
l3_loop:
      i2 = *(OOC_INT8*)((_check_pointer(i0, 7627))+4);
      i2 = i2==4;
      if (i2) goto l9;
      i2 = *(OOC_INT8*)((_check_pointer(i0, 7728))+4);
      i2 = i2==5;
      if (!i2) goto l10;
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7790));
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i2, 7);
      goto l10;
l9:
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7686));
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i2, 6);
l10:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7849))+8);
      opnd = (OOC_SSA__Opnd)i0;
      i2 = i0!=(OOC_INT32)0;
      if (i2) goto l3_loop;
l15:
      return;
      ;
    }

    
    OOC_SSA__Instr OOC_SSA_IRtoSSA__StatmSeq_CopyString(OOC_IR__CopyString cp) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
      OOC_SSA__Result source;
      OOC_SSA__Result dest;
      OOC_SSA__Result maxLength;
      OOC_SSA__Instr instr;

      i0 = (OOC_INT32)cp;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8074))+8);
      i1 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i1);
      source = (OOC_SSA__Result)i1;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8113))+12);
      i2 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i2);
      dest = (OOC_SSA__Result)i2;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8155))+16);
      i3 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i3);
      maxLength = (OOC_SSA__Result)i3;
      i4 = (OOC_INT32)pb;
      i4 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i4, 15, 0);
      instr = (OOC_SSA__Instr)i4;
      i5 = (OOC_INT32)s;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i4, (OOC_SSA__Result)i5, 2);
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8326))+8);
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 8334))+4);
      i5 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_TypeOfString((OOC_SymbolTable__Type)i5);
      i6 = (OOC_INT32)pb;
      i5 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetTypeRef((OOC_SSA__ProcBlock)i6, (OOC_SymbolTable__Type)i5);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i4, (OOC_SSA__Result)i5, 12);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8410))+12);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8416))+4);
      i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_TypeOfString((OOC_SymbolTable__Type)i0);
      i5 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetTypeRef((OOC_SSA__ProcBlock)i5, (OOC_SymbolTable__Type)i0);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i4, (OOC_SSA__Result)i0, 12);
      OOC_SSA_IRtoSSA__StatmSeq_TransferReadDesign((OOC_SSA__Result)i1, (OOC_SSA__Instr)i4);
      OOC_SSA_IRtoSSA__StatmSeq_TransferWriteDesign((OOC_SSA__Result)i2, (OOC_SSA__Instr)i4);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i4, (OOC_SSA__Result)i3, 1);
      return (OOC_SSA__Instr)i4;
      ;
    }

    
    OOC_SSA__Instr OOC_SSA_IRtoSSA__StatmSeq_AddException(OOC_SSA__ProcBlock pb, OOC_Scanner_SymList__Symbol sym, OOC_INT8 opcode, OOC_INT8 subclass) {
      register OOC_INT32 i0,i1,i2;

      i0 = subclass;
      i1 = opcode;
      i2 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i2, i1, i0);
      i1 = (OOC_INT32)sym;
      OOC_SSA__InstrDesc_SetPos((OOC_SSA__Instr)i0, (OOC_Scanner_SymList__Symbol)i1);
      i1 = (OOC_INT32)OOC_SSA__InstrDesc_AddResult((OOC_SSA__Instr)i0, 19);
      OOC_SSA_IRtoSSA__StatmSeq_Chain((OOC_SSA__Instr)i0);
      return (OOC_SSA__Instr)i0;
      ;
    }

    
    OOC_SSA__Instr OOC_SSA_IRtoSSA__StatmSeq_TypeTag(OOC_IR__Expression design, OOC_SSA__Result value, OOC_CHAR8 checkDerefOfNil, OOC_Scanner_SymList__Symbol derefSym) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5;
      OOC_SymbolTable__Type type;
      OOC_SSA__Instr check;
      OOC_SSA__Instr instr;

      i0 = (OOC_INT32)design;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9323))+4);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9323))+4);
      i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9328)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i2);
      type = (OOC_SymbolTable__Type)i1;
      i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9358)))), OOC_SymbolTable__TypeDesc_Bound)),OOC_SymbolTable__TypeDesc_Bound)((OOC_SymbolTable__Type)i1);
      type = (OOC_SymbolTable__Type)i1;
      i2 = checkDerefOfNil;
      if (i2) goto l3;
      i2=0u;
      goto l5;
l3:
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9449)))), &_td_OOC_SymbolTable__PointerDesc);
      
l5:
      if (!i2) goto l7;
      i2 = (OOC_INT32)value;
      i3 = *(OOC_INT8*)((_check_pointer(i2, 9572))+5);
      i4 = (OOC_INT32)derefSym;
      i5 = (OOC_INT32)pb;
      i3 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_AddException((OOC_SSA__ProcBlock)i5, (OOC_Scanner_SymList__Symbol)i4, 67, i3);
      check = (OOC_SSA__Instr)i3;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i3, (OOC_SSA__Result)i2, 1);
      value = (OOC_SSA__Result)i3;
l7:
      i2 = (OOC_INT32)pb;
      i2 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i2, 61, 9);
      instr = (OOC_SSA__Instr)i2;
      i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9748)))), &_td_OOC_SymbolTable__PointerDesc);
      if (i3) goto l22;
      i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9831)))), &_td_OOC_IR__VarDesc);
      if (i3) goto l12;
      i3=0u;
      goto l14;
l12:
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9866)))), &_td_OOC_IR__VarDesc, 9866)), 9870))+8);
      i3 = *(OOC_UINT8*)((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 9881)))), &_td_OOC_SymbolTable__VarDeclDesc, 9881)), 9889))+59);
      
l14:
      if (i3) goto l16;
      i0=0u;
      goto l18;
l16:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9938)))), &_td_OOC_IR__VarDesc, 9938)), 9942))+8);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9952)))), &_td_OOC_SymbolTable__VarDeclDesc, 9952)), 9960))+48);
      i0 = OOC_SymbolTable_TypeRules__IsRecord((OOC_SymbolTable__Type)i0);
      
l18:
      if (i0) goto l20;
      i0 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetTypeRef((OOC_SSA__ProcBlock)i0, (OOC_SymbolTable__Type)i1);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i0, 1);
      goto l23;
l20:
      i0 = (OOC_INT32)value;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10043))+8);
      i0 = (OOC_INT32)OOC_SSA__InstrDesc_GetArgClass((OOC_SSA__Instr)i0, 5);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i0, 1);
      goto l23;
l22:
      i0 = (OOC_INT32)value;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i0, 1);
l23:
      return (OOC_SSA__Instr)i2;
      ;
    }

    
    OOC_SSA__Instr OOC_SSA_IRtoSSA__StatmSeq_Copy(OOC_IR__Copy cp) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
      OOC_SSA__Result source;
      OOC_SSA__Result dest;
      OOC_SSA__Instr dynTag;
      OOC_SSA__Instr staticTag;
      OOC_SSA__Instr neq;
      OOC_SSA__Result okStore;
      OOC_SSA__Instr failed;
      OOC_SSA__Instr select;
      OOC_SSA__Instr instr;

      i0 = (OOC_INT32)cp;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10460))+8);
      i1 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i1);
      source = (OOC_SSA__Result)i1;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10499))+12);
      i2 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i2);
      dest = (OOC_SSA__Result)i2;
      i3 = *(OOC_UINT8*)((_check_pointer(i0, 10520))+16);
      if (!i3) goto l3;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10573))+12);
      i3 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_TypeTag((OOC_IR__Expression)i3, (OOC_SSA__Result)i2, 0u, (OOC_Scanner_SymList__Symbol)(OOC_INT32)0);
      dynTag = (OOC_SSA__Instr)i3;
      i4 = (OOC_INT32)pb;
      i4 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i4, 61, 9);
      staticTag = (OOC_SSA__Instr)i4;
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10716))+12);
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 10722))+4);
      i6 = (OOC_INT32)pb;
      i5 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetTypeRef((OOC_SSA__ProcBlock)i6, (OOC_SymbolTable__Type)i5);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i4, (OOC_SSA__Result)i5, 1);
      i5 = (OOC_INT32)pb;
      i5 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i5, 26, 9);
      neq = (OOC_SSA__Instr)i5;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i5, (OOC_SSA__Result)i4, 1);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i5, (OOC_SSA__Result)i3, 1);
      i3 = (OOC_INT32)s;
      okStore = (OOC_SSA__Result)i3;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10957))+12);
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 10963));
      i6 = (OOC_INT32)pb;
      i4 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_AddException((OOC_SSA__ProcBlock)i6, (OOC_Scanner_SymList__Symbol)i4, 71, 0);
      failed = (OOC_SSA__Instr)i4;
      i4 = (OOC_INT32)pb;
      i4 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i4, 5, 0);
      select = (OOC_SSA__Instr)i4;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i4, (OOC_SSA__Result)i5, 1);
      i5 = (OOC_INT32)pb;
      i5 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConstBool((OOC_SSA__ProcBlock)i5, 1u);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i4, (OOC_SSA__Result)i5, 1);
      i5 = (OOC_INT32)s;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i4, (OOC_SSA__Result)i5, 1);
      i5 = (OOC_INT32)pb;
      i5 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConstBool((OOC_SSA__ProcBlock)i5, 0u);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i4, (OOC_SSA__Result)i5, 1);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i4, (OOC_SSA__Result)i3, 1);
      i3 = (OOC_INT32)OOC_SSA__InstrDesc_AddResult((OOC_SSA__Instr)i4, 2);
      s = (OOC_SSA__Result)i3;
l3:
      i3 = (OOC_INT32)pb;
      i3 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i3, 14, 0);
      instr = (OOC_SSA__Instr)i3;
      i4 = (OOC_INT32)s;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i3, (OOC_SSA__Result)i4, 2);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11565))+12);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11571))+4);
      i4 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetTypeRef((OOC_SSA__ProcBlock)i4, (OOC_SymbolTable__Type)i0);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i3, (OOC_SSA__Result)i0, 12);
      OOC_SSA_IRtoSSA__StatmSeq_TransferReadDesign((OOC_SSA__Result)i1, (OOC_SSA__Instr)i3);
      OOC_SSA_IRtoSSA__StatmSeq_TransferWriteDesign((OOC_SSA__Result)i2, (OOC_SSA__Instr)i3);
      return (OOC_SSA__Instr)i3;
      ;
    }

    
    OOC_SSA__Result OOC_SSA_IRtoSSA__StatmSeq_Expression(OOC_IR__Expression expr) {
      register OOC_INT32 i0,i1,i2,i3,i4;
      Object_Boxed__Object v;
      Object_BigInt__BigInt x;
      OOC_SSA__Instr instr;
      OOC_SSA__Result res;
      OOC_SSA__Result baseArray;
      OOC_SymbolTable__Type type;
      OOC_INT32 dim;
      OOC_INT8 opcode;
      auto OOC_SSA__Result OOC_SSA_IRtoSSA__StatmSeq_Expression_Deref(OOC_IR__Deref deref);
      auto OOC_SSA__Result OOC_SSA_IRtoSSA__StatmSeq_Expression_GetIndexBaseArray(OOC_IR__Expression indexOp, OOC_INT32 *dim);
      auto OOC_SSA__Result OOC_SSA_IRtoSSA__StatmSeq_Expression_Index(OOC_IR__Index indexOp, OOC_SSA__Result baseArray, OOC_SSA__Result elementSize, OOC_INT32 dim);
      auto OOC_SSA__Result OOC_SSA_IRtoSSA__StatmSeq_Expression_SelectField(OOC_IR__SelectField selectOp);
      auto OOC_SSA__Instr OOC_SSA_IRtoSSA__StatmSeq_Expression_AddCompareOp(OOC_IR__Compare op, OOC_INT8 _class);
      auto OOC_SSA__Instr OOC_SSA_IRtoSSA__StatmSeq_Expression_NewObject(OOC_IR__NewObject _new);
      auto OOC_SSA__Instr OOC_SSA_IRtoSSA__StatmSeq_Expression_NewBlock(OOC_IR__NewBlock _new);
      auto OOC_SSA__Result OOC_SSA_IRtoSSA__StatmSeq_Expression_ShortcutAnd(OOC_IR__Expression left, OOC_IR__Expression right);
      auto OOC_SSA__Result OOC_SSA_IRtoSSA__StatmSeq_Expression_ShortcutOr(OOC_IR__Expression left, OOC_IR__Expression right);
      auto OOC_SSA__Instr OOC_SSA_IRtoSSA__StatmSeq_Expression_TypeTest(OOC_IR__TypeTest test);
      auto OOC_SSA__Result OOC_SSA_IRtoSSA__StatmSeq_Expression_TypeGuard(OOC_IR__TypeGuard guard);
      auto OOC_SSA__Result OOC_SSA_IRtoSSA__StatmSeq_Expression_TypeCast(OOC_IR__TypeCast cast);
      auto OOC_SSA__Result OOC_SSA_IRtoSSA__StatmSeq_Expression_TypeConv(OOC_IR__TypeConv conv);
      auto OOC_SSA__Result OOC_SSA_IRtoSSA__StatmSeq_Expression_SelectProc(OOC_IR__SelectProc selectOp);
      auto OOC_SSA__Result OOC_SSA_IRtoSSA__StatmSeq_Expression_Concat(OOC_IR__Concat expr);
      auto OOC_SSA__Result OOC_SSA_IRtoSSA__StatmSeq_Expression_Constructor(OOC_IR__Constructor expr);
        
        OOC_SSA__Result OOC_SSA_IRtoSSA__StatmSeq_Expression_Deref(OOC_IR__Deref deref) {
          register OOC_INT32 i0,i1,i2,i3,i4;
          OOC_SSA__Result address;
          OOC_SSA__Instr check;
          OOC_SSA__Instr instr;

          i0 = (OOC_INT32)deref;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12224))+8);
          i1 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i1);
          address = (OOC_SSA__Result)i1;
          i2 = *(OOC_UINT8*)((_check_pointer(i0, 12252))+12);
          if (!i2) goto l4;
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 12314));
          i3 = *(OOC_INT8*)((_check_pointer(i1, 12382))+5);
          i4 = (OOC_INT32)pb;
          i2 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_AddException((OOC_SSA__ProcBlock)i4, (OOC_Scanner_SymList__Symbol)i2, 67, i3);
          check = (OOC_SSA__Instr)i2;
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i1, 1);
          address = (OOC_SSA__Result)i2;
          i1=i2;
l4:
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12562))+4);
          i2 = OOC_SSA_Opcode__TypeToSubclass((OOC_SymbolTable__Type)i2);
          i3 = (OOC_INT32)pb;
          i2 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i3, 12, i2);
          instr = (OOC_SSA__Instr)i2;
          i3 = (OOC_INT32)s;
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i3, 2);
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i1, 4);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12704))+8);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12713))+4);
          i3 = (OOC_INT32)pb;
          i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetTypeRef((OOC_SSA__ProcBlock)i3, (OOC_SymbolTable__Type)i0);
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i0, 5);
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i1, 5);
          OOC_SSA_IRtoSSA__StatmSeq_Chain((OOC_SSA__Instr)i2);
          return (OOC_SSA__Result)i2;
          ;
        }

        
        OOC_SSA__Result OOC_SSA_IRtoSSA__StatmSeq_Expression_GetIndexBaseArray(OOC_IR__Expression indexOp, OOC_INT32 *dim) {
          register OOC_INT32 i0,i1;

          i0 = (OOC_INT32)indexOp;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13008)))), &_td_OOC_IR__IndexDesc);
          if (i1) goto l3;
          *dim = (-1);
          i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i0);
          return (OOC_SSA__Result)i0;
          goto l4;
l3:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13065))+8);
          i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression_GetIndexBaseArray((OOC_IR__Expression)i0, (void*)(OOC_INT32)dim);
          i1 = *dim;
          *dim = (i1+1);
          return (OOC_SSA__Result)i0;
l4:
          _failed_function(12867); return 0;
          ;
        }

        
        OOC_SSA__Result OOC_SSA_IRtoSSA__StatmSeq_Expression_Index(OOC_IR__Index indexOp, OOC_SSA__Result baseArray, OOC_SSA__Result elementSize, OOC_INT32 dim) {
          register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
          OOC_SymbolTable__Type arrayType;
          OOC_SSA__Result length;
          OOC_SSA__Instr newSize;
          OOC_SSA__Result baseResult;
          OOC_SSA__Instr instr;
          OOC_SSA__Result index;
          OOC_SSA__Instr check;
          OOC_SymbolTable__Type elementType;
          OOC_SSA__Instr scaledIndex;
          OOC_SSA__Opnd adrOpnd;
          OOC_SSA__Instr elementAdr;

          i0 = (OOC_INT32)indexOp;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14127))+8);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14127))+8);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14133))+4);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14133))+4);
          i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 14138)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i1);
          arrayType = (OOC_SymbolTable__Type)i1;
          i2 = (OOC_INT32)baseArray;
          i3 = (OOC_INT32)pb;
          i4 = dim;
          i1 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddGetLengthInstr((OOC_SSA__ProcBlock)i3, (OOC_SSA__Instr)(_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 14205)))), &_td_OOC_SSA__InstrDesc, 14205)), i4, (OOC_SymbolTable__Array)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14273)))), &_td_OOC_SymbolTable__ArrayDesc, 14273)));
          length = (OOC_SSA__Result)i1;
          i3 = (OOC_INT32)pb;
          i3 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i3, 22, 9);
          newSize = (OOC_SSA__Instr)i3;
          i5 = (OOC_INT32)elementSize;
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i3, (OOC_SSA__Result)i5, 1);
          i6 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_FixAddress((OOC_SSA__Result)i1);
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i3, (OOC_SSA__Result)i6, 1);
          i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14486))+8);
          i6 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 14494)))), &_td_OOC_IR__IndexDesc);
          if (i6) goto l3;
          baseResult = (OOC_SSA__Result)i2;
          _assert((i4==0), 127, 14686);
          
          goto l4;
l3:
          i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14550))+8);
          i2 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression_Index((OOC_IR__Index)(_type_guard(i6, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 14561)))), &_td_OOC_IR__IndexDesc, 14561)), (OOC_SSA__Result)i2, (OOC_SSA__Result)i3, (i4-1));
          baseResult = (OOC_SSA__Result)i2;
          
l4:
          dim = (i4+1);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14762))+8);
          i3 = *(OOC_INT8*)((_check_pointer(i3, 14769))+36);
          _assert((i3==12), 127, 14744);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 15144))+8);
          instr = (OOC_SSA__Instr)i2;
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 15171))+24);
          i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 15181));
          s = (OOC_SSA__Result)i3;
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15224))+12);
          i3 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i3);
          index = (OOC_SSA__Result)i3;
          i4 = *(OOC_UINT8*)((_check_pointer(i0, 15252))+16);
          if (i4) goto l7;
          i1=i3;
          goto l8;
l7:
          i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 15314));
          i6 = *(OOC_INT8*)((_check_pointer(i3, 15378))+5);
          i7 = (OOC_INT32)pb;
          i4 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_AddException((OOC_SSA__ProcBlock)i7, (OOC_Scanner_SymList__Symbol)i4, 66, i6);
          check = (OOC_SSA__Instr)i4;
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i4, (OOC_SSA__Result)i3, 1);
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i4, (OOC_SSA__Result)i1, 1);
          index = (OOC_SSA__Result)i4;
          i1=i4;
l8:
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 15533))+24);
          i4 = (OOC_INT32)s;
          OOC_SSA__OpndDesc_ReplaceArg((OOC_SSA__Opnd)i3, (OOC_SSA__Result)i4);
          i3 = (OOC_INT32)OOC_SSA__InstrDesc_GetResultStore((OOC_SSA__Instr)i2);
          s = (OOC_SSA__Result)i3;
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15642))+4);
          elementType = (OOC_SymbolTable__Type)i3;
          i3 = (OOC_INT32)pb;
          i3 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i3, 22, 9);
          scaledIndex = (OOC_SSA__Instr)i3;
          i4 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_FixAddress((OOC_SSA__Result)i1);
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i3, (OOC_SSA__Result)i4, 1);
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i3, (OOC_SSA__Result)i5, 1);
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 15870))+24);
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 15880))+8);
          adrOpnd = (OOC_SSA__Opnd)i4;
          i5 = (OOC_INT32)pb;
          i5 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i5, 19, 9);
          elementAdr = (OOC_SSA__Instr)i5;
          i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 15995));
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i5, (OOC_SSA__Result)i6, 1);
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i5, (OOC_SSA__Result)i3, 1);
          OOC_SSA__OpndDesc_ReplaceArg((OOC_SSA__Opnd)i4, (OOC_SSA__Result)i5);
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i1, 5);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16216))+4);
          i0 = OOC_SSA_Opcode__TypeToSubclass((OOC_SymbolTable__Type)i0);
          OOC_SSA__InstrDesc_SetSubclass((OOC_SSA__Instr)i2, i0);
          return (OOC_SSA__Result)i2;
          ;
        }

        
        OOC_SSA__Result OOC_SSA_IRtoSSA__StatmSeq_Expression_SelectField(OOC_IR__SelectField selectOp) {
          register OOC_INT32 i0,i1,i2,i3,i4,i5;
          OOC_SSA__Result baseResult;
          OOC_SSA__Instr instr;
          OOC_SSA__Opnd adrOpnd;
          OOC_SSA__Instr fieldAdr;
          OOC_SSA__Result offset;

          i0 = (OOC_INT32)selectOp;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16630))+8);
          i1 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i1);
          baseResult = (OOC_SSA__Result)i1;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 16667))+8);
          i2 = *(OOC_INT8*)((_check_pointer(i2, 16674))+36);
          _assert((i2==12), 127, 16649);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 16725))+8);
          instr = (OOC_SSA__Instr)i1;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 16767))+24);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 16777))+8);
          adrOpnd = (OOC_SSA__Opnd)i2;
          i3 = (OOC_INT32)pb;
          i3 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i3, 19, 9);
          fieldAdr = (OOC_SSA__Instr)i3;
          i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 16888));
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i3, (OOC_SSA__Result)i4, 1);
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16947))+12);
          i4 = *(OOC_INT32*)((_check_pointer(i4, 16953))+56);
          i5 = (OOC_INT32)pb;
          i4 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConstInt((OOC_SSA__ProcBlock)i5, i4);
          offset = (OOC_SSA__Result)i4;
          i4 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_FixAddress((OOC_SSA__Result)i4);
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i3, (OOC_SSA__Result)i4, 1);
          OOC_SSA__OpndDesc_ReplaceArg((OOC_SSA__Opnd)i2, (OOC_SSA__Result)i3);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17107))+12);
          i3 = (OOC_INT32)pb;
          i2 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetDeclRef((OOC_SSA__ProcBlock)i3, (OOC_SymbolTable__Declaration)i2);
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i2, 5);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17194))+12);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17201))+48);
          i0 = OOC_SSA_Opcode__TypeToSubclass((OOC_SymbolTable__Type)i0);
          OOC_SSA__InstrDesc_SetSubclass((OOC_SSA__Instr)i1, i0);
          return (OOC_SSA__Result)i1;
          ;
        }

        
        OOC_SSA__Instr OOC_SSA_IRtoSSA__StatmSeq_Expression_AddCompareOp(OOC_IR__Compare op, OOC_INT8 _class) {
          register OOC_INT32 i0,i1,i2,i3,i4;
          OOC_SymbolTable__Type typeOfString;
          OOC_SSA__Result left;

          i0 = (OOC_INT32)op;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17495))+12);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 17501))+4);
          i1 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_TypeOfString((OOC_SymbolTable__Type)i1);
          typeOfString = (OOC_SymbolTable__Type)i1;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17540))+12);
          i2 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i2);
          left = (OOC_SSA__Result)i2;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17580))+16);
          i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i0);
          i3 = i1!=(OOC_INT32)0;
          if (i3) goto l3;
          i1=i0;i0=i2;
          goto l4;
l3:
          i3 = (OOC_INT32)pb;
          i3 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i3, 16, 3);
          i4 = (OOC_INT32)s;
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i3, (OOC_SSA__Result)i4, 2);
          i4 = (OOC_INT32)pb;
          i1 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetTypeRef((OOC_SSA__ProcBlock)i4, (OOC_SymbolTable__Type)i1);
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i3, (OOC_SSA__Result)i1, 12);
          OOC_SSA_IRtoSSA__StatmSeq_TransferReadDesign((OOC_SSA__Result)i2, (OOC_SSA__Instr)i3);
          OOC_SSA_IRtoSSA__StatmSeq_TransferReadDesign((OOC_SSA__Result)i0, (OOC_SSA__Instr)i3);
          i0 = (OOC_INT32)pb;
          i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConstInt((OOC_SSA__ProcBlock)i0, 0);
          i1=i0;i0=i3;
l4:
          i2 = _class;
          i3 = (OOC_INT32)pb;
          i2 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i3, i2, 5);
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i0, 1);
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i1, 1);
          return (OOC_SSA__Instr)i2;
          ;
        }

        
        OOC_SSA__Instr OOC_SSA_IRtoSSA__StatmSeq_Expression_NewObject(OOC_IR__NewObject _new) {
          register OOC_INT32 i0,i1,i2,i3,i4,i5;
          OOC_SSA__Instr instr;
          OOC_INT32 i;

          i0 = (OOC_INT32)pb;
          i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i0, 59, 9);
          instr = (OOC_SSA__Instr)i0;
          i1 = (OOC_INT32)s;
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i1, 2);
          i1 = (OOC_INT32)_new;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 18491))+4);
          i3 = (OOC_INT32)pb;
          i2 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetTypeRef((OOC_SSA__ProcBlock)i3, (OOC_SymbolTable__Type)i2);
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i2, 12);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 18527))+8);
          i2 = i2!=(OOC_INT32)0;
          if (!i2) goto l11;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 18580))+8);
          i = 0;
          i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 18588)), 0);
          i3 = 0<i2;
          if (!i3) goto l11;
          i3=0;
l5_loop:
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 18639))+8);
          i4 = _check_pointer(i4, 18647);
          i5 = OOC_ARRAY_LENGTH(i4, 0);
          i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 18647))*4);
          i4 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i4);
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i4, 1);
          i3 = i3+1;
          i = i3;
          i4 = i3<i2;
          if (i4) goto l5_loop;
l11:
          OOC_SSA_IRtoSSA__StatmSeq_Chain((OOC_SSA__Instr)i0);
          return (OOC_SSA__Instr)i0;
          ;
        }

        
        OOC_SSA__Instr OOC_SSA_IRtoSSA__StatmSeq_Expression_NewBlock(OOC_IR__NewBlock _new) {
          register OOC_INT32 i0,i1,i2,i3;
          OOC_SSA__Instr instr;

          i0 = (OOC_INT32)pb;
          i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i0, 60, 9);
          instr = (OOC_SSA__Instr)i0;
          i1 = (OOC_INT32)s;
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i1, 2);
          i1 = (OOC_INT32)_new;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 19011))+4);
          i3 = (OOC_INT32)pb;
          i2 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetTypeRef((OOC_SSA__ProcBlock)i3, (OOC_SymbolTable__Type)i2);
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i2, 12);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 19071))+8);
          i1 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i1);
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i1, 1);
          OOC_SSA_IRtoSSA__StatmSeq_Chain((OOC_SSA__Instr)i0);
          return (OOC_SSA__Instr)i0;
          ;
        }

        
        OOC_SSA__Result OOC_SSA_IRtoSSA__StatmSeq_Expression_ShortcutAnd(OOC_IR__Expression left, OOC_IR__Expression right) {
          register OOC_INT32 i0,i1,i2,i3,i4;

          i0 = (OOC_INT32)pb;
          i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i0, 5, 0);
          i1 = (OOC_INT32)left;
          i1 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i1);
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i1, 1);
          i1 = (OOC_INT32)s;
          i2 = (OOC_INT32)pb;
          i2 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConstBool((OOC_SSA__ProcBlock)i2, 1u);
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i2, 1);
          i2 = (OOC_INT32)right;
          i2 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i2);
          i3 = (OOC_INT32)pb;
          i3 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i3, 6, 0);
          i4 = (OOC_INT32)s;
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i3, (OOC_SSA__Result)i4, 2);
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i3, (OOC_SSA__Result)i2, 1);
          i2 = (OOC_INT32)OOC_SSA__InstrDesc_AddResult((OOC_SSA__Instr)i3, 2);
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i2, 1);
          i2 = (OOC_INT32)pb;
          i2 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConstBool((OOC_SSA__ProcBlock)i2, 0u);
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i2, 1);
          i2 = (OOC_INT32)pb;
          i2 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i2, 6, 0);
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i1, 2);
          i1 = (OOC_INT32)pb;
          i1 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConstBool((OOC_SSA__ProcBlock)i1, 0u);
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i1, 1);
          i1 = (OOC_INT32)OOC_SSA__InstrDesc_AddResult((OOC_SSA__Instr)i2, 2);
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i1, 1);
          i1 = (OOC_INT32)OOC_SSA__InstrDesc_AddResult((OOC_SSA__Instr)i0, 2);
          s = (OOC_SSA__Result)i1;
          i0 = (OOC_INT32)OOC_SSA__InstrDesc_AddResultSubclass((OOC_SSA__Instr)i0, 14, 5);
          return (OOC_SSA__Result)i0;
          ;
        }

        
        OOC_SSA__Result OOC_SSA_IRtoSSA__StatmSeq_Expression_ShortcutOr(OOC_IR__Expression left, OOC_IR__Expression right) {
          register OOC_INT32 i0,i1,i2,i3;

          i0 = (OOC_INT32)pb;
          i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i0, 5, 0);
          i1 = (OOC_INT32)left;
          i1 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i1);
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i1, 1);
          i1 = (OOC_INT32)s;
          i2 = (OOC_INT32)pb;
          i2 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConstBool((OOC_SSA__ProcBlock)i2, 1u);
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i2, 1);
          i2 = (OOC_INT32)pb;
          i2 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i2, 6, 0);
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i1, 2);
          i1 = (OOC_INT32)pb;
          i1 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConstBool((OOC_SSA__ProcBlock)i1, 1u);
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i1, 1);
          i1 = (OOC_INT32)OOC_SSA__InstrDesc_AddResult((OOC_SSA__Instr)i2, 2);
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i1, 1);
          i1 = (OOC_INT32)pb;
          i1 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConstBool((OOC_SSA__ProcBlock)i1, 0u);
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i1, 1);
          i1 = (OOC_INT32)right;
          i1 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i1);
          i2 = (OOC_INT32)pb;
          i2 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i2, 6, 0);
          i3 = (OOC_INT32)s;
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i3, 2);
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i1, 1);
          i1 = (OOC_INT32)OOC_SSA__InstrDesc_AddResult((OOC_SSA__Instr)i2, 2);
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i1, 1);
          i1 = (OOC_INT32)OOC_SSA__InstrDesc_AddResult((OOC_SSA__Instr)i0, 2);
          s = (OOC_SSA__Result)i1;
          i0 = (OOC_INT32)OOC_SSA__InstrDesc_AddResultSubclass((OOC_SSA__Instr)i0, 14, 5);
          return (OOC_SSA__Result)i0;
          ;
        }

        
        OOC_SSA__Instr OOC_SSA_IRtoSSA__StatmSeq_Expression_TypeTest(OOC_IR__TypeTest test) {
          register OOC_INT32 i0,i1,i2,i3,i4,i5;
          OOC_SSA__Instr instr;

          i0 = (OOC_INT32)pb;
          i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i0, 62, 5);
          instr = (OOC_SSA__Instr)i0;
          i1 = (OOC_INT32)test;
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 21708));
          i3 = *(OOC_UINT8*)((_check_pointer(i1, 21688))+16);
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 21642))+8);
          i4 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i4);
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 21618))+8);
          i2 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_TypeTag((OOC_IR__Expression)i5, (OOC_SSA__Result)i4, i3, (OOC_Scanner_SymList__Symbol)i2);
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i2, 1);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 21795))+12);
          i2 = (OOC_INT32)pb;
          i1 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetTypeRef((OOC_SSA__ProcBlock)i2, (OOC_SymbolTable__Type)i1);
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i1, 12);
          return (OOC_SSA__Instr)i0;
          ;
        }

        
        OOC_SSA__Result OOC_SSA_IRtoSSA__StatmSeq_Expression_TypeGuard(OOC_IR__TypeGuard guard) {
          register OOC_INT32 i0,i1,i2,i3,i4;
          OOC_SSA__Result design;
          OOC_SSA__Instr tag;
          OOC_SSA__Instr adr;
          OOC_SSA__Instr instr;
          auto OOC_SSA__Instr OOC_SSA_IRtoSSA__StatmSeq_Expression_TypeGuard_NewTypeGuard(OOC_SSA__Result adr, OOC_SSA__Result tag);
            
            OOC_SSA__Instr OOC_SSA_IRtoSSA__StatmSeq_Expression_TypeGuard_NewTypeGuard(OOC_SSA__Result adr, OOC_SSA__Result tag) {
              register OOC_INT32 i0,i1,i2,i3;
              OOC_SSA__Instr instr;

              i0 = (OOC_INT32)adr;
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22242))+8);
              i2 = (OOC_INT32)guard;
              i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 22165))+8);
              i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 22171))+24);
              i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 22181));
              i1 = *(OOC_INT8*)((_check_pointer(i1, 22249))+5);
              i3 = (OOC_INT32)pb;
              i1 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_AddException((OOC_SSA__ProcBlock)i3, (OOC_Scanner_SymList__Symbol)i2, 68, i1);
              instr = (OOC_SSA__Instr)i1;
              OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i0, 1);
              i0 = (OOC_INT32)tag;
              OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i0, 1);
              i0 = (OOC_INT32)guard;
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22393))+8);
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22399))+12);
              i2 = (OOC_INT32)pb;
              i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetTypeRef((OOC_SSA__ProcBlock)i2, (OOC_SymbolTable__Type)i0);
              OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i0, 12);
              return (OOC_SSA__Instr)i1;
              ;
            }


          i0 = (OOC_INT32)guard;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22559))+8);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 22565))+8);
          i1 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i1);
          design = (OOC_SSA__Result)i1;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 22596))+8);
          i2 = *(OOC_INT8*)((_check_pointer(i2, 22603))+36);
          _assert((i2==12), 127, 22582);
          i2 = *(OOC_UINT8*)((_check_pointer(i0, 22644))+13);
          if (i2) goto l3;
          return (OOC_SSA__Result)i1;
          goto l16;
l3:
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22692))+8);
          i3 = *(OOC_UINT8*)((_check_pointer(i0, 22745))+12);
          i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 22766));
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 22698))+8);
          i2 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_TypeTag((OOC_IR__Expression)i2, (OOC_SSA__Result)i1, i3, (OOC_Scanner_SymList__Symbol)i4);
          tag = (OOC_SSA__Instr)i2;
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22793))+8);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 22799))+20);
          i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 22810)))), &_td_OOC_IR__VarDesc);
          if (i3) goto l6;
          i3=0u;
          goto l8;
l6:
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22842))+8);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 22848))+20);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 22858))+4);
          i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 22865)))), &_td_OOC_SymbolTable__RecordDesc);
          
l8:
          if (i3) goto l14;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23221))+8);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23226))+20);
          i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 23236)))), &_td_OOC_IR__DerefDesc);
          if (i0) goto l12;
          i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression_TypeGuard_NewTypeGuard((OOC_SSA__Result)i1, (OOC_SSA__Result)i2);
          return (OOC_SSA__Result)i0;
          goto l16;
l12:
          i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression_TypeGuard_NewTypeGuard((OOC_SSA__Result)i1, (OOC_SSA__Result)i2);
          adr = (OOC_SSA__Instr)i0;
          i1 = (OOC_INT32)guard;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23509))+4);
          i2 = OOC_SSA_Opcode__TypeToSubclass((OOC_SymbolTable__Type)i2);
          i3 = (OOC_INT32)pb;
          i2 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i3, 12, i2);
          instr = (OOC_SSA__Instr)i2;
          i3 = (OOC_INT32)s;
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i3, 2);
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i0, 4);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23651))+8);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23656))+8);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23661))+4);
          i3 = (OOC_INT32)pb;
          i1 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetTypeRef((OOC_SSA__ProcBlock)i3, (OOC_SymbolTable__Type)i1);
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i1, 5);
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i0, 5);
          OOC_SSA_IRtoSSA__StatmSeq_Chain((OOC_SSA__Instr)i2);
          return (OOC_SSA__Result)i2;
          goto l16;
l14:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23131))+8);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23138))+24);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23148))+8);
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 23158));
          i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression_TypeGuard_NewTypeGuard((OOC_SSA__Result)i0, (OOC_SSA__Result)i2);
          i1 = (OOC_INT32)design;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23054))+8);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 23061))+24);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 23071))+8);
          OOC_SSA__OpndDesc_ReplaceArg((OOC_SSA__Opnd)i2, (OOC_SSA__Result)i0);
          return (OOC_SSA__Result)i1;
l16:
          _failed_function(21885); return 0;
          ;
        }

        
        OOC_SSA__Result OOC_SSA_IRtoSSA__StatmSeq_Expression_TypeCast(OOC_IR__TypeCast cast) {
          register OOC_INT32 i0,i1,i2;
          OOC_INT8 scDest;
          OOC_SSA__Instr instr;

          i0 = (OOC_INT32)cast;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24151))+4);
          i1 = OOC_SSA_Opcode__TypeToSubclass((OOC_SymbolTable__Type)i1);
          scDest = i1;
          i2 = (OOC_INT32)pb;
          i1 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i2, 41, i1);
          instr = (OOC_SSA__Instr)i1;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24257))+8);
          i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i0);
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i0, 1);
          return (OOC_SSA__Result)i1;
          ;
        }

        
        OOC_SSA__Result OOC_SSA_IRtoSSA__StatmSeq_Expression_TypeConv(OOC_IR__TypeConv conv) {
          register OOC_INT32 i0,i1,i2,i3,i4,i5;
          OOC_SSA__Result _const;
          OOC_SSA__Instr instr;
          Object__String fct;
          OOC_INT8 scDest;
          OOC_INT8 scSource;

          i0 = (OOC_INT32)conv;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24568))+4);
          i1 = OOC_SymbolTable_TypeRules__IsSTRING((OOC_SymbolTable__Type)i1);
          if (i1) goto l7;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26164))+4);
          i1 = OOC_SSA_Opcode__TypeToSubclass((OOC_SymbolTable__Type)i1);
          scDest = i1;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26222))+8);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 26228))+4);
          i2 = OOC_SSA_Opcode__TypeToSubclass((OOC_SymbolTable__Type)i2);
          scSource = i2;
          i2 = i1!=i2;
          if (i2) goto l5;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26476))+8);
          i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i0);
          return (OOC_SSA__Result)i0;
          goto l20;
l5:
          i2 = (OOC_INT32)pb;
          i1 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i2, 42, i1);
          instr = (OOC_SSA__Instr)i1;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26380))+8);
          i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i0);
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i0, 1);
          return (OOC_SSA__Result)i1;
          goto l20;
l7:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24682))+8);
          i1 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i1);
          _const = (OOC_SSA__Result)i1;
          i2 = (OOC_INT32)pb;
          i2 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i2, 81, 9);
          instr = (OOC_SSA__Instr)i2;
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24791))+8);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 24796))+4);
          i3 = *(OOC_INT16*)((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 24806)))), &_td_OOC_SymbolTable__PredefTypeDesc, 24806)), 24817))+40);
          switch (i3) {
          case 1:
            i3 = (OOC_INT32)Object__NewLatin1("Object__NewLatin1Char", 22);
            fct = (Object__String)i3;
            goto l16;
          case 13:
            i3 = (OOC_INT32)Object__NewLatin1("Object__NewLatin1Region", 24);
            fct = (Object__String)i3;
            goto l16;
          case 2:
            i3 = (OOC_INT32)Object__NewLatin1("Object__NewUTF16Char", 21);
            fct = (Object__String)i3;
            goto l16;
          case 14:
            i3 = (OOC_INT32)Object__NewLatin1("Object__NewUTF16Region", 23);
            fct = (Object__String)i3;
            goto l16;
          case 3:
            i3 = (OOC_INT32)Object__NewLatin1("Object__NewUCS4Char", 20);
            fct = (Object__String)i3;
            goto l16;
          case 15:
            i3 = (OOC_INT32)Object__NewLatin1("Object__NewUCS4Region", 22);
            fct = (Object__String)i3;
            goto l16;
          default:
            _failed_case(i3, 24782);
            goto l16;
          }
l16:
          i3 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(13);
          i4 = (OOC_INT32)fct;
          i4 = (OOC_INT32)Object_Boxed__NewString((Object__String)i4);
          i5 = (OOC_INT32)pb;
          i3 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConst((OOC_SSA__ProcBlock)i5, (Object_Boxed__Object)i4, 9, (OOC_SymbolTable__Type)i3);
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i3, 1);
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i1, 1);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25750))+8);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 25755))+4);
          i1 = OOC_SymbolTable_TypeRules__IsStringConst((OOC_SymbolTable__Type)i1);
          if (!i1) goto l19;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25790))+8);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 25799)))), &_td_OOC_IR__ConstDesc, 25799)), 25805))+8);
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 25818)))), &_td_Object_Boxed__StringDesc, 25818)), 25825));
          i0 = *(OOC_INT32*)(_check_pointer(i0, 25831));
          i1 = (OOC_INT32)pb;
          i1 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConstInt((OOC_SSA__ProcBlock)i1, (i0+1));
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i1, 1);
          i1 = (OOC_INT32)pb;
          i1 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConstInt((OOC_SSA__ProcBlock)i1, 0);
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i1, 1);
          i1 = (OOC_INT32)pb;
          i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConstInt((OOC_SSA__ProcBlock)i1, i0);
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i0, 1);
l19:
          return (OOC_SSA__Result)i2;
l20:
          _failed_function(24338); return 0;
          ;
        }

        
        OOC_SSA__Result OOC_SSA_IRtoSSA__StatmSeq_Expression_SelectProc(OOC_IR__SelectProc selectOp) {
          register OOC_INT32 i0,i1,i2,i3,i4;
          OOC_IR__Expression object;
          OOC_SymbolTable__Type type;

          i0 = (OOC_INT32)selectOp;
          i1 = *(OOC_UINT8*)((_check_pointer(i0, 26699))+28);
          if (i1) goto l11;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26887))+8);
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 26898)))), &_td_OOC_IR__DerefDesc);
          if (i1) goto l5;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27022))+8);
          object = (OOC_IR__Expression)i1;
          
          goto l6;
l5:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26946))+8);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 26960)))), &_td_OOC_IR__DerefDesc, 26960)), 26966))+8);
          object = (OOC_IR__Expression)i1;
          
l6:
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27075))+12);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27075))+12);
          i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 27087)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i3);
          type = (OOC_SymbolTable__Type)i2;
          i2 = *(OOC_UINT8*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 27122)))), &_td_OOC_SymbolTable__RecordDesc, 27122)), 27129))+60);
          if (i2) goto l9;
          i2 = (OOC_INT32)pb;
          i2 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i2, 63, 9);
          instr = (OOC_SSA__Instr)i2;
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 27617));
          i3 = *(OOC_UINT8*)((_check_pointer(i0, 27558))+16);
          i4 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i1);
          i1 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_TypeTag((OOC_IR__Expression)i1, (OOC_SSA__Result)i4, i3, (OOC_Scanner_SymList__Symbol)i2);
          i2 = (OOC_INT32)instr;
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i1, 1);
          goto l10;
l9:
          i2 = (OOC_INT32)pb;
          i2 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i2, 87, 9);
          instr = (OOC_SSA__Instr)i2;
          i1 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i1);
          i2 = (OOC_INT32)instr;
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i1, 1);
l10:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27701))+20);
          i1 = (OOC_INT32)pb;
          i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetDeclRef((OOC_SSA__ProcBlock)i1, (OOC_SymbolTable__Declaration)i0);
          i1 = (OOC_INT32)instr;
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i0, 1);
          i0 = (OOC_INT32)instr;
          return (OOC_SSA__Result)i0;
          goto l12;
l11:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26787))+20);
          i1 = (OOC_INT32)pb;
          i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetAddress((OOC_SSA__ProcBlock)i1, (OOC_SymbolTable__Declaration)i0);
          return (OOC_SSA__Result)i0;
l12:
          _failed_function(26552); return 0;
          ;
        }

        
        OOC_SSA__Result OOC_SSA_IRtoSSA__StatmSeq_Expression_Concat(OOC_IR__Concat expr) {
          register OOC_INT32 i0,i1,i2,i3,i4,i5;
          OOC_SSA__Instr instr;
          OOC_INT32 i;

          i0 = (OOC_INT32)pb;
          i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i0, 17, 9);
          instr = (OOC_SSA__Instr)i0;
          i1 = (OOC_INT32)expr;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 27997))+8);
          i = 0;
          i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 28005)), 0);
          i3 = 0<i2;
          if (!i3) goto l8;
          i3=0;
l3_loop:
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 28052))+8);
          i4 = _check_pointer(i4, 28060);
          i5 = OOC_ARRAY_LENGTH(i4, 0);
          i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 28060))*4);
          i4 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i4);
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i4, 1);
          i3 = i3+1;
          i = i3;
          i4 = i3<i2;
          if (i4) goto l3_loop;
l8:
          return (OOC_SSA__Result)i0;
          ;
        }

        
        OOC_SSA__Result OOC_SSA_IRtoSSA__StatmSeq_Expression_Constructor(OOC_IR__Constructor expr) {
          register OOC_INT32 i0,i1,i2;
          OOC_SSA__Result obj;
          OOC_SSA__Result call;

          i0 = (OOC_INT32)expr;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28274))+8);
          i1 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression_NewObject((OOC_IR__NewObject)i1);
          obj = (OOC_SSA__Result)i1;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28299))+12);
          i2 = i2!=(OOC_INT32)0;
          if (!i2) goto l4;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28350))+12);
          i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i0);
          call = (OOC_SSA__Result)i0;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28372))+8);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28378))+24);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28387))+8);
          OOC_SSA__OpndDesc_ReplaceArg((OOC_SSA__Opnd)i0, (OOC_SSA__Result)i1);
l4:
          return (OOC_SSA__Result)i1;
          ;
        }


      i0 = (OOC_INT32)expr;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 28522)))), &_td_OOC_IR__ConstDesc);
      if (i1) goto l194;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 29376)))), &_td_OOC_IR__ProcedureRefDesc);
      if (i1) goto l192;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 29453)))), &_td_OOC_IR__VarDesc);
      if (i1) goto l190;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 29781)))), &_td_OOC_IR__TypeRefDesc);
      if (i1) goto l188;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 29882)))), &_td_OOC_IR__AdrDesc);
      if (i1) goto l182;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 30346)))), &_td_OOC_IR__LenDesc);
      if (i1) goto l176;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 30859)))), &_td_OOC_IR__DerefDesc);
      if (i1) goto l174;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 30923)))), &_td_OOC_IR__IndexDesc);
      if (i1) goto l172;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 31195)))), &_td_OOC_IR__SelectFieldDesc);
      if (i1) goto l170;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 31271)))), &_td_OOC_IR__SelectProcDesc);
      if (i1) goto l168;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 31337)))), &_td_OOC_IR__TypeCastDesc);
      if (i1) goto l166;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 31398)))), &_td_OOC_IR__TypeConvDesc);
      if (i1) goto l164;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 31459)))), &_td_OOC_IR__TypeTagDesc);
      if (i1) goto l162;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 31565)))), &_td_OOC_IR__TypeTestDesc);
      if (i1) goto l160;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 31626)))), &_td_OOC_IR__TypeGuardDesc);
      if (i1) goto l158;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 31698)))), &_td_OOC_IR__NegateDesc);
      if (i1) goto l152;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32088)))), &_td_OOC_IR__NotDesc);
      if (i1) goto l150;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32268)))), &_td_OOC_IR__SetMemberDesc);
      if (i1) goto l148;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32511)))), &_td_OOC_IR__AbsDesc);
      if (i1) goto l146;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32709)))), &_td_OOC_IR__AshDesc);
      if (i1) goto l144;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32964)))), &_td_OOC_IR__CapDesc);
      if (i1) goto l142;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33154)))), &_td_OOC_IR__EntierDesc);
      if (i1) goto l140;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33362)))), &_td_OOC_IR__ShiftDesc);
      if (i1) goto l134;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33733)))), &_td_OOC_IR__OddDesc);
      if (i1) goto l132;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33935)))), &_td_OOC_IR__BinaryArithDesc);
      if (i1) goto l121;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34669)))), &_td_OOC_IR__BooleanOpDesc);
      if (i1) goto l114;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 35010)))), &_td_OOC_IR__SetOpDesc);
      if (i1) goto l105;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 35656)))), &_td_OOC_IR__SetRangeDesc);
      if (i1) goto l103;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 35909)))), &_td_OOC_IR__ChangeElementDesc);
      if (i1) goto l96;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36313)))), &_td_OOC_IR__ConcatDesc);
      if (i1) goto l94;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36378)))), &_td_OOC_IR__CompareDesc);
      if (i1) goto l83;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36996)))), &_td_OOC_IR__NewObjectDesc);
      if (i1) goto l81;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37059)))), &_td_OOC_IR__NewBlockDesc);
      if (i1) goto l79;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37129)))), &_td_OOC_IR__CallDesc);
      if (i1) goto l77;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37475)))), &_td_OOC_IR__ConstructorDesc);
      if (i1) goto l75;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37541)))), &_td_OOC_IR__CurrentExceptionDesc);
      if (i1) goto l73;
      Log__Type("++ Unknown type in Expression", 30, (void*)i0);
      _assert(0u, 127, 37681);
      goto l215;
l73:
      i0 = (OOC_INT32)pb;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 37583))+8);
      return (OOC_SSA__Result)i0;
      goto l215;
l75:
      i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression_Constructor((OOC_IR__Constructor)i0);
      return (OOC_SSA__Result)i0;
      goto l215;
l77:
      i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Call((OOC_IR__Call)i0);
      i1 = (OOC_INT32)s;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i1, 2);
      i1 = (OOC_INT32)OOC_SSA__InstrDesc_AddResult((OOC_SSA__Instr)i0, 2);
      s = (OOC_SSA__Result)i1;
      return (OOC_SSA__Result)i0;
      goto l215;
l79:
      i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression_NewBlock((OOC_IR__NewBlock)i0);
      return (OOC_SSA__Result)i0;
      goto l215;
l81:
      i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression_NewObject((OOC_IR__NewObject)i0);
      return (OOC_SSA__Result)i0;
      goto l215;
l83:
      i1 = *(OOC_INT8*)((_check_pointer(i0, 36411))+8);
      switch (i1) {
      case 10:
        i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression_AddCompareOp((OOC_IR__Compare)i0, 25);
        return (OOC_SSA__Result)i0;
        goto l215;
      case 11:
        i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression_AddCompareOp((OOC_IR__Compare)i0, 26);
        return (OOC_SSA__Result)i0;
        goto l215;
      case 12:
        i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression_AddCompareOp((OOC_IR__Compare)i0, 27);
        return (OOC_SSA__Result)i0;
        goto l215;
      case 13:
        i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression_AddCompareOp((OOC_IR__Compare)i0, 28);
        return (OOC_SSA__Result)i0;
        goto l215;
      case 14:
        i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression_AddCompareOp((OOC_IR__Compare)i0, 29);
        return (OOC_SSA__Result)i0;
        goto l215;
      case 15:
        i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression_AddCompareOp((OOC_IR__Compare)i0, 30);
        return (OOC_SSA__Result)i0;
        goto l215;
      default:
        Log__Type("++ Unknown variant of Compare in Expression", 44, (void*)i0);
        _assert(0u, 127, 36954);
        goto l215;
      }
l94:
      i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression_Concat((OOC_IR__Concat)i0);
      return (OOC_SSA__Result)i0;
      goto l215;
l96:
      i1 = *(OOC_INT8*)((_check_pointer(i0, 35948))+8);
      switch (i1) {
      case 22:
        opcode = 39;
        goto l101;
      case 23:
        opcode = 40;
        goto l101;
      default:
        _failed_case(i1, 35939);
        goto l101;
      }
l101:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36143))+12);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 36147))+4);
      i1 = OOC_SSA_Opcode__TypeToSubclass((OOC_SymbolTable__Type)i1);
      i2 = (OOC_INT32)pb;
      i3 = opcode;
      i1 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i2, i3, i1);
      instr = (OOC_SSA__Instr)i1;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36196))+12);
      i2 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i2);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i2, 1);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36255))+16);
      i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i0);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i0, 1);
      return (OOC_SSA__Result)i1;
      goto l215;
l103:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35748))+4);
      i1 = OOC_SSA_Opcode__TypeToSubclass((OOC_SymbolTable__Type)i1);
      i2 = (OOC_INT32)pb;
      i1 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i2, 44, i1);
      instr = (OOC_SSA__Instr)i1;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35797))+8);
      i2 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i2);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i2, 1);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35857))+12);
      i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i0);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i0, 1);
      return (OOC_SSA__Result)i1;
      goto l215;
l105:
      i1 = *(OOC_INT8*)((_check_pointer(i0, 35041))+8);
      switch (i1) {
      case 6:
        opcode = 35;
        goto l112;
      case 7:
        opcode = 38;
        goto l112;
      case 8:
        opcode = 34;
        goto l112;
      case 9:
        opcode = 36;
        goto l112;
      default:
        i1 = *(OOC_INT8*)((_check_pointer(i0, 35370))+8);
        Log__Int("++ Unknown variant of SetOp in Expression", 42, i1);
        _assert(0u, 127, 35392);
        goto l112;
      }
l112:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35487))+12);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 35492))+4);
      i1 = OOC_SSA_Opcode__TypeToSubclass((OOC_SymbolTable__Type)i1);
      i2 = (OOC_INT32)pb;
      i3 = opcode;
      i1 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i2, i3, i1);
      instr = (OOC_SSA__Instr)i1;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35541))+12);
      i2 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i2);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i2, 1);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35601))+16);
      i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i0);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i0, 1);
      return (OOC_SSA__Result)i1;
      goto l215;
l114:
      i1 = *(OOC_INT8*)((_check_pointer(i0, 34704))+8);
      switch (i1) {
      case 20:
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34780))+16);
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34768))+12);
        i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression_ShortcutAnd((OOC_IR__Expression)i0, (OOC_IR__Expression)i1);
        return (OOC_SSA__Result)i0;
        goto l215;
      case 21:
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34852))+16);
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34840))+12);
        i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression_ShortcutOr((OOC_IR__Expression)i0, (OOC_IR__Expression)i1);
        return (OOC_SSA__Result)i0;
        goto l215;
      default:
        Log__Type("++ Unknown variant of BooleanOp in Expression", 46, (void*)i0);
        _assert(0u, 127, 34960);
        goto l215;
      }
l121:
      i1 = *(OOC_INT8*)((_check_pointer(i0, 33972))+8);
      switch (i1) {
      case 0:
        opcode = 19;
        goto l130;
      case 1:
        opcode = 20;
        goto l130;
      case 4:
        opcode = 22;
        goto l130;
      case 5:
        opcode = 24;
        goto l130;
      case 2:
        opcode = 23;
        goto l130;
      case 3:
        opcode = 23;
        goto l130;
      default:
        i1 = *(OOC_INT8*)((_check_pointer(i0, 34383))+8);
        Log__Int("++ Unknown variant of BinaryArith in Expression", 48, i1);
        _assert(0u, 127, 34405);
        goto l130;
      }
l130:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34500))+12);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34505))+4);
      i1 = OOC_SSA_Opcode__TypeToSubclass((OOC_SymbolTable__Type)i1);
      i2 = (OOC_INT32)pb;
      i3 = opcode;
      i1 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i2, i3, i1);
      instr = (OOC_SSA__Instr)i1;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34554))+12);
      i2 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i2);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i2, 1);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34614))+16);
      i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i0);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i0, 1);
      return (OOC_SSA__Result)i1;
      goto l215;
l132:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33815))+4);
      i1 = OOC_SSA_Opcode__TypeToSubclass((OOC_SymbolTable__Type)i1);
      i2 = (OOC_INT32)pb;
      i1 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i2, 54, i1);
      instr = (OOC_SSA__Instr)i1;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33865))+8);
      i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i0);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i0, 1);
      return (OOC_SSA__Result)i1;
      goto l215;
l134:
      i1 = *(OOC_UINT8*)((_check_pointer(i0, 33391))+16);
      if (i1) goto l137;
      opcode = 52;
      i1=52;
      goto l138;
l137:
      opcode = 53;
      i1=53;
l138:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33561))+4);
      i2 = OOC_SSA_Opcode__TypeToSubclass((OOC_SymbolTable__Type)i2);
      i3 = (OOC_INT32)pb;
      i1 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i3, i1, i2);
      instr = (OOC_SSA__Instr)i1;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33611))+8);
      i2 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i2);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i2, 1);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33672))+12);
      i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i0);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i0, 1);
      return (OOC_SSA__Result)i1;
      goto l215;
l140:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33242))+4);
      i1 = OOC_SSA_Opcode__TypeToSubclass((OOC_SymbolTable__Type)i1);
      i2 = (OOC_INT32)pb;
      i1 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i2, 50, i1);
      instr = (OOC_SSA__Instr)i1;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33292))+8);
      i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i0);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i0, 1);
      return (OOC_SSA__Result)i1;
      goto l215;
l142:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33046))+4);
      i1 = OOC_SSA_Opcode__TypeToSubclass((OOC_SymbolTable__Type)i1);
      i2 = (OOC_INT32)pb;
      i1 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i2, 49, i1);
      instr = (OOC_SSA__Instr)i1;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33096))+8);
      i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i0);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i0, 1);
      return (OOC_SSA__Result)i1;
      goto l215;
l144:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32791))+4);
      i1 = OOC_SSA_Opcode__TypeToSubclass((OOC_SymbolTable__Type)i1);
      i2 = (OOC_INT32)pb;
      i1 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i2, 48, i1);
      instr = (OOC_SSA__Instr)i1;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32841))+8);
      i2 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i2);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i2, 1);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32902))+12);
      i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i0);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i0, 1);
      return (OOC_SSA__Result)i1;
      goto l215;
l146:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32593))+4);
      i1 = OOC_SSA_Opcode__TypeToSubclass((OOC_SymbolTable__Type)i1);
      i2 = (OOC_INT32)pb;
      i1 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i2, 45, i1);
      instr = (OOC_SSA__Instr)i1;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32643))+8);
      i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i0);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i0, 1);
      return (OOC_SSA__Result)i1;
      goto l215;
l148:
      i1 = (OOC_INT32)pb;
      i1 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i1, 43, 5);
      instr = (OOC_SSA__Instr)i1;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32394))+8);
      i2 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i2);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i2, 1);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32457))+12);
      i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i0);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i0, 1);
      return (OOC_SSA__Result)i1;
      goto l215;
l150:
      i1 = (OOC_INT32)pb;
      i1 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i1, 33, 5);
      instr = (OOC_SSA__Instr)i1;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32202))+8);
      i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i0);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i0, 1);
      return (OOC_SSA__Result)i1;
      goto l215;
l152:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31744))+4);
      i1 = OOC_SymbolTable_TypeRules__IsPredefType((OOC_SymbolTable__Type)i1, 10);
      if (i1) goto l155;
      opcode = 21;
      i1=21;
      goto l156;
l155:
      opcode = 37;
      i1=37;
l156:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31972))+8);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 31981))+4);
      i2 = OOC_SSA_Opcode__TypeToSubclass((OOC_SymbolTable__Type)i2);
      i3 = (OOC_INT32)pb;
      i1 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i3, i1, i2);
      instr = (OOC_SSA__Instr)i1;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32031))+8);
      i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i0);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i0, 1);
      return (OOC_SSA__Result)i1;
      goto l215;
l158:
      i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression_TypeGuard((OOC_IR__TypeGuard)i0);
      return (OOC_SSA__Result)i0;
      goto l215;
l160:
      i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression_TypeTest((OOC_IR__TypeTest)i0);
      return (OOC_SSA__Result)i0;
      goto l215;
l162:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31529))+8);
      i1 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i1);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31503))+8);
      i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_TypeTag((OOC_IR__Expression)i0, (OOC_SSA__Result)i1, 0u, (OOC_Scanner_SymList__Symbol)(OOC_INT32)0);
      return (OOC_SSA__Result)i0;
      goto l215;
l164:
      i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression_TypeConv((OOC_IR__TypeConv)i0);
      return (OOC_SSA__Result)i0;
      goto l215;
l166:
      i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression_TypeCast((OOC_IR__TypeCast)i0);
      return (OOC_SSA__Result)i0;
      goto l215;
l168:
      i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression_SelectProc((OOC_IR__SelectProc)i0);
      return (OOC_SSA__Result)i0;
      goto l215;
l170:
      i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression_SelectField((OOC_IR__SelectField)i0);
      return (OOC_SSA__Result)i0;
      goto l215;
l172:
      i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression_GetIndexBaseArray((OOC_IR__Expression)i0, (void*)(OOC_INT32)&dim);
      baseArray = (OOC_SSA__Result)i0;
      i1 = dim;
      i2 = (OOC_INT32)expr;
      i3 = (OOC_INT32)pb;
      i3 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_CalculateLength((OOC_SSA__ProcBlock)i3, (OOC_IR__Expression)i2, (-1), (OOC_SSA__Result)i0);
      i4 = (OOC_INT32)pb;
      i3 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_CalculateSize((OOC_SSA__ProcBlock)i4, (OOC_IR__Expression)i2, (OOC_SSA__Result)i3);
      i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression_Index((OOC_IR__Index)i2, (OOC_SSA__Result)i0, (OOC_SSA__Result)i3, i1);
      return (OOC_SSA__Result)i0;
      goto l215;
l174:
      i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression_Deref((OOC_IR__Deref)i0);
      return (OOC_SSA__Result)i0;
      goto l215;
l176:
      i1 = *(OOC_INT8*)((_check_pointer(i0, 30374))+8);
      i1 = i1==16;
      if (i1) goto l179;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30566))+20);
      i1 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i1);
      baseArray = (OOC_SSA__Result)i1;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30606))+20);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30606))+20);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 30621))+4);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 30621))+4);
      i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 30627)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i2);
      type = (OOC_SymbolTable__Type)i2;
      i3 = *(OOC_INT32*)((_check_pointer(i0, 30695))+16);
      i2 = (OOC_INT32)OOC_SymbolTable__ArrayDesc_GetNthElementType((OOC_SymbolTable__Array)(_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 30666)))), &_td_OOC_SymbolTable__ArrayDesc, 30666)), i3);
      type = (OOC_SymbolTable__Type)i2;
      i0 = *(OOC_INT32*)((_check_pointer(i0, 30768))+16);
      i3 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddGetLengthInstr((OOC_SSA__ProcBlock)i3, (OOC_SSA__Instr)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 30756)))), &_td_OOC_SSA__InstrDesc, 30756)), i0, (OOC_SymbolTable__Array)(_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 30824)))), &_td_OOC_SymbolTable__ArrayDesc, 30824)));
      return (OOC_SSA__Result)i0;
      goto l215;
l179:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30448))+20);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 30467)))), &_td_OOC_IR__ConstDesc, 30467)), 30473))+8);
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 30487)))), &_td_Object_Boxed__StringDesc, 30487)), 30494));
      i0 = *(OOC_INT32*)(_check_pointer(i0, 30501));
      i1 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConstInt((OOC_SSA__ProcBlock)i1, (i0+1));
      return (OOC_SSA__Result)i0;
      goto l215;
l182:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29925))+8);
      i1 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i1);
      res = (OOC_SSA__Result)i1;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 29951))+8);
      i2 = *(OOC_INT8*)((_check_pointer(i2, 29958))+36);
      i2 = i2==12;
      if (i2) goto l185;
      return (OOC_SSA__Result)i1;
      goto l215;
l185:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30116))+4);
      i0 = OOC_SSA_Opcode__TypeToSubclass((OOC_SymbolTable__Type)i0);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 30021))+8);
      i1 = (OOC_INT32)OOC_SSA__InstrDesc_GetArgClass((OOC_SSA__Instr)i1, 4);
      i2 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_FixSubclass((OOC_SSA__ProcBlock)i2, (OOC_SSA__Result)i1, i0);
      return (OOC_SSA__Result)i0;
      goto l215;
l188:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29832))+8);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 29843)))), &_td_OOC_SymbolTable__TypeDeclDesc, 29843)), 29852))+48);
      i1 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetTypeRef((OOC_SSA__ProcBlock)i1, (OOC_SymbolTable__Type)i0);
      return (OOC_SSA__Result)i0;
      goto l215;
l190:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29535))+4);
      i1 = OOC_SSA_Opcode__TypeToSubclass((OOC_SymbolTable__Type)i1);
      i2 = (OOC_INT32)pb;
      i1 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i2, 12, i1);
      instr = (OOC_SSA__Instr)i1;
      i2 = (OOC_INT32)s;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i2, 2);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29629))+8);
      i3 = (OOC_INT32)pb;
      i2 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetAddress((OOC_SSA__ProcBlock)i3, (OOC_SymbolTable__Declaration)i2);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i2, 4);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29697))+8);
      i2 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetDeclRef((OOC_SSA__ProcBlock)i2, (OOC_SymbolTable__Declaration)i0);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i0, 5);
      OOC_SSA_IRtoSSA__StatmSeq_Chain((OOC_SSA__Instr)i1);
      return (OOC_SSA__Result)i1;
      goto l215;
l192:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29432))+8);
      i1 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetAddress((OOC_SSA__ProcBlock)i1, (OOC_SymbolTable__Declaration)i0);
      return (OOC_SSA__Result)i0;
      goto l215;
l194:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28552))+8);
      i1 = i1==(OOC_INT32)0;
      if (i1) goto l213;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28666))+8);
      v = (Object_Boxed__Object)i1;
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 28690)))), &_td_Object_Boxed__StringDesc);
      if (i2) goto l207;
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 29004)))), &_td_Object_Boxed__BooleanDesc);
      if (i2) goto l205;
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 29082)))), &_td_Object_Boxed__SetDesc);
      if (i2) goto l203;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29309))+4);
      i0 = OOC_SSA_Opcode__TypeToSubclass((OOC_SymbolTable__Type)i0);
      i2 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConst((OOC_SSA__ProcBlock)i2, (Object_Boxed__Object)i1, i0, (OOC_SymbolTable__Type)(OOC_INT32)0);
      return (OOC_SSA__Result)i0;
      goto l215;
l203:
      i1 = *(OOC_UINT32*)(_check_pointer(i1, 29149));
      i1 = (OOC_INT32)Object_BigInt__NewInt((_type_cast_fast(OOC_INT32, OOC_UINT32, i1)));
      x = (Object_BigInt__BigInt)i1;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29219))+4);
      i0 = OOC_SSA_Opcode__TypeToSubclass((OOC_SymbolTable__Type)i0);
      i2 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConst((OOC_SSA__ProcBlock)i2, (Object_Boxed__Object)i1, i0, (OOC_SymbolTable__Type)(OOC_INT32)0);
      return (OOC_SSA__Result)i0;
      goto l215;
l205:
      i0 = *(OOC_UINT8*)(_check_pointer(i1, 29059));
      i1 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConstBool((OOC_SSA__ProcBlock)i1, i0);
      return (OOC_SSA__Result)i0;
      goto l215;
l207:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28744))+4);
      i2 = OOC_SymbolTable_TypeRules__IsStringConst((OOC_SymbolTable__Type)i2);
      if (i2) goto l210;
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 28877));
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 28877));
      i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 28883)))), Object__StringDesc_CharAt)),Object__StringDesc_CharAt)((Object__String)i1, 0);
      i1 = (OOC_INT32)Object_BigInt__NewInt(i1);
      x = (Object_BigInt__BigInt)i1;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28959))+4);
      i0 = OOC_SSA_Opcode__TypeToSubclass((OOC_SymbolTable__Type)i0);
      i2 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConst((OOC_SSA__ProcBlock)i2, (Object_Boxed__Object)i1, i0, (OOC_SymbolTable__Type)(OOC_INT32)0);
      return (OOC_SSA__Result)i0;
      goto l215;
l210:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28814))+4);
      i2 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConst((OOC_SSA__ProcBlock)i2, (Object_Boxed__Object)i1, 9, (OOC_SymbolTable__Type)i0);
      return (OOC_SSA__Result)i0;
      goto l215;
l213:
      i0 = (OOC_INT32)OOC_SSA__nil;
      i1 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConst((OOC_SSA__ProcBlock)i1, (Object_Boxed__Object)i0, 9, (OOC_SymbolTable__Type)(OOC_INT32)0);
      return (OOC_SSA__Result)i0;
l215:
      _failed_function(11724); return 0;
      ;
    }

    
    void OOC_SSA_IRtoSSA__StatmSeq_Assert(OOC_IR__Assert assert) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_SSA__Instr instr;
      OOC_SSA__Result predicate;

      i0 = (OOC_INT32)assert;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 37855))+8);
      i1 = i1==(OOC_INT32)0;
      if (i1) goto l6;
      i1 = *(OOC_UINT8*)((_check_pointer(i0, 38042))+16);
      i1 = !i1;
      if (!i1) goto l7;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 38096))+8);
      i1 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i1);
      predicate = (OOC_SSA__Result)i1;
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 38151));
      i3 = (OOC_INT32)pb;
      i2 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_AddException((OOC_SSA__ProcBlock)i3, (OOC_Scanner_SymList__Symbol)i2, 64, 0);
      instr = (OOC_SSA__Instr)i2;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i1, 1);
      i0 = *(OOC_INT32*)((_check_pointer(i0, 38282))+12);
      i1 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConstInt((OOC_SSA__ProcBlock)i1, i0);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i0, 1);
      goto l7;
l6:
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 37920));
      i2 = (OOC_INT32)pb;
      i1 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_AddException((OOC_SSA__ProcBlock)i2, (OOC_Scanner_SymList__Symbol)i1, 65, 0);
      instr = (OOC_SSA__Instr)i1;
      i0 = *(OOC_INT32*)((_check_pointer(i0, 38003))+12);
      i2 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConstInt((OOC_SSA__ProcBlock)i2, i0);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i0, 1);
l7:
      return;
      ;
    }

    
    OOC_SSA__Instr OOC_SSA_IRtoSSA__StatmSeq_Assignment(OOC_IR__Assignment assignment) {
      register OOC_INT32 i0,i1,i2;
      OOC_SSA__Result get;

      i0 = (OOC_INT32)assignment;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 38675))+8);
      i1 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i1);
      get = (OOC_SSA__Result)i1;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 38756))+12);
      i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i0);
      i2 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddSetInstr((OOC_SSA__ProcBlock)i2, (OOC_SSA__Instr)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 38726)))), &_td_OOC_SSA__InstrDesc, 38726)), (OOC_SSA__Result)i0);
      return (OOC_SSA__Instr)i0;
      ;
    }

    
    OOC_SSA__Instr OOC_SSA_IRtoSSA__StatmSeq_Call(OOC_IR__Call call) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
      OOC_SSA__Result *args;
      OOC_INT32 i;
      OOC_SSA__Instr instr;
      OOC_SymbolTable__VarDecl fpar;
      OOC_SymbolTable__Type type;
      OOC_CHAR8 isVarParam;

      i0 = (OOC_INT32)call;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 39113))+12);
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 39123)), 0);
      i1 = (OOC_INT32)RT0__NewObject(_td_OOC_SSA_IRtoSSA__38971.baseTypes[0], i1);
      args = (void*)i1;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 39152))+12);
      i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 39163)), 0);
      i2 = i2-1;
      i = i2;
      i3 = i2>=0;
      if (!i3) goto l8;
l3_loop:
      i3 = _check_pointer(i1, 39194);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 39217))+12);
      i5 = _check_pointer(i5, 39228);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i2, i6, OOC_UINT32, 39228))*4);
      i5 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i5);
      *(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 39194))*4) = i5;
      i2 = i2+(-1);
      i = i2;
      i3 = i2>=0;
      if (i3) goto l3_loop;
l8:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 39321))+4);
      i2 = OOC_SSA_Opcode__TypeToSubclass((OOC_SymbolTable__Type)i2);
      i3 = (OOC_INT32)pb;
      i2 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i3, 55, i2);
      instr = (OOC_SSA__Instr)i2;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 39430))+8);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 39438))+4);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 39374))+8);
      i4 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i4);
      OOC_SSA__InstrDesc_AddTypedOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i4, 3, (OOC_SymbolTable__Type)i3, 0u);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 39483))+12);
      i = 0;
      i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 39494)), 0);
      i4 = 0<i3;
      if (!i4) goto l20;
      i4=0;
l11_loop:
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 39518))+16);
      i5 = _check_pointer(i5, 39530);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 39530))*4);
      i5 = i5!=(OOC_INT32)0;
      if (i5) goto l14;
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 39700))+12);
      i5 = _check_pointer(i5, 39711);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 39711))*4);
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 39714))+4);
      type = (OOC_SymbolTable__Type)i5;
      isVarParam = 0u;
      i6=i5;i5=0u;
      goto l15;
l14:
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 39568))+16);
      i5 = _check_pointer(i5, 39580);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 39580))*4);
      fpar = (OOC_SymbolTable__VarDecl)i5;
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 39607))+48);
      type = (OOC_SymbolTable__Type)i6;
      i5 = *(OOC_UINT8*)((_check_pointer(i5, 39643))+60);
      isVarParam = i5;
      
l15:
      i7 = _check_pointer(i1, 39799);
      i8 = OOC_ARRAY_LENGTH(i7, 0);
      i7 = (OOC_INT32)*(OOC_INT32*)(i7+(_check_index(i4, i8, OOC_UINT32, 39799))*4);
      OOC_SSA__InstrDesc_AddTypedOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i7, 1, (OOC_SymbolTable__Type)i6, i5);
      i4 = i4+1;
      i = i4;
      i5 = i4<i3;
      if (i5) goto l11_loop;
l20:
      return (OOC_SSA__Instr)i2;
      ;
    }

    
    OOC_SSA__Result OOC_SSA_IRtoSSA__StatmSeq_PopExceptionContext(OOC_SSA__Result storeIn, OOC_INT32 n) {
      register OOC_INT32 i0,i1,i2;

      i0 = n;
      i1 = i0!=0;
      if (i1) goto l3;
      i0 = (OOC_INT32)storeIn;
      return (OOC_SSA__Result)i0;
      goto l4;
l3:
      i1 = (OOC_INT32)pb;
      i1 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i1, 79, 0);
      i2 = (OOC_INT32)storeIn;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i2, 2);
      i2 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConstInt((OOC_SSA__ProcBlock)i2, i0);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i0, 1);
      i0 = (OOC_INT32)OOC_SSA__InstrDesc_AddResult((OOC_SSA__Instr)i1, 2);
      return (OOC_SSA__Result)i0;
l4:
      _failed_function(39890); return 0;
      ;
    }

    
    void OOC_SSA_IRtoSSA__StatmSeq_Return(OOC_IR__Return _return) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_SSA__Result expr;
      OOC_SSA__Instr instr;
      OOC_SSA__Result store;

      i0 = (OOC_INT32)_return;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 40442))+8);
      i1 = i1!=(OOC_INT32)0;
      if (i1) goto l3;
      i1 = (OOC_INT32)pb;
      i1 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i1, 7, 0);
      instr = (OOC_SSA__Instr)i1;
      i0 = *(OOC_INT32*)((_check_pointer(i0, 40870))+12);
      i2 = (OOC_INT32)s;
      i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_PopExceptionContext((OOC_SSA__Result)i2, i0);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i0, 2);
      i0=i1;
      goto l4;
l3:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 40497))+8);
      i1 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i1);
      expr = (OOC_SSA__Result)i1;
      i2 = (OOC_INT32)pb;
      i2 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i2, 7, 0);
      instr = (OOC_SSA__Instr)i2;
      i0 = *(OOC_INT32*)((_check_pointer(i0, 40632))+12);
      i3 = (OOC_INT32)s;
      i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_PopExceptionContext((OOC_SSA__Result)i3, i0);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i0, 2);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i1, 9);
      i0=i2;
l4:
      i0 = (OOC_INT32)OOC_SSA__InstrDesc_AddResult((OOC_SSA__Instr)i0, 2);
      store = (OOC_SSA__Result)i0;
      i1 = (OOC_INT32)pb;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 41004));
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i0, 11);
      s = (OOC_SSA__Result)i0;
      return;
      ;
    }

    
    void OOC_SSA_IRtoSSA__StatmSeq_IfStatm(OOC_IR__IfStatm ifStatm) {
      register OOC_INT32 i0,i1,i2,i3,i4;
      OOC_SSA__Instr select;
      OOC_SSA__Result storeAfterGuard;

      i0 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i0, 5, 0);
      select = (OOC_SSA__Instr)i0;
      i1 = (OOC_INT32)ifStatm;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 41311))+8);
      i2 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i2);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i2, 1);
      i2 = (OOC_INT32)s;
      storeAfterGuard = (OOC_SSA__Result)i2;
      i3 = (OOC_INT32)pb;
      i3 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConstBool((OOC_SSA__ProcBlock)i3, 1u);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i3, 1);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 41487))+12);
      i4 = (OOC_INT32)pb;
      i3 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq((OOC_SSA__ProcBlock)i4, (OOC_SSA__Result)i2, (OOC_IR__StatementSeq)i3);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i3, 1);
      i3 = (OOC_INT32)pb;
      i3 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConstBool((OOC_SSA__ProcBlock)i3, 0u);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i3, 1);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 41618))+16);
      i3 = i3!=(OOC_INT32)0;
      if (i3) goto l3;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i2, 1);
      goto l4;
l3:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 41705))+16);
      i3 = (OOC_INT32)pb;
      i1 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq((OOC_SSA__ProcBlock)i3, (OOC_SSA__Result)i2, (OOC_IR__StatementSeq)i1);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i1, 1);
l4:
      i0 = (OOC_INT32)OOC_SSA__InstrDesc_AddResult((OOC_SSA__Instr)i0, 2);
      s = (OOC_SSA__Result)i0;
      return;
      ;
    }

    
    void OOC_SSA_IRtoSSA__StatmSeq_WithStatm(OOC_IR__WithStatm withStatm) {
      register OOC_INT32 i0,i1,i2,i3,i4;
      OOC_SSA__Instr select;
      OOC_SSA__Result storeAfterGuard;
      OOC_IR__Expression var;
      OOC_SSA__Instr typeTag;

      i0 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i0, 5, 0);
      select = (OOC_SSA__Instr)i0;
      i1 = (OOC_INT32)withStatm;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 42166))+8);
      i2 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i2);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i2, 1);
      i2 = (OOC_INT32)s;
      storeAfterGuard = (OOC_SSA__Result)i2;
      i3 = (OOC_INT32)pb;
      i3 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConstBool((OOC_SSA__ProcBlock)i3, 1u);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i3, 1);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 42344))+12);
      i4 = (OOC_INT32)pb;
      i3 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq((OOC_SSA__ProcBlock)i4, (OOC_SSA__Result)i2, (OOC_IR__StatementSeq)i3);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i3, 1);
      i3 = (OOC_INT32)pb;
      i3 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConstBool((OOC_SSA__ProcBlock)i3, 0u);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i3, 1);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 42477))+16);
      i3 = i3!=(OOC_INT32)0;
      if (i3) goto l7;
      i3 = *(OOC_UINT8*)((_check_pointer(i1, 42646))+20);
      if (i3) goto l5;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i2, 1);
      goto l8;
l5:
      s = (OOC_SSA__Result)i2;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 42718))+8);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 42729)))), &_td_OOC_IR__TypeTestDesc, 42729)), 42738))+8);
      var = (OOC_IR__Expression)i2;
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 42812));
      i4 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i2);
      i2 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_TypeTag((OOC_IR__Expression)i2, (OOC_SSA__Result)i4, 1u, (OOC_Scanner_SymList__Symbol)i3);
      typeTag = (OOC_SSA__Instr)i2;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 42864));
      i3 = (OOC_INT32)pb;
      i1 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_AddException((OOC_SSA__ProcBlock)i3, (OOC_Scanner_SymList__Symbol)i1, 70, 0);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i2, 1);
      i1 = (OOC_INT32)s;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i1, 1);
      goto l8;
l7:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 42566))+16);
      i3 = (OOC_INT32)pb;
      i1 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq((OOC_SSA__ProcBlock)i3, (OOC_SSA__Result)i2, (OOC_IR__StatementSeq)i1);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i1, 1);
l8:
      i0 = (OOC_INT32)OOC_SSA__InstrDesc_AddResult((OOC_SSA__Instr)i0, 2);
      s = (OOC_SSA__Result)i0;
      return;
      ;
    }

    
    void OOC_SSA_IRtoSSA__StatmSeq_CaseStatm(OOC_IR__CaseStatm caseStatm) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
      OOC_SSA__Instr select;
      OOC_SSA__Result storeAfterSelect;
      OOC_INT32 i;
      OOC_SSA__Instr instr;
      auto OOC_SSA__Instr OOC_SSA_IRtoSSA__StatmSeq_CaseStatm_Labels(OOC_IR__CaseLabels labels);
        
        OOC_SSA__Instr OOC_SSA_IRtoSSA__StatmSeq_CaseStatm_Labels(OOC_IR__CaseLabels labels) {
          register OOC_INT32 i0,i1,i2,i3,i4,i5;
          OOC_SSA__Instr instr;
          OOC_INT32 i;
          OOC_IR__Expression l;
          OOC_SSA__Result value;

          i0 = (OOC_INT32)pb;
          i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i0, 82, 0);
          instr = (OOC_SSA__Instr)i0;
          i1 = (OOC_INT32)labels;
          i = 0;
          i2 = OOC_ARRAY_LENGTH((_check_pointer(i1, 43601)), 0);
          i3 = 0<i2;
          if (!i3) goto l12;
          i3=0;
l3_loop:
          i4 = _check_pointer(i1, 43630);
          i5 = OOC_ARRAY_LENGTH(i4, 0);
          i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 43630))*4);
          l = (OOC_IR__Expression)i4;
          i5 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 43651)))), &_td_OOC_IR__SetRangeDesc);
          if (i5) goto l6;
          i4 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i4);
          value = (OOC_SSA__Result)i4;
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i4, 1);
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i4, 1);
          goto l7;
l6:
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 43709))+8);
          i5 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i5);
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i5, 1);
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 43770))+12);
          i4 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i4);
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i4, 1);
l7:
          i3 = i3+1;
          i = i3;
          i4 = i3<i2;
          if (i4) goto l3_loop;
l12:
          return (OOC_SSA__Instr)i0;
          ;
        }


      i0 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i0, 5, 0);
      select = (OOC_SSA__Instr)i0;
      i1 = (OOC_INT32)caseStatm;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 44119))+8);
      i2 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i2);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i2, 1);
      i2 = (OOC_INT32)s;
      storeAfterSelect = (OOC_SSA__Result)i2;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 44205))+12);
      i = 0;
      i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 44215)), 0);
      i4 = 0<i3;
      if (!i4) goto l13;
      i4=i2;i2=i0;i0=i1;i1=0;
l4_loop:
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 44249))+12);
      i5 = _check_pointer(i5, 44259);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i1, i6, OOC_UINT32, 44259))*4);
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 44262))+8);
      i5 = OOC_ARRAY_LENGTH((_check_pointer(i5, 44270)), 0);
      i5 = i5>0;
      if (!i5) goto l8;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 44327))+12);
      i0 = _check_pointer(i0, 44337);
      i2 = OOC_ARRAY_LENGTH(i0, 0);
      i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(i1, i2, OOC_UINT32, 44337))*4);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 44340))+8);
      i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_CaseStatm_Labels((OOC_IR__CaseLabels)i0);
      i1 = (OOC_INT32)select;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i0, 16);
      i0 = (OOC_INT32)caseStatm;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 44497))+12);
      i2 = _check_pointer(i2, 44507);
      i4 = OOC_ARRAY_LENGTH(i2, 0);
      i5 = i;
      i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i5, i4, OOC_UINT32, 44507))*4);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 44510))+12);
      i4 = (OOC_INT32)pb;
      i6 = (OOC_INT32)storeAfterSelect;
      i2 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq((OOC_SSA__ProcBlock)i4, (OOC_SSA__Result)i6, (OOC_IR__StatementSeq)i2);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i2, 1);
      i2=i1;i1=i5;i4=i6;
l8:
      i1 = i1+1;
      i = i1;
      i5 = i1<i3;
      if (i5) goto l4_loop;
l12:
      i1=i0;i0=i2;i2=i4;
l13:
      i3 = (OOC_INT32)pb;
      i3 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConstBool((OOC_SSA__ProcBlock)i3, 0u);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i3, 16);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 44674))+16);
      i3 = i3!=(OOC_INT32)0;
      if (i3) goto l20;
      i3 = *(OOC_UINT8*)((_check_pointer(i1, 44840))+20);
      if (i3) goto l18;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i2, 1);
      goto l21;
l18:
      s = (OOC_SSA__Result)i2;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 44933));
      i2 = (OOC_INT32)pb;
      i1 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_AddException((OOC_SSA__ProcBlock)i2, (OOC_Scanner_SymList__Symbol)i1, 69, 0);
      instr = (OOC_SSA__Instr)i1;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 45036))+24);
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 45046));
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i2, 1);
      i1 = (OOC_INT32)s;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i1, 1);
      goto l21;
l20:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 44762))+16);
      i3 = (OOC_INT32)pb;
      i1 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq((OOC_SSA__ProcBlock)i3, (OOC_SSA__Result)i2, (OOC_IR__StatementSeq)i1);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i1, 1);
l21:
      i0 = (OOC_INT32)OOC_SSA__InstrDesc_AddResult((OOC_SSA__Instr)i0, 2);
      s = (OOC_SSA__Result)i0;
      return;
      ;
    }

    
    void OOC_SSA_IRtoSSA__StatmSeq_RepeatStatm(OOC_IR__RepeatStatm repeatStatm) {
      register OOC_INT32 i0,i1,i2,i3,i4;
      OOC_SSA__Instr start;
      OOC_SSA__Result guard;
      OOC_SSA__Instr exit;
      OOC_SSA__Instr select;
      OOC_SSA__Instr end;

      i0 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i0, 10, 0);
      start = (OOC_SSA__Instr)i0;
      i1 = (OOC_INT32)s;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i1, 2);
      i1 = (OOC_INT32)OOC_SSA__InstrDesc_AddResult((OOC_SSA__Instr)i0, 2);
      s = (OOC_SSA__Result)i1;
      i2 = (OOC_INT32)repeatStatm;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 45649))+8);
      i4 = (OOC_INT32)pb;
      i1 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq((OOC_SSA__ProcBlock)i4, (OOC_SSA__Result)i1, (OOC_IR__StatementSeq)i3);
      s = (OOC_SSA__Result)i1;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 45696))+12);
      i1 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i1);
      guard = (OOC_SSA__Result)i1;
      i2 = (OOC_INT32)pb;
      i2 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i2, 9, 0);
      exit = (OOC_SSA__Instr)i2;
      i3 = (OOC_INT32)s;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i3, 2);
      i3 = (OOC_INT32)pb;
      i3 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i3, 5, 0);
      select = (OOC_SSA__Instr)i3;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i3, (OOC_SSA__Result)i1, 1);
      i1 = (OOC_INT32)pb;
      i1 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConstBool((OOC_SSA__ProcBlock)i1, 1u);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i3, (OOC_SSA__Result)i1, 1);
      i1 = (OOC_INT32)OOC_SSA__InstrDesc_AddResult((OOC_SSA__Instr)i2, 2);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i3, (OOC_SSA__Result)i1, 1);
      i1 = (OOC_INT32)pb;
      i1 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConstBool((OOC_SSA__ProcBlock)i1, 0u);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i3, (OOC_SSA__Result)i1, 1);
      i1 = (OOC_INT32)s;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i3, (OOC_SSA__Result)i1, 1);
      i1 = (OOC_INT32)OOC_SSA__InstrDesc_AddResult((OOC_SSA__Instr)i3, 2);
      s = (OOC_SSA__Result)i1;
      i1 = (OOC_INT32)pb;
      i1 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i1, 11, 0);
      end = (OOC_SSA__Instr)i1;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i0, 1);
      i0 = (OOC_INT32)s;
      i3 = (OOC_INT32)pb;
      OOC_SSA_IRtoSSA__AddStoreBackwardFeed((OOC_SSA__ProcBlock)i3, (OOC_SSA__Instr)i1, (OOC_SSA__Result)i0);
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 46523));
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i0, 11);
      i0 = (OOC_INT32)OOC_SSA__InstrDesc_AddResult((OOC_SSA__Instr)i1, 2);
      s = (OOC_SSA__Result)i0;
      return;
      ;
    }

    
    void OOC_SSA_IRtoSSA__StatmSeq_WhileStatm(OOC_IR__WhileStatm whileStatm) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
      OOC_SSA__Result guard1;
      OOC_SSA__Result storeAfterGuard1;
      OOC_SSA__Instr start;
      OOC_SSA__Result guard2;
      OOC_SSA__Instr exit;
      OOC_SSA__Instr select;
      OOC_SSA__Instr end;

      i0 = (OOC_INT32)whileStatm;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 46973))+8);
      i1 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i1);
      guard1 = (OOC_SSA__Result)i1;
      i2 = (OOC_INT32)s;
      storeAfterGuard1 = (OOC_SSA__Result)i2;
      i3 = (OOC_INT32)pb;
      i3 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i3, 10, 0);
      start = (OOC_SSA__Instr)i3;
      i4 = (OOC_INT32)s;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i3, (OOC_SSA__Result)i4, 2);
      i4 = (OOC_INT32)OOC_SSA__InstrDesc_AddResult((OOC_SSA__Instr)i3, 2);
      s = (OOC_SSA__Result)i4;
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 47310))+12);
      i6 = (OOC_INT32)pb;
      i4 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq((OOC_SSA__ProcBlock)i6, (OOC_SSA__Result)i4, (OOC_IR__StatementSeq)i5);
      s = (OOC_SSA__Result)i4;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 47357))+8);
      i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i0);
      guard2 = (OOC_SSA__Result)i0;
      i4 = (OOC_INT32)pb;
      i4 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i4, 9, 0);
      exit = (OOC_SSA__Instr)i4;
      i5 = (OOC_INT32)s;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i4, (OOC_SSA__Result)i5, 2);
      i5 = (OOC_INT32)pb;
      i5 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i5, 5, 0);
      select = (OOC_SSA__Instr)i5;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i5, (OOC_SSA__Result)i0, 1);
      i0 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConstBool((OOC_SSA__ProcBlock)i0, 1u);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i5, (OOC_SSA__Result)i0, 1);
      i0 = (OOC_INT32)s;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i5, (OOC_SSA__Result)i0, 1);
      i0 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConstBool((OOC_SSA__ProcBlock)i0, 0u);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i5, (OOC_SSA__Result)i0, 1);
      i0 = (OOC_INT32)OOC_SSA__InstrDesc_AddResult((OOC_SSA__Instr)i4, 2);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i5, (OOC_SSA__Result)i0, 1);
      i0 = (OOC_INT32)OOC_SSA__InstrDesc_AddResult((OOC_SSA__Instr)i5, 2);
      s = (OOC_SSA__Result)i0;
      i0 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i0, 11, 0);
      end = (OOC_SSA__Instr)i0;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i3, 1);
      i3 = (OOC_INT32)s;
      i5 = (OOC_INT32)pb;
      OOC_SSA_IRtoSSA__AddStoreBackwardFeed((OOC_SSA__ProcBlock)i5, (OOC_SSA__Instr)i0, (OOC_SSA__Result)i3);
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 48183));
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i3, 11);
      i3 = (OOC_INT32)pb;
      i3 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i3, 5, 0);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i3, (OOC_SSA__Result)i1, 1);
      i1 = (OOC_INT32)pb;
      i1 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConstBool((OOC_SSA__ProcBlock)i1, 1u);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i3, (OOC_SSA__Result)i1, 1);
      i0 = (OOC_INT32)OOC_SSA__InstrDesc_AddResult((OOC_SSA__Instr)i0, 2);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i3, (OOC_SSA__Result)i0, 1);
      i0 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConstBool((OOC_SSA__ProcBlock)i0, 0u);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i3, (OOC_SSA__Result)i0, 1);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i3, (OOC_SSA__Result)i2, 1);
      i0 = (OOC_INT32)OOC_SSA__InstrDesc_AddResult((OOC_SSA__Instr)i3, 2);
      s = (OOC_SSA__Result)i0;
      return;
      ;
    }

    
    void OOC_SSA_IRtoSSA__StatmSeq_ForStatm(OOC_IR__ForStatm forStatm) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_SSA__Result endValue;
      OOC_SSA__Result stepValue;
      OOC_SSA__Result v;
      OOC_SSA__Result guard1;
      OOC_SSA__Result storeAfterGuard1;
      OOC_SSA__Instr start;
      OOC_SSA__Instr dummy;
      OOC_SSA__Result guard2;
      OOC_SSA__Instr exit;
      OOC_SSA__Instr select;
      OOC_SSA__Instr end;
      auto OOC_SSA__Instr OOC_SSA_IRtoSSA__StatmSeq_ForStatm_Guard(OOC_SSA__Result bound);
        
        OOC_SSA__Instr OOC_SSA_IRtoSSA__StatmSeq_ForStatm_Guard(OOC_SSA__Result bound) {
          register OOC_INT32 i0,i1;
          OOC_INT8 cmpClass;
          OOC_SSA__Instr instr;

          i0 = (OOC_INT32)forStatm;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 49034))+20);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 49044)))), &_td_OOC_IR__ConstDesc, 49044)), 49050))+8);
          i0 = Object_BigInt__BigIntDesc_Sign((Object_BigInt__BigInt)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 49065)))), &_td_Object_BigInt__BigIntDesc, 49065)));
          i0 = i0>=0;
          if (i0) goto l3;
          cmpClass = 30;
          i0=30;
          goto l4;
l3:
          cmpClass = 28;
          i0=28;
l4:
          i1 = (OOC_INT32)pb;
          i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i1, i0, 5);
          instr = (OOC_SSA__Instr)i0;
          i1 = (OOC_INT32)forStatm;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 49290))+8);
          i1 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i1);
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i1, 1);
          i1 = (OOC_INT32)bound;
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i1, 1);
          return (OOC_SSA__Instr)i0;
          ;
        }


      i0 = (OOC_INT32)forStatm;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 49849))+16);
      i1 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i1);
      endValue = (OOC_SSA__Result)i1;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 49896))+20);
      i2 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i2);
      stepValue = (OOC_SSA__Result)i2;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 49936))+8);
      i2 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i2);
      v = (OOC_SSA__Result)i2;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 50008))+12);
      i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i0);
      i3 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddSetInstr((OOC_SSA__ProcBlock)i3, (OOC_SSA__Instr)(_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 49980)))), &_td_OOC_SSA__InstrDesc, 49980)), (OOC_SSA__Result)i0);
      OOC_SSA_IRtoSSA__StatmSeq_Chain((OOC_SSA__Instr)i0);
      i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_ForStatm_Guard((OOC_SSA__Result)i1);
      guard1 = (OOC_SSA__Result)i0;
      i0 = (OOC_INT32)s;
      storeAfterGuard1 = (OOC_SSA__Result)i0;
      i0 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i0, 10, 0);
      start = (OOC_SSA__Instr)i0;
      i1 = (OOC_INT32)s;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i1, 2);
      i0 = (OOC_INT32)OOC_SSA__InstrDesc_AddResult((OOC_SSA__Instr)i0, 2);
      s = (OOC_SSA__Result)i0;
      i1 = (OOC_INT32)forStatm;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 50386))+24);
      i3 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq((OOC_SSA__ProcBlock)i3, (OOC_SSA__Result)i0, (OOC_IR__StatementSeq)i2);
      s = (OOC_SSA__Result)i0;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 50496))+8);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 50501))+4);
      i0 = OOC_SSA_Opcode__TypeToSubclass((OOC_SymbolTable__Type)i0);
      i2 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i2, 19, i0);
      dummy = (OOC_SSA__Instr)i0;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 50542))+8);
      i1 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i1);
      v = (OOC_SSA__Result)i1;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i1, 1);
      i2 = (OOC_INT32)stepValue;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i2, 1);
      i2 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddSetInstr((OOC_SSA__ProcBlock)i2, (OOC_SSA__Instr)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 50666)))), &_td_OOC_SSA__InstrDesc, 50666)), (OOC_SSA__Result)i0);
      OOC_SSA_IRtoSSA__StatmSeq_Chain((OOC_SSA__Instr)i0);
      i0 = (OOC_INT32)endValue;
      i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_ForStatm_Guard((OOC_SSA__Result)i0);
      guard2 = (OOC_SSA__Result)i0;
      i1 = (OOC_INT32)pb;
      i1 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i1, 9, 0);
      exit = (OOC_SSA__Instr)i1;
      i2 = (OOC_INT32)s;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i2, 2);
      i2 = (OOC_INT32)pb;
      i2 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i2, 5, 0);
      select = (OOC_SSA__Instr)i2;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i0, 1);
      i0 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConstBool((OOC_SSA__ProcBlock)i0, 1u);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i0, 1);
      i0 = (OOC_INT32)s;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i0, 1);
      i0 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConstBool((OOC_SSA__ProcBlock)i0, 0u);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i0, 1);
      i0 = (OOC_INT32)OOC_SSA__InstrDesc_AddResult((OOC_SSA__Instr)i1, 2);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i0, 1);
      i0 = (OOC_INT32)OOC_SSA__InstrDesc_AddResult((OOC_SSA__Instr)i2, 2);
      s = (OOC_SSA__Result)i0;
      i0 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i0, 11, 0);
      end = (OOC_SSA__Instr)i0;
      i2 = (OOC_INT32)start;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i2, 1);
      i2 = (OOC_INT32)s;
      i3 = (OOC_INT32)pb;
      OOC_SSA_IRtoSSA__AddStoreBackwardFeed((OOC_SSA__ProcBlock)i3, (OOC_SSA__Instr)i0, (OOC_SSA__Result)i2);
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 51533));
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i1, 11);
      i1 = (OOC_INT32)pb;
      i1 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i1, 5, 0);
      i2 = (OOC_INT32)guard1;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i2, 1);
      i2 = (OOC_INT32)pb;
      i2 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConstBool((OOC_SSA__ProcBlock)i2, 1u);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i2, 1);
      i0 = (OOC_INT32)OOC_SSA__InstrDesc_AddResult((OOC_SSA__Instr)i0, 2);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i0, 1);
      i0 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConstBool((OOC_SSA__ProcBlock)i0, 0u);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i0, 1);
      i0 = (OOC_INT32)storeAfterGuard1;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i0, 1);
      i0 = (OOC_INT32)OOC_SSA__InstrDesc_AddResult((OOC_SSA__Instr)i1, 2);
      s = (OOC_SSA__Result)i0;
      return;
      ;
    }

    
    void OOC_SSA_IRtoSSA__StatmSeq_IterateArrayStatm(OOC_IR__IterateArrayStatm iterStatm) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5;
      OOC_SSA__Result array;
      OOC_SSA__Result numElements;
      OOC_SSA__Result size;
      OOC_SSA__Result start;
      OOC_SSA__Instr end;
      OOC_SSA__Result guard1;
      OOC_SSA__Result storeAfterGuard1;
      OOC_SSA__Instr collect;
      OOC_SSA__Instr loopStart;
      OOC_SSA__Result curr;
      OOC_SymbolTable__Type elementType;
      OOC_SSA__Instr get;
      OOC_SSA__Opnd opnd;
      OOC_SSA__Result v;
      OOC_SSA__Instr curr2;
      OOC_SSA__Result guard2;
      OOC_SSA__Instr exit;
      OOC_SSA__Instr select;
      OOC_SSA__Instr loopEnd;
      auto OOC_SSA__Instr OOC_SSA_IRtoSSA__StatmSeq_IterateArrayStatm_Guard(OOC_SSA__Result curr);
        
        OOC_SSA__Instr OOC_SSA_IRtoSSA__StatmSeq_IterateArrayStatm_Guard(OOC_SSA__Result curr) {
          register OOC_INT32 i0,i1;

          i0 = (OOC_INT32)pb;
          i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i0, 26, 5);
          i1 = (OOC_INT32)end;
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i1, 1);
          i1 = (OOC_INT32)curr;
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i1, 1);
          return (OOC_SSA__Instr)i0;
          ;
        }


      i0 = (OOC_INT32)iterStatm;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 53012))+12);
      i1 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i1);
      array = (OOC_SSA__Result)i1;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 53071))+12);
      i3 = (OOC_INT32)pb;
      i2 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_CalculateLength((OOC_SSA__ProcBlock)i3, (OOC_IR__Expression)i2, (-1), (OOC_SSA__Result)i1);
      numElements = (OOC_SSA__Result)i2;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 53132))+12);
      i3 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_CalculateSize((OOC_SSA__ProcBlock)i3, (OOC_IR__Expression)i0, (OOC_SSA__Result)i2);
      size = (OOC_SSA__Result)i0;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 53181))+8);
      i1 = (OOC_INT32)OOC_SSA__InstrDesc_GetArgClass((OOC_SSA__Instr)i1, 4);
      start = (OOC_SSA__Result)i1;
      i2 = (OOC_INT32)pb;
      i2 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i2, 19, 9);
      end = (OOC_SSA__Instr)i2;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i1, 1);
      i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_FixAddress((OOC_SSA__Result)i0);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i0, 1);
      i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_IterateArrayStatm_Guard((OOC_SSA__Result)i1);
      guard1 = (OOC_SSA__Result)i0;
      i0 = (OOC_INT32)s;
      storeAfterGuard1 = (OOC_SSA__Result)i0;
      i0 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i0, 6, 0);
      collect = (OOC_SSA__Instr)i0;
      i1 = (OOC_INT32)s;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i1, 2);
      i1 = (OOC_INT32)start;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i1, 1);
      i1 = (OOC_INT32)pb;
      i1 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i1, 10, 0);
      loopStart = (OOC_SSA__Instr)i1;
      i0 = (OOC_INT32)OOC_SSA__InstrDesc_AddResult((OOC_SSA__Instr)i0, 2);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i0, 2);
      i0 = (OOC_INT32)OOC_SSA__InstrDesc_AddResult((OOC_SSA__Instr)i1, 2);
      s = (OOC_SSA__Result)i0;
      i0 = (OOC_INT32)OOC_SSA__InstrDesc_AddResultSubclass((OOC_SSA__Instr)i1, 14, 9);
      curr = (OOC_SSA__Result)i0;
      i1 = (OOC_INT32)iterStatm;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 54049))+12);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 54055))+4);
      i2 = (OOC_INT32)OOC_SymbolTable_TypeRules__ArrayElementType((OOC_SymbolTable__Type)i2);
      elementType = (OOC_SymbolTable__Type)i2;
      i3 = OOC_SSA_Opcode__TypeToSubclass((OOC_SymbolTable__Type)i2);
      i4 = (OOC_INT32)pb;
      i3 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i4, 12, i3);
      get = (OOC_SSA__Instr)i3;
      i4 = (OOC_INT32)s;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i3, (OOC_SSA__Result)i4, 2);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i3, (OOC_SSA__Result)i0, 4);
      i4 = (OOC_INT32)array;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 54229))+8);
      i4 = (OOC_INT32)OOC_SSA__InstrDesc_GetOpndClass((OOC_SSA__Instr)i4, 5);
      opnd = (OOC_SSA__Opnd)i4;
      i5 = i4!=(OOC_INT32)0;
      if (i5) goto l3;
      i5=0u;
      goto l5;
l3:
      i5 = *(OOC_INT8*)((_check_pointer(i4, 54299))+4);
      i5 = i5==5;
      
l5:
      if (!i5) goto l16;
l7_loop:
      i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 54352));
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i3, (OOC_SSA__Result)i5, 5);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 54396))+8);
      opnd = (OOC_SSA__Opnd)i4;
      i5 = i4!=(OOC_INT32)0;
      if (i5) goto l10;
      i5=0u;
      goto l12;
l10:
      i5 = *(OOC_INT8*)((_check_pointer(i4, 54299))+4);
      i5 = i5==5;
      
l12:
      if (i5) goto l7_loop;
l16:
      i4 = (OOC_INT32)OOC_SSA__InstrDesc_AddResult((OOC_SSA__Instr)i3, 2);
      s = (OOC_SSA__Result)i4;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 54577))+8);
      i4 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i4);
      v = (OOC_SSA__Result)i4;
      i5 = (OOC_INT32)pb;
      i3 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddSetInstr((OOC_SSA__ProcBlock)i5, (OOC_SSA__Instr)(_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 54618)))), &_td_OOC_SSA__InstrDesc, 54618)), (OOC_SSA__Result)i3);
      OOC_SSA_IRtoSSA__StatmSeq_Chain((OOC_SSA__Instr)i3);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 54707))+16);
      i3 = (OOC_INT32)s;
      i4 = (OOC_INT32)pb;
      i1 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq((OOC_SSA__ProcBlock)i4, (OOC_SSA__Result)i3, (OOC_IR__StatementSeq)i1);
      s = (OOC_SSA__Result)i1;
      i1 = (OOC_INT32)pb;
      i1 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i1, 19, 9);
      curr2 = (OOC_SSA__Instr)i1;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i0, 1);
      i0 = *(OOC_INT32*)((_check_pointer(i2, 54911))+32);
      i2 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConstInt((OOC_SSA__ProcBlock)i2, i0);
      i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_FixAddress((OOC_SSA__Result)i0);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i0, 1);
      i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_IterateArrayStatm_Guard((OOC_SSA__Result)i1);
      guard2 = (OOC_SSA__Result)i0;
      i1 = (OOC_INT32)pb;
      i1 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i1, 9, 0);
      exit = (OOC_SSA__Instr)i1;
      i2 = (OOC_INT32)s;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i2, 2);
      i2 = (OOC_INT32)pb;
      i2 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i2, 5, 0);
      select = (OOC_SSA__Instr)i2;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i0, 1);
      i0 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConstBool((OOC_SSA__ProcBlock)i0, 1u);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i0, 1);
      i0 = (OOC_INT32)s;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i0, 1);
      i0 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConstBool((OOC_SSA__ProcBlock)i0, 0u);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i0, 1);
      i0 = (OOC_INT32)OOC_SSA__InstrDesc_AddResult((OOC_SSA__Instr)i1, 2);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i0, 1);
      i0 = (OOC_INT32)OOC_SSA__InstrDesc_AddResult((OOC_SSA__Instr)i2, 2);
      s = (OOC_SSA__Result)i0;
      i0 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i0, 11, 0);
      loopEnd = (OOC_SSA__Instr)i0;
      i2 = (OOC_INT32)loopStart;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i2, 1);
      i2 = (OOC_INT32)pb;
      i2 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i2, 6, 0);
      collect = (OOC_SSA__Instr)i2;
      i3 = (OOC_INT32)s;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i3, 2);
      i3 = (OOC_INT32)curr2;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i3, 1);
      i2 = (OOC_INT32)OOC_SSA__InstrDesc_AddResult((OOC_SSA__Instr)i2, 2);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i2, 13);
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 55944));
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i1, 11);
      i1 = (OOC_INT32)pb;
      i1 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i1, 5, 0);
      i2 = (OOC_INT32)guard1;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i2, 1);
      i2 = (OOC_INT32)pb;
      i2 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConstBool((OOC_SSA__ProcBlock)i2, 1u);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i2, 1);
      i0 = (OOC_INT32)OOC_SSA__InstrDesc_AddResult((OOC_SSA__Instr)i0, 2);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i0, 1);
      i0 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConstBool((OOC_SSA__ProcBlock)i0, 0u);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i0, 1);
      i0 = (OOC_INT32)storeAfterGuard1;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i0, 1);
      i0 = (OOC_INT32)OOC_SSA__InstrDesc_AddResult((OOC_SSA__Instr)i1, 2);
      s = (OOC_SSA__Result)i0;
      return;
      ;
    }

    
    void OOC_SSA_IRtoSSA__StatmSeq_IterateObjectStatm(OOC_IR__IterateObjectStatm iterStatm) {
      register OOC_INT32 i0,i1,i2;
      OOC_SSA__Result iterator;
      OOC_SSA__Result guard1;
      OOC_SSA__Result storeAfterGuard1;
      OOC_SSA__Instr loopStart;
      OOC_SSA__Result guard2;
      OOC_SSA__Instr exit;
      OOC_SSA__Instr select;
      OOC_SSA__Instr loopEnd;
      auto OOC_SSA__Instr OOC_SSA_IRtoSSA__StatmSeq_IterateObjectStatm_Guard(void);
        
        OOC_SSA__Instr OOC_SSA_IRtoSSA__StatmSeq_IterateObjectStatm_Guard(void) {
          register OOC_INT32 i0,i1,i2;
          OOC_SSA__Result res;
          OOC_SSA__Instr instr;
          OOC_SSA__Instr typeTag;

          i0 = (OOC_INT32)iterStatm;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 56789))+16);
          i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i0);
          res = (OOC_SSA__Result)i0;
          i0 = _type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 56829)))), &_td_OOC_SSA__InstrDesc, 56829);
          instr = (OOC_SSA__Instr)i0;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 56861))+24);
          i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 56870));
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 56879)))), &_td_OOC_SSA__InstrDesc, 56879)), 56885))+24);
          i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 56894));
          i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 56903)))), &_td_OOC_SSA__InstrDesc, 56903);
          typeTag = (OOC_SSA__Instr)i1;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 56926))+24);
          i2 = (OOC_INT32)iterator;
          OOC_SSA__OpndDesc_ReplaceArg((OOC_SSA__Opnd)i1, (OOC_SSA__Result)i2);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 56971))+24);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 56980))+8);
          i2 = (OOC_INT32)iterator;
          OOC_SSA__OpndDesc_ReplaceArg((OOC_SSA__Opnd)i1, (OOC_SSA__Result)i2);
          return (OOC_SSA__Instr)i0;
          ;
        }


      i0 = (OOC_INT32)iterStatm;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 57316))+12);
      i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i0);
      iterator = (OOC_SSA__Result)i0;
      i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_IterateObjectStatm_Guard();
      guard1 = (OOC_SSA__Result)i0;
      i0 = (OOC_INT32)s;
      storeAfterGuard1 = (OOC_SSA__Result)i0;
      i0 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i0, 10, 0);
      loopStart = (OOC_SSA__Instr)i0;
      i1 = (OOC_INT32)s;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i1, 2);
      i0 = (OOC_INT32)OOC_SSA__InstrDesc_AddResult((OOC_SSA__Instr)i0, 2);
      s = (OOC_SSA__Result)i0;
      i1 = (OOC_INT32)iterStatm;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 57737))+20);
      i2 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq((OOC_SSA__ProcBlock)i2, (OOC_SSA__Result)i0, (OOC_IR__StatementSeq)i1);
      s = (OOC_SSA__Result)i0;
      i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_IterateObjectStatm_Guard();
      guard2 = (OOC_SSA__Result)i0;
      i1 = (OOC_INT32)pb;
      i1 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i1, 9, 0);
      exit = (OOC_SSA__Instr)i1;
      i2 = (OOC_INT32)s;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i2, 2);
      i2 = (OOC_INT32)pb;
      i2 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i2, 5, 0);
      select = (OOC_SSA__Instr)i2;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i0, 1);
      i0 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConstBool((OOC_SSA__ProcBlock)i0, 1u);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i0, 1);
      i0 = (OOC_INT32)s;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i0, 1);
      i0 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConstBool((OOC_SSA__ProcBlock)i0, 0u);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i0, 1);
      i0 = (OOC_INT32)OOC_SSA__InstrDesc_AddResult((OOC_SSA__Instr)i1, 2);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i0, 1);
      i0 = (OOC_INT32)OOC_SSA__InstrDesc_AddResult((OOC_SSA__Instr)i2, 2);
      s = (OOC_SSA__Result)i0;
      i0 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i0, 11, 0);
      loopEnd = (OOC_SSA__Instr)i0;
      i2 = (OOC_INT32)loopStart;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i2, 1);
      i2 = (OOC_INT32)s;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i2, 13);
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 58609));
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i1, 11);
      i1 = (OOC_INT32)pb;
      i1 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i1, 5, 0);
      i2 = (OOC_INT32)guard1;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i2, 1);
      i2 = (OOC_INT32)pb;
      i2 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConstBool((OOC_SSA__ProcBlock)i2, 1u);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i2, 1);
      i0 = (OOC_INT32)OOC_SSA__InstrDesc_AddResult((OOC_SSA__Instr)i0, 2);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i0, 1);
      i0 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConstBool((OOC_SSA__ProcBlock)i0, 0u);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i0, 1);
      i0 = (OOC_INT32)storeAfterGuard1;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i0, 1);
      i0 = (OOC_INT32)OOC_SSA__InstrDesc_AddResult((OOC_SSA__Instr)i1, 2);
      s = (OOC_SSA__Result)i0;
      return;
      ;
    }

    
    void OOC_SSA_IRtoSSA__StatmSeq_LoopStatm(OOC_IR__LoopStatm loopStatm) {
      register OOC_INT32 i0,i1,i2,i3,i4;
      OOC_SSA__Instr start;
      OOC_SSA__Instr end;
      OOC_SSA__Instr oldSelect;

      i0 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i0, 10, 0);
      start = (OOC_SSA__Instr)i0;
      i1 = (OOC_INT32)s;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i1, 2);
      i1 = (OOC_INT32)OOC_SSA__InstrDesc_AddResult((OOC_SSA__Instr)i0, 2);
      s = (OOC_SSA__Result)i1;
      i1 = (OOC_INT32)pb;
      i1 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i1, 11, 0);
      end = (OOC_SSA__Instr)i1;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i0, 1);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i0, 13);
      i0 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_SetLoopContext((OOC_SSA__ProcBlock)i0, (OOC_SSA__Instr)i1);
      oldSelect = (OOC_SSA__Instr)i0;
      i2 = (OOC_INT32)loopStatm;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 59693))+8);
      i3 = (OOC_INT32)s;
      i4 = (OOC_INT32)pb;
      i2 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq((OOC_SSA__ProcBlock)i4, (OOC_SSA__Result)i3, (OOC_IR__StatementSeq)i2);
      s = (OOC_SSA__Result)i2;
      i3 = (OOC_INT32)pb;
      OOC_SSA_IRtoSSA__AddStoreBackwardFeed((OOC_SSA__ProcBlock)i3, (OOC_SSA__Instr)i1, (OOC_SSA__Result)i2);
      i1 = (OOC_INT32)OOC_SSA__InstrDesc_AddResult((OOC_SSA__Instr)i1, 2);
      s = (OOC_SSA__Result)i1;
      i1 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_SetLoopContext((OOC_SSA__ProcBlock)i1, (OOC_SSA__Instr)i0);
      return;
      ;
    }

    
    void OOC_SSA_IRtoSSA__StatmSeq_Exit(OOC_IR__Exit exit) {
      register OOC_INT32 i0,i1;
      OOC_SSA__Instr instr;
      OOC_SSA__Result store;

      i0 = (OOC_INT32)exit;
      i0 = *(OOC_INT32*)((_check_pointer(i0, 60175))+12);
      i1 = (OOC_INT32)s;
      i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_PopExceptionContext((OOC_SSA__Result)i1, i0);
      s = (OOC_SSA__Result)i0;
      i0 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i0, 9, 0);
      instr = (OOC_SSA__Instr)i0;
      i1 = (OOC_INT32)s;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i1, 2);
      i0 = (OOC_INT32)OOC_SSA__InstrDesc_AddResult((OOC_SSA__Instr)i0, 2);
      store = (OOC_SSA__Result)i0;
      i1 = (OOC_INT32)pb;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 60357))+4);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i0, 11);
      s = (OOC_SSA__Result)i0;
      return;
      ;
    }

    
    void OOC_SSA_IRtoSSA__StatmSeq_TryStatm(OOC_IR__TryStatm _try) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10;
      OOC_SSA__Instr start;
      OOC_SSA__Instr instr;
      OOC_SSA__Instr oldPushContext;
      OOC_SSA__Result sDefault;
      OOC_SSA__Instr pushExceptionContext;
      OOC_SSA__Instr e;
      OOC_SSA__Instr typeTag;
      OOC_SSA__Result sCatch;
      OOC_INT32 i;
      OOC_SSA__Instr typeTest;
      OOC_SSA__Result catchClause;

      i0 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i0, 72, 5);
      start = (OOC_SSA__Instr)i0;
      i1 = (OOC_INT32)s;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i1, 2);
      i1 = (OOC_INT32)OOC_SSA__InstrDesc_AddResult((OOC_SSA__Instr)i0, 2);
      s = (OOC_SSA__Result)i1;
      i1 = (OOC_INT32)pb;
      i1 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i1, 78, 0);
      instr = (OOC_SSA__Instr)i1;
      i2 = (OOC_INT32)s;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i2, 2);
      i2 = (OOC_INT32)pb;
      i2 = (OOC_INT32)OOC_SSA__ProcBlockDesc_SetTryContext((OOC_SSA__ProcBlock)i2, (OOC_SSA__Instr)i1);
      oldPushContext = (OOC_SSA__Instr)i2;
      i3 = (OOC_INT32)_try;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 61061))+8);
      i5 = (OOC_INT32)OOC_SSA__InstrDesc_AddResult((OOC_SSA__Instr)i1, 2);
      i6 = (OOC_INT32)pb;
      i4 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq((OOC_SSA__ProcBlock)i6, (OOC_SSA__Result)i5, (OOC_IR__StatementSeq)i4);
      s = (OOC_SSA__Result)i4;
      i4 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_PopExceptionContext((OOC_SSA__Result)i4, 1);
      sDefault = (OOC_SSA__Result)i4;
      pushExceptionContext = (OOC_SSA__Instr)i1;
      i5 = (OOC_INT32)OOC_SSA__InstrDesc_AddResult((OOC_SSA__Instr)i0, 2);
      i5 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_PopExceptionContext((OOC_SSA__Result)i5, 1);
      s = (OOC_SSA__Result)i5;
      i5 = (OOC_INT32)pb;
      i5 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i5, 76, 9);
      e = (OOC_SSA__Instr)i5;
      i6 = (OOC_INT32)pb;
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 61398))+8);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i5, (OOC_SSA__Result)i6, 1);
      i6 = (OOC_INT32)s;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i5, (OOC_SSA__Result)i6, 2);
      i6 = (OOC_INT32)pb;
      i6 = (OOC_INT32)OOC_SSA__ProcBlockDesc_SetTryContext((OOC_SSA__ProcBlock)i6, (OOC_SSA__Instr)i5);
      i6 = (OOC_INT32)pb;
      i6 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i6, 61, 9);
      typeTag = (OOC_SSA__Instr)i6;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i6, (OOC_SSA__Result)i5, 1);
      i5 = (OOC_INT32)s;
      sCatch = (OOC_SSA__Result)i5;
      i7 = (OOC_INT32)pb;
      i7 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i7, 80, 0);
      instr = (OOC_SSA__Instr)i7;
      i8 = (OOC_INT32)s;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i7, (OOC_SSA__Result)i8, 2);
      i7 = (OOC_INT32)OOC_SSA__InstrDesc_AddResult((OOC_SSA__Instr)i7, 2);
      s = (OOC_SSA__Result)i7;
      i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 61872))+12);
      i7 = OOC_ARRAY_LENGTH((_check_pointer(i7, 61882)), 0);
      i7 = i7-1;
      i = i7;
      i8 = i7>=0;
      if (!i8) goto l8;
l3_loop:
      i8 = (OOC_INT32)pb;
      i8 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i8, 62, 5);
      typeTest = (OOC_SSA__Instr)i8;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i8, (OOC_SSA__Result)i6, 1);
      i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 62056))+12);
      i9 = _check_pointer(i9, 62066);
      i10 = OOC_ARRAY_LENGTH(i9, 0);
      i9 = (OOC_INT32)*(OOC_INT32*)(i9+(_check_index(i7, i10, OOC_UINT32, 62066))*4);
      i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i9, 62069))+8);
      i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i9, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i9, 62088)))), &_td_OOC_SymbolTable__PointerDesc, 62088)), 62096))+40);
      i10 = (OOC_INT32)pb;
      i9 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetTypeRef((OOC_SSA__ProcBlock)i10, (OOC_SymbolTable__Type)i9);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i8, (OOC_SSA__Result)i9, 12);
      i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 62168))+12);
      i9 = _check_pointer(i9, 62178);
      i10 = OOC_ARRAY_LENGTH(i9, 0);
      i9 = (OOC_INT32)*(OOC_INT32*)(i9+(_check_index(i7, i10, OOC_UINT32, 62178))*4);
      i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i9, 62181))+12);
      i10 = (OOC_INT32)pb;
      i9 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq((OOC_SSA__ProcBlock)i10, (OOC_SSA__Result)i5, (OOC_IR__StatementSeq)i9);
      catchClause = (OOC_SSA__Result)i9;
      i10 = (OOC_INT32)pb;
      i10 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i10, 5, 0);
      instr = (OOC_SSA__Instr)i10;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i10, (OOC_SSA__Result)i8, 1);
      i8 = (OOC_INT32)pb;
      i8 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConstBool((OOC_SSA__ProcBlock)i8, 1u);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i10, (OOC_SSA__Result)i8, 1);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i10, (OOC_SSA__Result)i9, 1);
      i8 = (OOC_INT32)pb;
      i8 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConstBool((OOC_SSA__ProcBlock)i8, 0u);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i10, (OOC_SSA__Result)i8, 1);
      i8 = (OOC_INT32)s;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i10, (OOC_SSA__Result)i8, 1);
      i8 = (OOC_INT32)OOC_SSA__InstrDesc_AddResult((OOC_SSA__Instr)i10, 2);
      s = (OOC_SSA__Result)i8;
      i7 = i7+(-1);
      i = i7;
      i8 = i7>=0;
      if (i8) goto l3_loop;
l8:
      i3 = (OOC_INT32)pb;
      i3 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i3, 77, 0);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i3, (OOC_SSA__Result)i1, 1);
      i1 = (OOC_INT32)s;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i3, (OOC_SSA__Result)i1, 2);
      i1 = (OOC_INT32)OOC_SSA__InstrDesc_AddResult((OOC_SSA__Instr)i3, 2);
      s = (OOC_SSA__Result)i1;
      i1 = (OOC_INT32)pb;
      i1 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i1, 5, 0);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i0, 1);
      i0 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConstBool((OOC_SSA__ProcBlock)i0, 0u);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i0, 1);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i4, 1);
      i0 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConstBool((OOC_SSA__ProcBlock)i0, 1u);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i0, 1);
      i0 = (OOC_INT32)s;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i0, 1);
      i0 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i0, 73, 0);
      i1 = (OOC_INT32)OOC_SSA__InstrDesc_AddResult((OOC_SSA__Instr)i1, 2);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i1, 2);
      i0 = (OOC_INT32)OOC_SSA__InstrDesc_AddResult((OOC_SSA__Instr)i0, 2);
      s = (OOC_SSA__Result)i0;
      i0 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_SetTryContext((OOC_SSA__ProcBlock)i0, (OOC_SSA__Instr)i2);
      return;
      ;
    }

    
    void OOC_SSA_IRtoSSA__StatmSeq_CopyParameter(OOC_IR__CopyParameter cp) {
      register OOC_INT32 i0,i1,i2,i3,i4;
      OOC_SSA__Result len;

      i0 = (OOC_INT32)cp;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 63561))+8);
      i1 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i1);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 63535))+8);
      i3 = (OOC_INT32)pb;
      i1 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_CalculateLength((OOC_SSA__ProcBlock)i3, (OOC_IR__Expression)i2, (-1), (OOC_SSA__Result)i1);
      len = (OOC_SSA__Result)i1;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 63701))+8);
      i3 = (OOC_INT32)pb;
      i2 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_CalculateSize((OOC_SSA__ProcBlock)i3, (OOC_IR__Expression)i2, (OOC_SSA__Result)i1);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 63609))+8);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 63616))+8);
      i3 = (OOC_INT32)s;
      i4 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddCopyParameter((OOC_SSA__ProcBlock)i4, (OOC_SymbolTable__VarDecl)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 63627)))), &_td_OOC_SymbolTable__VarDeclDesc, 63627)), (OOC_SSA__Result)i3, (OOC_SSA__Result)i1, (OOC_SSA__Result)i2);
      i0 = (OOC_INT32)OOC_SSA__InstrDesc_AddResult((OOC_SSA__Instr)i0, 2);
      s = (OOC_SSA__Result)i0;
      return;
      ;
    }

    
    OOC_SSA__Instr OOC_SSA_IRtoSSA__StatmSeq_MoveBlock(OOC_IR__MoveBlock move) {
      register OOC_INT32 i0,i1,i2,i3,i4;
      OOC_SSA__Result source;
      OOC_SSA__Result dest;

      i0 = (OOC_INT32)move;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 63953))+8);
      i1 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i1);
      source = (OOC_SSA__Result)i1;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 63994))+12);
      i2 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i2);
      dest = (OOC_SSA__Result)i2;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 64033))+16);
      i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i0);
      i3 = (OOC_INT32)pb;
      i3 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i3, 18, 0);
      i4 = (OOC_INT32)s;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i3, (OOC_SSA__Result)i4, 2);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i3, (OOC_SSA__Result)i1, 4);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i3, (OOC_SSA__Result)i2, 6);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i3, (OOC_SSA__Result)i0, 1);
      return (OOC_SSA__Instr)i3;
      ;
    }

    
    OOC_SSA__Instr OOC_SSA_IRtoSSA__StatmSeq_Raise(OOC_IR__Raise raise) {
      register OOC_INT32 i0,i1,i2;

      i0 = (OOC_INT32)raise;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 64476))+8);
      i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Expression((OOC_IR__Expression)i0);
      i1 = (OOC_INT32)pb;
      i1 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i1, 74, 0);
      i2 = (OOC_INT32)s;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i2, 2);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i0, 1);
      return (OOC_SSA__Instr)i1;
      ;
    }


  i0 = (OOC_INT32)statmSeq;
  i = 0;
  i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 64717)), 0);
  i1 = 0<i0;
  if (!i1) goto l88;
  i1=0;
l3_loop:
  i2 = (OOC_INT32)statmSeq;
  i2 = _check_pointer(i2, 64748);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i1, i3, OOC_UINT32, 64748))*4);
  statm = (OOC_IR__Statement)i1;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 64769)))), &_td_OOC_IR__AssertDesc);
  if (i2) goto l82;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 64822)))), &_td_OOC_IR__AssignmentDesc);
  if (i2) goto l80;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 64903)))), &_td_OOC_IR__CallDesc);
  if (i2) goto l78;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 64968)))), &_td_OOC_IR__ReturnDesc);
  if (i2) goto l76;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 65021)))), &_td_OOC_IR__IfStatmDesc);
  if (i2) goto l74;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 65076)))), &_td_OOC_IR__WithStatmDesc);
  if (i2) goto l72;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 65135)))), &_td_OOC_IR__CaseStatmDesc);
  if (i2) goto l70;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 65206)))), &_td_OOC_IR__RepeatStatmDesc);
  if (i2) goto l68;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 65281)))), &_td_OOC_IR__WhileStatmDesc);
  if (i2) goto l66;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 65342)))), &_td_OOC_IR__ForStatmDesc);
  if (i2) goto l64;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 65399)))), &_td_OOC_IR__IterateArrayStatmDesc);
  if (i2) goto l62;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 65474)))), &_td_OOC_IR__IterateObjectStatmDesc);
  if (i2) goto l60;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 65551)))), &_td_OOC_IR__LoopStatmDesc);
  if (i2) goto l58;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 65610)))), &_td_OOC_IR__ExitDesc);
  if (i2) goto l56;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 65659)))), &_td_OOC_IR__TryStatmDesc);
  if (i2) goto l54;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 65724)))), &_td_OOC_IR__CopyDesc);
  if (i2) goto l52;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 65793)))), &_td_OOC_IR__CopyParameterDesc);
  if (i2) goto l50;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 65872)))), &_td_OOC_IR__CopyStringDesc);
  if (i2) goto l48;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 65941)))), &_td_OOC_IR__MoveBlockDesc);
  if (i2) goto l46;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 66008)))), &_td_OOC_IR__RaiseDesc);
  if (i2) goto l44;
  Log__Type("++ Unknown statement class in StatmSeq", 39, (void*)i1);
  _assert(0u, 127, 66139);
  goto l83;
l44:
  i1 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Raise((OOC_IR__Raise)i1);
  OOC_SSA_IRtoSSA__StatmSeq_Chain((OOC_SSA__Instr)i1);
  goto l83;
l46:
  i1 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_MoveBlock((OOC_IR__MoveBlock)i1);
  OOC_SSA_IRtoSSA__StatmSeq_Chain((OOC_SSA__Instr)i1);
  goto l83;
l48:
  i1 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_CopyString((OOC_IR__CopyString)i1);
  OOC_SSA_IRtoSSA__StatmSeq_Chain((OOC_SSA__Instr)i1);
  goto l83;
l50:
  OOC_SSA_IRtoSSA__StatmSeq_CopyParameter((OOC_IR__CopyParameter)i1);
  goto l83;
l52:
  i1 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Copy((OOC_IR__Copy)i1);
  OOC_SSA_IRtoSSA__StatmSeq_Chain((OOC_SSA__Instr)i1);
  goto l83;
l54:
  OOC_SSA_IRtoSSA__StatmSeq_TryStatm((OOC_IR__TryStatm)i1);
  goto l83;
l56:
  OOC_SSA_IRtoSSA__StatmSeq_Exit((OOC_IR__Exit)i1);
  goto l83;
l58:
  OOC_SSA_IRtoSSA__StatmSeq_LoopStatm((OOC_IR__LoopStatm)i1);
  goto l83;
l60:
  OOC_SSA_IRtoSSA__StatmSeq_IterateObjectStatm((OOC_IR__IterateObjectStatm)i1);
  goto l83;
l62:
  OOC_SSA_IRtoSSA__StatmSeq_IterateArrayStatm((OOC_IR__IterateArrayStatm)i1);
  goto l83;
l64:
  OOC_SSA_IRtoSSA__StatmSeq_ForStatm((OOC_IR__ForStatm)i1);
  goto l83;
l66:
  OOC_SSA_IRtoSSA__StatmSeq_WhileStatm((OOC_IR__WhileStatm)i1);
  goto l83;
l68:
  OOC_SSA_IRtoSSA__StatmSeq_RepeatStatm((OOC_IR__RepeatStatm)i1);
  goto l83;
l70:
  OOC_SSA_IRtoSSA__StatmSeq_CaseStatm((OOC_IR__CaseStatm)i1);
  goto l83;
l72:
  OOC_SSA_IRtoSSA__StatmSeq_WithStatm((OOC_IR__WithStatm)i1);
  goto l83;
l74:
  OOC_SSA_IRtoSSA__StatmSeq_IfStatm((OOC_IR__IfStatm)i1);
  goto l83;
l76:
  OOC_SSA_IRtoSSA__StatmSeq_Return((OOC_IR__Return)i1);
  goto l83;
l78:
  i1 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Call((OOC_IR__Call)i1);
  OOC_SSA_IRtoSSA__StatmSeq_Chain((OOC_SSA__Instr)i1);
  goto l83;
l80:
  i1 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq_Assignment((OOC_IR__Assignment)i1);
  OOC_SSA_IRtoSSA__StatmSeq_Chain((OOC_SSA__Instr)i1);
  goto l83;
l82:
  OOC_SSA_IRtoSSA__StatmSeq_Assert((OOC_IR__Assert)i1);
l83:
  i1 = i;
  i1 = i1+1;
  i = i1;
  i2 = i1<i0;
  if (i2) goto l3_loop;
l88:
  i0 = (OOC_INT32)s;
  return (OOC_SSA__Result)i0;
  ;
}

void OOC_SSA_IRtoSSA__DiscardGets(OOC_SSA__ProcBlock pb) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_SSA__Instr instr;
  OOC_SSA__Instr next;
  OOC_SSA__Result storeOut;

  i0 = (OOC_INT32)pb;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 66331))+12);
  instr = (OOC_SSA__Instr)i1;
  i2 = i1!=(OOC_INT32)0;
  if (!i2) goto l15;
l3_loop:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 66390))+28);
  next = (OOC_SSA__Instr)i2;
  i3 = *(OOC_INT8*)((_check_pointer(i1, 66418))+36);
  i3 = i3==12;
  if (i3) goto l6;
  i3=0u;
  goto l8;
l6:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 66449))+12);
  i3 = i3==(OOC_INT32)0;
  
l8:
  if (!i3) goto l10;
  i3 = (OOC_INT32)OOC_SSA__InstrDesc_GetResultStore((OOC_SSA__Instr)i1);
  storeOut = (OOC_SSA__Result)i3;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 66552))+24);
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 66562));
  OOC_SSA__ResultDesc_ReplaceUses((OOC_SSA__Result)i3, (OOC_SSA__Result)i4);
  OOC_SSA__ProcBlockDesc_DeleteInstr((OOC_SSA__ProcBlock)i0, (OOC_SSA__Instr)i1);
l10:
  instr = (OOC_SSA__Instr)i2;
  i1 = i2!=(OOC_INT32)0;
  if (!i1) goto l15;
  i1=i2;
  goto l3_loop;
l15:
  return;
  ;
}

void OOC_OOC_SSA_IRtoSSA_init(void) {

  return;
  ;
}

/* --- */
