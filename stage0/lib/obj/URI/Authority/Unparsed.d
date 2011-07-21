static void* _c0;
static void* _c1;
#include <URI/Authority/Unparsed.oh>
#include <CharClass.oh>
#include <URI/CharClass.oh>

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_URI_Authority_Unparsed__Authority = { (RT0__Struct[]){&_td_URI_Authority_Unparsed__AuthorityDesc}, NULL, NULL, &_mid, "Authority", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_URI_Authority_Unparsed__AuthorityDesc = { (RT0__Struct[]){&_td_URI__AuthorityDesc,&_td_URI_Authority_Unparsed__AuthorityDesc}, (void*[]){(void*)URI_Authority_Unparsed__AuthorityDesc_Clone,(void*)URI_Authority_Unparsed__AuthorityDesc_Copy,(void*)URI_Authority_Unparsed__AuthorityDesc_ParseAuthority,(void*)URI_Authority_Unparsed__AuthorityDesc_WriteXML,(void*)URI_Authority_Unparsed__AuthorityDesc_Append}, NULL, &_mid, "AuthorityDesc", 4, 1, 0, RT0__strRecord };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"URI:Authority:Unparsed", (RT0__Struct[]) { &_td_URI_Authority_Unparsed__Authority, &_td_URI_Authority_Unparsed__AuthorityDesc, NULL }, 0 };

extern void OOC_URI_Authority_Unparsed_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_TextRider_open(&_mid);
    OOC_CharClass_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);
    OOC_ADT_StringBuffer_open(&_mid);
    OOC_URI_open(&_mid);
    OOC_URI_CharClass_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_URI_Authority_Unparsed_init();
  }
  _mid.openCount++;
}
extern void OOC_URI_Authority_Unparsed_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_URI_Authority_Unparsed_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_TextRider_close(&_mid);
    OOC_CharClass_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
    OOC_ADT_StringBuffer_close(&_mid);
    OOC_URI_close(&_mid);
    OOC_URI_CharClass_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
