#include <OOC/X86/Destore.d>
#include <__oo2c.h>
#include <setjmp.h>

void OOC_X86_Destore__MemAccessDesc_INIT(OOC_X86_Destore__MemAccess memAccess, OOC_INT8 type, OOC_X86_SSA__Designator designator, OOC_X86_SSA__Result address) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)memAccess;
  i1 = (OOC_INT32)designator;
  *(OOC_INT32*)(_check_pointer(i0, 605)) = i1;
  i1 = (OOC_INT32)address;
  *(OOC_INT32*)((_check_pointer(i0, 645))+4) = i1;
  i1 = type;
  *(OOC_INT8*)((_check_pointer(i0, 679))+8) = i1;
  return;
  ;
}

void OOC_X86_Destore__Transform(OOC_X86_SSA__FunctionBlock fctBlock) {
  register OOC_INT32 i0,i1,i2;
  OOC_X86_Destore__Worklist worklist;
  ADT_Dictionary__Dictionary inWorklist;
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
      register OOC_INT32 i0,i1,i2;
      OOC_X86_Destore__Worklist entry;

      i0 = (OOC_INT32)instr;
      i1 = (OOC_INT32)inWorklist;
      i1 = ADT_Dictionary__DictionaryDesc_HasKey((ADT_Dictionary__Dictionary)i1, (Object__Object)i0);
      i1 = !i1;
      if (!i1) goto l4;
      i1 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_Destore__Worklist.baseTypes[0]);
      entry = (OOC_X86_Destore__Worklist)i1;
      i2 = (OOC_INT32)worklist;
      *(OOC_INT32*)(_check_pointer(i1, 1497)) = i2;
      *(OOC_INT32*)((_check_pointer(i1, 1529))+4) = i0;
      worklist = (OOC_X86_Destore__Worklist)i1;
      i1 = (OOC_INT32)inWorklist;
      ADT_Dictionary__DictionaryDesc_Set((ADT_Dictionary__Dictionary)i1, (Object__Object)i0, (Object__Object)0);
l4:
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
              i5 = *(OOC_INT8*)((_check_pointer(i4, 2387))+20);
              i5 = i5==51;
              if (i5) goto l6;
              i4=0u;
              goto l8;
l6:
              i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 2466))+28);
              i4 = OOC_X86_SSA__SameDesignator((OOC_X86_SSA__Designator)i3, (OOC_X86_SSA__Designator)i4);
              
l8:
              if (!i4) goto l10;
              i4 = (OOC_INT32)instr;
              return (OOC_X86_SSA__GateInstr)(_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 2513)))), &_td_OOC_X86_SSA__GateInstrDesc, 2513));
l10:
              i4 = OOC_TBCALL(i2,OOC_X86_SSA__IterBlockInstructionsDesc_Next)((OOC_X86_SSA__IterBlockInstructions)i1, (void*)(OOC_INT32)&instr);
              if (i4) goto l3_loop;
l15:
              i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddGate((OOC_X86_SSA__Block)i0, 51);
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
              i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2777)))), &_td_OOC_X86_SSA__GateInstrDesc);
              if (i2) goto l31;
              i2 = *(OOC_INT8*)((_check_pointer(i0, 2898))+20);
              switch (i2) {
              case 34:
                i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2961))+4);
                i2 = *(OOC_INT8*)((_check_pointer(i2, 2972))+12);
                type = i2;
                goto l30;
              case 35:
                i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 3031));
                i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 3040))+4);
                i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 3049));
                i2 = *(OOC_INT8*)((_check_pointer(i2, 3053))+12);
                type = i2;
                goto l30;
              default:
                _failed_case(i2, 2884);
                goto l30;
              }
l30:
              i2 = type;
              _assert((i2!=0), 127, 3089);
              i3 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_Destore__MemAccess.baseTypes[0]);
              i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 3238));
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3178))+28);
              i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 3247));
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
              i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 3665));
              opnd = (OOC_X86_SSA__Opnd)i2;
              i = 0;
              i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3706))+56);
              i3 = _check_pointer(i3, 3712);
              i4 = OOC_ARRAY_LENGTH(i3, 0);
              i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(0, i4, OOC_UINT32, 3712))*4);
              i4 = (OOC_INT32)jump;
              i3 = i3!=i4;
              if (!i3) goto l9;
              i3=0;
