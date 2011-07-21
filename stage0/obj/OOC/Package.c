#include <OOC/Package.d>
#include <__oo2c.h>
#include <setjmp.h>

void OOC_Package__ErrorContextDesc_GetTemplate(OOC_Package__ErrorContext context, Msg__Msg msg, Msg__LString templ, OOC_LEN templ_0d) {
  register OOC_INT32 i0,i1;
  OOC_CHAR16 t[128];

  i0 = (OOC_INT32)msg;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 3041))+8);
  switch (i1) {
  case 0:
    _copy_16((const void*)((OOC_CHAR16[]){73,110,118,97,108,105,100,32,99,111,110,116,101,110,116,32,102,111,114,32,101,108,101,109,101,110,116,32,96,36,123,110,97,109,101,125,39,0}),(void*)(OOC_INT32)t,128);
    goto l21;
  case 1:
    _copy_16((const void*)((OOC_CHAR16[]){78,97,109,101,32,111,102,32,114,111,111,116,32,101,108,101,109,101,110,116,32,109,117,115,116,32,98,101,32,96,36,123,110,97,109,101,125,39,0}),(void*)(OOC_INT32)t,128);
    goto l21;
  case 2:
    _copy_16((const void*)((OOC_CHAR16[]){79,110,108,121,32,119,104,105,116,101,115,112,97,99,101,32,99,104,97,114,97,99,116,101,114,32,100,97,116,97,32,97,108,108,111,119,101,100,32,104,101,114,101,0}),(void*)(OOC_INT32)t,128);
    goto l21;
  case 3:
    _copy_16((const void*)((OOC_CHAR16[]){65,116,116,114,105,98,117,116,101,32,96,36,123,110,97,109,101,125,39,32,105,115,32,110,111,116,32,100,101,102,105,110,101,100,32,102,111,114,32,116,104,105,115,32,101,108,101,109,101,110,116,0}),(void*)(OOC_INT32)t,128);
    goto l21;
  case 4:
    _copy_16((const void*)((OOC_CHAR16[]){74,117,110,107,32,97,116,32,101,110,100,32,111,102,32,101,108,101,109,101,110,116,0}),(void*)(OOC_INT32)t,128);
    goto l21;
  case 5:
    _copy_16((const void*)((OOC_CHAR16[]){84,104,105,115,32,101,108,101,109,101,110,116,32,114,101,113,117,105,114,101,115,32,97,110,32,97,116,116,114,105,98,117,116,101,32,96,110,97,109,101,39,0}),(void*)(OOC_INT32)t,128);
    goto l21;
  case 6:
    _copy_16((const void*)((OOC_CHAR16[]){69,120,112,101,99,116,101,100,32,99,104,105,108,100,32,101,108,101,109,101,110,116,32,96,118,101,114,115,105,111,110,39,0}),(void*)(OOC_INT32)t,128);
    goto l21;
  case 7:
    _copy_16((const void*)((OOC_CHAR16[]){84,104,105,115,32,101,108,101,109,101,110,116,32,114,101,113,117,105,114,101,115,32,97,110,32,97,116,116,114,105,98,117,116,101,32,96,99,117,114,114,101,110,116,39,0}),(void*)(OOC_INT32)t,128);
    goto l21;
  case 8:
    _copy_16((const void*)((OOC_CHAR16[]){84,104,105,115,32,101,108,101,109,101,110,116,32,114,101,113,117,105,114,101,115,32,97,110,32,97,116,116,114,105,98,117,116,101,32,96,114,101,118,105,115,105,111,110,39,0}),(void*)(OOC_INT32)t,128);
    goto l21;
  case 9:
    _copy_16((const void*)((OOC_CHAR16[]){84,104,105,115,32,101,108,101,109,101,110,116,32,114,101,113,117,105,114,101,115,32,97,110,32,97,116,116,114,105,98,117,116,101,32,96,109,97,105,110,45,109,111,100,117,108,101,39,0}),(void*)(OOC_INT32)t,128);
    goto l21;
  case 10:
    _copy_16((const void*)((OOC_CHAR16[]){84,104,105,115,32,101,108,101,109,101,110,116,32,114,101,113,117,105,114,101,115,32,97,110,32,97,116,116,114,105,98,117,116,101,32,96,115,111,117,114,99,101,45,100,105,114,39,0}),(void*)(OOC_INT32)t,128);
    goto l21;
  case 11:
    _copy_16((const void*)((OOC_CHAR16[]){84,104,105,115,32,101,108,101,109,101,110,116,32,114,101,113,117,105,114,101,115,32,97,110,32,97,116,116,114,105,98,117,116,101,32,96,116,121,112,101,39,0}),(void*)(OOC_INT32)t,128);
    goto l21;
  case 12:
    _copy_16((const void*)((OOC_CHAR16[]){69,120,112,101,99,116,101,100,32,99,104,105,108,100,32,101,108,101,109,101,110,116,32,96,102,105,108,101,39,32,111,114,32,96,102,105,108,101,45,115,101,116,39,0}),(void*)(OOC_INT32)t,128);
    goto l21;
  case 13:
    _copy_16((const void*)((OOC_CHAR16[]){69,120,112,101,99,116,101,100,32,99,104,105,108,100,32,101,108,101,109,101,110,116,32,96,100,101,102,105,110,101,39,0}),(void*)(OOC_INT32)t,128);
    goto l21;
  case 14:
    _copy_16((const void*)((OOC_CHAR16[]){65,116,116,114,105,98,117,116,101,32,96,36,123,110,97,109,101,125,39,32,109,117,115,116,32,98,101,32,97,110,32,117,110,115,105,103,110,101,100,32,105,110,116,101,103,101,114,0}),(void*)(OOC_INT32)t,128);
    goto l21;
  case 15:
    _copy_16((const void*)((OOC_CHAR16[]){79,110,108,121,32,99,104,97,114,97,99,116,101,114,32,100,97,116,97,32,97,108,108,111,119,101,100,32,104,101,114,101,0}),(void*)(OOC_INT32)t,128);
    goto l21;
  case 16:
    _copy_16((const void*)((OOC_CHAR16[]){84,121,112,101,32,96,36,123,116,121,112,101,125,39,32,105,115,32,110,111,116,32,115,117,112,112,111,114,116,101,100,32,102,111,114,32,116,104,105,115,32,118,97,114,105,97,98,108,101,0}),(void*)(OOC_INT32)t,128);
    goto l21;
  case 17:
    _copy_16((const void*)((OOC_CHAR16[]){73,110,118,97,108,105,100,32,118,97,108,117,101,58,32,36,123,114,101,97,115,111,110,125,0}),(void*)(OOC_INT32)t,128);
    goto l21;
  default:
    _failed_case(i1, 3033);
    goto l21;
  }
l21:
  i1 = (OOC_INT32)context;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4511)))), XML_Error__ContextDesc_WriteTemplate)),XML_Error__ContextDesc_WriteTemplate)((XML_Error__Context)i1, (Msg__Msg)i0, (void*)(OOC_INT32)t, 128, (void*)(OOC_INT32)templ, templ_0d);
  return;
  ;
}

static OOC_Package__Version OOC_Package__NewVersion(void) {
  register OOC_INT32 i0;
  OOC_Package__Version version;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Package__Version.baseTypes[0]);
  version = (OOC_Package__Version)i0;
  *(OOC_INT32*)(_check_pointer(i0, 4661)) = (-1);
  *(OOC_INT32*)((_check_pointer(i0, 4688))+4) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 4710))+8) = (-1);
  _copy_8((const void*)"",(void*)((_check_pointer(i0, 4738))+12),32);
  return (OOC_Package__Version)i0;
  ;
}

static OOC_Package__Executable OOC_Package__NewExecutable(void) {
  register OOC_INT32 i0;
  OOC_Package__Executable executable;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Package__Executable.baseTypes[0]);
  executable = (OOC_Package__Executable)i0;
  *(OOC_INT32*)(_check_pointer(i0, 4907)) = 0;
  return (OOC_Package__Executable)i0;
  ;
}

static OOC_Package__Library OOC_Package__NewLibrary(void) {
  register OOC_INT32 i0;
  OOC_Package__Library library;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Package__Library.baseTypes[0]);
  library = (OOC_Package__Library)i0;
  *(OOC_INT32*)((_check_pointer(i0, 5070))+4) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i0, 5101))+8) = (OOC_INT32)0;
  return (OOC_Package__Library)i0;
  ;
}

static void OOC_Package__InitFileData(OOC_Package__FileData fdata) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)fdata;
  *(OOC_INT32*)(_check_pointer(i0, 5215)) = 0;
  return;
  ;
}

static OOC_Package__FileSet OOC_Package__NewFileSet(void) {
  register OOC_INT32 i0;
  OOC_Package__FileSet fileSet;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Package__FileSet.baseTypes[0]);
  fileSet = (OOC_Package__FileSet)i0;
  OOC_Package__InitFileData((OOC_Package__FileData)i0);
  *(OOC_INT32*)((_check_pointer(i0, 5383))+4) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i0, 5413))+8) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i0, 5441))+12) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i0, 5466))+16) = (OOC_INT32)0;
  return (OOC_Package__FileSet)i0;
  ;
}

void OOC_Package__FileSetDesc_Append(OOC_Package__FileSet fileSet, OOC_Package__FileData fdata) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)fileSet;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5597))+16);
  i1 = i1==(OOC_INT32)0;
  if (i1) goto l3;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5666))+16);
  i2 = (OOC_INT32)fdata;
  *(OOC_INT32*)(_check_pointer(i1, 5671)) = i2;
  i1=i2;
  goto l4;
l3:
  i1 = (OOC_INT32)fdata;
  *(OOC_INT32*)((_check_pointer(i0, 5628))+12) = i1;
  
l4:
  *(OOC_INT32*)((_check_pointer(i0, 5715))+16) = i1;
  return;
  ;
}

OOC_Package__File OOC_Package__NewFile(Object__String name, Object__String destName) {
  register OOC_INT32 i0,i1;
  OOC_Package__File file;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Package__File.baseTypes[0]);
  file = (OOC_Package__File)i0;
  OOC_Package__InitFileData((OOC_Package__FileData)i0);
  i1 = (OOC_INT32)name;
  *(OOC_INT32*)((_check_pointer(i0, 5873))+4) = i1;
  i1 = (OOC_INT32)destName;
  *(OOC_INT32*)((_check_pointer(i0, 5896))+8) = i1;
  return (OOC_Package__File)i0;
  ;
}

OOC_Package__KeyValue OOC_Package__NewKeyValue(Object__String key, Config__Variable value) {
  register OOC_INT32 i0,i1;
  OOC_Package__KeyValue kv;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Package__KeyValue.baseTypes[0]);
  kv = (OOC_Package__KeyValue)i0;
  i1 = (OOC_INT32)key;
  *(OOC_INT32*)(_check_pointer(i0, 6075)) = i1;
  i1 = (OOC_INT32)value;
  *(OOC_INT32*)((_check_pointer(i0, 6094))+4) = i1;
  return (OOC_Package__KeyValue)i0;
  ;
}

static void OOC_Package__MergeConfig(OOC_Repository__PkgInfo pkg, Config_Section_Options__Section options, Config_Section_Options__Section pragmas) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT32 i;
  OOC_Package__KeyValue kv;
  Config_Section_Options__Option o;

  i0 = (OOC_INT32)pkg;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6314));
  i = 0;
  i1 = *(OOC_INT32*)((_check_pointer(i1, 6322))+4);
  i2 = 0<i1;
  if (!i2) goto l8;
  i2 = (OOC_INT32)options;
  i3=0;
l3_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6348));
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 6356));
  i4 = _check_pointer(i4, 6362);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 6362))*4);
  i4 = _type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 6366)))), &_td_OOC_Package__KeyValueDesc, 6366);
  kv = (OOC_Package__KeyValue)i4;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 6410))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 6402));
  i4 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 6395)))), Config_Section_Options__SectionDesc_Set)),Config_Section_Options__SectionDesc_Set)((Config_Section_Options__Section)i2, (Object__String)i4, (Config__Variable)i5);
  o = (Config_Section_Options__Option)i4;
  i3 = i3+1;
  i = i3;
  i4 = i3<i1;
  if (i4) goto l3_loop;
l8:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6449))+4);
  i1 = *(OOC_INT32*)((_check_pointer(i1, 6457))+4);
  i = 0;
  i2 = 0<i1;
  if (!i2) goto l16;
  i2 = (OOC_INT32)pragmas;
  i3=0;
l11_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6483))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 6491));
  i4 = _check_pointer(i4, 6497);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 6497))*4);
  i4 = _type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 6501)))), &_td_OOC_Package__KeyValueDesc, 6501);
  kv = (OOC_Package__KeyValue)i4;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 6545))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 6537));
  i4 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 6530)))), Config_Section_Options__SectionDesc_Set)),Config_Section_Options__SectionDesc_Set)((Config_Section_Options__Section)i2, (Object__String)i4, (Config__Variable)i5);
  o = (Config_Section_Options__Option)i4;
  i3 = i3+1;
  i = i3;
  i4 = i3<i1;
  if (i4) goto l11_loop;
l16:
  return;
  ;
}

static OOC_Package__Package OOC_Package__NewPackage(void) {
  register OOC_INT32 i0,i1;
  OOC_Package__Package p;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Package__Package.baseTypes[0]);
  p = (OOC_Package__Package)i0;
  OOC_Repository__InitPkgInfo((OOC_Repository__PkgInfo)i0);
  *(OOC_INT32*)((_check_pointer(i0, 6687))+8) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i0, 6706))+12) = (OOC_INT32)0;
  i1 = (OOC_INT32)RT0__NewObject(_td__qtd1.baseTypes[0]);
  ADT_ArrayList__ArrayListDesc_INIT((ADT_ArrayList__ArrayList)i1, 4);
  *(OOC_INT32*)((_check_pointer(i0, 6728))+16) = i1;
  i1 = (OOC_INT32)RT0__NewObject(_td__qtd3.baseTypes[0]);
  ADT_ArrayList__ArrayListDesc_INIT((ADT_ArrayList__ArrayList)i1, 4);
  *(OOC_INT32*)((_check_pointer(i0, 6783))+20) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 6844))+24) = (OOC_INT32)0;
  return (OOC_Package__Package)i0;
  ;
}

static OOC_Package__Repository OOC_Package__NewRepository(void) {
  register OOC_INT32 i0,i1;
  OOC_Package__Repository r;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Package__Repository.baseTypes[0]);
  r = (OOC_Package__Repository)i0;
  OOC_Repository__InitPkgInfo((OOC_Repository__PkgInfo)i0);
  i1 = (OOC_INT32)RT0__NewObject(_td__qtd5.baseTypes[0]);
  ADT_ArrayList__ArrayListDesc_INIT((ADT_ArrayList__ArrayList)i1, 4);
  *(OOC_INT32*)((_check_pointer(i0, 7007))+8) = i1;
  return (OOC_Package__Repository)i0;
  ;
}

void OOC_Package__RepositoryDesc_MergePackage(OOC_Package__Repository r, OOC_Package__Package pkg) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_INT32 i;
  OOC_Package__KeyValue kv;

  i0 = (OOC_INT32)pkg;
  i1 = (OOC_INT32)r;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 7205))+8);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7230))+8);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 7205))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 7219)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i4, (Object__Object)i3);
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7259));
  i = 0;
  i2 = *(OOC_INT32*)((_check_pointer(i2, 7267))+4);
  i3 = 0<i2;
  if (!i3) goto l8;
  i3=0;
l3_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7293));
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 7301));
  i4 = _check_pointer(i4, 7307);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 7307))*4);
  i4 = _type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 7311)))), &_td_OOC_Package__KeyValueDesc, 7311);
  kv = (OOC_Package__KeyValue)i4;
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 7329));
  i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 7329));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 7337)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i6, (Object__Object)i4);
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l3_loop;
l8:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7380))+4);
  i2 = *(OOC_INT32*)((_check_pointer(i2, 7388))+4);
  i = 0;
  i3 = 0<i2;
  if (!i3) goto l16;
  i3=0;
