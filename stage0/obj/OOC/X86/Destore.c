#include <OOC/X86/Destore.d>
#include <__oo2c.h>
#include <setjmp.h>

void OOC_X86_Destore__MemAccessDesc_INIT(OOC_X86_Destore__MemAccess memAccess, OOC_INT8 type, OOC_X86_SSA__Designator designator, OOC_X86_SSA__Result address) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)memAccess;
  i1 = (OOC_INT32)designator;
  *(OOC_INT32*)(_check_pointer(i0, 581)) = i1;
  i1 = (OOC_INT32)address;
  *(OOC_INT32*)((_check_pointer(i0, 621))+4) = i1;
  i1 = type;
  *(OOC_INT8*)((_check_pointer(i0, 655))+8) = i1;
  return;
  ;
}

void OOC_X86_Destore__Transform(OOC_X86_SSA__FunctionBlock fctBlock) {
  register OOC_INT32 i0,i1,i2;
  OOC_X86_Destore__Worklist worklist;
  OOC_X86_SSA__Result undefValue;
  ADT_Dictionary__Dictionary gateToInstr;
  OOC_X86_SSA__Instr instr;
  OOC_X86_SSA__GateInstr gate;
  auto OOC_CHAR8 OOC_X86_Destore__Transform_AccessedByCall(OOC_X86_SSA__Result calledAdr, OOC_X86_SSA__Designator design, OOC_INT8 mode);
  auto void OOC_X86_Destore__Transform_AddToWorklist(OOC_X86_SSA__Instr instr);
  auto void OOC_X86_Destore__Transform_PropagateInstr(OOC_X86_SSA__Instr propInstr);
  auto OOC_CHAR8 OOC_X86_Destore__Transform_VisibleEffect(OOC_X86_SSA__Instr store, OOC_X86_SSA__Instr set);
  auto void OOC_X86_Destore__Transform_AddDesignatorGatetoWorklist(OOC_X86_SSA__Block b);
  auto void OOC_X86_Destore__Transform_ReplaceUses(OOC_X86_SSA__Result old, OOC_X86_SSA__Result _new, OOC_CHAR8 eliminateLoopEnd);
  auto void OOC_X86_Destore__Transform_PromoteDesignatorGate(OOC_X86_SSA__GateInstr instr);
  auto void OOC_X86_Destore__Transform_AddMemoryDeps(OOC_X86_SSA__Instr instr);
  auto void OOC_X86_Destore__Transform_FixLoopStart(OOC_X86_SSA__GateInstr gate);
    
    OOC_CHAR8 OOC_X86_Destore__Transform_AccessedByCall(OOC_X86_SSA__Result calledAdr, OOC_X86_SSA__Designator design, OOC_INT8 mode) {

      return 1u;
      ;
    }

    
    void OOC_X86_Destore__Transform_AddToWorklist(OOC_X86_SSA__Instr instr) {
      register OOC_INT32 i0,i1;
      OOC_X86_Destore__Worklist entry;

      i0 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_Destore__Worklist.baseTypes[0]);
      entry = (OOC_X86_Destore__Worklist)i0;
      i1 = (OOC_INT32)worklist;
      *(OOC_INT32*)(_check_pointer(i0, 1366)) = i1;
      i1 = (OOC_INT32)instr;
      *(OOC_INT32*)((_check_pointer(i0, 1396))+4) = i1;
      worklist = (OOC_X86_Destore__Worklist)i0;
      return;
      ;
    }

    
    void OOC_X86_Destore__Transform_PropagateInstr(OOC_X86_SSA__Instr propInstr) {
      register OOC_INT32 i0,i1,i2;
      auto void OOC_X86_Destore__Transform_PropagateInstr_PropagateValue(OOC_X86_SSA__Designator designator, OOC_X86_SSA__Result value, OOC_X86_SSA__Instr instr);
      auto OOC_CHAR8 OOC_X86_Destore__Transform_PropagateInstr_FixedDesignator(OOC_X86_SSA__Designator designator);
        
        void OOC_X86_Destore__Transform_PropagateInstr_PropagateValue(OOC_X86_SSA__Designator designator, OOC_X86_SSA__Result value, OOC_X86_SSA__Instr instr) {
          register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
          OOC_X86_SSA__Dep dep;
          OOC_X86_SSA__Instr afterInstr;
          OOC_X86_SSA__Instr merge;
          auto OOC_X86_SSA__GateInstr OOC_X86_Destore__Transform_PropagateInstr_PropagateValue_GetDesignatorGate(OOC_X86_SSA__Block merge, OOC_X86_SSA__Designator designator);
          auto void OOC_X86_Destore__Transform_PropagateInstr_PropagateValue_MergeValue(OOC_X86_SSA__MergeInstr merge, OOC_X86_SSA__Instr jump, OOC_X86_SSA__Designator designator, OOC_X86_SSA__Result value);
          auto void OOC_X86_Destore__Transform_PropagateInstr_PropagateValue_MergeLoopValue(OOC_X86_SSA__Block loopStart, OOC_INT32 pathIndex, OOC_X86_SSA__Designator designator, OOC_X86_SSA__Result value);
            
            OOC_X86_SSA__GateInstr OOC_X86_Destore__Transform_PropagateInstr_PropagateValue_GetDesignatorGate(OOC_X86_SSA__Block merge, OOC_X86_SSA__Designator designator) {
              register OOC_INT32 i0,i1,i2,i3,i4,i5;
              OOC_X86_SSA__Instr instr;
              OOC_X86_SSA__GateInstr gate;
              OOC_INT32 i;
              OOC_INT8 type;

              i0 = (OOC_INT32)merge;
              i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_Instructions((OOC_X86_SSA__Block)i0);
              i2 = (OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG(i1)), OOC_X86_SSA__IterBlockInstructionsDesc_Next);
              i3 = (OOC_INT32)designator;
              i4 = OOC_TBCALL(i2,OOC_X86_SSA__IterBlockInstructionsDesc_Next)((OOC_X86_SSA__IterBlockInstructions)i1, (void*)(OOC_INT32)&instr);
              if (!i4) goto l15;
l3_loop:
              i4 = (OOC_INT32)instr;
              i5 = *(OOC_INT8*)((_check_pointer(i4, 2205))+20);
              i5 = i5==39;
              if (i5) goto l6;
              i4=0u;
              goto l8;
l6:
              i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 2284))+28);
              i4 = OOC_X86_SSA__SameDesignator((OOC_X86_SSA__Designator)i3, (OOC_X86_SSA__Designator)i4);
              
