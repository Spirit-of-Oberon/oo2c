#include <ADT/Dictionary.d>
#include <__oo2c.h>
#include <setjmp.h>

void ADT_Dictionary__DictionaryDesc_INIT(ADT_Dictionary__Dictionary dict) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)dict;
  *(OOC_INT32*)((_check_pointer(i0, 4900))+8) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 4921))+12) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 4942))+16) = (OOC_INT32)0;
  *(OOC_INT32*)(_check_pointer(i0, 4966)) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 4987))+4) = 0;
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
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5219))+16);
  i1 = i1!=(OOC_INT32)0;
  if (!i1) goto l11;
  i = 0;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 5263))+8);
  i2 = 0<i1;
  if (!i2) goto l10;
  i2=0;
l5_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5326))+16);
  i3 = _check_pointer(i3, 5333);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)((i3+((_check_index(i2, i4, OOC_UINT32, 5333))*12))+4) = (OOC_INT32)0;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5362))+16);
  i3 = _check_pointer(i3, 5369);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)((i3+((_check_index(i2, i4, OOC_UINT32, 5369))*12))+8) = (OOC_INT32)0;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5400))+16);
  i3 = _check_pointer(i3, 5407);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)(i3+((_check_index(i2, i4, OOC_UINT32, 5407))*12)) = 0;
  i2 = i2+1;
  i = i2;
  i3 = i2<i1;
  if (i3) goto l5_loop;
l10:
  *(OOC_INT32*)((_check_pointer(i0, 5443))+16) = (OOC_INT32)0;
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

OOC_INT32 ADT_Dictionary__DictionaryDesc_Lookup(ADT_Dictionary__Dictionary dict, Object__Object key, OOC_INT32 hash) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
  ADT_Dictionary__Table t;
  OOC_UINT32 mask;
  OOC_INT32 i;
  OOC_INT32 freeslot;
  OOC_INT32 incr;

  i0 = (OOC_INT32)dict;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6890))+16);
  t = (ADT_Dictionary__Table)i1;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 6927))+8);
  i3 = hash;
  i4 = _type_cast_fast(OOC_UINT32, OOC_INT32, i3);
  i2 = _type_cast_fast(OOC_UINT32, OOC_INT32, (i2-1));
  mask = i2;
  i5 = _type_cast_fast(OOC_INT32, OOC_UINT32, ((~i4)&i2));
  i = i5;
  i6 = _check_pointer(i1, 7000);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((i6+((_check_index(i5, i7, OOC_UINT32, 7000))*12))+4);
  i6 = i6==(OOC_INT32)0;
  if (i6) goto l3;
  i6 = _check_pointer(i1, 7021);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((i6+((_check_index(i5, i7, OOC_UINT32, 7021))*12))+4);
  i7 = (OOC_INT32)key;
  i6 = i6==i7;
  
  goto l4;
l3:
  i6=1u;
l4:
  i7 = (OOC_INT32)key;
  if (i6) goto l19;
  i6 = _check_pointer(i1, 7069);
  i8 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((i6+((_check_index(i5, i8, OOC_UINT32, 7069))*12))+4);
  i8 = (OOC_INT32)ADT_Dictionary__dummy;
  i6 = i6==i8;
  if (i6) goto l17;
  i6 = _check_pointer(i1, 7124);
  i8 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = *(OOC_INT32*)(i6+((_check_index(i5, i8, OOC_UINT32, 7124))*12));
  i6 = i6==i3;
  if (i6) goto l11;
  i6=0u;
  goto l13;
l11:
  i6 = _check_pointer(i1, 7158);
  i8 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((i6+((_check_index(i5, i8, OOC_UINT32, 7158))*12))+4);
  i6 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 7147)))), Object__ObjectDesc_Equals)),Object__ObjectDesc_Equals)((Object__Object)i7, (Object__Object)i6);
  
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
  i4 = *(OOC_INT32*)((_check_pointer(i0, 7360))+8);
  i4 = i4-1;
  incr = i4;
  
l24:
  {register OOC_INT32 h0=i4;i4=i5;i5=h0;}
