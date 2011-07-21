#include <OOC/SSA/Blocker.d>
#include <__oo2c.h>
#include <setjmp.h>

static void OOC_SSA_Blocker__InitProxy(OOC_SSA_Blocker__Proxy p, OOC_SSA__Instr instr) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)p;
  *(OOC_INT32*)(_check_pointer(i0, 7118)) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 7143))+4) = 0;
  i1 = (OOC_INT32)instr;
  *(OOC_INT32*)((_check_pointer(i0, 7168))+8) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 7191))+12) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 7213))+16) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 7238))+20) = 0;
  *(OOC_UINT8*)((_check_pointer(i0, 7268))+24) = 0u;
  *(OOC_INT32*)((_check_pointer(i0, 7299))+28) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 7332))+32) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 7352))+36) = (-1);
  *(OOC_INT32*)((_check_pointer(i0, 7373))+40) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 7395))+44) = 0;
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
  *(OOC_INT32*)((_check_pointer(i0, 7649))+32) = 0;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7678))+48);
  proxy = (OOC_SSA_Blocker__Proxy)i0;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l11;
l3_loop:
  *(OOC_INT32*)((_check_pointer(i0, 7725))+32) = 0;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7756)))), &_td_OOC_SSA_Blocker__RegionDesc);
  if (!i1) goto l6;
  OOC_SSA_Blocker__ClearMarkers((OOC_SSA_Blocker__Region)i0);
l6:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7883));
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
  *(OOC_INT32*)((_check_pointer(i0, 8107))+48) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i0, 8128))+52) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i0, 8148))+56) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 8174))+32) = 0;
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
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8418))+12);
  _assert((i1==(OOC_INT32)0), 127, 8409);
  i1 = (OOC_INT32)r;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 8461))+52);
  *(OOC_INT32*)((_check_pointer(i0, 8445))+4) = i2;
  *(OOC_INT32*)(_check_pointer(i0, 8474)) = (OOC_INT32)0;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 8503))+52);
  i2 = i2!=(OOC_INT32)0;
  if (i2) goto l3;
  *(OOC_INT32*)((_check_pointer(i1, 8569))+48) = i0;
  goto l4;
l3:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 8529))+52);
  *(OOC_INT32*)(_check_pointer(i2, 8535)) = i0;
l4:
  *(OOC_INT32*)((_check_pointer(i1, 8597))+52) = i0;
  *(OOC_INT32*)((_check_pointer(i0, 8620))+12) = i1;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8645)))), &_td_OOC_SSA_Blocker__RegionDesc);
  if (!i2) goto l7;
  i1 = *(OOC_INT32*)((_check_pointer(i1, 8695))+56);
  *(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8669)))), &_td_OOC_SSA_Blocker__RegionDesc, 8669)), 8676))+56) = (i1+1);
l7:
  return;
  ;
}

void OOC_SSA_Blocker__RegionDesc_Insert(OOC_SSA_Blocker__Region r, OOC_SSA_Blocker__Proxy p) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)p;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8798))+12);
  _assert((i1==(OOC_INT32)0), 127, 8789);
  *(OOC_INT32*)((_check_pointer(i0, 8825))+4) = (OOC_INT32)0;
  i1 = (OOC_INT32)r;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 8866))+48);
  *(OOC_INT32*)(_check_pointer(i0, 8850)) = i2;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 8884))+48);
  i2 = i2!=(OOC_INT32)0;
  if (i2) goto l3;
  *(OOC_INT32*)((_check_pointer(i1, 8952))+52) = i0;
  goto l4;
l3:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 8911))+48);
  *(OOC_INT32*)((_check_pointer(i2, 8918))+4) = i0;
l4:
  *(OOC_INT32*)((_check_pointer(i1, 8979))+48) = i0;
  *(OOC_INT32*)((_check_pointer(i0, 9003))+12) = i1;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9028)))), &_td_OOC_SSA_Blocker__RegionDesc);
  if (!i2) goto l7;
  i1 = *(OOC_INT32*)((_check_pointer(i1, 9078))+56);
  *(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9052)))), &_td_OOC_SSA_Blocker__RegionDesc, 9052)), 9059))+56) = (i1+1);
l7:
  return;
  ;
}

void OOC_SSA_Blocker__RegionDesc_Remove(OOC_SSA_Blocker__Region r, OOC_SSA_Blocker__Proxy p) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)p;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9181))+12);
  i2 = (OOC_INT32)r;
  _assert((i1==i2), 127, 9172);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9205))+4);
  i1 = i1!=(OOC_INT32)0;
  if (i1) goto l3;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 9304));
  *(OOC_INT32*)((_check_pointer(i2, 9292))+48) = i1;
  goto l4;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9236))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 9263));
  *(OOC_INT32*)(_check_pointer(i1, 9247)) = i3;
l4:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 9335));
  i1 = i1!=(OOC_INT32)0;
  if (i1) goto l7;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9433))+4);
  *(OOC_INT32*)((_check_pointer(i2, 9422))+52) = i1;
  goto l8;
l7:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 9366));
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9393))+4);
  *(OOC_INT32*)((_check_pointer(i1, 9377))+4) = i2;
l8:
  *(OOC_INT32*)((_check_pointer(i0, 9465))+12) = (OOC_INT32)0;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9492)))), &_td_OOC_SSA_Blocker__RegionDesc);
  if (!i1) goto l11;
  *(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9516)))), &_td_OOC_SSA_Blocker__RegionDesc, 9516)), 9523))+56) = 0;
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
  *(OOC_INT32*)((_check_pointer(i0, 9777))+60) = ((OOC_INT32)RT0__NewObject(_td_OOC_SSA_Blocker__5556.baseTypes[0], (i1>>1)));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9840))+60);
  i = 0;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 9847)), 0);
  i2 = 0<i1;
  if (!i2) goto l8;
  i2=0;
l3_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9862))+60);
  i3 = _check_pointer(i3, 9869);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 9869))*4) = (OOC_INT32)0;
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
  *(OOC_INT32*)((_check_pointer(i0, 10233))+64) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i0, 10257))+60) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i0, 10284))+68) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i0, 10310))+72) = (OOC_INT32)0;
  *(OOC_UINT8*)((_check_pointer(i0, 10340))+76) = 0u;
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
      _assert((i0!=i1), 127, 10621);
      i2 = i1==(OOC_INT32)0;
      if (i2) goto l3;
      OOC_SSA_Blocker__LoopDesc_AppendLoop_App((void*)((_check_pointer(i1, 10769))+64));
      goto l4;
l3:
      *(OOC_INT32*)((_check_pointer(i0, 10694))+64) = (OOC_INT32)0;
      *list = (OOC_SSA_Blocker__Loop)i0;
l4:
      return;
      ;
    }


  i0 = (OOC_INT32)loop;
  OOC_SSA_Blocker__LoopDesc_AppendLoop_App((void*)((_check_pointer(i0, 10830))+60));
  i0 = (OOC_INT32)nestedLoop;
  i1 = (OOC_INT32)loop;
  *(OOC_INT32*)((_check_pointer(i0, 10860))+68) = i1;
  return;
  ;
}

static OOC_SSA_Blocker__Proxy OOC_SSA_Blocker__GetProxy(OOC_SSA__Instr instr) {
  register OOC_INT32 i0,i1;
  OOC_SSA_Blocker__Proxy p;

  i0 = (OOC_INT32)instr;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10992))+16);
  i1 = i1!=(OOC_INT32)0;
  if (i1) goto l9;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 11069))+36);
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
  *(OOC_INT32*)((_check_pointer(i0, 11315))+16) = i1;
  return (OOC_SSA_Blocker__Proxy)i1;
  goto l10;
l9:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11029))+16);
  return (OOC_SSA_Blocker__Proxy)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11036)))), &_td_OOC_SSA_Blocker__ProxyDesc, 11036));
l10:
  _failed_function(10913); return 0;
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
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11492))+12);
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
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11862)))), &_td_OOC_SSA_Blocker__RegionDesc);
      if (!i1) goto l11;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11888))+48);
      n = (OOC_SSA_Blocker__Proxy)i1;
      i2 = i1!=(OOC_INT32)0;
      if (!i2) goto l11;
l5_loop:
      OOC_SSA_Blocker__WriteBlocks_AssignId((OOC_SSA_Blocker__Proxy)i1);
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 11964));
      n = (OOC_SSA_Blocker__Proxy)i1;
      i2 = i1!=(OOC_INT32)0;
      if (i2) goto l5_loop;
l11:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12024))+8);
      i1 = i1!=(OOC_INT32)0;
      if (i1) goto l14;
      i1=0u;
      goto l16;
l14:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12043))+8);
      i1 = OOC_SSA__InstrDesc_IsConst((OOC_SSA__Instr)i1);
      i1 = !i1;
      
l16:
      if (!i1) goto l18;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12088))+8);
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
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12303))+8);
      instr = (OOC_SSA__Instr)i1;
      i2 = i1==(OOC_INT32)0;
      if (i2) goto l3;
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 12482)))), IO_TextRider__WriterDesc_WriteHex)),IO_TextRider__WriterDesc_WriteHex)((IO_TextRider__Writer)i2, (_type_cast_fast(OOC_INT32, OOC_INT32, i1)), 8);
      goto l4;
l3:
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 12421)))), IO_TextRider__WriterDesc_WriteHex)),IO_TextRider__WriterDesc_WriteHex)((IO_TextRider__Writer)i1, (_type_cast_fast(OOC_INT32, OOC_INT32, i0)), 8);
l4:
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 12553)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, "  ", 3);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13146))+12);
      i1 = i1!=(OOC_INT32)0;
      if (!i1) goto l28;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13181))+12);
      i1 = *(OOC_INT32*)((_check_pointer(i1, 13189))+56);
      d = i1;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13219))+12);
      r = (OOC_SSA_Blocker__Region)i0;
      i2 = i0!=(OOC_INT32)0;
      if (i2) goto l10_loop;
      i0=i1;
      goto l19;
l10_loop:
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13272)))), &_td_OOC_SSA_Blocker__SelectDesc);
      if (!i2) goto l14;
      i1 = i1-1;
      d = i1;
      
l14:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13340))+12);
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
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 13401)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i2, "  ", 3);
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
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 13737)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i2, 91u);
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 13765)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i2, (Object__Object)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13795)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i0, 93u);
l3:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 13899))+8);
      instr = (OOC_SSA__Instr)i0;
      i2 = OOC_SSA__InstrDesc_IsConst((OOC_SSA__Instr)i0);
      if (i2) goto l18;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14958))+8);
      i2 = (OOC_INT32)idMap;
      i0 = ADT_Dictionary_IntValue__DictionaryDesc_Get((ADT_Dictionary_IntValue__Dictionary)i2, (Object__Object)i0);
      id = i0;
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 14977)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i2, 40u);
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 15005)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i2, i0, 0);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 15041))+8);
      i0 = i0!=i1;
      if (!i0) goto l17;
      count = 1;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 15103))+8);
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 15110));
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
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 15202));
      ptr = (OOC_SSA__Result)i2;
      i3 = i2!=i1;
      if (i3) goto l11_loop;
l16:
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15242)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i1, 46u);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15272)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i1, i0, 0);
l17:
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15318)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i0, 41u);
      goto l43;
