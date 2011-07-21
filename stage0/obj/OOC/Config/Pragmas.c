#include <OOC/Config/Pragmas.d>
#include <__oo2c.h>
#include <setjmp.h>

static void OOC_Config_Pragmas__Init(OOC_Config_Pragmas__Section s, const Config_Parser__String id__ref, OOC_LEN id_0d, ADT_Dictionary__Dictionary prototypeMap) {
  register OOC_INT32 i0,i1;
  OOC_ALLOCATE_VPAR(id,OOC_CHAR16 ,id_0d)

  OOC_INITIALIZE_VPAR(id__ref,id,OOC_CHAR16 ,(id_0d*2))
  i0 = (OOC_INT32)prototypeMap;
  i1 = (OOC_INT32)s;
  Config_Section_Options__Init((Config_Section_Options__Section)i1, (void*)(OOC_INT32)id, id_0d, (ADT_Dictionary__Dictionary)i0);
  return;
  ;
}

OOC_Config_Pragmas__Section OOC_Config_Pragmas__New(void) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Config_Pragmas__Section.baseTypes[0]);
  i1 = (OOC_INT32)RT0__NewObject(_td__qtd1.baseTypes[0]);
  ADT_Dictionary__DictionaryDesc_INIT((ADT_Dictionary__Dictionary)i1);
  i2 = (OOC_INT32)Config__NewBooleanVar(0u);
  Config__SetPrototype((ADT_Dictionary__Dictionary)i1, (Object__String)((OOC_INT32)_c0), (Config__Variable)i2);
  i2 = (OOC_INT32)Config__NewIntegerVar(0);
  Config__SetPrototype((ADT_Dictionary__Dictionary)i1, (Object__String)((OOC_INT32)_c1), (Config__Variable)i2);
  i2 = (OOC_INT32)Config__NewStringVar((Object__String8)((OOC_INT32)_c2));
  Config__SetPrototype((ADT_Dictionary__Dictionary)i1, (Object__String)((OOC_INT32)_c3), (Config__Variable)i2);
  OOC_Config_Pragmas__Init((OOC_Config_Pragmas__Section)i0, ((OOC_CHAR16[]){112,114,97,103,109,97,115,0}), 8, (ADT_Dictionary__Dictionary)i1);
  return (OOC_Config_Pragmas__Section)i0;
  ;
}

void OOC_Config_Pragmas__SectionDesc_Copy(OOC_Config_Pragmas__Section s, Config_Section_Options__Section dest) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)dest;
  i1 = (OOC_INT32)s;
  Config_Section_Options__SectionDesc_Copy((Config_Section_Options__Section)i1, (Config_Section_Options__Section)i0);
  return;
  ;
}

OOC_Config_Pragmas__Section OOC_Config_Pragmas__SectionDesc_Clone(OOC_Config_Pragmas__Section s) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Config_Pragmas__Section.baseTypes[0]);
  i1 = (OOC_INT32)s;
  OOC_Config_Pragmas__SectionDesc_Copy((OOC_Config_Pragmas__Section)i1, (Config_Section_Options__Section)i0);
  return (OOC_Config_Pragmas__Section)i0;
  ;
}

static void OOC_Config_Pragmas__InitHistory(OOC_Config_Pragmas__History h, OOC_Config_Pragmas__Section startVariables) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)h;
  i1 = (OOC_INT32)startVariables;
  *(OOC_INT32*)(_check_pointer(i0, 2617)) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 2658))+4) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 2681))+8) = (-1);
  *(OOC_INT32*)((_check_pointer(i0, 2707))+12) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 2729))+16) = 0;
  return;
  ;
}

OOC_Config_Pragmas__History OOC_Config_Pragmas__NewHistory(OOC_Config_Pragmas__Section startVariables) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Config_Pragmas__History.baseTypes[0]);
  i1 = (OOC_INT32)startVariables;
  OOC_Config_Pragmas__InitHistory((OOC_Config_Pragmas__History)i0, (OOC_Config_Pragmas__Section)i1);
  return (OOC_Config_Pragmas__History)i0;
  ;
}