l4_loop:
              i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 3751))+4);
              opnd = (OOC_X86_SSA__Opnd)i2;
              i3 = i3+1;
              i = i3;
              i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3706))+56);
              i5 = _check_pointer(i5, 3712);
              i6 = OOC_ARRAY_LENGTH(i5, 0);
              i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i3, i6, OOC_UINT32, 3712))*4);
              i5 = i5!=i4;
              if (i5) goto l4_loop;
l9:
              i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 3803));
              i4 = (OOC_INT32)undefValue;
              i3 = i3==i4;
              if (i3) goto l12;
              i0 = (OOC_INT32)value;
              OOC_X86_SSA__OpndDesc_ReplaceArg((OOC_X86_SSA__Opnd)i2, (OOC_X86_SSA__Result)i0);
              goto l16;
l12:
              i3 = (OOC_INT32)value;
              OOC_X86_SSA__OpndDesc_ReplaceArg((OOC_X86_SSA__Opnd)i2, (OOC_X86_SSA__Result)i3);
              i2 = *(OOC_INT32*)((_check_pointer(i0, 4032))+44);
              *(OOC_INT32*)((_check_pointer(i0, 4032))+44) = (i2+1);
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4081))+56);
              i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 4087)), 0);
              i2 = *(OOC_INT32*)((_check_pointer(i0, 4062))+44);
              i1 = i2==i1;
              if (!i1) goto l16;
              i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4136));
              i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 4145));
              i1 = *(OOC_INT8*)((_check_pointer(i1, 4149))+12);
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
              i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4670));
              opnd = (OOC_X86_SSA__Opnd)i1;
              i2 = pathIndex;
              i3 = i2!=0;
              if (!i3) goto l9;
l4_loop:
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4740))+4);
              opnd = (OOC_X86_SSA__Opnd)i1;
              i2 = i2-1;
              pathIndex = i2;
              i3 = i2!=0;
              if (i3) goto l4_loop;
l9:
              i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 4800));
              i3 = (OOC_INT32)undefValue;
              i2 = i2==i3;
              if (i2) goto l12;
              i0 = (OOC_INT32)value;
              OOC_X86_SSA__OpndDesc_ReplaceArg((OOC_X86_SSA__Opnd)i1, (OOC_X86_SSA__Result)i0);
              goto l16;
l12:
              i2 = (OOC_INT32)value;
              OOC_X86_SSA__OpndDesc_ReplaceArg((OOC_X86_SSA__Opnd)i1, (OOC_X86_SSA__Result)i2);
              i1 = *(OOC_INT32*)((_check_pointer(i0, 5026))+44);
              *(OOC_INT32*)((_check_pointer(i0, 5026))+44) = (i1+1);
              i1 = *(OOC_INT32*)((_check_pointer(i0, 5056))+44);
              i1 = i1==1;
              if (!i1) goto l16;
              i1 = (OOC_INT32)gateToInstr;
              i1 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i1, (Object__Object)i0);
              memAccess = (OOC_X86_Destore__MemAccess)i1;
              i1 = *(OOC_INT8*)((_check_pointer(i1, 5191))+8);
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
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 5442))+12);
          afterInstr = (OOC_X86_SSA__Instr)i2;
          i3 = *(OOC_INT8*)((_check_pointer(i2, 5475))+20);
          switch (i3) {
          case 34:
            i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 5557))+28);
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
              i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 5808))+4);
              OOC_X86_SSA__ResultDesc_ReplaceUses((OOC_X86_SSA__Result)i4, (OOC_X86_SSA__Result)i3);
              OOC_X86_SSA__InstrDesc_TransferDeps((OOC_X86_SSA__Instr)i2);
              OOC_X86_SSA__InstrDesc_Delete((OOC_X86_SSA__Instr)i2);
              goto l36;
            default:
              goto l36;
            }
            /* goto: unreachable */
          case 35:
            i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 6083))+28);
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
          case 29:
            goto l36;
          case 49:
            i3 = (OOC_INT32)OOC_X86_SSA__InstrDesc_GetAfterInstr((OOC_X86_SSA__Instr)i2, 0);
            merge = (OOC_X86_SSA__Instr)i3;
            i4 = (OOC_INT32)value;
            i5 = (OOC_INT32)designator;
            OOC_X86_Destore__Transform_PropagateInstr_PropagateValue_MergeValue((OOC_X86_SSA__MergeInstr)(_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 6494)))), &_td_OOC_X86_SSA__MergeInstrDesc, 6494)), (OOC_X86_SSA__Instr)i2, (OOC_X86_SSA__Designator)i5, (OOC_X86_SSA__Result)i4);
            goto l36;
          case 47:
            i3 = (OOC_INT32)value;
            i4 = (OOC_INT32)designator;
            OOC_X86_Destore__Transform_PropagateInstr_PropagateValue((OOC_X86_SSA__Designator)i4, (OOC_X86_SSA__Result)i3, (OOC_X86_SSA__Instr)i2);
            goto l36;
          case 52:
            i3 = (OOC_INT32)value;
            i4 = (OOC_INT32)designator;
            OOC_X86_Destore__Transform_PropagateInstr_PropagateValue_MergeLoopValue((OOC_X86_SSA__Block)(_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 6684)))), &_td_OOC_X86_SSA__BlockDesc, 6684)), 0, (OOC_X86_SSA__Designator)i4, (OOC_X86_SSA__Result)i3);
            goto l36;
          case 54:
            i2 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AfterList((OOC_X86_SSA__Instr)i2, (-1));
            i3 = (OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG(i2)), OOC_X86_SSA__IterInstrAfterListDesc_Next);
            i4 = OOC_TBCALL(i3,OOC_X86_SSA__IterInstrAfterListDesc_Next)((OOC_X86_SSA__IterInstrAfterList)i2, (void*)(OOC_INT32)&dep);
            if (!i4) goto l36;
