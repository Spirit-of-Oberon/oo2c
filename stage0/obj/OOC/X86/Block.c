#include <OOC/X86/Block.d>
#include <__oo2c.h>
#include <setjmp.h>

void OOC_X86_Block__ArrangeInstructions(OOC_X86_SSA__FunctionBlock fctBlock) {
  register OOC_INT32 i0,i1,i2;
  OOC_X86_SSA__MergeInstr dummy;
  OOC_X86_SSA__Block ready;
  OOC_X86_SSA__Block waiting;
  OOC_X86_SSA__Instr instr;
  OOC_X86_SSA__Block block;
  OOC_X86_SSA__Instr next;
  OOC_X86_SSA__Dep dep;
  auto OOC_X86_SSA__MergeInstr OOC_X86_Block__ArrangeInstructions_InflateControlFlow(OOC_X86_SSA__Block b, OOC_X86_SSA__Instr instr);
  auto void OOC_X86_Block__ArrangeInstructions_AddToReady(OOC_X86_SSA__Instr instr);
  auto void OOC_X86_Block__ArrangeInstructions_SetUseCount(OOC_X86_SSA__Block b);
  auto void OOC_X86_Block__ArrangeInstructions_UpdateDefs(OOC_X86_SSA__Instr instr);
  auto OOC_X86_SSA__Block OOC_X86_Block__ArrangeInstructions_GetBlock(OOC_X86_SSA__Instr instr);
  auto void OOC_X86_Block__ArrangeInstructions_ClearBlock(OOC_X86_SSA__Block b);
  auto void OOC_X86_Block__ArrangeInstructions_SortBlock(OOC_X86_SSA__Block b);
    
    OOC_X86_SSA__MergeInstr OOC_X86_Block__ArrangeInstructions_InflateControlFlow(OOC_X86_SSA__Block b, OOC_X86_SSA__Instr instr) {
      register OOC_INT32 i0,i1,i2,i3,i4;
      OOC_X86_SSA__MergeInstr merge;
      OOC_INT32 nonMergeCount;
      OOC_X86_SSA__Block path;
      OOC_X86_SSA__MergeInstr m;
      auto OOC_X86_SSA__Instr OOC_X86_Block__ArrangeInstructions_InflateControlFlow_NextInControlFlow(OOC_X86_SSA__Instr instr);
      auto void OOC_X86_Block__ArrangeInstructions_InflateControlFlow_Prelocate(OOC_X86_SSA__Instr instr, OOC_X86_SSA__Instr block);
        
        OOC_X86_SSA__Instr OOC_X86_Block__ArrangeInstructions_InflateControlFlow_NextInControlFlow(OOC_X86_SSA__Instr instr) {
          register OOC_INT32 i0,i1,i2;
          OOC_X86_SSA__Instr next;
          auto OOC_CHAR8 OOC_X86_Block__ArrangeInstructions_InflateControlFlow_NextInControlFlow_RelevantAfterDep(OOC_X86_SSA__Dep dep);
            
            OOC_CHAR8 OOC_X86_Block__ArrangeInstructions_InflateControlFlow_NextInControlFlow_RelevantAfterDep(OOC_X86_SSA__Dep dep) {
              register OOC_INT32 i0;

              i0 = (OOC_INT32)dep;
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 599))+12);
              i0 = *(OOC_INT8*)((_check_pointer(i0, 605))+20);
              switch (i0) {
              case 18:
              case 41:
                return 0u;
                goto l4;
              default:
                return 1u;
                goto l4;
              }
l4:
              _failed_function(528); return 0;
              ;
            }


          next = (OOC_X86_SSA__Instr)(OOC_INT32)0;
          i0 = (OOC_INT32)instr;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 818))+36);
          dep = (OOC_X86_SSA__Dep)i0;
          i1 = i0!=(OOC_INT32)0;
          if (i1) goto l3;
          i0=(OOC_INT32)0;
          goto l17;
l3:
          i1=(OOC_INT32)0;
l4_loop:
          i2 = *(OOC_INT8*)((_check_pointer(i0, 876))+8);
          i2 = i2==0;
          if (i2) goto l7;
          i2=0u;
          goto l9;
l7:
          i2 = OOC_X86_Block__ArrangeInstructions_InflateControlFlow_NextInControlFlow_RelevantAfterDep((OOC_X86_SSA__Dep)i0);
          
l9:
          if (!i2) goto l12;
          _assert((i1==(OOC_INT32)0), 127, 939);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 982))+12);
          next = (OOC_X86_SSA__Instr)i1;
          
l12:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 1025))+16);
          dep = (OOC_X86_SSA__Dep)i0;
          i2 = i0!=(OOC_INT32)0;
          if (i2) goto l4_loop;
l16:
          i0=i1;
l17:
          return (OOC_X86_SSA__Instr)i0;
          ;
        }

        
        void OOC_X86_Block__ArrangeInstructions_InflateControlFlow_Prelocate(OOC_X86_SSA__Instr instr, OOC_X86_SSA__Instr block) {
          register OOC_INT32 i0,i1;

          i0 = (OOC_INT32)instr;
          i1 = (OOC_INT32)block;
          *(OOC_INT32*)((_check_pointer(i0, 1183))+40) = i1;
          return;
          ;
        }


      i0 = (OOC_INT32)instr;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l3;
      i1=0u;
      goto l5;