l11_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7414))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 7422));
  i4 = _check_pointer(i4, 7428);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 7428))*4);
  i4 = _type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 7432)))), &_td_OOC_Package__KeyValueDesc, 7432);
  kv = (OOC_Package__KeyValue)i4;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 7450))+4);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 7450))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 7458)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i6, (Object__Object)i4);
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l11_loop;
l16:
  return;
  ;
}

OOC_CHAR8 OOC_Package__RepositoryDesc_PackageInstalled(OOC_Package__Repository r, Object__String pkgName) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
  OOC_INT32 i;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7621))+8);
  i = 0;
  i1 = *(OOC_INT32*)((_check_pointer(i1, 7635))+4);
  i2 = 0<i1;
  if (!i2) goto l11;
  i2 = (OOC_INT32)pkgName;
  i3=0;
l3_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7656))+8);
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 7670));
  i4 = _check_pointer(i4, 7676);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7656))+8);
  i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i6, 7670));
  i6 = _check_pointer(i6, 7676);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i3, i7, OOC_UINT32, 7676))*4);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 7676))*4);
  i4 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 7679)))), Object__StringDesc_Equals)),Object__StringDesc_Equals)((Object__String)i4, (Object__Object)i2);
  if (!i4) goto l6;
  return 1u;
l6:
  i3 = i3+1;
  i = i3;
  i4 = i3<i1;
  if (i4) goto l3_loop;
l11:
  return 0u;
  ;
}

OOC_Package__FileSet OOC_Package__Normalize(OOC_Package__FileSet fileSet) {
  register OOC_INT32 i0,i1;
  OOC_CHAR8 *buffer;
  OOC_Package__FileSet norm;
  auto void OOC_Package__Normalize_NormalizeFileSet(OOC_Package__FileSet fileSet, Object__String sourcePrefix, Object__String destPrefix);
  auto OOC_Package__FileData OOC_Package__Normalize_MergeSort(OOC_Package__FileData list);
    
    void OOC_Package__Normalize_NormalizeFileSet(OOC_Package__FileSet fileSet, Object__String sourcePrefix, Object__String destPrefix) {
      register OOC_INT32 i0,i1,i2;
      OOC_Package__FileData ptr;
      auto void OOC_Package__Normalize_NormalizeFileSet_NormalizeFile(OOC_Package__File file);
        
        void OOC_Package__Normalize_NormalizeFileSet_NormalizeFile(OOC_Package__File file) {
          register OOC_INT32 i0,i1;
          Object__String name;
          auto Object__String OOC_Package__Normalize_NormalizeFileSet_NormalizeFile_NormalizePath(Object__String path);
            
            Object__String OOC_Package__Normalize_NormalizeFileSet_NormalizeFile_NormalizePath(Object__String path) {
              register OOC_INT32 i0,i1,i2,i3,i4,i5;
              Object__CharsLatin1 chars;
              OOC_INT16 i;
              OOC_INT16 j;

              i0 = (OOC_INT32)buffer;
              i1 = i0==(OOC_INT32)0;
              if (i1) goto l3;
              i1 = (OOC_INT32)path;
              i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 9133)), 0);
              i1 = *(OOC_INT32*)(_check_pointer(i1, 9112));
              i0 = i1>=i0;
              
              goto l4;
l3:
              i0=1u;
l4:
              i1 = (OOC_INT32)path;
              if (!i0) goto l7;
              i0 = *(OOC_INT32*)(_check_pointer(i1, 9170));
              buffer = (void*)((OOC_INT32)RT0__NewObject(_td_OOC_Package__8658.baseTypes[0], (i0+1)));
l7:
              i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9219)))), Object__StringDesc_ToString8)),Object__StringDesc_ToString8)((Object__String)i1, 63u);
              path = (Object__String)i0;
              i1 = (OOC_INT32)Object__String8Desc_CharsLatin1((Object__String8)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9267)))), &_td_Object__String8Desc, 9267)));
              chars = (Object__CharsLatin1)i1;
              i2 = (OOC_INT32)buffer;
              i3 = OOC_ARRAY_LENGTH((_check_pointer(i2, 9320)), 0);
              _copy_8((const void*)(_check_pointer(i1, 9311)),(void*)(_check_pointer(i2, 9320)),i3);
              i = 0;
              i1 = _check_pointer(i2, 9366);
              i2 = OOC_ARRAY_LENGTH(i1, 0);
              i1 = *(OOC_UINT8*)(i1+(_check_index(0, i2, OOC_UINT16, 9366)));
              i1 = i1!=0u;
              if (i1) goto l10;
              i1=0;
              goto l63;
l10:
              i1=0;
l11_loop:
              i2 = (OOC_INT32)buffer;
              i3 = _check_pointer(i2, 9401);
              i4 = OOC_ARRAY_LENGTH(i3, 0);
              i3 = *(OOC_UINT8*)(i3+(_check_index(i1, i4, OOC_UINT16, 9401)));
              i3 = i3==47u;
              if (i3) goto l57;
              i3 = _check_pointer(i2, 9538);
              i4 = OOC_ARRAY_LENGTH(i3, 0);
              i3 = *(OOC_UINT8*)(i3+(_check_index(i1, i4, OOC_UINT16, 9538)));
              i3 = i3==46u;
              if (i3) goto l16;
              i3=0u;
              goto l18;
l16:
              i3 = _check_pointer(i2, 9558);
              i4 = OOC_ARRAY_LENGTH(i3, 0);
              i3 = *(OOC_UINT8*)(i3+(_check_index((i1+1), i4, OOC_UINT16, 9558)));
              i3 = i3==47u;
              
l18:
              if (i3) goto l55;
              i3 = _check_pointer(i2, 9697);
              i4 = OOC_ARRAY_LENGTH(i3, 0);
              i3 = *(OOC_UINT8*)(i3+(_check_index(i1, i4, OOC_UINT16, 9697)));
              i3 = i3==46u;
              if (i3) goto l22;
              i3=0u;
              goto l24;
l22:
              i3 = _check_pointer(i2, 9717);
              i4 = OOC_ARRAY_LENGTH(i3, 0);
              i3 = *(OOC_UINT8*)(i3+(_check_index((i1+1), i4, OOC_UINT16, 9717)));
              i3 = i3==46u;
              
l24:
              if (i3) goto l26;
              i3=0u;
              goto l28;
l26:
              i3 = _check_pointer(i2, 9757);
              i4 = OOC_ARRAY_LENGTH(i3, 0);
              i3 = *(OOC_UINT8*)(i3+(_check_index((i1+2), i4, OOC_UINT16, 9757)));
              i3 = i3==47u;
              
l28:
              if (i3) goto l40;
l30_loop:
              i3 = _check_pointer(i2, 10307);
              i4 = OOC_ARRAY_LENGTH(i3, 0);
              i3 = *(OOC_UINT8*)(i3+(_check_index(i1, i4, OOC_UINT16, 10307)));
              i3 = i3==0u;
              if (i3) goto l58;
              i3 = _check_pointer(i2, 10375);
              i4 = OOC_ARRAY_LENGTH(i3, 0);
              i3 = *(OOC_UINT8*)(i3+(_check_index(i1, i4, OOC_UINT16, 10375)));
              i3 = i3==47u;
              if (i3) goto l36;
              i1 = i1+1;
              i = i1;
              
              goto l30_loop;
l36:
              i1 = i1+1;
              i = i1;
              
              goto l58;
l40:
              i3 = i1==0;
              if (i3) goto l52;
              i3=i1;
l43_loop:
              i3 = i3-1;
              j = i3;
              i4 = i3==0;
              if (i4) goto l46;
              i4 = _check_pointer(i2, 10107);
              i5 = OOC_ARRAY_LENGTH(i4, 0);
              i4 = *(OOC_UINT8*)(i4+(_check_index((i3-1), i5, OOC_UINT16, 10107)));
              i4 = i4==47u;
              
              goto l48;
l46:
              i4=1u;
l48:
              if (!i4) goto l43_loop;
l51:
              i4 = OOC_ARRAY_LENGTH((_check_pointer(i2, 10158)), 0);
              Strings__Delete((void*)(_check_pointer(i2, 10158)), i4, i3, ((i1-i3)+3));
              i = i3;
              i1=i3;
              goto l58;
l52:
              i3 = OOC_ARRAY_LENGTH((_check_pointer(i2, 9901)), 0);
              Strings__Delete((void*)(_check_pointer(i2, 9901)), i3, i1, 3);
              
              goto l58;
l55:
              i3 = OOC_ARRAY_LENGTH((_check_pointer(i2, 9662)), 0);
              Strings__Delete((void*)(_check_pointer(i2, 9662)), i3, i1, 2);
              
              goto l58;
l57:
              i3 = OOC_ARRAY_LENGTH((_check_pointer(i2, 9503)), 0);
              Strings__Delete((void*)(_check_pointer(i2, 9503)), i3, i1, 1);
              
l58:
              i2 = (OOC_INT32)buffer;
              i2 = _check_pointer(i2, 9366);
              i3 = OOC_ARRAY_LENGTH(i2, 0);
              i2 = *(OOC_UINT8*)(i2+(_check_index(i1, i3, OOC_UINT16, 9366)));
              i2 = i2!=0u;
              if (i2) goto l11_loop;
l63:
              i2 = (OOC_INT32)buffer;
              i3 = i1!=0;
              if (i3) goto l66;
              i3=0u;
              goto l68;
l66:
              i3 = _check_pointer(i2, 10633);
              i4 = OOC_ARRAY_LENGTH(i3, 0);
              i3 = *(OOC_UINT8*)(i3+(_check_index((i1-1), i4, OOC_UINT16, 10633)));
              i3 = i3==47u;
              
l68:
              if (!i3) goto l80;
l71_loop:
              i1 = i1-1;
              i = i1;
              i3 = i1!=0;
              if (i3) goto l74;
              i3=0u;
              goto l76;
l74:
              i3 = _check_pointer(i2, 10633);
              i4 = OOC_ARRAY_LENGTH(i3, 0);
              i3 = *(OOC_UINT8*)(i3+(_check_index((i1-1), i4, OOC_UINT16, 10633)));
              i3 = i3==47u;
              
l76:
              if (i3) goto l71_loop;
l80:
              i3 = _check_pointer(i2, 10700);
              i4 = OOC_ARRAY_LENGTH(i3, 0);
              *(OOC_UINT8*)(i3+(_check_index(i1, i4, OOC_UINT16, 10700))) = 0u;
              i3 = *(OOC_INT32*)(_check_pointer(i0, 10744));
              i3 = i1!=i3;
              if (i3) goto l83;
              return (Object__String)i0;
              goto l84;
l83:
              i0 = OOC_ARRAY_LENGTH((_check_pointer(i2, 10806)), 0);
              i0 = (OOC_INT32)Object__NewLatin1Region((void*)(_check_pointer(i2, 10806)), i0, 0, i1);
              return (Object__String)i0;
l84:
              _failed_function(8951); return 0;
              ;
            }


          i0 = (OOC_INT32)file;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11007))+4);
          i1 = (OOC_INT32)sourcePrefix;
          i0 = (OOC_INT32)Object__StringDesc_Concat((Object__String)i1, (Object__String)i0);
          i0 = (OOC_INT32)OOC_Package__Normalize_NormalizeFileSet_NormalizeFile_NormalizePath((Object__String)i0);
          name = (Object__String)i0;
          i0 = (OOC_INT32)file;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11032))+8);
          i1 = i1!=(OOC_INT32)0;
          if (i1) goto l3;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11196))+4);
          i1 = (OOC_INT32)destPrefix;
          i0 = (OOC_INT32)Object__StringDesc_Concat((Object__String)i1, (Object__String)i0);
          i0 = (OOC_INT32)OOC_Package__Normalize_NormalizeFileSet_NormalizeFile_NormalizePath((Object__String)i0);
          
          goto l4;
l3:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11112))+8);
          i1 = (OOC_INT32)destPrefix;
          i0 = (OOC_INT32)Object__StringDesc_Concat((Object__String)i1, (Object__String)i0);
          i0 = (OOC_INT32)OOC_Package__Normalize_NormalizeFileSet_NormalizeFile_NormalizePath((Object__String)i0);
          
l4:
          i1 = (OOC_INT32)name;
          i0 = (OOC_INT32)OOC_Package__NewFile((Object__String)i1, (Object__String)i0);
          i1 = (OOC_INT32)norm;
          OOC_Package__FileSetDesc_Append((OOC_Package__FileSet)i1, (OOC_Package__FileData)i0);
          return;
          ;
        }


      i0 = (OOC_INT32)fileSet;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11370))+4);
      i2 = (OOC_INT32)sourcePrefix;
      sourcePrefix = (Object__String)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)i2,(void*)i1)),(void*)((OOC_INT32)_c0)));
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11403))+8);
      i1 = i1!=(OOC_INT32)0;
      if (i1) goto l3;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11525))+4);
      i2 = (OOC_INT32)destPrefix;
      i1 = (OOC_INT32)Object__Concat2((void*)i2,(void*)i1);
      
      goto l4;
l3:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11464))+8);
      i2 = (OOC_INT32)destPrefix;
      i1 = (OOC_INT32)Object__Concat2((void*)i2,(void*)i1);
      
l4:
      destPrefix = (Object__String)((OOC_INT32)Object__Concat2((void*)i1,(void*)((OOC_INT32)_c1)));
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11611))+12);
      ptr = (OOC_Package__FileData)i0;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l20;
l7_loop:
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11661)))), &_td_OOC_Package__FileSetDesc);
      if (i1) goto l14;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11746)))), &_td_OOC_Package__FileDesc);
      if (i1) goto l12;
      _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11741)))), 11741);
      goto l15;
l12:
      OOC_Package__Normalize_NormalizeFileSet_NormalizeFile((OOC_Package__File)i0);
      goto l15;
l14:
      i1 = (OOC_INT32)destPrefix;
      i2 = (OOC_INT32)sourcePrefix;
      OOC_Package__Normalize_NormalizeFileSet((OOC_Package__FileSet)i0, (Object__String)i2, (Object__String)i1);
l15:
      i0 = (OOC_INT32)ptr;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 11817));
      ptr = (OOC_Package__FileData)i0;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l7_loop;
l20:
      return;
      ;
    }

    
    OOC_Package__FileData OOC_Package__Normalize_MergeSort(OOC_Package__FileData list) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_Package__FileData a;
      OOC_Package__FileData b;
      OOC_Package__FileData ptr;
      OOC_Package__FileData next;
      OOC_Package__FileData tail;
      auto OOC_CHAR8 OOC_Package__Normalize_MergeSort_Less(OOC_Package__File a, OOC_Package__File b);
        
        OOC_CHAR8 OOC_Package__Normalize_MergeSort_Less(OOC_Package__File a, OOC_Package__File b) {
          register OOC_INT32 i0,i1,i2,i3,i4;
          OOC_INT32 cmp;

          i0 = (OOC_INT32)b;
          i1 = (OOC_INT32)a;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12070))+8);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12070))+8);
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12089))+8);
          i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 12079)))), Object__StringDesc_Compare)),Object__StringDesc_Compare)((Object__String)i3, (Object__Object)i4);
          cmp = i2;
          i3 = i2==0;
          if (i3) goto l3;
          i0=i2;
          goto l4;
l3:
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12145))+4);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12145))+4);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12160))+4);
          i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 12150)))), Object__StringDesc_Compare)),Object__StringDesc_Compare)((Object__String)i1, (Object__Object)i0);
          
l4:
          return (i0<0);
          ;
        }


      i0 = (OOC_INT32)list;
      i1 = i0==(OOC_INT32)0;
      if (i1) goto l3;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 12268));
      i1 = i1==(OOC_INT32)0;
      
      goto l5;
l3:
      i1=1u;
l5:
      if (i1) goto l48;
      a = (OOC_Package__FileData)(OOC_INT32)0;
      b = (OOC_Package__FileData)(OOC_INT32)0;
      ptr = (OOC_Package__FileData)i0;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l9;
      i0=(OOC_INT32)0;i1=(OOC_INT32)0;
      goto l19;
l9:
      i1=(OOC_INT32)0;i2=(OOC_INT32)0;