l22_loop:
            i4 = (OOC_INT32)dep;
            i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 6812))+12);
            i5 = *(OOC_INT8*)((_check_pointer(i5, 6818))+20);
            switch (i5) {
            case 53:
              i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 6886))+12);
              i5 = (OOC_INT32)value;
              i6 = (OOC_INT32)designator;
              i7 = (OOC_INT32)afterInstr;
              OOC_X86_Destore__Transform_PropagateInstr_PropagateValue_MergeValue((OOC_X86_SSA__MergeInstr)(_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 6895)))), &_td_OOC_X86_SSA__MergeInstrDesc, 6895)), (OOC_X86_SSA__Instr)i7, (OOC_X86_SSA__Designator)i6, (OOC_X86_SSA__Result)i5);
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
          case 55:
            i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 7153)))), &_td_OOC_X86_SSA__LoopBackedgeInstrDesc, 7153)), 7171))+48);
            i3 = (OOC_INT32)value;
            i4 = (OOC_INT32)designator;
            OOC_X86_Destore__Transform_PropagateInstr_PropagateValue_MergeLoopValue((OOC_X86_SSA__Block)i2, 1, (OOC_X86_SSA__Designator)i4, (OOC_X86_SSA__Result)i3);
            goto l36;
          case 28:
            goto l36;
          case 27:
            goto l36;
          default:
            _failed_case(i3, 5460);
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
          register OOC_INT32 i0,i1,i2;

          i0 = (OOC_INT32)designator;
          i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 7545)), 0);
          i1 = i1==1;
          if (i1) goto l3;
          i1=0u;
          goto l5;
l3:
          i1 = _check_pointer(i0, 7566);
          i2 = OOC_ARRAY_LENGTH(i1, 0);
          i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 7566))*4);
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7570)))), &_td_OOC_X86_SSA__VarDesc);
          
l5:
          if (i1) goto l7;
          i0=0u;
          goto l8;
l7:
          i0 = _check_pointer(i0, 7615);
          i1 = OOC_ARRAY_LENGTH(i0, 0);
          i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 7615))*4);
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7621)))), &_td_OOC_X86_SSA__VarDesc, 7621)), 7625));
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7630))+48);
          i0 = OOC_X86_SSA__MapType((OOC_SymbolTable__Type)i0);
          i0 = i0!=0;
          
