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
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11;
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
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5461))+108);
  i6 = _check_pointer(i6, 5472);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5429))+108);
  i8 = _check_pointer(i8, 5440);
  i9 = OOC_ARRAY_LENGTH(i8, 0);
  i10 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5429))+108);
  i10 = _check_pointer(i10, 5440);
  i11 = OOC_ARRAY_LENGTH(i10, 0);
  i10 = (OOC_INT32)*(OOC_INT32*)(i10+((_check_index(i4, i11, OOC_UINT32, 5440))*16));
  i6 = (OOC_INT32)*(OOC_INT32*)((i6+((_check_index(i2, i7, OOC_UINT32, 5472))*16))+4);
  i7 = (OOC_INT32)*(OOC_INT32*)(i8+((_check_index(i4, i9, OOC_UINT32, 5440))*16));
  i6 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i10, 5451)))), Object__StringDesc_Equals)),Object__StringDesc_Equals)((Object__String)i7, (Object__Object)i6);
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
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9;
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
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5812))+108);
  i4 = _check_pointer(i4, 5823);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5782))+108);
  i6 = _check_pointer(i6, 5793);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5782))+108);
  i8 = _check_pointer(i8, 5793);
  i9 = OOC_ARRAY_LENGTH(i8, 0);
  i8 = (OOC_INT32)*(OOC_INT32*)((i8+((_check_index(i2, i9, OOC_UINT32, 5793))*16))+4);
  i6 = (OOC_INT32)*(OOC_INT32*)((i6+((_check_index(i2, i7, OOC_UINT32, 5793))*16))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+((_check_index(i3, i5, OOC_UINT32, 5823))*16));
  i4 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i8, 5802)))), Object__StringDesc_Equals)),Object__StringDesc_Equals)((Object__String)i6, (Object__Object)i4);
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
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10;
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
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6416))+108);
  i5 = _check_pointer(i5, 6427);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6384))+108);
  i7 = _check_pointer(i7, 6395);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6384))+108);
  i9 = _check_pointer(i9, 6395);
  i10 = OOC_ARRAY_LENGTH(i9, 0);
  i9 = (OOC_INT32)*(OOC_INT32*)(i9+((_check_index(i4, i10, OOC_UINT32, 6395))*16));
  i5 = (OOC_INT32)*(OOC_INT32*)((i5+((_check_index(i3, i6, OOC_UINT32, 6427))*16))+4);
  i6 = (OOC_INT32)*(OOC_INT32*)(i7+((_check_index(i4, i8, OOC_UINT32, 6395))*16));
  i5 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i9, 6406)))), Object__StringDesc_Equals)),Object__StringDesc_Equals)((Object__String)i6, (Object__Object)i5);
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
    i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 7786)))), &_td_OOC_SSA__AddressDesc, 7786)), 7794))+44);
    i4 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetDeclRef((OOC_SSA__ProcBlock)i0, (OOC_SymbolTable__Declaration)i4);
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 7707))+24);
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
  auto void OOC_SSA_WriteC__WriteTypeAndLength_ExpandMult(OOC_SSA__Opnd opnd);
    
    void OOC_SSA_WriteC__WriteTypeAndLength_ExpandMult(OOC_SSA__Opnd opnd) {
      register OOC_INT32 i0,i1,i2;
      OOC_SSA__Instr instr;

      i0 = (OOC_INT32)opnd;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 9230));
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 9234))+8);
      instr = (OOC_SSA__Instr)i1;
      i2 = *(OOC_INT8*)((_check_pointer(i1, 9257))+36);
      i2 = i2==22;
      if (i2) goto l3;
      i1 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i1, (OOC_SSA__Opnd)i0);
      goto l4;
l3:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 9313))+24);
      OOC_SSA_WriteC__WriteTypeAndLength_ExpandMult((OOC_SSA__Opnd)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9334)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i0, 42u);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 9375))+24);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9384))+8);
      OOC_SSA_WriteC__WriteTypeAndLength_ExpandMult((OOC_SSA__Opnd)i0);
l4:
      return;
      ;
    }


  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9475)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ",", 2);
  i1 = (OOC_INT32)varDecl;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 9515))+48);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 9515))+48);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 9520)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i1);
  type = (OOC_SymbolTable__Type)i1;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9546)))), &_td_OOC_SymbolTable__ArrayDesc);
  if (i2) goto l3;
  OOC_SSA_WriteC__WriterDesc_TypeRef((OOC_SSA_WriteC__Writer)i0, (OOC_SymbolTable__Type)i1);
  goto l4;
l3:
  i1 = (OOC_INT32)OOC_SymbolTable__ArrayDesc_GetInnermostElementType((OOC_SymbolTable__Array)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9590)))), &_td_OOC_SymbolTable__ArrayDesc, 9590)));
  OOC_SSA_WriteC__WriterDesc_TypeRef((OOC_SSA_WriteC__Writer)i0, (OOC_SymbolTable__Type)i1);
l4:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9671)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ",", 2);
  i1 = inBytes;
  if (i1) goto l7;
  i0 = (OOC_INT32)instr;
  i0 = (OOC_INT32)OOC_SSA__InstrDesc_NthOpnd((OOC_SSA__Instr)i0, 1);
  OOC_SSA_WriteC__WriteTypeAndLength_ExpandMult((OOC_SSA__Opnd)i0);
  goto l8;
l7:
  i1 = (OOC_INT32)instr;
  i1 = (OOC_INT32)OOC_SSA__InstrDesc_NthOpnd((OOC_SSA__Instr)i1, 2);
  OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i0, (OOC_SSA__Opnd)i1);
l8:
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9802)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ")", 2);
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
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10356)))), &_td_OOC_SSA__AddressDesc);
      if (i1) goto l34;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10655))+24);
      opnd = (OOC_SSA__Opnd)i0;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l5;
      i1=0u;
      goto l11;
l5:
      i1 = *(OOC_INT8*)((_check_pointer(i0, 10716))+4);
      i1 = i1!=5;
      if (i1) goto l8;
      i1=0u;
      goto l11;
l8:
      i1 = *(OOC_INT8*)((_check_pointer(i0, 10765))+4);
      i1 = i1!=7;
      
l11:
      if (!i1) goto l27;
l14_loop:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10819))+8);
      opnd = (OOC_SSA__Opnd)i0;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l17;
      i1=0u;
      goto l23;
l17:
      i1 = *(OOC_INT8*)((_check_pointer(i0, 10716))+4);
      i1 = i1!=5;
      if (i1) goto l20;
      i1=0u;
      goto l23;
l20:
      i1 = *(OOC_INT8*)((_check_pointer(i0, 10765))+4);
      i1 = i1!=7;
      
l23:
      if (i1) goto l14_loop;
l27:
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 10860));
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 10866)))), &_td_OOC_SSA__DeclRefDesc);
      if (!i1) goto l33;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 10912));
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10922)))), &_td_OOC_SSA__DeclRefDesc, 10922)), 10930))+44);
      i0 = _type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10941)))), &_td_OOC_SymbolTable__VarDeclDesc, 10941);
      varDecl = (OOC_SymbolTable__VarDecl)i0;
      i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10972)))), OOC_SymbolTable__ItemDesc_Procedure)),OOC_SymbolTable__ItemDesc_Procedure)((OOC_SymbolTable__Item)i0);
      i2 = (OOC_INT32)pb;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 10990))+20);
      i1 = i1==i2;
      if (!i1) goto l33;
      return (OOC_SymbolTable__VarDecl)i0;
l33:
      return (OOC_SymbolTable__VarDecl)(OOC_INT32)0;
      goto l43;
l34:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10436))+44);
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 10443)))), &_td_OOC_SymbolTable__VarDeclDesc);
      if (i1) goto l37;
      i1=0u;
      goto l39;
l37:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10478))+44);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10478))+44);
      i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 10489)))), &_td_OOC_SymbolTable__VarDeclDesc, 10489)), 10497)))), OOC_SymbolTable__ItemDesc_Procedure)),OOC_SymbolTable__ItemDesc_Procedure)((OOC_SymbolTable__Item)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 10489)))), &_td_OOC_SymbolTable__VarDeclDesc, 10489)));
      i2 = (OOC_INT32)pb;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 10515))+20);
      i1 = i1==i2;
      
l39:
      if (i1) goto l41;
      return (OOC_SymbolTable__VarDecl)(OOC_INT32)0;
      goto l43;
l41:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10554))+44);
      return (OOC_SymbolTable__VarDecl)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10565)))), &_td_OOC_SymbolTable__VarDeclDesc, 10565));
l43:
      _failed_function(10226); return 0;
      ;
    }


  i0 = (OOC_INT32)ADT_Dictionary__New();
  declMap = (ADT_Dictionary__Dictionary)i0;
  i0 = (OOC_INT32)pb;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11173))+12);
  instr = (OOC_SSA__Instr)i0;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l40;
l3_loop:
  i1 = *(OOC_INT8*)((_check_pointer(i0, 11228))+36);
  i1 = i1==12;
  if (i1) goto l6;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 11269))+36);
  i1 = i1==13;
  
  goto l8;
l6:
  i1=1u;
l8:
  if (i1) goto l10;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 11310))+36);
  i1 = i1==58;
  
  goto l12;
l10:
  i1=1u;
l12:
  if (i1) goto l14;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 11361))+36);
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
  i2 = *(OOC_INT8*)((_check_pointer(i1, 11505))+36);
  i2 = i2==58;
  if (i2) goto l32;
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 11781))+56);
  i1 = !i1;
  if (!i1) goto l35;
  i1 = (OOC_INT32)w;
  i2 = (OOC_INT32)OOC_C_ConvertDecl__GetDecl((OOC_C_DeclWriter__Writer)i1, (OOC_SymbolTable__Declaration)i0);
  cDecl = (OOC_C_DeclWriter__Declaration)i2;
  i3 = _volatile;
  if (!i3) goto l30;
  OOC_C_DeclWriter__DeclarationDesc_SetTypeQualifier((OOC_C_DeclWriter__Declaration)i2, 2);
l30:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 11972)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 11996)))), OOC_C_DeclWriter__WriterDesc_WriteDeclaration)),OOC_C_DeclWriter__WriterDesc_WriteDeclaration)((OOC_C_DeclWriter__Writer)i1, (OOC_C_DeclWriter__Declaration)i2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 12037)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 59u);
  i1 = (OOC_INT32)declMap;
  ADT_Dictionary__DictionaryDesc_Set((ADT_Dictionary__Dictionary)i1, (Object__Object)i0, (Object__Object)(OOC_INT32)0);
  goto l35;
l32:
  i2 = (OOC_INT32)OOC_C_Naming__NameOfDeclaration((OOC_SymbolTable__Declaration)i0);
  name = (Object__String)i2;
  i3 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 11608)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i3);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 11632)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i3, "OOC_ALLOCATE_VPAR(", 19);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 11683)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i3, (Object__Object)i2);
  OOC_SSA_WriteC__WriteTypeAndLength((OOC_SSA_WriteC__Writer)i3, (OOC_SSA__Instr)i1, (OOC_SymbolTable__VarDecl)i0, 0u);
l35:
  i0 = (OOC_INT32)instr;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12152))+28);
  instr = (OOC_SSA__Instr)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l3_loop;
l40:
  i0 = (OOC_INT32)pb;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12361))+20);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12371))+8);
  item = (OOC_SymbolTable__Item)i1;
  i2 = i1!=(OOC_INT32)0;
  if (!i2) goto l62;
  i2 = (OOC_INT32)t;
  i3 = (OOC_INT32)w;
  i4 = (OOC_INT32)declMap;
  
l43_loop:
  i5 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 12427)))), &_td_OOC_SymbolTable__VarDeclDesc);
  if (!i5) goto l57;
  i5 = *(OOC_UINT8*)((_check_pointer(i1, 12460))+56);
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
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 12525))+32);
  i5 = ADT_Dictionary__DictionaryDesc_HasKey((ADT_Dictionary__Dictionary)i5, (Object__Object)i1);
  
l54:
  if (!i5) goto l57;
  i5 = (OOC_INT32)OOC_C_ConvertDecl__GetDecl((OOC_C_DeclWriter__Writer)i3, (OOC_SymbolTable__Declaration)i1);
  cDecl = (OOC_C_DeclWriter__Declaration)i5;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 12623)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i3);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 12645)))), OOC_C_DeclWriter__WriterDesc_WriteDeclaration)),OOC_C_DeclWriter__WriterDesc_WriteDeclaration)((OOC_C_DeclWriter__Writer)i3, (OOC_C_DeclWriter__Declaration)i5);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 12684)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i3, 59u);
  ADT_Dictionary__DictionaryDesc_Set((ADT_Dictionary__Dictionary)i4, (Object__Object)i1, (Object__Object)(OOC_INT32)0);
l57:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 12833));
  item = (OOC_SymbolTable__Item)i1;
  i5 = i1!=(OOC_INT32)0;
  if (i5) goto l43_loop;
l62:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12977))+20);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12987))+8);
  item = (OOC_SymbolTable__Item)i0;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l73;
  i1 = (OOC_INT32)declMap;
  i2 = (OOC_INT32)w;
  
