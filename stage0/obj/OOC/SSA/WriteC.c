#include <OOC/SSA/WriteC.d>
#include <__oo2c.h>
#include <setjmp.h>

static OOC_SSA_WriteC__Visitor OOC_SSA_WriteC__NewVisitor(void) {
  register OOC_INT32 i0,i1;
  OOC_SSA_WriteC__Visitor v;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_SSA_WriteC__Visitor.baseTypes[0]);
  v = (OOC_SSA_WriteC__Visitor)i0;
  OOC_IR_VisitAll__InitVisitor((OOC_IR_VisitAll__Visitor)i0);
  *(OOC_INT32*)(_check_pointer(i0, 3107)) = 0;
  i1 = (OOC_INT32)ADT_Dictionary__New();
  *(OOC_INT32*)((_check_pointer(i0, 3139))+4) = i1;
  return (OOC_SSA_WriteC__Visitor)i0;
  ;
}

void OOC_SSA_WriteC__VisitorDesc_VisitProcedure(OOC_SSA_WriteC__Visitor v, OOC_IR__Procedure procedure) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)procedure;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3319))+4);
  *(OOC_INT32*)(_check_pointer(i0, 3288)) = i2;
  OOC_IR_VisitAll__VisitorDesc_VisitProcedure((OOC_IR_VisitAll__Visitor)i0, (OOC_IR__Procedure)i1);
  *(OOC_INT32*)(_check_pointer(i0, 3368)) = 0;
  return;
  ;
}

void OOC_SSA_WriteC__VisitorDesc_VisitVar(OOC_SSA_WriteC__Visitor v, OOC_IR__Var var) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_SymbolTable__ProcDecl proc;

  i0 = (OOC_INT32)var;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3519))+8);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3519))+8);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3525)))), OOC_SymbolTable__ItemDesc_Procedure)),OOC_SymbolTable__ItemDesc_Procedure)((OOC_SymbolTable__Item)i2);
  proc = (OOC_SymbolTable__ProcDecl)i1;
  i2 = (OOC_INT32)v;
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 3556));
  i3 = i1!=i3;
  if (!i3) goto l4;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 3588))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3614))+8);
  ADT_Dictionary__DictionaryDesc_Set((ADT_Dictionary__Dictionary)i2, (Object__Object)i0, (Object__Object)i1);
l4:
  return;
  ;
}

static OOC_INT8 OOC_SSA_WriteC__SubclassToBasicType(OOC_SSA__Result res) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)res;
  i0 = *(OOC_INT8*)((_check_pointer(i0, 3783))+5);
  i0 = OOC_SSA_Allocator__SubclassToBasicType(i0);
  return i0;
  ;
}

static OOC_SSA_WriteC__Writer OOC_SSA_WriteC__NewWriter(OOC_SSA_WriteC__Translator translator, OOC_C_DeclWriter__Writer cWriter, OOC_SSA__ProcBlock procBlock, ADT_Dictionary__Dictionary registerMap, ADT_Dictionary__Dictionary jmpbufMap) {
  register OOC_INT32 i0,i1;
  OOC_SSA_WriteC__Writer w;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_SSA_WriteC__Writer.baseTypes[0]);
  w = (OOC_SSA_WriteC__Writer)i0;
  i1 = (OOC_INT32)cWriter;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4095)))), OOC_C_DeclWriter__WriterDesc_CopyTo)),OOC_C_DeclWriter__WriterDesc_CopyTo)((OOC_C_DeclWriter__Writer)i1, (OOC_C_DeclWriter__Writer)i0);
  i1 = (OOC_INT32)procBlock;
  *(OOC_INT32*)((_check_pointer(i0, 4114))+104) = i1;
  i1 = (OOC_INT32)registerMap;
  *(OOC_INT32*)((_check_pointer(i0, 4145))+96) = i1;
  i1 = (OOC_INT32)jmpbufMap;
  *(OOC_INT32*)((_check_pointer(i0, 4180))+100) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 4216))+108) = ((OOC_INT32)RT0__NewObject(_td_OOC_SSA_WriteC__SwapArray.baseTypes[0], 8));
  *(OOC_INT32*)((_check_pointer(i0, 4238))+112) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 4267))+116) = 0;
  i1 = (OOC_INT32)translator;
  *(OOC_INT32*)((_check_pointer(i0, 4295))+92) = i1;
  return (OOC_SSA_WriteC__Writer)i0;
  ;
}

void OOC_SSA_WriteC__WriterDesc_ClearSwapData(OOC_SSA_WriteC__Writer w) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)w;
  *(OOC_INT32*)((_check_pointer(i0, 4404))+112) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 4433))+116) = 0;
  return;
  ;
}

void OOC_SSA_WriteC__WriterDesc_AddSwapData(OOC_SSA_WriteC__Writer w, Object__String source, Object__String dest, OOC_INT8 ctype) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9;
  OOC_SSA_WriteC__SwapArray _new;
  OOC_INT32 i;

  i0 = (OOC_INT32)source;
  i1 = (OOC_INT32)dest;
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4666)))), Object__StringDesc_Equals)),Object__StringDesc_Equals)((Object__String)i0, (Object__Object)i1);
  i2 = !i2;
  if (!i2) goto l14;
  i2 = (OOC_INT32)w;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 4758))+108);
  i4 = *(OOC_INT32*)((_check_pointer(i2, 4732))+112);
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 4769)), 0);
  i3 = i4==i3;
  if (!i3) goto l13;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 4802))+108);
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 4813)), 0);
  i3 = (OOC_INT32)RT0__NewObject(_td_OOC_SSA_WriteC__SwapArray.baseTypes[0], (i3*2));
  _new = (OOC_SSA_WriteC__SwapArray)i3;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 4848))+108);
  i = 0;
  i4 = OOC_ARRAY_LENGTH((_check_pointer(i4, 4859)), 0);
  i5 = 0<i4;
  if (!i5) goto l12;
  i5=0;
l7_loop:
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 4888))+108);
  i6 = _check_pointer(i6, 4899);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i8 = _check_pointer(i3, 4880);
  i9 = OOC_ARRAY_LENGTH(i8, 0);
  _copy_block((i6+((_check_index(i5, i7, OOC_UINT32, 4899))*16)),(i8+((_check_index(i5, i9, OOC_UINT32, 4880))*16)),16);
  i5 = i5+1;
  i = i5;
  i6 = i5<i4;
  if (i6) goto l7_loop;
l12:
  *(OOC_INT32*)((_check_pointer(i2, 4925))+108) = i3;
l13:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 4962))+108);
  i3 = _check_pointer(i3, 4973);
  i4 = *(OOC_INT32*)((_check_pointer(i2, 4975))+112);
  i5 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)(i3+((_check_index(i4, i5, OOC_UINT32, 4973))*16)) = i0;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 5020))+108);
  i0 = _check_pointer(i0, 5031);
  i3 = *(OOC_INT32*)((_check_pointer(i2, 5033))+112);
  i4 = OOC_ARRAY_LENGTH(i0, 0);
  *(OOC_INT32*)((i0+((_check_index(i3, i4, OOC_UINT32, 5031))*16))+4) = i1;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 5074))+108);
  i0 = _check_pointer(i0, 5085);
  i1 = *(OOC_INT32*)((_check_pointer(i2, 5087))+112);
  i3 = OOC_ARRAY_LENGTH(i0, 0);
  i4 = ctype;
  *(OOC_INT8*)((i0+((_check_index(i1, i3, OOC_UINT32, 5085))*16))+12) = i4;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 5130))+108);
  i0 = _check_pointer(i0, 5141);
  i1 = *(OOC_INT32*)((_check_pointer(i2, 5143))+112);
  i3 = OOC_ARRAY_LENGTH(i0, 0);
  *(OOC_INT32*)((i0+((_check_index(i1, i3, OOC_UINT32, 5141))*16))+8) = 0;
  i0 = *(OOC_INT32*)((_check_pointer(i2, 5191))+112);
  *(OOC_INT32*)((_check_pointer(i2, 5191))+112) = (i0+1);
l14:
  return;
  ;
}

void OOC_SSA_WriteC__WriterDesc_CountReadsSwapData(OOC_SSA_WriteC__Writer w) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10;
  OOC_INT32 i;
  OOC_INT32 c;
  OOC_INT32 j;

  i0 = (OOC_INT32)w;
  i = 0;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 5336))+112);
  i2 = 0<i1;
  if (!i2) goto l21;
  i2=0;
l3_loop:
  c = 0;
  i3 = *(OOC_INT32*)((_check_pointer(i0, 5394))+112);
  j = 0;
  i4 = 0<i3;
  if (i4) goto l6;
  i3=0;
  goto l16;
l6:
  i4=0;i5=0;
l7_loop:
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5429))+108);
  i6 = _check_pointer(i6, 5440);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+((_check_index(i4, i7, OOC_UINT32, 5440))*16));
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5429))+108);
  i7 = _check_pointer(i7, 5440);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5461))+108);
  i9 = _check_pointer(i9, 5472);
  i10 = OOC_ARRAY_LENGTH(i9, 0);
  i9 = (OOC_INT32)*(OOC_INT32*)((i9+((_check_index(i2, i10, OOC_UINT32, 5472))*16))+4);
  i7 = (OOC_INT32)*(OOC_INT32*)(i7+((_check_index(i4, i8, OOC_UINT32, 5440))*16));
  i6 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 5451)))), Object__StringDesc_Equals)),Object__StringDesc_Equals)((Object__String)i7, (Object__Object)i9);
  if (!i6) goto l11;
  i5 = i5+1;
  c = i5;
  
l11:
  i4 = i4+1;
  j = i4;
  i6 = i4<i3;
  if (i6) goto l7_loop;
l15:
  i3=i5;
l16:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5537))+108);
  i4 = _check_pointer(i4, 5548);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  *(OOC_INT32*)((i4+((_check_index(i2, i5, OOC_UINT32, 5548))*16))+8) = i3;
  i2 = i2+1;
  i = i2;
  i3 = i2<i1;
  if (i3) goto l3_loop;
l21:
  return;
  ;
}

void OOC_SSA_WriteC__WriterDesc_RemoveSwapData(OOC_SSA_WriteC__Writer w, OOC_INT32 i) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
  OOC_INT32 j;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5698))+108);
  i1 = _check_pointer(i1, 5709);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i3 = i;
  i1 = *(OOC_INT32*)((i1+((_check_index(i3, i2, OOC_UINT32, 5709))*16))+8);
  _assert((i1==0), 127, 5689);
  i1 = *(OOC_INT32*)((_check_pointer(i0, 5749))+112);
  j = 0;
  i2 = 0<i1;
  if (!i2) goto l11;
  i2=0;
l3_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5782))+108);
  i4 = _check_pointer(i4, 5793);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((i4+((_check_index(i2, i5, OOC_UINT32, 5793))*16))+4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5782))+108);
  i5 = _check_pointer(i5, 5793);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5812))+108);
  i7 = _check_pointer(i7, 5823);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)((i5+((_check_index(i2, i6, OOC_UINT32, 5793))*16))+4);
  i6 = (OOC_INT32)*(OOC_INT32*)(i7+((_check_index(i3, i8, OOC_UINT32, 5823))*16));
  i4 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 5802)))), Object__StringDesc_Equals)),Object__StringDesc_Equals)((Object__String)i5, (Object__Object)i6);
  if (!i4) goto l6;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5855))+108);
  i4 = _check_pointer(i4, 5866);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5855))+108);
  i6 = _check_pointer(i6, 5866);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = *(OOC_INT32*)((i6+((_check_index(i2, i7, OOC_UINT32, 5866))*16))+8);
  *(OOC_INT32*)((i4+((_check_index(i2, i5, OOC_UINT32, 5866))*16))+8) = (i6-1);
l6:
  i2 = i2+1;
  j = i2;
  i4 = i2<i1;
  if (i4) goto l3_loop;
l11:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5926))+108);
  i1 = _check_pointer(i1, 5937);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 5939))+112);
  i4 = OOC_ARRAY_LENGTH(i1, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5907))+108);
  i5 = _check_pointer(i5, 5918);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  _copy_block((i1+((_check_index((i2-1), i4, OOC_UINT32, 5937))*16)),(i5+((_check_index(i3, i6, OOC_UINT32, 5918))*16)),16);
  i1 = *(OOC_INT32*)((_check_pointer(i0, 5971))+112);
  *(OOC_INT32*)((_check_pointer(i0, 5971))+112) = (i1-1);
  return;
  ;
}

void OOC_SSA_WriteC__WriterDesc_IntroduceHelperVar(OOC_SSA_WriteC__Writer w, OOC_INT32 i) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9;
  OOC_CHAR8 str[16];
  Object__String h;
  OOC_INT32 j;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6154))+108);
  i1 = _check_pointer(i1, 6165);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i3 = i;
  i1 = *(OOC_INT32*)((i1+((_check_index(i3, i2, OOC_UINT32, 6165))*16))+8);
  _assert((i1!=0), 127, 6145);
  i1 = *(OOC_INT32*)((_check_pointer(i0, 6208))+116);
  IntStr__IntToStr(i1, (void*)(OOC_INT32)str, 16);
  Strings__Insert("h", 2, 0, (void*)(OOC_INT32)str, 16);
  i1 = (OOC_INT32)Object__NewLatin1((void*)(OOC_INT32)str, 16);
  h = (Object__String)i1;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 6308))+116);
  *(OOC_INT32*)((_check_pointer(i0, 6308))+116) = (i2+1);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 6351))+112);
  j = 0;
  i4 = 0<i2;
  if (!i4) goto l11;
  i4=0;
l3_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6384))+108);
  i5 = _check_pointer(i5, 6395);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+((_check_index(i4, i6, OOC_UINT32, 6395))*16));
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6384))+108);
  i6 = _check_pointer(i6, 6395);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6416))+108);
  i8 = _check_pointer(i8, 6427);
  i9 = OOC_ARRAY_LENGTH(i8, 0);
  i8 = (OOC_INT32)*(OOC_INT32*)((i8+((_check_index(i3, i9, OOC_UINT32, 6427))*16))+4);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+((_check_index(i4, i7, OOC_UINT32, 6395))*16));
  i5 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 6406)))), Object__StringDesc_Equals)),Object__StringDesc_Equals)((Object__String)i6, (Object__Object)i8);
  if (!i5) goto l6;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6452))+108);
  i5 = _check_pointer(i5, 6463);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  *(OOC_INT32*)(i5+((_check_index(i4, i6, OOC_UINT32, 6463))*16)) = i1;
l6:
  i4 = i4+1;
  j = i4;
  i5 = i4<i2;
  if (i5) goto l3_loop;
l11:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6506))+108);
  i2 = _check_pointer(i2, 6517);
  i4 = OOC_ARRAY_LENGTH(i2, 0);
  *(OOC_INT32*)((i2+((_check_index(i3, i4, OOC_UINT32, 6517))*16))+8) = 0;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6544)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "{register ", 11);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6632))+108);
  i2 = _check_pointer(i2, 6643);
  i4 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = *(OOC_INT8*)((i2+((_check_index(i3, i4, OOC_UINT32, 6643))*16))+12);
  i2 = OOC_SSA_Allocator__RegisterType(i2);
  i2 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i0, 6595))+24)+(_check_index(i2, 17, OOC_UINT8, 6606))*4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6579)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, (void*)((_check_pointer(i2, 6655))+1), 32);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6669)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, " ", 2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6695)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i0, (Object__Object)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6719)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i0, 61u);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6759))+108);
  i1 = _check_pointer(i1, 6770);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)((i1+((_check_index(i3, i2, OOC_UINT32, 6770))*16))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6743)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i0, (Object__Object)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6787)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i0, 59u);
  return;
  ;
}

void OOC_SSA_WriteC__WriterDesc_FixupHelperVars(OOC_SSA_WriteC__Writer w) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)w;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 6892))+116);
  i1 = i1!=0;
  if (!i1) goto l8;
l3_loop:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6924)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i0, 125u);
  i1 = *(OOC_INT32*)((_check_pointer(i0, 6955))+116);
  *(OOC_INT32*)((_check_pointer(i0, 6955))+116) = (i1-1);
  i1 = *(OOC_INT32*)((_check_pointer(i0, 6892))+116);
  i1 = i1!=0;
  if (i1) goto l3_loop;
l8:
  return;
  ;
}

static void OOC_SSA_WriteC__Fixup(OOC_SSA__ProcBlock pb, ADT_Dictionary__Dictionary *jmpbufMap) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_SSA__Instr instr;
  OOC_SSA__Instr next;
  OOC_CHAR8 num[16];
  OOC_INT8 regDest;
  OOC_INT8 regSource;

  *jmpbufMap = (ADT_Dictionary__Dictionary)(OOC_INT32)0;
  i0 = (OOC_INT32)pb;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7235))+12);
  instr = (OOC_SSA__Instr)i1;
  i2 = i1!=(OOC_INT32)0;
  if (!i2) goto l24;
  i2=(OOC_INT32)0;
l3_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 7294))+28);
  next = (OOC_SSA__Instr)i3;
  i4 = *(OOC_INT8*)((_check_pointer(i1, 7322))+36);
  switch (i4) {
  case 55:
    i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 7372))+24);
    i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 7382));
    i4 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 7388)))), &_td_OOC_SSA__AddressDesc);
    if (!i4) goto l8;
    i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 7766))+24);
    i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 7776));
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 7707))+24);
    i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 7786)))), &_td_OOC_SSA__AddressDesc, 7786)), 7794))+44);
    i4 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetDeclRef((OOC_SSA__ProcBlock)i0, (OOC_SymbolTable__Declaration)i4);
    OOC_SSA__OpndDesc_ReplaceArg((OOC_SSA__Opnd)i1, (OOC_SSA__Result)i4);
l8:
    i1=i2;
    goto l19;
  case 72:
    i4 = i2==(OOC_INT32)0;
    if (!i4) goto l13;
    i2 = (OOC_INT32)ADT_Dictionary__New();
    *jmpbufMap = (ADT_Dictionary__Dictionary)i2;
    
l13:
    i4 = ADT_Dictionary__DictionaryDesc_Size((ADT_Dictionary__Dictionary)i2);
    IntStr__IntToStr(i4, (void*)(OOC_INT32)num, 16);
    i4 = (OOC_INT32)Object__NewLatin1((void*)(OOC_INT32)num, 16);
    ADT_Dictionary__DictionaryDesc_Set((ADT_Dictionary__Dictionary)i2, (Object__Object)i1, (Object__Object)i4);
    i1=i2;
    goto l19;
  case 42:
    i4 = *(OOC_INT8*)((_check_pointer(i1, 8148))+5);
    i4 = OOC_SSA_Allocator__SubclassToBasicType(i4);
    i4 = OOC_SSA_Allocator__RegisterType(i4);
    regDest = i4;
    i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 8253))+24);
    i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 8262));
    i5 = *(OOC_INT8*)((_check_pointer(i5, 8266))+5);
    i5 = OOC_SSA_Allocator__SubclassToBasicType(i5);
    i5 = OOC_SSA_Allocator__RegisterType(i5);
    regSource = i5;
    i4 = i4==i5;
    if (!i4) goto l17;
    i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 8339));
    _assert((i4==(OOC_INT32)0), 127, 8327);
    i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 8392))+24);
    i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 8401));
    OOC_SSA__ResultDesc_ReplaceUses((OOC_SSA__Result)i1, (OOC_SSA__Result)i4);
    OOC_SSA__ProcBlockDesc_DeleteInstr((OOC_SSA__ProcBlock)i0, (OOC_SSA__Instr)i1);
l17:
    i1=i2;
    goto l19;
  default:
    i1=i2;
    goto l19;
  }
l19:
  instr = (OOC_SSA__Instr)i3;
  i2 = i3!=(OOC_INT32)0;
  if (!i2) goto l24;
  i2=i1;i1=i3;
  goto l3_loop;
l24:
  return;
  ;
}

static void OOC_SSA_WriteC__WriteTypeCast(OOC_C_DeclWriter__Writer w, OOC_INT8 ctype) {
  register OOC_INT32 i0,i1;
  OOC_INT8 rtype;

  i0 = ctype;
  i1 = OOC_SSA_Allocator__RegisterType(i0);
  rtype = i1;
  i0 = i1!=i0;
  if (!i0) goto l4;
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8749)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i0, 40u);
  i1 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i0, 8791))+24)+(_check_index(i1, 17, OOC_UINT8, 8802))*4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8775)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, (void*)((_check_pointer(i1, 8809))+1), 32);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8825)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i0, 41u);
l4:
  return;
  ;
}

static void OOC_SSA_WriteC__WriteTypeAndLength(OOC_SSA_WriteC__Writer w, OOC_SSA__Instr instr, OOC_SymbolTable__VarDecl varDecl, OOC_CHAR8 inBytes) {
  register OOC_INT32 i0,i1,i2;
  OOC_SymbolTable__Type type;

  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9141)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ",", 2);
  i1 = (OOC_INT32)varDecl;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 9181))+48);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 9181))+48);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 9186)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i1);
  type = (OOC_SymbolTable__Type)i1;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9212)))), &_td_OOC_SymbolTable__ArrayDesc);
  if (i2) goto l3;
  OOC_SSA_WriteC__WriterDesc_TypeRef((OOC_SSA_WriteC__Writer)i0, (OOC_SymbolTable__Type)i1);
  goto l4;
