#include <OOC/X86/Write.d>
#include <__oo2c.h>
#include <setjmp.h>

void OOC_X86_Write__BlockDesc_INIT(OOC_X86_Write__Block block, OOC_X86_SSA__Block blockInstr) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)block;
  *(OOC_INT32*)(_check_pointer(i0, 1370)) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 1401))+4) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 1432))+8) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 1457))+12) = 0;
  i1 = (OOC_INT32)blockInstr;
  *(OOC_INT32*)((_check_pointer(i0, 1480))+16) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 1516))+20) = 0;
  return;
  ;
}

OOC_CHAR8 OOC_X86_Write__BlockDesc_IsEmpty(OOC_X86_Write__Block block) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)block;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 1612))+8);
  i1 = i1==(OOC_INT32)0;
  if (i1) goto l3;
  i0=0u;
  goto l4;
l3:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 1635));
  i0 = *(OOC_INT32*)((_check_pointer(i0, 1648))+4);
  i0 = i0==0;
  
l4:
  return i0;
  ;
}

static void OOC_X86_Write__AddToIncoming(OOC_X86_Write__Block block, OOC_X86_Write__Arc arc) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)arc;
  i1 = (OOC_INT32)block;
  *(OOC_INT32*)((_check_pointer(i0, 1742))+4) = i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 1785))+4);
  *(OOC_INT32*)((_check_pointer(i0, 1763))+12) = i2;
  *(OOC_INT32*)((_check_pointer(i1, 1809))+4) = i0;
  return;
  ;
}

void OOC_X86_Write__BlockDesc_SetArc(OOC_X86_Write__Block block, OOC_X86_Write__Arc *arc, OOC_X86_Write__Block to, OOC_INT8 type, OOC_INT8 opcode) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)*arc;
  _assert((i0==(OOC_INT32)0), 127, 1987);
  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_Write__Arc.baseTypes[0]);
  *arc = (OOC_X86_Write__Arc)i0;
  i1 = (OOC_INT32)block;
  *(OOC_INT32*)(_check_pointer(i0, 2027)) = i1;
  i0 = (OOC_INT32)*arc;
  i1 = type;
  *(OOC_INT8*)((_check_pointer(i0, 2050))+8) = i1;
  i0 = (OOC_INT32)*arc;
  i1 = opcode;
  *(OOC_INT8*)((_check_pointer(i0, 2072))+9) = i1;
  i0 = (OOC_INT32)to;
  i1 = (OOC_INT32)*arc;
  OOC_X86_Write__AddToIncoming((OOC_X86_Write__Block)i0, (OOC_X86_Write__Arc)i1);
  return;
  ;
}

static void OOC_X86_Write__RemoveFromIncoming(OOC_X86_Write__Arc arc) {
  register OOC_INT32 i0,i1,i2;
  OOC_X86_Write__Block block;
  OOC_X86_Write__Arc ptr;

  i0 = (OOC_INT32)arc;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2236))+4);
  block = (OOC_X86_Write__Block)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 2254))+4);
  i2 = i2==i0;
  if (i2) goto l12;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 2353))+4);
  ptr = (OOC_X86_Write__Arc)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 2384))+12);
  i2 = i2!=i0;
  if (!i2) goto l11;
l6_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 2426))+12);
  ptr = (OOC_X86_Write__Arc)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 2384))+12);
  i2 = i2!=i0;
  if (i2) goto l6_loop;
l11:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2481))+12);
  *(OOC_INT32*)((_check_pointer(i1, 2461))+12) = i2;
  goto l13;
l12:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2311))+12);
  *(OOC_INT32*)((_check_pointer(i1, 2291))+4) = i2;
l13:
  *(OOC_INT32*)((_check_pointer(i0, 2512))+4) = (OOC_INT32)0;
  return;
  ;
}

static void OOC_X86_Write__ClearArc(OOC_X86_Write__Arc *arc) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)*arc;
  OOC_X86_Write__RemoveFromIncoming((OOC_X86_Write__Arc)i0);
  *arc = (OOC_X86_Write__Arc)(OOC_INT32)0;
  return;
  ;
}

void OOC_X86_Write__ArcDesc_ReplaceTo(OOC_X86_Write__Arc arc, OOC_X86_Write__Block to) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)arc;
  OOC_X86_Write__RemoveFromIncoming((OOC_X86_Write__Arc)i0);
  i1 = (OOC_INT32)to;
  OOC_X86_Write__AddToIncoming((OOC_X86_Write__Block)i1, (OOC_X86_Write__Arc)i0);
  return;
  ;
}

static OOC_INT8 OOC_X86_Write__NegateBranch(OOC_INT8 opcode) {
  register OOC_INT32 i0;

  i0 = opcode;
  switch (i0) {
  case 9:
    return 10;
    goto l9;
  case 10:
    return 9;
    goto l9;
  case 11:
    return 14;
    goto l9;
  case 12:
    return 13;
    goto l9;
  case 13:
    return 12;
    goto l9;
  case 14:
    return 11;
    goto l9;
  default:
    _failed_case(i0, 2845);
    goto l9;
  }
l9:
  _failed_function(2791); return 0;
  ;
}

static Object__String OOC_X86_Write__OpcodeCC(OOC_INT8 type, OOC_INT8 opcode) {
  register OOC_INT32 i0,i1;
  Object__String str;

  i0 = opcode;
  i1 = i0==37;
  if (i1) goto l23;
  i1 = type;
  i1 = i1<5;
  if (i1) goto l13;
  switch (i0) {
  case 9:
    str = (Object__String)((OOC_INT32)_c0);
    goto l24;
  case 10:
    str = (Object__String)((OOC_INT32)_c1);
    goto l24;
  case 11:
    str = (Object__String)((OOC_INT32)_c2);
    goto l24;
  case 12:
    str = (Object__String)((OOC_INT32)_c3);
    goto l24;
  case 13:
    str = (Object__String)((OOC_INT32)_c4);
    goto l24;
  case 14:
    str = (Object__String)((OOC_INT32)_c5);
    goto l24;
  default:
    _failed_case(i0, 3546);
    goto l24;
  }
l13:
  switch (i0) {
  case 9:
    str = (Object__String)((OOC_INT32)_c6);
    goto l24;
  case 10:
    str = (Object__String)((OOC_INT32)_c7);
    goto l24;
  case 11:
    str = (Object__String)((OOC_INT32)_c8);
    goto l24;
  case 12:
    str = (Object__String)((OOC_INT32)_c9);
    goto l24;
  case 13:
    str = (Object__String)((OOC_INT32)_c10);
    goto l24;
  case 14:
    str = (Object__String)((OOC_INT32)_c11);
    goto l24;
  default:
    _failed_case(i0, 3291);
    goto l24;
  }
l23:
  str = (Object__String)((OOC_INT32)_c12);
l24:
  i0 = (OOC_INT32)str;
  return (Object__String)i0;
  ;
}

static void OOC_X86_Write__WriteArc(IO_TextRider__Writer w, OOC_X86_Write__Arc arc) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)arc;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l3;
  i1=0u;
  goto l9;
l3:
  i1 = *(OOC_INT8*)((_check_pointer(i0, 3871))+9);
  i1 = i1!=37;
  if (i1) goto l6;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3896))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 3911));
  i2 = *(OOC_INT32*)((_check_pointer(i2, 3916))+20);
  i1 = *(OOC_INT32*)((_check_pointer(i1, 3899))+20);
  i1 = i1!=(i2+1);
  
  goto l9;
l6:
  i1=1u;
l9:
  if (!i1) goto l11;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 3974))+8);
  i2 = *(OOC_INT8*)((_check_pointer(i0, 3984))+9);
  i1 = (OOC_INT32)OOC_X86_Write__OpcodeCC(i1, i2);
  i2 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 3939)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i2, (Object__Object)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)_c13),(void*)i1)),(void*)((OOC_INT32)_c14))));
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4022))+4);
  i0 = *(OOC_INT32*)((_check_pointer(i0, 4025))+20);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 4008)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i2, i0, 0);
l11:
  return;
  ;
}

void OOC_X86_Write__WriterDesc_INIT(OOC_X86_Write__Writer w, OOC_SymbolTable__Module module, IO__ByteChannel ch) {
  register OOC_INT32 i0,i1,i2;
  OOC_INT32 i;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)module;
  *(OOC_INT32*)(_check_pointer(i0, 4167)) = i1;
  i1 = (OOC_INT32)ch;
  i1 = (OOC_INT32)IO_TextRider__ConnectWriter((IO__ByteChannel)i1);
  *(OOC_INT32*)((_check_pointer(i0, 4191))+4) = i1;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4231))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4231))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4233)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i2, "\011.arch athlon", 14);
  *(OOC_INT32*)((_check_pointer(i0, 4272))+16) = 0;
  i = 0;
  i1=0;
l1_loop:
  i2 = (OOC_INT32)RT0__NewObject(_td__qtd1.baseTypes[0]);
  ADT_Dictionary__DictionaryDesc_INIT((ADT_Dictionary__Dictionary)i2);
  *(OOC_INT32*)(((_check_pointer(i0, 4321))+20)+(_check_index(i1, 3, OOC_UINT32, 4329))*4) = i2;
  i2 = (OOC_INT32)RT0__NewObject(_td__qtd3.baseTypes[0]);
  ADT_ArrayList__ArrayListDesc_INIT((ADT_ArrayList__ArrayList)i2, 8);
  *(OOC_INT32*)(((_check_pointer(i0, 4363))+32)+(_check_index(i1, 3, OOC_UINT32, 4374))*4) = i2;
  i1 = i1+1;
  i = i1;
  i2 = i1<=2;
  if (i2) goto l1_loop;
l5:
  return;
  ;
}

OOC_X86_Write__Block OOC_X86_Write__WriterDesc_GetBlock(OOC_X86_Write__Writer w, OOC_X86_SSA__Block b) {
  register OOC_INT32 i0,i1,i2;
  OOC_X86_Write__Block block;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4531))+12);
  i2 = (OOC_INT32)b;
  i1 = ADT_Dictionary__DictionaryDesc_HasKey((ADT_Dictionary__Dictionary)i1, (Object__Object)i2);
  if (i1) goto l3;
  i1 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_Write__Block.baseTypes[0]);
  OOC_X86_Write__BlockDesc_INIT((OOC_X86_Write__Block)i1, (OOC_X86_SSA__Block)i2);
  block = (OOC_X86_Write__Block)i1;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4634))+12);
  ADT_Dictionary__DictionaryDesc_Set((ADT_Dictionary__Dictionary)i0, (Object__Object)i2, (Object__Object)i1);
  return (OOC_X86_Write__Block)i1;
  goto l4;
l3:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4570))+12);
  i0 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i0, (Object__Object)i2);
  return (OOC_X86_Write__Block)i0;
l4:
  _failed_function(4462); return 0;
  ;
}

void OOC_X86_Write__WriterDesc_RuntimeData(OOC_X86_Write__Writer w) {
  register OOC_INT32 i0,i1,i2;
  ADT_StringBuffer__StringBuffer sb;

  i0 = (OOC_INT32)RT0__NewObject(_td_ADT_StringBuffer__StringBuffer.baseTypes[0]);
  ADT_StringBuffer__StringBufferDesc_INIT((ADT_StringBuffer__StringBuffer)i0, 2048);
  sb = (ADT_StringBuffer__StringBuffer)i0;
  i1 = (OOC_INT32)w;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 4866));
  OOC_X86_RuntimeData__Write((ADT_StringBuffer__StringBuffer)i0, (OOC_SymbolTable__Module)i2);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4881))+4);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4881))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 4883)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i1, (Object__Object)i0);
  return;
  ;
}

void OOC_X86_Write__WriterDesc_ModuleVariables(OOC_X86_Write__Writer w) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
  OOC_SymbolTable__Item item;
  Object__String name;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5027));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 5034))+8);
  item = (OOC_SymbolTable__Item)i1;
  i2 = i1!=0;
  if (!i2) goto l14;
  i2 = (OOC_INT32)_c15;
  i3 = (OOC_INT32)_c16;
  i4 = (OOC_INT32)_c17;
  
