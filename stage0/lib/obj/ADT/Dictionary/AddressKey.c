#include <ADT/Dictionary/AddressKey.d>
#include <__oo2c.h>
#include <setjmp.h>

void ADT_Dictionary_AddressKey__Init(ADT_Dictionary_AddressKey__Dictionary dict) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)dict;
  *(OOC_INT32*)((_check_pointer(i0, 4355))+8) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 4376))+12) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 4397))+16) = (OOC_INT32)0;
  *(OOC_INT32*)(_check_pointer(i0, 4421)) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 4442))+4) = 0;
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
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4717))+16);
  i1 = i1!=(OOC_INT32)0;
  if (!i1) goto l11;
  i = 0;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 4761))+8);
  i2 = 0<i1;
  if (!i2) goto l10;
  i2=0;
l5_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4824))+16);
  i3 = _check_pointer(i3, 4831);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)((i3+((_check_index(i2, i4, OOC_UINT32, 4831))*12))+4) = (OOC_INT32)0;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4860))+16);
  i3 = _check_pointer(i3, 4867);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)((i3+((_check_index(i2, i4, OOC_UINT32, 4867))*12))+8) = (OOC_INT32)0;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4898))+16);
  i3 = _check_pointer(i3, 4905);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)(i3+((_check_index(i2, i4, OOC_UINT32, 4905))*12)) = 0;
  i2 = i2+1;
  i = i2;
  i3 = i2<i1;
  if (i3) goto l5_loop;
l10:
  *(OOC_INT32*)((_check_pointer(i0, 4941))+16) = (OOC_INT32)0;
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

static OOC_INT32 ADT_Dictionary_AddressKey__InternalLookup(ADT_Dictionary_AddressKey__Dictionary dict, Object__Object key, OOC_INT32 hash) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9;
  ADT_Dictionary_AddressKey__Table t;
  OOC_UINT32 mask;
  OOC_INT32 i;
  OOC_INT32 freeslot;
  OOC_INT32 incr;

  i0 = (OOC_INT32)dict;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6385))+16);
  t = (ADT_Dictionary_AddressKey__Table)i1;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 6422))+8);
  i3 = hash;
  i4 = _type_cast_fast(OOC_UINT32, OOC_INT32, i3);
  i2 = _type_cast_fast(OOC_UINT32, OOC_INT32, (i2-1));
  mask = i2;
  i5 = _type_cast_fast(OOC_INT32, OOC_UINT32, ((~i4)&i2));
  i = i5;
  i6 = _check_pointer(i1, 6495);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((i6+((_check_index(i5, i7, OOC_UINT32, 6495))*12))+4);
  i6 = i6==(OOC_INT32)0;
  if (i6) goto l3;
  i6 = _check_pointer(i1, 6516);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((i6+((_check_index(i5, i7, OOC_UINT32, 6516))*12))+4);
  i7 = (OOC_INT32)key;
  i6 = i6==i7;
  
  goto l4;
l3:
  i6=1u;
l4:
  i7 = (OOC_INT32)key;
  i8 = (OOC_INT32)ADT_Dictionary_AddressKey__dummy;
  if (i6) goto l19;
  i6 = _check_pointer(i1, 6564);
  i9 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((i6+((_check_index(i5, i9, OOC_UINT32, 6564))*12))+4);
  i6 = i6==i8;
  if (i6) goto l17;
  i6 = _check_pointer(i1, 6619);
  i9 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = *(OOC_INT32*)(i6+((_check_index(i5, i9, OOC_UINT32, 6619))*12));
  i6 = i6==i3;
  if (i6) goto l11;
  i6=0u;
  goto l13;
