#include <OOC/Make.d>
#include <__oo2c.h>
#include <setjmp.h>

void OOC_Make__ErrorContextDesc_GetTemplate(OOC_Make__ErrorContext context, Msg__Msg msg, Msg__LString templ, OOC_LEN templ_0d) {
  register OOC_INT32 i0,i1;
  OOC_CHAR16 t[128];

  i0 = (OOC_INT32)msg;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 4685))+8);
  switch (i1) {
  case 1:
    _copy_16((const void*)((OOC_CHAR16[]){67,97,110,110,111,116,32,108,111,99,97,116,101,32,109,111,100,117,108,101,32,96,36,123,110,97,109,101,125,39,0}),(void*)(OOC_INT32)t,128);
    goto l5;
  case 2:
    _copy_16((const void*)((OOC_CHAR16[]){77,111,100,117,108,101,32,105,115,32,97,108,114,101,97,100,121,32,112,97,114,116,32,111,102,32,108,105,98,114,97,114,121,32,96,36,123,110,97,109,101,125,39,0}),(void*)(OOC_INT32)t,128);
    goto l5;
  default:
    _failed_case(i1, 4677);
    goto l5;
  }
l5:
  i1 = (OOC_INT32)context;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4864)))), OOC_Error__ContextDesc_BaseTemplate)),OOC_Error__ContextDesc_BaseTemplate)((OOC_Error__Context)i1, (Msg__Msg)i0, (void*)(OOC_INT32)t, 128, (void*)(OOC_INT32)templ, templ_0d);
  return;
  ;
}

void OOC_Make__InitRules(OOC_Make__Rules r) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)r;
  *(OOC_INT32*)(_check_pointer(i0, 4962)) = 1;
  *(OOC_INT32*)((_check_pointer(i0, 4994))+4) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 5016))+8) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 5057))+12) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 5087))+16) = 0;
  i1 = (OOC_INT32)ADT_Dictionary__New();
  *(OOC_INT32*)((_check_pointer(i0, 5109))+20) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 5142))+24) = 0;
  *(OOC_UINT8*)((_check_pointer(i0, 5170))+28) = 1u;
  i1 = (OOC_INT32)IO_StdChannels__stdout;
  *(OOC_INT32*)((_check_pointer(i0, 5204))+32) = i1;
  *(OOC_UINT8*)((_check_pointer(i0, 5240))+36) = 0u;
  *(OOC_UINT8*)((_check_pointer(i0, 5268))+36) = 0u;
  *(OOC_INT32*)((_check_pointer(i0, 5296))+40) = 0;
  return;
  ;
}

OOC_Make__Rules OOC_Make__NewRules(void) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Make__Rules.baseTypes[0]);
  OOC_Make__InitRules((OOC_Make__Rules)i0);
  return (OOC_Make__Rules)i0;
  ;
}

void OOC_Make__RulesDesc_SetBackend(OOC_Make__Rules r, OOC_INT32 backend) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)r;
  i1 = backend;
  *(OOC_INT32*)(_check_pointer(i0, 5513)) = i1;
  return;
  ;
}

void OOC_Make__RulesDesc_SetLibrary(OOC_Make__Rules r, OOC_Package__Library library) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)library;
  *(OOC_INT32*)((_check_pointer(i0, 5627))+4) = i1;
  return;
  ;
}

Object__String OOC_Make__RulesDesc_LibraryName(OOC_Make__Rules r) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5729))+4);
  i1 = i1!=(OOC_INT32)0;
  if (i1) goto l3;
  return (Object__String)(OOC_INT32)0;
  goto l4;
l3:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5764))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5772));
  return (Object__String)i0;
l4:
  _failed_function(5688); return 0;
  ;
}

void OOC_Make__RulesDesc_SetAllImportsModule(OOC_Make__Rules r, OOC_Repository__Module module) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)module;
  *(OOC_INT32*)((_check_pointer(i0, 5911))+8) = i1;
  return;
  ;
}

void OOC_Make__RulesDesc_SetErrOut(OOC_Make__Rules r, IO__ByteChannel ch) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)ch;
  *(OOC_INT32*)((_check_pointer(i0, 6040))+32) = i1;
  return;
  ;
}

void OOC_Make__RulesDesc_SetForceUpdate(OOC_Make__Rules r, OOC_CHAR8 forceUpdate) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)r;
  i1 = forceUpdate;
  *(OOC_UINT8*)((_check_pointer(i0, 6146))+36) = i1;
  return;
  ;
}

OOC_CHAR8 OOC_Make__RulesDesc_UsageTracking(OOC_Make__Rules r, Object__String extIdent) {
  register OOC_INT32 i0,i1,i2;
  OOC_CHAR8 syntaxError;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)extIdent;
  i1 = (OOC_INT32)OOC_SymbolTable_Uses__New((Object__String)i1, (void*)(OOC_INT32)&syntaxError);
  i2 = syntaxError;
  *(OOC_INT32*)((_check_pointer(i0, 6307))+40) = i1;
  return (!i2);
  ;
}

void OOC_Make__RulesDesc_SetExtensionDict(OOC_Make__Rules r, ADT_Dictionary__Dictionary dict) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)dict;
  *(OOC_INT32*)((_check_pointer(i0, 6474))+24) = i1;
  return;
  ;
}

OOC_CHAR8 OOC_Make__RulesDesc_CheckAllImports(OOC_Make__Rules r, OOC_Repository__Module module) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6809))+8);
  i1 = i1==(OOC_INT32)0;
  if (i1) goto l3;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6852))+8);
  i1 = (OOC_INT32)module;
  i0 = i0==i1;
  
  goto l4;
l3:
  i0=1u;
l4:
  return i0;
  ;
}

OOC_Make__ModuleInfo OOC_Make__RulesDesc_GetModuleInfo(OOC_Make__Rules r, OOC_Repository__Module module) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  Object__Object obj;
  OOC_Make__ModuleInfo mInfo;
  OOC_INT32 i;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7065))+20);
  i2 = (OOC_INT32)module;
  i1 = ADT_Dictionary__DictionaryDesc_HasKey((ADT_Dictionary__Dictionary)i1, (Object__Object)i2);
  if (i1) goto l8;
  i1 = (OOC_INT32)RT0__NewObject(_td_OOC_Make__ModuleInfo.baseTypes[0]);
  mInfo = (OOC_Make__ModuleInfo)i1;
  i = 0;
  i3=0;
l3_loop:
  *(OOC_UINT8*)((_check_pointer(i1, 7235))+(_check_index(i3, 22, OOC_UINT32, 7243))) = 0u;
  *(OOC_UINT8*)(((_check_pointer(i1, 7270))+22)+(_check_index(i3, 22, OOC_UINT32, 7283))) = 0u;
  i3 = i3+1;
  i = i3;
  i4 = i3<=21;
  if (i4) goto l3_loop;
l7:
  *(OOC_UINT8*)((_check_pointer(i1, 7319))+44) = 0u;
  *(OOC_UINT8*)((_check_pointer(i1, 7350))+45) = 0u;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7382))+20);
  ADT_Dictionary__DictionaryDesc_Set((ADT_Dictionary__Dictionary)i0, (Object__Object)i2, (Object__Object)i1);
  i0=i1;
  goto l9;
l8:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7106))+20);
  i0 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i0, (Object__Object)i2);
  obj = (Object__Object)i0;
  i0 = _type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7145)))), &_td_OOC_Make__ModuleInfoDesc, 7145);
  
l9:
  return (OOC_Make__ModuleInfo)i0;
  ;
}

static OOC_CHAR8 OOC_Make__Exists(OOC_Repository__Module module, OOC_INT8 fileId) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)module;
  i1 = fileId;
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7547)))), OOC_Repository__ModuleDesc_FileExists)),OOC_Repository__ModuleDesc_FileExists)((OOC_Repository__Module)i0, i1);
  if (i2) goto l3;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7723)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i0, i1, 1u);
  OOC_Logger__ExplainFileMake("file ", 6, (URI__URI)i0, " does not exist", 16);
  return 0u;
  goto l4;
l3:
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7616)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i0, i1, 1u);
  OOC_Logger__ExplainFileMake("file ", 6, (URI__URI)i0, " exists", 8);
  return 1u;
l4:
  _failed_function(7468); return 0;
  ;
}

static OOC_CHAR8 OOC_Make__DerivedIsOlder2(OOC_Repository__Module descendentModule, OOC_INT8 descendent, OOC_Repository__Module ancestorModule, OOC_INT8 ancestor) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  struct Time__TimeStamp tsDesc;
  struct Time__TimeStamp tsAncest;

  i0 = (OOC_INT32)descendentModule;
  i1 = descendent;
  i2 = (OOC_INT32)&_td_Time__TimeStamp;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8371)))), OOC_Repository__ModuleDesc_GetTimeStamp)),OOC_Repository__ModuleDesc_GetTimeStamp)((OOC_Repository__Module)i0, i1, (void*)(OOC_INT32)&tsDesc, (RT0__Struct)i2);
  i3 = *(OOC_INT32*)(OOC_INT32)&tsDesc;
  i3 = i3==2147483647;
  if (i3) goto l7;
  i3 = (OOC_INT32)ancestorModule;
  i4 = ancestor;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 8625)))), OOC_Repository__ModuleDesc_GetTimeStamp)),OOC_Repository__ModuleDesc_GetTimeStamp)((OOC_Repository__Module)i3, i4, (void*)(OOC_INT32)&tsAncest, (RT0__Struct)i2);
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(i2, Time__TimeStamp_Cmp)),Time__TimeStamp_Cmp)((void*)(OOC_INT32)&tsDesc, (RT0__Struct)i2, (void*)(OOC_INT32)&tsAncest);
  i2 = i2>=0;
  if (i2) goto l5;
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 9045)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i3, i4, 1u);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8961)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i0, i1, 1u);
  OOC_Logger__ExplainFilesMake("ts(", 4, (URI__URI)i0, ") < ts(", 8, (URI__URI)i2, ")", 2);
  return 1u;
  goto l8;
l5:
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 8842)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i3, i4, 1u);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8757)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i0, i1, 1u);
  OOC_Logger__ExplainFilesMake("ts(", 4, (URI__URI)i0, ") >= ts(", 9, (URI__URI)i2, ")", 2);
  return 0u;
  goto l8;
l7:
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8501)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i0, i1, 1u);
  OOC_Logger__ExplainFileMake("file ", 6, (URI__URI)i0, " does not exist", 16);
  return 1u;
l8:
  _failed_function(7820); return 0;
  ;
}

static OOC_CHAR8 OOC_Make__DerivedIsOlder(OOC_Repository__Module module, OOC_INT8 descendent, OOC_INT8 ancestor) {
  register OOC_INT32 i0,i1,i2;

  i0 = ancestor;
  i1 = (OOC_INT32)module;
  i2 = descendent;
  i0 = OOC_Make__DerivedIsOlder2((OOC_Repository__Module)i1, i2, (OOC_Repository__Module)i1, i0);
  return i0;
  ;
}

