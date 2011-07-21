#include <oo2c.d>
#include <__oo2c.h>
#include <setjmp.h>

static void oo2c__NewConfig(void) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)Config__NewIntegerVar(0);
  i0 = (OOC_INT32)OOC_Config__AddOption((Object__String)((OOC_INT32)_c0), (Config__Variable)i0);
  oo2c__command = (Config_Section_Options__Option)i0;
  i0 = (OOC_INT32)Config__NewBooleanVar(0u);
  i0 = (OOC_INT32)OOC_Config__AddOption((Object__String)((OOC_INT32)_c1), (Config__Variable)i0);
  oo2c__forceUpdate = (Config_Section_Options__Option)i0;
  i0 = (OOC_INT32)Config__NewStringVar((Object__String8)((OOC_INT32)_c2));
  i0 = (OOC_INT32)OOC_Config__AddOption((Object__String)((OOC_INT32)_c3), (Config__Variable)i0);
  oo2c__listUses = (Config_Section_Options__Option)i0;
  i0 = (OOC_INT32)Config__NewBooleanVar(0u);
  i0 = (OOC_INT32)OOC_Config__AddOption((Object__String)((OOC_INT32)_c4), (Config__Variable)i0);
  oo2c__useStderr = (Config_Section_Options__Option)i0;
  i0 = (OOC_INT32)Config__NewBooleanVar(0u);
  i0 = (OOC_INT32)OOC_Config__AddOption((Object__String)((OOC_INT32)_c5), (Config__Variable)i0);
  oo2c__writeStats = (Config_Section_Options__Option)i0;
  i0 = (OOC_INT32)Config__NewBooleanVar(0u);
  i0 = (OOC_INT32)OOC_Config__AddOption((Object__String)((OOC_INT32)_c6), (Config__Variable)i0);
  oo2c__verbose = (Config_Section_Options__Option)i0;
  i0 = (OOC_INT32)Config__NewStringVar((Object__String8)((OOC_INT32)_c7));
  i0 = (OOC_INT32)OOC_Config__AddOption((Object__String)((OOC_INT32)_c8), (Config__Variable)i0);
  oo2c__errorStyle = (Config_Section_Options__Option)i0;
  i0 = (OOC_INT32)Config__NewBooleanVar(0u);
  i0 = (OOC_INT32)OOC_Config__AddOption((Object__String)((OOC_INT32)_c9), (Config__Variable)i0);
  oo2c__showHelp = (Config_Section_Options__Option)i0;
  i0 = (OOC_INT32)Config__NewBooleanVar(0u);
  i0 = (OOC_INT32)OOC_Config__AddOption((Object__String)((OOC_INT32)_c10), (Config__Variable)i0);
  oo2c__showVersion = (Config_Section_Options__Option)i0;
  OOC_Config__AddRepositoryListEnv();
  OOC_Config__AddCmdLine("--repository,-r", 16, "<repositories><file-system>$1</file-system></repositories>", 59);
  OOC_Config__AddCmdLine("--make,-M", 10, "<options><set name=\047command\047>1</set></options>", 47);
  OOC_Config__AddCmdLine("--build-package", 16, "<options><set name=\047command\047>2</set></options>", 47);
  OOC_Config__AddCmdLine("--install-package", 18, "<options><set name=\047command\047>3</set></options>", 47);
  OOC_Config__AddCmdLine("--uninstall-package", 20, "<options><set name=\047command\047>4</set></options>", 47);
  OOC_Config__AddCmdLine("--update-repository", 20, "<options><set name=\047command\047>5</set></options>", 47);
  OOC_Config__AddCmdLine("--get-option", 13, "<options><set name=\047command\047>6</set></options>", 47);
  OOC_Config__AddCmdLine("--build-pkg-doc", 16, "<options><set name=\047command\047>7</set></options>", 47);
  OOC_Config__AddCmdLine("--package-installed", 20, "<options><set name=\047command\047>8</set></options>", 47);
  OOC_Config__AddCmdLine("--list-packages", 16, "<options><set name=\047command\047>9</set></options>", 47);
  OOC_Config__AddCmdLine("-h,--help", 10, "<options><set name=\047showHelp\047>TRUE</set></options>", 51);
  OOC_Config__AddCmdLine("--version", 10, "<options><set name=\047showVersion\047>TRUE</set></options>", 54);
  OOC_Config__AddCmdLine("--no-rtc", 9, "<pragmas>  <set name=\047Assertions\047>FALSE</set>  <set name=\047IndexCheck\047>FALSE</set>  <set name=\047DerefCheck\047>FALSE</set>  <set name=\047OverflowCheck\047>FALSE</set>  <set name=\047CaseSelectCheck\047>FALSE</set>  <set name=\047FunctResult\047>FALSE</set>  <set name=\047TypeGuard\047>FALSE</set></pragmas>", 280);
  OOC_Config__AddCmdLine("--verbose,-v", 13, "<options><set name=\047verbose\047>TRUE</set></options>", 50);
  OOC_Config__AddCmdLine("--warnings,-w", 14, "", 1);
  OOC_Config__AddCmdLine("-A,--all", 9, "<options><set name=\047forceUpdate\047>TRUE</set></options>", 54);
  OOC_Config__AddCmdLine("--uses", 7, "<options>  <set name=\047listUses\047>$1</set>  <set name=\047command\047>1</set></options>", 80);
  OOC_Config__AddCmdLine("--error-style", 14, "<options><set name=\047errorStyle\047>$1</set></options>", 51);
  OOC_Config__AddCmdLine("--use-stderr", 13, "<options><set name=\047useStderr\047>TRUE</set></options>", 52);
  OOC_Config__AddCmdLine("--stats", 8, "<options><set name=\047writeStats\047>TRUE</set></options>", 53);
  OOC_Config_CCompiler__RegisterConfig();
  return;
  ;
}

static OOC_Repository__Module oo2c__GetModule(Object__String moduleName) {
  register OOC_INT32 i0,i1,i2;
  Object__String8 str;
  Object__CharsLatin1 chars;
  OOC_Repository__Module m;

  i0 = (OOC_INT32)moduleName;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5755)))), Object__StringDesc_ToString8)),Object__StringDesc_ToString8)((Object__String)i0, 63u);
  str = (Object__String8)i0;
  i0 = (OOC_INT32)Object__String8Desc_CharsLatin1((Object__String8)i0);
  chars = (Object__CharsLatin1)i0;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 5848)), 0);
  i2 = (OOC_INT32)OOC_Config__repositories;
  i1 = (OOC_INT32)OOC_Config_Repositories__SectionDesc_GetModule((OOC_Config_Repositories__Section)i2, (void*)(_check_pointer(i0, 5848)), i1);
  m = (OOC_Repository__Module)i1;
  i2 = i1==(OOC_INT32)0;
  if (!i2) goto l4;
  Err__String("Error: Cannot locate module ", 29);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i0, 5948)), 0);
  Err__String((void*)(_check_pointer(i0, 5948)), i2);
  Err__Ln();
  _halt(1);
l4:
  return (OOC_Repository__Module)i1;
  ;
}

