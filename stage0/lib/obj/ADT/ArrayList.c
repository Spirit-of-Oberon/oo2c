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
  i2 = *(OOC_INT32*)((_check_pointer(i1, 2037))+4);
  i3 = 0<i2;
  if (!i3) goto l15;
  i3=0;
l9_loop:
  i4 = _check_pointer(i0, 2060);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 2070));
  i6 = _check_pointer(i6, 2077);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i3, i7, OOC_UINT32, 2077))*4);
  *(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 2060))*4) = i6;
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 2093));
  i4 = _check_pointer(i4, 2100);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  *(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 2100))*4) = (OOC_INT32)0;
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l9_loop;
l15:
  i1 = (OOC_INT32)l;
  *(OOC_INT32*)(_check_pointer(i1, 2167)) = i0;
  return;
  ;
}

void ADT_ArrayList__ArrayListDesc_INIT(ADT_ArrayList__ArrayList l, OOC_INT32 initialSize) {
  register OOC_INT32 i0,i1;

  i0 = initialSize;
  i1 = (OOC_INT32)l;
  ADT_ArrayList__ArrayListDesc_CreateArray((ADT_ArrayList__ArrayList)i1, i0, (ADT_ArrayList__ArrayList)(OOC_INT32)0);
  *(OOC_INT32*)((_check_pointer(i1, 2368))+4) = 0;
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
  i1 = *(OOC_INT32*)((_check_pointer(i0, 2711))+4);
  i2 = 0<i1;
  if (!i2) goto l8;
  i2=0;
l3_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 2730));
  i3 = _check_pointer(i3, 2737);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 2737))*4) = 0;
  i2 = i2+1;
  i = i2;
  i3 = i2<i1;
  if (i3) goto l3_loop;
l8:
  *(OOC_INT32*)(_check_pointer(i0, 2762)) = 0;
  return;
  ;
}

ADT_ArrayList__ArrayList ADT_ArrayList__ArrayListDesc_Copy(ADT_ArrayList__ArrayList l) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
  ADT_ArrayList__ArrayList _new;
  OOC_INT32 i;

  i0 = (OOC_INT32)RT0__NewObject(_td__qtd4.baseTypes[0]);
  i1 = (OOC_INT32)l;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 3016))+4);
  ADT_ArrayList__ArrayListDesc_INIT((ADT_ArrayList__ArrayList)i0, i2);
  _new = (ADT_ArrayList__ArrayList)i0;
  i = 0;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 3044))+4);
  i3 = 0<i2;
  if (!i3) goto l8;
  i3=0;
l3_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 3065));
  i4 = _check_pointer(i4, 3072);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 3080));
  i6 = _check_pointer(i6, 3087);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i3, i7, OOC_UINT32, 3087))*4);
  *(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 3072))*4) = i6;
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l3_loop;
l8:
  i1 = *(OOC_INT32*)((_check_pointer(i1, 3118))+4);
  *(OOC_INT32*)((_check_pointer(i0, 3107))+4) = i1;
  return (ADT_ArrayList__ArrayList)i0;
  ;
}

void ADT_ArrayList__ArrayListDesc_EnsureCapacity(ADT_ArrayList__ArrayList l, OOC_INT32 size) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)l;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 3482));
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 3489)), 0);
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
  i1 = *(OOC_INT32*)((_check_pointer(i0, 3755))+4);
  i2 = 0<i1;
  if (!i2) goto l8;
  i2=0;
l3_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 3774));
  i3 = _check_pointer(i3, 3781);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 3781))*4) = 0;
  i2 = i2+1;
  i = i2;
  i3 = i2<i1;
  if (i3) goto l3_loop;
l8:
  *(OOC_INT32*)((_check_pointer(i0, 3806))+4) = 0;
  return;
  ;
}

void ADT_ArrayList__ArrayListDesc_Append(ADT_ArrayList__ArrayList l, Object__Object obj) {
  register OOC_INT32 i0,i1,i2,i3,i4;

  i0 = (OOC_INT32)l;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 3985));
  i2 = *(OOC_INT32*)((_check_pointer(i0, 3970))+4);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 3992)), 0);
  i1 = i2==i1;
  if (!i1) goto l4;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 4024))+4);
  ADT_ArrayList__ArrayListDesc_CreateArray((ADT_ArrayList__ArrayList)i0, (i1*2), (ADT_ArrayList__ArrayList)i0);
