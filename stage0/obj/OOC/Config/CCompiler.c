#include <OOC/Config/CCompiler.d>
#include <__oo2c.h>
#include <setjmp.h>

OOC_CHAR8 OOC_Config_CCompiler__HaveLibtool(void) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)OOC_Config_CCompiler__libtool;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 1378))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 1378))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1393)))), &_td_Config__StringVarDesc, 1393)), 1403));
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 1393)))), &_td_Config__StringVarDesc, 1393)), 1403));
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1410)))), Object__StringDesc_Equals)),Object__StringDesc_Equals)((Object__String)i1, (Object__Object)((OOC_INT32)_c0));
  return (!i0);
  ;
}

OOC_CHAR8 OOC_Config_CCompiler__SkipCallCC(void) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)OOC_Config_CCompiler__cc;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 1601))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1616)))), &_td_Config__StringVarDesc, 1616)), 1626));
  i0 = *(OOC_INT32*)(_check_pointer(i0, 1633));
  return (i0==0);
  ;
}

static ADT_StringBuffer__StringBuffer OOC_Config_CCompiler__SetCommand(Object__String mode) {
  register OOC_INT32 i0,i1,i2;
  ADT_StringBuffer__StringBuffer sb;

  i0 = (OOC_INT32)ADT_StringBuffer__New((Object__String)((OOC_INT32)_c1));
  sb = (ADT_StringBuffer__StringBuffer)i0;
  i1 = (OOC_INT32)mode;
  i2 = *(OOC_INT32*)(_check_pointer(i1, 1822));
  i2 = i2!=0;
  if (i2) goto l3;
  i2=0u;
  goto l5;
l3:
  i2 = OOC_Config_CCompiler__HaveLibtool();
  
l5:
  if (!i2) goto l10;
  i2 = (OOC_INT32)OOC_Config_CCompiler__libtool;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 1879))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1864)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1896)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c2));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1936)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1959)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c3));
  i1 = OOC_Logger__silence;
  if (!i1) goto l10;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2012)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c4));
l10:
  i1 = (OOC_INT32)OOC_Config_CCompiler__cc;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 2069))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2059)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2084)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c5));
  return (ADT_StringBuffer__StringBuffer)i0;
  ;
}

Object__String OOC_Config_CCompiler__CompileFileCmd(URI__URI in, URI__URI out, OOC_CHAR8 forLibrary) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  ADT_StringBuffer__StringBuffer sb;
  URI_Scheme_File__URI f;
  Object__StringArrayPtr include;
  OOC_INT32 i;
  auto URI_Scheme_File__URI OOC_Config_CCompiler__CompileFileCmd_GetURIofRT(void);
    
    URI_Scheme_File__URI OOC_Config_CCompiler__CompileFileCmd_GetURIofRT(void) {
      register OOC_INT32 i0;
      OOC_Repository__Module m;
      URI__HierarchicalURI uri;
      URI_Scheme_File__URI f;

      i0 = (OOC_INT32)OOC_Config__repositories;
      i0 = (OOC_INT32)OOC_Config_Repositories__SectionDesc_GetModule((OOC_Config_Repositories__Section)i0, (OOC_CHAR8*)"RT0", 4);
      m = (OOC_Repository__Module)i0;
      _assert((i0!=(OOC_INT32)0), 127, 2527);
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2610)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i0, 0, 1u);
      uri = (URI__HierarchicalURI)i0;
      i0 = _type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2675)))), &_td_URI_Scheme_File__URIDesc, 2675);
      f = (URI_Scheme_File__URI)i0;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2688)))), URI_Scheme_Hierarchical__GenericDesc_StripSegments)),URI_Scheme_Hierarchical__GenericDesc_StripSegments)((URI_Scheme_Hierarchical__Generic)i0, 1);
      return (URI_Scheme_File__URI)i0;
      ;
    }


  i0 = forLibrary;
  if (i0) goto l3;
  i0 = (OOC_INT32)OOC_Config_CCompiler__SetCommand((Object__String)((OOC_INT32)_c6));
  sb = (ADT_StringBuffer__StringBuffer)i0;
  
  goto l4;
l3:
  i0 = (OOC_INT32)OOC_Config_CCompiler__SetCommand((Object__String)((OOC_INT32)_c7));
  sb = (ADT_StringBuffer__StringBuffer)i0;
  