static Config__Variable OOC_Config_Pragmas__GetValue(OOC_Config_Pragmas__History h, OOC_Config_Pragmas__Variable var, OOC_INT32 charPos) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_INT32 l;
  OOC_INT32 r;
  OOC_INT32 m;

  i0 = (OOC_INT32)var;
  _assert((i0!=(OOC_INT32)0), 127, 3331);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3372))+12);
  i1 = _check_pointer(i1, 3382);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = *(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 3382))*4);
  i2 = charPos;
  i1 = i2<i1;
  if (i1) goto l16;
  l = 0;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 3658))+16);
  r = i1;
  i3 = 1!=i1;
  if (i3) goto l5;
  i1=0;
  goto l15;
l5:
  i3=i1;i1=0;
l6_loop:
  i4 = (i1+i3)>>1;
  m = i4;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3887))+12);
  i5 = _check_pointer(i5, 3897);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = *(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 3897))*4);
  i5 = i5<=i2;
  if (i5) goto l9;
  r = i4;
  i3=i4;
  goto l10;
l9:
  l = i4;
  i1=i4;
l10:
  i4 = (i1+1)!=i3;
  if (i4) goto l6_loop;
l15:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4004))+8);
  i0 = _check_pointer(i0, 4012);
  i2 = OOC_ARRAY_LENGTH(i0, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(i1, i2, OOC_UINT32, 4012))*4);
  return (Config__Variable)i0;
  goto l17;
l16:
  i1 = (OOC_INT32)h;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 3588));
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3619))+4);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 3588));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 3604)))), Config_Section_Options__SectionDesc_GetValue)),Config_Section_Options__SectionDesc_GetValue)((Config_Section_Options__Section)i1, (Object__String)i0);
  return (Config__Variable)i0;
l17:
  _failed_function(3198); return 0;
  ;
}

Config__Variable OOC_Config_Pragmas__HistoryDesc_GetValue(OOC_Config_Pragmas__History h, Object__String name, OOC_INT32 charPos) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_Config_Pragmas__Variable var;

  i0 = (OOC_INT32)h;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4170))+4);
  var = (OOC_Config_Pragmas__Variable)i1;
  i2 = i1!=(OOC_INT32)0;
  if (i2) goto l3;
  i2=0u;
  goto l5;
l3:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4209))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4209))+4);
  i4 = (OOC_INT32)name;
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 4214)))), Object__StringDesc_Equals)),Object__StringDesc_Equals)((Object__String)i3, (Object__Object)i4);
  i2 = !i2;
  
l5:
  if (!i2) goto l17;
  i2 = (OOC_INT32)name;
  
l8_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 4247));
  var = (OOC_Config_Pragmas__Variable)i1;
  i3 = i1!=(OOC_INT32)0;
  if (i3) goto l11;
  i3=0u;
  goto l13;
l11:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4209))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4209))+4);
  i3 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 4214)))), Object__StringDesc_Equals)),Object__StringDesc_Equals)((Object__String)i4, (Object__Object)i2);
  i3 = !i3;
  
l13:
  if (i3) goto l8_loop;
l17:
  i2 = i1==(OOC_INT32)0;
  if (i2) goto l20;
  i2 = charPos;
  i0 = (OOC_INT32)OOC_Config_Pragmas__GetValue((OOC_Config_Pragmas__History)i0, (OOC_Config_Pragmas__Variable)i1, i2);
  return (Config__Variable)i0;
  goto l21;
l20:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4301));
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4301));
  i2 = (OOC_INT32)name;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4317)))), Config_Section_Options__SectionDesc_GetValue)),Config_Section_Options__SectionDesc_GetValue)((Config_Section_Options__Section)i0, (Object__String)i2);
  return (Config__Variable)i0;
l21:
  _failed_function(4064); return 0;
  ;
}

