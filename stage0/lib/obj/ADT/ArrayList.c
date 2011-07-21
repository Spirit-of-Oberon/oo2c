#include <ADT/ArrayList.d>
#include <__oo2c.h>
#include <setjmp.h>

void ADT_ArrayList__ArrayListDesc_CreateArray(ADT_ArrayList__ArrayList l, OOC_INT32 size, ADT_ArrayList__ArrayList old) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
  ADT_ArrayList__Array _new;
  OOC_INT32 i;

  i0 = size;
  i1 = i0<2;
  if (!i1) goto l4;
  size = 2;
  i0=2;
l4:
  i0 = (OOC_INT32)RT0__NewObject(_td_ADT_ArrayList__Array.baseTypes[0], i0);
  _new = (ADT_ArrayList__Array)i0;
  i1 = (OOC_INT32)old;
  i2 = i1!=(OOC_INT32)0;
  if (!i2) goto l15;
  i = 0;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 1860))+4);
  i3 = 0<i2;
  if (!i3) goto l15;
  i3=0;
l9_loop:
  i4 = _check_pointer(i0, 1883);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 1893));
  i6 = _check_pointer(i6, 1900);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i3, i7, OOC_UINT32, 1900))*4);
  *(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 1883))*4) = i6;
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 1916));
  i4 = _check_pointer(i4, 1923);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  *(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 1923))*4) = (OOC_INT32)0;
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l9_loop;
l15:
  i1 = (OOC_INT32)l;
  *(OOC_INT32*)(_check_pointer(i1, 1990)) = i0;
  return;
  ;
}

void ADT_ArrayList__ArrayListDesc_INIT(ADT_ArrayList__ArrayList l, OOC_INT32 initialSize) {
  register OOC_INT32 i0,i1;

  i0 = initialSize;
  i1 = (OOC_INT32)l;
  ADT_ArrayList__ArrayListDesc_CreateArray((ADT_ArrayList__ArrayList)i1, i0, (ADT_ArrayList__ArrayList)(OOC_INT32)0);
  *(OOC_INT32*)((_check_pointer(i1, 2191))+4) = 0;
  return;
  ;
}

ADT_ArrayList__ArrayList ADT_ArrayList__New(OOC_INT32 initialSize) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)RT0__NewObject(_td__qtd1.baseTypes[0]);
  i1 = initialSize;
  ADT_ArrayList__ArrayListDesc_INIT((ADT_ArrayList__ArrayList)i0, i1);
  return (ADT_ArrayList__ArrayList)i0;
  ;
}

void ADT_ArrayList__ArrayListDesc_Destroy(ADT_ArrayList__ArrayList l) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_INT32 i;

  i0 = (OOC_INT32)l;
  i = 0;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 2534))+4);
  i2 = 0<i1;
  if (!i2) goto l8;
  i2=0;
l3_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 2553));
  i3 = _check_pointer(i3, 2560);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 2560))*4) = 0;
  i2 = i2+1;
  i = i2;
  i3 = i2<i1;
  if (i3) goto l3_loop;
l8:
  *(OOC_INT32*)(_check_pointer(i0, 2585)) = 0;
  return;
  ;
}

ADT_ArrayList__ArrayList ADT_ArrayList__ArrayListDesc_Copy(ADT_ArrayList__ArrayList l) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
  ADT_ArrayList__ArrayList _new;
  OOC_INT32 i;

  i0 = (OOC_INT32)RT0__NewObject(_td__qtd3.baseTypes[0]);
  i1 = (OOC_INT32)l;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 2839))+4);
  ADT_ArrayList__ArrayListDesc_INIT((ADT_ArrayList__ArrayList)i0, i2);
  _new = (ADT_ArrayList__ArrayList)i0;
  i = 0;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 2867))+4);
  i3 = 0<i2;
  if (!i3) goto l8;
  i3=0;