l3:
  i1 = (OOC_INT32)OOC_SymbolTable__ArrayDesc_GetInnermostElementType((OOC_SymbolTable__Array)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9256)))), &_td_OOC_SymbolTable__ArrayDesc, 9256)));
  OOC_SSA_WriteC__WriterDesc_TypeRef((OOC_SSA_WriteC__Writer)i0, (OOC_SymbolTable__Type)i1);
l4:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9337)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ",", 2);
  i1 = inBytes;
  if (i1) goto l7;
  i1 = (OOC_INT32)instr;
  i1 = (OOC_INT32)OOC_SSA__InstrDesc_NthOpnd((OOC_SSA__Instr)i1, 1);
  OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i0, (OOC_SSA__Opnd)i1);
  goto l8;
l7:
  i1 = (OOC_INT32)instr;
  i1 = (OOC_INT32)OOC_SSA__InstrDesc_NthOpnd((OOC_SSA__Instr)i1, 2);
  OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i0, (OOC_SSA__Opnd)i1);
l8:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9463)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ")", 2);
  return;
  ;
}

static void OOC_SSA_WriteC__WriteLocalDecl(OOC_SSA_WriteC__Translator t, OOC_SSA_WriteC__Writer w, OOC_SSA__ProcBlock pb, OOC_CHAR8 _volatile) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  ADT_Dictionary__Dictionary declMap;
  OOC_SSA__Instr instr;
  OOC_SymbolTable__VarDecl decl;
  Object__String name;
  OOC_C_DeclWriter__Declaration cDecl;
  OOC_SymbolTable__Item item;
  auto OOC_SymbolTable__VarDecl OOC_SSA_WriteC__WriteLocalDecl_GetLocalDecl(OOC_SSA__Instr instr);
    
    OOC_SymbolTable__VarDecl OOC_SSA_WriteC__WriteLocalDecl_GetLocalDecl(OOC_SSA__Instr instr) {
      register OOC_INT32 i0,i1,i2;
      OOC_SSA__Opnd opnd;
      OOC_SymbolTable__VarDecl varDecl;

      i0 = (OOC_INT32)instr;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10017)))), &_td_OOC_SSA__AddressDesc);
      if (i1) goto l34;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10316))+24);
      opnd = (OOC_SSA__Opnd)i0;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l5;
      i1=0u;
      goto l11;
l5:
      i1 = *(OOC_INT8*)((_check_pointer(i0, 10377))+4);
      i1 = i1!=5;
      if (i1) goto l8;
      i1=0u;
      goto l11;
l8:
      i1 = *(OOC_INT8*)((_check_pointer(i0, 10426))+4);
      i1 = i1!=7;
      
l11:
      if (!i1) goto l27;
l14_loop:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10480))+8);
      opnd = (OOC_SSA__Opnd)i0;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l17;
      i1=0u;
      goto l23;
l17:
      i1 = *(OOC_INT8*)((_check_pointer(i0, 10377))+4);
      i1 = i1!=5;
      if (i1) goto l20;
      i1=0u;
      goto l23;
l20:
      i1 = *(OOC_INT8*)((_check_pointer(i0, 10426))+4);
      i1 = i1!=7;
      
l23:
      if (i1) goto l14_loop;
l27:
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 10521));
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 10527)))), &_td_OOC_SSA__DeclRefDesc);
      if (!i1) goto l33;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 10573));
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10583)))), &_td_OOC_SSA__DeclRefDesc, 10583)), 10591))+44);
      i0 = _type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10602)))), &_td_OOC_SymbolTable__VarDeclDesc, 10602);
      varDecl = (OOC_SymbolTable__VarDecl)i0;
      i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10633)))), OOC_SymbolTable__ItemDesc_Procedure)),OOC_SymbolTable__ItemDesc_Procedure)((OOC_SymbolTable__Item)i0);
      i2 = (OOC_INT32)pb;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 10651))+20);
      i1 = i1==i2;
      if (!i1) goto l33;
      return (OOC_SymbolTable__VarDecl)i0;
l33:
      return (OOC_SymbolTable__VarDecl)(OOC_INT32)0;
      goto l43;
l34:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10097))+44);
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 10104)))), &_td_OOC_SymbolTable__VarDeclDesc);
      if (i1) goto l37;
      i1=0u;
      goto l39;
l37:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10139))+44);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10139))+44);
      i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 10150)))), &_td_OOC_SymbolTable__VarDeclDesc, 10150)), 10158)))), OOC_SymbolTable__ItemDesc_Procedure)),OOC_SymbolTable__ItemDesc_Procedure)((OOC_SymbolTable__Item)(_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 10150)))), &_td_OOC_SymbolTable__VarDeclDesc, 10150)));
      i2 = (OOC_INT32)pb;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 10176))+20);
      i1 = i1==i2;
      
l39:
      if (i1) goto l41;
      return (OOC_SymbolTable__VarDecl)(OOC_INT32)0;
      goto l43;
l41:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10215))+44);
      return (OOC_SymbolTable__VarDecl)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10226)))), &_td_OOC_SymbolTable__VarDeclDesc, 10226));
l43:
      _failed_function(9887); return 0;
      ;
    }


  i0 = (OOC_INT32)ADT_Dictionary__New();
  declMap = (ADT_Dictionary__Dictionary)i0;
  i0 = (OOC_INT32)pb;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10834))+12);
  instr = (OOC_SSA__Instr)i0;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l40;
l3_loop:
  i1 = *(OOC_INT8*)((_check_pointer(i0, 10889))+36);
  i1 = i1==12;
  if (i1) goto l6;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 10930))+36);
  i1 = i1==13;
  
  goto l8;
l6:
  i1=1u;
l8:
  if (i1) goto l10;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 10971))+36);
  i1 = i1==58;
  
  goto l12;
l10:
  i1=1u;
l12:
  if (i1) goto l14;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 11022))+36);
  i1 = i1==3;
  
  goto l16;
l14:
  i1=1u;
l16:
  if (!i1) goto l35;
  i0 = (OOC_INT32)OOC_SSA_WriteC__WriteLocalDecl_GetLocalDecl((OOC_SSA__Instr)i0);
  decl = (OOC_SymbolTable__VarDecl)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l20;
  i1=0u;
  goto l22;
l20:
  i1 = (OOC_INT32)declMap;
  i1 = ADT_Dictionary__DictionaryDesc_HasKey((ADT_Dictionary__Dictionary)i1, (Object__Object)i0);
  i1 = !i1;
  
l22:
  if (!i1) goto l35;
  i1 = (OOC_INT32)instr;
  i2 = *(OOC_INT8*)((_check_pointer(i1, 11166))+36);
  i2 = i2==58;
  if (i2) goto l32;
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 11442))+56);
  i1 = !i1;
  if (!i1) goto l35;
  i1 = (OOC_INT32)w;
  i2 = (OOC_INT32)OOC_C_ConvertDecl__GetDecl((OOC_C_DeclWriter__Writer)i1, (OOC_SymbolTable__Declaration)i0);
  cDecl = (OOC_C_DeclWriter__Declaration)i2;
  i3 = _volatile;
  if (!i3) goto l30;
  OOC_C_DeclWriter__DeclarationDesc_SetTypeQualifier((OOC_C_DeclWriter__Declaration)i2, 2);
l30:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 11633)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 11657)))), OOC_C_DeclWriter__WriterDesc_WriteDeclaration)),OOC_C_DeclWriter__WriterDesc_WriteDeclaration)((OOC_C_DeclWriter__Writer)i1, (OOC_C_DeclWriter__Declaration)i2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 11698)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 59u);
  i1 = (OOC_INT32)declMap;
  ADT_Dictionary__DictionaryDesc_Set((ADT_Dictionary__Dictionary)i1, (Object__Object)i0, (Object__Object)(OOC_INT32)0);
  goto l35;
l32:
  i2 = (OOC_INT32)OOC_C_Naming__NameOfDeclaration((OOC_SymbolTable__Declaration)i0);
  name = (Object__String)i2;
  i3 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 11269)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i3);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 11293)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i3, "OOC_ALLOCATE_VPAR(", 19);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 11344)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i3, (Object__Object)i2);
  OOC_SSA_WriteC__WriteTypeAndLength((OOC_SSA_WriteC__Writer)i3, (OOC_SSA__Instr)i1, (OOC_SymbolTable__VarDecl)i0, 0u);
l35:
  i0 = (OOC_INT32)instr;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11813))+28);
  instr = (OOC_SSA__Instr)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l3_loop;
l40:
  i0 = (OOC_INT32)pb;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12022))+20);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12032))+8);
  item = (OOC_SymbolTable__Item)i1;
  i2 = i1!=(OOC_INT32)0;
  if (!i2) goto l62;
  i2 = (OOC_INT32)t;
  i3 = (OOC_INT32)w;
  i4 = (OOC_INT32)declMap;
  
l43_loop:
  i5 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 12088)))), &_td_OOC_SymbolTable__VarDeclDesc);
  if (!i5) goto l57;
  i5 = *(OOC_UINT8*)((_check_pointer(i1, 12121))+56);
  i5 = !i5;
  if (i5) goto l48;
  i5=0u;
  goto l50;
l48:
  i5 = ADT_Dictionary__DictionaryDesc_HasKey((ADT_Dictionary__Dictionary)i4, (Object__Object)i1);
  i5 = !i5;
  
l50:
  if (i5) goto l52;
  i5=0u;
  goto l54;
l52:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 12186))+32);
  i5 = ADT_Dictionary__DictionaryDesc_HasKey((ADT_Dictionary__Dictionary)i5, (Object__Object)i1);
  
l54:
  if (!i5) goto l57;
  i5 = (OOC_INT32)OOC_C_ConvertDecl__GetDecl((OOC_C_DeclWriter__Writer)i3, (OOC_SymbolTable__Declaration)i1);
  cDecl = (OOC_C_DeclWriter__Declaration)i5;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 12284)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i3);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 12306)))), OOC_C_DeclWriter__WriterDesc_WriteDeclaration)),OOC_C_DeclWriter__WriterDesc_WriteDeclaration)((OOC_C_DeclWriter__Writer)i3, (OOC_C_DeclWriter__Declaration)i5);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 12345)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i3, 59u);
  ADT_Dictionary__DictionaryDesc_Set((ADT_Dictionary__Dictionary)i4, (Object__Object)i1, (Object__Object)(OOC_INT32)0);
l57:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 12494));
  item = (OOC_SymbolTable__Item)i1;
  i5 = i1!=(OOC_INT32)0;
  if (i5) goto l43_loop;
l62:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12638))+20);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12648))+8);
  item = (OOC_SymbolTable__Item)i0;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l73;
  i1 = (OOC_INT32)declMap;
  i2 = (OOC_INT32)w;
  
l65_loop:
  i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12704)))), &_td_OOC_SymbolTable__ProcDeclDesc);
  if (!i3) goto l68;
  i3 = (OOC_INT32)OOC_C_ConvertDecl__GetProc((OOC_C_DeclWriter__Writer)i2, (OOC_SymbolTable__ProcDecl)i0, 1u);
  cDecl = (OOC_C_DeclWriter__Declaration)i3;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 12785)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 12805)))), OOC_C_DeclWriter__WriterDesc_WriteDeclaration)),OOC_C_DeclWriter__WriterDesc_WriteDeclaration)((OOC_C_DeclWriter__Writer)i2, (OOC_C_DeclWriter__Declaration)i3);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 12842)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i2, 59u);
  ADT_Dictionary__DictionaryDesc_Set((ADT_Dictionary__Dictionary)i1, (Object__Object)i0, (Object__Object)(OOC_INT32)0);
l68:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 12976));
  item = (OOC_SymbolTable__Item)i0;
  i3 = i0!=(OOC_INT32)0;
  if (i3) goto l65_loop;
l73:
  return;
  ;
}

void OOC_SSA_WriteC__WriterDesc_LengthExprHeap(OOC_SSA_WriteC__Writer w, OOC_SSA__Instr instr) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13093)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "OOC_ARRAY_LENGTH(", 18);
  i1 = (OOC_INT32)instr;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 13147))+24);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 13157))+8);
  OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i0, (OOC_SSA__Opnd)i2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13175)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ", ", 3);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 13214))+24);
  OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i0, (OOC_SSA__Opnd)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13232)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ")", 2);
  return;
  ;
}

void OOC_SSA_WriteC__WriterDesc_LengthExprParam(OOC_SSA_WriteC__Writer w, OOC_SSA__Instr instr) {
  register OOC_INT32 i0,i1;
  OOC_SSA__Result design;
  Object__String name;

  i0 = (OOC_INT32)instr;
  i1 = (OOC_INT32)OOC_SSA__InstrDesc_GetArgClass((OOC_SSA__Instr)i0, 5);
  design = (OOC_SSA__Result)i1;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 13499)))), &_td_OOC_SSA__DeclRefDesc, 13499)), 13507))+44);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13533))+24);
  i0 = OOC_SSA__OpndDesc_GetIntConst((OOC_SSA__Opnd)i0);
  i0 = (OOC_INT32)OOC_C_Naming__NameOfLengthParam((OOC_SymbolTable__VarDecl)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 13518)))), &_td_OOC_SymbolTable__VarDeclDesc, 13518)), i0);
  name = (Object__String)i0;
  i1 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 13566)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i1, (Object__Object)i0);
  return;
  ;
}

void OOC_SSA_WriteC__WriterDesc_Ref(OOC_SSA_WriteC__Writer w, OOC_SSA__Opnd opnd) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_SSA__Result arg;
  Object__String name;
  OOC_INT8 bt;
  OOC_SSA__Instr instr;
  Object__Object obj;

  i0 = (OOC_INT32)opnd;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 13856));
  arg = (OOC_SSA__Result)i1;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 13875)))), &_td_OOC_SSA__DeclRefDesc);
  if (i2) goto l50;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14388)))), &_td_OOC_SSA__ConstDesc);
  if (i2) goto l40;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15119)))), &_td_OOC_SSA__AddressDesc);
  if (i2) goto l23;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 15717));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 15722))+8);
  instr = (OOC_SSA__Instr)i1;
  i2 = (OOC_INT32)w;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 15741))+96);
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 15768));
  i3 = ADT_Dictionary__DictionaryDesc_HasKey((ADT_Dictionary__Dictionary)i3, (Object__Object)i4);
  if (i3) goto l17;
  i0 = *(OOC_INT8*)((_check_pointer(i1, 16054))+36);
  i0 = i0==57;
  if (i0) goto l15;
  i0 = *(OOC_INT8*)((_check_pointer(i1, 16156))+36);
  i0 = i0==72;
  if (i0) goto l13;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 16409)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i2, "XXX undefined ref /*internal error*/", 37);
  goto l62;
l13:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 16197)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i2, "setjmp(_target", 15);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 16245))+100);
  i0 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i0, (Object__Object)i1);
  obj = (Object__Object)i0;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 16277)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i2, (Object__Object)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 16305)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i2, ")", 2);
  goto l62;
l15:
  OOC_SSA_WriteC__WriterDesc_LengthExprParam((OOC_SSA_WriteC__Writer)i2, (OOC_SSA__Instr)i1);
  goto l62;
l17:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 15796))+96);
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 15820));
  i1 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i1, (Object__Object)i3);
  obj = (Object__Object)i1;
  i3 = (OOC_INT32)OOC_SSA_Allocator__markInPlace;
  i3 = i1==i3;
  if (i3) goto l20;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 16001)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i2, (Object__Object)i1);
  goto l62;
l20:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 15885)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i2, 40u);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 15932));
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15937))+8);
  OOC_SSA_WriteC__WriteExpr((OOC_SSA_WriteC__Writer)i2, (OOC_SSA__Instr)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 15958)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i2, 41u);
  goto l62;
l23:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 15179))+44);
  i0 = (OOC_INT32)OOC_C_Naming__NameOfDeclaration((OOC_SymbolTable__Declaration)i0);
  name = (Object__String)i0;
  i2 = (OOC_INT32)w;
  OOC_SSA_WriteC__WriteTypeCast((OOC_C_DeclWriter__Writer)i2, 1);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 15245))+44);
  i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 15252)))), &_td_OOC_SymbolTable__VarDeclDesc);
  if (i3) goto l26;
  i3=0u;
  goto l28;
l26:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 15286))+44);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 15297)))), &_td_OOC_SymbolTable__VarDeclDesc, 15297)), 15305))+48);
  i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 15312)))), &_td_OOC_SymbolTable__ArrayDesc);
  
l28:
  if (i3) goto l34;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 15346))+44);
  i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 15353)))), &_td_OOC_SymbolTable__VarDeclDesc);
  if (i3) goto l32;
  i1=0u;
  goto l35;
l32:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 15386))+44);
  i1 = *(OOC_UINT8*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15397)))), &_td_OOC_SymbolTable__VarDeclDesc, 15397)), 15405))+60);
  
  goto l35;
l34:
  i1=1u;
l35:
  i1 = !i1;
  if (!i1) goto l38;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 15623)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i2, 38u);
l38:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 15660)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i2, (Object__Object)i0);
  goto l62;
l40:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14579))+44);
  i2 = (OOC_INT32)OOC_SSA__nil;
  i0 = i0==i2;
  if (i0) goto l47;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14899))+48);
  i0 = i0!=0;
  if (i0) goto l45;
  i0 = (OOC_INT32)w;
  i2 = *(OOC_INT8*)((_check_pointer(i1, 15085))+5);
  i2 = OOC_SSA_Allocator__SubclassToBasicType(i2);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 15018))+44);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14998)))), OOC_C_DeclWriter__WriterDesc_WriteBasicConst)),OOC_C_DeclWriter__WriterDesc_WriteBasicConst)((OOC_C_DeclWriter__Writer)i0, (Object_Boxed__Object)i1, i2);
  goto l62;
l45:
  i0 = (OOC_INT32)w;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14953))+44);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14964))+48);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14932)))), OOC_C_DeclWriter__WriterDesc_WriteStringConst)),OOC_C_DeclWriter__WriterDesc_WriteStringConst)((OOC_C_DeclWriter__Writer)i0, (Object_Boxed__Object)i2, (OOC_SymbolTable__Type)i1);
  goto l62;
l47:
  bt = 4;
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14755)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "(", 2);
  i1 = bt;
  i1 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i0, 14801))+24)+(_check_index(i1, 17, OOC_UINT8, 14812))*4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14785)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, (void*)((_check_pointer(i1, 14816))+1), 32);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14834)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ")", 2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14864)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "0", 2);
  goto l62;
l50:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14039))+44);
  i0 = (OOC_INT32)OOC_C_Naming__NameOfDeclaration((OOC_SymbolTable__Declaration)i0);
  name = (Object__String)i0;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14061))+44);
  i3 = (OOC_INT32)w;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 14068)))), &_td_OOC_SymbolTable__VarDeclDesc);
  if (i2) goto l53;
  i2=0u;
  goto l55;
l53:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14098))+44);
  i2 = *(OOC_UINT8*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 14109)))), &_td_OOC_SymbolTable__VarDeclDesc, 14109)), 14117))+60);
  
l55:
  if (i2) goto l57;
  i1=0u;
  goto l59;
l57:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14154))+44);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14165)))), &_td_OOC_SymbolTable__VarDeclDesc, 14165)), 14173))+48);
  i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14180)))), &_td_OOC_SymbolTable__ArrayDesc));
  
l59:
  if (!i1) goto l61;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 14319)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i3, "*", 2);
l61:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 14357)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i3, (Object__Object)i0);
l62:
  return;
  ;
}

void OOC_SSA_WriteC__WriterDesc_TypeRef(OOC_SSA_WriteC__Writer w, OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1;
  OOC_C_DeclWriter__Type cType;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)type;
  i1 = (OOC_INT32)OOC_C_ConvertDecl__GetTypeRef((OOC_C_DeclWriter__Writer)i0, (OOC_SymbolTable__Type)i1);
  cType = (OOC_C_DeclWriter__Type)i1;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16637)))), OOC_C_DeclWriter__WriterDesc_WriteType)),OOC_C_DeclWriter__WriterDesc_WriteType)((OOC_C_DeclWriter__Writer)i0, (OOC_C_DeclWriter__Type)i1);
  return;
  ;
}

OOC_CHAR8 OOC_SSA_WriteC__WriterDesc_Noop(OOC_SSA_WriteC__Writer w, OOC_SSA__Instr instr) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_SSA__Instr targetInstr;
  OOC_SSA__Opnd opnd;
  OOC_SSA__Result res;
  Object__Object targetVar;
  Object__Object sourceVar;

  i0 = (OOC_INT32)instr;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 16869))+36);
  switch (i1) {
  case 0:
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 82:
  case 10:
  case 11:
  case 9:
    return 1u;
    goto l31;
  case 6:
    i1 = (OOC_INT32)OOC_SSA__InstrDesc_GetCollectTarget((OOC_SSA__Instr)i0);
    targetInstr = (OOC_SSA__Instr)i1;
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17209))+24);
    opnd = (OOC_SSA__Opnd)i0;
    i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 17245));
    res = (OOC_SSA__Result)i1;
    i2 = i0!=0;
    if (i2) goto l6;
    i2=0u;
    goto l8;
