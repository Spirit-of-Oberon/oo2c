#include <OOC/Make.d>
#include <__oo2c.h>
#include <setjmp.h>

void OOC_Make__ErrorContextDesc_GetTemplate(OOC_Make__ErrorContext context, Msg__Msg msg, Msg__LString templ, OOC_LEN templ_0d) {
  register OOC_INT32 i0,i1;
  OOC_CHAR16 t[128];

  i0 = (OOC_INT32)msg;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 4794))+8);
  switch (i1) {
  case 1:
    _copy_16((const void*)((OOC_CHAR16[]){67,97,110,110,111,116,32,108,111,99,97,116,101,32,109,111,100,117,108,101,32,96,36,123,110,97,109,101,125,39,0}),(void*)(OOC_INT32)t,128);
    goto l5;
  case 2:
    _copy_16((const void*)((OOC_CHAR16[]){77,111,100,117,108,101,32,105,115,32,97,108,114,101,97,100,121,32,112,97,114,116,32,111,102,32,108,105,98,114,97,114,121,32,96,36,123,110,97,109,101,125,39,0}),(void*)(OOC_INT32)t,128);
    goto l5;
  default:
    _failed_case(i1, 4786);
    goto l5;
  }
l5:
  i1 = (OOC_INT32)context;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4973)))), OOC_Error__ContextDesc_BaseTemplate)),OOC_Error__ContextDesc_BaseTemplate)((OOC_Error__Context)i1, (Msg__Msg)i0, (void*)(OOC_INT32)t, 128, (void*)(OOC_INT32)templ, templ_0d);
  return;
  ;
}

void OOC_Make__InitRules(OOC_Make__Rules r) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)r;
  *(OOC_INT32*)(_check_pointer(i0, 5071)) = 1;
  *(OOC_INT32*)((_check_pointer(i0, 5103))+4) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 5125))+8) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 5166))+12) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 5196))+16) = 0;
  i1 = (OOC_INT32)ADT_Dictionary__New();
  *(OOC_INT32*)((_check_pointer(i0, 5218))+20) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 5251))+24) = 0;
  *(OOC_UINT8*)((_check_pointer(i0, 5279))+28) = 1u;
  i1 = (OOC_INT32)IO_StdChannels__stdout;
  *(OOC_INT32*)((_check_pointer(i0, 5313))+32) = i1;
  *(OOC_UINT8*)((_check_pointer(i0, 5349))+36) = 0u;
  *(OOC_UINT8*)((_check_pointer(i0, 5377))+36) = 0u;
  *(OOC_INT32*)((_check_pointer(i0, 5405))+40) = 0;
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
  *(OOC_INT32*)(_check_pointer(i0, 5622)) = i1;
  return;
  ;
}

void OOC_Make__RulesDesc_SetLibrary(OOC_Make__Rules r, OOC_Package__Library library) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)library;
  *(OOC_INT32*)((_check_pointer(i0, 5736))+4) = i1;
  return;
  ;
}

Object__String OOC_Make__RulesDesc_LibraryName(OOC_Make__Rules r) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5838))+4);
  i1 = i1!=(OOC_INT32)0;
  if (i1) goto l3;
  return (Object__String)(OOC_INT32)0;
  goto l4;
l3:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5873))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5881));
  return (Object__String)i0;
l4:
  _failed_function(5797); return 0;
  ;
}

void OOC_Make__RulesDesc_SetAllImportsModule(OOC_Make__Rules r, OOC_Repository__Module module) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)module;
  *(OOC_INT32*)((_check_pointer(i0, 6020))+8) = i1;
  return;
  ;
}

void OOC_Make__RulesDesc_SetErrOut(OOC_Make__Rules r, IO__ByteChannel ch) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)ch;
  *(OOC_INT32*)((_check_pointer(i0, 6149))+32) = i1;
  return;
  ;
}

void OOC_Make__RulesDesc_SetForceUpdate(OOC_Make__Rules r, OOC_CHAR8 forceUpdate) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)r;
  i1 = forceUpdate;
  *(OOC_UINT8*)((_check_pointer(i0, 6255))+36) = i1;
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
  *(OOC_INT32*)((_check_pointer(i0, 6416))+40) = i1;
  return (!i2);
  ;
}

void OOC_Make__RulesDesc_SetExtensionDict(OOC_Make__Rules r, ADT_Dictionary__Dictionary dict) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)dict;
  *(OOC_INT32*)((_check_pointer(i0, 6583))+24) = i1;
  return;
  ;
}

OOC_CHAR8 OOC_Make__RulesDesc_CheckAllImports(OOC_Make__Rules r, OOC_Repository__Module module) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6918))+8);
  i1 = i1==(OOC_INT32)0;
  if (i1) goto l3;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6961))+8);
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
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7174))+20);
  i2 = (OOC_INT32)module;
  i1 = ADT_Dictionary__DictionaryDesc_HasKey((ADT_Dictionary__Dictionary)i1, (Object__Object)i2);
  if (i1) goto l8;
  i1 = (OOC_INT32)RT0__NewObject(_td_OOC_Make__ModuleInfo.baseTypes[0]);
  mInfo = (OOC_Make__ModuleInfo)i1;
  i = 0;
  i3=0;
l3_loop:
  *(OOC_UINT8*)((_check_pointer(i1, 7344))+(_check_index(i3, 22, OOC_UINT32, 7352))) = 0u;
  *(OOC_UINT8*)(((_check_pointer(i1, 7379))+22)+(_check_index(i3, 22, OOC_UINT32, 7392))) = 0u;
  i3 = i3+1;
  i = i3;
  i4 = i3<=21;
  if (i4) goto l3_loop;
l7:
  *(OOC_UINT8*)((_check_pointer(i1, 7428))+44) = 0u;
  *(OOC_UINT8*)((_check_pointer(i1, 7459))+45) = 0u;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7491))+20);
  ADT_Dictionary__DictionaryDesc_Set((ADT_Dictionary__Dictionary)i0, (Object__Object)i2, (Object__Object)i1);
  i0=i1;
  goto l9;
l8:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7215))+20);
  i0 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i0, (Object__Object)i2);
  obj = (Object__Object)i0;
  i0 = _type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7254)))), &_td_OOC_Make__ModuleInfoDesc, 7254);
  
l9:
  return (OOC_Make__ModuleInfo)i0;
  ;
}

static OOC_CHAR8 OOC_Make__Exists(OOC_Repository__Module module, OOC_INT8 fileId) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)module;
  i1 = fileId;
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7656)))), OOC_Repository__ModuleDesc_FileExists)),OOC_Repository__ModuleDesc_FileExists)((OOC_Repository__Module)i0, i1);
  if (i2) goto l3;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7832)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i0, i1, 1u);
  OOC_Logger__ExplainFileMake("file ", 6, (URI__URI)i0, " does not exist", 16);
  return 0u;
  goto l4;
l3:
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7725)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i0, i1, 1u);
  OOC_Logger__ExplainFileMake("file ", 6, (URI__URI)i0, " exists", 8);
  return 1u;
l4:
  _failed_function(7577); return 0;
  ;
}

static OOC_CHAR8 OOC_Make__DerivedIsOlder2(OOC_Repository__Module descendentModule, OOC_INT8 descendent, OOC_Repository__Module ancestorModule, OOC_INT8 ancestor) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  struct Time__TimeStamp tsDesc;
  struct Time__TimeStamp tsAncest;

  i0 = (OOC_INT32)descendentModule;
  i1 = descendent;
  i2 = (OOC_INT32)&_td_Time__TimeStamp;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8480)))), OOC_Repository__ModuleDesc_GetTimeStamp)),OOC_Repository__ModuleDesc_GetTimeStamp)((OOC_Repository__Module)i0, i1, (void*)(OOC_INT32)&tsDesc, (RT0__Struct)i2);
  i3 = *(OOC_INT32*)(OOC_INT32)&tsDesc;
  i3 = i3==2147483647;
  if (i3) goto l7;
  i3 = (OOC_INT32)ancestorModule;
  i4 = ancestor;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 8734)))), OOC_Repository__ModuleDesc_GetTimeStamp)),OOC_Repository__ModuleDesc_GetTimeStamp)((OOC_Repository__Module)i3, i4, (void*)(OOC_INT32)&tsAncest, (RT0__Struct)i2);
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(i2, Time__TimeStamp_Cmp)),Time__TimeStamp_Cmp)((void*)(OOC_INT32)&tsDesc, (RT0__Struct)i2, (void*)(OOC_INT32)&tsAncest);
  i2 = i2>=0;
  if (i2) goto l5;
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 9154)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i3, i4, 1u);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9070)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i0, i1, 1u);
  OOC_Logger__ExplainFilesMake("ts(", 4, (URI__URI)i0, ") < ts(", 8, (URI__URI)i2, ")", 2);
  return 1u;
  goto l8;