l3_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 2888));
  i4 = _check_pointer(i4, 2895);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 2903));
  i6 = _check_pointer(i6, 2910);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i3, i7, OOC_UINT32, 2910))*4);
  *(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 2895))*4) = i6;
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l3_loop;
l8:
  i1 = *(OOC_INT32*)((_check_pointer(i1, 2941))+4);
  *(OOC_INT32*)((_check_pointer(i0, 2930))+4) = i1;
  return (ADT_ArrayList__ArrayList)i0;
  ;
}

void ADT_ArrayList__ArrayListDesc_EnsureCapacity(ADT_ArrayList__ArrayList l, OOC_INT32 size) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)l;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 3305));
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 3312)), 0);
  i2 = size;
  i1 = i1<i2;
  if (!i1) goto l4;
  ADT_ArrayList__ArrayListDesc_CreateArray((ADT_ArrayList__ArrayList)i0, i2, (ADT_ArrayList__ArrayList)i0);
l4:
  return;
  ;
}

void ADT_ArrayList__ArrayListDesc_Clear(ADT_ArrayList__ArrayList l) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_INT32 i;

  i0 = (OOC_INT32)l;
  i = 0;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 3578))+4);
  i2 = 0<i1;
  if (!i2) goto l8;
  i2=0;
l3_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 3597));
  i3 = _check_pointer(i3, 3604);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 3604))*4) = 0;
  i2 = i2+1;
  i = i2;
  i3 = i2<i1;
  if (i3) goto l3_loop;
l8:
  *(OOC_INT32*)((_check_pointer(i0, 3629))+4) = 0;
  return;
  ;
}

void ADT_ArrayList__ArrayListDesc_Append(ADT_ArrayList__ArrayList l, Object__Object obj) {
  register OOC_INT32 i0,i1,i2,i3,i4;

  i0 = (OOC_INT32)l;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 3808));
  i2 = *(OOC_INT32*)((_check_pointer(i0, 3793))+4);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 3815)), 0);
  i1 = i2==i1;
  if (!i1) goto l4;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 3847))+4);
  ADT_ArrayList__ArrayListDesc_CreateArray((ADT_ArrayList__ArrayList)i0, (i1*2), (ADT_ArrayList__ArrayList)i0);
l4:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 3874));
  i1 = _check_pointer(i1, 3881);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 3883))+4);
  i3 = OOC_ARRAY_LENGTH(i1, 0);
  i4 = (OOC_INT32)obj;
  *(OOC_INT32*)(i1+(_check_index(i2, i3, OOC_UINT32, 3881))*4) = i4;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 3909))+4);
  *(OOC_INT32*)((_check_pointer(i0, 3909))+4) = (i1+1);
  return;
  ;
}

void ADT_ArrayList__ArrayListDesc_Insert(ADT_ArrayList__ArrayList l, OOC_INT32 index, Object__Object obj) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_INT32 i;

  i0 = (OOC_INT32)l;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 4391))+4);
  i2 = index;
  _assert((i2<=i1), 127, 4373);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4424));
  i3 = *(OOC_INT32*)((_check_pointer(i0, 4409))+4);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 4431)), 0);
  i1 = i3==i1;
  if (!i1) goto l3;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 4463))+4);
  ADT_ArrayList__ArrayListDesc_CreateArray((ADT_ArrayList__ArrayList)i0, (i1*2), (ADT_ArrayList__ArrayList)i0);
l3:
  i1 = *(OOC_INT32*)((_check_pointer(i0, 4499))+4);
  i1 = i1-1;
  i = i1;
  i3 = i1>=i2;
  if (!i3) goto l11;
l6_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4533));
  i3 = _check_pointer(i3, 4540);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4550));
  i5 = _check_pointer(i5, 4557);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i1, i6, OOC_UINT32, 4557))*4);
  *(OOC_INT32*)(i3+(_check_index((i1+1), i4, OOC_UINT32, 4540))*4) = i5;
  i1 = i1+(-1);
  i = i1;
  i3 = i1>=i2;
  if (i3) goto l6_loop;
