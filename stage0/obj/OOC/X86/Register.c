#include <OOC/X86/Register.d>
#include <__oo2c.h>
#include <setjmp.h>

void OOC_X86_Register__RegisterFileDesc_INIT(OOC_X86_Register__RegisterFile rf, OOC_INT8 registerType) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)rf;
  OOC_X86_SSA__NodeDesc_INIT((OOC_X86_SSA__Node)i0);
  i1 = registerType;
  *(OOC_INT8*)(_check_pointer(i0, 1031)) = i1;
  i1 = (OOC_INT32)RT0__NewObject(_td__qtd1.baseTypes[0]);
  ADT_ArrayList__ArrayListDesc_INIT((ADT_ArrayList__ArrayList)i1, 16);
  *(OOC_INT32*)((_check_pointer(i0, 1068))+4) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 1129))+8) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 1151))+12) = (-1);
  i1 = (OOC_INT32)RT0__NewObject(_td__qtd3.baseTypes[0]);
  ADT_Dictionary__DictionaryDesc_INIT((ADT_Dictionary__Dictionary)i1);
  *(OOC_INT32*)((_check_pointer(i0, 1174))+88) = i1;
  return;
  ;
}

void OOC_X86_Register__LiveDataDesc_INIT(OOC_X86_Register__LiveData ld, OOC_X86_SSA__Block block, OOC_X86_SSA__Instr position, OOC_INT32 remainingInput, OOC_SSA_IGraph__Vector live) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)ld;
  i1 = (OOC_INT32)block;
  *(OOC_INT32*)(_check_pointer(i0, 1390)) = i1;
  i1 = (OOC_INT32)position;
  *(OOC_INT32*)((_check_pointer(i0, 1413))+4) = i1;
  i1 = remainingInput;
  *(OOC_INT32*)((_check_pointer(i0, 1442))+8) = i1;
  i1 = (OOC_INT32)live;
  *(OOC_INT32*)((_check_pointer(i0, 1483))+12) = i1;
  return;
  ;
}

static void OOC_X86_Register__LogLiveData(OOC_X86_Register__RegisterFile rf, OOC_X86_Register__LiveData ld) {

  return;
  ;
}

static OOC_X86_Register__RegisterFiles OOC_X86_Register__GetRegisterFiles(void) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_X86_Register__RegisterFiles rfs;
  OOC_INT32 i;
  OOC_X86_Register__RegisterFile rf;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_Register__RegisterFiles.baseTypes[0], 12);
  rfs = (OOC_X86_Register__RegisterFiles)i0;
  i = 0;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 2150)), 0);
  i2 = 0<i1;
  if (!i2) goto l8;
  i2=0;
l3_loop:
  i3 = _check_pointer(i0, 2167);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 2167))*4) = (OOC_INT32)0;
  i2 = i2+1;
  i = i2;
  i3 = i2<i1;
  if (i3) goto l3_loop;
l8:
  i1 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_Register__RegisterFile.baseTypes[0]);
  OOC_X86_Register__RegisterFileDesc_INIT((OOC_X86_Register__RegisterFile)i1, 0);
  rf = (OOC_X86_Register__RegisterFile)i1;
  i = 0;
  i2=0;
l9_loop:
  *(OOC_INT32*)(((_check_pointer(i1, 2275))+16)+(_check_index(i2, 18, OOC_UINT32, 2289))*4) = (OOC_INT32)0;
  i2 = i2+1;
  i = i2;
  i3 = i2<=17;
  if (i3) goto l9_loop;
l13:
  i2 = _check_pointer(i0, 2317);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  *(OOC_INT32*)(i2+(_check_index(1, i3, OOC_UINT8, 2317))*4) = i1;
  i2 = _check_pointer(i0, 2343);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  *(OOC_INT32*)(i2+(_check_index(2, i3, OOC_UINT8, 2343))*4) = i1;
  i2 = _check_pointer(i0, 2370);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  *(OOC_INT32*)(i2+(_check_index(3, i3, OOC_UINT8, 2370))*4) = i1;
  i2 = _check_pointer(i0, 2397);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  *(OOC_INT32*)(i2+(_check_index(5, i3, OOC_UINT8, 2397))*4) = i1;
  i2 = _check_pointer(i0, 2425);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  *(OOC_INT32*)(i2+(_check_index(6, i3, OOC_UINT8, 2425))*4) = i1;
  i2 = _check_pointer(i0, 2454);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  *(OOC_INT32*)(i2+(_check_index(7, i3, OOC_UINT8, 2454))*4) = i1;
  i2 = _check_pointer(i0, 2483);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  *(OOC_INT32*)(i2+(_check_index(9, i3, OOC_UINT8, 2483))*4) = i1;
  i1 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_Register__RegisterFile.baseTypes[0]);
  OOC_X86_Register__RegisterFileDesc_INIT((OOC_X86_Register__RegisterFile)i1, 1);
  rf = (OOC_X86_Register__RegisterFile)i1;
  i = 0;
  i2=0;
l14_loop:
  *(OOC_INT32*)(((_check_pointer(i1, 2589))+16)+(_check_index(i2, 18, OOC_UINT32, 2603))*4) = (OOC_INT32)0;
  i2 = i2+1;
  i = i2;
  i3 = i2<=17;
  if (i3) goto l14_loop;
l18:
  i2 = _check_pointer(i0, 2631);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  *(OOC_INT32*)(i2+(_check_index(10, i3, OOC_UINT8, 2631))*4) = i1;
  i2 = _check_pointer(i0, 2656);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  *(OOC_INT32*)(i2+(_check_index(11, i3, OOC_UINT8, 2656))*4) = i1;
  return (OOC_X86_Register__RegisterFiles)i0;
  ;
}

static OOC_X86_Register__RegisterFiles OOC_X86_Register__IdentifyResults(OOC_X86_SSA__FunctionBlock b) {
  register OOC_INT32 i0;
  OOC_X86_Register__RegisterFiles rfs;
  auto void OOC_X86_Register__IdentifyResults_ScanBlock(OOC_X86_SSA__Block b);
    
    void OOC_X86_Register__IdentifyResults_ScanBlock(OOC_X86_SSA__Block b) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5;
      OOC_X86_SSA__Instr instr;
      OOC_X86_SSA__Result res;
      OOC_X86_Register__RegisterFile rf;
      auto OOC_CHAR8 OOC_X86_Register__IdentifyResults_ScanBlock_Relevant(OOC_X86_SSA__Result res);
        
        OOC_CHAR8 OOC_X86_Register__IdentifyResults_ScanBlock_Relevant(OOC_X86_SSA__Result res) {
          register OOC_INT32 i0,i1;

          i0 = (OOC_INT32)res;
          i1 = *(OOC_INT8*)((_check_pointer(i0, 3907))+13);
          i1 = i1!=2;
          if (i1) goto l3;
          i1 = *(OOC_INT8*)((_check_pointer(i0, 3932))+14);
          i1 = i1!=0;
          
          goto l5;
l3:
          i1=1u;
l5:
          if (i1) goto l7;
          i0=0u;
          goto l8;
l7:
          i0 = *(OOC_INT8*)((_check_pointer(i0, 3974))+13);
          i0 = i0!=9;
          
l8:
          return i0;
          ;
        }


      i0 = (OOC_INT32)b;
      i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_Instructions((OOC_X86_SSA__Block)i0);
      i1 = (OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG(i0)), OOC_X86_SSA__IterBlockInstructionsDesc_Next);
      i2 = OOC_TBCALL(i1,OOC_X86_SSA__IterBlockInstructionsDesc_Next)((OOC_X86_SSA__IterBlockInstructions)i0, (void*)(OOC_INT32)&instr);
      if (!i2) goto l25;