l3_loop:
  i5 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5089)))), &_td_OOC_SymbolTable__VarDeclDesc);
  if (!i5) goto l9;
  i5 = (OOC_INT32)OOC_C_Naming__NameOfDeclaration((OOC_SymbolTable__Declaration)i1);
  name = (Object__String)i5;
  i6 = *(OOC_INT8*)((_check_pointer(i1, 5170))+28);
  i6 = i6==0;
  if (!i6) goto l8;
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5221))+4);
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5221))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 5223)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i7, (Object__Object)((OOC_INT32)Object__Concat2((void*)i2,(void*)i5)));
l8:
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5281))+4);
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5281))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 5283)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i7, (Object__Object)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)i3,(void*)i5)),(void*)i4)));
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 5348))+48);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5331))+4);
  i5 = *(OOC_INT32*)((_check_pointer(i5, 5353))+32);
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5331))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 5333)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i7, i5, 0);
l9:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 5425));
  item = (OOC_SymbolTable__Item)i1;
  i5 = i1!=0;
  if (i5) goto l3_loop;
l14:
  return;
  ;
}

Object__String OOC_X86_Write__WriterDesc_StringSymbol(OOC_X86_Write__Writer w, Object__String value, OOC_INT16 type) {
  register OOC_INT32 i0,i1,i2,i3;
  ADT_Dictionary__Dictionary dict;
  ADT_ArrayList__ArrayList array;

  i0 = type;
  _assert((i0==13), 127, 5633);
  i1 = (OOC_INT32)w;
  i0 = i0-13;
  i2 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i1, 5680))+20)+(_check_index(i0, 3, OOC_UINT16, 5688))*4);
  dict = (ADT_Dictionary__Dictionary)i2;
  i0 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i1, 5728))+32)+(_check_index(i0, 3, OOC_UINT16, 5739))*4);
  array = (ADT_ArrayList__ArrayList)i0;
  i1 = (OOC_INT32)value;
  i3 = ADT_Dictionary__DictionaryDesc_HasKey((ADT_Dictionary__Dictionary)i2, (Object__Object)i1);
  i3 = !i3;
  if (!i3) goto l4;
  i3 = *(OOC_INT32*)((_check_pointer(i0, 5848))+4);
  i3 = (OOC_INT32)Object_Boxed__IntToString(i3);
  ADT_Dictionary__DictionaryDesc_Set((ADT_Dictionary__Dictionary)i2, (Object__Object)i1, (Object__Object)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)_c18),(void*)i3)));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5868)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i0, (Object__Object)i1);
l4:
  i0 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i2, (Object__Object)i1);
  return (Object__String)i0;
  ;
}

void OOC_X86_Write__WriterDesc_StringConstants(OOC_X86_Write__Writer w) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11,i12;
  OOC_INT32 s;
  OOC_INT32 i;
  Object__String value;
  Object__String label;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)_c19;
  i2 = (OOC_INT32)_c20;
  i3 = (OOC_INT32)_c21;
  i4 = (OOC_INT32)_c22;
  s = 0;
  i5=0;
l1_loop:
  i6 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i0, 6086))+32)+(_check_index(i5, 3, OOC_UINT32, 6097))*4);
  i6 = *(OOC_INT32*)((_check_pointer(i6, 6100))+4);
  i = 0;
  i7 = 0<i6;
  if (!i7) goto l9;
  i7 = i5==0;
  i8=0;
l4_loop:
  _assert(i7, 127, 6119);
  i9 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i0, 6152))+32)+(_check_index(i5, 3, OOC_UINT32, 6163))*4);
  i9 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i9, 6166));
  i9 = _check_pointer(i9, 6172);
  i10 = OOC_ARRAY_LENGTH(i9, 0);
  i9 = (OOC_INT32)*(OOC_INT32*)(i9+(_check_index(i8, i10, OOC_UINT32, 6172))*4);
  value = (Object__String)i9;
  i10 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i0, 6195))+20)+(_check_index(i5, 3, OOC_UINT32, 6203))*4);
  i10 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i10, (Object__Object)i9);
  label = (Object__String)i10;
  i11 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6228))+4);
  i12 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6228))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i11, 6230)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i12, (Object__Object)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)i1,(void*)i10)),(void*)i2)));
  i10 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6267))+4);
  i11 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6267))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i10, 6269)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i11, (Object__Object)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)i3,(void*)i9)),(void*)i4)));
  i8 = i8+1;
  i = i8;
  i9 = i8<i6;
  if (i9) goto l4_loop;
l9:
  i5 = i5+1;
  s = i5;
  i6 = i5<=2;
  if (i6) goto l1_loop;
l13:
  return;
  ;
}

void OOC_X86_Write__WriterDesc_EndFile(OOC_X86_Write__Writer w) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  Object__String name0;
  Object__String name;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6506));
  i1 = (OOC_INT32)OOC_C_Naming__NameOfModuleInit((OOC_SymbolTable__Module)i1, 1u);
  name0 = (Object__String)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6559));
  i2 = (OOC_INT32)OOC_C_Naming__NameOfModuleInit((OOC_SymbolTable__Module)i2, 0u);
  name = (Object__String)i2;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6581))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6581))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 6583)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i4, (Object__Object)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)_c23),(void*)i1)));
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6623))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6623))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 6625)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i4, (Object__Object)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)_c24),(void*)i1)),(void*)((OOC_INT32)_c25))));
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6680))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6680))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 6682)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i4, (Object__Object)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)_c26),(void*)i1)),(void*)((OOC_INT32)_c27))));
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6715))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6715))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 6717)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i4, (Object__Object)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)_c28),(void*)i2)));
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6756))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6756))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 6758)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i3, (Object__Object)((OOC_INT32)_c29));
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6790))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6790))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 6792)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i3, (Object__Object)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)_c30),(void*)i1)),(void*)((OOC_INT32)_c31))),(void*)i1)));
  OOC_X86_Write__WriterDesc_RuntimeData((OOC_X86_Write__Writer)i0);
  OOC_X86_Write__WriterDesc_ModuleVariables((OOC_X86_Write__Writer)i0);
  OOC_X86_Write__WriterDesc_StringConstants((OOC_X86_Write__Writer)i0);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6923))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6923))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6925)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "\012", 2);
  return;
  ;
}

OOC_X86_Write__Block OOC_X86_Write__WriterDesc_WriteBlock(OOC_X86_Write__Writer w, OOC_X86_SSA__Block b) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11,i12;
  OOC_C_Naming__QualTypeData qtdData;
  ADT_StringBuffer__StringBuffer sb;
  OOC_X86_Write__Block block;
  OOC_X86_SSA__Instr instr;
  OOC_X86_SSA__Instr nextInstr;
  OOC_INT8 opndWidth;
  OOC_INT8 type;
  OOC_X86_SSA__Instr cmp;
  Object__String str;
  OOC_X86_SSA__Opnd opnd;
  OOC_X86_SSA__MergeInstr merge;
  OOC_X86_Write__Block dummy;
  auto void OOC_X86_Write__WriterDesc_WriteBlock_OpcTT(const OOC_CHAR8 opc[], OOC_LEN opc_0d, OOC_INT8 type1, OOC_INT8 type2);
  auto void OOC_X86_Write__WriterDesc_WriteBlock_Opc0(const OOC_CHAR8 opc[], OOC_LEN opc_0d);
  auto void OOC_X86_Write__WriterDesc_WriteBlock_Opc(const OOC_CHAR8 opc[], OOC_LEN opc_0d);
  auto void OOC_X86_Write__WriterDesc_WriteBlock_RegT(OOC_INT8 reg, OOC_INT8 type);
  auto void OOC_X86_Write__WriterDesc_WriteBlock_RegAdr(OOC_INT8 reg);
  auto void OOC_X86_Write__WriterDesc_WriteBlock_Reg(OOC_INT8 reg);
  auto void OOC_X86_Write__WriterDesc_WriteBlock_Comma(void);
  auto void OOC_X86_Write__WriterDesc_WriteBlock_Literal(OOC_X86_SSA__Instr instr);
  auto void OOC_X86_Write__WriterDesc_WriteBlock_Result(OOC_X86_SSA__Result res);
  auto void OOC_X86_Write__WriterDesc_WriteBlock_OpndMem(OOC_X86_SSA__Opnd opnd);
  auto void OOC_X86_Write__WriterDesc_WriteBlock_Opnd(OOC_X86_SSA__Opnd opnd);
  auto void OOC_X86_Write__WriterDesc_WriteBlock_DirectOpnd(OOC_X86_SSA__Opnd opnd);
  auto void OOC_X86_Write__WriterDesc_WriteBlock_AssertResultMatch(OOC_X86_SSA__Opnd opnd);
  auto void OOC_X86_Write__WriterDesc_WriteBlock_FixGatedValues(OOC_X86_SSA__Instr jump);
  auto void OOC_X86_Write__WriterDesc_WriteBlock_WriteBranch2(OOC_X86_SSA__Instr cmp, OOC_CHAR8 neg, OOC_X86_SSA__Block path1, OOC_X86_SSA__Block path2);
  auto void OOC_X86_Write__WriterDesc_WriteBlock_WriteMerge(OOC_X86_SSA__MergeInstr instr);
  auto void OOC_X86_Write__WriterDesc_WriteBlock_MovMemReg(OOC_X86_SSA__Opnd fromMemReg, OOC_INT8 fromType, OOC_CHAR8 valueOpnd, OOC_X86_SSA__Result toReg);
    
    void OOC_X86_Write__WriterDesc_WriteBlock_OpcTT(const OOC_CHAR8 opc[], OOC_LEN opc_0d, OOC_INT8 type1, OOC_INT8 type2) {
      register OOC_INT32 i0;
      OOC_CHAR8 suffix[3];
      auto OOC_CHAR8 OOC_X86_Write__WriterDesc_WriteBlock_OpcTT_Type(OOC_INT8 type);
        
        OOC_CHAR8 OOC_X86_Write__WriterDesc_WriteBlock_OpcTT_Type(OOC_INT8 type) {
          register OOC_INT32 i0;

          i0 = type;
          switch (i0) {
          case 0:
            return 0u;
            goto l8;
          case 1:
          case 5:
            return 98u;
            goto l8;
          case 2:
          case 6:
            return 119u;
            goto l8;
          case 3:
          case 7:
          case 10:
          case 9:
            return 108u;
            goto l8;
          case 4:
          case 8:
            return 113u;
            goto l8;
          default:
            _failed_case(i0, 7774);
            goto l8;
          }
l8:
          _failed_function(7728); return 0;
          ;
        }


      i0 = (OOC_INT32)sb;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8131)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1)),ADT_StringBuffer__StringBufferDesc_AppendLatin1)((ADT_StringBuffer__StringBuffer)i0, "\012\011", 3);
      i0 = (OOC_INT32)sb;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8161)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1)),ADT_StringBuffer__StringBufferDesc_AppendLatin1)((ADT_StringBuffer__StringBuffer)i0, (void*)(OOC_INT32)opc, opc_0d);
      i0 = type1;
      i0 = OOC_X86_Write__WriterDesc_WriteBlock_OpcTT_Type(i0);
      *(OOC_UINT8*)((OOC_INT32)suffix+(_check_index(0, 3, OOC_UINT8, 8193))) = i0;
      i0 = type2;
      i0 = OOC_X86_Write__WriterDesc_WriteBlock_OpcTT_Type(i0);
      *(OOC_UINT8*)((OOC_INT32)suffix+(_check_index(1, 3, OOC_UINT8, 8225))) = i0;
      *(OOC_UINT8*)((OOC_INT32)suffix+(_check_index(2, 3, OOC_UINT8, 8257))) = 0u;
      i0 = (OOC_INT32)sb;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8276)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1)),ADT_StringBuffer__StringBufferDesc_AppendLatin1)((ADT_StringBuffer__StringBuffer)i0, (void*)(OOC_INT32)suffix, 3);
      i0 = (OOC_INT32)sb;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8307)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1)),ADT_StringBuffer__StringBufferDesc_AppendLatin1)((ADT_StringBuffer__StringBuffer)i0, " ", 2);
      return;
      ;
    }

    
    void OOC_X86_Write__WriterDesc_WriteBlock_Opc0(const OOC_CHAR8 opc[], OOC_LEN opc_0d) {

      OOC_X86_Write__WriterDesc_WriteBlock_OpcTT((void*)(OOC_INT32)opc, opc_0d, 0, 0);
      return;
      ;
    }

    
    void OOC_X86_Write__WriterDesc_WriteBlock_Opc(const OOC_CHAR8 opc[], OOC_LEN opc_0d) {
      register OOC_INT32 i0;

      i0 = opndWidth;
      OOC_X86_Write__WriterDesc_WriteBlock_OpcTT((void*)(OOC_INT32)opc, opc_0d, i0, 0);
      return;
      ;
    }

    
    void OOC_X86_Write__WriterDesc_WriteBlock_RegT(OOC_INT8 reg, OOC_INT8 type) {
      register OOC_INT32 i0;
      OOC_CHAR8 str[8];

      i0 = type;
      switch (i0) {
      case 1:
      case 5:
        i0 = reg;
        switch (i0) {
        case 3:
          _copy_8((const void*)"%al",(void*)(OOC_INT32)str,8);
          goto l35;
        case 4:
          _copy_8((const void*)"%cl",(void*)(OOC_INT32)str,8);
          goto l35;
        case 5:
          _copy_8((const void*)"%dl",(void*)(OOC_INT32)str,8);
          goto l35;
        case 6:
          _copy_8((const void*)"%bl",(void*)(OOC_INT32)str,8);
          goto l35;
        default:
          _failed_case(i0, 8910);
          goto l35;
        }
        /* goto: unreachable */
      case 2:
      case 6:
        i0 = reg;
        switch (i0) {
        case 0:
          _copy_8((const void*)"%sp",(void*)(OOC_INT32)str,8);
          goto l35;
        case 1:
          _copy_8((const void*)"%bp",(void*)(OOC_INT32)str,8);
          goto l35;
        case 3:
          _copy_8((const void*)"%ax",(void*)(OOC_INT32)str,8);
          goto l35;
        case 4:
          _copy_8((const void*)"%cx",(void*)(OOC_INT32)str,8);
          goto l35;
        case 5:
          _copy_8((const void*)"%dx",(void*)(OOC_INT32)str,8);
          goto l35;
        case 6:
          _copy_8((const void*)"%bx",(void*)(OOC_INT32)str,8);
          goto l35;
        case 7:
          _copy_8((const void*)"%si",(void*)(OOC_INT32)str,8);
          goto l35;
        case 8:
          _copy_8((const void*)"%di",(void*)(OOC_INT32)str,8);
          goto l35;
        default:
          _failed_case(i0, 9215);
          goto l35;
        }
        /* goto: unreachable */
      case 3:
      case 7:
      case 10:
      case 9:
        i0 = reg;
        switch (i0) {
        case 0:
          _copy_8((const void*)"%esp",(void*)(OOC_INT32)str,8);
          goto l35;
        case 1:
          _copy_8((const void*)"%ebp",(void*)(OOC_INT32)str,8);
          goto l35;
        case 3:
          _copy_8((const void*)"%eax",(void*)(OOC_INT32)str,8);
          goto l35;
        case 4:
          _copy_8((const void*)"%ecx",(void*)(OOC_INT32)str,8);
          goto l35;
        case 5:
          _copy_8((const void*)"%edx",(void*)(OOC_INT32)str,8);
          goto l35;
        case 6:
          _copy_8((const void*)"%ebx",(void*)(OOC_INT32)str,8);
          goto l35;
        case 7:
          _copy_8((const void*)"%esi",(void*)(OOC_INT32)str,8);
          goto l35;
        case 8:
          _copy_8((const void*)"%edi",(void*)(OOC_INT32)str,8);
          goto l35;
        default:
          _failed_case(i0, 9549);
          goto l35;
        }
        /* goto: unreachable */
      default:
        _failed_case(i0, 8786);
        goto l35;
      }
l35:
      i0 = (OOC_INT32)sb;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9847)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1)),ADT_StringBuffer__StringBufferDesc_AppendLatin1)((ADT_StringBuffer__StringBuffer)i0, (void*)(OOC_INT32)str, 8);
      return;
      ;
    }

    
    void OOC_X86_Write__WriterDesc_WriteBlock_RegAdr(OOC_INT8 reg) {
      register OOC_INT32 i0;

      i0 = reg;
      OOC_X86_Write__WriterDesc_WriteBlock_RegT(i0, 9);
      return;
      ;
    }

    
    void OOC_X86_Write__WriterDesc_WriteBlock_Reg(OOC_INT8 reg) {
      register OOC_INT32 i0,i1;

      i0 = opndWidth;
      i1 = reg;
      OOC_X86_Write__WriterDesc_WriteBlock_RegT(i1, i0);
      return;
      ;
    }

    
    void OOC_X86_Write__WriterDesc_WriteBlock_Comma(void) {
      register OOC_INT32 i0;

      i0 = (OOC_INT32)sb;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10201)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1)),ADT_StringBuffer__StringBufferDesc_AppendLatin1)((ADT_StringBuffer__StringBuffer)i0, ", ", 3);
      return;
      ;
    }

    
    void OOC_X86_Write__WriterDesc_WriteBlock_Literal(OOC_X86_SSA__Instr instr) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
      register OOC_REAL64 d0;
      OOC_INT32 i;
      OOC_X86_SSA__Selector s;
      Object_Boxed__Object value;
      auto Object__String OOC_X86_Write__WriterDesc_WriteBlock_Literal_ToHex(OOC_INT32 n, OOC_INT32 digits);
        
        Object__String OOC_X86_Write__WriterDesc_WriteBlock_Literal_ToHex(OOC_INT32 n, OOC_INT32 digits) {
          register OOC_INT32 i0,i1,i2,i3,i4,i5;
          OOC_CHAR8 str[16];

          i0 = digits;
          i1 = 0<i0;
          if (!i1) goto l12;
          i1 = n;
          i2 = -(4*i0);
          i3=0;
l3_loop:
          i2 = i2+4;
          i4 = _mod((_ash(i1,i2)),16);
          i5 = i4<=9;
          if (i5) goto l6;
          *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i3, 16, OOC_UINT32, 10754))) = (55+i4);
          goto l7;