static OOC_CHAR8 OOC_Make__FingerprintMismatch(OOC_Repository__Module descendentModule, OOC_INT32 descendentFP, OOC_Repository__Module ancestorModule, OOC_INT32 ancestorFP) {
  register OOC_INT32 i0,i1;

  i0 = descendentFP;
  i1 = ancestorFP;
  i0 = i0==i1;
  if (i0) goto l3;
  i0 = (OOC_INT32)ancestorModule;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9965)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i0, 1, 1u);
  i1 = (OOC_INT32)descendentModule;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9876)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i1, 1, 1u);
  OOC_Logger__ExplainFilesMake("fp(", 4, (URI__URI)i1, ") # fp(", 8, (URI__URI)i0, ")", 2);
  return 1u;
  goto l4;
l3:
  i0 = (OOC_INT32)ancestorModule;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9754)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i0, 1, 1u);
  i1 = (OOC_INT32)descendentModule;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9665)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i1, 1, 1u);
  OOC_Logger__ExplainFilesMake("fp(", 4, (URI__URI)i1, ") = fp(", 8, (URI__URI)i0, ")", 2);
  return 0u;
l4:
  _failed_function(9338); return 0;
  ;
}

static OOC_Error__List OOC_Make__CreateErrList(OOC_Repository__Module module) {
  register OOC_INT32 i0;
  URI__URI uri;

  i0 = (OOC_INT32)module;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10167)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i0, 0, 1u);
  uri = (URI__URI)i0;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10231)))), URI__URIDesc_ToString)),URI__URIDesc_ToString)((URI__URI)i0);
  i0 = (OOC_INT32)OOC_Error__NewList((Object__String)i0);
  return (OOC_Error__List)i0;
  ;
}

void OOC_Make__RulesDesc_WriteErrList(OOC_Make__Rules r, OOC_Error__List errList) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)errList;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 10348));
  i1 = i1!=0;
  if (!i1) goto l4;
  i1 = (OOC_INT32)r;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 10389))+32);
  OOC_Error__ListDesc_Write((OOC_Error__List)i0, (IO__ByteChannel)i1);
l4:
  return;
  ;
}

void OOC_Make__RulesDesc_WriteError(OOC_Make__Rules r, OOC_Repository__Module module, Msg__Msg res) {
  register OOC_INT32 i0,i1;
  OOC_Error__List errList;

  i0 = (OOC_INT32)module;
  i0 = (OOC_INT32)OOC_Make__CreateErrList((OOC_Repository__Module)i0);
  errList = (OOC_Error__List)i0;
  i1 = (OOC_INT32)res;
  OOC_Error__ListDesc_Append((OOC_Error__List)i0, (Msg__Msg)i1);
  i1 = (OOC_INT32)r;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 10603)))), OOC_Make__RulesDesc_WriteErrList)),OOC_Make__RulesDesc_WriteErrList)((OOC_Make__Rules)i1, (OOC_Error__List)i0);
  return;
  ;
}

static void OOC_Make__WriteImports(OOC_Repository__Module module) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT32 i;
  OOC_Repository__Module import;

  i0 = (OOC_INT32)module;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 10788))+16);
  _assert((i1>=2), 127, 10775);
  Out__String("> IMPORT of ", 13);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10869))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10869))+4);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 10874)), 0);
  Out__String((void*)(_check_pointer(i2, 10874)), i1);
  Out__Ln();
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10914))+20);
  i = 0;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 10927)), 0);
  i2 = 0<i1;
  if (!i2) goto l12;
  i2=0;
l3_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10987))+20);
  i3 = _check_pointer(i3, 11000);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = (OOC_INT32)*(OOC_INT32*)(i3+((_check_index(i2, i4, OOC_UINT32, 11000))*16));
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 11008))+12);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10987))+20);
  i4 = _check_pointer(i4, 11000);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+((_check_index(i2, i5, OOC_UINT32, 11000))*16));
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 11008))+12);
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 11012)), 0);
  i5 = (OOC_INT32)OOC_Config__repositories;
  i3 = (OOC_INT32)OOC_Config_Repositories__SectionDesc_GetModule((OOC_Config_Repositories__Section)i5, (void*)(_check_pointer(i4, 11012)), i3);
  import = (OOC_Repository__Module)i3;
  i4 = i3==0;
  if (i4) goto l6;
  Out__String("> ", 3);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 11219))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 11219))+4);
  i4 = OOC_ARRAY_LENGTH((_check_pointer(i4, 11224)), 0);
  Out__String((void*)(_check_pointer(i3, 11224)), i4);
  Out__Ln();
  goto l7;
l6:
  Out__String("> no such module: ", 19);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11112))+20);
  i3 = _check_pointer(i3, 11125);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = (OOC_INT32)*(OOC_INT32*)(i3+((_check_index(i2, i4, OOC_UINT32, 11125))*16));
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 11133))+12);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11112))+20);
  i4 = _check_pointer(i4, 11125);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+((_check_index(i2, i5, OOC_UINT32, 11125))*16));
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 11133))+12);
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 11137)), 0);
  Out__String((void*)(_check_pointer(i4, 11137)), i3);
  Out__Ln();
l7:
  i2 = i2+1;
  i = i2;
  i3 = i2<i1;
  if (i3) goto l3_loop;
l12:
  return;
  ;
}

OOC_CHAR8 OOC_Make__RulesDesc_GetImports(OOC_Make__Rules r, OOC_Repository__Module module) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_Error__List errList;
  OOC_Config_Pragmas__History pragmaHistory;
  OOC_SymbolTable__Module symTab;
  OOC_AST__Node ast;
  auto void OOC_Make__RulesDesc_GetImports_ResolveNames(void);
    
    void OOC_Make__RulesDesc_GetImports_ResolveNames(void) {
      register OOC_INT32 i0,i1,i2,i3,i4;
      OOC_INT32 i;
      OOC_Repository__Module import;
      auto void OOC_Make__RulesDesc_GetImports_ResolveNames_Err(OOC_INT32 code, OOC_SymbolTable__Name sym);
        
        void OOC_Make__RulesDesc_GetImports_ResolveNames_Err(OOC_INT32 code, OOC_SymbolTable__Name sym) {
          register OOC_INT32 i0,i1,i2,i3;
          Msg__Msg lastError;
          OOC_INT32 pos;

          i0 = code;
          i1 = (OOC_INT32)OOC_Make__makeContext;
          i0 = (OOC_INT32)OOC_Error__New((OOC_Error__Context)i1, i0);
          lastError = (Msg__Msg)i0;
          i1 = (OOC_INT32)sym;
          i2 = *(OOC_INT32*)(_check_pointer(i1, 12163));
          pos = i2;
          i3 = i2<0;
          if (!i3) goto l4;
          pos = 0;
          i2=0;
l4:
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12245)))), Msg__MsgDesc_SetIntAttrib)),Msg__MsgDesc_SetIntAttrib)((Msg__Msg)i0, "pos", 4, i2);
          i2 = *(OOC_INT32*)((_check_pointer(i1, 12318))+4);
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12291)))), Msg__MsgDesc_SetIntAttrib)),Msg__MsgDesc_SetIntAttrib)((Msg__Msg)i0, "line", 5, i2);
          i2 = *(OOC_INT32*)((_check_pointer(i1, 12373))+8);
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12344)))), Msg__MsgDesc_SetIntAttrib)),Msg__MsgDesc_SetIntAttrib)((Msg__Msg)i0, "column", 7, i2);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12448))+12);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12448))+12);
          i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 12453)), 0);
          i1 = (OOC_INT32)Msg__GetStringPtr((void*)(_check_pointer(i1, 12453)), i2);
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12401)))), Msg__MsgDesc_SetStringAttrib)),Msg__MsgDesc_SetStringAttrib)((Msg__Msg)i0, "name", 5, (Msg__StringPtr)i1);
          i1 = (OOC_INT32)errList;
          OOC_Error__ListDesc_Append((OOC_Error__List)i1, (Msg__Msg)i0);
          return;
          ;
        }


      i0 = (OOC_INT32)module;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12554))+20);
      i = 0;
      i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 12567)), 0);
      i1 = 0<i0;
      if (!i1) goto l15;
      i1=0;
l3_loop:
      i2 = (OOC_INT32)module;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 12593))+20);
      i3 = _check_pointer(i3, 12606);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = *(OOC_UINT8*)((i3+((_check_index(i1, i4, OOC_UINT32, 12606))*16))+8);
      i3 = !i3;
      if (!i3) goto l10;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 12680))+20);
      i3 = _check_pointer(i3, 12693);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)(i3+((_check_index(i1, i4, OOC_UINT32, 12693))*16));
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 12701))+12);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 12680))+20);
      i2 = _check_pointer(i2, 12693);
      i4 = OOC_ARRAY_LENGTH(i2, 0);
      i2 = (OOC_INT32)*(OOC_INT32*)(i2+((_check_index(i1, i4, OOC_UINT32, 12693))*16));
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 12701))+12);
      i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 12705)), 0);
      i4 = (OOC_INT32)OOC_Config__repositories;
      i2 = (OOC_INT32)OOC_Config_Repositories__SectionDesc_GetModule((OOC_Config_Repositories__Section)i4, (void*)(_check_pointer(i2, 12705)), i3);
      import = (OOC_Repository__Module)i2;
      i3 = i2==0;
      if (i3) goto l8;
      i3 = (OOC_INT32)module;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 12836))+20);
      i3 = _check_pointer(i3, 12849);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      *(OOC_INT32*)((i3+((_check_index(i1, i4, OOC_UINT32, 12849))*16))+4) = i2;
      goto l10;
l8:
      i2 = (OOC_INT32)module;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 12779))+20);
      i2 = _check_pointer(i2, 12792);
      i3 = OOC_ARRAY_LENGTH(i2, 0);
      i1 = (OOC_INT32)*(OOC_INT32*)(i2+((_check_index(i1, i3, OOC_UINT32, 12792))*16));
      OOC_Make__RulesDesc_GetImports_ResolveNames_Err(1, (OOC_SymbolTable__Name)i1);
l10:
      i1 = i;
      i1 = i1+1;
      i = i1;
      i2 = i1<i0;
      if (i2) goto l3_loop;
l15:
      return;
      ;
    }


  i0 = (OOC_INT32)module;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12984))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12984))+4);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 12989)), 0);
  OOC_Logger__EnterMake("GetImports", 11, (void*)(_check_pointer(i2, 12989)), i1);
  i1 = *(OOC_INT8*)((_check_pointer(i0, 13007))+16);
  i1 = i1!=1;
  if (i1) goto l14;
  i1 = OOC_Make__Exists((OOC_Repository__Module)i0, 0);
  if (i1) goto l5;
  i1=0u;
  goto l7;