l11:
  i6 = _check_pointer(i1, 6647);
  i9 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((i6+((_check_index(i5, i9, OOC_UINT32, 6647))*12))+4);
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
  i4 = _type_cast_fast(OOC_INT32, OOC_UINT32, ((i4^(_type_cast_fast(OOC_UINT32, OOC_INT32, (_lsh(OOC_INT32, OOC_UINT32, i3, (-3))))))&i2));
  incr = i4;
  i6 = i4==0;
  if (!i6) goto l24;
  i4 = *(OOC_INT32*)((_check_pointer(i0, 6849))+8);
  i4 = i4-1;
  incr = i4;
  
l24:
  {register OOC_INT32 h0=i4;i4=i5;i5=h0;}
l25_loop:
  i4 = _type_cast_fast(OOC_INT32, OOC_UINT32, ((_type_cast_fast(OOC_UINT32, OOC_INT32, (i4+i5)))&i2));
  i = i4;
  i6 = _check_pointer(i1, 6942);
  i9 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((i6+((_check_index(i4, i9, OOC_UINT32, 6942))*12))+4);
  i6 = i6==(OOC_INT32)0;
  if (i6) goto l42;
  i6 = _check_pointer(i1, 7079);
  i9 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((i6+((_check_index(i4, i9, OOC_UINT32, 7079))*12))+4);
  i6 = i6==i8;
  if (i6) goto l37;
  i6 = _check_pointer(i1, 7183);
  i9 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = *(OOC_INT32*)(i6+((_check_index(i4, i9, OOC_UINT32, 7183))*12));
  i6 = i6==i3;
  if (i6) goto l32;
  i6=0u;
  goto l34;
l32:
  i6 = _check_pointer(i1, 7211);
  i9 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((i6+((_check_index(i4, i9, OOC_UINT32, 7211))*12))+4);
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
  i6 = *(OOC_INT32*)((_check_pointer(i0, 7298))+8);
  i6 = i5>=i6;
  if (!i6) goto l25_loop;
  i6 = *(OOC_INT32*)((_check_pointer(i0, 7379))+12);
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
  i3 = ADT_Dictionary_AddressKey__InternalLookup((ADT_Dictionary_AddressKey__Dictionary)i2, (Object__Object)i1, i0);
  i = i3;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 7790))+16);
  i4 = _check_pointer(i4, 7797);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 7797))*12))+4);
  i4 = ADT_Dictionary_AddressKey__IsSet((Object__Object)i4);
  if (i4) goto l6;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 7957))+16);
  i4 = _check_pointer(i4, 7964);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 7964))*12))+4);
  i4 = i4==(OOC_INT32)0;
  if (!i4) goto l5;
  i4 = *(OOC_INT32*)(_check_pointer(i2, 8002));
  *(OOC_INT32*)(_check_pointer(i2, 8002)) = (i4+1);
l5:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 8031))+16);
  i4 = _check_pointer(i4, 8038);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  *(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 8038))*12))+4) = i1;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 8065))+16);
  i1 = _check_pointer(i1, 8072);
  i4 = OOC_ARRAY_LENGTH(i1, 0);
  *(OOC_INT32*)(i1+((_check_index(i3, i4, OOC_UINT32, 8072))*12)) = i0;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 8101))+16);
  i0 = _check_pointer(i0, 8108);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  i4 = (OOC_INT32)value;
  *(OOC_INT32*)((i0+((_check_index(i3, i1, OOC_UINT32, 8108))*12))+8) = i4;
  i0 = *(OOC_INT32*)((_check_pointer(i2, 8144))+4);
  *(OOC_INT32*)((_check_pointer(i2, 8144))+4) = (i0+1);
  goto l7;
l6:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 7849))+16);
  i0 = _check_pointer(i0, 7856);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  i2 = (OOC_INT32)value;
  *(OOC_INT32*)((i0+((_check_index(i3, i1, OOC_UINT32, 7856))*12))+8) = i2;
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
  i1 = *(OOC_INT32*)((_check_pointer(i0, 8548))+8);
  oldSize = i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8576))+16);
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
  i3 = *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey__polys+(_check_index(i3, 29, OOC_UINT32, 8729))*4);
  newPoly = i3;
  i5 = (OOC_INT32)RT0__NewObject(_td_ADT_Dictionary_AddressKey__Table.baseTypes[0], i4);
  newTable = (ADT_Dictionary_AddressKey__Table)i5;
  i = 0;
  i6 = 0<i4;
  if (!i6) goto l17;
  i6=0;