l6:
          *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i3, 16, OOC_UINT32, 10696))) = (48+i4);
l7:
          i3 = i3+1;
          i4 = i3<i0;
          if (i4) goto l3_loop;
l12:
          i0 = (OOC_INT32)Object__NewLatin1Region((void*)(OOC_INT32)str, 16, 0, i0);
          return (Object__String)i0;
          ;
        }


      i0 = (OOC_INT32)instr;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10931))+28);
      i = 0;
      i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 10942)), 0);
      i1 = 0<i0;
      if (!i1) goto l59;
      i1 = (OOC_INT32)_c32;
      i2 = (OOC_INT32)_c33;
      i3 = (OOC_INT32)_c34;
      i4=0;
l3_loop:
      i5 = i4!=0;
      if (!i5) goto l6;
      i5 = (OOC_INT32)sb;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 10986)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)),ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)((ADT_StringBuffer__StringBuffer)i5, 43u);
l6:
      i5 = (OOC_INT32)instr;
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 11050))+28);
      i6 = _check_pointer(i6, 11061);
      i7 = OOC_ARRAY_LENGTH(i6, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i4, i7, OOC_UINT32, 11061))*4);
      s = (OOC_X86_SSA__Selector)i4;
      i6 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 11080)))), &_td_OOC_X86_SSA__ConstDesc);
      if (i6) goto l33;
      i5 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 11794)))), &_td_OOC_X86_SSA__VarDesc);
      if (i5) goto l27;
      i5 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 11990)))), &_td_OOC_X86_SSA__ProcDesc);
      if (i5) goto l25;
      i5 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 12068)))), &_td_OOC_X86_SSA__ProcNameDesc);
      if (i5) goto l23;
      i5 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 12124)))), &_td_OOC_X86_SSA__TypeDescrDesc);
      if (i5) goto l21;
      i5 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 12219)))), &_td_OOC_X86_SSA__ModuleDescrDesc);
      if (i5) goto l19;
      _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 12216)))), 12216);
      goto l54;
l19:
      i4 = (OOC_INT32)sb;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 12250)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i4, (Object__Object)i3);
      goto l54;
l21:
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 12190));
      i5 = (OOC_INT32)qtdData;
      i4 = (OOC_INT32)OOC_C_Naming__NameOfTypeDescriptor((OOC_SymbolTable__Type)i4, (OOC_C_Naming__QualTypeData)i5);
      i5 = (OOC_INT32)sb;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 12153)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i5, (Object__Object)i4);
      goto l54;
l23:
      i5 = (OOC_INT32)sb;
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 12105));
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 12096)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i5, (Object__Object)i4);
      goto l54;
l25:
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 12048));
      i4 = (OOC_INT32)OOC_C_Naming__NameOfDeclaration((OOC_SymbolTable__Declaration)i4);
      i5 = (OOC_INT32)sb;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 12014)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i5, (Object__Object)i4);
      goto l54;
l27:
      i5 = OOC_X86_SSA__VarDesc_IsGlobalVar((OOC_X86_SSA__Var)i4);
      if (i5) goto l30;
      i5 = (OOC_INT32)w;
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 11937))+44);
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 11955));
      i4 = OOC_X86_SSA__FunctionBlockDesc_Offset((OOC_X86_SSA__FunctionBlock)i5, (OOC_SymbolTable__VarDecl)i4);
      i5 = (OOC_INT32)sb;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 11925)))), ADT_StringBuffer__StringBufferDesc_AppendInt)),ADT_StringBuffer__StringBufferDesc_AppendInt)((ADT_StringBuffer__StringBuffer)i5, i4);
      goto l54;
l30:
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 11887));
      i4 = (OOC_INT32)OOC_C_Naming__NameOfDeclaration((OOC_SymbolTable__Declaration)i4);
      i5 = (OOC_INT32)sb;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 11853)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i5, (Object__Object)i4);
      goto l54;
l33:
      i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 11113));
      value = (Object_Boxed__Object)i6;
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 11144))+4);
      i5 = *(OOC_INT8*)((_check_pointer(i5, 11155))+12);
      type = i5;
      i5 = *(OOC_INT16*)((_check_pointer(i4, 11177))+4);
      i5 = i5>=0;
      if (i5) goto l52;
      i5 = i6==0;
      if (i5) goto l50;
      i5 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 11399)))), &_td_Object_Boxed__StringDesc);
      if (i5) goto l48;
      i5 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 11492)))), &_td_Object_Boxed__SetDesc);
      if (i5) goto l46;
      i5 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 11573)))), &_td_Object_Boxed__LongRealDesc);
      if (i5) goto l44;
      i5 = (OOC_INT32)sb;
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 11742));
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 11733)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i5, (Object__Object)i4);
      goto l54;
l44:
      i4 = (OOC_INT32)sb;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 11609)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i4, (Object__Object)i2);
      d0 = *(OOC_REAL64*)(_check_pointer(i6, 11685));
      i4 = (OOC_INT32)OOC_X86_Write__WriterDesc_WriteBlock_Literal_ToHex((_type_cast(OOC_INT32, OOC_REAL32, ((OOC_REAL32)d0))), 8);
      i5 = (OOC_INT32)sb;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 11640)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i5, (Object__Object)i4);
      goto l54;
l46:
      i4 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 11539)))), Object_Boxed__SetDesc_ToLongInt)),Object_Boxed__SetDesc_ToLongInt)((Object_Boxed__Set)i6);
      i5 = (OOC_INT32)sb;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 11523)))), ADT_StringBuffer__StringBufferDesc_AppendInt)),ADT_StringBuffer__StringBufferDesc_AppendInt)((ADT_StringBuffer__StringBuffer)i5, i4);
      goto l54;
l48:
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i6, 11453));
      i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i6, 11453));
      i4 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 11459)))), Object__StringDesc_CharAt)),Object__StringDesc_CharAt)((Object__String)i5, 0);
      i5 = (OOC_INT32)sb;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 11433)))), ADT_StringBuffer__StringBufferDesc_AppendInt)),ADT_StringBuffer__StringBufferDesc_AppendInt)((ADT_StringBuffer__StringBuffer)i5, i4);
      goto l54;
l50:
      i4 = (OOC_INT32)sb;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 11348)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i4, (Object__Object)i1);
      goto l54;
l52:
      i4 = *(OOC_INT16*)((_check_pointer(i4, 11290))+4);
      i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i6, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 11274)))), &_td_Object_Boxed__StringDesc, 11274)), 11281));
      i6 = (OOC_INT32)w;
      i4 = (OOC_INT32)OOC_X86_Write__WriterDesc_StringSymbol((OOC_X86_Write__Writer)i6, (Object__String)i5, i4);
      i5 = (OOC_INT32)sb;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 11239)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i5, (Object__Object)i4);
