#include <OOC/Package.d>
#include <__oo2c.h>
#include <setjmp.h>

void OOC_Package__ErrorContextDesc_GetTemplate(OOC_Package__ErrorContext context, Msg__Msg msg, Msg__LString templ, OOC_LEN templ_0d) {
  register OOC_INT32 i0,i1;
  OOC_CHAR16 t[128];

  i0 = (OOC_INT32)msg;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 2965))+8);
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
    _failed_case(i1, 2957);
    goto l21;
  }
l21:
  i1 = (OOC_INT32)context;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4435)))), XML_Error__ContextDesc_WriteTemplate)),XML_Error__ContextDesc_WriteTemplate)((XML_Error__Context)i1, (Msg__Msg)i0, (void*)(OOC_INT32)t, 128, (void*)(OOC_INT32)templ, templ_0d);
  return;
  ;
}

static OOC_Package__Version OOC_Package__NewVersion(void) {
  register OOC_INT32 i0;
  OOC_Package__Version version;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Package__Version.baseTypes[0]);
  version = (OOC_Package__Version)i0;
  *(OOC_INT32*)(_check_pointer(i0, 4585)) = (-1);
  *(OOC_INT32*)((_check_pointer(i0, 4612))+4) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 4634))+8) = (-1);
  _copy_8((const void*)"",(void*)((_check_pointer(i0, 4662))+12),32);
  return (OOC_Package__Version)i0;
  ;
}

static OOC_Package__Executable OOC_Package__NewExecutable(void) {
  register OOC_INT32 i0;
  OOC_Package__Executable executable;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Package__Executable.baseTypes[0]);
  executable = (OOC_Package__Executable)i0;
  *(OOC_INT32*)(_check_pointer(i0, 4831)) = 0;
  return (OOC_Package__Executable)i0;
  ;
}

static OOC_Package__Library OOC_Package__NewLibrary(void) {
  register OOC_INT32 i0;
  OOC_Package__Library library;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Package__Library.baseTypes[0]);
  library = (OOC_Package__Library)i0;
  *(OOC_INT32*)((_check_pointer(i0, 4994))+4) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i0, 5025))+8) = (OOC_INT32)0;
  return (OOC_Package__Library)i0;
  ;
}

static void OOC_Package__InitFileData(OOC_Package__FileData fdata) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)fdata;
  *(OOC_INT32*)(_check_pointer(i0, 5139)) = 0;
  return;
  ;
}

static OOC_Package__FileSet OOC_Package__NewFileSet(void) {
  register OOC_INT32 i0;
  OOC_Package__FileSet fileSet;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Package__FileSet.baseTypes[0]);
  fileSet = (OOC_Package__FileSet)i0;
  OOC_Package__InitFileData((OOC_Package__FileData)i0);
  *(OOC_INT32*)((_check_pointer(i0, 5307))+4) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i0, 5337))+8) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i0, 5365))+12) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i0, 5390))+16) = (OOC_INT32)0;
  return (OOC_Package__FileSet)i0;
  ;
}

void OOC_Package__FileSetDesc_Append(OOC_Package__FileSet fileSet, OOC_Package__FileData fdata) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)fileSet;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5521))+16);
  i1 = i1==(OOC_INT32)0;
  if (i1) goto l3;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5590))+16);
  i2 = (OOC_INT32)fdata;
  *(OOC_INT32*)(_check_pointer(i1, 5595)) = i2;
  i1=i2;
  goto l4;
l3:
  i1 = (OOC_INT32)fdata;
  *(OOC_INT32*)((_check_pointer(i0, 5552))+12) = i1;
  
l4:
  *(OOC_INT32*)((_check_pointer(i0, 5639))+16) = i1;
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
  *(OOC_INT32*)((_check_pointer(i0, 5797))+4) = i1;
  i1 = (OOC_INT32)destName;
  *(OOC_INT32*)((_check_pointer(i0, 5820))+8) = i1;
  return (OOC_Package__File)i0;
  ;
}

OOC_Package__KeyValue OOC_Package__NewKeyValue(Object__String key, Config__Variable value) {
  register OOC_INT32 i0,i1;
  OOC_Package__KeyValue kv;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Package__KeyValue.baseTypes[0]);
  kv = (OOC_Package__KeyValue)i0;
  i1 = (OOC_INT32)key;
  *(OOC_INT32*)(_check_pointer(i0, 5999)) = i1;
  i1 = (OOC_INT32)value;
  *(OOC_INT32*)((_check_pointer(i0, 6018))+4) = i1;
  return (OOC_Package__KeyValue)i0;
  ;
}

static void OOC_Package__MergeConfig(OOC_Repository__PkgInfo pkg, Config_Section_Options__Section options, Config_Section_Options__Section pragmas) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT32 i;
  OOC_Package__KeyValue kv;
  Config_Section_Options__Option o;

  i0 = (OOC_INT32)pkg;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6238));
  i = 0;
  i1 = *(OOC_INT32*)((_check_pointer(i1, 6246))+4);
  i2 = 0<i1;
  if (!i2) goto l8;
  i2 = (OOC_INT32)options;
  i3=0;
l3_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6272));
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 6280));
  i4 = _check_pointer(i4, 6286);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 6286))*4);
  i4 = _type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 6290)))), &_td_OOC_Package__KeyValueDesc, 6290);
  kv = (OOC_Package__KeyValue)i4;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 6334))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 6326));
  i4 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 6319)))), Config_Section_Options__SectionDesc_Set)),Config_Section_Options__SectionDesc_Set)((Config_Section_Options__Section)i2, (Object__String)i4, (Config__Variable)i5);
  o = (Config_Section_Options__Option)i4;
  i3 = i3+1;
  i = i3;
  i4 = i3<i1;
  if (i4) goto l3_loop;
l8:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6373))+4);
  i1 = *(OOC_INT32*)((_check_pointer(i1, 6381))+4);
  i = 0;
  i2 = 0<i1;
  if (!i2) goto l16;
  i2 = (OOC_INT32)pragmas;
  i3=0;
l11_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6407))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 6415));
  i4 = _check_pointer(i4, 6421);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 6421))*4);
  i4 = _type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 6425)))), &_td_OOC_Package__KeyValueDesc, 6425);
  kv = (OOC_Package__KeyValue)i4;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 6469))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 6461));
  i4 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 6454)))), Config_Section_Options__SectionDesc_Set)),Config_Section_Options__SectionDesc_Set)((Config_Section_Options__Section)i2, (Object__String)i4, (Config__Variable)i5);
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
  *(OOC_INT32*)((_check_pointer(i0, 6611))+8) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i0, 6630))+12) = (OOC_INT32)0;
  i1 = (OOC_INT32)RT0__NewObject(_td__qtd1.baseTypes[0]);
  ADT_ArrayList__ArrayListDesc_INIT((ADT_ArrayList__ArrayList)i1, 4);
  *(OOC_INT32*)((_check_pointer(i0, 6652))+16) = i1;
  i1 = (OOC_INT32)RT0__NewObject(_td__qtd3.baseTypes[0]);
  ADT_ArrayList__ArrayListDesc_INIT((ADT_ArrayList__ArrayList)i1, 4);
  *(OOC_INT32*)((_check_pointer(i0, 6707))+20) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 6768))+24) = (OOC_INT32)0;
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
  *(OOC_INT32*)((_check_pointer(i0, 6931))+8) = i1;
  return (OOC_Package__Repository)i0;
  ;
}

void OOC_Package__RepositoryDesc_MergePackage(OOC_Package__Repository r, OOC_Package__Package pkg) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_INT32 i;
  OOC_Package__KeyValue kv;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7129))+8);
  i2 = (OOC_INT32)pkg;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 7154))+8);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7129))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7143)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i4, (Object__Object)i3);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 7183));
  i = 0;
  i1 = *(OOC_INT32*)((_check_pointer(i1, 7191))+4);
  i3 = 0<i1;
  if (!i3) goto l8;
  i3=0;
l3_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 7217));
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 7225));
  i4 = _check_pointer(i4, 7231);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 7231))*4);
  i4 = _type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 7235)))), &_td_OOC_Package__KeyValueDesc, 7235);
  kv = (OOC_Package__KeyValue)i4;
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7253));
  i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7253));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 7261)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i6, (Object__Object)i4);
  i3 = i3+1;
  i = i3;
  i4 = i3<i1;
  if (i4) goto l3_loop;
l8:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 7304))+4);
  i1 = *(OOC_INT32*)((_check_pointer(i1, 7312))+4);
  i = 0;
  i3 = 0<i1;
  if (!i3) goto l16;
  i3=0;
l11_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 7338))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 7346));
  i4 = _check_pointer(i4, 7352);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 7352))*4);
  i4 = _type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 7356)))), &_td_OOC_Package__KeyValueDesc, 7356);
  kv = (OOC_Package__KeyValue)i4;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7374))+4);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7374))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 7382)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i6, (Object__Object)i4);
  i3 = i3+1;
  i = i3;
  i4 = i3<i1;
  if (i4) goto l11_loop;
l16:
  return;
  ;
}

OOC_CHAR8 OOC_Package__RepositoryDesc_PackageInstalled(OOC_Package__Repository r, Object__String pkgName) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_INT32 i;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7545))+8);
  i = 0;
  i1 = *(OOC_INT32*)((_check_pointer(i1, 7559))+4);
  i2 = 0<i1;
  if (!i2) goto l11;
  i2 = (OOC_INT32)pkgName;
  i3=0;
l3_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7580))+8);
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 7594));
  i4 = _check_pointer(i4, 7600);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 7600))*4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7580))+8);
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 7594));
  i5 = _check_pointer(i5, 7600);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i3, i6, OOC_UINT32, 7600))*4);
  i4 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 7603)))), Object__StringDesc_Equals)),Object__StringDesc_Equals)((Object__String)i5, (Object__Object)i2);
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
              i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 9057)), 0);
              i1 = *(OOC_INT32*)(_check_pointer(i1, 9036));
              i0 = i1>=i0;
              
              goto l4;
l3:
              i0=1u;
l4:
              i1 = (OOC_INT32)path;
              if (!i0) goto l7;
              i0 = *(OOC_INT32*)(_check_pointer(i1, 9094));
              buffer = (void*)((OOC_INT32)RT0__NewObject(_td_OOC_Package__8582.baseTypes[0], (i0+1)));
l7:
              i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9143)))), Object__StringDesc_ToString8)),Object__StringDesc_ToString8)((Object__String)i1, 63u);
              path = (Object__String)i0;
              i1 = (OOC_INT32)Object__String8Desc_CharsLatin1((Object__String8)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9191)))), &_td_Object__String8Desc, 9191)));
              chars = (Object__CharsLatin1)i1;
              i2 = (OOC_INT32)buffer;
              i3 = OOC_ARRAY_LENGTH((_check_pointer(i2, 9244)), 0);
              _copy_8((const void*)(_check_pointer(i1, 9235)),(void*)(_check_pointer(i2, 9244)),i3);
              i = 0;
              i1 = _check_pointer(i2, 9290);
              i2 = OOC_ARRAY_LENGTH(i1, 0);
              i1 = *(OOC_UINT8*)(i1+(_check_index(0, i2, OOC_UINT16, 9290)));
              i1 = i1!=0u;
              if (i1) goto l10;
              i1=0;
              goto l63;
