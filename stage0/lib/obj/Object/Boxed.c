#include <Object/Boxed.d>
#include <__oo2c.h>
#include <setjmp.h>

Object__String Object_Boxed__ObjectDesc_ToString(Object_Boxed__Object v) {

  _failed_function(2581); return 0;
  ;
}

OOC_INT32 Object_Boxed__ObjectDesc_Cmp(Object_Boxed__Object v, Object__Object y) {

  _failed_function(2652); return 0;
  ;
}

void Object_Boxed__BooleanDesc_INIT(Object_Boxed__Boolean v, OOC_CHAR8 value) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = value;
  *(OOC_UINT8*)(_check_pointer(i0, 2844)) = i1;
  return;
  ;
}

Object_Boxed__Boolean Object_Boxed__NewBoolean(OOC_CHAR8 value) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)RT0__NewObject(_td_Object_Boxed__Boolean.baseTypes[0]);
  i1 = value;
  Object_Boxed__BooleanDesc_INIT((Object_Boxed__Boolean)i0, i1);
  return (Object_Boxed__Boolean)i0;
  ;
}

Object_Boxed__Boolean Object_Boxed__ParseBoolean(const OOC_CHAR8 str[], OOC_LEN str_0d) {
  register OOC_INT32 i0;

  i0 = (
  _cmp8((const void*)(OOC_INT32)str,(const void*)"TRUE"))==0;
  if (i0) goto l7;
  i0 = (
  _cmp8((const void*)(OOC_INT32)str,(const void*)"FALSE"))==0;
  if (i0) goto l5;
  return (Object_Boxed__Boolean)(OOC_INT32)0;
  goto l8;
l5:
  i0 = (OOC_INT32)Object_Boxed__false;
  return (Object_Boxed__Boolean)i0;
  goto l8;
l7:
  i0 = (OOC_INT32)Object_Boxed__true;
  return (Object_Boxed__Boolean)i0;
l8:
  _failed_function(3055); return 0;
  ;
}

Object__String Object_Boxed__BooleanToString(OOC_CHAR8 value) {
  register OOC_INT32 i0,i1;
  Object_Boxed__Boolean v;

  i0 = (OOC_INT32)RT0__NewObject(_td_Object_Boxed__Boolean.baseTypes[0]);
  i1 = value;
  Object_Boxed__BooleanDesc_INIT((Object_Boxed__Boolean)i0, i1);
  v = (Object_Boxed__Boolean)i0;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3514)))), Object_Boxed__ObjectDesc_ToString)),Object_Boxed__ObjectDesc_ToString)((Object_Boxed__Object)i0);
  return (Object__String)i0;
  ;
}

OOC_CHAR8 Object_Boxed__BooleanDesc_Equals(Object_Boxed__Boolean v, Object__Object y) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)y;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3629)))), &_td_Object_Boxed__BooleanDesc);
  if (i1) goto l3;
  i0=0u;
  goto l4;
l3:
  i1 = (OOC_INT32)v;
  i1 = *(OOC_UINT8*)(_check_pointer(i1, 3645));
  i0 = *(OOC_UINT8*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3656)))), &_td_Object_Boxed__BooleanDesc, 3656)), 3664));
  i0 = i1==i0;
  
l4:
  return i0;
  ;
}

OOC_INT32 Object_Boxed__BooleanDesc_Cmp(Object_Boxed__Boolean v, Object__Object y) {

  _assert(0u, 127, 3781);
  _failed_function(3712); return 0;
  ;
}

OOC_INT32 Object_Boxed__BooleanDesc_HashCode(Object_Boxed__Boolean v) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)v;
  i0 = *(OOC_UINT8*)(_check_pointer(i0, 3902));
  i0 = HashCode__Boolean(i0);
  return i0;
  ;
}

Object__String Object_Boxed__BooleanDesc_ToString(Object_Boxed__Boolean v) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)v;
  i0 = *(OOC_UINT8*)(_check_pointer(i0, 3990));
  if (i0) goto l3;
  i0 = (OOC_INT32)Object_Boxed__falseString;
  return (Object__String)i0;
  goto l4;
l3:
  i0 = (OOC_INT32)Object_Boxed__trueString;
  return (Object__String)i0;
l4:
  _failed_function(3953); return 0;
  ;
}

void Object_Boxed__BooleanDesc_Store(Object_Boxed__Boolean v, ADT_Storable__Writer w) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)v;
  i0 = *(OOC_UINT8*)(_check_pointer(i0, 4171));
  if (i0) goto l3;
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4221)))), IO_BinaryRider__WriterDesc_WriteSInt)),IO_BinaryRider__WriterDesc_WriteSInt)((IO_BinaryRider__Writer)i0, 0);
  goto l4;
l3:
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4190)))), IO_BinaryRider__WriterDesc_WriteSInt)),IO_BinaryRider__WriterDesc_WriteSInt)((IO_BinaryRider__Writer)i0, 1);
l4:
  return;
  ;
}

void Object_Boxed__BooleanDesc_Load(Object_Boxed__Boolean v, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1;
  OOC_INT8 si;

  i0 = (OOC_INT32)r;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4362)))), IO_BinaryRider__ReaderDesc_ReadSInt)),IO_BinaryRider__ReaderDesc_ReadSInt)((IO_BinaryRider__Reader)i0, (void*)(OOC_INT32)&si);
  i0 = (OOC_INT32)v;
  i1 = si;
  *(OOC_UINT8*)(_check_pointer(i0, 4382)) = (i1!=0);
  return;
  ;
}

