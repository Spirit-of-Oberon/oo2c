#include <OOC/Repository/FileSystem.d>
#include <__oo2c.h>
#include <setjmp.h>

OOC_Repository_FileSystem__Repository OOC_Repository_FileSystem__New(OOC_Repository__Repository baseRep, URI__HierarchicalURI baseDir) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_Repository_FileSystem__Repository rep;
  URI__URI relative;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Repository_FileSystem__Repository.baseTypes[0]);
  rep = (OOC_Repository_FileSystem__Repository)i0;
  i1 = (OOC_INT32)baseRep;
  i2 = (OOC_INT32)baseDir;
  OOC_Repository__Init((OOC_Repository__Repository)i0, (OOC_Repository__Repository)i1, (URI__HierarchicalURI)i2);
  i1 = (OOC_INT32)URI_Scheme_File__GetCwd();
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 1778)))), URI__HierarchicalURIDesc_MakeRelative)),URI__HierarchicalURIDesc_MakeRelative)((URI__HierarchicalURI)i2, (URI__HierarchicalURI)i1);
  relative = (URI__URI)i1;
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 1827));
  i3 = i3==0;
  if (i3) goto l3;
  i3=0u;
  goto l5;
l3:
  i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 1863)))), &_td_URI_Scheme_File__URIDesc);
  
l5:
  if (i3) goto l7;
  i3=0u;
  goto l9;
l7:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 1906)))), &_td_URI_Scheme_File__URIDesc, 1906)), 1910))+12);
  i3 = i3!=0;
  
l9:
  if (i3) goto l11;
  i3=0u;
  goto l13;
l11:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 1955)))), &_td_URI_Scheme_File__URIDesc, 1955)), 1959))+12);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 1955)))), &_td_URI_Scheme_File__URIDesc, 1955)), 1959))+12);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 1969))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 1969))+4);
  i3 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 1977)))), Object__StringDesc_Equals)),Object__StringDesc_Equals)((Object__String)i3, (Object__Object)((OOC_INT32)_c0));
  i3 = !i3;
  
l13:
  if (i3) goto l15;
  *(OOC_INT32*)((_check_pointer(i0, 2066))+12) = i2;
  goto l16;
l15:
  *(OOC_INT32*)((_check_pointer(i0, 2005))+12) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2042)))), &_td_URI_Scheme_File__URIDesc, 2042));
l16:
  return (OOC_Repository_FileSystem__Repository)i0;
  ;
}

static void OOC_Repository_FileSystem__InitModule(OOC_Repository_FileSystem__Module m, OOC_Repository_FileSystem__Repository origin, const Msg__String name__ref, OOC_LEN name_0d, URI__HierarchicalURI srcFileOverride) {
  register OOC_INT32 i0,i1,i2;
  OOC_ALLOCATE_VPAR(name,OOC_CHAR8 ,name_0d)

  OOC_INITIALIZE_VPAR(name__ref,name,OOC_CHAR8 ,name_0d)
  i0 = (OOC_INT32)srcFileOverride;
  i1 = (OOC_INT32)origin;
  i2 = (OOC_INT32)m;
  OOC_Repository__InitModule((OOC_Repository__Module)i2, (OOC_Repository__Repository)i1, (void*)(OOC_INT32)name, name_0d, (URI__HierarchicalURI)i0);
  return;
  ;
}

static OOC_Repository_FileSystem__Module OOC_Repository_FileSystem__NewModule(OOC_Repository_FileSystem__Repository origin, const Msg__String name__ref, OOC_LEN name_0d, URI__HierarchicalURI srcFileOverride) {
  register OOC_INT32 i0,i1,i2;
  OOC_ALLOCATE_VPAR(name,OOC_CHAR8 ,name_0d)

  OOC_INITIALIZE_VPAR(name__ref,name,OOC_CHAR8 ,name_0d)
  i0 = (OOC_INT32)origin;
  i1 = (OOC_INT32)srcFileOverride;
  i2 = (OOC_INT32)RT0__NewObject(_td_OOC_Repository_FileSystem__Module.baseTypes[0]);
  OOC_Repository_FileSystem__InitModule((OOC_Repository_FileSystem__Module)i2, (OOC_Repository_FileSystem__Repository)i0, (void*)(OOC_INT32)name, name_0d, (URI__HierarchicalURI)i1);
  return (OOC_Repository_FileSystem__Module)i2;
  ;
}