l10_loop:
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 12476));
      next = (OOC_Package__FileData)i3;
      *(OOC_INT32*)(_check_pointer(i0, 12504)) = i1;
      a = (OOC_Package__FileData)i0;
      ptr = (OOC_Package__FileData)i3;
      i1 = i3!=(OOC_INT32)0;
      if (i1) goto l13;
      i1=i3;
      goto l14;
l13:
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 12621));
      next = (OOC_Package__FileData)i1;
      *(OOC_INT32*)(_check_pointer(i3, 12651)) = i2;
      b = (OOC_Package__FileData)i3;
      ptr = (OOC_Package__FileData)i1;
      i2=i3;
l14:
      i3 = i1!=(OOC_INT32)0;
      if (!i3) goto l18;
      {register OOC_INT32 h0=i0;i0=i1;i1=h0;}
      goto l10_loop;
l18:
      i1=i2;
l19:
      i0 = (OOC_INT32)OOC_Package__Normalize_MergeSort((OOC_Package__FileData)i0);
      a = (OOC_Package__FileData)i0;
      i1 = (OOC_INT32)OOC_Package__Normalize_MergeSort((OOC_Package__FileData)i1);
      b = (OOC_Package__FileData)i1;
      i2 = (OOC_INT32)OOC_Package__NewFile((Object__String)(OOC_INT32)0, (Object__String)(OOC_INT32)0);
      list = (OOC_Package__FileData)i2;
      tail = (OOC_Package__FileData)i2;
      i0 = i0!=(OOC_INT32)0;
      if (i0) goto l22;
      i0 = i1!=(OOC_INT32)0;
      
      goto l24;
l22:
      i0=1u;
l24:
      if (!i0) goto l47;
l26_loop:
      i0 = (OOC_INT32)a;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l29;
      i0=0u;
      goto l35;
l29:
      i1 = (OOC_INT32)b;
      i2 = i1==(OOC_INT32)0;
      if (i2) goto l32;
      i0 = OOC_Package__Normalize_MergeSort_Less((OOC_Package__File)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13019)))), &_td_OOC_Package__FileDesc, 13019)), (OOC_Package__File)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 13028)))), &_td_OOC_Package__FileDesc, 13028)));
      
      goto l35;
l32:
      i0=1u;
l35:
      if (i0) goto l37;
      i0 = (OOC_INT32)b;
      ptr = (OOC_Package__FileData)i0;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 13127));
      b = (OOC_Package__FileData)i1;
      
      goto l38;
l37:
      i0 = (OOC_INT32)a;
      ptr = (OOC_Package__FileData)i0;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 13069));
      a = (OOC_Package__FileData)i1;
      
l38:
      *(OOC_INT32*)(_check_pointer(i0, 13170)) = (OOC_INT32)0;
      i1 = (OOC_INT32)tail;
      *(OOC_INT32*)(_check_pointer(i1, 13206)) = i0;
      tail = (OOC_Package__FileData)i0;
      i0 = (OOC_INT32)a;
      i0 = i0!=(OOC_INT32)0;
      if (i0) goto l41;
      i0 = (OOC_INT32)b;
      i0 = i0!=(OOC_INT32)0;
      
      goto l43;
l41:
      i0=1u;
l43:
      if (i0) goto l26_loop;
l47:
      i0 = (OOC_INT32)list;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 13283));
      return (OOC_Package__FileData)i0;
      goto l49;
l48:
      return (OOC_Package__FileData)i0;
l49:
      _failed_function(11884); return 0;
      ;
    }


  buffer = (void*)(OOC_INT32)0;
  i0 = (OOC_INT32)OOC_Package__NewFileSet();
  norm = (OOC_Package__FileSet)i0;
  *(OOC_INT32*)((_check_pointer(i0, 13392))+4) = ((OOC_INT32)_c2);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13435))+4);
  *(OOC_INT32*)((_check_pointer(i0, 13419))+8) = i1;
  i0 = (OOC_INT32)fileSet;
  OOC_Package__Normalize_NormalizeFileSet((OOC_Package__FileSet)i0, (Object__String)((OOC_INT32)_c3), (Object__String)((OOC_INT32)_c4));
  i0 = (OOC_INT32)norm;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13518))+12);
  i1 = (OOC_INT32)OOC_Package__Normalize_MergeSort((OOC_Package__FileData)i1);
  *(OOC_INT32*)((_check_pointer(i0, 13495))+12) = i1;
  i0 = (OOC_INT32)norm;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13547))+12);
  *(OOC_INT32*)((_check_pointer(i0, 13534))+16) = i1;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13566))+16);
  i1 = i1!=(OOC_INT32)0;
  if (!i1) goto l10;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13601))+16);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 13606));
  i1 = i1!=(OOC_INT32)0;
  if (!i1) goto l10;
l4_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13655))+16);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 13660));
  *(OOC_INT32*)((_check_pointer(i0, 13642))+16) = i1;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13601))+16);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 13606));
  i1 = i1!=(OOC_INT32)0;
  if (i1) goto l4_loop;
l10:
  return (OOC_Package__FileSet)i0;
  ;
}

static Object__String OOC_Package__StringAttr(XML_Builder__Attribute att) {
  register OOC_INT32 i0,i1,i2,i3;
  XML_UnicodeBuffer__CharArray str;
  OOC_CHAR8 *buffer;

  i0 = (OOC_INT32)att;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14100))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14082))+12);
  i0 = (OOC_INT32)XML_DTD__AttValueDesc_Flatten((XML_DTD__AttValue)i0, (XML_DTD__AttrDecl)i1);
  str = (XML_UnicodeBuffer__CharArray)i0;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 14135)), 0);
  i1 = (OOC_INT32)RT0__NewObject(_td_OOC_Package__14034.baseTypes[0], i1);
  buffer = (void*)i1;
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i0, 14165)), 0);
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i1, 14179)), 0);
  LongStrings__Short((void*)(_check_pointer(i0, 14165)), i2, 63u, (void*)(_check_pointer(i1, 14179)), i3);
  i0 = OOC_ARRAY_LENGTH((_check_pointer(i1, 14217)), 0);
  i0 = (OOC_INT32)Object__NewLatin1((void*)(_check_pointer(i1, 14217)), i0);
  return (Object__String)i0;
  ;
}

static OOC_CHAR8 OOC_Package__AtElement(Config_Parser__Node node, const OOC_CHAR16 elementName__ref[], OOC_LEN elementName_0d) {
  register OOC_INT32 i0,i1;
  OOC_ALLOCATE_VPAR(elementName,OOC_CHAR16 ,elementName_0d)

  OOC_INITIALIZE_VPAR(elementName__ref,elementName,OOC_CHAR16 ,(elementName_0d*2))
  i0 = (OOC_INT32)node;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14389)))), &_td_Config_Parser__ElementDesc);
  
l5:
  if (i1) goto l7;
  i0=0u;
  goto l8;
l7:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14431)))), &_td_Config_Parser__ElementDesc, 14431)), 14439))+28);
  i0 = (
  _cmp16((const void*)(_check_pointer(i0, 14444)),(const void*)(OOC_INT32)elementName))==0;
  
l8:
  return i0;
  ;
}

static void OOC_Package__ParseKeyValue(Config_Parser__Element elem, ADT_ArrayList__ArrayList list, Config_Section_Options__Section options, Object__String defaultType, XML_Locator__ErrorListener errorListener, OOC_Error__List errList) {
  register OOC_INT32 i0,i1,i2,i3;
  Msg__Msg lastError;
  Config_Parser__Node node;
  auto void OOC_Package__ParseKeyValue_Err(OOC_INT32 code, Config_Parser__Node xmlNode);
  auto void OOC_Package__ParseKeyValue_SetReason(Exception__Exception e);
  auto void OOC_Package__ParseKeyValue_SkipWS(Config_Parser__Node *node);
  auto OOC_Package__KeyValue OOC_Package__ParseKeyValue_ParseDefine(volatile Config_Parser__Element elem);
    
    void OOC_Package__ParseKeyValue_Err(OOC_INT32 code, Config_Parser__Node xmlNode) {
      register OOC_INT32 i0,i1,i2,i3;

      i0 = (OOC_INT32)xmlNode;
      i1 = (OOC_INT32)errorListener;
      i2 = (OOC_INT32)OOC_Package__packageContext;
      i3 = code;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14984)))), XML_Locator__ErrorListenerDesc_Error)),XML_Locator__ErrorListenerDesc_Error)((XML_Locator__ErrorListener)i1, (XML_Error__Context)i2, i3, 0u, (void*)((_check_pointer(i0, 15066))+4));
      lastError = (Msg__Msg)i0;
      i1 = (OOC_INT32)errList;
      OOC_Error__ListDesc_Append((OOC_Error__List)i1, (Msg__Msg)i0);
      return;
      ;
    }

    
    void OOC_Package__ParseKeyValue_SetReason(Exception__Exception e) {
      register OOC_INT32 i0,i1;
      Object__String msg;
      Object__CharsLatin1 chars;

      i0 = (OOC_INT32)e;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15252)))), Exception__ExceptionDesc_GetMessage)),Exception__ExceptionDesc_GetMessage)((Exception__Exception)i0);
      msg = (Object__String)i0;
      i0 = (OOC_INT32)Object__String8Desc_CharsLatin1((Object__String8)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15293)))), &_td_Object__String8Desc, 15293)));
      chars = (Object__CharsLatin1)i0;
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 15381)), 0);
      i0 = (OOC_INT32)Msg__GetStringPtr((void*)(_check_pointer(i0, 15381)), i1);
      i1 = (OOC_INT32)lastError;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15332)))), Msg__MsgDesc_SetStringAttrib)),Msg__MsgDesc_SetStringAttrib)((Msg__Msg)i1, "reason", 7, (Msg__StringPtr)i0);
      return;
      ;
    }

    
    void OOC_Package__ParseKeyValue_SkipWS(Config_Parser__Node *node) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)*node;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l3;
      i1=0u;
      goto l5;
l3:
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15494)))), &_td_Config_Parser__CharDataDesc);
      
l5:
      if (!i1) goto l19;
      
l7_loop:
      i1 = Config_Parser__NodeDesc_IsWhitespace((Config_Parser__Node)i0);
      i1 = !i1;
      if (!i1) goto l10;
      OOC_Package__ParseKeyValue_Err(2, (Config_Parser__Node)i0);
l10:
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 15625));
      *node = (Config_Parser__Node)i0;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l13;
      i1=0u;
      goto l15;
l13:
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15494)))), &_td_Config_Parser__CharDataDesc);
      
l15:
      if (i1) goto l7_loop;
l19:
      return;
      ;
    }

    
    OOC_Package__KeyValue OOC_Package__ParseKeyValue_ParseDefine(volatile Config_Parser__Element elem) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
      volatile Object__String name;
      volatile Object__String type;
      volatile OOC_INT32 i;
      volatile XML_Builder__Attribute att;
      volatile Object__String stringBuffer;
      volatile Config_Parser__Node node;
      volatile OOC_CHAR8 str[1024];
      volatile Object__CharsLatin1 chars;
      volatile Config__Variable value;
      jmp_buf _target0;
      Exception__Context _context0;

      name = (Object__String)(OOC_INT32)0;
      i0 = (OOC_INT32)defaultType;
      type = (Object__String)i0;
      i1 = (OOC_INT32)elem;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 16066))+32);
      i = 0;
      i2 = *(OOC_INT32*)(_check_pointer(i2, 16075));
      i3 = 0<i2;
      if (i3) goto l3;
      i2=i0;i0=(OOC_INT32)0;
      goto l17;
l3:
      i4=i0;i0=0;i3=(OOC_INT32)0;
l4_loop:
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 16104))+32);
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 16113))+4);
      i5 = _check_pointer(i5, 16118);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i0, i6, OOC_UINT32, 16118))*4);
      att = (XML_Builder__Attribute)i5;
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 16138))+4);
      i6 = (
      _cmp16((const void*)(_check_pointer(i6, 16148)),(const void*)((OOC_CHAR16[]){110,97,109,101,0})))==0;
      if (i6) goto l11;
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 16218))+4);
      i6 = (
      _cmp16((const void*)(_check_pointer(i6, 16228)),(const void*)((OOC_CHAR16[]){116,121,112,101,0})))==0;
      if (i6) goto l9;
      OOC_Package__ParseKeyValue_Err(3, (Config_Parser__Node)i1);
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 16398))+4);
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 16398))+4);
      i6 = OOC_ARRAY_LENGTH((_check_pointer(i6, 16408)), 0);
      i5 = (OOC_INT32)Msg__GetLStringPtr((void*)(_check_pointer(i5, 16408)), i6);
      i6 = (OOC_INT32)lastError;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 16351)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i6, "name", 5, (Msg__LStringPtr)i5);
      
      goto l12;
l9:
      i4 = (OOC_INT32)OOC_Package__StringAttr((XML_Builder__Attribute)i5);
      type = (Object__String)i4;
      
      goto l12;
l11:
      i3 = (OOC_INT32)OOC_Package__StringAttr((XML_Builder__Attribute)i5);
      name = (Object__String)i3;
      
l12:
      i0 = i0+1;
      i = i0;
      i5 = i0<i2;
      if (i5) goto l4_loop;
l16:
      i0=i3;i2=i4;
l17:
      i0 = i0==(OOC_INT32)0;
      if (i0) goto l49;
      i0 = i2==(OOC_INT32)0;
      if (i0) goto l47;
      i0 = (OOC_INT32)_c5;
      stringBuffer = (Object__String)i0;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 16674))+36);
      node = (Config_Parser__Node)i3;
      i4 = i3!=(OOC_INT32)0;
      if (!i4) goto l34;
      {register OOC_INT32 h0=i0;i0=i3;i3=h0;}
l25_loop:
      i4 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16733)))), &_td_Config_Parser__CharDataDesc);
      if (i4) goto l28;
      OOC_Package__ParseKeyValue_Err(15, (Config_Parser__Node)i0);
      
      goto l29;
l28:
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16788))+28);
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16788))+28);
      i4 = OOC_ARRAY_LENGTH((_check_pointer(i4, 16795)), 0);
      LongStrings__Short((void*)(_check_pointer(i5, 16795)), i4, 63u, (void*)(OOC_INT32)str, 1024);
      i4 = (OOC_INT32)Object__NewLatin1((void*)(OOC_INT32)str, 1024);
      i3 = (OOC_INT32)Object__StringDesc_Concat((Object__String)i3, (Object__String)i4);
      stringBuffer = (Object__String)i3;
      
l29:
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 16978));
      node = (Config_Parser__Node)i0;
      i4 = i0!=(OOC_INT32)0;
      if (i4) goto l25_loop;
l33:
      i0=i3;
l34:
      i3 = (OOC_INT32)Object__String8Desc_CharsLatin1((Object__String8)(_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 17032)))), &_td_Object__String8Desc, 17032)));
      chars = (Object__CharsLatin1)i3;
      i4 = (OOC_INT32)options;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 17097))+8);
      i2 = (OOC_INT32)Config__GetClone((ADT_Dictionary__Dictionary)i4, (Object__String)i2);
      value = (Config__Variable)i2;
      i4 = i2==(OOC_INT32)0;
      if (i4) goto l45;
      {
        Exception__PushContext(&_context0, &_target0);
        if (!setjmp(_target0)) goto l43;
        Exception__PopContext(1);
        i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG(((OOC_INT32)Exception__Current()))), &_td_Exception__ParseErrorDesc);
        if (i0) goto l41;
        Exception__ActivateContext();
        goto l42;
l41:
        i0 = (OOC_INT32)elem;
        OOC_Package__ParseKeyValue_Err(17, (Config_Parser__Node)i0);
        i0 = (OOC_INT32)Exception__Current();
        OOC_Package__ParseKeyValue_SetReason((Exception__Exception)i0);
l42:
        Exception__Clear();
        goto l44;
l43:
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 17292)))), Config__VariableDesc_StringToValue)),Config__VariableDesc_StringToValue)((Config__Variable)i2, (Object__String)i0);
        Exception__PopContext(1);
l44:;
      }
      goto l46;
