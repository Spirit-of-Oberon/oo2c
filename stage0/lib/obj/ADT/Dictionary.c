#include <ADT/Dictionary.d>
#include <__oo2c.h>
#include <setjmp.h>

void ADT_Dictionary__DictionaryDesc_INIT(ADT_Dictionary__Dictionary dict) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)dict;
  *(OOC_INT32*)((_check_pointer(i0, 4887))+8) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 4908))+12) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 4929))+16) = (OOC_INT32)0;
  *(OOC_INT32*)(_check_pointer(i0, 4953)) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 4974))+4) = 0;
  return;
  ;
}

ADT_Dictionary__Dictionary ADT_Dictionary__New(void) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)RT0__NewObject(_td__qtd1.baseTypes[0]);
  ADT_Dictionary__DictionaryDesc_INIT((ADT_Dictionary__Dictionary)i0);
  return (ADT_Dictionary__Dictionary)i0;
  ;
}

void ADT_Dictionary__DictionaryDesc_Destroy(ADT_Dictionary__Dictionary dict) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_INT32 i;

  i0 = (OOC_INT32)dict;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5206))+16);
  i1 = i1!=(OOC_INT32)0;
  if (!i1) goto l11;
  i = 0;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 5250))+8);
  i2 = 0<i1;
  if (!i2) goto l10;
  i2=0;
l5_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5313))+16);
  i3 = _check_pointer(i3, 5320);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)((i3+((_check_index(i2, i4, OOC_UINT32, 5320))*12))+4) = (OOC_INT32)0;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5349))+16);
  i3 = _check_pointer(i3, 5356);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)((i3+((_check_index(i2, i4, OOC_UINT32, 5356))*12))+8) = (OOC_INT32)0;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5387))+16);
  i3 = _check_pointer(i3, 5394);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)(i3+((_check_index(i2, i4, OOC_UINT32, 5394))*12)) = 0;
  i2 = i2+1;
  i = i2;
  i3 = i2<i1;
  if (i3) goto l5_loop;
l10:
  *(OOC_INT32*)((_check_pointer(i0, 5430))+16) = (OOC_INT32)0;
l11:
  return;
  ;
}

static OOC_CHAR8 ADT_Dictionary__IsSet(Object__Object key) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)key;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l3;
  i0=0u;
  goto l4;
l3:
  i1 = (OOC_INT32)ADT_Dictionary__dummy;
  i0 = i0!=i1;
  
l4:
  return i0;
  ;
}

OOC_INT32 ADT_Dictionary__DictionaryDesc_InternalLookup(ADT_Dictionary__Dictionary dict, Object__Object key, OOC_INT32 hash) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
  ADT_Dictionary__Table t;
  OOC_UINT32 mask;
  OOC_INT32 i;
  OOC_INT32 freeslot;
  OOC_INT32 incr;

  i0 = (OOC_INT32)dict;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6885))+16);
  t = (ADT_Dictionary__Table)i1;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 6922))+8);
  i3 = hash;
  i4 = _type_cast_fast(OOC_UINT32, OOC_INT32, i3);
  i2 = _type_cast_fast(OOC_UINT32, OOC_INT32, (i2-1));
  mask = i2;
  i5 = _type_cast_fast(OOC_INT32, OOC_UINT32, ((~i4)&i2));
  i = i5;
  i6 = _check_pointer(i1, 6995);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((i6+((_check_index(i5, i7, OOC_UINT32, 6995))*12))+4);
  i6 = i6==(OOC_INT32)0;
  if (i6) goto l3;
  i6 = _check_pointer(i1, 7016);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((i6+((_check_index(i5, i7, OOC_UINT32, 7016))*12))+4);
  i7 = (OOC_INT32)key;
  i6 = i6==i7;
  
  goto l4;
l3:
  i6=1u;
l4:
  i7 = (OOC_INT32)key;
  if (i6) goto l19;
  i6 = _check_pointer(i1, 7064);
  i8 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((i6+((_check_index(i5, i8, OOC_UINT32, 7064))*12))+4);
  i8 = (OOC_INT32)ADT_Dictionary__dummy;
  i6 = i6==i8;
  if (i6) goto l17;
  i6 = _check_pointer(i1, 7119);
  i8 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = *(OOC_INT32*)(i6+((_check_index(i5, i8, OOC_UINT32, 7119))*12));
  i6 = i6==i3;
  if (i6) goto l11;
  i6=0u;
  goto l13;
l11:
  i6 = _check_pointer(i1, 7153);
  i8 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((i6+((_check_index(i5, i8, OOC_UINT32, 7153))*12))+4);
  i6 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 7142)))), Object__ObjectDesc_Equals)),Object__ObjectDesc_Equals)((Object__Object)i7, (Object__Object)i6);
  
l13:
  if (i6) goto l15;
  freeslot = (-1);
  goto l20;
l15:
  return i5;
  goto l20;
l17:
  freeslot = i5;
  goto l20;
l19:
  return i5;
l20:
  i4 = _type_cast_fast(OOC_INT32, OOC_UINT32, ((i4^(_type_cast_fast(OOC_UINT32, OOC_INT32, (_lsh(OOC_INT32, i3, (-3))))))&i2));
  incr = i4;
  i6 = i4==0;
  if (!i6) goto l24;
  i4 = *(OOC_INT32*)((_check_pointer(i0, 7355))+8);
  i4 = i4-1;
  incr = i4;
  
