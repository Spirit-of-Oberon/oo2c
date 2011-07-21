#include <OOC/X86/Write.d>
#include <__oo2c.h>
#include <setjmp.h>

void OOC_X86_Write__BlockDesc_INIT(OOC_X86_Write__Block block, OOC_X86_SSA__Block blockInstr) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)block;
  *(OOC_INT32*)(_check_pointer(i0, 1470)) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 1501))+4) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 1532))+8) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 1557))+12) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 1580))+16) = 0;
  i1 = (OOC_INT32)blockInstr;
  *(OOC_INT32*)((_check_pointer(i0, 1611))+20) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 1647))+24) = 0;
  return;
  ;
}

OOC_CHAR8 OOC_X86_Write__BlockDesc_IsEmpty(OOC_X86_Write__Block block) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)block;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 1743))+8);
  i1 = i1==(OOC_INT32)0;
  if (i1) goto l3;
  i0=0u;
  goto l4;
l3:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 1766));
  i0 = *(OOC_INT32*)((_check_pointer(i0, 1779))+4);
  i0 = i0==0;
  
l4:
  return i0;
  ;
}

static void OOC_X86_Write__AddToIncoming(OOC_X86_Write__Block block, OOC_X86_Write__Arc arc) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)arc;
  i1 = (OOC_INT32)block;
  *(OOC_INT32*)((_check_pointer(i0, 1873))+4) = i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 1916))+4);
  *(OOC_INT32*)((_check_pointer(i0, 1894))+12) = i2;
  *(OOC_INT32*)((_check_pointer(i1, 1940))+4) = i0;
  return;
  ;
}

void OOC_X86_Write__BlockDesc_SetArc(OOC_X86_Write__Block block, OOC_X86_Write__Arc *arc, OOC_X86_Write__Block to, OOC_INT8 opcode) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)*arc;
  _assert((i0==(OOC_INT32)0), 127, 2072);
  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_Write__Arc.baseTypes[0]);
  *arc = (OOC_X86_Write__Arc)i0;
  i1 = (OOC_INT32)block;
  *(OOC_INT32*)(_check_pointer(i0, 2112)) = i1;
  i0 = (OOC_INT32)*arc;
  *(OOC_INT8*)((_check_pointer(i0, 2135))+8) = (-1);
  i0 = (OOC_INT32)*arc;
  i1 = opcode;
  *(OOC_INT8*)((_check_pointer(i0, 2155))+9) = i1;
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
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2319))+4);
  block = (OOC_X86_Write__Block)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 2337))+4);
  i2 = i2==i0;
  if (i2) goto l12;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 2436))+4);
  ptr = (OOC_X86_Write__Arc)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 2467))+12);
  i2 = i2!=i0;
  if (!i2) goto l11;
l6_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 2509))+12);
  ptr = (OOC_X86_Write__Arc)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 2467))+12);
  i2 = i2!=i0;
  if (i2) goto l6_loop;
l11:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2564))+12);
  *(OOC_INT32*)((_check_pointer(i1, 2544))+12) = i2;
  goto l13;
l12:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2394))+12);
  *(OOC_INT32*)((_check_pointer(i1, 2374))+4) = i2;
l13:
  *(OOC_INT32*)((_check_pointer(i0, 2595))+4) = (OOC_INT32)0;
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
  case 13:
    return 14;
    goto l9;
  case 14:
    return 13;
    goto l9;
  case 15:
    return 18;
    goto l9;
  case 16:
    return 17;
    goto l9;
  case 17:
    return 16;
    goto l9;
  case 18:
    return 15;
    goto l9;
  default:
    _failed_case(i0, 2928);
    goto l9;
  }
l9:
  _failed_function(2874); return 0;
  ;
}

static Object__String OOC_X86_Write__OpcodeCC(OOC_INT8 type, OOC_INT8 opcode) {
  register OOC_INT32 i0,i1;
  Object__String str;

  i0 = opcode;
  i1 = i0==49;
  if (i1) goto l23;
  i1 = type;
  i1 = i1<5;
  if (i1) goto l13;
  switch (i0) {
  case 13:
    str = (Object__String)((OOC_INT32)_c0);
    goto l24;
  case 14:
    str = (Object__String)((OOC_INT32)_c1);
    goto l24;
  case 15:
    str = (Object__String)((OOC_INT32)_c2);
    goto l24;
  case 16:
    str = (Object__String)((OOC_INT32)_c3);
    goto l24;
  case 17:
    str = (Object__String)((OOC_INT32)_c4);
    goto l24;
  case 18:
    str = (Object__String)((OOC_INT32)_c5);
    goto l24;
  default:
    _failed_case(i0, 3629);
    goto l24;
  }
l13:
  switch (i0) {
  case 13:
    str = (Object__String)((OOC_INT32)_c6);
    goto l24;
  case 14:
    str = (Object__String)((OOC_INT32)_c7);
    goto l24;
  case 15:
    str = (Object__String)((OOC_INT32)_c8);
    goto l24;
  case 16:
    str = (Object__String)((OOC_INT32)_c9);
    goto l24;
  case 17:
    str = (Object__String)((OOC_INT32)_c10);
    goto l24;
  case 18:
    str = (Object__String)((OOC_INT32)_c11);
    goto l24;
  default:
    _failed_case(i0, 3374);
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
  i1 = *(OOC_INT8*)((_check_pointer(i0, 3954))+9);
  i1 = i1!=49;
  if (i1) goto l6;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3979))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 3994));
  i2 = *(OOC_INT32*)((_check_pointer(i2, 3999))+24);
  i1 = *(OOC_INT32*)((_check_pointer(i1, 3982))+24);
  i1 = i1!=(i2+1);
  
  goto l9;
l6:
  i1=1u;
l9:
  if (!i1) goto l11;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 4057))+8);
  i2 = *(OOC_INT8*)((_check_pointer(i0, 4067))+9);
  i1 = (OOC_INT32)OOC_X86_Write__OpcodeCC(i1, i2);
  i2 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 4022)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i2, (Object__Object)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)_c13),(void*)i1)),(void*)((OOC_INT32)_c14))));
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4105))+4);
  i0 = *(OOC_INT32*)((_check_pointer(i0, 4108))+24);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 4091)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i2, i0, 0);
l11:
  return;
  ;
}

void OOC_X86_Write__WriterDesc_INIT(OOC_X86_Write__Writer w, OOC_SymbolTable__Module module, IO__ByteChannel ch) {
  register OOC_INT32 i0,i1,i2;
  OOC_INT32 i;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)module;
  *(OOC_INT32*)(_check_pointer(i0, 4250)) = i1;
  i1 = (OOC_INT32)ch;
  i1 = (OOC_INT32)IO_TextRider__ConnectWriter((IO__ByteChannel)i1);
  *(OOC_INT32*)((_check_pointer(i0, 4274))+4) = i1;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4314))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4314))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4316)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i2, "\011.arch pentium4", 16);
  *(OOC_INT32*)((_check_pointer(i0, 4374))+16) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 4398))+20) = 0;
  i = 0;
  i1=0;
l1_loop:
  i2 = (OOC_INT32)RT0__NewObject(_td__qtd1.baseTypes[0]);
  ADT_Dictionary__DictionaryDesc_INIT((ADT_Dictionary__Dictionary)i2);
  *(OOC_INT32*)(((_check_pointer(i0, 4462))+24)+(_check_index(i1, 19, OOC_UINT32, 4472))*4) = i2;
  i2 = (OOC_INT32)RT0__NewObject(_td__qtd3.baseTypes[0]);
  ADT_ArrayList__ArrayListDesc_INIT((ADT_ArrayList__ArrayList)i2, 8);
  *(OOC_INT32*)(((_check_pointer(i0, 4506))+100)+(_check_index(i1, 19, OOC_UINT32, 4519))*4) = i2;
  i1 = i1+1;
  i = i1;
  i2 = i1<=18;
  if (i2) goto l1_loop;
l5:
  return;
  ;
}

OOC_X86_Write__Block OOC_X86_Write__WriterDesc_GetBlock(OOC_X86_Write__Writer w, OOC_X86_SSA__Block b) {
  register OOC_INT32 i0,i1,i2;
  OOC_X86_Write__Block block;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4668))+12);
  i2 = (OOC_INT32)b;
  i1 = ADT_Dictionary__DictionaryDesc_HasKey((ADT_Dictionary__Dictionary)i1, (Object__Object)i2);
  if (i1) goto l3;
  i1 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_Write__Block.baseTypes[0]);
  OOC_X86_Write__BlockDesc_INIT((OOC_X86_Write__Block)i1, (OOC_X86_SSA__Block)i2);
  block = (OOC_X86_Write__Block)i1;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4771))+12);
  ADT_Dictionary__DictionaryDesc_Set((ADT_Dictionary__Dictionary)i0, (Object__Object)i2, (Object__Object)i1);
  return (OOC_X86_Write__Block)i1;
  goto l4;
l3:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4707))+12);
  i0 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i0, (Object__Object)i2);
  return (OOC_X86_Write__Block)i0;
l4:
  _failed_function(4599); return 0;
  ;
}

void OOC_X86_Write__WriterDesc_RuntimeData(OOC_X86_Write__Writer w) {
  register OOC_INT32 i0,i1,i2;
  ADT_StringBuffer__StringBuffer sb;

  i0 = (OOC_INT32)RT0__NewObject(_td_ADT_StringBuffer__StringBuffer.baseTypes[0]);
  ADT_StringBuffer__StringBufferDesc_INIT((ADT_StringBuffer__StringBuffer)i0, 2048);
  sb = (ADT_StringBuffer__StringBuffer)i0;
  i1 = (OOC_INT32)w;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 5003));
  OOC_X86_RuntimeData__Write((ADT_StringBuffer__StringBuffer)i0, (OOC_SymbolTable__Module)i2);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 5018))+4);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 5018))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 5020)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i1, (Object__Object)i0);
  return;
  ;
}

void OOC_X86_Write__WriterDesc_ModuleVariables(OOC_X86_Write__Writer w) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
  OOC_SymbolTable__Item item;
  Object__String name;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5164));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 5171))+8);
  item = (OOC_SymbolTable__Item)i1;
  i2 = i1!=0;
  if (!i2) goto l14;
  i2 = (OOC_INT32)_c15;
  i3 = (OOC_INT32)_c16;
  i4 = (OOC_INT32)_c17;
  
l3_loop:
  i5 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5226)))), &_td_OOC_SymbolTable__VarDeclDesc);
  if (!i5) goto l9;
  i5 = (OOC_INT32)OOC_C_Naming__NameOfDeclaration((OOC_SymbolTable__Declaration)i1);
  name = (Object__String)i5;
  i6 = *(OOC_INT8*)((_check_pointer(i1, 5307))+28);
  i6 = i6==0;
  if (!i6) goto l8;
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5358))+4);
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5358))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 5360)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i7, (Object__Object)((OOC_INT32)Object__Concat2((void*)i2,(void*)i5)));
l8:
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5418))+4);
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5418))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 5420)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i7, (Object__Object)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)i3,(void*)i5)),(void*)i4)));
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 5485))+48);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5468))+4);
  i5 = *(OOC_INT32*)((_check_pointer(i5, 5490))+32);
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5468))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 5470)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i7, i5, 0);
l9:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 5562));
  item = (OOC_SymbolTable__Item)i1;
  i5 = i1!=0;
  if (i5) goto l3_loop;
l14:
  return;
  ;
}

Object__String OOC_X86_Write__WriterDesc_ConstSymbol(OOC_X86_Write__Writer w, Object__Object value, OOC_INT16 type) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  ADT_Dictionary__Dictionary dict;
  ADT_ArrayList__ArrayList array;

  i0 = (OOC_INT32)w;
  i1 = type;
  i2 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i0, 5811))+24)+(_check_index(i1, 19, OOC_UINT16, 5821))*4);
  dict = (ADT_Dictionary__Dictionary)i2;
  i1 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i0, 5843))+100)+(_check_index(i1, 19, OOC_UINT16, 5856))*4);
  array = (ADT_ArrayList__ArrayList)i1;
  i3 = (OOC_INT32)value;
  i4 = ADT_Dictionary__DictionaryDesc_HasKey((ADT_Dictionary__Dictionary)i2, (Object__Object)i3);
  i4 = !i4;
  if (!i4) goto l4;
  i4 = *(OOC_INT32*)((_check_pointer(i0, 5943))+20);
  i4 = (OOC_INT32)Object_Boxed__IntToString(i4);
  ADT_Dictionary__DictionaryDesc_Set((ADT_Dictionary__Dictionary)i2, (Object__Object)i3, (Object__Object)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)_c18),(void*)i4)));
  i4 = *(OOC_INT32*)((_check_pointer(i0, 5973))+20);
  *(OOC_INT32*)((_check_pointer(i0, 5973))+20) = (i4+1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6002)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i1, (Object__Object)i3);
l4:
  i0 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i2, (Object__Object)i3);
  return (Object__String)i0;
  ;
}

static Object__String OOC_X86_Write__ToHex(OOC_INT32 n, OOC_INT32 digits) {
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
  *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i3, 16, OOC_UINT32, 6417))) = (55+i4);
  goto l7;
l6:
  *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i3, 16, OOC_UINT32, 6367))) = (48+i4);
l7:
  i3 = i3+1;
  i4 = i3<i0;
  if (i4) goto l3_loop;
l12:
  i0 = (OOC_INT32)Object__NewLatin1Region((void*)(OOC_INT32)str, 16, 0, i0);
  return (Object__String)i0;
  ;
}

