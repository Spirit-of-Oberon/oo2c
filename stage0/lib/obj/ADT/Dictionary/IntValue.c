#include <ADT/Dictionary/IntValue.d>
#include <__oo2c.h>
#include <setjmp.h>

void ADT_Dictionary_IntValue__Init(ADT_Dictionary_IntValue__Dictionary dict) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)dict;
  *(OOC_INT32*)((_check_pointer(i0, 4066))+8) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 4087))+12) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 4108))+16) = (OOC_INT32)0;
  *(OOC_INT32*)(_check_pointer(i0, 4132)) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 4153))+4) = 0;
  return;
  ;
}

ADT_Dictionary_IntValue__Dictionary ADT_Dictionary_IntValue__New(void) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)RT0__NewObject(_td_ADT_Dictionary_IntValue__Dictionary.baseTypes[0]);
  ADT_Dictionary_IntValue__Init((ADT_Dictionary_IntValue__Dictionary)i0);
  return (ADT_Dictionary_IntValue__Dictionary)i0;
  ;
}

void ADT_Dictionary_IntValue__DictionaryDesc_Destroy(ADT_Dictionary_IntValue__Dictionary dict) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_INT32 i;

  i0 = (OOC_INT32)dict;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4428))+16);
  i1 = i1!=(OOC_INT32)0;
  if (!i1) goto l11;
  i = 0;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 4472))+8);
  i2 = 0<i1;
  if (!i2) goto l10;
  i2=0;
l5_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4535))+16);
  i3 = _check_pointer(i3, 4542);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)((i3+((_check_index(i2, i4, OOC_UINT32, 4542))*12))+4) = (OOC_INT32)0;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4571))+16);
  i3 = _check_pointer(i3, 4578);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)((i3+((_check_index(i2, i4, OOC_UINT32, 4578))*12))+8) = 0;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4607))+16);
  i3 = _check_pointer(i3, 4614);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)(i3+((_check_index(i2, i4, OOC_UINT32, 4614))*12)) = 0;
  i2 = i2+1;
  i = i2;
  i3 = i2<i1;
  if (i3) goto l5_loop;
l10:
  *(OOC_INT32*)((_check_pointer(i0, 4650))+16) = (OOC_INT32)0;
l11:
  return;
  ;
}

static OOC_CHAR8 ADT_Dictionary_IntValue__IsSet(Object__Object key) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)key;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l3;
  i0=0u;
  goto l4;
l3:
  i1 = (OOC_INT32)ADT_Dictionary_IntValue__dummy;
  i0 = i0!=i1;
  
l4:
  return i0;
  ;
}

static OOC_INT32 ADT_Dictionary_IntValue__Lookup(ADT_Dictionary_IntValue__Dictionary dict, Object__Object key, OOC_INT32 hash) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
  ADT_Dictionary_IntValue__Table t;
  OOC_UINT32 mask;
  OOC_INT32 i;
  OOC_INT32 freeslot;
  OOC_INT32 incr;

  i0 = (OOC_INT32)dict;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6086))+16);
  t = (ADT_Dictionary_IntValue__Table)i1;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 6123))+8);
  i3 = hash;
  i4 = _type_cast_fast(OOC_UINT32, OOC_INT32, i3);
  i2 = _type_cast_fast(OOC_UINT32, OOC_INT32, (i2-1));
  mask = i2;
  i5 = _type_cast_fast(OOC_INT32, OOC_UINT32, ((~i4)&i2));
  i = i5;
  i6 = _check_pointer(i1, 6196);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((i6+((_check_index(i5, i7, OOC_UINT32, 6196))*12))+4);
  i6 = i6==(OOC_INT32)0;
  if (i6) goto l3;
  i6 = _check_pointer(i1, 6217);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((i6+((_check_index(i5, i7, OOC_UINT32, 6217))*12))+4);
  i7 = (OOC_INT32)key;
  i6 = i6==i7;
  
  goto l4;
l3:
  i6=1u;
l4:
  i7 = (OOC_INT32)key;
  if (i6) goto l19;
  i6 = _check_pointer(i1, 6265);
  i8 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((i6+((_check_index(i5, i8, OOC_UINT32, 6265))*12))+4);
  i8 = (OOC_INT32)ADT_Dictionary_IntValue__dummy;
  i6 = i6==i8;
  if (i6) goto l17;
  i6 = _check_pointer(i1, 6320);
  i8 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = *(OOC_INT32*)(i6+((_check_index(i5, i8, OOC_UINT32, 6320))*12));
  i6 = i6==i3;
  if (i6) goto l11;
  i6=0u;
  goto l13;
