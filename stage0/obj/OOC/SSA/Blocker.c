#include <OOC/SSA/Blocker.d>
#include <__oo2c.h>
#include <setjmp.h>

static void OOC_SSA_Blocker__InitProxy(OOC_SSA_Blocker__Proxy p, OOC_SSA__Instr instr) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)p;
  *(OOC_INT32*)(_check_pointer(i0, 7119)) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 7144))+4) = 0;
  i1 = (OOC_INT32)instr;
  *(OOC_INT32*)((_check_pointer(i0, 7169))+8) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 7192))+12) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 7214))+16) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 7239))+20) = 0;
  *(OOC_UINT8*)((_check_pointer(i0, 7269))+24) = 0u;
  *(OOC_INT32*)((_check_pointer(i0, 7300))+28) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 7333))+32) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 7353))+36) = (-1);
  *(OOC_INT32*)((_check_pointer(i0, 7374))+40) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 7396))+44) = 0;
  return;
  ;
}

static OOC_SSA_Blocker__Proxy OOC_SSA_Blocker__NewProxy(OOC_SSA__Instr instr) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_SSA_Blocker__Proxy.baseTypes[0]);
  i1 = (OOC_INT32)instr;
  OOC_SSA_Blocker__InitProxy((OOC_SSA_Blocker__Proxy)i0, (OOC_SSA__Instr)i1);
  return (OOC_SSA_Blocker__Proxy)i0;
  ;
}

static void OOC_SSA_Blocker__ClearMarkers(OOC_SSA_Blocker__Region r) {
  register OOC_INT32 i0,i1;
  OOC_SSA_Blocker__Proxy proxy;

  i0 = (OOC_INT32)r;
  *(OOC_INT32*)((_check_pointer(i0, 7650))+32) = 0;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7679))+48);
  proxy = (OOC_SSA_Blocker__Proxy)i0;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l11;
l3_loop:
  *(OOC_INT32*)((_check_pointer(i0, 7726))+32) = 0;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7757)))), &_td_OOC_SSA_Blocker__RegionDesc);
  if (!i1) goto l6;
  OOC_SSA_Blocker__ClearMarkers((OOC_SSA_Blocker__Region)i0);
l6:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7884));
  proxy = (OOC_SSA_Blocker__Proxy)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l3_loop;
l11:
  return;
  ;
}

static void OOC_SSA_Blocker__InitRegion(OOC_SSA_Blocker__Region r, OOC_SSA__Instr instr) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)instr;
  OOC_SSA_Blocker__InitProxy((OOC_SSA_Blocker__Proxy)i0, (OOC_SSA__Instr)i1);
  *(OOC_INT32*)((_check_pointer(i0, 8108))+48) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i0, 8129))+52) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i0, 8149))+56) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 8175))+32) = 0;
  return;
  ;
}

static OOC_SSA_Blocker__Region OOC_SSA_Blocker__NewRegion(OOC_SSA__Instr instr) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_SSA_Blocker__Region.baseTypes[0]);
  i1 = (OOC_INT32)instr;
  OOC_SSA_Blocker__InitRegion((OOC_SSA_Blocker__Region)i0, (OOC_SSA__Instr)i1);
  return (OOC_SSA_Blocker__Region)i0;
  ;
}

void OOC_SSA_Blocker__RegionDesc_Append(OOC_SSA_Blocker__Region r, OOC_SSA_Blocker__Proxy p) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)p;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8419))+12);
  _assert((i1==(OOC_INT32)0), 127, 8410);
  i1 = (OOC_INT32)r;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 8462))+52);
  *(OOC_INT32*)((_check_pointer(i0, 8446))+4) = i2;
  *(OOC_INT32*)(_check_pointer(i0, 8475)) = (OOC_INT32)0;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 8504))+52);
  i2 = i2!=(OOC_INT32)0;
  if (i2) goto l3;
  *(OOC_INT32*)((_check_pointer(i1, 8570))+48) = i0;
  goto l4;
l3:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 8530))+52);
  *(OOC_INT32*)(_check_pointer(i2, 8536)) = i0;
l4:
  *(OOC_INT32*)((_check_pointer(i1, 8598))+52) = i0;
  *(OOC_INT32*)((_check_pointer(i0, 8621))+12) = i1;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8646)))), &_td_OOC_SSA_Blocker__RegionDesc);
  if (!i2) goto l7;
  i1 = *(OOC_INT32*)((_check_pointer(i1, 8696))+56);
  *(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8670)))), &_td_OOC_SSA_Blocker__RegionDesc, 8670)), 8677))+56) = (i1+1);
l7:
  return;
  ;
}

void OOC_SSA_Blocker__RegionDesc_Insert(OOC_SSA_Blocker__Region r, OOC_SSA_Blocker__Proxy p) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)p;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8799))+12);
  _assert((i1==(OOC_INT32)0), 127, 8790);
  *(OOC_INT32*)((_check_pointer(i0, 8826))+4) = (OOC_INT32)0;
  i1 = (OOC_INT32)r;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 8867))+48);
  *(OOC_INT32*)(_check_pointer(i0, 8851)) = i2;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 8885))+48);
  i2 = i2!=(OOC_INT32)0;
  if (i2) goto l3;
  *(OOC_INT32*)((_check_pointer(i1, 8953))+52) = i0;
  goto l4;
l3:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 8912))+48);
  *(OOC_INT32*)((_check_pointer(i2, 8919))+4) = i0;
l4:
  *(OOC_INT32*)((_check_pointer(i1, 8980))+48) = i0;
  *(OOC_INT32*)((_check_pointer(i0, 9004))+12) = i1;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9029)))), &_td_OOC_SSA_Blocker__RegionDesc);
  if (!i2) goto l7;
  i1 = *(OOC_INT32*)((_check_pointer(i1, 9079))+56);
  *(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9053)))), &_td_OOC_SSA_Blocker__RegionDesc, 9053)), 9060))+56) = (i1+1);
l7:
  return;
  ;
}

void OOC_SSA_Blocker__RegionDesc_Remove(OOC_SSA_Blocker__Region r, OOC_SSA_Blocker__Proxy p) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)p;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9182))+12);
  i2 = (OOC_INT32)r;
  _assert((i1==i2), 127, 9173);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9206))+4);
  i1 = i1!=(OOC_INT32)0;
  if (i1) goto l3;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 9305));
  *(OOC_INT32*)((_check_pointer(i2, 9293))+48) = i1;
  goto l4;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9237))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 9264));
  *(OOC_INT32*)(_check_pointer(i1, 9248)) = i3;
l4:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 9336));
  i1 = i1!=(OOC_INT32)0;
  if (i1) goto l7;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9434))+4);
  *(OOC_INT32*)((_check_pointer(i2, 9423))+52) = i1;
  goto l8;
l7:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 9367));
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9394))+4);
  *(OOC_INT32*)((_check_pointer(i1, 9378))+4) = i2;
l8:
  *(OOC_INT32*)((_check_pointer(i0, 9466))+12) = (OOC_INT32)0;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9493)))), &_td_OOC_SSA_Blocker__RegionDesc);
  if (!i1) goto l11;
  *(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9517)))), &_td_OOC_SSA_Blocker__RegionDesc, 9517)), 9524))+56) = 0;
l11:
  return;
  ;
}

static void OOC_SSA_Blocker__InitSelect(OOC_SSA_Blocker__Select r, OOC_SSA__Instr instr) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_INT32 i;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)instr;
  OOC_SSA_Blocker__InitRegion((OOC_SSA_Blocker__Region)i0, (OOC_SSA__Instr)i1);
  i1 = OOC_SSA__InstrDesc_SizeOpndList((OOC_SSA__Instr)i1);
  *(OOC_INT32*)((_check_pointer(i0, 9778))+60) = ((OOC_INT32)RT0__NewObject(_td_OOC_SSA_Blocker__5557.baseTypes[0], (i1>>1)));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9841))+60);
  i = 0;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 9848)), 0);
  i2 = 0<i1;
  if (!i2) goto l8;
  i2=0;
l3_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9863))+60);
  i3 = _check_pointer(i3, 9870);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 9870))*4) = (OOC_INT32)0;
  i2 = i2+1;
  i = i2;
  i3 = i2<i1;
  if (i3) goto l3_loop;
l8:
  return;
  ;
}

static OOC_SSA_Blocker__Select OOC_SSA_Blocker__NewSelect(OOC_SSA__Instr instr) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_SSA_Blocker__Select.baseTypes[0]);
  i1 = (OOC_INT32)instr;
  OOC_SSA_Blocker__InitSelect((OOC_SSA_Blocker__Select)i0, (OOC_SSA__Instr)i1);
  return (OOC_SSA_Blocker__Select)i0;
  ;
}

static void OOC_SSA_Blocker__InitLoop(OOC_SSA_Blocker__Loop r, OOC_SSA__Instr instr) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)instr;
  OOC_SSA_Blocker__InitRegion((OOC_SSA_Blocker__Region)i0, (OOC_SSA__Instr)i1);
  *(OOC_INT32*)((_check_pointer(i0, 10234))+64) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i0, 10258))+60) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i0, 10285))+68) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i0, 10311))+72) = (OOC_INT32)0;
  *(OOC_UINT8*)((_check_pointer(i0, 10341))+76) = 0u;
  return;
  ;
}

static OOC_SSA_Blocker__Loop OOC_SSA_Blocker__NewLoop(OOC_SSA__Instr instr) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_SSA_Blocker__Loop.baseTypes[0]);
  i1 = (OOC_INT32)instr;
  OOC_SSA_Blocker__InitLoop((OOC_SSA_Blocker__Loop)i0, (OOC_SSA__Instr)i1);
  return (OOC_SSA_Blocker__Loop)i0;
  ;
}

void OOC_SSA_Blocker__LoopDesc_AppendLoop(OOC_SSA_Blocker__Loop loop, OOC_SSA_Blocker__Loop nestedLoop) {
  register OOC_INT32 i0,i1;
  auto void OOC_SSA_Blocker__LoopDesc_AppendLoop_App(OOC_SSA_Blocker__Loop *list);
    
    void OOC_SSA_Blocker__LoopDesc_AppendLoop_App(OOC_SSA_Blocker__Loop *list) {
      register OOC_INT32 i0,i1,i2;

      i0 = (OOC_INT32)nestedLoop;
      i1 = (OOC_INT32)*list;
      _assert((i0!=i1), 127, 10622);
      i2 = i1==(OOC_INT32)0;
      if (i2) goto l3;
      OOC_SSA_Blocker__LoopDesc_AppendLoop_App((void*)((_check_pointer(i1, 10770))+64));
      goto l4;
l3:
      *(OOC_INT32*)((_check_pointer(i0, 10695))+64) = (OOC_INT32)0;
      *list = (OOC_SSA_Blocker__Loop)i0;
l4:
      return;
      ;
    }


  i0 = (OOC_INT32)loop;
  OOC_SSA_Blocker__LoopDesc_AppendLoop_App((void*)((_check_pointer(i0, 10831))+60));
  i0 = (OOC_INT32)nestedLoop;
  i1 = (OOC_INT32)loop;
  *(OOC_INT32*)((_check_pointer(i0, 10861))+68) = i1;
  return;
  ;
}

static OOC_SSA_Blocker__Proxy OOC_SSA_Blocker__GetProxy(OOC_SSA__Instr instr) {
  register OOC_INT32 i0,i1;
  OOC_SSA_Blocker__Proxy p;

  i0 = (OOC_INT32)instr;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10993))+16);
  i1 = i1!=(OOC_INT32)0;
  if (i1) goto l9;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 11070))+36);
  switch (i1) {
  case 8:
    i1 = (OOC_INT32)OOC_SSA_Blocker__NewRegion((OOC_SSA__Instr)i0);
    p = (OOC_SSA_Blocker__Proxy)i1;
    
    goto l8;
  case 5:
    i1 = (OOC_INT32)OOC_SSA_Blocker__NewSelect((OOC_SSA__Instr)i0);
    p = (OOC_SSA_Blocker__Proxy)i1;
    
    goto l8;
  case 11:
    i1 = (OOC_INT32)OOC_SSA_Blocker__NewLoop((OOC_SSA__Instr)i0);
    p = (OOC_SSA_Blocker__Proxy)i1;
    
    goto l8;
  default:
    i1 = (OOC_INT32)OOC_SSA_Blocker__NewProxy((OOC_SSA__Instr)i0);
    p = (OOC_SSA_Blocker__Proxy)i1;
    
    goto l8;
  }
l8:
  *(OOC_INT32*)((_check_pointer(i0, 11316))+16) = i1;
  return (OOC_SSA_Blocker__Proxy)i1;
  goto l10;
l9:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11030))+16);
  return (OOC_SSA_Blocker__Proxy)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11037)))), &_td_OOC_SSA_Blocker__ProxyDesc, 11037));
l10:
  _failed_function(10914); return 0;
  ;
}

static OOC_CHAR8 OOC_SSA_Blocker__Dominates(OOC_SSA_Blocker__Region dom, OOC_SSA_Blocker__Region child) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)child;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_INT32)dom;
  i1 = i0!=i1;
  
l5:
  if (!i1) goto l17;
  i1 = (OOC_INT32)dom;
  
l8_loop:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11493))+12);
  child = (OOC_SSA_Blocker__Region)i0;
  i2 = i0!=(OOC_INT32)0;
  if (i2) goto l11;
  i2=0u;
  goto l13;
l11:
  i2 = i0!=i1;
  
l13:
  if (i2) goto l8_loop;
l17:
  return (i0!=(OOC_INT32)0);
  ;
}

static void OOC_SSA_Blocker__WriteBlocks(IO__ByteChannel c, OOC_SSA__ProcBlock pb, OOC_SSA_Blocker__Region root, ADT_Dictionary__Dictionary marker) {
  register OOC_INT32 i0,i1,i2;
  ADT_Dictionary_IntValue__Dictionary idMap;
  OOC_INT32 instrCount;
  IO_TextRider__Writer w;
  auto void OOC_SSA_Blocker__WriteBlocks_AssignId(OOC_SSA_Blocker__Proxy p);
  auto void OOC_SSA_Blocker__WriteBlocks_WriteInstrPrefix(OOC_SSA_Blocker__Proxy p);
  auto void OOC_SSA_Blocker__WriteBlocks_WriteResultId(OOC_SSA__Result res);
  auto void OOC_SSA_Blocker__WriteBlocks_WriteOpnd(OOC_SSA__Opnd opnd);
  auto void OOC_SSA_Blocker__WriteBlocks_WriteInstr(OOC_SSA_Blocker__Proxy p);
  auto void OOC_SSA_Blocker__WriteBlocks_WriteRegion(OOC_SSA_Blocker__Region r);
    
    void OOC_SSA_Blocker__WriteBlocks_AssignId(OOC_SSA_Blocker__Proxy p) {
      register OOC_INT32 i0,i1,i2;
      OOC_SSA_Blocker__Proxy n;

      i0 = (OOC_INT32)p;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11863)))), &_td_OOC_SSA_Blocker__RegionDesc);
      if (!i1) goto l11;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11889))+48);
      n = (OOC_SSA_Blocker__Proxy)i1;
      i2 = i1!=(OOC_INT32)0;
      if (!i2) goto l11;
l5_loop:
      OOC_SSA_Blocker__WriteBlocks_AssignId((OOC_SSA_Blocker__Proxy)i1);
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 11965));
      n = (OOC_SSA_Blocker__Proxy)i1;
      i2 = i1!=(OOC_INT32)0;
      if (i2) goto l5_loop;
l11:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12025))+8);
      i1 = i1!=(OOC_INT32)0;
      if (i1) goto l14;
      i1=0u;
      goto l16;
l14:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12044))+8);
      i1 = OOC_SSA__InstrDesc_IsConst((OOC_SSA__Instr)i1);
      i1 = !i1;
      
l16:
      if (!i1) goto l18;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12089))+8);
      i1 = (OOC_INT32)idMap;
      i2 = instrCount;
      ADT_Dictionary_IntValue__DictionaryDesc_Set((ADT_Dictionary_IntValue__Dictionary)i1, (Object__Object)i0, i2);
      i0 = instrCount;
      instrCount = (i0+1);
l18:
      return;
      ;
    }

    
    void OOC_SSA_Blocker__WriteBlocks_WriteInstrPrefix(OOC_SSA_Blocker__Proxy p) {
      register OOC_INT32 i0,i1,i2;
      OOC_SSA__Instr instr;
      OOC_INT32 d;
      OOC_SSA_Blocker__Region r;
      OOC_INT32 i;

      i0 = (OOC_INT32)p;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12304))+8);
      instr = (OOC_SSA__Instr)i1;
      i2 = i1==(OOC_INT32)0;
      if (i2) goto l3;
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 12483)))), IO_TextRider__WriterDesc_WriteHex)),IO_TextRider__WriterDesc_WriteHex)((IO_TextRider__Writer)i2, (_type_cast_fast(OOC_INT32, OOC_INT32, i1)), 8);
      goto l4;
l3:
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 12422)))), IO_TextRider__WriterDesc_WriteHex)),IO_TextRider__WriterDesc_WriteHex)((IO_TextRider__Writer)i1, (_type_cast_fast(OOC_INT32, OOC_INT32, i0)), 8);
l4:
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 12554)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, "  ", 3);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13147))+12);
      i1 = i1!=(OOC_INT32)0;
      if (!i1) goto l28;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13182))+12);
      i1 = *(OOC_INT32*)((_check_pointer(i1, 13190))+56);
      d = i1;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13220))+12);
      r = (OOC_SSA_Blocker__Region)i0;
      i2 = i0!=(OOC_INT32)0;
      if (i2) goto l10_loop;
      i0=i1;
      goto l19;
l10_loop:
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13273)))), &_td_OOC_SSA_Blocker__SelectDesc);
      if (!i2) goto l14;
      i1 = i1-1;
      d = i1;
      
l14:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13341))+12);
      r = (OOC_SSA_Blocker__Region)i0;
      i2 = i0!=(OOC_INT32)0;
      if (i2) goto l10_loop;
l18:
      i0=i1;
l19:
      i = 1;
      i1 = 1<=i0;
      if (!i1) goto l28;
      i1=1;
l22_loop:
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 13402)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i2, "  ", 3);
      i1 = i1+1;
      i = i1;
      i2 = i1<=i0;
      if (i2) goto l22_loop;