void OOC_X86_Write__WriterDesc_Constants(OOC_X86_Write__Writer w) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11,i12,i13,i14,i15,i16,i17,i18,i19,i20,i21;
  register OOC_REAL64 d0;
  OOC_INT32 s;
  OOC_INT32 i;
  Object__Object value;
  Object__String label;
  struct {
    OOC_INT32 x;
    OOC_INT32 y;
  } lr;
  OOC_X86_SSA__Block guard;
  OOC_X86_SSA__Opnd opnd;
  Object__Object x;
  auto void OOC_X86_Write__WriterDesc_Constants_AddInt(OOC_X86_SSA__Opnd opnd);
    
    void OOC_X86_Write__WriterDesc_Constants_AddInt(OOC_X86_SSA__Opnd opnd) {
      register OOC_INT32 i0,i1,i2;
      Object__Object value;

      i0 = (OOC_INT32)opnd;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6816));
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6820))+4);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6826))+28);
      i0 = _check_pointer(i0, 6837);
      i1 = OOC_ARRAY_LENGTH(i0, 0);
      i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 6837))*4);
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6843)))), &_td_OOC_X86_SSA__ConstDesc, 6843)), 6849));
      value = (Object__Object)i0;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6873)))), &_td_Object_Boxed__StringDesc);
      if (i1) goto l3;
      i1 = (OOC_INT32)w;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6965))+4);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6965))+4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 6967)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i1, (Object__Object)i0);
      goto l4;
l3:
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6922));
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6922));
      i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6928)))), Object__StringDesc_CharAt)),Object__StringDesc_CharAt)((Object__String)i0, 0);
      i1 = (OOC_INT32)w;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6900))+4);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6900))+4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 6902)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i1, i0, 0);
l4:
      return;
      ;
    }


  i0 = (OOC_INT32)_c19;
  i1 = (OOC_INT32)_c20;
  i2 = (OOC_INT32)_c21;
  i3 = (OOC_INT32)_c22;
  i4 = (OOC_INT32)_c23;
  i5 = (OOC_INT32)_c24;
  i6 = (OOC_INT32)_c25;
  i7 = (OOC_INT32)_c26;
  i8 = (OOC_INT32)_c27;
  i9 = (OOC_INT32)_c28;
  i10 = (OOC_INT32)_c29;
  i11 = (OOC_INT32)_c30;
  i12 = (OOC_INT32)_c31;
  i13 = (OOC_INT32)&lr+4;
  s = 0;
  i14=0;
l1_loop:
  i15 = (OOC_INT32)w;
  i14 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i15, 7082))+100)+(_check_index(i14, 19, OOC_UINT32, 7095))*4);
  i14 = *(OOC_INT32*)((_check_pointer(i14, 7098))+4);
  i = 0;
  i15 = 0<i14;
  if (!i15) goto l48;
  i15=0;
l4_loop:
  i16 = (OOC_INT32)w;
  i17 = s;
  i18 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i16, 7127))+100)+(_check_index(i17, 19, OOC_UINT32, 7140))*4);
  i18 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i18, 7143));
  i18 = _check_pointer(i18, 7149);
  i19 = OOC_ARRAY_LENGTH(i18, 0);
  i15 = (OOC_INT32)*(OOC_INT32*)(i18+(_check_index(i15, i19, OOC_UINT32, 7149))*4);
  value = (Object__Object)i15;
  i18 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i15, 7173)))), &_td_OOC_X86_SSA__MergeInstrDesc));
  if (!i18) goto l43;
  i18 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i16, 7378))+24)+(_check_index(i17, 19, OOC_UINT32, 7388))*4);
  i18 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i18, (Object__Object)i15);
  label = (Object__String)i18;
  i19 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i16, 7415))+4);
  i20 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i16, 7415))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i19, 7417)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i20, (Object__Object)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)i0,(void*)i18)),(void*)i1)));
  i18 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i15, 7465)))), &_td_Object__StringDesc);
  if (i18) goto l41;
  i18 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i15, 7642)))), &_td_Object_Boxed__LongRealDesc);
  if (i18) goto l35;
  i16 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i15, 8132)))), &_td_OOC_X86_SSA__BranchInstrDesc);
  if (i16) goto l13;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i15, 8125)))), 8125);
  goto l43;
l13:
  i15 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i15, 8227))+56);
  i15 = _check_pointer(i15, 8233);
  i16 = OOC_ARRAY_LENGTH(i15, 0);
  i16 = i15+i16*4;
  i17 = i16!=i15;
  if (!i17) goto l43;
l16_loop:
  i17 = (OOC_INT32)*(OOC_INT32*)i15;
  guard = (OOC_X86_SSA__Block)i17;
  i18 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i17, 8265));
  opnd = (OOC_X86_SSA__Opnd)i18;
  i19 = i18==0;
  if (i19) goto l27;
  i17 = i18!=0;
  if (!i17) goto l28;
  i17=i18;
l21_loop:
  i18 = (OOC_INT32)w;
  i19 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i18, 8799))+4);
  i18 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i18, 8799))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i19, 8801)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i18, (Object__Object)i9);
  OOC_X86_Write__WriterDesc_Constants_AddInt((OOC_X86_SSA__Opnd)i17);
  i17 = (OOC_INT32)opnd;
  i17 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i17, 8893))+4);
  opnd = (OOC_X86_SSA__Opnd)i17;
  i18 = (OOC_INT32)w;
  i19 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i18, 8923))+4);
  i18 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i18, 8923))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i19, 8925)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i18, (Object__Object)i10);
  OOC_X86_Write__WriterDesc_Constants_AddInt((OOC_X86_SSA__Opnd)i17);
  i17 = (OOC_INT32)opnd;
  i17 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i17, 9017))+4);
  opnd = (OOC_X86_SSA__Opnd)i17;
  i18 = (OOC_INT32)w;
  i19 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i18, 9113))+24)+(_check_index(17, 19, OOC_UINT8, 9123))*4);
  i20 = (OOC_INT32)guard;
  i19 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i19, (Object__Object)i20);
  i20 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i18, 9047))+4);
  i18 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i18, 9047))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i20, 9049)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i18, (Object__Object)((OOC_INT32)Object__Concat2((void*)i11,(void*)i19)));
  i18 = i17!=0;
  if (i18) goto l21_loop;
  goto l28;
l27:
  i18 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(6);
  i18 = (OOC_INT32)OOC_SymbolTable_Predef__GetMin((OOC_SymbolTable__Type)i18);
  x = (Object__Object)i18;
  i18 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i18, 8461)))), Object__ObjectDesc_ToString)),Object__ObjectDesc_ToString)((Object__Object)i18);
  i19 = (OOC_INT32)w;
  i20 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i19, 8430))+4);
  i21 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i19, 8430))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i20, 8432)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i21, (Object__Object)((OOC_INT32)Object__Concat2((void*)i6,(void*)i18)));
  i18 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(6);
  i18 = (OOC_INT32)OOC_SymbolTable_Predef__GetMax((OOC_SymbolTable__Type)i18);
  x = (Object__Object)i18;
  i18 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i18, 8591)))), Object__ObjectDesc_ToString)),Object__ObjectDesc_ToString)((Object__Object)i18);
  i20 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i19, 8560))+4);
  i21 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i19, 8560))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i20, 8562)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i21, (Object__Object)((OOC_INT32)Object__Concat2((void*)i7,(void*)i18)));
  i18 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i19, 8686))+24)+(_check_index(17, 19, OOC_UINT8, 8696))*4);
  i17 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i18, (Object__Object)i17);
  i18 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i19, 8622))+4);
  i19 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i19, 8622))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i18, 8624)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i19, (Object__Object)((OOC_INT32)Object__Concat2((void*)i8,(void*)i17)));
l28:
  i15 = i15+4;
  i17 = i16!=i15;
  if (i17) goto l16_loop;
  goto l43;
l35:
  i17 = i17==8;
  if (i17) goto l38;
  _move_block((_check_pointer(i15, 7889)),(OOC_INT32)&lr,8);
  i15 = *(OOC_INT32*)(OOC_INT32)&lr;
  i15 = (OOC_INT32)OOC_X86_Write__ToHex(i15, 8);
  i16 = (OOC_INT32)w;
  i17 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i16, 7972))+4);
  i18 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i16, 7972))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i17, 7974)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i18, (Object__Object)((OOC_INT32)Object__Concat2((void*)i4,(void*)i15)));
  i15 = *(OOC_INT32*)i13;
  i15 = (OOC_INT32)OOC_X86_Write__ToHex(i15, 8);
  i17 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i16, 8036))+4);
  i16 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i16, 8036))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i17, 8038)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i16, (Object__Object)((OOC_INT32)Object__Concat2((void*)i5,(void*)i15)));
  goto l43;
l38:
  d0 = *(OOC_REAL64*)(_check_pointer(i15, 7815));
  i15 = (OOC_INT32)OOC_X86_Write__ToHex((_type_cast(OOC_INT32, OOC_REAL32, ((OOC_REAL32)d0))), 8);
  i17 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i16, 7715))+4);
  i16 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i16, 7715))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i17, 7717)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i16, (Object__Object)((OOC_INT32)Object__Concat2((void*)i3,(void*)i15)));
  goto l43;
l41:
  _assert((i17==13), 127, 7489);
  i17 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i16, 7533))+4);
  i16 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i16, 7533))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i17, 7535)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i16, (Object__Object)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)i2,(void*)i15)),(void*)i12)));
l43:
  i15 = i;
  i15 = i15+1;
  i = i15;
  i16 = i15<i14;
  if (i16) goto l4_loop;
l48:
  i14 = s;
  i14 = i14+1;
  s = i14;
  i15 = i14<=18;
  if (i15) goto l1_loop;
l52:
  return;
  ;
}

void OOC_X86_Write__WriterDesc_EndFile(OOC_X86_Write__Writer w) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  Object__String name0;
  Object__String name;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 9389));
  i1 = (OOC_INT32)OOC_C_Naming__NameOfModuleInit((OOC_SymbolTable__Module)i1, 1u);
  name0 = (Object__String)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 9442));
  i2 = (OOC_INT32)OOC_C_Naming__NameOfModuleInit((OOC_SymbolTable__Module)i2, 0u);
  name = (Object__String)i2;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9464))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9464))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 9466)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i4, (Object__Object)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)_c32),(void*)i1)));
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9506))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9506))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 9508)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i4, (Object__Object)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)_c33),(void*)i1)),(void*)((OOC_INT32)_c34))));
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9563))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9563))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 9565)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i4, (Object__Object)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)_c35),(void*)i1)),(void*)((OOC_INT32)_c36))));
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9598))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9598))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 9600)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i4, (Object__Object)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)_c37),(void*)i2)));
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9639))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9639))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 9641)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i3, (Object__Object)((OOC_INT32)_c38));
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9673))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9673))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 9675)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i3, (Object__Object)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)_c39),(void*)i1)),(void*)((OOC_INT32)_c40))),(void*)i1)));
  OOC_X86_Write__WriterDesc_RuntimeData((OOC_X86_Write__Writer)i0);
  OOC_X86_Write__WriterDesc_ModuleVariables((OOC_X86_Write__Writer)i0);
  OOC_X86_Write__WriterDesc_Constants((OOC_X86_Write__Writer)i0);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9800))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9800))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9802)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "\012", 2);
  return;
  ;
}

OOC_X86_Write__Block OOC_X86_Write__WriterDesc_WriteBlock(OOC_X86_Write__Writer w, OOC_X86_SSA__Block b, Object__String label) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11,i12,i13,i14,i15;
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
  OOC_CHAR8 omitStackArg;
  OOC_INT32 i;
  OOC_X86_SSA__Block path;
  OOC_X86_Write__Block dummy;
  OOC_X86_SSA__MergeInstr merge;
  auto void OOC_X86_Write__WriterDesc_WriteBlock_OpcTT(const OOC_CHAR8 opc[], OOC_LEN opc_0d, OOC_INT8 type1, OOC_INT8 type2);
  auto void OOC_X86_Write__WriterDesc_WriteBlock_Opc0(const OOC_CHAR8 opc[], OOC_LEN opc_0d);
  auto void OOC_X86_Write__WriterDesc_WriteBlock_Opc(const OOC_CHAR8 opc[], OOC_LEN opc_0d);
  auto void OOC_X86_Write__WriterDesc_WriteBlock_ShiftOpcode(OOC_INT8 opcode);
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
  auto void OOC_X86_Write__WriterDesc_WriteBlock_MovMemRegNoX(OOC_X86_SSA__Opnd fromMemReg, OOC_INT8 fromType, OOC_CHAR8 valueOpnd, OOC_X86_SSA__Result toReg);
  auto void OOC_X86_Write__WriterDesc_WriteBlock_Bounce(OOC_X86_SSA__Result from, OOC_X86_SSA__Result to);
    
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
            goto l14;
          case 1:
          case 5:
            return 98u;
            goto l14;
          case 2:
          case 6:
            return 119u;
            goto l14;
          case 3:
          case 7:
          case 9:
            return 108u;
            goto l14;
          case 4:
          case 8:
            return 113u;
            goto l14;
          case 10:
            return 115u;
            goto l14;
          case 11:
            i0 = *(OOC_UINT8*)((OOC_INT32)opc+(_check_index(0, opc_0d, OOC_UINT8, 11102)));
            i0 = i0==102u;
            if (i0) goto l11;
            return 100u;
            goto l14;
l11:
            return 108u;
            goto l14;
          default:
            _failed_case(i0, 10728);
            goto l14;
          }
