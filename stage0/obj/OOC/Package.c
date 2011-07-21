#include <OOC/Package.d>
#include <__oo2c.h>
#include <setjmp.h>

void OOC_Package__ErrorContextDesc_GetTemplate(OOC_Package__ErrorContext context, Msg__Msg msg, Msg__LString templ, OOC_LEN templ_0d) {
  register OOC_INT32 i0,i1;
  OOC_CHAR16 t[128];

  i0 = (OOC_INT32)msg;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 3052))+8);
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
    _failed_case(i1, 3044);
    goto l21;
  }
l21:
  i1 = (OOC_INT32)context;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4522)))), XML_Error__ContextDesc_WriteTemplate)),XML_Error__ContextDesc_WriteTemplate)((XML_Error__Context)i1, (Msg__Msg)i0, (void*)(OOC_INT32)t, 128, (void*)(OOC_INT32)templ, templ_0d);
  return;
  ;
}

static OOC_Package__Version OOC_Package__NewVersion(void) {
  register OOC_INT32 i0;
  OOC_Package__Version version;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Package__Version.baseTypes[0]);
  version = (OOC_Package__Version)i0;
  *(OOC_INT32*)(_check_pointer(i0, 4672)) = (-1);
  *(OOC_INT32*)((_check_pointer(i0, 4699))+4) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 4721))+8) = (-1);
  _copy_8((const void*)"",(void*)((_check_pointer(i0, 4749))+12),32);
  return (OOC_Package__Version)i0;
  ;
}

static OOC_Package__Executable OOC_Package__NewExecutable(void) {
  register OOC_INT32 i0;
  OOC_Package__Executable executable;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Package__Executable.baseTypes[0]);
  executable = (OOC_Package__Executable)i0;
  *(OOC_INT32*)(_check_pointer(i0, 4918)) = 0;
  return (OOC_Package__Executable)i0;
  ;
}

static OOC_Package__Library OOC_Package__NewLibrary(void) {
  register OOC_INT32 i0;
  OOC_Package__Library library;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Package__Library.baseTypes[0]);
  library = (OOC_Package__Library)i0;
  *(OOC_INT32*)((_check_pointer(i0, 5081))+4) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i0, 5112))+8) = (OOC_INT32)0;
  return (OOC_Package__Library)i0;
  ;
}

static void OOC_Package__InitFileData(OOC_Package__FileData fdata) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)fdata;
  *(OOC_INT32*)(_check_pointer(i0, 5226)) = 0;
  return;
  ;
}

static OOC_Package__FileSet OOC_Package__NewFileSet(void) {
  register OOC_INT32 i0;
  OOC_Package__FileSet fileSet;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Package__FileSet.baseTypes[0]);
  fileSet = (OOC_Package__FileSet)i0;
  OOC_Package__InitFileData((OOC_Package__FileData)i0);
  *(OOC_INT32*)((_check_pointer(i0, 5394))+4) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i0, 5424))+8) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i0, 5452))+12) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i0, 5477))+16) = (OOC_INT32)0;
  return (OOC_Package__FileSet)i0;
  ;
}

void OOC_Package__FileSetDesc_Append(OOC_Package__FileSet fileSet, OOC_Package__FileData fdata) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)fileSet;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5608))+16);
  i1 = i1==(OOC_INT32)0;
  if (i1) goto l3;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5677))+16);
  i2 = (OOC_INT32)fdata;
  *(OOC_INT32*)(_check_pointer(i1, 5682)) = i2;
  i1=i2;
  goto l4;
l3:
  i1 = (OOC_INT32)fdata;
  *(OOC_INT32*)((_check_pointer(i0, 5639))+12) = i1;
  
l4:
  *(OOC_INT32*)((_check_pointer(i0, 5726))+16) = i1;
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
  *(OOC_INT32*)((_check_pointer(i0, 5884))+4) = i1;
  i1 = (OOC_INT32)destName;
  *(OOC_INT32*)((_check_pointer(i0, 5907))+8) = i1;
  return (OOC_Package__File)i0;
  ;
}

OOC_Package__KeyValue OOC_Package__NewKeyValue(Object__String key, Config__Variable value) {
  register OOC_INT32 i0,i1;
  OOC_Package__KeyValue kv;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Package__KeyValue.baseTypes[0]);
  kv = (OOC_Package__KeyValue)i0;
  i1 = (OOC_INT32)key;
  *(OOC_INT32*)(_check_pointer(i0, 6086)) = i1;
  i1 = (OOC_INT32)value;
  *(OOC_INT32*)((_check_pointer(i0, 6105))+4) = i1;
  return (OOC_Package__KeyValue)i0;
  ;
}

static void OOC_Package__MergeConfig(OOC_Repository__PkgInfo pkg, Config_Section_Options__Section options, Config_Section_Options__Section pragmas) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT32 i;
  OOC_Package__KeyValue kv;
  Config_Section_Options__Option o;

  i0 = (OOC_INT32)pkg;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6325));
  i = 0;
  i1 = *(OOC_INT32*)((_check_pointer(i1, 6333))+4);
  i2 = 0<i1;
  if (!i2) goto l8;
  i2 = (OOC_INT32)options;
  i3=0;
l3_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6359));
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 6367));
  i4 = _check_pointer(i4, 6373);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 6373))*4);
  i4 = _type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 6377)))), &_td_OOC_Package__KeyValueDesc, 6377);
  kv = (OOC_Package__KeyValue)i4;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 6421))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 6413));
  i4 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 6406)))), Config_Section_Options__SectionDesc_Set)),Config_Section_Options__SectionDesc_Set)((Config_Section_Options__Section)i2, (Object__String)i4, (Config__Variable)i5);
  o = (Config_Section_Options__Option)i4;
  i3 = i3+1;
  i = i3;
  i4 = i3<i1;
  if (i4) goto l3_loop;
l8:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6460))+4);
  i1 = *(OOC_INT32*)((_check_pointer(i1, 6468))+4);
  i = 0;
  i2 = 0<i1;
  if (!i2) goto l16;
  i2 = (OOC_INT32)pragmas;
  i3=0;
l11_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6494))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 6502));
  i4 = _check_pointer(i4, 6508);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 6508))*4);
  i4 = _type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 6512)))), &_td_OOC_Package__KeyValueDesc, 6512);
  kv = (OOC_Package__KeyValue)i4;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 6556))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 6548));
  i4 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 6541)))), Config_Section_Options__SectionDesc_Set)),Config_Section_Options__SectionDesc_Set)((Config_Section_Options__Section)i2, (Object__String)i4, (Config__Variable)i5);
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
  *(OOC_INT32*)((_check_pointer(i0, 6698))+8) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i0, 6717))+12) = (OOC_INT32)0;
  i1 = (OOC_INT32)RT0__NewObject(_td__qtd1.baseTypes[0]);
  ADT_ArrayList__ArrayListDesc_INIT((ADT_ArrayList__ArrayList)i1, 4);
  *(OOC_INT32*)((_check_pointer(i0, 6739))+16) = i1;
  i1 = (OOC_INT32)RT0__NewObject(_td__qtd3.baseTypes[0]);
  ADT_ArrayList__ArrayListDesc_INIT((ADT_ArrayList__ArrayList)i1, 4);
  *(OOC_INT32*)((_check_pointer(i0, 6794))+20) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 6855))+24) = (OOC_INT32)0;
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
  *(OOC_INT32*)((_check_pointer(i0, 7018))+8) = i1;
  return (OOC_Package__Repository)i0;
  ;
}

void OOC_Package__RepositoryDesc_MergePackage(OOC_Package__Repository r, OOC_Package__Package pkg) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_INT32 i;
  OOC_Package__KeyValue kv;

  i0 = (OOC_INT32)pkg;
  i1 = (OOC_INT32)r;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 7216))+8);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7241))+8);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 7216))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 7230)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i4, (Object__Object)i3);
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7270));
  i = 0;
  i2 = *(OOC_INT32*)((_check_pointer(i2, 7278))+4);
  i3 = 0<i2;
  if (!i3) goto l8;
  i3=0;
l3_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7304));
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 7312));
  i4 = _check_pointer(i4, 7318);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 7318))*4);
  i4 = _type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 7322)))), &_td_OOC_Package__KeyValueDesc, 7322);
  kv = (OOC_Package__KeyValue)i4;
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 7340));
  i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 7340));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 7348)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i6, (Object__Object)i4);
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l3_loop;
l8:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7391))+4);
  i2 = *(OOC_INT32*)((_check_pointer(i2, 7399))+4);
  i = 0;
  i3 = 0<i2;
  if (!i3) goto l16;
  i3=0;
l11_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7425))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 7433));
  i4 = _check_pointer(i4, 7439);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 7439))*4);
  i4 = _type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 7443)))), &_td_OOC_Package__KeyValueDesc, 7443);
  kv = (OOC_Package__KeyValue)i4;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 7461))+4);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 7461))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 7469)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i6, (Object__Object)i4);
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
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7632))+8);
  i = 0;
  i1 = *(OOC_INT32*)((_check_pointer(i1, 7646))+4);
  i2 = 0<i1;
  if (!i2) goto l11;
  i2 = (OOC_INT32)pkgName;
  i3=0;
l3_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7667))+8);
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 7681));
  i4 = _check_pointer(i4, 7687);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7667))+8);
  i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i6, 7681));
  i6 = _check_pointer(i6, 7687);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i3, i7, OOC_UINT32, 7687))*4);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 7687))*4);
  i4 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 7690)))), Object__StringDesc_Equals)),Object__StringDesc_Equals)((Object__String)i4, (Object__Object)i2);
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
              i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 9144)), 0);
              i1 = *(OOC_INT32*)(_check_pointer(i1, 9123));
              i0 = i1>=i0;
              
              goto l4;
l3:
              i0=1u;
l4:
              i1 = (OOC_INT32)path;
              if (!i0) goto l7;
              i0 = *(OOC_INT32*)(_check_pointer(i1, 9181));
              buffer = (void*)((OOC_INT32)RT0__NewObject(_td_OOC_Package__8669.baseTypes[0], (i0+1)));
