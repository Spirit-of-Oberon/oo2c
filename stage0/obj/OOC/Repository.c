#include <OOC/Repository.d>
#include <__oo2c.h>
#include <setjmp.h>

void OOC_Repository__Init(OOC_Repository__Repository rep, OOC_Repository__Repository baseRep, URI__HierarchicalURI baseURI) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)rep;
  i1 = (OOC_INT32)baseRep;
  *(OOC_INT32*)(_check_pointer(i0, 11179)) = i1;
  i1 = (OOC_INT32)baseURI;
  *(OOC_INT32*)((_check_pointer(i0, 11208))+4) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 11237))+8) = 0;
  return;
  ;
}

void OOC_Repository__InitModule(OOC_Repository__Module m, OOC_Repository__Repository origin, const Msg__String name__ref, OOC_LEN name_0d, URI__HierarchicalURI srcFileOverride) {
  register OOC_INT32 i0,i1;
  OOC_ALLOCATE_VPAR(name,OOC_CHAR8 ,name_0d)

  OOC_INITIALIZE_VPAR(name__ref,name,OOC_CHAR8 ,name_0d)
  i0 = (OOC_INT32)m;
  i1 = (OOC_INT32)origin;
  *(OOC_INT32*)(_check_pointer(i0, 11419)) = i1;
  i1 = (OOC_INT32)Msg__GetStringPtr((void*)(OOC_INT32)name, name_0d);
  *(OOC_INT32*)((_check_pointer(i0, 11444))+4) = i1;
  i1 = (OOC_INT32)srcFileOverride;
  *(OOC_INT32*)((_check_pointer(i0, 11484))+8) = i1;
  *(OOC_INT8*)((_check_pointer(i0, 11532))+16) = 1;
  *(OOC_INT32*)((_check_pointer(i0, 11569))+12) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 11591))+20) = 0;
  *(OOC_UINT32*)((_check_pointer(i0, 11619))+24) = 0u;
  *(OOC_UINT8*)((_check_pointer(i0, 11652))+28) = 0u;
  *(OOC_INT32*)((_check_pointer(i0, 11685))+32) = 0;
  return;
  ;
}

void OOC_Repository__InitPkgInfo(OOC_Repository__PkgInfo pkgInfo) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)pkgInfo;
  i1 = (OOC_INT32)ADT_ArrayList__New(4);
  *(OOC_INT32*)(_check_pointer(i0, 11786)) = i1;
  i1 = (OOC_INT32)ADT_ArrayList__New(4);
  *(OOC_INT32*)((_check_pointer(i0, 11827))+4) = i1;
  return;
  ;
}

void OOC_Repository__RepositoryDesc_SetPackageInfo(OOC_Repository__Repository rep, OOC_Repository__PkgInfo packageInfo) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)rep;
  i1 = (OOC_INT32)packageInfo;
  *(OOC_INT32*)((_check_pointer(i0, 11960))+8) = i1;
  return;
  ;
}

OOC_Repository__Module OOC_Repository__RepositoryDesc_GetModule(OOC_Repository__Repository rep, const OOC_CHAR8 moduleName__ref[], OOC_LEN moduleName_0d, URI__HierarchicalURI srcFileOverride) {
  OOC_ALLOCATE_VPAR(moduleName,OOC_CHAR8 ,moduleName_0d)

  OOC_INITIALIZE_VPAR(moduleName__ref,moduleName,OOC_CHAR8 ,moduleName_0d)
  _failed_function(12051); return 0;
  ;
}

URI__URI OOC_Repository__RepositoryDesc_GetResource(OOC_Repository__Repository rep, const OOC_CHAR8 package__ref[], OOC_LEN package_0d, const OOC_CHAR8 path__ref[], OOC_LEN path_0d) {
  OOC_ALLOCATE_VPAR(package,OOC_CHAR8 ,package_0d)
  OOC_ALLOCATE_VPAR(path,OOC_CHAR8 ,path_0d)

  OOC_INITIALIZE_VPAR(package__ref,package,OOC_CHAR8 ,package_0d)
  OOC_INITIALIZE_VPAR(path__ref,path,OOC_CHAR8 ,path_0d)
  _failed_function(12931); return 0;
  ;
}

void OOC_Repository__RepositoryDesc_DumpContent(OOC_Repository__Repository rep, TextRider__Writer w) {

  return;
  ;
}