l3_loop:
      i2 = (OOC_INT32)instr;
      i2 = OOC_X86_SSA__InstrDesc_IsLive((OOC_X86_SSA__Instr)i2);
      if (!i2) goto l17;
      i2 = (OOC_INT32)instr;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 4121))+4);
      res = (OOC_X86_SSA__Result)i2;
      i3 = i2!=(OOC_INT32)0;
      if (!i3) goto l17;
l8_loop:
      i3 = OOC_X86_Register__IdentifyResults_ScanBlock_Relevant((OOC_X86_SSA__Result)i2);
      if (!i3) goto l11;
      i3 = (OOC_INT32)rfs;
      i3 = _check_pointer(i3, 4222);
      i4 = *(OOC_INT8*)((_check_pointer(i2, 4226))+12);
      i5 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i4, i5, OOC_UINT8, 4222))*4);
      rf = (OOC_X86_Register__RegisterFile)i3;
      *(OOC_INT32*)((_check_pointer(i2, 4251))+20) = i3;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 4294))+4);
      i4 = *(OOC_INT32*)((_check_pointer(i4, 4305))+4);
      *(OOC_INT32*)((_check_pointer(i2, 4281))+24) = i4;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 4328))+4);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 4328))+4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 4339)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i3, (Object__Object)i2);
l11:
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 4392));
      res = (OOC_X86_SSA__Result)i2;
      i3 = i2!=(OOC_INT32)0;
      if (i3) goto l8_loop;
l17:
      i2 = (OOC_INT32)instr;
      i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 4452)))), &_td_OOC_X86_SSA__BlockDesc);
      if (!i3) goto l20;
      OOC_X86_Register__IdentifyResults_ScanBlock((OOC_X86_SSA__Block)i2);
l20:
      i2 = OOC_TBCALL(i1,OOC_X86_SSA__IterBlockInstructionsDesc_Next)((OOC_X86_SSA__IterBlockInstructions)i0, (void*)(OOC_INT32)&instr);
      if (i2) goto l3_loop;
l25:
      return;
      ;
    }


  i0 = (OOC_INT32)OOC_X86_Register__GetRegisterFiles();
  rfs = (OOC_X86_Register__RegisterFiles)i0;
  i0 = (OOC_INT32)b;
  OOC_X86_Register__IdentifyResults_ScanBlock((OOC_X86_SSA__Block)i0);
  i0 = (OOC_INT32)rfs;
  return (OOC_X86_Register__RegisterFiles)i0;
  ;
}

static OOC_X86_SSA__Instr OOC_X86_Register__SweepLiveSet(OOC_X86_Register__RegisterFile rf, OOC_X86_SSA__Block b, OOC_X86_SSA__Instr instr, OOC_SSA_IGraph__Vector live) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
  OOC_SSA_IGraph__Graph iGraph;
  OOC_X86_SSA__Result res;
  auto void OOC_X86_Register__SweepLiveSet_MarkOpndAsLive(OOC_SSA_IGraph__Vector live, OOC_X86_SSA__IterOperands iter);
    
    void OOC_X86_Register__SweepLiveSet_MarkOpndAsLive(OOC_SSA_IGraph__Vector live, OOC_X86_SSA__IterOperands iter) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5;
      OOC_X86_SSA__Opnd opnd;

      i0 = (OOC_INT32)iter;
      i1 = (OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG(i0)), OOC_X86_SSA__IterOperandsDesc_Next);
      i2 = OOC_TBCALL(i1,OOC_X86_SSA__IterOperandsDesc_Next)((OOC_X86_SSA__IterOperands)i0, (void*)(OOC_INT32)&opnd);
      if (!i2) goto l18;
      i2 = (OOC_INT32)live;
l3_loop:
      i3 = (OOC_INT32)opnd;
      i4 = *(OOC_UINT8*)((_check_pointer(i3, 5529))+16);
      if (i4) goto l12;
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 5623));
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 5627))+20);
      i5 = (OOC_INT32)rf;
      i4 = i4==i5;
      if (!i4) goto l13;
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 5672));
      i4 = *(OOC_INT32*)((_check_pointer(i4, 5676))+24);
      i5 = (OOC_INT32)iGraph;
      i4 = OOC_SSA_IGraph__GraphDesc_In((OOC_SSA_IGraph__Graph)i5, i4, (OOC_SSA_IGraph__Vector)i2);
      i4 = !i4;
      if (!i4) goto l13;
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 6003));
      i3 = *(OOC_INT32*)((_check_pointer(i3, 6007))+24);
      OOC_SSA_IGraph__GraphDesc_AddToLive((OOC_SSA_IGraph__Graph)i5, i3, (OOC_SSA_IGraph__Vector)i2);
      goto l13;
l12:
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 5580));
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 5584))+4);
      i3 = (OOC_INT32)OOC_X86_SSA__InstrDesc_Operands((OOC_X86_SSA__Instr)i3);
      OOC_X86_Register__SweepLiveSet_MarkOpndAsLive((OOC_SSA_IGraph__Vector)i2, (OOC_X86_SSA__IterOperands)i3);
l13:
      i3 = OOC_TBCALL(i1,OOC_X86_SSA__IterOperandsDesc_Next)((OOC_X86_SSA__IterOperands)i0, (void*)(OOC_INT32)&opnd);
      if (i3) goto l3_loop;
l18:
      return;
      ;
    }


  i0 = (OOC_INT32)rf;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6111))+8);
  iGraph = (OOC_SSA_IGraph__Graph)i0;
  i0 = (OOC_INT32)instr;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l55;
l3_loop:
  i1 = *(OOC_INT8*)((_check_pointer(i0, 6401))+20);
  switch (i1) {
  case 48:
  case 53:
    return (OOC_X86_SSA__Instr)i0;
    goto l50;
  case 54:
    i0 = (OOC_INT32)b;
    return (OOC_X86_SSA__Instr)i0;
    goto l50;
  case 52:
    i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_GateOperands((OOC_X86_SSA__Instr)i0);
    i1 = (OOC_INT32)live;
    OOC_X86_Register__SweepLiveSet_MarkOpndAsLive((OOC_SSA_IGraph__Vector)i1, (OOC_X86_SSA__IterOperands)i0);
    goto l50;
  default:
    i1 = *(OOC_INT8*)((_check_pointer(i0, 6635))+20);
    i1 = i1==46;
    if (i1) goto l11;
    i1=0u;
    goto l13;
l11:
    i1 = (OOC_INT32)rf;
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6660))+88);
    i1 = ADT_Dictionary__DictionaryDesc_HasKey((ADT_Dictionary__Dictionary)i1, (Object__Object)i0);
    i1 = !i1;
    