l24:
  {register OOC_INT32 h0=i4;i4=i5;i5=h0;}
l25_loop:
  i4 = _type_cast_fast(OOC_INT32, OOC_UINT32, ((_type_cast_fast(OOC_UINT32, OOC_INT32, (i4+i5)))&i2));
  i = i4;
  i6 = _check_pointer(i1, 7448);
  i8 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((i6+((_check_index(i4, i8, OOC_UINT32, 7448))*12))+4);
  i6 = i6==(OOC_INT32)0;
  if (i6) goto l42;
  i6 = _check_pointer(i1, 7585);
  i8 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((i6+((_check_index(i4, i8, OOC_UINT32, 7585))*12))+4);
  i8 = (OOC_INT32)ADT_Dictionary__dummy;
  i6 = i6==i8;
  if (i6) goto l37;
  i6 = _check_pointer(i1, 7689);
  i8 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = *(OOC_INT32*)(i6+((_check_index(i4, i8, OOC_UINT32, 7689))*12));
  i6 = i6==i3;
  if (i6) goto l32;
  i6=0u;
  goto l34;
l32:
  i6 = _check_pointer(i1, 7723);
  i8 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((i6+((_check_index(i4, i8, OOC_UINT32, 7723))*12))+4);
  i6 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 7712)))), Object__ObjectDesc_Equals)),Object__ObjectDesc_Equals)((Object__Object)i7, (Object__Object)i6);
  
l34:
  if (!i6) goto l47;
  return i4;
  goto l47;
l37:
  i6 = freeslot;
  i6 = i6<0;
  if (!i6) goto l47;
  freeslot = i4;
  goto l47;
l42:
  i6 = freeslot;
  i8 = i6>=0;
  if (i8) goto l45;
  return i4;
  goto l47;
l45:
  return i6;
l47:
  i5 = i5*2;
  incr = i5;
  i6 = *(OOC_INT32*)((_check_pointer(i0, 7810))+8);
  i6 = i5>=i6;
  if (!i6) goto l25_loop;
  i6 = *(OOC_INT32*)((_check_pointer(i0, 7891))+12);
  i5 = _type_cast_fast(OOC_INT32, OOC_UINT32, ((_type_cast_fast(OOC_UINT32, OOC_INT32, i5))^(_type_cast_fast(OOC_UINT32, OOC_INT32, i6))));
  incr = i5;
  
  goto l25_loop;
l53:
  ;
}

void ADT_Dictionary__DictionaryDesc_Insert(ADT_Dictionary__Dictionary dict, Object__Object key, OOC_INT32 hash, Object__Object value) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT32 i;

  i0 = hash;
  i1 = (OOC_INT32)key;
  i2 = (OOC_INT32)dict;
  i3 = ADT_Dictionary__DictionaryDesc_InternalLookup((ADT_Dictionary__Dictionary)i2, (Object__Object)i1, i0);
  i = i3;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 8283))+16);
  i4 = _check_pointer(i4, 8290);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 8290))*12))+4);
  i4 = ADT_Dictionary__IsSet((Object__Object)i4);
  if (i4) goto l6;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 8450))+16);
  i4 = _check_pointer(i4, 8457);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 8457))*12))+4);
  i4 = i4==(OOC_INT32)0;
  if (!i4) goto l5;
  i4 = *(OOC_INT32*)(_check_pointer(i2, 8495));
  *(OOC_INT32*)(_check_pointer(i2, 8495)) = (i4+1);
l5:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 8524))+16);
  i4 = _check_pointer(i4, 8531);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  *(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 8531))*12))+4) = i1;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 8558))+16);
  i1 = _check_pointer(i1, 8565);
  i4 = OOC_ARRAY_LENGTH(i1, 0);
  *(OOC_INT32*)(i1+((_check_index(i3, i4, OOC_UINT32, 8565))*12)) = i0;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 8594))+16);
  i0 = _check_pointer(i0, 8601);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  i4 = (OOC_INT32)value;
  *(OOC_INT32*)((i0+((_check_index(i3, i1, OOC_UINT32, 8601))*12))+8) = i4;
  i0 = *(OOC_INT32*)((_check_pointer(i2, 8637))+4);
  *(OOC_INT32*)((_check_pointer(i2, 8637))+4) = (i0+1);
  goto l7;
l6:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 8342))+16);
  i0 = _check_pointer(i0, 8349);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  i2 = (OOC_INT32)value;
  *(OOC_INT32*)((i0+((_check_index(i3, i1, OOC_UINT32, 8349))*12))+8) = i2;
l7:
  return;
  ;
}

void ADT_Dictionary__DictionaryDesc_Resize(ADT_Dictionary__Dictionary dict, OOC_INT32 minUsed) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9;
  OOC_INT32 oldSize;
  ADT_Dictionary__Table oldTable;
  OOC_INT32 i;
  OOC_INT32 newSize;
  OOC_INT32 newPoly;
  ADT_Dictionary__Table newTable;

  i0 = (OOC_INT32)dict;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 9054))+8);
  oldSize = i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9082))+16);
  oldTable = (ADT_Dictionary__Table)i2;
  newSize = 4;
  i3 = minUsed;
  i4 = 4<=i3;
  if (i4) goto l3;
  i3=0;i4=4;
  goto l9;
l3:
  i4=0;i5=4;
