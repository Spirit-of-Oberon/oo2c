#include <Config.d>
#include <__oo2c.h>
#include <setjmp.h>

void Config__InitConfig(Config__Config config) {

  return;
  ;
}

void Config__VariableDesc_StringToValue(Config__Variable v, Object__String str) {

  return;
  ;
}

Object__String Config__VariableDesc_ToString(Config__Variable v) {

  _failed_function(1039); return 0;
  ;
}

Config__Variable Config__VariableDesc_Clone(Config__Variable v) {

  _failed_function(1112); return 0;
  ;
}

Config__BooleanVar Config__NewBooleanVar(OOC_CHAR8 boolean) {
  register OOC_INT32 i0,i1;
  Config__BooleanVar s;

  i0 = (OOC_INT32)RT0__NewObject(_td_Config__BooleanVar.baseTypes[0]);
  s = (Config__BooleanVar)i0;
  i1 = boolean;
  *(OOC_UINT8*)(_check_pointer(i0, 1256)) = i1;
  return (Config__BooleanVar)i0;
  ;
}

void Config__BooleanVarDesc_StringToValue(Config__BooleanVar v, Object__String str) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_INT32 i;
  OOC_INT32 start;
  Object__String strip;

  i = 0;
  i0 = (OOC_INT32)str;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 1529));
  i1 = 0!=i1;
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1544)))), Object__StringDesc_CharAt)),Object__StringDesc_CharAt)((Object__String)i0, 0);
  i1 = (OOC_UINT32)i1<=(OOC_UINT32)32u;
  
l5:
  if (i1) goto l7;
  i1=0;
  goto l17;
l7:
  i1=0;
l8_loop:
  i1 = i1+1;
  i = i1;
  i2 = *(OOC_INT32*)(_check_pointer(i0, 1529));
  i2 = i1!=i2;
  if (i2) goto l11;
  i2=0u;
  goto l13;
l11:
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1544)))), Object__StringDesc_CharAt)),Object__StringDesc_CharAt)((Object__String)i0, i1);
  i2 = (OOC_UINT32)i2<=(OOC_UINT32)32u;
  
l13:
  if (i2) goto l8_loop;
l17:
  start = i1;
  i2 = *(OOC_INT32*)(_check_pointer(i0, 1669));
  i = i2;
  i3 = i2>0;
  if (i3) goto l20;
  i3=0u;
  goto l22;
l20:
  i3 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1702)))), Object__StringDesc_CharAt)),Object__StringDesc_CharAt)((Object__String)i0, (i2-1));
  i3 = (OOC_UINT32)i3<=(OOC_UINT32)32u;
  
l22:
  if (!i3) goto l34;
l25_loop:
  i2 = i2-1;
  i = i2;
  i3 = i2>0;
  if (i3) goto l28;
  i3=0u;
  goto l30;
l28:
  i3 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1702)))), Object__StringDesc_CharAt)),Object__StringDesc_CharAt)((Object__String)i0, (i2-1));
  i3 = (OOC_UINT32)i3<=(OOC_UINT32)32u;
  
l30:
  if (i3) goto l25_loop;
l34:
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1770)))), Object__StringDesc_Substring)),Object__StringDesc_Substring)((Object__String)i0, i1, i2);
  strip = (Object__String)i0;
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1804)))), Object__StringDesc_Equals)),Object__StringDesc_Equals)((Object__String)i0, (Object__Object)((OOC_INT32)_c0));
  if (i2) goto l41;
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1865)))), Object__StringDesc_Equals)),Object__StringDesc_Equals)((Object__String)i0, (Object__Object)((OOC_INT32)_c1));
  if (i0) goto l39;
  i0 = (OOC_INT32)RT0__NewObject(_td_Exception__ParseError.baseTypes[0]);
  Exception__ParseErrorDesc_INIT((Exception__ParseError)i0, (Object__String)((OOC_INT32)_c2), i1);
  Exception__Raise((void*)i0);
  goto l42;
l39:
  i0 = (OOC_INT32)v;
  *(OOC_UINT8*)(_check_pointer(i0, 1894)) = 0u;
  goto l42;
l41:
  i0 = (OOC_INT32)v;
  *(OOC_UINT8*)(_check_pointer(i0, 1832)) = 1u;
l42:
  return;
  ;
}

Object__String Config__BooleanVarDesc_ToString(Config__BooleanVar v) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)v;
  i0 = *(OOC_UINT8*)(_check_pointer(i0, 2075));
  if (i0) goto l3;
  return (Object__String)((OOC_INT32)_c3);
  goto l4;
l3:
  return (Object__String)((OOC_INT32)_c4);
l4:
  _failed_function(2038); return 0;
  ;
}

