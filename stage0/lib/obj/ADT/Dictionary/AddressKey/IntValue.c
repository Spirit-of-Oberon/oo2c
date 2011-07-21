#include <ADT/Dictionary/AddressKey/IntValue.d>
#include <__oo2c.h>
#include <setjmp.h>

void ADT_Dictionary_AddressKey_IntValue__Init(ADT_Dictionary_AddressKey_IntValue__Dictionary dict) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)dict;
  *(OOC_INT32*)((_check_pointer(i0, 4086))+8) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 4107))+12) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 4128))+16) = (OOC_INT32)0;
  *(OOC_INT32*)(_check_pointer(i0, 4152)) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 4173))+4) = 0;
  return;
  ;
}

ADT_Dictionary_AddressKey_IntValue__Dictionary ADT_Dictionary_AddressKey_IntValue__New(void) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)RT0__NewObject(_td_ADT_Dictionary_AddressKey_IntValue__Dictionary.baseTypes[0]);
  ADT_Dictionary_AddressKey_IntValue__Init((ADT_Dictionary_AddressKey_IntValue__Dictionary)i0);
  return (ADT_Dictionary_AddressKey_IntValue__Dictionary)i0;
  ;
}

void ADT_Dictionary_AddressKey_IntValue__DictionaryDesc_Destroy(ADT_Dictionary_AddressKey_IntValue__Dictionary dict) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_INT32 i;

  i0 = (OOC_INT32)dict;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4448))+16);
  i1 = i1!=(OOC_INT32)0;
  if (!i1) goto l11;
  i = 0;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 4492))+8);
  i2 = 0<i1;
  if (!i2) goto l10;
  i2=0;
l5_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4555))+16);
  i3 = _check_pointer(i3, 4562);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)((i3+((_check_index(i2, i4, OOC_UINT32, 4562))*12))+4) = (OOC_INT32)0;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4591))+16);
  i3 = _check_pointer(i3, 4598);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)((i3+((_check_index(i2, i4, OOC_UINT32, 4598))*12))+8) = 0;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4627))+16);
  i3 = _check_pointer(i3, 4634);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)(i3+((_check_index(i2, i4, OOC_UINT32, 4634))*12)) = 0;
  i2 = i2+1;
  i = i2;
  i3 = i2<i1;
  if (i3) goto l5_loop;
l10:
  *(OOC_INT32*)((_check_pointer(i0, 4670))+16) = (OOC_INT32)0;
l11:
  return;
  ;
}

static OOC_CHAR8 ADT_Dictionary_AddressKey_IntValue__IsSet(Object__Object key) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)key;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l3;
  i0=0u;
  goto l4;
l3:
  i1 = (OOC_INT32)ADT_Dictionary_AddressKey_IntValue__dummy;
  i0 = i0!=i1;
  
l4:
  return i0;
  ;
}

static OOC_INT32 ADT_Dictionary_AddressKey_IntValue__InternalLookup(ADT_Dictionary_AddressKey_IntValue__Dictionary dict, Object__Object key, OOC_INT32 hash) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9;
  ADT_Dictionary_AddressKey_IntValue__Table t;
  OOC_UINT32 mask;
  OOC_INT32 i;
  OOC_INT32 freeslot;
  OOC_INT32 incr;

  i0 = (OOC_INT32)dict;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6114))+16);
  t = (ADT_Dictionary_AddressKey_IntValue__Table)i1;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 6151))+8);
  i3 = hash;
  i4 = _type_cast_fast(OOC_UINT32, OOC_INT32, i3);
  i2 = _type_cast_fast(OOC_UINT32, OOC_INT32, (i2-1));
  mask = i2;
  i5 = _type_cast_fast(OOC_INT32, OOC_UINT32, ((~i4)&i2));
  i = i5;
  i6 = _check_pointer(i1, 6224);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((i6+((_check_index(i5, i7, OOC_UINT32, 6224))*12))+4);
  i6 = i6==(OOC_INT32)0;
  if (i6) goto l3;
  i6 = _check_pointer(i1, 6245);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((i6+((_check_index(i5, i7, OOC_UINT32, 6245))*12))+4);
  i7 = (OOC_INT32)key;
  i6 = i6==i7;
  
  goto l4;