l11:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4575));
  i1 = _check_pointer(i1, 4582);
  i3 = OOC_ARRAY_LENGTH(i1, 0);
  i4 = (OOC_INT32)obj;
  *(OOC_INT32*)(i1+(_check_index(i2, i3, OOC_UINT32, 4582))*4) = i4;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 4608))+4);
  *(OOC_INT32*)((_check_pointer(i0, 4608))+4) = (i1+1);
  return;
  ;
}

Object__Object ADT_ArrayList__ArrayListDesc_Get(ADT_ArrayList__ArrayList l, OOC_INT32 index) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)l;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 4900))+4);
  i2 = index;
  _assert((i2<i1), 127, 4883);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4921));
  i0 = _check_pointer(i0, 4928);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(i2, i1, OOC_UINT32, 4928))*4);
  return (Object__Object)i0;
  ;
}

void ADT_ArrayList__ArrayListDesc_Set(ADT_ArrayList__ArrayList l, OOC_INT32 index, Object__Object obj) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)l;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 5266))+4);
  i2 = index;
  _assert((i2<i1), 127, 5249);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5280));
  i0 = _check_pointer(i0, 5287);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  i3 = (OOC_INT32)obj;
  *(OOC_INT32*)(i0+(_check_index(i2, i1, OOC_UINT32, 5287))*4) = i3;
  return;
  ;
}

void ADT_ArrayList__ArrayListDesc_RemoveRange(ADT_ArrayList__ArrayList l, OOC_INT32 fromIndex, OOC_INT32 toIndex) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
  OOC_INT32 delta;
  OOC_INT32 i;

  i0 = toIndex;
  i1 = fromIndex;
  i1 = i0-i1;
  delta = i1;
  i2 = (OOC_INT32)l;
  i = i0;
  i3 = *(OOC_INT32*)((_check_pointer(i2, 6147))+4);
  i4 = i0<i3;
  if (!i4) goto l8;
  i4 = (i1*(-1))+i0;
  
l3_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 6166));
  i5 = _check_pointer(i5, 6173);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 6187));
  i7 = _check_pointer(i7, 6194);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)(i7+(_check_index(i0, i8, OOC_UINT32, 6194))*4);
  *(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 6173))*4) = i7;
  i0 = i0+1;
  i = i0;
  i4 = i4+1;
  i5 = i0<i3;
  if (i5) goto l3_loop;
l8:
  i0 = *(OOC_INT32*)((_check_pointer(i2, 6217))+4);
  *(OOC_INT32*)((_check_pointer(i2, 6217))+4) = (i0-i1);
  return;
  ;
}

void ADT_ArrayList__ArrayListDesc_Remove(ADT_ArrayList__ArrayList l, OOC_INT32 index) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)l;
  i1 = index;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6590)))), ADT_ArrayList__ArrayListDesc_RemoveRange)),ADT_ArrayList__ArrayListDesc_RemoveRange)((ADT_ArrayList__ArrayList)i0, i1, (i1+1));
  return;
  ;
}

void ADT_ArrayList__ArrayListDesc_TrimToSize(ADT_ArrayList__ArrayList l) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)l;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6883));
  i2 = *(OOC_INT32*)((_check_pointer(i0, 6868))+4);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 6890)), 0);
  i1 = i2!=i1;
  if (!i1) goto l4;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 6922))+4);
  ADT_ArrayList__ArrayListDesc_CreateArray((ADT_ArrayList__ArrayList)i0, i1, (ADT_ArrayList__ArrayList)i0);
l4:
  return;
  ;
}

OOC_INT32 ADT_ArrayList__ArrayListDesc_Size(ADT_ArrayList__ArrayList l) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)l;
  i0 = *(OOC_INT32*)((_check_pointer(i0, 7080))+4);
  return i0;
  ;
}

OOC_CHAR8 ADT_ArrayList__ArrayListDesc_Contains(ADT_ArrayList__ArrayList l, Object__Object obj) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT32 i;

  i0 = (OOC_INT32)l;
  i = 0;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 7278))+4);
  i2 = 0<i1;
  if (!i2) goto l11;
  i2 = (OOC_INT32)obj;
  i3=0;
