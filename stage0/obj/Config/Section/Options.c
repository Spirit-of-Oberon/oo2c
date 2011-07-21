#include <Config/Section/Options.d>
#include <__oo2c.h>
#include <setjmp.h>

void Config_Section_Options__ErrorContextDesc_GetTemplate(Config_Section_Options__ErrorContext context, Msg__Msg msg, Msg__LString templ, OOC_LEN templ_0d) {
  register OOC_INT32 i0,i1;
  OOC_CHAR16 t[128];

  i0 = (OOC_INT32)msg;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 1036))+8);
  switch (i1) {
  case 1:
    _copy_16((const void*)((OOC_CHAR16[]){73,110,118,97,108,105,100,32,99,111,110,116,101,110,116,32,102,111,114,32,101,108,101,109,101,110,116,32,96,36,123,110,97,109,101,125,39,0}),(void*)(OOC_INT32)t,128);
    goto l12;
  case 2:
    _copy_16((const void*)((OOC_CHAR16[]){65,116,116,114,105,98,117,116,101,32,96,36,123,110,97,109,101,125,39,32,105,115,32,110,111,116,32,100,101,102,105,110,101,100,32,102,111,114,32,116,104,105,115,32,101,108,101,109,101,110,116,0}),(void*)(OOC_INT32)t,128);
    goto l12;
  case 3:
    _copy_16((const void*)((OOC_CHAR16[]){84,104,105,115,32,101,108,101,109,101,110,116,32,114,101,113,117,105,114,101,115,32,97,110,32,97,116,116,114,105,98,117,116,101,32,96,110,97,109,101,39,0}),(void*)(OOC_INT32)t,128);
    goto l12;
  case 4:
    _copy_16((const void*)((OOC_CHAR16[]){84,104,105,115,32,101,108,101,109,101,110,116,32,114,101,113,117,105,114,101,115,32,97,110,32,97,116,116,114,105,98,117,116,101,32,96,116,121,112,101,39,0}),(void*)(OOC_INT32)t,128);
    goto l12;
  case 5:
    _copy_16((const void*)((OOC_CHAR16[]){84,104,105,115,32,101,108,101,109,101,110,116,32,109,117,115,116,32,99,111,110,116,97,105,110,32,99,104,97,114,97,99,116,101,114,32,100,97,116,97,32,111,110,108,121,0}),(void*)(OOC_INT32)t,128);
    goto l12;
  case 6:
    _copy_16((const void*)((OOC_CHAR16[]){79,112,116,105,111,110,32,96,36,123,110,97,109,101,125,39,32,105,115,32,97,108,114,101,97,100,121,32,100,101,102,105,110,101,100,0}),(void*)(OOC_INT32)t,128);
    goto l12;
  case 7:
    _copy_16((const void*)((OOC_CHAR16[]){79,112,116,105,111,110,32,96,36,123,110,97,109,101,125,39,32,105,115,32,110,111,116,32,100,101,102,105,110,101,100,0}),(void*)(OOC_INT32)t,128);
    goto l12;
  case 8:
    _copy_16((const void*)((OOC_CHAR16[]){84,121,112,101,32,96,36,123,116,121,112,101,125,39,32,105,115,32,110,111,116,32,115,117,112,112,111,114,116,101,100,32,102,111,114,32,111,112,116,105,111,110,32,118,97,114,105,97,98,108,101,115,0}),(void*)(OOC_INT32)t,128);
    goto l12;
  case 9:
    _copy_16((const void*)((OOC_CHAR16[]){73,110,118,97,108,105,100,32,118,97,108,117,101,58,32,36,123,114,101,97,115,111,110,125,0}),(void*)(OOC_INT32)t,128);
    goto l12;
  default:
    _failed_case(i1, 1028);
    goto l12;
  }
l12:
  i1 = (OOC_INT32)context;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 1772)))), XML_Error__ContextDesc_WriteTemplate)),XML_Error__ContextDesc_WriteTemplate)((XML_Error__Context)i1, (Msg__Msg)i0, (void*)(OOC_INT32)t, 128, (void*)(OOC_INT32)templ, templ_0d);
  return;
  ;
}

