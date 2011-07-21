#include <LRealConv.oh>
#include <libc.oh>
#include <CharClass.oh>
#include <Real0.oh>
#define LRealConv__maxValue "17976931348623157"
#define LRealConv__maxExp 308

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_LRealConv__2120 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_LRealConv__2256 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"LRealConv", (RT0__Struct[]) { NULL } };

extern void OOC_LRealConv_init0() {
  RT0__RegisterModule(&_mid);
  OOC_LRealConv_init();
}

/* --- */