l4:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4051));
  i1 = _check_pointer(i1, 4058);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 4060))+4);
  i3 = OOC_ARRAY_LENGTH(i1, 0);
  i4 = (OOC_INT32)obj;
  *(OOC_INT32*)(i1+(_check_index(i2, i3, OOC_UINT32, 4058))*4) = i4;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 4086))+4);
  *(OOC_INT32*)((_check_pointer(i0, 4086))+4) = (i1+1);
  return;
  ;
}

void ADT_ArrayList__ArrayListDesc_Insert(ADT_ArrayList__ArrayList l, OOC_INT32 index, Object__Object obj) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_INT32 i;

  i0 = (OOC_INT32)l;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 4568))+4);
  i2 = index;
  _assert((i2<=i1), 127, 4550);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4601));
  i3 = *(OOC_INT32*)((_check_pointer(i0, 4586))+4);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 4608)), 0);
  i1 = i3==i1;
  if (!i1) goto l3;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 4640))+4);
  ADT_ArrayList__ArrayListDesc_CreateArray((ADT_ArrayList__ArrayList)i0, (i1*2), (ADT_ArrayList__ArrayList)i0);
l3:
  i1 = *(OOC_INT32*)((_check_pointer(i0, 4676))+4);
  i1 = i1-1;
  i = i1;
  i3 = i1>=i2;
  if (!i3) goto l11;
l6_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4710));
  i3 = _check_pointer(i3, 4717);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4727));
  i5 = _check_pointer(i5, 4734);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i1, i6, OOC_UINT32, 4734))*4);
  *(OOC_INT32*)(i3+(_check_index((i1+1), i4, OOC_UINT32, 4717))*4) = i5;
  i1 = i1+(-1);
  i = i1;
  i3 = i1>=i2;
  if (i3) goto l6_loop;
l11:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4752));
  i1 = _check_pointer(i1, 4759);
  i3 = OOC_ARRAY_LENGTH(i1, 0);
  i4 = (OOC_INT32)obj;
  *(OOC_INT32*)(i1+(_check_index(i2, i3, OOC_UINT32, 4759))*4) = i4;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 4785))+4);
  *(OOC_INT32*)((_check_pointer(i0, 4785))+4) = (i1+1);
  return;
  ;
}

Object__Object ADT_ArrayList__ArrayListDesc_Get(ADT_ArrayList__ArrayList l, OOC_INT32 index) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)l;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 5077))+4);
  i2 = index;
  _assert((i2<i1), 127, 5060);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5098));
  i0 = _check_pointer(i0, 5105);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(i2, i1, OOC_UINT32, 5105))*4);
  return (Object__Object)i0;
  ;
}

void ADT_ArrayList__ArrayListDesc_Set(ADT_ArrayList__ArrayList l, OOC_INT32 index, Object__Object obj) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)l;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 5443))+4);
  i2 = index;
  _assert((i2<i1), 127, 5426);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5457));
  i0 = _check_pointer(i0, 5464);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  i3 = (OOC_INT32)obj;
  *(OOC_INT32*)(i0+(_check_index(i2, i1, OOC_UINT32, 5464))*4) = i3;
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
  i3 = *(OOC_INT32*)((_check_pointer(i2, 6324))+4);
  i4 = i0<i3;
  if (!i4) goto l8;
  i4 = (i1*(-1))+i0;
  
l3_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 6343));
  i5 = _check_pointer(i5, 6350);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 6364));
  i7 = _check_pointer(i7, 6371);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)(i7+(_check_index(i0, i8, OOC_UINT32, 6371))*4);
  *(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 6350))*4) = i7;
  i0 = i0+1;
  i = i0;
  i4 = i4+1;
  i5 = i0<i3;
  if (i5) goto l3_loop;
