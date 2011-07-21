static void* _c0;
static void* _c1;
static void* _c2;
#include <OOC/Make.oh>
#include <Out.oh>
#include <StdChannels.oh>
#include <Time.oh>
#include <ADT/ArrayList.oh>
#include <ADT/StringBuffer.oh>
#include <StringSearch/NoMatch.oh>
#include <OS/Path.oh>
#include <OS/Files.oh>
#include <OS/ProcessManagement.oh>
#include <URI.oh>
#include <URI/Scheme/File.oh>
#include <OOC/Logger.oh>
#include <OOC/Config.oh>
#include <OOC/Config/Pragmas.oh>
#include <OOC/Config/Repositories.oh>
#include <OOC/Doc/ResolveRef.oh>
#include <OOC/AST.oh>
#include <OOC/SymbolTable/InterfaceDescr.oh>
#include <OOC/SymbolTable/InterfaceXML.oh>
#include <OOC/Auxiliary/ParseModule.oh>
#include <OOC/Make/LinkProgramC.oh>
#include <OOC/C/IRtoC.oh>
#include <OOC/Config/CCompiler.oh>
#include <OOC/Make/TranslateToC.oh>
#include <OOC/Make/WriteMainFileC.oh>
#include <OOC/SSA/WriteC.oh>
#include <OOC/Config/Assembler.oh>
#include <OOC/Make/TranslateToIA32.oh>
#include <OOC/Make/WriteMainFileAssembler.oh>
#include <OOC/IA32/WriteAssembler.oh>
#define OOC_Make__stylesheetPackageName "OOC"
#define OOC_Make__stylesheetPath "xml/interface-description.xsl"
static OOC_CHAR8 OOC_Make__fileIdNames[22][24];
static URI__URI OOC_Make__stylesheetSystemId;
StringSearch__Matcher OOC_Make__inspectProc;
StringSearch__Matcher OOC_Make__inspectStage;
OOC_CHAR8 OOC_Make__writeAST;
OOC_CHAR8 OOC_Make__writeIR;
OOC_CHAR8 OOC_Make__writeStats;
#define OOC_Make__noSuchModule 1
#define OOC_Make__partOfAnotherLibrary 2
static OOC_Make__ErrorContext OOC_Make__makeContext;
static OOC_CHAR8 OOC_Make__Exists(OOC_Repository__Module module, OOC_INT8 fileId);
static OOC_CHAR8 OOC_Make__DerivedIsOlder2(OOC_Repository__Module descendentModule, OOC_INT8 descendent, OOC_Repository__Module ancestorModule, OOC_INT8 ancestor);
static OOC_CHAR8 OOC_Make__DerivedIsOlder(OOC_Repository__Module module, OOC_INT8 descendent, OOC_INT8 ancestor);
static OOC_CHAR8 OOC_Make__FingerprintMismatch(OOC_Repository__Module descendentModule, OOC_INT32 descendentFP, OOC_Repository__Module ancestorModule, OOC_INT32 ancestorFP);
static OOC_Error__List OOC_Make__CreateErrList(OOC_Repository__Module module);
static void OOC_Make__WriteImports(OOC_Repository__Module module);
static OOC_CHAR8 OOC_Make__UpdateCompilerOutput(OOC_Make__Rules r, OOC_Repository__Module module, OOC_INT8 fileId);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_Make__ModuleInfo = { (RT0__Struct[]){&_td_OOC_Make__ModuleInfoDesc}, NULL, NULL, &_mid, "ModuleInfo", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Make__ModuleInfoDesc = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_OOC_Make__ModuleInfoDesc}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__ObjectDesc_ToString,(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode}, NULL, &_mid, "ModuleInfoDesc", 46, 2, (1<<RT0__flagAtomic), RT0__strRecord };
RT0__StructDesc _td_OOC_Make__1851 = { (RT0__Struct[]){&RT0__boolean}, NULL, NULL, &_mid, NULL, 22, 22, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_Make__1903 = { (RT0__Struct[]){&RT0__boolean}, NULL, NULL, &_mid, NULL, 22, 22, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_Make__2030 = { (RT0__Struct[]){&_td_OOC_Repository__Module}, NULL, NULL, &_mid, NULL, 4, 1, 0, RT0__strOpenArray };
RT0__StructDesc _td_OOC_Make__ModuleList = { (RT0__Struct[]){&_td_OOC_Make__2030}, NULL, NULL, &_mid, "ModuleList", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Make__Rules = { (RT0__Struct[]){&_td_OOC_Make__RulesDesc}, NULL, NULL, &_mid, "Rules", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Make__RulesDesc = { (RT0__Struct[]){&_td_OOC_Make__RulesDesc}, (void*[]){(void*)OOC_Make__RulesDesc_SetBackend,(void*)OOC_Make__RulesDesc_SetLibrary,(void*)OOC_Make__RulesDesc_LibraryName,(void*)OOC_Make__RulesDesc_SetAllImportsModule,(void*)OOC_Make__RulesDesc_SetErrOut,(void*)OOC_Make__RulesDesc_SetForceUpdate,(void*)OOC_Make__RulesDesc_UsageTracking,(void*)OOC_Make__RulesDesc_SetExtensionDict,(void*)OOC_Make__RulesDesc_CheckAllImports,(void*)OOC_Make__RulesDesc_GetModuleInfo,(void*)OOC_Make__RulesDesc_WriteErrList,(void*)OOC_Make__RulesDesc_WriteError,(void*)OOC_Make__RulesDesc_GetImports,(void*)OOC_Make__RulesDesc_SelectBackend,(void*)OOC_Make__RulesDesc_CompileModule,(void*)OOC_Make__RulesDesc_UpdateSymbolFile,(void*)OOC_Make__RulesDesc_UpdateSymbolTableXML,(void*)OOC_Make__RulesDesc_UpdateInterfaceDescr,(void*)OOC_Make__RulesDesc_UpdateInterfaceXML,(void*)OOC_Make__RulesDesc_UpdateInterfaceHTML,(void*)OOC_Make__RulesDesc_UpdateHeaderFileC,(void*)OOC_Make__RulesDesc_UpdateDeclFileC,(void*)OOC_Make__RulesDesc_UpdateCodeFileC,(void*)OOC_Make__RulesDesc_UpdateAssemblerFile,(void*)OOC_Make__RulesDesc_UpdateObjectFile,(void*)OOC_Make__RulesDesc_UpdateObjectFileLib,(void*)OOC_Make__RulesDesc_UpdateMainFileC,(void*)OOC_Make__RulesDesc_UpdateMainFileAssembler,(void*)OOC_Make__RulesDesc_UpdateMainObjectFile,(void*)OOC_Make__RulesDesc_UpdateExecutable,(void*)OOC_Make__RulesDesc_UpdateLibrary,(void*)OOC_Make__RulesDesc_Update}, NULL, &_mid, "RulesDesc", 44, 0, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_Make__3698 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 24, 24, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_Make__3673 = { (RT0__Struct[]){&_td_OOC_Make__3698}, NULL, NULL, &_mid, NULL, 528, 22, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_Make__ErrorContext = { (RT0__Struct[]){&_td_OOC_Make__ErrorContextDesc}, NULL, NULL, &_mid, "ErrorContext", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Make__ErrorContextDesc = { (RT0__Struct[]){&_td_Msg__ContextDesc,&_td_OOC_Error__ContextDesc,&_td_OOC_Make__ErrorContextDesc}, (void*[]){(void*)OOC_Make__ErrorContextDesc_GetTemplate,(void*)OOC_Error__ContextDesc_BaseTemplate}, NULL, &_mid, "ErrorContextDesc", 4, 2, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_Make__4833 = { (RT0__Struct[]){&RT0__longchar}, NULL, NULL, &_mid, NULL, 256, 128, (1<<RT0__flagAtomic), RT0__strArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:Make", (RT0__Struct[]) { &_td_OOC_Make__ModuleInfo, &_td_OOC_Make__ModuleInfoDesc, &_td_OOC_Make__ModuleList, &_td_OOC_Make__Rules, &_td_OOC_Make__RulesDesc, &_td_OOC_Make__ErrorContext, &_td_OOC_Make__ErrorContextDesc, NULL } };

extern void OOC_OOC_Make_init0() {
  RT0__RegisterModule(&_mid);
  OOC_OOC_Make_init();
}

/* --- */