l8:
          return i0;
          ;
        }


      i0 = (OOC_INT32)propInstr;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7711))+40);
      i1 = i1==(OOC_INT32)0;
      if (!i1) goto l16;
      *(OOC_INT32*)((_check_pointer(i0, 7746))+40) = i0;
      i1 = *(OOC_INT8*)((_check_pointer(i0, 7822))+20);
      switch (i1) {
      case 26:
      case 32:
      case 28:
      case 27:
      case 47:
      case 49:
      case 48:
      case 52:
      case 54:
      case 55:
      case 53:
      case 29:
      case 36:
        goto l16;
      case 34:
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8070))+28);
        i0 = OOC_X86_Destore__Transform_PropagateInstr_FixedDesignator((OOC_X86_SSA__Designator)i0);
        if (!i0) goto l16;
        i0 = (OOC_INT32)propInstr;
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8173))+4);
        i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8124))+28);
        OOC_X86_Destore__Transform_PropagateInstr_PropagateValue((OOC_X86_SSA__Designator)i2, (OOC_X86_SSA__Result)i1, (OOC_X86_SSA__Instr)i0);
        goto l16;
      case 35:
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8268))+28);
        i0 = OOC_X86_Destore__Transform_PropagateInstr_FixedDesignator((OOC_X86_SSA__Designator)i0);
        if (!i0) goto l16;
        i0 = (OOC_INT32)propInstr;
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 8371));
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 8380))+4);
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 8389));
        i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8322))+28);
        OOC_X86_Destore__Transform_PropagateInstr_PropagateValue((OOC_X86_SSA__Designator)i2, (OOC_X86_SSA__Result)i1, (OOC_X86_SSA__Instr)i0);
        goto l16;
      case 51:
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8553))+16);
        i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8531))+4);
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8484))+28);
        OOC_X86_Destore__Transform_PropagateInstr_PropagateValue((OOC_X86_SSA__Designator)i0, (OOC_X86_SSA__Result)i2, (OOC_X86_SSA__Instr)i1);
        goto l16;
      default:
        _failed_case(i1, 7808);
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
              i1 = _check_pointer(i0, 9312);
              i2 = OOC_ARRAY_LENGTH(i1, 0);
              i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 9312))*4);
              i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9316)))), &_td_OOC_X86_SSA__VarDesc);
              if (i1) goto l3;
              return (OOC_SymbolTable__VarDecl)(OOC_INT32)0;
              goto l4;
l3:
              i0 = _check_pointer(i0, 9360);
              i1 = OOC_ARRAY_LENGTH(i0, 0);
              i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 9360))*4);
              i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9366)))), &_td_OOC_X86_SSA__VarDesc, 9366)), 9370));
              return (OOC_SymbolTable__VarDecl)i0;
l4:
              _failed_function(9054); return 0;
              ;
            }

            
            OOC_CHAR8 OOC_X86_Destore__Transform_VisibleEffect_ReadingUse_ExternalVisibility(OOC_SymbolTable__VarDecl var) {
              register OOC_INT32 i0,i1;

              i0 = (OOC_INT32)var;
              i1 = i0==(OOC_INT32)0;
              if (i1) goto l3;
              i1 = *(OOC_UINT8*)((_check_pointer(i0, 9748))+59);
              
              goto l5;
l3:
              i1=1u;
l5:
              if (i1) goto l7;
              i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9815)))), OOC_SymbolTable__ItemDesc_Procedure)),OOC_SymbolTable__ItemDesc_Procedure)((OOC_SymbolTable__Item)i0);
              i1 = (OOC_INT32)fctBlock;
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 9839))+56);
              i0 = i0!=i1;
              
              goto l8;
l7:
              i0=1u;
l8:
              return i0;
              ;
            }


          i0 = (OOC_INT32)instr;
          i1 = *(OOC_INT8*)((_check_pointer(i0, 9945))+20);
          switch (i1) {
          case 34:
            i1 = (OOC_INT32)set;
            i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10038))+28);
            i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 10020))+28);
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
          case 35:
            i1 = (OOC_INT32)set;
            i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10353))+28);
            i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 10335))+28);
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
          case 28:
          case 27:
            i0 = (OOC_INT32)set;
            i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11306))+28);
            i0 = (OOC_INT32)OOC_X86_Destore__Transform_VisibleEffect_ReadingUse_GetVar((OOC_X86_SSA__Designator)i0);
            i0 = OOC_X86_Destore__Transform_VisibleEffect_ReadingUse_ExternalVisibility((OOC_SymbolTable__VarDecl)i0);
            return i0;
            goto l26;
          case 47:
          case 48:
          case 52:
          case 53:
            i1 = (OOC_INT32)set;
            i0 = OOC_X86_Destore__Transform_VisibleEffect((OOC_X86_SSA__Instr)i0, (OOC_X86_SSA__Instr)i1);
            return i0;
            goto l26;
          case 55:
            i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11482)))), &_td_OOC_X86_SSA__LoopBackedgeInstrDesc, 11482)), 11500))+48);
            i1 = (OOC_INT32)set;
            i0 = OOC_X86_Destore__Transform_VisibleEffect((OOC_X86_SSA__Instr)i0, (OOC_X86_SSA__Instr)i1);
            return i0;
            goto l26;
          case 49:
          case 54:
            i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_MergingTarget((OOC_X86_SSA__Instr)i0);
            i0 = OOC_X86_Destore__Transform_VisibleEffect_ReadingUse((OOC_X86_SSA__Instr)i0);
            return i0;
            goto l26;
          case 29:
            i1 = (OOC_INT32)set;
            i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 11648));
            i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 11657));
            i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11666))+28);
            i2 = OOC_X86_Destore__Transform_AccessedByCall((OOC_X86_SSA__Result)i2, (OOC_X86_SSA__Designator)i3, 0);
            if (i2) goto l23;
            i0 = OOC_X86_Destore__Transform_VisibleEffect((OOC_X86_SSA__Instr)i0, (OOC_X86_SSA__Instr)i1);
            return i0;
            goto l26;
