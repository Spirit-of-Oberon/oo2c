#include <LRealStr.oh>
#include <libc.oh>
#include <LRealConv.oh>
#include <Real0.oh>
#include <Strings.oh>
#define LRealStr__prec 17

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_LRealStr__1572 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_LRealStr__1907 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_LRealStr__2774 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 32, 32, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_LRealStr__3073 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_LRealStr__3648 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 32, 32, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_LRealStr__3943 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_LRealStr__4802 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 340, 340, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_LRealStr__5113 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_LRealStr__5702 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 340, 340, (1<<RT0__flagAtomic), RT0__strArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"LRealStr", (RT0__Struct[]) { NULL }, 0 };

extern void OOC_LRealStr_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_ConvTypes_open(&_mid);
    OOC_LRealConv_open(&_mid);
    OOC_Real0_open(&_mid);
    OOC_Strings_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_LRealStr_init();
  }
  _mid.openCount++;
}
extern void OOC_LRealStr_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_LRealStr_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_ConvTypes_close(&_mid);
    OOC_LRealConv_close(&_mid);
    OOC_Real0_close(&_mid);
    OOC_Strings_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