l7:
              i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9230)))), Object__StringDesc_ToString8)),Object__StringDesc_ToString8)((Object__String)i1, 63u);
              path = (Object__String)i0;
              i1 = (OOC_INT32)Object__String8Desc_CharsLatin1((Object__String8)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9278)))), &_td_Object__String8Desc, 9278)));
              chars = (Object__CharsLatin1)i1;
              i2 = (OOC_INT32)buffer;
              i3 = OOC_ARRAY_LENGTH((_check_pointer(i2, 9331)), 0);
              _copy_8((const void*)(_check_pointer(i1, 9322)),(void*)(_check_pointer(i2, 9331)),i3);
              i = 0;
              i1 = _check_pointer(i2, 9377);
              i2 = OOC_ARRAY_LENGTH(i1, 0);
              i1 = *(OOC_UINT8*)(i1+(_check_index(0, i2, OOC_UINT16, 9377)));
              i1 = i1!=0u;
              if (i1) goto l10;
              i1=0;
              goto l63;
l10:
              i1=0;
l11_loop:
              i2 = (OOC_INT32)buffer;
              i3 = _check_pointer(i2, 9412);
              i4 = OOC_ARRAY_LENGTH(i3, 0);
              i3 = *(OOC_UINT8*)(i3+(_check_index(i1, i4, OOC_UINT16, 9412)));
              i3 = i3==47u;
              if (i3) goto l57;
              i3 = _check_pointer(i2, 9549);
              i4 = OOC_ARRAY_LENGTH(i3, 0);
              i3 = *(OOC_UINT8*)(i3+(_check_index(i1, i4, OOC_UINT16, 9549)));
              i3 = i3==46u;
              if (i3) goto l16;
              i3=0u;
              goto l18;
l16:
              i3 = _check_pointer(i2, 9569);
              i4 = OOC_ARRAY_LENGTH(i3, 0);
              i3 = *(OOC_UINT8*)(i3+(_check_index((i1+1), i4, OOC_UINT16, 9569)));
              i3 = i3==47u;
              
l18:
              if (i3) goto l55;
              i3 = _check_pointer(i2, 9708);
              i4 = OOC_ARRAY_LENGTH(i3, 0);
              i3 = *(OOC_UINT8*)(i3+(_check_index(i1, i4, OOC_UINT16, 9708)));
              i3 = i3==46u;
              if (i3) goto l22;
              i3=0u;
              goto l24;
l22:
              i3 = _check_pointer(i2, 9728);
              i4 = OOC_ARRAY_LENGTH(i3, 0);
              i3 = *(OOC_UINT8*)(i3+(_check_index((i1+1), i4, OOC_UINT16, 9728)));
              i3 = i3==46u;
              
l24:
              if (i3) goto l26;
              i3=0u;
              goto l28;
l26:
              i3 = _check_pointer(i2, 9768);
              i4 = OOC_ARRAY_LENGTH(i3, 0);
              i3 = *(OOC_UINT8*)(i3+(_check_index((i1+2), i4, OOC_UINT16, 9768)));
              i3 = i3==47u;
              
l28:
              if (i3) goto l40;
l30_loop:
              i3 = _check_pointer(i2, 10318);
              i4 = OOC_ARRAY_LENGTH(i3, 0);
              i3 = *(OOC_UINT8*)(i3+(_check_index(i1, i4, OOC_UINT16, 10318)));
              i3 = i3==0u;
              if (i3) goto l58;
              i3 = _check_pointer(i2, 10386);
              i4 = OOC_ARRAY_LENGTH(i3, 0);
              i3 = *(OOC_UINT8*)(i3+(_check_index(i1, i4, OOC_UINT16, 10386)));
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
              i4 = _check_pointer(i2, 10118);
              i5 = OOC_ARRAY_LENGTH(i4, 0);
              i4 = *(OOC_UINT8*)(i4+(_check_index((i3-1), i5, OOC_UINT16, 10118)));
              i4 = i4==47u;
              
              goto l48;
l46:
              i4=1u;
l48:
              if (!i4) goto l43_loop;
l51:
              i4 = OOC_ARRAY_LENGTH((_check_pointer(i2, 10169)), 0);
              Strings__Delete((void*)(_check_pointer(i2, 10169)), i4, i3, ((i1-i3)+3));
              i = i3;
              i1=i3;
              goto l58;
l52:
              i3 = OOC_ARRAY_LENGTH((_check_pointer(i2, 9912)), 0);
              Strings__Delete((void*)(_check_pointer(i2, 9912)), i3, i1, 3);
              
              goto l58;
l55:
              i3 = OOC_ARRAY_LENGTH((_check_pointer(i2, 9673)), 0);
              Strings__Delete((void*)(_check_pointer(i2, 9673)), i3, i1, 2);
              
              goto l58;
l57:
              i3 = OOC_ARRAY_LENGTH((_check_pointer(i2, 9514)), 0);
              Strings__Delete((void*)(_check_pointer(i2, 9514)), i3, i1, 1);
              
l58:
              i2 = (OOC_INT32)buffer;
              i2 = _check_pointer(i2, 9377);
              i3 = OOC_ARRAY_LENGTH(i2, 0);
              i2 = *(OOC_UINT8*)(i2+(_check_index(i1, i3, OOC_UINT16, 9377)));
              i2 = i2!=0u;
              if (i2) goto l11_loop;
l63:
              i2 = (OOC_INT32)buffer;
              i3 = i1!=0;
              if (i3) goto l66;
              i3=0u;
              goto l68;
l66:
              i3 = _check_pointer(i2, 10644);
              i4 = OOC_ARRAY_LENGTH(i3, 0);
              i3 = *(OOC_UINT8*)(i3+(_check_index((i1-1), i4, OOC_UINT16, 10644)));
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
              i3 = _check_pointer(i2, 10644);
              i4 = OOC_ARRAY_LENGTH(i3, 0);
              i3 = *(OOC_UINT8*)(i3+(_check_index((i1-1), i4, OOC_UINT16, 10644)));
              i3 = i3==47u;
              
l76:
              if (i3) goto l71_loop;
l80:
              i3 = _check_pointer(i2, 10711);
              i4 = OOC_ARRAY_LENGTH(i3, 0);
              *(OOC_UINT8*)(i3+(_check_index(i1, i4, OOC_UINT16, 10711))) = 0u;
              i3 = *(OOC_INT32*)(_check_pointer(i0, 10755));
              i3 = i1!=i3;
              if (i3) goto l83;
              return (Object__String)i0;
              goto l84;
l83:
              i0 = OOC_ARRAY_LENGTH((_check_pointer(i2, 10817)), 0);
              i0 = (OOC_INT32)Object__NewLatin1Region((void*)(_check_pointer(i2, 10817)), i0, 0, i1);
              return (Object__String)i0;
l84:
              _failed_function(8962); return 0;
              ;
            }


          i0 = (OOC_INT32)file;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11018))+4);
          i1 = (OOC_INT32)sourcePrefix;
          i0 = (OOC_INT32)Object__StringDesc_Concat((Object__String)i1, (Object__String)i0);
          i0 = (OOC_INT32)OOC_Package__Normalize_NormalizeFileSet_NormalizeFile_NormalizePath((Object__String)i0);
          name = (Object__String)i0;
          i0 = (OOC_INT32)file;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11043))+8);
          i1 = i1!=(OOC_INT32)0;
          if (i1) goto l3;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11207))+4);
          i1 = (OOC_INT32)destPrefix;
          i0 = (OOC_INT32)Object__StringDesc_Concat((Object__String)i1, (Object__String)i0);
          i0 = (OOC_INT32)OOC_Package__Normalize_NormalizeFileSet_NormalizeFile_NormalizePath((Object__String)i0);
          
          goto l4;
l3:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11123))+8);
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
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11381))+4);
      i2 = (OOC_INT32)sourcePrefix;
      sourcePrefix = (Object__String)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)i2,(void*)i1)),(void*)((OOC_INT32)_c0)));
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11414))+8);
      i1 = i1!=(OOC_INT32)0;
      if (i1) goto l3;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11536))+4);
      i2 = (OOC_INT32)destPrefix;
      i1 = (OOC_INT32)Object__Concat2((void*)i2,(void*)i1);
      
      goto l4;
l3:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11475))+8);
      i2 = (OOC_INT32)destPrefix;
      i1 = (OOC_INT32)Object__Concat2((void*)i2,(void*)i1);
      
l4:
      destPrefix = (Object__String)((OOC_INT32)Object__Concat2((void*)i1,(void*)((OOC_INT32)_c1)));
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11622))+12);
      ptr = (OOC_Package__FileData)i0;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l20;
l7_loop:
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11672)))), &_td_OOC_Package__FileSetDesc);
      if (i1) goto l14;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11757)))), &_td_OOC_Package__FileDesc);
      if (i1) goto l12;
      _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11752)))), 11752);
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
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 11828));
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
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12081))+8);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12081))+8);
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12100))+8);
          i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 12090)))), Object__StringDesc_Compare)),Object__StringDesc_Compare)((Object__String)i3, (Object__Object)i4);
          cmp = i2;
          i3 = i2==0;
          if (i3) goto l3;
          i0=i2;
          goto l4;
l3:
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12156))+4);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12156))+4);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12171))+4);
          i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 12161)))), Object__StringDesc_Compare)),Object__StringDesc_Compare)((Object__String)i1, (Object__Object)i0);
          
l4:
          return (i0<0);
          ;
        }


      i0 = (OOC_INT32)list;
      i1 = i0==(OOC_INT32)0;
      if (i1) goto l3;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 12279));
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
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 12487));
      next = (OOC_Package__FileData)i3;
      *(OOC_INT32*)(_check_pointer(i0, 12515)) = i1;
      a = (OOC_Package__FileData)i0;
      ptr = (OOC_Package__FileData)i3;
      i1 = i3!=(OOC_INT32)0;
      if (i1) goto l13;
      i1=i3;
      goto l14;
l13:
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 12632));
      next = (OOC_Package__FileData)i1;
      *(OOC_INT32*)(_check_pointer(i3, 12662)) = i2;
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
      i0 = OOC_Package__Normalize_MergeSort_Less((OOC_Package__File)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13030)))), &_td_OOC_Package__FileDesc, 13030)), (OOC_Package__File)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 13039)))), &_td_OOC_Package__FileDesc, 13039)));
      
      goto l35;