l10:
              i1=0;
l11_loop:
              i2 = (OOC_INT32)buffer;
              i3 = _check_pointer(i2, 9325);
              i4 = OOC_ARRAY_LENGTH(i3, 0);
              i3 = *(OOC_UINT8*)(i3+(_check_index(i1, i4, OOC_UINT16, 9325)));
              i3 = i3==47u;
              if (i3) goto l57;
              i3 = _check_pointer(i2, 9462);
              i4 = OOC_ARRAY_LENGTH(i3, 0);
              i3 = *(OOC_UINT8*)(i3+(_check_index(i1, i4, OOC_UINT16, 9462)));
              i3 = i3==46u;
              if (i3) goto l16;
              i3=0u;
              goto l18;
l16:
              i3 = _check_pointer(i2, 9482);
              i4 = OOC_ARRAY_LENGTH(i3, 0);
              i3 = *(OOC_UINT8*)(i3+(_check_index((i1+1), i4, OOC_UINT16, 9482)));
              i3 = i3==47u;
              
l18:
              if (i3) goto l55;
              i3 = _check_pointer(i2, 9621);
              i4 = OOC_ARRAY_LENGTH(i3, 0);
              i3 = *(OOC_UINT8*)(i3+(_check_index(i1, i4, OOC_UINT16, 9621)));
              i3 = i3==46u;
              if (i3) goto l22;
              i3=0u;
              goto l24;
l22:
              i3 = _check_pointer(i2, 9641);
              i4 = OOC_ARRAY_LENGTH(i3, 0);
              i3 = *(OOC_UINT8*)(i3+(_check_index((i1+1), i4, OOC_UINT16, 9641)));
              i3 = i3==46u;
              
l24:
              if (i3) goto l26;
              i3=0u;
              goto l28;
l26:
              i3 = _check_pointer(i2, 9681);
              i4 = OOC_ARRAY_LENGTH(i3, 0);
              i3 = *(OOC_UINT8*)(i3+(_check_index((i1+2), i4, OOC_UINT16, 9681)));
              i3 = i3==47u;
              
l28:
              if (i3) goto l40;
l30_loop:
              i3 = _check_pointer(i2, 10231);
              i4 = OOC_ARRAY_LENGTH(i3, 0);
              i3 = *(OOC_UINT8*)(i3+(_check_index(i1, i4, OOC_UINT16, 10231)));
              i3 = i3==0u;
              if (i3) goto l58;
              i3 = _check_pointer(i2, 10299);
              i4 = OOC_ARRAY_LENGTH(i3, 0);
              i3 = *(OOC_UINT8*)(i3+(_check_index(i1, i4, OOC_UINT16, 10299)));
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
              i4 = _check_pointer(i2, 10031);
              i5 = OOC_ARRAY_LENGTH(i4, 0);
              i4 = *(OOC_UINT8*)(i4+(_check_index((i3-1), i5, OOC_UINT16, 10031)));
              i4 = i4==47u;
              
              goto l48;
l46:
              i4=1u;
l48:
              if (!i4) goto l43_loop;
l51:
              i4 = OOC_ARRAY_LENGTH((_check_pointer(i2, 10082)), 0);
              Strings__Delete((void*)(_check_pointer(i2, 10082)), i4, i3, ((i1-i3)+3));
              i = i3;
              i1=i3;
              goto l58;
l52:
              i3 = OOC_ARRAY_LENGTH((_check_pointer(i2, 9825)), 0);
              Strings__Delete((void*)(_check_pointer(i2, 9825)), i3, i1, 3);
              
              goto l58;
l55:
              i3 = OOC_ARRAY_LENGTH((_check_pointer(i2, 9586)), 0);
              Strings__Delete((void*)(_check_pointer(i2, 9586)), i3, i1, 2);
              
              goto l58;
l57:
              i3 = OOC_ARRAY_LENGTH((_check_pointer(i2, 9427)), 0);
              Strings__Delete((void*)(_check_pointer(i2, 9427)), i3, i1, 1);
              
l58:
              i2 = (OOC_INT32)buffer;
              i2 = _check_pointer(i2, 9290);
              i3 = OOC_ARRAY_LENGTH(i2, 0);
              i2 = *(OOC_UINT8*)(i2+(_check_index(i1, i3, OOC_UINT16, 9290)));
              i2 = i2!=0u;
              if (i2) goto l11_loop;
l63:
              i2 = (OOC_INT32)buffer;
              i3 = i1!=0;
              if (i3) goto l66;
              i3=0u;
              goto l68;
l66:
              i3 = _check_pointer(i2, 10557);
              i4 = OOC_ARRAY_LENGTH(i3, 0);
              i3 = *(OOC_UINT8*)(i3+(_check_index((i1-1), i4, OOC_UINT16, 10557)));
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
              i3 = _check_pointer(i2, 10557);
              i4 = OOC_ARRAY_LENGTH(i3, 0);
              i3 = *(OOC_UINT8*)(i3+(_check_index((i1-1), i4, OOC_UINT16, 10557)));
              i3 = i3==47u;
              
l76:
              if (i3) goto l71_loop;
l80:
              i3 = _check_pointer(i2, 10624);
              i4 = OOC_ARRAY_LENGTH(i3, 0);
              *(OOC_UINT8*)(i3+(_check_index(i1, i4, OOC_UINT16, 10624))) = 0u;
              i3 = *(OOC_INT32*)(_check_pointer(i0, 10668));
              i3 = i1!=i3;
              if (i3) goto l83;
              return (Object__String)i0;
              goto l84;
l83:
              i0 = OOC_ARRAY_LENGTH((_check_pointer(i2, 10730)), 0);
              i0 = (OOC_INT32)Object__NewLatin1Region((void*)(_check_pointer(i2, 10730)), i0, 0, i1);
              return (Object__String)i0;
l84:
              _failed_function(8875); return 0;
              ;
            }


          i0 = (OOC_INT32)file;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10931))+4);
          i1 = (OOC_INT32)sourcePrefix;
          i0 = (OOC_INT32)Object__StringDesc_Concat((Object__String)i1, (Object__String)i0);
          i0 = (OOC_INT32)OOC_Package__Normalize_NormalizeFileSet_NormalizeFile_NormalizePath((Object__String)i0);
          name = (Object__String)i0;
          i0 = (OOC_INT32)file;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10956))+8);
          i1 = i1!=(OOC_INT32)0;
          if (i1) goto l3;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11120))+4);
          i1 = (OOC_INT32)destPrefix;
          i0 = (OOC_INT32)Object__StringDesc_Concat((Object__String)i1, (Object__String)i0);
          i0 = (OOC_INT32)OOC_Package__Normalize_NormalizeFileSet_NormalizeFile_NormalizePath((Object__String)i0);
          
          goto l4;
l3:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11036))+8);
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
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11294))+4);
      i2 = (OOC_INT32)sourcePrefix;
      sourcePrefix = (Object__String)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)i2,(void*)i1)),(void*)((OOC_INT32)_c0)));
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11327))+8);
      i1 = i1!=(OOC_INT32)0;
      if (i1) goto l3;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11449))+4);
      i2 = (OOC_INT32)destPrefix;
      i1 = (OOC_INT32)Object__Concat2((void*)i2,(void*)i1);
      
      goto l4;
l3:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11388))+8);
      i2 = (OOC_INT32)destPrefix;
      i1 = (OOC_INT32)Object__Concat2((void*)i2,(void*)i1);
      
l4:
      destPrefix = (Object__String)((OOC_INT32)Object__Concat2((void*)i1,(void*)((OOC_INT32)_c1)));
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11535))+12);
      ptr = (OOC_Package__FileData)i0;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l20;
l7_loop:
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11585)))), &_td_OOC_Package__FileSetDesc);
      if (i1) goto l14;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11670)))), &_td_OOC_Package__FileDesc);
      if (i1) goto l12;
      _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11665)))), 11665);
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
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 11741));
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

          i0 = (OOC_INT32)a;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11994))+8);
          i2 = (OOC_INT32)b;
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11994))+8);
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 12013))+8);
          i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 12003)))), Object__StringDesc_Compare)),Object__StringDesc_Compare)((Object__String)i3, (Object__Object)i4);
          cmp = i1;
          i3 = i1==0;
          if (i3) goto l3;
          i0=i1;
          goto l4;
l3:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12069))+4);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12069))+4);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 12084))+4);
          i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 12074)))), Object__StringDesc_Compare)),Object__StringDesc_Compare)((Object__String)i0, (Object__Object)i2);
          
l4:
          return (i0<0);
          ;
        }


      i0 = (OOC_INT32)list;
      i1 = i0==(OOC_INT32)0;
      if (i1) goto l3;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 12192));
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
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 12400));
      next = (OOC_Package__FileData)i3;
      *(OOC_INT32*)(_check_pointer(i0, 12428)) = i1;
      a = (OOC_Package__FileData)i0;
      ptr = (OOC_Package__FileData)i3;
      i1 = i3!=(OOC_INT32)0;
      if (i1) goto l13;
      i1=i3;
      goto l14;
l13:
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 12545));
      next = (OOC_Package__FileData)i1;
      *(OOC_INT32*)(_check_pointer(i3, 12575)) = i2;
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
      i0 = OOC_Package__Normalize_MergeSort_Less((OOC_Package__File)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12943)))), &_td_OOC_Package__FileDesc, 12943)), (OOC_Package__File)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 12952)))), &_td_OOC_Package__FileDesc, 12952)));
      
      goto l35;
l32:
      i0=1u;
l35:
      if (i0) goto l37;
      i0 = (OOC_INT32)b;
      ptr = (OOC_Package__FileData)i0;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 13051));
      b = (OOC_Package__FileData)i1;
      
      goto l38;
l37:
      i0 = (OOC_INT32)a;
      ptr = (OOC_Package__FileData)i0;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 12993));
      a = (OOC_Package__FileData)i1;
      
l38:
      *(OOC_INT32*)(_check_pointer(i0, 13094)) = (OOC_INT32)0;
      i1 = (OOC_INT32)tail;
      *(OOC_INT32*)(_check_pointer(i1, 13130)) = i0;
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
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 13207));
      return (OOC_Package__FileData)i0;
      goto l49;
l48:
      return (OOC_Package__FileData)i0;