l3:
  i6=1u;
l4:
  i7 = (OOC_INT32)key;
  i8 = (OOC_INT32)ADT_Dictionary_AddressKey_IntValue__dummy;
  if (i6) goto l19;
  i6 = _check_pointer(i1, 6293);
  i9 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((i6+((_check_index(i5, i9, OOC_UINT32, 6293))*12))+4);
  i6 = i6==i8;
  if (i6) goto l17;
  i6 = _check_pointer(i1, 6348);
  i9 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = *(OOC_INT32*)(i6+((_check_index(i5, i9, OOC_UINT32, 6348))*12));
  i6 = i6==i3;
  if (i6) goto l11;
  i6=0u;
  goto l13;
l11:
  i6 = _check_pointer(i1, 6376);
  i9 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((i6+((_check_index(i5, i9, OOC_UINT32, 6376))*12))+4);
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
  i4 = *(OOC_INT32*)((_check_pointer(i0, 6578))+8);
  i4 = i4-1;
  incr = i4;
  
l24:
  {register OOC_INT32 h0=i4;i4=i5;i5=h0;}
l25_loop:
  i4 = _type_cast_fast(OOC_INT32, OOC_UINT32, ((_type_cast_fast(OOC_UINT32, OOC_INT32, (i4+i5)))&i2));
  i = i4;
  i6 = _check_pointer(i1, 6671);
  i9 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((i6+((_check_index(i4, i9, OOC_UINT32, 6671))*12))+4);
  i6 = i6==(OOC_INT32)0;
  if (i6) goto l42;
  i6 = _check_pointer(i1, 6808);
  i9 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((i6+((_check_index(i4, i9, OOC_UINT32, 6808))*12))+4);
  i6 = i6==i8;
  if (i6) goto l37;
  i6 = _check_pointer(i1, 6912);
  i9 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = *(OOC_INT32*)(i6+((_check_index(i4, i9, OOC_UINT32, 6912))*12));
  i6 = i6==i3;
  if (i6) goto l32;
  i6=0u;
  goto l34;
l32:
  i6 = _check_pointer(i1, 6940);
  i9 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((i6+((_check_index(i4, i9, OOC_UINT32, 6940))*12))+4);
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
  i6 = *(OOC_INT32*)((_check_pointer(i0, 7027))+8);
  i6 = i5>=i6;
  if (!i6) goto l25_loop;
  i6 = *(OOC_INT32*)((_check_pointer(i0, 7108))+12);
  i5 = _type_cast_fast(OOC_INT32, OOC_UINT32, ((_type_cast_fast(OOC_UINT32, OOC_INT32, i5))^(_type_cast_fast(OOC_UINT32, OOC_INT32, i6))));
  incr = i5;
  
  goto l25_loop;
l53:
  ;
}

static void ADT_Dictionary_AddressKey_IntValue__Insert(ADT_Dictionary_AddressKey_IntValue__Dictionary dict, Object__Object key, OOC_INT32 hash, OOC_INT32 value) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT32 i;

  i0 = hash;
  i1 = (OOC_INT32)key;
  i2 = (OOC_INT32)dict;
  i3 = ADT_Dictionary_AddressKey_IntValue__InternalLookup((ADT_Dictionary_AddressKey_IntValue__Dictionary)i2, (Object__Object)i1, i0);
  i = i3;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 7519))+16);
  i4 = _check_pointer(i4, 7526);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 7526))*12))+4);
  i4 = ADT_Dictionary_AddressKey_IntValue__IsSet((Object__Object)i4);
  if (i4) goto l6;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 7686))+16);
  i4 = _check_pointer(i4, 7693);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 7693))*12))+4);
  i4 = i4==(OOC_INT32)0;
  if (!i4) goto l5;
  i4 = *(OOC_INT32*)(_check_pointer(i2, 7731));
  *(OOC_INT32*)(_check_pointer(i2, 7731)) = (i4+1);