l54:
      i4 = i;
      i4 = i4+1;
      i = i4;
      i5 = i4<i0;
      if (i5) goto l3_loop;
l59:
      return;
      ;
    }

    
    void OOC_X86_Write__WriterDesc_WriteBlock_Result(OOC_X86_SSA__Result res) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)res;
      i1 = *(OOC_INT8*)((_check_pointer(i0, 12370))+14);
      switch (i1) {
      case 0:
        i0 = *(OOC_INT8*)((_check_pointer(i0, 12417))+13);
        OOC_X86_Write__WriterDesc_WriteBlock_Reg(i0);
        goto l4;
      default:
        _failed_case(i1, 12362);
        goto l4;
      }
l4:
      return;
      ;
    }

    
    void OOC_X86_Write__WriterDesc_WriteBlock_OpndMem(OOC_X86_SSA__Opnd opnd) {
      register OOC_INT32 i0;

      i0 = (OOC_INT32)sb;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12510)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)),ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)((ADT_StringBuffer__StringBuffer)i0, 40u);
      i0 = (OOC_INT32)opnd;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 12551));
      i0 = *(OOC_INT8*)((_check_pointer(i0, 12555))+13);
      OOC_X86_Write__WriterDesc_WriteBlock_RegAdr(i0);
      i0 = (OOC_INT32)sb;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12575)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)),ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)((ADT_StringBuffer__StringBuffer)i0, 41u);
      return;
      ;
    }

    
    void OOC_X86_Write__WriterDesc_WriteBlock_Opnd(OOC_X86_SSA__Opnd opnd) {
      register OOC_INT32 i0,i1,i2;
      OOC_X86_SSA__Instr argInstr1;
      OOC_X86_SSA__Instr argInstr2;
      auto void OOC_X86_Write__WriterDesc_WriteBlock_Opnd_Offset(OOC_X86_SSA__Result arg1, OOC_X86_SSA__Result arg2);
        
        void OOC_X86_Write__WriterDesc_WriteBlock_Opnd_Offset(OOC_X86_SSA__Result arg1, OOC_X86_SSA__Result arg2) {
          register OOC_INT32 i0,i1,i2;

          i0 = (OOC_INT32)arg2;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12767))+4);
          i1 = *(OOC_INT8*)((_check_pointer(i1, 12773))+20);
          i1 = i1==0;
          if (i1) goto l7;
          i1 = (OOC_INT32)arg1;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12952))+4);
          i2 = *(OOC_INT8*)((_check_pointer(i2, 12958))+20);
          i2 = i2==0;
          if (i2) goto l5;
          i2 = (OOC_INT32)sb;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 13038)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)),ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)((ADT_StringBuffer__StringBuffer)i2, 40u);
          i1 = *(OOC_INT8*)((_check_pointer(i1, 13083))+13);
          OOC_X86_Write__WriterDesc_WriteBlock_RegAdr(i1);
          i1 = (OOC_INT32)sb;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 13107)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)),ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)((ADT_StringBuffer__StringBuffer)i1, 44u);
          i0 = *(OOC_INT8*)((_check_pointer(i0, 13152))+13);
          OOC_X86_Write__WriterDesc_WriteBlock_RegAdr(i0);
          i0 = (OOC_INT32)sb;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13176)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)),ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)((ADT_StringBuffer__StringBuffer)i0, 41u);
          goto l8;
l5:
          OOC_X86_Write__WriterDesc_WriteBlock_Opnd_Offset((OOC_X86_SSA__Result)i0, (OOC_X86_SSA__Result)i1);
          goto l8;
l7:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12819))+4);
          OOC_X86_Write__WriterDesc_WriteBlock_Literal((OOC_X86_SSA__Instr)i0);
          i0 = (OOC_INT32)sb;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12840)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)),ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)((ADT_StringBuffer__StringBuffer)i0, 40u);
          i0 = (OOC_INT32)arg1;
          i0 = *(OOC_INT8*)((_check_pointer(i0, 12885))+13);
          OOC_X86_Write__WriterDesc_WriteBlock_RegAdr(i0);
          i0 = (OOC_INT32)sb;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12909)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)),ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)((ADT_StringBuffer__StringBuffer)i0, 41u);
l8:
          return;
          ;
        }


      i0 = (OOC_INT32)opnd;
      i1 = *(OOC_UINT8*)((_check_pointer(i0, 13259))+16);
      if (i1) goto l3;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 13944));
      OOC_X86_Write__WriterDesc_WriteBlock_Result((OOC_X86_SSA__Result)i0);
      goto l18;
l3:
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 13300));
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13304))+4);
      argInstr1 = (OOC_X86_SSA__Instr)i0;
      i1 = *(OOC_INT8*)((_check_pointer(i0, 13334))+20);
      switch (i1) {
      case 0:
        i1 = (OOC_INT32)sb;
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 13376)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)),ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)((ADT_StringBuffer__StringBuffer)i1, 36u);
        OOC_X86_Write__WriterDesc_WriteBlock_Literal((OOC_X86_SSA__Instr)i0);
        goto l18;
      case 1:
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 13568));
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 13577))+4);
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 13527));
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 13536));
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 13586));
        OOC_X86_Write__WriterDesc_WriteBlock_Opnd_Offset((OOC_X86_SSA__Result)i0, (OOC_X86_SSA__Result)i1);
        goto l18;
      case 24:
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 13642));
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 13651));
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 13655))+4);
        argInstr2 = (OOC_X86_SSA__Instr)i1;
        i2 = *(OOC_INT8*)((_check_pointer(i1, 13686))+20);
        i2 = i2==0;
        if (i2) goto l14;
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 13767));
        i1 = *(OOC_UINT8*)((_check_pointer(i1, 13776))+16);
        if (i1) goto l12;
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 13874));
        OOC_X86_Write__WriterDesc_WriteBlock_OpndMem((OOC_X86_SSA__Opnd)i0);
        goto l18;
l12:
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 13818));
        OOC_X86_Write__WriterDesc_WriteBlock_Opnd((OOC_X86_SSA__Opnd)i0);
        goto l18;
l14:
        OOC_X86_Write__WriterDesc_WriteBlock_Literal((OOC_X86_SSA__Instr)i1);
        goto l18;
      default:
        _failed_case(i1, 13320);
        goto l18;
      }
l18:
      return;
      ;
    }

    
    void OOC_X86_Write__WriterDesc_WriteBlock_DirectOpnd(OOC_X86_SSA__Opnd opnd) {
      register OOC_INT32 i0,i1,i2;
      OOC_X86_SSA__Instr argInstr;

      i0 = (OOC_INT32)opnd;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 14080));
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14084))+4);
      argInstr = (OOC_X86_SSA__Instr)i1;
      i2 = *(OOC_INT8*)((_check_pointer(i1, 14110))+20);
      i2 = i2==0;
      if (i2) goto l3;
      OOC_X86_Write__WriterDesc_WriteBlock_Opnd((OOC_X86_SSA__Opnd)i0);
      goto l4;
l3:
      OOC_X86_Write__WriterDesc_WriteBlock_Literal((OOC_X86_SSA__Instr)i1);
l4:
      return;
      ;
    }

    
    void OOC_X86_Write__WriterDesc_WriteBlock_AssertResultMatch(OOC_X86_SSA__Opnd opnd) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)opnd;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14298))+8);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14304))+4);
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 14333));
      i0 = OOC_X86_SSA__ResultDesc_SameLocation((OOC_X86_SSA__Result)i1, (OOC_X86_SSA__Result)i0);
      _assert(i0, 127, 14287);
      return;
      ;
    }

    
    void OOC_X86_Write__WriterDesc_WriteBlock_FixGatedValues(OOC_X86_SSA__Instr jump) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
      OOC_X86_SSA__Block merge;
      struct OOC_X86_Write__WriterDesc_WriteBlock_FixGatedValues_IO *io;
      OOC_INT32 i;
      OOC_X86_SSA__Opnd opnd;
      OOC_INT32 len;
      OOC_INT32 j;

      i0 = (OOC_INT32)jump;
      i1 = (OOC_INT32)OOC_X86_SSA__InstrDesc_MergingTarget((OOC_X86_SSA__Instr)i0);
      merge = (OOC_X86_SSA__Block)i1;
      i1 = OOC_X86_SSA__BlockDesc_Count((OOC_X86_SSA__Block)i1, 38);
      i1 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_Write__14510.baseTypes[0], i1);
      io = (void*)i1;
      i = 0;
      i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_GateOperands((OOC_X86_SSA__Instr)i0);
      i2 = (OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG(i0)), OOC_X86_SSA__IterJumpGateOperandsDesc_Next);
      i3 = OOC_TBCALL(i2,OOC_X86_SSA__IterJumpGateOperandsDesc_Next)((OOC_X86_SSA__IterJumpGateOperands)i0, (void*)(OOC_INT32)&opnd);
      if (i3) goto l3;
      i0=0;
      goto l9;
l3:
      i3=0;
l4_loop:
      i4 = _check_pointer(i1, 14728);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i6 = (OOC_INT32)opnd;
      *(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 14728))*8) = i6;
      i4 = _check_pointer(i1, 14754);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 14769))+8);
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 14775))+4);
      *(OOC_INT32*)((i4+(_check_index(i3, i5, OOC_UINT32, 14754))*8)+4) = i6;
      i3 = i3+1;
      i = i3;
      i4 = OOC_TBCALL(i2,OOC_X86_SSA__IterJumpGateOperandsDesc_Next)((OOC_X86_SSA__IterJumpGateOperands)i0, (void*)(OOC_INT32)&opnd);
      if (i4) goto l4_loop;
l8:
      i0=i3;
l9:
      len = i0;
      i = 0;
      i2 = 0!=i0;
      if (!i2) goto l22;
      i2=i0;i0=0;
l13_loop:
      i3 = _check_pointer(i1, 14974);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i5 = _check_pointer(i1, 14948);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i0, i6, OOC_UINT32, 14948))*8);
      i3 = (OOC_INT32)*(OOC_INT32*)((i3+(_check_index(i0, i4, OOC_UINT32, 14974))*8)+4);
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 14954));
      i3 = OOC_X86_SSA__ResultDesc_SameLocation((OOC_X86_SSA__Result)i4, (OOC_X86_SSA__Result)i3);
      if (i3) goto l16;
      i0 = i0+1;
      i = i0;
      
      goto l17;
l16:
      i3 = _check_pointer(i1, 15009);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i2 = i2-1;
      i5 = _check_pointer(i1, 15000);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      _copy_block((i3+(_check_index(i2, i4, OOC_UINT32, 15009))*8),(i5+(_check_index(i0, i6, OOC_UINT32, 15000))*8),8);
      len = i2;
      
l17:
      i3 = i0!=i2;
      if (i3) goto l13_loop;
l21:
      i0=i2;
l22:
      i = 0;
      i2 = 0!=i0;
      if (!i2) goto l52;
      i2=0;
l26_loop:
      j = 0;
      i3 = 0!=i0;
      if (i3) goto l29;
      i3=0u;
      goto l31;
l29:
      i3 = _check_pointer(i1, 15349);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(0, i4, OOC_UINT32, 15349))*8);
      i4 = _check_pointer(i1, 15326);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)((i4+(_check_index(i2, i5, OOC_UINT32, 15326))*8)+4);
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 15355));
      i3 = OOC_X86_SSA__ResultDesc_SameLocation((OOC_X86_SSA__Result)i4, (OOC_X86_SSA__Result)i3);
      i3 = !i3;
      
l31:
      if (i3) goto l33;
      i3=0;
      goto l43;
l33:
      i3=0;
l34_loop:
      i3 = i3+1;
      j = i3;
      i4 = i3!=i0;
      if (i4) goto l37;
      i4=0u;
      goto l39;
l37:
      i4 = _check_pointer(i1, 15349);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 15349))*8);
      i5 = _check_pointer(i1, 15326);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i5 = (OOC_INT32)*(OOC_INT32*)((i5+(_check_index(i2, i6, OOC_UINT32, 15326))*8)+4);
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 15355));
      i4 = OOC_X86_SSA__ResultDesc_SameLocation((OOC_X86_SSA__Result)i5, (OOC_X86_SSA__Result)i4);
      i4 = !i4;
      