void OOC_Repository__ModuleDesc_SetInterfaceData(OOC_Repository__Module m, OOC_SymbolTable__Module ifData, OOC_INT8 ifQuality, OOC_CHAR8 allImports) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
  OOC_SymbolTable__Module oldIfData;
  OOC_INT32 count;
  OOC_SymbolTable__Item item;
  OOC_INT32 i;
  OOC_SymbolTable__ModuleRef mr;
  OOC_SymbolTable__Name name;

  i0 = (OOC_INT32)m;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13847))+12);
  oldIfData = (OOC_SymbolTable__Module)i1;
  i2 = (OOC_INT32)ifData;
  *(OOC_INT32*)((_check_pointer(i0, 13861))+12) = i2;
  i3 = ifQuality;
  *(OOC_INT8*)((_check_pointer(i0, 13885))+16) = i3;
  i3 = i2==(OOC_INT32)0;
  if (i3) goto l55;
  i1 = i1!=i2;
  if (!i1) goto l56;
  count = 0;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14041))+8);
  item = (OOC_SymbolTable__Item)i1;
  i3 = i1!=(OOC_INT32)0;
  if (i3) goto l7;
  i1=0;
  goto l17;
l7:
  i3=0;
l8_loop:
  i4 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14100)))), &_td_OOC_SymbolTable__ImportDesc);
  if (!i4) goto l12;
  i3 = i3+1;
  count = i3;
  
l12:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 14184));
  item = (OOC_SymbolTable__Item)i1;
  i4 = i1!=(OOC_INT32)0;
  if (i4) goto l8_loop;
l16:
  i1=i3;
l17:
  i3 = allImports;
  if (i3) goto l20;
  i4=0u;
  goto l22;
l20:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14237))+72);
  i4 = i4!=(OOC_INT32)0;
  
l22:
  if (!i4) goto l25;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14293))+72);
  i4 = OOC_ARRAY_LENGTH((_check_pointer(i4, 14307)), 0);
  i1 = i1+i4;
  count = i1;
  
l25:
  *(OOC_INT32*)((_check_pointer(i0, 14341))+20) = ((OOC_INT32)RT0__NewObject(_td_OOC_Repository__3256.baseTypes[0], i1));
  count = 0;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14402))+8);
  item = (OOC_SymbolTable__Item)i1;
  i4 = i1!=(OOC_INT32)0;
  if (i4) goto l28;
  i1=0;
  goto l39;
l28:
  i4=0;
l29_loop:
  i5 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14461)))), &_td_OOC_SymbolTable__ImportDesc);
  if (!i5) goto l33;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14488))+20);
  i5 = _check_pointer(i5, 14501);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14521))+48);
  *(OOC_INT32*)(i5+((_check_index(i4, i6, OOC_UINT32, 14501))*16)) = i7;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14545))+20);
  i5 = _check_pointer(i5, 14558);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  *(OOC_INT32*)((i5+((_check_index(i4, i6, OOC_UINT32, 14558))*16))+4) = (OOC_INT32)0;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14592))+20);
  i5 = _check_pointer(i5, 14605);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14630))+48);
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i7, 14641))+12);
  *(OOC_UINT8*)((i5+((_check_index(i4, i6, OOC_UINT32, 14605))*16))+8) = ((
  _cmp8((const void*)(_check_pointer(i7, 14645)),(const void*)"SYSTEM"))==0);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14671))+20);
  i5 = _check_pointer(i5, 14684);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i7 = *(OOC_INT32*)((_check_pointer(i1, 14711))+56);
  *(OOC_INT32*)((i5+((_check_index(i4, i6, OOC_UINT32, 14684))*16))+12) = i7;
  i4 = i4+1;
  count = i4;
  
l33:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 14793));
  item = (OOC_SymbolTable__Item)i1;
  i5 = i1!=(OOC_INT32)0;
  if (i5) goto l29_loop;
l37:
  i1=i4;
l39:
  if (i3) goto l41;
  i3=0u;
  goto l43;
l41:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14847))+72);
  i3 = i3!=(OOC_INT32)0;
  
l43:
  if (!i3) goto l56;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14906))+72);
  i = 0;
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 14920)), 0);
  i4 = 0<i3;
  if (!i4) goto l56;
  i4=i1;i1=0;