l25_loop:
  i4 = _type_cast_fast(OOC_INT32, OOC_UINT32, ((_type_cast_fast(OOC_UINT32, OOC_INT32, (i4+i5)))&i2));
  i = i4;
  i6 = _check_pointer(i1, 7453);
  i8 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((i6+((_check_index(i4, i8, OOC_UINT32, 7453))*12))+4);
  i6 = i6==(OOC_INT32)0;
  if (i6) goto l42;
  i6 = _check_pointer(i1, 7590);
  i8 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((i6+((_check_index(i4, i8, OOC_UINT32, 7590))*12))+4);
  i8 = (OOC_INT32)ADT_Dictionary__dummy;
  i6 = i6==i8;
  if (i6) goto l37;
  i6 = _check_pointer(i1, 7694);
  i8 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = *(OOC_INT32*)(i6+((_check_index(i4, i8, OOC_UINT32, 7694))*12));
  i6 = i6==i3;
  if (i6) goto l32;
  i6=0u;
  goto l34;
l32:
  i6 = _check_pointer(i1, 7728);
  i8 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((i6+((_check_index(i4, i8, OOC_UINT32, 7728))*12))+4);
  i6 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 7717)))), Object__ObjectDesc_Equals)),Object__ObjectDesc_Equals)((Object__Object)i7, (Object__Object)i6);
  
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
  i6 = *(OOC_INT32*)((_check_pointer(i0, 7815))+8);
  i6 = i5>=i6;
  if (!i6) goto l25_loop;
  i6 = *(OOC_INT32*)((_check_pointer(i0, 7896))+12);
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
  i3 = ADT_Dictionary__DictionaryDesc_Lookup((ADT_Dictionary__Dictionary)i2, (Object__Object)i1, i0);
  i = i3;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 8272))+16);
  i4 = _check_pointer(i4, 8279);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 8279))*12))+4);
  i4 = ADT_Dictionary__IsSet((Object__Object)i4);
  if (i4) goto l6;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 8439))+16);
  i4 = _check_pointer(i4, 8446);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 8446))*12))+4);
  i4 = i4==(OOC_INT32)0;
  if (!i4) goto l5;
  i4 = *(OOC_INT32*)(_check_pointer(i2, 8484));
  *(OOC_INT32*)(_check_pointer(i2, 8484)) = (i4+1);
l5:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 8513))+16);
  i4 = _check_pointer(i4, 8520);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  *(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 8520))*12))+4) = i1;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 8547))+16);
  i1 = _check_pointer(i1, 8554);
  i4 = OOC_ARRAY_LENGTH(i1, 0);
  *(OOC_INT32*)(i1+((_check_index(i3, i4, OOC_UINT32, 8554))*12)) = i0;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 8583))+16);
  i0 = _check_pointer(i0, 8590);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  i4 = (OOC_INT32)value;
  *(OOC_INT32*)((i0+((_check_index(i3, i1, OOC_UINT32, 8590))*12))+8) = i4;
  i0 = *(OOC_INT32*)((_check_pointer(i2, 8626))+4);
  *(OOC_INT32*)((_check_pointer(i2, 8626))+4) = (i0+1);
  goto l7;
l6:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 8331))+16);
  i0 = _check_pointer(i0, 8338);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  i2 = (OOC_INT32)value;
  *(OOC_INT32*)((i0+((_check_index(i3, i1, OOC_UINT32, 8338))*12))+8) = i2;
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
  i1 = *(OOC_INT32*)((_check_pointer(i0, 9043))+8);
  oldSize = i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9071))+16);
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
  i3 = *(OOC_INT32*)((OOC_INT32)ADT_Dictionary__polys+(_check_index(i3, 29, OOC_UINT32, 9224))*4);
  newPoly = i3;
  i5 = (OOC_INT32)RT0__NewObject(_td_ADT_Dictionary__Table.baseTypes[0], i4);
  newTable = (ADT_Dictionary__Table)i5;
  i = 0;
  i6 = 0<i4;
  if (!i6) goto l17;
  i6=0;
l12_loop:
  i7 = _check_pointer(i5, 9363);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  *(OOC_INT32*)((i7+((_check_index(i6, i8, OOC_UINT32, 9363))*12))+4) = (OOC_INT32)0;
  i7 = _check_pointer(i5, 9394);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  *(OOC_INT32*)((i7+((_check_index(i6, i8, OOC_UINT32, 9394))*12))+8) = (OOC_INT32)0;
  i7 = _check_pointer(i5, 9427);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  *(OOC_INT32*)(i7+((_check_index(i6, i8, OOC_UINT32, 9427))*12)) = 0;
  i6 = i6+1;
  i = i6;
  i7 = i6<i4;
  if (i7) goto l12_loop;