l5:
  i1 = OOC_Make__DerivedIsOlder((OOC_Repository__Module)i0, 1, 0);
  
l7:
  if (i1) goto l9;
  i1 = (OOC_INT32)OOC_Make__CreateErrList((OOC_Repository__Module)i0);
  errList = (OOC_Error__List)i1;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13994)))), OOC_Repository__ModuleDesc_ReadSymbolFile)),OOC_Repository__ModuleDesc_ReadSymbolFile)((OOC_Repository__Module)i0);
  symTab = (OOC_SymbolTable__Module)i1;
  i2 = (OOC_INT32)r;
  i2 = OOC_Make__RulesDesc_CheckAllImports((OOC_Make__Rules)i2, (OOC_Repository__Module)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14032)))), OOC_Repository__ModuleDesc_SetInterfaceData)),OOC_Repository__ModuleDesc_SetInterfaceData)((OOC_Repository__Module)i0, (OOC_SymbolTable__Module)i1, 3, i2);
  i1 = (OOC_INT32)symTab;
  i1 = *(OOC_INT32*)((_check_pointer(i1, 14178))+68);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14156)))), OOC_Repository__ModuleDesc_SetFingerprint)),OOC_Repository__ModuleDesc_SetFingerprint)((OOC_Repository__Module)i0, i1);
  goto l15;
l9:
  i1 = (OOC_INT32)r;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 13550))+40);
  i3 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 13533)))), OOC_Make__RulesDesc_LibraryName)),OOC_Make__RulesDesc_LibraryName)((OOC_Make__Rules)i1);
  OOC_Auxiliary_ParseModule__ParseModule((OOC_Repository__Module)i0, 0u, 0u, 0u, 1u, (Object__String)i3, (OOC_SymbolTable_Uses__Uses)i2, (void*)(OOC_INT32)&ast, (void*)(OOC_INT32)&symTab, (void*)(OOC_INT32)&pragmaHistory, (void*)(OOC_INT32)&errList);
  i2 = (OOC_INT32)errList;
  i2 = OOC_Error__ListDesc_NoErrors((OOC_Error__List)i2);
  if (!i2) goto l15;
  i1 = OOC_Make__RulesDesc_CheckAllImports((OOC_Make__Rules)i1, (OOC_Repository__Module)i0);
  i2 = (OOC_INT32)symTab;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13672)))), OOC_Repository__ModuleDesc_SetInterfaceData)),OOC_Repository__ModuleDesc_SetInterfaceData)((OOC_Repository__Module)i0, (OOC_SymbolTable__Module)i2, 2, i1);
  goto l15;
l14:
  OOC_Logger__ExplainMake("using cached value", 19);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13143))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13143))+4);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 13148)), 0);
  i0 = OOC_Logger__ExitMake("GetImports", 11, (void*)(_check_pointer(i0, 13148)), i1, 1u);
  return i0;
l15:
  i0 = (OOC_INT32)errList;
  i0 = OOC_Error__ListDesc_NoErrors((OOC_Error__List)i0);
  if (!i0) goto l18;
  OOC_Make__RulesDesc_GetImports_ResolveNames();
l18:
  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)errList;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14275)))), OOC_Make__RulesDesc_WriteErrList)),OOC_Make__RulesDesc_WriteErrList)((OOC_Make__Rules)i0, (OOC_Error__List)i1);
  i0 = (OOC_INT32)errList;
  i0 = OOC_Error__ListDesc_NoErrors((OOC_Error__List)i0);
  i1 = (OOC_INT32)module;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14346))+4);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14346))+4);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 14351)), 0);
  i0 = OOC_Logger__ExitMake("GetImports", 11, (void*)(_check_pointer(i1, 14351)), i2, i0);
  return i0;
  ;
}

OOC_INT32 OOC_Make__RulesDesc_SelectBackend(OOC_Make__Rules r, OOC_Repository__Module module) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)r;
  i0 = *(OOC_INT32*)(_check_pointer(i0, 14629));
  return i0;
  ;
}

OOC_CHAR8 OOC_Make__RulesDesc_CompileModule(OOC_Make__Rules r, OOC_Repository__Module module, OOC_CHAR8 analysisOnly) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_Make__ModuleInfo mInfo;
  Object__String libraryName;
  OOC_Error__List errList;
  OOC_CHAR8 success;
  auto OOC_Error__List OOC_Make__RulesDesc_CompileModule_DoEmptyBackend(Object__String libraryName);
  auto OOC_Error__List OOC_Make__RulesDesc_CompileModule_DoSSAtoC(Object__String libraryName);
    
    OOC_Error__List OOC_Make__RulesDesc_CompileModule_DoEmptyBackend(Object__String libraryName) {
      register OOC_INT32 i0,i1,i2;
      OOC_Error__List errList;
      OOC_Config_Pragmas__History pragmaHistory;
      OOC_SymbolTable__Module symTab;
      OOC_AST__Node ast;

      i0 = (OOC_INT32)r;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15596))+40);
      i1 = (OOC_INT32)module;
      i2 = (OOC_INT32)libraryName;
      OOC_Auxiliary_ParseModule__ParseModule((OOC_Repository__Module)i1, 0u, 1u, 1u, 0u, (Object__String)i2, (OOC_SymbolTable_Uses__Uses)i0, (void*)(OOC_INT32)&ast, (void*)(OOC_INT32)&symTab, (void*)(OOC_INT32)&pragmaHistory, (void*)(OOC_INT32)&errList);
      i0 = (OOC_INT32)errList;
      return (OOC_Error__List)i0;
      ;
    }

    
    OOC_Error__List OOC_Make__RulesDesc_CompileModule_DoSSAtoC(Object__String libraryName) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
      OOC_Make_TranslateToC__Translator t;

      i0 = (OOC_INT32)OOC_Make__inspectStage;
      i1 = (OOC_INT32)OOC_Make__inspectProc;
      i2 = OOC_Make__writeStats;
      i0 = (OOC_INT32)OOC_SSA_WriteC__NewTranslator(i2, (StringSearch__Matcher)i1, (StringSearch__Matcher)i0);
      t = (OOC_Make_TranslateToC__Translator)i0;
      i1 = (OOC_INT32)r;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 15953))+40);
      i2 = (OOC_INT32)module;
      i3 = (OOC_INT32)libraryName;
      i4 = analysisOnly;
      i5 = OOC_Make__writeAST;
      i6 = OOC_Make__writeIR;
      i0 = (OOC_INT32)OOC_Make_TranslateToC__Run((OOC_Repository__Module)i2, (Object__String)i3, i4, (OOC_SymbolTable_Uses__Uses)i1, i5, i6, (OOC_Make_TranslateToC__Translator)i0);
      return (OOC_Error__List)i0;
      ;
    }


  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)module;
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16056)))), OOC_Make__RulesDesc_GetModuleInfo)),OOC_Make__RulesDesc_GetModuleInfo)((OOC_Make__Rules)i0, (OOC_Repository__Module)i1);
  mInfo = (OOC_Make__ModuleInfo)i2;
  i3 = *(OOC_UINT8*)((_check_pointer(i2, 16092))+44);
  if (i3) goto l31;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 16254))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 16254))+4);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 16259)), 0);
  OOC_Logger__EnterMake("CompileModule", 14, (void*)(_check_pointer(i3, 16259)), i2);
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16286)))), OOC_Make__RulesDesc_LibraryName)),OOC_Make__RulesDesc_LibraryName)((OOC_Make__Rules)i0);
  libraryName = (Object__String)i2;
  i3 = i2!=(OOC_INT32)0;
  if (i3) goto l5;
  i3=0u;
  goto l7;
l5:
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 16340));
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16351))+12);
  i3 = i3!=i4;
  
l7:
  if (!i3) goto l10;
  libraryName = (Object__String)(OOC_INT32)0;
  i2=(OOC_INT32)0;
l10:
  i0 = OOC_Make__RulesDesc_SelectBackend((OOC_Make__Rules)i0, (OOC_Repository__Module)i1);
  switch (i0) {
  case 0:
    i0 = (OOC_INT32)OOC_Make__RulesDesc_CompileModule_DoEmptyBackend((Object__String)i2);
    errList = (OOC_Error__List)i0;
    goto l15;
  case 1:
    i0 = (OOC_INT32)OOC_Make__RulesDesc_CompileModule_DoSSAtoC((Object__String)i2);
    errList = (OOC_Error__List)i0;
    goto l15;
  default:
    _failed_case(i0, 16692);
    goto l15;
  }
l15:
  i0 = (OOC_INT32)errList;
  i1 = i0==(OOC_INT32)0;
  if (i1) goto l18;
  i1 = OOC_Error__ListDesc_NoErrors((OOC_Error__List)i0);
  
  goto l19;
l18:
  i1=1u;
l19:
  success = i1;
  i2 = (OOC_INT32)r;
  i3 = (OOC_INT32)module;
  if (i1) goto l22;
  i4=0u;
  goto l24;
l22:
  i4 = analysisOnly;
  i4 = !i4;
  
l24:
  if (!i4) goto l30;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 17035)))), OOC_Repository__ModuleDesc_SetInterfaceData)),OOC_Repository__ModuleDesc_SetInterfaceData)((OOC_Repository__Module)i3, (OOC_SymbolTable__Module)(OOC_INT32)0, 1, 1u);
  i1 = OOC_Make__RulesDesc_GetImports((OOC_Make__Rules)i2, (OOC_Repository__Module)i3);
  success = i1;
  if (!i1) goto l30;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 17191))+12);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 17167)))), OOC_Repository__ModuleDesc_SetInterfaceData)),OOC_Repository__ModuleDesc_SetInterfaceData)((OOC_Repository__Module)i3, (OOC_SymbolTable__Module)i4, 4, 1u);
l30:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 17261)))), OOC_Make__RulesDesc_WriteErrList)),OOC_Make__RulesDesc_WriteErrList)((OOC_Make__Rules)i2, (OOC_Error__List)i0);
  i0 = (OOC_INT32)mInfo;
  *(OOC_UINT8*)((_check_pointer(i0, 17303))+44) = 1u;
  *(OOC_UINT8*)((_check_pointer(i0, 17333))+45) = i1;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 17412))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 17412))+4);
  i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 17417)), 0);
  i0 = OOC_Logger__ExitMake("CompileModule", 14, (void*)(_check_pointer(i2, 17417)), i0, i1);
  return i0;
  goto l32;
l31:
  OOC_Logger__ExplainMake("cached result: CompileModule", 29);
  i0 = *(OOC_UINT8*)((_check_pointer(i2, 16183))+45);
  return i0;
l32:
  _failed_function(14922); return 0;
  ;
}

