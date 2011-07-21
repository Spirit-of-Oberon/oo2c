#include <OOC/SymbolTable/Exports.oh>
#include <Log.oh>
#include <OOC/SymbolTable/Builder.oh>
#include <OOC/Doc.oh>
#include <ADT/Dictionary/AddressKey.oh>

/* run-time meta data */
static RT0__ModuleDesc _mid;
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:SymbolTable:Exports", (RT0__Struct[]) { NULL } };

extern void OOC_OOC_SymbolTable_Exports_init0() {
  RT0__RegisterModule(&_mid);
  OOC_OOC_SymbolTable_Exports_init();
}

/* --- */