l18:
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13957)))), &_td_OOC_SSA__ConstDesc);
      if (i1) goto l37;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14179)))), &_td_OOC_SSA__DeclRefDesc);
      if (i1) goto l35;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14263)))), &_td_OOC_SSA__TypeRefDesc);
      if (i1) goto l33;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14335)))), &_td_OOC_SSA__AddressDesc);
      if (i1) goto l31;
      i1 = *(OOC_INT8*)((_check_pointer(i0, 14467))+36);
      switch (i1) {
      case 56:
      case 57:
        i1 = (OOC_INT32)w;
        i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14569))+24);
        i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14579))+8);
        i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14589))+8);
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 14599));
        i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 14637)))), &_td_OOC_SSA__DeclRefDesc, 14637)), 14645))+44);
        i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14651))+20);
        i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14657))+12);
        i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14569))+24);
        i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 14579))+8);
        i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 14589))+8);
        i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 14599));
        i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 14637)))), &_td_OOC_SSA__DeclRefDesc, 14637)), 14645))+44);
        i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 14651))+20);
        i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 14657))+12);
        i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 14662)), 0);
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14549)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, (void*)(_check_pointer(i2, 14662)), i3);
        i1 = (OOC_INT32)w;
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14679)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, "/dim", 5);
        i1 = (OOC_INT32)w;
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14734))+24);
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 14744));
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14754)))), &_td_OOC_SSA__ConstDesc, 14754)), 14760))+44);
        i0 = Object_BigInt__BigIntDesc_ToLongInt((Object_BigInt__BigInt)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14775)))), &_td_Object_BigInt__BigIntDesc, 14775)));
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14716)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i1, i0, 0);
        goto l43;
      default:
        OOC_SSA__InstrDesc_LogOpcode((OOC_SSA__Instr)i0, "instr.opcode", 13);
        _assert(0u, 127, 14875);
        goto l43;
      }
l31:
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14363)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i1, 38u);
      i1 = (OOC_INT32)w;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14413))+44);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14419))+20);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14425))+12);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14413))+44);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14419))+20);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14425))+12);
      i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 14430)), 0);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14393)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, (void*)(_check_pointer(i2, 14430)), i0);
      goto l43;
l33:
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14291)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "<typeref>", 10);
      goto l43;
l35:
      i1 = (OOC_INT32)w;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14227))+44);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14233))+20);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14239))+12);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14227))+44);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14233))+20);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14239))+12);
      i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 14244)), 0);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14207)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, (void*)(_check_pointer(i2, 14244)), i0);
      goto l43;
l37:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13991))+44);
      i2 = (OOC_INT32)OOC_SSA__nil;
      i1 = i1==i2;
      if (i1) goto l40;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14092))+44);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14092))+44);
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14099)))), Object_Boxed__ObjectDesc_ToString)),Object_Boxed__ObjectDesc_ToString)((Object_Boxed__Object)i0);
      value = (Object__String)i0;
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14126)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i1, (Object__Object)i0);
      goto l43;
l40:
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14028)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "NIL", 4);
l43:
      return;
      ;
    }

    
    void OOC_SSA_Blocker__WriteBlocks_WriteOpnd(OOC_SSA__Opnd opnd) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)opnd;
      i1 = *(OOC_INT8*)((_check_pointer(i0, 15437))+4);
      switch (i1) {
      case 18:
        i1 = (OOC_INT32)w;
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15486)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, "*ad*", 5);
        goto l6;
      case 20:
        i1 = (OOC_INT32)w;
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15550)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, "*rd*", 5);
        goto l6;
      case 17:
        i1 = (OOC_INT32)w;
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15613)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, "*led*", 6);
        goto l6;
      default:
        goto l6;
      }
l6:
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 15790));
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
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16019))+8);
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
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16190))+12);
      i3 = i3!=(OOC_INT32)0;
      if (i3) goto l9;
      i3 = *(OOC_INT8*)((_check_pointer(i1, 16216))+36);
      i3 = i3==8;
      
      goto l11;
l9:
      i3=1u;
l11:
      if (!i3) goto l17;
      i3 = i2!=0;
      if (!i3) goto l16;
      i3 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 16303)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i3, 44u);
l16:
      OOC_SSA_Blocker__WriteBlocks_WriteResultId((OOC_SSA__Result)i0);
      i2 = i2+1;
      resCount = i2;
      
l17:
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 16435));
      res = (OOC_SSA__Result)i0;
      i3 = i0!=(OOC_INT32)0;
      if (i3) goto l6_loop;
l21:
      i0=i2;
l22:
      i0 = i0==0;
      if (!i0) goto l25;
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16504)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "(--)", 5);
l25:
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16559)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, " := ", 5);
      i0 = *(OOC_INT8*)((_check_pointer(i1, 16627))+5);
      i2 = *(OOC_INT8*)((_check_pointer(i1, 16612))+36);
      OOC_SSA_Opcode__GetName(i2, i0, (void*)(OOC_INT32)str, 64);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16654)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (void*)(OOC_INT32)str, 64);
      i0 = *(OOC_INT32*)((_check_pointer(i1, 16692))+40);
      i0 = i0>=0;
      if (!i0) goto l28;
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16720)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "@", 2);
      i0 = (OOC_INT32)w;
      i2 = *(OOC_INT32*)((_check_pointer(i1, 16770))+40);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16752)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i0, i2, 0);
l28:
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16803)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i0, 32u);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 16852))+24);
      opnd = (OOC_SSA__Opnd)i0;
      i2 = i0!=(OOC_INT32)0;
      if (!i2) goto l39;
l31_loop:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 16920))+24);
      i2 = i0!=i2;
      if (!i2) goto l34;
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 16950)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i2, 44u);
l34:
      OOC_SSA_Blocker__WriteBlocks_WriteOpnd((OOC_SSA__Opnd)i0);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17034))+8);
      opnd = (OOC_SSA__Opnd)i0;
      i2 = i0!=(OOC_INT32)0;
      if (i2) goto l31_loop;
l39:
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17067)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
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
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17293)))), &_td_OOC_SSA_Blocker__RegionDesc);
          if (i1) goto l6;
          OOC_SSA_Blocker__WriteBlocks_WriteInstr((OOC_SSA_Blocker__Proxy)i0);
          goto l7;
l6:
          OOC_SSA_Blocker__WriteBlocks_WriteRegion((OOC_SSA_Blocker__Region)i0);
l7:
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 17408));
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
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17533)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "IF ", 4);
          i0 = (OOC_INT32)select;
          OOC_SSA_Blocker__WriteBlocks_WriteOpnd((OOC_SSA__Opnd)i0);
          i0 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17593)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, " = ", 4);
          i0 = (OOC_INT32)opnd;
          OOC_SSA_Blocker__WriteBlocks_WriteOpnd((OOC_SSA__Opnd)i0);
          i0 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17651)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, " THEN", 6);
          return;
          ;
        }


      i0 = (OOC_INT32)r;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17730)))), &_td_OOC_SSA_Blocker__LoopDesc);
      if (i1) goto l16;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17917)))), &_td_OOC_SSA_Blocker__SelectDesc);
      if (i1) goto l5;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18453))+48);
      OOC_SSA_Blocker__WriteBlocks_WriteRegion_WriteBody((OOC_SSA_Blocker__Proxy)i0);
      goto l17;
l5:
      OOC_SSA_Blocker__WriteBlocks_WriteInstrPrefix((OOC_SSA_Blocker__Proxy)i0);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17960)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, "SELECT", 7);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17987)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i1);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18015))+8);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 18022))+24);
      opnd = (OOC_SSA__Opnd)i1;
      i = 0;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18075))+60);
      i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 18082)), 0);
      i2 = 0!=i2;
      if (!i2) goto l14;
      {register OOC_INT32 h0=i0;i0=i1;i1=h0;}i2=0;
l9_loop:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18111))+8);
      opnd = (OOC_SSA__Opnd)i0;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 18152))+60);
      i3 = _check_pointer(i3, 18159);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i2 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 18159))*4);
      OOC_SSA_Blocker__WriteBlocks_WriteInstrPrefix((OOC_SSA_Blocker__Proxy)i2);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 18193))+8);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 18200))+24);
      OOC_SSA_Blocker__WriteBlocks_WriteRegion_WriteBranchHead((OOC_SSA__Opnd)i1, (OOC_SSA__Opnd)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18230)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
      i0 = (OOC_INT32)r;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18263))+60);
      i0 = _check_pointer(i0, 18270);
      i1 = OOC_ARRAY_LENGTH(i0, 0);
      i2 = i;
      i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(i2, i1, OOC_UINT32, 18270))*4);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18273))+48);
      OOC_SSA_Blocker__WriteBlocks_WriteRegion_WriteBody((OOC_SSA_Blocker__Proxy)i0);
      i0 = (OOC_INT32)opnd;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18305))+8);
      i1 = i;
      opnd = (OOC_SSA__Opnd)i0;
      i1 = i1+1;
      i = i1;
      i2 = (OOC_INT32)r;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 18075))+60);
      i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 18082)), 0);
      i3 = i1!=i3;
      if (!i3) goto l13;
      {register OOC_INT32 h0=i1;i1=i2;i2=h0;}
      goto l9_loop;
l13:
      i0=i2;
l14:
      OOC_SSA_Blocker__WriteBlocks_WriteInstrPrefix((OOC_SSA_Blocker__Proxy)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18380)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "END SELECT", 11);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18411)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
      goto l17;
l16:
      OOC_SSA_Blocker__WriteBlocks_WriteInstrPrefix((OOC_SSA_Blocker__Proxy)i0);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17771)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, "LOOP", 5);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17796)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i1);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17827))+48);
      OOC_SSA_Blocker__WriteBlocks_WriteRegion_WriteBody((OOC_SSA_Blocker__Proxy)i0);
      i0 = (OOC_INT32)r;
      OOC_SSA_Blocker__WriteBlocks_WriteInstrPrefix((OOC_SSA_Blocker__Proxy)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17868)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "END LOOP", 9);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17897)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
l17:
      i0 = (OOC_INT32)r;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18485))+8);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18692)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18708)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "Procedure: ", 12);
  i1 = (OOC_INT32)pb;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 18761))+20);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 18771))+20);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 18777))+12);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 18761))+20);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 18771))+20);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 18777))+12);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 18782)), 0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18744)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (void*)(_check_pointer(i2, 18782)), i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18791)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
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
      i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 19307)))), &_td_OOC_SSA_Blocker__RegionDesc));
      
l5:
      if (!i1) goto l32;
      i1 = (OOC_INT32)readDesign;
      i2 = (OOC_INT32)storeInGet;
      
l8_loop:
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19346))+8);
      i3 = (OOC_INT32)OOC_SSA__InstrDesc_GetResultStore((OOC_SSA__Instr)i3);
      storeOut = (OOC_SSA__Result)i3;
      i4 = *(OOC_INT32*)((_check_pointer(i0, 19390))+32);
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
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19692))+8);
      i4 = (OOC_INT32)destore;
      i3 = OOC_SSA_Destore__StateDesc_ClobberedBy((OOC_SSA_Destore__State)i4, (OOC_SSA__Opnd)i1, (OOC_SSA__Instr)i3);
      
l19:
      if (!i3) goto l23;
      i3 = violationCount;
      violationCount = (i3+1);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19753))+8);
      i4 = (OOC_INT32)get;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i3, (OOC_SSA__Result)i4, 18);
      goto l23;