l28:
      return;
      ;
    }

    
    void OOC_SSA_Blocker__WriteBlocks_WriteResultId(OOC_SSA__Result res) {
      register OOC_INT32 i0,i1,i2,i3;
      Object__Object obj;
      OOC_SSA__Instr instr;
      Object__String value;
      OOC_INT32 id;
      OOC_INT32 count;
      OOC_SSA__Result ptr;

      i0 = (OOC_INT32)marker;
      i1 = (OOC_INT32)res;
      i0 = ADT_Dictionary__DictionaryDesc_HasKey((ADT_Dictionary__Dictionary)i0, (Object__Object)i1);
      if (!i0) goto l3;
      i0 = (OOC_INT32)marker;
      i0 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i0, (Object__Object)i1);
      obj = (Object__Object)i0;
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 13738)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i2, 91u);
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 13766)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i2, (Object__Object)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13796)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i0, 93u);
l3:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 13900))+8);
      instr = (OOC_SSA__Instr)i0;
      i2 = OOC_SSA__InstrDesc_IsConst((OOC_SSA__Instr)i0);
      if (i2) goto l18;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14959))+8);
      i2 = (OOC_INT32)idMap;
      i0 = ADT_Dictionary_IntValue__DictionaryDesc_Get((ADT_Dictionary_IntValue__Dictionary)i2, (Object__Object)i0);
      id = i0;
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 14978)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i2, 40u);
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 15006)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i2, i0, 0);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 15042))+8);
      i0 = i0!=i1;
      if (!i0) goto l17;
      count = 1;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 15104))+8);
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 15111));
      ptr = (OOC_SSA__Result)i0;
      i2 = i0!=i1;
      if (i2) goto l10;
      i0=1;
      goto l16;
l10:
      i2=i0;i0=1;
l11_loop:
      i0 = i0+1;
      count = i0;
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 15203));
      ptr = (OOC_SSA__Result)i2;
      i3 = i2!=i1;
      if (i3) goto l11_loop;
l16:
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15243)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i1, 46u);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15273)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i1, i0, 0);
l17:
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15319)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i0, 41u);
      goto l43;
l18:
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13958)))), &_td_OOC_SSA__ConstDesc);
      if (i1) goto l37;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14180)))), &_td_OOC_SSA__DeclRefDesc);
      if (i1) goto l35;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14264)))), &_td_OOC_SSA__TypeRefDesc);
      if (i1) goto l33;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14336)))), &_td_OOC_SSA__AddressDesc);
      if (i1) goto l31;
      i1 = *(OOC_INT8*)((_check_pointer(i0, 14468))+36);
      switch (i1) {
      case 56:
      case 57:
        i1 = (OOC_INT32)w;
        i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14570))+24);
        i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14580))+8);
        i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14590))+8);
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 14600));
        i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 14638)))), &_td_OOC_SSA__DeclRefDesc, 14638)), 14646))+44);
        i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14652))+20);
        i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14658))+12);
        i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14570))+24);
        i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 14580))+8);
        i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 14590))+8);
        i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 14600));
        i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 14638)))), &_td_OOC_SSA__DeclRefDesc, 14638)), 14646))+44);
        i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 14652))+20);
        i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 14658))+12);
        i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 14663)), 0);
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14550)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, (void*)(_check_pointer(i2, 14663)), i3);
        i1 = (OOC_INT32)w;
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14680)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, "/dim", 5);
        i1 = (OOC_INT32)w;
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14735))+24);
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 14745));
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14755)))), &_td_OOC_SSA__ConstDesc, 14755)), 14761))+44);
        i0 = Object_BigInt__BigIntDesc_ToLongInt((Object_BigInt__BigInt)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14776)))), &_td_Object_BigInt__BigIntDesc, 14776)));
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14717)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i1, i0, 0);
        goto l43;
      default:
        OOC_SSA__InstrDesc_LogOpcode((OOC_SSA__Instr)i0, "instr.opcode", 13);
        _assert(0u, 127, 14876);
        goto l43;
      }
l31:
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14364)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i1, 38u);
      i1 = (OOC_INT32)w;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14414))+44);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14420))+20);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14426))+12);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14414))+44);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14420))+20);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14426))+12);
      i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 14431)), 0);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14394)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, (void*)(_check_pointer(i2, 14431)), i0);
      goto l43;
l33:
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14292)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "<typeref>", 10);
      goto l43;
l35:
      i1 = (OOC_INT32)w;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14228))+44);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14234))+20);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14240))+12);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14228))+44);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14234))+20);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14240))+12);
      i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 14245)), 0);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14208)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, (void*)(_check_pointer(i2, 14245)), i0);
      goto l43;
l37:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13992))+44);
      i2 = (OOC_INT32)OOC_SSA__nil;
      i1 = i1==i2;
      if (i1) goto l40;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14093))+44);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14093))+44);
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14100)))), Object_Boxed__ObjectDesc_ToString)),Object_Boxed__ObjectDesc_ToString)((Object_Boxed__Object)i0);
      value = (Object__String)i0;
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14127)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i1, (Object__Object)i0);
      goto l43;
l40:
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14029)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "NIL", 4);
l43:
      return;
      ;
    }

    
    void OOC_SSA_Blocker__WriteBlocks_WriteOpnd(OOC_SSA__Opnd opnd) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)opnd;
      i1 = *(OOC_INT8*)((_check_pointer(i0, 15438))+4);
      switch (i1) {
      case 18:
        i1 = (OOC_INT32)w;
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15487)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, "*ad*", 5);
        goto l6;
      case 20:
        i1 = (OOC_INT32)w;
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15551)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, "*rd*", 5);
        goto l6;
      case 17:
        i1 = (OOC_INT32)w;
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15614)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, "*led*", 6);
        goto l6;
      default:
        goto l6;
      }
l6:
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 15791));
      OOC_SSA_Blocker__WriteBlocks_WriteResultId((OOC_SSA__Result)i0);
      return;
      ;
    }

    
    void OOC_SSA_Blocker__WriteBlocks_WriteInstr(OOC_SSA_Blocker__Proxy p) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_SSA__Instr instr;
      OOC_INT32 resCount;
      OOC_SSA__Result res;
      OOC_CHAR8 str[64];
      OOC_SSA__Opnd opnd;

      i0 = (OOC_INT32)p;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16020))+8);
      instr = (OOC_SSA__Instr)i1;
      i2 = OOC_SSA__InstrDesc_IsConst((OOC_SSA__Instr)i1);
      i2 = !i2;
      if (!i2) goto l40;
      OOC_SSA_Blocker__WriteBlocks_WriteInstrPrefix((OOC_SSA_Blocker__Proxy)i0);
      resCount = 0;
      res = (OOC_SSA__Result)i1;
      i0 = i1!=(OOC_INT32)0;
      if (i0) goto l5;
      i0=0;
      goto l22;
l5:
      i0=i1;i2=0;
l6_loop:
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16191))+12);
      i3 = i3!=(OOC_INT32)0;
      if (i3) goto l9;
      i3 = *(OOC_INT8*)((_check_pointer(i1, 16217))+36);
      i3 = i3==8;
      
      goto l11;
l9:
      i3=1u;
l11:
      if (!i3) goto l17;
      i3 = i2!=0;
      if (!i3) goto l16;
      i3 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 16304)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i3, 44u);
l16:
      OOC_SSA_Blocker__WriteBlocks_WriteResultId((OOC_SSA__Result)i0);
      i2 = i2+1;
      resCount = i2;
      
l17:
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 16436));
      res = (OOC_SSA__Result)i0;
      i3 = i0!=(OOC_INT32)0;
      if (i3) goto l6_loop;
l21:
      i0=i2;
l22:
      i0 = i0==0;
      if (!i0) goto l25;
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16505)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "(--)", 5);
l25:
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16560)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, " := ", 5);
      i0 = *(OOC_INT8*)((_check_pointer(i1, 16628))+5);
      i2 = *(OOC_INT8*)((_check_pointer(i1, 16613))+36);
      OOC_SSA_Opcode__GetName(i2, i0, (void*)(OOC_INT32)str, 64);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16655)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (void*)(OOC_INT32)str, 64);
      i0 = *(OOC_INT32*)((_check_pointer(i1, 16693))+40);
      i0 = i0>=0;
      if (!i0) goto l28;
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16721)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "@", 2);
      i0 = (OOC_INT32)w;
      i2 = *(OOC_INT32*)((_check_pointer(i1, 16771))+40);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16753)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i0, i2, 0);
l28:
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16804)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i0, 32u);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 16853))+24);
      opnd = (OOC_SSA__Opnd)i0;
      i2 = i0!=(OOC_INT32)0;
      if (!i2) goto l39;
l31_loop:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 16921))+24);
      i2 = i0!=i2;
      if (!i2) goto l34;
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 16951)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i2, 44u);
l34:
      OOC_SSA_Blocker__WriteBlocks_WriteOpnd((OOC_SSA__Opnd)i0);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17035))+8);
      opnd = (OOC_SSA__Opnd)i0;
      i2 = i0!=(OOC_INT32)0;
      if (i2) goto l31_loop;
l39:
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17068)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
l40:
      return;
      ;
    }

    
    void OOC_SSA_Blocker__WriteBlocks_WriteRegion(OOC_SSA_Blocker__Region r) {
      register OOC_INT32 i0,i1,i2,i3,i4;
      OOC_SSA__Opnd opnd;
      OOC_INT32 i;
      auto void OOC_SSA_Blocker__WriteBlocks_WriteRegion_WriteBody(OOC_SSA_Blocker__Proxy p);
      auto void OOC_SSA_Blocker__WriteBlocks_WriteRegion_WriteBranchHead(OOC_SSA__Opnd select, OOC_SSA__Opnd opnd);
        
        void OOC_SSA_Blocker__WriteBlocks_WriteRegion_WriteBody(OOC_SSA_Blocker__Proxy p) {
          register OOC_INT32 i0,i1;

          i0 = (OOC_INT32)p;
          i1 = i0!=(OOC_INT32)0;
          if (!i1) goto l12;
          
l3_loop:
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17294)))), &_td_OOC_SSA_Blocker__RegionDesc);
          if (i1) goto l6;
          OOC_SSA_Blocker__WriteBlocks_WriteInstr((OOC_SSA_Blocker__Proxy)i0);
          goto l7;
l6:
          OOC_SSA_Blocker__WriteBlocks_WriteRegion((OOC_SSA_Blocker__Region)i0);
l7:
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 17409));
          p = (OOC_SSA_Blocker__Proxy)i0;
          i1 = i0!=(OOC_INT32)0;
          if (i1) goto l3_loop;
l12:
          return;
          ;
        }

        
        void OOC_SSA_Blocker__WriteBlocks_WriteRegion_WriteBranchHead(OOC_SSA__Opnd select, OOC_SSA__Opnd opnd) {
          register OOC_INT32 i0;

          i0 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17534)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "IF ", 4);
          i0 = (OOC_INT32)select;
          OOC_SSA_Blocker__WriteBlocks_WriteOpnd((OOC_SSA__Opnd)i0);
          i0 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17594)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, " = ", 4);
          i0 = (OOC_INT32)opnd;
          OOC_SSA_Blocker__WriteBlocks_WriteOpnd((OOC_SSA__Opnd)i0);
          i0 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17652)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, " THEN", 6);
          return;
          ;
        }


      i0 = (OOC_INT32)r;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17731)))), &_td_OOC_SSA_Blocker__LoopDesc);
      if (i1) goto l16;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17918)))), &_td_OOC_SSA_Blocker__SelectDesc);
      if (i1) goto l5;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18454))+48);
      OOC_SSA_Blocker__WriteBlocks_WriteRegion_WriteBody((OOC_SSA_Blocker__Proxy)i0);
      goto l17;
l5:
      OOC_SSA_Blocker__WriteBlocks_WriteInstrPrefix((OOC_SSA_Blocker__Proxy)i0);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17961)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, "SELECT", 7);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17988)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i1);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18016))+8);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 18023))+24);
      opnd = (OOC_SSA__Opnd)i1;
      i = 0;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18076))+60);
      i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 18083)), 0);
      i2 = 0!=i2;
      if (!i2) goto l14;
      {register OOC_INT32 h0=i0;i0=i1;i1=h0;}i2=0;
l9_loop:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18112))+8);
      opnd = (OOC_SSA__Opnd)i0;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 18153))+60);
      i3 = _check_pointer(i3, 18160);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i2 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 18160))*4);
      OOC_SSA_Blocker__WriteBlocks_WriteInstrPrefix((OOC_SSA_Blocker__Proxy)i2);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 18194))+8);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 18201))+24);
      OOC_SSA_Blocker__WriteBlocks_WriteRegion_WriteBranchHead((OOC_SSA__Opnd)i1, (OOC_SSA__Opnd)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18231)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
      i0 = (OOC_INT32)r;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18264))+60);
      i0 = _check_pointer(i0, 18271);
      i1 = OOC_ARRAY_LENGTH(i0, 0);
      i2 = i;
      i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(i2, i1, OOC_UINT32, 18271))*4);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18274))+48);
      OOC_SSA_Blocker__WriteBlocks_WriteRegion_WriteBody((OOC_SSA_Blocker__Proxy)i0);
      i0 = (OOC_INT32)opnd;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18306))+8);
      i1 = i;
      opnd = (OOC_SSA__Opnd)i0;
      i1 = i1+1;
      i = i1;
      i2 = (OOC_INT32)r;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 18076))+60);
      i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 18083)), 0);
      i3 = i1!=i3;
      if (!i3) goto l13;
      {register OOC_INT32 h0=i1;i1=i2;i2=h0;}
      goto l9_loop;
l13:
      i0=i2;
l14:
      OOC_SSA_Blocker__WriteBlocks_WriteInstrPrefix((OOC_SSA_Blocker__Proxy)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18381)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "END SELECT", 11);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18412)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
      goto l17;
l16:
      OOC_SSA_Blocker__WriteBlocks_WriteInstrPrefix((OOC_SSA_Blocker__Proxy)i0);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17772)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, "LOOP", 5);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17797)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i1);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17828))+48);
      OOC_SSA_Blocker__WriteBlocks_WriteRegion_WriteBody((OOC_SSA_Blocker__Proxy)i0);
      i0 = (OOC_INT32)r;
      OOC_SSA_Blocker__WriteBlocks_WriteInstrPrefix((OOC_SSA_Blocker__Proxy)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17869)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "END LOOP", 9);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17898)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
l17:
      i0 = (OOC_INT32)r;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18486))+8);
      i1 = i1!=(OOC_INT32)0;
      if (!i1) goto l20;
      OOC_SSA_Blocker__WriteBlocks_WriteInstr((OOC_SSA_Blocker__Proxy)i0);
l20:
      return;
      ;
    }


  i0 = (OOC_INT32)ADT_Dictionary_IntValue__New();
  idMap = (ADT_Dictionary_IntValue__Dictionary)i0;
  instrCount = 1;
  i0 = (OOC_INT32)root;
  OOC_SSA_Blocker__WriteBlocks_AssignId((OOC_SSA_Blocker__Proxy)i0);
  i0 = (OOC_INT32)c;
  i0 = (OOC_INT32)IO_TextRider__ConnectWriter((IO__ByteChannel)i0);
  w = (IO_TextRider__Writer)i0;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18693)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18709)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "Procedure: ", 12);
  i1 = (OOC_INT32)pb;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 18762))+20);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 18772))+20);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 18778))+12);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 18762))+20);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 18772))+20);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 18778))+12);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 18783)), 0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18745)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (void*)(_check_pointer(i2, 18783)), i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18792)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
  i0 = (OOC_INT32)root;
  OOC_SSA_Blocker__WriteBlocks_WriteRegion((OOC_SSA_Blocker__Region)i0);
  return;
  ;
}

static OOC_CHAR8 OOC_SSA_Blocker__AntiDepViolation(OOC_SSA__ProcBlock pb, OOC_SSA_Blocker__Region root) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_SSA_Destore__State destore;
  OOC_INT32 violationCount;
  OOC_INT32 currentId;
  OOC_SSA__Instr get;
  OOC_SSA_Blocker__Proxy startOfScan;
  auto void OOC_SSA_Blocker__AntiDepViolation_ScanBackward(OOC_SSA_Blocker__Region region, OOC_SSA_Blocker__Proxy proxy, OOC_SSA__Opnd readDesign, OOC_SSA__Result storeInGet);
  auto void OOC_SSA_Blocker__AntiDepViolation_ScanForward(OOC_SSA_Blocker__Proxy proxy, OOC_SSA__Opnd readDesign);
    
    void OOC_SSA_Blocker__AntiDepViolation_ScanBackward(OOC_SSA_Blocker__Region region, OOC_SSA_Blocker__Proxy proxy, OOC_SSA__Opnd readDesign, OOC_SSA__Result storeInGet) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
      OOC_SSA__Result storeOut;
      OOC_INT32 i;
      OOC_SSA__Opnd opnd;
      OOC_SSA_Blocker__Proxy x;

      i0 = (OOC_INT32)proxy;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l3;
      i1=0u;
      goto l5;
l3:
      i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 19308)))), &_td_OOC_SSA_Blocker__RegionDesc));
      
l5:
      if (!i1) goto l32;
      i1 = (OOC_INT32)readDesign;
      i2 = (OOC_INT32)storeInGet;
      
l8_loop:
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19347))+8);
      i3 = (OOC_INT32)OOC_SSA__InstrDesc_GetResultStore((OOC_SSA__Instr)i3);
      storeOut = (OOC_SSA__Result)i3;
      i4 = *(OOC_INT32*)((_check_pointer(i0, 19391))+32);
      i5 = currentId;
      i4 = i4==i5;
      if (i4) goto l11;
      i4 = i3==i2;
      
      goto l13;
l11:
      i4=1u;
l13:
      if (i4) goto l22;
      i3 = i3!=(OOC_INT32)0;
      if (i3) goto l17;
      i3=0u;
      goto l19;
l17:
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19693))+8);
      i4 = (OOC_INT32)destore;
      i3 = OOC_SSA_Destore__StateDesc_ClobberedBy((OOC_SSA_Destore__State)i4, (OOC_SSA__Opnd)i1, (OOC_SSA__Instr)i3);
      
l19:
      if (!i3) goto l23;
      i3 = violationCount;
      violationCount = (i3+1);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19754))+8);
      i4 = (OOC_INT32)get;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i3, (OOC_SSA__Result)i4, 18);
      goto l23;