l47_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14950))+72);
  i5 = _check_pointer(i5, 14964);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i1, i6, OOC_UINT32, 14964))*4);
  mr = (OOC_SymbolTable__ModuleRef)i5;
  i6 = (OOC_INT32)RT0__NewObject(_td_OOC_SymbolTable__Name.baseTypes[0]);
  name = (OOC_SymbolTable__Name)i6;
  i7 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 15021));
  OOC_SymbolTable__InitName((OOC_SymbolTable__Name)i6, (OOC_Scanner_InputBuffer__CharArray)i7, 0, 0, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15049))+20);
  i7 = _check_pointer(i7, 15062);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  *(OOC_INT32*)(i7+((_check_index(i4, i8, OOC_UINT32, 15062))*16)) = i6;
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15095))+20);
  i6 = _check_pointer(i6, 15108);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  *(OOC_INT32*)((i6+((_check_index(i4, i7, OOC_UINT32, 15108))*16))+4) = (OOC_INT32)0;
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15142))+20);
  i6 = _check_pointer(i6, 15155);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  *(OOC_UINT8*)((i6+((_check_index(i4, i7, OOC_UINT32, 15155))*16))+8) = 0u;
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15193))+20);
  i6 = _check_pointer(i6, 15206);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i5 = *(OOC_INT32*)((_check_pointer(i5, 15231))+4);
  *(OOC_INT32*)((i6+((_check_index(i4, i7, OOC_UINT32, 15206))*16))+12) = i5;
  i4 = i4+1;
  count = i4;
  i1 = i1+1;
  i = i1;
  i5 = i1<i3;
  if (i5) goto l47_loop;
  goto l56;
l55:
  *(OOC_INT32*)((_check_pointer(i0, 13945))+20) = (OOC_INT32)0;
l56:
  return;
  ;
}

void OOC_Repository__ModuleDesc_SetFingerprint(OOC_Repository__Module m, OOC_INT32 fp) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)m;
  *(OOC_UINT8*)((_check_pointer(i0, 15391))+28) = 1u;
  i1 = fp;
  *(OOC_INT32*)((_check_pointer(i0, 15422))+32) = i1;
  return;
  ;
}

OOC_Repository__Module OOC_Repository__ModuleDesc_GetImportedModule(OOC_Repository__Module m, const OOC_CHAR8 name__ref[], OOC_LEN name_0d) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_ALLOCATE_VPAR(name,OOC_CHAR8 ,name_0d)
  OOC_INT32 i;

  OOC_INITIALIZE_VPAR(name__ref,name,OOC_CHAR8 ,name_0d)
  i = 0;
  i0 = (OOC_INT32)m;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15598))+20);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 15611)), 0);
  i1 = 0!=i1;
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15629))+20);
  i1 = _check_pointer(i1, 15642);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i1+((_check_index(0, i2, OOC_UINT32, 15642))*16));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 15650))+12);
  i1 = (
  _cmp8((const void*)(_check_pointer(i1, 15654)),(const void*)(OOC_INT32)name))!=0;
  
l5:
  if (i1) goto l7;
  i1=0;
  goto l17;
l7:
  i1=0;
l8_loop:
  i1 = i1+1;
  i = i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15598))+20);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 15611)), 0);
  i2 = i1!=i2;
  if (i2) goto l11;
  i2=0u;
  goto l13;
l11:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15629))+20);
  i2 = _check_pointer(i2, 15642);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)(i2+((_check_index(i1, i3, OOC_UINT32, 15642))*16));
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 15650))+12);
  i2 = (
  _cmp8((const void*)(_check_pointer(i2, 15654)),(const void*)(OOC_INT32)name))!=0;
  
l13:
  if (i2) goto l8_loop;
l17:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15707))+20);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 15720)), 0);
  i2 = i1==i2;
  if (i2) goto l20;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15770))+20);
  i0 = _check_pointer(i0, 15783);
  i2 = OOC_ARRAY_LENGTH(i0, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)((i0+((_check_index(i1, i2, OOC_UINT32, 15783))*16))+4);
  return (OOC_Repository__Module)i0;
  goto l21;
l20:
  return (OOC_Repository__Module)0;
l21:
  _failed_function(15487); return 0;
  ;
}

Object__String8 OOC_Repository__RepositoryDesc_GetLocalPath(OOC_Repository__Repository rep, OOC_Repository__Module m, OOC_INT8 fileId) {

  _failed_function(15869); return 0;
  ;
}

OOC_Scanner_InputBuffer__Buffer OOC_Repository__ModuleDesc_GetInputBuffer(OOC_Repository__Module m) {

  _failed_function(16076); return 0;
  ;
}