l5:
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 8951)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i3, i4, 1u);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8866)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i0, i1, 1u);
  OOC_Logger__ExplainFilesMake("ts(", 4, (URI__URI)i0, ") >= ts(", 9, (URI__URI)i2, ")", 2);
  return 0u;
  goto l8;
l7:
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8610)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i0, i1, 1u);
  OOC_Logger__ExplainFileMake("file ", 6, (URI__URI)i0, " does not exist", 16);
  return 1u;
l8:
  _failed_function(7929); return 0;
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
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10074)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i0, 1, 1u);
  i1 = (OOC_INT32)descendentModule;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9985)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i1, 1, 1u);
  OOC_Logger__ExplainFilesMake("fp(", 4, (URI__URI)i1, ") # fp(", 8, (URI__URI)i0, ")", 2);
  return 1u;
  goto l4;
l3:
  i0 = (OOC_INT32)ancestorModule;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9863)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i0, 1, 1u);
  i1 = (OOC_INT32)descendentModule;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9774)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i1, 1, 1u);
  OOC_Logger__ExplainFilesMake("fp(", 4, (URI__URI)i1, ") = fp(", 8, (URI__URI)i0, ")", 2);
  return 0u;
l4:
  _failed_function(9447); return 0;
  ;
}

static OOC_Error__List OOC_Make__CreateErrList(OOC_Repository__Module module) {
  register OOC_INT32 i0;
  URI__URI uri;

  i0 = (OOC_INT32)module;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10276)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i0, 0, 1u);
  uri = (URI__URI)i0;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10340)))), URI__URIDesc_ToString)),URI__URIDesc_ToString)((URI__URI)i0);
  i0 = (OOC_INT32)OOC_Error__NewList((Object__String)i0);
  return (OOC_Error__List)i0;
  ;
}

void OOC_Make__RulesDesc_WriteErrList(OOC_Make__Rules r, OOC_Error__List errList) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)errList;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 10457));
  i1 = i1!=0;
  if (!i1) goto l4;
  i1 = (OOC_INT32)r;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 10498))+32);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 10712)))), OOC_Make__RulesDesc_WriteErrList)),OOC_Make__RulesDesc_WriteErrList)((OOC_Make__Rules)i1, (OOC_Error__List)i0);
  return;
  ;
}

static void OOC_Make__WriteImports(OOC_Repository__Module module) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT32 i;
  OOC_Repository__Module import;

  i0 = (OOC_INT32)module;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 10897))+16);
  _assert((i1>=2), 127, 10884);
  Out__String("> IMPORT of ", 13);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10978))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10978))+4);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 10983)), 0);
  Out__String((void*)(_check_pointer(i2, 10983)), i1);
  Out__Ln();
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11023))+20);
  i = 0;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 11036)), 0);
  i2 = 0<i1;
  if (!i2) goto l12;
  i2=0;
l3_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11096))+20);
  i3 = _check_pointer(i3, 11109);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = (OOC_INT32)*(OOC_INT32*)(i3+((_check_index(i2, i4, OOC_UINT32, 11109))*16));
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 11117))+12);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11096))+20);
  i4 = _check_pointer(i4, 11109);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+((_check_index(i2, i5, OOC_UINT32, 11109))*16));
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 11117))+12);
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 11121)), 0);
  i5 = (OOC_INT32)OOC_Config__repositories;
  i3 = (OOC_INT32)OOC_Config_Repositories__SectionDesc_GetModule((OOC_Config_Repositories__Section)i5, (void*)(_check_pointer(i4, 11121)), i3);
  import = (OOC_Repository__Module)i3;
  i4 = i3==0;
  if (i4) goto l6;
  Out__String("> ", 3);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 11328))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 11328))+4);
  i4 = OOC_ARRAY_LENGTH((_check_pointer(i4, 11333)), 0);
  Out__String((void*)(_check_pointer(i3, 11333)), i4);
  Out__Ln();
  goto l7;
l6:
  Out__String("> no such module: ", 19);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11221))+20);
  i3 = _check_pointer(i3, 11234);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = (OOC_INT32)*(OOC_INT32*)(i3+((_check_index(i2, i4, OOC_UINT32, 11234))*16));
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 11242))+12);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11221))+20);
  i4 = _check_pointer(i4, 11234);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+((_check_index(i2, i5, OOC_UINT32, 11234))*16));
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 11242))+12);
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 11246)), 0);
  Out__String((void*)(_check_pointer(i4, 11246)), i3);
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
          i2 = *(OOC_INT32*)(_check_pointer(i1, 12272));
          pos = i2;
          i3 = i2<0;
          if (!i3) goto l4;
          pos = 0;
          i2=0;
l4:
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12354)))), Msg__MsgDesc_SetIntAttrib)),Msg__MsgDesc_SetIntAttrib)((Msg__Msg)i0, "pos", 4, i2);
          i2 = *(OOC_INT32*)((_check_pointer(i1, 12427))+4);
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12400)))), Msg__MsgDesc_SetIntAttrib)),Msg__MsgDesc_SetIntAttrib)((Msg__Msg)i0, "line", 5, i2);
          i2 = *(OOC_INT32*)((_check_pointer(i1, 12482))+8);
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12453)))), Msg__MsgDesc_SetIntAttrib)),Msg__MsgDesc_SetIntAttrib)((Msg__Msg)i0, "column", 7, i2);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12557))+12);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12557))+12);
          i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 12562)), 0);
          i1 = (OOC_INT32)Msg__GetStringPtr((void*)(_check_pointer(i1, 12562)), i2);
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12510)))), Msg__MsgDesc_SetStringAttrib)),Msg__MsgDesc_SetStringAttrib)((Msg__Msg)i0, "name", 5, (Msg__StringPtr)i1);
          i1 = (OOC_INT32)errList;
          OOC_Error__ListDesc_Append((OOC_Error__List)i1, (Msg__Msg)i0);
          return;
          ;
        }


      i0 = (OOC_INT32)module;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12663))+20);
      i = 0;
      i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 12676)), 0);
      i1 = 0<i0;
      if (!i1) goto l15;
      i1=0;
l3_loop:
      i2 = (OOC_INT32)module;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 12702))+20);
      i3 = _check_pointer(i3, 12715);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = *(OOC_UINT8*)((i3+((_check_index(i1, i4, OOC_UINT32, 12715))*16))+8);
      i3 = !i3;
      if (!i3) goto l10;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 12789))+20);
      i3 = _check_pointer(i3, 12802);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)(i3+((_check_index(i1, i4, OOC_UINT32, 12802))*16));
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 12810))+12);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 12789))+20);
      i2 = _check_pointer(i2, 12802);
      i4 = OOC_ARRAY_LENGTH(i2, 0);
      i2 = (OOC_INT32)*(OOC_INT32*)(i2+((_check_index(i1, i4, OOC_UINT32, 12802))*16));
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 12810))+12);
      i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 12814)), 0);
      i4 = (OOC_INT32)OOC_Config__repositories;
      i2 = (OOC_INT32)OOC_Config_Repositories__SectionDesc_GetModule((OOC_Config_Repositories__Section)i4, (void*)(_check_pointer(i2, 12814)), i3);
      import = (OOC_Repository__Module)i2;
      i3 = i2==0;
      if (i3) goto l8;
      i3 = (OOC_INT32)module;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 12945))+20);
      i3 = _check_pointer(i3, 12958);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      *(OOC_INT32*)((i3+((_check_index(i1, i4, OOC_UINT32, 12958))*16))+4) = i2;
      goto l10;
l8:
      i2 = (OOC_INT32)module;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 12888))+20);
      i2 = _check_pointer(i2, 12901);
      i3 = OOC_ARRAY_LENGTH(i2, 0);
      i1 = (OOC_INT32)*(OOC_INT32*)(i2+((_check_index(i1, i3, OOC_UINT32, 12901))*16));
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
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13093))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13093))+4);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 13098)), 0);
  OOC_Logger__EnterMake("GetImports", 11, (void*)(_check_pointer(i2, 13098)), i1);
  i1 = *(OOC_INT8*)((_check_pointer(i0, 13116))+16);
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
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14103)))), OOC_Repository__ModuleDesc_ReadSymbolFile)),OOC_Repository__ModuleDesc_ReadSymbolFile)((OOC_Repository__Module)i0);
  symTab = (OOC_SymbolTable__Module)i1;
  i2 = (OOC_INT32)r;
  i2 = OOC_Make__RulesDesc_CheckAllImports((OOC_Make__Rules)i2, (OOC_Repository__Module)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14141)))), OOC_Repository__ModuleDesc_SetInterfaceData)),OOC_Repository__ModuleDesc_SetInterfaceData)((OOC_Repository__Module)i0, (OOC_SymbolTable__Module)i1, 3, i2);
  i1 = (OOC_INT32)symTab;
  i1 = *(OOC_INT32*)((_check_pointer(i1, 14287))+68);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14265)))), OOC_Repository__ModuleDesc_SetFingerprint)),OOC_Repository__ModuleDesc_SetFingerprint)((OOC_Repository__Module)i0, i1);
  goto l15;