l39:
      if (i4) goto l34_loop;
l43:
      i3 = i3==i0;
      if (i3) goto l46;
      i2 = i2+1;
      i = i2;
      
      goto l47;
l46:
      i3 = _check_pointer(i1, 15534);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)((i3+(_check_index(i2, i4, OOC_UINT32, 15534))*8)+4);
      i3 = *(OOC_INT8*)((_check_pointer(i3, 15541))+12);
      opndWidth = i3;
      OOC_X86_Write__WriterDesc_WriteBlock_Opc("mov", 4);
      i3 = _check_pointer(i1, 15587);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 15587))*8);
      OOC_X86_Write__WriterDesc_WriteBlock_Opnd((OOC_X86_SSA__Opnd)i3);
      OOC_X86_Write__WriterDesc_WriteBlock_Comma();
      i3 = _check_pointer(i1, 15634);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)((i3+(_check_index(i2, i4, OOC_UINT32, 15634))*8)+4);
      OOC_X86_Write__WriterDesc_WriteBlock_Result((OOC_X86_SSA__Result)i3);
      i3 = _check_pointer(i1, 15665);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i0 = i0-1;
      i5 = _check_pointer(i1, 15656);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      _copy_block((i3+(_check_index(i0, i4, OOC_UINT32, 15665))*8),(i5+(_check_index(i2, i6, OOC_UINT32, 15656))*8),8);
      len = i0;
      
l47:
      i3 = i2!=i0;
      if (i3) goto l26_loop;
l52:
      i2 = i0!=0;
      if (!i2) goto l55;
      _assert((i0==2), 127, 15932);
      i0 = _check_pointer(i1, 16200);
      i2 = OOC_ARRAY_LENGTH(i0, 0);
      i0 = (OOC_INT32)*(OOC_INT32*)((i0+(_check_index(0, i2, OOC_UINT8, 16200))*8)+4);
      i0 = *(OOC_INT8*)((_check_pointer(i0, 16207))+12);
      opndWidth = i0;
      OOC_X86_Write__WriterDesc_WriteBlock_Opc("xchg", 5);
      i0 = _check_pointer(i1, 16250);
      i2 = OOC_ARRAY_LENGTH(i0, 0);
      i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i2, OOC_UINT8, 16250))*8);
      OOC_X86_Write__WriterDesc_WriteBlock_Opnd((OOC_X86_SSA__Opnd)i0);
      OOC_X86_Write__WriterDesc_WriteBlock_Comma();
      i0 = _check_pointer(i1, 16293);
      i1 = OOC_ARRAY_LENGTH(i0, 0);
      i0 = (OOC_INT32)*(OOC_INT32*)((i0+(_check_index(0, i1, OOC_UINT8, 16293))*8)+4);
      OOC_X86_Write__WriterDesc_WriteBlock_Result((OOC_X86_SSA__Result)i0);
l55:
      return;
      ;
    }

    
    void OOC_X86_Write__WriterDesc_WriteBlock_WriteBranch2(OOC_X86_SSA__Instr cmp, OOC_CHAR8 neg, OOC_X86_SSA__Block path1, OOC_X86_SSA__Block path2) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_INT8 opc;

      i0 = (OOC_INT32)cmp;
      i1 = *(OOC_INT8*)((_check_pointer(i0, 16491))+20);
      opc = i1;
      i2 = i1==0;
      if (i2) goto l7;
      i2 = neg;
      if (!i2) goto l6;
      i1 = OOC_X86_Write__NegateBranch(i1);
      opc = i1;
      
l6:
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 16919));
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 16928));
      i0 = *(OOC_INT8*)((_check_pointer(i0, 16932))+12);
      i2 = (OOC_INT32)w;
      i3 = (OOC_INT32)path2;
      i2 = (OOC_INT32)OOC_X86_Write__WriterDesc_GetBlock((OOC_X86_Write__Writer)i2, (OOC_X86_SSA__Block)i3);
      i3 = (OOC_INT32)block;
      OOC_X86_Write__BlockDesc_SetArc((OOC_X86_Write__Block)i3, (void*)((_check_pointer(i3, 16867))+8), (OOC_X86_Write__Block)i2, i0, i1);
      i0 = (OOC_INT32)w;
      i1 = (OOC_INT32)path1;
      i0 = (OOC_INT32)OOC_X86_Write__WriterDesc_GetBlock((OOC_X86_Write__Writer)i0, (OOC_X86_SSA__Block)i1);
      i1 = (OOC_INT32)block;
      OOC_X86_Write__BlockDesc_SetArc((OOC_X86_Write__Block)i1, (void*)((_check_pointer(i1, 16971))+12), (OOC_X86_Write__Block)i0, (-1), 37);
      goto l12;
l7:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16592))+4);
      i0 = OOC_X86_SSA__ResultDesc_IsTrue((OOC_X86_SSA__Result)i0);
      i1 = neg;
      i0 = i1!=i0;
      if (i0) goto l10;
      i0 = (OOC_INT32)w;
      i1 = (OOC_INT32)path1;
      i0 = (OOC_INT32)OOC_X86_Write__WriterDesc_GetBlock((OOC_X86_Write__Writer)i0, (OOC_X86_SSA__Block)i1);
      i1 = (OOC_INT32)block;
      OOC_X86_Write__BlockDesc_SetArc((OOC_X86_Write__Block)i1, (void*)((_check_pointer(i1, 16727))+12), (OOC_X86_Write__Block)i0, (-1), 37);
      goto l12;
l10:
      i0 = (OOC_INT32)w;
      i1 = (OOC_INT32)path2;
      i0 = (OOC_INT32)OOC_X86_Write__WriterDesc_GetBlock((OOC_X86_Write__Writer)i0, (OOC_X86_SSA__Block)i1);
      i1 = (OOC_INT32)block;
      OOC_X86_Write__BlockDesc_SetArc((OOC_X86_Write__Block)i1, (void*)((_check_pointer(i1, 16647))+12), (OOC_X86_Write__Block)i0, (-1), 37);
l12:
      i0 = (OOC_INT32)path1;
      i1 = (OOC_INT32)w;
      i0 = (OOC_INT32)OOC_X86_Write__WriterDesc_WriteBlock((OOC_X86_Write__Writer)i1, (OOC_X86_SSA__Block)i0);
      i0 = (OOC_INT32)w;
      i1 = (OOC_INT32)path2;
      i0 = (OOC_INT32)OOC_X86_Write__WriterDesc_WriteBlock((OOC_X86_Write__Writer)i0, (OOC_X86_SSA__Block)i1);
      return;
      ;
    }

    
    void OOC_X86_Write__WriterDesc_WriteBlock_WriteMerge(OOC_X86_SSA__MergeInstr instr) {
      register OOC_INT32 i0,i1,i2;
      OOC_X86_Write__Block dummy;

      i0 = (OOC_INT32)instr;
      i1 = (OOC_INT32)w;
      i0 = (OOC_INT32)OOC_X86_Write__WriterDesc_WriteBlock((OOC_X86_Write__Writer)i1, (OOC_X86_SSA__Block)i0);
      dummy = (OOC_X86_Write__Block)i0;
      i1 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_Write__Block.baseTypes[0]);
      OOC_X86_Write__BlockDesc_INIT((OOC_X86_Write__Block)i1, (OOC_X86_SSA__Block)(OOC_INT32)0);
      block = (OOC_X86_Write__Block)i1;
      OOC_X86_Write__BlockDesc_SetArc((OOC_X86_Write__Block)i0, (void*)((_check_pointer(i0, 17298))+12), (OOC_X86_Write__Block)i1, (-1), 37);
      i0 = (OOC_INT32)RT0__NewObject(_td_ADT_StringBuffer__StringBuffer.baseTypes[0]);
      ADT_StringBuffer__StringBufferDesc_INIT((ADT_StringBuffer__StringBuffer)i0, 1024);
      sb = (ADT_StringBuffer__StringBuffer)i0;
      i1 = (OOC_INT32)block;
      *(OOC_INT32*)(_check_pointer(i1, 17386)) = i0;
      i0 = (OOC_INT32)w;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17414))+8);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17414))+8);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 17421)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i0, (Object__Object)i1);
      return;
      ;
    }

    
    void OOC_X86_Write__WriterDesc_WriteBlock_MovMemReg(OOC_X86_SSA__Opnd fromMemReg, OOC_INT8 fromType, OOC_CHAR8 valueOpnd, OOC_X86_SSA__Result toReg) {
      register OOC_INT32 i0,i1,i2,i3,i4;
      OOC_INT8 toType;

      i0 = (OOC_INT32)toReg;
      i1 = *(OOC_INT8*)((_check_pointer(i0, 18008))+12);
      toType = i1;
      i2 = fromType;
      i3 = i2==i1;
      if (i3) goto l7;
      i3 = i1<5;
      if (i3) goto l5;
      OOC_X86_Write__WriterDesc_WriteBlock_OpcTT("movz", 5, i2, i1);
      goto l15;
l5:
      OOC_X86_Write__WriterDesc_WriteBlock_OpcTT("movs", 5, i2, i1);
      goto l15;
l7:
      i3 = valueOpnd;
      if (i3) goto l10;
      i3=0u;
      goto l12;
l10:
      i3 = (OOC_INT32)fromMemReg;
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 18100));
      i4 = *(OOC_INT8*)((_check_pointer(i0, 18078))+13);
      i3 = *(OOC_INT8*)((_check_pointer(i3, 18104))+13);
      i3 = i4==i3;
      
l12:
      if (!i3) goto l14;
      return;
l14:
      OOC_X86_Write__WriterDesc_WriteBlock_OpcTT("mov", 4, i2, 0);
l15:
      opndWidth = i2;
      i2 = valueOpnd;
      if (i2) goto l22;
      i2 = (OOC_INT32)fromMemReg;
      i3 = *(OOC_UINT8*)((_check_pointer(i2, 18589))+16);
      if (i3) goto l20;
      OOC_X86_Write__WriterDesc_WriteBlock_OpndMem((OOC_X86_SSA__Opnd)i2);
      goto l23;
l20:
      OOC_X86_Write__WriterDesc_WriteBlock_DirectOpnd((OOC_X86_SSA__Opnd)i2);
      goto l23;
l22:
      i2 = (OOC_INT32)instr;
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 18545));
      OOC_X86_Write__WriterDesc_WriteBlock_Opnd((OOC_X86_SSA__Opnd)i2);
l23:
      OOC_X86_Write__WriterDesc_WriteBlock_Comma();
      i0 = *(OOC_INT8*)((_check_pointer(i0, 18738))+13);
      OOC_X86_Write__WriterDesc_WriteBlock_RegT(i0, i1);
      return;
      ;
    }


  qtdData = (OOC_C_Naming__QualTypeData)(OOC_INT32)0;
  i0 = (OOC_INT32)RT0__NewObject(_td_ADT_StringBuffer__StringBuffer.baseTypes[0]);
  ADT_StringBuffer__StringBufferDesc_INIT((ADT_StringBuffer__StringBuffer)i0, 1024);
  sb = (ADT_StringBuffer__StringBuffer)i0;
  i1 = (OOC_INT32)w;
  i2 = (OOC_INT32)b;
  i3 = (OOC_INT32)OOC_X86_Write__WriterDesc_GetBlock((OOC_X86_Write__Writer)i1, (OOC_X86_SSA__Block)i2);
  block = (OOC_X86_Write__Block)i3;
  *(OOC_INT32*)(_check_pointer(i3, 18893)) = i0;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 18919))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 18919))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18926)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i1, (Object__Object)i3);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 18957))+48);
  instr = (OOC_X86_SSA__Instr)i0;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l103;
  i1 = (OOC_INT32)_c35;
  i2 = (OOC_INT32)_c36;
  i3 = (OOC_INT32)_c37;
  i4 = (OOC_INT32)_c38;
  i5 = (OOC_INT32)_c39;
  i6 = (OOC_INT32)_c40;
  i7 = (OOC_INT32)_c41;
  i8 = (OOC_INT32)_c42;
  
l3_loop:
  i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19020))+8);
  nextInstr = (OOC_X86_SSA__Instr)i9;
  i9 = OOC_X86_SSA__InstrDesc_IsLive((OOC_X86_SSA__Instr)i0);
  if (!i9) goto l76;
  i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19125))+4);
  i9 = i9!=(OOC_INT32)0;
  if (i9) goto l8;
  opndWidth = 0;
  goto l9;
