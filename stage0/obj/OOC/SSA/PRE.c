#include <OOC/SSA/PRE.d>
#include <__oo2c.h>
#include <setjmp.h>

static OOC_SSA__Instr OOC_SSA_PRE__GetSelect(OOC_SSA__Instr collect) {
  register OOC_INT32 i0,i1,i2;
  OOC_SSA__Instr instr;

  i0 = (OOC_INT32)collect;
  i1 = (OOC_INT32)OOC_SSA__InstrDesc_GetCollectTarget((OOC_SSA__Instr)i0);
  instr = (OOC_SSA__Instr)i1;
  i2 = *(OOC_INT8*)((_check_pointer(i1, 1551))+36);
  switch (i2) {
  case 5:
    return (OOC_SSA__Instr)i1;
    goto l9;
  case 10:
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 1642))+24);
    i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 1651));
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 1655))+8);
    i0 = i2==i0;
    if (i0) goto l6;
    return (OOC_SSA__Instr)i1;
    goto l9;
l6:
    return (OOC_SSA__Instr)0;
    goto l9;
  default:
    return (OOC_SSA__Instr)0;
    goto l9;
  }
l9:
  _failed_function(1418); return 0;
  ;
}

static OOC_SSA__Instr OOC_SSA_PRE__GetNoop(OOC_SSA__ProcBlock pb, OOC_SSA__Result storeOut) {
  register OOC_INT32 i0,i1,i2;
  OOC_SSA__Opnd use;

  i0 = (OOC_INT32)storeOut;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 1961))+4);
  _assert((i1==2), 127, 1946);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2004))+12);
  use = (OOC_SSA__Opnd)i1;
  i2 = i1!=(OOC_INT32)0;
  if (!i2) goto l11;
l3_loop:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 2052))+12);
  i2 = *(OOC_INT8*)((_check_pointer(i2, 2058))+36);
  i2 = i2==88;
  if (!i2) goto l6;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 2104))+12);
  return (OOC_SSA__Instr)i2;
l6:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 2139))+16);
  use = (OOC_SSA__Opnd)i1;
  i2 = i1!=(OOC_INT32)0;
  if (i2) goto l3_loop;
l11:
  i1 = (OOC_INT32)pb;
  i1 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i1, 88, 0);
  i2 = (OOC_INT32)OOC_SSA__InstrDesc_AddResult((OOC_SSA__Instr)i1, 2);
  OOC_SSA__ResultDesc_ReplaceUses((OOC_SSA__Result)i0, (OOC_SSA__Result)i2);
  OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i0, 2);
  return (OOC_SSA__Instr)i1;
  ;
}