l9:
  i1 = (OOC_INT32)r;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 13659))+40);
  i3 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 13642)))), OOC_Make__RulesDesc_LibraryName)),OOC_Make__RulesDesc_LibraryName)((OOC_Make__Rules)i1);
  OOC_Auxiliary_ParseModule__ParseModule((OOC_Repository__Module)i0, 0u, 0u, 0u, 1u, (Object__String)i3, (OOC_SymbolTable_Uses__Uses)i2, (void*)(OOC_INT32)&ast, (void*)(OOC_INT32)&symTab, (void*)(OOC_INT32)&pragmaHistory, (void*)(OOC_INT32)&errList);
  i2 = (OOC_INT32)errList;
  i2 = OOC_Error__ListDesc_NoErrors((OOC_Error__List)i2);
  if (!i2) goto l15;
  i1 = OOC_Make__RulesDesc_CheckAllImports((OOC_Make__Rules)i1, (OOC_Repository__Module)i0);
  i2 = (OOC_INT32)symTab;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13781)))), OOC_Repository__ModuleDesc_SetInterfaceData)),OOC_Repository__ModuleDesc_SetInterfaceData)((OOC_Repository__Module)i0, (OOC_SymbolTable__Module)i2, 2, i1);
  goto l15;
l14:
  OOC_Logger__ExplainMake("using cached value", 19);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13252))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13252))+4);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 13257)), 0);
  i0 = OOC_Logger__ExitMake("GetImports", 11, (void*)(_check_pointer(i0, 13257)), i1, 1u);
  return i0;
l15:
  i0 = (OOC_INT32)errList;
  i0 = OOC_Error__ListDesc_NoErrors((OOC_Error__List)i0);
  if (!i0) goto l18;
  OOC_Make__RulesDesc_GetImports_ResolveNames();
l18:
  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)errList;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14384)))), OOC_Make__RulesDesc_WriteErrList)),OOC_Make__RulesDesc_WriteErrList)((OOC_Make__Rules)i0, (OOC_Error__List)i1);
  i0 = (OOC_INT32)errList;
  i0 = OOC_Error__ListDesc_NoErrors((OOC_Error__List)i0);
  i1 = (OOC_INT32)module;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14455))+4);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14455))+4);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 14460)), 0);
  i0 = OOC_Logger__ExitMake("GetImports", 11, (void*)(_check_pointer(i1, 14460)), i2, i0);
  return i0;
  ;
}

OOC_INT32 OOC_Make__RulesDesc_SelectBackend(OOC_Make__Rules r, OOC_Repository__Module module) {
  register OOC_INT32 i0,i1,i2;
  OOC_INT32 b;

  i0 = (OOC_INT32)r;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 14738));
  b = i1;
  i2 = (OOC_INT32)module;
  i0 = OOC_Make__RulesDesc_GetImports((OOC_Make__Rules)i0, (OOC_Repository__Module)i2);
  if (i0) goto l3;
  i0=i1;
  goto l16;
l3:
  i0 = i1==2;
  if (i0) goto l6;
  i0=0u;
  goto l12;
l6:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14831))+12);
  i0 = *(OOC_INT8*)((_check_pointer(i0, 14838))+52);
  i0 = i0==2;
  if (i0) goto l9;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14882))+12);
  i0 = *(OOC_INT8*)((_check_pointer(i0, 14889))+52);
  i0 = i0==3;
  
  goto l12;
l9:
  i0=1u;
l12:
  if (i0) goto l14;
  i0=i1;
  goto l16;
l14:
  i0=1;
l16:
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
  auto OOC_Error__List OOC_Make__RulesDesc_CompileModule_DoSSAtoX86(Object__String libraryName);
    
    OOC_Error__List OOC_Make__RulesDesc_CompileModule_DoEmptyBackend(Object__String libraryName) {
      register OOC_INT32 i0,i1,i2;
      OOC_Error__List errList;
      OOC_Config_Pragmas__History pragmaHistory;
      OOC_SymbolTable__Module symTab;
      OOC_AST__Node ast;

      i0 = (OOC_INT32)r;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15700))+40);
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
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 16057))+40);
      i2 = (OOC_INT32)module;
      i3 = (OOC_INT32)libraryName;
      i4 = analysisOnly;
      i5 = OOC_Make__writeAST;
      i6 = OOC_Make__writeIR;
      i0 = (OOC_INT32)OOC_Make_TranslateToC__Run((OOC_Repository__Module)i2, (Object__String)i3, i4, (OOC_SymbolTable_Uses__Uses)i1, i5, i6, (OOC_Make_TranslateToC__Translator)i0);
      return (OOC_Error__List)i0;
      ;
    }

    
    OOC_Error__List OOC_Make__RulesDesc_CompileModule_DoSSAtoX86(Object__String libraryName) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5;

      i0 = (OOC_INT32)r;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16291))+40);
      i1 = (OOC_INT32)module;
      i2 = (OOC_INT32)libraryName;
      i3 = analysisOnly;
      i4 = OOC_Make__writeAST;
      i5 = OOC_Make__writeIR;
      i0 = (OOC_INT32)OOC_Make_TranslateToX86__Run((OOC_Repository__Module)i1, (Object__String)i2, i3, (OOC_SymbolTable_Uses__Uses)i0, i4, i5);
      return (OOC_Error__List)i0;
      ;
    }


  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)module;
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16395)))), OOC_Make__RulesDesc_GetModuleInfo)),OOC_Make__RulesDesc_GetModuleInfo)((OOC_Make__Rules)i0, (OOC_Repository__Module)i1);
  mInfo = (OOC_Make__ModuleInfo)i2;
  i3 = *(OOC_UINT8*)((_check_pointer(i2, 16431))+44);
  if (i3) goto l32;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 16593))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 16593))+4);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 16598)), 0);
  OOC_Logger__EnterMake("CompileModule", 14, (void*)(_check_pointer(i3, 16598)), i2);
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16625)))), OOC_Make__RulesDesc_LibraryName)),OOC_Make__RulesDesc_LibraryName)((OOC_Make__Rules)i0);
  libraryName = (Object__String)i2;
  i3 = i2!=(OOC_INT32)0;
  if (i3) goto l5;
  i3=0u;
  goto l7;
l5:
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 16679));
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16690))+12);
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
    goto l16;
  case 1:
    i0 = (OOC_INT32)OOC_Make__RulesDesc_CompileModule_DoSSAtoC((Object__String)i2);
    errList = (OOC_Error__List)i0;
    goto l16;
  case 2:
    i0 = (OOC_INT32)OOC_Make__RulesDesc_CompileModule_DoSSAtoX86((Object__String)i2);
    errList = (OOC_Error__List)i0;
    goto l16;
  default:
    _failed_case(i0, 17031);
    goto l16;
  }
l16:
  i0 = (OOC_INT32)errList;
  i1 = i0==(OOC_INT32)0;
  if (i1) goto l19;
  i1 = OOC_Error__ListDesc_NoErrors((OOC_Error__List)i0);
  
  goto l20;
l19:
  i1=1u;
l20:
  success = i1;
  i2 = (OOC_INT32)r;
  i3 = (OOC_INT32)module;
  if (i1) goto l23;
  i4=0u;
  goto l25;
l23:
  i4 = analysisOnly;
  i4 = !i4;
  
l25:
  if (!i4) goto l31;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 17443)))), OOC_Repository__ModuleDesc_SetInterfaceData)),OOC_Repository__ModuleDesc_SetInterfaceData)((OOC_Repository__Module)i3, (OOC_SymbolTable__Module)(OOC_INT32)0, 1, 1u);
  i1 = OOC_Make__RulesDesc_GetImports((OOC_Make__Rules)i2, (OOC_Repository__Module)i3);
  success = i1;
  if (!i1) goto l31;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 17599))+12);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 17575)))), OOC_Repository__ModuleDesc_SetInterfaceData)),OOC_Repository__ModuleDesc_SetInterfaceData)((OOC_Repository__Module)i3, (OOC_SymbolTable__Module)i4, 4, 1u);