l3:
      i1 = *(OOC_INT8*)((_check_pointer(i0, 1269))+20);
      i1 = i1!=41;
      
l5:
      if (!i1) goto l52;
l7_loop:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 1313))+40);
      _assert((i1==(OOC_INT32)0), 127, 1301);
      i1 = (OOC_INT32)b;
      OOC_X86_Block__ArrangeInstructions_InflateControlFlow_Prelocate((OOC_X86_SSA__Instr)i0, (OOC_X86_SSA__Instr)i1);
      i0 = (OOC_INT32)instr;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1383)))), &_td_OOC_X86_SSA__BranchInstrDesc);
      if (i1) goto l22;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2026)))), &_td_OOC_X86_SSA__LoopStartInstrDesc);
      if (i1) goto l20;
      i1 = *(OOC_INT8*)((_check_pointer(i0, 2339))+20);
      i1 = i1==37;
      if (i1) goto l14;
      i0 = (OOC_INT32)OOC_X86_Block__ArrangeInstructions_InflateControlFlow_NextInControlFlow((OOC_X86_SSA__Instr)i0);
      next = (OOC_X86_SSA__Instr)i0;
      goto l43;
l14:
      i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_JumpTarget((OOC_X86_SSA__Instr)i0);
      m = (OOC_X86_SSA__MergeInstr)i0;
      i1 = *(OOC_INT8*)((_check_pointer(i0, 2416))+20);
      i1 = i1==36;
      if (i1) goto l17;
      return (OOC_X86_SSA__MergeInstr)(OOC_INT32)0;
      goto l43;
l17:
      return (OOC_X86_SSA__MergeInstr)i0;
      goto l43;
l20:
      i0 = (OOC_INT32)OOC_X86_Block__ArrangeInstructions_InflateControlFlow_NextInControlFlow((OOC_X86_SSA__Instr)i0);
      i1 = (OOC_INT32)instr;
      i0 = (OOC_INT32)OOC_X86_Block__ArrangeInstructions_InflateControlFlow((OOC_X86_SSA__Block)i1, (OOC_X86_SSA__Instr)i0);
      m = (OOC_X86_SSA__MergeInstr)i0;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 2141))+56);
      OOC_X86_Block__ArrangeInstructions_InflateControlFlow_Prelocate((OOC_X86_SSA__Instr)i0, (OOC_X86_SSA__Instr)i1);
      i0 = (OOC_INT32)instr;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2185))+60);
      i1 = (OOC_INT32)b;
      OOC_X86_Block__ArrangeInstructions_InflateControlFlow_Prelocate((OOC_X86_SSA__Instr)i0, (OOC_X86_SSA__Instr)i1);
      i0 = (OOC_INT32)instr;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2236))+60);
      i0 = (OOC_INT32)OOC_X86_Block__ArrangeInstructions_InflateControlFlow_NextInControlFlow((OOC_X86_SSA__Instr)i0);
      next = (OOC_X86_SSA__Instr)i0;
      goto l43;
l22:
      merge = (OOC_X86_SSA__MergeInstr)(OOC_INT32)0;
      nonMergeCount = 0;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 1483))+56);
      i0 = _check_pointer(i0, 1489);
      i1 = OOC_ARRAY_LENGTH(i0, 0);
      i1 = i0+i1*4;
      i2 = i1!=i0;
      if (!i2) goto l38;
l25_loop:
      i2 = (OOC_INT32)*(OOC_INT32*)i0;
      path = (OOC_X86_SSA__Block)i2;
      i3 = (OOC_INT32)instr;
      OOC_X86_Block__ArrangeInstructions_InflateControlFlow_Prelocate((OOC_X86_SSA__Instr)i2, (OOC_X86_SSA__Instr)i3);
      i2 = (OOC_INT32)path;
      i2 = (OOC_INT32)OOC_X86_Block__ArrangeInstructions_InflateControlFlow_NextInControlFlow((OOC_X86_SSA__Instr)i2);
      i3 = (OOC_INT32)path;
      i2 = (OOC_INT32)OOC_X86_Block__ArrangeInstructions_InflateControlFlow((OOC_X86_SSA__Block)i3, (OOC_X86_SSA__Instr)i2);
      m = (OOC_X86_SSA__MergeInstr)i2;
      i3 = i2==(OOC_INT32)0;
      if (i3) goto l32;
      i3 = (OOC_INT32)merge;
      i4 = i3==(OOC_INT32)0;
      if (i4) goto l30;
      i3 = i3==i2;
      
      goto l31;
l30:
      i3=1u;
l31:
      _assert(i3, 127, 1693);
      merge = (OOC_X86_SSA__MergeInstr)i2;
      goto l33;
l32:
      i2 = nonMergeCount;
      nonMergeCount = (i2+1);