l23:
            return 1u;
            goto l26;
          default:
            _failed_case(i1, 9935);
            goto l26;
          }
l26:
          _failed_function(8954); return 0;
          ;
        }


      i0 = (OOC_INT32)store;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11974))+40);
      i2 = (OOC_INT32)set;
      i1 = i1!=i2;
      if (i1) goto l3;
      i0 = *(OOC_INT32*)((_check_pointer(i0, 12465))+44);
      return (i0!=0);
      goto l32;
l3:
      *(OOC_INT32*)((_check_pointer(i0, 12005))+40) = i2;
      *(OOC_INT32*)((_check_pointer(i0, 12032))+44) = 0;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12104))+36);
      dep = (OOC_X86_SSA__Dep)i0;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l6;
      i0=0u;
      goto l12;
l6:
      i1 = *(OOC_INT8*)((_check_pointer(i0, 12149))+8);
      i1 = i1!=1;
      if (i1) goto l9;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12217))+12);
      i0 = OOC_X86_Destore__Transform_VisibleEffect_ReadingUse((OOC_X86_SSA__Instr)i0);
      i0 = !i0;
      
      goto l12;
l9:
      i0=1u;
l12:
      if (!i0) goto l27;
l14_loop:
      i0 = (OOC_INT32)dep;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12249))+16);
      dep = (OOC_X86_SSA__Dep)i0;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l17;
      i0=0u;
      goto l23;
l17:
      i1 = *(OOC_INT8*)((_check_pointer(i0, 12149))+8);
      i1 = i1!=1;
      if (i1) goto l20;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12217))+12);
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
      *(OOC_INT32*)((_check_pointer(i0, 12382))+44) = 0;
      return 0u;
      goto l32;
l30:
      i0 = (OOC_INT32)store;
      *(OOC_INT32*)((_check_pointer(i0, 12317))+44) = 1;
      return 1u;
l32:
      _failed_function(8625); return 0;
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
      i3 = *(OOC_INT8*)((_check_pointer(i2, 12663))+20);
      i3 = i3==51;
      if (i3) goto l9;
      i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 12749)))), &_td_OOC_X86_SSA__BlockDesc);
      if (!i3) goto l10;
      OOC_X86_Destore__Transform_AddDesignatorGatetoWorklist((OOC_X86_SSA__Block)(_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 12812)))), &_td_OOC_X86_SSA__BlockDesc, 12812)));
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
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13010))+8);
      i1 = i1!=(OOC_INT32)0;
      if (!i1) goto l30;
      i1 = (OOC_INT32)_new;
      i2 = eliminateLoopEnd;
l3_loop:
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13047))+8);
      use = (OOC_X86_SSA__Opnd)i3;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 13112))+8);
      i4 = *(OOC_INT8*)((_check_pointer(i4, 13118))+20);
      i4 = i4==51;
      if (i4) goto l6;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 13165))+8);
      i4 = *(OOC_INT8*)((_check_pointer(i4, 13171))+20);
      i4 = i4==50;
      
      goto l8;
l6:
      i4=1u;
l8:
      if (i4) goto l10;
      i4=0u;
      goto l12;
l10:
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 13207))+8);
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13219))+4);
      i4 = i4!=i5;
      
l12:
      if (!i4) goto l14;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 13259))+8);
      OOC_X86_Destore__Transform_AddToWorklist((OOC_X86_SSA__Instr)i4);
l14:
      OOC_X86_SSA__OpndDesc_ReplaceArg((OOC_X86_SSA__Opnd)i3, (OOC_X86_SSA__Result)i1);
      if (i2) goto l17;
      i4=0u;
      goto l19;
l17:
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 13355))+8);
      i4 = OOC_X86_SSA__InstrDesc_IsLoopEndGate((OOC_X86_SSA__Instr)i4);
      
l19:
      if (i4) goto l21;
      i4=0u;
      goto l23;