void Config_Section_Options__Init(Config_Section_Options__Section s, const Config_Parser__String id__ref, OOC_LEN id_0d, ADT_Dictionary__Dictionary typeMap) {
  register OOC_INT32 i0,i1;
  OOC_ALLOCATE_VPAR(id,OOC_CHAR16 ,id_0d)

  OOC_INITIALIZE_VPAR(id__ref,id,OOC_CHAR16 ,(id_0d*2))
  i0 = (OOC_INT32)s;
  Config_Section__Init((Config_Section__Section)i0, (void*)(OOC_INT32)id, id_0d);
  *(OOC_INT32*)((_check_pointer(i0, 1938))+4) = (OOC_INT32)0;
  i1 = (OOC_INT32)typeMap;
  *(OOC_INT32*)((_check_pointer(i0, 1964))+8) = i1;
  return;
  ;
}

Config_Section_Options__Section Config_Section_Options__New(const Config_Parser__String sectionName__ref, OOC_LEN sectionName_0d, ADT_Dictionary__Dictionary typeMap) {
  register OOC_INT32 i0,i1;
  OOC_ALLOCATE_VPAR(sectionName,OOC_CHAR16 ,sectionName_0d)

  OOC_INITIALIZE_VPAR(sectionName__ref,sectionName,OOC_CHAR16 ,(sectionName_0d*2))
  i0 = (OOC_INT32)typeMap;
  i1 = (OOC_INT32)RT0__NewObject(_td_Config_Section_Options__Section.baseTypes[0]);
  Config_Section_Options__Init((Config_Section_Options__Section)i1, (void*)(OOC_INT32)sectionName, sectionName_0d, (ADT_Dictionary__Dictionary)i0);
  return (Config_Section_Options__Section)i1;
  ;
}

static void Config_Section_Options__InitOption(Config_Section_Options__Option opt, Object__String name, Config__Variable value) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)opt;
  *(OOC_INT32*)(_check_pointer(i0, 2275)) = 0;
  i1 = (OOC_INT32)name;
  *(OOC_INT32*)((_check_pointer(i0, 2297))+4) = i1;
  i1 = (OOC_INT32)value;
  *(OOC_INT32*)((_check_pointer(i0, 2320))+8) = i1;
  return;
  ;
}

static Config_Section_Options__Option Config_Section_Options__NewOption(Object__String name, Config__Variable value) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)RT0__NewObject(_td_Config_Section_Options__Option.baseTypes[0]);
  i1 = (OOC_INT32)value;
  i2 = (OOC_INT32)name;
  Config_Section_Options__InitOption((Config_Section_Options__Option)i0, (Object__String)i2, (Config__Variable)i1);
  return (Config_Section_Options__Option)i0;
  ;
}

static void Config_Section_Options__Insert(Config_Section_Options__Option *list, Config_Section_Options__Option opt) {
  register OOC_INT32 i0,i1,i2,i3,i4;

  i0 = (OOC_INT32)*list;
  i1 = i0==(OOC_INT32)0;
  if (i1) goto l7;
  i1 = (OOC_INT32)opt;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2730))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2730))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 2747))+4);
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 2735)))), Object__StringDesc_Compare)),Object__StringDesc_Compare)((Object__String)i3, (Object__Object)i4);
  i2 = i2<0;
  if (i2) goto l5;
  *(OOC_INT32*)(_check_pointer(i1, 2813)) = i0;
  *list = (Config_Section_Options__Option)i1;
  goto l8;
l5:
  Config_Section_Options__Insert((void*)(_check_pointer(i0, 2782)), (Config_Section_Options__Option)i1);
  goto l8;
l7:
  i0 = (OOC_INT32)opt;
  *(OOC_INT32*)(_check_pointer(i0, 2682)) = (OOC_INT32)0;
  *list = (Config_Section_Options__Option)i0;
l8:
  return;
  ;
}