l5:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 7760))+16);
  i4 = _check_pointer(i4, 7767);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  *(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 7767))*12))+4) = i1;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 7794))+16);
  i1 = _check_pointer(i1, 7801);
  i4 = OOC_ARRAY_LENGTH(i1, 0);
  *(OOC_INT32*)(i1+((_check_index(i3, i4, OOC_UINT32, 7801))*12)) = i0;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 7830))+16);
  i0 = _check_pointer(i0, 7837);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  i4 = value;
  *(OOC_INT32*)((i0+((_check_index(i3, i1, OOC_UINT32, 7837))*12))+8) = i4;
  i0 = *(OOC_INT32*)((_check_pointer(i2, 7873))+4);
  *(OOC_INT32*)((_check_pointer(i2, 7873))+4) = (i0+1);
  goto l7;
l6:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 7578))+16);
  i0 = _check_pointer(i0, 7585);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  i2 = value;
  *(OOC_INT32*)((i0+((_check_index(i3, i1, OOC_UINT32, 7585))*12))+8) = i2;
l7:
  return;
  ;
}

static void ADT_Dictionary_AddressKey_IntValue__Resize(ADT_Dictionary_AddressKey_IntValue__Dictionary dict, OOC_INT32 minUsed) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9;
  OOC_INT32 oldSize;
  ADT_Dictionary_AddressKey_IntValue__Table oldTable;
  OOC_INT32 i;
  OOC_INT32 newSize;
  OOC_INT32 newPoly;
  ADT_Dictionary_AddressKey_IntValue__Table newTable;

  i0 = (OOC_INT32)dict;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 8277))+8);
  oldSize = i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8305))+16);
  oldTable = (ADT_Dictionary_AddressKey_IntValue__Table)i2;
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
  i3 = *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey_IntValue__polys+(_check_index(i3, 29, OOC_UINT32, 8458))*4);
  newPoly = i3;
  i5 = (OOC_INT32)RT0__NewObject(_td_ADT_Dictionary_AddressKey_IntValue__Table.baseTypes[0], i4);
  newTable = (ADT_Dictionary_AddressKey_IntValue__Table)i5;
  i = 0;
  i6 = 0<i4;
  if (!i6) goto l17;
  i6=0;
l12_loop:
  i7 = _check_pointer(i5, 8597);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  *(OOC_INT32*)((i7+((_check_index(i6, i8, OOC_UINT32, 8597))*12))+4) = (OOC_INT32)0;
  i7 = _check_pointer(i5, 8628);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  *(OOC_INT32*)((i7+((_check_index(i6, i8, OOC_UINT32, 8628))*12))+8) = 0;
  i7 = _check_pointer(i5, 8659);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  *(OOC_INT32*)(i7+((_check_index(i6, i8, OOC_UINT32, 8659))*12)) = 0;
  i6 = i6+1;
  i = i6;
  i7 = i6<i4;
  if (i7) goto l12_loop;
l17:
  *(OOC_INT32*)((_check_pointer(i0, 8691))+8) = i4;
  *(OOC_INT32*)((_check_pointer(i0, 8718))+12) = i3;
  *(OOC_INT32*)((_check_pointer(i0, 8745))+16) = i5;
  *(OOC_INT32*)(_check_pointer(i0, 8774)) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 8795))+4) = 0;
  i = 0;
  i3 = 0<i1;
  if (!i3) goto l28;
  i3=0;
l20_loop:
  i4 = _check_pointer(i2, 8868);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 8868))*12))+4);
  i4 = ADT_Dictionary_AddressKey_IntValue__IsSet((Object__Object)i4);
  if (!i4) goto l23;
  i4 = _check_pointer(i2, 8950);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = _check_pointer(i2, 8931);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i8 = _check_pointer(i2, 8913);
  i9 = OOC_ARRAY_LENGTH(i8, 0);
  i4 = *(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 8950))*12))+8);
  i5 = (OOC_INT32)*(OOC_INT32*)((i8+((_check_index(i3, i9, OOC_UINT32, 8913))*12))+4);
  i6 = *(OOC_INT32*)(i6+((_check_index(i3, i7, OOC_UINT32, 8931))*12));
  ADT_Dictionary_AddressKey_IntValue__Insert((ADT_Dictionary_AddressKey_IntValue__Dictionary)i0, (Object__Object)i5, i6, i4);
  i4 = _check_pointer(i2, 8979);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  *(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 8979))*12))+4) = (OOC_INT32)0;
  i4 = _check_pointer(i2, 9040);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  *(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 9040))*12))+8) = 0;