URI__HierarchicalURI OOC_Repository__ModuleDesc_GetURI(OOC_Repository__Module m, OOC_INT8 fileId, OOC_CHAR8 allowRelative) {
  register OOC_INT32 i0,i1;

  i0 = fileId;
  i0 = i0==11;
  if (i0) goto l3;
  i0=0u;
  goto l5;
l3:
  i0 = (OOC_INT32)m;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16743))+12);
  i0 = i0!=(OOC_INT32)0;
  
l5:
  if (i0) goto l7;
  i0=0u;
  goto l9;
l7:
  i0 = (OOC_INT32)m;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16770))+12);
  i0 = *(OOC_INT8*)((_check_pointer(i0, 16778))+52);
  i0 = i0!=0;
  
l9:
  if (i0) goto l11;
  return (URI__HierarchicalURI)(OOC_INT32)0;
  goto l12;
l11:
  i0 = (OOC_INT32)m;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 16853));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 16861))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16823))+12);
  i0 = (OOC_INT32)OOC_SymbolTable__ModuleDesc_GetExternalSource((OOC_SymbolTable__Module)i0, (URI__HierarchicalURI)i1);
  return (URI__HierarchicalURI)i0;
l12:
  _failed_function(16250); return 0;
  ;
}

OOC_CHAR8 OOC_Repository__ModuleDesc_MatchesURI(OOC_Repository__Module m, OOC_INT8 fileId, URI__URI uri) {
  register OOC_INT32 i0,i1;
  URI__HierarchicalURI muri;
  Object__String a;
  Object__String b;

  i0 = (OOC_INT32)m;
  i1 = fileId;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17169)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i0, i1, 0u);
  muri = (URI__HierarchicalURI)i0;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17208)))), URI__URIDesc_ToString)),URI__URIDesc_ToString)((URI__URI)i0);
  a = (Object__String)i0;
  i1 = (OOC_INT32)uri;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17233)))), URI__URIDesc_ToString)),URI__URIDesc_ToString)((URI__URI)i1);
  b = (Object__String)i1;
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17258)))), Object__StringDesc_Equals)),Object__StringDesc_Equals)((Object__String)i0, (Object__Object)i1);
  return i0;
  ;
}

void OOC_Repository__ModuleDesc_GetTimeStamp(OOC_Repository__Module m, OOC_INT8 fileId, struct Time__TimeStamp *ts, RT0__Struct ts__tag) {

  return;
  ;
}

OOC_CHAR8 OOC_Repository__ModuleDesc_FileExists(OOC_Repository__Module m, OOC_INT8 fileId) {

  _failed_function(17572); return 0;
  ;
}

void OOC_Repository__ModuleDesc_CreateOutputDir(OOC_Repository__Module m, OOC_INT8 fileId) {

  return;
  ;
}

IO__ByteChannel OOC_Repository__ModuleDesc_GetOutputChannel(OOC_Repository__Module m, OOC_INT8 fileId, OOC_CHAR8 makeTmp) {

  _failed_function(17771); return 0;
  ;
}

Object__String8 OOC_Repository__RepositoryDesc_GetDefaultSubdir(OOC_Repository__Repository rep, OOC_INT8 id) {
  register OOC_INT32 i0;

  i0 = id;
  switch (i0) {
  case 0:
    return (Object__String8)((OOC_INT32)_c0);
    goto l12;
  case 1:
  case 20:
    return (Object__String8)((OOC_INT32)_c1);
    goto l12;
  case 2:
  case 3:
  case 4:
  case 6:
    return (Object__String8)((OOC_INT32)_c2);
    goto l12;
  case 5:
    return (Object__String8)((OOC_INT32)_c3);
    goto l12;
  case 7:
  case 11:
  case 12:
  case 13:
  case 14:
  case 10:
  case 15:
  case 16:
  case 17:
    return (Object__String8)((OOC_INT32)_c4);
    goto l12;
  case 8:
    return (Object__String8)((OOC_INT32)_c5);
    goto l12;
  case 18:
    return (Object__String8)((OOC_INT32)_c6);
    goto l12;
  case 19:
    return (Object__String8)((OOC_INT32)_c7);
    goto l12;
  case 21:
    return (Object__String8)((OOC_INT32)_c8);
    goto l12;
  default:
    _failed_case(i0, 18022);
    goto l12;
  }
l12:
  _failed_function(17962); return 0;
  ;
}