l17:
  *(OOC_INT32*)((_check_pointer(i0, 9459))+8) = i4;
  *(OOC_INT32*)((_check_pointer(i0, 9486))+12) = i3;
  *(OOC_INT32*)((_check_pointer(i0, 9513))+16) = i5;
  *(OOC_INT32*)(_check_pointer(i0, 9542)) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 9563))+4) = 0;
  i = 0;
  i3 = 0<i1;
  if (!i3) goto l28;
  i3=0;
l20_loop:
  i4 = _check_pointer(i2, 9636);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 9636))*12))+4);
  i4 = ADT_Dictionary__IsSet((Object__Object)i4);
  if (!i4) goto l23;
  i4 = _check_pointer(i2, 9716);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = _check_pointer(i2, 9697);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i8 = _check_pointer(i2, 9679);
  i9 = OOC_ARRAY_LENGTH(i8, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 9716))*12))+8);
  i5 = (OOC_INT32)*(OOC_INT32*)((i8+((_check_index(i3, i9, OOC_UINT32, 9679))*12))+4);
  i6 = *(OOC_INT32*)(i6+((_check_index(i3, i7, OOC_UINT32, 9697))*12));
  ADT_Dictionary__DictionaryDesc_Insert((ADT_Dictionary__Dictionary)i0, (Object__Object)i5, i6, (Object__Object)i4);
  i4 = _check_pointer(i2, 9745);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  *(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 9745))*12))+4) = (OOC_INT32)0;
  i4 = _check_pointer(i2, 9806);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  *(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 9806))*12))+8) = (OOC_INT32)0;
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
  i1 = *(OOC_INT32*)((_check_pointer(i0, 10106))+4);
  i1 = i1==0;
  if (i1) goto l3;
  i1 = (OOC_INT32)key;
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 10186)))), Object__ObjectDesc_HashCode)),Object__ObjectDesc_HashCode)((Object__Object)i1);
  i1 = ADT_Dictionary__DictionaryDesc_Lookup((ADT_Dictionary__Dictionary)i0, (Object__Object)i1, i2);
  index = i1;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10224))+16);
  i0 = _check_pointer(i0, 10231);
  i2 = OOC_ARRAY_LENGTH(i0, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)((i0+((_check_index(i1, i2, OOC_UINT32, 10231))*12))+4);
  i0 = ADT_Dictionary__IsSet((Object__Object)i0);
  return i0;
  goto l4;
l3:
  return 0u;
l4:
  _failed_function(9894); return 0;
  ;
}

OOC_INT32 ADT_Dictionary__DictionaryDesc_Size(ADT_Dictionary__Dictionary dict) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)dict;
  i0 = *(OOC_INT32*)((_check_pointer(i0, 10399))+4);
  return i0;
  ;
}

Object__Object ADT_Dictionary__DictionaryDesc_Get(ADT_Dictionary__Dictionary dict, Object__Object key) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_INT32 i;

  i0 = (OOC_INT32)key;
  _assert((i0!=(OOC_INT32)0), 127, 10757);
  i1 = (OOC_INT32)dict;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 10793))+4);
  _assert((i2!=0), 127, 10781);
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10835)))), Object__ObjectDesc_HashCode)),Object__ObjectDesc_HashCode)((Object__Object)i0);
  i0 = ADT_Dictionary__DictionaryDesc_Lookup((ADT_Dictionary__Dictionary)i1, (Object__Object)i0, i2);
  i = i0;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 10873))+16);
  i2 = _check_pointer(i2, 10880);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)((i2+((_check_index(i0, i3, OOC_UINT32, 10880))*12))+4);
  i2 = ADT_Dictionary__IsSet((Object__Object)i2);
  _assert(i2, 127, 10854);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 10907))+16);
  i1 = _check_pointer(i1, 10914);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)((i1+((_check_index(i0, i2, OOC_UINT32, 10914))*12))+8);
  return (Object__Object)i0;
  ;
}