l13:
    if (!i1) goto l15;
    return (OOC_X86_SSA__Instr)i0;
l15:
    i1 = OOC_X86_SSA__InstrDesc_IsLive((OOC_X86_SSA__Instr)i0);
    if (!i1) goto l50;
    i1 = (OOC_INT32)OOC_X86_SSA__InstrDesc_Results((OOC_X86_SSA__Instr)i0);
    i2 = (OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG(i1)), OOC_X86_SSA__IterInstrResultsDesc_Next);
    i3 = OOC_TBCALL(i2,OOC_X86_SSA__IterInstrResultsDesc_Next)((OOC_X86_SSA__IterInstrResults)i1, (void*)(OOC_INT32)&res);
    if (!i3) goto l32;
    i3 = (OOC_INT32)live;
    i4 = (OOC_INT32)iGraph;
    i5 = (OOC_INT32)rf;
l20_loop:
    i6 = (OOC_INT32)res;
    i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 7283))+20);
    i7 = i7==i5;
    if (i7) goto l23;
    i7=0u;
    goto l25;
l23:
    i7 = OOC_X86_SSA__ResultDesc_NonImmediateUses((OOC_X86_SSA__Result)i6);
    i7 = !i7;
    
l25:
    if (!i7) goto l27;
    i6 = *(OOC_INT32*)((_check_pointer(i6, 7791))+24);
    OOC_SSA_IGraph__GraphDesc_AddToLive((OOC_SSA_IGraph__Graph)i4, i6, (OOC_SSA_IGraph__Vector)i3);
l27:
    i6 = OOC_TBCALL(i2,OOC_X86_SSA__IterInstrResultsDesc_Next)((OOC_X86_SSA__IterInstrResults)i1, (void*)(OOC_INT32)&res);
    if (i6) goto l20_loop;
l32:
    i1 = (OOC_INT32)OOC_X86_SSA__InstrDesc_Results((OOC_X86_SSA__Instr)i0);
    i2 = (OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG(i1)), OOC_X86_SSA__IterInstrResultsDesc_Next);
    i3 = OOC_TBCALL(i2,OOC_X86_SSA__IterInstrResultsDesc_Next)((OOC_X86_SSA__IterInstrResults)i1, (void*)(OOC_INT32)&res);
    if (!i3) goto l43;
    i3 = (OOC_INT32)live;
    i4 = (OOC_INT32)iGraph;
    i5 = (OOC_INT32)rf;
l35_loop:
    i6 = (OOC_INT32)res;
    i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 7992))+20);
    i7 = i7==i5;
    if (!i7) goto l38;
    i6 = *(OOC_INT32*)((_check_pointer(i6, 8048))+24);
    OOC_SSA_IGraph__GraphDesc_RemoveFromLive((OOC_SSA_IGraph__Graph)i4, i6, (OOC_SSA_IGraph__Vector)i3);
l38:
    i6 = OOC_TBCALL(i2,OOC_X86_SSA__IterInstrResultsDesc_Next)((OOC_X86_SSA__IterInstrResults)i1, (void*)(OOC_INT32)&res);
    if (i6) goto l35_loop;
l43:
    i1 = *(OOC_INT8*)((_check_pointer(i0, 8280))+20);
    switch (i1) {
    case 50:
      goto l50;
    case 55:
      i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_GateOperands((OOC_X86_SSA__Instr)i0);
      i1 = (OOC_INT32)live;
      OOC_X86_Register__SweepLiveSet_MarkOpndAsLive((OOC_SSA_IGraph__Vector)i1, (OOC_X86_SSA__IterOperands)i0);
      goto l50;
    default:
      i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_Operands((OOC_X86_SSA__Instr)i0);
      i1 = (OOC_INT32)live;
      OOC_X86_Register__SweepLiveSet_MarkOpndAsLive((OOC_SSA_IGraph__Vector)i1, (OOC_X86_SSA__IterOperands)i0);
      goto l50;
    }
    /* goto: unreachable */
  }
l50:
  i0 = (OOC_INT32)instr;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8554))+12);
  instr = (OOC_X86_SSA__Instr)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l3_loop;
l55:
  return (OOC_X86_SSA__Instr)(OOC_INT32)0;
  ;
}

static OOC_INT32 OOC_X86_Register__CoalesceFixedLocations(OOC_X86_Register__RegisterFile rf, OOC_X86_SSA__FunctionBlock b) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_INT32 addedCopies;
  OOC_INT32 i;
  OOC_X86_SSA__Result res;
  OOC_CHAR8 success;
  OOC_X86_SSA__Instr instr;
  OOC_X86_SSA__Opnd inOutOpnd;
  auto OOC_CHAR8 OOC_X86_Register__CoalesceFixedLocations_CoalesceWith(OOC_X86_SSA__Result coalesced, OOC_X86_SSA__Result base);
    
    OOC_CHAR8 OOC_X86_Register__CoalesceFixedLocations_CoalesceWith(OOC_X86_SSA__Result coalesced, OOC_X86_SSA__Result base) {
      register OOC_INT32 i0,i1,i2,i3,i4;
      OOC_SSA_IGraph__Graph iGraph;

      i0 = (OOC_INT32)rf;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8943))+8);
      iGraph = (OOC_SSA_IGraph__Graph)i0;
      i1 = (OOC_INT32)base;
      i2 = (OOC_INT32)coalesced;
      i3 = *(OOC_INT32*)((_check_pointer(i1, 9000))+24);
      i4 = *(OOC_INT32*)((_check_pointer(i2, 8987))+24);
      i3 = OOC_SSA_IGraph__GraphDesc_Conflicts((OOC_SSA_IGraph__Graph)i0, i4, i3);
      if (i3) goto l3;
      i3 = *(OOC_INT32*)((_check_pointer(i1, 9099))+24);
      i4 = *(OOC_INT32*)((_check_pointer(i2, 9086))+24);
      OOC_SSA_IGraph__GraphDesc_MergeRowColumn((OOC_SSA_IGraph__Graph)i0, i4, i3);
      i0 = *(OOC_INT32*)((_check_pointer(i1, 9142))+24);
      *(OOC_INT32*)((_check_pointer(i2, 9126))+24) = ((-i0)-1);
      return 1u;
      goto l4;
l3:
      return 0u;
l4:
      _failed_function(8829); return 0;
      ;
    }


  addedCopies = 0;
  i0 = (OOC_INT32)rf;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9260))+4);
  i0 = *(OOC_INT32*)((_check_pointer(i0, 9271))+4);
  i = 0;
  i1 = 0<i0;
  if (!i1) goto l28;
  i1=0;
