#include <ADT/Dictionary/AddressKey.d>
#include <__oo2c.h>
#include <setjmp.h>

void ADT_Dictionary_AddressKey__Init(ADT_Dictionary_AddressKey__Dictionary dict) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)dict;
  *(OOC_INT32*)((_check_pointer(i0, 4349))+8) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 4370))+12) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 4391))+16) = (OOC_INT32)0;
  *(OOC_INT32*)(_check_pointer(i0, 4415)) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 4436))+4) = 0;
  return;
  ;
}

ADT_Dictionary_AddressKey__Dictionary ADT_Dictionary_AddressKey__New(void) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)RT0__NewObject(_td_ADT_Dictionary_AddressKey__Dictionary.baseTypes[0]);
  ADT_Dictionary_AddressKey__Init((ADT_Dictionary_AddressKey__Dictionary)i0);
  return (ADT_Dictionary_AddressKey__Dictionary)i0;
  ;
}

void ADT_Dictionary_AddressKey__DictionaryDesc_Destroy(ADT_Dictionary_AddressKey__Dictionary dict) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_INT32 i;

  i0 = (OOC_INT32)dict;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4711))+16);
  i1 = i1!=(OOC_INT32)0;
  if (!i1) goto l11;
  i = 0;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 4755))+8);
  i2 = 0<i1;
  if (!i2) goto l10;
  i2=0;
l5_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4818))+16);
  i3 = _check_pointer(i3, 4825);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)((i3+((_check_index(i2, i4, OOC_UINT32, 4825))*12))+4) = (OOC_INT32)0;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4854))+16);
  i3 = _check_pointer(i3, 4861);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)((i3+((_check_index(i2, i4, OOC_UINT32, 4861))*12))+8) = (OOC_INT32)0;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4892))+16);
  i3 = _check_pointer(i3, 4899);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)(i3+((_check_index(i2, i4, OOC_UINT32, 4899))*12)) = 0;
  i2 = i2+1;
  i = i2;
  i3 = i2<i1;
  if (i3) goto l5_loop;
l10:
  *(OOC_INT32*)((_check_pointer(i0, 4935))+16) = (OOC_INT32)0;
l11:
  return;
  ;
}

static OOC_CHAR8 ADT_Dictionary_AddressKey__IsSet(Object__Object key) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)key;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l3;
  i0=0u;
  goto l4;
l3:
  i1 = (OOC_INT32)ADT_Dictionary_AddressKey__dummy;
  i0 = i0!=i1;
  
l4:
  return i0;
  ;
}

static OOC_INT32 ADT_Dictionary_AddressKey__Lookup(ADT_Dictionary_AddressKey__Dictionary dict, Object__Object key, OOC_INT32 hash) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9;
  ADT_Dictionary_AddressKey__Table t;
  OOC_UINT32 mask;
  OOC_INT32 i;
  OOC_INT32 freeslot;
  OOC_INT32 incr;

  i0 = (OOC_INT32)dict;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6371))+16);
  t = (ADT_Dictionary_AddressKey__Table)i1;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 6408))+8);
  i3 = hash;
  i4 = _type_cast_fast(OOC_UINT32, OOC_INT32, i3);
  i2 = _type_cast_fast(OOC_UINT32, OOC_INT32, (i2-1));
  mask = i2;
  i5 = _type_cast_fast(OOC_INT32, OOC_UINT32, ((~i4)&i2));
  i = i5;
  i6 = _check_pointer(i1, 6481);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((i6+((_check_index(i5, i7, OOC_UINT32, 6481))*12))+4);
  i6 = i6==(OOC_INT32)0;
  if (i6) goto l3;
  i6 = _check_pointer(i1, 6502);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((i6+((_check_index(i5, i7, OOC_UINT32, 6502))*12))+4);
  i7 = (OOC_INT32)key;
  i6 = i6==i7;
  
  goto l4;
l3:
  i6=1u;