l31:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 17669)))), OOC_Make__RulesDesc_WriteErrList)),OOC_Make__RulesDesc_WriteErrList)((OOC_Make__Rules)i2, (OOC_Error__List)i0);
  i0 = (OOC_INT32)mInfo;
  *(OOC_UINT8*)((_check_pointer(i0, 17711))+44) = 1u;
  *(OOC_UINT8*)((_check_pointer(i0, 17741))+45) = i1;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 17820))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 17820))+4);
  i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 17825)), 0);
  i0 = OOC_Logger__ExitMake("CompileModule", 14, (void*)(_check_pointer(i2, 17825)), i0, i1);
  return i0;
  goto l33;
l32:
  OOC_Logger__ExplainMake("cached result: CompileModule", 29);
  i0 = *(OOC_UINT8*)((_check_pointer(i2, 16522))+45);
  return i0;
l33:
  _failed_function(15026); return 0;
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
  i1 = *(OOC_INT8*)((_check_pointer(i0, 18119))+16);
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
  i4 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 18586)))), OOC_Make__RulesDesc_LibraryName)),OOC_Make__RulesDesc_LibraryName)((OOC_Make__Rules)i1);
  i4 = i4!=(OOC_INT32)0;
  if (i4) goto l11;
  i4=0u;
  goto l13;
l11:
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 18617));
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 18628))+12);
  i4 = i4==i5;
  
l13:
  if (!i4) goto l23;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18669))+12);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 18676))+56);
  i4 = i4==(OOC_INT32)0;
  if (i4) goto l21;
  i4 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 19000)))), OOC_Make__RulesDesc_LibraryName)),OOC_Make__RulesDesc_LibraryName)((OOC_Make__Rules)i1);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18972))+12);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18972))+12);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 18979))+56);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 18979))+56);
  i4 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 18991)))), Object__StringDesc_Equals)),Object__StringDesc_Equals)((Object__String)i5, (Object__Object)i4);
  i4 = !i4;
  if (!i4) goto l23;
  i4 = (OOC_INT32)OOC_Make__makeContext;
  i4 = (OOC_INT32)OOC_Error__New((OOC_Error__Context)i4, 2);
  err = (Msg__Msg)i4;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19293))+12);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 19300))+56);
  i5 = (OOC_INT32)Object__String8Desc_CharsLatin1((Object__String8)(_type_guard(i5, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 19320)))), &_td_Object__String8Desc, 19320)));
  chars = (Object__CharsLatin1)i5;
  i6 = OOC_ARRAY_LENGTH((_check_pointer(i5, 19406)), 0);
  i5 = (OOC_INT32)Msg__GetStringPtr((void*)(_check_pointer(i5, 19406)), i6);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 19357)))), Msg__MsgDesc_SetStringAttrib)),Msg__MsgDesc_SetStringAttrib)((Msg__Msg)i4, "name", 5, (Msg__StringPtr)i5);
  OOC_Make__RulesDesc_WriteError((OOC_Make__Rules)i1, (OOC_Repository__Module)i0, (Msg__Msg)i4);
  return 0u;
  goto l23;
l21:
  OOC_Logger__ExplainMake("module is not part of a library", 32);
  isUpToDate = 0u;
  i3=0u;
l23:
  i = 0;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19692))+20);
  i4 = OOC_ARRAY_LENGTH((_check_pointer(i4, 19705)), 0);
  i4 = 0!=i4;
  if (!i4) goto l44;
  i4=i3;i3=0;
l27_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19730))+20);
  i5 = _check_pointer(i5, 19743);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = *(OOC_UINT8*)((i5+((_check_index(i3, i6, OOC_UINT32, 19743))*16))+8);
  i5 = !i5;
  if (!i5) goto l38;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19789))+20);
  i5 = _check_pointer(i5, 19802);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)((i5+((_check_index(i3, i6, OOC_UINT32, 19802))*16))+4);
  i5 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 19775)))), OOC_Make__RulesDesc_Update)),OOC_Make__RulesDesc_Update)((OOC_Make__Rules)i1, (OOC_Repository__Module)i5, 1);
  if (i5) goto l33;
  return 0u;
  
  goto l38;
l33:
  if (i4) goto l35;
  i4=0u;
  goto l36;
l35:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20370))+20);
  i4 = _check_pointer(i4, 20383);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 20383))*16))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 20393))+12);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20302))+20);
  i5 = _check_pointer(i5, 20315);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20229))+20);
  i7 = _check_pointer(i7, 20242);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i4 = *(OOC_INT32*)((_check_pointer(i4, 20400))+68);
  i5 = (OOC_INT32)*(OOC_INT32*)((i5+((_check_index(i3, i6, OOC_UINT32, 20315))*16))+4);
  i6 = *(OOC_INT32*)((i7+((_check_index(i3, i8, OOC_UINT32, 20242))*16))+12);
  i4 = OOC_Make__FingerprintMismatch((OOC_Repository__Module)i0, i6, (OOC_Repository__Module)i5, i4);
  i4 = !i4;
  
l36:
  isUpToDate = i4;
  
l38:
  i3 = i3+1;
  i = i3;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19692))+20);
  i5 = OOC_ARRAY_LENGTH((_check_pointer(i5, 19705)), 0);
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
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 21377)))), OOC_Make__RulesDesc_CompileModule)),OOC_Make__RulesDesc_CompileModule)((OOC_Make__Rules)i1, (OOC_Repository__Module)i0, 0u);
  isUpToDate = i2;
  
  goto l63;
l50:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20914))+12);
  _assert((i4!=(OOC_INT32)0), 127, 20901);
  i4 = OOC_Make__RulesDesc_CheckAllImports((OOC_Make__Rules)i1, (OOC_Repository__Module)i0);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20968))+12);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20944)))), OOC_Repository__ModuleDesc_SetInterfaceData)),OOC_Repository__ModuleDesc_SetInterfaceData)((OOC_Repository__Module)i0, (OOC_SymbolTable__Module)i5, 4, i4);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 21075))+40);
  i4 = i4!=(OOC_INT32)0;
  if (i4) goto l55;
  i2=0u;
l55:
  if (i2) goto l57;
  i2=0u;
  goto l59;
l57:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 21106))+40);
  i2 = OOC_SymbolTable_Uses__UsesDesc_TrackingDeclarations((OOC_SymbolTable_Uses__Uses)i2);
  
l59:
  if (!i2) goto l61;
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 21300)))), OOC_Make__RulesDesc_CompileModule)),OOC_Make__RulesDesc_CompileModule)((OOC_Make__Rules)i1, (OOC_Repository__Module)i0, 1u);
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
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 21543))+40);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21533))+12);
  OOC_SymbolTable_CreateNamespace__CreateNamespace((OOC_SymbolTable__Module)i0, (OOC_SymbolTable_Uses__Uses)i4, (OOC_Error__List)i3);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 21569)))), OOC_Make__RulesDesc_WriteErrList)),OOC_Make__RulesDesc_WriteErrList)((OOC_Make__Rules)i1, (OOC_Error__List)i3);
  i0 = OOC_Error__ListDesc_NoErrors((OOC_Error__List)i3);
  i0 = !i0;
  if (i0) goto l68;
  i0=i2;
  goto l70;
l68:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 21640)))), OOC_Make__RulesDesc_WriteErrList)),OOC_Make__RulesDesc_WriteErrList)((OOC_Make__Rules)i1, (OOC_Error__List)i3);
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

  _assert(0u, 127, 21982);
  _failed_function(21824); return 0;
  ;
}