l4_loop:
  i5 = _ash(i5,1);
  newSize = i5;
  i4 = i4+1;
  i6 = i5<=i3;
  if (i6) goto l4_loop;
l8:
  i3=i4;i4=i5;
l9:
  i3 = *(OOC_INT32*)((OOC_INT32)ADT_Dictionary__polys+(_check_index(i3, 29, OOC_UINT32, 9235))*4);
  newPoly = i3;
  i5 = (OOC_INT32)RT0__NewObject(_td_ADT_Dictionary__Table.baseTypes[0], i4);
  newTable = (ADT_Dictionary__Table)i5;
  i = 0;
  i6 = 0<i4;
  if (!i6) goto l17;
  i6=0;
l12_loop:
  i7 = _check_pointer(i5, 9374);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  *(OOC_INT32*)((i7+((_check_index(i6, i8, OOC_UINT32, 9374))*12))+4) = (OOC_INT32)0;
  i7 = _check_pointer(i5, 9405);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  *(OOC_INT32*)((i7+((_check_index(i6, i8, OOC_UINT32, 9405))*12))+8) = (OOC_INT32)0;
  i7 = _check_pointer(i5, 9438);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  *(OOC_INT32*)(i7+((_check_index(i6, i8, OOC_UINT32, 9438))*12)) = 0;
  i6 = i6+1;
  i = i6;
  i7 = i6<i4;
  if (i7) goto l12_loop;
l17:
  *(OOC_INT32*)((_check_pointer(i0, 9470))+8) = i4;
  *(OOC_INT32*)((_check_pointer(i0, 9497))+12) = i3;
  *(OOC_INT32*)((_check_pointer(i0, 9524))+16) = i5;
  *(OOC_INT32*)(_check_pointer(i0, 9553)) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 9574))+4) = 0;
  i = 0;
  i3 = 0<i1;
  if (!i3) goto l28;
  i3=0;
l20_loop:
  i4 = _check_pointer(i2, 9647);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 9647))*12))+4);
  i4 = ADT_Dictionary__IsSet((Object__Object)i4);
  if (!i4) goto l23;
  i4 = _check_pointer(i2, 9727);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = _check_pointer(i2, 9708);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i8 = _check_pointer(i2, 9690);
  i9 = OOC_ARRAY_LENGTH(i8, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 9727))*12))+8);
  i5 = (OOC_INT32)*(OOC_INT32*)((i8+((_check_index(i3, i9, OOC_UINT32, 9690))*12))+4);
  i6 = *(OOC_INT32*)(i6+((_check_index(i3, i7, OOC_UINT32, 9708))*12));
  ADT_Dictionary__DictionaryDesc_Insert((ADT_Dictionary__Dictionary)i0, (Object__Object)i5, i6, (Object__Object)i4);
  i4 = _check_pointer(i2, 9756);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  *(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 9756))*12))+4) = (OOC_INT32)0;
  i4 = _check_pointer(i2, 9817);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  *(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 9817))*12))+8) = (OOC_INT32)0;
l23:
  i3 = i3+1;
  i = i3;
  i4 = i3<i1;
  if (i4) goto l20_loop;
l28:
  return;
  ;
}

OOC_CHAR8 ADT_Dictionary__DictionaryDesc_HasKey(ADT_Dictionary__Dictionary dict, Object__Object key) {
  register OOC_INT32 i0,i1,i2;
  OOC_INT32 index;

  i0 = (OOC_INT32)dict;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 10117))+4);
  i1 = i1==0;
  if (i1) goto l3;
  i1 = (OOC_INT32)key;
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 10205)))), Object__ObjectDesc_HashCode)),Object__ObjectDesc_HashCode)((Object__Object)i1);
  i1 = ADT_Dictionary__DictionaryDesc_InternalLookup((ADT_Dictionary__Dictionary)i0, (Object__Object)i1, i2);
  index = i1;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10243))+16);
  i0 = _check_pointer(i0, 10250);
  i2 = OOC_ARRAY_LENGTH(i0, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)((i0+((_check_index(i1, i2, OOC_UINT32, 10250))*12))+4);
  i0 = ADT_Dictionary__IsSet((Object__Object)i0);
  return i0;
  goto l4;
l3:
  return 0u;
l4:
  _failed_function(9905); return 0;
  ;
}

OOC_INT32 ADT_Dictionary__DictionaryDesc_Size(ADT_Dictionary__Dictionary dict) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)dict;
  i0 = *(OOC_INT32*)((_check_pointer(i0, 10418))+4);
  return i0;
  ;
}

Object__Object ADT_Dictionary__DictionaryDesc_Get(ADT_Dictionary__Dictionary dict, Object__Object key) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_INT32 i;

  i0 = (OOC_INT32)key;
  _assert((i0!=(OOC_INT32)0), 127, 10776);
  i1 = (OOC_INT32)dict;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 10812))+4);
  _assert((i2!=0), 127, 10800);
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10862)))), Object__ObjectDesc_HashCode)),Object__ObjectDesc_HashCode)((Object__Object)i0);
  i0 = ADT_Dictionary__DictionaryDesc_InternalLookup((ADT_Dictionary__Dictionary)i1, (Object__Object)i0, i2);
  i = i0;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 10900))+16);
  i2 = _check_pointer(i2, 10907);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)((i2+((_check_index(i0, i3, OOC_UINT32, 10907))*12))+4);
  i2 = ADT_Dictionary__IsSet((Object__Object)i2);
  _assert(i2, 127, 10881);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 10934))+16);
  i1 = _check_pointer(i1, 10941);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)((i1+((_check_index(i0, i2, OOC_UINT32, 10941))*12))+8);
  return (Object__Object)i0;
  ;
}