l4:
  i1 = (OOC_INT32)OOC_Config_CCompiler__cflags;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 2880))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2866)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2895)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c8));
  i1 = (OOC_INT32)OOC_Config_CCompiler__cppflags;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 2931))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2915)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i1);
  i0 = (OOC_INT32)OOC_Config_CCompiler__CompileFileCmd_GetURIofRT();
  f = (URI_Scheme_File__URI)i0;
  i1 = (OOC_INT32)sb;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3347)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i1, (Object__Object)((OOC_INT32)_c9));
  i0 = (OOC_INT32)URI_Scheme_File__URIDesc_GetPath((URI_Scheme_File__URI)i0);
  i0 = (OOC_INT32)OS_Path__QuoteForShell((Object__String)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3369)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i1, (Object__Object)i0);
  i0 = (OOC_INT32)OOC_Config__repositories;
  i0 = (OOC_INT32)OOC_Config_Repositories__SectionDesc_GetIncludePaths((OOC_Config_Repositories__Section)i0);
  include = (Object__StringArrayPtr)i0;
  i = 0;
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i0, 3501)), 0);
  i3 = 0<i2;
  if (!i3) goto l12;
  i3 = (OOC_INT32)_c10;
  i4=0;
l7_loop:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3517)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i1, (Object__Object)i3);
  i5 = _check_pointer(i0, 3575);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 3575))*4);
  i5 = (OOC_INT32)OS_Path__QuoteForShell((Object__String)i5);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3541)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i1, (Object__Object)i5);
  i4 = i4+1;
  i = i4;
  i5 = i4<i2;
  if (i5) goto l7_loop;
l12:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3602)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i1, (Object__Object)((OOC_INT32)_c11));
  i0 = (OOC_INT32)in;
  i0 = (OOC_INT32)URI_Scheme_File__URIDesc_GetPath((URI_Scheme_File__URI)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3660)))), &_td_URI_Scheme_File__URIDesc, 3660)));
  i0 = (OOC_INT32)OS_Path__QuoteForShell((Object__String)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3625)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i1, (Object__Object)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3684)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i1, (Object__Object)((OOC_INT32)_c12));
  i0 = (OOC_INT32)out;
  i0 = (OOC_INT32)URI_Scheme_File__URIDesc_GetPath((URI_Scheme_File__URI)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3743)))), &_td_URI_Scheme_File__URIDesc, 3743)));
  i0 = (OOC_INT32)OS_Path__QuoteForShell((Object__String)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3707)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i1, (Object__Object)i0);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3774)))), ADT_StringBuffer__StringBufferDesc_ToString)),ADT_StringBuffer__StringBufferDesc_ToString)((ADT_StringBuffer__StringBuffer)i1);
  return (Object__String)i0;
  ;
}

Object__String OOC_Config_CCompiler__LinkProgramCmd(URI__URI execFile, OOC_Package__Library forLibrary) {
  register OOC_INT32 i0,i1,i2;
  ADT_StringBuffer__StringBuffer sb;

  i0 = (OOC_INT32)OOC_Config_CCompiler__SetCommand((Object__String)((OOC_INT32)_c13));
  sb = (ADT_StringBuffer__StringBuffer)i0;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4006)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c14));
  i1 = (OOC_INT32)execFile;
  i1 = (OOC_INT32)URI_Scheme_File__URIDesc_GetPath((URI_Scheme_File__URI)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4069)))), &_td_URI_Scheme_File__URIDesc, 4069)));
  i1 = (OOC_INT32)OS_Path__QuoteForShell((Object__String)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4028)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i1);
  i1 = (OOC_INT32)forLibrary;
  i2 = i1!=(OOC_INT32)0;
  if (i2) goto l3;
  i2=0u;
  goto l5;
l3:
  i2 = OOC_Config_CCompiler__HaveLibtool();
  
l5:
  if (!i2) goto l7;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4142)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c15));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4202))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4178)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1)),ADT_StringBuffer__StringBufferDesc_AppendLatin1)((ADT_StringBuffer__StringBuffer)i0, (void*)((_check_pointer(i1, 4210))+12), 32);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4227)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c16));
  i1 = (OOC_INT32)OOC_Config_CCompiler__libdir;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4289))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4289))+8);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 4295)))), Config__VariableDesc_ToString)),Config__VariableDesc_ToString)((Config__Variable)i1);
  i1 = (OOC_INT32)OS_Path__QuoteForShell((Object__String)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4256)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i1);
