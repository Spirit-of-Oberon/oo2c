static void* _c0;
static void* _c1;
#include <URI/Query/Unparsed.oh>
#include <CharClass.oh>
#include <URI/CharClass.oh>

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_URI_Query_Unparsed__Query = { (RT0__Struct[]){&_td_URI_Query_Unparsed__QueryDesc}, NULL, NULL, &_mid, "Query", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_URI_Query_Unparsed__QueryDesc = { (RT0__Struct[]){&_td_URI__QueryDesc,&_td_URI_Query_Unparsed__QueryDesc}, (void*[]){(void*)URI_Query_Unparsed__QueryDesc_Clone,(void*)URI_Query_Unparsed__QueryDesc_Copy,(void*)URI_Query_Unparsed__QueryDesc_ParseQuery,(void*)URI_Query_Unparsed__QueryDesc_WriteXML,(void*)URI_Query_Unparsed__QueryDesc_Append}, NULL, &_mid, "QueryDesc", 4, 1, 0, RT0__strRecord };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"URI:Query:Unparsed", (RT0__Struct[]) { &_td_URI_Query_Unparsed__Query, &_td_URI_Query_Unparsed__QueryDesc, NULL } };

extern void OOC_URI_Query_Unparsed_init0() {
  RT0__RegisterModule(&_mid);
  OOC_URI_Query_Unparsed_init();
}

/* --- */
