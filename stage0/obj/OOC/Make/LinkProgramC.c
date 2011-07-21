#include <OOC/Make/LinkProgramC.d>
#include <__oo2c.h>
#include <setjmp.h>

static Object__StringArrayPtr OOC_Make_LinkProgramC__GetExternalLibs(const OOC_Repository__Module moduleList__ref[], OOC_LEN moduleList_0d, Object__String thisLibrary) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_ALLOCATE_VPAR(moduleList,OOC_Repository__Module ,moduleList_0d)
  ADT_Dictionary__Dictionary libDeps;
  ADT_Dictionary__Dictionary option;
  OOC_INT32 i;
  OOC_SymbolTable__LinkDirective linkDirective;
  ADT_ArrayList__ArrayList depArray;
  OOC_INT32 j;
  Object__String prev;
  Object__String _new;
  Object__StringArrayPtr extLibs;
  ADT_Dictionary__Dictionary visited;
  auto ADT_ArrayList__ArrayList OOC_Make_LinkProgramC__GetExternalLibs_GetDepArray(Object__String libName);
  auto void OOC_Make_LinkProgramC__GetExternalLibs_AddLibrary(Object__String libName, OOC_INT32 *pos);
  auto OOC_CHAR8 OOC_Make_LinkProgramC__GetExternalLibs_IncludeModule(OOC_Repository__Module module);
  auto Object__String OOC_Make_LinkProgramC__GetExternalLibs_Option(OOC_SymbolTable__LinkLib lib);
  auto Object__String OOC_Make_LinkProgramC__GetExternalLibs_LookupValue(Object__String optionName);
    
    ADT_ArrayList__ArrayList OOC_Make_LinkProgramC__GetExternalLibs_GetDepArray(Object__String libName) {
      register OOC_INT32 i0,i1,i2;

      i0 = (OOC_INT32)libDeps;
      i1 = (OOC_INT32)libName;
      i0 = ADT_Dictionary__DictionaryDesc_HasKey((ADT_Dictionary__Dictionary)i0, (Object__Object)i1);
      if (i0) goto l3;
      i0 = (OOC_INT32)ADT_ArrayList__New(4);
      i2 = (OOC_INT32)libDeps;
      ADT_Dictionary__DictionaryDesc_Set((ADT_Dictionary__Dictionary)i2, (Object__Object)i1, (Object__Object)i0);
      return (ADT_ArrayList__ArrayList)i0;
      goto l4;
l3:
      i0 = (OOC_INT32)libDeps;
      i0 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i0, (Object__Object)i1);
      return (ADT_ArrayList__ArrayList)i0;
l4:
      _failed_function(1646); return 0;
      ;
    }

    
    void OOC_Make_LinkProgramC__GetExternalLibs_AddLibrary(Object__String libName, OOC_INT32 *pos) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5;
      ADT_ArrayList__ArrayList depArray;
      OOC_INT32 i;
      Object__Object obj;

      i0 = (OOC_INT32)visited;
      i1 = (OOC_INT32)libName;
      i0 = ADT_Dictionary__DictionaryDesc_HasKey((ADT_Dictionary__Dictionary)i0, (Object__Object)i1);
      i0 = !i0;
      if (i0) goto l3;
      i0=0u;
      goto l5;
l3:
      i0 = (OOC_INT32)libDeps;
      i0 = ADT_Dictionary__DictionaryDesc_HasKey((ADT_Dictionary__Dictionary)i0, (Object__Object)i1);
      
l5:
      if (!i0) goto l15;
      i0 = (OOC_INT32)visited;
      ADT_Dictionary__DictionaryDesc_Set((ADT_Dictionary__Dictionary)i0, (Object__Object)i1, (Object__Object)(OOC_INT32)0);
      i0 = (OOC_INT32)OOC_Make_LinkProgramC__GetExternalLibs_GetDepArray((Object__String)i1);
      depArray = (ADT_ArrayList__ArrayList)i0;
      i = 0;
      i2 = *(OOC_INT32*)((_check_pointer(i0, 2290))+4);
      i3 = 0<i2;
      if (!i3) goto l14;
      i3=0;