l12_loop:
  i7 = _check_pointer(i5, 8868);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  *(OOC_INT32*)((i7+((_check_index(i6, i8, OOC_UINT32, 8868))*12))+4) = (OOC_INT32)0;
  i7 = _check_pointer(i5, 8899);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  *(OOC_INT32*)((i7+((_check_index(i6, i8, OOC_UINT32, 8899))*12))+8) = (OOC_INT32)0;
  i7 = _check_pointer(i5, 8932);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  *(OOC_INT32*)(i7+((_check_index(i6, i8, OOC_UINT32, 8932))*12)) = 0;
  i6 = i6+1;
  i = i6;
  i7 = i6<i4;
  if (i7) goto l12_loop;
l17:
  *(OOC_INT32*)((_check_pointer(i0, 8964))+8) = i4;
  *(OOC_INT32*)((_check_pointer(i0, 8991))+12) = i3;
  *(OOC_INT32*)((_check_pointer(i0, 9018))+16) = i5;
  *(OOC_INT32*)(_check_pointer(i0, 9047)) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 9068))+4) = 0;
  i = 0;
  i3 = 0<i1;
  if (!i3) goto l28;
  i3=0;
l20_loop:
  i4 = _check_pointer(i2, 9141);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 9141))*12))+4);
  i4 = ADT_Dictionary_AddressKey__IsSet((Object__Object)i4);
  if (!i4) goto l23;
  i4 = _check_pointer(i2, 9223);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = _check_pointer(i2, 9204);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i8 = _check_pointer(i2, 9186);
  i9 = OOC_ARRAY_LENGTH(i8, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 9223))*12))+8);
  i5 = (OOC_INT32)*(OOC_INT32*)((i8+((_check_index(i3, i9, OOC_UINT32, 9186))*12))+4);
  i6 = *(OOC_INT32*)(i6+((_check_index(i3, i7, OOC_UINT32, 9204))*12));
  ADT_Dictionary_AddressKey__Insert((ADT_Dictionary_AddressKey__Dictionary)i0, (Object__Object)i5, i6, (Object__Object)i4);
  i4 = _check_pointer(i2, 9252);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  *(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 9252))*12))+4) = (OOC_INT32)0;
  i4 = _check_pointer(i2, 9313);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  *(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 9313))*12))+8) = (OOC_INT32)0;
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
  i1 = *(OOC_INT32*)((_check_pointer(i0, 9609))+4);
  i1 = i1==0;
  if (i1) goto l3;
  i1 = (OOC_INT32)key;
  i2 = HashCode__Ptr((void*)i1);
  i1 = ADT_Dictionary_AddressKey__InternalLookup((ADT_Dictionary_AddressKey__Dictionary)i0, (Object__Object)i1, i2);
  index = i1;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9740))+16);
  i0 = _check_pointer(i0, 9747);
  i2 = OOC_ARRAY_LENGTH(i0, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)((i0+((_check_index(i1, i2, OOC_UINT32, 9747))*12))+4);
  i0 = ADT_Dictionary_AddressKey__IsSet((Object__Object)i0);
  return i0;
  goto l4;
l3:
  return 0u;
l4:
  _failed_function(9395); return 0;
  ;
}

OOC_INT32 ADT_Dictionary_AddressKey__DictionaryDesc_Size(ADT_Dictionary_AddressKey__Dictionary dict) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)dict;
  i0 = *(OOC_INT32*)((_check_pointer(i0, 9909))+4);
  return i0;
  ;
}