static void OOC_Config_Pragmas__LastCharPos(OOC_Config_Pragmas__History h, OOC_INT32 charPos) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)h;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 4494))+8);
  i2 = charPos;
  _assert((i2>i1), 127, 4475);
  *(OOC_INT32*)((_check_pointer(i0, 4515))+8) = i2;
  return;
  ;
}

static void OOC_Config_Pragmas__SetValue(OOC_Config_Pragmas__Variable var, OOC_INT32 charPos, Config__Variable value) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  auto void OOC_Config_Pragmas__SetValue_Extend(OOC_Config_Pragmas__Variable var, OOC_INT32 size);
    
    void OOC_Config_Pragmas__SetValue_Extend(OOC_Config_Pragmas__Variable var, OOC_INT32 size) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9;
      OOC_Config_Pragmas__ValueArray newValues;
      OOC_Config_Pragmas__CharPosArray newPos;
      OOC_INT32 i;

      i0 = size;
      i1 = (OOC_INT32)RT0__NewObject(_td_OOC_Config_Pragmas__ValueArray.baseTypes[0], i0);
      newValues = (OOC_Config_Pragmas__ValueArray)i1;
      i2 = (OOC_INT32)RT0__NewObject(_td_OOC_Config_Pragmas__CharPosArray.baseTypes[0], i0);
      newPos = (OOC_Config_Pragmas__CharPosArray)i2;
      i3 = (OOC_INT32)var;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 4925))+8);
      i = 0;
      i4 = OOC_ARRAY_LENGTH((_check_pointer(i4, 4933)), 0);
      i5 = 0<i4;
      if (!i5) goto l8;
      i5=0;
l3_loop:
      i6 = _check_pointer(i1, 4958);
      i7 = OOC_ARRAY_LENGTH(i6, 0);
      i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 4968))+8);
      i8 = _check_pointer(i8, 4976);
      i9 = OOC_ARRAY_LENGTH(i8, 0);
      i8 = (OOC_INT32)*(OOC_INT32*)(i8+(_check_index(i5, i9, OOC_UINT32, 4976))*4);
      *(OOC_INT32*)(i6+(_check_index(i5, i7, OOC_UINT32, 4958))*4) = i8;
      i6 = _check_pointer(i2, 4995);
      i7 = OOC_ARRAY_LENGTH(i6, 0);
      i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 5005))+12);
      i8 = _check_pointer(i8, 5015);
      i9 = OOC_ARRAY_LENGTH(i8, 0);
      i8 = *(OOC_INT32*)(i8+(_check_index(i5, i9, OOC_UINT32, 5015))*4);
      *(OOC_INT32*)(i6+(_check_index(i5, i7, OOC_UINT32, 4995))*4) = i8;
      i5 = i5+1;
      i = i5;
      i6 = i5<i4;
      if (i6) goto l3_loop;
l8:
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 5053))+8);
      i4 = OOC_ARRAY_LENGTH((_check_pointer(i4, 5061)), 0);
      i = i4;
      i5 = i4<i0;
      if (!i5) goto l16;
l11_loop:
      i5 = _check_pointer(i1, 5094);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      *(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 5094))*4) = (OOC_INT32)0;
      i5 = _check_pointer(i2, 5120);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      *(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 5120))*4) = (-1);
      i4 = i4+1;
      i = i4;
      i5 = i4<i0;
      if (i5) goto l11_loop;
l16:
      *(OOC_INT32*)((_check_pointer(i3, 5157))+8) = i1;
      *(OOC_INT32*)((_check_pointer(i3, 5189))+12) = i2;
      return;
      ;
    }


  i0 = (OOC_INT32)var;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5271))+8);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 5249))+16);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 5279)), 0);
  i1 = i2==i1;
  if (!i1) goto l4;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 5334))+16);
  OOC_Config_Pragmas__SetValue_Extend((OOC_Config_Pragmas__Variable)i0, (i1+4));