l9_loop:
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 2330));
      i4 = _check_pointer(i4, 2336);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 2336))*4);
      OOC_Make_LinkProgramC__GetExternalLibs_AddLibrary((Object__String)(_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 2347)))), &_td_Object__StringDesc, 2347)), (void*)(OOC_INT32)pos);
      i3 = i3+1;
      i = i3;
      i4 = i3<i2;
      if (i4) goto l9_loop;
l14:
      i0 = (OOC_INT32)option;
      i0 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i0, (Object__Object)i1);
      obj = (Object__Object)i0;
      i1 = (OOC_INT32)extLibs;
      i1 = _check_pointer(i1, 2426);
      i2 = OOC_ARRAY_LENGTH(i1, 0);
      i3 = *pos;
      *(OOC_INT32*)(i1+(_check_index(i3, i2, OOC_UINT32, 2426))*4) = (_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2439)))), &_td_Object__StringDesc, 2439));
      *pos = (i3+1);
l15:
      return;
      ;
    }

    
    OOC_CHAR8 OOC_Make_LinkProgramC__GetExternalLibs_IncludeModule(OOC_Repository__Module module) {
      register OOC_INT32 i0,i1,i2;

      i0 = (OOC_INT32)module;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2592))+12);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 2599))+56);
      i1 = i1==(OOC_INT32)0;
      if (i1) goto l3;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2638))+12);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 2645))+56);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2638))+12);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2645))+56);
      i2 = (OOC_INT32)thisLibrary;
      i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2657)))), Object__StringDesc_Equals)),Object__StringDesc_Equals)((Object__String)i0, (Object__Object)i2);
      
      goto l4;
l3:
      i0=1u;
l4:
      return i0;
      ;
    }

    
    Object__String OOC_Make_LinkProgramC__GetExternalLibs_Option(OOC_SymbolTable__LinkLib lib) {
      register OOC_INT32 i0,i1,i2;
      Object__Object obj;
      Object__String str;

      i0 = (OOC_INT32)lib;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2838))+4);
      i2 = (OOC_INT32)option;
      i1 = ADT_Dictionary__DictionaryDesc_HasKey((ADT_Dictionary__Dictionary)i2, (Object__Object)i1);
      if (i1) goto l8;
      i1 = *(OOC_INT32*)((_check_pointer(i0, 2956))+20);
      switch (i1) {
      case 0:
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3022))+4);
        str = (Object__String)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)_c0),(void*)i1));
        goto l7;
      case 1:
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3103))+4);
        str = (Object__String)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)_c1),(void*)i1));
        goto l7;
      default:
        _failed_case(i1, 2948);
        goto l7;
      }
l7:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3152))+4);
      i1 = (OOC_INT32)str;
      i2 = (OOC_INT32)option;
      ADT_Dictionary__DictionaryDesc_Set((ADT_Dictionary__Dictionary)i2, (Object__Object)i0, (Object__Object)i1);
      return (Object__String)i1;
      goto l9;
l8:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2886))+4);
      i1 = (OOC_INT32)option;
      i0 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i1, (Object__Object)i0);
      obj = (Object__Object)i0;
      return (Object__String)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2920)))), &_td_Object__StringDesc, 2920));
l9:
      _failed_function(2715); return 0;
      ;
    }

    
    Object__String OOC_Make_LinkProgramC__GetExternalLibs_LookupValue(Object__String optionName) {
      register OOC_INT32 i0,i1;
      Config__Variable v;

      i0 = (OOC_INT32)OOC_Config__options;
      i1 = (OOC_INT32)optionName;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3343)))), Config_Section_Options__SectionDesc_GetValue)),Config_Section_Options__SectionDesc_GetValue)((Config_Section_Options__Section)i0, (Object__String)i1);
      v = (Config__Variable)i0;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l3;
      i1=0u;
      goto l5;
l3:
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3390)))), &_td_Config__StringVarDesc);
      
l5:
      if (i1) goto l7;
      i0 = (OOC_INT32)OOC_Make_LinkProgramC__empty;
      return (Object__String)i0;
      goto l8;
l7:
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3442)))), &_td_Config__StringVarDesc, 3442)), 3452));
      return (Object__String)i0;