l7:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4325)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c17));
  i1 = (OOC_INT32)OOC_Config_CCompiler__ldflags;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4360))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4345)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i1);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4382)))), ADT_StringBuffer__StringBufferDesc_ToString)),ADT_StringBuffer__StringBufferDesc_ToString)((ADT_StringBuffer__StringBuffer)i0);
  return (Object__String)i0;
  ;
}

Object__String OOC_Config_CCompiler__InstallDirectoryCmd(Object__String path) {
  register OOC_INT32 i0,i1;
  ADT_StringBuffer__StringBuffer sb;

  i0 = (OOC_INT32)OOC_Config_CCompiler__install;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4555))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4555))+8);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4561)))), Config__VariableDesc_ToString)),Config__VariableDesc_ToString)((Config__Variable)i0);
  i0 = (OOC_INT32)ADT_StringBuffer__New((Object__String)i0);
  sb = (ADT_StringBuffer__StringBuffer)i0;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4581)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c18));
  i1 = (OOC_INT32)path;
  i1 = (OOC_INT32)OS_Path__QuoteForShell((Object__String)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4604)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i1);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4652)))), ADT_StringBuffer__StringBufferDesc_ToString)),ADT_StringBuffer__StringBufferDesc_ToString)((ADT_StringBuffer__StringBuffer)i0);
  return (Object__String)i0;
  ;
}

Object__String OOC_Config_CCompiler__InstallProgramCmd(URI__URI file, OOC_CHAR8 asLibrary) {
  register OOC_INT32 i0,i1,i2;
  ADT_StringBuffer__StringBuffer sb;

  i0 = (OOC_INT32)ADT_StringBuffer__New((Object__String)((OOC_INT32)_c19));
  sb = (ADT_StringBuffer__StringBuffer)i0;
  i1 = OOC_Config_CCompiler__HaveLibtool();
  if (!i1) goto l3;
  i1 = (OOC_INT32)OOC_Config_CCompiler__libtool;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4896))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4881)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4913)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c20));
l3:
  i1 = (OOC_INT32)OOC_Config_CCompiler__installProgram;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4995))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4973)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5010)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c21));
  i1 = (OOC_INT32)file;
  i1 = (OOC_INT32)URI_Scheme_File__URIDesc_GetPath((URI_Scheme_File__URI)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5067)))), &_td_URI_Scheme_File__URIDesc, 5067)));
  i1 = (OOC_INT32)OS_Path__QuoteForShell((Object__String)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5030)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5091)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c22));
  i1 = asLibrary;
  if (i1) goto l6;
  i1 = (OOC_INT32)OOC_Config_CCompiler__bindir;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 5239))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 5239))+8);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 5245)))), Config__VariableDesc_ToString)),Config__VariableDesc_ToString)((Config__Variable)i1);
  i1 = (OOC_INT32)OS_Path__QuoteForShell((Object__String)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5206)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i1);
  goto l7;
l6:
  i1 = (OOC_INT32)OOC_Config_CCompiler__libdir;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 5168))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 5168))+8);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 5174)))), Config__VariableDesc_ToString)),Config__VariableDesc_ToString)((Config__Variable)i1);
  i1 = (OOC_INT32)OS_Path__QuoteForShell((Object__String)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5135)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i1);
l7:
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5282)))), ADT_StringBuffer__StringBufferDesc_ToString)),ADT_StringBuffer__StringBufferDesc_ToString)((ADT_StringBuffer__StringBuffer)i0);
  return (Object__String)i0;
  ;
}

Object__String OOC_Config_CCompiler__UninstallProgramCmd(Object__String path, OOC_CHAR8 asLibrary) {
  register OOC_INT32 i0,i1;
  ADT_StringBuffer__StringBuffer sb;

  i0 = (OOC_INT32)ADT_StringBuffer__New((Object__String)((OOC_INT32)_c23));
  sb = (ADT_StringBuffer__StringBuffer)i0;
  i1 = OOC_Config_CCompiler__HaveLibtool();
  if (!i1) goto l4;
  i1 = (OOC_INT32)OOC_Config_CCompiler__libtool;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 5525))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5510)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5542)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c24));