l3_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7313));
  i4 = _check_pointer(i4, 7320);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 7320))*4);
  i4 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 7302)))), Object__ObjectDesc_Equals)),Object__ObjectDesc_Equals)((Object__Object)i2, (Object__Object)i4);
  if (!i4) goto l6;
  return 1u;
l6:
  i3 = i3+1;
  i = i3;
  i4 = i3<i1;
  if (i4) goto l3_loop;
l11:
  return 0u;
  ;
}

OOC_INT32 ADT_ArrayList__ArrayListDesc_IndexOf(ADT_ArrayList__ArrayList l, Object__Object obj) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT32 i;

  i0 = (OOC_INT32)l;
  i = 0;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 7692))+4);
  i2 = 0<i1;
  if (!i2) goto l11;
  i2 = (OOC_INT32)obj;
  i3=0;
l3_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7727));
  i4 = _check_pointer(i4, 7734);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 7734))*4);
  i4 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 7716)))), Object__ObjectDesc_Equals)),Object__ObjectDesc_Equals)((Object__Object)i2, (Object__Object)i4);
  if (!i4) goto l6;
  return i3;
l6:
  i3 = i3+1;
  i = i3;
  i4 = i3<i1;
  if (i4) goto l3_loop;
l11:
  return (-1);
  ;
}

OOC_INT32 ADT_ArrayList__ArrayListDesc_LastIndexOf(ADT_ArrayList__ArrayList l, Object__Object obj) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_INT32 i;

  i0 = (OOC_INT32)l;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 8097))+4);
  i1 = i1-1;
  i = i1;
  i2 = i1>=0;
  if (!i2) goto l11;
  i2 = (OOC_INT32)obj;
  
l3_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 8143));
  i3 = _check_pointer(i3, 8150);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i1, i4, OOC_UINT32, 8150))*4);
  i3 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 8132)))), Object__ObjectDesc_Equals)),Object__ObjectDesc_Equals)((Object__Object)i2, (Object__Object)i3);
  if (!i3) goto l6;
  return i1;
l6:
  i1 = i1+(-1);
  i = i1;
  i3 = i1>=0;
  if (i3) goto l3_loop;
l11:
  return (-1);
  ;
}

OOC_CHAR8 ADT_ArrayList__ArrayListDesc_IsEmpty(ADT_ArrayList__ArrayList l) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)l;
  i0 = *(OOC_INT32*)((_check_pointer(i0, 8344))+4);
  return (i0==0);
  ;
}

OOC_CHAR8 ADT_ArrayList__ArrayListDesc_Equals(ADT_ArrayList__ArrayList l, Object__Object obj) {

  _assert(0u, 127, 8482);
  _failed_function(8402); return 0;
  ;
}

OOC_INT32 ADT_ArrayList__ArrayListDesc_HashCode(ADT_ArrayList__ArrayList l) {

  _assert(0u, 127, 8617);
  _failed_function(8549); return 0;
  ;
}

void ADT_ArrayList__ArrayListDesc_Store(ADT_ArrayList__ArrayList l, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT32 i;

  i0 = (OOC_INT32)l;
  i1 = (OOC_INT32)w;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 8779))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8766)))), IO_BinaryRider__WriterDesc_WriteNum)),IO_BinaryRider__WriterDesc_WriteNum)((IO_BinaryRider__Writer)i1, i2);
  i = 0;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 8807))+4);
  i3 = 0<i2;
  if (!i3) goto l8;
  i3=0;
l3_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 8842));
  i4 = _check_pointer(i4, 8849);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 8849))*4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8826)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i1, (Object__Object)i4);
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l3_loop;
l8:
  return;
  ;
}