void Object_Boxed__LongIntDesc_INIT(Object_Boxed__LongInt v, OOC_INT32 val) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = val;
  *(OOC_INT32*)(_check_pointer(i0, 4563)) = i1;
  return;
  ;
}

Object_Boxed__LongInt Object_Boxed__NewLongInt(OOC_INT32 val) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)RT0__NewObject(_td_Object_Boxed__LongInt.baseTypes[0]);
  i1 = val;
  Object_Boxed__LongIntDesc_INIT((Object_Boxed__LongInt)i0, i1);
  return (Object_Boxed__LongInt)i0;
  ;
}

Object_Boxed__LongInt Object_Boxed__ParseLongInt(const OOC_CHAR8 s__ref[], OOC_LEN s_0d) {
  register OOC_INT32 i0,i1;
  OOC_ALLOCATE_VPAR(s,OOC_CHAR8 ,s_0d)
  OOC_INT8 res;
  OOC_INT32 _int;

  OOC_INITIALIZE_VPAR(s__ref,s,OOC_CHAR8 ,s_0d)
  IntStr__StrToInt((void*)(OOC_INT32)s, s_0d, (void*)(OOC_INT32)&_int, (void*)(OOC_INT32)&res);
  i0 = res;
  i0 = i0==0;
  if (i0) goto l3;
  return (Object_Boxed__LongInt)(OOC_INT32)0;
  goto l4;
l3:
  i0 = _int;
  i1 = (OOC_INT32)RT0__NewObject(_td_Object_Boxed__LongInt.baseTypes[0]);
  Object_Boxed__LongIntDesc_INIT((Object_Boxed__LongInt)i1, i0);
  return (Object_Boxed__LongInt)i1;
l4:
  _failed_function(4768); return 0;
  ;
}

Object__String Object_Boxed__IntToString(OOC_INT32 value) {
  register OOC_INT32 i0,i1;
  Object_Boxed__LongInt v;

  i0 = (OOC_INT32)RT0__NewObject(_td_Object_Boxed__LongInt.baseTypes[0]);
  i1 = value;
  Object_Boxed__LongIntDesc_INIT((Object_Boxed__LongInt)i0, i1);
  v = (Object_Boxed__LongInt)i0;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5272)))), Object_Boxed__ObjectDesc_ToString)),Object_Boxed__ObjectDesc_ToString)((Object_Boxed__Object)i0);
  return (Object__String)i0;
  ;
}

void Object_Boxed__LongIntDesc_Store(Object_Boxed__LongInt v, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)w;
  i0 = *(OOC_INT32*)(_check_pointer(i0, 5398));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5385)))), IO_BinaryRider__WriterDesc_WriteLInt)),IO_BinaryRider__WriterDesc_WriteLInt)((IO_BinaryRider__Writer)i1, i0);
  return;
  ;
}

void Object_Boxed__LongIntDesc_Load(Object_Boxed__LongInt v, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)r;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5500)))), IO_BinaryRider__ReaderDesc_ReadLInt)),IO_BinaryRider__ReaderDesc_ReadLInt)((IO_BinaryRider__Reader)i1, (void*)(_check_pointer(i0, 5512)));
  return;
  ;
}

OOC_CHAR8 Object_Boxed__LongIntDesc_Equals(Object_Boxed__LongInt v, Object__Object y) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)y;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5612)))), &_td_Object_Boxed__LongIntDesc);
  if (i1) goto l3;
  i0=0u;
  goto l4;
l3:
  i1 = (OOC_INT32)v;
  i1 = *(OOC_INT32*)(_check_pointer(i1, 5628));
  i0 = *(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5639)))), &_td_Object_Boxed__LongIntDesc, 5639)), 5647));
  i0 = i1==i0;
  
l4:
  return i0;
  ;
}

OOC_INT32 Object_Boxed__LongIntDesc_HashCode(Object_Boxed__LongInt v) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)v;
  i0 = *(OOC_INT32*)(_check_pointer(i0, 5739));
  return i0;
  ;
}

Object__String Object_Boxed__LongIntDesc_ToString(Object_Boxed__LongInt v) {
  register OOC_INT32 i0;
  OOC_CHAR8 str[10];

  i0 = (OOC_INT32)v;
  i0 = *(OOC_INT32*)(_check_pointer(i0, 5871));
  IntStr__IntToStr(i0, (void*)(OOC_INT32)str, 10);
  i0 = (OOC_INT32)Object__NewLatin1((void*)(OOC_INT32)str, 10);
  return (Object__String)i0;
  ;
}

Object_Boxed__LongInt Object_Boxed__LongIntDesc_Add(Object_Boxed__LongInt v, Object_Boxed__LongInt right) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)RT0__NewObject(_td_Object_Boxed__LongInt.baseTypes[0]);
  i1 = (OOC_INT32)v;
  i2 = (OOC_INT32)right;
  i1 = *(OOC_INT32*)(_check_pointer(i1, 6020));
  i2 = *(OOC_INT32*)(_check_pointer(i2, 6034));
  Object_Boxed__LongIntDesc_INIT((Object_Boxed__LongInt)i0, (i1+i2));
  return (Object_Boxed__LongInt)i0;
  ;
}