l11:
  i6 = _check_pointer(i1, 6354);
  i8 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((i6+((_check_index(i5, i8, OOC_UINT32, 6354))*12))+4);
  i6 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 6343)))), Object__ObjectDesc_Equals)),Object__ObjectDesc_Equals)((Object__Object)i7, (Object__Object)i6);
  
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
  i4 = *(OOC_INT32*)((_check_pointer(i0, 6556))+8);
  i4 = i4-1;
  incr = i4;
  
l24:
  {register OOC_INT32 h0=i4;i4=i5;i5=h0;}
l25_loop:
  i4 = _type_cast_fast(OOC_INT32, OOC_UINT32, ((_type_cast_fast(OOC_UINT32, OOC_INT32, (i4+i5)))&i2));
  i = i4;
  i6 = _check_pointer(i1, 6649);
  i8 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((i6+((_check_index(i4, i8, OOC_UINT32, 6649))*12))+4);
  i6 = i6==(OOC_INT32)0;
  if (i6) goto l42;
  i6 = _check_pointer(i1, 6786);
  i8 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((i6+((_check_index(i4, i8, OOC_UINT32, 6786))*12))+4);
  i8 = (OOC_INT32)ADT_Dictionary_IntValue__dummy;
  i6 = i6==i8;
  if (i6) goto l37;
  i6 = _check_pointer(i1, 6890);
  i8 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = *(OOC_INT32*)(i6+((_check_index(i4, i8, OOC_UINT32, 6890))*12));
  i6 = i6==i3;
  if (i6) goto l32;
  i6=0u;
  goto l34;
l32:
  i6 = _check_pointer(i1, 6924);
  i8 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((i6+((_check_index(i4, i8, OOC_UINT32, 6924))*12))+4);
  i6 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 6913)))), Object__ObjectDesc_Equals)),Object__ObjectDesc_Equals)((Object__Object)i7, (Object__Object)i6);
  
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
  i6 = *(OOC_INT32*)((_check_pointer(i0, 7011))+8);
  i6 = i5>=i6;
  if (!i6) goto l25_loop;
  i6 = *(OOC_INT32*)((_check_pointer(i0, 7092))+12);
  i5 = _type_cast_fast(OOC_INT32, OOC_UINT32, ((_type_cast_fast(OOC_UINT32, OOC_INT32, i5))^(_type_cast_fast(OOC_UINT32, OOC_INT32, i6))));
  incr = i5;
  
  goto l25_loop;
l53:
  ;
}

static void ADT_Dictionary_IntValue__Insert(ADT_Dictionary_IntValue__Dictionary dict, Object__Object key, OOC_INT32 hash, OOC_INT32 value) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT32 i;

  i0 = hash;
  i1 = (OOC_INT32)key;
  i2 = (OOC_INT32)dict;
  i3 = ADT_Dictionary_IntValue__Lookup((ADT_Dictionary_IntValue__Dictionary)i2, (Object__Object)i1, i0);
  i = i3;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 7487))+16);
  i4 = _check_pointer(i4, 7494);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 7494))*12))+4);
  i4 = ADT_Dictionary_IntValue__IsSet((Object__Object)i4);
  if (i4) goto l6;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 7654))+16);
  i4 = _check_pointer(i4, 7661);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 7661))*12))+4);
  i4 = i4==(OOC_INT32)0;
  if (!i4) goto l5;
  i4 = *(OOC_INT32*)(_check_pointer(i2, 7699));
  *(OOC_INT32*)(_check_pointer(i2, 7699)) = (i4+1);
l5:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 7728))+16);
  i4 = _check_pointer(i4, 7735);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  *(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 7735))*12))+4) = i1;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 7762))+16);
  i1 = _check_pointer(i1, 7769);
  i4 = OOC_ARRAY_LENGTH(i1, 0);
  *(OOC_INT32*)(i1+((_check_index(i3, i4, OOC_UINT32, 7769))*12)) = i0;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 7798))+16);
  i0 = _check_pointer(i0, 7805);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  i4 = value;
  *(OOC_INT32*)((i0+((_check_index(i3, i1, OOC_UINT32, 7805))*12))+8) = i4;
  i0 = *(OOC_INT32*)((_check_pointer(i2, 7841))+4);
  *(OOC_INT32*)((_check_pointer(i2, 7841))+4) = (i0+1);
  goto l7;