void Config_Section_Options__OptionDesc_Set(Config_Section_Options__Option opt, Config__Variable value) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)opt;
  i1 = (OOC_INT32)value;
  *(OOC_INT32*)((_check_pointer(i0, 2941))+8) = i1;
  return;
  ;
}

Config_Section_Options__Option Config_Section_Options__SectionDesc_Get(Config_Section_Options__Section s, Object__String name) {
  register OOC_INT32 i0,i1,i2,i3;
  Config_Section_Options__Option opt;

  i0 = (OOC_INT32)s;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3065))+4);
  opt = (Config_Section_Options__Option)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3107))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3107))+4);
  i3 = (OOC_INT32)name;
  i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3112)))), Object__StringDesc_Equals)),Object__StringDesc_Equals)((Object__String)i2, (Object__Object)i3);
  i1 = !i1;
  
l5:
  if (!i1) goto l17;
  i1 = (OOC_INT32)name;
  
l8_loop:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 3145));
  opt = (Config_Section_Options__Option)i0;
  i2 = i0!=(OOC_INT32)0;
  if (i2) goto l11;
  i2=0u;
  goto l13;
l11:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3107))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3107))+4);
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 3112)))), Object__StringDesc_Equals)),Object__StringDesc_Equals)((Object__String)i3, (Object__Object)i1);
  i2 = !i2;
  
l13:
  if (i2) goto l8_loop;
l17:
  return (Config_Section_Options__Option)i0;
  ;
}

Config_Section_Options__Option Config_Section_Options__SectionDesc_Set(Config_Section_Options__Section s, Object__String name, Config__Variable value) {
  register OOC_INT32 i0,i1,i2,i3;
  Config_Section_Options__Option opt;

  i0 = (OOC_INT32)s;
  i1 = (OOC_INT32)name;
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3307)))), Config_Section_Options__SectionDesc_Get)),Config_Section_Options__SectionDesc_Get)((Config_Section_Options__Section)i0, (Object__String)i1);
  i3 = i2==(OOC_INT32)0;
  if (i3) goto l3;
  i0 = (OOC_INT32)value;
  Config_Section_Options__OptionDesc_Set((Config_Section_Options__Option)i2, (Config__Variable)i0);
  i0=i2;
  goto l4;
l3:
  i2 = (OOC_INT32)value;
  i1 = (OOC_INT32)Config_Section_Options__NewOption((Object__String)i1, (Config__Variable)i2);
  opt = (Config_Section_Options__Option)i1;
  Config_Section_Options__Insert((void*)((_check_pointer(i0, 3398))+4), (Config_Section_Options__Option)i1);
  i0=i1;
l4:
  return (Config_Section_Options__Option)i0;
  ;
}

Config__Variable Config_Section_Options__SectionDesc_GetValue(Config_Section_Options__Section s, Object__String name) {
  register OOC_INT32 i0,i1;
  Config_Section_Options__Option opt;

  i0 = (OOC_INT32)s;
  i1 = (OOC_INT32)name;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3594)))), Config_Section_Options__SectionDesc_Get)),Config_Section_Options__SectionDesc_Get)((Config_Section_Options__Section)i0, (Object__String)i1);
  opt = (Config_Section_Options__Option)i0;
  i1 = i0==(OOC_INT32)0;
  if (i1) goto l3;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3674))+8);
  return (Config__Variable)i0;
  goto l4;
l3:
  return (Config__Variable)(OOC_INT32)0;
l4:
  _failed_function(3508); return 0;
  ;
}

void Config_Section_Options__SectionDesc_Copy(Config_Section_Options__Section s, Config_Section_Options__Section dest) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  Config_Section_Options__Option opt;
  Config_Section_Options__Option newOpt;

  i0 = (OOC_INT32)s;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 3809));
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 3809));
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 3815)), 0);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3819))+8);
  i4 = (OOC_INT32)dest;
  Config_Section_Options__Init((Config_Section_Options__Section)i4, (void*)(_check_pointer(i2, 3815)), i1, (ADT_Dictionary__Dictionary)i3);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3843))+4);
  opt = (Config_Section_Options__Option)i0;
  i1 = i0!=0;
  if (!i1) goto l8;