l22:
      return;
l23:
      i3 = currentId;
      *(OOC_INT32*)((_check_pointer(i0, 19951))+32) = i3;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19996))+4);
      proxy = (OOC_SSA_Blocker__Proxy)i0;
      i3 = i0!=(OOC_INT32)0;
      if (i3) goto l26;
      i3=0u;
      goto l28;
l26:
      i3 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 19307)))), &_td_OOC_SSA_Blocker__RegionDesc));
      
l28:
      if (i3) goto l8_loop;
l32:
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l41;
      i0 = (OOC_INT32)region;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21183))+12);
      i1 = i1!=(OOC_INT32)0;
      if (!i1) goto l81;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21224))+12);
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 21233)))), &_td_OOC_SSA_Blocker__SelectDesc);
      if (!i1) goto l39;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21277))+12);
      region = (OOC_SSA_Blocker__Region)i0;
l39:
      i0 = (OOC_INT32)region;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21332))+12);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21348))+4);
      i2 = (OOC_INT32)storeInGet;
      i3 = (OOC_INT32)readDesign;
      OOC_SSA_Blocker__AntiDepViolation_ScanBackward((OOC_SSA_Blocker__Region)i1, (OOC_SSA_Blocker__Proxy)i0, (OOC_SSA__Opnd)i3, (OOC_SSA__Result)i2);
      goto l81;
l41:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20268))+8);
      i1 = (OOC_INT32)OOC_SSA__InstrDesc_GetResultStore((OOC_SSA__Instr)i1);
      storeOut = (OOC_SSA__Result)i1;
      i2 = *(OOC_INT32*)((_check_pointer(i0, 20312))+32);
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
      *(OOC_INT32*)((_check_pointer(i0, 20412))+32) = i3;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20455)))), &_td_OOC_SSA_Blocker__SelectDesc);
      if (i1) goto l69;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20725)))), &_td_OOC_SSA_Blocker__LoopDesc);
      if (!i1) goto l81;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20760))+8);
      i0 = (OOC_INT32)OOC_SSA__InstrDesc_NthOpnd((OOC_SSA__Instr)i0, 2);
      opnd = (OOC_SSA__Opnd)i0;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l54;
      i1=0u;
      goto l56;
l54:
      i1 = *(OOC_INT8*)((_check_pointer(i0, 20820))+4);
      i1 = i1==11;
      
l56:
      if (!i1) goto l81;
      i1 = (OOC_INT32)storeInGet;
      i2 = (OOC_INT32)readDesign;
      
l58_loop:
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 20872));
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 20877))+8);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 20884))+16);
      i3 = _type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 20891)))), &_td_OOC_SSA_Blocker__ProxyDesc, 20891);
      x = (OOC_SSA_Blocker__Proxy)i3;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 20928))+12);
      OOC_SSA_Blocker__AntiDepViolation_ScanBackward((OOC_SSA_Blocker__Region)i4, (OOC_SSA_Blocker__Proxy)i3, (OOC_SSA__Opnd)i2, (OOC_SSA__Result)i1);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20992))+8);
      opnd = (OOC_SSA__Opnd)i0;
      i3 = i0!=(OOC_INT32)0;
      if (i3) goto l61;
      i3=0u;
      goto l63;
l61:
      i3 = *(OOC_INT8*)((_check_pointer(i0, 20820))+4);
      i3 = i3==11;
      
l63:
      if (i3) goto l58_loop;
      goto l81;
l69:
      i = 0;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20520))+60);
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 20527)), 0);
      i1 = 0!=i1;
      if (!i1) goto l81;
      i1 = (OOC_INT32)storeInGet;
      i2 = (OOC_INT32)readDesign;
      i3=0;
l72_loop:
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20567))+60);
      i4 = _check_pointer(i4, 20574);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20584))+60);
      i6 = _check_pointer(i6, 20591);
      i7 = OOC_ARRAY_LENGTH(i6, 0);
      i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i3, i7, OOC_UINT32, 20591))*4);
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 20594))+52);
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 20574))*4);
      OOC_SSA_Blocker__AntiDepViolation_ScanBackward((OOC_SSA_Blocker__Region)i4, (OOC_SSA_Blocker__Proxy)i6, (OOC_SSA__Opnd)i2, (OOC_SSA__Result)i1);
      i3 = i3+1;
      i = i3;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20520))+60);
      i4 = OOC_ARRAY_LENGTH((_check_pointer(i4, 20527)), 0);
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
      i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21791)))), &_td_OOC_SSA_Blocker__RegionDesc));
      
l5:
      if (!i1) goto l23;
      i1 = (OOC_INT32)readDesign;
      
l7_loop:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21830))+8);
      i2 = (OOC_INT32)OOC_SSA__InstrDesc_GetResultStore((OOC_SSA__Instr)i2);
      storeOut = (OOC_SSA__Result)i2;
      i2 = i2!=(OOC_INT32)0;
      if (i2) goto l10;
      i2=0u;
      goto l12;
l10:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21937))+8);
      i3 = (OOC_INT32)destore;
      i2 = OOC_SSA_Destore__StateDesc_ClobberedBy((OOC_SSA_Destore__State)i3, (OOC_SSA__Opnd)i1, (OOC_SSA__Instr)i2);
      
l12:
      if (!i2) goto l14;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21966))+8);
      i3 = (OOC_INT32)get;
      OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i3, 18);
      return;
l14:
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 22621));
      proxy = (OOC_SSA_Blocker__Proxy)i0;
      i2 = i0!=(OOC_INT32)0;
      if (i2) goto l17;
      i2=0u;
      goto l19;
l17:
      i2 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21791)))), &_td_OOC_SSA_Blocker__RegionDesc));
      
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
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22796))+12);
  get = (OOC_SSA__Instr)i0;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l15;
l3_loop:
  i1 = *(OOC_INT8*)((_check_pointer(i0, 22847))+36);
  i1 = i1==12;
  if (i1) goto l6;
  i1=0u;
  goto l8;
l6:
  i1 = (OOC_INT32)OOC_SSA__InstrDesc_GetResultStore((OOC_SSA__Instr)i0);
  i1 = i1==(OOC_INT32)0;
  
l8:
  if (!i1) goto l10;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23002))+16);
  i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 23009)))), &_td_OOC_SSA_Blocker__ProxyDesc, 23009);
  startOfScan = (OOC_SSA_Blocker__Proxy)i1;
  i2 = (OOC_INT32)OOC_SSA__InstrDesc_GetOpndClass((OOC_SSA__Instr)i0, 5);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23190))+24);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23050))+12);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23093))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 23200));
  OOC_SSA_Blocker__AntiDepViolation_ScanBackward((OOC_SSA_Blocker__Region)i3, (OOC_SSA_Blocker__Proxy)i1, (OOC_SSA__Opnd)i2, (OOC_SSA__Result)i0);
  i0 = (OOC_INT32)startOfScan;
  i1 = (OOC_INT32)get;
  i1 = (OOC_INT32)OOC_SSA__InstrDesc_GetOpndClass((OOC_SSA__Instr)i1, 5);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 23249));
  OOC_SSA_Blocker__AntiDepViolation_ScanForward((OOC_SSA_Blocker__Proxy)i0, (OOC_SSA__Opnd)i1);
  i0 = currentId;
  currentId = (i0+1);
l10:
  i0 = (OOC_INT32)get;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23382))+28);
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
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23869))+12);
  instr = (OOC_SSA__Instr)i0;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l20;
l3_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23928))+24);
  opnd = (OOC_SSA__Opnd)i1;
  i2 = i1!=(OOC_INT32)0;
  if (!i2) goto l15;
l6_loop:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23988))+8);
  next = (OOC_SSA__Opnd)i2;
  i3 = *(OOC_INT8*)((_check_pointer(i1, 24017))+4);
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
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24228))+28);
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
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24399))+12);
  instr = (OOC_SSA__Instr)i0;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l19;
l3_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24458))+24);
  opnd = (OOC_SSA__Opnd)i1;
  i2 = i1!=(OOC_INT32)0;
  if (!i2) goto l14;
l6_loop:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 24518))+8);
  next = (OOC_SSA__Opnd)i2;
  i3 = *(OOC_INT8*)((_check_pointer(i1, 24546))+4);
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
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24678))+28);
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
          *(OOC_INT32*)((_check_pointer(i1, 26821))+4) = i0;
          i0 = (OOC_INT32)following;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26893))+72);
          *(OOC_INT32*)(_check_pointer(i1, 26866)) = i2;
          *(OOC_INT32*)((_check_pointer(i0, 26930))+72) = i1;
l4:
          return;
          ;
        }


      i0 = (OOC_INT32)storeIn;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l24;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27065))+12);
      use = (OOC_SSA__Opnd)i0;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l24;
l5_loop:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27127))+12);
      instr = (OOC_SSA__Instr)i0;
      i1 = (OOC_INT32)endOfSearch;
      i2 = i0!=i1;
      if (!i2) goto l18;
      i2 = *(OOC_INT8*)((_check_pointer(i0, 27197))+36);
      i2 = i2==10;
      if (i2) goto l13;
      i2 = (OOC_INT32)OOC_SSA_Blocker__GetProxy((OOC_SSA__Instr)i0);
      p = (OOC_SSA_Blocker__Proxy)i2;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 28412))+28);
      i4 = (OOC_INT32)loop;
      i3 = i3!=i4;
      if (!i3) goto l18;
      *(OOC_INT32*)((_check_pointer(i2, 28462))+28) = i4;
      i0 = (OOC_INT32)OOC_SSA__InstrDesc_GetResultStore((OOC_SSA__Instr)i0);
      i2 = (OOC_INT32)preceedingLoop;
      OOC_SSA_Blocker__ArrangeInstructions_DiscoverLoopStructure((OOC_SSA_Blocker__Loop)i4, (OOC_SSA__Result)i0, (OOC_SSA__Instr)i1, (OOC_SSA_Blocker__Loop)i2);
      goto l18;
l13:
      i0 = (OOC_INT32)OOC_SSA__InstrDesc_GetLoopEnd((OOC_SSA__Instr)i0);
      loopEnd = (OOC_SSA__Instr)i0;
      i0 = (OOC_INT32)OOC_SSA_Blocker__GetProxy((OOC_SSA__Instr)i0);
      p = (OOC_SSA_Blocker__Proxy)i0;
      i0 = _type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 27606)))), &_td_OOC_SSA_Blocker__LoopDesc, 27606);
      loopProxy = (OOC_SSA_Blocker__Loop)i0;
      i1 = (OOC_INT32)preceedingLoop;
      OOC_SSA_Blocker__ArrangeInstructions_DiscoverLoopStructure_RegisterPreceeding((OOC_SSA_Blocker__Loop)i1, (OOC_SSA_Blocker__Loop)i0);
      i0 = (OOC_INT32)instr;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27713))+16);
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
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28740))+16);
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
          _assert((i0!=(OOC_INT32)0), 127, 29223);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29307))+72);
          ptr = (OOC_SSA_Blocker__Preceeds)i1;
          i2 = i1!=(OOC_INT32)0;
          if (i2) goto l3;
          i2=0u;
          goto l5;
l3:
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 29356))+4);
          i2 = *(OOC_UINT8*)((_check_pointer(i2, 29372))+76);
          
l5:
          if (!i2) goto l17;