void OOC_SSA_PRE__Transform(OOC_SSA__ProcBlock pb) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_SSA_Blocker__DependenceData dd;
  ADT_ArrayList__ArrayList worklist;
  ADT_ArrayList__ArrayList equivList;
  OOC_SSA__Instr instr;
  OOC_SSA__Instr select;
  OOC_SSA__Opnd opnd;
  ADT_Dictionary__Dictionary equivToCollect;
  OOC_SSA__Instr enter;
  OOC_INT32 i;
  OOC_SSA__Instr h;
  auto void OOC_SSA_PRE__Transform_MigrateCandidates(OOC_SSA__Opnd collectOpnd, OOC_SSA__Instr undefValue);
  auto void OOC_SSA_PRE__Transform_ResolveEquiv(OOC_SSA__Instr equiv);
  auto OOC_CHAR8 OOC_SSA_PRE__Transform_OnlyUsedInEquiv(OOC_SSA__Result res);
    
    void OOC_SSA_PRE__Transform_MigrateCandidates(OOC_SSA__Opnd collectOpnd, OOC_SSA__Instr undefValue) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
      OOC_SSA__Instr collect;
      OOC_SSA__Instr select;
      OOC_SSA__Instr anchor;
      OOC_SSA__Instr domReference;
      OOC_SSA__Opnd use;
      OOC_SSA__Instr instr;
      OOC_SSA__Instr _new;
      OOC_SSA__Opnd opnd;
      OOC_SSA__Result res;
      OOC_SSA__Instr sameInstr;
      OOC_SSA__Result selectResult;
      OOC_INT32 i;
      OOC_SSA__Instr c;
      OOC_SSA__Instr equiv;
      auto OOC_CHAR8 OOC_SSA_PRE__Transform_MigrateCandidates_Dominates(OOC_SSA__Result res, OOC_SSA__Instr instr);
      auto OOC_SSA__Result OOC_SSA_PRE__Transform_MigrateCandidates_GetSelectResult(OOC_SSA__Instr select, OOC_SSA__Instr collect, OOC_SSA__Result arg);
        
        OOC_CHAR8 OOC_SSA_PRE__Transform_MigrateCandidates_Dominates(OOC_SSA__Result res, OOC_SSA__Instr instr) {
          register OOC_INT32 i0,i1,i2;

          i0 = (OOC_INT32)res;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3026))+8);
          i1 = (OOC_INT32)dd;
          i2 = (OOC_INT32)instr;
          i0 = OOC_SSA_Blocker__DependenceDataDesc_Dominates((OOC_SSA_Blocker__DependenceData)i1, (OOC_SSA__Instr)i0, (OOC_SSA__Instr)i2);
          return i0;
          ;
        }

        
        OOC_SSA__Result OOC_SSA_PRE__Transform_MigrateCandidates_GetSelectResult(OOC_SSA__Instr select, OOC_SSA__Instr collect, OOC_SSA__Result arg) {
          register OOC_INT32 i0,i1,i2,i3,i4;
          OOC_SSA__Opnd opnd;
          OOC_SSA__Result res;
          OOC_SSA__Opnd use;

          i0 = (OOC_INT32)collect;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3285))+24);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3294))+8);
          opnd = (OOC_SSA__Opnd)i1;
          i2 = i1!=(OOC_INT32)0;
          if (i2) goto l3;
          i2=0u;
          goto l5;
l3:
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 3339));
          i3 = (OOC_INT32)arg;
          i2 = i2!=i3;
          
l5:
          if (!i2) goto l17;
          i2 = (OOC_INT32)arg;
          
l8_loop:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3376))+8);
          opnd = (OOC_SSA__Opnd)i1;
          i3 = i1!=(OOC_INT32)0;
          if (i3) goto l11;
          i3=0u;
          goto l13;
l11:
          i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 3339));
          i3 = i3!=i2;
          
l13:
          if (i3) goto l8_loop;
l17:
          i2 = i1==(OOC_INT32)0;
          if (i2) goto l39;
          i1 = OOC_SSA__OpndDesc_OpndIndex((OOC_SSA__Opnd)i1);
          i2 = (OOC_INT32)select;
          i1 = (OOC_INT32)OOC_SSA__InstrDesc_NthResult((OOC_SSA__Instr)i2, (i1+1));
          res = (OOC_SSA__Result)i1;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3539))+12);
          use = (OOC_SSA__Opnd)i2;
          i3 = i2!=(OOC_INT32)0;
          if (!i3) goto l38;
l22_loop:
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 3599))+12);
          i3 = *(OOC_INT8*)((_check_pointer(i3, 3605))+36);
          i3 = i3==86;
          if (i3) goto l25;
          i3=0u;
          goto l27;
l25:
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 3653))+12);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 3659))+24);
          i3 = i3==i2;
          
l27:
          if (i3) goto l29;
          i3=0u;
          goto l31;
l29:
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 3716))+12);
          i4 = (OOC_INT32)equivToCollect;
          i3 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i4, (Object__Object)i3);
          i3 = i3==i0;
          
l31:
          if (!i3) goto l33;
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 3977))+12);
          i3 = (OOC_INT32)OOC_SSA__InstrDesc_NthArg((OOC_SSA__Instr)i3, 1);
          return (OOC_SSA__Result)i3;
l33:
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 4034))+16);
          use = (OOC_SSA__Opnd)i2;
          i3 = i2!=(OOC_INT32)0;
          if (i3) goto l22_loop;