l14:
          _failed_function(10682); return 0;
          ;
        }


      i0 = (OOC_INT32)sb;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11343)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1)),ADT_StringBuffer__StringBufferDesc_AppendLatin1)((ADT_StringBuffer__StringBuffer)i0, "\012\011", 3);
      i0 = (OOC_INT32)sb;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11373)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1)),ADT_StringBuffer__StringBufferDesc_AppendLatin1)((ADT_StringBuffer__StringBuffer)i0, (void*)(OOC_INT32)opc, opc_0d);
      i0 = type1;
      i0 = OOC_X86_Write__WriterDesc_WriteBlock_OpcTT_Type(i0);
      *(OOC_UINT8*)((OOC_INT32)suffix+(_check_index(0, 3, OOC_UINT8, 11405))) = i0;
      i0 = type2;
      i0 = OOC_X86_Write__WriterDesc_WriteBlock_OpcTT_Type(i0);
      *(OOC_UINT8*)((OOC_INT32)suffix+(_check_index(1, 3, OOC_UINT8, 11437))) = i0;
      *(OOC_UINT8*)((OOC_INT32)suffix+(_check_index(2, 3, OOC_UINT8, 11469))) = 0u;
      i0 = (OOC_INT32)sb;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11488)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1)),ADT_StringBuffer__StringBufferDesc_AppendLatin1)((ADT_StringBuffer__StringBuffer)i0, (void*)(OOC_INT32)suffix, 3);
      i0 = (OOC_INT32)sb;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11519)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1)),ADT_StringBuffer__StringBufferDesc_AppendLatin1)((ADT_StringBuffer__StringBuffer)i0, " ", 2);
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

    
    void OOC_X86_Write__WriterDesc_WriteBlock_ShiftOpcode(OOC_INT8 opcode) {
      register OOC_INT32 i0;

      i0 = opcode;
      switch (i0) {
      case 6:
        OOC_X86_Write__WriterDesc_WriteBlock_Opc("sar", 4);
        goto l9;
      case 7:
        OOC_X86_Write__WriterDesc_WriteBlock_Opc("sal", 4);
        goto l9;
      case 8:
        OOC_X86_Write__WriterDesc_WriteBlock_Opc("shr", 4);
        goto l9;
      case 9:
        OOC_X86_Write__WriterDesc_WriteBlock_Opc("shl", 4);
        goto l9;
      case 11:
        OOC_X86_Write__WriterDesc_WriteBlock_Opc("rol", 4);
        goto l9;
      case 10:
        OOC_X86_Write__WriterDesc_WriteBlock_Opc("ror", 4);
        goto l9;
      default:
        _failed_case(i0, 11956);
        goto l9;
      }
l9:
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
          goto l48;
        case 4:
          _copy_8((const void*)"%cl",(void*)(OOC_INT32)str,8);
          goto l48;
        case 5:
          _copy_8((const void*)"%dl",(void*)(OOC_INT32)str,8);
          goto l48;
        case 6:
          _copy_8((const void*)"%bl",(void*)(OOC_INT32)str,8);
          goto l48;
        default:
          _failed_case(i0, 12393);
          goto l48;
        }
        /* goto: unreachable */
      case 2:
      case 6:
        i0 = reg;
        switch (i0) {
        case 0:
          _copy_8((const void*)"%sp",(void*)(OOC_INT32)str,8);
          goto l48;
        case 1:
          _copy_8((const void*)"%bp",(void*)(OOC_INT32)str,8);
          goto l48;
        case 3:
          _copy_8((const void*)"%ax",(void*)(OOC_INT32)str,8);
          goto l48;
        case 4:
          _copy_8((const void*)"%cx",(void*)(OOC_INT32)str,8);
          goto l48;
        case 5:
          _copy_8((const void*)"%dx",(void*)(OOC_INT32)str,8);
          goto l48;
        case 6:
          _copy_8((const void*)"%bx",(void*)(OOC_INT32)str,8);
          goto l48;
        case 7:
          _copy_8((const void*)"%si",(void*)(OOC_INT32)str,8);
          goto l48;
        case 8:
          _copy_8((const void*)"%di",(void*)(OOC_INT32)str,8);
          goto l48;
        default:
          _failed_case(i0, 12698);
          goto l48;
        }
        /* goto: unreachable */
      case 3:
      case 7:
      case 9:
        i0 = reg;
        switch (i0) {
        case 0:
          _copy_8((const void*)"%esp",(void*)(OOC_INT32)str,8);
          goto l48;
        case 1:
          _copy_8((const void*)"%ebp",(void*)(OOC_INT32)str,8);
          goto l48;
        case 3:
          _copy_8((const void*)"%eax",(void*)(OOC_INT32)str,8);
          goto l48;
        case 4:
          _copy_8((const void*)"%ecx",(void*)(OOC_INT32)str,8);
          goto l48;
        case 5:
          _copy_8((const void*)"%edx",(void*)(OOC_INT32)str,8);
          goto l48;
        case 6:
          _copy_8((const void*)"%ebx",(void*)(OOC_INT32)str,8);
          goto l48;
        case 7:
          _copy_8((const void*)"%esi",(void*)(OOC_INT32)str,8);
          goto l48;
        case 8:
          _copy_8((const void*)"%edi",(void*)(OOC_INT32)str,8);
          goto l48;
        default:
          _failed_case(i0, 13022);
          goto l48;
        }
        /* goto: unreachable */
      case 10:
      case 11:
        i0 = reg;
        switch (i0) {
        case 9:
          _copy_8((const void*)"%st",(void*)(OOC_INT32)str,8);
          goto l48;
        case 10:
          _copy_8((const void*)"%xmm0",(void*)(OOC_INT32)str,8);
          goto l48;
        case 11:
          _copy_8((const void*)"%xmm1",(void*)(OOC_INT32)str,8);
          goto l48;
        case 12:
          _copy_8((const void*)"%xmm2",(void*)(OOC_INT32)str,8);
          goto l48;
        case 13:
          _copy_8((const void*)"%xmm3",(void*)(OOC_INT32)str,8);
          goto l48;
        case 14:
          _copy_8((const void*)"%xmm4",(void*)(OOC_INT32)str,8);
          goto l48;
        case 15:
          _copy_8((const void*)"%xmm5",(void*)(OOC_INT32)str,8);
          goto l48;
        case 16:
          _copy_8((const void*)"%xmm6",(void*)(OOC_INT32)str,8);
          goto l48;
        case 17:
          _copy_8((const void*)"%xmm7",(void*)(OOC_INT32)str,8);
          goto l48;
        default:
          _failed_case(i0, 13337);
          goto l48;
        }
        /* goto: unreachable */
      default:
        _failed_case(i0, 12269);
        goto l48;
      }
l48:
      i0 = (OOC_INT32)sb;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13676)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1)),ADT_StringBuffer__StringBufferDesc_AppendLatin1)((ADT_StringBuffer__StringBuffer)i0, (void*)(OOC_INT32)str, 8);
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
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14030)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1)),ADT_StringBuffer__StringBufferDesc_AppendLatin1)((ADT_StringBuffer__StringBuffer)i0, ", ", 3);
      return;
      ;
    }

    
    void OOC_X86_Write__WriterDesc_WriteBlock_Literal(OOC_X86_SSA__Instr instr) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
      OOC_INT32 i;
      OOC_X86_SSA__Selector s;
      Object__Object value;
      OOC_INT16 predefId;

      i0 = (OOC_INT32)instr;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14250))+28);
      i = 0;
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 14261)), 0);
      i2 = 0<i1;
      if (!i2) goto l71;
      i2 = (OOC_INT32)_c41;
      i3 = (OOC_INT32)_c42;
      i4=0;
l3_loop:
      i5 = i4!=0;
      if (!i5) goto l6;
      i5 = (OOC_INT32)sb;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 14305)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)),ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)((ADT_StringBuffer__StringBuffer)i5, 43u);
l6:
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14369))+28);
      i5 = _check_pointer(i5, 14380);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 14380))*4);
      s = (OOC_X86_SSA__Selector)i5;
      i6 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 14399)))), &_td_OOC_X86_SSA__ConstDesc);
      if (i6) goto l33;
      i6 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 15552)))), &_td_OOC_X86_SSA__VarDesc);
      if (i6) goto l27;
      i6 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 15755)))), &_td_OOC_X86_SSA__ProcDesc);
      if (i6) goto l25;
      i6 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 15833)))), &_td_OOC_X86_SSA__ProcNameDesc);
      if (i6) goto l23;
      i6 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 15889)))), &_td_OOC_X86_SSA__TypeDescrDesc);
      if (i6) goto l21;
      i6 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 15984)))), &_td_OOC_X86_SSA__ModuleDescrDesc);
      if (i6) goto l19;
      _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 15981)))), 15981);
      goto l66;
l19:
      i5 = (OOC_INT32)sb;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 16015)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i5, (Object__Object)i3);
      goto l66;
l21:
      i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 15955));
      i6 = (OOC_INT32)qtdData;
      i5 = (OOC_INT32)OOC_C_Naming__NameOfTypeDescriptor((OOC_SymbolTable__Type)i5, (OOC_C_Naming__QualTypeData)i6);
      i6 = (OOC_INT32)sb;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 15918)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i6, (Object__Object)i5);
      goto l66;
l23:
      i6 = (OOC_INT32)sb;
      i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 15870));
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 15861)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i6, (Object__Object)i5);
      goto l66;
l25:
      i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 15813));
      i5 = (OOC_INT32)OOC_C_Naming__NameOfDeclaration((OOC_SymbolTable__Declaration)i5);
      i6 = (OOC_INT32)sb;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 15779)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i6, (Object__Object)i5);
      goto l66;
l27:
      i6 = OOC_X86_SSA__VarDesc_IsGlobalVar((OOC_X86_SSA__Var)i5);
      if (i6) goto l30;
      i6 = (OOC_INT32)w;
      i7 = *(OOC_INT32*)((_check_pointer(i5, 15721))+4);
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 15695))+176);
      i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 15713));
      i5 = OOC_X86_SSA__FunctionBlockDesc_Offset((OOC_X86_SSA__FunctionBlock)i6, (OOC_SymbolTable__VarDecl)i5, i7);
      i6 = (OOC_INT32)sb;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 15683)))), ADT_StringBuffer__StringBufferDesc_AppendInt)),ADT_StringBuffer__StringBufferDesc_AppendInt)((ADT_StringBuffer__StringBuffer)i6, i5);
      goto l66;
l30:
      i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 15645));
      i5 = (OOC_INT32)OOC_C_Naming__NameOfDeclaration((OOC_SymbolTable__Declaration)i5);
      i6 = (OOC_INT32)sb;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 15611)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i6, (Object__Object)i5);
      goto l66;
l33:
      i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 14432));
      value = (Object__Object)i6;
      i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14463))+4);
      i7 = *(OOC_INT8*)((_check_pointer(i7, 14474))+12);
      type = i7;
      i8 = i6!=0;
      if (i8) goto l36;
      i8=0u;
      goto l38;
l36:
      i8 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 14517)))), &_td_OOC_X86_SSA__BranchInstrDesc);
      
l38:
      if (i8) goto l64;
      i8 = *(OOC_INT16*)((_check_pointer(i5, 14611))+4);
      i8 = i8>=0;
      if (i8) goto l62;
      i8 = i6==0;
      if (i8) goto l60;
      i8 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 14829)))), &_td_Object_Boxed__StringDesc);
      if (i8) goto l58;
      i8 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 14922)))), &_td_Object_Boxed__SetDesc);
      if (i8) goto l56;
      i8 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 15003)))), &_td_Object_Boxed__LongRealDesc);
      if (i8) goto l50;
      i6 = (OOC_INT32)sb;
      i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 15500));
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 15491)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i6, (Object__Object)i5);
      goto l66;
l50:
      switch (i7) {
      case 10:
        predefId = 8;
        goto l54;
      case 11:
        predefId = 9;
        goto l54;
      default:
        _failed_case(i7, 15037);
        goto l54;
      }
l54:
      i5 = predefId;
      i7 = (OOC_INT32)w;
      i5 = (OOC_INT32)OOC_X86_Write__WriterDesc_ConstSymbol((OOC_X86_Write__Writer)i7, (Object__Object)i6, i5);
      i6 = (OOC_INT32)sb;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 15276)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i6, (Object__Object)i5);
      goto l66;
l56:
      i5 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 14969)))), Object_Boxed__SetDesc_ToLongInt)),Object_Boxed__SetDesc_ToLongInt)((Object_Boxed__Set)i6);
      i6 = (OOC_INT32)sb;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 14953)))), ADT_StringBuffer__StringBufferDesc_AppendInt)),ADT_StringBuffer__StringBufferDesc_AppendInt)((ADT_StringBuffer__StringBuffer)i6, i5);
      goto l66;
l58:
      i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i6, 14883));
      i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i6, 14883));
      i5 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 14889)))), Object__StringDesc_CharAt)),Object__StringDesc_CharAt)((Object__String)i6, 0);
      i6 = (OOC_INT32)sb;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 14863)))), ADT_StringBuffer__StringBufferDesc_AppendInt)),ADT_StringBuffer__StringBufferDesc_AppendInt)((ADT_StringBuffer__StringBuffer)i6, i5);
      goto l66;
l60:
      i5 = (OOC_INT32)sb;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 14778)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i5, (Object__Object)i2);
      goto l66;
l62:
      i5 = *(OOC_INT16*)((_check_pointer(i5, 14720))+4);
      i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i6, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 14704)))), &_td_Object_Boxed__StringDesc, 14704)), 14711));
      i7 = (OOC_INT32)w;
      i5 = (OOC_INT32)OOC_X86_Write__WriterDesc_ConstSymbol((OOC_X86_Write__Writer)i7, (Object__Object)i6, i5);
      i6 = (OOC_INT32)sb;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 14670)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i6, (Object__Object)i5);
      goto l66;
l64:
      i5 = *(OOC_INT16*)((_check_pointer(i5, 14584))+4);
      i7 = (OOC_INT32)w;
      i5 = (OOC_INT32)OOC_X86_Write__WriterDesc_ConstSymbol((OOC_X86_Write__Writer)i7, (Object__Object)i6, i5);
      i6 = (OOC_INT32)sb;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 14554)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i6, (Object__Object)i5);
l66:
      i4 = i4+1;
      i = i4;
      i5 = i4<i1;
      if (i5) goto l3_loop;
l71:
      return;
      ;
    }

    
    void OOC_X86_Write__WriterDesc_WriteBlock_Result(OOC_X86_SSA__Result res) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)res;
      i1 = *(OOC_INT8*)((_check_pointer(i0, 16135))+14);
      switch (i1) {
      case 0:
        i0 = *(OOC_INT8*)((_check_pointer(i0, 16182))+13);
        OOC_X86_Write__WriterDesc_WriteBlock_Reg(i0);
        goto l4;
      default:
        _failed_case(i1, 16127);
        goto l4;
      }