Object__String8 OOC_Repository__RepositoryDesc_GetDefaultSuffix(OOC_Repository__Repository rep, OOC_INT8 id) {
  register OOC_INT32 i0;

  i0 = id;
  switch (i0) {
  case 0:
    return (Object__String8)((OOC_INT32)_c9);
    goto l23;
  case 1:
    return (Object__String8)((OOC_INT32)_c10);
    goto l23;
  case 20:
    return (Object__String8)((OOC_INT32)_c11);
    goto l23;
  case 2:
    return (Object__String8)((OOC_INT32)_c12);
    goto l23;
  case 3:
    return (Object__String8)((OOC_INT32)_c13);
    goto l23;
  case 4:
    return (Object__String8)((OOC_INT32)_c14);
    goto l23;
  case 5:
    return (Object__String8)((OOC_INT32)_c15);
    goto l23;
  case 6:
    return (Object__String8)((OOC_INT32)_c16);
    goto l23;
  case 7:
  case 10:
    return (Object__String8)((OOC_INT32)_c17);
    goto l23;
  case 8:
    return (Object__String8)((OOC_INT32)_c18);
    goto l23;
  case 11:
    return (Object__String8)((OOC_INT32)_c19);
    goto l23;
  case 12:
    return (Object__String8)((OOC_INT32)_c20);
    goto l23;
  case 13:
    return (Object__String8)((OOC_INT32)_c21);
    goto l23;
  case 14:
    return (Object__String8)((OOC_INT32)_c22);
    goto l23;
  case 15:
    return (Object__String8)((OOC_INT32)_c23);
    goto l23;
  case 16:
    return (Object__String8)((OOC_INT32)_c24);
    goto l23;
  case 17:
    return (Object__String8)((OOC_INT32)_c25);
    goto l23;
  case 18:
    return (Object__String8)((OOC_INT32)_c26);
    goto l23;
  case 19:
    return (Object__String8)((OOC_INT32)_c27);
    goto l23;
  case 21:
    _assert(0u, 127, 19664);
    goto l23;
  default:
    _failed_case(i0, 18770);
    goto l23;
  }
l23:
  _failed_function(18710); return 0;
  ;
}

