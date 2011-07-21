#include <URI/String.oh>
#include <Object.oh>

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_URI_String__1420 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_URI_String__1409 = { (RT0__Struct[]){&_td_URI_String__1420}, NULL, NULL, &_mid, NULL, 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_URI_String__2369 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"URI:String", (RT0__Struct[]) { NULL } };

extern void OOC_URI_String_init0() {
  RT0__RegisterModule(&_mid);
  OOC_URI_String_init();
}

/* --- */