l22:
      return;
l23:
      i3 = currentId;
      *(OOC_INT32*)((_check_pointer(i0, 19952))+32) = i3;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19997))+4);
      proxy = (OOC_SSA_Blocker__Proxy)i0;
      i3 = i0!=(OOC_INT32)0;
      if (i3) goto l26;
      i3=0u;
      goto l28;
l26:
      i3 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 19308)))), &_td_OOC_SSA_Blocker__RegionDesc));
      
l28:
      if (i3) goto l8_loop;
l32:
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l41;
      i0 = (OOC_INT32)region;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21184))+12);
      i1 = i1!=(OOC_INT32)0;
      if (!i1) goto l81;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21225))+12);
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 21234)))), &_td_OOC_SSA_Blocker__SelectDesc);
      if (!i1) goto l39;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21278))+12);
      region = (OOC_SSA_Blocker__Region)i0;
l39:
      i0 = (OOC_INT32)region;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21333))+12);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21349))+4);
      i2 = (OOC_INT32)storeInGet;
      i3 = (OOC_INT32)readDesign;
      OOC_SSA_Blocker__AntiDepViolation_ScanBackward((OOC_SSA_Blocker__Region)i1, (OOC_SSA_Blocker__Proxy)i0, (OOC_SSA__Opnd)i3, (OOC_SSA__Result)i2);
      goto l81;
l41:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20269))+8);
      i1 = (OOC_INT32)OOC_SSA__InstrDesc_GetResultStore((OOC_SSA__Instr)i1);
      storeOut = (OOC_SSA__Result)i1;
      i2 = *(OOC_INT32*)((_check_pointer(i0, 20313))+32);
      i3 = currentId;
      i2 = i2==i3;
      if (i2) goto l44;
      i2 = (OOC_INT32)storeInGet;
      i1 = i1==i2;
      
      goto l46;
l44:
      i1=1u;
l46:
      if (i1) goto l79;
      *(OOC_INT32*)((_check_pointer(i0, 20413))+32) = i3;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20456)))), &_td_OOC_SSA_Blocker__SelectDesc);
      if (i1) goto l69;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20726)))), &_td_OOC_SSA_Blocker__LoopDesc);
      if (!i1) goto l81;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20761))+8);
      i0 = (OOC_INT32)OOC_SSA__InstrDesc_NthOpnd((OOC_SSA__Instr)i0, 2);
      opnd = (OOC_SSA__Opnd)i0;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l54;
      i1=0u;
      goto l56;
l54:
      i1 = *(OOC_INT8*)((_check_pointer(i0, 20821))+4);
      i1 = i1==11;
      
l56:
      if (!i1) goto l81;
      i1 = (OOC_INT32)storeInGet;
      i2 = (OOC_INT32)readDesign;
      
l58_loop:
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 20873));
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 20878))+8);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 20885))+16);
      i3 = _type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 20892)))), &_td_OOC_SSA_Blocker__ProxyDesc, 20892);
      x = (OOC_SSA_Blocker__Proxy)i3;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 20929))+12);
      OOC_SSA_Blocker__AntiDepViolation_ScanBackward((OOC_SSA_Blocker__Region)i4, (OOC_SSA_Blocker__Proxy)i3, (OOC_SSA__Opnd)i2, (OOC_SSA__Result)i1);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20993))+8);
      opnd = (OOC_SSA__Opnd)i0;
      i3 = i0!=(OOC_INT32)0;
      if (i3) goto l61;
      i3=0u;
      goto l63;
l61:
      i3 = *(OOC_INT8*)((_check_pointer(i0, 20821))+4);
      i3 = i3==11;
      
l63:
      if (i3) goto l58_loop;
      goto l81;
l69:
      i = 0;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20521))+60);
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 20528)), 0);
      i1 = 0!=i1;
      if (!i1) goto l81;
      i1 = (OOC_INT32)storeInGet;
      i2 = (OOC_INT32)readDesign;
      i3=0;
l72_loop:
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20568))+60);
      i4 = _check_pointer(i4, 20575);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20585))+60);
      i6 = _check_pointer(i6, 20592);
      i7 = OOC_ARRAY_LENGTH(i6, 0);
      i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i3, i7, OOC_UINT32, 20592))*4);
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 20595))+52);
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 20575))*4);
      OOC_SSA_Blocker__AntiDepViolation_ScanBackward((OOC_SSA_Blocker__Region)i4, (OOC_SSA_Blocker__Proxy)i6, (OOC_SSA__Opnd)i2, (OOC_SSA__Result)i1);
      i3 = i3+1;
      i = i3;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20521))+60);
      i4 = OOC_ARRAY_LENGTH((_check_pointer(i4, 20528)), 0);
      i4 = i3!=i4;
      if (i4) goto l72_loop;
      goto l81;
l79:
      return;
l81:
      return;
      ;
    }

    
    void OOC_SSA_Blocker__AntiDepViolation_ScanForward(OOC_SSA_Blocker__Proxy proxy, OOC_SSA__Opnd readDesign) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_SSA__Result storeOut;

      i0 = (OOC_INT32)proxy;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l3;
      i1=0u;
      goto l5;
l3:
      i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21792)))), &_td_OOC_SSA_Blocker__RegionDesc));
      
l5:
      if (!i1) goto l23;
      i1 = (OOC_INT32)readDesign;
      
l7_loop:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21831))+8);
      i2 = (OOC_INT32)OOC_SSA__InstrDesc_GetResultStore((OOC_SSA__Instr)i2);
      storeOut = (OOC_SSA__Result)i2;
      i2 = i2!=(OOC_INT32)0;
      if (i2) goto l10;
      i2=0u;
      goto l12;
l10:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21938))+8);
      i3 = (OOC_INT32)destore;
      i2 = OOC_SSA_Destore__StateDesc_ClobberedBy((OOC_SSA_Destore__State)i3, (OOC_SSA__Opnd)i1, (OOC_SSA__Instr)i2);
      
l12:
      if (!i2) goto l14;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21967))+8);
      i3 = (OOC_INT32)get;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i3, 18);
      return;
l14:
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 22622));
      proxy = (OOC_SSA_Blocker__Proxy)i0;
      i2 = i0!=(OOC_INT32)0;
      if (i2) goto l17;
      i2=0u;
      goto l19;
l17:
      i2 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21792)))), &_td_OOC_SSA_Blocker__RegionDesc));
      
l19:
      if (i2) goto l7_loop;
l23:
      return;
      ;
    }


  i0 = (OOC_INT32)pb;
  i1 = (OOC_INT32)OOC_SSA_Destore__New((OOC_SSA__ProcBlock)i0);
  destore = (OOC_SSA_Destore__State)i1;
  i1 = (OOC_INT32)root;
  OOC_SSA_Blocker__ClearMarkers((OOC_SSA_Blocker__Region)i1);
  violationCount = 0;
  currentId = 1;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22797))+12);
  get = (OOC_SSA__Instr)i0;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l15;
l3_loop:
  i1 = *(OOC_INT8*)((_check_pointer(i0, 22848))+36);
  i1 = i1==12;
  if (i1) goto l6;
  i1=0u;
  goto l8;
l6:
  i1 = (OOC_INT32)OOC_SSA__InstrDesc_GetResultStore((OOC_SSA__Instr)i0);
  i1 = i1==(OOC_INT32)0;
  
l8:
  if (!i1) goto l10;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23003))+16);
  i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 23010)))), &_td_OOC_SSA_Blocker__ProxyDesc, 23010);
  startOfScan = (OOC_SSA_Blocker__Proxy)i1;
  i2 = (OOC_INT32)OOC_SSA__InstrDesc_GetOpndClass((OOC_SSA__Instr)i0, 5);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23191))+24);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23051))+12);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23094))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 23201));
  OOC_SSA_Blocker__AntiDepViolation_ScanBackward((OOC_SSA_Blocker__Region)i3, (OOC_SSA_Blocker__Proxy)i1, (OOC_SSA__Opnd)i2, (OOC_SSA__Result)i0);
  i0 = (OOC_INT32)startOfScan;
  i1 = (OOC_INT32)get;
  i1 = (OOC_INT32)OOC_SSA__InstrDesc_GetOpndClass((OOC_SSA__Instr)i1, 5);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 23250));
  OOC_SSA_Blocker__AntiDepViolation_ScanForward((OOC_SSA_Blocker__Proxy)i0, (OOC_SSA__Opnd)i1);
  i0 = currentId;
  currentId = (i0+1);
l10:
  i0 = (OOC_INT32)get;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23383))+28);
  get = (OOC_SSA__Instr)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l3_loop;
l15:
  i0 = violationCount;
  return (i0!=0);
  ;
}

void OOC_SSA_Blocker__RemoveAntiDeps(OOC_SSA__ProcBlock pb) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_SSA__Instr instr;
  OOC_SSA__Opnd opnd;
  OOC_SSA__Opnd next;

  i0 = (OOC_INT32)pb;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23870))+12);
  instr = (OOC_SSA__Instr)i0;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l20;
l3_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23929))+24);
  opnd = (OOC_SSA__Opnd)i1;
  i2 = i1!=(OOC_INT32)0;
  if (!i2) goto l15;
l6_loop:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23989))+8);
  next = (OOC_SSA__Opnd)i2;
  i3 = *(OOC_INT8*)((_check_pointer(i1, 24018))+4);
  switch (i3) {
  case 18:
  case 20:
    OOC_SSA__OpndDesc_DeleteOpnd((OOC_SSA__Opnd)i1);
    goto l10;
  default:
    goto l10;
  }
l10:
  opnd = (OOC_SSA__Opnd)i2;
  i1 = i2!=(OOC_INT32)0;
  if (!i1) goto l15;
  i1=i2;
  goto l6_loop;
l15:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24229))+28);
  instr = (OOC_SSA__Instr)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l3_loop;
l20:
  return;
  ;
}

void OOC_SSA_Blocker__RemoveRegionDeps(OOC_SSA__ProcBlock pb) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_SSA__Instr instr;
  OOC_SSA__Opnd opnd;
  OOC_SSA__Opnd next;

  i0 = (OOC_INT32)pb;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24400))+12);
  instr = (OOC_SSA__Instr)i0;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l19;
l3_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24459))+24);
  opnd = (OOC_SSA__Opnd)i1;
  i2 = i1!=(OOC_INT32)0;
  if (!i2) goto l14;
l6_loop:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 24519))+8);
  next = (OOC_SSA__Opnd)i2;
  i3 = *(OOC_INT8*)((_check_pointer(i1, 24547))+4);
  i3 = i3==20;
  if (!i3) goto l9;
  OOC_SSA__OpndDesc_DeleteOpnd((OOC_SSA__Opnd)i1);
l9:
  opnd = (OOC_SSA__Opnd)i2;
  i1 = i2!=(OOC_INT32)0;
  if (!i1) goto l14;
  i1=i2;
  goto l6_loop;
l14:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24679))+28);
  instr = (OOC_SSA__Instr)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l3_loop;
l19:
  return;
  ;
}

OOC_SSA_Blocker__Region OOC_SSA_Blocker__ArrangeInstructions(OOC_SSA__ProcBlock pb, OOC_CHAR8 markAntiDeps) {
  register OOC_INT32 i0,i1,i2;
  OOC_SSA__Instr enter;
  OOC_SSA_Blocker__Loop mainLoop;
  OOC_SSA_Blocker__Region ready;
  OOC_SSA_Blocker__Region waiting;
  OOC_SSA__Instr instr;
  OOC_INT32 useCount;
  OOC_SSA__Result res;
  OOC_SSA__Opnd use;
  OOC_SSA_Blocker__Proxy p;
  OOC_SSA_Blocker__Region root;
  OOC_SSA_Blocker__Region region;
  auto void OOC_SSA_Blocker__ArrangeInstructions_DiscoverLoopStructure(OOC_SSA_Blocker__Loop loop, OOC_SSA__Result storeIn, OOC_SSA__Instr endOfSearch, OOC_SSA_Blocker__Loop preceedingLoop);
  auto void OOC_SSA_Blocker__ArrangeInstructions_SortNestedLoops(OOC_SSA_Blocker__Loop loop);
  auto void OOC_SSA_Blocker__ArrangeInstructions_AttachToLoop(OOC_SSA_Blocker__Loop loop);
  auto void OOC_SSA_Blocker__ArrangeInstructions_AddRegionDeps(OOC_SSA_Blocker__Region r);
  auto OOC_CHAR8 OOC_SSA_Blocker__ArrangeInstructions_IgnoredUse(OOC_SSA__Opnd use);
  auto void OOC_SSA_Blocker__ArrangeInstructions_UpdateDefs(OOC_SSA_Blocker__Proxy p);
  auto OOC_SSA_Blocker__Region OOC_SSA_Blocker__ArrangeInstructions_GetRegion(OOC_SSA_Blocker__Proxy p);
  auto void OOC_SSA_Blocker__ArrangeInstructions_SortRegion(OOC_SSA_Blocker__Region r);
  auto void OOC_SSA_Blocker__ArrangeInstructions_ClearRegion(OOC_SSA_Blocker__Region r);
    
    void OOC_SSA_Blocker__ArrangeInstructions_DiscoverLoopStructure(OOC_SSA_Blocker__Loop loop, OOC_SSA__Result storeIn, OOC_SSA__Instr endOfSearch, OOC_SSA_Blocker__Loop preceedingLoop) {
      register OOC_INT32 i0,i1,i2,i3,i4;
      OOC_SSA__Opnd use;
      OOC_SSA__Instr instr;
      OOC_SSA__Instr loopEnd;
      OOC_SSA_Blocker__Loop loopProxy;
      OOC_SSA_Blocker__Proxy dummy;
      auto void OOC_SSA_Blocker__ArrangeInstructions_DiscoverLoopStructure_RegisterPreceeding(OOC_SSA_Blocker__Loop preceeding, OOC_SSA_Blocker__Loop following);
        
        void OOC_SSA_Blocker__ArrangeInstructions_DiscoverLoopStructure_RegisterPreceeding(OOC_SSA_Blocker__Loop preceeding, OOC_SSA_Blocker__Loop following) {
          register OOC_INT32 i0,i1,i2;
          OOC_SSA_Blocker__Preceeds pre;

          i0 = (OOC_INT32)preceeding;
          i1 = i0!=(OOC_INT32)0;
          if (!i1) goto l4;
          i1 = (OOC_INT32)RT0__NewObject(_td_OOC_SSA_Blocker__Preceeds.baseTypes[0]);
          pre = (OOC_SSA_Blocker__Preceeds)i1;
          *(OOC_INT32*)((_check_pointer(i1, 26822))+4) = i0;
          i0 = (OOC_INT32)following;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26894))+72);
          *(OOC_INT32*)(_check_pointer(i1, 26867)) = i2;
          *(OOC_INT32*)((_check_pointer(i0, 26931))+72) = i1;
l4:
          return;
          ;
        }


      i0 = (OOC_INT32)storeIn;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l24;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27066))+12);
      use = (OOC_SSA__Opnd)i0;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l24;
l5_loop:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27128))+12);
      instr = (OOC_SSA__Instr)i0;
      i1 = (OOC_INT32)endOfSearch;
      i2 = i0!=i1;
      if (!i2) goto l18;
      i2 = *(OOC_INT8*)((_check_pointer(i0, 27198))+36);
      i2 = i2==10;
      if (i2) goto l13;
      i2 = (OOC_INT32)OOC_SSA_Blocker__GetProxy((OOC_SSA__Instr)i0);
      p = (OOC_SSA_Blocker__Proxy)i2;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 28413))+28);
      i4 = (OOC_INT32)loop;
      i3 = i3!=i4;
      if (!i3) goto l18;
      *(OOC_INT32*)((_check_pointer(i2, 28463))+28) = i4;
      i0 = (OOC_INT32)OOC_SSA__InstrDesc_GetResultStore((OOC_SSA__Instr)i0);
      i2 = (OOC_INT32)preceedingLoop;
      OOC_SSA_Blocker__ArrangeInstructions_DiscoverLoopStructure((OOC_SSA_Blocker__Loop)i4, (OOC_SSA__Result)i0, (OOC_SSA__Instr)i1, (OOC_SSA_Blocker__Loop)i2);
      goto l18;
l13:
      i0 = (OOC_INT32)OOC_SSA__InstrDesc_GetLoopEnd((OOC_SSA__Instr)i0);
      loopEnd = (OOC_SSA__Instr)i0;
      i0 = (OOC_INT32)OOC_SSA_Blocker__GetProxy((OOC_SSA__Instr)i0);
      p = (OOC_SSA_Blocker__Proxy)i0;
      i0 = _type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 27607)))), &_td_OOC_SSA_Blocker__LoopDesc, 27607);
      loopProxy = (OOC_SSA_Blocker__Loop)i0;
      i1 = (OOC_INT32)preceedingLoop;
      OOC_SSA_Blocker__ArrangeInstructions_DiscoverLoopStructure_RegisterPreceeding((OOC_SSA_Blocker__Loop)i1, (OOC_SSA_Blocker__Loop)i0);
      i0 = (OOC_INT32)instr;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27714))+16);
      i1 = i1==(OOC_INT32)0;
      if (!i1) goto l18;
      i1 = (OOC_INT32)OOC_SSA_Blocker__GetProxy((OOC_SSA__Instr)i0);
      dummy = (OOC_SSA_Blocker__Proxy)i1;
      i1 = (OOC_INT32)loopProxy;
      i2 = (OOC_INT32)loop;
      OOC_SSA_Blocker__LoopDesc_AppendLoop((OOC_SSA_Blocker__Loop)i2, (OOC_SSA_Blocker__Loop)i1);
      i0 = (OOC_INT32)OOC_SSA__InstrDesc_GetResultStore((OOC_SSA__Instr)i0);
      i3 = (OOC_INT32)loopEnd;
      OOC_SSA_Blocker__ArrangeInstructions_DiscoverLoopStructure((OOC_SSA_Blocker__Loop)i1, (OOC_SSA__Result)i0, (OOC_SSA__Instr)i3, (OOC_SSA_Blocker__Loop)(OOC_INT32)0);
      i0 = (OOC_INT32)OOC_SSA__InstrDesc_GetResultStore((OOC_SSA__Instr)i3);
      i3 = (OOC_INT32)endOfSearch;
      OOC_SSA_Blocker__ArrangeInstructions_DiscoverLoopStructure((OOC_SSA_Blocker__Loop)i2, (OOC_SSA__Result)i0, (OOC_SSA__Instr)i3, (OOC_SSA_Blocker__Loop)i1);