l32:
      i0=1u;
l35:
      if (i0) goto l37;
      i0 = (OOC_INT32)b;
      ptr = (OOC_Package__FileData)i0;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 13138));
      b = (OOC_Package__FileData)i1;
      
      goto l38;
l37:
      i0 = (OOC_INT32)a;
      ptr = (OOC_Package__FileData)i0;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 13080));
      a = (OOC_Package__FileData)i1;
      
l38:
      *(OOC_INT32*)(_check_pointer(i0, 13181)) = (OOC_INT32)0;
      i1 = (OOC_INT32)tail;
      *(OOC_INT32*)(_check_pointer(i1, 13217)) = i0;
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
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 13294));
      return (OOC_Package__FileData)i0;
      goto l49;
l48:
      return (OOC_Package__FileData)i0;
l49:
      _failed_function(11895); return 0;
      ;
    }


  buffer = (void*)(OOC_INT32)0;
  i0 = (OOC_INT32)OOC_Package__NewFileSet();
  norm = (OOC_Package__FileSet)i0;
  *(OOC_INT32*)((_check_pointer(i0, 13403))+4) = ((OOC_INT32)_c2);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13446))+4);
  *(OOC_INT32*)((_check_pointer(i0, 13430))+8) = i1;
  i0 = (OOC_INT32)fileSet;
  OOC_Package__Normalize_NormalizeFileSet((OOC_Package__FileSet)i0, (Object__String)((OOC_INT32)_c3), (Object__String)((OOC_INT32)_c4));
  i0 = (OOC_INT32)norm;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13529))+12);
  i1 = (OOC_INT32)OOC_Package__Normalize_MergeSort((OOC_Package__FileData)i1);
  *(OOC_INT32*)((_check_pointer(i0, 13506))+12) = i1;
  i0 = (OOC_INT32)norm;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13558))+12);
  *(OOC_INT32*)((_check_pointer(i0, 13545))+16) = i1;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13577))+16);
  i1 = i1!=(OOC_INT32)0;
  if (!i1) goto l10;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13612))+16);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 13617));
  i1 = i1!=(OOC_INT32)0;
  if (!i1) goto l10;
l4_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13666))+16);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 13671));
  *(OOC_INT32*)((_check_pointer(i0, 13653))+16) = i1;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13612))+16);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 13617));
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
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14111))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14093))+12);
  i0 = (OOC_INT32)XML_DTD__AttValueDesc_Flatten((XML_DTD__AttValue)i0, (XML_DTD__AttrDecl)i1);
  str = (XML_UnicodeBuffer__CharArray)i0;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 14146)), 0);
  i1 = (OOC_INT32)RT0__NewObject(_td_OOC_Package__14045.baseTypes[0], i1);
  buffer = (void*)i1;
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i0, 14176)), 0);
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i1, 14190)), 0);
  LongStrings__Short((void*)(_check_pointer(i0, 14176)), i2, 63u, (void*)(_check_pointer(i1, 14190)), i3);
  i0 = OOC_ARRAY_LENGTH((_check_pointer(i1, 14228)), 0);
  i0 = (OOC_INT32)Object__NewLatin1((void*)(_check_pointer(i1, 14228)), i0);
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
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14400)))), &_td_Config_Parser__ElementDesc);
  
l5:
  if (i1) goto l7;
  i0=0u;
  goto l8;
l7:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14442)))), &_td_Config_Parser__ElementDesc, 14442)), 14450))+28);
  i0 = (
  _cmp16((const void*)(_check_pointer(i0, 14455)),(const void*)(OOC_INT32)elementName))==0;
  
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
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14995)))), XML_Locator__ErrorListenerDesc_Error)),XML_Locator__ErrorListenerDesc_Error)((XML_Locator__ErrorListener)i1, (XML_Error__Context)i2, i3, 0u, (void*)((_check_pointer(i0, 15077))+4));
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
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15263)))), Exception__ExceptionDesc_GetMessage)),Exception__ExceptionDesc_GetMessage)((Exception__Exception)i0);
      msg = (Object__String)i0;
      i0 = (OOC_INT32)Object__String8Desc_CharsLatin1((Object__String8)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15304)))), &_td_Object__String8Desc, 15304)));
      chars = (Object__CharsLatin1)i0;
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 15392)), 0);
      i0 = (OOC_INT32)Msg__GetStringPtr((void*)(_check_pointer(i0, 15392)), i1);
      i1 = (OOC_INT32)lastError;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15343)))), Msg__MsgDesc_SetStringAttrib)),Msg__MsgDesc_SetStringAttrib)((Msg__Msg)i1, "reason", 7, (Msg__StringPtr)i0);
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
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15505)))), &_td_Config_Parser__CharDataDesc);
      
l5:
      if (!i1) goto l19;
      
l7_loop:
      i1 = Config_Parser__NodeDesc_IsWhitespace((Config_Parser__Node)i0);
      i1 = !i1;
      if (!i1) goto l10;
      OOC_Package__ParseKeyValue_Err(2, (Config_Parser__Node)i0);
l10:
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 15636));
      *node = (Config_Parser__Node)i0;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l13;
      i1=0u;
      goto l15;
l13:
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15505)))), &_td_Config_Parser__CharDataDesc);
      
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
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 16077))+32);
      i = 0;
      i2 = *(OOC_INT32*)(_check_pointer(i2, 16086));
      i3 = 0<i2;
      if (i3) goto l3;
      i2=i0;i0=(OOC_INT32)0;
      goto l17;
l3:
      i4=i0;i0=0;i3=(OOC_INT32)0;
l4_loop:
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 16115))+32);
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 16124))+4);
      i5 = _check_pointer(i5, 16129);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i0, i6, OOC_UINT32, 16129))*4);
      att = (XML_Builder__Attribute)i5;
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 16149))+4);
      i6 = (
      _cmp16((const void*)(_check_pointer(i6, 16159)),(const void*)((OOC_CHAR16[]){110,97,109,101,0})))==0;
      if (i6) goto l11;
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 16229))+4);
      i6 = (
      _cmp16((const void*)(_check_pointer(i6, 16239)),(const void*)((OOC_CHAR16[]){116,121,112,101,0})))==0;
      if (i6) goto l9;
      OOC_Package__ParseKeyValue_Err(3, (Config_Parser__Node)i1);
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 16409))+4);
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 16409))+4);
      i6 = OOC_ARRAY_LENGTH((_check_pointer(i6, 16419)), 0);
      i5 = (OOC_INT32)Msg__GetLStringPtr((void*)(_check_pointer(i5, 16419)), i6);
      i6 = (OOC_INT32)lastError;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 16362)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i6, "name", 5, (Msg__LStringPtr)i5);
      
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
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 16685))+36);
      node = (Config_Parser__Node)i3;
      i4 = i3!=(OOC_INT32)0;
      if (!i4) goto l34;
      {register OOC_INT32 h0=i0;i0=i3;i3=h0;}
l25_loop:
      i4 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16744)))), &_td_Config_Parser__CharDataDesc);
      if (i4) goto l28;
      OOC_Package__ParseKeyValue_Err(15, (Config_Parser__Node)i0);
      
      goto l29;
l28:
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16799))+28);
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16799))+28);
      i4 = OOC_ARRAY_LENGTH((_check_pointer(i4, 16806)), 0);
      LongStrings__Short((void*)(_check_pointer(i5, 16806)), i4, 63u, (void*)(OOC_INT32)str, 1024);
      i4 = (OOC_INT32)Object__NewLatin1((void*)(OOC_INT32)str, 1024);
      i3 = (OOC_INT32)Object__StringDesc_Concat((Object__String)i3, (Object__String)i4);
      stringBuffer = (Object__String)i3;
      
l29:
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 16989));
      node = (Config_Parser__Node)i0;
      i4 = i0!=(OOC_INT32)0;
      if (i4) goto l25_loop;
l33:
      i0=i3;
l34:
      i3 = (OOC_INT32)Object__String8Desc_CharsLatin1((Object__String8)(_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 17043)))), &_td_Object__String8Desc, 17043)));
      chars = (Object__CharsLatin1)i3;
      i4 = (OOC_INT32)options;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 17108))+8);
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
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 17303)))), Config__VariableDesc_StringToValue)),Config__VariableDesc_StringToValue)((Config__Variable)i2, (Object__String)i0);
        Exception__PopContext(1);
l44:;
      }
      goto l46;
l45:
      OOC_Package__ParseKeyValue_Err(16, (Config_Parser__Node)i1);
      i0 = OOC_ARRAY_LENGTH((_check_pointer(i3, 17255)), 0);
      i0 = (OOC_INT32)Msg__GetStringPtr((void*)(_check_pointer(i3, 17255)), i0);
      i1 = (OOC_INT32)lastError;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17208)))), Msg__MsgDesc_SetStringAttrib)),Msg__MsgDesc_SetStringAttrib)((Msg__Msg)i1, "type", 5, (Msg__StringPtr)i0);
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
      _failed_function(15687); return 0;
      ;
    }


  i0 = (OOC_INT32)elem;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17585))+32);
  i1 = *(OOC_INT32*)(_check_pointer(i1, 17594));
  i1 = i1!=0;
  if (!i1) goto l4;
  OOC_Package__ParseKeyValue_Err(3, (Config_Parser__Node)i0);
  i0 = (OOC_INT32)elem;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17707))+32);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 17716))+4);
  i1 = _check_pointer(i1, 17721);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 17721))*4);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 17724))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17707))+32);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 17716))+4);
  i2 = _check_pointer(i2, 17721);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(0, i3, OOC_UINT8, 17721))*4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 17724))+4);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 17734)), 0);
  i1 = (OOC_INT32)Msg__GetLStringPtr((void*)(_check_pointer(i2, 17734)), i1);
  i2 = (OOC_INT32)lastError;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 17659)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i2, "name", 5, (Msg__LStringPtr)i1);
  
l4:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17769))+36);
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
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 18015));
  node = (Config_Parser__Node)i0;
  goto l11;