l6:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 7546))+16);
  i0 = _check_pointer(i0, 7553);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  i2 = value;
  *(OOC_INT32*)((i0+((_check_index(i3, i1, OOC_UINT32, 7553))*12))+8) = i2;
l7:
  return;
  ;
}

static void ADT_Dictionary_IntValue__Resize(ADT_Dictionary_IntValue__Dictionary dict, OOC_INT32 minUsed) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9;
  OOC_INT32 oldSize;
  ADT_Dictionary_IntValue__Table oldTable;
  OOC_INT32 i;
  OOC_INT32 newSize;
  OOC_INT32 newPoly;
  ADT_Dictionary_IntValue__Table newTable;

  i0 = (OOC_INT32)dict;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 8245))+8);
  oldSize = i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8273))+16);
  oldTable = (ADT_Dictionary_IntValue__Table)i2;
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
  i3 = *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_IntValue__polys+(_check_index(i3, 29, OOC_UINT32, 8426))*4);
  newPoly = i3;
  i5 = (OOC_INT32)RT0__NewObject(_td_ADT_Dictionary_IntValue__Table.baseTypes[0], i4);
  newTable = (ADT_Dictionary_IntValue__Table)i5;
  i = 0;
  i6 = 0<i4;
  if (!i6) goto l17;
  i6=0;
l12_loop:
  i7 = _check_pointer(i5, 8565);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  *(OOC_INT32*)((i7+((_check_index(i6, i8, OOC_UINT32, 8565))*12))+4) = (OOC_INT32)0;
  i7 = _check_pointer(i5, 8596);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  *(OOC_INT32*)((i7+((_check_index(i6, i8, OOC_UINT32, 8596))*12))+8) = 0;
  i7 = _check_pointer(i5, 8627);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  *(OOC_INT32*)(i7+((_check_index(i6, i8, OOC_UINT32, 8627))*12)) = 0;
  i6 = i6+1;
  i = i6;
  i7 = i6<i4;
  if (i7) goto l12_loop;
l17:
  *(OOC_INT32*)((_check_pointer(i0, 8659))+8) = i4;
  *(OOC_INT32*)((_check_pointer(i0, 8686))+12) = i3;
  *(OOC_INT32*)((_check_pointer(i0, 8713))+16) = i5;
  *(OOC_INT32*)(_check_pointer(i0, 8742)) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 8763))+4) = 0;
  i = 0;
  i3 = 0<i1;
  if (!i3) goto l28;
  i3=0;
l20_loop:
  i4 = _check_pointer(i2, 8836);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 8836))*12))+4);
  i4 = ADT_Dictionary_IntValue__IsSet((Object__Object)i4);
  if (!i4) goto l23;
  i4 = _check_pointer(i2, 8918);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = _check_pointer(i2, 8899);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i8 = _check_pointer(i2, 8881);
  i9 = OOC_ARRAY_LENGTH(i8, 0);
  i4 = *(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 8918))*12))+8);
  i5 = (OOC_INT32)*(OOC_INT32*)((i8+((_check_index(i3, i9, OOC_UINT32, 8881))*12))+4);
  i6 = *(OOC_INT32*)(i6+((_check_index(i3, i7, OOC_UINT32, 8899))*12));
  ADT_Dictionary_IntValue__Insert((ADT_Dictionary_IntValue__Dictionary)i0, (Object__Object)i5, i6, i4);
  i4 = _check_pointer(i2, 8947);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  *(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 8947))*12))+4) = (OOC_INT32)0;
  i4 = _check_pointer(i2, 9008);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  *(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 9008))*12))+8) = 0;
l23:
  i3 = i3+1;
  i = i3;
  i4 = i3<i1;
  if (i4) goto l20_loop;
l28:
  return;
  ;
}