l4:
  i0 = (OOC_INT32)var;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5382))+8);
  i1 = _check_pointer(i1, 5390);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 5394))+16);
  i3 = OOC_ARRAY_LENGTH(i1, 0);
  i4 = (OOC_INT32)value;
  *(OOC_INT32*)(i1+(_check_index(i2, i3, OOC_UINT32, 5390))*4) = i4;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5424))+12);
  i1 = _check_pointer(i1, 5434);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i3 = *(OOC_INT32*)((_check_pointer(i0, 5438))+16);
  i4 = charPos;
  *(OOC_INT32*)(i1+(_check_index(i3, i2, OOC_UINT32, 5434))*4) = i4;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 5475))+16);
  *(OOC_INT32*)((_check_pointer(i0, 5475))+16) = (i1+1);
  return;
  ;
}

void OOC_Config_Pragmas__HistoryDesc_SetValue(OOC_Config_Pragmas__History h, Object__String name, OOC_INT32 charPos, Config__Variable value) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_Config_Pragmas__Variable var;

  i0 = charPos;
  i1 = (OOC_INT32)h;
  OOC_Config_Pragmas__LastCharPos((OOC_Config_Pragmas__History)i1, i0);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6025))+4);
  var = (OOC_Config_Pragmas__Variable)i2;
  i3 = i2!=(OOC_INT32)0;
  if (i3) goto l3;
  i3=0u;
  goto l5;
l3:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 6064))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 6064))+4);
  i5 = (OOC_INT32)name;
  i3 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 6069)))), Object__StringDesc_Equals)),Object__StringDesc_Equals)((Object__String)i4, (Object__Object)i5);
  i3 = !i3;
  
l5:
  if (!i3) goto l17;
  i3 = (OOC_INT32)name;
  
l8_loop:
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 6102));
  var = (OOC_Config_Pragmas__Variable)i2;
  i4 = i2!=(OOC_INT32)0;
  if (i4) goto l11;
  i4=0u;
  goto l13;
l11:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 6064))+4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 6064))+4);
  i4 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 6069)))), Object__StringDesc_Equals)),Object__StringDesc_Equals)((Object__String)i5, (Object__Object)i3);
  i4 = !i4;
  
l13:
  if (i4) goto l8_loop;
l17:
  i3 = i2==(OOC_INT32)0;
  if (i3) goto l20;
  i1=i2;
  goto l21;
l20:
  i2 = (OOC_INT32)RT0__NewObject(_td_OOC_Config_Pragmas__Variable.baseTypes[0]);
  var = (OOC_Config_Pragmas__Variable)i2;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6283))+4);
  *(OOC_INT32*)(_check_pointer(i2, 6272)) = i3;
  i3 = (OOC_INT32)name;
  *(OOC_INT32*)((_check_pointer(i2, 6303))+4) = i3;
  *(OOC_INT32*)((_check_pointer(i2, 6333))+8) = ((OOC_INT32)RT0__NewObject(_td_OOC_Config_Pragmas__ValueArray.baseTypes[0], 4));
  *(OOC_INT32*)((_check_pointer(i2, 6371))+12) = ((OOC_INT32)RT0__NewObject(_td_OOC_Config_Pragmas__CharPosArray.baseTypes[0], 4));
  *(OOC_INT32*)((_check_pointer(i2, 6406))+16) = 0;
  *(OOC_INT32*)((_check_pointer(i1, 6438))+4) = i2;
  i1=i2;
l21:
  i2 = (OOC_INT32)value;
  OOC_Config_Pragmas__SetValue((OOC_Config_Pragmas__Variable)i1, i0, (Config__Variable)i2);
  return;
  ;
}

void OOC_Config_Pragmas__HistoryDesc_Push(OOC_Config_Pragmas__History h) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
  OOC_Config_Pragmas__CharPosArray _new;
  OOC_INT32 i;

  i0 = (OOC_INT32)h;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6651))+12);
  i1 = i1==(OOC_INT32)0;
  if (i1) goto l14;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6729))+12);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 6709))+16);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 6737)), 0);
  i1 = i2==i1;
  if (!i1) goto l15;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6768))+12);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 6776)), 0);
  i1 = (OOC_INT32)RT0__NewObject(_td_OOC_Config_Pragmas__CharPosArray.baseTypes[0], (i1*2));
  _new = (OOC_Config_Pragmas__CharPosArray)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6809))+12);
  i = 0;
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 6817)), 0);
  i3 = 0<i2;
  if (!i3) goto l15;
  i3=0;