OOC_CHAR8 ADT_Dictionary__DictionaryDesc_Lookup(ADT_Dictionary__Dictionary dict, Object__Object key, Object__Object *value) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_INT32 i;

  i0 = (OOC_INT32)key;
  _assert((i0!=(OOC_INT32)0), 127, 11371);
  i1 = (OOC_INT32)dict;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 11402))+4);
  i2 = i2==0;
  if (i2) goto l7;
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11485)))), Object__ObjectDesc_HashCode)),Object__ObjectDesc_HashCode)((Object__Object)i0);
  i0 = ADT_Dictionary__DictionaryDesc_InternalLookup((ADT_Dictionary__Dictionary)i1, (Object__Object)i0, i2);
  i = i0;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11520))+16);
  i2 = _check_pointer(i2, 11527);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)((i2+((_check_index(i0, i3, OOC_UINT32, 11527))*12))+4);
  i2 = ADT_Dictionary__IsSet((Object__Object)i2);
  if (i2) goto l5;
  return 0u;
  goto l8;
l5:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11563))+16);
  i1 = _check_pointer(i1, 11570);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)((i1+((_check_index(i0, i2, OOC_UINT32, 11570))*12))+8);
  *value = (Object__Object)i0;
  return 1u;
  goto l8;
l7:
  return 0u;
l8:
  _failed_function(10999); return 0;
  ;
}

void ADT_Dictionary__DictionaryDesc_Set(ADT_Dictionary__Dictionary dict, Object__Object key, Object__Object value) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)key;
  _assert((i0!=(OOC_INT32)0), 127, 12057);
  i1 = (OOC_INT32)dict;
  i2 = *(OOC_INT32*)(_check_pointer(i1, 12089));
  i3 = *(OOC_INT32*)((_check_pointer(i1, 12105))+8);
  i2 = (i2*3)>=(i3*2);
  if (!i2) goto l4;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 12142))+4);
  ADT_Dictionary__DictionaryDesc_Resize((ADT_Dictionary__Dictionary)i1, (i2*2));
l4:
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12185)))), Object__ObjectDesc_HashCode)),Object__ObjectDesc_HashCode)((Object__Object)i0);
  i3 = (OOC_INT32)value;
  ADT_Dictionary__DictionaryDesc_Insert((ADT_Dictionary__Dictionary)i1, (Object__Object)i0, i2, (Object__Object)i3);
  return;
  ;
}

ADT_Dictionary__Dictionary ADT_Dictionary__DictionaryDesc_Copy(ADT_Dictionary__Dictionary dict) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9;
  ADT_Dictionary__Dictionary copy;
  OOC_INT32 i;

  i0 = (OOC_INT32)RT0__NewObject(_td__qtd3.baseTypes[0]);
  ADT_Dictionary__DictionaryDesc_INIT((ADT_Dictionary__Dictionary)i0);
  copy = (ADT_Dictionary__Dictionary)i0;
  i1 = (OOC_INT32)dict;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 12505))+4);
  i2 = i2>0;
  if (!i2) goto l14;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 12545))+4);
  ADT_Dictionary__DictionaryDesc_Resize((ADT_Dictionary__Dictionary)i0, ((i2*3)>>1));
  i2 = *(OOC_INT32*)((_check_pointer(i1, 12587))+8);
  i = 0;
  i3 = 0<i2;
  if (!i3) goto l14;
  i3=0;
l5_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12621))+16);
  i4 = _check_pointer(i4, 12628);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 12628))*12))+4);
  i4 = ADT_Dictionary__IsSet((Object__Object)i4);
  if (!i4) goto l8;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12730))+16);
  i4 = _check_pointer(i4, 12736);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12688))+16);
  i6 = _check_pointer(i6, 12694);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12669))+16);
  i8 = _check_pointer(i8, 12675);
  i9 = OOC_ARRAY_LENGTH(i8, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 12736))*12))+8);
  i5 = (OOC_INT32)*(OOC_INT32*)((i8+((_check_index(i3, i9, OOC_UINT32, 12675))*12))+4);
  i6 = *(OOC_INT32*)(i6+((_check_index(i3, i7, OOC_UINT32, 12694))*12));
  ADT_Dictionary__DictionaryDesc_Insert((ADT_Dictionary__Dictionary)i0, (Object__Object)i5, i6, (Object__Object)i4);
l8:
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l5_loop;
l14:
  return (ADT_Dictionary__Dictionary)i0;
  ;
}