void ADT_ArrayList__ArrayListDesc_Load(ADT_ArrayList__ArrayList l, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_INT32 size;
  OOC_INT32 i;
  Object__Object obj;

  i0 = (OOC_INT32)r;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9014)))), IO_BinaryRider__ReaderDesc_ReadNum)),IO_BinaryRider__ReaderDesc_ReadNum)((IO_BinaryRider__Reader)i0, (void*)(OOC_INT32)&size);
  i1 = (OOC_INT32)l;
  i2 = size;
  ADT_ArrayList__ArrayListDesc_INIT((ADT_ArrayList__ArrayList)i1, i2);
  i = 0;
  i2 = size;
  i3 = 0<i2;
  if (!i3) goto l8;
  i3=0;
l3_loop:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9085)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i0, (void*)(OOC_INT32)&obj);
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 9112));
  i4 = _check_pointer(i4, 9119);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)obj;
  *(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 9119))*4) = ((OOC_INT32)_type_cast_fast(OOC_INT32, OOC_INT32, i6));
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l3_loop;
l8:
  i0 = size;
  *(OOC_INT32*)((_check_pointer(i1, 9160))+4) = i0;
  return;
  ;
}

void ADT_ArrayList__ArrayListDesc_Sort(ADT_ArrayList__ArrayList a, OOC_INT32 fromIndex, OOC_INT32 toIndex, ADT_Comparator__Comparator cmp) {
  register OOC_INT32 i0,i1;
  auto void ADT_ArrayList__ArrayListDesc_Sort_Quicksort(OOC_INT32 l, OOC_INT32 r);
    
    void ADT_ArrayList__ArrayListDesc_Sort_Quicksort(OOC_INT32 l, OOC_INT32 r) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10;
      OOC_INT32 m;
      Object__Object t;
      Object__Object v;
      OOC_INT32 i;
      OOC_INT32 j;

      i0 = r;
      i1 = l;
      i2 = i0>i1;
      if (!i2) goto l31;
      i2 = (i0+i1)>>1;
      m = i2;
      i3 = (OOC_INT32)a;
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 9642));
      i4 = _check_pointer(i4, 9648);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 9630));
      i3 = _check_pointer(i3, 9636);
      i6 = OOC_ARRAY_LENGTH(i3, 0);
      i7 = (OOC_INT32)cmp;
      i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i1, i6, OOC_UINT32, 9636))*4);
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i0, i5, OOC_UINT32, 9648))*4);
      i3 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 9620)))), ADT_Comparator__ComparatorDesc_Compare)),ADT_Comparator__ComparatorDesc_Compare)((ADT_Comparator__Comparator)i7, (Object__Object)i3, (Object__Object)i4);
      i3 = i3>0;
      if (!i3) goto l5;
      i3 = (OOC_INT32)a;
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 9679));
      i4 = _check_pointer(i4, 9685);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i1, i5, OOC_UINT32, 9685))*4);
      t = (Object__Object)i4;
      i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 9691));
      i5 = _check_pointer(i5, 9697);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i7 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 9705));
      i7 = _check_pointer(i7, 9711);
      i8 = OOC_ARRAY_LENGTH(i7, 0);
      i7 = (OOC_INT32)*(OOC_INT32*)(i7+(_check_index(i0, i8, OOC_UINT32, 9711))*4);
      *(OOC_INT32*)(i5+(_check_index(i1, i6, OOC_UINT32, 9697))*4) = i7;
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 9717));
      i3 = _check_pointer(i3, 9723);
      i5 = OOC_ARRAY_LENGTH(i3, 0);
      *(OOC_INT32*)(i3+(_check_index(i0, i5, OOC_UINT32, 9723))*4) = i4;
