#include <OOC/SymbolTable/Exports.oh>
#include <Log.oh>
#include <OOC/SymbolTable/Builder.oh>
#include <OOC/Doc.oh>
#include <ADT/Dictionary/AddressKey.oh>

/* run-time meta data */
static RT0__ModuleDesc _mid;
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:SymbolTable:Exports", (RT0__Struct[]) { NULL }, 0 };

extern void OOC_OOC_SymbolTable_Exports_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_Log_open(&_mid);
    OOC_OOC_SymbolTable_open(&_mid);
    OOC_OOC_SymbolTable_Builder_open(&_mid);
    OOC_OOC_Doc_open(&_mid);
    OOC_ADT_Dictionary_AddressKey_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_OOC_SymbolTable_Exports_init();
  }
  _mid.openCount++;
}
extern void OOC_OOC_SymbolTable_Exports_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_OOC_SymbolTable_Exports_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_Log_close(&_mid);
    OOC_OOC_SymbolTable_close(&_mid);
    OOC_OOC_SymbolTable_Builder_close(&_mid);
    OOC_OOC_Doc_close(&_mid);
    OOC_ADT_Dictionary_AddressKey_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