l3_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3923))+8);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3923))+8);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3930)))), Config__VariableDesc_Clone)),Config__VariableDesc_Clone)((Config__Variable)i2);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3912))+4);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 3902)))), Config_Section_Options__SectionDesc_Set)),Config_Section_Options__SectionDesc_Set)((Config_Section_Options__Section)i4, (Object__String)i2, (Config__Variable)i1);
  newOpt = (Config_Section_Options__Option)i1;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 3958));
  opt = (Config_Section_Options__Option)i0;
  i1 = i0!=0;
  if (i1) goto l3_loop;
l8:
  return;
  ;
}

Config_Section_Options__Section Config_Section_Options__SectionDesc_Clone(Config_Section_Options__Section s) {
  register OOC_INT32 i0,i1;
  Config_Section_Options__Section _new;

  i0 = (OOC_INT32)RT0__NewObject(_td_Config_Section_Options__Section.baseTypes[0]);
  _new = (Config_Section_Options__Section)i0;
  i1 = (OOC_INT32)s;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4081)))), Config_Section_Options__SectionDesc_Copy)),Config_Section_Options__SectionDesc_Copy)((Config_Section_Options__Section)i1, (Config_Section_Options__Section)i0);
  return (Config_Section_Options__Section)i0;
  ;
}

void Config_Section_Options__SectionDesc_ProcessElements(volatile Config_Section_Options__Section s, volatile Config_Parser__Element sectionRoot, volatile XML_Locator__ErrorListener errorListener) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  volatile Config_Parser__Node node;
  volatile XML_UnicodeBuffer__CharArray name;
  volatile OOC_INT32 i;
  volatile XML_Builder__Attribute att;
  volatile Msg__Msg lastError;
  volatile Config_Section_Options__Option option;
  volatile XML_UnicodeBuffer__CharArray parserString;
  volatile XML_UnicodeBuffer__CharArray type;
  volatile Object__String name8;
  volatile Config__Variable newValue;
  auto void Config_Section_Options__SectionDesc_ProcessElements_Err(OOC_INT32 code, Config_Parser__Node xmlNode);
  auto void Config_Section_Options__SectionDesc_ProcessElements_SetReason(Exception__Exception e);
  jmp_buf _target0, _target1;
  Exception__Context _context0, _context1;
    
    void Config_Section_Options__SectionDesc_ProcessElements_Err(OOC_INT32 code, Config_Parser__Node xmlNode) {
      register OOC_INT32 i0,i1,i2,i3;

      i0 = (OOC_INT32)xmlNode;
      i1 = (OOC_INT32)errorListener;
      i2 = (OOC_INT32)Config_Section_Options__optionsContext;
      i3 = code;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4612)))), XML_Locator__ErrorListenerDesc_Error)),XML_Locator__ErrorListenerDesc_Error)((XML_Locator__ErrorListener)i1, (XML_Error__Context)i2, i3, 0u, (void*)((_check_pointer(i0, 4657))+4));
      lastError = (Msg__Msg)i0;
      return;
      ;
    }

    
    void Config_Section_Options__SectionDesc_ProcessElements_SetReason(Exception__Exception e) {
      register OOC_INT32 i0,i1;
      Object__String msg;
      Object__CharsLatin1 chars;

      i0 = (OOC_INT32)e;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4809)))), Exception__ExceptionDesc_GetMessage)),Exception__ExceptionDesc_GetMessage)((Exception__Exception)i0);
      msg = (Object__String)i0;
      i0 = (OOC_INT32)Object__String8Desc_CharsLatin1((Object__String8)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4850)))), &_td_Object__String8Desc, 4850)));
      chars = (Object__CharsLatin1)i0;
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 4938)), 0);
      i0 = (OOC_INT32)Msg__GetStringPtr((void*)(_check_pointer(i0, 4938)), i1);
      i1 = (OOC_INT32)lastError;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4889)))), Msg__MsgDesc_SetStringAttrib)),Msg__MsgDesc_SetStringAttrib)((Msg__Msg)i1, "reason", 7, (Msg__StringPtr)i0);
      return;
      ;
    }


  i0 = (OOC_INT32)sectionRoot;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4996))+36);
  node = (Config_Parser__Node)i0;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l103;