Config__BooleanVar Config__BooleanVarDesc_Clone(Config__BooleanVar v) {
  register OOC_INT32 i0,i1,i2,i3;
  Config__BooleanVar clone;

  i0 = (OOC_INT32)RT0__NewObject(_td_Config__BooleanVar.baseTypes[0]);
  clone = (Config__BooleanVar)i0;
  i1 = (OOC_INT32)v;
  i1 = _check_pointer(i1, 2284);
  i2 = _check_pointer(i0, 2278);
  i3 = (OOC_INT32)&_td_Config__BooleanVarDesc;
  i3 = i3!=i3;
  if (!i3) goto l4;
  _failed_type_assert(2278);
l4:
  _copy_block(i1,i2,1);
  return (Config__BooleanVar)i0;
  ;
}

Config__IntegerVar Config__NewIntegerVar(OOC_INT32 _int) {
  register OOC_INT32 i0,i1;
  Config__IntegerVar s;

  i0 = (OOC_INT32)RT0__NewObject(_td_Config__IntegerVar.baseTypes[0]);
  s = (Config__IntegerVar)i0;
  i1 = _int;
  *(OOC_INT32*)(_check_pointer(i0, 2424)) = i1;
  return (Config__IntegerVar)i0;
  ;
}

void Config__IntegerVarDesc_StringToValue(Config__IntegerVar v, Object__String str) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_INT32 i;
  OOC_INT32 start;
  Object__String strip;
  Object__String8 str8;
  Object__CharsLatin1 chars;
  OOC_INT8 res;
  OOC_INT32 _int;

  i = 0;
  i0 = (OOC_INT32)str;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 2797));
  i1 = 0!=i1;
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2812)))), Object__StringDesc_CharAt)),Object__StringDesc_CharAt)((Object__String)i0, 0);
  i1 = (OOC_UINT32)i1<=(OOC_UINT32)32u;
  
l5:
  if (i1) goto l7;
  i1=0;
  goto l17;
l7:
  i1=0;
l8_loop:
  i1 = i1+1;
  i = i1;
  i2 = *(OOC_INT32*)(_check_pointer(i0, 2797));
  i2 = i1!=i2;
  if (i2) goto l11;
  i2=0u;
  goto l13;
l11:
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2812)))), Object__StringDesc_CharAt)),Object__StringDesc_CharAt)((Object__String)i0, i1);
  i2 = (OOC_UINT32)i2<=(OOC_UINT32)32u;
  
l13:
  if (i2) goto l8_loop;
l17:
  start = i1;
  i2 = *(OOC_INT32*)(_check_pointer(i0, 2937));
  i = i2;
  i3 = i2>0;
  if (i3) goto l20;
  i3=0u;
  goto l22;
l20:
  i3 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2970)))), Object__StringDesc_CharAt)),Object__StringDesc_CharAt)((Object__String)i0, (i2-1));
  i3 = (OOC_UINT32)i3<=(OOC_UINT32)32u;
  
l22:
  if (!i3) goto l34;
l25_loop:
  i2 = i2-1;
  i = i2;
  i3 = i2>0;
  if (i3) goto l28;
  i3=0u;
  goto l30;
l28:
  i3 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2970)))), Object__StringDesc_CharAt)),Object__StringDesc_CharAt)((Object__String)i0, (i2-1));
  i3 = (OOC_UINT32)i3<=(OOC_UINT32)32u;
  
l30:
  if (i3) goto l25_loop;
l34:
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3033)))), Object__StringDesc_Substring)),Object__StringDesc_Substring)((Object__String)i0, i1, i2);
  strip = (Object__String)i0;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3072)))), Object__StringDesc_ToString8)),Object__StringDesc_ToString8)((Object__String)i0, 63u);
  str8 = (Object__String8)i0;
  i0 = (OOC_INT32)Object__String8Desc_CharsLatin1((Object__String8)i0);
  chars = (Object__CharsLatin1)i0;
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i0, 3153)), 0);
  IntStr__StrToInt((void*)(_check_pointer(i0, 3153)), i2, (void*)(OOC_INT32)&_int, (void*)(OOC_INT32)&res);
  i0 = res;
  switch (i0) {
  case 0:
    i0 = (OOC_INT32)v;
    i1 = _int;
    *(OOC_INT32*)(_check_pointer(i0, 3216)) = i1;
    goto l41;
  case 2:
    i0 = (OOC_INT32)RT0__NewObject(_td_Exception__ParseError.baseTypes[0]);
    Exception__ParseErrorDesc_INIT((Exception__ParseError)i0, (Object__String)((OOC_INT32)_c5), i1);
    Exception__Raise((void*)i0);
    goto l41;
  case 1:
    i0 = (OOC_INT32)RT0__NewObject(_td_Exception__ParseError.baseTypes[0]);
    Exception__ParseErrorDesc_INIT((Exception__ParseError)i0, (Object__String)((OOC_INT32)_c6), i1);
    Exception__Raise((void*)i0);
    goto l41;
  case 3:
    i0 = (OOC_INT32)RT0__NewObject(_td_Exception__ParseError.baseTypes[0]);
    Exception__ParseErrorDesc_INIT((Exception__ParseError)i0, (Object__String)((OOC_INT32)_c7), i1);
    Exception__Raise((void*)i0);
    goto l41;
  default:
    _failed_case(i0, 3171);
    goto l41;
  }