l21:
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 13394))+8);
      i4 = OOC_X86_SSA__InstrDesc_AllOpndsSameValue((OOC_X86_SSA__Instr)i4);
      
l23:
      if (!i4) goto l25;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 13827))+8);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 13833))+4);
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 13849));
      OOC_X86_Destore__Transform_ReplaceUses((OOC_X86_SSA__Result)i4, (OOC_X86_SSA__Result)i3, 0u);
l25:
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13010))+8);
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
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14080))+4);
      i1 = i1==(OOC_INT32)0;
      if (i1) goto l42;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14264))+48);
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14271)))), &_td_OOC_X86_SSA__LoopStartInstrDesc);
      if (i1) goto l33;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14625))+48);
      i1 = *(OOC_INT8*)((_check_pointer(i1, 14631))+20);
      i1 = i1==53;
      if (i1) goto l31;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 14971));
      opnd = (OOC_X86_SSA__Opnd)i1;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 15001))+4);
      i2 = i2!=(OOC_INT32)0;
      if (i2) goto l9;
      i2=0u;
      goto l11;
l9:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 15025))+4);
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 15045));
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 15034));
      i2 = i2==i3;
      
l11:
      if (!i2) goto l23;
l14_loop:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 15076))+4);
      opnd = (OOC_X86_SSA__Opnd)i1;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 15001))+4);
      i2 = i2!=(OOC_INT32)0;
      if (i2) goto l17;
      i2=0u;
      goto l19;
l17:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 15025))+4);
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 15045));
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 15034));
      i2 = i2==i3;
      
l19:
      if (i2) goto l14_loop;
l23:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 15116))+4);
      i1 = i1==(OOC_INT32)0;
      if (i1) goto l29;
      i1 = *(OOC_INT8*)((_check_pointer(i0, 15288))+20);
      i1 = i1==51;
      if (!i1) goto l43;
      OOC_X86_SSA__InstrDesc_DesignatorGateToGate((OOC_X86_SSA__Instr)i0);
      goto l43;
l29:
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 15219));
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15201))+4);
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 15228));
      OOC_X86_Destore__Transform_ReplaceUses((OOC_X86_SSA__Result)i2, (OOC_X86_SSA__Result)i1, 0u);
      OOC_X86_SSA__InstrDesc_Delete((OOC_X86_SSA__Instr)i0);
      goto l43;
l31:
      OOC_X86_SSA__InstrDesc_DesignatorGateToGate((OOC_X86_SSA__Instr)i0);
      goto l43;
l33:
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 14314));
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14323))+4);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14344))+4);
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 14332));
      i1 = i1==i2;
      if (i1) goto l39;
      i1 = *(OOC_INT8*)((_check_pointer(i0, 14521))+20);
      i1 = i1==51;
      if (!i1) goto l43;
      OOC_X86_SSA__InstrDesc_DesignatorGateToGate((OOC_X86_SSA__Instr)i0);
      goto l43;
l39:
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 14453));
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14435))+4);
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 14462));
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
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 15570))+12);
      OOC_X86_Destore__Transform_AddToWorklist((OOC_X86_SSA__Instr)i3);
      i3 = OOC_TBCALL(i2,OOC_X86_SSA__IterInstrAfterListDesc_Next)((OOC_X86_SSA__IterInstrAfterList)i1, (void*)(OOC_INT32)&dep);
      if (i3) goto l2_loop;
l7:
      i1 = *(OOC_INT8*)((_check_pointer(i0, 15605))+20);
      i1 = i1==49;
      if (i1) goto l13;
      i1 = *(OOC_INT8*)((_check_pointer(i0, 15747))+20);
      i1 = i1==55;
      if (!i1) goto l21;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15952)))), &_td_OOC_X86_SSA__LoopBackedgeInstrDesc, 15952)), 15970))+48);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15976))+60);
      OOC_X86_Destore__Transform_AddToWorklist((OOC_X86_SSA__Instr)i0);
      goto l21;
l13:
      i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AfterList((OOC_X86_SSA__Instr)i0, 0);
      i1 = (OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG(i0)), OOC_X86_SSA__IterInstrAfterListDesc_Next);
      i2 = OOC_TBCALL(i1,OOC_X86_SSA__IterInstrAfterListDesc_Next)((OOC_X86_SSA__IterInstrAfterList)i0, (void*)(OOC_INT32)&dep);
      if (!i2) goto l21;