OOC_CHAR8 OOC_Make__RulesDesc_UpdateInterfaceDescr(OOC_Make__Rules r, OOC_Repository__Module module) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_CHAR8 success;
  OOC_Error__List errList;
  IO__ByteChannel outputChannel;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)module;
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22236)))), OOC_Make__RulesDesc_Update)),OOC_Make__RulesDesc_Update)((OOC_Make__Rules)i0, (OOC_Repository__Module)i1, 1);
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
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22985))+40);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 22975))+12);
  OOC_SymbolTable_CreateNamespace__CreateNamespace((OOC_SymbolTable__Module)i4, (OOC_SymbolTable_Uses__Uses)i3, (OOC_Error__List)i2);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23035))+12);
  OOC_Doc_ResolveRef__Resolve((OOC_SymbolTable__Module)i3, (OOC_Error__List)i2);
  i3 = *(OOC_INT32*)(_check_pointer(i2, 23077));
  _assert((i3==0), 127, 23062);
  i3 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 23133)))), OOC_Repository__ModuleDesc_GetOutputChannel)),OOC_Repository__ModuleDesc_GetOutputChannel)((OOC_Repository__Module)i1, 4, 1u);
  outputChannel = (IO__ByteChannel)i3;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23399))+24);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23338))+12);
  i6 = (OOC_INT32)OOC_Config__repositories;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 23262)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i1, 4, 0u);
  OOC_SymbolTable_InterfaceDescr__Write((IO__ByteChannel)i3, (URI__HierarchicalURI)i1, (OOC_SymbolTable__Module)i5, (OOC_Config_Repositories__Section)i6, (ADT_Dictionary__Dictionary)i4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 23437)))), IO__ChannelDesc_CloseAndRegister)),IO__ChannelDesc_CloseAndRegister)((IO__Channel)i3);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 23476)))), OOC_Make__RulesDesc_WriteErrList)),OOC_Make__RulesDesc_WriteErrList)((OOC_Make__Rules)i0, (OOC_Error__List)i2);
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
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 23886)))), OOC_Make__RulesDesc_Update)),OOC_Make__RulesDesc_Update)((OOC_Make__Rules)i0, (OOC_Repository__Module)i1, 1);
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
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24464))+40);
  i3 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 24447)))), OOC_Make__RulesDesc_LibraryName)),OOC_Make__RulesDesc_LibraryName)((OOC_Make__Rules)i0);
  OOC_Auxiliary_ParseModule__ParseModule((OOC_Repository__Module)i1, 0u, 1u, 0u, 0u, (Object__String)i3, (OOC_SymbolTable_Uses__Uses)i2, (void*)(OOC_INT32)&ast, (void*)(OOC_INT32)&symTab, (void*)(OOC_INT32)&pragmaHistory, (void*)(OOC_INT32)&errList);
  i2 = (OOC_INT32)errList;
  i2 = OOC_Error__ListDesc_NoErrors((OOC_Error__List)i2);
  if (!i2) goto l9;
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 24609)))), OOC_Repository__ModuleDesc_GetOutputChannel)),OOC_Repository__ModuleDesc_GetOutputChannel)((OOC_Repository__Module)i1, 3, 1u);
  outputChannel = (IO__ByteChannel)i2;
  i3 = (OOC_INT32)OOC_Config__repositories;
  i4 = (OOC_INT32)symTab;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 24734)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i1, 3, 0u);
  OOC_SymbolTable_InterfaceXML__Write((IO__ByteChannel)i2, (URI__HierarchicalURI)i1, (OOC_SymbolTable__Module)i4, (OOC_Config_Repositories__Section)i3);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 24853)))), IO__ChannelDesc_CloseAndRegister)),IO__ChannelDesc_CloseAndRegister)((IO__Channel)i2);
l9:
  i1 = (OOC_INT32)errList;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 24897)))), OOC_Make__RulesDesc_WriteErrList)),OOC_Make__RulesDesc_WriteErrList)((OOC_Make__Rules)i0, (OOC_Error__List)i1);
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
      _failed_function(25279); return 0;
      ;
    }


  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)module;
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 25920)))), OOC_Make__RulesDesc_Update)),OOC_Make__RulesDesc_Update)((OOC_Make__Rules)i0, (OOC_Repository__Module)i1, 4);
  success = i0;
  if (!i0) goto l8;
  i2 = OOC_Make__DerivedIsOlder((OOC_Repository__Module)i1, 5, 4);
  if (!i2) goto l8;
  exit = 0;
  i0 = (OOC_INT32)OOC_Config__xsltproc;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26164))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26164))+8);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 26170)))), Config__VariableDesc_ToString)),Config__VariableDesc_ToString)((Config__Variable)i0);
  i0 = (OOC_INT32)ADT_StringBuffer__New((Object__String)i0);
  sb = (ADT_StringBuffer__StringBuffer)i0;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 26263)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c0));
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 26301)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i1, 5, 1u);
  uri = (URI__URI)i1;
  i1 = (OOC_INT32)URI_Scheme_File__URIDesc_GetPath((URI_Scheme_File__URI)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 26365)))), &_td_URI_Scheme_File__URIDesc, 26365)));
  path = (Object__String)i1;
  i2 = (OOC_INT32)OS_Path__QuoteForShell((Object__String)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 26391)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i2);
  i0 = (OOC_INT32)OS_Path__DirName((Object__String)i1);
  OS_Files__MakeDirs((Object__String)i0, 511);
  i0 = (OOC_INT32)OOC_Config__repositories;
  i0 = (OOC_INT32)OOC_Make__RulesDesc_UpdateInterfaceHTML_GetSystemId((OOC_Config_Repositories__Section)i0);
  uri = (URI__URI)i0;
  i1 = (OOC_INT32)sb;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 26677)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i1, (Object__Object)((OOC_INT32)_c1));
  i0 = (OOC_INT32)URI_Scheme_File__URIDesc_GetPath((URI_Scheme_File__URI)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 26737)))), &_td_URI_Scheme_File__URIDesc, 26737)));
  i0 = (OOC_INT32)OS_Path__QuoteForShell((Object__String)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 26701)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i1, (Object__Object)i0);
  i0 = (OOC_INT32)module;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 26823)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i0, 4, 1u);
  uri = (URI__URI)i0;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 26873)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i1, (Object__Object)((OOC_INT32)_c2));
  i0 = (OOC_INT32)URI_Scheme_File__URIDesc_GetPath((URI_Scheme_File__URI)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 26933)))), &_td_URI_Scheme_File__URIDesc, 26933)));
  i0 = (OOC_INT32)OS_Path__QuoteForShell((Object__String)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 26897)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i1, (Object__Object)i0);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 26977)))), ADT_StringBuffer__StringBufferDesc_ToString)),ADT_StringBuffer__StringBufferDesc_ToString)((ADT_StringBuffer__StringBuffer)i1);
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
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 27409))+36);
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
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 27507)))), OOC_Make__RulesDesc_CompileModule)),OOC_Make__RulesDesc_CompileModule)((OOC_Make__Rules)i1, (OOC_Repository__Module)i0, 0u);
  return i0;
l12:
  _failed_function(27213); return 0;
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
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28135))+20);
  i = 0;
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 28148)), 0);
  i3 = 0<i2;
  if (!i3) goto l18;
  i3=0;
l6_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28174))+20);
  i4 = _check_pointer(i4, 28187);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = *(OOC_UINT8*)((i4+((_check_index(i3, i5, OOC_UINT32, 28187))*16))+8);
  i4 = !i4;
  if (i4) goto l9;
  i4=0u;
  goto l11;
l9:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28229))+20);
  i4 = _check_pointer(i4, 28242);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((i4+((_check_index(i3, i5, OOC_UINT32, 28242))*16))+4);
  i4 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 28215)))), OOC_Make__RulesDesc_Update)),OOC_Make__RulesDesc_Update)((OOC_Make__Rules)i1, (OOC_Repository__Module)i4, 13);
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
  _failed_function(27686); return 0;
  ;
}

OOC_CHAR8 OOC_Make__RulesDesc_UpdateDeclFileC(OOC_Make__Rules r, OOC_Repository__Module module) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)module;
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 28568)))), OOC_Make__RulesDesc_Update)),OOC_Make__RulesDesc_Update)((OOC_Make__Rules)i0, (OOC_Repository__Module)i1, 13);
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
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 28788)))), OOC_Make__RulesDesc_Update)),OOC_Make__RulesDesc_Update)((OOC_Make__Rules)i0, (OOC_Repository__Module)i1, 12);
  if (i2) goto l3;
  return 0u;
  goto l12;
l3:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 28843))+12);
  i2 = *(OOC_INT8*)((_check_pointer(i2, 28850))+52);
  i2 = i2==2;
  if (i2) goto l6;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 28893))+12);
  i2 = *(OOC_INT8*)((_check_pointer(i2, 28900))+52);
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
  _failed_function(28710); return 0;
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
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29310))+12);
  i2 = *(OOC_INT8*)((_check_pointer(i2, 29317))+52);
  i2 = i2==2;
  if (i2) goto l6;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29360))+12);
  i2 = *(OOC_INT8*)((_check_pointer(i2, 29367))+52);
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
  _failed_function(29187); return 0;
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
  i2 = OOC_Make__RulesDesc_SelectBackend((OOC_Make__Rules)i0, (OOC_Repository__Module)i1);
  i2 = i2==2;
  if (i2) goto l26;
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 31237)))), OOC_Make__RulesDesc_Update)),OOC_Make__RulesDesc_Update)((OOC_Make__Rules)i0, (OOC_Repository__Module)i1, 11);
  success = i0;
  if (i0) goto l16;
  i2=0u;
  goto l18;
l16:
  i2 = OOC_Config_CCompiler__SkipCallCC();
  i2 = !i2;
  
l18:
  if (i2) goto l20;
  i2=0u;
  goto l22;
