#include <RealConv.oh>
#include <libc.oh>
#include <CharClass.oh>
#include <Real0.oh>
#define RealConv__maxValue "340282347"
#define RealConv__maxExp 38

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_RealConv__2095 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_RealConv__2231 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"RealConv", (RT0__Struct[]) { NULL } };

extern void OOC_RealConv_init0() {
  RT0__RegisterModule(&_mid);
  OOC_RealConv_init();
}

/* --- */