Object_Boxed__LongInt Object_Boxed__LongIntDesc_Sub(Object_Boxed__LongInt v, Object_Boxed__LongInt right) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)RT0__NewObject(_td_Object_Boxed__LongInt.baseTypes[0]);
  i1 = (OOC_INT32)v;
  i2 = (OOC_INT32)right;
  i1 = *(OOC_INT32*)(_check_pointer(i1, 6142));
  i2 = *(OOC_INT32*)(_check_pointer(i2, 6156));
  Object_Boxed__LongIntDesc_INIT((Object_Boxed__LongInt)i0, (i1-i2));
  return (Object_Boxed__LongInt)i0;
  ;
}

Object_Boxed__LongInt Object_Boxed__LongIntDesc_Mul(Object_Boxed__LongInt v, Object_Boxed__LongInt right) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)RT0__NewObject(_td_Object_Boxed__LongInt.baseTypes[0]);
  i1 = (OOC_INT32)v;
  i2 = (OOC_INT32)right;
  i1 = *(OOC_INT32*)(_check_pointer(i1, 6264));
  i2 = *(OOC_INT32*)(_check_pointer(i2, 6278));
  Object_Boxed__LongIntDesc_INIT((Object_Boxed__LongInt)i0, (i1*i2));
  return (Object_Boxed__LongInt)i0;
  ;
}

Object_Boxed__LongInt Object_Boxed__LongIntDesc_Div(Object_Boxed__LongInt v, Object_Boxed__LongInt right) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)RT0__NewObject(_td_Object_Boxed__LongInt.baseTypes[0]);
  i1 = (OOC_INT32)v;
  i2 = (OOC_INT32)right;
  i1 = *(OOC_INT32*)(_check_pointer(i1, 6386));
  i2 = *(OOC_INT32*)(_check_pointer(i2, 6402));
  Object_Boxed__LongIntDesc_INIT((Object_Boxed__LongInt)i0, (_div(i1,i2)));
  return (Object_Boxed__LongInt)i0;
  ;
}

Object_Boxed__LongInt Object_Boxed__LongIntDesc_Mod(Object_Boxed__LongInt v, Object_Boxed__LongInt right) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)RT0__NewObject(_td_Object_Boxed__LongInt.baseTypes[0]);
  i1 = (OOC_INT32)v;
  i2 = (OOC_INT32)right;
  i1 = *(OOC_INT32*)(_check_pointer(i1, 6510));
  i2 = *(OOC_INT32*)(_check_pointer(i2, 6526));
  Object_Boxed__LongIntDesc_INIT((Object_Boxed__LongInt)i0, (_mod(i1,i2)));
  return (Object_Boxed__LongInt)i0;
  ;
}

OOC_INT32 Object_Boxed__LongIntDesc_Cmp(Object_Boxed__LongInt v, Object__Object right) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)right;
  i2 = *(OOC_INT32*)(_check_pointer(i0, 6620));
  i3 = *(OOC_INT32*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6635)))), &_td_Object_Boxed__LongIntDesc, 6635)), 6643));
  i2 = i2==i3;
  if (i2) goto l7;
  i1 = *(OOC_INT32*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6697)))), &_td_Object_Boxed__LongIntDesc, 6697)), 6705));
  i0 = *(OOC_INT32*)(_check_pointer(i0, 6682));
  i0 = i0<i1;
  if (i0) goto l5;
  return 1;
  goto l8;
l5:
  return (-1);
  goto l8;
l7:
  return 0;
l8:
  _failed_function(6570); return 0;
  ;
}

OOC_INT32 Object_Boxed__LongIntDesc_Sign(Object_Boxed__LongInt v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)Object_Boxed__zeroLongInt;
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6841)))), Object_Boxed__LongIntDesc_Cmp)),Object_Boxed__LongIntDesc_Cmp)((Object_Boxed__LongInt)i0, (Object__Object)i1);
  return i0;
  ;
}

Object_Boxed__LongInt Object_Boxed__LongIntDesc_Neg(Object_Boxed__LongInt v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)RT0__NewObject(_td_Object_Boxed__LongInt.baseTypes[0]);
  i1 = (OOC_INT32)v;
  i1 = *(OOC_INT32*)(_check_pointer(i1, 6947));
  Object_Boxed__LongIntDesc_INIT((Object_Boxed__LongInt)i0, (-i1));
  return (Object_Boxed__LongInt)i0;
  ;
}

void Object_Boxed__LongRealDesc_INIT(Object_Boxed__LongReal v, OOC_REAL64 val) {
  register OOC_INT32 i0;
  register OOC_REAL64 d0;

  i0 = (OOC_INT32)v;
  d0 = val;
  *(OOC_REAL64*)(_check_pointer(i0, 7119)) = d0;
  return;
  ;
}

Object_Boxed__LongReal Object_Boxed__NewLongReal(OOC_REAL64 val) {
  register OOC_INT32 i0;
  register OOC_REAL64 d0;

  i0 = (OOC_INT32)RT0__NewObject(_td_Object_Boxed__LongReal.baseTypes[0]);
  d0 = val;
  Object_Boxed__LongRealDesc_INIT((Object_Boxed__LongReal)i0, d0);
  return (Object_Boxed__LongReal)i0;
  ;
}