OOC_CHAR8 OOC_Make__RulesDesc_UpdateSymbolFile(OOC_Make__Rules r, OOC_Repository__Module module) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
  OOC_CHAR8 sourceExists;
  OOC_CHAR8 isUpToDate;
  Msg__Msg err;
  Object__CharsLatin1 chars;
  OOC_INT32 i;
  OOC_CHAR8 dummy;
  OOC_Error__List errList;

  i0 = (OOC_INT32)module;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 17711))+16);
  i1 = i1==4;
  if (i1) goto l72;
  i1 = (OOC_INT32)r;
  i2 = OOC_Make__RulesDesc_GetImports((OOC_Make__Rules)i1, (OOC_Repository__Module)i0);
  if (!i2) goto l73;
  i2 = OOC_Make__Exists((OOC_Repository__Module)i0, 0);
  sourceExists = i2;
  i3 = !i2;
  if (i3) goto l7;
  i3 = OOC_Make__DerivedIsOlder((OOC_Repository__Module)i0, 1, 0);
  i3 = !i3;
  
  goto l8;
l7:
  i3=1u;
l8:
  isUpToDate = i3;
  i4 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 18178)))), OOC_Make__RulesDesc_LibraryName)),OOC_Make__RulesDesc_LibraryName)((OOC_Make__Rules)i1);
  i4 = i4!=(OOC_INT32)0;
  if (i4) goto l11;
  i4=0u;
  goto l13;
l11:
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 18209));
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 18220))+12);
  i4 = i4==i5;
  
l13:
  if (!i4) goto l23;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18261))+12);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 18268))+56);
  i4 = i4==(OOC_INT32)0;
  if (i4) goto l21;
  i4 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 18592)))), OOC_Make__RulesDesc_LibraryName)),OOC_Make__RulesDesc_LibraryName)((OOC_Make__Rules)i1);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18564))+12);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18564))+12);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 18571))+56);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 18571))+56);
  i4 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 18583)))), Object__StringDesc_Equals)),Object__StringDesc_Equals)((Object__String)i5, (Object__Object)i4);
  i4 = !i4;
  if (!i4) goto l23;
  i4 = (OOC_INT32)OOC_Make__makeContext;
  i4 = (OOC_INT32)OOC_Error__New((OOC_Error__Context)i4, 2);
  err = (Msg__Msg)i4;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18885))+12);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 18892))+56);
  i5 = (OOC_INT32)Object__String8Desc_CharsLatin1((Object__String8)(_type_guard(i5, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 18912)))), &_td_Object__String8Desc, 18912)));
  chars = (Object__CharsLatin1)i5;
  i6 = OOC_ARRAY_LENGTH((_check_pointer(i5, 18998)), 0);
  i5 = (OOC_INT32)Msg__GetStringPtr((void*)(_check_pointer(i5, 18998)), i6);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 18949)))), Msg__MsgDesc_SetStringAttrib)),Msg__MsgDesc_SetStringAttrib)((Msg__Msg)i4, "name", 5, (Msg__StringPtr)i5);
  OOC_Make__RulesDesc_WriteError((OOC_Make__Rules)i1, (OOC_Repository__Module)i0, (Msg__Msg)i4);
  return 0u;
  goto l23;
l21:
  OOC_Logger__ExplainMake("module is not part of a library", 32);
  isUpToDate = 0u;
  i3=0u;
l23:
  i = 0;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19284))+20);
  i4 = OOC_ARRAY_LENGTH((_check_pointer(i4, 19297)), 0);
  i4 = 0!=i4;
  if (!i4) goto l44;
  i4=i3;i3=0;
l27_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19322))+20);
  i5 = _check_pointer(i5, 19335);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = *(OOC_UINT8*)((i5+((_check_index(i3, i6, OOC_UINT32, 19335))*16))+8);
  i5 = !i5;
  if (!i5) goto l38;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19381))+20);
  i5 = _check_pointer(i5, 19394);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)((i5+((_check_index(i3, i6, OOC_UINT32, 19394))*16))+4);
  i5 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 19367)))), OOC_Make__RulesDesc_Update)),OOC_Make__RulesDesc_Update)((OOC_Make__Rules)i1, (OOC_Repository__Module)i5, 1);
  if (i5) goto l33;
  return 0u;
  
  goto l38;
l33:
  if (i4) goto l35;
  i4=0u;
  goto l36;
l35:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19962))+20);
  i4 = _check_pointer(i4, 19975);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 19975))*16))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 19985))+12);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19894))+20);
  i5 = _check_pointer(i5, 19907);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19821))+20);
  i7 = _check_pointer(i7, 19834);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i4 = *(OOC_INT32*)((_check_pointer(i4, 19992))+68);
  i5 = (OOC_INT32)*(OOC_INT32*)((i5+((_check_index(i3, i6, OOC_UINT32, 19907))*16))+4);
  i6 = *(OOC_INT32*)((i7+((_check_index(i3, i8, OOC_UINT32, 19834))*16))+12);
  i4 = OOC_Make__FingerprintMismatch((OOC_Repository__Module)i0, i6, (OOC_Repository__Module)i5, i4);
  i4 = !i4;
  
l36:
  isUpToDate = i4;
  
l38:
  i3 = i3+1;
  i = i3;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19284))+20);
  i5 = OOC_ARRAY_LENGTH((_check_pointer(i5, 19297)), 0);
  i5 = i3!=i5;
  if (i5) goto l27_loop;
l42:
  i3=i4;
l44:
  if (i3) goto l46;
  i3=0u;
  goto l47;
l46:
  i3 = OOC_Make__Exists((OOC_Repository__Module)i0, 20);
  
l47:
  isUpToDate = i3;
  if (i3) goto l50;
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 20969)))), OOC_Make__RulesDesc_CompileModule)),OOC_Make__RulesDesc_CompileModule)((OOC_Make__Rules)i1, (OOC_Repository__Module)i0, 0u);
  isUpToDate = i2;
  
  goto l63;
l50:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20506))+12);
  _assert((i4!=(OOC_INT32)0), 127, 20493);
  i4 = OOC_Make__RulesDesc_CheckAllImports((OOC_Make__Rules)i1, (OOC_Repository__Module)i0);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20560))+12);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20536)))), OOC_Repository__ModuleDesc_SetInterfaceData)),OOC_Repository__ModuleDesc_SetInterfaceData)((OOC_Repository__Module)i0, (OOC_SymbolTable__Module)i5, 4, i4);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 20667))+40);
  i4 = i4!=(OOC_INT32)0;
  if (i4) goto l55;
  i2=0u;
l55:
  if (i2) goto l57;
  i2=0u;
  goto l59;
l57:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 20698))+40);
  i2 = OOC_SymbolTable_Uses__UsesDesc_TrackingDeclarations((OOC_SymbolTable_Uses__Uses)i2);
  
l59:
  if (!i2) goto l61;
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 20892)))), OOC_Make__RulesDesc_CompileModule)),OOC_Make__RulesDesc_CompileModule)((OOC_Make__Rules)i1, (OOC_Repository__Module)i0, 1u);
  dummy = i2;
l61:
  i2=i3;
l63:
  if (i2) goto l65;
  i0=i2;
  goto l70;
l65:
  i3 = (OOC_INT32)OOC_Make__CreateErrList((OOC_Repository__Module)i0);
  errList = (OOC_Error__List)i3;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 21135))+40);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21125))+12);
  OOC_SymbolTable_CreateNamespace__CreateNamespace((OOC_SymbolTable__Module)i0, (OOC_SymbolTable_Uses__Uses)i4, (OOC_Error__List)i3);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 21161)))), OOC_Make__RulesDesc_WriteErrList)),OOC_Make__RulesDesc_WriteErrList)((OOC_Make__Rules)i1, (OOC_Error__List)i3);
  i0 = OOC_Error__ListDesc_NoErrors((OOC_Error__List)i3);
  i0 = !i0;
  if (i0) goto l68;
  i0=i2;
  goto l70;
l68:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 21232)))), OOC_Make__RulesDesc_WriteErrList)),OOC_Make__RulesDesc_WriteErrList)((OOC_Make__Rules)i1, (OOC_Error__List)i3);
  i0=0u;
l70:
  return i0;
  goto l73;
l72:
  return 1u;
l73:
  return 0u;
  ;
}

OOC_CHAR8 OOC_Make__RulesDesc_UpdateSymbolTableXML(OOC_Make__Rules r, OOC_Repository__Module module) {

  _assert(0u, 127, 21574);
  _failed_function(21416); return 0;
  ;
}

OOC_CHAR8 OOC_Make__RulesDesc_UpdateInterfaceDescr(OOC_Make__Rules r, OOC_Repository__Module module) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_CHAR8 success;
  OOC_Error__List errList;
  IO__ByteChannel outputChannel;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)module;
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21828)))), OOC_Make__RulesDesc_Update)),OOC_Make__RulesDesc_Update)((OOC_Make__Rules)i0, (OOC_Repository__Module)i1, 1);
  success = i2;
  if (i2) goto l3;
  i0=i2;
  goto l8;
l3:
  i3 = OOC_Make__DerivedIsOlder((OOC_Repository__Module)i1, 4, 1);
  if (i3) goto l6;
  i0=i2;
  goto l8;
l6:
  i2 = (OOC_INT32)OOC_Make__CreateErrList((OOC_Repository__Module)i1);
  errList = (OOC_Error__List)i2;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22577))+40);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 22567))+12);
  OOC_SymbolTable_CreateNamespace__CreateNamespace((OOC_SymbolTable__Module)i4, (OOC_SymbolTable_Uses__Uses)i3, (OOC_Error__List)i2);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 22627))+12);
  OOC_Doc_ResolveRef__Resolve((OOC_SymbolTable__Module)i3, (OOC_Error__List)i2);
  i3 = *(OOC_INT32*)(_check_pointer(i2, 22669));
  _assert((i3==0), 127, 22654);
  i3 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 22725)))), OOC_Repository__ModuleDesc_GetOutputChannel)),OOC_Repository__ModuleDesc_GetOutputChannel)((OOC_Repository__Module)i1, 4, 1u);
  outputChannel = (IO__ByteChannel)i3;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22991))+24);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 22930))+12);
  i6 = (OOC_INT32)OOC_Config__repositories;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 22854)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i1, 4, 0u);
  OOC_SymbolTable_InterfaceDescr__Write((IO__ByteChannel)i3, (URI__HierarchicalURI)i1, (OOC_SymbolTable__Module)i5, (OOC_Config_Repositories__Section)i6, (ADT_Dictionary__Dictionary)i4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 23029)))), IO__ChannelDesc_CloseAndRegister)),IO__ChannelDesc_CloseAndRegister)((IO__Channel)i3);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 23068)))), OOC_Make__RulesDesc_WriteErrList)),OOC_Make__RulesDesc_WriteErrList)((OOC_Make__Rules)i0, (OOC_Error__List)i2);
  i0 = OOC_Error__ListDesc_NoErrors((OOC_Error__List)i2);
  