l23:
  i3 = i3+1;
  i = i3;
  i4 = i3<i1;
  if (i4) goto l20_loop;
l28:
  return;
  ;
}

OOC_CHAR8 ADT_Dictionary_AddressKey_IntValue__DictionaryDesc_HasKey(ADT_Dictionary_AddressKey_IntValue__Dictionary dict, Object__Object key) {
  register OOC_INT32 i0,i1,i2;
  OOC_INT32 index;

  i0 = (OOC_INT32)dict;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 9334))+4);
  i1 = i1==0;
  if (i1) goto l3;
  i1 = (OOC_INT32)key;
  i2 = HashCode__Ptr((void*)i1);
  i1 = ADT_Dictionary_AddressKey_IntValue__InternalLookup((ADT_Dictionary_AddressKey_IntValue__Dictionary)i0, (Object__Object)i1, i2);
  index = i1;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9465))+16);
  i0 = _check_pointer(i0, 9472);
  i2 = OOC_ARRAY_LENGTH(i0, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)((i0+((_check_index(i1, i2, OOC_UINT32, 9472))*12))+4);
  i0 = ADT_Dictionary_AddressKey_IntValue__IsSet((Object__Object)i0);
  return i0;
  goto l4;
l3:
  return 0u;
l4:
  _failed_function(9120); return 0;
  ;
}

OOC_INT32 ADT_Dictionary_AddressKey_IntValue__DictionaryDesc_Size(ADT_Dictionary_AddressKey_IntValue__Dictionary dict) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)dict;
  i0 = *(OOC_INT32*)((_check_pointer(i0, 9634))+4);
  return i0;
  ;
}

OOC_INT32 ADT_Dictionary_AddressKey_IntValue__DictionaryDesc_Get(ADT_Dictionary_AddressKey_IntValue__Dictionary dict, Object__Object key) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_INT32 i;

  i0 = (OOC_INT32)key;
  _assert((i0!=(OOC_INT32)0), 127, 9992);
  i1 = (OOC_INT32)dict;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 10028))+4);
  _assert((i2!=0), 127, 10016);
  i2 = HashCode__Ptr((void*)i0);
  i0 = ADT_Dictionary_AddressKey_IntValue__InternalLookup((ADT_Dictionary_AddressKey_IntValue__Dictionary)i1, (Object__Object)i0, i2);
  i = i0;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 10120))+16);
  i2 = _check_pointer(i2, 10127);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)((i2+((_check_index(i0, i3, OOC_UINT32, 10127))*12))+4);
  i2 = ADT_Dictionary_AddressKey_IntValue__IsSet((Object__Object)i2);
  _assert(i2, 127, 10101);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 10154))+16);
  i1 = _check_pointer(i1, 10161);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i0 = *(OOC_INT32*)((i1+((_check_index(i0, i2, OOC_UINT32, 10161))*12))+8);
  return i0;
  ;
}

OOC_CHAR8 ADT_Dictionary_AddressKey_IntValue__DictionaryDesc_Lookup(ADT_Dictionary_AddressKey_IntValue__Dictionary dict, Object__Object key, OOC_INT32 *value) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_INT32 i;

  i0 = (OOC_INT32)key;
  _assert((i0!=(OOC_INT32)0), 127, 10591);
  i1 = (OOC_INT32)dict;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 10622))+4);
  i2 = i2==0;
  if (i2) goto l7;
  i2 = HashCode__Ptr((void*)i0);
  i0 = ADT_Dictionary_AddressKey_IntValue__InternalLookup((ADT_Dictionary_AddressKey_IntValue__Dictionary)i1, (Object__Object)i0, i2);
  i = i0;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 10744))+16);
  i2 = _check_pointer(i2, 10751);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)((i2+((_check_index(i0, i3, OOC_UINT32, 10751))*12))+4);
  i2 = ADT_Dictionary_AddressKey_IntValue__IsSet((Object__Object)i2);
  if (i2) goto l5;
  return 0u;
  goto l8;