l10:
  i0 = (OOC_INT32)OOC_Package__ParseKeyValue_ParseDefine((Config_Parser__Element)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17907)))), &_td_Config_Parser__ElementDesc, 17907)));
  i1 = (OOC_INT32)list;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17875)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i1, (Object__Object)i0);
  i0 = (OOC_INT32)node;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 17939));
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
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 18474)))), XML_Locator__ErrorListenerDesc_Error)),XML_Locator__ErrorListenerDesc_Error)((XML_Locator__ErrorListener)i1, (XML_Error__Context)i2, i3, 0u, (void*)((_check_pointer(i0, 18556))+4));
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
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18697)))), &_td_Config_Parser__CharDataDesc);
      
l5:
      if (!i1) goto l19;
      
l7_loop:
      i1 = Config_Parser__NodeDesc_IsWhitespace((Config_Parser__Node)i0);
      i1 = !i1;
      if (!i1) goto l10;
      OOC_Package__ProcessPackage_Err(2, (Config_Parser__Node)i0);
l10:
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 18828));
      *node = (Config_Parser__Node)i0;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l13;
      i1=0u;
      goto l15;
l13:
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18697)))), &_td_Config_Parser__CharDataDesc);
      
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
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19350))+8);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19332))+12);
          i1 = (OOC_INT32)XML_DTD__AttValueDesc_Flatten((XML_DTD__AttValue)i2, (XML_DTD__AttrDecl)i1);
          str = (XML_UnicodeBuffer__CharArray)i1;
          i2 = OOC_ARRAY_LENGTH((_check_pointer(i1, 19381)), 0);
          i2 = i2<128;
          if (!i2) goto l10;
          i2 = OOC_ARRAY_LENGTH((_check_pointer(i1, 19434)), 0);
          LongStrings__Short((void*)(_check_pointer(i1, 19434)), i2, 63u, (void*)(OOC_INT32)buffer, 128);
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
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19703))+4);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19703))+4);
          i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 19713)), 0);
          i0 = (OOC_INT32)Msg__GetLStringPtr((void*)(_check_pointer(i0, 19713)), i1);
          i1 = (OOC_INT32)lastError;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 19656)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i1, "name", 5, (Msg__LStringPtr)i0);
          return 0;
          ;
        }


      i0 = (OOC_INT32)OOC_Package__NewVersion();
      version = (OOC_Package__Version)i0;
      i0 = (OOC_INT32)elem;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19826))+32);
      i = 0;
      i0 = *(OOC_INT32*)(_check_pointer(i0, 19835));
      i1 = 0<i0;
      if (!i1) goto l20;
      i1=0;
l3_loop:
      i2 = (OOC_INT32)elem;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 19864))+32);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 19873))+4);
      i3 = _check_pointer(i3, 19878);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i1 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i1, i4, OOC_UINT32, 19878))*4);
      att = (XML_Builder__Attribute)i1;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 19898))+4);
      i3 = (
      _cmp16((const void*)(_check_pointer(i3, 19908)),(const void*)((OOC_CHAR16[]){99,117,114,114,101,110,116,0})))==0;
      if (i3) goto l14;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 19990))+4);
      i3 = (
      _cmp16((const void*)(_check_pointer(i3, 20000)),(const void*)((OOC_CHAR16[]){97,103,101,0})))==0;
      if (i3) goto l12;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 20074))+4);
      i3 = (
      _cmp16((const void*)(_check_pointer(i3, 20084)),(const void*)((OOC_CHAR16[]){114,101,118,105,115,105,111,110,0})))==0;
      if (i3) goto l10;
      OOC_Package__ProcessPackage_Err(3, (Config_Parser__Node)i2);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 20268))+4);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 20268))+4);
      i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 20278)), 0);
      i1 = (OOC_INT32)Msg__GetLStringPtr((void*)(_check_pointer(i1, 20278)), i2);
      i2 = (OOC_INT32)lastError;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 20221)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i2, "name", 5, (Msg__LStringPtr)i1);
      goto l15;
l10:
      i2 = (OOC_INT32)version;
      i1 = OOC_Package__ProcessPackage_ParseVersion_Unsigned((XML_Builder__Attribute)i1);
      *(OOC_INT32*)((_check_pointer(i2, 20122))+8) = i1;
      goto l15;
l12:
      i2 = (OOC_INT32)version;
      i1 = OOC_Package__ProcessPackage_ParseVersion_Unsigned((XML_Builder__Attribute)i1);
      *(OOC_INT32*)((_check_pointer(i2, 20033))+4) = i1;
      goto l15;
l14:
      i2 = (OOC_INT32)version;
      i1 = OOC_Package__ProcessPackage_ParseVersion_Unsigned((XML_Builder__Attribute)i1);
      *(OOC_INT32*)(_check_pointer(i2, 19945)) = i1;
l15:
      i1 = i;
      i1 = i1+1;
      i = i1;
      i2 = i1<i0;
      if (i2) goto l3_loop;
l20:
      i0 = (OOC_INT32)version;
      i1 = *(OOC_INT32*)(_check_pointer(i0, 20323));
      i2 = (OOC_INT32)elem;
      i1 = i1==(-1);
      if (!i1) goto l23;
      OOC_Package__ProcessPackage_Err(7, (Config_Parser__Node)i2);
l23:
      i1 = *(OOC_INT32*)((_check_pointer(i0, 20415))+8);
      i1 = i1==(-1);
      if (!i1) goto l26;
      OOC_Package__ProcessPackage_Err(8, (Config_Parser__Node)i2);
l26:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 20506))+36);
      i1 = i1!=0;
      if (!i1) goto l29;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 20559))+36);
      OOC_Package__ProcessPackage_Err(0, (Config_Parser__Node)i1);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 20635))+28);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 20635))+28);
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 20640)), 0);
      i1 = (OOC_INT32)Msg__GetLStringPtr((void*)(_check_pointer(i2, 20640)), i1);
      i2 = (OOC_INT32)lastError;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 20587)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i2, "name", 5, (Msg__LStringPtr)i1);
l29:
      _copy_8((const void*)"",(void*)((_check_pointer(i0, 20676))+12),32);
      i1 = *(OOC_INT32*)(_check_pointer(i0, 20719));
      IntStr__IntToStr(i1, (void*)(OOC_INT32)str, 32);
      Strings__Append((void*)(OOC_INT32)str, 32, (void*)((_check_pointer(i0, 20768))+12), 32);
      Strings__Append(":", 2, (void*)((_check_pointer(i0, 20810))+12), 32);
      i1 = *(OOC_INT32*)((_check_pointer(i0, 20848))+8);
      IntStr__IntToStr(i1, (void*)(OOC_INT32)str, 32);
      Strings__Append((void*)(OOC_INT32)str, 32, (void*)((_check_pointer(i0, 20898))+12), 32);
      Strings__Append(":", 2, (void*)((_check_pointer(i0, 20940))+12), 32);
      i1 = *(OOC_INT32*)((_check_pointer(i0, 20978))+4);
      IntStr__IntToStr(i1, (void*)(OOC_INT32)str, 32);
      Strings__Append((void*)(OOC_INT32)str, 32, (void*)((_check_pointer(i0, 21023))+12), 32);
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
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 21345))+32);
      i = 0;
      i2 = *(OOC_INT32*)(_check_pointer(i2, 21354));
      i3 = 0<i2;
      if (!i3) goto l12;
      i3=0;
l3_loop:
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 21383))+32);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 21392))+4);
      i4 = _check_pointer(i4, 21397);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 21397))*4);
      att = (XML_Builder__Attribute)i4;
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 21417))+4);
      i5 = (
      _cmp16((const void*)(_check_pointer(i5, 21427)),(const void*)((OOC_CHAR16[]){109,97,105,110,45,109,111,100,117,108,101,0})))==0;
      if (i5) goto l6;
      OOC_Package__ProcessPackage_Err(3, (Config_Parser__Node)i1);
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 21621))+4);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 21621))+4);
      i5 = OOC_ARRAY_LENGTH((_check_pointer(i5, 21631)), 0);
      i4 = (OOC_INT32)Msg__GetLStringPtr((void*)(_check_pointer(i4, 21631)), i5);
      i5 = (OOC_INT32)lastError;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 21574)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i5, "name", 5, (Msg__LStringPtr)i4);
      goto l7;
l6:
      i4 = (OOC_INT32)OOC_Package__StringAttr((XML_Builder__Attribute)i4);
      *(OOC_INT32*)(_check_pointer(i0, 21471)) = i4;
l7:
      i3 = i3+1;
      i = i3;
      i4 = i3<i2;
      if (i4) goto l3_loop;
l12:
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 21679));
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
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 22077))+32);
      i = 0;
      i2 = *(OOC_INT32*)(_check_pointer(i2, 22086));
      i3 = 0<i2;
      if (!i3) goto l16;
      i3=0;
l3_loop:
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 22115))+32);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 22124))+4);
      i4 = _check_pointer(i4, 22129);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 22129))*4);
      att = (XML_Builder__Attribute)i4;
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 22149))+4);
      i5 = (
      _cmp16((const void*)(_check_pointer(i5, 22159)),(const void*)((OOC_CHAR16[]){110,97,109,101,0})))==0;
      if (i5) goto l10;
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 22237))+4);
      i5 = (
      _cmp16((const void*)(_check_pointer(i5, 22247)),(const void*)((OOC_CHAR16[]){109,97,105,110,45,109,111,100,117,108,101,0})))==0;
      if (i5) goto l8;
      OOC_Package__ProcessPackage_Err(3, (Config_Parser__Node)i1);
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 22438))+4);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 22438))+4);
      i5 = OOC_ARRAY_LENGTH((_check_pointer(i5, 22448)), 0);
      i4 = (OOC_INT32)Msg__GetLStringPtr((void*)(_check_pointer(i4, 22448)), i5);
      i5 = (OOC_INT32)lastError;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 22391)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i5, "name", 5, (Msg__LStringPtr)i4);
      goto l11;
l8:
      i4 = (OOC_INT32)OOC_Package__StringAttr((XML_Builder__Attribute)i4);
      *(OOC_INT32*)((_check_pointer(i0, 22288))+4) = i4;
      goto l11;