l6:
    i2 = OOC_SSA__OpndDesc_IsScheduleOpnd((OOC_SSA__Opnd)i0);
    i2 = !i2;
    
l8:
    if (!i2) goto l29;
    i2 = (OOC_INT32)w;
    
l10_loop:
    i3 = *(OOC_INT8*)((_check_pointer(i0, 17329))+4);
    i3 = i3!=2;
    if (!i3) goto l20;
    i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 17380))+96);
    i3 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i3, (Object__Object)i1);
    targetVar = (Object__Object)i3;
    i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 17420))+96);
    i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 17447));
    i4 = ADT_Dictionary__DictionaryDesc_HasKey((ADT_Dictionary__Dictionary)i4, (Object__Object)i5);
    if (i4) goto l15;
    return 0u;
    goto l20;
l15:
    i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 17485))+96);
    i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 17509));
    i4 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i4, (Object__Object)i5);
    sourceVar = (Object__Object)i4;
    i3 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 17542)))), Object__ObjectDesc_Equals)),Object__ObjectDesc_Equals)((Object__Object)i4, (Object__Object)i3);
    i3 = !i3;
    if (!i3) goto l20;
    return 0u;
l20:
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17790))+8);
    opnd = (OOC_SSA__Opnd)i0;
    i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 17812));
    res = (OOC_SSA__Result)i1;
    i3 = i0!=0;
    if (i3) goto l23;
    i3=0u;
    goto l25;
l23:
    i3 = OOC_SSA__OpndDesc_IsScheduleOpnd((OOC_SSA__Opnd)i0);
    i3 = !i3;
    
l25:
    if (i3) goto l10_loop;
l29:
    return 1u;
    goto l31;
  default:
    return 0u;
    goto l31;
  }
l31:
  _failed_function(16697); return 0;
  ;
}

OOC_CHAR8 OOC_SSA_WriteC__WriterDesc_EmptyBlock(OOC_SSA_WriteC__Writer w, OOC_SSA_Schedule__Block b) {
  register OOC_INT32 i0,i1,i2;
  OOC_SSA_Schedule__InstrProxy proxy;

  i0 = (OOC_INT32)b;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18152)))), &_td_OOC_SSA_Schedule__JumpBlockDesc);
  if (i1) goto l3;
  return 0u;
  goto l15;
l3:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18192))+8);
  proxy = (OOC_SSA_Schedule__InstrProxy)i0;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l14;
  i1 = (OOC_INT32)w;
  
l6_loop:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18260))+12);
  i2 = OOC_SSA_WriteC__WriterDesc_Noop((OOC_SSA_WriteC__Writer)i1, (OOC_SSA__Instr)i2);
  i2 = !i2;
  if (!i2) goto l9;
  return 0u;
l9:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 18333));
  proxy = (OOC_SSA_Schedule__InstrProxy)i0;
  i2 = i0!=(OOC_INT32)0;
  if (i2) goto l6_loop;
l14:
  return 1u;
l15:
  _failed_function(17935); return 0;
  ;
}

static void OOC_SSA_WriteC__CastToPtr(OOC_SSA_WriteC__Writer w, OOC_SSA__Result var, OOC_SymbolTable__Type type, OOC_CHAR8 passByReference) {
  register OOC_INT32 i0,i1,i2;
  Object__String name;

  i0 = (OOC_INT32)type;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18594)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  type = (OOC_SymbolTable__Type)i0;
  i1 = (OOC_INT32)var;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 18617))+8);
  i2 = *(OOC_INT8*)((_check_pointer(i2, 18624))+36);
  i2 = i2==61;
  if (i2) goto l41;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18712)))), &_td_OOC_SymbolTable__PointerDesc);
  if (i2) goto l5;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18747)))), &_td_OOC_SymbolTable__FormalParsDesc);
  
  goto l7;
l5:
  i2=1u;
l7:
  if (i2) goto l9;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18785)))), &_td_OOC_SymbolTable__TypeVarDesc);
  
  goto l11;
l9:
  i2=1u;
l11:
  if (i2) goto l13;
  i2 = passByReference;
  
  goto l15;
l13:
  i2=1u;
l15:
  if (i2) goto l17;
  i2 = OOC_SymbolTable_TypeRules__IsPredefType((OOC_SymbolTable__Type)i0, 12);
  
  goto l19;
l17:
  i2=1u;
l19:
  if (!i2) goto l42;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 18897)))), &_td_OOC_SSA__ConstDesc);
  if (i2) goto l23;
  i1=0u;
  goto l25;
l23:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 18931)))), &_td_OOC_SSA__ConstDesc, 18931)), 18937))+44);
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 18945)))), &_td_Object_Boxed__StringDesc);
  
l25:
  if (i1) goto l42;
  i1 = passByReference;
  if (i1) goto l29;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19058))+24);
  i1 = i1==(OOC_INT32)0;
  
  goto l31;
l29:
  i1=1u;
l31:
  if (i1) goto l33;
  i1 = OOC_SymbolTable_TypeRules__IsPredefType((OOC_SymbolTable__Type)i0, 12);
  
  goto l35;
l33:
  i1=1u;
l35:
  if (i1) goto l37;
  i0 = (OOC_INT32)OOC_C_Naming__NameOfType((OOC_SymbolTable__Type)i0);
  name = (Object__String)i0;
  i1 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 19231)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "(", 2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 19261)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i1, (Object__Object)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 19292)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, ")", 2);
  goto l42;
l37:
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 19142)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "(void*)", 8);
  goto l42;
l41:
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18663)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "(RT0__Struct)", 14);
l42:
  return;
  ;
}

static OOC_INT32 OOC_SSA_WriteC__GetPreloadId(ADT_Dictionary_IntValue__Dictionary preloadedVars, OOC_SSA__Instr instr) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)preloadedVars;
  i1 = (OOC_INT32)instr;
  i2 = ADT_Dictionary_IntValue__DictionaryDesc_HasKey((ADT_Dictionary_IntValue__Dictionary)i0, (Object__Object)i1);
  if (i2) goto l3;
  i2 = ADT_Dictionary_IntValue__DictionaryDesc_Size((ADT_Dictionary_IntValue__Dictionary)i0);
  ADT_Dictionary_IntValue__DictionaryDesc_Set((ADT_Dictionary_IntValue__Dictionary)i0, (Object__Object)i1, i2);
  i0=i2;
  goto l4;
l3:
  i0 = ADT_Dictionary_IntValue__DictionaryDesc_Get((ADT_Dictionary_IntValue__Dictionary)i0, (Object__Object)i1);
  
l4:
  return i0;
  ;
}

static Object__Object OOC_SSA_WriteC__WriteExceptionContext(OOC_SSA_WriteC__Writer w, OOC_SSA__Instr instr) {
  register OOC_INT32 i0,i1,i2;
  Object__Object obj;

  i0 = (OOC_INT32)instr;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 19822))+36);
  switch (i1) {
  case 78:
    
    goto l5;
  case 77:
  case 76:
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19965))+24);
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 19974));
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19978))+8);
    instr = (OOC_SSA__Instr)i0;
    
    goto l5;
  default:
    _failed_case(i1, 19812);
    
    goto l5;
  }
l5:
  i1 = (OOC_INT32)w;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20027))+24);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 20036));
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 20007))+100);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20040))+8);
  i0 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i2, (Object__Object)i0);
  obj = (Object__Object)i0;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 20054)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "_context", 9);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 20085)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i1, (Object__Object)i0);
  return (Object__Object)i0;
  ;
}

static void OOC_SSA_WriteC__WriteExpr(OOC_SSA_WriteC__Writer w, OOC_SSA__Instr instr) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_SSA__Result var;
  OOC_SSA__Opnd opnd;
  auto void OOC_SSA_WriteC__WriteExpr_Call(OOC_SSA__Instr call);
  auto void OOC_SSA_WriteC__WriteExpr_RefList(OOC_SSA__Opnd start, OOC_INT8 _class);
  auto void OOC_SSA_WriteC__WriteExpr_Assert(OOC_SSA__Instr assert);
  auto void OOC_SSA_WriteC__WriteExpr_CheckIndex(OOC_SSA__Instr checkIndex);
  auto void OOC_SSA_WriteC__WriteExpr_CheckPointer(OOC_SSA__Instr checkPointer);
  auto void OOC_SSA_WriteC__WriteExpr_TypeGuard(OOC_SSA__Instr typeGuard);
  auto void OOC_SSA_WriteC__WriteExpr_FailedCheck(OOC_SSA__Instr instr, const OOC_CHAR8 fct__ref[], OOC_LEN fct_0d, OOC_SSA__Opnd opnd);
  auto void OOC_SSA_WriteC__WriteExpr_Call(OOC_SSA__Instr call);
  auto void OOC_SSA_WriteC__WriteExpr_WriteDyadicOp(OOC_SSA__Instr instr, const OOC_CHAR8 op__ref[], OOC_LEN op_0d);
  auto void OOC_SSA_WriteC__WriteExpr_WriteDyadicOpU(OOC_SSA__Instr instr, const OOC_CHAR8 op__ref[], OOC_LEN op_0d);
  auto void OOC_SSA_WriteC__WriteExpr_WriteDyadicFct(OOC_SSA__Instr instr, const OOC_CHAR8 fct__ref[], OOC_LEN fct_0d);
  auto void OOC_SSA_WriteC__WriteExpr_WriteMonadicOp(OOC_SSA__Instr instr, const OOC_CHAR8 op__ref[], OOC_LEN op_0d, const OOC_CHAR8 suffix__ref[], OOC_LEN suffix_0d);
  auto void OOC_SSA_WriteC__WriteExpr_CastFromPtr(OOC_SSA__Result res);
  auto void OOC_SSA_WriteC__WriteExpr_NewObject(OOC_SSA__Instr instr);
  auto void OOC_SSA_WriteC__WriteExpr_NewBlock(OOC_SSA__Instr instr);
  auto void OOC_SSA_WriteC__WriteExpr_TypeCast(OOC_SSA__Instr instr);
  auto void OOC_SSA_WriteC__WriteExpr_TypeConv(OOC_SSA__Instr instr);
  auto void OOC_SSA_WriteC__WriteExpr_TypeTag(OOC_SSA__Instr instr);
  auto void OOC_SSA_WriteC__WriteExpr_TypeTest(OOC_SSA__Instr instr);
  auto void OOC_SSA_WriteC__WriteExpr_TBProcAddress(OOC_SSA__Instr instr);
  auto void OOC_SSA_WriteC__WriteExpr_VTableProcAddress(OOC_SSA__Instr instr);
  auto void OOC_SSA_WriteC__WriteExpr_CopyParameter(OOC_SSA__Address instr);
  auto void OOC_SSA_WriteC__WriteExpr_Copy(OOC_SSA__Instr instr);
  auto OOC_INT32 OOC_SSA_WriteC__WriteExpr_TypeId(OOC_SSA__Result res);
  auto void OOC_SSA_WriteC__WriteExpr_CopyString(OOC_SSA__Instr instr);
  auto void OOC_SSA_WriteC__WriteExpr_CmpString(OOC_SSA__Instr instr);
  auto void OOC_SSA_WriteC__WriteExpr_Concat(OOC_SSA__Instr instr);
  auto void OOC_SSA_WriteC__WriteExpr_MoveBlock(OOC_SSA__Instr instr);
  auto void OOC_SSA_WriteC__WriteExpr_Shift(OOC_SSA__Instr instr, OOC_CHAR8 rotate);
  auto void OOC_SSA_WriteC__WriteExpr_Indexed(OOC_SSA__Instr instr);
  auto OOC_CHAR8 OOC_SSA_WriteC__WriteExpr_SimpleVarAccess(OOC_SSA__Instr instr, OOC_INT8 adrClass);
  auto void OOC_SSA_WriteC__WriteExpr_PreloadedVar(OOC_SSA__Instr instr);
    
    void OOC_SSA_WriteC__WriteExpr_RefList(OOC_SSA__Opnd start, OOC_INT8 _class) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
      OOC_INT32 count;
      OOC_SSA__Opnd opnd;

      count = 0;
      i0 = (OOC_INT32)start;
      opnd = (OOC_SSA__Opnd)i0;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l18;
      i1 = _class;
      i2=0;
l3_loop:
      i3 = *(OOC_INT8*)((_check_pointer(i0, 20495))+4);
      i3 = i3==i1;
      if (!i3) goto l13;
      i3 = i2!=0;
      if (!i3) goto l9;
      i3 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 20560)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i3, ", ", 3);
l9:
      i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20615)))), &_td_OOC_SSA__TypedOpndDesc);
      if (!i3) goto l12;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20707)))), &_td_OOC_SSA__TypedOpndDesc, 20707)), 20717))+20);
      i4 = *(OOC_UINT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20757)))), &_td_OOC_SSA__TypedOpndDesc, 20757)), 20767))+24);
      i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 20668));
      i6 = (OOC_INT32)w;
      OOC_SSA_WriteC__CastToPtr((OOC_SSA_WriteC__Writer)i6, (OOC_SSA__Result)i5, (OOC_SymbolTable__Type)i3, i4);
l12:
      i3 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i3, (OOC_SSA__Opnd)i0);
      i2 = i2+1;
      count = i2;
      
l13:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20882))+8);
      opnd = (OOC_SSA__Opnd)i0;
      i3 = i0!=(OOC_INT32)0;
      if (i3) goto l3_loop;
l18:
      return;
      ;
    }

    
    void OOC_SSA_WriteC__WriteExpr_Assert(OOC_SSA__Instr assert) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20981)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20999)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "_assert(", 9);
      i0 = (OOC_INT32)assert;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21048))+24);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 21058))+8);
      OOC_SSA_WriteC__WriteExpr_RefList((OOC_SSA__Opnd)i1, 1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 21088)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, ", ", 3);
      i1 = (OOC_INT32)w;
      i0 = *(OOC_INT32*)((_check_pointer(i0, 21136))+40);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 21117)))), OOC_C_DeclWriter__WriterDesc_WriteLInt)),OOC_C_DeclWriter__WriterDesc_WriteLInt)((OOC_C_DeclWriter__Writer)i1, i0, 0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21154)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ")", 2);
      return;
      ;
    }

    
    void OOC_SSA_WriteC__WriteExpr_CheckIndex(OOC_SSA__Instr checkIndex) {
      register OOC_INT32 i0,i1,i2;
      OOC_INT8 bt;

      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21300)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "_check_index(", 14);
      i0 = (OOC_INT32)checkIndex;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21358))+24);
      OOC_SSA_WriteC__WriteExpr_RefList((OOC_SSA__Opnd)i1, 1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 21388)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, ", ", 3);
      i1 = (OOC_INT32)instr;
      i1 = OOC_SSA_WriteC__SubclassToBasicType((OOC_SSA__Result)i1);
      i1 = i1+4;
      bt = i1;
      i2 = (OOC_INT32)w;
      i1 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i2, 21509))+24)+(_check_index(i1, 17, OOC_UINT8, 21520))*4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 21493)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i2, (void*)((_check_pointer(i1, 21524))+1), 32);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 21540)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, ", ", 3);
      i1 = (OOC_INT32)w;
      i0 = *(OOC_INT32*)((_check_pointer(i0, 21592))+40);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 21569)))), OOC_C_DeclWriter__WriterDesc_WriteLInt)),OOC_C_DeclWriter__WriterDesc_WriteLInt)((OOC_C_DeclWriter__Writer)i1, i0, 0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21610)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ")", 2);
      return;
      ;
    }

    
    void OOC_SSA_WriteC__WriteExpr_CheckPointer(OOC_SSA__Instr checkPointer) {
      register OOC_INT32 i0,i1,i2;

      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21720)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "_check_pointer(", 16);
      i0 = (OOC_INT32)checkPointer;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21781))+24);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 21791))+8);
      i2 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i2, (OOC_SSA__Opnd)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 21811)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, ", ", 3);
      i1 = (OOC_INT32)w;
      i0 = *(OOC_INT32*)((_check_pointer(i0, 21865))+40);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 21840)))), OOC_C_DeclWriter__WriterDesc_WriteLInt)),OOC_C_DeclWriter__WriterDesc_WriteLInt)((OOC_C_DeclWriter__Writer)i1, i0, 0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21883)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ")", 2);
      return;
      ;
    }

    
    void OOC_SSA_WriteC__WriteExpr_TypeGuard(OOC_SSA__Instr typeGuard) {
      register OOC_INT32 i0,i1,i2;
      OOC_SSA__Opnd opnd;
      OOC_SymbolTable__Type type;
      Object__String name;

      i0 = (OOC_INT32)typeGuard;
      i1 = (OOC_INT32)OOC_SSA__InstrDesc_GetOpndClass((OOC_SSA__Instr)i0, 12);
      opnd = (OOC_SSA__Opnd)i1;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 22123));
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 22133)))), &_td_OOC_SSA__TypeRefDesc, 22133)), 22141))+44);
      type = (OOC_SymbolTable__Type)i1;
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 22171)))), &_td_OOC_SymbolTable__TypeClosureDesc);
      if (i2) goto l3;
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 22291)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i2, "_type_guard(", 13);
      goto l4;
l3:
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 22237)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i2, "_type_guard_q(", 15);
l4:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22358))+24);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 22368))+8);
      OOC_SSA_WriteC__WriteExpr_RefList((OOC_SSA__Opnd)i2, 1);
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 22398)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i2, ", &", 4);
      i2 = (OOC_INT32)w;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 22471))+92);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 22482))+16);
      i1 = (OOC_INT32)OOC_C_Naming__NameOfTypeDescriptor((OOC_SymbolTable__Type)i1, (OOC_C_Naming__QualTypeData)i2);
      name = (Object__String)i1;
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 22500)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i2, (Object__Object)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 22529)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, ", ", 3);
      i1 = (OOC_INT32)w;
      i0 = *(OOC_INT32*)((_check_pointer(i0, 22580))+40);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 22558)))), OOC_C_DeclWriter__WriterDesc_WriteLInt)),OOC_C_DeclWriter__WriterDesc_WriteLInt)((OOC_C_DeclWriter__Writer)i1, i0, 0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22598)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ")", 2);
      return;
      ;
    }

    
    void OOC_SSA_WriteC__WriteExpr_FailedCheck(OOC_SSA__Instr instr, const OOC_CHAR8 fct__ref[], OOC_LEN fct_0d, OOC_SSA__Opnd opnd) {
      register OOC_INT32 i0,i1;
      OOC_ALLOCATE_VPAR(fct,OOC_CHAR8 ,fct_0d)

      OOC_INITIALIZE_VPAR(fct__ref,fct,OOC_CHAR8 ,fct_0d)
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22735)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22753)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, (void*)(OOC_INT32)fct, fct_0d);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22781)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "(", 2);
      i0 = (OOC_INT32)opnd;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l4;
      i1 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i1, (OOC_SSA__Opnd)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22861)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ", ", 3);
l4:
      i0 = (OOC_INT32)w;
      i1 = (OOC_INT32)instr;
      i1 = *(OOC_INT32*)((_check_pointer(i1, 22919))+40);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22901)))), OOC_C_DeclWriter__WriterDesc_WriteLInt)),OOC_C_DeclWriter__WriterDesc_WriteLInt)((OOC_C_DeclWriter__Writer)i0, i1, 0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22937)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ")", 2);
      return;
      ;
    }

    
    void OOC_SSA_WriteC__WriteExpr_Call(OOC_SSA__Instr call) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_INT8 _class;
      OOC_SSA__Instr adr;
      OOC_SymbolTable__Declaration decl;
      Object__String name;
      OOC_SymbolTable__FormalPars procType;

      i0 = (OOC_INT32)call;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23186))+24);
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 23196));
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23201))+8);
      i1 = *(OOC_INT8*)((_check_pointer(i1, 23208))+36);
      _class = i1;
      i2 = i1==63;
      if (i2) goto l3;
      i1 = i1==87;
      
      goto l5;
l3:
      i1=1u;
l5:
      if (i1) goto l11;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23721))+24);
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 23731));
      i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 23737)))), &_td_OOC_SSA__DeclRefDesc));
      if (i1) goto l9;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24097))+24);
      i2 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i2, (OOC_SSA__Opnd)i1);
      goto l12;
l9:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23852))+24);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 23867)))), &_td_OOC_SSA__TypedOpndDesc, 23867)), 23877))+20);
      i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 23888)))), &_td_OOC_SymbolTable__FormalParsDesc, 23888);
      procType = (OOC_SymbolTable__FormalPars)i1;
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 23910)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i2, 40u);
      i2 = (OOC_INT32)w;
      i1 = (OOC_INT32)OOC_C_ConvertDecl__ConvertType((OOC_C_DeclWriter__Writer)i2, (OOC_SymbolTable__Type)i1, (OOC_SymbolTable__Type)i1);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 23938)))), OOC_C_DeclWriter__WriterDesc_WriteTypeCast)),OOC_C_DeclWriter__WriterDesc_WriteTypeCast)((OOC_C_DeclWriter__Writer)i2, (OOC_C_DeclWriter__Type)i1);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24025))+24);
      i2 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i2, (OOC_SSA__Opnd)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 24047)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 41u);
      goto l12;