l8:
  i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19177))+4);
  i9 = *(OOC_INT8*)((_check_pointer(i9, 19188))+12);
  opndWidth = i9;
l9:
  i9 = *(OOC_INT8*)((_check_pointer(i0, 19281))+20);
  switch (i9) {
  case 0:
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19361))+4);
    i0 = *(OOC_INT8*)((_check_pointer(i0, 19372))+12);
    type = i0;
    OOC_X86_Write__WriterDesc_WriteBlock_Opc("mov", 4);
    i0 = (OOC_INT32)sb;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 19413)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)),ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)((ADT_StringBuffer__StringBuffer)i0, 36u);
    i0 = (OOC_INT32)instr;
    OOC_X86_Write__WriterDesc_WriteBlock_Literal((OOC_X86_SSA__Instr)i0);
    OOC_X86_Write__WriterDesc_WriteBlock_Comma();
    i0 = (OOC_INT32)instr;
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19504))+4);
    OOC_X86_Write__WriterDesc_WriteBlock_Result((OOC_X86_SSA__Result)i0);
    goto l76;
  case 1:
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 19571));
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19580))+4);
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 19589));
    i0 = (OOC_INT32)OOC_X86_SSA__ResultDesc_GetConst((OOC_X86_SSA__Result)i0);
    i9 = (OOC_INT32)Object_BigInt__one;
    i0 = Object_BigInt__BigIntDesc_Equals((Object_BigInt__BigInt)i9, (Object__Object)i0);
    if (i0) goto l15;
    OOC_X86_Write__WriterDesc_WriteBlock_Opc("add", 4);
    i0 = (OOC_INT32)instr;
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 19696));
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19705))+4);
    OOC_X86_Write__WriterDesc_WriteBlock_Opnd((OOC_X86_SSA__Opnd)i0);
    OOC_X86_Write__WriterDesc_WriteBlock_Comma();
    goto l16;
l15:
    OOC_X86_Write__WriterDesc_WriteBlock_Opc("inc", 4);
l16:
    i0 = (OOC_INT32)instr;
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19775))+4);
    OOC_X86_Write__WriterDesc_WriteBlock_Result((OOC_X86_SSA__Result)i0);
    i0 = (OOC_INT32)instr;
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 19822));
    OOC_X86_Write__WriterDesc_WriteBlock_AssertResultMatch((OOC_X86_SSA__Opnd)i0);
    goto l76;
  case 2:
  case 22:
    i9 = *(OOC_INT8*)((_check_pointer(i0, 19887))+20);
    i9 = i9==22;
    if (!i9) goto l20;
    i9 = (OOC_INT32)sb;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i9, 19933)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1)),ADT_StringBuffer__StringBufferDesc_AppendLatin1)((ADT_StringBuffer__StringBuffer)i9, "\012\011pushl %edi", 13);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i9, 19982)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1)),ADT_StringBuffer__StringBufferDesc_AppendLatin1)((ADT_StringBuffer__StringBuffer)i9, "\012\011pushl %esi", 13);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i9, 20031)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1)),ADT_StringBuffer__StringBufferDesc_AppendLatin1)((ADT_StringBuffer__StringBuffer)i9, "\012\011pushl %ebx", 13);
l20:
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 20117));
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20126))+4);
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 20135));
    i0 = (OOC_INT32)OOC_X86_SSA__ResultDesc_GetConst((OOC_X86_SSA__Result)i0);
    i9 = (OOC_INT32)Object_BigInt__one;
    i0 = Object_BigInt__BigIntDesc_Equals((Object_BigInt__BigInt)i9, (Object__Object)i0);
    if (i0) goto l23;
    OOC_X86_Write__WriterDesc_WriteBlock_Opc("sub", 4);
    i0 = (OOC_INT32)instr;
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 20242));
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20251))+4);
    OOC_X86_Write__WriterDesc_WriteBlock_Opnd((OOC_X86_SSA__Opnd)i0);
    OOC_X86_Write__WriterDesc_WriteBlock_Comma();
    goto l24;
l23:
    OOC_X86_Write__WriterDesc_WriteBlock_Opc("dec", 4);
l24:
    i0 = (OOC_INT32)instr;
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20321))+4);
    OOC_X86_Write__WriterDesc_WriteBlock_Result((OOC_X86_SSA__Result)i0);
    i0 = (OOC_INT32)instr;
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 20368));
    OOC_X86_Write__WriterDesc_WriteBlock_AssertResultMatch((OOC_X86_SSA__Opnd)i0);
    goto l76;
  case 3:
    OOC_X86_Write__WriterDesc_WriteBlock_Opc("imul", 5);
    i0 = (OOC_INT32)instr;
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 20441));
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20450))+4);
    OOC_X86_Write__WriterDesc_WriteBlock_Opnd((OOC_X86_SSA__Opnd)i0);
    OOC_X86_Write__WriterDesc_WriteBlock_Comma();
    i0 = (OOC_INT32)instr;
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20503))+4);
    OOC_X86_Write__WriterDesc_WriteBlock_Result((OOC_X86_SSA__Result)i0);
    i0 = (OOC_INT32)instr;
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 20550));
    OOC_X86_Write__WriterDesc_WriteBlock_AssertResultMatch((OOC_X86_SSA__Opnd)i0);
    goto l76;
  case 5:
    OOC_X86_Write__WriterDesc_WriteBlock_Opc("neg", 4);
    i0 = (OOC_INT32)instr;
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 20621));
    OOC_X86_Write__WriterDesc_WriteBlock_Opnd((OOC_X86_SSA__Opnd)i0);
    i0 = (OOC_INT32)instr;
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 20666));
    OOC_X86_Write__WriterDesc_WriteBlock_AssertResultMatch((OOC_X86_SSA__Opnd)i0);
    goto l76;
  case 9:
  case 10:
  case 11:
  case 12:
  case 13:
  case 14:
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 20758));
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 20767));
    i0 = *(OOC_INT8*)((_check_pointer(i0, 20771))+12);
    opndWidth = i0;
    OOC_X86_Write__WriterDesc_WriteBlock_Opc("cmp", 4);
    i0 = (OOC_INT32)instr;
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 20820));
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20829))+4);
    OOC_X86_Write__WriterDesc_WriteBlock_Opnd((OOC_X86_SSA__Opnd)i0);
    OOC_X86_Write__WriterDesc_WriteBlock_Comma();
    i0 = (OOC_INT32)instr;
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 20880));
    OOC_X86_Write__WriterDesc_WriteBlock_Opnd((OOC_X86_SSA__Opnd)i0);
    goto l76;
  case 15:
    i9 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 20935));
    i9 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i9, 20944));
    i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i9, 20948))+4);
    cmp = (OOC_X86_SSA__Instr)i9;
    i10 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i9, 20991));
    i10 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i10, 21000));
    i9 = *(OOC_INT8*)((_check_pointer(i9, 21014))+20);
    i10 = *(OOC_INT8*)((_check_pointer(i10, 21004))+12);
    i9 = (OOC_INT32)OOC_X86_Write__OpcodeCC(i10, i9);
    i9 = (OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)i1,(void*)i9)),(void*)i5);
    str = (Object__String)i9;
    i10 = (OOC_INT32)sb;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i10, 21040)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i10, (Object__Object)i9);
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 21074));
    OOC_X86_Write__WriterDesc_WriteBlock_Opnd((OOC_X86_SSA__Opnd)i0);
    goto l76;
  case 17:
    goto l76;
  case 18:
    OOC_X86_Write__WriterDesc_WriteBlock_Opc0("ret", 4);
    goto l76;
  case 20:
    OOC_X86_Write__WriterDesc_WriteBlock_Opc0("call", 5);
    i0 = (OOC_INT32)instr;
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 21282));
    OOC_X86_Write__WriterDesc_WriteBlock_DirectOpnd((OOC_X86_SSA__Opnd)i0);
    goto l76;
  case 29:
    i0 = (OOC_INT32)w;
    i9 = (OOC_INT32)sb;
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21394))+52);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i9, 21382)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i9, (Object__Object)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)i6,(void*)i0)),(void*)i7)));
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i9, 21423)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1)),ADT_StringBuffer__StringBufferDesc_AppendLatin1)((ADT_StringBuffer__StringBuffer)i9, "\012\011lea -12(%ebp), %esp", 22);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i9, 21479)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1)),ADT_StringBuffer__StringBufferDesc_AppendLatin1)((ADT_StringBuffer__StringBuffer)i9, "\012\011popl %ebx", 12);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i9, 21525)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1)),ADT_StringBuffer__StringBufferDesc_AppendLatin1)((ADT_StringBuffer__StringBuffer)i9, "\012\011popl %esi", 12);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i9, 21571)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1)),ADT_StringBuffer__StringBufferDesc_AppendLatin1)((ADT_StringBuffer__StringBuffer)i9, "\012\011popl %edi", 12);
    OOC_X86_Write__WriterDesc_WriteBlock_Opc0("leave", 6);
    goto l76;
  case 26:
  case 16:
    i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21821))+4);
    i9 = *(OOC_INT8*)((_check_pointer(i9, 21832))+12);
    i9 = i9==9;
    if (i9) goto l36;
    i9=0u;
    goto l42;
l36:
    i9 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 21873));
    i9 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i9, 21882));
    i9 = *(OOC_INT8*)((_check_pointer(i9, 21886))+12);
    i9 = i9==3;
    if (i9) goto l39;
    i9 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 21929));
    i9 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i9, 21938));
    i9 = *(OOC_INT8*)((_check_pointer(i9, 21942))+12);
    i9 = i9==7;
    
    goto l42;
l39:
    i9=1u;
l42:
    if (i9) goto l56;
    i9 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 22023));
    i9 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i9, 22032));
    i9 = *(OOC_INT8*)((_check_pointer(i9, 22036))+12);
    i9 = i9==9;
    if (i9) goto l46;
    i9=0u;
    goto l52;
l46:
    i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22080))+4);
    i9 = *(OOC_INT8*)((_check_pointer(i9, 22091))+12);
    i9 = i9==3;
    if (i9) goto l49;
    i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22137))+4);
    i9 = *(OOC_INT8*)((_check_pointer(i9, 22148))+12);
    i9 = i9==7;
    
    goto l52;
l49:
    i9=1u;
l52:
    if (i9) goto l54;
    i9 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 22259));
    i9 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i9, 22268));
    i9 = *(OOC_INT8*)((_check_pointer(i9, 22272))+12);
    type = i9;
    
    goto l57;
l54:
    i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22201))+4);
    i9 = *(OOC_INT8*)((_check_pointer(i9, 22212))+12);
    type = i9;
    
    goto l57;
l56:
    type = 9;
    i9=9;
l57:
    i10 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22347))+4);
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 22319));
    OOC_X86_Write__WriterDesc_WriteBlock_MovMemReg((OOC_X86_SSA__Opnd)i0, i9, 1u, (OOC_X86_SSA__Result)i10);
    goto l76;
  case 19:
    i9 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 22422));
    i9 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i9, 22431));
    i10 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22473))+4);
    i9 = *(OOC_INT8*)((_check_pointer(i9, 22435))+12);
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 22406));
    OOC_X86_Write__WriterDesc_WriteBlock_MovMemReg((OOC_X86_SSA__Opnd)i0, i9, 1u, (OOC_X86_SSA__Result)i10);
    OOC_X86_Write__WriterDesc_WriteBlock_Opc0("jmp", 4);
    i0 = (OOC_INT32)w;
    i9 = (OOC_INT32)sb;
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22531))+52);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i9, 22522)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i9, (Object__Object)i0);
    goto l76;
  case 24:
    i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22602))+4);
    i10 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22652))+4);
    i9 = *(OOC_INT8*)((_check_pointer(i9, 22613))+12);
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 22586));
    OOC_X86_Write__WriterDesc_WriteBlock_MovMemReg((OOC_X86_SSA__Opnd)i0, i9, 0u, (OOC_X86_SSA__Result)i10);
    goto l76;
  case 25:
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 22711));
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22720))+4);
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 22729));
    i0 = *(OOC_INT8*)((_check_pointer(i0, 22733))+12);
    opndWidth = i0;
    OOC_X86_Write__WriterDesc_WriteBlock_Opc("mov", 4);
    i0 = (OOC_INT32)instr;
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 22782));
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22791))+4);
    OOC_X86_Write__WriterDesc_WriteBlock_Opnd((OOC_X86_SSA__Opnd)i0);
    OOC_X86_Write__WriterDesc_WriteBlock_Comma();
    i0 = (OOC_INT32)instr;
    i9 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 22840));
    i9 = *(OOC_UINT8*)((_check_pointer(i9, 22849))+16);
    if (i9) goto l63;
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 22945));
    OOC_X86_Write__WriterDesc_WriteBlock_OpndMem((OOC_X86_SSA__Opnd)i0);
    goto l76;