l65_loop:
  i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13043)))), &_td_OOC_SymbolTable__ProcDeclDesc);
  if (!i3) goto l68;
  i3 = (OOC_INT32)OOC_C_ConvertDecl__GetProc((OOC_C_DeclWriter__Writer)i2, (OOC_SymbolTable__ProcDecl)i0, 1u);
  cDecl = (OOC_C_DeclWriter__Declaration)i3;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 13124)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 13144)))), OOC_C_DeclWriter__WriterDesc_WriteDeclaration)),OOC_C_DeclWriter__WriterDesc_WriteDeclaration)((OOC_C_DeclWriter__Writer)i2, (OOC_C_DeclWriter__Declaration)i3);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 13181)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i2, 59u);
  ADT_Dictionary__DictionaryDesc_Set((ADT_Dictionary__Dictionary)i1, (Object__Object)i0, (Object__Object)(OOC_INT32)0);
l68:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 13315));
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13432)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "OOC_ARRAY_LENGTH(", 18);
  i1 = (OOC_INT32)instr;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 13486))+24);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 13496))+8);
  OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i0, (OOC_SSA__Opnd)i2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13514)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ", ", 3);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 13553))+24);
  OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i0, (OOC_SSA__Opnd)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13571)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ")", 2);
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
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13872))+24);
  i0 = OOC_SSA__OpndDesc_GetIntConst((OOC_SSA__Opnd)i0);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 13838)))), &_td_OOC_SSA__DeclRefDesc, 13838)), 13846))+44);
  i0 = (OOC_INT32)OOC_C_Naming__NameOfLengthParam((OOC_SymbolTable__VarDecl)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 13857)))), &_td_OOC_SymbolTable__VarDeclDesc, 13857)), i0);
  name = (Object__String)i0;
  i1 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 13905)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i1, (Object__Object)i0);
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
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 14195));
  arg = (OOC_SSA__Result)i1;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14214)))), &_td_OOC_SSA__DeclRefDesc);
  if (i2) goto l50;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14727)))), &_td_OOC_SSA__ConstDesc);
  if (i2) goto l40;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15458)))), &_td_OOC_SSA__AddressDesc);
  if (i2) goto l23;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 16056));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 16061))+8);
  instr = (OOC_SSA__Instr)i1;
  i2 = (OOC_INT32)w;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 16080))+96);
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 16107));
  i3 = ADT_Dictionary__DictionaryDesc_HasKey((ADT_Dictionary__Dictionary)i3, (Object__Object)i4);
  if (i3) goto l17;
  i0 = *(OOC_INT8*)((_check_pointer(i1, 16393))+36);
  i0 = i0==57;
  if (i0) goto l15;
  i0 = *(OOC_INT8*)((_check_pointer(i1, 16495))+36);
  i0 = i0==72;
  if (i0) goto l13;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 16748)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i2, "XXX undefined ref /*internal error*/", 37);
  goto l62;
l13:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 16536)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i2, "setjmp(_target", 15);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 16584))+100);
  i0 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i0, (Object__Object)i1);
  obj = (Object__Object)i0;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 16616)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i2, (Object__Object)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 16644)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i2, ")", 2);
  goto l62;
l15:
  OOC_SSA_WriteC__WriterDesc_LengthExprParam((OOC_SSA_WriteC__Writer)i2, (OOC_SSA__Instr)i1);
  goto l62;
l17:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 16135))+96);
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 16159));
  i1 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i1, (Object__Object)i3);
  obj = (Object__Object)i1;
  i3 = (OOC_INT32)OOC_SSA_Allocator__markInPlace;
  i3 = i1==i3;
  if (i3) goto l20;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 16340)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i2, (Object__Object)i1);
  goto l62;
l20:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 16224)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i2, 40u);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 16271));
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16276))+8);
  OOC_SSA_WriteC__WriteExpr((OOC_SSA_WriteC__Writer)i2, (OOC_SSA__Instr)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 16297)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i2, 41u);
  goto l62;
l23:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 15518))+44);
  i0 = (OOC_INT32)OOC_C_Naming__NameOfDeclaration((OOC_SymbolTable__Declaration)i0);
  name = (Object__String)i0;
  i2 = (OOC_INT32)w;
  OOC_SSA_WriteC__WriteTypeCast((OOC_C_DeclWriter__Writer)i2, 1);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 15584))+44);
  i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 15591)))), &_td_OOC_SymbolTable__VarDeclDesc);
  if (i3) goto l26;
  i3=0u;
  goto l28;
l26:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 15625))+44);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 15636)))), &_td_OOC_SymbolTable__VarDeclDesc, 15636)), 15644))+48);
  i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 15651)))), &_td_OOC_SymbolTable__ArrayDesc);
  
l28:
  if (i3) goto l34;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 15685))+44);
  i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 15692)))), &_td_OOC_SymbolTable__VarDeclDesc);
  if (i3) goto l32;
  i1=0u;
  goto l35;
l32:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 15725))+44);
  i1 = *(OOC_UINT8*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15736)))), &_td_OOC_SymbolTable__VarDeclDesc, 15736)), 15744))+60);
  
  goto l35;
l34:
  i1=1u;
l35:
  i1 = !i1;
  if (!i1) goto l38;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 15962)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i2, 38u);
l38:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 15999)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i2, (Object__Object)i0);
  goto l62;
l40:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14918))+44);
  i2 = (OOC_INT32)OOC_SSA__nil;
  i0 = i0==i2;
  if (i0) goto l47;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 15238))+48);
  i0 = i0!=0;
  if (i0) goto l45;
  i0 = *(OOC_INT8*)((_check_pointer(i1, 15424))+5);
  i0 = OOC_SSA_Allocator__SubclassToBasicType(i0);
  i2 = (OOC_INT32)w;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 15357))+44);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 15337)))), OOC_C_DeclWriter__WriterDesc_WriteBasicConst)),OOC_C_DeclWriter__WriterDesc_WriteBasicConst)((OOC_C_DeclWriter__Writer)i2, (Object_Boxed__Object)i1, i0);
  goto l62;
l45:
  i0 = (OOC_INT32)w;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 15303))+48);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 15292))+44);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15271)))), OOC_C_DeclWriter__WriterDesc_WriteStringConst)),OOC_C_DeclWriter__WriterDesc_WriteStringConst)((OOC_C_DeclWriter__Writer)i0, (Object_Boxed__Object)i1, (OOC_SymbolTable__Type)i2);
  goto l62;
l47:
  bt = 4;
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15094)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "(", 2);
  i1 = bt;
  i1 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i0, 15140))+24)+(_check_index(i1, 17, OOC_UINT8, 15151))*4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15124)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, (void*)((_check_pointer(i1, 15155))+1), 32);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15173)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ")", 2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15203)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "0", 2);
  goto l62;
l50:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14378))+44);
  i0 = (OOC_INT32)OOC_C_Naming__NameOfDeclaration((OOC_SymbolTable__Declaration)i0);
  name = (Object__String)i0;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14400))+44);
  i3 = (OOC_INT32)w;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 14407)))), &_td_OOC_SymbolTable__VarDeclDesc);
  if (i2) goto l53;
  i2=0u;
  goto l55;
l53:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14437))+44);
  i2 = *(OOC_UINT8*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 14448)))), &_td_OOC_SymbolTable__VarDeclDesc, 14448)), 14456))+60);
  
l55:
  if (i2) goto l57;
  i1=0u;
  goto l59;
l57:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14493))+44);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14504)))), &_td_OOC_SymbolTable__VarDeclDesc, 14504)), 14512))+48);
  i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14519)))), &_td_OOC_SymbolTable__ArrayDesc));
  
l59:
  if (!i1) goto l61;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 14658)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i3, "*", 2);
l61:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 14696)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i3, (Object__Object)i0);
l62:
  return;
  ;
}

void OOC_SSA_WriteC__WriterDesc_TypeRef(OOC_SSA_WriteC__Writer w, OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1;
  OOC_C_DeclWriter__Type cType;

  i0 = (OOC_INT32)type;
  i1 = (OOC_INT32)w;
  i0 = (OOC_INT32)OOC_C_ConvertDecl__GetTypeRef((OOC_C_DeclWriter__Writer)i1, (OOC_SymbolTable__Type)i0);
  cType = (OOC_C_DeclWriter__Type)i0;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16976)))), OOC_C_DeclWriter__WriterDesc_WriteType)),OOC_C_DeclWriter__WriterDesc_WriteType)((OOC_C_DeclWriter__Writer)i1, (OOC_C_DeclWriter__Type)i0);
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
  i1 = *(OOC_INT8*)((_check_pointer(i0, 17208))+36);
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
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17548))+24);
    opnd = (OOC_SSA__Opnd)i0;
    i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 17584));
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
    i3 = *(OOC_INT8*)((_check_pointer(i0, 17668))+4);
    i3 = i3!=2;
    if (!i3) goto l20;
    i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 17719))+96);
    i3 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i3, (Object__Object)i1);
    targetVar = (Object__Object)i3;
    i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 17759))+96);
    i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 17786));
    i4 = ADT_Dictionary__DictionaryDesc_HasKey((ADT_Dictionary__Dictionary)i4, (Object__Object)i5);
    if (i4) goto l15;
    return 0u;
    goto l20;
l15:
    i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 17824))+96);
    i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 17848));
    i4 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i4, (Object__Object)i5);
    sourceVar = (Object__Object)i4;
    i3 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 17881)))), Object__ObjectDesc_Equals)),Object__ObjectDesc_Equals)((Object__Object)i4, (Object__Object)i3);
    i3 = !i3;
    if (!i3) goto l20;
    return 0u;
l20:
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18129))+8);
    opnd = (OOC_SSA__Opnd)i0;
    i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 18151));
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
  _failed_function(17036); return 0;
  ;
}

OOC_CHAR8 OOC_SSA_WriteC__WriterDesc_EmptyBlock(OOC_SSA_WriteC__Writer w, OOC_SSA_Schedule__Block b) {
  register OOC_INT32 i0,i1,i2;
  OOC_SSA_Schedule__InstrProxy proxy;

  i0 = (OOC_INT32)b;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18491)))), &_td_OOC_SSA_Schedule__JumpBlockDesc);
  if (i1) goto l3;
  return 0u;
  goto l15;
l3:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18531))+8);
  proxy = (OOC_SSA_Schedule__InstrProxy)i0;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l14;
  i1 = (OOC_INT32)w;
  
l6_loop:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18599))+12);
  i2 = OOC_SSA_WriteC__WriterDesc_Noop((OOC_SSA_WriteC__Writer)i1, (OOC_SSA__Instr)i2);
  i2 = !i2;
  if (!i2) goto l9;
  return 0u;
l9:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 18672));
  proxy = (OOC_SSA_Schedule__InstrProxy)i0;
  i2 = i0!=(OOC_INT32)0;
  if (i2) goto l6_loop;
l14:
  return 1u;
l15:
  _failed_function(18274); return 0;
  ;
}

static void OOC_SSA_WriteC__CastToPtr(OOC_SSA_WriteC__Writer w, OOC_SSA__Result var, OOC_SymbolTable__Type type, OOC_CHAR8 passByReference) {
  register OOC_INT32 i0,i1,i2;
  Object__String name;

  i0 = (OOC_INT32)type;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18933)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  type = (OOC_SymbolTable__Type)i0;
  i1 = (OOC_INT32)var;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 18956))+8);
  i2 = *(OOC_INT8*)((_check_pointer(i2, 18963))+36);
  i2 = i2==61;
  if (i2) goto l41;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 19051)))), &_td_OOC_SymbolTable__PointerDesc);
  if (i2) goto l5;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 19086)))), &_td_OOC_SymbolTable__FormalParsDesc);
  
  goto l7;
l5:
  i2=1u;
l7:
  if (i2) goto l9;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 19124)))), &_td_OOC_SymbolTable__TypeVarDesc);
  
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
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 19236)))), &_td_OOC_SSA__ConstDesc);
  if (i2) goto l23;
  i1=0u;
  goto l25;
l23:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 19270)))), &_td_OOC_SSA__ConstDesc, 19270)), 19276))+44);
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 19284)))), &_td_Object_Boxed__StringDesc);
  
l25:
  if (i1) goto l42;
  i1 = passByReference;
  if (i1) goto l29;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19397))+24);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 19570)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "(", 2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 19600)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i1, (Object__Object)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 19631)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, ")", 2);
  goto l42;
l37:
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 19481)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "(void*)", 8);
  goto l42;
l41:
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 19002)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "(RT0__Struct)", 14);
l42:
  return;
  ;
}

static OOC_INT32 OOC_SSA_WriteC__GetPreloadId(ADT_Dictionary_IntValue__Dictionary preloadedVars, OOC_SSA__Instr instr) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)instr;
  i1 = (OOC_INT32)preloadedVars;
  i2 = ADT_Dictionary_IntValue__DictionaryDesc_HasKey((ADT_Dictionary_IntValue__Dictionary)i1, (Object__Object)i0);
  if (i2) goto l3;
  i2 = ADT_Dictionary_IntValue__DictionaryDesc_Size((ADT_Dictionary_IntValue__Dictionary)i1);
  ADT_Dictionary_IntValue__DictionaryDesc_Set((ADT_Dictionary_IntValue__Dictionary)i1, (Object__Object)i0, i2);
  i0=i2;
  goto l4;
l3:
  i0 = ADT_Dictionary_IntValue__DictionaryDesc_Get((ADT_Dictionary_IntValue__Dictionary)i1, (Object__Object)i0);
  
l4:
  return i0;
  ;
}