static OOC_CHAR8 oo2c__BuildPackage(OOC_Package__Package pkg, OOC_Repository__Repository rep, OOC_CHAR8 install) {
  register OOC_INT32 i0,i1,i2;
  OOC_CHAR8 installObjects;
  OOC_CHAR8 ok;
  OOC_INT32 i;
  OOC_Package__Library lib;
  OOC_Repository__Module module;
  OOC_Package__Executable exec;
  OOC_Package__FileSet normSet;
  auto OOC_CHAR8 oo2c__BuildPackage_InstallDirectory(Object__String prefix, Object__String path);
  auto OOC_CHAR8 oo2c__BuildPackage_InstallLibrary(OOC_Repository__Module module, OOC_Make__Rules makeRules);
  auto OOC_CHAR8 oo2c__BuildPackage_InstallExecutable(OOC_Repository__Module module);
  auto OOC_CHAR8 oo2c__BuildPackage_InstallFiles(OOC_Package__FileData list);
  auto OOC_CHAR8 oo2c__BuildPackage_BuildDocs(OOC_Repository__Module module, OOC_Make__Rules makeRules, OOC_CHAR8 install);
    
    OOC_CHAR8 oo2c__BuildPackage_InstallDirectory(Object__String prefix, Object__String path) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)prefix;
      i1 = *(OOC_INT32*)(_check_pointer(i0, 6448));
      i1 = i1!=0;
      if (!i1) goto l3;
      i1 = (OOC_INT32)path;
      path = (Object__String)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)i0,(void*)((OOC_INT32)_c11))),(void*)i1));
l3:
      i0 = (OOC_INT32)path;
      i1 = OS_Files__Exists((Object__String)i0);
      if (i1) goto l6;
      i0 = (OOC_INT32)OOC_Config_CCompiler__InstallDirectoryCmd((Object__String)i0);
      OOC_Logger__ShellCommand((Object__String)i0);
      i0 = OS_ProcessManagement__system((Object__String)i0);
      return (i0==0);
      goto l7;
l6:
      return 1u;
l7:
      _failed_function(6346); return 0;
      ;
    }

    
    OOC_CHAR8 oo2c__BuildPackage_InstallLibrary(OOC_Repository__Module module, OOC_Make__Rules makeRules) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
      OOC_CHAR8 installObjects;
      OOC_INT32 i;
      OOC_Repository__Module m;

      i0 = OOC_Config_CCompiler__HaveLibtool();
      installObjects = (!i0);
      i1 = (OOC_INT32)makeRules;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 7650))+16);
      i = 0;
      i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 7658)), 0);
      i3 = 0<i2;
      if (!i3) goto l18;
      i3 = (OOC_INT32)module;
      i4=0;
l3_loop:
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 7688))+16);
      i5 = _check_pointer(i5, 7696);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 7696))*4);
      m = (OOC_Repository__Module)i5;
      i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 7731));
      i7 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 7715));
      i6 = i7==i6;
      if (!i6) goto l12;
      if ((!i0)) goto l7;
      i6=0u;
      goto l9;
l7:
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 7777))+12);
      i6 = OOC_SymbolTable__ModuleDesc_NoObjectFile((OOC_SymbolTable__Module)i6);
      i6 = !i6;
      
l9:
      if (!i6) goto l11;
      i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 7853));
      i7 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 7853));
      i6 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 7860)))), OOC_Repository__RepositoryDesc_GetLocalPath)),OOC_Repository__RepositoryDesc_GetLocalPath)((OOC_Repository__Repository)i7, (OOC_Repository__Module)i5, 7);
      i6 = (OOC_INT32)OOC_Package__NewFile((Object__String)i6, (Object__String)0);
      i7 = (OOC_INT32)pkg;
      i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i7, 7820))+24);
      OOC_Package__FileSetDesc_Append((OOC_Package__FileSet)i7, (OOC_Package__FileData)i6);
l11:
      i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 7976));
      i7 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 7976));
      i6 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 7983)))), OOC_Repository__RepositoryDesc_GetLocalPath)),OOC_Repository__RepositoryDesc_GetLocalPath)((OOC_Repository__Repository)i7, (OOC_Repository__Module)i5, 1);
      i6 = (OOC_INT32)OOC_Package__NewFile((Object__String)i6, (Object__String)0);
      i7 = (OOC_INT32)pkg;
      i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i7, 7943))+24);
      OOC_Package__FileSetDesc_Append((OOC_Package__FileSet)i7, (OOC_Package__FileData)i6);
      i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 8073));
      i7 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 8073));
      i6 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 8080)))), OOC_Repository__RepositoryDesc_GetLocalPath)),OOC_Repository__RepositoryDesc_GetLocalPath)((OOC_Repository__Repository)i7, (OOC_Repository__Module)i5, 20);
      i6 = (OOC_INT32)OOC_Package__NewFile((Object__String)i6, (Object__String)0);
      i7 = (OOC_INT32)pkg;
      i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i7, 8040))+24);
      OOC_Package__FileSetDesc_Append((OOC_Package__FileSet)i7, (OOC_Package__FileData)i6);
      i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 8173));
      i7 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 8173));
      i5 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 8180)))), OOC_Repository__RepositoryDesc_GetLocalPath)),OOC_Repository__RepositoryDesc_GetLocalPath)((OOC_Repository__Repository)i7, (OOC_Repository__Module)i5, 13);
      i5 = (OOC_INT32)OOC_Package__NewFile((Object__String)i5, (Object__String)0);
      i6 = (OOC_INT32)pkg;
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 8140))+24);
      OOC_Package__FileSetDesc_Append((OOC_Package__FileSet)i6, (OOC_Package__FileData)i5);
l12:
      i4 = i4+1;
      i = i4;
      i5 = i4<i2;
      if (i5) goto l3_loop;
l18:
      if ((!i0)) goto l24;
      i1 = (OOC_INT32)OOC_Config_CCompiler__libdir;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 8349))+8);
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8364)))), &_td_Config__StringVarDesc, 8364)), 8374));
      i1 = oo2c__BuildPackage_InstallDirectory((Object__String)((OOC_INT32)_c12), (Object__String)i1);
      if (i1) goto l22;
      return 0u;
      goto l25;
l22:
      i1 = (OOC_INT32)module;
      i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8409)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i1, 19, 1u);
      i1 = (OOC_INT32)OOC_Config_CCompiler__InstallProgramCmd((URI__URI)i1, 1u);
      OOC_Logger__ShellCommand((Object__String)i1);
      i1 = OS_ProcessManagement__system((Object__String)i1);
      return (i1==0);
      goto l25;
l24:
      return 1u;
l25:
      _failed_function(6833); return 0;
      ;
    }

    
    OOC_CHAR8 oo2c__BuildPackage_InstallExecutable(OOC_Repository__Module module) {
      register OOC_INT32 i0;

      i0 = (OOC_INT32)OOC_Config_CCompiler__bindir;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8886))+8);
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8901)))), &_td_Config__StringVarDesc, 8901)), 8911));
      i0 = oo2c__BuildPackage_InstallDirectory((Object__String)((OOC_INT32)_c13), (Object__String)i0);
      if (i0) goto l3;
      return 0u;
      goto l4;
l3:
      i0 = (OOC_INT32)module;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8946)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i0, 18, 1u);
      i0 = (OOC_INT32)OOC_Config_CCompiler__InstallProgramCmd((URI__URI)i0, 0u);
      OOC_Logger__ShellCommand((Object__String)i0);
      i0 = OS_ProcessManagement__system((Object__String)i0);
      return (i0==0);
l4:
      _failed_function(8664); return 0;
      ;
    }

    
    OOC_CHAR8 oo2c__BuildPackage_InstallFiles(OOC_Package__FileData list) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
      URI__URI baseURI;
      Object__String sourcePrefix;
      OOC_Package__FileData end;
      Object__String dir;
      Object__CharsLatin1 chars;
      ADT_StringBuffer__StringBuffer cmd;
      Object__String str;

      i0 = (OOC_INT32)rep;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10495)))), &_td_OOC_Repository_FileSystem__RepositoryDesc, 10495)), 10506))+12);
      baseURI = (URI__URI)i0;
      i0 = (OOC_INT32)URI_Scheme_File__URIDesc_GetPath((URI_Scheme_File__URI)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10559)))), &_td_URI_Scheme_File__URIDesc, 10559)));
      sourcePrefix = (Object__String)i0;
      i1 = (OOC_INT32)list;
      i2 = i1!=(OOC_INT32)0;
      if (!i2) goto l30;
      i2 = (OOC_INT32)_c14;
      i3 = (OOC_INT32)_c15;
      i4 = (OOC_INT32)_c16;
      