Object_Boxed__LongReal Object_Boxed__ParseLongReal(const OOC_CHAR8 s__ref[], OOC_LEN s_0d) {
  register OOC_INT32 i0;
  register OOC_REAL64 d0;
  OOC_ALLOCATE_VPAR(s,OOC_CHAR8 ,s_0d)
  OOC_INT8 res;
  OOC_REAL64 real;

  OOC_INITIALIZE_VPAR(s__ref,s,OOC_CHAR8 ,s_0d)
  LRealStr__StrToReal((void*)(OOC_INT32)s, s_0d, (void*)(OOC_INT32)&real, (void*)(OOC_INT32)&res);
  i0 = res;
  i0 = i0==0;
  if (i0) goto l3;
  return (Object_Boxed__LongReal)(OOC_INT32)0;
  goto l4;
l3:
  d0 = real;
  i0 = (OOC_INT32)RT0__NewObject(_td_Object_Boxed__LongReal.baseTypes[0]);
  Object_Boxed__LongRealDesc_INIT((Object_Boxed__LongReal)i0, d0);
  return (Object_Boxed__LongReal)i0;
l4:
  _failed_function(7330); return 0;
  ;
}

Object__String Object_Boxed__LongRealToString(OOC_REAL64 value) {
  register OOC_INT32 i0;
  register OOC_REAL64 d0;
  Object_Boxed__LongReal v;

  i0 = (OOC_INT32)RT0__NewObject(_td_Object_Boxed__LongReal.baseTypes[0]);
  d0 = value;
  Object_Boxed__LongRealDesc_INIT((Object_Boxed__LongReal)i0, d0);
  v = (Object_Boxed__LongReal)i0;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7858)))), Object_Boxed__ObjectDesc_ToString)),Object_Boxed__ObjectDesc_ToString)((Object_Boxed__Object)i0);
  return (Object__String)i0;
  ;
}

Object_Boxed__LongReal Object_Boxed__ParseLongRealLiteral(const OOC_CHAR8 s__ref[], OOC_LEN s_0d) {
  register OOC_INT32 i0,i1;
  register OOC_REAL32 f0;
  register OOC_REAL64 d0;
  OOC_ALLOCATE_VPAR(s,OOC_CHAR8 ,s_0d)
  OOC_INT8 res;
  OOC_REAL64 longreal;
  OOC_REAL32 real;

  OOC_INITIALIZE_VPAR(s__ref,s,OOC_CHAR8 ,s_0d)
  i0 = *(OOC_UINT8*)((OOC_INT32)s+(_check_index(0, s_0d, OOC_UINT32, 8409)));
  i0 = i0!=0u;
  if (i0) goto l3;
  i0=0u;
  goto l5;
l3:
  i0 = *(OOC_UINT8*)((OOC_INT32)s+(_check_index(0, s_0d, OOC_UINT32, 8423)));
  i0 = i0!=68u;
  
l5:
  if (i0) goto l7;
  i0=0;
  goto l17;
l7:
  i0=0;
l8_loop:
  i0 = i0+1;
  i1 = *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i0, s_0d, OOC_UINT32, 8409)));
  i1 = i1!=0u;
  if (i1) goto l11;
  i1=0u;
  goto l13;
l11:
  i1 = *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i0, s_0d, OOC_UINT32, 8423)));
  i1 = i1!=68u;
  
l13:
  if (i1) goto l8_loop;
l17:
  i1 = *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i0, s_0d, OOC_UINT32, 8489)));
  i1 = i1==68u;
  if (i1) goto l24;
  RealStr__StrToReal((void*)(OOC_INT32)s, s_0d, (void*)(OOC_INT32)&real, (void*)(OOC_INT32)&res);
  i0 = res;
  i0 = i0==0;
  if (i0) goto l22;
  i0=(OOC_INT32)0;
  goto l29;
l22:
  f0 = real;
  i0 = (OOC_INT32)RT0__NewObject(_td_Object_Boxed__LongReal.baseTypes[0]);
  Object_Boxed__LongRealDesc_INIT((Object_Boxed__LongReal)i0, ((OOC_REAL64)f0));
  
  goto l29;
l24:
  *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i0, s_0d, OOC_UINT32, 8512))) = 69u;
  LRealStr__StrToReal((void*)(OOC_INT32)s, s_0d, (void*)(OOC_INT32)&longreal, (void*)(OOC_INT32)&res);
  i0 = res;
  i0 = i0==0;
  if (i0) goto l27;
  i0=(OOC_INT32)0;
  goto l29;
l27:
  d0 = longreal;
  i0 = (OOC_INT32)RT0__NewObject(_td_Object_Boxed__LongReal.baseTypes[0]);
  Object_Boxed__LongRealDesc_INIT((Object_Boxed__LongReal)i0, d0);
  
l29:
  return (Object_Boxed__LongReal)i0;
  ;
}

void Object_Boxed__LongRealDesc_Store(Object_Boxed__LongReal v, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1;
  register OOC_REAL64 d0;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)w;
  d0 = *(OOC_REAL64*)(_check_pointer(i0, 8939));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8925)))), IO_BinaryRider__WriterDesc_WriteLReal)),IO_BinaryRider__WriterDesc_WriteLReal)((IO_BinaryRider__Writer)i1, d0);
  return;
  ;
}