l4:
  i1 = (OOC_INT32)OOC_Config_CCompiler__uninstall;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 5621))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5604)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5636)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c25));
  i1 = (OOC_INT32)path;
  i1 = (OOC_INT32)OS_Path__QuoteForShell((Object__String)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5656)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i1);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5704)))), ADT_StringBuffer__StringBufferDesc_ToString)),ADT_StringBuffer__StringBufferDesc_ToString)((ADT_StringBuffer__StringBuffer)i0);
  return (Object__String)i0;
  ;
}

void OOC_Config_CCompiler__RegisterConfig(void) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)Config__NewStringVar((Object__String8)((OOC_INT32)_c26));
  i0 = (OOC_INT32)OOC_Config__AddOption((Object__String)((OOC_INT32)_c27), (Config__Variable)i0);
  OOC_Config_CCompiler__cc = (Config_Section_Options__Option)i0;
  i0 = (OOC_INT32)Config__NewStringVar((Object__String8)((OOC_INT32)_c28));
  i0 = (OOC_INT32)OOC_Config__AddOption((Object__String)((OOC_INT32)_c29), (Config__Variable)i0);
  OOC_Config_CCompiler__cppflags = (Config_Section_Options__Option)i0;
  i0 = (OOC_INT32)Config__NewStringVar((Object__String8)((OOC_INT32)_c30));
  i0 = (OOC_INT32)OOC_Config__AddOption((Object__String)((OOC_INT32)_c31), (Config__Variable)i0);
  OOC_Config_CCompiler__cflags = (Config_Section_Options__Option)i0;
  i0 = (OOC_INT32)Config__NewStringVar((Object__String8)((OOC_INT32)_c32));
  i0 = (OOC_INT32)OOC_Config__AddOption((Object__String)((OOC_INT32)_c33), (Config__Variable)i0);
  OOC_Config_CCompiler__ldflags = (Config_Section_Options__Option)i0;
  i0 = (OOC_INT32)Config__NewStringVar((Object__String8)((OOC_INT32)_c34));
  i0 = (OOC_INT32)OOC_Config__AddOption((Object__String)((OOC_INT32)_c35), (Config__Variable)i0);
  OOC_Config_CCompiler__libs = (Config_Section_Options__Option)i0;
  OOC_Config__AddCmdLine((OOC_CHAR8*)"--cc", 5, (OOC_CHAR8*)"<options><set name=\047cc\047>$1</set></options>", 43);
  OOC_Config__AddCmdLine((OOC_CHAR8*)"--cppflags", 11, (OOC_CHAR8*)"<options><set name=\047cppflags\047>$1</set></options>", 49);
  OOC_Config__AddCmdLine((OOC_CHAR8*)"--cflags", 9, (OOC_CHAR8*)"<options><set name=\047cflags\047>$1</set></options>", 47);
  OOC_Config__AddCmdLine((OOC_CHAR8*)"--ldflags", 10, (OOC_CHAR8*)"<options><set name=\047ldflags\047>$1</set></options>", 48);
  OOC_Config__AddCmdLine((OOC_CHAR8*)"--libs", 7, (OOC_CHAR8*)"<options><set name=\047libs\047>$1</set></options>", 45);
  i0 = (OOC_INT32)Config__NewStringVar((Object__String8)((OOC_INT32)_c36));
  i0 = (OOC_INT32)OOC_Config__AddOption((Object__String)((OOC_INT32)_c37), (Config__Variable)i0);
  OOC_Config_CCompiler__libtool = (Config_Section_Options__Option)i0;
  i0 = (OOC_INT32)Config__NewStringVar((Object__String8)((OOC_INT32)_c38));
  i0 = (OOC_INT32)OOC_Config__AddOption((Object__String)((OOC_INT32)_c39), (Config__Variable)i0);
  OOC_Config_CCompiler__libdir = (Config_Section_Options__Option)i0;
  OOC_Config__AddCmdLine((OOC_CHAR8*)"--libtool", 10, (OOC_CHAR8*)"<options><set name=\047libtool\047>$1</set></options>", 48);
  OOC_Config__AddCmdLine((OOC_CHAR8*)"--libdir", 9, (OOC_CHAR8*)"<options><set name=\047libdir\047>$1</set></options>", 47);
  i0 = (OOC_INT32)Config__NewStringVar((Object__String8)((OOC_INT32)_c40));
  i0 = (OOC_INT32)OOC_Config__AddOption((Object__String)((OOC_INT32)_c41), (Config__Variable)i0);
  OOC_Config_CCompiler__install = (Config_Section_Options__Option)i0;
  i0 = (OOC_INT32)Config__NewStringVar((Object__String8)((OOC_INT32)_c42));
  i0 = (OOC_INT32)OOC_Config__AddOption((Object__String)((OOC_INT32)_c43), (Config__Variable)i0);
  OOC_Config_CCompiler__installProgram = (Config_Section_Options__Option)i0;
  i0 = (OOC_INT32)Config__NewStringVar((Object__String8)((OOC_INT32)_c44));
  i0 = (OOC_INT32)OOC_Config__AddOption((Object__String)((OOC_INT32)_c45), (Config__Variable)i0);
  OOC_Config_CCompiler__installData = (Config_Section_Options__Option)i0;
  i0 = (OOC_INT32)Config__NewStringVar((Object__String8)((OOC_INT32)_c46));
  i0 = (OOC_INT32)OOC_Config__AddOption((Object__String)((OOC_INT32)_c47), (Config__Variable)i0);
  OOC_Config_CCompiler__uninstall = (Config_Section_Options__Option)i0;
  i0 = (OOC_INT32)Config__NewStringVar((Object__String8)((OOC_INT32)_c48));
  i0 = (OOC_INT32)OOC_Config__AddOption((Object__String)((OOC_INT32)_c49), (Config__Variable)i0);
  OOC_Config_CCompiler__bindir = (Config_Section_Options__Option)i0;
  i0 = (OOC_INT32)Config__NewStringVar((Object__String8)((OOC_INT32)_c50));
  i0 = (OOC_INT32)OOC_Config__AddOption((Object__String)((OOC_INT32)_c51), (Config__Variable)i0);
  OOC_Config_CCompiler__oocdir = (Config_Section_Options__Option)i0;
  OOC_Config__AddCmdLine((OOC_CHAR8*)"--install", 10, (OOC_CHAR8*)"<options><set name=\047install\047>$1</set></options>", 48);
  OOC_Config__AddCmdLine((OOC_CHAR8*)"--install-program", 18, (OOC_CHAR8*)"<options><set name=\047installProgram\047>$1</set></options>", 55);
  OOC_Config__AddCmdLine((OOC_CHAR8*)"--install-data", 15, (OOC_CHAR8*)"<options><set name=\047installData\047>$1</set></options>", 52);
  OOC_Config__AddCmdLine((OOC_CHAR8*)"--uninstall", 12, (OOC_CHAR8*)"<options><set name=\047uninstall\047>$1</set></options>", 50);
  OOC_Config__AddCmdLine((OOC_CHAR8*)"--bindir", 9, (OOC_CHAR8*)"<options><set name=\047bindir\047>$1</set></options>", 47);
  OOC_Config__AddCmdLine((OOC_CHAR8*)"--oocdir", 9, (OOC_CHAR8*)"<options><set name=\047oocdir\047>$1</set></options>", 47);
  return;
  ;
}