l8:
  i0 = *(OOC_INT32*)((_check_pointer(i2, 6394))+4);
  *(OOC_INT32*)((_check_pointer(i2, 6394))+4) = (i0-i1);
  return;
  ;
}

void ADT_ArrayList__ArrayListDesc_Remove(ADT_ArrayList__ArrayList l, OOC_INT32 index) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)l;
  i1 = index;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6767)))), ADT_ArrayList__ArrayListDesc_RemoveRange)),ADT_ArrayList__ArrayListDesc_RemoveRange)((ADT_ArrayList__ArrayList)i0, i1, (i1+1));
  return;
  ;
}

void ADT_ArrayList__ArrayListDesc_TrimToSize(ADT_ArrayList__ArrayList l) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)l;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7060));
  i2 = *(OOC_INT32*)((_check_pointer(i0, 7045))+4);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 7067)), 0);
  i1 = i2!=i1;
  if (!i1) goto l4;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 7099))+4);
  ADT_ArrayList__ArrayListDesc_CreateArray((ADT_ArrayList__ArrayList)i0, i1, (ADT_ArrayList__ArrayList)i0);
l4:
  return;
  ;
}

OOC_INT32 ADT_ArrayList__ArrayListDesc_Size(ADT_ArrayList__ArrayList l) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)l;
  i0 = *(OOC_INT32*)((_check_pointer(i0, 7257))+4);
  return i0;
  ;
}

OOC_CHAR8 ADT_ArrayList__ArrayListDesc_Contains(ADT_ArrayList__ArrayList l, Object__Object obj) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT32 i;

  i0 = (OOC_INT32)l;
  i = 0;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 7455))+4);
  i2 = 0<i1;
  if (!i2) goto l11;
  i2 = (OOC_INT32)obj;
  i3=0;
l3_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7490));
  i4 = _check_pointer(i4, 7497);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 7497))*4);
  i4 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 7479)))), Object__ObjectDesc_Equals)),Object__ObjectDesc_Equals)((Object__Object)i2, (Object__Object)i4);
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
  i1 = *(OOC_INT32*)((_check_pointer(i0, 7869))+4);
  i2 = 0<i1;
  if (!i2) goto l11;
  i2 = (OOC_INT32)obj;
  i3=0;
l3_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7904));
  i4 = _check_pointer(i4, 7911);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 7911))*4);
  i4 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 7893)))), Object__ObjectDesc_Equals)),Object__ObjectDesc_Equals)((Object__Object)i2, (Object__Object)i4);
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
  i1 = *(OOC_INT32*)((_check_pointer(i0, 8274))+4);
  i1 = i1-1;
  i = i1;
  i2 = i1>=0;
  if (!i2) goto l11;
  i2 = (OOC_INT32)obj;
  
l3_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 8320));
  i3 = _check_pointer(i3, 8327);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i1, i4, OOC_UINT32, 8327))*4);
  i3 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 8309)))), Object__ObjectDesc_Equals)),Object__ObjectDesc_Equals)((Object__Object)i2, (Object__Object)i3);
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
  i0 = *(OOC_INT32*)((_check_pointer(i0, 8521))+4);
  return (i0==0);
  ;
}

OOC_CHAR8 ADT_ArrayList__ArrayListDesc_Equals(ADT_ArrayList__ArrayList l, Object__Object obj) {

  _assert(0u, 127, 8659);
  _failed_function(8579); return 0;
  ;
}

OOC_INT32 ADT_ArrayList__ArrayListDesc_HashCode(ADT_ArrayList__ArrayList l) {

  _assert(0u, 127, 8794);
  _failed_function(8726); return 0;
  ;
}

void ADT_ArrayList__ArrayListDesc_Store(ADT_ArrayList__ArrayList l, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT32 i;

  i0 = (OOC_INT32)l;
  i1 = (OOC_INT32)w;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 8956))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8943)))), IO_BinaryRider__WriterDesc_WriteNum)),IO_BinaryRider__WriterDesc_WriteNum)((IO_BinaryRider__Writer)i1, i2);
  i = 0;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 8984))+4);
  i3 = 0<i2;
  if (!i3) goto l8;
  i3=0;