l33:
      i0 = i0+4;
      i2 = i1!=i0;
      if (i2) goto l25_loop;
l38:
      i0 = nonMergeCount;
      i0 = i0==0;
      if (i0) goto l41;
      i0 = (OOC_INT32)merge;
      return (OOC_X86_SSA__MergeInstr)i0;
      goto l43;
l41:
      i0 = (OOC_INT32)merge;
      i1 = *(OOC_INT8*)((_check_pointer(i0, 1851))+20);
      _assert((i1==36), 127, 1839);
      i1 = (OOC_INT32)instr;
      OOC_X86_Block__ArrangeInstructions_InflateControlFlow_Prelocate((OOC_X86_SSA__Instr)i0, (OOC_X86_SSA__Instr)i1);
      i0 = (OOC_INT32)merge;
      i0 = (OOC_INT32)OOC_X86_Block__ArrangeInstructions_InflateControlFlow_NextInControlFlow((OOC_X86_SSA__Instr)i0);
      next = (OOC_X86_SSA__Instr)i0;
l43:
      i0 = (OOC_INT32)next;
      instr = (OOC_X86_SSA__Instr)i0;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l46;
      i1=0u;
      goto l48;
l46:
      i1 = *(OOC_INT8*)((_check_pointer(i0, 1269))+20);
      i1 = i1!=41;
      
l48:
      if (i1) goto l7_loop;
l52:
      return (OOC_X86_SSA__MergeInstr)(OOC_INT32)0;
      ;
    }

    
    void OOC_X86_Block__ArrangeInstructions_AddToReady(OOC_X86_SSA__Instr instr) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)instr;
      i1 = *(OOC_INT8*)((_check_pointer(i0, 2760))+20);
      switch (i1) {
      case 37:
      case 43:
        i1 = (OOC_INT32)ready;
        OOC_X86_SSA__BlockDesc_AddInFront((OOC_X86_SSA__Block)i1, (OOC_X86_SSA__Instr)i0);
        goto l4;
      default:
        i1 = (OOC_INT32)ready;
        OOC_X86_SSA__BlockDesc_Add((OOC_X86_SSA__Block)i1, (OOC_X86_SSA__Instr)i0);
        goto l4;
      }
l4:
      return;
      ;
    }

    
    void OOC_X86_Block__ArrangeInstructions_SetUseCount(OOC_X86_SSA__Block b) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
      OOC_X86_SSA__Instr instr;
      OOC_INT32 useCount;
      OOC_X86_SSA__Result res;
      OOC_X86_SSA__Opnd use;
      OOC_X86_SSA__Dep dep;

      i0 = (OOC_INT32)b;
      i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_Instructions((OOC_X86_SSA__Block)i0);
      i1 = (OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG(i0)), OOC_X86_SSA__IterBlockInstructionsDesc_Next);
      i2 = OOC_TBCALL(i1,OOC_X86_SSA__IterBlockInstructionsDesc_Next)((OOC_X86_SSA__IterBlockInstructions)i0, (void*)(OOC_INT32)&instr);
      if (!i2) goto l46;
l3_loop:
      useCount = 0;
      i2 = (OOC_INT32)instr;
      i2 = (OOC_INT32)OOC_X86_SSA__InstrDesc_Results((OOC_X86_SSA__Instr)i2);
      i3 = (OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG(i2)), OOC_X86_SSA__IterInstrResultsDesc_Next);
      i4 = OOC_TBCALL(i3,OOC_X86_SSA__IterInstrResultsDesc_Next)((OOC_X86_SSA__IterInstrResults)i2, (void*)(OOC_INT32)&res);
      if (i4) goto l6;
      i2=0;
      goto l25;
l6:
      i4=0;
l7_loop:
      i5 = (OOC_INT32)res;
      i5 = (OOC_INT32)OOC_X86_SSA__ResultDesc_Uses((OOC_X86_SSA__Result)i5);
      i6 = (OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG(i5)), OOC_X86_SSA__IterResultUsesDesc_Next);
      i7 = OOC_TBCALL(i6,OOC_X86_SSA__IterResultUsesDesc_Next)((OOC_X86_SSA__IterResultUses)i5, (void*)(OOC_INT32)&use);
      if (!i7) goto l20;
l11_loop:
      i7 = (OOC_INT32)use;
      i7 = OOC_X86_SSA__OpndDesc_IsBackedgeOpnd((OOC_X86_SSA__Opnd)i7);
      i7 = !i7;
      if (!i7) goto l15;
      i4 = i4+1;
      useCount = i4;
      
l15:
      i7 = OOC_TBCALL(i6,OOC_X86_SSA__IterResultUsesDesc_Next)((OOC_X86_SSA__IterResultUses)i5, (void*)(OOC_INT32)&use);
      if (i7) goto l11_loop;
l20:
      i5 = OOC_TBCALL(i3,OOC_X86_SSA__IterInstrResultsDesc_Next)((OOC_X86_SSA__IterInstrResults)i2, (void*)(OOC_INT32)&res);
      if (i5) goto l7_loop;
l24:
      i2=i4;