l4:
  i7 = (OOC_INT32)key;
  i8 = (OOC_INT32)ADT_Dictionary_AddressKey__dummy;
  if (i6) goto l19;
  i6 = _check_pointer(i1, 6550);
  i9 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((i6+((_check_index(i5, i9, OOC_UINT32, 6550))*12))+4);
  i6 = i6==i8;
  if (i6) goto l17;
  i6 = _check_pointer(i1, 6605);
  i9 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = *(OOC_INT32*)(i6+((_check_index(i5, i9, OOC_UINT32, 6605))*12));
  i6 = i6==i3;
  if (i6) goto l11;
  i6=0u;
  goto l13;
l11:
  i6 = _check_pointer(i1, 6633);
  i9 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((i6+((_check_index(i5, i9, OOC_UINT32, 6633))*12))+4);
  i6 = i7==i6;
  
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
  i4 = *(OOC_INT32*)((_check_pointer(i0, 6835))+8);
  i4 = i4-1;
  incr = i4;
  
l24:
  {register OOC_INT32 h0=i4;i4=i5;i5=h0;}
l25_loop:
  i4 = _type_cast_fast(OOC_INT32, OOC_UINT32, ((_type_cast_fast(OOC_UINT32, OOC_INT32, (i4+i5)))&i2));
  i = i4;
  i6 = _check_pointer(i1, 6928);
  i9 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((i6+((_check_index(i4, i9, OOC_UINT32, 6928))*12))+4);
  i6 = i6==(OOC_INT32)0;
  if (i6) goto l42;
  i6 = _check_pointer(i1, 7065);
  i9 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((i6+((_check_index(i4, i9, OOC_UINT32, 7065))*12))+4);
  i6 = i6==i8;
  if (i6) goto l37;
  i6 = _check_pointer(i1, 7169);
  i9 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = *(OOC_INT32*)(i6+((_check_index(i4, i9, OOC_UINT32, 7169))*12));
  i6 = i6==i3;
  if (i6) goto l32;
  i6=0u;
  goto l34;
l32:
  i6 = _check_pointer(i1, 7197);
  i9 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((i6+((_check_index(i4, i9, OOC_UINT32, 7197))*12))+4);
  i6 = i7==i6;
  
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
  i9 = i6>=0;
  if (i9) goto l45;
  return i4;
  goto l47;
l45:
  return i6;
l47:
  i5 = i5*2;
  incr = i5;
  i6 = *(OOC_INT32*)((_check_pointer(i0, 7284))+8);
  i6 = i5>=i6;
  if (!i6) goto l25_loop;
  i6 = *(OOC_INT32*)((_check_pointer(i0, 7365))+12);
  i5 = _type_cast_fast(OOC_INT32, OOC_UINT32, ((_type_cast_fast(OOC_UINT32, OOC_INT32, i5))^(_type_cast_fast(OOC_UINT32, OOC_INT32, i6))));
  incr = i5;
  
  goto l25_loop;
l53:
  ;
}

static void ADT_Dictionary_AddressKey__Insert(ADT_Dictionary_AddressKey__Dictionary dict, Object__Object key, OOC_INT32 hash, Object__Object value) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT32 i;

  i0 = hash;
  i1 = (OOC_INT32)key;
  i2 = (OOC_INT32)dict;
  i3 = ADT_Dictionary_AddressKey__Lookup((ADT_Dictionary_AddressKey__Dictionary)i2, (Object__Object)i1, i0);
  i = i3;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 7760))+16);
  i4 = _check_pointer(i4, 7767);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 7767))*12))+4);
  i4 = ADT_Dictionary_AddressKey__IsSet((Object__Object)i4);
  if (i4) goto l6;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 7927))+16);
  i4 = _check_pointer(i4, 7934);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 7934))*12))+4);
  i4 = i4==(OOC_INT32)0;
  if (!i4) goto l5;
  i4 = *(OOC_INT32*)(_check_pointer(i2, 7972));
  *(OOC_INT32*)(_check_pointer(i2, 7972)) = (i4+1);