OOC_CHAR8 ADT_Dictionary_IntValue__DictionaryDesc_HasKey(ADT_Dictionary_IntValue__Dictionary dict, Object__Object key) {
  register OOC_INT32 i0,i1,i2;
  OOC_INT32 index;

  i0 = (OOC_INT32)dict;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 9302))+4);
  i1 = i1==0;
  if (i1) goto l3;
  i1 = (OOC_INT32)key;
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9384)))), Object__ObjectDesc_HashCode)),Object__ObjectDesc_HashCode)((Object__Object)i1);
  i1 = ADT_Dictionary_IntValue__Lookup((ADT_Dictionary_IntValue__Dictionary)i0, (Object__Object)i1, i2);
  index = i1;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9423))+16);
  i0 = _check_pointer(i0, 9430);
  i2 = OOC_ARRAY_LENGTH(i0, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)((i0+((_check_index(i1, i2, OOC_UINT32, 9430))*12))+4);
  i0 = ADT_Dictionary_IntValue__IsSet((Object__Object)i0);
  return i0;
  goto l4;
l3:
  return 0u;
l4:
  _failed_function(9088); return 0;
  ;
}

OOC_INT32 ADT_Dictionary_IntValue__DictionaryDesc_Size(ADT_Dictionary_IntValue__Dictionary dict) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)dict;
  i0 = *(OOC_INT32*)((_check_pointer(i0, 9592))+4);
  return i0;
  ;
}

OOC_INT32 ADT_Dictionary_IntValue__DictionaryDesc_Get(ADT_Dictionary_IntValue__Dictionary dict, Object__Object key) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_INT32 i;

  i0 = (OOC_INT32)key;
  _assert((i0!=(OOC_INT32)0), 127, 9950);
  i1 = (OOC_INT32)dict;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 9986))+4);
  _assert((i2!=0), 127, 9974);
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10030)))), Object__ObjectDesc_HashCode)),Object__ObjectDesc_HashCode)((Object__Object)i0);
  i0 = ADT_Dictionary_IntValue__Lookup((ADT_Dictionary_IntValue__Dictionary)i1, (Object__Object)i0, i2);
  i = i0;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 10068))+16);
  i2 = _check_pointer(i2, 10075);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)((i2+((_check_index(i0, i3, OOC_UINT32, 10075))*12))+4);
  i2 = ADT_Dictionary_IntValue__IsSet((Object__Object)i2);
  _assert(i2, 127, 10049);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 10102))+16);
  i1 = _check_pointer(i1, 10109);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i0 = *(OOC_INT32*)((i1+((_check_index(i0, i2, OOC_UINT32, 10109))*12))+8);
  return i0;
  ;
}

void ADT_Dictionary_IntValue__DictionaryDesc_Set(ADT_Dictionary_IntValue__Dictionary dict, Object__Object key, OOC_INT32 value) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)key;
  _assert((i0!=(OOC_INT32)0), 127, 10522);
  i1 = (OOC_INT32)dict;
  i2 = *(OOC_INT32*)(_check_pointer(i1, 10554));
  i3 = *(OOC_INT32*)((_check_pointer(i1, 10570))+8);
  i2 = (i2*3)>=(i3*2);
  if (!i2) goto l4;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 10609))+4);
  ADT_Dictionary_IntValue__Resize((ADT_Dictionary_IntValue__Dictionary)i1, (i2*2));
l4:
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10654)))), Object__ObjectDesc_HashCode)),Object__ObjectDesc_HashCode)((Object__Object)i0);
  i3 = value;
  ADT_Dictionary_IntValue__Insert((ADT_Dictionary_IntValue__Dictionary)i1, (Object__Object)i0, i2, i3);
  return;
  ;
}

ADT_Dictionary_IntValue__Dictionary ADT_Dictionary_IntValue__DictionaryDesc_Copy(ADT_Dictionary_IntValue__Dictionary dict) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9;
  ADT_Dictionary_IntValue__Dictionary copy;
  OOC_INT32 i;

  i0 = (OOC_INT32)ADT_Dictionary_IntValue__New();
  copy = (ADT_Dictionary_IntValue__Dictionary)i0;
  i1 = (OOC_INT32)dict;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 11808))+4);
  i2 = i2>0;
  if (!i2) goto l14;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 11850))+4);
  ADT_Dictionary_IntValue__Resize((ADT_Dictionary_IntValue__Dictionary)i0, ((i2*3)>>1));
  i2 = *(OOC_INT32*)((_check_pointer(i1, 11892))+8);
  i = 0;
  i3 = 0<i2;
  if (!i3) goto l14;
  i3=0;