static Object__Object OOC_SSA_WriteC__WriteExceptionContext(OOC_SSA_WriteC__Writer w, OOC_SSA__Instr instr) {
  register OOC_INT32 i0,i1,i2;
  Object__Object obj;

  i0 = (OOC_INT32)instr;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 20161))+36);
  switch (i1) {
  case 78:
    
    goto l5;
  case 77:
  case 76:
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20304))+24);
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 20313));
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20317))+8);
    instr = (OOC_SSA__Instr)i0;
    
    goto l5;
  default:
    _failed_case(i1, 20151);
    
    goto l5;
  }
l5:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20366))+24);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 20375));
  i1 = (OOC_INT32)w;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 20346))+100);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20379))+8);
  i0 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i2, (Object__Object)i0);
  obj = (Object__Object)i0;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 20393)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "_context", 9);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 20424)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i1, (Object__Object)i0);
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
      i3 = *(OOC_INT8*)((_check_pointer(i0, 20834))+4);
      i3 = i3==i1;
      if (!i3) goto l13;
      i3 = i2!=0;
      if (!i3) goto l9;
      i3 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 20899)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i3, ", ", 3);
l9:
      i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20954)))), &_td_OOC_SSA__TypedOpndDesc);
      if (!i3) goto l12;
      i3 = *(OOC_UINT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21096)))), &_td_OOC_SSA__TypedOpndDesc, 21096)), 21106))+24);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21046)))), &_td_OOC_SSA__TypedOpndDesc, 21046)), 21056))+20);
      i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 21007));
      i6 = (OOC_INT32)w;
      OOC_SSA_WriteC__CastToPtr((OOC_SSA_WriteC__Writer)i6, (OOC_SSA__Result)i5, (OOC_SymbolTable__Type)i4, i3);
l12:
      i3 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i3, (OOC_SSA__Opnd)i0);
      i2 = i2+1;
      count = i2;
      
l13:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21221))+8);
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
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21320)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21338)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "_assert(", 9);
      i0 = (OOC_INT32)assert;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21387))+24);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 21397))+8);
      OOC_SSA_WriteC__WriteExpr_RefList((OOC_SSA__Opnd)i1, 1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 21427)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, ", ", 3);
      i1 = (OOC_INT32)w;
      i0 = *(OOC_INT32*)((_check_pointer(i0, 21475))+40);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 21456)))), OOC_C_DeclWriter__WriterDesc_WriteLInt)),OOC_C_DeclWriter__WriterDesc_WriteLInt)((OOC_C_DeclWriter__Writer)i1, i0, 0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21493)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ")", 2);
      return;
      ;
    }

    
    void OOC_SSA_WriteC__WriteExpr_CheckIndex(OOC_SSA__Instr checkIndex) {
      register OOC_INT32 i0,i1,i2;
      OOC_INT8 bt;

      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21639)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "_check_index(", 14);
      i0 = (OOC_INT32)checkIndex;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21697))+24);
      OOC_SSA_WriteC__WriteExpr_RefList((OOC_SSA__Opnd)i1, 1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 21727)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, ", ", 3);
      i1 = (OOC_INT32)instr;
      i1 = OOC_SSA_WriteC__SubclassToBasicType((OOC_SSA__Result)i1);
      i1 = i1+4;
      bt = i1;
      i2 = (OOC_INT32)w;
      i1 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i2, 21848))+24)+(_check_index(i1, 17, OOC_UINT8, 21859))*4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 21832)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i2, (void*)((_check_pointer(i1, 21863))+1), 32);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 21879)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, ", ", 3);
      i1 = (OOC_INT32)w;
      i0 = *(OOC_INT32*)((_check_pointer(i0, 21931))+40);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 21908)))), OOC_C_DeclWriter__WriterDesc_WriteLInt)),OOC_C_DeclWriter__WriterDesc_WriteLInt)((OOC_C_DeclWriter__Writer)i1, i0, 0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21949)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ")", 2);
      return;
      ;
    }

    
    void OOC_SSA_WriteC__WriteExpr_CheckPointer(OOC_SSA__Instr checkPointer) {
      register OOC_INT32 i0,i1,i2;

      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22059)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "_check_pointer(", 16);
      i0 = (OOC_INT32)checkPointer;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22120))+24);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 22130))+8);
      i2 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i2, (OOC_SSA__Opnd)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 22150)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, ", ", 3);
      i1 = (OOC_INT32)w;
      i0 = *(OOC_INT32*)((_check_pointer(i0, 22204))+40);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 22179)))), OOC_C_DeclWriter__WriterDesc_WriteLInt)),OOC_C_DeclWriter__WriterDesc_WriteLInt)((OOC_C_DeclWriter__Writer)i1, i0, 0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22222)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ")", 2);
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
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 22462));
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 22472)))), &_td_OOC_SSA__TypeRefDesc, 22472)), 22480))+44);
      type = (OOC_SymbolTable__Type)i1;
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 22510)))), &_td_OOC_SymbolTable__TypeClosureDesc);
      if (i2) goto l3;
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 22630)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i2, "_type_guard(", 13);
      goto l4;
l3:
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 22576)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i2, "_type_guard_q(", 15);
l4:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22697))+24);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 22707))+8);
      OOC_SSA_WriteC__WriteExpr_RefList((OOC_SSA__Opnd)i2, 1);
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 22737)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i2, ", &", 4);
      i2 = (OOC_INT32)w;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 22810))+92);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 22821))+16);
      i1 = (OOC_INT32)OOC_C_Naming__NameOfTypeDescriptor((OOC_SymbolTable__Type)i1, (OOC_C_Naming__QualTypeData)i2);
      name = (Object__String)i1;
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 22839)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i2, (Object__Object)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 22868)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, ", ", 3);
      i1 = (OOC_INT32)w;
      i0 = *(OOC_INT32*)((_check_pointer(i0, 22919))+40);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 22897)))), OOC_C_DeclWriter__WriterDesc_WriteLInt)),OOC_C_DeclWriter__WriterDesc_WriteLInt)((OOC_C_DeclWriter__Writer)i1, i0, 0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22937)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ")", 2);
      return;
      ;
    }

    
    void OOC_SSA_WriteC__WriteExpr_FailedCheck(OOC_SSA__Instr instr, const OOC_CHAR8 fct__ref[], OOC_LEN fct_0d, OOC_SSA__Opnd opnd) {
      register OOC_INT32 i0,i1;
      OOC_ALLOCATE_VPAR(fct,OOC_CHAR8 ,fct_0d)

      OOC_INITIALIZE_VPAR(fct__ref,fct,OOC_CHAR8 ,fct_0d)
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 23074)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 23092)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, (void*)(OOC_INT32)fct, fct_0d);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 23120)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "(", 2);
      i0 = (OOC_INT32)opnd;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l4;
      i1 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i1, (OOC_SSA__Opnd)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 23200)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ", ", 3);
l4:
      i0 = (OOC_INT32)instr;
      i1 = (OOC_INT32)w;
      i0 = *(OOC_INT32*)((_check_pointer(i0, 23258))+40);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 23240)))), OOC_C_DeclWriter__WriterDesc_WriteLInt)),OOC_C_DeclWriter__WriterDesc_WriteLInt)((OOC_C_DeclWriter__Writer)i1, i0, 0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 23276)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ")", 2);
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
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23525))+24);
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 23535));
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23540))+8);
      i1 = *(OOC_INT8*)((_check_pointer(i1, 23547))+36);
      _class = i1;
      i2 = i1==63;
      if (i2) goto l3;
      i1 = i1==87;
      
      goto l5;
l3:
      i1=1u;
l5:
      if (i1) goto l11;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24060))+24);
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 24070));
      i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 24076)))), &_td_OOC_SSA__DeclRefDesc));
      if (i1) goto l9;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24436))+24);
      i2 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i2, (OOC_SSA__Opnd)i1);
      goto l12;
l9:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24191))+24);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 24206)))), &_td_OOC_SSA__TypedOpndDesc, 24206)), 24216))+20);
      i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 24227)))), &_td_OOC_SymbolTable__FormalParsDesc, 24227);
      procType = (OOC_SymbolTable__FormalPars)i1;
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 24249)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i2, 40u);
      i2 = (OOC_INT32)w;
      i1 = (OOC_INT32)OOC_C_ConvertDecl__ConvertType((OOC_C_DeclWriter__Writer)i2, (OOC_SymbolTable__Type)i1, (OOC_SymbolTable__Type)i1);
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 24277)))), OOC_C_DeclWriter__WriterDesc_WriteTypeCast)),OOC_C_DeclWriter__WriterDesc_WriteTypeCast)((OOC_C_DeclWriter__Writer)i2, (OOC_C_DeclWriter__Type)i1);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24364))+24);
      i2 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i2, (OOC_SSA__Opnd)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 24386)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 41u);
      goto l12;
l11:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23737))+24);
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 23747));
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23752))+8);
      adr = (OOC_SSA__Instr)i1;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23780))+24);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23790))+8);
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 23800));
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23805))+8);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 23817)))), &_td_OOC_SSA__DeclRefDesc, 23817)), 23825))+44);
      decl = (OOC_SymbolTable__Declaration)i1;
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 23842)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i2, "OOC_TBCALL(", 12);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23893))+24);
      i3 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i3, (OOC_SSA__Opnd)i2);
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 23915)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i2, 44u);
      i1 = (OOC_INT32)OOC_C_Naming__NameOfDeclaration((OOC_SymbolTable__Declaration)i1);
      name = (Object__String)i1;
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 23992)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i2, (Object__Object)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 24023)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 41u);
l12:
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 24467)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "(", 2);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24507))+24);
      OOC_SSA_WriteC__WriteExpr_RefList((OOC_SSA__Opnd)i0, 1);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 24537)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ")", 2);
      return;
      ;
    }

    
    void OOC_SSA_WriteC__WriteExpr_WriteDyadicOp(OOC_SSA__Instr instr, const OOC_CHAR8 op__ref[], OOC_LEN op_0d) {
      register OOC_INT32 i0,i1,i2;
      OOC_ALLOCATE_VPAR(op,OOC_CHAR8 ,op_0d)

      OOC_INITIALIZE_VPAR(op__ref,op,OOC_CHAR8 ,op_0d)
      i0 = (OOC_INT32)instr;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24668))+24);
      i2 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i2, (OOC_SSA__Opnd)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 24688)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, (void*)(OOC_INT32)op, op_0d);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24727))+24);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24737))+8);
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
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25068))+24);
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 25077));
      i1 = *(OOC_INT8*)((_check_pointer(i1, 25081))+5);
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
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 25391)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i2, 40u);
      i2 = (OOC_INT32)w;
      i3 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i2, 25435))+24)+(_check_index(i1, 17, OOC_UINT8, 25446))*4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 25419)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i2, (void*)((_check_pointer(i3, 25452))+1), 32);
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 25470)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i2, 41u);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25510))+24);
      i3 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i3, (OOC_SSA__Opnd)i2);
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 25532)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i2, (void*)(OOC_INT32)op, op_0d);
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 25561)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i2, 40u);
      i2 = (OOC_INT32)w;
      i1 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i2, 25605))+24)+(_check_index(i1, 17, OOC_UINT8, 25616))*4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 25589)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i2, (void*)((_check_pointer(i1, 25622))+1), 32);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 25640)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 41u);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25680))+24);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25690))+8);
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
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 25870)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, (void*)(OOC_INT32)fct, fct_0d);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 25898)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i0, 40u);
      i0 = (OOC_INT32)instr;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25936))+24);
      i2 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i2, (OOC_SSA__Opnd)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 25956)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 44u);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25994))+24);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26004))+8);
      i1 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i1, (OOC_SSA__Opnd)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 26024)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ")", 2);
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
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 26163)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, (void*)(OOC_INT32)op, op_0d);
      i0 = (OOC_INT32)instr;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26202))+24);
      i1 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i1, (OOC_SSA__Opnd)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 26222)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, (void*)(OOC_INT32)suffix, suffix_0d);
      return;
      ;
    }

    
    void OOC_SSA_WriteC__WriteExpr_CastFromPtr(OOC_SSA__Result res) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)res;
      i0 = *(OOC_INT8*)((_check_pointer(i0, 26339))+5);
      i0 = i0==9;
      if (!i0) goto l4;
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 26384)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "(", 2);
      i0 = (OOC_INT32)w;
      i1 = (OOC_INT32)instr;
      i1 = OOC_SSA_WriteC__SubclassToBasicType((OOC_SSA__Result)i1);
      i1 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i0, 26430))+24)+(_check_index(i1, 17, OOC_UINT8, 26441))*4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 26414)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, (void*)((_check_pointer(i1, 26470))+1), 32);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 26488)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ")", 2);
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
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 26680)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "RT0__NewObject(", 16);
      i0 = (OOC_INT32)OOC_SSA__InstrDesc_GetOpndClass((OOC_SSA__Instr)i0, 12);
      opnd = (OOC_SSA__Opnd)i0;
      i1 = (OOC_INT32)w;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 26879))+92);
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 26809));
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 26819)))), &_td_OOC_SSA__TypeRefDesc, 26819)), 26827))+44);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 26890))+16);
      i1 = (OOC_INT32)OOC_C_Naming__NameOfTypeDescriptor((OOC_SymbolTable__Type)i2, (OOC_C_Naming__QualTypeData)i1);
      name = (Object__String)i1;
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 26908)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i2, (Object__Object)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 26937)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, ".baseTypes[0]", 14);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26989))+8);
      opnd = (OOC_SSA__Opnd)i0;
      i1 = i0!=0;
      if (i1) goto l3;
      i1=0u;
      goto l5;