OOC_CHAR8 OOC_Repository__ValidModuleName(const OOC_CHAR8 moduleName__ref[], OOC_LEN moduleName_0d) {
  register OOC_INT32 i0,i1;
  OOC_ALLOCATE_VPAR(moduleName,OOC_CHAR8 ,moduleName_0d)

  OOC_INITIALIZE_VPAR(moduleName__ref,moduleName,OOC_CHAR8 ,moduleName_0d)
  i0 = *(OOC_UINT8*)((OOC_INT32)moduleName+(_check_index(0, moduleName_0d, OOC_UINT32, 19907)));
  i0 = i0!=0u;
  if (i0) goto l3;
  i0=0;
  goto l52;
l3:
  i0=0;
l4_loop:
  i1 = *(OOC_UINT8*)((OOC_INT32)moduleName+(_check_index(i0, moduleName_0d, OOC_UINT32, 19953)));
  i1 = (OOC_UINT8)65u<=(OOC_UINT8)(_cap(i1));
  if (i1) goto l7;
  i1=0u;
  goto l9;
l7:
  i1 = *(OOC_UINT8*)((OOC_INT32)moduleName+(_check_index(i0, moduleName_0d, OOC_UINT32, 19977)));
  i1 = (OOC_UINT8)(_cap(i1))<=(OOC_UINT8)90u;
  
l9:
  if (i1) goto l11;
  i1 = *(OOC_UINT8*)((OOC_INT32)moduleName+(_check_index(i0, moduleName_0d, OOC_UINT32, 20014)));
  i1 = i1==95u;
  
  goto l13;
l11:
  i1=1u;
l13:
  if (i1) goto l16_loop;
  return 0u;
  
  goto l47;
l16_loop:
  i0 = i0+1;
  i1 = *(OOC_UINT8*)((OOC_INT32)moduleName+(_check_index(i0, moduleName_0d, OOC_UINT32, 20103)));
  i1 = (OOC_UINT8)65u<=(OOC_UINT8)(_cap(i1));
  if (i1) goto l19;
  i1=0u;
  goto l21;
l19:
  i1 = *(OOC_UINT8*)((OOC_INT32)moduleName+(_check_index(i0, moduleName_0d, OOC_UINT32, 20127)));
  i1 = (OOC_UINT8)(_cap(i1))<=(OOC_UINT8)90u;
  
l21:
  if (i1) goto l27;
  i1 = *(OOC_UINT8*)((OOC_INT32)moduleName+(_check_index(i0, moduleName_0d, OOC_UINT32, 20177)));
  i1 = (OOC_UINT8)48u<=(OOC_UINT8)i1;
  if (i1) goto l25;
  i1=0u;
  goto l29;
l25:
  i1 = *(OOC_UINT8*)((OOC_INT32)moduleName+(_check_index(i0, moduleName_0d, OOC_UINT32, 20195)));
  i1 = (OOC_UINT8)i1<=(OOC_UINT8)57u;
  
  goto l29;
l27:
  i1=1u;
l29:
  if (i1) goto l31;
  i1 = *(OOC_UINT8*)((OOC_INT32)moduleName+(_check_index(i0, moduleName_0d, OOC_UINT32, 20237)));
  i1 = i1==95u;
  
  goto l32;
l31:
  i1=1u;
l32:
  i1 = !i1;
  if (!i1) goto l16_loop;
l36:
  i1 = *(OOC_UINT8*)((OOC_INT32)moduleName+(_check_index(i0, moduleName_0d, OOC_UINT32, 20272)));
  i1 = i1==58u;
  if (i1) goto l42;
  i1 = *(OOC_UINT8*)((OOC_INT32)moduleName+(_check_index(i0, moduleName_0d, OOC_UINT32, 20437)));
  i1 = i1!=0u;
  if (!i1) goto l47;
  return 0u;
  goto l47;
l42:
  i0 = i0+1;
  i1 = *(OOC_UINT8*)((OOC_INT32)moduleName+(_check_index(i0, moduleName_0d, OOC_UINT32, 20331)));
  i1 = i1==0u;
  if (!i1) goto l47;
  return 0u;
l47:
  i1 = *(OOC_UINT8*)((OOC_INT32)moduleName+(_check_index(i0, moduleName_0d, OOC_UINT32, 19907)));
  i1 = i1!=0u;
  if (i1) goto l4_loop;
l52:
  return (i0>0);
  ;
}

OOC_Repository__Module OOC_Repository__RepositoryDesc_GetModuleByURI(OOC_Repository__Repository rep, URI__HierarchicalURI uri, OOC_CHAR8 force) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_Repository__Module m;
  Object__String s;
  Object__String ext;
  Object__CharsLatin1 chars;
  URI__URI relURI;
  Object__String8 subdir;
  OOC_INT32 i;
  Object__String8 s8;
  OOC_Repository__URIBuffer str;

  m = (OOC_Repository__Module)(OOC_INT32)0;
  i0 = force;
  if (i0) goto l43;
  i0 = (OOC_INT32)uri;
  i1 = (OOC_INT32)rep;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 21285))+4);
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21266)))), URI__HierarchicalURIDesc_MakeRelative)),URI__HierarchicalURIDesc_MakeRelative)((URI__HierarchicalURI)i0, (URI__HierarchicalURI)i2);
  relURI = (URI__URI)i2;
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 21313));
  i3 = i3==(OOC_INT32)0;
  if (i3) goto l5;
  i0=(OOC_INT32)0;
  goto l48;
l5:
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 21389)))), URI__URIDesc_ToString)),URI__URIDesc_ToString)((URI__URI)i2);
  s = (Object__String)i2;
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 21423)))), OOC_Repository__RepositoryDesc_GetDefaultSubdir)),OOC_Repository__RepositoryDesc_GetDefaultSubdir)((OOC_Repository__Repository)i1, 0);
  subdir = (Object__String8)i2;
  i3 = *(OOC_INT32*)(_check_pointer(i2, 21687));
  _assert((i3!=0), 127, 21673);
  i3 = *(OOC_INT32*)(_check_pointer(i2, 21720));
  i = i3;
  i4 = (OOC_INT32)s;
  i2 = Object__StringDesc_StartsWith((Object__String)i4, (Object__String)i2);
  if (i2) goto l8;
  i2=0u;
  goto l10;
l8:
  i2 = (OOC_INT32)s;
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 21765)))), Object__StringDesc_CharAt)),Object__StringDesc_CharAt)((Object__String)i2, i3);
  i2 = i2==47u;
  