l18:
      i0 = (OOC_INT32)use;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28741))+16);
      use = (OOC_SSA__Opnd)i0;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l5_loop;
l24:
      return;
      ;
    }

    
    void OOC_SSA_Blocker__ArrangeInstructions_SortNestedLoops(OOC_SSA_Blocker__Loop loop) {
      register OOC_INT32 i0,i1;
      OOC_SSA_Blocker__Loop oldNested;
      OOC_SSA_Blocker__Loop nested;
      auto OOC_SSA_Blocker__Loop OOC_SSA_Blocker__ArrangeInstructions_SortNestedLoops_GetNext(OOC_SSA_Blocker__Loop *list);
        
        OOC_SSA_Blocker__Loop OOC_SSA_Blocker__ArrangeInstructions_SortNestedLoops_GetNext(OOC_SSA_Blocker__Loop *list) {
          register OOC_INT32 i0,i1,i2;
          OOC_SSA_Blocker__Preceeds ptr;
          OOC_SSA_Blocker__Loop best;

          i0 = (OOC_INT32)*list;
          _assert((i0!=(OOC_INT32)0), 127, 29224);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29308))+72);
          ptr = (OOC_SSA_Blocker__Preceeds)i1;
          i2 = i1!=(OOC_INT32)0;
          if (i2) goto l3;
          i2=0u;
          goto l5;
l3:
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 29357))+4);
          i2 = *(OOC_UINT8*)((_check_pointer(i2, 29373))+76);
          
l5:
          if (!i2) goto l17;
l8_loop:
          i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 29408));
          ptr = (OOC_SSA_Blocker__Preceeds)i1;
          i2 = i1!=(OOC_INT32)0;
          if (i2) goto l11;
          i2=0u;
          goto l13;
l11:
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 29357))+4);
          i2 = *(OOC_UINT8*)((_check_pointer(i2, 29373))+76);
          
l13:
          if (i2) goto l8_loop;
l17:
          i1 = i1==(OOC_INT32)0;
          if (i1) goto l20;
          i0 = (OOC_INT32)OOC_SSA_Blocker__ArrangeInstructions_SortNestedLoops_GetNext((void*)((_check_pointer(i0, 29624))+64));
          return (OOC_SSA_Blocker__Loop)i0;
          goto l21;
l20:
          best = (OOC_SSA_Blocker__Loop)i0;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29511))+64);
          *list = (OOC_SSA_Blocker__Loop)i1;
          *(OOC_UINT8*)((_check_pointer(i0, 29537))+76) = 1u;
          return (OOC_SSA_Blocker__Loop)i0;
l21:
          _failed_function(29119); return 0;
          ;
        }


      i0 = (OOC_INT32)loop;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29707))+60);
      oldNested = (OOC_SSA_Blocker__Loop)i1;
      *(OOC_INT32*)((_check_pointer(i0, 29732))+60) = (OOC_INT32)0;
      i0 = i1!=(OOC_INT32)0;
      if (!i0) goto l8;
l3_loop:
      i0 = (OOC_INT32)OOC_SSA_Blocker__ArrangeInstructions_SortNestedLoops_GetNext((void*)(OOC_INT32)&oldNested);
      nested = (OOC_SSA_Blocker__Loop)i0;
      i1 = (OOC_INT32)loop;
      OOC_SSA_Blocker__LoopDesc_AppendLoop((OOC_SSA_Blocker__Loop)i1, (OOC_SSA_Blocker__Loop)i0);
      i0 = (OOC_INT32)oldNested;
      i0 = i0!=(OOC_INT32)0;
      if (i0) goto l3_loop;
l8:
      return;
      ;
    }

    
    void OOC_SSA_Blocker__ArrangeInstructions_AttachToLoop(OOC_SSA_Blocker__Loop loop) {
      register OOC_INT32 i0,i1;
      auto OOC_CHAR8 OOC_SSA_Blocker__ArrangeInstructions_AttachToLoop_PartOfLoop(OOC_SSA_Blocker__Loop loop, OOC_SSA__Instr instr);
        
        OOC_CHAR8 OOC_SSA_Blocker__ArrangeInstructions_AttachToLoop_PartOfLoop(OOC_SSA_Blocker__Loop loop, OOC_SSA__Instr instr) {
          register OOC_INT32 i0,i1,i2,i3,i4,i5;
          OOC_SSA_Blocker__Proxy instrProxy;
          OOC_INT32 inLoopUse;
          OOC_SSA__Result res;
          OOC_SSA__Opnd use;
          OOC_SSA_Blocker__Proxy useProxy;

          i0 = (OOC_INT32)instr;
          i1 = (OOC_INT32)OOC_SSA_Blocker__GetProxy((OOC_SSA__Instr)i0);
          instrProxy = (OOC_SSA_Blocker__Proxy)i1;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 31588))+20);
          i3 = (OOC_INT32)loop;
          i2 = i2==i3;
          if (i2) goto l44;
          inLoopUse = 0;
          res = (OOC_SSA__Result)i0;
          i2 = i0!=(OOC_INT32)0;
          if (i2) goto l5;
          i0=0;
          goto l36;
l5:
          i2=0;
l6_loop:
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31851))+12);
          use = (OOC_SSA__Opnd)i4;
          i5 = i4!=(OOC_INT32)0;
          if (!i5) goto l31;
          {register OOC_INT32 h0=i2;i2=i4;i4=h0;}
l10_loop:
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 31933))+12);
          i5 = (OOC_INT32)OOC_SSA_Blocker__GetProxy((OOC_SSA__Instr)i5);
          useProxy = (OOC_SSA_Blocker__Proxy)i5;
          i5 = i5==i3;
          if (i5) goto l13;
          i5=0u;
          goto l19;
l13:
          i5 = *(OOC_INT8*)((_check_pointer(i2, 32002))+4);
          i5 = i5==13;
          if (i5) goto l16;
          i5 = OOC_SSA__OpndDesc_OpndIndex((OOC_SSA__Opnd)i2);
          i5 = i5==2;
          
          goto l19;
l16:
          i5=1u;
l19:
          if (i5) goto l21;
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 32116))+12);
          i5 = OOC_SSA_Blocker__ArrangeInstructions_AttachToLoop_PartOfLoop((OOC_SSA_Blocker__Loop)i3, (OOC_SSA__Instr)i5);
          
          goto l23;
l21:
          i5=1u;
l23:
          if (!i5) goto l26;
          i4 = i4+1;
          inLoopUse = i4;
          
l26:
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 32206))+16);
          use = (OOC_SSA__Opnd)i2;
          i5 = i2!=(OOC_INT32)0;
          if (i5) goto l10_loop;
l30:
          i2=i4;
l31:
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 32256));
          res = (OOC_SSA__Result)i0;
          i4 = i0!=(OOC_INT32)0;
          if (i4) goto l6_loop;
l35:
          i0=i2;
l36:
          *(OOC_INT32*)((_check_pointer(i1, 32306))+20) = i3;
          *(OOC_UINT8*)((_check_pointer(i1, 32352))+24) = (i0!=0);
          i0 = *(OOC_UINT8*)((_check_pointer(i1, 32411))+24);
          if (i0) goto l39;
          i0=0u;
          goto l41;
l39:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 32440))+16);
          i0 = i0==(OOC_INT32)0;
          
l41:
          if (!i0) goto l43;
          *(OOC_INT32*)((_check_pointer(i1, 32627))+16) = i3;
l43:
          i0 = *(OOC_UINT8*)((_check_pointer(i1, 32690))+24);
          return i0;
          goto l45;
l44:
          i0 = *(OOC_UINT8*)((_check_pointer(i1, 31718))+24);
          return i0;
l45:
          _failed_function(30568); return 0;
          ;
        }


      i0 = (OOC_INT32)loop;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l6;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32810))+64);
      OOC_SSA_Blocker__ArrangeInstructions_AttachToLoop((OOC_SSA_Blocker__Loop)i1);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32849))+60);
      OOC_SSA_Blocker__ArrangeInstructions_AttachToLoop((OOC_SSA_Blocker__Loop)i1);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32881))+8);
      i1 = i1!=(OOC_INT32)0;
      if (!i1) goto l6;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32942))+8);
      i1 = (OOC_INT32)OOC_SSA__InstrDesc_GetLoopStart((OOC_SSA__Instr)i1);
      i0 = OOC_SSA_Blocker__ArrangeInstructions_AttachToLoop_PartOfLoop((OOC_SSA_Blocker__Loop)i0, (OOC_SSA__Instr)i1);
l6:
      return;
      ;
    }

    
    void OOC_SSA_Blocker__ArrangeInstructions_AddRegionDeps(OOC_SSA_Blocker__Region r) {
      register OOC_INT32 i0,i1;
      OOC_SSA_Blocker__Proxy proxy;
      OOC_SSA__Opnd opnd;
      auto void OOC_SSA_Blocker__ArrangeInstructions_AddRegionDeps_AddOpndDep(OOC_SSA_Blocker__Proxy proxy, OOC_SSA__Opnd opnd);
        
        void OOC_SSA_Blocker__ArrangeInstructions_AddRegionDeps_AddOpndDep(OOC_SSA_Blocker__Proxy proxy, OOC_SSA__Opnd opnd) {
          register OOC_INT32 i0,i1,i2,i3,i4,i5;
          OOC_SSA_Blocker__Proxy argProxy;
          OOC_SSA_Blocker__Proxy a;
          OOC_SSA_Blocker__Proxy b;
          OOC_SSA_Blocker__Loop argLoop;
          OOC_SSA__Opnd exit;
          OOC_SSA__Instr exitInstr;

          i0 = (OOC_INT32)opnd;
          i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 33316));
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 33321))+8);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 33328))+16);
          i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 33335)))), &_td_OOC_SSA_Blocker__ProxyDesc, 33335);
          argProxy = (OOC_SSA_Blocker__Proxy)i1;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 33363))+12);
          i3 = (OOC_INT32)r;
          i2 = i2!=i3;
          if (!i2) goto l30;
          a = (OOC_SSA_Blocker__Proxy)i1;
          i2 = (OOC_INT32)proxy;
          b = (OOC_SSA_Blocker__Proxy)i2;
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 33447))+12);
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 33473))+12);
          i3 = *(OOC_INT32*)((_check_pointer(i3, 33455))+56);
          i4 = *(OOC_INT32*)((_check_pointer(i4, 33481))+56);
          i3 = i3>i4;
          if (i3) goto l5;
          i3=i1;
          goto l11;
l5:
          i3=i1;
l6_loop:
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 33518))+12);
          a = (OOC_SSA_Blocker__Proxy)i3;
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 33447))+12);
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 33473))+12);
          i4 = *(OOC_INT32*)((_check_pointer(i4, 33455))+56);
          i5 = *(OOC_INT32*)((_check_pointer(i5, 33481))+56);
          i4 = i4>i5;
          if (i4) goto l6_loop;
l11:
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 33561))+12);
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 33587))+12);
          i4 = *(OOC_INT32*)((_check_pointer(i4, 33569))+56);
          i5 = *(OOC_INT32*)((_check_pointer(i5, 33595))+56);
          i4 = i4>i5;
          if (!i4) goto l20;
l15_loop:
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 33632))+12);
          b = (OOC_SSA_Blocker__Proxy)i2;
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 33561))+12);
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 33587))+12);
          i4 = *(OOC_INT32*)((_check_pointer(i4, 33569))+56);
          i5 = *(OOC_INT32*)((_check_pointer(i5, 33595))+56);
          i4 = i4>i5;
          if (i4) goto l15_loop;
l20:
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 33675))+12);
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 33687))+12);
          i4 = i4!=i5;
          if (!i4) goto l29;
          {register OOC_INT32 h0=i2;i2=i3;i3=h0;}
l24_loop:
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 33718))+12);
          a = (OOC_SSA_Blocker__Proxy)i2;
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 33746))+12);
          b = (OOC_SSA_Blocker__Proxy)i3;
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 33675))+12);
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 33687))+12);
          i4 = i4!=i5;
          if (i4) goto l24_loop;
l28:
          {register OOC_INT32 h0=i2;i2=i3;i3=h0;}
l29:
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 33782))+8);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 33807))+8);
          OOC_SSA__InstrDesc_AddUniqueOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i3, 20);
l30:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34023))+16);
          argLoop = (OOC_SSA_Blocker__Loop)i1;
          i2 = i1!=0;
          if (i2) goto l33;
          i2=0u;
          goto l35;
l33:
          i2 = (OOC_INT32)proxy;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 34091))+12);
          i2 = OOC_SSA_Blocker__Dominates((OOC_SSA_Blocker__Region)i1, (OOC_SSA_Blocker__Region)i2);
          i2 = !i2;
          
l35:
          if (!i2) goto l53;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34131))+8);
          i2 = *(OOC_INT8*)((_check_pointer(i2, 34138))+36);
          _assert((i2==11), 127, 34116);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34191))+8);
          i1 = (OOC_INT32)OOC_SSA__InstrDesc_NthOpnd((OOC_SSA__Instr)i1, 2);
          exit = (OOC_SSA__Opnd)i1;
          i2 = i1!=0;
          if (i2) goto l39;
          i2=0u;
          goto l41;
l39:
          i2 = *(OOC_INT8*)((_check_pointer(i1, 34249))+4);
          i2 = i2==11;
          
l41:
          if (!i2) goto l53;
l43_loop:
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 34307));
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 34312))+8);
          exitInstr = (OOC_SSA__Instr)i2;
          i3 = *(OOC_INT8*)((_check_pointer(i2, 34350))+36);
          _assert((i3==9), 127, 34333);
          i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 34411));
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 34416))+8);
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i3, 18);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 34480))+16);
          i2 = (OOC_INT32)OOC_SSA__InstrDesc_LastOpnd((OOC_SSA__Instr)i2);
          OOC_SSA_Blocker__ArrangeInstructions_AddRegionDeps_AddOpndDep((OOC_SSA_Blocker__Proxy)(_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 34487)))), &_td_OOC_SSA_Blocker__ProxyDesc, 34487)), (OOC_SSA__Opnd)i2);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34543))+8);
          exit = (OOC_SSA__Opnd)i1;
          i2 = i1!=0;
          if (i2) goto l46;
          i2=0u;
          goto l48;
l46:
          i2 = *(OOC_INT8*)((_check_pointer(i1, 34249))+4);
          i2 = i2==11;
          
l48:
          if (i2) goto l43_loop;
l53:
          return;
          ;
        }


      i0 = (OOC_INT32)r;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34636))+48);
      proxy = (OOC_SSA_Blocker__Proxy)i0;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l36;
l3_loop:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34691))+8);
      i1 = i1!=(OOC_INT32)0;
      if (!i1) goto l28;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34731))+8);
      i1 = *(OOC_INT8*)((_check_pointer(i1, 34738))+36);
      switch (i1) {
      case 5:
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34813))+8);
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34820))+24);
        OOC_SSA_Blocker__ArrangeInstructions_AddRegionDeps_AddOpndDep((OOC_SSA_Blocker__Proxy)i0, (OOC_SSA__Opnd)i1);
        goto l28;
      case 8:
        goto l28;
      case 11:
        goto l28;
      default:
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34986))+8);
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34993))+24);
        opnd = (OOC_SSA__Opnd)i0;
        i1 = i0!=(OOC_INT32)0;
        if (i1) goto l13;
        i1=0u;
        goto l15;
l13:
        i1 = *(OOC_INT8*)((_check_pointer(i0, 35043))+4);
        i1 = i1!=20;
        
l15:
        if (!i1) goto l28;
l17_loop:
        i1 = (OOC_INT32)proxy;
        OOC_SSA_Blocker__ArrangeInstructions_AddRegionDeps_AddOpndDep((OOC_SSA_Blocker__Proxy)i1, (OOC_SSA__Opnd)i0);
        i0 = (OOC_INT32)opnd;
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35145))+8);
        opnd = (OOC_SSA__Opnd)i0;
        i1 = i0!=(OOC_INT32)0;
        if (i1) goto l20;
        i1=0u;
        goto l22;
l20:
        i1 = *(OOC_INT8*)((_check_pointer(i0, 35043))+4);
        i1 = i1!=20;
        
l22:
        if (i1) goto l17_loop;
        goto l28;
      }
l28:
      i0 = (OOC_INT32)proxy;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 35221)))), &_td_OOC_SSA_Blocker__RegionDesc);
      if (!i1) goto l31;
      OOC_SSA_Blocker__ArrangeInstructions_AddRegionDeps((OOC_SSA_Blocker__Region)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 35268)))), &_td_OOC_SSA_Blocker__RegionDesc, 35268)));
l31:
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 35313));
      proxy = (OOC_SSA_Blocker__Proxy)i0;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l3_loop;
l36:
      return;
      ;
    }

    
    OOC_CHAR8 OOC_SSA_Blocker__ArrangeInstructions_IgnoredUse(OOC_SSA__Opnd use) {
      register OOC_INT32 i0,i1,i2;
      OOC_INT8 opcode;

      i0 = (OOC_INT32)use;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35708))+12);
      i1 = *(OOC_INT8*)((_check_pointer(i1, 35714))+36);
      opcode = i1;
      i2 = i1==8;
      if (i2) goto l7;
      i2 = i1==11;
      if (i2) goto l5;
      i2=0u;
      goto l9;
l5:
      i2 = *(OOC_INT8*)((_check_pointer(i0, 35822))+4);
      i2 = i2==11;
      
      goto l9;
l7:
      i2=1u;
l9:
      if (i2) goto l15;
      i1 = i1==86;
      if (i1) goto l13;
      i0=0u;
      goto l16;
l13:
      i0 = OOC_SSA__OpndDesc_OpndIndex((OOC_SSA__Opnd)i0);
      i0 = i0==2;
      
      goto l16;
l15:
      i0=1u;
l16:
      return i0;
      ;
    }

    
    void OOC_SSA_Blocker__ArrangeInstructions_UpdateDefs(OOC_SSA_Blocker__Proxy p) {
      register OOC_INT32 i0,i1,i2;
      OOC_SSA__Opnd opnd;
      OOC_SSA__Instr defInstr;
      OOC_SSA_Blocker__Proxy pDef;

      i0 = (OOC_INT32)p;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36069))+8);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36076))+24);
      opnd = (OOC_SSA__Opnd)i0;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l14;
