#include <StringSearch.oh>

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_StringSearch__Factory = { (RT0__Struct[]){&_td_StringSearch__FactoryDesc}, NULL, NULL, &_mid, "Factory", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_StringSearch__FactoryDesc = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_StringSearch__FactoryDesc}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__ObjectDesc_ToString,(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)StringSearch__FactoryDesc_Destroy,(void*)StringSearch__FactoryDesc_Compile}, NULL, &_mid, "FactoryDesc", 0, 2, (1<<RT0__flagAtomic), RT0__strRecord };
RT0__StructDesc _td_StringSearch__Matcher = { (RT0__Struct[]){&_td_StringSearch__MatcherDesc}, NULL, NULL, &_mid, "Matcher", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_StringSearch__MatcherDesc = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_StringSearch__MatcherDesc}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__ObjectDesc_ToString,(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)StringSearch__MatcherDesc_Destroy,(void*)StringSearch__MatcherDesc_MatchChars,(void*)StringSearch__MatcherDesc_Match,(void*)StringSearch__MatcherDesc_SearchChars,(void*)StringSearch__MatcherDesc_Search}, NULL, &_mid, "MatcherDesc", 12, 2, 0, RT0__strRecord };
RT0__StructDesc _td_StringSearch__MatchObject = { (RT0__Struct[]){&_td_StringSearch__MatchObjectDesc}, NULL, NULL, &_mid, "MatchObject", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_StringSearch__MatchObjectDesc = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_StringSearch__MatchObjectDesc}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__ObjectDesc_ToString,(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)StringSearch__MatchObjectDesc_Destroy,(void*)StringSearch__MatchObjectDesc_Start,(void*)StringSearch__MatchObjectDesc_End}, NULL, &_mid, "MatchObjectDesc", 16, 2, 0, RT0__strRecord };
RT0__StructDesc _td_StringSearch__5550 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_StringSearch__7054 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"StringSearch", (RT0__Struct[]) { &_td_StringSearch__Factory, &_td_StringSearch__FactoryDesc, &_td_StringSearch__Matcher, &_td_StringSearch__MatcherDesc, &_td_StringSearch__MatchObject, &_td_StringSearch__MatchObjectDesc, NULL }, 0 };

extern void OOC_StringSearch_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_Object_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_StringSearch_init();
  }
  _mid.openCount++;
}
extern void OOC_StringSearch_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_StringSearch_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_Object_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