l38:
          return (OOC_SSA__Result)i1;
          goto l40;
l39:
          return (OOC_SSA__Result)(OOC_INT32)0;
l40:
          _failed_function(3082); return 0;
          ;
        }


      i0 = (OOC_INT32)collectOpnd;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4164))+12);
      collect = (OOC_SSA__Instr)i1;
      i1 = (OOC_INT32)OOC_SSA_PRE__GetSelect((OOC_SSA__Instr)i1);
      select = (OOC_SSA__Instr)i1;
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 4242));
      i3 = (OOC_INT32)pb;
      i2 = (OOC_INT32)OOC_SSA_PRE__GetNoop((OOC_SSA__ProcBlock)i3, (OOC_SSA__Result)i2);
      anchor = (OOC_SSA__Instr)i2;
      i2 = *(OOC_INT8*)((_check_pointer(i1, 4272))+36);
      i2 = i2==10;
      if (i2) goto l3;
      domReference = (OOC_SSA__Instr)i1;
      goto l4;
l3:
      i2 = (OOC_INT32)OOC_SSA__InstrDesc_GetLoopEnd((OOC_SSA__Instr)i1);
      domReference = (OOC_SSA__Instr)i2;
      i3 = (OOC_INT32)dd;
      i1 = OOC_SSA_Blocker__DependenceDataDesc_Dominates((OOC_SSA_Blocker__DependenceData)i3, (OOC_SSA__Instr)i1, (OOC_SSA__Instr)i2);
      _assert((!i1), 127, 4358);
l4:
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4488));
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4492))+12);
      use = (OOC_SSA__Opnd)i0;
      i1 = i0!=0;
      if (!i1) goto l70;
l7_loop:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4566))+12);
      i2 = (OOC_INT32)dd;
      i3 = (OOC_INT32)collect;
      i1 = OOC_SSA_Blocker__DependenceDataDesc_SameRegion((OOC_SSA_Blocker__DependenceData)i2, (OOC_SSA__Instr)i3, (OOC_SSA__Instr)i1);
      if (i1) goto l10;
      i1=0u;
      goto l12;
l10:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4591))+12);
      i1 = *(OOC_INT8*)((_check_pointer(i1, 4597))+36);
      i1 = i1!=85;
      
l12:
      if (i1) goto l14;
      i1=0u;
      goto l16;
l14:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4638))+12);
      i1 = *(OOC_INT8*)((_check_pointer(i1, 4644))+36);
      i1 = i1!=86;
      
l16:
      if (i1) goto l18;
      i1=0u;
      goto l20;
l18:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4688))+12);
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 4694));
      i1 = i1==0;
      
l20:
      if (i1) goto l22;
      i1=0u;
      goto l24;
l22:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4789))+12);
      i1 = OOC_SSA_Blocker__DependenceDataDesc_Dominates((OOC_SSA_Blocker__DependenceData)i2, (OOC_SSA__Instr)i3, (OOC_SSA__Instr)i1);
      
l24:
      if (!i1) goto l65;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4854))+12);
      instr = (OOC_SSA__Instr)i0;
      i1 = *(OOC_INT8*)((_check_pointer(i0, 4897))+36);
      i2 = *(OOC_INT8*)((_check_pointer(i0, 4911))+5);
      i3 = (OOC_INT32)pb;
      i1 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i3, i1, i2);
      _new = (OOC_SSA__Instr)i1;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4946))+24);
      opnd = (OOC_SSA__Opnd)i0;
      i1 = i0!=0;
      if (!i1) goto l45;
l28_loop:
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5045));
      i1 = (OOC_INT32)select;
      i2 = (OOC_INT32)collect;
      i0 = (OOC_INT32)OOC_SSA_PRE__Transform_MigrateCandidates_GetSelectResult((OOC_SSA__Instr)i1, (OOC_SSA__Instr)i2, (OOC_SSA__Result)i0);
      res = (OOC_SSA__Result)i0;
      i1 = i0!=0;
      if (i1) goto l39;
      i0 = (OOC_INT32)opnd;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5188));
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 5192))+16);
      i1 = i1==0;
      if (i1) goto l33;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5276));
      i1 = (OOC_INT32)domReference;
      i0 = OOC_SSA_PRE__Transform_MigrateCandidates_Dominates((OOC_SSA__Result)i0, (OOC_SSA__Instr)i1);
      i0 = !i0;
      
      goto l35;