l8_loop:
          i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 29407));
          ptr = (OOC_SSA_Blocker__Preceeds)i1;
          i2 = i1!=(OOC_INT32)0;
          if (i2) goto l11;
          i2=0u;
          goto l13;
l11:
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 29356))+4);
          i2 = *(OOC_UINT8*)((_check_pointer(i2, 29372))+76);
          
l13:
          if (i2) goto l8_loop;
l17:
          i1 = i1==(OOC_INT32)0;
          if (i1) goto l20;
          i0 = (OOC_INT32)OOC_SSA_Blocker__ArrangeInstructions_SortNestedLoops_GetNext((void*)((_check_pointer(i0, 29623))+64));
          return (OOC_SSA_Blocker__Loop)i0;
          goto l21;
l20:
          best = (OOC_SSA_Blocker__Loop)i0;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29510))+64);
          *list = (OOC_SSA_Blocker__Loop)i1;
          *(OOC_UINT8*)((_check_pointer(i0, 29536))+76) = 1u;
          return (OOC_SSA_Blocker__Loop)i0;
l21:
          _failed_function(29118); return 0;
          ;
        }


      i0 = (OOC_INT32)loop;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29706))+60);
      oldNested = (OOC_SSA_Blocker__Loop)i1;
      *(OOC_INT32*)((_check_pointer(i0, 29731))+60) = (OOC_INT32)0;
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
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 31587))+20);
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
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31850))+12);
          use = (OOC_SSA__Opnd)i4;
          i5 = i4!=(OOC_INT32)0;
          if (!i5) goto l31;
          {register OOC_INT32 h0=i2;i2=i4;i4=h0;}
l10_loop:
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 31932))+12);
          i5 = (OOC_INT32)OOC_SSA_Blocker__GetProxy((OOC_SSA__Instr)i5);
          useProxy = (OOC_SSA_Blocker__Proxy)i5;
          i5 = i5==i3;
          if (i5) goto l13;
          i5=0u;
          goto l19;
l13:
          i5 = *(OOC_INT8*)((_check_pointer(i2, 32001))+4);
          i5 = i5==13;
          if (i5) goto l16;
          i5 = OOC_SSA__OpndDesc_OpndIndex((OOC_SSA__Opnd)i2);
          i5 = i5==2;
          
          goto l19;
l16:
          i5=1u;
l19:
          if (i5) goto l21;
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 32115))+12);
          i5 = OOC_SSA_Blocker__ArrangeInstructions_AttachToLoop_PartOfLoop((OOC_SSA_Blocker__Loop)i3, (OOC_SSA__Instr)i5);
          
          goto l23;
l21:
          i5=1u;
l23:
          if (!i5) goto l26;
          i4 = i4+1;
          inLoopUse = i4;
          
l26:
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 32205))+16);
          use = (OOC_SSA__Opnd)i2;
          i5 = i2!=(OOC_INT32)0;
          if (i5) goto l10_loop;
l30:
          i2=i4;
l31:
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 32255));
          res = (OOC_SSA__Result)i0;
          i4 = i0!=(OOC_INT32)0;
          if (i4) goto l6_loop;
l35:
          i0=i2;
l36:
          *(OOC_INT32*)((_check_pointer(i1, 32305))+20) = i3;
          *(OOC_UINT8*)((_check_pointer(i1, 32351))+24) = (i0!=0);
          i0 = *(OOC_UINT8*)((_check_pointer(i1, 32410))+24);
          if (i0) goto l39;
          i0=0u;
          goto l41;
l39:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 32439))+16);
          i0 = i0==(OOC_INT32)0;
          
l41:
          if (!i0) goto l43;
          *(OOC_INT32*)((_check_pointer(i1, 32626))+16) = i3;
l43:
          i0 = *(OOC_UINT8*)((_check_pointer(i1, 32689))+24);
          return i0;
          goto l45;
l44:
          i0 = *(OOC_UINT8*)((_check_pointer(i1, 31717))+24);
          return i0;
l45:
          _failed_function(30567); return 0;
          ;
        }


      i0 = (OOC_INT32)loop;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l6;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32809))+64);
      OOC_SSA_Blocker__ArrangeInstructions_AttachToLoop((OOC_SSA_Blocker__Loop)i1);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32848))+60);
      OOC_SSA_Blocker__ArrangeInstructions_AttachToLoop((OOC_SSA_Blocker__Loop)i1);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32880))+8);
      i1 = i1!=(OOC_INT32)0;
      if (!i1) goto l6;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32941))+8);
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
          i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 33315));
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 33320))+8);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 33327))+16);
          i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 33334)))), &_td_OOC_SSA_Blocker__ProxyDesc, 33334);
          argProxy = (OOC_SSA_Blocker__Proxy)i1;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 33362))+12);
          i3 = (OOC_INT32)r;
          i2 = i2!=i3;
          if (!i2) goto l30;
          a = (OOC_SSA_Blocker__Proxy)i1;
          i2 = (OOC_INT32)proxy;
          b = (OOC_SSA_Blocker__Proxy)i2;
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 33446))+12);
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 33472))+12);
          i3 = *(OOC_INT32*)((_check_pointer(i3, 33454))+56);
          i4 = *(OOC_INT32*)((_check_pointer(i4, 33480))+56);
          i3 = i3>i4;
          if (i3) goto l5;
          i3=i1;
          goto l11;
l5:
          i3=i1;
l6_loop:
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 33517))+12);
          a = (OOC_SSA_Blocker__Proxy)i3;
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 33446))+12);
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 33472))+12);
          i4 = *(OOC_INT32*)((_check_pointer(i4, 33454))+56);
          i5 = *(OOC_INT32*)((_check_pointer(i5, 33480))+56);
          i4 = i4>i5;
          if (i4) goto l6_loop;
l11:
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 33560))+12);
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 33586))+12);
          i4 = *(OOC_INT32*)((_check_pointer(i4, 33568))+56);
          i5 = *(OOC_INT32*)((_check_pointer(i5, 33594))+56);
          i4 = i4>i5;
          if (!i4) goto l20;
l15_loop:
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 33631))+12);
          b = (OOC_SSA_Blocker__Proxy)i2;
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 33560))+12);
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 33586))+12);
          i4 = *(OOC_INT32*)((_check_pointer(i4, 33568))+56);
          i5 = *(OOC_INT32*)((_check_pointer(i5, 33594))+56);
          i4 = i4>i5;
          if (i4) goto l15_loop;
l20:
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 33674))+12);
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 33686))+12);
          i4 = i4!=i5;
          if (!i4) goto l29;
          {register OOC_INT32 h0=i2;i2=i3;i3=h0;}
l24_loop:
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 33717))+12);
          a = (OOC_SSA_Blocker__Proxy)i2;
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 33745))+12);
          b = (OOC_SSA_Blocker__Proxy)i3;
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 33674))+12);
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 33686))+12);
          i4 = i4!=i5;
          if (i4) goto l24_loop;
l28:
          {register OOC_INT32 h0=i2;i2=i3;i3=h0;}
l29:
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 33781))+8);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 33806))+8);
          OOC_SSA__InstrDesc_AddUniqueOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i3, 20);
l30:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34022))+16);
          argLoop = (OOC_SSA_Blocker__Loop)i1;
          i2 = i1!=0;
          if (i2) goto l33;
          i2=0u;
          goto l35;
l33:
          i2 = (OOC_INT32)proxy;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 34090))+12);
          i2 = OOC_SSA_Blocker__Dominates((OOC_SSA_Blocker__Region)i1, (OOC_SSA_Blocker__Region)i2);
          i2 = !i2;
          
l35:
          if (!i2) goto l53;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34130))+8);
          i2 = *(OOC_INT8*)((_check_pointer(i2, 34137))+36);
          _assert((i2==11), 127, 34115);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34190))+8);
          i1 = (OOC_INT32)OOC_SSA__InstrDesc_NthOpnd((OOC_SSA__Instr)i1, 2);
          exit = (OOC_SSA__Opnd)i1;
          i2 = i1!=0;
          if (i2) goto l39;
          i2=0u;
          goto l41;
l39:
          i2 = *(OOC_INT8*)((_check_pointer(i1, 34248))+4);
          i2 = i2==11;
          
l41:
          if (!i2) goto l53;
l43_loop:
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 34306));
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 34311))+8);
          exitInstr = (OOC_SSA__Instr)i2;
          i3 = *(OOC_INT8*)((_check_pointer(i2, 34349))+36);
          _assert((i3==9), 127, 34332);
          i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 34410));
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 34415))+8);
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i3, 18);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 34479))+16);
          i2 = (OOC_INT32)OOC_SSA__InstrDesc_LastOpnd((OOC_SSA__Instr)i2);
          OOC_SSA_Blocker__ArrangeInstructions_AddRegionDeps_AddOpndDep((OOC_SSA_Blocker__Proxy)(_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 34486)))), &_td_OOC_SSA_Blocker__ProxyDesc, 34486)), (OOC_SSA__Opnd)i2);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34542))+8);
          exit = (OOC_SSA__Opnd)i1;
          i2 = i1!=0;
          if (i2) goto l46;
          i2=0u;
          goto l48;
l46:
          i2 = *(OOC_INT8*)((_check_pointer(i1, 34248))+4);
          i2 = i2==11;
          
l48:
          if (i2) goto l43_loop;
l53:
          return;
          ;
        }


      i0 = (OOC_INT32)r;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34635))+48);
      proxy = (OOC_SSA_Blocker__Proxy)i0;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l36;
l3_loop:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34690))+8);
      i1 = i1!=(OOC_INT32)0;
      if (!i1) goto l28;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34730))+8);
      i1 = *(OOC_INT8*)((_check_pointer(i1, 34737))+36);
      switch (i1) {
      case 5:
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34812))+8);
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34819))+24);
        OOC_SSA_Blocker__ArrangeInstructions_AddRegionDeps_AddOpndDep((OOC_SSA_Blocker__Proxy)i0, (OOC_SSA__Opnd)i1);
        goto l28;
      case 8:
        goto l28;
      case 11:
        goto l28;
      default:
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34985))+8);
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34992))+24);
        opnd = (OOC_SSA__Opnd)i0;
        i1 = i0!=(OOC_INT32)0;
        if (i1) goto l13;
        i1=0u;
        goto l15;
l13:
        i1 = *(OOC_INT8*)((_check_pointer(i0, 35042))+4);
        i1 = i1!=20;
        
l15:
        if (!i1) goto l28;
l17_loop:
        i1 = (OOC_INT32)proxy;
        OOC_SSA_Blocker__ArrangeInstructions_AddRegionDeps_AddOpndDep((OOC_SSA_Blocker__Proxy)i1, (OOC_SSA__Opnd)i0);
        i0 = (OOC_INT32)opnd;
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35144))+8);
        opnd = (OOC_SSA__Opnd)i0;
        i1 = i0!=(OOC_INT32)0;
        if (i1) goto l20;
        i1=0u;
        goto l22;
l20:
        i1 = *(OOC_INT8*)((_check_pointer(i0, 35042))+4);
        i1 = i1!=20;
        
l22:
        if (i1) goto l17_loop;
        goto l28;
      }
l28:
      i0 = (OOC_INT32)proxy;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 35220)))), &_td_OOC_SSA_Blocker__RegionDesc);
      if (!i1) goto l31;
      OOC_SSA_Blocker__ArrangeInstructions_AddRegionDeps((OOC_SSA_Blocker__Region)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 35267)))), &_td_OOC_SSA_Blocker__RegionDesc, 35267)));
