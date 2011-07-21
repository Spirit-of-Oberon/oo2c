#include <OOC/SSA/LoopRewrite.d>
#include <__oo2c.h>
#include <setjmp.h>

static void OOC_SSA_LoopRewrite__InitSum(OOC_SSA_LoopRewrite__Sum sum, OOC_INT8 subclass, OOC_SSA__Result atom) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)sum;
  OOC_SSA__InitNode((OOC_SSA__Node)i0);
  i1 = subclass;
  *(OOC_INT8*)(_check_pointer(i0, 6574)) = i1;
  i1 = (OOC_INT32)atom;
  *(OOC_INT32*)((_check_pointer(i0, 6604))+4) = i1;
  i1 = i1!=0;
  if (i1) goto l3;
  *(OOC_INT32*)((_check_pointer(i0, 6707))+8) = 0;
  goto l4;
l3:
  i1 = OOC_SSA_LoopRewrite__idCount;
  *(OOC_INT32*)((_check_pointer(i0, 6653))+8) = i1;
  OOC_SSA_LoopRewrite__idCount = (i1+1);
l4:
  *(OOC_INT32*)((_check_pointer(i0, 6738))+16) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 6757))+20) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 6783))+24) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 6814))+28) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 6840))+32) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 6865))+36) = 0;
  *(OOC_UINT8*)((_check_pointer(i0, 6893))+12) = 0u;
  *(OOC_INT8*)((_check_pointer(i0, 6932))+40) = (-1);
  return;
  ;
}

static void OOC_SSA_LoopRewrite__InitCycleElement(OOC_SSA_LoopRewrite__CycleElement ce, OOC_SSA_LoopRewrite__InductionCycle ic, OOC_SSA__Result res) {
  register OOC_INT32 i0,i1,i2;
  OOC_SSA_LoopRewrite__CycleElement ptr;
  OOC_INT32 i;

  i0 = (OOC_INT32)res;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 7147))+5);
  i2 = (OOC_INT32)ce;
  OOC_SSA_LoopRewrite__InitSum((OOC_SSA_LoopRewrite__Sum)i2, i1, (OOC_SSA__Result)i0);
  *(OOC_INT32*)((_check_pointer(i2, 7199))+16) = i2;
  i1 = (OOC_INT32)OOC_SSA_LoopRewrite__one;
  *(OOC_INT32*)((_check_pointer(i2, 7216))+20) = i1;
  *(OOC_INT32*)((_check_pointer(i2, 7245))+48) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i2, 7265))+52) = i0;
  i0 = (OOC_INT32)ic;
  i1 = i0==(OOC_INT32)0;
  if (i1) goto l12;
  *(OOC_INT32*)((_check_pointer(i2, 7372))+60) = i0;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 7401))+84);
  *(OOC_INT32*)((_check_pointer(i2, 7391))+56) = i1;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 7427))+84);
  *(OOC_INT32*)((_check_pointer(i0, 7427))+84) = (i1+1);
  ptr = (OOC_SSA_LoopRewrite__CycleElement)i0;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7482))+48);
  i1 = i1!=(OOC_INT32)0;
  if (!i1) goto l11;
l6_loop:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7516))+48);
  ptr = (OOC_SSA_LoopRewrite__CycleElement)i0;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7482))+48);
  i1 = i1!=(OOC_INT32)0;
  if (i1) goto l6_loop;
l11:
  *(OOC_INT32*)((_check_pointer(i0, 7543))+48) = i2;
  goto l13;
l12:
  *(OOC_INT32*)((_check_pointer(i2, 7309))+56) = 0;
  *(OOC_INT32*)((_check_pointer(i2, 7328))+60) = (_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 7338)))), &_td_OOC_SSA_LoopRewrite__InductionCycleDesc, 7338));
l13:
  i = 0;
  i0=0;
l14_loop:
  *(OOC_INT32*)(((_check_pointer(i2, 7604))+64)+(_check_index(i0, 5, OOC_UINT32, 7613))*4) = 0;
  i0 = i0+1;
  i = i0;
  i1 = i0<=4;
  if (i1) goto l14_loop;
l18:
  *(OOC_INT32*)((_check_pointer(i2, 7638))+44) = (OOC_INT32)0;
  return;
  ;
}

static void OOC_SSA_LoopRewrite__InitInductionCycle(OOC_SSA_LoopRewrite__InductionCycle ic, OOC_SSA__Result res) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)res;
  i1 = (OOC_INT32)ic;
  OOC_SSA_LoopRewrite__InitCycleElement((OOC_SSA_LoopRewrite__CycleElement)i1, (OOC_SSA_LoopRewrite__InductionCycle)(OOC_INT32)0, (OOC_SSA__Result)i0);
  *(OOC_INT32*)((_check_pointer(i1, 7801))+84) = 1;
  *(OOC_INT32*)((_check_pointer(i1, 7880))+88) = (OOC_INT32)0;
  return;
  ;
}

static void OOC_SSA_LoopRewrite__Classify(OOC_SSA__ProcBlock pb, OOC_SSA__Instr loopStart) {
  register OOC_INT32 i0,i1,i2;
  OOC_SSA_LoopRewrite__Worklist worklist;
  OOC_SSA__Result res;
  OOC_SSA__Instr instr;
  auto void OOC_SSA_LoopRewrite__Classify_UpdateMarker(OOC_SSA__Result res, OOC_INT32 newMarker);
  auto void OOC_SSA_LoopRewrite__Classify_UpdateMarkers(OOC_SSA__Instr instr, OOC_INT32 newMarker);
  auto void OOC_SSA_LoopRewrite__Classify_UpdateMarker(OOC_SSA__Result res, OOC_INT32 newMarker);
  auto void OOC_SSA_LoopRewrite__Classify_ClassifyInstr(OOC_SSA__Instr instr);
    
    void OOC_SSA_LoopRewrite__Classify_UpdateMarkers(OOC_SSA__Instr instr, OOC_INT32 newMarker) {
      register OOC_INT32 i0,i1,i2;
      OOC_SSA__Result res;

      i0 = (OOC_INT32)instr;
      res = (OOC_SSA__Result)i0;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l8;
      i1 = newMarker;
      
l3_loop:
      OOC_SSA_LoopRewrite__Classify_UpdateMarker((OOC_SSA__Result)i0, i1);
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 10753));
      res = (OOC_SSA__Result)i0;
      i2 = i0!=(OOC_INT32)0;
      if (i2) goto l3_loop;
l8:
      return;
      ;
    }

    
    void OOC_SSA_LoopRewrite__Classify_UpdateMarker(OOC_SSA__Result res, OOC_INT32 newMarker) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_SSA__Opnd use;
      OOC_SSA__Instr useInstr;
      OOC_SSA_LoopRewrite__Worklist wl;

      i0 = newMarker;
      _assert((i0>0), 127, 11100);
      i1 = (OOC_INT32)res;
      i2 = *(OOC_INT32*)((_check_pointer(i1, 11152))+20);
      i2 = i0>(_abs(i2));
      if (!i2) goto l18;
      i2 = *(OOC_INT32*)((_check_pointer(i1, 11182))+20);
      i2 = i2<0;
      if (i2) goto l5;
      *(OOC_INT32*)((_check_pointer(i1, 11297))+20) = i0;
      goto l6;
l5:
      *(OOC_INT32*)((_check_pointer(i1, 11248))+20) = (-i0);
l6:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11351))+12);
      use = (OOC_SSA__Opnd)i0;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l18;
l9_loop:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11416))+12);
      useInstr = (OOC_SSA__Instr)i1;
      i2 = *(OOC_INT32*)((_check_pointer(i1, 11447))+20);
      i2 = i2>0;
      if (!i2) goto l12;
      i2 = *(OOC_INT32*)((_check_pointer(i1, 11533))+20);
      *(OOC_INT32*)((_check_pointer(i1, 11513))+20) = (-i2);
      i2 = (OOC_INT32)RT0__NewObject(_td_OOC_SSA_LoopRewrite__Worklist.baseTypes[0]);
      wl = (OOC_SSA_LoopRewrite__Worklist)i2;
      i3 = (OOC_INT32)worklist;
      *(OOC_INT32*)(_check_pointer(i2, 11578)) = i3;
      *(OOC_INT32*)((_check_pointer(i2, 11611))+4) = i1;
      worklist = (OOC_SSA_LoopRewrite__Worklist)i2;
l12:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11694))+16);
      use = (OOC_SSA__Opnd)i0;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l9_loop;
l18:
      return;
      ;
    }

    
    void OOC_SSA_LoopRewrite__Classify_ClassifyInstr(OOC_SSA__Instr instr) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
      OOC_INT32 marker;
      OOC_SSA__Instr gate;
      OOC_SSA__Result res;
      OOC_SSA__Opnd opnd;
      OOC_INT32 min;
      OOC_INT32 opndIndex;
      OOC_INT32 max;
      OOC_SSA__Opnd next;
      OOC_INT32 m;

      i0 = (OOC_INT32)instr;
      i1 = *(OOC_INT8*)((_check_pointer(i0, 11952))+36);
      switch (i1) {
      case 19:
      case 20:
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12027))+24);
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12036))+8);
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 12045));
        i1 = *(OOC_INT32*)((_check_pointer(i1, 12049))+20);
        i1 = _abs(i1);
        marker = i1;
        i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12080))+24);
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 12089));
        i2 = *(OOC_INT32*)((_check_pointer(i2, 12093))+20);
        i2 = (_abs(i2))>i1;
        if (!i2) goto l6;
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12146))+24);
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 12155));
        i1 = *(OOC_INT32*)((_check_pointer(i1, 12159))+20);
        i1 = _abs(i1);
        
l6:
        OOC_SSA_LoopRewrite__Classify_UpdateMarkers((OOC_SSA__Instr)i0, i1);
        goto l55;
      case 42:
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12339))+24);
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 12348));
        i1 = *(OOC_INT32*)((_check_pointer(i1, 12352))+20);
        OOC_SSA_LoopRewrite__Classify_UpdateMarkers((OOC_SSA__Instr)i0, (_abs(i1)));
        goto l55;
      case 6:
        OOC_SSA_LoopRewrite__Classify_UpdateMarker((OOC_SSA__Result)i0, 3);
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 12451));
        OOC_SSA_LoopRewrite__Classify_UpdateMarker((OOC_SSA__Result)i1, 3);
        i1 = (OOC_INT32)OOC_SSA__InstrDesc_GetCollectTarget((OOC_SSA__Instr)i0);
        gate = (OOC_SSA__Instr)i1;
        i2 = (OOC_INT32)loopStart;
        i2 = i1==i2;
        if (i2) goto l11;
        i2 = *(OOC_INT8*)((_check_pointer(i1, 12573))+36);
        i2 = i2!=10;
        
        goto l13;
l11:
        i2=1u;
l13:
        if (!i2) goto l55;
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 12720));
        res = (OOC_SSA__Result)i1;
        i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12756))+24);
        opnd = (OOC_SSA__Opnd)i2;
        i3 = i1!=0;
        if (!i3) goto l22;
        {register OOC_INT32 h0=i1;i1=i2;i2=h0;}
l17_loop:
        i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 12951));
        i3 = *(OOC_INT32*)((_check_pointer(i3, 12955))+20);
        OOC_SSA_LoopRewrite__Classify_UpdateMarker((OOC_SSA__Result)i2, (_abs(i3)));
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 12988));
        res = (OOC_SSA__Result)i2;
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 13025))+8);
        opnd = (OOC_SSA__Opnd)i1;
        i3 = i2!=0;
        if (i3) goto l17_loop;
l22:
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13101))+24);
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 13110));
        i1 = *(OOC_INT32*)((_check_pointer(i1, 13114))+20);
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 13079));
        OOC_SSA_LoopRewrite__Classify_UpdateMarker((OOC_SSA__Result)i0, (_abs(i1)));
        goto l55;
      case 5:
        OOC_SSA_LoopRewrite__Classify_UpdateMarker((OOC_SSA__Result)i0, 3);
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13229))+24);
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 13238));
        i1 = *(OOC_INT32*)((_check_pointer(i1, 13242))+20);
        i1 = (_abs(i1))!=1;
        if (i1) goto l27;
        min = 1;
        i1=1;
        goto l28;
l27:
        min = 2;
        i1=2;
l28:
        opndIndex = 0;
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 13520));
        res = (OOC_SSA__Result)i2;
        i3 = i2!=0;
        if (!i3) goto l55;
        i3=i2;i2=0;
l31_loop:
        max = i1;
        i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13618))+24);
        i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 13627))+8);
        opnd = (OOC_SSA__Opnd)i4;
        i5 = i4!=0;
        if (i5) goto l34;
        i4=i1;
        goto l48;
l34:
        i5=i1;
l35_loop:
        i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 13694))+8);
        opnd = (OOC_SSA__Opnd)i4;
        i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 13729))+8);
        next = (OOC_SSA__Opnd)i6;
        i7 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 13761));
        i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i7, 13765))+8);
        i7 = *(OOC_INT8*)((_check_pointer(i7, 13771))+36);
        i7 = i7==6;
        if (!i7) goto l39;
        i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 13828));
        i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 13832))+8);
        i4 = (OOC_INT32)OOC_SSA__InstrDesc_NthOpnd((OOC_SSA__Instr)i4, i2);
        opnd = (OOC_SSA__Opnd)i4;
        
l39:
        i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 13901));
        i4 = *(OOC_INT32*)((_check_pointer(i4, 13905))+20);
        i4 = _abs(i4);
        m = i4;
        i7 = i4>i5;
        if (i7) goto l42;
        i4=i5;
        goto l43;
l42:
        max = i4;
        
l43:
        opnd = (OOC_SSA__Opnd)i6;
        i5 = i6!=0;
        if (!i5) goto l48;
        i5=i4;i4=i6;
        goto l35_loop;
l48:
        OOC_SSA_LoopRewrite__Classify_UpdateMarker((OOC_SSA__Result)i3, i4);
        i2 = i2+1;
        opndIndex = i2;
        i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 14121));
        res = (OOC_SSA__Result)i3;
        i4 = i3!=0;
        if (i4) goto l31_loop;
        goto l55;
      default:
        OOC_SSA_LoopRewrite__Classify_UpdateMarkers((OOC_SSA__Instr)i0, 3);
        goto l55;
      }
l55:
      return;
      ;
    }


  i0 = (OOC_INT32)pb;
  OOC_SSA__ProcBlockDesc_SetMarkers((OOC_SSA__ProcBlock)i0, (OOC_SSA__Node)(OOC_INT32)0, 1);
  worklist = (OOC_SSA_LoopRewrite__Worklist)(OOC_INT32)0;
  i0 = (OOC_INT32)loopStart;
  OOC_SSA_LoopRewrite__Classify_UpdateMarker((OOC_SSA__Result)i0, 3);
  i0 = (OOC_INT32)loopStart;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 14473));
  res = (OOC_SSA__Result)i0;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l8;
l3_loop:
  OOC_SSA_LoopRewrite__Classify_UpdateMarker((OOC_SSA__Result)i0, 2);
  i0 = (OOC_INT32)res;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 14570));
  res = (OOC_SSA__Result)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l3_loop;
l8:
  i0 = (OOC_INT32)worklist;
  i0 = i0!=(OOC_INT32)0;
  if (!i0) goto l16;
l11_loop:
  i0 = (OOC_INT32)worklist;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14691))+4);
  instr = (OOC_SSA__Instr)i1;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 14718))+20);
  _assert((i2<0), 127, 14706);
  i2 = *(OOC_INT32*)((_check_pointer(i1, 14760))+20);
  *(OOC_INT32*)((_check_pointer(i1, 14743))+20) = (-i2);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 14795));
  worklist = (OOC_SSA_LoopRewrite__Worklist)i0;
  OOC_SSA_LoopRewrite__Classify_ClassifyInstr((OOC_SSA__Instr)i1);
  i0 = (OOC_INT32)worklist;
  i0 = i0!=(OOC_INT32)0;
  if (i0) goto l11_loop;
l16:
  return;
  ;
}

static void OOC_SSA_LoopRewrite__FindInductiveCycles(OOC_SSA__Instr loopStart) {
  register OOC_INT32 i0,i1,i2;
  OOC_SSA__Instr loopEnd;
  OOC_INT32 count;
  OOC_SSA__Result res;
  OOC_SSA_LoopRewrite__InductionCycle ic;
  OOC_SSA__Opnd opnd;
  OOC_SSA_LoopRewrite__CycleElement ce;
  auto OOC_SSA_LoopRewrite__InductionCycle OOC_SSA_LoopRewrite__FindInductiveCycles_NewInductionCycle(OOC_SSA__Result head);
  auto void OOC_SSA_LoopRewrite__FindInductiveCycles_AddInductionValue(OOC_SSA_LoopRewrite__InductionCycle ic, OOC_SSA__Result res);
  auto OOC_CHAR8 OOC_SSA_LoopRewrite__FindInductiveCycles_SearchCycle(OOC_SSA__Result res, OOC_SSA__Result head, OOC_SSA_LoopRewrite__InductionCycle ic);
    
    OOC_SSA_LoopRewrite__InductionCycle OOC_SSA_LoopRewrite__FindInductiveCycles_NewInductionCycle(OOC_SSA__Result head) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)RT0__NewObject(_td_OOC_SSA_LoopRewrite__InductionCycle.baseTypes[0]);
      i1 = (OOC_INT32)head;
      OOC_SSA_LoopRewrite__InitInductionCycle((OOC_SSA_LoopRewrite__InductionCycle)i0, (OOC_SSA__Result)i1);
      return (OOC_SSA_LoopRewrite__InductionCycle)i0;
      ;
    }

    
    void OOC_SSA_LoopRewrite__FindInductiveCycles_AddInductionValue(OOC_SSA_LoopRewrite__InductionCycle ic, OOC_SSA__Result res) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)res;
      i1 = (OOC_INT32)ic;
      OOC_SSA_LoopRewrite__InitCycleElement((OOC_SSA_LoopRewrite__CycleElement)((OOC_INT32)RT0__NewObject(_td_OOC_SSA_LoopRewrite__CycleElement.baseTypes[0])), (OOC_SSA_LoopRewrite__InductionCycle)i1, (OOC_SSA__Result)i0);
      return;
      ;
    }

    
    OOC_CHAR8 OOC_SSA_LoopRewrite__FindInductiveCycles_SearchCycle(OOC_SSA__Result res, OOC_SSA__Result head, OOC_SSA_LoopRewrite__InductionCycle ic) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
      OOC_CHAR8 onCycle;
      OOC_SSA__Opnd opnd;
      OOC_INT32 resIndex;
      OOC_SSA__Result arg;

      i0 = (OOC_INT32)res;
      i1 = (OOC_INT32)head;
      i2 = i0==i1;
      if (i2) goto l47;
      i2 = *(OOC_INT32*)((_check_pointer(i0, 15839))+20);
      i2 = i2==2;
      if (i2) goto l5;
      return 0u;
      goto l48;