l49:
      _failed_function(11808); return 0;
      ;
    }


  buffer = (void*)(OOC_INT32)0;
  i0 = (OOC_INT32)OOC_Package__NewFileSet();
  norm = (OOC_Package__FileSet)i0;
  *(OOC_INT32*)((_check_pointer(i0, 13316))+4) = ((OOC_INT32)_c2);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13359))+4);
  *(OOC_INT32*)((_check_pointer(i0, 13343))+8) = i1;
  i0 = (OOC_INT32)fileSet;
  OOC_Package__Normalize_NormalizeFileSet((OOC_Package__FileSet)i0, (Object__String)((OOC_INT32)_c3), (Object__String)((OOC_INT32)_c4));
  i0 = (OOC_INT32)norm;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13442))+12);
  i1 = (OOC_INT32)OOC_Package__Normalize_MergeSort((OOC_Package__FileData)i1);
  *(OOC_INT32*)((_check_pointer(i0, 13419))+12) = i1;
  i0 = (OOC_INT32)norm;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13471))+12);
  *(OOC_INT32*)((_check_pointer(i0, 13458))+16) = i1;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13490))+16);
  i1 = i1!=(OOC_INT32)0;
  if (!i1) goto l10;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13525))+16);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 13530));
  i1 = i1!=(OOC_INT32)0;
  if (!i1) goto l10;
l4_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13579))+16);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 13584));
  *(OOC_INT32*)((_check_pointer(i0, 13566))+16) = i1;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13525))+16);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 13530));
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
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14006))+12);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14024))+8);
  i0 = (OOC_INT32)XML_DTD__AttValueDesc_Flatten((XML_DTD__AttValue)i1, (XML_DTD__AttrDecl)i0);
  str = (XML_UnicodeBuffer__CharArray)i0;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 14059)), 0);
  i1 = (OOC_INT32)RT0__NewObject(_td_OOC_Package__13958.baseTypes[0], i1);
  buffer = (void*)i1;
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i1, 14103)), 0);
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i0, 14089)), 0);
  LongStrings__Short((void*)(_check_pointer(i0, 14089)), i3, 63u, (void*)(_check_pointer(i1, 14103)), i2);
  i0 = OOC_ARRAY_LENGTH((_check_pointer(i1, 14141)), 0);
  i0 = (OOC_INT32)Object__NewLatin1((void*)(_check_pointer(i1, 14141)), i0);
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
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14313)))), &_td_Config_Parser__ElementDesc);
  
l5:
  if (i1) goto l7;
  i0=0u;
  goto l8;
l7:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14355)))), &_td_Config_Parser__ElementDesc, 14355)), 14363))+28);
  i0 = (
  _cmp16((const void*)(_check_pointer(i0, 14368)),(const void*)(OOC_INT32)elementName))==0;
  
l8:
  return i0;
  ;
}

static void OOC_Package__ParseKeyValue(Config_Parser__Element elem, ADT_ArrayList__ArrayList list, Config_Section_Options__Section options, Object__String defaultType, XML_Locator__ErrorListener errorListener, OOC_Error__List errList) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  Msg__Msg lastError;
  Config_Parser__Node node;
  auto void OOC_Package__ParseKeyValue_Err(OOC_INT32 code, Config_Parser__Node xmlNode);
  auto void OOC_Package__ParseKeyValue_SetReason(Exception__Exception e);
  auto void OOC_Package__ParseKeyValue_SkipWS(Config_Parser__Node *node);
  auto OOC_Package__KeyValue OOC_Package__ParseKeyValue_ParseDefine(volatile Config_Parser__Element elem);
    
    void OOC_Package__ParseKeyValue_Err(OOC_INT32 code, Config_Parser__Node xmlNode) {
      register OOC_INT32 i0,i1,i2,i3;

      i0 = (OOC_INT32)errorListener;
      i1 = (OOC_INT32)xmlNode;
      i2 = (OOC_INT32)OOC_Package__packageContext;
      i3 = code;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14908)))), XML_Locator__ErrorListenerDesc_Error)),XML_Locator__ErrorListenerDesc_Error)((XML_Locator__ErrorListener)i0, (XML_Error__Context)i2, i3, 0u, (void*)((_check_pointer(i1, 14990))+4));
      lastError = (Msg__Msg)i0;
      i1 = (OOC_INT32)errList;
      OOC_Error__ListDesc_Append((OOC_Error__List)i1, (Msg__Msg)i0);
      return;
      ;
    }

    
    void OOC_Package__ParseKeyValue_SetReason(Exception__Exception e) {
      register OOC_INT32 i0,i1,i2;
      Object__String msg;
      Object__CharsLatin1 chars;

      i0 = (OOC_INT32)e;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15176)))), Exception__ExceptionDesc_GetMessage)),Exception__ExceptionDesc_GetMessage)((Exception__Exception)i0);
      msg = (Object__String)i0;
      i0 = (OOC_INT32)Object__String8Desc_CharsLatin1((Object__String8)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15217)))), &_td_Object__String8Desc, 15217)));
      chars = (Object__CharsLatin1)i0;
      i1 = (OOC_INT32)lastError;
      i2 = OOC_ARRAY_LENGTH((_check_pointer(i0, 15305)), 0);
      i0 = (OOC_INT32)Msg__GetStringPtr((void*)(_check_pointer(i0, 15305)), i2);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15256)))), Msg__MsgDesc_SetStringAttrib)),Msg__MsgDesc_SetStringAttrib)((Msg__Msg)i1, "reason", 7, (Msg__StringPtr)i0);
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
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15418)))), &_td_Config_Parser__CharDataDesc);
      
l5:
      if (!i1) goto l19;
      
l7_loop:
      i1 = Config_Parser__NodeDesc_IsWhitespace((Config_Parser__Node)i0);
      i1 = !i1;
      if (!i1) goto l10;
      OOC_Package__ParseKeyValue_Err(2, (Config_Parser__Node)i0);
l10:
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 15549));
      *node = (Config_Parser__Node)i0;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l13;
      i1=0u;
      goto l15;
l13:
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15418)))), &_td_Config_Parser__CharDataDesc);
      
l15:
      if (i1) goto l7_loop;
l19:
      return;
      ;
    }

    
    OOC_Package__KeyValue OOC_Package__ParseKeyValue_ParseDefine(volatile Config_Parser__Element elem) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
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
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 15990))+32);
      i = 0;
      i2 = *(OOC_INT32*)(_check_pointer(i2, 15999));
      i3 = 0<i2;
      if (i3) goto l3;
      i2=i0;i0=(OOC_INT32)0;
      goto l17;
l3:
      i4=i0;i0=0;i3=(OOC_INT32)0;
l4_loop:
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 16028))+32);
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 16037))+4);
      i5 = _check_pointer(i5, 16042);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i0, i6, OOC_UINT32, 16042))*4);
      att = (XML_Builder__Attribute)i5;
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 16062))+4);
      i6 = (
      _cmp16((const void*)(_check_pointer(i6, 16072)),(const void*)((OOC_CHAR16[]){110,97,109,101,0})))==0;
      if (i6) goto l11;
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 16142))+4);
      i6 = (
      _cmp16((const void*)(_check_pointer(i6, 16152)),(const void*)((OOC_CHAR16[]){116,121,112,101,0})))==0;
      if (i6) goto l9;
      OOC_Package__ParseKeyValue_Err(3, (Config_Parser__Node)i1);
      i6 = (OOC_INT32)lastError;
      i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 16322))+4);
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 16322))+4);
      i5 = OOC_ARRAY_LENGTH((_check_pointer(i5, 16332)), 0);
      i5 = (OOC_INT32)Msg__GetLStringPtr((void*)(_check_pointer(i7, 16332)), i5);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 16275)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i6, "name", 5, (Msg__LStringPtr)i5);
      
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
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 16598))+36);
      node = (Config_Parser__Node)i3;
      i4 = i3!=(OOC_INT32)0;
      if (!i4) goto l34;
      {register OOC_INT32 h0=i0;i0=i3;i3=h0;}
l25_loop:
      i4 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16657)))), &_td_Config_Parser__CharDataDesc);
      if (i4) goto l28;
      OOC_Package__ParseKeyValue_Err(15, (Config_Parser__Node)i0);
      
      goto l29;
l28:
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16712))+28);
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16712))+28);
      i5 = OOC_ARRAY_LENGTH((_check_pointer(i5, 16719)), 0);
      LongStrings__Short((void*)(_check_pointer(i4, 16719)), i5, 63u, (void*)(OOC_INT32)str, 1024);
      i4 = (OOC_INT32)Object__NewLatin1((void*)(OOC_INT32)str, 1024);
      i3 = (OOC_INT32)Object__StringDesc_Concat((Object__String)i3, (Object__String)i4);
      stringBuffer = (Object__String)i3;
      
l29:
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 16902));
      node = (Config_Parser__Node)i0;
      i4 = i0!=(OOC_INT32)0;
      if (i4) goto l25_loop;
l33:
      i0=i3;
l34:
      i3 = (OOC_INT32)Object__String8Desc_CharsLatin1((Object__String8)(_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 16956)))), &_td_Object__String8Desc, 16956)));
      chars = (Object__CharsLatin1)i3;
      i4 = (OOC_INT32)options;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 17021))+8);
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
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 17216)))), Config__VariableDesc_StringToValue)),Config__VariableDesc_StringToValue)((Config__Variable)i2, (Object__String)i0);
        Exception__PopContext(1);
l44:;
      }
      goto l46;
l45:
      OOC_Package__ParseKeyValue_Err(16, (Config_Parser__Node)i1);
      i0 = (OOC_INT32)lastError;
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i3, 17168)), 0);
      i1 = (OOC_INT32)Msg__GetStringPtr((void*)(_check_pointer(i3, 17168)), i1);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17121)))), Msg__MsgDesc_SetStringAttrib)),Msg__MsgDesc_SetStringAttrib)((Msg__Msg)i0, "type", 5, (Msg__StringPtr)i1);
l46:
      i0 = (OOC_INT32)name;
      i1 = (OOC_INT32)value;
      i0 = (OOC_INT32)OOC_Package__NewKeyValue((Object__String)i0, (Config__Variable)i1);
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
      _failed_function(15600); return 0;
      ;
    }


  i0 = (OOC_INT32)elem;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17498))+32);
  i1 = *(OOC_INT32*)(_check_pointer(i1, 17507));
  i1 = i1!=0;
  if (!i1) goto l4;
  OOC_Package__ParseKeyValue_Err(3, (Config_Parser__Node)i0);
  i0 = (OOC_INT32)lastError;
  i1 = (OOC_INT32)elem;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 17620))+32);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 17629))+4);
  i2 = _check_pointer(i2, 17634);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(0, i3, OOC_UINT8, 17634))*4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 17637))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 17620))+32);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 17629))+4);
  i3 = _check_pointer(i3, 17634);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(0, i4, OOC_UINT8, 17634))*4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 17637))+4);
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 17647)), 0);
  i2 = (OOC_INT32)Msg__GetLStringPtr((void*)(_check_pointer(i2, 17647)), i3);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17572)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i0, "name", 5, (Msg__LStringPtr)i2);
  i0=i1;
l4:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17682))+36);
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
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 17928));
  node = (Config_Parser__Node)i0;
  goto l11;