l25:
      i3 = (OOC_INT32)instr;
      i3 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AfterList((OOC_X86_SSA__Instr)i3, (-1));
      i4 = (OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG(i3)), OOC_X86_SSA__IterInstrAfterListDesc_Next);
      i5 = OOC_TBCALL(i4,OOC_X86_SSA__IterInstrAfterListDesc_Next)((OOC_X86_SSA__IterInstrAfterList)i3, (void*)(OOC_INT32)&dep);
      if (!i5) goto l34;
l29_loop:
      i2 = i2+1;
      useCount = i2;
      i5 = OOC_TBCALL(i4,OOC_X86_SSA__IterInstrAfterListDesc_Next)((OOC_X86_SSA__IterInstrAfterList)i3, (void*)(OOC_INT32)&dep);
      if (i5) goto l29_loop;
l34:
      i3 = (OOC_INT32)instr;
      *(OOC_INT32*)((_check_pointer(i3, 3437))+44) = i2;
      i2 = i2==0;
      if (i2) goto l37;
      i2 = (OOC_INT32)waiting;
      OOC_X86_SSA__BlockDesc_Add((OOC_X86_SSA__Block)i2, (OOC_X86_SSA__Instr)i3);
      goto l38;
l37:
      OOC_X86_Block__ArrangeInstructions_AddToReady((OOC_X86_SSA__Instr)i3);
l38:
      i2 = (OOC_INT32)instr;
      i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 3602)))), &_td_OOC_X86_SSA__BlockDesc);
      if (!i3) goto l41;
      OOC_X86_Block__ArrangeInstructions_SetUseCount((OOC_X86_SSA__Block)i2);
l41:
      i2 = OOC_TBCALL(i1,OOC_X86_SSA__IterBlockInstructionsDesc_Next)((OOC_X86_SSA__IterBlockInstructions)i0, (void*)(OOC_INT32)&instr);
      if (i2) goto l3_loop;
l46:
      return;
      ;
    }

    
    void OOC_X86_Block__ArrangeInstructions_UpdateDefs(OOC_X86_SSA__Instr instr) {
      register OOC_INT32 i0,i1,i2,i3,i4;
      OOC_X86_SSA__Opnd opnd;
      OOC_X86_SSA__Instr defInstr;
      OOC_X86_SSA__Dep dep;

      i0 = (OOC_INT32)instr;
      i1 = (OOC_INT32)OOC_X86_SSA__InstrDesc_Operands((OOC_X86_SSA__Instr)i0);
      i2 = (OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG(i1)), OOC_X86_SSA__IterInstrOperandsDesc_Next);
      i3 = OOC_TBCALL(i2,OOC_X86_SSA__IterInstrOperandsDesc_Next)((OOC_X86_SSA__IterInstrOperands)i1, (void*)(OOC_INT32)&opnd);
      if (!i3) goto l14;
l3_loop:
      i3 = (OOC_INT32)opnd;
      i4 = OOC_X86_SSA__OpndDesc_IsBackedgeOpnd((OOC_X86_SSA__Opnd)i3);
      i4 = !i4;
      if (!i4) goto l9;
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 3954));
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 3958))+4);
      defInstr = (OOC_X86_SSA__Instr)i3;
      i4 = *(OOC_INT32*)((_check_pointer(i3, 3988))+44);
      *(OOC_INT32*)((_check_pointer(i3, 3988))+44) = (i4-1);
      i4 = *(OOC_INT32*)((_check_pointer(i3, 4020))+44);
      i4 = i4==0;
      if (!i4) goto l9;
      i4 = (OOC_INT32)waiting;
      OOC_X86_SSA__BlockDesc_Remove((OOC_X86_SSA__Block)i4, (OOC_X86_SSA__Instr)i3);
      OOC_X86_Block__ArrangeInstructions_AddToReady((OOC_X86_SSA__Instr)i3);
l9:
      i3 = OOC_TBCALL(i2,OOC_X86_SSA__IterInstrOperandsDesc_Next)((OOC_X86_SSA__IterInstrOperands)i1, (void*)(OOC_INT32)&opnd);
      if (i3) goto l3_loop;
l14:
      i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_BeforeList((OOC_X86_SSA__Instr)i0, (-1));
      i1 = (OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG(i0)), OOC_X86_SSA__IterInstrBeforeListDesc_Next);
      i2 = OOC_TBCALL(i1,OOC_X86_SSA__IterInstrBeforeListDesc_Next)((OOC_X86_SSA__IterInstrBeforeList)i0, (void*)(OOC_INT32)&dep);
      if (!i2) goto l25;
l17_loop:
      i2 = (OOC_INT32)dep;
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 4219));
      defInstr = (OOC_X86_SSA__Instr)i2;
      i3 = *(OOC_INT32*)((_check_pointer(i2, 4248))+44);
      *(OOC_INT32*)((_check_pointer(i2, 4248))+44) = (i3-1);
      i3 = *(OOC_INT32*)((_check_pointer(i2, 4278))+44);
      i3 = i3==0;
      if (!i3) goto l20;
      i3 = (OOC_INT32)waiting;
      OOC_X86_SSA__BlockDesc_Remove((OOC_X86_SSA__Block)i3, (OOC_X86_SSA__Instr)i2);
      OOC_X86_Block__ArrangeInstructions_AddToReady((OOC_X86_SSA__Instr)i2);