l11:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23398))+24);
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 23408));
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23413))+8);
      adr = (OOC_SSA__Instr)i1;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23441))+24);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23451))+8);
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 23461));
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23466))+8);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 23478)))), &_td_OOC_SSA__DeclRefDesc, 23478)), 23486))+44);
      decl = (OOC_SymbolTable__Declaration)i1;
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 23503)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i2, "OOC_TBCALL(", 12);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23554))+24);
      i3 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i3, (OOC_SSA__Opnd)i2);
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 23576)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i2, 44u);
      i1 = (OOC_INT32)OOC_C_Naming__NameOfDeclaration((OOC_SymbolTable__Declaration)i1);
      name = (Object__String)i1;
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 23653)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i2, (Object__Object)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 23684)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 41u);
l12:
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 24128)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "(", 2);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24168))+24);
      OOC_SSA_WriteC__WriteExpr_RefList((OOC_SSA__Opnd)i0, 1);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 24198)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ")", 2);
      return;
      ;
    }

    
    void OOC_SSA_WriteC__WriteExpr_WriteDyadicOp(OOC_SSA__Instr instr, const OOC_CHAR8 op__ref[], OOC_LEN op_0d) {
      register OOC_INT32 i0,i1,i2;
      OOC_ALLOCATE_VPAR(op,OOC_CHAR8 ,op_0d)

      OOC_INITIALIZE_VPAR(op__ref,op,OOC_CHAR8 ,op_0d)
      i0 = (OOC_INT32)instr;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24329))+24);
      i2 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i2, (OOC_SSA__Opnd)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 24349)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, (void*)(OOC_INT32)op, op_0d);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24388))+24);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24398))+8);
      i1 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i1, (OOC_SSA__Opnd)i0);
      return;
      ;
    }

    
    void OOC_SSA_WriteC__WriteExpr_WriteDyadicOpU(OOC_SSA__Instr instr, const OOC_CHAR8 op__ref[], OOC_LEN op_0d) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_ALLOCATE_VPAR(op,OOC_CHAR8 ,op_0d)
      OOC_INT8 subclass;
      OOC_INT8 type;

      OOC_INITIALIZE_VPAR(op__ref,op,OOC_CHAR8 ,op_0d)
      i0 = (OOC_INT32)instr;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24729))+24);
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 24738));
      i1 = *(OOC_INT8*)((_check_pointer(i1, 24742))+5);
      subclass = i1;
      i2 = 5<=i1;
      if (i2) goto l3;
      i2=0u;
      goto l5;
l3:
      i2 = i1<=9;
      
l5:
      if (i2) goto l7;
      OOC_SSA_WriteC__WriteExpr_WriteDyadicOp((OOC_SSA__Instr)i0, (void*)(OOC_INT32)op, op_0d);
      goto l12;
l7:
      i1 = OOC_SSA_Allocator__SubclassToBasicType(i1);
      type = i1;
      i2 = i1<6;
      if (!i2) goto l11;
      i1 = i1+4;
      type = i1;
      
l11:
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 25052)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i2, 40u);
      i2 = (OOC_INT32)w;
      i3 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i2, 25096))+24)+(_check_index(i1, 17, OOC_UINT8, 25107))*4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 25080)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i2, (void*)((_check_pointer(i3, 25113))+1), 32);
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 25131)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i2, 41u);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25171))+24);
      i3 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i3, (OOC_SSA__Opnd)i2);
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 25193)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i2, (void*)(OOC_INT32)op, op_0d);
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 25222)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i2, 40u);
      i2 = (OOC_INT32)w;
      i1 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i2, 25266))+24)+(_check_index(i1, 17, OOC_UINT8, 25277))*4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 25250)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i2, (void*)((_check_pointer(i1, 25283))+1), 32);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 25301)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 41u);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25341))+24);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25351))+8);
      i1 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i1, (OOC_SSA__Opnd)i0);
l12:
      return;
      ;
    }

    
    void OOC_SSA_WriteC__WriteExpr_WriteDyadicFct(OOC_SSA__Instr instr, const OOC_CHAR8 fct__ref[], OOC_LEN fct_0d) {
      register OOC_INT32 i0,i1,i2;
      OOC_ALLOCATE_VPAR(fct,OOC_CHAR8 ,fct_0d)

      OOC_INITIALIZE_VPAR(fct__ref,fct,OOC_CHAR8 ,fct_0d)
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 25531)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, (void*)(OOC_INT32)fct, fct_0d);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 25559)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i0, 40u);
      i0 = (OOC_INT32)instr;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25597))+24);
      i2 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i2, (OOC_SSA__Opnd)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 25617)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 44u);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25655))+24);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25665))+8);
      i1 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i1, (OOC_SSA__Opnd)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 25685)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ")", 2);
      return;
      ;
    }

    
    void OOC_SSA_WriteC__WriteExpr_WriteMonadicOp(OOC_SSA__Instr instr, const OOC_CHAR8 op__ref[], OOC_LEN op_0d, const OOC_CHAR8 suffix__ref[], OOC_LEN suffix_0d) {
      register OOC_INT32 i0,i1;
      OOC_ALLOCATE_VPAR(op,OOC_CHAR8 ,op_0d)
      OOC_ALLOCATE_VPAR(suffix,OOC_CHAR8 ,suffix_0d)

      OOC_INITIALIZE_VPAR(op__ref,op,OOC_CHAR8 ,op_0d)
      OOC_INITIALIZE_VPAR(suffix__ref,suffix,OOC_CHAR8 ,suffix_0d)
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 25824)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, (void*)(OOC_INT32)op, op_0d);
      i0 = (OOC_INT32)instr;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25863))+24);
      i1 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i1, (OOC_SSA__Opnd)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 25883)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, (void*)(OOC_INT32)suffix, suffix_0d);
      return;
      ;
    }

    
    void OOC_SSA_WriteC__WriteExpr_CastFromPtr(OOC_SSA__Result res) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)res;
      i0 = *(OOC_INT8*)((_check_pointer(i0, 26000))+5);
      i0 = i0==9;
      if (!i0) goto l4;
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 26045)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "(", 2);
      i0 = (OOC_INT32)w;
      i1 = (OOC_INT32)instr;
      i1 = OOC_SSA_WriteC__SubclassToBasicType((OOC_SSA__Result)i1);
      i1 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i0, 26091))+24)+(_check_index(i1, 17, OOC_UINT8, 26102))*4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 26075)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, (void*)((_check_pointer(i1, 26131))+1), 32);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 26149)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ")", 2);
l4:
      return;
      ;
    }

    
    void OOC_SSA_WriteC__WriteExpr_NewObject(OOC_SSA__Instr instr) {
      register OOC_INT32 i0,i1,i2;
      OOC_SSA__Opnd opnd;
      Object__String name;

      i0 = (OOC_INT32)instr;
      OOC_SSA_WriteC__WriteExpr_CastFromPtr((OOC_SSA__Result)i0);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 26341)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "RT0__NewObject(", 16);
      i0 = (OOC_INT32)OOC_SSA__InstrDesc_GetOpndClass((OOC_SSA__Instr)i0, 12);
      opnd = (OOC_SSA__Opnd)i0;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 26470));
      i2 = (OOC_INT32)w;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 26540))+92);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 26480)))), &_td_OOC_SSA__TypeRefDesc, 26480)), 26488))+44);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 26551))+16);
      i1 = (OOC_INT32)OOC_C_Naming__NameOfTypeDescriptor((OOC_SymbolTable__Type)i1, (OOC_C_Naming__QualTypeData)i2);
      name = (Object__String)i1;
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 26569)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i2, (Object__Object)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 26598)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, ".baseTypes[0]", 14);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26650))+8);
      opnd = (OOC_SSA__Opnd)i0;
      i1 = i0!=0;
      if (i1) goto l3;
      i1=0u;
      goto l5;
l3:
      i1 = *(OOC_INT8*)((_check_pointer(i0, 26694))+4);
      i1 = i1==1;
      
l5:
      if (!i1) goto l16;
l7_loop:
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 26726)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, ", ", 3);
      i1 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i1, (OOC_SSA__Opnd)i0);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26791))+8);
      opnd = (OOC_SSA__Opnd)i0;
      i1 = i0!=0;
      if (i1) goto l10;
      i1=0u;
      goto l12;
l10:
      i1 = *(OOC_INT8*)((_check_pointer(i0, 26694))+4);
      i1 = i1==1;
      
l12:
      if (i1) goto l7_loop;
l16:
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 26821)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ")", 2);
      return;
      ;
    }

    
    void OOC_SSA_WriteC__WriteExpr_NewBlock(OOC_SSA__Instr instr) {
      register OOC_INT32 i0,i1;
      OOC_SSA__Opnd opnd;

      i0 = (OOC_INT32)instr;
      OOC_SSA_WriteC__WriteExpr_CastFromPtr((OOC_SSA__Result)i0);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 26979)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "RT0__NewBlock(", 15);
      i0 = (OOC_INT32)OOC_SSA__InstrDesc_GetOpndClass((OOC_SSA__Instr)i0, 1);
      opnd = (OOC_SSA__Opnd)i0;
      i1 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i1, (OOC_SSA__Opnd)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 27087)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ")", 2);
      return;
      ;
    }

    
    void OOC_SSA_WriteC__WriteExpr_TypeCast(OOC_SSA__Instr instr) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_INT8 destType;
      OOC_INT8 sourceType;

      i0 = (OOC_INT32)instr;
      OOC_SSA_WriteC__WriteExpr_CastFromPtr((OOC_SSA__Result)i0);
      i1 = *(OOC_INT8*)((_check_pointer(i0, 27314))+5);
      i1 = OOC_SSA_Allocator__SubclassToBasicType(i1);
      destType = i1;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27383))+24);
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 27393));
      i2 = *(OOC_INT8*)((_check_pointer(i2, 27398))+5);
      i2 = OOC_SSA_Allocator__SubclassToBasicType(i2);
      sourceType = i2;
      i3 = OOC_SSA_Opcode__ConvDiffersFromCast(i2, i1);
      if (i3) goto l3;
      i3 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 27535)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i3, "_type_cast_fast(", 17);
      goto l4;
l3:
      i3 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 27484)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i3, "_type_cast(", 12);
l4:
      i3 = (OOC_INT32)w;
      i1 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i3, 27605))+24)+(_check_index(i1, 17, OOC_UINT8, 27616))*4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 27589)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i3, (void*)((_check_pointer(i1, 27626))+1), 32);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 27642)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, ", ", 3);
      i1 = (OOC_INT32)w;
      i2 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i1, 27687))+24)+(_check_index(i2, 17, OOC_UINT8, 27698))*4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 27671)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, (void*)((_check_pointer(i2, 27710))+1), 32);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 27726)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, ", ", 3);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27767))+24);
      i1 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i1, (OOC_SSA__Opnd)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 27787)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ")", 2);
      return;
      ;
    }

    
    void OOC_SSA_WriteC__WriteExpr_TypeConv(OOC_SSA__Instr instr) {
      register OOC_INT32 i0,i1,i2;
      OOC_INT8 destType;

      i0 = (OOC_INT32)instr;
      i1 = *(OOC_INT8*)((_check_pointer(i0, 27973))+5);
      i1 = OOC_SSA_Allocator__SubclassToBasicType(i1);
      destType = i1;
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 27993)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i2, "(", 2);
      i2 = (OOC_INT32)w;
      i1 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i2, 28037))+24)+(_check_index(i1, 17, OOC_UINT8, 28048))*4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 28021)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i2, (void*)((_check_pointer(i1, 28058))+1), 32);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 28074)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, ")", 2);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28114))+24);
      i1 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i1, (OOC_SSA__Opnd)i0);
      return;
      ;
    }

    
    void OOC_SSA_WriteC__WriteExpr_TypeTag(OOC_SSA__Instr instr) {
      register OOC_INT32 i0,i1;
      Object__String name;

      i0 = (OOC_INT32)instr;
      OOC_SSA_WriteC__WriteExpr_CastFromPtr((OOC_SSA__Result)i0);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28266))+24);
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 28276));
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 28282)))), &_td_OOC_SSA__DeclRefDesc);
      if (i1) goto l7;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28450))+24);
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 28460));
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 28466)))), &_td_OOC_SSA__TypeRefDesc);
      if (i1) goto l5;
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 28715)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "OOC_TYPE_TAG(", 14);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28769))+24);
      i1 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i1, (OOC_SSA__Opnd)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 28791)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i0, 41u);
      goto l8;
l5:
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 28496)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 38u);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28564))+24);
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 28573));
      i1 = (OOC_INT32)w;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 28642))+92);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 28582)))), &_td_OOC_SSA__TypeRefDesc, 28582)), 28590))+44);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 28653))+16);
      i0 = (OOC_INT32)OOC_C_Naming__NameOfTypeDescriptor((OOC_SymbolTable__Type)i0, (OOC_C_Naming__QualTypeData)i1);
      name = (Object__String)i0;
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 28673)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i1, (Object__Object)i0);
      goto l8;
l7:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28351))+24);
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 28361));
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 28371)))), &_td_OOC_SSA__DeclRefDesc, 28371)), 28379))+44);
      i0 = (OOC_INT32)OOC_C_Naming__NameOfTypeTagParam((OOC_SymbolTable__VarDecl)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 28390)))), &_td_OOC_SymbolTable__VarDeclDesc, 28390)));
      name = (Object__String)i0;
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 28410)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i1, (Object__Object)i0);
l8:
      return;
      ;
    }

    
    void OOC_SSA_WriteC__WriteExpr_TypeTest(OOC_SSA__Instr instr) {
      register OOC_INT32 i0,i1,i2;
      OOC_SSA__Opnd opnd;
      OOC_SymbolTable__Type type;
      Object__String name;

      i0 = (OOC_INT32)instr;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28983))+24);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 28993))+8);
      opnd = (OOC_SSA__Opnd)i1;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 29023));
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 29033)))), &_td_OOC_SSA__TypeRefDesc, 29033)), 29041))+44);
      type = (OOC_SymbolTable__Type)i1;
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 29065)))), &_td_OOC_SymbolTable__TypeClosureDesc);
      if (i2) goto l3;
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 29192)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i2, "OOC_TYPE_TEST(", 15);
      goto l4;
l3:
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 29131)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i2, "RT0__TypeTest((OOC_PTR)", 24);
l4:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29254))+24);
      i2 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i2, (OOC_SSA__Opnd)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 29274)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ", &", 4);
      i0 = (OOC_INT32)w;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29347))+92);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29358))+16);
      i0 = (OOC_INT32)OOC_C_Naming__NameOfTypeDescriptor((OOC_SymbolTable__Type)i1, (OOC_C_Naming__QualTypeData)i0);
      name = (Object__String)i0;
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 29376)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i1, (Object__Object)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 29405)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ")", 2);
      return;
      ;
    }

    
    void OOC_SSA_WriteC__WriteExpr_TBProcAddress(OOC_SSA__Instr instr) {
      register OOC_INT32 i0,i1,i2;
      Object__String name;

      i0 = (OOC_INT32)instr;
      OOC_SSA_WriteC__WriteExpr_CastFromPtr((OOC_SSA__Result)i0);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 29563)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "OOC_TBPROC_ADR(", 16);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29617))+24);
      i2 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i2, (OOC_SSA__Opnd)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 29637)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, ", ", 3);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29704))+24);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29714))+8);
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 29724));
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 29734)))), &_td_OOC_SSA__DeclRefDesc, 29734)), 29742))+44);
      i0 = (OOC_INT32)OOC_C_Naming__NameOfDeclaration((OOC_SymbolTable__Declaration)i0);
      name = (Object__String)i0;
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 29758)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i1, (Object__Object)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 29787)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ")", 2);
      return;
      ;
    }

    
    void OOC_SSA_WriteC__WriteExpr_VTableProcAddress(OOC_SSA__Instr instr) {
      register OOC_INT32 i0,i1,i2;
      Object__String name;

      i0 = (OOC_INT32)instr;
      OOC_SSA_WriteC__WriteExpr_CastFromPtr((OOC_SSA__Result)i0);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 29955)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "OOC_VTABLEPROC_ADR(", 20);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30013))+24);
      i2 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i2, (OOC_SSA__Opnd)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 30033)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, ", ", 3);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30100))+24);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30110))+8);
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 30120));
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 30130)))), &_td_OOC_SSA__DeclRefDesc, 30130)), 30138))+44);
      i0 = (OOC_INT32)OOC_C_Naming__NameOfDeclaration((OOC_SymbolTable__Declaration)i0);
      name = (Object__String)i0;
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 30154)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i1, (Object__Object)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 30183)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ")", 2);
      return;
      ;
    }

    
    void OOC_SSA_WriteC__WriteExpr_CopyParameter(OOC_SSA__Address instr) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_SymbolTable__VarDecl varDecl;
      Object__String name;

      i0 = (OOC_INT32)instr;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30370))+44);
      i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 30381)))), &_td_OOC_SymbolTable__VarDeclDesc, 30381);
      varDecl = (OOC_SymbolTable__VarDecl)i1;
      i2 = (OOC_INT32)OOC_C_Naming__NameOfDeclaration((OOC_SymbolTable__Declaration)i1);
      name = (Object__String)i2;
      i3 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 30455)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i3);
      i3 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 30473)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i3, "OOC_INITIALIZE_VPAR(", 21);
      i3 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 30520)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i3, (Object__Object)i2);
      i3 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 30549)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i3, "__ref,", 7);
      i3 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 30601)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i3, (Object__Object)i2);
      i2 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriteTypeAndLength((OOC_SSA_WriteC__Writer)i2, (OOC_SSA__Instr)i0, (OOC_SymbolTable__VarDecl)i1, 1u);
      return;
      ;
    }

    
    void OOC_SSA_WriteC__WriteExpr_Copy(OOC_SSA__Instr instr) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_SymbolTable__Type type;

      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 30784)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i0);
      i0 = (OOC_INT32)instr;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30814))+24);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 30824))+8);
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 30834));
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 30844)))), &_td_OOC_SSA__TypeRefDesc, 30844)), 30852))+44);
      type = (OOC_SymbolTable__Type)i1;
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 30867)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i2, "_copy_block(", 13);
      i2 = (OOC_INT32)OOC_SSA__InstrDesc_GetOpndClass((OOC_SSA__Instr)i0, 4);
      i3 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i3, (OOC_SSA__Opnd)i2);
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 30957)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i2, 44u);
      i0 = (OOC_INT32)OOC_SSA__InstrDesc_GetOpndClass((OOC_SSA__Instr)i0, 6);
      i2 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i2, (OOC_SSA__Opnd)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 31035)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i0, 44u);
      i0 = (OOC_INT32)w;
      i1 = *(OOC_INT32*)((_check_pointer(i1, 31078))+32);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 31061)))), OOC_C_DeclWriter__WriterDesc_WriteLInt)),OOC_C_DeclWriter__WriterDesc_WriteLInt)((OOC_C_DeclWriter__Writer)i0, i1, 0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 31097)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ")", 2);
      return;
      ;
    }

    
    OOC_INT32 OOC_SSA_WriteC__WriteExpr_TypeId(OOC_SSA__Result res) {
      register OOC_INT32 i0;

      i0 = (OOC_INT32)res;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 31213)))), &_td_OOC_SSA__TypeRefDesc, 31213)), 31221))+44);
      i0 = *(OOC_INT16*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 31232)))), &_td_OOC_SymbolTable__PredefTypeDesc, 31232)), 31243))+40);
      return i0;
      ;
    }

    
    void OOC_SSA_WriteC__WriteExpr_CopyString(OOC_SSA__Instr instr) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_INT32 source;
      OOC_INT32 dest;

      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 31365)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i0);
      i0 = (OOC_INT32)instr;
      i1 = (OOC_INT32)OOC_SSA__InstrDesc_NthArg((OOC_SSA__Instr)i0, 1);
      i1 = OOC_SSA_WriteC__WriteExpr_TypeId((OOC_SSA__Result)i1);
      source = i1;
      i2 = (OOC_INT32)OOC_SSA__InstrDesc_NthArg((OOC_SSA__Instr)i0, 2);
      i2 = OOC_SSA_WriteC__WriteExpr_TypeId((OOC_SSA__Result)i2);
      dest = i2;
      i3 = i1==1;
      if (i3) goto l12;
      i1 = i1==2;
      if (i1) goto l5;
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 31986)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "_copy_32(", 10);
      goto l18;
l5:
      switch (i2) {
      case 2:
        i1 = (OOC_INT32)w;
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 31803)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "_copy_16(", 10);
        goto l18;
      case 3:
        i1 = (OOC_INT32)w;
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 31860)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "_copy_16to32(", 14);
        goto l18;
      default:
        _failed_case(i2, 31762);
        goto l18;
      }