l4:
      return;
      ;
    }

    
    void OOC_X86_Write__WriterDesc_WriteBlock_OpndMem(OOC_X86_SSA__Opnd opnd) {
      register OOC_INT32 i0;

      i0 = (OOC_INT32)sb;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16275)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)),ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)((ADT_StringBuffer__StringBuffer)i0, 40u);
      i0 = (OOC_INT32)opnd;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 16316));
      i0 = *(OOC_INT8*)((_check_pointer(i0, 16320))+13);
      OOC_X86_Write__WriterDesc_WriteBlock_RegAdr(i0);
      i0 = (OOC_INT32)sb;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16340)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)),ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)((ADT_StringBuffer__StringBuffer)i0, 41u);
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
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16532))+4);
          i1 = *(OOC_INT8*)((_check_pointer(i1, 16538))+20);
          i1 = i1==0;
          if (i1) goto l7;
          i1 = (OOC_INT32)arg1;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 16717))+4);
          i2 = *(OOC_INT8*)((_check_pointer(i2, 16723))+20);
          i2 = i2==0;
          if (i2) goto l5;
          i2 = (OOC_INT32)sb;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 16803)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)),ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)((ADT_StringBuffer__StringBuffer)i2, 40u);
          i1 = *(OOC_INT8*)((_check_pointer(i1, 16848))+13);
          OOC_X86_Write__WriterDesc_WriteBlock_RegAdr(i1);
          i1 = (OOC_INT32)sb;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16872)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)),ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)((ADT_StringBuffer__StringBuffer)i1, 44u);
          i0 = *(OOC_INT8*)((_check_pointer(i0, 16917))+13);
          OOC_X86_Write__WriterDesc_WriteBlock_RegAdr(i0);
          i0 = (OOC_INT32)sb;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16941)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)),ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)((ADT_StringBuffer__StringBuffer)i0, 41u);
          goto l8;
l5:
          OOC_X86_Write__WriterDesc_WriteBlock_Opnd_Offset((OOC_X86_SSA__Result)i0, (OOC_X86_SSA__Result)i1);
          goto l8;
l7:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16584))+4);
          OOC_X86_Write__WriterDesc_WriteBlock_Literal((OOC_X86_SSA__Instr)i0);
          i0 = (OOC_INT32)sb;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16605)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)),ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)((ADT_StringBuffer__StringBuffer)i0, 40u);
          i0 = (OOC_INT32)arg1;
          i0 = *(OOC_INT8*)((_check_pointer(i0, 16650))+13);
          OOC_X86_Write__WriterDesc_WriteBlock_RegAdr(i0);
          i0 = (OOC_INT32)sb;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16674)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)),ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)((ADT_StringBuffer__StringBuffer)i0, 41u);
l8:
          return;
          ;
        }


      i0 = (OOC_INT32)opnd;
      i1 = *(OOC_UINT8*)((_check_pointer(i0, 17024))+16);
      if (i1) goto l3;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 17852));
      OOC_X86_Write__WriterDesc_WriteBlock_Result((OOC_X86_SSA__Result)i0);
      goto l22;
l3:
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 17065));
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17069))+4);
      argInstr1 = (OOC_X86_SSA__Instr)i0;
      i1 = *(OOC_INT8*)((_check_pointer(i0, 17099))+20);
      switch (i1) {
      case 0:
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17153))+4);
        i1 = *(OOC_INT8*)((_check_pointer(i1, 17164))+12);
        switch (i1) {
        case 10:
        case 11:
          goto l9;
        default:
          i1 = (OOC_INT32)sb;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17269)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)),ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)((ADT_StringBuffer__StringBuffer)i1, 36u);
          goto l9;
        }
l9:
        OOC_X86_Write__WriterDesc_WriteBlock_Literal((OOC_X86_SSA__Instr)i0);
        goto l22;
      case 1:
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 17476));
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 17485))+4);
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 17435));
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 17444));
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 17494));
        OOC_X86_Write__WriterDesc_WriteBlock_Opnd_Offset((OOC_X86_SSA__Result)i0, (OOC_X86_SSA__Result)i1);
        goto l22;
      case 34:
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 17550));
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 17559));
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 17563))+4);
        argInstr2 = (OOC_X86_SSA__Instr)i1;
        i2 = *(OOC_INT8*)((_check_pointer(i1, 17594))+20);
        i2 = i2==0;
        if (i2) goto l18;
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 17675));
        i1 = *(OOC_UINT8*)((_check_pointer(i1, 17684))+16);
        if (i1) goto l16;
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 17782));
        OOC_X86_Write__WriterDesc_WriteBlock_OpndMem((OOC_X86_SSA__Opnd)i0);
        goto l22;
l16:
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 17726));
        OOC_X86_Write__WriterDesc_WriteBlock_Opnd((OOC_X86_SSA__Opnd)i0);
        goto l22;
l18:
        OOC_X86_Write__WriterDesc_WriteBlock_Literal((OOC_X86_SSA__Instr)i1);
        goto l22;
      default:
        _failed_case(i1, 17085);
        goto l22;
      }
l22:
      return;
      ;
    }

    
    void OOC_X86_Write__WriterDesc_WriteBlock_DirectOpnd(OOC_X86_SSA__Opnd opnd) {
      register OOC_INT32 i0,i1,i2;
      OOC_X86_SSA__Instr argInstr;

      i0 = (OOC_INT32)opnd;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 17988));
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 17992))+4);
      argInstr = (OOC_X86_SSA__Instr)i1;
      i2 = *(OOC_INT8*)((_check_pointer(i1, 18018))+20);
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
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18206))+8);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 18212))+4);
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 18241));
      i0 = OOC_X86_SSA__ResultDesc_SameLocation((OOC_X86_SSA__Result)i1, (OOC_X86_SSA__Result)i0);
      _assert(i0, 127, 18195);
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
      i1 = OOC_X86_SSA__BlockDesc_Count((OOC_X86_SSA__Block)i1, 50);
      i1 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_Write__18418.baseTypes[0], i1);
      io = (void*)i1;
      i = 0;
      i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_GateOperands((OOC_X86_SSA__Instr)i0);
      i2 = (OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG(i0)), OOC_X86_SSA__IterJumpGateOperandsDesc_Next);
      i3 = OOC_TBCALL(i2,OOC_X86_SSA__IterJumpGateOperandsDesc_Next)((OOC_X86_SSA__IterJumpGateOperands)i0, (void*)(OOC_INT32)&opnd);
      if (i3) goto l3;
      i0=0;
      goto l13;
l3:
      i3=0;
l4_loop:
      i4 = (OOC_INT32)opnd;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 18641))+8);
      i4 = OOC_X86_SSA__InstrDesc_IsLive((OOC_X86_SSA__Instr)i4);
      if (!i4) goto l8;
      i4 = _check_pointer(i1, 18674);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i6 = (OOC_INT32)opnd;
      *(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 18674))*8) = i6;
      i4 = _check_pointer(i1, 18702);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 18717))+8);
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 18723))+4);
      *(OOC_INT32*)((i4+(_check_index(i3, i5, OOC_UINT32, 18702))*8)+4) = i6;
      i3 = i3+1;
      i = i3;
      
l8:
      i4 = OOC_TBCALL(i2,OOC_X86_SSA__IterJumpGateOperandsDesc_Next)((OOC_X86_SSA__IterJumpGateOperands)i0, (void*)(OOC_INT32)&opnd);
      if (i4) goto l4_loop;
l12:
      i0=i3;
l13:
      len = i0;
      i = 0;
      i2 = 0!=i0;
      if (!i2) goto l26;
      i2=i0;i0=0;
l17_loop:
      i3 = _check_pointer(i1, 18937);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i5 = _check_pointer(i1, 18911);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i0, i6, OOC_UINT32, 18911))*8);
      i3 = (OOC_INT32)*(OOC_INT32*)((i3+(_check_index(i0, i4, OOC_UINT32, 18937))*8)+4);
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 18917));
      i3 = OOC_X86_SSA__ResultDesc_SameLocation((OOC_X86_SSA__Result)i4, (OOC_X86_SSA__Result)i3);
      if (i3) goto l20;
      i0 = i0+1;
      i = i0;
      
      goto l21;
l20:
      i3 = _check_pointer(i1, 18972);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i2 = i2-1;
      i5 = _check_pointer(i1, 18963);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      _copy_block((i3+(_check_index(i2, i4, OOC_UINT32, 18972))*8),(i5+(_check_index(i0, i6, OOC_UINT32, 18963))*8),8);
      len = i2;
      
l21:
      i3 = i0!=i2;
      if (i3) goto l17_loop;
l25:
      i0=i2;
l26:
      i = 0;
      i2 = 0!=i0;
      if (!i2) goto l60;
      i2=0;
l30_loop:
      j = 0;
      i3 = 0!=i0;
      if (i3) goto l33;
      i3=0u;
      goto l35;
l33:
      i3 = _check_pointer(i1, 19312);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(0, i4, OOC_UINT32, 19312))*8);
      i4 = _check_pointer(i1, 19289);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)((i4+(_check_index(i2, i5, OOC_UINT32, 19289))*8)+4);
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 19318));
      i3 = OOC_X86_SSA__ResultDesc_SameLocation((OOC_X86_SSA__Result)i4, (OOC_X86_SSA__Result)i3);
      i3 = !i3;
      
l35:
      if (i3) goto l37;
      i3=0;
      goto l47;
l37:
      i3=0;
l38_loop:
      i3 = i3+1;
      j = i3;
      i4 = i3!=i0;
      if (i4) goto l41;
      i4=0u;
      goto l43;
l41:
      i4 = _check_pointer(i1, 19312);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 19312))*8);
      i5 = _check_pointer(i1, 19289);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i5 = (OOC_INT32)*(OOC_INT32*)((i5+(_check_index(i2, i6, OOC_UINT32, 19289))*8)+4);
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 19318));
      i4 = OOC_X86_SSA__ResultDesc_SameLocation((OOC_X86_SSA__Result)i5, (OOC_X86_SSA__Result)i4);
      i4 = !i4;
      
l43:
      if (i4) goto l38_loop;
l47:
      i3 = i3==i0;
      if (i3) goto l50;
      i2 = i2+1;
      i = i2;
      
      goto l55;
l50:
      i3 = _check_pointer(i1, 19497);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)((i3+(_check_index(i2, i4, OOC_UINT32, 19497))*8)+4);
      i3 = *(OOC_INT8*)((_check_pointer(i3, 19504))+12);
      opndWidth = i3;
      i3 = OOC_X86_SSA__IsFloat(i3);
      if (i3) goto l53;
      OOC_X86_Write__WriterDesc_WriteBlock_Opc("mov", 4);
      goto l54;
l53:
      OOC_X86_Write__WriterDesc_WriteBlock_Opc("movs", 5);
l54:
      i3 = _check_pointer(i1, 19646);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 19646))*8);
      OOC_X86_Write__WriterDesc_WriteBlock_Opnd((OOC_X86_SSA__Opnd)i3);
      OOC_X86_Write__WriterDesc_WriteBlock_Comma();
      i3 = _check_pointer(i1, 19693);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)((i3+(_check_index(i2, i4, OOC_UINT32, 19693))*8)+4);
      OOC_X86_Write__WriterDesc_WriteBlock_Result((OOC_X86_SSA__Result)i3);
      i3 = _check_pointer(i1, 19724);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i0 = i0-1;
      i5 = _check_pointer(i1, 19715);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      _copy_block((i3+(_check_index(i0, i4, OOC_UINT32, 19724))*8),(i5+(_check_index(i2, i6, OOC_UINT32, 19715))*8),8);
      len = i0;
      
l55:
      i3 = i2!=i0;
      if (i3) goto l30_loop;
l60:
      i2 = i0!=0;
      if (!i2) goto l63;
      _assert((i0==2), 127, 19991);
      i0 = _check_pointer(i1, 20259);
      i2 = OOC_ARRAY_LENGTH(i0, 0);
      i0 = (OOC_INT32)*(OOC_INT32*)((i0+(_check_index(0, i2, OOC_UINT8, 20259))*8)+4);
      i0 = *(OOC_INT8*)((_check_pointer(i0, 20266))+12);
      opndWidth = i0;
      OOC_X86_Write__WriterDesc_WriteBlock_Opc("xchg", 5);
      i0 = _check_pointer(i1, 20309);
      i2 = OOC_ARRAY_LENGTH(i0, 0);
      i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i2, OOC_UINT8, 20309))*8);
      OOC_X86_Write__WriterDesc_WriteBlock_Opnd((OOC_X86_SSA__Opnd)i0);
      OOC_X86_Write__WriterDesc_WriteBlock_Comma();
      i0 = _check_pointer(i1, 20352);
      i1 = OOC_ARRAY_LENGTH(i0, 0);
      i0 = (OOC_INT32)*(OOC_INT32*)((i0+(_check_index(0, i1, OOC_UINT8, 20352))*8)+4);
      OOC_X86_Write__WriterDesc_WriteBlock_Result((OOC_X86_SSA__Result)i0);
l63:
      return;
      ;
    }

    
    void OOC_X86_Write__WriterDesc_WriteBlock_WriteBranch2(OOC_X86_SSA__Instr cmp, OOC_CHAR8 neg, OOC_X86_SSA__Block path1, OOC_X86_SSA__Block path2) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_INT8 opc;

      i0 = (OOC_INT32)cmp;
      i1 = *(OOC_INT8*)((_check_pointer(i0, 20550))+20);
      opc = i1;
      i2 = i1==0;
      if (i2) goto l7;
      i2 = neg;
      if (!i2) goto l6;
      i1 = OOC_X86_Write__NegateBranch(i1);
      opc = i1;
      
l6:
      i2 = (OOC_INT32)path2;
      i3 = (OOC_INT32)w;
      i2 = (OOC_INT32)OOC_X86_Write__WriterDesc_GetBlock((OOC_X86_Write__Writer)i3, (OOC_X86_SSA__Block)i2);
      i3 = (OOC_INT32)block;
      OOC_X86_Write__BlockDesc_SetArc((OOC_X86_Write__Block)i3, (void*)((_check_pointer(i3, 20918))+8), (OOC_X86_Write__Block)i2, i1);
      i1 = (OOC_INT32)block;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 20965))+8);
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 20984));
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 20993));
      i0 = *(OOC_INT8*)((_check_pointer(i0, 20997))+12);
      *(OOC_INT8*)((_check_pointer(i1, 20972))+8) = i0;
      i0 = (OOC_INT32)w;
      i1 = (OOC_INT32)path1;
      i0 = (OOC_INT32)OOC_X86_Write__WriterDesc_GetBlock((OOC_X86_Write__Writer)i0, (OOC_X86_SSA__Block)i1);
      i1 = (OOC_INT32)block;
      OOC_X86_Write__BlockDesc_SetArc((OOC_X86_Write__Block)i1, (void*)((_check_pointer(i1, 21030))+12), (OOC_X86_Write__Block)i0, 49);
      goto l12;