Object__String8 OOC_Repository_FileSystem__ModuleToFileName(const OOC_CHAR8 name__ref[], OOC_LEN name_0d) {
  register OOC_INT32 i0,i1;
  OOC_ALLOCATE_VPAR(name,OOC_CHAR8 ,name_0d)

  OOC_INITIALIZE_VPAR(name__ref,name,OOC_CHAR8 ,name_0d)
  i0 = *(OOC_UINT8*)((OOC_INT32)name+(_check_index(0, name_0d, OOC_UINT32, 2749)));
  i0 = i0!=0u;
  if (!i0) goto l11;
  i0=0;
l3_loop:
  i1 = *(OOC_UINT8*)((OOC_INT32)name+(_check_index(i0, name_0d, OOC_UINT32, 2776)));
  i1 = i1==58u;
  if (!i1) goto l6;
  *(OOC_UINT8*)((OOC_INT32)name+(_check_index(i0, name_0d, OOC_UINT32, 2804))) = 47u;
l6:
  i0 = i0+1;
  i1 = *(OOC_UINT8*)((OOC_INT32)name+(_check_index(i0, name_0d, OOC_UINT32, 2749)));
  i1 = i1!=0u;
  if (i1) goto l3_loop;
l11:
  i0 = (OOC_INT32)Object__NewLatin1((void*)(OOC_INT32)name, name_0d);
  return (Object__String8)i0;
  ;
}

OOC_Repository_FileSystem__Module OOC_Repository_FileSystem__RepositoryDesc_GetModule(volatile OOC_Repository_FileSystem__Repository rep, const OOC_CHAR8 moduleName__ref[], volatile OOC_LEN moduleName_0d, volatile URI__HierarchicalURI srcFileOverride) {
  register OOC_INT32 i0,i1;
  OOC_ALLOCATE_VPAR(moduleName,OOC_CHAR8 ,moduleName_0d)
  volatile URI__URI uri;
  auto URI__URI OOC_Repository_FileSystem__RepositoryDesc_GetModule_GetURI(OOC_INT8 fileId);
  jmp_buf _target0, _target1;
  Exception__Context _context0, _context1;
    
    URI__URI OOC_Repository_FileSystem__RepositoryDesc_GetModule_GetURI(OOC_INT8 fileId) {
      register OOC_INT32 i0,i1,i2;
      ADT_StringBuffer__StringBuffer sb;
      Object__String string;

      i0 = (OOC_INT32)rep;
      i1 = fileId;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3387)))), OOC_Repository__RepositoryDesc_GetDefaultSubdir)),OOC_Repository__RepositoryDesc_GetDefaultSubdir)((OOC_Repository__Repository)i0, i1);
      i0 = (OOC_INT32)ADT_StringBuffer__New((Object__String)i0);
      sb = (ADT_StringBuffer__StringBuffer)i0;
      i2 = *(OOC_INT32*)((_check_pointer(i0, 3437))+4);
      i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3427)))), ADT_StringBuffer__StringBufferDesc_CharAt)),ADT_StringBuffer__StringBufferDesc_CharAt)((ADT_StringBuffer__StringBuffer)i0, (i2-1));
      i2 = i2!=47u;
      if (!i2) goto l4;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3470)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c1));
l4:
      i2 = (OOC_INT32)OOC_Repository_FileSystem__ModuleToFileName((void*)(OOC_INT32)moduleName, moduleName_0d);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3503)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i2);
      i2 = (OOC_INT32)rep;
      i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 3561)))), OOC_Repository__RepositoryDesc_GetDefaultSuffix)),OOC_Repository__RepositoryDesc_GetDefaultSuffix)((OOC_Repository__Repository)i2, i1);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3550)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i1);
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3608)))), ADT_StringBuffer__StringBufferDesc_ToString)),ADT_StringBuffer__StringBufferDesc_ToString)((ADT_StringBuffer__StringBuffer)i0);
      string = (Object__String)i0;
      i1 = (OOC_INT32)rep;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3678))+4);
      i0 = (OOC_INT32)URI_Parser__NewURI((Object__String8)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3665)))), &_td_Object__String8Desc, 3665)), (URI__HierarchicalURI)i1);
      return (URI__URI)i0;
      ;
    }


  OOC_INITIALIZE_VPAR(moduleName__ref,moduleName,OOC_CHAR8 ,moduleName_0d)
  {
    Exception__PushContext(&_context0, &_target0);
    if (!setjmp(_target0)) goto l7;
    Exception__PopContext(1);
    i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG(((OOC_INT32)Exception__Current()))), &_td_Exception__ParseErrorDesc);
    if (i0) goto l5;
    Exception__ActivateContext();
    goto l6;