void ADT_Dictionary__DictionaryDesc_Set(ADT_Dictionary__Dictionary dict, Object__Object key, Object__Object value) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)key;
  _assert((i0!=(OOC_INT32)0), 127, 11327);
  i1 = (OOC_INT32)dict;
  i2 = *(OOC_INT32*)(_check_pointer(i1, 11359));
  i3 = *(OOC_INT32*)((_check_pointer(i1, 11375))+8);
  i2 = (i2*3)>=(i3*2);
  if (!i2) goto l4;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 11412))+4);
  ADT_Dictionary__DictionaryDesc_Resize((ADT_Dictionary__Dictionary)i1, (i2*2));
l4:
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11455)))), Object__ObjectDesc_HashCode)),Object__ObjectDesc_HashCode)((Object__Object)i0);
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
  i2 = *(OOC_INT32*)((_check_pointer(i1, 11775))+4);
  i2 = i2>0;
  if (!i2) goto l14;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 11815))+4);
  ADT_Dictionary__DictionaryDesc_Resize((ADT_Dictionary__Dictionary)i0, ((i2*3)>>1));
  i2 = *(OOC_INT32*)((_check_pointer(i1, 11857))+8);
  i = 0;
  i3 = 0<i2;
  if (!i3) goto l14;
  i3=0;
l5_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11891))+16);
  i4 = _check_pointer(i4, 11898);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 11898))*12))+4);
  i4 = ADT_Dictionary__IsSet((Object__Object)i4);
  if (!i4) goto l8;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12000))+16);
  i4 = _check_pointer(i4, 12006);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11958))+16);
  i6 = _check_pointer(i6, 11964);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11939))+16);
  i8 = _check_pointer(i8, 11945);
  i9 = OOC_ARRAY_LENGTH(i8, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 12006))*12))+8);
  i5 = (OOC_INT32)*(OOC_INT32*)((i8+((_check_index(i3, i9, OOC_UINT32, 11945))*12))+4);
  i6 = *(OOC_INT32*)(i6+((_check_index(i3, i7, OOC_UINT32, 11964))*12));
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
  _assert((i0!=(OOC_INT32)0), 127, 12412);
  i1 = (OOC_INT32)dict;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 12448))+4);
  _assert((i2!=0), 127, 12436);
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12490)))), Object__ObjectDesc_HashCode)),Object__ObjectDesc_HashCode)((Object__Object)i0);
  i0 = ADT_Dictionary__DictionaryDesc_Lookup((ADT_Dictionary__Dictionary)i1, (Object__Object)i0, i2);
  i = i0;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12528))+16);
  i2 = _check_pointer(i2, 12535);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)((i2+((_check_index(i0, i3, OOC_UINT32, 12535))*12))+4);
  i2 = ADT_Dictionary__IsSet((Object__Object)i2);
  _assert(i2, 127, 12509);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12599))+16);
  i2 = _check_pointer(i2, 12605);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i4 = (OOC_INT32)ADT_Dictionary__dummy;
  *(OOC_INT32*)((i2+((_check_index(i0, i3, OOC_UINT32, 12605))*12))+4) = ((OOC_INT32)_type_cast_fast(OOC_INT32, OOC_INT32, i4));
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12641))+16);
  i2 = _check_pointer(i2, 12647);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  *(OOC_INT32*)((i2+((_check_index(i0, i3, OOC_UINT32, 12647))*12))+8) = (OOC_INT32)0;
  i0 = *(OOC_INT32*)((_check_pointer(i1, 12678))+4);
  *(OOC_INT32*)((_check_pointer(i1, 12678))+4) = (i0-1);
  return;
  ;
}

void ADT_Dictionary__DictionaryDesc_Clear(ADT_Dictionary__Dictionary dict) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_INT32 i;

  i0 = (OOC_INT32)dict;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12846))+16);
  i1 = i1!=(OOC_INT32)0;
  if (!i1) goto l11;
  i = 0;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 12890))+8);
  i2 = 0<i1;
  if (!i2) goto l10;
  i2=0;