l45:
      OOC_Package__ParseKeyValue_Err(16, (Config_Parser__Node)i1);
      i0 = OOC_ARRAY_LENGTH((_check_pointer(i3, 17244)), 0);
      i0 = (OOC_INT32)Msg__GetStringPtr((void*)(_check_pointer(i3, 17244)), i0);
      i1 = (OOC_INT32)lastError;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17197)))), Msg__MsgDesc_SetStringAttrib)),Msg__MsgDesc_SetStringAttrib)((Msg__Msg)i1, "type", 5, (Msg__StringPtr)i0);
l46:
      i0 = (OOC_INT32)value;
      i1 = (OOC_INT32)name;
      i0 = (OOC_INT32)OOC_Package__NewKeyValue((Object__String)i1, (Config__Variable)i0);
      return (OOC_Package__KeyValue)i0;
      goto l50;
l47:
      OOC_Package__ParseKeyValue_Err(11, (Config_Parser__Node)i1);
      return (OOC_Package__KeyValue)(OOC_INT32)0;
      goto l50;
l49:
      OOC_Package__ParseKeyValue_Err(5, (Config_Parser__Node)i1);
      return (OOC_Package__KeyValue)(OOC_INT32)0;
l50:
      _failed_function(15676); return 0;
      ;
    }


  i0 = (OOC_INT32)elem;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17574))+32);
  i1 = *(OOC_INT32*)(_check_pointer(i1, 17583));
  i1 = i1!=0;
  if (!i1) goto l4;
  OOC_Package__ParseKeyValue_Err(3, (Config_Parser__Node)i0);
  i0 = (OOC_INT32)elem;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17696))+32);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 17705))+4);
  i1 = _check_pointer(i1, 17710);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 17710))*4);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 17713))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17696))+32);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 17705))+4);
  i2 = _check_pointer(i2, 17710);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(0, i3, OOC_UINT8, 17710))*4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 17713))+4);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 17723)), 0);
  i1 = (OOC_INT32)Msg__GetLStringPtr((void*)(_check_pointer(i2, 17723)), i1);
  i2 = (OOC_INT32)lastError;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 17648)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i2, "name", 5, (Msg__LStringPtr)i1);
  
l4:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17758))+36);
  node = (Config_Parser__Node)i0;
  OOC_Package__ParseKeyValue_SkipWS((void*)(OOC_INT32)&node);
  i0 = (OOC_INT32)node;
  i1 = i0!=0;
  if (!i1) goto l16;
l7_loop:
  i1 = OOC_Package__AtElement((Config_Parser__Node)i0, ((OOC_CHAR16[]){100,101,102,105,110,101,0}), 7);
  if (i1) goto l10;
  OOC_Package__ParseKeyValue_Err(13, (Config_Parser__Node)i0);
  i0 = (OOC_INT32)node;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 18004));
  node = (Config_Parser__Node)i0;
  goto l11;
l10:
  i0 = (OOC_INT32)OOC_Package__ParseKeyValue_ParseDefine((Config_Parser__Element)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17896)))), &_td_Config_Parser__ElementDesc, 17896)));
  i1 = (OOC_INT32)list;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17864)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i1, (Object__Object)i0);
  i0 = (OOC_INT32)node;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 17928));
  node = (Config_Parser__Node)i0;
l11:
  OOC_Package__ParseKeyValue_SkipWS((void*)(OOC_INT32)&node);
  i0 = (OOC_INT32)node;
  i1 = i0!=0;
  if (i1) goto l7_loop;
l16:
  return;
  ;
}

static OOC_Package__Package OOC_Package__ProcessPackage(Config_Parser__Element root, XML_Locator__ErrorListener errorListener, OOC_Error__List errList) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  Msg__Msg lastError;
  OOC_Package__Package pkg;
  OOC_INT32 i;
  XML_Builder__Attribute att;
  Config_Parser__Node node;
  auto void OOC_Package__ProcessPackage_Err(OOC_INT32 code, Config_Parser__Node xmlNode);
  auto void OOC_Package__ProcessPackage_SkipWS(Config_Parser__Node *node);
  auto OOC_Package__Version OOC_Package__ProcessPackage_ParseVersion(Config_Parser__Element elem);
  auto OOC_Package__Executable OOC_Package__ProcessPackage_ParseExecutable(Config_Parser__Element elem);
  auto OOC_Package__Library OOC_Package__ProcessPackage_ParseLibrary(Config_Parser__Element elem);
  auto OOC_Package__FileSet OOC_Package__ProcessPackage_ParseFileSet(Config_Parser__Element elem);
    
    void OOC_Package__ProcessPackage_Err(OOC_INT32 code, Config_Parser__Node xmlNode) {
      register OOC_INT32 i0,i1,i2,i3;

      i0 = (OOC_INT32)xmlNode;
      i1 = (OOC_INT32)errorListener;
      i2 = (OOC_INT32)OOC_Package__packageContext;
      i3 = code;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 18463)))), XML_Locator__ErrorListenerDesc_Error)),XML_Locator__ErrorListenerDesc_Error)((XML_Locator__ErrorListener)i1, (XML_Error__Context)i2, i3, 0u, (void*)((_check_pointer(i0, 18545))+4));
      lastError = (Msg__Msg)i0;
      i1 = (OOC_INT32)errList;
      OOC_Error__ListDesc_Append((OOC_Error__List)i1, (Msg__Msg)i0);
      return;
      ;
    }

    
    void OOC_Package__ProcessPackage_SkipWS(Config_Parser__Node *node) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)*node;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l3;
      i1=0u;
      goto l5;
l3:
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18686)))), &_td_Config_Parser__CharDataDesc);
      
l5:
      if (!i1) goto l19;
      
l7_loop:
      i1 = Config_Parser__NodeDesc_IsWhitespace((Config_Parser__Node)i0);
      i1 = !i1;
      if (!i1) goto l10;
      OOC_Package__ProcessPackage_Err(2, (Config_Parser__Node)i0);
l10:
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 18817));
      *node = (Config_Parser__Node)i0;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l13;
      i1=0u;
      goto l15;
l13:
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18686)))), &_td_Config_Parser__CharDataDesc);
      
l15:
      if (i1) goto l7_loop;
l19:
      return;
      ;
    }

    
    OOC_Package__Version OOC_Package__ProcessPackage_ParseVersion(Config_Parser__Element elem) {
      register OOC_INT32 i0,i1,i2,i3,i4;
      OOC_Package__Version version;
      OOC_INT32 i;
      XML_Builder__Attribute att;
      OOC_CHAR8 str[32];
      auto OOC_INT32 OOC_Package__ProcessPackage_ParseVersion_Unsigned(XML_Builder__Attribute att);
        
        OOC_INT32 OOC_Package__ProcessPackage_ParseVersion_Unsigned(XML_Builder__Attribute att) {
          register OOC_INT32 i0,i1,i2;
          XML_UnicodeBuffer__CharArray str;
          OOC_CHAR8 buffer[128];
          OOC_INT8 res;
          OOC_INT32 i;

          i0 = (OOC_INT32)att;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19339))+8);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19321))+12);
          i1 = (OOC_INT32)XML_DTD__AttValueDesc_Flatten((XML_DTD__AttValue)i2, (XML_DTD__AttrDecl)i1);
          str = (XML_UnicodeBuffer__CharArray)i1;
          i2 = OOC_ARRAY_LENGTH((_check_pointer(i1, 19370)), 0);
          i2 = i2<128;
          if (!i2) goto l10;
          i2 = OOC_ARRAY_LENGTH((_check_pointer(i1, 19423)), 0);
          LongStrings__Short((void*)(_check_pointer(i1, 19423)), i2, 63u, (void*)(OOC_INT32)buffer, 128);
          IntStr__StrToInt((void*)(OOC_INT32)buffer, 128, (void*)(OOC_INT32)&i, (void*)(OOC_INT32)&res);
          i1 = res;
          i1 = i1==0;
          if (i1) goto l5;
          i1=0u;
          goto l7;
l5:
          i1 = i;
          i1 = i1>=0;
          
l7:
          if (!i1) goto l10;
          i1 = i;
          return i1;
l10:
          i1 = (OOC_INT32)elem;
          OOC_Package__ProcessPackage_Err(14, (Config_Parser__Node)i1);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19692))+4);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19692))+4);
          i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 19702)), 0);
          i0 = (OOC_INT32)Msg__GetLStringPtr((void*)(_check_pointer(i0, 19702)), i1);
          i1 = (OOC_INT32)lastError;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 19645)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i1, "name", 5, (Msg__LStringPtr)i0);
          return 0;
          ;
        }


      i0 = (OOC_INT32)OOC_Package__NewVersion();
      version = (OOC_Package__Version)i0;
      i0 = (OOC_INT32)elem;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19815))+32);
      i = 0;
      i0 = *(OOC_INT32*)(_check_pointer(i0, 19824));
      i1 = 0<i0;
      if (!i1) goto l20;
      i1=0;
l3_loop:
      i2 = (OOC_INT32)elem;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 19853))+32);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 19862))+4);
      i3 = _check_pointer(i3, 19867);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i1 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i1, i4, OOC_UINT32, 19867))*4);
      att = (XML_Builder__Attribute)i1;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 19887))+4);
      i3 = (
      _cmp16((const void*)(_check_pointer(i3, 19897)),(const void*)((OOC_CHAR16[]){99,117,114,114,101,110,116,0})))==0;
      if (i3) goto l14;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 19979))+4);
      i3 = (
      _cmp16((const void*)(_check_pointer(i3, 19989)),(const void*)((OOC_CHAR16[]){97,103,101,0})))==0;
      if (i3) goto l12;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 20063))+4);
      i3 = (
      _cmp16((const void*)(_check_pointer(i3, 20073)),(const void*)((OOC_CHAR16[]){114,101,118,105,115,105,111,110,0})))==0;
      if (i3) goto l10;
      OOC_Package__ProcessPackage_Err(3, (Config_Parser__Node)i2);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 20257))+4);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 20257))+4);
      i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 20267)), 0);
      i1 = (OOC_INT32)Msg__GetLStringPtr((void*)(_check_pointer(i1, 20267)), i2);
      i2 = (OOC_INT32)lastError;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 20210)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i2, "name", 5, (Msg__LStringPtr)i1);
      goto l15;
l10:
      i2 = (OOC_INT32)version;
      i1 = OOC_Package__ProcessPackage_ParseVersion_Unsigned((XML_Builder__Attribute)i1);
      *(OOC_INT32*)((_check_pointer(i2, 20111))+8) = i1;
      goto l15;
l12:
      i2 = (OOC_INT32)version;
      i1 = OOC_Package__ProcessPackage_ParseVersion_Unsigned((XML_Builder__Attribute)i1);
      *(OOC_INT32*)((_check_pointer(i2, 20022))+4) = i1;
      goto l15;
l14:
      i2 = (OOC_INT32)version;
      i1 = OOC_Package__ProcessPackage_ParseVersion_Unsigned((XML_Builder__Attribute)i1);
      *(OOC_INT32*)(_check_pointer(i2, 19934)) = i1;
l15:
      i1 = i;
      i1 = i1+1;
      i = i1;
      i2 = i1<i0;
      if (i2) goto l3_loop;
l20:
      i0 = (OOC_INT32)version;
      i1 = *(OOC_INT32*)(_check_pointer(i0, 20312));
      i2 = (OOC_INT32)elem;
      i1 = i1==(-1);
      if (!i1) goto l23;
      OOC_Package__ProcessPackage_Err(7, (Config_Parser__Node)i2);
l23:
      i1 = *(OOC_INT32*)((_check_pointer(i0, 20404))+8);
      i1 = i1==(-1);
      if (!i1) goto l26;
      OOC_Package__ProcessPackage_Err(8, (Config_Parser__Node)i2);
l26:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 20495))+36);
      i1 = i1!=0;
      if (!i1) goto l29;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 20548))+36);
      OOC_Package__ProcessPackage_Err(0, (Config_Parser__Node)i1);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 20624))+28);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 20624))+28);
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 20629)), 0);
      i1 = (OOC_INT32)Msg__GetLStringPtr((void*)(_check_pointer(i2, 20629)), i1);
      i2 = (OOC_INT32)lastError;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 20576)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i2, "name", 5, (Msg__LStringPtr)i1);
l29:
      _copy_8((const void*)"",(void*)((_check_pointer(i0, 20665))+12),32);
      i1 = *(OOC_INT32*)(_check_pointer(i0, 20708));
      IntStr__IntToStr(i1, (void*)(OOC_INT32)str, 32);
      Strings__Append((void*)(OOC_INT32)str, 32, (void*)((_check_pointer(i0, 20757))+12), 32);
      Strings__Append(":", 2, (void*)((_check_pointer(i0, 20799))+12), 32);
      i1 = *(OOC_INT32*)((_check_pointer(i0, 20837))+8);
      IntStr__IntToStr(i1, (void*)(OOC_INT32)str, 32);
      Strings__Append((void*)(OOC_INT32)str, 32, (void*)((_check_pointer(i0, 20887))+12), 32);
      Strings__Append(":", 2, (void*)((_check_pointer(i0, 20929))+12), 32);
      i1 = *(OOC_INT32*)((_check_pointer(i0, 20967))+4);
      IntStr__IntToStr(i1, (void*)(OOC_INT32)str, 32);
      Strings__Append((void*)(OOC_INT32)str, 32, (void*)((_check_pointer(i0, 21012))+12), 32);
      return (OOC_Package__Version)i0;
      ;
    }

    
    OOC_Package__Executable OOC_Package__ProcessPackage_ParseExecutable(Config_Parser__Element elem) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5;
      OOC_Package__Executable executable;
      OOC_INT32 i;
      XML_Builder__Attribute att;

      i0 = (OOC_INT32)OOC_Package__NewExecutable();
      executable = (OOC_Package__Executable)i0;
      i1 = (OOC_INT32)elem;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 21334))+32);
      i = 0;
      i2 = *(OOC_INT32*)(_check_pointer(i2, 21343));
      i3 = 0<i2;
      if (!i3) goto l12;
      i3=0;
l3_loop:
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 21372))+32);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 21381))+4);
      i4 = _check_pointer(i4, 21386);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 21386))*4);
      att = (XML_Builder__Attribute)i4;
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 21406))+4);
      i5 = (
      _cmp16((const void*)(_check_pointer(i5, 21416)),(const void*)((OOC_CHAR16[]){109,97,105,110,45,109,111,100,117,108,101,0})))==0;
      if (i5) goto l6;
      OOC_Package__ProcessPackage_Err(3, (Config_Parser__Node)i1);
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 21610))+4);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 21610))+4);
      i5 = OOC_ARRAY_LENGTH((_check_pointer(i5, 21620)), 0);
      i4 = (OOC_INT32)Msg__GetLStringPtr((void*)(_check_pointer(i4, 21620)), i5);
      i5 = (OOC_INT32)lastError;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 21563)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i5, "name", 5, (Msg__LStringPtr)i4);
      goto l7;
l6:
      i4 = (OOC_INT32)OOC_Package__StringAttr((XML_Builder__Attribute)i4);
      *(OOC_INT32*)(_check_pointer(i0, 21460)) = i4;
l7:
      i3 = i3+1;
      i = i3;
      i4 = i3<i2;
      if (i4) goto l3_loop;
l12:
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 21668));
      i2 = i2==0;
      if (!i2) goto l15;
      OOC_Package__ProcessPackage_Err(9, (Config_Parser__Node)i1);
l15:
      return (OOC_Package__Executable)i0;
      ;
    }

    
    OOC_Package__Library OOC_Package__ProcessPackage_ParseLibrary(Config_Parser__Element elem) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5;
      OOC_Package__Library library;
      OOC_INT32 i;
      XML_Builder__Attribute att;
      Config_Parser__Node node;

      i0 = (OOC_INT32)OOC_Package__NewLibrary();
      library = (OOC_Package__Library)i0;
      i1 = (OOC_INT32)elem;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 22066))+32);
      i = 0;
      i2 = *(OOC_INT32*)(_check_pointer(i2, 22075));
      i3 = 0<i2;
      if (!i3) goto l16;
      i3=0;