l5:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 10787))+16);
  i1 = _check_pointer(i1, 10794);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i0 = *(OOC_INT32*)((i1+((_check_index(i0, i2, OOC_UINT32, 10794))*12))+8);
  *value = i0;
  return 1u;
  goto l8;
l7:
  return 0u;
l8:
  _failed_function(10213); return 0;
  ;
}

void ADT_Dictionary_AddressKey_IntValue__DictionaryDesc_Set(ADT_Dictionary_AddressKey_IntValue__Dictionary dict, Object__Object key, OOC_INT32 value) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)key;
  _assert((i0!=(OOC_INT32)0), 127, 11281);
  i1 = (OOC_INT32)dict;
  i2 = *(OOC_INT32*)(_check_pointer(i1, 11313));
  i3 = *(OOC_INT32*)((_check_pointer(i1, 11329))+8);
  i2 = (i2*3)>=(i3*2);
  if (!i2) goto l4;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 11368))+4);
  ADT_Dictionary_AddressKey_IntValue__Resize((ADT_Dictionary_AddressKey_IntValue__Dictionary)i1, (i2*2));
l4:
  i2 = HashCode__Ptr((void*)i0);
  i3 = value;
  ADT_Dictionary_AddressKey_IntValue__Insert((ADT_Dictionary_AddressKey_IntValue__Dictionary)i1, (Object__Object)i0, i2, i3);
  return;
  ;
}

ADT_Dictionary_AddressKey_IntValue__Dictionary ADT_Dictionary_AddressKey_IntValue__DictionaryDesc_Copy(ADT_Dictionary_AddressKey_IntValue__Dictionary dict) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9;
  ADT_Dictionary_AddressKey_IntValue__Dictionary copy;
  OOC_INT32 i;

  i0 = (OOC_INT32)ADT_Dictionary_AddressKey_IntValue__New();
  copy = (ADT_Dictionary_AddressKey_IntValue__Dictionary)i0;
  i1 = (OOC_INT32)dict;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 11637))+4);
  i2 = i2>0;
  if (!i2) goto l14;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 11679))+4);
  ADT_Dictionary_AddressKey_IntValue__Resize((ADT_Dictionary_AddressKey_IntValue__Dictionary)i0, ((i2*3)>>1));
  i2 = *(OOC_INT32*)((_check_pointer(i1, 11721))+8);
  i = 0;
  i3 = 0<i2;
  if (!i3) goto l14;
  i3=0;
l5_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11755))+16);
  i4 = _check_pointer(i4, 11762);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 11762))*12))+4);
  i4 = ADT_Dictionary_AddressKey_IntValue__IsSet((Object__Object)i4);
  if (!i4) goto l8;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11866))+16);
  i4 = _check_pointer(i4, 11873);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11826))+16);
  i6 = _check_pointer(i6, 11833);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11805))+16);
  i8 = _check_pointer(i8, 11812);
  i9 = OOC_ARRAY_LENGTH(i8, 0);
  i4 = *(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 11873))*12))+8);
  i5 = (OOC_INT32)*(OOC_INT32*)((i8+((_check_index(i3, i9, OOC_UINT32, 11812))*12))+4);
  i6 = *(OOC_INT32*)(i6+((_check_index(i3, i7, OOC_UINT32, 11833))*12));
  ADT_Dictionary_AddressKey_IntValue__Insert((ADT_Dictionary_AddressKey_IntValue__Dictionary)i0, (Object__Object)i5, i6, i4);
l8:
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l5_loop;
l14:
  return (ADT_Dictionary_AddressKey_IntValue__Dictionary)i0;
  ;
}