l3_loop:
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5048)))), &_td_Config_Parser__ElementDesc);
  if (i1) goto l13;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8197)))), &_td_Config_Parser__CharDataDesc);
  if (i1) goto l8;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8191)))), 8191);
  goto l98;
l8:
  i1 = Config_Parser__NodeDesc_IsWhitespace((Config_Parser__Node)i0);
  i1 = !i1;
  if (!i1) goto l98;
  Config_Section_Options__SectionDesc_ProcessElements_Err(1, (Config_Parser__Node)i0);
  goto l98;
l13:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5084))+28);
  i1 = (
  _cmp16((const void*)(_check_pointer(i1, 5090)),(const void*)((OOC_CHAR16[]){115,101,116,0})))==0;
  if (i1) goto l64;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6298))+28);
  i1 = (
  _cmp16((const void*)(_check_pointer(i1, 6304)),(const void*)((OOC_CHAR16[]){100,101,102,105,110,101,0})))==0;
  if (i1) goto l18;
  Config_Section_Options__SectionDesc_ProcessElements_Err(1, (Config_Parser__Node)i0);
  i0 = (OOC_INT32)s;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 8154));
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 8154));
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 8160)), 0);
  i0 = (OOC_INT32)Msg__GetLStringPtr((void*)(_check_pointer(i0, 8160)), i1);
  i1 = (OOC_INT32)lastError;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8106)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i1, "name", 5, (Msg__LStringPtr)i0);
  goto l98;
l18:
  name = (XML_UnicodeBuffer__CharArray)(OOC_INT32)0;
  type = (XML_UnicodeBuffer__CharArray)(OOC_INT32)0;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6387))+32);
  i = 0;
  i0 = *(OOC_INT32*)(_check_pointer(i0, 6397));
  i1 = 0<i0;
  if (!i1) goto l34;
  i1=0;
l21_loop:
  i2 = (OOC_INT32)node;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 6431))+32);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 6441))+4);
  i3 = _check_pointer(i3, 6447);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i1, i4, OOC_UINT32, 6447))*4);
  att = (XML_Builder__Attribute)i1;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6471))+4);
  i3 = (
  _cmp16((const void*)(_check_pointer(i3, 6482)),(const void*)((OOC_CHAR16[]){110,97,109,101,0})))==0;
  if (i3) goto l28;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6579))+4);
  i3 = (
  _cmp16((const void*)(_check_pointer(i3, 6590)),(const void*)((OOC_CHAR16[]){116,121,112,101,0})))==0;
  if (i3) goto l26;
  Config_Section_Options__SectionDesc_ProcessElements_Err(2, (Config_Parser__Node)i2);
  i1 = (OOC_INT32)att;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6799))+4);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6799))+4);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 6810)), 0);
  i1 = (OOC_INT32)Msg__GetLStringPtr((void*)(_check_pointer(i1, 6810)), i2);
  i2 = (OOC_INT32)lastError;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 6749)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i2, "name", 5, (Msg__LStringPtr)i1);
  goto l29;
l26:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6653))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6632))+12);
  i1 = (OOC_INT32)XML_DTD__AttValueDesc_Flatten((XML_DTD__AttValue)i1, (XML_DTD__AttrDecl)i2);
  type = (XML_UnicodeBuffer__CharArray)i1;
  goto l29;
l28:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6545))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6524))+12);
  i1 = (OOC_INT32)XML_DTD__AttValueDesc_Flatten((XML_DTD__AttValue)i1, (XML_DTD__AttrDecl)i2);
  name = (XML_UnicodeBuffer__CharArray)i1;
l29:
  i1 = i;
  i1 = i1+1;
  i = i1;
  i2 = i1<i0;
  if (i2) goto l21_loop;
