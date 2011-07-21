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
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"LRealStr", (RT0__Struct[]) { NULL } };

extern void OOC_LRealStr_init0() {
  RT0__RegisterModule(&_mid);
  OOC_LRealStr_init();
}

/* --- */