void ADT_Dictionary_AddressKey_IntValue__DictionaryDesc_Delete(ADT_Dictionary_AddressKey_IntValue__Dictionary dict, Object__Object key) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_INT32 i;

  i0 = (OOC_INT32)key;
  _assert((i0!=(OOC_INT32)0), 127, 12276);
  i1 = (OOC_INT32)dict;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 12312))+4);
  _assert((i2!=0), 127, 12300);
  i2 = HashCode__Ptr((void*)i0);
  i0 = ADT_Dictionary_AddressKey_IntValue__InternalLookup((ADT_Dictionary_AddressKey_IntValue__Dictionary)i1, (Object__Object)i0, i2);
  i = i0;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12404))+16);
  i2 = _check_pointer(i2, 12411);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)((i2+((_check_index(i0, i3, OOC_UINT32, 12411))*12))+4);
  i2 = ADT_Dictionary_AddressKey_IntValue__IsSet((Object__Object)i2);
  _assert(i2, 127, 12385);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12431))+16);
  i2 = _check_pointer(i2, 12438);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i4 = (OOC_INT32)ADT_Dictionary_AddressKey_IntValue__dummy;
  *(OOC_INT32*)((i2+((_check_index(i0, i3, OOC_UINT32, 12438))*12))+4) = i4;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12511))+16);
  i2 = _check_pointer(i2, 12518);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  *(OOC_INT32*)((i2+((_check_index(i0, i3, OOC_UINT32, 12518))*12))+8) = 0;
  i0 = *(OOC_INT32*)((_check_pointer(i1, 12548))+4);
  *(OOC_INT32*)((_check_pointer(i1, 12548))+4) = (i0-1);
  return;
  ;
}

void ADT_Dictionary_AddressKey_IntValue__DictionaryDesc_Clear(ADT_Dictionary_AddressKey_IntValue__Dictionary dict) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_INT32 i;

  i0 = (OOC_INT32)dict;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12710))+16);
  i1 = i1!=(OOC_INT32)0;
  if (!i1) goto l11;
  i = 0;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 12754))+8);
  i2 = 0<i1;
  if (!i2) goto l10;
  i2=0;
l5_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12817))+16);
  i3 = _check_pointer(i3, 12824);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)((i3+((_check_index(i2, i4, OOC_UINT32, 12824))*12))+4) = (OOC_INT32)0;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12853))+16);
  i3 = _check_pointer(i3, 12860);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)((i3+((_check_index(i2, i4, OOC_UINT32, 12860))*12))+8) = 0;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12889))+16);
  i3 = _check_pointer(i3, 12896);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)(i3+((_check_index(i2, i4, OOC_UINT32, 12896))*12)) = 0;
  i2 = i2+1;
  i = i2;
  i3 = i2<i1;
  if (i3) goto l5_loop;
l10:
  ADT_Dictionary_AddressKey_IntValue__Init((ADT_Dictionary_AddressKey_IntValue__Dictionary)i0);
l11:
  return;
  ;
}

Object__ObjectArrayPtr ADT_Dictionary_AddressKey_IntValue__DictionaryDesc_Keys(ADT_Dictionary_AddressKey_IntValue__Dictionary dict) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
  Object__ObjectArrayPtr list;
  OOC_INT32 j;
  OOC_INT32 i;

  i0 = (OOC_INT32)dict;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 13223))+4);
  i1 = (OOC_INT32)RT0__NewObject(_td_Object__ObjectArrayPtr.baseTypes[0], i1);
  list = (Object__ObjectArrayPtr)i1;
  j = 0;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 13266))+8);
  i = 0;
  i3 = 0<i2;
  if (i3) goto l3;
  i2=0;
  goto l13;
l3:
  i3=0;i4=0;