l5_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12953))+16);
  i3 = _check_pointer(i3, 12960);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)((i3+((_check_index(i2, i4, OOC_UINT32, 12960))*12))+4) = (OOC_INT32)0;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12989))+16);
  i3 = _check_pointer(i3, 12996);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)((i3+((_check_index(i2, i4, OOC_UINT32, 12996))*12))+8) = (OOC_INT32)0;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13027))+16);
  i3 = _check_pointer(i3, 13034);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)(i3+((_check_index(i2, i4, OOC_UINT32, 13034))*12)) = 0;
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
  i1 = *(OOC_INT32*)((_check_pointer(i0, 13374))+4);
  i1 = (OOC_INT32)RT0__NewObject(_td_Object__ObjectArrayPtr.baseTypes[0], i1);
  list = (Object__ObjectArrayPtr)i1;
  j = 0;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 13417))+8);
  i = 0;
  i3 = 0<i2;
  if (i3) goto l3;
  i2=0;
  goto l13;
l3:
  i3=0;i4=0;
l4_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13449))+16);
  i5 = _check_pointer(i5, 13456);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)((i5+((_check_index(i3, i6, OOC_UINT32, 13456))*12))+4);
  i5 = ADT_Dictionary__IsSet((Object__Object)i5);
  if (!i5) goto l8;
  i5 = _check_pointer(i1, 13483);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13494))+16);
  i7 = _check_pointer(i7, 13501);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)((i7+((_check_index(i3, i8, OOC_UINT32, 13501))*12))+4);
  *(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 13483))*4) = i7;
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
  i0 = *(OOC_INT32*)((_check_pointer(i0, 13566))+4);
  _assert((i2==i0), 127, 13550);
  return (Object__ObjectArrayPtr)i1;
  ;
}

Object__ObjectArrayPtr ADT_Dictionary__DictionaryDesc_Values(ADT_Dictionary__Dictionary dict) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
  Object__ObjectArrayPtr list;
  OOC_INT32 j;
  OOC_INT32 i;

  i0 = (OOC_INT32)dict;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 13882))+4);
  i1 = (OOC_INT32)RT0__NewObject(_td_Object__ObjectArrayPtr.baseTypes[0], i1);
  list = (Object__ObjectArrayPtr)i1;
  j = 0;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 13925))+8);
  i = 0;
  i3 = 0<i2;
  if (i3) goto l3;
  i2=0;
  goto l13;
l3:
  i3=0;i4=0;
l4_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13957))+16);
  i5 = _check_pointer(i5, 13964);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)((i5+((_check_index(i3, i6, OOC_UINT32, 13964))*12))+4);
  i5 = ADT_Dictionary__IsSet((Object__Object)i5);
  if (!i5) goto l8;
  i5 = _check_pointer(i1, 13991);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14002))+16);
  i7 = _check_pointer(i7, 14009);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)((i7+((_check_index(i3, i8, OOC_UINT32, 14009))*12))+8);
  *(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 13991))*4) = i7;
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
  i0 = *(OOC_INT32*)((_check_pointer(i0, 14076))+4);
  _assert((i2==i0), 127, 14060);
  return (Object__ObjectArrayPtr)i1;
  ;
}

ADT_Dictionary__ItemArrayPtr ADT_Dictionary__DictionaryDesc_Items(ADT_Dictionary__Dictionary dict) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
  ADT_Dictionary__ItemArrayPtr list;
  OOC_INT32 j;
  OOC_INT32 i;

  i0 = (OOC_INT32)dict;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 14378))+4);
  i1 = (OOC_INT32)RT0__NewObject(_td_ADT_Dictionary__ItemArrayPtr.baseTypes[0], i1);
  list = (ADT_Dictionary__ItemArrayPtr)i1;
  j = 0;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 14420))+8);
  i = 0;
  i3 = 0<i2;
  if (i3) goto l3;
  i2=0;
  goto l13;
l3:
  i3=0;i4=0;
l4_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14451))+16);
  i5 = _check_pointer(i5, 14457);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)((i5+((_check_index(i3, i6, OOC_UINT32, 14457))*12))+4);
  i5 = ADT_Dictionary__IsSet((Object__Object)i5);
  if (!i5) goto l8;
  i5 = _check_pointer(i1, 14483);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14498))+16);
  i7 = _check_pointer(i7, 14504);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)((i7+((_check_index(i3, i8, OOC_UINT32, 14504))*12))+4);
  *(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 14483))*8) = i7;
  i5 = _check_pointer(i1, 14525);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14542))+16);
  i7 = _check_pointer(i7, 14548);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)((i7+((_check_index(i3, i8, OOC_UINT32, 14548))*12))+8);
  *(OOC_INT32*)((i5+(_check_index(i4, i6, OOC_UINT32, 14525))*8)+4) = i7;
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
  i0 = *(OOC_INT32*)((_check_pointer(i0, 14614))+4);
  _assert((i2==i0), 127, 14599);
  return (ADT_Dictionary__ItemArrayPtr)i1;
  ;
}