l3_loop:
      i1 = OOC_SSA_Blocker__ArrangeInstructions_IgnoredUse((OOC_SSA__Opnd)i0);
      i1 = !i1;
      if (!i1) goto l9;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 36177));
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 36182))+8);
      defInstr = (OOC_SSA__Instr)i1;
      i2 = *(OOC_INT32*)((_check_pointer(i1, 36214))+20);
      *(OOC_INT32*)((_check_pointer(i1, 36214))+20) = (i2-1);
      i2 = *(OOC_INT32*)((_check_pointer(i1, 36247))+20);
      i2 = i2==0;
      if (!i2) goto l9;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 36294))+16);
      i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 36301)))), &_td_OOC_SSA_Blocker__ProxyDesc, 36301);
      pDef = (OOC_SSA_Blocker__Proxy)i1;
      i2 = (OOC_INT32)waiting;
      OOC_SSA_Blocker__RegionDesc_Remove((OOC_SSA_Blocker__Region)i2, (OOC_SSA_Blocker__Proxy)i1);
      i2 = (OOC_INT32)ready;
      OOC_SSA_Blocker__RegionDesc_Append((OOC_SSA_Blocker__Region)i2, (OOC_SSA_Blocker__Proxy)i1);
l9:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36427))+8);
      opnd = (OOC_SSA__Opnd)i0;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l3_loop;
l14:
      return;
      ;
    }

    
    OOC_SSA_Blocker__Region OOC_SSA_Blocker__ArrangeInstructions_GetRegion(OOC_SSA_Blocker__Proxy p) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_SSA__Instr loopEnd;
      OOC_SSA_Blocker__Region region;
      OOC_SSA__Result res;
      OOC_SSA__Opnd use;
      OOC_SSA_Blocker__Region useRegion;
      auto OOC_SSA_Blocker__Region OOC_SSA_Blocker__ArrangeInstructions_GetRegion_Merge(OOC_SSA_Blocker__Region a, OOC_SSA_Blocker__Region b);
      auto OOC_SSA_Blocker__Region OOC_SSA_Blocker__ArrangeInstructions_GetRegion_RegionOfUse(OOC_SSA__Opnd opnd);
      auto OOC_SSA_Blocker__Region OOC_SSA_Blocker__ArrangeInstructions_GetRegion_CorrectForLoop(OOC_SSA_Blocker__Region region);
      auto OOC_SSA_Blocker__Region OOC_SSA_Blocker__ArrangeInstructions_GetRegion_MoveLoopInvariants(OOC_SSA_Blocker__Region region);
        
        OOC_SSA_Blocker__Region OOC_SSA_Blocker__ArrangeInstructions_GetRegion_Merge(OOC_SSA_Blocker__Region a, OOC_SSA_Blocker__Region b) {
          register OOC_INT32 i0,i1,i2,i3;

          i0 = (OOC_INT32)a;
          i1 = (OOC_INT32)b;
          i2 = *(OOC_INT32*)((_check_pointer(i0, 37233))+56);
          i3 = *(OOC_INT32*)((_check_pointer(i1, 37251))+56);
          i2 = i2>i3;
          if (!i2) goto l9;
l4_loop:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 37286))+12);
          a = (OOC_SSA_Blocker__Region)i0;
          i2 = *(OOC_INT32*)((_check_pointer(i0, 37233))+56);
          i3 = *(OOC_INT32*)((_check_pointer(i1, 37251))+56);
          i2 = i2>i3;
          if (i2) goto l4_loop;
l9:
          i2 = *(OOC_INT32*)((_check_pointer(i1, 37325))+56);
          i3 = *(OOC_INT32*)((_check_pointer(i0, 37343))+56);
          i2 = i2>i3;
          if (!i2) goto l18;
l13_loop:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 37378))+12);
          b = (OOC_SSA_Blocker__Region)i1;
          i2 = *(OOC_INT32*)((_check_pointer(i1, 37325))+56);
          i3 = *(OOC_INT32*)((_check_pointer(i0, 37343))+56);
          i2 = i2>i3;
          if (i2) goto l13_loop;
l18:
          i2 = i0!=i1;
          if (!i2) goto l27;
l22_loop:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 37442))+12);
          a = (OOC_SSA_Blocker__Region)i0;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 37468))+12);
          b = (OOC_SSA_Blocker__Region)i1;
          i2 = i0!=i1;
          if (i2) goto l22_loop;
l27:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 37504))+8);
          i1 = i1!=(OOC_INT32)0;
          if (i1) goto l30;
          i1=0u;
          goto l32;
l30:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 37523))+8);
          i1 = *(OOC_INT8*)((_check_pointer(i1, 37530))+36);
          i1 = i1==5;
          
l32:
          if (!i1) goto l35;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 37577))+12);
          
l35:
          return (OOC_SSA_Blocker__Region)i0;
          ;
        }

        
        OOC_SSA_Blocker__Region OOC_SSA_Blocker__ArrangeInstructions_GetRegion_RegionOfUse(OOC_SSA__Opnd opnd) {
          register OOC_INT32 i0,i1,i2,i3,i4;
          OOC_SSA__Instr instr;
          OOC_INT32 i;
          OOC_INT32 pathNum;
          OOC_SSA_Blocker__Select selectProxy;

          i0 = (OOC_INT32)opnd;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 37815))+12);
          instr = (OOC_SSA__Instr)i1;
          i2 = *(OOC_INT8*)((_check_pointer(i1, 37841))+36);
          i2 = i2==5;
          if (i2) goto l7;
          i0 = *(OOC_INT8*)((_check_pointer(i1, 38387))+36);
          i0 = i0==11;
          if (i0) goto l5;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 38490))+16);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 38497)))), &_td_OOC_SSA_Blocker__ProxyDesc, 38497)), 38503))+12);
          return (OOC_SSA_Blocker__Region)i0;
          goto l19;
l5:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 38441))+16);
          return (OOC_SSA_Blocker__Region)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 38448)))), &_td_OOC_SSA_Blocker__LoopDesc, 38448));
          goto l19;
l7:
          i2 = OOC_SSA__OpndDesc_OpndIndex((OOC_SSA__Opnd)i0);
          i = i2;
          i3 = i2==0;
          if (i3) goto l10;
          i0 = OOC_SSA__OpndDesc_IsScheduleOpnd((OOC_SSA__Opnd)i0);
          
          goto l12;
l10:
          i0=1u;
l12:
          if (i0) goto l17;
          i0 = (i2-1)>>1;
          pathNum = i0;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 38088))+16);
          i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 38095)))), &_td_OOC_SSA_Blocker__SelectDesc, 38095);
          selectProxy = (OOC_SSA_Blocker__Select)i1;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 38131))+60);
          i2 = _check_pointer(i2, 38138);
          i3 = OOC_ARRAY_LENGTH(i2, 0);
          i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i0, i3, OOC_UINT32, 38138))*4);
          i2 = i2==(OOC_INT32)0;
          if (!i2) goto l16;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 38185))+60);
          i2 = _check_pointer(i2, 38192);
          i3 = OOC_ARRAY_LENGTH(i2, 0);
          i4 = (OOC_INT32)OOC_SSA_Blocker__NewRegion((OOC_SSA__Instr)(OOC_INT32)0);
          *(OOC_INT32*)(i2+(_check_index(i0, i3, OOC_UINT32, 38192))*4) = i4;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 38268))+60);
          i2 = _check_pointer(i2, 38275);
          i3 = OOC_ARRAY_LENGTH(i2, 0);
          i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i0, i3, OOC_UINT32, 38275))*4);
          OOC_SSA_Blocker__RegionDesc_Append((OOC_SSA_Blocker__Region)i1, (OOC_SSA_Blocker__Proxy)i2);
l16:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 38334))+60);
          i1 = _check_pointer(i1, 38341);
          i2 = OOC_ARRAY_LENGTH(i1, 0);
          i0 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(i0, i2, OOC_UINT32, 38341))*4);
          return (OOC_SSA_Blocker__Region)i0;
          goto l19;
l17:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 37982))+16);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37989)))), &_td_OOC_SSA_Blocker__ProxyDesc, 37989)), 37995))+12);
          return (OOC_SSA_Blocker__Region)i0;
l19:
          _failed_function(37650); return 0;
          ;
        }

        
        OOC_SSA_Blocker__Region OOC_SSA_Blocker__ArrangeInstructions_GetRegion_CorrectForLoop(OOC_SSA_Blocker__Region region) {
          register OOC_INT32 i0,i1,i2;
          OOC_SSA_Blocker__Loop loopProxy;
          OOC_SSA_Blocker__Proxy ptr;

          i0 = (OOC_INT32)p;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 38694))+16);
          loopProxy = (OOC_SSA_Blocker__Loop)i0;
          i1 = (OOC_INT32)region;
          i2 = i0!=(OOC_INT32)0;
          if (!i2) goto l11;
l3_loop:
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 38768))+12);
          ptr = (OOC_SSA_Blocker__Proxy)i2;
          i2 = i2==i1;
          if (!i2) goto l6;
          return (OOC_SSA_Blocker__Region)i0;
l6:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 38888))+68);
          loopProxy = (OOC_SSA_Blocker__Loop)i0;
          i2 = i0!=(OOC_INT32)0;
          if (i2) goto l3_loop;
l11:
          return (OOC_SSA_Blocker__Region)i1;
          ;
        }

        
        OOC_SSA_Blocker__Region OOC_SSA_Blocker__ArrangeInstructions_GetRegion_MoveLoopInvariants(OOC_SSA_Blocker__Region region) {
          register OOC_INT32 i0,i1,i2,i3,i4;
          OOC_SSA_Blocker__Region ptr;
          OOC_SSA_Blocker__Region lowerBound;
          OOC_SSA_Blocker__Loop lastLoop;

          i0 = (OOC_INT32)region;
          ptr = (OOC_SSA_Blocker__Region)i0;
          i1 = i0!=(OOC_INT32)0;
          if (i1) goto l3;
          i1=0u;
          goto l5;
l3:
          i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 39160)))), &_td_OOC_SSA_Blocker__LoopDesc));
          
l5:
          if (i1) goto l7;
          i1=i0;
          goto l17;
l7:
          i1=i0;
l8_loop:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 39192))+12);
          ptr = (OOC_SSA_Blocker__Region)i1;
          i2 = i1!=(OOC_INT32)0;
          if (i2) goto l11;
          i2=0u;
          goto l13;
l11:
          i2 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 39160)))), &_td_OOC_SSA_Blocker__LoopDesc));
          
l13:
          if (i2) goto l8_loop;
l17:
          i2 = (OOC_INT32)p;
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 39342))+16);
          lowerBound = (OOC_SSA_Blocker__Region)i3;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 39368))+16);
          i2 = i2==(OOC_INT32)0;
          if (i2) goto l20;
          i2=i3;
          goto l21;
l20:
          i2 = (OOC_INT32)root;
          lowerBound = (OOC_SSA_Blocker__Region)i2;
          
l21:
          i3 = i1!=(OOC_INT32)0;
          if (i3) goto l24;
          i4=0u;
          goto l26;
l24:
          i4 = i1!=i2;
          
l26:
          if (!i4) goto l50;
          i0 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 39660)))), &_td_OOC_SSA_Blocker__LoopDesc, 39660);
          lastLoop = (OOC_SSA_Blocker__Loop)i0;
          if (i3) goto l31;
          i3=0u;
          goto l33;
l31:
          i3 = i1!=i2;
          
l33:
          if (!i3) goto l49;
          {register OOC_INT32 h0=i0;i0=i1;i1=h0;}
l36_loop:
          i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 39739)))), &_td_OOC_SSA_Blocker__LoopDesc);
          if (!i3) goto l40;
          i1 = _type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 39783)))), &_td_OOC_SSA_Blocker__LoopDesc, 39783);
          lastLoop = (OOC_SSA_Blocker__Loop)i1;
          
l40:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 39829))+12);
          ptr = (OOC_SSA_Blocker__Region)i0;
          i3 = i0!=(OOC_INT32)0;
          if (i3) goto l43;
          i3=0u;
          goto l45;
l43:
          i3 = i0!=i2;
          
l45:
          if (i3) goto l36_loop;
l48:
          i0=i1;
l49:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 40000))+12);
          
l50:
          return (OOC_SSA_Blocker__Region)i0;
          ;
        }


      i0 = (OOC_INT32)p;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 40098))+8);
      i1 = *(OOC_INT8*)((_check_pointer(i1, 40105))+36);
      i1 = i1==10;
      if (i1) goto l43;
      region = (OOC_SSA_Blocker__Region)(OOC_INT32)0;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 40378))+8);
      res = (OOC_SSA__Result)i1;
      i2 = i1!=(OOC_INT32)0;
      if (!i2) goto l35;
      {register OOC_INT32 h0=i0;i0=i1;i1=h0;}
l6_loop:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 40436))+12);
      use = (OOC_SSA__Opnd)i0;
      i2 = i0!=(OOC_INT32)0;
      if (i2) goto l10_loop;
      i0=i1;
      goto l30;
l10_loop:
      i2 = OOC_SSA_Blocker__ArrangeInstructions_IgnoredUse((OOC_SSA__Opnd)i0);
      i2 = !i2;
      if (i2) goto l13;
      i0=i1;
      goto l25;
l13:
      i0 = (OOC_INT32)OOC_SSA_Blocker__ArrangeInstructions_GetRegion_RegionOfUse((OOC_SSA__Opnd)i0);
      useRegion = (OOC_SSA_Blocker__Region)i0;
      i1 = (OOC_INT32)p;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 40581))+16);
      i2 = i2==(OOC_INT32)0;
      if (i2) goto l16;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 40632))+16);
      i2 = OOC_SSA_Blocker__Dominates((OOC_SSA_Blocker__Region)i2, (OOC_SSA_Blocker__Region)i0);
      
      goto l18;
l16:
      i2=1u;
l18:
      if (!i2) goto l24;
      i2 = (OOC_INT32)region;
      i3 = i2==(OOC_INT32)0;
      if (i3) goto l22;
      i0 = (OOC_INT32)OOC_SSA_Blocker__ArrangeInstructions_GetRegion_Merge((OOC_SSA_Blocker__Region)i2, (OOC_SSA_Blocker__Region)i0);
      region = (OOC_SSA_Blocker__Region)i0;
      
      goto l24;
l22:
      region = (OOC_SSA_Blocker__Region)i0;
      
l24:
      i0=i1;
l25:
      i1 = (OOC_INT32)use;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 41170))+16);
      use = (OOC_SSA__Opnd)i1;
      i2 = i1!=(OOC_INT32)0;
      if (!i2) goto l30;
      {register OOC_INT32 h0=i0;i0=i1;i1=h0;}
      goto l10_loop;
l30:
      i1 = (OOC_INT32)res;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 41216));
      res = (OOC_SSA__Result)i1;
      i2 = i1!=(OOC_INT32)0;
      if (!i2) goto l35;
      {register OOC_INT32 h0=i0;i0=i1;i1=h0;}
      goto l6_loop;
l35:
      i1 = (OOC_INT32)region;
      i2 = i1==(OOC_INT32)0;
      if (i2) goto l41;
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 41339)))), &_td_OOC_SSA_Blocker__SelectDesc);
      if (!i2) goto l44;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 41415))+12);
      region = (OOC_SSA_Blocker__Region)i1;
      goto l44;
l41:
      i1 = (OOC_INT32)root;
      region = (OOC_SSA_Blocker__Region)i1;
      goto l44;
l43:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 40267))+8);
      i1 = (OOC_INT32)OOC_SSA__InstrDesc_GetLoopEnd((OOC_SSA__Instr)i1);
      loopEnd = (OOC_SSA__Instr)i1;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 40312))+16);
      return (OOC_SSA_Blocker__Region)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 40319)))), &_td_OOC_SSA_Blocker__RegionDesc, 40319));
      
l44:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 41461))+8);
      i0 = *(OOC_INT8*)((_check_pointer(i0, 41468))+36);
      i0 = i0==82;
      if (i0) goto l47;
      i0 = (OOC_INT32)region;
      i0 = (OOC_INT32)OOC_SSA_Blocker__ArrangeInstructions_GetRegion_CorrectForLoop((OOC_SSA_Blocker__Region)i0);
      i0 = (OOC_INT32)OOC_SSA_Blocker__ArrangeInstructions_GetRegion_MoveLoopInvariants((OOC_SSA_Blocker__Region)i0);
      return (OOC_SSA_Blocker__Region)i0;
      goto l48;
l47:
      i0 = (OOC_INT32)region;
      return (OOC_SSA_Blocker__Region)i0;
l48:
      _failed_function(36483); return 0;
      ;
    }

    
    void OOC_SSA_Blocker__ArrangeInstructions_SortRegion(OOC_SSA_Blocker__Region r) {
      register OOC_INT32 i0,i1,i2;
      OOC_SSA_Blocker__Proxy ready;
      OOC_SSA_Blocker__Proxy waiting;
      OOC_SSA_Blocker__Proxy proxy;
      auto void OOC_SSA_Blocker__ArrangeInstructions_SortRegion_Add(OOC_SSA_Blocker__Proxy *list, OOC_SSA_Blocker__Proxy proxy);
      auto void OOC_SSA_Blocker__ArrangeInstructions_SortRegion_Remove(OOC_SSA_Blocker__Proxy *list, OOC_SSA_Blocker__Proxy proxy);
      auto OOC_INT32 OOC_SSA_Blocker__ArrangeInstructions_SortRegion_GetLength(OOC_SSA_Blocker__Proxy proxy);
      auto void OOC_SSA_Blocker__ArrangeInstructions_SortRegion_CalculateWeight(OOC_SSA_Blocker__Proxy *list);
      auto void OOC_SSA_Blocker__ArrangeInstructions_SortRegion_CountLocalUses(OOC_SSA_Blocker__Proxy *head);
      auto void OOC_SSA_Blocker__ArrangeInstructions_SortRegion_UpdateUses(OOC_SSA__Instr instr);
      auto OOC_SSA_Blocker__Proxy OOC_SSA_Blocker__ArrangeInstructions_SortRegion_NextInstr(OOC_SSA_Blocker__Proxy ready);
        
        void OOC_SSA_Blocker__ArrangeInstructions_SortRegion_Add(OOC_SSA_Blocker__Proxy *list, OOC_SSA_Blocker__Proxy proxy) {
          register OOC_INT32 i0,i1;

          i0 = (OOC_INT32)proxy;
          i1 = (OOC_INT32)*list;
          *(OOC_INT32*)(_check_pointer(i0, 42187)) = i1;
          *list = (OOC_SSA_Blocker__Proxy)i0;
          return;
          ;
        }

        
        void OOC_SSA_Blocker__ArrangeInstructions_SortRegion_Remove(OOC_SSA_Blocker__Proxy *list, OOC_SSA_Blocker__Proxy proxy) {
          register OOC_INT32 i0,i1,i2;

          i0 = (OOC_INT32)*list;
          i1 = (OOC_INT32)proxy;
          i2 = i0==i1;
          if (i2) goto l3;
          OOC_SSA_Blocker__ArrangeInstructions_SortRegion_Remove((void*)(_check_pointer(i0, 42415)), (OOC_SSA_Blocker__Proxy)i1);
          goto l4;
l3:
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 42367));
          *list = (OOC_SSA_Blocker__Proxy)i0;