l8:
              if (!i4) goto l10;
              i4 = (OOC_INT32)instr;
              return (OOC_X86_SSA__GateInstr)(_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 2331)))), &_td_OOC_X86_SSA__GateInstrDesc, 2331));
l10:
              i4 = OOC_TBCALL(i2,OOC_X86_SSA__IterBlockInstructionsDesc_Next)((OOC_X86_SSA__IterBlockInstructions)i1, (void*)(OOC_INT32)&instr);
              if (i4) goto l3_loop;
l15:
              i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddGate((OOC_X86_SSA__Block)i0, 39);
              gate = (OOC_X86_SSA__GateInstr)i1;
              OOC_X86_SSA__InstrDesc_SetDesignator((OOC_X86_SSA__Instr)i1, (OOC_X86_SSA__Designator)i3);
              i0 = OOC_X86_SSA__InstrDesc_IncomingPaths((OOC_X86_SSA__Instr)i0);
              i = 1;
              i2 = 1<=i0;
              if (!i2) goto l23;
              i2=1;
l18_loop:
              i3 = (OOC_INT32)undefValue;
              OOC_X86_SSA__InstrDesc_AddOpnd((OOC_X86_SSA__Instr)i1, (OOC_X86_SSA__Result)i3);
              i2 = i2+1;
              i = i2;
              i3 = i2<=i0;
              if (i3) goto l18_loop;
l23:
              i0 = (OOC_INT32)propInstr;
              i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2595)))), &_td_OOC_X86_SSA__GateInstrDesc);
              if (i2) goto l31;
              i2 = *(OOC_INT8*)((_check_pointer(i0, 2716))+20);
              switch (i2) {
              case 24:
                i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2779))+4);
                i2 = *(OOC_INT8*)((_check_pointer(i2, 2790))+12);
                type = i2;
                goto l30;
              case 25:
                i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 2849));
                i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 2858))+4);
                i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 2867));
                i2 = *(OOC_INT8*)((_check_pointer(i2, 2871))+12);
                type = i2;
                goto l30;
              default:
                _failed_case(i2, 2702);
                goto l30;
              }
l30:
              i2 = type;
              _assert((i2!=0), 127, 2907);
              i3 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_Destore__MemAccess.baseTypes[0]);
              i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 3055));
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2995))+28);
              i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 3064));
              OOC_X86_Destore__MemAccessDesc_INIT((OOC_X86_Destore__MemAccess)i3, i2, (OOC_X86_SSA__Designator)i0, (OOC_X86_SSA__Result)i4);
              i0 = (OOC_INT32)gateToInstr;
              ADT_Dictionary__DictionaryDesc_Set((ADT_Dictionary__Dictionary)i0, (Object__Object)i1, (Object__Object)i3);
              goto l32;
l31:
              i2 = (OOC_INT32)gateToInstr;
              i0 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i2, (Object__Object)i0);
              i2 = (OOC_INT32)gateToInstr;
              ADT_Dictionary__DictionaryDesc_Set((ADT_Dictionary__Dictionary)i2, (Object__Object)i1, (Object__Object)i0);
l32:
              return (OOC_X86_SSA__GateInstr)i1;
              ;
            }

            
            void OOC_X86_Destore__Transform_PropagateInstr_PropagateValue_MergeValue(OOC_X86_SSA__MergeInstr merge, OOC_X86_SSA__Instr jump, OOC_X86_SSA__Designator designator, OOC_X86_SSA__Result value) {
              register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
              OOC_X86_SSA__Instr gate;
              OOC_X86_SSA__Opnd opnd;
              OOC_INT32 i;

              i0 = (OOC_INT32)designator;
              i1 = (OOC_INT32)merge;
              i0 = (OOC_INT32)OOC_X86_Destore__Transform_PropagateInstr_PropagateValue_GetDesignatorGate((OOC_X86_SSA__Block)i1, (OOC_X86_SSA__Designator)i0);
              gate = (OOC_X86_SSA__Instr)i0;
              i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 3482));
              opnd = (OOC_X86_SSA__Opnd)i2;
              i = 0;
              i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3523))+56);
              i3 = _check_pointer(i3, 3529);
              i4 = OOC_ARRAY_LENGTH(i3, 0);
              i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(0, i4, OOC_UINT32, 3529))*4);
              i4 = (OOC_INT32)jump;
              i3 = i3!=i4;
              if (!i3) goto l9;
              i3=0;
l4_loop:
              i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 3568))+4);
              opnd = (OOC_X86_SSA__Opnd)i2;
              i3 = i3+1;
              i = i3;
              i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3523))+56);
              i5 = _check_pointer(i5, 3529);
              i6 = OOC_ARRAY_LENGTH(i5, 0);
              i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i3, i6, OOC_UINT32, 3529))*4);
              i5 = i5!=i4;
              if (i5) goto l4_loop;
l9:
              i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 3620));
              i4 = (OOC_INT32)undefValue;
              i3 = i3==i4;
              if (i3) goto l12;
              i0 = (OOC_INT32)value;
              OOC_X86_SSA__OpndDesc_ReplaceArg((OOC_X86_SSA__Opnd)i2, (OOC_X86_SSA__Result)i0);
              goto l16;
l12:
              i3 = (OOC_INT32)value;
              OOC_X86_SSA__OpndDesc_ReplaceArg((OOC_X86_SSA__Opnd)i2, (OOC_X86_SSA__Result)i3);
              i2 = *(OOC_INT32*)((_check_pointer(i0, 3849))+44);
              *(OOC_INT32*)((_check_pointer(i0, 3849))+44) = (i2+1);
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3898))+56);
              i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 3904)), 0);
              i2 = *(OOC_INT32*)((_check_pointer(i0, 3879))+44);
              i1 = i2==i1;
              if (!i1) goto l16;
              i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 3953));
              i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 3962));
              i1 = *(OOC_INT8*)((_check_pointer(i1, 3966))+12);
              i1 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResult((OOC_X86_SSA__Instr)i0, i1);
              OOC_X86_Destore__Transform_AddToWorklist((OOC_X86_SSA__Instr)i0);