l20:
      i2 = OOC_TBCALL(i1,OOC_X86_SSA__IterInstrBeforeListDesc_Next)((OOC_X86_SSA__IterInstrBeforeList)i0, (void*)(OOC_INT32)&dep);
      if (i2) goto l17_loop;
l25:
      return;
      ;
    }

    
    OOC_X86_SSA__Block OOC_X86_Block__ArrangeInstructions_GetBlock(OOC_X86_SSA__Instr instr) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
      OOC_X86_SSA__Block block;
      OOC_X86_SSA__Result res;
      OOC_X86_SSA__Opnd use;
      OOC_X86_SSA__Block useBlock;
      OOC_X86_SSA__Dep dep;
      auto OOC_X86_SSA__Block OOC_X86_Block__ArrangeInstructions_GetBlock_Merge(OOC_X86_SSA__Block a, OOC_X86_SSA__Block b);
      auto OOC_X86_SSA__Block OOC_X86_Block__ArrangeInstructions_GetBlock_BlockOfUse(OOC_X86_SSA__Opnd opnd);
        
        OOC_X86_SSA__Block OOC_X86_Block__ArrangeInstructions_GetBlock_Merge(OOC_X86_SSA__Block a, OOC_X86_SSA__Block b) {
          register OOC_INT32 i0,i1,i2,i3;
          auto OOC_X86_SSA__Block OOC_X86_Block__ArrangeInstructions_GetBlock_Merge_Up(OOC_X86_SSA__Block b);
          auto OOC_INT32 OOC_X86_Block__ArrangeInstructions_GetBlock_Merge_NestingDepth(OOC_X86_SSA__Block b);
            
            OOC_X86_SSA__Block OOC_X86_Block__ArrangeInstructions_GetBlock_Merge_Up(OOC_X86_SSA__Block b) {
              register OOC_INT32 i0,i1;

              i0 = (OOC_INT32)b;
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4672))+40);
              i1 = i1!=(OOC_INT32)0;
              if (i1) goto l3;
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4761))+16);
              return (OOC_X86_SSA__Block)i0;
              goto l4;
l3:
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4710))+40);
              return (OOC_X86_SSA__Block)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4718)))), &_td_OOC_X86_SSA__BlockDesc, 4718));
l4:
              _failed_function(4618); return 0;
              ;
            }

            
            OOC_INT32 OOC_X86_Block__ArrangeInstructions_GetBlock_Merge_NestingDepth(OOC_X86_SSA__Block b) {
              register OOC_INT32 i0,i1,i2;

              i0 = (OOC_INT32)b;
              i1 = i0!=(OOC_INT32)0;
              if (i1) goto l3;
              i0=0;
              goto l9;
l3:
              i1=i0;i0=0;
l4_loop:
              i1 = (OOC_INT32)OOC_X86_Block__ArrangeInstructions_GetBlock_Merge_Up((OOC_X86_SSA__Block)i1);
              i0 = i0+1;
              i2 = i1!=(OOC_INT32)0;
              if (i2) goto l4_loop;
l9:
              return i0;
              ;
            }


          i0 = (OOC_INT32)a;
          i1 = OOC_X86_Block__ArrangeInstructions_GetBlock_Merge_NestingDepth((OOC_X86_SSA__Block)i0);
          i2 = (OOC_INT32)b;
          i3 = OOC_X86_Block__ArrangeInstructions_GetBlock_Merge_NestingDepth((OOC_X86_SSA__Block)i2);
          i1 = i1>i3;
          if (!i1) goto l9;
l4_loop:
          i0 = (OOC_INT32)OOC_X86_Block__ArrangeInstructions_GetBlock_Merge_Up((OOC_X86_SSA__Block)i0);
          a = (OOC_X86_SSA__Block)i0;
          i1 = OOC_X86_Block__ArrangeInstructions_GetBlock_Merge_NestingDepth((OOC_X86_SSA__Block)i0);
          i3 = OOC_X86_Block__ArrangeInstructions_GetBlock_Merge_NestingDepth((OOC_X86_SSA__Block)i2);
          i1 = i1>i3;
          if (i1) goto l4_loop;
l9:
          i1 = OOC_X86_Block__ArrangeInstructions_GetBlock_Merge_NestingDepth((OOC_X86_SSA__Block)i2);
          i3 = OOC_X86_Block__ArrangeInstructions_GetBlock_Merge_NestingDepth((OOC_X86_SSA__Block)i0);
          i1 = i1>i3;
          if (i1) goto l12;
          i1=i2;
          goto l18;
l12:
          i1=i2;
