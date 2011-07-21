#include <OOC/SymbolTable/TypeRules.oh>
static OOC_CHAR8 OOC_SymbolTable_TypeRules__ExtendsLibType(OOC_SymbolTable__Type type, const OOC_CHAR8 module__ref[], OOC_LEN module_0d, const OOC_CHAR8 recordName__ref[], OOC_LEN recordName_0d);
static OOC_CHAR8 OOC_SymbolTable_TypeRules__IsPointerType(OOC_SymbolTable__Type type, const OOC_CHAR8 module__ref[], OOC_LEN module_0d, const OOC_CHAR8 recordName__ref[], OOC_LEN recordName_0d);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_SymbolTable_TypeRules__3257 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_SymbolTable_TypeRules__3872 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:SymbolTable:TypeRules", (RT0__Struct[]) { NULL }, 0 };

extern void OOC_OOC_SymbolTable_TypeRules_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_OOC_SymbolTable_open(&_mid);
    OOC_OOC_SymbolTable_Predef_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_OOC_SymbolTable_TypeRules_init();
  }
  _mid.openCount++;
}
extern void OOC_OOC_SymbolTable_TypeRules_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_OOC_SymbolTable_TypeRules_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_OOC_SymbolTable_close(&_mid);
    OOC_OOC_SymbolTable_Predef_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