l33:
      i0=1u;
l35:
      if (i0) goto l37;
      i0 = (OOC_INT32)opnd;
      i1 = *(OOC_INT8*)((_check_pointer(i0, 5518))+4);
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5508));
      i3 = (OOC_INT32)_new;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i3, (OOC_SSA__Result)i2, i1);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5553))+8);
      opnd = (OOC_SSA__Opnd)i0;
      
      goto l40;
l37:
      i0 = (OOC_INT32)_new;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5325))+12);
      _assert((i1==0), 127, 5315);
      i1 = (OOC_INT32)pb;
      OOC_SSA__ProcBlockDesc_DeleteInstr((OOC_SSA__ProcBlock)i1, (OOC_SSA__Instr)i0);
      _new = (OOC_SSA__Instr)0;
      opnd = (OOC_SSA__Opnd)0;
      i0=0;
      goto l40;
l39:
      i1 = (OOC_INT32)opnd;
      i2 = *(OOC_INT8*)((_check_pointer(i1, 5119))+4);
      i3 = (OOC_INT32)_new;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i3, (OOC_SSA__Result)i0, i2);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 5154))+8);
      opnd = (OOC_SSA__Opnd)i0;
      
l40:
      i1 = i0!=0;
      if (i1) goto l28_loop;
l45:
      i0 = (OOC_INT32)_new;
      i1 = i0!=0;
      if (!i1) goto l65;
      i1 = (OOC_INT32)select;
      i2 = (OOC_INT32)dd;
      i3 = (OOC_INT32)OOC_SSA_Blocker__DependenceDataDesc_GetSameInstr((OOC_SSA_Blocker__DependenceData)i2, (OOC_SSA__Instr)i1, (OOC_SSA__Instr)i0);
      sameInstr = (OOC_SSA__Instr)i3;
      i4 = i3!=0;
      if (i4) goto l50;
      OOC_SSA_Blocker__DependenceDataDesc_SetRegion((OOC_SSA_Blocker__DependenceData)i2, (OOC_SSA__Instr)i1, (OOC_SSA__Instr)i0);
      goto l51;
l50:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5924))+12);
      _assert((i2==0), 127, 5914);
      i2 = (OOC_INT32)pb;
      OOC_SSA__ProcBlockDesc_DeleteInstr((OOC_SSA__ProcBlock)i2, (OOC_SSA__Instr)i0);
      _new = (OOC_SSA__Instr)i3;
l51:
      i0 = (OOC_INT32)instr;
      i2 = *(OOC_INT8*)((_check_pointer(i0, 6227))+5);
      i2 = (OOC_INT32)OOC_SSA__InstrDesc_AddResultSubclass((OOC_SSA__Instr)i1, 14, i2);
      selectResult = (OOC_SSA__Result)i2;
      i3 = OOC_SSA__InstrDesc_NumberOfPaths((OOC_SSA__Instr)i1);
      i = 0;
      i4 = (OOC_INT32)collect;
      i5 = 0<i3;
      if (!i5) goto l63;
      i5 = (OOC_INT32)undefValue;
      i6=0;
l54_loop:
      i7 = (OOC_INT32)OOC_SSA__InstrDesc_GetCollect((OOC_SSA__Instr)i1, (OOC_SSA__ProcBlock)0, i6);
      c = (OOC_SSA__Instr)i7;
      i8 = i7==i4;
      if (i8) goto l57;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i7, (OOC_SSA__Result)i5, 1);
      goto l58;
l57:
      i7 = (OOC_INT32)worklist;
      i8 = (OOC_INT32)OOC_SSA__InstrDesc_AddOpndFct((OOC_SSA__Instr)i4, (OOC_SSA__Result)i0, 1);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 6399)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i7, (Object__Object)i8);