l3_loop:
      i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 10629));
      end = (OOC_Package__FileData)i5;
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 10970)))), &_td_OOC_Package__FileDesc, 10970)), 10975))+8);
      i6 = (OOC_INT32)OS_Path__DirName((Object__String)i6);
      dir = (Object__String)i6;
      i7 = (OOC_INT32)Object__String8Desc_CharsLatin1((Object__String8)(_type_guard(i6, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 11024)))), &_td_Object__String8Desc, 11024)));
      chars = (Object__CharsLatin1)i7;
      i7 = (OOC_INT32)OOC_Config_CCompiler__oocdir;
      i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i7, 11092))+8);
      i7 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i7, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 11107)))), &_td_Config__StringVarDesc, 11107)), 11117));
      i7 = oo2c__BuildPackage_InstallDirectory((Object__String)i7, (Object__String)(_type_guard(i6, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 11165)))), &_td_Object__String8Desc, 11165)));
      if (i7) goto l6;
      return 0u;
      
      goto l25;
l6:
      i7 = (OOC_INT32)OOC_Config_CCompiler__installData;
      i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i7, 11235))+8);
      i7 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i7, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 11250)))), &_td_Config__StringVarDesc, 11250)), 11260));
      i7 = (OOC_INT32)ADT_StringBuffer__New((Object__String)i7);
      cmd = (ADT_StringBuffer__StringBuffer)i7;
      i8 = i1!=i5;
      if (!i8) goto l15;
l10_loop:
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 11317)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i7, (Object__Object)i2);
      i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 11399)))), &_td_OOC_Package__FileDesc, 11399)), 11404))+4);
      i8 = (OOC_INT32)OS_Path__QuoteForShell((Object__String)((OOC_INT32)Object__Concat2((void*)i0,(void*)i8)));
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 11346)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i7, (Object__Object)i8);
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 11437));
      list = (OOC_Package__FileData)i1;
      i8 = i1!=i5;
      if (i8) goto l10_loop;
l15:
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 11481)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i7, (Object__Object)i3);
      i5 = (OOC_INT32)OOC_Config_CCompiler__oocdir;
      i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 11525))+8);
      i8 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i8, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i8, 11540)))), &_td_Config__StringVarDesc, 11540)), 11550));
      i8 = *(OOC_INT32*)(_check_pointer(i8, 11557));
      i8 = i8!=0;
      if (!i8) goto l21;
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 11633))+8);
      i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i5, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 11648)))), &_td_Config__StringVarDesc, 11648)), 11658));
      i5 = (OOC_INT32)OS_Path__QuoteForShell((Object__String)i5);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 11590)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i7, (Object__Object)i5);
      i5 = *(OOC_INT32*)(_check_pointer(i6, 11688));
      i5 = i5!=0;
      if (!i5) goto l21;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 11723)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i7, (Object__Object)i4);
l21:
      i5 = (OOC_INT32)OS_Path__QuoteForShell((Object__String)i6);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 11782)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i7, (Object__Object)i5);
      i5 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 11837)))), ADT_StringBuffer__StringBufferDesc_ToString)),ADT_StringBuffer__StringBufferDesc_ToString)((ADT_StringBuffer__StringBuffer)i7);
      str = (Object__String)i5;
      OOC_Logger__ShellCommand((Object__String)i5);
      i5 = OS_ProcessManagement__system((Object__String)i5);
      i5 = i5!=0;
      if (!i5) goto l25;
      return 0u;
l25:
      i5 = i1!=(OOC_INT32)0;
      if (i5) goto l3_loop;
l30:
      return 1u;
      ;
    }

    
    OOC_CHAR8 oo2c__BuildPackage_BuildDocs(OOC_Repository__Module module, OOC_Make__Rules makeRules, OOC_CHAR8 install) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
      OOC_CHAR8 ok;
      OOC_INT32 i;
      OOC_Repository__Module m;

      ok = 1u;
      i0 = OOC_Config__HaveXsltProc();
      if (i0) goto l3;
      i0=1u;
      goto l24;
l3:
      i = 0;
      i0 = (OOC_INT32)makeRules;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12401))+16);
      i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 12409)), 0);
      i0 = 0!=i0;
      if (i0) goto l6;
      i0=1u;
      goto l24;
l6:
      i0 = (OOC_INT32)module;
      i1 = (OOC_INT32)makeRules;
      i2 = install;
      i3=0;i4=1u;
l7_loop:
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12440))+16);
      i5 = _check_pointer(i5, 12448);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i3, i6, OOC_UINT32, 12448))*4);
      m = (OOC_Repository__Module)i5;
      i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 12484));
      i7 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 12468));
      i3 = i3+1;
      i6 = i7==i6;
      if (!i6) goto l14;
      if (i2) goto l12;
      i4 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 12781)))), OOC_Make__RulesDesc_Update)),OOC_Make__RulesDesc_Update)((OOC_Make__Rules)i1, (OOC_Repository__Module)i5, 5);
      ok = i4;
      
      goto l14;
l12:
      i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 12576));
      i7 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 12576));
      i6 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 12583)))), OOC_Repository__RepositoryDesc_GetLocalPath)),OOC_Repository__RepositoryDesc_GetLocalPath)((OOC_Repository__Repository)i7, (OOC_Repository__Module)i5, 4);
      i6 = (OOC_INT32)OOC_Package__NewFile((Object__String)i6, (Object__String)0);
      i7 = (OOC_INT32)pkg;
      i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i7, 12543))+24);
      OOC_Package__FileSetDesc_Append((OOC_Package__FileSet)i7, (OOC_Package__FileData)i6);
      i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 12681));
      i7 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 12681));
      i5 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 12688)))), OOC_Repository__RepositoryDesc_GetLocalPath)),OOC_Repository__RepositoryDesc_GetLocalPath)((OOC_Repository__Repository)i7, (OOC_Repository__Module)i5, 5);
      i5 = (OOC_INT32)OOC_Package__NewFile((Object__String)i5, (Object__String)0);
      i6 = (OOC_INT32)pkg;
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 12648))+24);
      OOC_Package__FileSetDesc_Append((OOC_Package__FileSet)i6, (OOC_Package__FileData)i5);
      
l14:
      i = i3;
      if (i4) goto l17;
      i5=0u;
      goto l19;
l17:
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12401))+16);
      i5 = OOC_ARRAY_LENGTH((_check_pointer(i5, 12409)), 0);
      i5 = i3!=i5;
      
l19:
      if (i5) goto l7_loop;
l22:
      i0=i4;
l24:
      return i0;
      ;
    }


  OOC_Repository__readDocStrings = 1u;
  i0 = OOC_Config_CCompiler__HaveLibtool();
  installObjects = (!i0);
  ok = 1u;
  i = 0;
  i0 = (OOC_INT32)pkg;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13068))+16);
  i0 = *(OOC_INT32*)((_check_pointer(i0, 13076))+4);
  i0 = 0!=i0;
  if (i0) goto l3;
  i0=1u;
  goto l37;
l3:
  i0=0;
l4_loop:
  i1 = (OOC_INT32)pkg;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 13102))+16);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 13110));
  i1 = _check_pointer(i1, 13116);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(i0, i2, OOC_UINT32, 13116))*4);
  lib = (OOC_Package__Library)i0;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13151))+4);
  i1 = (OOC_INT32)oo2c__GetModule((Object__String)i1);
  module = (OOC_Repository__Module)i1;
  i2 = installObjects;
  if (i2) goto l15;
  i2 = (OOC_INT32)oo2c__makeRules;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 13343)))), OOC_Make__RulesDesc_SetLibrary)),OOC_Make__RulesDesc_SetLibrary)((OOC_Make__Rules)i2, (OOC_Package__Library)i0);
  i0 = (OOC_INT32)oo2c__makeRules;
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13384)))), OOC_Make__RulesDesc_Update)),OOC_Make__RulesDesc_Update)((OOC_Make__Rules)i0, (OOC_Repository__Module)i1, 19);
  if (i0) goto l9;
  i0=0u;
  goto l14;