l4:
          return;
          ;
        }

        
        OOC_INT32 OOC_SSA_Blocker__ArrangeInstructions_SortRegion_GetLength(OOC_SSA_Blocker__Proxy proxy) {
          register OOC_INT32 i0,i1,i2;
          OOC_INT32 l;
          auto OOC_INT32 OOC_SSA_Blocker__ArrangeInstructions_SortRegion_GetLength_RegionLength(OOC_SSA_Blocker__Region region);
          auto OOC_CHAR8 OOC_SSA_Blocker__ArrangeInstructions_SortRegion_GetLength_IsEmpty(OOC_SSA_Blocker__Region region);
          auto OOC_CHAR8 OOC_SSA_Blocker__ArrangeInstructions_SortRegion_GetLength_IsExit(OOC_SSA_Blocker__Region region);
            
            OOC_INT32 OOC_SSA_Blocker__ArrangeInstructions_SortRegion_GetLength_RegionLength(OOC_SSA_Blocker__Region region) {
              register OOC_INT32 i0,i1,i2;
              OOC_INT32 l;
              OOC_SSA_Blocker__Proxy p;

              l = 1;
              i0 = (OOC_INT32)region;
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 42711))+48);
              p = (OOC_SSA_Blocker__Proxy)i0;
              i1 = i0!=(OOC_INT32)0;
              if (i1) goto l3;
              i0=1;
              goto l9;
l3:
              i1=i0;i0=1;
l4_loop:
              i2 = OOC_SSA_Blocker__ArrangeInstructions_SortRegion_GetLength((OOC_SSA_Blocker__Proxy)i1);
              i0 = i0+i2;
              l = i0;
              i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 42803));
              p = (OOC_SSA_Blocker__Proxy)i1;
              i2 = i1!=(OOC_INT32)0;
              if (i2) goto l4_loop;
l9:
              return i0;
              ;
            }

            
            OOC_CHAR8 OOC_SSA_Blocker__ArrangeInstructions_SortRegion_GetLength_IsEmpty(OOC_SSA_Blocker__Region region) {
              register OOC_INT32 i0;

              i0 = (OOC_INT32)region;
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 42966))+48);
              return (i0==(OOC_INT32)0);
              ;
            }

            
            OOC_CHAR8 OOC_SSA_Blocker__ArrangeInstructions_SortRegion_GetLength_IsExit(OOC_SSA_Blocker__Region region) {
              register OOC_INT32 i0,i1;

              i0 = (OOC_INT32)region;
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 43096))+48);
              i1 = i1!=(OOC_INT32)0;
              if (i1) goto l3;
              i1=0u;
              goto l5;
l3:
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 43133))+48);
              i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 43139));
              i1 = i1==(OOC_INT32)0;
              
l5:
              if (i1) goto l7;
              i0=0u;
              goto l8;
l7:
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 43180))+48);
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 43186))+8);
              i0 = *(OOC_INT8*)((_check_pointer(i0, 43192))+36);
              i0 = i0==9;
              
l8:
              return i0;
              ;
            }


          i0 = (OOC_INT32)proxy;
          i1 = *(OOC_INT32*)((_check_pointer(i0, 43272))+36);
          i1 = i1<0;
          if (!i1) goto l36;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 43311)))), &_td_OOC_SSA_Blocker__SelectDesc);
          if (i1) goto l14;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 43894)))), &_td_OOC_SSA_Blocker__RegionDesc);
          if (i1) goto l12;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 43981))+8);
          i0 = *(OOC_INT8*)((_check_pointer(i0, 43988))+36);
          switch (i0) {
          case 6:
            l = (-1);
            i0=(-1);
            goto l35;
          case 55:
            l = 20;
            i0=20;
            goto l35;
          default:
            l = 1;
            i0=1;
            goto l35;
          }
l12:
          i0 = OOC_SSA_Blocker__ArrangeInstructions_SortRegion_GetLength_RegionLength((OOC_SSA_Blocker__Region)i0);
          l = i0;
          
          goto l35;
l14:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 43348))+60);
          i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 43354)), 0);
          i1 = i1==2;
          if (i1) goto l17;
          i1=0u;
          goto l31;
l17:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 43394))+60);
          i1 = _check_pointer(i1, 43400);
          i2 = OOC_ARRAY_LENGTH(i1, 0);
          i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 43400))*4);
          i1 = OOC_SSA_Blocker__ArrangeInstructions_SortRegion_GetLength_IsEmpty((OOC_SSA_Blocker__Region)i1);
          if (i1) goto l20;
          i1=0u;
          goto l22;
l20:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 43419))+60);
          i1 = _check_pointer(i1, 43425);
          i2 = OOC_ARRAY_LENGTH(i1, 0);
          i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(1, i2, OOC_UINT8, 43425))*4);
          i1 = OOC_SSA_Blocker__ArrangeInstructions_SortRegion_GetLength_IsExit((OOC_SSA_Blocker__Region)i1);
          
l22:
          if (i1) goto l28;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 43464))+60);
          i1 = _check_pointer(i1, 43470);
          i2 = OOC_ARRAY_LENGTH(i1, 0);
          i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(1, i2, OOC_UINT8, 43470))*4);
          i1 = OOC_SSA_Blocker__ArrangeInstructions_SortRegion_GetLength_IsEmpty((OOC_SSA_Blocker__Region)i1);
          if (i1) goto l26;
          i1=0u;
          goto l31;
l26:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 43489))+60);
          i1 = _check_pointer(i1, 43495);
          i2 = OOC_ARRAY_LENGTH(i1, 0);
          i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 43495))*4);
          i1 = OOC_SSA_Blocker__ArrangeInstructions_SortRegion_GetLength_IsExit((OOC_SSA_Blocker__Region)i1);
          
          goto l31;
l28:
          i1=1u;
l31:
          if (i1) goto l33;
          i0 = OOC_SSA_Blocker__ArrangeInstructions_SortRegion_GetLength_RegionLength((OOC_SSA_Blocker__Region)i0);
          l = i0;
          
          goto l35;
l33:
          l = 0;
          i0=0;
l35:
          i1 = (OOC_INT32)proxy;
          *(OOC_INT32*)((_check_pointer(i1, 44164))+36) = i0;
l36:
          i0 = (OOC_INT32)proxy;
          i0 = *(OOC_INT32*)((_check_pointer(i0, 44212))+36);
          return i0;
          ;
        }

        
        void OOC_SSA_Blocker__ArrangeInstructions_SortRegion_CalculateWeight(OOC_SSA_Blocker__Proxy *list) {
          register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
          OOC_SSA_Blocker__Proxy ready;
          OOC_SSA_Blocker__Proxy waiting;
          OOC_SSA_Blocker__Proxy proxy;
          OOC_INT32 degreeDiff;
          OOC_SSA__Result res;
          OOC_SSA__Opnd opnd;
          OOC_SSA__Opnd use;
          OOC_CHAR8 selectingValue;
          OOC_INT32 max;
          OOC_SSA_Blocker__Proxy useProxy;
          OOC_SSA_Blocker__Proxy defProxy;
          auto OOC_CHAR8 OOC_SSA_Blocker__ArrangeInstructions_SortRegion_CalculateWeight_CountAsRegister(OOC_SSA__Result arg);
            
            OOC_CHAR8 OOC_SSA_Blocker__ArrangeInstructions_SortRegion_CalculateWeight_CountAsRegister(OOC_SSA__Result arg) {
              register OOC_INT32 i0,i1;

              i0 = (OOC_INT32)arg;
              i1 = *(OOC_INT8*)((_check_pointer(i0, 44578))+5);
              i1 = i1==0;
              if (i1) goto l3;
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 44625))+8);
              i1 = *(OOC_INT8*)((_check_pointer(i1, 44631))+36);
              i1 = i1==13;
              
              goto l5;
l3:
              i1=1u;
l5:
              if (i1) goto l11;
              i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 44881)))), &_td_OOC_SSA__InstrDesc));
              if (i1) goto l9;
              i0 = OOC_SSA__InstrDesc_IsConst((OOC_SSA__Instr)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 44907)))), &_td_OOC_SSA__InstrDesc, 44907)));
              i0 = !i0;
              
              goto l10;
l9:
              i0=1u;
l10:
              return i0;
              goto l12;
l11:
              return 0u;
l12:
              _failed_function(44503); return 0;
              ;
            }


          ready = (OOC_SSA_Blocker__Proxy)(OOC_INT32)0;
          waiting = (OOC_SSA_Blocker__Proxy)(OOC_INT32)0;
          i0 = (OOC_INT32)*list;
          i0 = i0!=(OOC_INT32)0;
          if (!i0) goto l60;
l3_loop:
          i0 = (OOC_INT32)*list;
          proxy = (OOC_SSA_Blocker__Proxy)i0;
          i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 45112));
          *list = (OOC_SSA_Blocker__Proxy)i1;
          degreeDiff = 0;
          useCount = 0;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 45208))+8);
          i1 = i1!=(OOC_INT32)0;
          if (!i1) goto l51;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 45314))+8);
          res = (OOC_SSA__Result)i0;
          i1 = i0!=(OOC_INT32)0;
          if (!i1) goto l16;
l8_loop:
          i0 = OOC_SSA_Blocker__ArrangeInstructions_SortRegion_CalculateWeight_CountAsRegister((OOC_SSA__Result)i0);
          if (!i0) goto l11;
          i0 = degreeDiff;
          degreeDiff = (i0+1);
l11:
          i0 = (OOC_INT32)res;
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 45477));
          res = (OOC_SSA__Result)i0;
          i1 = i0!=(OOC_INT32)0;
          if (i1) goto l8_loop;
l16:
          i0 = (OOC_INT32)proxy;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 45533))+8);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 45540))+24);
          opnd = (OOC_SSA__Opnd)i0;
          i1 = i0!=(OOC_INT32)0;
          if (!i1) goto l31;
l19_loop:
          i1 = OOC_SSA__OpndDesc_IsValueOpndHere((OOC_SSA__Opnd)i0);
          if (i1) goto l22;
          i0=0u;
          goto l24;
l22:
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 45650));
          i0 = OOC_SSA_Blocker__ArrangeInstructions_SortRegion_CalculateWeight_CountAsRegister((OOC_SSA__Result)i0);
          
l24:
          if (!i0) goto l26;
          i0 = degreeDiff;
          degreeDiff = (i0-1);
l26:
          i0 = (OOC_INT32)opnd;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 45741))+8);
          opnd = (OOC_SSA__Opnd)i0;
          i1 = i0!=(OOC_INT32)0;
          if (i1) goto l19_loop;
l31:
          i0 = (OOC_INT32)proxy;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 45873))+8);
          res = (OOC_SSA__Result)i0;
          i1 = i0!=(OOC_INT32)0;
          if (!i1) goto l51;
          i1 = (OOC_INT32)r;
          
l34_loop:
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 45939))+12);
          use = (OOC_SSA__Opnd)i2;
          i3 = i2!=(OOC_INT32)0;
          if (!i3) goto l45;
l37_loop:
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 46008))+12);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 46015))+16);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 46022)))), &_td_OOC_SSA_Blocker__ProxyDesc, 46022)), 46028))+12);
          i3 = i3==i1;
          if (!i3) goto l40;
          i3 = useCount;
          useCount = (i3+1);
l40:
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 46128))+16);
          use = (OOC_SSA__Opnd)i2;
          i3 = i2!=(OOC_INT32)0;
          if (i3) goto l37_loop;
l45:
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 46182));
          res = (OOC_SSA__Result)i0;
          i2 = i0!=(OOC_INT32)0;
          if (i2) goto l34_loop;
l51:
          i0 = (OOC_INT32)proxy;
          i1 = degreeDiff;
          *(OOC_INT32*)((_check_pointer(i0, 46243))+44) = i1;
          i1 = useCount;
          *(OOC_INT32*)((_check_pointer(i0, 46286))+32) = i1;
          i1 = i1==0;
          if (i1) goto l54;
          OOC_SSA_Blocker__ArrangeInstructions_SortRegion_Add((void*)(OOC_INT32)&waiting, (OOC_SSA_Blocker__Proxy)i0);
          goto l55;
l54:
          i1 = *(OOC_INT32*)((_check_pointer(i0, 46377))+36);
          *(OOC_INT32*)((_check_pointer(i0, 46358))+40) = i1;
          OOC_SSA_Blocker__ArrangeInstructions_SortRegion_Add((void*)(OOC_INT32)&ready, (OOC_SSA_Blocker__Proxy)i0);
l55:
          i0 = (OOC_INT32)*list;
          i0 = i0!=(OOC_INT32)0;
          if (i0) goto l3_loop;
l60:
          i0 = (OOC_INT32)ready;
          i0 = i0!=(OOC_INT32)0;
          if (!i0) goto l124;
l63_loop:
          i0 = (OOC_INT32)ready;
          proxy = (OOC_SSA_Blocker__Proxy)i0;
          OOC_SSA_Blocker__ArrangeInstructions_SortRegion_Remove((void*)(OOC_INT32)&ready, (OOC_SSA_Blocker__Proxy)i0);
          selectingValue = 0u;
          max = 0;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 46662))+8);
          i1 = i1!=(OOC_INT32)0;
          if (i1) goto l66;
          i1=0u;i2=0;
          goto l115;
l66:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 46706))+8);
          res = (OOC_SSA__Result)i1;
          i2 = i1!=(OOC_INT32)0;
          if (i2) goto l69;
          i1=0u;i2=0;
          goto l100;
l69:
          i2 = (OOC_INT32)r;
          i3=0;i4=0u;
l70_loop:
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 46772))+12);
          use = (OOC_SSA__Opnd)i5;
          i6 = i5!=(OOC_INT32)0;
          if (!i6) goto l95;
          {register OOC_INT32 h0=i3;i3=i5;i5=i4;i4=h0;}
l74_loop:
          i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 46849))+12);
          i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 46856))+16);
          i6 = _type_guard(i6, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 46863)))), &_td_OOC_SSA_Blocker__ProxyDesc, 46863);
          useProxy = (OOC_SSA_Blocker__Proxy)i6;
          i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 46899))+12);
          i7 = i7==i2;
          if (i7) goto l77;
          i7=0u;
          goto l79;
l77:
          i7 = *(OOC_INT32*)((_check_pointer(i6, 46924))+40);
          i7 = i7>i4;
          
l79:
          if (!i7) goto l82;
          i4 = *(OOC_INT32*)((_check_pointer(i6, 46980))+40);
          max = i4;
          
l82:
          i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 47036))+12);
          i6 = *(OOC_INT8*)((_check_pointer(i6, 47042))+36);
          i6 = i6==5;
          if (i6) goto l85;
          i6=0u;
          goto l87;
l85:
          i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 47092))+12);
          i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 47098))+24);
          i6 = i6==i3;
          
l87:
          if (!i6) goto l90;
          selectingValue = 1u;
          i5=1u;
l90:
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 47209))+16);
          use = (OOC_SSA__Opnd)i3;
          i6 = i3!=(OOC_INT32)0;
          if (i6) goto l74_loop;
l94:
          i3=i4;i4=i5;
l95:
          i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 47263));
          res = (OOC_SSA__Result)i1;
          i5 = i1!=(OOC_INT32)0;
          if (i5) goto l70_loop;
l99:
          i1=i4;i2=i3;
l100:
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 47336))+8);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 47343))+24);
          opnd = (OOC_SSA__Opnd)i3;
          i4 = i3!=(OOC_INT32)0;
          if (!i4) goto l115;
l103_loop:
          i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 47419));
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 47424))+8);
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 47431))+16);
          i4 = _type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 47438)))), &_td_OOC_SSA_Blocker__ProxyDesc, 47438);
          defProxy = (OOC_SSA_Blocker__Proxy)i4;
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 47472))+12);
          i6 = (OOC_INT32)r;
          i5 = i5==i6;
          if (!i5) goto l109;
          i5 = *(OOC_INT32*)((_check_pointer(i4, 47520))+32);
          *(OOC_INT32*)((_check_pointer(i4, 47520))+32) = (i5-1);
          i5 = *(OOC_INT32*)((_check_pointer(i4, 47559))+32);
          i5 = i5==0;
          if (!i5) goto l109;
          OOC_SSA_Blocker__ArrangeInstructions_SortRegion_Remove((void*)(OOC_INT32)&waiting, (OOC_SSA_Blocker__Proxy)i4);
          OOC_SSA_Blocker__ArrangeInstructions_SortRegion_Add((void*)(OOC_INT32)&ready, (OOC_SSA_Blocker__Proxy)i4);
l109:
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 47731))+8);
          opnd = (OOC_SSA__Opnd)i3;
          i4 = i3!=(OOC_INT32)0;
          if (i4) goto l103_loop;
l115:
          i1 = !i1;
          if (i1) goto l118;
          i1=i2;
          goto l119;
l118:
          i1 = OOC_SSA_Blocker__ArrangeInstructions_SortRegion_GetLength((OOC_SSA_Blocker__Proxy)i0);
          i1 = i2+i1;
          max = i1;
          
l119:
          *(OOC_INT32*)((_check_pointer(i0, 48050))+40) = i1;
          i1 = (OOC_INT32)*list;
          *(OOC_INT32*)(_check_pointer(i0, 48095)) = i1;
          *list = (OOC_SSA_Blocker__Proxy)i0;
          i0 = (OOC_INT32)ready;
          i0 = i0!=(OOC_INT32)0;
          if (i0) goto l63_loop;