l13_loop:
          i1 = (OOC_INT32)OOC_X86_Block__ArrangeInstructions_GetBlock_Merge_Up((OOC_X86_SSA__Block)i1);
          b = (OOC_X86_SSA__Block)i1;
          i2 = OOC_X86_Block__ArrangeInstructions_GetBlock_Merge_NestingDepth((OOC_X86_SSA__Block)i1);
          i3 = OOC_X86_Block__ArrangeInstructions_GetBlock_Merge_NestingDepth((OOC_X86_SSA__Block)i0);
          i2 = i2>i3;
          if (i2) goto l13_loop;
l18:
          i2 = i0!=i1;
          if (!i2) goto l27;
l22_loop:
          i0 = (OOC_INT32)OOC_X86_Block__ArrangeInstructions_GetBlock_Merge_Up((OOC_X86_SSA__Block)i0);
          a = (OOC_X86_SSA__Block)i0;
          i1 = (OOC_INT32)OOC_X86_Block__ArrangeInstructions_GetBlock_Merge_Up((OOC_X86_SSA__Block)i1);
          b = (OOC_X86_SSA__Block)i1;
          i2 = i0!=i1;
          if (i2) goto l22_loop;
l27:
          return (OOC_X86_SSA__Block)i0;
          ;
        }

        
        OOC_X86_SSA__Block OOC_X86_Block__ArrangeInstructions_GetBlock_BlockOfUse(OOC_X86_SSA__Opnd opnd) {
          register OOC_INT32 i0,i1,i2,i3;
          OOC_X86_SSA__Instr instr;
          OOC_X86_SSA__Block merge;

          i0 = (OOC_INT32)opnd;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6133))+8);
          instr = (OOC_X86_SSA__Instr)i1;
          i2 = *(OOC_INT8*)((_check_pointer(i1, 6158))+20);
          i2 = i2==38;
          if (i2) goto l3;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6565))+16);
          return (OOC_X86_SSA__Block)i0;
          goto l16;
l3:
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6208)))), &_td_OOC_X86_SSA__GateInstrDesc, 6208)), 6218))+48);
          merge = (OOC_X86_SSA__Block)i2;
          i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 6246)))), &_td_OOC_X86_SSA__MergeInstrDesc);
          if (i3) goto l14;
          i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 6345)))), &_td_OOC_X86_SSA__LoopStartInstrDesc);
          if (i3) goto l8;
          _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 6338)))), 6338);
          goto l16;
l8:
          i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 6395));
          i0 = i0==i1;
          if (i0) goto l11;
          return (OOC_X86_SSA__Block)i2;
          goto l16;
l11:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 6437))+40);
          return (OOC_X86_SSA__Block)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6445)))), &_td_OOC_X86_SSA__BlockDesc, 6445));
          goto l16;
l14:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 6288))+56);
          i1 = _check_pointer(i1, 6294);
          i0 = OOC_X86_SSA__OpndDesc_OpndIndex((OOC_X86_SSA__Opnd)i0);
          i2 = OOC_ARRAY_LENGTH(i1, 0);
          i0 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(i0, i2, OOC_UINT32, 6294))*4);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6312))+40);
          return (OOC_X86_SSA__Block)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6320)))), &_td_OOC_X86_SSA__BlockDesc, 6320));
l16:
          _failed_function(6006); return 0;
          ;
        }


      i0 = (OOC_INT32)instr;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6634))+40);
      i1 = i1!=(OOC_INT32)0;
      if (i1) goto l45;
      i1 = *(OOC_INT8*)((_check_pointer(i0, 6708))+20);
      i1 = i1==38;
      if (i1) goto l43;
      block = (OOC_X86_SSA__Block)(OOC_INT32)0;
      i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_Results((OOC_X86_SSA__Instr)i0);
      i1 = (OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG(i0)), OOC_X86_SSA__IterInstrResultsDesc_Next);
      i2 = OOC_TBCALL(i1,OOC_X86_SSA__IterInstrResultsDesc_Next)((OOC_X86_SSA__IterInstrResults)i0, (void*)(OOC_INT32)&res);
      if (i2) goto l7;
      i0=(OOC_INT32)0;
      goto l25;
l7:
      i2=(OOC_INT32)0;
l8_loop:
      i3 = (OOC_INT32)res;
      i3 = (OOC_INT32)OOC_X86_SSA__ResultDesc_Uses((OOC_X86_SSA__Result)i3);
      i4 = (OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG(i3)), OOC_X86_SSA__IterResultUsesDesc_Next);
      i5 = OOC_TBCALL(i4,OOC_X86_SSA__IterResultUsesDesc_Next)((OOC_X86_SSA__IterResultUses)i3, (void*)(OOC_INT32)&use);
      if (!i5) goto l20;
l11_loop:
      i2 = (OOC_INT32)use;
      i2 = (OOC_INT32)OOC_X86_Block__ArrangeInstructions_GetBlock_BlockOfUse((OOC_X86_SSA__Opnd)i2);
      useBlock = (OOC_X86_SSA__Block)i2;
      i5 = (OOC_INT32)block;
      i6 = i5==(OOC_INT32)0;
      if (i6) goto l14;
      i2 = (OOC_INT32)OOC_X86_Block__ArrangeInstructions_GetBlock_Merge((OOC_X86_SSA__Block)i5, (OOC_X86_SSA__Block)i2);
      block = (OOC_X86_SSA__Block)i2;
      
      goto l15;