l5:
      onCycle = 0u;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15923))+8);
      i2 = *(OOC_INT8*)((_check_pointer(i2, 15929))+36);
      switch (i2) {
      case 19:
      case 20:
        i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16000))+8);
        i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 16006))+24);
        opnd = (OOC_SSA__Opnd)i2;
        i3 = i2!=(OOC_INT32)0;
        if (i3) goto l10;
        i1=0u;
        goto l43;
l10:
        i3 = (OOC_INT32)ic;
        i4=0u;
l11_loop:
        i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 16080));
        i5 = OOC_SSA_LoopRewrite__FindInductiveCycles_SearchCycle((OOC_SSA__Result)i5, (OOC_SSA__Result)i1, (OOC_SSA_LoopRewrite__InductionCycle)i3);
        if (!i5) goto l15;
        onCycle = 1u;
        i4=1u;
l15:
        i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 16173))+8);
        opnd = (OOC_SSA__Opnd)i2;
        i5 = i2!=(OOC_INT32)0;
        if (i5) goto l11_loop;
l19:
        i1=i4;
        goto l43;
      case 5:
        i2 = OOC_SSA__ResultDesc_ResultIndex((OOC_SSA__Result)i0);
        resIndex = i2;
        i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16308))+8);
        i3 = (OOC_INT32)OOC_SSA__InstrDesc_NthOpnd((OOC_SSA__Instr)i3, 1);
        opnd = (OOC_SSA__Opnd)i3;
        i4 = i3!=(OOC_INT32)0;
        if (i4) goto l24;
        i1=0u;
        goto l43;
l24:
        i2 = i2-1;
        i4 = (OOC_INT32)ic;
        i5=0u;
l25_loop:
        i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 16383))+8);
        opnd = (OOC_SSA__Opnd)i3;
        i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 16414));
        i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 16418))+8);
        i6 = *(OOC_INT8*)((_check_pointer(i6, 16424))+36);
        i6 = i6==6;
        if (i6) goto l28;
        i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 16553));
        arg = (OOC_SSA__Result)i6;
        
        goto l29;
l28:
        i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 16480));
        i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 16484))+8);
        i6 = (OOC_INT32)OOC_SSA__InstrDesc_NthArg((OOC_SSA__Instr)i6, i2);
        arg = (OOC_SSA__Result)i6;
        
l29:
        i6 = OOC_SSA_LoopRewrite__FindInductiveCycles_SearchCycle((OOC_SSA__Result)i6, (OOC_SSA__Result)i1, (OOC_SSA_LoopRewrite__InductionCycle)i4);
        if (!i6) goto l33;
        onCycle = 1u;
        i5=1u;
l33:
        i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 16695))+8);
        opnd = (OOC_SSA__Opnd)i3;
        i6 = i3!=(OOC_INT32)0;
        if (i6) goto l25_loop;
l37:
        i1=i5;
        goto l43;
      case 42:
        i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16785))+8);
        i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 16791))+24);
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 16800));
        i3 = (OOC_INT32)ic;
        i1 = OOC_SSA_LoopRewrite__FindInductiveCycles_SearchCycle((OOC_SSA__Result)i2, (OOC_SSA__Result)i1, (OOC_SSA_LoopRewrite__InductionCycle)i3);
        
        goto l43;
      case 10:
        i1=0u;
        goto l43;
      default:
        _failed_case(i2, 15915);
        i1=0u;
        goto l43;
      }
l43:
      if (!i1) goto l45;
      i2 = (OOC_INT32)ic;
      OOC_SSA_LoopRewrite__FindInductiveCycles_AddInductionValue((OOC_SSA_LoopRewrite__InductionCycle)i2, (OOC_SSA__Result)i0);
l45:
      return i1;
      goto l48;
l47:
      return 1u;
l48:
      _failed_function(15598); return 0;
      ;
    }


  i0 = (OOC_INT32)loopStart;
  i1 = (OOC_INT32)OOC_SSA__InstrDesc_GetLoopEnd((OOC_SSA__Instr)i0);
  loopEnd = (OOC_SSA__Instr)i1;
  count = 1;
  i0 = (OOC_INT32)OOC_SSA__InstrDesc_NthResult((OOC_SSA__Instr)i0, 2);
  res = (OOC_SSA__Result)i0;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l22;
  
l3_loop:
  i1 = *(OOC_INT32*)((_check_pointer(i0, 17318))+20);
  i1 = i1==2;
  if (!i1) goto l17;
  i0 = (OOC_INT32)OOC_SSA_LoopRewrite__FindInductiveCycles_NewInductionCycle((OOC_SSA__Result)i0);
  ic = (OOC_SSA_LoopRewrite__InductionCycle)i0;
  i1 = (OOC_INT32)loopEnd;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 17420))+24);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 17429))+8);
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 17438));
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 17442))+8);
  i2 = *(OOC_INT8*)((_check_pointer(i2, 17448))+36);
  _assert((i2==6), 127, 17406);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 17498))+24);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 17507))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 17516));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 17520))+8);
  i2 = count;
  i1 = (OOC_INT32)OOC_SSA__InstrDesc_NthOpnd((OOC_SSA__Instr)i1, i2);
  opnd = (OOC_SSA__Opnd)i1;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 17570));
  i2 = (OOC_INT32)res;
  i0 = OOC_SSA_LoopRewrite__FindInductiveCycles_SearchCycle((OOC_SSA__Result)i1, (OOC_SSA__Result)i2, (OOC_SSA_LoopRewrite__InductionCycle)i0);
  if (!i0) goto l17;
  i0 = (OOC_INT32)ic;
  ce = (OOC_SSA_LoopRewrite__CycleElement)i0;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l17;
l10_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17654))+52);
  *(OOC_INT32*)((_check_pointer(i1, 17658))+16) = i0;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17691))+48);
  ce = (OOC_SSA_LoopRewrite__CycleElement)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l10_loop;
l17:
  i0 = (OOC_INT32)res;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 17825));
  i1 = count;
  res = (OOC_SSA__Result)i0;
  count = (i1+1);
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l3_loop;
l22:
  return;
  ;
}

static OOC_INT32 OOC_SSA_LoopRewrite__Cmp(OOC_SSA_LoopRewrite__Product a, OOC_SSA_LoopRewrite__Product b) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT32 i;

  i0 = (OOC_INT32)a;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17975))+4);
  i2 = (OOC_INT32)b;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 17993))+4);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 17983)), 0);
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 18001)), 0);
  i1 = i1==i3;
  if (i1) goto l3;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18266))+4);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 18284))+4);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 18292)), 0);
  i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 18274)), 0);
  return (i0-i1);
  goto l16;
l3:
  i = 0;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18046))+4);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 18054)), 0);
  i1 = 0!=i1;
  if (!i1) goto l15;
  i1=0;
l6_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18074))+4);
  i3 = _check_pointer(i3, 18082);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i1, i4, OOC_UINT32, 18082))*4);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 18092))+4);
  i4 = _check_pointer(i4, 18100);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i1, i5, OOC_UINT32, 18100))*4);
  i3 = *(OOC_INT32*)((_check_pointer(i3, 18085))+8);
  i4 = *(OOC_INT32*)((_check_pointer(i4, 18103))+8);
  i3 = i3!=i4;
  if (i3) goto l9;
  i1 = i1+1;
  i = i1;
  
  goto l10;
l9:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18132))+4);
  i3 = _check_pointer(i3, 18140);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i1, i4, OOC_UINT32, 18140))*4);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 18150))+4);
  i4 = _check_pointer(i4, 18158);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i1, i5, OOC_UINT32, 18158))*4);
  i3 = *(OOC_INT32*)((_check_pointer(i3, 18143))+8);
  i4 = *(OOC_INT32*)((_check_pointer(i4, 18161))+8);
  return (i3-i4);
  
l10:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18046))+4);
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 18054)), 0);
  i3 = i1!=i3;
  if (i3) goto l6_loop;
l15:
  return 0;
l16:
  _failed_function(17903); return 0;
  ;
}

static OOC_SSA_LoopRewrite__Sum OOC_SSA_LoopRewrite__NewSum(OOC_INT8 subclass, OOC_SSA__Result atom) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_SSA_LoopRewrite__Sum.baseTypes[0]);
  i1 = (OOC_INT32)atom;
  i2 = subclass;
  OOC_SSA_LoopRewrite__InitSum((OOC_SSA_LoopRewrite__Sum)i0, i2, (OOC_SSA__Result)i1);
  return (OOC_SSA_LoopRewrite__Sum)i0;
  ;
}

void OOC_SSA_LoopRewrite__Flatten(OOC_SSA__Result res) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_SSA_LoopRewrite__Sum sum;
  OOC_SSA__Instr instr;
  OOC_SSA__Opnd opnd;
  auto OOC_SSA_LoopRewrite__PList OOC_SSA_LoopRewrite__Flatten_ScalePList(OOC_SSA_LoopRewrite__PList a, OOC_INT32 b);
  auto OOC_SSA_LoopRewrite__PList OOC_SSA_LoopRewrite__Flatten_AddPLists(OOC_SSA_LoopRewrite__PList a, OOC_SSA_LoopRewrite__PList b, OOC_INT32 magnB);
  auto OOC_SSA_LoopRewrite__PList OOC_SSA_LoopRewrite__Flatten_MultProduct(OOC_SSA_LoopRewrite__Product a, OOC_SSA_LoopRewrite__PList b);
  auto OOC_SSA_LoopRewrite__Sum OOC_SSA_LoopRewrite__Flatten_AddSum(OOC_SSA_LoopRewrite__Sum a, OOC_SSA_LoopRewrite__Sum b, OOC_INT32 magnB);
  auto OOC_SSA_LoopRewrite__Sum OOC_SSA_LoopRewrite__Flatten_MultSum(OOC_SSA_LoopRewrite__Sum a, OOC_SSA_LoopRewrite__Sum b);
  auto OOC_SSA_LoopRewrite__PList OOC_SSA_LoopRewrite__Flatten_NewPList(OOC_SSA_LoopRewrite__Sum factor);
    
    OOC_SSA_LoopRewrite__PList OOC_SSA_LoopRewrite__Flatten_ScalePList(OOC_SSA_LoopRewrite__PList a, OOC_INT32 b) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
      OOC_SSA_LoopRewrite__PList c;
      OOC_INT32 i;

      i0 = b;
      i1 = i0==1;
      if (i1) goto l15;
      i1 = (OOC_INT32)a;
      i2 = i1==(OOC_INT32)0;
      if (i2) goto l13;
      i2 = (OOC_INT32)RT0__NewObject(_td_OOC_SSA_LoopRewrite__PList.baseTypes[0]);
      c = (OOC_SSA_LoopRewrite__PList)i2;
      i3 = *(OOC_INT32*)((_check_pointer(i1, 18859))+4);
      *(OOC_INT32*)(_check_pointer(i2, 18851)) = ((OOC_INT32)RT0__NewObject(_td_OOC_SSA_LoopRewrite__2903.baseTypes[0], i3));
      i3 = *(OOC_INT32*)((_check_pointer(i1, 18886))+4);
      *(OOC_INT32*)((_check_pointer(i2, 18876))+4) = i3;
      i = 0;
      i3 = *(OOC_INT32*)((_check_pointer(i1, 18916))+4);
      i4 = 0<i3;
      if (!i4) goto l12;
      i4=0;
l7_loop:
      i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 18942));
      i5 = _check_pointer(i5, 18947);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      *(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 18947))*4) = ((OOC_INT32)RT0__NewObject(_td_OOC_SSA_LoopRewrite__Product.baseTypes[0]));
      i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 18964));
      i5 = _check_pointer(i5, 18969);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 18969))*4);
      i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 18987));
      i6 = _check_pointer(i6, 18992);
      i7 = OOC_ARRAY_LENGTH(i6, 0);
      i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i4, i7, OOC_UINT32, 18992))*4);
      i6 = *(OOC_INT32*)(_check_pointer(i6, 18995));
      *(OOC_INT32*)(_check_pointer(i5, 18972)) = (i6*i0);
      i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 19020));
      i5 = _check_pointer(i5, 19025);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 19025))*4);
      i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 19041));
      i6 = _check_pointer(i6, 19046);
      i7 = OOC_ARRAY_LENGTH(i6, 0);
      i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i4, i7, OOC_UINT32, 19046))*4);
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 19049))+4);
      *(OOC_INT32*)((_check_pointer(i5, 19028))+4) = i6;
      i4 = i4+1;
      i = i4;
      i5 = i4<i3;
      if (i5) goto l7_loop;
l12:
      return (OOC_SSA_LoopRewrite__PList)i2;
      goto l16;
l13:
      return (OOC_SSA_LoopRewrite__PList)(OOC_INT32)0;
      goto l16;
l15:
      i0 = (OOC_INT32)a;
      return (OOC_SSA_LoopRewrite__PList)i0;
l16:
      _failed_function(18605); return 0;
      ;
    }

    
    OOC_SSA_LoopRewrite__PList OOC_SSA_LoopRewrite__Flatten_AddPLists(OOC_SSA_LoopRewrite__PList a, OOC_SSA_LoopRewrite__PList b, OOC_INT32 magnB) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
      OOC_SSA_LoopRewrite__PList p;
      OOC_INT32 i;
      OOC_INT32 ia;
      OOC_INT32 ib;
      auto OOC_SSA_LoopRewrite__Product OOC_SSA_LoopRewrite__Flatten_AddPLists_CopyProduct(OOC_SSA_LoopRewrite__Product a);
        
        OOC_SSA_LoopRewrite__Product OOC_SSA_LoopRewrite__Flatten_AddPLists_CopyProduct(OOC_SSA_LoopRewrite__Product a) {
          register OOC_INT32 i0,i1,i2,i3;
          OOC_SSA_LoopRewrite__Product p;

          i0 = (OOC_INT32)RT0__NewObject(_td_OOC_SSA_LoopRewrite__Product.baseTypes[0]);
          p = (OOC_SSA_LoopRewrite__Product)i0;
          i1 = (OOC_INT32)a;
          i1 = _check_pointer(i1, 19385);
          i2 = _check_pointer(i0, 19379);
          i3 = (OOC_INT32)&_td_OOC_SSA_LoopRewrite__ProductDesc;
          i3 = i3!=i3;
          if (!i3) goto l4;
          _failed_type_assert(19379);
l4:
          _copy_block(i1,i2,8);
          return (OOC_SSA_LoopRewrite__Product)i0;
          ;
        }


      i0 = (OOC_INT32)a;
      i1 = i0==(OOC_INT32)0;
      if (i1) goto l44;
      i1 = (OOC_INT32)b;
      i2 = i1==(OOC_INT32)0;
      if (i2) goto l42;
      i2 = (OOC_INT32)RT0__NewObject(_td_OOC_SSA_LoopRewrite__PList.baseTypes[0]);
      p = (OOC_SSA_LoopRewrite__PList)i2;
      i3 = *(OOC_INT32*)((_check_pointer(i0, 19600))+4);
      i4 = *(OOC_INT32*)((_check_pointer(i1, 19607))+4);
      *(OOC_INT32*)(_check_pointer(i2, 19592)) = ((OOC_INT32)RT0__NewObject(_td_OOC_SSA_LoopRewrite__2903.baseTypes[0], (i3+i4)));
      i = 0;
      ia = 0;
      ib = 0;
      i0 = *(OOC_INT32*)((_check_pointer(i0, 19670))+4);
      i0 = 0!=i0;
      if (i0) goto l7;
      i0 = *(OOC_INT32*)((_check_pointer(i1, 19687))+4);
      i0 = 0!=i0;
      
      goto l9;
l7:
      i0=1u;
l9:
      if (i0) goto l11;
      i0=i2;i1=0;
      goto l41;
l11:
      i1=i2;i0=0;i2=0;
l12_loop:
      i3 = (OOC_INT32)a;
      i4 = *(OOC_INT32*)((_check_pointer(i3, 19717))+4);
      i5 = ia;
      i4 = i5!=i4;
      if (i4) goto l15;
      i4=0u;
      goto l21;
l15:
      i4 = (OOC_INT32)b;
      i6 = *(OOC_INT32*)((_check_pointer(i4, 19747))+4);
      i6 = i0==i6;
      if (i6) goto l18;
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 19775));
      i4 = _check_pointer(i4, 19780);
      i6 = OOC_ARRAY_LENGTH(i4, 0);
      i7 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 19763));
      i7 = _check_pointer(i7, 19768);
      i8 = OOC_ARRAY_LENGTH(i7, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i0, i6, OOC_UINT32, 19780))*4);
      i6 = (OOC_INT32)*(OOC_INT32*)(i7+(_check_index(i5, i8, OOC_UINT32, 19768))*4);
      i4 = OOC_SSA_LoopRewrite__Cmp((OOC_SSA_LoopRewrite__Product)i6, (OOC_SSA_LoopRewrite__Product)i4);
      i4 = i4<0;
      
      goto l21;
l18:
      i4=1u;
l21:
      if (i4) goto l31;
      i4 = *(OOC_INT32*)((_check_pointer(i3, 19886))+4);
      i4 = i5==i4;
      if (i4) goto l25;
      i4 = (OOC_INT32)b;
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 19914));
      i4 = _check_pointer(i4, 19919);
      i6 = OOC_ARRAY_LENGTH(i4, 0);
      i7 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 19902));
      i7 = _check_pointer(i7, 19907);
      i8 = OOC_ARRAY_LENGTH(i7, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i0, i6, OOC_UINT32, 19919))*4);
      i6 = (OOC_INT32)*(OOC_INT32*)(i7+(_check_index(i5, i8, OOC_UINT32, 19907))*4);
      i4 = OOC_SSA_LoopRewrite__Cmp((OOC_SSA_LoopRewrite__Product)i6, (OOC_SSA_LoopRewrite__Product)i4);
      i4 = i4>0;
      
      goto l27;
l25:
      i4=1u;
l27:
      if (i4) goto l29;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 20123));
      i0 = _check_pointer(i0, 20128);
      i1 = OOC_ARRAY_LENGTH(i0, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 20148));
      i3 = _check_pointer(i3, 20153);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i5, i4, OOC_UINT32, 20153))*4);
      i3 = (OOC_INT32)OOC_SSA_LoopRewrite__Flatten_AddPLists_CopyProduct((OOC_SSA_LoopRewrite__Product)i3);
      *(OOC_INT32*)(i0+(_check_index(i2, i1, OOC_UINT32, 20128))*4) = i3;
      i0 = (OOC_INT32)p;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 20177));
      i1 = _check_pointer(i1, 20182);
      i2 = OOC_ARRAY_LENGTH(i1, 0);
      i3 = i;
      i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(i3, i2, OOC_UINT32, 20182))*4);
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 20177));
      i2 = _check_pointer(i2, 20182);
      i4 = OOC_ARRAY_LENGTH(i2, 0);
      i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i3, i4, OOC_UINT32, 20182))*4);
      i4 = (OOC_INT32)b;
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 20198));
      i4 = _check_pointer(i4, 20203);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i6 = ib;
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i6, i5, OOC_UINT32, 20203))*4);
      i4 = *(OOC_INT32*)(_check_pointer(i4, 20207));
      i5 = magnB;
      i2 = *(OOC_INT32*)(_check_pointer(i2, 20185));
      *(OOC_INT32*)(_check_pointer(i1, 20185)) = (i2+(i4*i5));
      i1 = i3+1;
      i2 = ia;
      i = i1;
      ia = (i2+1);
      i2 = i6+1;
      ib = i2;
      {register OOC_INT32 h0=i0;i0=i2;i2=i1;i1=h0;}
      goto l32;