l16:
              return;
              ;
            }

            
            void OOC_X86_Destore__Transform_PropagateInstr_PropagateValue_MergeLoopValue(OOC_X86_SSA__Block loopStart, OOC_INT32 pathIndex, OOC_X86_SSA__Designator designator, OOC_X86_SSA__Result value) {
              register OOC_INT32 i0,i1,i2,i3;
              OOC_X86_SSA__GateInstr gate;
              OOC_X86_SSA__Opnd opnd;
              OOC_X86_Destore__MemAccess memAccess;

              i0 = (OOC_INT32)designator;
              i1 = (OOC_INT32)loopStart;
              i0 = (OOC_INT32)OOC_X86_Destore__Transform_PropagateInstr_PropagateValue_GetDesignatorGate((OOC_X86_SSA__Block)i1, (OOC_X86_SSA__Designator)i0);
              gate = (OOC_X86_SSA__GateInstr)i0;
              i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4487));
              opnd = (OOC_X86_SSA__Opnd)i1;
              i2 = pathIndex;
              i3 = i2!=0;
              if (!i3) goto l9;
l4_loop:
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4557))+4);
              opnd = (OOC_X86_SSA__Opnd)i1;
              i2 = i2-1;
              pathIndex = i2;
              i3 = i2!=0;
              if (i3) goto l4_loop;
l9:
              i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 4617));
              i3 = (OOC_INT32)undefValue;
              i2 = i2==i3;
              if (i2) goto l12;
              i0 = (OOC_INT32)value;
              OOC_X86_SSA__OpndDesc_ReplaceArg((OOC_X86_SSA__Opnd)i1, (OOC_X86_SSA__Result)i0);
              goto l16;
l12:
              i2 = (OOC_INT32)value;
              OOC_X86_SSA__OpndDesc_ReplaceArg((OOC_X86_SSA__Opnd)i1, (OOC_X86_SSA__Result)i2);
              i1 = *(OOC_INT32*)((_check_pointer(i0, 4843))+44);
              *(OOC_INT32*)((_check_pointer(i0, 4843))+44) = (i1+1);
              i1 = *(OOC_INT32*)((_check_pointer(i0, 4873))+44);
              i1 = i1==1;
              if (!i1) goto l16;
              i1 = (OOC_INT32)gateToInstr;
              i1 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i1, (Object__Object)i0);
              memAccess = (OOC_X86_Destore__MemAccess)i1;
              i1 = *(OOC_INT8*)((_check_pointer(i1, 5008))+8);
              i1 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResult((OOC_X86_SSA__Instr)i0, i1);
              OOC_X86_Destore__Transform_AddToWorklist((OOC_X86_SSA__Instr)i0);
l16:
              return;
              ;
            }


          i0 = (OOC_INT32)instr;
          i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AfterList((OOC_X86_SSA__Instr)i0, 1);
          i1 = (OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG(i0)), OOC_X86_SSA__IterInstrAfterListDesc_Next);
          i2 = OOC_TBCALL(i1,OOC_X86_SSA__IterInstrAfterListDesc_Next)((OOC_X86_SSA__IterInstrAfterList)i0, (void*)(OOC_INT32)&dep);
          if (!i2) goto l41;
l3_loop:
          i2 = (OOC_INT32)dep;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 5259))+12);
          afterInstr = (OOC_X86_SSA__Instr)i2;
          i3 = *(OOC_INT8*)((_check_pointer(i2, 5292))+20);
          switch (i3) {
          case 24:
            i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 5374))+28);
            i4 = (OOC_INT32)designator;
            i3 = OOC_X86_Aliasing__DesignatorAlias((OOC_X86_SSA__Designator)i3, (OOC_X86_SSA__Designator)i4);
            switch (i3) {
            case 0:
              i3 = (OOC_INT32)value;
              OOC_X86_Destore__Transform_PropagateInstr_PropagateValue((OOC_X86_SSA__Designator)i4, (OOC_X86_SSA__Result)i3, (OOC_X86_SSA__Instr)i2);
              goto l36;
            case 1:
              i3 = (OOC_INT32)value;
              OOC_X86_Destore__Transform_PropagateInstr_PropagateValue((OOC_X86_SSA__Designator)i4, (OOC_X86_SSA__Result)i3, (OOC_X86_SSA__Instr)i2);
              i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 5625))+4);
              OOC_X86_SSA__ResultDesc_ReplaceUses((OOC_X86_SSA__Result)i4, (OOC_X86_SSA__Result)i3);
              OOC_X86_SSA__InstrDesc_TransferDeps((OOC_X86_SSA__Instr)i2);
              OOC_X86_SSA__InstrDesc_Delete((OOC_X86_SSA__Instr)i2);
              goto l36;
            default:
              goto l36;
            }
            /* goto: unreachable */
          case 25:
            i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 5900))+28);
            i4 = (OOC_INT32)designator;
            i3 = OOC_X86_Aliasing__DesignatorAlias((OOC_X86_SSA__Designator)i3, (OOC_X86_SSA__Designator)i4);
            switch (i3) {
            case 0:
              i3 = (OOC_INT32)value;
              OOC_X86_Destore__Transform_PropagateInstr_PropagateValue((OOC_X86_SSA__Designator)i4, (OOC_X86_SSA__Result)i3, (OOC_X86_SSA__Instr)i2);
              goto l36;
            default:
              goto l36;
            }
            /* goto: unreachable */
          case 20:
            goto l36;
          case 37:
            i3 = (OOC_INT32)OOC_X86_SSA__InstrDesc_GetAfterInstr((OOC_X86_SSA__Instr)i2, 0);
            merge = (OOC_X86_SSA__Instr)i3;
            i4 = (OOC_INT32)value;
            i5 = (OOC_INT32)designator;
            OOC_X86_Destore__Transform_PropagateInstr_PropagateValue_MergeValue((OOC_X86_SSA__MergeInstr)(_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 6311)))), &_td_OOC_X86_SSA__MergeInstrDesc, 6311)), (OOC_X86_SSA__Instr)i2, (OOC_X86_SSA__Designator)i5, (OOC_X86_SSA__Result)i4);
            goto l36;
          case 35:
            i3 = (OOC_INT32)value;
            i4 = (OOC_INT32)designator;
            OOC_X86_Destore__Transform_PropagateInstr_PropagateValue((OOC_X86_SSA__Designator)i4, (OOC_X86_SSA__Result)i3, (OOC_X86_SSA__Instr)i2);
            goto l36;
          case 40:
            i3 = (OOC_INT32)value;
            i4 = (OOC_INT32)designator;
            OOC_X86_Destore__Transform_PropagateInstr_PropagateValue_MergeLoopValue((OOC_X86_SSA__Block)(_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 6501)))), &_td_OOC_X86_SSA__BlockDesc, 6501)), 0, (OOC_X86_SSA__Designator)i4, (OOC_X86_SSA__Result)i3);
            goto l36;
          case 42:
            i2 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AfterList((OOC_X86_SSA__Instr)i2, (-1));
            i3 = (OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG(i2)), OOC_X86_SSA__IterInstrAfterListDesc_Next);
            i4 = OOC_TBCALL(i3,OOC_X86_SSA__IterInstrAfterListDesc_Next)((OOC_X86_SSA__IterInstrAfterList)i2, (void*)(OOC_INT32)&dep);
            if (!i4) goto l36;