l7:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20651))+4);
      i0 = OOC_X86_SSA__ResultDesc_IsTrue((OOC_X86_SSA__Result)i0);
      i1 = neg;
      i0 = i1!=i0;
      if (i0) goto l10;
      i0 = (OOC_INT32)path1;
      i1 = (OOC_INT32)w;
      i0 = (OOC_INT32)OOC_X86_Write__WriterDesc_GetBlock((OOC_X86_Write__Writer)i1, (OOC_X86_SSA__Block)i0);
      i1 = (OOC_INT32)block;
      OOC_X86_Write__BlockDesc_SetArc((OOC_X86_Write__Block)i1, (void*)((_check_pointer(i1, 20782))+12), (OOC_X86_Write__Block)i0, 49);
      goto l12;
l10:
      i0 = (OOC_INT32)path2;
      i1 = (OOC_INT32)w;
      i0 = (OOC_INT32)OOC_X86_Write__WriterDesc_GetBlock((OOC_X86_Write__Writer)i1, (OOC_X86_SSA__Block)i0);
      i1 = (OOC_INT32)block;
      OOC_X86_Write__BlockDesc_SetArc((OOC_X86_Write__Block)i1, (void*)((_check_pointer(i1, 20706))+12), (OOC_X86_Write__Block)i0, 49);
l12:
      i0 = (OOC_INT32)path1;
      i1 = (OOC_INT32)w;
      i0 = (OOC_INT32)OOC_X86_Write__WriterDesc_WriteBlock((OOC_X86_Write__Writer)i1, (OOC_X86_SSA__Block)i0, (Object__String)0);
      i0 = (OOC_INT32)w;
      i1 = (OOC_INT32)path2;
      i0 = (OOC_INT32)OOC_X86_Write__WriterDesc_WriteBlock((OOC_X86_Write__Writer)i0, (OOC_X86_SSA__Block)i1, (Object__String)0);
      return;
      ;
    }

    
    void OOC_X86_Write__WriterDesc_WriteBlock_WriteMerge(OOC_X86_SSA__MergeInstr instr) {
      register OOC_INT32 i0,i1,i2;
      OOC_X86_Write__Block dummy;

      i0 = (OOC_INT32)instr;
      i1 = (OOC_INT32)w;
      i0 = (OOC_INT32)OOC_X86_Write__WriterDesc_WriteBlock((OOC_X86_Write__Writer)i1, (OOC_X86_SSA__Block)i0, (Object__String)(OOC_INT32)0);
      dummy = (OOC_X86_Write__Block)i0;
      i1 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_Write__Block.baseTypes[0]);
      OOC_X86_Write__BlockDesc_INIT((OOC_X86_Write__Block)i1, (OOC_X86_SSA__Block)(OOC_INT32)0);
      block = (OOC_X86_Write__Block)i1;
      OOC_X86_Write__BlockDesc_SetArc((OOC_X86_Write__Block)i0, (void*)((_check_pointer(i0, 21368))+12), (OOC_X86_Write__Block)i1, 49);
      i0 = (OOC_INT32)RT0__NewObject(_td_ADT_StringBuffer__StringBuffer.baseTypes[0]);
      ADT_StringBuffer__StringBufferDesc_INIT((ADT_StringBuffer__StringBuffer)i0, 1024);
      sb = (ADT_StringBuffer__StringBuffer)i0;
      i1 = (OOC_INT32)block;
      *(OOC_INT32*)(_check_pointer(i1, 21452)) = i0;
      i0 = (OOC_INT32)w;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21480))+8);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21480))+8);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 21487)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i0, (Object__Object)i1);
      return;
      ;
    }

    
    void OOC_X86_Write__WriterDesc_WriteBlock_MovMemReg(OOC_X86_SSA__Opnd fromMemReg, OOC_INT8 fromType, OOC_CHAR8 valueOpnd, OOC_X86_SSA__Result toReg) {
      register OOC_INT32 i0,i1,i2,i3,i4;
      OOC_INT8 toType;

      i0 = (OOC_INT32)toReg;
      i1 = *(OOC_INT8*)((_check_pointer(i0, 22074))+12);
      toType = i1;
      i2 = fromType;
      i3 = i2==i1;
      if (i3) goto l3;
      i3 = OOC_X86_SSA__TypeSize(i1);
      i4 = OOC_X86_SSA__TypeSize(i2);
      i3 = i3<=i4;
      
      goto l4;
l3:
      i3=1u;
l4:
      i4 = valueOpnd;
      if (i3) goto l15;
      i3 = i1<5;
      if (i3) goto l9;
      i3=0u;
      goto l11;
l9:
      i3 = i2<5;
      
l11:
      if (i3) goto l13;
      OOC_X86_Write__WriterDesc_WriteBlock_OpcTT("movz", 5, i2, i1);
      goto l30;
l13:
      OOC_X86_Write__WriterDesc_WriteBlock_OpcTT("movs", 5, i2, i1);
      goto l30;
l15:
      if (i4) goto l17;
      i2=0u;
      goto l19;
l17:
      i2 = (OOC_INT32)fromMemReg;
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 22370));
      i3 = *(OOC_INT8*)((_check_pointer(i0, 22348))+13);
      i2 = *(OOC_INT8*)((_check_pointer(i2, 22374))+13);
      i2 = i3==i2;
      
l19:
      if (!i2) goto l21;
      return;
l21:
      fromType = i1;
      switch (i1) {
      case 10:
      case 11:
        i2 = *(OOC_INT8*)((_check_pointer(i0, 22605))+13);
        i2 = i2!=9;
        if (i2) goto l26;
        OOC_X86_Write__WriterDesc_WriteBlock_OpcTT("fld", 4, i1, 0);
        goto l29;
l26:
        OOC_X86_Write__WriterDesc_WriteBlock_OpcTT("movs", 5, i1, 0);
        goto l29;
      default:
        OOC_X86_Write__WriterDesc_WriteBlock_OpcTT("mov", 4, i1, 0);
        goto l29;
      }
l29:
      i2=i1;
l30:
      opndWidth = i2;
      if (i4) goto l37;
      i2 = (OOC_INT32)fromMemReg;
      i3 = *(OOC_UINT8*)((_check_pointer(i2, 23156))+16);
      if (i3) goto l35;
      OOC_X86_Write__WriterDesc_WriteBlock_OpndMem((OOC_X86_SSA__Opnd)i2);
      goto l38;
l35:
      OOC_X86_Write__WriterDesc_WriteBlock_DirectOpnd((OOC_X86_SSA__Opnd)i2);
      goto l38;
l37:
      i2 = (OOC_INT32)instr;
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 23112));
      OOC_X86_Write__WriterDesc_WriteBlock_Opnd((OOC_X86_SSA__Opnd)i2);
l38:
      i2 = *(OOC_INT8*)((_check_pointer(i0, 23289))+13);
      i2 = i2!=9;
      if (!i2) goto l41;
      OOC_X86_Write__WriterDesc_WriteBlock_Comma();
      i0 = *(OOC_INT8*)((_check_pointer(i0, 23348))+13);
      OOC_X86_Write__WriterDesc_WriteBlock_RegT(i0, i1);
l41:
      return;
      ;
    }

    
    void OOC_X86_Write__WriterDesc_WriteBlock_MovMemRegNoX(OOC_X86_SSA__Opnd fromMemReg, OOC_INT8 fromType, OOC_CHAR8 valueOpnd, OOC_X86_SSA__Result toReg) {
      register OOC_INT32 i0,i1,i2,i3,i4;
      OOC_INT8 toType;

      i0 = (OOC_INT32)toReg;
      i1 = *(OOC_INT8*)((_check_pointer(i0, 23951))+12);
      toType = i1;
      i2 = valueOpnd;
      if (i2) goto l3;
      i3=0u;
      goto l5;
l3:
      i3 = (OOC_INT32)fromMemReg;
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 24007));
      i4 = *(OOC_INT8*)((_check_pointer(i0, 23985))+13);
      i3 = *(OOC_INT8*)((_check_pointer(i3, 24011))+13);
      i3 = i4==i3;
      
l5:
      if (!i3) goto l7;
      return;
l7:
      fromType = i1;
      switch (i1) {
      case 10:
      case 11:
        i3 = *(OOC_INT8*)((_check_pointer(i0, 24230))+13);
        i3 = i3!=9;
        if (i3) goto l12;
        OOC_X86_Write__WriterDesc_WriteBlock_OpcTT("fld", 4, i1, 0);
        goto l15;
l12:
        OOC_X86_Write__WriterDesc_WriteBlock_OpcTT("movs", 5, i1, 0);
        goto l15;
      default:
        OOC_X86_Write__WriterDesc_WriteBlock_OpcTT("mov", 4, i1, 0);
        goto l15;
      }
l15:
      opndWidth = i1;
      if (i2) goto l22;
      i2 = (OOC_INT32)fromMemReg;
      i3 = *(OOC_UINT8*)((_check_pointer(i2, 24555))+16);
      if (i3) goto l20;
      OOC_X86_Write__WriterDesc_WriteBlock_OpndMem((OOC_X86_SSA__Opnd)i2);
      goto l23;
l20:
      OOC_X86_Write__WriterDesc_WriteBlock_DirectOpnd((OOC_X86_SSA__Opnd)i2);
      goto l23;
l22:
      i2 = (OOC_INT32)instr;
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 24511));
      OOC_X86_Write__WriterDesc_WriteBlock_Opnd((OOC_X86_SSA__Opnd)i2);
l23:
      i2 = *(OOC_INT8*)((_check_pointer(i0, 24688))+13);
      i2 = i2!=9;
      if (!i2) goto l26;
      OOC_X86_Write__WriterDesc_WriteBlock_Comma();
      i0 = *(OOC_INT8*)((_check_pointer(i0, 24747))+13);
      OOC_X86_Write__WriterDesc_WriteBlock_RegT(i0, i1);
l26:
      return;
      ;
    }

    
    void OOC_X86_Write__WriterDesc_WriteBlock_Bounce(OOC_X86_SSA__Result from, OOC_X86_SSA__Result to) {
      register OOC_INT32 i0;

      OOC_X86_Write__WriterDesc_WriteBlock_Opc("movs", 5);
      i0 = (OOC_INT32)from;
      OOC_X86_Write__WriterDesc_WriteBlock_Result((OOC_X86_SSA__Result)i0);
      i0 = (OOC_INT32)sb;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 24898)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1)),ADT_StringBuffer__StringBufferDesc_AppendLatin1)((ADT_StringBuffer__StringBuffer)i0, ", (%esp)", 9);
      OOC_X86_Write__WriterDesc_WriteBlock_Opc("fld", 4);
      i0 = (OOC_INT32)sb;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 24951)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1)),ADT_StringBuffer__StringBufferDesc_AppendLatin1)((ADT_StringBuffer__StringBuffer)i0, "(%esp)", 7);
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
  *(OOC_INT32*)(_check_pointer(i3, 25108)) = i0;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 25134))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 25134))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 25141)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i1, (Object__Object)i3);
  i1 = (OOC_INT32)label;
  i3 = i1!=(OOC_INT32)0;
  if (!i3) goto l3;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 25192)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)_c43),(void*)i1)),(void*)((OOC_INT32)_c44))));
l3:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 25243))+48);
  instr = (OOC_X86_SSA__Instr)i0;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l170;
  i1 = (OOC_INT32)_c45;
  i2 = (OOC_INT32)_c46;
  i3 = (OOC_INT32)_c47;
  i4 = (OOC_INT32)_c48;
  i5 = (OOC_INT32)_c49;
  i6 = (OOC_INT32)_c50;
  i7 = (OOC_INT32)_c51;
  i8 = (OOC_INT32)_c52;
  
l6_loop:
  i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25306))+8);
  nextInstr = (OOC_X86_SSA__Instr)i9;
  i9 = OOC_X86_SSA__InstrDesc_IsLive((OOC_X86_SSA__Instr)i0);
  if (!i9) goto l131;
  i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25411))+4);
  i9 = i9!=(OOC_INT32)0;
  if (i9) goto l11;
  opndWidth = 0;
  goto l12;
l11:
  i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25463))+4);
  i9 = *(OOC_INT8*)((_check_pointer(i9, 25474))+12);
  opndWidth = i9;
l12:
  i9 = *(OOC_INT8*)((_check_pointer(i0, 25567))+20);
  switch (i9) {
  case 0:
    i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25647))+4);
    i9 = *(OOC_INT8*)((_check_pointer(i9, 25658))+12);
    type = i9;
    switch (i9) {
    case 10:
    case 11:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25741))+4);
      i0 = *(OOC_INT8*)((_check_pointer(i0, 25752))+13);
      i0 = i0==9;
      if (i0) goto l19;
      OOC_X86_Write__WriterDesc_WriteBlock_Opc("movs", 5);
      i0 = (OOC_INT32)instr;
      OOC_X86_Write__WriterDesc_WriteBlock_Literal((OOC_X86_SSA__Instr)i0);
      OOC_X86_Write__WriterDesc_WriteBlock_Comma();
      i0 = (OOC_INT32)instr;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26012))+4);
      OOC_X86_Write__WriterDesc_WriteBlock_Result((OOC_X86_SSA__Result)i0);
      goto l131;