l5:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 8001))+16);
  i4 = _check_pointer(i4, 8008);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  *(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 8008))*12))+4) = i1;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 8035))+16);
  i1 = _check_pointer(i1, 8042);
  i4 = OOC_ARRAY_LENGTH(i1, 0);
  *(OOC_INT32*)(i1+((_check_index(i3, i4, OOC_UINT32, 8042))*12)) = i0;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 8071))+16);
  i0 = _check_pointer(i0, 8078);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  i4 = (OOC_INT32)value;
  *(OOC_INT32*)((i0+((_check_index(i3, i1, OOC_UINT32, 8078))*12))+8) = i4;
  i0 = *(OOC_INT32*)((_check_pointer(i2, 8114))+4);
  *(OOC_INT32*)((_check_pointer(i2, 8114))+4) = (i0+1);
  goto l7;
l6:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 7819))+16);
  i0 = _check_pointer(i0, 7826);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  i2 = (OOC_INT32)value;
  *(OOC_INT32*)((i0+((_check_index(i3, i1, OOC_UINT32, 7826))*12))+8) = i2;
l7:
  return;
  ;
}

static void ADT_Dictionary_AddressKey__Resize(ADT_Dictionary_AddressKey__Dictionary dict, OOC_INT32 minUsed) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9;
  OOC_INT32 oldSize;
  ADT_Dictionary_AddressKey__Table oldTable;
  OOC_INT32 i;
  OOC_INT32 newSize;
  OOC_INT32 newPoly;
  ADT_Dictionary_AddressKey__Table newTable;

  i0 = (OOC_INT32)dict;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 8518))+8);
  oldSize = i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8546))+16);
  oldTable = (ADT_Dictionary_AddressKey__Table)i2;
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
  i3 = *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey__polys+(_check_index(i3, 29, OOC_UINT32, 8699))*4);
  newPoly = i3;
  i5 = (OOC_INT32)RT0__NewObject(_td_ADT_Dictionary_AddressKey__Table.baseTypes[0], i4);
  newTable = (ADT_Dictionary_AddressKey__Table)i5;
  i = 0;
  i6 = 0<i4;
  if (!i6) goto l17;
  i6=0;
l12_loop:
  i7 = _check_pointer(i5, 8838);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  *(OOC_INT32*)((i7+((_check_index(i6, i8, OOC_UINT32, 8838))*12))+4) = (OOC_INT32)0;
  i7 = _check_pointer(i5, 8869);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  *(OOC_INT32*)((i7+((_check_index(i6, i8, OOC_UINT32, 8869))*12))+8) = (OOC_INT32)0;
  i7 = _check_pointer(i5, 8902);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  *(OOC_INT32*)(i7+((_check_index(i6, i8, OOC_UINT32, 8902))*12)) = 0;
  i6 = i6+1;
  i = i6;
  i7 = i6<i4;
  if (i7) goto l12_loop;
l17:
  *(OOC_INT32*)((_check_pointer(i0, 8934))+8) = i4;
  *(OOC_INT32*)((_check_pointer(i0, 8961))+12) = i3;
  *(OOC_INT32*)((_check_pointer(i0, 8988))+16) = i5;
  *(OOC_INT32*)(_check_pointer(i0, 9017)) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 9038))+4) = 0;
  i = 0;
  i3 = 0<i1;
  if (!i3) goto l28;
  i3=0;