void OOC_OOC_Config_CCompiler_init(void) {
  _c0 = Object__NewLatin1Region((OOC_CHAR8*)"no", 3, 0, 2);
  _c1 = Object__NewLatin1Region((OOC_CHAR8*)"", 1, 0, 0);
  _c2 = Object__NewLatin1Region((OOC_CHAR8*)" --tag=CXX --mode=", 19, 0, 18);
  _c3 = Object__NewLatin1Char(32u);
  _c4 = Object__NewLatin1Region((OOC_CHAR8*)"--quiet ", 9, 0, 8);
  _c5 = Object__NewLatin1Char(32u);
  _c6 = Object__NewLatin1Region((OOC_CHAR8*)"", 1, 0, 0);
  _c7 = Object__NewLatin1Region((OOC_CHAR8*)"compile", 8, 0, 7);
  _c8 = Object__NewLatin1Char(32u);
  _c9 = Object__NewLatin1Region((OOC_CHAR8*)" -I", 4, 0, 3);
  _c10 = Object__NewLatin1Region((OOC_CHAR8*)" -I", 4, 0, 3);
  _c11 = Object__NewLatin1Region((OOC_CHAR8*)" -c ", 5, 0, 4);
  _c12 = Object__NewLatin1Region((OOC_CHAR8*)" -o ", 5, 0, 4);
  _c13 = Object__NewLatin1Region((OOC_CHAR8*)"link", 5, 0, 4);
  _c14 = Object__NewLatin1Region((OOC_CHAR8*)"-o ", 4, 0, 3);
  _c15 = Object__NewLatin1Region((OOC_CHAR8*)" -version-info ", 16, 0, 15);
  _c16 = Object__NewLatin1Region((OOC_CHAR8*)" -rpath ", 9, 0, 8);
  _c17 = Object__NewLatin1Char(32u);
  _c18 = Object__NewLatin1Region((OOC_CHAR8*)" -d ", 5, 0, 4);
  _c19 = Object__NewLatin1Region((OOC_CHAR8*)"", 1, 0, 0);
  _c20 = Object__NewLatin1Region((OOC_CHAR8*)" --tag=CXX --mode=install ", 27, 0, 26);
  _c21 = Object__NewLatin1Char(32u);
  _c22 = Object__NewLatin1Char(32u);
  _c23 = Object__NewLatin1Region((OOC_CHAR8*)"", 1, 0, 0);
  _c24 = Object__NewLatin1Region((OOC_CHAR8*)" --tag=CXX --mode=uninstall ", 29, 0, 28);
  _c25 = Object__NewLatin1Char(32u);
  _c26 = Object__NewLatin1Region((OOC_CHAR8*)"gcc", 4, 0, 3);
  _c27 = Object__NewLatin1Region((OOC_CHAR8*)"cc", 3, 0, 2);
  _c28 = Object__NewLatin1Region((OOC_CHAR8*)"", 1, 0, 0);
  _c29 = Object__NewLatin1Region((OOC_CHAR8*)"cppflags", 9, 0, 8);
  _c30 = Object__NewLatin1Region((OOC_CHAR8*)"-O2 -g", 7, 0, 6);
  _c31 = Object__NewLatin1Region((OOC_CHAR8*)"cflags", 7, 0, 6);
  _c32 = Object__NewLatin1Region((OOC_CHAR8*)"", 1, 0, 0);
  _c33 = Object__NewLatin1Region((OOC_CHAR8*)"ldflags", 8, 0, 7);
  _c34 = Object__NewLatin1Region((OOC_CHAR8*)"-lgc", 5, 0, 4);
  _c35 = Object__NewLatin1Region((OOC_CHAR8*)"libs", 5, 0, 4);
  _c36 = Object__NewLatin1Region((OOC_CHAR8*)"libtool", 8, 0, 7);
  _c37 = Object__NewLatin1Region((OOC_CHAR8*)"libtool", 8, 0, 7);
  _c38 = Object__NewLatin1Region((OOC_CHAR8*)"libdir", 7, 0, 6);
  _c39 = Object__NewLatin1Region((OOC_CHAR8*)"libdir", 7, 0, 6);
  _c40 = Object__NewLatin1Region((OOC_CHAR8*)"install -c", 11, 0, 10);
  _c41 = Object__NewLatin1Region((OOC_CHAR8*)"install", 8, 0, 7);
  _c42 = Object__NewLatin1Region((OOC_CHAR8*)"install -c", 11, 0, 10);
  _c43 = Object__NewLatin1Region((OOC_CHAR8*)"installProgram", 15, 0, 14);
  _c44 = Object__NewLatin1Region((OOC_CHAR8*)"install -c -m 644", 18, 0, 17);
  _c45 = Object__NewLatin1Region((OOC_CHAR8*)"installData", 12, 0, 11);
  _c46 = Object__NewLatin1Region((OOC_CHAR8*)"rm -f", 6, 0, 5);
  _c47 = Object__NewLatin1Region((OOC_CHAR8*)"uninstall", 10, 0, 9);
  _c48 = Object__NewLatin1Region((OOC_CHAR8*)"bindir", 7, 0, 6);
  _c49 = Object__NewLatin1Region((OOC_CHAR8*)"bindir", 7, 0, 6);
  _c50 = Object__NewLatin1Region((OOC_CHAR8*)"oocdir", 7, 0, 6);
  _c51 = Object__NewLatin1Region((OOC_CHAR8*)"oocdir", 7, 0, 6);

  return;
  ;
}

void OOC_OOC_Config_CCompiler_destroy(void) {
}

/* --- */