l29:
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 19948));
      i1 = _check_pointer(i1, 19953);
      i3 = OOC_ARRAY_LENGTH(i1, 0);
      i4 = (OOC_INT32)b;
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 19973));
      i4 = _check_pointer(i4, 19978);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i0 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i0, i5, OOC_UINT32, 19978))*4);
      i0 = (OOC_INT32)OOC_SSA_LoopRewrite__Flatten_AddPLists_CopyProduct((OOC_SSA_LoopRewrite__Product)i0);
      *(OOC_INT32*)(i1+(_check_index(i2, i3, OOC_UINT32, 19953))*4) = i0;
      i0 = (OOC_INT32)p;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 19998));
      i1 = _check_pointer(i1, 20003);
      i2 = OOC_ARRAY_LENGTH(i1, 0);
      i3 = i;
      i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(i3, i2, OOC_UINT32, 20003))*4);
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 20021));
      i2 = _check_pointer(i2, 20026);
      i4 = OOC_ARRAY_LENGTH(i2, 0);
      i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i3, i4, OOC_UINT32, 20026))*4);
      i2 = *(OOC_INT32*)(_check_pointer(i2, 20029));
      i4 = magnB;
      *(OOC_INT32*)(_check_pointer(i1, 20006)) = (i2*i4);
      i1 = i3+1;
      i2 = ib;
      i = i1;
      i2 = i2+1;
      ib = i2;
      {register OOC_INT32 h0=i0;i0=i2;i2=i1;i1=h0;}
      goto l32;
l31:
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 19810));
      i4 = _check_pointer(i4, 19815);
      i6 = OOC_ARRAY_LENGTH(i4, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 19823));
      i3 = _check_pointer(i3, 19828);
      i7 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i5, i7, OOC_UINT32, 19828))*4);
      *(OOC_INT32*)(i4+(_check_index(i2, i6, OOC_UINT32, 19815))*4) = i3;
      i2 = i2+1;
      i = i2;
      ia = (i5+1);
      
l32:
      i3 = (OOC_INT32)a;
      i3 = *(OOC_INT32*)((_check_pointer(i3, 19670))+4);
      i4 = ia;
      i3 = i4!=i3;
      if (i3) goto l35;
      i3 = (OOC_INT32)b;
      i3 = *(OOC_INT32*)((_check_pointer(i3, 19687))+4);
      i3 = i0!=i3;
      
      goto l37;
l35:
      i3=1u;
l37:
      if (i3) goto l12_loop;
l40:
      i0=i1;i1=i2;
l41:
      *(OOC_INT32*)((_check_pointer(i0, 20303))+4) = i1;
      return (OOC_SSA_LoopRewrite__PList)i0;
      goto l45;
l42:
      return (OOC_SSA_LoopRewrite__PList)i0;
      goto l45;
l44:
      i0 = magnB;
      i1 = (OOC_INT32)b;
      i0 = (OOC_INT32)OOC_SSA_LoopRewrite__Flatten_ScalePList((OOC_SSA_LoopRewrite__PList)i1, i0);
      return (OOC_SSA_LoopRewrite__PList)i0;
l45:
      _failed_function(19136); return 0;
      ;
    }

    
    OOC_SSA_LoopRewrite__PList OOC_SSA_LoopRewrite__Flatten_MultProduct(OOC_SSA_LoopRewrite__Product a, OOC_SSA_LoopRewrite__PList b) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11,i12,i13,i14;
      OOC_SSA_LoopRewrite__PList p;
      OOC_INT32 i;
      OOC_INT32 la;
      OOC_INT32 lb;
      OOC_SSA_LoopRewrite__Factors f;
      OOC_INT32 j;
      OOC_INT32 ia;
      OOC_INT32 ib;

      i0 = (OOC_INT32)b;
      i1 = i0==(OOC_INT32)0;
      if (i1) goto l44;
      i1 = (OOC_INT32)OOC_SSA_LoopRewrite__one;
      i1 = i0==i1;
      if (i1) goto l42;
      i1 = (OOC_INT32)RT0__NewObject(_td_OOC_SSA_LoopRewrite__PList.baseTypes[0]);
      p = (OOC_SSA_LoopRewrite__PList)i1;
      i2 = *(OOC_INT32*)((_check_pointer(i0, 20734))+4);
      *(OOC_INT32*)((_check_pointer(i1, 20724))+4) = i2;
      i2 = *(OOC_INT32*)((_check_pointer(i1, 20762))+4);
      *(OOC_INT32*)(_check_pointer(i1, 20754)) = ((OOC_INT32)RT0__NewObject(_td_OOC_SSA_LoopRewrite__2903.baseTypes[0], i2));
      i = 0;
      i2 = *(OOC_INT32*)((_check_pointer(i1, 20793))+4);
      i3 = 0<i2;
      if (!i3) goto l41;
      i3 = (OOC_INT32)a;
      i4=0;
l7_loop:
      i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 20819));
      i5 = _check_pointer(i5, 20824);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      *(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 20824))*4) = ((OOC_INT32)RT0__NewObject(_td_OOC_SSA_LoopRewrite__Product.baseTypes[0]));
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 20862))+4);
      i5 = OOC_ARRAY_LENGTH((_check_pointer(i5, 20870)), 0);
      la = i5;
      i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 20895));
      i6 = _check_pointer(i6, 20900);
      i7 = OOC_ARRAY_LENGTH(i6, 0);
      i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i4, i7, OOC_UINT32, 20900))*4);
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 20903))+4);
      i6 = OOC_ARRAY_LENGTH((_check_pointer(i6, 20911)), 0);
      lb = i6;
      i7 = (OOC_INT32)RT0__NewObject(_td_OOC_SSA_LoopRewrite__Factors.baseTypes[0], (i5+i6));
      f = (OOC_SSA_LoopRewrite__Factors)i7;
      i8 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 20951));
      i8 = _check_pointer(i8, 20956);
      i9 = OOC_ARRAY_LENGTH(i8, 0);
      i8 = (OOC_INT32)*(OOC_INT32*)(i8+(_check_index(i4, i9, OOC_UINT32, 20956))*4);
      *(OOC_INT32*)((_check_pointer(i8, 20959))+4) = i7;
      i8 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 20985));
      i8 = _check_pointer(i8, 20990);
      i9 = OOC_ARRAY_LENGTH(i8, 0);
      i8 = (OOC_INT32)*(OOC_INT32*)(i8+(_check_index(i4, i9, OOC_UINT32, 20990))*4);
      i9 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 21008));
      i9 = _check_pointer(i9, 21013);
      i10 = OOC_ARRAY_LENGTH(i9, 0);
      i9 = (OOC_INT32)*(OOC_INT32*)(i9+(_check_index(i4, i10, OOC_UINT32, 21013))*4);
      i10 = *(OOC_INT32*)(_check_pointer(i3, 21028));
      i9 = *(OOC_INT32*)(_check_pointer(i9, 21016));
      *(OOC_INT32*)(_check_pointer(i8, 20993)) = (i9*i10);
      j = 0;
      ia = 0;
      ib = 0;
      i8 = 0!=i5;
      if (i8) goto l10;
      i9 = 0!=i6;
      
      goto l12;
l10:
      i9=1u;
l12:
      if (i9) goto l14;
      i5=0;
      goto l36;
l14:
      i11=i8;i8=0;i9=0;i10=0;
l15_loop:
      if (i11) goto l18;
      i11=0u;
      goto l24;
l18:
      i11 = i9==i6;
      if (i11) goto l21;
      i11 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 21203))+4);
      i11 = _check_pointer(i11, 21211);
      i12 = OOC_ARRAY_LENGTH(i11, 0);
      i11 = (OOC_INT32)*(OOC_INT32*)(i11+(_check_index(i8, i12, OOC_UINT32, 21211))*4);
      i12 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 21223));
      i12 = _check_pointer(i12, 21228);
      i13 = OOC_ARRAY_LENGTH(i12, 0);
      i12 = (OOC_INT32)*(OOC_INT32*)(i12+(_check_index(i4, i13, OOC_UINT32, 21228))*4);
      i12 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i12, 21231))+4);
      i12 = _check_pointer(i12, 21239);
      i13 = OOC_ARRAY_LENGTH(i12, 0);
      i12 = (OOC_INT32)*(OOC_INT32*)(i12+(_check_index(i9, i13, OOC_UINT32, 21239))*4);
      i11 = *(OOC_INT32*)((_check_pointer(i11, 21215))+8);
      i12 = *(OOC_INT32*)((_check_pointer(i12, 21243))+8);
      i11 = i11<=i12;
      
      goto l24;
l21:
      i11=1u;
l24:
      if (i11) goto l26;
      i11 = _check_pointer(i7, 21332);
      i12 = OOC_ARRAY_LENGTH(i11, 0);
      i13 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 21340));
      i13 = _check_pointer(i13, 21345);
      i14 = OOC_ARRAY_LENGTH(i13, 0);
      i13 = (OOC_INT32)*(OOC_INT32*)(i13+(_check_index(i4, i14, OOC_UINT32, 21345))*4);
      i13 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i13, 21348))+4);
      i13 = _check_pointer(i13, 21356);
      i14 = OOC_ARRAY_LENGTH(i13, 0);
      i13 = (OOC_INT32)*(OOC_INT32*)(i13+(_check_index(i9, i14, OOC_UINT32, 21356))*4);
      *(OOC_INT32*)(i11+(_check_index(i10, i12, OOC_UINT32, 21332))*4) = i13;
      i9 = i9+1;
      ib = i9;
      
      goto l27;
l26:
      i11 = _check_pointer(i7, 21269);
      i12 = OOC_ARRAY_LENGTH(i11, 0);
      i13 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 21277))+4);
      i13 = _check_pointer(i13, 21285);
      i14 = OOC_ARRAY_LENGTH(i13, 0);
      i13 = (OOC_INT32)*(OOC_INT32*)(i13+(_check_index(i8, i14, OOC_UINT32, 21285))*4);
      *(OOC_INT32*)(i11+(_check_index(i10, i12, OOC_UINT32, 21269))*4) = i13;
      i8 = i8+1;
      ia = i8;
      
l27:
      i10 = i10+1;
      j = i10;
      i11 = i8!=i5;
      if (i11) goto l30;
      i12 = i9!=i6;
      
      goto l32;
l30:
      i12=1u;
l32:
      if (i12) goto l15_loop;
l35:
      i5=i10;
l36:
      i6 = OOC_ARRAY_LENGTH((_check_pointer(i7, 21449)), 0);
      _assert((i5==i6), 127, 21433);
      i4 = i4+1;
      i = i4;
      i5 = i4<i2;
      if (i5) goto l7_loop;
l41:
      return (OOC_SSA_LoopRewrite__PList)i1;
      goto l45;
l42:
      i0 = (OOC_INT32)RT0__NewObject(_td_OOC_SSA_LoopRewrite__PList.baseTypes[0]);
      p = (OOC_SSA_LoopRewrite__PList)i0;
      *(OOC_INT32*)((_check_pointer(i0, 20610))+4) = 1;
      *(OOC_INT32*)(_check_pointer(i0, 20635)) = ((OOC_INT32)RT0__NewObject(_td_OOC_SSA_LoopRewrite__2903.baseTypes[0], 1));
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 20655));
      i1 = _check_pointer(i1, 20660);
      i2 = OOC_ARRAY_LENGTH(i1, 0);
      i3 = (OOC_INT32)a;
      *(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 20660))*4) = i3;
      return (OOC_SSA_LoopRewrite__PList)i0;
      goto l45;
l44:
      return (OOC_SSA_LoopRewrite__PList)(OOC_INT32)0;
l45:
      _failed_function(20381); return 0;
      ;
    }

    
    OOC_SSA_LoopRewrite__Sum OOC_SSA_LoopRewrite__Flatten_AddSum(OOC_SSA_LoopRewrite__Sum a, OOC_SSA_LoopRewrite__Sum b, OOC_INT32 magnB) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5;
      OOC_INT8 subclass;
      OOC_SSA_LoopRewrite__Sum sum;
      auto OOC_INT32 OOC_SSA_LoopRewrite__Flatten_AddSum_UseCount(OOC_SSA__Result res);
      auto OOC_SSA_LoopRewrite__Sum OOC_SSA_LoopRewrite__Flatten_AddSum_MoveCE(OOC_SSA_LoopRewrite__Sum a);
        
        OOC_INT32 OOC_SSA_LoopRewrite__Flatten_AddSum_UseCount(OOC_SSA__Result res) {
          register OOC_INT32 i0,i1,i2;
          OOC_INT32 num;
          OOC_SSA__Opnd use;

          num = 0;
          i0 = (OOC_INT32)res;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21869))+12);
          use = (OOC_SSA__Opnd)i0;
          i1 = i0!=(OOC_INT32)0;
          if (i1) goto l3;
          i0=0;
          goto l9;
l3:
          i1=i0;i0=0;
l4_loop:
          i0 = i0+1;
          num = i0;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 21948))+16);
          use = (OOC_SSA__Opnd)i1;
          i2 = i1!=(OOC_INT32)0;
          if (i2) goto l4_loop;
l9:
          return i0;
          ;
        }

        
        OOC_SSA_LoopRewrite__Sum OOC_SSA_LoopRewrite__Flatten_AddSum_MoveCE(OOC_SSA_LoopRewrite__Sum a) {
          register OOC_INT32 i0,i1,i2,i3,i4;
          OOC_SSA_LoopRewrite__Product p;
          OOC_SSA_LoopRewrite__PList plist;
          OOC_SSA_LoopRewrite__Sum b;

          i0 = (OOC_INT32)RT0__NewObject(_td_OOC_SSA_LoopRewrite__Product.baseTypes[0]);
          p = (OOC_SSA_LoopRewrite__Product)i0;
          *(OOC_INT32*)(_check_pointer(i0, 22200)) = 1;
          *(OOC_INT32*)((_check_pointer(i0, 22230))+4) = ((OOC_INT32)RT0__NewObject(_td_OOC_SSA_LoopRewrite__Factors.baseTypes[0], 1));
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22253))+4);
          i1 = _check_pointer(i1, 22261);
          i2 = OOC_ARRAY_LENGTH(i1, 0);
          i3 = (OOC_INT32)a;
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 22269))+16);
          *(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 22261))*4) = i4;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 22307))+20);
          i0 = (OOC_INT32)OOC_SSA_LoopRewrite__Flatten_MultProduct((OOC_SSA_LoopRewrite__Product)i0, (OOC_SSA_LoopRewrite__PList)i1);
          plist = (OOC_SSA_LoopRewrite__PList)i0;
          i1 = (OOC_INT32)RT0__NewObject(_td_OOC_SSA_LoopRewrite__Sum.baseTypes[0]);
          b = (OOC_SSA_LoopRewrite__Sum)i1;
          i2 = _check_pointer(i3, 22413);
          i3 = _check_pointer(i1, 22407);
          i4 = (OOC_INT32)&_td_OOC_SSA_LoopRewrite__SumDesc;
          i4 = i4!=i4;
          if (!i4) goto l4;
          _failed_type_assert(22407);
l4:
          _copy_block(i2,i3,48);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 22447))+32);
          i0 = (OOC_INT32)OOC_SSA_LoopRewrite__Flatten_AddPLists((OOC_SSA_LoopRewrite__PList)i2, (OOC_SSA_LoopRewrite__PList)i0, 1);
          *(OOC_INT32*)((_check_pointer(i1, 22425))+32) = i0;
          *(OOC_INT32*)((_check_pointer(i1, 22476))+20) = 0;
          *(OOC_INT32*)((_check_pointer(i1, 22504))+16) = 0;
          return (OOC_SSA_LoopRewrite__Sum)i1;
          ;
        }


      i0 = (OOC_INT32)a;
      i1 = (OOC_INT32)b;
      i2 = *(OOC_INT8*)(_check_pointer(i0, 22581));
      i3 = *(OOC_INT8*)(_check_pointer(i1, 22594));
      _assert((i2==i3), 127, 22573);
      i2 = *(OOC_INT8*)(_check_pointer(i0, 22625));
      subclass = i2;
      i3 = (OOC_INT32)RT0__NewObject(_td_OOC_SSA_LoopRewrite__Sum.baseTypes[0]);
      sum = (OOC_SSA_LoopRewrite__Sum)i3;
      OOC_SSA_LoopRewrite__InitSum((OOC_SSA_LoopRewrite__Sum)i3, i2, (OOC_SSA__Result)0);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22705))+20);
      i2 = i2==0;
      if (i2) goto l15;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 22766))+20);
      i2 = i2==0;
      if (i2) goto l13;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22827))+16);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 22834))+16);
      i2 = i2==i4;
      if (i2) goto l11;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 22901))+16);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 22904))+52);
      i2 = OOC_SSA_LoopRewrite__Flatten_AddSum_UseCount((OOC_SSA__Result)i2);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22922))+16);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 22925))+52);
      i3 = OOC_SSA_LoopRewrite__Flatten_AddSum_UseCount((OOC_SSA__Result)i3);
      i2 = i2>i3;
      if (i2) goto l9;
      i0 = (OOC_INT32)OOC_SSA_LoopRewrite__Flatten_AddSum_MoveCE((OOC_SSA_LoopRewrite__Sum)i1);
      i1 = (OOC_INT32)a;
      i2 = magnB;
      i0 = (OOC_INT32)OOC_SSA_LoopRewrite__Flatten_AddSum((OOC_SSA_LoopRewrite__Sum)i1, (OOC_SSA_LoopRewrite__Sum)i0, i2);
      return (OOC_SSA_LoopRewrite__Sum)i0;
      goto l16;
l9:
      i0 = (OOC_INT32)OOC_SSA_LoopRewrite__Flatten_AddSum_MoveCE((OOC_SSA_LoopRewrite__Sum)i0);
      i2 = magnB;
      i0 = (OOC_INT32)OOC_SSA_LoopRewrite__Flatten_AddSum((OOC_SSA_LoopRewrite__Sum)i0, (OOC_SSA_LoopRewrite__Sum)i1, i2);
      return (OOC_SSA_LoopRewrite__Sum)i0;
      goto l16;
l11:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22863))+16);
      *(OOC_INT32*)((_check_pointer(i3, 22855))+16) = i0;
      goto l16;