l20:
  i2 = OOC_Make__DerivedIsOlder((OOC_Repository__Module)i1, 7, 11);
  
l22:
  if (!i2) goto l31;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 31405)))), OOC_Repository__ModuleDesc_CreateOutputDir)),OOC_Repository__ModuleDesc_CreateOutputDir)((OOC_Repository__Module)i1, 7);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 31568)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i1, 7, 1u);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 31489)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i1, 11, 1u);
  i0 = (OOC_INT32)OOC_Config_CCompiler__CompileFileCmd((URI__URI)i1, (URI__URI)i0, 0u);
  OOC_Logger__ShellCommand((Object__String)i0);
  i0 = OS_ProcessManagement__system((Object__String)i0);
  i0 = i0==0;
  
  goto l31;
l26:
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 30773)))), OOC_Make__RulesDesc_Update)),OOC_Make__RulesDesc_Update)((OOC_Make__Rules)i0, (OOC_Repository__Module)i1, 14);
  success = i0;
  i2 = OOC_Make__DerivedIsOlder((OOC_Repository__Module)i1, 7, 14);
  if (!i2) goto l31;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 30904)))), OOC_Repository__ModuleDesc_CreateOutputDir)),OOC_Repository__ModuleDesc_CreateOutputDir)((OOC_Repository__Module)i1, 7);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 31066)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i1, 7, 1u);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 30989)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i1, 14, 1u);
  i0 = (OOC_INT32)OOC_Config_Assembler__AssembleFileCmd((URI__URI)i1, (URI__URI)i0);
  OOC_Logger__ShellCommand((Object__String)i0);
  i0 = OS_ProcessManagement__system((Object__String)i0);
  i0 = i0==0;
  
l31:
  return i0;
  ;
}

OOC_CHAR8 OOC_Make__RulesDesc_UpdateObjectFileLib(OOC_Make__Rules r, OOC_Repository__Module module) {
  register OOC_INT32 i0,i1,i2;
  OOC_CHAR8 success;
  URI__URI outputFile;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)module;
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32175)))), OOC_Make__RulesDesc_Update)),OOC_Make__RulesDesc_Update)((OOC_Make__Rules)i0, (OOC_Repository__Module)i1, 11);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 32330)))), OOC_Repository__ModuleDesc_CreateOutputDir)),OOC_Repository__ModuleDesc_CreateOutputDir)((OOC_Repository__Module)i1, 7);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 32394)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i1, 8, 1u);
  outputFile = (URI__URI)i0;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 32552)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i1, 8, 1u);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 32475)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i1, 11, 1u);
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
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33305)))), OOC_Make__RulesDesc_Update)),OOC_Make__RulesDesc_Update)((OOC_Make__Rules)i0, (OOC_Repository__Module)i1, 1);
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
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33495))+16);
  i4 = OOC_ARRAY_LENGTH((_check_pointer(i4, 33503)), 0);
  i4 = 0!=i4;
  
l8:
  if (!i4) goto l24;
  i4=i3;i3=0;
l11_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33591))+16);
  i5 = _check_pointer(i5, 33599);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i3, i6, OOC_UINT32, 33599))*4);
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
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33495))+16);
  i5 = OOC_ARRAY_LENGTH((_check_pointer(i5, 33503)), 0);
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
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33774))+16);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33774))+16);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 33782)), 0);
  OOC_Make_WriteMainFileC__WriteFile((OOC_Repository__Module)i1, (void*)(_check_pointer(i0, 33782)), i2);
  i0=1u;
l29:
  return i0;
  ;
}

OOC_CHAR8 OOC_Make__RulesDesc_UpdateMainFileX86(OOC_Make__Rules r, OOC_Repository__Module module) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_CHAR8 success;
  OOC_CHAR8 isUpToDate;
  OOC_INT32 i;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)module;
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34098)))), OOC_Make__RulesDesc_Update)),OOC_Make__RulesDesc_Update)((OOC_Make__Rules)i0, (OOC_Repository__Module)i1, 1);
  success = i2;
  if (!i2) goto l27;
  i3 = OOC_Make__Exists((OOC_Repository__Module)i1, 16);
  isUpToDate = i3;
  i = 0;
  if (i3) goto l5;
  i4=0u;
  goto l7;
l5:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34296))+16);
  i4 = OOC_ARRAY_LENGTH((_check_pointer(i4, 34304)), 0);
  i4 = 0!=i4;
  
l7:
  if (!i4) goto l23;
  i4=i3;i3=0;
l10_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34400))+16);
  i5 = _check_pointer(i5, 34408);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i3, i6, OOC_UINT32, 34408))*4);
  i3 = i3+1;
  i5 = OOC_Make__DerivedIsOlder2((OOC_Repository__Module)i1, 16, (OOC_Repository__Module)i5, 1);
  if (!i5) goto l14;
  isUpToDate = 0u;
  i4=0u;
l14:
  i = i3;
  if (i4) goto l17;
  i5=0u;
  goto l19;
l17:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34296))+16);
  i5 = OOC_ARRAY_LENGTH((_check_pointer(i5, 34304)), 0);
  i5 = i3!=i5;
  
l19:
  if (i5) goto l10_loop;
l22:
  i3=i4;
l23:
  i3 = !i3;
  if (!i3) goto l27;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34591))+16);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34591))+16);
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 34599)), 0);
  OOC_Make_WriteMainFileAssembler__WriteFile((OOC_Repository__Module)i1, (void*)(_check_pointer(i0, 34599)), i3);
l27:
  return i2;
  ;
}

OOC_CHAR8 OOC_Make__RulesDesc_UpdateMainObjectFile(OOC_Make__Rules r, OOC_Repository__Module module) {
  register OOC_INT32 i0,i1,i2;
  OOC_CHAR8 success;

  i0 = (OOC_INT32)r;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 35037));
  i1 = i1==2;
  if (i1) goto l11;
  i1 = (OOC_INT32)module;
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 35599)))), OOC_Make__RulesDesc_Update)),OOC_Make__RulesDesc_Update)((OOC_Make__Rules)i0, (OOC_Repository__Module)i1, 15);
  success = i0;
  i2 = OOC_Config_CCompiler__SkipCallCC();
  i2 = !i2;
  if (i2) goto l5;
  i2=0u;
  goto l7;
l5:
  i2 = OOC_Make__DerivedIsOlder((OOC_Repository__Module)i1, 17, 15);
  
l7:
  if (!i2) goto l16;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 35761)))), OOC_Repository__ModuleDesc_CreateOutputDir)),OOC_Repository__ModuleDesc_CreateOutputDir)((OOC_Repository__Module)i1, 17);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 35928)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i1, 17, 1u);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 35849)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i1, 15, 1u);
  i0 = (OOC_INT32)OOC_Config_CCompiler__CompileFileCmd((URI__URI)i1, (URI__URI)i0, 0u);
  OOC_Logger__ShellCommand((Object__String)i0);
  i0 = OS_ProcessManagement__system((Object__String)i0);
  i0 = i0==0;
  
  goto l16;
l11:
  i1 = (OOC_INT32)module;
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 35088)))), OOC_Make__RulesDesc_Update)),OOC_Make__RulesDesc_Update)((OOC_Make__Rules)i0, (OOC_Repository__Module)i1, 16);
  success = i0;
  i2 = OOC_Make__DerivedIsOlder((OOC_Repository__Module)i1, 17, 16);
  if (!i2) goto l16;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 35255)))), OOC_Repository__ModuleDesc_CreateOutputDir)),OOC_Repository__ModuleDesc_CreateOutputDir)((OOC_Repository__Module)i1, 17);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 35425)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i1, 17, 1u);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 35344)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i1, 16, 1u);
  i0 = (OOC_INT32)OOC_Config_Assembler__AssembleFileCmd((URI__URI)i1, (URI__URI)i0);
  OOC_Logger__ShellCommand((Object__String)i0);
  i0 = OS_ProcessManagement__system((Object__String)i0);
  i0 = i0==0;
  
l16:
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
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36526))+20);
      i = 0;
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 36539)), 0);
      i2 = 0<i1;
      if (!i2) goto l13;
      i2=0;
l5_loop:
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36567))+20);
      i3 = _check_pointer(i3, 36580);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = *(OOC_UINT8*)((i3+((_check_index(i2, i4, OOC_UINT32, 36580))*16))+8);
      i3 = !i3;
      if (!i3) goto l8;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36623))+20);
      i3 = _check_pointer(i3, 36636);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)((i3+((_check_index(i2, i4, OOC_UINT32, 36636))*16))+4);
      _assert((i3!=(OOC_INT32)0), 127, 36610);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36681))+20);
      i3 = _check_pointer(i3, 36694);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)((i3+((_check_index(i2, i4, OOC_UINT32, 36694))*16))+4);
      OOC_Make__ModuleClosure_Closure((OOC_Repository__Module)i3);
