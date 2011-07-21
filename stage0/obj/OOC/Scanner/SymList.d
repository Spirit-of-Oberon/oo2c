#include <OOC/Scanner/SymList.oh>
#include <Strings.oh>

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_Scanner_SymList__Symbol = { (RT0__Struct[]){&_td_OOC_Scanner_SymList__SymbolDesc}, NULL, NULL, &_mid, "Symbol", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Scanner_SymList__SymbolDesc = { (RT0__Struct[]){&_td_OOC_Scanner_SymList__SymbolDesc}, (void*[]){}, NULL, &_mid, "SymbolDesc", 28, 0, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_Scanner_SymList__Builder = { (RT0__Struct[]){&_td_OOC_Scanner_SymList__BuilderDesc}, NULL, NULL, &_mid, "Builder", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Scanner_SymList__BuilderDesc = { (RT0__Struct[]){&_td_OOC_Scanner_SymList__BuilderDesc}, (void*[]){(void*)OOC_Scanner_SymList__BuilderDesc_Clear,(void*)OOC_Scanner_SymList__BuilderDesc_AddSymbol,(void*)OOC_Scanner_SymList__BuilderDesc_SetPragmaHistory}, NULL, &_mid, "BuilderDesc", 20, 0, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_Scanner_SymList__3802 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:Scanner:SymList", (RT0__Struct[]) { &_td_OOC_Scanner_SymList__Symbol, &_td_OOC_Scanner_SymList__SymbolDesc, &_td_OOC_Scanner_SymList__Builder, &_td_OOC_Scanner_SymList__BuilderDesc, NULL }, 0 };

extern void OOC_OOC_Scanner_SymList_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_Strings_open(&_mid);
    OOC_OOC_Scanner_InputBuffer_open(&_mid);
    OOC_OOC_Scanner_Symbol_open(&_mid);
    OOC_OOC_Config_Pragmas_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_OOC_Scanner_SymList_init();
  }
  _mid.openCount++;
}
extern void OOC_OOC_Scanner_SymList_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_OOC_Scanner_SymList_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_Strings_close(&_mid);
    OOC_OOC_Scanner_InputBuffer_close(&_mid);
    OOC_OOC_Scanner_Symbol_close(&_mid);
    OOC_OOC_Config_Pragmas_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