l4_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13298))+16);
  i5 = _check_pointer(i5, 13305);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)((i5+((_check_index(i3, i6, OOC_UINT32, 13305))*12))+4);
  i5 = ADT_Dictionary_AddressKey_IntValue__IsSet((Object__Object)i5);
  if (!i5) goto l8;
  i5 = _check_pointer(i1, 13332);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13343))+16);
  i7 = _check_pointer(i7, 13350);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)((i7+((_check_index(i3, i8, OOC_UINT32, 13350))*12))+4);
  *(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 13332))*4) = i7;
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
  i0 = *(OOC_INT32*)((_check_pointer(i0, 13415))+4);
  _assert((i2==i0), 127, 13399);
  return (Object__ObjectArrayPtr)i1;
  ;
}

void ADT_Dictionary_AddressKey_IntValue__DictionaryDesc_Store(ADT_Dictionary_AddressKey_IntValue__Dictionary dict, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT32 i;

  i0 = (OOC_INT32)dict;
  i1 = (OOC_INT32)w;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 14095))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14079)))), IO_BinaryRider__WriterDesc_WriteNum)),IO_BinaryRider__WriterDesc_WriteNum)((IO_BinaryRider__Writer)i1, i2);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 14116))+4);
  i2 = i2!=0;
  if (!i2) goto l14;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 14157))+8);
  i = 0;
  i3 = 0<i2;
  if (!i3) goto l14;
  i3=0;
l5_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14191))+16);
  i4 = _check_pointer(i4, 14198);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 14198))*12))+4);
  i4 = ADT_Dictionary_AddressKey_IntValue__IsSet((Object__Object)i4);
  if (!i4) goto l8;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14243))+16);
  i4 = _check_pointer(i4, 14250);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 14250))*12))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14224)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i1, (Object__Object)i4);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14288))+16);
  i4 = _check_pointer(i4, 14295);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = *(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 14295))*12))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14272)))), IO_BinaryRider__WriterDesc_WriteNum)),IO_BinaryRider__WriterDesc_WriteNum)((IO_BinaryRider__Writer)i1, i4);
l8:
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l5_loop;
l14:
  return;
  ;
}

void ADT_Dictionary_AddressKey_IntValue__DictionaryDesc_Load(ADT_Dictionary_AddressKey_IntValue__Dictionary dict, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
  OOC_INT32 i;
  Object__Object obj;

  i0 = (OOC_INT32)dict;
  ADT_Dictionary_AddressKey_IntValue__Init((ADT_Dictionary_AddressKey_IntValue__Dictionary)i0);
  i1 = (OOC_INT32)r;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14500)))), IO_BinaryRider__ReaderDesc_ReadNum)),IO_BinaryRider__ReaderDesc_ReadNum)((IO_BinaryRider__Reader)i1, (void*)((_check_pointer(i0, 14515))+8));
  i2 = *(OOC_INT32*)((_check_pointer(i0, 14536))+8);
  i2 = i2!=0;
  if (!i2) goto l11;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 14714))+8);
  *(OOC_INT32*)((_check_pointer(i0, 14701))+16) = ((OOC_INT32)RT0__NewObject(_td_ADT_Dictionary_AddressKey_IntValue__Table.baseTypes[0], i2));
  i = 0;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 14747))+8);
  i3 = 0<i2;
  if (!i3) goto l10;
  i3=0;
l5_loop:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14768)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i1, (void*)(OOC_INT32)&obj);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14800))+16);
  i4 = _check_pointer(i4, 14807);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)obj;
  *(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 14807))*12))+4) = i6;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14848))+16);
  i4 = _check_pointer(i4, 14855);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14833)))), IO_BinaryRider__ReaderDesc_ReadNum)),IO_BinaryRider__ReaderDesc_ReadNum)((IO_BinaryRider__Reader)i1, (void*)((i4+((_check_index(i3, i5, OOC_UINT32, 14855))*12))+8));
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14880))+16);
  i4 = _check_pointer(i4, 14887);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14917))+16);
  i6 = _check_pointer(i6, 14924);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((i6+((_check_index(i3, i7, OOC_UINT32, 14924))*12))+4);
  i6 = HashCode__Ptr((void*)i6);
  *(OOC_INT32*)(i4+((_check_index(i3, i5, OOC_UINT32, 14887))*12)) = i6;
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l5_loop;
l10:
  i1 = *(OOC_INT32*)((_check_pointer(i0, 14970))+8);
  ADT_Dictionary_AddressKey_IntValue__Resize((ADT_Dictionary_AddressKey_IntValue__Dictionary)i0, ((i1*3)>>1));