l31:
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 35312));
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
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35707))+12);
      i1 = *(OOC_INT8*)((_check_pointer(i1, 35713))+36);
      opcode = i1;
      i2 = i1==8;
      if (i2) goto l7;
      i2 = i1==11;
      if (i2) goto l5;
      i2=0u;
      goto l9;
l5:
      i2 = *(OOC_INT8*)((_check_pointer(i0, 35821))+4);
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
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36068))+8);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36075))+24);
      opnd = (OOC_SSA__Opnd)i0;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l14;
l3_loop:
      i1 = OOC_SSA_Blocker__ArrangeInstructions_IgnoredUse((OOC_SSA__Opnd)i0);
      i1 = !i1;
      if (!i1) goto l9;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 36176));
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 36181))+8);
      defInstr = (OOC_SSA__Instr)i1;
      i2 = *(OOC_INT32*)((_check_pointer(i1, 36213))+20);
      *(OOC_INT32*)((_check_pointer(i1, 36213))+20) = (i2-1);
      i2 = *(OOC_INT32*)((_check_pointer(i1, 36246))+20);
      i2 = i2==0;
      if (!i2) goto l9;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 36293))+16);
      i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 36300)))), &_td_OOC_SSA_Blocker__ProxyDesc, 36300);
      pDef = (OOC_SSA_Blocker__Proxy)i1;
      i2 = (OOC_INT32)waiting;
      OOC_SSA_Blocker__RegionDesc_Remove((OOC_SSA_Blocker__Region)i2, (OOC_SSA_Blocker__Proxy)i1);
      i2 = (OOC_INT32)ready;
      OOC_SSA_Blocker__RegionDesc_Append((OOC_SSA_Blocker__Region)i2, (OOC_SSA_Blocker__Proxy)i1);
l9:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36426))+8);
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
          i2 = *(OOC_INT32*)((_check_pointer(i0, 37232))+56);
          i3 = *(OOC_INT32*)((_check_pointer(i1, 37250))+56);
          i2 = i2>i3;
          if (!i2) goto l9;
l4_loop:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 37285))+12);
          a = (OOC_SSA_Blocker__Region)i0;
          i2 = *(OOC_INT32*)((_check_pointer(i0, 37232))+56);
          i3 = *(OOC_INT32*)((_check_pointer(i1, 37250))+56);
          i2 = i2>i3;
          if (i2) goto l4_loop;
l9:
          i2 = *(OOC_INT32*)((_check_pointer(i1, 37324))+56);
          i3 = *(OOC_INT32*)((_check_pointer(i0, 37342))+56);
          i2 = i2>i3;
          if (!i2) goto l18;
l13_loop:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 37377))+12);
          b = (OOC_SSA_Blocker__Region)i1;
          i2 = *(OOC_INT32*)((_check_pointer(i1, 37324))+56);
          i3 = *(OOC_INT32*)((_check_pointer(i0, 37342))+56);
          i2 = i2>i3;
          if (i2) goto l13_loop;
l18:
          i2 = i0!=i1;
          if (!i2) goto l27;
l22_loop:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 37441))+12);
          a = (OOC_SSA_Blocker__Region)i0;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 37467))+12);
          b = (OOC_SSA_Blocker__Region)i1;
          i2 = i0!=i1;
          if (i2) goto l22_loop;
l27:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 37503))+8);
          i1 = i1!=(OOC_INT32)0;
          if (i1) goto l30;
          i1=0u;
          goto l32;
l30:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 37522))+8);
          i1 = *(OOC_INT8*)((_check_pointer(i1, 37529))+36);
          i1 = i1==5;
          
l32:
          if (!i1) goto l35;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 37576))+12);
          
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
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 37814))+12);
          instr = (OOC_SSA__Instr)i1;
          i2 = *(OOC_INT8*)((_check_pointer(i1, 37840))+36);
          i2 = i2==5;
          if (i2) goto l7;
          i0 = *(OOC_INT8*)((_check_pointer(i1, 38386))+36);
          i0 = i0==11;
          if (i0) goto l5;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 38489))+16);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 38496)))), &_td_OOC_SSA_Blocker__ProxyDesc, 38496)), 38502))+12);
          return (OOC_SSA_Blocker__Region)i0;
          goto l19;
l5:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 38440))+16);
          return (OOC_SSA_Blocker__Region)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 38447)))), &_td_OOC_SSA_Blocker__LoopDesc, 38447));
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
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 38087))+16);
          i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 38094)))), &_td_OOC_SSA_Blocker__SelectDesc, 38094);
          selectProxy = (OOC_SSA_Blocker__Select)i1;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 38130))+60);
          i2 = _check_pointer(i2, 38137);
          i3 = OOC_ARRAY_LENGTH(i2, 0);
          i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i0, i3, OOC_UINT32, 38137))*4);
          i2 = i2==(OOC_INT32)0;
          if (!i2) goto l16;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 38184))+60);
          i2 = _check_pointer(i2, 38191);
          i3 = OOC_ARRAY_LENGTH(i2, 0);
          i4 = (OOC_INT32)OOC_SSA_Blocker__NewRegion((OOC_SSA__Instr)(OOC_INT32)0);
          *(OOC_INT32*)(i2+(_check_index(i0, i3, OOC_UINT32, 38191))*4) = i4;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 38267))+60);
          i2 = _check_pointer(i2, 38274);
          i3 = OOC_ARRAY_LENGTH(i2, 0);
          i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i0, i3, OOC_UINT32, 38274))*4);
          OOC_SSA_Blocker__RegionDesc_Append((OOC_SSA_Blocker__Region)i1, (OOC_SSA_Blocker__Proxy)i2);
l16:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 38333))+60);
          i1 = _check_pointer(i1, 38340);
          i2 = OOC_ARRAY_LENGTH(i1, 0);
          i0 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(i0, i2, OOC_UINT32, 38340))*4);
          return (OOC_SSA_Blocker__Region)i0;
          goto l19;
l17:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 37981))+16);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37988)))), &_td_OOC_SSA_Blocker__ProxyDesc, 37988)), 37994))+12);
          return (OOC_SSA_Blocker__Region)i0;
l19:
          _failed_function(37649); return 0;
          ;
        }

        
        OOC_SSA_Blocker__Region OOC_SSA_Blocker__ArrangeInstructions_GetRegion_CorrectForLoop(OOC_SSA_Blocker__Region region) {
          register OOC_INT32 i0,i1,i2;
          OOC_SSA_Blocker__Loop loopProxy;
          OOC_SSA_Blocker__Proxy ptr;

          i0 = (OOC_INT32)p;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 38693))+16);
          loopProxy = (OOC_SSA_Blocker__Loop)i0;
          i1 = (OOC_INT32)region;
          i2 = i0!=(OOC_INT32)0;
          if (!i2) goto l11;
l3_loop:
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 38767))+12);
          ptr = (OOC_SSA_Blocker__Proxy)i2;
          i2 = i2==i1;
          if (!i2) goto l6;
          return (OOC_SSA_Blocker__Region)i0;
l6:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 38887))+68);
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
          i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 39159)))), &_td_OOC_SSA_Blocker__LoopDesc));
          
l5:
          if (i1) goto l7;
          i1=i0;
          goto l17;
l7:
          i1=i0;
l8_loop:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 39191))+12);
          ptr = (OOC_SSA_Blocker__Region)i1;
          i2 = i1!=(OOC_INT32)0;
          if (i2) goto l11;
          i2=0u;
          goto l13;
l11:
          i2 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 39159)))), &_td_OOC_SSA_Blocker__LoopDesc));
          
l13:
          if (i2) goto l8_loop;
l17:
          i2 = (OOC_INT32)p;
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 39341))+16);
          lowerBound = (OOC_SSA_Blocker__Region)i3;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 39367))+16);
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
          i0 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 39659)))), &_td_OOC_SSA_Blocker__LoopDesc, 39659);
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
          i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 39738)))), &_td_OOC_SSA_Blocker__LoopDesc);
          if (!i3) goto l40;
          i1 = _type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 39782)))), &_td_OOC_SSA_Blocker__LoopDesc, 39782);
          lastLoop = (OOC_SSA_Blocker__Loop)i1;
          
l40:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 39828))+12);
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
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 39999))+12);
          
l50:
          return (OOC_SSA_Blocker__Region)i0;
          ;
        }


      i0 = (OOC_INT32)p;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 40097))+8);
      i1 = *(OOC_INT8*)((_check_pointer(i1, 40104))+36);
      i1 = i1==10;
      if (i1) goto l43;
      region = (OOC_SSA_Blocker__Region)(OOC_INT32)0;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 40377))+8);
      res = (OOC_SSA__Result)i1;
      i2 = i1!=(OOC_INT32)0;
      if (!i2) goto l35;
      {register OOC_INT32 h0=i0;i0=i1;i1=h0;}
l6_loop:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 40435))+12);
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
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 40580))+16);
      i2 = i2==(OOC_INT32)0;
      if (i2) goto l16;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 40631))+16);
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
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 41169))+16);
      use = (OOC_SSA__Opnd)i1;
      i2 = i1!=(OOC_INT32)0;
      if (!i2) goto l30;
      {register OOC_INT32 h0=i0;i0=i1;i1=h0;}
      goto l10_loop;
l30:
      i1 = (OOC_INT32)res;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 41215));
      res = (OOC_SSA__Result)i1;
      i2 = i1!=(OOC_INT32)0;
      if (!i2) goto l35;
      {register OOC_INT32 h0=i0;i0=i1;i1=h0;}
      goto l6_loop;
l35:
      i1 = (OOC_INT32)region;
      i2 = i1==(OOC_INT32)0;
      if (i2) goto l41;
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 41338)))), &_td_OOC_SSA_Blocker__SelectDesc);
      if (!i2) goto l44;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 41414))+12);
      region = (OOC_SSA_Blocker__Region)i1;
      goto l44;
l41:
      i1 = (OOC_INT32)root;
      region = (OOC_SSA_Blocker__Region)i1;
      goto l44;
l43:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 40266))+8);
      i1 = (OOC_INT32)OOC_SSA__InstrDesc_GetLoopEnd((OOC_SSA__Instr)i1);
      loopEnd = (OOC_SSA__Instr)i1;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 40311))+16);
      return (OOC_SSA_Blocker__Region)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 40318)))), &_td_OOC_SSA_Blocker__RegionDesc, 40318));
      
l44:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 41460))+8);
      i0 = *(OOC_INT8*)((_check_pointer(i0, 41467))+36);
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
      _failed_function(36482); return 0;
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
          register OOC_INT32 i0,i1,i2;

          i0 = (OOC_INT32)proxy;
          *(OOC_INT32*)((_check_pointer(i0, 42186))+4) = (OOC_INT32)0;
          i1 = (OOC_INT32)*list;
          *(OOC_INT32*)(_check_pointer(i0, 42219)) = i1;
          i1 = (OOC_INT32)*list;
          i2 = i1!=(OOC_INT32)0;
          if (!i2) goto l4;
          *(OOC_INT32*)((_check_pointer(i1, 42283))+4) = i0;