l3_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 9019));
  i4 = _check_pointer(i4, 9026);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 9026))*4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9003)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i1, (Object__Object)i4);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9191)))), IO_BinaryRider__ReaderDesc_ReadNum)),IO_BinaryRider__ReaderDesc_ReadNum)((IO_BinaryRider__Reader)i0, (void*)(OOC_INT32)&size);
  i1 = (OOC_INT32)l;
  i2 = size;
  ADT_ArrayList__ArrayListDesc_INIT((ADT_ArrayList__ArrayList)i1, i2);
  i = 0;
  i2 = size;
  i3 = 0<i2;
  if (!i3) goto l8;
  i3=0;
l3_loop:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9262)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i0, (void*)(OOC_INT32)&obj);
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 9289));
  i4 = _check_pointer(i4, 9296);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)obj;
  *(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 9296))*4) = ((OOC_INT32)_type_cast_fast(OOC_INT32, OOC_INT32, i6));
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l3_loop;
l8:
  i0 = size;
  *(OOC_INT32*)((_check_pointer(i1, 9337))+4) = i0;
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
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 9819));
      i4 = _check_pointer(i4, 9825);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 9807));
      i3 = _check_pointer(i3, 9813);
      i6 = OOC_ARRAY_LENGTH(i3, 0);
      i7 = (OOC_INT32)cmp;
      i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i1, i6, OOC_UINT32, 9813))*4);
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i0, i5, OOC_UINT32, 9825))*4);
      i3 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 9797)))), ADT_Comparator__ComparatorDesc_Compare)),ADT_Comparator__ComparatorDesc_Compare)((ADT_Comparator__Comparator)i7, (Object__Object)i3, (Object__Object)i4);
      i3 = i3>0;
      if (!i3) goto l5;
      i3 = (OOC_INT32)a;
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 9856));
      i4 = _check_pointer(i4, 9862);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i1, i5, OOC_UINT32, 9862))*4);
      t = (Object__Object)i4;
      i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 9868));
      i5 = _check_pointer(i5, 9874);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i7 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 9882));
      i7 = _check_pointer(i7, 9888);
      i8 = OOC_ARRAY_LENGTH(i7, 0);
      i7 = (OOC_INT32)*(OOC_INT32*)(i7+(_check_index(i0, i8, OOC_UINT32, 9888))*4);
      *(OOC_INT32*)(i5+(_check_index(i1, i6, OOC_UINT32, 9874))*4) = i7;
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 9894));
      i3 = _check_pointer(i3, 9900);
      i5 = OOC_ARRAY_LENGTH(i3, 0);
      *(OOC_INT32*)(i3+(_check_index(i0, i5, OOC_UINT32, 9900))*4) = i4;
l5:
      i3 = (OOC_INT32)a;
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 9959));
      i4 = _check_pointer(i4, 9965);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 9947));
      i3 = _check_pointer(i3, 9953);
      i6 = OOC_ARRAY_LENGTH(i3, 0);
      i7 = (OOC_INT32)cmp;
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i2, i5, OOC_UINT32, 9965))*4);
      i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i1, i6, OOC_UINT32, 9953))*4);
      i3 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 9937)))), ADT_Comparator__ComparatorDesc_Compare)),ADT_Comparator__ComparatorDesc_Compare)((ADT_Comparator__Comparator)i7, (Object__Object)i3, (Object__Object)i4);
      i3 = i3>0;
      if (!i3) goto l8;
      i3 = (OOC_INT32)a;
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 9996));
      i4 = _check_pointer(i4, 10002);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i1, i5, OOC_UINT32, 10002))*4);
      t = (Object__Object)i4;
      i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 10008));
      i5 = _check_pointer(i5, 10014);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i7 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 10022));
      i7 = _check_pointer(i7, 10028);
      i8 = OOC_ARRAY_LENGTH(i7, 0);
      i7 = (OOC_INT32)*(OOC_INT32*)(i7+(_check_index(i2, i8, OOC_UINT32, 10028))*4);
      *(OOC_INT32*)(i5+(_check_index(i1, i6, OOC_UINT32, 10014))*4) = i7;
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 10034));
      i3 = _check_pointer(i3, 10040);
      i5 = OOC_ARRAY_LENGTH(i3, 0);
      *(OOC_INT32*)(i3+(_check_index(i2, i5, OOC_UINT32, 10040))*4) = i4;