l22_loop:
            i4 = (OOC_INT32)dep;
            i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 6629))+12);
            i5 = *(OOC_INT8*)((_check_pointer(i5, 6635))+20);
            switch (i5) {
            case 41:
              i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 6703))+12);
              i5 = (OOC_INT32)value;
              i6 = (OOC_INT32)designator;
              i7 = (OOC_INT32)afterInstr;
              OOC_X86_Destore__Transform_PropagateInstr_PropagateValue_MergeValue((OOC_X86_SSA__MergeInstr)(_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 6712)))), &_td_OOC_X86_SSA__MergeInstrDesc, 6712)), (OOC_X86_SSA__Instr)i7, (OOC_X86_SSA__Designator)i6, (OOC_X86_SSA__Result)i5);
              goto l26;
            default:
              i4 = (OOC_INT32)afterInstr;
              i5 = (OOC_INT32)value;
              i6 = (OOC_INT32)designator;
              OOC_X86_Destore__Transform_PropagateInstr_PropagateValue((OOC_X86_SSA__Designator)i6, (OOC_X86_SSA__Result)i5, (OOC_X86_SSA__Instr)i4);
              goto l26;
            }
l26:
            i4 = OOC_TBCALL(i3,OOC_X86_SSA__IterInstrAfterListDesc_Next)((OOC_X86_SSA__IterInstrAfterList)i2, (void*)(OOC_INT32)&dep);
            if (i4) goto l22_loop;
            goto l36;
          case 43:
            i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 6970)))), &_td_OOC_X86_SSA__LoopBackedgeInstrDesc, 6970)), 6988))+48);
            i3 = (OOC_INT32)value;
            i4 = (OOC_INT32)designator;
            OOC_X86_Destore__Transform_PropagateInstr_PropagateValue_MergeLoopValue((OOC_X86_SSA__Block)i2, 1, (OOC_X86_SSA__Designator)i4, (OOC_X86_SSA__Result)i3);
            goto l36;
          case 19:
            goto l36;
          case 18:
            goto l36;
          default:
            _failed_case(i3, 5277);
            goto l36;
          }
l36:
          i2 = OOC_TBCALL(i1,OOC_X86_SSA__IterInstrAfterListDesc_Next)((OOC_X86_SSA__IterInstrAfterList)i0, (void*)(OOC_INT32)&dep);
          if (i2) goto l3_loop;
l41:
          return;
          ;
        }

        
        OOC_CHAR8 OOC_X86_Destore__Transform_PropagateInstr_FixedDesignator(OOC_X86_SSA__Designator designator) {
          register OOC_INT32 i0,i1;

          i0 = (OOC_INT32)designator;
          i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 7362)), 0);
          i1 = i1==1;
          if (i1) goto l3;
          i0=0u;
          goto l4;
l3:
          i0 = _check_pointer(i0, 7383);
          i1 = OOC_ARRAY_LENGTH(i0, 0);
          i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 7383))*4);
          i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7387)))), &_td_OOC_X86_SSA__VarDesc);
          
l4:
          return i0;
          ;
        }


      i0 = (OOC_INT32)propInstr;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7459))+40);
      i1 = i1==(OOC_INT32)0;
      if (!i1) goto l16;
      *(OOC_INT32*)((_check_pointer(i0, 7494))+40) = i0;
      i1 = *(OOC_INT8*)((_check_pointer(i0, 7570))+20);
      switch (i1) {
      case 17:
      case 22:
      case 19:
      case 18:
      case 35:
      case 37:
      case 36:
      case 40:
      case 42:
      case 43:
      case 41:
      case 20:
      case 26:
        goto l16;
      case 24:
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7818))+28);
        i1 = OOC_X86_Destore__Transform_PropagateInstr_FixedDesignator((OOC_X86_SSA__Designator)i1);
        if (!i1) goto l16;
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7921))+4);
        i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7872))+28);
        OOC_X86_Destore__Transform_PropagateInstr_PropagateValue((OOC_X86_SSA__Designator)i2, (OOC_X86_SSA__Result)i1, (OOC_X86_SSA__Instr)i0);
        goto l16;
      case 25:
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8016))+28);
        i1 = OOC_X86_Destore__Transform_PropagateInstr_FixedDesignator((OOC_X86_SSA__Designator)i1);
        if (!i1) goto l16;
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 8119));
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 8128))+4);
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 8137));
        i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8070))+28);
        OOC_X86_Destore__Transform_PropagateInstr_PropagateValue((OOC_X86_SSA__Designator)i2, (OOC_X86_SSA__Result)i1, (OOC_X86_SSA__Instr)i0);
        goto l16;
      case 39:
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8301))+16);
        i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8279))+4);
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8232))+28);
        OOC_X86_Destore__Transform_PropagateInstr_PropagateValue((OOC_X86_SSA__Designator)i0, (OOC_X86_SSA__Result)i2, (OOC_X86_SSA__Instr)i1);
        goto l16;
      default:
        _failed_case(i1, 7556);
        goto l16;
      }
l16:
      return;
      ;
    }

    
    OOC_CHAR8 OOC_X86_Destore__Transform_VisibleEffect(OOC_X86_SSA__Instr store, OOC_X86_SSA__Instr set) {
      register OOC_INT32 i0,i1,i2;
      OOC_X86_SSA__Dep dep;
      auto OOC_CHAR8 OOC_X86_Destore__Transform_VisibleEffect_ReadingUse(OOC_X86_SSA__Instr instr);
        
        OOC_CHAR8 OOC_X86_Destore__Transform_VisibleEffect_ReadingUse(OOC_X86_SSA__Instr instr) {
          register OOC_INT32 i0,i1,i2,i3;
          auto OOC_SymbolTable__VarDecl OOC_X86_Destore__Transform_VisibleEffect_ReadingUse_GetVar(OOC_X86_SSA__Designator designator);
          auto OOC_CHAR8 OOC_X86_Destore__Transform_VisibleEffect_ReadingUse_ExternalVisibility(OOC_SymbolTable__VarDecl var);
            
            OOC_SymbolTable__VarDecl OOC_X86_Destore__Transform_VisibleEffect_ReadingUse_GetVar(OOC_X86_SSA__Designator designator) {
              register OOC_INT32 i0,i1,i2;

              i0 = (OOC_INT32)designator;
              i1 = _check_pointer(i0, 9060);
              i2 = OOC_ARRAY_LENGTH(i1, 0);
              i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 9060))*4);
              i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9064)))), &_td_OOC_X86_SSA__VarDesc);
              if (i1) goto l3;
              return (OOC_SymbolTable__VarDecl)0;
              goto l4;