l5:
    return (OOC_Repository_FileSystem__Module)(OOC_INT32)0;
l6:
    Exception__Clear();
    goto l8;
l7:
    i0 = (OOC_INT32)OOC_Repository_FileSystem__RepositoryDesc_GetModule_GetURI(0);
    uri = (URI__URI)i0;
    Exception__PopContext(1);
l8:;
  }
  i0 = (OOC_INT32)srcFileOverride;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l27;
  i1 = (OOC_INT32)uri;
  i1 = (OOC_INT32)URI_Scheme_File__URIDesc_GetPath((URI_Scheme_File__URI)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4055)))), &_td_URI_Scheme_File__URIDesc, 4055)));
  i1 = OS_Files__Exists((Object__String)i1);
  if (i1) goto l25;
  {
    Exception__PushContext(&_context1, &_target1);
    if (!setjmp(_target1)) goto l19;
    Exception__PopContext(1);
    i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG(((OOC_INT32)Exception__Current()))), &_td_Exception__ParseErrorDesc);
    if (i0) goto l17;
    Exception__ActivateContext();
    goto l18;
l17:
    return (OOC_Repository_FileSystem__Module)(OOC_INT32)0;
l18:
    Exception__Clear();
    goto l20;
l19:
    i0 = (OOC_INT32)OOC_Repository_FileSystem__RepositoryDesc_GetModule_GetURI(1);
    uri = (URI__URI)i0;
    Exception__PopContext(1);
l20:;
  }
  i0 = (OOC_INT32)uri;
  i0 = (OOC_INT32)URI_Scheme_File__URIDesc_GetPath((URI_Scheme_File__URI)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4384)))), &_td_URI_Scheme_File__URIDesc, 4384)));
  i0 = OS_Files__Exists((Object__String)i0);
  if (i0) goto l23;
  return (OOC_Repository_FileSystem__Module)(OOC_INT32)0;
  goto l28;
l23:
  i0 = (OOC_INT32)srcFileOverride;
  i1 = (OOC_INT32)rep;
  i0 = (OOC_INT32)OOC_Repository_FileSystem__NewModule((OOC_Repository_FileSystem__Repository)i1, (void*)(OOC_INT32)moduleName, moduleName_0d, (URI__HierarchicalURI)i0);
  return (OOC_Repository_FileSystem__Module)i0;
  goto l28;
l25:
  i1 = (OOC_INT32)rep;
  i0 = (OOC_INT32)OOC_Repository_FileSystem__NewModule((OOC_Repository_FileSystem__Repository)i1, (void*)(OOC_INT32)moduleName, moduleName_0d, (URI__HierarchicalURI)i0);
  return (OOC_Repository_FileSystem__Module)i0;
  goto l28;
l27:
  i1 = (OOC_INT32)rep;
  i0 = (OOC_INT32)OOC_Repository_FileSystem__NewModule((OOC_Repository_FileSystem__Repository)i1, (void*)(OOC_INT32)moduleName, moduleName_0d, (URI__HierarchicalURI)i0);
  return (OOC_Repository_FileSystem__Module)i0;
l28:
  _failed_function(2937); return 0;
  ;
}