l8:
      _failed_function(3232); return 0;
      ;
    }


  OOC_INITIALIZE_VPAR(moduleList__ref,moduleList,OOC_Repository__Module ,(moduleList_0d*4))
  i0 = (OOC_INT32)RT0__NewObject(_td__qtd1.baseTypes[0]);
  libDeps = (ADT_Dictionary__Dictionary)i0;
  ADT_Dictionary__DictionaryDesc_INIT((ADT_Dictionary__Dictionary)i0);
  i0 = (OOC_INT32)ADT_Dictionary__New();
  option = (ADT_Dictionary__Dictionary)i0;
  i = 0;
  i0 = 0<moduleList_0d;
  if (!i0) goto l36;
  i1=0;
l3_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)((OOC_INT32)moduleList+(_check_index(i1, moduleList_0d, OOC_UINT32, 3859))*4);
  i1 = OOC_Make_LinkProgramC__GetExternalLibs_IncludeModule((OOC_Repository__Module)i1);
  if (!i1) goto l31;
  i1 = i;
  i1 = (OOC_INT32)*(OOC_INT32*)((OOC_INT32)moduleList+(_check_index(i1, moduleList_0d, OOC_UINT32, 3968))*4);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3971))+12);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3978))+64);
  linkDirective = (OOC_SymbolTable__LinkDirective)i1;
  i2 = i1!=(OOC_INT32)0;
  if (!i2) goto l31;
l8_loop:
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4062)))), &_td_OOC_SymbolTable__LinkLibDesc);
  if (!i2) goto l25;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4128))+4);
  i1 = (OOC_INT32)OOC_Make_LinkProgramC__GetExternalLibs_GetDepArray((Object__String)i1);
  depArray = (ADT_ArrayList__ArrayList)i1;
  i2 = (OOC_INT32)linkDirective;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 4186))+8);
  j = 0;
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 4199)), 0);
  i4 = 0<i3;
  if (!i4) goto l18;
  i4=0;
l13_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 4250))+8);
  i5 = _check_pointer(i5, 4263);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 4263))*4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4229)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i1, (Object__Object)i4);
  i4 = j;
  i4 = i4+1;
  j = i4;
  i5 = i4<i3;
  if (i5) goto l13_loop;
l18:
  i1 = (OOC_INT32)OOC_Make_LinkProgramC__GetExternalLibs_Option((OOC_SymbolTable__LinkLib)i2);
  prev = (Object__String)i1;
  i1 = (OOC_INT32)linkDirective;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4358))+12);
  i2 = i2!=(OOC_INT32)0;
  if (!i2) goto l21;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4443))+12);
  i2 = (OOC_INT32)OOC_Make_LinkProgramC__space;
  i1 = (OOC_INT32)OOC_Make_LinkProgramC__GetExternalLibs_LookupValue((Object__String)i1);
  i1 = (OOC_INT32)Object__StringDesc_Concat((Object__String)i2, (Object__String)i1);
  _new = (Object__String)i1;
  i2 = (OOC_INT32)linkDirective;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 4498))+4);
  i4 = (OOC_INT32)prev;
  i1 = (OOC_INT32)Object__StringDesc_Concat((Object__String)i1, (Object__String)i4);
  i4 = (OOC_INT32)option;
  ADT_Dictionary__DictionaryDesc_Set((ADT_Dictionary__Dictionary)i4, (Object__Object)i3, (Object__Object)i1);
  i1 = (OOC_INT32)OOC_Make_LinkProgramC__GetExternalLibs_Option((OOC_SymbolTable__LinkLib)i2);
  prev = (Object__String)i1;
