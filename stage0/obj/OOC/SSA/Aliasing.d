#include <OOC/SSA/Aliasing.oh>
#include <OOC/SymbolTable.oh>
#include <OOC/SymbolTable/TypeRules.oh>

/* run-time meta data */
static RT0__ModuleDesc _mid;
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:SSA:Aliasing", (RT0__Struct[]) { NULL }, 0 };

extern void OOC_OOC_SSA_Aliasing_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_OOC_SymbolTable_open(&_mid);
    OOC_OOC_SymbolTable_TypeRules_open(&_mid);
    OOC_OOC_SSA_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_OOC_SSA_Aliasing_init();
  }
  _mid.openCount++;
}
extern void OOC_OOC_SSA_Aliasing_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_OOC_SSA_Aliasing_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_OOC_SymbolTable_close(&_mid);
    OOC_OOC_SymbolTable_TypeRules_close(&_mid);
    OOC_OOC_SSA_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