l3_loop:
  i2 = (OOC_INT32)rf;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 9297))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 9308));
  i3 = _check_pointer(i3, 9314);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i1, i4, OOC_UINT32, 9314))*4);
  res = (OOC_X86_SSA__Result)i1;
  i3 = *(OOC_INT8*)((_check_pointer(i1, 9332))+14);
  i3 = i3!=(-1);
  if (!i3) goto l10;
  i3 = *(OOC_INT8*)((_check_pointer(i1, 9394))+13);
  i3 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i2, 9376))+16)+(_check_index(i3, 18, OOC_UINT8, 9390))*4);
  i3 = i3==0;
  if (i3) goto l8;
  i3 = *(OOC_INT8*)((_check_pointer(i1, 9669))+13);
  i2 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i2, 9651))+16)+(_check_index(i3, 18, OOC_UINT8, 9665))*4);
  i1 = OOC_X86_Register__CoalesceFixedLocations_CoalesceWith((OOC_X86_SSA__Result)i1, (OOC_X86_SSA__Result)i2);
  success = i1;
  _assert(i1, 127, 9692);
  goto l10;
l8:
  i3 = *(OOC_INT8*)((_check_pointer(i1, 9578))+13);
  *(OOC_INT32*)(((_check_pointer(i2, 9560))+16)+(_check_index(i3, 18, OOC_UINT8, 9574))*4) = i1;
l10:
  i1 = (OOC_INT32)res;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 9752))+4);
  instr = (OOC_X86_SSA__Instr)i2;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 9781))+4);
  i3 = i1==i3;
  if (!i3) goto l23;
  i2 = (OOC_INT32)OOC_X86_Machine__InOutOpnd((OOC_X86_SSA__Instr)i2);
  inOutOpnd = (OOC_X86_SSA__Opnd)i2;
  i3 = i2!=0;
  if (!i3) goto l23;
  i3 = *(OOC_INT8*)((_check_pointer(i1, 9991))+14);
  _assert((i3==(-1)), 127, 9981);
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 10040));
  i3 = *(OOC_INT32*)((_check_pointer(i3, 10044))+24);
  i3 = i3>=0;
  if (i3) goto l17;
  i3 = (OOC_INT32)rf;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 10178))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 10189));
  i3 = _check_pointer(i3, 10195);
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 10206));
  i2 = *(OOC_INT32*)((_check_pointer(i2, 10210))+24);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(((-i2)-1), i4, OOC_UINT32, 10195))*4);
  i1 = OOC_X86_Register__CoalesceFixedLocations_CoalesceWith((OOC_X86_SSA__Result)i1, (OOC_X86_SSA__Result)i2);
  success = i1;
  
  goto l18;
l17:
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 10108));
  i1 = OOC_X86_Register__CoalesceFixedLocations_CoalesceWith((OOC_X86_SSA__Result)i2, (OOC_X86_SSA__Result)i1);
  success = i1;
  
l18:
  i1 = !i1;
  if (!i1) goto l23;
  i1 = (OOC_INT32)inOutOpnd;
  OOC_X86_SSA__OpndDesc_InsertCopy((OOC_X86_SSA__Opnd)i1);
  i1 = addedCopies;
  addedCopies = (i1+1);
l23:
  i1 = i;
  i1 = i1+1;
  i = i1;
  i2 = i1<i0;
  if (i2) goto l3_loop;
l28:
  i0 = addedCopies;
  return i0;
  ;
}

static OOC_INT32 OOC_X86_Register__AssignRegisterFile(OOC_X86_Register__RegisterFile rf, OOC_X86_SSA__FunctionBlock b) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_X86_Register__LiveData ld;
  ADT_ArrayList__ArrayList ldReady;
  ADT_Dictionary__Dictionary ldWaiting;
  OOC_X86_SSA__Instr instr;
  OOC_X86_SSA__Block block;
  OOC_X86_SSA__Block branchBlock;
  OOC_X86_Register__LiveData ldBranch;
  OOC_X86_SSA__MergeInstr merge;
  OOC_INT32 addedCopies;
  OOC_SSA_IGraph__ColorArray coloring;
  auto void OOC_X86_Register__AssignRegisterFile_AddResToLive(OOC_X86_SSA__Result res, OOC_SSA_IGraph__Vector live);
  auto void OOC_X86_Register__AssignRegisterFile_AddIncomingResults(OOC_X86_SSA__LoopStartInstr loop, OOC_SSA_IGraph__Vector live);
  auto void OOC_X86_Register__AssignRegisterFile_AssignRegisterNames(OOC_X86_Register__RegisterFile rf, OOC_SSA_IGraph__ColorArray colors);
  auto void OOC_X86_Register__AssignRegisterFile_AddToReady(OOC_X86_Register__LiveData ld);
  auto void OOC_X86_Register__AssignRegisterFile_AddJumpsToReady(OOC_X86_SSA__MergeInstr merge, OOC_X86_Register__LiveData ld);
    
    void OOC_X86_Register__AssignRegisterFile_AddResToLive(OOC_X86_SSA__Result res, OOC_SSA_IGraph__Vector live) {
      register OOC_INT32 i0,i1,i2,i3,i4;

      i0 = (OOC_INT32)res;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10875))+20);
      i2 = (OOC_INT32)rf;
      i1 = i1==i2;
      if (i1) goto l3;
      i1=0u;
      goto l5;
l3:
      i1 = *(OOC_INT32*)((_check_pointer(i0, 10907))+24);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 10893))+8);
      i4 = (OOC_INT32)live;
      i1 = OOC_SSA_IGraph__GraphDesc_In((OOC_SSA_IGraph__Graph)i3, i1, (OOC_SSA_IGraph__Vector)i4);
      i1 = !i1;
      
l5:
      if (!i1) goto l7;
      i0 = *(OOC_INT32*)((_check_pointer(i0, 10958))+24);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 10937))+8);
      i2 = (OOC_INT32)live;
      OOC_SSA_IGraph__GraphDesc_AddToLive((OOC_SSA_IGraph__Graph)i1, i0, (OOC_SSA_IGraph__Vector)i2);
l7:
      return;
      ;
    }

    
    void OOC_X86_Register__AssignRegisterFile_AddIncomingResults(OOC_X86_SSA__LoopStartInstr loop, OOC_SSA_IGraph__Vector live) {
      register OOC_INT32 i0;
      auto void OOC_X86_Register__AssignRegisterFile_AddIncomingResults_InspectBlock(OOC_X86_SSA__Block b);
        
        void OOC_X86_Register__AssignRegisterFile_AddIncomingResults_InspectBlock(OOC_X86_SSA__Block b) {
          register OOC_INT32 i0,i1,i2,i3,i4,i5;
          OOC_X86_SSA__Instr instr;
          OOC_X86_SSA__Opnd opnd;

          i0 = (OOC_INT32)b;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11339))+48);
          instr = (OOC_X86_SSA__Instr)i0;
          i1 = i0!=(OOC_INT32)0;
          if (!i1) goto l24;