void ADT_Dictionary__DictionaryDesc_Delete(ADT_Dictionary__Dictionary dict, Object__Object key) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_INT32 i;

  i0 = (OOC_INT32)key;
  _assert((i0!=(OOC_INT32)0), 127, 13142);
  i1 = (OOC_INT32)dict;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 13178))+4);
  _assert((i2!=0), 127, 13166);
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13228)))), Object__ObjectDesc_HashCode)),Object__ObjectDesc_HashCode)((Object__Object)i0);
  i0 = ADT_Dictionary__DictionaryDesc_InternalLookup((ADT_Dictionary__Dictionary)i1, (Object__Object)i0, i2);
  i = i0;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 13266))+16);
  i2 = _check_pointer(i2, 13273);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)((i2+((_check_index(i0, i3, OOC_UINT32, 13273))*12))+4);
  i2 = ADT_Dictionary__IsSet((Object__Object)i2);
  _assert(i2, 127, 13247);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 13337))+16);
  i2 = _check_pointer(i2, 13343);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i4 = (OOC_INT32)ADT_Dictionary__dummy;
  *(OOC_INT32*)((i2+((_check_index(i0, i3, OOC_UINT32, 13343))*12))+4) = ((OOC_INT32)_type_cast_fast(OOC_INT32, OOC_INT32, i4));
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 13379))+16);
  i2 = _check_pointer(i2, 13385);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  *(OOC_INT32*)((i2+((_check_index(i0, i3, OOC_UINT32, 13385))*12))+8) = (OOC_INT32)0;
  i0 = *(OOC_INT32*)((_check_pointer(i1, 13416))+4);
  *(OOC_INT32*)((_check_pointer(i1, 13416))+4) = (i0-1);
  return;
  ;
}

void ADT_Dictionary__DictionaryDesc_Clear(ADT_Dictionary__Dictionary dict) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_INT32 i;

  i0 = (OOC_INT32)dict;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13584))+16);
  i1 = i1!=(OOC_INT32)0;
  if (!i1) goto l11;
  i = 0;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 13628))+8);
  i2 = 0<i1;
  if (!i2) goto l10;
  i2=0;
l5_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13691))+16);
  i3 = _check_pointer(i3, 13698);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)((i3+((_check_index(i2, i4, OOC_UINT32, 13698))*12))+4) = (OOC_INT32)0;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13727))+16);
  i3 = _check_pointer(i3, 13734);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)((i3+((_check_index(i2, i4, OOC_UINT32, 13734))*12))+8) = (OOC_INT32)0;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13765))+16);
  i3 = _check_pointer(i3, 13772);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)(i3+((_check_index(i2, i4, OOC_UINT32, 13772))*12)) = 0;
  i2 = i2+1;
  i = i2;
  i3 = i2<i1;
  if (i3) goto l5_loop;
l10:
  ADT_Dictionary__DictionaryDesc_INIT((ADT_Dictionary__Dictionary)i0);
l11:
  return;
  ;
}

Object__ObjectArrayPtr ADT_Dictionary__DictionaryDesc_Keys(ADT_Dictionary__Dictionary dict) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
  Object__ObjectArrayPtr list;
  OOC_INT32 j;
  OOC_INT32 i;

  i0 = (OOC_INT32)dict;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 14112))+4);
  i1 = (OOC_INT32)RT0__NewObject(_td_Object__ObjectArrayPtr.baseTypes[0], i1);
  list = (Object__ObjectArrayPtr)i1;
  j = 0;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 14155))+8);
  i = 0;
  i3 = 0<i2;
  if (i3) goto l3;
  i2=0;
  goto l13;
l3:
  i3=0;i4=0;
l4_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14187))+16);
  i5 = _check_pointer(i5, 14194);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)((i5+((_check_index(i3, i6, OOC_UINT32, 14194))*12))+4);
  i5 = ADT_Dictionary__IsSet((Object__Object)i5);
  if (!i5) goto l8;
  i5 = _check_pointer(i1, 14221);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14232))+16);
  i7 = _check_pointer(i7, 14239);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)((i7+((_check_index(i3, i8, OOC_UINT32, 14239))*12))+4);
  *(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 14221))*4) = i7;
  i4 = i4+1;
  j = i4;
  
l8:
  i3 = i3+1;
  i = i3;
  i5 = i3<i2;
  if (i5) goto l4_loop;
l12:
  i2=i4;
l13:
  i0 = *(OOC_INT32*)((_check_pointer(i0, 14304))+4);
  _assert((i2==i0), 127, 14288);
  return (Object__ObjectArrayPtr)i1;
  ;
}

Object__ObjectArrayPtr ADT_Dictionary__DictionaryDesc_Values(ADT_Dictionary__Dictionary dict) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
  Object__ObjectArrayPtr list;
  OOC_INT32 j;
  OOC_INT32 i;

  i0 = (OOC_INT32)dict;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 14620))+4);
  i1 = (OOC_INT32)RT0__NewObject(_td_Object__ObjectArrayPtr.baseTypes[0], i1);
  list = (Object__ObjectArrayPtr)i1;
  j = 0;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 14663))+8);
  i = 0;
  i3 = 0<i2;
  if (i3) goto l3;
  i2=0;
  goto l13;
l3:
  i3=0;i4=0;
l4_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14695))+16);
  i5 = _check_pointer(i5, 14702);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)((i5+((_check_index(i3, i6, OOC_UINT32, 14702))*12))+4);
  i5 = ADT_Dictionary__IsSet((Object__Object)i5);
  if (!i5) goto l8;
  i5 = _check_pointer(i1, 14729);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14740))+16);
  i7 = _check_pointer(i7, 14747);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)((i7+((_check_index(i3, i8, OOC_UINT32, 14747))*12))+8);
  *(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 14729))*4) = i7;
  i4 = i4+1;
  j = i4;
  
l8:
  i3 = i3+1;
  i = i3;
  i5 = i3<i2;
  if (i5) goto l4_loop;
l12:
  i2=i4;
