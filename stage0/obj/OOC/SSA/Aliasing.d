#include <OOC/SSA/Aliasing.oh>
#include <OOC/SymbolTable.oh>
#include <OOC/SymbolTable/TypeRules.oh>

/* run-time meta data */
static RT0__ModuleDesc _mid;
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:SSA:Aliasing", (RT0__Struct[]) { NULL } };

extern void OOC_OOC_SSA_Aliasing_init0() {
  RT0__RegisterModule(&_mid);
  OOC_OOC_SSA_Aliasing_init();
}

/* --- */