l9:
  i0 = install;
  i0 = !i0;
  if (i0) goto l12;
  i0 = (OOC_INT32)oo2c__makeRules;
  i0 = oo2c__BuildPackage_InstallLibrary((OOC_Repository__Module)i1, (OOC_Make__Rules)i0);
  
  goto l14;
l12:
  i0=1u;
l14:
  ok = i0;
  
  goto l25;
l15:
  i0 = (OOC_INT32)oo2c__makeRules;
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13217)))), OOC_Make__RulesDesc_Update)),OOC_Make__RulesDesc_Update)((OOC_Make__Rules)i0, (OOC_Repository__Module)i1, 18);
  if (i0) goto l18;
  i0=0u;
  goto l23;
l18:
  i0 = install;
  i0 = !i0;
  if (i0) goto l21;
  i0 = (OOC_INT32)oo2c__makeRules;
  i0 = oo2c__BuildPackage_InstallLibrary((OOC_Repository__Module)i1, (OOC_Make__Rules)i0);
  
  goto l23;
l21:
  i0=1u;
l23:
  ok = i0;
  
l25:
  if (!i0) goto l28;
  i0 = install;
  i1 = (OOC_INT32)oo2c__makeRules;
  i2 = (OOC_INT32)module;
  i0 = oo2c__BuildPackage_BuildDocs((OOC_Repository__Module)i2, (OOC_Make__Rules)i1, i0);
  ok = i0;
  
l28:
  i1 = (OOC_INT32)oo2c__makeRules;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 13656)))), OOC_Make__RulesDesc_SetLibrary)),OOC_Make__RulesDesc_SetLibrary)((OOC_Make__Rules)i1, (OOC_Package__Library)0);
  i1 = i;
  i1 = i1+1;
  i = i1;
  if (i0) goto l31;
  i2=0u;
  goto l33;
l31:
  i2 = (OOC_INT32)pkg;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 13068))+16);
  i2 = *(OOC_INT32*)((_check_pointer(i2, 13076))+4);
  i2 = i1!=i2;
  
l33:
  if (!i2) goto l37;
  i0=i1;
  goto l4_loop;
l37:
  i = 0;
  if (i0) goto l40;
  i1=0u;
  goto l42;
l40:
  i1 = (OOC_INT32)pkg;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 13733))+20);
  i1 = *(OOC_INT32*)((_check_pointer(i1, 13744))+4);
  i1 = 0!=i1;
  
l42:
  if (!i1) goto l63;
  i0=0;
l45_loop:
  i1 = (OOC_INT32)pkg;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 13771))+20);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 13782));
  i1 = _check_pointer(i1, 13788);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(i0, i2, OOC_UINT32, 13788))*4);
  exec = (OOC_Package__Executable)i0;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 13823));
  i0 = (OOC_INT32)oo2c__GetModule((Object__String)i0);
  module = (OOC_Repository__Module)i0;
  i1 = (OOC_INT32)oo2c__makeRules;
  i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 13858)))), OOC_Make__RulesDesc_Update)),OOC_Make__RulesDesc_Update)((OOC_Make__Rules)i1, (OOC_Repository__Module)i0, 18);
  if (i1) goto l48;
  i0=0u;
  goto l53;
l48:
  i1 = install;
  i1 = !i1;
  if (i1) goto l51;
  i0 = oo2c__BuildPackage_InstallExecutable((OOC_Repository__Module)i0);
  
  goto l53;
l51:
  i0=1u;
l53:
  i1 = i;
  ok = i0;
  i1 = i1+1;
  i = i1;
  if (i0) goto l56;
  i2=0u;
  goto l58;
l56:
  i2 = (OOC_INT32)pkg;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 13733))+20);
  i2 = *(OOC_INT32*)((_check_pointer(i2, 13744))+4);
  i2 = i1!=i2;
  
l58:
  if (!i2) goto l63;
  i0=i1;
  goto l45_loop;
l63:
  if (i0) goto l65;
  i1=0u;
  goto l67;
l65:
  i1 = install;
  
l67:
  if (!i1) goto l71;
  i0 = (OOC_INT32)pkg;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14037))+24);
  i0 = (OOC_INT32)OOC_Package__Normalize((OOC_Package__FileSet)i0);
  normSet = (OOC_Package__FileSet)i0;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14080))+12);
  i0 = oo2c__BuildPackage_InstallFiles((OOC_Package__FileData)i0);
  ok = i0;
  
l71:
  if (i0) goto l73;
  i1=0u;
  goto l75;
l73:
  i1 = install;
  
l75:
  if (!i1) goto l77;
  i1 = (OOC_INT32)OOC_Config_CCompiler__oocdir;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14198))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14213)))), &_td_Config__StringVarDesc, 14213)), 14223));
  i2 = (OOC_INT32)pkg;
  OOC_Package__WritePackage((OOC_Package__Package)i2, (Object__String)i1);
l77:
  return i0;
  ;
}

static void oo2c__UninstallPackage(OOC_Package__Package pkg) {
  register OOC_INT32 i0,i1,i2;
  OOC_INT32 i;
  OOC_Package__FileSet normSet;
  auto void oo2c__UninstallPackage_UninstallLibrary(OOC_Package__Library library);
  auto void oo2c__UninstallPackage_UninstallExecutable(OOC_Package__Executable executable);
  auto void oo2c__UninstallPackage_UninstallFiles(OOC_Package__FileData list);
  auto void oo2c__UninstallPackage_UninstallPkgInfo(OOC_Package__Package pkg);
    
    void oo2c__UninstallPackage_UninstallLibrary(OOC_Package__Library library) {
      register OOC_INT32 i0,i1;
      ADT_StringBuffer__StringBuffer b;

      i0 = (OOC_INT32)ADT_StringBuffer__NewLatin1("", 1);
      b = (ADT_StringBuffer__StringBuffer)i0;
      i1 = (OOC_INT32)OOC_Config_CCompiler__libdir;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14608))+8);
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14623)))), &_td_Config__StringVarDesc, 14623)), 14633));
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14584)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i1);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14650)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c17));
      i1 = (OOC_INT32)library;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 14689));
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14674)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i1);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14704)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c18));
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14764)))), ADT_StringBuffer__StringBufferDesc_ToString)),ADT_StringBuffer__StringBufferDesc_ToString)((ADT_StringBuffer__StringBuffer)i0);
      i0 = (OOC_INT32)OOC_Config_CCompiler__UninstallProgramCmd((Object__String)i0, 1u);
      OOC_Logger__ShellCommand((Object__String)i0);
      i0 = OS_ProcessManagement__system((Object__String)i0);
      return;
      ;
    }

    
    void oo2c__UninstallPackage_UninstallExecutable(OOC_Package__Executable executable) {
      register OOC_INT32 i0,i1;
      ADT_StringBuffer__StringBuffer b;

      i0 = (OOC_INT32)ADT_StringBuffer__NewLatin1("", 1);
      b = (ADT_StringBuffer__StringBuffer)i0;
      i1 = (OOC_INT32)OOC_Config_CCompiler__bindir;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 15121))+8);
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15136)))), &_td_Config__StringVarDesc, 15136)), 15146));
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15097)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i1);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15163)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c19));
      i1 = (OOC_INT32)executable;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 15202));
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15184)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i1);
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15260)))), ADT_StringBuffer__StringBufferDesc_ToString)),ADT_StringBuffer__StringBufferDesc_ToString)((ADT_StringBuffer__StringBuffer)i0);
      i0 = (OOC_INT32)OOC_Config_CCompiler__UninstallProgramCmd((Object__String)i0, 0u);
      OOC_Logger__ShellCommand((Object__String)i0);
      i0 = OS_ProcessManagement__system((Object__String)i0);
      return;
      ;
    }

    
    void oo2c__UninstallPackage_UninstallFiles(OOC_Package__FileData list) {
      register OOC_INT32 i0,i1,i2,i3,i4;
      ADT_StringBuffer__StringBuffer b;
      Object__String str;
      OOC_CHAR8 ok;

      i0 = (OOC_INT32)list;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l8;
      i1 = (OOC_INT32)_c20;
      i2 = (OOC_INT32)_c21;
      
l3_loop:
      i3 = (OOC_INT32)OOC_Config_CCompiler__uninstall;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 15613))+8);
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 15628)))), &_td_Config__StringVarDesc, 15628)), 15638));
      i3 = (OOC_INT32)ADT_StringBuffer__New((Object__String)i3);
      b = (ADT_StringBuffer__StringBuffer)i3;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 15657)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i3, (Object__Object)i1);
      i4 = (OOC_INT32)OOC_Config_CCompiler__oocdir;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 15723))+8);
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 15738)))), &_td_Config__StringVarDesc, 15738)), 15748));
      i4 = (OOC_INT32)OS_Path__QuoteForShell((Object__String)i4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 15680)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i3, (Object__Object)i4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 15768)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i3, (Object__Object)i2);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15812)))), &_td_OOC_Package__FileDesc, 15812)), 15817))+8);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 15791)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i3, (Object__Object)i4);
      i3 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 15846)))), ADT_StringBuffer__StringBufferDesc_ToString)),ADT_StringBuffer__StringBufferDesc_ToString)((ADT_StringBuffer__StringBuffer)i3);
      str = (Object__String)i3;
      OOC_Logger__ShellCommand((Object__String)i3);
      i3 = OS_ProcessManagement__system((Object__String)i3);
      ok = (i3==0);
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 15964));
      list = (OOC_Package__FileData)i0;
      i3 = i0!=(OOC_INT32)0;
      if (i3) goto l3_loop;