l21:
  i1 = (OOC_INT32)linkDirective;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4636))+16);
  i2 = i2!=(OOC_INT32)0;
  if (!i2) goto l25;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4721))+16);
  i2 = (OOC_INT32)OOC_Make_LinkProgramC__space;
  i1 = (OOC_INT32)OOC_Make_LinkProgramC__GetExternalLibs_LookupValue((Object__String)i1);
  i1 = (OOC_INT32)Object__StringDesc_Concat((Object__String)i2, (Object__String)i1);
  _new = (Object__String)i1;
  i2 = (OOC_INT32)linkDirective;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 4776))+4);
  i3 = (OOC_INT32)prev;
  i1 = (OOC_INT32)Object__StringDesc_Concat((Object__String)i3, (Object__String)i1);
  i3 = (OOC_INT32)option;
  ADT_Dictionary__DictionaryDesc_Set((ADT_Dictionary__Dictionary)i3, (Object__Object)i2, (Object__Object)i1);
l25:
  i1 = (OOC_INT32)linkDirective;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 4933));
  linkDirective = (OOC_SymbolTable__LinkDirective)i1;
  i2 = i1!=(OOC_INT32)0;
  if (i2) goto l8_loop;
l31:
  i1 = i;
  i1 = i1+1;
  i = i1;
  i2 = i1<moduleList_0d;
  if (i2) goto l3_loop;
l36:
  i1 = (OOC_INT32)libDeps;
  i1 = ADT_Dictionary__DictionaryDesc_Size((ADT_Dictionary__Dictionary)i1);
  extLibs = (Object__StringArrayPtr)((OOC_INT32)RT0__NewObject(_td_Object__StringArrayPtr.baseTypes[0], i1));
  i1 = (OOC_INT32)ADT_Dictionary__New();
  visited = (ADT_Dictionary__Dictionary)i1;
  j = 0;
  i = 0;
  if (!i0) goto l58;
  i0=0;
l39_loop:
  i0 = (OOC_INT32)*(OOC_INT32*)((OOC_INT32)moduleList+(_check_index(i0, moduleList_0d, OOC_UINT32, 5345))*4);
  i0 = OOC_Make_LinkProgramC__GetExternalLibs_IncludeModule((OOC_Repository__Module)i0);
  if (!i0) goto l53;
  i0 = i;
  i0 = (OOC_INT32)*(OOC_INT32*)((OOC_INT32)moduleList+(_check_index(i0, moduleList_0d, OOC_UINT32, 5454))*4);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5457))+12);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5464))+64);
  linkDirective = (OOC_SymbolTable__LinkDirective)i0;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l53;
l44_loop:
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5548)))), &_td_OOC_SymbolTable__LinkLibDesc);
  if (!i1) goto l47;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5601))+4);
  OOC_Make_LinkProgramC__GetExternalLibs_AddLibrary((Object__String)i0, (void*)(OOC_INT32)&j);
l47:
  i0 = (OOC_INT32)linkDirective;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5726));
  linkDirective = (OOC_SymbolTable__LinkDirective)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l44_loop;
l53:
  i0 = i;
  i0 = i0+1;
  i = i0;
  i1 = i0<moduleList_0d;
  if (i1) goto l39_loop;
l58:
  i0 = (OOC_INT32)extLibs;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 5792)), 0);
  i2 = j;
  _assert((i2==i1), 127, 5770);
  return (Object__StringArrayPtr)i0;
  ;
}

OOC_CHAR8 OOC_Make_LinkProgramC__Run(OOC_Repository__Module module, const OOC_Repository__Module imports__ref[], OOC_LEN imports_0d, OOC_Package__Library forLibrary) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10;
  OOC_ALLOCATE_VPAR(imports,OOC_Repository__Module ,imports_0d)
  OOC_INT32 exit;
  OOC_INT8 objectFile;
  OOC_INT8 outputFile;
  Object__String forLibraryName;
  ADT_StringBuffer__StringBuffer sb;
  ADT_Dictionary__Dictionary importedLibs;
  ADT_ArrayList__ArrayList importedLibsList;
  OOC_INT32 i;
  Object__String libraryName;
  URI__URI uri;
  OOC_Repository__Module import;
  Object__StringArrayPtr extLibs;

  OOC_INITIALIZE_VPAR(imports__ref,imports,OOC_Repository__Module ,(imports_0d*4))
  exit = 0;
  i0 = (OOC_INT32)forLibrary;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l3;
  objectFile = 7;
  outputFile = 18;
  forLibraryName = (Object__String)(OOC_INT32)0;
  i1=18;i2=(OOC_INT32)0;i3=7;
  goto l4;