l3_loop:
          i1 = OOC_X86_SSA__InstrDesc_IsLive((OOC_X86_SSA__Instr)i0);
          if (!i1) goto l19;
          i1 = (OOC_INT32)OOC_X86_SSA__InstrDesc_Operands((OOC_X86_SSA__Instr)i0);
          i2 = (OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG(i1)), OOC_X86_SSA__IterInstrOperandsDesc_Next);
          i3 = OOC_TBCALL(i2,OOC_X86_SSA__IterInstrOperandsDesc_Next)((OOC_X86_SSA__IterInstrOperands)i1, (void*)(OOC_INT32)&opnd);
          if (!i3) goto l15;
l7_loop:
          i3 = (OOC_INT32)opnd;
          i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 11496));
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 11500))+4);
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 11506))+16);
          i5 = (OOC_INT32)loop;
          i4 = OOC_X86_SSA__BlockDesc_Dominates((OOC_X86_SSA__Block)i5, (OOC_X86_SSA__Block)i4);
          i4 = !i4;
          if (!i4) goto l10;
          i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 11552));
          i4 = (OOC_INT32)live;
          OOC_X86_Register__AssignRegisterFile_AddResToLive((OOC_X86_SSA__Result)i3, (OOC_SSA_IGraph__Vector)i4);
l10:
          i3 = OOC_TBCALL(i2,OOC_X86_SSA__IterInstrOperandsDesc_Next)((OOC_X86_SSA__IterInstrOperands)i1, (void*)(OOC_INT32)&opnd);
          if (i3) goto l7_loop;
l15:
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11636)))), &_td_OOC_X86_SSA__BlockDesc);
          if (!i1) goto l19;
          OOC_X86_Register__AssignRegisterFile_AddIncomingResults_InspectBlock((OOC_X86_SSA__Block)i0);
l19:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11757))+8);
          instr = (OOC_X86_SSA__Instr)i0;
          i1 = i0!=(OOC_INT32)0;
          if (i1) goto l3_loop;
l24:
          return;
          ;
        }


      i0 = (OOC_INT32)loop;
      OOC_X86_Register__AssignRegisterFile_AddIncomingResults_InspectBlock((OOC_X86_SSA__Block)i0);
      return;
      ;
    }

    
    void OOC_X86_Register__AssignRegisterFile_AssignRegisterNames(OOC_X86_Register__RegisterFile rf, OOC_SSA_IGraph__ColorArray colors) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
      OOC_INT32 i;
      OOC_X86_SSA__Result res;
      OOC_INT32 j;
      OOC_INT32 maxColor;
      OOC_INT32 c;
      OOC_INT8 first;
      OOC_INT8 last;
      OOC_INT8 colorToRegister[18];
      OOC_INT8 reg;
      auto OOC_CHAR8 OOC_X86_Register__AssignRegisterFile_AssignRegisterNames_IsFreeRegister(OOC_INT8 reg);
        
        OOC_CHAR8 OOC_X86_Register__AssignRegisterFile_AssignRegisterNames_IsFreeRegister(OOC_INT8 reg) {
          register OOC_INT32 i0,i1,i2,i3;

          i0 = (OOC_INT32)colorToRegister+18;
          i1 = i0!=(OOC_INT32)colorToRegister;
          if (!i1) goto l11;
          i1 = reg;
          i2=(OOC_INT32)colorToRegister;
l3_loop:
          i3 = *(OOC_INT8*)i2;
          i3 = i3==i1;
          if (!i3) goto l6;
          return 0u;
l6:
          i2 = i2+1;
          i3 = i0!=i2;
          if (i3) goto l3_loop;
l11:
          return 1u;
          ;
        }


      i0 = (OOC_INT32)colors;
      i = 0;
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 12583)), 0);
      i2 = (OOC_INT32)rf;
      i3 = 0<i1;
      if (!i3) goto l16;
      i3=0;
l3_loop:
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 12608))+4);
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 12619));
      i4 = _check_pointer(i4, 12625);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 12625))*4);
      res = (OOC_X86_SSA__Result)i4;
      i4 = *(OOC_INT32*)((_check_pointer(i4, 12646))+24);
      j = i4;
      i5 = i4<0;
      if (!i5) goto l11;
l6_loop:
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 12715))+4);
      i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 12726));
      i5 = _check_pointer(i5, 12732);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(((-i4)-1), i6, OOC_UINT32, 12732))*4);
      i4 = *(OOC_INT32*)((_check_pointer(i4, 12738))+24);
      j = i4;
      i5 = i4>=0;
      if (!i5) goto l6_loop;
l10:
      i5 = _check_pointer(i0, 12789);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i7 = _check_pointer(i0, 12802);
      i8 = OOC_ARRAY_LENGTH(i7, 0);
      i4 = *(OOC_INT32*)(i7+(_check_index(i4, i8, OOC_UINT32, 12802))*4);
      *(OOC_INT32*)(i5+(_check_index(i3, i6, OOC_UINT32, 12789))*4) = i4;
l11:
      i3 = i3+1;
      i = i3;
      i4 = i3<i1;
      if (i4) goto l3_loop;
l16:
      maxColor = (-1);
      i1 = _check_pointer(i0, 12937);
      i3 = OOC_ARRAY_LENGTH(i1, 0);
      i3 = i1+i3*4;
      i4 = i3!=i1;
      if (i4) goto l19;
      i1=(-1);
      goto l29;
l19:
      i4=(-1);
l20_loop:
      i5 = *(OOC_INT32*)i1;
      c = i5;
      i6 = i5>i4;
      if (!i6) goto l24;
      maxColor = i5;
      i4=i5;
l24:
      i1 = i1+4;
      i5 = i3!=i1;
      if (i5) goto l20_loop;
l28:
      i1=i4;
l29:
      *(OOC_INT32*)((_check_pointer(i2, 13062))+12) = i1;
      i3 = *(OOC_INT8*)(_check_pointer(i2, 13411));
      switch (i3) {
      case 0:
        first = 3;
        last = 8;
        goto l34;
      case 1:
        first = 10;
        last = 17;
        goto l34;
      default:
        _failed_case(i3, 13404);
        goto l34;
      }
l34:
      i3=0;
l35_loop:
      *(OOC_INT8*)((OOC_INT32)colorToRegister+(_check_index(i3, 18, OOC_UINT32, 13620))) = (-1);
      i3 = i3+1;
      i4 = i3<=17;
      if (i4) goto l35_loop;
l39:
      i = 0;
      i3=0;
l40_loop:
      i4 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i2, 13694))+16)+(_check_index(i3, 18, OOC_UINT32, 13708))*4);
      i4 = i4!=0;
      if (!i4) goto l43;
      i4 = _check_pointer(i0, 13756);
      i5 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i2, 13759))+16)+(_check_index(i3, 18, OOC_UINT32, 13773))*4);
      i5 = *(OOC_INT32*)((_check_pointer(i5, 13776))+24);
      i6 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = *(OOC_INT32*)(i4+(_check_index(i5, i6, OOC_UINT32, 13756))*4);
      i5 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i2, 13805))+16)+(_check_index(i3, 18, OOC_UINT32, 13819))*4);
      i5 = *(OOC_INT8*)((_check_pointer(i5, 13822))+13);
      *(OOC_INT8*)((OOC_INT32)colorToRegister+(_check_index(i4, 18, OOC_UINT32, 13749))) = i5;