OOC_CHAR8 ADT_Dictionary__DictionaryDesc_Equals(ADT_Dictionary__Dictionary dict, Object__Object obj) {

  _assert(0u, 127, 14769);
  _failed_function(14689); 
  ;
}

OOC_INT32 ADT_Dictionary__DictionaryDesc_HashCode(ADT_Dictionary__Dictionary dict) {

  _assert(0u, 127, 14911);
  _failed_function(14843); 
  ;
}

void ADT_Dictionary__DictionaryDesc_Store(ADT_Dictionary__Dictionary dict, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT32 i;

  i0 = (OOC_INT32)dict;
  i1 = (OOC_INT32)w;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 15083))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15067)))), IO_BinaryRider__WriterDesc_WriteNum)),IO_BinaryRider__WriterDesc_WriteNum)((IO_BinaryRider__Writer)i1, i2);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 15104))+4);
  i2 = i2!=0;
  if (!i2) goto l14;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 15145))+8);
  i = 0;
  i3 = 0<i2;
  if (!i3) goto l14;
  i3=0;
l5_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15179))+16);
  i4 = _check_pointer(i4, 15186);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 15186))*12))+4);
  i4 = ADT_Dictionary__IsSet((Object__Object)i4);
  if (!i4) goto l8;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15231))+16);
  i4 = _check_pointer(i4, 15238);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 15238))*12))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15212)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i1, (Object__Object)i4);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15279))+16);
  i4 = _check_pointer(i4, 15286);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 15286))*12))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15260)))), ADT_Storable__WriterDesc_WriteObject)),ADT_Storable__WriterDesc_WriteObject)((ADT_Storable__Writer)i1, (Object__Object)i4);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15498)))), IO_BinaryRider__ReaderDesc_ReadNum)),IO_BinaryRider__ReaderDesc_ReadNum)((IO_BinaryRider__Reader)i1, (void*)((_check_pointer(i0, 15513))+8));
  i2 = *(OOC_INT32*)((_check_pointer(i0, 15534))+8);
  i2 = i2!=0;
  if (!i2) goto l11;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 15712))+8);
  *(OOC_INT32*)((_check_pointer(i0, 15699))+16) = ((OOC_INT32)RT0__NewObject(_td_ADT_Dictionary__Table.baseTypes[0], i2));
  i2 = *(OOC_INT32*)((_check_pointer(i0, 15745))+8);
  i = 0;
  i3 = 0<i2;
  if (!i3) goto l10;
  i3=0;
l5_loop:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15766)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i1, (void*)(OOC_INT32)&obj);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15798))+16);
  i4 = _check_pointer(i4, 15804);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)obj;
  *(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 15804))*12))+4) = ((OOC_INT32)_type_cast_fast(OOC_INT32, OOC_INT32, i6));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15839)))), ADT_Storable__ReaderDesc_ReadObject)),ADT_Storable__ReaderDesc_ReadObject)((ADT_Storable__Reader)i1, (void*)(OOC_INT32)&obj);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15871))+16);
  i4 = _check_pointer(i4, 15877);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)obj;
  *(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 15877))*12))+8) = ((OOC_INT32)_type_cast_fast(OOC_INT32, OOC_INT32, i6));
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15918))+16);
  i4 = _check_pointer(i4, 15924);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15940))+16);
  i6 = _check_pointer(i6, 15946);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15940))+16);
  i8 = _check_pointer(i8, 15946);
  i9 = OOC_ARRAY_LENGTH(i8, 0);
  i8 = (OOC_INT32)*(OOC_INT32*)((i8+((_check_index(i3, i9, OOC_UINT32, 15946))*12))+4);
  i6 = (OOC_INT32)*(OOC_INT32*)((i6+((_check_index(i3, i7, OOC_UINT32, 15946))*12))+4);
  i6 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i8, 15953)))), Object__ObjectDesc_HashCode)),Object__ObjectDesc_HashCode)((Object__Object)i6);
  *(OOC_INT32*)(i4+((_check_index(i3, i5, OOC_UINT32, 15924))*12)) = i6;
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l5_loop;
l10:
  i1 = *(OOC_INT32*)((_check_pointer(i0, 15999))+8);
  ADT_Dictionary__DictionaryDesc_Resize((ADT_Dictionary__Dictionary)i0, ((i1*3)>>1));