l3:
      i1 = *(OOC_INT8*)((_check_pointer(i0, 27033))+4);
      i1 = i1==1;
      
l5:
      if (!i1) goto l16;
l7_loop:
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 27065)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, ", ", 3);
      i1 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i1, (OOC_SSA__Opnd)i0);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27130))+8);
      opnd = (OOC_SSA__Opnd)i0;
      i1 = i0!=0;
      if (i1) goto l10;
      i1=0u;
      goto l12;
l10:
      i1 = *(OOC_INT8*)((_check_pointer(i0, 27033))+4);
      i1 = i1==1;
      
l12:
      if (i1) goto l7_loop;
l16:
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 27160)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ")", 2);
      return;
      ;
    }

    
    void OOC_SSA_WriteC__WriteExpr_NewBlock(OOC_SSA__Instr instr) {
      register OOC_INT32 i0,i1;
      OOC_SSA__Opnd opnd;

      i0 = (OOC_INT32)instr;
      OOC_SSA_WriteC__WriteExpr_CastFromPtr((OOC_SSA__Result)i0);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 27318)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "RT0__NewBlock(", 15);
      i0 = (OOC_INT32)OOC_SSA__InstrDesc_GetOpndClass((OOC_SSA__Instr)i0, 1);
      opnd = (OOC_SSA__Opnd)i0;
      i1 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i1, (OOC_SSA__Opnd)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 27426)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ")", 2);
      return;
      ;
    }

    
    void OOC_SSA_WriteC__WriteExpr_TypeCast(OOC_SSA__Instr instr) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_INT8 destType;
      OOC_INT8 sourceType;

      i0 = (OOC_INT32)instr;
      OOC_SSA_WriteC__WriteExpr_CastFromPtr((OOC_SSA__Result)i0);
      i1 = *(OOC_INT8*)((_check_pointer(i0, 27653))+5);
      i1 = OOC_SSA_Allocator__SubclassToBasicType(i1);
      destType = i1;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27722))+24);
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 27732));
      i2 = *(OOC_INT8*)((_check_pointer(i2, 27737))+5);
      i2 = OOC_SSA_Allocator__SubclassToBasicType(i2);
      sourceType = i2;
      i3 = OOC_SSA_Opcode__ConvDiffersFromCast(i2, i1);
      if (i3) goto l3;
      i3 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 27874)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i3, "_type_cast_fast(", 17);
      goto l4;
l3:
      i3 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 27823)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i3, "_type_cast(", 12);
l4:
      i3 = (OOC_INT32)w;
      i1 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i3, 27944))+24)+(_check_index(i1, 17, OOC_UINT8, 27955))*4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 27928)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i3, (void*)((_check_pointer(i1, 27965))+1), 32);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 27981)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, ", ", 3);
      i1 = (OOC_INT32)w;
      i2 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i1, 28026))+24)+(_check_index(i2, 17, OOC_UINT8, 28037))*4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 28010)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, (void*)((_check_pointer(i2, 28049))+1), 32);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 28065)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, ", ", 3);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28106))+24);
      i1 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i1, (OOC_SSA__Opnd)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 28126)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ")", 2);
      return;
      ;
    }

    
    void OOC_SSA_WriteC__WriteExpr_TypeConv(OOC_SSA__Instr instr) {
      register OOC_INT32 i0,i1,i2;
      OOC_INT8 destType;

      i0 = (OOC_INT32)instr;
      i1 = *(OOC_INT8*)((_check_pointer(i0, 28312))+5);
      i1 = OOC_SSA_Allocator__SubclassToBasicType(i1);
      destType = i1;
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 28332)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i2, "(", 2);
      i2 = (OOC_INT32)w;
      i1 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i2, 28376))+24)+(_check_index(i1, 17, OOC_UINT8, 28387))*4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 28360)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i2, (void*)((_check_pointer(i1, 28397))+1), 32);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 28413)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, ")", 2);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28453))+24);
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
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28605))+24);
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 28615));
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 28621)))), &_td_OOC_SSA__DeclRefDesc);
      if (i1) goto l7;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28789))+24);
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 28799));
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 28805)))), &_td_OOC_SSA__TypeRefDesc);
      if (i1) goto l5;
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 29054)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "OOC_TYPE_TAG(", 14);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29108))+24);
      i1 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i1, (OOC_SSA__Opnd)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 29130)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i0, 41u);
      goto l8;
l5:
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 28835)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 38u);
      i1 = (OOC_INT32)w;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 28981))+92);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28903))+24);
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 28912));
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 28921)))), &_td_OOC_SSA__TypeRefDesc, 28921)), 28929))+44);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 28992))+16);
      i0 = (OOC_INT32)OOC_C_Naming__NameOfTypeDescriptor((OOC_SymbolTable__Type)i0, (OOC_C_Naming__QualTypeData)i1);
      name = (Object__String)i0;
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 29012)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i1, (Object__Object)i0);
      goto l8;
l7:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28690))+24);
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 28700));
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 28710)))), &_td_OOC_SSA__DeclRefDesc, 28710)), 28718))+44);
      i0 = (OOC_INT32)OOC_C_Naming__NameOfTypeTagParam((OOC_SymbolTable__VarDecl)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 28729)))), &_td_OOC_SymbolTable__VarDeclDesc, 28729)));
      name = (Object__String)i0;
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 28749)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i1, (Object__Object)i0);
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
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29322))+24);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 29332))+8);
      opnd = (OOC_SSA__Opnd)i1;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 29362));
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 29372)))), &_td_OOC_SSA__TypeRefDesc, 29372)), 29380))+44);
      type = (OOC_SymbolTable__Type)i1;
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 29404)))), &_td_OOC_SymbolTable__TypeClosureDesc);
      if (i2) goto l3;
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 29531)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i2, "OOC_TYPE_TEST(", 15);
      goto l4;
l3:
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 29470)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i2, "RT0__TypeTest((OOC_PTR)", 24);
l4:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29593))+24);
      i2 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i2, (OOC_SSA__Opnd)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 29613)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ", &", 4);
      i0 = (OOC_INT32)w;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29686))+92);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29697))+16);
      i0 = (OOC_INT32)OOC_C_Naming__NameOfTypeDescriptor((OOC_SymbolTable__Type)i1, (OOC_C_Naming__QualTypeData)i0);
      name = (Object__String)i0;
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 29715)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i1, (Object__Object)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 29744)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ")", 2);
      return;
      ;
    }

    
    void OOC_SSA_WriteC__WriteExpr_TBProcAddress(OOC_SSA__Instr instr) {
      register OOC_INT32 i0,i1,i2;
      Object__String name;

      i0 = (OOC_INT32)instr;
      OOC_SSA_WriteC__WriteExpr_CastFromPtr((OOC_SSA__Result)i0);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 29902)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "OOC_TBPROC_ADR(", 16);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29956))+24);
      i2 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i2, (OOC_SSA__Opnd)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 29976)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, ", ", 3);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30043))+24);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30053))+8);
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 30063));
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 30073)))), &_td_OOC_SSA__DeclRefDesc, 30073)), 30081))+44);
      i0 = (OOC_INT32)OOC_C_Naming__NameOfDeclaration((OOC_SymbolTable__Declaration)i0);
      name = (Object__String)i0;
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 30097)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i1, (Object__Object)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 30126)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ")", 2);
      return;
      ;
    }

    
    void OOC_SSA_WriteC__WriteExpr_VTableProcAddress(OOC_SSA__Instr instr) {
      register OOC_INT32 i0,i1,i2;
      Object__String name;

      i0 = (OOC_INT32)instr;
      OOC_SSA_WriteC__WriteExpr_CastFromPtr((OOC_SSA__Result)i0);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 30294)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "OOC_VTABLEPROC_ADR(", 20);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30352))+24);
      i2 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i2, (OOC_SSA__Opnd)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 30372)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, ", ", 3);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30439))+24);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30449))+8);
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 30459));
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 30469)))), &_td_OOC_SSA__DeclRefDesc, 30469)), 30477))+44);
      i0 = (OOC_INT32)OOC_C_Naming__NameOfDeclaration((OOC_SymbolTable__Declaration)i0);
      name = (Object__String)i0;
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 30493)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i1, (Object__Object)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 30522)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ")", 2);
      return;
      ;
    }

    
    void OOC_SSA_WriteC__WriteExpr_CopyParameter(OOC_SSA__Address instr) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_SymbolTable__VarDecl varDecl;
      Object__String name;

      i0 = (OOC_INT32)instr;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30709))+44);
      i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 30720)))), &_td_OOC_SymbolTable__VarDeclDesc, 30720);
      varDecl = (OOC_SymbolTable__VarDecl)i1;
      i2 = (OOC_INT32)OOC_C_Naming__NameOfDeclaration((OOC_SymbolTable__Declaration)i1);
      name = (Object__String)i2;
      i3 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 30794)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i3);
      i3 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 30812)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i3, "OOC_INITIALIZE_VPAR(", 21);
      i3 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 30859)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i3, (Object__Object)i2);
      i3 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 30888)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i3, "__ref,", 7);
      i3 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 30940)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i3, (Object__Object)i2);
      i2 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriteTypeAndLength((OOC_SSA_WriteC__Writer)i2, (OOC_SSA__Instr)i0, (OOC_SymbolTable__VarDecl)i1, 1u);
      return;
      ;
    }

    
    void OOC_SSA_WriteC__WriteExpr_Copy(OOC_SSA__Instr instr) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_SymbolTable__Type type;

      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 31123)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i0);
      i0 = (OOC_INT32)instr;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31153))+24);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 31163))+8);
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 31173));
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 31183)))), &_td_OOC_SSA__TypeRefDesc, 31183)), 31191))+44);
      type = (OOC_SymbolTable__Type)i1;
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 31206)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i2, "_copy_block(", 13);
      i2 = (OOC_INT32)OOC_SSA__InstrDesc_GetOpndClass((OOC_SSA__Instr)i0, 4);
      i3 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i3, (OOC_SSA__Opnd)i2);
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 31296)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i2, 44u);
      i0 = (OOC_INT32)OOC_SSA__InstrDesc_GetOpndClass((OOC_SSA__Instr)i0, 6);
      i2 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i2, (OOC_SSA__Opnd)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 31374)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i0, 44u);
      i0 = (OOC_INT32)w;
      i1 = *(OOC_INT32*)((_check_pointer(i1, 31417))+32);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 31400)))), OOC_C_DeclWriter__WriterDesc_WriteLInt)),OOC_C_DeclWriter__WriterDesc_WriteLInt)((OOC_C_DeclWriter__Writer)i0, i1, 0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 31436)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ")", 2);
      return;
      ;
    }

    
    OOC_INT32 OOC_SSA_WriteC__WriteExpr_TypeId(OOC_SSA__Result res) {
      register OOC_INT32 i0;

      i0 = (OOC_INT32)res;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 31552)))), &_td_OOC_SSA__TypeRefDesc, 31552)), 31560))+44);
      i0 = *(OOC_INT16*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 31571)))), &_td_OOC_SymbolTable__PredefTypeDesc, 31571)), 31582))+40);
      return i0;
      ;
    }

    
    void OOC_SSA_WriteC__WriteExpr_CopyString(OOC_SSA__Instr instr) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_INT32 source;
      OOC_INT32 dest;

      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 31704)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i0);
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
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 32325)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "_copy_32(", 10);
      goto l18;
l5:
      switch (i2) {
      case 2:
        i1 = (OOC_INT32)w;
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 32142)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "_copy_16(", 10);
        goto l18;
      case 3:
        i1 = (OOC_INT32)w;
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 32199)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "_copy_16to32(", 14);
        goto l18;
      default:
        _failed_case(i2, 32101);
        goto l18;
      }
l12:
      switch (i2) {
      case 1:
        i1 = (OOC_INT32)w;
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 31888)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "_copy_8(", 9);
        goto l18;
      case 2:
        i1 = (OOC_INT32)w;
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 31944)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "_copy_8to16(", 13);
        goto l18;
      case 3:
        i1 = (OOC_INT32)w;
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 32004)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "_copy_8to32(", 13);
        goto l18;
      default:
        _failed_case(i2, 31847);
        goto l18;
      }
l18:
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 32372)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "(const void*)", 14);
      i1 = (OOC_INT32)OOC_SSA__InstrDesc_GetOpndClass((OOC_SSA__Instr)i0, 4);
      i2 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i2, (OOC_SSA__Opnd)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 32463)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, ",(void*)", 9);
      i1 = (OOC_INT32)OOC_SSA__InstrDesc_GetOpndClass((OOC_SSA__Instr)i0, 6);
      i2 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i2, (OOC_SSA__Opnd)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 32550)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 44u);
      i0 = (OOC_INT32)OOC_SSA__InstrDesc_GetOpndClass((OOC_SSA__Instr)i0, 1);
      i1 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i1, (OOC_SSA__Opnd)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32623)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ")", 2);
      return;
      ;
    }

    
    void OOC_SSA_WriteC__WriteExpr_CmpString(OOC_SSA__Instr instr) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32726)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i0);
      i0 = (OOC_INT32)instr;
      i1 = (OOC_INT32)OOC_SSA__InstrDesc_NthArg((OOC_SSA__Instr)i0, 1);
      i1 = OOC_SSA_WriteC__WriteExpr_TypeId((OOC_SSA__Result)i1);
      switch (i1) {
      case 1:
        i1 = (OOC_INT32)w;
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 32801)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "_cmp8((const void*)", 20);
        goto l6;
      case 2:
        i1 = (OOC_INT32)w;
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 32864)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "_cmp16((const void*)", 21);
        goto l6;
      case 3:
        i1 = (OOC_INT32)w;
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 32928)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "_cmp32((const void*)", 21);
        goto l6;
      default:
        _failed_case(i1, 32743);
        goto l6;
      }