l43:
      i3 = i3+1;
      i = i3;
      i4 = i3<=17;
      if (i4) goto l40_loop;
l47:
      i3 = first;
      i3 = i3-1;
      reg = i3;
      i = 0;
      i4 = 0<=i1;
      if (!i4) goto l64;
      i4=i3;i3=0;
l50_loop:
      i5 = *(OOC_INT8*)((OOC_INT32)colorToRegister+(_check_index(i3, 18, OOC_UINT32, 13938)));
      i5 = i5<0;
      if (!i5) goto l59;
l54_loop:
      i4 = i4+1;
      reg = i4;
      i5 = OOC_X86_Register__AssignRegisterFile_AssignRegisterNames_IsFreeRegister(i4);
      if (!i5) goto l54_loop;
l58:
      *(OOC_INT8*)((OOC_INT32)colorToRegister+(_check_index(i3, 18, OOC_UINT32, 14053))) = i4;
      
l59:
      i3 = i3+1;
      i = i3;
      i5 = i3<=i1;
      if (i5) goto l50_loop;
l64:
      i = 0;
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 14184)), 0);
      i3 = 0<i1;
      if (!i3) goto l75;
      i3=0;
l67_loop:
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14209))+4);
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 14220));
      i4 = _check_pointer(i4, 14226);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 14226))*4);
      res = (OOC_X86_SSA__Result)i4;
      i5 = *(OOC_INT8*)((_check_pointer(i4, 14246))+14);
      i5 = i5!=(-1);
      if (!i5) goto l70;
      i5 = _check_pointer(i0, 14330);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i5 = *(OOC_INT32*)(i5+(_check_index(i3, i6, OOC_UINT32, 14330))*4);
      i6 = *(OOC_INT8*)((_check_pointer(i4, 14296))+13);
      i5 = *(OOC_INT8*)((OOC_INT32)colorToRegister+(_check_index(i5, 18, OOC_UINT32, 14323)));
      _assert((i6==i5), 127, 14286);
l70:
      *(OOC_INT8*)((_check_pointer(i4, 14361))+14) = 0;
      i5 = _check_pointer(i0, 14431);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i5 = *(OOC_INT32*)(i5+(_check_index(i3, i6, OOC_UINT32, 14431))*4);
      i5 = *(OOC_INT8*)((OOC_INT32)colorToRegister+(_check_index(i5, 18, OOC_UINT32, 14424)));
      *(OOC_INT8*)((_check_pointer(i4, 14396))+13) = i5;
      i3 = i3+1;
      i = i3;
      i4 = i3<i1;
      if (i4) goto l67_loop;
l75:
      return;
      ;
    }

    
    void OOC_X86_Register__AssignRegisterFile_AddToReady(OOC_X86_Register__LiveData ld) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)ldReady;
      i1 = (OOC_INT32)ld;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14539)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i0, (Object__Object)i1);
      return;
      ;
    }

    
    void OOC_X86_Register__AssignRegisterFile_AddJumpsToReady(OOC_X86_SSA__MergeInstr merge, OOC_X86_Register__LiveData ld) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9;
      OOC_INT32 i;
      OOC_X86_SSA__Instr jump;
      OOC_X86_SSA__Block mergedBlock;
      OOC_X86_SSA__Instr position;
      OOC_X86_Register__LiveData ldJump;
      OOC_X86_SSA__Opnd opnd;

      i0 = (OOC_INT32)merge;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14807))+56);
      i = 0;
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 14813)), 0);
      i2 = 0<i1;
      if (!i2) goto l19;
      i2 = (OOC_INT32)ld;
      i3=0;
l3_loop:
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14842))+56);
      i4 = _check_pointer(i4, 14848);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 14848))*4);
      jump = (OOC_X86_SSA__Instr)i4;
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 14880))+16);
      mergedBlock = (OOC_X86_SSA__Block)i5;
      position = (OOC_X86_SSA__Instr)i4;
      i6 = *(OOC_INT8*)((_check_pointer(i0, 14931))+20);
      i6 = i6==53;
      if (i6) goto l6;
      i6=i4;
      goto l7;
l6:
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 14987))+12);
      position = (OOC_X86_SSA__Instr)i6;
      
l7:
      i7 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_Register__LiveData.baseTypes[0]);
      i8 = (OOC_INT32)rf;
      i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 15115))+12);
      i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i8, 15094))+8);
      i8 = (OOC_INT32)OOC_SSA_IGraph__GraphDesc_CopyVector((OOC_SSA_IGraph__Graph)i8, (OOC_SSA_IGraph__Vector)i9);
      OOC_X86_Register__LiveDataDesc_INIT((OOC_X86_Register__LiveData)i7, (OOC_X86_SSA__Block)i5, (OOC_X86_SSA__Instr)i6, 0, (OOC_SSA_IGraph__Vector)i8);
      ldJump = (OOC_X86_Register__LiveData)i7;
      i4 = (OOC_INT32)OOC_X86_SSA__InstrDesc_GateOperands((OOC_X86_SSA__Instr)i4);
      i5 = (OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG(i4)), OOC_X86_SSA__IterJumpGateOperandsDesc_Next);
      i6 = OOC_TBCALL(i5,OOC_X86_SSA__IterJumpGateOperandsDesc_Next)((OOC_X86_SSA__IterJumpGateOperands)i4, (void*)(OOC_INT32)&opnd);
      if (!i6) goto l14;
l9_loop:
      i6 = (OOC_INT32)opnd;
      i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i7, 15206))+12);
      i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i6, 15194));
      OOC_X86_Register__AssignRegisterFile_AddResToLive((OOC_X86_SSA__Result)i6, (OOC_SSA_IGraph__Vector)i8);
      i6 = OOC_TBCALL(i5,OOC_X86_SSA__IterJumpGateOperandsDesc_Next)((OOC_X86_SSA__IterJumpGateOperands)i4, (void*)(OOC_INT32)&opnd);
      if (i6) goto l9_loop;
l14:
      OOC_X86_Register__AssignRegisterFile_AddToReady((OOC_X86_Register__LiveData)i7);
      i3 = i3+1;
      i = i3;
      i4 = i3<i1;
      if (i4) goto l3_loop;