l63:
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 22893));
    OOC_X86_Write__WriterDesc_WriteBlock_DirectOpnd((OOC_X86_SSA__Opnd)i0);
    goto l76;
  case 27:
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 23018));
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23027))+4);
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 23036));
    i0 = *(OOC_INT8*)((_check_pointer(i0, 23040))+12);
    opndWidth = i0;
    OOC_X86_Write__WriterDesc_WriteBlock_Opc("push", 5);
    i0 = (OOC_INT32)instr;
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 23090));
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23099))+4);
    OOC_X86_Write__WriterDesc_WriteBlock_Opnd((OOC_X86_SSA__Opnd)i0);
    goto l76;
  case 32:
    i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_NthOpnd((OOC_X86_SSA__Instr)i0, 2);
    opnd = (OOC_X86_SSA__Opnd)i0;
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 23196));
    i0 = *(OOC_INT8*)((_check_pointer(i0, 23200))+12);
    opndWidth = i0;
    OOC_X86_Write__WriterDesc_WriteBlock_Opc("mov", 4);
    i0 = (OOC_INT32)opnd;
    OOC_X86_Write__WriterDesc_WriteBlock_Opnd((OOC_X86_SSA__Opnd)i0);
    i0 = (OOC_INT32)sb;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 23263)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i3);
    i0 = (OOC_INT32)instr;
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 23301));
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23310))+4);
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 23319));
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23323))+4);
    OOC_X86_Write__WriterDesc_WriteBlock_Literal((OOC_X86_SSA__Instr)i0);
    i0 = (OOC_INT32)sb;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 23344)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i4);
    goto l76;
  case 33:
    OOC_X86_Write__WriterDesc_WriteBlock_Opc("mov", 4);
    i0 = (OOC_INT32)sb;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 23418)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i2);
    i0 = (OOC_INT32)instr;
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 23454));
    OOC_X86_Write__WriterDesc_WriteBlock_Opnd((OOC_X86_SSA__Opnd)i0);
    i0 = (OOC_INT32)sb;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 23478)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i8);
    OOC_X86_Write__WriterDesc_WriteBlock_Comma();
    i0 = (OOC_INT32)instr;
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23533))+4);
    OOC_X86_Write__WriterDesc_WriteBlock_Result((OOC_X86_SSA__Result)i0);
    goto l76;
  case 34:
    goto l76;
  case 37:
  case 42:
    OOC_X86_Write__WriterDesc_WriteBlock_FixGatedValues((OOC_X86_SSA__Instr)i0);
    i0 = (OOC_INT32)instr;
    i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_MergingTarget((OOC_X86_SSA__Instr)i0);
    i9 = (OOC_INT32)w;
    i0 = (OOC_INT32)OOC_X86_Write__WriterDesc_GetBlock((OOC_X86_Write__Writer)i9, (OOC_X86_SSA__Block)i0);
    i9 = (OOC_INT32)block;
    OOC_X86_Write__BlockDesc_SetArc((OOC_X86_Write__Block)i9, (void*)((_check_pointer(i9, 23739))+12), (OOC_X86_Write__Block)i0, (-1), 37);
    nextInstr = (OOC_X86_SSA__Instr)(OOC_INT32)0;
    goto l76;
  case 38:
    goto l76;
  case 40:
    OOC_X86_Write__WriterDesc_WriteBlock_FixGatedValues((OOC_X86_SSA__Instr)i0);
    goto l76;
  case 43:
    OOC_X86_Write__WriterDesc_WriteBlock_FixGatedValues((OOC_X86_SSA__Instr)i0);
    i0 = (OOC_INT32)instr;
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 24126)))), &_td_OOC_X86_SSA__LoopBackedgeInstrDesc, 24126)), 24144))+48);
    i9 = (OOC_INT32)w;
    i0 = (OOC_INT32)OOC_X86_Write__WriterDesc_GetBlock((OOC_X86_Write__Writer)i9, (OOC_X86_SSA__Block)i0);
    i9 = (OOC_INT32)block;
    OOC_X86_Write__BlockDesc_SetArc((OOC_X86_Write__Block)i9, (void*)((_check_pointer(i9, 24077))+12), (OOC_X86_Write__Block)i0, (-1), 37);
    goto l76;
  case 41:
    goto l76;
  default:
    _failed_case(i9, 19271);
    goto l76;
  }
l76:
  i0 = (OOC_INT32)instr;
  i9 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 24281)))), &_td_OOC_X86_SSA__BranchInstrDesc);
  if (i9) goto l90;
  i9 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 24706)))), &_td_OOC_X86_SSA__MergeInstrDesc);
  if (i9) goto l88;
  i9 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 24806)))), &_td_OOC_X86_SSA__LoopStartInstrDesc);
  if (i9) goto l86;
  i9 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 24879)))), &_td_OOC_X86_SSA__BlockDesc);
  if (!i9) goto l98;
  Log__Type("instr", 6, (void*)i0);
  OOC_X86_Debug__Log("instr", 6, (OOC_X86_SSA__Node)i0);
  _assert(0u, 127, 24965);
  goto l98;
l86:
  i9 = (OOC_INT32)w;
  i0 = (OOC_INT32)OOC_X86_Write__WriterDesc_WriteBlock((OOC_X86_Write__Writer)i9, (OOC_X86_SSA__Block)i0);
  dummy = (OOC_X86_Write__Block)i0;
  goto l98;
l88:
  i9 = *(OOC_INT8*)((_check_pointer(i0, 24744))+20);
  _assert((i9==41), 127, 24732);
  OOC_X86_Write__WriterDesc_WriteBlock_WriteMerge((OOC_X86_SSA__MergeInstr)i0);
  goto l98;
l90:
  i9 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 24320));
  i9 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i9, 24329));
  i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i9, 24333))+4);
  cmp = (OOC_X86_SSA__Instr)i9;
  i10 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24358))+56);
  i10 = _check_pointer(i10, 24364);
  i11 = OOC_ARRAY_LENGTH(i10, 0);
  i10 = (OOC_INT32)*(OOC_INT32*)(i10+(_check_index(0, i11, OOC_UINT8, 24364))*4);
  i10 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i10, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i10, 24370)))), &_td_OOC_X86_SSA__MergeInstrDesc, 24370)), 24381))+56);
  i10 = i10!=(OOC_INT32)0;
  if (i10) goto l93;
  i10 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24536))+56);
  i10 = _check_pointer(i10, 24542);
  i11 = OOC_ARRAY_LENGTH(i10, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24520))+56);
  i0 = _check_pointer(i0, 24526);
  i12 = OOC_ARRAY_LENGTH(i0, 0);
  i10 = (OOC_INT32)*(OOC_INT32*)(i10+(_check_index(1, i11, OOC_UINT8, 24542))*4);
  i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i12, OOC_UINT8, 24526))*4);
  OOC_X86_Write__WriterDesc_WriteBlock_WriteBranch2((OOC_X86_SSA__Instr)i9, 1u, (OOC_X86_SSA__Block)i0, (OOC_X86_SSA__Block)i10);
  goto l94;
l93:
  i10 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24456))+56);
  i10 = _check_pointer(i10, 24462);
  i11 = OOC_ARRAY_LENGTH(i10, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24440))+56);
  i0 = _check_pointer(i0, 24446);
  i12 = OOC_ARRAY_LENGTH(i0, 0);
  i10 = (OOC_INT32)*(OOC_INT32*)(i10+(_check_index(0, i11, OOC_UINT8, 24462))*4);
  i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(1, i12, OOC_UINT8, 24446))*4);
  OOC_X86_Write__WriterDesc_WriteBlock_WriteBranch2((OOC_X86_SSA__Instr)i9, 0u, (OOC_X86_SSA__Block)i0, (OOC_X86_SSA__Block)i10);
l94:
  i0 = (OOC_INT32)instr;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24584))+52);
  i0 = _type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 24597)))), &_td_OOC_X86_SSA__MergeInstrDesc, 24597);
  merge = (OOC_X86_SSA__MergeInstr)i0;
  i9 = *(OOC_INT8*)((_check_pointer(i0, 24627))+20);
  i9 = i9==36;
  if (!i9) goto l98;
  OOC_X86_Write__WriterDesc_WriteBlock_WriteMerge((OOC_X86_SSA__MergeInstr)i0);
l98:
  i0 = (OOC_INT32)nextInstr;
  instr = (OOC_X86_SSA__Instr)i0;
  i9 = i0!=(OOC_INT32)0;
  if (i9) goto l3_loop;
l103:
  i0 = (OOC_INT32)block;
  return (OOC_X86_Write__Block)i0;
  ;
}

void OOC_X86_Write__WriterDesc_WriteFunction(OOC_X86_Write__Writer w, OOC_X86_SSA__FunctionBlock b) {
  register OOC_INT32 i0,i1;
  OOC_X86_Write__Block dummy;
  auto Object__String OOC_X86_Write__WriterDesc_WriteFunction_StartFunction(OOC_X86_SSA__FunctionBlock fctBlock);
  auto void OOC_X86_Write__WriterDesc_WriteFunction_EndFunction(void);
    
    Object__String OOC_X86_Write__WriterDesc_WriteFunction_StartFunction(OOC_X86_SSA__FunctionBlock fctBlock) {
      register OOC_INT32 i0,i1,i2;
      auto OOC_CHAR8 OOC_X86_Write__WriterDesc_WriteFunction_StartFunction_IsGlobal(OOC_SymbolTable__ProcDecl procDecl);
        
        OOC_CHAR8 OOC_X86_Write__WriterDesc_WriteFunction_StartFunction_IsGlobal(OOC_SymbolTable__ProcDecl procDecl) {
          register OOC_INT32 i0,i1;

          i0 = (OOC_INT32)procDecl;
          i1 = *(OOC_INT8*)((_check_pointer(i0, 25338))+28);
          i1 = i1!=0;
          if (i1) goto l3;
          i0 = *(OOC_INT32*)((_check_pointer(i0, 25397))+56);
          i0 = i0>=0;
          
          goto l4;
l3:
          i0=1u;
l4:
          return i0;
          ;
        }


      i0 = (OOC_INT32)w;
      i1 = (OOC_INT32)RT0__NewObject(_td__qtd5.baseTypes[0]);
      ADT_Dictionary__DictionaryDesc_INIT((ADT_Dictionary__Dictionary)i1);
      *(OOC_INT32*)((_check_pointer(i0, 25459))+12) = i1;
      i0 = (OOC_INT32)w;
      i1 = (OOC_INT32)RT0__NewObject(_td__qtd7.baseTypes[0]);
      ADT_ArrayList__ArrayListDesc_INIT((ADT_ArrayList__ArrayList)i1, 16);
      *(OOC_INT32*)((_check_pointer(i0, 25523))+8) = i1;
      i0 = (OOC_INT32)w;
      i1 = (OOC_INT32)fctBlock;
      *(OOC_INT32*)((_check_pointer(i0, 25578))+44) = i1;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 25619))+56);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 25628))+72);
      i2 = i2==(OOC_INT32)0;
      if (i2) goto l3;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 25779))+56);
      i2 = (OOC_INT32)OOC_C_Naming__NameOfDeclaration((OOC_SymbolTable__Declaration)i2);
      *(OOC_INT32*)((_check_pointer(i0, 25737))+48) = i2;
      goto l4;
l3:
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 25692));
      i2 = (OOC_INT32)OOC_C_Naming__NameOfModuleInit((OOC_SymbolTable__Module)i2, 0u);
      *(OOC_INT32*)((_check_pointer(i0, 25658))+48) = i2;