l19:
      OOC_X86_Write__WriterDesc_WriteBlock_Opc("fld", 4);
      i0 = (OOC_INT32)instr;
      OOC_X86_Write__WriterDesc_WriteBlock_Literal((OOC_X86_SSA__Instr)i0);
      goto l131;
    default:
      OOC_X86_Write__WriterDesc_WriteBlock_Opc("mov", 4);
      i0 = (OOC_INT32)sb;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 26150)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)),ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)((ADT_StringBuffer__StringBuffer)i0, 36u);
      i0 = (OOC_INT32)instr;
      OOC_X86_Write__WriterDesc_WriteBlock_Literal((OOC_X86_SSA__Instr)i0);
      OOC_X86_Write__WriterDesc_WriteBlock_Comma();
      i0 = (OOC_INT32)instr;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26247))+4);
      OOC_X86_Write__WriterDesc_WriteBlock_Result((OOC_X86_SSA__Result)i0);
      goto l131;
    }
    /* goto: unreachable */
  case 1:
    i9 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 26329));
    i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i9, 26338))+4);
    i9 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i9, 26347));
    i9 = (OOC_INT32)OOC_X86_SSA__ResultDesc_GetConst((OOC_X86_SSA__Result)i9);
    i10 = (OOC_INT32)Object_BigInt__one;
    i9 = Object_BigInt__BigIntDesc_Equals((Object_BigInt__BigInt)i10, (Object__Object)i9);
    if (i9) goto l30;
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26428))+4);
    i0 = OOC_X86_SSA__ResultDesc_IsFloat((OOC_X86_SSA__Result)i0);
    if (i0) goto l28;
    OOC_X86_Write__WriterDesc_WriteBlock_Opc("add", 4);
    goto l29;
l28:
    OOC_X86_Write__WriterDesc_WriteBlock_Opc("adds", 5);
l29:
    i0 = (OOC_INT32)instr;
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 26564));
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26573))+4);
    OOC_X86_Write__WriterDesc_WriteBlock_Opnd((OOC_X86_SSA__Opnd)i0);
    OOC_X86_Write__WriterDesc_WriteBlock_Comma();
    goto l31;
l30:
    OOC_X86_Write__WriterDesc_WriteBlock_Opc("inc", 4);
l31:
    i0 = (OOC_INT32)instr;
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26643))+4);
    OOC_X86_Write__WriterDesc_WriteBlock_Result((OOC_X86_SSA__Result)i0);
    i0 = (OOC_INT32)instr;
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 26690));
    OOC_X86_Write__WriterDesc_WriteBlock_AssertResultMatch((OOC_X86_SSA__Opnd)i0);
    goto l131;
  case 2:
  case 32:
    i9 = *(OOC_INT8*)((_check_pointer(i0, 26755))+20);
    i9 = i9==32;
    if (!i9) goto l35;
    i9 = (OOC_INT32)sb;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i9, 26801)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1)),ADT_StringBuffer__StringBufferDesc_AppendLatin1)((ADT_StringBuffer__StringBuffer)i9, "\012\011pushl %edi", 13);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i9, 26850)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1)),ADT_StringBuffer__StringBufferDesc_AppendLatin1)((ADT_StringBuffer__StringBuffer)i9, "\012\011pushl %esi", 13);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i9, 26899)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1)),ADT_StringBuffer__StringBufferDesc_AppendLatin1)((ADT_StringBuffer__StringBuffer)i9, "\012\011pushl %ebx", 13);
l35:
    i9 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 26985));
    i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i9, 26994))+4);
    i9 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i9, 27003));
    i9 = (OOC_INT32)OOC_X86_SSA__ResultDesc_GetConst((OOC_X86_SSA__Result)i9);
    i10 = (OOC_INT32)Object_BigInt__one;
    i9 = Object_BigInt__BigIntDesc_Equals((Object_BigInt__BigInt)i10, (Object__Object)i9);
    if (i9) goto l42;
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27084))+4);
    i0 = OOC_X86_SSA__ResultDesc_IsFloat((OOC_X86_SSA__Result)i0);
    if (i0) goto l40;
    OOC_X86_Write__WriterDesc_WriteBlock_Opc("sub", 4);
    goto l41;
l40:
    OOC_X86_Write__WriterDesc_WriteBlock_Opc("subs", 5);
l41:
    i0 = (OOC_INT32)instr;
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 27220));
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27229))+4);
    OOC_X86_Write__WriterDesc_WriteBlock_Opnd((OOC_X86_SSA__Opnd)i0);
    OOC_X86_Write__WriterDesc_WriteBlock_Comma();
    goto l43;
l42:
    OOC_X86_Write__WriterDesc_WriteBlock_Opc("dec", 4);
l43:
    i0 = (OOC_INT32)instr;
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27299))+4);
    OOC_X86_Write__WriterDesc_WriteBlock_Result((OOC_X86_SSA__Result)i0);
    i0 = (OOC_INT32)instr;
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 27346));
    OOC_X86_Write__WriterDesc_WriteBlock_AssertResultMatch((OOC_X86_SSA__Opnd)i0);
    goto l131;
  case 3:
    OOC_X86_Write__WriterDesc_WriteBlock_Opc("imul", 5);
    i0 = (OOC_INT32)instr;
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 27419));
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27428))+4);
    OOC_X86_Write__WriterDesc_WriteBlock_Opnd((OOC_X86_SSA__Opnd)i0);
    OOC_X86_Write__WriterDesc_WriteBlock_Comma();
    i0 = (OOC_INT32)instr;
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27481))+4);
    OOC_X86_Write__WriterDesc_WriteBlock_Result((OOC_X86_SSA__Result)i0);
    i0 = (OOC_INT32)instr;
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 27528));
    OOC_X86_Write__WriterDesc_WriteBlock_AssertResultMatch((OOC_X86_SSA__Opnd)i0);
    goto l131;
  case 5:
    OOC_X86_Write__WriterDesc_WriteBlock_Opc("neg", 4);
    i0 = (OOC_INT32)instr;
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 27599));
    OOC_X86_Write__WriterDesc_WriteBlock_Opnd((OOC_X86_SSA__Opnd)i0);
    i0 = (OOC_INT32)instr;
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 27644));
    OOC_X86_Write__WriterDesc_WriteBlock_AssertResultMatch((OOC_X86_SSA__Opnd)i0);
    goto l131;
  case 6:
  case 7:
  case 8:
  case 9:
  case 11:
  case 10:
    i0 = *(OOC_INT8*)((_check_pointer(i0, 27733))+20);
    OOC_X86_Write__WriterDesc_WriteBlock_ShiftOpcode(i0);
    opndWidth = 1;
    i0 = (OOC_INT32)instr;
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 27797));
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27806))+4);
    OOC_X86_Write__WriterDesc_WriteBlock_Opnd((OOC_X86_SSA__Opnd)i0);
    OOC_X86_Write__WriterDesc_WriteBlock_Comma();
    i0 = (OOC_INT32)instr;
    i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27865))+4);
    i9 = *(OOC_INT8*)((_check_pointer(i9, 27876))+12);
    opndWidth = i9;
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27905))+4);
    OOC_X86_Write__WriterDesc_WriteBlock_Result((OOC_X86_SSA__Result)i0);
    i0 = (OOC_INT32)instr;
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 27952));
    OOC_X86_Write__WriterDesc_WriteBlock_AssertResultMatch((OOC_X86_SSA__Opnd)i0);
    goto l131;
  case 13:
  case 14:
  case 15:
  case 16:
  case 17:
  case 18:
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 28044));
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 28053));
    i0 = *(OOC_INT8*)((_check_pointer(i0, 28057))+12);
    opndWidth = i0;
    i0 = OOC_X86_SSA__IsFloat(i0);
    if (i0) goto l50;
    OOC_X86_Write__WriterDesc_WriteBlock_Opc("cmp", 4);
    goto l51;
l50:
    OOC_X86_Write__WriterDesc_WriteBlock_Opc("ucomis", 7);
l51:
    i0 = (OOC_INT32)instr;
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 28204));
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28213))+4);
    OOC_X86_Write__WriterDesc_WriteBlock_Opnd((OOC_X86_SSA__Opnd)i0);
    OOC_X86_Write__WriterDesc_WriteBlock_Comma();
    i0 = (OOC_INT32)instr;
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 28264));
    OOC_X86_Write__WriterDesc_WriteBlock_Opnd((OOC_X86_SSA__Opnd)i0);
    goto l131;
  case 19:
    i9 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 28319));
    i9 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i9, 28328));
    i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i9, 28332))+4);
    cmp = (OOC_X86_SSA__Instr)i9;
    i10 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i9, 28375));
    i10 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i10, 28384));
    i9 = *(OOC_INT8*)((_check_pointer(i9, 28398))+20);
    i10 = *(OOC_INT8*)((_check_pointer(i10, 28388))+12);
    i9 = (OOC_INT32)OOC_X86_Write__OpcodeCC(i10, i9);
    i9 = (OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)i1,(void*)i9)),(void*)i5);
    str = (Object__String)i9;
    i10 = (OOC_INT32)sb;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i10, 28424)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i10, (Object__Object)i9);
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 28458));
    OOC_X86_Write__WriterDesc_WriteBlock_Opnd((OOC_X86_SSA__Opnd)i0);
    goto l131;
  case 20:
    OOC_X86_Write__WriterDesc_WriteBlock_Opc("bts", 4);
    i0 = (OOC_INT32)instr;
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 28539));
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28548))+4);
    OOC_X86_Write__WriterDesc_WriteBlock_Opnd((OOC_X86_SSA__Opnd)i0);
    OOC_X86_Write__WriterDesc_WriteBlock_Comma();
    i0 = (OOC_INT32)instr;
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28601))+4);
    OOC_X86_Write__WriterDesc_WriteBlock_Result((OOC_X86_SSA__Result)i0);
    i0 = (OOC_INT32)instr;
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 28648));
    OOC_X86_Write__WriterDesc_WriteBlock_AssertResultMatch((OOC_X86_SSA__Opnd)i0);
    goto l131;
  case 21:
    OOC_X86_Write__WriterDesc_WriteBlock_Opc("btr", 4);
    i0 = (OOC_INT32)instr;
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 28731));
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28740))+4);
    OOC_X86_Write__WriterDesc_WriteBlock_Opnd((OOC_X86_SSA__Opnd)i0);
    OOC_X86_Write__WriterDesc_WriteBlock_Comma();
    i0 = (OOC_INT32)instr;
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28793))+4);
    OOC_X86_Write__WriterDesc_WriteBlock_Result((OOC_X86_SSA__Result)i0);
    i0 = (OOC_INT32)instr;
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 28840));
    OOC_X86_Write__WriterDesc_WriteBlock_AssertResultMatch((OOC_X86_SSA__Opnd)i0);
    goto l131;
  case 26:
    goto l131;
  case 27:
    OOC_X86_Write__WriterDesc_WriteBlock_Opc0("ret", 4);
    goto l131;
  case 29:
    OOC_X86_Write__WriterDesc_WriteBlock_Opc0("call", 5);
    i0 = (OOC_INT32)instr;
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 29048));
    OOC_X86_Write__WriterDesc_WriteBlock_DirectOpnd((OOC_X86_SSA__Opnd)i0);
    goto l131;
  case 30:
    OOC_X86_Write__WriterDesc_WriteBlock_Opc("fstp", 5);
    i0 = (OOC_INT32)sb;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 29121)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1)),ADT_StringBuffer__StringBufferDesc_AppendLatin1)((ADT_StringBuffer__StringBuffer)i0, "(%esp)", 7);
    OOC_X86_Write__WriterDesc_WriteBlock_Opc("movs", 5);
    i0 = (OOC_INT32)sb;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 29181)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1)),ADT_StringBuffer__StringBufferDesc_AppendLatin1)((ADT_StringBuffer__StringBuffer)i0, "(%esp), ", 9);
    i0 = (OOC_INT32)instr;
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29230))+4);
    OOC_X86_Write__WriterDesc_WriteBlock_Result((OOC_X86_SSA__Result)i0);
    goto l131;
  case 41:
    i0 = (OOC_INT32)w;
    i9 = (OOC_INT32)sb;
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29344))+184);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i9, 29332)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i9, (Object__Object)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)i6,(void*)i0)),(void*)i7)));
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i9, 29373)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1)),ADT_StringBuffer__StringBufferDesc_AppendLatin1)((ADT_StringBuffer__StringBuffer)i9, "\012\011lea -12(%ebp), %esp", 22);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i9, 29429)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1)),ADT_StringBuffer__StringBufferDesc_AppendLatin1)((ADT_StringBuffer__StringBuffer)i9, "\012\011popl %ebx", 12);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i9, 29475)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1)),ADT_StringBuffer__StringBufferDesc_AppendLatin1)((ADT_StringBuffer__StringBuffer)i9, "\012\011popl %esi", 12);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i9, 29521)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1)),ADT_StringBuffer__StringBufferDesc_AppendLatin1)((ADT_StringBuffer__StringBuffer)i9, "\012\011popl %edi", 12);
    OOC_X86_Write__WriterDesc_WriteBlock_Opc0("leave", 6);
    goto l131;
  case 36:
  case 38:
  case 22:
    i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29787))+4);
    i9 = *(OOC_INT8*)((_check_pointer(i9, 29798))+12);
    i9 = i9==9;
    if (i9) goto l63;
    i9=0u;
    goto l69;
l63:
    i9 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 29839));
    i9 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i9, 29848));
    i9 = *(OOC_INT8*)((_check_pointer(i9, 29852))+12);
    i9 = i9==3;
    if (i9) goto l66;
    i9 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 29895));
    i9 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i9, 29904));
    i9 = *(OOC_INT8*)((_check_pointer(i9, 29908))+12);
    i9 = i9==7;
    
    goto l69;
l66:
    i9=1u;
l69:
    if (i9) goto l83;
    i9 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 29989));
    i9 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i9, 29998));
    i9 = *(OOC_INT8*)((_check_pointer(i9, 30002))+12);
    i9 = i9==9;
    if (i9) goto l73;
    i9=0u;
    goto l79;
l73:
    i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30046))+4);
    i9 = *(OOC_INT8*)((_check_pointer(i9, 30057))+12);
    i9 = i9==3;
    if (i9) goto l76;
    i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30103))+4);
    i9 = *(OOC_INT8*)((_check_pointer(i9, 30114))+12);
    i9 = i9==7;
    
    goto l79;
l76:
    i9=1u;
l79:
    if (i9) goto l81;
    i9 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 30225));
    i9 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i9, 30234));
    i9 = *(OOC_INT8*)((_check_pointer(i9, 30238))+12);
    type = i9;
    
    goto l84;
l81:
    i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30167))+4);
    i9 = *(OOC_INT8*)((_check_pointer(i9, 30178))+12);
    type = i9;
    
    goto l84;
l83:
    type = 9;
    i9=9;