l3:
              i0 = _check_pointer(i0, 9108);
              i1 = OOC_ARRAY_LENGTH(i0, 0);
              i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 9108))*4);
              i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9114)))), &_td_OOC_X86_SSA__VarDesc, 9114)), 9118));
              return (OOC_SymbolTable__VarDecl)i0;
l4:
              _failed_function(8802); return 0;
              ;
            }

            
            OOC_CHAR8 OOC_X86_Destore__Transform_VisibleEffect_ReadingUse_ExternalVisibility(OOC_SymbolTable__VarDecl var) {
              register OOC_INT32 i0,i1;

              i0 = (OOC_INT32)var;
              i1 = i0==(OOC_INT32)0;
              if (i1) goto l3;
              i1 = *(OOC_UINT8*)((_check_pointer(i0, 9496))+59);
              
              goto l5;
l3:
              i1=1u;
l5:
              if (i1) goto l7;
              i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9563)))), OOC_SymbolTable__ItemDesc_Procedure)),OOC_SymbolTable__ItemDesc_Procedure)((OOC_SymbolTable__Item)i0);
              i1 = (OOC_INT32)fctBlock;
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 9587))+56);
              i0 = i0!=i1;
              
              goto l8;
l7:
              i0=1u;
l8:
              return i0;
              ;
            }


          i0 = (OOC_INT32)instr;
          i1 = *(OOC_INT8*)((_check_pointer(i0, 9693))+20);
          switch (i1) {
          case 24:
            i1 = (OOC_INT32)set;
            i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9786))+28);
            i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 9768))+28);
            i1 = OOC_X86_Aliasing__DesignatorAlias((OOC_X86_SSA__Designator)i1, (OOC_X86_SSA__Designator)i2);
            i1 = i1!=0;
            if (i1) goto l5;
            i1 = (OOC_INT32)set;
            i0 = OOC_X86_Destore__Transform_VisibleEffect((OOC_X86_SSA__Instr)i0, (OOC_X86_SSA__Instr)i1);
            return i0;
            goto l26;
l5:
            return 1u;
            goto l26;
          case 25:
            i1 = (OOC_INT32)set;
            i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10101))+28);
            i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 10083))+28);
            i1 = OOC_X86_Aliasing__DesignatorAlias((OOC_X86_SSA__Designator)i1, (OOC_X86_SSA__Designator)i2);
            i2 = i1==1;
            if (i2) goto l14;
            i1 = i1!=0;
            if (i1) goto l12;
            i1 = (OOC_INT32)set;
            i0 = OOC_X86_Destore__Transform_VisibleEffect((OOC_X86_SSA__Instr)i0, (OOC_X86_SSA__Instr)i1);
            return i0;
            goto l26;
l12:
            return 1u;
            goto l26;
l14:
            return 0u;
            goto l26;
          case 19:
          case 18:
            i0 = (OOC_INT32)set;
            i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11054))+28);
            i0 = (OOC_INT32)OOC_X86_Destore__Transform_VisibleEffect_ReadingUse_GetVar((OOC_X86_SSA__Designator)i0);
            i0 = OOC_X86_Destore__Transform_VisibleEffect_ReadingUse_ExternalVisibility((OOC_SymbolTable__VarDecl)i0);
            return i0;
            goto l26;
          case 35:
          case 36:
          case 40:
          case 41:
            i1 = (OOC_INT32)set;
            i0 = OOC_X86_Destore__Transform_VisibleEffect((OOC_X86_SSA__Instr)i0, (OOC_X86_SSA__Instr)i1);
            return i0;
            goto l26;
          case 43:
            i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11230)))), &_td_OOC_X86_SSA__LoopBackedgeInstrDesc, 11230)), 11248))+48);
            i1 = (OOC_INT32)set;
            i0 = OOC_X86_Destore__Transform_VisibleEffect((OOC_X86_SSA__Instr)i0, (OOC_X86_SSA__Instr)i1);
            return i0;
            goto l26;
          case 37:
          case 42:
            i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_MergingTarget((OOC_X86_SSA__Instr)i0);
            i0 = OOC_X86_Destore__Transform_VisibleEffect_ReadingUse((OOC_X86_SSA__Instr)i0);
            return i0;
            goto l26;
          case 20:
            i1 = (OOC_INT32)set;
            i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 11396));
            i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 11405));
            i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11414))+28);
            i2 = OOC_X86_Destore__Transform_AccessedByCall((OOC_X86_SSA__Result)i2, (OOC_X86_SSA__Designator)i3, 0);
            if (i2) goto l23;
            i0 = OOC_X86_Destore__Transform_VisibleEffect((OOC_X86_SSA__Instr)i0, (OOC_X86_SSA__Instr)i1);
            return i0;
            goto l26;
l23:
            return 1u;
            goto l26;
          default:
            _failed_case(i1, 9683);
            goto l26;
          }
l26:
          _failed_function(8702); return 0;
          ;
        }


      i0 = (OOC_INT32)store;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11722))+40);
      i2 = (OOC_INT32)set;
      i1 = i1!=i2;
      if (i1) goto l3;
      i0 = *(OOC_INT32*)((_check_pointer(i0, 12213))+44);
      return (i0!=0);
      goto l32;
l3:
      *(OOC_INT32*)((_check_pointer(i0, 11753))+40) = i2;
      *(OOC_INT32*)((_check_pointer(i0, 11780))+44) = 0;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11852))+36);
      dep = (OOC_X86_SSA__Dep)i0;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l6;
      i0=0u;
      goto l12;
l6:
      i1 = *(OOC_INT8*)((_check_pointer(i0, 11897))+8);
      i1 = i1!=1;
      if (i1) goto l9;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11965))+12);
      i0 = OOC_X86_Destore__Transform_VisibleEffect_ReadingUse((OOC_X86_SSA__Instr)i0);
      i0 = !i0;
      
      goto l12;