l10:
  i1 = (OOC_INT32)list;
  i0 = (OOC_INT32)OOC_Package__ParseKeyValue_ParseDefine((Config_Parser__Element)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17820)))), &_td_Config_Parser__ElementDesc, 17820)));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17788)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i1, (Object__Object)i0);
  i0 = (OOC_INT32)node;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 17852));
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

      i0 = (OOC_INT32)errorListener;
      i1 = (OOC_INT32)xmlNode;
      i2 = (OOC_INT32)OOC_Package__packageContext;
      i3 = code;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18387)))), XML_Locator__ErrorListenerDesc_Error)),XML_Locator__ErrorListenerDesc_Error)((XML_Locator__ErrorListener)i0, (XML_Error__Context)i2, i3, 0u, (void*)((_check_pointer(i1, 18469))+4));
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
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18610)))), &_td_Config_Parser__CharDataDesc);
      
l5:
      if (!i1) goto l19;
      
l7_loop:
      i1 = Config_Parser__NodeDesc_IsWhitespace((Config_Parser__Node)i0);
      i1 = !i1;
      if (!i1) goto l10;
      OOC_Package__ProcessPackage_Err(2, (Config_Parser__Node)i0);
l10:
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 18741));
      *node = (Config_Parser__Node)i0;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l13;
      i1=0u;
      goto l15;
l13:
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18610)))), &_td_Config_Parser__CharDataDesc);
      
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
          OOC_INT32 i;
          OOC_INT8 res;

          i0 = (OOC_INT32)att;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19245))+12);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19263))+8);
          i1 = (OOC_INT32)XML_DTD__AttValueDesc_Flatten((XML_DTD__AttValue)i1, (XML_DTD__AttrDecl)i2);
          str = (XML_UnicodeBuffer__CharArray)i1;
          i2 = OOC_ARRAY_LENGTH((_check_pointer(i1, 19294)), 0);
          i2 = i2<128;
          if (!i2) goto l10;
          i2 = OOC_ARRAY_LENGTH((_check_pointer(i1, 19347)), 0);
          LongStrings__Short((void*)(_check_pointer(i1, 19347)), i2, 63u, (void*)(OOC_INT32)buffer, 128);
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
          i1 = (OOC_INT32)lastError;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19616))+4);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19616))+4);
          i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 19626)), 0);
          i0 = (OOC_INT32)Msg__GetLStringPtr((void*)(_check_pointer(i2, 19626)), i0);
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 19569)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i1, "name", 5, (Msg__LStringPtr)i0);
          return 0;
          ;
        }


      i0 = (OOC_INT32)OOC_Package__NewVersion();
      version = (OOC_Package__Version)i0;
      i0 = (OOC_INT32)elem;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19739))+32);
      i = 0;
      i0 = *(OOC_INT32*)(_check_pointer(i0, 19748));
      i1 = 0<i0;
      if (!i1) goto l20;
      i1=0;
l3_loop:
      i2 = (OOC_INT32)elem;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 19777))+32);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 19786))+4);
      i3 = _check_pointer(i3, 19791);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i1 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i1, i4, OOC_UINT32, 19791))*4);
      att = (XML_Builder__Attribute)i1;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 19811))+4);
      i3 = (
      _cmp16((const void*)(_check_pointer(i3, 19821)),(const void*)((OOC_CHAR16[]){99,117,114,114,101,110,116,0})))==0;
      if (i3) goto l14;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 19903))+4);
      i3 = (
      _cmp16((const void*)(_check_pointer(i3, 19913)),(const void*)((OOC_CHAR16[]){97,103,101,0})))==0;
      if (i3) goto l12;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 19987))+4);
      i3 = (
      _cmp16((const void*)(_check_pointer(i3, 19997)),(const void*)((OOC_CHAR16[]){114,101,118,105,115,105,111,110,0})))==0;
      if (i3) goto l10;
      OOC_Package__ProcessPackage_Err(3, (Config_Parser__Node)i2);
      i2 = (OOC_INT32)lastError;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 20181))+4);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 20181))+4);
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 20191)), 0);
      i1 = (OOC_INT32)Msg__GetLStringPtr((void*)(_check_pointer(i3, 20191)), i1);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 20134)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i2, "name", 5, (Msg__LStringPtr)i1);
      goto l15;
l10:
      i2 = (OOC_INT32)version;
      i1 = OOC_Package__ProcessPackage_ParseVersion_Unsigned((XML_Builder__Attribute)i1);
      *(OOC_INT32*)((_check_pointer(i2, 20035))+8) = i1;
      goto l15;
l12:
      i2 = (OOC_INT32)version;
      i1 = OOC_Package__ProcessPackage_ParseVersion_Unsigned((XML_Builder__Attribute)i1);
      *(OOC_INT32*)((_check_pointer(i2, 19946))+4) = i1;
      goto l15;
l14:
      i2 = (OOC_INT32)version;
      i1 = OOC_Package__ProcessPackage_ParseVersion_Unsigned((XML_Builder__Attribute)i1);
      *(OOC_INT32*)(_check_pointer(i2, 19858)) = i1;
l15:
      i1 = i;
      i1 = i1+1;
      i = i1;
      i2 = i1<i0;
      if (i2) goto l3_loop;
l20:
      i0 = (OOC_INT32)version;
      i1 = *(OOC_INT32*)(_check_pointer(i0, 20236));
      i2 = (OOC_INT32)elem;
      i1 = i1==(-1);
      if (!i1) goto l23;
      OOC_Package__ProcessPackage_Err(7, (Config_Parser__Node)i2);
l23:
      i1 = *(OOC_INT32*)((_check_pointer(i0, 20328))+8);
      i1 = i1==(-1);
      if (!i1) goto l26;
      OOC_Package__ProcessPackage_Err(8, (Config_Parser__Node)i2);
l26:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 20419))+36);
      i1 = i1!=0;
      if (!i1) goto l29;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 20472))+36);
      OOC_Package__ProcessPackage_Err(0, (Config_Parser__Node)i1);
      i1 = (OOC_INT32)lastError;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 20548))+28);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 20548))+28);
      i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 20553)), 0);
      i2 = (OOC_INT32)Msg__GetLStringPtr((void*)(_check_pointer(i3, 20553)), i2);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 20500)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i1, "name", 5, (Msg__LStringPtr)i2);
l29:
      _copy_8((const void*)"",(void*)((_check_pointer(i0, 20589))+12),32);
      i1 = *(OOC_INT32*)(_check_pointer(i0, 20632));
      IntStr__IntToStr(i1, (void*)(OOC_INT32)str, 32);
      Strings__Append((void*)(OOC_INT32)str, 32, (void*)((_check_pointer(i0, 20681))+12), 32);
      Strings__Append(":", 2, (void*)((_check_pointer(i0, 20723))+12), 32);
      i1 = *(OOC_INT32*)((_check_pointer(i0, 20761))+4);
      IntStr__IntToStr(i1, (void*)(OOC_INT32)str, 32);
      Strings__Append((void*)(OOC_INT32)str, 32, (void*)((_check_pointer(i0, 20806))+12), 32);
      Strings__Append(":", 2, (void*)((_check_pointer(i0, 20848))+12), 32);
      i1 = *(OOC_INT32*)((_check_pointer(i0, 20886))+8);
      IntStr__IntToStr(i1, (void*)(OOC_INT32)str, 32);
      Strings__Append((void*)(OOC_INT32)str, 32, (void*)((_check_pointer(i0, 20936))+12), 32);
      return (OOC_Package__Version)i0;
      ;
    }

    
    OOC_Package__Executable OOC_Package__ProcessPackage_ParseExecutable(Config_Parser__Element elem) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
      OOC_Package__Executable executable;
      OOC_INT32 i;
      XML_Builder__Attribute att;

      i0 = (OOC_INT32)OOC_Package__NewExecutable();
      executable = (OOC_Package__Executable)i0;
      i1 = (OOC_INT32)elem;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 21258))+32);
      i = 0;
      i2 = *(OOC_INT32*)(_check_pointer(i2, 21267));
      i3 = 0<i2;
      if (!i3) goto l12;
      i3=0;
l3_loop:
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 21296))+32);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 21305))+4);
      i4 = _check_pointer(i4, 21310);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 21310))*4);
      att = (XML_Builder__Attribute)i4;
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 21330))+4);
      i5 = (
      _cmp16((const void*)(_check_pointer(i5, 21340)),(const void*)((OOC_CHAR16[]){109,97,105,110,45,109,111,100,117,108,101,0})))==0;
      if (i5) goto l6;
      OOC_Package__ProcessPackage_Err(3, (Config_Parser__Node)i1);
      i5 = (OOC_INT32)lastError;
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 21534))+4);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 21534))+4);
      i4 = OOC_ARRAY_LENGTH((_check_pointer(i4, 21544)), 0);
      i4 = (OOC_INT32)Msg__GetLStringPtr((void*)(_check_pointer(i6, 21544)), i4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 21487)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i5, "name", 5, (Msg__LStringPtr)i4);
      goto l7;
l6:
      i4 = (OOC_INT32)OOC_Package__StringAttr((XML_Builder__Attribute)i4);
      *(OOC_INT32*)(_check_pointer(i0, 21384)) = i4;
l7:
      i3 = i3+1;
      i = i3;
      i4 = i3<i2;
      if (i4) goto l3_loop;
l12:
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 21592));
      i2 = i2==0;
      if (!i2) goto l15;
      OOC_Package__ProcessPackage_Err(9, (Config_Parser__Node)i1);
l15:
      return (OOC_Package__Executable)i0;
      ;
    }

    
    OOC_Package__Library OOC_Package__ProcessPackage_ParseLibrary(Config_Parser__Element elem) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
      OOC_Package__Library library;
      OOC_INT32 i;
      XML_Builder__Attribute att;
      Config_Parser__Node node;

      i0 = (OOC_INT32)OOC_Package__NewLibrary();
      library = (OOC_Package__Library)i0;
      i1 = (OOC_INT32)elem;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 21990))+32);
      i = 0;
      i2 = *(OOC_INT32*)(_check_pointer(i2, 21999));
      i3 = 0<i2;
      if (!i3) goto l16;
      i3=0;
l3_loop:
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 22028))+32);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 22037))+4);
      i4 = _check_pointer(i4, 22042);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 22042))*4);
      att = (XML_Builder__Attribute)i4;
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 22062))+4);
      i5 = (
      _cmp16((const void*)(_check_pointer(i5, 22072)),(const void*)((OOC_CHAR16[]){110,97,109,101,0})))==0;
      if (i5) goto l10;
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 22150))+4);
      i5 = (
      _cmp16((const void*)(_check_pointer(i5, 22160)),(const void*)((OOC_CHAR16[]){109,97,105,110,45,109,111,100,117,108,101,0})))==0;
      if (i5) goto l8;
      OOC_Package__ProcessPackage_Err(3, (Config_Parser__Node)i1);
      i5 = (OOC_INT32)lastError;
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 22351))+4);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 22351))+4);
      i4 = OOC_ARRAY_LENGTH((_check_pointer(i4, 22361)), 0);
      i4 = (OOC_INT32)Msg__GetLStringPtr((void*)(_check_pointer(i6, 22361)), i4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 22304)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i5, "name", 5, (Msg__LStringPtr)i4);
      goto l11;