URI__URI OOC_Repository_FileSystem__RepositoryDesc_GetResource(volatile OOC_Repository_FileSystem__Repository rep, const OOC_CHAR8 package__ref[], volatile OOC_LEN package_0d, const OOC_CHAR8 path__ref[], volatile OOC_LEN path_0d) {
  register OOC_INT32 i0,i1;
  OOC_ALLOCATE_VPAR(package,OOC_CHAR8 ,package_0d)
  OOC_ALLOCATE_VPAR(path,OOC_CHAR8 ,path_0d)
  volatile Object__String string;
  volatile ADT_StringBuffer__StringBuffer sb;
  volatile URI__URI uri;
  jmp_buf _target0;
  Exception__Context _context0;

  OOC_INITIALIZE_VPAR(package__ref,package,OOC_CHAR8 ,package_0d)
  OOC_INITIALIZE_VPAR(path__ref,path,OOC_CHAR8 ,path_0d)
  i0 = (
  _cmp8((const void*)(OOC_INT32)package,(const void*)""))==0;
  if (i0) goto l10;
  i0 = (OOC_INT32)rep;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4958)))), OOC_Repository__RepositoryDesc_GetDefaultSubdir)),OOC_Repository__RepositoryDesc_GetDefaultSubdir)((OOC_Repository__Repository)i0, 21);
  i0 = (OOC_INT32)ADT_StringBuffer__New((Object__String)i0);
  sb = (ADT_StringBuffer__StringBuffer)i0;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 5008))+4);
  i1 = i1!=0;
  if (i1) goto l5;
  i1=0u;
  goto l7;
l5:
  i1 = *(OOC_INT32*)((_check_pointer(i0, 5036))+4);
  i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5026)))), ADT_StringBuffer__StringBufferDesc_CharAt)),ADT_StringBuffer__StringBufferDesc_CharAt)((ADT_StringBuffer__StringBuffer)i0, (i1-1));
  i1 = i1!=47u;
  
l7:
  if (!i1) goto l9;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5069)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c2));
l9:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5102)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1)),ADT_StringBuffer__StringBufferDesc_AppendLatin1)((ADT_StringBuffer__StringBuffer)i0, (void*)(OOC_INT32)package, package_0d);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5134)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c3));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5156)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1)),ADT_StringBuffer__StringBufferDesc_AppendLatin1)((ADT_StringBuffer__StringBuffer)i0, (void*)(OOC_INT32)path, path_0d);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5195)))), ADT_StringBuffer__StringBufferDesc_ToString)),ADT_StringBuffer__StringBufferDesc_ToString)((ADT_StringBuffer__StringBuffer)i0);
  string = (Object__String)i0;
  
  goto l11;
l10:
  i0 = (OOC_INT32)Object__NewLatin1((void*)(OOC_INT32)path, path_0d);
  string = (Object__String)i0;
  
l11:
  {
    Exception__PushContext(&_context0, &_target0);
    if (!setjmp(_target0)) goto l18;
    Exception__PopContext(1);
    i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG(((OOC_INT32)Exception__Current()))), &_td_Exception__ParseErrorDesc);
    if (i0) goto l16;
    Exception__ActivateContext();
    goto l17;
l16:
    return (URI__URI)(OOC_INT32)0;
l17:
    Exception__Clear();
    goto l19;
l18:
    i1 = (OOC_INT32)rep;
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 5420))+4);
    i0 = (OOC_INT32)URI_Parser__NewURI((Object__String8)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5407)))), &_td_Object__String8Desc, 5407)), (URI__HierarchicalURI)i1);
    uri = (URI__URI)i0;
    Exception__PopContext(1);
l19:;
  }
  i0 = (OOC_INT32)uri;
  i1 = (OOC_INT32)URI_Scheme_File__URIDesc_GetPath((URI_Scheme_File__URI)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5530)))), &_td_URI_Scheme_File__URIDesc, 5530)));
  i1 = OS_Files__Exists((Object__String)i1);
  if (i1) goto l22;
  return (URI__URI)(OOC_INT32)0;
  goto l23;
l22:
  return (URI__URI)i0;
l23:
  _failed_function(4632); return 0;
  ;
}

void OOC_Repository_FileSystem__RepositoryDesc_DumpContent(OOC_Repository_FileSystem__Repository rep, TextRider__Writer w) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5701)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, "  <file-system>", 16);
  i1 = (OOC_INT32)rep;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 5759))+4);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 5759))+4);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 5767)))), URI__URIDesc_ToString)),URI__URIDesc_ToString)((URI__URI)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5741)))), TextRider__WriterDesc_WriteObject)),TextRider__WriterDesc_WriteObject)((TextRider__Writer)i0, (Object__Object)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5786)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, "</file-system>", 15);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5825)))), TextRider__WriterDesc_WriteLn)),TextRider__WriterDesc_WriteLn)((TextRider__Writer)i0);
  return;
  ;
}