Object__Object ADT_Dictionary_AddressKey__DictionaryDesc_Get(ADT_Dictionary_AddressKey__Dictionary dict, Object__Object key) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_INT32 i;

  i0 = (OOC_INT32)key;
  _assert((i0!=(OOC_INT32)0), 127, 10267);
  i1 = (OOC_INT32)dict;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 10303))+4);
  _assert((i2!=0), 127, 10291);
  i2 = HashCode__Ptr((void*)i0);
  i0 = ADT_Dictionary_AddressKey__InternalLookup((ADT_Dictionary_AddressKey__Dictionary)i1, (Object__Object)i0, i2);
  i = i0;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 10395))+16);
  i2 = _check_pointer(i2, 10402);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)((i2+((_check_index(i0, i3, OOC_UINT32, 10402))*12))+4);
  i2 = ADT_Dictionary_AddressKey__IsSet((Object__Object)i2);
  _assert(i2, 127, 10376);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 10429))+16);
  i1 = _check_pointer(i1, 10436);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)((i1+((_check_index(i0, i2, OOC_UINT32, 10436))*12))+8);
  return (Object__Object)i0;
  ;
}

OOC_CHAR8 ADT_Dictionary_AddressKey__DictionaryDesc_Lookup(ADT_Dictionary_AddressKey__Dictionary dict, Object__Object key, Object__Object *value) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_INT32 i;

  i0 = (OOC_INT32)key;
  _assert((i0!=(OOC_INT32)0), 127, 10866);
  i1 = (OOC_INT32)dict;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 10897))+4);
  i2 = i2==0;
  if (i2) goto l7;
  i2 = HashCode__Ptr((void*)i0);
  i0 = ADT_Dictionary_AddressKey__InternalLookup((ADT_Dictionary_AddressKey__Dictionary)i1, (Object__Object)i0, i2);
  i = i0;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11019))+16);
  i2 = _check_pointer(i2, 11026);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)((i2+((_check_index(i0, i3, OOC_UINT32, 11026))*12))+4);
  i2 = ADT_Dictionary_AddressKey__IsSet((Object__Object)i2);
  if (i2) goto l5;
  return 0u;
  goto l8;
l5:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11062))+16);
  i1 = _check_pointer(i1, 11069);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)((i1+((_check_index(i0, i2, OOC_UINT32, 11069))*12))+8);
  *value = (Object__Object)i0;
  return 1u;
  goto l8;
l7:
  return 0u;
l8:
  _failed_function(10488); return 0;
  ;
}

void ADT_Dictionary_AddressKey__DictionaryDesc_Set(ADT_Dictionary_AddressKey__Dictionary dict, Object__Object key, Object__Object value) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)key;
  _assert((i0!=(OOC_INT32)0), 127, 11556);
  i1 = (OOC_INT32)dict;
  i2 = *(OOC_INT32*)(_check_pointer(i1, 11588));
  i3 = *(OOC_INT32*)((_check_pointer(i1, 11604))+8);
  i2 = (i2*3)>=(i3*2);
  if (!i2) goto l4;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 11643))+4);
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
  i2 = *(OOC_INT32*)((_check_pointer(i1, 11977))+4);
  i2 = i2>0;
  if (!i2) goto l14;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 12019))+4);
  ADT_Dictionary_AddressKey__Resize((ADT_Dictionary_AddressKey__Dictionary)i0, ((i2*3)>>1));
  i2 = *(OOC_INT32*)((_check_pointer(i1, 12061))+8);
  i = 0;
  i3 = 0<i2;
  if (!i3) goto l14;
  i3=0;