l8:
      i4 = (OOC_INT32)OOC_Package__StringAttr((XML_Builder__Attribute)i4);
      *(OOC_INT32*)((_check_pointer(i0, 22201))+4) = i4;
      goto l11;
l10:
      i4 = (OOC_INT32)OOC_Package__StringAttr((XML_Builder__Attribute)i4);
      *(OOC_INT32*)(_check_pointer(i0, 22106)) = i4;
l11:
      i3 = i3+1;
      i = i3;
      i4 = i3<i2;
      if (i4) goto l3_loop;
l16:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22406))+4);
      i2 = i2==0;
      if (!i2) goto l19;
      OOC_Package__ProcessPackage_Err(9, (Config_Parser__Node)i1);
l19:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 22507))+36);
      node = (Config_Parser__Node)i2;
      OOC_Package__ProcessPackage_SkipWS((void*)(OOC_INT32)&node);
      i2 = (OOC_INT32)node;
      i3 = OOC_Package__AtElement((Config_Parser__Node)i2, ((OOC_CHAR16[]){118,101,114,115,105,111,110,0}), 8);
      if (i3) goto l22;
      OOC_Package__ProcessPackage_Err(6, (Config_Parser__Node)i1);
      goto l23;
l22:
      i1 = (OOC_INT32)OOC_Package__ProcessPackage_ParseVersion((Config_Parser__Element)(_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 22630)))), &_td_Config_Parser__ElementDesc, 22630)));
      *(OOC_INT32*)((_check_pointer(i0, 22593))+8) = i1;
      i1 = (OOC_INT32)node;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 22661));
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
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
      OOC_Package__FileSet fileSet;
      OOC_INT32 i;
      XML_Builder__Attribute att;
      Config_Parser__Node node;
      auto OOC_Package__File OOC_Package__ProcessPackage_ParseFileSet_ParseFile(Config_Parser__Element elem);
        
        OOC_Package__File OOC_Package__ProcessPackage_ParseFileSet_ParseFile(Config_Parser__Element elem) {
          register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
          Object__String name;
          Object__String destName;
          OOC_INT32 i;
          XML_Builder__Attribute att;
          Config_Parser__Node node;

          name = (Object__String)(OOC_INT32)0;
          destName = (Object__String)(OOC_INT32)0;
          i0 = (OOC_INT32)elem;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23386))+32);
          i = 0;
          i1 = *(OOC_INT32*)(_check_pointer(i1, 23395));
          i2 = 0<i1;
          if (i2) goto l3;
          i1=(OOC_INT32)0;i2=(OOC_INT32)0;
          goto l17;
l3:
          i2=0;i3=(OOC_INT32)0;i4=(OOC_INT32)0;
l4_loop:
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23426))+32);
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 23435))+4);
          i5 = _check_pointer(i5, 23440);
          i6 = OOC_ARRAY_LENGTH(i5, 0);
          i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i2, i6, OOC_UINT32, 23440))*4);
          att = (XML_Builder__Attribute)i5;
          i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 23462))+4);
          i6 = (
          _cmp16((const void*)(_check_pointer(i6, 23472)),(const void*)((OOC_CHAR16[]){110,97,109,101,0})))==0;
          if (i6) goto l11;
          i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 23546))+4);
          i6 = (
          _cmp16((const void*)(_check_pointer(i6, 23556)),(const void*)((OOC_CHAR16[]){100,101,115,116,45,110,97,109,101,0})))==0;
          if (i6) goto l9;
          OOC_Package__ProcessPackage_Err(3, (Config_Parser__Node)i0);
          i6 = (OOC_INT32)lastError;
          i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 23743))+4);
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 23743))+4);
          i5 = OOC_ARRAY_LENGTH((_check_pointer(i5, 23753)), 0);
          i5 = (OOC_INT32)Msg__GetLStringPtr((void*)(_check_pointer(i7, 23753)), i5);
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 23696)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i6, "name", 5, (Msg__LStringPtr)i5);
          
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
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23899))+36);
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
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 24154))+32);
      i = 0;
      i2 = *(OOC_INT32*)(_check_pointer(i2, 24163));
      i3 = 0<i2;
      if (!i3) goto l16;
      i3=0;
l3_loop:
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 24192))+32);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 24201))+4);
      i4 = _check_pointer(i4, 24206);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 24206))*4);
      att = (XML_Builder__Attribute)i4;
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 24226))+4);
      i5 = (
      _cmp16((const void*)(_check_pointer(i5, 24236)),(const void*)((OOC_CHAR16[]){115,111,117,114,99,101,45,100,105,114,0})))==0;
      if (i5) goto l10;
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 24325))+4);
      i5 = (
      _cmp16((const void*)(_check_pointer(i5, 24335)),(const void*)((OOC_CHAR16[]){100,101,115,116,45,100,105,114,0})))==0;
      if (i5) goto l8;
      OOC_Package__ProcessPackage_Err(3, (Config_Parser__Node)i1);
      i5 = (OOC_INT32)lastError;
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 24520))+4);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 24520))+4);
      i4 = OOC_ARRAY_LENGTH((_check_pointer(i4, 24530)), 0);
      i4 = (OOC_INT32)Msg__GetLStringPtr((void*)(_check_pointer(i6, 24530)), i4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 24473)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i5, "name", 5, (Msg__LStringPtr)i4);
      goto l11;
l8:
      i4 = (OOC_INT32)OOC_Package__StringAttr((XML_Builder__Attribute)i4);
      *(OOC_INT32*)((_check_pointer(i0, 24373))+8) = i4;
      goto l11;
l10:
      i4 = (OOC_INT32)OOC_Package__StringAttr((XML_Builder__Attribute)i4);
      *(OOC_INT32*)((_check_pointer(i0, 24276))+4) = i4;
l11:
      i3 = i3+1;
      i = i3;
      i4 = i3<i2;
      if (i4) goto l3_loop;
l16:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24575))+4);
      i0 = i0==0;
      if (!i0) goto l19;
      OOC_Package__ProcessPackage_Err(10, (Config_Parser__Node)i1);
l19:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 24674))+36);
      node = (Config_Parser__Node)i0;
      OOC_Package__ProcessPackage_SkipWS((void*)(OOC_INT32)&node);
      i0 = (OOC_INT32)node;
      i1 = i0!=0;
      if (!i1) goto l35;
l22_loop:
      i1 = OOC_Package__AtElement((Config_Parser__Node)i0, ((OOC_CHAR16[]){102,105,108,101,45,115,101,116,0}), 9);
      if (i1) goto l29;
      i1 = OOC_Package__AtElement((Config_Parser__Node)i0, ((OOC_CHAR16[]){102,105,108,101,0}), 5);
      if (i1) goto l27;
      OOC_Package__ProcessPackage_Err(12, (Config_Parser__Node)i0);
      i0 = (OOC_INT32)node;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 25084));
      node = (Config_Parser__Node)i0;
      goto l30;
l27:
      i0 = (OOC_INT32)OOC_Package__ProcessPackage_ParseFileSet_ParseFile((Config_Parser__Element)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 24961)))), &_td_Config_Parser__ElementDesc, 24961)));
      i1 = (OOC_INT32)fileSet;
      OOC_Package__FileSetDesc_Append((OOC_Package__FileSet)i1, (OOC_Package__FileData)i0);
      i0 = (OOC_INT32)node;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 24995));
      node = (Config_Parser__Node)i0;
      goto l30;
l29:
      i0 = (OOC_INT32)OOC_Package__ProcessPackage_ParseFileSet((Config_Parser__Element)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 24826)))), &_td_Config_Parser__ElementDesc, 24826)));
      i1 = (OOC_INT32)fileSet;
      OOC_Package__FileSetDesc_Append((OOC_Package__FileSet)i1, (OOC_Package__FileData)i0);
      i0 = (OOC_INT32)node;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 24860));
      node = (Config_Parser__Node)i0;
l30:
      OOC_Package__ProcessPackage_SkipWS((void*)(OOC_INT32)&node);
      i0 = (OOC_INT32)node;
      i1 = i0!=0;
      if (i1) goto l22_loop;
l35:
      i0 = (OOC_INT32)fileSet;
      return (OOC_Package__FileSet)i0;
      ;
    }


  i0 = (OOC_INT32)root;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25206))+28);
  i1 = (
  _cmp16((const void*)(_check_pointer(i1, 25211)),(const void*)((OOC_CHAR16[]){112,97,99,107,97,103,101,0})))!=0;
  if (!i1) goto l3;
  OOC_Package__ProcessPackage_Err(1, (Config_Parser__Node)i0);
  i0 = (OOC_INT32)lastError;
  i1 = (OOC_INT32)Msg__GetLStringPtr(((OOC_CHAR16[]){112,97,99,107,97,103,101,0}), 8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 25283)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i0, "name", 5, (Msg__LStringPtr)i1);
l3:
  i0 = (OOC_INT32)OOC_Package__NewPackage();
  pkg = (OOC_Package__Package)i0;
  i0 = (OOC_INT32)root;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25399))+32);
  i = 0;
  i0 = *(OOC_INT32*)(_check_pointer(i0, 25408));
  i1 = 0<i0;
  if (!i1) goto l15;
  i1=0;
l6_loop:
  i2 = (OOC_INT32)root;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 25435))+32);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 25444))+4);
  i3 = _check_pointer(i3, 25449);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i1, i4, OOC_UINT32, 25449))*4);
  att = (XML_Builder__Attribute)i1;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 25467))+4);
  i3 = (
  _cmp16((const void*)(_check_pointer(i3, 25477)),(const void*)((OOC_CHAR16[]){110,97,109,101,0})))==0;
  if (i3) goto l9;
  OOC_Package__ProcessPackage_Err(3, (Config_Parser__Node)i2);
  i1 = (OOC_INT32)lastError;
  i2 = (OOC_INT32)att;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 25643))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 25643))+4);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 25653)), 0);
  i2 = (OOC_INT32)Msg__GetLStringPtr((void*)(_check_pointer(i3, 25653)), i2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 25596)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i1, "name", 5, (Msg__LStringPtr)i2);
  goto l10;
l9:
  i2 = (OOC_INT32)pkg;
  i1 = (OOC_INT32)OOC_Package__StringAttr((XML_Builder__Attribute)i1);
  *(OOC_INT32*)((_check_pointer(i2, 25505))+8) = i1;
l10:
  i1 = i;
  i1 = i1+1;
  i = i1;
  i2 = i1<i0;
  if (i2) goto l6_loop;
l15:
  i0 = (OOC_INT32)pkg;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25688))+8);
  i0 = i0==0;
  if (!i0) goto l18;
  i0 = (OOC_INT32)root;
  OOC_Package__ProcessPackage_Err(5, (Config_Parser__Node)i0);