l8:
      return;
      ;
    }

    
    void oo2c__UninstallPackage_UninstallPkgInfo(OOC_Package__Package pkg) {
      register OOC_INT32 i0,i1,i2;

      i0 = (OOC_INT32)OOC_Config_CCompiler__uninstall;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16268))+8);
      i1 = (OOC_INT32)OOC_Config_CCompiler__oocdir;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 16204))+8);
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16283)))), &_td_Config__StringVarDesc, 16283)), 16293));
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16219)))), &_td_Config__StringVarDesc, 16219)), 16229));
      i2 = (OOC_INT32)pkg;
      i0 = (OOC_INT32)OOC_Package__RemovePkgInfoCmd((OOC_Package__Package)i2, (Object__String)i1, (Object__String)i0);
      OOC_Logger__ShellCommand((Object__String)i0);
      i0 = OS_ProcessManagement__system((Object__String)i0);
      return;
      ;
    }


  i = 0;
  i0 = (OOC_INT32)pkg;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16451))+16);
  i1 = *(OOC_INT32*)((_check_pointer(i1, 16459))+4);
  i1 = 0!=i1;
  if (!i1) goto l9;
  i1=0;
l4_loop:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16495))+16);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 16503));
  i0 = _check_pointer(i0, 16509);
  i2 = OOC_ARRAY_LENGTH(i0, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(i1, i2, OOC_UINT32, 16509))*4);
  oo2c__UninstallPackage_UninstallLibrary((OOC_Package__Library)i0);
  i0 = i;
  i0 = i0+1;
  i = i0;
  i1 = (OOC_INT32)pkg;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 16451))+16);
  i2 = *(OOC_INT32*)((_check_pointer(i2, 16459))+4);
  i2 = i0!=i2;
  if (!i2) goto l8;
  {register OOC_INT32 h0=i0;i0=i1;i1=h0;}
  goto l4_loop;
l8:
  i0=i1;
l9:
  i = 0;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16569))+20);
  i1 = *(OOC_INT32*)((_check_pointer(i1, 16580))+4);
  i1 = 0!=i1;
  if (!i1) goto l18;
  i1=0;
l13_loop:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16619))+20);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 16630));
  i0 = _check_pointer(i0, 16636);
  i2 = OOC_ARRAY_LENGTH(i0, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(i1, i2, OOC_UINT32, 16636))*4);
  oo2c__UninstallPackage_UninstallExecutable((OOC_Package__Executable)i0);
  i0 = i;
  i0 = i0+1;
  i = i0;
  i1 = (OOC_INT32)pkg;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 16569))+20);
  i2 = *(OOC_INT32*)((_check_pointer(i2, 16580))+4);
  i2 = i0!=i2;
  if (!i2) goto l17;
  {register OOC_INT32 h0=i0;i0=i1;i1=h0;}
  goto l13_loop;
l17:
  i0=i1;
l18:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16706))+24);
  i0 = (OOC_INT32)OOC_Package__Normalize((OOC_Package__FileSet)i0);
  normSet = (OOC_Package__FileSet)i0;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16743))+12);
  oo2c__UninstallPackage_UninstallFiles((OOC_Package__FileData)i0);
  i0 = (OOC_INT32)pkg;
  oo2c__UninstallPackage_UninstallPkgInfo((OOC_Package__Package)i0);
  return;
  ;
}

static OOC_CHAR8 oo2c__BuildPackageDoc(OOC_Package__Package pkg) {
  register OOC_INT32 i0,i1,i2;
  OOC_CHAR8 ok;
  OOC_INT32 i;
  OOC_Package__Library lib;
  OOC_Package__Executable exec;
  auto OOC_CHAR8 oo2c__BuildPackageDoc_BuildDocs(OOC_Repository__Module module);
    
    OOC_CHAR8 oo2c__BuildPackageDoc_BuildDocs(OOC_Repository__Module module) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
      OOC_CHAR8 ok;
      OOC_Make__ModuleList list;
      OOC_INT32 i;

      i0 = (OOC_INT32)oo2c__makeRules;
      i1 = (OOC_INT32)module;
      i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17149)))), OOC_Make__RulesDesc_Update)),OOC_Make__RulesDesc_Update)((OOC_Make__Rules)i0, (OOC_Repository__Module)i1, 1);
      ok = i0;
      i2 = (OOC_INT32)OOC_Make__ModuleClosure((OOC_Repository__Module)i1);
      list = (OOC_Make__ModuleList)i2;
      i = 0;
      if (i0) goto l3;
      i3=0u;
      goto l5;
l3:
      i3 = OOC_ARRAY_LENGTH((_check_pointer(i2, 17279)), 0);
      i3 = 0!=i3;
      
l5:
      if (!i3) goto l21;
      i3=i0;i0=0;
l8_loop:
      i4 = _check_pointer(i2, 17302);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i0, i5, OOC_UINT32, 17302))*4);
      i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 17321));
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 17305));
      i6 = i0+1;
      i4 = i4==i5;
      if (i4) goto l11;
      i0=i3;
      goto l12;
l11:
      i3 = _check_pointer(i2, 17372);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i5 = (OOC_INT32)oo2c__makeRules;
      i0 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i0, i4, OOC_UINT32, 17372))*4);
      i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 17360)))), OOC_Make__RulesDesc_Update)),OOC_Make__RulesDesc_Update)((OOC_Make__Rules)i5, (OOC_Repository__Module)i0, 5);
      ok = i0;
      
l12:
      i = i6;
      if (i0) goto l15;
      i3=0u;
      goto l17;