l11:
  return;
  ;
}

void ADT_Dictionary__IterKeysDesc_INIT(ADT_Dictionary__IterKeys iter, ADT_Dictionary__Dictionary dict) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)iter;
  i1 = (OOC_INT32)dict;
  *(OOC_INT32*)(_check_pointer(i0, 16119)) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 16142))+4) = 0;
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
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 16813));
  d = (ADT_Dictionary__Dictionary)i1;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 16833))+4);
  i = i2;
  i3 = *(OOC_INT32*)((_check_pointer(i1, 16855))+8);
  i3 = i2!=i3;
  if (i3) goto l3;
  i3=0u;
  goto l5;
l3:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 16872))+16);
  i3 = _check_pointer(i3, 16878);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = (OOC_INT32)*(OOC_INT32*)((i3+((_check_index(i2, i4, OOC_UINT32, 16878))*12))+4);
  i3 = ADT_Dictionary__IsSet((Object__Object)i3);
  i3 = !i3;
  
l5:
  if (!i3) goto l17;
l8_loop:
  i2 = i2+1;
  i = i2;
  i3 = *(OOC_INT32*)((_check_pointer(i1, 16855))+8);
  i3 = i2!=i3;
  if (i3) goto l11;
  i3=0u;
  goto l13;
l11:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 16872))+16);
  i3 = _check_pointer(i3, 16878);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = (OOC_INT32)*(OOC_INT32*)((i3+((_check_index(i2, i4, OOC_UINT32, 16878))*12))+4);
  i3 = ADT_Dictionary__IsSet((Object__Object)i3);
  i3 = !i3;
  
l13:
  if (i3) goto l8_loop;
l17:
  i3 = *(OOC_INT32*)((_check_pointer(i1, 16926))+8);
  i3 = i2==i3;
  if (i3) goto l20;
  *(OOC_INT32*)((_check_pointer(i0, 16998))+4) = (i2+1);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 17025))+16);
  i0 = _check_pointer(i0, 17031);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)((i0+((_check_index(i2, i1, OOC_UINT32, 17031))*12))+4);
  *key = (Object__Object)i0;
  return 1u;
  goto l21;
l20:
  *(OOC_INT32*)((_check_pointer(i0, 16948))+4) = i2;
  return 0u;
l21:
  _failed_function(16717); return 0;
  ;
}

void ADT_Dictionary__IterValuesDesc_INIT(ADT_Dictionary__IterValues iter, ADT_Dictionary__Dictionary dict) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)iter;
  i1 = (OOC_INT32)dict;
  *(OOC_INT32*)(_check_pointer(i0, 17166)) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 17189))+4) = 0;
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
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 17878));
  d = (ADT_Dictionary__Dictionary)i1;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 17898))+4);
  i = i2;
  i3 = *(OOC_INT32*)((_check_pointer(i1, 17920))+8);
  i3 = i2!=i3;
  if (i3) goto l3;
  i3=0u;
  goto l5;
l3:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 17937))+16);
  i3 = _check_pointer(i3, 17943);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = (OOC_INT32)*(OOC_INT32*)((i3+((_check_index(i2, i4, OOC_UINT32, 17943))*12))+4);
  i3 = ADT_Dictionary__IsSet((Object__Object)i3);
  i3 = !i3;
  
l5:
  if (!i3) goto l17;
l8_loop:
  i2 = i2+1;
  i = i2;
  i3 = *(OOC_INT32*)((_check_pointer(i1, 17920))+8);
  i3 = i2!=i3;
  if (i3) goto l11;
  i3=0u;
  goto l13;
l11:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 17937))+16);
  i3 = _check_pointer(i3, 17943);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = (OOC_INT32)*(OOC_INT32*)((i3+((_check_index(i2, i4, OOC_UINT32, 17943))*12))+4);
  i3 = ADT_Dictionary__IsSet((Object__Object)i3);
  i3 = !i3;
  