void Object_Boxed__LongRealDesc_Load(Object_Boxed__LongReal v, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)r;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9042)))), IO_BinaryRider__ReaderDesc_ReadLReal)),IO_BinaryRider__ReaderDesc_ReadLReal)((IO_BinaryRider__Reader)i1, (void*)(_check_pointer(i0, 9055)));
  return;
  ;
}

OOC_CHAR8 Object_Boxed__LongRealDesc_Equals(Object_Boxed__LongReal v, Object__Object y) {
  register OOC_INT32 i0,i1;
  register OOC_REAL64 d0,d1;

  i0 = (OOC_INT32)y;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9156)))), &_td_Object_Boxed__LongRealDesc);
  if (i1) goto l3;
  i0=0u;
  goto l4;
l3:
  i1 = (OOC_INT32)v;
  d0 = *(OOC_REAL64*)(_check_pointer(i1, 9173));
  d1 = *(OOC_REAL64*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9184)))), &_td_Object_Boxed__LongRealDesc, 9184)), 9193));
  i0 = d0==d1;
  
l4:
  return i0;
  ;
}

OOC_INT32 Object_Boxed__LongRealDesc_HashCode(Object_Boxed__LongReal v) {
  register OOC_INT32 i0;
  register OOC_REAL64 d0;

  i0 = (OOC_INT32)v;
  d0 = *(OOC_REAL64*)(_check_pointer(i0, 9304));
  i0 = HashCode__LongReal(d0);
  return i0;
  ;
}

Object__String Object_Boxed__LongRealDesc_ToString(Object_Boxed__LongReal v) {
  register OOC_INT32 i0;
  register OOC_REAL64 d0;
  OOC_CHAR8 str[128];

  i0 = (OOC_INT32)v;
  d0 = *(OOC_REAL64*)(_check_pointer(i0, 9444));
  LRealStr__RealToFloat(d0, 17, (void*)(OOC_INT32)str, 128);
  i0 = (OOC_INT32)Object__NewLatin1((void*)(OOC_INT32)str, 128);
  return (Object__String)i0;
  ;
}

OOC_REAL64 Object_Boxed__LongRealDesc_ToLongReal(Object_Boxed__LongReal v) {
  register OOC_INT32 i0;
  register OOC_REAL64 d0;

  i0 = (OOC_INT32)v;
  d0 = *(OOC_REAL64*)(_check_pointer(i0, 9579));
  return d0;
  ;
}

Object_Boxed__LongReal Object_Boxed__LongRealDesc_Add(Object_Boxed__LongReal v, Object_Boxed__LongReal right) {
  register OOC_INT32 i0,i1,i2;
  register OOC_REAL64 d0,d1;

  i0 = (OOC_INT32)RT0__NewObject(_td_Object_Boxed__LongReal.baseTypes[0]);
  i1 = (OOC_INT32)v;
  i2 = (OOC_INT32)right;
  d0 = *(OOC_REAL64*)(_check_pointer(i1, 9697));
  d1 = *(OOC_REAL64*)(_check_pointer(i2, 9711));
  Object_Boxed__LongRealDesc_INIT((Object_Boxed__LongReal)i0, (d0+d1));
  return (Object_Boxed__LongReal)i0;
  ;
}

Object_Boxed__LongReal Object_Boxed__LongRealDesc_Sub(Object_Boxed__LongReal v, Object_Boxed__LongReal right) {
  register OOC_INT32 i0,i1,i2;
  register OOC_REAL64 d0,d1;

  i0 = (OOC_INT32)RT0__NewObject(_td_Object_Boxed__LongReal.baseTypes[0]);
  i1 = (OOC_INT32)v;
  i2 = (OOC_INT32)right;
  d0 = *(OOC_REAL64*)(_check_pointer(i1, 9823));
  d1 = *(OOC_REAL64*)(_check_pointer(i2, 9837));
  Object_Boxed__LongRealDesc_INIT((Object_Boxed__LongReal)i0, (d0-d1));
  return (Object_Boxed__LongReal)i0;
  ;
}

Object_Boxed__LongReal Object_Boxed__LongRealDesc_Mul(Object_Boxed__LongReal v, Object_Boxed__LongReal right) {
  register OOC_INT32 i0,i1,i2;
  register OOC_REAL64 d0,d1;

  i0 = (OOC_INT32)RT0__NewObject(_td_Object_Boxed__LongReal.baseTypes[0]);
  i1 = (OOC_INT32)v;
  i2 = (OOC_INT32)right;
  d0 = *(OOC_REAL64*)(_check_pointer(i1, 9949));
  d1 = *(OOC_REAL64*)(_check_pointer(i2, 9963));
  Object_Boxed__LongRealDesc_INIT((Object_Boxed__LongReal)i0, (d0*d1));
  return (Object_Boxed__LongReal)i0;
  ;
}

Object_Boxed__LongReal Object_Boxed__LongRealDesc_Div(Object_Boxed__LongReal v, Object_Boxed__LongReal right) {
  register OOC_INT32 i0,i1,i2;
  register OOC_REAL64 d0,d1;

  i0 = (OOC_INT32)RT0__NewObject(_td_Object_Boxed__LongReal.baseTypes[0]);
  i1 = (OOC_INT32)v;
  i2 = (OOC_INT32)right;
  d0 = *(OOC_REAL64*)(_check_pointer(i1, 10075));
  d1 = *(OOC_REAL64*)(_check_pointer(i2, 10089));
  Object_Boxed__LongRealDesc_INIT((Object_Boxed__LongReal)i0, (d0/d1));
  return (Object_Boxed__LongReal)i0;
  ;
}