l13:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22808))+16);
      *(OOC_INT32*)((_check_pointer(i3, 22800))+16) = i0;
      goto l16;
l15:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 22747))+16);
      *(OOC_INT32*)((_check_pointer(i3, 22739))+16) = i0;
l16:
      i0 = (OOC_INT32)sum;
      i1 = (OOC_INT32)b;
      i2 = (OOC_INT32)a;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23111))+20);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 23099))+20);
      i5 = magnB;
      i3 = (OOC_INT32)OOC_SSA_LoopRewrite__Flatten_AddPLists((OOC_SSA_LoopRewrite__PList)i4, (OOC_SSA_LoopRewrite__PList)i3, i5);
      *(OOC_INT32*)((_check_pointer(i0, 23075))+20) = i3;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23185))+24);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 23168))+24);
      i3 = (OOC_INT32)OOC_SSA_LoopRewrite__Flatten_AddPLists((OOC_SSA_LoopRewrite__PList)i4, (OOC_SSA_LoopRewrite__PList)i3, i5);
      *(OOC_INT32*)((_check_pointer(i0, 23139))+24) = i3;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23254))+28);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 23242))+28);
      i3 = (OOC_INT32)OOC_SSA_LoopRewrite__Flatten_AddPLists((OOC_SSA_LoopRewrite__PList)i4, (OOC_SSA_LoopRewrite__PList)i3, i5);
      *(OOC_INT32*)((_check_pointer(i0, 23218))+28) = i3;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23314))+32);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 23304))+32);
      i1 = (OOC_INT32)OOC_SSA_LoopRewrite__Flatten_AddPLists((OOC_SSA_LoopRewrite__PList)i2, (OOC_SSA_LoopRewrite__PList)i1, i5);
      *(OOC_INT32*)((_check_pointer(i0, 23282))+32) = i1;
      return (OOC_SSA_LoopRewrite__Sum)i0;
      ;
    }

    
    OOC_SSA_LoopRewrite__Sum OOC_SSA_LoopRewrite__Flatten_MultSum(OOC_SSA_LoopRewrite__Sum a, OOC_SSA_LoopRewrite__Sum b) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_SSA_LoopRewrite__Sum h;
      OOC_SSA_LoopRewrite__Sum mult;
      auto OOC_SSA_LoopRewrite__Sum OOC_SSA_LoopRewrite__Flatten_MultSum_MultPList(OOC_SSA_LoopRewrite__PList a, OOC_SSA_LoopRewrite__Sum b, OOC_INT8 subclass);
        
        OOC_SSA_LoopRewrite__Sum OOC_SSA_LoopRewrite__Flatten_MultSum_MultPList(OOC_SSA_LoopRewrite__PList a, OOC_SSA_LoopRewrite__Sum b, OOC_INT8 subclass) {
          register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
          OOC_SSA_LoopRewrite__Sum sum;
          OOC_INT32 i;

          i0 = (OOC_INT32)RT0__NewObject(_td_OOC_SSA_LoopRewrite__Sum.baseTypes[0]);
          sum = (OOC_SSA_LoopRewrite__Sum)i0;
          i1 = subclass;
          OOC_SSA_LoopRewrite__InitSum((OOC_SSA_LoopRewrite__Sum)i0, i1, (OOC_SSA__Result)(OOC_INT32)0);
          i1 = (OOC_INT32)a;
          i2 = i1==(OOC_INT32)0;
          if (i2) goto l15;
          i2 = (OOC_INT32)OOC_SSA_LoopRewrite__one;
          i2 = i1==i2;
          if (i2) goto l13;
          i2 = (OOC_INT32)b;
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 23763))+16);
          *(OOC_INT32*)((_check_pointer(i0, 23755))+16) = i3;
          i = 0;
          i3 = *(OOC_INT32*)((_check_pointer(i1, 23793))+4);
          i4 = 0<i3;
          if (!i4) goto l12;
          i4=0;
l7_loop:
          i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 23886));
          i5 = _check_pointer(i5, 23891);
          i6 = OOC_ARRAY_LENGTH(i5, 0);
          i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 23897))+20);
          i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 23891))*4);
          i5 = (OOC_INT32)OOC_SSA_LoopRewrite__Flatten_MultProduct((OOC_SSA_LoopRewrite__Product)i5, (OOC_SSA_LoopRewrite__PList)i7);
          i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23862))+20);
          i5 = (OOC_INT32)OOC_SSA_LoopRewrite__Flatten_AddPLists((OOC_SSA_LoopRewrite__PList)i6, (OOC_SSA_LoopRewrite__PList)i5, 1);
          *(OOC_INT32*)((_check_pointer(i0, 23819))+20) = i5;
          i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 23995));
          i5 = _check_pointer(i5, 24000);
          i6 = OOC_ARRAY_LENGTH(i5, 0);
          i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 24006))+28);
          i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 24000))*4);
          i5 = (OOC_INT32)OOC_SSA_LoopRewrite__Flatten_MultProduct((OOC_SSA_LoopRewrite__Product)i5, (OOC_SSA_LoopRewrite__PList)i7);
          i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23971))+28);
          i5 = (OOC_INT32)OOC_SSA_LoopRewrite__Flatten_AddPLists((OOC_SSA_LoopRewrite__PList)i6, (OOC_SSA_LoopRewrite__PList)i5, 1);
          *(OOC_INT32*)((_check_pointer(i0, 23928))+28) = i5;
          i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 24114));
          i5 = _check_pointer(i5, 24119);
          i6 = OOC_ARRAY_LENGTH(i5, 0);
          i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 24124))+24);
          i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 24119))*4);
          i5 = (OOC_INT32)OOC_SSA_LoopRewrite__Flatten_MultProduct((OOC_SSA_LoopRewrite__Product)i5, (OOC_SSA_LoopRewrite__PList)i7);
          i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24085))+24);
          i5 = (OOC_INT32)OOC_SSA_LoopRewrite__Flatten_AddPLists((OOC_SSA_LoopRewrite__PList)i6, (OOC_SSA_LoopRewrite__PList)i5, 1);
          *(OOC_INT32*)((_check_pointer(i0, 24037))+24) = i5;
          i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 24223));
          i5 = _check_pointer(i5, 24228);
          i6 = OOC_ARRAY_LENGTH(i5, 0);
          i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 24234))+32);
          i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 24228))*4);
          i5 = (OOC_INT32)OOC_SSA_LoopRewrite__Flatten_MultProduct((OOC_SSA_LoopRewrite__Product)i5, (OOC_SSA_LoopRewrite__PList)i7);
          i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24201))+32);
          i5 = (OOC_INT32)OOC_SSA_LoopRewrite__Flatten_AddPLists((OOC_SSA_LoopRewrite__PList)i6, (OOC_SSA_LoopRewrite__PList)i5, 1);
          *(OOC_INT32*)((_check_pointer(i0, 24160))+32) = i5;
          i4 = i4+1;
          i = i4;
          i5 = i4<i3;
          if (i5) goto l7_loop;
l12:
          return (OOC_SSA_LoopRewrite__Sum)i0;
          goto l16;
l13:
          i0 = (OOC_INT32)b;
          return (OOC_SSA_LoopRewrite__Sum)i0;
          goto l16;
l15:
          return (OOC_SSA_LoopRewrite__Sum)i0;
l16:
          _failed_function(23446); return 0;
          ;
        }


      i0 = (OOC_INT32)a;
      i1 = (OOC_INT32)b;
      i2 = *(OOC_INT8*)(_check_pointer(i0, 24348));
      i3 = *(OOC_INT8*)(_check_pointer(i1, 24361));
      _assert((i2==i3), 127, 24340);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 24391))+20);
      i2 = i2==0;
      if (i2) goto l3;
      i2=0u;
      goto l5;
l3:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 24413))+32);
      i2 = i2==0;
      
l5:
      if (!i2) goto l8;
      h = (OOC_SSA_LoopRewrite__Sum)i0;
      a = (OOC_SSA_LoopRewrite__Sum)i1;
      b = (OOC_SSA_LoopRewrite__Sum)i0;
      {register OOC_INT32 h0=i0;i0=i1;i1=h0;}
l8:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24488))+20);
      i2 = i2!=0;
      if (i2) goto l11;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24511))+32);
      i2 = i2!=0;
      
      goto l13;
l11:
      i2=1u;
l13:
      if (!i2) goto l15;
      return (OOC_SSA_LoopRewrite__Sum)0;
l15:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24589))+28);
      i0 = *(OOC_INT8*)(_check_pointer(i0, 24604));
      i0 = (OOC_INT32)OOC_SSA_LoopRewrite__Flatten_MultSum_MultPList((OOC_SSA_LoopRewrite__PList)i2, (OOC_SSA_LoopRewrite__Sum)i1, i0);
      mult = (OOC_SSA_LoopRewrite__Sum)i0;
      i1 = (OOC_INT32)a;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 24627))+24);
      i2 = i2!=0;
      if (!i2) goto l19;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 24679))+24);
      i1 = *(OOC_INT8*)(_check_pointer(i1, 24699));
      i2 = (OOC_INT32)b;
      i0 = (OOC_INT32)OOC_SSA_LoopRewrite__Flatten_MultSum_MultPList((OOC_SSA_LoopRewrite__PList)i0, (OOC_SSA_LoopRewrite__Sum)i2, i1);
      h = (OOC_SSA_LoopRewrite__Sum)i0;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24766))+28);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24749))+24);
      i1 = (OOC_INT32)OOC_SSA_LoopRewrite__Flatten_AddPLists((OOC_SSA_LoopRewrite__PList)i2, (OOC_SSA_LoopRewrite__PList)i1, 1);
      *(OOC_INT32*)((_check_pointer(i0, 24720))+24) = i1;
      *(OOC_INT32*)((_check_pointer(i0, 24790))+28) = 0;
      i1 = (OOC_INT32)mult;
      i0 = (OOC_INT32)OOC_SSA_LoopRewrite__Flatten_AddSum((OOC_SSA_LoopRewrite__Sum)i1, (OOC_SSA_LoopRewrite__Sum)i0, 1);
      _assert((i0!=0), 127, 24853);
      
l19:
      return (OOC_SSA_LoopRewrite__Sum)i0;
      ;
    }

    
    OOC_SSA_LoopRewrite__PList OOC_SSA_LoopRewrite__Flatten_NewPList(OOC_SSA_LoopRewrite__Sum factor) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_SSA_LoopRewrite__PList plist;

      i0 = (OOC_INT32)RT0__NewObject(_td_OOC_SSA_LoopRewrite__PList.baseTypes[0]);
      plist = (OOC_SSA_LoopRewrite__PList)i0;
      *(OOC_INT32*)((_check_pointer(i0, 25032))+4) = 1;
      *(OOC_INT32*)(_check_pointer(i0, 25059)) = ((OOC_INT32)RT0__NewObject(_td_OOC_SSA_LoopRewrite__2903.baseTypes[0], 1));
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 25085));
      i1 = _check_pointer(i1, 25090);
      i2 = OOC_ARRAY_LENGTH(i1, 0);
      *(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 25090))*4) = ((OOC_INT32)RT0__NewObject(_td_OOC_SSA_LoopRewrite__Product.baseTypes[0]));
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 25107));
      i1 = _check_pointer(i1, 25112);
      i2 = OOC_ARRAY_LENGTH(i1, 0);
      i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 25112))*4);
      *(OOC_INT32*)(_check_pointer(i1, 25115)) = 1;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 25147));
      i1 = _check_pointer(i1, 25152);
      i2 = OOC_ARRAY_LENGTH(i1, 0);
      i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 25152))*4);
      *(OOC_INT32*)((_check_pointer(i1, 25155))+4) = ((OOC_INT32)RT0__NewObject(_td_OOC_SSA_LoopRewrite__Factors.baseTypes[0], 1));
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 25180));
      i1 = _check_pointer(i1, 25185);
      i2 = OOC_ARRAY_LENGTH(i1, 0);
      i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 25185))*4);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 25188))+4);
      i1 = _check_pointer(i1, 25196);
      i2 = OOC_ARRAY_LENGTH(i1, 0);
      i3 = (OOC_INT32)factor;
      *(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 25196))*4) = i3;
      return (OOC_SSA_LoopRewrite__PList)i0;
      ;
    }


  i0 = (OOC_INT32)res;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25271))+16);
  i1 = i1!=(OOC_INT32)0;
  if (i1) goto l41;
  i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 25336)))), &_td_OOC_SSA__InstrDesc));
  if (i1) goto l39;
  i0 = _type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 25572)))), &_td_OOC_SSA__InstrDesc, 25572);
  instr = (OOC_SSA__Instr)i0;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 25595))+20);
  i1 = i1==1;
  if (i1) goto l33;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25976))+24);
  opnd = (OOC_SSA__Opnd)i1;
  i2 = i1!=(OOC_INT32)0;
  if (!i2) goto l14;
l9_loop:
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 26039));
  OOC_SSA_LoopRewrite__Flatten((OOC_SSA__Result)i2);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 26068))+8);
  opnd = (OOC_SSA__Opnd)i1;
  i2 = i1!=(OOC_INT32)0;
  if (i2) goto l9_loop;
l14:
  i1 = *(OOC_INT8*)((_check_pointer(i0, 26111))+36);
  switch (i1) {
  case 19:
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26241))+24);
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 26250))+8);
    i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 26259));
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 26263))+16);
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26180))+24);
    i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 26189));
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 26193))+16);
    i1 = (OOC_INT32)OOC_SSA_LoopRewrite__Flatten_AddSum((OOC_SSA_LoopRewrite__Sum)(_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 26199)))), &_td_OOC_SSA_LoopRewrite__SumDesc, 26199)), (OOC_SSA_LoopRewrite__Sum)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 26269)))), &_td_OOC_SSA_LoopRewrite__SumDesc, 26269)), 1);
    *(OOC_INT32*)((_check_pointer(i0, 26159))+16) = i1;
    goto l24;
  case 20:
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26403))+24);
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 26412))+8);
    i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 26421));
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 26425))+16);
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26342))+24);
    i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 26351));
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 26355))+16);
    i1 = (OOC_INT32)OOC_SSA_LoopRewrite__Flatten_AddSum((OOC_SSA_LoopRewrite__Sum)(_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 26361)))), &_td_OOC_SSA_LoopRewrite__SumDesc, 26361)), (OOC_SSA_LoopRewrite__Sum)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 26431)))), &_td_OOC_SSA_LoopRewrite__SumDesc, 26431)), (-1));
    *(OOC_INT32*)((_check_pointer(i0, 26321))+16) = i1;
    goto l24;
  case 22:
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26568))+24);
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 26577))+8);
    i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 26586));
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 26590))+16);
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26506))+24);
    i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 26515));
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 26519))+16);
    i1 = (OOC_INT32)OOC_SSA_LoopRewrite__Flatten_MultSum((OOC_SSA_LoopRewrite__Sum)(_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 26525)))), &_td_OOC_SSA_LoopRewrite__SumDesc, 26525)), (OOC_SSA_LoopRewrite__Sum)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 26596)))), &_td_OOC_SSA_LoopRewrite__SumDesc, 26596)));
    *(OOC_INT32*)((_check_pointer(i0, 26484))+16) = i1;
    goto l24;
  case 42:
    i1 = (OOC_INT32)RT0__NewObject(_td_OOC_SSA_LoopRewrite__Sum.baseTypes[0]);
    sum = (OOC_SSA_LoopRewrite__Sum)i1;
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26705))+24);
    i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 26714));
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 26718))+16);
    i2 = _check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 26724)))), &_td_OOC_SSA_LoopRewrite__SumDesc, 26724)), 26728);
    i3 = _check_pointer(i1, 26695);
    i4 = (OOC_INT32)&_td_OOC_SSA_LoopRewrite__SumDesc;
    i4 = i4!=i4;
    if (!i4) goto l22;
    _failed_type_assert(26695);
l22:
    _copy_block(i2,i3,48);
    i2 = *(OOC_INT8*)((_check_pointer(i0, 26762))+5);
    *(OOC_INT8*)(_check_pointer(i1, 26744)) = i2;
    *(OOC_INT32*)((_check_pointer(i0, 26788))+16) = i1;
    goto l24;
  default:
    goto l24;
  }
l24:
  i0 = (OOC_INT32)instr;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26865))+16);
  i1 = i1==(OOC_INT32)0;
  if (i1) goto l31;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27034))+16);
  i0 = _type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 27040)))), &_td_OOC_SSA_LoopRewrite__SumDesc, 27040);
  sum = (OOC_SSA_LoopRewrite__Sum)i0;
  i1 = _check_pointer(i0, 27059);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27103))+16);
  i2 = i2!=(OOC_INT32)0;
  if (i2) goto l29;
  i0=0u;
  goto l30;
l29:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27134))+24);
  i0 = i0!=(OOC_INT32)0;
  
l30:
  *(OOC_UINT8*)(i1+12) = i0;
  goto l41;
l31:
  i1 = *(OOC_INT8*)((_check_pointer(i0, 26912))+5);
  i0 = (OOC_INT32)OOC_SSA_LoopRewrite__NewSum(i1, (OOC_SSA__Result)i0);
  sum = (OOC_SSA_LoopRewrite__Sum)i0;
  i1 = (OOC_INT32)OOC_SSA_LoopRewrite__Flatten_NewPList((OOC_SSA_LoopRewrite__Sum)i0);
  *(OOC_INT32*)((_check_pointer(i0, 26944))+32) = i1;
  i0 = (OOC_INT32)instr;
  i1 = (OOC_INT32)sum;
  *(OOC_INT32*)((_check_pointer(i0, 26985))+16) = i1;
  goto l41;
l33:
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 25643)))), &_td_OOC_SSA__ConstDesc);
  if (i1) goto l36;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 25830))+5);
  i0 = (OOC_INT32)OOC_SSA_LoopRewrite__NewSum(i1, (OOC_SSA__Result)i0);
  sum = (OOC_SSA_LoopRewrite__Sum)i0;
  i1 = (OOC_INT32)OOC_SSA_LoopRewrite__Flatten_NewPList((OOC_SSA_LoopRewrite__Sum)i0);
  *(OOC_INT32*)((_check_pointer(i0, 25862))+24) = i1;
  goto l37;
l36:
  i1 = *(OOC_INT8*)((_check_pointer(i0, 25687))+5);
  i0 = (OOC_INT32)OOC_SSA_LoopRewrite__NewSum(i1, (OOC_SSA__Result)i0);
  sum = (OOC_SSA_LoopRewrite__Sum)i0;
  i1 = (OOC_INT32)OOC_SSA_LoopRewrite__Flatten_NewPList((OOC_SSA_LoopRewrite__Sum)i0);
  *(OOC_INT32*)((_check_pointer(i0, 25719))+28) = i1;
l37:
  i0 = (OOC_INT32)instr;
  i1 = (OOC_INT32)sum;
  *(OOC_INT32*)((_check_pointer(i0, 25921))+16) = i1;
  goto l41;