l8:
  return i0;
  ;
}

OOC_CHAR8 OOC_Make__RulesDesc_UpdateInterfaceXML(OOC_Make__Rules r, OOC_Repository__Module module) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_CHAR8 success;
  OOC_Error__List errList;
  OOC_Config_Pragmas__History pragmaHistory;
  OOC_SymbolTable__Module symTab;
  OOC_AST__Node ast;
  IO__ByteChannel outputChannel;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)module;
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 23478)))), OOC_Make__RulesDesc_Update)),OOC_Make__RulesDesc_Update)((OOC_Make__Rules)i0, (OOC_Repository__Module)i1, 1);
  success = i2;
  if (i2) goto l3;
  i0=i2;
  goto l11;
l3:
  i3 = OOC_Make__DerivedIsOlder((OOC_Repository__Module)i1, 3, 1);
  if (i3) goto l6;
  i0=i2;
  goto l11;
l6:
  i2 = (OOC_INT32)OOC_Make__CreateErrList((OOC_Repository__Module)i1);
  errList = (OOC_Error__List)i2;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24056))+40);
  i3 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 24039)))), OOC_Make__RulesDesc_LibraryName)),OOC_Make__RulesDesc_LibraryName)((OOC_Make__Rules)i0);
  OOC_Auxiliary_ParseModule__ParseModule((OOC_Repository__Module)i1, 0u, 1u, 0u, 0u, (Object__String)i3, (OOC_SymbolTable_Uses__Uses)i2, (void*)(OOC_INT32)&ast, (void*)(OOC_INT32)&symTab, (void*)(OOC_INT32)&pragmaHistory, (void*)(OOC_INT32)&errList);
  i2 = (OOC_INT32)errList;
  i2 = OOC_Error__ListDesc_NoErrors((OOC_Error__List)i2);
  if (!i2) goto l9;
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 24201)))), OOC_Repository__ModuleDesc_GetOutputChannel)),OOC_Repository__ModuleDesc_GetOutputChannel)((OOC_Repository__Module)i1, 3, 1u);
  outputChannel = (IO__ByteChannel)i2;
  i3 = (OOC_INT32)OOC_Config__repositories;
  i4 = (OOC_INT32)symTab;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 24326)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i1, 3, 0u);
  OOC_SymbolTable_InterfaceXML__Write((IO__ByteChannel)i2, (URI__HierarchicalURI)i1, (OOC_SymbolTable__Module)i4, (OOC_Config_Repositories__Section)i3);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 24445)))), IO__ChannelDesc_CloseAndRegister)),IO__ChannelDesc_CloseAndRegister)((IO__Channel)i2);
l9:
  i1 = (OOC_INT32)errList;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 24489)))), OOC_Make__RulesDesc_WriteErrList)),OOC_Make__RulesDesc_WriteErrList)((OOC_Make__Rules)i0, (OOC_Error__List)i1);
  i0 = (OOC_INT32)errList;
  i0 = OOC_Error__ListDesc_NoErrors((OOC_Error__List)i0);
  
l11:
  return i0;
  ;
}

OOC_CHAR8 OOC_Make__RulesDesc_UpdateInterfaceHTML(OOC_Make__Rules r, OOC_Repository__Module module) {
  register OOC_INT32 i0,i1,i2;
  OOC_CHAR8 success;
  OOC_INT32 exit;
  ADT_StringBuffer__StringBuffer sb;
  URI__URI uri;
  Object__String path;
  auto URI__URI OOC_Make__RulesDesc_UpdateInterfaceHTML_GetSystemId(OOC_Config_Repositories__Section repositories);
    
    URI__URI OOC_Make__RulesDesc_UpdateInterfaceHTML_GetSystemId(OOC_Config_Repositories__Section repositories) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)OOC_Make__stylesheetSystemId;
      i1 = i0==(OOC_INT32)0;
      if (i1) goto l3;
      return (URI__URI)i0;
      goto l7;
l3:
      i0 = (OOC_INT32)repositories;
      i0 = (OOC_INT32)OOC_Config_Repositories__SectionDesc_GetResource((OOC_Config_Repositories__Section)i0, "OOC", 4, "xml/interface-description.xsl", 30);
      OOC_Make__stylesheetSystemId = (URI__URI)i0;
      i0 = i0==(OOC_INT32)0;
      if (!i0) goto l6;
      Out__String("Error: Cannot locate stylesheet xml/interface-description.xsl from package OOC in any of the configured repositories.", 118);
      Out__Ln();
      _halt(1);
l6:
      i0 = (OOC_INT32)OOC_Make__stylesheetSystemId;
      return (URI__URI)i0;
l7:
      _failed_function(24871); return 0;
      ;
    }


  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)module;
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 25512)))), OOC_Make__RulesDesc_Update)),OOC_Make__RulesDesc_Update)((OOC_Make__Rules)i0, (OOC_Repository__Module)i1, 4);
  success = i0;
  if (!i0) goto l8;
  i2 = OOC_Make__DerivedIsOlder((OOC_Repository__Module)i1, 5, 4);
  if (!i2) goto l8;
  exit = 0;
  i0 = (OOC_INT32)OOC_Config__xsltproc;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25756))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25756))+8);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 25762)))), Config__VariableDesc_ToString)),Config__VariableDesc_ToString)((Config__Variable)i0);
  i0 = (OOC_INT32)ADT_StringBuffer__New((Object__String)i0);
  sb = (ADT_StringBuffer__StringBuffer)i0;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 25855)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c0));
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 25893)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i1, 5, 1u);
  uri = (URI__URI)i1;
  i1 = (OOC_INT32)URI_Scheme_File__URIDesc_GetPath((URI_Scheme_File__URI)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 25957)))), &_td_URI_Scheme_File__URIDesc, 25957)));
  path = (Object__String)i1;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 25983)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i1);
  i0 = (OOC_INT32)OS_Path__DirName((Object__String)i1);
  OS_Files__MakeDirs((Object__String)i0, 511);
  i0 = (OOC_INT32)OOC_Config__repositories;
  i0 = (OOC_INT32)OOC_Make__RulesDesc_UpdateInterfaceHTML_GetSystemId((OOC_Config_Repositories__Section)i0);
  uri = (URI__URI)i0;
  i1 = (OOC_INT32)sb;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 26249)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i1, (Object__Object)((OOC_INT32)_c1));
  i0 = (OOC_INT32)URI_Scheme_File__URIDesc_GetPath((URI_Scheme_File__URI)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 26290)))), &_td_URI_Scheme_File__URIDesc, 26290)));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 26273)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i1, (Object__Object)i0);
  i0 = (OOC_INT32)module;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 26375)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i0, 4, 1u);
  uri = (URI__URI)i0;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 26425)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i1, (Object__Object)((OOC_INT32)_c2));
  i0 = (OOC_INT32)URI_Scheme_File__URIDesc_GetPath((URI_Scheme_File__URI)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 26466)))), &_td_URI_Scheme_File__URIDesc, 26466)));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 26449)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i1, (Object__Object)i0);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 26509)))), ADT_StringBuffer__StringBufferDesc_ToString)),ADT_StringBuffer__StringBufferDesc_ToString)((ADT_StringBuffer__StringBuffer)i1);
  OOC_Logger__ShellCommand((Object__String)i0);
  i0 = OS_ProcessManagement__system((Object__String)i0);
  i0 = i0==0;
  
l8:
  return i0;
  ;
}

static OOC_CHAR8 OOC_Make__UpdateCompilerOutput(OOC_Make__Rules r, OOC_Repository__Module module, OOC_INT8 fileId) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)module;
  i1 = OOC_Make__Exists((OOC_Repository__Module)i0, 0);
  if (i1) goto l3;
  i1 = fileId;
  i0 = OOC_Make__Exists((OOC_Repository__Module)i0, i1);
  return i0;
  goto l12;
l3:
  i1 = (OOC_INT32)r;
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 26941))+36);
  if (i2) goto l6;
  i2 = fileId;
  i2 = OOC_Make__DerivedIsOlder((OOC_Repository__Module)i0, i2, 0);
  
  goto l8;
l6:
  i2=1u;
l8:
  if (i2) goto l10;
  return 1u;
  goto l12;
l10:
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 27039)))), OOC_Make__RulesDesc_CompileModule)),OOC_Make__RulesDesc_CompileModule)((OOC_Make__Rules)i1, (OOC_Repository__Module)i0, 0u);
  return i0;
l12:
  _failed_function(26745); return 0;
  ;
}

OOC_CHAR8 OOC_Make__RulesDesc_UpdateHeaderFileC(OOC_Make__Rules r, OOC_Repository__Module module) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT32 i;

  i0 = (OOC_INT32)module;
  i1 = (OOC_INT32)r;
  i2 = OOC_Make__RulesDesc_GetImports((OOC_Make__Rules)i1, (OOC_Repository__Module)i0);
  if (i2) goto l3;
  return 0u;
  goto l19;
l3:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27667))+20);
  i = 0;
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 27680)), 0);
  i3 = 0<i2;
  if (!i3) goto l18;
  i3=0;
l6_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27706))+20);
  i4 = _check_pointer(i4, 27719);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = *(OOC_UINT8*)((i4+((_check_index(i3, i5, OOC_UINT32, 27719))*16))+8);
  i4 = !i4;
  if (i4) goto l9;
  i4=0u;
  goto l11;
l9:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27761))+20);
  i4 = _check_pointer(i4, 27774);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 27774))*16))+4);
  i4 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 27747)))), OOC_Make__RulesDesc_Update)),OOC_Make__RulesDesc_Update)((OOC_Make__Rules)i1, (OOC_Repository__Module)i4, 13);
  i4 = !i4;
  
l11:
  if (!i4) goto l13;
  return 0u;
l13:
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l6_loop;
l18:
  i0 = OOC_Make__UpdateCompilerOutput((OOC_Make__Rules)i1, (OOC_Repository__Module)i0, 13);
  return i0;
l19:
  _failed_function(27218); return 0;
  ;
}

OOC_CHAR8 OOC_Make__RulesDesc_UpdateDeclFileC(OOC_Make__Rules r, OOC_Repository__Module module) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)module;
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 28100)))), OOC_Make__RulesDesc_Update)),OOC_Make__RulesDesc_Update)((OOC_Make__Rules)i0, (OOC_Repository__Module)i1, 13);
  if (i2) goto l3;
  i0=0u;
  goto l4;
l3:
  i0 = OOC_Make__UpdateCompilerOutput((OOC_Make__Rules)i0, (OOC_Repository__Module)i1, 12);
  
l4:
  return i0;
  ;
}

OOC_CHAR8 OOC_Make__RulesDesc_UpdateCodeFileC(OOC_Make__Rules r, OOC_Repository__Module module) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)module;
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 28320)))), OOC_Make__RulesDesc_Update)),OOC_Make__RulesDesc_Update)((OOC_Make__Rules)i0, (OOC_Repository__Module)i1, 12);
  if (i2) goto l3;
  return 0u;
  goto l12;