OOC_INT32 Object_Boxed__LongRealDesc_Cmp(Object_Boxed__LongReal v, Object__Object right) {
  register OOC_INT32 i0,i1,i2;
  register OOC_REAL64 d0,d1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)right;
  d0 = *(OOC_REAL64*)(_check_pointer(i0, 10184));
  d1 = *(OOC_REAL64*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 10199)))), &_td_Object_Boxed__LongRealDesc, 10199)), 10208));
  i2 = d0==d1;
  if (i2) goto l7;
  d0 = *(OOC_REAL64*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 10262)))), &_td_Object_Boxed__LongRealDesc, 10262)), 10271));
  d1 = *(OOC_REAL64*)(_check_pointer(i0, 10247));
  i0 = d1<d0;
  if (i0) goto l5;
  return 1;
  goto l8;
l5:
  return (-1);
  goto l8;
l7:
  return 0;
l8:
  _failed_function(10134); return 0;
  ;
}

OOC_INT32 Object_Boxed__LongRealDesc_Sign(Object_Boxed__LongReal v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)Object_Boxed__zeroLongReal;
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10566)))), Object_Boxed__LongRealDesc_Cmp)),Object_Boxed__LongRealDesc_Cmp)((Object_Boxed__LongReal)i0, (Object__Object)i1);
  return i0;
  ;
}

Object_Boxed__LongReal Object_Boxed__LongRealDesc_Neg(Object_Boxed__LongReal v) {
  register OOC_INT32 i0,i1;
  register OOC_REAL64 d0;

  i0 = (OOC_INT32)RT0__NewObject(_td_Object_Boxed__LongReal.baseTypes[0]);
  i1 = (OOC_INT32)v;
  d0 = *(OOC_REAL64*)(_check_pointer(i1, 10676));
  Object_Boxed__LongRealDesc_INIT((Object_Boxed__LongReal)i0, (-d0));
  return (Object_Boxed__LongReal)i0;
  ;
}

void Object_Boxed__SetDesc_INIT(Object_Boxed__Set v, OOC_UINT32 value) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = value;
  *(OOC_UINT32*)(_check_pointer(i0, 10835)) = i1;
  return;
  ;
}

Object_Boxed__Set Object_Boxed__NewSet(OOC_UINT32 value) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)RT0__NewObject(_td_Object_Boxed__Set.baseTypes[0]);
  i1 = value;
  Object_Boxed__SetDesc_INIT((Object_Boxed__Set)i0, i1);
  return (Object_Boxed__Set)i0;
  ;
}

Object__String Object_Boxed__SetToString(OOC_UINT32 value) {
  register OOC_INT32 i0,i1;
  Object_Boxed__Set v;

  i0 = (OOC_INT32)RT0__NewObject(_td_Object_Boxed__Set.baseTypes[0]);
  i1 = value;
  Object_Boxed__SetDesc_INIT((Object_Boxed__Set)i0, i1);
  v = (Object_Boxed__Set)i0;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11236)))), Object_Boxed__ObjectDesc_ToString)),Object_Boxed__ObjectDesc_ToString)((Object_Boxed__Object)i0);
  return (Object__String)i0;
  ;
}

OOC_CHAR8 Object_Boxed__SetDesc_Equals(Object_Boxed__Set v, Object__Object y) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)y;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11335)))), &_td_Object_Boxed__SetDesc);
  if (i1) goto l3;
  return 0u;
  goto l4;
l3:
  i1 = (OOC_INT32)v;
  i0 = *(OOC_UINT32*)(_check_pointer(i0, 11356));
  i1 = *(OOC_UINT32*)(_check_pointer(i1, 11366));
  return (i0==i1);
l4:
  _failed_function(11288); return 0;
  ;
}

OOC_INT32 Object_Boxed__SetDesc_Cmp(Object_Boxed__Set v, Object__Object y) {

  _assert(0u, 127, 11506);
  _failed_function(11437); return 0;
  ;
}

OOC_INT32 Object_Boxed__SetDesc_HashCode(Object_Boxed__Set v) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)v;
  i0 = *(OOC_UINT32*)(_check_pointer(i0, 11619));
  i0 = HashCode__Set(i0);
  return i0;
  ;
}

Object__String Object_Boxed__SetDesc_ToString(Object_Boxed__Set v) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_CHAR8 str[131];
  OOC_CHAR8 num[8];

  i0 = (OOC_INT32)v;
  i0 = *(OOC_UINT32*)(_check_pointer(i0, 11826));
  _copy_8((const void*)"{",(void*)(OOC_INT32)str,131);
  i1=0;i2=0u;
l1_loop:
  i3 = _in(i1,i0);
  if (i3) goto l4;
  {register OOC_INT32 h0=i1;i1=i2;i2=h0;}
  goto l32;
l4:
  i3 = i1<31;
  if (i3) goto l7;
  i3=0u;
  goto l9;
l7:
  i3 = _in((i1+1),i0);
  
l9:
  if (i3) goto l11;
  i3=i1;
  goto l22;