l10:
      i4 = (OOC_INT32)OOC_Package__StringAttr((XML_Builder__Attribute)i4);
      *(OOC_INT32*)(_check_pointer(i0, 22193)) = i4;
l11:
      i3 = i3+1;
      i = i3;
      i4 = i3<i2;
      if (i4) goto l3_loop;
l16:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22493))+4);
      i2 = i2==0;
      if (!i2) goto l19;
      OOC_Package__ProcessPackage_Err(9, (Config_Parser__Node)i1);
l19:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 22594))+36);
      node = (Config_Parser__Node)i2;
      OOC_Package__ProcessPackage_SkipWS((void*)(OOC_INT32)&node);
      i2 = (OOC_INT32)node;
      i3 = OOC_Package__AtElement((Config_Parser__Node)i2, ((OOC_CHAR16[]){118,101,114,115,105,111,110,0}), 8);
      if (i3) goto l22;
      OOC_Package__ProcessPackage_Err(6, (Config_Parser__Node)i1);
      goto l23;
l22:
      i1 = (OOC_INT32)OOC_Package__ProcessPackage_ParseVersion((Config_Parser__Element)(_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 22717)))), &_td_Config_Parser__ElementDesc, 22717)));
      *(OOC_INT32*)((_check_pointer(i0, 22680))+8) = i1;
      i1 = (OOC_INT32)node;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 22748));
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
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23473))+32);
          i = 0;
          i1 = *(OOC_INT32*)(_check_pointer(i1, 23482));
          i2 = 0<i1;
          if (i2) goto l3;
          i1=(OOC_INT32)0;i2=(OOC_INT32)0;
          goto l17;
l3:
          i2=0;i3=(OOC_INT32)0;i4=(OOC_INT32)0;
l4_loop:
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23513))+32);
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 23522))+4);
          i5 = _check_pointer(i5, 23527);
          i6 = OOC_ARRAY_LENGTH(i5, 0);
          i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i2, i6, OOC_UINT32, 23527))*4);
          att = (XML_Builder__Attribute)i5;
          i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 23549))+4);
          i6 = (
          _cmp16((const void*)(_check_pointer(i6, 23559)),(const void*)((OOC_CHAR16[]){110,97,109,101,0})))==0;
          if (i6) goto l11;
          i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 23633))+4);
          i6 = (
          _cmp16((const void*)(_check_pointer(i6, 23643)),(const void*)((OOC_CHAR16[]){100,101,115,116,45,110,97,109,101,0})))==0;
          if (i6) goto l9;
          OOC_Package__ProcessPackage_Err(3, (Config_Parser__Node)i0);
          i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 23830))+4);
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 23830))+4);
          i6 = OOC_ARRAY_LENGTH((_check_pointer(i6, 23840)), 0);
          i5 = (OOC_INT32)Msg__GetLStringPtr((void*)(_check_pointer(i5, 23840)), i6);
          i6 = (OOC_INT32)lastError;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 23783)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i6, "name", 5, (Msg__LStringPtr)i5);
          
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
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23986))+36);
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
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 24241))+32);
      i = 0;
      i2 = *(OOC_INT32*)(_check_pointer(i2, 24250));
      i3 = 0<i2;
      if (!i3) goto l16;
      i3=0;
l3_loop:
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 24279))+32);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 24288))+4);
      i4 = _check_pointer(i4, 24293);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 24293))*4);
      att = (XML_Builder__Attribute)i4;
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 24313))+4);
      i5 = (
      _cmp16((const void*)(_check_pointer(i5, 24323)),(const void*)((OOC_CHAR16[]){115,111,117,114,99,101,45,100,105,114,0})))==0;
      if (i5) goto l10;
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 24412))+4);
      i5 = (
      _cmp16((const void*)(_check_pointer(i5, 24422)),(const void*)((OOC_CHAR16[]){100,101,115,116,45,100,105,114,0})))==0;
      if (i5) goto l8;
      OOC_Package__ProcessPackage_Err(3, (Config_Parser__Node)i1);
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 24607))+4);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 24607))+4);
      i5 = OOC_ARRAY_LENGTH((_check_pointer(i5, 24617)), 0);
      i4 = (OOC_INT32)Msg__GetLStringPtr((void*)(_check_pointer(i4, 24617)), i5);
      i5 = (OOC_INT32)lastError;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 24560)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i5, "name", 5, (Msg__LStringPtr)i4);
      goto l11;
l8:
      i4 = (OOC_INT32)OOC_Package__StringAttr((XML_Builder__Attribute)i4);
      *(OOC_INT32*)((_check_pointer(i0, 24460))+8) = i4;
      goto l11;
l10:
      i4 = (OOC_INT32)OOC_Package__StringAttr((XML_Builder__Attribute)i4);
      *(OOC_INT32*)((_check_pointer(i0, 24363))+4) = i4;
l11:
      i3 = i3+1;
      i = i3;
      i4 = i3<i2;
      if (i4) goto l3_loop;
l16:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24662))+4);
      i2 = i2==0;
      if (!i2) goto l19;
      OOC_Package__ProcessPackage_Err(10, (Config_Parser__Node)i1);
l19:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 24761))+36);
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
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 25171));
      node = (Config_Parser__Node)i0;
      i0=i1;
      goto l31;
l28:
      i0 = (OOC_INT32)OOC_Package__ProcessPackage_ParseFileSet_ParseFile((Config_Parser__Element)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 25048)))), &_td_Config_Parser__ElementDesc, 25048)));
      i1 = (OOC_INT32)fileSet;
      OOC_Package__FileSetDesc_Append((OOC_Package__FileSet)i1, (OOC_Package__FileData)i0);
      i0 = (OOC_INT32)node;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 25082));
      node = (Config_Parser__Node)i0;
      i0=i1;
      goto l31;
l30:
      i0 = (OOC_INT32)OOC_Package__ProcessPackage_ParseFileSet((Config_Parser__Element)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 24913)))), &_td_Config_Parser__ElementDesc, 24913)));
      OOC_Package__FileSetDesc_Append((OOC_Package__FileSet)i1, (OOC_Package__FileData)i0);
      i0 = (OOC_INT32)node;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 24947));
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
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25293))+28);
  i1 = (
  _cmp16((const void*)(_check_pointer(i1, 25298)),(const void*)((OOC_CHAR16[]){112,97,99,107,97,103,101,0})))!=0;
  if (!i1) goto l3;
  OOC_Package__ProcessPackage_Err(1, (Config_Parser__Node)i0);
  i0 = (OOC_INT32)Msg__GetLStringPtr(((OOC_CHAR16[]){112,97,99,107,97,103,101,0}), 8);
  i1 = (OOC_INT32)lastError;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 25370)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i1, "name", 5, (Msg__LStringPtr)i0);
l3:
  i0 = (OOC_INT32)OOC_Package__NewPackage();
  pkg = (OOC_Package__Package)i0;
  i0 = (OOC_INT32)root;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25486))+32);
  i = 0;
  i0 = *(OOC_INT32*)(_check_pointer(i0, 25495));
  i1 = 0<i0;
  if (!i1) goto l15;
  i1=0;
l6_loop:
  i2 = (OOC_INT32)root;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 25522))+32);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 25531))+4);
  i3 = _check_pointer(i3, 25536);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i1, i4, OOC_UINT32, 25536))*4);
  att = (XML_Builder__Attribute)i1;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 25554))+4);
  i3 = (
  _cmp16((const void*)(_check_pointer(i3, 25564)),(const void*)((OOC_CHAR16[]){110,97,109,101,0})))==0;
  if (i3) goto l9;
  OOC_Package__ProcessPackage_Err(3, (Config_Parser__Node)i2);
  i1 = (OOC_INT32)att;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 25730))+4);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 25730))+4);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 25740)), 0);
  i1 = (OOC_INT32)Msg__GetLStringPtr((void*)(_check_pointer(i1, 25740)), i2);
  i2 = (OOC_INT32)lastError;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 25683)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i2, "name", 5, (Msg__LStringPtr)i1);
  goto l10;
l9:
  i2 = (OOC_INT32)pkg;
  i1 = (OOC_INT32)OOC_Package__StringAttr((XML_Builder__Attribute)i1);
  *(OOC_INT32*)((_check_pointer(i2, 25592))+8) = i1;
l10:
  i1 = i;
  i1 = i1+1;
  i = i1;
  i2 = i1<i0;
  if (i2) goto l6_loop;
l15:
  i0 = (OOC_INT32)pkg;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25775))+8);
  i0 = i0==0;
  if (!i0) goto l18;
  i0 = (OOC_INT32)root;
  OOC_Package__ProcessPackage_Err(5, (Config_Parser__Node)i0);
l18:
  i0 = (OOC_INT32)root;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25862))+36);
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
  i0 = (OOC_INT32)OOC_Package__ProcessPackage_ParseVersion((Config_Parser__Element)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 25975)))), &_td_Config_Parser__ElementDesc, 25975)));
  *(OOC_INT32*)((_check_pointer(i1, 25938))+12) = i0;
  i0 = (OOC_INT32)node;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 26004));
  node = (Config_Parser__Node)i0;
  OOC_Package__ProcessPackage_SkipWS((void*)(OOC_INT32)&node);
l22:
  i0 = (OOC_INT32)node;
  i0 = OOC_Package__AtElement((Config_Parser__Node)i0, ((OOC_CHAR16[]){114,101,113,117,105,114,101,115,0}), 9);
  if (!i0) goto l30;
l25_loop:
  i0 = (OOC_INT32)node;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 26155));
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
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 26284));
  i2 = (OOC_INT32)OOC_Config__options;
  i3 = (OOC_INT32)errList;
  i4 = (OOC_INT32)errorListener;
  i5 = (OOC_INT32)OOC_Package__stringType;
  OOC_Package__ParseKeyValue((Config_Parser__Element)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 26271)))), &_td_Config_Parser__ElementDesc, 26271)), (ADT_ArrayList__ArrayList)i1, (Config_Section_Options__Section)i2, (Object__String)i5, (XML_Locator__ErrorListener)i4, (OOC_Error__List)i3);
  i0 = (OOC_INT32)node;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 26385));
  node = (Config_Parser__Node)i0;
  OOC_Package__ProcessPackage_SkipWS((void*)(OOC_INT32)&node);