l39:
  i1 = *(OOC_INT8*)((_check_pointer(i0, 25439))+5);
  i0 = (OOC_INT32)OOC_SSA_LoopRewrite__NewSum(i1, (OOC_SSA__Result)i0);
  sum = (OOC_SSA_LoopRewrite__Sum)i0;
  i1 = (OOC_INT32)OOC_SSA_LoopRewrite__Flatten_NewPList((OOC_SSA_LoopRewrite__Sum)i0);
  *(OOC_INT32*)((_check_pointer(i0, 25465))+32) = i1;
  i0 = (OOC_INT32)res;
  i1 = (OOC_INT32)sum;
  *(OOC_INT32*)((_check_pointer(i0, 25500))+16) = i1;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25531))+8);
  OOC_SSA_LoopRewrite__Flatten((OOC_SSA__Result)i0);
l41:
  return;
  ;
}

static OOC_SSA__Result OOC_SSA_LoopRewrite__InitialValue(OOC_SSA__ProcBlock pb, OOC_SSA_LoopRewrite__RewrittenCycle rc, OOC_SSA__Result initOld, OOC_INT32 marker) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT8 subclass;
  OOC_SSA__Result res;
  OOC_SSA__Instr instr;

  i0 = (OOC_INT32)rc;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27472))+4);
  i1 = *(OOC_INT8*)(_check_pointer(i1, 27479));
  subclass = i1;
  i2 = (OOC_INT32)pb;
  i3 = (OOC_INT32)initOld;
  i4 = (OOC_INT32)OOC_SSA__ProcBlockDesc_FixSubclass((OOC_SSA__ProcBlock)i2, (OOC_SSA__Result)i3, i1);
  res = (OOC_SSA__Result)i4;
  i3 = i4!=i3;
  if (!i3) goto l3;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 27607))+8);
  i5 = marker;
  *(OOC_INT32*)((_check_pointer(i3, 27613))+20) = i5;
l3:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27656))+8);
  i3 = i3!=0;
  if (i3) goto l6;
  i3=i4;
  goto l7;
l6:
  i3 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i2, 22, i1);
  instr = (OOC_SSA__Instr)i3;
  OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i3, (OOC_SSA__Result)i4, 1);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27784))+8);
  OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i3, (OOC_SSA__Result)i4, 1);
  i4 = marker;
  *(OOC_INT32*)((_check_pointer(i3, 27810))+20) = i4;
  res = (OOC_SSA__Result)i3;
  
l7:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27873))+12);
  i4 = i4!=0;
  if (i4) goto l10;
  i0=i3;
  goto l11;
l10:
  i1 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i2, 19, i1);
  instr = (OOC_SSA__Instr)i1;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27960))+12);
  OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i0, 1);
  OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i3, 1);
  i0 = marker;
  *(OOC_INT32*)((_check_pointer(i1, 28022))+20) = i0;
  i0=i1;
l11:
  return (OOC_SSA__Result)i0;
  ;
}

static void OOC_SSA_LoopRewrite__Rewrite(OOC_SSA__ProcBlock pb, OOC_SSA_LoopRewrite__Sum sum) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_SSA_LoopRewrite__InductionCycle ic;
  OOC_SSA_LoopRewrite__RewrittenCycle rc;
  OOC_SSA__Instr loopStart;
  OOC_SSA__Instr collect;
  OOC_SSA__Result res;
  ADT_Dictionary__Dictionary replacement;
  OOC_INT32 i;
  OOC_SSA__Instr loopEnd;
  auto OOC_SSA__Result OOC_SSA_LoopRewrite__Rewrite_Expr(OOC_SSA_LoopRewrite__PList plist, OOC_INT8 subclass);
  auto void OOC_SSA_LoopRewrite__Rewrite_RewriteCycle(OOC_SSA_LoopRewrite__RewrittenCycle rc, OOC_SSA_LoopRewrite__CycleElement ce);
  auto OOC_SSA__Result OOC_SSA_LoopRewrite__Rewrite_ComputeReplacement(OOC_SSA_LoopRewrite__RewrittenCycle rc, OOC_SSA_LoopRewrite__Sum sum);
  auto OOC_CHAR8 OOC_SSA_LoopRewrite__Rewrite_EqualAB(OOC_SSA_LoopRewrite__Sum sum1, OOC_SSA_LoopRewrite__Sum sum2);
    
    OOC_SSA__Result OOC_SSA_LoopRewrite__Rewrite_Expr(OOC_SSA_LoopRewrite__PList plist, OOC_INT8 subclass) {
      register OOC_INT32 i0,i1,i2,i3,i4;
      OOC_SSA__Result res;
      OOC_INT32 i;
      OOC_SSA__Result instr;
      OOC_SSA__Instr add;
      auto OOC_SSA__Result OOC_SSA_LoopRewrite__Rewrite_Expr_Multiply(OOC_INT32 m, OOC_SSA_LoopRewrite__Factors f);
        
        OOC_SSA__Result OOC_SSA_LoopRewrite__Rewrite_Expr_Multiply(OOC_INT32 m, OOC_SSA_LoopRewrite__Factors f) {
          register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
          OOC_SSA__Result res;
          OOC_INT32 i;
          OOC_SSA__Instr mult;

          i0 = (OOC_INT32)f;
          i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 28661)), 0);
          i1 = i1==0;
          if (i1) goto l12;
          i1 = _check_pointer(i0, 28782);
          i2 = OOC_ARRAY_LENGTH(i1, 0);
          i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 28782))*4);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 28785))+4);
          i2 = (OOC_INT32)pb;
          i3 = subclass;
          i1 = (OOC_INT32)OOC_SSA__ProcBlockDesc_FixSubclass((OOC_SSA__ProcBlock)i2, (OOC_SSA__Result)i1, i3);
          res = (OOC_SSA__Result)i1;
          i = 1;
          i2 = OOC_ARRAY_LENGTH((_check_pointer(i0, 28832)), 0);
          i3 = 1<i2;
          if (i3) goto l5;
          i0=i1;
          goto l13;
l5:
          i3=1;
l6_loop:
          i4 = subclass;
          i5 = (OOC_INT32)pb;
          i4 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i5, 22, i4);
          mult = (OOC_SSA__Instr)i4;
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i4, (OOC_SSA__Result)i1, 1);
          i1 = _check_pointer(i0, 28982);
          i5 = OOC_ARRAY_LENGTH(i1, 0);
          i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(i3, i5, OOC_UINT32, 28982))*4);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 28985))+4);
          i5 = subclass;
          i6 = (OOC_INT32)pb;
          i1 = (OOC_INT32)OOC_SSA__ProcBlockDesc_FixSubclass((OOC_SSA__ProcBlock)i6, (OOC_SSA__Result)i1, i5);
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i4, (OOC_SSA__Result)i1, 1);
          res = (OOC_SSA__Result)i4;
          i1 = i3+1;
          i = i1;
          i3 = i1<i2;
          if (!i3) goto l10;
          i3=i1;i1=i4;
          goto l6_loop;
l10:
          i0=i4;
          goto l13;
l12:
          i0 = (OOC_INT32)pb;
          i1 = subclass;
          i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConstInt((OOC_SSA__ProcBlock)i0, 1);
          i2 = (OOC_INT32)pb;
          i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_FixSubclass((OOC_SSA__ProcBlock)i2, (OOC_SSA__Result)i0, i1);
          
l13:
          i1 = m;
          i2 = i1!=1;
          if (!i2) goto l17;
          i2 = (OOC_INT32)pb;
          i3 = subclass;
          i2 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i2, 22, i3);
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i0, 1);
          i0 = subclass;
          i3 = (OOC_INT32)pb;
          i1 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConstInt((OOC_SSA__ProcBlock)i3, i1);
          i3 = (OOC_INT32)pb;
          i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_FixSubclass((OOC_SSA__ProcBlock)i3, (OOC_SSA__Result)i1, i0);
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i0, 1);
          i0=i2;
l17:
          return (OOC_SSA__Result)i0;
          ;
        }


      i0 = (OOC_INT32)plist;
      i1 = *(OOC_INT32*)((_check_pointer(i0, 29373))+4);
      i1 = i1==0;
      if (i1) goto l12;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 29514));
      i1 = _check_pointer(i1, 29519);
      i2 = OOC_ARRAY_LENGTH(i1, 0);
      i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 29519))*4);
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 29489));
      i0 = _check_pointer(i0, 29494);
      i2 = OOC_ARRAY_LENGTH(i0, 0);
      i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i2, OOC_UINT8, 29494))*4);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 29522))+4);
      i0 = *(OOC_INT32*)(_check_pointer(i0, 29497));
      i0 = (OOC_INT32)OOC_SSA_LoopRewrite__Rewrite_Expr_Multiply(i0, (OOC_SSA_LoopRewrite__Factors)i1);
      res = (OOC_SSA__Result)i0;
      i1 = (OOC_INT32)plist;
      i = 1;
      i1 = *(OOC_INT32*)((_check_pointer(i1, 29560))+4);
      i2 = 1<i1;
      if (!i2) goto l11;
      i0=1;
l6_loop:
      i2 = (OOC_INT32)plist;
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 29629));
      i3 = _check_pointer(i3, 29634);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i0, i4, OOC_UINT32, 29634))*4);
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 29604));
      i2 = _check_pointer(i2, 29609);
      i4 = OOC_ARRAY_LENGTH(i2, 0);
      i0 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i0, i4, OOC_UINT32, 29609))*4);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 29637))+4);
      i0 = *(OOC_INT32*)(_check_pointer(i0, 29612));
      i0 = (OOC_INT32)OOC_SSA_LoopRewrite__Rewrite_Expr_Multiply(i0, (OOC_SSA_LoopRewrite__Factors)i2);
      instr = (OOC_SSA__Result)i0;
      i2 = subclass;
      i3 = (OOC_INT32)pb;
      i2 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i3, 19, i2);
      add = (OOC_SSA__Instr)i2;
      i3 = (OOC_INT32)res;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i3, 1);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i0, 1);
      i0 = i;
      res = (OOC_SSA__Result)i2;
      i0 = i0+1;
      i = i0;
      i3 = i0<i1;
      if (i3) goto l6_loop;
l10:
      i0=i2;
l11:
      return (OOC_SSA__Result)i0;
      goto l13;
l12:
      i0 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConstInt((OOC_SSA__ProcBlock)i0, 0);
      i1 = (OOC_INT32)pb;
      i2 = subclass;
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_FixSubclass((OOC_SSA__ProcBlock)i1, (OOC_SSA__Result)i0, i2);
      return (OOC_SSA__Result)i0;
l13:
      _failed_function(28348); return 0;
      ;
    }

    
    void OOC_SSA_LoopRewrite__Rewrite_RewriteCycle(OOC_SSA_LoopRewrite__RewrittenCycle rc, OOC_SSA_LoopRewrite__CycleElement ce) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
      OOC_SSA__Instr ci;
      OOC_SSA__Result iv;
      OOC_SSA__Result ni;
      OOC_SSA__Result res;
      Object__Object obj;
      OOC_SSA__Instr mult;
      OOC_SSA__Result mres;
      OOC_SSA__Instr instr;
      OOC_INT32 resultIndex;
      OOC_SSA__Opnd opnd;
      OOC_SSA__Opnd next;
      OOC_SSA__Instr collect;

      i0 = (OOC_INT32)ce;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l33;
      i1 = (OOC_INT32)rc;
      
l3_loop:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30145))+52);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 30149))+8);
      ci = (OOC_SSA__Instr)i2;
      i3 = *(OOC_INT8*)((_check_pointer(i2, 30172))+36);
      switch (i3) {
      case 19:
      case 20:
        i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 30240))+24);
        i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 30249));
        iv = (OOC_SSA__Result)i3;
        i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 30305))+24);
        i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 30314))+8);
        i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 30323));
        ni = (OOC_SSA__Result)i4;
        i5 = (OOC_INT32)replacement;
        i5 = ADT_Dictionary__DictionaryDesc_HasKey((ADT_Dictionary__Dictionary)i5, (Object__Object)i4);
        if (!i5) goto l9;
        res = (OOC_SSA__Result)i3;
        iv = (OOC_SSA__Result)i4;
        ni = (OOC_SSA__Result)i3;
        {register OOC_INT32 h0=i3;i3=i4;i4=h0;}
l9:
        i5 = (OOC_INT32)replacement;
        i5 = ADT_Dictionary__DictionaryDesc_HasKey((ADT_Dictionary__Dictionary)i5, (Object__Object)i3);
        _assert(i5, 127, 30492);
        i5 = (OOC_INT32)replacement;
        i3 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i5, (Object__Object)i3);
        obj = (Object__Object)i3;
        i3 = _type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 30598)))), &_td_OOC_SSA__ResultDesc, 30598);
        res = (OOC_SSA__Result)i3;
        i5 = (OOC_INT32)sum;
        i5 = *(OOC_INT8*)(_check_pointer(i5, 30645));
        i6 = (OOC_INT32)pb;
        i4 = (OOC_INT32)OOC_SSA__ProcBlockDesc_FixSubclass((OOC_SSA__ProcBlock)i6, (OOC_SSA__Result)i4, i5);
        ni = (OOC_SSA__Result)i4;
        i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 30673))+8);
        i5 = i5!=(OOC_INT32)0;
        if (i5) goto l12;
        mres = (OOC_SSA__Result)i4;
        
        goto l13;
l12:
        i5 = (OOC_INT32)sum;
        i5 = *(OOC_INT8*)(_check_pointer(i5, 30740));
        i6 = (OOC_INT32)pb;
        i5 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i6, 22, i5);
        mult = (OOC_SSA__Instr)i5;
        OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i5, (OOC_SSA__Result)i4, 1);
        i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 30819))+8);
        OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i5, (OOC_SSA__Result)i4, 1);
        mres = (OOC_SSA__Result)i5;
        i4=i5;
l13:
        i5 = (OOC_INT32)sum;
        i2 = *(OOC_INT8*)((_check_pointer(i2, 30958))+36);
        i5 = *(OOC_INT8*)(_check_pointer(i5, 30970));
        i6 = (OOC_INT32)pb;
        i2 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i6, i2, i5);
        instr = (OOC_SSA__Instr)i2;
        OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i3, 1);
        OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i4, 1);
        res = (OOC_SSA__Result)i2;
        goto l28;
      case 5:
        i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31150))+52);
        i3 = OOC_SSA__ResultDesc_ResultIndex((OOC_SSA__Result)i3);
        resultIndex = i3;
        i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 31201))+24);
        i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 31210))+8);
        opnd = (OOC_SSA__Opnd)i4;
        i5 = i4!=(OOC_INT32)0;
        if (!i5) goto l26;
        i3 = i3-1;
        
l17_loop:
        i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 31277))+8);
        opnd = (OOC_SSA__Opnd)i4;
        i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 31312))+8);
        next = (OOC_SSA__Opnd)i5;
        i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 31359));
        i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 31363))+8);
        i6 = *(OOC_INT8*)((_check_pointer(i6, 31369))+36);
        _assert((i6==6), 127, 31348);
        i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 31423));
        i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 31427))+8);
        collect = (OOC_SSA__Instr)i4;
        i6 = (OOC_INT32)OOC_SSA__InstrDesc_NthArg((OOC_SSA__Instr)i4, i3);
        iv = (OOC_SSA__Result)i6;
        i7 = (OOC_INT32)replacement;
        i7 = ADT_Dictionary__DictionaryDesc_HasKey((ADT_Dictionary__Dictionary)i7, (Object__Object)i6);
        if (i7) goto l20;
        i7 = (OOC_INT32)pb;
        i6 = (OOC_INT32)OOC_SSA_LoopRewrite__InitialValue((OOC_SSA__ProcBlock)i7, (OOC_SSA_LoopRewrite__RewrittenCycle)i1, (OOC_SSA__Result)i6, (-1));
        res = (OOC_SSA__Result)i6;
        
        goto l21;
l20:
        i7 = (OOC_INT32)replacement;
        i6 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i7, (Object__Object)i6);
        obj = (Object__Object)i6;
        i6 = _type_guard(i6, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 31646)))), &_td_OOC_SSA__ResultDesc, 31646);
        res = (OOC_SSA__Result)i6;
        
l21:
        OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i4, (OOC_SSA__Result)i6, 1);
        opnd = (OOC_SSA__Opnd)i5;
        i4 = i5!=(OOC_INT32)0;
        if (!i4) goto l26;
        i4=i5;
        goto l17_loop;
l26:
        i3 = (OOC_INT32)sum;
        i3 = *(OOC_INT8*)(_check_pointer(i3, 31920));
        i2 = (OOC_INT32)OOC_SSA__InstrDesc_AddResultSubclass((OOC_SSA__Instr)i2, 14, i3);
        res = (OOC_SSA__Result)i2;
        goto l28;
      default:
        _failed_case(i3, 30165);
        goto l28;
      }
l28:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 31955))+16);
      i2 = _check_pointer(i2, 31968);
      i3 = *(OOC_INT32*)((_check_pointer(i0, 31971))+56);
      i4 = OOC_ARRAY_LENGTH(i2, 0);
      i5 = (OOC_INT32)res;
      *(OOC_INT32*)(i2+(_check_index(i3, i4, OOC_UINT32, 31968))*4) = i5;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32011))+52);
      i3 = (OOC_INT32)replacement;
      ADT_Dictionary__DictionaryDesc_Set((ADT_Dictionary__Dictionary)i3, (Object__Object)i2, (Object__Object)i5);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32040))+48);
      ce = (OOC_SSA_LoopRewrite__CycleElement)i0;
      i2 = i0!=(OOC_INT32)0;
      if (i2) goto l3_loop;
l33:
      return;
      ;
    }

    
    OOC_SSA__Result OOC_SSA_LoopRewrite__Rewrite_ComputeReplacement(OOC_SSA_LoopRewrite__RewrittenCycle rc, OOC_SSA_LoopRewrite__Sum sum) {
      register OOC_INT32 i0,i1,i2,i3,i4;
      OOC_SSA__Result res;
      OOC_SSA__Instr instr;

      i0 = (OOC_INT32)sum;
      i1 = (OOC_INT32)rc;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 32250))+16);
      i1 = _check_pointer(i1, 32263);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32267))+16);
      i2 = *(OOC_INT32*)((_check_pointer(i2, 32270))+56);
      i3 = OOC_ARRAY_LENGTH(i1, 0);
      i4 = *(OOC_INT8*)(_check_pointer(i0, 32280));
      i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(i2, i3, OOC_UINT32, 32263))*4);
      i2 = (OOC_INT32)pb;
      i1 = (OOC_INT32)OOC_SSA__ProcBlockDesc_FixSubclass((OOC_SSA__ProcBlock)i2, (OOC_SSA__Result)i1, i4);
      res = (OOC_SSA__Result)i1;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32306))+32);
      i2 = i2!=0;
      if (!i2) goto l4;
      i2 = *(OOC_INT8*)(_check_pointer(i0, 32371));
      i3 = (OOC_INT32)pb;
      i2 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i3, 19, i2);
      instr = (OOC_SSA__Instr)i2;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i1, 1);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32451))+32);
      i3 = *(OOC_INT8*)(_check_pointer(i0, 32463));
      i1 = (OOC_INT32)OOC_SSA_LoopRewrite__Rewrite_Expr((OOC_SSA_LoopRewrite__PList)i1, i3);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i1, 1);
      res = (OOC_SSA__Result)i2;
      i1=i2;