l84:
    i10 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30313))+4);
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 30285));
    OOC_X86_Write__WriterDesc_WriteBlock_MovMemReg((OOC_X86_SSA__Opnd)i0, i9, 1u, (OOC_X86_SSA__Result)i10);
    goto l131;
  case 37:
    i9 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 30372));
    i9 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i9, 30381));
    i9 = *(OOC_INT8*)((_check_pointer(i9, 30385))+12);
    type = i9;
    i10 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30448))+4);
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 30420));
    OOC_X86_Write__WriterDesc_WriteBlock_MovMemRegNoX((OOC_X86_SSA__Opnd)i0, i9, 1u, (OOC_X86_SSA__Result)i10);
    goto l131;
  case 28:
    i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30501))+4);
    i9 = *(OOC_INT8*)((_check_pointer(i9, 30512))+13);
    i9 = i9==9;
    if (i9) goto l89;
    i9=0u;
    goto l91;
l89:
    i9 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 30552));
    i9 = *(OOC_UINT8*)((_check_pointer(i9, 30561))+16);
    i9 = !i9;
    
l91:
    if (i9) goto l93;
    i9=0u;
    goto l95;
l93:
    i9 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 30593));
    i9 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i9, 30602));
    i9 = *(OOC_INT8*)((_check_pointer(i9, 30606))+12);
    i9 = i9!=9;
    
l95:
    if (i9) goto l97;
    i9 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 30742));
    i9 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i9, 30751));
    i10 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30795))+4);
    i9 = *(OOC_INT8*)((_check_pointer(i9, 30755))+12);
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 30726));
    OOC_X86_Write__WriterDesc_WriteBlock_MovMemReg((OOC_X86_SSA__Opnd)i0, i9, 1u, (OOC_X86_SSA__Result)i10);
    goto l98;
l97:
    i9 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 30650));
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30670))+4);
    i9 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i9, 30659));
    OOC_X86_Write__WriterDesc_WriteBlock_Bounce((OOC_X86_SSA__Result)i9, (OOC_X86_SSA__Result)i0);
l98:
    OOC_X86_Write__WriterDesc_WriteBlock_Opc0("jmp", 4);
    i0 = (OOC_INT32)w;
    i9 = (OOC_INT32)sb;
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30868))+184);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i9, 30859)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i9, (Object__Object)i0);
    goto l131;
  case 34:
    i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30939))+4);
    i10 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30989))+4);
    i9 = *(OOC_INT8*)((_check_pointer(i9, 30950))+12);
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 30923));
    OOC_X86_Write__WriterDesc_WriteBlock_MovMemReg((OOC_X86_SSA__Opnd)i0, i9, 0u, (OOC_X86_SSA__Result)i10);
    goto l131;
  case 35:
    i9 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 31048));
    i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i9, 31057))+4);
    i9 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i9, 31066));
    i9 = *(OOC_INT8*)((_check_pointer(i9, 31070))+12);
    opndWidth = i9;
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 31095));
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31104))+4);
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 31113));
    i0 = OOC_X86_SSA__ResultDesc_IsFloat((OOC_X86_SSA__Result)i0);
    if (i0) goto l103;
    OOC_X86_Write__WriterDesc_WriteBlock_Opc("mov", 4);
    goto l104;
l103:
    OOC_X86_Write__WriterDesc_WriteBlock_Opc("movs", 5);
l104:
    i0 = (OOC_INT32)instr;
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 31232));
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31241))+4);
    OOC_X86_Write__WriterDesc_WriteBlock_Opnd((OOC_X86_SSA__Opnd)i0);
    OOC_X86_Write__WriterDesc_WriteBlock_Comma();
    i0 = (OOC_INT32)instr;
    i9 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 31290));
    i9 = *(OOC_UINT8*)((_check_pointer(i9, 31299))+16);
    if (i9) goto l107;
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 31395));
    OOC_X86_Write__WriterDesc_WriteBlock_OpndMem((OOC_X86_SSA__Opnd)i0);
    goto l131;
l107:
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 31343));
    OOC_X86_Write__WriterDesc_WriteBlock_DirectOpnd((OOC_X86_SSA__Opnd)i0);
    goto l131;
  case 39:
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 31468));
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31477))+4);
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 31486));
    i0 = *(OOC_INT8*)((_check_pointer(i0, 31490))+12);
    opndWidth = i0;
    OOC_X86_Write__WriterDesc_WriteBlock_Opc("push", 5);
    i0 = (OOC_INT32)instr;
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 31540));
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31549))+4);
    OOC_X86_Write__WriterDesc_WriteBlock_Opnd((OOC_X86_SSA__Opnd)i0);
    goto l131;
  case 43:
    i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_NthOpnd((OOC_X86_SSA__Instr)i0, 2);
    opnd = (OOC_X86_SSA__Opnd)i0;
    i9 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 31646));
    i9 = *(OOC_INT8*)((_check_pointer(i9, 31650))+12);
    opndWidth = i9;
    omitStackArg = 0u;
    i9 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 31709));
    i9 = *(OOC_INT8*)((_check_pointer(i9, 31713))+12);
    switch (i9) {
    case 10:
    case 11:
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 31774));
      i0 = *(OOC_INT8*)((_check_pointer(i0, 31778))+13);
      i0 = i0==9;
      if (i0) goto l115;
      OOC_X86_Write__WriterDesc_WriteBlock_Opc("movs", 5);
      goto l118;
l115:
      OOC_X86_Write__WriterDesc_WriteBlock_Opc("fstp", 5);
      omitStackArg = 1u;
      goto l118;
    default:
      OOC_X86_Write__WriterDesc_WriteBlock_Opc("mov", 4);
      goto l118;
    }
l118:
    i0 = omitStackArg;
    i0 = !i0;
    if (!i0) goto l121;
    i0 = (OOC_INT32)opnd;
    OOC_X86_Write__WriterDesc_WriteBlock_Opnd((OOC_X86_SSA__Opnd)i0);
    i0 = (OOC_INT32)sb;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32050)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i3);
l121:
    i0 = (OOC_INT32)instr;
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 32103));
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32112))+4);
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 32121));
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32125))+4);
    OOC_X86_Write__WriterDesc_WriteBlock_Literal((OOC_X86_SSA__Instr)i0);
    i0 = (OOC_INT32)sb;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32146)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i4);
    goto l131;
  case 44:
    OOC_X86_Write__WriterDesc_WriteBlock_Opc("mov", 4);
    i0 = (OOC_INT32)sb;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32220)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i2);
    i0 = (OOC_INT32)instr;
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 32256));
    OOC_X86_Write__WriterDesc_WriteBlock_Opnd((OOC_X86_SSA__Opnd)i0);
    i0 = (OOC_INT32)sb;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32280)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i8);
    OOC_X86_Write__WriterDesc_WriteBlock_Comma();
    i0 = (OOC_INT32)instr;
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32335))+4);
    OOC_X86_Write__WriterDesc_WriteBlock_Result((OOC_X86_SSA__Result)i0);
    goto l131;
  case 46:
    goto l131;
  case 49:
  case 54:
    OOC_X86_Write__WriterDesc_WriteBlock_FixGatedValues((OOC_X86_SSA__Instr)i0);
    i0 = (OOC_INT32)instr;
    i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_MergingTarget((OOC_X86_SSA__Instr)i0);
    i9 = (OOC_INT32)w;
    i0 = (OOC_INT32)OOC_X86_Write__WriterDesc_GetBlock((OOC_X86_Write__Writer)i9, (OOC_X86_SSA__Block)i0);
    i9 = (OOC_INT32)block;
    OOC_X86_Write__BlockDesc_SetArc((OOC_X86_Write__Block)i9, (void*)((_check_pointer(i9, 32541))+12), (OOC_X86_Write__Block)i0, 49);
    nextInstr = (OOC_X86_SSA__Instr)(OOC_INT32)0;
    goto l131;
  case 50:
    goto l131;
  case 52:
    OOC_X86_Write__WriterDesc_WriteBlock_FixGatedValues((OOC_X86_SSA__Instr)i0);
    goto l131;
  case 55:
    OOC_X86_Write__WriterDesc_WriteBlock_FixGatedValues((OOC_X86_SSA__Instr)i0);
    i0 = (OOC_INT32)instr;
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32901)))), &_td_OOC_X86_SSA__LoopBackedgeInstrDesc, 32901)), 32919))+48);
    i9 = (OOC_INT32)w;
    i0 = (OOC_INT32)OOC_X86_Write__WriterDesc_GetBlock((OOC_X86_Write__Writer)i9, (OOC_X86_SSA__Block)i0);
    i9 = (OOC_INT32)block;
    OOC_X86_Write__BlockDesc_SetArc((OOC_X86_Write__Block)i9, (void*)((_check_pointer(i9, 32852))+12), (OOC_X86_Write__Block)i0, 49);
    goto l131;
  case 53:
    goto l131;
  default:
    _failed_case(i9, 25557);
    goto l131;
  }
l131:
  i0 = (OOC_INT32)instr;
  i9 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33029)))), &_td_OOC_X86_SSA__BranchInstrDesc);
  if (i9) goto l145;
  i9 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33916)))), &_td_OOC_X86_SSA__MergeInstrDesc);
  if (i9) goto l143;
  i9 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34016)))), &_td_OOC_X86_SSA__LoopStartInstrDesc);
  if (i9) goto l141;
  i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34094)))), &_td_OOC_X86_SSA__BlockDesc);
  if (!i0) goto l165;
  _assert(0u, 127, 34115);
  goto l165;
l141:
  i9 = (OOC_INT32)w;
  i0 = (OOC_INT32)OOC_X86_Write__WriterDesc_WriteBlock((OOC_X86_Write__Writer)i9, (OOC_X86_SSA__Block)i0, (Object__String)(OOC_INT32)0);
  dummy = (OOC_X86_Write__Block)i0;
  goto l165;
l143:
  i9 = *(OOC_INT8*)((_check_pointer(i0, 33954))+20);
  _assert((i9==53), 127, 33942);
  OOC_X86_Write__WriterDesc_WriteBlock_WriteMerge((OOC_X86_SSA__MergeInstr)i0);
  goto l165;
l145:
  i9 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 33068));
  i9 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i9, 33077));
  i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i9, 33081))+4);
  cmp = (OOC_X86_SSA__Instr)i9;
  i10 = *(OOC_UINT8*)((_check_pointer(i0, 33105))+60);
  if (i10) goto l152;
  i10 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33568))+56);
  i10 = _check_pointer(i10, 33574);
  i11 = OOC_ARRAY_LENGTH(i10, 0);
  i10 = (OOC_INT32)*(OOC_INT32*)(i10+(_check_index(0, i11, OOC_UINT8, 33574))*4);
  i10 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i10, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i10, 33580)))), &_td_OOC_X86_SSA__MergeInstrDesc, 33580)), 33591))+56);
  i10 = i10!=(OOC_INT32)0;
  if (i10) goto l150;
  i10 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33746))+56);
  i10 = _check_pointer(i10, 33752);
  i11 = OOC_ARRAY_LENGTH(i10, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33730))+56);
  i0 = _check_pointer(i0, 33736);
  i12 = OOC_ARRAY_LENGTH(i0, 0);
  i10 = (OOC_INT32)*(OOC_INT32*)(i10+(_check_index(1, i11, OOC_UINT8, 33752))*4);
  i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i12, OOC_UINT8, 33736))*4);
  OOC_X86_Write__WriterDesc_WriteBlock_WriteBranch2((OOC_X86_SSA__Instr)i9, 1u, (OOC_X86_SSA__Block)i0, (OOC_X86_SSA__Block)i10);
  goto l161;
l150:
  i10 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33666))+56);
  i10 = _check_pointer(i10, 33672);
  i11 = OOC_ARRAY_LENGTH(i10, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33650))+56);
  i0 = _check_pointer(i0, 33656);
  i12 = OOC_ARRAY_LENGTH(i0, 0);
  i10 = (OOC_INT32)*(OOC_INT32*)(i10+(_check_index(0, i11, OOC_UINT8, 33672))*4);
  i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(1, i12, OOC_UINT8, 33656))*4);
  OOC_X86_Write__WriterDesc_WriteBlock_WriteBranch2((OOC_X86_SSA__Instr)i9, 0u, (OOC_X86_SSA__Block)i0, (OOC_X86_SSA__Block)i10);
  goto l161;
l152:
  OOC_X86_Write__WriterDesc_WriteBlock_Opc0("jmp *", 6);
  opndWidth = 9;
  i0 = (OOC_INT32)instr;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 33201));
  OOC_X86_Write__WriterDesc_WriteBlock_Opnd((OOC_X86_SSA__Opnd)i0);
  i0 = (OOC_INT32)block;
  i9 = (OOC_INT32)instr;
  i10 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i9, 33256))+56);
  i10 = OOC_ARRAY_LENGTH((_check_pointer(i10, 33262)), 0);
  *(OOC_INT32*)((_check_pointer(i0, 33232))+16) = ((OOC_INT32)RT0__NewObject(_td_OOC_X86_Write__612.baseTypes[0], i10));
  i10 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i9, 33300))+56);
  i = 0;
  i10 = OOC_ARRAY_LENGTH((_check_pointer(i10, 33306)), 0);
  i11 = 0<i10;
  if (!i11) goto l161;
  i11 = (OOC_INT32)w;
  i12=0;
l155_loop:
  i13 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i9, 33339))+56);
  i13 = _check_pointer(i13, 33345);
  i14 = OOC_ARRAY_LENGTH(i13, 0);
  i13 = (OOC_INT32)*(OOC_INT32*)(i13+(_check_index(i12, i14, OOC_UINT32, 33345))*4);
  path = (OOC_X86_SSA__Block)i13;
  i14 = (OOC_INT32)OOC_X86_Write__WriterDesc_ConstSymbol((OOC_X86_Write__Writer)i11, (Object__Object)i13, 17);
  i13 = (OOC_INT32)OOC_X86_Write__WriterDesc_WriteBlock((OOC_X86_Write__Writer)i11, (OOC_X86_SSA__Block)i13, (Object__String)i14);
  dummy = (OOC_X86_Write__Block)i13;
  i14 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33442))+16);
  i14 = _check_pointer(i14, 33455);
  i15 = OOC_ARRAY_LENGTH(i14, 0);
  *(OOC_INT32*)(i14+(_check_index(i12, i15, OOC_UINT32, 33455))*4) = (OOC_INT32)0;
  i14 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33497))+16);
  i14 = _check_pointer(i14, 33510);
  i15 = OOC_ARRAY_LENGTH(i14, 0);
  OOC_X86_Write__BlockDesc_SetArc((OOC_X86_Write__Block)i0, (void*)(i14+(_check_index(i12, i15, OOC_UINT32, 33510))*4), (OOC_X86_Write__Block)i13, 46);
  i12 = i12+1;
  i = i12;
  i13 = i12<i10;
  if (i13) goto l155_loop;