l12:
      switch (i2) {
      case 1:
        i1 = (OOC_INT32)w;
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 31549)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "_copy_8(", 9);
        goto l18;
      case 2:
        i1 = (OOC_INT32)w;
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 31605)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "_copy_8to16(", 13);
        goto l18;
      case 3:
        i1 = (OOC_INT32)w;
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 31665)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "_copy_8to32(", 13);
        goto l18;
      default:
        _failed_case(i2, 31508);
        goto l18;
      }
l18:
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 32033)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "(const void*)", 14);
      i1 = (OOC_INT32)OOC_SSA__InstrDesc_GetOpndClass((OOC_SSA__Instr)i0, 4);
      i2 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i2, (OOC_SSA__Opnd)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 32124)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, ",(void*)", 9);
      i1 = (OOC_INT32)OOC_SSA__InstrDesc_GetOpndClass((OOC_SSA__Instr)i0, 6);
      i2 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i2, (OOC_SSA__Opnd)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 32211)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 44u);
      i0 = (OOC_INT32)OOC_SSA__InstrDesc_GetOpndClass((OOC_SSA__Instr)i0, 1);
      i1 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i1, (OOC_SSA__Opnd)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32284)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ")", 2);
      return;
      ;
    }

    
    void OOC_SSA_WriteC__WriteExpr_CmpString(OOC_SSA__Instr instr) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32387)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i0);
      i0 = (OOC_INT32)instr;
      i1 = (OOC_INT32)OOC_SSA__InstrDesc_NthArg((OOC_SSA__Instr)i0, 1);
      i1 = OOC_SSA_WriteC__WriteExpr_TypeId((OOC_SSA__Result)i1);
      switch (i1) {
      case 1:
        i1 = (OOC_INT32)w;
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 32462)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "_cmp8((const void*)", 20);
        goto l6;
      case 2:
        i1 = (OOC_INT32)w;
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 32525)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "_cmp16((const void*)", 21);
        goto l6;
      case 3:
        i1 = (OOC_INT32)w;
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 32589)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "_cmp32((const void*)", 21);
        goto l6;
      default:
        _failed_case(i1, 32404);
        goto l6;
      }
l6:
      i0 = (OOC_INT32)OOC_SSA__InstrDesc_GetOpndClass((OOC_SSA__Instr)i0, 4);
      opnd = (OOC_SSA__Opnd)i0;
      i1 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i1, (OOC_SSA__Opnd)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32716)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ",(const void*)", 15);
l7_loop:
      i0 = (OOC_INT32)opnd;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32839))+8);
      opnd = (OOC_SSA__Opnd)i0;
      i1 = *(OOC_INT8*)((_check_pointer(i0, 32868))+4);
      i1 = i1==4;
      if (!i1) goto l7_loop;
l11:
      i1 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i1, (OOC_SSA__Opnd)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32921)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ")", 2);
      return;
      ;
    }

    
    void OOC_SSA_WriteC__WriteExpr_Concat(OOC_SSA__Instr instr) {
      register OOC_INT32 i0,i1,i2;
      OOC_SSA__Opnd opnd;

      i0 = (OOC_INT32)instr;
      OOC_SSA_WriteC__WriteExpr_CastFromPtr((OOC_SSA__Result)i0);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 33074)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "Object__Concat2(", 17);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33144))+24);
      opnd = (OOC_SSA__Opnd)i1;
      i2 = i1!=(OOC_INT32)0;
      if (!i2) goto l11;
l3_loop:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33207))+24);
      i2 = i1!=i2;
      if (!i2) goto l6;
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 33234)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i2, ",", 2);
l6:
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 33276)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i2, "(void*)", 8);
      i2 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i2, (OOC_SSA__Opnd)i1);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 33343))+8);
      opnd = (OOC_SSA__Opnd)i1;
      i2 = i1!=(OOC_INT32)0;
      if (i2) goto l3_loop;
l11:
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33372)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ")", 2);
      return;
      ;
    }

    
    void OOC_SSA_WriteC__WriteExpr_MoveBlock(OOC_SSA__Instr instr) {
      register OOC_INT32 i0,i1,i2;

      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33470)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33488)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "_move_block(", 13);
      i0 = (OOC_INT32)instr;
      i1 = (OOC_INT32)OOC_SSA__InstrDesc_GetOpndClass((OOC_SSA__Instr)i0, 4);
      i2 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i2, (OOC_SSA__Opnd)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 33578)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 44u);
      i1 = (OOC_INT32)OOC_SSA__InstrDesc_GetOpndClass((OOC_SSA__Instr)i0, 6);
      i2 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i2, (OOC_SSA__Opnd)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 33656)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 44u);
      i0 = (OOC_INT32)OOC_SSA__InstrDesc_GetOpndClass((OOC_SSA__Instr)i0, 1);
      i1 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i1, (OOC_SSA__Opnd)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33729)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ")", 2);
      return;
      ;
    }

    
    void OOC_SSA_WriteC__WriteExpr_Shift(OOC_SSA__Instr instr, OOC_CHAR8 rotate) {
      register OOC_INT32 i0,i1,i2;

      i0 = rotate;
      if (i0) goto l3;
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33912)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "_lsh(", 6);
      goto l4;
l3:
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33867)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "_rot(", 6);
l4:
      i0 = (OOC_INT32)w;
      i1 = (OOC_INT32)instr;
      i2 = *(OOC_INT8*)((_check_pointer(i1, 34019))+5);
      i2 = OOC_SSA_Allocator__SubclassToBasicType(i2);
      i2 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i0, 33971))+24)+(_check_index(i2, 17, OOC_UINT8, 33982))*4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33955)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, (void*)((_check_pointer(i2, 34031))+1), 32);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34047)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ", ", 3);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34088))+24);
      i2 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i2, (OOC_SSA__Opnd)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34108)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ", ", 3);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34149))+24);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34159))+8);
      i1 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i1, (OOC_SSA__Opnd)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34179)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ")", 2);
      return;
      ;
    }

    
    void OOC_SSA_WriteC__WriteExpr_Indexed(OOC_SSA__Instr instr) {
      register OOC_INT32 i0,i1,i2;

      i0 = (OOC_INT32)instr;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34285))+24);
      i2 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i2, (OOC_SSA__Opnd)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 34305)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 43u);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34343))+24);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34353))+8);
      i2 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i2, (OOC_SSA__Opnd)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 34373)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 42u);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34411))+24);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34421))+8);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34431))+8);
      i1 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i1, (OOC_SSA__Opnd)i0);
      return;
      ;
    }

    
    OOC_CHAR8 OOC_SSA_WriteC__WriteExpr_SimpleVarAccess(OOC_SSA__Instr instr, OOC_INT8 adrClass) {
      register OOC_INT32 i0,i1;
      OOC_SSA__Opnd opnd;
      OOC_SSA__Result adr;
      OOC_SSA__Opnd design;

      i0 = (OOC_INT32)instr;
      i1 = adrClass;
      i0 = (OOC_INT32)OOC_SSA__InstrDesc_GetOpndClass((OOC_SSA__Instr)i0, i1);
      opnd = (OOC_SSA__Opnd)i0;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 34677));
      adr = (OOC_SSA__Result)i1;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34704))+8);
      design = (OOC_SSA__Opnd)i0;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 34730)))), &_td_OOC_SSA__AddressDesc);
      if (i1) goto l3;
      i0=0u;
      goto l9;
l3:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34765))+8);
      i1 = i1==0;
      if (i1) goto l6;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34803))+8);
      i1 = *(OOC_INT8*)((_check_pointer(i1, 34813))+4);
      i0 = *(OOC_INT8*)((_check_pointer(i0, 34829))+4);
      i0 = i1!=i0;
      
      goto l9;
l6:
      i0=1u;
l9:
      if (i0) goto l11;
      return 0u;
      goto l12;
l11:
      return 1u;
l12:
      _failed_function(34476); return 0;
      ;
    }

    
    void OOC_SSA_WriteC__WriteExpr_PreloadedVar(OOC_SSA__Instr instr) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_INT32 id;
      OOC_C_DeclWriter__Writer wd;

      i0 = (OOC_INT32)w;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35196))+92);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35207))+36);
      i1 = (OOC_INT32)instr;
      i0 = OOC_SSA_WriteC__GetPreloadId((ADT_Dictionary_IntValue__Dictionary)i0, (OOC_SSA__Instr)i1);
      id = i0;
      OOC_SSA_WriteC__WriteExpr_CastFromPtr((OOC_SSA__Result)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 35264)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "_c", 3);
      i1 = (OOC_INT32)w;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 35303))+8);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 35303))+8);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 35314)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i1, i0, 0);
      i1 = (OOC_INT32)w;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 35347))+92);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 35358))+4);
      wd = (OOC_C_DeclWriter__Writer)i1;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 35371)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "static void* _c", 16);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 35427))+8);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 35427))+8);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 35438)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i3, i0, 0);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 35465)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, ";", 2);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 35492)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i1);
      return;
      ;
    }


  i0 = (OOC_INT32)instr;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 35549))+36);
  switch (i1) {
  case 12:
    OOC_SSA_WriteC__WriteExpr_CastFromPtr((OOC_SSA__Result)i0);
    i0 = (OOC_INT32)instr;
    i0 = OOC_SSA_WriteC__WriteExpr_SimpleVarAccess((OOC_SSA__Instr)i0, 4);
    if (i0) goto l5;
    i0 = (OOC_INT32)w;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 35733)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "*(", 3);
    i1 = (OOC_INT32)instr;
    i2 = OOC_SSA_WriteC__SubclassToBasicType((OOC_SSA__Result)i1);
    i2 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i0, 35780))+24)+(_check_index(i2, 17, OOC_UINT8, 35816))*4);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 35764)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, (void*)((_check_pointer(i2, 35845))+1), 32);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 35863)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "*)", 3);
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 35906))+24);
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 35916))+8);
    OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i0, (OOC_SSA__Opnd)i1);
    goto l82;
l5:
    i0 = (OOC_INT32)instr;
    i0 = (OOC_INT32)OOC_SSA__InstrDesc_GetOpndClass((OOC_SSA__Instr)i0, 5);
    i1 = (OOC_INT32)w;
    OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i1, (OOC_SSA__Opnd)i0);
    goto l82;
  case 13:
    i1 = (OOC_INT32)w;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 35972)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i1);
    i0 = OOC_SSA_WriteC__WriteExpr_SimpleVarAccess((OOC_SSA__Instr)i0, 6);
    if (i0) goto l10;
    i0 = (OOC_INT32)w;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36277)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "*(", 3);
    i1 = (OOC_INT32)instr;
    i2 = OOC_SSA_WriteC__SubclassToBasicType((OOC_SSA__Result)i1);
    i2 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i0, 36324))+24)+(_check_index(i2, 17, OOC_UINT8, 36360))*4);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36308)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, (void*)((_check_pointer(i2, 36389))+1), 32);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36407)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "*)", 3);
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 36450))+24);
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 36460))+8);
    OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i0, (OOC_SSA__Opnd)i2);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36482)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, " = ", 4);
    
    goto l11;
l10:
    i0 = (OOC_INT32)instr;
    i1 = (OOC_INT32)OOC_SSA__InstrDesc_GetOpndClass((OOC_SSA__Instr)i0, 7);
    i2 = (OOC_INT32)w;
    OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i2, (OOC_SSA__Opnd)i1);
    i1 = (OOC_INT32)OOC_SSA__InstrDesc_GetArgClass((OOC_SSA__Instr)i0, 7);
    var = (OOC_SSA__Result)i1;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 36156)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i2, " = ", 4);
    i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 36214)))), &_td_OOC_SSA__DeclRefDesc, 36214)), 36222))+44);
    i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 36233)))), &_td_OOC_SymbolTable__VarDeclDesc, 36233)), 36241))+48);
    OOC_SSA_WriteC__CastToPtr((OOC_SSA_WriteC__Writer)i2, (OOC_SSA__Result)i1, (OOC_SymbolTable__Type)i3, 0u);
    i1=i0;i0=i2;
l11:
    i1 = (OOC_INT32)OOC_SSA__InstrDesc_GetOpndClass((OOC_SSA__Instr)i1, 8);
    OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i0, (OOC_SSA__Opnd)i1);
    goto l82;
  case 14:
    OOC_SSA_WriteC__WriteExpr_Copy((OOC_SSA__Instr)i0);
    goto l82;
  case 15:
    OOC_SSA_WriteC__WriteExpr_CopyString((OOC_SSA__Instr)i0);
    goto l82;
  case 16:
    OOC_SSA_WriteC__WriteExpr_CmpString((OOC_SSA__Instr)i0);
    goto l82;
  case 17:
    OOC_SSA_WriteC__WriteExpr_Concat((OOC_SSA__Instr)i0);
    goto l82;
  case 18:
    OOC_SSA_WriteC__WriteExpr_MoveBlock((OOC_SSA__Instr)i0);
    goto l82;
  case 56:
    i1 = (OOC_INT32)w;
    OOC_SSA_WriteC__WriterDesc_LengthExprHeap((OOC_SSA_WriteC__Writer)i1, (OOC_SSA__Instr)i0);
    goto l82;
  case 57:
    goto l82;
  case 58:
    OOC_SSA_WriteC__WriteExpr_CopyParameter((OOC_SSA__Address)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37041)))), &_td_OOC_SSA__AddressDesc, 37041)));
    goto l82;
  case 59:
    OOC_SSA_WriteC__WriteExpr_NewObject((OOC_SSA__Instr)i0);
    goto l82;
  case 60:
    OOC_SSA_WriteC__WriteExpr_NewBlock((OOC_SSA__Instr)i0);
    goto l82;
  case 61:
    OOC_SSA_WriteC__WriteExpr_TypeTag((OOC_SSA__Instr)i0);
    goto l82;
  case 62:
    OOC_SSA_WriteC__WriteExpr_TypeTest((OOC_SSA__Instr)i0);
    goto l82;
  case 63:
    OOC_SSA_WriteC__WriteExpr_TBProcAddress((OOC_SSA__Instr)i0);
    goto l82;
  case 87:
    OOC_SSA_WriteC__WriteExpr_VTableProcAddress((OOC_SSA__Instr)i0);
    goto l82;
  case 41:
    OOC_SSA_WriteC__WriteExpr_TypeCast((OOC_SSA__Instr)i0);
    goto l82;
  case 42:
    OOC_SSA_WriteC__WriteExpr_TypeConv((OOC_SSA__Instr)i0);
    goto l82;
  case 19:
    OOC_SSA_WriteC__WriteExpr_WriteDyadicOp((OOC_SSA__Instr)i0, "+", 2);
    goto l82;
  case 20:
    OOC_SSA_WriteC__WriteExpr_WriteDyadicOp((OOC_SSA__Instr)i0, "-", 2);
    goto l82;
  case 21:
    OOC_SSA_WriteC__WriteExpr_WriteMonadicOp((OOC_SSA__Instr)i0, "-", 2, "", 1);
    goto l82;
  case 22:
    OOC_SSA_WriteC__WriteExpr_WriteDyadicOp((OOC_SSA__Instr)i0, "*", 2);
    goto l82;
  case 23:
    i1 = *(OOC_INT8*)((_check_pointer(i0, 37732))+5);
    i1 = i1<5;
    if (i1) goto l35;
    OOC_SSA_WriteC__WriteExpr_WriteDyadicOp((OOC_SSA__Instr)i0, "/", 2);
    goto l82;
l35:
    OOC_SSA_WriteC__WriteExpr_WriteDyadicFct((OOC_SSA__Instr)i0, "_div", 5);
    goto l82;
  case 24:
    OOC_SSA_WriteC__WriteExpr_WriteDyadicFct((OOC_SSA__Instr)i0, "_mod", 5);
    goto l82;
  case 31:
    OOC_SSA_WriteC__WriteExpr_WriteDyadicOp((OOC_SSA__Instr)i0, "&&", 3);
    goto l82;
  case 32:
    OOC_SSA_WriteC__WriteExpr_WriteDyadicOp((OOC_SSA__Instr)i0, "||", 3);
    goto l82;
  case 33:
    OOC_SSA_WriteC__WriteExpr_WriteMonadicOp((OOC_SSA__Instr)i0, "!", 2, "", 1);
    goto l82;
  case 34:
    OOC_SSA_WriteC__WriteExpr_WriteDyadicOp((OOC_SSA__Instr)i0, "&", 2);
    goto l82;
  case 35:
    OOC_SSA_WriteC__WriteExpr_WriteDyadicOp((OOC_SSA__Instr)i0, "|", 2);
    goto l82;
  case 36:
    OOC_SSA_WriteC__WriteExpr_WriteDyadicOp((OOC_SSA__Instr)i0, "^", 2);
    goto l82;
  case 38:
    OOC_SSA_WriteC__WriteExpr_WriteDyadicFct((OOC_SSA__Instr)i0, "_logical_subtr", 15);
    goto l82;
  case 37:
    OOC_SSA_WriteC__WriteExpr_WriteMonadicOp((OOC_SSA__Instr)i0, "~", 2, "", 1);
    goto l82;
  case 39:
    OOC_SSA_WriteC__WriteExpr_WriteDyadicFct((OOC_SSA__Instr)i0, "_set_bit", 9);
    goto l82;
  case 40:
    OOC_SSA_WriteC__WriteExpr_WriteDyadicFct((OOC_SSA__Instr)i0, "_clear_bit", 11);
    goto l82;
  case 43:
    OOC_SSA_WriteC__WriteExpr_WriteDyadicFct((OOC_SSA__Instr)i0, "_in", 4);
    goto l82;
  case 44:
    OOC_SSA_WriteC__WriteExpr_WriteDyadicFct((OOC_SSA__Instr)i0, "_bit_range", 11);
    goto l82;
  case 45:
    OOC_SSA_WriteC__WriteExpr_WriteMonadicOp((OOC_SSA__Instr)i0, "_abs(", 6, ")", 2);
    goto l82;
  case 46:
    OOC_SSA_WriteC__WriteExpr_WriteDyadicOp((OOC_SSA__Instr)i0, "<<", 3);
    goto l82;
  case 47:
    OOC_SSA_WriteC__WriteExpr_WriteDyadicOp((OOC_SSA__Instr)i0, ">>", 3);
    goto l82;
  case 48:
    OOC_SSA_WriteC__WriteExpr_WriteDyadicFct((OOC_SSA__Instr)i0, "_ash", 5);
    goto l82;
  case 49:
    OOC_SSA_WriteC__WriteExpr_WriteMonadicOp((OOC_SSA__Instr)i0, "_cap(", 6, ")", 2);
    goto l82;
  case 50:
    OOC_SSA_WriteC__WriteExpr_WriteMonadicOp((OOC_SSA__Instr)i0, "_entier(", 9, ")", 2);
    goto l82;
  case 51:
    OOC_SSA_WriteC__WriteExpr_Indexed((OOC_SSA__Instr)i0);
    goto l82;
  case 52:
    OOC_SSA_WriteC__WriteExpr_Shift((OOC_SSA__Instr)i0, 0u);
    goto l82;
  case 53:
    OOC_SSA_WriteC__WriteExpr_Shift((OOC_SSA__Instr)i0, 1u);
    goto l82;
  case 54:
    OOC_SSA_WriteC__WriteExpr_WriteMonadicOp((OOC_SSA__Instr)i0, "_odd(", 6, ")", 2);
    goto l82;
  case 25:
    OOC_SSA_WriteC__WriteExpr_WriteDyadicOp((OOC_SSA__Instr)i0, "==", 3);
    goto l82;
  case 26:
    OOC_SSA_WriteC__WriteExpr_WriteDyadicOp((OOC_SSA__Instr)i0, "!=", 3);
    goto l82;
  case 27:
    OOC_SSA_WriteC__WriteExpr_WriteDyadicOpU((OOC_SSA__Instr)i0, "<", 2);
    goto l82;
  case 28:
    OOC_SSA_WriteC__WriteExpr_WriteDyadicOpU((OOC_SSA__Instr)i0, "<=", 3);
    goto l82;
  case 29:
    OOC_SSA_WriteC__WriteExpr_WriteDyadicOpU((OOC_SSA__Instr)i0, ">", 2);
    goto l82;
  case 30:
    OOC_SSA_WriteC__WriteExpr_WriteDyadicOpU((OOC_SSA__Instr)i0, ">=", 3);
    goto l82;
  case 64:
    OOC_SSA_WriteC__WriteExpr_Assert((OOC_SSA__Instr)i0);
    goto l82;
  case 65:
    i1 = (OOC_INT32)w;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 39651)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i1);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 39669)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "_halt(", 7);
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 39714))+24);
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 39724))+8);
    OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i1, (OOC_SSA__Opnd)i0);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 39744)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, ")", 2);
    goto l82;
  case 66:
    OOC_SSA_WriteC__WriteExpr_CheckIndex((OOC_SSA__Instr)i0);
    goto l82;
  case 67:
    OOC_SSA_WriteC__WriteExpr_CheckPointer((OOC_SSA__Instr)i0);
    goto l82;
  case 68:
    OOC_SSA_WriteC__WriteExpr_TypeGuard((OOC_SSA__Instr)i0);
    goto l82;
  case 69:
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 39991))+24);
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 40001))+8);
    OOC_SSA_WriteC__WriteExpr_FailedCheck((OOC_SSA__Instr)i0, "_failed_case", 13, (OOC_SSA__Opnd)i1);
    goto l82;
  case 70:
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 40086))+24);
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 40096))+8);
    OOC_SSA_WriteC__WriteExpr_FailedCheck((OOC_SSA__Instr)i0, "_failed_with", 13, (OOC_SSA__Opnd)i1);
    goto l82;
  case 71:
    OOC_SSA_WriteC__WriteExpr_FailedCheck((OOC_SSA__Instr)i0, "_failed_type_assert", 20, (OOC_SSA__Opnd)(OOC_INT32)0);
    goto l82;
  case 55:
    i1 = (OOC_INT32)w;
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 40232))+96);
    i2 = ADT_Dictionary__DictionaryDesc_HasKey((ADT_Dictionary__Dictionary)i2, (Object__Object)i0);
    i2 = !i2;
    if (i2) goto l77;
    OOC_SSA_WriteC__WriteExpr_CastFromPtr((OOC_SSA__Result)i0);
    goto l78;