Object__String8 OOC_Repository_FileSystem__RepositoryDesc_GetLocalPath(OOC_Repository_FileSystem__Repository rep, OOC_Repository__Module m, OOC_INT8 fileId) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  ADT_StringBuffer__StringBuffer sb;
  Object__String string;

  i0 = (OOC_INT32)rep;
  i1 = fileId;
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6048)))), OOC_Repository__RepositoryDesc_GetDefaultSubdir)),OOC_Repository__RepositoryDesc_GetDefaultSubdir)((OOC_Repository__Repository)i0, i1);
  i2 = (OOC_INT32)ADT_StringBuffer__New((Object__String)i2);
  sb = (ADT_StringBuffer__StringBuffer)i2;
  i3 = *(OOC_INT32*)((_check_pointer(i2, 6086))+4);
  i3 = i3!=0;
  if (i3) goto l3;
  i3=0u;
  goto l5;
l3:
  i3 = *(OOC_INT32*)((_check_pointer(i2, 6114))+4);
  i3 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 6104)))), ADT_StringBuffer__StringBufferDesc_CharAt)),ADT_StringBuffer__StringBufferDesc_CharAt)((ADT_StringBuffer__StringBuffer)i2, (i3-1));
  i3 = i3!=47u;
  
l5:
  if (!i3) goto l7;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 6145)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i2, (Object__Object)((OOC_INT32)_c4));
l7:
  i3 = i1==19;
  if (i3) goto l10;
  i3 = (OOC_INT32)m;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 6368))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 6368))+4);
  i4 = OOC_ARRAY_LENGTH((_check_pointer(i4, 6373)), 0);
  i3 = (OOC_INT32)OOC_Repository_FileSystem__ModuleToFileName((void*)(_check_pointer(i3, 6373)), i4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 6342)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i2, (Object__Object)i3);
  goto l11;
l10:
  i3 = (OOC_INT32)m;
  i4 = *(OOC_INT8*)((_check_pointer(i3, 6225))+16);
  _assert((i4==4), 127, 6217);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 6270)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i2, (Object__Object)((OOC_INT32)_c5));
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 6303))+12);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 6310))+56);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 6294)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i2, (Object__Object)i3);
l11:
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6404)))), OOC_Repository__RepositoryDesc_GetDefaultSuffix)),OOC_Repository__RepositoryDesc_GetDefaultSuffix)((OOC_Repository__Repository)i0, i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 6393)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i2, (Object__Object)i0);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 6449)))), ADT_StringBuffer__StringBufferDesc_ToString)),ADT_StringBuffer__StringBufferDesc_ToString)((ADT_StringBuffer__StringBuffer)i2);
  string = (Object__String)i0;
  return (Object__String8)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6487)))), &_td_Object__String8Desc, 6487));
  ;
}

URI__HierarchicalURI OOC_Repository_FileSystem__ModuleDesc_GetURI(volatile OOC_Repository_FileSystem__Module m, volatile OOC_INT8 fileId, volatile OOC_CHAR8 allowRelative) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  volatile URI__HierarchicalURI huri;
  volatile Object__String8 path;
  volatile URI__URI uri;
  jmp_buf _target0;
  Exception__Context _context0;

  i0 = fileId;
  i1 = (OOC_INT32)m;
  i2 = allowRelative;
  i3 = (OOC_INT32)OOC_Repository__ModuleDesc_GetURI((OOC_Repository__Module)i1, i0, i2);
  huri = (URI__HierarchicalURI)i3;
  i4 = i3==(OOC_INT32)0;
  if (i4) goto l3;
  return (URI__HierarchicalURI)i3;
  goto l24;
l3:
  i3 = i0==0;
  if (i3) goto l6;
  i3=0u;
  goto l8;
l6:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6852))+8);
  i3 = i3!=(OOC_INT32)0;
  