l15_loop:
      i2 = (OOC_INT32)dep;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 15707))+12);
      OOC_X86_Destore__Transform_AddToWorklist((OOC_X86_SSA__Instr)i2);
      i2 = OOC_TBCALL(i1,OOC_X86_SSA__IterInstrAfterListDesc_Next)((OOC_X86_SSA__IterInstrAfterList)i0, (void*)(OOC_INT32)&dep);
      if (i2) goto l15_loop;
l21:
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
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16205))+48);
      i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16214)))), &_td_OOC_X86_SSA__LoopStartInstrDesc, 16214);
      loopStart = (OOC_X86_SSA__LoopStartInstr)i1;
      i2 = (OOC_INT32)gateToInstr;
      i2 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i2, (Object__Object)i0);
      memAccess = (OOC_X86_Destore__MemAccess)i2;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 16328))+4);
      i4 = (OOC_INT32)fctBlock;
      i3 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr1((OOC_X86_SSA__Block)i4, 34, (OOC_X86_SSA__Result)i3);
      get = (OOC_X86_SSA__Instr)i3;
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 16372));
      OOC_X86_SSA__InstrDesc_SetDesignator((OOC_X86_SSA__Instr)i3, (OOC_X86_SSA__Designator)i4);
      i4 = (OOC_INT32)OOC_X86_SSA__InstrDesc_BeforeList((OOC_X86_SSA__Instr)i1, 1);
      i5 = (OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG(i4)), OOC_X86_SSA__IterInstrBeforeListDesc_Next);
      i6 = OOC_TBCALL(i5,OOC_X86_SSA__IterInstrBeforeListDesc_Next)((OOC_X86_SSA__IterInstrBeforeList)i4, (void*)(OOC_INT32)&dep);
      if (!i6) goto l8;
l3_loop:
      i6 = (OOC_INT32)dep;
      i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i6, 16475));
      OOC_X86_SSA__InstrDesc_AddDep((OOC_X86_SSA__Instr)i3, 1, (OOC_X86_SSA__Instr)i6);
      i6 = (OOC_INT32)dep;
      OOC_X86_SSA__DepDesc_DeleteDep((OOC_X86_SSA__Dep)i6);
      i6 = OOC_TBCALL(i5,OOC_X86_SSA__IterInstrBeforeListDesc_Next)((OOC_X86_SSA__IterInstrBeforeList)i4, (void*)(OOC_INT32)&dep);
      if (i6) goto l3_loop;
l8:
      OOC_X86_SSA__InstrDesc_AddDep((OOC_X86_SSA__Instr)i1, 1, (OOC_X86_SSA__Instr)i3);
      i1 = *(OOC_INT8*)((_check_pointer(i2, 16617))+8);
      i1 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResult((OOC_X86_SSA__Instr)i3, i1);
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 16573));
      OOC_X86_SSA__OpndDesc_ReplaceArg((OOC_X86_SSA__Opnd)i0, (OOC_X86_SSA__Result)i1);
      return;
      ;
    }


  worklist = (OOC_X86_Destore__Worklist)(OOC_INT32)0;
  i0 = (OOC_INT32)RT0__NewObject(_td__qtd1.baseTypes[0]);
  ADT_Dictionary__DictionaryDesc_INIT((ADT_Dictionary__Dictionary)i0);
  inWorklist = (ADT_Dictionary__Dictionary)i0;
  i0 = (OOC_INT32)fctBlock;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16776))+60);
  i1 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResult((OOC_X86_SSA__Instr)i1, 0);
  undefValue = (OOC_X86_SSA__Result)i1;
  OOC_X86_SSA__BlockDesc_SetMarkers((OOC_X86_SSA__Block)i0, (OOC_X86_SSA__Node)(OOC_INT32)0, 0);
  i1 = (OOC_INT32)RT0__NewObject(_td__qtd3.baseTypes[0]);
  ADT_Dictionary__DictionaryDesc_INIT((ADT_Dictionary__Dictionary)i1);
  gateToInstr = (ADT_Dictionary__Dictionary)i1;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16939))+60);
  OOC_X86_Destore__Transform_AddToWorklist((OOC_X86_SSA__Instr)i0);
  i0 = (OOC_INT32)worklist;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l8;
l3_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17001))+4);
  instr = (OOC_X86_SSA__Instr)i1;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 17035));
  worklist = (OOC_X86_Destore__Worklist)i0;
  OOC_X86_Destore__Transform_PropagateInstr((OOC_X86_SSA__Instr)i1);
  i0 = (OOC_INT32)instr;
  OOC_X86_Destore__Transform_AddMemoryDeps((OOC_X86_SSA__Instr)i0);
  i0 = (OOC_INT32)worklist;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l3_loop;