l9:
      i0=1u;
l12:
      if (!i0) goto l27;
l14_loop:
      i0 = (OOC_INT32)dep;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11997))+16);
      dep = (OOC_X86_SSA__Dep)i0;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l17;
      i0=0u;
      goto l23;
l17:
      i1 = *(OOC_INT8*)((_check_pointer(i0, 11897))+8);
      i1 = i1!=1;
      if (i1) goto l20;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11965))+12);
      i0 = OOC_X86_Destore__Transform_VisibleEffect_ReadingUse((OOC_X86_SSA__Instr)i0);
      i0 = !i0;
      
      goto l23;
l20:
      i0=1u;
l23:
      if (i0) goto l14_loop;
l27:
      i0 = (OOC_INT32)dep;
      i0 = i0!=(OOC_INT32)0;
      if (i0) goto l30;
      i0 = (OOC_INT32)store;
      *(OOC_INT32*)((_check_pointer(i0, 12130))+44) = 0;
      return 0u;
      goto l32;
l30:
      i0 = (OOC_INT32)store;
      *(OOC_INT32*)((_check_pointer(i0, 12065))+44) = 1;
      return 1u;
l32:
      _failed_function(8373); return 0;
      ;
    }

    
    void OOC_X86_Destore__Transform_AddDesignatorGatetoWorklist(OOC_X86_SSA__Block b) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_X86_SSA__Instr instr;

      i0 = (OOC_INT32)b;
      i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_Instructions((OOC_X86_SSA__Block)i0);
      i1 = (OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG(i0)), OOC_X86_SSA__IterBlockInstructionsDesc_Next);
      i2 = OOC_TBCALL(i1,OOC_X86_SSA__IterBlockInstructionsDesc_Next)((OOC_X86_SSA__IterBlockInstructions)i0, (void*)(OOC_INT32)&instr);
      if (!i2) goto l15;
l3_loop:
      i2 = (OOC_INT32)instr;
      i3 = *(OOC_INT8*)((_check_pointer(i2, 12411))+20);
      i3 = i3==39;
      if (i3) goto l9;
      i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 12497)))), &_td_OOC_X86_SSA__BlockDesc);
      if (!i3) goto l10;
      OOC_X86_Destore__Transform_AddDesignatorGatetoWorklist((OOC_X86_SSA__Block)(_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 12560)))), &_td_OOC_X86_SSA__BlockDesc, 12560)));
      goto l10;
l9:
      OOC_X86_Destore__Transform_AddToWorklist((OOC_X86_SSA__Instr)i2);
l10:
      i2 = OOC_TBCALL(i1,OOC_X86_SSA__IterBlockInstructionsDesc_Next)((OOC_X86_SSA__IterBlockInstructions)i0, (void*)(OOC_INT32)&instr);
      if (i2) goto l3_loop;
l15:
      return;
      ;
    }

    
    void OOC_X86_Destore__Transform_ReplaceUses(OOC_X86_SSA__Result old, OOC_X86_SSA__Result _new, OOC_CHAR8 eliminateLoopEnd) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5;
      OOC_X86_SSA__Opnd use;

      i0 = (OOC_INT32)old;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12758))+8);
      i1 = i1!=(OOC_INT32)0;
      if (!i1) goto l30;
      i1 = (OOC_INT32)_new;
      i2 = eliminateLoopEnd;
l3_loop:
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12795))+8);
      use = (OOC_X86_SSA__Opnd)i3;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 12860))+8);
      i4 = *(OOC_INT8*)((_check_pointer(i4, 12866))+20);
      i4 = i4==39;
      if (i4) goto l6;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 12913))+8);
      i4 = *(OOC_INT8*)((_check_pointer(i4, 12919))+20);
      i4 = i4==38;
      
      goto l8;
l6:
      i4=1u;
l8:
      if (i4) goto l10;
      i4=0u;
      goto l12;
l10:
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 12955))+8);
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12967))+4);
      i4 = i4!=i5;
      
l12:
      if (!i4) goto l14;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 13007))+8);
      OOC_X86_Destore__Transform_AddToWorklist((OOC_X86_SSA__Instr)i4);
l14:
      OOC_X86_SSA__OpndDesc_ReplaceArg((OOC_X86_SSA__Opnd)i3, (OOC_X86_SSA__Result)i1);
      if (i2) goto l17;
      i4=0u;
      goto l19;
l17:
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 13103))+8);
      i4 = OOC_X86_SSA__InstrDesc_IsLoopEndGate((OOC_X86_SSA__Instr)i4);
      
l19:
      if (i4) goto l21;
      i4=0u;
      goto l23;
l21:
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 13142))+8);
      i4 = OOC_X86_SSA__InstrDesc_AllOpndsSameValue((OOC_X86_SSA__Instr)i4);
      
l23:
      if (!i4) goto l25;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 13575))+8);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 13581))+4);
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 13597));
      OOC_X86_Destore__Transform_ReplaceUses((OOC_X86_SSA__Result)i4, (OOC_X86_SSA__Result)i3, 0u);
l25:
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12758))+8);
      i3 = i3!=(OOC_INT32)0;
      if (i3) goto l3_loop;
l30:
      return;
      ;
    }

    
    void OOC_X86_Destore__Transform_PromoteDesignatorGate(OOC_X86_SSA__GateInstr instr) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_X86_SSA__Opnd opnd;

      i0 = (OOC_INT32)instr;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13828))+4);
      i1 = i1==(OOC_INT32)0;
      if (i1) goto l42;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14012))+48);
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14019)))), &_td_OOC_X86_SSA__LoopStartInstrDesc);
      if (i1) goto l33;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14373))+48);
      i1 = *(OOC_INT8*)((_check_pointer(i1, 14379))+20);
      i1 = i1==41;
      if (i1) goto l31;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 14719));
      opnd = (OOC_X86_SSA__Opnd)i1;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14749))+4);
      i2 = i2!=(OOC_INT32)0;
      if (i2) goto l9;
      i2=0u;
      goto l11;
l9:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14773))+4);
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 14793));
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 14782));
      i2 = i2==i3;
      
l11:
      if (!i2) goto l23;
l14_loop:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14824))+4);
      opnd = (OOC_X86_SSA__Opnd)i1;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14749))+4);
      i2 = i2!=(OOC_INT32)0;
      if (i2) goto l17;
      i2=0u;
      goto l19;
l17:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14773))+4);
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 14793));
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 14782));
      i2 = i2==i3;
      