l18:
  i0 = (OOC_INT32)root;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25775))+36);
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
  i0 = (OOC_INT32)OOC_Package__ProcessPackage_ParseVersion((Config_Parser__Element)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 25888)))), &_td_Config_Parser__ElementDesc, 25888)));
  *(OOC_INT32*)((_check_pointer(i1, 25851))+12) = i0;
  i0 = (OOC_INT32)node;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 25917));
  node = (Config_Parser__Node)i0;
  OOC_Package__ProcessPackage_SkipWS((void*)(OOC_INT32)&node);
l22:
  i0 = (OOC_INT32)node;
  i0 = OOC_Package__AtElement((Config_Parser__Node)i0, ((OOC_CHAR16[]){114,101,113,117,105,114,101,115,0}), 9);
  if (!i0) goto l30;
l25_loop:
  i0 = (OOC_INT32)node;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 26068));
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
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 26197));
  i2 = (OOC_INT32)OOC_Config__options;
  i3 = (OOC_INT32)OOC_Package__stringType;
  i4 = (OOC_INT32)errList;
  i5 = (OOC_INT32)errorListener;
  OOC_Package__ParseKeyValue((Config_Parser__Element)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 26184)))), &_td_Config_Parser__ElementDesc, 26184)), (ADT_ArrayList__ArrayList)i1, (Config_Section_Options__Section)i2, (Object__String)i3, (XML_Locator__ErrorListener)i5, (OOC_Error__List)i4);
  i0 = (OOC_INT32)node;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 26298));
  node = (Config_Parser__Node)i0;
  OOC_Package__ProcessPackage_SkipWS((void*)(OOC_INT32)&node);
l33:
  i0 = (OOC_INT32)node;
  i1 = OOC_Package__AtElement((Config_Parser__Node)i0, ((OOC_CHAR16[]){112,114,97,103,109,97,115,0}), 8);
  if (!i1) goto l36;
  i1 = (OOC_INT32)pkg;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 26427))+4);
  i2 = (OOC_INT32)OOC_Config__pragmas;
  i3 = (OOC_INT32)OOC_Package__stringType;
  i4 = (OOC_INT32)errList;
  i5 = (OOC_INT32)errorListener;
  OOC_Package__ParseKeyValue((Config_Parser__Element)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 26414)))), &_td_Config_Parser__ElementDesc, 26414)), (ADT_ArrayList__ArrayList)i1, (Config_Section_Options__Section)i2, (Object__String)i3, (XML_Locator__ErrorListener)i5, (OOC_Error__List)i4);
  i0 = (OOC_INT32)node;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 26528));
  node = (Config_Parser__Node)i0;
  OOC_Package__ProcessPackage_SkipWS((void*)(OOC_INT32)&node);
l36:
  i0 = (OOC_INT32)node;
  i0 = OOC_Package__AtElement((Config_Parser__Node)i0, ((OOC_CHAR16[]){108,105,98,114,97,114,121,0}), 8);
  if (!i0) goto l44;
l39_loop:
  i0 = (OOC_INT32)pkg;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26622))+16);
  i2 = (OOC_INT32)node;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26622))+16);
  i2 = (OOC_INT32)OOC_Package__ProcessPackage_ParseLibrary((Config_Parser__Element)(_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 26663)))), &_td_Config_Parser__ElementDesc, 26663)));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 26630)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i0, (Object__Object)i2);
  i0 = (OOC_INT32)node;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 26693));
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
  i0 = (OOC_INT32)pkg;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26785))+20);
  i2 = (OOC_INT32)node;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26785))+20);
  i2 = (OOC_INT32)OOC_Package__ProcessPackage_ParseExecutable((Config_Parser__Element)(_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 26832)))), &_td_Config_Parser__ElementDesc, 26832)));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 26796)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i0, (Object__Object)i2);
  i0 = (OOC_INT32)node;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 26862));
  node = (Config_Parser__Node)i0;
  OOC_Package__ProcessPackage_SkipWS((void*)(OOC_INT32)&node);
  i0 = (OOC_INT32)node;
  i0 = OOC_Package__AtElement((Config_Parser__Node)i0, ((OOC_CHAR16[]){101,120,101,99,117,116,97,98,108,101,0}), 11);
  if (i0) goto l47_loop;
l52:
  i0 = (OOC_INT32)pkg;
  i1 = (OOC_INT32)OOC_Package__NewFileSet();
  *(OOC_INT32*)((_check_pointer(i0, 26910))+24) = i1;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26943))+24);
  *(OOC_INT32*)((_check_pointer(i1, 26951))+4) = ((OOC_INT32)_c6);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26977))+24);
  *(OOC_INT32*)((_check_pointer(i0, 26985))+8) = ((OOC_INT32)_c7);
  i0 = (OOC_INT32)node;
  i1 = OOC_Package__AtElement((Config_Parser__Node)i0, ((OOC_CHAR16[]){102,105,108,101,45,115,101,116,0}), 9);
  if (!i1) goto l61;
l56_loop:
  i1 = (OOC_INT32)pkg;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 27052))+24);
  i0 = (OOC_INT32)OOC_Package__ProcessPackage_ParseFileSet((Config_Parser__Element)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 27093)))), &_td_Config_Parser__ElementDesc, 27093)));
  OOC_Package__FileSetDesc_Append((OOC_Package__FileSet)i1, (OOC_Package__FileData)i0);
  i0 = (OOC_INT32)node;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 27123));
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
  i0 = *(OOC_INT32*)(_check_pointer(i0, 27249));
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

      i0 = (OOC_INT32)errorListener;
      i1 = (OOC_INT32)xmlNode;
      i2 = (OOC_INT32)OOC_Package__packageContext;
      i3 = code;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 27692)))), XML_Locator__ErrorListenerDesc_Error)),XML_Locator__ErrorListenerDesc_Error)((XML_Locator__ErrorListener)i0, (XML_Error__Context)i2, i3, 0u, (void*)((_check_pointer(i1, 27774))+4));
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
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 27915)))), &_td_Config_Parser__CharDataDesc);
      
l5:
      if (!i1) goto l19;
      
l7_loop:
      i1 = Config_Parser__NodeDesc_IsWhitespace((Config_Parser__Node)i0);
      i1 = !i1;
      if (!i1) goto l10;
      OOC_Package__ProcessRepository_Err(2, (Config_Parser__Node)i0);
l10:
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 28046));
      *node = (Config_Parser__Node)i0;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l13;
      i1=0u;
      goto l15;
l13:
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 27915)))), &_td_Config_Parser__CharDataDesc);
      
l15:
      if (i1) goto l7_loop;
l19:
      return;
      ;
    }

    
    Object__String OOC_Package__ProcessRepository_ParseInstalled(Config_Parser__Element elem) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
      Object__String package;
      OOC_INT32 i;
      XML_Builder__Attribute att;

      package = (Object__String)(OOC_INT32)0;
      i0 = (OOC_INT32)elem;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28316))+32);
      i = 0;
      i1 = *(OOC_INT32*)(_check_pointer(i1, 28325));
      i2 = 0<i1;
      if (i2) goto l3;
      i1=(OOC_INT32)0;
      goto l13;
l3:
      i2=0;i3=(OOC_INT32)0;
l4_loop:
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28354))+32);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 28363))+4);
      i4 = _check_pointer(i4, 28368);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i2, i5, OOC_UINT32, 28368))*4);
      att = (XML_Builder__Attribute)i4;
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 28388))+4);
      i5 = (
      _cmp16((const void*)(_check_pointer(i5, 28398)),(const void*)((OOC_CHAR16[]){112,97,99,107,97,103,101,0})))==0;
      if (i5) goto l7;
      OOC_Package__ProcessRepository_Err(3, (Config_Parser__Node)i0);
      i5 = (OOC_INT32)lastError;
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 28574))+4);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 28574))+4);
      i4 = OOC_ARRAY_LENGTH((_check_pointer(i4, 28584)), 0);
      i4 = (OOC_INT32)Msg__GetLStringPtr((void*)(_check_pointer(i6, 28584)), i4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 28527)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i5, "name", 5, (Msg__LStringPtr)i4);
      
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
      _failed_function(28097); return 0;
      ;
    }


  i0 = (OOC_INT32)root;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28796))+28);
  i1 = (
  _cmp16((const void*)(_check_pointer(i1, 28801)),(const void*)((OOC_CHAR16[]){114,101,112,111,115,105,116,111,114,121,0})))!=0;
  if (!i1) goto l3;
  OOC_Package__ProcessRepository_Err(1, (Config_Parser__Node)i0);
  i0 = (OOC_INT32)lastError;
  i1 = (OOC_INT32)Msg__GetLStringPtr(((OOC_CHAR16[]){114,101,112,111,115,105,116,111,114,121,0}), 11);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 28876)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i0, "name", 5, (Msg__LStringPtr)i1);
l3:
  i0 = (OOC_INT32)OOC_Package__NewRepository();
  rep = (OOC_Package__Repository)i0;
  i0 = (OOC_INT32)root;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28992))+36);
  node = (Config_Parser__Node)i0;
  OOC_Package__ProcessRepository_SkipWS((void*)(OOC_INT32)&node);
  i0 = (OOC_INT32)node;
  i1 = OOC_Package__AtElement((Config_Parser__Node)i0, ((OOC_CHAR16[]){105,110,115,116,97,108,108,101,100,0}), 10);
  if (!i1) goto l12;
l7_loop:
  i1 = (OOC_INT32)rep;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 29071))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 29071))+8);
  i0 = (OOC_INT32)OOC_Package__ProcessRepository_ParseInstalled((Config_Parser__Element)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 29120)))), &_td_Config_Parser__ElementDesc, 29120)));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 29085)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i1, (Object__Object)i0);
  i0 = (OOC_INT32)node;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 29150));
  node = (Config_Parser__Node)i0;
  OOC_Package__ProcessRepository_SkipWS((void*)(OOC_INT32)&node);
  i0 = (OOC_INT32)node;
  i1 = OOC_Package__AtElement((Config_Parser__Node)i0, ((OOC_CHAR16[]){105,110,115,116,97,108,108,101,100,0}), 10);
  if (i1) goto l7_loop;
l12:
  i1 = OOC_Package__AtElement((Config_Parser__Node)i0, ((OOC_CHAR16[]){111,112,116,105,111,110,115,0}), 8);
  if (!i1) goto l15;
  i1 = (OOC_INT32)rep;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 29279));
  i2 = (OOC_INT32)OOC_Config__options;
  i3 = (OOC_INT32)OOC_Package__stringType;
  i4 = (OOC_INT32)errList;
  i5 = (OOC_INT32)errorListener;
  OOC_Package__ParseKeyValue((Config_Parser__Element)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 29266)))), &_td_Config_Parser__ElementDesc, 29266)), (ADT_ArrayList__ArrayList)i1, (Config_Section_Options__Section)i2, (Object__String)i3, (XML_Locator__ErrorListener)i5, (OOC_Error__List)i4);
  i0 = (OOC_INT32)node;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 29380));
  node = (Config_Parser__Node)i0;
  OOC_Package__ProcessRepository_SkipWS((void*)(OOC_INT32)&node);