l11:
  i3=i1;
l12_loop:
  i3 = i3+1;
  i4 = i3<31;
  if (i4) goto l15;
  i4=0u;
  goto l17;
l15:
  i4 = _in((i3+1),i0);
  
l17:
  if (i4) goto l12_loop;
l22:
  if (!i2) goto l24;
  Strings__Append(",", 2, (void*)(OOC_INT32)str, 131);
l24:
  IntStr__IntToStr(i1, (void*)(OOC_INT32)num, 8);
  Strings__Append((void*)(OOC_INT32)num, 8, (void*)(OOC_INT32)str, 131);
  i2 = i1<i3;
  if (!i2) goto l31;
  i1 = i3==(i1+1);
  if (i1) goto l29;
  Strings__Append("..", 3, (void*)(OOC_INT32)str, 131);
  goto l30;
l29:
  Strings__Append(",", 2, (void*)(OOC_INT32)str, 131);
l30:
  IntStr__IntToStr(i3, (void*)(OOC_INT32)num, 8);
  Strings__Append((void*)(OOC_INT32)num, 8, (void*)(OOC_INT32)str, 131);
l31:
  i2=i3;i1=1u;
l32:
  i2 = i2+1;
  i3 = i2<=31;
  if (!i3) goto l36;
  {register OOC_INT32 h0=i1;i1=i2;i2=h0;}
  goto l1_loop;
l36:
  Strings__Append("}", 2, (void*)(OOC_INT32)str, 131);
  i0 = (OOC_INT32)Object__NewLatin1((void*)(OOC_INT32)str, 131);
  return (Object__String)i0;
  ;
}

OOC_INT32 Object_Boxed__SetDesc_ToLongInt(Object_Boxed__Set v) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)v;
  i0 = *(OOC_UINT32*)(_check_pointer(i0, 12642));
  return (_type_cast_fast(OOC_INT32, OOC_UINT32, i0));
  ;
}

void Object_Boxed__SetDesc_Store(Object_Boxed__Set v, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)w;
  i0 = *(OOC_UINT32*)(_check_pointer(i0, 12756));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 12745)))), IO_BinaryRider__WriterDesc_WriteSet)),IO_BinaryRider__WriterDesc_WriteSet)((IO_BinaryRider__Writer)i1, i0);
  return;
  ;
}

void Object_Boxed__SetDesc_Load(Object_Boxed__Set v, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)r;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 12854)))), IO_BinaryRider__ReaderDesc_ReadSet)),IO_BinaryRider__ReaderDesc_ReadSet)((IO_BinaryRider__Reader)i1, (void*)(_check_pointer(i0, 12864)));
  return;
  ;
}

void Object_Boxed__StringDesc_INIT(Object_Boxed__String v, Object__String value) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)value;
  *(OOC_INT32*)(_check_pointer(i0, 13033)) = i1;
  return;
  ;
}

Object_Boxed__String Object_Boxed__NewString(Object__String value) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)value;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 13192));
  i1 = i1==0;
  if (i1) goto l3;
  i1 = (OOC_INT32)RT0__NewObject(_td_Object_Boxed__String.baseTypes[0]);
  Object_Boxed__StringDesc_INIT((Object_Boxed__String)i1, (Object__String)i0);
  return (Object_Boxed__String)i1;
  goto l4;
l3:
  i0 = (OOC_INT32)Object_Boxed__emptyString;
  return (Object_Boxed__String)i0;
l4:
  _failed_function(13086); return 0;
  ;
}

OOC_INT32 Object_Boxed__StringDesc_Cmp(Object_Boxed__String v, Object__Object str) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)str;
  i1 = (OOC_INT32)v;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 13379));
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13398)))), &_td_Object_Boxed__StringDesc, 13398)), 13405));
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 13379));
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 13385)))), Object__StringDesc_Compare)),Object__StringDesc_Compare)((Object__String)i1, (Object__Object)i0);
  return i0;
  ;
}

OOC_CHAR8 Object_Boxed__StringDesc_Equals(Object_Boxed__String v, Object__Object y) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)y;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13503)))), &_td_Object_Boxed__StringDesc);
  if (i1) goto l3;
  i0=0u;
  goto l4;
l3:
  i1 = (OOC_INT32)v;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 13517));
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13535)))), &_td_Object_Boxed__StringDesc, 13535)), 13542));
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 13517));
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 13524)))), Object__StringDesc_Equals)),Object__StringDesc_Equals)((Object__String)i1, (Object__Object)i0);
  
l4:
  return i0;
  ;
}

OOC_INT32 Object_Boxed__StringDesc_HashCode(Object_Boxed__String v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 13633));
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 13633));
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 13639)))), Object__StringDesc_HashCode)),Object__StringDesc_HashCode)((Object__String)i0);
  return i0;
  ;
}

Object__String Object_Boxed__StringDesc_ToString(Object_Boxed__String v) {
  register OOC_INT32 i0,i1,i2;
  OOC_INT32 i;
  OOC_CHAR8 delim[2];
  ADT_StringBuffer__StringBuffer sb;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 13817));
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 13817));
  i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 13824)))), Object__StringDesc_IndexOf)),Object__StringDesc_IndexOf)((Object__String)i2, 34u, 0);
  i = i1;
  i1 = i1<0;
  if (i1) goto l3;
  _copy_8((const void*)"\047",(void*)(OOC_INT32)delim,2);
  goto l4;