l5:
      i3 = (OOC_INT32)a;
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 9782));
      i4 = _check_pointer(i4, 9788);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 9770));
      i3 = _check_pointer(i3, 9776);
      i6 = OOC_ARRAY_LENGTH(i3, 0);
      i7 = (OOC_INT32)cmp;
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i2, i5, OOC_UINT32, 9788))*4);
      i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i1, i6, OOC_UINT32, 9776))*4);
      i3 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 9760)))), ADT_Comparator__ComparatorDesc_Compare)),ADT_Comparator__ComparatorDesc_Compare)((ADT_Comparator__Comparator)i7, (Object__Object)i3, (Object__Object)i4);
      i3 = i3>0;
      if (!i3) goto l8;
      i3 = (OOC_INT32)a;
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 9819));
      i4 = _check_pointer(i4, 9825);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i1, i5, OOC_UINT32, 9825))*4);
      t = (Object__Object)i4;
      i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 9831));
      i5 = _check_pointer(i5, 9837);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i7 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 9845));
      i7 = _check_pointer(i7, 9851);
      i8 = OOC_ARRAY_LENGTH(i7, 0);
      i7 = (OOC_INT32)*(OOC_INT32*)(i7+(_check_index(i2, i8, OOC_UINT32, 9851))*4);
      *(OOC_INT32*)(i5+(_check_index(i1, i6, OOC_UINT32, 9837))*4) = i7;
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 9857));
      i3 = _check_pointer(i3, 9863);
      i5 = OOC_ARRAY_LENGTH(i3, 0);
      *(OOC_INT32*)(i3+(_check_index(i2, i5, OOC_UINT32, 9863))*4) = i4;
l8:
      i3 = (OOC_INT32)a;
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 9922));
      i4 = _check_pointer(i4, 9928);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 9910));
      i3 = _check_pointer(i3, 9916);
      i6 = OOC_ARRAY_LENGTH(i3, 0);
      i7 = (OOC_INT32)cmp;
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i2, i5, OOC_UINT32, 9928))*4);
      i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i0, i6, OOC_UINT32, 9916))*4);
      i3 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 9900)))), ADT_Comparator__ComparatorDesc_Compare)),ADT_Comparator__ComparatorDesc_Compare)((ADT_Comparator__Comparator)i7, (Object__Object)i3, (Object__Object)i4);
      i3 = i3>0;
      if (!i3) goto l11;
      i3 = (OOC_INT32)a;
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 9959));
      i4 = _check_pointer(i4, 9965);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i0, i5, OOC_UINT32, 9965))*4);
      t = (Object__Object)i4;
      i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 9971));
      i5 = _check_pointer(i5, 9977);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i7 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 9985));
      i7 = _check_pointer(i7, 9991);
      i8 = OOC_ARRAY_LENGTH(i7, 0);
      i7 = (OOC_INT32)*(OOC_INT32*)(i7+(_check_index(i2, i8, OOC_UINT32, 9991))*4);
      *(OOC_INT32*)(i5+(_check_index(i0, i6, OOC_UINT32, 9977))*4) = i7;
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 9997));
      i3 = _check_pointer(i3, 10003);
      i5 = OOC_ARRAY_LENGTH(i3, 0);
      *(OOC_INT32*)(i3+(_check_index(i2, i5, OOC_UINT32, 10003))*4) = i4;
l11:
      i2 = (OOC_INT32)a;
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 10048));
      i2 = _check_pointer(i2, 10054);
      i3 = OOC_ARRAY_LENGTH(i2, 0);
      i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i0, i3, OOC_UINT32, 10054))*4);
      v = (Object__Object)i2;
      j = i0;
      i3 = i1-1;
      i4=i0;
l12_loop:
      
l13_loop:
      i3 = i3+1;
      i = i3;
      i5 = (OOC_INT32)a;
      i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 10158));
      i5 = _check_pointer(i5, 10164);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i7 = (OOC_INT32)cmp;
      i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i3, i6, OOC_UINT32, 10164))*4);
      i5 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 10148)))), ADT_Comparator__ComparatorDesc_Compare)),ADT_Comparator__ComparatorDesc_Compare)((ADT_Comparator__Comparator)i7, (Object__Object)i5, (Object__Object)i2);
      i5 = i5>=0;
      if (!i5) goto l13_loop;
