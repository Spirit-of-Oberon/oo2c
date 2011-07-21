static void* _c0;
static void* _c1;
static void* _c2;
static void* _c3;
static void* _c4;
static void* _c5;
static void* _c6;
static void* _c7;
static void* _c8;
#include <URI/Authority/ServerBased.oh>
#include <IntStr.oh>
#include <CharClass.oh>
#include <URI/CharClass.oh>
#include <URI/String.oh>
#define URI_Authority_ServerBased__defaultPort (-1)
static void URI_Authority_ServerBased__ParseHost(Object__CharsLatin1 str, OOC_INT16 offset);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_URI_Authority_ServerBased__Authority = { (RT0__Struct[]){&_td_URI_Authority_ServerBased__AuthorityDesc}, NULL, NULL, &_mid, "Authority", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_URI_Authority_ServerBased__AuthorityDesc = { (RT0__Struct[]){&_td_URI__AuthorityDesc,&_td_URI_Authority_ServerBased__AuthorityDesc}, (void*[]){(void*)URI_Authority_ServerBased__AuthorityDesc_Clone,(void*)URI_Authority_ServerBased__AuthorityDesc_Copy,(void*)URI_Authority_ServerBased__AuthorityDesc_ParseAuthority,(void*)URI_Authority_ServerBased__AuthorityDesc_WriteXML,(void*)URI_Authority_ServerBased__AuthorityDesc_Append}, NULL, &_mid, "AuthorityDesc", 16, 1, 0, RT0__strRecord };
RT0__StructDesc _td_URI_Authority_ServerBased__8110 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 32, 32, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_URI_Authority_ServerBased__8798 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 32, 32, (1<<RT0__flagAtomic), RT0__strArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"URI:Authority:ServerBased", (RT0__Struct[]) { &_td_URI_Authority_ServerBased__Authority, &_td_URI_Authority_ServerBased__AuthorityDesc, NULL } };

extern void OOC_URI_Authority_ServerBased_init0() {
  RT0__RegisterModule(&_mid);
  OOC_URI_Authority_ServerBased_init();
}

/* --- */