l15:
  i0 = (OOC_INT32)node;
  i1 = OOC_Package__AtElement((Config_Parser__Node)i0, ((OOC_CHAR16[]){112,114,97,103,109,97,115,0}), 8);
  if (!i1) goto l18;
  i1 = (OOC_INT32)rep;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 29509))+4);
  i2 = (OOC_INT32)OOC_Config__pragmas;
  i3 = (OOC_INT32)OOC_Package__stringType;
  i4 = (OOC_INT32)errList;
  i5 = (OOC_INT32)errorListener;
  OOC_Package__ParseKeyValue((Config_Parser__Element)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 29496)))), &_td_Config_Parser__ElementDesc, 29496)), (ADT_ArrayList__ArrayList)i1, (Config_Section_Options__Section)i2, (Object__String)i3, (XML_Locator__ErrorListener)i5, (OOC_Error__List)i4);
  i0 = (OOC_INT32)node;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 29610));
  node = (Config_Parser__Node)i0;
  OOC_Package__ProcessRepository_SkipWS((void*)(OOC_INT32)&node);
l18:
  i0 = (OOC_INT32)node;
  i1 = i0!=0;
  if (!i1) goto l21;
  OOC_Package__ProcessRepository_Err(4, (Config_Parser__Node)i0);
l21:
  i0 = (OOC_INT32)errList;
  i0 = *(OOC_INT32*)(_check_pointer(i0, 29741));
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
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30121))+8);
    i1 = *(OOC_INT32*)(_check_pointer(i1, 30129));
    i1 = i1==0;
    if (i1) goto l10;
    i1 = (OOC_INT32)*errList;
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30417))+8);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 30404)))), Msg__MsgListDesc_AppendList)),Msg__MsgListDesc_AppendList)((Msg__MsgList)i1, (Msg__MsgList)i0);
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
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30180))+12);
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 30185))+28);
    i1 = (
    _cmp16((const void*)(_check_pointer(i1, 30190)),(const void*)((OOC_CHAR16[]){114,101,112,111,115,105,116,111,114,121,0})))==0;
    
l15:
    if (i1) goto l17;
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30331))+12);
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30339))+16);
    i2 = (OOC_INT32)*errList;
    i0 = (OOC_INT32)OOC_Package__ProcessPackage((Config_Parser__Element)i1, (XML_Locator__ErrorListener)i0, (OOC_Error__List)i2);
    Exception__PopContext(1);
    return (OOC_Repository__PkgInfo)i0;
    goto l19;
l17:
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30251))+12);
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30259))+16);
    i2 = (OOC_INT32)*errList;
    i0 = (OOC_INT32)OOC_Package__ProcessRepository((Config_Parser__Element)i1, (XML_Locator__ErrorListener)i0, (OOC_Error__List)i2);
    Exception__PopContext(1);
    return (OOC_Repository__PkgInfo)i0;
l19:
    Exception__PopContext(1);
l20:;
  }
  _failed_function(29840); return 0;
  ;
}

OOC_Package__Package OOC_Package__GetPackage(Object__String pkgName, OOC_Repository__Repository *rep) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)OOC_Config__repositories;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30703))+4);
  *rep = (OOC_Repository__Repository)i0;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l19;
  i1 = (OOC_INT32)pkgName;
  
l3_loop:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30755))+8);
  i2 = i2!=(OOC_INT32)0;
  if (i2) goto l6;
  i2=0u;
  goto l8;
l6:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30790))+8);
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 30803)))), &_td_OOC_Package__PackageDesc);
  
l8:
  if (i2) goto l10;
  i2=0u;
  goto l12;
l10:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30829))+8);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 30842)))), &_td_OOC_Package__PackageDesc, 30842)), 30850))+8);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30829))+8);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 30842)))), &_td_OOC_Package__PackageDesc, 30842)), 30850))+8);
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 30855)))), Object__StringDesc_Equals)),Object__StringDesc_Equals)((Object__String)i3, (Object__Object)i1);
  
l12:
  if (!i2) goto l14;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30895))+8);
  return (OOC_Package__Package)(_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 30908)))), &_td_OOC_Package__PackageDesc, 30908));
l14:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 30945));
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
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 31316));
      i1 = OOC_Package__ParseMetaData_Parse((OOC_Repository__Repository)i1);
      if (!i1) goto l15;
      i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 31351)))), OOC_Repository__RepositoryDesc_GetResource)),OOC_Repository__RepositoryDesc_GetResource)((OOC_Repository__Repository)i0, "", 1, "pkginfo.xml", 12);
      uri = (URI__URI)i1;
      i2 = i1!=(OOC_INT32)0;
      if (!i2) goto l15;
      i1 = (OOC_INT32)URI_Scheme_File__URIDesc_GetPath((URI_Scheme_File__URI)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 31453)))), &_td_URI_Scheme_File__URIDesc, 31453)));
      i1 = (OOC_INT32)OOC_Package__ParseFile((Object__String)i1, 0u, (void*)(OOC_INT32)&errList);
      pkg = (OOC_Repository__PkgInfo)i1;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 31501)))), OOC_Repository__RepositoryDesc_SetPackageInfo)),OOC_Repository__RepositoryDesc_SetPackageInfo)((OOC_Repository__Repository)i0, (OOC_Repository__PkgInfo)i1);
      i0 = i1!=(OOC_INT32)0;
      if (!i0) goto l9;
      i0 = (OOC_INT32)options;
      i2 = (OOC_INT32)pragmas;
      OOC_Package__MergeConfig((OOC_Repository__PkgInfo)i1, (Config_Section_Options__Section)i0, (Config_Section_Options__Section)i2);
l9:
      i0 = (OOC_INT32)errList;
      i0 = *(OOC_INT32*)(_check_pointer(i0, 31645));
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
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31866))+4);
  i0 = OOC_Package__ParseMetaData_Parse((OOC_Repository__Repository)i0);
  i0 = (OOC_INT32)StdChannels__stdout;
  i1 = (OOC_INT32)errList;
  OOC_Error__ListDesc_Write((OOC_Error__List)i1, (Channel__Channel)i0);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32193)))), XML_Writer__WriterDesc_StartTagLatin1)),XML_Writer__WriterDesc_StartTagLatin1)((XML_Writer__Writer)i0, (void*)(OOC_INT32)tag, tag_0d, 0u);
  i1 = (OOC_INT32)list;
  i = 0;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 32244))+4);
  i3 = 0<i2;
  if (!i3) goto l20;
  i3=0;
l3_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 32271));
  i4 = _check_pointer(i4, 32277);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 32277))*4);
  i4 = _type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 32281)))), &_td_OOC_Package__KeyValueDesc, 32281);
  kv = (OOC_Package__KeyValue)i4;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32299)))), XML_Writer__WriterDesc_StartTag)),XML_Writer__WriterDesc_StartTag)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){100,101,102,105,110,101,0}), 7, 1u);
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 32355));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32333)))), XML_Writer__WriterDesc_AttrObject)),XML_Writer__WriterDesc_AttrObject)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){110,97,109,101,0}), 5, (Object__String)i5);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 32375))+4);
  v = (Config__Variable)i5;
  i6 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 32395)))), &_td_Config__StringVarDesc);
  if (i6) goto l14;
  i6 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 32453)))), &_td_Config__BooleanVarDesc);
  if (i6) goto l12;
  i6 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 32513)))), &_td_Config__IntegerVarDesc);
  if (i6) goto l10;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 32510)))), 32510);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32582)))), XML_Writer__WriterDesc_AttrStringLatin1)),XML_Writer__WriterDesc_AttrStringLatin1)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){116,121,112,101,0}), 5, (void*)(OOC_INT32)type, 32);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 32637))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32622)))), XML_Writer__WriterDesc_WriteObject)),XML_Writer__WriterDesc_WriteObject)((XML_Writer__Writer)i0, (Object__Object)i4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32653)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i0);
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l3_loop;
l20:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32689)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i0);
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
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33008)))), XML_Writer__WriterDesc_StartTag)),XML_Writer__WriterDesc_StartTag)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){118,101,114,115,105,111,110,0}), 8, 0u);
      i1 = (OOC_INT32)version;
      i2 = *(OOC_INT32*)(_check_pointer(i1, 33071));
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33044)))), XML_Writer__WriterDesc_AttrInt)),XML_Writer__WriterDesc_AttrInt)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){99,117,114,114,101,110,116,0}), 8, i2);
      i2 = *(OOC_INT32*)((_check_pointer(i1, 33099))+4);
      i2 = i2>0;
      if (!i2) goto l3;
      i2 = *(OOC_INT32*)((_check_pointer(i1, 33146))+4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33123)))), XML_Writer__WriterDesc_AttrInt)),XML_Writer__WriterDesc_AttrInt)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){97,103,101,0}), 4, i2);
l3:
      i1 = *(OOC_INT32*)((_check_pointer(i1, 33198))+8);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33170)))), XML_Writer__WriterDesc_AttrInt)),XML_Writer__WriterDesc_AttrInt)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){114,101,118,105,115,105,111,110,0}), 9, i1);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33217)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i0);
      return;
      ;
    }

    
    void OOC_Package__WritePackage_WriteLibrary(XML_Writer__Writer w, OOC_Package__Library library) {
      register OOC_INT32 i0,i1,i2;

      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33345)))), XML_Writer__WriterDesc_StartTag)),XML_Writer__WriterDesc_StartTag)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){108,105,98,114,97,114,121,0}), 8, 0u);
      i1 = (OOC_INT32)library;
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 33408));
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33381)))), XML_Writer__WriterDesc_AttrObject)),XML_Writer__WriterDesc_AttrObject)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){110,97,109,101,0}), 5, (Object__String)i2);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 33457))+4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33423)))), XML_Writer__WriterDesc_AttrObject)),XML_Writer__WriterDesc_AttrObject)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){109,97,105,110,45,109,111,100,117,108,101,0}), 12, (Object__String)i2);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 33500))+8);
      OOC_Package__WritePackage_WriteVersion((XML_Writer__Writer)i0, (OOC_Package__Version)i1);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33518)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i0);
      return;
      ;
    }

    
    void OOC_Package__WritePackage_WriteExecutable(XML_Writer__Writer w, OOC_Package__Executable executable) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33655)))), XML_Writer__WriterDesc_StartTag)),XML_Writer__WriterDesc_StartTag)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){101,120,101,99,117,116,97,98,108,101,0}), 11, 0u);
      i1 = (OOC_INT32)executable;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 33731));
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33694)))), XML_Writer__WriterDesc_AttrObject)),XML_Writer__WriterDesc_AttrObject)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){109,97,105,110,45,109,111,100,117,108,101,0}), 12, (Object__String)i1);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33752)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i0);
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
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33975)))), XML_Writer__WriterDesc_StartTag)),XML_Writer__WriterDesc_StartTag)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){102,105,108,101,0}), 5, 0u);
          i1 = (OOC_INT32)file;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34034))+4);
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34010)))), XML_Writer__WriterDesc_AttrObject)),XML_Writer__WriterDesc_AttrObject)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){110,97,109,101,0}), 5, (Object__String)i2);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34058))+8);
          i2 = i2!=(OOC_INT32)0;
          if (!i2) goto l3;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34120))+8);
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34091)))), XML_Writer__WriterDesc_AttrObject)),XML_Writer__WriterDesc_AttrObject)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){100,101,115,116,45,110,97,109,101,0}), 10, (Object__String)i1);
l3:
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34154)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i0);
          return;
          ;
        }


      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34220)))), XML_Writer__WriterDesc_StartTag)),XML_Writer__WriterDesc_StartTag)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){102,105,108,101,45,115,101,116,0}), 9, 0u);
      i1 = (OOC_INT32)fileSet;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34290))+4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34257)))), XML_Writer__WriterDesc_AttrObject)),XML_Writer__WriterDesc_AttrObject)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){115,111,117,114,99,101,45,100,105,114,0}), 11, (Object__String)i2);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34320))+8);
      i2 = i2!=(OOC_INT32)0;
      if (!i2) goto l3;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34381))+8);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34350)))), XML_Writer__WriterDesc_AttrObject)),XML_Writer__WriterDesc_AttrObject)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){100,101,115,116,45,100,105,114,0}), 9, (Object__String)i2);