l14:
      block = (OOC_X86_SSA__Block)i2;
      
l15:
      i5 = OOC_TBCALL(i4,OOC_X86_SSA__IterResultUsesDesc_Next)((OOC_X86_SSA__IterResultUses)i3, (void*)(OOC_INT32)&use);
      if (i5) goto l11_loop;
l20:
      i3 = OOC_TBCALL(i1,OOC_X86_SSA__IterInstrResultsDesc_Next)((OOC_X86_SSA__IterInstrResults)i0, (void*)(OOC_INT32)&res);
      if (i3) goto l8_loop;
l24:
      i0=i2;
l25:
      i1 = (OOC_INT32)instr;
      i1 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AfterList((OOC_X86_SSA__Instr)i1, (-1));
      i2 = (OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG(i1)), OOC_X86_SSA__IterInstrAfterListDesc_Next);
      i3 = OOC_TBCALL(i2,OOC_X86_SSA__IterInstrAfterListDesc_Next)((OOC_X86_SSA__IterInstrAfterList)i1, (void*)(OOC_INT32)&dep);
      if (!i3) goto l38;
l29_loop:
      i3 = (OOC_INT32)dep;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 7281))+12);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 7287))+16);
      useBlock = (OOC_X86_SSA__Block)i3;
      i4 = i0==(OOC_INT32)0;
      if (i4) goto l32;
      i0 = (OOC_INT32)OOC_X86_Block__ArrangeInstructions_GetBlock_Merge((OOC_X86_SSA__Block)i0, (OOC_X86_SSA__Block)i3);
      block = (OOC_X86_SSA__Block)i0;
      
      goto l33;
l32:
      block = (OOC_X86_SSA__Block)i3;
      i0=i3;
l33:
      i3 = OOC_TBCALL(i2,OOC_X86_SSA__IterInstrAfterListDesc_Next)((OOC_X86_SSA__IterInstrAfterList)i1, (void*)(OOC_INT32)&dep);
      if (i3) goto l29_loop;
l38:
      i1 = i0==(OOC_INT32)0;
      if (!i1) goto l46;
      i0 = (OOC_INT32)fctBlock;
      
      goto l46;
l43:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6817)))), &_td_OOC_X86_SSA__GateInstrDesc, 6817)), 6827))+48);
      _assert((i1!=(OOC_INT32)0), 127, 6802);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6867)))), &_td_OOC_X86_SSA__GateInstrDesc, 6867)), 6877))+48);
      
      goto l46;
l45:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6674))+40);
      i0 = _type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6682)))), &_td_OOC_X86_SSA__BlockDesc, 6682);
      
l46:
      return (OOC_X86_SSA__Block)i0;
      ;
    }

    
    void OOC_X86_Block__ArrangeInstructions_ClearBlock(OOC_X86_SSA__Block b) {
      register OOC_INT32 i0,i1,i2,i3,i4;
      OOC_X86_SSA__Instr instr;

      i0 = (OOC_INT32)b;
      i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_Instructions((OOC_X86_SSA__Block)i0);
      i2 = (OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG(i1)), OOC_X86_SSA__IterBlockInstructionsDesc_Next);
      i3 = OOC_TBCALL(i2,OOC_X86_SSA__IterBlockInstructionsDesc_Next)((OOC_X86_SSA__IterBlockInstructions)i1, (void*)(OOC_INT32)&instr);
      if (!i3) goto l11;
l3_loop:
      i3 = (OOC_INT32)instr;
      i4 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 7710)))), &_td_OOC_X86_SSA__BlockDesc);
      if (!i4) goto l6;
      OOC_X86_Block__ArrangeInstructions_ClearBlock((OOC_X86_SSA__Block)i3);
l6:
      OOC_X86_SSA__BlockDesc_RemoveAll((OOC_X86_SSA__Block)i0);
      i3 = OOC_TBCALL(i2,OOC_X86_SSA__IterBlockInstructionsDesc_Next)((OOC_X86_SSA__IterBlockInstructions)i1, (void*)(OOC_INT32)&instr);
      if (i3) goto l3_loop;
l11:
      return;
      ;
    }

    
    void OOC_X86_Block__ArrangeInstructions_SortBlock(OOC_X86_SSA__Block b) {
      register OOC_INT32 i0,i1,i2,i3,i4;
      OOC_X86_SSA__Instr instr;

      i0 = (OOC_INT32)b;
      i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_Instructions((OOC_X86_SSA__Block)i0);
      i1 = (OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG(i0)), OOC_X86_SSA__IterBlockInstructionsDesc_Next);
      i2 = OOC_TBCALL(i1,OOC_X86_SSA__IterBlockInstructionsDesc_Next)((OOC_X86_SSA__IterBlockInstructions)i0, (void*)(OOC_INT32)&instr);
      if (!i2) goto l22;