l77:
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 40276)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i1);
l78:
    i0 = (OOC_INT32)instr;
    OOC_SSA_WriteC__WriteExpr_Call((OOC_SSA__Instr)i0);
    goto l82;
  case 76:
    OOC_SSA_WriteC__WriteExpr_CastFromPtr((OOC_SSA__Result)i0);
    i0 = (OOC_INT32)w;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 40423)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "Exception__Current()", 21);
    goto l82;
  case 81:
    OOC_SSA_WriteC__WriteExpr_PreloadedVar((OOC_SSA__Instr)i0);
    goto l82;
  default:
    _failed_case(i1, 35539);
    goto l82;
  }
l82:
  return;
  ;
}

void OOC_SSA_WriteC__WriterDesc_WriteInstrList(OOC_SSA_WriteC__Writer w, OOC_SSA_Schedule__Block b) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_SSA_Schedule__InstrProxy proxy;
  OOC_SSA__Instr instr;
  Object__Object target;
  OOC_SSA__Opnd opnd;
  OOC_SymbolTable__FormalPars fpars;
  Object__Object obj;
  auto void OOC_SSA_WriteC__WriterDesc_WriteInstrList_WriteCollect(OOC_SSA__Instr collect, OOC_SSA__Instr targetInstr);
  auto void OOC_SSA_WriteC__WriterDesc_WriteInstrList_PrefixReturn(void);
  auto OOC_CHAR8 OOC_SSA_WriteC__WriterDesc_WriteInstrList_AllPathsClosed(OOC_SSA__Instr selectReturn);
    
    void OOC_SSA_WriteC__WriterDesc_WriteInstrList_WriteCollect(OOC_SSA__Instr collect, OOC_SSA__Instr targetInstr) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
      OOC_SSA__Opnd opnd;
      OOC_SSA__Result res;
      Object__Object targetVar;
      Object__Object sourceVar;
      OOC_INT32 i;

      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 40988)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i0);
      i0 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_ClearSwapData((OOC_SSA_WriteC__Writer)i0);
      i0 = (OOC_INT32)collect;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 41164))+24);
      opnd = (OOC_SSA__Opnd)i1;
      i2 = (OOC_INT32)targetInstr;
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 41200));
      res = (OOC_SSA__Result)i3;
      i4 = i1!=0;
      if (i4) goto l3;
      i4=0u;
      goto l5;
l3:
      i4 = OOC_SSA__OpndDesc_IsScheduleOpnd((OOC_SSA__Opnd)i1);
      i4 = !i4;
      
l5:
      if (!i4) goto l22;
l7_loop:
      i4 = *(OOC_INT8*)((_check_pointer(i1, 41284))+4);
      i4 = i4!=2;
      if (!i4) goto l13;
      i4 = (OOC_INT32)w;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 41335))+96);
      i4 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i4, (Object__Object)i3);
      targetVar = (Object__Object)i4;
      i5 = (OOC_INT32)w;
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 41375))+96);
      i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 41402));
      i5 = ADT_Dictionary__DictionaryDesc_HasKey((ADT_Dictionary__Dictionary)i5, (Object__Object)i6);
      if (!i5) goto l13;
      i5 = (OOC_INT32)w;
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 41440))+96);
      i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 41464));
      i5 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i5, (Object__Object)i6);
      sourceVar = (Object__Object)i5;
      i6 = OOC_SSA_WriteC__SubclassToBasicType((OOC_SSA__Result)i3);
      i7 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_AddSwapData((OOC_SSA_WriteC__Writer)i7, (Object__String)(_type_guard(i5, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 41510)))), &_td_Object__StringDesc, 41510)), (Object__String)(_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 41557)))), &_td_Object__StringDesc, 41557)), i6);
l13:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 41669))+8);
      opnd = (OOC_SSA__Opnd)i1;
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 41691));
      res = (OOC_SSA__Result)i3;
      i4 = i1!=0;
      if (i4) goto l16;
      i4=0u;
      goto l18;
l16:
      i4 = OOC_SSA__OpndDesc_IsScheduleOpnd((OOC_SSA__Opnd)i1);
      i4 = !i4;
      
l18:
      if (i4) goto l7_loop;
l22:
      i1 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_CountReadsSwapData((OOC_SSA_WriteC__Writer)i1);
      i1 = (OOC_INT32)w;
      i1 = *(OOC_INT32*)((_check_pointer(i1, 41881))+112);
      i1 = i1!=0;
      if (!i1) goto l51;
l25_loop:
      i = 0;
      i1 = (OOC_INT32)w;
      i3 = *(OOC_INT32*)((_check_pointer(i1, 41943))+112);
      i3 = 0!=i3;
      if (i3) goto l28;
      i3=0u;
      goto l30;
l28:
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 41966))+108);
      i3 = _check_pointer(i3, 41977);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = *(OOC_INT32*)((i3+((_check_index(0, i4, OOC_UINT32, 41977))*16))+8);
      i3 = i3!=0;
      
l30:
      if (i3) goto l32;
      i3=0;
      goto l42;
l32:
      i3=0;
l33_loop:
      i3 = i3+1;
      i = i3;
      i4 = *(OOC_INT32*)((_check_pointer(i1, 41943))+112);
      i4 = i3!=i4;
      if (i4) goto l36;
      i4=0u;
      goto l38;
l36:
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 41966))+108);
      i4 = _check_pointer(i4, 41977);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = *(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 41977))*16))+8);
      i4 = i4!=0;
      
l38:
      if (i4) goto l33_loop;
l42:
      i4 = *(OOC_INT32*)((_check_pointer(i1, 42049))+112);
      i4 = i3==i4;
      if (i4) goto l45;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 42208))+108);
      i4 = _check_pointer(i4, 42219);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 42219))*16))+4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 42192)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i1, (Object__Object)i4);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 42242)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "=", 2);
      i1 = (OOC_INT32)w;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 42290))+108);
      i4 = _check_pointer(i4, 42301);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+((_check_index(i3, i5, OOC_UINT32, 42301))*16));
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 42274)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i1, (Object__Object)i4);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 42326)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 59u);
      i1 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_RemoveSwapData((OOC_SSA_WriteC__Writer)i1, i3);
      goto l46;
l45:
      OOC_SSA_WriteC__WriterDesc_IntroduceHelperVar((OOC_SSA_WriteC__Writer)i1, 0);
l46:
      i1 = (OOC_INT32)w;
      i1 = *(OOC_INT32*)((_check_pointer(i1, 41881))+112);
      i1 = i1!=0;
      if (i1) goto l25_loop;
l51:
      i1 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_FixupHelperVars((OOC_SSA_WriteC__Writer)i1);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 42533))+24);
      opnd = (OOC_SSA__Opnd)i0;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 42569));
      res = (OOC_SSA__Result)i1;
      i2 = i0!=0;
      if (i2) goto l54;
      i2=0u;
      goto l56;
l54:
      i2 = OOC_SSA__OpndDesc_IsScheduleOpnd((OOC_SSA__Opnd)i0);
      i2 = !i2;
      
l56:
      if (!i2) goto l73;
l58_loop:
      i2 = *(OOC_INT8*)((_check_pointer(i0, 42653))+4);
      i2 = i2!=2;
      if (!i2) goto l64;
      i2 = (OOC_INT32)w;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 42704))+96);
      i2 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i2, (Object__Object)i1);
      targetVar = (Object__Object)i2;
      i3 = (OOC_INT32)w;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 42745))+96);
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 42772));
      i3 = ADT_Dictionary__DictionaryDesc_HasKey((ADT_Dictionary__Dictionary)i3, (Object__Object)i4);
      i3 = !i3;
      if (!i3) goto l64;
      i3 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 42797)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i3, (Object__Object)i2);
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 42837)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i2, "=", 2);
      i2 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i2, (OOC_SSA__Opnd)i0);
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 42898)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i2, 59u);
l64:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 42964))+8);
      opnd = (OOC_SSA__Opnd)i0;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 42986));
      res = (OOC_SSA__Result)i1;
      i2 = i0!=0;
      if (i2) goto l67;
      i2=0u;
      goto l69;
l67:
      i2 = OOC_SSA__OpndDesc_IsScheduleOpnd((OOC_SSA__Opnd)i0);
      i2 = !i2;
      
l69:
      if (i2) goto l58_loop;
l73:
      return;
      ;
    }

    
    void OOC_SSA_WriteC__WriterDesc_WriteInstrList_PrefixReturn(void) {
      register OOC_INT32 i0;

      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 43127)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i0);
      return;
      ;
    }

    
    OOC_CHAR8 OOC_SSA_WriteC__WriterDesc_WriteInstrList_AllPathsClosed(OOC_SSA__Instr selectReturn) {
      register OOC_INT32 i0,i1;
      OOC_SSA__Opnd opnd;

      i0 = (OOC_INT32)selectReturn;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 43640))+24);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 43650))+8);
      opnd = (OOC_SSA__Opnd)i0;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 43679))+8);
      i1 = i1!=(OOC_INT32)0;
      if (!i1) goto l9;
l4_loop:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 43720))+8);
      opnd = (OOC_SSA__Opnd)i0;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 43679))+8);
      i1 = i1!=(OOC_INT32)0;
      if (i1) goto l4_loop;
l9:
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 43761));
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 43766))+8);
      i0 = *(OOC_INT8*)((_check_pointer(i0, 43773))+36);
      return (i0==7);
      ;
    }


  i0 = (OOC_INT32)b;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 43847))+8);
  proxy = (OOC_SSA_Schedule__InstrProxy)i0;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l65;
l3_loop:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 43907))+12);
  instr = (OOC_SSA__Instr)i0;
  target = (Object__Object)(OOC_INT32)0;
  i1 = (OOC_INT32)w;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 44144))+96);
  i2 = ADT_Dictionary__DictionaryDesc_HasKey((ADT_Dictionary__Dictionary)i2, (Object__Object)i0);
  if (i2) goto l6;
  i2=(OOC_INT32)0;
  goto l10;
l6:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 44198))+96);
  i2 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i2, (Object__Object)i0);
  target = (Object__Object)i2;
  i3 = (OOC_INT32)OOC_SSA_Allocator__markInPlace;
  i3 = i2!=i3;
  if (!i3) goto l10;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 44286)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 44451)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i1, (Object__Object)i2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 44486)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, " = ", 4);
l10:
  i3 = (OOC_INT32)OOC_SSA_Allocator__markInPlace;
  i2 = i2!=i3;
  if (!i2) goto l60;
  i2 = *(OOC_INT8*)((_check_pointer(i0, 44746))+36);
  switch (i2) {
  case 0:
    goto l60;
  case 1:
    goto l60;
  case 2:
    goto l60;
  case 3:
    goto l60;
  case 4:
    goto l60;
  case 5:
    goto l60;
  case 82:
    goto l60;
  case 84:
    goto l60;
  case 10:
    goto l60;
  case 11:
    goto l60;
  case 9:
    goto l60;
  case 6:
    i1 = (OOC_INT32)OOC_SSA__InstrDesc_GetCollectTarget((OOC_SSA__Instr)i0);
    OOC_SSA_WriteC__WriterDesc_WriteInstrList_WriteCollect((OOC_SSA__Instr)i0, (OOC_SSA__Instr)i1);
    goto l60;
  case 7:
    OOC_SSA_WriteC__WriterDesc_WriteInstrList_PrefixReturn();
    i0 = (OOC_INT32)instr;
    i0 = (OOC_INT32)OOC_SSA__InstrDesc_GetOpndClass((OOC_SSA__Instr)i0, 9);
    opnd = (OOC_SSA__Opnd)i0;
    i1 = i0!=(OOC_INT32)0;
    if (i1) goto l29;
    i0 = (OOC_INT32)w;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 45955)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "return", 7);
    
    goto l30;
l29:
    i1 = (OOC_INT32)w;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 45757)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "return ", 8);
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 45845))+104);
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 45856))+20);
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 45866))+64);
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 45878))+44);
    i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 45814));
    OOC_SSA_WriteC__CastToPtr((OOC_SSA_WriteC__Writer)i1, (OOC_SSA__Result)i3, (OOC_SymbolTable__Type)i2, 0u);
    OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i1, (OOC_SSA__Opnd)i0);
    i0=i1;
l30:
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 46006)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i0, 59u);
    goto l60;
  case 8:
    i0 = OOC_SSA_WriteC__WriterDesc_WriteInstrList_AllPathsClosed((OOC_SSA__Instr)i0);
    i0 = !i0;
    if (!i0) goto l60;
    OOC_SSA_WriteC__WriterDesc_WriteInstrList_PrefixReturn();
    i0 = (OOC_INT32)w;
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 46156))+104);
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 46166))+20);
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 46175))+64);
    fpars = (OOC_SymbolTable__FormalPars)i1;
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 46209))+44);
    i2 = i2!=(OOC_INT32)0;
    if (i2) goto l39;
    i1 = *(OOC_UINT8*)((_check_pointer(i1, 46598))+57);
    i1 = !i1;
    if (!i1) goto l60;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 46628)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "return;", 8);
    goto l60;
l39:
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 46251))+104);
    i2 = *(OOC_UINT8*)((_check_pointer(i2, 46262))+24);
    if (!i2) goto l42;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 46306)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "_failed_function(", 18);
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 46374))+104);
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 46385))+20);
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 46395))+20);
    i2 = *(OOC_INT32*)(_check_pointer(i2, 46401));
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 46360)))), OOC_C_DeclWriter__WriterDesc_WriteLInt)),OOC_C_DeclWriter__WriterDesc_WriteLInt)((OOC_C_DeclWriter__Writer)i0, i2, 0);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 46429)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "); ", 4);
l42:
    i1 = *(OOC_UINT8*)((_check_pointer(i1, 46494))+57);
    i1 = !i1;
    if (!i1) goto l60;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 46526)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "return 0;", 10);
    goto l60;
  case 72:
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 46735)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i1);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 46756)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "{", 2);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 46786)))), OOC_C_DeclWriter__WriterDesc_Indent)),OOC_C_DeclWriter__WriterDesc_Indent)((OOC_C_DeclWriter__Writer)i1, 1);
    goto l60;
  case 73:
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 46834)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, ";", 2);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 46864)))), OOC_C_DeclWriter__WriterDesc_Indent)),OOC_C_DeclWriter__WriterDesc_Indent)((OOC_C_DeclWriter__Writer)i1, (-1));
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 46888)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i1);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 46909)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "}", 2);
    goto l60;
  case 74:
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 46972)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i1);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 46993)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "Exception__Raise((void*)", 25);
    i0 = (OOC_INT32)OOC_SSA__InstrDesc_NthOpnd((OOC_SSA__Instr)i0, 1);
    OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i1, (OOC_SSA__Opnd)i0);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 47081)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, ");", 3);
    goto l60;
  case 78:
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 47151)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i1);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 47172)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "Exception__PushContext(&", 25);
    i0 = (OOC_INT32)OOC_SSA_WriteC__WriteExceptionContext((OOC_SSA_WriteC__Writer)i1, (OOC_SSA__Instr)i0);
    obj = (Object__Object)i0;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 47275)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, ", &_target", 11);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 47314)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i1, (Object__Object)i0);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 47344)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, ");", 3);
    goto l60;
  case 79:
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 47413)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i1);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 47434)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "Exception__PopContext(", 23);
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 47507))+24);
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 47516))+8);
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 47525));
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 47534)))), &_td_OOC_SSA__ConstDesc, 47534)), 47540))+44);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 47485)))), OOC_C_DeclWriter__WriterDesc_WriteBasicConst)),OOC_C_DeclWriter__WriterDesc_WriteBasicConst)((OOC_C_DeclWriter__Writer)i1, (Object_Boxed__Object)i0, 4);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 47606)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, ");", 3);
    goto l60;
  case 77:
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 47670)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i1);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 47691)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "Exception__Clear();", 20);
    goto l60;
  case 80:
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 47773)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i1);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 47794)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "Exception__ActivateContext();", 30);
    goto l60;
  default:
    OOC_SSA_WriteC__WriteExpr((OOC_SSA_WriteC__Writer)i1, (OOC_SSA__Instr)i0);
    i0 = OOC_SSA__InstrDesc_IsConst((OOC_SSA__Instr)i0);
    i0 = !i0;
    if (!i0) goto l60;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 47977)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 59u);
    goto l60;
  }
l60:
  i0 = (OOC_INT32)proxy;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 48062));
  proxy = (OOC_SSA_Schedule__InstrProxy)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l3_loop;
l65:
  return;
  ;
}

void OOC_SSA_WriteC__WriterDesc_WriteBlocks(OOC_SSA_WriteC__Writer w, OOC_SSA_Schedule__Block domRoot) {
  register OOC_INT32 i0;
  OOC_SSA_Schedule__Block registeredGoto;
  auto void OOC_SSA_WriteC__WriterDesc_WriteBlocks_WriteBlockId(OOC_SSA_Schedule__Block b);
  auto void OOC_SSA_WriteC__WriterDesc_WriteBlocks_WriteGoto(OOC_SSA_Schedule__Block target);
  auto void OOC_SSA_WriteC__WriterDesc_WriteBlocks_WriteBlock(OOC_SSA_Schedule__Block b);
    
    void OOC_SSA_WriteC__WriterDesc_WriteBlocks_WriteBlockId(OOC_SSA_Schedule__Block b) {
      register OOC_INT32 i0,i1,i2;

      i0 = (OOC_INT32)b;
      i1 = i0==(OOC_INT32)0;
      if (i1) goto l6;
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 48534)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "l", 2);
      i1 = (OOC_INT32)w;
      i2 = *(OOC_INT32*)((_check_pointer(i0, 48578))+40);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 48564)))), OOC_C_DeclWriter__WriterDesc_WriteLInt)),OOC_C_DeclWriter__WriterDesc_WriteLInt)((OOC_C_DeclWriter__Writer)i1, i2, 0);
      i0 = *(OOC_UINT8*)((_check_pointer(i0, 48600))+28);
      if (!i0) goto l7;
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 48629)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "_loop", 6);
      goto l7;
l6:
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 48473)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "XXX WriteBlockId(NIL)", 22);
l7:
      return;
      ;
    }

    
    void OOC_SSA_WriteC__WriterDesc_WriteBlocks_WriteGoto(OOC_SSA_Schedule__Block target) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)target;
      i1 = i0==(OOC_INT32)0;
      if (i1) goto l3;
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 48862)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "goto ", 6);
      OOC_SSA_WriteC__WriterDesc_WriteBlocks_WriteBlockId((OOC_SSA_Schedule__Block)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 48927)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i0, 59u);
      goto l4;
l3:
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 48799)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "/* goto: unreachable */", 24);
l4:
      return;
      ;
    }

    
    void OOC_SSA_WriteC__WriterDesc_WriteBlocks_WriteBlock(OOC_SSA_Schedule__Block b) {
      register OOC_INT32 i0,i1,i2,i3,i4;
      OOC_INT32 d;
      OOC_SSA_Schedule__Block nested;
      OOC_INT32 i;
      auto void OOC_SSA_WriteC__WriterDesc_WriteBlocks_WriteBlock_WriteNested(OOC_SSA_Schedule__Block nested);
      auto void OOC_SSA_WriteC__WriterDesc_WriteBlocks_WriteBlock_WriteCases(OOC_SSA__Instr instr);
        
        void OOC_SSA_WriteC__WriterDesc_WriteBlocks_WriteBlock_WriteNested(OOC_SSA_Schedule__Block nested) {
          register OOC_INT32 i0,i1;

          i0 = (OOC_INT32)nested;
          i1 = i0!=(OOC_INT32)0;
          if (!i1) goto l8;
          
l3_loop:
          OOC_SSA_WriteC__WriterDesc_WriteBlocks_WriteBlock((OOC_SSA_Schedule__Block)i0);
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 49242));
          nested = (OOC_SSA_Schedule__Block)i0;
          i1 = i0!=(OOC_INT32)0;
          if (i1) goto l3_loop;