l10:
  if (i2) goto l12;
  i0=(OOC_INT32)0;
  goto l48;
l12:
  i2 = (OOC_INT32)s;
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 21957)))), Object__StringDesc_ToString8)),Object__StringDesc_ToString8)((Object__String)i2, 63u);
  s8 = (Object__String8)i2;
  i2 = (OOC_INT32)Object__String8Desc_CharsLatin1((Object__String8)i2);
  chars = (Object__CharsLatin1)i2;
  _copy_8((const void*)(_check_pointer(i2, 22031)),(void*)(OOC_INT32)str,1024);
  Strings__Delete((void*)(OOC_INT32)str, 1024, 0, (i3+1));
  i = 0;
  i2 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, 1024, OOC_UINT32, 22136)));
  i2 = i2!=0u;
  if (i2) goto l15;
  i2=0u;
  goto l17;
l15:
  i2 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, 1024, OOC_UINT32, 22152)));
  i2 = i2!=46u;
  
l17:
  if (i2) goto l19;
  i2=0;
  goto l32;
l19:
  i2=0;
l20_loop:
  i3 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i2, 1024, OOC_UINT32, 22185)));
  i3 = i3==47u;
  if (!i3) goto l23;
  *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i2, 1024, OOC_UINT32, 22218))) = 58u;
l23:
  i2 = i2+1;
  i = i2;
  i3 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i2, 1024, OOC_UINT32, 22136)));
  i3 = i3!=0u;
  if (i3) goto l26;
  i3=0u;
  goto l28;
l26:
  i3 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i2, 1024, OOC_UINT32, 22152)));
  i3 = i3!=46u;
  
l28:
  if (i3) goto l20_loop;
l32:
  *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i2, 1024, OOC_UINT32, 22294))) = 0u;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 22324)))), OOC_Repository__RepositoryDesc_GetModule)),OOC_Repository__RepositoryDesc_GetModule)((OOC_Repository__Repository)i1, (void*)(OOC_INT32)str, 1024, (URI__HierarchicalURI)(OOC_INT32)0);
  m = (OOC_Repository__Module)i1;
  i2 = i1!=(OOC_INT32)0;
  if (i2) goto l35;
  i0=0u;
  goto l37;
l35:
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 22375)))), OOC_Repository__ModuleDesc_MatchesURI)),OOC_Repository__ModuleDesc_MatchesURI)((OOC_Repository__Module)i1, 0, (URI__URI)i0);
  i0 = !i0;
  
l37:
  if (i0) goto l39;
  i0=i1;
  goto l48;
l39:
  i0=(OOC_INT32)0;
  goto l48;
l43:
  i0 = (OOC_INT32)uri;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21052)))), URI__URIDesc_ToString)),URI__URIDesc_ToString)((URI__URI)i0);
  i1 = (OOC_INT32)OS_Path__BaseName((Object__String)i1);
  s = (Object__String)i1;
  OS_Path__SplitExt((Object__String)i1, (void*)(OOC_INT32)&s, (void*)(OOC_INT32)&ext);
  i1 = (OOC_INT32)s;
  i1 = (OOC_INT32)Object__String8Desc_CharsLatin1((Object__String8)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 21122)))), &_td_Object__String8Desc, 21122)));
  chars = (Object__CharsLatin1)i1;
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i1, 21177)), 0);
  i2 = OOC_Repository__ValidModuleName((void*)(_check_pointer(i1, 21177)), i2);
  if (i2) goto l46;
  i0=(OOC_INT32)0;
  goto l48;
l46:
  i2 = (OOC_INT32)rep;
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i1, 21219)), 0);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 21201)))), OOC_Repository__RepositoryDesc_GetModule)),OOC_Repository__RepositoryDesc_GetModule)((OOC_Repository__Repository)i2, (void*)(_check_pointer(i1, 21219)), i3, (URI__HierarchicalURI)i0);
  
l48:
  return (OOC_Repository__Module)i0;
  ;
}