l19:
      if (i2) goto l14_loop;
l23:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14864))+4);
      i1 = i1==(OOC_INT32)0;
      if (i1) goto l29;
      i1 = *(OOC_INT8*)((_check_pointer(i0, 15036))+20);
      i1 = i1==39;
      if (!i1) goto l43;
      OOC_X86_SSA__InstrDesc_DesignatorGateToGate((OOC_X86_SSA__Instr)i0);
      goto l43;
l29:
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 14967));
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14949))+4);
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 14976));
      OOC_X86_Destore__Transform_ReplaceUses((OOC_X86_SSA__Result)i2, (OOC_X86_SSA__Result)i1, 0u);
      OOC_X86_SSA__InstrDesc_Delete((OOC_X86_SSA__Instr)i0);
      goto l43;
l31:
      OOC_X86_SSA__InstrDesc_DesignatorGateToGate((OOC_X86_SSA__Instr)i0);
      goto l43;
l33:
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 14062));
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14071))+4);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14092))+4);
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 14080));
      i1 = i1==i2;
      if (i1) goto l39;
      i1 = *(OOC_INT8*)((_check_pointer(i0, 14269))+20);
      i1 = i1==39;
      if (!i1) goto l43;
      OOC_X86_SSA__InstrDesc_DesignatorGateToGate((OOC_X86_SSA__Instr)i0);
      goto l43;
l39:
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 14201));
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14183))+4);
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 14210));
      OOC_X86_Destore__Transform_ReplaceUses((OOC_X86_SSA__Result)i2, (OOC_X86_SSA__Result)i1, 1u);
      OOC_X86_SSA__InstrDesc_Delete((OOC_X86_SSA__Instr)i0);
      goto l43;
l42:
      OOC_X86_SSA__InstrDesc_Delete((OOC_X86_SSA__Instr)i0);
l43:
      return;
      ;
    }

    
    void OOC_X86_Destore__Transform_AddMemoryDeps(OOC_X86_SSA__Instr instr) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_X86_SSA__Dep dep;

      i0 = (OOC_INT32)instr;
      i1 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AfterList((OOC_X86_SSA__Instr)i0, 1);
      i2 = (OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG(i1)), OOC_X86_SSA__IterInstrAfterListDesc_Next);
      i3 = OOC_TBCALL(i2,OOC_X86_SSA__IterInstrAfterListDesc_Next)((OOC_X86_SSA__IterInstrAfterList)i1, (void*)(OOC_INT32)&dep);
      if (!i3) goto l7;
l2_loop:
      i3 = (OOC_INT32)dep;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 15318))+12);
      OOC_X86_Destore__Transform_AddToWorklist((OOC_X86_SSA__Instr)i3);
      i3 = OOC_TBCALL(i2,OOC_X86_SSA__IterInstrAfterListDesc_Next)((OOC_X86_SSA__IterInstrAfterList)i1, (void*)(OOC_INT32)&dep);
      if (i3) goto l2_loop;
l7:
      i1 = *(OOC_INT8*)((_check_pointer(i0, 15353))+20);
      i1 = i1==37;
      if (!i1) goto l17;
      i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AfterList((OOC_X86_SSA__Instr)i0, 0);
      i1 = (OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG(i0)), OOC_X86_SSA__IterInstrAfterListDesc_Next);
      i2 = OOC_TBCALL(i1,OOC_X86_SSA__IterInstrAfterListDesc_Next)((OOC_X86_SSA__IterInstrAfterList)i0, (void*)(OOC_INT32)&dep);
      if (!i2) goto l17;
l11_loop:
      i2 = (OOC_INT32)dep;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 15455))+12);
      OOC_X86_Destore__Transform_AddToWorklist((OOC_X86_SSA__Instr)i2);
      i2 = OOC_TBCALL(i1,OOC_X86_SSA__IterInstrAfterListDesc_Next)((OOC_X86_SSA__IterInstrAfterList)i0, (void*)(OOC_INT32)&dep);
      if (i2) goto l11_loop;
l17:
      return;
      ;
    }

    
    void OOC_X86_Destore__Transform_FixLoopStart(OOC_X86_SSA__GateInstr gate) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
      OOC_X86_SSA__LoopStartInstr loopStart;
      OOC_X86_Destore__MemAccess memAccess;
      OOC_X86_SSA__Instr get;
      OOC_X86_SSA__Dep dep;

      i0 = (OOC_INT32)gate;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15699))+48);
      i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15708)))), &_td_OOC_X86_SSA__LoopStartInstrDesc, 15708);
      loopStart = (OOC_X86_SSA__LoopStartInstr)i1;
      i2 = (OOC_INT32)gateToInstr;
      i2 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i2, (Object__Object)i0);
      memAccess = (OOC_X86_Destore__MemAccess)i2;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 15822))+4);
      i4 = (OOC_INT32)fctBlock;
      i3 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr1((OOC_X86_SSA__Block)i4, 24, (OOC_X86_SSA__Result)i3);
      get = (OOC_X86_SSA__Instr)i3;
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 15866));
      OOC_X86_SSA__InstrDesc_SetDesignator((OOC_X86_SSA__Instr)i3, (OOC_X86_SSA__Designator)i4);
      i4 = (OOC_INT32)OOC_X86_SSA__InstrDesc_BeforeList((OOC_X86_SSA__Instr)i1, 1);
      i5 = (OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG(i4)), OOC_X86_SSA__IterInstrBeforeListDesc_Next);
      i6 = OOC_TBCALL(i5,OOC_X86_SSA__IterInstrBeforeListDesc_Next)((OOC_X86_SSA__IterInstrBeforeList)i4, (void*)(OOC_INT32)&dep);
      if (!i6) goto l8;
l3_loop:
      i6 = (OOC_INT32)dep;
      i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i6, 15969));
      OOC_X86_SSA__InstrDesc_AddDep((OOC_X86_SSA__Instr)i3, 1, (OOC_X86_SSA__Instr)i6);
      i6 = (OOC_INT32)dep;
      OOC_X86_SSA__DepDesc_DeleteDep((OOC_X86_SSA__Dep)i6);
      i6 = OOC_TBCALL(i5,OOC_X86_SSA__IterInstrBeforeListDesc_Next)((OOC_X86_SSA__IterInstrBeforeList)i4, (void*)(OOC_INT32)&dep);
      if (i6) goto l3_loop;