l34:
  i0 = (OOC_INT32)name;
  i1 = i0==(OOC_INT32)0;
  if (i1) goto l61;
  i1 = (OOC_INT32)type;
  i2 = i1==(OOC_INT32)0;
  if (i2) goto l59;
  i2 = (OOC_INT32)node;
  i3 = Config_Parser__NodeDesc_HasNoElementContent((Config_Parser__Node)i2);
  i3 = !i3;
  if (i3) goto l57;
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i0, 7164)), 0);
  i0 = (OOC_INT32)Object__NewUTF16((void*)(_check_pointer(i0, 7164)), i3);
  name8 = (Object__String)i0;
  i3 = (OOC_INT32)s;
  i4 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 7185)))), Config_Section_Options__SectionDesc_Get)),Config_Section_Options__SectionDesc_Get)((Config_Section_Options__Section)i3, (Object__String)i0);
  i4 = i4!=(OOC_INT32)0;
  if (i4) goto l55;
  i4 = OOC_ARRAY_LENGTH((_check_pointer(i1, 7427)), 0);
  i1 = (OOC_INT32)Object__NewUTF16((void*)(_check_pointer(i1, 7427)), i4);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 7397))+8);
  i1 = (OOC_INT32)Config__GetClone((ADT_Dictionary__Dictionary)i4, (Object__String)i1);
  newValue = (Config__Variable)i1;
  i4 = i1==(OOC_INT32)0;
  if (i4) goto l53;
  i2 = (OOC_INT32)Config_Parser__NodeDesc_GetCharDataContent((Config_Parser__Node)i2);
  parserString = (XML_UnicodeBuffer__CharArray)i2;
  {
    Exception__PushContext(&_context1, &_target1);
    if (!setjmp(_target1)) goto l51;
    Exception__PopContext(1);
    i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG(((OOC_INT32)Exception__Current()))), &_td_Exception__ParseErrorDesc);
    if (i0) goto l49;
    Exception__ActivateContext();
    goto l50;
l49:
    i0 = (OOC_INT32)node;
    Config_Section_Options__SectionDesc_ProcessElements_Err(9, (Config_Parser__Node)i0);
    i0 = (OOC_INT32)Exception__Current();
    Config_Section_Options__SectionDesc_ProcessElements_SetReason((Exception__Exception)i0);
l50:
    Exception__Clear();
    goto l52;
l51:
    i4 = OOC_ARRAY_LENGTH((_check_pointer(i2, 7760)), 0);
    i2 = (OOC_INT32)Object__NewUTF16((void*)(_check_pointer(i2, 7760)), i4);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7717)))), Config__VariableDesc_StringToValue)),Config__VariableDesc_StringToValue)((Config__Variable)i1, (Object__String)i2);
    i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 7794)))), Config_Section_Options__SectionDesc_Set)),Config_Section_Options__SectionDesc_Set)((Config_Section_Options__Section)i3, (Object__String)i0, (Config__Variable)i1);
    option = (Config_Section_Options__Option)i0;
    Exception__PopContext(1);
l52:;
  }
  goto l98;
l53:
  Config_Section_Options__SectionDesc_ProcessElements_Err(8, (Config_Parser__Node)i2);
  i0 = (OOC_INT32)type;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 7588)), 0);
  i0 = (OOC_INT32)Msg__GetLStringPtr((void*)(_check_pointer(i0, 7588)), i1);
  i1 = (OOC_INT32)lastError;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7537)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i1, "type", 5, (Msg__LStringPtr)i0);
  goto l98;
l55:
  Config_Section_Options__SectionDesc_ProcessElements_Err(6, (Config_Parser__Node)i2);
  i0 = (OOC_INT32)name;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 7333)), 0);
  i0 = (OOC_INT32)Msg__GetLStringPtr((void*)(_check_pointer(i0, 7333)), i1);
  i1 = (OOC_INT32)lastError;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7282)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i1, "name", 5, (Msg__LStringPtr)i0);
  goto l98;