l5_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12095))+16);
  i4 = _check_pointer(i4, 12102);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 12102))*12))+4);
  i4 = ADT_Dictionary_AddressKey__IsSet((Object__Object)i4);
  if (!i4) goto l8;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12206))+16);
  i4 = _check_pointer(i4, 12213);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12166))+16);
  i6 = _check_pointer(i6, 12173);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12145))+16);
  i8 = _check_pointer(i8, 12152);
  i9 = OOC_ARRAY_LENGTH(i8, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 12213))*12))+8);
  i5 = (OOC_INT32)*(OOC_INT32*)((i8+((_check_index(i3, i9, OOC_UINT32, 12152))*12))+4);
  i6 = *(OOC_INT32*)(i6+((_check_index(i3, i7, OOC_UINT32, 12173))*12));
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
  _assert((i0!=(OOC_INT32)0), 127, 12616);
  i1 = (OOC_INT32)dict;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 12652))+4);
  _assert((i2!=0), 127, 12640);
  i2 = HashCode__Ptr((void*)i0);
  i0 = ADT_Dictionary_AddressKey__InternalLookup((ADT_Dictionary_AddressKey__Dictionary)i1, (Object__Object)i0, i2);
  i = i0;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12744))+16);
  i2 = _check_pointer(i2, 12751);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)((i2+((_check_index(i0, i3, OOC_UINT32, 12751))*12))+4);
  i2 = ADT_Dictionary_AddressKey__IsSet((Object__Object)i2);
  _assert(i2, 127, 12725);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12771))+16);
  i2 = _check_pointer(i2, 12778);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i4 = (OOC_INT32)ADT_Dictionary_AddressKey__dummy;
  *(OOC_INT32*)((i2+((_check_index(i0, i3, OOC_UINT32, 12778))*12))+4) = i4;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12851))+16);
  i2 = _check_pointer(i2, 12858);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  *(OOC_INT32*)((i2+((_check_index(i0, i3, OOC_UINT32, 12858))*12))+8) = (OOC_INT32)0;
  i0 = *(OOC_INT32*)((_check_pointer(i1, 12890))+4);
  *(OOC_INT32*)((_check_pointer(i1, 12890))+4) = (i0-1);
  return;
  ;
}

void ADT_Dictionary_AddressKey__DictionaryDesc_Clear(ADT_Dictionary_AddressKey__Dictionary dict) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_INT32 i;

  i0 = (OOC_INT32)dict;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13052))+16);
  i1 = i1!=(OOC_INT32)0;
  if (!i1) goto l11;
  i = 0;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 13096))+8);
  i2 = 0<i1;
  if (!i2) goto l10;
  i2=0;
l5_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13159))+16);
  i3 = _check_pointer(i3, 13166);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)((i3+((_check_index(i2, i4, OOC_UINT32, 13166))*12))+4) = (OOC_INT32)0;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13195))+16);
  i3 = _check_pointer(i3, 13202);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)((i3+((_check_index(i2, i4, OOC_UINT32, 13202))*12))+8) = (OOC_INT32)0;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13233))+16);
  i3 = _check_pointer(i3, 13240);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)(i3+((_check_index(i2, i4, OOC_UINT32, 13240))*12)) = 0;
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
  i1 = *(OOC_INT32*)((_check_pointer(i0, 13567))+4);
  i1 = (OOC_INT32)RT0__NewObject(_td_Object__ObjectArrayPtr.baseTypes[0], i1);
  list = (Object__ObjectArrayPtr)i1;
  j = 0;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 13610))+8);
  i = 0;
  i3 = 0<i2;
  if (i3) goto l3;
  i2=0;
  goto l13;
l3:
  i3=0;i4=0;
l4_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13642))+16);
  i5 = _check_pointer(i5, 13649);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)((i5+((_check_index(i3, i6, OOC_UINT32, 13649))*12))+4);
  i5 = ADT_Dictionary_AddressKey__IsSet((Object__Object)i5);
  if (!i5) goto l8;
  i5 = _check_pointer(i1, 13676);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13687))+16);
  i7 = _check_pointer(i7, 13694);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)((i7+((_check_index(i3, i8, OOC_UINT32, 13694))*12))+4);
  *(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 13676))*4) = i7;
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
  i0 = *(OOC_INT32*)((_check_pointer(i0, 13759))+4);
  _assert((i2==i0), 127, 13743);
  return (Object__ObjectArrayPtr)i1;
  ;
}