l3:
  _copy_8((const void*)"\"",(void*)(OOC_INT32)delim,2);
l4:
  i1 = (OOC_INT32)Object__NewLatin1((void*)(OOC_INT32)delim, 2);
  i1 = (OOC_INT32)ADT_StringBuffer__New((Object__String)i1);
  sb = (ADT_StringBuffer__StringBuffer)i1;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 13985));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 13976)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i1, (Object__Object)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14000)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1)),ADT_StringBuffer__StringBufferDesc_AppendLatin1)((ADT_StringBuffer__StringBuffer)i1, (void*)(OOC_INT32)delim, 2);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14035)))), ADT_StringBuffer__StringBufferDesc_ToString)),ADT_StringBuffer__StringBufferDesc_ToString)((ADT_StringBuffer__StringBuffer)i1);
  return (Object__String)i0;
  ;
}

void Object_Boxed__StringDesc_Store(Object_Boxed__String v, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)w;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 14155));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14144)))), IO_BinaryRider__WriterDesc_WriteStr)),IO_BinaryRider__WriterDesc_WriteStr)((IO_BinaryRider__Writer)i1, (Object__String)i0);
  return;
  ;
}

void Object_Boxed__StringDesc_Load(Object_Boxed__String v, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)r;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14256)))), IO_BinaryRider__ReaderDesc_ReadStr)),IO_BinaryRider__ReaderDesc_ReadStr)((IO_BinaryRider__Reader)i1, (void*)(_check_pointer(i0, 14266)));
  return;
  ;
}

Object_Boxed__String Object_Boxed__ParseString(const OOC_CHAR8 str[], OOC_LEN str_0d) {
  register OOC_INT32 i0,i1,i2;

  i0 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, str_0d, OOC_UINT32, 14405)));
  i0 = i0!=0u;
  if (i0) goto l3;
  i0=0;
  goto l9;
l3:
  i0=0;
l4_loop:
  i0 = i0+1;
  i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT32, 14405)));
  i1 = i1!=0u;
  if (i1) goto l4_loop;
l9:
  i1 = i0>=2;
  if (i1) goto l12;
  i1=0u;
  goto l14;
l12:
  i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, str_0d, OOC_UINT8, 14463)));
  i2 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index((i0-1), str_0d, OOC_UINT32, 14472)));
  i1 = i1==i2;
  
l14:
  if (i1) goto l16;
  i1=0u;
  goto l22;
l16:
  i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, str_0d, OOC_UINT8, 14486)));
  i1 = i1==34u;
  if (i1) goto l19;
  i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, str_0d, OOC_UINT8, 14504)));
  i1 = i1==39u;
  
  goto l22;
l19:
  i1=1u;
l22:
  if (i1) goto l24;
  return (Object_Boxed__String)(OOC_INT32)0;
  goto l25;
l24:
  i1 = (OOC_INT32)RT0__NewObject(_td_Object_Boxed__String.baseTypes[0]);
  i0 = (OOC_INT32)Object__NewLatin1Region((void*)(OOC_INT32)str, str_0d, 1, (i0-1));
  Object_Boxed__StringDesc_INIT((Object_Boxed__String)i1, (Object__String)i0);
  return (Object_Boxed__String)i1;
l25:
  _failed_function(14298); return 0;
  ;
}

void OOC_Object_Boxed_init(void) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)RT0__NewObject(_td_Object_Boxed__Boolean.baseTypes[0]);
  Object_Boxed__BooleanDesc_INIT((Object_Boxed__Boolean)i0, 1u);
  Object_Boxed__true = (Object_Boxed__Boolean)i0;
  i0 = (OOC_INT32)Object__NewLatin1("TRUE", 5);
  Object_Boxed__trueString = (Object__String)i0;
  i0 = (OOC_INT32)RT0__NewObject(_td_Object_Boxed__Boolean.baseTypes[0]);
  Object_Boxed__BooleanDesc_INIT((Object_Boxed__Boolean)i0, 0u);
  Object_Boxed__false = (Object_Boxed__Boolean)i0;
  i0 = (OOC_INT32)Object__NewLatin1("FALSE", 6);
  Object_Boxed__falseString = (Object__String)i0;
  i0 = (OOC_INT32)RT0__NewObject(_td_Object_Boxed__LongReal.baseTypes[0]);
  Object_Boxed__LongRealDesc_INIT((Object_Boxed__LongReal)i0, 0.0000000000000000);
  Object_Boxed__zeroLongReal = (Object_Boxed__LongReal)i0;
  i0 = (OOC_INT32)RT0__NewObject(_td_Object_Boxed__LongInt.baseTypes[0]);
  Object_Boxed__LongIntDesc_INIT((Object_Boxed__LongInt)i0, 0);
  Object_Boxed__zeroLongInt = (Object_Boxed__LongInt)i0;
  i0 = (OOC_INT32)RT0__NewObject(_td_Object_Boxed__String.baseTypes[0]);
  Object_Boxed__emptyString = (Object_Boxed__String)i0;
  i1 = (OOC_INT32)Object__NewLatin1("", 1);
  *(OOC_INT32*)(_check_pointer(i0, 14929)) = i1;
  return;
  ;
}

/* --- */