l3_loop:
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 22104))+32);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 22113))+4);
      i4 = _check_pointer(i4, 22118);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 22118))*4);
      att = (XML_Builder__Attribute)i4;
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 22138))+4);
      i5 = (
      _cmp16((const void*)(_check_pointer(i5, 22148)),(const void*)((OOC_CHAR16[]){110,97,109,101,0})))==0;
      if (i5) goto l10;
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 22226))+4);
      i5 = (
      _cmp16((const void*)(_check_pointer(i5, 22236)),(const void*)((OOC_CHAR16[]){109,97,105,110,45,109,111,100,117,108,101,0})))==0;
      if (i5) goto l8;
      OOC_Package__ProcessPackage_Err(3, (Config_Parser__Node)i1);
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 22427))+4);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 22427))+4);
      i5 = OOC_ARRAY_LENGTH((_check_pointer(i5, 22437)), 0);
      i4 = (OOC_INT32)Msg__GetLStringPtr((void*)(_check_pointer(i4, 22437)), i5);
      i5 = (OOC_INT32)lastError;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 22380)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i5, "name", 5, (Msg__LStringPtr)i4);
      goto l11;
l8:
      i4 = (OOC_INT32)OOC_Package__StringAttr((XML_Builder__Attribute)i4);
      *(OOC_INT32*)((_check_pointer(i0, 22277))+4) = i4;
      goto l11;
l10:
      i4 = (OOC_INT32)OOC_Package__StringAttr((XML_Builder__Attribute)i4);
      *(OOC_INT32*)(_check_pointer(i0, 22182)) = i4;
l11:
      i3 = i3+1;
      i = i3;
      i4 = i3<i2;
      if (i4) goto l3_loop;
l16:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22482))+4);
      i2 = i2==0;
      if (!i2) goto l19;
      OOC_Package__ProcessPackage_Err(9, (Config_Parser__Node)i1);
l19:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 22583))+36);
      node = (Config_Parser__Node)i2;
      OOC_Package__ProcessPackage_SkipWS((void*)(OOC_INT32)&node);
      i2 = (OOC_INT32)node;
      i3 = OOC_Package__AtElement((Config_Parser__Node)i2, ((OOC_CHAR16[]){118,101,114,115,105,111,110,0}), 8);
      if (i3) goto l22;
      OOC_Package__ProcessPackage_Err(6, (Config_Parser__Node)i1);
      goto l23;
l22:
      i1 = (OOC_INT32)OOC_Package__ProcessPackage_ParseVersion((Config_Parser__Element)(_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 22706)))), &_td_Config_Parser__ElementDesc, 22706)));
      *(OOC_INT32*)((_check_pointer(i0, 22669))+8) = i1;
      i1 = (OOC_INT32)node;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 22737));
      node = (Config_Parser__Node)i1;
      OOC_Package__ProcessPackage_SkipWS((void*)(OOC_INT32)&node);
l23:
      i1 = (OOC_INT32)node;
      i2 = i1!=0;
      if (!i2) goto l26;
      OOC_Package__ProcessPackage_Err(4, (Config_Parser__Node)i1);
l26:
      return (OOC_Package__Library)i0;
      ;
    }

    
    OOC_Package__FileSet OOC_Package__ProcessPackage_ParseFileSet(Config_Parser__Element elem) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5;
      OOC_Package__FileSet fileSet;
      OOC_INT32 i;
      XML_Builder__Attribute att;
      Config_Parser__Node node;
      auto OOC_Package__File OOC_Package__ProcessPackage_ParseFileSet_ParseFile(Config_Parser__Element elem);
        
        OOC_Package__File OOC_Package__ProcessPackage_ParseFileSet_ParseFile(Config_Parser__Element elem) {
          register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
          Object__String name;
          Object__String destName;
          OOC_INT32 i;
          XML_Builder__Attribute att;
          Config_Parser__Node node;

          name = (Object__String)(OOC_INT32)0;
          destName = (Object__String)(OOC_INT32)0;
          i0 = (OOC_INT32)elem;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23462))+32);
          i = 0;
          i1 = *(OOC_INT32*)(_check_pointer(i1, 23471));
          i2 = 0<i1;
          if (i2) goto l3;
          i1=(OOC_INT32)0;i2=(OOC_INT32)0;
          goto l17;
l3:
          i2=0;i3=(OOC_INT32)0;i4=(OOC_INT32)0;
l4_loop:
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23502))+32);
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 23511))+4);
          i5 = _check_pointer(i5, 23516);
          i6 = OOC_ARRAY_LENGTH(i5, 0);
          i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i2, i6, OOC_UINT32, 23516))*4);
          att = (XML_Builder__Attribute)i5;
          i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 23538))+4);
          i6 = (
          _cmp16((const void*)(_check_pointer(i6, 23548)),(const void*)((OOC_CHAR16[]){110,97,109,101,0})))==0;
          if (i6) goto l11;
          i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 23622))+4);
          i6 = (
          _cmp16((const void*)(_check_pointer(i6, 23632)),(const void*)((OOC_CHAR16[]){100,101,115,116,45,110,97,109,101,0})))==0;
          if (i6) goto l9;
          OOC_Package__ProcessPackage_Err(3, (Config_Parser__Node)i0);
          i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 23819))+4);
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 23819))+4);
          i6 = OOC_ARRAY_LENGTH((_check_pointer(i6, 23829)), 0);
          i5 = (OOC_INT32)Msg__GetLStringPtr((void*)(_check_pointer(i5, 23829)), i6);
          i6 = (OOC_INT32)lastError;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 23772)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i6, "name", 5, (Msg__LStringPtr)i5);
          
          goto l12;
l9:
          i4 = (OOC_INT32)OOC_Package__StringAttr((XML_Builder__Attribute)i5);
          destName = (Object__String)i4;
          
          goto l12;
l11:
          i3 = (OOC_INT32)OOC_Package__StringAttr((XML_Builder__Attribute)i5);
          name = (Object__String)i3;
          
l12:
          i2 = i2+1;
          i = i2;
          i5 = i2<i1;
          if (i5) goto l4_loop;
l16:
          i1=i3;i2=i4;
l17:
          i3 = i1==(OOC_INT32)0;
          if (!i3) goto l20;
          OOC_Package__ProcessPackage_Err(5, (Config_Parser__Node)i0);
l20:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23975))+36);
          node = (Config_Parser__Node)i0;
          OOC_Package__ProcessPackage_SkipWS((void*)(OOC_INT32)&node);
          i0 = (OOC_INT32)node;
          i3 = i0!=(OOC_INT32)0;
          if (!i3) goto l23;
          OOC_Package__ProcessPackage_Err(4, (Config_Parser__Node)i0);
l23:
          i0 = (OOC_INT32)OOC_Package__NewFile((Object__String)i1, (Object__String)i2);
          return (OOC_Package__File)i0;
          ;
        }


      i0 = (OOC_INT32)OOC_Package__NewFileSet();
      fileSet = (OOC_Package__FileSet)i0;
      i1 = (OOC_INT32)elem;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 24230))+32);
      i = 0;
      i2 = *(OOC_INT32*)(_check_pointer(i2, 24239));
      i3 = 0<i2;
      if (!i3) goto l16;
      i3=0;
l3_loop:
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 24268))+32);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 24277))+4);
      i4 = _check_pointer(i4, 24282);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 24282))*4);
      att = (XML_Builder__Attribute)i4;
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 24302))+4);
      i5 = (
      _cmp16((const void*)(_check_pointer(i5, 24312)),(const void*)((OOC_CHAR16[]){115,111,117,114,99,101,45,100,105,114,0})))==0;
      if (i5) goto l10;
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 24401))+4);
      i5 = (
      _cmp16((const void*)(_check_pointer(i5, 24411)),(const void*)((OOC_CHAR16[]){100,101,115,116,45,100,105,114,0})))==0;
      if (i5) goto l8;
      OOC_Package__ProcessPackage_Err(3, (Config_Parser__Node)i1);
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 24596))+4);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 24596))+4);
      i5 = OOC_ARRAY_LENGTH((_check_pointer(i5, 24606)), 0);
      i4 = (OOC_INT32)Msg__GetLStringPtr((void*)(_check_pointer(i4, 24606)), i5);
      i5 = (OOC_INT32)lastError;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 24549)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i5, "name", 5, (Msg__LStringPtr)i4);
      goto l11;
l8:
      i4 = (OOC_INT32)OOC_Package__StringAttr((XML_Builder__Attribute)i4);
      *(OOC_INT32*)((_check_pointer(i0, 24449))+8) = i4;
      goto l11;
l10:
      i4 = (OOC_INT32)OOC_Package__StringAttr((XML_Builder__Attribute)i4);
      *(OOC_INT32*)((_check_pointer(i0, 24352))+4) = i4;
l11:
      i3 = i3+1;
      i = i3;
      i4 = i3<i2;
      if (i4) goto l3_loop;
l16:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24651))+4);
      i2 = i2==0;
      if (!i2) goto l19;
      OOC_Package__ProcessPackage_Err(10, (Config_Parser__Node)i1);
l19:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 24750))+36);
      node = (Config_Parser__Node)i1;
      OOC_Package__ProcessPackage_SkipWS((void*)(OOC_INT32)&node);
      i1 = (OOC_INT32)node;
      i2 = i1!=0;
      if (!i2) goto l36;
      {register OOC_INT32 h0=i0;i0=i1;i1=h0;}
l23_loop:
      i2 = OOC_Package__AtElement((Config_Parser__Node)i0, ((OOC_CHAR16[]){102,105,108,101,45,115,101,116,0}), 9);
      if (i2) goto l30;
      i2 = OOC_Package__AtElement((Config_Parser__Node)i0, ((OOC_CHAR16[]){102,105,108,101,0}), 5);
      if (i2) goto l28;
      OOC_Package__ProcessPackage_Err(12, (Config_Parser__Node)i0);
      i0 = (OOC_INT32)node;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 25160));
      node = (Config_Parser__Node)i0;
      i0=i1;
      goto l31;
l28:
      i0 = (OOC_INT32)OOC_Package__ProcessPackage_ParseFileSet_ParseFile((Config_Parser__Element)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 25037)))), &_td_Config_Parser__ElementDesc, 25037)));
      i1 = (OOC_INT32)fileSet;
      OOC_Package__FileSetDesc_Append((OOC_Package__FileSet)i1, (OOC_Package__FileData)i0);
      i0 = (OOC_INT32)node;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 25071));
      node = (Config_Parser__Node)i0;
      i0=i1;
      goto l31;
l30:
      i0 = (OOC_INT32)OOC_Package__ProcessPackage_ParseFileSet((Config_Parser__Element)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 24902)))), &_td_Config_Parser__ElementDesc, 24902)));
      OOC_Package__FileSetDesc_Append((OOC_Package__FileSet)i1, (OOC_Package__FileData)i0);
      i0 = (OOC_INT32)node;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 24936));
      node = (Config_Parser__Node)i0;
      i0=i1;
l31:
      OOC_Package__ProcessPackage_SkipWS((void*)(OOC_INT32)&node);
      i1 = (OOC_INT32)node;
      i2 = i1!=0;
      if (!i2) goto l36;
      {register OOC_INT32 h0=i0;i0=i1;i1=h0;}
      goto l23_loop;
l36:
      return (OOC_Package__FileSet)i0;
      ;
    }


  i0 = (OOC_INT32)root;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25282))+28);
  i1 = (
  _cmp16((const void*)(_check_pointer(i1, 25287)),(const void*)((OOC_CHAR16[]){112,97,99,107,97,103,101,0})))!=0;
  if (!i1) goto l3;
  OOC_Package__ProcessPackage_Err(1, (Config_Parser__Node)i0);
  i0 = (OOC_INT32)Msg__GetLStringPtr(((OOC_CHAR16[]){112,97,99,107,97,103,101,0}), 8);
  i1 = (OOC_INT32)lastError;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 25359)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i1, "name", 5, (Msg__LStringPtr)i0);
l3:
  i0 = (OOC_INT32)OOC_Package__NewPackage();
  pkg = (OOC_Package__Package)i0;
  i0 = (OOC_INT32)root;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25475))+32);
  i = 0;
  i0 = *(OOC_INT32*)(_check_pointer(i0, 25484));
  i1 = 0<i0;
  if (!i1) goto l15;
  i1=0;
l6_loop:
  i2 = (OOC_INT32)root;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 25511))+32);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 25520))+4);
  i3 = _check_pointer(i3, 25525);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i1, i4, OOC_UINT32, 25525))*4);
  att = (XML_Builder__Attribute)i1;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 25543))+4);
  i3 = (
  _cmp16((const void*)(_check_pointer(i3, 25553)),(const void*)((OOC_CHAR16[]){110,97,109,101,0})))==0;
  if (i3) goto l9;
  OOC_Package__ProcessPackage_Err(3, (Config_Parser__Node)i2);
  i1 = (OOC_INT32)att;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 25719))+4);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 25719))+4);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 25729)), 0);
  i1 = (OOC_INT32)Msg__GetLStringPtr((void*)(_check_pointer(i1, 25729)), i2);
  i2 = (OOC_INT32)lastError;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 25672)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i2, "name", 5, (Msg__LStringPtr)i1);
  goto l10;
l9:
  i2 = (OOC_INT32)pkg;
  i1 = (OOC_INT32)OOC_Package__StringAttr((XML_Builder__Attribute)i1);
  *(OOC_INT32*)((_check_pointer(i2, 25581))+8) = i1;
l10:
  i1 = i;
  i1 = i1+1;
  i = i1;
  i2 = i1<i0;
  if (i2) goto l6_loop;
l15:
  i0 = (OOC_INT32)pkg;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25764))+8);
  i0 = i0==0;
  if (!i0) goto l18;
  i0 = (OOC_INT32)root;
  OOC_Package__ProcessPackage_Err(5, (Config_Parser__Node)i0);
l18:
  i0 = (OOC_INT32)root;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25851))+36);
  node = (Config_Parser__Node)i0;
  OOC_Package__ProcessPackage_SkipWS((void*)(OOC_INT32)&node);
  i0 = (OOC_INT32)node;
  i1 = OOC_Package__AtElement((Config_Parser__Node)i0, ((OOC_CHAR16[]){118,101,114,115,105,111,110,0}), 8);
  if (i1) goto l21;
  i0 = (OOC_INT32)root;
  OOC_Package__ProcessPackage_Err(6, (Config_Parser__Node)i0);
  goto l22;
l21:
  i1 = (OOC_INT32)pkg;
  i0 = (OOC_INT32)OOC_Package__ProcessPackage_ParseVersion((Config_Parser__Element)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 25964)))), &_td_Config_Parser__ElementDesc, 25964)));
  *(OOC_INT32*)((_check_pointer(i1, 25927))+12) = i0;
  i0 = (OOC_INT32)node;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 25993));
  node = (Config_Parser__Node)i0;
  OOC_Package__ProcessPackage_SkipWS((void*)(OOC_INT32)&node);
l22:
  i0 = (OOC_INT32)node;
  i0 = OOC_Package__AtElement((Config_Parser__Node)i0, ((OOC_CHAR16[]){114,101,113,117,105,114,101,115,0}), 9);
  if (!i0) goto l30;
l25_loop:
  i0 = (OOC_INT32)node;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 26144));
  node = (Config_Parser__Node)i0;
  OOC_Package__ProcessPackage_SkipWS((void*)(OOC_INT32)&node);
  i0 = (OOC_INT32)node;
  i0 = OOC_Package__AtElement((Config_Parser__Node)i0, ((OOC_CHAR16[]){114,101,113,117,105,114,101,115,0}), 9);
  if (i0) goto l25_loop;
l30:
  i0 = (OOC_INT32)node;
  i1 = OOC_Package__AtElement((Config_Parser__Node)i0, ((OOC_CHAR16[]){111,112,116,105,111,110,115,0}), 8);
  if (!i1) goto l33;
  i1 = (OOC_INT32)pkg;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 26273));
  i2 = (OOC_INT32)OOC_Config__options;
  i3 = (OOC_INT32)errList;
  i4 = (OOC_INT32)errorListener;
  i5 = (OOC_INT32)OOC_Package__stringType;
  OOC_Package__ParseKeyValue((Config_Parser__Element)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 26260)))), &_td_Config_Parser__ElementDesc, 26260)), (ADT_ArrayList__ArrayList)i1, (Config_Section_Options__Section)i2, (Object__String)i5, (XML_Locator__ErrorListener)i4, (OOC_Error__List)i3);
  i0 = (OOC_INT32)node;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 26374));
  node = (Config_Parser__Node)i0;
  OOC_Package__ProcessPackage_SkipWS((void*)(OOC_INT32)&node);