l4:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32533))+28);
      i2 = i2!=0;
      if (i2) goto l7;
      i0=i1;
      goto l8;
l7:
      i2 = *(OOC_INT8*)(_check_pointer(i0, 32600));
      i3 = (OOC_INT32)pb;
      i2 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i3, 19, i2);
      instr = (OOC_SSA__Instr)i2;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i1, 1);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32680))+28);
      i0 = *(OOC_INT8*)(_check_pointer(i0, 32694));
      i0 = (OOC_INT32)OOC_SSA_LoopRewrite__Rewrite_Expr((OOC_SSA_LoopRewrite__PList)i1, i0);
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i0, 1);
      i0=i2;
l8:
      return (OOC_SSA__Result)i0;
      ;
    }

    
    OOC_CHAR8 OOC_SSA_LoopRewrite__Rewrite_EqualAB(OOC_SSA_LoopRewrite__Sum sum1, OOC_SSA_LoopRewrite__Sum sum2) {
      register OOC_INT32 i0,i1,i2,i3;
      auto OOC_CHAR8 OOC_SSA_LoopRewrite__Rewrite_EqualAB_EqualPList(OOC_SSA_LoopRewrite__PList p1, OOC_SSA_LoopRewrite__PList p2);
        
        OOC_CHAR8 OOC_SSA_LoopRewrite__Rewrite_EqualAB_EqualPList(OOC_SSA_LoopRewrite__PList p1, OOC_SSA_LoopRewrite__PList p2) {
          register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
          OOC_INT32 _i1;
          OOC_INT32 _i2;
          auto OOC_CHAR8 OOC_SSA_LoopRewrite__Rewrite_EqualAB_EqualPList_EqualFactors(OOC_SSA_LoopRewrite__Factors _f1, OOC_SSA_LoopRewrite__Factors _f2);
            
            OOC_CHAR8 OOC_SSA_LoopRewrite__Rewrite_EqualAB_EqualPList_EqualFactors(OOC_SSA_LoopRewrite__Factors _f1, OOC_SSA_LoopRewrite__Factors _f2) {
              register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
              OOC_INT32 i;

              i0 = (OOC_INT32)_f1;
              i1 = (OOC_INT32)_f2;
              i2 = OOC_ARRAY_LENGTH((_check_pointer(i0, 33055)), 0);
              i3 = OOC_ARRAY_LENGTH((_check_pointer(i1, 33066)), 0);
              i2 = i2!=i3;
              if (i2) goto l14;
              i = 0;
              i2 = OOC_ARRAY_LENGTH((_check_pointer(i0, 33148)), 0);
              i3 = 0<i2;
              if (!i3) goto l13;
              i3=0;
l5_loop:
              i4 = _check_pointer(i0, 33176);
              i5 = OOC_ARRAY_LENGTH(i4, 0);
              i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 33176))*4);
              i5 = _check_pointer(i1, 33189);
              i6 = OOC_ARRAY_LENGTH(i5, 0);
              i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i3, i6, OOC_UINT32, 33189))*4);
              i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 33179))+4);
              i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 33192))+4);
              i4 = i4!=i5;
              if (!i4) goto l8;
              return 0u;
l8:
              i3 = i3+1;
              i = i3;
              i4 = i3<i2;
              if (i4) goto l5_loop;
l13:
              return 1u;
              goto l15;
l14:
              return 0u;
l15:
              _failed_function(32947); return 0;
              ;
            }


          _i1 = 0;
          _i2 = 0;
          i0 = (OOC_INT32)p1;
          i1 = *(OOC_INT32*)((_check_pointer(i0, 33403))+4);
          i1 = 0!=i1;
          if (i1) goto l3;
          i1=0u;
          goto l4;
l3:
          i1 = (OOC_INT32)p2;
          i1 = *(OOC_INT32*)((_check_pointer(i1, 33420))+4);
          i1 = 0!=i1;
          
l4:
          i2 = (OOC_INT32)p2;
          if (i1) goto l7;
          i1=0;i3=0;
          goto l33;
l7:
          i1=0;i3=0;
l8_loop:
          i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 33446));
          i4 = _check_pointer(i4, 33451);
          i5 = OOC_ARRAY_LENGTH(i4, 0);
          i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i1, i5, OOC_UINT32, 33451))*4);
          i4 = *(OOC_INT32*)(_check_pointer(i4, 33455));
          i4 = i4==0;
          if (i4) goto l23;
          i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 33516));
          i4 = _check_pointer(i4, 33521);
          i5 = OOC_ARRAY_LENGTH(i4, 0);
          i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 33521))*4);
          i4 = *(OOC_INT32*)(_check_pointer(i4, 33525));
          i4 = i4==0;
          if (i4) goto l21;
          i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 33586));
          i4 = _check_pointer(i4, 33591);
          i5 = OOC_ARRAY_LENGTH(i4, 0);
          i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i1, i5, OOC_UINT32, 33591))*4);
          i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 33610));
          i5 = _check_pointer(i5, 33615);
          i6 = OOC_ARRAY_LENGTH(i5, 0);
          i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i3, i6, OOC_UINT32, 33615))*4);
          i5 = *(OOC_INT32*)(_check_pointer(i5, 33619));
          i4 = *(OOC_INT32*)(_check_pointer(i4, 33595));
          i4 = i4!=i5;
          if (i4) goto l15;
          i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 33687));
          i4 = _check_pointer(i4, 33692);
          i5 = OOC_ARRAY_LENGTH(i4, 0);
          i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 33692))*4);
          i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 33666));
          i5 = _check_pointer(i5, 33671);
          i6 = OOC_ARRAY_LENGTH(i5, 0);
          i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i1, i6, OOC_UINT32, 33671))*4);
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 33696))+4);
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 33675))+4);
          i4 = OOC_SSA_LoopRewrite__Rewrite_EqualAB_EqualPList_EqualFactors((OOC_SSA_LoopRewrite__Factors)i5, (OOC_SSA_LoopRewrite__Factors)i4);
          i4 = !i4;
          
          goto l17;
l15:
          i4=1u;
l17:
          if (i4) goto l19;
          i1 = i1+1;
          _i1 = i1;
          i3 = i3+1;
          _i2 = i3;
          
          goto l24;
l19:
          return 0u;
          
          goto l24;
l21:
          i3 = i3+1;
          _i2 = i3;
          
          goto l24;
l23:
          i1 = i1+1;
          _i1 = i1;
          
l24:
          i4 = *(OOC_INT32*)((_check_pointer(i0, 33403))+4);
          i4 = i1!=i4;
          if (i4) goto l27;
          i4=0u;
          goto l29;
l27:
          i4 = *(OOC_INT32*)((_check_pointer(i2, 33420))+4);
          i4 = i3!=i4;
          
l29:
          if (i4) goto l8_loop;
l33:
          i4 = *(OOC_INT32*)((_check_pointer(i0, 33832))+4);
          i4 = i1!=i4;
          if (i4) goto l36;
          i4=0u;
          goto l38;
l36:
          i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 33844));
          i4 = _check_pointer(i4, 33849);
          i5 = OOC_ARRAY_LENGTH(i4, 0);
          i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i1, i5, OOC_UINT32, 33849))*4);
          i4 = *(OOC_INT32*)(_check_pointer(i4, 33853));
          i4 = i4==0;
          
l38:
          if (!i4) goto l50;
l41_loop:
          i1 = i1+1;
          _i1 = i1;
          i4 = *(OOC_INT32*)((_check_pointer(i0, 33832))+4);
          i4 = i1!=i4;
          if (i4) goto l44;
          i4=0u;
          goto l46;
l44:
          i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 33844));
          i4 = _check_pointer(i4, 33849);
          i5 = OOC_ARRAY_LENGTH(i4, 0);
          i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i1, i5, OOC_UINT32, 33849))*4);
          i4 = *(OOC_INT32*)(_check_pointer(i4, 33853));
          i4 = i4==0;
          
l46:
          if (i4) goto l41_loop;
l50:
          i4 = *(OOC_INT32*)((_check_pointer(i2, 33926))+4);
          i4 = i3!=i4;
          if (i4) goto l53;
          i4=0u;
          goto l55;
l53:
          i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 33938));
          i4 = _check_pointer(i4, 33943);
          i5 = OOC_ARRAY_LENGTH(i4, 0);
          i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 33943))*4);
          i4 = *(OOC_INT32*)(_check_pointer(i4, 33947));
          i4 = i4==0;
          
l55:
          if (!i4) goto l67;
l58_loop:
          i3 = i3+1;
          _i2 = i3;
          i4 = *(OOC_INT32*)((_check_pointer(i2, 33926))+4);
          i4 = i3!=i4;
          if (i4) goto l61;
          i4=0u;
          goto l63;
l61:
          i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 33938));
          i4 = _check_pointer(i4, 33943);
          i5 = OOC_ARRAY_LENGTH(i4, 0);
          i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 33943))*4);
          i4 = *(OOC_INT32*)(_check_pointer(i4, 33947));
          i4 = i4==0;
          
l63:
          if (i4) goto l58_loop;
l67:
          i0 = *(OOC_INT32*)((_check_pointer(i0, 34021))+4);
          i0 = i1==i0;
          if (i0) goto l70;
          i0=0u;
          goto l71;
l70:
          i0 = *(OOC_INT32*)((_check_pointer(i2, 34038))+4);
          i0 = i3==i0;
          
l71:
          return i0;
          ;
        }


      i0 = (OOC_INT32)sum2;
      i1 = (OOC_INT32)sum1;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34126))+20);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34111))+20);
      i2 = OOC_SSA_LoopRewrite__Rewrite_EqualAB_EqualPList((OOC_SSA_LoopRewrite__PList)i3, (OOC_SSA_LoopRewrite__PList)i2);
      if (i2) goto l3;
      i0=0u;
      goto l4;
l3:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34189))+24);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34169))+24);
      i0 = OOC_SSA_LoopRewrite__Rewrite_EqualAB_EqualPList((OOC_SSA_LoopRewrite__PList)i1, (OOC_SSA_LoopRewrite__PList)i0);
      
l4:
      return i0;
      ;
    }


  i0 = (OOC_INT32)sum;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34247))+16);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34250))+60);
  ic = (OOC_SSA_LoopRewrite__InductionCycle)i1;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34267))+88);
  rc = (OOC_SSA_LoopRewrite__RewrittenCycle)i1;
  i2 = i1!=(OOC_INT32)0;
  if (i2) goto l3;
  i0=0u;
  goto l5;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34324))+4);
  i0 = OOC_SSA_LoopRewrite__Rewrite_EqualAB((OOC_SSA_LoopRewrite__Sum)i0, (OOC_SSA_LoopRewrite__Sum)i1);
  i0 = !i0;
  
l5:
  if (!i0) goto l15;
l6_loop:
  i0 = (OOC_INT32)rc;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 34350));
  rc = (OOC_SSA_LoopRewrite__RewrittenCycle)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l9;
  i0=0u;
  goto l11;
l9:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34324))+4);
  i1 = (OOC_INT32)sum;
  i0 = OOC_SSA_LoopRewrite__Rewrite_EqualAB((OOC_SSA_LoopRewrite__Sum)i1, (OOC_SSA_LoopRewrite__Sum)i0);
  i0 = !i0;
  
l11:
  if (i0) goto l6_loop;
l15:
  i0 = (OOC_INT32)rc;
  i0 = i0==(OOC_INT32)0;
  if (!i0) goto l34;
  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_SSA_LoopRewrite__RewrittenCycle.baseTypes[0]);
  rc = (OOC_SSA_LoopRewrite__RewrittenCycle)i0;
  i1 = (OOC_INT32)ic;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34471))+88);
  *(OOC_INT32*)(_check_pointer(i0, 34460)) = i2;
  *(OOC_INT32*)((_check_pointer(i1, 34497))+88) = i0;
  i1 = (OOC_INT32)sum;
  *(OOC_INT32*)((_check_pointer(i0, 34529))+4) = i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34565))+20);
  i3 = (OOC_INT32)OOC_SSA_LoopRewrite__one;
  i2 = i2!=i3;
  if (i2) goto l20;
  *(OOC_INT32*)((_check_pointer(i0, 34658))+8) = (OOC_INT32)0;
  goto l21;
l20:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34611))+20);
  i1 = *(OOC_INT8*)(_check_pointer(i1, 34625));
  i1 = (OOC_INT32)OOC_SSA_LoopRewrite__Rewrite_Expr((OOC_SSA_LoopRewrite__PList)i2, i1);
  *(OOC_INT32*)((_check_pointer(i0, 34597))+8) = i1;
l21:
  i0 = (OOC_INT32)sum;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34693))+24);
  i1 = i1!=(OOC_INT32)0;
  if (i1) goto l24;
  i0 = (OOC_INT32)rc;
  *(OOC_INT32*)((_check_pointer(i0, 34797))+12) = (OOC_INT32)0;
  goto l25;
l24:
  i1 = (OOC_INT32)rc;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34745))+24);
  i0 = *(OOC_INT8*)(_check_pointer(i0, 34764));
  i0 = (OOC_INT32)OOC_SSA_LoopRewrite__Rewrite_Expr((OOC_SSA_LoopRewrite__PList)i2, i0);
  *(OOC_INT32*)((_check_pointer(i1, 34731))+12) = i0;
l25:
  i0 = (OOC_INT32)sum;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34979))+16);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34982))+60);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34985))+52);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34989))+8);
  loopStart = (OOC_SSA__Instr)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 35023))+24);
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 35032));
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 35036))+8);
  collect = (OOC_SSA__Instr)i2;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35122))+16);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 35125))+60);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 35128))+52);
  i3 = OOC_SSA__ResultDesc_ResultIndex((OOC_SSA__Result)i3);
  i3 = (OOC_INT32)OOC_SSA__InstrDesc_NthArg((OOC_SSA__Instr)i2, (i3-1));
  i4 = (OOC_INT32)pb;
  i5 = (OOC_INT32)rc;
  i3 = (OOC_INT32)OOC_SSA_LoopRewrite__InitialValue((OOC_SSA__ProcBlock)i4, (OOC_SSA_LoopRewrite__RewrittenCycle)i5, (OOC_SSA__Result)i3, (-1));
  res = (OOC_SSA__Result)i3;
  OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i3, 1);
  i2 = (OOC_INT32)ADT_Dictionary__New();
  replacement = (ADT_Dictionary__Dictionary)i2;
  i3 = *(OOC_INT8*)(_check_pointer(i0, 35445));
  i1 = (OOC_INT32)OOC_SSA__InstrDesc_AddResultSubclass((OOC_SSA__Instr)i1, 14, i3);
  res = (OOC_SSA__Result)i1;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35482))+16);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35485))+60);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35488))+52);
  ADT_Dictionary__DictionaryDesc_Set((ADT_Dictionary__Dictionary)i2, (Object__Object)i0, (Object__Object)i1);
  i0 = (OOC_INT32)ic;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 35529))+84);
  *(OOC_INT32*)((_check_pointer(i5, 35512))+16) = ((OOC_INT32)RT0__NewObject(_td_OOC_SSA_LoopRewrite__5868.baseTypes[0], i2));
  i = 0;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 35566))+84);
  i3 = 0<i2;
  if (!i3) goto l33;
  i3=0;
l28_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 35594))+16);
  i4 = _check_pointer(i4, 35607);
  i6 = OOC_ARRAY_LENGTH(i4, 0);
  *(OOC_INT32*)(i4+(_check_index(i3, i6, OOC_UINT32, 35607))*4) = (OOC_INT32)0;
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l28_loop;
l33:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 35638))+16);
  i2 = _check_pointer(i2, 35651);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  *(OOC_INT32*)(i2+(_check_index(0, i3, OOC_UINT8, 35651))*4) = i1;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35757))+48);
  OOC_SSA_LoopRewrite__Rewrite_RewriteCycle((OOC_SSA_LoopRewrite__RewrittenCycle)i5, (OOC_SSA_LoopRewrite__CycleElement)i0);
  i0 = (OOC_INT32)loopStart;
  i0 = (OOC_INT32)OOC_SSA__InstrDesc_GetLoopEnd((OOC_SSA__Instr)i0);
  loopEnd = (OOC_SSA__Instr)i0;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35913))+24);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35922))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 35931));
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35935))+8);
  collect = (OOC_SSA__Instr)i0;
  i1 = (OOC_INT32)rc;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 35967))+16);
  i2 = _check_pointer(i2, 35980);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 35987))+16);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 36000)), 0);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index((i1-1), i3, OOC_UINT32, 35980))*4);
  OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i1, 1);
l34:
  i0 = (OOC_INT32)sum;
  i1 = (OOC_INT32)rc;
  i1 = (OOC_INT32)OOC_SSA_LoopRewrite__Rewrite_ComputeReplacement((OOC_SSA_LoopRewrite__RewrittenCycle)i1, (OOC_SSA_LoopRewrite__Sum)i0);
  *(OOC_INT32*)((_check_pointer(i0, 36110))+36) = i1;
  return;
  ;
}

static OOC_INT8 OOC_SSA_LoopRewrite__ClassifyUse(OOC_SSA__Opnd use, OOC_SSA_LoopRewrite__InductionCycle ic) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_SSA__Instr instr;
  OOC_SSA__Instr target;
  OOC_SSA__Result res;
  OOC_INT8 min;
  OOC_SSA__Opnd recUse;
  OOC_INT8 x;
  OOC_SSA_LoopRewrite__Sum sum;

  i0 = (OOC_INT32)use;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36378))+12);
  instr = (OOC_SSA__Instr)i1;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 36399))+20);
  i2 = i2==(-1);
  if (i2) goto l94;
  i2 = *(OOC_INT8*)((_check_pointer(i0, 36477))+4);
  i2 = i2==13;
  if (i2) goto l92;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 36557))+16);
  i2 = i2==(OOC_INT32)0;
  if (i2) goto l90;
  i2 = *(OOC_INT8*)((_check_pointer(i1, 36620))+36);
  i2 = i2==6;
  if (i2) goto l55;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 37379))+16);
  i0 = i0!=(OOC_INT32)0;
  if (i0) goto l11;
  i0=0u;
  goto l13;
l11:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 37400))+16);
  i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37406)))), &_td_OOC_SSA_LoopRewrite__CycleElementDesc);
  
l13:
  if (i0) goto l15;
  i0=0u;
  goto l17;
l15:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 37441))+16);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37447)))), &_td_OOC_SSA_LoopRewrite__CycleElementDesc, 37447)), 37460))+60);
  i2 = (OOC_INT32)ic;
  i0 = i0==i2;
  