l58:
      i6 = i6+1;
      i = i6;
      i7 = i6<i3;
      if (i7) goto l54_loop;
l63:
      i0 = (OOC_INT32)pb;
      i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i0, 86, 0);
      equiv = (OOC_SSA__Instr)i0;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i2, 1);
      i1 = (OOC_INT32)_new;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i1, 1);
      i2 = (OOC_INT32)equivToCollect;
      ADT_Dictionary__DictionaryDesc_Set((ADT_Dictionary__Dictionary)i2, (Object__Object)i0, (Object__Object)i4);
      i2 = (OOC_INT32)dd;
      OOC_SSA_Blocker__DependenceDataDesc_SetRegion((OOC_SSA_Blocker__DependenceData)i2, (OOC_SSA__Instr)i1, (OOC_SSA__Instr)i0);
      i1 = (OOC_INT32)anchor;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i0, 1);
      i1 = (OOC_INT32)equivList;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6886)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i1, (Object__Object)i0);
l65:
      i0 = (OOC_INT32)use;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6948))+16);
      use = (OOC_SSA__Opnd)i0;
      i1 = i0!=0;
      if (i1) goto l7_loop;
l70:
      return;
      ;
    }

    
    void OOC_SSA_PRE__Transform_ResolveEquiv(OOC_SSA__Instr equiv) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11;
      Object__Object obj;
      OOC_SSA__Instr collect;
      OOC_SSA__Instr select;
      OOC_SSA__Result res;
      OOC_SSA__Instr old;
      OOC_INT32 resultIndex;
      OOC_INT32 i;
      OOC_SSA__Instr c;
      OOC_SSA__Instr _new;
      OOC_SSA__Opnd opnd;
      OOC_SSA__Opnd h;
      OOC_SSA__Instr sameInstr;

      i0 = (OOC_INT32)equiv;
      i1 = *(OOC_INT8*)((_check_pointer(i0, 7240))+36);
      _assert((i1==86), 127, 7228);
      i1 = (OOC_INT32)equivToCollect;
      i1 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i1, (Object__Object)i0);
      obj = (Object__Object)i1;
      i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7334)))), &_td_OOC_SSA__InstrDesc, 7334);
      collect = (OOC_SSA__Instr)i1;
      i2 = (OOC_INT32)OOC_SSA_PRE__GetSelect((OOC_SSA__Instr)i1);
      select = (OOC_SSA__Instr)i2;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7396))+24);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 7405))+8);
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 7414));
      res = (OOC_SSA__Result)i3;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 7436))+8);
      old = (OOC_SSA__Instr)i4;
      i5 = i4==i2;
      if (i5) goto l30;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7774))+24);
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 7783));
      i3 = OOC_SSA__ResultDesc_ResultIndex((OOC_SSA__Result)i3);
      resultIndex = i3;
      i5 = OOC_SSA__InstrDesc_NumberOfPaths((OOC_SSA__Instr)i2);
      i = 0;
      i6 = 0<i5;
      if (!i6) goto l29;
      i3 = i3-1;
      i6=0;
l5_loop:
      i7 = (OOC_INT32)OOC_SSA__InstrDesc_GetCollect((OOC_SSA__Instr)i2, (OOC_SSA__ProcBlock)0, i6);
      c = (OOC_SSA__Instr)i7;
      i8 = *(OOC_INT8*)((_check_pointer(i7, 7914))+36);
      _assert((i8==6), 127, 7906);
      i8 = i7!=i1;
      if (!i8) goto l24;
      i8 = *(OOC_INT8*)((_check_pointer(i4, 8018))+36);
      i9 = *(OOC_INT8*)((_check_pointer(i4, 8030))+5);
      i10 = (OOC_INT32)pb;
      i8 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i10, i8, i9);
      _new = (OOC_SSA__Instr)i8;
      i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 8065))+24);
      opnd = (OOC_SSA__Opnd)i9;
      i10 = i9!=0;
      if (!i10) goto l19;