l4:
          *list = (OOC_SSA_Blocker__Proxy)i0;
          return;
          ;
        }

        
        void OOC_SSA_Blocker__ArrangeInstructions_SortRegion_Remove(OOC_SSA_Blocker__Proxy *list, OOC_SSA_Blocker__Proxy proxy) {
          register OOC_INT32 i0,i1,i2;

          i0 = (OOC_INT32)proxy;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 42440))+4);
          i1 = i1==(OOC_INT32)0;
          if (i1) goto l3;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 42526))+4);
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 42555));
          *(OOC_INT32*)(_check_pointer(i1, 42536)) = i2;
          goto l4;
l3:
          i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 42486));
          *list = (OOC_SSA_Blocker__Proxy)i1;
l4:
          i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 42597));
          i1 = i1!=(OOC_INT32)0;
          if (!i1) goto l7;
          i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 42635));
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 42664))+4);
          *(OOC_INT32*)((_check_pointer(i1, 42645))+4) = i0;
l7:
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
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 42950))+48);
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
              i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 43042));
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
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 43205))+48);
              return (i0==(OOC_INT32)0);
              ;
            }

            
            OOC_CHAR8 OOC_SSA_Blocker__ArrangeInstructions_SortRegion_GetLength_IsExit(OOC_SSA_Blocker__Region region) {
              register OOC_INT32 i0,i1;

              i0 = (OOC_INT32)region;
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 43335))+48);
              i1 = i1!=(OOC_INT32)0;
              if (i1) goto l3;
              i1=0u;
              goto l5;
l3:
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 43372))+48);
              i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 43378));
              i1 = i1==(OOC_INT32)0;
              
l5:
              if (i1) goto l7;
              i0=0u;
              goto l8;
l7:
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 43419))+48);
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 43425))+8);
              i0 = *(OOC_INT8*)((_check_pointer(i0, 43431))+36);
              i0 = i0==9;
              
l8:
              return i0;
              ;
            }


          i0 = (OOC_INT32)proxy;
          i1 = *(OOC_INT32*)((_check_pointer(i0, 43511))+36);
          i1 = i1<0;
          if (!i1) goto l36;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 43550)))), &_td_OOC_SSA_Blocker__SelectDesc);
          if (i1) goto l14;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 44133)))), &_td_OOC_SSA_Blocker__RegionDesc);
          if (i1) goto l12;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 44220))+8);
          i0 = *(OOC_INT8*)((_check_pointer(i0, 44227))+36);
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
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 43587))+60);
          i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 43593)), 0);
          i1 = i1==2;
          if (i1) goto l17;
          i1=0u;
          goto l31;
l17:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 43633))+60);
          i1 = _check_pointer(i1, 43639);
          i2 = OOC_ARRAY_LENGTH(i1, 0);
          i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 43639))*4);
          i1 = OOC_SSA_Blocker__ArrangeInstructions_SortRegion_GetLength_IsEmpty((OOC_SSA_Blocker__Region)i1);
          if (i1) goto l20;
          i1=0u;
          goto l22;
l20:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 43658))+60);
          i1 = _check_pointer(i1, 43664);
          i2 = OOC_ARRAY_LENGTH(i1, 0);
          i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(1, i2, OOC_UINT8, 43664))*4);
          i1 = OOC_SSA_Blocker__ArrangeInstructions_SortRegion_GetLength_IsExit((OOC_SSA_Blocker__Region)i1);
          
l22:
          if (i1) goto l28;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 43703))+60);
          i1 = _check_pointer(i1, 43709);
          i2 = OOC_ARRAY_LENGTH(i1, 0);
          i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(1, i2, OOC_UINT8, 43709))*4);
          i1 = OOC_SSA_Blocker__ArrangeInstructions_SortRegion_GetLength_IsEmpty((OOC_SSA_Blocker__Region)i1);
          if (i1) goto l26;
          i1=0u;
          goto l31;
l26:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 43728))+60);
          i1 = _check_pointer(i1, 43734);
          i2 = OOC_ARRAY_LENGTH(i1, 0);
          i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 43734))*4);
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
          *(OOC_INT32*)((_check_pointer(i1, 44403))+36) = i0;
l36:
          i0 = (OOC_INT32)proxy;
          i0 = *(OOC_INT32*)((_check_pointer(i0, 44451))+36);
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
              i1 = *(OOC_INT8*)((_check_pointer(i0, 44817))+5);
              i1 = i1==0;
              if (i1) goto l3;
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 44864))+8);
              i1 = *(OOC_INT8*)((_check_pointer(i1, 44870))+36);
              i1 = i1==13;
              
              goto l5;
l3:
              i1=1u;
l5:
              if (i1) goto l11;
              i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 45120)))), &_td_OOC_SSA__InstrDesc));
              if (i1) goto l9;
              i0 = OOC_SSA__InstrDesc_IsConst((OOC_SSA__Instr)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 45146)))), &_td_OOC_SSA__InstrDesc, 45146)));
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
              _failed_function(44742); return 0;
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
          i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 45351));
          *list = (OOC_SSA_Blocker__Proxy)i1;
          degreeDiff = 0;
          useCount = 0;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 45447))+8);
          i1 = i1!=(OOC_INT32)0;
          if (!i1) goto l51;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 45553))+8);
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
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 45716));
          res = (OOC_SSA__Result)i0;
          i1 = i0!=(OOC_INT32)0;
          if (i1) goto l8_loop;
l16:
          i0 = (OOC_INT32)proxy;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 45772))+8);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 45779))+24);
          opnd = (OOC_SSA__Opnd)i0;
          i1 = i0!=(OOC_INT32)0;
          if (!i1) goto l31;
l19_loop:
          i1 = OOC_SSA__OpndDesc_IsValueOpndHere((OOC_SSA__Opnd)i0);
          if (i1) goto l22;
          i0=0u;
          goto l24;
l22:
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 45889));
          i0 = OOC_SSA_Blocker__ArrangeInstructions_SortRegion_CalculateWeight_CountAsRegister((OOC_SSA__Result)i0);
          
l24:
          if (!i0) goto l26;
          i0 = degreeDiff;
          degreeDiff = (i0-1);
l26:
          i0 = (OOC_INT32)opnd;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 45980))+8);
          opnd = (OOC_SSA__Opnd)i0;
          i1 = i0!=(OOC_INT32)0;
          if (i1) goto l19_loop;
l31:
          i0 = (OOC_INT32)proxy;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 46112))+8);
          res = (OOC_SSA__Result)i0;
          i1 = i0!=(OOC_INT32)0;
          if (!i1) goto l51;
          i1 = (OOC_INT32)r;
          
l34_loop:
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 46178))+12);
          use = (OOC_SSA__Opnd)i2;
          i3 = i2!=(OOC_INT32)0;
          if (!i3) goto l45;
l37_loop:
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 46247))+12);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 46254))+16);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 46261)))), &_td_OOC_SSA_Blocker__ProxyDesc, 46261)), 46267))+12);
          i3 = i3==i1;
          if (!i3) goto l40;
          i3 = useCount;
          useCount = (i3+1);
l40:
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 46367))+16);
          use = (OOC_SSA__Opnd)i2;
          i3 = i2!=(OOC_INT32)0;
          if (i3) goto l37_loop;
l45:
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 46421));
          res = (OOC_SSA__Result)i0;
          i2 = i0!=(OOC_INT32)0;
          if (i2) goto l34_loop;
l51:
          i0 = (OOC_INT32)proxy;
          i1 = degreeDiff;
          *(OOC_INT32*)((_check_pointer(i0, 46482))+44) = i1;
          i1 = useCount;
          *(OOC_INT32*)((_check_pointer(i0, 46525))+32) = i1;
          i1 = i1==0;
          if (i1) goto l54;
          OOC_SSA_Blocker__ArrangeInstructions_SortRegion_Add((void*)(OOC_INT32)&waiting, (OOC_SSA_Blocker__Proxy)i0);
          goto l55;
l54:
          i1 = *(OOC_INT32*)((_check_pointer(i0, 46616))+36);
          *(OOC_INT32*)((_check_pointer(i0, 46597))+40) = i1;
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
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 46901))+8);
          i1 = i1!=(OOC_INT32)0;
          if (i1) goto l66;
          i1=0u;i2=0;
          goto l115;
l66:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 46945))+8);
          res = (OOC_SSA__Result)i1;
          i2 = i1!=(OOC_INT32)0;
          if (i2) goto l69;
          i1=0u;i2=0;
          goto l100;
l69:
          i2 = (OOC_INT32)r;
          i3=0;i4=0u;
l70_loop:
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 47011))+12);
          use = (OOC_SSA__Opnd)i5;
          i6 = i5!=(OOC_INT32)0;
          if (!i6) goto l95;
          {register OOC_INT32 h0=i3;i3=i5;i5=i4;i4=h0;}
l74_loop:
          i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 47088))+12);
          i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 47095))+16);
          i6 = _type_guard(i6, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 47102)))), &_td_OOC_SSA_Blocker__ProxyDesc, 47102);
          useProxy = (OOC_SSA_Blocker__Proxy)i6;
          i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 47138))+12);
          i7 = i7==i2;
          if (i7) goto l77;
          i7=0u;
          goto l79;
l77:
          i7 = *(OOC_INT32*)((_check_pointer(i6, 47163))+40);
          i7 = i7>i4;
          
l79:
          if (!i7) goto l82;
          i4 = *(OOC_INT32*)((_check_pointer(i6, 47219))+40);
          max = i4;
          
l82:
          i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 47275))+12);
          i6 = *(OOC_INT8*)((_check_pointer(i6, 47281))+36);
          i6 = i6==5;
          if (i6) goto l85;
          i6=0u;
          goto l87;
l85:
          i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 47331))+12);
          i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 47337))+24);
          i6 = i6==i3;
          
l87:
          if (!i6) goto l90;
          selectingValue = 1u;
          i5=1u;
l90:
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 47448))+16);
          use = (OOC_SSA__Opnd)i3;
          i6 = i3!=(OOC_INT32)0;
          if (i6) goto l74_loop;
l94:
          i3=i4;i4=i5;
l95:
          i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 47502));
          res = (OOC_SSA__Result)i1;
          i5 = i1!=(OOC_INT32)0;
          if (i5) goto l70_loop;
l99:
          i1=i4;i2=i3;
l100:
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 47575))+8);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 47582))+24);
          opnd = (OOC_SSA__Opnd)i3;
          i4 = i3!=(OOC_INT32)0;
          if (!i4) goto l115;
l103_loop:
          i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 47658));
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 47663))+8);
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 47670))+16);
          i4 = _type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 47677)))), &_td_OOC_SSA_Blocker__ProxyDesc, 47677);
          defProxy = (OOC_SSA_Blocker__Proxy)i4;
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 47711))+12);
          i6 = (OOC_INT32)r;
          i5 = i5==i6;
          if (!i5) goto l109;
          i5 = *(OOC_INT32*)((_check_pointer(i4, 47759))+32);
          *(OOC_INT32*)((_check_pointer(i4, 47759))+32) = (i5-1);
          i5 = *(OOC_INT32*)((_check_pointer(i4, 47798))+32);
          i5 = i5==0;
          if (!i5) goto l109;
          OOC_SSA_Blocker__ArrangeInstructions_SortRegion_Remove((void*)(OOC_INT32)&waiting, (OOC_SSA_Blocker__Proxy)i4);
          OOC_SSA_Blocker__ArrangeInstructions_SortRegion_Add((void*)(OOC_INT32)&ready, (OOC_SSA_Blocker__Proxy)i4);