l33:
  i0 = (OOC_INT32)node;
  i1 = OOC_Package__AtElement((Config_Parser__Node)i0, ((OOC_CHAR16[]){112,114,97,103,109,97,115,0}), 8);
  if (!i1) goto l36;
  i1 = (OOC_INT32)pkg;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 26503))+4);
  i2 = (OOC_INT32)OOC_Config__pragmas;
  i3 = (OOC_INT32)errList;
  i4 = (OOC_INT32)errorListener;
  i5 = (OOC_INT32)OOC_Package__stringType;
  OOC_Package__ParseKeyValue((Config_Parser__Element)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 26490)))), &_td_Config_Parser__ElementDesc, 26490)), (ADT_ArrayList__ArrayList)i1, (Config_Section_Options__Section)i2, (Object__String)i5, (XML_Locator__ErrorListener)i4, (OOC_Error__List)i3);
  i0 = (OOC_INT32)node;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 26604));
  node = (Config_Parser__Node)i0;
  OOC_Package__ProcessPackage_SkipWS((void*)(OOC_INT32)&node);
l36:
  i0 = (OOC_INT32)node;
  i0 = OOC_Package__AtElement((Config_Parser__Node)i0, ((OOC_CHAR16[]){108,105,98,114,97,114,121,0}), 8);
  if (!i0) goto l44;
l39_loop:
  i0 = (OOC_INT32)node;
  i0 = (OOC_INT32)OOC_Package__ProcessPackage_ParseLibrary((Config_Parser__Element)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 26739)))), &_td_Config_Parser__ElementDesc, 26739)));
  i1 = (OOC_INT32)pkg;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 26698))+16);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 26698))+16);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 26706)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i1, (Object__Object)i0);
  i0 = (OOC_INT32)node;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 26769));
  node = (Config_Parser__Node)i0;
  OOC_Package__ProcessPackage_SkipWS((void*)(OOC_INT32)&node);
  i0 = (OOC_INT32)node;
  i0 = OOC_Package__AtElement((Config_Parser__Node)i0, ((OOC_CHAR16[]){108,105,98,114,97,114,121,0}), 8);
  if (i0) goto l39_loop;
l44:
  i0 = (OOC_INT32)node;
  i0 = OOC_Package__AtElement((Config_Parser__Node)i0, ((OOC_CHAR16[]){101,120,101,99,117,116,97,98,108,101,0}), 11);
  if (!i0) goto l52;
l47_loop:
  i0 = (OOC_INT32)node;
  i0 = (OOC_INT32)OOC_Package__ProcessPackage_ParseExecutable((Config_Parser__Element)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 26908)))), &_td_Config_Parser__ElementDesc, 26908)));
  i1 = (OOC_INT32)pkg;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 26861))+20);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 26861))+20);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 26872)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i1, (Object__Object)i0);
  i0 = (OOC_INT32)node;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 26938));
  node = (Config_Parser__Node)i0;
  OOC_Package__ProcessPackage_SkipWS((void*)(OOC_INT32)&node);
  i0 = (OOC_INT32)node;
  i0 = OOC_Package__AtElement((Config_Parser__Node)i0, ((OOC_CHAR16[]){101,120,101,99,117,116,97,98,108,101,0}), 11);
  if (i0) goto l47_loop;
l52:
  i0 = (OOC_INT32)pkg;
  i1 = (OOC_INT32)OOC_Package__NewFileSet();
  *(OOC_INT32*)((_check_pointer(i0, 26986))+24) = i1;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27019))+24);
  *(OOC_INT32*)((_check_pointer(i1, 27027))+4) = ((OOC_INT32)_c6);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27053))+24);
  *(OOC_INT32*)((_check_pointer(i0, 27061))+8) = ((OOC_INT32)_c7);
  i0 = (OOC_INT32)node;
  i1 = OOC_Package__AtElement((Config_Parser__Node)i0, ((OOC_CHAR16[]){102,105,108,101,45,115,101,116,0}), 9);
  if (!i1) goto l61;
l56_loop:
  i0 = (OOC_INT32)OOC_Package__ProcessPackage_ParseFileSet((Config_Parser__Element)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 27169)))), &_td_Config_Parser__ElementDesc, 27169)));
  i1 = (OOC_INT32)pkg;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 27128))+24);
  OOC_Package__FileSetDesc_Append((OOC_Package__FileSet)i1, (OOC_Package__FileData)i0);
  i0 = (OOC_INT32)node;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 27199));
  node = (Config_Parser__Node)i0;
  OOC_Package__ProcessPackage_SkipWS((void*)(OOC_INT32)&node);
  i0 = (OOC_INT32)node;
  i1 = OOC_Package__AtElement((Config_Parser__Node)i0, ((OOC_CHAR16[]){102,105,108,101,45,115,101,116,0}), 9);
  if (i1) goto l56_loop;
l61:
  i1 = i0!=0;
  if (!i1) goto l64;
  OOC_Package__ProcessPackage_Err(4, (Config_Parser__Node)i0);
l64:
  i0 = (OOC_INT32)errList;
  i0 = *(OOC_INT32*)(_check_pointer(i0, 27325));
  i0 = i0!=0;
  if (!i0) goto l67;
  pkg = (OOC_Package__Package)0;
l67:
  i0 = (OOC_INT32)pkg;
  return (OOC_Package__Package)i0;
  ;
}

static OOC_Package__Repository OOC_Package__ProcessRepository(Config_Parser__Element root, XML_Locator__ErrorListener errorListener, OOC_Error__List errList) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  Msg__Msg lastError;
  OOC_Package__Repository rep;
  Config_Parser__Node node;
  auto void OOC_Package__ProcessRepository_Err(OOC_INT32 code, Config_Parser__Node xmlNode);
  auto void OOC_Package__ProcessRepository_SkipWS(Config_Parser__Node *node);
  auto Object__String OOC_Package__ProcessRepository_ParseInstalled(Config_Parser__Element elem);
    
    void OOC_Package__ProcessRepository_Err(OOC_INT32 code, Config_Parser__Node xmlNode) {
      register OOC_INT32 i0,i1,i2,i3;

      i0 = (OOC_INT32)xmlNode;
      i1 = (OOC_INT32)errorListener;
      i2 = (OOC_INT32)OOC_Package__packageContext;
      i3 = code;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 27768)))), XML_Locator__ErrorListenerDesc_Error)),XML_Locator__ErrorListenerDesc_Error)((XML_Locator__ErrorListener)i1, (XML_Error__Context)i2, i3, 0u, (void*)((_check_pointer(i0, 27850))+4));
      lastError = (Msg__Msg)i0;
      i1 = (OOC_INT32)errList;
      OOC_Error__ListDesc_Append((OOC_Error__List)i1, (Msg__Msg)i0);
      return;
      ;
    }

    
    void OOC_Package__ProcessRepository_SkipWS(Config_Parser__Node *node) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)*node;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l3;
      i1=0u;
      goto l5;
l3:
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 27991)))), &_td_Config_Parser__CharDataDesc);
      
l5:
      if (!i1) goto l19;
      
l7_loop:
      i1 = Config_Parser__NodeDesc_IsWhitespace((Config_Parser__Node)i0);
      i1 = !i1;
      if (!i1) goto l10;
      OOC_Package__ProcessRepository_Err(2, (Config_Parser__Node)i0);
l10:
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 28122));
      *node = (Config_Parser__Node)i0;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l13;
      i1=0u;
      goto l15;
l13:
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 27991)))), &_td_Config_Parser__CharDataDesc);
      
l15:
      if (i1) goto l7_loop;
l19:
      return;
      ;
    }

    
    Object__String OOC_Package__ProcessRepository_ParseInstalled(Config_Parser__Element elem) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5;
      Object__String package;
      OOC_INT32 i;
      XML_Builder__Attribute att;

      package = (Object__String)(OOC_INT32)0;
      i0 = (OOC_INT32)elem;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28392))+32);
      i = 0;
      i1 = *(OOC_INT32*)(_check_pointer(i1, 28401));
      i2 = 0<i1;
      if (i2) goto l3;
      i1=(OOC_INT32)0;
      goto l13;
l3:
      i2=0;i3=(OOC_INT32)0;
l4_loop:
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28430))+32);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 28439))+4);
      i4 = _check_pointer(i4, 28444);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i2, i5, OOC_UINT32, 28444))*4);
      att = (XML_Builder__Attribute)i4;
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 28464))+4);
      i5 = (
      _cmp16((const void*)(_check_pointer(i5, 28474)),(const void*)((OOC_CHAR16[]){112,97,99,107,97,103,101,0})))==0;
      if (i5) goto l7;
      OOC_Package__ProcessRepository_Err(3, (Config_Parser__Node)i0);
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 28650))+4);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 28650))+4);
      i5 = OOC_ARRAY_LENGTH((_check_pointer(i5, 28660)), 0);
      i4 = (OOC_INT32)Msg__GetLStringPtr((void*)(_check_pointer(i4, 28660)), i5);
      i5 = (OOC_INT32)lastError;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 28603)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i5, "name", 5, (Msg__LStringPtr)i4);
      
      goto l8;
l7:
      i3 = (OOC_INT32)OOC_Package__StringAttr((XML_Builder__Attribute)i4);
      package = (Object__String)i3;
      
l8:
      i2 = i2+1;
      i = i2;
      i4 = i2<i1;
      if (i4) goto l4_loop;
l12:
      i1=i3;
l13:
      i2 = i1==(OOC_INT32)0;
      if (i2) goto l16;
      return (Object__String)i1;
      goto l17;
l16:
      OOC_Package__ProcessRepository_Err(5, (Config_Parser__Node)i0);
      return (Object__String)(OOC_INT32)0;
l17:
      _failed_function(28173); return 0;
      ;
    }


  i0 = (OOC_INT32)root;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28872))+28);
  i1 = (
  _cmp16((const void*)(_check_pointer(i1, 28877)),(const void*)((OOC_CHAR16[]){114,101,112,111,115,105,116,111,114,121,0})))!=0;
  if (!i1) goto l3;
  OOC_Package__ProcessRepository_Err(1, (Config_Parser__Node)i0);
  i0 = (OOC_INT32)Msg__GetLStringPtr(((OOC_CHAR16[]){114,101,112,111,115,105,116,111,114,121,0}), 11);
  i1 = (OOC_INT32)lastError;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 28952)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i1, "name", 5, (Msg__LStringPtr)i0);
l3:
  i0 = (OOC_INT32)OOC_Package__NewRepository();
  rep = (OOC_Package__Repository)i0;
  i0 = (OOC_INT32)root;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29068))+36);
  node = (Config_Parser__Node)i0;
  OOC_Package__ProcessRepository_SkipWS((void*)(OOC_INT32)&node);
  i0 = (OOC_INT32)node;
  i1 = OOC_Package__AtElement((Config_Parser__Node)i0, ((OOC_CHAR16[]){105,110,115,116,97,108,108,101,100,0}), 10);
  if (!i1) goto l12;
l7_loop:
  i0 = (OOC_INT32)OOC_Package__ProcessRepository_ParseInstalled((Config_Parser__Element)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 29196)))), &_td_Config_Parser__ElementDesc, 29196)));
  i1 = (OOC_INT32)rep;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 29147))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 29147))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 29161)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i1, (Object__Object)i0);
  i0 = (OOC_INT32)node;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 29226));
  node = (Config_Parser__Node)i0;
  OOC_Package__ProcessRepository_SkipWS((void*)(OOC_INT32)&node);
  i0 = (OOC_INT32)node;
  i1 = OOC_Package__AtElement((Config_Parser__Node)i0, ((OOC_CHAR16[]){105,110,115,116,97,108,108,101,100,0}), 10);
  if (i1) goto l7_loop;
l12:
  i1 = OOC_Package__AtElement((Config_Parser__Node)i0, ((OOC_CHAR16[]){111,112,116,105,111,110,115,0}), 8);
  if (!i1) goto l15;
  i1 = (OOC_INT32)rep;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 29355));
  i2 = (OOC_INT32)OOC_Config__options;
  i3 = (OOC_INT32)errList;
  i4 = (OOC_INT32)errorListener;
  i5 = (OOC_INT32)OOC_Package__stringType;
  OOC_Package__ParseKeyValue((Config_Parser__Element)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 29342)))), &_td_Config_Parser__ElementDesc, 29342)), (ADT_ArrayList__ArrayList)i1, (Config_Section_Options__Section)i2, (Object__String)i5, (XML_Locator__ErrorListener)i4, (OOC_Error__List)i3);
  i0 = (OOC_INT32)node;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 29456));
  node = (Config_Parser__Node)i0;
  OOC_Package__ProcessRepository_SkipWS((void*)(OOC_INT32)&node);
l15:
  i0 = (OOC_INT32)node;
  i1 = OOC_Package__AtElement((Config_Parser__Node)i0, ((OOC_CHAR16[]){112,114,97,103,109,97,115,0}), 8);
  if (!i1) goto l18;
  i1 = (OOC_INT32)rep;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 29585))+4);
  i2 = (OOC_INT32)OOC_Config__pragmas;
  i3 = (OOC_INT32)errList;
  i4 = (OOC_INT32)errorListener;
  i5 = (OOC_INT32)OOC_Package__stringType;
  OOC_Package__ParseKeyValue((Config_Parser__Element)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 29572)))), &_td_Config_Parser__ElementDesc, 29572)), (ADT_ArrayList__ArrayList)i1, (Config_Section_Options__Section)i2, (Object__String)i5, (XML_Locator__ErrorListener)i4, (OOC_Error__List)i3);
  i0 = (OOC_INT32)node;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 29686));
  node = (Config_Parser__Node)i0;
  OOC_Package__ProcessRepository_SkipWS((void*)(OOC_INT32)&node);
l18:
  i0 = (OOC_INT32)node;
  i1 = i0!=0;
  if (!i1) goto l21;
  OOC_Package__ProcessRepository_Err(4, (Config_Parser__Node)i0);
l21:
  i0 = (OOC_INT32)errList;
  i0 = *(OOC_INT32*)(_check_pointer(i0, 29817));
  i0 = i0!=0;
  if (!i0) goto l24;
  rep = (OOC_Package__Repository)0;
l24:
  i0 = (OOC_INT32)rep;
  return (OOC_Package__Repository)i0;
  ;
}

static OOC_Repository__PkgInfo OOC_Package__ParseFile(volatile Object__String fileName, volatile OOC_CHAR8 requirePackage, volatile OOC_Error__List *errList) {
  register OOC_INT32 i0,i1,i2;
  volatile Config_Parser__Parser p;
  jmp_buf _target0;
  Exception__Context _context0;

  i0 = (OOC_INT32)fileName;
  OOC_Logger__ReadFileName((Object__String)i0);
  {
    Exception__PushContext(&_context0, &_target0);
    if (!setjmp(_target0)) goto l7;
    Exception__PopContext(1);
    i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG(((OOC_INT32)Exception__Current()))), &_td_IO__FileNotFoundDesc);
    if (i0) goto l5;
    Exception__ActivateContext();
    goto l6;
l5:
    return (OOC_Repository__PkgInfo)0;
l6:
    Exception__Clear();
    goto l20;
l7:
    i0 = (OOC_INT32)Config_Parser__NewFile((Object__String)i0);
    p = (Config_Parser__Parser)i0;
    Config_Parser__ParserDesc_ParseDocument((Config_Parser__Parser)i0);
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30197))+8);
    i1 = *(OOC_INT32*)(_check_pointer(i1, 30205));
    i1 = i1==0;
    if (i1) goto l10;
    i1 = (OOC_INT32)*errList;
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30493))+8);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 30480)))), Msg__MsgListDesc_AppendList)),Msg__MsgListDesc_AppendList)((Msg__MsgList)i1, (Msg__MsgList)i0);
    Exception__PopContext(1);
    return (OOC_Repository__PkgInfo)0;
    goto l19;