l6:
      i0 = (OOC_INT32)OOC_SSA__InstrDesc_GetOpndClass((OOC_SSA__Instr)i0, 4);
      opnd = (OOC_SSA__Opnd)i0;
      i1 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i1, (OOC_SSA__Opnd)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33055)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ",(const void*)", 15);
l7_loop:
      i0 = (OOC_INT32)opnd;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33178))+8);
      opnd = (OOC_SSA__Opnd)i0;
      i1 = *(OOC_INT8*)((_check_pointer(i0, 33207))+4);
      i1 = i1==4;
      if (!i1) goto l7_loop;
l11:
      i1 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i1, (OOC_SSA__Opnd)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33260)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ")", 2);
      return;
      ;
    }

    
    void OOC_SSA_WriteC__WriteExpr_Concat(OOC_SSA__Instr instr) {
      register OOC_INT32 i0,i1,i2;
      OOC_SSA__Opnd opnd;

      i0 = (OOC_INT32)instr;
      OOC_SSA_WriteC__WriteExpr_CastFromPtr((OOC_SSA__Result)i0);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 33413)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "Object__Concat2(", 17);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33483))+24);
      opnd = (OOC_SSA__Opnd)i1;
      i2 = i1!=(OOC_INT32)0;
      if (!i2) goto l11;
l3_loop:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33546))+24);
      i2 = i1!=i2;
      if (!i2) goto l6;
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 33573)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i2, ",", 2);
l6:
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 33615)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i2, "(void*)", 8);
      i2 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i2, (OOC_SSA__Opnd)i1);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 33682))+8);
      opnd = (OOC_SSA__Opnd)i1;
      i2 = i1!=(OOC_INT32)0;
      if (i2) goto l3_loop;
l11:
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33711)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ")", 2);
      return;
      ;
    }

    
    void OOC_SSA_WriteC__WriteExpr_MoveBlock(OOC_SSA__Instr instr) {
      register OOC_INT32 i0,i1,i2;

      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33809)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33827)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "_move_block(", 13);
      i0 = (OOC_INT32)instr;
      i1 = (OOC_INT32)OOC_SSA__InstrDesc_GetOpndClass((OOC_SSA__Instr)i0, 4);
      i2 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i2, (OOC_SSA__Opnd)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 33917)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 44u);
      i1 = (OOC_INT32)OOC_SSA__InstrDesc_GetOpndClass((OOC_SSA__Instr)i0, 6);
      i2 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i2, (OOC_SSA__Opnd)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 33995)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 44u);
      i0 = (OOC_INT32)OOC_SSA__InstrDesc_GetOpndClass((OOC_SSA__Instr)i0, 1);
      i1 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i1, (OOC_SSA__Opnd)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34068)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ")", 2);
      return;
      ;
    }

    
    void OOC_SSA_WriteC__WriteExpr_Shift(OOC_SSA__Instr instr, OOC_CHAR8 rotate) {
      register OOC_INT32 i0,i1,i2;

      i0 = rotate;
      if (i0) goto l3;
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34251)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "_lsh(", 6);
      goto l4;
l3:
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34206)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "_rot(", 6);
l4:
      i0 = (OOC_INT32)w;
      i1 = (OOC_INT32)instr;
      i2 = *(OOC_INT8*)((_check_pointer(i1, 34358))+5);
      i2 = OOC_SSA_Allocator__SubclassToBasicType(i2);
      i2 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i0, 34310))+24)+(_check_index(i2, 17, OOC_UINT8, 34321))*4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34294)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, (void*)((_check_pointer(i2, 34370))+1), 32);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34386)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ", ", 3);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34427))+24);
      i2 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i2, (OOC_SSA__Opnd)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34447)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ", ", 3);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34488))+24);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34498))+8);
      i1 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i1, (OOC_SSA__Opnd)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34518)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ")", 2);
      return;
      ;
    }

    
    void OOC_SSA_WriteC__WriteExpr_Indexed(OOC_SSA__Instr instr) {
      register OOC_INT32 i0,i1,i2;

      i0 = (OOC_INT32)instr;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34624))+24);
      i2 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i2, (OOC_SSA__Opnd)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 34644)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 43u);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34682))+24);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34692))+8);
      i2 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i2, (OOC_SSA__Opnd)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 34712)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 42u);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34750))+24);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34760))+8);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34770))+8);
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

      i0 = adrClass;
      i1 = (OOC_INT32)instr;
      i0 = (OOC_INT32)OOC_SSA__InstrDesc_GetOpndClass((OOC_SSA__Instr)i1, i0);
      opnd = (OOC_SSA__Opnd)i0;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 35016));
      adr = (OOC_SSA__Result)i1;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35043))+8);
      design = (OOC_SSA__Opnd)i0;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 35069)))), &_td_OOC_SSA__AddressDesc);
      if (i1) goto l3;
      i0=0u;
      goto l9;
l3:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35104))+8);
      i1 = i1==0;
      if (i1) goto l6;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35142))+8);
      i1 = *(OOC_INT8*)((_check_pointer(i1, 35152))+4);
      i0 = *(OOC_INT8*)((_check_pointer(i0, 35168))+4);
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
      _failed_function(34815); return 0;
      ;
    }

    
    void OOC_SSA_WriteC__WriteExpr_PreloadedVar(OOC_SSA__Instr instr) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_INT32 id;
      OOC_C_DeclWriter__Writer wd;

      i0 = (OOC_INT32)w;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35535))+92);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35546))+36);
      i1 = (OOC_INT32)instr;
      i0 = OOC_SSA_WriteC__GetPreloadId((ADT_Dictionary_IntValue__Dictionary)i0, (OOC_SSA__Instr)i1);
      id = i0;
      OOC_SSA_WriteC__WriteExpr_CastFromPtr((OOC_SSA__Result)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 35603)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "_c", 3);
      i1 = (OOC_INT32)w;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 35642))+8);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 35642))+8);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 35653)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i1, i0, 0);
      i1 = (OOC_INT32)w;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 35686))+92);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 35697))+4);
      wd = (OOC_C_DeclWriter__Writer)i1;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 35710)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "static void* _c", 16);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 35766))+8);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 35766))+8);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 35777)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i3, i0, 0);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 35804)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, ";", 2);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 35831)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i1);
      return;
      ;
    }


  i0 = (OOC_INT32)instr;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 35888))+36);
  switch (i1) {
  case 12:
    OOC_SSA_WriteC__WriteExpr_CastFromPtr((OOC_SSA__Result)i0);
    i0 = (OOC_INT32)instr;
    i0 = OOC_SSA_WriteC__WriteExpr_SimpleVarAccess((OOC_SSA__Instr)i0, 4);
    if (i0) goto l5;
    i0 = (OOC_INT32)w;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36072)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "*(", 3);
    i1 = (OOC_INT32)instr;
    i2 = OOC_SSA_WriteC__SubclassToBasicType((OOC_SSA__Result)i1);
    i2 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i0, 36119))+24)+(_check_index(i2, 17, OOC_UINT8, 36155))*4);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36103)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, (void*)((_check_pointer(i2, 36184))+1), 32);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36202)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "*)", 3);
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 36245))+24);
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 36255))+8);
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
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 36311)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i1);
    i0 = OOC_SSA_WriteC__WriteExpr_SimpleVarAccess((OOC_SSA__Instr)i0, 6);
    if (i0) goto l10;
    i0 = (OOC_INT32)w;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36616)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "*(", 3);
    i1 = (OOC_INT32)instr;
    i2 = OOC_SSA_WriteC__SubclassToBasicType((OOC_SSA__Result)i1);
    i2 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i0, 36663))+24)+(_check_index(i2, 17, OOC_UINT8, 36699))*4);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36647)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, (void*)((_check_pointer(i2, 36728))+1), 32);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36746)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "*)", 3);
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 36789))+24);
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 36799))+8);
    OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i0, (OOC_SSA__Opnd)i2);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36821)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, " = ", 4);
    {register OOC_INT32 h0=i0;i0=i1;i1=h0;}
    goto l11;
l10:
    i0 = (OOC_INT32)instr;
    i1 = (OOC_INT32)OOC_SSA__InstrDesc_GetOpndClass((OOC_SSA__Instr)i0, 7);
    i2 = (OOC_INT32)w;
    OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i2, (OOC_SSA__Opnd)i1);
    i1 = (OOC_INT32)OOC_SSA__InstrDesc_GetArgClass((OOC_SSA__Instr)i0, 7);
    var = (OOC_SSA__Result)i1;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 36495)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i2, " = ", 4);
    i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 36553)))), &_td_OOC_SSA__DeclRefDesc, 36553)), 36561))+44);
    i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 36572)))), &_td_OOC_SymbolTable__VarDeclDesc, 36572)), 36580))+48);
    OOC_SSA_WriteC__CastToPtr((OOC_SSA_WriteC__Writer)i2, (OOC_SSA__Result)i1, (OOC_SymbolTable__Type)i3, 0u);
    i1=i2;
l11:
    i0 = (OOC_INT32)OOC_SSA__InstrDesc_GetOpndClass((OOC_SSA__Instr)i0, 8);
    OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i1, (OOC_SSA__Opnd)i0);
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
    OOC_SSA_WriteC__WriteExpr_CopyParameter((OOC_SSA__Address)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37380)))), &_td_OOC_SSA__AddressDesc, 37380)));
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
    i1 = *(OOC_INT8*)((_check_pointer(i0, 38071))+5);
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
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 39990)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i1);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 40008)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "_halt(", 7);
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 40053))+24);
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 40063))+8);
    OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i1, (OOC_SSA__Opnd)i0);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 40083)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, ")", 2);
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
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 40330))+24);
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 40340))+8);
    OOC_SSA_WriteC__WriteExpr_FailedCheck((OOC_SSA__Instr)i0, "_failed_case", 13, (OOC_SSA__Opnd)i1);
    goto l82;
  case 70:
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 40425))+24);
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 40435))+8);
    OOC_SSA_WriteC__WriteExpr_FailedCheck((OOC_SSA__Instr)i0, "_failed_with", 13, (OOC_SSA__Opnd)i1);
    goto l82;
  case 71:
    OOC_SSA_WriteC__WriteExpr_FailedCheck((OOC_SSA__Instr)i0, "_failed_type_assert", 20, (OOC_SSA__Opnd)(OOC_INT32)0);
    goto l82;
  case 55:
    i1 = (OOC_INT32)w;
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 40571))+96);
    i2 = ADT_Dictionary__DictionaryDesc_HasKey((ADT_Dictionary__Dictionary)i2, (Object__Object)i0);
    i2 = !i2;
    if (i2) goto l77;
    OOC_SSA_WriteC__WriteExpr_CastFromPtr((OOC_SSA__Result)i0);
    goto l78;
l77:
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 40615)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i1);
l78:
    i0 = (OOC_INT32)instr;
    OOC_SSA_WriteC__WriteExpr_Call((OOC_SSA__Instr)i0);
    goto l82;
  case 76:
    OOC_SSA_WriteC__WriteExpr_CastFromPtr((OOC_SSA__Result)i0);
    i0 = (OOC_INT32)w;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 40762)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "Exception__Current()", 21);
    goto l82;
  case 81:
    OOC_SSA_WriteC__WriteExpr_PreloadedVar((OOC_SSA__Instr)i0);
    goto l82;
  default:
    _failed_case(i1, 35878);
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
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 41327)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i0);
      i0 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_ClearSwapData((OOC_SSA_WriteC__Writer)i0);
      i0 = (OOC_INT32)collect;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 41503))+24);
      opnd = (OOC_SSA__Opnd)i1;
      i2 = (OOC_INT32)targetInstr;
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 41539));
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
      i4 = *(OOC_INT8*)((_check_pointer(i1, 41623))+4);
      i4 = i4!=2;
      if (!i4) goto l13;
      i4 = (OOC_INT32)w;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 41674))+96);
      i4 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i4, (Object__Object)i3);
      targetVar = (Object__Object)i4;
      i5 = (OOC_INT32)w;
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 41714))+96);
      i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 41741));
      i5 = ADT_Dictionary__DictionaryDesc_HasKey((ADT_Dictionary__Dictionary)i5, (Object__Object)i6);
      if (!i5) goto l13;
      i5 = (OOC_INT32)w;
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 41779))+96);
      i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 41803));
      i5 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i5, (Object__Object)i6);
      sourceVar = (Object__Object)i5;
      i6 = OOC_SSA_WriteC__SubclassToBasicType((OOC_SSA__Result)i3);
      i7 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_AddSwapData((OOC_SSA_WriteC__Writer)i7, (Object__String)(_type_guard(i5, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 41849)))), &_td_Object__StringDesc, 41849)), (Object__String)(_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 41896)))), &_td_Object__StringDesc, 41896)), i6);