l18_loop:
      i4 = i4-1;
      j = i4;
      i5 = i4<0;
      if (i5) goto l21;
      i5 = (OOC_INT32)a;
      i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 10258));
      i5 = _check_pointer(i5, 10264);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i7 = (OOC_INT32)cmp;
      i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 10264))*4);
      i5 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 10248)))), ADT_Comparator__ComparatorDesc_Compare)),ADT_Comparator__ComparatorDesc_Compare)((ADT_Comparator__Comparator)i7, (Object__Object)i5, (Object__Object)i2);
      i5 = i5<=0;
      
      goto l23;
l21:
      i5=1u;
l23:
      if (!i5) goto l18_loop;
l26:
      i5 = (OOC_INT32)a;
      i6 = i3>=i4;
      if (i6) goto l30;
      i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 10355));
      i6 = _check_pointer(i6, 10361);
      i7 = OOC_ARRAY_LENGTH(i6, 0);
      i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i3, i7, OOC_UINT32, 10361))*4);
      t = (Object__Object)i6;
      i7 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 10367));
      i7 = _check_pointer(i7, 10373);
      i8 = OOC_ARRAY_LENGTH(i7, 0);
      i9 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 10381));
      i9 = _check_pointer(i9, 10387);
      i10 = OOC_ARRAY_LENGTH(i9, 0);
      i9 = (OOC_INT32)*(OOC_INT32*)(i9+(_check_index(i4, i10, OOC_UINT32, 10387))*4);
      *(OOC_INT32*)(i7+(_check_index(i3, i8, OOC_UINT32, 10373))*4) = i9;
      i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 10393));
      i5 = _check_pointer(i5, 10399);
      i7 = OOC_ARRAY_LENGTH(i5, 0);
      *(OOC_INT32*)(i5+(_check_index(i4, i7, OOC_UINT32, 10399))*4) = i6;
      
      goto l12_loop;
l30:
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 10435));
      i2 = _check_pointer(i2, 10441);
      i4 = OOC_ARRAY_LENGTH(i2, 0);
      i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i3, i4, OOC_UINT32, 10441))*4);
      t = (Object__Object)i2;
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 10447));
      i4 = _check_pointer(i4, 10453);
      i6 = OOC_ARRAY_LENGTH(i4, 0);
      i7 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 10461));
      i7 = _check_pointer(i7, 10467);
      i8 = OOC_ARRAY_LENGTH(i7, 0);
      i7 = (OOC_INT32)*(OOC_INT32*)(i7+(_check_index(i0, i8, OOC_UINT32, 10467))*4);
      *(OOC_INT32*)(i4+(_check_index(i3, i6, OOC_UINT32, 10453))*4) = i7;
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 10473));
      i4 = _check_pointer(i4, 10479);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      *(OOC_INT32*)(i4+(_check_index(i0, i5, OOC_UINT32, 10479))*4) = i2;
      ADT_ArrayList__ArrayListDesc_Sort_Quicksort(i1, (i3-1));
      ADT_ArrayList__ArrayListDesc_Sort_Quicksort((i3+1), i0);
l31:
      return;
      ;
    }


  i0 = toIndex;
  i1 = fromIndex;
  ADT_ArrayList__ArrayListDesc_Sort_Quicksort(i1, (i0-1));
  return;
  ;
}

Object__ObjectArrayPtr ADT_ArrayList__ArrayListDesc_Elements(ADT_ArrayList__ArrayList l) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
  Object__ObjectArrayPtr a;
  OOC_INT32 i;

  i0 = (OOC_INT32)l;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 10773))+4);
  i1 = (OOC_INT32)RT0__NewObject(_td_Object__ObjectArrayPtr.baseTypes[0], i1);
  a = (Object__ObjectArrayPtr)i1;
  i = 0;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 10800))+4);
  i3 = 0<i2;
  if (!i3) goto l8;
  i3=0;
l3_loop:
  i4 = _check_pointer(i1, 10818);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 10826));
  i6 = _check_pointer(i6, 10832);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i3, i7, OOC_UINT32, 10832))*4);
  *(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 10818))*4) = i6;
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l3_loop;
l8:
  return (Object__ObjectArrayPtr)i1;
  ;
}

void OOC_ADT_ArrayList_init(void) {

  return;
  ;
}

/* --- */