l8:
      OOC_X86_SSA__InstrDesc_AddDep((OOC_X86_SSA__Instr)i1, 1, (OOC_X86_SSA__Instr)i3);
      i1 = *(OOC_INT8*)((_check_pointer(i2, 16111))+8);
      i1 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResult((OOC_X86_SSA__Instr)i3, i1);
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 16067));
      OOC_X86_SSA__OpndDesc_ReplaceArg((OOC_X86_SSA__Opnd)i0, (OOC_X86_SSA__Result)i1);
      return;
      ;
    }


  worklist = (OOC_X86_Destore__Worklist)(OOC_INT32)0;
  i0 = (OOC_INT32)fctBlock;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16201))+60);
  i1 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResult((OOC_X86_SSA__Instr)i1, 0);
  undefValue = (OOC_X86_SSA__Result)i1;
  OOC_X86_SSA__BlockDesc_SetMarkers((OOC_X86_SSA__Block)i0, (OOC_X86_SSA__Node)(OOC_INT32)0, 0);
  i1 = (OOC_INT32)RT0__NewObject(_td__qtd1.baseTypes[0]);
  ADT_Dictionary__DictionaryDesc_INIT((ADT_Dictionary__Dictionary)i1);
  gateToInstr = (ADT_Dictionary__Dictionary)i1;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16364))+60);
  OOC_X86_Destore__Transform_AddToWorklist((OOC_X86_SSA__Instr)i0);
  i0 = (OOC_INT32)worklist;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l8;
l3_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16426))+4);
  instr = (OOC_X86_SSA__Instr)i1;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 16460));
  worklist = (OOC_X86_Destore__Worklist)i0;
  OOC_X86_Destore__Transform_PropagateInstr((OOC_X86_SSA__Instr)i1);
  i0 = (OOC_INT32)instr;
  OOC_X86_Destore__Transform_AddMemoryDeps((OOC_X86_SSA__Instr)i0);
  i0 = (OOC_INT32)worklist;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l3_loop;
l8:
  i0 = (OOC_INT32)undefValue;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16878))+8);
  i0 = i0!=(OOC_INT32)0;
  if (!i0) goto l25;
l11_loop:
  i0 = (OOC_INT32)undefValue;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16921))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 16929))+8);
  i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16938)))), &_td_OOC_X86_SSA__GateInstrDesc, 16938);
  gate = (OOC_X86_SSA__GateInstr)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 16965))+48);
  i2 = *(OOC_INT8*)((_check_pointer(i2, 16971))+20);
  switch (i2) {
  case 40:
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17041))+8);
    i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 17019));
    i0 = i2==i0;
    if (i0) goto l16;
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 17450));
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 17433))+4);
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 17459));
    OOC_X86_Destore__Transform_ReplaceUses((OOC_X86_SSA__Result)i1, (OOC_X86_SSA__Result)i0, 1u);
    i0 = (OOC_INT32)gate;
    OOC_X86_SSA__InstrDesc_Delete((OOC_X86_SSA__Instr)i0);
    goto l20;
l16:
    OOC_X86_Destore__Transform_FixLoopStart((OOC_X86_SSA__GateInstr)i1);
    goto l20;
  case 36:
  case 35:
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 17555))+4);
    _assert((i0==(OOC_INT32)0), 127, 17544);
    OOC_X86_SSA__InstrDesc_Delete((OOC_X86_SSA__Instr)i1);
    goto l20;
  default:
    _failed_case(i2, 16956);
    goto l20;
  }
l20:
  i0 = (OOC_INT32)undefValue;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16878))+8);
  i0 = i0!=(OOC_INT32)0;
  if (i0) goto l11_loop;
l25:
  i0 = (OOC_INT32)fctBlock;
  OOC_X86_SSA__BlockDesc_SetMarkers((OOC_X86_SSA__Block)i0, (OOC_X86_SSA__Node)(OOC_INT32)0, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17823))+60);
  OOC_X86_Destore__Transform_AddToWorklist((OOC_X86_SSA__Instr)i0);
  i0 = (OOC_INT32)worklist;
  i0 = i0!=(OOC_INT32)0;
  if (!i0) goto l40;
l28_loop:
  i0 = (OOC_INT32)worklist;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17885))+4);
  instr = (OOC_X86_SSA__Instr)i1;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 17919));
  worklist = (OOC_X86_Destore__Worklist)i0;
  OOC_X86_Destore__Transform_AddMemoryDeps((OOC_X86_SSA__Instr)i1);
  i0 = (OOC_INT32)instr;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 17969))+20);
  i1 = i1==25;
  if (i1) goto l31;
  i0=0u;
  goto l33;
l31:
  i0 = OOC_X86_Destore__Transform_VisibleEffect((OOC_X86_SSA__Instr)i0, (OOC_X86_SSA__Instr)i0);
  i0 = !i0;
  
l33:
  if (!i0) goto l35;
  i0 = (OOC_INT32)instr;
  OOC_X86_SSA__InstrDesc_TransferDeps((OOC_X86_SSA__Instr)i0);
  OOC_X86_SSA__InstrDesc_Delete((OOC_X86_SSA__Instr)i0);
l35:
  i0 = (OOC_INT32)worklist;
  i0 = i0!=(OOC_INT32)0;
  if (i0) goto l28_loop;
l40:
  i0 = (OOC_INT32)fctBlock;
  OOC_X86_Destore__Transform_AddDesignatorGatetoWorklist((OOC_X86_SSA__Block)i0);
  i0 = (OOC_INT32)worklist;
  i0 = i0!=(OOC_INT32)0;
  if (!i0) goto l51;
l43_loop:
  i0 = (OOC_INT32)worklist;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18258))+4);
  instr = (OOC_X86_SSA__Instr)i1;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 18292));
  worklist = (OOC_X86_Destore__Worklist)i0;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 18314));
  i0 = i0!=(OOC_INT32)0;
  if (!i0) goto l46;
  OOC_X86_Destore__Transform_PromoteDesignatorGate((OOC_X86_SSA__GateInstr)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 18436)))), &_td_OOC_X86_SSA__GateInstrDesc, 18436)));
l46:
  i0 = (OOC_INT32)worklist;
  i0 = i0!=(OOC_INT32)0;
  if (i0) goto l43_loop;
l51:
  i0 = (OOC_INT32)undefValue;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18490))+8);
  _assert((i1==(OOC_INT32)0), 127, 18473);
  OOC_X86_SSA__ResultDesc_DeleteResult((OOC_X86_SSA__Result)i0);
  return;
  ;
}

void OOC_OOC_X86_Destore_init(void) {

  return;
  ;
}

/* --- */