l8:
  i0 = (OOC_INT32)undefValue;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17453))+8);
  i0 = i0!=(OOC_INT32)0;
  if (!i0) goto l25;
l11_loop:
  i0 = (OOC_INT32)undefValue;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17496))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 17504))+8);
  i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17513)))), &_td_OOC_X86_SSA__GateInstrDesc, 17513);
  gate = (OOC_X86_SSA__GateInstr)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 17540))+48);
  i2 = *(OOC_INT8*)((_check_pointer(i2, 17546))+20);
  switch (i2) {
  case 52:
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17616))+8);
    i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 17594));
    i0 = i2==i0;
    if (i0) goto l16;
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 18025));
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 18008))+4);
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 18034));
    OOC_X86_Destore__Transform_ReplaceUses((OOC_X86_SSA__Result)i1, (OOC_X86_SSA__Result)i0, 1u);
    i0 = (OOC_INT32)gate;
    OOC_X86_SSA__InstrDesc_Delete((OOC_X86_SSA__Instr)i0);
    goto l20;
l16:
    OOC_X86_Destore__Transform_FixLoopStart((OOC_X86_SSA__GateInstr)i1);
    goto l20;
  case 48:
  case 47:
  case 53:
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 18141))+4);
    _assert((i0==(OOC_INT32)0), 127, 18130);
    OOC_X86_SSA__InstrDesc_Delete((OOC_X86_SSA__Instr)i1);
    goto l20;
  default:
    _failed_case(i2, 17531);
    goto l20;
  }
l20:
  i0 = (OOC_INT32)undefValue;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17453))+8);
  i0 = i0!=(OOC_INT32)0;
  if (i0) goto l11_loop;
l25:
  i0 = (OOC_INT32)fctBlock;
  OOC_X86_SSA__BlockDesc_SetMarkers((OOC_X86_SSA__Block)i0, (OOC_X86_SSA__Node)(OOC_INT32)0, 0);
  i1 = (OOC_INT32)inWorklist;
  ADT_Dictionary__DictionaryDesc_Clear((ADT_Dictionary__Dictionary)i1);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18433))+60);
  OOC_X86_Destore__Transform_AddToWorklist((OOC_X86_SSA__Instr)i0);
  i0 = (OOC_INT32)worklist;
  i0 = i0!=(OOC_INT32)0;
  if (!i0) goto l40;
l28_loop:
  i0 = (OOC_INT32)worklist;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18495))+4);
  instr = (OOC_X86_SSA__Instr)i1;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 18529));
  worklist = (OOC_X86_Destore__Worklist)i0;
  OOC_X86_Destore__Transform_AddMemoryDeps((OOC_X86_SSA__Instr)i1);
  i0 = (OOC_INT32)instr;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 18579))+20);
  i1 = i1==35;
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
  i0 = (OOC_INT32)inWorklist;
  ADT_Dictionary__DictionaryDesc_Clear((ADT_Dictionary__Dictionary)i0);
  i0 = (OOC_INT32)fctBlock;
  OOC_X86_Destore__Transform_AddDesignatorGatetoWorklist((OOC_X86_SSA__Block)i0);
  i0 = (OOC_INT32)worklist;
  i0 = i0!=(OOC_INT32)0;
  if (!i0) goto l51;
l43_loop:
  i0 = (OOC_INT32)worklist;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18892))+4);
  instr = (OOC_X86_SSA__Instr)i1;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 18926));
  worklist = (OOC_X86_Destore__Worklist)i0;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 18948));
  i0 = i0!=(OOC_INT32)0;
  if (!i0) goto l46;
  OOC_X86_Destore__Transform_PromoteDesignatorGate((OOC_X86_SSA__GateInstr)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 19070)))), &_td_OOC_X86_SSA__GateInstrDesc, 19070)));
l46:
  i0 = (OOC_INT32)worklist;
  i0 = i0!=(OOC_INT32)0;
  if (i0) goto l43_loop;
l51:
  i0 = (OOC_INT32)undefValue;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19124))+8);
  _assert((i1==(OOC_INT32)0), 127, 19107);
  OOC_X86_SSA__ResultDesc_DeleteResult((OOC_X86_SSA__Result)i0);
  return;
  ;
}

void OOC_OOC_X86_Destore_init(void) {

  return;
  ;
}

void OOC_OOC_X86_Destore_destroy(void) {
}

/* --- */