l8:
  if (i3) goto l22;
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 6944));
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 6944));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 6951)))), OOC_Repository__RepositoryDesc_GetLocalPath)),OOC_Repository__RepositoryDesc_GetLocalPath)((OOC_Repository__Repository)i4, (OOC_Repository__Module)i1, i0);
  path = (Object__String8)i0;
  {
    Exception__PushContext(&_context0, &_target0);
    if (!setjmp(_target0)) goto l17;
    Exception__PopContext(1);
    i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG(((OOC_INT32)Exception__Current()))), &_td_Exception__ParseErrorDesc);
    if (i0) goto l14;
    Exception__ActivateContext();
    goto l15;
l14:
    _assert(0u, 127, 7309);
l15:
    Exception__Clear();
    goto l21;
l17:
    if (i2) goto l19;
    i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 7160));
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 7167))+4);
    i0 = (OOC_INT32)URI_Parser__NewURI((Object__String8)i0, (URI__HierarchicalURI)i1);
    uri = (URI__URI)i0;
    goto l20;
l19:
    i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 7064));
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7072)))), &_td_OOC_Repository_FileSystem__RepositoryDesc, 7072)), 7083))+12);
    i0 = (OOC_INT32)URI_Parser__NewURI((Object__String8)i0, (URI__HierarchicalURI)i1);
    uri = (URI__URI)i0;
l20:
    Exception__PopContext(1);
l21:;
  }
  i0 = (OOC_INT32)uri;
  return (URI__HierarchicalURI)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7361)))), &_td_URI__HierarchicalURIDesc, 7361));
  goto l24;
l22:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6898))+8);
  return (URI__HierarchicalURI)i0;
l24:
  _failed_function(6540); return 0;
  ;
}

void OOC_Repository_FileSystem__ModuleDesc_GetTimeStamp(OOC_Repository_FileSystem__Module m, OOC_INT8 fileId, struct Time__TimeStamp *ts, RT0__Struct ts__tag) {
  register OOC_INT32 i0,i1,i2;
  URI__URI uri;
  Object__String path;
  Object__CharsLatin1 chars;
  Msg__Msg res;

  i0 = fileId;
  i1 = (OOC_INT32)m;
  i0 = (OOC_INT32)OOC_Repository_FileSystem__ModuleDesc_GetURI((OOC_Repository_FileSystem__Module)i1, i0, 0u);
  uri = (URI__URI)i0;
  i0 = (OOC_INT32)URI_Scheme_File__URIDesc_GetPath((URI_Scheme_File__URI)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7683)))), &_td_URI_Scheme_File__URIDesc, 7683)));
  path = (Object__String)i0;
  i0 = (OOC_INT32)OS_Path__Encode((Object__String)i0);
  chars = (Object__CharsLatin1)i0;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 7757)), 0);
  i2 = (OOC_INT32)ts__tag;
  Files__GetModTime((void*)(_check_pointer(i0, 7757)), i1, (void*)(OOC_INT32)ts, (RT0__Struct)i2, (void*)(OOC_INT32)&res);
  i0 = (OOC_INT32)res;
  i0 = i0!=(OOC_INT32)0;
  if (!i0) goto l3;
  Time__InitTimeStamp((void*)(OOC_INT32)ts, (RT0__Struct)i2, 2147483647, 0);
l3:
  return;
  ;
}

OOC_CHAR8 OOC_Repository_FileSystem__ModuleDesc_FileExists(OOC_Repository_FileSystem__Module m, OOC_INT8 fileId) {
  register OOC_INT32 i0,i1;
  URI__URI uri;

  i0 = fileId;
  i1 = (OOC_INT32)m;
  i0 = (OOC_INT32)OOC_Repository_FileSystem__ModuleDesc_GetURI((OOC_Repository_FileSystem__Module)i1, i0, 0u);
  uri = (URI__URI)i0;
  i0 = (OOC_INT32)URI_Scheme_File__URIDesc_GetPath((URI_Scheme_File__URI)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8042)))), &_td_URI_Scheme_File__URIDesc, 8042)));
  i0 = OS_Files__Exists((Object__String)i0);
  return i0;
  ;
}