l15:
      i3 = OOC_ARRAY_LENGTH((_check_pointer(i2, 17279)), 0);
      i3 = i6!=i3;
      
l17:
      if (!i3) goto l21;
      i3=i0;i0=i6;
      goto l8_loop;
l21:
      return i0;
      ;
    }


  OOC_Repository__readDocStrings = 1u;
  ok = 1u;
  i = 0;
  i0 = (OOC_INT32)pkg;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17571))+16);
  i0 = *(OOC_INT32*)((_check_pointer(i0, 17579))+4);
  i0 = 0!=i0;
  if (i0) goto l3;
  i0=1u;
  goto l13;
l3:
  i0=0;
l4_loop:
  i1 = (OOC_INT32)pkg;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 17605))+16);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 17613));
  i1 = _check_pointer(i1, 17619);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(i0, i2, OOC_UINT32, 17619))*4);
  lib = (OOC_Package__Library)i0;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17659))+4);
  i0 = (OOC_INT32)oo2c__GetModule((Object__String)i0);
  i0 = oo2c__BuildPackageDoc_BuildDocs((OOC_Repository__Module)i0);
  i1 = i;
  ok = i0;
  i1 = i1+1;
  i = i1;
  if (i0) goto l7;
  i2=0u;
  goto l9;
l7:
  i2 = (OOC_INT32)pkg;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 17571))+16);
  i2 = *(OOC_INT32*)((_check_pointer(i2, 17579))+4);
  i2 = i1!=i2;
  
l9:
  if (!i2) goto l13;
  i0=i1;
  goto l4_loop;
l13:
  i = 0;
  if (i0) goto l16;
  i1=0u;
  goto l18;
l16:
  i1 = (OOC_INT32)pkg;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 17733))+20);
  i1 = *(OOC_INT32*)((_check_pointer(i1, 17744))+4);
  i1 = 0!=i1;
  
l18:
  if (!i1) goto l30;
  i0=0;
l21_loop:
  i1 = (OOC_INT32)pkg;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 17771))+20);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 17782));
  i1 = _check_pointer(i1, 17788);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(i0, i2, OOC_UINT32, 17788))*4);
  exec = (OOC_Package__Executable)i0;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 17829));
  i0 = (OOC_INT32)oo2c__GetModule((Object__String)i0);
  i0 = oo2c__BuildPackageDoc_BuildDocs((OOC_Repository__Module)i0);
  i1 = i;
  ok = i0;
  i1 = i1+1;
  i = i1;
  if (i0) goto l24;
  i2=0u;
  goto l26;
l24:
  i2 = (OOC_INT32)pkg;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 17733))+20);
  i2 = *(OOC_INT32*)((_check_pointer(i2, 17744))+4);
  i2 = i1!=i2;
  
l26:
  if (!i2) goto l30;
  i0=i1;
  goto l21_loop;
l30:
  return i0;
  ;
}

static void oo2c__WriteHelp(void) {

  Out__String("Usage:", 7);
  Out__Ln();
  Out__String("  oo2c [options] <module>...", 29);
  Out__Ln();
  Out__String("  oo2c (--make|-M) [options] <module>", 38);
  Out__Ln();
  Out__String("  oo2c --uses <ext-ident> [options] <module> ...", 49);
  Out__Ln();
  Out__String("  oo2c --build-package [options] <package>", 43);
  Out__Ln();
  Out__String("  oo2c --install-package [options] <package>", 45);
  Out__Ln();
  Out__String("  oo2c --uninstall-package [options] <package>", 47);
  Out__Ln();
  Out__String("  oo2c --build-pkg-doc [options] <package>", 43);
  Out__Ln();
  Out__String("  oo2c --package-installed [options] <package>", 47);
  Out__Ln();
  Out__String("  oo2c --list-packages [options]", 33);
  Out__Ln();
  Out__String("Options:", 9);
  Out__Ln();
  Out__String("  --config <file>", 18);
  Out__Ln();
  Out__String("  --repository <directory>, -r <directory>", 43);
  Out__Ln();
  Out__String("  --no-rtc", 11);
  Out__Ln();
  Out__String("  (--all|-A)", 13);
  Out__Ln();
  Out__String("  --error-style (file:line:column|char-pos|attributes)", 55);
  Out__Ln();
  return;
  ;
}

void OOC_oo2c_init(void) {
  register OOC_INT32 i0,i1,i2,i3;
  _c0 = Object__NewLatin1Region("command", 8, 0, 7);
  _c1 = Object__NewLatin1Region("forceUpdate", 12, 0, 11);
  _c2 = Object__NewLatin1Region("", 1, 0, 0);
  _c3 = Object__NewLatin1Region("listUses", 9, 0, 8);
  _c4 = Object__NewLatin1Region("useStderr", 10, 0, 9);
  _c5 = Object__NewLatin1Region("writeStats", 11, 0, 10);
  _c6 = Object__NewLatin1Region("verbose", 8, 0, 7);
  _c7 = Object__NewLatin1Region("file:line:column", 17, 0, 16);
  _c8 = Object__NewLatin1Region("errorStyle", 11, 0, 10);
  _c9 = Object__NewLatin1Region("showHelp", 9, 0, 8);
  _c10 = Object__NewLatin1Region("showVersion", 12, 0, 11);
  _c11 = Object__NewLatin1Char(47u);
  _c12 = Object__NewLatin1Region("", 1, 0, 0);
  _c13 = Object__NewLatin1Region("", 1, 0, 0);
  _c14 = Object__NewLatin1Char(32u);
  _c15 = Object__NewLatin1Char(32u);
  _c16 = Object__NewLatin1Char(47u);
  _c17 = Object__NewLatin1Region("/lib", 5, 0, 4);
  _c18 = Object__NewLatin1Region(".la", 4, 0, 3);
  _c19 = Object__NewLatin1Char(47u);
  _c20 = Object__NewLatin1Char(32u);
  _c21 = Object__NewLatin1Char(47u);
  _c22 = Object__NewLatin1Region("", 1, 0, 0);
  _c23 = Object__NewLatin1Region("file:line:column", 17, 0, 16);
  _c24 = Object__NewLatin1Region("char-pos", 9, 0, 8);

  OOC_Error__minErrorDistance = 16;
  OOC_SymbolTable_Builder__doAutoImport = 2;
  i0 = (OOC_INT32)OOC_Error__NewList((Object__String)((OOC_INT32)_c22));
  oo2c__cfgErrList = (OOC_Error__List)i0;
  oo2c__NewConfig();
  i0 = (OOC_INT32)oo2c__cfgErrList;
  OOC_Config__Read((Msg__MsgList)i0);
  i0 = (OOC_INT32)OOC_Make__NewRules();
  oo2c__makeRules = (OOC_Make__Rules)i0;
  i1 = (OOC_INT32)oo2c__useStderr;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 19161))+8);
  i1 = *(OOC_UINT8*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 19176)))), &_td_Config__BooleanVarDesc, 19176)), 19187));
  if (!i1) goto l3;
  i1 = (OOC_INT32)IO_StdChannels__stderr;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 19214)))), OOC_Make__RulesDesc_SetErrOut)),OOC_Make__RulesDesc_SetErrOut)((OOC_Make__Rules)i0, (IO__ByteChannel)i1);
l3:
  i0 = (OOC_INT32)oo2c__forceUpdate;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19291))+8);
  i1 = (OOC_INT32)oo2c__makeRules;
  i0 = *(OOC_UINT8*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 19306)))), &_td_Config__BooleanVarDesc, 19306)), 19317));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 19264)))), OOC_Make__RulesDesc_SetForceUpdate)),OOC_Make__RulesDesc_SetForceUpdate)((OOC_Make__Rules)i1, i0);
  i0 = (OOC_INT32)oo2c__listUses;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19368))+8);
  i1 = (OOC_INT32)oo2c__makeRules;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 19383)))), &_td_Config__StringVarDesc, 19383)), 19393));
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 19345)))), OOC_Make__RulesDesc_UsageTracking)),OOC_Make__RulesDesc_UsageTracking)((OOC_Make__Rules)i1, (Object__String)i0);
  oo2c__ok = i0;
  i0 = !i0;
  if (!i0) goto l6;
  Err__String("Error: Invalid selector string for `--uses\047", 44);
  Err__Ln();
  _halt(1);
