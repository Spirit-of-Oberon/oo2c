#include <OOC/Scanner/SymList.oh>
#include <Strings.oh>

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_Scanner_SymList__Symbol = { (RT0__Struct[]){&_td_OOC_Scanner_SymList__SymbolDesc}, NULL, NULL, &_mid, "Symbol", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Scanner_SymList__SymbolDesc = { (RT0__Struct[]){&_td_OOC_Scanner_SymList__SymbolDesc}, (void*[]){}, NULL, &_mid, "SymbolDesc", 28, 0, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_Scanner_SymList__Builder = { (RT0__Struct[]){&_td_OOC_Scanner_SymList__BuilderDesc}, NULL, NULL, &_mid, "Builder", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Scanner_SymList__BuilderDesc = { (RT0__Struct[]){&_td_OOC_Scanner_SymList__BuilderDesc}, (void*[]){(void*)OOC_Scanner_SymList__BuilderDesc_Clear,(void*)OOC_Scanner_SymList__BuilderDesc_AddSymbol,(void*)OOC_Scanner_SymList__BuilderDesc_SetPragmaHistory}, NULL, &_mid, "BuilderDesc", 20, 0, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_Scanner_SymList__3802 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:Scanner:SymList", (RT0__Struct[]) { &_td_OOC_Scanner_SymList__Symbol, &_td_OOC_Scanner_SymList__SymbolDesc, &_td_OOC_Scanner_SymList__Builder, &_td_OOC_Scanner_SymList__BuilderDesc, NULL } };

extern void OOC_OOC_Scanner_SymList_init0() {
  RT0__RegisterModule(&_mid);
  OOC_OOC_Scanner_SymList_init();
}

/* --- */