l3_loop:
      i2 = (OOC_INT32)instr;
      i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 7991)))), &_td_OOC_X86_SSA__BlockDesc);
      if (i3) goto l13;
      i3 = *(OOC_INT8*)((_check_pointer(i2, 8198))+20);
      i3 = i3==38;
      if (i3) goto l8;
      i3 = *(OOC_INT8*)((_check_pointer(i2, 8225))+20);
      i3 = i3==17;
      
      goto l10;
l8:
      i3=1u;
l10:
      if (!i3) goto l17;
      OOC_X86_SSA__InstrDesc_MoveToFront((OOC_X86_SSA__Instr)i2);
      goto l17;
l13:
      i3 = *(OOC_INT8*)((_check_pointer(i2, 8023))+20);
      i3 = i3==40;
      if (!i3) goto l16;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 8101)))), &_td_OOC_X86_SSA__LoopStartInstrDesc, 8101)), 8116))+60);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 8068))+16);
      OOC_X86_SSA__BlockDesc_MoveBehind((OOC_X86_SSA__Block)i4, (OOC_X86_SSA__Instr)i2, (OOC_X86_SSA__Instr)i3);
l16:
      i2 = (OOC_INT32)instr;
      OOC_X86_Block__ArrangeInstructions_SortBlock((OOC_X86_SSA__Block)i2);
l17:
      i2 = OOC_TBCALL(i1,OOC_X86_SSA__IterBlockInstructionsDesc_Next)((OOC_X86_SSA__IterBlockInstructions)i0, (void*)(OOC_INT32)&instr);
      if (i2) goto l3_loop;
l22:
      return;
      ;
    }


  i0 = (OOC_INT32)fctBlock;
  OOC_X86_SSA__BlockDesc_SetMarkers((OOC_X86_SSA__Block)i0, (OOC_X86_SSA__Node)(OOC_INT32)0, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8542))+60);
  i0 = (OOC_INT32)OOC_X86_Block__ArrangeInstructions_InflateControlFlow((OOC_X86_SSA__Block)i0, (OOC_X86_SSA__Instr)i1);
  dummy = (OOC_X86_SSA__MergeInstr)i0;
  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Block.baseTypes[0]);
  OOC_X86_SSA__BlockDesc_INIT((OOC_X86_SSA__Block)i0, (-1));
  ready = (OOC_X86_SSA__Block)i0;
  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Block.baseTypes[0]);
  OOC_X86_SSA__BlockDesc_INIT((OOC_X86_SSA__Block)i0, (-1));
  waiting = (OOC_X86_SSA__Block)i0;
  i0 = (OOC_INT32)fctBlock;
  OOC_X86_Block__ArrangeInstructions_SetUseCount((OOC_X86_SSA__Block)i0);
  i0 = (OOC_INT32)fctBlock;
  OOC_X86_Block__ArrangeInstructions_ClearBlock((OOC_X86_SSA__Block)i0);
  i0 = (OOC_INT32)ready;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9067))+48);
  i1 = i1!=(OOC_INT32)0;
  if (!i1) goto l8;
l3_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9108))+48);
  instr = (OOC_X86_SSA__Instr)i1;
  OOC_X86_SSA__BlockDesc_Remove((OOC_X86_SSA__Block)i0, (OOC_X86_SSA__Instr)i1);
  OOC_X86_Block__ArrangeInstructions_UpdateDefs((OOC_X86_SSA__Instr)i1);
  i0 = (OOC_INT32)instr;
  i0 = (OOC_INT32)OOC_X86_Block__ArrangeInstructions_GetBlock((OOC_X86_SSA__Instr)i0);
  block = (OOC_X86_SSA__Block)i0;
  i1 = (OOC_INT32)instr;
  OOC_X86_SSA__BlockDesc_AddInFront((OOC_X86_SSA__Block)i0, (OOC_X86_SSA__Instr)i1);
  i0 = (OOC_INT32)ready;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9067))+48);
  i1 = i1!=(OOC_INT32)0;
  if (i1) goto l3_loop;
l8:
  i0 = (OOC_INT32)waiting;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9259))+48);
  i1 = i1!=(OOC_INT32)0;
  if (!i1) goto l19;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9301))+48);
  instr = (OOC_X86_SSA__Instr)i1;
  i2 = i1!=(OOC_INT32)0;
  if (!i2) goto l19;
l13_loop:
  i2 = (OOC_INT32)OOC_X86_Debug__Label((OOC_X86_SSA__Node)i1);
  Log__Object("waiting", 8, (Object__Object)i2);
  i2 = *(OOC_INT32*)((_check_pointer(i1, 9422))+44);
  Log__Int("  marker", 9, i2);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 9454))+8);
  instr = (OOC_X86_SSA__Instr)i1;
  i2 = i1!=(OOC_INT32)0;
  if (i2) goto l13_loop;
l19:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9504))+48);
  _assert((i0==(OOC_INT32)0), 127, 9490);
  i0 = (OOC_INT32)fctBlock;
  OOC_X86_Block__ArrangeInstructions_SortBlock((OOC_X86_SSA__Block)i0);
  return;
  ;
}

void OOC_OOC_X86_Block_init(void) {

  return;
  ;
}

/* --- */