l6:
  i0 = (OOC_INT32)oo2c__writeStats;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19544))+8);
  i0 = *(OOC_UINT8*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 19559)))), &_td_Config__BooleanVarDesc, 19559)), 19570));
  OOC_Make__writeStats = i0;
  i0 = (OOC_INT32)oo2c__verbose;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19608))+8);
  i0 = *(OOC_UINT8*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 19623)))), &_td_Config__BooleanVarDesc, 19623)), 19634));
  OOC_Logger__silence = (!i0);
  i0 = (OOC_INT32)oo2c__command;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19661))+8);
  i0 = *(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 19676)))), &_td_Config__IntegerVarDesc, 19676)), 19687));
  switch (i0) {
  case 0:
    oo2c__mode = 11;
    goto l19;
  case 1:
    oo2c__mode = 18;
    goto l19;
  case 2:
    oo2c__mode = (-1);
    goto l19;
  case 3:
    oo2c__mode = (-2);
    goto l19;
  case 4:
    oo2c__mode = (-3);
    goto l19;
  case 5:
    oo2c__mode = (-4);
    goto l19;
  case 6:
    oo2c__mode = (-5);
    OOC_Logger__silence = 1u;
    goto l19;
  case 7:
    oo2c__mode = (-6);
    goto l19;
  case 8:
    oo2c__mode = (-7);
    OOC_Logger__silence = 1u;
    goto l19;
  case 9:
    oo2c__mode = (-8);
    OOC_Logger__silence = 1u;
    goto l19;
  default:
    _failed_case(i0, 19649);
    goto l19;
  }
l19:
  i0 = (OOC_INT32)oo2c__errorStyle;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20146))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20146))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20161)))), &_td_Config__StringVarDesc, 20161)), 20171));
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 20161)))), &_td_Config__StringVarDesc, 20161)), 20171));
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20178)))), Object__StringDesc_Equals)),Object__StringDesc_Equals)((Object__String)i1, (Object__Object)((OOC_INT32)_c23));
  if (i0) goto l25;
  i0 = (OOC_INT32)oo2c__errorStyle;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20275))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20275))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20290)))), &_td_Config__StringVarDesc, 20290)), 20300));
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 20290)))), &_td_Config__StringVarDesc, 20290)), 20300));
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20307)))), Object__StringDesc_Equals)),Object__StringDesc_Equals)((Object__String)i1, (Object__Object)((OOC_INT32)_c24));
  if (!i0) goto l26;
  OOC_Error__style = 1;
  goto l26;
l25:
  OOC_Error__style = 0;
l26:
  i0 = (OOC_INT32)oo2c__cfgErrList;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 20397));
  i1 = i1!=0;
  if (i1) goto l138;
  i0 = (OOC_INT32)oo2c__showVersion;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20494))+8);
  i0 = *(OOC_UINT8*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20509)))), &_td_Config__BooleanVarDesc, 20509)), 20520));
  if (i0) goto l136;
  i0 = (OOC_INT32)oo2c__showHelp;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20718))+8);
  i0 = *(OOC_UINT8*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20733)))), &_td_Config__BooleanVarDesc, 20733)), 20744));
  if (i0) goto l134;
  i0 = oo2c__mode;
  i1 = i0==(-4);
  if (i1) goto l35;
  i2 = i0==(-8);
  
  goto l36;
l35:
  i2=1u;
l36:
  i3 = (OOC_INT32)OOC_Config__arguments;
  i3 = Config_Section_Arguments__SectionDesc_ArgNumber((Config_Section_Arguments__Section)i3);
  i2 = i2!=(i3==0);
  if (i2) goto l132;
  oo2c__ok = 1u;
  if (i1) goto l123;
  i0 = i0==(-8);
  if (i0) goto l113;
  i0 = (OOC_INT32)OOC_Config__options;
  i1 = (OOC_INT32)OOC_Config__pragmas;
  i0 = OOC_Package__ParseMetaData((Config_Section_Options__Section)i0, (Config_Section_Options__Section)i1);
  i0 = !i0;
  if (!i0) goto l45;
  _halt(1);
l45:
  oo2c__forceUpdateRepository = 0u;
  oo2c__i = 0;
  i0 = oo2c__ok;
  if (i0) goto l48;
  i0=0u;
  goto l50;
l48:
  i0 = (OOC_INT32)OOC_Config__arguments;
  i0 = Config_Section_Arguments__SectionDesc_ArgNumber((Config_Section_Arguments__Section)i0);
  i0 = 0!=i0;
  
l50:
  if (!i0) goto l105;
  i0=0;
l52_loop:
  i1 = (OOC_INT32)OOC_Config__arguments;
  i0 = (OOC_INT32)Config_Section_Arguments__SectionDesc_Get((Config_Section_Arguments__Section)i1, i0);
  oo2c__arg = (Object__String)i0;
  i1 = oo2c__mode;
  switch (i1) {
  case (-1):
  case (-2):
    oo2c__doInstall = (i1==(-2));
    i0 = (OOC_INT32)OOC_Package__GetPackage((Object__String)i0, (void*)(OOC_INT32)&oo2c__rep);
    oo2c__pkg = (OOC_Package__Package)i0;
    i0 = i0==0;
    if (i0) goto l67;
    i0 = oo2c__doInstall;
    if (!i0) goto l66;
    i0 = (OOC_INT32)OOC_Config_CCompiler__oocdir;
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22026))+8);
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22041)))), &_td_Config__StringVarDesc, 22041)), 22051));
    i1 = (OOC_INT32)oo2c__arg;
    i0 = (OOC_INT32)OOC_Package__GetPkgInfo((Object__String)i0, (Object__String)i1, (void*)(OOC_INT32)&oo2c__errList);
    oo2c__pkgInfo = (OOC_Package__Package)i0;
    i1 = i0!=0;
    if (i1) goto l61;
    i1=0u;
    goto l63;
l61:
    i1 = (OOC_INT32)oo2c__errList;
    i1 = *(OOC_INT32*)(_check_pointer(i1, 22118));
    i1 = i1==0;
    
l63:
    if (!i1) goto l66;
    oo2c__UninstallPackage((OOC_Package__Package)i0);
l66:
    i0 = oo2c__doInstall;
    i1 = (OOC_INT32)oo2c__rep;
    i2 = (OOC_INT32)oo2c__pkg;
    i0 = oo2c__BuildPackage((OOC_Package__Package)i2, (OOC_Repository__Repository)i1, i0);
    oo2c__ok = i0;
    i0 = oo2c__doInstall;
    oo2c__forceUpdateRepository = i0;
    goto l96;
l67:
    Err__String("Error: Cannot locate package ", 30);
    i0 = (OOC_INT32)oo2c__arg;
    Err__Object((Object__Object)i0);
    Err__Ln();
    _halt(1);
    goto l96;
  case (-3):
    i1 = (OOC_INT32)OOC_Config_CCompiler__oocdir;
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 22424))+8);
    i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 22439)))), &_td_Config__StringVarDesc, 22439)), 22449));
    i0 = (OOC_INT32)OOC_Package__GetPkgInfo((Object__String)i1, (Object__String)i0, (void*)(OOC_INT32)&oo2c__errList);
    oo2c__pkg = (OOC_Package__Package)i0;
    i0 = (OOC_INT32)oo2c__errList;
    i1 = *(OOC_INT32*)(_check_pointer(i0, 22494));
    i1 = i1!=0;
    if (!i1) goto l72;
    i1 = (OOC_INT32)IO_StdChannels__stdout;
    OOC_Error__ListDesc_Write((OOC_Error__List)i0, (IO__ByteChannel)i1);
