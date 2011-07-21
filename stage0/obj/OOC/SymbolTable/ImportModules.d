#include <OOC/SymbolTable/ImportModules.oh>
#include <Msg.oh>
#include <OOC/Config.oh>
#include <OOC/Repository.oh>
#define OOC_SymbolTable_ImportModules__noSuchModule 1
#define OOC_SymbolTable_ImportModules__readErrorSymbolFile 2
static OOC_SymbolTable_ImportModules__ErrorContext OOC_SymbolTable_ImportModules__importModulesContext;

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_SymbolTable_ImportModules__ErrorContext = { (RT0__Struct[]){&_td_OOC_SymbolTable_ImportModules__ErrorContextDesc}, NULL, NULL, &_mid, "ErrorContext", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_SymbolTable_ImportModules__ErrorContextDesc = { (RT0__Struct[]){&_td_Msg__ContextDesc,&_td_OOC_Error__ContextDesc,&_td_OOC_SymbolTable_ImportModules__ErrorContextDesc}, (void*[]){(void*)OOC_SymbolTable_ImportModules__ErrorContextDesc_GetTemplate,(void*)OOC_Error__ContextDesc_BaseTemplate}, NULL, &_mid, "ErrorContextDesc", 4, 2, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_SymbolTable_ImportModules__1364 = { (RT0__Struct[]){&RT0__longchar}, NULL, NULL, &_mid, NULL, 256, 128, (1<<RT0__flagAtomic), RT0__strArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:SymbolTable:ImportModules", (RT0__Struct[]) { &_td_OOC_SymbolTable_ImportModules__ErrorContext, &_td_OOC_SymbolTable_ImportModules__ErrorContextDesc, NULL } };

extern void OOC_OOC_SymbolTable_ImportModules_init0() {
  RT0__RegisterModule(&_mid);
  OOC_OOC_SymbolTable_ImportModules_init();
}

/* --- */