l3:
  objectFile = 8;
  outputFile = 19;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6522));
  forLibraryName = (Object__String)i1;
  i2=i1;i1=19;i3=8;
l4:
  i4 = (OOC_INT32)module;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 6683)))), OOC_Repository__ModuleDesc_CreateOutputDir)),OOC_Repository__ModuleDesc_CreateOutputDir)((OOC_Repository__Module)i4, i1);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 6801)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i4, i1, 1u);
  i1 = (OOC_INT32)OOC_Config_CCompiler__LinkProgramCmd((URI__URI)i1, (OOC_Package__Library)i0);
  i1 = (OOC_INT32)ADT_StringBuffer__New((Object__String)i1);
  sb = (ADT_StringBuffer__StringBuffer)i1;
  i5 = (OOC_INT32)ADT_Dictionary__New();
  importedLibs = (ADT_Dictionary__Dictionary)i5;
  i6 = (OOC_INT32)ADT_ArrayList__New(4);
  importedLibsList = (ADT_ArrayList__ArrayList)i6;
  i = 0;
  i7 = 0<imports_0d;
  if (!i7) goto l26;
  i7 = (OOC_INT32)_c2;
  i8=0;
l7_loop:
  i9 = (OOC_INT32)*(OOC_INT32*)((OOC_INT32)imports+(_check_index(i8, imports_0d, OOC_UINT32, 6981))*4);
  i9 = *(OOC_INT8*)((_check_pointer(i9, 6984))+16);
  _assert((i9==4), 127, 6967);
  i9 = (OOC_INT32)*(OOC_INT32*)((OOC_INT32)imports+(_check_index(i8, imports_0d, OOC_UINT32, 7056))*4);
  i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i9, 7059))+12);
  i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i9, 7066))+56);
  libraryName = (Object__String)i9;
  i10 = i9!=(OOC_INT32)0;
  if (i10) goto l10;
  i10=0u;
  goto l12;
l10:
  i10 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i9, 7123)))), Object__StringDesc_Equals)),Object__StringDesc_Equals)((Object__String)i9, (Object__Object)i2);
  i10 = !i10;
  
l12:
  if (i10) goto l17;
  i9 = (OOC_INT32)*(OOC_INT32*)((OOC_INT32)imports+(_check_index(i8, imports_0d, OOC_UINT32, 7468))*4);
  i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i9, 7471))+12);
  i9 = OOC_SymbolTable__ModuleDesc_NoObjectFile((OOC_SymbolTable__Module)i9);
  i9 = !i9;
  if (!i9) goto l21;
  i9 = (OOC_INT32)*(OOC_INT32*)((OOC_INT32)imports+(_check_index(i8, imports_0d, OOC_UINT32, 7521))*4);
  i10 = (OOC_INT32)*(OOC_INT32*)((OOC_INT32)imports+(_check_index(i8, imports_0d, OOC_UINT32, 7521))*4);
  i9 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i9, 7524)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i10, i3, 1u);
  uri = (URI__URI)i9;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7563)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i1, (Object__Object)i7);
  i9 = (OOC_INT32)URI_Scheme_File__URIDesc_GetPath((URI_Scheme_File__URI)(_type_guard(i9, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i9, 7604)))), &_td_URI_Scheme_File__URIDesc, 7604)));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7587)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i1, (Object__Object)i9);
  goto l21;
l17:
  i10 = ADT_Dictionary__DictionaryDesc_HasKey((ADT_Dictionary__Dictionary)i5, (Object__Object)i9);
  i10 = !i10;
  if (!i10) goto l21;
  ADT_Dictionary__DictionaryDesc_Set((ADT_Dictionary__Dictionary)i5, (Object__Object)i9, (Object__Object)(OOC_INT32)0);
  i9 = (OOC_INT32)*(OOC_INT32*)((OOC_INT32)imports+(_check_index(i8, imports_0d, OOC_UINT32, 7429))*4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 7414)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i6, (Object__Object)i9);
l21:
  i8 = i8+1;
  i = i8;
  i9 = i8<imports_0d;
  if (i9) goto l7_loop;