l72:
    i0 = (OOC_INT32)oo2c__pkg;
    i1 = i0==0;
    if (i1) goto l75;
    oo2c__UninstallPackage((OOC_Package__Package)i0);
    oo2c__forceUpdateRepository = 1u;
    goto l96;
l75:
    Err__String("Error: Cannot locate package ", 30);
    i0 = (OOC_INT32)oo2c__arg;
    Err__Object((Object__Object)i0);
    Err__Ln();
    _halt(1);
    goto l96;
  case (-5):
    i1 = (OOC_INT32)OOC_Config__options;
    i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 22900)))), Config_Section_Options__SectionDesc_Get)),Config_Section_Options__SectionDesc_Get)((Config_Section_Options__Section)i1, (Object__String)i0);
    oo2c__option = (Config_Section_Options__Option)i0;
    i1 = i0==0;
    if (i1) goto l80;
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23022))+8);
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 23037)))), &_td_Config__StringVarDesc, 23037)), 23047));
    Out__Object((Object__Object)i0);
    goto l81;
l80:
    Out__String("(none)", 7);
l81:
    Out__Ln();
    goto l96;
  case (-6):
    i0 = (OOC_INT32)OOC_Package__GetPackage((Object__String)i0, (void*)(OOC_INT32)&oo2c__rep);
    oo2c__pkg = (OOC_Package__Package)i0;
    i1 = i0==0;
    if (i1) goto l85;
    i0 = oo2c__BuildPackageDoc((OOC_Package__Package)i0);
    oo2c__ok = i0;
    goto l96;
l85:
    Err__String("Error: Cannot locate package ", 30);
    i0 = (OOC_INT32)oo2c__arg;
    Err__Object((Object__Object)i0);
    Err__Ln();
    _halt(1);
    goto l96;
  case (-7):
    i0 = (OOC_INT32)OOC_Config_CCompiler__oocdir;
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23496))+8);
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 23511)))), &_td_Config__StringVarDesc, 23511)), 23521));
    i0 = (OOC_INT32)OOC_Package__GetRepository((Object__String)i0, (void*)(OOC_INT32)&oo2c__errList);
    oo2c__r = (OOC_Package__Repository)i0;
    i0 = (OOC_INT32)IO_StdChannels__stderr;
    i1 = (OOC_INT32)oo2c__errList;
    OOC_Error__ListDesc_Write((OOC_Error__List)i1, (IO__ByteChannel)i0);
    i0 = (OOC_INT32)oo2c__arg;
    i1 = (OOC_INT32)oo2c__r;
    i0 = OOC_Package__RepositoryDesc_PackageInstalled((OOC_Package__Repository)i1, (Object__String)i0);
    if (i0) goto l90;
    _halt(1);
    goto l96;
l90:
    _halt(0);
    goto l96;
  default:
    i0 = (OOC_INT32)oo2c__GetModule((Object__String)i0);
    oo2c__module = (OOC_Repository__Module)i0;
    i1 = oo2c__mode;
    i1 = i1==11;
    if (!i1) goto l95;
    i1 = (OOC_INT32)oo2c__makeRules;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 23814)))), OOC_Make__RulesDesc_SetAllImportsModule)),OOC_Make__RulesDesc_SetAllImportsModule)((OOC_Make__Rules)i1, (OOC_Repository__Module)i0);
l95:
    i0 = (OOC_INT32)oo2c__makeRules;
    i1 = oo2c__mode;
    i2 = (OOC_INT32)oo2c__module;
    i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 23884)))), OOC_Make__RulesDesc_Update)),OOC_Make__RulesDesc_Update)((OOC_Make__Rules)i0, (OOC_Repository__Module)i2, i1);
    oo2c__ok = i0;
    i0 = (OOC_INT32)oo2c__makeRules;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 23926)))), OOC_Make__RulesDesc_SetAllImportsModule)),OOC_Make__RulesDesc_SetAllImportsModule)((OOC_Make__Rules)i0, (OOC_Repository__Module)0);
    goto l96;
  }
l96:
  i0 = oo2c__i;
  i0 = i0+1;
  oo2c__i = i0;
  i1 = oo2c__ok;
  if (i1) goto l99;
  i1=0u;
  goto l101;
l99:
  i1 = (OOC_INT32)OOC_Config__arguments;
  i1 = Config_Section_Arguments__SectionDesc_ArgNumber((Config_Section_Arguments__Section)i1);
  i1 = i0!=i1;
  
l101:
  if (i1) goto l52_loop;
l105:
  i0 = oo2c__ok;
  if (i0) goto l108;
  i0=0u;
  goto l110;
l108:
  i0 = oo2c__forceUpdateRepository;
  
l110:
  if (!i0) goto l124;
  i0 = (OOC_INT32)OOC_Config_CCompiler__oocdir;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24090))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 24105)))), &_td_Config__StringVarDesc, 24105)), 24115));
  i0 = OOC_Package__UpdateRepository((Object__String)i0);
  oo2c__ok = i0;
  goto l124;
l113:
  i0 = (OOC_INT32)OOC_Config_CCompiler__oocdir;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21146))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21161)))), &_td_Config__StringVarDesc, 21161)), 21171));
  i0 = (OOC_INT32)OOC_Package__GetRepository((Object__String)i0, (void*)(OOC_INT32)&oo2c__errList);
  oo2c__r = (OOC_Package__Repository)i0;
  i0 = (OOC_INT32)IO_StdChannels__stderr;
  i1 = (OOC_INT32)oo2c__errList;
  OOC_Error__ListDesc_Write((OOC_Error__List)i1, (IO__ByteChannel)i0);
  i0 = (OOC_INT32)oo2c__r;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21252))+8);
  i0 = *(OOC_INT32*)((_check_pointer(i0, 21266))+4);
  oo2c__i = 0;
  i1 = 0<i0;
  if (!i1) goto l124;
  i1=0;
l116_loop:
  i2 = (OOC_INT32)oo2c__r;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 21297))+8);
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 21311));
  i2 = _check_pointer(i2, 21317);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i1, i3, OOC_UINT32, 21317))*4);
  Out__Object((Object__Object)i1);
  Out__Ln();
  i1 = oo2c__i;
  i1 = i1+1;
  oo2c__i = i1;
  i2 = i1<i0;
  if (i2) goto l116_loop;
  goto l124;
l123:
  i0 = (OOC_INT32)OOC_Config_CCompiler__oocdir;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21024))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21039)))), &_td_Config__StringVarDesc, 21039)), 21049));
  i0 = OOC_Package__UpdateRepository((Object__String)i0);
  oo2c__ok = i0;
l124:
  i0 = oo2c__ok;
  if (i0) goto l127;
  _halt(1);
  goto l139;
l127:
  i0 = OOC_Make__writeStats;
  if (!i0) goto l139;
  OOC_SSA_Stats__Write();
  goto l139;
l132:
  oo2c__WriteHelp();
  _halt(1);
  goto l139;
l134:
  oo2c__WriteHelp();
  goto l139;
l136:
  Out__String("oo2c/", 6);
  Out__String("gcc", 4);
  Out__String(" ", 2);
  Out__String("2.1.7", 6);
  Out__Ln();
  _halt(0);
  goto l139;
l138:
  i1 = (OOC_INT32)IO_StdChannels__stderr;
  OOC_Error__ListDesc_Write((OOC_Error__List)i0, (IO__ByteChannel)i1);
  _halt(1);
l139:
  return;
  ;
}

void OOC_oo2c_destroy(void) {
}

/* --- */