l4:
      i0 = (OOC_INT32)w;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25816))+4);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25816))+4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 25818)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i0, (Object__Object)((OOC_INT32)_c43));
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 25871))+56);
      i0 = OOC_X86_Write__WriterDesc_WriteFunction_StartFunction_IsGlobal((OOC_SymbolTable__ProcDecl)i0);
      if (!i0) goto l7;
      i0 = (OOC_INT32)w;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25896))+4);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25926))+48);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25896))+4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 25898)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i0, (Object__Object)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)_c44),(void*)i2)));
l7:
      i0 = (OOC_INT32)w;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25952))+4);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25983))+48);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25952))+4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 25954)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i0, (Object__Object)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)_c45),(void*)i2)),(void*)((OOC_INT32)_c46))));
      i0 = (OOC_INT32)w;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26012))+4);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26031))+48);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26012))+4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 26014)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i0, (Object__Object)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)_c47),(void*)i2)),(void*)((OOC_INT32)_c48))));
      i0 = (OOC_INT32)w;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26065))+48);
      return (Object__String)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)_c49),(void*)i0));
      ;
    }

    
    void OOC_X86_Write__WriterDesc_WriteFunction_EndFunction(void) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5;
      OOC_INT32 i;
      OOC_X86_Write__Block block;
      OOC_X86_Write__Block nextBlock;
      OOC_X86_Write__Arc incoming;
      OOC_X86_Write__Arc next;

      i0 = (OOC_INT32)w;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26240))+8);
      i = 0;
      i0 = *(OOC_INT32*)((_check_pointer(i0, 26247))+4);
      i1 = 0<i0;
      if (!i1) goto l19;
      i1=0;
l3_loop:
      i2 = (OOC_INT32)w;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 26276))+8);
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 26283));
      i2 = _check_pointer(i2, 26289);
      i3 = OOC_ARRAY_LENGTH(i2, 0);
      i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i1, i3, OOC_UINT32, 26289))*4);
      block = (OOC_X86_Write__Block)i2;
      i3 = OOC_X86_Write__BlockDesc_IsEmpty((OOC_X86_Write__Block)i2);
      if (!i3) goto l14;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 26348))+12);
      _assert((i3!=0), 127, 26336);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 26390))+12);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 26395))+4);
      nextBlock = (OOC_X86_Write__Block)i3;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 26438))+4);
      incoming = (OOC_X86_Write__Arc)i2;
      i4 = i2!=0;
      if (!i4) goto l14;
l8_loop:
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 26517))+12);
      next = (OOC_X86_Write__Arc)i4;
      OOC_X86_Write__ArcDesc_ReplaceTo((OOC_X86_Write__Arc)i2, (OOC_X86_Write__Block)i3);
      incoming = (OOC_X86_Write__Arc)i4;
      i2 = i4!=0;
      if (!i2) goto l14;
      i2=i4;
      goto l8_loop;
l14:
      i1 = i1+1;
      i = i1;
      i2 = i1<i0;
      if (i2) goto l3_loop;
l19:
      i0 = (OOC_INT32)w;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26696))+8);
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 26703));
      i1 = _check_pointer(i1, 26709);
      i2 = OOC_ARRAY_LENGTH(i1, 0);
      i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 26709))*4);
      i2 = *(OOC_INT32*)((_check_pointer(i0, 26723))+16);
      *(OOC_INT32*)((_check_pointer(i1, 26712))+20) = i2;
      i1 = *(OOC_INT32*)((_check_pointer(i0, 26747))+16);
      *(OOC_INT32*)((_check_pointer(i0, 26747))+16) = (i1+1);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26782))+8);
      i0 = *(OOC_INT32*)((_check_pointer(i0, 26789))+4);
      i = 1;
      i1 = 1<i0;
      if (!i1) goto l34;
      i1=1;
l22_loop:
      i2 = (OOC_INT32)w;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 26818))+8);
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 26825));
      i3 = _check_pointer(i3, 26831);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i1, i4, OOC_UINT32, 26831))*4);
      block = (OOC_X86_Write__Block)i3;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 26853))+4);
      i4 = i4==0;
      if (i4) goto l25;
      i4 = *(OOC_INT32*)((_check_pointer(i2, 27071))+16);
      *(OOC_INT32*)((_check_pointer(i3, 27060))+20) = i4;
      i3 = *(OOC_INT32*)((_check_pointer(i2, 27099))+16);
      *(OOC_INT32*)((_check_pointer(i2, 27099))+16) = (i3+1);
      goto l29;
l25:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 26901))+8);
      _assert((i2==0), 127, 26889);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 26936))+12);
      i2 = i2!=0;
      if (!i2) goto l28;
      OOC_X86_Write__ClearArc((void*)((_check_pointer(i3, 26980))+12));
l28:
      *(OOC_INT32*)((_check_pointer(i3, 27018))+20) = (-1);
l29:
      i1 = i1+1;
      i = i1;
      i2 = i1<i0;
      if (i2) goto l22_loop;
l34:
      i0 = (OOC_INT32)w;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27165))+8);
      i0 = *(OOC_INT32*)((_check_pointer(i0, 27172))+4);
      i = 0;
      i1 = 0<i0;
      if (!i1) goto l52;
      i1=0;
l37_loop:
      i2 = (OOC_INT32)w;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 27201))+8);
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 27208));
      i3 = _check_pointer(i3, 27214);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i1, i4, OOC_UINT32, 27214))*4);
      block = (OOC_X86_Write__Block)i3;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 27236))+4);
      i4 = i4!=0;
      if (!i4) goto l40;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 27273))+4);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 27273))+4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 27275)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i2, "\012.L", 4);
      i2 = (OOC_INT32)w;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 27309))+4);
      i5 = *(OOC_INT32*)((_check_pointer(i3, 27327))+20);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 27309))+4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 27311)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i2, i5, 0);
      i2 = (OOC_INT32)w;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 27350))+4);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 27350))+4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 27352)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i2, ":", 2);
l40:
      i2 = (OOC_INT32)w;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 27393))+4);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 27393))+4);
      i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 27413));
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 27395)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i2, (Object__Object)i5);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 27447))+8);
      i2 = i2!=0;
      if (i2) goto l43;
      i2=0u;
      goto l45;
l43:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 27470))+8);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 27477))+4);
      i4 = *(OOC_INT32*)((_check_pointer(i3, 27494))+20);
      i2 = *(OOC_INT32*)((_check_pointer(i2, 27480))+20);
      i2 = i2==(i4+1);
      
l45:
      if (!i2) goto l47;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 27632))+8);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 27639))+4);
      nextBlock = (OOC_X86_Write__Block)i2;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 27682))+12);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 27687))+4);
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 27659))+8);
      OOC_X86_Write__ArcDesc_ReplaceTo((OOC_X86_Write__Arc)i5, (OOC_X86_Write__Block)i4);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 27708))+12);
      OOC_X86_Write__ArcDesc_ReplaceTo((OOC_X86_Write__Arc)i4, (OOC_X86_Write__Block)i2);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 27751))+8);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 27787))+8);
      i4 = *(OOC_INT8*)((_check_pointer(i4, 27794))+9);
      i4 = OOC_X86_Write__NegateBranch(i4);
      *(OOC_INT8*)((_check_pointer(i2, 27758))+9) = i4;
l47:
      i2 = (OOC_INT32)w;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 27844))+8);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 27835))+4);
      OOC_X86_Write__WriteArc((IO_TextRider__Writer)i2, (OOC_X86_Write__Arc)i4);
      i2 = (OOC_INT32)w;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 27881))+12);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 27872))+4);
      OOC_X86_Write__WriteArc((IO_TextRider__Writer)i2, (OOC_X86_Write__Arc)i3);
      i1 = i1+1;
      i = i1;
      i2 = i1<i0;
      if (i2) goto l37_loop;
l52:
      i0 = (OOC_INT32)w;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27938))+48);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27907))+4);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27952))+48);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27907))+4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 27909)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i0, (Object__Object)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)_c50),(void*)i1)),(void*)((OOC_INT32)_c51))),(void*)i3)));
      return;
      ;
    }


  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)b;
  i1 = (OOC_INT32)OOC_X86_Write__WriterDesc_WriteFunction_StartFunction((OOC_X86_SSA__FunctionBlock)i1);
  *(OOC_INT32*)((_check_pointer(i0, 27997))+52) = i1;
  i0 = (OOC_INT32)b;
  i1 = (OOC_INT32)w;
  i0 = (OOC_INT32)OOC_X86_Write__WriterDesc_WriteBlock((OOC_X86_Write__Writer)i1, (OOC_X86_SSA__Block)i0);
  dummy = (OOC_X86_Write__Block)i0;
  OOC_X86_Write__WriterDesc_WriteFunction_EndFunction();
  return;
  ;
}

void OOC_OOC_X86_Write_init(void) {
  _c0 = Object__NewLatin1Char(101u);
  _c1 = Object__NewLatin1Region("ne", 3, 0, 2);
  _c2 = Object__NewLatin1Char(98u);
  _c3 = Object__NewLatin1Region("be", 3, 0, 2);
  _c4 = Object__NewLatin1Char(97u);
  _c5 = Object__NewLatin1Region("ae", 3, 0, 2);
  _c6 = Object__NewLatin1Char(101u);
  _c7 = Object__NewLatin1Region("ne", 3, 0, 2);
  _c8 = Object__NewLatin1Char(108u);
  _c9 = Object__NewLatin1Region("le", 3, 0, 2);
  _c10 = Object__NewLatin1Char(103u);
  _c11 = Object__NewLatin1Region("ge", 3, 0, 2);
  _c12 = Object__NewLatin1Region("mp", 3, 0, 2);
  _c13 = Object__NewLatin1Region("\012\011j", 4, 0, 3);
  _c14 = Object__NewLatin1Region(" .L", 4, 0, 3);
  _c15 = Object__NewLatin1Region("\012\011.local ", 10, 0, 9);
  _c16 = Object__NewLatin1Region("\012\011.comm ", 9, 0, 8);
  _c17 = Object__NewLatin1Char(44u);
  _c18 = Object__NewLatin1Region(".LS", 4, 0, 3);
  _c19 = Object__NewLatin1Char(10u);
  _c20 = Object__NewLatin1Char(58u);
  _c21 = Object__NewLatin1Region("\012\011.string \"", 12, 0, 11);
  _c22 = Object__NewLatin1Char(34u);
  _c23 = Object__NewLatin1Region("\012.global ", 10, 0, 9);
  _c24 = Object__NewLatin1Region("\012\011.type ", 9, 0, 8);
  _c25 = Object__NewLatin1Region(", @function", 12, 0, 11);
  _c26 = Object__NewLatin1Char(10u);
  _c27 = Object__NewLatin1Char(58u);
  _c28 = Object__NewLatin1Region("\012\011call ", 8, 0, 7);
  _c29 = Object__NewLatin1Region("\012\011ret", 6, 0, 5);
  _c30 = Object__NewLatin1Region("\012\011.size ", 9, 0, 8);
  _c31 = Object__NewLatin1Region(", .-", 5, 0, 4);
  _c32 = Object__NewLatin1Char(48u);
  _c33 = Object__NewLatin1Region("0x", 3, 0, 2);
  _c34 = Object__NewLatin1Region("_mid", 5, 0, 4);
  _c35 = Object__NewLatin1Region("set", 4, 0, 3);
  _c36 = Object__NewLatin1Region("-4(", 4, 0, 3);
  _c37 = Object__NewLatin1Region(", ", 3, 0, 2);
  _c38 = Object__NewLatin1Region("(%esp)", 7, 0, 6);
  _c39 = Object__NewLatin1Char(32u);
  _c40 = Object__NewLatin1Char(10u);
  _c41 = Object__NewLatin1Char(58u);
  _c42 = Object__NewLatin1Char(41u);
  _c43 = Object__NewLatin1Region("\012\011.p2align 4,,15", 17, 0, 16);
  _c44 = Object__NewLatin1Region("\012.global ", 10, 0, 9);
  _c45 = Object__NewLatin1Region("\012\011.type ", 9, 0, 8);
  _c46 = Object__NewLatin1Region(", @function", 12, 0, 11);
  _c47 = Object__NewLatin1Char(10u);
  _c48 = Object__NewLatin1Char(58u);
  _c49 = Object__NewLatin1Region(".LE_", 5, 0, 4);
  _c50 = Object__NewLatin1Region("\012\011.size ", 9, 0, 8);
  _c51 = Object__NewLatin1Region(", .-", 5, 0, 4);

  return;
  ;
}

/* --- */