l26:
  i0 = i0==(OOC_INT32)0;
  if (!i0) goto l29;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 7734)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i4, 17, 1u);
  uri = (URI__URI)i0;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7789)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i1, (Object__Object)((OOC_INT32)_c3));
  i0 = (OOC_INT32)URI_Scheme_File__URIDesc_GetPath((URI_Scheme_File__URI)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7828)))), &_td_URI_Scheme_File__URIDesc, 7828)));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7811)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i1, (Object__Object)i0);
l29:
  i0 = *(OOC_INT32*)((_check_pointer(i6, 7889))+4);
  i = 0;
  i3 = 0<i0;
  if (!i3) goto l41;
  i3 = (OOC_INT32)_c4;
  i4 = (OOC_INT32)_c5;
  i5=0;
l32_loop:
  i7 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i6, 7932));
  i7 = _check_pointer(i7, 7938);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)(i7+(_check_index(i5, i8, OOC_UINT32, 7938))*4);
  i7 = _type_guard(i7, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 7953)))), &_td_OOC_Repository__ModuleDesc, 7953);
  import = (OOC_Repository__Module)i7;
  i8 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 7977)))), OOC_Repository__ModuleDesc_FileExists)),OOC_Repository__ModuleDesc_FileExists)((OOC_Repository__Module)i7, 19);
  if (i8) goto l35;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8323)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i1, (Object__Object)i4);
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i7, 8363))+12);
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i7, 8370))+56);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8349)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i1, (Object__Object)i7);
  goto l36;
l35:
  i7 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 8086)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i7, 19, 1u);
  uri = (URI__URI)i7;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8134)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i1, (Object__Object)i3);
  i7 = (OOC_INT32)URI_Scheme_File__URIDesc_GetPath((URI_Scheme_File__URI)(_type_guard(i7, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 8175)))), &_td_URI_Scheme_File__URIDesc, 8175)));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8158)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i1, (Object__Object)i7);
l36:
  i5 = i5+1;
  i = i5;
  i7 = i5<i0;
  if (i7) goto l32_loop;
l41:
  i0 = (OOC_INT32)OOC_Make_LinkProgramC__GetExternalLibs((void*)(OOC_INT32)imports, imports_0d, (Object__String)i2);
  extLibs = (Object__StringArrayPtr)i0;
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i0, 8582)), 0);
  i2 = i2-1;
  i = i2;
  i3 = i2>=0;
  if (!i3) goto l49;
l44_loop:
  i3 = _check_pointer(i0, 8624);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 8624))*4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8609)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i1, (Object__Object)i3);
  i2 = i2+(-1);
  i = i2;
  i3 = i2>=0;
  if (i3) goto l44_loop;
l49:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8645)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i1, (Object__Object)((OOC_INT32)_c6));
  i0 = (OOC_INT32)OOC_Config_CCompiler__libs;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8687))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8665)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i1, (Object__Object)i0);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8710)))), ADT_StringBuffer__StringBufferDesc_ToString)),ADT_StringBuffer__StringBufferDesc_ToString)((ADT_StringBuffer__StringBuffer)i1);
  Out__Object((Object__Object)i0);
  Out__Ln();
  i0 = OS_ProcessManagement__system((Object__String)i0);
  return (i0==0);
  ;
}

void OOC_OOC_Make_LinkProgramC_init(void) {
  register OOC_INT32 i0;
  _c0 = Object__NewLatin1Region(" -l", 4, 0, 3);
  _c1 = Object__NewLatin1Region(" -framework ", 13, 0, 12);
  _c2 = Object__NewLatin1Char(32u);
  _c3 = Object__NewLatin1Char(32u);
  _c4 = Object__NewLatin1Char(32u);
  _c5 = Object__NewLatin1Region(" -l", 4, 0, 3);
  _c6 = Object__NewLatin1Char(32u);
  _c7 = Object__NewLatin1Char(32u);

  i0 = (OOC_INT32)Object__emptyString;
  OOC_Make_LinkProgramC__empty = (Object__String)i0;
  OOC_Make_LinkProgramC__space = (Object__String)((OOC_INT32)_c7);
  return;
  ;
}

/* --- */