Object__ObjectArrayPtr ADT_Dictionary_AddressKey__DictionaryDesc_Values(ADT_Dictionary_AddressKey__Dictionary dict) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
  Object__ObjectArrayPtr list;
  OOC_INT32 j;
  OOC_INT32 i;

  i0 = (OOC_INT32)dict;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 14063))+4);
  i1 = (OOC_INT32)RT0__NewObject(_td_Object__ObjectArrayPtr.baseTypes[0], i1);
  list = (Object__ObjectArrayPtr)i1;
  j = 0;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 14106))+8);
  i = 0;
  i3 = 0<i2;
  if (i3) goto l3;
  i2=0;
  goto l13;
l3:
  i3=0;i4=0;
l4_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14138))+16);
  i5 = _check_pointer(i5, 14145);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)((i5+((_check_index(i3, i6, OOC_UINT32, 14145))*12))+4);
  i5 = ADT_Dictionary_AddressKey__IsSet((Object__Object)i5);
  if (!i5) goto l8;
  i5 = _check_pointer(i1, 14172);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14183))+16);
  i7 = _check_pointer(i7, 14190);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)((i7+((_check_index(i3, i8, OOC_UINT32, 14190))*12))+8);
  *(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 14172))*4) = i7;
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
  i0 = *(OOC_INT32*)((_check_pointer(i0, 14257))+4);
  _assert((i2==i0), 127, 14241);
  return (Object__ObjectArrayPtr)i1;
  ;
}

OOC_CHAR8 ADT_Dictionary_AddressKey__DictionaryDesc_Equals(ADT_Dictionary_AddressKey__Dictionary dict, Object__Object obj) {

  _assert(0u, 127, 14404);
  _failed_function(14327); 
  ;
}

OOC_INT32 ADT_Dictionary_AddressKey__DictionaryDesc_HashCode(ADT_Dictionary_AddressKey__Dictionary dict) {

  _assert(0u, 127, 14530);
  _failed_function(14469); 
  ;
}

void ADT_Dictionary_AddressKey__DictionaryDesc_Store(ADT_Dictionary_AddressKey__Dictionary dict, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT32 i;

  i0 = (OOC_INT32)dict;
  i1 = (OOC_INT32)w;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 14693))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14677)))), IO_BinaryRider__WriterDesc_WriteNum)),IO_BinaryRider__WriterDesc_WriteNum)((IO_BinaryRider__Writer)i1, i2);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 14714))+4);
  i2 = i2!=0;
  if (!i2) goto l14;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 14755))+8);
  i = 0;
  i3 = 0<i2;
  if (!i3) goto l14;
  i3=0;
l5_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14789))+16);
  i4 = _check_pointer(i4, 14796);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 14796))*12))+4);
  i4 = ADT_Dictionary_AddressKey__IsSet((Object__Object)i4);
  if (!i4) goto l8;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14841))+16);
  i4 = _check_pointer(i4, 14848);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 14848))*12))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14822)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i1, (Object__Object)i4);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14889))+16);
  i4 = _check_pointer(i4, 14896);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 14896))*12))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14870)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i1, (Object__Object)i4);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15102)))), IO_BinaryRider__ReaderDesc_ReadNum)),IO_BinaryRider__ReaderDesc_ReadNum)((IO_BinaryRider__Reader)i1, (void*)((_check_pointer(i0, 15117))+8));
  i2 = *(OOC_INT32*)((_check_pointer(i0, 15138))+8);
  i2 = i2!=0;
  if (!i2) goto l11;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 15316))+8);
  *(OOC_INT32*)((_check_pointer(i0, 15303))+16) = ((OOC_INT32)RT0__NewObject(_td_ADT_Dictionary_AddressKey__Table.baseTypes[0], i2));
  i = 0;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 15349))+8);
  i3 = 0<i2;
  if (!i3) goto l10;
  i3=0;