l33:
  i0 = (OOC_INT32)node;
  i1 = OOC_Package__AtElement((Config_Parser__Node)i0, ((OOC_CHAR16[]){112,114,97,103,109,97,115,0}), 8);
  if (!i1) goto l36;
  i1 = (OOC_INT32)pkg;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 26514))+4);
  i2 = (OOC_INT32)OOC_Config__pragmas;
  i3 = (OOC_INT32)errList;
  i4 = (OOC_INT32)errorListener;
  i5 = (OOC_INT32)OOC_Package__stringType;
  OOC_Package__ParseKeyValue((Config_Parser__Element)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 26501)))), &_td_Config_Parser__ElementDesc, 26501)), (ADT_ArrayList__ArrayList)i1, (Config_Section_Options__Section)i2, (Object__String)i5, (XML_Locator__ErrorListener)i4, (OOC_Error__List)i3);
  i0 = (OOC_INT32)node;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 26615));
  node = (Config_Parser__Node)i0;
  OOC_Package__ProcessPackage_SkipWS((void*)(OOC_INT32)&node);
l36:
  i0 = (OOC_INT32)node;
  i0 = OOC_Package__AtElement((Config_Parser__Node)i0, ((OOC_CHAR16[]){108,105,98,114,97,114,121,0}), 8);
  if (!i0) goto l44;
l39_loop:
  i0 = (OOC_INT32)node;
  i0 = (OOC_INT32)OOC_Package__ProcessPackage_ParseLibrary((Config_Parser__Element)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 26750)))), &_td_Config_Parser__ElementDesc, 26750)));
  i1 = (OOC_INT32)pkg;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 26709))+16);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 26709))+16);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 26717)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i1, (Object__Object)i0);
  i0 = (OOC_INT32)node;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 26780));
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
  i0 = (OOC_INT32)OOC_Package__ProcessPackage_ParseExecutable((Config_Parser__Element)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 26919)))), &_td_Config_Parser__ElementDesc, 26919)));
  i1 = (OOC_INT32)pkg;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 26872))+20);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 26872))+20);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 26883)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i1, (Object__Object)i0);
  i0 = (OOC_INT32)node;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 26949));
  node = (Config_Parser__Node)i0;
  OOC_Package__ProcessPackage_SkipWS((void*)(OOC_INT32)&node);
  i0 = (OOC_INT32)node;
  i0 = OOC_Package__AtElement((Config_Parser__Node)i0, ((OOC_CHAR16[]){101,120,101,99,117,116,97,98,108,101,0}), 11);
  if (i0) goto l47_loop;
l52:
  i0 = (OOC_INT32)pkg;
  i1 = (OOC_INT32)OOC_Package__NewFileSet();
  *(OOC_INT32*)((_check_pointer(i0, 26997))+24) = i1;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27030))+24);
  *(OOC_INT32*)((_check_pointer(i1, 27038))+4) = ((OOC_INT32)_c6);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27064))+24);
  *(OOC_INT32*)((_check_pointer(i0, 27072))+8) = ((OOC_INT32)_c7);
  i0 = (OOC_INT32)node;
  i1 = OOC_Package__AtElement((Config_Parser__Node)i0, ((OOC_CHAR16[]){102,105,108,101,45,115,101,116,0}), 9);
  if (!i1) goto l61;
l56_loop:
  i0 = (OOC_INT32)OOC_Package__ProcessPackage_ParseFileSet((Config_Parser__Element)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 27180)))), &_td_Config_Parser__ElementDesc, 27180)));
  i1 = (OOC_INT32)pkg;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 27139))+24);
  OOC_Package__FileSetDesc_Append((OOC_Package__FileSet)i1, (OOC_Package__FileData)i0);
  i0 = (OOC_INT32)node;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 27210));
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
  i0 = *(OOC_INT32*)(_check_pointer(i0, 27336));
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
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 27779)))), XML_Locator__ErrorListenerDesc_Error)),XML_Locator__ErrorListenerDesc_Error)((XML_Locator__ErrorListener)i1, (XML_Error__Context)i2, i3, 0u, (void*)((_check_pointer(i0, 27861))+4));
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
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 28002)))), &_td_Config_Parser__CharDataDesc);
      
l5:
      if (!i1) goto l19;
      
l7_loop:
      i1 = Config_Parser__NodeDesc_IsWhitespace((Config_Parser__Node)i0);
      i1 = !i1;
      if (!i1) goto l10;
      OOC_Package__ProcessRepository_Err(2, (Config_Parser__Node)i0);
l10:
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 28133));
      *node = (Config_Parser__Node)i0;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l13;
      i1=0u;
      goto l15;
l13:
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 28002)))), &_td_Config_Parser__CharDataDesc);
      
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
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28403))+32);
      i = 0;
      i1 = *(OOC_INT32*)(_check_pointer(i1, 28412));
      i2 = 0<i1;
      if (i2) goto l3;
      i1=(OOC_INT32)0;
      goto l13;
l3:
      i2=0;i3=(OOC_INT32)0;
l4_loop:
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28441))+32);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 28450))+4);
      i4 = _check_pointer(i4, 28455);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i2, i5, OOC_UINT32, 28455))*4);
      att = (XML_Builder__Attribute)i4;
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 28475))+4);
      i5 = (
      _cmp16((const void*)(_check_pointer(i5, 28485)),(const void*)((OOC_CHAR16[]){112,97,99,107,97,103,101,0})))==0;
      if (i5) goto l7;
      OOC_Package__ProcessRepository_Err(3, (Config_Parser__Node)i0);
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 28661))+4);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 28661))+4);
      i5 = OOC_ARRAY_LENGTH((_check_pointer(i5, 28671)), 0);
      i4 = (OOC_INT32)Msg__GetLStringPtr((void*)(_check_pointer(i4, 28671)), i5);
      i5 = (OOC_INT32)lastError;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 28614)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i5, "name", 5, (Msg__LStringPtr)i4);
      
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
      _failed_function(28184); return 0;
      ;
    }


  i0 = (OOC_INT32)root;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28883))+28);
  i1 = (
  _cmp16((const void*)(_check_pointer(i1, 28888)),(const void*)((OOC_CHAR16[]){114,101,112,111,115,105,116,111,114,121,0})))!=0;
  if (!i1) goto l3;
  OOC_Package__ProcessRepository_Err(1, (Config_Parser__Node)i0);
  i0 = (OOC_INT32)Msg__GetLStringPtr(((OOC_CHAR16[]){114,101,112,111,115,105,116,111,114,121,0}), 11);
  i1 = (OOC_INT32)lastError;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 28963)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i1, "name", 5, (Msg__LStringPtr)i0);
l3:
  i0 = (OOC_INT32)OOC_Package__NewRepository();
  rep = (OOC_Package__Repository)i0;
  i0 = (OOC_INT32)root;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29079))+36);
  node = (Config_Parser__Node)i0;
  OOC_Package__ProcessRepository_SkipWS((void*)(OOC_INT32)&node);
  i0 = (OOC_INT32)node;
  i1 = OOC_Package__AtElement((Config_Parser__Node)i0, ((OOC_CHAR16[]){105,110,115,116,97,108,108,101,100,0}), 10);
  if (!i1) goto l12;
l7_loop:
  i0 = (OOC_INT32)OOC_Package__ProcessRepository_ParseInstalled((Config_Parser__Element)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 29207)))), &_td_Config_Parser__ElementDesc, 29207)));
  i1 = (OOC_INT32)rep;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 29158))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 29158))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 29172)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i1, (Object__Object)i0);
  i0 = (OOC_INT32)node;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 29237));
  node = (Config_Parser__Node)i0;
  OOC_Package__ProcessRepository_SkipWS((void*)(OOC_INT32)&node);
  i0 = (OOC_INT32)node;
  i1 = OOC_Package__AtElement((Config_Parser__Node)i0, ((OOC_CHAR16[]){105,110,115,116,97,108,108,101,100,0}), 10);
  if (i1) goto l7_loop;
l12:
  i1 = OOC_Package__AtElement((Config_Parser__Node)i0, ((OOC_CHAR16[]){111,112,116,105,111,110,115,0}), 8);
  if (!i1) goto l15;
  i1 = (OOC_INT32)rep;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 29366));
  i2 = (OOC_INT32)OOC_Config__options;
  i3 = (OOC_INT32)errList;
  i4 = (OOC_INT32)errorListener;
  i5 = (OOC_INT32)OOC_Package__stringType;
  OOC_Package__ParseKeyValue((Config_Parser__Element)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 29353)))), &_td_Config_Parser__ElementDesc, 29353)), (ADT_ArrayList__ArrayList)i1, (Config_Section_Options__Section)i2, (Object__String)i5, (XML_Locator__ErrorListener)i4, (OOC_Error__List)i3);
  i0 = (OOC_INT32)node;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 29467));
  node = (Config_Parser__Node)i0;
  OOC_Package__ProcessRepository_SkipWS((void*)(OOC_INT32)&node);
l15:
  i0 = (OOC_INT32)node;
  i1 = OOC_Package__AtElement((Config_Parser__Node)i0, ((OOC_CHAR16[]){112,114,97,103,109,97,115,0}), 8);
  if (!i1) goto l18;
  i1 = (OOC_INT32)rep;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 29596))+4);
  i2 = (OOC_INT32)OOC_Config__pragmas;
  i3 = (OOC_INT32)errList;
  i4 = (OOC_INT32)errorListener;
  i5 = (OOC_INT32)OOC_Package__stringType;
  OOC_Package__ParseKeyValue((Config_Parser__Element)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 29583)))), &_td_Config_Parser__ElementDesc, 29583)), (ADT_ArrayList__ArrayList)i1, (Config_Section_Options__Section)i2, (Object__String)i5, (XML_Locator__ErrorListener)i4, (OOC_Error__List)i3);
  i0 = (OOC_INT32)node;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 29697));
  node = (Config_Parser__Node)i0;
  OOC_Package__ProcessRepository_SkipWS((void*)(OOC_INT32)&node);
l18:
  i0 = (OOC_INT32)node;
  i1 = i0!=0;
  if (!i1) goto l21;
  OOC_Package__ProcessRepository_Err(4, (Config_Parser__Node)i0);