l19:
      return;
      ;
    }


  i0 = (OOC_INT32)rf;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15829))+4);
  i1 = *(OOC_INT32*)((_check_pointer(i1, 15840))+4);
  i1 = (OOC_INT32)OOC_SSA_IGraph__NewGraph(i1);
  *(OOC_INT32*)((_check_pointer(i0, 15800))+8) = i1;
  i1 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_Register__LiveData.baseTypes[0]);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16183))+8);
  i0 = (OOC_INT32)OOC_SSA_IGraph__GraphDesc_NewVector((OOC_SSA_IGraph__Graph)i0);
  i2 = (OOC_INT32)b;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 16166))+52);
  OOC_X86_Register__LiveDataDesc_INIT((OOC_X86_Register__LiveData)i1, (OOC_X86_SSA__Block)i2, (OOC_X86_SSA__Instr)i3, 0, (OOC_SSA_IGraph__Vector)i0);
  ld = (OOC_X86_Register__LiveData)i1;
  i0 = (OOC_INT32)RT0__NewObject(_td__qtd5.baseTypes[0]);
  ADT_ArrayList__ArrayListDesc_INIT((ADT_ArrayList__ArrayList)i0, 4);
  ldReady = (ADT_ArrayList__ArrayList)i0;
  OOC_X86_Register__AssignRegisterFile_AddToReady((OOC_X86_Register__LiveData)i1);
  i0 = (OOC_INT32)RT0__NewObject(_td__qtd7.baseTypes[0]);
  ADT_Dictionary__DictionaryDesc_INIT((ADT_Dictionary__Dictionary)i0);
  ldWaiting = (ADT_Dictionary__Dictionary)i0;
  i0 = (OOC_INT32)ldReady;
  i0 = *(OOC_INT32*)((_check_pointer(i0, 16361))+4);
  i0 = i0!=0;
  if (!i0) goto l41;
l3_loop:
  i0 = (OOC_INT32)ldReady;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 16394));
  i1 = _check_pointer(i1, 16400);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 16408))+4);
  i3 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index((i2-1), i3, OOC_UINT32, 16400))*4);
  ld = (OOC_X86_Register__LiveData)i1;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 16446))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16431)))), ADT_ArrayList__ArrayListDesc_Remove)),ADT_ArrayList__ArrayListDesc_Remove)((ADT_ArrayList__ArrayList)i0, (i2-1));
  i0 = (OOC_INT32)rf;
  OOC_X86_Register__LogLiveData((OOC_X86_Register__RegisterFile)i0, (OOC_X86_Register__LiveData)i1);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 16540))+12);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 16527))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 16517));
  i0 = (OOC_INT32)OOC_X86_Register__SweepLiveSet((OOC_X86_Register__RegisterFile)i0, (OOC_X86_SSA__Block)i4, (OOC_X86_SSA__Instr)i3, (OOC_SSA_IGraph__Vector)i2);
  instr = (OOC_X86_SSA__Instr)i0;
  i2 = i0==(OOC_INT32)0;
  if (i2) goto l13;
  i2 = *(OOC_INT8*)((_check_pointer(i0, 18490))+20);
  i2 = i2==46;
  if (i2) goto l11;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 18698));
  i2 = i0==i2;
  if (i2) goto l36;
  *(OOC_INT32*)(_check_pointer(i1, 18814)) = (_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18832)))), &_td_OOC_X86_SSA__BlockDesc, 18832));
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 18865));
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18871))+52);
  *(OOC_INT32*)((_check_pointer(i1, 18850))+4) = i0;
  OOC_X86_Register__AssignRegisterFile_AddToReady((OOC_X86_Register__LiveData)i1);
  goto l36;
l11:
  i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_TopLevelMerge((OOC_X86_SSA__Instr)i0);
  merge = (OOC_X86_SSA__MergeInstr)i0;
  *(OOC_INT32*)(_check_pointer(i1, 18591)) = i0;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 18633));
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18639))+52);
  *(OOC_INT32*)((_check_pointer(i1, 18618))+4) = i0;
  OOC_X86_Register__AssignRegisterFile_AddToReady((OOC_X86_Register__LiveData)i1);
  goto l36;
l13:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 16602));
  block = (OOC_X86_SSA__Block)i0;
  i2 = *(OOC_INT8*)((_check_pointer(i0, 16628))+20);
  switch (i2) {
  case 48:
    OOC_X86_Register__AssignRegisterFile_AddJumpsToReady((OOC_X86_SSA__MergeInstr)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16692)))), &_td_OOC_X86_SSA__MergeInstrDesc, 16692)), (OOC_X86_Register__LiveData)i1);
    goto l36;
  case 53:
    OOC_X86_Register__AssignRegisterFile_AddJumpsToReady((OOC_X86_SSA__MergeInstr)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16776)))), &_td_OOC_X86_SSA__MergeInstrDesc, 16776)), (OOC_X86_Register__LiveData)i1);
    i0 = (OOC_INT32)block;
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16818))+12);
    instr = (OOC_X86_SSA__Instr)i1;
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16855)))), &_td_OOC_X86_SSA__LoopStartInstrDesc, 16855)), 16870))+60);
    _assert((i2==i0), 127, 16840);
    i0 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_Register__LiveData.baseTypes[0]);
    i2 = (OOC_INT32)ld;
    i3 = (OOC_INT32)rf;
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 17116))+12);
    i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 17095))+8);
    i2 = (OOC_INT32)OOC_SSA_IGraph__GraphDesc_CopyVector((OOC_SSA_IGraph__Graph)i3, (OOC_SSA_IGraph__Vector)i2);
    i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17043)))), &_td_OOC_X86_SSA__LoopStartInstrDesc, 17043)), 17058))+52);
    OOC_X86_Register__LiveDataDesc_INIT((OOC_X86_Register__LiveData)i0, (OOC_X86_SSA__Block)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16998)))), &_td_OOC_X86_SSA__LoopStartInstrDesc, 16998)), (OOC_X86_SSA__Instr)i3, 0, (OOC_SSA_IGraph__Vector)i2);
    ld = (OOC_X86_Register__LiveData)i0;
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17249))+12);
    OOC_X86_Register__AssignRegisterFile_AddIncomingResults((OOC_X86_SSA__LoopStartInstr)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17230)))), &_td_OOC_X86_SSA__LoopStartInstrDesc, 17230)), (OOC_SSA_IGraph__Vector)i0);
    i0 = (OOC_INT32)ld;
    OOC_X86_Register__AssignRegisterFile_AddToReady((OOC_X86_Register__LiveData)i0);
    goto l36;
  case 46:
  case 52:
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17354))+16);
    *(OOC_INT32*)(_check_pointer(i1, 17339)) = i2;
    *(OOC_INT32*)((_check_pointer(i1, 17374))+4) = i0;
    OOC_X86_Register__AssignRegisterFile_AddToReady((OOC_X86_Register__LiveData)i1);
    goto l36;
  case 47:
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17472)))), &_td_OOC_X86_SSA__MergeInstrDesc, 17472)), 17483))+56);
    i2 = i2!=(OOC_INT32)0;
    if (!i2) goto l21;
    OOC_X86_Register__AssignRegisterFile_AddJumpsToReady((OOC_X86_SSA__MergeInstr)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17538)))), &_td_OOC_X86_SSA__MergeInstrDesc, 17538)), (OOC_X86_Register__LiveData)i1);