l20_loop:
  i4 = _check_pointer(i2, 9111);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 9111))*12))+4);
  i4 = ADT_Dictionary_AddressKey__IsSet((Object__Object)i4);
  if (!i4) goto l23;
  i4 = _check_pointer(i2, 9193);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = _check_pointer(i2, 9174);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i8 = _check_pointer(i2, 9156);
  i9 = OOC_ARRAY_LENGTH(i8, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 9193))*12))+8);
  i5 = (OOC_INT32)*(OOC_INT32*)((i8+((_check_index(i3, i9, OOC_UINT32, 9156))*12))+4);
  i6 = *(OOC_INT32*)(i6+((_check_index(i3, i7, OOC_UINT32, 9174))*12));
  ADT_Dictionary_AddressKey__Insert((ADT_Dictionary_AddressKey__Dictionary)i0, (Object__Object)i5, i6, (Object__Object)i4);
  i4 = _check_pointer(i2, 9222);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  *(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 9222))*12))+4) = (OOC_INT32)0;
  i4 = _check_pointer(i2, 9283);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  *(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 9283))*12))+8) = (OOC_INT32)0;
l23:
  i3 = i3+1;
  i = i3;
  i4 = i3<i1;
  if (i4) goto l20_loop;
l28:
  return;
  ;
}

OOC_CHAR8 ADT_Dictionary_AddressKey__DictionaryDesc_HasKey(ADT_Dictionary_AddressKey__Dictionary dict, Object__Object key) {
  register OOC_INT32 i0,i1,i2;
  OOC_INT32 index;

  i0 = (OOC_INT32)dict;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 9579))+4);
  i1 = i1==0;
  if (i1) goto l3;
  i1 = (OOC_INT32)key;
  i2 = HashCode__Ptr((void*)i1);
  i1 = ADT_Dictionary_AddressKey__Lookup((ADT_Dictionary_AddressKey__Dictionary)i0, (Object__Object)i1, i2);
  index = i1;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9702))+16);
  i0 = _check_pointer(i0, 9709);
  i2 = OOC_ARRAY_LENGTH(i0, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)((i0+((_check_index(i1, i2, OOC_UINT32, 9709))*12))+4);
  i0 = ADT_Dictionary_AddressKey__IsSet((Object__Object)i0);
  return i0;
  goto l4;
l3:
  return 0u;
l4:
  _failed_function(9365); return 0;
  ;
}

OOC_INT32 ADT_Dictionary_AddressKey__DictionaryDesc_Size(ADT_Dictionary_AddressKey__Dictionary dict) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)dict;
  i0 = *(OOC_INT32*)((_check_pointer(i0, 9871))+4);
  return i0;
  ;
}

Object__Object ADT_Dictionary_AddressKey__DictionaryDesc_Get(ADT_Dictionary_AddressKey__Dictionary dict, Object__Object key) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_INT32 i;

  i0 = (OOC_INT32)key;
  _assert((i0!=(OOC_INT32)0), 127, 10229);
  i1 = (OOC_INT32)dict;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 10265))+4);
  _assert((i2!=0), 127, 10253);
  i2 = HashCode__Ptr((void*)i0);
  i0 = ADT_Dictionary_AddressKey__Lookup((ADT_Dictionary_AddressKey__Dictionary)i1, (Object__Object)i0, i2);
  i = i0;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 10349))+16);
  i2 = _check_pointer(i2, 10356);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)((i2+((_check_index(i0, i3, OOC_UINT32, 10356))*12))+4);
  i2 = ADT_Dictionary_AddressKey__IsSet((Object__Object)i2);
  _assert(i2, 127, 10330);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 10383))+16);
  i1 = _check_pointer(i1, 10390);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)((i1+((_check_index(i0, i2, OOC_UINT32, 10390))*12))+8);
  return (Object__Object)i0;
  ;
}

void ADT_Dictionary_AddressKey__DictionaryDesc_Set(ADT_Dictionary_AddressKey__Dictionary dict, Object__Object key, Object__Object value) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)key;
  _assert((i0!=(OOC_INT32)0), 127, 10803);
  i1 = (OOC_INT32)dict;
  i2 = *(OOC_INT32*)(_check_pointer(i1, 10835));
  i3 = *(OOC_INT32*)((_check_pointer(i1, 10851))+8);
  i2 = (i2*3)>=(i3*2);
  if (!i2) goto l4;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 10890))+4);
  ADT_Dictionary_AddressKey__Resize((ADT_Dictionary_AddressKey__Dictionary)i1, (i2*2));