l8:
      i2 = i2+1;
      i = i2;
      i3 = i2<i1;
      if (i3) goto l5_loop;
l13:
      i1 = (OOC_INT32)list;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 36748)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i1, (Object__Object)i0);
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
  i1 = *(OOC_INT32*)((_check_pointer(i0, 36945))+4);
  i1 = (OOC_INT32)RT0__NewObject(_td_OOC_Make__ModuleList.baseTypes[0], i1);
  a = (OOC_Make__ModuleList)i1;
  i = 0;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 36975))+4);
  i3 = 0<i2;
  if (!i3) goto l8;
  i3=0;
l3_loop:
  i4 = _check_pointer(i1, 36993);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 37004));
  i6 = _check_pointer(i6, 37010);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i3, i7, OOC_UINT32, 37010))*4);
  *(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 36993))*4) = (_type_guard(i6, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 37018)))), &_td_OOC_Repository__ModuleDesc, 37018));
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
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 37762))+20);
      i = 0;
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 37775)), 0);
      i2 = 0<i1;
      if (!i2) goto l13;
      i2=0;
l5_loop:
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 37803))+20);
      i3 = _check_pointer(i3, 37816);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = *(OOC_UINT8*)((i3+((_check_index(i2, i4, OOC_UINT32, 37816))*16))+8);
      i3 = !i3;
      if (!i3) goto l8;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 37859))+20);
      i3 = _check_pointer(i3, 37872);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)((i3+((_check_index(i2, i4, OOC_UINT32, 37872))*16))+4);
      _assert((i3!=(OOC_INT32)0), 127, 37846);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 37917))+20);
      i3 = _check_pointer(i3, 37930);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)((i3+((_check_index(i2, i4, OOC_UINT32, 37930))*16))+4);
      OOC_Make__RulesDesc_UpdateExecutable_Closure((OOC_Repository__Module)i3);
l8:
      i2 = i2+1;
      i = i2;
      i3 = i2<i1;
      if (i3) goto l5_loop;
l13:
      i1 = (OOC_INT32)list;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 37984)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i1, (Object__Object)i0);
l14:
      return;
      ;
    }


  success = 0u;
  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)module;
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 38114)))), OOC_Make__RulesDesc_Update)),OOC_Make__RulesDesc_Update)((OOC_Make__Rules)i0, (OOC_Repository__Module)i1, 1);
  if (i2) goto l3;
  i0=0u;
  goto l48;
l3:
  i2 = (OOC_INT32)OOC_Make__ModuleClosure((OOC_Repository__Module)i1);
  *(OOC_INT32*)((_check_pointer(i0, 38402))+16) = i2;
  isUpToDate = 1u;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 38495))+16);
  i = 0;
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 38503)), 0);
  i3 = 0<i2;
  if (i3) goto l6;
  i2=1u;
  goto l32;
l6:
  i3=0;i4=1u;
l7_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 38524))+16);
  i5 = _check_pointer(i5, 38532);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i3, i6, OOC_UINT32, 38532))*4);
  i5 = *(OOC_INT8*)((_check_pointer(i5, 38535))+16);
  i5 = i5==4;
  if (i5) goto l10;
  i5=0u;
  goto l12;
l10:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 38586))+16);
  i5 = _check_pointer(i5, 38594);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i3, i6, OOC_UINT32, 38594))*4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 38597))+12);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 38604))+56);
  i5 = i5!=(OOC_INT32)0;
  
l12:
  if (i5) goto l27;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 38782))+16);
  i5 = _check_pointer(i5, 38790);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i3, i6, OOC_UINT32, 38790))*4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 38793))+12);
  i5 = OOC_SymbolTable__ModuleDesc_NoObjectFile((OOC_SymbolTable__Module)i5);
  if (i5) goto l27;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 38913))+16);
  i5 = _check_pointer(i5, 38921);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i3, i6, OOC_UINT32, 38921))*4);
  i5 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 38904)))), OOC_Make__RulesDesc_Update)),OOC_Make__RulesDesc_Update)((OOC_Make__Rules)i0, (OOC_Repository__Module)i5, 7);
  i5 = !i5;
  if (i5) goto l22;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 39062))+16);
  i5 = _check_pointer(i5, 39070);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i3, i6, OOC_UINT32, 39070))*4);
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
  i3 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 39172)))), OOC_Make__RulesDesc_Update)),OOC_Make__RulesDesc_Update)((OOC_Make__Rules)i0, (OOC_Repository__Module)i1, 17);
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
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 39552))+16);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 39552))+16);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 39560)), 0);
  i0 = OOC_Make_LinkProgramC__Run((OOC_Repository__Module)i1, (void*)(_check_pointer(i0, 39560)), i2, (OOC_Package__Library)(OOC_INT32)0);
  
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
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 40306));
  *(OOC_INT32*)((_check_pointer(i0, 40280))+12) = i2;
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 40514)))), OOC_Make__RulesDesc_Update)),OOC_Make__RulesDesc_Update)((OOC_Make__Rules)i0, (OOC_Repository__Module)i1, 1);
  success = i2;
  if (i2) goto l3;
  i0=i2;
  goto l40;
l3:
  i3 = (OOC_INT32)OOC_Make__ModuleClosure((OOC_Repository__Module)i1);
  closure = (OOC_Make__ModuleList)i3;
  *(OOC_INT32*)((_check_pointer(i0, 40617))+16) = i3;
  i4 = OOC_Make__Exists((OOC_Repository__Module)i1, 19);
  isUpToDate = i4;
  i = 0;
  i5 = OOC_ARRAY_LENGTH((_check_pointer(i3, 40783)), 0);
  i6 = 0<i5;
  if (!i6) goto l32;
  i6=i4;i4=0;
l7_loop:
  i7 = _check_pointer(i3, 40823);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)(i7+(_check_index(i4, i8, OOC_UINT32, 40823))*4);
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i7, 40826))+12);
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i7, 40833))+56);
  importLibrary = (Object__String)i7;
  i8 = i7!=0;
  if (i8) goto l10;
  i7=0u;
  goto l12;
l10:
  i8 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 40905)))), OOC_Make__RulesDesc_LibraryName)),OOC_Make__RulesDesc_LibraryName)((OOC_Make__Rules)i0);
  i7 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 40896)))), Object__StringDesc_Equals)),Object__StringDesc_Equals)((Object__String)i7, (Object__Object)i8);
  i7 = !i7;
  
