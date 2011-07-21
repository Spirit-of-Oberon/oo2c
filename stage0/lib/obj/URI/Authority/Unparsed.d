static void* _c0;
static void* _c1;
#include <URI/Authority/Unparsed.oh>
#include <CharClass.oh>
#include <URI/CharClass.oh>

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_URI_Authority_Unparsed__Authority = { (RT0__Struct[]){&_td_URI_Authority_Unparsed__AuthorityDesc}, NULL, NULL, &_mid, "Authority", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_URI_Authority_Unparsed__AuthorityDesc = { (RT0__Struct[]){&_td_URI__AuthorityDesc,&_td_URI_Authority_Unparsed__AuthorityDesc}, (void*[]){(void*)URI_Authority_Unparsed__AuthorityDesc_Clone,(void*)URI_Authority_Unparsed__AuthorityDesc_Copy,(void*)URI_Authority_Unparsed__AuthorityDesc_ParseAuthority,(void*)URI_Authority_Unparsed__AuthorityDesc_WriteXML,(void*)URI_Authority_Unparsed__AuthorityDesc_Append}, NULL, &_mid, "AuthorityDesc", 4, 1, 0, RT0__strRecord };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"URI:Authority:Unparsed", (RT0__Struct[]) { &_td_URI_Authority_Unparsed__Authority, &_td_URI_Authority_Unparsed__AuthorityDesc, NULL } };

extern void OOC_URI_Authority_Unparsed_init0() {
  RT0__RegisterModule(&_mid);
  OOC_URI_Authority_Unparsed_init();
}

/* --- */
