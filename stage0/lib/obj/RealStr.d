#include <RealStr.oh>
#include <libc.oh>
#include <RealConv.oh>
#include <Real0.oh>
#include <Strings.oh>
#define RealStr__prec 9

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_RealStr__1563 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_RealStr__1888 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_RealStr__2755 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 32, 32, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_RealStr__3050 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_RealStr__3625 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 32, 32, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_RealStr__3916 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_RealStr__4775 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 70, 70, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_RealStr__5081 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_RealStr__5670 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 70, 70, (1<<RT0__flagAtomic), RT0__strArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"RealStr", (RT0__Struct[]) { NULL } };

extern void OOC_RealStr_init0() {
  RT0__RegisterModule(&_mid);
  OOC_RealStr_init();
}

/* --- */