l3:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 28375))+12);
  i2 = *(OOC_INT8*)((_check_pointer(i2, 28382))+52);
  i2 = i2==2;
  if (i2) goto l6;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 28425))+12);
  i2 = *(OOC_INT8*)((_check_pointer(i2, 28432))+52);
  i2 = i2==3;
  
  goto l8;
l6:
  i2=1u;
l8:
  if (i2) goto l10;
  i0 = OOC_Make__UpdateCompilerOutput((OOC_Make__Rules)i0, (OOC_Repository__Module)i1, 11);
  return i0;
  goto l12;
l10:
  OOC_Logger__ExplainMake("module\047s C code provided by user", 33);
  return 1u;
l12:
  _failed_function(28242); return 0;
  ;
}

OOC_CHAR8 OOC_Make__RulesDesc_UpdateAssemblerFile(OOC_Make__Rules r, OOC_Repository__Module module) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)module;
  i1 = (OOC_INT32)r;
  i2 = OOC_Make__RulesDesc_GetImports((OOC_Make__Rules)i1, (OOC_Repository__Module)i0);
  if (i2) goto l3;
  return 0u;
  goto l12;
l3:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28842))+12);
  i2 = *(OOC_INT8*)((_check_pointer(i2, 28849))+52);
  i2 = i2==2;
  if (i2) goto l6;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28892))+12);
  i2 = *(OOC_INT8*)((_check_pointer(i2, 28899))+52);
  i2 = i2==3;
  
  goto l8;
l6:
  i2=1u;
l8:
  if (i2) goto l10;
  i0 = OOC_Make__UpdateCompilerOutput((OOC_Make__Rules)i1, (OOC_Repository__Module)i0, 14);
  return i0;
  goto l12;
l10:
  OOC_Logger__ExplainMake("module\047s C code provided by user", 33);
  return 1u;
l12:
  _failed_function(28719); return 0;
  ;
}

OOC_CHAR8 OOC_Make__RulesDesc_UpdateObjectFile(OOC_Make__Rules r, OOC_Repository__Module module) {
  register OOC_INT32 i0,i1,i2;
  OOC_CHAR8 success;

  i0 = OOC_Config_CCompiler__HaveLibtool();
  i0 = !i0;
  if (i0) goto l3;
  i0=0u;
  goto l4;
l3:
  i0 = (OOC_INT32)module;
  i0 = OOC_Make__Exists((OOC_Repository__Module)i0, 0);
  i0 = !i0;
  
l4:
  i1 = (OOC_INT32)module;
  if (i0) goto l7;
  i0=0u;
  goto l9;
l7:
  i0 = OOC_Make__Exists((OOC_Repository__Module)i1, 7);
  
l9:
  if (!i0) goto l11;
  OOC_Logger__ExplainMake("no source code available, and object file exists", 49);
  return 1u;
l11:
  i0 = (OOC_INT32)r;
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 30247)))), OOC_Make__RulesDesc_Update)),OOC_Make__RulesDesc_Update)((OOC_Make__Rules)i0, (OOC_Repository__Module)i1, 11);
  success = i0;
  if (i0) goto l14;
  i2=0u;
  goto l16;
l14:
  i2 = OOC_Config_CCompiler__SkipCallCC();
  i2 = !i2;
  
l16:
  if (i2) goto l18;
  i2=0u;
  goto l20;
l18:
  i2 = OOC_Make__DerivedIsOlder((OOC_Repository__Module)i1, 7, 11);
  
l20:
  if (!i2) goto l23;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 30409)))), OOC_Repository__ModuleDesc_CreateOutputDir)),OOC_Repository__ModuleDesc_CreateOutputDir)((OOC_Repository__Module)i1, 7);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 30568)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i1, 7, 1u);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 30491)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i1, 11, 1u);
  i0 = (OOC_INT32)OOC_Config_CCompiler__CompileFileCmd((URI__URI)i1, (URI__URI)i0, 0u);
  OOC_Logger__ShellCommand((Object__String)i0);
  i0 = OS_ProcessManagement__system((Object__String)i0);
  i0 = i0==0;
  
l23:
  return i0;
  ;
}

OOC_CHAR8 OOC_Make__RulesDesc_UpdateObjectFileLib(OOC_Make__Rules r, OOC_Repository__Module module) {
  register OOC_INT32 i0,i1,i2;
  OOC_CHAR8 success;
  URI__URI outputFile;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)module;
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 31158)))), OOC_Make__RulesDesc_Update)),OOC_Make__RulesDesc_Update)((OOC_Make__Rules)i0, (OOC_Repository__Module)i1, 11);
  success = i0;
  i2 = OOC_Config_CCompiler__SkipCallCC();
  i2 = !i2;
  if (i2) goto l3;
  i2=0u;
  goto l5;
l3:
  i2 = OOC_Make__DerivedIsOlder((OOC_Repository__Module)i1, 8, 11);
  
l5:
  if (!i2) goto l8;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 31313)))), OOC_Repository__ModuleDesc_CreateOutputDir)),OOC_Repository__ModuleDesc_CreateOutputDir)((OOC_Repository__Module)i1, 7);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 31377)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i1, 8, 1u);
  outputFile = (URI__URI)i0;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 31535)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i1, 8, 1u);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 31458)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i1, 11, 1u);
  i0 = (OOC_INT32)OOC_Config_CCompiler__CompileFileCmd((URI__URI)i1, (URI__URI)i0, 1u);
  OOC_Logger__ShellCommand((Object__String)i0);
  i0 = OS_ProcessManagement__system((Object__String)i0);
  i0 = i0==0;
  
l8:
  return i0;
  ;
}

OOC_CHAR8 OOC_Make__RulesDesc_UpdateMainFileC(OOC_Make__Rules r, OOC_Repository__Module module) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_CHAR8 success;
  OOC_CHAR8 isUpToDate;
  OOC_INT32 i;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)module;
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32288)))), OOC_Make__RulesDesc_Update)),OOC_Make__RulesDesc_Update)((OOC_Make__Rules)i0, (OOC_Repository__Module)i1, 1);
  success = i2;
  if (i2) goto l3;
  i0=i2;
  goto l29;
l3:
  i3 = OOC_Make__Exists((OOC_Repository__Module)i1, 15);
  isUpToDate = i3;
  i = 0;
  if (i3) goto l6;
  i4=0u;
  goto l8;
l6:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32478))+16);
  i4 = OOC_ARRAY_LENGTH((_check_pointer(i4, 32486)), 0);
  i4 = 0!=i4;
  
l8:
  if (!i4) goto l24;
  i4=i3;i3=0;
l11_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32574))+16);
  i5 = _check_pointer(i5, 32582);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i3, i6, OOC_UINT32, 32582))*4);
  i3 = i3+1;
  i5 = OOC_Make__DerivedIsOlder2((OOC_Repository__Module)i1, 15, (OOC_Repository__Module)i5, 1);
  if (!i5) goto l15;
  isUpToDate = 0u;
  i4=0u;
l15:
  i = i3;
  if (i4) goto l18;
  i5=0u;
  goto l20;
l18:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32478))+16);
  i5 = OOC_ARRAY_LENGTH((_check_pointer(i5, 32486)), 0);
  i5 = i3!=i5;
  
l20:
  if (i5) goto l11_loop;
l23:
  i3=i4;
l24:
  i3 = !i3;
  if (i3) goto l27;
  i0=i2;
  goto l29;
l27:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32757))+16);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32757))+16);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 32765)), 0);
  OOC_Make_WriteMainFileC__WriteFile((OOC_Repository__Module)i1, (void*)(_check_pointer(i0, 32765)), i2);
  i0=1u;
l29:
  return i0;
  ;
}

OOC_CHAR8 OOC_Make__RulesDesc_UpdateMainObjectFile(OOC_Make__Rules r, OOC_Repository__Module module) {
  register OOC_INT32 i0,i1,i2;
  OOC_CHAR8 success;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)module;
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33233)))), OOC_Make__RulesDesc_Update)),OOC_Make__RulesDesc_Update)((OOC_Make__Rules)i0, (OOC_Repository__Module)i1, 15);
  success = i0;
  i2 = OOC_Config_CCompiler__SkipCallCC();
  i2 = !i2;
  if (i2) goto l3;
  i2=0u;
  goto l5;
l3:
  i2 = OOC_Make__DerivedIsOlder((OOC_Repository__Module)i1, 17, 15);
  
l5:
  if (!i2) goto l8;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 33389)))), OOC_Repository__ModuleDesc_CreateOutputDir)),OOC_Repository__ModuleDesc_CreateOutputDir)((OOC_Repository__Module)i1, 17);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 33552)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i1, 17, 1u);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 33475)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i1, 15, 1u);
  i0 = (OOC_INT32)OOC_Config_CCompiler__CompileFileCmd((URI__URI)i1, (URI__URI)i0, 0u);
  OOC_Logger__ShellCommand((Object__String)i0);
  i0 = OS_ProcessManagement__system((Object__String)i0);
  i0 = i0==0;
  
l8:
  return i0;
  ;
}

OOC_Make__ModuleList OOC_Make__ModuleClosure(OOC_Repository__Module module) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
  ADT_Dictionary__Dictionary dict;
  ADT_ArrayList__ArrayList list;
  OOC_Make__ModuleList a;
  OOC_INT32 i;
  auto void OOC_Make__ModuleClosure_Closure(OOC_Repository__Module module);
    
    void OOC_Make__ModuleClosure_Closure(OOC_Repository__Module module) {
      register OOC_INT32 i0,i1,i2,i3,i4;
      OOC_INT32 i;

      i0 = (OOC_INT32)module;
      i1 = (OOC_INT32)dict;
      i1 = ADT_Dictionary__DictionaryDesc_HasKey((ADT_Dictionary__Dictionary)i1, (Object__Object)i0);
      i1 = !i1;
      if (!i1) goto l14;
      i1 = (OOC_INT32)dict;
      ADT_Dictionary__DictionaryDesc_Set((ADT_Dictionary__Dictionary)i1, (Object__Object)i0, (Object__Object)(OOC_INT32)0);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34133))+20);
      i = 0;
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 34146)), 0);
      i2 = 0<i1;
      if (!i2) goto l13;
      i2=0;
l5_loop:
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34174))+20);
      i3 = _check_pointer(i3, 34187);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = *(OOC_UINT8*)((i3+((_check_index(i2, i4, OOC_UINT32, 34187))*16))+8);
      i3 = !i3;
      if (!i3) goto l8;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34230))+20);
      i3 = _check_pointer(i3, 34243);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)((i3+((_check_index(i2, i4, OOC_UINT32, 34243))*16))+4);
      _assert((i3!=(OOC_INT32)0), 127, 34217);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34288))+20);
      i3 = _check_pointer(i3, 34301);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)((i3+((_check_index(i2, i4, OOC_UINT32, 34301))*16))+4);
      OOC_Make__ModuleClosure_Closure((OOC_Repository__Module)i3);