l8:
          return;
          ;
        }

        
        void OOC_SSA_WriteC__WriterDesc_WriteBlocks_WriteBlock_WriteCases(OOC_SSA__Instr instr) {
          register OOC_INT32 i0,i1,i2,i3;
          OOC_SSA__Opnd opnd;
          OOC_SSA__Opnd lower;
          OOC_SSA__Opnd upper;

          i0 = (OOC_INT32)instr;
          i1 = *(OOC_INT8*)((_check_pointer(i0, 49411))+36);
          i1 = i1==82;
          if (i1) goto l3;
          i0 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 49974)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i0);
          i0 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 49996)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "default:", 9);
          goto l15;
l3:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 49465))+24);
          opnd = (OOC_SSA__Opnd)i0;
          i1 = i0!=(OOC_INT32)0;
          if (!i1) goto l15;
l6_loop:
          lower = (OOC_SSA__Opnd)i0;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 49560))+8);
          opnd = (OOC_SSA__Opnd)i1;
          upper = (OOC_SSA__Opnd)i1;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 49623))+8);
          opnd = (OOC_SSA__Opnd)i2;
          i3 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 49661)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i3);
          i3 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 49685)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i3, "case ", 6);
          i3 = (OOC_INT32)w;
          OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i3, (OOC_SSA__Opnd)i0);
          i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 49772));
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 49759));
          i0 = i0!=i3;
          if (!i0) goto l9;
          i0 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 49799)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, " ... ", 6);
          i0 = (OOC_INT32)w;
          OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i0, (OOC_SSA__Opnd)i1);
l9:
          i0 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 49914)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ":", 2);
          i0 = i2!=(OOC_INT32)0;
          if (!i0) goto l15;
          i0=i2;
          goto l6_loop;
l15:
          return;
          ;
        }


      i0 = (OOC_INT32)b;
      i1 = *(OOC_INT32*)((_check_pointer(i0, 50085))+36);
      i1 = i1!=0;
      if (i1) goto l3;
      i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 50108)))), &_td_OOC_SSA_Schedule__JumpBlockDesc));
      
      goto l5;
l3:
      i1=1u;
l5:
      if (!i1) goto l21;
      i1 = (OOC_INT32)registeredGoto;
      i2 = i1!=(OOC_INT32)0;
      if (i2) goto l9;
      i1=0u;
      goto l11;
l9:
      i1 = i1!=i0;
      
l11:
      if (!i1) goto l13;
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 50209)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i1);
      i1 = (OOC_INT32)registeredGoto;
      OOC_SSA_WriteC__WriterDesc_WriteBlocks_WriteGoto((OOC_SSA_Schedule__Block)i1);
      registeredGoto = (OOC_SSA_Schedule__Block)(OOC_INT32)0;
l13:
      i1 = *(OOC_INT32*)((_check_pointer(i0, 50319))+36);
      d = i1;
      i2 = (OOC_INT32)registeredGoto;
      i2 = i0==i2;
      if (!i2) goto l17;
      i1 = i1-1;
      d = i1;
      
l17:
      i1 = i1!=0;
      if (!i1) goto l20;
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 50435)))), OOC_C_DeclWriter__WriterDesc_WriteLn)),OOC_C_DeclWriter__WriterDesc_WriteLn)((OOC_C_DeclWriter__Writer)i1);
      OOC_SSA_WriteC__WriterDesc_WriteBlocks_WriteBlockId((OOC_SSA_Schedule__Block)i0);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 50485)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 58u);
l20:
      i1 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_WriteInstrList((OOC_SSA_WriteC__Writer)i1, (OOC_SSA_Schedule__Block)i0);
l21:
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 50578)))), &_td_OOC_SSA_Schedule__BranchBlockDesc);
      if (i1) goto l56;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 51249)))), &_td_OOC_SSA_Schedule__SwitchBlockDesc);
      if (i1) goto l37;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 52030)))), &_td_OOC_SSA_Schedule__JumpBlockDesc);
      if (i1) goto l32;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 52230)))), &_td_OOC_SSA_Schedule__DeadEndBlockDesc);
      if (i1) goto l30;
      _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 52227)))), 52227);
      goto l67;
l30:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 52279))+16);
      OOC_SSA_WriteC__WriterDesc_WriteBlocks_WriteBlock_WriteNested((OOC_SSA_Schedule__Block)i0);
      goto l67;
l32:
      i1 = *(OOC_INT32*)((_check_pointer(i0, 52067))+36);
      i1 = i1!=0;
      if (!i1) goto l35;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 52159))+48);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 52165))+4);
      registeredGoto = (OOC_SSA_Schedule__Block)i1;
l35:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 52208))+16);
      OOC_SSA_WriteC__WriterDesc_WriteBlocks_WriteBlock_WriteNested((OOC_SSA_Schedule__Block)i0);
      goto l67;
l37:
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 51284)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 51304)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "switch (", 9);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 51349))+48);
      i2 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i2, (OOC_SSA__Opnd)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 51367)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, ") {", 4);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 51420))+16);
      nested = (OOC_SSA_Schedule__Block)i1;
      i = 0;
      i2 = i1!=(OOC_INT32)0;
      if (i2) goto l40;
      i2=0u;
      goto l42;
l40:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 51481))+52);
      i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 51487)), 0);
      i2 = 0!=i2;
      
l42:
      if (i2) goto l44;
      i0=i1;
      goto l54;
l44:
      {register OOC_INT32 h0=i0;i0=i1;i1=h0;}i2=0;
l45_loop:
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 51522))+52);
      i3 = _check_pointer(i3, 51528);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 51528))*4);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 51531))+4);
      _assert((i0==i3), 127, 51504);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 51563))+60);
      i0 = _check_pointer(i0, 51575);
      i1 = OOC_ARRAY_LENGTH(i0, 0);
      i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(i2, i1, OOC_UINT32, 51575))*4);
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 51578));
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 51583))+8);
      OOC_SSA_WriteC__WriterDesc_WriteBlocks_WriteBlock_WriteCases((OOC_SSA__Instr)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 51615)))), OOC_C_DeclWriter__WriterDesc_Indent)),OOC_C_DeclWriter__WriterDesc_Indent)((OOC_C_DeclWriter__Writer)i0, 1);
      i0 = (OOC_INT32)b;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 51658))+52);
      i1 = _check_pointer(i1, 51664);
      i2 = OOC_ARRAY_LENGTH(i1, 0);
      i3 = i;
      i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(i3, i2, OOC_UINT32, 51664))*4);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 51667))+4);
      registeredGoto = (OOC_SSA_Schedule__Block)i1;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 51698))+52);
      i1 = _check_pointer(i1, 51704);
      i2 = OOC_ARRAY_LENGTH(i1, 0);
      i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(i3, i2, OOC_UINT32, 51704))*4);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 51707))+4);
      OOC_SSA_WriteC__WriterDesc_WriteBlocks_WriteBlock((OOC_SSA_Schedule__Block)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 51727)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i1);
      i1 = (OOC_INT32)registeredGoto;
      OOC_SSA_WriteC__WriterDesc_WriteBlocks_WriteGoto((OOC_SSA_Schedule__Block)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 51787)))), OOC_C_DeclWriter__WriterDesc_Indent)),OOC_C_DeclWriter__WriterDesc_Indent)((OOC_C_DeclWriter__Writer)i1, (-1));
      i1 = (OOC_INT32)nested;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 51828));
      nested = (OOC_SSA_Schedule__Block)i1;
      i2 = i3+1;
      i = i2;
      i3 = i1!=(OOC_INT32)0;
      if (i3) goto l48;
      i3=0u;
      goto l50;
l48:
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 51481))+52);
      i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 51487)), 0);
      i3 = i2!=i3;
      
l50:
      if (!i3) goto l53;
      {register OOC_INT32 h0=i0;i0=i1;i1=h0;}
      goto l45_loop;
l53:
      i0=i1;
l54:
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 51883));
      _assert((i1==(OOC_INT32)0), 127, 51869);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 51910)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 51930)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "}", 2);
      registeredGoto = (OOC_SSA_Schedule__Block)(OOC_INT32)0;
      OOC_SSA_WriteC__WriterDesc_WriteBlocks_WriteBlock_WriteNested((OOC_SSA_Schedule__Block)i0);
      goto l67;
l56:
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 50613)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 50633)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "if (", 5);
      i1 = (OOC_INT32)OOC_SSA_Schedule__BranchBlockDesc_DefaultTarget((OOC_SSA_Schedule__BranchBlock)i0);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 50691))+48);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 50697))+4);
      i1 = i1==i2;
      if (i1) goto l62;
      i1 = *(OOC_UINT8*)((_check_pointer(i0, 50968))+56);
      if (!i1) goto l61;
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 51001)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 33u);
l61:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 51053))+52);
      i2 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i2, (OOC_SSA__Opnd)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 51078)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, ") ", 3);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 51122))+48);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 51128))+4);
      OOC_SSA_WriteC__WriterDesc_WriteBlocks_WriteGoto((OOC_SSA_Schedule__Block)i1);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 51166))+60);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 51176))+4);
      registeredGoto = (OOC_SSA_Schedule__Block)i1;
      goto l66;
l62:
      i1 = *(OOC_UINT8*)((_check_pointer(i0, 50725))+56);
      i1 = !i1;
      if (!i1) goto l65;
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 50758)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 33u);
l65:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 50810))+52);
      i2 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i2, (OOC_SSA__Opnd)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 50835)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, ") ", 3);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 50879))+60);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 50889))+4);
      OOC_SSA_WriteC__WriterDesc_WriteBlocks_WriteGoto((OOC_SSA_Schedule__Block)i1);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 50927))+48);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 50933))+4);
      registeredGoto = (OOC_SSA_Schedule__Block)i1;
l66:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 51219))+16);
      OOC_SSA_WriteC__WriterDesc_WriteBlocks_WriteBlock_WriteNested((OOC_SSA_Schedule__Block)i0);
l67:
      return;
      ;
    }


  i0 = (OOC_INT32)domRoot;
  registeredGoto = (OOC_SSA_Schedule__Block)i0;
  OOC_SSA_WriteC__WriterDesc_WriteBlocks_WriteBlock((OOC_SSA_Schedule__Block)i0);
  return;
  ;
}

void OOC_SSA_WriteC__TranslatorDesc_WriteProcBody(volatile OOC_SSA_WriteC__Translator t, volatile OOC_IR__Procedure proc) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  volatile OOC_SSA__ProcBlock pb;
  volatile OOC_CHAR8 writeProc;
  volatile OOC_SSA__Instr enter;
  volatile OOC_SSA__Result s;
  volatile OOC_SSA_Destore__State destore;
  volatile ADT_Dictionary__Dictionary jmpbufMap;
  volatile OOC_SSA_Schedule__Block domRoot;
  volatile ADT_Dictionary__Dictionary registerMap;
  volatile OOC_SSA_WriteC__Writer w;
  volatile OOC_SSA__Instr instr;
  volatile OOC_INT32 dummy;
  auto void OOC_SSA_WriteC__TranslatorDesc_WriteProcBody_WriteJmpBufDecl(ADT_Dictionary__Dictionary jmpbufMap);
  auto void OOC_SSA_WriteC__TranslatorDesc_WriteProcBody_Write(const OOC_CHAR8 pre__ref[], OOC_LEN pre_0d, const OOC_CHAR8 post__ref[], OOC_LEN post_0d, OOC_CHAR8 addToStats);
  auto void OOC_SSA_WriteC__TranslatorDesc_WriteProcBody_JumpChaining(OOC_SSA_Schedule__Block b);
  auto void OOC_SSA_WriteC__TranslatorDesc_WriteProcBody_FixCrossJumps(OOC_SSA_Schedule__Block b);
  auto void OOC_SSA_WriteC__TranslatorDesc_WriteProcBody_InitPreloadedVars(ADT_Dictionary_IntValue__Dictionary vars);
  jmp_buf _target0;
  Exception__Context _context0;
    
    void OOC_SSA_WriteC__TranslatorDesc_WriteProcBody_WriteJmpBufDecl(ADT_Dictionary__Dictionary jmpbufMap) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_INT32 i;

      i0 = (OOC_INT32)jmpbufMap;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l25;
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 52858)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 52877)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "jmp_buf ", 9);
      i1 = ADT_Dictionary__DictionaryDesc_Size((ADT_Dictionary__Dictionary)i0);
      i = 0;
      i2 = 0<i1;
      if (!i2) goto l13;
      i2=0;
l5_loop:
      i3 = i2!=0;
      if (!i3) goto l8;
      i3 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 52974)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i3, ", ", 3);
l8:
      i3 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 53009)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i3, "_target", 8);
      i3 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 53035)))), OOC_C_DeclWriter__WriterDesc_WriteLInt)),OOC_C_DeclWriter__WriterDesc_WriteLInt)((OOC_C_DeclWriter__Writer)i3, i2, 0);
      i2 = i2+1;
      i = i2;
      i3 = i2<i1;
      if (i3) goto l5_loop;
l13:
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 53075)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, ";", 2);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 53104)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 53123)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "Exception__Context ", 20);
      i0 = ADT_Dictionary__DictionaryDesc_Size((ADT_Dictionary__Dictionary)i0);
      i = 0;
      i1 = 0<i0;
      if (!i1) goto l24;
      i1=0;
l16_loop:
      i2 = i1!=0;
      if (!i2) goto l19;
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 53231)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i2, ", ", 3);
l19:
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 53266)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i2, "_context", 9);
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 53293)))), OOC_C_DeclWriter__WriterDesc_WriteLInt)),OOC_C_DeclWriter__WriterDesc_WriteLInt)((OOC_C_DeclWriter__Writer)i2, i1, 0);
      i1 = i1+1;
      i = i1;
      i2 = i1<i0;
      if (i2) goto l16_loop;
l24:
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 53333)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ";", 2);
l25:
      return;
      ;
    }

    
    void OOC_SSA_WriteC__TranslatorDesc_WriteProcBody_Write(const OOC_CHAR8 pre__ref[], OOC_LEN pre_0d, const OOC_CHAR8 post__ref[], OOC_LEN post_0d, OOC_CHAR8 addToStats) {
      register OOC_INT32 i0,i1;
      OOC_ALLOCATE_VPAR(pre,OOC_CHAR8 ,pre_0d)
      OOC_ALLOCATE_VPAR(post,OOC_CHAR8 ,post_0d)

      OOC_INITIALIZE_VPAR(pre__ref,pre,OOC_CHAR8 ,pre_0d)
      OOC_INITIALIZE_VPAR(post__ref,post,OOC_CHAR8 ,post_0d)
      i0 = writeProc;
      if (i0) goto l3;
      i0=0u;
      goto l9;
l3:
      i0 = (OOC_INT32)t;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 53501))+24);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 53501))+24);
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 53515)))), StringSearch__MatcherDesc_MatchChars)),StringSearch__MatcherDesc_MatchChars)((StringSearch__Matcher)i0, (void*)(OOC_INT32)pre, pre_0d, 0, (-1));
      i0 = i0!=(OOC_INT32)0;
      if (i0) goto l6;
      i0 = (OOC_INT32)t;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 53563))+24);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 53563))+24);
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 53577)))), StringSearch__MatcherDesc_MatchChars)),StringSearch__MatcherDesc_MatchChars)((StringSearch__Matcher)i0, (void*)(OOC_INT32)post, post_0d, 0, (-1));
      i0 = i0!=(OOC_INT32)0;
      
      goto l9;
l6:
      i0=1u;
l9:
      if (!i0) goto l11;
      Err__String("PROCEDURE ", 11);
      i0 = (OOC_INT32)pb;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 53674))+20);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 53684))+20);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 53690))+12);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 53674))+20);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 53684))+20);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 53690))+12);
      i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 53695)), 0);
      Err__String((void*)(_check_pointer(i1, 53695)), i0);
      Err__String("/", 2);
      Err__String((void*)(OOC_INT32)pre, pre_0d);
      Err__String("/", 2);
      Err__String((void*)(OOC_INT32)post, post_0d);
      Err__String(":", 2);
      Err__Ln();
      Err__Flush();
      i0 = (OOC_INT32)IO_StdChannels__stderr;
      i1 = (OOC_INT32)pb;
      OOC_SSA_Blocker__Write((IO__ByteChannel)i0, (OOC_SSA__ProcBlock)i1);
      Err__Flush();
l11:
      i0 = addToStats;
      if (!i0) goto l14;
      i0 = (OOC_INT32)Object__NewLatin1((void*)(OOC_INT32)pre, pre_0d);
      i1 = (OOC_INT32)pb;
      OOC_SSA_Stats__AddProcBlock((Object__String)i0, (OOC_SSA__ProcBlock)i1);
l14:
      return;
      ;
    }

    
    void OOC_SSA_WriteC__TranslatorDesc_WriteProcBody_JumpChaining(OOC_SSA_Schedule__Block b) {
      register OOC_INT32 i0,i1;
      OOC_SSA_Schedule__Block nested;
      auto void OOC_SSA_WriteC__TranslatorDesc_WriteProcBody_JumpChaining_Chain(OOC_SSA_Schedule__Jump *jump);
        
        void OOC_SSA_WriteC__TranslatorDesc_WriteProcBody_JumpChaining_Chain(OOC_SSA_Schedule__Jump *jump) {
          register OOC_INT32 i0,i1,i2;

          i0 = (OOC_INT32)*jump;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 54244))+4);
          i1 = *(OOC_UINT8*)((_check_pointer(i1, 54250))+28);
          i1 = !i1;
          if (i1) goto l3;
          i1=0u;
          goto l5;
l3:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 54298))+4);
          i2 = (OOC_INT32)w;
          i1 = OOC_SSA_WriteC__WriterDesc_EmptyBlock((OOC_SSA_WriteC__Writer)i2, (OOC_SSA_Schedule__Block)i1);
          
l5:
          if (i1) goto l7;
          i1=0u;
          goto l9;
l7:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 54327))+4);
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 54340));
          i1 = i1!=i2;
          
l9:
          if (!i1) goto l24;
l11_loop:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 54435))+4);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 54450)))), &_td_OOC_SSA_Schedule__JumpBlockDesc, 54450)), 54460))+48);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 54465))+4);
          OOC_SSA_Schedule__ChangeJumpTarget((OOC_SSA_Schedule__Jump)i0, (OOC_SSA_Schedule__Block)i1);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 54244))+4);
          i1 = *(OOC_UINT8*)((_check_pointer(i1, 54250))+28);
          i1 = !i1;
          if (i1) goto l14;
          i1=0u;
          goto l16;
l14:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 54298))+4);
          i2 = (OOC_INT32)w;
          i1 = OOC_SSA_WriteC__WriterDesc_EmptyBlock((OOC_SSA_WriteC__Writer)i2, (OOC_SSA_Schedule__Block)i1);
          
l16:
          if (i1) goto l18;
          i1=0u;
          goto l20;
l18:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 54327))+4);
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 54340));
          i1 = i1!=i2;
          
l20:
          if (i1) goto l11_loop;
l24:
          return;
          ;
        }


      i0 = (OOC_INT32)b;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 54530)))), &_td_OOC_SSA_Schedule__BranchBlockDesc);
      if (i1) goto l13;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 54628)))), &_td_OOC_SSA_Schedule__SwitchBlockDesc);
      if (i1) goto l14;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 54717)))), &_td_OOC_SSA_Schedule__JumpBlockDesc);
      if (i1) goto l10;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 54776)))), &_td_OOC_SSA_Schedule__DeadEndBlockDesc);
      if (i1) goto l14;
      _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 54773)))), 54773);
      goto l14;
l10:
      OOC_SSA_WriteC__TranslatorDesc_WriteProcBody_JumpChaining_Chain((void*)((_check_pointer(i0, 54757))+48));
      goto l14;
l13:
      OOC_SSA_WriteC__TranslatorDesc_WriteProcBody_JumpChaining_Chain((void*)((_check_pointer(i0, 54572))+48));
      i0 = (OOC_INT32)b;
      OOC_SSA_WriteC__TranslatorDesc_WriteProcBody_JumpChaining_Chain((void*)((_check_pointer(i0, 54597))+60));
l14:
      i0 = (OOC_INT32)b;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 54860))+16);
      nested = (OOC_SSA_Schedule__Block)i0;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l22;
l17_loop:
      OOC_SSA_WriteC__TranslatorDesc_WriteProcBody_JumpChaining((OOC_SSA_Schedule__Block)i0);
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 54956));
      nested = (OOC_SSA_Schedule__Block)i0;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l17_loop;
l22:
      return;
      ;
    }

    
    void OOC_SSA_WriteC__TranslatorDesc_WriteProcBody_FixCrossJumps(OOC_SSA_Schedule__Block b) {
      register OOC_INT32 i0,i1,i2;
      OOC_SSA_Schedule__Block nested;
      auto void OOC_SSA_WriteC__TranslatorDesc_WriteProcBody_FixCrossJumps_Switch(OOC_CHAR8 *negate, OOC_SSA_Schedule__Jump *j1, OOC_SSA_Schedule__Jump *j2);
        
        void OOC_SSA_WriteC__TranslatorDesc_WriteProcBody_FixCrossJumps_Switch(OOC_CHAR8 *negate, OOC_SSA_Schedule__Jump *j1, OOC_SSA_Schedule__Jump *j2) {
          register OOC_INT32 i0,i1;

          i0 = *negate;
          *negate = (!i0);
          i0 = (OOC_INT32)*j1;
          i1 = (OOC_INT32)*j2;
          *j1 = (OOC_SSA_Schedule__Jump)i1;
          *j2 = (OOC_SSA_Schedule__Jump)i0;
          return;
          ;
        }


      i0 = (OOC_INT32)b;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 55317)))), &_td_OOC_SSA_Schedule__BranchBlockDesc);
      if (!i1) goto l18;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 55356))+60);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 55366))+4);
      i1 = *(OOC_INT32*)((_check_pointer(i1, 55372))+40);
      i2 = *(OOC_INT32*)((_check_pointer(i0, 55380))+40);
      i1 = i1>i2;
      if (i1) goto l5;
      i1=0u;
      goto l7;