l4:
  i2 = HashCode__Ptr((void*)i0);
  i3 = (OOC_INT32)value;
  ADT_Dictionary_AddressKey__Insert((ADT_Dictionary_AddressKey__Dictionary)i1, (Object__Object)i0, i2, (Object__Object)i3);
  return;
  ;
}

ADT_Dictionary_AddressKey__Dictionary ADT_Dictionary_AddressKey__DictionaryDesc_Copy(ADT_Dictionary_AddressKey__Dictionary dict) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9;
  ADT_Dictionary_AddressKey__Dictionary copy;
  OOC_INT32 i;

  i0 = (OOC_INT32)ADT_Dictionary_AddressKey__New();
  copy = (ADT_Dictionary_AddressKey__Dictionary)i0;
  i1 = (OOC_INT32)dict;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 11224))+4);
  i2 = i2>0;
  if (!i2) goto l14;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 11266))+4);
  ADT_Dictionary_AddressKey__Resize((ADT_Dictionary_AddressKey__Dictionary)i0, ((i2*3)>>1));
  i2 = *(OOC_INT32*)((_check_pointer(i1, 11308))+8);
  i = 0;
  i3 = 0<i2;
  if (!i3) goto l14;
  i3=0;
l5_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11342))+16);
  i4 = _check_pointer(i4, 11349);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 11349))*12))+4);
  i4 = ADT_Dictionary_AddressKey__IsSet((Object__Object)i4);
  if (!i4) goto l8;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11453))+16);
  i4 = _check_pointer(i4, 11460);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11413))+16);
  i6 = _check_pointer(i6, 11420);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11392))+16);
  i8 = _check_pointer(i8, 11399);
  i9 = OOC_ARRAY_LENGTH(i8, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 11460))*12))+8);
  i5 = (OOC_INT32)*(OOC_INT32*)((i8+((_check_index(i3, i9, OOC_UINT32, 11399))*12))+4);
  i6 = *(OOC_INT32*)(i6+((_check_index(i3, i7, OOC_UINT32, 11420))*12));
  ADT_Dictionary_AddressKey__Insert((ADT_Dictionary_AddressKey__Dictionary)i0, (Object__Object)i5, i6, (Object__Object)i4);
l8:
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l5_loop;
l14:
  return (ADT_Dictionary_AddressKey__Dictionary)i0;
  ;
}

void ADT_Dictionary_AddressKey__DictionaryDesc_Delete(ADT_Dictionary_AddressKey__Dictionary dict, Object__Object key) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_INT32 i;

  i0 = (OOC_INT32)key;
  _assert((i0!=(OOC_INT32)0), 127, 11863);
  i1 = (OOC_INT32)dict;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 11899))+4);
  _assert((i2!=0), 127, 11887);
  i2 = HashCode__Ptr((void*)i0);
  i0 = ADT_Dictionary_AddressKey__Lookup((ADT_Dictionary_AddressKey__Dictionary)i1, (Object__Object)i0, i2);
  i = i0;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11983))+16);
  i2 = _check_pointer(i2, 11990);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)((i2+((_check_index(i0, i3, OOC_UINT32, 11990))*12))+4);
  i2 = ADT_Dictionary_AddressKey__IsSet((Object__Object)i2);
  _assert(i2, 127, 11964);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12010))+16);
  i2 = _check_pointer(i2, 12017);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i4 = (OOC_INT32)ADT_Dictionary_AddressKey__dummy;
  *(OOC_INT32*)((i2+((_check_index(i0, i3, OOC_UINT32, 12017))*12))+4) = i4;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12090))+16);
  i2 = _check_pointer(i2, 12097);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  *(OOC_INT32*)((i2+((_check_index(i0, i3, OOC_UINT32, 12097))*12))+8) = (OOC_INT32)0;
  i0 = *(OOC_INT32*)((_check_pointer(i1, 12129))+4);
  *(OOC_INT32*)((_check_pointer(i1, 12129))+4) = (i0-1);
  return;
  ;
}