l10_loop:
      i10 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i9, 8132));
      i10 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i10, 8136))+8);
      i10 = i10==i2;
      if (i10) goto l13;
      i10 = *(OOC_INT8*)((_check_pointer(i9, 8325))+4);
      i11 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i9, 8315));
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i8, (OOC_SSA__Result)i11, i10);
      goto l14;
l13:
      i10 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i9, 8193));
      i10 = OOC_SSA__ResultDesc_ResultIndex((OOC_SSA__Result)i10);
      i10 = (OOC_INT32)OOC_SSA__InstrDesc_NthOpnd((OOC_SSA__Instr)i7, (i10-1));
      h = (OOC_SSA__Opnd)i10;
      i11 = *(OOC_INT8*)((_check_pointer(i9, 8255))+4);
      i10 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i10, 8245));
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i8, (OOC_SSA__Result)i10, i11);
l14:
      i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i9, 8379))+8);
      opnd = (OOC_SSA__Opnd)i9;
      i10 = i9!=0;
      if (i10) goto l10_loop;
l19:
      i9 = (OOC_INT32)dd;
      i10 = (OOC_INT32)OOC_SSA_Blocker__DependenceDataDesc_GetSameInstr((OOC_SSA_Blocker__DependenceData)i9, (OOC_SSA__Instr)i7, (OOC_SSA__Instr)i8);
      sameInstr = (OOC_SSA__Instr)i10;
      i11 = i10!=0;
      if (i11) goto l22;
      OOC_SSA_Blocker__DependenceDataDesc_SetRegion((OOC_SSA_Blocker__DependenceData)i9, (OOC_SSA__Instr)i7, (OOC_SSA__Instr)i8);
      
      goto l23;
l22:
      i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i8, 8559))+12);
      _assert((i9==0), 127, 8549);
      i9 = (OOC_INT32)pb;
      OOC_SSA__ProcBlockDesc_DeleteInstr((OOC_SSA__ProcBlock)i9, (OOC_SSA__Instr)i8);
      _new = (OOC_SSA__Instr)i10;
      i8=i10;
l23:
      i7 = (OOC_INT32)OOC_SSA__InstrDesc_NthOpnd((OOC_SSA__Instr)i7, i3);
      opnd = (OOC_SSA__Opnd)i7;
      OOC_SSA__OpndDesc_ReplaceArg((OOC_SSA__Opnd)i7, (OOC_SSA__Result)i8);
l24:
      i6 = i6+1;
      i = i6;
      i7 = i6<i5;
      if (i7) goto l5_loop;
l29:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8872))+24);
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 8881));
      OOC_SSA__ResultDesc_ReplaceUses((OOC_SSA__Result)i4, (OOC_SSA__Result)i1);
      goto l31;
l30:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7703))+24);
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 7712));
      OOC_SSA__ResultDesc_ReplaceUses((OOC_SSA__Result)i1, (OOC_SSA__Result)i3);
l31:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8917))+12);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 8925))+16);
      _assert((i1==0), 127, 8905);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8953))+12);
      OOC_SSA__OpndDesc_DeleteOpnd((OOC_SSA__Opnd)i1);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8994))+12);
      _assert((i1==0), 127, 8982);
      i1 = (OOC_INT32)pb;
      OOC_SSA__ProcBlockDesc_DeleteInstr((OOC_SSA__ProcBlock)i1, (OOC_SSA__Instr)i0);
      return;
      ;
    }

    
    OOC_CHAR8 OOC_SSA_PRE__Transform_OnlyUsedInEquiv(OOC_SSA__Result res) {
      register OOC_INT32 i0,i1;
      OOC_SSA__Opnd use;

      i0 = (OOC_INT32)res;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9173))+12);
      use = (OOC_SSA__Opnd)i0;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l11;
l3_loop:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9225))+12);
      i1 = *(OOC_INT8*)((_check_pointer(i1, 9231))+36);
      i1 = i1!=86;
      if (!i1) goto l6;
      return 0u;
l6:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9318))+16);
      use = (OOC_SSA__Opnd)i0;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l3_loop;