l8:
      i3 = (OOC_INT32)a;
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 10099));
      i4 = _check_pointer(i4, 10105);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 10087));
      i3 = _check_pointer(i3, 10093);
      i6 = OOC_ARRAY_LENGTH(i3, 0);
      i7 = (OOC_INT32)cmp;
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i2, i5, OOC_UINT32, 10105))*4);
      i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i0, i6, OOC_UINT32, 10093))*4);
      i3 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 10077)))), ADT_Comparator__ComparatorDesc_Compare)),ADT_Comparator__ComparatorDesc_Compare)((ADT_Comparator__Comparator)i7, (Object__Object)i3, (Object__Object)i4);
      i3 = i3>0;
      if (!i3) goto l11;
      i3 = (OOC_INT32)a;
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 10136));
      i4 = _check_pointer(i4, 10142);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i0, i5, OOC_UINT32, 10142))*4);
      t = (Object__Object)i4;
      i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 10148));
      i5 = _check_pointer(i5, 10154);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i7 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 10162));
      i7 = _check_pointer(i7, 10168);
      i8 = OOC_ARRAY_LENGTH(i7, 0);
      i7 = (OOC_INT32)*(OOC_INT32*)(i7+(_check_index(i2, i8, OOC_UINT32, 10168))*4);
      *(OOC_INT32*)(i5+(_check_index(i0, i6, OOC_UINT32, 10154))*4) = i7;
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 10174));
      i3 = _check_pointer(i3, 10180);
      i5 = OOC_ARRAY_LENGTH(i3, 0);
      *(OOC_INT32*)(i3+(_check_index(i2, i5, OOC_UINT32, 10180))*4) = i4;
l11:
      i2 = (OOC_INT32)a;
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 10225));
      i2 = _check_pointer(i2, 10231);
      i3 = OOC_ARRAY_LENGTH(i2, 0);
      i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i0, i3, OOC_UINT32, 10231))*4);
      v = (Object__Object)i2;
      j = i0;
      i3 = i1-1;
      i4=i0;
l12_loop:
      
l13_loop:
      i3 = i3+1;
      i = i3;
      i5 = (OOC_INT32)a;
      i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 10335));
      i5 = _check_pointer(i5, 10341);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i7 = (OOC_INT32)cmp;
      i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i3, i6, OOC_UINT32, 10341))*4);
      i5 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 10325)))), ADT_Comparator__ComparatorDesc_Compare)),ADT_Comparator__ComparatorDesc_Compare)((ADT_Comparator__Comparator)i7, (Object__Object)i5, (Object__Object)i2);
      i5 = i5>=0;
      if (!i5) goto l13_loop;
l18_loop:
      i4 = i4-1;
      j = i4;
      i5 = i4<0;
      if (i5) goto l21;
      i5 = (OOC_INT32)a;
      i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 10435));
      i5 = _check_pointer(i5, 10441);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i7 = (OOC_INT32)cmp;
      i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 10441))*4);
      i5 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 10425)))), ADT_Comparator__ComparatorDesc_Compare)),ADT_Comparator__ComparatorDesc_Compare)((ADT_Comparator__Comparator)i7, (Object__Object)i5, (Object__Object)i2);
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
      i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 10532));
      i6 = _check_pointer(i6, 10538);
      i7 = OOC_ARRAY_LENGTH(i6, 0);
      i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i3, i7, OOC_UINT32, 10538))*4);
      t = (Object__Object)i6;
      i7 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 10544));
      i7 = _check_pointer(i7, 10550);
      i8 = OOC_ARRAY_LENGTH(i7, 0);
      i9 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 10558));
      i9 = _check_pointer(i9, 10564);
      i10 = OOC_ARRAY_LENGTH(i9, 0);
      i9 = (OOC_INT32)*(OOC_INT32*)(i9+(_check_index(i4, i10, OOC_UINT32, 10564))*4);
      *(OOC_INT32*)(i7+(_check_index(i3, i8, OOC_UINT32, 10550))*4) = i9;
      i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 10570));
      i5 = _check_pointer(i5, 10576);
      i7 = OOC_ARRAY_LENGTH(i5, 0);
      *(OOC_INT32*)(i5+(_check_index(i4, i7, OOC_UINT32, 10576))*4) = i6;
      
      goto l12_loop;