void ADT_Dictionary_AddressKey__DictionaryDesc_Clear(ADT_Dictionary_AddressKey__Dictionary dict) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_INT32 i;

  i0 = (OOC_INT32)dict;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12291))+16);
  i1 = i1!=(OOC_INT32)0;
  if (!i1) goto l11;
  i = 0;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 12335))+8);
  i2 = 0<i1;
  if (!i2) goto l10;
  i2=0;
l5_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12398))+16);
  i3 = _check_pointer(i3, 12405);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)((i3+((_check_index(i2, i4, OOC_UINT32, 12405))*12))+4) = (OOC_INT32)0;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12434))+16);
  i3 = _check_pointer(i3, 12441);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)((i3+((_check_index(i2, i4, OOC_UINT32, 12441))*12))+8) = (OOC_INT32)0;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12472))+16);
  i3 = _check_pointer(i3, 12479);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)(i3+((_check_index(i2, i4, OOC_UINT32, 12479))*12)) = 0;
  i2 = i2+1;
  i = i2;
  i3 = i2<i1;
  if (i3) goto l5_loop;
l10:
  ADT_Dictionary_AddressKey__Init((ADT_Dictionary_AddressKey__Dictionary)i0);
l11:
  return;
  ;
}

Object__ObjectArrayPtr ADT_Dictionary_AddressKey__DictionaryDesc_Keys(ADT_Dictionary_AddressKey__Dictionary dict) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
  Object__ObjectArrayPtr list;
  OOC_INT32 j;
  OOC_INT32 i;

  i0 = (OOC_INT32)dict;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 12806))+4);
  i1 = (OOC_INT32)RT0__NewObject(_td_Object__ObjectArrayPtr.baseTypes[0], i1);
  list = (Object__ObjectArrayPtr)i1;
  j = 0;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 12849))+8);
  i = 0;
  i3 = 0<i2;
  if (i3) goto l3;
  i2=0;
  goto l13;
l3:
  i3=0;i4=0;
l4_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12881))+16);
  i5 = _check_pointer(i5, 12888);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)((i5+((_check_index(i3, i6, OOC_UINT32, 12888))*12))+4);
  i5 = ADT_Dictionary_AddressKey__IsSet((Object__Object)i5);
  if (!i5) goto l8;
  i5 = _check_pointer(i1, 12915);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12926))+16);
  i7 = _check_pointer(i7, 12933);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)((i7+((_check_index(i3, i8, OOC_UINT32, 12933))*12))+4);
  *(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 12915))*4) = i7;
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
  i0 = *(OOC_INT32*)((_check_pointer(i0, 12998))+4);
  _assert((i2==i0), 127, 12982);
  return (Object__ObjectArrayPtr)i1;
  ;
}

Object__ObjectArrayPtr ADT_Dictionary_AddressKey__DictionaryDesc_Values(ADT_Dictionary_AddressKey__Dictionary dict) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
  Object__ObjectArrayPtr list;
  OOC_INT32 j;
  OOC_INT32 i;

  i0 = (OOC_INT32)dict;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 13302))+4);
  i1 = (OOC_INT32)RT0__NewObject(_td_Object__ObjectArrayPtr.baseTypes[0], i1);
  list = (Object__ObjectArrayPtr)i1;
  j = 0;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 13345))+8);
  i = 0;
  i3 = 0<i2;
  if (i3) goto l3;
  i2=0;
  goto l13;
l3:
  i3=0;i4=0;