l12:
  if (i7) goto l27;
  i7 = _check_pointer(i3, 40996);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)(i7+(_check_index(i4, i8, OOC_UINT32, 40996))*4);
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i7, 40999))+12);
  i7 = OOC_SymbolTable__ModuleDesc_NoObjectFile((OOC_SymbolTable__Module)i7);
  if (i7) goto l27;
  i7 = _check_pointer(i3, 41079);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)(i7+(_check_index(i4, i8, OOC_UINT32, 41079))*4);
  i7 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 41064)))), OOC_Make__RulesDesc_Update)),OOC_Make__RulesDesc_Update)((OOC_Make__Rules)i0, (OOC_Repository__Module)i7, 8);
  i7 = !i7;
  if (i7) goto l22;
  i7 = _check_pointer(i3, 41226);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)(i7+(_check_index(i4, i8, OOC_UINT32, 41226))*4);
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
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 41732))+4);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i3, 41728)), 0);
  i0 = OOC_Make_LinkProgramC__Run((OOC_Repository__Module)i1, (void*)(_check_pointer(i3, 41728)), i2, (OOC_Package__Library)i0);
  
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
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 42098)))), OOC_Make__RulesDesc_GetModuleInfo)),OOC_Make__RulesDesc_GetModuleInfo)((OOC_Make__Rules)i0, (OOC_Repository__Module)i1);
  mInfo = (OOC_Make__ModuleInfo)i2;
  i3 = fileId;
  i4 = *(OOC_UINT8*)((_check_pointer(i2, 42134))+(_check_index(i3, 22, OOC_UINT8, 42142)));
  if (i4) goto l26;
  i4 = *(OOC_UINT32*)((_check_pointer(i1, 42309))+24);
  i4 = _in(i3,i4);
  if (i4) goto l24;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 42491))+4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 42491))+4);
  i4 = OOC_ARRAY_LENGTH((_check_pointer(i4, 42496)), 0);
  OOC_Logger__EnterMake((void*)(_check_pointer(i5, 42496)), i4, (void*)((OOC_INT32)OOC_Make__fileIdNames+((_check_index(i3, 22, OOC_UINT8, 42510))*24)), 24);
  i4 = *(OOC_UINT32*)((_check_pointer(i1, 42538))+24);
  *(OOC_UINT32*)((_check_pointer(i1, 42538))+24) = (_set_bit(i4,i3));
  switch (i3) {
  case 18:
    i0 = OOC_Make__RulesDesc_UpdateExecutable((OOC_Make__Rules)i0, (OOC_Repository__Module)i1);
    res = i0;
    goto l23;
  case 19:
    i0 = OOC_Make__RulesDesc_UpdateLibrary((OOC_Make__Rules)i0, (OOC_Repository__Module)i1);
    res = i0;
    goto l23;
  case 17:
    i0 = OOC_Make__RulesDesc_UpdateMainObjectFile((OOC_Make__Rules)i0, (OOC_Repository__Module)i1);
    res = i0;
    goto l23;
  case 15:
    i0 = OOC_Make__RulesDesc_UpdateMainFileC((OOC_Make__Rules)i0, (OOC_Repository__Module)i1);
    res = i0;
    goto l23;
  case 16:
    i0 = OOC_Make__RulesDesc_UpdateMainFileX86((OOC_Make__Rules)i0, (OOC_Repository__Module)i1);
    res = i0;
    goto l23;
  case 7:
    i0 = OOC_Make__RulesDesc_UpdateObjectFile((OOC_Make__Rules)i0, (OOC_Repository__Module)i1);
    res = i0;
    goto l23;
  case 8:
    i0 = OOC_Make__RulesDesc_UpdateObjectFileLib((OOC_Make__Rules)i0, (OOC_Repository__Module)i1);
    res = i0;
    goto l23;
  case 11:
    i0 = OOC_Make__RulesDesc_UpdateCodeFileC((OOC_Make__Rules)i0, (OOC_Repository__Module)i1);
    res = i0;
    goto l23;
  case 12:
    i0 = OOC_Make__RulesDesc_UpdateDeclFileC((OOC_Make__Rules)i0, (OOC_Repository__Module)i1);
    res = i0;
    goto l23;
  case 13:
    i0 = OOC_Make__RulesDesc_UpdateHeaderFileC((OOC_Make__Rules)i0, (OOC_Repository__Module)i1);
    res = i0;
    goto l23;
  case 14:
    i0 = OOC_Make__RulesDesc_UpdateAssemblerFile((OOC_Make__Rules)i0, (OOC_Repository__Module)i1);
    res = i0;
    goto l23;
  case 4:
    i0 = OOC_Make__RulesDesc_UpdateInterfaceDescr((OOC_Make__Rules)i0, (OOC_Repository__Module)i1);
    res = i0;
    goto l23;
  case 3:
    i0 = OOC_Make__RulesDesc_UpdateInterfaceXML((OOC_Make__Rules)i0, (OOC_Repository__Module)i1);
    res = i0;
    goto l23;
  case 5:
    i0 = OOC_Make__RulesDesc_UpdateInterfaceHTML((OOC_Make__Rules)i0, (OOC_Repository__Module)i1);
    res = i0;
    goto l23;
  case 2:
    i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 43647)))), OOC_Make__RulesDesc_UpdateSymbolTableXML)),OOC_Make__RulesDesc_UpdateSymbolTableXML)((OOC_Make__Rules)i0, (OOC_Repository__Module)i1);
    res = i0;
    goto l23;
  case 1:
    i0 = OOC_Make__RulesDesc_UpdateSymbolFile((OOC_Make__Rules)i0, (OOC_Repository__Module)i1);
    res = i0;
    goto l23;
  default:
    _failed_case(i3, 42569);
    goto l23;
  }
l23:
  *(OOC_UINT8*)((_check_pointer(i2, 43770))+(_check_index(i3, 22, OOC_UINT8, 43778))) = 1u;
  i0 = res;
  *(OOC_UINT8*)(((_check_pointer(i2, 43807))+22)+(_check_index(i3, 22, OOC_UINT8, 43820))) = i0;
  i2 = *(OOC_UINT32*)((_check_pointer(i1, 43854))+24);
  *(OOC_UINT32*)((_check_pointer(i1, 43854))+24) = (_clear_bit(i2,i3));
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 43914))+4);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 43914))+4);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 43919)), 0);
  i0 = OOC_Logger__ExitMake((void*)(_check_pointer(i1, 43919)), i2, (void*)((OOC_INT32)OOC_Make__fileIdNames+((_check_index(i3, 22, OOC_UINT8, 43933))*24)), 24, i0);
  return i0;
  goto l27;
l24:
  Out__String("Error: Cyclic dependency in module ", 36);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 42410))+4);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 42410))+4);
  i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 42415)), 0);
  Out__String((void*)(_check_pointer(i1, 42415)), i0);
  Out__Ln();
  return 0u;
  goto l27;
l26:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 42245))+4);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 42245))+4);
  i2 = *(OOC_UINT8*)(((_check_pointer(i2, 42258))+22)+(_check_index(i3, 22, OOC_UINT8, 42271)));
  i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 42250)), 0);
  i0 = OOC_Logger__CachedMake((void*)((OOC_INT32)OOC_Make__fileIdNames+((_check_index(i3, 22, OOC_UINT8, 42198))*24)), 24, (void*)(_check_pointer(i1, 42250)), i0, i2);
  return i0;
l27:
  _failed_function(41955); return 0;
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
  _copy_8((const void*)"Executable",(void*)((OOC_INT32)OOC_Make__fileIdNames+((_check_index(18, 22, OOC_UINT8, 44157))*24)),24);
  _copy_8((const void*)"Library",(void*)((OOC_INT32)OOC_Make__fileIdNames+((_check_index(19, 22, OOC_UINT8, 44207))*24)),24);
  _copy_8((const void*)"MainObjectFile",(void*)((OOC_INT32)OOC_Make__fileIdNames+((_check_index(17, 22, OOC_UINT8, 44251))*24)),24);
  _copy_8((const void*)"MainFileC",(void*)((OOC_INT32)OOC_Make__fileIdNames+((_check_index(15, 22, OOC_UINT8, 44309))*24)),24);
  _copy_8((const void*)"ObjectFile",(void*)((OOC_INT32)OOC_Make__fileIdNames+((_check_index(7, 22, OOC_UINT8, 44357))*24)),24);
  _copy_8((const void*)"ObjectFileLib",(void*)((OOC_INT32)OOC_Make__fileIdNames+((_check_index(8, 22, OOC_UINT8, 44407))*24)),24);
  _copy_8((const void*)"CodeFileC",(void*)((OOC_INT32)OOC_Make__fileIdNames+((_check_index(11, 22, OOC_UINT8, 44463))*24)),24);
  _copy_8((const void*)"DeclFileC",(void*)((OOC_INT32)OOC_Make__fileIdNames+((_check_index(12, 22, OOC_UINT8, 44511))*24)),24);
  _copy_8((const void*)"HeaderFileC",(void*)((OOC_INT32)OOC_Make__fileIdNames+((_check_index(13, 22, OOC_UINT8, 44559))*24)),24);
  _copy_8((const void*)"InterfaceDescr",(void*)((OOC_INT32)OOC_Make__fileIdNames+((_check_index(4, 22, OOC_UINT8, 44611))*24)),24);
  _copy_8((const void*)"InterfaceXML",(void*)((OOC_INT32)OOC_Make__fileIdNames+((_check_index(3, 22, OOC_UINT8, 44669))*24)),24);
  _copy_8((const void*)"InterfaceHTML",(void*)((OOC_INT32)OOC_Make__fileIdNames+((_check_index(5, 22, OOC_UINT8, 44723))*24)),24);
  _copy_8((const void*)"SymbolFile",(void*)((OOC_INT32)OOC_Make__fileIdNames+((_check_index(1, 22, OOC_UINT8, 44779))*24)),24);
  _copy_8((const void*)"SymbolTableXML",(void*)((OOC_INT32)OOC_Make__fileIdNames+((_check_index(2, 22, OOC_UINT8, 44829))*24)),24);
  _copy_8((const void*)"AssemblerFile",(void*)((OOC_INT32)OOC_Make__fileIdNames+((_check_index(14, 22, OOC_UINT8, 44887))*24)),24);
  _copy_8((const void*)"MainFileAssembler",(void*)((OOC_INT32)OOC_Make__fileIdNames+((_check_index(16, 22, OOC_UINT8, 44943))*24)),24);
  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Make__ErrorContext.baseTypes[0]);
  OOC_Make__makeContext = (OOC_Make__ErrorContext)i0;
  OOC_Error__InitContext((OOC_Error__Context)i0, "OOC:Make", 9);
  return;
  ;
}

/* --- */