l8:
      i2 = i2+1;
      i = i2;
      i3 = i2<i1;
      if (i3) goto l5_loop;
l13:
      i1 = (OOC_INT32)list;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 34355)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i1, (Object__Object)i0);
l14:
      return;
      ;
    }


  i0 = (OOC_INT32)ADT_Dictionary__New();
  dict = (ADT_Dictionary__Dictionary)i0;
  i0 = (OOC_INT32)ADT_ArrayList__New(16);
  list = (ADT_ArrayList__ArrayList)i0;
  i0 = (OOC_INT32)module;
  OOC_Make__ModuleClosure_Closure((OOC_Repository__Module)i0);
  i0 = (OOC_INT32)list;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 34552))+4);
  i1 = (OOC_INT32)RT0__NewObject(_td_OOC_Make__ModuleList.baseTypes[0], i1);
  a = (OOC_Make__ModuleList)i1;
  i = 0;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 34582))+4);
  i3 = 0<i2;
  if (!i3) goto l8;
  i3=0;
l3_loop:
  i4 = _check_pointer(i1, 34600);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 34611));
  i6 = _check_pointer(i6, 34617);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i3, i7, OOC_UINT32, 34617))*4);
  *(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 34600))*4) = (_type_guard(i6, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 34625)))), &_td_OOC_Repository__ModuleDesc, 34625));
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l3_loop;
l8:
  return (OOC_Make__ModuleList)i1;
  ;
}

OOC_CHAR8 OOC_Make__RulesDesc_UpdateExecutable(OOC_Make__Rules r, OOC_Repository__Module module) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_CHAR8 success;
  OOC_CHAR8 isUpToDate;
  OOC_INT32 i;
  ADT_Dictionary__Dictionary dict;
  ADT_ArrayList__ArrayList list;
  auto void OOC_Make__RulesDesc_UpdateExecutable_Closure(OOC_Repository__Module module);
    
    void OOC_Make__RulesDesc_UpdateExecutable_Closure(OOC_Repository__Module module) {
      register OOC_INT32 i0,i1,i2,i3,i4;
      OOC_INT32 i;

      i0 = (OOC_INT32)module;
      i1 = (OOC_INT32)dict;
      i1 = ADT_Dictionary__DictionaryDesc_HasKey((ADT_Dictionary__Dictionary)i1, (Object__Object)i0);
      i1 = !i1;
      if (!i1) goto l14;
      i1 = (OOC_INT32)dict;
      ADT_Dictionary__DictionaryDesc_Set((ADT_Dictionary__Dictionary)i1, (Object__Object)i0, (Object__Object)(OOC_INT32)0);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35369))+20);
      i = 0;
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 35382)), 0);
      i2 = 0<i1;
      if (!i2) goto l13;
      i2=0;
l5_loop:
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35410))+20);
      i3 = _check_pointer(i3, 35423);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = *(OOC_UINT8*)((i3+((_check_index(i2, i4, OOC_UINT32, 35423))*16))+8);
      i3 = !i3;
      if (!i3) goto l8;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35466))+20);
      i3 = _check_pointer(i3, 35479);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)((i3+((_check_index(i2, i4, OOC_UINT32, 35479))*16))+4);
      _assert((i3!=(OOC_INT32)0), 127, 35453);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35524))+20);
      i3 = _check_pointer(i3, 35537);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)((i3+((_check_index(i2, i4, OOC_UINT32, 35537))*16))+4);
      OOC_Make__RulesDesc_UpdateExecutable_Closure((OOC_Repository__Module)i3);
l8:
      i2 = i2+1;
      i = i2;
      i3 = i2<i1;
      if (i3) goto l5_loop;
l13:
      i1 = (OOC_INT32)list;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 35591)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i1, (Object__Object)i0);
l14:
      return;
      ;
    }


  success = 0u;
  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)module;
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 35721)))), OOC_Make__RulesDesc_Update)),OOC_Make__RulesDesc_Update)((OOC_Make__Rules)i0, (OOC_Repository__Module)i1, 1);
  if (i2) goto l3;
  i0=0u;
  goto l48;
l3:
  i2 = (OOC_INT32)OOC_Make__ModuleClosure((OOC_Repository__Module)i1);
  *(OOC_INT32*)((_check_pointer(i0, 36009))+16) = i2;
  isUpToDate = 1u;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36102))+16);
  i = 0;
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 36110)), 0);
  i3 = 0<i2;
  if (i3) goto l6;
  i2=1u;
  goto l32;
l6:
  i3=0;i4=1u;
l7_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36131))+16);
  i5 = _check_pointer(i5, 36139);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i3, i6, OOC_UINT32, 36139))*4);
  i5 = *(OOC_INT8*)((_check_pointer(i5, 36142))+16);
  i5 = i5==4;
  if (i5) goto l10;
  i5=0u;
  goto l12;
l10:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36193))+16);
  i5 = _check_pointer(i5, 36201);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i3, i6, OOC_UINT32, 36201))*4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 36204))+12);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 36211))+56);
  i5 = i5!=(OOC_INT32)0;
  
l12:
  if (i5) goto l27;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36389))+16);
  i5 = _check_pointer(i5, 36397);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i3, i6, OOC_UINT32, 36397))*4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 36400))+12);
  i5 = OOC_SymbolTable__ModuleDesc_NoObjectFile((OOC_SymbolTable__Module)i5);
  if (i5) goto l27;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36520))+16);
  i5 = _check_pointer(i5, 36528);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i3, i6, OOC_UINT32, 36528))*4);
  i5 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36511)))), OOC_Make__RulesDesc_Update)),OOC_Make__RulesDesc_Update)((OOC_Make__Rules)i0, (OOC_Repository__Module)i5, 7);
  i5 = !i5;
  if (i5) goto l22;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36669))+16);
  i5 = _check_pointer(i5, 36677);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i3, i6, OOC_UINT32, 36677))*4);
  i5 = OOC_Make__DerivedIsOlder2((OOC_Repository__Module)i1, 18, (OOC_Repository__Module)i5, 7);
  if (!i5) goto l27;
  isUpToDate = 0u;
  i4=0u;
  goto l27;
l22:
  return 0u;
  
l27:
  i3 = i3+1;
  i = i3;
  i5 = i3<i2;
  if (i5) goto l7_loop;
l31:
  i2=i4;
l32:
  i3 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36779)))), OOC_Make__RulesDesc_Update)),OOC_Make__RulesDesc_Update)((OOC_Make__Rules)i0, (OOC_Repository__Module)i1, 17);
  i3 = !i3;
  if (!i3) goto l36;
  return 0u;
l36:
  if (i2) goto l38;
  i2=0u;
  goto l39;
l38:
  i2 = OOC_Make__DerivedIsOlder((OOC_Repository__Module)i1, 18, 17);
  i2 = !i2;
  
l39:
  isUpToDate = i2;
  if (i2) goto l42;
  i2 = OOC_Config_CCompiler__SkipCallCC();
  
  goto l44;
l42:
  i2=1u;
l44:
  if (i2) goto l46;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 37159))+16);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 37159))+16);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 37167)), 0);
  i0 = OOC_Make_LinkProgramC__Run((OOC_Repository__Module)i1, (void*)(_check_pointer(i0, 37167)), i2, (OOC_Package__Library)(OOC_INT32)0);
  
  goto l48;
l46:
  i0=1u;
l48:
  return i0;
  ;
}

OOC_CHAR8 OOC_Make__RulesDesc_UpdateLibrary(OOC_Make__Rules r, OOC_Repository__Module module) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
  OOC_CHAR8 success;
  OOC_Make__ModuleList closure;
  OOC_CHAR8 isUpToDate;
  OOC_INT32 i;
  Object__String importLibrary;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)module;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 37913));
  *(OOC_INT32*)((_check_pointer(i0, 37887))+12) = i2;
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 38121)))), OOC_Make__RulesDesc_Update)),OOC_Make__RulesDesc_Update)((OOC_Make__Rules)i0, (OOC_Repository__Module)i1, 1);
  success = i2;
  if (i2) goto l3;
  i0=i2;
  goto l40;
l3:
  i3 = (OOC_INT32)OOC_Make__ModuleClosure((OOC_Repository__Module)i1);
  closure = (OOC_Make__ModuleList)i3;
  *(OOC_INT32*)((_check_pointer(i0, 38224))+16) = i3;
  i4 = OOC_Make__Exists((OOC_Repository__Module)i1, 19);
  isUpToDate = i4;
  i = 0;
  i5 = OOC_ARRAY_LENGTH((_check_pointer(i3, 38390)), 0);
  i6 = 0<i5;
  if (!i6) goto l32;
  i6=i4;i4=0;
l7_loop:
  i7 = _check_pointer(i3, 38430);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)(i7+(_check_index(i4, i8, OOC_UINT32, 38430))*4);
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i7, 38433))+12);
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i7, 38440))+56);
  importLibrary = (Object__String)i7;
  i8 = i7!=0;
  if (i8) goto l10;
  i7=0u;
  goto l12;
l10:
  i8 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 38512)))), OOC_Make__RulesDesc_LibraryName)),OOC_Make__RulesDesc_LibraryName)((OOC_Make__Rules)i0);
  i7 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 38503)))), Object__StringDesc_Equals)),Object__StringDesc_Equals)((Object__String)i7, (Object__Object)i8);
  i7 = !i7;
  
l12:
  if (i7) goto l27;
  i7 = _check_pointer(i3, 38603);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)(i7+(_check_index(i4, i8, OOC_UINT32, 38603))*4);
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i7, 38606))+12);
  i7 = OOC_SymbolTable__ModuleDesc_NoObjectFile((OOC_SymbolTable__Module)i7);
  if (i7) goto l27;
  i7 = _check_pointer(i3, 38686);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)(i7+(_check_index(i4, i8, OOC_UINT32, 38686))*4);
  i7 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 38671)))), OOC_Make__RulesDesc_Update)),OOC_Make__RulesDesc_Update)((OOC_Make__Rules)i0, (OOC_Repository__Module)i7, 8);
  i7 = !i7;
  if (i7) goto l22;
  i7 = _check_pointer(i3, 38833);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)(i7+(_check_index(i4, i8, OOC_UINT32, 38833))*4);
  i7 = OOC_Make__DerivedIsOlder2((OOC_Repository__Module)i1, 19, (OOC_Repository__Module)i7, 8);
  if (!i7) goto l27;
  isUpToDate = 0u;
  i6=0u;
  goto l27;
l22:
  return 0u;
  
l27:
  i4 = i4+1;
  i = i4;
  i7 = i4<i5;
  if (i7) goto l7_loop;
l31:
  i4=i6;