l5_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11926))+16);
  i4 = _check_pointer(i4, 11933);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 11933))*12))+4);
  i4 = ADT_Dictionary_IntValue__IsSet((Object__Object)i4);
  if (!i4) goto l8;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12037))+16);
  i4 = _check_pointer(i4, 12044);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11997))+16);
  i6 = _check_pointer(i6, 12004);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11976))+16);
  i8 = _check_pointer(i8, 11983);
  i9 = OOC_ARRAY_LENGTH(i8, 0);
  i4 = *(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 12044))*12))+8);
  i5 = (OOC_INT32)*(OOC_INT32*)((i8+((_check_index(i3, i9, OOC_UINT32, 11983))*12))+4);
  i6 = *(OOC_INT32*)(i6+((_check_index(i3, i7, OOC_UINT32, 12004))*12));
  ADT_Dictionary_IntValue__Insert((ADT_Dictionary_IntValue__Dictionary)i0, (Object__Object)i5, i6, i4);
l8:
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l5_loop;
l14:
  return (ADT_Dictionary_IntValue__Dictionary)i0;
  ;
}

void ADT_Dictionary_IntValue__DictionaryDesc_Delete(ADT_Dictionary_IntValue__Dictionary dict, Object__Object key) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_INT32 i;

  i0 = (OOC_INT32)key;
  _assert((i0!=(OOC_INT32)0), 127, 12447);
  i1 = (OOC_INT32)dict;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 12483))+4);
  _assert((i2!=0), 127, 12471);
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12527)))), Object__ObjectDesc_HashCode)),Object__ObjectDesc_HashCode)((Object__Object)i0);
  i0 = ADT_Dictionary_IntValue__Lookup((ADT_Dictionary_IntValue__Dictionary)i1, (Object__Object)i0, i2);
  i = i0;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12565))+16);
  i2 = _check_pointer(i2, 12572);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)((i2+((_check_index(i0, i3, OOC_UINT32, 12572))*12))+4);
  i2 = ADT_Dictionary_IntValue__IsSet((Object__Object)i2);
  _assert(i2, 127, 12546);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12592))+16);
  i2 = _check_pointer(i2, 12599);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i4 = (OOC_INT32)ADT_Dictionary_IntValue__dummy;
  *(OOC_INT32*)((i2+((_check_index(i0, i3, OOC_UINT32, 12599))*12))+4) = i4;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12672))+16);
  i2 = _check_pointer(i2, 12679);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  *(OOC_INT32*)((i2+((_check_index(i0, i3, OOC_UINT32, 12679))*12))+8) = 0;
  i0 = *(OOC_INT32*)((_check_pointer(i1, 12709))+4);
  *(OOC_INT32*)((_check_pointer(i1, 12709))+4) = (i0-1);
  return;
  ;
}

void ADT_Dictionary_IntValue__DictionaryDesc_Clear(ADT_Dictionary_IntValue__Dictionary dict) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_INT32 i;

  i0 = (OOC_INT32)dict;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12871))+16);
  i1 = i1!=(OOC_INT32)0;
  if (!i1) goto l11;
  i = 0;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 12915))+8);
  i2 = 0<i1;
  if (!i2) goto l10;
  i2=0;
l5_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12978))+16);
  i3 = _check_pointer(i3, 12985);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)((i3+((_check_index(i2, i4, OOC_UINT32, 12985))*12))+4) = (OOC_INT32)0;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13014))+16);
  i3 = _check_pointer(i3, 13021);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)((i3+((_check_index(i2, i4, OOC_UINT32, 13021))*12))+8) = 0;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13050))+16);
  i3 = _check_pointer(i3, 13057);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)(i3+((_check_index(i2, i4, OOC_UINT32, 13057))*12)) = 0;
  i2 = i2+1;
  i = i2;
  i3 = i2<i1;
  if (i3) goto l5_loop;
l10:
  ADT_Dictionary_IntValue__Init((ADT_Dictionary_IntValue__Dictionary)i0);
l11:
  return;
  ;
}

Object__ObjectArrayPtr ADT_Dictionary_IntValue__DictionaryDesc_Keys(ADT_Dictionary_IntValue__Dictionary dict) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
  Object__ObjectArrayPtr list;
  OOC_INT32 j;
  OOC_INT32 i;

  i0 = (OOC_INT32)dict;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 13384))+4);
  i1 = (OOC_INT32)RT0__NewObject(_td_Object__ObjectArrayPtr.baseTypes[0], i1);
  list = (Object__ObjectArrayPtr)i1;
  j = 0;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 13427))+8);
  i = 0;
  i3 = 0<i2;
  if (i3) goto l3;
  i2=0;
  goto l13;