l13:
  i0 = *(OOC_INT32*)((_check_pointer(i0, 14814))+4);
  _assert((i2==i0), 127, 14798);
  return (Object__ObjectArrayPtr)i1;
  ;
}

ADT_Dictionary__ItemArrayPtr ADT_Dictionary__DictionaryDesc_Items(ADT_Dictionary__Dictionary dict) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
  ADT_Dictionary__ItemArrayPtr list;
  OOC_INT32 j;
  OOC_INT32 i;

  i0 = (OOC_INT32)dict;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 15116))+4);
  i1 = (OOC_INT32)RT0__NewObject(_td_ADT_Dictionary__ItemArrayPtr.baseTypes[0], i1);
  list = (ADT_Dictionary__ItemArrayPtr)i1;
  j = 0;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 15158))+8);
  i = 0;
  i3 = 0<i2;
  if (i3) goto l3;
  i2=0;
  goto l13;
l3:
  i3=0;i4=0;
l4_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15189))+16);
  i5 = _check_pointer(i5, 15195);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)((i5+((_check_index(i3, i6, OOC_UINT32, 15195))*12))+4);
  i5 = ADT_Dictionary__IsSet((Object__Object)i5);
  if (!i5) goto l8;
  i5 = _check_pointer(i1, 15221);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15236))+16);
  i7 = _check_pointer(i7, 15242);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)((i7+((_check_index(i3, i8, OOC_UINT32, 15242))*12))+4);
  *(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 15221))*8) = i7;
  i5 = _check_pointer(i1, 15263);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15280))+16);
  i7 = _check_pointer(i7, 15286);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)((i7+((_check_index(i3, i8, OOC_UINT32, 15286))*12))+8);
  *(OOC_INT32*)((i5+(_check_index(i4, i6, OOC_UINT32, 15263))*8)+4) = i7;
  i4 = i4+1;
  j = i4;
  
l8:
  i3 = i3+1;
  i = i3;
  i5 = i3<i2;
  if (i5) goto l4_loop;
l12:
  i2=i4;
l13:
  i0 = *(OOC_INT32*)((_check_pointer(i0, 15352))+4);
  _assert((i2==i0), 127, 15337);
  return (ADT_Dictionary__ItemArrayPtr)i1;
  ;
}

OOC_CHAR8 ADT_Dictionary__DictionaryDesc_Equals(ADT_Dictionary__Dictionary dict, Object__Object obj) {

  _assert(0u, 127, 15507);
  _failed_function(15427); 
  ;
}

OOC_INT32 ADT_Dictionary__DictionaryDesc_HashCode(ADT_Dictionary__Dictionary dict) {

  _assert(0u, 127, 15649);
  _failed_function(15581); 
  ;
}

void ADT_Dictionary__DictionaryDesc_Store(ADT_Dictionary__Dictionary dict, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT32 i;

  i0 = (OOC_INT32)dict;
  i1 = (OOC_INT32)w;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 15821))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15805)))), IO_BinaryRider__WriterDesc_WriteNum)),IO_BinaryRider__WriterDesc_WriteNum)((IO_BinaryRider__Writer)i1, i2);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 15842))+4);
  i2 = i2!=0;
  if (!i2) goto l14;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 15883))+8);
  i = 0;
  i3 = 0<i2;
  if (!i3) goto l14;
  i3=0;
l5_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15917))+16);
  i4 = _check_pointer(i4, 15924);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 15924))*12))+4);
  i4 = ADT_Dictionary__IsSet((Object__Object)i4);
  if (!i4) goto l8;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15969))+16);
  i4 = _check_pointer(i4, 15976);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 15976))*12))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15950)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i1, (Object__Object)i4);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16017))+16);
  i4 = _check_pointer(i4, 16024);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 16024))*12))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15998)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i1, (Object__Object)i4);
l8:
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l5_loop;
l14:
  return;
  ;
}

void ADT_Dictionary__DictionaryDesc_Load(ADT_Dictionary__Dictionary dict, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9;
  OOC_INT32 i;
  Object__Object obj;

  i0 = (OOC_INT32)dict;
  ADT_Dictionary__DictionaryDesc_INIT((ADT_Dictionary__Dictionary)i0);
  i1 = (OOC_INT32)r;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16236)))), IO_BinaryRider__ReaderDesc_ReadNum)),IO_BinaryRider__ReaderDesc_ReadNum)((IO_BinaryRider__Reader)i1, (void*)((_check_pointer(i0, 16251))+8));
  i2 = *(OOC_INT32*)((_check_pointer(i0, 16272))+8);
  i2 = i2!=0;
  if (!i2) goto l11;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 16450))+8);
  *(OOC_INT32*)((_check_pointer(i0, 16437))+16) = ((OOC_INT32)RT0__NewObject(_td_ADT_Dictionary__Table.baseTypes[0], i2));
  i2 = *(OOC_INT32*)((_check_pointer(i0, 16483))+8);
  i = 0;
  i3 = 0<i2;
  if (!i3) goto l10;
  i3=0;