l11:
      return 1u;
      ;
    }


  i0 = (OOC_INT32)pb;
  i1 = (OOC_INT32)OOC_SSA_Blocker__GetDependenceData((OOC_SSA__ProcBlock)i0);
  dd = (OOC_SSA_Blocker__DependenceData)i1;
  OOC_SSA_Blocker__RemoveAntiDeps((OOC_SSA__ProcBlock)i0);
  i1 = (OOC_INT32)ADT_ArrayList__New(32);
  worklist = (ADT_ArrayList__ArrayList)i1;
  i2 = (OOC_INT32)ADT_ArrayList__New(32);
  equivList = (ADT_ArrayList__ArrayList)i2;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9558))+12);
  instr = (OOC_SSA__Instr)i2;
  i3 = i2!=(OOC_INT32)0;
  if (!i3) goto l22;
l3_loop:
  i3 = *(OOC_INT8*)((_check_pointer(i2, 9612))+36);
  i3 = i3==6;
  if (!i3) goto l17;
  i3 = (OOC_INT32)OOC_SSA_PRE__GetSelect((OOC_SSA__Instr)i2);
  select = (OOC_SSA__Instr)i3;
  i3 = i3!=(OOC_INT32)0;
  if (!i3) goto l17;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 9733))+24);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 9742))+8);
  opnd = (OOC_SSA__Opnd)i3;
  i4 = i3!=(OOC_INT32)0;
  if (!i4) goto l17;
l10_loop:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9805)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i1, (Object__Object)i3);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 9844))+8);
  opnd = (OOC_SSA__Opnd)i3;
  i4 = i3!=(OOC_INT32)0;
  if (i4) goto l10_loop;
l17:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 9914))+28);
  instr = (OOC_SSA__Instr)i2;
  i3 = i2!=(OOC_INT32)0;
  if (i3) goto l3_loop;
l22:
  i2 = (OOC_INT32)ADT_Dictionary__New();
  equivToCollect = (ADT_Dictionary__Dictionary)i2;
  i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetEnter((OOC_SSA__ProcBlock)i0);
  enter = (OOC_SSA__Instr)i0;
  i0 = *(OOC_INT32*)((_check_pointer(i1, 10023))+4);
  i0 = i0!=0;
  if (!i0) goto l30;
  i0=i1;
l25_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 10059));
  i1 = _check_pointer(i1, 10065);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 10074))+4);
  i3 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index((i2-1), i3, OOC_UINT32, 10065))*4);
  i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 10087)))), &_td_OOC_SSA__OpndDesc, 10087);
  opnd = (OOC_SSA__Opnd)i1;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 10124))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10108)))), ADT_ArrayList__ArrayListDesc_Remove)),ADT_ArrayList__ArrayListDesc_Remove)((ADT_ArrayList__ArrayList)i0, (i2-1));
  i0 = (OOC_INT32)enter;
  OOC_SSA_PRE__Transform_MigrateCandidates((OOC_SSA__Opnd)i1, (OOC_SSA__Instr)i0);
  i0 = (OOC_INT32)worklist;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 10023))+4);
  i1 = i1!=0;
  if (i1) goto l25_loop;
l30:
  i0 = (OOC_INT32)pb;
  OOC_SSA_CSE__Transform((OOC_SSA__ProcBlock)i0);
  i1 = (OOC_INT32)equivList;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 10363))+4);
  i2 = i2-1;
  i = i2;
  i3 = i2>=0;
  if (!i3) goto l44;
l33_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 10409));
  i3 = _check_pointer(i3, 10415);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 10415))*4);
  i3 = _type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 10423)))), &_td_OOC_SSA__InstrDesc, 10423);
  instr = (OOC_SSA__Instr)i3;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 10447))+24);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 10456))+8);
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 10465));
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 10469))+8);
  h = (OOC_SSA__Instr)i4;
  i5 = OOC_SSA_PRE__Transform_OnlyUsedInEquiv((OOC_SSA__Result)i4);
  if (!i5) goto l39;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 10608))+12);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 10616))+16);
  _assert((i5==(OOC_INT32)0), 127, 10596);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 10646))+12);
  OOC_SSA__OpndDesc_DeleteOpnd((OOC_SSA__Opnd)i5);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 10689))+12);
  _assert((i5==(OOC_INT32)0), 127, 10677);
  OOC_SSA__ProcBlockDesc_DeleteInstr((OOC_SSA__ProcBlock)i0, (OOC_SSA__Instr)i3);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 10751))+12);
  i3 = i3==(OOC_INT32)0;
  if (!i3) goto l38;
  OOC_SSA__ProcBlockDesc_DeleteInstr((OOC_SSA__ProcBlock)i0, (OOC_SSA__Instr)i4);