l3:
  i3=0;i4=0;
l4_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13459))+16);
  i5 = _check_pointer(i5, 13466);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)((i5+((_check_index(i3, i6, OOC_UINT32, 13466))*12))+4);
  i5 = ADT_Dictionary_IntValue__IsSet((Object__Object)i5);
  if (!i5) goto l8;
  i5 = _check_pointer(i1, 13493);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13504))+16);
  i7 = _check_pointer(i7, 13511);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)((i7+((_check_index(i3, i8, OOC_UINT32, 13511))*12))+4);
  *(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 13493))*4) = i7;
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
  i0 = *(OOC_INT32*)((_check_pointer(i0, 13576))+4);
  _assert((i2==i0), 127, 13560);
  return (Object__ObjectArrayPtr)i1;
  ;
}

void ADT_Dictionary_IntValue__DictionaryDesc_Store(ADT_Dictionary_IntValue__Dictionary dict, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT32 i;

  i0 = (OOC_INT32)dict;
  i1 = (OOC_INT32)w;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 14256))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14240)))), IO_BinaryRider__WriterDesc_WriteNum)),IO_BinaryRider__WriterDesc_WriteNum)((IO_BinaryRider__Writer)i1, i2);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 14277))+4);
  i2 = i2!=0;
  if (!i2) goto l14;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 14318))+8);
  i = 0;
  i3 = 0<i2;
  if (!i3) goto l14;
  i3=0;
l5_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14352))+16);
  i4 = _check_pointer(i4, 14359);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 14359))*12))+4);
  i4 = ADT_Dictionary_IntValue__IsSet((Object__Object)i4);
  if (!i4) goto l8;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14404))+16);
  i4 = _check_pointer(i4, 14411);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 14411))*12))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14385)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i1, (Object__Object)i4);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14449))+16);
  i4 = _check_pointer(i4, 14456);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = *(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 14456))*12))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14433)))), IO_BinaryRider__WriterDesc_WriteNum)),IO_BinaryRider__WriterDesc_WriteNum)((IO_BinaryRider__Writer)i1, i4);
l8:
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l5_loop;
l14:
  return;
  ;
}

void ADT_Dictionary_IntValue__DictionaryDesc_Load(ADT_Dictionary_IntValue__Dictionary dict, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9;
  OOC_INT32 i;
  Object__Object obj;

  i0 = (OOC_INT32)dict;
  ADT_Dictionary_IntValue__Init((ADT_Dictionary_IntValue__Dictionary)i0);
  i1 = (OOC_INT32)r;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14661)))), IO_BinaryRider__ReaderDesc_ReadNum)),IO_BinaryRider__ReaderDesc_ReadNum)((IO_BinaryRider__Reader)i1, (void*)((_check_pointer(i0, 14676))+8));
  i2 = *(OOC_INT32*)((_check_pointer(i0, 14697))+8);
  i2 = i2!=0;
  if (!i2) goto l11;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 14875))+8);
  *(OOC_INT32*)((_check_pointer(i0, 14862))+16) = ((OOC_INT32)RT0__NewObject(_td_ADT_Dictionary_IntValue__Table.baseTypes[0], i2));
  i = 0;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 14908))+8);
  i3 = 0<i2;
  if (!i3) goto l10;
  i3=0;
l5_loop:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14929)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i1, (void*)(OOC_INT32)&obj);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14961))+16);
  i4 = _check_pointer(i4, 14968);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)obj;
  *(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 14968))*12))+4) = i6;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15009))+16);
  i4 = _check_pointer(i4, 15016);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14994)))), IO_BinaryRider__ReaderDesc_ReadNum)),IO_BinaryRider__ReaderDesc_ReadNum)((IO_BinaryRider__Reader)i1, (void*)((i4+((_check_index(i3, i5, OOC_UINT32, 15016))*12))+8));
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15041))+16);
  i4 = _check_pointer(i4, 15048);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15065))+16);
  i6 = _check_pointer(i6, 15072);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15065))+16);
  i8 = _check_pointer(i8, 15072);
  i9 = OOC_ARRAY_LENGTH(i8, 0);
  i8 = (OOC_INT32)*(OOC_INT32*)((i8+((_check_index(i3, i9, OOC_UINT32, 15072))*12))+4);
  i6 = (OOC_INT32)*(OOC_INT32*)((i6+((_check_index(i3, i7, OOC_UINT32, 15072))*12))+4);
  i6 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i8, 15080)))), Object__ObjectDesc_HashCode)),Object__ObjectDesc_HashCode)((Object__Object)i6);
  *(OOC_INT32*)(i4+((_check_index(i3, i5, OOC_UINT32, 15048))*12)) = i6;
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l5_loop;
l10:
  i1 = *(OOC_INT32*)((_check_pointer(i0, 15129))+8);
  ADT_Dictionary_IntValue__Resize((ADT_Dictionary_IntValue__Dictionary)i0, ((i1*3)>>1));