l21:
  i0 = (OOC_INT32)errList;
  i0 = *(OOC_INT32*)(_check_pointer(i0, 29828));
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
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30208))+8);
    i1 = *(OOC_INT32*)(_check_pointer(i1, 30216));
    i1 = i1==0;
    if (i1) goto l10;
    i1 = (OOC_INT32)*errList;
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30504))+8);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 30491)))), Msg__MsgListDesc_AppendList)),Msg__MsgListDesc_AppendList)((Msg__MsgList)i1, (Msg__MsgList)i0);
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
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30267))+12);
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 30272))+28);
    i1 = (
    _cmp16((const void*)(_check_pointer(i1, 30277)),(const void*)((OOC_CHAR16[]){114,101,112,111,115,105,116,111,114,121,0})))==0;
    
l15:
    if (i1) goto l17;
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30426))+16);
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30418))+12);
    i2 = (OOC_INT32)*errList;
    i0 = (OOC_INT32)OOC_Package__ProcessPackage((Config_Parser__Element)i0, (XML_Locator__ErrorListener)i1, (OOC_Error__List)i2);
    Exception__PopContext(1);
    return (OOC_Repository__PkgInfo)i0;
    goto l19;
l17:
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30346))+16);
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30338))+12);
    i2 = (OOC_INT32)*errList;
    i0 = (OOC_INT32)OOC_Package__ProcessRepository((Config_Parser__Element)i0, (XML_Locator__ErrorListener)i1, (OOC_Error__List)i2);
    Exception__PopContext(1);
    return (OOC_Repository__PkgInfo)i0;
l19:
    Exception__PopContext(1);
l20:;
  }
  _failed_function(29927); return 0;
  ;
}

OOC_Package__Package OOC_Package__GetPackage(Object__String pkgName, OOC_Repository__Repository *rep) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)OOC_Config__repositories;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30790))+4);
  *rep = (OOC_Repository__Repository)i0;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l19;
  i1 = (OOC_INT32)pkgName;
  
l3_loop:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30842))+8);
  i2 = i2!=(OOC_INT32)0;
  if (i2) goto l6;
  i2=0u;
  goto l8;
l6:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30877))+8);
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 30890)))), &_td_OOC_Package__PackageDesc);
  
l8:
  if (i2) goto l10;
  i2=0u;
  goto l12;
l10:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30916))+8);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30916))+8);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 30929)))), &_td_OOC_Package__PackageDesc, 30929)), 30937))+8);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 30929)))), &_td_OOC_Package__PackageDesc, 30929)), 30937))+8);
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 30942)))), Object__StringDesc_Equals)),Object__StringDesc_Equals)((Object__String)i2, (Object__Object)i1);
  
l12:
  if (!i2) goto l14;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30982))+8);
  return (OOC_Package__Package)(_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 30995)))), &_td_OOC_Package__PackageDesc, 30995));
l14:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 31032));
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
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 31403));
      i1 = OOC_Package__ParseMetaData_Parse((OOC_Repository__Repository)i1);
      if (!i1) goto l15;
      i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 31438)))), OOC_Repository__RepositoryDesc_GetResource)),OOC_Repository__RepositoryDesc_GetResource)((OOC_Repository__Repository)i0, "", 1, "pkginfo.xml", 12);
      uri = (URI__URI)i1;
      i2 = i1!=(OOC_INT32)0;
      if (!i2) goto l15;
      i1 = (OOC_INT32)URI_Scheme_File__URIDesc_GetPath((URI_Scheme_File__URI)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 31540)))), &_td_URI_Scheme_File__URIDesc, 31540)));
      i1 = (OOC_INT32)OOC_Package__ParseFile((Object__String)i1, 0u, (void*)(OOC_INT32)&errList);
      pkg = (OOC_Repository__PkgInfo)i1;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 31588)))), OOC_Repository__RepositoryDesc_SetPackageInfo)),OOC_Repository__RepositoryDesc_SetPackageInfo)((OOC_Repository__Repository)i0, (OOC_Repository__PkgInfo)i1);
      i0 = i1!=(OOC_INT32)0;
      if (!i0) goto l9;
      i0 = (OOC_INT32)options;
      i2 = (OOC_INT32)pragmas;
      OOC_Package__MergeConfig((OOC_Repository__PkgInfo)i1, (Config_Section_Options__Section)i0, (Config_Section_Options__Section)i2);
l9:
      i0 = (OOC_INT32)errList;
      i0 = *(OOC_INT32*)(_check_pointer(i0, 31732));
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
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31953))+4);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32280)))), XML_Writer__WriterDesc_StartTagLatin1)),XML_Writer__WriterDesc_StartTagLatin1)((XML_Writer__Writer)i0, (void*)(OOC_INT32)tag, tag_0d, 0u);
  i1 = (OOC_INT32)list;
  i = 0;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 32331))+4);
  i3 = 0<i2;
  if (!i3) goto l20;
  i3=0;
l3_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 32358));
  i4 = _check_pointer(i4, 32364);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 32364))*4);
  i4 = _type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 32368)))), &_td_OOC_Package__KeyValueDesc, 32368);
  kv = (OOC_Package__KeyValue)i4;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32386)))), XML_Writer__WriterDesc_StartTag)),XML_Writer__WriterDesc_StartTag)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){100,101,102,105,110,101,0}), 7, 1u);
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 32442));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32420)))), XML_Writer__WriterDesc_AttrObject)),XML_Writer__WriterDesc_AttrObject)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){110,97,109,101,0}), 5, (Object__String)i5);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 32462))+4);
  v = (Config__Variable)i5;
  i6 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 32482)))), &_td_Config__StringVarDesc);
  if (i6) goto l14;
  i6 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 32540)))), &_td_Config__BooleanVarDesc);
  if (i6) goto l12;
  i6 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 32600)))), &_td_Config__IntegerVarDesc);
  if (i6) goto l10;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 32597)))), 32597);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32669)))), XML_Writer__WriterDesc_AttrStringLatin1)),XML_Writer__WriterDesc_AttrStringLatin1)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){116,121,112,101,0}), 5, (void*)(OOC_INT32)type, 32);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 32724))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32709)))), XML_Writer__WriterDesc_WriteObject)),XML_Writer__WriterDesc_WriteObject)((XML_Writer__Writer)i0, (Object__Object)i4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32740)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i0);
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l3_loop;
l20:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32776)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i0);
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
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33095)))), XML_Writer__WriterDesc_StartTag)),XML_Writer__WriterDesc_StartTag)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){118,101,114,115,105,111,110,0}), 8, 0u);
      i1 = (OOC_INT32)version;
      i2 = *(OOC_INT32*)(_check_pointer(i1, 33158));
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33131)))), XML_Writer__WriterDesc_AttrInt)),XML_Writer__WriterDesc_AttrInt)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){99,117,114,114,101,110,116,0}), 8, i2);
      i2 = *(OOC_INT32*)((_check_pointer(i1, 33186))+4);
      i2 = i2>0;
      if (!i2) goto l3;
      i2 = *(OOC_INT32*)((_check_pointer(i1, 33233))+4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33210)))), XML_Writer__WriterDesc_AttrInt)),XML_Writer__WriterDesc_AttrInt)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){97,103,101,0}), 4, i2);
l3:
      i1 = *(OOC_INT32*)((_check_pointer(i1, 33285))+8);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33257)))), XML_Writer__WriterDesc_AttrInt)),XML_Writer__WriterDesc_AttrInt)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){114,101,118,105,115,105,111,110,0}), 9, i1);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33304)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i0);
      return;
      ;
    }

    
    void OOC_Package__WritePackage_WriteLibrary(XML_Writer__Writer w, OOC_Package__Library library) {
      register OOC_INT32 i0,i1,i2;

      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33432)))), XML_Writer__WriterDesc_StartTag)),XML_Writer__WriterDesc_StartTag)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){108,105,98,114,97,114,121,0}), 8, 0u);
      i1 = (OOC_INT32)library;
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 33495));
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33468)))), XML_Writer__WriterDesc_AttrObject)),XML_Writer__WriterDesc_AttrObject)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){110,97,109,101,0}), 5, (Object__String)i2);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 33544))+4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33510)))), XML_Writer__WriterDesc_AttrObject)),XML_Writer__WriterDesc_AttrObject)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){109,97,105,110,45,109,111,100,117,108,101,0}), 12, (Object__String)i2);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 33587))+8);
      OOC_Package__WritePackage_WriteVersion((XML_Writer__Writer)i0, (OOC_Package__Version)i1);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33605)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i0);
      return;
      ;
    }

    
    void OOC_Package__WritePackage_WriteExecutable(XML_Writer__Writer w, OOC_Package__Executable executable) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33742)))), XML_Writer__WriterDesc_StartTag)),XML_Writer__WriterDesc_StartTag)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){101,120,101,99,117,116,97,98,108,101,0}), 11, 0u);
      i1 = (OOC_INT32)executable;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 33818));
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33781)))), XML_Writer__WriterDesc_AttrObject)),XML_Writer__WriterDesc_AttrObject)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){109,97,105,110,45,109,111,100,117,108,101,0}), 12, (Object__String)i1);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33839)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i0);
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
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34062)))), XML_Writer__WriterDesc_StartTag)),XML_Writer__WriterDesc_StartTag)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){102,105,108,101,0}), 5, 0u);
          i1 = (OOC_INT32)file;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34121))+4);
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34097)))), XML_Writer__WriterDesc_AttrObject)),XML_Writer__WriterDesc_AttrObject)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){110,97,109,101,0}), 5, (Object__String)i2);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34145))+8);
          i2 = i2!=(OOC_INT32)0;
          if (!i2) goto l3;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34207))+8);
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34178)))), XML_Writer__WriterDesc_AttrObject)),XML_Writer__WriterDesc_AttrObject)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){100,101,115,116,45,110,97,109,101,0}), 10, (Object__String)i1);
l3:
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34241)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i0);
          return;
          ;
        }


      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34307)))), XML_Writer__WriterDesc_StartTag)),XML_Writer__WriterDesc_StartTag)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){102,105,108,101,45,115,101,116,0}), 9, 0u);
      i1 = (OOC_INT32)fileSet;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34377))+4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34344)))), XML_Writer__WriterDesc_AttrObject)),XML_Writer__WriterDesc_AttrObject)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){115,111,117,114,99,101,45,100,105,114,0}), 11, (Object__String)i2);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34407))+8);
      i2 = i2!=(OOC_INT32)0;
      if (!i2) goto l3;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34468))+8);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34437)))), XML_Writer__WriterDesc_AttrObject)),XML_Writer__WriterDesc_AttrObject)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){100,101,115,116,45,100,105,114,0}), 9, (Object__String)i2);