l30:
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 10612));
      i2 = _check_pointer(i2, 10618);
      i4 = OOC_ARRAY_LENGTH(i2, 0);
      i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i3, i4, OOC_UINT32, 10618))*4);
      t = (Object__Object)i2;
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 10624));
      i4 = _check_pointer(i4, 10630);
      i6 = OOC_ARRAY_LENGTH(i4, 0);
      i7 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 10638));
      i7 = _check_pointer(i7, 10644);
      i8 = OOC_ARRAY_LENGTH(i7, 0);
      i7 = (OOC_INT32)*(OOC_INT32*)(i7+(_check_index(i0, i8, OOC_UINT32, 10644))*4);
      *(OOC_INT32*)(i4+(_check_index(i3, i6, OOC_UINT32, 10630))*4) = i7;
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 10650));
      i4 = _check_pointer(i4, 10656);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      *(OOC_INT32*)(i4+(_check_index(i0, i5, OOC_UINT32, 10656))*4) = i2;
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
  i1 = *(OOC_INT32*)((_check_pointer(i0, 10950))+4);
  i1 = (OOC_INT32)RT0__NewObject(_td_Object__ObjectArrayPtr.baseTypes[0], i1);
  a = (Object__ObjectArrayPtr)i1;
  i = 0;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 10977))+4);
  i3 = 0<i2;
  if (!i3) goto l8;
  i3=0;
l3_loop:
  i4 = _check_pointer(i1, 10995);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 11003));
  i6 = _check_pointer(i6, 11009);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i3, i7, OOC_UINT32, 11009))*4);
  *(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 10995))*4) = i6;
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l3_loop;
l8:
  return (Object__ObjectArrayPtr)i1;
  ;
}

void ADT_ArrayList__IterElementsDesc_INIT(ADT_ArrayList__IterElements iter, ADT_ArrayList__ArrayList list) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)iter;
  i1 = (OOC_INT32)list;
  *(OOC_INT32*)(_check_pointer(i0, 11132)) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 11155))+4) = 0;
  return;
  ;
}

ADT_ArrayList__IterElements ADT_ArrayList__ArrayListDesc_IterElements(ADT_ArrayList__ArrayList l) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)RT0__NewObject(_td__qtd6.baseTypes[0]);
  i1 = (OOC_INT32)l;
  ADT_ArrayList__IterElementsDesc_INIT((ADT_ArrayList__IterElements)i0, (ADT_ArrayList__ArrayList)i1);
  return (ADT_ArrayList__IterElements)i0;
  ;
}

OOC_CHAR8 ADT_ArrayList__IterElementsDesc_Next(ADT_ArrayList__IterElements iter, Object__Object *elem) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)iter;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 11716));
  i2 = *(OOC_INT32*)((_check_pointer(i0, 11704))+4);
  i1 = *(OOC_INT32*)((_check_pointer(i1, 11721))+4);
  i1 = i2>=i1;
  if (i1) goto l3;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 11780));
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 11785));
  i1 = _check_pointer(i1, 11791);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 11796))+4);
  i3 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(i2, i3, OOC_UINT32, 11791))*4);
  *elem = (Object__Object)i1;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 11817))+4);
  *(OOC_INT32*)((_check_pointer(i0, 11817))+4) = (i1+1);
  return 1u;
  goto l4;
l3:
  return 0u;
l4:
  _failed_function(11655); return 0;
  ;
}

void OOC_ADT_ArrayList_init(void) {

  return;
  ;
}

void OOC_ADT_ArrayList_destroy(void) {
}

/* --- */