l124:
          i0 = (OOC_INT32)waiting;
          _assert((i0==(OOC_INT32)0), 127, 48162);
          return;
          ;
        }

        
        void OOC_SSA_Blocker__ArrangeInstructions_SortRegion_CountLocalUses(OOC_SSA_Blocker__Proxy *head) {
          register OOC_INT32 i0,i1,i2,i3,i4,i5;
          OOC_SSA_Blocker__Proxy proxy;
          OOC_INT32 opndCount;
          OOC_SSA__Opnd opnd;

          i0 = (OOC_INT32)*head;
          i1 = i0!=(OOC_INT32)0;
          if (!i1) goto l29;
          
l3_loop:
          proxy = (OOC_SSA_Blocker__Proxy)i0;
          i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 48439));
          *head = (OOC_SSA_Blocker__Proxy)i1;
          opndCount = 0;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 48632))+8);
          i2 = i2!=(OOC_INT32)0;
          if (i2) goto l6;
          i2=0;
          goto l20;
l6:
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 48677))+8);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 48684))+24);
          opnd = (OOC_SSA__Opnd)i2;
          i3 = i2!=(OOC_INT32)0;
          if (i3) goto l9;
          i2=0;
          goto l19;
l9:
          i3 = (OOC_INT32)r;
          i4=0;
l10_loop:
          i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 48752));
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 48757))+8);
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 48764))+16);
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i5, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 48771)))), &_td_OOC_SSA_Blocker__ProxyDesc, 48771)), 48777))+12);
          i5 = i5==i3;
          if (!i5) goto l14;
          i4 = i4+1;
          opndCount = i4;
          
l14:
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 48874))+8);
          opnd = (OOC_SSA__Opnd)i2;
          i5 = i2!=(OOC_INT32)0;
          if (i5) goto l10_loop;
l18:
          i2=i4;
l19:
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 48920))+8);
          *(OOC_INT32*)((_check_pointer(i3, 48927))+20) = i2;
          
l20:
          i2 = i2==0;
          if (i2) goto l23;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 49071))+8);
          _assert((i2!=(OOC_INT32)0), 127, 49058);
          OOC_SSA_Blocker__ArrangeInstructions_SortRegion_Add((void*)(OOC_INT32)&waiting, (OOC_SSA_Blocker__Proxy)i0);
          goto l24;
l23:
          OOC_SSA_Blocker__ArrangeInstructions_SortRegion_Add((void*)(OOC_INT32)&ready, (OOC_SSA_Blocker__Proxy)i0);
l24:
          i0 = i1!=(OOC_INT32)0;
          if (!i0) goto l29;
          i0=i1;
          goto l3_loop;
l29:
          return;
          ;
        }

        
        void OOC_SSA_Blocker__ArrangeInstructions_SortRegion_UpdateUses(OOC_SSA__Instr instr) {
          register OOC_INT32 i0,i1,i2,i3,i4;
          OOC_SSA__Result res;
          OOC_SSA__Opnd use;
          OOC_SSA_Blocker__Proxy useProxy;

          i0 = (OOC_INT32)instr;
          res = (OOC_SSA__Result)i0;
          i1 = i0!=(OOC_INT32)0;
          if (!i1) goto l22;
          
l3_loop:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 49390))+12);
          use = (OOC_SSA__Opnd)i1;
          i2 = i1!=(OOC_INT32)0;
          if (!i2) goto l17;
l6_loop:
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 49459))+12);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 49466))+16);
          i2 = _type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 49473)))), &_td_OOC_SSA_Blocker__ProxyDesc, 49473);
          useProxy = (OOC_SSA_Blocker__Proxy)i2;
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 49505))+12);
          i4 = (OOC_INT32)r;
          i3 = i3==i4;
          if (!i3) goto l12;
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 49546))+12);
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 49546))+12);
          i4 = *(OOC_INT32*)((_check_pointer(i4, 49553))+20);
          *(OOC_INT32*)((_check_pointer(i3, 49553))+20) = (i4-1);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 49585))+12);
          i3 = *(OOC_INT32*)((_check_pointer(i3, 49592))+20);
          i3 = i3==0;
          if (!i3) goto l12;
          OOC_SSA_Blocker__ArrangeInstructions_SortRegion_Remove((void*)(OOC_INT32)&waiting, (OOC_SSA_Blocker__Proxy)i2);
          OOC_SSA_Blocker__ArrangeInstructions_SortRegion_Add((void*)(OOC_INT32)&ready, (OOC_SSA_Blocker__Proxy)i2);
l12:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 49752))+16);
          use = (OOC_SSA__Opnd)i1;
          i2 = i1!=(OOC_INT32)0;
          if (i2) goto l6_loop;
l17:
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 49798));
          res = (OOC_SSA__Result)i0;
          i1 = i0!=(OOC_INT32)0;
          if (i1) goto l3_loop;
l22:
          return;
          ;
        }

        
        OOC_SSA_Blocker__Proxy OOC_SSA_Blocker__ArrangeInstructions_SortRegion_NextInstr(OOC_SSA_Blocker__Proxy ready) {
          register OOC_INT32 i0,i1,i2,i3;
          OOC_SSA_Blocker__Proxy best;

          i0 = (OOC_INT32)ready;
          best = (OOC_SSA_Blocker__Proxy)i0;
          i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 49983));
          ready = (OOC_SSA_Blocker__Proxy)i1;
          i2 = i1!=0;
          if (!i2) goto l21;
          {register OOC_INT32 h0=i0;i0=i1;i1=h0;}
l4_loop:
          i2 = *(OOC_INT32*)((_check_pointer(i0, 50046))+40);
          i3 = *(OOC_INT32*)((_check_pointer(i1, 50063))+40);
          i2 = i2>i3;
          if (i2) goto l11;
          i2 = *(OOC_INT32*)((_check_pointer(i0, 50097))+40);
          i3 = *(OOC_INT32*)((_check_pointer(i1, 50114))+40);
          i2 = i2==i3;
          if (i2) goto l9;
          i2=0u;
          goto l13;
l9:
          i2 = *(OOC_INT32*)((_check_pointer(i0, 50149))+44);
          i3 = *(OOC_INT32*)((_check_pointer(i1, 50168))+44);
          i2 = i2<i3;
          
          goto l13;
l11:
          i2=1u;
l13:
          if (!i2) goto l16;
          best = (OOC_SSA_Blocker__Proxy)i0;
          i1=i0;
l16:
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 50253));
          ready = (OOC_SSA_Blocker__Proxy)i0;
          i2 = i0!=0;
          if (i2) goto l4_loop;
l20:
          i0=i1;
l21:
          return (OOC_SSA_Blocker__Proxy)i0;
          ;
        }


      ready = (OOC_SSA_Blocker__Proxy)(OOC_INT32)0;
      waiting = (OOC_SSA_Blocker__Proxy)(OOC_INT32)0;
      i0 = (OOC_INT32)r;
      *(OOC_INT32*)((_check_pointer(i0, 50637))+52) = (OOC_INT32)0;
      OOC_SSA_Blocker__ArrangeInstructions_SortRegion_CalculateWeight((void*)((_check_pointer(i0, 50676))+48));
      i0 = (OOC_INT32)r;
      OOC_SSA_Blocker__ArrangeInstructions_SortRegion_CountLocalUses((void*)((_check_pointer(i0, 50709))+48));
      i0 = (OOC_INT32)ready;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l8;
l3_loop:
      i0 = (OOC_INT32)OOC_SSA_Blocker__ArrangeInstructions_SortRegion_NextInstr((OOC_SSA_Blocker__Proxy)i0);
      proxy = (OOC_SSA_Blocker__Proxy)i0;
      OOC_SSA_Blocker__ArrangeInstructions_SortRegion_Remove((void*)(OOC_INT32)&ready, (OOC_SSA_Blocker__Proxy)i0);
      i0 = (OOC_INT32)proxy;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 50966))+8);
      OOC_SSA_Blocker__ArrangeInstructions_SortRegion_UpdateUses((OOC_SSA__Instr)i0);
      i0 = (OOC_INT32)proxy;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 50997))+12);
      i2 = (OOC_INT32)r;
      _assert((i1==i2), 127, 50984);
      *(OOC_INT32*)((_check_pointer(i0, 51025))+12) = (OOC_INT32)0;
      OOC_SSA_Blocker__RegionDesc_Append((OOC_SSA_Blocker__Region)i2, (OOC_SSA_Blocker__Proxy)i0);
      i0 = (OOC_INT32)ready;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l3_loop;
l8:
      i0 = (OOC_INT32)waiting;
      _assert((i0==(OOC_INT32)0), 127, 51086);
      i0 = (OOC_INT32)r;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 51127))+48);
      ready = (OOC_SSA_Blocker__Proxy)i0;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l19;
l11_loop:
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 51183)))), &_td_OOC_SSA_Blocker__RegionDesc);
      if (!i1) goto l14;
      OOC_SSA_Blocker__ArrangeInstructions_SortRegion((OOC_SSA_Blocker__Region)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 51227)))), &_td_OOC_SSA_Blocker__RegionDesc, 51227)));
l14:
      i0 = (OOC_INT32)ready;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 51272));
      ready = (OOC_SSA_Blocker__Proxy)i0;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l11_loop;
l19:
      return;
      ;
    }

    
    void OOC_SSA_Blocker__ArrangeInstructions_ClearRegion(OOC_SSA_Blocker__Region r) {
      register OOC_INT32 i0,i1,i2;
      OOC_SSA_Blocker__Proxy p;

      i0 = (OOC_INT32)r;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 51400))+48);
      p = (OOC_SSA_Blocker__Proxy)i1;
      i2 = i1!=(OOC_INT32)0;
      if (!i2) goto l15;
l3_loop:
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 51448)))), &_td_OOC_SSA_Blocker__RegionDesc);
      if (i2) goto l6;
      *(OOC_INT32*)((_check_pointer(i1, 51597))+12) = (OOC_INT32)0;
      goto l10;
l6:
      OOC_SSA_Blocker__ArrangeInstructions_ClearRegion((OOC_SSA_Blocker__Region)i1);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 51503))+12);
      i2 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 51512)))), &_td_OOC_SSA_Blocker__SelectDesc));
      if (!i2) goto l10;
      *(OOC_INT32*)((_check_pointer(i1, 51541))+12) = (OOC_INT32)0;
l10:
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 51641));
      p = (OOC_SSA_Blocker__Proxy)i1;
      i2 = i1!=(OOC_INT32)0;
      if (i2) goto l3_loop;
l15:
      i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 51678)))), &_td_OOC_SSA_Blocker__SelectDesc));
      if (!i1) goto l18;
      *(OOC_INT32*)((_check_pointer(i0, 51703))+48) = (OOC_INT32)0;
      *(OOC_INT32*)((_check_pointer(i0, 51728))+52) = (OOC_INT32)0;
l18:
      return;
      ;
    }


  i0 = (OOC_INT32)pb;
  OOC_SSA_DeadCodeElimination__Transform((OOC_SSA__ProcBlock)i0);
  OOC_SSA_Blocker__RemoveAntiDeps((OOC_SSA__ProcBlock)i0);
  OOC_SSA__ProcBlockDesc_SetMarkers((OOC_SSA__ProcBlock)i0, (OOC_SSA__Node)(OOC_INT32)0, 0);
  i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetEnter((OOC_SSA__ProcBlock)i0);
  enter = (OOC_SSA__Instr)i0;
  i1 = (OOC_INT32)OOC_SSA_Blocker__NewLoop((OOC_SSA__Instr)(OOC_INT32)0);
  mainLoop = (OOC_SSA_Blocker__Loop)i1;
  i0 = (OOC_INT32)OOC_SSA__InstrDesc_GetResultStore((OOC_SSA__Instr)i0);
  OOC_SSA_Blocker__ArrangeInstructions_DiscoverLoopStructure((OOC_SSA_Blocker__Loop)i1, (OOC_SSA__Result)i0, (OOC_SSA__Instr)(OOC_INT32)0, (OOC_SSA_Blocker__Loop)(OOC_INT32)0);
  i0 = (OOC_INT32)mainLoop;
  OOC_SSA_Blocker__ArrangeInstructions_SortNestedLoops((OOC_SSA_Blocker__Loop)i0);
  i0 = (OOC_INT32)mainLoop;
  OOC_SSA_Blocker__ArrangeInstructions_AttachToLoop((OOC_SSA_Blocker__Loop)i0);
l1_loop:
  i0 = (OOC_INT32)OOC_SSA_Blocker__NewRegion((OOC_SSA__Instr)(OOC_INT32)0);
  ready = (OOC_SSA_Blocker__Region)i0;
  i0 = (OOC_INT32)OOC_SSA_Blocker__NewRegion((OOC_SSA__Instr)(OOC_INT32)0);
  waiting = (OOC_SSA_Blocker__Region)i0;
  i0 = (OOC_INT32)pb;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 52614))+12);
  instr = (OOC_SSA__Instr)i0;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l32;
l4_loop:
  useCount = 0;
  res = (OOC_SSA__Result)i0;
  if (!i1) goto l23;
l7_loop:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 52750))+12);
  use = (OOC_SSA__Opnd)i0;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l18;
l10_loop:
  i0 = OOC_SSA_Blocker__ArrangeInstructions_IgnoredUse((OOC_SSA__Opnd)i0);
  i0 = !i0;
  if (!i0) goto l13;
  i0 = useCount;
  useCount = (i0+1);
l13:
  i0 = (OOC_INT32)use;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 52899))+16);
  use = (OOC_SSA__Opnd)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l10_loop;
l18:
  i0 = (OOC_INT32)res;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 52945));
  res = (OOC_SSA__Result)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l7_loop;
l23:
  i0 = (OOC_INT32)instr;
  i1 = (OOC_INT32)OOC_SSA_Blocker__GetProxy((OOC_SSA__Instr)i0);
  p = (OOC_SSA_Blocker__Proxy)i1;
  i2 = useCount;
  *(OOC_INT32*)((_check_pointer(i0, 53025))+20) = i2;
  i2 = i2==0;
  if (i2) goto l26;
  i2 = (OOC_INT32)waiting;
  OOC_SSA_Blocker__RegionDesc_Append((OOC_SSA_Blocker__Region)i2, (OOC_SSA_Blocker__Proxy)i1);
  goto l27;
l26:
  i2 = (OOC_INT32)ready;
  OOC_SSA_Blocker__RegionDesc_Append((OOC_SSA_Blocker__Region)i2, (OOC_SSA_Blocker__Proxy)i1);
l27:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 53186))+28);
  instr = (OOC_SSA__Instr)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l4_loop;
l32:
  i0 = (OOC_INT32)ready;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 53379))+48);
  p = (OOC_SSA_Blocker__Proxy)i1;
  i2 = i1!=(OOC_INT32)0;
  if (i2) goto l35;
  i2=0u;
  goto l37;
l35:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 53414))+8);
  i2 = *(OOC_INT8*)((_check_pointer(i2, 53421))+36);
  i2 = i2!=8;
  
l37:
  if (!i2) goto l49;
l40_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 53470));
  p = (OOC_SSA_Blocker__Proxy)i1;
  i2 = i1!=(OOC_INT32)0;
  if (i2) goto l43;
  i2=0u;
  goto l45;
l43:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 53414))+8);
  i2 = *(OOC_INT8*)((_check_pointer(i2, 53421))+36);
  i2 = i2!=8;
  
l45:
  if (i2) goto l40_loop;
l49:
  OOC_SSA_Blocker__RegionDesc_Remove((OOC_SSA_Blocker__Region)i0, (OOC_SSA_Blocker__Proxy)i1);
  root = (OOC_SSA_Blocker__Region)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 53535)))), &_td_OOC_SSA_Blocker__RegionDesc, 53535));
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 53767))+48);
  i0 = i0!=(OOC_INT32)0;
  if (!i0) goto l56;
l51_loop:
  i0 = (OOC_INT32)ready;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 53803))+48);
  p = (OOC_SSA_Blocker__Proxy)i1;
  OOC_SSA_Blocker__RegionDesc_Remove((OOC_SSA_Blocker__Region)i0, (OOC_SSA_Blocker__Proxy)i1);
  OOC_SSA_Blocker__ArrangeInstructions_UpdateDefs((OOC_SSA_Blocker__Proxy)i1);
  i0 = (OOC_INT32)p;
  i0 = (OOC_INT32)OOC_SSA_Blocker__ArrangeInstructions_GetRegion((OOC_SSA_Blocker__Proxy)i0);
  region = (OOC_SSA_Blocker__Region)i0;
  i1 = (OOC_INT32)p;
  OOC_SSA_Blocker__RegionDesc_Insert((OOC_SSA_Blocker__Region)i0, (OOC_SSA_Blocker__Proxy)i1);
  i0 = (OOC_INT32)ready;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 53767))+48);
  i0 = i0!=(OOC_INT32)0;
  if (i0) goto l51_loop;
l56:
  i0 = (OOC_INT32)waiting;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 53965))+48);
  _assert((i0==(OOC_INT32)0), 127, 53950);
  i0 = (OOC_INT32)root;
  OOC_SSA_Blocker__ArrangeInstructions_AddRegionDeps((OOC_SSA_Blocker__Region)i0);
  i0 = (OOC_INT32)root;
  OOC_SSA_Blocker__ArrangeInstructions_SortRegion((OOC_SSA_Blocker__Region)i0);
  i0 = markAntiDeps;
  if (i0) goto l59;
  i0=0u;
  goto l61;
l59:
  i0 = (OOC_INT32)root;
  i1 = (OOC_INT32)pb;
  i0 = OOC_SSA_Blocker__AntiDepViolation((OOC_SSA__ProcBlock)i1, (OOC_SSA_Blocker__Region)i0);
  
l61:
  if (!i0) goto l65;
  i0 = (OOC_INT32)pb;
  OOC_SSA_Blocker__RemoveRegionDeps((OOC_SSA__ProcBlock)i0);
  i0 = (OOC_INT32)root;
  OOC_SSA_Blocker__ArrangeInstructions_ClearRegion((OOC_SSA_Blocker__Region)i0);
  goto l1_loop;
l65:
  i0 = (OOC_INT32)root;
  return (OOC_SSA_Blocker__Region)i0;
  ;
}