l4_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13377))+16);
  i5 = _check_pointer(i5, 13384);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)((i5+((_check_index(i3, i6, OOC_UINT32, 13384))*12))+4);
  i5 = ADT_Dictionary_AddressKey__IsSet((Object__Object)i5);
  if (!i5) goto l8;
  i5 = _check_pointer(i1, 13411);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13422))+16);
  i7 = _check_pointer(i7, 13429);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)((i7+((_check_index(i3, i8, OOC_UINT32, 13429))*12))+8);
  *(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 13411))*4) = i7;
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
  i0 = *(OOC_INT32*)((_check_pointer(i0, 13496))+4);
  _assert((i2==i0), 127, 13480);
  return (Object__ObjectArrayPtr)i1;
  ;
}

OOC_CHAR8 ADT_Dictionary_AddressKey__DictionaryDesc_Equals(ADT_Dictionary_AddressKey__Dictionary dict, Object__Object obj) {

  _assert(0u, 127, 13643);
  _failed_function(13566); 
  ;
}

OOC_INT32 ADT_Dictionary_AddressKey__DictionaryDesc_HashCode(ADT_Dictionary_AddressKey__Dictionary dict) {

  _assert(0u, 127, 13769);
  _failed_function(13708); 
  ;
}

void ADT_Dictionary_AddressKey__DictionaryDesc_Store(ADT_Dictionary_AddressKey__Dictionary dict, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT32 i;

  i0 = (OOC_INT32)dict;
  i1 = (OOC_INT32)w;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 13932))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 13916)))), IO_BinaryRider__WriterDesc_WriteNum)),IO_BinaryRider__WriterDesc_WriteNum)((IO_BinaryRider__Writer)i1, i2);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 13953))+4);
  i2 = i2!=0;
  if (!i2) goto l14;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 13994))+8);
  i = 0;
  i3 = 0<i2;
  if (!i3) goto l14;
  i3=0;
l5_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14028))+16);
  i4 = _check_pointer(i4, 14035);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 14035))*12))+4);
  i4 = ADT_Dictionary_AddressKey__IsSet((Object__Object)i4);
  if (!i4) goto l8;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14080))+16);
  i4 = _check_pointer(i4, 14087);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 14087))*12))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14061)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i1, (Object__Object)i4);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14128))+16);
  i4 = _check_pointer(i4, 14135);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 14135))*12))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14109)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i1, (Object__Object)i4);
l8:
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l5_loop;
l14:
  return;
  ;
}

void ADT_Dictionary_AddressKey__DictionaryDesc_Load(ADT_Dictionary_AddressKey__Dictionary dict, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
  OOC_INT32 i;
  Object__Object obj;

  i0 = (OOC_INT32)dict;
  ADT_Dictionary_AddressKey__Init((ADT_Dictionary_AddressKey__Dictionary)i0);
  i1 = (OOC_INT32)r;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14341)))), IO_BinaryRider__ReaderDesc_ReadNum)),IO_BinaryRider__ReaderDesc_ReadNum)((IO_BinaryRider__Reader)i1, (void*)((_check_pointer(i0, 14356))+8));
  i2 = *(OOC_INT32*)((_check_pointer(i0, 14377))+8);
  i2 = i2!=0;
  if (!i2) goto l11;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 14555))+8);
  *(OOC_INT32*)((_check_pointer(i0, 14542))+16) = ((OOC_INT32)RT0__NewObject(_td_ADT_Dictionary_AddressKey__Table.baseTypes[0], i2));
  i = 0;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 14588))+8);
  i3 = 0<i2;
  if (!i3) goto l10;
  i3=0;
l5_loop:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14609)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i1, (void*)(OOC_INT32)&obj);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14641))+16);
  i4 = _check_pointer(i4, 14648);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)obj;
  *(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 14648))*12))+4) = i6;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14674)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i1, (void*)(OOC_INT32)&obj);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14706))+16);
  i4 = _check_pointer(i4, 14713);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)obj;
  *(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 14713))*12))+8) = i6;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14744))+16);
  i4 = _check_pointer(i4, 14751);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14781))+16);
  i6 = _check_pointer(i6, 14788);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((i6+((_check_index(i3, i7, OOC_UINT32, 14788))*12))+4);
  i6 = HashCode__Ptr((void*)i6);
  *(OOC_INT32*)(i4+((_check_index(i3, i5, OOC_UINT32, 14751))*12)) = i6;
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l5_loop;
l10:
  i1 = *(OOC_INT32*)((_check_pointer(i0, 14834))+8);
  ADT_Dictionary_AddressKey__Resize((ADT_Dictionary_AddressKey__Dictionary)i0, ((i1*3)>>1));