l57:
  Config_Section_Options__SectionDesc_ProcessElements_Err(5, (Config_Parser__Node)i2);
  goto l98;
l59:
  i0 = (OOC_INT32)node;
  Config_Section_Options__SectionDesc_ProcessElements_Err(4, (Config_Parser__Node)i0);
  goto l98;
l61:
  i0 = (OOC_INT32)node;
  Config_Section_Options__SectionDesc_ProcessElements_Err(3, (Config_Parser__Node)i0);
  goto l98;
l64:
  name = (XML_UnicodeBuffer__CharArray)(OOC_INT32)0;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5157))+32);
  i = 0;
  i0 = *(OOC_INT32*)(_check_pointer(i0, 5167));
  i1 = 0<i0;
  if (!i1) goto l76;
  i1=0;
l67_loop:
  i2 = (OOC_INT32)node;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 5201))+32);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 5211))+4);
  i3 = _check_pointer(i3, 5217);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i1, i4, OOC_UINT32, 5217))*4);
  att = (XML_Builder__Attribute)i1;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 5241))+4);
  i3 = (
  _cmp16((const void*)(_check_pointer(i3, 5252)),(const void*)((OOC_CHAR16[]){110,97,109,101,0})))==0;
  if (i3) goto l70;
  Config_Section_Options__SectionDesc_ProcessElements_Err(2, (Config_Parser__Node)i2);
  i1 = (OOC_INT32)att;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 5461))+4);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 5461))+4);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 5472)), 0);
  i1 = (OOC_INT32)Msg__GetLStringPtr((void*)(_check_pointer(i1, 5472)), i2);
  i2 = (OOC_INT32)lastError;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 5411)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i2, "name", 5, (Msg__LStringPtr)i1);
  goto l71;
l70:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 5315))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 5294))+12);
  i1 = (OOC_INT32)XML_DTD__AttValueDesc_Flatten((XML_DTD__AttValue)i1, (XML_DTD__AttrDecl)i2);
  name = (XML_UnicodeBuffer__CharArray)i1;
l71:
  i1 = i;
  i1 = i1+1;
  i = i1;
  i2 = i1<i0;
  if (i2) goto l67_loop;
l76:
  i0 = (OOC_INT32)name;
  i1 = i0==(OOC_INT32)0;
  if (i1) goto l95;
  i1 = (OOC_INT32)node;
  i2 = Config_Parser__NodeDesc_HasNoElementContent((Config_Parser__Node)i1);
  i2 = !i2;
  if (i2) goto l93;
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i0, 5756)), 0);
  i0 = (OOC_INT32)Object__NewUTF16((void*)(_check_pointer(i0, 5756)), i2);
  i2 = (OOC_INT32)s;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 5729)))), Config_Section_Options__SectionDesc_Get)),Config_Section_Options__SectionDesc_Get)((Config_Section_Options__Section)i2, (Object__String)i0);
  option = (Config_Section_Options__Option)i0;
  i2 = i0==(OOC_INT32)0;
  if (i2) goto l91;
  i1 = (OOC_INT32)Config_Parser__NodeDesc_GetCharDataContent((Config_Parser__Node)i1);
  parserString = (XML_UnicodeBuffer__CharArray)i1;
  {
    Exception__PushContext(&_context0, &_target0);
    if (!setjmp(_target0)) goto l89;
    Exception__PopContext(1);
    i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG(((OOC_INT32)Exception__Current()))), &_td_Exception__ParseErrorDesc);
    if (i0) goto l87;
    Exception__ActivateContext();
    goto l88;
l87:
    i0 = (OOC_INT32)node;
    Config_Section_Options__SectionDesc_ProcessElements_Err(9, (Config_Parser__Node)i0);
    i0 = (OOC_INT32)Exception__Current();
    Config_Section_Options__SectionDesc_ProcessElements_SetReason((Exception__Exception)i0);
l88:
    Exception__Clear();
    goto l90;