l41:
  return;
  ;
}

Object__String Config__IntegerVarDesc_ToString(Config__IntegerVar v) {
  register OOC_INT32 i0;
  OOC_CHAR8 str[16];

  i0 = (OOC_INT32)v;
  i0 = *(OOC_INT32*)(_check_pointer(i0, 3627));
  IntStr__IntToStr(i0, (void*)(OOC_INT32)str, 16);
  i0 = (OOC_INT32)Object__NewLatin1((void*)(OOC_INT32)str, 16);
  return (Object__String)i0;
  ;
}

Config__IntegerVar Config__IntegerVarDesc_Clone(Config__IntegerVar v) {
  register OOC_INT32 i0,i1,i2,i3;
  Config__IntegerVar clone;

  i0 = (OOC_INT32)RT0__NewObject(_td_Config__IntegerVar.baseTypes[0]);
  clone = (Config__IntegerVar)i0;
  i1 = (OOC_INT32)v;
  i1 = _check_pointer(i1, 3812);
  i2 = _check_pointer(i0, 3806);
  i3 = (OOC_INT32)&_td_Config__IntegerVarDesc;
  i3 = i3!=i3;
  if (!i3) goto l4;
  _failed_type_assert(3806);
l4:
  _copy_block(i1,i2,4);
  return (Config__IntegerVar)i0;
  ;
}

Config__StringVar Config__NewStringVar(Object__String8 str) {
  register OOC_INT32 i0,i1;
  Config__StringVar s;

  i0 = (OOC_INT32)RT0__NewObject(_td_Config__StringVar.baseTypes[0]);
  s = (Config__StringVar)i0;
  i1 = (OOC_INT32)str;
  *(OOC_INT32*)(_check_pointer(i0, 3955)) = i1;
  return (Config__StringVar)i0;
  ;
}

void Config__StringVarDesc_StringToValue(Config__StringVar v, Object__String str) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)str;
  *(OOC_INT32*)(_check_pointer(i0, 4073)) = i1;
  return;
  ;
}

Object__String Config__StringVarDesc_ToString(Config__StringVar v) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)v;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4177));
  return (Object__String)i0;
  ;
}

Config__StringVar Config__StringVarDesc_Clone(Config__StringVar v) {
  register OOC_INT32 i0,i1,i2,i3;
  Config__StringVar clone;

  i0 = (OOC_INT32)RT0__NewObject(_td_Config__StringVar.baseTypes[0]);
  clone = (Config__StringVar)i0;
  i1 = (OOC_INT32)v;
  i1 = _check_pointer(i1, 4318);
  i2 = _check_pointer(i0, 4312);
  i3 = (OOC_INT32)&_td_Config__StringVarDesc;
  i3 = i3!=i3;
  if (!i3) goto l4;
  _failed_type_assert(4312);
l4:
  _copy_block(i1,i2,4);
  return (Config__StringVar)i0;
  ;
}

void Config__SetPrototype(ADT_Dictionary__Dictionary map, Object__String name, Config__Variable prototype) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)prototype;
  i1 = (OOC_INT32)name;
  i2 = (OOC_INT32)map;
  ADT_Dictionary__DictionaryDesc_Set((ADT_Dictionary__Dictionary)i2, (Object__Object)i1, (Object__Object)i0);
  return;
  ;
}

Config__Variable Config__GetClone(ADT_Dictionary__Dictionary map, Object__String prototypeName) {
  register OOC_INT32 i0,i1;
  Config__Variable ptr;

  i0 = (OOC_INT32)prototypeName;
  i1 = (OOC_INT32)map;
  i0 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i1, (Object__Object)i0);
  ptr = (Config__Variable)i0;
  i1 = i0==(OOC_INT32)0;
  if (i1) goto l3;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4698)))), Config__VariableDesc_Clone)),Config__VariableDesc_Clone)((Config__Variable)i0);
  return (Config__Variable)i0;
  goto l4;
l3:
  return (Config__Variable)(OOC_INT32)0;
l4:
  _failed_function(4501); return 0;
  ;
}

void OOC_Config_init(void) {
  _c0 = Object__NewLatin1Region("TRUE", 5, 0, 4);
  _c1 = Object__NewLatin1Region("FALSE", 6, 0, 5);
  _c2 = Object__NewLatin1Region("Invalid format", 15, 0, 14);
  _c3 = Object__NewLatin1Region("FALSE", 6, 0, 5);
  _c4 = Object__NewLatin1Region("TRUE", 5, 0, 4);
  _c5 = Object__NewLatin1Region("Invalid format", 15, 0, 14);
  _c6 = Object__NewLatin1Region("Value out of range", 19, 0, 18);
  _c7 = Object__NewLatin1Region("Value is empty", 15, 0, 14);

  return;
  ;
}

void OOC_Config_destroy(void) {
}

/* --- */