l13:
  if (i3) goto l8_loop;
l17:
  i3 = *(OOC_INT32*)((_check_pointer(i1, 17991))+8);
  i3 = i2==i3;
  if (i3) goto l20;
  *(OOC_INT32*)((_check_pointer(i0, 18063))+4) = (i2+1);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 18092))+16);
  i0 = _check_pointer(i0, 18098);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)((i0+((_check_index(i2, i1, OOC_UINT32, 18098))*12))+8);
  *value = (Object__Object)i0;
  return 1u;
  goto l21;
l20:
  *(OOC_INT32*)((_check_pointer(i0, 18013))+4) = i2;
  return 0u;
l21:
  _failed_function(17780); return 0;
  ;
}

void ADT_Dictionary__DummyDesc_Destroy(ADT_Dictionary__Dummy dummy) {

  return;
  ;
}

void OOC_ADT_Dictionary_init(void) {

  ADT_Dictionary__dummy = (ADT_Dictionary__Dummy)((OOC_INT32)RT0__NewObject(_td_ADT_Dictionary__Dummy.baseTypes[0]));
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary__polys+(_check_index(0, 29, OOC_UINT8, 18235))*4) = 7;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary__polys+(_check_index(1, 29, OOC_UINT8, 18256))*4) = 11;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary__polys+(_check_index(2, 29, OOC_UINT8, 18277))*4) = 19;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary__polys+(_check_index(3, 29, OOC_UINT8, 18299))*4) = 37;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary__polys+(_check_index(4, 29, OOC_UINT8, 18321))*4) = 67;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary__polys+(_check_index(5, 29, OOC_UINT8, 18343))*4) = 131;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary__polys+(_check_index(6, 29, OOC_UINT8, 18366))*4) = 285;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary__polys+(_check_index(7, 29, OOC_UINT8, 18390))*4) = 529;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary__polys+(_check_index(8, 29, OOC_UINT8, 18414))*4) = 1033;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary__polys+(_check_index(9, 29, OOC_UINT8, 18438))*4) = 2053;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary__polys+(_check_index(10, 29, OOC_UINT8, 18462))*4) = 4179;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary__polys+(_check_index(11, 29, OOC_UINT8, 18488))*4) = 8219;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary__polys+(_check_index(12, 29, OOC_UINT8, 18514))*4) = 16427;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary__polys+(_check_index(13, 29, OOC_UINT8, 18541))*4) = 32771;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary__polys+(_check_index(14, 29, OOC_UINT8, 18567))*4) = 65581;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary__polys+(_check_index(15, 29, OOC_UINT8, 18594))*4) = 131081;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary__polys+(_check_index(16, 29, OOC_UINT8, 18621))*4) = 262183;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary__polys+(_check_index(17, 29, OOC_UINT8, 18649))*4) = 524327;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary__polys+(_check_index(18, 29, OOC_UINT8, 18677))*4) = 1048585;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary__polys+(_check_index(19, 29, OOC_UINT8, 18705))*4) = 2097157;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary__polys+(_check_index(20, 29, OOC_UINT8, 18733))*4) = 4194307;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary__polys+(_check_index(21, 29, OOC_UINT8, 18761))*4) = 8388641;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary__polys+(_check_index(22, 29, OOC_UINT8, 18790))*4) = 16777243;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary__polys+(_check_index(23, 29, OOC_UINT8, 18820))*4) = 33554441;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary__polys+(_check_index(24, 29, OOC_UINT8, 18849))*4) = 67108935;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary__polys+(_check_index(25, 29, OOC_UINT8, 18879))*4) = 134217767;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary__polys+(_check_index(26, 29, OOC_UINT8, 18910))*4) = 268435465;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary__polys+(_check_index(27, 29, OOC_UINT8, 18940))*4) = 536870917;
  *(OOC_INT32*)((OOC_INT32)ADT_Dictionary__polys+(_check_index(28, 29, OOC_UINT8, 18970))*4) = 1073741907;
  return;
  ;
}

void OOC_ADT_Dictionary_destroy(void) {
}

/* --- */