l17:
  if (i0) goto l53;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 37534))+16);
  i0 = _type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37540)))), &_td_OOC_SSA_LoopRewrite__SumDesc, 37540);
  sum = (OOC_SSA_LoopRewrite__Sum)i0;
  i2 = *(OOC_UINT8*)((_check_pointer(i0, 37558))+12);
  if (i2) goto l51;
  i2 = *(OOC_INT8*)((_check_pointer(i0, 37641))+40);
  i2 = i2>=0;
  if (i2) goto l49;
  min = 127;
  res = (OOC_SSA__Result)i1;
  i2 = i1!=(OOC_INT32)0;
  if (i2) goto l25;
  i1=127;
  goto l44;
l25:
  i2 = (OOC_INT32)ic;
  i3=127;
l26_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 37806))+12);
  recUse = (OOC_SSA__Opnd)i4;
  i5 = i4!=(OOC_INT32)0;
  if (!i5) goto l39;
  {register OOC_INT32 h0=i3;i3=i4;i4=h0;}
l30_loop:
  i5 = OOC_SSA_LoopRewrite__ClassifyUse((OOC_SSA__Opnd)i3, (OOC_SSA_LoopRewrite__InductionCycle)i2);
  x = i5;
  i6 = i5<i4;
  if (!i6) goto l34;
  min = i5;
  i4=i5;
l34:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 37991))+16);
  recUse = (OOC_SSA__Opnd)i3;
  i5 = i3!=(OOC_INT32)0;
  if (i5) goto l30_loop;
l38:
  i3=i4;
l39:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 38036));
  res = (OOC_SSA__Result)i1;
  i4 = i1!=(OOC_INT32)0;
  if (i4) goto l26_loop;
l43:
  i1=i3;
l44:
  i2 = i1==0;
  if (!i2) goto l48;
  min = 1;
  i1=1;
l48:
  *(OOC_INT8*)((_check_pointer(i0, 38166))+40) = i1;
  return i1;
  goto l95;
l49:
  i0 = *(OOC_INT8*)((_check_pointer(i0, 37680))+40);
  return i0;
  goto l95;
l51:
  return 2;
  goto l95;
l53:
  return 3;
  goto l95;
l55:
  i1 = (OOC_INT32)OOC_SSA__InstrDesc_GetCollectTarget((OOC_SSA__Instr)i1);
  target = (OOC_SSA__Instr)i1;
  i0 = OOC_SSA__OpndDesc_OpndIndex((OOC_SSA__Opnd)i0);
  i0 = (OOC_INT32)OOC_SSA__InstrDesc_NthResult((OOC_SSA__Instr)i1, (i0+1));
  res = (OOC_SSA__Result)i0;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36756))+16);
  i2 = i2!=(OOC_INT32)0;
  if (i2) goto l58;
  i2=0u;
  goto l60;
l58:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36775))+16);
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 36781)))), &_td_OOC_SSA_LoopRewrite__CycleElementDesc);
  
l60:
  if (i2) goto l62;
  i2=0u;
  goto l64;
l62:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36813))+16);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 36819)))), &_td_OOC_SSA_LoopRewrite__CycleElementDesc, 36819)), 36832))+60);
  i3 = (OOC_INT32)ic;
  i2 = i2==i3;
  
l64:
  if (i2) goto l87;
  i1 = *(OOC_INT8*)((_check_pointer(i1, 36900))+36);
  i1 = i1==10;
  if (i1) goto l85;
  min = 127;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 37028))+12);
  recUse = (OOC_SSA__Opnd)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l70;
  i0=127;
  goto l80;
l70:
  i1 = (OOC_INT32)ic;
  i2=127;
l71_loop:
  i3 = OOC_SSA_LoopRewrite__ClassifyUse((OOC_SSA__Opnd)i0, (OOC_SSA_LoopRewrite__InductionCycle)i1);
  x = i3;
  i4 = i3<i2;
  if (!i4) goto l75;
  min = i3;
  i2=i3;
l75:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 37201))+16);
  recUse = (OOC_SSA__Opnd)i0;
  i3 = i0!=(OOC_INT32)0;
  if (i3) goto l71_loop;
l79:
  i0=i2;
l80:
  i1 = i0==0;
  if (i1) goto l83;
  return i0;
  goto l95;
l83:
  return 1;
  goto l95;
l85:
  return 4;
  goto l95;
l87:
  return 3;
  goto l95;
l90:
  return 0;
  goto l95;
l92:
  return 4;
  goto l95;
l94:
  return 3;
l95:
  _failed_function(36181); return 0;
  ;
}

static void OOC_SSA_LoopRewrite__RewriteUses(OOC_SSA__ProcBlock pb, OOC_SSA_LoopRewrite__RewrittenCycle rc, OOC_SSA_LoopRewrite__CycleElement ce) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_SSA__Opnd use;
  OOC_SSA__Opnd nextUse;
  OOC_SSA__Instr instr;
  OOC_INT8 newOpcode;
  OOC_SSA__Instr _new;
  OOC_SSA__Result other;
  OOC_SSA__Result res;
  auto OOC_INT8 OOC_SSA_LoopRewrite__RewriteUses_SignPList(OOC_SSA_LoopRewrite__PList a);
    
    OOC_INT8 OOC_SSA_LoopRewrite__RewriteUses_SignPList(OOC_SSA_LoopRewrite__PList a) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_INT8 sign;
      OOC_INT32 i;
      OOC_INT8 fSign;
      auto OOC_INT8 OOC_SSA_LoopRewrite__RewriteUses_SignPList_SignProduct(OOC_SSA_LoopRewrite__Product a);
        
        OOC_INT8 OOC_SSA_LoopRewrite__RewriteUses_SignPList_SignProduct(OOC_SSA_LoopRewrite__Product a) {
          register OOC_INT32 i0,i1,i2,i3;
          OOC_INT8 sign;
          OOC_INT32 i;
          OOC_INT8 aSign;
          auto OOC_INT8 OOC_SSA_LoopRewrite__RewriteUses_SignPList_SignProduct_SignAtom(OOC_SSA_LoopRewrite__Sum a);
            
            OOC_INT8 OOC_SSA_LoopRewrite__RewriteUses_SignPList_SignProduct_SignAtom(OOC_SSA_LoopRewrite__Sum a) {
              register OOC_INT32 i0,i1;
              OOC_SSA__Const _const;

              i0 = (OOC_INT32)a;
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 38766))+4);
              i1 = i1==(OOC_INT32)0;
              if (i1) goto l12;
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 38849))+4);
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 38854))+8);
              i1 = *(OOC_INT8*)((_check_pointer(i1, 38860))+36);
              switch (i1) {
              case 0:
                i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 38923))+4);
                i0 = _type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 38933)))), &_td_OOC_SSA__ConstDesc, 38933);
                _const = (OOC_SSA__Const)i0;
                i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 38964))+44);
                i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 38971)))), &_td_Object_BigInt__BigIntDesc);
                if (i1) goto l7;
                return (-2);
                goto l13;
l7:
                i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 39034))+44);
                i0 = Object_BigInt__BigIntDesc_Sign((Object_BigInt__BigInt)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 39048)))), &_td_Object_BigInt__BigIntDesc, 39048)));
                return i0;
                goto l13;
              case 56:
              case 57:
                return 1;
                goto l13;
              default:
                return (-2);
                goto l13;
              }
l12:
              return (-2);
l13:
              _failed_function(38669); return 0;
              ;
            }


          i0 = (OOC_INT32)a;
          i1 = *(OOC_INT32*)(_check_pointer(i0, 39390));
          i1 = i1==0;
          if (i1) goto l26;
          sign = 1;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 39515))+4);
          i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 39523)), 0);
          i = 0;
          i1 = 0<i0;
          if (!i1) goto l21;
          i1=0;
l5_loop:
          i2 = (OOC_INT32)a;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 39562))+4);
          i2 = _check_pointer(i2, 39570);
          i3 = OOC_ARRAY_LENGTH(i2, 0);
          i1 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i1, i3, OOC_UINT32, 39570))*4);
          i1 = OOC_SSA_LoopRewrite__RewriteUses_SignPList_SignProduct_SignAtom((OOC_SSA_LoopRewrite__Sum)i1);
          aSign = i1;
          i2 = i1==(-2);
          if (i2) goto l15;
          i2 = i1==0;
          if (i2) goto l13;
          i1 = i1==(-1);
          if (!i1) goto l16;
          i1 = sign;
          sign = (-i1);
          goto l16;
l13:
          return 0;
          goto l16;
l15:
          return (-2);
l16:
          i1 = i;
          i1 = i1+1;
          i = i1;
          i2 = i1<i0;
          if (i2) goto l5_loop;
l21:
          i0 = (OOC_INT32)a;
          i0 = *(OOC_INT32*)(_check_pointer(i0, 39850));
          i0 = i0<0;
          if (i0) goto l24;
          i0 = sign;
          return i0;
          goto l27;
l24:
          i0 = sign;
          return (-i0);
          goto l27;
l26:
          return 0;
l27:
          _failed_function(38556); return 0;
          ;
        }


      i0 = (OOC_INT32)a;
      i1 = *(OOC_INT32*)((_check_pointer(i0, 40014))+4);
      i1 = i1==0;
      if (i1) goto l25;
      sign = 0;
      i = 0;
      i0 = *(OOC_INT32*)((_check_pointer(i0, 40115))+4);
      i1 = 0<i0;
      if (!i1) goto l24;
      i1=0;
l5_loop:
      i2 = (OOC_INT32)a;
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 40158));
      i2 = _check_pointer(i2, 40163);
      i3 = OOC_ARRAY_LENGTH(i2, 0);
      i1 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i1, i3, OOC_UINT32, 40163))*4);
      i1 = OOC_SSA_LoopRewrite__RewriteUses_SignPList_SignProduct((OOC_SSA_LoopRewrite__Product)i1);
      fSign = i1;
      i2 = i1==(-2);
      if (i2) goto l18;
      i2 = i1==0;
      if (i2) goto l19;
      i2 = sign;
      i3 = i2==0;
      if (i3) goto l15;
      i1 = i2!=i1;
      if (!i1) goto l19;
      return (-2);
      goto l19;
l15:
      sign = i1;
      
      goto l19;
l18:
      return (-2);
l19:
      i1 = i;
      i1 = i1+1;
      i = i1;
      i2 = i1<i0;
      if (i2) goto l5_loop;
l24:
      i0 = sign;
      return i0;
      goto l26;
l25:
      return 0;
l26:
      _failed_function(38455); return 0;
      ;
    }


  i0 = (OOC_INT32)ce;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 40661))+52);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 40665))+12);
  use = (OOC_SSA__Opnd)i0;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l73;
l3_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 40720))+16);
  nextUse = (OOC_SSA__Opnd)i1;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 40755))+12);
  instr = (OOC_SSA__Instr)i1;
  i2 = *(OOC_INT8*)((_check_pointer(i1, 40792))+36);
  i2 = 25<=i2;
  if (i2) goto l6;
  i2=0u;
  goto l8;
l6:
  i2 = *(OOC_INT8*)((_check_pointer(i1, 40809))+36);
  i2 = i2<=30;
  
l8:
  if (i2) goto l25;
  i1 = (OOC_INT32)ce;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 42620))+60);
  i2 = OOC_SSA_LoopRewrite__ClassifyUse((OOC_SSA__Opnd)i0, (OOC_SSA_LoopRewrite__InductionCycle)i2);
  i2 = i2==0;
  if (!i2) goto l68;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 42712))+44);
  i2 = i2==(OOC_INT32)0;
  if (i2) goto l14;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 43370))+44);
  res = (OOC_SSA__Result)i1;
  
  goto l23;
l14:
  i2 = (OOC_INT32)rc;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 42756))+16);
  i3 = _check_pointer(i3, 42769);
  i4 = *(OOC_INT32*)((_check_pointer(i1, 42772))+56);
  i5 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i4, i5, OOC_UINT32, 42769))*4);
  res = (OOC_SSA__Result)i3;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 42806))+12);
  i5 = (OOC_INT32)pb;
  i4 = i4!=(OOC_INT32)0;
  if (!i4) goto l18;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 42871))+4);
  i4 = *(OOC_INT8*)(_check_pointer(i4, 42878));
  i4 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i5, 20, i4);
  _new = (OOC_SSA__Instr)i4;
  OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i4, (OOC_SSA__Result)i3, 1);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 42956))+12);
  OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i4, (OOC_SSA__Result)i3, 1);
  res = (OOC_SSA__Result)i4;
  i3=i4;
l18:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 43037))+8);
  i4 = i4!=(OOC_INT32)0;
  if (i4) goto l21;
  i2=i3;
  goto l22;
l21:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 43100))+4);
  i4 = *(OOC_INT8*)(_check_pointer(i4, 43107));
  i4 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i5, 23, i4);
  _new = (OOC_SSA__Instr)i4;
  OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i4, (OOC_SSA__Result)i3, 1);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 43185))+8);
  OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i4, (OOC_SSA__Result)i2, 1);
  res = (OOC_SSA__Result)i4;
  i2=i4;
l22:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 43289))+52);
  i3 = *(OOC_INT8*)((_check_pointer(i3, 43293))+5);
  i2 = (OOC_INT32)OOC_SSA__ProcBlockDesc_FixSubclass((OOC_SSA__ProcBlock)i5, (OOC_SSA__Result)i2, i3);
  res = (OOC_SSA__Result)i2;
  *(OOC_INT32*)((_check_pointer(i1, 43317))+44) = i2;
  i1=i2;
l23:
  OOC_SSA__OpndDesc_ReplaceArg((OOC_SSA__Opnd)i0, (OOC_SSA__Result)i1);
  goto l68;
l25:
  i0 = *(OOC_INT8*)((_check_pointer(i1, 40863))+36);
  newOpcode = i0;
  i0 = i0>26;
  if (!i0) goto l41;
  i0 = (OOC_INT32)rc;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 40940))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 40947))+20);
  i0 = OOC_SSA_LoopRewrite__RewriteUses_SignPList((OOC_SSA_LoopRewrite__PList)i0);
  switch (i0) {
  case 1:
  case 0:
    goto l41;
  case (-1):
    i0 = newOpcode;
    switch (i0) {
    case 27:
      newOpcode = 29;
      
      goto l41;
    case 28:
      newOpcode = 30;
      
      goto l41;
    case 29:
      newOpcode = 27;
      
      goto l41;
    case 30:
      newOpcode = 28;
      
      goto l41;
    default:
      _failed_case(i0, 41099);
      
      goto l41;
    }
    /* goto: unreachable */
  case (-2):
    newOpcode = (-1);
    goto l41;
  default:
    _failed_case(i0, 40923);
    goto l41;
  }
l41:
  i0 = newOpcode;
  i1 = i0>=0;
  if (!i1) goto l68;
  _new = (OOC_SSA__Instr)(OOC_INT32)0;
  i1 = (OOC_INT32)rc;
  i2 = (OOC_INT32)use;
  i2 = OOC_SSA__OpndDesc_OpndIndex((OOC_SSA__Opnd)i2);
  switch (i2) {
  case 0:
    i2 = (OOC_INT32)instr;
    i2 = (OOC_INT32)OOC_SSA__InstrDesc_NthArg((OOC_SSA__Instr)i2, 1);
    other = (OOC_SSA__Result)i2;
    i3 = *(OOC_INT32*)((_check_pointer(i2, 41635))+20);
    i3 = i3==1;
    if (i3) goto l48;
    i0=(OOC_INT32)0;
    goto l56;
l48:
    i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 41711))+4);
    i3 = *(OOC_INT8*)(_check_pointer(i3, 41718));
    i4 = (OOC_INT32)pb;
    i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i4, i0, i3);
    _new = (OOC_SSA__Instr)i0;
    i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 41758))+16);
    i3 = _check_pointer(i3, 41771);
    i5 = (OOC_INT32)ce;
    i5 = *(OOC_INT32*)((_check_pointer(i5, 41774))+56);
    i6 = OOC_ARRAY_LENGTH(i3, 0);
    i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i5, i6, OOC_UINT32, 41771))*4);
    OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i3, 1);
    i2 = (OOC_INT32)OOC_SSA_LoopRewrite__InitialValue((OOC_SSA__ProcBlock)i4, (OOC_SSA_LoopRewrite__RewrittenCycle)i1, (OOC_SSA__Result)i2, (-1));
    OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i2, 1);
    
    goto l56;
  case 1:
    i2 = (OOC_INT32)instr;
    i2 = (OOC_INT32)OOC_SSA__InstrDesc_NthArg((OOC_SSA__Instr)i2, 0);
    other = (OOC_SSA__Result)i2;
    i3 = *(OOC_INT32*)((_check_pointer(i2, 41987))+20);
    i3 = i3==1;
    if (i3) goto l53;
    i0=(OOC_INT32)0;
    goto l56;
l53:
    i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 42063))+4);
    i3 = *(OOC_INT8*)(_check_pointer(i3, 42070));
    i4 = (OOC_INT32)pb;
    i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i4, i0, i3);
    _new = (OOC_SSA__Instr)i0;
    i2 = (OOC_INT32)OOC_SSA_LoopRewrite__InitialValue((OOC_SSA__ProcBlock)i4, (OOC_SSA_LoopRewrite__RewrittenCycle)i1, (OOC_SSA__Result)i2, (-1));
    OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i2, 1);
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 42188))+16);
    i2 = _check_pointer(i2, 42201);
    i3 = (OOC_INT32)ce;
    i3 = *(OOC_INT32*)((_check_pointer(i3, 42204))+56);
    i4 = OOC_ARRAY_LENGTH(i2, 0);
    i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i3, i4, OOC_UINT32, 42201))*4);
    OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i2, 1);
    
    goto l56;
  default:
    _failed_case(i2, 41537);
    i0=(OOC_INT32)0;
    goto l56;
  }
l56:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 42324))+4);
  i2 = *(OOC_INT8*)(_check_pointer(i2, 42331));
  i2 = i2==9;
  if (i2) goto l59;
  i2=0u;
  goto l61;
l59:
  i2 = i0!=(OOC_INT32)0;
  
l61:
  if (!i2) goto l68;
  i2 = (OOC_INT32)instr;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 42415))+16);
  i3 = i3==(OOC_INT32)0;
  if (!i3) goto l65;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 42470))+4);
  i1 = *(OOC_INT8*)(_check_pointer(i1, 42477));
  i1 = (OOC_INT32)OOC_SSA_LoopRewrite__NewSum(i1, (OOC_SSA__Result)(OOC_INT32)0);
  *(OOC_INT32*)((_check_pointer(i2, 42452))+16) = i1;
l65:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 42528))+16);
  *(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 42534)))), &_td_OOC_SSA_LoopRewrite__SumDesc, 42534)), 42538))+36) = i0;
l68:
  i0 = (OOC_INT32)nextUse;
  use = (OOC_SSA__Opnd)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l3_loop;