l32:
  i5 = !i4;
  if (i5) goto l35;
  i0=i2;
  goto l40;
l35:
  if (i4) goto l37;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 39339))+4);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i3, 39335)), 0);
  i0 = OOC_Make_LinkProgramC__Run((OOC_Repository__Module)i1, (void*)(_check_pointer(i3, 39335)), i2, (OOC_Package__Library)i0);
  
  goto l40;
l37:
  i0=1u;
l40:
  return i0;
  ;
}

OOC_CHAR8 OOC_Make__RulesDesc_Update(OOC_Make__Rules r, OOC_Repository__Module module, OOC_INT8 fileId) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_Make__ModuleInfo mInfo;
  OOC_CHAR8 res;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)module;
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 39705)))), OOC_Make__RulesDesc_GetModuleInfo)),OOC_Make__RulesDesc_GetModuleInfo)((OOC_Make__Rules)i0, (OOC_Repository__Module)i1);
  mInfo = (OOC_Make__ModuleInfo)i2;
  i3 = fileId;
  i4 = *(OOC_UINT8*)((_check_pointer(i2, 39741))+(_check_index(i3, 22, OOC_UINT8, 39749)));
  if (i4) goto l25;
  i4 = *(OOC_UINT32*)((_check_pointer(i1, 39916))+24);
  i4 = _in(i3,i4);
  if (i4) goto l23;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 40098))+4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 40098))+4);
  i4 = OOC_ARRAY_LENGTH((_check_pointer(i4, 40103)), 0);
  OOC_Logger__EnterMake((void*)(_check_pointer(i5, 40103)), i4, (void*)((OOC_INT32)OOC_Make__fileIdNames+((_check_index(i3, 22, OOC_UINT8, 40117))*24)), 24);
  i4 = *(OOC_UINT32*)((_check_pointer(i1, 40145))+24);
  *(OOC_UINT32*)((_check_pointer(i1, 40145))+24) = (_set_bit(i4,i3));
  switch (i3) {
  case 18:
    i0 = OOC_Make__RulesDesc_UpdateExecutable((OOC_Make__Rules)i0, (OOC_Repository__Module)i1);
    res = i0;
    goto l22;
  case 19:
    i0 = OOC_Make__RulesDesc_UpdateLibrary((OOC_Make__Rules)i0, (OOC_Repository__Module)i1);
    res = i0;
    goto l22;
  case 17:
    i0 = OOC_Make__RulesDesc_UpdateMainObjectFile((OOC_Make__Rules)i0, (OOC_Repository__Module)i1);
    res = i0;
    goto l22;
  case 15:
    i0 = OOC_Make__RulesDesc_UpdateMainFileC((OOC_Make__Rules)i0, (OOC_Repository__Module)i1);
    res = i0;
    goto l22;
  case 7:
    i0 = OOC_Make__RulesDesc_UpdateObjectFile((OOC_Make__Rules)i0, (OOC_Repository__Module)i1);
    res = i0;
    goto l22;
  case 8:
    i0 = OOC_Make__RulesDesc_UpdateObjectFileLib((OOC_Make__Rules)i0, (OOC_Repository__Module)i1);
    res = i0;
    goto l22;
  case 11:
    i0 = OOC_Make__RulesDesc_UpdateCodeFileC((OOC_Make__Rules)i0, (OOC_Repository__Module)i1);
    res = i0;
    goto l22;
  case 12:
    i0 = OOC_Make__RulesDesc_UpdateDeclFileC((OOC_Make__Rules)i0, (OOC_Repository__Module)i1);
    res = i0;
    goto l22;
  case 13:
    i0 = OOC_Make__RulesDesc_UpdateHeaderFileC((OOC_Make__Rules)i0, (OOC_Repository__Module)i1);
    res = i0;
    goto l22;
  case 14:
    i0 = OOC_Make__RulesDesc_UpdateAssemblerFile((OOC_Make__Rules)i0, (OOC_Repository__Module)i1);
    res = i0;
    goto l22;
  case 4:
    i0 = OOC_Make__RulesDesc_UpdateInterfaceDescr((OOC_Make__Rules)i0, (OOC_Repository__Module)i1);
    res = i0;
    goto l22;
  case 3:
    i0 = OOC_Make__RulesDesc_UpdateInterfaceXML((OOC_Make__Rules)i0, (OOC_Repository__Module)i1);
    res = i0;
    goto l22;
  case 5:
    i0 = OOC_Make__RulesDesc_UpdateInterfaceHTML((OOC_Make__Rules)i0, (OOC_Repository__Module)i1);
    res = i0;
    goto l22;
  case 2:
    i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 41176)))), OOC_Make__RulesDesc_UpdateSymbolTableXML)),OOC_Make__RulesDesc_UpdateSymbolTableXML)((OOC_Make__Rules)i0, (OOC_Repository__Module)i1);
    res = i0;
    goto l22;
  case 1:
    i0 = OOC_Make__RulesDesc_UpdateSymbolFile((OOC_Make__Rules)i0, (OOC_Repository__Module)i1);
    res = i0;
    goto l22;
  default:
    _failed_case(i3, 40176);
    goto l22;
  }
l22:
  *(OOC_UINT8*)((_check_pointer(i2, 41299))+(_check_index(i3, 22, OOC_UINT8, 41307))) = 1u;
  i0 = res;
  *(OOC_UINT8*)(((_check_pointer(i2, 41336))+22)+(_check_index(i3, 22, OOC_UINT8, 41349))) = i0;
  i2 = *(OOC_UINT32*)((_check_pointer(i1, 41383))+24);
  *(OOC_UINT32*)((_check_pointer(i1, 41383))+24) = (_clear_bit(i2,i3));
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 41443))+4);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 41443))+4);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 41448)), 0);
  i0 = OOC_Logger__ExitMake((void*)(_check_pointer(i1, 41448)), i2, (void*)((OOC_INT32)OOC_Make__fileIdNames+((_check_index(i3, 22, OOC_UINT8, 41462))*24)), 24, i0);
  return i0;
  goto l26;
l23:
  Out__String("Error: Cyclic dependency in module ", 36);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 40017))+4);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 40017))+4);
  i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 40022)), 0);
  Out__String((void*)(_check_pointer(i1, 40022)), i0);
  Out__Ln();
  return 0u;
  goto l26;
l25:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 39852))+4);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 39852))+4);
  i2 = *(OOC_UINT8*)(((_check_pointer(i2, 39865))+22)+(_check_index(i3, 22, OOC_UINT8, 39878)));
  i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 39857)), 0);
  i0 = OOC_Logger__CachedMake((void*)((OOC_INT32)OOC_Make__fileIdNames+((_check_index(i3, 22, OOC_UINT8, 39805))*24)), 24, (void*)(_check_pointer(i1, 39857)), i0, i2);
  return i0;
l26:
  _failed_function(39562); return 0;
  ;
}

void OOC_OOC_Make_init(void) {
  register OOC_INT32 i0;
  _c0 = Object__NewLatin1Region(" -o ", 5, 0, 4);
  _c1 = Object__NewLatin1Char(32u);
  _c2 = Object__NewLatin1Char(32u);

  i0 = (OOC_INT32)StringSearch_NoMatch__matcher;
  OOC_Make__inspectProc = (StringSearch__Matcher)i0;
  OOC_Make__inspectStage = (StringSearch__Matcher)i0;
  OOC_Make__writeAST = 0u;
  OOC_Make__writeIR = 0u;
  OOC_Make__writeStats = 0u;
  OOC_Make__stylesheetSystemId = (URI__URI)(OOC_INT32)0;
  _copy_8((const void*)"Executable",(void*)((OOC_INT32)OOC_Make__fileIdNames+((_check_index(18, 22, OOC_UINT8, 41686))*24)),24);
  _copy_8((const void*)"Library",(void*)((OOC_INT32)OOC_Make__fileIdNames+((_check_index(19, 22, OOC_UINT8, 41736))*24)),24);
  _copy_8((const void*)"MainObjectFile",(void*)((OOC_INT32)OOC_Make__fileIdNames+((_check_index(17, 22, OOC_UINT8, 41780))*24)),24);
  _copy_8((const void*)"MainFileC",(void*)((OOC_INT32)OOC_Make__fileIdNames+((_check_index(15, 22, OOC_UINT8, 41838))*24)),24);
  _copy_8((const void*)"ObjectFile",(void*)((OOC_INT32)OOC_Make__fileIdNames+((_check_index(7, 22, OOC_UINT8, 41886))*24)),24);
  _copy_8((const void*)"ObjectFileLib",(void*)((OOC_INT32)OOC_Make__fileIdNames+((_check_index(8, 22, OOC_UINT8, 41936))*24)),24);
  _copy_8((const void*)"CodeFileC",(void*)((OOC_INT32)OOC_Make__fileIdNames+((_check_index(11, 22, OOC_UINT8, 41992))*24)),24);
  _copy_8((const void*)"DeclFileC",(void*)((OOC_INT32)OOC_Make__fileIdNames+((_check_index(12, 22, OOC_UINT8, 42040))*24)),24);
  _copy_8((const void*)"HeaderFileC",(void*)((OOC_INT32)OOC_Make__fileIdNames+((_check_index(13, 22, OOC_UINT8, 42088))*24)),24);
  _copy_8((const void*)"InterfaceDescr",(void*)((OOC_INT32)OOC_Make__fileIdNames+((_check_index(4, 22, OOC_UINT8, 42140))*24)),24);
  _copy_8((const void*)"InterfaceXML",(void*)((OOC_INT32)OOC_Make__fileIdNames+((_check_index(3, 22, OOC_UINT8, 42198))*24)),24);
  _copy_8((const void*)"InterfaceHTML",(void*)((OOC_INT32)OOC_Make__fileIdNames+((_check_index(5, 22, OOC_UINT8, 42252))*24)),24);
  _copy_8((const void*)"SymbolFile",(void*)((OOC_INT32)OOC_Make__fileIdNames+((_check_index(1, 22, OOC_UINT8, 42308))*24)),24);
  _copy_8((const void*)"SymbolTableXML",(void*)((OOC_INT32)OOC_Make__fileIdNames+((_check_index(2, 22, OOC_UINT8, 42358))*24)),24);
  _copy_8((const void*)"AssemblerFile",(void*)((OOC_INT32)OOC_Make__fileIdNames+((_check_index(14, 22, OOC_UINT8, 42416))*24)),24);
  _copy_8((const void*)"MainFileAssembler",(void*)((OOC_INT32)OOC_Make__fileIdNames+((_check_index(16, 22, OOC_UINT8, 42472))*24)),24);
  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Make__ErrorContext.baseTypes[0]);
  OOC_Make__makeContext = (OOC_Make__ErrorContext)i0;
  OOC_Error__InitContext((OOC_Error__Context)i0, "OOC:Make", 9);
  return;
  ;
}

/* --- */