l10:
    i1 = requirePackage;
    i1 = !i1;
    if (i1) goto l13;
    i1=0u;
    goto l15;
l13:
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30256))+12);
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 30261))+28);
    i1 = (
    _cmp16((const void*)(_check_pointer(i1, 30266)),(const void*)((OOC_CHAR16[]){114,101,112,111,115,105,116,111,114,121,0})))==0;
    
l15:
    if (i1) goto l17;
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30415))+16);
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30407))+12);
    i2 = (OOC_INT32)*errList;
    i0 = (OOC_INT32)OOC_Package__ProcessPackage((Config_Parser__Element)i0, (XML_Locator__ErrorListener)i1, (OOC_Error__List)i2);
    Exception__PopContext(1);
    return (OOC_Repository__PkgInfo)i0;
    goto l19;
l17:
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30335))+16);
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30327))+12);
    i2 = (OOC_INT32)*errList;
    i0 = (OOC_INT32)OOC_Package__ProcessRepository((Config_Parser__Element)i0, (XML_Locator__ErrorListener)i1, (OOC_Error__List)i2);
    Exception__PopContext(1);
    return (OOC_Repository__PkgInfo)i0;
l19:
    Exception__PopContext(1);
l20:;
  }
  _failed_function(29916); return 0;
  ;
}

OOC_Package__Package OOC_Package__GetPackage(Object__String pkgName, OOC_Repository__Repository *rep) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)OOC_Config__repositories;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30779))+4);
  *rep = (OOC_Repository__Repository)i0;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l19;
  i1 = (OOC_INT32)pkgName;
  
l3_loop:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30831))+8);
  i2 = i2!=(OOC_INT32)0;
  if (i2) goto l6;
  i2=0u;
  goto l8;
l6:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30866))+8);
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 30879)))), &_td_OOC_Package__PackageDesc);
  
l8:
  if (i2) goto l10;
  i2=0u;
  goto l12;
l10:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30905))+8);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30905))+8);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 30918)))), &_td_OOC_Package__PackageDesc, 30918)), 30926))+8);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 30918)))), &_td_OOC_Package__PackageDesc, 30918)), 30926))+8);
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 30931)))), Object__StringDesc_Equals)),Object__StringDesc_Equals)((Object__String)i2, (Object__Object)i1);
  
l12:
  if (!i2) goto l14;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30971))+8);
  return (OOC_Package__Package)(_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 30984)))), &_td_OOC_Package__PackageDesc, 30984));
l14:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 31021));
  *rep = (OOC_Repository__Repository)i0;
  i2 = i0!=(OOC_INT32)0;
  if (i2) goto l3_loop;
l19:
  return (OOC_Package__Package)(OOC_INT32)0;
  ;
}

OOC_CHAR8 OOC_Package__ParseMetaData(Config_Section_Options__Section options, Config_Section_Options__Section pragmas) {
  register OOC_INT32 i0,i1;
  OOC_Error__List errList;
  auto OOC_CHAR8 OOC_Package__ParseMetaData_Parse(OOC_Repository__Repository rep);
    
    OOC_CHAR8 OOC_Package__ParseMetaData_Parse(OOC_Repository__Repository rep) {
      register OOC_INT32 i0,i1,i2;
      URI__URI uri;
      OOC_Repository__PkgInfo pkg;

      i0 = (OOC_INT32)rep;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l15;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 31392));
      i1 = OOC_Package__ParseMetaData_Parse((OOC_Repository__Repository)i1);
      if (!i1) goto l15;
      i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 31427)))), OOC_Repository__RepositoryDesc_GetResource)),OOC_Repository__RepositoryDesc_GetResource)((OOC_Repository__Repository)i0, "", 1, "pkginfo.xml", 12);
      uri = (URI__URI)i1;
      i2 = i1!=(OOC_INT32)0;
      if (!i2) goto l15;
      i1 = (OOC_INT32)URI_Scheme_File__URIDesc_GetPath((URI_Scheme_File__URI)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 31529)))), &_td_URI_Scheme_File__URIDesc, 31529)));
      i1 = (OOC_INT32)OOC_Package__ParseFile((Object__String)i1, 0u, (void*)(OOC_INT32)&errList);
      pkg = (OOC_Repository__PkgInfo)i1;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 31577)))), OOC_Repository__RepositoryDesc_SetPackageInfo)),OOC_Repository__RepositoryDesc_SetPackageInfo)((OOC_Repository__Repository)i0, (OOC_Repository__PkgInfo)i1);
      i0 = i1!=(OOC_INT32)0;
      if (!i0) goto l9;
      i0 = (OOC_INT32)options;
      i2 = (OOC_INT32)pragmas;
      OOC_Package__MergeConfig((OOC_Repository__PkgInfo)i1, (Config_Section_Options__Section)i0, (Config_Section_Options__Section)i2);
l9:
      i0 = (OOC_INT32)errList;
      i0 = *(OOC_INT32*)(_check_pointer(i0, 31721));
      i0 = i0!=0;
      if (!i0) goto l15;
      return 0u;
l15:
      return 1u;
      ;
    }


  i0 = (OOC_INT32)OOC_Error__NewList((Object__String)((OOC_INT32)_c8));
  errList = (OOC_Error__List)i0;
  i0 = (OOC_INT32)OOC_Config__repositories;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31942))+4);
  i0 = OOC_Package__ParseMetaData_Parse((OOC_Repository__Repository)i0);
  i0 = (OOC_INT32)IO_StdChannels__stdout;
  i1 = (OOC_INT32)errList;
  OOC_Error__ListDesc_Write((OOC_Error__List)i1, (IO__ByteChannel)i0);
  i0 = OOC_Error__ListDesc_NoErrors((OOC_Error__List)i1);
  return i0;
  ;
}

static void OOC_Package__WriteKeyValue(XML_Writer__Writer w, const OOC_CHAR8 tag__ref[], OOC_LEN tag_0d, ADT_ArrayList__ArrayList list) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_ALLOCATE_VPAR(tag,OOC_CHAR8 ,tag_0d)
  OOC_INT32 i;
  OOC_Package__KeyValue kv;
  Config__Variable v;
  OOC_CHAR8 type[32];

  OOC_INITIALIZE_VPAR(tag__ref,tag,OOC_CHAR8 ,tag_0d)
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32269)))), XML_Writer__WriterDesc_StartTagLatin1)),XML_Writer__WriterDesc_StartTagLatin1)((XML_Writer__Writer)i0, (void*)(OOC_INT32)tag, tag_0d, 0u);
  i1 = (OOC_INT32)list;
  i = 0;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 32320))+4);
  i3 = 0<i2;
  if (!i3) goto l20;
  i3=0;
l3_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 32347));
  i4 = _check_pointer(i4, 32353);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 32353))*4);
  i4 = _type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 32357)))), &_td_OOC_Package__KeyValueDesc, 32357);
  kv = (OOC_Package__KeyValue)i4;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32375)))), XML_Writer__WriterDesc_StartTag)),XML_Writer__WriterDesc_StartTag)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){100,101,102,105,110,101,0}), 7, 1u);
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 32431));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32409)))), XML_Writer__WriterDesc_AttrObject)),XML_Writer__WriterDesc_AttrObject)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){110,97,109,101,0}), 5, (Object__String)i5);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 32451))+4);
  v = (Config__Variable)i5;
  i6 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 32471)))), &_td_Config__StringVarDesc);
  if (i6) goto l14;
  i6 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 32529)))), &_td_Config__BooleanVarDesc);
  if (i6) goto l12;
  i6 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 32589)))), &_td_Config__IntegerVarDesc);
  if (i6) goto l10;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 32586)))), 32586);
  goto l15;
l10:
  _copy_8((const void*)"integer",(void*)(OOC_INT32)type,32);
  goto l15;
l12:
  _copy_8((const void*)"boolean",(void*)(OOC_INT32)type,32);
  goto l15;
l14:
  _copy_8((const void*)"string",(void*)(OOC_INT32)type,32);
l15:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32658)))), XML_Writer__WriterDesc_AttrStringLatin1)),XML_Writer__WriterDesc_AttrStringLatin1)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){116,121,112,101,0}), 5, (void*)(OOC_INT32)type, 32);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 32713))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32698)))), XML_Writer__WriterDesc_WriteObject)),XML_Writer__WriterDesc_WriteObject)((XML_Writer__Writer)i0, (Object__Object)i4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32729)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i0);
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l3_loop;
l20:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32765)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i0);
  return;
  ;
}

void OOC_Package__WritePackage(OOC_Package__Package pkg, Object__String targetDir) {
  register OOC_INT32 i0,i1,i2,i3;
  ADT_StringBuffer__StringBuffer b;
  Object__String fileName;
  IO__ByteChannel f;
  XML_Writer__Writer w;
  OOC_INT32 i;
  auto void OOC_Package__WritePackage_WriteVersion(XML_Writer__Writer w, OOC_Package__Version version);
  auto void OOC_Package__WritePackage_WriteLibrary(XML_Writer__Writer w, OOC_Package__Library library);
  auto void OOC_Package__WritePackage_WriteExecutable(XML_Writer__Writer w, OOC_Package__Executable executable);
  auto void OOC_Package__WritePackage_WriteFileSet(XML_Writer__Writer w, OOC_Package__FileSet fileSet);
    
    void OOC_Package__WritePackage_WriteVersion(XML_Writer__Writer w, OOC_Package__Version version) {
      register OOC_INT32 i0,i1,i2;

      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33084)))), XML_Writer__WriterDesc_StartTag)),XML_Writer__WriterDesc_StartTag)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){118,101,114,115,105,111,110,0}), 8, 0u);
      i1 = (OOC_INT32)version;
      i2 = *(OOC_INT32*)(_check_pointer(i1, 33147));
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33120)))), XML_Writer__WriterDesc_AttrInt)),XML_Writer__WriterDesc_AttrInt)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){99,117,114,114,101,110,116,0}), 8, i2);
      i2 = *(OOC_INT32*)((_check_pointer(i1, 33175))+4);
      i2 = i2>0;
      if (!i2) goto l3;
      i2 = *(OOC_INT32*)((_check_pointer(i1, 33222))+4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33199)))), XML_Writer__WriterDesc_AttrInt)),XML_Writer__WriterDesc_AttrInt)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){97,103,101,0}), 4, i2);
l3:
      i1 = *(OOC_INT32*)((_check_pointer(i1, 33274))+8);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33246)))), XML_Writer__WriterDesc_AttrInt)),XML_Writer__WriterDesc_AttrInt)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){114,101,118,105,115,105,111,110,0}), 9, i1);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33293)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i0);
      return;
      ;
    }

    
    void OOC_Package__WritePackage_WriteLibrary(XML_Writer__Writer w, OOC_Package__Library library) {
      register OOC_INT32 i0,i1,i2;

      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33421)))), XML_Writer__WriterDesc_StartTag)),XML_Writer__WriterDesc_StartTag)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){108,105,98,114,97,114,121,0}), 8, 0u);
      i1 = (OOC_INT32)library;
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 33484));
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33457)))), XML_Writer__WriterDesc_AttrObject)),XML_Writer__WriterDesc_AttrObject)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){110,97,109,101,0}), 5, (Object__String)i2);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 33533))+4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33499)))), XML_Writer__WriterDesc_AttrObject)),XML_Writer__WriterDesc_AttrObject)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){109,97,105,110,45,109,111,100,117,108,101,0}), 12, (Object__String)i2);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 33576))+8);
      OOC_Package__WritePackage_WriteVersion((XML_Writer__Writer)i0, (OOC_Package__Version)i1);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33594)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i0);
      return;
      ;
    }

    
    void OOC_Package__WritePackage_WriteExecutable(XML_Writer__Writer w, OOC_Package__Executable executable) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33731)))), XML_Writer__WriterDesc_StartTag)),XML_Writer__WriterDesc_StartTag)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){101,120,101,99,117,116,97,98,108,101,0}), 11, 0u);
      i1 = (OOC_INT32)executable;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 33807));
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33770)))), XML_Writer__WriterDesc_AttrObject)),XML_Writer__WriterDesc_AttrObject)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){109,97,105,110,45,109,111,100,117,108,101,0}), 12, (Object__String)i1);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33828)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i0);
      return;
      ;
    }

    
    void OOC_Package__WritePackage_WriteFileSet(XML_Writer__Writer w, OOC_Package__FileSet fileSet) {
      register OOC_INT32 i0,i1,i2;
      OOC_Package__FileData ptr;
      auto void OOC_Package__WritePackage_WriteFileSet_WriteFile(XML_Writer__Writer w, OOC_Package__File file);
        
        void OOC_Package__WritePackage_WriteFileSet_WriteFile(XML_Writer__Writer w, OOC_Package__File file) {
          register OOC_INT32 i0,i1,i2;

          i0 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34051)))), XML_Writer__WriterDesc_StartTag)),XML_Writer__WriterDesc_StartTag)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){102,105,108,101,0}), 5, 0u);
          i1 = (OOC_INT32)file;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34110))+4);
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34086)))), XML_Writer__WriterDesc_AttrObject)),XML_Writer__WriterDesc_AttrObject)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){110,97,109,101,0}), 5, (Object__String)i2);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34134))+8);
          i2 = i2!=(OOC_INT32)0;
          if (!i2) goto l3;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34196))+8);
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34167)))), XML_Writer__WriterDesc_AttrObject)),XML_Writer__WriterDesc_AttrObject)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){100,101,115,116,45,110,97,109,101,0}), 10, (Object__String)i1);
l3:
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34230)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i0);
          return;
          ;
        }


      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34296)))), XML_Writer__WriterDesc_StartTag)),XML_Writer__WriterDesc_StartTag)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){102,105,108,101,45,115,101,116,0}), 9, 0u);
      i1 = (OOC_INT32)fileSet;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34366))+4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34333)))), XML_Writer__WriterDesc_AttrObject)),XML_Writer__WriterDesc_AttrObject)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){115,111,117,114,99,101,45,100,105,114,0}), 11, (Object__String)i2);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34396))+8);
      i2 = i2!=(OOC_INT32)0;
      if (!i2) goto l3;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34457))+8);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34426)))), XML_Writer__WriterDesc_AttrObject)),XML_Writer__WriterDesc_AttrObject)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){100,101,115,116,45,100,105,114,0}), 9, (Object__String)i2);
l3:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34499))+12);
      ptr = (OOC_Package__FileData)i0;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l19;
l6_loop:
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34549)))), &_td_OOC_Package__FileSetDesc);
      if (i1) goto l13;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34607)))), &_td_OOC_Package__FileDesc);
      if (i1) goto l11;
      _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34602)))), 34602);
      goto l14;
l11:
      i1 = (OOC_INT32)w;
      OOC_Package__WritePackage_WriteFileSet_WriteFile((XML_Writer__Writer)i1, (OOC_Package__File)i0);
      goto l14;
l13:
      i1 = (OOC_INT32)w;
      OOC_Package__WritePackage_WriteFileSet((XML_Writer__Writer)i1, (OOC_Package__FileSet)i0);
l14:
      i0 = (OOC_INT32)ptr;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 34677));
      ptr = (OOC_Package__FileData)i0;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l6_loop;