l3:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34423))+12);
      ptr = (OOC_Package__FileData)i0;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l19;
l6_loop:
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34473)))), &_td_OOC_Package__FileSetDesc);
      if (i1) goto l13;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34531)))), &_td_OOC_Package__FileDesc);
      if (i1) goto l11;
      _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34526)))), 34526);
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
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 34601));
      ptr = (OOC_Package__FileData)i0;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l6_loop;
l19:
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34634)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i0);
      return;
      ;
    }


  i0 = (OOC_INT32)targetDir;
  i0 = (OOC_INT32)ADT_StringBuffer__New((Object__String)i0);
  b = (ADT_StringBuffer__StringBuffer)i0;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34735)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1)),ADT_StringBuffer__StringBufferDesc_AppendLatin1)((ADT_StringBuffer__StringBuffer)i0, "/pkginfo", 9);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34770)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c9));
  i1 = (OOC_INT32)pkg;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34800))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34789)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34813)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c10));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34847)))), ADT_StringBuffer__StringBufferDesc_ToString)),ADT_StringBuffer__StringBufferDesc_ToString)((ADT_StringBuffer__StringBuffer)i0);
  fileName = (Object__String)i0;
  i0 = (OOC_INT32)IO_FileChannel__Open((Object__String)i0, 22u);
  f = (IO__ByteChannel)i0;
  i2 = (OOC_INT32)XML_UnicodeCodec_Latin1__factory;
  i0 = (OOC_INT32)XML_Writer__New((IO__ByteChannel)i0, (XML_UnicodeCodec__Factory)i2, 1u, 2);
  w = (XML_Writer__Writer)i0;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 35077)))), XML_Writer__WriterDesc_StartTag)),XML_Writer__WriterDesc_StartTag)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){112,97,99,107,97,103,101,0}), 8, 0u);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 35134))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 35111)))), XML_Writer__WriterDesc_AttrObject)),XML_Writer__WriterDesc_AttrObject)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){110,97,109,101,0}), 5, (Object__String)i2);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 35165))+12);
  OOC_Package__WritePackage_WriteVersion((XML_Writer__Writer)i0, (OOC_Package__Version)i1);
  i0 = (OOC_INT32)pkg;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 35211));
  i2 = (OOC_INT32)w;
  OOC_Package__WriteKeyValue((XML_Writer__Writer)i2, "options", 8, (ADT_ArrayList__ArrayList)i1);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35257))+4);
  OOC_Package__WriteKeyValue((XML_Writer__Writer)i2, "pragmas", 8, (ADT_ArrayList__ArrayList)i1);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35289))+16);
  i = 0;
  i0 = *(OOC_INT32*)((_check_pointer(i0, 35297))+4);
  i1 = 0<i0;
  if (!i1) goto l8;
  i1=0;
l3_loop:
  i2 = (OOC_INT32)pkg;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 35333))+16);
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 35341));
  i2 = _check_pointer(i2, 35347);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i1, i3, OOC_UINT32, 35347))*4);
  i2 = (OOC_INT32)w;
  OOC_Package__WritePackage_WriteLibrary((XML_Writer__Writer)i2, (OOC_Package__Library)i1);
  i1 = i;
  i1 = i1+1;
  i = i1;
  i2 = i1<i0;
  if (i2) goto l3_loop;
l8:
  i0 = (OOC_INT32)pkg;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35383))+20);
  i0 = *(OOC_INT32*)((_check_pointer(i0, 35394))+4);
  i = 0;
  i1 = 0<i0;
  if (!i1) goto l16;
  i1=0;
l11_loop:
  i2 = (OOC_INT32)pkg;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 35433))+20);
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 35444));
  i2 = _check_pointer(i2, 35450);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i1, i3, OOC_UINT32, 35450))*4);
  i2 = (OOC_INT32)w;
  OOC_Package__WritePackage_WriteExecutable((XML_Writer__Writer)i2, (OOC_Package__Executable)i1);
  i1 = i;
  i1 = i1+1;
  i = i1;
  i2 = i1<i0;
  if (i2) goto l11_loop;
l16:
  i0 = (OOC_INT32)pkg;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35488))+24);
  i1 = (OOC_INT32)w;
  OOC_Package__WritePackage_WriteFileSet((XML_Writer__Writer)i1, (OOC_Package__FileSet)i0);
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 35504)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 35535)))), XML_Writer__WriterDesc_EndOfText)),XML_Writer__WriterDesc_EndOfText)((XML_Writer__Writer)i0);
  i0 = (OOC_INT32)f;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 35559)))), IO__ChannelDesc_Close)),IO__ChannelDesc_Close)((IO__Channel)i0);
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
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 35952)))), XML_Writer__WriterDesc_StartTag)),XML_Writer__WriterDesc_StartTag)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){105,110,115,116,97,108,108,101,100,0}), 10, 0u);
      i1 = (OOC_INT32)pkgName;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 35990)))), XML_Writer__WriterDesc_AttrObject)),XML_Writer__WriterDesc_AttrObject)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){112,97,99,107,97,103,101,0}), 8, (Object__String)i1);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36030)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i0);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36384)))), XML_Writer__WriterDesc_StartTag)),XML_Writer__WriterDesc_StartTag)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){114,101,112,111,115,105,116,111,114,121,0}), 11, 0u);
  i0 = (OOC_INT32)rep;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36437))+8);
  i = 0;
  i0 = *(OOC_INT32*)((_check_pointer(i0, 36451))+4);
  i1 = 0<i0;
  if (!i1) goto l8;
  i1=0;
l3_loop:
  i2 = (OOC_INT32)rep;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 36492))+8);
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 36506));
  i2 = _check_pointer(i2, 36512);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i1, i3, OOC_UINT32, 36512))*4);
  i2 = (OOC_INT32)w;
  OOC_Package__WriteRepository_WriteInstalledPkg((XML_Writer__Writer)i2, (Object__String)i1);
  i1 = i;
  i1 = i1+1;
  i = i1;
  i2 = i1<i0;
  if (i2) goto l3_loop;
l8:
  i0 = (OOC_INT32)rep;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 36562));
  i2 = (OOC_INT32)w;
  OOC_Package__WriteKeyValue((XML_Writer__Writer)i2, "options", 8, (ADT_ArrayList__ArrayList)i1);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36608))+4);
  OOC_Package__WriteKeyValue((XML_Writer__Writer)i2, "pragmas", 8, (ADT_ArrayList__ArrayList)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 36624)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 36658)))), XML_Writer__WriterDesc_EndOfText)),XML_Writer__WriterDesc_EndOfText)((XML_Writer__Writer)i2);
  i0 = (OOC_INT32)f;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36677)))), IO__ChannelDesc_Close)),IO__ChannelDesc_Close)((IO__Channel)i0);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36991)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c14));
  i1 = (OOC_INT32)targetDir;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37011)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37037)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c15));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37067)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c16));
  i1 = (OOC_INT32)pkg;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 37098))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37087)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37112)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c17));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37142)))), ADT_StringBuffer__StringBufferDesc_ToString)),ADT_StringBuffer__StringBufferDesc_ToString)((ADT_StringBuffer__StringBuffer)i0);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37456)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37482)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c18));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37512)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c19));
  i1 = (OOC_INT32)pkgName;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37532)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37556)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c20));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37587)))), ADT_StringBuffer__StringBufferDesc_ToString)),ADT_StringBuffer__StringBufferDesc_ToString)((ADT_StringBuffer__StringBuffer)i0);
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
  return (OOC_Package__Package)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37730)))), &_td_OOC_Package__PackageDesc, 37730));
l4:
  _failed_function(37190); return 0;
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
  return (OOC_Package__Repository)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 38165)))), &_td_OOC_Package__RepositoryDesc, 38165));
l4:
  _failed_function(37805); return 0;
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
  i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 38740)), 0);
  i1 = 0<i0;
  if (!i1) goto l15;
  i1 = (OOC_INT32)_c24;
  i2=0;
l3_loop:
  i3 = (OOC_INT32)files;
  i3 = _check_pointer(i3, 38772);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 38772))*4);
  i2 = OOC_Package__UpdateRepository_IsPkgInfo((Object__String)i2);
  if (!i2) goto l10;
  i2 = (OOC_INT32)files;
  i2 = _check_pointer(i2, 38819);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i4 = i;
  i5 = (OOC_INT32)dirName;
  i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i4, i3, OOC_UINT32, 38819))*4);
  i2 = (OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)i5,(void*)i1)),(void*)i2);
  fileName = (Object__String)i2;
  i3 = (OOC_INT32)OOC_Error__NewList((Object__String)i2);
  errList = (OOC_Error__List)i3;
  i2 = (OOC_INT32)OOC_Package__ParseFile((Object__String)i2, 1u, (void*)(OOC_INT32)&errList);
  pkg = (OOC_Repository__PkgInfo)i2;
  i3 = (OOC_INT32)errList;
  i4 = *(OOC_INT32*)(_check_pointer(i3, 38947));
  i4 = i4!=0;
  if (i4) goto l8;
  i3 = (OOC_INT32)repository;
  OOC_Package__RepositoryDesc_MergePackage((OOC_Package__Repository)i3, (OOC_Package__Package)(_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 39087)))), &_td_OOC_Package__PackageDesc, 39087)));
  goto l10;
l8:
  i2 = (OOC_INT32)StdChannels__stdout;
  OOC_Error__ListDesc_Write((OOC_Error__List)i3, (Channel__Channel)i2);
  return 0u;
l10:
  i2 = i;
  i2 = i2+1;
  i = i2;
  i3 = i2<i0;
  if (i3) goto l3_loop;
l15:
  i0 = (OOC_INT32)repository;
  i1 = (OOC_INT32)targetDir;
  OOC_Package__WriteRepository((OOC_Package__Repository)i0, (Object__String)i1);
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