l21:
    i0 = (OOC_INT32)block;
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17612))+16);
    i0 = _type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17621)))), &_td_OOC_X86_SSA__BranchInstrDesc, 17621);
    branchBlock = (OOC_X86_SSA__Block)i0;
    i1 = (OOC_INT32)ldWaiting;
    i2 = ADT_Dictionary__DictionaryDesc_HasKey((ADT_Dictionary__Dictionary)i1, (Object__Object)i0);
    if (i2) goto l28;
    i2 = (OOC_INT32)ld;
    i3 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_Register__LiveData.baseTypes[0]);
    i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18142)))), &_td_OOC_X86_SSA__BranchInstrDesc, 18142)), 18154))+56);
    i4 = OOC_ARRAY_LENGTH((_check_pointer(i4, 18160)), 0);
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 18168))+12);
    OOC_X86_Register__LiveDataDesc_INIT((OOC_X86_Register__LiveData)i3, (OOC_X86_SSA__Block)i0, (OOC_X86_SSA__Instr)(OOC_INT32)0, (i4-1), (OOC_SSA_IGraph__Vector)i2);
    ld = (OOC_X86_Register__LiveData)i3;
    i2 = *(OOC_INT32*)((_check_pointer(i3, 18194))+8);
    i2 = i2==0;
    if (i2) goto l26;
    ADT_Dictionary__DictionaryDesc_Set((ADT_Dictionary__Dictionary)i1, (Object__Object)i0, (Object__Object)i3);
    goto l36;
l26:
    OOC_X86_Register__AssignRegisterFile_AddToReady((OOC_X86_Register__LiveData)i3);
    i0 = (OOC_INT32)rf;
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18266))+88);
    i1 = (OOC_INT32)branchBlock;
    ADT_Dictionary__DictionaryDesc_Set((ADT_Dictionary__Dictionary)i0, (Object__Object)i1, (Object__Object)(OOC_INT32)0);
    goto l36;
l28:
    i0 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i1, (Object__Object)i0);
    ldBranch = (OOC_X86_Register__LiveData)i0;
    i1 = (OOC_INT32)ld;
    i2 = (OOC_INT32)rf;
    i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17786))+12);
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 17771))+12);
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 17749))+8);
    OOC_SSA_IGraph__GraphDesc_MergeVector((OOC_SSA_IGraph__Graph)i2, (OOC_SSA_IGraph__Vector)i1, (OOC_SSA_IGraph__Vector)i3);
    i1 = *(OOC_INT32*)((_check_pointer(i0, 17818))+8);
    *(OOC_INT32*)((_check_pointer(i0, 17818))+8) = (i1-1);
    i1 = *(OOC_INT32*)((_check_pointer(i0, 17860))+8);
    i1 = i1==0;
    if (!i1) goto l36;
    OOC_X86_Register__AssignRegisterFile_AddToReady((OOC_X86_Register__LiveData)i0);
    i0 = (OOC_INT32)branchBlock;
    i1 = (OOC_INT32)ldWaiting;
    ADT_Dictionary__DictionaryDesc_Delete((ADT_Dictionary__Dictionary)i1, (Object__Object)i0);
    i1 = (OOC_INT32)rf;
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 17983))+88);
    ADT_Dictionary__DictionaryDesc_Set((ADT_Dictionary__Dictionary)i1, (Object__Object)i0, (Object__Object)(OOC_INT32)0);
    goto l36;
  case 31:
    goto l36;
  default:
    _failed_case(i2, 16618);
    goto l36;
  }
l36:
  i0 = (OOC_INT32)ldReady;
  i0 = *(OOC_INT32*)((_check_pointer(i0, 16361))+4);
  i0 = i0!=0;
  if (i0) goto l3_loop;
l41:
  i0 = (OOC_INT32)ldWaiting;
  i0 = ADT_Dictionary__DictionaryDesc_Size((ADT_Dictionary__Dictionary)i0);
  _assert((i0==0), 127, 18931);
  i0 = (OOC_INT32)rf;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18967))+8);
  OOC_SSA_IGraph__GraphDesc_SymmetricMatrix((OOC_SSA_IGraph__Graph)i1);
  i1 = (OOC_INT32)b;
  i1 = OOC_X86_Register__CoalesceFixedLocations((OOC_X86_Register__RegisterFile)i0, (OOC_X86_SSA__FunctionBlock)i1);
  addedCopies = i1;
  i1 = i1==0;
  if (!i1) goto l48;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19356))+8);
  i1 = (OOC_INT32)OOC_SSA_IGraph__GraphDesc_ColorGraphCombinatorial((OOC_SSA_IGraph__Graph)i1);
  coloring = (OOC_SSA_IGraph__ColorArray)i1;
  i2 = i1==(OOC_INT32)0;
  if (!i2) goto l47;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19444))+8);
  i1 = (OOC_INT32)OOC_SSA_IGraph__GraphDesc_ColorGraphSimple((OOC_SSA_IGraph__Graph)i1);
  coloring = (OOC_SSA_IGraph__ColorArray)i1;
  
l47:
  OOC_X86_Register__AssignRegisterFile_AssignRegisterNames((OOC_X86_Register__RegisterFile)i0, (OOC_SSA_IGraph__ColorArray)i1);
l48:
  i0 = addedCopies;
  return i0;
  ;
}

void OOC_X86_Register__AssignRegisters(OOC_X86_SSA__FunctionBlock b) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_X86_Register__RegisterFiles rfs;
  OOC_INT32 addedCopies;
  OOC_X86_Register__RegisterFile rf;

  i0 = (OOC_INT32)b;
l1_loop:
  OOC_X86_SSA__BlockDesc_SetMarkers((OOC_X86_SSA__Block)i0, (OOC_X86_SSA__Node)(OOC_INT32)0, (-1));
  i1 = (OOC_INT32)OOC_X86_Register__IdentifyResults((OOC_X86_SSA__FunctionBlock)i0);
  rfs = (OOC_X86_Register__RegisterFiles)i1;
  addedCopies = 0;
  i1 = _check_pointer(i1, 20275);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i2 = i1+i2*4;
  i3 = i2!=i1;
  if (i3) goto l4;
  i1=0;
  goto l18;
l4:
  i3=0;
l5_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)i1;
  rf = (OOC_X86_Register__RegisterFile)i4;
  i5 = i4!=(OOC_INT32)0;
  if (i5) goto l8;
  i5=0u;
  goto l10;
l8:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 20307))+8);
  i5 = i5==(OOC_INT32)0;
  
l10:
  if (!i5) goto l13;
  i4 = OOC_X86_Register__AssignRegisterFile((OOC_X86_Register__RegisterFile)i4, (OOC_X86_SSA__FunctionBlock)i0);
  i3 = i3+i4;
  addedCopies = i3;
  
l13:
  i1 = i1+4;
  i4 = i2!=i1;
  if (i4) goto l5_loop;
l17:
  i1=i3;
l18:
  i1 = i1==0;
  if (!i1) goto l1_loop;
l22:
  return;
  ;
}

void OOC_OOC_X86_Register_init(void) {

  return;
  ;
}

void OOC_OOC_X86_Register_destroy(void) {
}

/* --- */