l13:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 42008))+8);
      opnd = (OOC_SSA__Opnd)i1;
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 42030));
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
      i1 = *(OOC_INT32*)((_check_pointer(i1, 42220))+112);
      i1 = i1!=0;
      if (!i1) goto l51;
l25_loop:
      i = 0;
      i1 = (OOC_INT32)w;
      i3 = *(OOC_INT32*)((_check_pointer(i1, 42282))+112);
      i3 = 0!=i3;
      if (i3) goto l28;
      i3=0u;
      goto l30;
l28:
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 42305))+108);
      i3 = _check_pointer(i3, 42316);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = *(OOC_INT32*)((i3+((_check_index(0, i4, OOC_UINT32, 42316))*16))+8);
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
      i4 = *(OOC_INT32*)((_check_pointer(i1, 42282))+112);
      i4 = i3!=i4;
      if (i4) goto l36;
      i4=0u;
      goto l38;
l36:
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 42305))+108);
      i4 = _check_pointer(i4, 42316);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = *(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 42316))*16))+8);
      i4 = i4!=0;
      
l38:
      if (i4) goto l33_loop;
l42:
      i4 = *(OOC_INT32*)((_check_pointer(i1, 42388))+112);
      i4 = i3==i4;
      if (i4) goto l45;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 42547))+108);
      i4 = _check_pointer(i4, 42558);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 42558))*16))+4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 42531)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i1, (Object__Object)i4);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 42581)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "=", 2);
      i1 = (OOC_INT32)w;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 42629))+108);
      i4 = _check_pointer(i4, 42640);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+((_check_index(i3, i5, OOC_UINT32, 42640))*16));
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 42613)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i1, (Object__Object)i4);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 42665)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 59u);
      i1 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_RemoveSwapData((OOC_SSA_WriteC__Writer)i1, i3);
      goto l46;
l45:
      OOC_SSA_WriteC__WriterDesc_IntroduceHelperVar((OOC_SSA_WriteC__Writer)i1, 0);
l46:
      i1 = (OOC_INT32)w;
      i1 = *(OOC_INT32*)((_check_pointer(i1, 42220))+112);
      i1 = i1!=0;
      if (i1) goto l25_loop;
l51:
      i1 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_FixupHelperVars((OOC_SSA_WriteC__Writer)i1);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 42872))+24);
      opnd = (OOC_SSA__Opnd)i0;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 42908));
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
      i2 = *(OOC_INT8*)((_check_pointer(i0, 42992))+4);
      i2 = i2!=2;
      if (!i2) goto l64;
      i2 = (OOC_INT32)w;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 43043))+96);
      i2 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i2, (Object__Object)i1);
      targetVar = (Object__Object)i2;
      i3 = (OOC_INT32)w;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 43084))+96);
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 43111));
      i3 = ADT_Dictionary__DictionaryDesc_HasKey((ADT_Dictionary__Dictionary)i3, (Object__Object)i4);
      i3 = !i3;
      if (!i3) goto l64;
      i3 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 43136)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i3, (Object__Object)i2);
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 43176)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i2, "=", 2);
      i2 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i2, (OOC_SSA__Opnd)i0);
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 43237)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i2, 59u);
l64:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 43303))+8);
      opnd = (OOC_SSA__Opnd)i0;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 43325));
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
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 43466)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i0);
      return;
      ;
    }

    
    OOC_CHAR8 OOC_SSA_WriteC__WriterDesc_WriteInstrList_AllPathsClosed(OOC_SSA__Instr selectReturn) {
      register OOC_INT32 i0,i1;
      OOC_SSA__Opnd opnd;

      i0 = (OOC_INT32)selectReturn;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 43979))+24);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 43989))+8);
      opnd = (OOC_SSA__Opnd)i0;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 44018))+8);
      i1 = i1!=(OOC_INT32)0;
      if (!i1) goto l9;
l4_loop:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 44059))+8);
      opnd = (OOC_SSA__Opnd)i0;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 44018))+8);
      i1 = i1!=(OOC_INT32)0;
      if (i1) goto l4_loop;
l9:
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 44100));
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 44105))+8);
      i0 = *(OOC_INT8*)((_check_pointer(i0, 44112))+36);
      return (i0==7);
      ;
    }


  i0 = (OOC_INT32)b;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 44186))+8);
  proxy = (OOC_SSA_Schedule__InstrProxy)i0;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l65;
l3_loop:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 44246))+12);
  instr = (OOC_SSA__Instr)i0;
  target = (Object__Object)(OOC_INT32)0;
  i1 = (OOC_INT32)w;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 44483))+96);
  i2 = ADT_Dictionary__DictionaryDesc_HasKey((ADT_Dictionary__Dictionary)i2, (Object__Object)i0);
  if (i2) goto l6;
  i2=(OOC_INT32)0;
  goto l10;
l6:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 44537))+96);
  i2 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i2, (Object__Object)i0);
  target = (Object__Object)i2;
  i3 = (OOC_INT32)OOC_SSA_Allocator__markInPlace;
  i3 = i2!=i3;
  if (!i3) goto l10;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 44625)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 44790)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i1, (Object__Object)i2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 44825)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, " = ", 4);
l10:
  i3 = (OOC_INT32)OOC_SSA_Allocator__markInPlace;
  i2 = i2!=i3;
  if (!i2) goto l60;
  i2 = *(OOC_INT8*)((_check_pointer(i0, 45085))+36);
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
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 46294)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "return", 7);
    
    goto l30;
l29:
    i1 = (OOC_INT32)w;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 46096)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "return ", 8);
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 46184))+104);
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 46195))+20);
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 46205))+64);
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 46217))+44);
    i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 46153));
    OOC_SSA_WriteC__CastToPtr((OOC_SSA_WriteC__Writer)i1, (OOC_SSA__Result)i3, (OOC_SymbolTable__Type)i2, 0u);
    OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i1, (OOC_SSA__Opnd)i0);
    i0=i1;
l30:
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 46345)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i0, 59u);
    goto l60;
  case 8:
    i0 = OOC_SSA_WriteC__WriterDesc_WriteInstrList_AllPathsClosed((OOC_SSA__Instr)i0);
    i0 = !i0;
    if (!i0) goto l60;
    OOC_SSA_WriteC__WriterDesc_WriteInstrList_PrefixReturn();
    i0 = (OOC_INT32)w;
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 46495))+104);
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 46505))+20);
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 46514))+64);
    fpars = (OOC_SymbolTable__FormalPars)i1;
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 46548))+44);
    i2 = i2!=(OOC_INT32)0;
    if (i2) goto l39;
    i1 = *(OOC_UINT8*)((_check_pointer(i1, 46937))+57);
    i1 = !i1;
    if (!i1) goto l60;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 46967)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "return;", 8);
    goto l60;
l39:
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 46590))+104);
    i2 = *(OOC_UINT8*)((_check_pointer(i2, 46601))+24);
    if (!i2) goto l42;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 46645)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "_failed_function(", 18);
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 46713))+104);
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 46724))+20);
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 46734))+20);
    i2 = *(OOC_INT32*)(_check_pointer(i2, 46740));
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 46699)))), OOC_C_DeclWriter__WriterDesc_WriteLInt)),OOC_C_DeclWriter__WriterDesc_WriteLInt)((OOC_C_DeclWriter__Writer)i0, i2, 0);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 46768)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "); ", 4);
l42:
    i1 = *(OOC_UINT8*)((_check_pointer(i1, 46833))+57);
    i1 = !i1;
    if (!i1) goto l60;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 46865)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "return 0;", 10);
    goto l60;
  case 72:
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 47074)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i1);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 47095)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "{", 2);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 47125)))), OOC_C_DeclWriter__WriterDesc_Indent)),OOC_C_DeclWriter__WriterDesc_Indent)((OOC_C_DeclWriter__Writer)i1, 1);
    goto l60;
  case 73:
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 47173)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, ";", 2);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 47203)))), OOC_C_DeclWriter__WriterDesc_Indent)),OOC_C_DeclWriter__WriterDesc_Indent)((OOC_C_DeclWriter__Writer)i1, (-1));
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 47227)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i1);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 47248)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "}", 2);
    goto l60;
  case 74:
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 47311)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i1);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 47332)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "Exception__Raise((void*)", 25);
    i0 = (OOC_INT32)OOC_SSA__InstrDesc_NthOpnd((OOC_SSA__Instr)i0, 1);
    OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i1, (OOC_SSA__Opnd)i0);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 47420)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, ");", 3);
    goto l60;
  case 78:
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 47490)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i1);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 47511)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "Exception__PushContext(&", 25);
    i0 = (OOC_INT32)OOC_SSA_WriteC__WriteExceptionContext((OOC_SSA_WriteC__Writer)i1, (OOC_SSA__Instr)i0);
    obj = (Object__Object)i0;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 47614)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, ", &_target", 11);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 47653)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i1, (Object__Object)i0);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 47683)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, ");", 3);
    goto l60;
  case 79:
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 47752)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i1);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 47773)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "Exception__PopContext(", 23);
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 47846))+24);
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 47855))+8);
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 47864));
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 47873)))), &_td_OOC_SSA__ConstDesc, 47873)), 47879))+44);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 47824)))), OOC_C_DeclWriter__WriterDesc_WriteBasicConst)),OOC_C_DeclWriter__WriterDesc_WriteBasicConst)((OOC_C_DeclWriter__Writer)i1, (Object_Boxed__Object)i0, 4);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 47945)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, ");", 3);
    goto l60;
  case 77:
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 48009)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i1);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 48030)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "Exception__Clear();", 20);
    goto l60;
  case 80:
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 48112)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i1);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 48133)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "Exception__ActivateContext();", 30);
    goto l60;
  default:
    OOC_SSA_WriteC__WriteExpr((OOC_SSA_WriteC__Writer)i1, (OOC_SSA__Instr)i0);
    i0 = OOC_SSA__InstrDesc_IsConst((OOC_SSA__Instr)i0);
    i0 = !i0;
    if (!i0) goto l60;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 48316)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 59u);
    goto l60;
  }
l60:
  i0 = (OOC_INT32)proxy;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 48401));
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
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 48873)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "l", 2);
      i1 = (OOC_INT32)w;
      i2 = *(OOC_INT32*)((_check_pointer(i0, 48917))+40);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 48903)))), OOC_C_DeclWriter__WriterDesc_WriteLInt)),OOC_C_DeclWriter__WriterDesc_WriteLInt)((OOC_C_DeclWriter__Writer)i1, i2, 0);
      i0 = *(OOC_UINT8*)((_check_pointer(i0, 48939))+28);
      if (!i0) goto l7;
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 48968)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "_loop", 6);
      goto l7;
l6:
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 48812)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "XXX WriteBlockId(NIL)", 22);
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
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 49201)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "goto ", 6);
      OOC_SSA_WriteC__WriterDesc_WriteBlocks_WriteBlockId((OOC_SSA_Schedule__Block)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 49266)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i0, 59u);
      goto l4;
l3:
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 49138)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "/* goto: unreachable */", 24);
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
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 49581));
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
          i1 = *(OOC_INT8*)((_check_pointer(i0, 49750))+36);
          i1 = i1==82;
          if (i1) goto l3;
          i0 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 50313)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i0);
          i0 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 50335)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "default:", 9);
          goto l15;
l3:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 49804))+24);
          opnd = (OOC_SSA__Opnd)i0;
          i1 = i0!=(OOC_INT32)0;
          if (!i1) goto l15;
l6_loop:
          lower = (OOC_SSA__Opnd)i0;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 49899))+8);
          opnd = (OOC_SSA__Opnd)i1;
          upper = (OOC_SSA__Opnd)i1;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 49962))+8);
          opnd = (OOC_SSA__Opnd)i2;
          i3 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 50000)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i3);
          i3 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 50024)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i3, "case ", 6);
          i3 = (OOC_INT32)w;
          OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i3, (OOC_SSA__Opnd)i0);
          i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 50111));
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 50098));
          i0 = i0!=i3;
          if (!i0) goto l9;
          i0 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 50138)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, " ... ", 6);
          i0 = (OOC_INT32)w;
          OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i0, (OOC_SSA__Opnd)i1);
l9:
          i0 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 50253)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ":", 2);
          i0 = i2!=(OOC_INT32)0;
          if (!i0) goto l15;
          i0=i2;
          goto l6_loop;
l15:
          return;
          ;
        }


      i0 = (OOC_INT32)b;
      i1 = *(OOC_INT32*)((_check_pointer(i0, 50424))+36);
      i1 = i1!=0;
      if (i1) goto l3;
      i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 50447)))), &_td_OOC_SSA_Schedule__JumpBlockDesc));
      
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
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 50548)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i1);
      i1 = (OOC_INT32)registeredGoto;
      OOC_SSA_WriteC__WriterDesc_WriteBlocks_WriteGoto((OOC_SSA_Schedule__Block)i1);
      registeredGoto = (OOC_SSA_Schedule__Block)(OOC_INT32)0;
l13:
      i1 = *(OOC_INT32*)((_check_pointer(i0, 50658))+36);
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
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 50774)))), OOC_C_DeclWriter__WriterDesc_WriteLn)),OOC_C_DeclWriter__WriterDesc_WriteLn)((OOC_C_DeclWriter__Writer)i1);
      OOC_SSA_WriteC__WriterDesc_WriteBlocks_WriteBlockId((OOC_SSA_Schedule__Block)i0);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 50824)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 58u);