l11:
  return;
  ;
}

void OOC_ADT_Dictionary_IntValue_init(void) {

  ADT_Dictionary_IntValue__dummy = (ADT_Dictionary_IntValue__Dummy)((OOC_INT32)RT0__NewObject(_td_ADT_Dictionary_IntValue__Dummy.baseTypes[0]));
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_IntValue__polys+(_check_index(0, 29, OOC_UINT8, 15198))*4) = 7;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_IntValue__polys+(_check_index(1, 29, OOC_UINT8, 15219))*4) = 11;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_IntValue__polys+(_check_index(2, 29, OOC_UINT8, 15240))*4) = 19;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_IntValue__polys+(_check_index(3, 29, OOC_UINT8, 15262))*4) = 37;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_IntValue__polys+(_check_index(4, 29, OOC_UINT8, 15284))*4) = 67;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_IntValue__polys+(_check_index(5, 29, OOC_UINT8, 15306))*4) = 131;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_IntValue__polys+(_check_index(6, 29, OOC_UINT8, 15329))*4) = 285;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_IntValue__polys+(_check_index(7, 29, OOC_UINT8, 15353))*4) = 529;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_IntValue__polys+(_check_index(8, 29, OOC_UINT8, 15377))*4) = 1033;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_IntValue__polys+(_check_index(9, 29, OOC_UINT8, 15401))*4) = 2053;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_IntValue__polys+(_check_index(10, 29, OOC_UINT8, 15425))*4) = 4179;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_IntValue__polys+(_check_index(11, 29, OOC_UINT8, 15451))*4) = 8219;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_IntValue__polys+(_check_index(12, 29, OOC_UINT8, 15477))*4) = 16427;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_IntValue__polys+(_check_index(13, 29, OOC_UINT8, 15504))*4) = 32771;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_IntValue__polys+(_check_index(14, 29, OOC_UINT8, 15530))*4) = 65581;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_IntValue__polys+(_check_index(15, 29, OOC_UINT8, 15557))*4) = 131081;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_IntValue__polys+(_check_index(16, 29, OOC_UINT8, 15584))*4) = 262183;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_IntValue__polys+(_check_index(17, 29, OOC_UINT8, 15612))*4) = 524327;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_IntValue__polys+(_check_index(18, 29, OOC_UINT8, 15640))*4) = 1048585;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_IntValue__polys+(_check_index(19, 29, OOC_UINT8, 15668))*4) = 2097157;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_IntValue__polys+(_check_index(20, 29, OOC_UINT8, 15696))*4) = 4194307;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_IntValue__polys+(_check_index(21, 29, OOC_UINT8, 15724))*4) = 8388641;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_IntValue__polys+(_check_index(22, 29, OOC_UINT8, 15753))*4) = 16777243;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_IntValue__polys+(_check_index(23, 29, OOC_UINT8, 15783))*4) = 33554441;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_IntValue__polys+(_check_index(24, 29, OOC_UINT8, 15812))*4) = 67108935;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_IntValue__polys+(_check_index(25, 29, OOC_UINT8, 15842))*4) = 134217767;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_IntValue__polys+(_check_index(26, 29, OOC_UINT8, 15873))*4) = 268435465;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_IntValue__polys+(_check_index(27, 29, OOC_UINT8, 15903))*4) = 536870917;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary_IntValue__polys+(_check_index(28, 29, OOC_UINT8, 15933))*4) = 1073741907;
  return;
  ;
}

void OOC_ADT_Dictionary_IntValue_destroy(void) {
}

/* --- */
