static void* _c0;
static void* _c1;
static void* _c2;
#include <OOC/Make.oh>
#include <Out.oh>
#include <Time.oh>
#include <IO/StdChannels.oh>
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
#include <OOC/Config/CCompiler.oh>
#include <OOC/Make/TranslateToC.oh>
#include <OOC/Make/WriteMainFileC.oh>
#include <OOC/SSA/WriteC.oh>
#include <OOC/Config/Assembler.oh>
#include <OOC/Make/TranslateToX86.oh>
#include <OOC/Make/WriteMainFileAssembler.oh>
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
RT0__StructDesc _td_OOC_Make__1782 = { (RT0__Struct[]){&RT0__boolean}, NULL, NULL, &_mid, NULL, 22, 22, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_Make__1834 = { (RT0__Struct[]){&RT0__boolean}, NULL, NULL, &_mid, NULL, 22, 22, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_Make__1961 = { (RT0__Struct[]){&_td_OOC_Repository__Module}, NULL, NULL, &_mid, NULL, 4, 1, 0, RT0__strOpenArray };
RT0__StructDesc _td_OOC_Make__ModuleList = { (RT0__Struct[]){&_td_OOC_Make__1961}, NULL, NULL, &_mid, "ModuleList", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Make__Rules = { (RT0__Struct[]){&_td_OOC_Make__RulesDesc}, NULL, NULL, &_mid, "Rules", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Make__RulesDesc = { (RT0__Struct[]){&_td_OOC_Make__RulesDesc}, (void*[]){(void*)OOC_Make__RulesDesc_SetBackend,(void*)OOC_Make__RulesDesc_SetLibrary,(void*)OOC_Make__RulesDesc_LibraryName,(void*)OOC_Make__RulesDesc_SetAllImportsModule,(void*)OOC_Make__RulesDesc_SetErrOut,(void*)OOC_Make__RulesDesc_SetForceUpdate,(void*)OOC_Make__RulesDesc_UsageTracking,(void*)OOC_Make__RulesDesc_SetExtensionDict,(void*)OOC_Make__RulesDesc_CheckAllImports,(void*)OOC_Make__RulesDesc_GetModuleInfo,(void*)OOC_Make__RulesDesc_WriteErrList,(void*)OOC_Make__RulesDesc_WriteError,(void*)OOC_Make__RulesDesc_GetImports,(void*)OOC_Make__RulesDesc_SelectBackend,(void*)OOC_Make__RulesDesc_CompileModule,(void*)OOC_Make__RulesDesc_UpdateSymbolFile,(void*)OOC_Make__RulesDesc_UpdateSymbolTableXML,(void*)OOC_Make__RulesDesc_UpdateInterfaceDescr,(void*)OOC_Make__RulesDesc_UpdateInterfaceXML,(void*)OOC_Make__RulesDesc_UpdateInterfaceHTML,(void*)OOC_Make__RulesDesc_UpdateHeaderFileC,(void*)OOC_Make__RulesDesc_UpdateDeclFileC,(void*)OOC_Make__RulesDesc_UpdateCodeFileC,(void*)OOC_Make__RulesDesc_UpdateAssemblerFile,(void*)OOC_Make__RulesDesc_UpdateObjectFile,(void*)OOC_Make__RulesDesc_UpdateObjectFileLib,(void*)OOC_Make__RulesDesc_UpdateMainFileC,(void*)OOC_Make__RulesDesc_UpdateMainFileX86,(void*)OOC_Make__RulesDesc_UpdateMainObjectFile,(void*)OOC_Make__RulesDesc_UpdateExecutable,(void*)OOC_Make__RulesDesc_UpdateLibrary,(void*)OOC_Make__RulesDesc_Update}, NULL, &_mid, "RulesDesc", 44, 0, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_Make__3606 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 24, 24, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_Make__3581 = { (RT0__Struct[]){&_td_OOC_Make__3606}, NULL, NULL, &_mid, NULL, 528, 22, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_Make__ErrorContext = { (RT0__Struct[]){&_td_OOC_Make__ErrorContextDesc}, NULL, NULL, &_mid, "ErrorContext", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Make__ErrorContextDesc = { (RT0__Struct[]){&_td_Msg__ContextDesc,&_td_OOC_Error__ContextDesc,&_td_OOC_Make__ErrorContextDesc}, (void*[]){(void*)OOC_Make__ErrorContextDesc_GetTemplate,(void*)OOC_Error__ContextDesc_BaseTemplate}, NULL, &_mid, "ErrorContextDesc", 4, 2, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_Make__4741 = { (RT0__Struct[]){&RT0__longchar}, NULL, NULL, &_mid, NULL, 256, 128, (1<<RT0__flagAtomic), RT0__strArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:Make", (RT0__Struct[]) { &_td_OOC_Make__ModuleInfo, &_td_OOC_Make__ModuleInfoDesc, &_td_OOC_Make__ModuleList, &_td_OOC_Make__Rules, &_td_OOC_Make__RulesDesc, &_td_OOC_Make__ErrorContext, &_td_OOC_Make__ErrorContextDesc, NULL }, 0 };

extern void OOC_OOC_Make_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_Msg_open(&_mid);
    OOC_Out_open(&_mid);
    OOC_Time_open(&_mid);
    OOC_IO_open(&_mid);
    OOC_IO_StdChannels_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_ADT_ArrayList_open(&_mid);
    OOC_ADT_Dictionary_open(&_mid);
    OOC_ADT_StringBuffer_open(&_mid);
    OOC_StringSearch_open(&_mid);
    OOC_StringSearch_NoMatch_open(&_mid);
    OOC_OS_Path_open(&_mid);
    OOC_OS_Files_open(&_mid);
    OOC_OS_ProcessManagement_open(&_mid);
    OOC_URI_open(&_mid);
    OOC_URI_Scheme_File_open(&_mid);
    OOC_OOC_Logger_open(&_mid);
    OOC_OOC_Error_open(&_mid);
    OOC_OOC_Config_open(&_mid);
    OOC_OOC_Config_Pragmas_open(&_mid);
    OOC_OOC_Config_Repositories_open(&_mid);
    OOC_OOC_Doc_ResolveRef_open(&_mid);
    OOC_OOC_Package_open(&_mid);
    OOC_OOC_Repository_open(&_mid);
    OOC_OOC_AST_open(&_mid);
    OOC_OOC_SymbolTable_open(&_mid);
    OOC_OOC_SymbolTable_CreateNamespace_open(&_mid);
    OOC_OOC_SymbolTable_InterfaceDescr_open(&_mid);
    OOC_OOC_SymbolTable_InterfaceXML_open(&_mid);
    OOC_OOC_SymbolTable_Uses_open(&_mid);
    OOC_OOC_Auxiliary_ParseModule_open(&_mid);
    OOC_OOC_Make_LinkProgramC_open(&_mid);
    OOC_OOC_Config_CCompiler_open(&_mid);
    OOC_OOC_Make_TranslateToC_open(&_mid);
    OOC_OOC_Make_WriteMainFileC_open(&_mid);
    OOC_OOC_SSA_WriteC_open(&_mid);
    OOC_OOC_Config_Assembler_open(&_mid);
    OOC_OOC_Make_TranslateToX86_open(&_mid);
    OOC_OOC_Make_WriteMainFileAssembler_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_OOC_Make_init();
  }
  _mid.openCount++;
}
extern void OOC_OOC_Make_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_OOC_Make_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_Msg_close(&_mid);
    OOC_Out_close(&_mid);
    OOC_Time_close(&_mid);
    OOC_IO_close(&_mid);
    OOC_IO_StdChannels_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_ADT_ArrayList_close(&_mid);
    OOC_ADT_Dictionary_close(&_mid);
    OOC_ADT_StringBuffer_close(&_mid);
    OOC_StringSearch_close(&_mid);
    OOC_StringSearch_NoMatch_close(&_mid);
    OOC_OS_Path_close(&_mid);
    OOC_OS_Files_close(&_mid);
    OOC_OS_ProcessManagement_close(&_mid);
    OOC_URI_close(&_mid);
    OOC_URI_Scheme_File_close(&_mid);
    OOC_OOC_Logger_close(&_mid);
    OOC_OOC_Error_close(&_mid);
    OOC_OOC_Config_close(&_mid);
    OOC_OOC_Config_Pragmas_close(&_mid);
    OOC_OOC_Config_Repositories_close(&_mid);
    OOC_OOC_Doc_ResolveRef_close(&_mid);
    OOC_OOC_Package_close(&_mid);
    OOC_OOC_Repository_close(&_mid);
    OOC_OOC_AST_close(&_mid);
    OOC_OOC_SymbolTable_close(&_mid);
    OOC_OOC_SymbolTable_CreateNamespace_close(&_mid);
    OOC_OOC_SymbolTable_InterfaceDescr_close(&_mid);
    OOC_OOC_SymbolTable_InterfaceXML_close(&_mid);
    OOC_OOC_SymbolTable_Uses_close(&_mid);
    OOC_OOC_Auxiliary_ParseModule_close(&_mid);
    OOC_OOC_Make_LinkProgramC_close(&_mid);
    OOC_OOC_Config_CCompiler_close(&_mid);
    OOC_OOC_Make_TranslateToC_close(&_mid);
    OOC_OOC_Make_WriteMainFileC_close(&_mid);
    OOC_OOC_SSA_WriteC_close(&_mid);
    OOC_OOC_Config_Assembler_close(&_mid);
    OOC_OOC_Make_TranslateToX86_close(&_mid);
    OOC_OOC_Make_WriteMainFileAssembler_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