l20:
      i1 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_WriteInstrList((OOC_SSA_WriteC__Writer)i1, (OOC_SSA_Schedule__Block)i0);
l21:
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 50917)))), &_td_OOC_SSA_Schedule__BranchBlockDesc);
      if (i1) goto l56;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 51588)))), &_td_OOC_SSA_Schedule__SwitchBlockDesc);
      if (i1) goto l37;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 52369)))), &_td_OOC_SSA_Schedule__JumpBlockDesc);
      if (i1) goto l32;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 52569)))), &_td_OOC_SSA_Schedule__DeadEndBlockDesc);
      if (i1) goto l30;
      _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 52566)))), 52566);
      goto l67;
l30:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 52618))+16);
      OOC_SSA_WriteC__WriterDesc_WriteBlocks_WriteBlock_WriteNested((OOC_SSA_Schedule__Block)i0);
      goto l67;
l32:
      i1 = *(OOC_INT32*)((_check_pointer(i0, 52406))+36);
      i1 = i1!=0;
      if (!i1) goto l35;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 52498))+48);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 52504))+4);
      registeredGoto = (OOC_SSA_Schedule__Block)i1;
l35:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 52547))+16);
      OOC_SSA_WriteC__WriterDesc_WriteBlocks_WriteBlock_WriteNested((OOC_SSA_Schedule__Block)i0);
      goto l67;
l37:
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 51623)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 51643)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "switch (", 9);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 51688))+48);
      i2 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i2, (OOC_SSA__Opnd)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 51706)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, ") {", 4);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 51759))+16);
      nested = (OOC_SSA_Schedule__Block)i1;
      i = 0;
      i2 = i1!=(OOC_INT32)0;
      if (i2) goto l40;
      i2=0u;
      goto l42;
l40:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 51820))+52);
      i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 51826)), 0);
      i2 = 0!=i2;
      
l42:
      if (i2) goto l44;
      i0=i1;
      goto l54;
l44:
      {register OOC_INT32 h0=i0;i0=i1;i1=h0;}i2=0;
l45_loop:
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 51861))+52);
      i3 = _check_pointer(i3, 51867);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 51867))*4);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 51870))+4);
      _assert((i0==i3), 127, 51843);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 51902))+60);
      i0 = _check_pointer(i0, 51914);
      i1 = OOC_ARRAY_LENGTH(i0, 0);
      i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(i2, i1, OOC_UINT32, 51914))*4);
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 51917));
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 51922))+8);
      OOC_SSA_WriteC__WriterDesc_WriteBlocks_WriteBlock_WriteCases((OOC_SSA__Instr)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 51954)))), OOC_C_DeclWriter__WriterDesc_Indent)),OOC_C_DeclWriter__WriterDesc_Indent)((OOC_C_DeclWriter__Writer)i0, 1);
      i0 = (OOC_INT32)b;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 51997))+52);
      i1 = _check_pointer(i1, 52003);
      i2 = OOC_ARRAY_LENGTH(i1, 0);
      i3 = i;
      i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(i3, i2, OOC_UINT32, 52003))*4);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 52006))+4);
      registeredGoto = (OOC_SSA_Schedule__Block)i1;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 52037))+52);
      i1 = _check_pointer(i1, 52043);
      i2 = OOC_ARRAY_LENGTH(i1, 0);
      i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(i3, i2, OOC_UINT32, 52043))*4);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 52046))+4);
      OOC_SSA_WriteC__WriterDesc_WriteBlocks_WriteBlock((OOC_SSA_Schedule__Block)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 52066)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i1);
      i1 = (OOC_INT32)registeredGoto;
      OOC_SSA_WriteC__WriterDesc_WriteBlocks_WriteGoto((OOC_SSA_Schedule__Block)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 52126)))), OOC_C_DeclWriter__WriterDesc_Indent)),OOC_C_DeclWriter__WriterDesc_Indent)((OOC_C_DeclWriter__Writer)i1, (-1));
      i1 = (OOC_INT32)nested;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 52167));
      nested = (OOC_SSA_Schedule__Block)i1;
      i2 = i3+1;
      i = i2;
      i3 = i1!=(OOC_INT32)0;
      if (i3) goto l48;
      i3=0u;
      goto l50;
l48:
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 51820))+52);
      i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 51826)), 0);
      i3 = i2!=i3;
      
l50:
      if (!i3) goto l53;
      {register OOC_INT32 h0=i0;i0=i1;i1=h0;}
      goto l45_loop;
l53:
      i0=i1;
l54:
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 52222));
      _assert((i1==(OOC_INT32)0), 127, 52208);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 52249)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 52269)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "}", 2);
      registeredGoto = (OOC_SSA_Schedule__Block)(OOC_INT32)0;
      OOC_SSA_WriteC__WriterDesc_WriteBlocks_WriteBlock_WriteNested((OOC_SSA_Schedule__Block)i0);
      goto l67;
l56:
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 50952)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 50972)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "if (", 5);
      i1 = (OOC_INT32)OOC_SSA_Schedule__BranchBlockDesc_DefaultTarget((OOC_SSA_Schedule__BranchBlock)i0);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 51030))+48);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 51036))+4);
      i1 = i1==i2;
      if (i1) goto l62;
      i1 = *(OOC_UINT8*)((_check_pointer(i0, 51307))+56);
      if (!i1) goto l61;
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 51340)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 33u);
l61:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 51392))+52);
      i2 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i2, (OOC_SSA__Opnd)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 51417)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, ") ", 3);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 51461))+48);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 51467))+4);
      OOC_SSA_WriteC__WriterDesc_WriteBlocks_WriteGoto((OOC_SSA_Schedule__Block)i1);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 51505))+60);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 51515))+4);
      registeredGoto = (OOC_SSA_Schedule__Block)i1;
      goto l66;
l62:
      i1 = *(OOC_UINT8*)((_check_pointer(i0, 51064))+56);
      i1 = !i1;
      if (!i1) goto l65;
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 51097)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 33u);
l65:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 51149))+52);
      i2 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i2, (OOC_SSA__Opnd)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 51174)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, ") ", 3);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 51218))+60);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 51228))+4);
      OOC_SSA_WriteC__WriterDesc_WriteBlocks_WriteGoto((OOC_SSA_Schedule__Block)i1);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 51266))+48);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 51272))+4);
      registeredGoto = (OOC_SSA_Schedule__Block)i1;
l66:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 51558))+16);
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
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 53197)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 53216)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "jmp_buf ", 9);
      i1 = ADT_Dictionary__DictionaryDesc_Size((ADT_Dictionary__Dictionary)i0);
      i = 0;
      i2 = 0<i1;
      if (!i2) goto l13;
      i2=0;
l5_loop:
      i3 = i2!=0;
      if (!i3) goto l8;
      i3 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 53313)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i3, ", ", 3);
l8:
      i3 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 53348)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i3, "_target", 8);
      i3 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 53374)))), OOC_C_DeclWriter__WriterDesc_WriteLInt)),OOC_C_DeclWriter__WriterDesc_WriteLInt)((OOC_C_DeclWriter__Writer)i3, i2, 0);
      i2 = i2+1;
      i = i2;
      i3 = i2<i1;
      if (i3) goto l5_loop;
l13:
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 53414)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, ";", 2);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 53443)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 53462)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "Exception__Context ", 20);
      i0 = ADT_Dictionary__DictionaryDesc_Size((ADT_Dictionary__Dictionary)i0);
      i = 0;
      i1 = 0<i0;
      if (!i1) goto l24;
      i1=0;
l16_loop:
      i2 = i1!=0;
      if (!i2) goto l19;
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 53570)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i2, ", ", 3);
l19:
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 53605)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i2, "_context", 9);
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 53632)))), OOC_C_DeclWriter__WriterDesc_WriteLInt)),OOC_C_DeclWriter__WriterDesc_WriteLInt)((OOC_C_DeclWriter__Writer)i2, i1, 0);
      i1 = i1+1;
      i = i1;
      i2 = i1<i0;
      if (i2) goto l16_loop;
l24:
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 53672)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ";", 2);
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
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 53840))+24);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 53840))+24);
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 53854)))), StringSearch__MatcherDesc_MatchChars)),StringSearch__MatcherDesc_MatchChars)((StringSearch__Matcher)i0, (void*)(OOC_INT32)pre, pre_0d, 0, (-1));
      i0 = i0!=(OOC_INT32)0;
      if (i0) goto l6;
      i0 = (OOC_INT32)t;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 53902))+24);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 53902))+24);
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 53916)))), StringSearch__MatcherDesc_MatchChars)),StringSearch__MatcherDesc_MatchChars)((StringSearch__Matcher)i0, (void*)(OOC_INT32)post, post_0d, 0, (-1));
      i0 = i0!=(OOC_INT32)0;
      
      goto l9;
l6:
      i0=1u;
l9:
      if (!i0) goto l11;
      Err__String("PROCEDURE ", 11);
      i0 = (OOC_INT32)pb;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 54013))+20);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 54023))+20);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 54029))+12);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 54013))+20);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 54023))+20);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 54029))+12);
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 54034)), 0);
      Err__String((void*)(_check_pointer(i0, 54034)), i1);
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
      i0 = (OOC_INT32)pb;
      i1 = (OOC_INT32)Object__NewLatin1((void*)(OOC_INT32)pre, pre_0d);
      OOC_SSA_Stats__AddProcBlock((Object__String)i1, (OOC_SSA__ProcBlock)i0);
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
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 54583))+4);
          i1 = *(OOC_UINT8*)((_check_pointer(i1, 54589))+28);
          i1 = !i1;
          if (i1) goto l3;
          i1=0u;
          goto l5;
l3:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 54637))+4);
          i2 = (OOC_INT32)w;
          i1 = OOC_SSA_WriteC__WriterDesc_EmptyBlock((OOC_SSA_WriteC__Writer)i2, (OOC_SSA_Schedule__Block)i1);
          
l5:
          if (i1) goto l7;
          i1=0u;
          goto l9;
l7:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 54666))+4);
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 54679));
          i1 = i1!=i2;
          
l9:
          if (!i1) goto l24;
l11_loop:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 54774))+4);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 54789)))), &_td_OOC_SSA_Schedule__JumpBlockDesc, 54789)), 54799))+48);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 54804))+4);
          OOC_SSA_Schedule__ChangeJumpTarget((OOC_SSA_Schedule__Jump)i0, (OOC_SSA_Schedule__Block)i1);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 54583))+4);
          i1 = *(OOC_UINT8*)((_check_pointer(i1, 54589))+28);
          i1 = !i1;
          if (i1) goto l14;
          i1=0u;
          goto l16;
l14:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 54637))+4);
          i2 = (OOC_INT32)w;
          i1 = OOC_SSA_WriteC__WriterDesc_EmptyBlock((OOC_SSA_WriteC__Writer)i2, (OOC_SSA_Schedule__Block)i1);
          
l16:
          if (i1) goto l18;
          i1=0u;
          goto l20;
l18:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 54666))+4);
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 54679));
          i1 = i1!=i2;
          
l20:
          if (i1) goto l11_loop;
l24:
          return;
          ;
        }


      i0 = (OOC_INT32)b;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 54869)))), &_td_OOC_SSA_Schedule__BranchBlockDesc);
      if (i1) goto l13;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 54967)))), &_td_OOC_SSA_Schedule__SwitchBlockDesc);
      if (i1) goto l14;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 55056)))), &_td_OOC_SSA_Schedule__JumpBlockDesc);
      if (i1) goto l10;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 55115)))), &_td_OOC_SSA_Schedule__DeadEndBlockDesc);
      if (i1) goto l14;
      _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 55112)))), 55112);
      goto l14;
l10:
      OOC_SSA_WriteC__TranslatorDesc_WriteProcBody_JumpChaining_Chain((void*)((_check_pointer(i0, 55096))+48));
      goto l14;
l13:
      OOC_SSA_WriteC__TranslatorDesc_WriteProcBody_JumpChaining_Chain((void*)((_check_pointer(i0, 54911))+48));
      i0 = (OOC_INT32)b;
      OOC_SSA_WriteC__TranslatorDesc_WriteProcBody_JumpChaining_Chain((void*)((_check_pointer(i0, 54936))+60));
l14:
      i0 = (OOC_INT32)b;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 55199))+16);
      nested = (OOC_SSA_Schedule__Block)i0;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l22;
l17_loop:
      OOC_SSA_WriteC__TranslatorDesc_WriteProcBody_JumpChaining((OOC_SSA_Schedule__Block)i0);
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 55295));
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
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 55656)))), &_td_OOC_SSA_Schedule__BranchBlockDesc);
      if (!i1) goto l18;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 55695))+60);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 55705))+4);
      i1 = *(OOC_INT32*)((_check_pointer(i1, 55711))+40);
      i2 = *(OOC_INT32*)((_check_pointer(i0, 55719))+40);
      i1 = i1>i2;
      if (i1) goto l5;
      i1=0u;
      goto l7;
l5:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 55740))+48);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 55746))+4);
      i1 = *(OOC_INT32*)((_check_pointer(i1, 55752))+40);
      i2 = *(OOC_INT32*)((_check_pointer(i0, 55761))+40);
      i1 = i1<=i2;
      