l7_loop:
  i4 = _check_pointer(i1, 6836);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6844))+12);
  i6 = _check_pointer(i6, 6852);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = *(OOC_INT32*)(i6+(_check_index(i3, i7, OOC_UINT32, 6852))*4);
  *(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 6836))*4) = i6;
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l7_loop;
  goto l15;
l14:
  *(OOC_INT32*)((_check_pointer(i0, 6684))+12) = ((OOC_INT32)RT0__NewObject(_td_OOC_Config_Pragmas__CharPosArray.baseTypes[0], 4));
l15:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6880))+12);
  i1 = _check_pointer(i1, 6888);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 6890))+16);
  i3 = OOC_ARRAY_LENGTH(i1, 0);
  i4 = *(OOC_INT32*)((_check_pointer(i0, 6907))+8);
  *(OOC_INT32*)(i1+(_check_index(i2, i3, OOC_UINT32, 6888))*4) = i4;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 6932))+16);
  *(OOC_INT32*)((_check_pointer(i0, 6932))+16) = (i1+1);
  return;
  ;
}

void OOC_Config_Pragmas__HistoryDesc_Pop(OOC_Config_Pragmas__History h, OOC_INT32 charPos) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_INT32 pushPos;
  OOC_Config_Pragmas__Variable var;
  Config__Variable oldValue;

  i0 = charPos;
  i1 = (OOC_INT32)h;
  OOC_Config_Pragmas__LastCharPos((OOC_Config_Pragmas__History)i1, i0);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 7143))+12);
  i2 = _check_pointer(i2, 7151);
  i3 = *(OOC_INT32*)((_check_pointer(i1, 7153))+16);
  i4 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = *(OOC_INT32*)(i2+(_check_index((i3-1), i4, OOC_UINT32, 7151))*4);
  pushPos = i2;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 7181))+4);
  var = (OOC_Config_Pragmas__Variable)i3;
  i4 = i3!=(OOC_INT32)0;
  if (!i4) goto l14;
l3_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 7230))+12);
  i4 = _check_pointer(i4, 7240);
  i5 = *(OOC_INT32*)((_check_pointer(i3, 7244))+16);
  i6 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = *(OOC_INT32*)(i4+(_check_index((i5-1), i6, OOC_UINT32, 7240))*4);
  i4 = i4>i2;
  if (!i4) goto l9;
  i4 = (OOC_INT32)OOC_Config_Pragmas__GetValue((OOC_Config_Pragmas__History)i1, (OOC_Config_Pragmas__Variable)i3, i2);
  oldValue = (Config__Variable)i4;
  i5 = i4!=(OOC_INT32)0;
  if (!i5) goto l9;
  OOC_Config_Pragmas__SetValue((OOC_Config_Pragmas__Variable)i3, i0, (Config__Variable)i4);
l9:
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 7541));
  var = (OOC_Config_Pragmas__Variable)i3;
  i4 = i3!=(OOC_INT32)0;
  if (i4) goto l3_loop;
l14:
  i0 = *(OOC_INT32*)((_check_pointer(i1, 7572))+16);
  *(OOC_INT32*)((_check_pointer(i1, 7572))+16) = (i0-1);
  return;
  ;
}

void OOC_OOC_Config_Pragmas_init(void) {
  _c0 = Object__NewLatin1Region("boolean", 8, 0, 7);
  _c1 = Object__NewLatin1Region("integer", 8, 0, 7);
  _c2 = Object__NewLatin1Region("", 1, 0, 0);
  _c3 = Object__NewLatin1Region("string", 7, 0, 6);

  return;
  ;
}

/* --- */