l38:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 10996)))), ADT_ArrayList__ArrayListDesc_Set)),ADT_ArrayList__ArrayListDesc_Set)((ADT_ArrayList__ArrayList)i1, i2, (Object__Object)(OOC_INT32)0);
l39:
  i2 = i2+(-1);
  i = i2;
  i3 = i2>=0;
  if (i3) goto l33_loop;
l44:
  i0 = *(OOC_INT32*)((_check_pointer(i1, 11107))+4);
  i = 0;
  i1 = 0<i0;
  if (!i1) goto l55;
  i1=0;
l47_loop:
  i2 = (OOC_INT32)equivList;
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 11137));
  i3 = _check_pointer(i3, 11143);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i1, i4, OOC_UINT32, 11143))*4);
  i3 = i3!=(OOC_INT32)0;
  if (!i3) goto l50;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 11230));
  i2 = _check_pointer(i2, 11236);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i1, i3, OOC_UINT32, 11236))*4);
  OOC_SSA_PRE__Transform_ResolveEquiv((OOC_SSA__Instr)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 11244)))), &_td_OOC_SSA__InstrDesc, 11244)));
l50:
  i1 = i;
  i1 = i1+1;
  i = i1;
  i2 = i1<i0;
  if (i2) goto l47_loop;
l55:
  return;
  ;
}

void OOC_SSA_PRE__ResolveEquiv(OOC_SSA__ProcBlock pb) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_SSA__Instr instr;
  OOC_SSA__Instr next;

  i0 = (OOC_INT32)pb;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11533))+12);
  instr = (OOC_SSA__Instr)i1;
  i2 = i1!=(OOC_INT32)0;
  if (!i2) goto l18;
l3_loop:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11591))+28);
  next = (OOC_SSA__Instr)i2;
  i3 = *(OOC_INT8*)((_check_pointer(i1, 11618))+36);
  i3 = i3==85;
  if (i3) goto l9;
  i3 = *(OOC_INT8*)((_check_pointer(i1, 11902))+36);
  i3 = i3==88;
  if (!i3) goto l13;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11972))+24);
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 11981));
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 11943));
  OOC_SSA__ResultDesc_ReplaceUses((OOC_SSA__Result)i4, (OOC_SSA__Result)i3);
  OOC_SSA__ProcBlockDesc_DeleteInstr((OOC_SSA__ProcBlock)i0, (OOC_SSA__Instr)i1);
  goto l13;
l9:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11660))+24);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 11669))+8);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11700))+24);
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 11709));
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 11678));
  OOC_SSA__ResultDesc_ReplaceUses((OOC_SSA__Result)i3, (OOC_SSA__Result)i4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11733))+12);
  i3 = i3!=(OOC_INT32)0;
  if (!i3) goto l12;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11776))+12);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 11784))+16);
  _assert((i3==(OOC_INT32)0), 127, 11764);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11816))+12);
  OOC_SSA__OpndDesc_DeleteOpnd((OOC_SSA__Opnd)i3);
l12:
  OOC_SSA__ProcBlockDesc_DeleteInstr((OOC_SSA__ProcBlock)i0, (OOC_SSA__Instr)i1);
l13:
  instr = (OOC_SSA__Instr)i2;
  i1 = i2!=(OOC_INT32)0;
  if (!i1) goto l18;
  i1=i2;
  goto l3_loop;
l18:
  return;
  ;
}

void OOC_OOC_SSA_PRE_init(void) {

  return;
  ;
}

/* --- */