l161:
  i0 = (OOC_INT32)instr;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33794))+52);
  i0 = _type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33807)))), &_td_OOC_X86_SSA__MergeInstrDesc, 33807);
  merge = (OOC_X86_SSA__MergeInstr)i0;
  i9 = *(OOC_INT8*)((_check_pointer(i0, 33837))+20);
  i9 = i9==48;
  if (!i9) goto l165;
  OOC_X86_Write__WriterDesc_WriteBlock_WriteMerge((OOC_X86_SSA__MergeInstr)i0);
l165:
  i0 = (OOC_INT32)nextInstr;
  instr = (OOC_X86_SSA__Instr)i0;
  i9 = i0!=(OOC_INT32)0;
  if (i9) goto l6_loop;
l170:
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
          i1 = *(OOC_INT8*)((_check_pointer(i0, 34488))+28);
          i1 = i1!=0;
          if (i1) goto l3;
          i0 = *(OOC_INT32*)((_check_pointer(i0, 34547))+56);
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
      *(OOC_INT32*)((_check_pointer(i0, 34609))+12) = i1;
      i0 = (OOC_INT32)w;
      i1 = (OOC_INT32)RT0__NewObject(_td__qtd7.baseTypes[0]);
      ADT_ArrayList__ArrayListDesc_INIT((ADT_ArrayList__ArrayList)i1, 16);
      *(OOC_INT32*)((_check_pointer(i0, 34673))+8) = i1;
      i0 = (OOC_INT32)w;
      i1 = (OOC_INT32)fctBlock;
      *(OOC_INT32*)((_check_pointer(i0, 34728))+176) = i1;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34769))+56);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 34778))+72);
      i2 = i2==(OOC_INT32)0;
      if (i2) goto l3;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34929))+56);
      i2 = (OOC_INT32)OOC_C_Naming__NameOfDeclaration((OOC_SymbolTable__Declaration)i2);
      *(OOC_INT32*)((_check_pointer(i0, 34887))+180) = i2;
      goto l4;
l3:
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 34842));
      i2 = (OOC_INT32)OOC_C_Naming__NameOfModuleInit((OOC_SymbolTable__Module)i2, 0u);
      *(OOC_INT32*)((_check_pointer(i0, 34808))+180) = i2;
l4:
      i0 = (OOC_INT32)w;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34966))+4);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34966))+4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 34968)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i0, (Object__Object)((OOC_INT32)_c53));
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 35021))+56);
      i0 = OOC_X86_Write__WriterDesc_WriteFunction_StartFunction_IsGlobal((OOC_SymbolTable__ProcDecl)i0);
      if (!i0) goto l7;
      i0 = (OOC_INT32)w;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35046))+4);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35076))+180);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35046))+4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 35048)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i0, (Object__Object)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)_c54),(void*)i2)));
l7:
      i0 = (OOC_INT32)w;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35102))+4);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35133))+180);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35102))+4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 35104)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i0, (Object__Object)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)_c55),(void*)i2)),(void*)((OOC_INT32)_c56))));
      i0 = (OOC_INT32)w;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35162))+4);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35181))+180);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35162))+4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 35164)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i0, (Object__Object)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)_c57),(void*)i2)),(void*)((OOC_INT32)_c58))));
      i0 = (OOC_INT32)w;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35215))+180);
      return (Object__String)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)_c59),(void*)i0));
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
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35390))+8);
      i = 0;
      i0 = *(OOC_INT32*)((_check_pointer(i0, 35397))+4);
      i1 = 0<i0;
      if (!i1) goto l19;
      i1=0;
l3_loop:
      i2 = (OOC_INT32)w;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 35426))+8);
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 35433));
      i2 = _check_pointer(i2, 35439);
      i3 = OOC_ARRAY_LENGTH(i2, 0);
      i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i1, i3, OOC_UINT32, 35439))*4);
      block = (OOC_X86_Write__Block)i2;
      i3 = OOC_X86_Write__BlockDesc_IsEmpty((OOC_X86_Write__Block)i2);
      if (!i3) goto l14;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 35498))+12);
      _assert((i3!=0), 127, 35486);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 35540))+12);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 35545))+4);
      nextBlock = (OOC_X86_Write__Block)i3;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 35588))+4);
      incoming = (OOC_X86_Write__Arc)i2;
      i4 = i2!=0;
      if (!i4) goto l14;
l8_loop:
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 35667))+12);
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
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35846))+8);
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 35853));
      i1 = _check_pointer(i1, 35859);
      i2 = OOC_ARRAY_LENGTH(i1, 0);
      i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 35859))*4);
      i2 = *(OOC_INT32*)((_check_pointer(i0, 35873))+16);
      *(OOC_INT32*)((_check_pointer(i1, 35862))+24) = i2;
      i1 = *(OOC_INT32*)((_check_pointer(i0, 35897))+16);
      *(OOC_INT32*)((_check_pointer(i0, 35897))+16) = (i1+1);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35932))+8);
      i0 = *(OOC_INT32*)((_check_pointer(i0, 35939))+4);
      i = 1;
      i1 = 1<i0;
      if (!i1) goto l38;
      i1=1;
l22_loop:
      i2 = (OOC_INT32)w;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 35968))+8);
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 35975));
      i3 = _check_pointer(i3, 35981);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i1, i4, OOC_UINT32, 35981))*4);
      block = (OOC_X86_Write__Block)i3;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 36003))+4);
      i4 = i4==0;
      if (i4) goto l25;
      i4=0u;
      goto l27;
l25:
      i4 = OOC_X86_Write__BlockDesc_IsEmpty((OOC_X86_Write__Block)i3);
      
l27:
      if (i4) goto l29;
      i4 = *(OOC_INT32*)((_check_pointer(i2, 36239))+16);
      *(OOC_INT32*)((_check_pointer(i3, 36228))+24) = i4;
      i3 = *(OOC_INT32*)((_check_pointer(i2, 36267))+16);
      *(OOC_INT32*)((_check_pointer(i2, 36267))+16) = (i3+1);
      goto l33;
l29:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 36069))+8);
      _assert((i2==0), 127, 36057);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 36104))+12);
      i2 = i2!=0;
      if (!i2) goto l32;
      OOC_X86_Write__ClearArc((void*)((_check_pointer(i3, 36148))+12));
l32:
      *(OOC_INT32*)((_check_pointer(i3, 36186))+24) = (-1);
l33:
      i1 = i1+1;
      i = i1;
      i2 = i1<i0;
      if (i2) goto l22_loop;
l38:
      i0 = (OOC_INT32)w;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36333))+8);
      i0 = *(OOC_INT32*)((_check_pointer(i0, 36340))+4);
      i = 0;
      i1 = 0<i0;
      if (!i1) goto l56;
      i1=0;
l41_loop:
      i2 = (OOC_INT32)w;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 36369))+8);
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 36376));
      i3 = _check_pointer(i3, 36382);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i1, i4, OOC_UINT32, 36382))*4);
      block = (OOC_X86_Write__Block)i3;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 36404))+4);
      i4 = i4!=0;
      if (!i4) goto l44;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 36441))+4);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 36441))+4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 36443)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i2, "\012.L", 4);
      i2 = (OOC_INT32)w;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 36477))+4);
      i5 = *(OOC_INT32*)((_check_pointer(i3, 36495))+24);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 36477))+4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 36479)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i2, i5, 0);
      i2 = (OOC_INT32)w;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 36518))+4);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 36518))+4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 36520)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i2, ":", 2);
l44:
      i2 = (OOC_INT32)w;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 36561))+4);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 36561))+4);
      i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 36581));
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 36563)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i2, (Object__Object)i5);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 36615))+8);
      i2 = i2!=0;
      if (i2) goto l47;
      i2=0u;
      goto l49;
l47:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 36638))+8);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 36645))+4);
      i4 = *(OOC_INT32*)((_check_pointer(i3, 36662))+24);
      i2 = *(OOC_INT32*)((_check_pointer(i2, 36648))+24);
      i2 = i2==(i4+1);
      
l49:
      if (!i2) goto l51;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 36800))+8);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 36807))+4);
      nextBlock = (OOC_X86_Write__Block)i2;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 36850))+12);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 36855))+4);
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 36827))+8);
      OOC_X86_Write__ArcDesc_ReplaceTo((OOC_X86_Write__Arc)i5, (OOC_X86_Write__Block)i4);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 36876))+12);
      OOC_X86_Write__ArcDesc_ReplaceTo((OOC_X86_Write__Arc)i4, (OOC_X86_Write__Block)i2);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 36919))+8);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 36955))+8);
      i4 = *(OOC_INT8*)((_check_pointer(i4, 36962))+9);
      i4 = OOC_X86_Write__NegateBranch(i4);
      *(OOC_INT8*)((_check_pointer(i2, 36926))+9) = i4;
l51:
      i2 = (OOC_INT32)w;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 37012))+8);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 37003))+4);
      OOC_X86_Write__WriteArc((IO_TextRider__Writer)i2, (OOC_X86_Write__Arc)i4);
      i2 = (OOC_INT32)w;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 37049))+12);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 37040))+4);
      OOC_X86_Write__WriteArc((IO_TextRider__Writer)i2, (OOC_X86_Write__Arc)i3);
      i1 = i1+1;
      i = i1;
      i2 = i1<i0;
      if (i2) goto l41_loop;
l56:
      i0 = (OOC_INT32)w;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 37106))+180);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 37075))+4);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 37120))+180);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 37075))+4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 37077)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i0, (Object__Object)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)_c60),(void*)i1)),(void*)((OOC_INT32)_c61))),(void*)i3)));
      return;
      ;
    }


  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)b;
  i1 = (OOC_INT32)OOC_X86_Write__WriterDesc_WriteFunction_StartFunction((OOC_X86_SSA__FunctionBlock)i1);
  *(OOC_INT32*)((_check_pointer(i0, 37165))+184) = i1;
  i0 = (OOC_INT32)b;
  i1 = (OOC_INT32)w;
  i0 = (OOC_INT32)OOC_X86_Write__WriterDesc_WriteBlock((OOC_X86_Write__Writer)i1, (OOC_X86_SSA__Block)i0, (Object__String)(OOC_INT32)0);
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
  _c18 = Object__NewLatin1Region(".LC", 4, 0, 3);
  _c19 = Object__NewLatin1Char(10u);
  _c20 = Object__NewLatin1Char(58u);
  _c21 = Object__NewLatin1Region("\012\011.string \"", 12, 0, 11);
  _c22 = Object__NewLatin1Region("\012\011.long 0x", 11, 0, 10);
  _c23 = Object__NewLatin1Region("\012\011.long 0x", 11, 0, 10);
  _c24 = Object__NewLatin1Region("\012\011.long 0x", 11, 0, 10);
  _c25 = Object__NewLatin1Region("\012\011.long ", 9, 0, 8);
  _c26 = Object__NewLatin1Region("\012\011.long ", 9, 0, 8);
  _c27 = Object__NewLatin1Region("\012\011.long ", 9, 0, 8);
  _c28 = Object__NewLatin1Region("\012\011.long ", 9, 0, 8);
  _c29 = Object__NewLatin1Region("\012\011.long ", 9, 0, 8);
  _c30 = Object__NewLatin1Region("\012\011.long ", 9, 0, 8);
  _c31 = Object__NewLatin1Char(34u);
  _c32 = Object__NewLatin1Region("\012.global ", 10, 0, 9);
  _c33 = Object__NewLatin1Region("\012\011.type ", 9, 0, 8);
  _c34 = Object__NewLatin1Region(", @function", 12, 0, 11);
  _c35 = Object__NewLatin1Char(10u);
  _c36 = Object__NewLatin1Char(58u);
  _c37 = Object__NewLatin1Region("\012\011call ", 8, 0, 7);
  _c38 = Object__NewLatin1Region("\012\011ret", 6, 0, 5);
  _c39 = Object__NewLatin1Region("\012\011.size ", 9, 0, 8);
  _c40 = Object__NewLatin1Region(", .-", 5, 0, 4);
  _c41 = Object__NewLatin1Char(48u);
  _c42 = Object__NewLatin1Region("_mid", 5, 0, 4);
  _c43 = Object__NewLatin1Char(10u);
  _c44 = Object__NewLatin1Char(58u);
  _c45 = Object__NewLatin1Region("set", 4, 0, 3);
  _c46 = Object__NewLatin1Region("-4(", 4, 0, 3);
  _c47 = Object__NewLatin1Region(", ", 3, 0, 2);
  _c48 = Object__NewLatin1Region("(%esp)", 7, 0, 6);
  _c49 = Object__NewLatin1Char(32u);
  _c50 = Object__NewLatin1Char(10u);
  _c51 = Object__NewLatin1Char(58u);
  _c52 = Object__NewLatin1Char(41u);
  _c53 = Object__NewLatin1Region("\012\011.p2align 4,,15", 17, 0, 16);
  _c54 = Object__NewLatin1Region("\012.global ", 10, 0, 9);
  _c55 = Object__NewLatin1Region("\012\011.type ", 9, 0, 8);
  _c56 = Object__NewLatin1Region(", @function", 12, 0, 11);
  _c57 = Object__NewLatin1Char(10u);
  _c58 = Object__NewLatin1Char(58u);
  _c59 = Object__NewLatin1Region(".LE_", 5, 0, 4);
  _c60 = Object__NewLatin1Region("\012\011.size ", 9, 0, 8);
  _c61 = Object__NewLatin1Region(", .-", 5, 0, 4);

  return;
  ;
}

/* --- */