l7:
      if (i1) goto l16;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 55915))+60);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 55925))+4);
      i2 = *(OOC_INT32*)((_check_pointer(i0, 55907))+40);
      i1 = *(OOC_INT32*)((_check_pointer(i1, 55931))+40);
      i1 = i2<i1;
      if (i1) goto l11;
      i1=0u;
      goto l13;
l11:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 55955))+60);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 55965))+4);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 55979))+48);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 55985))+4);
      i1 = *(OOC_INT32*)((_check_pointer(i1, 55971))+40);
      i2 = *(OOC_INT32*)((_check_pointer(i2, 55991))+40);
      i1 = i1<i2;
      
l13:
      if (!i1) goto l18;
      OOC_SSA_WriteC__TranslatorDesc_WriteProcBody_FixCrossJumps_Switch((void*)((_check_pointer(i0, 56075))+56), (void*)((_check_pointer(i0, 56092))+60), (void*)((_check_pointer(i0, 56105))+48));
      goto l18;
l16:
      OOC_SSA_WriteC__TranslatorDesc_WriteProcBody_FixCrossJumps_Switch((void*)((_check_pointer(i0, 55852))+56), (void*)((_check_pointer(i0, 55869))+60), (void*)((_check_pointer(i0, 55882))+48));
l18:
      i0 = (OOC_INT32)b;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 56194))+16);
      nested = (OOC_SSA_Schedule__Block)i0;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l26;
l21_loop:
      OOC_SSA_WriteC__TranslatorDesc_WriteProcBody_FixCrossJumps((OOC_SSA_Schedule__Block)i0);
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 56291));
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
      i2 = OOC_ARRAY_LENGTH((_check_pointer(i1, 56641)), 0);
      i2 = (OOC_INT32)RT0__NewObject(_td_Object__ObjectArrayPtr.baseTypes[0], i2);
      varList = (Object__ObjectArrayPtr)i2;
      i = 0;
      i3 = OOC_ARRAY_LENGTH((_check_pointer(i1, 56679)), 0);
      i4 = 0<i3;
      if (!i4) goto l8;
      i4=0;
l3_loop:
      i5 = _check_pointer(i2, 56702);
      i6 = _check_pointer(i1, 56721);
      i7 = OOC_ARRAY_LENGTH(i6, 0);
      i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i4, i7, OOC_UINT32, 56721))*4);
      i6 = ADT_Dictionary_IntValue__DictionaryDesc_Get((ADT_Dictionary_IntValue__Dictionary)i0, (Object__Object)i6);
      i7 = OOC_ARRAY_LENGTH(i5, 0);
      i8 = _check_pointer(i1, 56739);
      i9 = OOC_ARRAY_LENGTH(i8, 0);
      i8 = (OOC_INT32)*(OOC_INT32*)(i8+(_check_index(i4, i9, OOC_UINT32, 56739))*4);
      *(OOC_INT32*)(i5+(_check_index(i6, i7, OOC_UINT32, 56702))*4) = i8;
      i4 = i4+1;
      i = i4;
      i5 = i4<i3;
      if (i5) goto l3_loop;
l8:
      i0 = OOC_ARRAY_LENGTH((_check_pointer(i2, 56793)), 0);
      i = 0;
      i1 = 0<i0;
      if (!i1) goto l27;
      i1=0;
l11_loop:
      i3 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 56810)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i3);
      i3 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 56829)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i3, "_c", 3);
      i3 = (OOC_INT32)w;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 56870))+8);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 56870))+8);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 56881)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i3, i1, 0);
      i3 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 56908)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i3, " = ", 4);
      i3 = _check_pointer(i2, 56953);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i1, i4, OOC_UINT32, 56953))*4);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 56961)))), &_td_OOC_SSA__InstrDesc, 56961)), 56967))+24);
      opnd = (OOC_SSA__Opnd)i3;
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 57000));
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 57009)))), &_td_OOC_SSA__ConstDesc, 57009)), 57015))+44);
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 57028)))), &_td_Object_Boxed__StringDesc, 57028)), 57035));
      i4 = (OOC_INT32)Object__String8Desc_CharsLatin1((Object__String8)(_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 57049)))), &_td_Object__String8Desc, 57049)));
      chars = (Object__CharsLatin1)i4;
      i5 = (OOC_INT32)w;
      i6 = OOC_ARRAY_LENGTH((_check_pointer(i4, 57100)), 0);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 57082)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i5, (void*)(_check_pointer(i4, 57100)), i6);
      i4 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 57113)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i4, "(", 2);
      count = 0;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 57172))+8);
      opnd = (OOC_SSA__Opnd)i3;
      i4 = i3!=0;
      if (!i4) goto l22;
      i4=i3;i3=0;
l14_loop:
      i5 = i3!=0;
      if (!i5) goto l17;
      i5 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 57257)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i5, ", ", 3);
l17:
      i5 = (OOC_INT32)w;
      OOC_SSA_WriteC__WriterDesc_Ref((OOC_SSA_WriteC__Writer)i5, (OOC_SSA__Opnd)i4);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 57337))+8);
      opnd = (OOC_SSA__Opnd)i4;
      i3 = i3+1;
      count = i3;
      i5 = i4!=0;
      if (i5) goto l14_loop;
l22:
      i3 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 57394)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i3, ");", 3);
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
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 57605))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 57611))+20);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 57617))+12);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 57605))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 57611))+20);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 57617))+12);
  i4 = (OOC_INT32)t;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 57574))+20);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 57622)), 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 57574))+20);
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 57587)))), StringSearch__MatcherDesc_MatchChars)),StringSearch__MatcherDesc_MatchChars)((StringSearch__Matcher)i4, (void*)(_check_pointer(i3, 57622)), i2, 0, (-1));
  writeProc = (i2!=(OOC_INT32)0);
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 57655));
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 57669))+24);
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 57679));
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 57684))+8);
  enter = (OOC_SSA__Instr)i2;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 57729));
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 57774))+8);
  i0 = (OOC_INT32)OOC_SSA_IRtoSSA__StatmSeq((OOC_SSA__ProcBlock)i1, (OOC_SSA__Result)i2, (OOC_IR__StatementSeq)i0);
  s = (OOC_SSA__Result)i0;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 57793));
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
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 59410))+24);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 59410))+24);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 59424)))), StringSearch__MatcherDesc_MatchChars)),StringSearch__MatcherDesc_MatchChars)((StringSearch__Matcher)i1, "schedule", 9, 0, (-1));
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
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 59673));
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 59673));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 59676)))), OOC_C_DeclWriter__WriterDesc_Indent)),OOC_C_DeclWriter__WriterDesc_Indent)((OOC_C_DeclWriter__Writer)i2, 1);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 59750));
  i2 = (OOC_INT32)domRoot;
  i3 = (OOC_INT32)pb;
  i1 = (OOC_INT32)OOC_SSA_Allocator__AssignRegisters((OOC_SSA__ProcBlock)i3, (OOC_SSA_Schedule__Block)i2, (OOC_C_DeclWriter__Writer)i1);
  registerMap = (ADT_Dictionary__Dictionary)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 59780));
  i4 = (OOC_INT32)jmpbufMap;
  i1 = (OOC_INT32)OOC_SSA_WriteC__NewWriter((OOC_SSA_WriteC__Translator)i0, (OOC_C_DeclWriter__Writer)i2, (OOC_SSA__ProcBlock)i3, (ADT_Dictionary__Dictionary)i1, (ADT_Dictionary__Dictionary)i4);
  i2 = (OOC_INT32)jmpbufMap;
  w = (OOC_SSA_WriteC__Writer)i1;
  OOC_SSA_WriteC__WriteLocalDecl((OOC_SSA_WriteC__Translator)i0, (OOC_SSA_WriteC__Writer)i1, (OOC_SSA__ProcBlock)i3, (i2!=(OOC_INT32)0));
  i0 = (OOC_INT32)jmpbufMap;
  OOC_SSA_WriteC__TranslatorDesc_WriteProcBody_WriteJmpBufDecl((ADT_Dictionary__Dictionary)i0);
  i0 = (OOC_INT32)proc;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 59905))+4);
  i0 = OOC_SymbolTable__ProcDeclDesc_IsModuleBody((OOC_SymbolTable__ProcDecl)i0);
  if (!i0) goto l27;
  i0 = (OOC_INT32)pb;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 60096))+12);
  instr = (OOC_SSA__Instr)i0;
  i1 = (OOC_INT32)t;
  i2 = i0!=(OOC_INT32)0;
  if (!i2) goto l26;
l18_loop:
  i2 = *(OOC_INT8*)((_check_pointer(i0, 60154))+36);
  i2 = i2==81;
  if (!i2) goto l21;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 60223))+36);
  i2 = OOC_SSA_WriteC__GetPreloadId((ADT_Dictionary_IntValue__Dictionary)i2, (OOC_SSA__Instr)i0);
  dummy = i2;
l21:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 60282))+28);
  instr = (OOC_SSA__Instr)i0;
  i2 = i0!=(OOC_INT32)0;
  if (i2) goto l18_loop;
l26:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 60337))+36);
  OOC_SSA_WriteC__TranslatorDesc_WriteProcBody_InitPreloadedVars((ADT_Dictionary_IntValue__Dictionary)i0);
l27:
  i0 = (OOC_INT32)t;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 60368)))), OOC_Make_TranslateToC__TranslatorDesc_WriteNestedProcedures)),OOC_Make_TranslateToC__TranslatorDesc_WriteNestedProcedures)((OOC_Make_TranslateToC__Translator)i0);
  i0 = (OOC_INT32)domRoot;
  OOC_SSA_WriteC__TranslatorDesc_WriteProcBody_JumpChaining((OOC_SSA_Schedule__Block)i0);
  i0 = (OOC_INT32)domRoot;
  OOC_SSA_WriteC__TranslatorDesc_WriteProcBody_FixCrossJumps((OOC_SSA_Schedule__Block)i0);
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 60485)))), OOC_C_DeclWriter__WriterDesc_WriteLn)),OOC_C_DeclWriter__WriterDesc_WriteLn)((OOC_C_DeclWriter__Writer)i0);
  i1 = (OOC_INT32)domRoot;
  OOC_SSA_WriteC__WriterDesc_WriteBlocks((OOC_SSA_WriteC__Writer)i0, (OOC_SSA_Schedule__Block)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 60531)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 60663)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ";", 2);
  i0 = (OOC_INT32)t;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 60689));
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 60689));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 60692)))), OOC_C_DeclWriter__WriterDesc_Indent)),OOC_C_DeclWriter__WriterDesc_Indent)((OOC_C_DeclWriter__Writer)i0, (-1));
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
  *(OOC_INT32*)((_check_pointer(i0, 61000))+20) = i1;
  i1 = (OOC_INT32)inspectStage;
  *(OOC_INT32*)((_check_pointer(i0, 61035))+24) = i1;
  i1 = writeStats;
  *(OOC_UINT8*)((_check_pointer(i0, 61072))+28) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 61105))+32) = (OOC_INT32)0;
  i1 = (OOC_INT32)ADT_Dictionary_IntValue__New();
  *(OOC_INT32*)((_check_pointer(i0, 61135))+36) = i1;
  return;
  ;
}

OOC_SSA_WriteC__Translator OOC_SSA_WriteC__NewTranslator(OOC_CHAR8 writeStats, StringSearch__Matcher inspectProc, StringSearch__Matcher inspectStage) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_SSA_WriteC__Translator.baseTypes[0]);
  i1 = (OOC_INT32)inspectStage;
  i2 = (OOC_INT32)inspectProc;
  i3 = writeStats;
  OOC_SSA_WriteC__InitTranslator((OOC_SSA_WriteC__Translator)i0, i3, (StringSearch__Matcher)i2, (StringSearch__Matcher)i1);
  return (OOC_SSA_WriteC__Translator)i0;
  ;
}

void OOC_SSA_WriteC__TranslatorDesc_SetProcedureList(OOC_SSA_WriteC__Translator t, OOC_IR__ProcedureList procList) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_SSA_WriteC__Visitor v;
  OOC_INT32 i;

  i0 = (OOC_INT32)procList;
  i1 = (OOC_INT32)t;
  OOC_Make_TranslateToC__TranslatorDesc_SetProcedureList((OOC_Make_TranslateToC__Translator)i1, (OOC_IR__ProcedureList)i0);
  i2 = i0!=(OOC_INT32)0;
  if (!i2) goto l11;
  i2 = (OOC_INT32)OOC_SSA_WriteC__NewVisitor();
  v = (OOC_SSA_WriteC__Visitor)i2;
  i = 0;
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i0, 61716)), 0);
  i4 = 0<i3;
  if (!i4) goto l10;
  i4=0;
l5_loop:
  i5 = _check_pointer(i0, 61740);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 61740))*4);
  OOC_IR__ProcedureDesc_Accept((OOC_IR__Procedure)i5, (OOC_IR__Visitor)i2);
  i4 = i4+1;
  i = i4;
  i5 = i4<i3;
  if (i5) goto l5_loop;
l10:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 61796))+4);
  *(OOC_INT32*)((_check_pointer(i1, 61775))+32) = i0;
l11:
  return;
  ;
}

void OOC_OOC_SSA_WriteC_init(void) {

  return;
  ;
}

void OOC_OOC_SSA_WriteC_destroy(void) {
}

/* --- */