l5_loop:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15370)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i1, (void*)(OOC_INT32)&obj);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15402))+16);
  i4 = _check_pointer(i4, 15409);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)obj;
  *(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 15409))*12))+4) = i6;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15435)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i1, (void*)(OOC_INT32)&obj);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15467))+16);
  i4 = _check_pointer(i4, 15474);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)obj;
  *(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 15474))*12))+8) = i6;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15505))+16);
  i4 = _check_pointer(i4, 15512);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15542))+16);
  i6 = _check_pointer(i6, 15549);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((i6+((_check_index(i3, i7, OOC_UINT32, 15549))*12))+4);
  i6 = HashCode__Ptr((void*)i6);
  *(OOC_INT32*)(i4+((_check_index(i3, i5, OOC_UINT32, 15512))*12)) = i6;
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l5_loop;
l10:
  i1 = *(OOC_INT32*)((_check_pointer(i0, 15595))+8);
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
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey__polys+(_check_index(0, 29, OOC_UINT8, 15716))*4) = 7;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey__polys+(_check_index(1, 29, OOC_UINT8, 15737))*4) = 11;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey__polys+(_check_index(2, 29, OOC_UINT8, 15758))*4) = 19;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey__polys+(_check_index(3, 29, OOC_UINT8, 15780))*4) = 37;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey__polys+(_check_index(4, 29, OOC_UINT8, 15802))*4) = 67;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey__polys+(_check_index(5, 29, OOC_UINT8, 15824))*4) = 131;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey__polys+(_check_index(6, 29, OOC_UINT8, 15847))*4) = 285;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey__polys+(_check_index(7, 29, OOC_UINT8, 15871))*4) = 529;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey__polys+(_check_index(8, 29, OOC_UINT8, 15895))*4) = 1033;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey__polys+(_check_index(9, 29, OOC_UINT8, 15919))*4) = 2053;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey__polys+(_check_index(10, 29, OOC_UINT8, 15943))*4) = 4179;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey__polys+(_check_index(11, 29, OOC_UINT8, 15969))*4) = 8219;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey__polys+(_check_index(12, 29, OOC_UINT8, 15995))*4) = 16427;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey__polys+(_check_index(13, 29, OOC_UINT8, 16022))*4) = 32771;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey__polys+(_check_index(14, 29, OOC_UINT8, 16048))*4) = 65581;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey__polys+(_check_index(15, 29, OOC_UINT8, 16075))*4) = 131081;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey__polys+(_check_index(16, 29, OOC_UINT8, 16102))*4) = 262183;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey__polys+(_check_index(17, 29, OOC_UINT8, 16130))*4) = 524327;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey__polys+(_check_index(18, 29, OOC_UINT8, 16158))*4) = 1048585;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey__polys+(_check_index(19, 29, OOC_UINT8, 16186))*4) = 2097157;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey__polys+(_check_index(20, 29, OOC_UINT8, 16214))*4) = 4194307;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey__polys+(_check_index(21, 29, OOC_UINT8, 16242))*4) = 8388641;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey__polys+(_check_index(22, 29, OOC_UINT8, 16271))*4) = 16777243;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey__polys+(_check_index(23, 29, OOC_UINT8, 16301))*4) = 33554441;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey__polys+(_check_index(24, 29, OOC_UINT8, 16330))*4) = 67108935;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey__polys+(_check_index(25, 29, OOC_UINT8, 16360))*4) = 134217767;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey__polys+(_check_index(26, 29, OOC_UINT8, 16391))*4) = 268435465;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey__polys+(_check_index(27, 29, OOC_UINT8, 16421))*4) = 536870917;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey__polys+(_check_index(28, 29, OOC_UINT8, 16451))*4) = 1073741907;
  return;
  ;
}

void OOC_ADT_Dictionary_AddressKey_destroy(void) {
}

/* --- */
