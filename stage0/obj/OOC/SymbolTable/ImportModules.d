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
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:SymbolTable:ImportModules", (RT0__Struct[]) { &_td_OOC_SymbolTable_ImportModules__ErrorContext, &_td_OOC_SymbolTable_ImportModules__ErrorContextDesc, NULL }, 0 };

extern void OOC_OOC_SymbolTable_ImportModules_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_Msg_open(&_mid);
    OOC_IO_open(&_mid);
    OOC_OOC_Config_open(&_mid);
    OOC_OOC_Error_open(&_mid);
    OOC_OOC_SymbolTable_open(&_mid);
    OOC_OOC_Repository_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_OOC_SymbolTable_ImportModules_init();
  }
  _mid.openCount++;
}
extern void OOC_OOC_SymbolTable_ImportModules_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_OOC_SymbolTable_ImportModules_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_Msg_close(&_mid);
    OOC_IO_close(&_mid);
    OOC_OOC_Config_close(&_mid);
    OOC_OOC_Error_close(&_mid);
    OOC_OOC_SymbolTable_close(&_mid);
    OOC_OOC_Repository_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