OOC_SSA_Blocker__DependenceData OOC_SSA_Blocker__GetDependenceData(OOC_SSA__ProcBlock pb) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_SSA_Blocker__DependenceData dd;
  ADT_Dictionary__Dictionary proxyMap;
  OOC_SSA__Instr instr;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_SSA_Blocker__DependenceData.baseTypes[0]);
  dd = (OOC_SSA_Blocker__DependenceData)i0;
  i1 = (OOC_INT32)pb;
  i2 = (OOC_INT32)OOC_SSA_Blocker__ArrangeInstructions((OOC_SSA__ProcBlock)i1, 0u);
  *(OOC_INT32*)(_check_pointer(i0, 54818)) = i2;
  i2 = (OOC_INT32)ADT_Dictionary__New();
  proxyMap = (ADT_Dictionary__Dictionary)i2;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 54915))+12);
  instr = (OOC_SSA__Instr)i1;
  i3 = i1!=0;
  if (!i3) goto l8;
l3_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 54988))+16);
  ADT_Dictionary__DictionaryDesc_Set((ADT_Dictionary__Dictionary)i2, (Object__Object)i1, (Object__Object)(_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 54995)))), &_td_OOC_SSA_Blocker__ProxyDesc, 54995)));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 55024))+28);
  instr = (OOC_SSA__Instr)i1;
  i3 = i1!=0;
  if (i3) goto l3_loop;
l8:
  *(OOC_INT32*)((_check_pointer(i0, 55052))+4) = i2;
  return (OOC_SSA_Blocker__DependenceData)i0;
  ;
}

OOC_CHAR8 OOC_SSA_Blocker__DependenceDataDesc_SameRegion(OOC_SSA_Blocker__DependenceData dd, OOC_SSA__Instr x, OOC_SSA__Instr y) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)x;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 55294))+16);
  i1 = (OOC_INT32)y;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 55317))+16);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 55300)))), &_td_OOC_SSA_Blocker__ProxyDesc, 55300)), 55306))+12);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 55323)))), &_td_OOC_SSA_Blocker__ProxyDesc, 55323)), 55329))+12);
  return (i0==i1);
  ;
}

OOC_CHAR8 OOC_SSA_Blocker__DependenceDataDesc_Dominates(OOC_SSA_Blocker__DependenceData dd, OOC_SSA__Instr x, OOC_SSA__Instr y) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)x;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 55545))+16);
  i1 = (OOC_INT32)y;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 55567))+16);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 55551)))), &_td_OOC_SSA_Blocker__ProxyDesc, 55551)), 55557))+12);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 55573)))), &_td_OOC_SSA_Blocker__ProxyDesc, 55573)), 55579))+12);
  i0 = OOC_SSA_Blocker__Dominates((OOC_SSA_Blocker__Region)i0, (OOC_SSA_Blocker__Region)i1);
  return i0;
  ;
}

OOC_CHAR8 OOC_SSA_Blocker__DependenceDataDesc_Conflict(OOC_SSA_Blocker__DependenceData dd, OOC_SSA__Instr x, OOC_SSA__Instr y) {
  register OOC_INT32 i0,i1,i2,i3;
  Object__Object p;
  OOC_SSA_Blocker__Region a;
  OOC_SSA_Blocker__Region b;

  i0 = (OOC_INT32)dd;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 55741))+4);
  i2 = (OOC_INT32)x;
  i1 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i1, (Object__Object)i2);
  p = (Object__Object)i1;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 55773)))), &_td_OOC_SSA_Blocker__ProxyDesc, 55773)), 55779))+12);
  a = (OOC_SSA_Blocker__Region)i1;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 55800))+4);
  i2 = (OOC_INT32)y;
  i0 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i0, (Object__Object)i2);
  p = (Object__Object)i0;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 55832)))), &_td_OOC_SSA_Blocker__ProxyDesc, 55832)), 55838))+12);
  b = (OOC_SSA_Blocker__Region)i0;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 55865))+56);
  i3 = *(OOC_INT32*)((_check_pointer(i0, 55883))+56);
  i2 = i2>i3;
  if (!i2) goto l9;
l4_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 55914))+12);
  a = (OOC_SSA_Blocker__Region)i1;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 55865))+56);
  i3 = *(OOC_INT32*)((_check_pointer(i0, 55883))+56);
  i2 = i2>i3;
  if (i2) goto l4_loop;
l9:
  i2 = *(OOC_INT32*)((_check_pointer(i0, 55945))+56);
  i3 = *(OOC_INT32*)((_check_pointer(i1, 55963))+56);
  i2 = i2>i3;
  if (!i2) goto l18;
l13_loop:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 55994))+12);
  b = (OOC_SSA_Blocker__Region)i0;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 55945))+56);
  i3 = *(OOC_INT32*)((_check_pointer(i1, 55963))+56);
  i2 = i2>i3;
  if (i2) goto l13_loop;
l18:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 56025))+12);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 56037))+12);
  i2 = i2!=i3;
  if (i2) goto l21;
  {register OOC_INT32 h0=i0;i0=i1;i1=h0;}
  goto l27;
l21:
  {register OOC_INT32 h0=i0;i0=i1;i1=h0;}
l22_loop:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 56062))+12);
  a = (OOC_SSA_Blocker__Region)i0;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 56084))+12);
  b = (OOC_SSA_Blocker__Region)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 56025))+12);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 56037))+12);
  i2 = i2!=i3;
  if (i2) goto l22_loop;
l27:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 56116))+12);
  i2 = i2!=(OOC_INT32)0;
  if (i2) goto l30;
  i2=0u;
  goto l32;
l30:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 56136))+12);
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 56145)))), &_td_OOC_SSA_Blocker__SelectDesc);
  
l32:
  if (i2) goto l34;
  i0=0u;
  goto l35;
l34:
  i0 = i0!=i1;
  
l35:
  return i0;
  ;
}

OOC_CHAR8 OOC_SSA_Blocker__DependenceDataDesc_DependsOn(OOC_SSA_Blocker__DependenceData dd, OOC_SSA__Instr x, OOC_SSA__Instr y) {
  register OOC_INT32 i0,i1;
  ADT_Dictionary__Dictionary visited;
  auto OOC_CHAR8 OOC_SSA_Blocker__DependenceDataDesc_DependsOn_PassesResult(OOC_SSA__Result res);
    
    OOC_CHAR8 OOC_SSA_Blocker__DependenceDataDesc_DependsOn_PassesResult(OOC_SSA__Result res) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_SSA__Opnd use;

      i0 = (OOC_INT32)res;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l26;
      
l3_loop:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 56655))+12);
      use = (OOC_SSA__Opnd)i1;
      i2 = i1!=(OOC_INT32)0;
      if (!i2) goto l21;
l6_loop:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 56729))+12);
      i3 = (OOC_INT32)visited;
      i2 = ADT_Dictionary__DictionaryDesc_HasKey((ADT_Dictionary__Dictionary)i3, (Object__Object)i2);
      i2 = !i2;
      if (!i2) goto l16;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 56772))+12);
      i3 = (OOC_INT32)visited;
      ADT_Dictionary__DictionaryDesc_Set((ADT_Dictionary__Dictionary)i3, (Object__Object)i2, (Object__Object)(OOC_INT32)0);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 56806))+12);
      i3 = (OOC_INT32)x;
      i2 = i2==i3;
      if (i2) goto l11;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 56839))+12);
      i2 = OOC_SSA_Blocker__DependenceDataDesc_DependsOn_PassesResult((OOC_SSA__Result)i2);
      
      goto l13;
l11:
      i2=1u;
l13:
      if (!i2) goto l16;
      return 1u;
l16:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 56932))+16);
      use = (OOC_SSA__Opnd)i1;
      i2 = i1!=(OOC_INT32)0;
      if (i2) goto l6_loop;
l21:
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 56974));
      res = (OOC_SSA__Result)i0;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l3_loop;
l26:
      return 0u;
      ;
    }


  i0 = (OOC_INT32)ADT_Dictionary__New();
  visited = (ADT_Dictionary__Dictionary)i0;
  i0 = (OOC_INT32)x;
  i1 = (OOC_INT32)y;
  i0 = i0!=i1;
  if (i0) goto l3;
  i0=0u;
  goto l4;
l3:
  i0 = OOC_SSA_Blocker__DependenceDataDesc_DependsOn_PassesResult((OOC_SSA__Result)i1);
  
l4:
  return i0;
  ;
}

OOC_CHAR8 OOC_SSA_Blocker__DependenceDataDesc_AvailableTo(OOC_SSA_Blocker__DependenceData dd, OOC_SSA__Instr x, OOC_SSA__Instr y) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_SSA__Instr xValue;
  OOC_SSA_Blocker__Loop xLoop;
  OOC_SSA__Opnd exit;

  i0 = (OOC_INT32)x;
  xValue = (OOC_SSA__Instr)i0;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 57639))+16);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 57646)))), &_td_OOC_SSA_Blocker__ProxyDesc, 57646)), 57652))+16);
  xLoop = (OOC_SSA_Blocker__Loop)i1;
  i2 = i1!=(OOC_INT32)0;
  if (i2) goto l3;
  i2=0u;
  goto l4;
l3:
  i2 = (OOC_INT32)y;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 57711))+16);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 57718)))), &_td_OOC_SSA_Blocker__ProxyDesc, 57718)), 57724))+12);
  i2 = OOC_SSA_Blocker__Dominates((OOC_SSA_Blocker__Region)i1, (OOC_SSA_Blocker__Region)i2);
  i2 = !i2;
  
l4:
  i3 = (OOC_INT32)y;
  if (!i2) goto l36;
  i2 = (OOC_INT32)dd;
  {register OOC_INT32 h0=i0;i0=i1;i1=h0;}
l8_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 57756))+8);
  i4 = (OOC_INT32)OOC_SSA__InstrDesc_NthOpnd((OOC_SSA__Instr)i4, 2);
  exit = (OOC_SSA__Opnd)i4;
  i5 = i4!=(OOC_INT32)0;
  if (i5) goto l11;
  i5=0u;
  goto l13;
l11:
  i5 = *(OOC_INT8*)((_check_pointer(i4, 57810))+4);
  i5 = i5==11;
  
l13:
  if (!i5) goto l27;
l15_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 57880));
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 57885))+8);
  i5 = OOC_SSA_Blocker__DependenceDataDesc_AvailableTo((OOC_SSA_Blocker__DependenceData)i2, (OOC_SSA__Instr)i1, (OOC_SSA__Instr)i5);
  i5 = !i5;
  if (!i5) goto l18;
  return 0u;
l18:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 58083))+8);
  exit = (OOC_SSA__Opnd)i4;
  i5 = i4!=(OOC_INT32)0;
  if (i5) goto l21;
  i5=0u;
  goto l23;
l21:
  i5 = *(OOC_INT8*)((_check_pointer(i4, 57810))+4);
  i5 = i5==11;
  
l23:
  if (i5) goto l15_loop;
l27:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 58127))+8);
  xValue = (OOC_SSA__Instr)i1;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 58156))+16);
  xLoop = (OOC_SSA_Blocker__Loop)i0;
  i4 = i0!=(OOC_INT32)0;
  if (i4) goto l30;
  i4=0u;
  goto l32;
l30:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 57711))+16);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 57718)))), &_td_OOC_SSA_Blocker__ProxyDesc, 57718)), 57724))+12);
  i4 = OOC_SSA_Blocker__Dominates((OOC_SSA_Blocker__Region)i0, (OOC_SSA_Blocker__Region)i4);
  i4 = !i4;
  
l32:
  if (i4) goto l8_loop;
l35:
  i0=i1;
l36:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 58427))+16);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 58451))+16);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 58434)))), &_td_OOC_SSA_Blocker__ProxyDesc, 58434)), 58440))+12);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 58458)))), &_td_OOC_SSA_Blocker__ProxyDesc, 58458)), 58464))+12);
  i1 = OOC_SSA_Blocker__Dominates((OOC_SSA_Blocker__Region)i1, (OOC_SSA_Blocker__Region)i2);
  if (i1) goto l39;
  i0=0u;
  goto l40;
l39:
  i1 = (OOC_INT32)dd;
  i0 = OOC_SSA_Blocker__DependenceDataDesc_DependsOn((OOC_SSA_Blocker__DependenceData)i1, (OOC_SSA__Instr)i0, (OOC_SSA__Instr)i3);
  i0 = !i0;
  
l40:
  return i0;
  ;
}

OOC_SSA__Instr OOC_SSA_Blocker__DependenceDataDesc_GetSameInstr(OOC_SSA_Blocker__DependenceData dd, OOC_SSA__Instr regionInstr, OOC_SSA__Instr instr) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_SSA_Blocker__Region region;
  OOC_SSA_Blocker__Proxy p;
  OOC_SSA__Instr instr2;
  OOC_SSA__Opnd opnd1;
  OOC_SSA__Opnd opnd2;

  i0 = (OOC_INT32)regionInstr;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 58744))+16);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 58750)))), &_td_OOC_SSA_Blocker__ProxyDesc, 58750)), 58756))+12);
  region = (OOC_SSA_Blocker__Region)i0;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 58780))+48);
  p = (OOC_SSA_Blocker__Proxy)i0;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l47;
  i1 = (OOC_INT32)instr;
  
l3_loop:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 58828))+8);
  instr2 = (OOC_SSA__Instr)i2;
  i3 = *(OOC_INT8*)((_check_pointer(i1, 58851))+36);
  i4 = *(OOC_INT8*)((_check_pointer(i2, 58867))+36);
  i3 = i3==i4;
  if (i3) goto l6;
  i3=0u;
  goto l8;
l6:
  i3 = *(OOC_INT8*)((_check_pointer(i1, 58893))+5);
  i4 = *(OOC_INT8*)((_check_pointer(i2, 58911))+5);
  i3 = i3==i4;
  
l8:
  if (!i3) goto l42;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 58949))+24);
  opnd1 = (OOC_SSA__Opnd)i3;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 58983))+24);
  opnd2 = (OOC_SSA__Opnd)i4;
  i5 = i3!=(OOC_INT32)0;
  if (i5) goto l12;
  i5=0u;
  goto l14;
l12:
  i5 = i4!=(OOC_INT32)0;
  
l14:
  if (i5) goto l16;
  i5=0u;
  goto l18;
l16:
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 59058));
  i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 59046));
  i5 = i6==i5;
  
l18:
  if (!i5) goto l34;
l21_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 59091))+8);
  opnd1 = (OOC_SSA__Opnd)i3;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 59126))+8);
  opnd2 = (OOC_SSA__Opnd)i4;
  i5 = i3!=(OOC_INT32)0;
  if (i5) goto l24;
  i5=0u;
  goto l26;
l24:
  i5 = i4!=(OOC_INT32)0;
  
l26:
  if (i5) goto l28;
  i5=0u;
  goto l30;
l28:
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 59058));
  i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 59046));
  i5 = i6==i5;
  
l30:
  if (i5) goto l21_loop;
l34:
  i3 = i3==(OOC_INT32)0;
  if (i3) goto l37;
  i3=0u;
  goto l39;
l37:
  i3 = i4==(OOC_INT32)0;
  
l39:
  if (!i3) goto l42;
  return (OOC_SSA__Instr)i2;
l42:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 59285));
  p = (OOC_SSA_Blocker__Proxy)i0;
  i2 = i0!=(OOC_INT32)0;
  if (i2) goto l3_loop;
l47:
  return (OOC_SSA__Instr)(OOC_INT32)0;
  ;
}

void OOC_SSA_Blocker__DependenceDataDesc_SetRegion(OOC_SSA_Blocker__DependenceData dd, OOC_SSA__Instr regionInstr, OOC_SSA__Instr instr) {
  register OOC_INT32 i0,i1,i2;
  OOC_SSA_Blocker__Proxy p;

  i0 = (OOC_INT32)instr;
  i1 = (OOC_INT32)OOC_SSA_Blocker__NewProxy((OOC_SSA__Instr)i0);
  p = (OOC_SSA_Blocker__Proxy)i1;
  i2 = (OOC_INT32)regionInstr;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 59486))+16);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 59492)))), &_td_OOC_SSA_Blocker__ProxyDesc, 59492)), 59498))+12);
  OOC_SSA_Blocker__RegionDesc_Append((OOC_SSA_Blocker__Region)i2, (OOC_SSA_Blocker__Proxy)i1);
  *(OOC_INT32*)((_check_pointer(i0, 59526))+16) = i1;
  return;
  ;
}

void OOC_SSA_Blocker__Write(IO__ByteChannel c, OOC_SSA__ProcBlock pb) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)pb;
  i1 = (OOC_INT32)OOC_SSA_Blocker__ArrangeInstructions((OOC_SSA__ProcBlock)i0, 0u);
  i2 = (OOC_INT32)ADT_Dictionary__New();
  i3 = (OOC_INT32)c;
  OOC_SSA_Blocker__WriteBlocks((IO__ByteChannel)i3, (OOC_SSA__ProcBlock)i0, (OOC_SSA_Blocker__Region)i1, (ADT_Dictionary__Dictionary)i2);
  OOC_SSA_Blocker__RemoveAntiDeps((OOC_SSA__ProcBlock)i0);
  return;
  ;
}

void OOC_SSA_Blocker__WriteMarker(IO__ByteChannel c, OOC_SSA__ProcBlock pb, ADT_Dictionary__Dictionary marker) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)pb;
  i1 = (OOC_INT32)OOC_SSA_Blocker__ArrangeInstructions((OOC_SSA__ProcBlock)i0, 0u);
  i2 = (OOC_INT32)c;
  i3 = (OOC_INT32)marker;
  OOC_SSA_Blocker__WriteBlocks((IO__ByteChannel)i2, (OOC_SSA__ProcBlock)i0, (OOC_SSA_Blocker__Region)i1, (ADT_Dictionary__Dictionary)i3);
  OOC_SSA_Blocker__RemoveAntiDeps((OOC_SSA__ProcBlock)i0);
  return;
  ;
}

void OOC_SSA_Blocker__ToStderr(OOC_SSA__ProcBlock pb) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)IO_StdChannels__stderr;
  i1 = (OOC_INT32)pb;
  OOC_SSA_Blocker__Write((IO__ByteChannel)i0, (OOC_SSA__ProcBlock)i1);
  return;
  ;
}

void OOC_OOC_SSA_Blocker_init(void) {

  return;
  ;
}

/* --- */