OOC_SymbolTable__Module OOC_Repository__ModuleDesc_ReadSymbolFile(OOC_Repository__Module m) {
  register OOC_INT32 i0,i1,i2,i3;
  URI__URI uri;
  IO__ByteChannel ch;
  IO__ByteChannel chDoc;
  OOC_SymbolTable_Builder__Builder stb;
  OOC_SymbolTable__Module symTab;

  i0 = (OOC_INT32)m;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 23444))+16);
  i1 = i1==4;
  if (i1) goto l10;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 23527)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i0, 1, 1u);
  uri = (URI__URI)i1;
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 23574)))), URI__URIDesc_GetChannel)),URI__URIDesc_GetChannel)((URI__URI)i1, 2);
  ch = (IO__ByteChannel)i2;
  OOC_Logger__ReadFile((URI__URI)i1);
  i1 = OOC_Repository__readDocStrings;
  if (i1) goto l5;
  chDoc = (IO__ByteChannel)(OOC_INT32)0;
  i0=(OOC_INT32)0;
  goto l6;
l5:
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 23679)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i0, 20, 1u);
  uri = (URI__URI)i0;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 23734)))), URI__URIDesc_GetChannel)),URI__URIDesc_GetChannel)((URI__URI)i0, 2);
  chDoc = (IO__ByteChannel)i1;
  OOC_Logger__ReadFile((URI__URI)i0);
  i0=i1;
l6:
  i1 = (OOC_INT32)OOC_SymbolTable_Builder__New();
  stb = (OOC_SymbolTable_Builder__Builder)i1;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 23893)))), OOC_SymbolTable_Builder__BuilderDesc_ReadSymbolTable)),OOC_SymbolTable_Builder__BuilderDesc_ReadSymbolTable)((OOC_SymbolTable_Builder__Builder)i1, (IO__ByteChannel)i2, (IO__ByteChannel)i0);
  symTab = (OOC_SymbolTable__Module)i1;
  i3 = i0!=(OOC_INT32)0;
  if (!i3) goto l9;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 23965)))), IO__ChannelDesc_Close)),IO__ChannelDesc_Close)((IO__Channel)i0);
l9:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 23992)))), IO__ChannelDesc_Close)),IO__ChannelDesc_Close)((IO__Channel)i2);
  return (OOC_SymbolTable__Module)i1;
  goto l11;
l10:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23495))+12);
  return (OOC_SymbolTable__Module)i0;
l11:
  _failed_function(22669); return 0;
  ;
}

void OOC_OOC_Repository_init(void) {
  _c0 = Object__NewLatin1Region("src", 4, 0, 3);
  _c1 = Object__NewLatin1Region("sym", 4, 0, 3);
  _c2 = Object__NewLatin1Region("oocdoc/xml", 11, 0, 10);
  _c3 = Object__NewLatin1Region("oocdoc/html", 12, 0, 11);
  _c4 = Object__NewLatin1Region("obj", 4, 0, 3);
  _c5 = Object__NewLatin1Region("obj", 4, 0, 3);
  _c6 = Object__NewLatin1Region("bin", 4, 0, 3);
  _c7 = Object__NewLatin1Region("obj", 4, 0, 3);
  _c8 = Object__NewLatin1Region("rsrc", 5, 0, 4);
  _c9 = Object__NewLatin1Region(".Mod", 5, 0, 4);
  _c10 = Object__NewLatin1Region(".Sym", 5, 0, 4);
  _c11 = Object__NewLatin1Region(".Doc", 5, 0, 4);
  _c12 = Object__NewLatin1Region("_symtab.xml", 12, 0, 11);
  _c13 = Object__NewLatin1Region("_sym.xml", 9, 0, 8);
  _c14 = Object__NewLatin1Region(".xml", 5, 0, 4);
  _c15 = Object__NewLatin1Region(".html", 6, 0, 5);
  _c16 = Object__NewLatin1Region("_op.xml", 8, 0, 7);
  _c17 = Object__NewLatin1Region(".o", 3, 0, 2);
  _c18 = Object__NewLatin1Region(".lo", 4, 0, 3);
  _c19 = Object__NewLatin1Region(".c", 3, 0, 2);
  _c20 = Object__NewLatin1Region(".d", 3, 0, 2);
  _c21 = Object__NewLatin1Region(".oh", 4, 0, 3);
  _c22 = Object__NewLatin1Region(".s", 3, 0, 2);
  _c23 = Object__NewLatin1Region("_.c", 4, 0, 3);
  _c24 = Object__NewLatin1Region("_.s", 4, 0, 3);
  _c25 = Object__NewLatin1Region("_.o", 4, 0, 3);
  _c26 = Object__NewLatin1Region("", 1, 0, 0);
  _c27 = Object__NewLatin1Region(".la", 4, 0, 3);

  OOC_Repository__readDocStrings = 0u;
  return;
  ;
}

/* --- */