l89:
    i2 = OOC_ARRAY_LENGTH((_check_pointer(i1, 6082)), 0);
    i1 = (OOC_INT32)Object__NewUTF16((void*)(_check_pointer(i1, 6082)), i2);
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6033))+8);
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6033))+8);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 6039)))), Config__VariableDesc_StringToValue)),Config__VariableDesc_StringToValue)((Config__Variable)i0, (Object__String)i1);
    Exception__PopContext(1);
l90:;
  }
  goto l98;
l91:
  Config_Section_Options__SectionDesc_ProcessElements_Err(7, (Config_Parser__Node)i1);
  i0 = (OOC_INT32)name;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 5914)), 0);
  i0 = (OOC_INT32)Msg__GetLStringPtr((void*)(_check_pointer(i0, 5914)), i1);
  i1 = (OOC_INT32)lastError;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5863)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i1, "name", 5, (Msg__LStringPtr)i0);
  goto l98;
l93:
  Config_Section_Options__SectionDesc_ProcessElements_Err(5, (Config_Parser__Node)i1);
  goto l98;
l95:
  i0 = (OOC_INT32)node;
  Config_Section_Options__SectionDesc_ProcessElements_Err(3, (Config_Parser__Node)i0);
l98:
  i0 = (OOC_INT32)node;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 8334));
  node = (Config_Parser__Node)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l3_loop;
l103:
  return;
  ;
}

void Config_Section_Options__SectionDesc_DumpContent(Config_Section_Options__Section s, Channel__Channel ch) {
  register OOC_INT32 i0,i1,i2,i3;
  TextRider__Writer w;
  OOC_CHAR8 str8[2048];
  Config_Section_Options__Option opt;

  i0 = (OOC_INT32)ch;
  i0 = (OOC_INT32)TextRider__ConnectWriter((Channel__Channel)i0);
  w = (TextRider__Writer)i0;
  i1 = (OOC_INT32)s;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 8585));
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 8585));
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 8591)), 0);
  LongStrings__Short((void*)(_check_pointer(i3, 8591)), i2, 63u, (void*)(OOC_INT32)str8, 2048);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8611)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, "<", 2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8637)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, (void*)(OOC_INT32)str8, 2048);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8664)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, ">", 2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8686)))), TextRider__WriterDesc_WriteLn)),TextRider__WriterDesc_WriteLn)((TextRider__Writer)i0);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 8709))+4);
  opt = (Config_Section_Options__Option)i2;
  i3 = i2!=0;
  if (!i3) goto l8;
l3_loop:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8755)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, "  <value name=\047", 16);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 8815))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8797)))), TextRider__WriterDesc_WriteObject)),TextRider__WriterDesc_WriteObject)((TextRider__Writer)i0, (Object__Object)i3);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8831)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, "\047>", 3);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 8884))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8867)))), TextRider__WriterDesc_WriteObject)),TextRider__WriterDesc_WriteObject)((TextRider__Writer)i0, (Object__Object)i3);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8907)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, "</value>", 9);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8942)))), TextRider__WriterDesc_WriteLn)),TextRider__WriterDesc_WriteLn)((TextRider__Writer)i0);
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 8969));
  opt = (Config_Section_Options__Option)i2;
  i3 = i2!=0;
  if (i3) goto l3_loop;
l8:
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 9009));
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 9009));
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 9015)), 0);
  LongStrings__Short((void*)(_check_pointer(i1, 9015)), i2, 63u, (void*)(OOC_INT32)str8, 2048);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9035)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, "</", 3);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9062)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, (void*)(OOC_INT32)str8, 2048);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9089)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, ">", 2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9111)))), TextRider__WriterDesc_WriteLn)),TextRider__WriterDesc_WriteLn)((TextRider__Writer)i0);
  return;
  ;
}

void OOC_Config_Section_Options_init(void) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)RT0__NewObject(_td_Config_Section_Options__ErrorContext.baseTypes[0]);
  Config_Section_Options__optionsContext = (Config_Section_Options__ErrorContext)i0;
  Msg__InitContext((Msg__Context)i0, "Config:Section:Options", 23);
  return;
  ;
}

void OOC_Config_Section_Options_destroy(void) {
}

/* --- */