OOC_Scanner_InputBuffer__Buffer OOC_Repository_FileSystem__ModuleDesc_GetInputBuffer(OOC_Repository_FileSystem__Module m) {
  register OOC_INT32 i0,i1,i2;
  URI__URI modURI;
  Object__String str;
  OOC_Error__List errList;

  i0 = (OOC_INT32)m;
  i0 = (OOC_INT32)OOC_Repository_FileSystem__ModuleDesc_GetURI((OOC_Repository_FileSystem__Module)i0, 0, 1u);
  modURI = (URI__URI)i0;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8379)))), &_td_URI_Scheme_File__URIDesc);
  if (i1) goto l3;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8472)))), URI__URIDesc_ToString)),URI__URIDesc_ToString)((URI__URI)i0);
  str = (Object__String)i1;
  
  goto l4;
l3:
  i1 = (OOC_INT32)URI_Scheme_File__URIDesc_GetPath((URI_Scheme_File__URI)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8428)))), &_td_URI_Scheme_File__URIDesc, 8428)));
  str = (Object__String)i1;
  
l4:
  i1 = (OOC_INT32)OOC_Error__NewList((Object__String)i1);
  errList = (OOC_Error__List)i1;
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8584)))), URI__URIDesc_GetChannel)),URI__URIDesc_GetChannel)((URI__URI)i0, 2);
  OOC_Logger__ReadFile((URI__URI)i0);
  i0 = (OOC_INT32)OOC_Scanner_InputBuffer__New((IO__ByteChannel)i2, (OOC_Error__List)i1);
  return (OOC_Scanner_InputBuffer__Buffer)i0;
  ;
}

void OOC_Repository_FileSystem__ModuleDesc_CreateOutputDir(OOC_Repository_FileSystem__Module m, OOC_INT8 fileId) {
  register OOC_INT32 i0,i1;
  URI__URI uri;

  i0 = fileId;
  i1 = (OOC_INT32)m;
  i0 = (OOC_INT32)OOC_Repository_FileSystem__ModuleDesc_GetURI((OOC_Repository_FileSystem__Module)i1, i0, 1u);
  uri = (URI__URI)i0;
  i0 = (OOC_INT32)URI_Scheme_File__URIDesc_GetPath((URI_Scheme_File__URI)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8903)))), &_td_URI_Scheme_File__URIDesc, 8903)));
  i0 = (OOC_INT32)OS_Path__DirName((Object__String)i0);
  OS_Files__MakeDirs((Object__String)i0, 511);
  return;
  ;
}

IO__ByteChannel OOC_Repository_FileSystem__ModuleDesc_GetOutputChannel(OOC_Repository_FileSystem__Module m, OOC_INT8 fileId, OOC_CHAR8 makeTmp) {
  register OOC_INT32 i0,i1;
  URI__URI uri;

  i0 = fileId;
  i1 = (OOC_INT32)m;
  OOC_Repository_FileSystem__ModuleDesc_CreateOutputDir((OOC_Repository_FileSystem__Module)i1, i0);
  i0 = (OOC_INT32)OOC_Repository_FileSystem__ModuleDesc_GetURI((OOC_Repository_FileSystem__Module)i1, i0, 1u);
  uri = (URI__URI)i0;
  OOC_Logger__WriteFile((URI__URI)i0);
  i1 = makeTmp;
  if (i1) goto l3;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9360)))), URI__URIDesc_GetChannel)),URI__URIDesc_GetChannel)((URI__URI)i0, 0);
  return (IO__ByteChannel)i0;
  goto l4;
l3:
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9305)))), URI__URIDesc_GetChannel)),URI__URIDesc_GetChannel)((URI__URI)i0, 1);
  return (IO__ByteChannel)i0;
l4:
  _failed_function(9009); return 0;
  ;
}

void OOC_OOC_Repository_FileSystem_init(void) {
  register OOC_INT32 i0;
  _c0 = Object__NewLatin1Region("..", 3, 0, 2);
  _c1 = Object__NewLatin1Char(47u);
  _c2 = Object__NewLatin1Char(47u);
  _c3 = Object__NewLatin1Char(47u);
  _c4 = Object__NewLatin1Char(47u);
  _c5 = Object__NewLatin1Region("lib", 4, 0, 3);

  i0 = (OOC_INT32)URI_Scheme_File__GetCwd();
  OOC_Repository_FileSystem__baseURI = (URI__HierarchicalURI)i0;
  return;
  ;
}

void OOC_OOC_Repository_FileSystem_destroy(void) {
}

/* --- */