l19:
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34710)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i0);
      return;
      ;
    }


  i0 = (OOC_INT32)targetDir;
  i0 = (OOC_INT32)ADT_StringBuffer__New((Object__String)i0);
  b = (ADT_StringBuffer__StringBuffer)i0;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34811)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1)),ADT_StringBuffer__StringBufferDesc_AppendLatin1)((ADT_StringBuffer__StringBuffer)i0, "/pkginfo", 9);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34846)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c9));
  i1 = (OOC_INT32)pkg;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34876))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34865)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34889)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c10));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34923)))), ADT_StringBuffer__StringBufferDesc_ToString)),ADT_StringBuffer__StringBufferDesc_ToString)((ADT_StringBuffer__StringBuffer)i0);
  fileName = (Object__String)i0;
  i0 = (OOC_INT32)IO_FileChannel__Open((Object__String)i0, 22u);
  f = (IO__ByteChannel)i0;
  i2 = (OOC_INT32)XML_UnicodeCodec_Latin1__factory;
  i0 = (OOC_INT32)XML_Writer__New((IO__ByteChannel)i0, (XML_UnicodeCodec__Factory)i2, 1u, 2);
  w = (XML_Writer__Writer)i0;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 35153)))), XML_Writer__WriterDesc_StartTag)),XML_Writer__WriterDesc_StartTag)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){112,97,99,107,97,103,101,0}), 8, 0u);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 35210))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 35187)))), XML_Writer__WriterDesc_AttrObject)),XML_Writer__WriterDesc_AttrObject)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){110,97,109,101,0}), 5, (Object__String)i2);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 35241))+12);
  OOC_Package__WritePackage_WriteVersion((XML_Writer__Writer)i0, (OOC_Package__Version)i1);
  i0 = (OOC_INT32)pkg;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 35287));
  i2 = (OOC_INT32)w;
  OOC_Package__WriteKeyValue((XML_Writer__Writer)i2, "options", 8, (ADT_ArrayList__ArrayList)i1);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35333))+4);
  OOC_Package__WriteKeyValue((XML_Writer__Writer)i2, "pragmas", 8, (ADT_ArrayList__ArrayList)i1);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35365))+16);
  i = 0;
  i0 = *(OOC_INT32*)((_check_pointer(i0, 35373))+4);
  i1 = 0<i0;
  if (!i1) goto l8;
  i1=0;
l3_loop:
  i2 = (OOC_INT32)pkg;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 35409))+16);
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 35417));
  i2 = _check_pointer(i2, 35423);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i1, i3, OOC_UINT32, 35423))*4);
  i2 = (OOC_INT32)w;
  OOC_Package__WritePackage_WriteLibrary((XML_Writer__Writer)i2, (OOC_Package__Library)i1);
  i1 = i;
  i1 = i1+1;
  i = i1;
  i2 = i1<i0;
  if (i2) goto l3_loop;
l8:
  i0 = (OOC_INT32)pkg;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35459))+20);
  i0 = *(OOC_INT32*)((_check_pointer(i0, 35470))+4);
  i = 0;
  i1 = 0<i0;
  if (!i1) goto l16;
  i1=0;
l11_loop:
  i2 = (OOC_INT32)pkg;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 35509))+20);
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 35520));
  i2 = _check_pointer(i2, 35526);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i1, i3, OOC_UINT32, 35526))*4);
  i2 = (OOC_INT32)w;
  OOC_Package__WritePackage_WriteExecutable((XML_Writer__Writer)i2, (OOC_Package__Executable)i1);
  i1 = i;
  i1 = i1+1;
  i = i1;
  i2 = i1<i0;
  if (i2) goto l11_loop;
l16:
  i0 = (OOC_INT32)pkg;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35564))+24);
  i1 = (OOC_INT32)w;
  OOC_Package__WritePackage_WriteFileSet((XML_Writer__Writer)i1, (OOC_Package__FileSet)i0);
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 35580)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 35611)))), XML_Writer__WriterDesc_EndOfText)),XML_Writer__WriterDesc_EndOfText)((XML_Writer__Writer)i0);
  i0 = (OOC_INT32)f;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 35635)))), IO__ChannelDesc_Close)),IO__ChannelDesc_Close)((IO__Channel)i0);
  i0 = (OOC_INT32)fileName;
  i0 = (OOC_INT32)Object__Concat2((void*)((OOC_INT32)_c11),(void*)i0);
  OOC_Logger__ShellCommand((Object__String)i0);
  i0 = OS_ProcessManagement__system((Object__String)i0);
  return;
  ;
}

void OOC_Package__WriteRepository(OOC_Package__Repository rep, Object__String targetDir) {
  register OOC_INT32 i0,i1,i2,i3;
  Object__String fileName;
  IO__ByteChannel f;
  XML_Writer__Writer w;
  OOC_INT32 i;
  auto void OOC_Package__WriteRepository_WriteInstalledPkg(XML_Writer__Writer w, Object__String pkgName);
    
    void OOC_Package__WriteRepository_WriteInstalledPkg(XML_Writer__Writer w, Object__String pkgName) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36028)))), XML_Writer__WriterDesc_StartTag)),XML_Writer__WriterDesc_StartTag)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){105,110,115,116,97,108,108,101,100,0}), 10, 0u);
      i1 = (OOC_INT32)pkgName;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36066)))), XML_Writer__WriterDesc_AttrObject)),XML_Writer__WriterDesc_AttrObject)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){112,97,99,107,97,103,101,0}), 8, (Object__String)i1);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36106)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i0);
      return;
      ;
    }


  i0 = (OOC_INT32)targetDir;
  i0 = (OOC_INT32)Object__Concat2((void*)i0,(void*)((OOC_INT32)_c12));
  fileName = (Object__String)i0;
  OOC_Logger__WriteFileName((Object__String)i0);
  i0 = (OOC_INT32)IO_FileChannel__Open((Object__String)i0, 22u);
  f = (IO__ByteChannel)i0;
  i1 = (OOC_INT32)XML_UnicodeCodec_Latin1__factory;
  i0 = (OOC_INT32)XML_Writer__New((IO__ByteChannel)i0, (XML_UnicodeCodec__Factory)i1, 1u, 2);
  w = (XML_Writer__Writer)i0;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36460)))), XML_Writer__WriterDesc_StartTag)),XML_Writer__WriterDesc_StartTag)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){114,101,112,111,115,105,116,111,114,121,0}), 11, 0u);
  i0 = (OOC_INT32)rep;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36513))+8);
  i = 0;
  i0 = *(OOC_INT32*)((_check_pointer(i0, 36527))+4);
  i1 = 0<i0;
  if (!i1) goto l8;
  i1=0;
l3_loop:
  i2 = (OOC_INT32)rep;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 36568))+8);
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 36582));
  i2 = _check_pointer(i2, 36588);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i1, i3, OOC_UINT32, 36588))*4);
  i2 = (OOC_INT32)w;
  OOC_Package__WriteRepository_WriteInstalledPkg((XML_Writer__Writer)i2, (Object__String)i1);
  i1 = i;
  i1 = i1+1;
  i = i1;
  i2 = i1<i0;
  if (i2) goto l3_loop;
l8:
  i0 = (OOC_INT32)rep;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 36638));
  i2 = (OOC_INT32)w;
  OOC_Package__WriteKeyValue((XML_Writer__Writer)i2, "options", 8, (ADT_ArrayList__ArrayList)i1);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36684))+4);
  OOC_Package__WriteKeyValue((XML_Writer__Writer)i2, "pragmas", 8, (ADT_ArrayList__ArrayList)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 36700)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 36734)))), XML_Writer__WriterDesc_EndOfText)),XML_Writer__WriterDesc_EndOfText)((XML_Writer__Writer)i2);
  i0 = (OOC_INT32)f;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36753)))), IO__ChannelDesc_Close)),IO__ChannelDesc_Close)((IO__Channel)i0);
  i0 = (OOC_INT32)fileName;
  i0 = (OOC_INT32)Object__Concat2((void*)((OOC_INT32)_c13),(void*)i0);
  OOC_Logger__ShellCommand((Object__String)i0);
  i0 = OS_ProcessManagement__system((Object__String)i0);
  return;
  ;
}

Object__String OOC_Package__RemovePkgInfoCmd(OOC_Package__Package pkg, Object__String targetDir, Object__String uninstall) {
  register OOC_INT32 i0,i1;
  ADT_StringBuffer__StringBuffer sb;

  i0 = (OOC_INT32)uninstall;
  i0 = (OOC_INT32)ADT_StringBuffer__New((Object__String)i0);
  sb = (ADT_StringBuffer__StringBuffer)i0;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37067)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c14));
  i1 = (OOC_INT32)targetDir;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37087)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37113)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c15));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37143)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c16));
  i1 = (OOC_INT32)pkg;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 37174))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37163)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37188)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c17));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37218)))), ADT_StringBuffer__StringBufferDesc_ToString)),ADT_StringBuffer__StringBufferDesc_ToString)((ADT_StringBuffer__StringBuffer)i0);
  return (Object__String)i0;
  ;
}

OOC_Package__Package OOC_Package__GetPkgInfo(Object__String targetDir, Object__String pkgName, OOC_Error__List *errList) {
  register OOC_INT32 i0,i1;
  ADT_StringBuffer__StringBuffer sb;
  Object__String str;
  OOC_Repository__PkgInfo pkgInfo;

  i0 = (OOC_INT32)RT0__NewObject(_td_ADT_StringBuffer__StringBuffer.baseTypes[0]);
  ADT_StringBuffer__StringBufferDesc_INIT((ADT_StringBuffer__StringBuffer)i0, 256);
  sb = (ADT_StringBuffer__StringBuffer)i0;
  i1 = (OOC_INT32)targetDir;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37532)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37558)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c18));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37588)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c19));
  i1 = (OOC_INT32)pkgName;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37608)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37632)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c20));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37663)))), ADT_StringBuffer__StringBufferDesc_ToString)),ADT_StringBuffer__StringBufferDesc_ToString)((ADT_StringBuffer__StringBuffer)i0);
  str = (Object__String)i0;
  i1 = (OOC_INT32)OOC_Error__NewList((Object__String)i0);
  *errList = (OOC_Error__List)i1;
  i0 = (OOC_INT32)OOC_Package__ParseFile((Object__String)i0, 1u, (void*)(OOC_INT32)errList);
  pkgInfo = (OOC_Repository__PkgInfo)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l3;
  return (OOC_Package__Package)(OOC_INT32)0;
  goto l4;
l3:
  return (OOC_Package__Package)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37806)))), &_td_OOC_Package__PackageDesc, 37806));
l4:
  _failed_function(37266); return 0;
  ;
}

OOC_Package__Repository OOC_Package__GetRepository(Object__String targetDir, OOC_Error__List *errList) {
  register OOC_INT32 i0,i1;
  Object__String fileName;
  OOC_Repository__PkgInfo pkgInfo;

  i0 = (OOC_INT32)targetDir;
  i0 = (OOC_INT32)Object__Concat2((void*)i0,(void*)((OOC_INT32)_c21));
  fileName = (Object__String)i0;
  i1 = (OOC_INT32)OOC_Error__NewList((Object__String)i0);
  *errList = (OOC_Error__List)i1;
  i0 = (OOC_INT32)OOC_Package__ParseFile((Object__String)i0, 0u, (void*)(OOC_INT32)errList);
  pkgInfo = (OOC_Repository__PkgInfo)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l3;
  return (OOC_Package__Repository)(OOC_INT32)0;
  goto l4;
l3:
  return (OOC_Package__Repository)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 38241)))), &_td_OOC_Package__RepositoryDesc, 38241));
l4:
  _failed_function(37881); return 0;
  ;
}

OOC_CHAR8 OOC_Package__UpdateRepository(Object__String targetDir) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  Object__String dirName;
  OS_Files__NameArray files;
  OOC_Package__Repository repository;
  OOC_INT32 i;
  Object__String fileName;
  OOC_Error__List errList;
  OOC_Repository__PkgInfo pkg;
  auto OOC_CHAR8 OOC_Package__UpdateRepository_IsPkgInfo(Object__String name);
    
    OOC_CHAR8 OOC_Package__UpdateRepository_IsPkgInfo(Object__String name) {
      register OOC_INT32 i0;

      i0 = (OOC_INT32)name;
      i0 = Object__StringDesc_EndsWith((Object__String)i0, (Object__String)((OOC_INT32)_c22));
      return i0;
      ;
    }


  i0 = (OOC_INT32)targetDir;
  i0 = (OOC_INT32)Object__Concat2((void*)i0,(void*)((OOC_INT32)_c23));
  dirName = (Object__String)i0;
  i0 = (OOC_INT32)OS_Files__ListDir((Object__String)i0);
  files = (OS_Files__NameArray)i0;
  i1 = (OOC_INT32)OOC_Package__NewRepository();
  repository = (OOC_Package__Repository)i1;
  i = 0;
  i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 38816)), 0);
  i1 = 0<i0;
  if (!i1) goto l15;
  i1 = (OOC_INT32)_c24;
  i2=0;
l3_loop:
  i3 = (OOC_INT32)files;
  i3 = _check_pointer(i3, 38848);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 38848))*4);
  i2 = OOC_Package__UpdateRepository_IsPkgInfo((Object__String)i2);
  if (!i2) goto l10;
  i2 = (OOC_INT32)files;
  i2 = _check_pointer(i2, 38895);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i4 = i;
  i5 = (OOC_INT32)dirName;
  i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i4, i3, OOC_UINT32, 38895))*4);
  i2 = (OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)i5,(void*)i1)),(void*)i2);
  fileName = (Object__String)i2;
  i3 = (OOC_INT32)OOC_Error__NewList((Object__String)i2);
  errList = (OOC_Error__List)i3;
  i2 = (OOC_INT32)OOC_Package__ParseFile((Object__String)i2, 1u, (void*)(OOC_INT32)&errList);
  pkg = (OOC_Repository__PkgInfo)i2;
  i3 = (OOC_INT32)errList;
  i4 = *(OOC_INT32*)(_check_pointer(i3, 39023));
  i4 = i4!=0;
  if (i4) goto l8;
  i3 = (OOC_INT32)repository;
  OOC_Package__RepositoryDesc_MergePackage((OOC_Package__Repository)i3, (OOC_Package__Package)(_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 39163)))), &_td_OOC_Package__PackageDesc, 39163)));
  goto l10;
l8:
  i2 = (OOC_INT32)IO_StdChannels__stdout;
  OOC_Error__ListDesc_Write((OOC_Error__List)i3, (IO__ByteChannel)i2);
  return 0u;
l10:
  i2 = i;
  i2 = i2+1;
  i = i2;
  i3 = i2<i0;
  if (i3) goto l3_loop;
l15:
  i0 = (OOC_INT32)targetDir;
  i1 = (OOC_INT32)repository;
  OOC_Package__WriteRepository((OOC_Package__Repository)i1, (Object__String)i0);
  return 1u;
  ;
}

void OOC_OOC_Package_init(void) {
  register OOC_INT32 i0;
  _c0 = Object__NewLatin1Char(47u);
  _c1 = Object__NewLatin1Char(47u);
  _c2 = Object__NewLatin1Char(46u);
  _c3 = Object__NewLatin1Region("", 1, 0, 0);
  _c4 = Object__NewLatin1Region("", 1, 0, 0);
  _c5 = Object__NewLatin1Region("", 1, 0, 0);
  _c6 = Object__NewLatin1Char(46u);
  _c7 = Object__NewLatin1Char(46u);
  _c8 = Object__NewLatin1Region("", 1, 0, 0);
  _c9 = Object__NewLatin1Char(47u);
  _c10 = Object__NewLatin1Region(".xml", 5, 0, 4);
  _c11 = Object__NewLatin1Region("chmod 644 ", 11, 0, 10);
  _c12 = Object__NewLatin1Region("/pkginfo.xml", 13, 0, 12);
  _c13 = Object__NewLatin1Region("chmod 644 ", 11, 0, 10);
  _c14 = Object__NewLatin1Char(32u);
  _c15 = Object__NewLatin1Region("/pkginfo", 9, 0, 8);
  _c16 = Object__NewLatin1Char(47u);
  _c17 = Object__NewLatin1Region(".xml", 5, 0, 4);
  _c18 = Object__NewLatin1Region("/pkginfo", 9, 0, 8);
  _c19 = Object__NewLatin1Char(47u);
  _c20 = Object__NewLatin1Region(".xml", 5, 0, 4);
  _c21 = Object__NewLatin1Region("/pkginfo.xml", 13, 0, 12);
  _c22 = Object__NewLatin1Region(".xml", 5, 0, 4);
  _c23 = Object__NewLatin1Region("/pkginfo", 9, 0, 8);
  _c24 = Object__NewLatin1Char(47u);
  _c25 = Object__NewLatin1Region("string", 7, 0, 6);

  OOC_Package__stringType = (Object__String)((OOC_INT32)_c25);
  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Package__ErrorContext.baseTypes[0]);
  OOC_Package__packageContext = (OOC_Package__ErrorContext)i0;
  Msg__InitContext((Msg__Context)i0, "OOC:Package", 12);
  return;
  ;
}

/* --- */