l5:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 55401))+48);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 55407))+4);
      i1 = *(OOC_INT32*)((_check_pointer(i1, 55413))+40);
      i2 = *(OOC_INT32*)((_check_pointer(i0, 55422))+40);
      i1 = i1<=i2;
      
l7:
      if (i1) goto l16;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 55576))+60);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 55586))+4);
      i2 = *(OOC_INT32*)((_check_pointer(i0, 55568))+40);
      i1 = *(OOC_INT32*)((_check_pointer(i1, 55592))+40);
      i1 = i2<i1;
      if (i1) goto l11;
      i1=0u;
      goto l13;
l11:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 55616))+60);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 55626))+4);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 55640))+48);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 55646))+4);
      i1 = *(OOC_INT32*)((_check_pointer(i1, 55632))+40);
      i2 = *(OOC_INT32*)((_check_pointer(i2, 55652))+40);
      i1 = i1<i2;
      
l13:
      if (!i1) goto l18;
      OOC_SSA_WriteC__TranslatorDesc_WriteProcBody_FixCrossJumps_Switch((void*)((_check_pointer(i0, 55736))+56), (void*)((_check_pointer(i0, 55753))+60), (void*)((_check_pointer(i0, 55766))+48));
      goto l18;
l16:
      OOC_SSA_WriteC__TranslatorDesc_WriteProcBody_FixCrossJumps_Switch((void*)((_check_pointer(i0, 55513))+56), (void*)((_check_pointer(i0, 55530))+60), (void*)((_check_pointer(i0, 55543))+48));
l18:
      i0 = (OOC_INT32)b;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 55855))+16);
      nested = (OOC_SSA_Schedule__Block)i0;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l26;
l21_loop:
      OOC_SSA_WriteC__TranslatorDesc_WriteProcBody_FixCrossJumps((OOC_SSA_Schedule__Block)i0);
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 55952));
      nested = (OOC_SSA_Schedule__Block)i0;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l21_loop;
l26:
      return;
      ;
    }

    
    void OOC_SSA_WriteC__TranslatorDesc_WriteProcBody_InitPreloadedVars(ADT_Dictionary_IntValue__Dictionary vars) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9;
      Object__ObjectArrayPtr instrList;
      Object__ObjectArrayPtr varList;
      OOC_INT32 i;
      OOC_SSA__Opnd opnd;
      Object__CharsLatin1 chars;
      OOC_INT32 count;

      i0 = (OOC_INT32)vars;
      i1 = (OOC_INT32)ADT_Dictionary_IntValue__DictionaryDesc_Keys((ADT_Dictionary_IntValue__Dictionary)i0);
      instrList = (Object__ObjectArrayPtr)i1;
      i2 = OOC_ARRAY_LENGTH((_check_pointer(i1, 56302)), 0);
      i2 = (OOC_INT32)RT0__NewObject(_td_Object__ObjectArrayPtr.baseTypes[0], i2);
      varList = (Object__ObjectArrayPtr)i2;
      i = 0;
      i3 = OOC_ARRAY_LENGTH((_check_pointer(i1, 56340)), 0);
      i4 = 0<i3;
      if (!i4) goto l8;
      i4=0;
l3_loop:
      i5 = _check_pointer(i2, 56363);
      i6 = _check_pointer(i1, 56382);
      i7 = OOC_ARRAY_LENGTH(i6, 0);
      i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i4, i7, OOC_UINT32, 56382))*4);
      i6 = ADT_Dictionary_IntValue__DictionaryDesc_Get((ADT_Dictionary_IntValue__Dictionary)i0, (Object__Object)i6);
      i7 = OOC_ARRAY_LENGTH(i5, 0);
      i8 = _check_pointer(i1, 56400);
      i9 = OOC_ARRAY_LENGTH(i8, 0);
      i8 = (OOC_INT32)*(OOC_INT32*)(i8+(_check_index(i4, i9, OOC_UINT32, 56400))*4);
      *(OOC_INT32*)(i5+(_check_index(i6, i7, OOC_UINT32, 56363))*4) = i8;
      i4 = i4+1;
      i = i4;
      i5 = i4<i3;
      if (i5) goto l3_loop;
l8:
      i0 = OOC_ARRAY_LENGTH((_check_pointer(i2, 56454)), 0);
      i = 0;
      i1 = 0<i0;
      if (!i1) goto l27;
      i1=0;
l11_loop:
      i3 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 56471)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i3);
      i3 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 56490)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i3, "_c", 3);
      i3 = (OOC_INT32)w;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 56531))+8);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 56531))+8);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 56542)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i3, i1, 0);
      i3 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 56569)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i3, " = ", 4);
      i3 = _check_pointer(i2, 56614);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i1, i4, OOC_UINT32, 56614))*4);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 56622)))), &_td_OOC_SSA__InstrDesc, 56622)), 56628))+24);
      opnd = (OOC_SSA__Opnd)i3;
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 56661));
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 56670)))), &_td_OOC_SSA__ConstDesc, 56670)), 56676))+44);
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 56689)))), &_td_Object_Boxed__StringDesc, 56689)), 56696));
      i4 = (OOC_INT32)Object__String8Desc_CharsLatin1((Object__String8)(_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 56710)))), &_td_Object__String8Desc, 56710)));
      chars = (Object__CharsLatin1)i4;
      i5 = (OOC_INT32)w;
      i6 = OOC_ARRAY_LENGTH((_check_pointer(i4, 56761)), 0);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 56743)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i5, (void*)(_check_pointer(i4, 56761)), i6);
      i4 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 56774)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i4, "(", 2);
      count = 0;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 56833))+8);
      opnd = (OOC_SSA__Opnd)i3;
      i4 = i3!=0;
      if (!i4) goto l22;
      i4=i3;i3=0;
l14_loop:
      i5 = i3!=0;
      if (!i5) goto l17;
      i5 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 56918)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i5, ", ", 3);
l17:
      i5 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i5, (OOC_SSA__Opnd)i4);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 56998))+8);
      opnd = (OOC_SSA__Opnd)i4;
      i3 = i3+1;
      count = i3;
      i5 = i4!=0;
      if (i5) goto l14_loop;
l22:
      i3 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 57055)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i3, ");", 3);
      i1 = i1+1;
      i = i1;
      i3 = i1<i0;
      if (i3) goto l11_loop;
l27:
      return;
      ;
    }


  i0 = (OOC_INT32)proc;
  i1 = (OOC_INT32)OOC_SSA__NewProcBlock((OOC_IR__Procedure)i0);
  pb = (OOC_SSA__ProcBlock)i1;
  i2 = (OOC_INT32)t;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 57235))+20);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 57266))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 57272))+20);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 57278))+12);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 57266))+4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 57272))+20);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 57278))+12);
  i5 = OOC_ARRAY_LENGTH((_check_pointer(i5, 57283)), 0);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 57235))+20);
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 57248)))), StringSearch__MatcherDesc_MatchChars)),StringSearch__MatcherDesc_MatchChars)((StringSearch__Matcher)i2, (void*)(_check_pointer(i4, 57283)), i5, 0, (-1));
  writeProc = (i2!=(OOC_INT32)0);
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 57316));
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 57330))+24);
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 57340));
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 57345))+8);
  enter = (OOC_SSA__Instr)i2;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 57390));
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 57435))+8);
  i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq((OOC_SSA__ProcBlock)i1, (OOC_SSA__Result)i2, (OOC_IR__StatementSeq)i0);
  s = (OOC_SSA__Result)i0;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 57454));
  OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i0, 2);
  OOC_SSA_IRtoSSA__DiscardGets((OOC_SSA__ProcBlock)i1);
  OOC_SSA_DeadCodeElimination__Transform((OOC_SSA__ProcBlock)i1);
  OOC_SSA_WriteC__TranslatorDesc_WriteProcBody_Write("initial", 8, "destore1-pre", 13, 1u);
  i0 = (OOC_INT32)pb;
  i1 = (OOC_INT32)OOC_SSA_Destore__New((OOC_SSA__ProcBlock)i0);
  destore = (OOC_SSA_Destore__State)i1;
  OOC_SSA_Destore__StateDesc_Transform((OOC_SSA_Destore__State)i1);
  OOC_SSA_DeadCodeElimination__RemoveDesignators((OOC_SSA__ProcBlock)i0);
  OOC_SSA_DeadCodeElimination__Transform((OOC_SSA__ProcBlock)i0);
  OOC_SSA_WriteC__TranslatorDesc_WriteProcBody_Write("destore1-post", 14, "constprop1-pre", 15, 1u);
  i0 = (OOC_INT32)pb;
  OOC_SSA_ConstProp__Transform((OOC_SSA__ProcBlock)i0);
  OOC_SSA_DeadCodeElimination__Transform((OOC_SSA__ProcBlock)i0);
  OOC_SSA_WriteC__TranslatorDesc_WriteProcBody_Write("constprop1-post", 16, "algebraic1-pre", 15, 1u);
  i0 = (OOC_INT32)pb;
  OOC_SSA_Algebraic__Transform((OOC_SSA__ProcBlock)i0, 0u);
  OOC_SSA_DeadCodeElimination__Transform((OOC_SSA__ProcBlock)i0);
  OOC_SSA_WriteC__TranslatorDesc_WriteProcBody_Write("algebraic1-post", 16, "cse1-pre", 9, 1u);
  i0 = (OOC_INT32)pb;
  OOC_SSA_CSE__Transform((OOC_SSA__ProcBlock)i0);
  OOC_SSA_DeadCodeElimination__Transform((OOC_SSA__ProcBlock)i0);
  OOC_SSA_WriteC__TranslatorDesc_WriteProcBody_Write("cse1-post", 10, "loop-pre", 9, 1u);
  i0 = (OOC_INT32)pb;
  OOC_SSA_LoopRewrite__Transform((OOC_SSA__ProcBlock)i0);
  OOC_SSA_DeadCodeElimination__Transform((OOC_SSA__ProcBlock)i0);
  OOC_SSA_WriteC__TranslatorDesc_WriteProcBody_Write("loop-post", 10, "pared-pre", 10, 1u);
  i0 = (OOC_INT32)pb;
  OOC_SSA_PRE__Transform((OOC_SSA__ProcBlock)i0);
  OOC_SSA_PRE__ResolveEquiv((OOC_SSA__ProcBlock)i0);
  OOC_SSA_DeadCodeElimination__Transform((OOC_SSA__ProcBlock)i0);
  OOC_SSA_WriteC__TranslatorDesc_WriteProcBody_Write("pared-post", 11, "constprop2-pre", 15, 1u);
  i0 = (OOC_INT32)pb;
  OOC_SSA_ConstProp__Transform((OOC_SSA__ProcBlock)i0);
  OOC_SSA_DeadCodeElimination__Transform((OOC_SSA__ProcBlock)i0);
  OOC_SSA_WriteC__TranslatorDesc_WriteProcBody_Write("constprop2-post", 16, "algebraic2-pre", 15, 1u);
  i0 = (OOC_INT32)pb;
  OOC_SSA_Algebraic__Transform((OOC_SSA__ProcBlock)i0, 1u);
  OOC_SSA_DeadCodeElimination__Transform((OOC_SSA__ProcBlock)i0);
  OOC_SSA_WriteC__TranslatorDesc_WriteProcBody_Write("algebraic2-post", 16, "cse2-pre", 9, 1u);
  i0 = (OOC_INT32)pb;
  OOC_SSA_CSE__Transform((OOC_SSA__ProcBlock)i0);
  OOC_SSA_DeadCodeElimination__Transform((OOC_SSA__ProcBlock)i0);
  OOC_SSA_WriteC__TranslatorDesc_WriteProcBody_Write("cse2-post", 10, "final", 6, 1u);
  i0 = (OOC_INT32)pb;
  OOC_SSA_WriteC__Fixup((OOC_SSA__ProcBlock)i0, (void*)(OOC_INT32)&jmpbufMap);
  i0 = (OOC_INT32)OOC_SSA_Schedule__Schedule((OOC_SSA__ProcBlock)i0);
  domRoot = (OOC_SSA_Schedule__Block)i0;
  i1 = writeProc;
  if (!i1) goto l13;
  i1 = (OOC_INT32)t;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 59071))+24);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 59071))+24);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 59085)))), StringSearch__MatcherDesc_MatchChars)),StringSearch__MatcherDesc_MatchChars)((StringSearch__Matcher)i1, "schedule", 9, 0, (-1));
  i1 = i1!=(OOC_INT32)0;
  if (!i1) goto l13;
  {
    Exception__PushContext(&_context0, &_target0);
    if (!setjmp(_target0)) goto l10;
    Exception__PopContext(1);
    i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG(((OOC_INT32)Exception__Current()))), &_td_IO__ErrorDesc);
    if (i0) goto l9;
    Exception__ActivateContext();
l9:
    Exception__Clear();
    goto l11;
l10:
    i1 = (OOC_INT32)IO_StdChannels__stdout;
    OOC_SSA_XML__WriteSchedule((IO__ByteChannel)i1, (OOC_SSA_Schedule__Block)i0);
    Exception__PopContext(1);
l11:;
  }
  Out__Flush();
l13:
  i0 = (OOC_INT32)t;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 59334));
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 59334));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 59337)))), OOC_C_DeclWriter__WriterDesc_Indent)),OOC_C_DeclWriter__WriterDesc_Indent)((OOC_C_DeclWriter__Writer)i2, 1);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 59411));
  i2 = (OOC_INT32)pb;
  i3 = (OOC_INT32)domRoot;
  i1 = (OOC_INT32)OOC_SSA_Allocator__AssignRegisters((OOC_SSA__ProcBlock)i2, (OOC_SSA_Schedule__Block)i3, (OOC_C_DeclWriter__Writer)i1);
  registerMap = (ADT_Dictionary__Dictionary)i1;
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 59441));
  i4 = (OOC_INT32)jmpbufMap;
  i1 = (OOC_INT32)OOC_SSA_WriteC__NewWriter((OOC_SSA_WriteC__Translator)i0, (OOC_C_DeclWriter__Writer)i3, (OOC_SSA__ProcBlock)i2, (ADT_Dictionary__Dictionary)i1, (ADT_Dictionary__Dictionary)i4);
  i3 = (OOC_INT32)jmpbufMap;
  w = (OOC_SSA_WriteC__Writer)i1;
  OOC_SSA_WriteC__WriteLocalDecl((OOC_SSA_WriteC__Translator)i0, (OOC_SSA_WriteC__Writer)i1, (OOC_SSA__ProcBlock)i2, (i3!=(OOC_INT32)0));
  i0 = (OOC_INT32)jmpbufMap;
  OOC_SSA_WriteC__TranslatorDesc_WriteProcBody_WriteJmpBufDecl((ADT_Dictionary__Dictionary)i0);
  i0 = (OOC_INT32)proc;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 59566))+4);
  i0 = OOC_SymbolTable__ProcDeclDesc_IsModuleBody((OOC_SymbolTable__ProcDecl)i0);
  if (!i0) goto l27;
  i0 = (OOC_INT32)pb;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 59757))+12);
  instr = (OOC_SSA__Instr)i0;
  i1 = (OOC_INT32)t;
  i2 = i0!=(OOC_INT32)0;
  if (!i2) goto l26;
l18_loop:
  i2 = *(OOC_INT8*)((_check_pointer(i0, 59815))+36);
  i2 = i2==81;
  if (!i2) goto l21;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 59884))+36);
  i2 = OOC_SSA_WriteC__GetPreloadId((ADT_Dictionary_IntValue__Dictionary)i2, (OOC_SSA__Instr)i0);
  dummy = i2;
l21:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 59943))+28);
  instr = (OOC_SSA__Instr)i0;
  i2 = i0!=(OOC_INT32)0;
  if (i2) goto l18_loop;
l26:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 59998))+36);
  OOC_SSA_WriteC__TranslatorDesc_WriteProcBody_InitPreloadedVars((ADT_Dictionary_IntValue__Dictionary)i0);
l27:
  i0 = (OOC_INT32)t;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 60029)))), OOC_Make_TranslateToC__TranslatorDesc_WriteNestedProcedures)),OOC_Make_TranslateToC__TranslatorDesc_WriteNestedProcedures)((OOC_Make_TranslateToC__Translator)i0);
  i0 = (OOC_INT32)domRoot;
  OOC_SSA_WriteC__TranslatorDesc_WriteProcBody_JumpChaining((OOC_SSA_Schedule__Block)i0);
  i0 = (OOC_INT32)domRoot;
  OOC_SSA_WriteC__TranslatorDesc_WriteProcBody_FixCrossJumps((OOC_SSA_Schedule__Block)i0);
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 60146)))), OOC_C_DeclWriter__WriterDesc_WriteLn)),OOC_C_DeclWriter__WriterDesc_WriteLn)((OOC_C_DeclWriter__Writer)i0);
  i1 = (OOC_INT32)domRoot;
  OOC_SSA_WriteC__WriterDesc_WriteBlocks((OOC_SSA_WriteC__Writer)i0, (OOC_SSA_Schedule__Block)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 60192)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 60324)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ";", 2);
  i0 = (OOC_INT32)t;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 60350));
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 60350));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 60353)))), OOC_C_DeclWriter__WriterDesc_Indent)),OOC_C_DeclWriter__WriterDesc_Indent)((OOC_C_DeclWriter__Writer)i0, (-1));
  i0 = (OOC_INT32)pb;
  OOC_SSA__ProcBlockDesc_Destroy((OOC_SSA__ProcBlock)i0);
  return;
  ;
}

void OOC_SSA_WriteC__InitTranslator(OOC_SSA_WriteC__Translator t, OOC_CHAR8 writeStats, StringSearch__Matcher inspectProc, StringSearch__Matcher inspectStage) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)t;
  OOC_Make_TranslateToC__InitTranslator((OOC_Make_TranslateToC__Translator)i0);
  i1 = (OOC_INT32)inspectProc;
  *(OOC_INT32*)((_check_pointer(i0, 60661))+20) = i1;
  i1 = (OOC_INT32)inspectStage;
  *(OOC_INT32*)((_check_pointer(i0, 60696))+24) = i1;
  i1 = writeStats;
  *(OOC_UINT8*)((_check_pointer(i0, 60733))+28) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 60766))+32) = (OOC_INT32)0;
  i1 = (OOC_INT32)ADT_Dictionary_IntValue__New();
  *(OOC_INT32*)((_check_pointer(i0, 60796))+36) = i1;
  return;
  ;
}

OOC_SSA_WriteC__Translator OOC_SSA_WriteC__NewTranslator(OOC_CHAR8 writeStats, StringSearch__Matcher inspectProc, StringSearch__Matcher inspectStage) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_SSA_WriteC__Translator.baseTypes[0]);
  i1 = writeStats;
  i2 = (OOC_INT32)inspectProc;
  i3 = (OOC_INT32)inspectStage;
  OOC_SSA_WriteC__InitTranslator((OOC_SSA_WriteC__Translator)i0, i1, (StringSearch__Matcher)i2, (StringSearch__Matcher)i3);
  return (OOC_SSA_WriteC__Translator)i0;
  ;
}

void OOC_SSA_WriteC__TranslatorDesc_SetProcedureList(OOC_SSA_WriteC__Translator t, OOC_IR__ProcedureList procList) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_SSA_WriteC__Visitor v;
  OOC_INT32 i;

  i0 = (OOC_INT32)t;
  i1 = (OOC_INT32)procList;
  OOC_Make_TranslateToC__TranslatorDesc_SetProcedureList((OOC_Make_TranslateToC__Translator)i0, (OOC_IR__ProcedureList)i1);
  i2 = i1!=(OOC_INT32)0;
  if (!i2) goto l11;
  i2 = (OOC_INT32)OOC_SSA_WriteC__NewVisitor();
  v = (OOC_SSA_WriteC__Visitor)i2;
  i = 0;
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i1, 61377)), 0);
  i4 = 0<i3;
  if (!i4) goto l10;
  i4=0;
l5_loop:
  i5 = _check_pointer(i1, 61401);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 61401))*4);
  OOC_IR__ProcedureDesc_Accept((OOC_IR__Procedure)i5, (OOC_IR__Visitor)i2);
  i4 = i4+1;
  i = i4;
  i5 = i4<i3;
  if (i5) goto l5_loop;
l10:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 61457))+4);
  *(OOC_INT32*)((_check_pointer(i0, 61436))+32) = i1;
l11:
  return;
  ;
}

void OOC_OOC_SSA_WriteC_init(void) {

  return;
  ;
}

/* --- */