l11:
  return;
  ;
}

void OOC_ADT_Dictionary_AddressKey_IntValue_init(void) {

  ADT_Dictionary_AddressKey_IntValue__dummy = (ADT_Dictionary_AddressKey_IntValue__Dummy)((OOC_INT32)RT0__NewObject(_td_ADT_Dictionary_AddressKey_IntValue__Dummy.baseTypes[0]));
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey_IntValue__polys+(_check_index(0, 29, OOC_UINT8, 15039))*4) = 7;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey_IntValue__polys+(_check_index(1, 29, OOC_UINT8, 15060))*4) = 11;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey_IntValue__polys+(_check_index(2, 29, OOC_UINT8, 15081))*4) = 19;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey_IntValue__polys+(_check_index(3, 29, OOC_UINT8, 15103))*4) = 37;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey_IntValue__polys+(_check_index(4, 29, OOC_UINT8, 15125))*4) = 67;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey_IntValue__polys+(_check_index(5, 29, OOC_UINT8, 15147))*4) = 131;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey_IntValue__polys+(_check_index(6, 29, OOC_UINT8, 15170))*4) = 285;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey_IntValue__polys+(_check_index(7, 29, OOC_UINT8, 15194))*4) = 529;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey_IntValue__polys+(_check_index(8, 29, OOC_UINT8, 15218))*4) = 1033;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey_IntValue__polys+(_check_index(9, 29, OOC_UINT8, 15242))*4) = 2053;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey_IntValue__polys+(_check_index(10, 29, OOC_UINT8, 15266))*4) = 4179;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey_IntValue__polys+(_check_index(11, 29, OOC_UINT8, 15292))*4) = 8219;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey_IntValue__polys+(_check_index(12, 29, OOC_UINT8, 15318))*4) = 16427;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey_IntValue__polys+(_check_index(13, 29, OOC_UINT8, 15345))*4) = 32771;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey_IntValue__polys+(_check_index(14, 29, OOC_UINT8, 15371))*4) = 65581;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey_IntValue__polys+(_check_index(15, 29, OOC_UINT8, 15398))*4) = 131081;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey_IntValue__polys+(_check_index(16, 29, OOC_UINT8, 15425))*4) = 262183;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey_IntValue__polys+(_check_index(17, 29, OOC_UINT8, 15453))*4) = 524327;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey_IntValue__polys+(_check_index(18, 29, OOC_UINT8, 15481))*4) = 1048585;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey_IntValue__polys+(_check_index(19, 29, OOC_UINT8, 15509))*4) = 2097157;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey_IntValue__polys+(_check_index(20, 29, OOC_UINT8, 15537))*4) = 4194307;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey_IntValue__polys+(_check_index(21, 29, OOC_UINT8, 15565))*4) = 8388641;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey_IntValue__polys+(_check_index(22, 29, OOC_UINT8, 15594))*4) = 16777243;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey_IntValue__polys+(_check_index(23, 29, OOC_UINT8, 15624))*4) = 33554441;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey_IntValue__polys+(_check_index(24, 29, OOC_UINT8, 15653))*4) = 67108935;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey_IntValue__polys+(_check_index(25, 29, OOC_UINT8, 15683))*4) = 134217767;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey_IntValue__polys+(_check_index(26, 29, OOC_UINT8, 15714))*4) = 268435465;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey_IntValue__polys+(_check_index(27, 29, OOC_UINT8, 15744))*4) = 536870917;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_AddressKey_IntValue__polys+(_check_index(28, 29, OOC_UINT8, 15774))*4) = 1073741907;
  return;
  ;
}

void OOC_ADT_Dictionary_AddressKey_IntValue_destroy(void) {
}

/* --- */