l5_loop:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16504)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i1, (void*)(OOC_INT32)&obj);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16536))+16);
  i4 = _check_pointer(i4, 16542);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)obj;
  *(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 16542))*12))+4) = ((OOC_INT32)_type_cast_fast(OOC_INT32, OOC_INT32, i6));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16577)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i1, (void*)(OOC_INT32)&obj);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16609))+16);
  i4 = _check_pointer(i4, 16615);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)obj;
  *(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 16615))*12))+8) = ((OOC_INT32)_type_cast_fast(OOC_INT32, OOC_INT32, i6));
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16656))+16);
  i4 = _check_pointer(i4, 16662);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16678))+16);
  i6 = _check_pointer(i6, 16684);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16678))+16);
  i8 = _check_pointer(i8, 16684);
  i9 = OOC_ARRAY_LENGTH(i8, 0);
  i8 = (OOC_INT32)*(OOC_INT32*)((i8+((_check_index(i3, i9, OOC_UINT32, 16684))*12))+4);
  i6 = (OOC_INT32)*(OOC_INT32*)((i6+((_check_index(i3, i7, OOC_UINT32, 16684))*12))+4);
  i6 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i8, 16691)))), Object__ObjectDesc_HashCode)),Object__ObjectDesc_HashCode)((Object__Object)i6);
  *(OOC_INT32*)(i4+((_check_index(i3, i5, OOC_UINT32, 16662))*12)) = i6;
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l5_loop;
l10:
  i1 = *(OOC_INT32*)((_check_pointer(i0, 16737))+8);
  ADT_Dictionary__DictionaryDesc_Resize((ADT_Dictionary__Dictionary)i0, ((i1*3)>>1));
l11:
  return;
  ;
}

void ADT_Dictionary__IterKeysDesc_INIT(ADT_Dictionary__IterKeys iter, ADT_Dictionary__Dictionary dict) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)iter;
  i1 = (OOC_INT32)dict;
  *(OOC_INT32*)(_check_pointer(i0, 16857)) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 16880))+4) = 0;
  return;
  ;
}

ADT_Dictionary__IterKeys ADT_Dictionary__DictionaryDesc_IterKeys(ADT_Dictionary__Dictionary dict) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)RT0__NewObject(_td__qtd5.baseTypes[0]);
  i1 = (OOC_INT32)dict;
  ADT_Dictionary__IterKeysDesc_INIT((ADT_Dictionary__IterKeys)i0, (ADT_Dictionary__Dictionary)i1);
  return (ADT_Dictionary__IterKeys)i0;
  ;
}

OOC_CHAR8 ADT_Dictionary__IterKeysDesc_Next(ADT_Dictionary__IterKeys iter, Object__Object *key) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  ADT_Dictionary__Dictionary d;
  OOC_INT32 i;

  i0 = (OOC_INT32)iter;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 17551));
  d = (ADT_Dictionary__Dictionary)i1;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 17571))+4);
  i = i2;
  i3 = *(OOC_INT32*)((_check_pointer(i1, 17593))+8);
  i3 = i2!=i3;
  if (i3) goto l3;
  i3=0u;
  goto l5;
l3:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 17610))+16);
  i3 = _check_pointer(i3, 17616);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = (OOC_INT32)*(OOC_INT32*)((i3+((_check_index(i2, i4, OOC_UINT32, 17616))*12))+4);
  i3 = ADT_Dictionary__IsSet((Object__Object)i3);
  i3 = !i3;
  
l5:
  if (!i3) goto l17;
l8_loop:
  i2 = i2+1;
  i = i2;
  i3 = *(OOC_INT32*)((_check_pointer(i1, 17593))+8);
  i3 = i2!=i3;
  if (i3) goto l11;
  i3=0u;
  goto l13;
l11:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 17610))+16);
  i3 = _check_pointer(i3, 17616);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = (OOC_INT32)*(OOC_INT32*)((i3+((_check_index(i2, i4, OOC_UINT32, 17616))*12))+4);
  i3 = ADT_Dictionary__IsSet((Object__Object)i3);
  i3 = !i3;
  
l13:
  if (i3) goto l8_loop;
l17:
  i3 = *(OOC_INT32*)((_check_pointer(i1, 17664))+8);
  i3 = i2==i3;
  if (i3) goto l20;
  *(OOC_INT32*)((_check_pointer(i0, 17736))+4) = (i2+1);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 17763))+16);
  i0 = _check_pointer(i0, 17769);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)((i0+((_check_index(i2, i1, OOC_UINT32, 17769))*12))+4);
  *key = (Object__Object)i0;
  return 1u;
  goto l21;
l20:
  *(OOC_INT32*)((_check_pointer(i0, 17686))+4) = i2;
  return 0u;
l21:
  _failed_function(17455); return 0;
  ;
}

void ADT_Dictionary__IterValuesDesc_INIT(ADT_Dictionary__IterValues iter, ADT_Dictionary__Dictionary dict) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)iter;
  i1 = (OOC_INT32)dict;
  *(OOC_INT32*)(_check_pointer(i0, 17904)) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 17927))+4) = 0;
  return;
  ;
}

ADT_Dictionary__IterValues ADT_Dictionary__DictionaryDesc_IterValues(ADT_Dictionary__Dictionary dict) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)RT0__NewObject(_td__qtd7.baseTypes[0]);
  i1 = (OOC_INT32)dict;
  ADT_Dictionary__IterValuesDesc_INIT((ADT_Dictionary__IterValues)i0, (ADT_Dictionary__Dictionary)i1);
  return (ADT_Dictionary__IterValues)i0;
  ;
}