l109:
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 47970))+8);
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
          *(OOC_INT32*)((_check_pointer(i0, 48289))+40) = i1;
          i1 = (OOC_INT32)*list;
          *(OOC_INT32*)(_check_pointer(i0, 48334)) = i1;
          *list = (OOC_SSA_Blocker__Proxy)i0;
          i0 = (OOC_INT32)ready;
          i0 = i0!=(OOC_INT32)0;
          if (i0) goto l63_loop;
l124:
          i0 = (OOC_INT32)waiting;
          _assert((i0==(OOC_INT32)0), 127, 48401);
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
          i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 48678));
          *head = (OOC_SSA_Blocker__Proxy)i1;
          opndCount = 0;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 48871))+8);
          i2 = i2!=(OOC_INT32)0;
          if (i2) goto l6;
          i2=0;
          goto l20;
l6:
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 48916))+8);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 48923))+24);
          opnd = (OOC_SSA__Opnd)i2;
          i3 = i2!=(OOC_INT32)0;
          if (i3) goto l9;
          i2=0;
          goto l19;
l9:
          i3 = (OOC_INT32)r;
          i4=0;
l10_loop:
          i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 48991));
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 48996))+8);
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 49003))+16);
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i5, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 49010)))), &_td_OOC_SSA_Blocker__ProxyDesc, 49010)), 49016))+12);
          i5 = i5==i3;
          if (!i5) goto l14;
          i4 = i4+1;
          opndCount = i4;
          
l14:
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 49113))+8);
          opnd = (OOC_SSA__Opnd)i2;
          i5 = i2!=(OOC_INT32)0;
          if (i5) goto l10_loop;
l18:
          i2=i4;
l19:
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 49159))+8);
          *(OOC_INT32*)((_check_pointer(i3, 49166))+20) = i2;
          
l20:
          i2 = i2==0;
          if (i2) goto l23;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 49310))+8);
          _assert((i2!=(OOC_INT32)0), 127, 49297);
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
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 49629))+12);
          use = (OOC_SSA__Opnd)i1;
          i2 = i1!=(OOC_INT32)0;
          if (!i2) goto l17;
l6_loop:
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 49698))+12);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 49705))+16);
          i2 = _type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 49712)))), &_td_OOC_SSA_Blocker__ProxyDesc, 49712);
          useProxy = (OOC_SSA_Blocker__Proxy)i2;
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 49744))+12);
          i4 = (OOC_INT32)r;
          i3 = i3==i4;
          if (!i3) goto l12;
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 49785))+12);
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 49785))+12);
          i4 = *(OOC_INT32*)((_check_pointer(i4, 49792))+20);
          *(OOC_INT32*)((_check_pointer(i3, 49792))+20) = (i4-1);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 49824))+12);
          i3 = *(OOC_INT32*)((_check_pointer(i3, 49831))+20);
          i3 = i3==0;
          if (!i3) goto l12;
          OOC_SSA_Blocker__ArrangeInstructions_SortRegion_Remove((void*)(OOC_INT32)&waiting, (OOC_SSA_Blocker__Proxy)i2);
          OOC_SSA_Blocker__ArrangeInstructions_SortRegion_Add((void*)(OOC_INT32)&ready, (OOC_SSA_Blocker__Proxy)i2);
l12:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 49991))+16);
          use = (OOC_SSA__Opnd)i1;
          i2 = i1!=(OOC_INT32)0;
          if (i2) goto l6_loop;
l17:
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 50037));
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
          i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 50222));
          ready = (OOC_SSA_Blocker__Proxy)i1;
          i2 = i1!=0;
          if (!i2) goto l21;
          {register OOC_INT32 h0=i0;i0=i1;i1=h0;}
l4_loop:
          i2 = *(OOC_INT32*)((_check_pointer(i0, 50285))+40);
          i3 = *(OOC_INT32*)((_check_pointer(i1, 50302))+40);
          i2 = i2>i3;
          if (i2) goto l11;
          i2 = *(OOC_INT32*)((_check_pointer(i0, 50336))+40);
          i3 = *(OOC_INT32*)((_check_pointer(i1, 50353))+40);
          i2 = i2==i3;
          if (i2) goto l9;
          i2=0u;
          goto l13;
l9:
          i2 = *(OOC_INT32*)((_check_pointer(i0, 50388))+44);
          i3 = *(OOC_INT32*)((_check_pointer(i1, 50407))+44);
          i2 = i2<i3;
          
          goto l13;
l11:
          i2=1u;
l13:
          if (!i2) goto l16;
          best = (OOC_SSA_Blocker__Proxy)i0;
          i1=i0;
l16:
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 50492));
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
      *(OOC_INT32*)((_check_pointer(i0, 50876))+52) = (OOC_INT32)0;
      OOC_SSA_Blocker__ArrangeInstructions_SortRegion_CalculateWeight((void*)((_check_pointer(i0, 50915))+48));
      i0 = (OOC_INT32)r;
      OOC_SSA_Blocker__ArrangeInstructions_SortRegion_CountLocalUses((void*)((_check_pointer(i0, 50948))+48));
      i0 = (OOC_INT32)ready;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l8;
l3_loop:
      i0 = (OOC_INT32)OOC_SSA_Blocker__ArrangeInstructions_SortRegion_NextInstr((OOC_SSA_Blocker__Proxy)i0);
      proxy = (OOC_SSA_Blocker__Proxy)i0;
      OOC_SSA_Blocker__ArrangeInstructions_SortRegion_Remove((void*)(OOC_INT32)&ready, (OOC_SSA_Blocker__Proxy)i0);
      i0 = (OOC_INT32)proxy;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 51205))+8);
      OOC_SSA_Blocker__ArrangeInstructions_SortRegion_UpdateUses((OOC_SSA__Instr)i0);
      i0 = (OOC_INT32)proxy;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 51236))+12);
      i2 = (OOC_INT32)r;
      _assert((i1==i2), 127, 51223);
      *(OOC_INT32*)((_check_pointer(i0, 51264))+12) = (OOC_INT32)0;
      OOC_SSA_Blocker__RegionDesc_Append((OOC_SSA_Blocker__Region)i2, (OOC_SSA_Blocker__Proxy)i0);
      i0 = (OOC_INT32)ready;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l3_loop;
l8:
      i0 = (OOC_INT32)waiting;
      _assert((i0==(OOC_INT32)0), 127, 51325);
      i0 = (OOC_INT32)r;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 51366))+48);
      ready = (OOC_SSA_Blocker__Proxy)i0;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l19;
l11_loop:
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 51422)))), &_td_OOC_SSA_Blocker__RegionDesc);
      if (!i1) goto l14;
      OOC_SSA_Blocker__ArrangeInstructions_SortRegion((OOC_SSA_Blocker__Region)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 51466)))), &_td_OOC_SSA_Blocker__RegionDesc, 51466)));
l14:
      i0 = (OOC_INT32)ready;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 51511));
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
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 51639))+48);
      p = (OOC_SSA_Blocker__Proxy)i1;
      i2 = i1!=(OOC_INT32)0;
      if (!i2) goto l15;
l3_loop:
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 51687)))), &_td_OOC_SSA_Blocker__RegionDesc);
      if (i2) goto l6;
      *(OOC_INT32*)((_check_pointer(i1, 51836))+12) = (OOC_INT32)0;
      goto l10;
l6:
      OOC_SSA_Blocker__ArrangeInstructions_ClearRegion((OOC_SSA_Blocker__Region)i1);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 51742))+12);
      i2 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 51751)))), &_td_OOC_SSA_Blocker__SelectDesc));
      if (!i2) goto l10;
      *(OOC_INT32*)((_check_pointer(i1, 51780))+12) = (OOC_INT32)0;
l10:
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 51880));
      p = (OOC_SSA_Blocker__Proxy)i1;
      i2 = i1!=(OOC_INT32)0;
      if (i2) goto l3_loop;
l15:
      i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 51917)))), &_td_OOC_SSA_Blocker__SelectDesc));
      if (!i1) goto l18;
      *(OOC_INT32*)((_check_pointer(i0, 51942))+48) = (OOC_INT32)0;
      *(OOC_INT32*)((_check_pointer(i0, 51967))+52) = (OOC_INT32)0;
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
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 52853))+12);
  instr = (OOC_SSA__Instr)i0;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l32;
l4_loop:
  useCount = 0;
  res = (OOC_SSA__Result)i0;
  if (!i1) goto l23;
l7_loop:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 52989))+12);
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
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 53138))+16);
  use = (OOC_SSA__Opnd)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l10_loop;
l18:
  i0 = (OOC_INT32)res;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 53184));
  res = (OOC_SSA__Result)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l7_loop;
l23:
  i0 = (OOC_INT32)instr;
  i1 = (OOC_INT32)OOC_SSA_Blocker__GetProxy((OOC_SSA__Instr)i0);
  p = (OOC_SSA_Blocker__Proxy)i1;
  i2 = useCount;
  *(OOC_INT32*)((_check_pointer(i0, 53264))+20) = i2;
  i2 = i2==0;
  if (i2) goto l26;
  i2 = (OOC_INT32)waiting;
  OOC_SSA_Blocker__RegionDesc_Append((OOC_SSA_Blocker__Region)i2, (OOC_SSA_Blocker__Proxy)i1);
  goto l27;
l26:
  i2 = (OOC_INT32)ready;
  OOC_SSA_Blocker__RegionDesc_Append((OOC_SSA_Blocker__Region)i2, (OOC_SSA_Blocker__Proxy)i1);
l27:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 53425))+28);
  instr = (OOC_SSA__Instr)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l4_loop;
l32:
  i0 = (OOC_INT32)ready;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 53618))+48);
  p = (OOC_SSA_Blocker__Proxy)i1;
  i2 = i1!=(OOC_INT32)0;
  if (i2) goto l35;
  i2=0u;
  goto l37;
l35:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 53653))+8);
  i2 = *(OOC_INT8*)((_check_pointer(i2, 53660))+36);
  i2 = i2!=8;
  
l37:
  if (!i2) goto l49;
l40_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 53709));
  p = (OOC_SSA_Blocker__Proxy)i1;
  i2 = i1!=(OOC_INT32)0;
  if (i2) goto l43;
  i2=0u;
  goto l45;
l43:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 53653))+8);
  i2 = *(OOC_INT8*)((_check_pointer(i2, 53660))+36);
  i2 = i2!=8;
  
l45:
  if (i2) goto l40_loop;
l49:
  OOC_SSA_Blocker__RegionDesc_Remove((OOC_SSA_Blocker__Region)i0, (OOC_SSA_Blocker__Proxy)i1);
  root = (OOC_SSA_Blocker__Region)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 53774)))), &_td_OOC_SSA_Blocker__RegionDesc, 53774));
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 54006))+48);
  i0 = i0!=(OOC_INT32)0;
  if (!i0) goto l56;