l3:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34510))+12);
      ptr = (OOC_Package__FileData)i0;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l19;
l6_loop:
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34560)))), &_td_OOC_Package__FileSetDesc);
      if (i1) goto l13;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34618)))), &_td_OOC_Package__FileDesc);
      if (i1) goto l11;
      _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34613)))), 34613);
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
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 34688));
      ptr = (OOC_Package__FileData)i0;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l6_loop;
l19:
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34721)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i0);
      return;
      ;
    }


  i0 = (OOC_INT32)targetDir;
  i0 = (OOC_INT32)ADT_StringBuffer__New((Object__String)i0);
  b = (ADT_StringBuffer__StringBuffer)i0;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34822)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1)),ADT_StringBuffer__StringBufferDesc_AppendLatin1)((ADT_StringBuffer__StringBuffer)i0, "/pkginfo", 9);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34857)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c9));
  i1 = (OOC_INT32)pkg;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34887))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34876)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34900)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c10));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34934)))), ADT_StringBuffer__StringBufferDesc_ToString)),ADT_StringBuffer__StringBufferDesc_ToString)((ADT_StringBuffer__StringBuffer)i0);
  fileName = (Object__String)i0;
  i0 = (OOC_INT32)IO_FileChannel__Open((Object__String)i0, 22u);
  f = (IO__ByteChannel)i0;
  i2 = (OOC_INT32)XML_UnicodeCodec_Latin1__factory;
  i0 = (OOC_INT32)XML_Writer__New((IO__ByteChannel)i0, (XML_UnicodeCodec__Factory)i2, 1u, 2);
  w = (XML_Writer__Writer)i0;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 35164)))), XML_Writer__WriterDesc_StartTag)),XML_Writer__WriterDesc_StartTag)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){112,97,99,107,97,103,101,0}), 8, 0u);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 35221))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 35198)))), XML_Writer__WriterDesc_AttrObject)),XML_Writer__WriterDesc_AttrObject)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){110,97,109,101,0}), 5, (Object__String)i2);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 35252))+12);
  OOC_Package__WritePackage_WriteVersion((XML_Writer__Writer)i0, (OOC_Package__Version)i1);
  i0 = (OOC_INT32)pkg;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 35298));
  i2 = (OOC_INT32)w;
  OOC_Package__WriteKeyValue((XML_Writer__Writer)i2, "options", 8, (ADT_ArrayList__ArrayList)i1);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35344))+4);
  OOC_Package__WriteKeyValue((XML_Writer__Writer)i2, "pragmas", 8, (ADT_ArrayList__ArrayList)i1);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35376))+16);
  i = 0;
  i0 = *(OOC_INT32*)((_check_pointer(i0, 35384))+4);
  i1 = 0<i0;
  if (!i1) goto l8;
  i1=0;
l3_loop:
  i2 = (OOC_INT32)pkg;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 35420))+16);
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 35428));
  i2 = _check_pointer(i2, 35434);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i1, i3, OOC_UINT32, 35434))*4);
  i2 = (OOC_INT32)w;
  OOC_Package__WritePackage_WriteLibrary((XML_Writer__Writer)i2, (OOC_Package__Library)i1);
  i1 = i;
  i1 = i1+1;
  i = i1;
  i2 = i1<i0;
  if (i2) goto l3_loop;
l8:
  i0 = (OOC_INT32)pkg;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35470))+20);
  i0 = *(OOC_INT32*)((_check_pointer(i0, 35481))+4);
  i = 0;
  i1 = 0<i0;
  if (!i1) goto l16;
  i1=0;
l11_loop:
  i2 = (OOC_INT32)pkg;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 35520))+20);
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 35531));
  i2 = _check_pointer(i2, 35537);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i1, i3, OOC_UINT32, 35537))*4);
  i2 = (OOC_INT32)w;
  OOC_Package__WritePackage_WriteExecutable((XML_Writer__Writer)i2, (OOC_Package__Executable)i1);
  i1 = i;
  i1 = i1+1;
  i = i1;
  i2 = i1<i0;
  if (i2) goto l11_loop;
l16:
  i0 = (OOC_INT32)pkg;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35575))+24);
  i1 = (OOC_INT32)w;
  OOC_Package__WritePackage_WriteFileSet((XML_Writer__Writer)i1, (OOC_Package__FileSet)i0);
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 35591)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 35622)))), XML_Writer__WriterDesc_EndOfText)),XML_Writer__WriterDesc_EndOfText)((XML_Writer__Writer)i0);
  i0 = (OOC_INT32)f;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 35646)))), IO__ChannelDesc_Close)),IO__ChannelDesc_Close)((IO__Channel)i0);
  i0 = (OOC_INT32)fileName;
  i0 = (OOC_INT32)OS_Path__QuoteForShell((Object__String)i0);
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
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36059)))), XML_Writer__WriterDesc_StartTag)),XML_Writer__WriterDesc_StartTag)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){105,110,115,116,97,108,108,101,100,0}), 10, 0u);
      i1 = (OOC_INT32)pkgName;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36097)))), XML_Writer__WriterDesc_AttrObject)),XML_Writer__WriterDesc_AttrObject)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){112,97,99,107,97,103,101,0}), 8, (Object__String)i1);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36137)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i0);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36491)))), XML_Writer__WriterDesc_StartTag)),XML_Writer__WriterDesc_StartTag)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){114,101,112,111,115,105,116,111,114,121,0}), 11, 0u);
  i0 = (OOC_INT32)rep;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36544))+8);
  i = 0;
  i0 = *(OOC_INT32*)((_check_pointer(i0, 36558))+4);
  i1 = 0<i0;
  if (!i1) goto l8;
  i1=0;
l3_loop:
  i2 = (OOC_INT32)rep;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 36599))+8);
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 36613));
  i2 = _check_pointer(i2, 36619);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i1, i3, OOC_UINT32, 36619))*4);
  i2 = (OOC_INT32)w;
  OOC_Package__WriteRepository_WriteInstalledPkg((XML_Writer__Writer)i2, (Object__String)i1);
  i1 = i;
  i1 = i1+1;
  i = i1;
  i2 = i1<i0;
  if (i2) goto l3_loop;
l8:
  i0 = (OOC_INT32)rep;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 36669));
  i2 = (OOC_INT32)w;
  OOC_Package__WriteKeyValue((XML_Writer__Writer)i2, "options", 8, (ADT_ArrayList__ArrayList)i1);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36715))+4);
  OOC_Package__WriteKeyValue((XML_Writer__Writer)i2, "pragmas", 8, (ADT_ArrayList__ArrayList)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 36731)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 36765)))), XML_Writer__WriterDesc_EndOfText)),XML_Writer__WriterDesc_EndOfText)((XML_Writer__Writer)i2);
  i0 = (OOC_INT32)f;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36784)))), IO__ChannelDesc_Close)),IO__ChannelDesc_Close)((IO__Channel)i0);
  i0 = (OOC_INT32)fileName;
  i0 = (OOC_INT32)OS_Path__QuoteForShell((Object__String)i0);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37118)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c14));
  i1 = (OOC_INT32)targetDir;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37138)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37164)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c15));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37194)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c16));
  i1 = (OOC_INT32)pkg;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 37225))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37214)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37239)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c17));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37269)))), ADT_StringBuffer__StringBufferDesc_ToString)),ADT_StringBuffer__StringBufferDesc_ToString)((ADT_StringBuffer__StringBuffer)i0);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37583)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37609)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c18));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37639)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c19));
  i1 = (OOC_INT32)pkgName;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37659)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37683)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c20));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37714)))), ADT_StringBuffer__StringBufferDesc_ToString)),ADT_StringBuffer__StringBufferDesc_ToString)((ADT_StringBuffer__StringBuffer)i0);
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
  return (OOC_Package__Package)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37857)))), &_td_OOC_Package__PackageDesc, 37857));
l4:
  _failed_function(37317); return 0;
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
  return (OOC_Package__Repository)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 38292)))), &_td_OOC_Package__RepositoryDesc, 38292));
l4:
  _failed_function(37932); return 0;
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
  i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 38867)), 0);
  i1 = 0<i0;
  if (!i1) goto l15;
  i1 = (OOC_INT32)_c24;
  i2=0;
l3_loop:
  i3 = (OOC_INT32)files;
  i3 = _check_pointer(i3, 38899);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 38899))*4);
  i2 = OOC_Package__UpdateRepository_IsPkgInfo((Object__String)i2);
  if (!i2) goto l10;
  i2 = (OOC_INT32)files;
  i2 = _check_pointer(i2, 38946);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i4 = i;
  i5 = (OOC_INT32)dirName;
  i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i4, i3, OOC_UINT32, 38946))*4);
  i2 = (OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)i5,(void*)i1)),(void*)i2);
  fileName = (Object__String)i2;
  i3 = (OOC_INT32)OOC_Error__NewList((Object__String)i2);
  errList = (OOC_Error__List)i3;
  i2 = (OOC_INT32)OOC_Package__ParseFile((Object__String)i2, 1u, (void*)(OOC_INT32)&errList);
  pkg = (OOC_Repository__PkgInfo)i2;
  i3 = (OOC_INT32)errList;
  i4 = *(OOC_INT32*)(_check_pointer(i3, 39074));
  i4 = i4!=0;
  if (i4) goto l8;
  i3 = (OOC_INT32)repository;
  OOC_Package__RepositoryDesc_MergePackage((OOC_Package__Repository)i3, (OOC_Package__Package)(_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 39214)))), &_td_OOC_Package__PackageDesc, 39214)));
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
