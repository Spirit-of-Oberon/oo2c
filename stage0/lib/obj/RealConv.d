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
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"RealConv", (RT0__Struct[]) { NULL }, 0 };

extern void OOC_RealConv_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_CharClass_open(&_mid);
    OOC_ConvTypes_open(&_mid);
    OOC_Real0_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_RealConv_init();
  }
  _mid.openCount++;
}
extern void OOC_RealConv_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_RealConv_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_CharClass_close(&_mid);
    OOC_ConvTypes_close(&_mid);
    OOC_Real0_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