l51_loop:
  i0 = (OOC_INT32)ready;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 54042))+48);
  p = (OOC_SSA_Blocker__Proxy)i1;
  OOC_SSA_Blocker__RegionDesc_Remove((OOC_SSA_Blocker__Region)i0, (OOC_SSA_Blocker__Proxy)i1);
  OOC_SSA_Blocker__ArrangeInstructions_UpdateDefs((OOC_SSA_Blocker__Proxy)i1);
  i0 = (OOC_INT32)p;
  i0 = (OOC_INT32)OOC_SSA_Blocker__ArrangeInstructions_GetRegion((OOC_SSA_Blocker__Proxy)i0);
  region = (OOC_SSA_Blocker__Region)i0;
  i1 = (OOC_INT32)p;
  OOC_SSA_Blocker__RegionDesc_Insert((OOC_SSA_Blocker__Region)i0, (OOC_SSA_Blocker__Proxy)i1);
  i0 = (OOC_INT32)ready;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 54006))+48);
  i0 = i0!=(OOC_INT32)0;
  if (i0) goto l51_loop;
l56:
  i0 = (OOC_INT32)waiting;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 54204))+48);
  _assert((i0==(OOC_INT32)0), 127, 54189);
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
  *(OOC_INT32*)(_check_pointer(i0, 55057)) = i2;
  i2 = (OOC_INT32)ADT_Dictionary__New();
  proxyMap = (ADT_Dictionary__Dictionary)i2;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 55154))+12);
  instr = (OOC_SSA__Instr)i1;
  i3 = i1!=0;
  if (!i3) goto l8;
l3_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 55227))+16);
  ADT_Dictionary__DictionaryDesc_Set((ADT_Dictionary__Dictionary)i2, (Object__Object)i1, (Object__Object)(_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 55234)))), &_td_OOC_SSA_Blocker__ProxyDesc, 55234)));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 55263))+28);
  instr = (OOC_SSA__Instr)i1;
  i3 = i1!=0;
  if (i3) goto l3_loop;
l8:
  *(OOC_INT32*)((_check_pointer(i0, 55291))+4) = i2;
  return (OOC_SSA_Blocker__DependenceData)i0;
  ;
}

OOC_CHAR8 OOC_SSA_Blocker__DependenceDataDesc_SameRegion(OOC_SSA_Blocker__DependenceData dd, OOC_SSA__Instr x, OOC_SSA__Instr y) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)x;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 55533))+16);
  i1 = (OOC_INT32)y;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 55556))+16);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 55539)))), &_td_OOC_SSA_Blocker__ProxyDesc, 55539)), 55545))+12);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 55562)))), &_td_OOC_SSA_Blocker__ProxyDesc, 55562)), 55568))+12);
  return (i0==i1);
  ;
}

OOC_CHAR8 OOC_SSA_Blocker__DependenceDataDesc_Dominates(OOC_SSA_Blocker__DependenceData dd, OOC_SSA__Instr x, OOC_SSA__Instr y) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)x;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 55784))+16);
  i1 = (OOC_INT32)y;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 55806))+16);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 55790)))), &_td_OOC_SSA_Blocker__ProxyDesc, 55790)), 55796))+12);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 55812)))), &_td_OOC_SSA_Blocker__ProxyDesc, 55812)), 55818))+12);
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
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 55980))+4);
  i2 = (OOC_INT32)x;
  i1 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i1, (Object__Object)i2);
  p = (Object__Object)i1;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 56012)))), &_td_OOC_SSA_Blocker__ProxyDesc, 56012)), 56018))+12);
  a = (OOC_SSA_Blocker__Region)i1;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 56039))+4);
  i2 = (OOC_INT32)y;
  i0 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i0, (Object__Object)i2);
  p = (Object__Object)i0;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 56071)))), &_td_OOC_SSA_Blocker__ProxyDesc, 56071)), 56077))+12);
  b = (OOC_SSA_Blocker__Region)i0;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 56104))+56);
  i3 = *(OOC_INT32*)((_check_pointer(i0, 56122))+56);
  i2 = i2>i3;
  if (!i2) goto l9;
l4_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 56153))+12);
  a = (OOC_SSA_Blocker__Region)i1;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 56104))+56);
  i3 = *(OOC_INT32*)((_check_pointer(i0, 56122))+56);
  i2 = i2>i3;
  if (i2) goto l4_loop;
l9:
  i2 = *(OOC_INT32*)((_check_pointer(i0, 56184))+56);
  i3 = *(OOC_INT32*)((_check_pointer(i1, 56202))+56);
  i2 = i2>i3;
  if (!i2) goto l18;
l13_loop:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 56233))+12);
  b = (OOC_SSA_Blocker__Region)i0;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 56184))+56);
  i3 = *(OOC_INT32*)((_check_pointer(i1, 56202))+56);
  i2 = i2>i3;
  if (i2) goto l13_loop;
l18:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 56264))+12);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 56276))+12);
  i2 = i2!=i3;
  if (i2) goto l21;
  {register OOC_INT32 h0=i0;i0=i1;i1=h0;}
  goto l27;
l21:
  {register OOC_INT32 h0=i0;i0=i1;i1=h0;}
l22_loop:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 56301))+12);
  a = (OOC_SSA_Blocker__Region)i0;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 56323))+12);
  b = (OOC_SSA_Blocker__Region)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 56264))+12);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 56276))+12);
  i2 = i2!=i3;
  if (i2) goto l22_loop;
l27:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 56355))+12);
  i2 = i2!=(OOC_INT32)0;
  if (i2) goto l30;
  i2=0u;
  goto l32;
l30:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 56375))+12);
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 56384)))), &_td_OOC_SSA_Blocker__SelectDesc);
  
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
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 56894))+12);
      use = (OOC_SSA__Opnd)i1;
      i2 = i1!=(OOC_INT32)0;
      if (!i2) goto l21;
l6_loop:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 56968))+12);
      i3 = (OOC_INT32)visited;
      i2 = ADT_Dictionary__DictionaryDesc_HasKey((ADT_Dictionary__Dictionary)i3, (Object__Object)i2);
      i2 = !i2;
      if (!i2) goto l16;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 57011))+12);
      i3 = (OOC_INT32)visited;
      ADT_Dictionary__DictionaryDesc_Set((ADT_Dictionary__Dictionary)i3, (Object__Object)i2, (Object__Object)(OOC_INT32)0);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 57045))+12);
      i3 = (OOC_INT32)x;
      i2 = i2==i3;
      if (i2) goto l11;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 57078))+12);
      i2 = OOC_SSA_Blocker__DependenceDataDesc_DependsOn_PassesResult((OOC_SSA__Result)i2);
      
      goto l13;
l11:
      i2=1u;
l13:
      if (!i2) goto l16;
      return 1u;
l16:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 57171))+16);
      use = (OOC_SSA__Opnd)i1;
      i2 = i1!=(OOC_INT32)0;
      if (i2) goto l6_loop;
l21:
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 57213));
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
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 57878))+16);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 57885)))), &_td_OOC_SSA_Blocker__ProxyDesc, 57885)), 57891))+16);
  xLoop = (OOC_SSA_Blocker__Loop)i1;
  i2 = i1!=(OOC_INT32)0;
  if (i2) goto l3;
  i2=0u;
  goto l4;
l3:
  i2 = (OOC_INT32)y;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 57950))+16);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 57957)))), &_td_OOC_SSA_Blocker__ProxyDesc, 57957)), 57963))+12);
  i2 = OOC_SSA_Blocker__Dominates((OOC_SSA_Blocker__Region)i1, (OOC_SSA_Blocker__Region)i2);
  i2 = !i2;
  
l4:
  i3 = (OOC_INT32)y;
  if (!i2) goto l36;
  i2 = (OOC_INT32)dd;
  {register OOC_INT32 h0=i0;i0=i1;i1=h0;}
l8_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 57995))+8);
  i4 = (OOC_INT32)OOC_SSA__InstrDesc_NthOpnd((OOC_SSA__Instr)i4, 2);
  exit = (OOC_SSA__Opnd)i4;
  i5 = i4!=(OOC_INT32)0;
  if (i5) goto l11;
  i5=0u;
  goto l13;
l11:
  i5 = *(OOC_INT8*)((_check_pointer(i4, 58049))+4);
  i5 = i5==11;
  
l13:
  if (!i5) goto l27;
l15_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 58119));
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 58124))+8);
  i5 = OOC_SSA_Blocker__DependenceDataDesc_AvailableTo((OOC_SSA_Blocker__DependenceData)i2, (OOC_SSA__Instr)i1, (OOC_SSA__Instr)i5);
  i5 = !i5;
  if (!i5) goto l18;
  return 0u;
l18:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 58322))+8);
  exit = (OOC_SSA__Opnd)i4;
  i5 = i4!=(OOC_INT32)0;
  if (i5) goto l21;
  i5=0u;
  goto l23;
l21:
  i5 = *(OOC_INT8*)((_check_pointer(i4, 58049))+4);
  i5 = i5==11;
  
l23:
  if (i5) goto l15_loop;
l27:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 58366))+8);
  xValue = (OOC_SSA__Instr)i1;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 58395))+16);
  xLoop = (OOC_SSA_Blocker__Loop)i0;
  i4 = i0!=(OOC_INT32)0;
  if (i4) goto l30;
  i4=0u;
  goto l32;
l30:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 57950))+16);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 57957)))), &_td_OOC_SSA_Blocker__ProxyDesc, 57957)), 57963))+12);
  i4 = OOC_SSA_Blocker__Dominates((OOC_SSA_Blocker__Region)i0, (OOC_SSA_Blocker__Region)i4);
  i4 = !i4;
  
l32:
  if (i4) goto l8_loop;
l35:
  i0=i1;
l36:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 58666))+16);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 58690))+16);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 58673)))), &_td_OOC_SSA_Blocker__ProxyDesc, 58673)), 58679))+12);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 58697)))), &_td_OOC_SSA_Blocker__ProxyDesc, 58697)), 58703))+12);
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
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 58983))+16);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 58989)))), &_td_OOC_SSA_Blocker__ProxyDesc, 58989)), 58995))+12);
  region = (OOC_SSA_Blocker__Region)i0;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 59019))+48);
  p = (OOC_SSA_Blocker__Proxy)i0;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l47;
  i1 = (OOC_INT32)instr;
  
l3_loop:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 59067))+8);
  instr2 = (OOC_SSA__Instr)i2;
  i3 = *(OOC_INT8*)((_check_pointer(i1, 59090))+36);
  i4 = *(OOC_INT8*)((_check_pointer(i2, 59106))+36);
  i3 = i3==i4;
  if (i3) goto l6;
  i3=0u;
  goto l8;
l6:
  i3 = *(OOC_INT8*)((_check_pointer(i1, 59132))+5);
  i4 = *(OOC_INT8*)((_check_pointer(i2, 59150))+5);
  i3 = i3==i4;
  
l8:
  if (!i3) goto l42;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 59188))+24);
  opnd1 = (OOC_SSA__Opnd)i3;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 59222))+24);
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
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 59297));
  i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 59285));
  i5 = i6==i5;
  
l18:
  if (!i5) goto l34;
l21_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 59330))+8);
  opnd1 = (OOC_SSA__Opnd)i3;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 59365))+8);
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
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 59297));
  i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 59285));
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
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 59524));
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
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 59725))+16);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 59731)))), &_td_OOC_SSA_Blocker__ProxyDesc, 59731)), 59737))+12);
  OOC_SSA_Blocker__RegionDesc_Append((OOC_SSA_Blocker__Region)i2, (OOC_SSA_Blocker__Proxy)i1);
  *(OOC_INT32*)((_check_pointer(i0, 59765))+16) = i1;
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