OOC_CHAR8 ADT_Dictionary__IterValuesDesc_Next(ADT_Dictionary__IterValues iter, Object__Object *value) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  ADT_Dictionary__Dictionary d;
  OOC_INT32 i;

  i0 = (OOC_INT32)iter;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 18616));
  d = (ADT_Dictionary__Dictionary)i1;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 18636))+4);
  i = i2;
  i3 = *(OOC_INT32*)((_check_pointer(i1, 18658))+8);
  i3 = i2!=i3;
  if (i3) goto l3;
  i3=0u;
  goto l5;
l3:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 18675))+16);
  i3 = _check_pointer(i3, 18681);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = (OOC_INT32)*(OOC_INT32*)((i3+((_check_index(i2, i4, OOC_UINT32, 18681))*12))+4);
  i3 = ADT_Dictionary__IsSet((Object__Object)i3);
  i3 = !i3;
  
l5:
  if (!i3) goto l17;
l8_loop:
  i2 = i2+1;
  i = i2;
  i3 = *(OOC_INT32*)((_check_pointer(i1, 18658))+8);
  i3 = i2!=i3;
  if (i3) goto l11;
  i3=0u;
  goto l13;
l11:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 18675))+16);
  i3 = _check_pointer(i3, 18681);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = (OOC_INT32)*(OOC_INT32*)((i3+((_check_index(i2, i4, OOC_UINT32, 18681))*12))+4);
  i3 = ADT_Dictionary__IsSet((Object__Object)i3);
  i3 = !i3;
  
l13:
  if (i3) goto l8_loop;
l17:
  i3 = *(OOC_INT32*)((_check_pointer(i1, 18729))+8);
  i3 = i2==i3;
  if (i3) goto l20;
  *(OOC_INT32*)((_check_pointer(i0, 18801))+4) = (i2+1);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 18830))+16);
  i0 = _check_pointer(i0, 18836);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)((i0+((_check_index(i2, i1, OOC_UINT32, 18836))*12))+8);
  *value = (Object__Object)i0;
  return 1u;
  goto l21;
l20:
  *(OOC_INT32*)((_check_pointer(i0, 18751))+4) = i2;
  return 0u;
l21:
  _failed_function(18518); return 0;
  ;
}

void ADT_Dictionary__DummyDesc_Destroy(ADT_Dictionary__Dummy dummy) {

  return;
  ;
}

void OOC_ADT_Dictionary_init(void) {

  ADT_Dictionary__dummy = (ADT_Dictionary__Dummy)((OOC_INT32)RT0__NewObject(_td_ADT_Dictionary__Dummy.baseTypes[0]));
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary__polys+(_check_index(0, 29, OOC_UINT8, 18973))*4) = 7;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary__polys+(_check_index(1, 29, OOC_UINT8, 18994))*4) = 11;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary__polys+(_check_index(2, 29, OOC_UINT8, 19015))*4) = 19;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary__polys+(_check_index(3, 29, OOC_UINT8, 19037))*4) = 37;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary__polys+(_check_index(4, 29, OOC_UINT8, 19059))*4) = 67;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary__polys+(_check_index(5, 29, OOC_UINT8, 19081))*4) = 131;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary__polys+(_check_index(6, 29, OOC_UINT8, 19104))*4) = 285;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary__polys+(_check_index(7, 29, OOC_UINT8, 19128))*4) = 529;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary__polys+(_check_index(8, 29, OOC_UINT8, 19152))*4) = 1033;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary__polys+(_check_index(9, 29, OOC_UINT8, 19176))*4) = 2053;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary__polys+(_check_index(10, 29, OOC_UINT8, 19200))*4) = 4179;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary__polys+(_check_index(11, 29, OOC_UINT8, 19226))*4) = 8219;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary__polys+(_check_index(12, 29, OOC_UINT8, 19252))*4) = 16427;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary__polys+(_check_index(13, 29, OOC_UINT8, 19279))*4) = 32771;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary__polys+(_check_index(14, 29, OOC_UINT8, 19305))*4) = 65581;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary__polys+(_check_index(15, 29, OOC_UINT8, 19332))*4) = 131081;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary__polys+(_check_index(16, 29, OOC_UINT8, 19359))*4) = 262183;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary__polys+(_check_index(17, 29, OOC_UINT8, 19387))*4) = 524327;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary__polys+(_check_index(18, 29, OOC_UINT8, 19415))*4) = 1048585;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary__polys+(_check_index(19, 29, OOC_UINT8, 19443))*4) = 2097157;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary__polys+(_check_index(20, 29, OOC_UINT8, 19471))*4) = 4194307;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary__polys+(_check_index(21, 29, OOC_UINT8, 19499))*4) = 8388641;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary__polys+(_check_index(22, 29, OOC_UINT8, 19528))*4) = 16777243;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary__polys+(_check_index(23, 29, OOC_UINT8, 19558))*4) = 33554441;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary__polys+(_check_index(24, 29, OOC_UINT8, 19587))*4) = 67108935;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary__polys+(_check_index(25, 29, OOC_UINT8, 19617))*4) = 134217767;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary__polys+(_check_index(26, 29, OOC_UINT8, 19648))*4) = 268435465;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary__polys+(_check_index(27, 29, OOC_UINT8, 19678))*4) = 536870917;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary__polys+(_check_index(28, 29, OOC_UINT8, 19708))*4) = 1073741907;
  return;
  ;
}

void OOC_ADT_Dictionary_destroy(void) {
}

/* --- */