l73:
  return;
  ;
}

static void OOC_SSA_LoopRewrite__ClassifyCEUses(OOC_SSA__ProcBlock pb, OOC_SSA__Instr loopStart) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_SSA__Result res;
  OOC_SSA_LoopRewrite__InductionCycle ic;
  OOC_SSA_LoopRewrite__CycleElement ce;
  OOC_SSA__Opnd use;

  i0 = (OOC_INT32)loopStart;
  res = (OOC_SSA__Result)i0;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l31;
  
l3_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 43724))+16);
  i1 = i1!=(OOC_INT32)0;
  if (i1) goto l6;
  i1=0u;
  goto l8;
l6:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 43743))+16);
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 43749)))), &_td_OOC_SSA_LoopRewrite__InductionCycleDesc);
  
l8:
  if (!i1) goto l26;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 43790))+16);
  i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 43796)))), &_td_OOC_SSA_LoopRewrite__InductionCycleDesc, 43796);
  ic = (OOC_SSA_LoopRewrite__InductionCycle)i1;
  ce = (OOC_SSA_LoopRewrite__CycleElement)i1;
  i2 = i1!=(OOC_INT32)0;
  if (!i2) goto l26;
  i2=i1;
l12_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 43878))+52);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 43882))+12);
  use = (OOC_SSA__Opnd)i3;
  i4 = i3!=(OOC_INT32)0;
  if (!i4) goto l20;
l15_loop:
  i4 = OOC_SSA_LoopRewrite__ClassifyUse((OOC_SSA__Opnd)i3, (OOC_SSA_LoopRewrite__InductionCycle)i1);
  i5 = OOC_SSA_LoopRewrite__ClassifyUse((OOC_SSA__Opnd)i3, (OOC_SSA_LoopRewrite__InductionCycle)i1);
  i5 = *(OOC_INT32*)(((_check_pointer(i2, 43941))+64)+(_check_index(i5, 5, OOC_UINT8, 43950))*4);
  *(OOC_INT32*)(((_check_pointer(i2, 43941))+64)+(_check_index(i4, 5, OOC_UINT8, 43950))*4) = (i5+1);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 43997))+16);
  use = (OOC_SSA__Opnd)i3;
  i4 = i3!=(OOC_INT32)0;
  if (i4) goto l15_loop;
l20:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 44229))+48);
  ce = (OOC_SSA_LoopRewrite__CycleElement)i2;
  i3 = i2!=(OOC_INT32)0;
  if (i3) goto l12_loop;
l26:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 44276));
  res = (OOC_SSA__Result)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l3_loop;
l31:
  return;
  ;
}

static void OOC_SSA_LoopRewrite__InstallEquivCE(OOC_SSA__ProcBlock pb, OOC_SSA__Instr loopStart) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
  OOC_SSA__Instr loopEnd;
  OOC_SSA__Instr anchor;
  OOC_SSA__Result storeOut;
  OOC_SSA__Result res;
  OOC_SSA_LoopRewrite__RewrittenCycle rc;
  OOC_SSA_LoopRewrite__CycleElement ce;
  OOC_SSA__Instr equiv;
  auto OOC_CHAR8 OOC_SSA_LoopRewrite__InstallEquivCE_UsedOutsideLoop(OOC_SSA__Result res);
    
    OOC_CHAR8 OOC_SSA_LoopRewrite__InstallEquivCE_UsedOutsideLoop(OOC_SSA__Result res) {
      register OOC_INT32 i0,i1;
      OOC_SSA__Opnd use;

      i0 = (OOC_INT32)res;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 44621))+12);
      use = (OOC_SSA__Opnd)i0;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l15;
l3_loop:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 44673))+12);
      i1 = *(OOC_INT32*)((_check_pointer(i1, 44679))+20);
      i1 = i1!=1;
      if (i1) goto l6;
      i1=0u;
      goto l8;
l6:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 44710))+12);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 44716))+16);
      i1 = i1==(OOC_INT32)0;
      
l8:
      if (!i1) goto l10;
      return 1u;
l10:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 44788))+16);
      use = (OOC_SSA__Opnd)i0;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l3_loop;
l15:
      return 0u;
      ;
    }


  i0 = (OOC_INT32)loopStart;
  i1 = (OOC_INT32)OOC_SSA__InstrDesc_GetLoopEnd((OOC_SSA__Instr)i0);
  loopEnd = (OOC_SSA__Instr)i1;
  i2 = (OOC_INT32)pb;
  i3 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i2, 88, 0);
  anchor = (OOC_SSA__Instr)i3;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 45112));
  storeOut = (OOC_SSA__Result)i1;
  i4 = (OOC_INT32)OOC_SSA__InstrDesc_AddResult((OOC_SSA__Instr)i3, 2);
  OOC_SSA__ResultDesc_ReplaceUses((OOC_SSA__Result)i1, (OOC_SSA__Result)i4);
  OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i3, (OOC_SSA__Result)i1, 2);
  res = (OOC_SSA__Result)i0;
  i1 = i0!=0;
  if (!i1) goto l34;
l3_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 45306))+16);
  i1 = i1!=0;
  if (i1) goto l6;
  i1=0u;
  goto l8;
l6:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 45325))+16);
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 45331)))), &_td_OOC_SSA_LoopRewrite__InductionCycleDesc);
  
l8:
  if (!i1) goto l29;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 45372))+16);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 45378)))), &_td_OOC_SSA_LoopRewrite__InductionCycleDesc, 45378)), 45393))+88);
  rc = (OOC_SSA_LoopRewrite__RewrittenCycle)i1;
  i4 = i1!=0;
  if (!i4) goto l29;
l12_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 45458))+16);
  i4 = _type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 45464)))), &_td_OOC_SSA_LoopRewrite__InductionCycleDesc, 45464);
  ce = (OOC_SSA_LoopRewrite__CycleElement)i4;
  i5 = i4!=0;
  if (!i5) goto l23;
l15_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 45544))+52);
  i5 = OOC_SSA_LoopRewrite__InstallEquivCE_UsedOutsideLoop((OOC_SSA__Result)i5);
  if (!i5) goto l18;
  i5 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i2, 85, 0);
  equiv = (OOC_SSA__Instr)i5;
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 45650))+16);
  i6 = _check_pointer(i6, 45663);
  i7 = *(OOC_INT32*)((_check_pointer(i4, 45666))+56);
  i8 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i7, i8, OOC_UINT32, 45663))*4);
  OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i5, (OOC_SSA__Result)i6, 1);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 45735))+52);
  i6 = (OOC_INT32)OOC_SSA_LoopRewrite__InitialValue((OOC_SSA__ProcBlock)i2, (OOC_SSA_LoopRewrite__RewrittenCycle)i1, (OOC_SSA__Result)i6, 3);
  OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i5, (OOC_SSA__Result)i6, 1);
  OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i3, (OOC_SSA__Result)i5, 1);
l18:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 45873))+48);
  ce = (OOC_SSA_LoopRewrite__CycleElement)i4;
  i5 = i4!=0;
  if (i5) goto l15_loop;
l23:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 45913));
  rc = (OOC_SSA_LoopRewrite__RewrittenCycle)i1;
  i4 = i1!=0;
  if (i4) goto l12_loop;
l29:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 45960));
  res = (OOC_SSA__Result)i0;
  i1 = i0!=0;
  if (i1) goto l3_loop;
l34:
  return;
  ;
}

void OOC_SSA_LoopRewrite__Transform(OOC_SSA__ProcBlock pb) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  ADT_ArrayList__ArrayList loops;
  OOC_INT32 i;
  OOC_SSA__Instr loopStart;
  OOC_SSA__Instr loopEnd;
  OOC_SSA__Opnd opnd;
  OOC_SSA__Instr instr;
  OOC_SSA__Result res;
  OOC_SSA_LoopRewrite__InductionCycle ic;
  OOC_SSA_LoopRewrite__CycleElement ce;
  auto void OOC_SSA_LoopRewrite__Transform_EnumerateLoops(OOC_SSA__Result storeOut, OOC_SSA__Instr firstInstr);
    
    void OOC_SSA_LoopRewrite__Transform_EnumerateLoops(OOC_SSA__Result storeOut, OOC_SSA__Instr firstInstr) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_SSA__Instr instr;
      OOC_SSA__Instr loopStart;
      OOC_SSA__Opnd opnd;

      i0 = (OOC_INT32)storeOut;
      i1 = *(OOC_INT32*)((_check_pointer(i0, 46699))+20);
      i1 = i1==0;
      if (!i1) goto l32;
      *(OOC_INT32*)((_check_pointer(i0, 46742))+20) = 1;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 46794))+8);
      i2 = (OOC_INT32)firstInstr;
      i1 = i1!=i2;
      if (!i1) goto l32;
l5_loop:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 46845))+8);
      instr = (OOC_SSA__Instr)i0;
      i1 = *(OOC_INT8*)((_check_pointer(i0, 46873))+36);
      switch (i1) {
      case 11:
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 46942))+24);
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 46951));
        i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 46960)))), &_td_OOC_SSA__InstrDesc, 46960);
        loopStart = (OOC_SSA__Instr)i1;
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 47000))+24);
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 47009))+8);
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 47018));
        OOC_SSA_LoopRewrite__Transform_EnumerateLoops((OOC_SSA__Result)i0, (OOC_SSA__Instr)i1);
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 47069))+24);
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 47078));
        storeOut = (OOC_SSA__Result)i0;
        i3 = (OOC_INT32)loops;
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 47101)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i3, (Object__Object)i1);
        
        goto l26;
      case 5:
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 47186))+24);
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 47195))+8);
        opnd = (OOC_SSA__Opnd)i0;
        i1 = i0!=0;
        if (i1) goto l11;
        i1=0u;
        goto l13;
l11:
        i1 = *(OOC_INT8*)((_check_pointer(i0, 47244))+4);
        i1 = i1==1;
        
l13:
        if (!i1) goto l24;
l15_loop:
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 47292))+8);
        opnd = (OOC_SSA__Opnd)i0;
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 47336));
        OOC_SSA_LoopRewrite__Transform_EnumerateLoops((OOC_SSA__Result)i1, (OOC_SSA__Instr)i2);
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 47381))+8);
        opnd = (OOC_SSA__Opnd)i0;
        i1 = i0!=0;
        if (i1) goto l18;
        i1=0u;
        goto l20;
l18:
        i1 = *(OOC_INT8*)((_check_pointer(i0, 47244))+4);
        i1 = i1==1;
        
l20:
        if (i1) goto l15_loop;
l24:
        storeOut = (OOC_SSA__Result)i2;
        i0=i2;
        goto l26;
      default:
        i0 = (OOC_INT32)OOC_SSA__InstrDesc_GetArgStore((OOC_SSA__Instr)i0);
        storeOut = (OOC_SSA__Result)i0;
        _assert((i0!=0), 127, 47552);
        
        goto l26;
      }
l26:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 46794))+8);
      i1 = i1!=i2;
      if (i1) goto l5_loop;
l32:
      return;
      ;
    }


  i0 = (OOC_INT32)pb;
  OOC_SSA__ProcBlockDesc_SetMarkers((OOC_SSA__ProcBlock)i0, (OOC_SSA__Node)(OOC_INT32)0, 0);
  i1 = (OOC_INT32)ADT_ArrayList__New(4);
  loops = (ADT_ArrayList__ArrayList)i1;
  i1 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetEnter((OOC_SSA__ProcBlock)i0);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 48243));
  i0 = (OOC_INT32)OOC_SSA__InstrDesc_GetArgStore((OOC_SSA__Instr)i0);
  OOC_SSA_LoopRewrite__Transform_EnumerateLoops((OOC_SSA__Result)i0, (OOC_SSA__Instr)i1);
  OOC_SSA_LoopRewrite__idCount = 0;
  i = 0;
  i0 = (OOC_INT32)loops;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 48339))+4);
  i1 = 0!=i1;
  if (!i1) goto l77;
  i1 = (OOC_INT32)pb;
  i2=0;
l3_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 48373));
  i3 = _check_pointer(i3, 48379);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 48379))*4);
  i3 = _type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 48387)))), &_td_OOC_SSA__InstrDesc, 48387);
  loopStart = (OOC_SSA__Instr)i3;
  OOC_SSA_LoopRewrite__Classify((OOC_SSA__ProcBlock)i1, (OOC_SSA__Instr)i3);
  OOC_SSA_LoopRewrite__FindInductiveCycles((OOC_SSA__Instr)i3);
  i4 = (OOC_INT32)OOC_SSA__InstrDesc_GetLoopEnd((OOC_SSA__Instr)i3);
  loopEnd = (OOC_SSA__Instr)i4;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 49351))+24);
  opnd = (OOC_SSA__Opnd)i4;
  i5 = i4!=(OOC_INT32)0;
  if (!i5) goto l11;
l6_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 49410));
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 49414))+8);
  OOC_SSA_LoopRewrite__Flatten((OOC_SSA__Result)i5);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 49443))+8);
  opnd = (OOC_SSA__Opnd)i4;
  i5 = i4!=(OOC_INT32)0;
  if (i5) goto l6_loop;
l11:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 49726))+12);
  instr = (OOC_SSA__Instr)i4;
  i5 = i4!=(OOC_INT32)0;
  if (!i5) goto l30;
l14_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 49938))+16);
  i5 = i5!=(OOC_INT32)0;
  if (i5) goto l17;
  i5=0u;
  goto l19;
l17:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 49970))+16);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i5, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 49976)))), &_td_OOC_SSA_LoopRewrite__SumDesc, 49976)), 49980))+16);
  i5 = i5!=(OOC_INT32)0;
  
l19:
  if (i5) goto l21;
  i5=0u;
  goto l23;
l21:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 50010))+16);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i5, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 50016)))), &_td_OOC_SSA_LoopRewrite__SumDesc, 50016)), 50020))+24);
  i5 = i5!=(OOC_INT32)0;
  
l23:
  if (!i5) goto l25;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 50075))+16);
  OOC_SSA_LoopRewrite__Rewrite((OOC_SSA__ProcBlock)i1, (OOC_SSA_LoopRewrite__Sum)(_type_guard(i5, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 50081)))), &_td_OOC_SSA_LoopRewrite__SumDesc, 50081)));
l25:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 50123))+28);
  instr = (OOC_SSA__Instr)i4;
  i5 = i4!=(OOC_INT32)0;
  if (i5) goto l14_loop;
l30:
  OOC_SSA_LoopRewrite__ClassifyCEUses((OOC_SSA__ProcBlock)i1, (OOC_SSA__Instr)i3);
  OOC_SSA_LoopRewrite__InstallEquivCE((OOC_SSA__ProcBlock)i1, (OOC_SSA__Instr)i3);
  res = (OOC_SSA__Result)i3;
  i4 = i3!=(OOC_INT32)0;
  if (!i4) goto l57;
l33_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 50807))+16);
  i4 = i4!=(OOC_INT32)0;
  if (i4) goto l36;
  i4=0u;
  goto l38;
l36:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 50837))+16);
  i4 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 50843)))), &_td_OOC_SSA_LoopRewrite__InductionCycleDesc);
  
l38:
  if (i4) goto l40;
  i4=0u;
  goto l42;
l40:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 50879))+16);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 50885)))), &_td_OOC_SSA_LoopRewrite__InductionCycleDesc, 50885)), 50900))+88);
  i4 = i4!=(OOC_INT32)0;
  
l42:
  if (!i4) goto l52;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 50948))+16);
  i4 = _type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 50954)))), &_td_OOC_SSA_LoopRewrite__InductionCycleDesc, 50954);
  ic = (OOC_SSA_LoopRewrite__InductionCycle)i4;
  ce = (OOC_SSA_LoopRewrite__CycleElement)i4;
  i5 = i4!=(OOC_INT32)0;
  if (!i5) goto l52;
  i5=i4;
l46_loop:
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 51051))+88);
  OOC_SSA_LoopRewrite__RewriteUses((OOC_SSA__ProcBlock)i1, (OOC_SSA_LoopRewrite__RewrittenCycle)i6, (OOC_SSA_LoopRewrite__CycleElement)i5);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 51094))+48);
  ce = (OOC_SSA_LoopRewrite__CycleElement)i5;
  i6 = i5!=(OOC_INT32)0;
  if (i6) goto l46_loop;
l52:
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 51147));
  res = (OOC_SSA__Result)i3;
  i4 = i3!=(OOC_INT32)0;
  if (i4) goto l33_loop;
l57:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 51320))+12);
  instr = (OOC_SSA__Instr)i3;
  i4 = i3!=(OOC_INT32)0;
  if (!i4) goto l72;
l60_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 51378))+16);
  i4 = i4!=(OOC_INT32)0;
  if (i4) goto l63;
  i4=0u;
  goto l65;
l63:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 51399))+16);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 51405)))), &_td_OOC_SSA_LoopRewrite__SumDesc, 51405)), 51409))+36);
  i4 = i4!=(OOC_INT32)0;
  
l65:
  if (!i4) goto l67;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 51467))+16);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 51473)))), &_td_OOC_SSA_LoopRewrite__SumDesc, 51473)), 51477))+36);
  OOC_SSA__ResultDesc_ReplaceUses((OOC_SSA__Result)i3, (OOC_SSA__Result)i4);
l67:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 51527))+28);
  instr = (OOC_SSA__Instr)i3;
  i4 = i3!=(OOC_INT32)0;
  if (i4) goto l60_loop;
l72:
  i2 = i2+1;
  i = i2;
  i3 = *(OOC_INT32*)((_check_pointer(i0, 48339))+4);
  i3 = i2!=i3;
  if (i3) goto l3_loop;
l77:
  return;
  ;
}

void OOC_OOC_SSA_LoopRewrite_init(void) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_SSA_LoopRewrite__PList.baseTypes[0]);
  OOC_SSA_LoopRewrite__one = (OOC_SSA_LoopRewrite__PList)i0;
  *(OOC_INT32*)((_check_pointer(i0, 51621))+4) = 1;
  *(OOC_INT32*)(_check_pointer(i0, 51642)) = ((OOC_INT32)RT0__NewObject(_td_OOC_SSA_LoopRewrite__2903.baseTypes[0], 1));
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 51662));
  i1 = _check_pointer(i1, 51667);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  *(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 51667))*4) = ((OOC_INT32)RT0__NewObject(_td_OOC_SSA_LoopRewrite__Product.baseTypes[0]));
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 51682));
  i1 = _check_pointer(i1, 51687);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 51687))*4);
  *(OOC_INT32*)((_check_pointer(i1, 51690))+4) = ((OOC_INT32)RT0__NewObject(_td_OOC_SSA_LoopRewrite__Factors.baseTypes[0], 0));
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 51709));
  i0 = _check_pointer(i0, 51714);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 51714))*4);
  *(OOC_INT32*)(_check_pointer(i0, 51717)) = 1;
  return;
  ;
}

void OOC_OOC_SSA_LoopRewrite_destroy(void) {
}

/* --- */