l11:
  return;
  ;
}

void ADT_Dictionary_AddressKey__DummyDesc_Destroy(ADT_Dictionary_AddressKey__Dummy dummy) {

  return;
  ;
}

void OOC_ADT_Dictionary_AddressKey_init(void) {

  ADT_Dictionary_AddressKey__dummy = (ADT_Dictionary_AddressKey__Dummy)((OOC_INT32)RT0__NewObject(_td_ADT_Dictionary_AddressKey__Dummy.baseTypes[0]));
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey__polys+(_check_index(0, 29, OOC_UINT8, 14955))*4) = 7;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey__polys+(_check_index(1, 29, OOC_UINT8, 14976))*4) = 11;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey__polys+(_check_index(2, 29, OOC_UINT8, 14997))*4) = 19;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey__polys+(_check_index(3, 29, OOC_UINT8, 15019))*4) = 37;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey__polys+(_check_index(4, 29, OOC_UINT8, 15041))*4) = 67;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey__polys+(_check_index(5, 29, OOC_UINT8, 15063))*4) = 131;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey__polys+(_check_index(6, 29, OOC_UINT8, 15086))*4) = 285;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey__polys+(_check_index(7, 29, OOC_UINT8, 15110))*4) = 529;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey__polys+(_check_index(8, 29, OOC_UINT8, 15134))*4) = 1033;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey__polys+(_check_index(9, 29, OOC_UINT8, 15158))*4) = 2053;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey__polys+(_check_index(10, 29, OOC_UINT8, 15182))*4) = 4179;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey__polys+(_check_index(11, 29, OOC_UINT8, 15208))*4) = 8219;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey__polys+(_check_index(12, 29, OOC_UINT8, 15234))*4) = 16427;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey__polys+(_check_index(13, 29, OOC_UINT8, 15261))*4) = 32771;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey__polys+(_check_index(14, 29, OOC_UINT8, 15287))*4) = 65581;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey__polys+(_check_index(15, 29, OOC_UINT8, 15314))*4) = 131081;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey__polys+(_check_index(16, 29, OOC_UINT8, 15341))*4) = 262183;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey__polys+(_check_index(17, 29, OOC_UINT8, 15369))*4) = 524327;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey__polys+(_check_index(18, 29, OOC_UINT8, 15397))*4) = 1048585;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey__polys+(_check_index(19, 29, OOC_UINT8, 15425))*4) = 2097157;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey__polys+(_check_index(20, 29, OOC_UINT8, 15453))*4) = 4194307;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey__polys+(_check_index(21, 29, OOC_UINT8, 15481))*4) = 8388641;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey__polys+(_check_index(22, 29, OOC_UINT8, 15510))*4) = 16777243;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey__polys+(_check_index(23, 29, OOC_UINT8, 15540))*4) = 33554441;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey__polys+(_check_index(24, 29, OOC_UINT8, 15569))*4) = 67108935;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey__polys+(_check_index(25, 29, OOC_UINT8, 15599))*4) = 134217767;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey__polys+(_check_index(26, 29, OOC_UINT8, 15630))*4) = 268435465;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey__polys+(_check_index(27, 29, OOC_UINT8, 15660))*4) = 536870917;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey__polys+(_check_index(28, 29, OOC_UINT8, 15690))*4) = 1073741907;
  return;
  ;
}

/* --- */
